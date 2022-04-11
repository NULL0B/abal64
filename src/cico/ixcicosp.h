/*
 *	CICO - Interface ECRAN / CLAVIER / IMPRIMANTE
 *	---------------------------------------------
 *
 *	Copyright (c) 1990 Amenesik / Sologic s.a.
 *
 *	ixcico.h - declarations interface ecran/clavier/imprimante
 *
 *	$Header: /home/Produits/Abal3/cico/ixcicosp.h,v 1.2 2005/01/28 10:01:19 jamie Exp $
 *
 *	08/03/93 : NOCASE -1 -> 0xFF
 *	----------------------- 1.4d / 2.1c -----------------------------
 * 	30/05/94 : Probleme dans table des touches de fonctions 2 * a1
 *      02/06/94 : Essai CIFIC
 */


/*
 *	fichiers standards
 *	------------------
 */

#undef	STDIN
#define STDIN	0

#undef	STDOUT
#define STDOUT	1

#undef	STDERR
#define STDERR	2


/*
 *	constantes diverses
 *	-------------------
 */

#ifdef vms
#define ECR_CHEMIN			"SYS$MANAGER:"
#else
#define ECR_CHEMIN			"/usr/lib/cico"
#endif /* vms */
#define ECR_SIGNATURE			"CICO14"
#define ECR_LONGUEUR_SIGNATURE		6
#define ECR_LONGUEUR_ENTETE		20

#ifdef vms
#define IMP_TBL_CHEMIN			"SYS$MANAGER:"
#else
#define IMP_TBL_CHEMIN			"/usr/lib/tbl"
#endif /* vms */
#define IMP_TBL_SIGNATURE		"MP1"
#define IMP_TBL_LONGUEUR_SIGNATURE	3
#define IMP_TBL_EXTENSION		".tbl"
#define IMP_SEPARATEUR			','

#ifdef vms
#define ENV_SEPARATEUR			'|'
#else
#define ENV_SEPARATEUR			':'
#endif /* vms */
#define ENV_ECRAN			"CICO"
#define ENV_IMPRIMANTE			"LO"
#define ENV_LANGUE			"ABALANG"
#define ENV_LANGUE2			"LANG"

#ifdef CIFIC
#define ENV_COFIC			"CICOFICS"
#define ENV_CIFIC			"CICOFICE"
FILE * cific_ptr;			/* fichier recevant les caracteres tapes */
FILE * cofic_ptr;			/* fichier simulant la frappe de caracteres */
static BOOL cific_ok = FALSE;		/* mode simulation */
static BOOL cofic_ok = FALSE;		/* mode enregistrement */
#endif

/*
 *	oublis de certains systemes
 *	---------------------------
 */

#ifndef O_SYNC
#define O_SYNC		0
#endif /* O_SYNC */

#ifndef SEEK_SET
#define SEEK_SET	0
#endif /* SEEK_SET */

#ifndef SEEK_CUR
#define SEEK_CUR	1
#endif /* SEEK_CUR */

#ifndef R_OK
#define R_OK		4
#endif /* R_OK */

#ifndef W_OK
#define W_OK		2
#endif /* W_OK */

#ifdef vms
#define F_SETFL 	0
#endif /* vms */


/*
 *	variables diverses
 *	------------------
 */

WORD bda_cico = 0xffff; 	/* numero de BDA contenant CICO 	*/

static int code_lang = 0;	/* code langue				*/

#ifdef TEMPO
static int tempo = TEMPO;	/* temporisation de la lecture clavier	*/
#else
static int tempo = -1;
#endif /* TEMPO */


static CHAR *tbl_defaut = NULL;
static CHAR *tbl_chemin = NULL;

/*DLR:02/02/93*/

static unsigned short int process_number;
static BOOL process_flag=FALSE; 
static BOOL process_seq=FALSE; 

/*
 *	tables de conversion minuscule/majuscule
 *	----------------------------------------
 */

static BYTE maj_to_min[] = {
	0x87, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 	/* 0x80 */
	0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x84, 0x86,
	0x82, 0x91, 0x91, 0x93, 0x94, 0x95, 0x96, 0x97, 	/* 0x90 */
	0x98, 0x94, 0x81, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
	0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa4, 0xa6, 0xa7, 	/* 0xa0 */
	0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
	0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0x85, 0xa0, 0x83, 	/* 0xb0 */
	0xce, 0x8a, 0x88, 0x89, 0x8d, 0xa1, 0x8c, 0xbf,
	0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0x8b, 0x95, 	/* 0xc0 */
	0xa2, 0x93, 0xcf, 0x97, 0xa3, 0x96, 0xce, 0xcf,
};

