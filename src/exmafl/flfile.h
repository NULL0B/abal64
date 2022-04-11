/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1997
 *	Module  : EXA
 *	Fichier : FLFILE.H
 *	Version : 1.1c
 *	Date    : 14/04/97
 *	Systeme : Windows 3 / NT / MS-DOS / Unix
 *
 *	Methodes d'acces
 *
 *	[DLL acces direct + sequentiel - Definitions privees globales]
 *
 */

#ifndef __FLFILE_H__
#define __FLFILE_H__

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		QUELQUES DEFINITIONS ET INCLUSIONS			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* Inclusions des definitions de types dependant de l'OS */

#ifdef WIN16
#include "fltw16.h"
#endif
#ifdef WIN32
#include "fltw32.h"
#endif
#ifdef DOS
#include "fltdos.h"
#endif
#ifdef ISUNIX
#include "fltunix.h"
#endif
#ifdef NETWARE
/* Pb pour generation de FLFILE32.DLL => incllusion suivante mise en commentaire */
/*#include "flNetWar.h"*/
#endif

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			QUELQUES DEFINITIONS				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
#ifdef	CRIVER40
#define	CRIVER38
#endif

#ifdef	CRIVER38
#define	CRIVER37
#endif

#ifdef	CRIVER37
#define FL_COMPATIBLE	4			/* indice compatibilite API FLFILE */
#else
#define FL_COMPATIBLE	3 			/* indice compatibilite API FLFILE */
#endif
#define MAGICHANDLE	0xE231095EL		/* magic number */
#define MAXFILE 256				/* Nombre maximum de fichiers par session */ 
#define EHANDLESIZE	sizeof(EHANDLE)


/* Position du lock fichier */
#define LCK_58_STA	(U32)0x7C000001L	

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES TYPES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* Structure de description d'un entete de fichier sequentiel 	*/
/* encore du con ! et pourquoi pas les autres systemes aussi	*/
/* WIN32 ca eblouit l'esprit ( entre autre )	c'est grave	*/

/* #ifdef WIN32 */
#pragma pack(1)
/* #endif	*/

struct _sqform {
	U16		SQxx_rec;
	U16		SQsz_rec;		/* longueur enregistrement */
	U32		SQnb_rec;		/* nombre d'enregistrements */
	U32		SQrd_rec;		/* position de lecture */
	U32		SQwr_rec;		/* position d'ecriture */
};
typedef struct _sqform SQFORM;


/* Structure de description d'un fichier */

struct _filehandle {
	HNLOG 			OriginalHandle;		/* handle d'origine */
	CPTR			FileName;		/* ptr nom du fichier */
	U16			ExclAttr;		/* exclusif / partageable */
	U16			CopyAttr;		/* copie / securite */
	U32			MagicNumber;		/* pour la robustesse ! */
	SQFORM			sqform;			/* infos fichier sequentiel */
	struct _taskenviron SPTR Owner;			/* ptr environnement */
	U16			PosInOwnerFileTable;	/* position du handle dans la table de l'environnement 
							 * poids fort = ligne, poids faible = col
							 */ 
};

typedef struct _filehandle FILEHANDLE;
typedef FILEHANDLE SPTR EHANDLE;

/* Structure de description d'un environnement de travail */
struct _taskenviron {
	U32		TaskId;			/* identifiant de tache */
	U8		CurDir[LMAXF];		/* repertoire par defaut */
	FARPROC	lpABQT;				/* callback pour ABQT */

	/* Tableau de stockage des handles de fichiers ouverts : 
	 *   c'est un tableau a deux dimensions. contenant
	 *	 MAXFILE tables de MAXFILE handles de fichiers.
	 *   On gere ainsi jusqu'a MAXFILE*MAFILE-1 fichiers par Env.
	 */
	U8PTR	FileOwned[MAXFILE];
};
typedef struct _taskenviron TASKENVIRON;



/* Structure de description d'une signature de DLL */

struct _flconf {
	U8	version;		/* numero de version */
	U8	release;		/* numero de release */
	U8	indice;			/* indice de correction */
	U8	compatible;		/* indice de compatibilite */
	U16	dedicat;		/* cle pour dedicat */
	U32	IdPart1;		/* identifiant de tache */
	U32	IdPart2;		/* identifiant de tache (suite) */
	U32	hCnx;			/* handle de connexion */
	U8	EnAttendant[90];	/* reserve pour extensions */
	};
typedef struct _flconf FLCONF;

