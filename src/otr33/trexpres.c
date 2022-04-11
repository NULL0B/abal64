/* #define      DEBUG */
/* -------------------------------------------------------------------- */
/*                                                                      */
/*              Project ABAL : Macro pre-processer                      */
/*                                                                      */
/*               Copyright (c) 1990, 1994 Amenesik / Sologic s.a.                 */
/*                                                                      */
/*                                                                      */
/*              File    :       TREXPRES.C                              */
/*              Version :       2.1d                                    */
/*              Date    :       08/12/1994                              */
/*                                                                      */
/* -------------------------------------------------------------------- */
#ifndef _TREXPRES_C
#define _TREXPRES_C

#include <stdio.h>              /* Standard IO handling routines        */
#include <errno.h>              /* Error return definitions             */
#include <string.h>
#include "stdtypes.h"
#include "translat.h"
#include "trshadow.h"
#include "trsyntax.h"
#include "trparser.h"
#include "trexpres.h"
#include "troption.h"
#include "trsymbol.h"
#include "trproc.h"		
#include "triof.h"
#include "troutput.h"
#include "trdebug.h"
#include "trclf.h"
#include "trldf.h"
#include "trmethod.h"
#include "trclass.h"		
#include "trerrors.h"	
#include "trtables.h"	
#include "trabal.h"		
#include "trecho.h"		


#ifndef UNIX
#else
RESULTPTR       primary_term();
TCVARPTR        copy_variable();
TCVARPTR        protect_variable();
TCTYPPTR        register_alias();
RESULTPTR       clf_reg_alias();
TCVARPTR        dcl_object_alias();
RESULTPTR       evaluate_object_operator();
RESULTPTR       evaluate_member_term();
VOID            shadow_variable();
RESULTPTR       build_numeric_term();
#endif

RESULTPTR       allocate_for_result()
{
	RESULTPTR       rptr;

	if ((rptr = ResultFree) != (RESULTPTR) 0 )
		ResultFree = ResultFree->next;
	else    {
		trace("allocate_for_result(");
		if ((rptr = (RESULTPTR) allocate( sizeof( struct otr_result ))) == (RESULTPTR) 0)
			return( rptr );
		}
	rptr->nature  = MOINS_UN;
	rptr->value   = 0;
	rptr->contents= (VPTR) 0;
	rptr->next    = ResultUsed;
	ResultUsed    = rptr;
	return( rptr );
}

FACTORPTR       allocate_for_factor( operand, operation )
RESULTPTR       operand;
WORD            operation;
{
	FACTORPTR       fptr;
	if ((fptr = FactorHeap) != (FACTORPTR) 0)
		FactorHeap = fptr->next;
	else if (!( fptr = allocate( sizeof( struct otr_factor ) ) ))
		return( fptr );

	fptr->operation = operation;
	fptr->operand   = operand;
	fptr->previous  = fptr->next = (FACTORPTR) 0;
	return( fptr );
}

WORD    compare_types( lptr, rptr )
TCTYPPTR        lptr;
TCTYPPTR        rptr;   /* Type Required by strict method */
{
	trace("compare_types()\n");

/*      sysprintf("CompareTypes( %x =?= %x )\n",lptr->type,rptr->type); */

	if (!( rptr->type & _TYPE_DEFINED )) {
		if (( rptr->type & _TYPE_BASIC ) != ( lptr->type & _TYPE_BASIC ))
			return( FAUX );
		else    return( VRAI );
		}
	else    {
		if (( lptr->type & _TYPE_DEFINED )
		&&  ( OtrOption.Enhanced & _ENHANCED_STRICT ))
			return( compare_classes( lptr->class, rptr->class ) );
		else if (( lptr->type & _TYPE_BASIC ) == _TYPE_STRING )
			return( VRAI );
		else    return( FAUX );
		}
}

RESULTPTR       allocate_protected_result( sptr )
RESULTPTR       sptr;
{
	RESULTPTR       rptr;

	trace("allocate_protected_result()\n");

	if ((rptr = ResultFree) != (RESULTPTR) 0 )
		ResultFree = ResultFree->next;
	else if ((rptr = (RESULTPTR) allocate( sizeof( struct otr_result ))) == (RESULTPTR) 0)
		return( rptr );

	rptr->next      = (RESULTPTR) 0;
	rptr->value     = sptr->value;
	rptr->nature    = sptr->nature;

	switch ((rptr->nature & _RESULT_BASIC)) {
		case _RESULT_INT   :    break;
		case _RESULT_EXPR  : 
			rptr->contents = (VPTR) lock_register( sptr->contents );
			break;
		case _RESULT_CONST :    
			rptr->contents = sptr->contents;
			break;
		case _RESULT_VARB  :    
			rptr->contents = sptr->contents;
			break;
		default            :
			(void) internal_error( 4733 );
			break;
		}
	return( rptr );

}


VOID    transfer_result( tptr, sptr )
RESULTPTR       tptr;
RESULTPTR       sptr;
{
/*      sysprintf("transfer_result(%x <- %x)\n",tptr->nature,sptr->nature);        */
	tptr->value    = sptr->value;
	tptr->contents = sptr->contents;
	tptr->nature   = sptr->nature;
	if ( OtrOption.ListFlag  & 1 ) {
		switch ( tptr->nature ) {
			case	_RESULT_VPTR :
			case    _RESULT_VARB :  
				set_shadow_variable( tptr->contents, sptr->contents );
				break;
			case    _RESULT_CONST :
				set_shadow_constant( tptr->contents, sptr->contents );
				break;
			case    _RESULT_EXPR  :
				set_shadow_register( tptr->contents, sptr->contents );
				break;
			}
		}
	return;
}

VOID            release_result( rptr ) 
RESULTPTR       rptr;
{
	rptr->next = ResultFree;
	ResultFree = rptr;
	return;
}

VOID            forget_protected_result( sptr )
RESULTPTR       sptr;
{
	switch (( sptr->nature & _RESULT_BASIC)) {
		case _RESULT_VARB  : 
		case _RESULT_INT   : 
		case _RESULT_CONST : 
			break;
		case _RESULT_EXPR  :
			unlock_register( sptr->contents );
			break;
		}
	sptr->next    = ResultUsed;
	ResultUsed    = sptr;
	return;
}

WORD    is_constant_expression( lptr )
RESULTPTR       lptr;
{
	if (( lptr->nature == _RESULT_INT )
	||  ( lptr->nature == _RESULT_CONST ))
		return( VRAI );
	else    return( FAUX );
}

VOID            initialise_expressions()
{
	FactorHeap   = (FACTORPTR) 0;
	ResultFree   = (RESULTPTR) 0;
	ResultUsed   = (RESULTPTR) 0;
	initialise_shadower();
	initialise_variables();
	return;
}

VOID    release_expressions(mode)
WORD    mode;
{
	RESULTPTR       rptr;
	trace("release_expressions()\n");
	while ((rptr = ResultUsed) != (RESULTPTR) 0) {
		ResultUsed = ResultUsed->next;
		release_result( rptr );
		}
	if ( mode ) {
		reset_shadower();
		release_variables();
		}
	return;
}

RESULTPTR       lock_used_results()
{
	RESULTPTR       rptr=ResultUsed;
	trace("lock_used_results()\n");
	ResultUsed = (RESULTPTR) 0;
	return( rptr );
}

VOID    unlock_used_results(rptr)
RESULTPTR       rptr;
{
	trace("unlock_used_results()\n");
	release_expressions(0);
	ResultUsed = rptr;
	return;
}

VOID            liberate_expressions()
{
	RESULTPTR       rptr;
	FACTORPTR	fptr;
	release_expressions(VRAI);
	while ((rptr = ResultFree) != (RESULTPTR) 0) {
		ResultFree = ResultFree->next;
		liberate( rptr );
		}
	while ((fptr = FactorHeap) != (FACTORPTR) 0) {
		FactorHeap = FactorHeap->next;
		liberate( fptr );
		}
	terminate_shadower();
	liberate_variables();
	return;
}

WORD		constant_value( cptr )
TCCONPTR        cptr;
{
	BPTR	sptr;
	WORD	slen;
	WORD	v=0;
	if (!( cptr ))
		return( MOINS_UN );
	else	{
		switch (( cptr->type->type & _TYPE_BASIC )) {
			case	_TYPE_INT8	:
			case	_TYPE_INT16	:
			case	_TYPE_INT32	:
				return( cptr->identity );
			case	_TYPE_STRING	:
				sptr=cptr->value; slen=cptr->length; v = 0;
				while (( *sptr == ' ' ) && ( slen != 0)) {
					sptr++; slen--;
					}
				while (( *sptr >= '0' ) && ( *sptr <= '9') && ( slen != 0)) {
					v = ((v*10) + (*(sptr++) - '0'));
					slen--;
					}
				return( v );

			case	_TYPE_NUMERIC	:
			default			:
				return( MOINS_UN );
			}
		}
}

RESULTPTR       constant_result( cptr )
TCCONPTR        cptr;
{
	RESULTPTR       rptr=(RESULTPTR) 0;
	trace("constant_result()\n");
	if (!( cptr ))
		return( rptr );
#ifndef	otr32
	else if (!(cptr = redirect_local_constant( cptr )))
		return( rptr );
#endif
	else if  (!(rptr = allocate_for_result()))
		return( rptr );
	else	{
		if (( cptr->type->type & 3 ) < 2) {
			rptr->nature   = _RESULT_INT;
			rptr->value    = cptr->identity;
			rptr->contents = (VPTR) cptr;
			}
		else    {
			rptr->nature   = _RESULT_CONST;
			rptr->value    = cptr->identity;
			rptr->contents = (VPTR) cptr;
			}
		return( rptr );
		}
}


