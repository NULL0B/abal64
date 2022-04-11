/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : FUSER.H
 *      Version : 2.1f
 *      Date    : 22/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions relatives aux bibliotheques dynamiques]
 *
 */
#ifndef _FUSER_H
#define _FUSER_H

#define         LGNRT   64      /* lgr max d'un nom de bibliotheque */


/*              Definition du type "fonction utilisateur"       */
/*              -----------------------------------------       */

#define Tbusr   struct _tusr

Tbusr {
        BYTE    nom[LGIDENT];   /* nom de la fonction */
        BINAIRE nort;           /* numero de bibli */
        BINAIRE nofct;          /* numero de fonction dans la bibli */
        BYTE    tres;           /* type de retour (void,%,*,$) */
        BOOL    nbavar;         /* nombre d'arguments variable */
        BINAIRE nba;            /* nombre d'arguments */
        BYTE    *typa;          /* ptr sur le type des arguments */
        BYTE    *moda;          /* ptr sur le mode de passage des arguments */
        Tbusr   *g;             /* fils gauche */
        Tbusr   *d;             /* fils droit */
};

/*              Definition du type "appel a une fonction"       */
/*              -----------------------------------------       */

#define AppFct  struct _appfct

AppFct {
        BOOL    *simple;        /* ptr sur type simple/complexe des arguments */
        Tbusr   *fct;           /* ptr sur descripteur fonction */
};


/*              Definition du type "runtime"    */
/*              ----------------------------    */

#define TabRt   struct _tabrt

TabRt {
        BYTE    nom[LGNRT];     /* nom de la runtime */
        BYTE    ident[LGIDENT];	/* identificateur de la runtime */
        BINAIRE nort;           /* numero de la runtime */
        BINAIRE nbfct;          /* nombre de fonctions de la runtime */
	BYTE options;		/* 1 = differe */
        TabRt   *suiv;          /* chainage */
};


/*              Definition du type "reference a une runtime"    */
/*              --------------------------------------------    */

#define TabuRef struct _taburef

TabuRef {
        BYTE    nort;           /* numero de runtime */
        BINAIRE bloc;           /* numero de bloc de la reference */
        BINAIRE offst;          /* offset dans ce bloc */
        TabuRef *suiv;          /* chainage */
};


#define All_Tbusr() (Tbusr *) XNmalloc("Tbusr",sizeof(Tbusr))
#define All_TabRt() (TabRt *) XNmalloc("TabRt",sizeof(TabRt))
#define All_TabuRef() (TabuRef *) XNmalloc("TabuRef",sizeof(TabuRef))
#define All_AppFct() (AppFct *) XNmalloc("AppFct",sizeof(AppFct))
#define Free_Tbusr(p) Xfree((char *) p)
#define Free_TabRt(p) Xfree((char *) p)
#define Free_TabuRef(p) Xfree((char *) p)
#define Free_AppFct(p)  Xfree((char *) p)
#define Free_BYTE(p)    Xfree((char *) p)
#define Free_BOOL(p)    Xfree((char *) p)

#define TVOID   31              /* type sans retour */

#endif /* _FUSER_H */