/* voir ci-dessus */
/*#ifdef WIN32*/
#pragma pack()
/*#endif*/

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		DESCRIPTION DE LA VERSION ACTUELLE			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#define FL_VERSION		'1'
#define FL_RELEASE		'1'
#define FL_INDICE		'd'
#define FL_PROVISOIRE		0
#define FL_DATE			"14/04/1997"
#ifdef WIN32
#define FL_LABEL		"Low level file access for 32 bits app"
#endif
#ifdef WIN16
#define FL_LABEL		"Low level file access for 16 bits app"
#endif
#ifdef DOS
#define FL_LABEL		"Low Level file access for DOS app"
#endif
#ifdef ISUNIX
#define FL_LABEL		"Low Level file access for UNIX app"
#endif
#ifdef NETWARE
#define FL_LABEL		"Low Level file access for NetWare app"
#endif


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DEFINITION DES MACROS				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#define FILE_OUT(x)	if ((U16)fl_xwrite(hBan,(CPTR)x,(U16)fl_xstrlen((CPTR)x)) != \
			       (U16)fl_xstrlen((CPTR)x)) return(1);
#define FILE_TAB(x)	{ S16 _ii; for (_ii = 0 ; _ii < (S16)x ; _ii++) { FILE_OUT("\011");} }


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES CONSTANTES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* Nombre maxi de taches simultanees */

#ifdef WIN32
#define MAX_TASK	256
#endif
#ifdef WIN16
#define MAX_TASK	32
#endif
#ifdef DOS
#define MAX_TASK	32
#endif
#ifdef ISUNIX
#define MAX_TASK	1			/* car linke a EXA */
#endif
#ifdef	NETWARE
#define MAX_TASK	256
#endif	/* NETWARE */


/* Codes fonctions des acces sequentiels */

#define	GET_SQFCB	1		/* Read SQ file control block	*/
#define	MAJ_SQFCB	2		/* Update SQ file control block	*/
#define	LCK_SQFCB	4		/* Reads and locks SQ F.C.B.	*/


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES DONNEES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* Inclusions dependant de l'OS */

#ifdef WIN16
#include "flw16.h"
#endif
#ifdef WIN32
#include "flw32.h"
#endif
#ifdef DOS
#include "fldos.h"
#endif
#ifdef ISUNIX
#include "flunix.h"
#endif


/* Donnees independantes de l'OS */

#ifndef ISUNIX
TASKENVIRON SPTR EnvTable[MAX_TASK];		/* table des environnements */
#else
static TASKENVIRON SPTR EnvTable[MAX_TASK] = {(TASKENVIRON SPTR) NULL};
#endif


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		DESCRIPTION DES PRIMITIVES	(LINT_ARGS)		     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifdef LINT_ARGS

/* Primitives privees */

static U16 CloseAllFiles(TASKENVIRON SPTR);
static U16 ConnectFileToEnviron(TASKENVIRON SPTR, EHANDLE);
static U16 DisconnectFileToEnviron(TASKENVIRON SPTR, EHANDLE);

static TASKENVIRON SPTR NewEnviron(void);
static void DropEnviron(TASKENVIRON SPTR);
static TASKENVIRON SPTR GetEnviron(void);
static void release_locks(EHANDLE);
static U16 sq_ctrl(TASKENVIRON SPTR, EHANDLE , U16 , SQFORM SPTR, S16PTR);
#ifndef ISUNIX
static S16 ErrorConv(S16);
#endif

#ifndef NETWARE
static S16 MakeCompleteName(TASKENVIRON SPTR, CPTR, CPTR);
static U16 AbalLock(EHANDLE ,LSEEKTYPE, U32);
static U16 AbalUnlock(EHANDLE ,LSEEKTYPE, U32);
#else /* NETWARE */
S16 MakeCompleteName(TASKENVIRON SPTR, CPTR, CPTR);
U16 AbalLock(EHANDLE ,LSEEKTYPE, U32);
U16 AbalUnlock(EHANDLE ,LSEEKTYPE, U32);
#endif

static void U32INVwrite(U32, U8PTR);
static U32 U32INVread(U8PTR);
static void U16INVwrite(U16, U8PTR);
static U16 U16INVread(U8PTR);


/* Primitives publiques */

int WINAPI FFbegin(FLCONF SPTR, FARPROC);
int WINAPI FFend(EHANDLE);
int WINAPI ModuleIdentification(LPSTR, int);
EHANDLE WINAPI FFopen(LPSTR , int , int , LPINT);
EHANDLE WINAPI FFcreate(LPSTR , int , int , LPINT);
int WINAPI FFclose(EHANDLE);
int WINAPI FFaccess(LPSTR , int);
int WINAPI FFunlink(LPSTR);
int WINAPI FFatbopen(EHANDLE , int , int);
int WINAPI FFread(EHANDLE , LSEEKTYPE , CPTR , int , LPINT);
int WINAPI FFwrite(EHANDLE , LSEEKTYPE , CPTR , int , LPINT);
int WINAPI FFextend(EHANDLE , U32);
int WINAPI FFrename(EHANDLE , LPSTR);
EHANDLE WINAPI SQopen(LPSTR , int , int , LPINT , LPINT);
EHANDLE WINAPI SQcreate(LPSTR , int , int , int , LPINT);
int WINAPI SQclose(EHANDLE);
int WINAPI SQunlink(LPSTR);
int WINAPI SQatbopen(EHANDLE , int , int);
int WINAPI SQread(EHANDLE , CPTR , int);
int WINAPI SQwrite(EHANDLE , CPTR , int);
int WINAPI SQmodif(EHANDLE , CPTR , int);
int WINAPI SQrewind(EHANDLE);
int WINAPI SQrename(EHANDLE , LPSTR);