static BYTE min_to_maj[][2] = {
	0x80, 0x80, 0x9a, 'U',  0x90, 'E',  0xb7, 'A',          /* 0x80 */
	0x8e, 'A',  0xb5, 'A',  0x8f, 'A',  0x80, 'C',
	0xba, 'E',  0xbb, 'E',  0xb9, 'E',  0xc6, 'I',
	0xbe, 'I',  0xbc, 'I',  0x8e, 0x8e, 0x8f, 0x8f,
	0x90, 0x90, 0x92, 0x92, 0x92, 0x92, 0xc9, 'O',          /* 0x90 */
	0x99, 'O',  0xc7, 'O',  0xcd, 'U',  0xcb, 'U',
	'Y',  'Y',  0x99, 0x99, 0x9a, 0x9a, 0x9b, 0x9b,
	0x9c, 0x9c, 0x9d, 0x9d, 0x9e, 0x9e, 0x9f, 0x9f,
	0xb6, 'A',  0xbd, 'I',  0xc8, 'O',  0xcc, 'U',          /* 0xa0 */
	0xa5, 'N',  0xa5, 0xa5, 'A',  'A',  'O',  'O',
	0xa8, 0xa8, 0xa9, 0xa9, 0xaa, 0xaa, 0xab, 0xab,
	0xac, 0xac, 0xad, 0xad, 0xae, 0xae, 0xaf, 0xaf,
	0xb0, 0xb0, 0xb1, 0xb1, 0xb2, 0xb2, 0xb3, 0xb3, 	/* 0xb0 */
	0xb4, 0xb4, 0xb5, 0xb5, 0xb6, 0xb6, 0xb7, 0xb7,
	0xb8, 0xb8, 0xb9, 0xb9, 0xba, 0xba, 0xbb, 0xbb,
	0xbc, 0xbc, 0xbd, 0xbd, 0xbe, 0xbe, 0xbf, 0xbf,
	0xc0, 0xc0, 0xc1, 0xc1, 0xc2, 0xc2, 0xc3, 0xc3, 	/* 0xc0 */
	0xc4, 0xc4, 0xc5, 0xc5, 0xc6, 0xc6, 0xc7, 0xc7,
	0xc8, 0xc8, 0xc9, 0xc9, 0xca, 0xca, 0xcb, 0xcb,
	0xcc, 0xcc, 0xcd, 0xcd, 0xb8, 'A',  0xca, 'O',
};


/*
 *	messages
 *	--------
 */

static CHAR *message[] = {
	"cannot find terminal name",                    /*  0 */
	"incorrect tempo",                              /*  1 */
	"cannot open ",                                 /*  2 */
	"cannot stat ",                                 /*  3 */
	"cannot read ",                                 /*  4 */
	"incorrect file ",                              /*  5 */
	"cannot allocate memory",                       /*  6 */
	"cannot open default printer",                  /*  7 */
	"cannot seek ",                                 /*  8 */
	"incorrect installation ",                      /*  9 */
	"file access manager not active ",              /* 10 */
	"CICO - Version 1.2 PROVISOIRE (",              /* 11 */
	UPDATE, 					/* 12 */
	")\nCopyright (c) 1989 Amenesik / Sologic s.a.\n\n",      /* 13 */
};

#define E_FIND		0	/* fichier parametre non trouve 	*/
#define E_TEMPO 	1	/* temporisation incorrecte		*/
#define E_OPEN		2	/* erreur ouverture fichier parametre	*/
#define E_STAT		3	/* erreur stat fichier parametre	*/
#define E_READ		4	/* erreur lecture fichier parametre	*/
#define E_BADF		5	/* fichier parametre incorrect		*/
#define E_ALLOC 	6	/* erreur allocation memoire		*/
#define E_DEFAUT	7	/* erreur ouverture imprimante defaut	*/
#define E_SEEK		8	/* erreur lseek fichier parametre	*/
#define E_INSTALL	9	/* erreur installation			*/
#define E_ACCESS	10	/* access non actif			*/