RESULTPTR       implicite_constant(type)
WORD            type;
{
	TCCONPTR        cptr;
	trace("implicite_constant()\n");
	unget_byte();
	if ((cptr = build_implicite_constant(type)) != (TCCONPTR) 0) 
		return( constant_result( cptr ) );
	else    return((RESULTPTR) 0);
}
	
/*      EXPRESSION ANALYSIS SECTION
 *      ---------------------------
 */

RESULTPTR       next_free_register()
{
	RESULTPTR       rptr;
	SHADOWPTR       sptr;
	trace("next_free_register()\n");
	if ((rptr = allocate_for_result()) != (RESULTPTR) 0) {
		rptr->nature = _RESULT_EXPR;
		if ((sptr = allocate_new_register()) == (SHADOWPTR) 0)
			return((RESULTPTR) 0);
		rptr->contents = (VPTR) sptr;
		rptr->value  = sptr->number;
		}
	return( rptr );
}

RESULTPTR       ensure_register( xterm )
RESULTPTR       xterm;
{
	RESULTPTR       rterm;
	if ((xterm->nature & _RESULT_BASIC) == _RESULT_EXPR) {
		pop_live_register( xterm->contents );
		return( xterm );
		}
	else if ((rterm = next_free_register()) == (RESULTPTR) 0)
		return( rterm );
	else    return( (xterm = generate_register_load( rterm, xterm,(xterm->nature & _RESULT_VPT))) );
}

extern	BPTR	LinePointer;

RESULTPTR	negate_constant( rptr )
RESULTPTR	rptr;
{
	TCCONPTR	cptr;
	TCTYPPTR	tptr;
	BPTR		wptr;
	if (!(cptr = (TCCONPTR) rptr->contents))
		return( rptr );
	else if (!(tptr = (TCTYPPTR) cptr->type))
		return( rptr );
	else if (( tptr->type & _TYPE_BASIC ) != _TYPE_NUMERIC )
		return( rptr );

	else if (!( wptr = allocate( strlen( TokenBuffer ) + 8 ) ))
		return( rptr );
	else	{
		sprintf(wptr,"-%s",TokenBuffer);
		rptr->contents = (VOID*)0;
		build_numeric_term( rptr, wptr );
		liberate( wptr );
		return( rptr );
		}
}

RESULTPTR       negate_expression( rptr )
RESULTPTR       rptr;
{
/*
	sysprintf("negate expression in ( %s ) \n",LinePointer);
 */
	switch (( rptr->nature & _RESULT_BASIC)) {

		case _RESULT_INT :

			rptr->value = -rptr->value;
			break;

		case _RESULT_CONST : 
			/* negation of a constant should be performed now */
			/* ---------------------------------------------- */
			rptr = negate_constant( rptr );
			break;

		case _RESULT_VARB  : 

			if ((rptr = ensure_register( rptr)) == (RESULTPTR) 0)
				break;

		case _RESULT_EXPR  : 
			negate_register( rptr );
			break;

		}
	return( rptr );
}

RESULTPTR       expression_term()
{
	RESULTPTR       tptr=(RESULTPTR) 0;

	if ( is_left_brace() ) {
		if (!( tptr = evaluate_expression(0) ))
			return( tptr );
		else if (!( is_right_brace() ))
			return((RESULTPTR) 0);
		else	return( tptr );
		}
	else if ( is_minus() ) {
		if ( is_left_brace() ) {
			if (!(tptr = evaluate_expression(0) ))
				return( tptr );
			else if (!( is_right_brace() ))
				return((RESULTPTR) 0);
			else	return( negate_expression( tptr ) );
			}
		else if (!( get_token() ))
			return((RESULTPTR) 0);
		else if (!( tptr = primary_term() ))
			return( tptr );
		else	return( negate_expression( tptr ) );
		}
	else if ( is_plus() )
		return( evaluate_expression(0)  );
	else    return( (RESULTPTR) 0 );
}


WORD    constant_type( cptr )
TCCONPTR        cptr;
{
	if ((cptr != (TCCONPTR) 0)
	&&  (cptr->type != (TCTYPPTR) 0))
		return((cptr->type->type & _TYPE_BASIC));
	else    return( MOINS_UN );
}

WORD    variable_type( vptr )
TCVARPTR        vptr;
{
	if ((vptr != (TCVARPTR) 0)
	&&  (vptr->type != (TCTYPPTR) 0))
		return((vptr->type->type & _TYPE_BASIC));
	else    return( MOINS_UN );
}

WORD    result_type( rptr )
RESULTPTR       rptr;
{
	switch (( rptr->nature & _RESULT_BASIC)) {
#ifdef	otr32
		case _RESULT_INT   : return( _TYPE_INT16 );
#else
		case _RESULT_INT   : return( _TYPE_INT16 );
#endif
		case _RESULT_CONST : return( constant_type( rptr->contents ) );
		case _RESULT_VARB  : return( variable_type( rptr->contents ) );
		case _RESULT_EXPR  : return( register_type( rptr->contents ) );
		default            : return( MOINS_UN );
		}
}

WORD	check_case_operator( rptr, operator )
RESULTPTR	rptr;
WORD		operator;
{
	if (( operator != _CMP_IN )
	&&  ( operator != _CMP_NI ))
		return( operator );
	switch ( result_type( rptr ) ) {
		case _TYPE_STRING	:
			return( operator );
		default			:
			return( (operator == _CMP_IN ? _CMP_EQ : _CMP_NE) );
		 }
}


WORD    verify_result_type( rptr, type )
RESULTPTR       rptr;
TCTYPPTR        type;
{
	TCCONPTR        cptr;
	TCVARPTR        vptr;

	trace("verify_result_type()\n");

	switch (( rptr->nature & _RESULT_BASIC )) {

		case _RESULT_INT   : 
			if (( type->type & _TYPE_BASIC ) < _TYPE_NUMERIC )
				return( VRAI );
			else    return( FAUX );

		case _RESULT_CONST : 
			if ((cptr = (TCCONPTR) rptr->contents) == (TCCONPTR) 0)
				return( FAUX );
			else if (cptr->type == (TCTYPPTR) 0)
				return( FAUX );
			else    return( compare_types( cptr->type, type ) );

		case _RESULT_VARB  :
			if (((vptr = (TCVARPTR) rptr->contents) == (TCVARPTR) 0)
			||  (vptr->type == (TCTYPPTR) 0))
				return( FAUX );
			else    return( compare_types( vptr->type, type ) );

		case _RESULT_EXPR    : 
			return( verify_register_type( rptr->contents, type ) );

		default            : return( MOINS_UN );
		}

}


RESULTPTR       build_string_constant( tptr, token )
RESULTPTR       tptr;
BPTR            token;
{
	TCCONPTR        cptr;

	if ((cptr = build_explicite_constant( 3, token )) != (TCCONPTR) 0) { 
		tptr->nature   = _RESULT_CONST;
		tptr->value    = cptr->identity;
		tptr->contents = (VPTR) cptr;
		}
	else    (void) syntax_error(3733);
	return( tptr );
}

RESULTPTR       build_numeric_term( tptr, token )
RESULTPTR       tptr;
BPTR            token;
{
	TCCONPTR        cptr;

	if ((cptr = build_explicite_constant( 2, token )) != (TCCONPTR) 0) { 
		tptr->nature   = _RESULT_CONST;
		tptr->value    = cptr->identity;
		tptr->contents = (VPTR) cptr;
		}
	else    (void) syntax_error(3734);
	return( tptr );
}


RESULTPTR	numeric_term()
{
	RESULTPTR       tptr=(RESULTPTR) 0;
	WORD            c;

	if ((c = is_numeric_token( TokenBuffer )) != 0) {
		if ((tptr = allocate_for_result()) == (RESULTPTR) 0)
			(void) allocation_failure();
		else    {
			if (( c == '/' ) || ( is_integer(TokenBuffer) )) {
				tptr->nature = _RESULT_INT;
				tptr->value  = convert_numeric_token( TokenBuffer );
				}
			else    tptr = build_numeric_term( tptr,TokenBuffer );
			return( tptr );
			}
		}
	return((RESULTPTR) 0);
}

RESULTPTR       constant_term()
{
	RESULTPTR       tptr=(RESULTPTR) 0;
	WORD            c;

	trace("constant_term()\n");

	if ((c = is_string_token( TokenBuffer )) != 0) {
		if ((tptr = allocate_for_result()) == (RESULTPTR) 0) {
			(void) allocation_failure();
			return((RESULTPTR) 0);
			}
		else    return( build_string_constant( tptr, TokenBuffer ) );
		}

	else 	return( numeric_term() );

}

RESULTPTR       alias_result( vptr )
TCVARPTR        vptr;
{
	RESULTPTR       rptr;
	if ((rptr = variable_result( vptr )) != (RESULTPTR) 0)
		rptr->nature |= _RESULT_POINTER;
	return( rptr );
}

