/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : PARSE1.C
 *      Version : 2.2b
 *      Date    : 28/09/96
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Analyseur syntaxique 1/2]
 *
 */

 /*
 * Mises a jour :
 * ------------
 * 18/07/90 : Mise en conformite avec les versions 1.2e / 1.3a / 1.4a
 * 27/08/90 : Introduction de l'appel a l'ensemble integre 1.4
 * 14/09/90 : Exclusions 1.4a hors de 1.2e
 * 23/10/90 : Introduction de la notion de segment resident, variables
 *            locales publiques (remanentes) + taille du heap = 1 Ko
 * 24/10/90 : Introduction END.SEG
 * 30/10/90 : Commentaires
 * 03/12/90 : Correction pb LDV sur CALL PROC( "a"!"b" , t(1)? )
 * 14/01/91 : Evite double fermeture du parser en cas d'erreur fatale
 * 21/01/91 : Commentaires
 * 07/02/91 : Corrige nom de procedure/numero de segment incorrect
 *            dans le fichier erreur, si erreur sur leur declaration
 * ---------- Sortie 1.2f / 1.3c / 1.4a ------------------------------
 * 12/06/91 : Correction du bug ou une fonction externe void(void)
 *            provoquait une exception, due a une variable automatique
 *            non initialisee
 * 19/08/91 : Admet un nombre d'argument variable nul pour une fonction
 *            externe
 * 21/08/91 : Introduction de l'indicateur de compatibilite BAL (1.5)
 * 14/10/91 : Introduction message "LOOP attendu et non trouve"
 * ---------- Sortie 1.2g / 1.3d --------------------------------------
 * 26/12/91 : Suppression minuscules accentuees dans les sources
 *	---------- Sortie 1.4b ---------------------------------------------
 *	25/05/92 : Pas de backpatch des etiquettes en cas d'erreur
 *            Remise a zero des declarations sur extern proc
 *            Firstreg = 1 pour un module egalement
 *	10/09/92 : Remplacement du no de message en cas d'EXIT sur un segment
 *	---------- version 1.5a --------------------------------------------
 * 14/10/92 : Listes des modifications a ce jour :
 *                      - FORWARD, EXTERN FIELD, EXTERN SEGMENT
 *                      - ordre SEGMENT et PROC indiferent
 *                      - segment dans les modules (SYNTAXE)
 *                      - variables externes (SYNTAXE)
 *                      - nouveau type : PTR, LIKE
 *                      - syntaxe des fonctions
 *	27/10/92 : Creation des instructions de gestions de memoires
 *	07/07/93 : Vidage des points d'ancrage meme si pas de vars globales
 *	15/09/93 : Toujours mettre la table des noms dans le .o et .dbo
 *	07/04/94 : Traitement des segments constants ( CONST IDSEG1%=10 )
 *	24/05/94 : Apres chaque gennew() un init_suivi_registre !
 *	---------- 2.1 c ----------------------------------------------
 *	31/05/94 : sauvegarde du dernier segment nomme (numero) 
 *	20/06/94 : bon message d'erreur sur affectation d'une var inconnue
 *	17/11/94 : passage a 2 Go pour les FIELD=E (reserve et xtm)
 *	------------ 2.1d -------------------------------------------------
 *	21/11/95 : version dediee 2.1
 *	10/08/96 : adaptations Windows
 *	28/09/96 : correction PROC(),D : affecte le bon bit
 *			gestion du EXIT,D et EXIT(valeur),D
 *	------------ 2.2a -------------------------------------------------
 * 17/02/97 : Debut revision 2.2
 * 17/02/97 : Nouveau mot cle : STRUCT
 * 07/03/97 : Prototype de findvar() modifie, reprise de tous les appels
 *				  Fonctions modifiees :	localdcl(), globaldcl()
 * 20/06/97 : dans la table de correspondance du fichier DBG, remplacement de l'offset
 *            par le numero de ligne
 * 02/07/97 : Optimisation ds variables locales, la table des descripteur est generee
 *            en fin de parse du segment ou de la procedure. 
 * 20/10/97 : Modification de l'analyse syntaxique : les dcl locaux et globaux 
 *            peuvent se situer n'importe où: modifications de localdcl() et globaldcl() 
 *            
 * 27/04/98 : Insertion de EVENTDONE
 * 18/12/98 : Correction EXIT
 *
 * 20/04/99 : (#AT) Enhancement ATR 24: Check of types into procedure header 
 * 12/07/99 : (#AT) Bug ATR 30 fixed: Recursive ABAL procedures.
 * 13/09/99 : (#AT) Bug ATR 6 fixed: Prohibit to pass integer parameters to 
 *            procedure if formal parameters has type ptr.
 * 08/10/99 : (#OK) Bug ATR 42 fixed: "segment 0 absent in program".
 * 08/10/99 : (#OK) Bug ATR 43 fixed: With instruction "extern segment a as 1" in module.
 * 11/10/99 : (#SP) Enhancement ATR 23: Local named constants.
 *            New syntax : CONST is now available for declaring local named constants inside proc/segment via defining LOCAL_CONSTANT pragma.
 *            For this purpose the localdcl() was appended to analyse 'CONST' keyword
 * 26/10/99 : (#SP) Bug ATR 3 fixed: Avoid exception when using ARG operator.
 * 24/11/99 : (#OK) Enhancement ATR 20: Add warning message: "Size of argument can't
 *            be verified".
 * 09/12/99 : (#OK) Bug ATR 6 fixed. "Type d'operande incorrect".
 * 17/12/99 : (#OK) Bug ATR 14 fixed: If dcl instruction in the code then debugger go to incorrect line.
 * 27/01/00 : (#BG) Bug ATR 4 fixed. Error message modified in callproc() if procedure unknown. 
 * 09/02/00 : (#OK) Bug fixed in ATR 30 correction.
 * 22/02/00 : (#OK) Bug ATR 44 (EXA 66) fixed. Incorrect cleaning of the table of the global variables
 * 07/03/00 : (#SP) Bug ATR 38 fixed: Crash if 2 procedures with the same name.
 * 07/04/00 : (#OK) Bug ATR 50 fixed: Bug that causes an exception in WALD if instruction "ARG xxx$".
 * 10/05/00 : (#OK) Enhancement ATR 19: Commentaires multilignes.
 * 09/03/00 : (#OK) Bug ATR 48 fixed: Procedure return code in array variable.
 * -------------------------------------------------------------------------
 * 29/02/00 : (#AT) Amelioration EXA-57 - LOAD.GO modifications for ABAL v.2.2a
 * -------------------------------------------------------------------------
 * 11/07/00 : (#OK) ATR 11: Structure.
 * 05/09/00 : (#OK) ALD 7:  #pragma LOCAL_CONSTANT
 * 24/10/00 : (#OK) Bug fixed. Incorrect error message: "Procedure inconnue" instead of "Variable inconnue".
 * 13/12/00 : (#CR) Bug fixed. Corection of correction ATR 24.
 * 29/03/01 : (#OK) Bug EXA-139 fixed. Problem was with #pragma KEYBOARD_FLUSH.
 * 02/04/01 : (#OK) Bug ATR-68 fixed. Label in the beginning of the procedure or segment.
 * 16/08/01 : (#BG) Révision complète du mode verbose.
 * 06/06/02 : (#OK) Bug fixed. Incorrect free memory.
 *	------------ 2.2b -------------------------------------------------
 * 20/11/02 : (#BG) Révision du END.USER.
 */

#include "abal.h"		/* #IJM 06/11/02 */



                /*---------------------------------------------*
                 *      Primitives globales du syntaxique      *
                 *---------------------------------------------*/


#ifdef	VERSION_XX
static void	reset_extern_call();
static void extcall();
#endif


void parser()
{                                               /* parser */
#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nparser():debut");
#endif /* ATR_DEBUG */

        etat_tr = S_DECL;       /* commencer par une phase de declaration */
    /* #OK: 10/05/00 (begin) */
    #ifdef __ATR22__
		     do {
		       lexical();
		     } while (usc.code == FDLN);
    #else
			  lexical();
    #endif
    /* #OK: 10/05/00 (end) */        
        if (usc.code == PROGRAM) {
                notaprog = FALSE;
                debprog = TRUE; /* interdire les #USER */
                programme();
        }
        else if (usc.code == MODULE) {
                notaprog = TRUE;
                debprog = TRUE;
                module();
        }
        else
                erreur(FATALE,ersynt0);

        /* fin de programme ou de module : on doit trouver le END */
        if (usc.code == END) {
		tfdln();
        }
        else {
                erreur(USUAL,ersynt2); sfdln();
        }
        sautpage();

/* #OK: 08/10/99 (begin) */
/* If "segment 0" absent in program then generate error */
	if (!presentSegment0 && !notaprog) 
	{ 
		erreur(USUAL,ersynt49);
		sfdln();
	}
/* #OK: 08/10/99 (end) */


#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nparser():fin");
#endif /* ATR_DEBUG */
}                                               /* parser */



void initparse(v,i,db)

/*      initialisation analyse syntaxique
 */
char v,i;
BOOL db;

{	
/* initparse */
#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ninitparse():debut");
#endif /* ATR_DEBUG */

        debug = db;
        clr = TRUE;             /* clear initial de l'ecran a priori */
        putimpl = FALSE;        /* a ne pas editer pour le moment */
        debprog = FALSE;        /* Program/Module non encore trouve */
        verrue_for = FALSE;     /* pas dans un FOR..NEXT */
			not_a_call_var = TRUE;	
        lienc = GenericNULL(LienRef);

        /* init pour traitement des expressions */
        initexp();

        adsproc = 0;            /* pas de procedure a priori */
        adscst = 0;             /* pas de constante a priori */
        hd_tcode.adr_arg = 0;   /* pas de variable ARG a priori */
        nb_pext = 0;            /* pas de proc externe a priori */

        lg_datas = lg_const = lg_code = 0L;

        deb_tseg = GenericNULL(TabSeg);
        adsseg = 0;             /* pas de segment a priori */
        nb_sext = 0;            /* pas de segment externe a priori */
        hd_tcode.adr_nmod = 0;  /* pas de table des noms de modules a priori */
        hd_tcode.adr_nsrc = 0;  /* pas de table des noms de sources a priori */
        deb_tnmod = GenericNULL(TabMod);

        hd_tcode.ver = (BYTE) v;        /* version du traducteur */
        hd_tcode.ind = (BYTE) i;        /* indice du traducteur */

        /* pas de nom a priori */
        Xstrcpy(&hd_tcode.nom[0],"               ");

        hd_tcode.exec = 0;      /* executable a priori */
        hd_tcode.reserve = 0;
        /* pas de variable locale a priori */
        hd_tcode.l_mxvl = hd_tcode.t_mxdl = 0;
        /* pas de relogeabilite des objets a priori */
        hd_tcode.adr_xpro = hd_tcode.adr_xvar = hd_tcode.adr_xcst = 0;
        /* pas de map de mise au point a priori */
        hd_tcode.adr_map = hd_tcode.adr_lst = 0;

        hd_tcode.adr_tfu = hd_tcode.lng_tfu = 0;
        hd_tcode.adr_xtfu = 0;

        firstreg = 1;   /* 1er registre banalise ... */
        limvregs = 32;  /* limite au nombre de variables 'registre' */
        maxregs = 50;   /* nb max de registres utilisable */
        heapsize = 1024;/* taille du heap par defaut */
        glob_m = 0;     /* Pas de variables globales par defaut */
        opt_oper = 0;

        maxfiles = 64;  /* nb max de fichiers accessibles */
        lgstack = 256;  /* taille de la pile interne */
        lgmem = 2048;   /* taille de la zone de memoire temporaire */

        glseg = 255;    /* hors segment et procedure */
        glproc = GenericNULL(BYTE);

	lentokmax = LGIDENT;	/* longueur max des tokens */

	    /* #OK: 05/09/00 ALD 7 (begin) */
	    /*	hd_tcode.flg_plus=0; /* Par defaut : Variables publiques */ /* commented by #OK */
	    hd_tcode.flg_plus=2; /* Par defaut : Variables publiques & new version ATR for pragma LOCAL_CONSTANT */
	    /* #OK: 05/09/00 ALD 7 (begin) */
        nsegc = FIRSTSEG; /* NBMAXSEG; */

	/* initialisations des traitements pour les variables externes */
        hd_tcode.adr_xvg = 0;
	nbptancr=0;	
	deb_tptancr=GenericNULL(LstAncr);

	/* initialisations des traitements pour les etiquettes de var */
        hd_tcode.adr_etv = 0;
	nbetiqvar=0;
	deb_tetiqvar=GenericNULL(LstEtiqvar);

	/* initialisation des desc externes */
	adsdclextcr = 6; 	/* offset 1er descripteur dans tvarext */
	

        hd_tcode.adr_xdesc = 0;
        hd_tcode.lng_xdesc = 0;
	

	hd_tcode.nb_pageme = 10;
	hd_tcode.t_pageme=0x0800;
	/* Initialisation des options de traduction */
	hd_tcode.ext_opt=0; /* Par defaut : Pas de validation de pointeur */
			    /*		    Pas de liberation totale	  */
			    /* 		    Initialisation des Field=E	  */

	/* Cas de double appel de findvar !!! */
	verrue_findvar = FALSE;
	
	/* #FC+BG 03/12/02 */
//	lreg_pushed = GenericNULL(RegList);
//	lreg_used = GenericNULL(RegList);
	init_contexte_registre(NULL, NULL, NULL);

	if ( aplus_debug ) {
		char x[LGMXNOM];
		strcpy(x,ncurfic);
		forceext(x,x,"atr");
		connect(x);
		strcpy(aplus_info.fichier,ncurfic);
	}

        parsinit = TRUE;

	/* uniquement pour le mode verbose */
	nbSegment = 0;
	nbProcedure = 0;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ninitparse():fin");
#endif /* ATR_DEBUG */
}                               /* initparse */


int finparse(force)
/*      Fin d'analyse syntaxique : mise a jour entete du fichier traduit.
 *      En entree, 'force' vaut :
 *              0 si pas de liberation memoire et ecriture entete
 *              1 si liberation memoire et ecriture entete
 *              2 si liberation memoire et pas ecriture entete
 *      En sortie, retourne :
 *              0 si le programme est executable
 *              1 si le programme a des procedures externes
 *              2 si le resultat est en fait un module
 *         et + 10 si il y a des erreurs dans le fichier traduit
 *            + 8 a partir de la version 1.4
 */
