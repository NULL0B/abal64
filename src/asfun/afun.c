/*
 *	Bibliotheque Dynamique Multi-Fenetrage
 *	--------------------------------------
 *
 *	Copyright (c) 2021 Amenesik / Sologic
 *
 *	afun.c - fonctions entete
 *
 *	$Header: /home/Produits/Abal3/asfun/afun.c,v 1.2 2006/05/18 16:00:12 jamie Exp $
 *
 ***************************************************
 *	MAJ llb		18.12.90
 *	    cr		18.03.91
 *	    llb		04.07.91	fenetres simples 
 */

#define		NB_WFONC	13	/* nbre fonctions ASFUN */


/*
 *	Definitions evolutives
 *	----------------------
 */

#ifndef MENTION_PROVISOIRE
#if M_I8086 || M_I186 || M_I286 || __TURBOC__
#define MENTION_PROVISOIRE	"   PROVISOIRE ("__DATE__" "__TIME__")"
#else
#define MENTION_PROVISOIRE	"   PROVISOIRE"
#endif /* M_I8086 || M_I186 || M_I286 || __TURBOC__ */
#endif /* MENTION_PROVISOIRE */

#ifdef OLDBDA
#define VERSION 		"  Version 1.0b"
#else
#define VERSION 		"  Version 1.1a"
#endif /*OLDBDA*/
#define COPYRIGHT		"   Copyright (c) 2021 Amenesik / Sologic "


/*
 *	Inclusions
 *	----------
 */

#include "fundef.h"
#include "bda.h"

#if MSDOS || PRL
#include <conio.h>
#else
#include <stdio.h>
#endif


/*
 *	Fonctions externes
 *	------------------
 */

#if PRL
extern void far Run_Co(WORD);
extern WORD far Run_Info(WORD);
extern void far Run_Mes(BYTE far *,WORD);
extern void far Run_Str(BYTE far *);
#else
extern void initerm();		/* initialisation CICO		*/
extern void finterm();		/* terminaison CICO		*/
extern WORD x_getch();
extern WORD x_kbhit();
extern WORD prfo();
extern WORD lcfo();
extern WORD Run_Conf();
extern WORD Run_Co();
extern WORD Run_Lin();
extern WORD Run_Col();
extern void Run_Mes();
extern void _co_start();
extern void _co_flush();
extern void _lo();
#endif /* PRL */


/*
 *	Variables externes
 *	------------------
 */

#if !PRL

extern WORD prndest;

#endif /* !PRL */


/*
 *	Variables utilisees
 *	-------------------
 */

BDA Descripteur;		/* descripteur de bibliotheque	*/
extern BDA_INIT FAR * rt_init;

#if PRL

int _mem_res = 1;		/* chargement resident		*/
int _stkmin = 4096;		/* minimum reserve a la pile	*/
int _stklen = 40280;		/* taille pile + tas		*/

#endif /* PRL */


