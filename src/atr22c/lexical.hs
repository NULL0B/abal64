/*
 *      Projet  : ABAL                  Copyright Prologue s.a. (c) 1990, 1996
 *      Module  : ATR
 *      Fichier : LEXICAL.HS
 *      Version : 2.2b
 *      Date    : 15/01/96
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions de l'analyseur lexical]
 *
 * --------------------------------------------------------------------------
 * 27/10/92 : Debut revision 1.5
 *           Insertion des nouveaux mots cles :
 *           ALIAS (fct), ANY (syn), AS (syn), ASKATB (ins), ASKCOLOR (ins)
 *           CREATE (ins), FORGET (ins), FORWARD (syn), IN (syn), INITGLOBAL (mac)
 *           INITLOCAL (mac), LANG (fct), LIKE (syn), NAME (ins), PARSE (fct)
 *           POWER (fct), CODE (syn), PTR (syn), REAL (fct), REMOVE (ins)
 *           STDFORM (fct)
 *
 * 06/09/93 : LOCAL pour ON LOCAL ERROR
 * 15/10/93 : "BACKSPAC" -----> "BACKSPACE" ( 16 caracteres max maintenant !!!)
 *	17/02/97 : Debut revision 2.2
 *									Nouveaux mots cles : ENDSTRUCT, STRUCT
 *	01/04/97 : Nouveaux mots cles : ENDWITH, WITH
 *	22/03/98 : Paramètre ! dans la définition des BDA, liste des motes clés plus claire
 * -------------------------------------------------------------------------
 *	22/11/99 : (#AT:) Enhancement ATR: BINARY function.
 *	------------ 2.2b -------------------------------------------------
 */

#ifdef _LEXICAL

/* DEFINITIONS EXTERNES */
/* -------------------- */

/* MODULE */
/* ------ */

#include "trnoy.he"
#include "symboles.he"
#include "parser.he"
#include "trmess.he"
#include "debugzon.h"
#include "cico.h"
#include "systeme.h"
#include "date.he"

/* FIN DEFINITION EXTERNES */
/* ----------------------- */

/* DEFINITION LOCALE  */
/* ------------------ */

/* PRIVATE */
/* ------- */

/* PRIVATE MACRO */
/* ------------- */

#ifdef	VERSION_XX
#define isblanc(c) ((c == ' ') || (c == '\t') || (c == '\r'))
#else
#define isblanc(c) ((c == ' ') || (c == '\t'))
#endif
#define isdebidt(c) (isalpha(c) || (c == '_'))

#define remettre() { lptr--; clncur--; }
#define nremettre(n) { lptr-=n; clncur-=n; }

/* PRIVATE VARIABLES */
/* ----------------- */
static long int pinput[MAXINCL];/* pile des positions dans les fichiers */

static BOOL verrue_usrfic=FALSE; /* traitement des #USER sans fichier */

static long  curlgn[MAXINCL];    /* ligne courante sur fichiers inclus */
static char *incfic[MAXINCL];   /* noms des fichiers inclus */
static BINAIRE incsrc[MAXINCL];   /* numero des sources inclus */
static short nivcond;           /* trad. cond. en cours, et son niveau */
static short nbemb;             /* nb trad. cond. by-passe sur clause fausse */

static int  nivincl;            /* niveau courant d'inclusion des sources */

static BOOL DBLN;               /* indicateur debut ligne logique */
static BOOL NDBLN;              /* indicateur debut ligne physique */

static BOOL forceupr;           /* lecture du source en majuscules */

static char nom[LGIDENT];      /* buffer pour memoriser les ident */
static char shortName[LGIDENT];	/* buffer pour memoriser les ident avec gestion des noms longs */
	    bufstr[LGCSTR];     /* buffer pour les constantes chaines */

static BYTE bufbcd[LGBCD+1];    /* buffer pour les constantes BCD */

static short lglignemax;        /* Longueur max du buffer ligne de traduction */

static BYTE verrue_activekey;   /* Sauvegarde du keyword inhibe */
static BINAIRE kbdflush=0;      /* Flush de l'executeur */

/* #AT: 22/11/99 (begin)*/
#ifdef __ATR22__
extern BINAIRE gwSign;
#endif
/* #AT: 22/11/99 (end)*/

