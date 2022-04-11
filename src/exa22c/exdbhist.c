/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXWORK.H  				*/
/*		Date 	:	12/11/1992				*/
/*		Version :	1.4c / 2.1a				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef _EXDBHIST_C
#define	_EXDBHIST_C

#include "allocate.h"

#define	HISTPTR	struct exadb_command_history XPTR

struct	exadb_command_history {
	HISTPTR	prev;
	HISTPTR	next;
	BPTR	value;
	};

HISTPTR	RootHist;
HISTPTR	LastHist;
HISTPTR	ThisHist;

#include "exdbstd.c"

VOID	initialise_history()
{
	RootHist = LastHist = ThisHist = (HISTPTR) 0;
	return;
}

VOID	liberate_history()
{
	HISTPTR	lhist;
	while ((lhist = RootHist) != (HISTPTR) 0) {
		RootHist = lhist->next;
		liberate( lhist->value );
		liberate( lhist );
		}
	return;
}

EXAWORD	history_compare( aptr, bptr )
BPTR	aptr;
BPTR	bptr;
{
	while (( *aptr ) && ( *bptr ))
		if ( *(aptr++) != *(bptr++) )
			return( 0 );

	if ( *aptr != *bptr )
		return( 0 );
	else	return( 1 );
}

EXAWORD	is_already_history( cmdptr )
BPTR	cmdptr;
{
	HISTPTR	hptr;

	if ((hptr = LastHist) != (HISTPTR) 0) {
		do	{
			if ( history_compare( hptr->value, cmdptr ) )
				return( 1 );	 
			}
		while ((hptr = hptr->prev) != (HISTPTR) 0);
		}
	return( 0 );
}

VOID	put_history( cmdptr )
BPTR	cmdptr;
{
	HISTPTR	lhist;

	ThisHist = (HISTPTR) 0;

	if ( is_already_history( cmdptr ) )
		return;
	if ((lhist = (HISTPTR) allocate( sizeof( struct exadb_command_history ))) != (HISTPTR) 0) {
		if ((lhist->value = (BPTR) allocate( exadb_strlen( cmdptr ) + 1 )) != (BPTR) 0) {
			exadb_strcpy( lhist->value, cmdptr );
			if ((lhist->prev = LastHist) != (HISTPTR) 0)
				LastHist->next = lhist;
			LastHist = lhist;
			if ( RootHist == (HISTPTR) 0)
				RootHist = lhist;
			lhist->next = (HISTPTR) 0;
			}
		else	liberate( lhist );
		}
	return;
}

BPTR	get_history()
{
	if ((ThisHist = LastHist) == (HISTPTR) 0 )
		return( (BPTR) 0 );
	else	return( (BPTR) ThisHist->value );
}

BPTR	previous_history()
{
	if (( ThisHist == (HISTPTR) 0 )
	|| ((ThisHist = ThisHist->prev) == (HISTPTR) 0))
		ThisHist = LastHist;

	if (ThisHist == (HISTPTR) 0 )
		return( (BPTR) 0 );
	else	return( (BPTR) ThisHist->value );
}

BPTR	next_history()
{
	if (( ThisHist == (HISTPTR) 0 )
	|| ((ThisHist = ThisHist->next) == (HISTPTR) 0))
		ThisHist = RootHist;

	if (ThisHist == (HISTPTR) 0 )
		return( (BPTR) 0 );
	else	return( (BPTR) ThisHist->value );

}


#endif
