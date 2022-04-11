#define	DEBUGGER

#ifndef	_EXDBSTAK_C
#define	_EXDBSTAK_C

#include "exdebug.h"
#include "exdbstak.h"
#include "exdbcico.h"
#include "allocate.h"
#include "announce.h"
#include "exdbctrl.h"
#include "exdbmimo.h"
#include "exproto1.h"

BPTR	ThisCodeBase;

static  EXAWORD	allocate_for_stack( type, identity, offset )
EXAWORD	type;
EXAWORD	identity;
EXAWORD	offset;
{
	STACKPTR sptr=(STACKPTR) 0;
	if ((sptr = (STACKPTR) allocate( sizeof( struct stack_analysis ))) != (STACKPTR) 0) {
		MaxStack++;
		CurrentType  = sptr->type  = type;
		CurrentBlock = sptr->identity = identity;
		sptr->offset   = offset;
		sptr->next     = (STACKPTR) 0;
		sptr->previous = (STACKPTR) 0;
		if ((sptr->previous = EndStack) != (STACKPTR) 0)
			sptr->previous->next = sptr;
		else	TopStack = sptr;
		EndStack = sptr;
		return(1);
		}
	return(0);
}

static  VOID	trace_gosubs( current , limit )
EXAWORD	current;
EXAWORD	limit;
{
	EXAWORD	offs;
	for ( ; current > limit; current-- ) {
		offs = ip_hold [ (current-1) ];
#ifndef	UNIX
#ifndef WIN32
		offs = adjust_gosub_offset( ThisCodeBase, offs );
#endif	
#endif
		if (allocate_for_stack( CurrentType, CurrentBlock, offs ) == 0 )
			break;
		}
	return;
}

/*
 *	A N A L Y S E _ S T A C K 
 *	-------------------------
 *	This function alanyses the current stacked context and generates
 *	the equivalent stack browsing control structure for display.
 *
 */

static VOID	analyse_stack()
{
	EXAWORD	ContextFlag;
	EXAWORD	ContextWP;
	EXAWORD	ContextPP;
	EXAWORD	ContextType;
	EXAWORD	ContextOffs;
	EXAWORD	ContextHold;
	EXAWORD	ContextSpec;
	EXAWORD	ContextWadj;
	EXAWORD	ContextPadj;
	struct context SPTR sgcp;

	/* Display Current Code Unit */
	/* ------------------------- */
	if ( sicico & ONSEM_PRC ) {
		trace_procedure( procid,  CurrentTcodeOffset(0) );
		}
	else 	{
		trace_segment  ( cur_seg, CurrentTcodeOffset(0) );
		}

	/* First display pending RETURN adresses */
	/* ------------------------------------- */
	ThisCodeBase = TcodeSegment;

	trace_gosubs( ip_next , StackHold );

	/* Now analyse the current stack context */
	/* ------------------------------------- */
	ContextFlag = sicico; ContextWP = StackHold; ContextPP = mindex;

	/* Destack possible procedures */
	/* --------------------------- */
	while ( ContextFlag & ONSEM_PRC ) {
		ContextFlag = ip_hold [ (ContextWP -  5) ];	/* SICICO   */
		ContextOffs = ip_hold [ (ContextWP -  9) ];	/* FDEX-SB  */
		ContextHold = ip_hold [ (ContextWP -  1) ];	/* STACKHLD */
		ContextSpec = ip_hold [ (ContextWP - 10) ];	/* SPECIAL  */

		if ( ContextSpec ) {
#ifdef LONG_FILE_HANDLES
			ContextWadj = 1;
			ContextPadj = 7;
#else
			ContextWadj = 2;
			ContextPadj = 6;
#endif
		}
		else	{
			ContextWadj = 0;
			ContextPadj = 0;
		}

		/* For sure, this is a procedure context ! */
		ContextType = ip_hold [ (ContextWP - (15+ContextWadj)) ];
		ThisCodeBase = (BPTR) minder [ (ContextPP - 3) ];
		if ( ContextFlag & ONSEM_PRC ) {
			trace_procedure( ContextType , ContextOffs );
		}
		else {
		 	trace_segment( cur_seg , ContextOffs );
		}

		/* Adjust Context stacking pointers */
		/* -------------------------------- */
		ContextWP -= (15 + ContextWadj);
		ContextPP -= (5  + ContextPadj);

		/* Display possible stacked Gosubs */
		/* ------------------------------- */
		trace_gosubs(ContextWP,ContextHold);

		/* Remove possible Gosubs */
		/* ---------------------- */
		ContextWP   = ContextHold;
	}

	/* Destack Possible Segments */
	/* ------------------------- */
	while ( ContextPP > 0 ) {
		ContextPP--;
		sgcp = (struct context SPTR) minder [ ContextPP ];
		ThisCodeBase = sgcp->seg_CS;
		trace_segment( sgcp->seg_ID , sgcp->seg_IP );

		/* Display possible stacked Gosubs */
		/* ------------------------------- */
		trace_gosubs(sgcp->seg_SP,sgcp->seg_SH);
	}
}

static	VOID initialise_stack_trace()
{
	TopStack     = (STACKPTR) 0;
	EndStack     = (STACKPTR) 0;
	MaxStack     = 0;
	return;
}	

