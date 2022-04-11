/*
 *	Projet  : Visual ABAL++		Copyright Amenesik / Sologic   (c) 1995
 *	Module  : ALM
 *	Fichier : ALM.H
 *	Version : 2.2a
 *	Date    : 03/07/95
 *	Systeme : Amenesik / Sologic / Windows 3 / NT / MS-DOS / Unix
 *
 *	Interface bibliotheques dynamiques Abal++
 *
 *	[Library Manager - Definitions de types]
 *
 *	Relies upon stdtypes.h : modified for ALM users.
 */

#ifndef	_ALM_H
#define	_ALM_H

#ifdef PROLOGUE
#define PIDT	unsigned short
#define SHMREF	void far *
#define PASCAL
#define PUBAPI	far
#endif

#ifdef UNIX
#define PIDT	int
#define SHMREF	int
#define PASCAL
#define PUBAPI
#endif

#ifdef DOS
#define PIDT	unsigned short
#define SHMREF	void far *
#define PASCAL	pascal
#define PUBAPI	far pascal
#endif

#ifdef WIN16
#define PIDT	unsigned short
#define SHMREF	void far *
#define PASCAL	pascal
#define PUBAPI	far pascal
#endif

#ifdef WIN32
#define PIDT	unsigned long
#define SHMREF	unsigned long
#define PASCAL	pascal
#define PUBAPI	far pascal
#endif

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DEFINITIONS DES TYPES SUBSTITUES		     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#define	ALM_ERROR		WORD
#define	ALM_ERRORPTR		ALM_ERROR XPTR
#define	ALM_HANDLE		WORD
#define	ALM_DESCR		WORD
#define	ALM_PID			WORD
#define	ALM_IDENTITYPTR		ALM_IDENTITY XPTR

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DEFINITION DES CONSTANTES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#define MAX_FONCTION	255
#define MAX_ARGUMENT	20
#define ALM_NAME	255


/* Types des donnees manipulees */

#define TYPE_DIESE		0x00
#define TYPE_POURCENT		0x01
#define TYPE_BCD		0x02
#define TYPE_CHAINE		0x03
#define TYPE_WORD		0x09
#define TYPE			0x0f
#define MODIFIABLE		0x80


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DEFINITION DES TYPES STRUCTURES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* Description des arguments d'appel d'une fonction */

struct _alm_arg_st {
	WORD c; 			/* nombre d'arguments */
	VPTR XPTR v;			/* adresse des arguments */
	BPTR t;				/* type des arguments */
	WPTR l;				/* taille des arguments */
	BYTE cpl[32];
};
typedef struct _alm_arg_st ALM_ARG;


/* Identite du process demandant une (de)connexion */

struct _alm_identity_st {
	PIDT pid;			/* id processus demandeur */
	PIDT ppid;			/* id pere du processus demandeur */
};
typedef struct _alm_identity_st ALM_IDENTITY;

struct _alm_init_st {
	WORD signature;			/* signature de la bibliotheque */
	WORD numero;			/* numero alloue */
	BYTE cpl[64];
};
typedef struct _alm_init_st ALM_INIT;

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			PROTOTYPES PRIMITIVES PUBLIQUES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifndef	UNIX
ALM_ERROR 	PUBAPI ALM_initiate( ALM_IDENTITYPTR );
ALM_HANDLE 	PUBAPI ALM_declare( BPTR, ALM_HANDLE, WORD, ALM_ERRORPTR );
ALM_HANDLE 	PUBAPI ALM_new( BPTR, ALM_ERRORPTR );
ALM_HANDLE 	PUBAPI ALM_sharename( BPTR, ALM_ERRORPTR );
ALM_HANDLE 	PUBAPI ALM_sharehandle( ALM_HANDLE, ALM_ERRORPTR );
ALM_HANDLE 	PUBAPI ALM_overload( BPTR, ALM_HANDLE, ALM_ERRORPTR );
ALM_ERROR 	PUBAPI ALM_load( ALM_HANDLE, ALM_INIT XPTR, WORD );
ALM_ERROR 	PUBAPI ALM_use( ALM_HANDLE, WORD, WORD, BPTR, VPTR XPTR,
				WPTR, WPTR , ALM_ERROR (XPTR)());
ALM_ERROR 	PUBAPI ALM_drop( ALM_HANDLE );
ALM_ERROR 	PUBAPI ALM_forget( ALM_HANDLE );
ALM_ERROR 	PUBAPI ALM_remove( ALM_HANDLE, ALM_HANDLE );
ALM_ERROR 	PUBAPI ALM_terminate( ALM_IDENTITYPTR );
PIDT		PUBAPI ALM_getpid(void);
PIDT		PUBAPI ALM_getppid(void);
ALM_ERROR 	PUBAPI ALM_whoamI(PIDT XPTR , SHMREF XPTR , ALM_HANDLE XPTR);
#else
ALM_ERROR 	PUBAPI ALM_initiate();
ALM_HANDLE 	PUBAPI ALM_declare();
ALM_HANDLE 	PUBAPI ALM_new();
ALM_HANDLE 	PUBAPI ALM_sharename();
ALM_HANDLE 	PUBAPI ALM_sharehandle();
ALM_HANDLE 	PUBAPI ALM_overload();
ALM_ERROR 	PUBAPI ALM_load();
ALM_ERROR 	PUBAPI ALM_use();
ALM_ERROR 	PUBAPI ALM_drop();
ALM_ERROR 	PUBAPI ALM_forget();
ALM_ERROR 	PUBAPI ALM_remove();
ALM_ERROR 	PUBAPI ALM_terminate();
PIDT		PUBAPI ALM_getpid();
PIDT		PUBAPI ALM_getppid();
ALM_ERROR 	PUBAPI ALM_whoamI();
#endif	/* UNIX */

#endif	/* _ALM_H */
	/* ------ */

