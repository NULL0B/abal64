/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1993
 *	Module  : T-CODE
 *	Fichier : LKFICH.C
 *	Version : 2.2b
 *	Date    : 02/07/93
 *	Systeme : Tous
 *
 *	Gestion des informations contenus dans un traduit
 *
 *	[Noyau TCode- Gestion des informations ]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 * 11/01/93 : Debut du codage
 * 02/11/93 : Correction du bug dans la taille de l'espace memoire
 *            lors de la relocation des Var=M en recouvrement 
 * 17/12/93 : Correction Dans RelocPro et RelocSeg. Avant la relocation
 *            d'une procedure ou segment on enregistre toues les refences
 *            faites a l'interieur du code
 * 25/01/94 : Correction dans FichierRelocPro et FichierRelocSeg
 *            tester avant de reloger si la proc ou le seg a deja ete traitee.
 * 21/04/94 : Suppression du test de debordement en taille de la table
 *            des variables en Field=e
 * 01/07/94 : Transfert de code de longueur multiple de 4096 correction 
 *            dans FichierCopyCode 
 *        
 * 18/11/94 : 1) Prise en compte du MEGA pour les Field=E
 *            2) Correction de la longueur des tableaux Field=E
 *            3) Correction de la limite memoire des Field=M
 * 17/03/99 : Correction (table en entrée) et ajout (table résultat)
 *            du test de débordement de la table des variables (max 32k = 7FFE)
 * 18/11/99 : (#OK) Bug ALD 10 fixed:  remove "readonly" attribute for *.at and *.dbg/wdg files.
 * 25/07/00 : (#OK) Bug ALD 13 fixed:  gerer correctement les limites du linker (messages).
 * 14/09/00 : (#OK) Bug ALD 18 fixed:  FIELD=E.
 * 14/09/00 : (#AT) Changes for extension of tables of global and local variables.
 * 05/09/00 : (#OK) ALD 7: #pragma LOCAL_CONSTANT.
 * 16/10/00 : (#OK) Bug fixed: Exception in EXA if numbers of segments in module was more than 170.
 * 22/11/00 : (#OK & #SP) Bug fixed bounded with constants and and GV > 32k.
 * 28/02/01 : (#BG) Bug fixed in the tests of GV memory size overflow.
 * 28/03/01 : (#BG) Correction concernat ALD 7.
 * 20/08/01 : (#BG) Correction d'une régression: ne pas comptabiliser les variables
 *                  en Field=E dans le test à 64k de l'espace de données!
 * 08/10/01 : (#BG) Abandon du link si la cible est ouverte.
 * 19/11/01 : (#BG) Correction ALD29: Le test de débordement de l'espace de données globales
 *                  ne tenait pas compte de la dimension des tableaux!
 * 02/10/02 : (#BG) Correction du calcul de l'espace à allouer dans le cas des field=e.
 * 08/10/00 : (#BG) Nouvelle correction ALD 18.
 *                 - Suppression d'une exception dans le cas d'une variable Field=e
 *                  redéfinie plusieurs fois dont la taille de la dernière redéfinition
 *                  est inférieure à celle d'une redéfinition précédente (ex. Micrologic STD7.AT).
 *                  - Suppression d'une exception dans le cas d'une variable à plusieurs dimensions en Field=e
 *                  dont la taille est supérieure à 64k (ex. Massa simage.at).
 *                  - Suppression d'une exception dans le cas d'une variable en Field=e
 *                  redéfinie affectée par Move (ex. Technodata).
 *	------------ 2.2b -------------------------------------------------
 */

/* Inclusions importees et privees */
/* Inclusions exportees et privees */


#define _LKFICH 
#include "aldtype.h"
#include "lkstruct.h"

#include "lkfich.h"
#include "lkmes.h"
#include "lklist.h"

#include "lkmain.h"
// YT : for undefined functions
#include "lklib.h"
#include "lkfile.h"
#include "lktable.h"
#include "lkecran.h"
#include "pubslist.h"
#include "fn_parse.h"
#ifndef __PUBSLIST_H__
#include "pubslist.h"
#endif
#include "lkmes.h"

#ifdef __WALD__
extern BOOL	GlobalShowConsole;
#endif

#ifdef DBGTRC2
	extern FILE * fdbgtrc;
#endif

//JPH : for DEBUG
#ifdef _DEBUG
#define DEBUG
#endif


#ifdef VERSION_XX

BYTE	first_version=0;

WORD set_first_version( BYTE v )
{
	if (!( first_version )) 
		first_version = v;
	if (( v != '3')
	&&  ( v != '4'))
		return(0);
	else if ( first_version == v )
		return(1);
	else	return(0);
}

#endif

/*T****
 *	Fonctions pour la gestion des tables 
 *
 */


/*********************************
*
* FCT FichierInit
*
* Entree : 
*	un nom de fichier
*	un repertoire par defaut
*	un type (MODULE / RESULTAT)
* Sortie :
*	rien
*
* Remarque :
*
*
* Voir aussi:
*
*
*/

VOID FichierInit( fic, FullPathFile , DestinationFullPath, typ)
Fichier XPTR * 	fic;
BYTE XPTR * 	FullPathFile;
BYTE XPTR * 	DestinationFullPath;
BYTE 		typ;
{
	BYTE FileName					[LGREP];
	BYTE NameFromDestinationPath	[LGREP];
	BYTE NameFromPath				[LGREP];
	BYTE DestinationPath			[LGREP];
	WORD i = 0;

TRACE
	
	FileName[0]='\0';
	NameFromDestinationPath[0]='\0';
	NameFromPath[0]='\0';
	DestinationPath[0]='\0';

#ifdef DBGTRC
fprintf(fdbgtrc,"\nFichierInit() - Debut\n");
#endif


	/* Nom du module CODE */
	if (typ == RESULTAT) 
	{
		Xfn_parser( DestinationFullPath, DestinationPath, (FILE_NETWORK_NODE | FILE_DEVICE | FILE_PATH));
		Xfn_parser( FullPathFile, NameFromPath, FILE_NAME);
		Xfn_parser( DestinationFullPath, NameFromDestinationPath, FILE_NAME);

		if (NameFromDestinationPath[0]) 
		{
			/* renomage du fichier resultat */
			LibGetNomFic( NameFromDestinationPath, FileName, EXTENSION_AT , DestinationPath );
		}
		else	
		{
			LibGetNomFic( NameFromPath, FileName, EXTENSION_AT , DestinationPath );
		}

		FileInit( &(fic->code), FileName, ECRITURE, &(fic->ent_code) );

		if (NameFromDestinationPath[0]) 
		{
			/* renomage du fichier resultat */
			LibGetNomFic( NameFromDestinationPath, FileName, GlobalExtensionDBG , DestinationPath );
		}
		else	
		{
			LibGetNomFic( NameFromPath, FileName, GlobalExtensionDBG, DestinationPath );
		}

		FileInit( &(fic->dbg), FileName, ECRITURE, &(fic->ent_dbg) );
	}
	else 
	{
		/* type MODULE / PROGRAMME */

		LibGetNomFic( FullPathFile, FileName, EXTENSION_O , DestinationFullPath );
		FileInit( &(fic->code), FileName, LECTURE, &(fic->ent_code) );

		LibGetNomFic( FullPathFile, FileName, GlobalExtensionDBO , DestinationFullPath );
		FileInit( &(fic->dbg), FileName, LECTURE, &(fic->ent_dbg) );
	}

	/* initialise les tables */

	TableInit( &(fic->Tcst) );
	TableInit( &(fic->Tvar) );

	TablePutBin(&(fic->Tvar), 0); /* nombre des variables  */
	TablePutBin(&(fic->Tvar), 0); /* adr_nom de variables */
	TablePutBin(&(fic->Tvar), 0); /* Taille des variables */
	
	
	TableInit( &(fic->Tpro) );
	TableInit( &(fic->Tseg) );
	TableInit( &(fic->Tvarext ));

	/* initialise les listes */


	/*	la liste des noms des constantes binaires */
	for (i=0; i< HTV ; i++) 
	{
		INIT_SLIST(fic->liste_cstbin_pub[ i ]);
	}

	/*	la liste des noms des constantes */
	for (i=0; i< HTV ; i++) 
	{
		INIT_SLIST(fic->liste_cst_pub[ i ]);
	}

	/* 	la liste des bda	*/
	INIT_SLIST( fic->liste_bda );

	/* 	la liste des var  pub	*/
	for (i=0; i< HTV ; i++)
	{
		INIT_SLIST(fic->liste_var_pub[ i ]);
	}

	/* 	la liste des proc pub	*/
	for (i=0; i< HTV ; i++) 
	{
		INIT_SLIST( fic->liste_pro_pub[ i ] );
	}

	/* 	la liste des seg  pub	*/
	for (i=0; i< HTV ; i++) 
	{
		INIT_SLIST( fic->liste_seg_pub[ i ] );
	}
	
	/* 	la liste des sources	*/
	INIT_SLIST( fic->liste_source );

	/* 	la liste des proc. ext. */
	INIT_SLIST( fic->liste_pro_ext );

	/* 	la liste des seg. ext   */
	INIT_SLIST( fic->liste_seg_ext );

	/* 	la liste des seg. ext   */
	INIT_SLIST( fic->liste_var_ext );

	/* 	la liste des modules ext. */
	INIT_SLIST( fic->liste_mod_ext );


	/*	la liste des labels */
	INIT_SLIST( fic->liste_label );

	/*	la liste des tables des points d'ancrages */
	INIT_SLIST( fic->liste_ancrage );

	fic->nb_var_solved = 0;
	fic->nb_pro_solved = 0;
	fic->nb_seg_solved = 0;

	fic->NUM_PRG = 0;

	fic->next_num_seg = MAX_NB_SEG;

#ifdef DBGTRC
fprintf(fdbgtrc,"\nFichierInit() - Fin\n");
#endif

}

/*********************************
*
* FCT FichierGetInfo
*
* Entree : 
*	un fichier en lecture
*	un fichier en reception
*
* Sortie :
*	rien
*
* Remarque :
*	Monte en memoire tables et listes d'un programme (ou module )
*
* Voir aussi:
*
*
*/

VOID FichierGetInfo( fic, dest )
Fichier XPTR * 	fic;
Fichier XPTR * 	dest;
{

TRACE

#ifdef DBGTRC
fprintf(fdbgtrc,"\n FichierGetInfo() - Debut\n");
#endif

	/* initialise les tables */

#ifndef VERSION_XX
	/* #AT: 22/11/00 (begin) */
	bIsGlobalVariable = 0;
	/* #AT: 22/11/00 (end) */
#endif
	FichierInitCst( fic, dest );

#ifndef VERSION_XX
	/* #AT: 22/11/00 (begin) */
	bIsGlobalVariable = 1;
	/* #AT: 22/11/00 (end) */
#endif

	FichierInitVar( fic, dest );

#ifndef VERSION_XX
	/* #AT: 22/11/00 (begin) */
	bIsGlobalVariable = 0;
	/* #AT: 22/11/00 (end) */
#endif
	FichierInitPro( fic, dest );

	FichierInitSeg( fic, dest );

	/* initialise les listes */

	/* 	la liste des bda	*/
	FichierInitNomBda( fic, dest );
	
	/* liste des noms de constantes */
	FichierInitNomCst( fic, dest );
	
	/* 	la liste des var  pub	*/
	FichierInitNomVar( fic, dest );

	/* 	la liste des proc pub	*/
	FichierInitNomPro( fic, dest );
	
	/* 	la liste des seg  pub	*/
	FichierInitNomSeg( fic, dest );
	
	/* 	la liste des sources	*/
	FichierInitNomSource( fic, dest );

	/* 	la liste des var. ext   */
	FichierInitVarExt( fic, dest );

	/*	la liste des labels de variable */
	FichierInitLabel( fic, dest );

	/* 	la liste des proc. ext. */
	FichierInitProExt( fic, dest );

	/* 	la liste des seg. ext   */
	FichierInitSegExt( fic, dest );

	/* 	la liste des modules ext. */
	FichierInitModExt( fic, dest );

#ifdef DBGTRC
fprintf(fdbgtrc,"\n FichierGetInfo() - Fin\n");
#endif
}

/*********************************
*
* FCT FichierLiberer
*
* Entree : 
*	un pointeur sur un fichier
*			
* Sortie :
*	rien
*
* Remarque :
*	Libere toutes les allocations relatives a un fichier 
*
* Voir aussi:
*
*
**********************************/
VOID FichierLiberer( fichier )
Fichier XPTR * fichier;
{
	WORD i;

TRACE

	if (fichier->code.nl == 0 ) return; /* fichier ferme */

	/* on vide les tables */

	TableClose( &(fichier->Tcst) );
	TableClose( &(fichier->Tvar) );
	TableClose( &(fichier->Tpro) );
	TableClose( &(fichier->Tseg) );
	TableClose( &(fichier->Tvarext) );

	/* Supression des listes */

	/* listes des constantes publiques */
	for (i=0; i<HTV; i++)
	{
		ListDel( fichier->liste_cstbin_pub[i] );
		INIT_SLIST( fichier->liste_cstbin_pub[i] );
	}
	/* listes variables publiques */
	for (i=0; i<HTV; i++)
	{
		ListDel( fichier->liste_cst_pub[i] );
		INIT_SLIST( fichier->liste_cst_pub[i] );
	}

	/* listes variables publiques */
	for (i=0; i<HTV; i++)
	{
		ListDel( fichier->liste_var_pub[i] );
		INIT_SLIST( fichier->liste_var_pub[i] );
	}

	/* listes procedures publiques */

	for (i=0; i<HTV; i++)
	{
		ListDelPub( fichier->liste_pro_pub[i] );
		INIT_SLIST( fichier->liste_pro_pub[i] );
	}	

	/* listes segments publiques */
	for (i=0; i<HTV; i++)
	{
		ListDelPub( fichier->liste_seg_pub[i] );
		INIT_SLIST( fichier->liste_seg_pub[i] );
	}	

	/* listes sources publiques */
	ListDel( fichier->liste_source );
	INIT_SLIST( fichier->liste_source );

	/* listes bda publiques */
	ListDel( fichier->liste_bda );
	INIT_SLIST( fichier->liste_bda );

	/* listes procedures externes */
	ListDelExt( fichier->liste_pro_ext );
	INIT_SLIST( fichier->liste_pro_ext );

	/* listes segements externes */
	ListDelExt( fichier->liste_seg_ext );
	INIT_SLIST( fichier->liste_seg_ext );

	/* listes modules externes */
	ListDel( fichier->liste_mod_ext );
	INIT_SLIST( fichier->liste_mod_ext );
	
	/* liste label */
	ListDel( fichier->liste_label );
	INIT_SLIST( fichier->liste_label );

	/* listes ancrage */
	ListDelAncrage( fichier->liste_ancrage );
	INIT_SLIST( fichier->liste_ancrage );

}

/*********************************
*
* FCT FichierOuvrir
*
* Entree : 
*	un pointeur sur un fichier
*			
* Sortie :
*	rien
*
* Remarque :
*	Ouverture d'un fichier .O + .DBO
*
* Voir aussi:
*
*
**********************************/
VOID FichierOuvrir( fic )
Fichier XPTR * fic;
{
	/* #OK: 05/09/00 ALD 7 (begin) */
	int localConstant;
	/* #OK: 05/09/00 ALD 7 (end) */

TRACE

	EcranAction( MessageOuverture );

	FileOpen( &(fic->code) );
	FichierGetEntete( &(fic->code) );

	FileOpen( &(fic->dbg) );
	FichierGetEntete( &(fic->dbg) );

	/* #OK: 05/09/00 ALD 7 (begin) */
	// localConstant = 0 for old version object file
	// localConstant = 1 pragma localConstant does not exist in one of new version object file
	// localConstant = 3 pragma localConstant exists in one of new version object file
	localConstant = (fic->dbg.ent->var_static & 6) >> 1;

	// commonPragma = 0 for old version object file
   // commonPragma = 1 pragma localConstant does not exist in one of new version object file
   // commonPragma = 2 by default
	// commonPragma = 3 pragma localConstant does exist in one of new version object file

	switch (commonPragmaLocalConstant) {
	   case 0: if (localConstant == 1) commonPragmaLocalConstant = 1; 
		       else if (localConstant == 3) 
			   {
				   commonPragmaLocalConstant = 3; 
				   //warning();
			   }
		       break;
	   case 1: if (localConstant == 3)
					/* #BG 28/03/01 Begin */
					/* THROW(MessageLocalConst);*/
					commonPragmaLocalConstant = -1;
					/* #BG 28/03/01 End */
		       break;
	   case 2: commonPragmaLocalConstant = localConstant;		     
		       break;
	   case 3: if (localConstant == 0) ;//warning(); 
		       else if (localConstant == 1)
					/* #BG 28/03/01 Begin */
					/* THROW(MessageLocalConst);*/
					commonPragmaLocalConstant = -1;
					/* #BG 28/03/01 End */
		       break;
	}

	// Clear bits for pragma local constant
	fic->dbg.ent->var_static &= 1;
    /* #OK: 05/09/00 ALD 7 (end) */
}

/*********************************
*
* FCT FichierCreateResult
*
* Entree : 
*	un pointeur sur un fichier programme
*	un pointeur sur un fichier resultat
*		
* Sortie :
*	rien
*
* Remarque :
*	Creation du fichier resultat avec les droits d'acces du programme
*
* Voir aussi:
*	FileResultOpen
*
**********************************/
VOID FichierCreateResult( prg, res )
Fichier XPTR * prg;
Fichier XPTR * res;
{
TRACE
	ULONG RelocE;

	res->NUM_PRG = NUM_RES;

/* #BG 08/10/01 Begin */
#ifdef __WALD__
	if (GlobalShowConsole)
#endif
		if (IsFileOpened(res->code.nom))
		{
			THROW(MessageResultat);
		}
/* #BG 08/10/01 End */

	FileResultOpen( &(prg->code), &(res->code) );
	FileResultOpen( &(prg->dbg), &(res->dbg) );

	FichierInitEntete( &(res->code) );
	FichierInitEntete( &(res->dbg) );

	/* recopier le nom du module */
	XstrCpySize(res->code.ent->nom, prg->code.ent->nom ,sizeof(res->code.ent->nom));

	/* recopie de la taille des fielde */
	/* nombre de bloc de un mega */

	RelocE = ((ULONG) prg->code.ent->reserve) << 20;
	RelocE += ((ULONG) prg->code.ent->lng_xtm) << 4;
	FichierSetRelocEtendue( &(res->code) , RelocE );

/*
	FichierSetRelocEtendue(&(res->code), (ULONG)(FichierGetAdrEtendue(&(prg->code))));
*/

	res->code.ent->l_mxvl = prg->code.ent->l_mxvl;
	res->code.ent->t_mxdl = prg->code.ent->t_mxdl;

	/* initialise le prochain numero de segment a reloger */
	res->next_num_seg     = prg->dbg.ent->max_seg;
}

/*********************************
*	Fonction d'acces au T-Code 
/*********************************
*
* FCT FichierFermer
*
* Entree : 
*	un pointeur sur un fichier
*			
* Sortie :
*	rien
*
* Remarque :
*	Fermeture d'un fichier ( .O et DB? ) et liberation memoire
*
* Voir aussi:
*
*
**********************************/
VOID FichierFermer( fic )
Fichier XPTR * fic;
{
TRACE

	/* liberation de la memoire */
	FichierLiberer( fic );

	FileClose( &(fic->code) );
	if ( fic->code.type == ECRITURE ) 
	{
		if (fic->ent_code.opt & 1) 
		{
			/* le module a ete traduit en mode mise au point */
			FileClose( &(fic->dbg) );
			/* JPH : force to Read/write after close - due to some bizare bug... */
			AttemptToForceReadWrite(fic->dbg.nom, O_RDWR, 0);
		}
		else 
		{
//ODS("Mode mise au point==0 : détruit le .wdg");
			FileDestroy( &(fic->dbg) );
		}

		/* JPH : force to Read/write after close - due to some bizare bug... */
		AttemptToForceReadWrite(fic->code.nom, O_RDWR, 0);
	}
	else	
		FileClose( &(fic->dbg) );
}

/*********************************
*
* FCT FichierDetruire
*
* Entree : 
*	un pointeur sur une table
*			
* Sortie :
*	rien
*
* Remarque :
*	fermeture et destruction d'un fichier
*
* Voir aussi:
*
*
**********************************/
VOID FichierDetruire( fic )
Fichier XPTR * fic;
{
TRACE

	
	/* liberation de la memoire */
	FichierLiberer( fic );

/* #OK: 18/11/99 ALD 10 (begin) */   
   // Remove "readonly" attribute before deleting file.
#ifndef DOS		
   _chmod(fic->code.nom,_S_IREAD|_S_IWRITE);
   _chmod(fic->dbg.nom,_S_IREAD|_S_IWRITE);
#endif
/* #OK: 18/11/99 ALD 10 (end) */   

	FileDestroy( &(fic->code) );
	FileDestroy( &(fic->dbg) );
}

/*********************************
* FCT FichierCrypt
*
* Entree : 
*	cle
*	buffer
*	longueur du buffer a analyser
*	mode cryptage /decryptage
*			
* Sortie :
*	rien
*
* Remarque :
*	fonction de cryptage / decryptage du secteur 0
*
**********************************/

VOID FichierCrypt(pkey, sptr, slen, mode)
WORD pkey;
BYTE XPTR * sptr;
WORD slen;
WORD mode;

/*	Fonction pour la protection du  T-Code
 *	retourne un pointeur sur le buffer converti
 */

{						/* crypt */
	BYTE	exkm[16][16];

	SWORD	kdex,kdey;
	SWORD	rotor,cmpt,x,y,phase;

	cmpt = 0;
	for (x = 0; x < 16 ; x++)
	{
		for ( y =0; y < 16; y++ )
		{
			exkm[x][y] = (BYTE) cmpt; cmpt++;
		}
	}

	rotor = 1; phase = (SWORD) (pkey & 0x0007);
	while ( slen > 0 )
	{
		if ( mode )
		{ 
			kdex = (SWORD) (*sptr / 16);
			kdey = (SWORD) (*sptr % 16);
			switch ( phase ) {
				case 1 : kdey++;
				case 0 : kdex--; break;
				case 2 : kdey++; break;
				case 3 : kdey++; 
				case 4 : kdex++; break;
				case 5 : kdex++;
				case 6 : kdey--; break;
				case 7 : kdex--; kdey--;
			}
		}
		else
		{
			for ( x = 0; x < 16; x++ )
			{
				for ( y = 0; y < 16; y++ )
				{
					if ( exkm[x][y] == *sptr )
					{
						kdex = x; x = 16;
						kdey = y; y = 16;
					}
				}
			}
			switch ( phase )
			{
				case 1 : kdey--;
				case 0 : kdex++; break;
				case 2 : kdey--; break;
				case 3 : kdey--; 
				case 4 : kdex--; break;
				case 5 : kdex--;
				case 6 : kdey++; break;
				case 7 : kdex++; kdey++;
			}
		}
		if ( kdex > 15 ) { kdex = 0; }
		if ( kdey > 15 ) { kdey = 0; }
		if ( kdex < 0 ) { kdex = 15; }
		if ( kdey < 0 ) { kdey = 15; }
		if ((pkey & rotor ) != 0 )
		{
			phase++;
			if ( phase > 7 ) { phase = 0; }
		}
		rotor <<= 1;
		if ( rotor == 0 ) { rotor = 1; }
		*(sptr++) = exkm [ kdex ][ kdey ]; slen--;
	}
}					/* crypt */

/*********************************
*
* FCT FichierInitEntete
*
* Entree : 
*	un pointeur sur une table
*			
* Sortie :
*	rien
*
* Remarque :
*	initialise la structure d'une Table
*
* Voir aussi:
*
*
**********************************/
VOID FichierInitEntete( Tabfic XPTR * pt)			/* chkprg */
{
	pt->ent->secret = 0;

	/* Remplissage de la structure d'entete */

	pt->ent->ver = 0; pt->ent->ind = 0;
	pt->ent->typ = 0;
	
  	pt->ent->nom[0] = EOSTR; 

	pt->ent->opt = 0; 

	pt->ent->exec = 0;
	pt->ent->adr_arg = 0; pt->ent->adr_tcg = 0;
	pt->ent->lng_tcg = 0; pt->ent->adr_tvg = 0;
	pt->ent->lng_tvg = 0; pt->ent->reserve = 0;
	pt->ent->lng_xtm = 0; pt->ent->adr_tsg = 0;
	pt->ent->lng_tsg = 0; pt->ent->adr_tpr = 0;
	pt->ent->lng_tpr = 0; pt->ent->adr_npr = 0;
	pt->ent->l_mxvl = 0; pt->ent->t_mxdl = 0;
	pt->ent->adr_xpro = 0; pt->ent->adr_xvar = 0;
	pt->ent->adr_xcst = 0; pt->ent->nb_regs = 0;
	pt->ent->nb_files = 0; pt->ent->lg_mem = 0;
	pt->ent->lg_stack = 0; 

	pt->ent->adr_map = 0; pt->ent->adr_lst = 0;
	pt->ent->adr_tfu = 0; pt->ent->lng_tfu = 0;
	pt->ent->adr_tdr = 0;

	pt->ent->val_min_bloc = 0;	/* Valeur minimum de blocager 		74 */
	pt->ent->adr_image_tvg = 0;  /* Adresse de l'image des var. glob.	76 */
	pt->ent->lg_image_tvg = 0;	/* Longueur de l'image des var. glo.	78 */
	pt->ent->taille_page = 0;	/* Taille des pages en memoire		80 */
	pt->ent->nb_buf_swap = 0;	/* Nombre de buffers de swap		82 */
	pt->ent->niv_opt = 0;	/* Niveau maximal d'optimisation	84 */
	pt->ent->tnom_seg = 0;	/* Adresse de la table des noms de seg. 86 */
	pt->ent->tseg_ext = 0;	/* Adresse de la table des seg. ext.	88 */
	pt->ent->tancrage = 0;	/* Adresse des noms de modules		90 */
	pt->ent->tnom_modules = 0;	/* Adresse des noms de module		92 */	
	pt->ent->tcor_vg = 0; 	/* Table de corres. des var. glo. 	94 */
	pt->ent->tcor_cst = 0;	/* Table de corres. des cst. 		96 */
	pt->ent->lg_tcor_cst = 0;	/* Longueur de la table de cor. de cst  98 */
	pt->ent->tnom_sources = 0;	/* Adr. de la table des sources        100 */	
	pt->ent->tlabel_var  = 0;	/* Adr. de la table des labels 	       102 */	
	pt->ent->adr_tvarext = 0;	/* Adr de la table des var. ext		104 */
	pt->ent->lgn_tvarext = 0;	/* Longueur de la table des var ext 	106 */
	pt->ent->nom_cstbin  = 0;	/* Adr de la table des noms de cst bin  108 */
	pt->ent->nom_cst     = 0;	/* Adr de la table des noms de cst      110 */
	pt->ent->var_static   = 0;
	pt->ent->max_seg     = 0;	/* Prochain num. segment a reloger */

	/* Test si le programme est valable */
}

/*********************************
*
* FCT FichierGetEntete
*
* Entree : 
*	un pointeur sur une table
*			
* Sortie :
*	rien
*
* Remarque :
*	initialise la structure d'une Table
*
* Voir aussi:
*
*
**********************************/
VOID FichierGetEntete( Tabfic XPTR * pt)			/* chkprg */
{
	WORD secret;

TRACE

	FileGetBloc( pt, pt, 0);		/* lire le bloc 0 */
	
	/* Decrypte */
	
	pt->ofst = 62;

	secret = FileGetBin( pt );

	pt->ent->secret = secret;

	FichierCrypt(secret,&pt->buffer[18],44,FALSE);
	
	/* Remplissage de la structure d'entete */

	pt->ofst = 0;

	pt->ent->ver = FileGetByte( pt ); pt->ent->ind = FileGetByte( pt );
	pt->ent->typ = FileGetByte( pt );
	
  	FileGetStringLg(pt,&(pt->ent->nom[0]),LGNOMPRG); 

	pt->ent->opt = FileGetByte( pt ); 

	pt->ent->exec = FileGetByte( pt );
	pt->ent->adr_arg = FileGetBin( pt ); pt->ent->adr_tcg = FileGetBin( pt );
	pt->ent->lng_tcg = FileGetBin( pt ); pt->ent->adr_tvg = FileGetBin( pt );
	pt->ent->lng_tvg = FileGetBin( pt ); pt->ent->reserve = FileGetBin( pt );
	pt->ent->lng_xtm = FileGetBin( pt ); pt->ent->adr_tsg = FileGetBin( pt );
	pt->ent->lng_tsg = FileGetBin( pt ); pt->ent->adr_tpr = FileGetBin( pt );
	pt->ent->lng_tpr = FileGetBin( pt ); pt->ent->adr_npr = FileGetBin( pt );
	pt->ent->l_mxvl = FileGetBin( pt ); pt->ent->t_mxdl = FileGetBin( pt );
	pt->ent->adr_xpro = FileGetBin( pt ); pt->ent->adr_xvar = FileGetBin( pt );
	pt->ent->adr_xcst = FileGetBin( pt ); pt->ent->nb_regs = FileGetBin( pt );
	pt->ent->nb_files = FileGetBin( pt ); pt->ent->lg_mem = FileGetBin( pt );
	pt->ent->lg_stack = FileGetBin( pt ); 
	pt->ofst = 64;
	pt->ent->adr_map = FileGetBin( pt ); pt->ent->adr_lst = FileGetBin( pt );
	pt->ent->adr_tfu = FileGetBin( pt ); pt->ent->lng_tfu = FileGetBin( pt );
	pt->ent->adr_tdr = FileGetBin( pt );

	pt->ent->val_min_bloc = FileGetBin( pt );	/* Valeur minimum de blocager 		74 */
	pt->ent->adr_image_tvg = FileGetBin( pt );  /* Adresse de l'image des var. glob.	76 */
	pt->ent->lg_image_tvg = FileGetBin( pt );	/* Longueur de l'image des var. glo.	78 */
	pt->ent->taille_page = FileGetBin( pt );	/* Taille des pages en memoire		80 */
	pt->ent->nb_buf_swap = FileGetBin( pt );	/* Nombre de buffers de swap		82 */
	pt->ent->niv_opt = FileGetBin( pt );	/* Niveau maximal d'optimisation	84 */
	pt->ent->tnom_seg = FileGetBin( pt );	/* Adresse de la table des noms de seg. 86 */
	pt->ent->tseg_ext = FileGetBin( pt );	/* Adresse de la table des seg. ext.	88 */
	pt->ent->tancrage = FileGetBin( pt );	/* Adresse des noms de modules		90 */
	pt->ent->tnom_modules = FileGetBin( pt );	/* Adresse des noms de module		92 */	
	pt->ent->tcor_vg = FileGetBin( pt ); 	/* Table de corres. des var. glo. 	94 */
	pt->ent->tcor_cst = FileGetBin( pt );	/* Table de corres. des cst. 		96 */
	pt->ent->lg_tcor_cst = FileGetBin( pt );	/* Longueur de la table de cor. de cst  98 */
	pt->ent->tnom_sources = FileGetBin( pt );	/* Adr. de la table des sources        100 */	
	pt->ent->tlabel_var  = FileGetBin( pt );	/* Adr. de la table des labels 	       102 */	
	pt->ent->adr_tvarext = FileGetBin( pt );	/* Adr de la table des var. ext		104 */
	pt->ent->lgn_tvarext = FileGetBin( pt );	/* Longueur de la table des var ext 	106 */
	pt->ent->nom_cstbin  = FileGetBin( pt );	/* Adr de la table des noms de cst bin  108 */
	pt->ent->nom_cst     = FileGetBin( pt );	/* Adr de la table des noms de cst      110 */
	pt->ent->var_static   = FileGetBin( pt );	/* reserve 				112 */
	pt->ent->max_seg     = FileGetBin( pt );	/* prochain num. segment 		114 */	

	/* Test si le programme est valable */
	MesVerifTcode( pt->ent );
}

/*********************************
*
* FCT FichierPutEntete
*
* Entree : 
*	un pointeur sur un fichier Tabfic
*			
* Sortie :
*	rien
*
* Remarque :
*	Ecrire l'entete d'un fichier
*
* Voir aussi:
*
*
**********************************/
VOID FichierPutEntete( res )
Fichier XPTR * res;
{ 
TRACE
	/*******************/
	/* Fichier Traduit */
	/*******************/

	/* se positionner en debut du secteur 0 */
	FileSeek(&res->code, 0);

	Init_bloc(res->code.buffer);

	FilePutByte(&res->code,res->code.ent->ver); FilePutByte(&res->code,res->code.ent->ind);
#ifdef	VERSION_XX
	if (!( first_version ))
		FilePutByte(&res->code,res->code.ent->typ);
	else	FilePutByte(&res->code,first_version);
#else
	FilePutByte(&res->code,res->code.ent->typ);
#endif
	FilePutStringLg(&res->code,&res->code.ent->nom[0],LGNOMPRG);
	FilePutByte(&res->code,res->code.ent->opt); FilePutByte(&res->code,res->code.ent->exec);
	FilePutBin(&res->code,res->code.ent->adr_arg); FilePutBin(&res->code,res->code.ent->adr_tcg);
	FilePutBin(&res->code,res->code.ent->lng_tcg); FilePutBin(&res->code,res->code.ent->adr_tvg);
	FilePutBin(&res->code,res->code.ent->lng_tvg); FilePutBin(&res->code,res->code.ent->reserve);
	FilePutBin(&res->code,res->code.ent->lng_xtm); FilePutBin(&res->code,res->code.ent->adr_tsg);
	FilePutBin(&res->code,res->code.ent->lng_tsg); FilePutBin(&res->code,res->code.ent->adr_tpr);
	FilePutBin(&res->code,res->code.ent->lng_tpr); FilePutBin(&res->code,res->code.ent->adr_npr);
	FilePutBin(&res->code,res->code.ent->l_mxvl); FilePutBin(&res->code,res->code.ent->t_mxdl);
	FilePutBin(&res->code,res->code.ent->adr_xpro); FilePutBin(&res->code,res->code.ent->adr_xvar);
	FilePutBin(&res->code,res->code.ent->adr_xcst); FilePutBin(&res->code,res->code.ent->nb_regs);
	FilePutBin(&res->code,res->code.ent->nb_files); FilePutBin(&res->code,res->code.ent->lg_mem);
	FilePutBin(&res->code,res->code.ent->lg_stack); 
	FilePutBin(&res->code,res->code.ent->secret);

	FilePutBin(&res->code,res->code.ent->adr_map); FilePutBin(&res->code,res->code.ent->adr_lst);
	FilePutBin(&res->code,res->code.ent->adr_tfu); FilePutBin(&res->code,res->code.ent->lng_tfu);
	FilePutBin(&res->code,res->code.ent->adr_tdr);

	FilePutBin(&res->code,res->code.ent->val_min_bloc);   
	FilePutBin(&res->code,res->code.ent->adr_image_tvg);  
	FilePutBin(&res->code,res->code.ent->lg_image_tvg);   
	FilePutBin(&res->code,res->code.ent->taille_page);    
	FilePutBin(&res->code,res->code.ent->nb_buf_swap);    
	FilePutBin(&res->code,res->code.ent->niv_opt);        
	FilePutBin(&res->code,res->code.ent->tnom_seg);       
	FilePutBin(&res->code,res->code.ent->tseg_ext);       
	FilePutBin(&res->code,res->code.ent->tancrage);       

	/* A completer */
	FilePutBin(&res->code,res->code.ent->tnom_modules );	/* Adresse des noms de module		92 */	
	FilePutBin(&res->code,res->code.ent->tcor_vg); 	/* Table de corres. des var. glo. 	94 */
	FilePutBin(&res->code,res->code.ent->tcor_cst);	/* Table de corres. des cst. 		96 */
	FilePutBin(&res->code,res->code.ent->lg_tcor_cst);	/* Longueur de la table de cor. de cst  98 */
	FilePutBin(&res->code,res->code.ent->tnom_sources);	/* Adr. de la table des sources        100 */	
	FilePutBin(&res->code,res->code.ent->tlabel_var);	/* Adr. de la table des labels 	       102 */	
	FilePutBin(&res->code,res->code.ent->adr_tvarext );	/* Adr de la table des var. ext		104 */
	FilePutBin(&res->code,res->code.ent->lgn_tvarext );	/* Longueur de la table des var ext     106 */
	FilePutBin(&res->code,res->code.ent->nom_cstbin  );	/* Adr de la table des noms de cst bin  108 */
	FilePutBin(&res->code,res->code.ent->nom_cst     );	/* Adr de la table des noms de cst      110 */
	FilePutBin(&res->code,res->code.ent->var_static   );	/* Adr de la table des noms de cst      112 */
	FilePutBin(&res->code,res->code.ent->max_seg     );	/* Adr de la table des noms de cst      114 */

  	FichierCrypt(res->code.ent->secret,&res->code.buffer[18],44,TRUE);

	/* ecrire le premier secteur */
	FileWrite( &res->code, res->code.buffer, LGBLOC);
	
	/*******************/
	/* Fichier DBG     */
	/*******************/

	if (res->ent_code.opt & 1)
	{
		/* se positionner en debut du secteur 0 */
		FileSeek( &res->dbg, 0);
	
		Init_bloc( res->dbg.buffer );
	
		FilePutByte(&res->dbg,res->dbg.ent->ver) ; FilePutByte(&res->dbg,res->dbg.ent->ind);
		FilePutByte(&res->dbg,res->dbg.ent->typ);
		FilePutStringLg(&res->dbg,&res->dbg.ent->nom[0],LGNOMPRG);
		FilePutByte(&res->dbg,res->dbg.ent->opt); FilePutByte(&res->dbg,res->dbg.ent->exec);
		FilePutBin(&res->dbg,res->dbg.ent->adr_arg); FilePutBin(&res->dbg,res->dbg.ent->adr_tcg);
		FilePutBin(&res->dbg,res->dbg.ent->lng_tcg); FilePutBin(&res->dbg,res->dbg.ent->adr_tvg);
		FilePutBin(&res->dbg,res->dbg.ent->lng_tvg); FilePutBin(&res->dbg,res->dbg.ent->reserve);
		FilePutBin(&res->dbg,res->dbg.ent->lng_xtm); FilePutBin(&res->dbg,res->dbg.ent->adr_tsg);
		FilePutBin(&res->dbg,res->dbg.ent->lng_tsg); FilePutBin(&res->dbg,res->dbg.ent->adr_tpr);
		FilePutBin(&res->dbg,res->dbg.ent->lng_tpr); FilePutBin(&res->dbg,res->dbg.ent->adr_npr);
		FilePutBin(&res->dbg,res->dbg.ent->l_mxvl); FilePutBin(&res->dbg,res->dbg.ent->t_mxdl);
		FilePutBin(&res->dbg,res->dbg.ent->adr_xpro); FilePutBin(&res->dbg,res->dbg.ent->adr_xvar);
		FilePutBin(&res->dbg,res->dbg.ent->adr_xcst); FilePutBin(&res->dbg,res->dbg.ent->nb_regs);
		FilePutBin(&res->dbg,res->dbg.ent->nb_files); FilePutBin(&res->dbg,res->dbg.ent->lg_mem);
		FilePutBin(&res->dbg,res->dbg.ent->lg_stack); 
		FilePutBin(&res->dbg,res->dbg.ent->secret);
	
		FilePutBin(&res->dbg,res->dbg.ent->adr_map); FilePutBin(&res->dbg,res->dbg.ent->adr_lst);
		FilePutBin(&res->dbg,res->dbg.ent->adr_tfu); FilePutBin(&res->dbg,res->dbg.ent->lng_tfu);
		FilePutBin(&res->dbg,res->dbg.ent->adr_tdr);

		FilePutBin(&res->dbg,res->dbg.ent->val_min_bloc);   
		FilePutBin(&res->dbg,res->dbg.ent->adr_image_tvg);  
		FilePutBin(&res->dbg,res->dbg.ent->lg_image_tvg);   
		FilePutBin(&res->dbg,res->dbg.ent->taille_page);
		FilePutBin(&res->dbg,res->dbg.ent->nb_buf_swap);    
		FilePutBin(&res->dbg,res->dbg.ent->niv_opt);        
		FilePutBin(&res->dbg,res->dbg.ent->tnom_seg);       
		FilePutBin(&res->dbg,res->dbg.ent->tseg_ext);       
		FilePutBin(&res->dbg,res->dbg.ent->tancrage);       
		FilePutBin(&res->dbg,res->dbg.ent->tnom_modules );	/* Adresse des noms de module		92 */	
		FilePutBin(&res->dbg,res->dbg.ent->tcor_vg); 		/* Table de corres. des var. glo. 	94 */
		FilePutBin(&res->dbg,res->dbg.ent->tcor_cst);		/* Table de corres. des cst. 		96 */
		FilePutBin(&res->dbg,res->dbg.ent->lg_tcor_cst);	/* Longueur de la table de cor. de cst  98 */
		FilePutBin(&res->dbg,res->dbg.ent->tnom_sources);	/* Adr. de la table des sources        100 */	
		FilePutBin(&res->dbg,res->dbg.ent->tlabel_var);		/* Adr. de la table des labels 	       102 */	
		FilePutBin(&res->dbg,res->code.ent->adr_tvarext );	/* Adr de la table des var. ext		104 */
		FilePutBin(&res->dbg,res->code.ent->lgn_tvarext );	/* Longueur de la table des var ext     106 */
		FilePutBin(&res->dbg,res->code.ent->nom_cstbin  );	/* Adr de la table des noms de cst bin  108 */
		FilePutBin(&res->dbg,res->code.ent->nom_cst     );	/* Adr de la table des noms de cst      110 */
		FilePutBin(&res->dbg,res->code.ent->var_static   );	/* reserve                              112 */
		FilePutBin(&res->dbg,res->code.ent->max_seg     );	/* max seg                              114 */

	  	FichierCrypt(res->dbg.ent->secret,&res->dbg.buffer[18],44,TRUE);
	
		/* ecrire le premier secteur */
		FileWrite(&res->dbg, res->dbg.buffer, LGBLOC);
	}	
}

/*********************************
*
* FCT FichierResultConstruct
*
* Entree : 
*	un fichier origine
*	le fichier resultat
*			
* Sortie :
*	rien
*
* Remarque :
*	Construction du traduit final
*
* Voir aussi:
*
*
**********************************/
VOID FichierResultConstruct(prg, res)
Fichier XPTR * prg;
Fichier XPTR * res;
{ 
	BYTE i;

TRACE
	EcranAction( MessageConstruct );
	EcranEnCours( res->code.nom );
 
	/* Entete Code */

	res->code.ent->ver = prg->code.ent->ver;
	res->code.ent->ind = prg->code.ent->ind;
	res->code.ent->typ = prg->code.ent->typ;

	for (i=0; i < LGNOMPRG - 1; i++) {
		res->code.ent->nom[i] = prg->code.ent->nom[i];
	}	

	res->code.ent->opt |= prg->code.ent->opt;

	/* Test si le programme est executable */

	res->code.ent->exec = 0;
	res->code.ent->adr_arg = prg->code.ent->adr_arg;

	/* table des constantes */
	if ( TableIsVide( &(res->Tcst)))
	{
		res->code.ent->adr_tcg = 0;	/* pas de constante */
		res->code.ent->lng_tcg = 0;
	}
	else
	{
		FichierCstConstruct( res );
	}
	
	/* table des variables globales */

	if ( TableIsVide( &(res->Tvar) ) )
	{
		res->code.ent->adr_tvg = 0; /* Pas de variables globales */
		res->code.ent->lng_tvg = 0;	
	}
	else
	{

		FichierVarConstruct( res );
	}

	/* Longueur de la memoire etendue */
	/* Deja utilisee dans FIchierInitVariable */

	/* table des procedures */

	if ( TableIsVide( &(res->Tpro) ) )
	{
		/* pas de procedure */
		res->code.ent->adr_tpr = 0;
		res->code.ent->lng_tpr = 0;
	}
	else
	{
		/* 1 ere passe pour mettre a jour les num. de bloc */
		FichierProConstruct( prg, res );
	}

	/* table des noms de procedures */

	res->code.ent->adr_npr = 0; /* pas de nom de procedure dans le code */

	/* table des segments */

	FichierSegConstruct( prg, res );

	/* table des procedures externes */

	res->code.ent->adr_xpro = 0; /* a priori toutes les references ont ete resolues */
	res->code.ent->adr_xvar = 0;
	res->code.ent->adr_xcst = 0;

	/* informations parametres */
	res->code.ent->nb_regs = prg->code.ent->nb_regs;
	res->code.ent->nb_files = prg->code.ent->nb_files;
	res->code.ent->lg_mem = prg->code.ent->lg_mem;
	res->code.ent->lg_stack = prg->code.ent->lg_stack;

	res->code.ent->secret = prg->code.ent->secret;
	
	/* information debug c'est dans le dbg */
	
	res->dbg.ent->adr_map = 0;
	res->dbg.ent->adr_lst = 0;

	/* fonctions utilisateurs */

	if (SlistCount( res->liste_bda ) == 0 )
	{
		res->code.ent->adr_tfu = 0;
		res->code.ent->lng_tfu = 0;
	}
	else
	{
		FichierBdaConstruct( res ); 
	}

	res->code.ent->adr_tdr = 0;	/* Plus de relocation */

	res->code.ent->val_min_bloc   = prg->code.ent->val_min_bloc;   
	res->code.ent->adr_image_tvg  = prg->code.ent->adr_image_tvg;  
	res->code.ent->lg_image_tvg	= prg->code.ent->lg_image_tvg;
	res->code.ent->taille_page	= prg->code.ent->taille_page;
	res->code.ent->nb_buf_swap	= prg->code.ent->nb_buf_swap;
	res->code.ent->niv_opt	= prg->code.ent->niv_opt;

	/* 	liste des noms de segment 	*/
	/* 	a mettre si debug		*/	

	res->code.ent->tnom_seg	= 0;       
	res->code.ent->tseg_ext	= 0;       
	res->code.ent->tancrage	= 0;       

	/* liste des noms de module */
	res->code.ent->tnom_modules	= 0;
	res->code.ent->tcor_vg =0;
	res->code.ent->tcor_cst = 0;
	res->code.ent->lg_tcor_cst = 0;
	res->code.ent->tnom_sources = 0 ;
	res->code.ent->tlabel_var = 0;
	res->code.ent->adr_tvarext = 0;
	res->code.ent->lgn_tvarext = 0;
	res->code.ent->nom_cstbin  = 0;
	res->code.ent->nom_cst 	 = 0;

	/**************/
	/* Entete DBG */
	/**************/

	EcranEnCours( res->dbg.nom );

	res->dbg.ent->ver = prg->dbg.ent->ver;
	res->dbg.ent->ind = prg->dbg.ent->ind;
	res->dbg.ent->typ = prg->dbg.ent->typ;

	for (i=0; i < LGNOMPRG - 1; i++)
	{
		res->dbg.ent->nom[i] = prg->dbg.ent->nom[i];
	}	

	res->dbg.ent->opt |= prg->dbg.ent->opt;
	/* Test si le programme est executable */

	res->dbg.ent->exec = 0;

	res->dbg.ent->adr_arg = prg->dbg.ent->adr_arg;

	/* table des constantes */

	res->dbg.ent->adr_tcg = 0; 	/* pas de constante dans le dbg */
	res->dbg.ent->lng_tcg = 0;
	
	/* table des variables globales */

	res->dbg.ent->adr_tvg = 0; /* Pas de variables globales dans le dbg */
	res->dbg.ent->lng_tvg = 0;	

	/* Longueur de la memoire etendue */

	res->dbg.ent->reserve = 0;
	res->dbg.ent->lng_xtm = 0;

	/* table des procedures */

	/* pas de procedure */
	res->dbg.ent->adr_tpr = 0;
	res->dbg.ent->lng_tpr = 0;

	/* table des noms de procedures */

	if (( res->ent_code.opt & 1 ) && ( ListCountHashList( res->liste_pro_pub) != 0 ) )
	{
		/* Noms de procedure */
		FichierNomProConstruct( prg, res );
	}
	else
	{
		res->dbg.ent->adr_npr = 0;	/* pas de nom de procedure */
	}	

	/* variables locales */

	res->dbg.ent->l_mxvl = 0;
	res->dbg.ent->t_mxdl = 0;

	/* table des procedures externes */

	res->dbg.ent->adr_xpro = 0; /* a priori toutes les references ont ete resolues */
	res->dbg.ent->adr_xvar = 0;
	res->dbg.ent->adr_xcst = 0;

	/* informations parametres */
	res->dbg.ent->nb_regs = 0;
	res->dbg.ent->nb_files = 0;
	res->dbg.ent->lg_mem = 0;
	res->dbg.ent->lg_stack = 0;

	res->dbg.ent->secret = prg->dbg.ent->secret;
	
	res->dbg.ent->adr_lst = 0;

	/* fonctions utilisateurs */

	res->dbg.ent->adr_tfu = 0;

	/* Modif du 17/02/90 */
	res->dbg.ent->lng_tfu = 0;

	res->dbg.ent->adr_tdr = 0;	/* Plus de relocation */

	res->dbg.ent->val_min_bloc   = 0;
	res->dbg.ent->adr_image_tvg  = 0;
	res->dbg.ent->lg_image_tvg	= 0;
	res->dbg.ent->taille_page	= 0;
	res->dbg.ent->nb_buf_swap	= 0;
	res->dbg.ent->niv_opt	= 0;

	/* 	liste des noms de segment 	*/
	/* 	a mettre si debug		*/	

	if (( res->ent_code.opt & 1 ) && ( ListCountHashList( res->liste_seg_pub) != 0 ) )
	{
		/* Noms de procedure */
		FichierNomSegConstruct( prg, res);
	}
	else
	{
		res->dbg.ent->adr_npr = 0;	/* pas de nom de procedure */
	}	
	res->dbg.ent->tseg_ext	= 0;       
	res->dbg.ent->tancrage	= 0;       

	/* liste des noms de module */
	res->dbg.ent->tnom_modules = 0;
	res->dbg.ent->tcor_vg = 0;
	res->dbg.ent->tcor_cst = 0;
	res->dbg.ent->lg_tcor_cst = 0;
	res->dbg.ent->tlabel_var = 0;
	res->dbg.ent->adr_tvarext = 0;
	res->dbg.ent->lgn_tvarext = 0;

	/* liste des noms de module */
	if (( res->ent_code.opt & 1 ) && ( SlistCount( res->liste_source ) != 0 ) )
	{
		/* Noms de procedure */
		FichierSourceConstruct( res );
	}
	else
	{
		res->dbg.ent->tnom_sources = 0;	/* pas de nom de procedure */
	}	

	/* Patcher les blocs */
 	ListPatcher( res ); 

	/* putentete */
	FichierPutEntete( res );
	/* Pour prologue */

	FilePadding( &res->code );	/* padding du granule a zero */
	FilePadding( &res->dbg );	/* padding du granule a zero */

	FichierFermer( res );

}

/* Init */

/*********************************
* FCT FichierInitCst
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Construction de la table des Constantes Globales
*
**********************************/

VOID FichierInitCst( fic, dest )
Fichier XPTR * fic;
Fichier XPTR * dest;
{ 
	Tabfic XPTR * pt;
	WORD desc;
	WORD bloc;
	WORD off;
#ifdef DEBUG
	FILE * trace;
#endif
TRACE

	pt = &(fic->code);

	if (pt->ent->adr_tcg == 0) return; /* Ce module n' a pas de cst */


	TableGetFromFile( pt, &(dest->Tcst), pt->ent->adr_tcg, pt->ent->lng_tcg);

	pt = &(fic->dbg);

	if (pt->ent->adr_xcst == 0 ) return;
	FileGetBloc( pt, pt, pt->ent->adr_xcst );
#ifdef DEBUG
trace = fopen(TranslateLongPathName("relo.cst"),"w");
#endif
	desc = FileGetBin( pt );

	while( desc != MOINS_UN)
	{
#ifdef DEBUG
fprintf(trace,"\n Desc : %x \n", desc);
#endif
		bloc = FileGetBin( pt );
		while ( bloc != 0 )
		{
			off  = FileGetBin( pt );
#ifdef DEBUG
fprintf(trace,"\n %d : %x \n",bloc,off);
#endif
			ListMajPatch(0,fic->NUM_PRG, &(fic->code),bloc, off, MOINS_UN );
			bloc = FileGetBin( pt );
		}
		desc = FileGetBin( pt );
	}

#ifdef DEBUG
	fclose(trace);
#endif
}

/*********************************
* FCT FichierInitVar
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Construction de la table des Variables Globales
*
**********************************/

VOID FichierInitVar( fic, dest )
Fichier XPTR * fic;
Fichier XPTR * dest;
{ 
	Tabfic XPTR * pt;
	WORD desc;
	WORD bloc;
	WORD off;

#ifdef DEBUG
	FILE * trace;
#endif
TRACE
	pt = &(fic->code);


	if (pt->ent->adr_tvg == 0) return; /* Ce module n' a pas de variable */

	TableGetFromFile( pt, &(dest->Tvar), pt->ent->adr_tvg, pt->ent->lng_tvg);

	/* reserve et xtm contiennene la longueur du field = e */


	/* Inserer la liste des relocations au cas ou des procedures
		ou des segments sont reloges
	*/

	pt = &(fic->dbg) ;
	if ( pt->ent->adr_xvar == 0 ) return;

	FileGetBloc(pt, pt, pt->ent->adr_xvar);
#ifdef DEBUG
	trace = fopen(TranslateLongPathName("relo.var"),"w");
#endif
	desc = FileGetBin( pt );
	while( desc != MOINS_UN)
	{
#ifdef DEBUG
		fprintf(trace,"\n Desc : %x (%d,%x)\n", desc, pt->bloc, pt->ofst);
#endif
		bloc = FileGetBin( pt );

		while ( bloc != 0 )
		{
			off  = FileGetBin( pt );
#ifdef DEBUG
fprintf(trace,"%d : %x \n",bloc,off);
#endif
			ListMajPatch(0,fic->NUM_PRG, &(fic->code),bloc, off, MOINS_UN );
			bloc = FileGetBin( pt );
		}
		desc = FileGetBin( pt );
	}
#ifdef DEBUG
	fclose(trace);
#endif
}

/*********************************
* FCT FichierInitPro
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Construction de la table des Procedures
*
**********************************/

VOID FichierInitPro( fic, dest )
Fichier XPTR * fic;
Fichier XPTR * dest;
{
	Tabfic XPTR * pt;

TRACE
	pt = &(fic->code);

	if (pt->ent->adr_tpr == 0) return; /* Ce module n' a pas de cst */

	TableGetFromFile( pt, &(dest->Tpro), pt->ent->adr_tpr, pt->ent->lng_tpr);

}

/*********************************
* FCT FichierInitSeg
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Construction de la table des Segments
*
**********************************/

VOID FichierInitSeg( fic, dest )
Fichier XPTR * fic;
Fichier XPTR * dest;
{ 

	Tabfic XPTR * pt;

TRACE
	pt = &(fic->code);

	if (pt->ent->adr_tsg == 0) 
		return; /* Ce module n' a pas de segments */

	TableGetFromFile( pt, &(dest->Tseg), pt->ent->adr_tsg, (WORD) (pt->ent->lng_tsg - 2) );

}

/*-------------------------- */
/* Init des listes PUBLIQUES */
/*-------------------------- */

/*********************************
* FCT FichierInitNomCst
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Construction de la liste des noms de constantes
*
**********************************/
VOID FichierInitNomCst( fic, dest )
Fichier XPTR * fic;
Fichier XPTR * dest;
{ 
	Tabfic XPTR * pt;
	WORD nb_args;
	C_SNODE FAR * 	node_pro;

	/*	creation d'un descripteur local */

	BYTE 	  nomp[LGIDENT+1]; /* +1 pour EOSTR */
	WORD      relo_proc, proc_app,adr_map,lg_map;
	WORD      hlv, htv;
	ModPro XPTR * pt_proc;

TRACE

	pt = &(fic->dbg);

	/* Noms de constantes BCD / CHAINE */
	ListCreateHashList( dest->liste_cst_pub );
	ListCreateHashList( dest->liste_cstbin_pub );

	if (pt->ent->nom_cst == 0) return; /* Ce module n' a pas de cst */
	

	FileGetBloc(pt,pt,pt->ent->nom_cst);
	FileGetString(pt, nomp);
	while (nomp[0])
	{

		/* la hliste se fait sur le numero de descripteur */
		ListCalculHashValue(nomp, &htv, &hlv);

		/*
			la liste est repartie sur le numero de descripteur et
			non sur le nom
		*/

		/* descritpeur */
		relo_proc = FileGetBin( pt );

		/* adr table des pros appele */
		proc_app = 0;

		/* adr de la table des correspondances */
		adr_map = 0;
		lg_map  = 0;

		nb_args = 0;

		/* creation d'une procedure */
		if (pt->ent->exec == 3)
		{
			/* C'est un traduit module */
			/* l'organisation est faite sur le numero de descripteur */

			htv = relo_proc % HTV;
		}

		/* reservation de la structure dans la liste */
		/* insertion en tete de liste */
		node_pro = SnodeCreate();
		SlistAddHead( dest->liste_cst_pub[htv], node_pro );

		/* Creation d'une procedure sans argument */
		pt_proc = ListNewPro(nomp, dest->NUM_PRG, relo_proc, proc_app, adr_map,lg_map,nb_args,hlv);

		if ( fic->NUM_PRG == 0)
		{
			/* Les procedures du programme sont relog‚es de fait */
			pt_proc->used = relo_proc;
		}

		SnodeSet( node_pro, pt_proc );

		FileGetString(pt, nomp);
	}

	/* Noms de constantes DIESE / POURCENT */

	if (pt->ent->nom_cstbin == 0) return; /* Ce module n' a pas de cst binaire */


	FileGetBloc(pt,pt,pt->ent->nom_cstbin);

	FileGetString(pt, nomp);

	while (nomp[0])
	{

		/* la hliste se fait sur le numero de descripteur */
		ListCalculHashValue(nomp, &htv, &hlv);

		/*
			la liste est repartie sur le numero de descripteur et
			non sur le nom
		*/


		/* valeur */
		relo_proc = FileGetBin( pt );

		/* adr table des pros appele */
		proc_app = 0;

		/* adr de la table des correspondances */
		adr_map = 0;
		lg_map  = 0;

		nb_args = 0;

		/* creation d'une procedure */
		if (pt->ent->exec == 3)
		{
			/* C'est un traduit module */
			/* l'organisation est faite sur le numero de descripteur */

			htv = relo_proc % HTV;
		}

		/* reservation de la structure dans la liste */
		/* insertion en tete de liste */
		node_pro = SnodeCreate();
		SlistAddHead( dest->liste_cstbin_pub[htv], node_pro );

		/* Creation d'une procedure sans argument */
		pt_proc = ListNewPro(nomp, dest->NUM_PRG, relo_proc, proc_app, adr_map,lg_map,nb_args,hlv);

		pt_proc->used = relo_proc;

		SnodeSet( node_pro, pt_proc );

		FileGetString(pt, nomp);
	}
}

/*********************************
* FCT FichierInitNomVar
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Construction de la liste des noms de variables
*
**********************************/
VOID FichierInitNomVar( fic, dest )
Fichier XPTR * fic;
Fichier XPTR * dest;
{ 
	C_SNODE	FAR *	node;
	Tabfic XPTR *	pt;
	ModPro	XPTR *	pt_nomvar;
	WORD		adr_nom;
	BYTE 		nom[LGIDENT];
	WORD		nb_var;
	WORD		num_desc;
	WORD		htv;
	WORD		hlv;
TRACE

	pt = &(fic->dbg);

	ListCreateHashList( dest->liste_var_pub ) ;
	if (TableIsVide( &(dest->Tvar) ) ) return;

	TableSeek( &(dest->Tvar), 0);
	nb_var  = TableGetVarNb( &(dest->Tvar) );
	adr_nom = TableGetVarNom( &(dest->Tvar) );

	if ( adr_nom )
	{
		FileGetBloc( pt, pt, adr_nom );
		while ( nb_var )
		{
			FileGetString( pt, nom );
			num_desc = FileGetBin( pt );

			ListCalculHashValue(nom, &htv, &hlv);

			/* hashed on num_desc */

			htv = num_desc % HTV;
						
			ALLOC_SNODE( node );

			SlistAddHead( dest->liste_var_pub[htv], node );

			pt_nomvar = ListNewPro(nom, dest->NUM_PRG, num_desc, 0, 0, 0, 0, hlv);

			if (fic->NUM_PRG == 0)
			{
				/* Les noms de variables du programme sont relogés de fait */
				pt_nomvar->used = num_desc;
			}

			SnodeSet( node, pt_nomvar );

			nb_var --;
		}		
	}
}


/*********************************
* FCT FichierInitNomPro
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Construction de la liste des procedures
*
**********************************/
VOID FichierInitNomPro( fic, dest )
Fichier XPTR * fic;	/* liste des noms de procedures */
Fichier XPTR * dest;
{ 
	WORD nb_proc;
	Tabfic XPTR * pt;
	WORD j,nb,nb_args;

	Args XPTR *	pt_arg;
	C_SNODE FAR * 	node_arg;
	C_SNODE FAR * 	node_pro;

	/*	creation d'un descripteur local */

	BYTE 	  nomp[LGIDENT+1]; /* +1 pour EOSTR */
	WORD      relo_proc, proc_app,adr_map,lg_map;
	WORD      hlv, htv;
	ModPro XPTR * pt_proc;
	
TRACE
	pt = &fic->dbg;

	ListCreateHashList( dest->liste_pro_pub );

	if (pt->ent->adr_npr == 0) return; /* Pas de nom de procedure */


	FileGetBloc(pt,pt,pt->ent->adr_npr);
	nb_proc = FileGetBin( pt );	/* nb de noms de procedures */
		
	nb = nb_proc;
	while (nb--)
	{
		FileGetString(pt, nomp);

		/* la hliste se fait sur le numero de descripteur */
		ListCalculHashValue(nomp, &htv, &hlv);

		/*
			la liste est repartie sur le numero de descripteur et
			non sur le nom
		*/

		/* descritpeur */
		relo_proc = FileGetBin( pt );

		/* adr table des pros appele */
		proc_app = FileGetBin( pt );

		/* adr de la table des correspondances */
		adr_map = FileGetBin( pt );
		lg_map  = FileGetBin( pt );

		nb_args = FileGetBin( pt );

		/* creation d'une procedure */
		if (pt->ent->exec == 3)
		{
			/* C'est un traduit module */
			/* l'organisation est faite sur le numero de descripteur */

			htv = relo_proc % HTV;
		}

		/* reservation de la structure dans la liste */
		/* insertion en tete de liste */
		node_pro = SnodeCreate();
		SlistAddHead( dest->liste_pro_pub[htv], node_pro );

		/* Creation d'une procedure sans argument */
		pt_proc = ListNewPro(nomp, dest->NUM_PRG, relo_proc, proc_app, adr_map,lg_map,nb_args,hlv);

		if ( fic->NUM_PRG == 0)
		{
			/* Les procedures du programme sont relogées de fait */
			pt_proc->used = relo_proc;
		}

		SnodeSet( node_pro, pt_proc );

		/* Attention nb arg / valeur de retour */

		j = (WORD)(nb_args & MASK_NB_ARGS);
		ALLOC_SLIST( pt_proc->pt_args );

		while(j--)
		{
			/* L'ordre est important */

			/* insertion en tete */
			ALLOC_SNODE( node_arg );
			SlistAddHead( pt_proc->pt_args, node_arg );			

			pt_arg = ListNewArgs( (BYTE) FileGetByte( pt ) );
			
			SnodeSet( node_arg, pt_arg );						
		}
	}
}

/*********************************
* FCT FichierInitNomSeg
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Construction de la liste des noms de segments
*
**********************************/
VOID FichierInitNomSeg( fic, dest )
Fichier XPTR * fic;	/* liste des noms de procedures */
Fichier XPTR * dest;	/* liste receptive */
{ 
	Tabfic XPTR * pt;
	WORD nb,nb_seg;
	/*	creation d'un descripteur local */

	WORD relo_seg;
	BYTE 	  nomp[LGIDENT+1]; /* +1 pour EOSTR */
	WORD   num_seg;
	WORD   proc_app;
	WORD   adr_map;
	WORD   lg_map;
	WORD htv, hlv;
	ModPro XPTR * pt_proc;
	C_SNODE FAR * node_seg;

TRACE

	pt = &fic->dbg;

	ListCreateHashList( dest->liste_seg_pub );

	if (pt->ent->tnom_seg == 0) return; /* Pas de nom de segment */


	FileGetBloc(pt,pt,pt->ent->tnom_seg);

	nb_seg = FileGetBin( pt );	/* nb de noms de segment */

	nb = nb_seg;
	while (nb--)
	{

		FileGetString(pt, nomp);

		/* descritpeur */

		num_seg = FileGetBin( pt );

		relo_seg = FileGetBin( pt );

		/* adr table des procs appeler par le segment */
		proc_app = FileGetBin( pt );

		/* adresse de la table de correspondance */
		adr_map  = FileGetBin( pt );

		/* longeur de la table des correspondances */
		lg_map   = FileGetBin( pt );

		/* la hliste se fait sur le numero de descripteur */
		ListCalculHashValue(nomp, &htv, &hlv);
		/*
			la liste est repartie sur le numero de descripteur et
			non sur le nom
		*/

		if (pt->ent->exec == 3)
		{
			/* C'est un traduit module */
			/* l'organisation est faite sur le numero de descripteur */

			htv = relo_seg % HTV;
		}

		/* reservation de la structure dans la liste */
		/* insertion en tete */

		node_seg = SnodeCreate();
		SlistAddHead( dest->liste_seg_pub[htv], node_seg );

		pt_proc = ListNewPro(nomp, dest->NUM_PRG, relo_seg, proc_app, adr_map,lg_map,num_seg,hlv);

		if (fic->NUM_PRG == 0)
		{
			/* Les segments du programme sont relogés de fait */
			pt_proc->used = num_seg;
		}
		SnodeSet( node_seg, pt_proc );
	}
}

/*********************************
* FCT FichierInitNomSource
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Construction de la liste des noms de sources 
*
**********************************/
VOID FichierInitNomSource( fic, dest )
Fichier XPTR * fic;	/* liste des noms de procedures */
Fichier XPTR * dest;
{ 
	Tabfic XPTR * pt;
	WORD nb_sources;
	BYTE nom[LGREP];

TRACE
	pt = &fic->dbg;

	ALLOC_SLIST( dest->liste_source );

	if (pt->ent->tnom_sources == 0) return;


	FileGetBloc(pt, pt, pt->ent->tnom_sources );
	nb_sources = FileGetBin( pt );
	while (nb_sources != MOINS_UN )
	{
		FileGetString( pt, nom );
		ListAddName( dest->liste_source, nom, nb_sources );
		nb_sources = FileGetBin( pt );
	}

}

/*********************************
* FCT FichierInitNomBda
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Construction de la liste des noms de BDA
*
**********************************/
VOID FichierInitNomBda( prg, dest )
Fichier XPTR * prg;	/* liste des noms de procedures */
Fichier XPTR * dest;
{
	WORD i,j;
	WORD nb_bib;
	Tabfic XPTR * pt;
	Bibli bda;
	Bibli XPTR * pt_bda;
	C_SNODE FAR * node;

#ifdef ver21
	WORD bloc_bda;
	WORD ofst_bda;
	BYTE num_bda;
	BYTE current_bda;
#endif

TRACE
	pt = &prg->code;


	ALLOC_SLIST( dest->liste_bda );

	if (pt->ent->adr_tfu != 0)
	{
		FileGetBloc(pt, pt, pt->ent->adr_tfu);

		nb_bib = FileGetBin( pt );

		for (i = 0; i < nb_bib; i++)
		{
			/* ceation d'une nouvelle structure */

			/* copie du nom */
			FileGetString( pt, bda.nom );

			/* nb_fonction de la bda */
			bda.pgn = FileGetBin( pt );

			for (j=0; j < 16; j ++)
			{
				bda.non_util[j] = FileGetByte( pt ); /* by pass les 16 octets a 0 */
			}

			ALLOC_SNODE( node );

			if (pt->ent->exec == 3)
			{
				/* Si c'est un module */
				/* Ajoute en tete CAR pour la relocation
			 	la liste sera en ordre decroissante donc
				en phase avec les relocations. on pourra
				donc reloger en seule passe */
/*
				SlistAddHead( dest->liste_bda, node );
*/
				SlistAddTail( dest->liste_bda, node );
				
			}
			else
			{
				/* Pour le programme il faut conserver l'ordre
				pour que les nouvelles bda puissent s'inserer
				en queue de liste */

				SlistAddTail( dest->liste_bda, node );
			}

			pt_bda = ListNewBda( &bda.nom[0], bda.pgn, bda.non_util );
			SnodeSet( node, pt_bda );
		}

#ifdef ver21
		/* mettre la liste des eventuelles relocations */
		pt = &prg->dbg;
		if (pt->ent->adr_tdr == 0) return;

		/* On se place sur le bloc des relocations de BDA */

		FileGetBloc( pt,pt, pt->ent->adr_tdr );

		current_bda = 0xff;
		num_bda = FileGetByte( pt );
		while ( num_bda != 0xff )
		{

			bloc_bda = FileGetBin( pt );
			ofst_bda = FileGetBin( pt );

			ListMajPatch(1, prg->NUM_PRG, &(prg->code), bloc_bda, ofst_bda, MOINS_UN);

			num_bda = FileGetByte( pt );
		}

#endif

	}
}

/*------------------------- */
/* Init des listes EXTERNES */
/*------------------------- */

/*********************************
* FCT FichierInitVarExt
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Construction de la liste des variables externes
*
**********************************/

VOID FichierInitVarExt( fic, dest )
Fichier XPTR * fic;
Fichier XPTR * dest;
{ 
	Tabfic XPTR * pt;

	C_SNODE FAR *	node;
	Ancrage	XPTR *	pt_ancrage;
	LstPro	XPTR *	p;
	LstRef	XPTR *	r;
	WORD		nb;
	WORD		bloc;
	WORD		htv;
	WORD		hlv;

TRACE
	pt = &fic->dbg;

	/* Recuperation de table des var ext */

	ALLOC_SLIST( dest->liste_ancrage);

	if ( pt->ent->adr_tvarext == 0 ) return; 	


	TableGetFromFile( pt, &(dest->Tvarext), pt->ent->adr_tvarext, pt->ent->lgn_tvarext );

	/* Liste des points d'ancrages */
	FileGetBloc( pt, pt, pt->ent->tancrage);
	nb = FileGetBin( pt );
	while ( nb )
	{
		ALLOC_SNODE( node );
		SlistAddHead( dest->liste_ancrage, node );
		
		ALLOC_STRUCT( pt_ancrage, Ancrage );
		SnodeSet( node, pt_ancrage );


		pt_ancrage->par_qui	= FileGetBin( pt );
		FileGetString( pt, pt_ancrage->label );
		pt_ancrage->field	= FileGetByte( pt );
		pt_ancrage->off		= FileGetBin( pt );
		pt_ancrage->bloc	= FileGetBin( pt );
	
		pt_ancrage->adr_varext	= FileGetBin( pt );
		INIT_SLIST( pt_ancrage->liste_varext );

		nb--;
	}

	/* recherche des variables externes associees aux points d'ancrages */

	SlistRewind( dest->liste_ancrage );               
	node = SlistGetNext( dest->liste_ancrage );
	while ( node )
	{
		pt_ancrage = SnodeGet( node );

		if ( pt_ancrage->adr_varext )
		{
			FileGetBloc( pt, pt, pt_ancrage->adr_varext );
			nb = FileGetBin( pt );
			ALLOC_SLIST( pt_ancrage->liste_varext );
			while ( nb )
			{
				ALLOC_SNODE( node );
				SlistAddHead( pt_ancrage->liste_varext, node );

				ALLOC_STRUCT( p, LstPro );
				SnodeSet( node, p );

				INIT_SLIST( p->pt_args );
				INIT_SLIST( p->pt_ref );

				p->module = fic->NUM_PRG;

				/* numero dans la table des noms de module */

				p->par_qui = pt_ancrage->par_qui;
				p->any	= p->par_qui;	/* type d'extern */
	
				FileGetString(pt, p->nom);
				p->ext.adr_desc = FileGetBin( pt );

				ListCalculHashValue(p->nom, &htv, &hlv);
				p->hash_code = hlv;

				/* Par default non resolue */

				p->solved = MOINS_UN;

				p->num_module = MOINS_UN; /* par defaut je ne sais pas */


				bloc = FileGetBin( pt );
				ALLOC_SLIST( p->pt_ref );
				while ( bloc )
				{
					/* Liste des references dans le code */

					/* insertion en tete */
					ALLOC_SNODE( node );
					SlistAddHead( p->pt_ref, node );

					ALLOC_STRUCT( r, LstRef );
					SnodeSet( node, r );

					r->prog = fic->NUM_PRG;
					r->bloc = bloc;
					r->off = FileGetBin( pt );
			
					ListMajPatch(0,fic->NUM_PRG, &fic->code, r->bloc, r->off, 0xffff);
					bloc = FileGetBin( pt );
				}

				nb --;
			}
		}
		node = SlistGetNext( dest->liste_ancrage );
	}
}

/*********************************
* FCT FichierInitLabel
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Construction de la liste des labels
*
**********************************/
VOID FichierInitLabel( fic, dest )
Fichier XPTR * fic;
Fichier XPTR * dest;
{ 
	Tabfic XPTR * pt;
	C_SNODE FAR *	node;
	Label 	XPTR *	pt_label;
	WORD		nb;	

TRACE

	pt = &fic->dbg;

	ALLOC_SLIST( dest->liste_label );	

	if ( pt->ent->tlabel_var == 0 ) return; 	


	FileGetBloc(pt,pt,pt->ent->tlabel_var);
	nb = FileGetBin( pt );
	while ( nb )
	{
		ALLOC_SNODE( node );
		SlistAddHead( dest->liste_label, node );

		ALLOC_STRUCT( pt_label, Label );
		SnodeSet( node, pt_label);

		FileGetString( pt, pt_label->label );
		pt_label->field = FileGetByte( pt );
		pt_label->off	= FileGetBin( pt );
		pt_label->bloc  = FileGetBin( pt );
		nb--;
	}
}

/*********************************
* FCT FichierInitProExt
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Construction de la liste des porcedures externes
*
**********************************/
VOID FichierInitProExt( fic, dest )
Fichier XPTR * fic;
Fichier XPTR * dest;
{ 
	Tabfic XPTR * pt;
	WORD i,j;
	WORD bloc;
	LstPro *p;
	WORD htv, hlv;
	Args *q;
	LstRef *r;
	C_SNODE FAR * node;

TRACE
	/* les tables d'externs se  trouvent dans le dbg */

	pt = &fic->dbg;

	ALLOC_SLIST( dest->liste_pro_ext );

	if (pt->ent->adr_xpro == 0) return;


	FileGetBloc(pt,pt,pt->ent->adr_xpro);

	i = FileGetBin( pt );

	while (i--)
	{
		/* insertion en tete */

		ALLOC_SNODE( node );
		SlistAddHead( dest->liste_pro_ext, node );

		ALLOC_STRUCT( p , LstPro);

		SnodeSet( node, p );

		p->module = fic->NUM_PRG;

		INIT_SLIST( p->pt_args );
		INIT_SLIST( p->pt_ref );

		/* numero dans la table des noms de module */

		p->par_qui = FileGetBin( pt );
		p->any = p->par_qui;
		FileGetString(pt, p->nom);

		ListCalculHashValue(p->nom, &htv, &hlv);
		p->hash_code = hlv;

		/* Par default non resolue */

		p->solved = MOINS_UN;

		p->num_module = MOINS_UN; /* par defaut je ne sais pas */

		/* Traitement des arguments */

		j = FileGetBin( pt ); 

		p->ext.nb_args = j;

		j &= MASK_NB_ARGS; /* masque pour le nombre d'argument */
	
		ALLOC_SLIST( p->pt_args );
		while (j--)
		{
			/* insertion en tete */
			ALLOC_SNODE( node );
			SlistAddHead( p->pt_args, node );			
			
			q = ListNewArgs( (BYTE) FileGetByte( pt ) );
			SnodeSet( node, q );
		}

		/* Liste des references dans le code */

		bloc = FileGetBin( pt );
		ALLOC_SLIST( p->pt_ref );
		while (bloc)
		{
			/* insertion en tete */
			ALLOC_SNODE( node );
			SlistAddHead( p->pt_ref, node );

			ALLOC_STRUCT( r, LstRef );
			SnodeSet( node, r );

			r->prog = fic->NUM_PRG;
			r->bloc = bloc;
			r->off = FileGetBin( pt );
			
			ListMajPatch(0,fic->NUM_PRG, &fic->code, r->bloc, r->off, 0xffff);
			bloc = FileGetBin( pt );
		}
	}
}

/*********************************
* FCT FichierInitSegExt
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Construction de la liste des segments externs
*
**********************************/
VOID FichierInitSegExt(fic, dest)
Fichier XPTR * fic;
Fichier XPTR * dest;
{ 	Tabfic XPTR * pt;
	WORD i;
	WORD bloc;
	LstPro *p;
	LstRef *r;
	WORD htv, hlv;
	C_SNODE FAR * node;

TRACE

	pt = &fic->dbg;

	ALLOC_SLIST( dest->liste_seg_ext );

	if (pt->ent->tseg_ext == 0) return;
	
	FileGetBloc(pt,pt,pt->ent->tseg_ext);

	i = FileGetBin( pt );

	while (i--)
	{
		ALLOC_SNODE( node );
		SlistAddHead( dest->liste_seg_ext, node );

		ALLOC_STRUCT( p, LstPro);
		SnodeSet( node, p );
		
		p->module = fic->NUM_PRG;

		INIT_SLIST( p->pt_args );
		INIT_SLIST( p->pt_ref  );

		/* numero de module */
		p->par_qui = FileGetBin( pt );
		p->any = p->par_qui;
		/* nom du segment */
		FileGetString(pt, p->nom);

		ListCalculHashValue(p->nom, &htv, &hlv);
		p->hash_code = hlv;

		/* Par default non resolue */
		p->solved = MOINS_UN;

		p->ext.nb_args = FileGetBin( pt ); /* numero de segment */


		/* Creation des listes */

		ALLOC_SLIST( p->pt_args );

		/* Liste des references dans le code */
		
		bloc = FileGetBin( pt );
		p->pt_ref = SlistCreate();
		while (bloc)
		{
			/* insertion en tete */
			ALLOC_SNODE( node );
			SlistAddHead( p->pt_ref, node );

			ALLOC_STRUCT( r, LstRef );
			SnodeSet( node, r );
			r->prog = fic->NUM_PRG;
			r->bloc = bloc;
			r->off = FileGetBin( pt );

			ListMajPatch(0,fic->NUM_PRG, &fic->code, r->bloc, r->off, 0xffff);
			bloc = FileGetBin( pt );

		}
	}
}

/*********************************
* FCT FichierInitModExt
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Construction de la lisqte des modules externs
*
**********************************/

VOID FichierInitModExt( fic, dest )
Fichier XPTR * fic;
Fichier XPTR * dest;
{ 
	Tabfic XPTR * pt;
	WORD nb_modules;
	BYTE nom[LGREP];

TRACE
	pt = &fic->dbg;


	ALLOC_SLIST( dest->liste_mod_ext );

	if ( pt->ent->tnom_modules == 0 ) return;


	FileGetBloc(pt, pt, pt->ent->tnom_modules );
	nb_modules = FileGetBin( pt );
	while (nb_modules != MOINS_UN )
	{
		FileGetString( pt, nom );
		ListAddName( dest->liste_mod_ext, nom, nb_modules );
		nb_modules = FileGetBin( pt );
	}
}

/***************/
/* Relocations */
/***************/

VOID FichierGetRelocEtendue( fic, segment, offset )
Tabfic	XPTR *	fic;
WORD	XPTR *	segment;
WORD	XPTR *	offset;
{ 
	TRACE

	*((WORD XPTR *) offset) = (WORD) (fic->ent->lng_xtm);
	*((WORD XPTR *) segment) = (WORD) (fic->ent->reserve);
}

VOID FichierSetRelocEtendue( fic, relo )
Tabfic	XPTR *	fic;
ULONG		relo;
{
	TRACE

	/* Attention lng_xtm et reserve changent de sens */
	/* ils servent a memoriser les poids faibles/ poids fort */
	/* de la relocation de l'espace des FieldE */

	fic->ent->lng_xtm = (WORD) (relo & 0xffff);         
	fic->ent->reserve = (WORD) ((relo >> 16) & 0xffff);
}

ULONG FichierGetAdrEtendue( fic )
Tabfic	XPTR *	fic;
{ 
	ULONG	relo;

	/* Attention lng_xtm et reserve changent de sens */
	/* ils servent a memoriser les poids faibles/ poids fort */
	/* de la relocation de l'espace des FieldE */

	relo = (ULONG) ( fic->ent->reserve );
	relo = (ULONG) ( relo << 16 ) + fic->ent->lng_xtm;

	return( relo );
}

/*********************************
* FCT FichierRelocBda
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Relocation des Bda
*	la liste bda de module est en ordre decroissante 
*	la liste bda de resultat est en ordre croissant 
*
**********************************/
#ifdef OLD
VOID FichierRelocBda(module, res)
Fichier XPTR * module;
Fichier XPTR * res;
{
	Bibli XPTR * pt_bda;
	Bibli XPTR * res_bda;
	
	C_SNODE FAR * node;
	C_SNODE FAR * pt_node;
	C_SNODE FAR * res_node;
	Tabfic XPTR * pt;
		
	WORD bloc,ofst;
	BYTE res_numero;
	BYTE mod_numero;
	WORD bloc_bda;
	WORD ofst_bda;
	BYTE num_bda;


TRACE

	/* On reloge les bda */
	pt = &(module->dbg);
	if (pt->ent->adr_tdr == 0) return; 
	
	/* On se place sur le bloc des relocations de BDA */

	FileGetBloc( pt,pt, pt->ent->adr_tdr );
	num_bda  = FileGetByte( pt ); /* Amorce */
	
	SlistRewind( module->liste_bda );
	pt_node = SlistGetNext( module->liste_bda );

	mod_numero = SlistCount( module->liste_bda ) - 1;

	while ( pt_node )
	{
		pt_bda = SnodeGet( pt_node);
		
		/* Parcours la liste des bda publiques */

		res_numero = 0;

		/* On se positionne sur la liste des bda publiques */

		SlistRewind( res->liste_bda );
		res_node = SlistGetNext( res->liste_bda );
		while ( res_node )
		{
			res_bda = SnodeGet( res_node );

			/* on compare les nom de bda */
			/* Identique ? */
			if ( ! ListMatchBib(pt_bda, res_bda) ) {
				/* OUI : On reloge avec le numero d'ordre de bda */
				break;
			}
			else {	
				/* NON : Suivant */
				res_node = SlistGetNext( res->liste_bda );
				res_numero ++;
			}
		}

		if ( ! res_node )
		{
			/* insertion en queue */
			ALLOC_SNODE( node );
			SlistAddTail( res->liste_bda, node );

			/* Rendre la bda publique */
			res_bda = ListNewBda( pt_bda->nom, pt_bda->pgn, pt_bda->non_util );

			SnodeSet( node, res_bda );
		}

		/* On reloge	*/
		
		do
		{
			bloc_bda = FileGetBin( pt );
			ofst_bda = FileGetBin( pt );

			ListMajPatch(1, module->NUM_PRG, &(module->code), bloc_bda, ofst_bda, res_numero);

			num_bda  = FileGetByte( pt );

		}
		while( num_bda == mod_numero );

		pt_node = SlistGetNext( module->liste_bda );

		mod_numero --;
	}

}

#else

VOID FichierRelocBda(module, res)
Fichier XPTR * module;
Fichier XPTR * res;
{
	Bibli XPTR * pt_bda;
	Bibli XPTR * res_bda;
	
	C_SNODE FAR * node;
	C_SNODE FAR * pt_node;
	C_SNODE FAR * res_node;
	Tabfic XPTR * pt;
	BYTE res_numero;
	WORD bloc_bda;
	WORD ofst_bda;
	BYTE num_bda;
	BYTE current_bda;
	BYTE i;

TRACE

	/* On reloge les bda */
	pt = &(module->dbg);
	if (pt->ent->adr_tdr == 0) return; 
	
 /* On se place sur le bloc des relocations de BDA */

	FileGetBloc( pt,pt, pt->ent->adr_tdr );

	current_bda = 0xff;
	num_bda = FileGetByte( pt );
	while ( num_bda != 0xff )
	{
		if ( num_bda != current_bda )
		{
			/* recherche de la bda du module */
			SlistRewind( module->liste_bda );
			pt_node = SlistGetNext( module->liste_bda );
			for (i=0; i < num_bda; i ++)
			{
				pt_node = SlistGetNext( module->liste_bda );
			}
			pt_bda = SnodeGet( pt_node );
			/* est elle publique */
			/* Parcours la liste des bda publiques */

			res_numero = 0; /* valeur a reloger */

			/* On se positionne sur la liste des bda publiques */
			SlistRewind( res->liste_bda );
			res_node = SlistGetNext( res->liste_bda );
			while ( res_node )
			{
				res_bda = SnodeGet( res_node );
	
				/* on compare les nom de bda */
				/* Identique ? */
				if ( ! ListMatchBib(pt_bda, res_bda) )
				{
					/* OUI : On reloge avec le numero d'ordre de bda */
					break;
				}
				else
				{	
					/* NON : Suivant */
					res_node = SlistGetNext( res->liste_bda );
					res_numero ++;
				}
			}

			if ( ! res_node )
			{
				/* insertion en queue */
				ALLOC_SNODE( node );
				SlistAddTail( res->liste_bda, node );

				/* Rendre la bda publique */
				res_bda = ListNewBda( pt_bda->nom, pt_bda->pgn, pt_bda->non_util );

				SnodeSet( node, res_bda );
			}

			current_bda = num_bda;
		}

		bloc_bda = FileGetBin( pt );
		ofst_bda = FileGetBin( pt );

		ListMajPatch(1, module->NUM_PRG, &(module->code), bloc_bda, ofst_bda, res_numero);

		num_bda  = FileGetByte( pt );
	}
}

#endif


/*********************************
* FCT FichierRelocCst
*
* Entree : 
* 	le fichier contenant la table a reloger
*	le fichier qui recoit la table
*	gestion des alias (TRUE / FALSE)
*
* Sortie :
*	rien
*
* Remarque :
*	Relocation d'une table de constante
*
**********************************/
VOID FichierRelocCst( mod, res, alias )
Fichier XPTR *	mod;
Fichier XPTR *	res;
BOOL		alias;
{ 
	WORD		bloc;
	WORD		off;
	WORD		desc;
	WORD		val_reloc;
	WORD		i;
	WORD		base_reloc;

	InfoCst		TmpCst;
	InfoCst		ResCst;
	ModPro XPTR *	nomcst;
	ModPro XPTR *	pubcst;
	Tabfic XPTR *	pt;

	WORD tmp;

	C_SNODE FAR * node;

TRACE
	pt = &(mod->dbg);

	if ( pt->ent->adr_xcst == 0 ) return;

	FileGetBloc(pt, pt, pt->ent->adr_xcst);

	base_reloc = TableGetReloc( &(res->Tcst) );
	
	tmp = 0;
	desc = FileGetBin( pt );
	while( desc != MOINS_UN )
	{

		TableGetCst( &(mod->Tcst), desc, &TmpCst );

		val_reloc	= TableGetReloc( &(res->Tcst) );
		TmpCst.adrdesc  = val_reloc;

		if (alias == TRUE)
		{

			nomcst = ListGetNomVarFromDesc( mod->liste_cst_pub, desc );

			if (nomcst)
			{
				pubcst = ListIsCstPub( res->liste_cst_pub, nomcst );
				if (pubcst)
				{
					TableGetCst(&(res->Tcst), pubcst->used, &ResCst );
					if (ListMatchCst( &ResCst, &TmpCst ) )
					{
						/* deja present */
						nomcst->used = pubcst->used;
						TmpCst.adrdesc = pubcst->used;
					}
					else
					{
						/* meme nom valeur <> */
						/* est ce que la valeur de la constante existe */
						TableGetCstAlias( &(res->Tcst), &TmpCst ); 

						nomcst->used = TmpCst.adrdesc;
						ListDupliqueVar( res->liste_cst_pub, nomcst );
					}
				}	   
				else
				{
					/* Ce nom de constante n'existe pas */ 
					/* est ce que la valeur de la constante existe */

					TableGetCstAlias( &(res->Tcst), &TmpCst ); 
					nomcst->used = TmpCst.adrdesc;
					ListDupliqueVar( res->liste_cst_pub, nomcst );
				}
			}
			else
			{
				/* Ce nom de constante n'existe pas */ 
				/* est ce que la valeur de la constante existe */
				TableGetCstAlias( &(res->Tcst), &TmpCst ); 
			}
			val_reloc = TmpCst.adrdesc;
		}
		else
		{
			/* relocation du nom de  la constnte */
			nomcst = ListGetNomVarFromDesc( mod->liste_cst_pub, desc );
			if (nomcst)
			{
				nomcst->used = TmpCst.adrdesc;
				ListDupliqueVar( res->liste_cst_pub, nomcst );
			}
		}

		if ( val_reloc == TmpCst.adrdesc)
		{
			/* Cst inconnu */

			if ( (ULONG) ((ULONG) (TmpCst.adrdesc )+ (ULONG) (TmpCst.lgdesc)) >= 65535L )
				THROW( ErreurMoteur06 );

			TablePutCst( &(res->Tcst), &TmpCst );
		}

		/* relocation du nom de constantes */
		
		bloc = FileGetBin( pt );
		while ( bloc != 0 )
		{
			off  = FileGetBin( pt );
			ListMajPatch(0,mod->NUM_PRG, &(mod->code),bloc, off, val_reloc);
			bloc = FileGetBin( pt );
		}

		desc = FileGetBin( pt );
	}
	
	pt->ent->adr_xcst = 0; /* reloc des constantes du module faites */

	/* Liberation de la table des constantes du module */
	TableClose( &(mod->Tcst) );

	/* Reloge la table de correspondance des constantantes */

	/* relocation des constantes binaires */
	for (i=0; i<HTV; i++)
	{
		SlistRewind( mod->liste_cstbin_pub[i] );
		node = SlistGetNext( mod->liste_cstbin_pub[i] );
		while (node)
		{
			nomcst = SnodeGet( node );
			ListDupliqueVar( res->liste_cstbin_pub, nomcst );
			node = SlistGetNext( mod->liste_cstbin_pub[i] );
		}
	}
}

/*********************************
* FCT FichierRelocVarExt
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Relocation des ancrages externs
*
**********************************/
VOID FichierRelocVarExt( mod, res )
Fichier XPTR * mod;
Fichier XPTR * res;
{ 
	C_SNODE FAR *	node;
	Ancrage XPTR *	pt_ancrage;
	Ancrage XPTR *	pub_ancrage;
	LstPro XPTR *	varext;
	LstPro XPTR *	varextpub;
	InfoVar			type_varext;
	InfoVar			type_varextpub;
	InfoVar			vp;
	BYTE			nom[LGIDENT];

TRACE
	SlistRewind(mod->liste_ancrage);
	node = SlistGetNext(mod->liste_ancrage);

	while(node)
	{
		pt_ancrage = SnodeGet(node);
		pub_ancrage = ListIsAncragePub(res->liste_ancrage, pt_ancrage, res, mod);
		if (pub_ancrage)
		{
			SlistRewind(pt_ancrage->liste_varext);
			node = SlistGetNext(pt_ancrage->liste_varext);

			while(node)
			{
				varext = SnodeGet(node);

				varextpub = ListIsVarExtPub(pub_ancrage->liste_varext, varext);

				if ( varextpub )
				{
					/* meme nom est ce le meme type */
					TableGetVar(&(mod->Tvarext), varext->ext.adr_desc, &type_varext);
					TableGetVar(&(res->Tvarext), varextpub->ext.adr_desc, &type_varextpub);

					if ( ListMatchVar(&type_varextpub, &type_varext) || pub_ancrage->field == MALL)
					{
						/* meme nom meme type */
						if (varextpub->solved == MOINS_UN)
						{
							ListConcat(varextpub->pt_ref, varext->pt_ref);
						}
						else
						{
							varext->solved = varextpub->solved;
							TableGetVar(&(res->Tvar), varextpub->solved, &vp);
							ListRelocVarPatch(mod, varext->pt_ref, varextpub->solved, vp.adrvar);
						}
					}
					else
					{
						/* meme nom de type different */
						ListDupliqueVarExt(&(mod->Tvarext), &(res->Tvarext), pub_ancrage->liste_varext, varext, res, mod );

						if ( varext->par_qui != MOINS_UN)
						{
							varextpub = SnodeGet(SlistGetHead(pub_ancrage->liste_varext));
							ListGetNameFromNum(mod->liste_mod_ext, varext->par_qui, nom);
							varextpub->par_qui = ListGetNameNum(res->liste_mod_ext, nom);
						}
					} 
				}
				else
				{
					ListDupliqueVarExt(&(mod->Tvarext), &(res->Tvarext), pub_ancrage->liste_varext, varext, res, mod);
				}
				node = SlistGetNext(pt_ancrage->liste_varext);
			}
		}
		else
		{
			ListDupliqueAncrage(&(mod->Tvarext), &(res->Tvarext), res->liste_ancrage, pt_ancrage, res, mod);
		}

		node = SlistGetNext(mod->liste_ancrage);
	}
}

/*********************************
* FCT FichierRelocVarMFIN
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Relocation des variables field=m
*
**********************************/
VOID FichierRelocVarMFIN ( mod, res )
Fichier XPTR *	mod;
Fichier XPTR *	res;
{ 
	
	WORD				bloc;
	WORD				off;
	WORD				desc;
	WORD				reloc_taille;
	WORD				reloc_base;
	InfoVar			var;
	InfoVar			resvar;
	ModPro XPTR *	nomvar;
	ModPro XPTR *	nomptr;
	Tabfic XPTR *	pt;
	WORD				nb_var;
	BYTE				nomtmp[LGIDENT];
	WORD				i,j;

#ifdef DBGTRC
fprintf(fdbgtrc,"\n FichierRelocVarMFIN() - Debut\n");
#endif

TRACE
	pt = &(mod->dbg);

	if (pt->FieldM == TRUE)
		return; /* Deja effectue */

	/* On reloge la table */

	reloc_taille = TableGetVarTaille( &(res->Tvar) ) ;
	reloc_base   = TableGetReloc(&(res->Tvar)) - 6 ;
	nb_var = TableGetVarNb( &(mod->Tvar) );
	desc = 6;

	while(nb_var)
	{
		TableGetVar(&(mod->Tvar), desc, &var);

		/* Mise en phase avec les trous du traducteur */
		desc = var.adrdesc;

		if (var.etendue == FALSE && var.virtuelle == FALSE)
		{
			nomvar = ListGetNomVarFromDesc( mod->liste_var_pub, desc );
			
			if (nomvar == GN(ModPro))
			{
				/* Pas de nom de variable ==> en fin */

				var.adrdesc  = TableGetReloc( &(res->Tvar) );

				/* En nombre de variables */
				if ((LONG) ((ULONG) TableGetVarNb(&(res->Tvar)) + 1 ) >= 65535L)
					THROW( ErreurMoteur09 );

				/* En taille memoire */

/* #BG 19/11/01
	var.longueur ne tient pas compte des dimensions: utiliser var.lgfielde
				if ((LONG) ((ULONG) reloc_taille + (ULONG)var.adrvar + (ULONG)var.longueur ) >= 65535L)
*/
				if ((LONG) ((ULONG) reloc_taille + (ULONG)var.adrvar + (ULONG)var.lgfielde ) >= 65535L)
					THROW( ErreurMoteur10 );
#ifdef DBGTRC2
fprintf(fdbgtrc,"\nVarMFIN Pas de nom - %ld \n", ((ULONG) reloc_taille + (ULONG)var.adrvar + (ULONG)var.lgfielde) );
#endif

				/* En taille table */
				/* #AT: 14/09/00 (begin)*/
				CheckReloc(&mod->Tvar, MAX_VAR_DESC_OFFSET, ErreurMoteur07);
				/* #AT: 14/09/00 (end)*/

				/*	Relocation de la variable */
				var.adrvar += reloc_taille;

				TablePutVar(&(res->Tvar), &var);
				TablePutVarNb(&(res->Tvar), (WORD) (TableGetVarNb( &(res->Tvar) ) + 1));
			}
			else
			{
				if (nomvar->used == MOINS_UN)
				{
					var.adrdesc = TableGetReloc(&(res->Tvar));

					/* En nombre de variables */

					if ((LONG) ((ULONG) TableGetVarNb(&(res->Tvar)) + 1 ) >= 65535L)
						THROW( ErreurMoteur09 );

					/* En taille table */
					/* #AT: 14/09/00 (begin)*/
					CheckReloc(&mod->Tvar, MAX_VAR_DESC_OFFSET, ErreurMoteur07);
					/* #AT: 14/09/00 (end)*/

					if (var.tptr == 0x03 || var.tptr == 0x02)
					{
						nomptr = ListGetNomVarFromDesc( mod->liste_var_pub, var.adredefptr);
						var.adredefptr = nomptr->used;
					}
					else
					{
						/* En taille memoire */

/* #BG 19/11/01
	var.longueur ne tient pas compte des dimensions: utiliser var.lgfielde
*/
						if ((LONG) ((ULONG)reloc_taille + (ULONG)var.adrvar + (ULONG)var.lgfielde) >= 65535L)
							THROW(ErreurMoteur10);
#ifdef DBGTRC2
fprintf(fdbgtrc,"\nVarMFIN Avec nom - %ld \n", ((ULONG) reloc_taille + (ULONG)var.adrvar + (ULONG)var.lgfielde) );
#endif

						/*	Relocation de la variable	*/
						var.adrvar += reloc_taille;
					}

					nomvar->used = var.adrdesc;
					TablePutVar(&(res->Tvar), &var);
					TablePutVarNb(&(res->Tvar), (WORD) (TableGetVarNb( &(res->Tvar) ) + 1));

					if (mod->dbg.ent->var_static == 1)
					{
				 		/* Insertion de _ avant le nom pour ne pas 
				 		perturber la recherche les relocations des externs */
				 		nomtmp[0] = (BYTE) ('A'+ nomvar->num_module);
						nomtmp[1] = EOSTR;
				 		Xstrcat(nomtmp,"_");
						i = 0;
						for (j=Xstrlen(nomtmp); j < LGIDENT; j++)
						{
							if (nomvar->nom[i] == EOSTR)
								break;
							
							nomtmp[j] = nomvar->nom[i++];
						}
						nomtmp[j] = EOSTR;
			 			
				 		XstrCpySize(nomvar->nom, nomtmp, sizeof(nomvar->nom));
					}

					ListDupliqueVar(res->liste_var_pub, nomvar);
				}
			}
		}

		desc += var.lgdesc;
		nb_var--;
	}
	
	TablePutVarTaille(&(res->Tvar), (WORD) (TableGetVarTaille(&(mod->Tvar)) + reloc_taille));

	/* Module traite */
	pt->FieldM = TRUE;

	/* Prise en compte les relocations */

	if (pt->ent->adr_xvar == 0)
		return;

	FileGetBloc(pt, pt, pt->ent->adr_xvar);

	desc = FileGetBin(pt);
	while(desc != MOINS_UN)
	{
		TableGetVar(&(mod->Tvar), desc, &var);
		desc = var.adrdesc;

		if (var.etendue == 0 && var.virtuelle == 0)
		{
			nomvar = ListGetNomVarFromDesc(mod->liste_var_pub, desc);
			bloc = FileGetBin(pt);

			while(bloc != 0)
			{
				off = FileGetBin(pt);
			
				if (nomvar != GN(ModPro))
				{
					if (off & 0xff00)
					{
						TableGetVar(&(res->Tvar), nomvar->used, &resvar);
						ListMajPatch(0, mod->NUM_PRG, &(mod->code), bloc, (WORD) (off & 0x00ff), resvar.adrvar);
					}
					else
						ListMajPatch(0, mod->NUM_PRG, &(mod->code), bloc, off, nomvar->used);
				}
				else
				{
					if (off & 0xff00)
						ListMajPatch(0, mod->NUM_PRG, &(mod->code), bloc, (WORD) (off & 0x00ff), resvar.adrvar);
					else
						ListMajPatch(0, mod->NUM_PRG, &(mod->code), bloc, off, (WORD) (var.adrdesc + reloc_base));
				}

				bloc = FileGetBin(pt);
			}
		}
		else
		{
			/* On avance sur le suivant */
			bloc = FileGetBin(pt);
			while (bloc != 0)
			{
				off = FileGetBin(pt);
				bloc = FileGetBin(pt);
			}
		}

 		desc = FileGetBin(pt);
	}

#ifdef DBGTRC
fprintf(fdbgtrc,"\n FichierRelocVarMFIN() - Fin\n");
#endif
}


/*********************************
* FCT FichierRelocVarMRECOUVRE
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Relocation des variables field=m en recouvrement 
*
**********************************/
VOID FichierRelocVarMRECOUVRE( mod, res, ancrage )
Fichier XPTR *	mod;
Fichier XPTR *	res;
Ancrage XPTR *	ancrage;
{ 
	WORD				bloc;
	WORD				off;
	WORD				desc;
	WORD				reloc_taille;
	InfoVar			var;
	InfoVar			resvar;
	ModPro XPTR *	nomvar;
	ModPro XPTR *	nomptr;
	Tabfic XPTR *	pt;
	WORD				nb_var;

#ifdef DBGTRC
fprintf(fdbgtrc,"\n FichierRelocVarMRECOUVRE() - Debut\n");
#endif

TRACE
	pt = &(mod->dbg);

	if (pt->FieldM == TRUE)
		return;

	/* On reloge la table en redefinition */

	reloc_taille = ancrage->off;
	nb_var = TableGetVarNb(&(mod->Tvar));
	desc = 6;

	while (nb_var)
	{
		TableGetVar(&(mod->Tvar), desc, &var);
		desc = var.adrdesc;

		if (var.etendue == FALSE && var.virtuelle == FALSE)
		{
			nomvar = ListGetNomVarFromDesc(mod->liste_var_pub, desc);
			if (nomvar->used == MOINS_UN)
			{
				var.adrdesc = TableGetReloc(&(res->Tvar));

				/* En nombre de variables */

				if ((LONG) ((ULONG) TableGetVarNb(&(res->Tvar)) + 1 ) >= 65535L) 
					THROW(ErreurMoteur09);

				/* En taille table */
				/* #AT: 14/09/00 (begin)*/
				CheckReloc(&mod->Tvar, MAX_VAR_DESC_OFFSET, ErreurMoteur07);
				/* #AT: 14/09/00 (end)*/

				if (var.tptr == 0x03 || var.tptr == 0x02)
				{
					nomptr = ListGetNomVarFromDesc(mod->liste_var_pub, var.adredefptr);
					var.adredefptr = nomptr->used;
				}
				else
				{
					/* En taille memoire */

/* #BG 19/11/01
	var.longueur ne tient pas compte des dimensions: utiliser var.lgfielde
*/
					if ((LONG) ((ULONG)reloc_taille + (ULONG)var.adrvar + (ULONG)var.lgfielde) >= 65535L)
						THROW(ErreurMoteur10);
#ifdef DBGTRC2
fprintf(fdbgtrc,"\nVarMRECOUVRE - %ld \n", ((ULONG)reloc_taille + (ULONG)var.adrvar + (ULONG)var.lgfielde) );
#endif

					/*	Relocation de la variable */
					var.adrvar += reloc_taille;
				}

				nomvar->used = var.adrdesc;

				TablePutVar(&(res->Tvar), &var);
				TablePutVarNb(&(res->Tvar), (WORD)(TableGetVarNb(&(res->Tvar)) + 1));
				ListDupliqueVar(res->liste_var_pub, nomvar);
			}
		}

		desc += var.lgdesc;
		nb_var--;
	}


	/* Modif du 2/12/1993 (bd)
		On modifie la taille si la relocation depasse la taille de l'espace
		memoire du fichier resultat 
	*/
	
	if ((reloc_taille + TableGetVarTaille(&(mod->Tvar))) > TableGetVarTaille(&(res->Tvar)) )
	{
		TablePutVarTaille( &(res->Tvar), (WORD)(TableGetVarTaille(&(mod->Tvar)) + reloc_taille) );
	}

	pt->FieldM = TRUE;

	/* Prise en compte les relocations */

	if ( pt->ent->adr_xvar == 0 )
		return;

	FileGetBloc(pt, pt, pt->ent->adr_xvar);

	desc = FileGetBin(pt);

	while(desc != MOINS_UN)
	{
		TableGetVar(&(mod->Tvar), desc, &var);
		desc = var.adrdesc;

		if (var.etendue == 0 && var.virtuelle == 0)
		{
			nomvar = ListGetNomVarFromDesc(mod->liste_var_pub, desc);

			bloc = FileGetBin(pt);
			while (bloc != 0)
			{
				off = FileGetBin(pt);
			
				if (off & 0xff00)
				{
					TableGetVar(&(res->Tvar), nomvar->used, &resvar);
					ListMajPatch(0, mod->NUM_PRG, &(mod->code), bloc, (WORD)(off & 0x00ff), resvar.adrvar);
				}
				else
					ListMajPatch(0, mod->NUM_PRG, &(mod->code), bloc, off, nomvar->used);

				bloc = FileGetBin(pt);
			}
		}
		else
		{
			/* On avance sur le suivant */
			bloc = FileGetBin(pt);
			while (bloc != 0)
			{
				off = FileGetBin(pt);
				bloc = FileGetBin(pt);
			}
		}

 		desc = FileGetBin(pt);
	}

#ifdef DBGTRC
fprintf(fdbgtrc,"\n FichierRelocVarMRECOUVRE() - Fin\n");
#endif

}

/*********************************
* FCT FichierRelocVarMINSERT
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Relocation des variables field=m en insertion
*                                                                   
*                         x                                              
*                  a      y                                              
*  relo_adr  ->   ------------  <- relo_label (adr memoire a mapper sur relo_adr                                         
*                  b      z -+                                           
*                  c      w  !-> relo_insert = taille - relo_label                      
*                         u -+  <- taille de l'espace memoire
*                                                                                                                                                                   
**********************************/
VOID FichierRelocVarMINSERT ( mod, res, ancrage, label )
Fichier XPTR *	mod;
Fichier XPTR *	res;
Ancrage XPTR *	ancrage;
Label	XPTR *	label;
{ 
	WORD				bloc;
	WORD				off;
	WORD				desc;
	WORD				reloc_taille;
	WORD				relo_adr;
	WORD				relo_label;
	WORD				relo_insert;
	InfoVar			var;
	InfoVar			resvar;
	ModPro XPTR *	nomvar;
	ModPro XPTR *	nomptr;
	Tabfic XPTR *	pt;
	WORD				nb_var;

#ifdef DBGTRC
fprintf(fdbgtrc,"\n FichierRelocVarMINSERT() - Debut\n");
#endif

TRACE

	pt = &(mod->dbg);

	if ( pt->FieldM == TRUE )
		return;

	relo_adr = ancrage->off;
	relo_label = label->off;
	relo_insert = TableGetVarTaille(&(mod->Tvar) ) - relo_label;

	/* On insere avant de reloger */
	nb_var = TableGetVarNb( &(res->Tvar) );
	desc = 6;

	while (nb_var)
	{
		TableGetVar(&(res->Tvar), desc, &var);
		desc = var.adrdesc;
		
		if (var.etendue == FALSE && var.virtuelle == FALSE)
		{
			if (var.adrvar >= relo_adr)
			{
				if (relo_label > relo_adr)
					var.adrvar = (var.adrvar - relo_adr) + (relo_label + relo_insert);
				else
					var.adrvar += relo_insert;
			}
			else
			{
				if (relo_label > relo_adr)
				{
					/* Le recouvrement en arriere du module est plus grand que le debut de l'espace memoire */
					var.adrvar = relo_label - (relo_adr - var.adrvar);
				}
			}

			TablePutVar( &(res->Tvar), &var );
		}

		desc += var.lgdesc;
		nb_var--;
	}

	/* On reloge la table en insertion */

	reloc_taille = ancrage->off;
	nb_var = TableGetVarNb(&(mod->Tvar));
	desc = 6;

	while(nb_var)
	{
		TableGetVar(&(mod->Tvar), desc, &var);
		desc = var.adrdesc;

		if (var.etendue == FALSE && var.virtuelle == FALSE)
		{
			nomvar = ListGetNomVarFromDesc(mod->liste_var_pub, desc);

			if (nomvar->used == MOINS_UN)
			{
				var.adrdesc = TableGetReloc( &(res->Tvar));

				/* En nombre de variables */
				if ((LONG) ((ULONG) TableGetVarNb(&(res->Tvar)) + 1 )  >= 65535L)
					THROW( ErreurMoteur09 );

				/* En taille table */
				/* #AT: 14/09/00 (begin)*/
				CheckReloc(&mod->Tvar, MAX_VAR_DESC_OFFSET, ErreurMoteur07);
				/* #AT: 14/09/00 (end)*/

				if (var.tptr == 0x03 || var.tptr == 0x02)
				{
					nomptr = ListGetNomVarFromDesc( mod->liste_var_pub, var.adredefptr);
					var.adredefptr = nomptr->used;
				}
				else
				{
					/* En taille memoire */
					if ((LONG) ((ULONG)reloc_taille + (ULONG)var.adrvar + (ULONG)var.lgfielde) >= 65535L)
						THROW( ErreurMoteur10 );
#ifdef DBGTRC2
fprintf(fdbgtrc,"\nVarMINSERT - %ld \n", ((ULONG)reloc_taille + (ULONG)var.adrvar + (ULONG)var.lgfielde) );
#endif

					/*	Relocation de la variable	*/
					if (relo_label < relo_adr)
					{
						if (var.adrvar < relo_label)
							var.adrvar = relo_adr - (relo_label - var.adrvar);
						else
							var.adrvar = relo_adr + (var.adrvar - relo_label);
					}
				}

				nomvar->used = var.adrdesc;
				TablePutVar( &(res->Tvar), &var );
				TablePutVarNb( &(res->Tvar), (WORD) (TableGetVarNb( &(res->Tvar) ) + 1) );
				ListDupliqueVar( res->liste_var_pub, nomvar );
			}
		}

		desc += var.lgdesc;
		nb_var--;
	}

	TablePutVarTaille(&(res->Tvar), (WORD)(TableGetVarTaille(&(res->Tvar)) + relo_adr + relo_label));
	pt->FieldM = TRUE;

	/* Prise en compte les relocations */

	if (pt->ent->adr_xvar == 0)
		return;

	FileGetBloc(pt, pt, pt->ent->adr_xvar);

	desc = FileGetBin(pt);

	while(desc != MOINS_UN)
	{
		TableGetVar(&(mod->Tvar), desc, &var);
		desc = var.adrdesc;

		if (var.etendue == 0 && var.virtuelle == 0)
		{
			nomvar = ListGetNomVarFromDesc(mod->liste_var_pub, desc);

			bloc = FileGetBin(pt);
			while (bloc != 0)
			{
				off = FileGetBin(pt);
				if (off & 0xff00)
				{
					TableGetVar(&(res->Tvar), nomvar->used, &resvar);
					ListMajPatch(0, mod->NUM_PRG, &(mod->code), bloc, (WORD)(off & 0x00ff), resvar.adrvar);
				}
				else
					ListMajPatch(0, mod->NUM_PRG, &(mod->code), bloc, off, nomvar->used);

				bloc = FileGetBin(pt);
			}
		}
		else
		{
			/* On avance sur le suivant */
			bloc = FileGetBin(pt);
			while(bloc != 0)
			{
				off = FileGetBin(pt);
				bloc = FileGetBin(pt);
			}
		}

 		desc = FileGetBin(pt);
	}

#ifdef DBGTRC
fprintf(fdbgtrc,"\n FichierRelocVarMINSERT() - Fin\n");
#endif
}

/*********************************
* FCT FichierRelocVarEFIN
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Relocation des variables field=e
*
**********************************/
VOID FichierRelocVarEFIN ( mod, res )
Fichier XPTR *	mod;
Fichier XPTR *	res;
{ 
	WORD				bloc;
	WORD				off;
	WORD				desc;
	ULONG				reloc_taille, base_reloc_taille, ul1, ul2;
	ULONG				max_taille;	/* #BG 02/10/02 */
	WORD				reloc_base;
	InfoVar			var;
	ModPro XPTR *	nomvar;
	ModPro XPTR *	nomptr;
	Tabfic XPTR *	pt;
	WORD				nb_var;

#ifdef DBGTRC
fprintf(fdbgtrc,"\n FichierRelocVarEFIN() - Debut\n");
#endif

TRACE
	pt = &(mod->dbg);

	if (pt->FieldE == TRUE)
		return;

	/* On reloge la table */
	max_taille = 0;	/* #BG 02/10/02 */
	reloc_taille = FichierGetAdrEtendue(&(res->code));
	base_reloc_taille = reloc_taille;
	reloc_base = TableGetReloc(&(res->Tvar) ) - 6;
	nb_var = TableGetVarNb(&(mod->Tvar));
	desc = 6;

	while(nb_var)
	{
		TableGetVar(&(mod->Tvar), desc, &var);
		desc = var.adrdesc;

		if (var.etendue)
		{
			nomvar = ListGetNomVarFromDesc(mod->liste_var_pub, desc);

			if (nomvar == GN(ModPro))
			{
				/* Pas de nom de variable ==> en fin */
				var.adrdesc = TableGetReloc(&(res->Tvar));
				
				/* En nombre de variables */
				if ((LONG) ((ULONG) TableGetVarNb(&(res->Tvar)) + 1 ) >= 65535L)
					THROW(ErreurMoteur09);

				/* En taille memoire */
				/* #BG 20/08/01 Pas de test de taille mémoire avec les variables en Field=E! */

				/* En taille table */
				/* #AT: 14/09/00 (begin) */
				CheckReloc(&mod->Tvar, MAX_VAR_DESC_OFFSET, ErreurMoteur07);
				/* #AT: 14/09/00 (end)*/

				/* Relocation de la variable */

				FichierGetRelocEtendue(&(res->code), &var.adrfield, &var.adrvar);

				TablePutVar(&(res->Tvar), &var);
				TablePutVarNb(&(res->Tvar), (WORD)(TableGetVarNb(&(res->Tvar)) + 1));

				reloc_taille += (ULONG)(var.lgfielde);

				if (reloc_taille > max_taille)	/* #BG 02/10/02 */
				{
					FichierSetRelocEtendue(&(res->code), reloc_taille);
					max_taille = reloc_taille;		/* #BG 02/10/02 */
				}

			}
			else
			{
				if (nomvar->used == MOINS_UN)
				{
					var.adrdesc  = TableGetReloc(&(res->Tvar));

					/* En nombre de variables */
					if ((LONG) ((ULONG) TableGetVarNb(&(res->Tvar)) + 1 )  >= 65535L)
						THROW(ErreurMoteur09);

					/* En taille table */
					/* #AT: 14/09/00 (begin) */
					CheckReloc(&mod->Tvar, MAX_VAR_DESC_OFFSET, ErreurMoteur07);
					/* #AT: 14/09/00 (end)*/

					if (var.tptr == 0x03 || var.tptr == 0x02 )
					{
						nomptr = ListGetNomVarFromDesc(mod->liste_var_pub, var.adredefptr);
						var.adredefptr = nomptr->used;
					}
					else
					{
						/* En taille memoire */
						/* #BG 20/08/01 Pas de test de taille mémoire avec les variables en Field=E! */

						/*	Relocation de la variable */

						// Adresse absolue (32bits) de fin de relocation pour ce module.
						ul1 = FichierGetAdrEtendue(&(res->code)) - base_reloc_taille;
						// Adresse absolue (32bits) de la variable dans ce module.
						ul2 = (ULONG)((var.adrfield << 16) + var.adrvar);

						if (ul1 <= ul2)
						{
							// Ce n'est pas une redéfinition.
							// Relocation à la fin.
							FichierGetRelocEtendue(&(res->code), &var.adrfield, &var.adrvar);
							reloc_taille += (ULONG)(var.lgfielde);
							FichierSetRelocEtendue(&(res->code), reloc_taille);
						}
						else
						{
							// C'est une redéfinition.
							// Pas de relocation.
							// Allocation nécessaire si redéfinition dépasse la taille allouée courante.

							// Adresse absolue (32bits) de fin de la variable dans ce module.
							ul2 = (ULONG)((var.adrfield << 16) + var.adrvar) + var.lgfielde;

							if (ul2 > ul1)
							{
								reloc_taille += (ul2 - ul1);
								FichierSetRelocEtendue(&(res->code), reloc_taille);
							}
						}
					}

					nomvar->used = var.adrdesc;
					TablePutVar(&(res->Tvar), &var );
					TablePutVarNb(&(res->Tvar), (WORD)(TableGetVarNb(&(res->Tvar)) + 1));
					ListDupliqueVar(res->liste_var_pub, nomvar);
				}
			}
		}

		desc += var.lgdesc;
		nb_var--;
	}

	/* Module traite */
	pt->FieldE = TRUE;

	/* On prend en compte les relocations */
	if (pt->ent->adr_xvar == 0)
		return;

	FileGetBloc(pt, pt, pt->ent->adr_xvar);

	desc = FileGetBin(pt);

	while(desc != MOINS_UN)
	{
		TableGetVar(&(mod->Tvar), desc, &var);
		desc = var.adrdesc;
		if (var.etendue)
		{
			nomvar = ListGetNomVarFromDesc(mod->liste_var_pub, desc);

			bloc = FileGetBin(pt);
			while (bloc != 0)
			{
				off  = FileGetBin(pt);
				if (nomvar == GN( ModPro)) 
					ListMajPatch(0,mod->NUM_PRG, &(mod->code),bloc, off, (WORD)(var.adrdesc + reloc_base));
				else 
					ListMajPatch(0,mod->NUM_PRG, &(mod->code),bloc, off, nomvar->used);

				bloc = FileGetBin(pt);
			}
		}
		else
		{
			/* On avance sur le suivant */
			bloc = FileGetBin(pt);
			while(bloc != 0)
			{
				off = FileGetBin(pt);
				bloc = FileGetBin(pt);
			}
		}

 		desc = FileGetBin(pt);
	}

#ifdef DBGTRC
fprintf(fdbgtrc,"\n FichierRelocVarEFIN() - Fin\n");
#endif
}


/*********************************
* FCT FichierRelocVarERECOUVRE
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
 * Sortie :
*	rien
*
* Remarque :
*	Relocation des variables field=e en recouvrement
*
**********************************/
VOID FichierRelocVarERECOUVRE ( mod, res, ancrage )
Fichier XPTR * mod;
Fichier XPTR * res;
Ancrage	XPTR * ancrage;
{ 
	WORD				bloc;
	WORD				off;
	WORD				desc;
	ULONG				reloc_taille;
	ULONG				max_taille;	/* #BG 02/10/02 */
	InfoVar			var;
	ModPro XPTR *	nomvar;
	ModPro XPTR *	nomptr;
	Tabfic XPTR *	pt;
	WORD				nb_var;

#ifdef DBGTRC
fprintf(fdbgtrc,"\n FichierRelocVarERECOUVRE() - Debut\n");
#endif

TRACE	

	pt = &(mod->dbg);

	if (pt->FieldE == TRUE)
		return;

	max_taille = 0;	/* #BG 02/10/02 */

	reloc_taille = (ULONG) ((ancrage->bloc << 16) + (ancrage->off));
	FichierSetRelocEtendue(&(res->code), reloc_taille);

	nb_var = TableGetVarNb(&(mod->Tvar));
	desc = 6;

	while(nb_var)
	{
		TableGetVar(&(mod->Tvar), desc, &var);
		desc = var.adrdesc;

		if (var.etendue)
		{
			nomvar = ListGetNomVarFromDesc(mod->liste_var_pub, desc);

			if (nomvar->used == MOINS_UN)
			{
				var.adrdesc  = TableGetReloc( &(res->Tvar) );

				/* En nombre de variables */
				
				if ((LONG) ((ULONG) TableGetVarNb(&(res->Tvar)) + 1 ) >= 65535L)
					THROW(ErreurMoteur09);

				if (var.tptr == 0x03 || var.tptr == 0x02)
				{
					nomptr = ListGetNomVarFromDesc(mod->liste_var_pub, var.adredefptr);
					var.adredefptr = nomptr->used;
				}
				else
				{
					/* En taille table */
					/* #AT: 14/09/00 (begin)*/
					CheckReloc(&mod->Tvar, MAX_VAR_DESC_OFFSET, ErreurMoteur07);
					/* #AT: 14/09/00 (end)*/

					/*	Relocation de la variable */
					FichierGetRelocEtendue(&(res->code), &var.adrfield, &var.adrvar);
				}

				reloc_taille += (ULONG)(var.longueur);

				if (reloc_taille > max_taille)	/* #BG 02/10/02 */
				{
					FichierSetRelocEtendue(&(res->code), reloc_taille);
					max_taille = reloc_taille;		/* #BG 02/10/02 */
				}

				nomvar->used = var.adrdesc;
				TablePutVar(&(res->Tvar), &var);
				TablePutVarNb(&(res->Tvar), (WORD) (TableGetVarNb( &(res->Tvar) ) + 1));
				ListDupliqueVar(res->liste_var_pub, nomvar);
			}
		}

		desc += var.lgdesc;
		nb_var--;
	}

	/* Module traite */
	pt->FieldE = TRUE;

	/* On prend en compte les relocations */
	if (pt->ent->adr_xvar == 0)
		return;

	FileGetBloc(pt, pt, pt->ent->adr_xvar);

	desc = FileGetBin(pt);

	while(desc != MOINS_UN)
	{
		TableGetVar(&(mod->Tvar), desc, &var);
		desc = var.adrdesc;
		if (var.etendue)
		{
			nomvar = ListGetNomVarFromDesc(mod->liste_var_pub, desc);

			bloc = FileGetBin(pt);
			while (bloc != 0)
			{
				off  = FileGetBin(pt);
				ListMajPatch(0,mod->NUM_PRG, &(mod->code),bloc, off, nomvar->used);
				bloc = FileGetBin(pt);
			}
		}
		else
		{
			/* 0n avance sur le suivant */
			bloc = FileGetBin(pt);
			while(bloc != 0)
			{
				off = FileGetBin(pt);
				bloc = FileGetBin(pt);
			}
		}

 		desc = FileGetBin( pt );
	}

#ifdef DBGTRC
fprintf(fdbgtrc,"\n FichierRelocVarERECOUVRE() - Fin\n");
#endif
}

/*********************************
* FCT FichierRelocVarEINSERT
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Relocation des variables field=e en insertion
*                                                                   
*                         x                                              
*                  a      y                                              
*  relo_adr  ->   ------------  <- relo_label (adr memoire a mapper sur relo_adr                                         
*                  b      z -+                                           
*                  c      w  !-> relo_insert = taille - relo_label                      
*                         u -+  <- taille de l'espace memoire
*                                                                                                                                                                   
*
**********************************/
VOID FichierRelocVarEINSERT( mod, res, ancrage, label )
Fichier XPTR *	mod;
Fichier XPTR *	res;
Ancrage XPTR *	ancrage;
Label	XPTR *	label;
{ 
	WORD				bloc;
	WORD				off;
	WORD				desc;
	ULONG				relo_taille;
	ULONG				relo_adr;
	ULONG				relo_label;
	ULONG				relo_insert;
	ULONG				relo_var;
	InfoVar			var;
	ModPro XPTR *	nomvar;
	ModPro XPTR *	nomptr;
	Tabfic XPTR *	pt;
	WORD				nb_var;

#ifdef DBGTRC
fprintf(fdbgtrc,"\n FichierRelocVarEINSERT() - Debut\n");
#endif

TRACE

	pt = &(mod->dbg);

	if (pt->FieldE == TRUE)
		return;

	relo_adr = (ULONG) ((ancrage->bloc << 16) + (ancrage->off));
	relo_label = (ULONG) ((label->bloc << 16) + (label->off));
	relo_taille = (ULONG) ((ancrage->bloc << 16) + (ancrage->off));
	
	relo_insert = FichierGetAdrEtendue(&(mod->code));

	relo_insert -= relo_label;

	/* On insere avant de reloger */
	nb_var = TableGetVarNb(&(res->Tvar));
	desc = 6;

	while(nb_var)
	{
		TableGetVar( &(res->Tvar), desc, &var );
		desc = var.adrdesc;		
		relo_var = (ULONG) ((var.adrfield << 16) + (var.adrvar));

		if (var.etendue)
		{
			if (relo_var >= relo_adr)
			{
				if (relo_label > relo_adr)
					relo_var = (relo_var - relo_adr) + (relo_label + relo_insert);
				else
					relo_var += relo_insert;
			}
			else
			{
				if (relo_label > relo_adr)
				{
					/* Le recouvrement en arriere du module est plus grand que le debut de l'espace memoire */
					relo_var = relo_label - (relo_adr - relo_var);
				}
			}

			var.adrvar = (WORD) (relo_var & 0xffff);
			var.adrfield = (WORD) ((relo_var >> 16) & 0xffff);

			TablePutVar(&(res->Tvar), &var);
		}

		desc += var.lgdesc;
		nb_var --;
	}

	/* On reloge la table en insertion */
	nb_var = TableGetVarNb(&(mod->Tvar));
	desc = 6;

	while(nb_var)
	{
		TableGetVar( &(mod->Tvar), desc, &var);
		desc = var.adrdesc;

		if ( var.etendue )
		{
			nomvar = ListGetNomVarFromDesc(mod->liste_var_pub, desc);

			if (nomvar->used == MOINS_UN)
			{
				var.adrdesc  = TableGetReloc(&(res->Tvar));

				/* En nombre de variables */
				if ((LONG) ((ULONG) TableGetVarNb(&(res->Tvar)) + 1 ) >= 65535L)
					THROW( ErreurMoteur09 );

				/* En taille table */
				/* #AT: 14/09/00 (begin)*/
				CheckReloc(&mod->Tvar, MAX_VAR_DESC_OFFSET, ErreurMoteur07);
				/* #AT: 14/09/00 (end)*/

				if (var.tptr == 0x03 || var.tptr == 0x02)
				{
					nomptr = ListGetNomVarFromDesc(mod->liste_var_pub, var.adredefptr);
					var.adredefptr = nomptr->used;
				}
				else
				{
					/*	Relocation de la variable	*/

					relo_var = (ULONG) ((var.adrfield << 16) + var.adrvar);
				
					if (relo_label < relo_adr)
					{
						if (relo_var < relo_label)
							relo_var = relo_adr - (relo_label - relo_var);
						else
							relo_var = relo_adr + (relo_var - relo_label);
					}
				}

				nomvar->used = var.adrdesc;

				var.adrvar = (WORD) (relo_var & 0xffff);
				var.adrfield = (WORD) ((relo_var >> 16) & 0xffff);

				TablePutVar(&(res->Tvar), &var);
				TablePutVarNb(&(res->Tvar), (WORD) (TableGetVarNb( &(res->Tvar) ) + 1));
				ListDupliqueVar(res->liste_var_pub, nomvar);
			}
		}

		desc += var.lgdesc;
		nb_var--;
	}

	/* Calcul de la taille de relocation */
	relo_taille = (FichierGetAdrEtendue(&(res->code) ) - relo_adr) + relo_insert;
	FichierSetRelocEtendue (&(res->code), relo_taille );

	/* Module traite */
	pt->FieldE = TRUE;

	/* On prend en compte les relocations */
	if (pt->ent->adr_xvar == 0)
		return;

	FileGetBloc(pt, pt, pt->ent->adr_xvar);

	desc = FileGetBin(pt);

	while(desc != MOINS_UN)
	{
		TableGetVar(&(mod->Tvar), desc, &var);
		desc = var.adrdesc;

		if (var.etendue)
		{
			nomvar = ListGetNomVarFromDesc(mod->liste_var_pub, desc);

			bloc = FileGetBin( pt );
			while(bloc != 0)
			{
				off = FileGetBin(pt);
				ListMajPatch(0, mod->NUM_PRG, &(mod->code),bloc, off, nomvar->used);
				bloc = FileGetBin(pt);
			}

		}
		else
		{
			/* On avance sur le suivant */
			bloc = FileGetBin(pt);
			while (bloc != 0)
			{
				off = FileGetBin(pt);
				bloc = FileGetBin(pt);
			}
		}

 		desc = FileGetBin(pt);
	}

#ifdef DBGTRC
fprintf(fdbgtrc,"\n FichierRelocVarEINSERT() - Fin\n");
#endif
}

/*********************************
* FCT FichierRelocVarVIRT
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Relocation des variables virtuelles
*
**********************************/
VOID FichierRelocVarVIRT ( mod, res )
Fichier XPTR *	mod;
Fichier XPTR *	res;
{ 
	WORD				bloc;
	WORD				off;
	WORD				desc;
	WORD				reloc_taille;
	WORD 				reloc_base;
	InfoVar			var;
	InfoVar			pubvar;
	ModPro XPTR *	nomvar;
	ModPro XPTR *	pubvirt;
	Tabfic XPTR *	pt;
	WORD				nb_var;
	BOOL				reloc_virt;
	
#ifdef DBGTRC
fprintf(fdbgtrc,"\n FichierRelocVarVIRT() - Debut\n");
#endif

TRACE

	pt = &(mod->dbg);

	if (pt->FieldV == TRUE)
		return;

	/* On reloge la table */
	reloc_taille = TableGetVarTaille(&(res->Tvar)) + 1;
	reloc_base = TableGetReloc(&(res->Tvar)) - 6;

	nb_var = TableGetVarNb(&(mod->Tvar));
	desc = 6;

	while(nb_var)
	{
		TableGetVar(&(mod->Tvar), desc, &var);
		desc = var.adrdesc;

		if (var.virtuelle)
		{
			nomvar = ListGetNomVarFromDesc(mod->liste_var_pub, desc);
			if (nomvar == GN( ModPro))
			{
				var.adrdesc = TableGetReloc(&(res->Tvar));

				/* En nombre de variables */

				if ((LONG) ((ULONG) TableGetVarNb(&(res->Tvar)) + 1) >= 65535L)
					THROW( ErreurMoteur09 );

				/* En taille table */
				/* #AT: 14/09/00 (begin)*/
				CheckReloc(&mod->Tvar, MAX_VAR_DESC_OFFSET, ErreurMoteur07);
				/* #AT: 14/09/00 (end)*/

				/*	Relocation de la variable	*/
				TablePutVar(&(res->Tvar), &var);
				TablePutVarNb(&(res->Tvar), (WORD)(TableGetVarNb(&(res->Tvar)) + 1));
			}
			else
			{
				if (nomvar->used == MOINS_UN)
				{
					reloc_virt = TRUE;
					pubvirt = ListIsCstPub(res->liste_var_pub, nomvar);
					if (pubvirt)
					{
						/* le meme nom existe sont ils de meme type ? */
						TableGetVar( &(res->Tvar), pubvirt->used, &pubvar);
						if (ListMatchVar(&var, &pubvar))
						{
							/* oui il sont de meme type */
							nomvar->used = pubvirt->used;
							reloc_virt = FALSE;
						}
					}
					if (reloc_virt == TRUE)
					{
						var.adrdesc  = TableGetReloc(&(res->Tvar));

						/* En nombre de variables */

						if ((LONG) ((ULONG) TableGetVarNb(&(res->Tvar)) + 1 ) >= 65535L) 
							THROW( ErreurMoteur09 );

						/* En taille table */
						/* #AT: 14/09/00 (begin)*/
						CheckReloc(&mod->Tvar, MAX_VAR_DESC_OFFSET, ErreurMoteur07);
						/* #AT: 14/09/00 (end)*/

						/*	Relocation de la variable	*/
						nomvar->used = var.adrdesc;

						TablePutVar(&(res->Tvar), &var);
						TablePutVarNb(&(res->Tvar), (WORD)(TableGetVarNb(&(res->Tvar)) + 1));
						ListDupliqueVar(res->liste_var_pub, nomvar);
					}
				}
			}
		}

	desc += var.lgdesc;
	nb_var--;
	}

	/* Module traite */
	pt->FieldV = TRUE;

	/* On prend en compte les relocations */
	if (pt->ent->adr_xvar == 0)
		return;

	FileGetBloc(pt, pt, pt->ent->adr_xvar);

	desc = FileGetBin(pt);

	while(desc != MOINS_UN)
	{
		TableGetVar(&(mod->Tvar), desc, &var);
		desc = var.adrdesc;

		if (var.virtuelle)
		{
			nomvar = ListGetNomVarFromDesc(mod->liste_var_pub, desc);

			bloc = FileGetBin(pt);
			while(bloc != 0)
			{
				off = FileGetBin(pt);

				if (nomvar == GN(ModPro))
					ListMajPatch(0,mod->NUM_PRG, &(mod->code), bloc, off, (WORD)(var.adrdesc + reloc_base));
				else
					ListMajPatch(0,mod->NUM_PRG, &(mod->code), bloc, off, nomvar->used );

				bloc = FileGetBin(pt);
			}
		}
		else
		{
			/* on avance sur le suivant */
			bloc = FileGetBin(pt);
			while(bloc != 0)
			{
				off = FileGetBin(pt);
				bloc = FileGetBin(pt);
			}
		}

 		desc = FileGetBin(pt);
	}
#ifdef DBGTRC
fprintf(fdbgtrc,"\n FichierRelocVarVIRT() - Fin\n");
#endif
}

/*********************************
* FCT FichierRelocModExt
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Reloge les noms de modules externs 
*
**********************************/
VOID FichierRelocModExt( mod, res )
Fichier XPTR * mod;
Fichier XPTR * res;
{ 
	C_SNODE FAR *	pt_node;
	Name XPTR *	pt_name;

TRACE

	/* pour chaque procedure externe */
	SlistRewind( mod->liste_mod_ext );
	pt_node = SlistGetNext( mod->liste_mod_ext );
	while( pt_node ) {
		pt_name = SnodeGet( pt_node );

		ListAddNameUnique( res->liste_mod_ext, pt_name->nom );		

		pt_node = SnodeGetNext( pt_node );
	}
}

/*********************************
* FCT FichierRelocProExt
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Construction de la 
*
**********************************/
VOID FichierRelocProExt( mod, res )
Fichier XPTR * mod;
Fichier XPTR * res;
{ 
	C_SNODE FAR * pt_node;
	LstPro XPTR * pt_extern;
	LstPro XPTR * pp_extern;
	BYTE 	    nom[LGIDENT];

TRACE

	/* pour chaque procedure externe */
	SlistRewind( mod->liste_pro_ext );
	pt_node = SlistGetNext( mod->liste_pro_ext );
	while( pt_node )
	{
		pt_extern = SnodeGet( pt_node );
	
		if ( pt_extern->solved == MOINS_UN )
		{
			/* Existe t elle dans la liste publique des proc. externes */

			pp_extern = ListIsProExtPub( res->liste_pro_ext, pt_extern, res, mod );

			if (pp_extern != GenericNULL( LstPro ) )
			{
				if ( pp_extern->solved == MOINS_UN )
				{
					/* Elle existe deja et non encore resolue => on Transfert les references */
					ListConcat( pp_extern->pt_ref, pt_extern->pt_ref );
				}
				else
				{
					/* Procedure deja resolue, on reloge les references avec la valeur de la procedure publique */
					pt_extern->solved = pp_extern->solved;
					ListRelocPatch(mod,  pt_extern->pt_ref, pp_extern->solved, (BYTE) 0 );
				}
			}
			else
			{
				ListDupliqueProExt( res->liste_pro_ext, pt_extern );
				/* mettre a jour par_qui le seg. ext doit etre reloge */
				
				
				if ( pt_extern->par_qui != MOINS_UN)
				{
					pp_extern		= SnodeGet( SlistGetHead(res->liste_pro_ext));
					ListGetNameFromNum( mod->liste_mod_ext, pt_extern->par_qui, nom );
					pp_extern->par_qui	= ListGetNameNum( res->liste_mod_ext, nom );
				}
			}
		}
		pt_node = SnodeGetNext( pt_node );
	}
}
	
/*********************************
* FCT FichierRelocSegExt
*
* Entree : 
* 	le fichier en lecture
*	le fichier qui recoit la table
*
* Sortie :
*	rien
*
* Remarque :
*	Construction de la 
*
**********************************/
VOID FichierRelocSegExt( mod, res )
Fichier XPTR * mod;
Fichier XPTR * res;
{ 
	C_SNODE FAR *	pt_node;
	LstPro XPTR *	pt_extern;
	LstPro XPTR *	pp_extern;
	BYTE		nom[LGIDENT];
	
TRACE

	/* pour chaque procedure externe */
	SlistRewind( mod->liste_seg_ext );
	pt_node = SlistGetNext( mod->liste_seg_ext );
	while( pt_node )
	{
		pt_extern = SnodeGet( pt_node );
	
		if ( pt_extern->solved == MOINS_UN )
		{
			/* Existe t elle dans la liste publique des proc. externes */

			pp_extern = ListIsSegExtPub( res->liste_seg_ext, pt_extern, res, mod );

			if (pp_extern != GenericNULL( LstPro ) )
			{

				if ( pp_extern->solved == MOINS_UN )
				{
					/* Elle existe deja et resolu => on Transfert les references */
					ListConcat( pp_extern->pt_ref, pt_extern->pt_ref );
				}
				else
				{
					/* Segment deja resolue, on reloge les references avec la valeur de la procedure publique */
					pt_extern->solved = pp_extern->solved;
					ListRelocPatch(mod,  pt_extern->pt_ref, pp_extern->solved, (BYTE) 0 );
				}
			}
			else
			{
				ListDupliqueSegExt( res->liste_seg_ext, pt_extern );

				/* mettre a jour par_qui le seg. ext doit etre reloge */
				
				if ( pt_extern->par_qui != MOINS_UN)
				{
					pp_extern		= SnodeGet( SlistGetHead(res->liste_seg_ext));
					ListGetNameFromNum( mod->liste_mod_ext, pt_extern->par_qui, nom );
					pp_extern->par_qui	= ListGetNameNum( res->liste_mod_ext, nom );

				}
			}

		}
		pt_node = SnodeGetNext( pt_node );
	}
}

/*********************************
* FCT FichierRelocPro
*
* Entree : 
* 	le fichier en lecture
*	le fichier destination
*	la procedure publique a reloger
*
*
* Sortie :
*	rien
*
* Remarque :
*	relocation + transfert des informations lies a la procedure numero 
*
**********************************/

VOID FichierRelocPro( fic, des, pp )
Fichier XPTR *	fic;
Fichier XPTR *	des;
ModPro	XPTR *	pp;
{ 
	InfoPro pro;
	WORD p_fils;
	WORD p_bloc;
	WORD p_off;
	BYTE p_byte;

TRACE

	/* Relocation de toutes les references aux references appell‚es */

	/* Correction 2.1b du 25/01/94 */
	if (pp->used != MOINS_UN) return; /* Deja traite */

	if (pp->proc_app)
	{
		/* Determination du fils */

		FileGetBloc(&(fic->dbg), &(fic->dbg), pp->proc_app);
		p_byte = FileGetByte(&fic->dbg);

		do
		{
			p_fils = FileGetBin(&fic->dbg);
			p_bloc = FileGetBin(&fic->dbg);
			p_off  = FileGetBin(&fic->dbg);

			ListMajPatch(0,fic->NUM_PRG, &(fic->code), p_bloc, p_off, MOINS_UN);

			/* Determination du frere */
			p_byte = FileGetByte(&fic->dbg);
		}
		while (p_byte != 0xff);

	}

	/* relocation de la table des procedures */
	TableSeek( &(fic->Tpro), pp->num_desc );
	TableGetPro( &(fic->Tpro), pp->num_desc, &pro );

	FichierCopyPro( fic, des, &pro );

	pro.adrdesc = TableGetReloc( &(des->Tpro) );
	pp->used = pro.adrdesc;

	/* #OK: 25/07/00 (begin) */
	if ( (ULONG) ((ULONG)pro.adrdesc + (ULONG)pro.lgdesc) >= 32766L )
		THROW( ErreurMoteur08 )
	else
	/* #OK: 25/07/00 (end) */
		TablePutPro( &(des->Tpro), &pro );

	/* relocation de la map */
	if (pp->adr_map)
	{
		pp->adr_map = FichierRelocMap( fic, des, pp->adr_map );
	}

	/* relocation du nom de la procedure */

	/* On duplique la procedure dans la liste
	   des procedures publiques */
	ListDupliquePro( des->liste_pro_pub, pp );
}

/*********************************
* FCT FichierRelocMap
*
* Entree : 
* 	le fichier origine
*	le fichier destination
*	bloc ou se trouve la map a reloger
*
* Sortie :
*	bloc ou a eu lieu la relocation de la tabl de correspoondance
*
* Remarque :
*	Relocation d'une table de correspondance d'un code reloge
*
**********************************/

WORD FichierRelocMap(module, res, bloc )
Fichier XPTR *	module;
Fichier XPTR *	res;
WORD		bloc;
{ 
	Name XPTR * pt_source;
	
	WORD 	num_source;
	WORD	reloc_source;
	WORD 	long_bas;
	WORD	long_haut;
	WORD	adr_varloc;
	WORD	lgn_varloc;
	WORD	adr_cstloc;
	WORD	lgn_cstloc;
	WORD	tcode_nl;
	WORD	reloc_map;

TRACE

	if (bloc == 0) return( 0 );
	
	FileGetBloc( &(module->dbg), (&module->dbg), bloc );

	adr_varloc = FileGetBin( &(module->dbg) );
	lgn_varloc = FileGetBin( &(module->dbg) );
	adr_cstloc = FileGetBin( &(module->dbg) );
	lgn_cstloc = FileGetBin( &(module->dbg) );

	reloc_map  = FileGetReloc( &(res->dbg) ); 

	FilePutBin(&(res->dbg), adr_varloc);
	FilePutBin(&(res->dbg), lgn_varloc);
	FilePutBin(&(res->dbg), adr_cstloc);
	FilePutBin(&(res->dbg), lgn_cstloc);
	

	num_source = FileGetBin( &(module->dbg) );
	while ( num_source != MOINS_UN )
	{
		long_bas  = FileGetBin( &(module->dbg) );
		long_haut = FileGetBin( &(module->dbg) );
		tcode_nl  = FileGetBin( &(module->dbg) );
				
		if (module->NUM_PRG)
		{
			pt_source = ListGetNameItemFromNum( module->liste_source, num_source );
			
			if ( pt_source)
				reloc_source = ListAddNameUnique( res->liste_source, pt_source->nom );
			else
				reloc_source = 0;
		}
		else
		{
			reloc_source = num_source;
		}

		FilePutBin( &(res->dbg), reloc_source);
		FilePutBin( &(res->dbg), long_bas );
		FilePutBin( &(res->dbg), long_haut);
		FilePutBin( &(res->dbg), tcode_nl );
	
		num_source = FileGetBin( &(module->dbg) );
	}

	FilePutBin( &(res->dbg), MOINS_UN );

	FileEndBloc( &(res->dbg) );

	return( reloc_map );
}


/*********************************
* FCT FichierRelocSeg
*
* Entree : 
* 	le fichier en lecture
*	le fichier destination
*	Le segment publique a reloger
*	Extern as ( num )
*
* Sortie :
*	rien
*
* Remarque :
*	relocation + transfert des informations lies au segment numero 
*
**********************************/

VOID FichierRelocSeg( fic, des, pp_seg, extern_as )
Fichier XPTR *	fic;
Fichier XPTR *	des;
ModPro  XPTR *	pp_seg;
WORD 		extern_as;
{
	InfoSeg seg;
	WORD p_fils;
	WORD p_bloc;
	WORD p_off;
	BYTE p_byte;
	WORD save_adr;
	/* #OK: 16/10/00 (begin) */
	int myOffset=0;
	/* #OK: 16/10/00 (end) */
	
TRACE

	/* Relocation de toutes les references aux references appell‚es */

	/* Correction 2.1b du 25/01/94 */
	if (pp_seg->used != MOINS_UN) return; /* deja relogee */

	if (pp_seg->proc_app)
	{
		/* Determination du fils */

		FileGetBloc(&(fic->dbg), &(fic->dbg), pp_seg->proc_app);
		p_byte = FileGetByte(&fic->dbg);
		do
		{
			p_fils = FileGetBin(&fic->dbg);
			p_bloc = FileGetBin(&fic->dbg);
			p_off  = FileGetBin(&fic->dbg);

			ListMajPatch(0,fic->NUM_PRG, &(fic->code), p_bloc, p_off, MOINS_UN);

			/* Determination du frere */
			p_byte = FileGetByte(&fic->dbg);
		}
		while (p_byte != 0xff);
	}

    /* #OK: 16/10/00 (begin) */
	myOffset = (pp_seg->num_desc / 4096) * 16;
    /* #OK: 16/10/00 (end) */

	TableSeek( &(fic->Tseg), pp_seg->num_desc );

	/* #OK: 25/07/00 ALD NR (begin) Commented by OK
	if (fic->Tseg.reloc <= pp_seg->num_desc)
	    THROW( ErreurMoteur12 );    
	/* #OK: 25/07/00 ALD NR (end) */

	/* #OK: 16/10/00 (begin) */
	TableGetSeg( &(fic->Tseg), pp_seg->num_desc - myOffset, &seg );
	/* #OK: 16/10/00 (end) */

	/********************************/
	/* reloger le numero de segment */
	/********************************/
	if (seg.numseg == MOINS_UN)
	{
		if (extern_as == MOINS_UN)
		{
			/* a reloger completement */
			seg.numseg = des->next_num_seg;
			des->next_num_seg ++; /* ex -- A partir de 2.1c voir Mr Marshall pour les raisons*/
		}
		else
		{
			/* extern as */
			seg.numseg = extern_as;
		}
	}

	/* #OK: 25/07/00 ALD NR (begin) */
	if ( (ULONG) ((ULONG)seg.adrdesc + (ULONG)seg.lgdesc) >= 32766L - 16)
		THROW( ErreurMoteur12 )
	else
	/* #OK: 25/07/00 ALD NR (end) */
		FichierCopySeg( fic, des, &seg );

	seg.adrdesc = TableGetReloc( &(des->Tseg) );

	pp_seg->used = seg.numseg;

	/* A retablir après la duplication du segment reloge */
	save_adr = pp_seg->num_desc; 
	pp_seg->num_desc = seg.adrdesc;

	/* #OK: 25/07/00 ALD NR (begin) */
	if ( (ULONG) ((ULONG)seg.adrdesc + (ULONG)seg.lgdesc) >= 32766L )
		THROW( ErreurMoteur12 )
	else
	/* #OK: 25/07/00 ALD NR (end) */
		TablePutSeg( &(des->Tseg), &seg );
	

	/* relocation de la map */
	if (pp_seg->adr_map)
	{
		pp_seg->adr_map = FichierRelocMap( fic, des, pp_seg->adr_map );
	}

	/* relocation du nom de la procedure */

	/* On duplique la procedure dans la liste
	   des procedures publiques */
	ListDupliqueSeg( des->liste_seg_pub, pp_seg );
	
	pp_seg->num_desc = save_adr; 
	
}

/***************/
/* Transferts  */
/***************/

/*********************************
* FCT FichierCopyPro
*
* Entree : 
* 	le fichier en lecture
*	le fichier destination
*	Procedure a copier
*
* Sortie :
*	rien
*
* Remarque :
*	transfert des informations lies a une procedure
*
**********************************/
VOID FichierCopyPro( fic, des, pro )
Fichier XPTR * fic;
Fichier XPTR * des;
InfoPro XPTR * pro;
{ 

	WORD bloc;

TRACE

	/* transferer le code        */

	bloc = FileGetReloc( &(des->code) );
	FichierCopyCode( fic, des, pro->adrcode, pro->lgcode );
	pro->adrcode = bloc;


	/* transferer les variables  */

	if (pro->adrdcl)
	{
		bloc = FileGetReloc( &(des->code) );
		FichierCopyVar( fic, des, pro->adrdcl, pro->lgdcl );
		pro->adrdcl = bloc;
	}

	/* transferer les constantes */

	if (pro->adrcst)
	{
		bloc = FileGetReloc( &(des->code) );
		FichierCopyCst( fic, des, pro->adrcst, pro->lgcst );
		pro->adrcst = bloc;
	}
}

/*********************************
* FCT FichierCopySeg
*
* Entree : 
* 	le fichier en lecture
*	le fichier destination
*	Segment a copier
*
* Sortie :
*	rien
*
* Remarque :
*	transfert des informations lies a un segment
*
**********************************/
VOID FichierCopySeg( fic, des, seg )
Fichier XPTR * fic;
Fichier XPTR * des;
InfoSeg XPTR * seg;
{ 

	WORD bloc;

TRACE
	/* transferer le code        */

	bloc = FileGetReloc( &(des->code) );
	FichierCopyCode( fic, des, seg->adrcode, seg->lgcode );
	seg->adrcode = bloc;


	/* transferer les variables  */

	if (seg->adrdcl)
	{
		bloc = FileGetReloc( &(des->code) );

		FichierCopyVar( fic, des, seg->adrdcl, seg->lgdcl);
		seg->adrdcl = bloc;
	}
	/* transferer les constantes */

	if (seg->adrcst)
	{
		bloc = FileGetReloc( &(des->code) );
		FichierCopyCst( fic, des, seg->adrcst, seg->lgcst );
		seg->adrcst = bloc;
	}
}



/*********************************
* FCT FichierCopyVar
*
* Entree : 
* 	le fichier en lecture
*	le fichier destination
*	le bloc ou se situe la table des variables a transferer
*
*
* Sortie :
*	rien
*
* Remarque :
*	recopie d'une table de variable
*
**********************************/
VOID FichierCopyVar( source, target, bloc, lg )
Fichier XPTR *	source;
Fichier XPTR *	target;
WORD		bloc;
WORD 		lg;
{ 
	WORD nb_var;
	WORD adr_nom;
	WORD taille;
	WORD relo_nom;
	WORD relo_var;
	BYTE nomv[LGIDENT];
	WORD desc;
	
TRACE
	if (bloc == 0) return; /* pas de variable */

	/* recupere l'adresse des noms de variable */
	
	FilePositBloc( &(source->code), bloc );
	FileReadBloc( &(source->code), &(source->code), bloc );

	nb_var  = FileGetBin( &(source->code) );
	adr_nom = FileGetBin( &(source->code) );
	taille  = FileGetBin( &(source->code) );

	if ( target->code.ent->l_mxvl < lg ) target->code.ent->l_mxvl = lg;
	if ( target->code.ent->t_mxdl < taille ) target->code.ent->t_mxdl = taille;

	/* transfert de la table de variable */
	relo_var = FileGetReloc( &(target->code) );
	FileCopyBuf( &(source->code), &(target->code), bloc, lg);

	if (adr_nom)
	{
		/* transfert des noms de variables locales */

		relo_nom = FileGetReloc( &(target->dbg));

		FilePositBloc( &(source->dbg), adr_nom );
		FileReadBloc( &(source->dbg), &(source->dbg), adr_nom );
		
		while (nb_var)
		{
			FileGetString( &(source->dbg), nomv );
			desc = FileGetBin( &(source->dbg) );
		
			FilePutString( &(target->dbg), nomv );
			FilePutBin( &(target->dbg), desc );

			nb_var --;
		}

		FileEndBloc( &(target->dbg) );

		ListMajPatch(0xff,target->NUM_PRG, &(target->code), relo_var, 2, relo_nom);
	}		
}

/*********************************
* FCT FichierCopyCst
*
* Entree : 
* 	le fichier en lecture
*	le fichier destination
*	le bloc ou se situe la table des variables a transferer
*	la longeur de la table
*
* Sortie :
*	rien
*
* Remarque :
*	recopie d'une table de constantes
*
**********************************/
VOID FichierCopyCst( source, target, bloc, lg )
Fichier XPTR *	source;
Fichier XPTR *	target;
WORD		bloc;
WORD 		lg;
{
	TRACE

	if (bloc == 0) return; /* pas de constante */

	FichierCopyCode( source, target, bloc, lg );
}

/*********************************
*
* FCT FichierCopyCode
*
* Entree : 
*	un fichier origine
*	un fichier destination
*	le bloc de depart
*	la longeur a transferer
*			
* Sortie :
*	rien
*
* Remarque :
*	initialise la structure d'une Table
*
* Voir aussi:
*
*
**********************************/

VOID FichierCopyCode(source, target, debut, lg)		/* getcode */
Fichier XPTR * source;
Fichier XPTR * target;					/* buffer de reception */
WORD debut;
WORD lg;
{ 
	WORD i,j;
	WORD rel_bloc;

TRACE

	FileSeek( &(source->code), debut );

	rel_bloc = FileGetReloc( &(target->code) );
	i = lg / LGBUF;

	for( i=0; i < lg /LGBUF; i ++)
	{
		/* lecture par bloc de LGBUF */
		FileRead( &(source->code), source->code.tmp, LGBUF );
		for( j=0; j < LGBUF / LGBLOC; j++)
		{
			ListTestPatch(source->NUM_PRG, debut ++, &(target->code), rel_bloc ++ );
		}
		FileWrite( &(target->code), source->code.tmp, LGBUF );
	} 

	i = lg - ((lg/LGBUF) * LGBUF);

	if ( i != 0 )
	{
		/* longueur non multiple de 4096  modif 1/7/94 */	
		i =  (i + LGBLOC - 1) / LGBLOC;
		FileRead( &(source->code), source->code.tmp, (WORD) (i * LGBLOC) );
		for( j=0; j < i; j++)
		{
			ListTestPatch(source->NUM_PRG, debut ++, &(target->code), rel_bloc ++ );
		}
		FileWrite( &(target->code), source->code.tmp, (WORD) (i * LGBLOC) );
	}
}

/*********************************
*
* FCT FichierRelocProApp
*
* Entree : 
*	un fichier origine
*	un fichier destination
*	une procedure
*			
* Sortie :
*	rien
*
* Remarque :
*	Reloge toutes les procedures appellees par cette procedure
*
* Voir aussi:
*
*
**********************************/
VOID FichierRelocProApp( module, resultat, pp_proc )
Fichier XPTR * module;
Fichier XPTR * resultat;
ModPro XPTR * pp_proc;
{ 
	BYTE p_byte;
	WORD p_fils, p_bloc, p_off;
	WORD sauv_bloc, sauv_ofst;

TRACE
	/* Se positionne sur la procedure dans la table des procedures */

	if (pp_proc->proc_app) {
		/* Determination du fils */
		
		FileGetBloc(&(module->dbg), &(module->dbg), pp_proc->proc_app);
		p_byte = FileGetByte(&module->dbg);
		
		do
		{
			p_fils = FileGetBin(&module->dbg);
			p_bloc = FileGetBin(&module->dbg);
			p_off  = FileGetBin(&module->dbg);

			sauv_bloc = FileGetNumBloc( &(module->dbg) );
			sauv_ofst = FileGetOffset( &(module->dbg) );

			ListMajPatch(0,module->NUM_PRG, &(module->code), p_bloc, p_off, MOINS_UN);
			/* Test si c'est une procedure externe ou globale */
			if (p_byte == 0)
			{ /* Procedure globale */
				/* Test si la procedure est dans la liste */
				pp_proc = ListGetProCall( module->liste_pro_pub , p_fils );
				
				if (pp_proc->used == MOINS_UN)
				{
					/* Proc non utilisee -> a reloger */
					FichierRelocPro( module, resultat, pp_proc );
#ifdef OLD
					pp_proc->used = FichierRelocProNum( module, resultat, pp_proc->num_desc );

					/* On duplique la procedure dans la liste des procedures publiques */
					ListDupliquePro( resultat->liste_pro_pub, pp_proc );
#endif

					/* Appel recursif */
					FichierRelocProApp(module, resultat, pp_proc);

					/* remise en etat */
					FileGetBloc(&module->dbg, &module->dbg, sauv_bloc);
					FilePutBlocOfst( &(module->dbg) , sauv_bloc, sauv_ofst);

				}

				/* Mettre a jour la relocations */

				ListMajPatch(0,module->NUM_PRG, &(module->code), p_bloc, p_off, pp_proc->used);
			}
			else
			{	/* Procedure externe */
				/* on se place sur la procedure externe */
				/* 0xfffe = extern utilise */
				ListMajPatch(0,module->NUM_PRG, &(module->code), p_bloc, p_off, 0xfffe);
			}

			/* Determination du frere */
			p_byte = FileGetByte(&module->dbg);
		}
		while (p_byte != 0xff);

	}
}

/*********************************
*
* FCT FichierRelocSegApp
*
* Entree : 
*	un fichier origine
*	un fichier destination
*	un segment public
*			
* Sortie :
*	rien
*
* Remarque :
*	Reloge les segments et procedures appeles par le segment
*
* Voir aussi:
*
*
*/

VOID FichierRelocSegApp( module, resultat, pp_seg)
Fichier XPTR * module;
Fichier XPTR * resultat;
ModPro XPTR * pp_seg;
{
	BYTE p_byte;
	WORD p_fils, p_bloc, p_off;
	WORD sauv_bloc, sauv_ofst;

 TRACE

	/* Se positionne sur la procedure dans la table des procedures */

	if (pp_seg->proc_app)
	{
		/* Determination du fils */

		FileGetBloc(&(module->dbg), &(module->dbg), pp_seg->proc_app);
		p_byte = FileGetByte(&module->dbg);
		do
		{
			p_fils = FileGetBin(&module->dbg);
			p_bloc = FileGetBin(&module->dbg);
			p_off  = FileGetBin(&module->dbg);

			sauv_bloc = FileGetNumBloc( &(module->dbg) );
			sauv_ofst = FileGetOffset( &(module->dbg) );
			ListMajPatch(0,module->NUM_PRG, &(module->code), p_bloc, p_off, MOINS_UN);

			/* Test si c'est une procedure externe ou globale */
			switch( p_byte )
			{
				case 0: /* Procedure globale */
					/* Test si la procedure est dans la liste */

					pp_seg = ListGetProCall( module->liste_pro_pub , p_fils );
				
					if (pp_seg->used == MOINS_UN)
					{
						/* Proc non utilisee -> a reloger */
						FichierRelocPro( module, resultat, pp_seg );
						/* Appel recursif */
						FichierRelocProApp(module, resultat, pp_seg);

						/* remise en etat */
						FileGetBloc(&module->dbg, &module->dbg, sauv_bloc);
						FilePutBlocOfst( &(module->dbg) , sauv_bloc, sauv_ofst);

					}

					/* Mettre a jour la relocations */

					ListMajPatch(0,module->NUM_PRG, &(module->code), p_bloc, p_off, pp_seg->used);
					break;

				case 2: /* segment public */
					pp_seg = ListGetProCall( module->liste_seg_pub , p_fils );
				
					if (pp_seg->used == MOINS_UN)
					{
						/* Proc non utilisee -> a reloger */
						FichierRelocSeg( module, resultat, pp_seg, MOINS_UN );

						/* Appel recursif */
						FichierRelocSegApp(module, resultat, pp_seg);

						/* remise en etat */
						FileGetBloc(&module->dbg, &module->dbg, sauv_bloc);
						FilePutBlocOfst( &(module->dbg) , sauv_bloc, sauv_ofst);
					}

					/* Mettre a jour la relocations */

					ListMajPatch(0,module->NUM_PRG, &(module->code), p_bloc, p_off, pp_seg->used);
					break;

				case 1: /* procedure extern */
				case 3: /* segment extern */
					/* on se place sur la procedure externe */
					/* 0xfffe = extern utilise */

					ListMajPatch(0,module->NUM_PRG, &(module->code), p_bloc, p_off, 0xfffe);

					break;

			}

			/* Determination du frere */
			p_byte = FileGetByte(&module->dbg);
		}
		while (p_byte != 0xff);
	}

}

VOID FichierEndModule( mod, res, cst_alias)
Fichier XPTR *	mod;
Fichier XPTR *	res;
BOOL		cst_alias;
{

TRACE

	/* Si le module contient des informations symboliques il le
	communique au traduit final */
	if ( mod->code.ent->opt & 1 )
	{
		res->code.ent->opt |= 0x01;
		res->dbg.ent->opt |= 0x01;
	}

	/* reloge les bda */
	FichierRelocBda( mod, res);

	/* reloge les constantes */
	FichierRelocCst( mod, res, cst_alias );

	/* reloge les variables */
	FichierRelocVarVIRT( mod, res );

	/* reloge les noms de module externs */
	FichierRelocModExt( mod, res );

	/* reloge les procedures externes utilisees */
	FichierRelocProExt( mod, res );

	/* reloge les segments externs utilises */
	FichierRelocSegExt( mod, res );

	/* reloge les segments externs utilises */
	FichierRelocVarExt( mod, res );
}

VOID FichierCstConstruct( res )
Fichier XPTR * res;
{ 

	ModPro XPTR *	nomcst;
	WORD		i;
	C_SNODE FAR *	node;

TRACE
	if (TableIsVide( &(res->Tcst) ) ) return;

	res->code.ent->adr_tcg = FileGetReloc( &res->code );
	res->code.ent->lng_tcg = (WORD) TableGetReloc( &(res->Tcst ) );
	TablePutToFile( &(res->code) , &(res->Tcst) );


	if (ListCountHashList( res->liste_cst_pub ) == 0 )
	{
		res->dbg.ent->nom_cst  = 0;
	}
	else
	{
		res->dbg.ent->nom_cst  = FileGetReloc( &(res->dbg ) );
		/* Noms de constantes */ 
		for (i=0; i< HTV; i++ )
		{
			SlistRewind( res->liste_cst_pub[i] );
			node = SlistGetNext( res->liste_cst_pub[ i ] );
			while ( node )
			{
				nomcst = SnodeGet( node );
	
				FilePutString( &(res->dbg), nomcst->nom );
				FilePutBin( &(res->dbg), nomcst->used );
	
				node = SlistGetNext( res->liste_cst_pub[i] );
			}
		}
		FilePutByte( &(res->dbg), 0 );
		FileEndBloc( &(res->dbg ) );
	}

	/* Noms de constantes binaires */ 
	if (ListCountHashList( res->liste_cstbin_pub ) == 0 )
	{
		res->dbg.ent->nom_cstbin  = 0;
	}
	else
	{
		res->dbg.ent->nom_cstbin  = FileGetReloc( &(res->dbg ) );
		/* Noms de constantes */ 
		for (i=0; i< HTV; i++ )
		{
			SlistRewind( res->liste_cstbin_pub[i] );
			node = SlistGetNext( res->liste_cstbin_pub[ i ] );
			while ( node )
			{
				nomcst = SnodeGet( node );
	
				FilePutString( &(res->dbg), nomcst->nom );
				FilePutBin( &(res->dbg), nomcst->used );

				node = SlistGetNext( res->liste_cstbin_pub[i] );
			}
		}

		FilePutByte( &(res->dbg), 0 );
		FileEndBloc( &(res->dbg ) );
	}
}	

VOID FichierVarConstruct( res )
Fichier XPTR * res;
{
	C_SNODE FAR *	node;
	ModPro XPTR *	pt_pub;
	WORD		bloc_fin;
	WORD		adr_nom;
	WORD		i;
	ULONG		reloc_fielde;

#ifdef DBGTRC
fprintf(fdbgtrc,"\n FichierVarConstruct() - Debut\n");
#endif

 TRACE
	/* Transfert des noms de variables */

	if ( TableGetReloc( &(res->Tvar)) == 6 ) return; /* Table vide */

#ifdef DBGTRC
fprintf(fdbgtrc,"\nVariables field=m - Taille table = %ld \n", (ULONG) TableGetReloc(&(res->Tvar)));
#endif

	/* #AT: 14/09/00 (begin)*/
	CheckReloc(&res->Tvar, MAX_VAR_DESC_OFFSET, ErreurMoteur07);
	/* #AT: 14/09/00 (end)*/

	/*	if (ListCountHashList( res->liste_var_pub ) == 0 || (! res->ent_code.opt & 1) )*/
	if (ListCountHashList( res->liste_var_pub ) == 0 )
	{
		adr_nom = 0; /* pas de nom de variables */
	}
	else
	{
		adr_nom = FileGetReloc( &(res->dbg ) );

		for (i=0; i< HTV; i++)
		{
			SlistRewind( res->liste_var_pub[i] );
			node = SlistGetNext( res->liste_var_pub[i] );
			while ( node )
			{
				pt_pub = SnodeGet( node );

				FilePutString( &(res->dbg), pt_pub->nom );
#ifndef VERSION_XX
				/* #AT: 19/10/00 (begin) */
				ChangeGlobVarAdr(&pt_pub->used);
				/* #AT: 19/10/00 (end) */			
#endif
				FilePutBin( &(res->dbg), pt_pub->used );
						
				node = SlistGetNext( res->liste_var_pub[i] );
			}
		}

		FileEndBloc( &(res->dbg) );

		/* teste le debordement de la table */
		bloc_fin = FileGetReloc( &(res->dbg) );

		if ( bloc_fin > adr_nom + LGMAXTABLE / LGBLOC )
		{
			/* tester le depassement de la table des noms de variable */
			THROW(ErreurMoteur11); 
		}
	}
	/* Transfert de table des variables */
	TablePutVarNom( &(res->Tvar), adr_nom );


	res->code.ent->adr_tvg = FileGetReloc( &(res->code) );
	res->code.ent->lng_tvg = TableGetReloc( &(res->Tvar) );

	reloc_fielde = FichierGetAdrEtendue( &(res->code) );
	if (reloc_fielde)
	{
		/* nombre de bloc de un mega */
		res->code.ent->reserve = (WORD) ( reloc_fielde >> 20 );

		/* le reste en nombre de paragraphe */
		res->code.ent->lng_xtm = (WORD) (( reloc_fielde >> 4 ) + 1);
		if (res->code.ent->lng_xtm == 0) res->code.ent->reserve++;
	}
	else
	{
		/* nombre de bloc de un mega */
		res->code.ent->reserve = 0;

		/* le reste en nombre de paragraphe */
		res->code.ent->lng_xtm = 0;
	}
	TablePutToFile( &(res->code) , &(res->Tvar) );

#ifdef DBGTRC
fprintf(fdbgtrc,"\n FichierVarConstruct() - Fin\n");
#endif
}

VOID FichierProConstruct( prg, res )
Fichier XPTR * prg;
Fichier XPTR * res;
{
	InfoPro proc;
	WORD adr;

 TRACE

	FichierInitPro( prg, prg );
	if (! TableIsVide( &(prg->Tpro) ) )
	{
		/* transfert des procedures du programme */
		for (adr=0; adr < TableGetReloc( &(prg->Tpro) ) ; adr += LGPRO)
		{
			TableGetPro( &(prg->Tpro), adr, &proc );
			/* TRansfert des constantes, var, code  */
			FichierCopyPro( prg, res, &proc );

			/* mise a jour de la table des procedures globales */
			TableSeek( &(res->Tpro), adr );
			TablePutPro( &(res->Tpro), &proc );		
		}
	}

	/* transfert de la table des procedures */
	if (TableIsVide( &(res->Tpro) ) ) return;

	res->code.ent->adr_tpr = FileGetReloc( &res->code );
	res->code.ent->lng_tpr = TableGetReloc( &(res->Tpro) );
	TablePutToFile( &(res->code), &(res->Tpro) );
	
	/* transfert des noms de procedures */
}

VOID FichierSegConstruct( prg, res )
Fichier XPTR * prg;
Fichier XPTR * res;
{ 
	InfoSeg seg;
	WORD adr;

TRACE
	/* transfert des segments du programme */
	FichierInitSeg( prg, prg );
	if ( ! TableIsVide( &(prg->Tseg) ) )
	{
		for (adr=0; adr < TableGetReloc( &(prg->Tseg) ) ; adr += LGSEG)
		{
			TableGetSeg( &(prg->Tseg), adr, &seg );

			/* TRansfert des ?constantes, var, code ? */
			FichierCopySeg( prg, res, &seg );

			/* mise a jour de la table des segments globales */
			TableSeek( &(res->Tseg), adr );
			TablePutSeg( &(res->Tseg), &seg );		
		}
	}

	if ( TableIsVide( &(res->Tseg) ) ) return;

	/* Marque de fin de table */
	TableSeek( &(res->Tseg), TableGetReloc(&(res->Tseg)) );
	TablePutBin(&(res->Tseg), MOINS_UN);
			
	/* transfert de la table des segments */

	res->code.ent->adr_tsg = FileGetReloc( &res->code );
	res->code.ent->lng_tsg = TableGetReloc( &(res->Tseg));
	TablePutToFile( &(res->code), &(res->Tseg) );

}

VOID FichierNomProConstruct( prg, res )
Fichier XPTR * prg;
Fichier XPTR * res;
{ 
	C_SNODE FAR *	node;
	ModPro	XPTR *	proc_pub;
	Args 	XPTR *	val_args;
	WORD		bloc_fin;
	WORD 		i;

TRACE
	/* Construction de la table des noms de procedures */

	/* Construction en deux temps */
	/* relocation de la map des segments du programme */
	for (i=0; i < HTV; i++)
	{
		SlistRewind( res->liste_pro_pub[i] );
		node = SlistGetNext( res->liste_pro_pub[i] );
		while ( node )
		{
			proc_pub = SnodeGet( node );

			/* Si c'est une procedure du programme */
			/* reloger la map */
			
			if ( proc_pub->num_module == NUM_RES )
			{ 
				proc_pub->adr_map = FichierRelocMap( prg, res, proc_pub->adr_map );
			}

			node = SlistGetNext( res->liste_pro_pub[i] );
		}
	}

	/* Creation de la table des Noms de procedures */
	res->dbg.ent->adr_npr = FileGetReloc( &res->dbg);

	FilePutBin(&res->dbg, ListCountHashList( res->liste_pro_pub ) );


	for (i=0; i < HTV; i++)
	{
		SlistRewind( res->liste_pro_pub[i] );
		node = SlistGetNext( res->liste_pro_pub[i] );
		while ( node )
		{
			proc_pub = SnodeGet( node );

			/* Si c'est une procedure du programme */
			/* reloger la map */
			
			/* Ecriture d'un nom de procedure */
			FilePutString( &(res->dbg), proc_pub->nom);

			/* offset dans la table des procedures */		
			FilePutBin( &(res->dbg), proc_pub->used );

			/* adresse des procedures appellees */
			FilePutBin( &(res->dbg), 0);

			/* adresse de la table de correspondance */
			FilePutBin( &(res->dbg), proc_pub->adr_map );

			/* Longueur de la table de correspondance */
			FilePutBin( &(res->dbg), proc_pub->lg_map );

			/* Type de retour / arguments */
			FilePutBin( &(res->dbg), proc_pub->pub.nb_args );
			
			SlistRewind( proc_pub->pt_args );
				
			node = SlistGetNext( proc_pub->pt_args );
			while ( node )
			{
				val_args = SnodeGet( node );
				FilePutByte( &(res->dbg), val_args->typ_arg );
				node = SlistGetNext( proc_pub->pt_args );
			}
		
			node = SlistGetNext( res->liste_pro_pub[i] );
		}
	}
	
	FileEndBloc( &(res->dbg) );

	/* teste le debordement de la table */
	bloc_fin = FileGetReloc( &(res->dbg) );

	if ( bloc_fin > res->dbg.ent->adr_npr + LGMAXTABLE / LGBLOC )
	{
		/* tester le depassement de la table des noms de procedure */
		THROW(ErreurMoteur11); 
	}

}

VOID FichierNomSegConstruct( prg, res )
Fichier XPTR * prg;
Fichier XPTR * res;
{ 
	C_SNODE FAR *	node;
	ModPro	XPTR *	proc_pub;
	WORD		bloc_fin;
	WORD 		i;

TRACE
	/* Construction de la table des noms de procedures */

	/* Construction en deux temps */
	/* relocation de la map des segments du programme */

	for (i=0; i < HTV; i++)
	{
		SlistRewind( res->liste_seg_pub[i] );
		node = SlistGetNext( res->liste_seg_pub[i] );
		while ( node ) {
			proc_pub = SnodeGet( node );

			if ( proc_pub->num_module == NUM_RES )
			{ 
				proc_pub->adr_map = FichierRelocMap( prg, res, proc_pub->adr_map );
			}
			node = SlistGetNext( res->liste_seg_pub[i] );
		}
	}


	/* Creation de la table des noms de segments */

	/* Noms de procedure */
	res->dbg.ent->tnom_seg = FileGetReloc( &res->dbg);

	FilePutBin(&res->dbg, ListCountHashList( res->liste_seg_pub ) );

	for (i=0; i < HTV; i++)
	{
		SlistRewind( res->liste_seg_pub[i] );
		node = SlistGetNext( res->liste_seg_pub[i] );
		while ( node )
		{
			proc_pub = SnodeGet( node );

			/* Ecriture d'un nom de procedure */
			FilePutString( &(res->dbg), proc_pub->nom);

			/* offset dans la table des procedures */		
			FilePutBin( &(res->dbg), proc_pub->used );

			/* descriteur table */
			FilePutBin( &(res->dbg), proc_pub->num_desc );

			/* adresse des procedures appellees */
			FilePutBin( &(res->dbg), 0);

			/* adresse de la table de correspondance */
			FilePutBin( &(res->dbg), proc_pub->adr_map );

			/* Longueur de la table de correspondance */
			FilePutBin( &(res->dbg), proc_pub->lg_map );

			
			node = SlistGetNext( res->liste_seg_pub[i] );
		}
	}


	FileEndBloc( &(res->dbg) );

	/* teste le debordement de la table */
	bloc_fin = FileGetReloc( &(res->dbg) );

	if ( bloc_fin > res->dbg.ent->tnom_seg + LGMAXTABLE / LGBLOC )
	{
		/* tester le depassement de la table des noms de procedure */
			THROW(ErreurMoteur11); 
	}

}

VOID FichierSourceConstruct( res )
Fichier XPTR * res;
{ 
	C_SNODE FAR *	node;
	Name 	XPTR *	pt_name;
	WORD		bloc_fin;

TRACE
	/* Construction de la table des noms de procedures */

	/* Noms de procedure */
	res->dbg.ent->tnom_sources = FileGetReloc( &res->dbg);

	SlistRewind( res->liste_source );
	node = SlistGetNext( res->liste_source );
	while ( node )
	{
		pt_name = SnodeGet( node );

		/* offset dans la table des procedures */		
		FilePutBin( &(res->dbg), pt_name->num );

		/* Ecriture d'un nom de procedure */
		FilePutString( &(res->dbg), pt_name->nom);

		node = SlistGetNext( res->liste_source );
	}

	
	/* fin de table */		
	FilePutBin( &(res->dbg), MOINS_UN );

	FileEndBloc( &(res->dbg) );

	/* teste le debordement de la table */
	bloc_fin = FileGetReloc( &(res->dbg) );

	if ( bloc_fin > res->dbg.ent->tnom_sources + LGMAXTABLE / LGBLOC )
	{
		/* tester le depassement de la table des noms de procedure */
			THROW(ErreurMoteur11); 
	}

}

VOID FichierBdaConstruct( res )
Fichier XPTR * res;
{ 
	C_SNODE FAR *	node;
	Bibli 	XPTR *	pt_bda;
	WORD		bloc_fin;
	WORD		i;

TRACE
	/* Construction de la table des Bda */

	/* Noms de procedure */
	res->code.ent->adr_tfu = FileGetReloc( &res->code);

	FilePutBin( &(res->code), SlistCount( res->liste_bda ) );
	
	SlistRewind( res->liste_bda );
	node = SlistGetNext( res->liste_bda );
	while ( node )
	{
		pt_bda = SnodeGet( node );

		/* offset dans la table des procedures */		
		FilePutString( &(res->code), pt_bda->nom );
		FilePutBin( &(res->code), pt_bda->pgn );
		for (i=0; i < 16; i++)
		{
			FilePutByte( &(res->code), pt_bda->non_util[i] );
		}

		node = SlistGetNext( res->liste_bda );
	}

	FileEndBloc( &(res->code) );

	/* teste le debordement de la table */
	bloc_fin = FileGetReloc( &(res->code) );

	if ( bloc_fin > res->code.ent->adr_tfu + LGMAXTABLE / LGBLOC )
	{
		/* tester le depassement de la table des noms de procedure */
		THROW(ErreurMoteur11); 
	}

	res->code.ent->lng_tfu = ( 2 + ( SlistCount( res->liste_bda ) * 16 ) + 255 ) / LGBLOC;
}



/* #BG 08/10/01 Begin */

#ifndef __WALD__

WORD IsFileOpened(char * FileName)
{      
/*
	A ce stade l'extension est toujours .AT meme s'il s'agit de la traduction d'un module.
	Donc message d'erreur a tord si traduction d'un module de meme nom qu'un AT en cours d'execution.
	
	Sous Twin, Rename devra etre remplacé par un Open exclusif quand la librarie PCRTL sera utilisée a la place de P3LLIBC.
*/

#ifdef prologue 
	if (access(FileName, 0) == 0)
	{
		char	TmpFile[LGMXNOM];
		int	Lg;

		Xstrcpy(TmpFile, FileName);
		Lg = Xstrlen(TmpFile);
		TmpFile[Lg-1] = '@';
		TmpFile[Lg-2] = '@';

		if (rename(FileName, TmpFile) != 0)
		{
			return 1;
		}
		else
			rename(TmpFile, FileName);
	}

#endif

#ifdef unix
	// To be implemented
#endif

	return 0;
}

#endif

/* Implementation dans WATR.C pour Windows */

/* #BG 08/10/01 End */
