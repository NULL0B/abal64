/*---------------------------------------------------------------EDNOY.H -----
 *
 *	Editeur de textes ABAL	  -	Copyright Amenesik / Sologic s.a. (c) 1989
 *
 *		   Definitions du noyau de l'editeur
 *
 *		      Revision 1.0 du 13/10/1997
 *		      Revision 2.0 du 08/10/2001
 *
 *--------------------------------------------------------------------------*/

/*	Date de la derniere mise a jour		*/
/*	-------------------------------		*/
/*
 * 13/10/97 : Gestion de plus de 65000 (YT131097)
 */

#ifdef	_edmain_c
#define	public extern
#else
#define	public
#endif



#ifdef pilote



#ifdef	ver2K
#define	ver2Kalloc
#include "allocate.h"
#define	verGraphic
#define prov	"\n   Provisoire 18/02/2008"
#else
#define prov	"\n   Provisoire 9/3/1998"
#endif
#define vpro	"" /* "\n   PROVISOIRE 01/07/1989" */

#else

#define prov	""
#define vpro	""
#endif

#ifdef	VERSION666
#define ved	'3'
#define ied	'2'
#define red	'a'
#else
#ifdef ver2K
#define ver12
#define ver13
#define ver14
#define ved	'2'
#define ied	'2'
#define red	'a'
#else
#ifdef ver12
#define ved	'1'
#define ied	'2'
#define red	'g'
#else
#ifdef ver13
#define ver12
#define ved	'1'
#define ied	'3'
#define red	'd'
#else
#ifdef ver21
#define ver12
#define ver14
#define ved	'2'
#define ied	'1'
#define red	'c'
#else
#define ver12
#define ved	'1'
#define ied	'4'
#define red	'c'
#endif
#endif
#endif
#endif
#endif	/* VERSION666 */

/*	Messages non traduisibles !!	*/
/*	----------------------------	*/

#define version		"Version "
#define vved 	'1'
#define vied	'1'
#define vred	'a'

#ifdef	VERSION666
#define copyright	"Copyright (c) 1988,2008 Amenesik / Sologic s.a."
#else
#ifdef	ver2K
#define copyright	"Copyright (c) 1988,2001 Amenesik / Sologic s.a."
#else
#define copyright	"Copyright (c) 1988,1998 Amenesik / Sologic s.a."
#endif
#endif
/*	-----------------		*/

#include "cursor.h"

#define ctrlbyte(c) ((BYTE) c < 0x020)

#define putch(c) x_putch((SWORD) c)
#define getch() (BYTE) x_getch()

#define getdest(p) getfic(fdest,p)
#define getret(p) getfic(fret,p)
#define putdest(p) putfic(fdest,p)
#define putret(p) putfic(fret,p)

#define putsrce(p) putfic(fs,p)

#define NextTab(c,d) {	if ((SWORD) ((c+d) % lg_tabul) != (SWORD) 0)\
     c = (SWORD) (((((c + d + lg_tabul) / lg_tabul) * lg_tabul) + 1) - d);\
     else c ++;\
}

#define LgNextTab(c,d) { c = (SWORD) (((((c + d + lg_tabul) / lg_tabul) * lg_tabul) + 1) - d); }

#if unix || vms
#define Xsystemd(c,t,b,s) system(c)
#else
#define Xsystemd(c,t,b,s) systemd(c,t,b,s)
#endif

/*	-----------------		*/
extern BYTE buf_getch[80];

static BYTE * nextindice;

SWORD nballoc;

static BYTE ryes;
static BYTE rno;

#ifdef ver14
static BYTE XPTR etxmes;
#endif

public	SWORD LGFIND;	/* longeur trouvee par wildcomp */

public TFILE *fs;	/* description fichier source */
public TFILE *fdest;	/* description fichier destination */
public TFILE *fret;	/* description fichier retour */
public  FILE *farg;	/* description fichier argument */