RESULTPTR       procedure_result( tptr )
TCTYPPTR        tptr;
{
	RESULTPTR       rptr=(RESULTPTR) 0;

	if ((rptr = next_free_register()) != (RESULTPTR) 0) {
		rptr->nature   = _RESULT_EXPR;
		rptr->contents = (VPTR) set_shadow_type( rptr->contents, ( tptr->type & 3)  );
		generate_copy_register( rptr->value, _EXIT_REGISTER );
		if (( tptr->type & _TYPE_POINTER) == _TYPE_POINTER) {
			rptr->nature |= _RESULT_ALEXPR;
			(void) shadow_alias_register( rptr->contents, tptr );
			}
		if ( OtrOption.ListFlag & 1 )
			set_shadow_text( rptr->contents );
		if ( rptr != (RESULTPTR) 0 )
			rptr = mark_live_result( rptr );
		}
	return( rptr );
}

RESULTPTR       string_result( sptr )
BPTR            sptr;
{
	RESULTPTR       rptr;
	if ((rptr = allocate_for_result()) != (RESULTPTR) 0)
		rptr = build_string_constant( rptr, sptr );
	return( rptr );
}

RESULTPTR       numeric_result( sptr )
BPTR            sptr;
{
	RESULTPTR       rptr;
	if ((rptr = allocate_for_result()) != (RESULTPTR) 0)
		rptr = build_numeric_term( rptr, sptr );
	return( rptr );
}

RESULTPTR       integer_result( value )
WORD            value;
{
	RESULTPTR       tptr=(RESULTPTR) 0;
	if ((tptr = allocate_for_result()) != (RESULTPTR) 0) {
		tptr->nature = _RESULT_INT;
		tptr->value  = value;
		}
	return( tptr );
}

RESULTPTR       codeptr_result( value, nature, vptr )
WORD            value;
WORD            nature;
VPTR		vptr;
{
	RESULTPTR       tptr=(RESULTPTR) 0;
	if ((tptr = allocate_for_result()) != (RESULTPTR) 0) {
		tptr->nature   = (_RESULT_INT | nature);
		tptr->value    = value;
		tptr->contents = vptr;
		}
	return( tptr );
}


WORD    procedure_exit( pptr )
TCPRCPTR        pptr;
{
	WORD            status;
	RESULTPTR       rptr;
	TCTYPPTR        tptr;

	if (( pptr == (TCPRCPTR) 0 )
	||  ((tptr = pptr->result) == (TCTYPPTR) 0 ))
		return( generate_exit((RESULTPTR) 0) );

	switch ( (tptr->type &  (_TYPE_POINTER | _TYPE_BASIC)) ) {
		case    _TYPE_INT8      :
		case    _TYPE_INT16     : 
		case    _TYPE_INT32     : 
		
			if ((rptr = integer_result( 0 )) == (RESULTPTR) 0)
				return( allocation_failure() );
			else    break;
	
		case    _TYPE_NUMERIC   :
			if ((rptr = numeric_result( "0" )) == (RESULTPTR) 0)
				return( allocation_failure() );
			else    break;

		case    _TYPE_STRING    :
			if ((rptr = string_result( " " )) == (RESULTPTR) 0)
				return( allocation_failure() );
			else    break;
	
		default                 :
			/* All Pointers return ALIAS(NULL) */
			if ((rptr = integer_result( 0 )) == (RESULTPTR) 0)
				return( allocation_failure() );
			else    break;
	

		}

	if ((status = translate_function_exit( rptr, tptr )) != 0)
		return( status );
	else    return( 0 );
}

RESULTPTR       evaluate_procedure( pptr, tptr, dtype )
TCPRCPTR        pptr;
RESULTPTR       tptr;
WORD		dtype;
{
	WORD            status;
	WORD            type;
	RESULTPTR       rptr=(RESULTPTR) 0;
	if (( pptr != (TCPRCPTR) 0 )
	&&  (!( pptr->options & _RETURN_PROC )))
		(void) syntax_error(3334);
	else    {
		if ((rptr = next_free_register()) != (RESULTPTR) 0) {
			rptr->nature   = _RESULT_EXPR;
			if ((status = activate_procedure(pptr,tptr,pptr)) != 0 ) {
				syntax_error(3335);
				return( (RESULTPTR) 0);
				}
			if ( pptr != (TCPRCPTR) 0) {
				type = (((pptr->options >> 8) & 0x0007) - 1);
				if (( pptr->result != (TCTYPPTR) 0)
				&&  ( pptr->result->type & 0x8000 ))
					type |= _RESULT_POINTER;
				}
			else    {
				issue_warning( 1 );
				type = dtype;
				}
			rptr->contents = (VPTR) set_shadow_type( rptr->contents, type  );
			if (!( OtrOption.InhibitAlias )) 
				if ( type & _RESULT_POINTER )
					rptr->nature |= _RESULT_POINTER; 
			generate_copy_register( rptr->value, _EXIT_REGISTER );
			}
		}
	return( rptr );
}

RESULTPTR       evaluate_extern_call_procedure( pptr, tptr, dtype )
TCPRCPTR        pptr;
RESULTPTR       tptr;
WORD		dtype;
{
	WORD            status;
	WORD            type;
	RESULTPTR       rptr=(RESULTPTR) 0;
	if (( pptr != (TCPRCPTR) 0 )
	&&  (!( pptr->options & _RETURN_PROC )))
		(void) syntax_error(3334);
	else    {
		if ((rptr = next_free_register()) != (RESULTPTR) 0) {
			rptr->nature   = _RESULT_EXPR;
			if ((status = activate_procedure((TCPRCPTR) 0,tptr,pptr)) != 0 ) {
				syntax_error(3335);
				return( (RESULTPTR) 0);
				}
			if ( pptr != (TCPRCPTR) 0) {
				type = (((pptr->options >> 8) & 0x0007) - 1);
				if (( pptr->result != (TCTYPPTR) 0)
				&&  ( pptr->result->type & 0x8000 ))
					type |= _RESULT_POINTER;
				}
			else    {
				issue_warning( 1 );
				type = dtype;
				}
			rptr->contents = (VPTR) set_shadow_type( rptr->contents, type  );
			if (!( OtrOption.InhibitAlias )) 
				if ( type & _RESULT_POINTER )
					rptr->nature |= _RESULT_POINTER; 
			generate_copy_register( rptr->value, _EXIT_REGISTER );
			}
		}
	return( rptr );
}

WORD    isok(mptr)
BPTR    mptr;
{
	sysprintf("%s\n",mptr);
	return( 1 );
}

RESULTPTR	extern_call_evaluate(TCPRCPTR pptr)
{
	RESULTPTR	rptr;
	TCVARPTR	vptr;

	WORD		type;
	trace("extern_call_evaluate()\n");
	if (!( pptr )) {
		syntax_error( 178 );
		return((RESULTPTR) 0);
		}
	else if (!( pptr->extcall )) {
		syntax_error( 178 );
		return((RESULTPTR) 0);
		}
	else if (!( pptr->extitem )) {
		syntax_error( 178 );
		return((RESULTPTR) 0);
		}
	else 	{
		type = (((pptr->options >> 8) & 0x0007) - 1);
		if ((!(vptr = temp_variable( pptr->extcall )))
		||  (!(vptr->firstdim = (VPTR) integer_result( pptr->extitem )))
		||  (!(rptr = variable_result( vptr ))))  {
			syntax_error( 178 );
			return((RESULTPTR) 0);
			}
		if ( OtrOption.ListFlag & 1 )
			set_echo_prefix();

		return( evaluate_extern_call_procedure(pptr, rptr, type) );
		}
}

static RESULTPTR	evaluate_procedure_symbol(TCPRCPTR pptr)
{
	RESULTPTR	rptr;

	if ( pptr->extcall != (TCVARPTR) 0 )
		return( extern_call_evaluate( pptr ) );
	else if ((rptr = integer_result( pptr->identity )) != (RESULTPTR) 0)
		return( evaluate_procedure( pptr,rptr,0 ) );
	else    {
		(void) allocation_failure();
		return((RESULTPTR) 0);
		}
}

RESULTPTR	symbolic_result()
{
	SYMBOLPTR       sptr;
	TCVARPTR        vptr;
	TCCONPTR        cptr;
	TCPRCPTR        pptr=(TCPRCPTR) 0;
	TCDLFPTR        fptr;
	WORD	seek_alternative=0;

	trace("symbolic_result()\n");

	/* Locate and Resolve Terminal Symbol */
	/* ---------------------------------- */
	for (	sptr = get_terminal_symbol();
		sptr != (SYMBOLPTR) 0;
		sptr = get_alternative_symbol(sptr)) {

		switch ( (sptr->type & 0X00FF) ) {

			case	SYMBOL_VARB	:

				consume_terminal_symbol();

				if ((!( vptr = (TCVARPTR) sptr->contents))
				||  (!( vptr->type			))
				||  (!( vptr = temp_variable( vptr )	))
				||  (!( vptr = collect_dimensions(vptr) ))) {
					(void) internal_error( 9200 );
					return((RESULTPTR) 0);
					}
				else    return( variable_result( vptr ) );

			case	SYMBOL_CONST	:
				consume_terminal_symbol();
				if (((cptr = (TCCONPTR) sptr->contents) == (TCCONPTR) 0)
				||  ( cptr->type == (TCTYPPTR) 0)) {
					(void) internal_error( 9201 );
					return( (RESULTPTR) 0 );
					}
				else    return( constant_result( cptr ) );

			case	SYMBOL_PROC	:
				if ((pptr = (TCPRCPTR) sptr->contents) == (TCPRCPTR) 0) {
					consume_terminal_symbol();
					(void) internal_error( 9202 );
					return( (RESULTPTR) 0 );
					}
				else if (!( OtrOption.DuplicateSymbols )) {
					consume_terminal_symbol();
					return( evaluate_procedure_symbol( pptr ) );
					}
				else	{
					seek_alternative=1;
					continue;
					}

			case	SYMBOL_USER	:
				consume_terminal_symbol();
				if ((fptr = (TCDLFPTR) sptr->contents) != (TCDLFPTR) 0)
					return( evaluate_dll_function( fptr ) );
				else    {
					(void) internal_error( 9203 );
					return( (RESULTPTR) 0 );
					}
			default	:
				consume_terminal_symbol();
				(void) internal_error( 9204 );
				return( (RESULTPTR) 0 );
			}
		}

	/* unknown symbol or alternative */ 

	consume_terminal_symbol();

	if ( seek_alternative ) {
		if (( pptr ) 
		&&  ( pptr->options & _RETURN_PROC )) 
			return( evaluate_procedure_symbol( pptr ) );
		else	(void) syntax_error(3334);
		}
	return( (RESULTPTR) 0 );
}

