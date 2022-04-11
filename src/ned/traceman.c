/* --------------------------------------------------------------------	
 *									
 *		Project ABAL : Macro pre-processer			
 *									
 *		 Copyright (c) 1991, 1997 Amenesik / Sologic s.a.			
 *									
 *									
 *		File	:	TRACEMAN.C				
 *		Version :	1.1a					
 *		Date	:	13/10/1997				
 *									
 * Corrections :
 * 13/10/97 : Gestion de plus de 65000 lignes (YT131097)
 *
 * --------------------------------------------------------------------	*/

#ifndef	_TRACEMAN_C
#define _TRACEMAN_C

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include <string.h>		/* Error return definitions		*/
#include "stdtypes.h"		/* Standardised type definitions	*/ 
#include "traceman.h"		/* Trace management decription header	*/
#include "allocate.h"
/* 	----------------------------------	*/
/*	PRIVATE TRACE MANAGEMENT FUNCTIONS	*/
/* 	----------------------------------	*/

PRIVATE_SCOPE	void	reset_trace_item( iptr )
TRACEPTR	iptr;
{
	iptr->filename 	 = (BYTE FPTR) 0;
	iptr->colonne 	 = 0;
	iptr->ligne 	 = 0;	
	iptr->original 	 = 0;	
	iptr->type 	 = 0;	
	iptr->message 	 = (BYTE FPTR) 0;	
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
WORD		selection;
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
BYTE FPTR	nfic;
LONG	linid;
WORD	colid;
BYTE FPTR	mptr;
{
	TRACEPTR	iptr;
	BYTE out[50];

	if (( iptr = (TRACEPTR) zalloc( sizeof( struct trace_control ) )) != (TRACEPTR) 0) {
		reset_trace_item( iptr );
		if (( iptr->filename = (BYTE FPTR) zalloc( (WORD) (Mstrlen( (BYTE FPTR) nfic ) + 1))) != (BYTE FPTR) 0) {
			Mstrcpy( (BYTE FPTR) iptr->filename, (BYTE FPTR) nfic );
			if (( iptr->message = (BYTE FPTR) zalloc( (WORD) (Mstrlen( (BYTE FPTR) mptr ) + 1))) != (BYTE FPTR) 0) {
				Mstrcpy( (BYTE FPTR) iptr->message, (BYTE FPTR) mptr );
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
	LONG		nbl;
	WORD		nbc;
	BYTE XPTR	bptr;
	WORD		indent;
	BYTE		buffer[256];
	BYTE		nomfic[256];

	nbi = 0;
	while ((bptr = Xfgets( buffer, 256, handle )) != (BYTE XPTR) 0) {
		(VOID) XscanfForLong( (BYTE XPTR) buffer, (BYTE XPTR) nomfic, (LONG XPTR) & nbl, (WORD XPTR) & nbc, (WORD XPTR) &indent );
		nbi += (WORD) add_trace_item( (BYTE FPTR) nomfic, (LONG) nbl, (WORD) nbc, (BYTE FPTR) (&buffer[indent]) );
		}
	return( nbi );	
}


/* 	---------------------------------	*/
/*	PUBLIC TRACE MANAGEMENT FUNCTIONS	*/
/* 	---------------------------------	*/

PUBLIC_SCOPE	WORD	initialise_trace_controller( tracefile )
BYTE FPTR 	tracefile;
{
	FILEPTR	handle;
	WORD	items;
	BYTE	fichier[256];

#ifdef test_alloc
	nb_alloc = 0;
#endif
	items = 0;
	reset_trace_controller();

	fichier[0] = 0;
	Mstrcpy((BYTE FPTR) fichier, (BYTE FPTR) tracefile);

	if ((handle = (FILEPTR) fopen( fichier, "r" )) != (FILEPTR) 0) {
		items = load_items( handle );
		TraceItem = TraceRoot;
		fclose( handle );
		}

	return( items );
}

PUBLIC_SCOPE	VOID	terminate_trace_controller()
{
	TRACEPTR	iptr;
	while (( iptr = TraceRoot ) != (TRACEPTR) 0) {
		TraceRoot = TraceRoot->next;
		zfree( iptr->filename );
		zfree( iptr->message );
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
SWORD   adjust;
LONG	ligne;
{
	TRACEPTR	iptr;

	if (( TraceItem != (TRACEPTR) 0)
	&&  (( iptr = TraceRoot ) != (TRACEPTR) 0)) {
		do	{
			if (( valid_item    ( iptr )) 
			&&  ( valid_filename( iptr )))   {
				if ( iptr->ligne == ligne && adjust == MOINS_UN )
					iptr->type |= INVALID_ITEM;
				else if ( iptr->ligne >= ligne )
					iptr->ligne += adjust;
				}
			iptr = iptr->next;
			}
		while ( iptr != (TRACEPTR) 0 );
		}
	return;
}

PUBLIC_SCOPE	VOID	commit_trace_adjustment()
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
			iptr->type &= ~ INVALID_ITEM; 
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

PUBLIC_SCOPE	WORD		Mstrcmp( s , t )
BYTE FPTR s;
BYTE FPTR t;
{
#ifdef	ver2Kalloc
	while (( *s != 0 ) && ( *t != 0 )) {
		if ( *s != *t )
			break;
		else	{ s++; t++; }
		}
	return( *s - *t );
#else
	BYTE source[320];
	BYTE target[320];

	Mstrcpy((BYTE FPTR ) source, (BYTE FPTR) s);
	Mstrcpy((BYTE FPTR ) target, (BYTE FPTR) t );

	return( strcmp(source, target ) );
#endif
}

static BYTE XPTR Xfgets(BYTE XPTR buf, WORD lgr, FILE XPTR fic)
{
	BYTE XPTR p;

	if (fgets(buf,lgr,fic) == NULL) {
		*buf = '\0';
	}
	if (strlen(buf) == 0)
		return( NULL );

	p = buf+strlen(buf)-1;
	if ((*p == '\n') || (*p == '\r'))
		*p = '\0';
	if (strlen(buf) == 0)
		return( NULL );

	p = buf+strlen(buf)-1;
	if ((*p == '\n') || (*p == '\r'))
		*p = '\0';
	if (strlen(buf) == 0)
		return( NULL );

	return( buf );


}


/*	Lecture d'un entier dans le tampon 'buf', a partir
 *	de la position 'ptr', et resultat dans 'val'
 */
static VOID Xscanf(BYTE XPTR buf,  BYTE XPTR fichier, WORD XPTR lig, WORD XPTR col, WORD XPTR indent)
{
	 WORD tmp;
	 BYTE c;
	 WORD ptr;

  ptr = 0;
	/* une chaine		*/
  while ((c = buf[ptr]) != '\0' && (c != ' ')) {
	*(fichier++) = c;
	ptr ++;
  }
  while ((c = buf[ptr]) == ' ')
	ptr++;

  *(fichier) = 0;

	/* un entier  l		*/
  tmp = 0;
  while ((c = buf[ptr]) != '\0' && (c != ' ')) {
	tmp = (WORD) (10 * tmp + (WORD) ((c - (BYTE) '0')));
	ptr ++;
  }
  while ((c = buf[ptr]) == ' ')
	ptr++;
  *lig = tmp;

  /* un entier  c		*/
  tmp = 0;
  while ((c = buf[ptr]) != '\0' && (c != ' ')) {
	tmp = (WORD) (10 * tmp + (WORD) ((c - (BYTE) '0')));
	ptr ++;
  }
  while ((c = buf[ptr]) == ' ')
	ptr++;

  *col = tmp;

  /* indentation */

  *indent = ptr;
}

/*	Lecture d'un entier LONG dans le tampon 'buf', a partir
 *	de la position 'ptr', et resultat dans 'val'
 */
static VOID XscanfForLong(BYTE XPTR buf,  BYTE XPTR fichier, LONG XPTR lig, WORD XPTR col, WORD XPTR indent)
{
	 LONG tmp;
	 BYTE c;
	 WORD ptr;

  ptr = 0;
	/* une chaine		*/
  while ((c = buf[ptr]) != '\0' && (c != ' ')) {
	*(fichier++) = c;
	ptr ++;
  }
  while ((c = buf[ptr]) == ' ')
	ptr++;

  *(fichier) = 0;

	/* un entier  l		*/
  tmp = 0;
  while ((c = buf[ptr]) != '\0' && (c != ' ')) {
	tmp = (LONG) (10 * tmp + (LONG) ((c - (BYTE) '0')));
	ptr ++;
  }
  while ((c = buf[ptr]) == ' ')
	ptr++;
  *lig = tmp;

  /* un entier  c		*/
  tmp = 0;
  while ((c = buf[ptr]) != '\0' && (c != ' ')) {
	tmp = (LONG) (10 * tmp + (LONG) ((c - (BYTE) '0')));
	ptr ++;
  }
  while ((c = buf[ptr]) == ' ')
	ptr++;

  *col = (WORD)tmp;

  /* indentation */

  *indent = ptr;
}


#ifdef test_alloc
void far * Xallocate( nb )
int nb;
{
	nb_alloc ++;
	return( (void far * ) allocate( nb ));
}
void Xliberate( pt )
void far * pt;
{
	nb_alloc --;
	return( liberate( (void far *) pt ));
}
#endif

#endif	/* _TRACEMAN_C */
	/* ----------- */

