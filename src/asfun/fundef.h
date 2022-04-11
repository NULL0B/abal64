/* composition de l'environnement */

#define	HX
#define	max_colonne asfun_max_colonne
#define max_ligne   asfun_max_ligne

#ifndef	_fundef_h
#define	_fundef_h

#include "wtype.h"                      /* types de donnees */

#ifdef PRL
#undef MSDOS
#define PROL
#endif

#ifdef DOS
#ifndef MSDOS
#define MSDOS
#endif
#define PROL
#endif

#ifdef ASFCICO
#include "asfcico.h"
#endif

/************************************
* Fenetrage    Definitions generales*
*-----------------------------------*
* Source : fundef.h		    *
*-----------------------------------*
* Version : 1.1a		    *
* Creation    le : 27/02/1989  LLB  *
* Mise a jour le : 08/03/1990	sb  *
*************************************/

#ifndef BOS
#include <malloc.h>
#endif

/* constantes  */

#define ESCAPE 27

#ifndef	NULL
#define NULL	0
#endif
#define ETX	3
#define WRES	1	/* indicateur WITEM reserve */
#define OK	0

#define TRUE	1
#define FALSE	0

#define MAXFUN	132	/* nbre max de fenetres gerees */
#define LTAB	8	/* Pas d'une tabulation */

#define HAUT	1	/* directions du scroll */
#define BAS	2
#define DROITE	3
#define GAUCHE	4

/* codage des attributs video */

#define NORMAL		0
#define VIDEO		1
#define SOULIGNE	2
#define SOUSINT 	4
#define SURINT		8
#define CLIGNOT 	128

/* codage des couleurs */

#define NOIR		0
#define ROUGE		1
#define VERT		2
#define MARRON		3
#define BLEU		4
#define MAGENTA 	5
#define CYAN		6
#define BLANC		7	/* GRIS CLAIR */
#define GRIS		8
#define ROUGE_CL	9
#define VERT_CL 	10
#define JAUNE		11
#define BLEU_CL 	12
#define MAGENTA_CL	13
#define CYAN_CL 	14
#define BLANC_INT	15

/* fonctions generique WFGEN */

#define CLFUN	   1		/* clear fenetre     */
#define CLEOF	   2		/* clear fin fenetre */
#define CLEOL	   3		/* clear fin ligne   */
#define INS_LIG    4		/* insertion ligne   */
#define SUP_LIG    5		/* suppression ligne */
#define SCROL_UP   6		/* haut   */
#define SCROL_DW   7		/* bas	  */
#define SCROL_DR   8		/* droite */
#define SCROL_GA   9		/* gauche */

#define CUROF	  11		/* allumer curseur */
#define CURON	  10		/* eteindre curseur */
#define INS_CAR   12		/* insertion caractere sur une ligne */
#define SUP_CAR   13		/* suppress  caractere sur une ligne */
#define CLBOL	  14		/* effacer debut de ligne */

/* constantes fenetre */

#define TAIL_TITRE 32		/* 32 caracteres pour le titre	*/
#define INVISIBLE   1		/* flag invisible		*/
#define VISIBLE    0xfffe	/* inverse de "INVISIBLE        */
#define CURSEUR     2		/* curseur visible		*/
#define SCROLL	    4		/* flag scroll			*/
#define CAD1	    8		/* cadre simple trait		*/
#define CAD2	   16		/* cadre double trait		*/
#define CAD3	   32		/* cadre utilisateur		*/
#define ARPCURS	   64		/* Curseur si Arriere plan	*/
#define OMBRE	  128		/* fenetre ombr‚e		*/

#define	TOP	   0x8000	/* fenetre hors chainage pour exadb*/

/* codage des caracteres composant le cadre fenetre */

#define SCHG	0xda	/* Simple Coin Haut Gauche	*/
#define SBH	0xc4	/* Simple Bord Haut		*/
#define SCHD	0xbf	/* Simple Coin Haut Droit	*/
#define SBD	0xb3	/* Simple Bord Droit		*/
#define SCBD	0xd9	/* Simple Coin Bas Droit	*/
#define SBB	0xc4	/* Simple Bord Bas		*/
#define SCBG	0xc0	/* Simple Coin Bas Gauche	*/
#define SBG	0xb3	/* Simple Bord Gauche		*/