int force;
{                               /* finparse */

        int     flg = 0;
        TabMod  *p1,*q1;
        TabSrc  *p2,*q2;
	BYTE	**pdesc;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nfinparse():debut");
#endif /* ATR_DEBUG */

		if (!parsinit)
                return(0);

        /* Vidage eventuel des references aux variables externes */
        if ((nbptancr != 0) && (force != 2)) {
                hd_tcode.adr_xvg = vid_xvar(NODBG,nbptancr,deb_tptancr);
		if ( hd_tcode.adr_xvg == 0 ) {
			nbptancr = 0; 
			hd_tcode.adr_xdesc = 0;
		    	hd_tcode.lng_xdesc = 0;
		}
        }

        /* vidage table des variables externes dans le fichier traduit */
        if (nbptancr != 0) {
		pdesc = ext_tdesc;
           	hd_tcode.adr_xdesc = vid_tvar(NODBG,nb_ext,FALSE,0,adsdclextcr-6,pdesc);
           	hd_tcode.lng_xdesc = adsdclextcr;
	}

        /* Vidage eventuel des references aux segments externes */
/* 27/09/93 */
        if ((nb_sext != 0) && (force != 2)) {
                hd_tcode.adr_xsg = vid_xseg(NODBG,nb_sext,deb_tseg);
        }

        /* Vidage eventuel de la table des noms de module */
        if ( deb_tnmod != GenericNULL(TabMod) ) {
                hd_tcode.adr_nmod = vid_tnmod(NODBG,deb_tnmod);
        }

        /* Vidage eventuel de la table des noms de sources */
        if ( deb_tnsrc != GenericNULL(TabSrc) ) {
                hd_tcode.adr_nsrc = vid_tnsrc(NODBG,deb_tnsrc);
        }

        if (force != 0) {
                /* Liberation eventuelle de la table des segments */
                /* Liberation eventuelle de la table des noms de modules */
                p1 = deb_tnmod;
                while (p1 != GenericNULL(TabMod)) {
                        q1 = p1->suiv;
                        Free_Tnmod(p1);
                        p1 = q1;
                }
                /* Liberation eventuelle de la table des noms de sources */
                p2 = deb_tnsrc;
                while (p2 != GenericNULL(TabSrc)) {
                        q2 = p2->suiv;
			Xfree(p2->nom);
                        Free_Tnsrc(p2);
                        p2 = q2;
                }
		/* liberation des points d'ancrage */
		libptancr();
        }

        /* Vidage eventuel des references aux procedures externes */
        if ((nb_refpext != 0) && (force != 2)) {
                hd_tcode.adr_xpro = vid_xproc(NODBG,nb_pext,deb_tproc);
        }

        /* Preparation du compte-rendu de retour */
        if (nberr != 0) {
                hd_tcode.exec = 1;
                flg = 8;
                if (notaprog)
                        flg += 2;
                else if (nb_pext != 0)
                        flg += 1;
        }
        else {
             if (notaprog) {
                hd_tcode.exec = 3;      /* signature "module" */
                flg = 2;
             }
             else {
                if ( (hd_tcode.adr_xpro != 0)
	 		|| (hd_tcode.adr_xsg != 0)
			|| (hd_tcode.adr_xdesc != 0) ) {
                        hd_tcode.exec = 2;      /* prog avec proc externes */
						/* ou	avec segment ext   */
						/* ou	avec variable ext  */
                        flg = 1;
                }
             }
        }

        /* Mise a jour options de DEBUG et NOCLR */
        
		/* #OK: 29/03/01 (begin) */
		// hd_tcode.opt = (BYTE) (debug | (clr << 1) | (balcomp << 5)); // commented by #OK
        hd_tcode.opt = (BYTE) (hd_tcode.opt | ((debug | (clr << 1) | (balcomp << 5))));
		/* #OK: 29/03/01 (end) */

        /* Mise a jour des valeurs de l'entete */
        hd_tcode.nb_regs = heapsize;
        hd_tcode.nb_files = maxfiles;
        hd_tcode.lg_stack = lgstack;
        hd_tcode.lg_mem = lgmem;
        hd_tcode.secret = (BINAIRE) lg_code;
        if ((hd_tcode.secret == 0) || (hd_tcode.secret == (BINAIRE) 0xFFFF))
                        hd_tcode.secret = 1;

		hd_tcode.max_seg = nsegc;

        /* Ecriture eventuelle du secteur d'entete NOAT */
        if (force != 2)
                putentete(NOAT);

        /* Ecriture eventuelle du secteur d'entete NODBG */
        if (force != 2)
                putentete(NODBG);

		  /* Statistiques */
		  messch(bid001, "");
  		  messch(mesynt19, "");
        /* Informe l'utilisateur sur le nombre de segments/Procédures */
        messlong(msgvidseg,nbSegment);
        messlong(msgvidproc,nbProcedure);
        /* Informe l'utilisateur sur la taille totale des données/constantes/code prodruit */
        messlong(mesynt7,lg_datas);
        messlong(mesynt8,lg_const);
        messlong(mesynt9,lg_code);

        /* Informe l'utilisateur sur la fin du programme/module */
		  messch(bid001, "");
        if (notaprog)
                messch(mesynt11,&hd_tcode.nom[0]);
        else
                messch(mesynt10,&hd_tcode.nom[0]);
		  messch(bid001, "");

        /* Affiche la taille des variables globales */
        if (Optintegre)
                outbin(IL_3,IC_4+2,glob_m);

	if ( aplus_debug )
		commit();

        /* Signale que la fermeture a deja eu lieu, afin de ne pas la refaire */
        parsinit = FALSE;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nfinparse():fin");
#endif /* ATR_DEBUG */

        return (flg);
}                               /* finparse */

        /*      ---------------------------------       *
         *      Primitives internes du syntaxique       *
         *      ---------------------------------       */

static BINAIRE nb_pro = 0;


static void programme()

/*      traduction d'un programme
 */
{                                               /* programme */
	BOOL fincode=FALSE;
	BYTE **pdesc; 


	adsdcl_glb = 6;
	adsGlobalVarImage = 0;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nprogramme():debut");
#endif /* ATR_DEBUG */

      lexical();
        if (usc.code == CSTR) {
                Xstrncpy(&hd_tcode.nom[0],usc.v.pval,15);

					  /* Informe l'utilisateur sur le début du programme */
					  messch(bid001, "");
					  messch(mesynt17,&hd_tcode.nom[0]);

                /* recherche eventuelle de l'option 'noclr' */
                lexical();
                if (usc.code != FDLN) {
                        if (usc.code != VIG) {
                                erreur(USUAL,ersynt21); sfdln();
                        }
                        else {
                                lexical();
                                if ((usc.code == IDENT) &&
                                    (Xstrcmp(usc.v.pval,"NOCLR") == 0)) {
                                        clr = FALSE; /* pas de clear initial */
                                        tfdln();
                                }
                                else {
                                        erreur(USUAL,ersynt1); sfdln();
                                }
                        }
                }
        }
        else {
                erreur(USUAL,ersynt1); sfdln();
        }

        /* traiter les declarations jusqu'a PROC ,FORWARD, SEGMENT,
                                            EXTERN PROC ou EXTERN SEGMENT
         */
		
			prepdcl();
			nb_dcl_global = 0; /* nombre de variables globales */
			nb_cst_global = 0; /* nombre de constantes globales */ /* #BG 16/08/01 */
			nb_ext = 0;	/* nombres de variables externes */
			lexical();
			globaldcl();


        /* traiter le bloc des Procedures et des Segments
         */
        do {
           switch (usc.code) {
          case EXTERN:
                        /* Procedure ou segment externe */
								lexical(); /* PROC ou SEGMENT */
                        if ( usc.code == PROC ) {
									/* Declaration d'une procedure externe */
									extproc(); nb_pext++;
									}
								else if ( usc.code == SEGMENT ) {
									/* Declaration d'un segment externe */
									extsegment(); nb_sext++;
									} 
#ifdef	VERSION_XX
								else if ( usc.code == CALL ) {
									/* Declaration d'un mechanisme d'indirection */
									extcall();
									}
#endif
								else {
									erreur(USUAL,ersynt1); sfdln();
									}
                        break;
              case FORWARD:
                        /* Procedure avant declaration */
              case PROC:
                        /* Procedure */
                        if ( procedure() )
                                nb_pro++;
                        break;
              case SEGMENT:
                        /* Segment */
                        segment();
                        break;
		
			  case PTR :
			  case FIELD :
			  case LIKE :			  
			  case DCL :
						adrimpl = size_dcl_glb;
						size_dcl = size_dcl_glb;
						globaldcl();
						break;
              case END:
						/*rajout SG With sans endWidth*/
						if (deb_with != GenericNULL(TabWith)) erreur(USUAL,errlex17);
                        fincode = TRUE; /*continue*/ break;

          /* #OK: 10/05/00 (begin) */
          #ifdef __ATR22__
			     case FDLN: break;
          #endif
          /* #OK: 10/05/00 (end) */

              default:
						adrimpl = size_dcl_glb;
						globaldcl();
						
                        /*erreur(USUAL,ersynt4); sfdln();*/
           }
           if ((usc.code!=SEGMENT) && (usc.code!=FORWARD) && (usc.code!=PROC) && (usc.code!=END))
				lexical();
           tstpause();  /* test clavier pour le cas d'une pause operateur */
        }
        while (!fincode);

   /* vidage de la table des variables globales dans le fichier traduit */
   if (nb_dcl_global != 0) {
      pdesc = glb_tdesc;
      hd_tcode.adr_tvg = vid_tvar(NOAT,nb_dcl_global,TRUE,size_dcl_glb,adsdcl_glb-6,pdesc);
      hd_tcode.lng_tvg = adsdcl_glb;


	/* vidage de la table des images des variables globales (initialisee a zero)*/
	  pdesc = glb_tdesc;
	  //hd_tcode.adr_ivg = vid_tInitGlobalVariable (NOAT,nb_dcl_global, pdesc);
      //hd_tcode.lng_ivg = adsGlobalVarImage;
	  vid_tnoms(NODBG,deb_glbsymb); 
	
      glob_m = size_dcl_glb;

		lg_datas += bintolong(size_dcl_glb);
      if (size_xtm != 0L) {
 			hd_tcode.reserve = (BINAIRE) ((unsigned long int)size_xtm >> 20);
			hd_tcode.lng_xtm = (BINAIRE) (((unsigned long int)size_xtm / 16L) + 1);
			if (hd_tcode.lng_xtm == 0)
			hd_tcode.reserve = hd_tcode.reserve + 1;
      } else
      	hd_tcode.lng_xtm = 0;

      lg_datas += size_xtm;
   }
   else    /* pas de variable globale */
     	hd_tcode.adr_tvg = hd_tcode.lng_tvg = hd_tcode.lng_xtm = 0;

		/* Données globales */
		if (!Optintegre)
		{
			messch(bid001, "");
			messch(mesynt20,"");
		}

      /* Informe l'utilisateur sur le nombre de constantes globales déclarées */
      if (!Optintegre)
         messint(mesynt16,nb_cst_global);

      /* Informe l'utilisateur sur le nombre de variables globales déclarées */
      if (!Optintegre)
         messint(mesynt15,nb_dcl_global);

      /* Informe l'utilisateur sur la taille des déclarations globales */
      if (!Optintegre)
	      messint(mesynt0,size_dcl_glb);

      /* Informe l'utilisateur sur la taille des déclarations étendues */
      messlong(mesynt12,size_xtm);

		/* Sauvegarde dans le fichier traduit de la table des procedures */

        if (nb_pro != 0) {

		/* ------------------------------------------------------ */
		/* #IJM : 06/11/02 					  */
		/* Ensure all used forward procedures have been instanced */
		/* ------------------------------------------------------ */
		if ( checkforward() != 0 ) { return; }

		hd_tcode.adr_tpr = vid_tproc(NOAT,adsproc,pr_tdesc);
		hd_tcode.lng_tpr = adsproc;
		/* si debug ou proc externe ou forward non resolu */
		if ((debug) || (nb_pext != 0) || nb_forward )
			/* vider aussi la table des noms */
			hd_tcode.adr_npr = vid_nomspr(NODBG,nb_pro,deb_tproc);
		else
			hd_tcode.adr_npr = 0;
        }
        else
             hd_tcode.adr_tpr = hd_tcode.lng_tpr = hd_tcode.adr_npr = 0;

        /* Sauvegarde dans le fichier traduit de la table des segments */

        if (deb_tseg != GenericNULL(TabSeg)) {
        	hd_tcode.adr_tsg = vid_tseg(NOAT,&adsseg,seg_tdesc);
		hd_tcode.lng_tsg = adsseg +2;	
        	hd_tcode.adr_nsg = vid_nomseg(NODBG,nb_seg,deb_tseg);
        } else
         hd_tcode.adr_tsg = hd_tcode.lng_tsg = 0;

        /* Sauvegarde dans le fichier traduit de la table des constantes */
        if (adscst != 0) {
        	hd_tcode.adr_tcg = vid_tcst(NOAT,adscst,cst_tdesc);
        	hd_tcode.lng_tcg = adscst;
        }
        else    /* pas de constante */
		hd_tcode.adr_tcg = hd_tcode.lng_tcg = 0;

        lg_const = bintolong(adscst);

        /* Sauvegarde dans le fichier traduit de la table des run-times */
        if (nortusr != 0) {
                hd_tcode.adr_tfu = vid_tusr(NOAT,&hd_tcode.lng_tfu);
        }

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nprogramme():fin");
#endif /* ATR_DEBUG */

}                                       /* programme */


static void module()
{                                       /* module */
        BOOL fincode=FALSE;
		BYTE **pdesc;

 		adsdcl_glb = 6;

		adsGlobalVarImage = 0;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nmodule():debut");
#endif /* ATR_DEBUG */

        /* Controle les options de traduction :
         *      - optimisation : interdite avant 1.4
         *                       autorisee mais sans effet dans 1.4
         */
        lexical();
        if (usc.code == CSTR) {
              Xstrncpy(&hd_tcode.nom[0],usc.v.pval,15);

				  /* Informe l'utilisateur sur le début du module */
				  messch(bid001, "");
				  messch(mesynt18,&hd_tcode.nom[0]);

				  tfdln();
        }
        else {
                erreur(USUAL,ersynt1); sfdln();
        } 
        clr = FALSE;    /* pas de clear ecran pour un module */

	firstreg = 1;

		
        /* traiter les declarations jusqu'a PROC , FORWARD ou SEGMENT */
		prepdcl();
		nb_dcl_global = 0; /* nombre de variables globales */
		nb_cst_global = 0; /* nombre de constantes globales */ /* #BG 16/08/01 */
		nb_ext = 0;	/* nombres de variables externes */
		lexical();
		globaldcl();
		//if ((usc.code == PROC) || (usc.code == FORWARD) || (usc.code == SEGMENT))

        do {
           switch (usc.code) {
              case EXTERN:
                        /* Procedure ou segment externe */
                        lexical(); /* PROC ou SEGMENT */
                        if ( usc.code == PROC ) {
                                /* Declaration d'une procedure externe */
                                extproc(); nb_pext++;
                        } else {
                        if ( usc.code == SEGMENT ) {
                                /* Declaration d'un segment externe */
                                extsegment(); nb_sext++;
                        } else {
                                erreur(USUAL,ersynt1); sfdln();
                        }}
                        break;
              case FORWARD:
                        /* Procedure avant declaration */
              case PROC:
                        /* Procedure */
                        if ( procedure() )
                                nb_pro++;
                        break;
              case SEGMENT:
                        /* Segment */
                        segment();
                        break;

				case PTR :
				case FIELD :
				case LIKE :			  
				case DCL :
						adrimpl = size_dcl_glb;
						size_dcl = size_dcl_glb;
						globaldcl();
						break;

              case END:
						/*rajout SG With sans endWidth*/
						if (deb_with != GenericNULL(TabWith)) erreur(USUAL,errlex17);

                        fincode = TRUE; continue;
              default:
						adrimpl = size_dcl_glb;
						globaldcl();

                        /*erreur(USUAL,ersynt4); sfdln();*/
           }
			if ((usc.code!=SEGMENT) && (usc.code!=FORWARD) && 
				(usc.code!=PROC) && (usc.code!=END)) 
				lexical();

           tstpause();  /* test clavier pour le cas d'une pause operateur */
        }
        while (!fincode);

		/* SG 12/06/98*/
         /* vidage table des variables globales dans le fichier traduit */
   if (nb_dcl_global != 0) {
      pdesc = glb_tdesc;
      hd_tcode.adr_tvg = vid_tvar(NOAT,nb_dcl_global,TRUE,size_dcl_glb,adsdcl_glb-6,pdesc);
      hd_tcode.lng_tvg = adsdcl_glb;


	/* vidage de la table des images des variables globales (initialisee a zero)*/
	  pdesc = glb_tdesc;
	  vid_tnoms(NODBG,deb_glbsymb); 
	
		glob_m = size_dcl_glb;

		lg_datas += bintolong(size_dcl_glb /* #BG 16/08/01 size_dcl*/);
		if (size_xtm != 0L) {
 			hd_tcode.reserve = (BINAIRE) ((unsigned long int)size_xtm >> 20);
			hd_tcode.lng_xtm = (BINAIRE) (((unsigned long int)size_xtm / 16L) + 1);
			if (hd_tcode.lng_xtm == 0)
			hd_tcode.reserve = hd_tcode.reserve + 1;
		} else
			hd_tcode.lng_xtm = 0;


      lg_datas += size_xtm;

   }
   else    /* pas de variable globale */
     	hd_tcode.adr_tvg = hd_tcode.lng_tvg = hd_tcode.lng_xtm = 0;
   /* SG end */

		/* Données globales */
		if (!Optintegre)
		{
			messch(bid001, "");
			messch(mesynt20,"");
		}

		/* Informe l'utilisateur sur le nombre de constantes globales déclarées */
		if (!Optintegre)
			messint(mesynt16,nb_cst_global);

		/* Informe l'utilisateur sur le nombre de variables globales déclarées */
		if (!Optintegre)
			messint(mesynt15,nb_dcl_global);

		/* Informe l'utilisateur sur la taille des déclarations globales */
		if (!Optintegre)
			messint(mesynt0,size_dcl_glb /*#BG 16/08/01 size_dcl*/);

		/* Informe l'utilisateur sur la taille des déclarations étendues */
		messlong(mesynt12,size_xtm);

		/* Sauvegarde dans le fichier traduit de la table des procedures */

        if (nb_pro != 0) {
		/* ------------------------------------------------------ */
		/* #IJM : 06/11/02 					  */
		/* Ensure all used forward procedures have been instanced */
		/* ------------------------------------------------------ */
		if ( checkforward() != 0 ) { return; }

		hd_tcode.adr_tpr = vid_tproc(NOAT,adsproc,pr_tdesc);
      		hd_tcode.lng_tpr = adsproc;
      		hd_tcode.adr_npr = vid_nomspr(NODBG,nb_pro,deb_tproc);
        }
        else
             hd_tcode.adr_tpr = hd_tcode.lng_tpr = hd_tcode.adr_npr = 0;

        /* Sauvegarde dans le fichier traduit de la table des segments */
/* Attention !!!
   Penser a ajouter les infos de relogeabilite des noms de segment et
   numero de segment et table des segments et procedures appeles et des variables !!!
*/
        if (nb_seg != 0) {
        	hd_tcode.adr_tsg = vid_tseg(NOAT,&adsseg,seg_tdesc);
		hd_tcode.lng_tsg = adsseg + 2;
        	hd_tcode.adr_nsg = vid_nomseg(NODBG,nb_seg,deb_tseg);
        } else {
        	hd_tcode.adr_tsg = hd_tcode.lng_tsg = 0;
        }

        /* Sauvegarde dans le fichier traduit de la table des constantes */
        if (adscst != 0) {
        	hd_tcode.adr_tcg = vid_tcst(NOAT,adscst,cst_tdesc);
        	hd_tcode.lng_tcg = adscst;
        }
        else    /* pas de constante */
        	hd_tcode.adr_tcg = hd_tcode.lng_tcg = 0;

        lg_const = bintolong(adscst);

        /* vidage tables de relogeabilite des objets globaux */

        if (TvarRef != GenericNULL(RelRef))
                hd_tcode.adr_xvar = vid_xobj(NODBG,TvarRef);

        if (TcstRef != GenericNULL(RelRef))
                hd_tcode.adr_xcst = vid_xobj(NODBG,TcstRef);

        /* Sauvegarde dans le fichier traduit de la table des run-times */

        if (nortusr != 0) {
                hd_tcode.adr_tfu = vid_tusr(NOAT,&hd_tcode.lng_tfu);
        }

        /* vidage de la table de relogeabilite des numero de RT
           dans le traduit */

        if (TusrRef != GenericNULL(TabuRef))
                hd_tcode.adr_xtfu = vid_xuref(NODBG,TusrRef);


#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nmodule():fin");
#endif /* ATR_DEBUG */
}                                       /* module */


