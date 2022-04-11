/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1993
 *	Module  : T-CODE
 *	Fichier : LKTABLE.C
 *	Version : 2.2b
 *	Date    : 01/06/93
 *	Systeme : Tous
 *
 *	Gestion Fichier des acces de fichier
 *
 *	[Noyau TCode- Gestion de table]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	11/01/93 : Debut du codage
 *	01/12/93 : (BD) Correction dans TablePutCst pour les bcd 
 *	10/12/93 : (BD) Correction dans TableGetStringLg: Transformait les blancs d'une chaine cst en EOSTR
 *	23/02/94 : (BD) Correction dans TableInit et TableClose:
 *		Passage de 8 a 16 dans les boucles de buffers a initialiser ou à liberer.
 * 17/03/99 : (#BG) Ajout du test de débordement de la table des variables (max 32k = 7FFE)
 * 25/07/00 : (#OK) ALD NR. Bug fixed. Overflow description table in EXA. Add error message.
 * 14/09/00 : (#AT) Changes for extension of tables of global and local variables.
 *	------------ 2.2b -------------------------------------------------
 */

/* Inclusions importees et privees */
/* Inclusions exportees et privees */


#define _LKTABLE

#include "aldtype.h"
#include "lkstruct.h"
#include "lktable.h"
#include "lkmes.h"
#include "lkfile.h"
#include "lklist.h"
#include "lkecran.h"


#ifdef DBGTRC
	extern FILE * fdbgtrc;
#endif


/*T*******************************
*	Fonction d'acces aux Tables 
*
* 	TableInit
* 	TableClose
* 
* 	TableGetReloc
*	TableSeek
*	TableGetFromFile
*	TablePutToFile
* 
* 	TableGetString
* 	TableGetStringLg
* 	TableGetByte
* 	TableGetBin
* 	TablePutByte
* 	TablePutBin
* 	TablePutStringLg
* 	TablePutString
*
*/


/*********************************
*
* FCT TableInit
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

VOID TableInit( table )
Table XPTR * 	table;
{
	WORD i;

	table->reloc = 0;
	table->adr   = 0;
	table->index = 0;

	for (i=0; i < 16; i++ ){ /* Correction 21b */
		table->mem[i] = GenericNULL( BYTE );
	}
}
/*********************************
*
* FCT TableIsVide
*
* Entree : 
*	un pointeur sur une table
*			
* Sortie :
*	TRUE ou FALSE
*
* Remarque :
*	Informe si une table est vide 
*
* Voir aussi:
*
*
**********************************/

BOOL TableIsVide( table )
Table XPTR * 	table;
{
	if (table->mem[0] == GN( BYTE ) ) return( TRUE );

	return( FALSE );
}

/*********************************
*
* FCT TableClose
*
* Entree : 
*	un pointeur sur une table
*			
* Sortie :
*	rien
*
* Remarque :
*	liberation d'une table 
*
* Voir aussi:
*
*
**********************************/
VOID TableClose( table )
Table XPTR * table;
{
	WORD i;

	for( i=0; i < 16; i++ ){ /* Correction 2.1b */
		if (table->mem[ i ] ) {
			FREE_ALLOC( table->mem[ i ], BYTE );
			INIT_ALLOC( table->mem[ i ], BYTE );
		}
	}	

	table->reloc	= 0;
	table->adr 	= 0;
	table->index	= 0;

}

/*********************************
*
* FCT TableSeek
*
* Entree : 
*	un pointeur sur une table
*	une adresse
*			
* Sortie :
*	rien
*
* Remarque :
*	Positionnement sur une adresse d'une table
*
* Voir aussi:
* 	
*
**********************************/
VOID TableSeek(table, off)
Table XPTR * 	table;
WORD 		off;
{

	table->index	= off / LGBUF;
	table->adr	= off - (table->index * LGBUF );

}


/*********************************
*
* FCT TableGetReloc
*
* Entree : 
*	un pointeur sur une table
*			
* Sortie :
*	la prochaine adresse  libre
*
* Remarque :
*	Donne la valeur de la prochaine relocation
*
* Voir aussi:
*
*
**********************************/
WORD TableGetReloc( table )
Table XPTR * table;
{
	return( table->reloc );
}

/*********************************
*
* FCT TableGetVarReloc
*
* Entree : 
*	un pointeur sur une table
*			
* Sortie :
*	la prochaine adresse  libre
*
* Remarque :
*	Donne la valeur de la prochaine relocation de la table des variables
*	moins les 6 premiers octets reserves
* Voir aussi:
*
*
**********************************/
WORD TableGetVarReloc( table )
Table XPTR * table;
{
	if ( TableIsVide( table ) ) return( 6 );
	return( table->reloc - 6 );
}


/*********************************
*
* FCT TableGetFromFile
*
* Entree : 
*	un pointeur de fichier (Tabfic)
*	un pointeur de table (Table)
*	le bloc ou se trouve la table
*	une longeur a transferer
*			
* Sortie :
*	rien
*
* Remarque :
*	copy d'une table a partir d'un fichier dans une table memoire
*	
* Voir aussi:
* 	FileRead, TableSeek, TablePutByte
*
**********************************/
VOID TableGetFromFile( fic, tab, adr, lg )
Tabfic XPTR * 	fic;
Table XPTR *	tab;
WORD 		adr;
WORD 		lg;
{

	WORD nbbufalire;
	WORD restealire;
	WORD adressedebut; /*JPH:to avoid warning:integral sisze mismatch */

	FileSeek( fic, adr);
	for (nbbufalire=0; nbbufalire < lg / LGBUF; nbbufalire ++) {
		adressedebut = nbbufalire * LGBUF;
		TableSeek( tab, adressedebut);
		TablePutByte( tab, ' '); /* Force l'allocation du buffer */
		FileRead( fic, tab->mem[tab->index], LGBUF ); /* Lecture de bloc de 4096 */
	}

	restealire = lg - (nbbufalire * LGBUF);

	if ( restealire ) {
		adressedebut = nbbufalire * LGBUF;
		TableSeek( tab, adressedebut);
		TablePutByte( tab, ' '); /* Force l'allocation du buffer */
		FileRead( fic, tab->mem[tab->index], restealire ); /* Lecture de bloc de 4096 */
	}

	tab->reloc = lg;

}

/*********************************
*
* FCT TablePutToFile
*
* Entree : 
*	un pointeur sur une table
*			
* Sortie :
*	rien
*
* Remarque :
*	Ecriture dans un fichier d'une table memoire
*
* Voir aussi:
* 
*
**********************************/
VOID TablePutToFile( fic, tab )
Tabfic XPTR * fic;
Table  XPTR * tab;
{

	WORD nbbuf;
	WORD reste;
	WORD borne;
	WORD i;


	/* Precondition */
	if (TableIsVide( tab ) ) return;

	for (nbbuf=0; nbbuf < TableGetReloc( tab ) / LGBUF; nbbuf ++) {
		FileWrite( fic, tab->mem[ nbbuf ], LGBUF ); /* Ecriture de bloc de 4096 */
	}

	/* completer la table a 0xff */



	borne = ((TableGetReloc( tab ) + LGBLOC - 1 ) / LGBLOC ) * LGBLOC;
	
	TableSeek( tab, TableGetReloc( tab ) );
	for (i=TableGetReloc( tab ); i < borne; i++) {
		TablePutByte(tab,0xff);
	}
	reste = ( (( borne - (nbbuf * LGBUF)) + LGBLOC - 1) / LGBLOC ) * LGBLOC;

	if ( reste ) {
		FileWrite( fic, tab->mem[nbbuf], reste ); /* Ecriture de bloc de 4096 */
	}

}

/*********************************
*
* FCT TableGetString 
*
* Entree : 
*	une table
*	une chaine a mettre a jour
*		
* Sortie :
*	rien
*
* Remarque :
*	extraction d'une table une chaine de charactere se terminant par NULL
*
*
* Voir aussi :
*	TableGetByte
*
**********************************/

VOID TableGetString( table, nom)
Table XPTR * 	table;
BYTE XPTR * 	nom;
{
	do {
		*nom = TableGetByte( table );
	}
	while (*nom++);
}

/*********************************
*
* FCT TableGetStringLg
*
* Entree : 
*	une table
*	une chaine resultat a mettre a jour
*	une longeur
*	Force majuscule
*		
* Sortie :
*	rien
*
* Remarque :
*	Extraction d'une table d'une chaine de charactere d'une longueur
*	donnee
*	Un booleen permet de forcer la chaine en majuscule
*	(sert pour l'extraction du nom de module dans l'entete)
*	
* Voir aussi :
*	TableGetByte
*
**********************************/

VOID TableGetStringLg( table, nom, lg, maj )
Table XPTR * 	table;
BYTE XPTR * 	nom;
WORD 		lg;
BOOL 		maj;
{
	BYTE c;

	while (lg--) {
		c = TableGetByte(table);
		if ( maj == TRUE ) {
			if (c == ' ') *nom++ = EOSTR;
			else 	{
				if (maj == TRUE) c = toupper( c );
				*nom++ = c;
			}
		}
		else {
			*nom++ = c;
		}
	}
	*nom = EOSTR;
}

/*********************************
*
* FCT TableGetByte
*
* Entree : 
*	un fichier
*
* Sortie :
*	un octet non signe
*
* Remarque :
*	Extraction d'un octet a partir d'un fichier
*
* Voir aussi :
*	FileGetBloc
*
**********************************/

BYTE TableGetByte( table )
Table XPTR * table;
{
	BYTE b;
	WORD index;
	


	if (table->adr == LGBUF) {
		table->index ++;
		table->adr = 0;
	}

	index = table->index;

	if (table->mem[ index ] == GenericNULL( BYTE ) ) {
		ALLOC_TAMPON( table->mem[index], LGBUF );
	}

	b = *(table->mem[index] + table->adr);

	table->adr ++;

	return(b);
}

/*********************************
*
* FCT TableGetBin 
*
* Entree : 
*	une table		
* Sortie :
*	un entier non signe
*
* Remarque :
*	Extraction d'un WORD a partir d'une table
*
* Voir aussi :
*	TableGetByte
*
**********************************/

WORD TableGetBin( table )
Table XPTR * table;
{
	WORD b;

	b =  (WORD) ((TableGetByte(table)) & 0x00ff);
	b |= (WORD) (TableGetByte(table) << 8) & (WORD) 0xff00;
	
	return(b);

}

/*********************************
*
* FCT TablePutByte 
*
* Entree : 
*	une table
*	un octet non signe
*		
* Sortie :
*	rien
*
* Remarque :
*	Ecriture d'un octet non signe dans une table
*
* Voir aussi :
*	
*	
**********************************/

VOID TablePutByte( table, val )
Table XPTR * 	table;
BYTE 		val;
{
	WORD index;

	if (table->adr == LGBUF) {
		table->index ++;
		if (table->index == MAX_TABLE) 
			{
			EcranSetLastFileAccessed("{Table}");
			EcranWarningFichier("{Table}");
			THROW( ErreurNoyau02 );
			}
		table->adr = 0;
	}

	index = table->index;

	if (table->mem[ index ] == GenericNULL( BYTE ) ) {
		ALLOC_TAMPON( table->mem[ index ], LGBUF );
	}

	*( table->mem[index] + table->adr ) = val;

	table->adr ++;

	if ((table->index * LGBUF) + table->adr > table->reloc)	
		table->reloc ++;

}

/*********************************
*
* FCT TablePutBin
*
* Entree : 
*	une table
*	un entier non signe	
* Sortie :
*	rien
*
* Remarque :
*	Ecriture d'un entier non signe dans une table
*
* Voir aussi :
*	TablePutBin
*
**********************************/

VOID TablePutBin( table, val )
Table XPTR * 	table;
WORD 		val;
{
	BYTE tb;

	tb = (BYTE) SECOND_BYTE( val );
	TablePutByte(table,tb);
	tb = (BYTE) FIRST_BYTE( val );
	TablePutByte(table,tb);
}

/*********************************
*
* FCT TablePutStringLg 
*
* Entree : 
*	une table		
*	une chaine
*	une longueur
*
* Sortie :
*	rien
*
* Remarque :
*	Ecriture d'une chaine de characteres dans une table sur une longueur
*	donnee
*	(sert pour ecrire le nom du module dans l'entete)
*
* Voir aussi :
*	TablePutByte	
*
**********************************/

VOID TablePutStringLg( table, s, l)
Table XPTR * 	table;
BYTE XPTR * 	s;
WORD 		l;
{
	BYTE c;

  	while(l--) {
		c = *s ++; 
		if (c == EOSTR) c = ' ';
	
		TablePutByte(table,(BYTE) c);
	}
}

/*********************************
*
* FCT TablePutString 
*
* Entree : 
*	une table
*	une chaine a ecrire dans une table
*		
* Sortie :
*	rien
*
* Remarque :
*	Ecriture d'une chaine dans une table 
*
*
* Voir aussi :
*	TablePutByte
*
**********************************/

VOID TablePutString( table, nom)
Table XPTR * 	table;
BYTE XPTR * 	nom;
{

	while(*nom) {
		TablePutByte( table, *nom++ );
	}
	TablePutByte( table, EOSTR );
}


/************************************************************************/
/*			                    				*/
/*			Decodage des tables 				*/
/*			                    				*/
/************************************************************************/

/*********************************
* FCT TableGetCst
*
* Entree : 
* 	Table a lire
*	numero de descripteur
*	pointeur sur une structure d'information
*
* Sortie :
*	rien
*
* Remarque :
*	decode une constante dans une structure d'information
*
**********************************/
VOID TableGetCst( tab, num_desc, infcst)
Table XPTR *	tab;
WORD 		num_desc;
InfoCst XPTR *	infcst;
{
	BYTE lg;

	TableSeek( tab, num_desc);

	infcst->adrdesc = num_desc;
	lg = TableGetByte( tab );
	if ( lg ) {
		/* C'est une chaine */

		TableGetStringLg( tab, infcst->valeur, lg, FALSE);
		infcst->lgdesc	 = lg + 1;
		infcst->type	 = TSTR;
		infcst->longueur = lg;
	}
	else {
		/* C'est un BCD */

		lg = TableGetByte( tab );

		TableGetStringLg( tab, infcst->valeur, lg, FALSE );

		infcst->lgdesc	= lg + 2;
		infcst->type	= TBCD;
		infcst->longueur = lg;
	}
}

/*********************************
* FCT TableGetVar
*
* Entree : 
* 	Table a lire
*	numero de descripteur
*	pointeur sur une structure d'information
*
* Sortie :
*	rien
*
* Remarque :
*	decode une variable dans une structure d'information
*
**********************************/
VOID TableGetVar( tab, num_desc, infvar)
Table XPTR *	tab;
WORD 		num_desc;
InfoVar XPTR *	infvar;
{
/*	WORD i,d;*/
	BYTE pds;

	TableSeek( tab, num_desc );

	do {
		/* 1er octet */
		pds = TableGetByte( tab );

		infvar->type = pds & 0x03;
		infvar->dim1 = ( (pds & 0x40) ? 1 : 0 );
		infvar->dim2 = ( (pds & 0x20) ? 1 : 0 );
#ifdef domi_bug_030195
		infvar->arg  = ( (pds & 0x10) ? TRUE : FALSE );
		infvar->trou = ( (pds & 0x20) ? TRUE : FALSE );
#endif
		infvar->arg  = ( (pds & 0x04) ? TRUE : FALSE );
		infvar->trou = ( (pds & 0x10) ? TRUE : FALSE );

		infvar->descripteur = (WORD) pds;
		if (infvar->trou) num_desc++;
	}
	while ( infvar->trou == TRUE );

	infvar->adrdesc = num_desc;
	
	/* 2eme octet */
	pds = TableGetByte( tab );

	infvar->ptr = ( (pds & 0x80) ? ((infvar->tptr=((pds & 0x30)>>4)),TRUE) : (infvar->tptr=0,FALSE));
	infvar->etendue = ( ((pds & 0x40) && !infvar->ptr && !(pds & 0x3F)) ? TRUE : FALSE);
	infvar->virtuelle = ( (!infvar->ptr && (pds & 0x3F)) ? (infvar->nologique=(pds & 0x3f),TRUE) : FALSE);

	infvar->descripteur = infvar->descripteur | (pds << 8);
	infvar->lgdesc = 2;

	/* adr de redef des zones pointees : OPTION */	
	if ( infvar->tptr & 0x02 ) {
		infvar->adredefptr = TableGetBin( tab );
		infvar->lgdesc +=2;
	} else {
		infvar->adredefptr = 0;
	}

	/* adr de la variable */
	infvar->adrvar = TableGetBin( tab );
	infvar->lgdesc +=2;
	
	/* adr de variable en FIELD=E, NO : OPTION */
	if ( infvar->etendue || infvar->virtuelle ) {
		infvar->adrfield = TableGetBin( tab );	
		infvar->lgdesc +=2;

	} else {
		infvar->adrfield = 0;
	}

	/* longueur */
	if ( (infvar->ptr) && (infvar->tptr != 2) ) {
		infvar->longueur = LGSTDPTR;

		switch ( infvar->type ) {
			case TBCD:
				infvar->ptr_longueur = TableGetBin( tab );
				infvar->lgdesc +=2;
				break;
			case TSTR:
				infvar->ptr_longueur = TableGetBin( tab );
				infvar->lgdesc +=2;
				break;
			case TBIN1:
				infvar->ptr_longueur = 1;
				break;
			case TBIN2:
				infvar->ptr_longueur = 2;
				break;
			default:
				infvar->ptr_longueur = 0;
					break;
		}
	} else
	switch ( infvar->type ) {
		case TBCD:
			infvar->longueur = TableGetBin( tab );
			infvar->lgdesc +=2;
			break;
		case TSTR:
			infvar->longueur = TableGetBin( tab );
			infvar->lgdesc +=2;
			break;
		case TBIN1:
			infvar->longueur = 1;
			break;
		case TBIN2:
			infvar->longueur = 2;
			break;
		default:
			infvar->longueur = 0;
	}
	
	infvar->lgfielde = infvar->longueur;

	if ( infvar->dim1 ) {
		infvar->dim1 = TableGetBin( tab );
		infvar->lgdesc +=2;
		infvar->lgfielde = (ULONG) infvar->longueur * (ULONG) infvar->dim1;
	}

	/* 2 eme dim */
	if ( infvar->dim2 ) {
		infvar->dim2 = TableGetBin( tab );
		infvar->lgdesc +=2;
		infvar->lgfielde = (ULONG) infvar->longueur * (ULONG) infvar->dim1 * (ULONG) infvar->dim2;
	}

}

/*********************************
* FCT TableGetVarNb
*
* Entree : 
* 	Table a lire
*
* Sortie :
*	retourne le nombre de variables dans la table (WORD)
*
* Remarque :
*	retourne le nombre de vaiables dans la table
*
**********************************/
WORD TableGetVarNb( tab )
Table XPTR *	tab;
{
	if ( TableIsVide( tab ) ) return( 0 );

	TableSeek( tab, 0 );
	
	return( TableGetBin( tab ) );

}
/*********************************
* FCT TableGetVarNom
*
* Entree : 
* 	Table a lire
*
* Sortie :
*	un numero de secteur 
*
* Remarque :
*	retourne le numero de secteur ou se trouve les noms de variables
*
**********************************/
WORD TableGetVarNom( tab )
Table XPTR *	tab;
{
	if ( TableIsVide( tab ) ) return( 0 );
	TableSeek( tab, 2 );
	
	return( TableGetBin( tab ) );

}

/*********************************
* FCT TableGetVarTaille
*
* Entree : 
* 	Table a lire
*
* Sortie :
*	la taille de l'espace memoire 
*
* Remarque :
*	retourne la taille de l'espace field=m
*
**********************************/
WORD TableGetVarTaille( tab )
Table XPTR *	tab;
{
	if ( TableIsVide( tab ) ) return( 0 );

	TableSeek( tab, 4 );
	
	return( TableGetBin( tab ) );
}


/*********************************
* FCT TableGetPro
*
* Entree : 
* 	Table a lire
*	numero de descripteur
*	pointeur sur une structure d'information
*
* Sortie :
*	rien
*
* Remarque :
*	decode une procedure dans une structure d'information
*
**********************************/
VOID TableGetPro( tab, num_desc, infpro)
Table XPTR *	tab;
WORD 		num_desc;
InfoPro XPTR *	infpro;
{

	TableSeek( tab, num_desc);

	infpro->adrcode 	= TableGetBin( tab );
	infpro->lgcode  	= TableGetBin( tab );
	infpro->adrdcl  	= TableGetBin( tab );
	infpro->lgdcl	  	= TableGetBin( tab );
	infpro->adrcst  	= TableGetBin( tab );
	infpro->lgcst	  	= TableGetBin( tab );
	infpro->reserve  	= TableGetBin( tab );
	infpro->options		= TableGetBin( tab );

	infpro->differedload	= ( (infpro->options & 0x1) ? TRUE : FALSE );
	infpro->staticdcl	= ( (infpro->options & 0x2) ? TRUE : FALSE );
	infpro->noinline	= ( (infpro->options & 0x4) ? TRUE : FALSE );

	infpro->adrdesc		= num_desc;
	infpro->lgdesc		= LGPRO;
}

/*********************************
* FCT TableGetSeg
*
* Entree : 
* 	Table a lire
*	numero de descripteur
*	pointeur sur une structure d'information
*
* Sortie :
*	rien
*
* Remarque :
*	decode un segment dans une structure d'information
*
**********************************/
VOID TableGetSeg( tab, num_desc, infseg)
Table XPTR *	tab;
WORD 		num_desc;
InfoSeg XPTR *	infseg;
{

	TableSeek( tab, num_desc);

	infseg->numseg	 	= TableGetBin( tab );
	infseg->adrcode		= TableGetBin( tab );
	infseg->lgcode	 	= TableGetBin( tab );
	infseg->adrdcl	  	= TableGetBin( tab );
	infseg->lgdcl	 	= TableGetBin( tab );	
	infseg->options 	= TableGetBin( tab );
	infseg->adrcst  	= TableGetBin( tab );
	infseg->lgcst	  	= TableGetBin( tab );
	infseg->r1		= TableGetBin( tab );
	infseg->r2		= TableGetBin( tab );
	infseg->r3		= TableGetBin( tab );
	infseg->r4		= TableGetBin( tab );

	infseg->differedload	= ( (infseg->options & 0x1) ? TRUE : FALSE );
	infseg->staticdcl	= ( (infseg->options & 0x2) ? TRUE : FALSE );
	infseg->noinline	= ( (infseg->options & 0x4) ? TRUE : FALSE );

	infseg->adrdesc		= num_desc;
	infseg->lgdesc		= LGSEG;
}

/************************************************************************/
/*			                    				*/
/*			Mise a jour des tables				*/
/*			                    				*/
/************************************************************************/
/*********************************
* FCT TablePutCst
*
* Entree : 
* 	Table a mettre a jour
*	numero de descripteur
*	pointeur sur une structure d'information
*
* Sortie :
*	rien
*
* Remarque :
*	code une constante dans une table
*
**********************************/
VOID TablePutCst( tab, infcst)
Table XPTR *	tab;
InfoCst XPTR *	infcst;
{
	WORD i;

	TableSeek( tab, infcst->adrdesc );
	if ( infcst->type == TBCD ) {
		/* C'est un BCD */
		TablePutByte( tab, 0 );
	}

	TablePutByte( tab, infcst->longueur );

	/* Modif du 1/12/93 En Remplacement de la fonction PuttStringLg 
		qui transforme les 00 d'un bcd en blanc 
	*/

	for (i=0; i < infcst->longueur; i ++ ) {
		TablePutByte(tab,(BYTE) infcst->valeur[i] );
	}

}

/*********************************
* FCT TablePutVar
*
* Entree : 
* 	Table a mettre a jour
*	numero de descripteur
*	pointeur sur une structure d'information
*
* Sortie :
*	rien
*
* Remarque :
*	decode une variable dans une structure d'information
*
**********************************/
VOID TablePutVar( tab, infvar)
Table XPTR *	tab;
InfoVar XPTR *	infvar;
{
/*	WORD i,d;*/
/*	BYTE pds;*/

	TableSeek( tab, infvar->adrdesc );

	TablePutBin( tab, infvar->descripteur );

	/* adr de redef des zones pointees : OPTION */	
	if ( infvar->tptr & 0x02 ) {
		TablePutBin( tab, infvar->adredefptr);
	}

	/* adr de la variable */
	TablePutBin( tab, infvar->adrvar );
	
	/* adr de variable en FIELD=E, NO : OPTION */
	if ( infvar->etendue || infvar->virtuelle ) {
		TablePutBin( tab, infvar->adrfield );
	} 

	/* longueur */
	switch ( infvar->type ) {
		case TBCD:
		case TSTR:
			if ( infvar->ptr && infvar->tptr != 0x02 ) {
				TablePutBin( tab, infvar->ptr_longueur);
			}
			else {
				TablePutBin( tab, infvar->longueur);
			}
			break;
		default:
			break;
	}
	
	/* 1er dim */
	if ( infvar->dim1 ) {
		TablePutBin( tab, infvar->dim1);
	}

	/* 2 eme dim */
	if ( infvar->dim2 ) {
		TablePutBin( tab, infvar->dim2);
	}

	/* Test de debordement de la table des variables */

#ifdef DBGTRC
	fprintf(fdbgtrc,"\nTablePutVar() : Taille table resultat = %ld \n", ((ULONG) TableGetReloc(tab)));
#endif
/* #AT: 14/09/00 (begin)*/
	CheckReloc(tab, MAX_VAR_DESC_OFFSET, ErreurMoteur07);
/* #AT: 14/09/00 (end)*/
}

/*********************************
* FCT TablePutVarNb
*
* Entree : 
* 	Table a lire
*	le nombre de variable ( WORD )
*
* Sortie :
*	rien
*
* Remarque :
*	retourne le nombre de vaiables dans la table
*
**********************************/
VOID TablePutVarNb( tab, nb )
Table XPTR *	tab;
WORD 		nb;
{

/* #AT: 14/09/00 (begin)*/
	CheckReloc(tab, MAX_VAR_DESC_OFFSET, ErreurMoteur07);
/* #AT: 14/09/00 (end)*/

	TableSeek( tab, 0 );
	TablePutBin( tab, nb );

}

/*********************************
* FCT TablePutVarNom
*
* Entree : 
* 	Table a lire
*	un numero de secteur
* Sortie :
*	rien
*
* Remarque :
*	Mise a jour de la localisation des noms de variables
*
**********************************/
VOID TablePutVarNom( tab, adrnom )
Table XPTR *	tab;
WORD		adrnom;
{
	TableSeek( tab, 2 );
	TablePutBin( tab, adrnom );
}

/*********************************
* FCT TablePutVarTaille
*
* Entree : 
* 	Table a lire
*	taille de l'espace memoire
*
* Sortie :
*	rien
*
* Remarque :
*	Mise a jour de l'espace memoire du field=m
*
**********************************/
VOID TablePutVarTaille( tab, taille )
Table XPTR *	tab;
WORD 		taille;
{
	TableSeek( tab, 4 );
	TablePutBin( tab, taille );
}

/*********************************
* FCT TablePutPro
*
* Entree : 
* 	Table a mettre a jour
*	pointeur sur une structure d'information
*
* Sortie :
*	rien
*
* Remarque :
*	Mise a jour d'un element de la table
*
**********************************/
VOID TablePutPro( tab, infpro )
Table XPTR *	tab;
InfoPro XPTR *	infpro;
{


	TableSeek( tab, infpro->adrdesc );

	TablePutBin( tab, infpro->adrcode);
	TablePutBin( tab, infpro->lgcode);
	TablePutBin( tab, infpro->adrdcl);
	TablePutBin( tab, infpro->lgdcl);
	TablePutBin( tab, infpro->adrcst);
	TablePutBin( tab, infpro->lgcst);
	TablePutBin( tab, infpro->reserve);
	TablePutBin( tab, infpro->options);

}

/*********************************
* FCT TablePutSeg
*
* Entree : 
* 	Table a mettre a jour
*	pointeur sur une structure d'information
*
* Sortie :
*	rien
*
* Remarque :
*	Mise a jour de la table des segments 
*
**********************************/
VOID TablePutSeg( tab, infseg)
Table XPTR *	tab;
InfoSeg XPTR *	infseg;
{

	TableSeek( tab, infseg->adrdesc );

	TablePutBin( tab ,infseg->numseg);
	TablePutBin( tab ,infseg->adrcode);
	TablePutBin( tab ,infseg->lgcode);
	TablePutBin( tab ,infseg->adrdcl);
	TablePutBin( tab ,infseg->lgdcl);
	TablePutBin( tab ,infseg->options);
	TablePutBin( tab ,infseg->adrcst);
	TablePutBin( tab ,infseg->lgcst);
	TablePutBin( tab ,infseg->r1);
	TablePutBin( tab ,infseg->r2);
	TablePutBin( tab ,infseg->r3);
	TablePutBin( tab ,infseg->r4);
}

/************************************************************************/
/*			                    				*/
/*			Fusion des tables				*/
/*			                    				*/
/************************************************************************/
/*********************************
* FCT TableFusionVar
*
* Entree : 
* 	Table origine
*	Table destination
*
* Sortie :
*	rien
*
* Remarque :
*	Fusion de deux tables de variables (sans les noms de variables 
*
**********************************/
VOID TableFusionVar( tab_ori, tab_des)
Table XPTR *	tab_ori;
Table XPTR *	tab_des;
{
	WORD i;
	InfoVar pvar;
	WORD desc;
	WORD desc_reloc;
	WORD NombreVariable;
	WORD TailleEspaceMemoire;

	TableSeek( tab_ori, 6 );

	desc_reloc = TableGetReloc( tab_des );

	/* pour chaque variable on reloge l'espace de donnee */

	desc = 6;
	for (i = 0; i < TableGetVarNb( tab_ori ); i ++) {
		TableGetVar( tab_ori, desc, &pvar );
		if (pvar.etendue || pvar.virtuelle ) {
			if (pvar.etendue) {
				/* Reloge etendue */
			}
		}
		else pvar.adrvar  += TableGetVarTaille( tab_des );

		pvar.adrdesc = TableGetReloc( tab_des );
		TablePutVar( tab_des,  &pvar );
		desc += pvar.lgdesc;
	}
	
	NombreVariable =( TableGetVarNb( tab_des ) + TableGetVarNb( tab_ori ) ) ;
	TablePutVarNb( tab_des, NombreVariable );
	TailleEspaceMemoire = TableGetVarTaille( tab_des ) + TableGetVarTaille( tab_ori );
	TablePutVarTaille( tab_des, TailleEspaceMemoire );
}

VOID TableGetCstAlias( tab, cst )
Table XPTR * tab;
InfoCst XPTR * cst;
{
	InfoCst csttmp;
	WORD	lg_table;
	
	lg_table = TableGetReloc( tab );

	csttmp.adrdesc = 0;
	while ( csttmp.adrdesc < lg_table ) {
		TableGetCst( tab, csttmp.adrdesc, &csttmp );
		if (ListMatchCst( &csttmp, cst ) ) {
			cst->adrdesc = csttmp.adrdesc;
			return;
		}
		csttmp.adrdesc += csttmp.lgdesc;
	}
}

/* #AT: 14/09/00 (begin) */
/////////////////////////////////////////////////////////////////
void CheckReloc(Table * pTable,unsigned long lngMax,int iErrNumb)
{
  if (pTable->reloc > lngMax) THROW(iErrNumb);
}

#ifndef VERSION_XX
//////////////////////////////////
// For global variables in the new part of the global descriptor table ([32K..64K])
void ChangeGlobVarAdr(WORD * wAdr)
{
  if (*wAdr & 0x8000){
    *wAdr &= 0x7FFF; // Reset elder bit
    *wAdr |= 1;      // Set bit 0
  }
}
#endif
/* #AT: 14/09/00 (end) */

