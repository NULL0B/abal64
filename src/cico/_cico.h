/*
 *	CICO - Interface ECRAN / CLAVIER / IMPRIMANTE
 *	---------------------------------------------
 *
 *	Copyright (c) 1989 Amenesik / Sologic s.a.
 *
 *	cico.h - definitions communes
 *
 *	$Header: /home/Produits/Abal3/cico/_cico.h,v 1.6 2005/05/09 14:54:38 jamie Exp $
 *
 * ----------------------------------------------------------------
 * 14/04/94 : modification couleur par defaut (def_char,def_back)
 *		define ABALCONF 
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
#define ETAT_TEXTE_ETD		14	/* esc R			*/
#define ETAT_FOND_ETD		15	/* esc S			*/

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



#include "_ecran.h"

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
	BOOL local;			/* indicateur si imprimante locale 			*/
#endif /*IMPLOC*/
	int sleep;			/* mise en sommeil de sleep secondes 			*/
#endif /* MSDOS */
	int	feedcount;		/* nombre de lignes depuis flush 			*/
	int 	feeding;		/* nombre de lignes avant spool flush : ABAL 3 USEIT 	*/
	int	linefeed;		/* inhibits 0A when true				*/
	int	carriage;		/* inhibits 0C when true				*/
	int	formfeed;		/* inhibits 0D when true				*/
	int	xcico;			/* transparence to printer output : keeps all sequences */
	BYTE * 	syntaxe;		/* syntaxe originale nom pour lo_open			*/
	int	mode;			/* mode initialde pour lo_open				*/
} imprimante_st;


/*
 *	structure de description des touches programmables
 *	--------------------------------------------------
 */
#ifdef UNIX
#define LGMAX_KEY 80
#endif
typedef struct {
	BYTE code;			/* code fonction		*/
	CHAR lg;			/* longueur courante		*/
	CHAR max;			/* longueur maximum		*/
#ifdef UNIX
	BYTE str[LGMAX_KEY];
#else 
	BYTE *str;			/* valeur courante		*/
#endif
#ifndef MSDOS
	BOOL act;			/* TRUE si programmable 	*/
#endif /* MSDOS */
} pkey_st;


/* fin de fichier */
