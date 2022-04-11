#ifndef	_TRAPPING_C
#define	_TRAPPING_C

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include "aplus.h"		/* Include standard definitions		*/
#include "struct.h"
#include "macros.h"
#include "options.h"
#include "status.h"
#include "syntax.h"
#include "memory.h"
#include "member.h"
#include "pragma.h"
#include "trapping.h"
#include "abal.h"
#include "allocate.h"		/* Allocation function prototypes	*/


EXTERN	MEMBERPTR	CurrentMacroMember;
WORD	ExceptionDestruction=0;
WORD	ExceptionConstruction=0;

VOID	activate_exception_destruction()
{
	ExceptionDestruction = 1;
	return;
}
VOID	inhibit_exception_destruction()
{
	ExceptionDestruction = 0;
	return;
}
void	initialise_exception_handlers()
{
	ExceptionCounter = 2;
	return;
}


void	release_exception_handler( ltrap )
TRAPPTR	ltrap;
{
	if ( ltrap != (TRAPPTR) 0 )
		free( ltrap );
	return;
}

void	exception_label( ltrap )
TRAPPTR	ltrap;
{
	output_byte( '&' );
	output_string( "XTRP" );
	output_integer( ltrap->identity );
	return;
}

void	generate_error_abhort()
{
	output_string("On Error Abort");
	output_newline();	
	return;
}

VOID	standard_exception_variable( level )
WORD	level;
{
	output_byte( 'X' );
	output_integer( level );
	output_string((BPTR) "_error_value" );
	return;
}

VOID	standard_exception_throw(level)
WORD	level;
{
	if (( Options.Version > 14 ) && ( pragmas_throw() )) {
		if ( level == 1 )
			ExceptionConstruction = 1;
		output_newline();
		standard_exception_variable( level );
		output_string((BPTR) " = 0" );
		output_newline();
		output_string((BPTR)"On Error Goto &XTRP" );
		output_integer( level );
		output_byte( COMMA );
		standard_exception_variable( level );
		output_newline();
		}
	return;
}

VOID	standard_exception_catch(level)
WORD	level;
{
	if (( Options.Version > 14 ) && ( pragmas_throw() )) {
		if (( level == 1 ) && (!( ExceptionConstruction )))
			return;

		output_newline();
		output_string((BPTR) "&XTRP" );
		output_integer( level );
		output_newline();
		generate_error_abhort();
		if (( level == 1 ) && ( ExceptionDestruction )) {
			activate_abal_destructors();
			inhibit_exception_destruction();
			ExceptionConstruction = 0;
			}
		output_string((BPTR) "Error(");
		standard_exception_variable( level );
		output_byte(RIGHTBRACE);
		output_newline();
		}
	return;
}

void	terminate_exception_handler( ltrap )
TRAPPTR	ltrap;
{
	if ( ltrap != (TRAPPTR) 0 ) {
		output_newline();
		output_string("Break");
		output_newline();
		exception_label( ltrap );
		output_newline();
		output_string(";** Exception handler : ");

/*
 *	For informational purposes only
 *
 *		output_string( ltrap->object->name );
 *		output_byte('.');
 *		output_string( ltrap->object->class->name );
 *		output_byte('.');
 */

		output_string( ltrap->member->name ); 

/*
 *		output_byte('(');
 *		output_string( ltrap->member->class->name ); 
 *		output_byte(')');
 */
		output_newline();

		if ( establish_null_source() != MOINS_UN) {
			if ( activate_method( ltrap->object, ltrap->member->class, ltrap->member->macro, ltrap->member, ltrap->adjust, ltrap->father, ltrap->ladjust, ltrap->common, ltrap->field) != MOINS_UN )
				(void) standard_parser(Status.Master);
			(void) pop_source_context();
			}

		output_newline();
		output_string("Loop");
		output_newline();
		generate_error_abhort();
		free( ltrap );
		}
	return;
}

MEMBERPTR	select_exception_handler( lcond )
MEMBERPTR	lcond;
{

	while ( lcond != (MEMBERPTR) 0) {
		if ( lcond->condition & 2 )
			break;
		else	lcond = lcond->next;
		}
	return( lcond );
}

MEMBERPTR	select_invariant_handler( lcond )
MEMBERPTR	lcond;
{

	while ( lcond != (MEMBERPTR) 0) {
		if ( lcond->condition & 8 )
			break;
		else	lcond = lcond->next;
		}
	return( lcond );
}

