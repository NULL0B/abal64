/*
 *	CICO - Interface ECRAN / CLAVIER / IMPRIMANTE
 *	---------------------------------------------
 *
 *	Copyright (c) 1989 Amenesik / Sologic s.a.
 *
 *	cico.h - definitions communes
 *
 *	$Header: /home/Produits/Abal3/asfun/_cico.h,v 1.1.1.1 2003/11/04 23:40:49 root Exp $
 *
 */


#include "_type.h"


/*
 *	constantes diverses
 *	-------------------
 */

#define TAMPON		0		/* numero peripherique tampon	*/
#define ECRAN		1		/* numero peripherique ecran	*/

#define CO		1
#define CI		2
#define LO		4


/*
 *	caracteres de controle
 *	----------------------
 */

#define ACK	'\006'                  /* acknowledge                  */
#define BEL	'\007'                  /* bell                         */
#define BS	'\010'                  /* backspace                    */
#define HT	'\011'                  /* horizontal tab               */
#define LF	'\012'                  /* line feed                    */
#define FF	'\014'                  /* form feed                    */
#define CR	'\015'                  /* carriage return              */
#define SUB	'\032'                  /* substitute                   */
#define ESC	'\033'                  /* escape                       */
#define FS	'\034'                  /* form separator               */


/*
 *	etats de l'automate de conversion en sortie sur un peripherique
 *	---------------------------------------------------------------
 */

#define ETAT_STANDARD		0	/* etat standard		*/
#define ETAT_ESCAPE		1	/* esc				*/
#define ETAT_POS_1		2	/* esc f			*/
#define ETAT_POS_2		3	/* esc f x			*/
#define ETAT_TRANS_1		4	/* esc T			*/
#define ETAT_TRANS_2		5	/* esc T low_byte		*/
#define ETAT_TRANS_3		6	/* esc T low_byte high_byte	*/
#define ETAT_DEFAUT		7	/* esc n			*/
#define ETAT_TEXTE		8	/* esc r			*/
#define ETAT_FOND		9	/* esc s			*/
#define ETAT_ESCAPE_ESCAPE	10	/* esc esc			*/


/*
 *	attribut courant sur un peripherique
 *	------------------------------------
 */

#define A_NORMAL		0	/* aucun attribut		*/
#define A_STANDOUT		1	/* preferentiel 		*/
#define A_REVERSE		2	/* inversion video		*/
#define A_BLINK 		3	/* clignotement 		*/
#define A_UNDERLINE		4	/* soulignement 		*/
#define A_DIM			5	/* sous-brillance		*/
#define A_BOLD			6	/* sur-brillance		*/
#define A_BOLD			1	/* italic is preferential	*/

#define C_BLACK 		0	/* noir 			*/
#define C_RED			1	/* rouge			*/
#define C_GREEN 		2	/* vert 			*/
#define C_BROWN 		3	/* marron / jaune fonce 	*/
#define C_BLUE			4	/* bleu 			*/
#define C_MAGENTA		5	/* magenta			*/
#define C_CYAN			6	/* cyan 			*/
#define C_WHITE 		7	/* gris clair / blanc		*/
#define C_GREY			8	/* gris fonce			*/
#define C_LIGHT_RED		9	/* rouge clair			*/
#define C_LIGHT_GREEN		10	/* vert clair			*/
#define C_YELLOW		11	/* jaune			*/
#define C_LIGHT_BLUE		12	/* bleu clair			*/
#define C_LIGHT_MAGENTA 	13	/* magenta clair		*/
#define C_LIGHT_CYAN		14	/* cyan clair			*/
#define C_INTENSE_WHITE 	15	/* blanc brillant		*/


/*
 *	structures de description d'ecran
 *	---------------------------------
 */

#ifndef MSDOS
typedef struct {
	BYTE *caractere;		/* caracteres			*/
	BYTE *attribut; 		/* attributs			*/
	BYTE *fond;			/* couleur de fond		*/
	BYTE *texte;			/* couleur de texte		*/
} image_st;
#endif /* MSDOS */

typedef struct ecran_struct {
	struct ecran_struct *suite;	/* ecran suivant		*/
#ifdef MSDOS
	WORD FAR *image;		/* image ecran			*/
#else
	image_st image; 		/* image ecran			*/
#endif /* MSDOS */
	BYTE ligne;			/* position ligne		*/
	BYTE colonne;			/* position colonne		*/
	BYTE jeu;			/* jeu de caractere		*/
	BYTE etat;			/* etat de l'automate           */
	BYTE attribut;			/* attribut courant		*/
#ifndef MSDOS
	BYTE fond;			/* couleur de fond		*/
	BYTE texte;			/* couleur de texte		*/
#endif /* MSDOS */
	BYTE defaut;			/* couleur par defaut		*/
} ecran_st;


/*
 *	structure de description d'imprimante
 *	-------------------------------------
 */

typedef struct {
	BYTE *nom;			/* nom du fichier imprimante	*/
	BOOL flag;			/* indicateur d'utilisation     */
	int handle;			/* handle du fichier imprimante */
	WORD ligne;			/* ligne courante		*/
	WORD colonne;			/* colonne courante		*/
	BYTE jeu;			/* jeu de caractere courant	*/
	BYTE etat;			/* etat courant automate	*/
	WORD nb_transparent;		/* nombre de transparent	*/
	BYTE *tbl_init; 		/* tables des inits		*/
	BYTE tbl_lg_init;		/* longueur d'une entree        */
	BYTE *tbl_attribut;		/* table des attributs		*/
	BYTE tbl_lg_attribut;		/* longueur d'une entree        */
	BYTE *tbl_table;		/* table de conversion		*/
	BYTE *tbl_tampon;		/* tampon de conversion 	*/
	WORD tbl_lg_tampon;		/* longueur du tampon		*/
#ifndef MSDOS
	BYTE *spool;			/* nom de l'utilitaire de spool */
#ifdef IMPLOC
	BOOL local;			/* indicateur si imprimante locale */
#endif /*IMPLOC*/
	int sleep;			/* mise en sommeil de sleep secondes */
#endif /* MSDOS */
} imprimante_st;


/*
 *	structure de description des touches programmables
 *	--------------------------------------------------
 */

typedef struct {
	BYTE code;			/* code fonction		*/
	CHAR lg;			/* longueur courante		*/
	CHAR max;			/* longueur maximum		*/
	BYTE *str;			/* valeur courante		*/
#ifndef MSDOS
	BOOL act;			/* TRUE si programmable 	*/
#endif /* MSDOS */
} pkey_st;


/* fin de fichier */