#define B_VERSION	11	/* banniere version			*/
#define B_UPDATE	12	/* banniere date de mise a jour 	*/
#define B_COPYRIGHT	13	/* banniere copyright			*/


/*
 *	buffer de sortie a l'ecran
 *	--------------------------
 */

#define DIM_OUT_BUF	512		/* taille du buffer de sortie	*/

static BYTE out_buf[DIM_OUT_BUF];	/* buffer de sortie		*/
static WORD out_nb = 0;			/* nb de car. dans le buffer	*/


/*
 *	buffer de sortie imprimante
 *	---------------------------
 */

static BYTE out_buflo[DIM_OUT_BUF];	/* buffer de sortie		*/
static WORD out_nblo = 0;		/* nb de car. dans le buffer	*/


/*
 *	buffer tournant du clavier (ne contient que des caracteres Amenesik / Sologic)
 *	--------------------------------------------------------------------
 */

#define DIM_TURN_BUF	128		/* taille du buffer tournant	*/

static BYTE turn_buf[DIM_TURN_BUF];	/* buffer tournant du clavier	*/
static BYTE *turn_lec = turn_buf;	/* pointeur en lecture		*/
static BYTE *turn_ecr = turn_buf;	/* pointeur en ecriture 	*/
static BYTE *turn_fin = turn_buf + DIM_TURN_BUF;
					/* pointeur de fin		*/


/*
 *	buffer d'entree au clavier
 *	--------------------------
 */

#define DIM_IN_BUF	128		/* taille du buffer d'entree    */

static BYTE in_buf[DIM_IN_BUF]; 	/* buffer d'entree              */
static int in_nb = 0;			/* nb de car. dans le buffer	*/


/*
 *	tables de gestion du terminal
 *	-----------------------------
 */

static BYTE *tab_in;		/* table de conversion clavier	*/
static BYTE *tab_out;		/* table de conversion ecran	*/
static CHAR *tab_str;		/* table des chaines		*/


/*
 *	variables de configuration de la liaison
 *	----------------------------------------
 */

#ifndef vms

static struct termio confterm;	/* sauvegarde des parametres	*/
static struct termio proterm;	/* parametres de configuration	*/

#endif /* vms */


/*
 *	etats de l'automate de conversion en sortie sur un peripherique
 *	---------------------------------------------------------------
 */

#define ETAT_STANDARD		0	/* etat standard		*/
#define ETAT_ESCAPE		1	/* esc				*/
#define ETAT_POS_1		2	/* esc f			*/
#define ETAT_POS_2		3	/* esc f x			*/
#define ETAT_TRANS_1		4	/* esc T			*/
#define ETAT_TRANS_2		5	/* esc T low_BYTE		*/
#define ETAT_TRANS_3		6	/* esc T low_BYTE high_BYTE	*/
#define ETAT_DEFAUT		7	/* esc n			*/
#define ETAT_TEXTE		8	/* esc r			*/
#define ETAT_FOND		9	/* esc s			*/
#define ETAT_ESCAPE_ESCAPE	10	/* esc esc			*/


/*
 *	definition des couleurs
 *	-----------------------
 */

#define FC_BLACK		0x00
#define FC_RED			0x01
#define FC_GREEN		0x02
#define FC_BROWN		0x03
#define FC_BLUE 		0x04
#define FC_MAGENTA		0x05
#define FC_CYAN 		0x06
#define FC_WHITE		0x07
#define FC_GREY 		0x08
#define FC_LIGHT_RED		0x09
#define FC_LIGHT_GREEN		0x0a
#define FC_YELLOW		0x0b
#define FC_LIGHT_BLUE		0x0c
#define FC_LIGHT_MAGENTA	0x0d
#define FC_LIGHT_CYAN		0x0e
#define FC_LIGHT_WHITE		0x0f

#define BC_BLACK		0x00
#define BC_RED			0x10
#define BC_GREEN		0x20
#define BC_BROWN		0x30
#define BC_BLUE 		0x40
#define BC_MAGENTA		0x50
#define BC_CYAN 		0x60
#define BC_GREY 		0x70
#define BC_BLINK		0x80


/*
 *	conversion en cours sur un peripherique
 *	---------------------------------------
 */

#define NO_CASE 	0xFF		/* pas de transcodage	*/
#define UPPER_CASE	0		/* en majuscule 	*/
#define LOWER_CASE	1		/* en minuscule 	*/