MEMBERPTR	locate_explicite_condition( xterm, lterm )
MEMBERPTR	xterm;
MEMBERPTR	lterm;
{
	MEMBERPTR	nterm;
	if ((nterm = lterm->class->condition) != (MEMBERPTR) 0) {
		do	{
			if ((nterm->hash == xterm->hash)
			&& ( compare_tokens( nterm->name, xterm->name )) == VRAI )
				break;
			}
		while (( nterm = nterm->next ) != (MEMBERPTR) 0 );
		}
	return( nterm );
}

MEMBERPTR	locate_exception_handler( lterm )
MEMBERPTR	lterm;
{
	MEMBERPTR	xterm;
	if ((xterm = select_exception_handler( lterm->local)) == (MEMBERPTR) 0)
		return((xterm = select_exception_handler( lterm->class->condition )));
	else	return( locate_explicite_condition( xterm, lterm ) );
	/* Was else return( xterm ); */ 
}

MEMBERPTR	locate_invariant_handler( lterm )
MEMBERPTR	lterm;
{
	MEMBERPTR	xterm;
	if ((xterm = select_invariant_handler( lterm->local)) == (MEMBERPTR) 0)
		return((xterm = select_invariant_handler( lterm->class->condition )));
	else	return( locate_explicite_condition( xterm, lterm ) );
	/* Was else	return( xterm ); */
}

void	generate_exception_variable( vname )
BPTR	vname;
{
	BYTE	vtemp[128];
	WORD	l;
	(void) establish_null_source();
	strcpy( (BPTR) vtemp, vname );
	vtemp[(l = strlen((BPTR) vname))] = ' ';
	vtemp[(l+1)] = 0;
	(void) establish_source_token( vtemp );
/*
 *	May be used for Debug 
 *
 *	announce_source_context();
 *	announce_current_status(); 
 */
	(void) standard_parser(Status.Master);
	pop_source_context();
	return;
}

TRAPPTR initiate_exception_handler(lterm,lobject,adjust,father,ladjust,lcommon,lfield)
MEMBERPTR	lterm;
OBJECTPTR	lobject;
WORD		adjust;
MEMBERPTR	father;
WORD		ladjust;
WORD		lcommon;
WORD		lfield;
{
	TRAPPTR		ltrap;
	MEMBERPTR	xterm;

	if ((xterm = locate_exception_handler( lterm)) == (MEMBERPTR) 0)
		return( (TRAPPTR) 0 );

	if ((ltrap = allocate_for_exception()) == (TRAPPTR) 0)
		return( (TRAPPTR) 0 );

	ltrap->member   = xterm;
	ltrap->object   = lobject;
	ltrap->adjust   = adjust;
	ltrap->ladjust  = ladjust;
	ltrap->common   = lcommon;
	ltrap->field    = lfield;
	ltrap->father   = father;
	ltrap->identity	= ++ExceptionCounter;

	if ( Options.Version >= 20 )
		output_string("On Local Error Goto ");
	else	output_string("On Error Goto ");
	exception_label( ltrap );
	output_byte( COMMA );
#ifdef	GENERATE_ERRNO
	output_string( "errno" );
#else
	generate_exception_variable( ltrap->member->name );
#endif
	output_newline();	
	output_string( "Do");
	output_newline();
	return( ltrap );

}

VOID	start_invariant( xterm )
MEMBERPTR	xterm;
{
	output_string("On Event ' ");
	if ( Options.Translator & ATR_SYMBOLIC )
		output_string( xterm->name );
	output_newline();	
	return;
}

void	terminate_invariant()
{
	output_newline();
	output_string("Event Off");
	output_newline();
	return;
}

WORD initiate_invariant_handler(lterm,lobject,adjust,father,ladjust,lcommon,lfield)
MEMBERPTR	lterm;
OBJECTPTR	lobject;
WORD		adjust;
MEMBERPTR	father;
WORD		ladjust;
WORD		lcommon;
WORD		lfield;
{
	TRAPPTR		ltrap;
	MEMBERPTR	xterm;

	if ((xterm = locate_invariant_handler( lterm)) == (MEMBERPTR) 0)
		return( 0 );

	if ((ltrap = allocate_for_exception()) == (TRAPPTR) 0)
		return( 0 );

	ltrap->member   = xterm;
	ltrap->object   = lobject;
	ltrap->adjust   = adjust;
	ltrap->ladjust  = ladjust;
	ltrap->common   = lcommon;
	ltrap->field    = lfield;
	ltrap->father   = father;

	start_invariant( xterm );

	/* Generate Invariant Test operations */
	/* ---------------------------------- */
	if ( establish_null_source() != MOINS_UN) {
		if ( activate_method( ltrap->object, ltrap->object->class, ltrap->member->macro, ltrap->member, ltrap->adjust, ltrap->father, ltrap->ladjust, ltrap->common, ltrap->field) != MOINS_UN )
			(void) standard_parser(Status.Master);
		(void) pop_source_context();
		}

	free( ltrap );

	output_newline();
	output_string("End Event" );
	output_newline();
	return( 1 );

}

