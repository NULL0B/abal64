/*
 *      Projet  : ABAL                  Copyright Prologue s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : GESTFIC.H
 *      Version : 2.2b
 *      Date    : 22/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions relatives a la gestion du fichier traduit]
 *
 */

/*	------------ 2.2b -------------------------------------------------
 */

#ifdef _GESTFIC

/* DEFINITION LOCALE  */
/* ------------------ */

/* PRIVATE */
/* ------- */

/* PRIVATE MACRO */
/* ------------- */

#ifdef	VERSION_XX
#define icode4   '4'     /* Version du T-code produit */
#define icode3   '3'     /* Version du T-code produit */
static	BYTE	icode=icode3;
#else
#define icode   '3'     /* Version du T-code produit */
#endif

#define padstr ' '      /* caractere de padding pour des chaines */

/* PRIVATE VARIABLES */
/* ----------------- */

static BOOL t_prod;         /* production d'un fichier -T oui/non */
static BYTE tamloc[LGBLOC]; /* bloc courant (sauvegarde temporaire) */
			    /* variable locale a posit */
static char nametrad[LGMXNOM];  /* nom du fichier traduit */

static int struct_index;	/* numero de la structure pour les info de debug*/

/* Generation du T-code en memoire Tampon de 8 ko,
   pour backpatch des etiquettes en memoire
   recopie du T-code sur disque 
*/
#define NBBUFCODE 8
#define NBBYTEBUF 8192

static flgcode = FALSE;
static BYTE *pcode[NBBUFCODE];  /* tableau des pointeurs de buffer code */
				/* 8 * 8 = 64 Ko */
static BINAIRE ppcode;  /* buffer courant */
static BINAIRE pscode;  /* Position dans le buffer courant */

/* PRIVATE FONCTIONS */
/* ----------------- */
#ifdef LINT_ARGS

static void pnom (BINAIRE, TabSymb * );
static void pprnom (BINAIRE, BOOL, TabProc * );
static void ssrnom (BINAIRE, BOOL, TabSeg * );
static void posit ( BINAIRE,BINAIRE,BOOL,BOOL );
static void purge (BINAIRE);
static BOOL xrename (BINAIRE, char *);
static BOOL xrenold (BINAIRE, char *);
static void crypt (BINAIRE,BYTE *,BINAIRE,BOOL);

static void mbyte(BYTE);

#else

static void pnom ();
static void pprnom ();
static void ssrnom ();
static void posit ();
static void purge ();
static BOOL xrename ();
static BOOL xrenold ();
static void crypt ();

static void mbyte();

#endif /* LINT_ARGS */

/* PRIVATE END */
/* ----------- */

/* DEFINITIONS EXTERNES */
/* -------------------- */

#include "trnoy.he"
#include "lexical.he"
#include "symboles.he"
#include "parser.he"
#include "trmess.he"
/*#include ""*/

#endif /* _GESTFIC */

/* ---------------- FIN gestfic.hs -----------------------------------------*/

