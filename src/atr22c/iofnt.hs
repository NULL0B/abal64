/*
 *      Projet  : ABAL                  Copyright Prologue s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : IOFNT.H
 *      Version : 2.1f
 *      Date    : 22/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions relatives aux instructions sur numero logique]
 *
 */
  
/*
 * Mises a jour :
 * ------------
 * 17/08/00 : (#SP) Criteria long names support.
 *
 */

#ifdef _IOFNT

/* DEFINITION LOCALE  */
/* ------------------ */

/* PRIVATE */
/* ------- */

/* PRIVATE MACRO */
/* ------------- */

/*              options de l'instruction ASSIGN                 */
/*              -------------------------------                 */

#define MA_OPT  0x00F0

#define DR_OPT  0x0000
#define SQ_OPT  0x0020
#define SI_OPT  0x0040
#define MC_OPT  0x0060
#define DB_OPT  0x0080
#define IPC_OPT 0x0070
#define IM_OPT  0x0050
#define GR_OPT  0x0030
#define DF_OPT  0x0008
#define C_OPT   0x0004
#define EX_OPT  0x0002
#define WR_OPT  0x0001

/* #SP 17/08/2000 (begin) */
#define L_OPT   0x8000
/* #SP 17/08/2000 (end) */


/* PRIVATE VARIABLES */
/* ----------------- */

/*      variables privees du module pour la construction des arguments  */
/*      --------------------------------------------------------------  */

static int nbargs;
static char *aderr,bufaderr[LGIDENT];
static BYTE targ[20];
static BINAIRE varg[20];
static BYTE options;

static BOOL flg_bufexpr;        /* expression autorisee comme buffer d'I/O */
static BOOL flg_lgexpl;         /* et on a trouve sa longueur explicite ... */


/* PRIVATE FONCTIONS */
/* ----------------- */
#ifdef LINT_ARGS

/*      Fonctions internes du module    */
/*      ----------------------------    */

static BOOL recnumlog (void);
static BOOL fininstio (int);
static BOOL recopt (BYTE *, BINAIRE *, BINAIRE, char *, BINAIRE);
static BOOL recjoin (BYTE *, BINAIRE *);
static BOOL recinterro (BYTE *, BINAIRE *);

#else
/*      Fonctions internes du module    */
/*      ----------------------------    */

static BOOL recnumlog ();
static BOOL fininstio ();
static BOOL recopt ();
static BOOL recjoin ();
static BOOL recinterro ();

#endif /* LINT_ARGS */

/* PRIVATE END */
/* ----------- */

/* DEFINITIONS EXTERNES */
/* -------------------- */

#include "trnoy.he"
#include "symboles.he"
#include "gencode.he"
#include "lexical.he"
#include "parser.he"
#include "trmess.he"
#include "expr.he"
#include "table.he"

/* FIN DEFINITION EXTERNES */
/* ----------------------- */
#endif /* _IOFNT */

/* ---------------- FIN iofnt.hs -----------------------------------------*/