/*
 *   Traitement des procedures et des segments
 *---------------------------------------------------*/

#ifdef	VERSION_XX
struct	indirection_control {
	BINAIRE	variable;
	BINAIRE item;
	BINAIRE limit;
	};
static struct indirection_control ExternCall = { 0,0,0 };	
#endif


#ifdef	VERSION_XX

static void	reset_extern_call()
{
	ExternCall.variable = 0;
	ExternCall.item = 0;
	ExternCall.limit= 0;
	return;
}

static void extcall()
/*      traduction d'une declaration de mechansim d'indirection
 */
{                                       /* extcall */
	BYTE	*	advar=(BYTE *) 0;
	BINAIRE		l=0;
	BINAIRE		extra=0;

	lexical();
        if (usc.code == END ) {
		reset_extern_call();
		sfdln();
		}
 	else if (usc.code != IDENT) {
		reset_extern_call();
                erreur(USUAL,ersynt6); sfdln();
        	}
	else	{
		/* EXTERNAL CALL <vname> */
		/* --------------------- */
		reset_extern_call();
                if (!( advar = findvar(usc.v.pval, GenericNULL(BYTE), &ExternCall.variable, GenericNULL(TabSymb *),TRUE) )) {
	                erreur(USUAL,ersynt6); sfdln();
	        	}
		else	{
			/* Check type, size and get limits */
			if ((!( *advar & PRIMARY_INDEX ))  
			||  (( *advar & VTYPE_ISOL ) != VTYPE_STRING)) {
				reset_extern_call();
		                erreur(USUAL,ersynt31); 
				sfdln();
				return;
		        	}
			if (!( *(advar+1) & 0x00FF) )
				extra = 6;
			else	extra = 8;

			ExternCall.limit = (( *(advar+extra) & 0x00FF ) | (( *(advar+extra+1) & 0x00FF ) << 8));
			ExternCall.item  = 1;

			/* get explicite start value */
			/* ------------------------- */
			lexical();
		 	if (usc.code == PAG ) {
				/* get value */
				/* --------- */
				lexical();
                                if (recbincst(&l)) {
					/* constante numerique entiere 	*/
					if ((ExternCall.item = l) > ExternCall.limit) {
						reset_extern_call();
				                erreur(USUAL,ersynt4); 
				        	}
					else	{
						/* get right brace 		*/
						lexical();
					 	if (usc.code != PAD ) {
							reset_extern_call();
					                erreur(USUAL,ersynt20);
							}
						}
					}
				else	{
					reset_extern_call();
					erreur(USUAL,ersynt42);
					}
				}
			else if ( usc.code != FDLN ) {
				reset_extern_call();
		                erreur(USUAL,ersynt19);	
				}
			sfdln();
			}
	        }
	return;
}					/* extcall */
#endif


static void extproc()

/*      traduction d'une declaration de procedure externe
 */
{                                       /* extproc */
        char    nom[LGIDENT];
        BINAIRE nbargs = 0;
        BYTE    targs[MXARGS];
        BINAIRE nmod;

#ifdef	VERSION_XX
	BINAIRE	ecv=0;
	BINAIRE	eci=0;
#endif

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nextproc():debut");
#endif /* ATR_DEBUG */

/* #OK: 22/02/00 (begin) */
/*prepdcl(); Commented by #OK */
/* #OK: 22/02/00 (end) */

        /* recuperer le nom de la procedure et voir si deja declaree */
        lexical();
        if (usc.code != IDENT) {
                erreur(USUAL,ersynt1); sfdln();
        }
        else {
                Xstrcpy(nom,usc.v.pval);

					/* traiter les eventuels arguments */
                nbargs = newargs(0,&targs[0],&nmod);
					 /* Completer avec la description des membres des structures */
					 complete_dcl(deb_lclsymb); /*BUG!!!!*/

                if (findproc(nmod, nom) != GenericNULL(TabProc)) {
                        erreur(USUAL,ersynt15); sfdln();
                }

			      /* Informe l'utilisateur sur le nom de la procedure externe en cours */
					 messch(bid001, "");
                messch(mesynt13,nom);
        }

#ifdef	VERSION_XX
	if ((ecv = ExternCall.variable) != 0) {
		if ( ExternCall.item <= ExternCall.limit )
			eci = ExternCall.item++;
		else	{
			ecv = 0;
                        erreur(USUAL,ersynt11); sfdln();
			}
		}
#endif

        /* inserer la procedure dans la table */
        newproc(nom,TRUE,FALSE,0,0,0,0,nbargs,targs,0,nmod,GenericNULL(TabProc *),&nb_forward,TRUE,GenericNULL(BOOL)
#ifdef VERSION_XX
		,ecv,eci
		/* these two are provided by external indirect syntax */
#endif
		);

        freelocal();

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nextproc():fin");
#endif /* ATR_DEBUG */

}                                       /* extproc */


static BOOL forward()
{
        char    nom[LGIDENT];
        BINAIRE nbargs = 0;
        BYTE    targs[MXARGS];
		  BINAIRE nmod;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nforward():debut");
#endif /* ATR_DEBUG */

        /* verifier le mot cle PROC */
        lexical();
        if (usc.code != PROC) {
                erreur(USUAL,ersynt1); sfdln();
        }
        /* recuperer le nom de la procedure et voir si deja declaree */
        lexical();
        if (usc.code != IDENT) {
                erreur(USUAL,ersynt1); sfdln();
        }
        else {
                Xstrcpy(nom,usc.v.pval);
                if (findproc(0,usc.v.pval) != GenericNULL(TabProc)) {
                        erreur(USUAL,ersynt15); sfdln();
                }
                else {
							/* traiter les eventuels arguments */
                     nbargs = newargs(2,&targs[0],&nmod);
					 		/* Completer avec la description des membres des structures */
					 		nbargs += complete_dcl(deb_lclsymb);
                }
                messch(mesynt3,nom);

		/* incrementation du nombre de forward non resolu */
		nb_forward++;
        }

        /* inserer la procedure dans la table */

        newproc(nom,FALSE,TRUE,0,0,0,0,nbargs,targs,0,nmod,GenericNULL(TabProc *),&nb_forward,TRUE,GenericNULL(BOOL)
#ifdef VERSION_XX
		,0,0 /* these two are used by external indirect syntax */
#endif
		);	

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nforward():debut");
#endif /* ATR_DEBUG */

        return(TRUE);

}       /* forward */


#ifdef __ATR22__
/* #AT: 13/09/99 (begin)*/

/* Analog of All_Symb */
#define ALLOC_TABSYMB_ITM (TabSymb *) XNmalloc("Symb",sizeof(TabSymb))
/* Analog of Free_Symb */
#define FREE_TABSYMB_ITM(p) Xfree((char *) p)

/* Analog of All_Ref */
#define ALLOC_EXTREF_ITM (ExtRef *) XNmalloc("Ref",sizeof(ExtRef))
/* Analog of Free_Ref */
#define FREE_EXTREF_ITM(p) Xfree((char *) p)

/* Analog of All_Type */
#define ALLOC_TYPE_ITM (Type *) XNmalloc("Type",sizeof(Type))
/* Analog of Free_Type */
#define FREE_TYPE_ITM(p) Xfree((char *) p)


void MakeTabSymbItmCopy(TabSymb * pDst,TabSymb * pSrc)
{
	memcpy((char *)pDst,(char *)pSrc,sizeof(TabSymb));
	pDst->d = GenericNULL(TabSymb);
	if (pSrc->lref) {
		pDst->lref = ALLOC_EXTREF_ITM;
		memcpy(pDst->lref,pSrc->lref,sizeof(ExtRef));
		}
		if (pSrc->type) {
		pDst->type = ALLOC_TYPE_ITM;
		memcpy(pDst->type,pSrc->type,sizeof(Type));
		} 
}


void FillFormalParamsField(TabProc * pTabProcItm)
// We need fill new field of TabProc structure named pFormalParams
{
	TabSymb * pTabSymbItm, * pNextParam;
	/* #OK: (begin) 09/12/99 */
	/* if (!pTabProcItm || !deb_lclsymb) return; COMMENTED BY OK */
	/* pTabSymbItm = deb_lclsymb;                COMMENTED BY OK */	
	if (!pTabProcItm || !old_deb_lclsymb) return; 	
	pTabSymbItm = old_deb_lclsymb;                
	/* #OK: (end) 09/12/99 */
	pTabProcItm->pFormalParams = pNextParam = ALLOC_TABSYMB_ITM;
	for(;;) {		
		MakeTabSymbItmCopy(pNextParam,pTabSymbItm);		
		if (!pTabSymbItm->d) break;		
		pNextParam->d = ALLOC_TABSYMB_ITM;		
		pNextParam = pNextParam->d;		
		pTabSymbItm = pTabSymbItm->d;
	} 
    /* #OK: 09/12/99 (begin) */	

	/* #OK: 06/06/02 (begin) */	
	/* Incorrect free memory.
    #ifndef prologue
	if (new_deb_lclsymb) 
		 FREE_TABSYMB_ITM(new_deb_lclsymb);	
	#endif
	*/
	/* #OK: 06/06/02 (end) */	

	while (old_deb_lclsymb) 
	{		
		new_deb_lclsymb = old_deb_lclsymb->d; // go to next element		
		#ifndef prologue
		if (old_deb_lclsymb) 
			 FREE_TABSYMB_ITM(old_deb_lclsymb);    // free		
        #endif
		old_deb_lclsymb = new_deb_lclsymb;
	}	

	/* #OK: 06/06/02 (begin) */	
	/* Incorrect free memory.
    #ifndef prologue
	if (new_deb_lclsymb) 
		 FREE_TABSYMB_ITM(new_deb_lclsymb);	
	#endif
	*/
	/* #OK: 06/06/02 (end) */	

    /* #OK: 09/12/99 (end) */
}

/* #AT: 13/09/99 (end)*/
#endif

static BOOL procedure()

/*      traduction d'une procedure
 */
{                                       /* procedure */
	char    	nom[LGIDENT];
	BINAIRE 	nbargs = 0, nbargs_struct = 0;
	BYTE    	targs[MXARGS], *pcode;
	BINAIRE	adrcode, adrtvar, lgtvar, blocl, optres, nmod;
	int		cerr=nberr;
	BOOL		res=TRUE;  /* resultat FALSE si Corps d'un FORWARD */
	TabProc 	*descp; /* adresse du descripteur de procedure deja declaree par Forward */
	BYTE 		**pdesc;
	long int	svadrimpl;
	BINAIRE	svsize_dcl;
	BOOL		fwd;
/* #AT: 12/07/99 (begin)*/
	BOOL boolSetAds;
/* #AT: 12/07/99 (end)*/
/* #SP: 07/03/00 (begin) */
   BOOL bProcAlreadyExists=FALSE;
/* #SP: 07/03/00 (end) */
/* #OK: 09/02/00 (begin)*/
	BINAIRE saveAdsproc;
/* #OK: 09/02/00 (end)*/

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nprocedure():debut");
#endif /* ATR_DEBUG */

	nb_dcl_local = 0;
	nb_cst_local = 0;	/* #BG 16/08/01 */

	optres = 0x00;	/* Option par defaut */

	if ( usc.code == FORWARD )
         	return(forward());

	/* Preparation et initialisations diverses. On va trouver :
	*      - un nom de procedure
	*      - d'eventuels arguments (variables locales)
	*      - d'autres eventuelles declarations locales
	*      - un eventuel corps de procedure
	*      - d'eventuelles DATA (locales)
	*      - une directive ENDPROC
	*/ 
	newmap('P',adsproc);            /* cree une map de mise au point */
	etspe = 0;                      /* reset des etiquettes internes */
	nbre_datas = 0;                 /* pas de DATA a priori */
	use_datas = FALSE;
	prepdcl();                      /* prepare la gestion des locales */

	/* Recupere le nom de la procedure et voit si elle
	* est deja declaree
	*/
	lexical();
	if (usc.code != IDENT) {
         	erreur(USUAL,ersynt1);
         	sfdln();
	}
	else {
		Xstrcpy(nom,usc.v.pval);
		if ( (descp = findproc(0,usc.v.pval)) != GenericNULL(TabProc)) {
		/* Traitement lie a une procedure declaree en FORWARD */
      	if ( ! descp->forward ) {
          /* #SP: 07/03/00 (begin) */
          bProcAlreadyExists=TRUE;
          /* #SP: 07/03/00 (end) */
          	erreur(USUAL,ersynt15); sfdln();
      	}
			else {
            res = FALSE;

	         /* Traitement des arguments eventuels */
            nbargs = newargs(1,&targs[0],&nmod);
				/* Completer avec la description des membres	des structures */
				nbargs_struct = complete_dcl(deb_lclsymb);

				if (optimise_tables)
					nb_dcl_local+=nbargs & 0x07FF;
      	}
		}
		else {
		/* Traitement des arguments eventuels */
		nbargs = newargs(1,&targs[0],&nmod);
		/* Completer avec la description des membres des structures */
		nbargs_struct = complete_dcl(deb_lclsymb);

		/* SG170798 nb_dcl_local n'était pas à jour quand il y avait optimisation (les paramètres de
		la procédure doivent obligatoirement être présent dans le .at)*/
		if (optimise_tables)
			nb_dcl_local+=nbargs & 0x07FF;
		}

      /* Informe l'utilisateur sur le nom de la procedure en cours */
      messch(bid001, "");
		messch(mesynt3,nom);
		glproc = nom;           /* pour fichier erreurs */
	}

	if ( usc.code == VIG ) {
		lexical();
		if ( (usc.code == IDENT) && (Xstrlen(usc.v.pval) == 1)
			&& (*usc.v.pval == 'D') ) {
			/* La procedure est a chargement differe */
			optres = 0x08;
		} else {
			/* Message : syntaxe incorrecte */
			erreur(USUAL,ersynt1); sfdln();
		}
	}

   /* Traitement des eventuelles declarations locales */
   etat_tr = S_PARS;

	/* Dans le cas d'une optimisation des tables, les donnees membres des
		structures passees en parametres ne sont pas comptabilisees */
	if (optimise_tables)
		nbargs_struct = 0;

	if (Optintegre) outbin(IL_3,IC_4+2,0);

/* #SP: 11/10/99 (begin)*/
#ifdef __ATR22__
	initlcst();
#endif
/* #SP: 11/10/99 (end)*/

	/* #OK: 02/04/01 (begin)*/	
	beginProcOrSegm = TRUE; 
	/* #OK: 02/04/01 (end)*/	

	debut_instruction(); //SG 171097
    localdcl(FALSE,nbargs+nbargs_struct,&optres, TRUE);

	/* #SP: 11/10/99 (begin)*/
	beginProcOrSegm = FALSE; 
	/* #OK: 02/04/01 (end)*/	

	/* Initialisation des tables des constantes locales */
/* #SP: 11/10/99 (begin)*/
#ifndef __ATR22__
	initlcst();
#endif
/* #SP: 11/10/99 (end)*/
   /* Traiter les instructions de la procedure :
   *      - prendre un nouveau bloc dans le traduit
   *      - inserer la procedure dans la table
   *      - traiter les instructions
   */
   adrcode = getbloc(NOAT);
	initcode();

	fwd = FALSE;
/* #AT: 12/07/99 (begin)*/
/* It is necessary to set ads field into TabProc structure 
   (for recursive ABAL-procedures) if boolSetAds = TRUE */
   boolSetAds = (descp == (TabProc *)NULL);
/* #AT: 12/07/99 (end)*/

/* #OK: 09/02/00 (begin) */
	saveAdsproc = adsproc;
/* #OK: 09/02/00 (end) */

/* #SP: 07/03/00 (begin) */
	/* Create a new procedure descriptor only in there was no such proc before */
   if (!bProcAlreadyExists) 
/* #SP: 07/03/00 (end)*/
		newproc(nom,FALSE,FALSE,adrcode,0,adrtvar,lgtvar,nbargs,targs,optres,nmod,&descp,&nb_forward,FALSE,&fwd
#ifdef VERSION_XX
		,0,0 /* these two are used by external indirect syntax */
#endif
		);

/* #AT: 12/07/99 (begin)*/
/* #OK: 09/02/00 (begin) */
   /*if (boolSetAds) descp->ads = adsproc;*/
	if (boolSetAds) descp->ads = saveAdsproc; 
/* #OK: 09/02/00 (end) */
/* #AT: 12/07/99 (end)*/

/* #AT: 13/09/99 (begin)*/
#ifdef __ATR22__
   FillFormalParamsField(descp);
#endif
/* #AT: 13/09/99 (end)*/

   lienc = GenericNULL(LienRef);

	svsize_dcl = size_dcl;

	/* Avant la 1ere instruction pas d'EXIT */
	flag_exit = FALSE;

	/* Memorisation du type de retour de la procedure */
	/* 0 : pas de retour sinon : type du retour */
	if ( nbargs & 0x0800 ) {
		curretfct = (nbargs & 0xF800) >> 11; /* Type + Fct */
		flag_exit = FALSE;
	}
	else {
		curretfct = 0;
	}

	/* initialisation de la table de correspondance */
	if ( aplus_debug ) {
		aplus_info.type = 'P';
		strcpy(aplus_info.ident,nom);
	}
	else {
		newtabcor(FALSE, (void *) descp);
	}
	
   while (instruction(FALSE)) {
            debut_instruction();
   }

   /* Traiter les eventuelles DATA de la procedure :
   *      - poser un EXIT
   *      - puis les DATA (qui se terminent sur ENDPROC)
   */
   if (usc.code == DATA) {
		if ( flag_exit == FALSE ) {
			if ( curretfct == 0 ) {
	     		genretp();
			}
			else {
		      	erreur(USUAL,ersynt1);
			}
		}

		ofst_datas = (BINAIRE) adrimpl;
		while (isdata(FALSE)) {
      		debut_instruction();
		}
		if (!use_datas)
     		erreur(WARNING,ersynt43);
	}
   else if (use_datas)
		erreur(WARNING,ersynt44);

   /* Traiter la fin de la procedure :
   *      - ignorer la fin de ligne ENDPROC
   *      - forcer une instruction EXIT, et positionner les DATA
   *      - resoudre les references en avant aux etiquettes
   *      - patcher la longueur du code de la procedure
   */
   tfdln();
	endmap();
	if ( (flag_exit == FALSE) && ( curretfct != 0) ) {
                erreur(USUAL,ersynt1);
	}
	genfincode(FALSE,ofst_datas,nbre_datas);
	resref(adrcode,(BOOL)((nberr == cerr) ? TRUE : FALSE));

   /* Informe l'utilisateur sur le nombre de constantes locales déclarées */
	if (!Optintegre)
	  	messint(mesynt6,nb_cst_local);

   /* Informe l'utilisateur sur le nombre de variables locales déclarées */
	if (!Optintegre)
	  	messint(mesynt1,nb_dcl_local);

   /* Informe l'utilisateur sur la taille des déclarations locales */
   if (!Optintegre)
   	messint(mesynt5,svsize_dcl);

	lg_datas += bintolong(svsize_dcl);

	svadrimpl = adrimpl;
   /* vidage table des variables dans le fichier traduit */
   if (nb_dcl_local != 0) {
      pdesc = lcl_tdesc;
      adrtvar = vid_tvar(NOAT,nb_dcl_local,debug,/*sv*/size_dcl,adsdcl-6,pdesc);
      lgtvar = adsdcl;
      if (debug) { /* vider aussi la table des noms */
            vid_tnoms(NODBG,deb_lclsymb);
      }
	}
	else
		adrtvar = lgtvar = 0;
	adrimpl = svadrimpl;

	pcode = mkprocdesc(descp,fwd,adrcode,0,adrtvar,lgtvar,optres);

	videcode(NOAT);
	bintobyte(pcode,(BINAIRE) adrimpl);

   /* Informe l'utilisateur sur la taille du code local produit */
   if (!Optintegre)
      messint(mesynt2,(BINAIRE) adrimpl);
   else
      outbin(IL_5,IC_4+2,adscst);

   /* Vider la liste des references des procedures appelees
   */
   if (lienc != GenericNULL(LienRef)) {
		blocl = vid_lien(NODBG,TRUE,lienc);
		descp->blien = blocl;
	}
	else {
		descp->blien = 0;
   }

	/* Sauvegarde des infos de la table des constantes locales */
/* #SP: 11/10/99 (begin)*/
#ifndef __ATR22__
	finlcst(0,pcode+6);
#else
	finlcst(0,pcode+6,debug);
#endif
/* #SP: 11/10/99 (end)*/

	/* sauvegarde des infos de debug */
	endtabcor(FALSE);

   librlien();                     /* libere la liste des liens */

   lg_code += adrimpl;
   putimpl = FALSE;                /* plus d'adresse T-code dans la liste */
   freelocal();                    /* liberer les variables locales */

	/* liberation des infos de type sur variable locale de type pointeur */
	LibPSUCTable(PSUC_LOCAL);
	glproc = GenericNULL(BYTE);

	nbProcedure++;
#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nprocedure():fin");
#endif /* ATR_DEBUG */

	return(res);
}                                       /* procedure */


