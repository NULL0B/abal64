/*
 *      Projet  : ABAL                  Copyright Prologue s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : TCASM.HS
 *      Version : 2.1f
 *      Date    : 22/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions relatives au macroassembleur de Tcode]
 *
 * --------------------------------------------------------------------------
 *      27/10/92 : Debut version 1.5
 *              Insertion des nouvelles fonctions CLF et  NGF 1.5
 *              CLF : CREATE (06), REMOVE (16), FORGET (26), ALIAS (36),
 *                    ASKCOLOR (57), ASKATB (67), SETHOTKEY (77), SETLANG (87),
 *                    INITDATA (97), LIBUSER (A7), LIBPROC (B7), LIBSEGM (C7),
 *                    PARSE (5C), POWER (AB), STDFORM (5E), REAL (6E)
 *              NGF : NAME (29)
 * --------------------------------------------------------------------------
 *
 */

#ifdef _TCASM

/* DEFINITION LOCALE  */
/* ------------------ */

/* PRIVATE */
/* ------- */

/* PRIVATE MACRO */
/* ------------- */

#define MXCODES 52      /* Nombre de codes operation de base */

/*      Temporaire pour tests : les fonctions PRINT et ASK      */

#define FN_ASK 0x00
#define FN_PRN 0x04

/*      Macro pour la generation de code                */

#define pcode(c) { pbyte(NOAT,c); adrimpl++; }
#define preg(c) { pbyte(NOAT,c); adrimpl++; }
#define padr(c) { pbin(NOAT,c); adrimpl += 2L; }

/* PRIVATE VARIABLES */
/* ----------------- */

/*      table des mnemoniques sous leur forme 'source'          */

static char     _tc_mnem[MXCODES][4] =  {

"ESC", "LDR", "IAX", "LIX", "AIX", "RAZ", "RET", "GSB", "ADD", "SUB", "MUL",
"DIV", "MOD", "AND", "OR",  "OX",  "SGT", "INC", "JMP", "PSE", "CLF", "NEW",
"CLP", "JEQ", "JNE", "JGE", "JLE", "JGR", "JLS", "JIN", "JNI", "ERG", "DAX",
"PSH", "RTS", "DEC", "ERA", "STO", "POP", "RTP", "INX", "RES", "NEG", "LDF",
"STP", "DBG", "DEX", "NOP", "TPC", "CNV", "VPT", "DTR"

};

/*      Codes binaires associes a chaque mnemomnique    */

static BYTE     _tc_code[MXCODES] =  {

F_ESC, F_LDR, F_AIX, F_LIX, F_AIX, F_RAZ, F_RET, F_GSB, F_ADD, F_SUB, F_MUL,
F_DIV, F_MOD, F_AND, F_OR,  F_OX,  F_SGT, F_INC, F_JMP, F_PSE, F_CLF, 0x16,
F_CLP, F_JEQ, F_JNE, F_JGE, F_JLE, F_JGR, F_JLS, F_JIN, F_JNI, F_ERG, F_DAX,
F_PSH, F_RTS, F_DEC, F_ERA, F_STO, F_POP, F_RTP, F_INX, F_RES, F_NGR, F_LDF,
F_STP, 0,     F_DEX, F_NOP, F_TPC, F_CNV, F_VPT, F_DTR,

};

/*      Codage des types d'arguments    */
/*      ----------------------------    */

static BINAIRE  _tc_args[MXCODES] = {
   15,     3,     1,     3,     3,     0,     0,     8,     4,     4,     4,
    4,     4,     4,     4,     4,     6,     1,     8,     7,    11,     0,
   12,     5,     5,     5,     5,     5,     5,     5,     5,    10,     1,
    1,     0,     1,     0,     2,     1,     0,     1,     0,     9,    14,
    0,     0,     1,     0,    10,    16,    17,    18
};

/*
Code    Nombre  Descriptif
---------------------------------------------
0       0       Pas d'argument
1       1       #
2       2       { I + 00 | C + 20 | V + 40 | # + 60 } , V
3       2       # , { I + 00 | C + 20 | V + 40 | # + 60 }
4       3       # , { I + 00 | C + 20 | V + 40 | # + 60 } ,  #
5       3       # , { I + 00 | C + 20 | V + 40 | # + 60 } ,  &
6       1       { I + 00 | # + 20 | V + 40 }
7       1       { I + 00 | C + 20 | V + 40 | # + 60 }
8       1       { & + 00 | # + 20 | V + 40 }
9       1       { # + 00 | V + 10 }
10      2       V , &
11      ... pour CLF
12      ... pour CLP
13      ... pour NGF
14      ... pour LDF
15      ... pour ESC : 2 octets (valeur binaire ou registre)
16      2       # , I
17      2       # , V
18      1       V
*/


/* PRIVATE FONCTIONS */
/* ----------------- */
#ifdef LINT_ARGS

/*      primitives internes du Macro-Assembleur         */

static BINAIRE recmnemo (void);
static void defbytes(void);
static void deflabel(void);
static void defvar(void);
static void rec_args (BYTE,BINAIRE);
static BOOL tr_fnt (void);
static BOOL getreg (BYTE *);
static BOOL getint (BINAIRE *);
static BOOL getvar (BINAIRE *);
static BOOL getetq (BINAIRE *);
static BOOL geticvr(BYTE,BYTE);
static BOOL gtsicvr(BYTE);
static BOOL getirv(BYTE);
static BOOL geterv(BYTE);
static BOOL getrv(BYTE);
static BOOL getir(void);
static BOOL sep (void);


#else

/*      primitives internes du Macro-Assembleur         */

static BINAIRE recmnemo ();
static void defbytes();
static void deflabel();
static void defvar();
static void rec_args ();
static BOOL tr_fnt ();
static BOOL getreg ();
static BOOL getint ();
static BOOL getvar ();
static BOOL getetq ();
static BOOL geticvr();
static BOOL gtsicvr();
static BOOL getirv();
static BOOL geterv();
static BOOL getrv();
static BOOL getir();
static BOOL sep ();

#endif /* LINT_ARGS */

/* PRIVATE END */
/* ----------- */

/* DEFINITIONS EXTERNES */
/* -------------------- */

/* MODULE */
/* ------ */

#include "trnoy.he"
#include "lexical.he"
#include "symboles.he"
#include "parser.he"
#include "trmess.he"
#include "gestfic.he"

/* FIN DEFINITION EXTERNES */
/* ----------------------- */
#endif /* _TCASM */

/* ---------------- FIN tcasm.hs -----------------------------------------*/

