#ifndef	_asfun_h
#define	_asfun_h

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
#define	OMBRE	  128		/* window has shadow		*/


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


#endif	/* _asfun_h */
	/* -------- */

