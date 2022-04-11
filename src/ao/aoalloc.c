/*----------------------------------------------------------------------*/
/*									*/
/*		---------------------------------------			*/
/*		  Copyright (c) 1989,1994 Amenesik / Sologic s.a.			*/
/*		---------------------------------------			*/
/*		Project		:	ABAL MAKE			*/
/*		Module		:	AOALLOC.C			*/
/*		Version		:	2.1b				*/
/*		Date		:	11/05/1994			*/
/*		---------------------------------------			*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_AOALLOC_H
#define	_AOALLOC_H

#include "aomain.h"

#ifdef	UNIX
#define MEMTREE struct Memory *
#else
#define MEMTREE struct Memory far *
#endif

extern	EXAWORD	Debug;

struct Memory {
				/* ---------------------------- */
	BPTR	page;		/* Page Buffer 			*/
	EXAWORD	next;		/* Next free entry in page 	*/
	EXAWORD	compte;		/* number of page users		*/
	EXAWORD	limit;		/* Size limit of this page	*/
	MEMTREE suite;		/* Next memory control block	*/
				/* ---------------------------- */
	};

MEMTREE	Ballock;
MEMTREE	Wallock;
EXAWORD	PushGod;
EXAWORD	PageSize;

EXAWORD	allocate_for_memory_control(nb)
EXAWORD	nb;
{
	MEMTREE	membase;
	if ((membase = (MEMTREE) malloc ( sizeof(struct Memory) )) != (MEMTREE) 0 ) {
		if ((membase->page = (BPTR) malloc ( nb )) != (BPTR) 0) {
			membase->next   = 0;
			membase->compte = 0;
			membase->limit  = nb;
			membase->suite  = Ballock;
			Ballock = membase;
			return( 0 );
			}
		free ( (BPTR) membase );
		}
	return( -1 );
}

void	PushMall()
{
	Wallock = Ballock;
	return;
}

void	PopMall()
{
	Ballock = Wallock;
	return;
}

EXAWORD	Mallinit( nb )
EXAWORD	nb;
{
	PageSize = nb;
	Ballock  = (MEMTREE) 0;
	return ( allocate_for_memory_control( PageSize ) );

}

void	LiberMall( BasePtr )
MEMTREE	BasePtr;
{
	if ( BasePtr != (MEMTREE) 0 ) {
		LiberMall(BasePtr->suite);
		if ( BasePtr->page != (BPTR) 0 ) {
			free ( BasePtr->page );
			}
		free ((BPTR) BasePtr);
		}
	return;
}

void	MallFree()
{

	LiberMall( Ballock );
	return;
}

BPTR	Mallocks( nb )
EXAWORD	nb;
{
	MEMTREE ltree;
	BPTR	lptr;

	/* Check for Bigger than Default Page Size */
	/* --------------------------------------- */
	if ( nb > PageSize ) {
		return ((BPTR) malloc ( nb ) );
		}
	
	ltree = Ballock;
	do 	{
		if (( PageSize - ltree->next ) > nb ) {
			lptr = (ltree->page + ltree->next);
			ltree->next += nb;
			ltree->compte++;
			return( (BPTR) lptr );
			}
		ltree = ltree->suite;
		}
	while ( ltree != (MEMTREE) 0 );

	if ( allocate_for_memory_control( PageSize ) == -1 ) {
		return ( (BPTR) 0 );
		}
	lptr = Ballock->page;
	Ballock->next = nb;
	Ballock->compte++;
	return ((BPTR) lptr );

}

void	FreeBee( mptr )
BPTR	mptr;
{
	MEMTREE	ltree;
	ltree = Ballock;
	while ( ltree != (MEMTREE) 0 ) {
		if (( mptr >= ltree->page ) && ( mptr < (ltree->page + ltree->limit ))) {
#ifdef	MERDO
		if ( Segment( mptr ) == Segment( ltree->page ) ) {
#endif
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
	
#endif	/* _AOALLOC_H */
	/* ---------- */

