#define	DEBUG
#define	_GEN_C_RTL
#define	_C_RTL_GEN
/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRLDF.C    				*/
/*		Version :	2.1c					*/
/*		Date	:	10/01/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRLDF_C
#define	_TRLDF_C

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include "stdtypes.h"
#include "translat.h"
#include "trsyntax.h"
#include "trparser.h"
#include "trerrors.h"
#include "trsymbol.h"
#include "trexpres.h"
#include "troption.h"
#include "trclf.h"
#include "trldf.h"
#include "trgenc.h"
#include "trdebug.h"
#include "trtnode.h"

static	WORD	LdfNumerate;

TCDLBPTR	allocate_for_dll()
{
	TCDLBPTR	lptr;

	if ((lptr = (TCDLBPTR) allocate( sizeof( struct tcode_library ) )) != (TCDLBPTR) 0) {
		lptr->next    	= (TCDLBPTR) 0;
		lptr->prev    	= (TCDLBPTR) 0;
		lptr->version 	= MOINS_UN;
		lptr->title	= (BPTR) 0;
		lptr->usage	= 0;
		lptr->name	= (BPTR) 0;
		lptr->identity  = MOINS_UN;
		lptr->function  = (TCDLFPTR) 0;
		}
	return( lptr );
}

TCDLFPTR	allocate_for_dlf()
{
	TCDLFPTR	fptr;

	if ((fptr = (TCDLFPTR) allocate( sizeof( struct	tcode_library_function ) )) != (TCDLFPTR) 0) {
		fptr->identity 	= MOINS_UN;
		fptr->name	= (BPTR) 0;
		fptr->library	= (TCDLBPTR) 0;
		fptr->type	= MOINS_UN;
		fptr->usage	= 0;
		fptr->parameter = (TCVARPTR) 0;
		fptr->next	= (TCDLFPTR) 0;
		}
	return( fptr );
}
	 


WORD	get_dll_type()
{
	if ( remove_white_space() ) {
		switch ( get_byte() ) {
			case '#' : return(0);
			case '%' : return(1);
			case '$' : return(3);
			case '*' : return(2); 
			case '.' : return(7);
			default  : unget_byte();
			}
		}
	return( MOINS_UN );
}
	
static WORD	translate_dll_function()
{
	WORD		retval=MOINS_UN;
	WORD		paratype;
	WORD		parasize;
	TCDLBPTR	lptr;
	TCDLFPTR	fptr;
	TCVARPTR	vptr;
	TCVARPTR	lvptr;
	SYMBOLPTR	sptr;
	WORD		numerate=MOINS_UN;

	trace("translate_dll_function()\n");

	if ((lptr = Context->DLT) == (TCDLBPTR) 0)
		return( syntax_error(3040) );

	if ( is_mnemonic("END") ) {
		pop_operation_pointer();
		pop_source_context(MOINS_UN);
		return( 0 );
		}
	else if ( LdfNumerate ) {
		numerate = collect_integer();
		if (!( is_colon() ))
			return( syntax_error(3040) );
		}
	else	numerate = MOINS_UN;

	retval = get_dll_type();

	if (!( get_token() ))
		return( syntax_error(3040) );

	if (( retval == MOINS_UN )
	&&  ( is_level1_keyword() == _KW1_END )) {
		pop_operation_pointer();
		pop_source_context(MOINS_UN);
		return( 0 );
		}


	if ((sptr = is_symbol( TokenBuffer )) != (SYMBOLPTR) 0)
		return( symbol_already_defined(TokenBuffer) );
	if ((sptr = add_symbol( TokenBuffer, SYMBOL_USER  )) == (SYMBOLPTR) 0)
		return(allocation_failure());

	if ((fptr = allocate_for_dlf()) == (TCDLFPTR) 0)
		return( allocation_failure() );

	sptr->contents 	= (VPTR) fptr;
	fptr->name 	= sptr->name;

	if ((fptr->next = lptr->function) != (TCDLFPTR) 0) {
		if ( LdfNumerate )
			fptr->identity = numerate;
		else	fptr->identity = (fptr->next->identity + 1);
		}
	else	{
		if ( LdfNumerate )
			fptr->identity = numerate;
		else	fptr->identity = 0;
		}

	lptr->function 	= fptr;
	fptr->type 	= retval;
	fptr->library 	= lptr;

	if ( is_left_brace() ) {
		do	{
			if ((paratype = get_dll_type()) == MOINS_UN)
				break;
			switch ( paratype ) {
				case	0 : parasize = 1; break;
				case 	1 : parasize = 2; break;
				case	2 : parasize = 8; break;
				case	7 :
				case	3 : parasize = 15; break;
				default	  : return( syntax_error(3040) );
				}
			if ( is_question() )
				paratype |= 0x0008;
			if ((vptr = allocate_for_variable()) == (TCVARPTR) 0)
				return( allocation_failure() );
			if ((vptr->type = allocate_for_type( paratype, parasize, 1, 1,(VPTR) 0 )) == (TCTYPPTR) 0)
				return( allocation_failure() );
			if (fptr->parameter == (TCVARPTR) 0) 
				fptr->parameter = vptr;
			else	lvptr->prev     = vptr;
			lvptr = vptr;
			}
		while ( is_comma() );

		if (!( is_right_brace() ))
			return( unmatched_braces() );
		}

	return(0);
}

static WORD	translate_dll_runtime()
{
	TCDLBPTR	lptr;
	BPTR		token;
	trace("translate_dll_runtime()\n");
	if (((lptr = Context->DLT) != (TCDLBPTR) 0)
	&&  ( get_token() )
	&&  ( is_equals() )
	&&  ( get_token() )) {
		token = (BPTR) TokenBuffer;
		if ( *token == '"' ) {
			token++;
			*( token + ( strlen( token ) - 1 )) = 0;
			}
		if ((lptr->name = allocate_for_string( token )) == (BPTR) 0)
			return( allocation_failure() );
		Context->operation = translate_dll_function;
		return(0);
		}
	return(syntax_error(3040));
}

static WORD	translate_dll_version()
{
	TCDLBPTR	lptr;
	WORD		vers;

	trace("translate_dll_version()\n");

	if (( get_token() )
	&&  ( is_equals() )
	&&  ((vers = collect_integer()) != 0 )) {
		if ((lptr = allocate_for_dll()) == (TCDLBPTR) 0)
			return( allocation_failure() );
		lptr->version = vers;
		if ((lptr->prev = Context->DLT) != (TCDLBPTR) 0) {
			lptr->identity = (lptr->prev->identity + 1);
			lptr->prev->next = lptr;
			}
		else	{
			Context->XDLT = lptr;
			lptr->identity = 0;
			}
		if ( is_comma() ) {
			if ( is_mnemonic( "NUM" ) )
				LdfNumerate = VRAI;
			else	return( syntax_error(3040) );
			}
		else	LdfNumerate = FAUX;

		Context->count_DLT++;
		Context->DLT = lptr;
		Context->operation  = translate_dll_runtime;
		return(0);
		}
	return(syntax_error(3040));
}

WORD	translate_dll_description( filename )
BPTR	filename;
{
	WORD	status;
	trace("translate_dll_description()\n");
	if (( filename != (BPTR) 0 )
	&&  (( status = include_source_file( filename, "def" )) != 0))
		return( status );

	push_operation_pointer();
	set_operation_pointer(translate_dll_version);
	return(0);

}

VOID	liberate_dynamic_library(lptr)
TCDLBPTR	lptr;
{
	TCDLFPTR	fptr;
	if ( lptr != (TCDLBPTR) 0) {
		while ((fptr = lptr->function) != (TCDLFPTR) 0) {
			lptr->function = fptr->next;
			liberate( fptr );
			}
		if ( lptr->name != (BPTR) 0 )
			liberate( lptr->name );
		liberate( lptr );
		}
	return;
}

VOID	liberate_dynamic_libraries()
{
	TCDLBPTR	lptr;

	while ((lptr = Context->DLT) != (TCDLBPTR) 0) {
		Context->DLT = lptr->next;
		liberate_dynamic_library( lptr );
		}
	return;
}

WORD	add_dll_function( lptr, fptr )
TCDLBPTR	lptr;
TCDLFPTR	fptr;
{
	if ((fptr->next = lptr->function) != (TCDLFPTR) 0) {
		if ( fptr->identity == MOINS_UN )
			fptr->identity = (fptr->next->identity + 1);
		}
	else	fptr->identity = 0;
	lptr->function 	= fptr;
	return( fptr->identity );
}

VOID	add_dynamic_library(lptr)
TCDLBPTR	lptr;
{
	if ((lptr->prev = Context->XDLT) != (TCDLBPTR) 0) {
		lptr->identity = (lptr->prev->identity + 1);
		lptr->prev->next = lptr;
		}
	else	{
		Context->DLT = lptr;
		lptr->identity = 0;
		}
	Context->count_DLT++;
	Context->XDLT = lptr;
/*	sysprintf("Add User Library : %u \n",lptr->identity);	*/
	return;
}