/*      Table des mots reserves : ATTENTION, il faut respecter l'ordre
 *                               alphabetique et rester en phase avec
 *                               la definition du type Code_Synt dans SYNTAXE.H
 */
#define First_KEY ABORT
//#ifdef _CRIEXT_
#define Last_KEY  XCRI
//#else
//#define Last_KEY  WRITE
//#endif
#define Max_KEY   ENDUSER		/* Voir syntaxe.h */
static BOOL ActKeyWords[Max_KEY+1];

static char KeyWords [] [LGIDENT] = {
	"ABORT",
	"ABS",
	"ALIAS",
	"ALTER",
	"AND",
	"ANY",
	"ARC",
	"ARG",
	"AS",
	"ASK",
	"ASKATB",
	"ASKCOLOR",
	"ASSIGN",
	"ATB",
	"ATN",
	"ATTACH",
	"BACKSPACE",
	"BELL",
/* #AT: 22/11/99 (begin)*/
#ifdef __ATR22__
	"BINARY",
#endif
/* #AT: 22/11/99 (end)*/
	"BOX",
	"BREAK",
	"CALL",
	"CASE",
	"CFILE",
	"CHAIN",
	"CHR",
	"CIRCLE",
	"CJOIN",
	"CKEY",
	"CLEAR",
	"CLINK",
	"CLOSE",
	"CODE",
	"COL",
	"CONF",
	"CONST",
	"CONV",
	"COS",
	"COUNT",
	"CREATE",
	"CURDIR",
	"CURVOL",
	"DATA",
	"DATE",
	"DCL",
	"DEC",
	"DEFAULT",
	"DEFPAINT",
	"DELETE",
	"DETACH",
	"DFILE",
	"DISPLAY",
	"DJOIN",
	"DO",
	"DOWN",
	"ELSE",
	"END",
	"ENDIF",
	"ENDLOC",
	"ENDPROC",
	"ENDSEL",
	"ENDSTRUCT",
	"ENDWITH",
	"ENV",
	"ERRADR",
	"ERROR",
	"ESEG",
	"EVENT",
	"EVENTADR",
	"EVENTDONE",
	"EXIT",
	"EXP",
	"EXTEND",
	"EXTERN",
	"FIELD",
	"FILE",
	"FILLER",
	"FIND",
	"FIX",
	"FKEY",
	"FM",
	"FMT",
	"FOR",
	"FORGET",
	"FORWARD",
	"FP",
	"FREEFONT",
	"GENER",
	"GOSUB",
	"GOTO",
	"GRCONF",
	"HASH",
	"HEX",
	"HOME",
	"HOTKEY",
	"IF",
	"IN",
	"INCLUD",
	"INDEX",
	"INITGLOBAL",
	"INITLOCAL",
	"INSERT",
	"INSTR",
	"INT",
	"INV",
	"JOIN",
	"KBF",
	"KEY",
	"LANG",
	"LARGE",
	"LASER",
	"LDGO",
	"LEFT",
	"LEN",
	"LFILE",
	"LIKE",
	"LIN",
	"LINE",
	"LINK",
	"LJOIN",
	"LKEY",
	"LLINK",
	"LOAD",
#ifdef _KEYWORD_LOADUSER
	"LOADUSER"	,	
#endif
	"LOCAL",
	"LOG",
	"LOOP",
	"MASK",
	"MOD",
	"MODIF",
	"MODULE",
	"MOVE",
	"NAME",
	"NEXT",
	"NKEY",
	"NULL",
	"OF",
	"OFF",
	"ON",
	"OP",
	"OPEN",
	"OR",
	"OX",
	"PAGE",
	"PAINT",
	"PALET",
	"PARSE",
	"PAUSE",
	"PEN",
	"PIE",
	"POINT",
	"POSIT",
	"POWER",
	"PREAD",
	"PRINT",
	"PROC",
	"PROCESS",
	"PROGRAM",
	"PTR",
	"READ",
	"REAL",
	"RECORD",
	"REMOVE",
	"RENAME",
	"REPEAT",
	"RESTORE",
	"RESUME",
	"RET",
	"RETURN",
	"RIGHT",
	"RJOIN",
	"RKEY",
	"RND",
	"ROUN",
	"SEARCH",
	"SEGMENT",
	"SELECT",
	"SGN",
	"SHL",
	"SHR",
	"SIN",
	"SMALL",
	"SPACE",
	"SQR",
	"STAT",
	"STDFORM",
	"STEP",
	"STOP",
	"STRN",
	"STRUCT",
	"SUBSTR",
	"SWAP",
	"SYSERROR",
	"TAB",
	"TABV",
	"TAN",
	"TEXTPEN",
	"THEN",
	"TIMER",
	"TO",
#ifdef _KEYWORD_TRACE
	"TRACE",	
#endif
	"TRAN",
	"UNTIL",
	"UP",
	"USEFONT",
	"USER",
	"VAL",
	"VALIDPTR",
	"VIEWPORT",
	"VPTR",
	"WAIT",
	"WEND",
	"WHERE",
	"WHILE",
	"WINDOW",
	"WITH",
	"WRITE",
//#ifdef _CRIEXT_
	"XCRI"
//#endif
};

