/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1991, 1992 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRACEMAN.C				*/
/*		Version :	1.1a					*/
/*		Date	:	13/10/1992				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRACEMAN_C
#define _TRACEMAN_C

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include "stdtypes.h"		/* Standardised type definitions	*/ 
#include "traceman.h"		/* Trace management decription header	*/
#include "memory.h"		/* Malloc / Free definitions		*/


/* 	----------------------------------	*/
/*	PRIVATE TRACE MANAGEMENT FUNCTIONS	*/
/* 	----------------------------------	*/

PRIVATE_SCOPE	void	reset_trace_item( iptr )
TRACEPTR	iptr;
{
	iptr->filename 	 = (BPTR) 0;
	iptr->colonne 	 = 0;
	iptr->ligne 	 = 0;	
	iptr->original 	 = 0;	
	iptr->type 	 = 0;	
	iptr->message 	 = (BPTR) 0;	
	iptr->previous 	 = (TRACEPTR) 0;	
	iptr->next 	 = (TRACEPTR) 0;	

	return;
}

PRIVATE_SCOPE	void	reset_trace_controller()
{
	TraceRoot = (TRACEPTR) 0;
	TraceItem = (TRACEPTR) 0;

	return;
} 

PRIVATE_SCOPE	WORD	valid_item( iptr )
TRACEPTR	iptr;
{
	if ( iptr->type & INVALID_ITEM )
		return( FAUX );
	else	return( VRAI );
}

PRIVATE_SCOPE	WORD	valid_type( iptr, selection )
TRACEPTR	iptr;
{
	if ( iptr->type & selection )
		return( VRAI );
	else	return( FAUX );
}

PRIVATE_SCOPE	WORD	valid_filename( iptr )
TRACEPTR	iptr;
{
	if ( zstrcmp( iptr->filename, TraceItem->filename ) == 0 )
		return( VRAI );
	else	return( FAUX );
}

WORD	add_trace_item( nfic, linid, colid, mptr )
BPTR	nfic;
int	linid;
int	colid;
BPTR	mptr;
{
	TRACEPTR	iptr;

	if (( iptr = (TRACEPTR) zalloc( sizeof( struct trace_control ) )) != (TRACEPTR) 0) {
		reset_trace_item( iptr );
		if (( iptr->filename = (BPTR) zalloc( strlen( nfic ) + 1)) != (BPTR) 0) {
			strcpy( iptr->filename, nfic );
			if (( iptr->message = (BPTR) zalloc( strlen( mptr ) + 1)) != (BPTR) 0) {
				strcpy( iptr->message, mptr );
				iptr->ligne 	= iptr->original = linid;
				iptr->colonne	= colid;
				iptr->type	= ANYTYPE;
				iptr->previous  = TraceItem;
				if ( TraceRoot == (TRACEPTR) 0 )
					TraceRoot = iptr ;
				if ( TraceItem != (TRACEPTR) 0 )
					TraceItem->next = iptr;
				TraceItem = iptr;
				return( 1 );
				}
			zfree( iptr->filename );
			}
		zfree( iptr );
		}
	return( 0 );

}

PRIVATE_SCOPE	WORD	load_items( handle )
FILEPTR	handle;
{
	WORD		nbf;
	WORD		nbi;
	unsigned int	nbl;
	unsigned int	nbc;
	BPTR		bptr;
	unsigned int	indent;
	BYTE		buffer[256];
	BYTE		nomfic[256];

	nbi = 0;
	while ((bptr = fgets( buffer, 256, handle )) != (BPTR) 0) {
		(void) sscanf( buffer, "%s %u %u %n ", nomfic, & nbl, & nbc, &indent );
		nbi += add_trace_item( nomfic, nbl, nbc, &buffer[indent] );
		}
	return( nbi );	
}


/* 	---------------------------------	*/
/*	PUBLIC TRACE MANAGEMENT FUNCTIONS	*/
/* 	---------------------------------	*/

PUBLIC_SCOPE	WORD	initialise_trace_controller( tracefile )
BPTR 	tracefile;
{
	FILEPTR	handle;
	WORD	items;

	items = 0;
	reset_trace_controller();
	if ((handle = (FILEPTR) fopen( tracefile, "r" )) != (FILEPTR) 0) {
		items = load_items( handle );
		TraceItem = TraceRoot;
		myfclose( handle );
		}
	return( items );
}

PUBLIC_SCOPE	VOID		terminate_trace_controller()
{
	TRACEPTR	iptr;
	while (( iptr = TraceRoot ) != (TRACEPTR) 0) {
		TraceRoot = TraceRoot->next;
		zfree( iptr );
		}
	reset_trace_controller(); 
	return;
}

