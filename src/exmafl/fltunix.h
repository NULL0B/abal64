/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1996
 *	Module  : EXA
 *	Fichier : FLTUNIX.H
 *	Version : 1.1b
 *	Date    : 29/03/96
 *	Systeme : Unix
 *
 *	Methodes d'acces
 *
 *	[DLL acces direct + sequentiel - Definitions privees]
 *
 */

#ifndef __FLTUNIX_H__
#define __FLTUNIX_H__

/* Inclusions importees */
#ifdef	VERSION666
#ifdef	AIX_VERS
#define	_LARGE_FILES
#define	_LARGE_FILE_API
#endif
#endif


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#if !defined(AVIION) && !defined(UNIXWARE) && !defined(LINUX) && !defined(RT_AIX) && !defined(HPUX)
#include <sys/locking.h>
#endif
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			QUELQUES DEFINITIONS				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#define	LMAXF		270		/* lgr maxi d'un nom de fichier */


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		QUELQUES DEFINITIONS DE TYPES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#define ErrorConv(a)	ErrorConvBib(a)
#define DOSUNIX
#define WIN32_UNIX

typedef signed char		S8;		/* 8 bit signed */
typedef unsigned char		U8;		/* 8 bit unsigned */
typedef signed short		S16;		/* 16 bit signed */
typedef unsigned short		U16;		/* 16 bit unsigned */
typedef signed long		S32;		/* 32 bit signed */
typedef unsigned long		U32;		/* 32 bit unsigned */
typedef char *			CPTR;
typedef	unsigned char * 	BPTR;
typedef S16 *			S16PTR;
typedef U8 *			U8PTR;
typedef S8 *			S8PTR;
typedef U16 *			U16PTR;
typedef U32 *			U32PTR;
typedef long			LONG;
typedef LONG *			LPLONG;
typedef int *			LPINT;
typedef char  *        		LPSTR;
typedef unsigned long		DWORD;
#ifdef	VERSION666
typedef unsigned long long	LSEEKTYPE;
#else
typedef unsigned long		LSEEKTYPE;
#endif

#define	SPTR		 *
#define HNLOG		int
#define HNLOG_ERROR	((HNLOG)-1)
#define WINAPI
#define FARPROC		LPLONG
#define FAR
#define PASCAL
#define BYTE		U8

#endif /* __FLTUNIX_H__ */

