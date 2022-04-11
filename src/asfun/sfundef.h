/************************************************
* Services Fenetres - Definitions sf		*
*-----------------------------------------------*
* Source : sfundef.h		    		*
*-----------------------------------------------*
* Version : 1.1a		    		*
* Mise a jour le : 08/03/1990	sb  		*
* MAJ llb  18.07.91 :	Adaptation Boites Dial. *
*     llb  21.07.94 :   Structure option menu   *
************************************************/

#ifndef	_sfundef_h
#define	_sfundef_h

#include "fundef.h"

#define sf_vers '1'
#define sf_ind	'3'
#define sf_niv	'a'
#define sf_ind4	'4'


/***************************************
*  limites du service		       *
****************************************/
/*
* config
*/
#define MAXSTC	3			/* nbre de styles de cadres   */
#define MAXSTF	13			/* nbre de styles de fenetres */
#define MAX_TOUCHES 35
#define	STYLMAX	27
/*
* menus
*/
#define MAXMEN	33			/* nbre menus */
#define MAXENCH 15			/* nbre d'enchainements max */
#define MAXOPM	30			/* nbre options max	    */
/*
* listes
*/
#define MAXLD	33			/* Nbre de listes */
#define MAXELL	9999			/* Nbre d'elements max */

/*
* Dialogues
*/
#define MAX_DIAL	8		/* Nb maxi boŒtes de dialogue	*/

/*
* Touches d'echappement
*/
#define NB_MAX_TCH_ESC	32		/* le nb maxi de touches	*/

/*
* Codes retour des elements ASFUN
*/
#define TAB		0x09
#define RC		0x0D
#define ESC		0x1B


/************************
*  structures standard	*
*************************/

typedef struct ATBV			/* attributs video */
{
	BYTE	atbc;			/* Attribut N/B caractere */
	BYTE	colf;			/* Couleur de fond */
	BYTE	colc;			/* Couleur de caractere */
} atbv;

typedef struct ATBC			/* attributs caractere */
{
	BYTE	car;			/* Code caractere */
	BYTE	catbc;			/* Attribut N/B caractere */
	BYTE	ccolf;			/* Couleur de fond */
	BYTE	ccolc;			/* Couleur de caractere */
} atbc;

typedef struct STC_DESC 		/* cadres */
{
	BYTE	trait[8];
} stc_desc;

typedef struct STF_DESC 		/* fenetres */
{
	BYTE	f_nostc;		/* numero style de cadre */
	atbv	f_cad;			/* attributs cadre	 */
	atbv	f_fond; 		/* attributs  fond	 */
	BYTE	f_ombre;		/* indicateur ombre 	 */
} stf_desc;

/* donnees configuration */

typedef struct	COF_TAB
{
atbv	o_carcle;		/* caractere cle   */
atbc	o_actif;		/* caractere actif menu */
atbv	o_grise;		/* attribut grise  */
atbv	o_selec;		/* barre selection */
atbc	o_chain;		/* caractere chaine */
BYTE	o_seph; 		/* separateur horizontal */
BYTE	o_lactif;		/* temoin activite liste */
atbv	el_bd_inact;  		/* attribut element boite dialogue inactif */
atbv    c_cle_bout;		/* attribut car. clef des boutons */
atbv	bout;
} cof_tab;

/*********************/
/* pour sfinit	      */
/*********************/

typedef struct FOND_TAB
{
BYTE	mode;
atbc	carf;
} fond_tab;
/*********************/
/* pour get/ set_style */
/*********************/

typedef struct
{
 BYTE arg1;
 BYTE arg2;
 BYTE arg3;
 BYTE arg4;
 BYTE arg5;
 BYTE arg6;
 BYTE arg7;
 BYTE arg8;
} STYL_DESC;

/*********************/
/* pour ligne status */
/*********************/

/* donnees configuration */

