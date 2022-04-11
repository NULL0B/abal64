
/*---------------------------------------------------------- EDVIDEO.H -----
 *
 *	Editeur de textes ABAL	  -	Copyright Amenesik / Sologic s.a. (c) 1989,97
 *
 *		   Definitions de la gestion du mode "page"
 *
 *		      Revision 1.0 du 13/10/1997
 *
 *--------------------------------------------------------------------------*/
#define YT131097

#define hextocar(c) ((c) < 10) ? '0'+(c) : 'A'+(c)-10

#define ctrlbyte(c) ((BYTE) c < 0x020)

#define putch(c) x_putch((SWORD) c)

#ifdef	ver2K
#define	_MESSAGE_COL1	51
#define	_MESSAGE_COL2	65
#else
#define	_MESSAGE_COL1	51
#define	_MESSAGE_COL2	66
#endif

#define getch() (BYTE) x_getch()

extern TFILE *fs;	/* description fichier source */
extern TFILE *fret;	/* description fichier retour */
extern TFILE *fdest;	/* description fichier destination */

#define getdest(p) getfic(fdest,p)
#define getret(p) getfic(fret,p)
#define putdest(p) putfic(fdest,p)
#define putret(p) putfic(fret,p)

#define NextTab(c,d) {	if ((SWORD) ((c+d) % lg_tabul) != (SWORD) 0)\
     c = (SWORD) (((((c + d + lg_tabul) / lg_tabul) * lg_tabul) + 1) - d);\
     else c ++;\
}

#define LgNextTab(c,d) { c = (SWORD) (((((c + d + lg_tabul) / lg_tabul) * lg_tabul) + 1) - d); }

/*	Etat courant en memoire		*/
/*	-----------------------		*/

#include "edmem.h"

extern SWORD ligcur,colcur;	/* position courante en memoire */

extern SWORD NBLIG;		/* nb reel de lignes montees en memoire */

extern SWORD lastligne;	/* derniere ligne affichee */
extern SWORD firstcol;	/* premiere colonne affichee */


extern ULONG numlgn;		/* numero ligne courante affichee */




extern BYTE com[];

extern SWORD err_ecart;


#include "cursor.h"

extern SWORD LGINIT,CLINIT;	/* 1ere position ecran utilisable */
extern SWORD MXLIG,MXCOL;	/* dimensions physiques de l'ecran */

extern SWORD ernoy03;
extern SWORD LGERR,COLERR;	/* position des messages d'erreur */

extern SWORD ligne,colonne;	/* position ecran courante */

extern SWORD lg_tabul;

extern SWORD APU;	/* attribut preferentiel de l'utilisateur */

extern BOOL flg_InsLgn, flg_DelLgn;	/* possibilites video */


extern BOOL txtchg, txtcons; /* et si il a change */

extern BOOL trace_err;

/* 	Flag HELP 	*/
/*	---------	*/
extern BOOL flg_help;


/*	Valeurs des touches speciales servant aux commandes	*/
/*	---------------------------------------------------	*/

#ifdef integre

extern BYTE vcomed[];
extern BYTE ESCAPE,CURD,CURG,CURH,CURB;

	/*	definitions pour l'acces aux commandes d'edition	*/

#define	PHOME	vcomed[0]
#define	PDEBFIN	vcomed[1]
#define	PGDN	vcomed[2]
#define	PGUP	vcomed[3]
#define	CENTER	vcomed[4]
#define	NEXTWORD vcomed[5]
#define	PREVWORD vcomed[6]
#define	ILINE	vcomed[7]
#define	DLINE	vcomed[8]
#define	DELCAR	vcomed[9]
#define	DELBACK vcomed[10]
#define	DEOLN	vcomed[11]
#define	DBOLN	vcomed[12]
#define	UNDEL	vcomed[13]
#define	INSERT	vcomed[14]
#define	INDENT	vcomed[15]
#define	NUMLN	vcomed[16]
#define	NEXTERR	vcomed[17]

#else
extern BYTE vcomed[];

