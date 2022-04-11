/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1993
 *	Module  : ALD
 *	Fichier : LKMESS.C
 *	Version : 2.2b
 *	Date    : 02/06/93
 *	Systeme : Tous
 *
 *	Gestion Fichier des acces ecrans
 *
 *	[Noyau ALD - Gestion ecran ]
 *
 */

/* Mises a jour :
 * ------------
 * 23/08/00 : (#BG) New version identification.
 * 14/11/01 : (#BG) Suppression de l'option -h sans objet sous Windows.
 *	------------ 2.2b -------------------------------------------------
 * 13/12/02 : (#BG) Nouvelle gestion de la bannière.
 */


#define _LKMES

#include "aldtype.h"
#include "lkstruct.h"
#include "lkmes.h"
#include "display.h"

/* Bannière */
#ifdef prologue
#define __Prl
#endif
#include "aldver.h"

/* ------------------------------------------------------------ From lKMess.h */

/* #include "lkmess.h" */

#ifdef ver21
	#define ver14
	#define ver13
	#define ver12
#endif

#ifdef ver21
	/* Version and indice in TCode for compatibility WEXA2.1 */ 
	#define vlk		'2'
	#define ilk		'1'
	#define Icode	'3'	/* version du T-Code */
#else
#endif 			/* ver21 */

/* ------------------------------------------------------------ */

#define Mentete "*STX*3ALD Fr  22a00"
#define Oentete "*STX*3ALD En  22a00"

#define OuiNon "ON0"
#define YesNo  "YN0"

#include "message.hg"


/* Pointeur vers messages d'extensions */
BYTE * etxmes;



char gBuffer[30];
char XPTR * GetMessageLine (int Index)
	{
	char * Result = "";

	static BOOL IsInited = FALSE;

	if (!IsInited)
		{
		/* Initialize message table */
		MesInitTab();
		IsInited = TRUE;
		}


	#ifdef __CT_DEBUG__
	if ((Index <0) || (Index >= MESSAGE_COUNT))
		{
		sprintf(gBuffer,"<Invalid message: %d>",Index);
		Result = gBuffer;
		}
	else
	#endif
		Result = messages[Index];

	if (isdigit(Result[0]))
		{
		Result++;
		}

	return Result;
	}

int GetMessageLevel (int Index)
	{
	int		Result = 0;
	char *	Message = "";

	#ifdef __CT_DEBUG__
	if ((Index <1) || (Index >= MESSAGE_COUNT))
		{
		}
	else
	#endif
		Message = messages[Index];

	if (isdigit(Message[0]))
		{
		Result = Message[0]-'0';
		}

	return Result;
	}


#ifdef HX /* unix mini */

/*********************************
* FCT MesInitTab
*
* Entree : 
*	rien
*		
* Sortie :
*	rien
*
**********************************/

VOID MesInitTab()

/*	Initialisation de la table des messages
 */

	{					/* initabmes */
	BYTE XPTR *	p;
	WORD		i;
	BOOL		other;
	static BOOL IsInited = FALSE;

	if (IsInited)
		return;
	else
		IsInited = TRUE;


	other = FALSE;


	p = &mentete[0][0];
	for (i = 0 ; i < 2 ; i++) 
		{	/* saute en-tete GESMES et O/N */
		if ( i == 1 ) 
			{
			if (*(p+2) == '1') 
				{
				other = TRUE;
				break;
				}
			}
			
		p += Xstrlen(p)+1;
		while (*p == EOSTR)
			p++;
		}

	if (other == TRUE) 
		{
		/* autre zone gesmetable */
		p = &oentete[0][0];
		for (i = 0 ; i < 2 ; i++) 	
			{	/* saute en-tete GESMES et O/N */
			p += Xstrlen(p)+1;
			while (*p == EOSTR)
				p++;
			}
		}
	for (i = 0 ; i < MESSAGE_COUNT ; i++)
		{
		messages[i] = p;
		p += Xstrlen(p) + 1;
		while (*p == EOSTR)
			p++;
		}
	etxmes = p;
	}					/* initabmes */

#else 					/* HX */

/*********************************
* FCT MesInitTab
*
* Entree : 
*	rien		
*
* Sortie :
*	rien
*
**********************************/

VOID MesInitTab()

/*	Initialisation de la table des messages
 */