typedef struct	LS_TAB
{
int	s_plig; 		/* position ligne   */
int	s_pcol; 		/* position colonne */
atbv	s_warn; 		/* attributs type 1 */
atbv	s_impt; 		/* attributs type 2 */
atbv	s_ess;			/* attributs type 3 */
} ls_tab;

/*********************/
/* pour boite valid  */
/*********************/

/* donnees configuration */

typedef struct	BV_TAB
{
int	v_plig; 		/* position ligne   */
int	v_pcol; 		/* position colonne */
BYTE	v_stf;			/* type de fenetre  */
} bv_tab;

/************************
* pour menus deroulants *
*************************/

/* structure descripteur d'entree  menu */

typedef struct	 MD_DESC
{
BYTE	md_stlf;		/* style fenetre    */
WORD	md_plig;		/* position ligne   */
WORD	md_pcol;		/* position colonne */
BYTE	md_titr[TAIL_TITRE];	/* titre	    */

BYTE	md_typm;		/* type (1=Hz, 2=Vt)*/
BYTE	md_esc; 		/* type Esc	    */

BYTE	md_nbel;		/* nbre elements    */
BYTE	md_lel; 		/* longueur valeur  */
BYTE	md_laff;		/* longueur affichee*/
BYTE	md_lcom;		/* longueur commentaires */
} md_desc;


/* equivalence dans le buffer ABAL */

#define MD_stlf 0		/* style fenetre    */
#define MD_plig 1		/* position ligne   */
#define MD_pcol 3		/* position colonne */
#define MD_titr 5		/* titre	    */
#define MD_typm 37		/* type (1=Hz, 2=Vt)*/
#define MD_esc 38		/* type Esc	    */
#define MD_nbel 39		/* nbre elements    */
#define MD_lel 40		/* longueur valeur  */
#define MD_laff 41		/* longueur affichee*/
#define MD_lcom 42		/* longueur commentaires */



/* structure descripteur interne option */

typedef struct	MO_TAB
{
BYTE	mo_type;		/* type d'element : 0 bl 1 sep 2 opt */

BYTE	mo_carcle;
BYTE	mo_eff;
BYTE	mo_ataff;
BYTE	mo_atsel;
BYTE	mo_atetat;
BYTE	mo_menc;
BYTE	mo_optc;

BYTE	mo_indm;		/* indicateur modif depuis affichage */
BYTE	mo_tst;
BYTE	mo_col;			/* position libelle (si horizontal variable */
BYTE	mo_lng;			/* taille libelle (si horizontal variable */
} mo_tab;

/* structure descripteur interne menu */

typedef struct	MD_TAB	{
	WORD	m_nofen;
	BYTE	m_typm; 		/* sauvegarde des parametres */
	BYTE	m_esc;
	BYTE	m_nbel;
	BYTE	m_lel;
	BYTE	m_laff;
	BYTE	m_lcom;

	BYTE	m_inda; 		/* indicateur affichage     */
	BYTE	m_indm; 		/* indicateur modification  */
	BYTE	m_nopp; 		/* option positionnee	    */
	mo_tab_ptr  m_ptro;		/* pointeur sur 1ere option */
	WORD	m_nofenc;		/* no fenetre commentaire   */
	atbv	m_at;			/* fond de fenetre */
	WORD	control;		/* Type de fonctionnement */
	BYTE	men_cle[9];		/* Cle AIDE contextuelle */
} md_tab;

/* descripteur liste des menus en cours */
typedef struct ME_TAB
{
BYTE	me_ma;			/* menu appelant */
BYTE	me_oa;			/* option appelante */
BYTE	me_mc;			/* menu chaine */
} me_tab;

/* structure descripteur d'entree option */

typedef struct	MO_DESC
{
BYTE	mod_carcle;
BYTE	mod_eff;
BYTE	mod_ataff;
BYTE	mod_atsel;
BYTE	mod_atetat;
BYTE	mod_menc;
BYTE	mod_optc;
} mo_desc;

/************************
* pour listes defilantes*
*************************/


