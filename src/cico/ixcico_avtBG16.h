/*
 *	CICO - Interface ECRAN / CLAVIER / IMPRIMANTE
 *	---------------------------------------------
 *
 *	Copyright (c) 1990 Amenesik / Sologic s.a.
 *
 *	ixcico.h - declarations interface ecran/clavier/imprimante
 *
 *	$Header: /home/Produits/Abal3/cico/ixcico.h,v 1.4 2005/01/13 16:00:18 jamie Exp $
 *
 *	08/03/93 : NOCASE -1 -> 0xFF
 *	----------------------- 1.4d / 2.1c -----------------------------
 * 	30/05/94 : Probleme dans table des touches de fonctions 2 * a1
 *      02!09!97 : S Barthe : ajout ifdef SHAREDLO pour partageabilit imprimante
 *      07/12/2000 S Barthe : ajout ABALNORESET pour pas ioctl sur STDIN (rsh)
 *	06/11/2001 IJM : extension of the CICO mechanisms for page/scroll
 *			mode switching, read/write kbf and hide/show status bar
 *			all this controlled by the variable _USEIT_FOR_WHATEVER
 */

#include "ixconst.h"

/*
 *	variables diverses
 *	------------------
 */

WORD bda_cico = 0xffff; 	/* numero de BDA contenant CICO 	*/



#ifdef SHAREDLO
static int resetterm = 1;	/* reset terminal			*/
#endif

#ifdef TEMPO
static int tempo = TEMPO;	/* temporisation de la lecture clavier	*/
#else
static int tempo = -1;
#endif /* TEMPO */


/*DLR:02/02/93*/
static unsigned short int process_number;
static BOOL process_flag=FALSE; 
static BOOL process_seq=FALSE; 


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

static BYTE *paranom=(BYTE*) 0;

static 	BYTE *tab_in;		/* table de conversion clavier	*/
static	BYTE *tab_out;		/* table de conversion ecran	*/
static 	CHAR *tab_str;		/* table des chaines		*/


/*
 *	variables de configuration de la liaison
 *	----------------------------------------
 */

#ifndef vms

static struct termio confterm;	/* sauvegarde des parametres	*/
static struct termio proterm;	/* parametres de configuration	*/

#endif /* vms */


static int accent = NO_ACCENT;		/* accent en cours		*/


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
BOOL flag_scroll = TRUE;	/* TRUE si mode scroll			*/

WORD max_ligne; 		/* numero de ligne maximum	*/
WORD max_colonne;		/* numero de colonne maximum	*/
#ifdef SPARC
BYTE nombre_ligne;		/* nombre de lignes nb_ligne peut etre ecrase 	*/
#else
BYTE nb_ligne;			/* nombre de lignes		*/
#endif
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

#else
#ifdef	_USEIT_FOR_WHATEVER
#define LOCAL_FIRST	COMP_FIRST + COMP_NB	
#define LOCAL_NB	0
#endif
#endif /*IMPLOC*/

#ifdef	_USEIT_FOR_WHATEVER
#define	USEIT_FIRST	LOCAL_FIRST + LOCAL_NB
#ifdef	_CICO_MIMO
#define	USEIT_NB	9
#else
#define	USEIT_NB	6
#endif