PUBLIC_SCOPE	TRACEPTR	position_to_next( item_type )
WORD 	item_type;
{
	TRACEPTR	iptr;

	if ((  TraceItem != (TRACEPTR) 0 )
	&&  (( iptr = TraceItem->next) != (TRACEPTR) 0)) {
		do	{
			if (( valid_item    ( iptr )) 
			&&  ( valid_type    ( iptr, item_type )))
				return((TraceItem = iptr));
			iptr = iptr->next;
			}
		while ( iptr != (TRACEPTR) 0 );	
		}
	return( (TRACEPTR) 0 );
}

PUBLIC_SCOPE	TRACEPTR	position_to_previous( item_type )
WORD 	item_type;
{
	TRACEPTR	iptr;

	if ((  TraceItem != (TRACEPTR) 0 )
	&&  (( iptr = TraceItem->previous) != (TRACEPTR) 0)) {
		do	{
			if (( valid_item    ( iptr )) 
			&&  ( valid_type    ( iptr, item_type )))
				return((TraceItem = iptr));
			iptr = iptr->previous;
			}
		while ( iptr != (TRACEPTR) 0 );	
		}
	return( (TRACEPTR) 0 );
}

PUBLIC_SCOPE	TRACEPTR	position_to_first( item_type )
WORD 	item_type;
{
	TRACEPTR	iptr;

	if  (( iptr = TraceRoot) != (TRACEPTR) 0) {
		do	{
			if (( valid_item    ( iptr )) 
			&&  ( valid_type    ( iptr, item_type )))
				return((TraceItem = iptr));
			iptr = iptr->next;
			}
		while ( iptr != (TRACEPTR) 0 );	
		}
	return( (TRACEPTR) 0 );
}

PUBLIC_SCOPE	TRACEPTR	position_to_current( item_type )
WORD 	item_type;
{
	return( TraceItem ) ;
}

PUBLIC_SCOPE	VOID		adjust_trace_information( adjust, ligne )
short int adjust;
WORD	ligne;
{
	TRACEPTR	iptr;

	if (( TraceItem != (TRACEPTR) 0)
	&&  (( iptr = TraceRoot ) != (TRACEPTR) 0)) {
		do	{
			if (( valid_item    ( iptr )) 
			&&  ( valid_filename( iptr )))   {
				if ( iptr->ligne == ligne )
					iptr->type |= INVALID_ITEM;
				else if ( iptr->ligne > ligne )
					iptr->ligne += adjust;
				}
			iptr = iptr->next;
			}
		while ( iptr != (TRACEPTR) 0 );
		}
	return;
}

PUBLIC_SCOPE	VOID		commit_trace_adjustment()
{
	TRACEPTR	iptr;

	if (( TraceItem != (TRACEPTR) 0)
	&&  (( iptr = TraceRoot ) != (TRACEPTR) 0)) {
		do	{
			if ( valid_filename( iptr ) ) {
				if ( iptr->type & INVALID_ITEM ) {
					if ( iptr->previous == (TRACEPTR) 0) {
						TraceRoot = iptr->next;
						TraceRoot->previous = (TRACEPTR) 0;
						}
					else	{
						iptr->previous->next = iptr->next;
						if ( iptr->next != (TRACEPTR) 0)
							iptr->next->previous = iptr->previous;
						}
					zfree( iptr );
					}
				else	iptr->original  = iptr->ligne;

				}
			iptr = iptr->next;
			}
		while ( iptr != (TRACEPTR) 0 );
		}
	return;
}

PUBLIC_SCOPE	VOID		forget_trace_adjustment()
{
	TRACEPTR	iptr;

	if (( TraceItem != (TRACEPTR) 0)
	&&  (( iptr = TraceRoot ) != (TRACEPTR) 0)) {
		do	{
			if ( valid_filename( iptr ) )
				iptr->ligne  = iptr->original;
			iptr->type &= ~ INVALID_TYPE; 
			iptr = iptr->next;
			}
		while ( iptr != (TRACEPTR) 0 );
		}
	return;
}

PUBLIC_SCOPE	VOID		revalidate_trace_information( nbl )
WORD nbl;
{
	TRACEPTR	iptr;

	if (( iptr = TraceRoot ) != (TRACEPTR) 0) {
		do	{
			if (( valid_filename( iptr ) )
			&&  (iptr->ligne  == nbl )) {
				iptr->type &= ~INVALID_ITEM;
				break;
				}
			iptr = iptr->next;
			}
		while ( iptr != (TRACEPTR) 0 );
		}
	return;
}

#endif	/* _TRACEMAN_C */
	/* ----------- */
