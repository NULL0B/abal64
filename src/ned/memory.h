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
VOID  * strcpy( VOID  * , VOID  * );
VOID  * memcpy( VOID  * , VOID  * , WORD );
VOID  * strcat( VOID  * , VOID  * );

VOID  * malloc( unsigned short int );
VOID  * strcpy( VOID  * , VOID  * );
VOID  * memcpy( VOID  * , VOID  * , WORD );
VOID  * strcat( VOID  * , VOID  * );
#endif
#endif	/* MEMORYH */
	/* ------- */