/*
 *	accent en cours de traitement en entree au clavier
 *	--------------------------------------------------
 */

#define NO_ACCENT	-1		/* pas d'accent en attente      */

static int accent = NO_ACCENT;		/* accent en cours		*/


/*
 *	position et dimensions des imprimantes
 *	--------------------------------------
 */

#define NB_IMPRIMANTE	64		/* nombre d'imprimantes         */

static imprimante_st *imprimante[NB_IMPRIMANTE] = {
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
};

#define courante	imprimante[prnfid]


/*
 *	image memoire de l'ecran
 *	------------------------
 */
/* 17/03/92 */
BOOL flag_finterm = FALSE;	/* FALSE si pas de finterm partiel	*/

BOOL flag_bios = FALSE; 	/* TRUE si utilisation du BIOS		*/
BOOL flag_couleur= FALSE;	/* TRUE si presence de la couleur	*/
BOOL flag_init = FALSE; 	/* TRUE si initialisation deja realisee */
BOOL flag_curseur = TRUE;	/* TRUE si curseur allume sur ecran	*/
BOOL flag_buf = FALSE;		/* TRUE si bufferisation sortie ecran	*/
static BOOL flag_buflo = FALSE;	/* TRUE si bufferisation sortie imprimante */
BOOL flag_scroll = TRUE;	/* TRUE si mode scroll			*/

BYTE max_ligne; 		/* numero de ligne maximum	*/
BYTE max_colonne;		/* numero de colonne maximum	*/
BYTE nb_ligne;			/* nombre de lignes		*/
BYTE nb_colonne;		/* nombre de colonnes		*/

ecran_st *courant = NULL;

BOOL flag_second = FALSE;	/* TRUE si jeu secondaire actif 	*/
BOOL flag_cursor = TRUE;	/* TRUE si curseur allume sur ecran	*/
BOOL flag_delay = TRUE; 	/* TRUE si lecture clavier bloquante	*/


/*
 *	variables de gestion des redirections
 *	-------------------------------------
 */

BOOL redir_CO = FALSE;
BOOL redir_CI = FALSE;
BOOL redir_LO = FALSE;

#ifdef CICO_BDA
BDA_INIT redir;
#endif /* fin CICO_BDA */


/*
 *	definition des capacites du terminal
 *	------------------------------------
 */


#define SET_FIRST	0
#define SET_NB		2

#define SET_TERM	term_str[SET_FIRST]	/* initialisation	*/
#define RESET_TERM	term_str[SET_FIRST + 1] /* retour etat initial	*/

/* attributs ecran */

#define ATB_FIRST	SET_FIRST + SET_NB
#define ATB_NB		7

#define EXIT_ATTRIBUTE	term_str[ATB_FIRST]	/* fin tous attributs	*/
#define ENTER_STANDOUT	term_str[ATB_FIRST + 1] /* preferentiel 	*/
#define ENTER_REVERSE	term_str[ATB_FIRST + 2] /* inversion video	*/
#define ENTER_BLINK	term_str[ATB_FIRST + 3] /* clignotant		*/
#define ENTER_UNDERLINE term_str[ATB_FIRST + 4] /* souligne		*/
#define ENTER_DIM	term_str[ATB_FIRST + 5] /* sous-brillance	*/
#define ENTER_BOLD	term_str[ATB_FIRST + 6] /* sur-brillance	*/

/* couleurs caractere */

#define FORE_FIRST	ATB_FIRST + ATB_NB
#define FORE_NB 	16

#define FOREGR_0	term_str[FORE_FIRST]		/* noir 	*/
#define FOREGR_1	term_str[FORE_FIRST + 1]	/* rouge	*/
#define FOREGR_2	term_str[FORE_FIRST + 2]	/* vert 	*/
#define FOREGR_3	term_str[FORE_FIRST + 3]	/* marron	*/
#define FOREGR_4	term_str[FORE_FIRST + 4]	/* bleu 	*/
#define FOREGR_5	term_str[FORE_FIRST + 5]	/* magenta	*/
#define FOREGR_6	term_str[FORE_FIRST + 6]	/* cyan 	*/
#define FOREGR_7	term_str[FORE_FIRST + 7]	/* gris clair	*/
#define FOREGR_8	term_str[FORE_FIRST + 8]	/* gris fonce	*/
#define FOREGR_9	term_str[FORE_FIRST + 9]	/* rouge clair	*/
#define FOREGR_A	term_str[FORE_FIRST + 10]	/* vert clair	*/
#define FOREGR_B	term_str[FORE_FIRST + 11]	/* jaune	*/
#define FOREGR_C	term_str[FORE_FIRST + 12]	/* bleu clair	*/
#define FOREGR_D	term_str[FORE_FIRST + 13]	/* magenta clair*/
#define FOREGR_E	term_str[FORE_FIRST + 14]	/* cyan clair	*/
#define FOREGR_F	term_str[FORE_FIRST + 15]	/* blanc	*/