#define DCHG	0xc9	/* Double Coin Haut Gauche	*/
#define DBH	0xcd	/* Double Bord Haut		*/
#define DCHD	0xbb	/* Double Coin Haut Droit	*/
#define DBD	0xba	/* Double Bord Droit		*/
#define DCBD	0xbc	/* Double Coin Bas Droit	*/
#define DBB	0xcd	/* Double Bord Bas		*/
#define DCBG	0xc8	/* Double Coin Bas Gauche	*/
#define DBG	0xba	/* Double Bord Gauche		*/

/* fonction MV2 */

#define AFFICHE 	0
#define POSCUR		16
#define SETCUR		17
#define SHOWCUR 	18
#define HIDECUR 	19
#define FILL		32
#define GSCROLL 	33
#define SETATB		34
#define SPEC		48

/* codes erreur */

#define werr_desc 1	/* parametre d'appel incorrect  */
#define werr_inex 2	/* fenetre inexistante		*/
#define werr_mem  27	/* panne memoire		*/
#define werr_ini  3	/* winit non effectuee		*/
#define werr_max  4	/* nbre fenetres max atteint	*/

/* description d'une fenetre */

typedef struct	desc_fun
{
   int	mere_nbr;	/* numero mere ou console */
   WORD pos_lig;	/* position fenetre */
   WORD pos_col;
   WORD nb_lig; 	/* taille  fenetre */
   WORD nb_col;

   WORD control;	/* bit 0 = 1  (1): Invisible	 */
			/* bit 1 = 1  (2): Curseur actif */
			/* bit 2 = 1  (4): SCROLL actif  */
			/* bit 3 = 1  (8): Cadre simple trait */
			/* bit 4 = 1 (16): Cadre double trait */
			/* bit 5 = 1 (32): Cadre utilisateur  */
   WORD ln_tit; 	/* longueur titre */
   BYTE titre[TAIL_TITRE];/* Titre fenetre (32 caracteres maxi) */
   BYTE cadre[8];
   WORD cur_lig;
   WORD cur_col;	/* curseur courant 		*/
   BPTR adr_text;	/* adresse data fenetre 	*/
   BPTR adr_fore;	/* adresse foreground map	*/
   BPTR adr_back;	/* adresse background map	*/
   BPTR adr_media;	/* adresse media map		*/
   WPTR adr_atb;	/* adresse atributs fenetre	*/
   WORD cur_fg;		/* RGB text colour index	*/
   WORD cur_bg;		/* RGB wash colour index	*/
   WORD cur_atb;	/* attribut courant 		*/
   WORD cad_atb;	/* attribut courant du cadre 	*/
   WORD cad_fg;		/* RGB text frame colour 	*/
   WORD cad_bg;		/* RGB back frame colour	*/
   WORD tit_atb;	/* attribut courant du titre 	*/
   WORD bas_atb;	/* memo attribut creation 	*/
   WORD bas_fg;		/* memo RGB text creation 	*/
   WORD bas_bg;		/* memo RGB wash creation 	*/
   BYTE cad;		/* 0: pas de cadre , 1: cadre 	*/
   BYTE cur;		/* 0: curseur OFF 1: curseur ON */
   BYTE gel;		/* gel fenetre			*/
} WDESC;

/* Chainage de superposition et filiation des fenetres */
/* --------------------------------------------------- */

typedef struct	item_fenetre
   {
   struct item_fenetre *mere;	/* Witem fenetre mere	      */
   struct item_fenetre *fsur;	/* Fun qui se trouve sur moi  */
   struct item_fenetre *fsous;	/* Fun qui se trouve sous moi */
   struct item_fenetre *fille;	/* Witem fenetre fille	      */
   WDESC_PTR wdesc_ptr; 	/* ptr descripteur fenetre    */
} WITEM;

