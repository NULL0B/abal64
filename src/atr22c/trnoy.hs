/*
 *      Projet  : ABAL                  Copyright Prologue s.a. (c) 1990, 2000
 *      Module  : ATR
 *      Fichier : TRNOY.HS
 *      Version : 2.2b
 *      Date    : 29/11/96
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions du noyau du traducteur]
 *
 */

#ifdef _TRNOY

/* DEFINITION LOCALE  */
/* ------------------ */

/* PRIVATE */
/* ------- */

/* PRIVATE MACRO */
/* ------------- */

/* Fixe le numero de version */

/* Version banniere */

/* Version and indice in TCode for compatibility WEXA2.1 */ 
#define vtr     '2'
#define itr     '1'


/* PRIVATE VARIABLES */
/* ----------------- */

/*      Extensions par defaut des fichiers en fonction du systeme hote  */
/*      --------------------------------------------------------------  */

#ifdef prologue

#define pretty_printing

static char EXTS[4]={'S',EOSTR,' ',' ' }; /* ext. fichier source */
static char EXTL[4]={'L',EOSTR,' ',' ' }; /* ext. fichier liste */
static char EXTE[4]={'E',EOSTR,' ',' ' }; /* ext. fichier d'erreurs */

static char EXTDEF[4]={'D','E','F',EOSTR }; /* ext. fichier definition */
static char EXTT[4]={'A','T',EOSTR,' ' }; /* ext. fichier traduit */


#define MODMAP

#endif /* prologue */

#ifdef msdos

#define pretty_printing

static char EXTS[4]={'S',EOSTR,' ',' ' }; /* ext. fichier source */
static char EXTL[4]={'L','S','T',EOSTR }; /* ext. fichier liste */
static char EXTE[4]={'E','R','R',EOSTR }; /* ext. fichier d'erreurs */

static char EXTDEF[4]={'D','E','F',EOSTR }; /* ext. fichier definition */
static char EXTT[4]={'A','T',EOSTR,' ' }; /* ext. fichier traduit */


#define MODMAP

#endif /* msdos */

#ifdef unix

static char EXTS[4]={'s',EOSTR,' ',' ' }; /* ext. fichier source */
static char EXTL[4]={'l','s','t',EOSTR }; /* ext. fichier liste */
static char EXTE[4]={'e','r','r',EOSTR }; /* ext. fichier d'erreurs */

static char EXTDEF[4]={'d','e','f',EOSTR }; /* ext. fichier definition */
static char EXTT[4]={'a','t',EOSTR,' ' }; /* ext. fichier traduit */


#undef MODMAP

#endif /* unix */

#ifdef vms

static char EXTS[4]={'S',EOSTR,' ',' ' }; /* ext. fichier source */
static char EXTL[4]={'L','S','T',EOSTR }; /* ext. fichier liste */
static char EXTE[4]={'E','R','R',EOSTR }; /* ext. fichier d'erreurs */

static char EXTDEF[4]={'D','E','F',EOSTR }; /* ext. fichier definition */
static char EXTT[4]={'A','T',EOSTR,' ' }; /* ext. fichier traduit */


#undef MODMAP

#endif /* vms */



/*      Declaration des variables privees du noyau              */
/*      ------------------------------------------              */

static int flg_suplst;  /* "empilage" des suppressions de liste */
static BOOL comptage;   /* comptage des lignes de la liste */
static BOOL lstforce;   /* edition des lignes non traduites */
static BOOL verbose;    /* edition complete de l'etat de la traduction */
static int nbpause;     /* pour ne pas tester ESC a chaque pas */
static BOOL sigabort;   /* flag d'interruption */
static BOOL purgeL;     /* indication de purge */
static BOOL ALcomptage;
static char *ALligne;

/*      gestion de la "map" de mise au point    */
/*      ------------------------------------    */

static MapRef *curmap;
static long int AMcurposlst;

/*      Variables globales pour la gestion du fichier liste     */
/*      ----------------------------------------------------    */
static char namelst[LGMXNOM];           /* nom du fichier liste */


/* PRIVATE FONCTIONS */
/* ----------------- */
#ifdef LINT_ARGS

int asyncab(int);
char *forceext();

static BOOL init_trad( int , char ** );
static BOOL EndCurOpt(char *);
static BINAIRE OptCopie(char *,char *);
static void init_ecran(BOOL);
static void remet_ecran(void);
static int getnum (void);

#ifdef vms
extern int   getnomfic( char * , char * , char * );
#else /* ! vms */
static char *getnomfic( char * , char * , char * );
#endif /* vms */

static int fin ( void );
static void insinclude(char *);
int IsFileOpened(char * FileName);

#else

int asyncab();
char *forceext();

static BOOL init_trad();
static BOOL EndCurOpt();
static BINAIRE OptCopie();
static void init_ecran();
static void remet_ecran();
static int getnum ();

#ifdef vms
extern int   getnomfic();
#else /* ! vms */
static char *getnomfic();
#endif /* vms */

static int fin ();
static void insinclude();
int IsFileOpened();

#endif /* LINT_ARGS */

/* PRIVATE END */
/* ----------- */

/* DEFINITIONS EXTERNES */
/* -------------------- */

#include "lexical.he"
#include "symboles.he"
#include "parser.he"
#include "trmess.he"
#include "gestfic.he"
#include "debug.he"
#include "debugzon.h"

#include "cico.h"
#include "systeme.h"

/* FIN DEFINITION EXTERNES */
/* ----------------------- */
#endif /* _TRNOY */

/* ---------------- FIN trnoy.hs -----------------------------------------*/