/* couleurs fond de caractere */

#define BACK_FIRST	FORE_FIRST + FORE_NB
#define BACK_NB 	8

#define BACKGR_0	term_str[BACK_FIRST]		/* noir 	*/
#define BACKGR_1	term_str[BACK_FIRST + 1]	/* rouge	*/
#define BACKGR_2	term_str[BACK_FIRST + 2]	/* vert 	*/
#define BACKGR_3	term_str[BACK_FIRST + 3]	/* marron	*/
#define BACKGR_4	term_str[BACK_FIRST + 4]	/* bleu 	*/
#define BACKGR_5	term_str[BACK_FIRST + 5]	/* magenta	*/
#define BACKGR_6	term_str[BACK_FIRST + 6]	/* cyan 	*/
#define BACKGR_7	term_str[BACK_FIRST + 7]	/* gris clair	*/

/* fonctions ecran */

#define SCR_FIRST	BACK_FIRST + BACK_NB
#define SCR_NB		18

#define CURSOR_ADR_BEG	term_str[SCR_FIRST]		/* pos. debut	*/
#define CURSOR_ADR_P1	term_str[SCR_FIRST + 1] 	/* pos. p1	*/
#define CURSOR_ADR_MID	term_str[SCR_FIRST + 2] 	/* pos. milieu	*/
#define CURSOR_ADR_P2	term_str[SCR_FIRST + 3] 	/* pos. p2	*/
#define CURSOR_ADR_END	term_str[SCR_FIRST + 4] 	/* pos. fin	*/
#define CURSOR_RIGHT	term_str[SCR_FIRST + 5] 	/* curs. droite */
#define CURSOR_LEFT	term_str[SCR_FIRST + 6] 	/* curs. gauche */
#define CURSOR_UP	term_str[SCR_FIRST + 7] 	/* curseur haut */
#define CURSOR_DOWN	term_str[SCR_FIRST + 8] 	/* curseur bas	*/
#define CLEAR_SCREEN	term_str[SCR_FIRST + 9] 	/* effac. ecran */

#define CLEAR_EOL	term_str[SCR_FIRST + 10]	/* eff. fin lig.*/
#define CLEAR_EOS	term_str[SCR_FIRST + 11]	/* eff. fin ecr.*/
#define INSERT_LINE	term_str[SCR_FIRST + 12]	/* insert. ligne*/
#define DELETE_LINE	term_str[SCR_FIRST + 13]	/* suppr. ligne */

#define INSERT_CHAR	term_str[SCR_FIRST + 14]	/* insert. car. */
#define DELETE_CHAR	term_str[SCR_FIRST + 15]	/* suppr. car.	*/

#define CURSOR_INVIS	term_str[SCR_FIRST + 16]	/* curseur off	*/
#define CURSOR_NORMAL	term_str[SCR_FIRST + 17]	/* curseur on	*/

/* jeu de caracteres secondaire */

#define SEC_FIRST	SCR_FIRST + SCR_NB
#define SEC_NB		3

#define ENTER_SECOND	term_str[SEC_FIRST]	/* entree dans jeu sec. */
#define EXIT_SECOND	term_str[SEC_FIRST + 1] /* retour au jeu prim.	*/
#define CHAR_SECOND	term_str[SEC_FIRST + 2] /* car. demand. jeu sec.*/

/* touches accent */

#define ACC_FIRST	SEC_FIRST + SEC_NB	/* 1er accent scrute	*/
#define ACC_NB		7			/* nombre d'accents     */

/* touches non programmables */

#define NKEY_FIRST	ACC_FIRST + ACC_NB	/* 1ere touche non prog.*/
#define NKEY_NB 	40			/* nb touches non prog. */

/* touches programmables */

#define PKEY_FIRST	NKEY_FIRST + NKEY_NB	/* 1ere touche program. */
#define PKEY_NB 	8			/* nb touches program.	*/