#define NO_EFF	  	1	/* pas d'effacement de la liste au retour 	*/
#define SCROLL_V	2	/* scroll bar verticale				*/
#define SCROLL_H	4	/* Scroll bar Horizontale			*/
#define	SOR_SI_TAB	8	/* TAB provoque la sortie de Liste()      	*/
#define	NO_BV	  	16	/* Pas de boite de validation si LISMUL   	*/
#define TCH_ESC		32	/* sortie sur touches d'echappement             */
#define	SOR_PAR_HAUT	64	/* sortie par le haut				*/

/* structure descripteur d'entree  liste*/

typedef struct	 LD_DESC
{
BYTE	ld_stlf;		/* style fenetre    */
WORD	ld_plig;		/* position ligne   */
WORD	ld_pcol;		/* position colonne */
WORD	ld_nlig;		/* nombre de lignes */
BYTE	ld_titr[TAIL_TITRE];	/* titre	    */

BYTE	ld_typa;		/* type affichage (1=Hz, 2=Vt)*/
BYTE	ld_typd;		/* type defilement(1=Hz, 2=Vt)*/
BYTE	ld_nelh;		/* nombre de colonnes */
BYTE	ld_pscrol;		/* pas de scroll      */
BYTE	ld_cadre;		/* 1 = a gauche  2=centre */

WORD	ld_mxel;		/* nombre max d'el  */
BYTE	ld_lel; 		/* longueur valeur  */
BYTE	ld_laff;		/* longueur affichee*/
BYTE	ld_lcom;		/* longueur commentaires */

} ld_desc;


/* equivalence pour buffer ABAL unix */

#define LD_stlf 0		/* style fenetre    */
#define LD_plig 1		/* position ligne   */
#define LD_pcol 3		/* position colonne */
#define LD_nlig 5		/* nombre de lignes */
#define LD_titr 7		/* titre	    */

#define LD_typa 39		/* type affichage (1=Hz, 2=Vt)*/
#define LD_typd 40		/* type defilement(1=Hz, 2=Vt)*/
#define LD_nelh 41		/* nombre de colonnes */
#define LD_pscrol 42		/* pas de scroll      */
#define LD_cadre 43		/* 1 = a gauche  2=centre */

#define LD_mxel 44		/* nombre max d'el  */
#define LD_lel 46		/* longueur valeur  */
#define LD_laff 47		/* longueur affichee*/
#define LD_lcom 48		/* longueur commentaires */


/* structure de la fonction LIST_INFO */

typedef struct ld_info
{
WORD ld_fun;			/* No fenetre de la liste */
WORD ld_plig;			/* coors fenetre */
WORD ld_pcol;
WORD ld_nlig;
WORD ld_ncol;
BYTE ld_cad;			/* indicateur de cadre de la liste	*/
WORD ld_fatb;			/* attribut fenetre			*/
WORD ld_control;                /* mode de fonctionnement 		*/
WORD ld_type;                   /* Liste simple ou multiple 		*/
BYTE ld_val;			/* taille de la valeur d'un ‚l‚ment 	*/
} LD_INFO;


/* structure descripteur interne liste */