RESULTPTR    symbolic_term()
{
	RESULTPTR       tptr=(RESULTPTR) 0;
	TCVARPTR        vptr=(TCVARPTR)  0;
	TCCONPTR        cptr=(TCCONPTR)  0;
	TCPRCPTR        pptr=(TCPRCPTR)  0;
	TCDLFPTR        fptr=(TCDLFPTR)  0;
	WORD            type;

	trace("symbolic_term()\n");

	if ((tptr = object_symbolic_term(VRAI)) != (RESULTPTR) 0)
		return( tptr );

	else if ((tptr = symbolic_result()) != (RESULTPTR) 0)
		return( tptr );
	else    {
		switch (((type = is_control_keyword()))) {

			case _CTRL_EVENT :
			case MOINS_UN    :
				return((RESULTPTR) 0);

			case _CTRL_CALL :
				trace("ctrl_call");
				if ((is_left_brace())
				&&  ((tptr = evaluate_expression(0)) != (RESULTPTR) 0)
				&&  ( is_right_brace() ))
					return( evaluate_procedure( (TCPRCPTR) 0, tptr,1 ) );
			default         :
				(void) syntax_error(3336);
				return((RESULTPTR) 0);

			}
		}
	return( tptr );
}

VOID    initialise_symbolic_term()
{
	Context->symbolic_term  = symbolic_term;
	return;
}

RESULTPTR       primary_term()
{
	RESULTPTR       tptr=(RESULTPTR) 0;
	if ((tptr = constant_term()) != (RESULTPTR) 0)
		return( tptr );
	else if ((tptr = (RESULTPTR) (*Context->symbolic_term)()) != (RESULTPTR) 0)
		return( tptr );
	else if ((tptr = evaluate_clf()) != (RESULTPTR) 0)
		return( tptr );
	return( tptr );
}

RESULTPTR       primary_integer_term()
{
	RESULTPTR       tptr=(RESULTPTR) 0;
	WORD            HoldType;
	WORD            HoldDepth;

	HoldType 		= Context->ConvertType;
	HoldDepth 		= Context->Depth;
	Context->ConvertType 	= 1;
	Context->Depth 		= 0;
	tptr = primary_term();
	Context->ConvertType 	= HoldType;
	Context->Depth 		= HoldDepth;
	return( tptr );
}

RESULTPTR       evaluate_term()
{
	RESULTPTR       tptr=(RESULTPTR) 0;
	trace("evaluate_term()\n");
	if ((tptr = expression_term()) != (RESULTPTR) 0)
		return( tptr );
	else if (!( get_token() ))
		return( expression_term() );
	else    return( primary_term() );
}

TCVARPTR        is_variable_result( xterm )
RESULTPTR       xterm;
{
	TCVARPTR        vptr;
	if (((xterm->nature & _RESULT_BASIC) == _RESULT_VARB)
	&&  ((vptr = (TCVARPTR) xterm->contents) != (TCVARPTR) 0))
		return( vptr );
	else    return( (TCVARPTR) 0 );
}

WORD    is_string_variable( xterm )
RESULTPTR       xterm;
{
	TCVARPTR        vptr;
	if (((xterm->nature & _RESULT_BASIC) == _RESULT_VARB)
	&&  ((vptr = (TCVARPTR) xterm->contents) != (TCVARPTR) 0)
	&&  (vptr->type != (TCTYPPTR) 0)
	&&  ((vptr->type->type & _TYPE_STRING) == _TYPE_STRING))
		return( VRAI );
	else    return( FAUX );
}

WORD    is_string_constant( xterm )
RESULTPTR       xterm;
{
	TCCONPTR        vptr;
	if ((xterm->nature == _RESULT_CONST)
	&&  ((vptr = (TCCONPTR) xterm->contents) != (TCCONPTR) 0)
	&&  (vptr->type != (TCTYPPTR) 0)
	&&  ((vptr->type->type & _TYPE_STRING) == _TYPE_STRING))
		return( VRAI );
	else    return( FAUX );
}


WORD    is_string_register( xterm )
RESULTPTR       xterm;
{
	if  (((xterm->nature & _RESULT_BASIC) == _RESULT_EXPR)
	&&   (is_shadow_string(xterm->contents)))
		return( VRAI );
	else    return( FAUX );
}


RESULTPTR       incrementation( xterm )
RESULTPTR       xterm;
{
	if ((xterm = ensure_register( xterm )) == (RESULTPTR) 0)
		return( xterm );
	else    return( generate_increment( xterm ) );
}

RESULTPTR       convert_to_string( xterm )
RESULTPTR       xterm;
{
	if ((xterm = ensure_register( xterm )) == (RESULTPTR) 0)
		return( xterm );
	else    return( generate_conversion( xterm, _TYPE_STRING ) );
}

WORD    is_string_operand( xterm )
RESULTPTR       xterm;
{
	if ((is_string_variable( xterm ))
	||  (is_string_constant( xterm ))
	||  (is_string_register( xterm )))
		return( VRAI );
	else    return( FAUX );
}

WORD    is_numeric_operand( xterm )
RESULTPTR       xterm;
{
	if ( result_type( xterm ) == 2 )
		return( VRAI );
	else    return( FAUX );
}


RESULTPTR       ensure_string( xterm )
RESULTPTR       xterm;
{
	if ( is_string_operand( xterm ) )
		return( xterm );
	else if ( OtrOption.Enhanced & _ENHANCED_AUTOCONV )
		return( convert_to_string(xterm) );
	else    {
		incorrect_data_type();
		return(xterm ); 
		}
}

WORD    is_integer_variable( xterm )
RESULTPTR       xterm;
{
	TCVARPTR        vptr;
	if (((xterm->nature & _RESULT_BASIC) == _RESULT_VARB)
	&&  ((vptr = (TCVARPTR) xterm->contents) != (TCVARPTR) 0)
	&&  (vptr->type != (TCTYPPTR) 0)
	&&  ((vptr->type->type & 0x0003) < 2))
		return( VRAI );
	else    return( FAUX );
}

WORD    is_integer_register( xterm )
RESULTPTR       xterm;
{
	if  (((xterm->nature & _RESULT_BASIC) == _RESULT_EXPR)
	&&   (is_shadow_integer(xterm->contents)))
		return( VRAI );
	else    return( FAUX );
}

RESULTPTR       convert_to_integer( xterm )
RESULTPTR       xterm;
{
	if ((xterm = ensure_register( xterm )) == (RESULTPTR) 0)
		return( xterm );
	else    return( generate_conversion( xterm, 1 ) );
}

WORD    is_integer_operand( xterm )
RESULTPTR       xterm;
{
	if ((xterm->nature == _RESULT_INT)
	||  (is_integer_variable( xterm ))
	||  (is_integer_register( xterm )))
		return( VRAI );
	else    return( FAUX );
}

RESULTPTR       ensure_integer( xterm )
RESULTPTR       xterm;
{
	if ( is_integer_operand( xterm ) )
		return( xterm );
	else if ( OtrOption.Enhanced & _ENHANCED_AUTOCONV )
		return( convert_to_integer(xterm) );
	else    {
		incorrect_data_type();
		return(xterm ); 
		}
}

RESULTPTR	enforce_integer( xterm )
RESULTPTR	xterm;
{
	WORD	holder=OtrOption.Enhanced;
	OtrOption.Enhanced &=  ~ _ENHANCED_AUTOCONV;
	xterm = ensure_integer( xterm );
	OtrOption.Enhanced = holder;
	return( xterm );
}

RESULTPTR	enforce_string( xterm )
RESULTPTR	xterm;
{
	WORD	holder=OtrOption.Enhanced;
	OtrOption.Enhanced &=  ~ _ENHANCED_AUTOCONV;
	xterm = ensure_string( xterm );
	OtrOption.Enhanced = holder;
	return( xterm );
}


RESULTPTR       convert_to_type( xterm, type )
RESULTPTR       xterm;
WORD            type;
{
	BYTE    buffer[16];
	if (xterm->nature == _RESULT_INT) {
#ifdef	otr32
		sprintf(buffer,"%ld",xterm->value);
#else
		sprintf(buffer,"%d",((int) ((short)xterm->value)));
#endif
		if ( type == 3 )
			return( build_string_constant( xterm, buffer ) );
		else if ( type == 2 )
			return( build_numeric_term( xterm, buffer ) );
		else    return( xterm );
		}
	else if ((xterm = ensure_register( xterm )) == (RESULTPTR) 0)
		return( xterm );
	else    return( generate_conversion( xterm, type ) );
}