#define PKEY_F_FIRST	PKEY_FIRST + PKEY_NB	/* 1ere touche fonction */
#define PKEY_F_NB	50			/* nb de touches fonct. */

/* chaines de retour des touches non programmables */

#define NKEY_STR_FIRST	PKEY_F_FIRST + PKEY_F_NB
#define NKEY_STR_NB	40

/* chaines d'affichage des caracteres composes */

#define COMP_FIRST	NKEY_STR_FIRST + NKEY_STR_NB
#define COMP_NB 	256

#ifdef IMPLOC
/* sequences d'ouverture et fermeture d'imprimante locale		*/

#define LOCAL_FIRST	COMP_FIRST + COMP_NB	
#define LOCAL_NB	2

#define ENTER_LOCAL	(term_str[LOCAL_FIRST])	/* ouverture		*/
#define EXIT_LOCAL	(term_str[LOCAL_FIRST+1]) /* fermeture		*/
#endif /*IMPLOC*/

/* touches scrutees */

#define SCAN_FIRST	ACC_FIRST			/* 1ere touche scrut.*/
							/* nb touches scrut.*/
#define SCAN_NB 	ACC_NB + NKEY_NB + PKEY_NB + PKEY_F_NB

#ifdef IMPLOC
#define NB_CAPA		SET_NB + ATB_NB + FORE_NB + BACK_NB + SCR_NB + SEC_NB + NKEY_STR_NB + SCAN_NB + COMP_NB+LOCAL_NB
static BYTE *term_str[ NB_CAPA ]; /* les capacite */
#else
static BYTE *term_str[SET_NB + ATB_NB + FORE_NB + BACK_NB + SCR_NB + SEC_NB +
		      NKEY_STR_NB + SCAN_NB + COMP_NB]; /* les capacite */
#endif /*IMPLOC*/

/*
 *	touches accent
 *	--------------
 */

struct acc_st {
	BYTE *istr;		/* caractere d'entree   */
	BYTE *ostr;		/* caractere de sortie	*/
};

static struct acc_st acc[] = {
							/* trema	*/
	(BYTE *)"aeiouAEIOU\321 ",
	(BYTE *)"\204\211\213\224\201\216\273\306\231\232\321\321",
							/* circonflexe	*/
	(BYTE *)"aeiouAEIOU^ ",
	(BYTE *)"\203\210\214\223\226\267\272\276\311\315^^",
							/* tilde	*/
	(BYTE *)"nNao~ ",
	(BYTE *)"\244\245\316\317~~",
							/* grave	*/
	(BYTE *)"aeiouAEIOU` ",
	(BYTE *)"\205\212\215\225\227\265\271\274\307\313``",
							/* aigu 	*/
	(BYTE *)"aeiouAEIOU\324 ",
	(BYTE *)"\240\202\241\242\243\266\220\275\310\314\324\324",
							/* rond 	*/
	(BYTE *)"aA\370 ",
	(BYTE *)"\206\217\370\370",
							/* cedille	*/
	(BYTE *)"cC",
	(BYTE *)"\207\200",
};


/*
 *	touches programmables
 *	---------------------
 */