typedef struct	LD_TAB
{
BYTE	l_ferm; 	/* liste fermee = 1 ouverte = 2  */
BYTE	l_mult; 	/* liste a choix multiple */
WORD	l_nbel; 	/* nbre d elements crees */
WORD	l_nofen;	/* numero de fenetre	 */

BYTE	l_typa; 	/* type affichage (1=Hz, 2=Vt)*/
BYTE	l_typd; 	/* type defilement(1=Hz, 2=Vt)*/
BYTE	l_nelh; 	/* nombre d elements horizontaux */
BYTE	l_nlig; 	/* nombre de lignes   */
BYTE	l_pscrol;	/* pas de scroll      */
BYTE	l_cadre;	/* 1 = a gauche  2=centre */

WORD	l_mxel; 	/* max elements     */
BYTE	l_lel;		/* longueur valeur  */
BYTE	l_laff; 	/* longueur affichee*/
BYTE	l_lcom; 	/* longueur commentaires */

BYTE	l_inda; 	/* indicateur affichage     */
BYTE	l_indm; 	/* indicateur modification  */
WORD	l_nelv; 	/* 1er element visualise    */
WORD	l_nelp; 	/* element positionnee	     */
WORD	l_ncolt;	/* nombre de colonnes total */
WORD	l_nligt;	/* nombre de lignes total */
BPTRPTR l_ptre; 	/* pointeur sur table elements */
WORD	l_nofenc;	/* no fenetre commentaire   */

WORD	l_plig;
WORD	l_pcol;

WORD	l_nelc; 	/* element en cours en lecture */
atbv	l_at;		/* fond de fenetre */
BYTE	l_styf; 	/* style de fenetre */

WORD	l_bvf;		/* no fenetre pour boite validation mult */
BYTE	l_bvm;		/* no de menu pour boite validation mult */
WORD	control;	/* Type de fonctionnement */
BYTE	lis_cle[9];	/* Cle AIDE contextuelle */

} ld_tab;


/* structure descripteur d'entree boite spec */
typedef struct BV_DESC
{
BYTE	bv_nbc; 		/* nombre de choix   */
BYTE	bv_noptd;		/* option de depart  */
BYTE	bv_stlf;		/* style fenetre     */
WORD	bv_plig;		/* position ligne    */
WORD	bv_pcol;		/* position colonne  */
BYTE	bv_laff;		/* longueur affichee */
} bv_desc;

/* redefinition pour transfert ABAL */

#define BV_nbc 0		/* nombre de choix   */
#define BV_noptd 1		/* option de depart  */
#define BV_stlf  2		/* style fenetre     */
#define BV_plig  3		/* position ligne    */
#define BV_pcol  5		/* position colonne  */
#define BV_laff  7		/* longueur affichee */

/* flag ombrage */

#define SFOMB 8


/* messages standard */
#define EOS 0

#define MAXMES 17

#define MESSTV 1
#define MESST2 2
#define MESST3 3
#define MESV   4
#define MESO   5
#define MESN   6
#define MESA   7
#define MEST   8
#define MESMT  9
#define MESL   10
#define MESC   11
#define MESINS 12
#define MESAID 13
#define MESAIC 14
#define MESAIS 15
#define MES_O_CB 16
#define MES_N_CB 17

/* touches utilisees */

#define SPACE	1
#define F_HAUT	2
#define F_BAS	3
#define F_GAUCHE 4
#define F_DROITE 5
#define T_HOME 6
#define T_END 7
#define T_ESC 8
#define T_ENVOI 9
#define BACK_SP 10
#define T_TAB	11
#define PG_UP 12
#define PG_DOWN 13
#define PG_DROITE 14
#define PG_GAUCHE 15
#define T_AIDE 16
#define EFECRAN 17
#define EFDEBL 18
#define EFFINL 19
#define CENTRE 20
#define SUPSUIV 21
#define SUPPREC 22
#define INSLIG 23
#define SUPLIG 24
#define INSCAR 25
#define T_MSUIV 26
#define T_MPREC 27
#define SHIFT_TAB 28

/* variables externes */

extern	BYTE	fen_ini;		/* flag init */
extern	WORD	MAXCOL,MAXLIG;

/* codes erreurs specifiques */

#define RT_err_arg	10	/* erreur de nombre d'arguments 	*/
#define RT_err_typ	11	/* erreur dans type arg 		*/


#define sferr_inex	40
#define werr_exist	41
#define sferr_open	42
#define sfenr_inex	78
#define sfenr_fin	48
#define sfenr_deb	64
#define sfenr_exist	81

/* deFINE POUR unix */

#ifndef R_OK
#define R_OK		4
#endif /* R_OK */

/* prototypage des fonctions */

#include "wproto.h"


/* fin de fichier */

#endif	/* _sfundef_h */
	/* ---------- */

