#ifndef	_TRMALLOC_H
#define	_TRMALLOC_H

#ifndef	UNIX

#ifdef	__QUALITY
VPTR	zalloc( WORD );
VOID	free( VPTR );
VPTR	QC_Alloc( WORD );
VOID	QC_Free( VPTR );
#define	allocate( n ) QC_Alloc(n)
#define	liberate( p ) QC_Free( p )
#else	/* __QUALITY */
#ifdef	WIN32
#include <malloc.h>
#define	allocate( n ) malloc( n )
#define	liberate( p ) free( p )	
#else	/* WIN32 */
VPTR	zalloc( WORD );
VOID	free( VPTR );
#define	allocate( n ) zalloc( n )
#define	liberate( p ) free( p )	
#endif
#endif

#else	/* UNIX */

#ifdef	__QUALITY
VPTR	QC_Alloc( WORD );
VOID	QC_Free( VPTR );
#define	allocate( n ) QC_Alloc(n)
#define	liberate( p ) QC_Free( p )
#else	/* __QUALITY */
#define	ALSMID "otr"
#include "allocate.h"
/*
void * malloc(int);
void   free(void *);
#define	allocate( n ) malloc(n)
#define	liberate( p ) free( p )
*/
#endif

#endif	/* UNIX */

#endif	/* _TRMALLOC_H */
	/* ----------- */