/* structure du descripteur d'appel MV2  */
/* ------------------------------------  */
typedef struct appel_mv2
{
    WORD	ln_desc;	/* longueur descripteur 	*/
    WORD	ncons;		/* No Console			*/
    WORD	nfonc;		/* fonction			*/
    WPTR	adr_atb;	/* Adresse  attribut / app_mv2	*/
    BPTR	adr_text;      	/* Adresse  texte/ app_mv2	*/
    BPTR	adr_fore;      	/* Adresse  texte/ app_mv2	*/
    BPTR	adr_back;      	/* Adresse  texte/ app_mv2	*/
    BPTR 	adr_media;	/* adresse media map		*/
    WORD	inc_buf;	/* Increment buffer		*/
    WORD	mvlig;		/* Position ligne		*/
    WORD	mvcol;		/* Position colonne		*/
    WORD	mvnblig;	/* Nbre lignes			*/
    WORD	mvnbcol;	/* Nbre colonnes		*/
    WORD	reserve;	/* pour extension		*/

/* sauvegarde des adresses buffer standard (ne fait pas partie de l'appel )*/
    WPTR	std_atb;
    BPTR	std_text;

} APP_MV2;

/* structure du descripteur d'appel de la fonction WCREAT */
/* ------------------------------------------------------ */

typedef struct desc_creat_fun {
	int Amere_nbr;			/* numero mere ou console */
	WORD Apos_lig;			/* position ligne   */
	WORD Apos_col;			/* position colonne */
	WORD Anb_lig;			/* Nombre de lignes */
	WORD Anb_col;			/* Nombre de colonnes */

	BYTE Aatb_vid;			/* attribut video texte */
	BYTE Aatbcol_text;		/* couleur texte */
	BYTE Aatbcol_fond;		/* couleur fond */

	WORD Acontrol;			/* bit 0 = 1  (1): Invisible	 */
					/* bit 1 = 1  (2): Curseur actif */
					/* bit 2 = 1  (4): SCROLL actif  */
					/* bit 3 = 1  (8): Cadre simple trait */
					/* bit 4 = 1 (16): Cadre double trait */
					/* bit 5 = 1 (32): Cadre utilisateur  */
	WORD Aln_tit;			/* Longueur titre */
	BYTE Atitre[TAIL_TITRE];	/* Titre fenetre  */
	BYTE Acad_usr[8];		/* Cadre utilisateur */
	BYTE Acad_atb ; 		/* attribut cadre user */
	BYTE Acad_text; 		/* couleur texte cadre user */
	BYTE Acad_fond; 		/* couleur fond cadre user */
	BYTE reserve;
} WDESC_APP;

/*********************************
* Transfert de la structure ABAL *
**********************************/

#define Bmere_nbr	0	/* numero mere ou console		*/
#define Bpos_lig	2	/* position ligne			*/
#define Bpos_col	4	/* position colonne			*/
#define Bnb_lig 	6	/* Nombre de lignes			*/
#define Bnb_col 	8	/* Nombre de colonnes			*/
#define Batb_vid	10	/* attribut video texte 		*/
#define Batbcol_text	11	/* couleur texte			*/
#define Batbcol_fond	12	/* couleur fond 			*/
#define Bcontrol	13	/* bit 0 = 1  (1): Invisible		*/
				/* bit 1 = 1  (2): Curseur actif	*/
				/* bit 2 = 1  (4): SCROLL actif 	*/
				/* bit 3 = 1  (8): Cadre simple trait	*/
				/* bit 4 = 1 (16): Cadre double trait	*/
				/* bit 5 = 1 (32): Cadre utilisateur	*/
#define Bln_tit 	15	/* Longueur titre			*/
#define Btitre		17	/* Titre fenetre			*/
#define Bcad_usr	49	/* Cadre utilisateur			*/
#define Bcad_atb	57	/* attribut cadre user			*/
#define Bcad_text	58	/* couleur texte cadre user		*/
#define Bcad_fond	59	/* couleur fond cadre user		*/
#define Breserve	60

/* prototypage des fonctions de base */

#include "wtypf.h"

/* Les macros pour acceder aux WORD et BYTE d'ABAL pour les idiot */

#include "abal.h"
#include "bdacico.h"

#endif	/* _fundef_h */
