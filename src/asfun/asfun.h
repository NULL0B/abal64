/************************************
* Fenetrage    Definitions generales*
*-----------------------------------*
* Source : ASFUN.H                  *
*-----------------------------------*
* Version : 1.1a                    *
* Creation    le : 18/10/1990  LLB  *
* Mise a jour le : 		    *
*************************************/

/* Definitions generales */

#define BYTE  signed char
#define BIN   unsigned short int
#define VFP (void far *)
#define VFFP (void far * far *)
#define GNULL VFP 0L
#define GGNULL VFFP 0L


/*-------------*/
/* constantes  */
/*-------------*/

/* codage des attributs video */
/*----------------------------*/
#define NORMAL     0
#define	VIDEO	   1
#define SOULIGNE   2
#define SOUSINT    4
#define SURINT     8
#define CLIGNOT  128

/* codage des couleurs */
/*---------------------*/
#define	NOIR	    0
#define ROUGE	    1
#define VERT	    2
#define MARRON	    3
#define BLEU        4
#define MAGENTA     5
#define CYAN	    6
#define BLANC	    7	/* GRIS CLAIR */
#define GRIS	    8
#define ROUGE_CL    9
#define VERT_CL    10
#define JAUNE      11
#define BLEU_CL    12
#define MAGENTA_CL 13
#define CYAN_CL	   14
#define BLANC_INT  15

/* fonctions generique WFGEN */

#define	CLFUN	   1		/* clear fenetre     */
#define	CLEOF	   2		/* clear fin fenetre */
#define	CLEOL	   3		/* clear fin ligne   */
#define INS_LIG	   4		/* insertion ligne   */
#define SUP_LIG    5		/* suppression ligne */
#define	SCROL_UP   6		/* haut   */
#define SCROL_DW   7		/* bas	  */
#define SCROL_DR   8		/* droite */
#define SCROL_GA   9		/* gauche */

#define	CURON	  10		/* eteindre curseur */
#define	CUROF	  11		/* allumer curseur */
#define INS_CAR	  12		/* insertion caractere sur une ligne */
#define SUP_CAR	  13		/* suppress  caractere sur une ligne */
#define CLBOL	  14		/* effacer debut de ligne */

#define HAUT	1	/* directions du scroll */
#define BAS	2
#define DROIT	3
#define GAUCHE	4

/* constantes fenetre */

#define	INVISIBLE   1		/* flag invisible 		*/
#define VISIBLE	   0xfffe       /* inverse de "INVISIBLE 	*/
#define	CURSEUR     2		/* curseur visible	        */
#define CAD1        8		/* cadre simple trait 		*/
#define CAD2       16		/* cadre double trait 		*/
#define CAD3	   32		/* cadre utilisateur 		*/
#define	SCROLL 	    4		/* flag scroll 			*/

#define TAIL_TITRE 32


/* codes erreur */
/* ------------ */
#define werr_desc 1	/* parametre d'appel incorrect  */
#define werr_inex 2	/* fenetre inexistante 		*/
#define werr_mem  27	/* panne memoire 		*/
#define werr_ini  3	/* winit non effectuee 		*/
#define	werr_max  4	/* nbre fenetres max atteint	*/

#define sferr_inex	40
#define werr_exist	41
#define sferr_open	42
#define sfenr_inex	78
#define sfenr_fin 	48
#define sfenr_deb 	64


/**********************************************************/
/* structure du descripteur d'appel de la fonction WCREAT */
/**********************************************************/

typedef struct  {
   BIN	mere;		/* numero mere ou console */
   BIN plig;		/* position ligne   */
   BIN pcol;	        /* position colonne */
   BIN nlig;		/* Nombre de lignes */
   BIN ncol;		/* Nombre de colonnes */

   BYTE	atbvid;		/* attribut video texte */
   BYTE coltxt;		/* couleur texte */
   BYTE colfon;		/* couleur fond */

   BIN	control;        /* bit 0 = 1  (1): Invisible     */
			/* bit 1 = 1  (2): Curseur actif */
			/* bit 2 = 1  (4): SCROLL actif  */
			/* bit 3 = 1  (8): Cadre simple trait */
			/* bit 4 = 1 (16): Cadre double trait */
			/* bit 5 = 1 (32): Cadre utilisateur  */

   BIN	lntitre;		/* Longueur titre */

   BYTE titre[TAIL_TITRE];	/* Titre fenetre  */
   BYTE cadusr[8];		/* Cadre utilisateur */
   BYTE cadatb;			/* attribut cadre user */
   BYTE cadtxt;			/* couleur texte cadre user */
   BYTE cadfon;			/* couleur fond cadre user */
   BYTE reserve;
   } WDESC;