static pkey_st pkey[] = {
	0x01, 1, 1, (BYTE *)"\006", TRUE,       /* curseur droit        */
	0x02, 1, 1, (BYTE *)"\010", TRUE,       /* curseur gauche       */
	0x03, 1, 1, (BYTE *)"\013", TRUE,       /* curseur haut         */
	0x04, 1, 1, (BYTE *)"\005", TRUE,       /* curseur bas          */
	0x05, 1, 1, (BYTE *)"\034", TRUE,       /* home                 */
	0x06, 1, 1, (BYTE *)"\014", TRUE,       /* clear                */
	0x07, 1, 1, (BYTE *)"\001", FALSE,      /* annulation           */
	0x08, 1, 1, (BYTE *)"\000", FALSE,      /* break                */
						/* f1			*/
	0x80, 1, 32, (BYTE *)"\200...............................", FALSE,
					 /* f2			 */
	0x81, 1, 32, (BYTE *)"\201...............................", FALSE,
					 /* f3			 */
	0x82, 1, 32, (BYTE *)"\202...............................", FALSE,
					 /* f4			 */
	0x83, 1, 32, (BYTE *)"\203...............................", FALSE,
					 /* f5			 */
	0x84, 1, 32, (BYTE *)"\204...............................", FALSE,
					 /* f6			 */
	0x85, 1, 32, (BYTE *)"\205...............................", FALSE,
					 /* f7			 */
	0x86, 1, 32, (BYTE *)"\206...............................", FALSE,
					 /* f8			 */
	0x87, 1, 32, (BYTE *)"\207...............................", FALSE,
					 /* f9			 */
	0x88, 1, 32, (BYTE *)"\210...............................", FALSE,
					 /* f10 		 */
	0x89, 1, 32, (BYTE *)"\211...............................", FALSE,
					 /* f11 		 */
	0x8a, 1, 32, (BYTE *)"\212...............................", FALSE,
					 /* f12 		 */
	0x8b, 1, 32, (BYTE *)"\213...............................", FALSE,
					 /* f13 		 */
	0x8c, 1, 32, (BYTE *)"\214...............................", FALSE,
					 /* f14 		 */
	0x8d, 1, 32, (BYTE *)"\215...............................", FALSE,
					 /* f15 		 */
	0x8e, 1, 32, (BYTE *)"\216...............................", FALSE,
					 /* f16 		 */
	0x8f, 1, 32, (BYTE *)"\217...............................", FALSE,
					 /* f17 		 */
	0x90, 1, 32, (BYTE *)"\220...............................", FALSE,
					 /* f18 		 */
	0x91, 1, 32, (BYTE *)"\221...............................", FALSE,
					 /* f19 		 */
	0x92, 1, 32, (BYTE *)"\222...............................", FALSE,
					 /* f20 		 */
	0x93, 1, 32, (BYTE *)"\223...............................", FALSE,
					 /* f21 		 */
	0x94, 1, 32, (BYTE *)"\224...............................", FALSE,
					 /* f22 		 */
	0x95, 1, 32, (BYTE *)"\225...............................", FALSE,
					 /* f23 		 */
	0x96, 1, 32, (BYTE *)"\226...............................", FALSE,
					 /* f24 		 */
	0x97, 1, 32, (BYTE *)"\227...............................", FALSE,
					 /* f25 		 */
	0x98, 1, 32, (BYTE *)"\230...............................", FALSE,
					 /* f26 		 */
	0x99, 1, 32, (BYTE *)"\231...............................", FALSE,
					 /* f27 		 */
	0x9a, 1, 32, (BYTE *)"\232...............................", FALSE,
					 /* f28 		 */
	0x9b, 1, 32, (BYTE *)"\233...............................", FALSE,
					 /* f29 		 */
	0x9c, 1, 32, (BYTE *)"\234...............................", FALSE,
					 /* f30 		 */
	0x9d, 1, 32, (BYTE *)"\235...............................", FALSE,
					 /* f31 		 */
	0x9e, 1, 32, (BYTE *)"\236...............................", FALSE,
					 /* f32 		 */
	0x9f, 1, 32, (BYTE *)"\237...............................", FALSE,
					 /* f33 		 */
	0xa0, 1, 32, (BYTE *)"\240...............................", FALSE,
					 /* f34 		 */
	0xa1, 1, 32, (BYTE *)"\241...............................", FALSE,
					 /* f35 		 */
	0xa2, 1, 32, (BYTE *)"\242...............................", FALSE,
					 /* f36 		 */
	0xa3, 1, 32, (BYTE *)"\243...............................", FALSE,
					 /* f37 		 */
	0xa4, 1, 32, (BYTE *)"\244...............................", FALSE,
					 /* f38 		 */
	0xa5, 1, 32, (BYTE *)"\245...............................", FALSE,
					 /* f39 		 */
	0xa6, 1, 32, (BYTE *)"\246...............................", FALSE,
					 /* f40 		 */
	0xa7, 1, 32, (BYTE *)"\247...............................", FALSE,
					 /* f41 (page up)	 */
	0xa8, 1, 32, (BYTE *)"\022...............................", FALSE,
					 /* f42 (end)		 */
	0xa9, 1, 32, (BYTE *)"\002...............................", FALSE,
					 /* f43 (page down)	 */
	0xaa, 1, 32, (BYTE *)"\003...............................", FALSE,
					 /* f44 (insert)	 */
	0xab, 1, 32, (BYTE *)"\017...............................", FALSE,
					 /* f45 (delete)	 */
	0xac, 1, 32, (BYTE *)"\177...............................", FALSE,
					 /* f46 (ctrl page up)	 */
	0xad, 1, 32, (BYTE *)"\250...............................", FALSE,
					 /* f47 (ctrl end)	 */
	0xae, 1, 32, (BYTE *)"\251...............................", FALSE,
					 /* f48 (ctrl page down) */
	0xaf, 1, 32, (BYTE *)"\252...............................", FALSE,
					 /* f49 (ctrl left)	 */
	0xb0, 1, 32, (BYTE *)"\253...............................", FALSE,
					 /* f50 (ctrl right)	 */
	0xb1, 1, 32, (BYTE *)"\254...............................", FALSE,
};