static BYTE ligarg[512];	/* Longueur de la ligne de commande */
static BYTE nomargu[LGMXNOM];	/* nom du fichier argument */
static BYTE nomsrce[LGMXNOM];	/* nom du fichier source */
static BYTE nombak[LGMXNOM];	/* nom du fichier sauvegarde */
static BYTE nomdest[LGMXNOM];   /* nom du fichier destination */
static BYTE nomret[LGMXNOM];	/* nom du fichier retour */
static BYTE firstedit[LGMXNOM]; /* nom du premier fichier editer */
static BOOL flg_def_dest;	/* destination explicite -> */
static BYTE nomdef[LGMXNOM];	/* nom du fichier definitif en sortie */

static BOOL flgcreat;	/* flag : creation du fichier edite */

/*	Etat courant en memoire		*/
/*	-----------------------		*/

#include "edmem.h"


public SWORD ligcur,colcur;	/* position courante en memoire */

public SWORD NBLIG;		/* nb reel de lignes montees en memoire */

public SWORD lastligne;	/* derniere ligne affichee */
public SWORD firstcol;	/* premiere colonne affichee */

public ULONG numlgn;		/* numero ligne courante affichee */

/* 		Test si le source a ete modifie et si mode consultation */
/*		-------------------------------------------------------	*/
/*global*/ BOOL txtchg;
/*global*/ BOOL txtcons;
/*gloabl*/ BOOL trace_err;

/*		BOOLEANS pour pattern de recherche 	*/
/*		----------------------------------	*/
static BOOL JOKER;
static BOOL MAJMIN;
static BOOL BOOLBAK;
static BOOL SAVE_NOBAK;

/*	Memoire temporaire pour gestion du tampon 		*/
/*	-----------------------------------------		*/

#define MemTemp	struct _MT
MemTemp {
	BYTE *    lgn;
	MemTemp	* suiv;
};

static MemTemp	*tampon;

#ifndef integre		/* Permet lors de la sortie d'AED de vider le tampon */

extern StrCor FPTR tete;

#define NIL 0

#endif
/*	Variables de la gestion de l'ecran et du clavier	*/
/*	------------------------------------------------	*/

#ifndef	EXAWORD
#ifdef	VERSION666
#define	EXAWORD unsigned long int
#else
#define	EXAWORD unsigned short int
#endif
#endif

#ifdef vms
extern SWORD qio_usage_flag;
#endif

#include "abalcico.h"

extern BOOL aff_ecran;
#ifdef prologue
/*	Variables pour le tas + pile pour prologue */
/*	------------------------------------------ */

#ifndef anc_bib
#ifdef	BEFORE_C8
int	_mem_res = 1;
int 	_stkmin = 15000;
int 	_stklen = 35000;
#endif

/*	Buffer + Variables pour lg exacte 	*/
/*	---------------------------------	*/
BYTE    lg_compatible;
BYTE 	_ngf_dd[64];
SWORD nsect, lg_file, noff;
#endif
#endif

LONG lgexacte;
extern void get_token(void);

extern void BackWord(void);

/*	Variable pour le tas et la pile de la nouvelle Bibli 	*/
/* 	----------------------------------------------------	*/

public BOOL curs_is_on;		/* etat courant du curseur */

public SWORD LGINIT,CLINIT;	/* 1ere position ecran utilisable */
public SWORD MXLIG,MXCOL;	/* dimensions physiques de l'ecran */

public SWORD LGERR,COLERR;	/* position des messages d'erreur */

public SWORD ligne,colonne;	/* position ecran courante */

public SWORD lg_tabul;

public SWORD APU;	/* attribut preferentiel de l'utilisateur */

public BOOL flg_InsLgn, flg_DelLgn;	/* possibilites video */


/*	Valeurs des touches speciales servant aux commande	*/
/*	--------------------------------------------------	*/

#ifdef integre

extern BYTE vcomed[];
extern BYTE ESCAPE,CURD,CURG,CURH,CURB;

/* extern BOOL flg_cico;	ecran deja initialise */