/**********************************************************/
/* structure du descripteur d'appel pour BOITE VALIDATION */
/**********************************************************/

typedef struct {
  BYTE	bv_typv;		/* type de validation  	*/
  BYTE	bv_optin;		/* option initiale	*/
  BYTE	bv_style;		/* style fenetre	*/
  BIN	bv_plig;		/* position ligne    */
  BIN	bv_pcol;		/* position colonne  */
  BYTE	bv_lgmes;            	/* longueur affichee */
} BV_DESC;

/*********************************************************/
/* structure du descripteur d'appel pour MENU DEROULANTS */
/*********************************************************/

/* CREATION D'UN MENU */
/*--------------------*/
typedef struct {
  BYTE	men_style;		/* style fenetre    */
  BIN	men_plig;		/* position ligne   */
  BIN	men_pcol;		/* position colonne */
  BYTE	men_titr[TAIL_TITRE];	/* titre            */

  BYTE	men_aff;		/* type (1=Hz, 2=Vt)*/
  BYTE	men_esc;		/* type Echappement */

  BYTE	men_nbop;		/* nbre elements    */
  BYTE	men_lgop;		/* longueur valeur  */
  BYTE	men_lgaf;		/* longueur affichee*/
  BYTE	men_lgcom;		/* longueur commentaires */
} MEN_DESC;

/* CREATION D'UNE OPTION */
/*-----------------------*/

typedef struct {
   BYTE	opt_car;
   BYTE	opt_typeff;
   BYTE	opt_ataff;
   BYTE	opt_atsel;
   BYTE	opt_atetat;
   BYTE	opt_nomen;
   BYTE	opt_optin;
} OPT_DESC;

/*********************************************************/
/* structure du descripteur d'appel pour LISTE DEFILANTE */
/*********************************************************/

/* CREATION D'UNE LISTE */
/*----------------------*/

typedef struct  {
  BYTE	lis_style;		/* style fenetre    */
  BIN	lis_plig;		/* position ligne   */
  BIN	lis_pcol;		/* position colonne */
  BIN	lis_nlig;		/* nombre de lignes */
  BYTE	lis_titr[TAIL_TITRE];	/* titre            */

  BYTE	lis_aff;		/* type affichage (1=Hz, 2=Vt)*/
  BYTE	lis_defil;		/* type defilement(1=Hz, 2=Vt)*/
  BYTE	lis_nbcol;		/* nombre de colonnes */
  BYTE	lis_pscroll;		/* pas de scroll      */
  BYTE	lis_cadre;		/* 1 = a gauche  2=centre */

  BIN	lis_maxel;		/* nombre max d'el  */
  BYTE	lis_elln;			/* longueur valeur  */
  BYTE	lis_ellaf;		/* longueur affichee*/
  BYTE	lis_ellcom;		/* longueur commentaires */
} LIS_DESC;


/* Declarations des fonctions de la bibliotheque dynamique fenetrage */