{					/* initabmes */
	BYTE XPTR * p;
	WORD   i;
	BOOL	other;
	static BOOL IsInited = FALSE;

	if (IsInited)
		return;
	else
		IsInited = TRUE;

	other = FALSE;
	p = &mentete[0];
	for (i = 0 ; i < 2 ; i++) {	/* saute en-tete GESMES et O/N */
		if ( i == 1 ) {
			if (*(p+2) == '1') {
				other = TRUE;
				break;
			}
		}
		p += Xstrlen(p)+1;
		while (*p == EOSTR)
			p++;
	}
	if ( other == TRUE ) {
		p = &oentete[0];
		for (i = 0 ; i < 2 ; i++) {	/* saute en-tete GESMES et O/N */
			if ( i == 1 ) {
				if (*(p+2) == '1') {
					other = TRUE;
				}
			}
			p += Xstrlen(p)+1;
			while (*p == EOSTR)
				p++;
		}
	}

	for (i = 0 ; i < MESSAGE_COUNT ; i++) {
		messages[i] = p;
		p += Xstrlen(p) + 1;
		while (*p == EOSTR)
			p++;
	}

	etxmes = p;

}					/* initabmes */

#endif


/*********************************
* FCT MesVerifTcode 
*
* Entree : 
*	une structure d'entete
*	
* Sortie :
*	rien
*
* Remarque :
*	teste la coherence des entetes T-code
*
**********************************/

VOID MesVerifTcode(Entete XPTR * ent)
{
#ifdef VERSION_XX
	if (( ent->ver != vlk ) || ( ent->ind != ilk )) {
		THROW( ErreurMoteur01 );
		}
	else if (!( set_first_version( ent->typ ) )) {
		THROW( ErreurMoteur04 );
		}
#else
	/* #BG: Allow mixed 2.1 and 2.2
	if (ent->typ != Icode || ent->ver != vlk || ent->ind != ilk ) { */
	if (ent->typ != Icode || ent->ver != vlk || ent->ind > ilk ) {
		THROW( ErreurMoteur01 );
	}
#endif
	if (ent->exec == 1) {
		/* programme ou module avec des erreurs */
		THROW( MessageErrsynt ); 
	}
}


/*********************************
* FCT Banniere
*
* Entree : 
*	rien
*		
* Sortie :
*	affichage de la banniere du programme
*
**********************************/

VOID Banniere ()
{
#ifdef WIN32
 	/* Affiche le nom de produit */
 	waDisplayMessage(Banner_GetProductName(waBuffer));

	/* Affiche la version */
  	waDisplayMessage(Banner_GetVersionID(waBuffer, Banner_GetVersionStatus()));

	/* Affiche la mention de build */
	waDisplayMessage(Banner_GetBuild(waBuffer));

	/* Affiche la mention de copyright */
	waDisplayMessage(Banner_GetCopyright(waBuffer));

	/* Affiche l'internal name */
//	waDisplayMessage(Banner_GetInternalName(waBuffer));
//	waDisplayMessage("\n");

	/* Affiche le commentaire */
//	waDisplayMessage(Banner_GetComment(waBuffer));
//	waDisplayMessage("\n");

	/* Help */
	waDisplayMessage(GetMessageLine(MessageBanniere1));
	waDisplayMessage(GetMessageLine(MessageBanniere2));
	waDisplayMessage(GetMessageLine(MessageBanniere3));
	waDisplayMessage(GetMessageLine(MessageBanniere4));
/*	#BG 14/11/01 waDisplayMessage(GetMessageLine(MessageBanniere5));	L'option -h est sans objet en WIN32 */
	waDisplayMessage(GetMessageLine(MessageBanniere6));
	waDisplayMessage(GetMessageLine(MessageBanniere7));
	waDisplayMessage(GetMessageLine(MessageBanniere8));
	waDisplayMessage(GetMessageLine(MessageBanniere9));
	waDisplayMessage("");

#else
	BYTE buf[256];

 	/* Affiche le nom de produit */
 	printf(Banner_GetProductName(buf));

	/* Affiche la version */
	printf("\n");
  	printf(Banner_GetVersionID(buf, Banner_GetVersionStatus()));

	/* Affiche la mention de build */
	printf("\n");
	printf(Banner_GetBuild(buf));

	/* Affiche la mention de copyright */
	printf("\n");
	printf(Banner_GetCopyright(buf));

	/* Affiche l'internal name */
//	printf(Banner_GetInternalName(buf));
//	printf("\n");

	/* Affiche le commentaire */
//	printf(Banner_GetComment(buf));
//	printf("\n");

	/* Help */
	printf("\n   %s", GetMessageLine(MessageBanniere1));
	printf("\n   %s", GetMessageLine(MessageBanniere2));
	printf("\n   %s", GetMessageLine(MessageBanniere3));
	printf("\n   %s", GetMessageLine(MessageBanniere4));
	printf("\n   %s", GetMessageLine(MessageBanniere5));
	printf("\n   %s", GetMessageLine(MessageBanniere6));
	printf("\n   %s", GetMessageLine(MessageBanniere7));
	printf("\n   %s", GetMessageLine(MessageBanniere8));
	printf("\n   %s", GetMessageLine(MessageBanniere9));
	printf("\n");

#endif
}					/* banniere */