WORD	check_for_precondition( lterm )
MEMBERPTR	lterm;
{
	if ((lterm->condition & 0x8000))
		return( FAUX );
	else if ( Options.Inhibitions & 1 )
		return( FAUX );
	else if ( lterm->condition & 0x0001 ) 
		return( VRAI );
	else if ( lterm->condition & 0x0010 )
		return( FAUX );
	else if ( lterm->overlay )
		return(( Options.Conditions & 0x1000 ));
	else if ( lterm->function )
		return(( Options.Conditions & 0x0100 ));
	else if ( lterm->routine )
		return(( Options.Conditions & 0x0010 ));
	else	return(( Options.Conditions & 0x0001 ));

}

WORD	check_for_exception( lterm )
MEMBERPTR	lterm;
{
	if ((lterm->condition & 0x8000))
		return( FAUX );
	else if ( Options.Inhibitions & 2 )
		return( FAUX );
	else if ( lterm->condition & 0x0002 )
		return( VRAI );
	else if ( lterm->condition & 0x0020 )
		return( FAUX );
	else if ( lterm->overlay )
		return(( Options.Conditions & 0x2000 ));
	else if ( lterm->function )
		return(( Options.Conditions & 0x0200 ));
	else if ( lterm->routine )
		return(( Options.Conditions & 0x0020 ));
	else	return(( Options.Conditions & 0x0002 ));

}

WORD	check_for_postcondition( )
{
	MEMBERPTR	lterm;

	if ((lterm = CurrentMacroMember) == (MEMBERPTR) 0)
		return( FAUX );
	else if ( Options.Inhibitions & 4 )
		return( FAUX );
	else if ((lterm->condition & 0x8000))
		return( FAUX );
	else if ( lterm->condition & 0x0004 )
		return( VRAI );
	else if ( lterm->condition & 0x0040 )
		return( FAUX );
	else if ( lterm->overlay )
		return(( Options.Conditions & 0x4000 ));
	else if ( lterm->function )
		return(( Options.Conditions & 0x0400 ));
	else if ( lterm->routine )
		return(( Options.Conditions & 0x0040 ));
	else	return(( Options.Conditions & 0x0004 ));

}

WORD	check_for_invariant( )
{
	MEMBERPTR	lterm;

	if ((lterm = CurrentMacroMember) == (MEMBERPTR) 0)
		return( FAUX );
	else if ( Options.Inhibitions & 8 )
		return( FAUX );
	else if ((lterm->condition & 0x8000))
		return( FAUX );
	else if ( lterm->condition & 0x0008 )
		return( VRAI );
	else if ( lterm->condition & 0x0080 )
		return( FAUX );
	else if ( lterm->overlay )
		return(( Options.Conditions & 0x8000 ));
	else if ( lterm->function )
		return(( Options.Conditions & 0x0800 ));
	else if ( lterm->routine )
		return(( Options.Conditions & 0x0080 ));
	else	return(( Options.Conditions & 0x0008 ));

}


void	start_condition( lcond )
MEMBERPTR	lcond;
{
	output_newline();
	output_string( "If ' ");
	if ( Options.Translator & ATR_SYMBOLIC )
		output_string( lcond->name );
	output_newline();
	return;
}

void	close_condition()
{
	output_newline();
	output_string("Endif");
	output_newline();
}