#ifdef LINT_ARGS
extern BIN InitRuntime(BIN , BYTE * , BIN , void * , BIN);
extern BIN FinRuntime(BIN);
extern BIN winit( BYTE , BYTE , BYTE , BYTE , BYTE );
extern BIN wcreat( BIN * , BYTE * );
extern BIN wsup( BIN );
extern BIN wwrite( BIN , BYTE * );
extern BIN wselect( BIN );
extern BIN winv( BIN );
extern BIN wvis( BIN );
extern BIN wfgen( BIN , BIN );
extern BIN watb( BIN , BYTE , BYTE , BYTE );
extern BIN wposcur( BIN , BIN , BIN );
extern BIN wimpl( BIN );
extern BIN wgel( BIN );
extern BIN wfend( void );
extern BIN wsetatb( BIN , BYTE , BYTE , BYTE , BIN , BIN , BIN , BIN );
extern BIN sf_init( BYTE * );
extern BIN sl_activ( void );
extern BIN sl_mess( BYTE , BYTE , BYTE * );
extern BIN sl_inv( void );
extern BIN sl_desac( void );
extern BIN menu_creat( BYTE , BYTE * );
extern BIN menu_option( BYTE , BYTE , BYTE * , BYTE * , BYTE * );
extern BIN menu_sep( BYTE , BYTE );
extern BIN menu_optif_opt( BYTE , BYTE , BYTE , BYTE * , BYTE * , BYTE * );
extern BIN menu_latt_opt( BYTE , BYTE , BYTE * , BYTE * , BYTE * );
extern BIN menu_matt_opt( BYTE , BYTE , BYTE , BYTE , BYTE );
extern BIN menu_annul_opt( BYTE , BYTE );
extern BIN menu_vis( BYTE , BYTE , BYTE );
extern BIN menu( BYTE , BYTE , BYTE * , BYTE * , BYTE * );
extern BIN menu_inv( BYTE );
extern BIN menu_sup( BYTE );
extern BIN list_creat( BYTE , BYTE * );
extern BIN listmul_creat( BYTE , BYTE * );
extern BIN list_element( BYTE , BIN * , BYTE , BYTE , BYTE * , BYTE * );
extern BIN list_read_elt( BYTE , BIN , BYTE * , BYTE * , BYTE * );
extern BIN list_down( BYTE , BIN * , BYTE * , BYTE * , BYTE * );
extern BIN list_up( BYTE , BIN * , BYTE * , BYTE * , BYTE * );
extern BIN list_matt_elt( BYTE , BIN , BYTE , BYTE );
extern BIN list_close( BYTE );
extern BIN list_vis( BYTE , BIN , BIN );
extern BIN list( BYTE , BIN * , BIN * , BYTE * , BYTE * );
extern BIN list_inv( BYTE );
extern BIN list_sup( BYTE );
extern BIN bvalid_spc( BYTE * , BYTE * , BYTE * );
extern BIN bvalid( BYTE , BYTE * );
extern BIN sf_end( void );
extern BIN wfmod( BIN , BIN , BIN * , BYTE * , BYTE );
extern BIN help_activ( BYTE , BYTE * );
extern BIN help( BYTE * );
extern BIN help_desac( void );
extern BIN help_def( BYTE * );
#else
extern BIN InitRuntime();
extern BIN FinRuntime();
extern BIN winit();
extern BIN wcreat();
extern BIN wsup();
extern BIN wwrite();
extern BIN wselect();
extern BIN winv();
extern BIN wvis();
extern BIN wfgen();
extern BIN watb();
extern BIN wposcur();
extern BIN wimpl();
extern BIN wgel();
extern BIN wfend();
extern BIN wsetatb();
extern BIN sf_init();
extern BIN sl_activ();
extern BIN sl_mess();
extern BIN sl_inv();
extern BIN sl_desac();
extern BIN menu_creat();
extern BIN menu_option();
extern BIN menu_sep();
extern BIN menu_optif_opt();
extern BIN menu_latt_opt();
extern BIN menu_matt_opt();
extern BIN menu_annul_opt();
extern BIN menu_vis();
extern BIN menu();
extern BIN menu_inv();
extern BIN menu_sup();
extern BIN list_creat();
extern BIN listmul_creat();
extern BIN list_element();
extern BIN list_read_elt();
extern BIN list_down();
extern BIN list_up();
extern BIN list_matt_elt();
extern BIN list_close();
extern BIN list_vis();
extern BIN list();
extern BIN list_inv();
extern BIN list_sup();
extern BIN bvalid_spc();
extern BIN bvalid();
extern BIN sf_end();
extern BIN wfmod();
extern BIN help_activ();
extern BIN help();
extern BIN help_desac();
extern BIN help_def();
#endif
