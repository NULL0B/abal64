/*----------------------------------------------------------------------*/
/*									*/
/*		---------------------------------------			*/
/*		  Copyright (c) 1989,1990 Amenesik / Sologic s.a.			*/
/*		---------------------------------------			*/
/*		Project		:	ABAL MAKE			*/
/*		Module		:	UTDEF.H				*/
/*		Version		:	1.4b				*/
/*		Date		:	15/11/1991			*/
/*		---------------------------------------			*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	_UTDEF_H
#define	_UTDEF_H

/*
 *	Redefinitions for Medium/Large Model Amenesik / Sologic and DOS
 *	-----------------------------------------------------
 *
 */

#ifdef	VERSION666
#define __USE_LARGEFILE64
#define	__USE_FILE_OFFSET64
#endif

#ifdef	VMS
#define	UNIX
#endif

#ifndef	UNIX

#define	calloc( arg1 ) Mcalloc( arg1 )
#define	strlen( arg1 ) Mstrlen( arg1 )
#define	memcpy( arg1 ,arg2 ,arg3 ) Mmemcpy( arg1 ,arg2 ,arg3 )
#define	strcpy( arg1 ,arg2 ) Mstrcpy( arg1 ,arg2 )
#define	strcat( arg1 ,arg2 ) Mstrcat( arg1 ,arg2 )
#define	system( arg1 ) systeme( arg1 )

#ifdef	DOS
#define	SEEK_SET 0
#define	lseek(arg1,arg2,arg3) Mlseek(arg1,arg2,arg3)
#define	read(arg1,arg2,arg3)  Mread(arg1,arg2,arg3)
#endif

#define DEPEND_FIELD_SEP ' '

#endif

#ifdef	UNIX
#ifndef	VMS
#define DEPEND_FIELD_SEP ' '
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#else	/* VMS */
#define DEPEND_FIELD_SEP ','
#include <types.h>
#include <stat.h>
#endif
#endif

/*
 *	Standard type definitions
 *	-------------------------
 *
 */

#ifdef	VMS
#define CHEMINSEP '['
#endif
#ifdef	UNIX
#define	CHEMINSEP '/'
#endif
#ifdef	DOS
#define CHEMINSEP '\\'
#endif
#ifdef	PRL
#define	CHEMINSEP '\\'
#endif

#ifdef	DOS
BPTR	Mgetenv(BPTR);
#endif

#ifdef	UNIX
#ifndef	SEEK_SET
#define	SEEK_SET 0
#endif
#endif
EXTERN	int	Access();
EXTERN	void	liberlox();
EXTERN	void	PurgeLox();
#ifdef	VMS
#define	EXIT_VALUE 1
#else
#define	EXIT_VALUE 0
#endif

#ifndef PRL
#ifndef DOS
#include <errno.h>
#endif
#endif

#ifndef VMS
#ifndef UNIX
EXTERN INT errno;
#endif
#endif


#ifndef UNIX
#define OPTION_FLAG_1 '-'
#define OPTION_FLAG_2 '/'
#else
#ifdef	VMS
#define OPTION_FLAG_1 '-'
#define OPTION_FLAG_2 '/'
#else
#define OPTION_FLAG_1 '-'
#define OPTION_FLAG_2 '-'
#endif
#endif

#ifdef	UNIX
WORD	fn_parser();
#else
WORD 	fn_parser( BPTR , BPTR , WORD );
#endif



#endif	/* _UTDEF_H */
	/* -------- */

