/*
 *      Projet  : ABAL                  Copyright Prologue s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : GENCODE.H
 *      Version : 2.2b
 *      Date    : 21/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions de la generation du T-code]
 *
 */

/* --------------------------------------------------------------------------
 * 27/10/92 : Debut version 1.5
 *              Insertion des nouvelles fonctions CLF et  NGF 1.5
 *              CLF : CREATE (06), REMOVE (16), FORGET (26), ALIAS (36),
 *                    ASKCOLOR (57), ASKATB (67), SETHOTKEY (77), SETLANG (87),
 *                    INITDATA (97), LIBUSER (A7), LIBPROC (B7), LIBSEGM (C7),
 *                    PARSE (5C), POWER (AB), STDFORM (5E), REAL (6E)
 *              NGF : NAME (29)
 *	------------ 2.2b -------------------------------------------------
 */

#ifdef _GENCODE

/* PRIVATE */
/* ------- */

/* PRIVATE MACRO */
/* ------------- */

#define MXRELARG        256

#define pcode(b) { pbyte(NOAT, (BYTE) (b | flg_new) ); flg_new = (BYTE) 0; }

#define IsExtVar(t,v)	(( t == 2 ) && ( (v & IS_EXTERN) == IS_EXTERN ))

/* PRIVATE VARIABLES */
/* ----------------- */

/*      Flag signalant le debut d'une instruction ABAL          */
/*      ----------------------------------------------          */

static BYTE flg_new;

/*      definition des codes des fonctions predefinies          */
/*      ----------------------------------------------          */

/*      ATTENTION: cette table respecte le classement des fonctions par ordre
 *                 alphabetique initial (BAL) puis par ordre d'apparition.
 */
static BYTE NumFn[] = {
/*  0 */
/*ABS*/ 0x0008, /*ATB*/ 0x0000, /*ATN*/ 0x0009, /*BELL*/ 0x0000,
/*  4 */
/*CHR*/ 0x007D, /*CLEAR*/ 0x0000, /*COL*/ 0x000F, /*CONF*/ 0x005F,
/*  8 */
/*CONV*/ 0x0000, /*COS*/ 0x0019, /*CURDIR*/ 0x004D, /*CURVOL*/ 0x005D,
/* 12 */
/*DATE*/ 0x002D, /*DEC*/ 0x001B, /*EXP*/ 0x0029, /*FIX*/ 0x000E,
/* 16 */
/*FM*/ 0x007A,
/* 17 */
/*FP*/ 0x002E, /*GENER*/ 0x000D, /*HEX*/ 0x006D, /*HOME*/ 0x0000,
/* 21 */
/*INCLUD*/ 0x0018, /*INDEX*/ 0x005B, /*INSTR*/ 0x006B, /*INT*/ 0x003E,
/* 25 */
/*INV*/ 0x004A, /*KBF*/ 0x003D, /*LARGE*/ 0x000A, /*LEFT*/ 0x000C,
/* 29 */
/*LEN*/ 0x002B, /*LEN$*/ 0x003B, /*LIN*/ 0x001F, /*LOG*/ 0x0039,
/* 33 */
/*MOD*/ 0x0000, /*MOVE*/ 0x003C, /*PAGE*/ 0x0000, /*PAINT*/ 0x0000,
/* 37 */
/*PRINT*/ 0x0000, /*PROCESS*/ 0x002F, /*RIGHT*/ 0x001C, /*RND*/ 0x003F,
/* 41 */
/*ROUN*/ 0x001E, /*SGN*/ 0x004B, /*SHL*/ 0x002A, /*SHR*/ 0x003A,
/* 45 */
/*SIN*/ 0x0049, /*SMALL*/ 0x001A, /*SPACE*/ 0x001D, /*SQR*/ 0x0059,
/* 49 */
/*STRN*/ 0x007E, /*SUBSTR*/ 0x002C, /*TAB*/ 0x0000, /*TABV*/ 0x0000,
/* 53 */
/*TAN*/ 0x0069, /*TRAN*/ 0x0028, /*VAL*/ 0x004E,
                /* Nouvelles fonctions ABAL */
/* 56 */
/*MASK(lecture)*/ 0x004F, /*DATE(ecriture)*/ 0x0037, /*KBF(ecriture)*/ 0x0047,
/* 59 */
/*WAIT*/ 0x0007, /*MASK*/ 0x0017, /* libre */ 0x0000,/*RESTORE*/ 0x0027,
/* 63 */
/*INSERT*/ 0x0038, /*SWAP*/ 0x004C, /*ERRADR*/ 0x006F, /*VPTR*/ 0x007B,
/* 67 */
/*RESTORE*/ 0x007F, /*ENV*/ 0x008A , /*HOTKEY*/ 0x009F, /*EVENTADR*/ 0x008F,
/* 71 */
/*SYSERROR*/ 0x00AD,
                /* Nouvelles fonctions ABAL 1.5 */
/* 72 */
/*PARSE*/ 0x005C, /*MASK (ecriture)*/ 0x0077, /*LANG (ecriture)*/ 0x0087,
/* 75 */
/* LANG (lecture)*/ 0x005F, /* INITGLOBAL */ 0x0097, /* INITLOCAL */ 0x0097,
/* 78 */
/* POWER */ 0x00AB, /* STDFORM */ 0x005E, /* REAL */ 0x006E,
/* 81 */
/* ASKATB */ 0x0067, /* ASKCOLOR */ 0x0057,
/* 83 */
/* CREATE */ 0x0006, /* REMOVE */ 0x0016, /* FORGET */ 0x0026,
/* 86 */
/* ALIAS */ 0x0036, /* LIBUSER */ 0x00A7, /* LIBPROC */ 0x00B7,
/* 89 */
/* LIBSEGM */ 0x00C7, /* VALIDPTR */ 0x0005, /* AFFECT */ 0x00AA,
/* 92 */
/* EVENT (GET) */ 0x00AF , /* EVENT (SET) */ 0x00D7, /* HASH */ 0x000B,
/* 95 */
/* ATTACH */ 0x0046, /* DETTACH */ 0x0056, /* PROC PTR */ 0x00BD,
/* 98 */
/* ALTER */ 0x0066, /* USER PTR */ 0x00CD, /* SEGMENT PTR */ 0x00DD,
/* 101 */
/* LOADUSER */ 0x00F7, /* TRACE ON */ 0x0001, /* TRACE OFF */ 0x0011, /*TRACE PRINT */ 0x0021, /* TRACE HEX */ 0x0031,
};