RESULTPTR       ensure_numeric( xterm )
RESULTPTR       xterm;
{
	if ( is_numeric_operand( xterm ) )
		return( xterm );
	else if ( OtrOption.Enhanced & _ENHANCED_AUTOCONV )
		return( convert_to_type(xterm,_TYPE_NUMERIC) );
	else    {
		incorrect_data_type();
		return(xterm ); 
		}
}

WORD		fundemental_type( datatype )
WORD		datatype;
{
	switch ( datatype & _TYPE_BASIC ) {
		case    _TYPE_INT8      :
		case    _TYPE_INT16     : 
		case    _TYPE_INT32     : 
			return(_TYPE_INT16);
		case	_TYPE_NUMERIC	:
			return(_TYPE_NUMERIC);
		case	_TYPE_STRING	:
			return(_TYPE_STRING);
		default			:
			return(0);
		}
}

WORD		normalised_type( datatype )
WORD		datatype;
{
	return((datatype & _TYPE_BASIC ));
}


RESULTPTR       ensure_numeric_term( lterm , rterm )
RESULTPTR  	lterm;
RESULTPTR       rterm;
{
	/* lterm must be converted to match rterm */
	/* -------------------------------------- */
	switch ((lterm->nature & _RESULT_BASIC)) {
		case _RESULT_INT   :
#ifdef	otr32
			sprintf(TokenBuffer,"%ld",lterm->value);
#else
			sprintf(TokenBuffer,"%d",lterm->value);
#endif
			build_numeric_term( lterm,TokenBuffer);
			break;

		case _RESULT_EXPR  : 
		case _RESULT_CONST :    
		case _RESULT_VARB  :    
			/* exa can manage it */			
			break;
		default            :
			(void) internal_error( 4733 );
			break;
		}
	return( rterm );
}

RESULTPTR	ensure_matching_type( lterm, rterm )
RESULTPTR	lterm;
RESULTPTR	rterm;
{
	WORD    lt;
	WORD    rt;

	if ((lt = result_type( lterm )) == 0)
		lt = _TYPE_INT16;
	if ((rt = result_type( rterm )) == 0)
		rt = _TYPE_INT16;

	if ( lt != rt ) {
		switch ( lt ) {
			case    _TYPE_INT8      :
				switch ( rt ) {
					case    _TYPE_INT8      :
					case    _TYPE_INT16     : 
					case    _TYPE_INT32     : 
						return( rterm );
					case	_TYPE_NUMERIC	:
						return( ensure_numeric_term( lterm, rterm ) );
					}
				break;
			case    _TYPE_INT16     : 
				switch ( rt ) {
					case    _TYPE_INT8      :
					case    _TYPE_INT16     : 
					case    _TYPE_INT32     : 
						return( rterm );
					case	_TYPE_NUMERIC	:
						return( ensure_numeric_term( lterm, rterm ) );
					}
				break;
			case    _TYPE_INT32     : 
				switch ( rt ) {
					case    _TYPE_INT8      :
					case    _TYPE_INT16     : 
					case    _TYPE_INT32     : 
						return( rterm );
					case	_TYPE_NUMERIC	:
						return( ensure_numeric_term( lterm, rterm ) );
					}
				break;
			}				
		/* check for and avoid constant and integral auto conv warning etc */
		/* --------------------------------------------------------------- */		
		switch ( rterm->nature ) {

			case _RESULT_INT   :
			case _RESULT_CONST :

				if ((rterm = convert_to_type( rterm, lt )) == (RESULTPTR) 0)
					(void) syntax_error(3338);                      
				break;

			case _RESULT_VPTR  :
			case _RESULT_VARB  :
			case _RESULT_ALIAS :
			case _RESULT_ALEXPR  :
			case _RESULT_EXPR  :

				if (!( OtrOption.Enhanced & _ENHANCED_AUTOCONV ))
					(void) syntax_error(3337);                      
				else if ((rterm = convert_to_type( rterm, lt )) == (RESULTPTR) 0)
					(void) syntax_error(3338);                      
				else	break;
/*				else    (void) issue_warning( 2 );	*/
			}
		}
	return( rterm );
}

WORD    result_is_one( xterm )
RESULTPTR       xterm;
{
	if (( xterm->nature == _RESULT_INT )
	&&  ( xterm->value  == 1 ))
		return( VRAI );
	else    return( FAUX );
}

WORD    result_is_zero( xterm )
RESULTPTR       xterm;
{
	if (( xterm->nature == _RESULT_INT )
	&&  ( xterm->value  == 0 ))
		return( VRAI );
	else    return( FAUX );
}

WORD    constant_folding( operation, lterm, rterm )
WORD            operation;
RESULTPTR       lterm;
RESULTPTR       rterm;
{
	if (( lterm->nature == _RESULT_INT )
	&&  ( rterm->nature == _RESULT_INT )) {
#ifndef	otr32
		if (( operation == '*' )
		||  ( operation == '+' )) {
			if ( integer_overflow(operation,  lterm->value, rterm->value ) )
				return( MOINS_UN );

			}
#endif
		lterm->value = evaluate_integer( operation, lterm->value, rterm->value );
		return( VRAI );
		}
	else    return( FAUX );
}

WORD    opposite_operator( operator )
WORD    operator;
{
	switch ( operator ) {
		case '-' : return( '~' );
		case '~' : return( '-' );
		case '/' : return( '\\' );
		case '\\': return( '/' );
		default  : return( operator );
		}
}


RESULTPTR       arithmetic( operation, lterm, rterm )
WORD            operation;
RESULTPTR       lterm;
RESULTPTR       rterm;
{
	RESULTPTR       rptr;

	if (( operation == '\\' ) || ( operation == '~' )) {
		rptr  = rterm;
		rterm = lterm;
		lterm = rptr;
		operation = opposite_operator( operation );
		}

	switch ( constant_folding( operation, lterm, rterm ) ) {
		case	VRAI	:	return( lterm );
		case	FAUX	:	break;
#ifndef	otr16
		case MOINS_UN	:
			/* ---------------------------------------- */
			/* on a rajout‚ ceci IJM+BG pour eviter les */
			/* souci lors que 1024*1024 en 16 devient 0 */
			/* ---------------------------------------- */
			if (!( lterm = convert_to_type( lterm, _TYPE_NUMERIC )))
				return( lterm );
			else if (!( rterm = convert_to_type( rterm,_TYPE_NUMERIC )))
				return( rterm );
			else	break;
#endif
		}

	if ((lterm = ensure_register( lterm )) == (RESULTPTR) 0)
		return( lterm );

	/* Detect Integer Incrementation/Decrementation Optimisation */
	/* --------------------------------------------------------- */
	if ( OtrOption.Optimise & _OPTIMISE_INCREMENT ) {
		switch ( operation ) {
			case '+' :
				if (( result_type( lterm ) < _TYPE_NUMERIC )
				&&  ( result_is_one( rterm )   ))
					return( generate_increment( lterm ) );
				else    break;
			case '-' :
				if (( result_type( lterm ) < _TYPE_NUMERIC )
				&&  ( result_is_one( rterm )   ))
					return( generate_decrement( lterm ) );
				else    break;
			}
		}
	if ((rptr = next_free_register()) == (RESULTPTR) 0)
		return( rptr );
	else    return( generate_arithmetic( operation, lterm, rterm, rptr ));
}

WORD            evaluate_comparison( operation, lterm, rterm, logic, label )
WORD            operation;
RESULTPTR       lterm;
RESULTPTR       rterm;
WORD            logic;
WORD            label;
{
	if (!( is_string_operand(lterm) )) {
		if ( operation == _CMP_IN )
			operation = _CMP_EQ;
		else if ( operation == _CMP_NI )
			operation = _CMP_NE;
		}
	if ((rterm = ensure_matching_type( lterm, rterm )) == (RESULTPTR) 0)
		return( 1 );
	if ((lterm = ensure_register( lterm )) == (RESULTPTR) 0)
		return( 1 );
	return( generate_compare( operation, lterm, rterm, logic, label ) );
	return(0);
}

WORD            evaluate_case_comparison( operation, lterm, rterm, logic, label )
WORD            operation;
RESULTPTR       lterm;
RESULTPTR       rterm;
WORD            logic;
WORD            label;
{
	if (!( is_string_operand(lterm) )) {
		if ( operation == _CMP_IN )
			operation = _CMP_EQ;
		else if ( operation == _CMP_NI )
			operation = _CMP_NE;
		}
/*	if ((rterm = ensure_matching_type( lterm, rterm )) == (RESULTPTR) 0)	*/
/*		return( 1 );							*/
	if ((lterm = ensure_register( lterm )) == (RESULTPTR) 0)		
		return( 1 );							
	return( generate_compare( operation, lterm, rterm, logic, label ) );
	return(0);
}

