/*
 *	Projet  : ABAL		Copyright (c) 1991, 2004 Amenesik / Sologic Technologies
 *	Module  : TTY
 *	Fichier : UTTY.H
 *	Version : 1.3a
 *	Date    : 05/03/2004
 *	Systeme : Use IT et UNIX
 *
 *	Procedure TTY sous Linux et UNIX
 *
 *	[Definitions de la bibliotheque dynamique]
 *
 */

/*
 *	1.3a	05/03/2004	Chris
 *	-----------------------------
 *
 *	1/ Dans la structure DVOIE, bdattymode devient un WORD car c'est un
 *	nombre d'au moins 16 bits (a la place de BYTE).
 *	2/ Ajout prototypes fonctions dolock et unlock.
 *
 *
 *	1.3a	24/02/2004	Chris
 *	-----------------------------
 *
 *	1/ Dans la structure DVOIE, ajout de bdattymode qui est la valeur de
 *	la variable d'environnement BDATTYMODE (0 si inexistante).
 *
 *
 *	1.3a	23/02/2004	Chris
 *	-----------------------------
 *
 *	1/ Dans la structure DVOIE, vitesse, nbits, oparite, iparite,
 *	typeparite, nstops et modem sont des LONGs (au lieu de WORD).
 *
 *
 *	1.3a	06/02/2004	Chris
 *	-----------------------------
 *
 *	1/ Ajout prototype exclusif.
 *
 *
 *	1.3a	14/01/2004	Chris
 *	-----------------------------
 *
 *	1/ Suppression de la gestion du tampon d'anticipation. Suppression
 *	des champs anticipation, ltampon, child, father, shmid, semid, shm
 *	et psem dans la structure DVOIE. Suppression de la structure SHM.
 *	Supression des prototypes des fonctions Pcreat, fathersigusr2,
 *	fathersigusr1, childsigusr1, alimente, Pdelete, getsem, relsem et
 *	LLAread.
 *
 *
 *	1.3a	12/01/2004	Chris
 *	-----------------------------
 *
 *	1/ ttyconfig devient ttybuffer, ce qui est conforme avec tty.def.
 *
 *	2/ ttyselmode disparait, ce qui est conforme avec tty.def.
 *
 *
 *	1.3a	09/01/2004	Chris
 *	-----------------------------
 *
 *	1/ Suppression de la gestion des signaux SIGHUP et SIGINT. Suppression
 *	des champs sigmodem et sigint de la structure DVOIE.
 *	Ces signaux ne permettent pas la gestion multivoie car il n'existe
 *	qu'un signal par process pour toutes les voies donc piege a con.
 *
 *	2/ Gestion de 256 voies possible sans signaux SIGHUP et SIGINT.
 *
 *	3/ Ajout de la structure TRACE_BIN pour la trace binaire.
 *	Remplacement du champ journal par trace_handle dans la structure DVOIE.
 *	trace_handle est le handle du fichier de la trace binaire.
 *
 *
 *	1.2a	17/12/2003	Chris
 *	-----------------------------
 *
 *	1/ Forcer a 10 voies (au lieu de 256) car on ne gere les signaux
 *	SIGHUP et SIGINT que de 10 voies.
 *
*/

/* Quelques macros pour une meilleure portabilite */

#define		Xmemcpy(a,b,c)		memcpy(a,b,c)
#define		Xstrlen(a)		strlen(a)
#define		Xstrcpy(a,b)		strcpy(a,b)
#define		Xstrcmp(a,b)		strcmp(a,b)
#define		Xfree(a)		free(a)
#define		Xmalloc(a)		malloc(a)
#define		Xopen(a,b)		open(a,b)
#define		Xcreat(a,b)		creat(a,b)
#define		Xclose(a)		close(a)
#define		Xread(a,b,c)		read(a,b,c)
#define		Xwrite(a,b,c)		write(a,b,c)


/* Quelques definitions de constantes */

#define		MAXNOM		256		/* lgr maxi nom device */
#define		MAXNLOG		256		/* nombre de voies maxi */
#define		EOSTR		'\0'
#define		MAXTAMPON	32768		/* lgr maxi tampon anticipation */

#define		BCD_SEP		0x0a		/* definition des BCD */
#define		BCD_FIN		0x0f
#define		BCD_PLUS	0xc0
#define		BCD_MOINS	0xb0


/* Definitions SCO non portables */


#ifdef	CLAUDE_ROBLEZ
/* This is absolute shit ! */
#ifndef	CTSFLOW
#define		CTSFLOW		0
#endif
#ifndef	RTSFLOW
#define		RTSFLOW		0
#endif
#else
#include "modem.h"
#endif


/* Definitions X/OPEN compatible */

#ifndef CXOPEN
#define		IEXTEN		0
#define		TOSTOP		0
#endif


/* Definition d'un contexte de voie */

