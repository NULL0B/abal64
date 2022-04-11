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
#ifdef AIX_VERS
#ifndef UNIXWARE
#endif /* AIX_VERS */
VOID  * strcpy(); /* VOID  * , VOID  * */
VOID  * memcpy(); /* VOID  * , VOID  * */
#ifdef AIX_VERS
#endif
#endif /* AIX_VERS */
VOID  * strcat(); /* VOID  * , VOID  * */

#ifndef AIX_VERS
VOID  * malloc(); /* unsigned short int */
VOID  * strcpy(); /* VOID  * , VOID  * */
VOID  * memcpy(); /* VOID  * , VOID  * */
VOID  * strcat(); /* VOID  * , VOID  * */
#endif /* AIX_VERS */
#else
VOID  * malloc( unsigned short int );
VOID  * strcpy( VOID  * , VOID  * );
VOID  * memcpy( VOID  * , VOID  * , EXAWORD );
VOID  * strcat( VOID  * , VOID  * );

#ifndef AIX_VERS
VOID  * malloc( unsigned short int );
VOID  * strcpy( VOID  * , VOID  * );
VOID  * memcpy( VOID  * , VOID  * , EXAWORD );
VOID  * strcat( VOID  * , VOID  * );
#endif /* AIX_VERS */
#endif
#endif
#endif	/* MEMORYH */
	/* ------- */