RESULTPTR       evaluate_operation( operation, lterm, rterm )
WORD            operation;
RESULTPTR       lterm;
RESULTPTR       rterm;
{
	RESULTPTR       rptr=(RESULTPTR) 0;

	trace("evaluate_operation()\n");

	if ((rptr = evaluate_object_operator( operation, lterm, rterm, FAUX, 0 )) != (RESULTPTR) 0)
		return( rptr );

	switch ( operation ) {

		/* ---------------------------------------------------- */
		/* STRING CONCATENATION OPERATOR        CAT             */
		/* ---------------------------------------------------- */
		case '!' :      /* Concatenate strings                  */

			if ((lterm = ensure_string( lterm )) == (RESULTPTR) 0)
				return( lterm );
			else if ((rterm = ensure_string( rterm )) == (RESULTPTR) 0)
				return( rterm );
			else    break;
			
		/* ---------------------------------------------------- */
		/* ARITHMETICAL NUMERIC OPERATIONS    ADD SUB MUL DIV   */
		/* ---------------------------------------------------- */
		case '%' :
			operation = '!';                
		case '\\':
		case '~' :
		case '+' :      /* Join strings or Numeric addition     */
		case '-' :      /* Numeric subtraction                  */
		case '*' :      /* Numeric multiplication               */
		case '/' :      /* Numeric Division                     */
			if ((rterm = ensure_matching_type( lterm, rterm )) == (RESULTPTR) 0)
				return( rterm );
			else    break;
 
		/* ---------------------------------------------------- */
		/* BITWISE INTEGER LOGICAL OPERATIONS   AND OR XOR      */
		/* ---------------------------------------------------- */
		case '&' :      /* Integer AND                          */
		case '|' :      /* Integer OR                           */
		case '^' :      /* Integer XOR                          */

			if ((lterm = ensure_integer( lterm )) == (RESULTPTR) 0)
				return( lterm );
			else if ((rterm = ensure_integer( rterm )) == (RESULTPTR) 0)
				return( lterm );
			else    break;                  

		}

	return((rptr = arithmetic( operation, lterm, rterm ) ));
}

VOID	drop_factor( fptr )
FACTORPTR       fptr;
{
	if ( fptr ) {
		fptr->next = FactorHeap;
		FactorHeap = fptr;
		}
	return;
}

VOID	drop_factors( root )
FACTORPTR       root;
{
	FACTORPTR       fptr;
	while ((fptr = root) != (FACTORPTR) 0) {
		root = fptr->next;
		drop_factor( fptr );
		}
	return;
}

RESULTPTR       evaluate_factors( root )
FACTORPTR       root;
{
	FACTORPTR       fptr=root;
	RESULTPTR       lptr=(RESULTPTR) 0;
	FACTORPTR       xptr=(FACTORPTR) 0;
	WORD            operation=0;
	WORD		pass;
	
	/* No factor ! No Result ! */
	/* ----------------------- */
	if (!( root ))	return((RESULTPTR) 0);

	/* Only One Factor : Return Result */
	/* ------------------------------- */
	else if (!( fptr->next )) {
		fptr->next = FactorHeap;
		FactorHeap = fptr;
		return( fptr->operand );
		}	

	/* Tripple pass evaluation for priority operators  ( * or / ) ( AND / OX ) ( others ) */
	/* ---------------------------------------------------------------------------------- */
	for ( pass=0; pass < 3; pass++  ) {

		/* To be sure to be sure */
		/* --------------------- */
		if (!( fptr=root )) break;

		while ( fptr ) {
			if (!( pass )) {
				/* pass zero is very selective */
				/* --------------------------- */
				if (( fptr->operation != '*' ) 
				&&  ( fptr->operation != '/' )) {
					fptr = fptr->next;
					continue;
					}
				}
			else if ( pass == 1 ) {
				/* pass one is  just selective */
				/* --------------------------- */
				if (( fptr->operation != '&' ) 
				&&  ( fptr->operation != '^' )) {
					fptr = fptr->next;
					continue;
					}
				}

			/* check for a legal operation */	
			/* --------------------------- */
			if (!( fptr->operation )) {
				fptr = fptr->next;
				continue;
				}

			/* check for a legal left operand */
			/* ------------------------------ */	
			else if (!( fptr->previous )) {
				fptr = fptr->next;
				continue;
				}

			else if (!( fptr->previous->operand )) {
				/* ca merde a donf */
				drop_factors(root);
				return( lptr );								
				}

			else if (!(lptr = evaluate_operation( fptr->operation, fptr->previous->operand, fptr->operand ))) {
				/* up to our necks in it ! */
				drop_factors(root);
				return( lptr );								
				}
			else	{
				/* backpatch the previous */
				/* ---------------------- */
				fptr->previous->operand = lptr; 				

				/* and drop the current */
				/* -------------------- */
				if ((fptr->previous->next = fptr->next) != (FACTORPTR) 0) 
					fptr->next->previous = fptr->previous;

				xptr = fptr->next;
				drop_factor( fptr );
				fptr = xptr;
				};
			}

		}

	/* Still No factor ! Still No Result ! */
	/* ----------------------------------- */
	if (!( root ))	return( (RESULTPTR) 0 );

	else	{
		/* Il ne doit en rester Qu'Un */
		/* -------------------------- */
		lptr = root->operand;

		/* Just in case */
		/* ------------ */
		drop_factors( root );

		return( lptr );
		}
}

static	int	floating_integers=-1;

RESULTPTR       secondary_evaluation( lptr )
RESULTPTR       lptr;
{
	BPTR		eptr;
	RESULTPTR       rptr=(RESULTPTR) 0;
	TCVARPTR        vptr;
	WORD            operation=0;
	WORD		xtype;
	FACTORPTR       root=(FACTORPTR) 0;
	FACTORPTR       last=(FACTORPTR) 0;
	FACTORPTR       fptr=(FACTORPTR) 0;

#ifdef  _INLINE_OPERATORS
	if ( is_period() ) {
		if ((vptr = is_variable_result( lptr )) == (TCVARPTR) 0) {
			(void) syntax_error( 2889 );
			return( (RESULTPTR) 0 );
			}
		if  (!( get_token() )) {
			(void) syntax_error( 2890 );
			return( (RESULTPTR) 0 );
			}
		if  ((lptr = evaluate_member_term( vptr, VRAI )) == (RESULTPTR) 0) {
			(void) syntax_error( 2891 );
			return( (RESULTPTR) 0 );
			}
		}
#endif
	if (!( root = allocate_for_factor(lptr, 0) )) {
		(void) syntax_error( 2891 );
		return( (RESULTPTR) 0 );
		}
	else	last = root;

	while ( 1 ) {

		switch ((operation = is_operator())) {
			case    ';' :
			case    ':' :
			case    ',' :
			case    ')' :
			case    0   :
				return( evaluate_factors( root ) );
			}

		/* --------------------------------------------------------------------------------- */
		/* this section of code is very important for the preservation of bcd type constants */
		/* --------------------------------------------------------------------------------- */

		/* ---------------------------- */
		/* IJM 15/12/2004 : RE CONV BCD */
		/* ---------------------------- */

		if ( floating_integers == -1 ) {

			if (!( eptr = sysgetenv("OTRCONV") ))
				floating_integers=1;
			else	floating_integers=(*eptr - '0');
			}


		switch ( floating_integers ) {

			case	1 :

				/* integers are to be converted to bcd */
				/* ----------------------------------- */
				switch ((xtype = result_type( lptr ))) {

					case	_TYPE_INT8	:
					case	_TYPE_INT16	:
					case	_TYPE_INT32	:

						switch (( lptr->nature & _RESULT_BASIC)) {
							case _RESULT_INT   : 
								Context->OperandType =
								Context->ConvertType = _TYPE_NUMERIC;
								break;
							default		   :
								Context->OperandType =
								Context->ConvertType = xtype;
								break;
							}
						break;

					case	_TYPE_NUMERIC	:
					case	_TYPE_STRING	:
						Context->OperandType =
						Context->ConvertType = xtype;
					}

				break;

			case	0 :

				/* integer  constants may be preserved */
				/* ----------------------------------- */
		Context->OperandType =
		Context->ConvertType = result_type( lptr );
				break;

			}

		/* -------------------------------- */
		/* END IJM 15/12/2004 : RE CONV BCD */
		/* -------------------------------- */

		Context->UseTarget   = 0;


		if ((rptr = evaluate_term()) == (RESULTPTR) 0) { 
			(void) syntax_error( 2888 );
			if ( operation == '!' )
				unget_byte();
			break;
			}


#ifdef  _INLINE_OPERATORS
		if ( is_period() ) {
			if (((vptr = is_variable_result( rptr )) == (TCVARPTR) 0)
			||  (!( get_token() ))
			||  ((rptr = evaluate_member_term( vptr, VRAI )) == (RESULTPTR) 0)) {
				(void) syntax_error( 2888 );
				return( (RESULTPTR) 0 );
				}
			}
#endif
		if (!( fptr = allocate_for_factor(rptr,operation) )) {
			(void) syntax_error( 2891 );
			return( (RESULTPTR) 0 );
			}
		else	{
			fptr->previous = last;
			last->next = fptr;
			last = fptr;
			lptr = rptr;
			}
		}
	return( evaluate_factors( root ) );
}

RESULTPTR       primary_evaluation()
{
	RESULTPTR       lptr;
	if ((lptr = primary_term()) != (RESULTPTR) 0)
		lptr = secondary_evaluation( lptr );
	return( lptr );
}

TCVARPTR        primary_variable()
{
	RESULTPTR       rptr;
	TCVARPTR        vptr;
	if (((rptr = primary_evaluation()) == (RESULTPTR) 0)
	||  (( rptr->nature & _RESULT_BASIC) != _RESULT_VARB )
	||  ((vptr = (TCVARPTR) rptr->contents) == (TCVARPTR) 0))
		return( (TCVARPTR) 0 );
	else    return( vptr );
}

