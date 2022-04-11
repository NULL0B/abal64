/*
 *      Projet  : ABAL                  Copyright Prologue s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : EXPR.HS
 *      Version : 2.1f
 *      Date    : 21/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions du traitement des expressions]
 *
 */

#ifdef _EXPR

/* DEFINITION LOCALE  */
/* ------------------ */

/* PRIVATE */
/* ------- */

/*   Definitions et Macros de gestion d'un arbre d'evaluation d'expression   */
/*   ---------------------------------------------------------------------   */

#define ExpMemb struct _E_Memb  /* membre d'une expression */
#define ArgList struct _A_List  /* liste d'arguments pour appel de fonction */
ArgList {
        ExpMemb *va;
        ArgList *suiv;
};
#define All_ArgList() (ArgList *) XNmalloc("ArgList",sizeof(ArgList))
#define Free_ArgList(c) Xfree((char *) c)

ExpMemb {
        BYTE    tp;     /* type : 0 = valeur immediate, 1 = constante,  */
                        /*        2 = variable, 3 = var. registre,      */
                        /*        4 = operateur, 5 = appel de fonction  */
                        /*        6 = CONV, 7 = VPTR, 8 = NEG,          */
                        /*        9 = variable avec 1 dimension         */
                        /*       10 = variable avec 2 dimension         */
			/*	 11 = procedure-resultat		*/
			/*	 12 = parametre variable modifiable	*/
			/*	 13 = parametre registre modifiable	*/
        BYTE    na;     /* nombre d'arguments si appel de fonction */
                        /* type de donnee si variable  */
        BINAIRE vl;     /* valeur ou numero suivant 'tp' */
        BINAIRE vr;     /* numero de registre si variable 'registre' */
        BYTE    *desc;  /* pointeur sur descripteur si variable */
        ArgList *ap;    /* pointeur sur liste des arguments si appel */
        ExpMemb *g,*d;  /* pointeurs sur 'fils' dans l'arbre */
};
#define All_ExpMemb() (ExpMemb *) XNmalloc("ExpMemb",sizeof(ExpMemb))
#define Free_ExpMemb(c) Xfree((char *) c)


/*      Macros pour gerer un arbre d'evaluation d'expression conditionnelle  */
/*      -------------------------------------------------------------------  */

#define All_CdMemb() (CdMemb *) XNmalloc("CdMemb",sizeof(CdMemb))
#define Free_CdMemb(c) Xfree((char *) c)


/* PRIVATE MACRO */
/* ------------- */

/* PRIVATE VARIABLES */
/* ----------------- */
/*      Variables privees                                       */
/*      -----------------                                       */

static BOOL forcesimple; /* le resultat doit etre une expression simple */

static BOOL ind_verrue; /* indicateur special pour les indices de tableaux */
static BOOL arg_verrue; /* indicateur special pour arguments d'appels */
static BOOL oper_verrue; /* indicateur special pour operation en cours */
static BOOL logic_verrue; /* indicateur pour operation logique en cours */
static BOOL vptr_verrue; /* indicateur de traitement de VPTR */
static BOOL verrue_retour_ptr; /* indicateur de traitement de retour pointeur */

/* indicateur special pour CONV sur une affectation simple */
static BOOL diez_verrue;
static BOOL conv_verrue;
static BOOL cond_verrue; /* indicateur special pour l'ambiguite du  */
                         /* parenthesage des expressions conditionnelles */
static int nb_pad;      /* et nombre de parentheses fermantes "forcees" */

static BINAIRE adrecep; /* var de reception de l'affectation courante */
static BINAIRE regrecep; /* registre associe en cas d'optimisation */
static BYTE typrecep; /* et type de cette variable */

static BINAIRE aff_verrue;      /* signal affectation en cours */
static BOOL aff_is_done; /* affectation realisee en cours d'evaluation */
static BINAIRE vptreg;  /* numero registre VPT pour optimisation */


/* PRIVATE FONCTIONS */
/* ----------------- */
#ifdef LINT_ARGS

/*      Prototypes des fonctions internes       */
/*      ---------------------------------       */

static CdMemb *expcond2 (CdMemb *,int);
static ExpMemb *tr_exp(BYTE *);
static ExpMemb *tr_terme(BYTE *);
static ExpMemb *tr_facteur(BYTE *);
static BOOL tr_dim(ExpMemb *,BYTE *);
static ExpMemb *tr_fnt(BYTE *);
static ArgList *tr_argfu(BINAIRE *,BYTE[],BYTE[],BOOL [],BOOL);
static ArgList *tr_args(BINAIRE *,BYTE[],BOOL);
static void lib_exp(ExpMemb *);
static void lib_AppFct(AppFct *);
static void lib_arg(ArgList *);
static void eval_exp(ExpMemb *, BYTE *, BINAIRE *,BYTE *);
static void eval_oper(ExpMemb *, BYTE *, BINAIRE *, BYTE *);
static void ev_indices(BINAIRE, ArgList *);
static ExpMemb *fnt_usr(Tbusr *,BYTE *);
static ExpMemb *fnt_proc(TabProc *,BYTE *);

static BINAIRE valeur (Code_Synt);
static BINAIRE calcul (BINAIRE,BINAIRE,BINAIRE);
static BOOL commutatif (BINAIRE);
static CdMemb *condition (void);
static BOOL isrelation (Code_Synt,BINAIRE *);
static BOOL recargs(int,BYTE [],BYTE [],BINAIRE []);
static BOOL tstbinres(BYTE *);
static BOOL tststrres(BYTE *);
static BOOL tstbcdres(BYTE *);
static BINAIRE cvbintobcd(BINAIRE,BOOL);
static void tr_proc_seg_user(BINAIRE,ExpMemb *);

static void init_lreg(RegList **);
static void lib_lreg(RegList **);
static void push_lreg(RegList **, BINAIRE);
static BINAIRE pop_lreg(RegList **);
// #FC+BG 03/12/02 static BINAIRE debut_lreg(RegList *);
// #FC+BG 03/12/02 static BINAIRE suivant_lreg(void);
static BOOL findreg(BINAIRE, BYTE [], BINAIRE [], BINAIRE);

#else

/*      Prototypes des fonctions internes       */
/*      ---------------------------------       */

static CdMemb *expcond2 ();
static ExpMemb *tr_exp();
static ExpMemb *tr_terme();
static ExpMemb *tr_facteur();
static BOOL tr_dim();
static ExpMemb *tr_fnt();
static ArgList *tr_argfu();
static ArgList *tr_args();
static void lib_exp();
static void lib_AppFct();
static void lib_arg();
static void eval_exp();
static void eval_oper();
static void ev_indices();
static ExpMemb *fnt_usr();
static ExpMemb *fnt_proc();

static BINAIRE valeur ();
static BINAIRE calcul ();
static BOOL commutatif ();
static CdMemb *condition ();
static BOOL isrelation ();
static BOOL recargs();
static BOOL tstbinres();
static BOOL tststrres();
static BOOL tstbcdres();
static BINAIRE cvbintobcd();
static void tr_proc_seg_user();

static void init_lreg();
static void lib_lreg();
static void push_lreg();
static BINAIRE pop_lreg();
// #FC+BG 03/12/02 static BINAIRE debut_lreg();
// #FC+BG 03/12/02 static BINAIRE suivant_lreg();
static BOOL findreg();

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
#include "gencode.he"
#include "table.he"

/* FIN DEFINITION EXTERNES */
/* ----------------------- */
#endif /* _EXPR */

/* ---------------- FIN expr.hs -----------------------------------------*/