TCDLFPTR	locate_dynamic_function( lptr, number )
TCDLBPTR	lptr;
WORD		number;
{
	TCDLFPTR	fptr;

	if ((fptr = lptr->function) != (TCDLFPTR) 0) {
		do	{
			if ( fptr->identity == number )
				break;
			}
		while ((fptr = fptr->next) != (TCDLFPTR) 0);
		}
	return( fptr );
}

	
TCDLBPTR	locate_dynamic_library( nptr )
BPTR		nptr;
{
	TCDLBPTR	lptr;
	BPTR		name;
	WORD		c;

	switch ((c = *nptr )) {
		case	'<'	:
			c = '>';
		case	'"'	:
			nptr++;
			name = nptr;
			while ((*nptr) && ( *nptr != c ))
				nptr++;
			*nptr = 0;
			nptr = name;
		}

	if ((lptr = Context->DLT) != (TCDLBPTR) 0) {
		do	{
			if ( compare_tokens( lptr->name, nptr ) ) {
				if ( lptr->version != MOINS_UN ) {
					(void) syntax_error(6244);
					lptr = (TCDLBPTR) 0;
					}
				return( lptr );
				}
			}
		while ((lptr = lptr->prev) != (TCDLBPTR) 0);
		}

	if (((lptr = allocate_for_dll()) != (TCDLBPTR) 0)
	&&  ((lptr->name = allocate_for_string( nptr )) != (BPTR) 0)) {
		lptr->version = MOINS_UN;
		lptr->access = Context->Visibility;
		add_dynamic_library( lptr );
		return( lptr );
		}
	else	liberate_dynamic_library( lptr );
	return( (TCDLBPTR) 0 );
}