#define	PDEBFIN	vcomed[1]
#define	DELBACK vcomed[10]

#else

public BYTE INSERT, INDENT;
public BYTE vcomed[18];
public BYTE ESCAPE;
public BYTE PGDN, PGUP;

public BYTE CURB, CURD, CURG, CURH, NEXTWORD, PREVWORD;
public BYTE DEOLN, DBOLN, DLINE, ILINE;
public BYTE PDEBFIN, PHOME, CENTER, NUMLN;
public BYTE DELCAR, DELBACK, UNDEL;
public BYTE NEXTERR;

public BYTE CORB;

static BYTE SAVCURB[32], SAVCURD[32], SAVCURG[32], SAVCURH[32];
#endif
#ifndef	_edmain_c
BOOL flg_cico=0;
#else
extern BOOL flg_cico;	/* ecran deja initialise */
#endif
public BYTE T7F;
static BYTE ST7F[32];


/*	Touches de fonction 	*/
/*	-------------------	*/

#define VEOF 0x1A
#define LGTFP 33

static BYTE eltf1[LGTFP];
static BYTE eltf2[LGTFP];
static BYTE eltf3[LGTFP];
static BYTE eltf4[LGTFP];
static BYTE eltf5[LGTFP];
static BYTE eltf6[LGTFP];
static BYTE eltf7[LGTFP];
static BYTE eltf8[LGTFP];
static BYTE eltf9[LGTFP];
static BYTE eltf10[LGTFP];

static BYTE *epltfp[] = { &eltf1[0], &eltf2[0], &eltf3[0], &eltf4[0], &eltf5[0],
			 &eltf6[0], &eltf7[0], &eltf8[0], &eltf9[0], &eltf10[0]
};
		/* Sauvegarde des touches de fonction */

#ifdef prologue
static BYTE sltf1[LGTFP];
static BYTE sltf2[LGTFP];
static BYTE sltf3[LGTFP];
static BYTE sltf4[LGTFP];
static BYTE sltf5[LGTFP];
static BYTE sltf6[LGTFP];
static BYTE sltf7[LGTFP];
static BYTE sltf8[LGTFP];
static BYTE sltf9[LGTFP];
static BYTE sltf10[LGTFP];

static BYTE *epstfp[] = { &sltf1[0], &sltf2[0], &sltf3[0], &sltf4[0], &sltf5[0],
			 &sltf6[0], &sltf7[0], &sltf8[0], &sltf9[0], &sltf10[0]
};

#endif


/*	Variables pour le help				*/
/*	----------------------				*/
public SWORD h_page, h_indice,nbl;
public BOOL flg_help;


/* 	Sauvegarde des coordonnees de la corbeil 	*/
/*	----------------------------------------	*/

public SWORD debcol, fincol, realcol, rfincol;	


public LONG deblgn, finlgn;


public BOOL boolcor, boolbloc, boolbest;
public SWORD colbest,fcolbest;

/*	Sauvegarde de la position avant commande	*/
/*	----------------------------------------	*/


public LONG mlig;




public SWORD mcol, mfirstcol, mcolr;


/*	Gestion de l'etat courant de l'editeur		*/
/*	--------------------------------------		*/

extern BOOL flg_insert, flg_indent;
#ifdef ver21
extern BOOL flg_affnbln;
#endif
#ifdef ver14
#define LGCOM 256
#else
#define LGCOM 45
#endif

public BYTE com[LGCOM];

/*	Gestion du mode TRACE		*/
/*	---------------------		*/

public BOOL	traceon;	/* mode trace oui / non */

static BYTE nomtrace[LGMXNOM];	/* nom du fichier d'erreurs */
static FILE *ftrace;		/* et reference a ce fichier */

static BYTE nomerr[LGMXNOM];  /* nom du fichier contenant l'erreur courante */

#ifdef	ver2Kalloc
static BYTE *	curerr=(BYTE *) 0; /* [LGLIGNE]; */ /* message de l'erreur courante */
#else
static BYTE	curerr[LGLIGNE]; /* message de l'erreur courante */
#endif
static SWORD	clerr;	 /* position de l'erreur dans la ligne */


