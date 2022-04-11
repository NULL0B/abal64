/*----------------------------------------------------------------------*/
/*									*/
/*		---------------------------------------			*/
/*		  Copyright (c) 1989,1991 Amenesik / Sologic s.a.			*/
/*		---------------------------------------			*/
/*		Project		:	ABAL MAKE			*/
/*		Module		:	UTALLOC.C			*/
/*		Version		:	1.4b				*/
/*		Date		:	15/11/1991			*/
/*		---------------------------------------			*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_UTALLOC_C
#define	_UTALLOC_C

#include "stdtypes.h"
#include "amake.h"

#define MEMTREE struct Memory XPTR

#define	malloc(arg1) Mmalloc(arg1)
#define	free(arg1)   Mfree(arg1)

EXTERN	WORD	Debug;

VPTR	Mmalloc( WORD );
VOID	Mfree( VPTR );

struct Memory {
	BPTR	page;
	WORD	next;
	WORD	compte;
	MEMTREE suite;
	};

MEMTREE	Ballock;
MEMTREE	Wallock;
WORD	PushGod;
WORD	PageSize;

WORD	page_allocation(nb)
WORD	nb;
{
	MEMTREE	membase;
	if ((membase = (MEMTREE) malloc ( sizeof(struct Memory) )) != (MEMTREE) 0 ) {
		if ((membase->page = (BPTR) malloc ( nb )) != (BPTR) 0) {
			membase->next   = 0;
			membase->compte = 0;
			membase->suite  = Ballock;
			Ballock = membase;
#ifdef DEBUG_QALLOC
			if ( Debug != 0 ) {
				llmf_co('+');
				}
#endif
			return( 0 );
			}
		free ( (BPTR) membase );
		}
	return( -1 );
}

VOID	PushMall()
{
	Wallock = Ballock;
	return;
}

VOID	PopMall()
{
	Ballock = Wallock;
	return;
}

WORD	Mallinit( nb )
WORD	nb;
{
#ifdef DEBUG_QALLOC
	if ( Debug != 0 ) {
		llmf_co('(');
		}
#endif
	PageSize = nb;
	Ballock  = (MEMTREE) 0;
	return ( page_allocation( PageSize ) );

}

VOID	LiberMall( BasePtr )
MEMTREE	BasePtr;
{
	if ( BasePtr != (MEMTREE) 0 ) {
#ifdef DEBUG_QALLOC
		if ( Debug != 0 ) {
			llmf_co('-');
			}
#endif
		LiberMall(BasePtr->suite);
		if ( BasePtr->page != (BPTR) 0 ) {
			free ( BasePtr->page );
			}
		free ((BPTR) BasePtr);
		}
	return;
}

VOID	MallFree()
{

	LiberMall( Ballock );
#ifdef DEBUG_QALLOC
	if ( Debug != 0 ) {
		llmf_co(')');
		}
#endif
	return;
}

VPTR	Mallocks( nb )
WORD	nb;
{
	MEMTREE ltree;
	VPTR	lptr;

	/* Check for Bigger than Default Page Size */
	/* --------------------------------------- */
	if ( nb > PageSize ) {
		return ((VPTR) malloc ( nb ) );
		}
	
	ltree = Ballock;
	do 	{
		if (( PageSize - ltree->next ) > nb ) {
			lptr = (ltree->page + ltree->next);
			ltree->next += nb;
			ltree->compte++;
			return( (VPTR) lptr );
			}
		ltree = ltree->suite;
		}
	while ( ltree != (MEMTREE) 0 );

	if ( page_allocation( PageSize ) == -1 ) {
		return ( (VPTR) 0 );
		}
	lptr = Ballock->page;
	Ballock->next = nb;
	Ballock->compte++;
	return ((VPTR) lptr );

}

VOID	FreeBee( mptr )
VPTR	mptr;
{
	MEMTREE	ltree;
	ltree = Ballock;
	while ( ltree != (MEMTREE) 0 ) {
		if (Segment(mptr) == Segment(ltree->page)) {
			if ( ltree->compte > 0 ) {
				ltree->compte--;
				}
			if ( ltree->compte == 0 ) {
				ltree->next = 0;
				}
			return;
			}
		ltree = ltree->suite;
		}
	free ( mptr );
	return;
}
	
#endif	/* _UTALLOC_C */
	/* ---------- */


