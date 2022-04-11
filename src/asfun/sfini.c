/************************************************************************
* Services Fenetres - Initialisation					*
*-----------------------------------------------------------------------*
* Source : sfini.c                  					*
*-----------------------------------------------------------------------*
* Version : 1.1a                    					*
* Mise a jour le : 05/02/1990   sb  					*
*									*
* Version 1.2c dlr 05.11.91						*
*		Init messages UNIX (BOS)				*
*									*
* Version 1.3 	18.11.91						*
*		Attributs ‚l‚ments boite de dialogue dans STF		*
*		  13.01.1992                                            *
*	 	Attributs ombrage dans STF                              *
*                                                                       *
* Version 1.4   07.05.91 llb						*
*			Init mouse						*
*		01.04.93 llb
*			Ajout styles dynamiques							*
*		16.09.93
*			Pas de Mouse_off si wend()
*       	23.09.93
*			Couleur boutons BD dans STF
*                       Souris ON/OFF dans STF
*************************************************************************
* Fonctions                         					*
*                                   					*
* - sfinit           initialisation 					*
* - sfend            fin            					*
*									*
************************************************************************/

#include "sfundef.h"
/*#include "bda.h"*/
#include "sfbd.h"

#include <stdio.h>
#include <fcntl.h>

#include "mouse.h"

WORD mouse_state;
BDA_ARG rt_arg;


/* l'EVENT partage par l'ensemble des items ASFUN 	*/

EVENT_STR event;


/* le tableau des fenetres mouse_sensitives		*/

WORD  mouse_item_list[MAXFUN];
WORD  mousson;
WORD  mous_is;
BPTR  Wkup_Adress;
WORD  Wkup_Mask;
/*******************************************
* Description du fichier de configuration  *
********************************************/
#include "fconfig.h"

struct	F_CONFIG	fc;

/* donnees globales */

/**********************/
/* pour tous services */
/**********************/
/*stc_desc stc[MAXSTC];*/
                                        /* styles de cadres */
stc_desc stc[MAXSTC] = { {SCHG,SBH,SCHD,SBD,SCBD,SBB,SCBG,SBG},
                       {DCHG,DBH,DCHD,DBD,DCBD,DBB,DCBG,DBG},
                       {'*','-','*','!','*','-','!'}  };


stf_desc stf[MAXSTF+1];			/* styles de fenetres */
cof_tab  co;				/* config options     */
fond_tab fond;				/* fond d'ecran  */
WDESC_APP fen;				/* appel fenetre */
BYTE lispace[132];			/* ligne blanche */

BYTE tb_style[MAXSTF];			/* table presence styles */


/*********************/
/* pour ligne status */
/*********************/

WORD  ls_nfenu;		/* numero de fenetre status utilisateur en cours */
ls_tab ls;		/* ligne status */

/********************/
/* pour menu        */
/********************/

md_tab	md[MAXMEN];	/* description des menus */
me_tab	me[MAXENCH];	/* table des enchainements */
WORD	cpt_e;		/* compteur d'enchainements */
WORD    ind_e;		/* indicateur menus r‚affich‚s */
BYTE	nomena;		/* menu actif */
BYTE	men_niv;	/* compteur niveaux chainage */
BYTE	men_way[15];	/* trace du chainage */	
BYTE	last_men;	/* memo dernier menu appele */

/********************/
/* pour liste       */
/********************/

ld_tab  ld[MAXLD];	/* description des listes */
WORD	ld_plig;
WORD	ld_pcol;

/******************************
* pour les boites validation  *
*******************************/

#include "asfmsg.h"

bv_tab bvc;

WORD bv_f;	/* fenetre bv */
BYTE bv_m;      /* menu bv */

/*************************
* pour aide contextuelle *
**************************/
BYTE sa_mcled[8];		/* mot_cle defaut     */
BYTE sa_touche;			/* touche aide en cours */
FILE * sa_ptf;			/* pointeur fichier aide */

/* touches utilisees */
BYTE tc[MAX_TOUCHES];