void	generate_postconditions()
{	
	MEMBERPTR	lterm;
	MEMBERPTR	lcond;

	/* Ensure valid member with valid conditions list */
	/* ---------------------------------------------- */
	if (((lterm = CurrentMacroMember) == (MEMBERPTR) 0)
/*IJM*/	||  (( lterm->function ) && (!(Status.Function))) /* 20/09/1994 */
	||  (( lcond = lterm->local ) == (MEMBERPTR) 0))
		return;

/*IJM*/	if ((lterm->function) || (lterm->overlay) || (lterm->routine)) {
		signal_abal_postcondition(lterm->routine);
		output_newline();
		if (lterm->routine)
			generate_condition_label( active_gosub_number() );
		else	generate_condition_label( MOINS_UN );
		output_newline();
		} /* 21/09/1994 */ 
	do	{
		if ( lcond->condition & 4 ) {
			start_condition( lcond );
			(void) establish_null_source();
			(void) activate_post_method( lcond );
			(void) standard_parser(Status.Master);
			(void) pop_source_context();
			close_condition();
			}
		}
	while ((lcond = lcond->next) != (MEMBERPTR) 0);
/*IJM*/	if ((lterm->function) || (lterm->overlay) || (lterm->routine)) {
		output_newline();
		output_string((BPTR) "Return" );
		output_newline();
		} /* 21/09/1994 */
	return;
}

WORD	terminate_preconditions( status, nombre )
WORD	status;
WORD	nombre;
{
	if ( check_for_postcondition() )
		generate_postconditions();
 
	while ( nombre ) {
		close_condition();
		nombre--;
		}
	return( status );
}

WORD	generate_pre_conditions(lobject, lclass, lcond, adjust, last_member, last_adjust, commonflag, field )
OBJECTPTR	lobject;
CLASSPTR	lclass;
MEMBERPTR	lcond;
WORD		adjust;
MEMBERPTR	last_member;
WORD		last_adjust;
WORD		commonflag;
WORD		field;
{
	WORD	nombre=0;

	do	{
		if ( lcond->condition & 1 ) {
			start_condition( lcond );
			(void) establish_null_source();
			(void) activate_method( lobject, lclass, lcond->macro, lcond, adjust, last_member, last_adjust, commonflag, field);
			(void) standard_parser(Status.Master);
			(void) pop_source_context();
			nombre++;
			}
		}
	while ((lcond = lcond->next) != (MEMBERPTR) 0);
	return( nombre );
}
	
WORD	flush_preconditions(lobject, lclass, lterm, adjust, last_member, last_adjust, commonflag, field )
OBJECTPTR	lobject;
CLASSPTR	lclass;
MEMBERPTR	lterm;
WORD		adjust;
MEMBERPTR	last_member;
WORD		last_adjust;
WORD		commonflag;
WORD		field;
{
	MEMBERPTR	lcond;
	MEMBERPTR	xcond;
	WORD		nombre=0;

	/* Allow generation of MEMBER LOCAL pre-conditions */
	/* ----------------------------------------------- */
	if (( lcond = lterm->local ) != (MEMBERPTR) 0)
		nombre += generate_pre_conditions( lobject, lclass, lcond, adjust, last_member, last_adjust, commonflag, field);
	else	
		/* Allow generation of CLASS pre-conditions */
		/* ---------------------------------------- */
		if (( lcond = lclass->condition ) != (MEMBERPTR) 0) {
			xcond = lcond;
			lclass->condition = (MEMBERPTR) 0;
			nombre += generate_pre_conditions( lobject, lclass, lcond, adjust, last_member, last_adjust, commonflag, field);
			lclass->condition = xcond;
			}

	return( nombre );
}


WORD	exceptional_inline( mterm, lmacro, lobject, lclass, adjust, lmember, ladjust, commonflag, field, nbcond )
MEMBERPTR	mterm;
MACROPTR	lmacro;
OBJECTPTR	lobject;
CLASSPTR	lclass;
WORD		adjust;
MEMBERPTR	lmember;
WORD		ladjust;
WORD		commonflag;
WORD		field;
WORD		nbcond;
{
	TRAPPTR	ltrap;
	WORD	status;

	status = establish_source_macro( mterm, lmacro, lobject, lclass, adjust, lmember, ladjust, commonflag, field,nbcond ); 

	/* Check for Exception available for INLINE METHOD */
	/* ----------------------------------------------- */
	if ((ltrap = initiate_exception_handler( mterm, lobject, adjust, lmember, ladjust, commonflag, field )) != (TRAPPTR) 0) {
		(void) pop_source_context();
		(void) establish_null_source();
		(void) establish_source_macro( mterm, lmacro, lobject, lclass, adjust, lmember, ladjust, commonflag, field, 0 ); 
		(void) standard_parser(Status.Master);
		(void) pop_source_context();
		terminate_exception_handler( ltrap );
		return( terminate_preconditions( VRAI, nbcond ));
		}
	/* No Exception Available so normal operation */
	/* ------------------------------------------ */
	else	return( status );
}


	 
#endif	/* _TRAPPING_C */
	/* ----------- */