static void extsegment()

/*      traduction d'une declaration de segment externe
 */
{                                       /* extsegment */
        char    nom[LGIDENT];
        BINAIRE numseg=0xFFFF;
        BINAIRE nummod=0xFFFF;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nextsegment():debut");
#endif /* ATR_DEBUG */

        /* recuperer le nom du segment et voir si deja declaree */
        lexical();
        if (usc.code != IDENT) {
                erreur(USUAL,ersynt1); sfdln();
        }
        else {
                Xstrcpy(nom,usc.v.pval);

		/* reconnaissance eventuelle du numero de segment */
		lexical();
		if ( usc.code == AS ) {
			lexical();
			if (!recbincst(&numseg)) {
				erreur(USUAL,ersynt1); sfdln();
			} else {
			  /* #OK: 08/10/99 (begin) */
				if (notaprog)  /* module */
				{
					erreur(USUAL,ersynt3);
					sfdln();
				} else 
			  /* #OK: 08/10/99 (end) */
				lexical();
			}
		}
		/* reconnaissance eventuelle du module */
		if ( inmod(&nummod) ) {
			if ( usc.code != FDLN ) {
				erreur(USUAL,ersynt1); sfdln();
			}
			sfdln();
		}
		/* Ce segment n'existe pas deja ??? */
		 if ( findseg(nummod,nom) != GenericNULL(TabSeg) ) {
					erreur(USUAL,ersynt14); sfdln();
		 }

      /* Informe l'utilisateur sur le nom du segment externe en cours */
		 messch(mesynt14,nom);
        }
        /* inserer le segment dans la table */
        newseg(TRUE,FALSE, nom, numseg, nummod, 0,(BINAIRE) 0, 0, 0, 0, 0, 0, 0, 0, 0);

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nextsegment():fin");
#endif /* ATR_DEBUG */
}                                       /* extsegment */

/* #AT: 29/02/00, EXA-57 (begin)*/
#ifdef __ATR22__
//////////////////////////////
void TreatESEG(BINAIRE binVal)
// Treat ESEG ABAL-operator; only for segment 0.
// binVal means the number of the segment.
{
  BYTE targ[20],bExpectedType = 0;
  BINAIRE varg[20], binRegNumb;
  if (binVal) return;
  lexical();
  if (usc.code != VIG) { lptr--; return;}
//  if (usc.code != VIG) { SET_PUSHBACK("TreatESEG"); return;}
  lexical();
/*  if (!expression(&bExpectedType,&targ[2],&varg[2]))*/
  gboolIsCallProc = TRUE;
  if (!expression(&bExpectedType,targ,varg)){
erreur(USUAL,ersynt1); sfdln();
  }
  gboolIsCallProc = FALSE;
  if (bExpectedType) return SetError(eriof3); // It's valid only for INT8 type
  lptr--;
  putreg( binRegNumb = getreg(),(BINAIRE)targ[0],varg[0]);
  genesc0(F_SLGR); pbyte(0,binRegNumb); adrimpl++;

}
#endif
/* #AT: 29/02/00, EXA-57 (end)*/

static void segment()