#if MSDOS || PRL		/* table des messages		*/
static char *message[] = {
	"*STX*2ASFUN   11b00",
#else
static char message[][42] = {
	"*STX*3ASFUN   11b00\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
#endif /* MSDOS || PRL */
	"   Gestionnaire multifenetres et Services",
	"                                         ",
	"*ETX*",
};

static char *provisoire = MENTION_PROVISOIRE;
static char *version = VERSION;
static char *copyright = COPYRIGHT;


/*
 *	Declarations des fonctions
 *	--------------------------
 */

static void FAR Banniere();
static void FAR FinRelais();
static void AfficheChaine();
static void NouvelleLigne();
static char *ChercheMessage();


/*
 *	Fonctions entetes pour Unix ou VMS
 *	----------------------------------
 */

#if unix || M_XENIX || vms

WORD _winit(a)
void *a[];
{
	WORD m = 0x0100;
	int o = *(BYTE *)&m;
	return (winit(*((BYTE *)a[0] + o), *((BYTE *)a[1] + o), *((BYTE *)a[2] + o), *((BYTE *)a[3] + o), *((BYTE *)a[4] + o)));
}

WORD _wcreat(a)
void *a[];
{
	return (wcreat((WORD *)a[0], (BYTE *)a[1]));
}

WORD _wsup(a)
void *a[];
{
	return (wsup(*(WORD *)a[0]));
}

WORD _wwrite(a)
void *a[];
{
	return (wwrite(*(WORD *)a[0], *(WORD *)a[1], (BYTE *)a[2]));
}

WORD _wselect(a)
void *a[];
{
	return (wselect(*(WORD *)a[0]));
}

WORD _winv(a)
void *a[];
{
	return (winv(*(WORD *)a[0]));
}

WORD _wvis(a)
void *a[];
{
	return (wvis(*(WORD *)a[0]));
}

WORD _wfgen(a)
void *a[];
{
	return (wfgen(*(WORD *)a[0], *(WORD *)a[1]));
}

WORD _watb(a)
void *a[];
{
	WORD m = 0x0100;
	int o = *(BYTE *)&m;
	return (watb(*(WORD *)a[0], *((BYTE *)a[1] + o), *((BYTE *)a[2] + o), *((BYTE *)a[3] + o)));
}

WORD _wposcur(a)
void *a[];
{
	return (wposcur(*(WORD *)a[0], *(WORD *)a[1], *(WORD *)a[2]));
}

WORD _wimpl(a)
void *a[];
{
	return (wimpl(*(WORD *)a[0]));
}

WORD _wgel(a)
void *a[];
{
	return (wgel(*(WORD *)a[0]));
}

WORD _wfend(a)
void *a[];
{
	return (wend());
}

WORD _wsetatb(a)
void *a[];
{
	WORD m = 0x0100;
	int o = *(BYTE *)&m;
	return (wsetatb(*(WORD *)a[0], *((BYTE *)a[1] + o), *((BYTE *)a[2] + o), *((BYTE *)a[3] + o), *(WORD *)a[4], *(WORD *)a[5], *(WORD *)a[6], *(WORD *)a[7]));
}

WORD _wgetimpl(a)
void *a[];
{
	return (wgetimpl((WORD *)a[0]));
}


WORD _x_getch()
{
	return (x_getch());
}

WORD _x_kbhit()
{
	return (x_kbhit());
}

WORD _prfo(a)
void *a[];
{
	return (prfo(*(WORD *)a[0], (BYTE *)a[1], *(WORD *)a[2]));
}

WORD _lcfo(a)
void *a[];
{
	return (lcfo(*(WORD *)a[0], (BYTE *)a[1], *(WORD *)a[2]));
}

WORD _Run_Conf(a)
void *a[];
{
	return (Run_Conf(*(WORD *)a[0]));
}

void _Run_Co(a)
void *a[];
{
	Run_Co(*(WORD *)a[0]);
}

void _Run_Mes(a)
void *a[];
{
	Run_Mes((BYTE *)a[0], *(WORD *)a[1]);
}

void __lo(a)
void *a[];
{
	_lo(*(WORD *)a[0]);
}

#endif /* unix || M_XENIX || vms */


/* InitRelais - initialisation bibliotheque
 * ----------------------------------------
 *
 * appel:	void FAR *InitRelais(origine);
 *		char origine = origine de l'appel
 *			       0 = appel par InitRunTime()
 *			       1 = appel depuis l'interpreteur de commandes
 *
 * retour:	pointeur sur le descripteur de bibliotheque
 *
 */
void FAR *InitRelais(origine)
char origine;
{
#if !PRL
	if (origine == 0) {
		initerm();
		prndest = 1;
	}
#endif /* !PRL */

	Descripteur.banniere = (void (FAR *)())Banniere;
	Descripteur.fin = (origine == 0) ? (void (FAR *)())FinRelais : (void (FAR *)())0;


	Descripteur.nombre = NB_WFONC+12;

#if unix || M_XENIX || vms

	Descripteur.fonction[0] = (WORD (FAR *)())_winit;
	Descripteur.fonction[1] = (WORD (FAR *)())_wcreat;
	Descripteur.fonction[2] = (WORD (FAR *)())_wsup;
	Descripteur.fonction[3] = (WORD (FAR *)())_wwrite;
	Descripteur.fonction[4] = (WORD (FAR *)())_wselect;
	Descripteur.fonction[5] = (WORD (FAR *)())_winv;
	Descripteur.fonction[6] = (WORD (FAR *)())_wvis;
	Descripteur.fonction[7] = (WORD (FAR *)())_wfgen;
	Descripteur.fonction[8] = (WORD (FAR *)())_watb;
	Descripteur.fonction[9] = (WORD (FAR *)())_wposcur;
	Descripteur.fonction[10] = (WORD (FAR *)())_wimpl;
	Descripteur.fonction[11] = (WORD (FAR *)())_wgel;
	Descripteur.fonction[12] = (WORD (FAR *)())_wfend;
	Descripteur.fonction[13] = (WORD (FAR *)())_wsetatb;

	Descripteur.fonction[NB_WFONC+1] = (WORD (FAR *)())_x_getch;
	Descripteur.fonction[NB_WFONC+2] = (WORD (FAR *)())_x_kbhit;
	Descripteur.fonction[NB_WFONC+3] = (WORD (FAR *)())_prfo;
	Descripteur.fonction[NB_WFONC+4] = (WORD (FAR *)())_lcfo;
	Descripteur.fonction[NB_WFONC+5] = (WORD (FAR *)())_Run_Conf;
	Descripteur.fonction[NB_WFONC+6] = (WORD (FAR *)())_Run_Co;
	Descripteur.fonction[NB_WFONC+7] = (WORD (FAR *)())_Run_Str;
	Descripteur.fonction[NB_WFONC+8] = (WORD (FAR *)())Run_Lin;
	Descripteur.fonction[NB_WFONC+9] = (WORD (FAR *)())Run_Col;
	Descripteur.fonction[NB_WFONC+10] = (WORD (FAR *)())_co_start;
	Descripteur.fonction[NB_WFONC+11] = (WORD (FAR *)())_co_flush;
	Descripteur.fonction[NB_WFONC+12] = (WORD (FAR *)())__lo;

#else
	Descripteur.fonction[0] = (WORD (FAR *)())winit;
	Descripteur.fonction[1] = (WORD (FAR *)())wcreat;
	Descripteur.fonction[2] = (WORD (FAR *)())wsup;
	Descripteur.fonction[3] = (WORD (FAR *)())wwrite;
	Descripteur.fonction[4] = (WORD (FAR *)())wselect;
	Descripteur.fonction[5] = (WORD (FAR *)())winv;
	Descripteur.fonction[6] = (WORD (FAR *)())wvis;
	Descripteur.fonction[7] = (WORD (FAR *)())wfgen;
	Descripteur.fonction[8] = (WORD (FAR *)())watb;
	Descripteur.fonction[9] = (WORD (FAR *)())wposcur;
	Descripteur.fonction[10] = (WORD (FAR *)())wimpl;
	Descripteur.fonction[11] = (WORD (FAR *)())wgel;
	Descripteur.fonction[12] = (WORD (FAR *)())wend;
	Descripteur.fonction[13] = (WORD (FAR *)())wsetatb;

#if !PRL
	Descripteur.fonction[NB_WFONC+1] = (WORD (FAR *)())x_getch;
	Descripteur.fonction[NB_WFONC+2] = (WORD (FAR *)())x_kbhit;
	Descripteur.fonction[NB_WFONC+3] = (WORD (FAR *)())prfo;
	Descripteur.fonction[NB_WFONC+4] = (WORD (FAR *)())lcfo;
	Descripteur.fonction[NB_WFONC+5] = (WORD (FAR *)())Run_Conf;
	Descripteur.fonction[NB_WFONC+6] = (WORD (FAR *)())Run_Co;
	Descripteur.fonction[NB_WFONC+7] = (WORD (FAR *)())Run_Str;
	Descripteur.fonction[NB_WFONC+8] = (WORD (FAR *)())Run_Lin;
	Descripteur.fonction[NB_WFONC+9] = (WORD (FAR *)())Run_Col;
	Descripteur.fonction[NB_WFONC+10] = (WORD (FAR *)())_co_start;
	Descripteur.fonction[NB_WFONC+11] = (WORD (FAR *)())_co_flush;
	Descripteur.fonction[NB_WFONC+12] = (WORD (FAR *)())_lo;
#endif /* !PRL */
#endif /* unix || M_XENIX || vms */

#ifndef OLDBDA
	if (origine == 0) {
		rt_init->cico.signature = BDA_ASFUN;
#if PRL
		rt_init->cico.Relay_Co = (void far *)Run_Co;
		rt_init->cico.Relay_Info = (void far *)Run_Info;
		rt_init->cico.Relay_Mes = (void far *)Run_Str;
		rt_init->cico.capacite = 0x0007;
#else
		rt_init->cico.fonction[CICO_CI]     = NB_WFONC+1;
		rt_init->cico.fonction[CICO_TPCI]   = NB_WFONC+2;
		rt_init->cico.fonction[CICO_PRFO]   = NB_WFONC+3;
		rt_init->cico.fonction[CICO_LCFO]   = NB_WFONC+4;
		rt_init->cico.fonction[CICO_CONF]   = NB_WFONC+5;
		rt_init->cico.fonction[CICO_CO]     = NB_WFONC+6;
		rt_init->cico.fonction[CICO_MES]    = NB_WFONC+7;
		rt_init->cico.fonction[CICO_LIGNE]  = NB_WFONC+8;
		rt_init->cico.fonction[CICO_COLONNE]= NB_WFONC+9;
		rt_init->cico.fonction[CICO_START]  = NB_WFONC+10;
		rt_init->cico.fonction[CICO_FLUSH]  = NB_WFONC+11;
		rt_init->cico.fonction[CICO_LO]     = NB_WFONC+12;
#endif /* PRL */
	}
#endif /* OLDBDA */

	return((void FAR *)&Descripteur);
}


/* FinRelais - terminaison de la bibliotheque
 * ------------------------------------------
 *
 * appel:	static void FinRelais(void);
 *
 * retour:	rien
 *
 */
static void FAR FinRelais()
{
	wend();
#if !PRL
	finterm(0);
#endif /* !PRL */
}


/* banniere - banniere de la bibliotheque
 * --------------------------------------
 *
 * appel:	static void banniere(void);
 *
 * retour:	rien
 *
 */
static void FAR Banniere()
{
	NouvelleLigne();
	AfficheChaine(ChercheMessage(1));
	AfficheChaine(version);
#if PRL3
	AfficheChaine("-P3");
#endif
	NouvelleLigne();
#if PROVISOIRE
	AfficheChaine(provisoire);
	NouvelleLigne();
#endif
	AfficheChaine(copyright);
	NouvelleLigne();
}


/* AfficheChaine - affichage d'une chaine sur l'ecran
 * --------------------------------------------------
 *
 * appel:	static void AfficheChaine(chaine);
 *		char chaine = chaine a afficher
 *
 * retour:	rien
 *
 */
static void AfficheChaine(chaine)
char *chaine;
{
#if MSDOS || PRL
	cputs(chaine);
#else
	fputs(chaine, stdout);
#endif
}


/* NouvellLigne - passage a la ligne suivante sur l'ecran
 * ------------------------------------------------------
 *
 * appel:	static void NouvelleLigne(void);
 *
 * retour:	rien
 *
 */
static void NouvelleLigne()
{
#if MSDOS || PRL
	cputs("\r\n");
#else
	putchar('\n');
#endif
}


/* ChercheMessage - recherche d'un message dans la table
 * -----------------------------------------------------
 *
 * appel:	static void ChercheMessage(numero);
 *		int numero = numero de message
 *
 * retour:	pointeur sur le message
 *
 */
static char *ChercheMessage(numero)
int numero;
{
	char *p;

	p = message[0];
	while (numero) {
		while (*p++);
		while (!*p++);
		numero--;
	}
	return (--p);
}

/* fin de fichier */

