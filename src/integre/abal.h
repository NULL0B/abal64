/*-------------------------------------------------------------- ABAL.H -----
 *
 *	Ensemble integre ABAL	  -	Copyright (c) Amenesik / Sologic s.a. 1989,1991
 *
 *		   Definitions globales de l'ensemble
 *
 *		      Revision 1.4 du 07/08/1991
 *
 *--------------------------------------------------------------------------*/

/*	La definition de l'environnement utilise doit etre faite
 *		lors de l'appel au compilateur
 */

#if small || unix || vms
#define XPTR *		/* type pointeur */
#define FPTR *
#else
#define XPTR *		/* type pointeur */
#define FPTR  far *
#endif

#ifdef	VERSION666
typedef unsigned int BINAIRE;	/* type binaire sur 2 octets */
#else
typedef unsigned short int BINAIRE;	/* type binaire sur 2 octets */
#endif
typedef unsigned char BYTE;		/* type binaire sur 1 octet */

#define MOINS_UN -1
#define cartoint(c) (c - '0')
#define inttocar(n) (unsigned char) (n + '0')

/*	Parametres dependants du systeme hote 		*/
/*	-------------------------------------		*/
#define LGEXT 5
#define LGCOM 250
#ifdef prologue
/*	Variables pour le tas + pile pour prologue */
/*	------------------------------------------ */

#define SEPTYP   "-"  /* separateur entre nom et extension d'un fichier */
#define DELIMOPT " /"  /* delimiteur des options dans ligne de commande */

#define SEPVOL "."
#define DELIMREP "\\" /* delimiteur entre repertoire et nom de fichier */



#define LGMXNOM 78	/* lg max d'un nom de fichier */
#define LGREP	80 	/* lg d'un repertoire */

#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <ctype.h>
#include <prl.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>

_mem_res = 1;
_stkmin = 8192;
_stklen = 20000;

#endif

#ifdef msdos

#define SEPVOL ":"
#define SEPTYP   "."  /* separateur entre nom et extension d'un fichier */
#define DELIMOPT " /"  /* delimiteur des options dans ligne de commande */
#define DELIMREP "\\" /* delimiteur entre repertoire et nom de fichier */

#define LGMXNOM 78	/* lg max d'un nom de fichier */
#define LGREP	80 	/* lg d'un repertoire */

#include <errno.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#ifdef BORLAND
#include <alloc.h>
#else
#include <malloc.h>
#endif
#include <fcntl.h>
#include <sys\types.h>
#include <sys\stat.h>
#include <setjmp.h>
#include <stddef.h>
#include <errno.h>
#include <io.h>
#include <dos.h>
#endif

#ifdef unix

#define SEPVOL ""
#define SEPTYP   "."  /* separateur entre nom et extension d'un fichier */
#define DELIMOPT " -"  /* delimiteur des options dans ligne de commande */
#define DELIMREP "/"  /* delimiteur entre repertoire et nom de fichier */
#define LGMXNOM 248	/* lg max d'un nom de fichier */
#define LGREP	250 	/* lg d'un repertoire */

#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char *malloc();

/*LINTLIBRARY*/		/* LINT: laisser tomber les fonctions de la	*/
			/* bibliotheque non utilisees par le programme  */

#define buf_cico	/* affichage ecran bufferise */

#endif

#ifdef vms
#define SEPVOL ":"
#define SEPTYP   "."  /* separateur entre nom et extension d'un fichier */
#define DELIMOPT " /"  /* delimiteur des options dans ligne de commande */
#define DELIMREP "]"  /* delimiteur entre repertoire et nom de fichier */
#define LGMXNOM 248	/* lg max d'un nom de fichier */
#define LGREP	250 	/* lg d'un repertoire */

#include <errno.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <file.h>
#include <unixio.h>
#include <stsdef.h>

#define buf_cico	/* affichage ecran bufferise */


#endif
#ifdef vms
static int VAL_RET = 1;
#else
static int VAL_RET = 0;
#endif

	/* Longueur de la zone de parametre */

