/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1991, 1992 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	MEMORY.H				*/
/*		Version :	1.1a					*/
/*		Date	:	20/08/1992				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef MEMORYH
#define MEMORYH

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include "aplus.h"		/* Include standard definitions		*/

#ifdef	ABAL_EXA
#ifndef	ABAL_OTR
#define	REDEFINE_MEMORY
#else
#ifdef	REDEFINE_MEMORY
#undef	REDEFINE_MEMORY
#endif
#endif
#else
#ifdef	REDEFINE_MEMORY
#undef	REDEFINE_MEMORY
#endif
#endif

#ifdef	REDEFINE_MEMORY
#include "exrdef.h"
#else
#ifndef CHECK_PROTO_ARGS
VOID  * malloc(); /* unsigned short int */
VOID  * strcpy(); /* VOID  * , VOID  * */
VOID  * memcpy(); /* VOID  * , VOID  * */
VOID  * strcat(); /* VOID  * , VOID  * */

VOID  * malloc(); /* unsigned short int */
VOID  * strcpy(); /* VOID  * , VOID  * */
VOID  * memcpy(); /* VOID  * , VOID  * */
VOID  * strcat(); /* VOID  * , VOID  * */
#else
VOID  * malloc( unsigned short int );
const char  * strcpy( const char  * , const char  * );
VOID  * memcpy( VOID  * , VOID  * , WORD );
const char  * strcat( const char  * , const char  * );

VOID  * malloc( unsigned short int );
const char  * strcpy( const char  * , const char  * );
VOID  * memcpy( VOID  * , VOID  * , WORD );
const char  * strcat( const char  * , const char  * );
#endif
#endif
#endif	/* MEMORYH */
	/* ------- */