LDFPTR	allocate_for_ldf()
{
	LDFPTR	lptr;

	if ((lptr = (LDFPTR) allocate( sizeof ( struct otr_dlf ) )) != (LDFPTR) 0) {
		lptr->root 	= (ARGPTR) 0;
		lptr->last	= (ARGPTR) 0;
		lptr->func	= (TCDLFPTR) 0;
		}
	return( lptr );
}

LDFPTR	start_ldf( fptr )
TCDLFPTR	fptr;
{
	LDFPTR	lptr;
	trace("start_ldf()\n");
	if ((lptr = allocate_for_ldf()) != (LDFPTR) 0)
		lptr->func = fptr;
	return( lptr );
}

#ifdef	_BEFORE_19031998

BPTR	ldf_target( xptr )
LDFPTR		xptr;
{
	BPTR		rptr=(BPTR) 0;
	TCDLFPTR	fptr;
	trace("ldf_target()\n");
	if ((fptr = xptr->func) != (TCDLFPTR) 0) {
		switch ( fptr->type ) {
			case 0  :
			case 1  : rptr = "\0";
				  break;
			case 2  : rptr = NewBcdRegister();
				  break;
			case 3  : rptr = NewStringRegister(256);
				  break;
			default : break;
			}
		}
	return( rptr );

}

#else

BPTR		ldf_return_value( type )
WORD		type;
{
	BPTR	rptr=(BPTR) 0;
	switch ( type ) {
		case 0  :
		case 1  : rptr = "\0";
			  break;
		case 2  : rptr = NewBcdRegister();
			  break;
		case 3  : rptr = NewStringRegister(256);
			  break;
		default : break;
		}
	return( rptr );
}