#define LGPARAM 250

#ifndef vms
#define  Xsystemd(c,t,b,s) systemd(c,t,b,s)
#define  Xsysteme(c) systeme(c)
#define  Xsystemr()  systemr()
#else
#define  Xsystemd(c,t,b,s) system(c)
#define  Xsysteme(c) system(c)
#define  Xsystemr()  systemr()
#endif

BINAIRE valeur_in;
BINAIRE valeur_out;

#define  FILLIN  Xset_filler( TRUE  )
#define  FILLOUT Xset_filler( FALSE )

#ifdef msdos
#define  Xsystemdos(c,b) systemdos(c,b);
#endif

/*		definition des fonctions standards utilisees		*/
/*		--------------------------------------------		*/
/*		Rem: ces redefinitions sont faites pour faciliter	*/
/*		un portage dans un contexte different, cependant,	*/
/*		printf et fprintf sont supposees "standard 100%".	*/
/*		ainsi que tous les 'is...(i)' (classification CTYPE)	*/

#ifndef unix
#define Xfn_parser(s,d,m) fn_parser(s,d,m | 128) 
#else
#define Xfn_parser(s,d,m) fn_parser( s,  d,m)
#endif


#define Xexit(n) exit(n)

#define Xfree(p) free(p)

#define Xmalloc(n) malloc(n)

#define Xstrcat(s,p) strcat(s,p)
#define Xstrchr(s,c) strchr(s,c)
#define Xstrcmp(s,p) strcmp(s,p)
#define Xstrncmp(s,p,n) strncmp(s,p,n)
#define Xstrcpy(d,s) strcpy(d,s)
#define Xstrlen(s) strlen(s)
#define Xstrrchr(s,c) strrchr(s,c)


#ifdef vms
#define Xaccess(f,m) vms$access()
#define Xunlink(n) delete(n)
#else
#define Xunlink(n) unlink(n)

#ifdef unix
#define Xaccess(f,m) Access(f,6,m)
#else
#define Xaccess(f,m) access(f,m)
#endif
#endif

#define Xfopen(f,m) XAfopen(f,m)
#define Xfclose(f) fclose(f)
#define Xfputc(c,f) fputc(c,f)
#define Xfgetc(c) fgetc(c)

/*		test d'egalite entre deux chaines		*/
/*		---------------------------------		*/

#define strEq(s1,s2) (Xstrcmp(s1,s2) == 0)

/*	 	definition generique d'un pointeur NULL 	*/
/*		---------------------------------------		*/

#define GenericNULL(t) (t XPTR) NULL

/*		definition du type logique/BOOLEEN		*/
/*		----------------------------------		*/

typedef unsigned char BOOL;

#define TRUE 1
#define FALSE 0

/*		gravite des erreurs			*/
/*		-------------------			*/

#define USUAL	'1'
#define FATALE	'2'

/*		parametres au niveau global		 */
/*		---------------------------		 */


#define EOSTR '\0'            /* caractere terminateur de chaine C */

#define CR	'\r'
#define NL	'\n'
#define PLUS	'+'

/*	variables utilisees par la gestion de l'ecran et du clavier	*/
/*	-----------------------------------------------------------	*/
#include "abalcico.h"

#ifdef	vms
extern  qio_usage_flag;
#endif

#if unix || vms
int 	flag_modterm;
#endif

/* 	ex maquette.h 	*/
/*	-------------	*/

#define LGAFF 20
#define LGARGU 256
#define NBEXT 5

#ifdef ver21
/* #BG Skipper supprimé
#define NBREP 6*/
#define NBREP 5
#else
#define NBREP 5
#endif

#define MAXMOD  10

#define LMAXHIS 20
#define TABUL 9
#define LGBNOM 13
#define LGVOL 3

#define RCH 48
#define RCB 60

#ifdef vms
static int REDEF1 = 0xae;
#else
static int REDEF1 = 0xc1;
#endif
#define rcol 1

#define MOINS '-'