#define	ENTER_PAGE	(term_str[USEIT_FIRST])	 /* enter page mode	*/
#define	EXIT_PAGE	(term_str[USEIT_FIRST+1])/* leave page mode	*/
#define	SHOW_STATUS	(term_str[USEIT_FIRST+2])/* show status bar	*/
#define	HIDE_STATUS	(term_str[USEIT_FIRST+3])/* hide status bar	*/
#define	READ_KBF   	(term_str[USEIT_FIRST+4])/* read function key	*/
#define	WRITE_KBF  	(term_str[USEIT_FIRST+5])/* write function key	*/
#ifdef	_CICO_MIMO
#define	MOUSE_EVENT  	(term_str[USEIT_FIRST+6])/* mouse event prefix	*/
#define	MOUSE_ON       	(term_str[USEIT_FIRST+7])/* mouse on sequence 	*/
#define	MOUSE_OFF      	(term_str[USEIT_FIRST+8])/* mouse off sequence 	*/
#endif
#endif

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

	0x01, 1, 1, "\006", TRUE,       /* curseur droit        */
	0x02, 1, 1, "\010", TRUE,       /* curseur gauche       */
	0x03, 1, 1, "\013", TRUE,       /* curseur haut         */
	0x04, 1, 1, "\005", TRUE,       /* curseur bas          */
	0x05, 1, 1, "\034", TRUE,       /* home                 */
	0x06, 1, 1, "\014", TRUE,       /* clear                */
	0x07, 1, 1, "\001", FALSE,      /* annulation           */
	0x08, 1, 1, "\000", FALSE,      /* break                */
					/* f1			*/
	0x80, 1, 32, "\200...............................", FALSE,
					 /* f2			 */
	0x81, 1, 32, "\201...............................", FALSE,
					 /* f3			 */
	0x82, 1, 32, "\202...............................", FALSE,
					 /* f4			 */
	0x83, 1, 32, "\203...............................", FALSE,
					 /* f5			 */
	0x84, 1, 32, "\204...............................", FALSE,
					 /* f6			 */
	0x85, 1, 32, "\205...............................", FALSE,
					 /* f7			 */
	0x86, 1, 32, "\206...............................", FALSE,
					 /* f8			 */
	0x87, 1, 32, "\207...............................", FALSE,
					 /* f9			 */
	0x88, 1, 32, "\210...............................", FALSE,
					 /* f10 		 */
	0x89, 1, 32, "\211...............................", FALSE,
					 /* f11 		 */
	0x8a, 1, 32, "\212...............................", FALSE,
					 /* f12 		 */
	0x8b, 1, 32, "\213...............................", FALSE,
					 /* f13 		 */
	0x8c, 1, 32, "\214...............................", FALSE,
					 /* f14 		 */
	0x8d, 1, 32, "\215...............................", FALSE,
					 /* f15 		 */
	0x8e, 1, 32, "\216...............................", FALSE,
					 /* f16 		 */
	0x8f, 1, 32, "\217...............................", FALSE,
					 /* f17 		 */
	0x90, 1, 32, "\220...............................", FALSE,
					 /* f18 		 */
	0x91, 1, 32, "\221...............................", FALSE,
					 /* f19 		 */
	0x92, 1, 32, "\222...............................", FALSE,
					 /* f20 		 */
	0x93, 1, 32, "\223...............................", FALSE,
					 /* f21 		 */
	0x94, 1, 32, "\224...............................", FALSE,
					 /* f22 		 */
	0x95, 1, 32, "\225...............................", FALSE,
					 /* f23 		 */
	0x96, 1, 32, "\226...............................", FALSE,
					 /* f24 		 */
	0x97, 1, 32, "\227...............................", FALSE,
					 /* f25 		 */
	0x98, 1, 32, "\230...............................", FALSE,
					 /* f26 		 */
	0x99, 1, 32, "\231...............................", FALSE,
					 /* f27 		 */
	0x9a, 1, 32, "\232...............................", FALSE,
					 /* f28 		 */
	0x9b, 1, 32, "\233...............................", FALSE,
					 /* f29 		 */
	0x9c, 1, 32, "\234...............................", FALSE,
					 /* f30 		 */
	0x9d, 1, 32, "\235...............................", FALSE,
					 /* f31 		 */
	0x9e, 1, 32, "\236...............................", FALSE,
					 /* f32 		 */
	0x9f, 1, 32, "\237...............................", FALSE,
					 /* f33 		 */
	0xa0, 1, 32, "\240...............................", FALSE,
					 /* f34 		 */
	0xa1, 1, 32, "\241...............................", FALSE,
					 /* f35 		 */
	0xa2, 1, 32, "\242...............................", FALSE,
					 /* f36 		 */
	0xa3, 1, 32, "\243...............................", FALSE,
					 /* f37 		 */
	0xa4, 1, 32, "\244...............................", FALSE,
					 /* f38 		 */
	0xa5, 1, 32, "\245...............................", FALSE,
					 /* f39 		 */
	0xa6, 1, 32, "\246...............................", FALSE,
					 /* f40 		 */
	0xa7, 1, 32, "\247...............................", FALSE,
					 /* f41 (page up)	 */
	0xa8, 1, 32, "\022...............................", FALSE,
					 /* f42 (end)		 */
	0xa9, 1, 32, "\002...............................", FALSE,
					 /* f43 (page down)	 */
	0xaa, 1, 32, "\003...............................", FALSE,
					 /* f44 (insert)	 */
	0xab, 1, 32, "\017...............................", FALSE,
					 /* f45 (delete)	 */
	0xac, 1, 32, "\177...............................", FALSE,
					 /* f46 (ctrl page up)	 */
	0xad, 1, 32, "\250...............................", FALSE,
					 /* f47 (ctrl end)	 */
	0xae, 1, 32, "\251...............................", FALSE,
					 /* f48 (ctrl page down) */
	0xaf, 1, 32, "\252...............................", FALSE,
					 /* f49 (ctrl left)	 */
	0xb0, 1, 32, "\253...............................", FALSE,
					 /* f50 (ctrl right)	 */
	0xb1, 1, 32, "\254...............................", FALSE,
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
#include "exacico.h"


/*
 *	prototypage des fonctions externes
 *	----------------------------------
 */

#ifndef	_LARGEFILE64_SOURCE
extern LONG lseek();
#endif

extern VOID exit();
extern VOID endutent();
extern struct utmp *getutent();
extern CHAR *getenv();
extern CHAR *ttyname();


/*
 *	prototypage des fonctions internes
 *	----------------------------------
 */

static VOID _ci_lecture();

VOID _co();
VOID _co_car();
WORD _co_conv();
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

WORD _lo(WORD);
VOID modterm();

static VOID erreur();
static WORD x_npos14();

int GetUseitVersion(void);

/* fin de fichier */