#define PRL_RIGHT	*pkey[0].str
#define PRL_LEFT	*pkey[1].str
#define PRL_UP		*pkey[2].str
#define PRL_DOWN	*pkey[3].str
#define PRL_HOME	*pkey[4].str
#define PRL_CLEAR	*pkey[5].str

/*
 *	Drapeau de gestion de l'envoi des sequences INIT_TERM et FIN_TERM
 *	par les fonctions initerm et finterm
 *
 */

WORD seqinit=TRUE;

/*
 *	definition des macros
 *	---------------------
 */

#ifdef vms

#define delay_on()	{\
				if (flag_delay == FALSE) {\
					vms$fcntl(STDIN, F_SETFL, O_RDONLY);\
					flag_delay = TRUE;\
				}\
			}

#define delay_off()	{\
				if (flag_delay == TRUE) {\
					vms$fcntl(STDIN, F_SETFL, O_RDONLY + O_NDELAY);\
					flag_delay = FALSE;\
				}\
			}

#else

#define delay_on()	{\
				if (flag_delay == FALSE) {\
					/*printf("\r\nD_ON");*/\
					fcntl(STDIN, F_SETFL, O_RDONLY);\
					flag_delay = TRUE;\
				}\
			}

#define delay_off()	{\
				if (flag_delay == TRUE) {\
					/*printf("\r\nD_OFF");*/\
					fcntl(STDIN, F_SETFL, O_RDONLY + O_NDELAY);\
					flag_delay = FALSE;\
				}\
			}

#endif /* vms */


/* entree dans le jeu de caracteres secondaire */

#define enter_second()	{\
				if (flag_second == FALSE) {\
					_co_capacite(ENTER_SECOND);\
					flag_second = TRUE;\
				}\
			}

/* retour au jeu de caracteres primaire */

#define exit_second()	{\
				if (flag_second == TRUE) {\
					_co_capacite(EXIT_SECOND);\
					flag_second = FALSE;\
				}\
			}


/*
 *	references aux variables de l'executeur
 *	---------------------------------------
 */

#include "abalcico.h"

/*
 *	prototypage des fonctions externes
 *	----------------------------------
 */

extern VOID exit();
extern LONG lseek();
extern CHAR *getenv();
extern VOID liberate();
extern struct utmp *getutent();
extern VOID endutent();
extern CHAR *ttyname();


/*
 *	prototypage des fonctions internes
 *	----------------------------------
 */

static VOID _ci_lecture();

VOID _co();
VOID _co_car();
VOID _co_conv();
VOID _co_pos();
VOID _co_out();
VOID _co_attribut();
VOID _co_set_attribut();
VOID _co_reset_attribut();
VOID _co_couleur_fond();
VOID _co_couleur_texte();
VOID _co_ins_line();
VOID _co_del_line();
VOID _co_ins_character();
VOID _co_del_character();
VOID _co_clear();
VOID _co_clear_eos();
VOID _co_clear_eol();
VOID _co_cursor();
VOID _co_capacite();
VOID _co_sequence();
VOID _co_scroll();
VOID _co_push();
VOID _co_pop();
WORD _co_ligne();
WORD _co_colonne();
VOID _co_start();
VOID _co_flush();

VOID _lo_start();
VOID _lo_flush();

VOID _lo();
VOID modterm();
static VOID _lo_conv();
static VOID _lo_out();
static WORD _lo_open();
static VOID _lo_close();
static WORD _lo_defaut();
static WORD _lo_tbl_charge();
static VOID _lo_tbl_init();
static VOID _lo_tbl_attribut();

static VOID erreur();
static WORD x_npos14();
/* fin de fichier */