static LONG 	plerr;	 /* position de l'erreur */




public SWORD err_ecart;  /* ecart entre numerotation erreurs et source */

#define ChnFic struct _CnFn 
ChnFic {
	BYTE	nom[16];
	SWORD  	ecart;
	ChnFic	*suiv;
};

ChnFic	*deb_chnfic;

#ifdef ver14

/* 	Variable pour l'historique 	*/
/*	--------------------------	*/

BYTE n_path[LGREP];


#define LMAXHIS 20

#define FileCat struct _Fic	/* Liste des procedures externes */
FileCat {
	BYTE nom[LGCOM];
	BYTE etat;
};
#define All_Cat()	 (FileCat *) malloc(sizeof(FileCat))
#define Free_Cat(p)	 free((BYTE *) p)


#define Liste struct _Lis	/* Liste de cfic */
Liste {
	FileCat *ptfic;
	Liste *next, *back;
};
#define All_Lis()	 (Liste *) malloc(sizeof(Liste))
#define Free_Lis(p)	 free((BYTE *) p)


/* Structure generale des parties */
#define StrGen struct _Gen
StrGen {

	SWORD lg_liste;

	Liste *lnext;	/* pointe sur le prochain */
	Liste *lback;   /* pointe sur le dernier */

	Liste *adr_fic;		/* Sauvegarde de l'adresse du dernier cfic */
	
};

static StrGen chis;


/* Structure Pour date et heures */
/* ----------------------------- */

struct _b32 {
	BYTE hh;
	BYTE ss;
	BYTE mm;
	BYTE MM;
	BYTE DD;
	BYTE AA;
} b32;

#ifdef msdos

#ifndef BORLAND
struct dosdate_t _date;
struct dostime_t _time;
#define get_date(t) _dos_getdate(t)
#define get_time(t) _dos_gettime(t)

#else /* BORLAND */
struct date _date;
struct time _time;
#define get_date(t) getdate(t)
#define get_time(t) gettime(t)

#endif
	

#else /* prologue */

struct tm *pt_time;
time_t gettime;

#endif

#ifdef prologue
typedef struct {
	int no_logique;
	long x;
	long y;
} _fcb_struct;

extern _fcb_struct _fcb[];
#endif
#endif

/*	Pour retour en cas d'erreur fatale		*/
/*	----------------------------------		*/


/* SOURIS */

extern SWORD mouse_col;
extern SWORD mouse_lin;
extern SWORD mouse_bouton;
#ifdef souris
extern SWORD InitSouris(SWORD XPTR);
extern void LimitSouris(SWORD, SWORD, SWORD);
extern void PositSouris(SWORD, SWORD);
#endif
#define MOUSE /* was 0x00f0 is now */ 256



/*	Prototypage des fonctions utilisees par le module	*/
/*	-------------------------------------------------	*/

#ifdef LINT_ARGS

#ifdef integre
public	SWORD editeur (BYTE XPTR,BOOL,SWORD);
#else
void banniere (void);
public	SWORD main (SWORD, BYTE XPTR []);
#endif

static void initabmes(void);
static BOOL initgene (SWORD,BYTE XPTR []);
static BOOL initrace (BYTE XPTR);
static void initecran (void);
static void finecran (void);
static BOOL init_arg(BYTE XPTR);
static BOOL NextOpt(BYTE XPTR XPTR);

#ifndef vms
static BOOL getnomfic (BYTE XPTR, BYTE XPTR, BYTE XPTR);
#else
extern BOOL getnomfic (BYTE XPTR, BYTE XPTR, BYTE XPTR);
#endif

static BOOL striEq (BYTE XPTR,BYTE XPTR);
static void designation (BYTE XPTR);
static void xrename (BYTE XPTR,BYTE XPTR);

/*global*/ SWORD Lgnlen (BYTE XPTR);