RESULTPTR       evaluate_expression(level)
WORD level;
{
	RESULTPTR       lptr=(RESULTPTR) 0;
	RESULTPTR       rptr=(RESULTPTR) 0;
	WORD            operation=0;
	WORD            HoldType;
	WORD		HoldLevel;
	WORD		HoldOther;
	HoldOther= Context->OperandType;
	HoldLevel= Context->UseTarget;
	HoldType = Context->ConvertType;
	Context->UseTarget = level;
	Context->Depth++;

	if ((lptr = evaluate_term()) != (RESULTPTR) 0)
		lptr = secondary_evaluation( lptr );
	

	Context->Depth--;
	Context->ConvertType = HoldType;
	Context->UseTarget=HoldLevel;
	Context->OperandType = HoldOther;
	return( lptr );
}

RESULTPTR       evaluate_integer_expression()
{
	RESULTPTR       lptr=(RESULTPTR) 0;
	RESULTPTR       rptr=(RESULTPTR) 0;
	WORD            operation=0;
	WORD            HoldType;
	WORD            HoldDepth;

	HoldType 		= Context->ConvertType;
	HoldDepth 		= Context->Depth;
	Context->ConvertType 	= 1;
	Context->Depth 		= 0;

	if ((lptr = evaluate_term()) != (RESULTPTR) 0)
		lptr = secondary_evaluation( lptr );
	

	Context->Depth 		= HoldDepth;
	Context->ConvertType 	= HoldType;

	return( lptr );
}

RESULTPTR	evaluate_typed_expression(type)
WORD type;
{
	WORD	rt;
	WORD		ht;
	WORD		autoconv;
	RESULTPTR rptr;

	/* Unknown expression type so leave it alone */
	/* ----------------------------------------- */
	if (type == _TYPE_BASIC ) { return( evaluate_expression(0)); }

	ht = Context->OperandType;
	if ( type != MOINS_UN ) { Context->OperandType = (type & _TYPE_BASIC); }
	AllowAutoConv(0);
	rptr = evaluate_expression(0);
	autoconv = IsAutoConv();
	AllowAutoConv(0);
	Context->OperandType = ht;
	if (!( rptr ))
		return( rptr );
	else if ( type == MOINS_UN )
		return( rptr );
	else if (((rt = result_type(rptr)) & _TYPE_BASIC) == (type & _TYPE_BASIC))
		return( rptr );
	else if ( fundemental_type(rt) == fundemental_type( type ) )
		return( rptr );
	else if ( type & _TYPE_POINTER ) {
		switch (( rptr->nature & _RESULT_BASIC)) {
			case _RESULT_INT   : return( rptr );
			}
		return((RESULTPTR) 0);
		}
	else	{
		switch (( rptr->nature & _RESULT_BASIC)) {
			case _RESULT_INT   : 
				if (!( OtrOption.Strict & 2 ))
					break;
				else if ( (type & _TYPE_BASIC) == _TYPE_NUMERIC )
					break;
			case _RESULT_CONST : 
				if (!( OtrOption.Strict & 2 ))
					break;
			default		   :	
				if (!( autoconv )) {
					if ( OtrOption.Strict & 2 ) {
						syntax_error(55);
						return((RESULTPTR) 0);
						}
					else issue_warning(21);
					}
			}
	 	return( convert_to_type( rptr, (type & _TYPE_BASIC) ) );
		}
}

VOID    shadow_integer( rptr , value )
RESULTPTR       rptr;
WORD            value;
{
	rptr->contents = (VPTR) shadow_integer_register( rptr->contents, value );
	return;
}

VOID    shadow_expression( tptr, opcode, lptr, rptr )
RESULTPTR       tptr;
WORD            opcode;
RESULTPTR       lptr;
RESULTPTR       rptr;
{
	if ( OtrOption.ListFlag & 1 )
		set_shadow_operands( tptr->contents, opcode, lptr, rptr );
	tptr->contents = (VPTR) set_shadow_type( tptr->contents, result_type( lptr ) );
	return;
}

VOID    shadow_register( rptr , sptr )
RESULTPTR       rptr;
RESULTPTR       sptr;
{
	rptr->contents = sptr->contents;
	return;
}

VOID    shadow_constant( rptr , cptr )
RESULTPTR       rptr;
TCCONPTR        cptr;
{
	rptr->contents = (VPTR) shadow_constant_register( rptr->contents, cptr );
	return;
}

VOID    shadow_variable( rptr , vptr )
RESULTPTR       rptr;
TCVARPTR        vptr;
{
	rptr->contents = (VPTR) shadow_variable_register( rptr->contents, vptr );
	return;
}

VOID    shadow_conversion( rptr, type )
RESULTPTR       rptr;
WORD            type;
{
	if ( OtrOption.ListFlag & 1 )
		set_shadow_conv( rptr->contents, type );
	rptr->contents = (VPTR) set_shadow_type( rptr->contents, type );
	return;
}

RESULTPTR       variable_result( vptr )
TCVARPTR        vptr;
{
	RESULTPTR       tptr=(RESULTPTR) 0;
	if (( vptr != (TCVARPTR) 0 )
	&&  ((tptr = allocate_for_result()) != (RESULTPTR) 0)) {
		tptr->nature   = _RESULT_VARB;
		tptr->value    = vptr->identity;
		tptr->contents = (VPTR) vptr;
		}
	return( tptr );
}

RESULTPTR       increment_variable( vptr )
TCVARPTR        vptr;
{
	RESULTPTR       lptr;
	RESULTPTR       rptr;
	WORD            status;

	if ((lptr = variable_result( vptr )) != (RESULTPTR) 0) {
		if ( result_type( lptr ) < 2 ) {
			if (((lptr = incrementation( lptr )) != (RESULTPTR) 0)
			&&  ((status = generate_affectation( vptr, lptr,VRAI )) == 0))
				return( lptr );
			}
		else    {
			if (((rptr = integer_result( 1 )) != (RESULTPTR) 0)
			&&  ((rptr = ensure_matching_type(lptr,rptr)) != (RESULTPTR) 0)
			&&  ((rptr = arithmetic( '+', lptr, rptr ))   != (RESULTPTR) 0)
			&&  ((status = generate_affectation( vptr, rptr,VRAI )) == 0))
				return( rptr );
			}
		}

	(void) syntax_error(3339);
	return((RESULTPTR) 0);
}

VOID            unprotect_operand( lptr )
RESULTPTR       lptr;
{
	lptr->next = ResultUsed;
	ResultUsed = lptr;
	if (( lptr->nature & _RESULT_BASIC) == _RESULT_EXPR )
		release_base_register((SHADOWPTR) lptr->contents);
	return;
}

RESULTPTR       copy_result( rptr )
RESULTPTR       rptr;
{
	RESULTPTR       lptr;

	if ((lptr = allocate_for_result()) != (RESULTPTR) 0) {
		lptr->nature    = rptr->nature;
		lptr->value     = rptr->value;
		lptr->contents  = rptr->contents;
		}
	return( lptr );
}

RESULTPTR       protect_operand( rptr )
RESULTPTR       rptr;
{
	RESULTPTR       lptr;
	SHADOWPTR       sptr;
	TCVARPTR        vptr;
	if ((lptr = allocate_for_result()) != (RESULTPTR) 0) {
		lptr->nature    = rptr->nature;
		lptr->value     = rptr->value;
		lptr->contents  = rptr->contents;
		ResultUsed      = lptr->next;
		lptr->next      = (RESULTPTR) 0;
		if (( lptr->nature & _RESULT_BASIC) == _RESULT_EXPR ) {
			if ((sptr = protect_base_register((SHADOWPTR) lptr->contents )) != (SHADOWPTR) 0) {
				lptr->value = sptr->number;
				lptr->contents = (VPTR) sptr;
				}
			else    return( (RESULTPTR) 0 );
			}
		else if (( lptr->nature & _RESULT_BASIC) == _RESULT_VARB ) {
			if ((vptr = protect_variable( lptr->contents )) != (TCVARPTR) 0)
				lptr->contents = (VPTR) vptr;
			else    return( (RESULTPTR) 0 );
			}
		}
	return( lptr );
}

WORD    index_available( vptr )
TCVARPTR        vptr;
{
	switch (( vptr->type->type & 0xF000 )) {
		case _TYPE_POINTER :
		case 0xB000 :
			if (( vptr->type->type & 0x0040 )
			&&  ( vptr->firstdim != (VPTR) 0 )) 
				return( VRAI );
			else    return( FAUX );
		default     : return( VRAI );
		}
}

WORD    handle_index_expression( rptr )
RESULTPTR       rptr;
{
	TCVARPTR        vptr;
	RESULTPTR       xptr;
	trace("handle_index_expression()\n");
	if (( rptr != (RESULTPTR) 0 )
	&&  ((vptr = (TCVARPTR) rptr->contents) != (TCVARPTR) 0)
	&&  ( vptr->type != (TCTYPPTR) 0)
	&&  ( vptr->type->type & 0x0060 )
	&&  ( index_available(vptr) )) { 
		trace("variable_requires_index()\n");
		if (((xptr = next_free_register()) != (RESULTPTR) 0) 
		&&  ((xptr = generate_register_load( xptr, rptr,(rptr->nature & _RESULT_VPT))) != (RESULTPTR) 0 ))
			transfer_result( rptr, xptr );
		}
	return(0);
}

