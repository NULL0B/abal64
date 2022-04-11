/*
 *      Projet  : ABAL                  Copyright Prologue s.a. (c) 1993, 1995
 *      Module  : ATR
 *      Fichier : TABLE.HS
 *      Version : 2.1f
 *      Date    : 22/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Module de gestion des tables ( DCL, CST, PROC, SEG )
 *	Definition interne
 */

#ifdef _TABLE

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

/* PRIVATE FONCTIONS */
/* ----------------- */
#ifdef LINT_ARGS

static BINAIRE Xmkdcldesc ( BOOL , BOOL, BOOL, BYTE , BINAIRE , BINAIRE , BINAIRE );
static BINAIRE Xmkcststr ( BINAIRE, BINAIRE *, char * );
static BINAIRE Xmkcstbcd ( BINAIRE, BINAIRE *, BYTE * );

static BYTE *All_Desc ( int , BINAIRE , BINAIRE *);
static BINAIRE Xmatchcst (char *,BINAIRE,BINAIRE,BOOL);

static void affvinfo(DCLInfo *);

#else
/*      Prototypes des fonctions internes       */
/*      ---------------------------------       */

static BINAIRE Xmkdcldesc ();
static BINAIRE Xmkcststr ();
static BINAIRE Xmkcstbcd ();

static BYTE *XAll_Desc ();
static BINAIRE Xmatchcst ();

static void affvinfo();

#endif /* LINT_ARGS */

/* PRIVATE END */
/* ----------- */

/* DEFINITIONS EXTERNES */
/* -------------------- */

/* MODULE */
/* ------ */
#ifndef NO_TRADUCT
#include "trnoy.he"
#include "trmess.he"
#else
#include "extable.he"
#endif /* NO_TRADUCT */
/* FIN DEFINITION EXTERNES */
/* ----------------------- */

#endif /* _TABLE */

/* ---------------- Fin du fichier : table.hs ----------------------------- */