static	VOID liberate_stack_trace()
{
	STACKPTR 	sptr;
	while ((sptr = TopStack) != (STACKPTR) 0) {
		TopStack = sptr->next;
		liberate( sptr );
		}
	return;
}

static VOID display_stack_entry(topcol,toplin,nbcol,xstack)
EXAWORD		topcol;
EXAWORD		toplin;
EXAWORD		nbcol;
STACKPTR	xstack;
{
	BPTR	nptr=(BPTR) 0;
	EXAWORD	cno=0;
	EXABYTE	buffer[32];
	BPTR	get_procedure_name( EXAWORD );

	if ( xstack != (STACKPTR) 0 ) {

		pos( toplin, topcol );
		if ( xstack->type ) {
			nptr = get_procedure_name((xstack->identity*16));
			x_cprintf((BPTR) "PROC ");
			x_cprintf((BPTR) nptr   );
			cno += (exadb_strlen((BPTR) nptr) + 5);
			}
		else	{
			x_cprintf((BPTR) "SEGM ");
			cno += (display_integer( xstack->identity ) + 5);
			}
		x_putch( ':' );
		display_hexint( xstack->offset );
		cno += 5;
		for ( ; cno < (nbcol-1); cno++ )
			x_putch( ' ' );
		}
	else	left_string( topcol, toplin, nbcol, (BPTR) " " );
	return;
}

static VOID	zoom_stack_entry( xstack )
STACKPTR	xstack;
{
	if ( xstack != (STACKPTR) 0) {
		(void) tcode_correspondance( xstack->type, ( xstack->type ? ( xstack->identity * 16 ) : xstack->identity ),xstack->offset, 2 );
		}
	return;
}

static VOID	display_stack_page(topcol,toplin,nbcol,nblin,xstack)
EXAWORD		topcol;
EXAWORD		toplin;
EXAWORD		nbcol;
EXAWORD		nblin;
STACKPTR	xstack;
{
	EXAWORD	item=0;
	for ( ; item < nblin; item++ ) {
		display_stack_entry( topcol, toplin+item, nbcol, xstack );
		xstack = xstack->next;
		}
	return;
}

static VOID display_stack()
{
	EXAWORD		topcol=2;
	EXAWORD		toplin=6;
	EXAWORD		nbcol=40;
	EXAWORD		nblin=13;
	EXAWORD		maxlines=13;
	EXAWORD		item=0;
	STACKPTR	hstack=TopStack;
	STACKPTR	lstack=TopStack;
	STACKPTR	xstack=TopStack;
	EXAWORD		c;

	maxlines = avoid_observations( 13 );
	if (!(maxlines & 1))
		maxlines--;

	nblin=(MaxStack > maxlines ? maxlines : MaxStack);
	mouse_title_box( topcol, toplin, nbcol, nblin, (BPTR) TalkPtr[54] );
	display_stack_page( topcol+1, toplin+1, nbcol, nblin, xstack );
	while ( 1 ) {
		symbolic_atribut(2);
		display_stack_entry( topcol+1, toplin+1+item, nbcol, xstack );
		symbolic_atribut(0);
		c = mouse_or_keyboard();
		display_stack_entry( topcol+1, toplin+1+item, nbcol, xstack );
	 	switch ( c ) {
			case CTRL_E :
				if ( xstack->next != (STACKPTR) 0 ) {
					xstack = xstack->next;
					if ( item < nblin )
						item++;
					else	{
						lstack = lstack->next;
						break;
						}
					}
				continue;

			case CTRL_K :
				if ( xstack->previous != (STACKPTR) 0 ) {
					xstack = xstack->previous;
					if ( item > 0 )
						item--;
					else	{
						lstack = lstack->previous;
						break;
						}
					}
				continue;

			case 0x001B :
				pop_mouse();
				return;

			case CTRL_D :
				if ( DbMouse.position == 0 )
					continue;
				item++;
				if ( DbMouse.position < item ) {
					for ( ; DbMouse.position < item; item-- ) {
						if ((xstack != (STACKPTR) 0)
						&& ( xstack->previous != (STACKPTR) 0 ))
							xstack = xstack->previous;
						else	{
							item--;
							continue;
							}
						}
					}
				else	{
					for ( ; item < DbMouse.position; item++ ) {
						if ((xstack != (STACKPTR) 0)
						&& ( xstack->next != (STACKPTR) 0 ))
							xstack = xstack->next;
						else	{
							item--;
							continue;
							}
						}
					}
				item--;
				if ( current_mouse_click() != 2 )
					continue;

			case CTRL_M :
				pop_mouse();
				zoom_stack_entry( xstack );
				mouse_title_box( topcol, toplin, nbcol, nblin, (BPTR) TalkPtr[54] );
				break;

			case CTRL_L :
				xstack = lstack = hstack;
				item = 0;
				break;
			}

		display_stack_page( topcol+1, toplin+1, nbcol, nblin, lstack );
		}	
}

void	stack_trace()
{
	initialise_stack_trace();
	analyse_stack();
	display_stack();
	liberate_stack_trace();
	return;
}


#endif	/* _EXDBSTAK_C */
	/* ----------- */
