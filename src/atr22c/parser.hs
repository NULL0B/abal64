/*
 *      Projet  : ABAL                  Copyright Prologue s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : PARSER.HS
 *      Version : 2.2b
 *      Date    : 21/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions de l'analyseur syntaxique]
 *
 */

#ifdef _PARSER

/* PRIVATE */
/* ------- */

/* PRIVATE MACRO */
/* ------------- */

#define Free_Etiq(p) Xfree((char *) p)

/*      Macro pour l'allocation d'un descripteur de segment     */
/*      ---------------------------------------------------     */

#define All_Tseg() (TabSeg *) XNmalloc("Tseg",sizeof(TabSeg))
#define Free_Tseg(p) Xfree((char *) p)

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

static CdMemb *deb_expcond;     /* racine de l'arbre d'evaluation         */
				/* de l'expresion conditionnelle courante */

static long int lg_datas;       /* taille totale des donnees */
static long int lg_const;       /* taille totale des constantes */
static long int lg_code;        /* taille totale du code */

static BINAIRE nb_pext;         /* nombre de procedures externes */
static BINAIRE nb_ext;		/* nombre de variables externes */

static BINAIRE ofst_datas;      /* offset dans code des eventuelles DATA */
static BINAIRE nbre_datas;      /* nombre des eventuelles DATA */
static BOOL use_datas;          /* utilisation de DATA .. */

static BINAIRE glob_m;          /* Taille des variables globales en FIELD=M */

static BOOL clr;        /* option clear oui/non */

static BOOL externfld=FALSE;            /* flag oui/non dans zone EXTERN FIELD */
static BINAIRE nb_vext=0;               /* nombre de variables externes */
static BINAIRE nb_sext=0;               /* nombre de segments externes */
static BINAIRE nb_seg=0;                /* nombre de segments nommes */

static BYTE curretfct=0; /* permet de connaitre le type de retour de la */
			 /* procedure courante */
static BOOL flag_exit=FALSE;    /* flag VRAI si instruction EXIT deja rencontree */
					
static BINAIRE nb_forward=0;	/* nombre de foraward non resolu */

static int etspe;       /* valeur binaire etiquette interne courante */

static BINAIRE NbToTrad;

/* PRIVATE FONCTIONS */
/* ----------------- */
#ifdef LINT_ARGS
/*      Prototypes des fonctions internes du syntaxique         */
/*      -----------------------------------------------         */

static void programme (void);
static void module (void);

static BOOL forward(void);
static BOOL procedure (void);
static void extsegment(void);   /* traitement d'un segment externe */

static void extproc (void);
static void segment (void);
static void fusion (void);
static BOOL segexist (BINAIRE);
static void localdcl (BOOL,BINAIRE,BINAIRE *, BOOL);

static void globaldcl (void);
static void dclarg (BINAIRE *);
static void prepdcl (void);
static void resref (BINAIRE,BOOL);
static void resetiq (BINAIRE,TabEtiq *,BOOL);
static BOOL instruction (BOOL);
static BOOL recadr (void);

static void callproc (BOOL);

static BOOL traitif (BOOL);
static BOOL trloop (BOOL);
static BOOL trepeat (BOOL);
static BOOL twhile (BOOL);
static BOOL trfor (BOOL);
static void pushfin (char **, char **);
static void popfin (char **);
static BOOL traitsel (BOOL);
static void debut_instruction(void);
static void trfnspe(int);
static void trerreur(void);
static void traffn(int);
static void trpause(void);
static void tradop(void);
static BOOL tradon(BOOL);
static void tradof(void);
static BOOL errbranch(BOOL,BYTE *,BINAIRE *,char *);
static void trprnt(void);
static void trask(void);
static BOOL trudir(int);
static BOOL trtrace();				/* #IJM 06/11/02 */
static BOOL trtraceon(int);		/* #IJM 06/11/02 */
static BOOL trtraceoff(int);		/* #IJM 06/11/02 */
static BOOL trtraceprint(int);	/* #IJM 06/11/02 */
static BOOL trddir(int);			/* #IJM 06/11/02 */
static BOOL askbranch(void);
static BOOL trfmt(void);
static void tradfmt(void);
static void trread(void);
static BOOL isdata(BOOL);

#else
/*      Prototypes des fonctions internes du syntaxique         */
/*      -----------------------------------------------         */

static void programme ();
static void module ();

static BOOL forward();
static BOOL procedure ();
static void extsegment();   /* traitement d'un segment externe */

static void extproc ();
static void segment ();
static void fusion ();
static BOOL segexist ();
static void localdcl ();
static void globaldcl ();
static void dclarg ();
static void prepdcl ();
static void resref ();
static void resetiq ();
static BOOL instruction ();
static BOOL recadr ();
static void callproc ();
static BOOL traitif ();
static BOOL trloop ();
static BOOL trepeat ();
static BOOL twhile ();
static BOOL trfor ();
static void pushfin ();
static void popfin ();
static BOOL traitsel ();
static void debut_instruction();
static void trfnspe();
static void trerreur();
static void traffn();
static void trpause();
static void tradop();
static BOOL tradon();
static void tradof();
static BOOL errbranch();
static void trprnt();
static void trask();
static BOOL trudir();
static BOOL trddir();
static BOOL askbranch();
static BOOL trfmt();
static void tradfmt();
static void trread();
static BOOL isdata();

#endif /* LINT_ARGS */

/* PRIVATE END */
/* ----------- */

/* FIN DEFINITIONS INTERNES */
/* ------------------------ */

/* DEFINITIONS EXTERNES */
/* -------------------- */

/* MODULE */
/* ------ */

#include "trnoy.he"
#include "symboles.he"
#include "lexical.he"
#include "trmess.he"
#include "expr.he"
#include "iofnt.he"
#include "gencode.he"
#include "gestfic.he"
#include "table.he"
#include "debug.he"

/* FIN DEFINITIONS EXTERNES */
/* ------------------------ */

#endif /* _PARSER */
/*------------------------- FIN parser.hs ----------------------------*/

