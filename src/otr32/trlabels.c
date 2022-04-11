#define	DEBUG
/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRLABELS.C				*/
/*		Version :	2.1d					*/
/*		Date	:	08/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRLABELS_C
#define	_TRLABELS_C

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include <string.h>		/* string functions */
#include "stdtypes.h"
#include "translat.h"
#include "trlabels.h"
#include "troption.h"
#include "trdebug.h"
#include "trsyntax.h"
#include "trproc.h"
#include "triof.h"
#include "troutput.h"
#include "trerrors.h"
#include "trclass.h"
#include "trtables.h"
#include "trecho.h"


WORD	tcode_labels() { return(VRAI); }

VOID	liberate_label( lptr )
LABELPTR	lptr;
{
	if ( lptr->name != (BPTR) 0 )
		liberate( lptr->name );
	lptr->next = FreeLabels;
	FreeLabels = lptr;
	return;
}

LABELPTR	allocate_for_label( nptr )
BPTR	nptr;
{
	LABELPTR	lptr;
	trace("allocate_for_label()\n");
	trace( nptr );
	if ( nptr == (BPTR) 0 )
		return((LABELPTR) 0);
	else if ( *nptr == '&' )
		nptr++;
	if ((lptr = FreeLabels) != (LABELPTR) 0)
		FreeLabels = lptr->next;
	else if ((lptr = (LABELPTR) allocate( sizeof( struct otr_label ))) == (LABELPTR) 0)
		return( lptr );

	if ((lptr->name = (BPTR) allocate( strlen(nptr) +1 )) != (BPTR) 0) {
		lptr->hash = keyword_hash( nptr );
		strcpy( lptr->name, nptr );
		lptr->user = MOINS_UN;
		lptr->adresse = MOINS_UN;
		lptr->next = (LABELPTR) 0;
		}
	else	{
		liberate_label( lptr );
		lptr = (LABELPTR) 0;
		}
	return( lptr );
}

WORD	release_labels()
{
	LABELPTR	lptr;
	WORD		nombre=0;
	trace("release_labels()\n");
	while ((lptr = FreeLabels) != (LABELPTR) 0) {
		FreeLabels = lptr->next;
		liberate( lptr );
		nombre++;
		}
	return( nombre );
}

LABELPTR	is_label( nptr )
BPTR	nptr;
{
	LABELPTR	lptr;
	WORD		h;
	if ( *nptr == '&' )
		nptr++;	
	trace( "is_label()\n");
	trace( nptr );
	if ((lptr = LabelHeap) != (LABELPTR) 0) {
		h = keyword_hash( nptr );
		do	{
			if ((h == lptr->hash)
			&& ( compare_tokens( nptr, lptr->name ) ))
				break;
			}
		while ((lptr = lptr->next) != (LABELPTR) 0);
		}
	return( lptr );
}

WORD	use_explicite_label( nptr, indent )
BPTR	nptr;
WORD	indent;
{
	WORD	result;
	LABELPTR	lptr;
#ifdef	_TRACE_ADD_LABEL
	sysprintf("use_explicite_label(%s,indent = %u) \n",nptr,indent);
#endif
	if ( *nptr == '&' )
		nptr++;
	trace("use_explicite_label()\n");
	trace(nptr);
	if ((lptr = is_label( nptr )) != (LABELPTR) 0) {
		if ( lptr->adresse != MOINS_UN )
			return( lptr->adresse );
		else	{
			result = lptr->user;
			lptr->user = (current_tcode_offset() + indent);
			return( result );
			}
		}
	else if ((lptr = allocate_for_label( nptr )) == (LABELPTR) 0) {
		(void) allocation_failure();
		return( 0 );
		}
	else	{
		lptr->user = (current_tcode_offset() + indent);
		lptr->next = LabelHeap;
		LabelHeap = lptr;
		return((lptr->adresse = MOINS_UN));
		}	

}

WORD	show_use_explicite_label( nptr, i )
BPTR	nptr;
WORD	i;
{
	WORD	result;
	result = use_explicite_label( nptr, i );
	sysprintf("use_explicite_label(%s,0%04.1X) ==>  %04.1X \n",nptr,i,result);
	return( result );
}

/*
 *	Called from TRPARSER.C when examining new line to be translated for
 *	an explicite label
 *
 *	And from TRITER.C when generating implicite labels
 */


WORD	add_explicite_label( nptr )
BPTR	nptr;
{
	LABELPTR	lptr;


	if ( is_method_definition() )
		return( transmit_method_label( nptr ) );
	else if ( check_data_label( nptr ) )
		return(1);

	trace("add_explicite_label()\n");
	trace( nptr );

	if ( OtrOption.ListFlag & 1 )
		if ( *nptr == '&' )
			echo_label( nptr );

	if ( *nptr == '&' )
		nptr++;

	if ((lptr = is_label( nptr )) != (LABELPTR) 0) {
		if ( lptr->adresse != MOINS_UN ) {
#ifdef	otr32
			sysprintf("duplicate label : %s : %s %08.1X \n",nptr,
				lptr->name,lptr->adresse);
#else
			sysprintf("duplicate label : %s : %s %04.1X \n",nptr,
				lptr->name,lptr->adresse);
#endif
			(void) syntax_error(2);
			return( 0 );
			}
		else	{
			lptr->adresse = current_tcode_offset();
#ifdef	_TRACE_ADD_LABEL
			sysprintf("AddLabel(%s) : &%04.1X \n",nptr,lptr->adresse); 
#endif
			while (lptr->user != MOINS_UN)
				lptr->user = backpatch_label(lptr->user, lptr->adresse);
#ifdef	_TRACE_ADD_LABEL
			sysprintf("Done\n"); 
#endif
			return( 1 );
			}
		}
	else if ((lptr = allocate_for_label( nptr )) == (LABELPTR) 0) {
		(void) allocation_failure();
		return( 0 );
		}
	else	{
		lptr->adresse = current_tcode_offset();
#ifdef	_TRACE_ADD_LABEL
		sysprintf("AddLabel(%s) : &%04.1X \n",nptr,lptr->adresse);	
#endif
		lptr->next = LabelHeap;
		LabelHeap = lptr;
		return(1);
		}	
}

VOID	terminate_labels()
{
	LABELPTR	lptr;
	trace("*** Terminate_Labels()\n");
	while ((lptr = LabelHeap) != (LABELPTR) 0) {
		LabelHeap = LabelHeap->next;
		if ( lptr->adresse == MOINS_UN )
			undefined_label( lptr->name );
		liberate_label( lptr );
		}
	return;
}

VOID	initialise_labels()
{
	trace("*** Initialise_Labels()\n");
	LabelHeap = (LABELPTR) 0;
	FreeLabels = (LABELPTR) 0;
	OtrOption.LabelGroup=1;
	return;
}


#endif	/* _TRLABELS_C */
	/* ----------- */

