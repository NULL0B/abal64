/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1991
 *	Module  : TTY
 *	Fichier : UTTY.H
 *	Version : 1.2a
 *	Date    : 06/04/92
 *	Systeme : UNIX
 *
 *	Procedure TTY sous UNIX
 *
 *	[Definitions de la bibliotheque dynamique]
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
#define		LSTANDARD	512		/* lgr par defaut tampon anticipation */
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


/* Definitions des structures de donnees de la bibliotheque */

struct SHM {
	WORD pdebut;
	WORD pfin;
	WORD erreur;
	WORD echec;
	BYTE tampon[MAXTAMPON];
};

typedef struct {
	BOOL	attach;		/* indicateur d'utilisation du numero logique */
	int	handle;		/* handle associe au device */
	BYTE PTR device;	/* nom du device */
	BOOL	connex;		/* indicateur de connexion */
	BOOL	reserve;	/* indicateur de reservation */
	BOOL	open;		/* indicateur d'ouverture */
	WORD	vitesse;	/* vitesse de transmission */
	WORD	nbits;		/* nombre de bits par caractere */
	WORD	oparite;	/* indicateur de presence de parite en sortie */
	WORD	iparite;	/* indicateur de presence de parite en entree */
	WORD	typeparite;	/* type de parite */
	WORD	nstops;		/* nombre de bits stop */
	BYTE	finenr;		/* caractere de fin d'enregistrement */
	BYTE	finfich;	/* caractere de fin de fichier */
	WORD	timeout;	/* time-out de reception */
	BOOL	transp;		/* indicateur de mode tranparent */
	BOOL	duplex;		/* indicateur de mode duplex */
	WORD	modem;		/* indicateur de gestion des signaux modems */
	BOOL	sigmodem;	/* indicateur deconnexion du modem */
	BOOL	sigint;		/* indicateur reception d'un break */
	int	journal;	/* handle du fichier journal associe */
	BOOL	anticipation;	/* indicateur gestion tampon d'anticipation */
	WORD	ltampon;	/* longueur du tampon d'anticipation */
	int	child;		/* numero processus fils */
	int	father;		/* numero processus pere */
	int	shmid;		/* identificateur segment memoire partagee */
	int	semid;		/* identificateur semaphore */
	struct SHM PTR shm;	/* pointeur segment memoire partagee */
	struct sembuf psem;	/* manipulation des semaphores */
} DVOIE;


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
static  WORD FAR ttyconfig(WORD,WORD);
static	WORD FAR ttyselmode(WORD,BYTE);

static	WORD bcd2word(BYTE FAR PTR,WORD);
static	WORD initvoie(DVOIE PTR);
//OLD TRACEstatic	VOID FAR mess_time(WORD,BYTE PTR);
//OLD TRACEstatic	VOID FAR mess(WORD,BYTE PTR);

static	VOID Catchsighup0(VOID);
static	VOID Catchsighup1(VOID);
static	VOID Catchsighup2(VOID);
static	VOID Catchsighup3(VOID);
static	VOID Catchsighup4(VOID);
static	VOID Catchsighup5(VOID);
static	VOID Catchsighup6(VOID);
static	VOID Catchsighup7(VOID);
static	VOID Catchsighup8(VOID);
static	VOID Catchsighup9(VOID);
static	VOID Catchsigint0(VOID);
static	VOID Catchsigint1(VOID);
static	VOID Catchsigint2(VOID);
static	VOID Catchsigint3(VOID);
static	VOID Catchsigint4(VOID);
static	VOID Catchsigint5(VOID);
static	VOID Catchsigint6(VOID);
static	VOID Catchsigint7(VOID);
static	VOID Catchsigint8(VOID);
static	VOID Catchsigint9(VOID);

static	VOID Catchsighup(WORD);
static	VOID Catchsigint(WORD);
static	WORD Pcreat(WORD);
static	VOID fathersigusr2(VOID);
static	VOID fathersigusr1(VOID);
static	VOID childsigusr1(VOID);
static	VOID alimente(WORD);
static	WORD Pdelete(WORD);
static	WORD getsem(WORD);
static	WORD relsem(WORD);
static  WORD Aread(WORD,BYTE PTR);
static  WORD LLread(WORD,BYTE PTR);
static  WORD LLAread(WORD,BYTE PTR);

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
WORD _ttyconfig(VOID PTR []);
WORD _ttyselmode(VOID PTR []);
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
static  WORD FAR ttyconfig();
static	WORD FAR ttyselmode();

static	WORD bcd2word();
static	WORD initvoie();
//OLD TRACEstatic	VOID FAR mess_time();
//OLD TRACEstatic	VOID FAR mess();

static	VOID Catchsighup0();
static	VOID Catchsighup1();
static	VOID Catchsighup2();
static	VOID Catchsighup3();
static	VOID Catchsighup4();
static	VOID Catchsighup5();
static	VOID Catchsighup6();
static	VOID Catchsighup7();
static	VOID Catchsighup8();
static	VOID Catchsighup9();
static	VOID Catchsigint0();
static	VOID Catchsigint1();
static	VOID Catchsigint2();
static	VOID Catchsigint3();
static	VOID Catchsigint4();
static	VOID Catchsigint5();
static	VOID Catchsigint6();
static	VOID Catchsigint7();
static	VOID Catchsigint8();
static	VOID Catchsigint9();

static	VOID Catchsighup();
static	VOID Catchsigint();
static	WORD Pcreat();
static	VOID fathersigusr2();
static	VOID fathersigusr1();
static	VOID childsigusr1();
static	VOID alimente();
static	WORD Pdelete();
static	WORD getsem();
static	WORD relsem();
static  WORD Aread();
static  WORD LLread();
static  WORD LLAread();

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
WORD _ttyconfig();
WORD _ttyselmode();
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