/*      Definition des codes des instructions de la categorie NGF       */
/*      ---------------------------------------------------------       */

/*      ATTENTION: cette table respecte le classement des fonctions par ordre
 *                 alphabetique initial (BAL) puis par ordre d'apparition.
 *              (0x00FF correspond a une fonction non encore traite par EX).
 */
static BYTE NumNGF[] = {
/*  0 */
/*ASSIGN*/ 0x0010, /*ARC*/ 0x00FF, /*ATB*/ 0x000D, /*BACKSPACE*/ 0x000E,
/*  4 */
/*BOX*/ 0x00FF, /*CFILE*/ 0x0000, /*CHAIN*/ 0x0013, /*CIRCLE*/ 0x00FF,
/*  8 */
/*CJOIN*/ 0x0022, /*CKEY*/ 0x0015, /*CLINK*/ 0x001B, /*CLOSE*/ 0x0004,
/* 12 */
/*COUNT*/ 0x001E, /*DELETE*/ 0x0009, /*DFILE*/ 0x0001, /*DJOIN*/ 0x0023,
/* 16 */
/*DOWN*/ 0x000B, /*EXTEND*/ 0x000F, /*FILE*/ 0x0010, /*FKEY*/ 0x0017,
/* 20 */
/*FREEFONT*/ 0x00FF, /*GRCONF*/ 0x00FF, /*INSERT*/ 0x0007, /*JOIN*/ 0x0021,
/* 24 */
/*KEY*/ 0x0014, /*LFILE*/ 0x0026, /*LINE*/ 0x00FF, /*LINK*/ 0x001A,
/* 28 */
/*LJOIN*/ 0x0025, /*LKEY*/ 0x0019, /*LLINK*/ 0x001C, /*LOADGO*/ 0x0011,
/* 32 */
/*MODIF*/ 0x0008, /*NKEY*/ 0x0018, /*OPEN*/ 0x0003, /*PALET*/ 0x00FF,
/* 36 */
/*PEN*/ 0x00FF, /*PIE*/ 0x00FF, /*POINT*/ 0x00FF, /*POSIT*/ 0x001D,
/* 40 */
/*PREAD*/ 0x00FF, /*READ*/ 0x0005, /*RECORD*/ 0x0020, /*RENAME*/ 0x0002,
/* 44 */
/*RJOIN*/ 0x0024, /*RKEY*/ 0x0016, /*SEARCH*/ 0x000A, /*STAT*/ 0x001F,
/* 48 */
/*TEXTPEN*/ 0x00FF, /*UP*/ 0x000C, /*USEFONT*/ 0x00FF, /*VIEWPORT*/ 0x00FF,
/* 52 */
/*WINDOW*/ 0x00FF, /*WRITE*/ 0x0006,
/* 54 */
/*FIND*/ 0x0027,
/* 55 */
/*NAME*/ 0x0029,
//#ifdef _CRIEXT_
/* 56 */
/* XCRI */ 0x0012
//#endif
};

/*      Codage d'une instruction PRINT ou ASK   */
/*      -------------------------------------   */

static BYTE     *ptabio;        /* pointeur sur code produit .............. */
static int      nbvrel,nbcrel;  /* nb variables ou constantes relogeables */
static int      varel[MXRELARG], cstrel[MXRELARG]; /* dans un PRINT ou ASK */
static int      nbetq;          /* nb etiquettes pour branch-list d'un ASK */
static int      tabref[MAXNBETQ];       /* et tables correspondantes ...   */
static BOOL     flgprint;       /* indique si PRINT ou ASK a produire */



/* PRIVATE FONCTIONS */
/* ----------------- */
#ifdef LINT_ARGS

static int decfmt(char *,BYTE *, int);
static void genioctl(BYTE,BYTE,BINAIRE);

#else

static int decfmt();
static void genioctl();

#endif /* LINT_ARGS */

/* PRIVATE END */
/* ----------- */

#include "trnoy.he"
#include "symboles.he"
#include "parser.he"
#include "trmess.he"
#include "gestfic.he"
#include "expr.he"
#include "table.he"

/* FIN DEFINITIONS EXTERNES */
/* ------------------------ */

#endif /* _GENCODE */

/*------------------------- FIN gencode.he ----------------------------*/