/*      traduction d'un segment
 */
{                                       /* segment */
	TabSeg	*s=GenericNULL(TabSeg);
	char    	nom[LGIDENT];
	BOOL    	okidseg=TRUE;
	BINAIRE 	numseg,v;
	BINAIRE 	adrcode, adrtvar, lgtvar;
	int		cerr = nberr;
	BINAIRE 	optres = 0;
	BINAIRE 	blocl; /* ver15 */
	TabSeg 	sdesc;
	BINAIRE 	k=0;
	BYTE 		*ptlcode;
	BYTE 		**pdesc;
	long int	svadrimpl;
	BINAIRE	svsize_dcl;
#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nsegment():debut");
#endif /* ATR_DEBUG */

        /* Recuperation du numero de segment et des caracteristiques
         * de ce segment. A partir de la version 1.4, un segment peut
         * etre declare "resident", et ses donnees locales "publiques"
         */

		nb_dcl_local = 0;
		nb_cst_local = 0;	/* #BG 16/08/01 */

        lexical();
        /* Le numero de segment est-il de nature numerique ??? */
        if (!recbincst(&numseg)) {
                /* identificateur de segment ? */
                if (usc.code == IDENT) {
                        Xstrcpy(nom,usc.v.pval);
                        /* verification de la non existence du segment */
                        if ( ( s=findseg(0xFFFF,nom) ) != GenericNULL(TabSeg) ) {
                                if ( s->fwd != TRUE ) {
                                        erreur(USUAL,ersynt14); sfdln();
                                        okidseg=FALSE;
                                        numseg=0xFFFF;
                                } else {
                                        numseg=s->num;
                                        nb_seg++;
                                }
                        } else {
                                nb_seg++;
                                if ( ! notaprog ) {
                                        numseg=nsegc++; /* --; */
                                } else
                                        numseg=0xFFFF;
                        }
                } else {
                        erreur(USUAL,ersynt1);
                        sfdln();
                        okidseg=FALSE;
                }
        } else {
                if ( ! notaprog )       {
                        /* On accepte les segments de 0 a 254 */
                        if ( numseg > 254 ) {
                                erreur(USUAL,ersynt3); sfdln();
                                okidseg=FALSE;
                        } else {
                                /* Le segment existe-t-il deja ? */
                                if (segexist(numseg)) {
                                        erreur(USUAL,ersynt14); sfdln();
                                        okidseg=FALSE;
                                }
#ifdef unix
				sprintf(nom,"%4d",numseg);
#else
				itoa(numseg,nom,10);
#endif /* unix */
				/* nom[0]='\0';	Xstrcpy(nom,"        "); */
				nb_seg++;
                        }
                } else {
                        erreur(USUAL,ersynt3); sfdln();
                        okidseg=FALSE;
                }
        }

        if ( okidseg == TRUE ) {
                glseg = numseg; /* pour fichier erreurs */
            
					/* #OK: 08/10/99 (begin) */
					if (numseg == 0) presentSegment0 = TRUE;
					/* #OK: 08/10/99 (end) */

                /* Regarde si le segment est resident */
                lexical();
                if (usc.code == VIG) {
                        lexical();

                        if ((usc.code == IDENT) &&
                            (Xstrlen(usc.v.pval) == 1) &&
                            (*usc.v.pval == 'R'))
                                optres |= OPT_RES;
                        else
                                erreur(USUAL,ersynt1);
                        tfdln();
                } else {
                        if (usc.code != FDLN) {
                                erreur(USUAL,ersynt1);
                                tfdln();
                        }
                }
      
		/* Informe l'utilisateur sur le nom du segment en cours */
		messch(bid001, "");
		if ( (numseg != 0xFFFF) && (numseg != (nsegc-1)) )
	      messint(mesynt4,numseg);
		else
			messch(mesynt4,nom);

                /* Remarque : plus de traduction partielle en 1.5 */
        }

        /* Analyse le corps du segment. On trouvera dans l'ordre :
         *      - les eventuelles declarations locales
         *      - les eventuelles instructions du segment
         *      - les eventuelles datas du segment
         * Ces trois zones sont facultatives.
         * Le corps du segment prend fin sur la directive ESEG.
         */

        /* initialisation de la liste des segments et procedures appeles par
                ce segment
        */
        lienc = GenericNULL(LienRef);

        newmap('S',numseg);             /* cree une map de mise au point */
        etat_tr = S_PARS;               /* pret pour instructions */
        etspe = 0;                      /* prepare etiquettes internes */
        nbre_datas = 0;                 /* se prepare aux eventuelles DATA */
        use_datas = FALSE;


        /* Traite les declarations des eventuelles variables locales */
        prepdcl();
		if (Optintegre) outbin(IL_3,IC_4+2,0);

/* #SP: 11/10/99 (begin)*/
#ifdef __ATR22__
		/* initialisation de la table des constantes locales */
		initlcst();
#endif
/* #SP: 11/10/99 (end)*/

		/* #OK: 02/04/01 (begin)*/	
		beginProcOrSegm = TRUE; 
		/* #OK: 02/04/01 (end)*/	

		debut_instruction(); /*SG 171097*/
        localdcl(TRUE,0,&optres,TRUE);

		/* #OK: 02/04/01 (begin)*/	
		beginProcOrSegm = FALSE; 
		/* #OK: 02/04/01 (end)*/	

		
/* #SP: 11/10/99 (begin)*/
#ifndef __ATR22__
		/* initialisation de la table des constantes locales */
		initlcst();
#endif
/* #SP: 11/10/99 (end)*/

	if ( aplus_debug ) {
		aplus_info.type = 'S';
		strcpy(aplus_info.ident,nom);
	} else {
		newtabcor(TRUE,(void *)&sdesc);
	}
	
	initcode();

	svsize_dcl = size_dcl;

        /* Traite les eventuelles instructions du segment :
         * S'il n'y en a pas, on insere un STOP d'office
         */
        adrcode = getbloc(NOAT);            /* prendre un bloc dans le traduit */

        while (instruction(TRUE)) {
              debut_instruction();
        }

        /* Traite les eventuelles directives DATA */
        if (usc.code == DATA) {
                genstop();
                ofst_datas = (BINAIRE) adrimpl;
                while (isdata(TRUE)) {
                        debut_instruction();
                }
                if (!use_datas)
                        erreur(WARNING,ersynt43);
        }
        else if (use_datas)
                erreur(WARNING,ersynt44);

        /* Fin du segment sur ESEG : il faut recuperer le numero (resp nom)
         * de segment et verifier qu'il correspond au numero ( resp nom) passe
         * lors de la declaration du segment .
         */
        lexical();
        if (!recbincst(&v)) {
                if ( usc.code == IDENT ) {
                        if ( Xstrcmp(usc.v.pval, nom) != 0 ) {
                                erreur(USUAL,ersynt3); sfdln();
                        } else
                                tfdln();
                } else {
                        erreur(USUAL,ersynt1); sfdln();
                }
        } else
/* #AT: 29/02/00, EXA-57 (begin)*/
#ifdef __ATR22__
/* COMMENTED BY AT:*/
/*
                if (v != numseg) {
                        erreur(USUAL,ersynt3); sfdln();
                } else
                        tfdln();
*/
            if (v != numseg) { erreur(USUAL,ersynt3); sfdln();} 
//                else { tfdln();}
            else { TreatESEG(v); tfdln();}
#endif
/* #AT: 29/02/00, EXA-57 (end)*/

        endmap();
        /* forcer une instruction STOP et positionner les eventuelles DATA */
        genfincode(TRUE,ofst_datas,nbre_datas);
        /* resoudre les references en avant aux etiquettes */
	resref(adrcode,(BOOL)((nberr == cerr) ? TRUE : FALSE));

	videcode(NOAT);
        /* Vider la liste des references des segments et des procedures appeles
         */
        if (lienc != GenericNULL(LienRef)) {
                blocl = vid_lien(NODBG,FALSE,lienc);
        } else {
                blocl = 0;
        }
        librlien();                     /* libere la liste des liens */

	/* Sauvegarde des infos de la table des constantes locales */

        /* Sauvegarde dans le fichier traduit de la table des constantes */
	/* locales */

/* #SP: 11/10/99 (begin)*/
#ifndef __ATR22__
    if ((ladscst != 0) && (flglcst == TRUE)) {
#else
if ((ladscst != 0)) {
#endif
/* #SP: 11/10/99 (end)*/
		k = vid_tcst(NOAT,ladscst,lcst_tdesc);
	 }
/* #SP: 11/10/99 (begin)*/
#ifndef __ATR22__
	finlcst(k,GenericNULL(BYTE));
#else
	finlcst(k,GenericNULL(BYTE),debug);
#endif
/* #SP: 11/10/99 (end)*/
	
	/* Table de correspondance */
	endtabcor(TRUE);

	lg_datas += bintolong(svsize_dcl);

    /* Informe l'utilisateur sur le nombre de constantes locales déclarées */
	if (!Optintegre)
	  	messint(mesynt6,nb_cst_local);

  /* Informe l'utilisateur sur le nombre de variables locales déclarées */
	if (!Optintegre)
		messint(mesynt1,nb_dcl_local);

   /* Informe l'utilisateur sur la taille des déclarations locales */
   if (!Optintegre)
		messint(mesynt5,svsize_dcl);

   if (bincmp(size_dcl,hd_tcode.t_mxdl) > 0)
      hd_tcode.t_mxdl = svsize_dcl;
   if (bincmp(adsdcl,hd_tcode.l_mxvl) > 0)
      hd_tcode.l_mxvl = adsdcl;

	svadrimpl = adrimpl;
   /* vidage table des variables dans le fichier traduit */
   if (nb_dcl_local != 0) {
      pdesc = lcl_tdesc;
      adrtvar = vid_tvar(NOAT,nb_dcl_local,debug,/*sv*/size_dcl,adsdcl-6,pdesc); //17/10/97
      lgtvar = adsdcl;
      if (debug) { /* vider aussi la table des noms */
            vid_tnoms(NODBG,deb_lclsymb);
      }
	}
	else
		adrtvar = lgtvar = 0;
	adrimpl = svadrimpl;

   /* Insertion de la description du segment dans la table
   * des segments, sauf si une erreur s'est produite dans la
   * traduction du segment */
   if (nberr == cerr) {
            if ( s != GenericNULL(TabSeg) ) {
                  /* C'etait un segment FORWARD */
                  /* Pas de creation de segment juste m a j des infos
                           non renseignees
                  */
                  s->fwd = FALSE;
                  s->mod = 0xFFFF;
                  s->adc = adrcode;
                  s->lgc = (BINAIRE) adrimpl;
                  s->adv = adrtvar;
                  s->lgv = lgtvar;
                  s->opt = optres;
                  s->blien = blocl;
						s->adcst = k;
						s->lgcst = ladscst;
						s->adtc = sdesc.adtc;
						s->lgtc = sdesc.lgtc;
               ptlcode = mksegdesc(s,TRUE,numseg,adrcode,(BINAIRE)adrimpl,adrtvar,lgtvar,k,ladscst,optres);
            } else {
                  newseg(FALSE,FALSE,nom,numseg,0xFFFF,adrcode,(BINAIRE) adrimpl,adrtvar,lgtvar,optres,blocl,k,ladscst,sdesc.adtc,sdesc.lgtc);
            }
   }

   /* Informe l'utilisateur sur la taille du code local produit */
	if (!Optintegre)
      messint(mesynt2,(BINAIRE) adrimpl);
   else
      outbin(IL_5,IC_4+2,adscst);

   lg_code += adrimpl;
   /*      arreter l'edition des adresses d'implantation */
   putimpl = FALSE;

   /* liberation des eventuelles variables locales */
   freelocal();

   glseg = 255;
			

	/* pour verbose uniquement*/
	nbSegment++;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nsegment():fin");
#endif /* ATR_DEBUG */
}                                       /* segment */


static BOOL segexist(nseg)

/*      Recherche de l'existence d'un segment dans la table
 */
BINAIRE nseg;
{                                       /* segexist */
        register TabSeg *p;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nsegexist():debut");
#endif /* ATR_DEBUG */

        p = deb_tseg;
        while (p != GenericNULL(TabSeg)) {
                if (p->num == nseg) return (TRUE);      /* got it !! */
                p = p->suiv;
        }

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nsegexist():fin");
#endif /* ATR_DEBUG */

        return (FALSE);
}                                       /* segexist */

/*
 *   Traitement des declarations
 *---------------------------------*/
static BYTE svdeclext;

/**********************************************************************
 *		Traitement des declarations au niveau local
 *
 *		Modifications :
 *			Structures a partir de la 2.2a.
 *				C'est ici que l'on trouve les mots cle STRUCT/ENDSTRUCT
 *				On peut declarer en global une instance de structure
 **********************************************************************/

static void globaldcl()

/* Traitement des declarations au niveau global */
{
	BINAIRE nb_dcl = 0;
	register BINAIRE nb_cst = 0;
	BOOL findcl = FALSE;
	BOOL isProcOrSeg = FALSE;
	BOOL	bDeclareStruct = FALSE;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nglobaldcl():debut");
#endif /* ATR_DEBUG */

	if (Optintegre)
		messch(msitg6,GenericNULL(char));

	do {
		switch (usc.code) {

			case WHERE:
				/* declaration de variables externes */
				memolex();			/* memorise l'unite lexicale courante */
				lexical();			/* et les suivante a chaque appel de lexical() */
				if (usc.code != PTR) {
					resumelex();	/* restauration des unites lexicales memorisees */
										/* l'unite lexicale courante est la 1ere memorisee */
				} else {
					standardlex();	/* fin de la memorisation */
					goto PTRglobaldcl;
				}
				
			case DCL:
				if (bDeclareStruct) {
					/* Dans la declaration d'une structure */
					newdcl(FALSE,FALSE,TRUE,TRUE);
				}
					/* declaration variable(s) globale(s) */
					/* 2eme para TRUE car DCL !!! */
				else if ( externfld )
					nb_ext += newdcl(TRUE, externfld, FALSE, TRUE);
				else {
					/* #SG */
					nb_dcl += newdcl(TRUE, externfld, FALSE, TRUE);
					size_dcl_glb = size_dcl;
				}
				break;

PTRglobaldcl:

			case PTR:
				if (bDeclareStruct) {
					/* Dans la declaration d'une structure */
					newdcl(FALSE,FALSE,TRUE,FALSE);
				}
					/* declaration variable(s) globale(s) */
					/* 2eme para FALSE car PTR !!! */
				else if ( externfld )
					nb_ext += newdcl(TRUE,externfld,FALSE,FALSE);
				else {
					/* #SG */
					nb_dcl += newdcl(TRUE,externfld,FALSE,FALSE);
					size_dcl_glb = size_dcl; 
				}
				break;

			case ETIQ:
				/* Etiquette de variable */
				/* Valeur : l'adresse d'implantation courante 	*/
				/* dans l'espace de donnee M ou E */
				newetiqvar();
				break;
				
			case CONST:
				/* declaration constante(s) */
				nb_cst += newcst(); 
				break;

			case FIELD:
				if ( externfld ) {
					sfdln();
				} else {
					/* choix d'emplacement des variables / redefinition */
					newfld(TRUE,notaprog);
				}
				break;

			case ARG:
				/* declaration reception commande initiale */
				if (notaprog) {
					/* interdit dans un un module */
					erreur(USUAL,ersynt4); sfdln(); break;
				}
					/* en 1.5 , arg peut creer une nouvelle variable */
				/* #SP: 26/10/99 (begin)*/
				/*dclarg(&nb_dcl); COMMENTED BY SP */
				else {
					BINAIRE		saved_size_dcl=size_dcl;
					BINAIRE		nb_args=0;

					dclarg(&nb_args);
					nb_dcl+=nb_args;
					if (nb_args){
						size_dcl_glb +=(size_dcl - saved_size_dcl);
						nb_dcl_global+=nb_args;	/*nb_dcl;  #OK 07/04/00 */
					}

					/* size_dcl_glb = size_dcl; QUAND ON EST DANS UNE PROC !!! */
				}
				/* #SP: 26/10/99 (end)*/
				break;

			case END:
/*				if ( notaprog == FALSE ) {
					erreur(USUAL,ersynt4); sfdln();
				}
*/
				findcl = TRUE;
				break;

			case EXTERN:
				lexical();
				if ( usc.code == PROC ) {
					/* Declaration d'une procedure externe */
					extproc(); nb_pext++;
					break;
				} else if ( usc.code == SEGMENT ) {
					/* Declaration d'un segment externe */
					extsegment(); nb_sext++;
					break;
				} 
	#ifdef VERSION_XX
				else if ( usc.code == CALL ) {
					/* Declaration d'un mechanisme d'indirection */
					extcall();
					break;
				}
	#endif
				memolex();      /* memorise l'unite lexicale courante */
				if ((usc.code != FIELD) && (usc.code != ETIQ)) {
					resumelex();    /* restauration des unites lexicales memorisees */
					/* l'unite lexicale courante est la 1ere memorisee */
				} else {
					standardlex();  /* fin de la memorisation */
					if ( usc.code == ETIQ ) {
						newptancr();
					} else {
						/* traitement de la declaration de variables externes */
						lexical();
						if ((usc.code == FDLN) && (externfld == TRUE)) {
							/* Restauration de l'etat FIELD=E,M,no */
							declext = svdeclext;
							externfld = FALSE;
						} else {
							if ( externfld == FALSE ) {
								svdeclext = declext;
								externfld = newextfld();
							} else {
								erreur(USUAL,ersynt4); sfdln(); break;
							}
						}
					}
					break;
				}

			case FORWARD:
			case PROC:
			case SEGMENT:
				findcl = TRUE; 
				isProcOrSeg = TRUE;
				continue;

#ifdef __STRUCT__ 	/* Structures */
			case ENDSTRUCT:
			{
				TabStruct *pTabStruct;

				bDeclareStruct = FALSE;
				lexical();

				/* #OK: 11/07/00 (begin) */
				if ((usc.code != FDLN) && (usc.code != VIG)) {
					erreur(USUAL,errfdln); sfdln();
				}
				/* #OK: 11/07/00 (end) */

				/* on calcule la taille globale de la structure */
				pTabStruct = get_last_struct();
				if (pTabStruct == GenericNULL(TabStruct))
					break;
				pTabStruct->l = get_struct_size(pTabStruct);
				if (pTabStruct->l==0) /* structure vide */
				{
					//warning
					erreur(WARNING,ersymb8);

					createEmptyStructure();
					pTabStruct->l = get_struct_size(pTabStruct);
				}
				break;
			}

			case STRUCT:
				/* declaration constante(s) */
				bDeclareStruct = TRUE;
				newstruct();
				break;
#endif

			/* #OK: 10/05/00 (begin) */
#ifdef __ATR22__
			case FDLN: break;
#endif
			/* #OK: 10/05/00 (end) */

			default:
			{
				TabStruct	*pTabStruct;
				BINAIRE		NbrDcl = 0;

				/* On verifie qu'il ne sagit pas d'une structure
				instanciee */
				if ((pTabStruct = findstruct(usc.v.pval)) != GenericNULL(TabStruct)) {
					if (newdcl_struct(TRUE,externfld,bDeclareStruct,pTabStruct,&NbrDcl)) {	
						if (!bDeclareStruct) {
							nb_dcl += NbrDcl;
							size_dcl_glb = size_dcl;
						}
					}
					else
						erreur(USUAL,ersynt4); sfdln();
				}
				else
					erreur(USUAL,ersynt4); sfdln();
			}
		}	// switch

		if ((usc.code != PROC)   && (usc.code != FORWARD) && 
			(usc.code != SEGMENT)&& (usc.code != EXTERN) && 
			(usc.code != END)) 
				lexical(); /*Ajout if*/
		
		tstpause();  /* test clavier pour le cas d'une pause operateur */
	}	// do
	while (!findcl);

	/* vidage table des noms de constante bin et bcd si debug */
	if ( (nb_cst != 0) && (debug) ) {
		/* Constante binaire */
		if ( deb_bincst != GenericNULL(TabSymb) ) {
			hd_tcode.adr_ncbin = vid_tncstbin(NODBG,deb_bincst);
		} else {
			hd_tcode.adr_ncbin = 0;
		}
		/* Constante bcd */
		if ( deb_bcdcst != GenericNULL(TabSymb) ) {
			hd_tcode.adr_ncbcd = vid_tncstbcd(NODBG,deb_bcdcst);
		} else {
			hd_tcode.adr_ncbcd = 0;
		}
	} else {
		hd_tcode.adr_ncbin = 0;
		hd_tcode.adr_ncbcd = 0;
	}

	/* Si non optimisation des tables, le nbr des variable dans
	la table des descripteus est le nbr de variables declarees */
	if (nb_dcl != 0) {
		/*if (!optimise_tables)
		9999 nb_dcl_global = nb_dcl;*/
	}

	/* Vidage eventuel des references aux etiquettes de variables */
	if (nbetiqvar != 0) {
		hd_tcode.adr_etv = vid_etv(NODBG,nbetiqvar,deb_tetiqvar);
		libetiqvar();
	}

	if (Optintegre)
		outlong(IL_4,IC_4,size_xtm);
	/* #BG 16/08/01 Begin */
	/*
	else
		// Informe l'utilisateur sur le nombre de constantes globales déclarées
		messint(mesynt6,nb_cst);
	*/
	nb_cst_global += nb_cst;
	/* #BG 16/08/01 End */

	#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nglobaldcl():fin");
	#endif /* ATR_DEBUG */
}                                       /* globaldcl */

static void dclarg(pnbdcl)
BINAIRE *pnbdcl;
/*      declaration variable de reception commande initiale
 */
{                                       /* dclarg */
        BINAIRE advar;
        BYTE    *adesc;
	

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ndclarg():debut");
#endif /* ATR_DEBUG */

        if (hd_tcode.adr_arg != 0) {
                erreur(USUAL,ersynt5); sfdln(); return;
        }
        lexical();
        if (usc.code != IDENT) {
                erreur(USUAL,ersynt4); sfdln(); return;
        }
        adesc = findvar(usc.v.pval,GenericNULL(BYTE),&advar,GenericNULL(TabSymb *),TRUE);
        if (adesc == GenericNULL(char)) {
                *pnbdcl += newdclarg(TRUE,TRUE,&adesc,&advar);
        } else {
		/* L'argument ne peut pas etre externe !!! */
		if ( advar & IS_EXTERN ) {
	                erreur(USUAL,ersynt4); sfdln(); return;
		}
	}

        /* remarque : la variable est forcement globale si l'on est ici
         * il faut s'assurer qu'elle est en FIELD=M et de type chaine */
	if ( adesc != GenericNULL(BYTE) ) {
        if ( ! IS_TSTR(typdesc(adesc)) || (*(adesc+1) != 0)) {
                erreur(USUAL,ersynt4); sfdln(); return;
        }
	}
        hd_tcode.adr_arg = advar;
        if ( usc.code != FDLN)
                 tfdln();

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ndclarg():fin");
#endif /* ATR_DEBUG */

}                                       /* dclarg */


static void localdcl(seg,nbargs,optres, oldDclLocation)

/**********************************************************************
 *		Traitement des declarations au niveau local
 *		seg			(IN)	Declaration des variables locales a un segment
 *		nbargs		(IN)	Nombre d'arguments
 *		optres
 *		oldDclLocation (IN) Dcl au debut du segment (ou procedure) termines
 *                          par ENDLOC
 *
 *		Modifications :
 *			Structures a partir de la 2.2.
 *				On peut declarer en local une instance de structure
 *			Dcl locaux a n'importe quel endroit 17/10/97
 **********************************************************************/
BOOL    seg;
BINAIRE nbargs;
BINAIRE *optres;
BOOL oldDclLocation;
{                                       /* localdcl */
/* #SP: 11/10/99 (begin)*/
#ifdef __ATR22__
	  register BINAIRE nb_cst = 0;
#endif
/* #SP: 11/10/99 (end)*/
        register BINAIRE nb_dcl;
        BOOL findcl = FALSE;
        long int impladr;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nlocaldcl():debut");
#endif /* ATR_DEBUG */

        /* Remise a zero de la taille des variables locales */
        //if (Optintegre) SG 171097
                //outbin(IL_3,IC_4+2,0);

	/* Masque pour ne pas recuperer le type de retour */

        /*nb_dcl_local = */nb_dcl = nbargs & 0x07FF;
		  //nb_dcl_local += nb_dcl; //SG061298 remove this line
        /* Assure qu'une etiquette definie sans variable locale
         * mais avec arguments pour une procedure sera definie en 0
         */
        impladr = adrimpl;
        adrimpl = 0L;
        //debut_instruction();
        adrimpl = impladr;

		//SG 1811
		//Si le dcl n'est pas dans un field =M
		if (local_niv_field ==0)
			adrimpl = size_dcl;
		
		/* A partir de la version 2.2a, on peut declarer des donnees
			  avec la syntaxe 'Structure MsStructure' */
        if ((usc.code == DCL) || (usc.code == PTR) || (usc.code == FIELD) ||
				(usc.code == ENDLOC) ||
/* #SP: 11/10/99 (begin)*/
#ifdef __ATR22__
				(usc.code == CONST) ||
#endif
/* #SP: 11/10/99 (end)*/
				 (findstruct(usc.v.pval) != GenericNULL(TabStruct))) {

           etat_tr = S_DECL;
           do {
              switch (usc.code) {
                 case DCL:
                        /* declaration variable(s) locale(s) */
                        nb_dcl += newdcl(FALSE,FALSE,FALSE,TRUE); 
						
						break;

                 case PTR:
                        /* declaration variable(s) locale(s) */
                        nb_dcl += newdcl(FALSE,FALSE,FALSE,FALSE); break;

/* #SP: 11/10/99 (begin)*/
#ifdef __ATR22__
             case CONST:
                    nb_cst += new_local_cst();
						  nb_cst_local = nb_cst;
						  break;
#endif
/* #SP: 11/10/99 (end)*/

                 case FIELD:
                        /* choix d'emplacement des variables / redefinition */
                        newfld(FALSE,notaprog); 
						//debut_instruction();
						break;
                 case ENDLOC:
                        etat_tr = S_PARS;
                        findcl = TRUE;

                        /* Traite les variables locales publiques / statiques */
                        lexical();
                        if (usc.code == VIG) {
                                lexical();
                                if ((usc.code == IDENT) &&
                                    (Xstrlen(usc.v.pval) == 1) &&
                                    (*usc.v.pval == 'S'))
                                        (*optres) |= OPT_PUB;
                                else
                                        erreur(USUAL,ersynt1);
                                tfdln();
                        }
                        else {
                                if (usc.code != FDLN) {
                                        erreur(USUAL,ersynt1);
                                        tfdln();
                                }
                        }
						//SG21197
                        adrimpl = 0L;    /* RAZ adr implantation courante */
                        putimpl = debug; /* adresses d'implantation si debug */
						debut_instruction();
                        break;
                 default:
							{
							TabStruct	*pTabStruct;
							BINAIRE		NbrDcl = 0;

							/* On verifie qu'il ne sagit pas d'une structure
								instanciee */
							if ((pTabStruct = findstruct(usc.v.pval)) != GenericNULL(TabStruct)) {
								if (newdcl_struct(FALSE,externfld,FALSE,pTabStruct,&NbrDcl))
									nb_dcl += NbrDcl;
								else
	   	                  erreur(USUAL,ersynt4); sfdln();
							}
							else //end declaration
   	                  //erreur(USUAL,ersynt4); sfdln(); //SG 171097
							{//SG 171097
							etat_tr = S_PARS;
							findcl = TRUE;}
							}
              }
              if ((oldDclLocation)&&(findcl != TRUE)) 
				  debut_instruction();
              tstpause();  /* test clavier pour le cas d'une pause operateur */
           }
           while (!findcl);
        }
        else {                   /* pas de declarations locales */
                adrimpl = 0L;    /* RAZ adr implantation courante */
                putimpl = debug; /* adresses d'implantation si debug */

                /* force mise adresse implantation dans fichier liste */
                ALputimpl = putimpl;
        }
		  /* Si non optimisation des tables, le nbr des variable dans
			  la table des descripteur est le nbr de variables declarees */
        if (nb_dcl != 0) {
		  		if (!optimise_tables)
						nb_dcl_local += nb_dcl;//17/10/97
      		}
      /* Affichage de la taille des variables locales */
      if (Optintegre)
               outbin(IL_3,IC_4+2,size_dcl);

		if (oldDclLocation) 
		{
			adrimpl = 0L;    /*RAZ adr implantation courante*/ 
			putimpl = debug;
		}

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nlocaldcl():fin");
#endif /* ATR_DEBUG */

}                                       /* localdcl */


extern BOOL fldptr;

static void prepdcl()

/*      re-init des variables globales servant a la declaration de donnees
 */
{                                               /* prepdcl */
#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nprepdcl():debut");
#endif /* ATR_DEBUG */

        size_dcl = 0;   /* taille var */
        adrimpl = 0L;   /* adresse implantation courante */
        declext = 0;    /* implantation en memoire par defaut */
        field = FALSE;  /* pas de FIELD en cours */
        adsdcl = 6;     /* offset 1er descripteur dans tvar */

	fldptr = FALSE;
		local_niv_field = 0;
				   
		adrimpl_instr = 0;


#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nprepdcl():fin");
#endif /* ATR_DEBUG */
}                                               /* prepdcl */

/*
 *	Traitement des references en avant aux etiquettes
 *	-------------------------------------------------  */
/*V14C*/
static void resref(a,ok)

/*	en entree a = le numero du bloc de debut des instructions
 *	ok indique si on doit effectuer un back patch ou non
 */
BINAIRE a;
BOOL ok;
{						/* resref */
	TabEtiq *p;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nresref():debut");
#endif /* ATR_DEBUG */

	p = deb_tetiq;
	if (p != GenericNULL(TabEtiq)) {
		resetiq(a,p,ok); deb_tetiq = GenericNULL(TabEtiq);
	}

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nresref():fin");
#endif /* ATR_DEBUG */
}						/* resref */


static void resetiq(b,s,ok)

/*	resolution des references a l'etiquette 'p' dans l'espace
 *	d'instruction commencant au bloc 'b'
 *	l'arbre des etiquettes est libere en cours de route dans le
 *	nouvel algorithme.
 *	Si ok est a TRUE on effectue le back patch, sinon on ne
 *	fait que liberer l'arbre.
 */
BINAIRE b;
TabEtiq *s;
BOOL ok;
{						/* resetiq */
	BINAIRE r;

/*	ANCIEN ALGORITHME : RECURSIF ...
 *	--------------------------------
 *	r = s->lref;
 *	if (r != (BINAIRE) 0xFFFF)
 *	   if (s->adef == (BINAIRE) 0xFFFF)
 *		err2(USUAL,ersynt12,s->pid);
 *	   else 
 *		backres(b,r,s->adef);
 * 	else if ((s->opt == 0) && (s->pid[0] != '$'))
 *		err2(WARNING,ersynt13,s->pid);
 *	if (s->g != GenericNULL(TabEtiq))
 *		resetiq(b,s->g);
 *	if (s->d != GenericNULL(TabEtiq))
 *		resetiq(b,s->d);
 *	tstpause();
 */

/*	NOUVEL ALGORITHME : ITERATIF	*/
/*	----------------------------	*/

	TabEtiq *p,*q,*x;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nresetiq():fin");
#endif /* ATR_DEBUG */

	p = s; q = s->g;
	if (q == GenericNULL(TabEtiq)) {
		q = s->d;
		if (q == GenericNULL(TabEtiq)) {
			r = s->lref;
			if (r != (BINAIRE) 0xFFFF) {
			   if (s->adef == (BINAIRE) 0xFFFF) {
				s->pid[lentokmax-1] = EOSTR;
				err2(USUAL,ersynt12,s->pid);
			   }
			   else {
				if (ok)
					backres(NOAT,b,r,s->adef);
			   }
			}
 			else if ((s->opt == 0) && (s->pid[0] != '$')) {
				s->pid[lentokmax-1] = EOSTR;
				err2(WARNING,ersynt13,s->pid);
			}
			/* liberation au passage */
			Free_Etiq(s);
			return;
		}
		s->d = GenericNULL(TabEtiq);
	}
	s->opt |= (BYTE) 0x0080;	/* flag deja parcouru */
	/* parcours des ss-arbres a partir du noeud courant */
	while (TRUE) {	/* sortie par BREAK */
	   if ((q->g != GenericNULL(TabEtiq)) &&
	       ((q->opt & (BYTE) 0x0080) == 0) ) {
		/* traiter le ss-arbre gauche */
		q->opt |= (BYTE) 0x0080; x = q->g;
		q->g = p; p = q; q = x;
	   }
	   else {	/* traiter l'eventuel ss-arbre droite */
		if (q->d != GenericNULL(TabEtiq)) {
			/* il y en a un !! */
			if ((q->opt & (BYTE) 0x0080) == 0) {
				/* maintenir le chainage */
				q->opt |= (BYTE) 0x0080; q->g = p;
			}
			x = q->d; q->d = GenericNULL(TabEtiq); 
			p = q; q = x;
		}
		else { /* ni gauche ni droite : supprimer cette feuille */
			if (q == s) break;	/* sauf si racine : out ... */
			r = q->lref;
			if (r != (BINAIRE) 0xFFFF) {
			   if (q->adef == (BINAIRE) 0xFFFF) {
				err2(USUAL,ersynt12,q->pid);
			   }
			   else {
				if (ok)
					backres(NOAT,b,r,q->adef);
			   }
			}
 			else if (((q->opt & 1) == 0) && (q->pid[0] != '$')) {
				err2(WARNING,ersynt13,q->pid);
			}
			/* liberation au passage */
			Free_Etiq(q);
			/* et remonter a son pere pour la suite */
			q = p; p = q->g;
		}
	   }
	   tstpause();	/* test clavier pour le cas d'une pause operateur */
	}
	/* fin de l'arbre : on est revenu au noeud initial */
	r = s->lref;
	if (r != (BINAIRE) 0xFFFF) {
	   if (s->adef == (BINAIRE) 0xFFFF) {
		err2(USUAL,ersynt12,s->pid);
	   }
	   else {
		if (ok)
			backres(NOAT,b,r,s->adef);
	   }
	}
	else if (((s->opt & 1) == 0) && (s->pid[0] != '$')) {
		err2(WARNING,ersynt13,s->pid);
	}
	/* liberation au passage */
	Free_Etiq(s);

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nresetiq():fin");
#endif /* ATR_DEBUG */
}						/* resetiq */

/*
 *      Traitement des etiquettes internes
 *      ----------------------------------      */

void cretiq(adr)

/*      creation d'une etiquette a partir de la valeur courante de 'etspe'
 *      cette fonction retourne une chaine de caracteres donnant la valeur
 *      "syntaxique" de l'etiquette a utiliser.
 */
char *adr;
{                                               /* cretiq */
        register char *p;
        register int n;
        char *q,c;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ncretiq():debut");
#endif /* ATR_DEBUG */

        *adr = '$';
        p = q = adr+1; n = etspe++;
        do {
                *p++ = inttocar(n % 10);
        }
        while ((n /= 10) > 0);
        *p = EOSTR;
        while (q < --p) {
                c = *q; *q++ = *p; *p = c;
        }

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ncretiq():fin");
#endif /* ATR_DEBUG */
}                                               /* cretiq */

/*
 *      Traitement des instructions
 *      ---------------------------     */

static BOOL instruction(seg)

/*      traduction d'une instruction de base
 *      retourne TRUE tant que l'instruction n'est pas une fin de module
 *      en entree seg est vrai pour un segment, faux pour une procedure
 */
BOOL seg;
{                                       /* instruction */
        BOOL flag = TRUE;
        BINAIRE advar,vop;
        BYTE *adesc,top;
		BOOL instructionIsDcl = FALSE;

		BINAIRE	sav_libreg;
		RegList*	sav_lreg_used;
		RegList* sav_lreg_pushed;
    
    /* #OK: 11/07/00 (begin) */
		adesc=0;
		/* #OK: 11/07/00 (end) */

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ninstruction():debut");
#endif /* ATR_DEBUG */

        if ( usc.code == FORWARD ) {
#ifdef ver16
                if (seg) {
                        erreur(USUAL,ersynt9); sfdln();
                        return(TRUE);
                } else {
		}
#endif
		if (forward()) nb_pro++;
		lexical();
        }
        if (etat_tr == S_PARS) { /* instruction A.B.A.L. */
           if ((usc.code != REPEAT) && (usc.code != DO) &&
                (usc.code != DATA) && (usc.code != FMT)) {
                        gennew();       /* delimiteur de ligne dans le code */
			if ( aplus_debug ) {
				aplus_info.noligne = (BINAIRE)lgnfic;
				aplus_info.offset = (BINAIRE)adrimpl;
				send(&aplus_info);
			} else {
/* #OK: 11/07/00 (begin) */
/* #OK: 17/12/99 (begin) */
#ifdef __ATR22__
//				if ((usc.code != DCL) && (usc.code != ENDLOC))
            if ((usc.code != DCL) && (usc.code != ENDLOC) && (usc.code != WITH) && (usc.code != ENDWITH))
					/* If dcl instruction or operator WITH in the code then debugger go to incorrect line. */
#endif
/* #OK: 17/12/99 (end) */
/* #OK: 11/07/00 (end) */
					instabcor(seg);
			}
           }

		/* #FC+BG 03/12/02 */
		/*init_suivi_registre();*/
	 	init_contexte_registre(&sav_libreg, &sav_lreg_used, &sav_lreg_pushed);
  
	   if ((usc.code!=PTR)&&(usc.code!=DCL)&&(usc.code!=FIELD)&&(usc.code!=LIKE))
			{	
				//adrimpl = adrimpl_instr;
			}
			else //SG 251197
				if (local_niv_field==0) 
				{
					adrimpl_instr = adrimpl;
					adrimpl = size_dcl; //SG 251197
				}
			// fin modif
           switch (usc.code) {
           case FUSER : argexp = TRUE;
                        callfuser();    /* appel a une fct util. void */
                        argexp = FALSE;
                        break;
           case IDENT:          /* affectation ou appel de fonction */
                adesc = findvar(usc.v.pval,GenericNULL(BYTE),&advar,GenericNULL(TabSymb *),TRUE);
                if ( adesc == GenericNULL(BYTE) ) {
						/*SG 251197 */
						TabStruct	*pTabStruct;
						if ((pTabStruct = findstruct(usc.v.pval)) != GenericNULL(TabStruct))
						{
							if (local_niv_field==0) adrimpl = size_dcl;
							localdcl(TRUE,0, 0, FALSE);
							if (local_niv_field==0) adrimpl = adrimpl_instr;
							instructionIsDcl = TRUE;
						}
						//BINAIRE		NbrDcl = 0;

							/* On verifie qu'il ne sagit pas d'une structure
								instanciee */
						//if ((pTabStruct = findstruct(usc.v.pval)) != GenericNULL(TabStruct)) {
							//if (newdcl_struct(FALSE,externfld,FALSE,pTabStruct,&NbrDcl))
								//nb_dcl += NbrDcl;
						else
						{     
								argexp = TRUE;
								callproc(FALSE);
								argexp = FALSE;
						}
						
				
                } else {
                        if (affectation(adesc,advar))
                           if (usc.code != FDLN) { /* on doit etre en fin de ligne */
                                erreur(USUAL,errfdln); sfdln();
                        }
										
                }
                break;
			
		   case PTR :
		   case FIELD :
		   case LIKE :
		   case DCL :	
					//SG 21/11/97 sauvegarde de l'adresse d'implantation 
					//des instructions 
					//adrimpl_instr = adrimpl;
					if (local_niv_field==0)
						adrimpl = size_dcl;
					localdcl(TRUE,0, 0, FALSE);
					if (local_niv_field==0)
						adrimpl = adrimpl_instr;
					instructionIsDcl = TRUE;
				break;
			
           case GOTO:           /* branchement inconditionnel */
                if (recadr()) { gengoto(usc.v.pval); tfdln(); }
                break;
           case GOSUB:          /* appel de sous-programme */
                if (recadr()) { gengosb(usc.v.pval); tfdln(); }
                break;
           case STOP:           /* fin d'execution */
                genstop(); tfdln();
                break;
           case EVENTDONE:	/* fin d'execution de callback evenement */
                genevdone(); tfdln();
                break;
		   case RETURN:         /* retour de sous-programme */
                genret(); tfdln();
                break;
           case WAIT:           /* suspension de l'execution */
                trfnspe(59); break;
           case PAUSE:          /* suspension apres affichage */
                trpause(); break;
           case OP:             /* test si pret clavier */
                tradop();       break;
           case IF:             /* execution conditionnelle */
                flag = traitif(seg); break;
           case SELECT:         /* execution conditionnelle */
                flag = traitsel(seg); break;
           case DO:             /* iteration perpetuelle */
                flag = trloop(seg); break;
           case FOR:            /* iteration FOR NEXT */
                flag = trfor(seg); break;
           case REPEAT:         /* iteration REPEAT UNTIL */
                flag = trepeat(seg); break;
           case WHILE:          /* iteration WHILE WEND */
                flag = twhile(seg); break;
           case MASK:           /* masque de saisie */
                trfnspe(60); break;
           case ASKATB:         /* saisie de l'atb des ASK */
                trfnspe(81); break;
           case ASKCOLOR:       /* saisie de la couleur de car /fond des ASK*/
                trfnspe(82); break;
           case HOTKEY:         /* saisie de la valeur de HOTKEY */
                trfnspe(73); break;
           case LANG:           /* saisie de la valeur de LANG */
                trfnspe(74); break;
           case INITGLOBAL:     /* initialisation de la table des variables globales */
                trfnspe(76); break;
           case INITLOCAL:      /* initialisation de la table des variables locales */
                trfnspe(77); break;
	   case ATTACH:	/* Fonction non documentee */
		trcreate(95); break;
           case CREATE:         /* allocation d'une liste de pointeurs */
                trcreate(83); break;
           case FORGET:         /* liberation d'une liste de pointeurs */
                trforget(85); break;
	   case DETTACH:	/* Fonction non documentee */
		trforget(96); break;
	   case ALTER:		/* redef de caracteristique pointeur */
		trforget(98); break;
           case REMOVE:         /* liberation d'une liste de pointeurs */
                trforget(84); break;
	   case ERROR:		/* Declenchement d'une erreur */
		trerreur(); break;
           case ASK:            /* saisie de donnees */
                trask(); break;
           case PRINT:          /* edition de donnees */
                trprnt(); break;
           case LDGOSEG:        /* appel de segment */
                if (!seg) {
                        erreur(USUAL,ersynt9); sfdln();
                } else {
			TabSeg *p;

                        lexical();
			if ( is_var_or_seg(TRUE,&p,&top,&vop) ) {
				gensgt(GenericNULL(TabSeg),top,vop);
			} else {
				lexical();
				gensgt(p,top,vop);
			}
			if (usc.code != FDLN) {
				erreur(USUAL,errfdln); sfdln();
			}
                }
                break;
           case RETSEG:         /* retour de segment */
                if (!seg) {
                        erreur(USUAL,ersynt9); sfdln();
                }
                else {
                        genrets(); tfdln();
                }
                break;

           case ENDSEG:         /* fin de segment */
                if (!seg) {
                        erreur(USUAL,ersynt9); sfdln();
                }
                else {
			trfnspe(89); /* LIBSEG ou EDS (END.SEG) */
                }
                break;

           case ENDDPTPROC:	/* dechargement d'une procedure OVL */
                if (seg) {
                        erreur(USUAL,ersynt9); sfdln();
                }
                else {
	                trfnspe(88); /* LIBPROC (END.PROC) */
                }
                break;

			  case ENDUSER:
/* #BG 20/11/02 Révision */
					trfnspe(87);	/* 87 => LIBUSER (END.USER) ds NumFnt[], code A7 */
					break;

           case CALL:           /* appel de procedure */
                argexp = TRUE;
                        callproc(TRUE);
                argexp = FALSE;
                break;

     case EXIT: /*correction SG 18/12/98 */   /* retour de procedure */
                if (seg) {
                        erreur(USUAL,ersynt9); sfdln();
                }
                else {
			/* La procedure retourne-t-elle une valeur ? */
			if ( curretfct == 0 ) {
				/* Si non, test EXIT,D */
				lexical();
				if ( usc.code == VIG ) {
					lexical();
					if ( (usc.code == IDENT) && (Xstrlen(usc.v.pval) == 1)
					     && (*usc.v.pval == 'D') ) {
						/* La sortie decharge la procedure */
						genedp(); sfdln();
					} else {
						/* Message : syntaxe incorrecte */
						erreur(USUAL,ersynt1); sfdln();
					}
				}
				else {
					/* La sortie ne decharge pas la procedure */
					if (usc.code == FDLN)	genretp();
					else {
						erreur(USUAL,ersynt1); sfdln();
					}
				}
			} else {
				/* Elle retourne un resultat, isole seulement le type */
				if (exitexpr((BYTE)(curretfct >> 1)) == TRUE ) {
					/* Test EXIT(valeur),D */
					lexical();
					if ( usc.code == VIG ) {
						lexical();
						if ( (usc.code == IDENT) && (Xstrlen(usc.v.pval) == 1)
						     && (*usc.v.pval == 'D') ) {
							/* La sortie decharge la procedure */
							genedp(); sfdln();
						}
						else {
							/* Message : syntaxe incorrecte */
							erreur(USUAL,ersynt1); sfdln();
						}
					}
					else {
						/* La sortie ne decharge pas la procedure */
                if (usc.code == FDLN)
							genretp();
						else {
							erreur(USUAL,ersynt1); sfdln();
						}
	           		}
					flag_exit=TRUE;
				}
			}
                }
                break;
            
     case READMEM:        /* lecture de DATAs */
                use_datas = TRUE; trread(); break;
           case RESTORE:        /* position pointeur DATAs */
                use_datas = TRUE; trfnspe(62); break;
           case ON:             /* ON ERROR goto/abort */
                flag = tradon(seg); break;
           case RESUME:         /* fin de traitement d'erreur */
                lexical();
                if (usc.code == FDLN)   /* pas d'etiquette */
                        genres(FALSE,GenericNULL(char));
                else if (usc.code == ETIQ) {
                        genres(TRUE,usc.v.pval); tfdln();
                }
                else { /* fin de ligne incorrecte */
                        erreur(USUAL,errfdln); sfdln();
                }
                break;
           case DATA:           /* finir par des DATA */
                flag = FALSE; break;
           case ESEG:           /* fin de segment */
                if (seg) flag = FALSE;
                else {
                        erreur(USUAL,ersynt8); sfdln();
                }
                break;
           case ENDPROC:        /* fin de procedure */
                if (!seg) flag = FALSE;
                else {
                        erreur(USUAL,ersynt9); sfdln();
                }
                break;
           case DATE:
                traffn(57); break;
           case KBF:
                traffn(58); break;
           case OF:
                tradof(); break;
           case FMT:
                tradfmt(); break;
           case ELSE:
                erreur(USUAL,ersynt23); sfdln(); break;
           case ENDIF:
                erreur(USUAL,ersynt24); sfdln(); break;
           case LOOP:
                erreur(USUAL,ersynt46); sfdln(); break;
           case UNTIL:
                erreur(USUAL,ersynt25); sfdln(); break;
           case WEND:
                erreur(USUAL,ersynt26); sfdln(); break;
           case NEXT:
                erreur(USUAL,ersynt29); sfdln(); break;
           case CASE:
                erreur(USUAL,ersynt32); sfdln(); break;
           case DEFAULT:
                erreur(USUAL,ersynt33); sfdln(); break;
           case ENDSEL:
                erreur(USUAL,ersynt34); sfdln(); break;
           case BREAK:
                if (!flg_itere) { /* pas d'iteration en cours */
                        erreur(USUAL,ersynt45); sfdln();
                }
                else {
                        if (*fin_itere == EOSTR) {
                                cretiq(fin_itere);      /* creer l'etiquette */
                        }
                        gengoto(fin_itere); tfdln();
                }
                break;
           case TIMER:
                lexical();
                if (usc.code != OFF) {
                        erreur(USUAL,ersynt1); sfdln(); break;
                }
                tfdln();
                gentim(0,0,0,GenericNULL(char));
                break;
           case EVENT:
       		memolex();      /* memorise l'unite lexicale courante */
                lexical();      /* et les suivante a chaque appel de lexical() */
                if (usc.code == PAG) {
                	resumelex();
			/* restauration des unites lexicales memorisees */
                        /* l'unite lexicale courante est la 1ere memorisee */
			
			/* affectation d'un des parametres EVENT(p1) = p2 */
                	trfnspe(93);
		} else {
       	        	standardlex();  /* fin de la memorisation */
	                if (usc.code != OFF) {
        	                erreur(USUAL,ersynt1); sfdln(); break;
                	}
                	tfdln();
	                genwhen(FALSE,0,GenericNULL(char));
		}
                break;
#ifdef	_KEYWORD_TRACE
				case TRACE :
				trtrace(); break;
#endif
#ifdef	_KEYWORD_LOADUSER
				case LOADUSER :
					traffn(101);	/* 101 => LOADUSER ds NumFnt[] */
					break;
#endif
           case ASSIGN:
                passign(); break;
           case ARC:
                erreur(USUAL,ersynt7); sfdln(); break;
           case ATB:
                patb(); break;
           case BACKSPACE:
                pngfnlog(3); break;
           case BOX:
                erreur(USUAL,ersynt7); sfdln(); break;
           case CFILE:
                pcfile(); break;
           case CHAIN:
/* #AT: 29/02/00, EXA-57 (begin)*/
#ifdef __ATR22__
            pldgo(FALSE); break;
/* COMMENTED BY AT:*/
/*                pldgo(6); break;*/
#endif
/* #AT: 29/02/00, EXA-57 (end)*/
           case CIRCLE:
                erreur(USUAL,ersynt7); sfdln(); break;
           case CJOIN:
                pclpj(8); break;
           case CKEY:
                pngfnlog(9); break;
           case CLEAR:
                erreur(USUAL,ersynt7); sfdln(); break;
           case CLINK:
                pclpj(10); break;
           case CLOSE:
                pngfnlog(11); break;
           case CONF:
                erreur(USUAL,ersynt7); sfdln(); break;
           case COUNT:
                pclpj(12); break;
           case DELETE:
                pinsdel(13); break;
           case DEFPAINT:
           case DISPLAY:
                erreur(USUAL,ersynt7); sfdln(); break;
           case DFILE:
                pdfile(); break;
           case DJOIN:
                pclpj(15); break;
           case DOWN:
                pupdwn(16); break;
#ifdef __STRUCT__	/* Structures */
			  case ENDWITH:
				  	 endwith(); break;
#endif					 
		   case ENDLOC:break;
           case EXTEND:
                pextend(); break;
           case FFILE:
                pfile(); break;
           case FIND:
                pfind(); break;
           case FKEY:
                pfkey(); break;
           case FREEFONT:
           case GRCONF:
                erreur(USUAL,ersynt7); sfdln(); break;
           case INSERT:
                pinsdel(22); break;
           case JOIN:
                pclpj(23); break;
           case KEY:
                pkey(); break;
           case LFILE:
                pliste(25); break;
           case LINE:
                erreur(USUAL,ersynt7); sfdln(); break;
           case LINK:
                pclpj(27); break;
           case LJOIN:
                pliste(28); break;
           case LKEY:
                pliste(29); break;
           case LLINK:
                pliste(30); break;
           case LOADGO:
/* #AT: 29/02/00, EXA-57 (begin)*/
#ifdef __ATR22__
            pldgo(TRUE); break;
/* COMMENTED BY AT:*/
/*                pldgo(31); break;*/
#endif
/* #AT: 29/02/00, EXA-57 (end)*/
           case MODIF:
                pmodif(); break;
           case NAME:
                pname(); break;
           case NKEY:
                prenkj(33); break;
           case OPEN:
                pngfnlog(34); break;
           case PAINT:
           case PALET:
           case PEN:
           case PIE:
           case POINT:
                erreur(USUAL,ersynt7); sfdln(); break;
           case POSIT:
                pclpj(39); break;
           case PREAD:
                erreur(USUAL,ersynt7); sfdln(); break;
           case READ:
                prdwr(41); break;
           case RECORD:
                pliste(42); break;
           case RENAME:
                prename(); break;
           case RJOIN:
                prenkj(44); break;
           case RKEY:
                pngfnlog(45); break;
           case SEARCH:
                psearch(); break;
           case STAT:
                pliste(47); break;
           case TEXTPEN:
                erreur(USUAL,ersynt7); sfdln(); break;
           case UP:
                pupdwn(49); break;
           case USEFONT:
           case VIEWPORT:
           case WINDOW:
                erreur(USUAL,ersynt7); sfdln(); break;
			  /* A partir de la 2.2a */
#ifdef __STRUCT__	/* Structures */
			  case WITH:
					newwith(); break;
#endif
           case WRITE:
                prdwr(53); break;
//#ifdef _CRIEXT_
       case XCRI:
            pxcri(); break;
//#endif
       case END:
					lexical();
					if ( usc.code != EXTERN ) {
									 erreur(USUAL,ersynt1); sfdln();
					} else {
						lexical();
						if ( usc.code != EVENT ) {
	        						  erreur(USUAL,ersynt1); sfdln();
						} else {
							genwhen(FALSE,0x40,GenericNULL(char));
							sfdln();
						}
					}
					break;
           default:
                erreur(USUAL,ersynt1); sfdln();
           }
        }
        else    /* assemblage de T-Code */
           masm(seg);

		if (!instructionIsDcl) //SG211197
				adrimpl_instr = adrimpl;

        if (adrimpl >= MXSEG) { /* debordement */
                erreur(USUAL,ersynt11); adrimpl = 0L;
        }
        tstpause();     /* test clavier pour le cas d'une pause operateur */

		/* #FC+BG 03/12/02 */
	 	restitue_contexte_registre(sav_libreg, sav_lreg_used, sav_lreg_pushed);


#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ninstruction():fin");
#endif /* ATR_DEBUG */

        return (flag);
}                                       /* instruction */

/*
	is_var_or_seg est TRUE  si EXPRESSION
			  FALSE si SEGMENT

	verrue_findvar : car double appel de findvar !!!
*/
BOOL is_var_or_seg(b,ps,top,vop)
BOOL b;
TabSeg **ps;
BYTE *top;
BINAIRE *vop;
{					/* is_var_or_seg */
BINAIRE advar;
BYTE tr;
BINAIRE numseg;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nis_var_or_seg():debut");
#endif /* ATR_DEBUG */

	/* Recherche d'un identificateur de segment SI PAS VARIABLE */

	*top = 0xFF;
	if (usc.code == IDENT) {
		/* verification pas une constante */
		if ( ! recbincst(&numseg) ) {
		/* verification de l'existence de la variable */
		if ( findvar(usc.v.pval,GenericNULL(BYTE),&advar,GenericNULL(TabSymb *),TRUE) == GenericNULL(BYTE) ) {
			/* verification de l'existence du segment */
			if ( ( *ps=findseg(0,usc.v.pval) ) == GenericNULL(TabSeg) ) {
				/* creation d'un symbole segment FORWARD */
				if ( ! notaprog ) {
					*top = 0; *vop=nsegc;
					newseg(FALSE,TRUE, usc.v.pval, nsegc++ , 0xFFFF, 0,(BINAIRE) 0, 0, 0, 0, 0, 0, 0, 0, 0);
				} else {
					*top = 0; *vop=(BINAIRE) -1;
					newseg(FALSE,TRUE, usc.v.pval, *vop, 0xFFFF, 0,(BINAIRE) 0, 0, 0, 0, 0, 0, 0, 0, 0);
					*ps=findseg(0xFFFF,usc.v.pval);
				}
			} else {
				*top = 0; *vop=(*ps)->num; /* valeur du segment */
			}
			return(FALSE);
		}
		} else {
			*top = 0; *vop = numseg;
		}
	}

	/* Recherche d'une expression SI PAS ID SEGMENT */

	libreg = firstreg;
	if ( b )
		tr = TBIN;
	else
		tr = T_ANY;

	verrue_findvar = TRUE;
	if (!expression(&tr,top,vop)) {
		*top = 0; *vop = 0; /* prendre 0 par defaut */
	}
	verrue_findvar = FALSE;

	if ((*top == 0) && (*vop > 254)) {
		erreur(USUAL,ersynt3); sfdln(); *vop = 0;
	}

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nis_var_or_seg():fin");
#endif /* ATR_DEBUG */

	return(TRUE);

}					/* is_var_or_seg */


static BOOL recadr()

/*      recuperation d'une adresse de branchement
 */
{                                       /* recadr */
#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nrecadr():debut");
#endif /* ATR_DEBUG */

        lexical();
        if (usc.code != ETIQ) {
                erreur(USUAL,ersynt10); sfdln(); return(FALSE);
        }

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\nrecadr():fin");
#endif /* ATR_DEBUG */

	return (TRUE);
}                                       /* recadr */

/* #AT: 13/09/99 (begin)*/
#ifdef __ATR22__
/* To extract needed TabSymb item from pProcItm->pFormalParams field
iIdx : index of list member (counted from 0) */

TabSymb * GetCurrFormalPar(TabProc * pProcItm,int iIdx)
{
  TabSymb * pParamItm = GenericNULL(TabSymb);
  if (!pProcItm || !(pParamItm=pProcItm->pFormalParams)) 
return GenericNULL(TabSymb);
  for(;;){
if (pParamItm && iIdx--) pParamItm = pParamItm->d;
else return pParamItm;
  }
}
#endif
/* #AT: 13/09/99 (end)*/


static char *aderr;
static char bufaderr[LGIDENT];

static void callproc(avec_call)
BOOL avec_call;         /* vrai si appel avec un call */
/*      traitement d'un appel de procedure
 */
{                                       /* callproc */
        BINAIRE i=0;
        BINAIRE vop[MXARGS],nbargs;
        BYTE    top[MXARGS],typ,*dargs;
        TabProc *dproc=GenericNULL(TabProc);

	BYTE tres;
	BINAIRE vres=0;

	BINAIRE reg;
	BINAIRE ivarbreg;		/* #IJM 06/11/02 */
	BYTE *adesc,typ2;

	PSUCInfo psuc;
	BINAIRE protege=0;
#ifdef __ATR22__
/* #AT: 20/04/99 (begin)*/
   BYTE bNeedArgType; // Type that is necessary from point of view of procedure
/* #AT: 20/04/99 (end)*/
/* #AT: 13/09/99 (begin)*/
   TabSymb * pCurrFormalPar;
/* #AT: 13/09/99 (end)*/
#endif

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ncallproc():debut");
#endif /* ATR_DEBUG */

        if ( avec_call ) {
                lexical();
		if ( usc.excode == MODULE )
			i=1;		/* Permet l'appel Call <module>.<nom proc> */
	}

	if ( usc.code == PAG ) {

		libreg = firstreg;

	 	typ=TSTR;
               	if (!expression(&typ,&tres,&vres)) {
               		sfdln(); return;
               	}
		if ((tres != 2) && (tres != 3)) {
        	        erreur(USUAL,ersynt16); sfdln(); return;
                } 

		if ( tres == 3 ) {
			/* Protection du registre contenant le no de fonction */
			/* Probleme avec les tableaux autres que les procedures */
			protege = vres;
			psuc.type = PSUC_PROC;
		} else {
			psuc.adr = vres;
			GetPSUCTable(&psuc);
		}


	       	if (usc.code != PAG) {  /* erreur : '(' attendue */
        	       	erreur(USUAL,erexp6); sfdln(); return;
       		}
	        lexical(); /* avaler la parenthese */

	        nbargs = 0;
		i = 0;
		libreg = firstreg + protege;
		while ( 1 ) {
		/* recherche des arguments un par un */
			if ( usc.code == PAD )
				break;
			typ = T_ANY;
               		argexp = TRUE;

			not_a_call_var = FALSE; 
	                if (!expression(&typ,&top[i],&vop[i])) {
				not_a_call_var = TRUE;
        	                sfdln(); return;
                	}
			not_a_call_var = TRUE;
			nbargs++;

                	if (top[i] == 3) { /* argument dans un registre */
			/* bug : protection du registre contenant la fonction */
				/* putreg((i+1),3,vop[i]); vop[i] = i+1; */
                        	putreg(vop[i]+1,3,vop[i]); vop[i]++;
				libreg = vop[i]+1;
                	}

	                /* verification de la validite des arguments */
			/* Pas possible dans le cas de l'appel par variable*/

	                if (usc.code == INTERRO) {      /* arg en reception : '?' */
        	                lexical();
	                        if ((top[i] != 2) && (top[i] != 3)) {
        	                        /* ni variable ni registre : erreur */
                	                erreur(USUAL,ersynt18); sfdln(); return;
                        	}
	                        if ((top[i] == 3) && (!simplexp)) {
        	                        /* reg mais expression composee : erreur */
                	                erreur(USUAL,ersynt18); sfdln(); return;
                        	}
                 	       top[i] |= 0x4;
                	}
                	i++;
			if (usc.code == PAD)
				break;
                        if (usc.code != VIG) {  /* erreur : ',' attendue */
                                erreur(USUAL,ersynt21); sfdln(); return;
                        }
                        else
                                lexical(); /* avaler la virgule */
                }
	        if (usc.code != PAD) {  /* erreur : ')' attendue */
        	        erreur(USUAL,ersynt20); sfdln(); return;
        	}

		top[nbargs+1] = tres;
		vop[nbargs+1] = vres;

	} else {
		/* Lorsque que l'appel est un appel classique 	*/
		/* c'est une procedure !!!!			*/
		psuc.type = PSUC_PROC;

	        if (usc.code != IDENT) { /* erreur : il faut un nom de proc */
        	        erreur(USUAL,ersynt16); sfdln(); return;
        	}

	        dproc = findproc(i, usc.v.pval);
        	if (dproc == GenericNULL(TabProc)) { /* procedure inconnue */
            /* #OK 24/10/00 (begin) */
            lexical();
			if ( usc.code == PAG ) {
	                	erreur(USUAL,ersynt17);	/* procedure */
			} else {
	                	erreur(USUAL,erexp6); /* variable */
			}
            /* #OK 24/10/00 (end) */
			sfdln(); return;
        	}
#ifdef	VERSION_XX 
		if (!( dproc->ivarb ))
#endif
		dproc->util = TRUE;	/* ca y est, elle est utilisee !!! */
	      	lexical();		/* 27/12/94 : lexical() apres findproc */

       	if (usc.code != PAG) {  /* erreur : '(' attendue */
               	erreur(USUAL,erexp6); sfdln(); return;
       	}

        lexical(); /* avaler la parenthese */
        nbargs = dproc->nba; dargs = dproc->adta;
        nbargs = nbargs & MNBARG;
        if (nbargs != 0) {
           i = 0; dargs = dproc->adta;
           while (i < nbargs) { /* recherche des arguments un par un */

					argexp = TRUE;
					libreg = nbargs + firstreg;
					top[i] = *dargs & typ_in_desc;
/* #AT: 20/04/99 (begin)*/
#ifdef __ATR22__
					bNeedArgType = top[i];
					gboolIsCallProc = TRUE;
#endif
/* #AT: 20/04/99 (end)*/

/* #AT: 20/04/99 (begin)*/
#ifndef __ATR22__
					if ((*dargs & 0x40) == 0) //* si pas de dimension *
						if ((top[i] == TBIN1) || (top[i] == TBIN2))
							top[i] = TBIN;
#endif
/* #AT: 20/04/99 (end)*/


/* #AT: 13/09/99 (begin)*/
#ifdef __ATR22__
					gboolIsActParAdmissible = TRUE;	/* Default */
#endif
/* #AT: 13/09/99 (end)*/

                if (!expression(&top[i],&typ,&vop[i])) {
                        sfdln(); return;
                }
/* #AT: 20/04/99 (begin)*/
/* top[i] is type that is really sended to procedure; 
   TBIN2 = 2 bytes (%) and  TBIN1 = 1 byte (#)
*/
#ifdef __ATR22__
					gboolIsCallProc = FALSE;
					if (bNeedArgType == TBIN1 && top[i] == TBIN2) {
						/* Error: Data conversion */
						//erreur(USUAL,erexp4); sfdln(); return;
						erreur(WARNING,erexp4); //  Commented by CR 13/12/00 sfdln(); return;
					}
#endif
/* #AT: 20/04/99 (end)*/
 
/* #AT: 13/09/99 (begin)*/
#ifdef __ATR22__
					if (pCurrFormalPar = GetCurrFormalPar(dproc,i))
						if (!pCurrFormalPar->type->pasptr && !gboolIsActParAdmissible) {
							/* Incompatibility between declaration and usage */
							erreur(USUAL,errfu14); sfdln(); return;
						}
#endif
/* #AT: 13/09/99 (end)*/

                if (typ == 3) { /* argument dans un registre */
                        putreg((i+1),3,vop[i]); vop[i] = i+1;
                }
                top[i] = typ;
                /* verification de la validite des arguments */
                if (simplexp) {
                        /* possible pour une expression simple seulement */
                        switch (typ) {
                           case 0:  /* resultat dans une valeur immediate */
                           case 1:  /* ou resultat dans une constante */
                           case 3:  /* ou resultat dans un registre */
                                    /* il faut un parametre non dimensionne */
                                if (*dargs & 0x40) { /* sinon : erreur */
                                   erreur(USUAL,ersynt18); sfdln(); return;
                                }
                                break;
                           case 2:  /* resultat dans une variable */
                                    /* la cohesion des types est deja vue */
                                if ((*dargs | typ_in_desc) !=
                                    ((*pdop & (BYTE) 0x00F7) | typ_in_desc) ) {
                                    erreur(USUAL,ersynt18); sfdln(); return;
                                }
                        }
                }
                dargs++;
                if (usc.code == INTERRO) {      /* arg en reception : '?' */
                        lexical();
                        if ((typ != 2) && (typ != 3)) {
                                /* ni variable ni registre : erreur */
                                erreur(USUAL,ersynt18); sfdln(); return;
                        }
                        if ((typ == 3) && (!simplexp)) {
                                /* reg mais expression composee : erreur */
                                erreur(USUAL,ersynt18); sfdln(); return;
                        }
        
                /* #OK: 24/11/99 (begin)*/
#ifdef __ATR22__
                if (IS_TSTR(bNeedArgType) || IS_TBCD(bNeedArgType)) 
                    err2(WARNING,ersymb10,usc.v.pval);
#endif
                /* #OK: 24/11/99 (end)*/

                        top[i] |= 0x4;
                }
                i++;
                if (i < nbargs) { /* reste des arguments */
                        if (usc.code != VIG) {  /* erreur : ',' attendue */
                                erreur(USUAL,ersynt21); sfdln(); return;
                        }
                        else
                                lexical(); /* avaler la virgule */
                }
           }
        } else
		i=0;	/* pas d'arguments */
        if (usc.code != PAD) {  /* erreur : ')' attendue */
                erreur(USUAL,ersynt20); sfdln(); return;
        }

	}

	/* Gestion des erreurs a la NGF */
	lexical();

	/* Pas de branchement d'erreur a priori */
	aderr = GenericNULL(char);
	top[i]=0;
	vop[i]=0;

	if ( usc.code != FDLN) {
	
	if ( usc.code != DPT ) { /* : attendu */
		erreur(USUAL,eriof8); sfdln(); return;
	}
	lexical();
	if ( (usc.code == ETIQ) || (usc.code == NEXT) ) {
		aderr = &bufaderr[0];
		if ( usc.code == ETIQ)
			Xstrcpy(aderr,usc.v.pval);
		else
			cretiq(aderr);
		lexical();
		if ( usc.code != VIG ) { /* , attendu */
			erreur(USUAL,eriof4); sfdln(); return;
		}
		lexical();
                /* reference a une variable de type numerique */
                reg = getreg(); adrref_verrue = TRUE;
            /* #OK: 09/03/00 (begin) */
            nextArray = TRUE;
            /* #OK: 09/03/00 (end) */
                if (!reference(reg,&adesc,&vop[i],&top[i],&typ2)) {
                    adrref_verrue = FALSE; sfdln(); 
								/* #OK: 09/03/00 (begin) */
                    nextArray = FALSE;
								/* #OK: 09/03/00 (begin) */
								return;
                }
            /* #OK: 09/03/00 (begin) */
            nextArray = FALSE;
					 /* #OK: 09/03/00 (end) */
                if (top[i] == 4) {     /* variable 'registre' */
                        ungetreg(); top[i] = 3; vop[i] = nrgvar;
                }
                adrref_verrue = FALSE;
                if (IS_TSTR(typ2)) {
                        erreur(USUAL,eriof3); sfdln(); return;
                }
		tfdln();
	} else {
		erreur(USUAL,eriof3); sfdln(); return;
	}
	}

	switch ( psuc.type )
	{
		case PSUC_PROC:
#ifdef	VERSION_XX
			if (!dproc || !(dproc->ivarb))
			{
#endif
				genclp(dproc,nbargs,top,vop,aderr);
#ifdef	VERSION_XX
			}
			else
			{
				ivarbreg = ev_indirection(dproc->ivarb,dproc->vitem);
				vop[nbargs+1] = ivarbreg; /* dproc->ivarb; */
				top[nbargs+1] = 3; /* was 2 means var for now */
				genclsuc(nbargs,top,vop,aderr);
			}
#endif
			break;

		default:
			genclsuc(nbargs,top,vop,aderr);
	}

	/* #FC+BG 03/12/02 Begin */
	Nettoyer_multi_lreg_used(nbargs+2, top, vop);
	/* #FC+BG 03/12/02 End */

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ncallproc():fin");
#endif /* ATR_DEBUG */

}                                       /* callproc */


void callfuser()

/*      Traitement des appels aux fonctions utilisateur
 *      (runtimes externes)
 *      usc.v.ptusr contient un pointeur vers la definition
 *      de la fonction utilisateur incriminee.
 */

{                                       /* callfuser */
        Tbusr *t;
        BINAIRE i;
        BINAIRE vop[MXARGS],nbargs;
        BYTE top[MXARGS],typ,*dargs;
        BYTE *margs;
        BYTE bidt;
        BINAIRE bidv;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ncallfuser():debut");
#endif /* ATR_DEBUG */

        t = usc.v.ptusr;
        bidt = (BYTE)0;


        bidv = (BINAIRE)0;

        /* Se substitue a une instruction : la fonction ne doit
         * donc pas avoir de valeur retournee
         */
        if (t->tres != TVOID) {
                erreur(USUAL,errfu14);sfdln();return;
        }

        lexical();
        if (usc.code != PAG) {          /* erreur : ( attendue */
                erreur(USUAL,ersynt19);sfdln();return;
        }

        lexical(); /* avaler la parenthese */
        nbargs = t->nba;
        dargs = t->typa;

        /* Traitement des arguments */
        i = 0;
        nbargs = nbargs & MNBARG;
        if ((nbargs != 0) || t->nbavar) {
           dargs = t->typa;
           margs = t->moda;
           while ((i < nbargs) || ((i < MXARGS) && t->nbavar)) {
                libreg = MXARGS + firstreg;
                top[i] = *dargs;         /* & typ_in_desc; */
                if ((i >= nbargs) && t->nbavar)
                        top[i] = T_ANY;

                /* Admet un nombre d'argument variable nul */
                if ((i == 0) && (t->nbavar) && (usc.code == PAD))
                        goto skgen;
                if (!expression(&top[i],&typ,&vop[i])) {
                        erreur(USUAL,errfu15);sfdln(); return;
                }
                if (typ == 3) { /* argument dans un registre */
                        putreg((i+1),3,vop[i]); vop[i] = i+1;
                }
                top[i] = typ;

                /* verification de la validite des arguments : A FAIRE ???
                 *	0 : passage par valeur
                 *	1 : passage par adresse
                 *	2 : les deux autorises
                 */
                if (*margs != 0) {
			if (*margs == 1) {
				/* Valeurs imm, constantes et expressions composees = non modifiables */
	                        if (((typ != 2) && (typ != 3)) || ((typ == 3) && (!simplexp))) {
                	                erreur(USUAL,errfu17); sfdln(); return;
                        	}
                        	top[i] |= 0x4;
                        }
                        else {
				/* Valeurs imm, constantes et expressions composees = non modifiables */
				if ((typ == 2) || ((typ == 3) && (simplexp)))	
					top[i] |= 0x4;
                        }
                }
                if (i < nbargs) {
                        dargs++;
                        margs++;
                }
                i++;
                if (i < nbargs) { /* reste des arguments */
                        if (usc.code != VIG) {  /* erreur : ',' attendue */
                                erreur(USUAL,ersynt21); sfdln(); return;
                        }
                        else
                                lexical(); /* avaler la virgule */
                }
                else {
                        switch(usc.code) {
                                case VIG : lexical(); break;
                                case PAD : goto skgen;
                                default  : erreur(USUAL,ersynt20);
                                           sfdln(); return;
                        }
                }
           }
        }
        if (usc.code != PAD) {  /* erreur : ')' attendue */
                erreur(USUAL,ersynt20); sfdln(); return;
        }
skgen:  tfdln();
        genfuser(t,bidt,bidv,top,vop,i);

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ncallfuser():fin");
#endif /* ATR_DEBUG */
}                                       /* callfuser */



static BOOL traitif(seg)

/*      traitement de l'instruction IF
 */
BOOL seg;
{                                       /* traitif */
        char    adr[LGIDENT],adr2[LGIDENT],*padr;
        BOOL    flg = TRUE;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ntraitif():debut");
#endif /* ATR_DEBUG */

        deb_expcond = expcond();

        if (deb_expcond == GenericNULL(CdMemb)) {
#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ntraitif():expcond()==NULL");
#endif /* ATR_DEBUG */
                sfdln();
        }
        else {
           if (usc.code == DPT) {
                /* une instruction doit suivre sur la meme ligne */
                lexical();
                switch (usc.code) {
                   case GOTO:           /* cas particulier du GOTO */
                        if (!recadr()) {
                                libcond(deb_expcond); break;
                        }
                        Xstrcpy(adr,usc.v.pval);
                        evalcond(TRUE,deb_expcond,adr);
                        tfdln();
                        break;
                   case ETIQ:           /* etiquette : erreur */
                   case IF:             /* debuts d'intructions interdites */
                   case SELECT:         /* ---> erreur ...... */
                   case FOR:
                   case DO:
                   case REPEAT:
                   case WHILE:
                   case DATA:
                   case ESEG:
                   case ENDPROC:
                   case ON:
                        erreur(USUAL,ersynt1); sfdln();
                        libcond(deb_expcond); break;
                   default:             /* une instruction autorisee */
                        cretiq(adr);
                        evalcond(FALSE,deb_expcond,adr);
                        instruction(seg);
                        defetiq(adr,(BINAIRE) adrimpl);
                        break;
                }
           }
           else {       /* un bloc d'instruction doit suivre */
             if (usc.code != FDLN) {
                erreur(USUAL,errfdln); sfdln(); libcond(deb_expcond);
             }
             else {
                cretiq(adr); evalcond(FALSE,deb_expcond,adr); padr = &adr[0];
                do {
                        debut_instruction();
                }
                while ((usc.code != ELSE) && (usc.code != ENDIF) &&
                        (instruction(seg)));
                if (usc.code == ELSE) {
                        cretiq(adr2); gengoto(adr2);
                        defetiq(adr,(BINAIRE) adrimpl);
                        tfdln(); padr = &adr2[0];
                        /* force adresse implantation dans fichier liste */
                        ALadrimpl = adrimpl;
                        do {
                                debut_instruction();
                        }
                        while ((usc.code != ENDIF) && (instruction(seg)));
                }
                if (usc.code == ENDIF) {
                        tfdln(); defetiq(padr,(BINAIRE) adrimpl);
                }
                else {  /* fin de segment ou de procedure */
                        defetiq(padr,(BINAIRE) adrimpl);
                        erreur(USUAL,ersynt22); flg = FALSE;
                }
             }
           }
        }

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ntraitif():fin");
#endif /* ATR_DEBUG */

        return (flg);
}                                       /* traitif */


static BOOL trloop(seg)

/* traitement de l'iteration DO ... LOOP */
BOOL seg;
{                                       /* trloop */
	char    adr[LGIDENT],*ptradr,*adrpile;
#ifdef WIN1632
	volatile char    adr2[LGIDENT];
#else
	char    adr2[LGIDENT];
#endif
	BOOL    flg = TRUE;

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ntrloop():debut");
#endif /* ATR_DEBUG */

	adr2[0] = EOSTR;
	ptradr = &adr2[0];
	/* DO = simple definition d'une etiquette */
	tfdln();
	cretiq(adr);
	defetiq(adr,(BINAIRE) adrimpl);
	pushfin(&ptradr,&adrpile);

	/* un bloc d'instruction doit suivre */
	do
	{
		debut_instruction();
	}
	while ((usc.code != LOOP) && (instruction(seg)));

	popfin(&adrpile);
	if (usc.code == LOOP)
	{
		gennew();       /* delimiteur de ligne dans le code */

		/* #FC+BG 03/12/02 init_suivi_registre(); */

		/* fin de l'iteration : remonter sur le DO */
		gengoto(adr);
		/* si necessaire : definir l'adresse de sortie des BREAK */
		if (adr2[0] != EOSTR)
			defetiq(adr2,(BINAIRE) adrimpl);
	}
	else
	{  
		/* fin de segment ou de procedure */
		erreur(USUAL,ersynt48);
		flg = FALSE;
	}

#ifdef ATR_DEBUG
	dbgprint(ATRACE,"\ntrloop():fin");
#endif /* ATR_DEBUG */

return (flg);
}                                       /* trloop */

/*----------------- Fin du fichier : parse1.c ------------------------*/