/*global*/ void init_fic (BOOL,BOOL);

#ifdef ver14
/*global*/ void Memento(BYTE);
/*global*/ void go_help(void);
/*global*/ void aff_help(void);
/*global*/ void maj_taille(SWORD, SWORD);
static void outbin(SWORD, SWORD, SWORD);

#else
/*global*/  void memento(void);
#endif

/*global*/  void XX_cprintf(BYTE XPTR);

/*global*/ BOOL tstfinsource (void);

/*global*/ BOOL getsource (BYTE XPTR);
/*global*/ BOOL getfic (TFILE XPTR, BYTE XPTR);
/*global*/ void putfic (TFILE XPTR, BYTE XPTR);

/*global */ void completer(SWORD);
/*global */ BOOL poscol(void);
/*global */ BOOL changer (SWORD,SWORD,SWORD,BYTE XPTR); 
/*global */ void Xatb(SWORD);
static void initmem (void);
static void purgedest (void);
static void purgesrce(void);

#ifdef unix
extern void LiberLox(BYTE XPTR);
extern void PurgeLox(void);
extern int  Access(BYTE XPTR, SWORD, SWORD);
#endif

extern void video (void);
extern void affecran (void);
extern void affligne (SWORD);
extern void newcol (BOOL);
extern BOOL centrer (void);
extern void Insline(void);
extern void Debut(void);
extern void BackWord(void);

#ifndef integre
static BOOL ecrcor(BOOL, BYTE XPTR);
extern void Raztamp(void);
#endif

/*global */ BOOL commande (void);
static int  aff_com(BYTE XPTR);
static void get_saisie (BYTE XPTR,SWORD);
static BOOL confirme (SWORD,SWORD,BYTE XPTR);
void posdeb (void);
void posfin (void);
static int  poslgn (SWORD,LONG);
static int  ecrfic (BOOL,LONG,BYTE XPTR);
static BOOL lirefic (BYTE XPTR);
static BOOL getampon (SWORD);
static BOOL putampon (BOOL,BOOL,SWORD);
static void suplines (LONG);
static void libtampon (void);
static BOOL stop(void);
static BOOL recherche (SWORD,BYTE XPTR);
static BOOL replace (SWORD,BYTE XPTR,BYTE XPTR);
static BOOL lgnsearch (BYTE XPTR,BYTE XPTR,SWORD);

/* static BOOL changer (SWORD,SWORD,SWORD,BYTE XPTR); */
/* static void completer (SWORD); */
/* static BOOL poscol (void); */


static BOOL brecher(SWORD,BYTE XPTR);
static void liginv(BYTE XPTR);


static void reposit(LONG, SWORD, SWORD, SWORD);




/*global*/ void poserrsuiv (void);
#ifdef ver21
/*global*/ void poserrback (void);
#endif
#ifndef integre
/*global*/ void Xerreur (BYTE,SWORD);
#else
static void Xerreur(BYTE, SWORD);
#endif

static void reinit (void);
static BOOL lecconf(BYTE XPTR);
static void Xscanf( BYTE XPTR, SWORD XPTR , SWORD XPTR);

static VOID XscanfForLong(BYTE XPTR ,  SWORD XPTR , LONG XPTR );

static void Xfgets( BYTE XPTR, SWORD, FILE XPTR);

#ifdef ver14
extern void backgr(WORD);
extern void foregr(WORD);
extern void saisie(WORD);
#endif
extern SWORD x_kbhit(void);
extern void initerm(void);
extern void finterm(SWORD);
extern void x_clear (void);
extern void pos (SWORD,SWORD);
extern void x_putch (SWORD);
extern SWORD x_getch (void);
extern void atb (SWORD);
extern void editor_bell (void);
extern SWORD prfo(SWORD,BYTE FPTR , SWORD);
extern SWORD lcfo(SWORD,BYTE FPTR , SWORD);

extern void x_cprintf(BYTE FPTR ); 

