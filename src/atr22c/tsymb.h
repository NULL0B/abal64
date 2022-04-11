/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : TSYMB.H
 *      Version : 2.2b
 *      Date    : 22/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions relatives a la gestion des symboles (syntaxique + production)]
 *
 *	25/10/94 : Cohabitation des constantes globales et locales
 *	------------ 2.2a -------------------------------------------------
 * 17/02/97 : Debut revision 2.2
 * 17/02/97 : Structure TabStruct
 * 19/03/99 : SG : Modification de la structure pTabSymb pour l'optmisation (probleme FIELD=E, FIELD=no)
 *
 * 13/09/99 : (#AT) Bug ATR 6 fixed: Prohibit to pass integer parameters to 
 *            procedure if formal parameters has type ptr.
 *	------------ 2.2b -------------------------------------------------
 */

#ifndef _TSYMB_H
#define _TSYMB_H

#define SIZETDESC 4096  /* taille d'une sous-table de descripteurs */
#ifdef	VERSION_XX
#define	MAXTDESC  16	/* nb max sous-tables de descripteurs */
#else 
#define MAXTDESC  8     /* nb max sous-tables de descripteurs */
#endif
#define MAXCDESC  16    /* nb max sous-tables de descripteurs de constantes */

/*      Definition d'une reference a un objet externe ou relogeable     */
/*      -----------------------------------------------------------     */

#define ExtRef struct _XtRf
ExtRef {
        BINAIRE bloc,ofst;
        ExtRef  *suiv;
};

/*      Definition d'une liste de references de relogeabilite   */
/*      -----------------------------------------------------   */

#define RelRef struct _RlRf
RelRef {
        BINAIRE ads;    /* adresse descripteur de variable */
        ExtRef  *lref;  /* liste de references */
        RelRef  *suiv;  /* suite de la liste */
};

/*      Definition d'une liste de types								 */
/*		  A partir de le 2.2													 */
/*      ----------------------------------                      */

#define Type struct _Type
Type {
		BYTE		type;				/* type */
		BINAIRE	l;					/* longueur */
		BINAIRE	d1;				/* dimension 1 */
		BINAIRE	d2;				/* dimension 2 */
		BOOL		pasptr;			/* TRUE si non pointeur */
		void		*pStruct;		/* reference a TabStruct */
		long int	adrimpl;		/* adresse d'implantation si passage par
											paramŠtres d'une structure */
};

/*      Definition d'une table de symboles                      */
/*      ----------------------------------                      */

#define TabSymb struct _TbSy    /* 'type' : table de symboles */
TabSymb {
        char pid[LGIDENT];      /* nom/identificateur */
	BINAIRE mod;		/* Numero de module */
        ExtRef *lref;           /* liste des references */
	BINAIRE adsloc;		/* adr du descripteur dans la table locale */
        BYTE    opt;            /* flag d'options : 01234567     */
                                /* bit 0 : a 1 si var inutilisee */
                                /* bit 1 : a 1 si var "registre" */
                            /* bit 2 : pour optimisation des tables (variable       */
											/* non presente en memoire) */
                                /* bits 3-7 : no de registre     */
        BINAIRE ads;            /* adr relative du descripteur   */
        TabSymb *g;             /* pointeur sur suivant gauche   */
        TabSymb *d;             /* pointeur sur suivant droite   */
        TabSymb *next;          /* A partir de 2.2 : donn‚es membres
		  									  d'une structure instanci‚e */
        TabSymb *prev;          /* A partir de 2.2 : r‚f‚rence arriŠre */
		  Type	 *type;			  /* A partir de 2.2a : reference au type */	
		  BYTE	 declext;			/*Rajout pour optimisation SG 19/03/99*/
		  BOOL	 fldptr;				/*rajout pour l'optimisation SG 26/03/99*/
		  int		 lgptrfld;			/*rajout pour l'optimisation SG 30/03/99*/
		  BINAIRE adrptr;				/*rajout pour l'optimisation SG 31/03/99*/

};

/*      Types crees pour Struct/EndStruct                       */
/*		  A partir de le 2.2													 */
/*      ----------------------------------                      */

#define TabStruct struct _TbStruct
TabStruct {
    char pid[LGIDENT];      /* nom/identificateur */
		  TabSymb	*Symb;		  /* Symboles utilises dans le nouveau type */	
    TabStruct *prec;        /* pointeur sur precedant */
    TabStruct *suiv;        /* pointeur sur suivant */
		  BINAIRE	l;				  /* longueur */
};

/*      Types crees pour Struct/EndStruct                       */
/*		  A partir de le 2.2													 */
/*      ----------------------------------                      */

#define TabWith struct _TbWith
TabWith {
        char pid[LGIDENT];      /* nom/identificateur */
		  BYTE	passe;				  /* No de la passe de recherche
 											  		3 : variable locale
 											  		2 : variable globale
 											  		1 : variable externe */
		  TabSymb	*Symb;		  /* Symboles utilises dans le nouveau type */	
        TabWith 	*prec;        /* pointeur sur precedant */
        TabWith 	*suiv;        /* pointeur sur suivant */
};

/*      Definition d'une liste de variables externes            */
/*      --------------------------------------------            */

#define LstXvar struct _LsXv    /* 'type' : liste des variables externes */
LstXvar {
	TabSymb *info;		/* Pointeur sur un descripteur de variable */
        LstXvar *suiv;		/* pointeur sur suivant */
};

/*      Definition d'une liste de point d'ancrage               */
/*      -----------------------------------------               */

#define LstAncr struct _LsAn    /* 'type' : liste des points d'ancrage */
LstAncr {
        BINAIRE mod;            /* numero du module */
        char *nom;	     	/* nom du point d'ancrage */
	char type;		/* type : M ou E */
        long ads;         	/* adr du point d'ancrage ou -1 */
	BINAIRE nbxvar;		/* nombre de var externes */
	BINAIRE adrxvar;	/* numero de secteur de vidage */
	LstXvar *xvar;		/* liste des variables externes */
        LstAncr *suiv;		/* pointeur sur suivant */
};

/*      Definition d'une liste d'etiquette de variable */
/*      ---------------------------------------------- */

#define LstEtiqvar struct _LsEv    /* 'type' : liste des etiquettes de var */
LstEtiqvar {
        char *nom;		/* nom de l'etiquette de var */
	char type;		/* type : M ou E */
	long adr;		/* adresse d'implantation */
        LstEtiqvar *suiv;          /* pointeur sur suivant */
};


/*      Definition d'une table de procedures                    */
/*      ------------------------------------                    */

#define TabProc struct _TbPr    /* 'type' : table de procedures */
TabProc {
	char pid[LGIDENT];		/* nom/identificateur */
	BOOL		ext;				/* externe oui/non */
	BINAIRE	mod;				/* numero du module */
	BOOL		forward;			/* declaration forward oui/non */
	BOOL		util;				/* vrai si la procedure a ete utilise */
	BOOL		implemented;	/* True if a Procedure has been implemented */
	BYTE		*adesc;        /* adresse du descripteur forward */
#ifdef	VERSION_XX
	BINAIRE	ivarb;			/* Variable Descriptor for INDIRECT PROC */
	BINAIRE	vitem;			/* method table entry 			 */
#endif
	BINAIRE	adtc;				/* adresse de la table de correspondance */
	BINAIRE	lgtc;				/* longueur de la table de correspondance */
	BINAIRE	ads;           /* adr relative du descripteur */
	BINAIRE	nba;           /* nombre d'arguments */
									/* dans le cas d'ABAL 1.5 :
									 les 5 bits de poids fort contiennent le type du retour
									 PTTTX : X = 0 sans retour, 1 avec retour
									 TTT : type de base 000 : #, ...
									 P : P=1 type pointeur sur TTT, P=0 type de base
									 */
	BINAIRE	blien;			/* bloc contenant la table des proc appeles */
	BYTE		*adta;			/* adresse types des arguments */
	ExtRef	*lref;			/* liste des references si externe */
	TabProc	*g;				/* pointeur sur suivant gauche */
	TabProc	*d;				/* pointeur sur suivant droite */
/* #AT: 13/09/99 (begin)*/
#ifdef __ATR22__
	TabSymb	* pFormalParams; /* Alternative description of formal parameters */
#endif
/* #AT: 13/09/99 (end)*/
};

/*      Definition de la Table des segments     */
/*      -----------------------------------     */

#define TabSeg struct _TbSg
TabSeg {
        char nom[LGIDENT];      /* nom du segment */
        BINAIRE mod;            /* numero du module */
        BOOL    ext;            /* externe oui/non */
        BOOL    fwd;            /* externe oui/non */
        BINAIRE ads;            /* adr relative du segment dans la table */
	BYTE *adesc;		/* adresse du descripteur forward */
        ExtRef *lref;           /* liste des references si externe */
        BINAIRE adtc;           /* adresse de la table des correspondances */
        BINAIRE lgtc;           /* longueur de la table des correspondances */
        BINAIRE blien;          /* bloc contenant la table des seg/proc appeles */
	BINAIRE adcst;		/* adresse de la table des constantes locales */
	BINAIRE lgcst;		/* longueur de la table des constantes locales */
        BINAIRE num;    /* numero du segment */
                        /* -1 en ver15 : si pas de numero ! */
        BINAIRE adc;    /* adresse du code */
        BINAIRE lgc;    /* longueur du code */
        BINAIRE adv;    /* adresse des variables locales */
        BINAIRE lgv;    /* longueur des variables locales */
        BINAIRE opt;    /* options (RESIDENT / PUBLIC) */
                        /* ver15 :  PAS INLINE  */
        TabSeg  *suiv;  /* descripteur suivant */
};

/*      Definition de la Table des noms de module */
/*      ----------------------------------------- */

#define TabMod struct _TbMd
TabMod {

        char nom[LGNOMPRG];     /* nom du module */
        BINAIRE num;            /* numero du module */
        TabMod  *suiv;          /* descripteur suivant */
};

/*      Definition de la Table des noms de sources */
/*      ------------------------------------------ */

#define TabSrc struct _TbSrc
TabSrc {

        char *nom;		/* nom du source */
        BINAIRE num;            /* numero du module */
        TabSrc  *suiv;          /* descripteur suivant */
};

/*      Definition de la structure d'information sur une variable */
/*      --------------------------------------------------------- */

#define AAAAAVarInf struct _AAAAAVrInf
AAAAAVarInf {
	BOOL local;		/* Local ou Global */
	BOOL etendue;		/* Field=E */
	BOOL virtuelle;		/* Field=no */
	BINAIRE nologique;	/* nologique =no */
	BOOL trou;		/* trou de traduction */
	BOOL arg;		/* arg ou proc */
	BOOL ptr;		/* Pointeur ou non */
	BYTE tptr;		/* Pointeur, ... */
	BYTE type;		/* type */
	BINAIRE longueur;	/* longueur */
	BINAIRE dim1;		/* 1ere dimension */
	BINAIRE dim2;		/* 2eme dimension */
	BINAIRE adredefptr;	/* adresse en cas de redef de zone pointee */
	BINAIRE adrvar;		/* adresse de la variable */
	BINAIRE adrfield;	/* adresse de la variable Field E, NO */
};


/*      Definition d'une table d'etiquettes                     */
/*      -----------------------------------                     */

#define TabEtiq struct _TbEt    /* 'type' : table d'etiquettes */
TabEtiq {
        char pid[LGIDENT];      /* nom/identificateur */
        BINAIRE adef;           /* adr de definition */
        BINAIRE lref;           /* liste de reference */
        TabEtiq *g;             /* pointeur sur suivant gauche */
        TabEtiq *d;             /* pointeur sur suivant droite */
        BYTE    opt;            /* flag d'options : 01234567   */
                                /* 7 : utilisee oui/non */
                                /* 0 : parcourue en liberation oui/non */
};

/*      Definition d'un arbre d'evaluation d'expression conditionnelle  */
/*      --------------------------------------------------------------  */

#define CdMemb struct _C_Memb           /* membre d'une exp. condit.    */
CdMemb {
        BYTE    tmb;    /* type de membre (4:conjonction, 5:relation,
                        /* 0:immediat, 1:constante, 2: variable 3:registre) */
        BYTE    tvar;   /* type de donnee si variable */
        BINAIRE vmb;    /* valeur du membre accorde suivant tmb */
        BINAIRE adr;    /* adr/offset si variable binaire */
        CdMemb  *g,*d;  /* filiation dans l'abre d'evaluation */
};


/*      Definition d'une relocation de procedure dans un module         */
/*      -------------------------------------------------------         */

#define LienRef struct _LiRf
LienRef {
        BOOL    proc_or_seg; /* si procedure TRUE, sinon FALSE */
        union _Ulirf {
                TabProc *dproc; /* pointeur sur descripteur procedure appelee */
                TabSeg  *dseg;  /* pointeur sur descripteur segment appele */
        } desc;
        BINAIRE bloc;   /* numero de bloc de la relocation */
        BINAIRE ofst;   /* offset dans le bloc */
        LienRef *suiv;  /* chainage sur le suivant */
};



/*      Gestion du Type de retour des procedures / nb d'arguments */
/*      --------------------------------------------------------- */

#define ISFCT 0x0800            /* test le bit indiquant si c'est une fonction */
#define MNBARG 0x07FF           /* masque ne gardant que le nombre d'arg */
#define DEPTYPNBA 12            /* Decalage type dans la variable nbarg */

#endif /* _TSYMB_H */