static BYTE sel[LGREP];
static BYTE tmp[LGREP];
static BYTE n_path[LGREP];
static BYTE buf_path[LGREP];
static BYTE edit_tmp[LGREP];

static BYTE sext[4];

static BINAIRE nalloc;	/* test le nombre d'allocation */


BOOL	flgsuite = FALSE;
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



#define FileCat struct _Fic	/* Liste des procedures externes */
FileCat {
	BYTE nom[LGREP];
	BYTE etat;
};
#define All_Cat()	 (FileCat FPTR) allocate(sizeof(FileCat))
#define Free_Cat(p)	 liberate(p)


#define Liste struct _Lis	/* Liste de cfic */
Liste {
	FileCat FPTR ptfic;
	Liste XPTR next, XPTR back;
};
#define All_Lis()	 (Liste XPTR) Xmalloc(sizeof(Liste))
#define Free_Lis(p)	 Xfree((BYTE XPTR) p)


/* Structure generale des parties */
#define StrGen struct _Gen
StrGen {
	BINAIRE ncol,nlig;
	BINAIRE imax, jmax;

	BINAIRE deb_page,fin_page; /* Bornes de la page affichee */
	Liste XPTR adr_deb, XPTR adr_fin; /* Pointeur sur les bornes */
	
	BINAIRE LH,CH,LB,CB;
	BYTE cat_mod[LGREP];

	BYTE nom[LGMXNOM]; /* Nom de la liste */
	
	int lg_liste;
	BOOL type_aff;  /* 0 affiche path+nom  1 affiche nom uniquement */
	Liste XPTR lnext;	/* pointe sur le prochain */
	Liste XPTR lback;   /* pointe sur le dernier */

	Liste XPTR adr_fic;		/* Sauvegarde de l'adresse du dernier cfic */
	BINAIRE num_fic;	/* pointe ainsi que son numero */
	
	BINAIRE LG_AFF;
};

static StrGen cfic;
static StrGen crep;
static StrGen hissrc;
static StrGen hismak;
static StrGen histra;
static StrGen hissys;

/*************************

	Init maquette

*************************/

static char cfgtmp[LGREP];
static char nomfic[LGREP];
static char nomcur[LGREP];
static char nomprj[LGREP];
static char nomcfg[LGREP];
static char nomtmp[LGREP];
static char reptmp[LGREP];
static char argtmp[LGREP];
static char edittmp[LGREP];

#ifdef ver21
int skipper_is_here = 0;
static char argskipp[LGREP];
#endif
static char argtsf[LGREP];
static char argecran[LGREP];
static char argtrans[LGREP];
/* #BG static char argsvsi[LGREP];*/
/* #BG static char argrtsi[LGREP];*/
static char argsvam[LGREP];
static char argrtam[LGREP];
static char argfrmc[LGREP];
static char argfrbd[LGREP];
static char argsys[LGREP];

static char ficarg[LGARGU];
static char nomargu[LGARGU];

/* position des options dans hmenu */
static char tpos[7];

static char EXTO[LGEXT];

static char EXTS[LGEXT];
static char EXTE[LGEXT];
static char EXTL[LGEXT];
static char EXTSAV[LGEXT];
static char EXTPRJ[LGEXT];
static char EXTT[LGEXT];
static char EXTB[LGEXT];

static char XPTR tab_ext[NBEXT];

static int  iext;
static int  irep;

       char REPS[LGREP];
       char REPI[LGREP];
       char REPM[LGREP];
       char REPT[LGREP];
       char REPB[LGREP];

#ifdef ver21
static char REPPIKS[LGREP]; /*skipper en verlan */
static char REPTMP[LGREP];
#endif

/*global*/ char XPTR tab_rep[NBREP];

static int nbmods;
static char lstmod[LGARGU];

static char lstdef[LGARGU];

static char param[LGARGU];
static char prog[LGREP];

static BYTE savedir[LGREP];

static BYTE XPTR  nextindice;
/* booleen pour controler la mise a jour du cfg */
static BOOL boolcfg;