extern SWORD conf (SWORD);
extern SWORD ask(SWORD, SWORD, SWORD, SWORD, BYTE XPTR);
extern SWORD fn_parser(BYTE FPTR , BYTE FPTR , SWORD);
extern void GetRep(BYTE XPTR, SWORD, SWORD);
extern void MakeReper(BYTE XPTR, BYTE XPTR);
extern void diff_repfich(BYTE XPTR, BYTE XPTR, BYTE XPTR);
extern void x_bstart (void);
extern void x_bflush (void);
#ifdef ver14
static SWORD wildcomp(BYTE XPTR, BYTE XPTR, SWORD);
static void init_his(void);
static void purge(void);
static void maj_histo(BYTE XPTR);
static void NextCom(BYTE XPTR);
static void BackCom(BYTE XPTR);
static void aff_file(BYTE XPTR);
static void aff_histo(void);
static void makenom(BYTE XPTR, BYTE);
static BYTE conv_base(BYTE);
static SWORD Xngffh(SWORD);
static void nedpause(void);
#endif

#else

#ifdef integre
public	SWORD editeur ();
#else
public	SWORD main ();
static void banniere ();
#endif

static void initabmes();
static BOOL initgene ();
static BOOL initrace ();
static void initecran ();
static void finecran ();


#ifndef vms
static BOOL getnomfic ();
#else
extern BOOL getnomfic();
#endif

static BOOL striEq ();
static void designation ();
static void xrename ();
static BOOL init_arg();
static BOOL NextOpt();

/*global */ SWORD Lgnlen ();

public void init_fic ();

#ifdef ver14
/*global */ void Memento();
/*global */ void go_help();
/*global */ void aff_help();
/*global */ void maj_taille();
static void outbin();
#else
/*global*/  void memento();
#endif
/*global*/  void XX_cprintf();

public BOOL tstfinsource ();

/*global */ BOOL getsource ();
/*global */ BOOL getfic ();
/*global */ void putfic ();

/*global */ void completer();
/*global */ BOOL poscol();
/*global */ BOOL changer ();
/*global*/  void Xatb();
static void initmem ();
static void purgedest ();
static void purgesrce ();

#ifdef unix
extern SWORD  Access();
extern void PurgeLox();
extern void LiberLox();
#endif

extern void video ();
extern void affecran ();
extern void affligne ();
extern void newcol ();
extern BOOL centrer ();
extern void Insline();
extern void Debut();

#ifdef ver14
static SWORD  wildcomp();
static void init_his();
static void purge();
static void maj_histo();
static void NextCom();
static void BackCom();
static void aff_file();
static void aff_histo();
static void makenom();
static BYTE conv_base();
static SWORD aff_com();
static SWORD Xngffh();
#endif

#ifndef integre
static BOOL ecrcor(BOOL, BYTE XPTR);
extern void Raztamp(void);
/*
static BOOL ecrcor();
extern void Raztamp();
*/
#endif

/*global */ BOOL commande ();
static SWORD  aff_com();
static void get_saisie ();
static BOOL confirme ();
void posdeb ();
void posfin ();
static int  poslgn ();
static void suplines ();
static void libtampon ();
static BOOL stop();
static BOOL recherche ();
static BOOL replace ();
static BOOL lgnsearch ();
/* static BOOL changer (); */
/* static void completer (); */
/* static BOOL poscol ();*/

static BOOL brecher();              
static void liginv();
static void reposit();

static BOOL lecconf();
static void Xscanf();
static void XscanfForLong();
static void Xfgets();

/*global*/ void poserrsuiv ();

#ifndef integre
/*global*/ void Xerreur ();
#else
static void Xerreur();
#endif


static void reinit ();
static void nedpause ();



extern void BackWord();

extern SWORD x_kbhit();
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
extern SWORD fn_parser();
extern void GetRep();
extern int ask();
#ifdef ver14
extern void backgr();
extern void foregr();
extern void saisie();
extern void getcwd();
#endif
extern void x_bstart ();
extern void x_bflush ();

#endif

