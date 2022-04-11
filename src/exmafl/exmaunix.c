/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1995
 *	Module  : EXA
 *	Fichier : EXMAUNIX.C
 *	Version : 1.1b
 *	Date    : 18/10/95
 *	Systeme : MS-DOS
 *
 *	Executeur ABAL
 *
 *	[Interface methodes d'acces - Code specifique]
 *
 */

/* Fonctions implementees sous forme de macros */

#define cmemset	memset
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

/* --------------------------------------------------------------------------
 *
 * FCT cmemmove
 *
 *	Copie memoire a memoire avec gestion des recouvrements.
 *
 *	E/ pointeur sur la zone de reception
 *	   pointeur sur la zone de depart
 *	   nombre d'octets a copier
 *	S/ rien
 *
 */
static void cmemmove(arriv, source, ln)
BPTR arriv;
BPTR source;
WORD ln;
{ WORD i;

	if (arriv < source) {
		for (i = 0 ; i < ln ; i++) {
			*(arriv+i) = *(source+i);
		}
	}
	else {
		for (i = ln ; i != 0 ; i--) {
			*(arriv+i-1) = *(source+i-1);
		}
	}
}


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		INITIALISATION / FIN DES METHODES D'ACCES		     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT si_conversion
 *
 *	Recuperation du type de conversion des noms de fichiers.
 *
 *	E/ rien
 *	S/ WORD value
 *
 * Notes :
 *	permet de recuperer la valeur du flag criteria.cfg
 *
 *		0	:	inconnu
 *		1	:	lowercase name and extension ( default )
 *		2	:	uppercase name and extension 
 *
 */

WORD	si_mc_bd_name_conversion=0;

WORD	NOTFASTCALL	si_conversion()
{
	return( si_mc_bd_name_conversion );
}

/* --------------------------------------------------------------------------
 *
 * FCT si_init
 *
 *	Initialisation des methodes d'acces.
 *
 *	E/ rien
 *	S/ compte-rendu : 0 si Ok
 *
 * Notes :
 *	Cette fonction est appelee tres tot au demarrage d'une execution
 *	et se charge d'initialiser les methodes d'acces : 
 *	Elle effectue en outre toutes les initialisations necessaires
 *	au niveau du systeme.
 *
 */

WORD NOTFASTCALL si_init()
{ int i;
  char confdll[CONF_SIZE];
  WORD e = 0;
  	
	/* A priori, echec */
	/* --------------- */
	AD_cnx    = (EHANDLE)0xFFFFFFFFL;
	MA_cnx    = (HCRIT)0xFFFFFFFFL;

	/* Effectue l'initialisation des methodes d'acces et	*/
	/* le controle de leur indice de compatibilite.		*/
	/* --------------------------------------------------	*/

	si_mc_bd_name_conversion=0;

	for (i = CRIT_fill ; i < CONF_SIZE ; i++) { *(confdll+i) = (char)0; }

	/* this is necessary to indicate to criteria that we can handle long names */
	/* ----------------------------------------------------------------------- */
#ifdef	VERSION666
	confdll[20]=1;
#else
	confdll[20]=1;
#endif

	e = (WORD)IsamBegin((CRTCONF FAR *)confdll, (FARPROC)NULL);
      
	if (e != 0)				{ ERR(e); }

	(void) cmemmove((BPTR)&MA_cnx,(BPTR)confdll+CRIT_cnx,4);

#ifdef	UNIX
	switch ((i = confdll[CRIT_compatible])) {
		case	5	:
		case	4	:
		case	3	:
		case	2	:
		case	1	:
		case	0	: break;
		default		: ERR(58);
		}
#else
	if ((i = confdll[CRIT_compatible]) != 4) { ERR(58);  }
#endif

	si_mc_bd_name_conversion=confdll[22];

	/* Initialise Criteria */
	/* ------------------- */
	for (i = FL_fill ; i < CONF_SIZE ; i++) { *(confdll+i) = (char)0; }

	e = (WORD)FFbegin((FLCONF FAR *)confdll, (FARPROC)NULL);

	if (e != 0) { ERR(e);  }

	(void) cmemmove((BPTR)&AD_cnx,(BPTR)confdll+FL_cnx,4);

#ifdef	UNIX
	switch ((i = confdll[FL_compatible])) {
		case	4	:
		case	3	:
		case	2	:
		case	1	:
		case	0	: break;
		default		: ERR(58);
		}
#else
	if ((i = confdll[FL_compatible]) != 4)	{ ERR(58);  }
#endif

	return(0);

	/* En cas d'erreur, tout remettre en etat */
	/* -------------------------------------- */
err:	si_fin();
	return(e);
}

WORD NOTFASTCALL MA_init()
{
	return( si_init() );
}

WORD	MA_GetConvFlag()
{
	return( si_conversion() );
}

WORD	MA_SetCurrentService(BPTR service)
{
	return(0);
}

/* --------------------------------------------------------------------------
 *
 * FCT si_fin
 *
 *	Terminaison des methodes d'acces.
 *
 *	E/ rien
 *	S/ rien
 *
 * Notes :
 *	Cette fonction est appelee tardivement a la fin d'une execution
 *	et se charge de terminer la gestion des fichiers : fermetures
 *	eventuelles et dechargement des DLL.
 *
 */
void NOTFASTCALL si_fin()
{
	/* Deconnecter, decharger les DLL et liberer les tables */
	if (MA_cnx != (HCRIT)0xFFFFFFFFL)	(void) IsamEnd(MA_cnx);
	if (AD_cnx != (EHANDLE)0xFFFFFFFFL)	(void) FFend(AD_cnx);
}

void NOTFASTCALL MA_fin()
{
	si_fin();
}


/* --------------------------------------------------------------------------
 *
 * FCT sf_init
 *
 *	Initialisation de la table des codes fonction SF de Amenesik / Sologic
 *
 *	E/ rien
 *	S/ rien
 *
 */
void sf_init()
{
	simcode[0] = (BYTE) 0x32;
	simcode[1] = (BYTE) 0x22;
	simcode[2] = (BYTE) 0x2E;
	simcode[3] = (BYTE) 0x36;
	simcode[4] = (BYTE) 0x26;
	simcode[5] = (BYTE) 0x60;
	simcode[6] = (BYTE) 0xA0;
	simcode[7] = (BYTE) 0xA2;
	simcode[8] = (BYTE) 0xA6;
	simcode[9] = (BYTE) 0x2A;
	simcode[10] = (BYTE) 0x62;
	simcode[11] = (BYTE) 0x6A;
	simcode[12] = (BYTE) 0x72;
	simcode[13] = (BYTE) 0x1E;
}

