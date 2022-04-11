/*
 *      Projet  : ABAL                  Copyright Prologue s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : SYMBOLES.HS
 *      Version : 2.1f
 *      Date    : 22/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions de la gestion des tables de symboles]
 *
 *	------------ 2.2a -------------------------------------------------
 * 17/02/97 : Debut revision 2.2
 * 17/02/97 : Allocation des structures TabStruct et Type
 *						 fonctions modifi‚es :
 *						 newvar()
 * 01/04/97 : Allocation de structure TabWith
 * 11/10/99 : (#SP) Enhancement ATR 23: Local named constants.
 *
 */

#ifdef _SYMBOLES

/* DEFINITION LOCALE  */
/* ------------------ */

/* PRIVATE */
/* ------- */

/* PRIVATE MACRO */
/* ------------- */
/*      Definitions relatives a la gestion des symboles         */
/*      -----------------------------------------------         */

#define All_LienR() (LienRef *) XNmalloc("LienR",sizeof(LienRef))
#define Free_LienR(p) Xfree((char *) p)
#define All_Symb() (TabSymb *) XNmalloc("Symb",sizeof(TabSymb))
#define Free_Symb(p) Xfree((char *) p)
#define All_With() (TabWith *) XNmalloc("With",sizeof(TabWith))
#define Free_With(p) Xfree((char *) p)
#define All_Struct() (TabStruct *) XNmalloc("Struct",sizeof(TabStruct))
#define Free_Struct(p) Xfree((char *) p)
#define All_Type() (Type *) XNmalloc("Type",sizeof(Type))
#define Free_Type(p) Xfree((char *) p)
#define All_Proc() (TabProc *) XNmalloc("Proc",sizeof(TabProc))
#define Free_Proc(p) Xfree((char *) p)
#define All_Tabdesc() (BYTE *) XNmalloc("Tabdesc",SIZETDESC)
#define Free_Tabdesc(t) Xfree((char *) t)
#define All_Etiq() (TabEtiq *) XNmalloc("Etiq",sizeof(TabEtiq))
#define Free_Etiq(p) Xfree((char *) p)
#define All_Lref() (RelRef *) XNmalloc("Lref",sizeof(RelRef))
#define Free_Lref(p) Xfree((char *) p)
#define All_Ref() (ExtRef *) XNmalloc("Ref",sizeof(ExtRef))
#define Free_Ref(p) Xfree((char *) p)

/*      Macro pour l'allocation d'un descripteur de segment     */
/*      ---------------------------------------------------     */

#define All_Tseg() (TabSeg *) XNmalloc("Tseg",sizeof(TabSeg))
#define Free_Tseg(p) Xfree((char *) p)

/*      Macro pour l'allocation d'un descripteur de variables externes */
/*      -------------------------------------------------------------- */

#define All_Xvar() (LstXvar *) XNmalloc("Xvar",sizeof(LstXvar))
#define Free_Xvar(p) Xfree((char *) p)

/*      Macro pour l'allocation d'un descripteur de point d'ancrage   */
/*      -----------------------------------------------------------   */

#define All_Ancr() (LstAncr *) XNmalloc("Ancr",sizeof(LstAncr))
#define Free_Ancr(p) Xfree((char *) p)

/*      Macro pour l'allocation d'un descripteur d'etiquette de variable  */
/*      ----------------------------------------------------------------  */
#define All_Etiqvar() (LstEtiqvar *) XNmalloc("Etiqvar",sizeof(LstEtiqvar))
#define Free_Etiqvar(p) Xfree((char *) p)

/*      Macro pour l'allocation d'un descripteur de nom de module */
/*      --------------------------------------------------------- */

#define All_Tnmod() (TabMod *) XNmalloc("Tnmod",sizeof(TabMod))
#define Free_Tnmod(p) Xfree((char *) p)


/*      Macro pour l'allocation d'un descripteur de nom de sources */
/*      --------------------------------------------------------- */

#define All_Tnsrc() (TabSrc *) XNmalloc("Tnsrc",sizeof(TabSrc))
#define Free_Tnsrc(p) Xfree((char *) p)

/* PRIVATE VARIABLES */
/* ----------------- */

/*	Hash-Listes des references aux variables externes		*/
/*	-------------------------------------------------		*/
#define HASHCODE	7
static RelRef *hlstextref[HASHCODE];
#define EvalHC(x)	(BINAIRE) (x % HASHCODE)

static long adrbaseextcr=0;	/* Point d'ancrage de variable externes courant */
static LstAncr *ptancr=GenericNULL(LstAncr);	/* Pointeur sur le point d'ancrage courant */

static BOOL flg_FEL=FALSE;	/* si flag ignorer les declarations en FIELD=E */
				/* en local */

BOOL flg_lcst_code=FALSE; /* vrai si dans le code . traitement local const */


/* PRIVATE FONCTIONS */
/* ----------------- */
#ifdef LINT_ARGS

static void libfusr(void);
static void libnfusr(Tbusr *);

static BOOL rec_depl ( BYTE * , long int * );
static BYTE getype (BOOL);
/*static BINAIRE getlong (BYTE);*/
static BINAIRE getdim (void);

static BOOL newvar (TabSymb **, BOOL, BOOL, char *, BOOL, BOOL, BOOL, Type *, BOOL);
static BOOL newconst (BOOL , char * , BINAIRE);
/* #SP: 11/10/99 (begin) */
#ifdef __ATR22__
static BOOL newconst_local (BOOL , char * , BINAIRE);
#endif
/* #SP: 11/10/99 (end) */
static void libproc (TabProc *);
static void libseg (TabSeg *);
static void libetiq (TabEtiq *);
static void libnoeud (TabSymb *);
static void libtabref (RelRef *);
static void libref (ExtRef *);

static void initextref (void);
static void createextref (BINAIRE, ExtRef **); 
static void insextref (BINAIRE, BINAIRE, BINAIRE);
static void libextref (void);

static void set_prev(TabSymb *, TabSymb *);
static void reftab(BINAIRE, BINAIRE);
static void patchreftab(BINAIRE);
static void initadsloc(TabSymb *);

#else

/*      Prototypes des fonctions internes       */
/*      ---------------------------------       */

static void libfusr();
static void libnfusr();

static BOOL rec_depl ();
static BYTE getype ();
/*static BINAIRE getlong ();*/
static BINAIRE getdim ();
static BOOL newvar ();
static BOOL newconst ();
static void libproc ();
static void libseg ();
static void libetiq ();
static void libnoeud ();
static void libtabref ();
static void libref ();

static void initextref ();
static void createextref (); 
static void insextref ();
static void libextref ();

static void reftab ();
static void patchreftab ();
static void initadsloc ();

#endif /* LINT_ARGS */

/* PRIVATE END */
/* ----------- */

/* DEFINITIONS EXTERNES */
/* -------------------- */

/* MODULE */
/* ------ */

#include "trnoy.he"
#include "lexical.he"
#include "parser.he"
#include "trmess.he"
#include "gencode.he"
#include "gestfic.he"
#include "table.he"

/* FIN DEFINITION EXTERNES */
/* ----------------------- */

#endif /* _SYMBOLES */

/* ---------------- FIN symboles.hs -----------------------------------------*/