WORD	omb_atrib = 0x0408;


/**************************
* Pour boŒtes de dialogue *
**************************/

TB_STR TB_BOX[MAX_DIAL];


/****************************************
*            Fonction sfinit            *
*  Initialisation des services          *
*  Version Provisoire                   *
*****************************************/
TYPF sfinit(nomfc)
BPTR nomfc;

{

/* fonctions externes */
TYPF lsacti();

/* donnees externes */
extern BYTE fen_ini;
extern ls_tab ls;
extern fond_tab fond;
extern  bv_tab bvc;
extern cof_tab co;
extern stc_desc stc[MAXSTC];
extern stf_desc stf[MAXSTF+1];
extern md_tab md[MAXMEN];
extern BYTE nomena;			/* menu actif */
extern BYTE lispace[132];
extern WORD bv_f;			/* fenetre bv */
extern BYTE bv_m;               	/* menu bv    */
extern BYTE tc[MAX_TOUCHES];
extern BYTE * tabmes[];
extern BYTE sa_mcled[8];		/* mot_cle defaut     */
extern BYTE sa_touche;			/* touche aide en cours */
extern FILE * sa_ptf;			/* fichier aide en cours */
extern struct F_CONFIG fc;		/* NS le 19/04/90 */

/* donnees internes */
BYTE nomfic[128];

int sf_er;
int i,j,k;
int pfc;
BYTE * pt;
WORD mot;
WORD bouton;				/* nb de bouton de la mouse 	*/
WORD lg_fic;


WORD button_i ,lig_i, col_i;

if (!( MAXLIG ))
	get_cons();


/* initialisation table des messages */

#ifdef HX

for (i=0 ; i <= MAXMES ; ++i)
   {
	tabmes[i] = &mentete[i][0];
   };
#else

pt = tabmes[0];
for (i=0 ; i <= MAXMES ; ++i)
   {
	tabmes[i] = pt;
	while (*pt != EOS) pt++;
	while (*pt == EOS) pt++;
   };

#endif /* HX */


j = -1;
k = -1;
if(rt_arg.t[0] != TYPE_CHAINE)
       return(Bd_err_typ);
if(rt_arg.l[0] > 128)
     return(werr_desc);

lg_fic = rt_arg.l[0];
/* compatibilite avec les anciens programmes C (casfun.obj */
if (( lg_fic == 2)&&(nomfc[2] != ' '))
	lg_fic = 16;

if (nomfc != (BPTR) NULL)
 {
   for (i=0;(i < lg_fic) && (nomfc[i] != ' ');++i) nomfic[i] = nomfc[i];
   nomfic[i] = EOS;
   k +=i;


#ifndef PROL
/*TC   if (Access(nomfic, R_OK, 0) == -1)*/
#ifdef AIX_VERS
#ifdef AVIION
       if (Access(nomfic, R_OK, 0) == -1)
#else
#endif /* AIX_VERS */
       if (Access(nomfic, R_OK, 0) == -1)
#ifdef AIX_VERS
#endif
#endif /* AIX_VERS */
	pfc = -1;
   else
#endif
#ifndef unix
   pfc = open( (char *) nomfic,O_RDONLY|O_BINARY,0);
#else
#define O_RDONLY 0
   pfc = open( (char *) nomfic,O_RDONLY,0);
#endif
   if (pfc != -1)
    {
	j =  read ( pfc, (char *) &fc ,0x100);
	close(pfc);
     };

 };
 /* test si le fichier est lu et correct */

  if (( j > 0) && (memcmp(fc.f_titr, "stf1",4)== 0) )
  {
	if ( fc.f_ind < sf_ind )		/* set param version 1.3 */
	{
		fc.f_bd[1]  = BLANC;	/* atb element actif boite dial */
		fc.f_bd[2]  = NOIR;
		fc.f_bd[0]  = VIDEO;

		fc.f_c_bout[1] = NOIR;	/* atb equiv. caractere bouton dialog */
		fc.f_c_bout[2] = JAUNE;
		fc.f_c_bout[0] = SURINT;

		fc.omb_atb[1] = NOIR;   /* couleur fond ombre */
		fc.omb_atb[2] = GRIS;	/* couleur texte ombre */
		fc.omb_atb[0] = SOUSINT;
	}
	if ( fc.f_ind < sf_ind4 )		/* set param version 1.4 */
	{
		fc.f_bouton[1]  = BLANC;	/* atb bouton boite dial */
		fc.f_bouton[2]  = BLANC_INT;
		fc.f_bouton[0]  = VIDEO;
		fc.mouse_inhibit = 1;
	}
  }
  else	/* pas de fichier ou fichier non reconnu */
  {
	/* CORRESPONDANCE ATTRIBUTS COULEURS */

	fc.f_fond[1] = BLEU;
	fc.f_fond[2] = BLANC;
	fc.f_fond[0] = NORMAL;

	fc.f_sousint[1] = BLEU;
	fc.f_sousint[2] = GRIS;
	fc.f_sousint[0] = SOUSINT;

	fc.f_normal[1] = BLEU;
	fc.f_normal[2] = BLANC;
	fc.f_normal[0] = NORMAL;

	fc.f_souligne[1] = BLEU;
	fc.f_souligne[2] = JAUNE;
	fc.f_souligne[0] = SURINT;

	fc.f_surint[1] = BLEU;
	fc.f_surint[2] = BLANC_INT;
	fc.f_surint[0] = SURINT;

	fc.f_inverse[1] = BLANC;
	fc.f_inverse[2] = NOIR;
	fc.f_inverse[0] = VIDEO;

	fc.f_barsel[1] = BLANC;
	fc.f_barsel[2] = NOIR;
	fc.f_barsel[0] = VIDEO;

	fc.f_bd[1]  = BLANC;	/* atb element inactif boite dial */
	fc.f_bd[2]  = NOIR;
	fc.f_bd[0]  = VIDEO;

	fc.f_c_bout[1] = NOIR;	/* atb car. clef des bouton boite dial */
	fc.f_c_bout[2] = JAUNE;
	fc.f_c_bout[0] = SURINT;

	fc.omb_atb[1] = NOIR;	/* couleur fond atb ombre */
	fc.omb_atb[2] = GRIS;  /* couleur caract ombre */
	fc.omb_atb[0] = SOUSINT;

	fc.f_bouton[1]  = BLANC;	/* atb bouton boite dial */
	fc.f_bouton[2]  = BLANC_INT;
	fc.f_bouton[0]  = VIDEO;
	fc.mouse_inhibit = 1;


	/* STYLES DE CADRES */

	/* cadre simple */
	fc.f_cadr1[0] = SCHG;	/* Coin Haut Gauche */
	fc.f_cadr1[1] = SBH;	/* Bord Haut        */
	fc.f_cadr1[2] = SCHD;	/* Coin Haut Droit  */
	fc.f_cadr1[3] = SBD;	/* Bord Droit	   */
	fc.f_cadr1[4] = SCBD;   /* Coin Bas Droit   */
	fc.f_cadr1[5] = SBB;	/* Bord Bas	   */
	fc.f_cadr1[6] = SCBG;	/* Coin Bas Gauche  */
	fc.f_cadr1[7] = SBG;	/* Bord Gauche	   */

	/* cadre double */
	fc.f_cadr2[0] = DCHG;	/* Coin Haut Gauche */
	fc.f_cadr2[1] = DBH;	/* Bord Haut        */
	fc.f_cadr2[2] = DCHD;	/* Coin Haut Droit  */
	fc.f_cadr2[3] = DBD;	/* Bord Droit	   */
	fc.f_cadr2[4] = DCBD;   /* Coin Bas Droit   */
	fc.f_cadr2[5] = DBB;	/* Bord Bas	   */
	fc.f_cadr2[6] = DCBG;	/* Coin Bas Gauche  */
	fc.f_cadr2[7] = DBG;	/* Bord Gauche	   */

	/* cadre personnalise */
	fc.f_cadr3[0] = '*';	/* Coin Haut Gauche */
	fc.f_cadr3[1] = '-';	/* Bord Haut        */
	fc.f_cadr3[2] = '*';	/* Coin Haut Droit  */
	fc.f_cadr3[3] = '!';	/* Bord Droit	   */
	fc.f_cadr3[4] = '*';    /* Coin Bas Droit   */
	fc.f_cadr3[5] = '-';	/* Bord Bas	   */
	fc.f_cadr3[6] = '*';	/* Coin Bas Gauche  */
	fc.f_cadr3[7] = '!';	/* Bord Gauche	   */

	/* caracteres particuliers */

	fc.f_cfond   = ' ';
	fc.f_cseph   = 0xc4;
	fc.f_cmactif = 0xfb;
	fc.f_clactif = 0xfb;
	fc.f_cchain  = 0xfe;

	/* touches speciales */

	fc.f_tvalid   = 0x0d;
	fc.f_tesc     = 0x1b;
	fc.f_tback    = 0x2d;
	fc.f_tdroite  = 0x06;
	fc.f_tgauche  = 0x08;
	fc.f_thaut    = 0x0b;
	fc.f_tbas     = 0x05;
	fc.f_tpghaut  = 0x12;
	fc.f_tpgbas   = 0x03;
	fc.f_tpgdroite= 0x04;
	fc.f_tpggauche= 0x07;
	fc.f_thome    = 0x1c;
	fc.f_tend     = 0x02;
	fc.f_ttab     = 0x09;
	fc.f_taide    = 0x0A;

	fc.f_efecran    =0x10;
	fc.f_efdebl     =0x15;
	fc.f_effinl     =0x18;
	fc.f_centre     =0x0c;
	fc.f_supsuiv    =0x7f;
	fc.f_supprec    =0x07;
	fc.f_inslig     =0x1e;
	fc.f_suplig     =0x19;
	fc.f_inscar     =0x0f;
	fc.f_msuiv      =0x01;
	fc.f_mprec      =0x04;
	fc.f_bd_elprec  =0x00;

	/* styles de fenetres */

	/* discrete avec cadre */
	fc.f_stf1[0] = 1;
	fc.f_stf1[2] = BLEU;
	fc.f_stf1[3] = BLANC;
	fc.f_stf1[1] = NORMAL;
	fc.f_stf1[5] = BLEU;
	fc.f_stf1[6] = BLANC;
	fc.f_stf1[4] = NORMAL;

	/* voyante avec cadre */
	fc.f_stf2[0] = 2;
	fc.f_stf2[2] = BLEU;
	fc.f_stf2[3] = BLANC_INT;
	fc.f_stf2[1] = SURINT;
	fc.f_stf2[5] = BLEU;
	fc.f_stf2[6] = BLANC_INT;
	fc.f_stf2[4] = SURINT;

	/* discrete sans cadre */
	fc.f_stf3[0] = 0;
	fc.f_stf3[2] = BLEU;
	fc.f_stf3[3] = GRIS;
	fc.f_stf3[1] = SOUSINT;
	fc.f_stf3[5] = BLEU;
	fc.f_stf3[6] = BLANC;
	fc.f_stf3[4] = NORMAL;


	/* voyante avec cadre */
	fc.f_stf4[0] = 2;
	fc.f_stf4[2] = ROUGE;
	fc.f_stf4[3] = NOIR;
	fc.f_stf4[1] = SURINT;
	fc.f_stf4[5] = ROUGE;
	fc.f_stf4[6] = NOIR;
	fc.f_stf4[4] = SURINT;


	/* diverse */
	fc.f_stf5[0] = 1;
	fc.f_stf5[2] = VERT;
	fc.f_stf5[3] = NOIR;
	fc.f_stf5[1] = SURINT;
	fc.f_stf5[5] = VERT;
	fc.f_stf5[6] = NOIR;
	fc.f_stf5[4] = SURINT;

	/* status */


	if (!( MAXLIG ))
		get_cons();

#ifdef PROL
	fc.f_lslig = 24;
#else
#ifdef	BEFORE_20102003
	fc.f_lslig = 23;
#else
	fc.f_lslig = (MAXLIG-1);
#endif
#endif
	fc.f_lscol = 2;
	/* boite validation */
	fc.f_bvlig = 18;
	fc.f_bvstf  = 1;

	/* fond */
	fc.f_mode = 6;

  };  /* set parametres par defaut */

/***********************************
* CHARGEMENT DES CODES INTERNES    *
************************************/

fond.carf.car   = fc.f_cfond;
fond.carf.ccolf = fc.f_fond[1];
fond.carf.ccolc = fc.f_fond[2];
fond.carf.catbc = fc.f_fond[0];

for (i=0;i<8;++i)
   {
	stc[0].trait[i] = fc.f_cadr1[i];
	stc[1].trait[i] = fc.f_cadr2[i];
	stc[2].trait[i] = fc.f_cadr3[i];
   };

/* styles fenetres */

stf[0].f_nostc = fc.f_stf1[0];
stf[0].f_cad.colf = fc.f_stf1[2];
stf[0].f_cad.colc = fc.f_stf1[3];
stf[0].f_cad.atbc = fc.f_stf1[1];
stf[0].f_fond.colf = fc.f_stf1[5];
stf[0].f_fond.colc = fc.f_stf1[6];
stf[0].f_fond.atbc = fc.f_stf1[4];
stf[0].f_ombre = 0;

stf[1].f_nostc = fc.f_stf2[0];
stf[1].f_cad.colf = fc.f_stf2[2];
stf[1].f_cad.colc = fc.f_stf2[3];
stf[1].f_cad.atbc = fc.f_stf2[1];
stf[1].f_fond.colf = fc.f_stf2[5];
stf[1].f_fond.colc = fc.f_stf2[6];
stf[1].f_fond.atbc = fc.f_stf2[4];
stf[1].f_ombre = 0;

stf[2].f_nostc = fc.f_stf3[0];
stf[2].f_cad.colf = fc.f_stf3[2];
stf[2].f_cad.colc = fc.f_stf3[3];
stf[2].f_cad.atbc = fc.f_stf3[1];
stf[2].f_fond.colf = fc.f_stf3[5];
stf[2].f_fond.colc = fc.f_stf3[6];
stf[2].f_fond.atbc = fc.f_stf3[4];
stf[2].f_ombre = 0;

stf[3].f_nostc = fc.f_stf4[0];
stf[3].f_cad.colf = fc.f_stf4[2];
stf[3].f_cad.colc = fc.f_stf4[3];
stf[3].f_cad.atbc = fc.f_stf4[1];
stf[3].f_fond.colf = fc.f_stf4[5];
stf[3].f_fond.colc = fc.f_stf4[6];
stf[3].f_fond.atbc = fc.f_stf4[4];
stf[3].f_ombre = 0;

stf[4].f_nostc = fc.f_stf5[0];
stf[4].f_cad.colf = fc.f_stf5[2];
stf[4].f_cad.colc = fc.f_stf5[3];
stf[4].f_cad.atbc = fc.f_stf5[1];
stf[4].f_fond.colf = fc.f_stf5[5];
stf[4].f_fond.colc = fc.f_stf5[6];
stf[4].f_fond.atbc = fc.f_stf5[4];
stf[4].f_ombre = 0;

for ( i = 0; i < 5; i++)
    tb_style[i] = 1;		/* styles 1..5 actifs */

for ( ; i < MAXSTF+1; i++ )
	tb_style[i] = 0;		/* styles 5..13 non actifs */

/* type d'affichage */

co.o_seph = fc.f_cseph;			/* separateur menu */
co.o_carcle.colf = fc.f_souligne[1];    /* atb carct cl‚ */
co.o_carcle.colc = fc.f_souligne[2];
co.o_carcle.atbc = fc.f_souligne[0];

co.o_grise.colf = fc.f_sousint[1];      /* atb gris‚ */
co.o_grise.colc = fc.f_sousint[2];
co.o_grise.atbc = fc.f_sousint[0];

co.o_actif.car = fc.f_cmactif;         	/* caractere option menu active */
co.o_actif.ccolf = fc.f_surint[1];     	/* attribut element actif */
co.o_actif.ccolc = fc.f_surint[2];
co.o_actif.catbc = fc.f_surint[0];

co.o_lactif = fc.f_clactif;		/* caractere element actif liste */

co.o_chain.car = fc.f_cchain;		/* caractere chainage menu */
co.o_chain.ccolf = fc.f_surint[1];	/* attribut option positionn‚e */
co.o_chain.ccolc = fc.f_surint[2];
co.o_chain.catbc = fc.f_surint[0];

co.o_selec.colf = fc.f_barsel[1];	/* attribut barre selection */
co.o_selec.colc = fc.f_barsel[2];
co.o_selec.atbc = fc.f_barsel[0];

co.el_bd_inact.colf = fc.f_bd[1];   	/* attribut element inactif */
co.el_bd_inact.colc = fc.f_bd[2];   	/* boite de dialogue      */
co.el_bd_inact.atbc = fc.f_bd[0];

co.c_cle_bout.colf = fc.f_c_bout[1];	/* attribut clef boutons */
co.c_cle_bout.colc = fc.f_c_bout[2];	/* boite de dialogue	   */
co.c_cle_bout.atbc = fc.f_c_bout[0];

co.bout.colf = fc.f_bouton[1];	/* attribut clef boutons */
co.bout.colc = fc.f_bouton[2];	/* boite de dialogue	   */
co.bout.atbc = fc.f_bouton[0];

#ifdef	BEFORE_20102003
#else
if (fc.f_lslig > (MAXLIG-1))	
	fc.f_lslig = (MAXLIG-1);	/* Limit to legal position 	*/
#endif

ls.s_plig = fc.f_lslig;			/* position ligne status 	*/
ls.s_pcol = fc.f_lscol;

ls.s_warn.colf = fc.f_sousint[1];
ls.s_warn.colc = fc.f_sousint[2];
ls.s_warn.atbc = fc.f_sousint[0];

ls.s_impt.colf = fc.f_normal[1];
ls.s_impt.colc = fc.f_normal[2];
ls.s_impt.atbc = fc.f_normal[0];

ls.s_ess.colf =  fc.f_surint[1];
ls.s_ess.colc =  fc.f_surint[2];
ls.s_ess.atbc =  fc.f_surint[0];

bvc.v_plig = fc.f_bvlig;
bvc.v_stf  = fc.f_bvstf;

tc[SPACE-1] = 0x20;
tc[T_ENVOI-1]=fc.f_tvalid;
tc[T_ESC-1]=fc.f_tesc;
tc[BACK_SP-1]=fc.f_tback;
tc[F_DROITE-1]=fc.f_tdroite;
tc[F_GAUCHE-1]=fc.f_tgauche;
tc[F_HAUT-1]=fc.f_thaut;
tc[F_BAS-1]=fc.f_tbas;
tc[PG_UP-1]=fc.f_tpghaut;
tc[PG_DOWN-1]=fc.f_tpgbas;
tc[PG_DROITE-1]=fc.f_tpgdroite;
tc[PG_GAUCHE-1]=fc.f_tpggauche;
tc[T_HOME-1]=fc.f_thome;
tc[T_END-1]=fc.f_tend;
tc[T_TAB-1]=fc.f_ttab;
tc[T_AIDE-1]=fc.f_taide;
tc[EFECRAN-1]=fc.f_efecran;
tc[EFDEBL-1]=fc.f_efdebl;
tc[EFFINL-1]=fc.f_effinl;
tc[CENTRE-1]=fc.f_centre;
tc[SUPSUIV-1]=fc.f_supsuiv;
tc[SUPPREC-1]=fc.f_supprec;
tc[INSLIG-1]=fc.f_inslig;
tc[SUPLIG-1]=fc.f_suplig;
tc[INSCAR-1]=fc.f_inscar;
tc[T_MSUIV-1]=fc.f_msuiv;
tc[T_MPREC-1]=fc.f_mprec;
tc[SHIFT_TAB-1] = fc.f_bd_elprec;		/* llb 29.10.92 */


fond.mode = fc.f_mode;


omb_atrib = (fc.omb_atb[1] << 4) + fc.omb_atb[2];
omb_atrib  += fc.omb_atb[0] << 8;

/****************/
/* init du fond */
/****************/

sf_er = winit(fond.mode,fond.carf.car,fond.carf.catbc,fond.carf.ccolc,fond.carf.ccolf);	/* init fenetres */

if (sf_er) return(sf_er);

fen_ini = 2;

/*******************/
/* init des status */
/*******************/
ls_nfenu = 0;
sf_er = lsacti();		/* init par defaut */

/*******************
* init des menus   *
********************/
for (i=0;i < MAXMEN;++i) md[i].m_nofen = 0;
nomena = 0;
cpt_e = 0;
last_men = 0;
/*******************
* init des listes  *
********************/
for (i=0;i < MAXLD;++i)  ld[i].l_nofen = 0;
for (i=0; i< MAXCOL;++i) lispace[i] = ' ';

/*******************
* init des boites  *
********************/
bv_f = 0;
bv_m = 0;

/*******************
* Init Dialogues   *
*******************/
for(i = 0; i < MAX_DIAL; i++)
  TB_BOX[i].no_log = 0;


/*******************
* init de l'aide   *
********************/
sa_touche = tc[T_AIDE-1];	/* SB le 4/7/90 modif pour eviter les 	*/
tc[T_AIDE-1] = 0x0d;		/* interferences dans l'aide menu liste */
sa_mcled[0] = 0;
sa_ptf = (FILE *) NULL;
/*******************
* Init MOUSE       *
*******************/
  Wkup_Adress = (BPTR) NULL;
  Wkup_Mask = NULL;

  mousson = FALSE;
  for (i = 0;i < MAXFUN; i++)
      mouse_item_list[i] = FALSE;	/* RAZ fenetres mouse_sensitives	*/

  bouton = 0;
  if (fc.mouse_inhibit ==0)
     mous_is = FALSE;
  else {
	mous_is = TRUE;
	if ( InitSouris(&bouton) == 56)		/* init mouse mode texte*/
	    mous_is = FALSE;			/* driver mouse non install‚ ! */
	if ( mous_is)
	  {

		mouse_on() ;		       		/* curseur ON*/
		PopSouris();

#ifdef PRL
		PrlFlushEvent();
		SetEventMask(MOUSE_DOWN+MOUSE_UP+MOUSE_D_CLICK+MOUSE_M_W_DOWN+MOUSE_IS_DOWN+0x7000); /* 7000 signifie */
#endif												/* bouton 1,2,3 */
	}/* if mous_is */ 
	event.event = NO_EVENT;
  }/*else*/

if ((k != -1) && (j == -1))
 return (sferr_inex);      /* fichier inexistant */
else
 return(OK);		   /* fichier existant ou blanc */

}





/*******************************************
* liberation de tout le service            *
********************************************/

TYPF sfend()
{

/* fonctions appelees */
TYPF ld_sup();
TYPF md_sup();
TYPF lsdesac();
TYPF wend();
/* variables externes 
extern BYTE nomena;
extern BYTE bv_m;
extern WORD bf_f;
extern BYTE fen_ini;
*/

WORD er,i;

/* execution sans tests d'erreurs */

	ld_sup(0);
	md_sup(0);
	lsdesac();
/*	nomena = 0;
	bv_m = 0;
	bv_f = 0;
*/
	for ( i = 1; i < MAXFUN ; i++)
		bd_supc(i);
/*llb 160993 : INUTILE */
/*llb 240694 : Si, qd on sort de l'appli sous dos */
#ifndef unix
if ((mous_is) && (mousson))			/* Si souris OK */
	PushSouris(); 				/* OFF curseur souris	*/
#endif
	er = wend();

	return(er);
}

/* fin du source */