static BOOL wan;        /* indicateur : numerotation automatique */
			/* des fonctions utilisateur d'une RT */
BINAIRE nofctusr;       /* numero fct utilisateur (numerotation auto) */

/* PRIVATE FONCTIONS */
/* ----------------- */

#ifdef LINT_ARGS

static  void traituser(void);
static  void getfusr(BOOL);
static  BINAIRE getfuarg(BYTE [],BYTE [],BOOL *);
static  void getident ( char );
static  BOOL buildidt ( char * );
static  BOOL isnotakey ( char * );
static  BOOL isnotausr(char *); /* reconnaissance fct util */
static  BOOL looknl0 ( void );
static  BOOL lookseg ( void );
static  BOOL lookproc ( void );
static  BOOL lookuser ( void );
static  BOOL lookgo ( void );
static  void gethex ( void );
static  void getnum ( char );
static  void cvascnum ( BOOL , int );
static  void getchn ( void);
static  void getetq ( void);
static  void getfmt ( void);
/* #AT: 22/11/99 (begin)*/
#ifndef __ATR22__
static  char getcar ( void);
#endif
/* #AT: 22/11/99 (end)*/
static  char *getstr ( char,char *,int );
static  char carsuiv ( void);
static  char nextcar ( void);
static  BOOL preprocess ( void);
static void trtpragma( void);
static  char ouinon(int,char *,char,char);
static  void traitincl ( void);
static  BOOL reprac(char *,char *);
static  void nextdirective ( void);
static  BOOL recupidt ( BYTE);
static  void traitdef ( BOOL);
static  void traitudef ( BOOL);
static  void recbin (BOOL, BINAIRE *);
static BOOL inclrecherche(char, LstInc *, char *, char *);
static void trkeyword(void);

#else /* ! LINT_ARGS */

static  void traituser();
static  void getfusr();
static  BINAIRE getfuarg();
static  void getident ();
static  BOOL buildidt ();
static  BOOL isnotakey ();
static  BOOL isnotausr();
static  BOOL looknl0 ();
static  BOOL lookseg ();
static  BOOL lookproc ();
static  BOOL lookuser ();
static  BOOL lookgo ();
static  void gethex ();
static  void getnum ();
static  void cvascnum ();
static  void getchn ();
static  void getetq ();
static  void getfmt ();
/* #AT: 22/11/99 (begin)*/
#ifndef __ATR22__
static  char getcar ();
#endif
/* #AT: 22/11/99 (end)*/
static  char *getstr ();
static  char carsuiv ();
static  char nextcar ();
static  BOOL preprocess ();
static void trtpragma ();
static  char ouinon();
static  void traitincl ();
static  BOOL reprac();
static  void nextdirective ();
static  BOOL recupidt ();
static  void traitdef ();
static  void traitudef ();
static  void recbin ();
static BOOL inclrecherche();
static void trkeyword();

#endif /* LINT_ARGS */

/* PRIVATE END */
/* ----------- */

#endif /* _LEXICAL */

/* ---------------- FIN lexical.hs-----------------------------------------*/