#ifdef __DEBUG__

int WINAPI _FFbegin(FLCONF SPTR, FARPROC);
int WINAPI _FFend(EHANDLE);
int WINAPI _ModuleIdentification(LPSTR, int);
EHANDLE WINAPI _FFopen(LPSTR , int , int , LPINT);
EHANDLE WINAPI _FFcreate(LPSTR , int , int , LPINT);
int WINAPI _FFclose(EHANDLE);
int WINAPI _FFaccess(LPSTR , int);
int WINAPI _FFunlink(LPSTR);
int WINAPI _FFatbopen(EHANDLE , int , int);
int WINAPI _FFread(EHANDLE , LSEEKTYPE , CPTR , int , LPINT);
int WINAPI _FFwrite(EHANDLE , LSEEKTYPE , CPTR , int , LPINT);
int WINAPI _FFextend(EHANDLE , U32);
int WINAPI _FFrename(EHANDLE , LPSTR);
EHANDLE WINAPI _SQopen(LPSTR , int , int , LPINT , LPINT);
EHANDLE WINAPI _SQcreate(LPSTR , int , int , int , LPINT);
int WINAPI _SQclose(EHANDLE);
int WINAPI _SQunlink(LPSTR);
int WINAPI _SQatbopen(EHANDLE , int , int);
int WINAPI _SQread(EHANDLE , CPTR , int);
int WINAPI _SQwrite(EHANDLE , CPTR , int);
int WINAPI _SQmodif(EHANDLE , CPTR , int);
int WINAPI _SQrewind(EHANDLE);
int WINAPI _SQrename(EHANDLE , LPSTR);

static void ReqTraceBegin(void);
static void ReqTrace(CPTR);

#endif /* __DEBUG__ */

#else /* LINT_ARGS */


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		DESCRIPTION DES PRIMITIVES	(Sans LINT_ARGS)	     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* Primitives privees */
static U16 CloseAllFiles();
static U16 ConnectFileToEnviron();
static U16 DisconnectFileToEnviron();

static TASKENVIRON SPTR NewEnviron();
static void DropEnviron();
static TASKENVIRON SPTR GetEnviron();
static void release_locks();
static U16 sq_ctrl();
#ifndef ISUNIX
static S16 ErrorConv();
#endif
static S16 MakeCompleteName();
static U16 AbalLock();
static U16 AbalUnlock();
static void U32INVwrite();
static U32 U32INVread();
static void U16INVwrite();
static U16 U16INVread();


/* Primitives publiques */

int WINAPI FFbegin();
int WINAPI FFend();
int WINAPI ModuleIdentification();
EHANDLE WINAPI FFopen();
EHANDLE WINAPI FFcreate();
int WINAPI FFclose();
int WINAPI FFaccess();
int WINAPI FFunlink();
int WINAPI FFatbopen();
int WINAPI FFread();
int WINAPI FFwrite();
int WINAPI FFextend();
int WINAPI FFrename();
EHANDLE WINAPI SQopen();
EHANDLE WINAPI SQcreate();
int WINAPI SQclose();
int WINAPI SQunlink();
int WINAPI SQatbopen();
int WINAPI SQread();
int WINAPI SQwrite();
int WINAPI SQmodif();
int WINAPI SQrewind();
int WINAPI SQrename();

#ifdef __DEBUG__

int WINAPI _FFbegin();
int WINAPI _FFend();
int WINAPI _ModuleIdentification();
EHANDLE WINAPI _FFopen();
EHANDLE WINAPI _FFcreate();
int WINAPI _FFclose();
int WINAPI _FFaccess();
int WINAPI _FFunlink();
int WINAPI _FFatbopen();
int WINAPI _FFread();
int WINAPI _FFwrite();
int WINAPI _FFextend();
int WINAPI _FFrename();
EHANDLE WINAPI _SQopen();
EHANDLE WINAPI _SQcreate();
int WINAPI _SQclose();
int WINAPI _SQunlink();
int WINAPI _SQatbopen();
int WINAPI _SQread();
int WINAPI _SQwrite();
int WINAPI _SQmodif();
int WINAPI _SQrewind();
int WINAPI _SQrename();

static void ReqTraceBegin();
static void ReqTrace();

#endif /* __DEBUG__ */

#endif /* LINT_ARGS */

#endif /* __FLFILE_H__ */
