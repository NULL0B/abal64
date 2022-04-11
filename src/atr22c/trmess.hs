/*
 *      Projet  : ABAL                  Copyright Prologue s.a. (c) 1990, 1996
 *      Module  : ATR
 *      Fichier : TRMESS.HS
 *      Version : 2.1f
 *      Date    : 09/10/96
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions de la gestion des messages]
 *
 */

#ifdef _TRMESS

/* DEFINITION LOCALE  */
/* ------------------ */

#include "messages.h"

/* PRIVATE */
/* ------- */

/* PRIVATE MACRO */
/* ------------- */
/*      Messages non traduisibles !!    */
/*      ----------------------------    */

#define LGBROMESS 100 

/* PRIVATE VARIABLES */
/* ----------------- */

/*      Variables privees               */
/*      -----------------               */

static BOOL verbose;            /* affichage complet de messages */
static BOOL bourrage;           /* indicateur de reentree */
static BOOL errfat = FALSE;     /* indicateur d'erreur fatale */
#ifdef WIN32
static clHandle requestHandle;	/* handle de protection pour June */
#endif

/* PRIVATE FONCTIONS */
/* ----------------- */
#ifdef LINT_ARGS

static void cadre(BINAIRE,BINAIRE,BINAIRE,BINAIRE);
static void ivon(void);
static void ivoff(void);

#else

static void cadre();
static void ivon();
static void ivoff();

#endif /* LINT_ARGS */

/* PRIVATE END */
/* ----------- */

/* DEFINITION EXTERNES */
/* ------------------- */

#include "trnoy.he"
#include "lexical.he"
#include "gestfic.he"
#include "symboles.he"
#include "parser.he"
#include "atrdebug.he"
#include "cico.h"

/* FIN DEFINITION EXTERNES */
/* ----------------------- */
#endif /* _TRMESS */

/* ---------------- FIN trmess.hs -----------------------------------------*/