WORD    zero_index_expression( rptr )
RESULTPTR       rptr;
{
	TCVARPTR        vptr;
	RESULTPTR       xptr;
	trace("handle_index_expression()\n");
	if (( rptr != (RESULTPTR) 0 )
	&&  ((vptr = (TCVARPTR) rptr->contents) != (TCVARPTR) 0)
	&&  ( vptr->type != (TCTYPPTR) 0)
	&&  ( vptr->type->type & 0x0060 )
	&&  ( index_available(vptr) )) { 
		trace("variable_requires_index()\n");
		if (((xptr = next_free_register()) != (RESULTPTR) 0) 
		&&  ((xptr = generate_register_load( xptr, rptr,_RESULT_VPT )) != (RESULTPTR) 0 ))
			transfer_result( rptr, xptr );
		}
	return(0);
}

WORD    handle_target_index( rptr )
RESULTPTR       rptr;
{
	TCVARPTR        vptr;

	trace("handle_index_expression()\n");
	if (( rptr != (RESULTPTR) 0 )
	&&  ((vptr = (TCVARPTR) rptr->contents) != (TCVARPTR) 0)
	&&  ( vptr->type != (TCTYPPTR) 0)
	&&  ( vptr->type->type & 0x0060 )
	&&  ( index_available(vptr) ))
		return( generate_dimensions( 0, vptr ) );
	else    return( 0 );
}

RESULTPTR       resolve_register_alias( lterm )
RESULTPTR       lterm;
{
	TCTYPPTR        tptr;
	TCVARPTR        vptr;
	RESULTPTR       rptr=(RESULTPTR) 0;
	if (((tptr = register_alias( lterm->contents ))  != (TCTYPPTR) 0)
	&&  ((vptr = dcl_object_alias( tptr, lterm->value )) != (TCVARPTR) 0)
	&&  ((rptr = variable_result( vptr ))  != (RESULTPTR) 0)) {
		lterm->nature &= ~_RESULT_POINTER;
		(void) clf_alias( rptr, lterm );
		}
	return( rptr );
}

RESULTPTR       mark_dead_result( rptr )
RESULTPTR       rptr;
{
	trace("mark_dead_result()\n");
	if ( rptr != (RESULTPTR) 0 ) {
		if (( rptr->nature & _RESULT_BASIC) == _RESULT_VARB )
			handle_index_expression( rptr );
		if ( rptr->nature == _RESULT_ALEXPR )
			return( resolve_register_alias( rptr ) );
		if (( rptr->nature & _RESULT_BASIC) == _RESULT_EXPR )
			mark_dead_register( rptr->contents );   
		}
	return(rptr);
}

RESULTPTR       mark_zero_result( rptr )
RESULTPTR       rptr;
{
	trace("mark_dead_result()\n");
	if ( rptr != (RESULTPTR) 0 ) {
		if (( rptr->nature & _RESULT_BASIC) == _RESULT_VARB )
			zero_index_expression( rptr );
		if ( rptr->nature == _RESULT_ALEXPR )
			return( resolve_register_alias( rptr ) );
		if (( rptr->nature & _RESULT_BASIC) == _RESULT_EXPR )
			mark_dead_register( rptr->contents );   
		}
	return(rptr);
}

RESULTPTR       mark_dead_target( rptr )
RESULTPTR       rptr;
{
	trace("mark_dead_result()\n");
	if ( rptr != (RESULTPTR) 0 ) {
		if (( rptr->nature & _RESULT_BASIC) == _RESULT_VARB )
			handle_target_index( rptr );
		if (( rptr->nature & _RESULT_BASIC) == _RESULT_EXPR )
			mark_dead_register( rptr->contents );   
		}
	return(rptr);
}

VOID    mark_live_indexs( vptr )
TCVARPTR        vptr;
{
	if ((vptr != (TCVARPTR) 0) 
	&&  (vptr->type->type & _TYPE_FIRST)) {
		vptr->firstdim = (VPTR) mark_live_result( vptr->firstdim );
		if ( vptr->type->type & _TYPE_SECOND )
			vptr->secondim = (VPTR) mark_live_result( vptr->secondim );
		}
	return;
}

RESULTPTR       mark_live_result( rptr )
RESULTPTR       rptr;
{
	trace("mark_live_result()\n");
	if ( rptr != (RESULTPTR) 0 ) {
		if (( rptr->nature & _RESULT_BASIC) == _RESULT_VARB )
			mark_live_indexs( rptr->contents );
		else if (( rptr->nature & _RESULT_BASIC) == _RESULT_EXPR )
			mark_live_register( rptr->contents );   
		}
	return(rptr);
}

/*
 *      R E S O L V E _ S T R U C T U R E _ M E M B E R ()
 *      --------------------------------------------------
 *
 *      Called from     :
 *
 *              TREXPRES.variable_operand()
 *      and
 *              TREXPRES.collect_dimensions()
 *
 *      to resolve structural componant requirements as detected
 *      by the calling function.
 *
 */

static  LONG    RmvFail=0L;
static  LONG    RmvCall=0L;

VOID    rmv_statistics()
{
	sysprintf("resolve_member_variable() calls   : %lu \n",RmvCall );
	sysprintf("resolve_member_variable() fails   : %lu \n",RmvFail );
	return;
}

TCVARPTR        resolve_member_variable( vptr, vname, vhash )
TCVARPTR        vptr;
BPTR            vname;
WORD            vhash;
{
	TCVARPTR        mptr;

	/* Locate Original Descriptor Node */
	/* ------------------------------- */
	while (vptr->parent != (TCVARPTR) 0)
		vptr = vptr->parent;

	mptr = vptr;

	RmvCall++;
/*
 *      sysprintf("resolve_member_variable( %s #%u of ",vname,vhash);
 *      sysprintf("Master(%s, id = %u) )\n",mptr->name,mptr->identity);
 */
	/* Locate Child Member Node */
	/* ------------------------ */
	while (( vptr = vptr->prev) != (TCVARPTR) 0 ) {

/*
 *              sysprintf("\tTEST(%s, #%u ,master= %u )\n",vptr->name,vptr->hash,vptr->master);
 */
		if (( vptr->master == mptr->identity )
		&&  ( vptr->hash == vhash )
		&&  ( compare_tokens( vptr->name, vname )))
			return( temp_variable( vptr ) );
		else    RmvFail++;
		}

	return((TCVARPTR) 0);
	
}

TCVARPTR        resolve_structure_member( vptr )
TCVARPTR        vptr;
{
	BYTE            vname[65];

	/* Collect Structure Member/Componant */
	/* ---------------------------------- */
	if (( get_token() )
	&&  ( copy_token( vname, 64 ) ))

		return( resolve_member_variable( vptr, vname,TokenHash ) );

	else    {

		(void) syntax_error(3340);
		return((TCVARPTR) 0);
		}
}

/*
 *      V A R I A B L E _ O P E R A N D ()
 *      ----------------------------------
 *
 *      This function is called from :
 *
 *              TRCLF.evaluate_clf6()
 *
 *      In order to collect an anticipated mandatory variable
 *      operand for the instructions :
 *
 *              CREATE, REMOVE, FORGET, ALTER, ATTACH and DETACH.
 *
 */

RESULTPTR       variable_operand()
{
	TCVARPTR        vptr;

	/* Locate Potential and Expected Variable Identifier */
	/* ------------------------------------------------- */
	if (( get_token() )
	&&  ((vptr = get_variable(1)) != (TCVARPTR) 0)) {

		/* Detect and Resolve Structure Member Componants */
		/* ---------------------------------------------- */
		while (( vptr->type->type & 0x0010 )
		   &&  ( is_period()               ))
			if ((vptr = resolve_structure_member( vptr )) == (TCVARPTR) 0)
				break;

		/* Return Variable Result */
		/* ---------------------- */
		return( variable_result( vptr ) );
		}

	else    return( object_symbolic_term(FAUX) );
}


RESULTPTR       named_segment(token)
BPTR            token;
{
	XTSEGPTR        xptr;
	if (( xptr = locate_external_segment( token )) == (XTSEGPTR) 0)
		return( integer_result( explicite_named_segment( token ) ) );
	else    return( integer_result( rellocate_external_segment( xptr ) ));
}

WORD    collect_legal_operator()
{
	WORD    operation;
	switch ((operation = is_operator())) {
		case    ';'      :
		case    ':'      :
		case    ','      :
		case    ')'      :
		case    0        :
		case    MOINS_UN :
			return( 0 );
		default     :
			return( operation );
		}
}

WORD    affectation_expression( vptr )
TCVARPTR        vptr;
{
	RESULTPTR       lptr;
	RESULTPTR       rptr;
	WORD            operator;
	WORD            status;
	if ((lptr = variable_result( vptr )) == (RESULTPTR) 0)
		return( syntax_error( 3360 ) );
	else if ((operator = collect_legal_operator()) == 0)
		return( syntax_error( 3361 ) );
	else if (!( is_equals() ))
		return( syntax_error( 3362 ) );
	else if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
		return( syntax_error( 3363 ) );
	else if ((rptr = evaluate_operation( operator,lptr, rptr )) == (RESULTPTR) 0)
		return( syntax_error(3341) );
	else if ((status = generate_affectation( vptr, rptr,VRAI )) != 0)
		return( status );
	else    return( status );
}


WORD            ldgo_extern_segment( xptr )
XTSEGPTR        xptr;
{
	trace("ldgo_extern_segment()\n");
	return( generate_ldgoseg(
			integer_result( rellocate_external_segment( xptr ) ),
			3,
			xptr->identity  ));
}

WORD            ldgo_intern_segment( sptr )
TCSEGPTR        sptr;
{
	trace("ldgo_intern_segment()\n");
	return( generate_ldgoseg(
			integer_result( sptr->identity ),
			2,
			sptr->offset  ));

}

#endif  /* _TREXPRES_C */
	/* ----------- */