extern BYTE ESCAPE, INSERT, INDENT;
extern BYTE PGDN, PGUP;
extern BYTE CURB, CURD, CURG, CURH, NEXTWORD, PREVWORD;
extern BYTE DEOLN, DBOLN, DLINE, ILINE;
extern BYTE PDEBFIN, PHOME, CENTER, NUMLN;
extern BYTE DELCAR, DELBACK, UNDEL;
extern BYTE NEXTERR;

extern BYTE CORB;
#endif
extern BYTE T7F;
#define CTRLHOME 0x1C
/* 	Sauvegarde des coordonnees de la corbeil	*/
/* 	----------------------------------------	*/

extern SWORD debcol, fincol, realcol, rfincol;


extern LONG deblgn, finlgn; 




extern SWORD mfirstcol;
extern BOOL   boolcor, boolbloc, boolbest;
extern SWORD colbest,fcolbest;

/* global */ SWORD delecart;	/* Compteur de ligne supprimees */
/* global */ BOOL fin_fichier;  /* test la fin de fichier pour Descente */
/* 	Sauvegarde de la position courante		*/
/*	----------------------------------		*/


/* global */ LONG saunum;




/* global */ SWORD saulgn, saufirst, saulig, saucol, saurcol, saulast;

/*	Pour la bufferisation de tout l'ecran		*/
/*	-------------------------------------		*/

       BOOL aff_ecran=FALSE;

/* 	Structure pour l'allocation de la corbeille	*/
/*	-------------------------------------------	*/
#define NIL 0
#ifndef ver21
#define StrCor struct _MTCOR
StrCor {
	BYTE FPTR lgn;
	StrCor FPTR suiv;
};
#endif
/* global */ StrCor FPTR tete;

/*	Gestion de l'etat courant de l'editeur		*/
/*	--------------------------------------		*/

/* global */ BOOL flg_insert;		/* mode insertion */
/* global */ BOOL flg_indent;		/* mode indentation */
/* global */ BOOL flg_affnbln;		/* Affichage numero de lignes */

static BYTE flg_undel;		/* fonction 'UnDelete' possible */


/*	Gestion du mode TRACE		*/
/*	---------------------		*/

extern BOOL	traceon;	/* mode trace oui / non */

/*	Messages	*/
/*	--------	*/
#include "edmsgid.h"

extern BYTE  XPTR edit_msg[];

#ifdef ver14
#define Xisalnum(c) XXisalnum(c)
#else
#define Xisalnum(c) isalnum(c)
#endif

/* SOURIS */
SWORD mouse_col;
SWORD mouse_lin;
SWORD mouse_bouton;

#define MOUSE /* was 0x00f0 is now */ 256

/*	Prototypage des fonctions utilisees par le module	*/
/*	-------------------------------------------------	*/

#ifdef LINT_ARGS
#ifdef souris
extern SWORD RelacheSouris(SWORD , SWORD *, SWORD *);
extern SWORD StateSouris(SWORD *, SWORD *);
#endif
extern SWORD Lgnlen (BYTE *);

extern BOOL tstfinsource (void);
extern BOOL getsource (BYTE XPTR);
extern BOOL getfic (TFILE XPTR, BYTE XPTR);
extern void putfic (TFILE XPTR, BYTE XPTR);
extern void completer(SWORD);
extern BOOL poscol(void);
extern BOOL changer(SWORD, SWORD, SWORD, BYTE XPTR);
extern void Xatb(BYTE);

static void PageDown (void);
static void PageUp (void);
int	Montee(void);
int	Descente(void);
static void Precedent(void);
static void Suivant(void);
static void NextWord(void);
       void BackWord(void);
static void Deline(void);
static void Delcar(void);
static void Backspace(void);
static void Delfline(void);
static void Deldline(void);
static void DebutFin(void);
static void HomeEnd(void);
static void UnDelete(void);
static void Centrage(void);
static void NewLine(void);
#ifdef ver14
static SWORD XXisalnum(BYTE);
	void Debut(void);
	void affnumligne (void);
#endif

