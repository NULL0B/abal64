/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1995
 *	Module  : EXA
 *	Fichier : EXMTUNIX.H
 *	Version : 1.1b
 *	Date    : 02/05/95
 *	Systeme : UNIX
 *
 *	Executeur ABAL
 *
 *	[Interface methodes d'acces - Definitions des types]
 *
 */

#ifndef __EXMTUNIX_H__
#define __EXMTUNIX_H__

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		QUELQUES DEFINITIONS DE TYPES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

typedef unsigned char		BYTE;
typedef unsigned long		LONG;

#ifdef	VERSION666
typedef unsigned long		WORD;
typedef unsigned long		DWORD;
typedef unsigned long long	LSEEKTYPE;	/* Abal 3 uses open64 and lseek64 for files > 2Go */
#else
typedef unsigned short		WORD;
typedef unsigned long		DWORD;
typedef unsigned long		LSEEKTYPE;
#endif
typedef int *			LPINT;
typedef BYTE *			LPBYTE;
typedef char *			LPSTR;
typedef LONG *			LPLONG;
typedef DWORD			EX_FILE_HANDLE;
typedef	unsigned char *		BPTR;
typedef	char *			CPTR;

typedef	WORD *			WPTR;

#define SPTR 		*
#define FARPROC		LPLONG
#define FAR
#define NOTFASTCALL
#define EXTERN		extern

#endif /* __EXMTUNIX_H__ */