BPTR		ldf_target( xptr )
LDFPTR		xptr;
{
	TCDLFPTR	fptr;
	trace("ldf_target()\n");
	if ((fptr = xptr->func) != (TCDLFPTR) 0)
		return( ldf_return_value( fptr->type ) );
	else	return( (BPTR) 0 );
}

#endif	/* _BEFORE_19031998 */
	/* ---------------- */

static	WORD	flush_ldf_parameter(lparam)
BPTR	lparam;
{
	if (lparam == (BPTR) 0)
		return( syntax_error(3040) );
	else	tcode_operand( lparam );
	return( 0 );
}

static	WORD	flush_ldf_parameters(xptr, iptr, rptr )
LDFPTR		xptr;
BPTR	iptr;
BPTR	rptr;
{
	ARGPTR		cptr;
	WORD		status=0;
	if ( rptr != (BPTR) 0)
		flush_ldf_parameter( rptr );
	if ( iptr != (BPTR) 0)
		flush_ldf_parameter( iptr );
	if ((cptr = xptr->root) != (ARGPTR) 0) {
		do	{
			if ((status = flush_ldf_parameter( cptr->operand )) != 0)
				return( status );
			}
		while ((cptr = cptr->next) != (ARGPTR) 0);
		}
	return( 0 );
}


BPTR	flush_integer_ldf( xptr )
LDFPTR		xptr;
{
	BPTR		rptr;
	ARGPTR		cptr;
	WORD		status=0;
	WORD		nombre=0;
	BPTR		vptr;

	if ((rptr = open_rtlclf( xptr->func->name )) == (BPTR) 0)
		return( rptr );

	if ((cptr = xptr->root) != (ARGPTR) 0) {
		do	{
			if ((vptr = cptr->operand) != (BPTR) 0) {
				if ( *vptr == '#' )
					vptr += 2;
				if ((rptr = add_rtlclf(rptr, vptr, nombre++ )) == (BPTR) 0)
					return( rptr );
				}
			}
		while ((cptr = cptr->next) != (ARGPTR) 0);
		}
	return(( rptr = close_rtlclf(rptr)));
}

BPTR	flush_string_ldf( xptr, wptr )
LDFPTR		xptr;
BPTR		wptr;
{
	BPTR		rptr;
	BPTR		vptr;
	ARGPTR		cptr;
	WORD		status=0;
	WORD		nombre=0;

	if ((rptr = open_rtlclf( xptr->func->name )) == (BPTR) 0)
		return( rptr );

	if ( wptr != (BPTR) 0) 
		if ((rptr = add_rtlclf(rptr, wptr, nombre++ )) == (BPTR) 0)
			return( rptr );
	if ((cptr = xptr->root) != (ARGPTR) 0) {
		do	{
			if ((vptr = cptr->operand) != (BPTR) 0) {
				if ( *vptr == '#' )
					vptr += 2;
				if ((rptr = add_rtlclf(rptr, vptr, nombre++ )) == (BPTR) 0)
					return( rptr );
				}
			}
		while ((cptr = cptr->next) != (ARGPTR) 0);
		}
	if ((rptr = close_rtlclf(rptr)) == (BPTR) 0)
		return( rptr );
	output_rtlclf( rptr );
	return( wptr );
}

BPTR	flush_ldf( xptr, iptr )
LDFPTR		xptr;
BPTR	iptr;
{
	BPTR	rptr=(BPTR) 0;
	trace("flush_ldf()\n");
	if ((rptr = ldf_target(xptr)) != (BPTR) 0) {
		if ( xptr->func->usage == 0 )
			rtl_function_prototype( xptr->func );
		xptr->func->usage++;
		xptr->func->library->usage++;
		if ( strlen(rptr) == 0 )
			return( flush_integer_ldf( xptr,iptr ) );
		else	return( flush_string_ldf( xptr, rptr ) );
		}
	else	return( rptr );
}