typedef struct {
	BOOL	attach;		/* indicateur d'utilisation du numero logique */
	int	handle;		/* handle associe au device */
	BYTE PTR device;	/* nom du device */
	BOOL	connex;		/* indicateur de connexion */
	BOOL	reserve;	/* indicateur de reservation */
	BOOL	open;		/* indicateur d'ouverture */
	LONG	vitesse;	/* vitesse de transmission */
	LONG	nbits;		/* nombre de bits par caractere */
	LONG	oparite;	/* indicateur de presence de parite en sortie */
	LONG	iparite;	/* indicateur de presence de parite en entree */
	LONG	typeparite;	/* type de parite */
	LONG	nstops;		/* nombre de bits stop */
	LONG	modem;		/* indicateur de gestion des signaux modems */
	BYTE	finenr;		/* caractere de fin d'enregistrement */
	BYTE	finfich;	/* caractere de fin de fichier */
	WORD	timeout;	/* time-out de reception */
	BOOL	transp;		/* indicateur de mode tranparent */
	BOOL	duplex;		/* indicateur de mode duplex */
	FILE	*trace_handle;	/* handle du fichier de trace binaire */
	WORD	bdattymode;	/* valeur de la variable d'environnement BDATTYMODE */
} DVOIE;

/*
 *	The buffer of trace is structured with blocks. Format of block is :
 *
 *	time_t : date of call TTY function
 *	function : function number, 1 = open, 2 = close, ...
 *	retcode : value returned to application
 *	nlog : handle returned from open et used by others functions
 *	maxlength : length of application buffer
 *	uselength : length of optional buffer, 0 means without associated data
 *	data : optional datas
 *
 *	If you change this structure, you must also modify the files
 *	tracetty.c and autotty.s
 */
#pragma	pack(1)
typedef struct {
	time_t	date;		/* Seconds since 01/01/1970	*/
	BYTE	function;	/* TTY function number		*/
	WORD	retcode;	/* Return code of TTY function	*/
	WORD	nlog;		/* handle number of TTY channel	*/
	WORD	maxlength;	/* maximum length of user buffer */
	WORD	uselength;	/* length of next bytes		*/
} TRACE_BIN;
#pragma	pack()

/* Prototypage des fonctions :
 *	- avec typage des arguments
 *	- et sans typage
 */
#ifdef LINT_ARGS
	VOID FAR PTR InitRelais(VOID);
static	VOID FAR banniere(VOID);
static	VOID FAR cloture(VOID);
static  BOOL VerifProtect(VOID);
extern	VOID rt_error(WORD);

static	WORD FAR ttyopen(WORD FAR PTR,BYTE FAR PTR);
static	WORD FAR ttyclose(WORD);
static	WORD FAR ttyconnect(WORD,BYTE FAR PTR);
static	WORD FAR ttydcn(WORD);
static	WORD FAR ttywrite(WORD,BYTE,BYTE FAR PTR);
static	WORD FAR ttyread(WORD,BYTE FAR PTR);
static	WORD FAR ttybreak(WORD);
static  WORD FAR ttybuffer(WORD,WORD);

static	WORD bcd2word(BYTE FAR PTR,WORD);
static	WORD initvoie(DVOIE PTR);

static  WORD Aread(WORD,BYTE PTR);
static  WORD LLread(WORD,BYTE PTR);
static	SWORD exclusif(BYTE FAR PTR);
static	WORD dolock(WORD,BYTE FAR PTR);
static	VOID unlock(WORD,BYTE FAR PTR);

extern	int Access(char *,int,int);
extern	void PurgeLox(void);
extern	void liberlox(char *);

#ifdef FCT_ENTETE
WORD _ttyopen(VOID PTR []);
WORD _ttyclose(VOID PTR []);
WORD _ttyconnect(VOID PTR []);
WORD _ttydcn(VOID PTR []);
WORD _ttywrite(VOID PTR []);
WORD _ttyread(VOID PTR []);
WORD _ttybreak(VOID PTR []);
WORD _ttybuffer(VOID PTR []);
#endif /* FCT_ENTETE */

#else  /* LINT_ARGS */

VOID  FAR PTR InitRelais();
static	VOID FAR banniere();
static	VOID FAR cloture();
static  BOOL VerifProtect();
extern	VOID rt_error();

static	WORD FAR ttyopen();
static	WORD FAR ttyclose();
static	WORD FAR ttyconnect();
static	WORD FAR ttydcn();
static	WORD FAR ttywrite();
static	WORD FAR ttyread();
static	WORD FAR ttybreak();
static  WORD FAR ttybuffer();

static	WORD bcd2word();
static	WORD initvoie();

static  WORD Aread();
static  WORD LLread();
static	SWORD exclusif();
static	WORD dolock();
static	VOID unlock();

extern	int Access();
extern	void PurgeLox();
extern	void liberlox();

#ifdef FCT_ENTETE
WORD _ttyopen();
WORD _ttyclose();
WORD _ttyconnect();
WORD _ttydcn();
WORD _ttywrite();
WORD _ttyread();
WORD _ttybreak();
WORD _ttybuffer();
#endif /* FCT_ENTETE */

#endif /* LINT_ARGS */


/* Definitions liees a la protection anti-copie pirate */

#define 	MAXPATH		128		/* lgr maxi chemin d'acces */
#define 	MAXFILE		14		/* lgr maxi nom de fichier */

/*                       0	  1         2         3         4         5         6         7         8         9         0         1         2                    142*/
#define	CONTROLFORM "/**/123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901\0\0\0\0\0\0\0\0\0                                /**/"

#define		CONTROLPATH	4
#define		CONTROLNODE	(MAXPATH+MAXFILE+8)
#define		CONTROLUNIT	(MAXPATH+MAXFILE+4)

static BYTE ControlZone[] = CONTROLFORM;


/* Definitions pour la mise au point */

BOOL ModeDebug;

/* ----- Fin de fichier ----- */