#ifndef integre
static BOOL Corbeil(void);
void Debtaq(void);
void Fintaq(void);
static void Razcorb(void);
static void Affdel(void);
static void Delcorb(void);
static void Poscorb(LONG, SWORD);
static BOOL Allocor(void);
static void Rempcor(void);
static void Inscor(BOOL);
static void Movcor(BOOL);
static void nextpage(BOOL);
/*global*/ void Raztamp(void);
#ifdef ver14
static void Modevi(void);


/*global*/ SWORD test_bloc(LONG);





void cursor_goto(SWORD, SWORD);
#endif


SWORD test_corb(LONG, SWORD);

SWORD test_atb(LONG, SWORD);


void 	alloc2(SWORD, BYTE FPTR);
void 	corb_CURB(BOOL);
#endif

/* global */ void Insline(void);
/* global */ BOOL centrer(void);
/* global */ void affecran (void);
/* global */ void affligne (SWORD);
/* global */ void newcol (BOOL);

/* global */ void video (void);

/* global */ void saisie(BYTE);
/* global */ BOOL carvisu(BYTE);

extern void aff_help(void);

extern BOOL commande (void);

extern void poserrsuiv ( void );

#ifdef ver21
extern void poserrback( void );
#endif

#ifndef integre
#ifndef ver14
extern void memento(void);
#endif
extern void Xerreur (BYTE,SWORD);
#endif
extern void initerm (void);
extern void finterm (SWORD);
extern void x_clear (void);
extern void pos (SWORD, SWORD);
extern void x_putch (SWORD);
extern SWORD x_getch (void);
extern void atb (SWORD);
extern void editor_bell (void);
extern int prfo(SWORD ,BYTE FPTR, SWORD);
extern int lcfo(SWORD,BYTE FPTR, SWORD);
extern void x_cprintf(BYTE FPTR);
extern SWORD conf (SWORD);
extern SWORD x_kbhit(void);

extern void get_token(void);

extern void x_bstart (void);
extern void x_bflush (void);

#else

extern void aff_help();

extern SWORD Lgnlen ();

extern BOOL tstfinsource ();
extern BOOL getsource ();
extern BOOL getfic ();
extern void putfic ();
extern BOOL changer();
extern BOOL poscol();

static void PageDown ();
static void PageUp ();
static void Montee();
static void Descente();
static void Precedent();
static void Suivant();
static void NextWord();
       void BackWord();
static void Delcar();
static void Backspace();
static void Deline();
static void Delfline();
static void Deldline();
static void DebutFin();
       void Debut();
static void HomeEnd();
static void UnDelete();
static void Centrage();
static void affnumligne ();
static void NewLine();
#ifdef ver14
static SWORD  XXisalnum();
#endif

#ifndef integre
static BOOL Corbeil();
static void Debtaq();
static void Fintaq();
static void Razcorb();
static void Delcorb();
static void Affdel();
static void Poscorb();
static BOOL Allocor();
static void Rempcor();
static void Inscor();
static void Movcor();
static void nextpage();

/*global*/ void Raztamp();
#ifdef ver14
static void Modevi();
/*global*/ int test_bloc();
#endif
int 	test_corb();
int	test_atb();
void 	alloc2();
void 	corb_CURB();
void   cursor_goto();
#endif

/* global */ void Insline();
/* global */ BOOL centrer();
/* global */ void affecran ();
/* global */ void affligne ();
/* global */ void newcol ();
/* global */ void video ();

/* global */ void saisie ();
/* global */ BOOL carvisu();

extern BOOL commande ();
extern void poserrsuiv ();

#ifndef integre
#ifndef ver14
extern void memento();
#endif
extern void Xerreur ();
#endif
extern void 	Xatb();

extern SWORD x_kbhit ();
extern void initerm ();
extern void finterm ();
extern void x_clear ();
extern void pos ();
extern void x_putch ();
extern SWORD x_getch ();
extern void atb ();
extern void editor_bell ();
extern SWORD prfo();
extern SWORD lcfo();
extern void x_cprintf();
extern SWORD conf ();
extern void x_bstart ();
extern void x_bflush ();

#endif