BPTR		flush_indirect_ldf( xptr, iptr, tptr )
LDFPTR		xptr;
BPTR 		iptr;
TCTYPPTR	tptr;
{
	BPTR		rptr=(BPTR) 0;
	WORD		status;
	trace("flush_ldf()\n");
	if (((rptr = ldf_return_value(tptr->type)) != (BPTR) 0)
	&&  ((status = flush_ldf_parameters(xptr,iptr, rptr ))   == 0))
		return( rptr );
	else	return( rptr );
	return( rptr );
}

WORD		flush_void_ldf( xptr, iptr )
LDFPTR		xptr;
BPTR	iptr;
{
	TCDLFPTR	fptr;
	WORD		status=0;
	trace("flush_void_ldf()\n");
	if   ((status = flush_ldf_parameters(xptr,iptr, (BPTR) 0 ))   == 0)
		return( status );
	else	return( status );
}

WORD		store_ldf(xptr, rptr )
LDFPTR		xptr;
BPTR	rptr;
{
	ARGPTR	cptr;
	trace("store_ldf()\n");
	if ((cptr = allocate_for_operand()) == (ARGPTR) 0)
		return( allocation_failure() );
	cptr->operand = rptr;
	if ((cptr->prev = xptr->last) == (ARGPTR) 0)
		xptr->root = cptr;
	else	xptr->last->next = cptr;
	xptr->last = cptr;
	return( 0 );
}


BPTR	evaluate_dll_function( fptr )
TCDLFPTR	fptr;
{
	TCVARPTR	vptr;
	BPTR		rptr=(BPTR) 0;
	BPTR		iptr=(BPTR) 0;
	LDFPTR		xptr;
	WORD		vlen;
	trace("evaluate_dll_function()\n");

	if ((xptr = start_ldf( fptr )) == (LDFPTR) 0)
		return( (BPTR) 0 ); 

	if ((iptr = IntegerResult( fptr->identity )) == (BPTR) 0)
		return( iptr );

	vptr = fptr->parameter;

	if ( is_left_brace() ) {
		do	{
			if ( is_right_brace() ) {
				unget_byte();
				break;
				}
			else if ( vptr == (TCVARPTR) 0 ) {
				(void) syntax_error( 1040 );
				return((BPTR) 0);
				}
			else 	{
				switch ((vptr->type->type & 0x000F)) {
					case	8	:
					case	9	: rptr = VariableExpression((WPTR) & vlen); break;
					case	0	:
					case	1	: rptr = IntegerExpression(); break;
					case	0x000A	:
					case	2	: rptr = BcdExpression(); break;
					case	0x000B	:
					case	3	: rptr = StringExpression(); break;
					case	0x000F	:
					case	7	: rptr = EvaluateExpression(); break;
					default		: (void) syntax_error(3040);
							  return( (BPTR) 0);
					}
				if (rptr == (BPTR) 0)
					return( (BPTR) 0 );
				else	store_ldf( xptr, rptr );
				vptr = vptr->prev;
				}
			}
		while ( is_comma() );
		if (!( is_right_brace() )) { 
			(void) unmatched_braces();
			return((BPTR) 0 );
			}
		}

	return( flush_ldf( xptr, iptr ) );
}

WORD		activate_dll_function( fptr )
TCDLFPTR	fptr;
{
	BPTR	rptr=(BPTR) 0;
	BPTR	iptr=(BPTR) 0;
	LDFPTR		xptr;

	trace("activate_dll_function()\n");

	if ((xptr = start_ldf( fptr )) == (LDFPTR) 0)
		return( allocation_failure() ); 

	if ((iptr = IntegerResult( fptr->identity )) == (BPTR) 0)
		return( syntax_error(3040) );

	if ( is_left_brace() ) {
		do	{
			if ( is_right_brace() ) {
				unget_byte();
				break;
				}
			else if ((rptr = EvaluateExpression()) == (BPTR) 0)
				return( syntax_error(3040) );
			else	store_ldf( xptr, rptr );
			}
		while ( is_comma() );
		if (!( is_right_brace() )) 
			return( unmatched_braces() );
		}

	return( flush_void_ldf( xptr, iptr ) );
}


#endif	/* _TRLDF_C */
	/* -------- */
