/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : TCODE.H
 *      Version : 2.1f
 *      Date    : 22/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions du T-code]
 *
 *      15/10/92 :      Debut version 1.5
 *                      Modification de l'entete du traduit
 *                      Modification de la structure de la table des segments
 *	-------------- 2.1c ---------------------------------------
 *	31/05/94 : sauvegarde info dernier segment nomme
 *	------------ 2.1d -------------------------------------------------
 *	22/11/95 : version dediee 2.1
 */

#ifndef _TCODE_H
#define _TCODE_H

/*      Definition de la "map" de mise au point         */
/*      ---------------------------------------         */

#define MapRef struct _MpRf
MapRef {
        char    typ;
        BINAIRE num,sd,sf;
        BYTE    od,of;
        MapRef  *suiv;
};

#define All_Map() (MapRef *) Xmalloc(sizeof(MapRef))
#define Free_Map(p) Xfree((char *) p)

/*      Structure du premier BLOC du fichier traduit -T         */
/*      -----------------------------------------------         */

#define Entete struct t_hd
Entete {
        BYTE    ver;            /* Version Traducteur                    0 */
        BYTE    ind;            /* Indice Traducteur                     1 */
        BYTE    typ;            /* Marqueur ABAL ='2'                    2 */
        BYTE    nom[LGNOMPRG];  /* Nom du fichier source                 3 */
        BYTE    opt;            /* Options de lancement,                18 */
                                /* Bit 0 : Debug(1) / Nodebug(0)           */
                                /* Bit 1 : Clear(1) / Noclear(0)           */
                                /* Bit 2 : Commande initiale(1) ou pas     */
                                /* ver15 :                                 */
                                /* Bit 2 : BAL() / ABAL()                  */
                                /* Bit 3 : PRE_PURGE oui(1) / non(0)       */
                                /* Bit 4 : BAL_PURGE oui(1) / non(0)       */
                                /* Bit 5 : POST_PURGE oui(1) / non(0)      */
                                /* Bit 6 : NO_INIT_ETENDU (1) / INIT_ETENDU (0) */
                                /* Bit 7 : VERIF_PTR oui(1) / non (0)      */
        BYTE    exec;           /* Executable si 0, non exec. sinon     19 */
                                /* (1 = erreurs, 2 = proc ext, 3 = module) */
                                /* ( ver15 : OPTIMISED )                */
        BINAIRE adr_arg;        /* Adr Desc Variable Commande Init      20 */
        BINAIRE adr_tcg;        /* Adresse table constantes globales    22 */
        BINAIRE lng_tcg;        /* Longeur de table                     24 */
        BINAIRE adr_tvg;        /* Adr Table variables Globales         26 */
        BINAIRE lng_tvg;        /* Longueur de table                    28 */
        BINAIRE reserve;        /*                                      30 */
        BINAIRE lng_xtm;        /* Longueur mem etendue                 32 */
        BINAIRE adr_tsg;        /* Adr table des segments               34 */
        BINAIRE lng_tsg;        /* Longeur de table                     36 */
        BINAIRE adr_tpr;        /* Adr table des procedures             38 */
        BINAIRE lng_tpr;        /* Longeur de table                     40 */
        BINAIRE adr_npr;        /* Adr table des noms des procedures    42 */
        BINAIRE l_mxvl;         /* Longeur max tables Var Locales       44 */
        BINAIRE t_mxdl;         /* Taille max de declarations locales   46 */
        BINAIRE adr_xpro;       /* Table des procedures externes        48 */
        BINAIRE adr_xvar;       /* Table des variables externes         50 */
        BINAIRE adr_xcst;       /* Table des constantes externes        52 */
        BINAIRE nb_regs;        /* Nb max de registres utilises         54 */
        BINAIRE nb_files;       /* Nb max de fichier utilises           56 */
        BINAIRE lg_mem;         /* Taille max de la memoire tempo.      58 */
        BINAIRE lg_stack;       /* Taille max de la pile interne        60 */
        BINAIRE secret;         /* codage pour la protection du T-code  62 */
        BINAIRE adr_map;        /* "map" de mise au point               64 */
                                /* ver15 : pas utilise                     */
        BINAIRE adr_lst;        /* fichiers "listes" associes           66 */
                                /* ver15 : listes des fichiers sources     */
        BINAIRE adr_tfu;        /* Adr table fonctions "utilisateur"    68 */
        BINAIRE lng_tfu;        /* et longueur associee                 70 */
        BINAIRE adr_xtfu;       /* Adr table relocation no runtime      72 */
        BINAIRE fact_blk;       /* Facteur de blocage allocations PRL 3 74 */
        BINAIRE adr_ivg;        /* Adresse de l'image des var globales  76 */
        BINAIRE lng_ivg;        /* Longueur de l'image des var globales 78 */
        BINAIRE t_pageme;       /* Taille des pages de memoire etendue  80 */
        BINAIRE nb_pageme;      /* Nombres de buffer de swap pge mem et 82 */
        BINAIRE nivmx_opt;      /* Niveau maximal d'optimisation        84 */
                                /* x01 : STANDARD                          */
                                /* x02 : INLINE PROCEDURE                  */
                                /* x04 : INLINE SEGMENT                    */
				
        BINAIRE adr_nsg;        /* Adresse de la table des noms de seg  86 */
	BINAIRE ext_opt;	/* dans le fichier .at :		86 */
				/* extension des options de traduction	   */
				/* x01 : VALIDPTR			   */
				/* x02 : REMOVEALL			   */
				/* x04 : No Init Field=E		   */
        BINAIRE adr_xsg;        /* Adresse de la table des segments ext 88 */
        BINAIRE adr_xvg;        /* Adresse de la table des var externes 90 */
        BINAIRE adr_nmod;       /* Adresse de la table des noms des mod 92 */
        BINAIRE adr_cvglo;      /* Adresse de la table de corr des var glo 94 */
        BINAIRE adr_cconst;     /* Adresse de la table de corr des const 96 */
        BINAIRE lng_cconst;     /* Long de la table de corr des constant 98 */
        BINAIRE adr_nsrc;       /* Adresse de la table des noms des src 100 */
	BINAIRE adr_etv;	/* Adresse de la table des etiquettes de var 102 */
	BINAIRE adr_xdesc;	/* Adresse de la table des desc externes 104 */
	BINAIRE lng_xdesc;	/* longueur de cette table 106 */
	BINAIRE adr_ncbin;	/* Adresse de la table des noms de cst bin 108 */
	BINAIRE adr_ncbcd;	/* Adresse de la table des noms de cst str/bcd 110 */
	BINAIRE flg_plus;	/* Flag en plus : 0001 : Private variable  112 */
	BINAIRE max_seg;	/* dernier segment nomme : 114 */
};
#endif /* _TCODE_H */

