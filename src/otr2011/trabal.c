#define DEBUG
/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRANSLAT.C				*/
/*		Version :	2.1c					*/
/*		Date	:	28/09/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRANSLAT_C
#define	_TRANSLAT_C

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#ifdef WIN32
#include <string.h>
#endif


#include "stdtypes.h"
#include "trtype.h"
#include "tctype.h"

#include "translat.h"
#include "trparser.h"
#include "trsyntax.h"
#include "trerrors.h"
#include "trsymbol.h"
#include "troption.h"
#include "trexpres.h"
#include "trlabels.h"
#include "triter.h"
#include "trclf.h"
#include "trldf.h"
#include "trdebug.h"
#include "trproc.h"		
#include "trmethod.h"	
#include "trshadow.h"	
#include "trabal.h"
#include "trtables.h"	
#include "trclass.h"		
#include "trecho.h"		
#include "trinput.h"		
#include "triof.h"
#include "troutput.h"	
#include "trcorres.h"	
#include "trdirect.h"	
#include "trcometh.h"	
#include "trngf.h"		
#include "trapl.h"		
#include "trworld.h"		
#include "trstdc.h"		
#include "trmain.h"		
#include "trauto.h"
#ifndef WIN32
#include "trstring.h"
#endif

#ifdef WIN32
// Trace
#include "trtrace.h"
#endif

#ifndef	UNIX
/* Internal procedures */
WORD		translate_filler(VOID);
WORD		segmental_translation(VOID);
#else
RESULTPTR	evaluate_operation();
RESULTPTR	exception_operand();
RESULTPTR	iteration_operand();
TCVARPTR 	primary_variable();
VPTR		input_object();
WORD		translator_code_or_data();
WORD		collect_string_litteral();
WORD		translate_filler();
WORD		segmental_translation();
WORD		translate_end();
#endif

RESULTPTR	string_resulat();
RESULTPTR	clf_len_dollar();
RESULTPTR	clf_tokeniser();

#ifndef	UNIX
#define	ENV_FIELD ';'
#else
#define	ENV_FIELD ':'
#endif


extern	WORD	ForceLDV;

static	WORD	translator_code()
{
	return(57);
}


WORD	reverse_compare( opcode )
WORD	opcode;
{
	switch ( opcode ) {
		case _CMP_EQ : return( _CMP_NE );
		case _CMP_NE : return( _CMP_EQ );
		case _CMP_GR : return( _CMP_LE );
		case _CMP_LS : return( _CMP_GE );
		case _CMP_GE : return( _CMP_LS );
		case _CMP_LE : return( _CMP_GR );
		case _CMP_IN : return( _CMP_NI );
		case _CMP_NI : return( _CMP_IN );
		default      : return( 0 );
		}
}

WORD	collect_normal_operator()
{
	WORD	result=0;
	WORD	c;

	if ( remove_white_space() ) {


		switch((c = get_byte())) {
			case '!' :
				result = _CMP_NI;
				if ((c = get_byte()) != '=')
					unget_byte();
				break;

			case '=' : 
				result = _CMP_IN;
				if ((c = get_byte()) == '=')
					result = _CMP_EQ;
				else 	unget_byte();
				break;
					
			case '<' :
				result = _CMP_LS;
				switch ((c = get_byte())) {
					case '=' : result = _CMP_LE; break;
					case '>' : result = _CMP_NE; break;
					default  :
						unget_byte();
					}
				break; 
			case '>' :
				result = _CMP_GR;
				if ((c = get_byte()) == '=')
					result = _CMP_GE;
				else 	unget_byte();
				break;
					
			default  : unget_byte();
			}

		}
	return( result );	
}

WORD	translate_variable( type, nature )
WORD	type;		/* DCL, PTR, ARG, CONST		*/
WORD	nature;		/* DCL, PROC, SEGM, USER, CODE 	*/
{
	WORD		l;
	BYTE		vname[_MAX_OTR_TOKEN+1];
	WORD		vsize=8;
	WORD		vone=1;
	WORD		vtwo=1;
	WORD		vtype=2;
	WORD		xtype=0;
	TCVARPTR	variable;

	trace("translate_variable()\n");

	l = strlen( TokenBuffer );

	if ( copy_token( vname, 32 ) == 0 )
		return( 30 );

	if ( type == _KW1_CONST ) {

		if ( is_dollar() )
			xtype = '$';
		else if ( is_dieze() )
			xtype = '#';
		else if ( is_percent() )
			xtype = '%';
#ifdef	otr32
		else if ( is_colon() )
			xtype = ':';
#endif
		else	xtype = '*';

		if (!( is_equals() ))
			return( syntax_error(140) );

		switch ( xtype ) {

			case '#' : vsize = 1;
				   vtype = 0;
				   sprintf(TokenBuffer,"%u",integer_expression());
				   break;
			case '%' : vsize = 2;  
				   vtype = 1;
				   sprintf(TokenBuffer,"%u",integer_expression());
				   break;
#ifdef	otr32
			case ':' : vsize = 4;  
				   vtype = 5;
				   sprintf(TokenBuffer,"%lu",integer_expression());
				   break;
#endif
			case '$' : vsize = 15;
				   vtype = 3;

				if ( is_dieze() ) {
					if (!( dieze_constants()))
						return( syntax_error( 141 ) );
					}
				else if (!( collect_string_litteral() ))
					return( syntax_error( 141 ) );
				break;

			default	  :
				   if (!( evaluate_token() ))
					return( syntax_error(141) );
				   break;
			}

		/* Collect constant value */
		/* ---------------------- */
		if ( World->CurrentStructure != (TCSTRUCTPTR) 0)
			return( add_structure_constant( vname, vtype, TokenBuffer ) );
		else	return( add_constant( vname, vtype, TokenBuffer ) );
		}

	else if ( nature == _DCL_NORMAL ) {

		if ( is_dollar() )
			xtype = '$';
		else if ( is_dieze() )
			xtype = '#';
		else if ( is_percent() )
			xtype = '%';
#ifdef	otr32
		else if ( is_colon() )
			xtype = ':';
#endif
		else	xtype = '*';

		/* Collect possible length */
		/* ----------------------- */
		switch ( xtype ) {
			case '#' : if ( is_equals() )
					return(syntax_error(142));
				   vsize = 1;
				   vtype = 0;
				   break;
			case '%' : if ( is_equals() )
					return(syntax_error(142));
				   vsize = 2;  
				   vtype = 1;
				   break;
#ifdef	otr32
			case ':' : if ( is_equals() )
					return(syntax_error(142));
				   vsize = 4;  
				   vtype = 5;
				   break;
#endif
			case '$' : vsize = 15;
				   vtype = 3;
				if ( is_equals() )
					vsize = integer_expression();
				break;
			default  :
				if (!( is_mnemonic( "LIKE" ) )) {
					if ( is_equals() )
						vsize = integer_expression();
					}
				else if (!( get_token() )) 
					return( syntax_error(143) );
				else if (!(variable = is_variable(1))) 
					return( syntax_error(143) );

				else	{
					vtype = (variable->type->type & 0x00FF);
					vsize = variable->type->size;
					vone  = variable->type->first;
					vtwo  = variable->type->second;
					}		

			}
		}
	else	{
		if ( is_dollar() )
			xtype = '$';
		else if ( is_dieze() )
			xtype = '#';
		else if ( is_percent() )
			xtype = '%';
#ifdef	otr32
		else if ( is_percent() )
			xtype = ':';
#endif
		else	xtype = 0;

		/* PROC,SEGM,USER,CODE pointers */
		/* ---------------------------- */
		switch (xtype) {
			case '#'	:
			case '%'	:
#ifdef	otr32
			case ':'	:
#endif
			case '$'	:
				return( syntax_error(144) );
			}
		vsize = 5;
		vtype = 3;
		}

	/* Ensure reasonable Bcd Limit */
	/* --------------------------- */
	if (( vtype == 2 ) && ( vsize > 12 ))
		return( syntax_error(236) );

	/* Collect possible dimensions */
	/* --------------------------- */
	if ( is_left_brace() ) {
		if (!(vone = integer_expression()))
			return( syntax_error(231) );
			
		vtype |= 0x0040;
		if ( is_comma() ) {
			if (!( vtwo = integer_expression() ))
				return( syntax_error( 232 ) );
			vtype |= 0x0020;
			}
		if (!( is_right_brace()))
			return( unmatched_braces() );
		}

	if ( World->CurrentStructure != (TCSTRUCTPTR) 0)
		return( add_to_structure( vname, vtype, vsize, vone, vtwo, type, nature ) );
	else	return( declare_terminal( vname, vtype, vsize, vone, vtwo, type, nature, 0 ) );

}


WORD	translate_declaration(type) 
WORD	type;
{
	WORD	status=0;
	WORD	nature=0;
	WORD	n;

	while	(1)	{
		if (get_token()) {
			switch 	((n = is_dcl_keyword())) {
				case _DCL_LIKE  : return(syntax_error(0));
				case _DCL_FILLER: 
					if ( type != _KW1_CONST )
						return(translate_filler());
					else  	return(syntax_error(145)); 
				case _DCL_PROC	:	
				case _DCL_SEGM  :
				case _DCL_USER  :
				case _DCL_CODE  : 
					if ( type == _KW1_CONST )
						return( syntax_error(146) );
					nature = n;
					continue;
				default		:
					if ((n = is_level1_keyword()) == _KW1_SEGMENT) {
						if ( type == _KW1_CONST )
							return( syntax_error(147) );
						nature = _DCL_SEGM;
						continue;
						}
					else if (n == _KW1_STRUCT)
						return( translate_structure(type,n) );
					else if (n == _KW1_UNION)
						return( translate_union(type,n) );
					else if (n == _KW1_CLASS)
						return( translate_structure(type,n) );
					else if ((status = translate_variable(type,nature)) != 0)
						return( status );
					else if (is_comma())
						continue;
					else	return(verify_end_of_line());
				}
			}
		else if (!( class_definition_active() ))
			return(syntax_error(148) );
		else if (!( new_input_line() ))
			return( syntax_error(148) );
		}

}

WORD	translate_filler()
{
	WORD	status;
	WORD	filler=0;
	if ( is_equals() ) {
		if (((status = dcl_filler((filler = integer_expression()))) == 0)
		&&  ( is_comma() ))
			return( translate_declaration( _KW1_DCL ) ); 
		else	return( status );
		}
	else	return( syntax_error(1490) );	
}

WORD	translate_field() 
{
	WORD	status;

	trace("translate_field()\n");
	if ( is_equals() ) {
		if (!(remove_white_space()))
			return(syntax_error(150));
		if ( is_mnemonic("E") ) {
			if ( OtrOption.WordSize > 2 ) {
				field_equals_m();
				}
			else	{
				field_equals_e();
				}
			}
		else if ( is_mnemonic( "M" ))
			field_equals_m();
		else if ( is_mnemonic( "G" )) {
			if ((status = field_equals_g()) != 0)
				return( status );
			}
		else if ( is_mnemonic( "L" )) {
			if ((status = field_equals_l()) != 0)
				return( status );
			}
		else if ( is_mnemonic( "(S)" )) {
			if ((status = field_equals_s()) != 0)
				return( status );
			}
		else if ( is_mnemonic( "(R)" )) {
			if ((status = field_equals_r()) != 0)
				return( status );
			}
		else if ((status = field_equals_file( integer_expression() )) !=0)
			return( status );

		Context->ThisField->Host = 0;

		if ( is_comma() ) {
			if ( get_token() )
				return( redefine_variable() );
			else	return( syntax_error(151) );
			}
		else	return(0);
		}
	else	{
		return( syntax_error(152) );
		}
}

WORD	enter_segmental_translation()
{
	push_operation_pointer();
	set_operation_pointer(segmental_translation);
	set_local_scope();
	return(0);
}

VOID	leave_segmental_translation()
{
	liberate_local_symbols();
	initialise_field((FIELDPTR) & Context->LocalField );
	pop_operation_pointer();
	set_global_scope();
	return;
}

WORD	translate_endproc()
{
	WORD	status=0;
	BYTE	vname[_MAX_OTR_TOKEN+1];
	trace("translate_endproc()\n");
	if ( Context->PRC == (TCPRCPTR) 0)
		return( syntax_error(153) );
	else if (( get_token() )
	     &&  ( copy_token( vname, 32 ) )
	     &&  (!( compare_tokens( Context->PRC->name, vname ) )))
		return( syntax_error(154) );

	status = terminate_procedure();

	leave_segmental_translation();

	return( status );
}

WORD	translate_eseg()
{
	WORD	status;
	WORD	identity;
	BYTE	nomseg[65];
	BPTR	nptr=(BPTR) 0;
	WORD	c;

	trace("translate_eseg()\n");

	if ((c = is_numeric()) != 0)
		identity = integer_expression();
	else if (!( get_token() ))
		return( syntax_error(155) );
	else 	strcpy( (nptr = (BPTR) nomseg), TokenBuffer );

	status = terminate_segment( identity, nptr, FAUX );

	leave_segmental_translation();

	return( status );

}

WORD	comma_option( WPTR result ,WORD v1, WORD v2 )
{
	WORD	c;
	WORD	options=0;
	if ( is_comma() ) {
		if (remove_white_space()) {
			c = get_byte();
			if (( c == v1 ) || (c == v2))
				options = 1;
			else	return( syntax_error(156));
			}
		else	return( syntax_error(157));
		}
	*result = options;
	return( 0 );
}

WORD	translate_endloc()
{
	WORD	status;
	WORD	options=0;
	trace("translate_endloc()\n");
	if ((status = comma_option(& options,'s', 'S' )) != 0) 
		return(status );
	else 	return( endloc_options(options) );

}

WORD	translate_segment_return()
{
	return( generate_retseg() );
}

WORD	translate_ldgo_ret_seg( type )
WORD	type;
{
	WORD		status=0;
	RESULTPTR	rptr;
#ifdef UNIX
	RESULTPTR	primary_term();
	RESULTPTR	primary_integer_term();
#endif
	XTSEGPTR	xptr;

	if (( get_token() ) &&  ( is_control_keyword() == _CTRL_SEG )) {

		/* ensure translating segment */
		/* -------------------------- */
		if ( Context->PRC != (TCPRCPTR) 0) {
			return( generate_exit((RESULTPTR) 0) );
			}
		trace("translate_ldgo_ret_seg()\n");
		if ( type == _CTRL_RET ) {
			if ((status = verify_destruction_abort()) != 0)
				return( status );
			else	return( translate_segment_return() );
			}
		else if (!( get_token() )) { 
			if ((rptr = evaluate_integer_expression()) != (RESULTPTR) 0)
				return( generate_ldgoseg(rptr,MOINS_UN,MOINS_UN) );
			else	return( generate_named_ldgoseg( TokenBuffer ) );
			}
		else if (( xptr = locate_external_segment( TokenBuffer )) != (XTSEGPTR) 0)
			return( ldgo_extern_segment( xptr  ) );
		else if ((rptr = primary_integer_term()) != (RESULTPTR) 0) 
			return( generate_ldgoseg(rptr,MOINS_UN,MOINS_UN) );
		else	return( generate_named_ldgoseg( TokenBuffer ) );
		}
	else	return( syntax_error(158) );

}

WORD	translate_gosub()
{
	TCVARPTR	vptr;
	RESULTPTR	rptr;
	trace("translate_gosub()\n"); 
	if ( is_ampersand() ) {
		unget_byte();
		if (!( get_label() ))
		 	return( syntax_error(159) );
		else	return(generate_gosub_label( TokenBuffer ) );
		}
	else if ( get_token() ) {
		if ((vptr = is_variable(0)) == (TCVARPTR) 0)
			return(generate_gosub_label( TokenBuffer ) );
		else if ((rptr = variable_result( vptr )) == (RESULTPTR) 0)
			return( allocation_failure() );
		else if ((rptr = ensure_register( rptr )) == (RESULTPTR) 0)
			return( allocation_failure() );
		else	return( generate_gosub_register( rptr ) );
		}
	else 	return( syntax_error(159) );
}

WORD	translate_goto()
{
	TCVARPTR	vptr;
	RESULTPTR	rptr;
	trace("translate_goto()\n"); 
	if ( is_ampersand() ) {
		unget_byte();
		if (!( get_label() ))
		 	return( syntax_error(160) );
		else	{
			if ( OtrOption.ListFlag & 1 )
				echo_goto_label( TokenBuffer );
			return(generate_goto( use_explicite_label( TokenBuffer, 1) ));
			}
		}
	else if ( get_token() ) {
		if ((vptr = is_variable(0)) == (TCVARPTR) 0) {
			if ( OtrOption.ListFlag & 1 )
				echo_goto_label( TokenBuffer );
			return(generate_goto( use_explicite_label( TokenBuffer, 1) ));
			}
		else if ((rptr = variable_result( vptr )) == (RESULTPTR) 0)
			return( allocation_failure() );
		else if ((rptr = ensure_register( rptr )) == (RESULTPTR) 0)
			return( allocation_failure() );
		else	return( generate_goto_register( rptr ) );
		}
	else 	return( syntax_error(160) );
}


WORD	translate_endif()
{
	WORD	status=0;
	if ((status = iteration_type()) != _ITERATION_IF )
		if ( status != _ITERATION_ELSE )
		return( syntax_error(161) );
	leave_iteration();
	return(status);
}


WORD	old_conditional_expression(repeat_until)
WORD	repeat_until;
{
	RESULTPTR	lptr=(RESULTPTR) 0;
	RESULTPTR	rptr=(RESULTPTR) 0;
	WORD		operation;
	WORD		status;
	WORD		logic=_LOGICAL_END;
	WORD		more_logic=VRAI;

	while (1) {

/*		braces = is_left_brace();	*/

		if ((lptr = evaluate_expression(0)) == (RESULTPTR) 0)
			return(syntax_error(5005));

		while ( is_right_brace() );

		if ((operation = comparison_operator(repeat_until)) != 0) {

			if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
				return(syntax_error(5005));

			}
		else	{
			if ( OtrOption.Enhanced & _ENHANCED_COMPARE ) {
				/* Allow Boolean Comparison (ie Not False) */
				/* --------------------------------------- */
				if ((rptr = integer_result(0)) == (RESULTPTR) 0)
					return( allocation_failure() );
				else if ( repeat_until)
					operation = _CMP_EQ;
				else	operation = _CMP_NE;
				}
			else	return( syntax_error(162) );
			}

		while ( is_right_brace() );

		if ( OtrOption.ListFlag & 1)
			echo_compare( operation, lptr, rptr );

		if ((more_logic = get_token()))  {
			if ((logic = is_logical_keyword()) == MOINS_UN)
				return( syntax_error(163) );
			else if ( OtrOption.ListFlag & 1 )
				echo_logic( logic );
			}
		else	logic = ( repeat_until ? _LOGICAL_OR : _LOGICAL_AND );

		switch (logic) {
			case _LOGICAL_END:
			case _LOGICAL_AND:
				if (!(repeat_until))
					operation = reverse_compare( operation );
				break;
			case _LOGICAL_OR : /* AND LOGIC : INVCMP : TRUE	 */
				if (repeat_until)
					operation = reverse_compare( operation );
				break;
			}

		if ( repeat_until ) {
			if ( logic == _LOGICAL_AND )
				logic = _LOGICAL_OR;
			else	logic = _LOGICAL_AND;
			}

		if ((status = evaluate_comparison(operation,lptr,rptr,logic,0)) != 0 )
			return( status );

		/* Terminate if Terminal Logic */
		/* --------------------------- */
		if (!(more_logic)) {
			while ( is_right_brace() );
			if ( OtrOption.ListFlag & 1)
				echo_compare_end();
			return( 0 );
			}
		}

}

#include "trcond.c"

WORD	conditional_expression(WORD repeat_until)
{
	reset_affectation(0);
	if (!( OtrOption.Con ))
		return( new_conditional_expression( repeat_until ) );
	else	return( old_conditional_expression( repeat_until ) );
}

WORD	translate_if()
{
	WORD		status=0;

	if ((status = enter_iteration( _ITERATION_IF,(TCVARPTR) 0 )) != 0)
		return( status );
	else if ((status = conditional_expression(0)) != 0 )
		return( status );
	else if ( dcl_operate_label() == 0 )
		return( syntax_error(164) );
	else if ( is_colon() ) {
		if ((status = (*Context->operation)()) != 0)
			return(status);
		else	return( translate_endif() );
		}
	else 	return( 0 );
}

WORD	translate_else()
{
	WORD	status=0;

/*	if ( iteration_type() != _ITERATION_IF )	*/
	if ( iteration_else() != _ITERATION_IF )
		return( syntax_error(165) );
	generate_iteration();
	dcl_abandon_label();	
	if ( OtrOption.ListFlag & 1 )
		echo_else();
	return(status);
}

WORD	translate_while()
{
	WORD	status=0;
	if ((status = enter_iteration( _ITERATION_WHILE,(TCVARPTR) 0 )) != 0)
		return( status );
	else if ((status = conditional_expression(0)) != 0 )
		return( status );
	else if ( dcl_operate_label() == 0 )
		return( syntax_error(166) );
	else	return( 0 );
}

WORD	translate_wend()
{
	WORD	status=0;
	if ( iteration_type() != _ITERATION_WHILE )
		return( syntax_error(167) );
	leave_iteration();
	return(status);
}

WORD	translate_loop()
{
	WORD	status=0;
	if ( iteration_type() != _ITERATION_DO )
		return( syntax_error(168) );
	leave_iteration();
	return(status);
}

WORD	translate_repeat()
{
	WORD	status=0;
	if ((status = enter_iteration( _ITERATION_REPEAT,(TCVARPTR) 0 )) != 0)
		return( status );
	else if ( dcl_operate_label() == 0 )
		return( syntax_error(169) );
	else	return( 0 );
}

WORD	translate_until()
{
	WORD	status=0;
	if ( iteration_type() != _ITERATION_REPEAT )
		return( syntax_error(170) );
	if ( OtrOption.ListFlag & 1 )
		echo_until();
	status = conditional_expression(1);
	leave_iteration();
	return(status);
}


TCVARPTR	generate_for_in(TCVARPTR vptr, TCVARPTR lptr, RESULTPTR rptr )
{
	RESULTPTR	iptr;
	RESULTPTR	xptr;
	if (!( iptr = integer_result( 1 ))) {
		(void) syntax_error(173);
		return((TCVARPTR) 0);
		}
	else	{
		/* ---------------------------------------------- */
		/* FOR TOKEN IN LISTE [ USING PUNCTUATION ]	  */
		/* ---------------------------------------------- */
		if ( enter_iteration( _ITERATION_FOR,vptr ) != 0)
			return((TCVARPTR) 0);

		/* ---------------------------------------------- */
		/* IF ( LEN$(LISTE) = 0 ) :: GOTO &LEAVE :: ENDIF */
		/* ---------------------------------------------- */
		if (!( xptr = clf_len_dollar( lptr )))
			return((TCVARPTR) 0);
		else if ( generate_compare( _CMP_EQ, xptr, integer_result(0), _LOGICAL_AND, 0) != 0)
			return((TCVARPTR) 0);

		/* ---------------------------------------------- */
		/* TOKEN = TOKENISER( LISTE, 1, PUNCTUATION )	  */
		/* ---------------------------------------------- */
		if (!( xptr = clf_tokeniser( lptr, 1, rptr )))
			return((TCVARPTR) 0);
		else if (!( generate_affectation( vptr, xptr, FAUX )))
			return((TCVARPTR) 0);
		else 	return((TCVARPTR) 0);
		}
}

TCVARPTR	for_initialisation(int * mode)
{
	TCVARPTR	vptr;
	TCVARPTR	svptr;
	RESULTPTR	rptr;
	RESULTPTR	lptr;
	WORD		operator;
	WORD		status;
	*mode = 0;
	if ((vptr = primary_variable()) != (TCVARPTR) 0) {

		if ( is_equals() ) {

			/* ----------------------------- */
			/* FOR <variable> = <expression> */
			/* ----------------------------- */
			if ((lptr = evaluate_expression(0)) != (RESULTPTR) 0) {
				if ( OtrOption.ListFlag & 1 )
					echo_for( vptr, lptr, 0 );
				if ( OtrOption.Optimise )
					if (!( lptr = convert_to_type( lptr,(vptr->type->type & _TYPE_BASIC))))
						return((TCVARPTR) 0);
				if ( generate_affectation( vptr, lptr,FAUX ) == 0 )
					return( vptr );
				}
			}
//#ifdef	ABALV33
		else if ( is_mnemonic( "IN" ) ) {
			/* ---------------------------- */
			/* FOR <variable> IN <variable> */
			/* ---------------------------- */
			if (!( get_token() )) {
				(void) syntax_error(173);
				return((TCVARPTR) 0);
				}

			else if (!(svptr = primary_variable())) {
				(void) syntax_error(173);
				return((TCVARPTR) 0);
				}

			else if ( is_mnemonic( "USING" ) ) {
				if (!( rptr = evaluate_expression(0))) {
					(void) syntax_error(173);
					return((TCVARPTR) 0);
					}
				}

			else if (!( rptr = (RESULTPTR) string_result( " " ) )) {
				(void) syntax_error(173);
				return((TCVARPTR) 0);
				}

			*mode = 1;
			generate_for_in( vptr,svptr, rptr );
			return((TCVARPTR) 0);

			}
//#endif
		else if ( OtrOption.Enhanced & _ENHANCED_AFFECTATION ) {

			/* ---------------------------------------- */
			/* FOR <variable> <operator> = <expression> */
			/* ---------------------------------------- */
			if (((operator = collect_legal_operator()) != 0)
			&&  ( is_equals() )
			&&  ((rptr = evaluate_expression(0)) != (RESULTPTR) 0)
			&&  ((lptr = variable_result( vptr )) != (RESULTPTR) 0)) {
				if ( OtrOption.ListFlag & 1 )
					echo_for( vptr, rptr, operator );
				if (((rptr = evaluate_operation( operator,lptr, rptr )) != (RESULTPTR) 0)
				&&  ((status = generate_affectation( vptr, rptr,FAUX )) == 0))
					return( vptr );
				}
			}
		}

	/* All "for_initialisation" errors arrive here */
	/* ------------------------------------------- */ 
	return((TCVARPTR) 0);
}

WORD	generate_to( lptr, rptr, steptr, corps )
RESULTPTR	lptr;
RESULTPTR	rptr;
RESULTPTR	steptr;
WORD		corps;
{
	RESULTPTR	zptr;
	WORD		status;
	WORD		label;

	if  ((lptr = ensure_register( lptr )) != (RESULTPTR) 0) {

		/* Incremental Step Comparison */
		/* --------------------------- */
		if ( steptr == (RESULTPTR) 0)
			return( evaluate_comparison(_CMP_GR,lptr,rptr,_LOGICAL_END,0));

		/* Complex STEP comparison */
		/* ----------------------- */
		label = new_implicite_label();
		if ((zptr = integer_result( 0 )) == (RESULTPTR) 0)
			return( allocation_failure() );
		else if ((status = evaluate_comparison(_CMP_GE,steptr,zptr,_LOGICAL_USE,label)) != 0)
			return( status );
		else if ((status = evaluate_comparison(_CMP_LS,lptr,rptr,_LOGICAL_END,0)) != 0)
			return( status );
		else if ((status = implicite_goto(corps)) != 0)
			return( status );
		else if ((status = dcl_implicite_label( label )) != 0)
			return( status );
		else	return( evaluate_comparison(_CMP_GR,lptr,rptr,_LOGICAL_END,0));
		}
	else	return( syntax_error(171) );
}

RESULTPTR	translate_to()
{
	RESULTPTR	rptr=(RESULTPTR) 0;
	if (( get_token() )
	&&  ( is_control_keyword() == _CTRL_TO ))
		rptr = evaluate_expression(0);
	return( rptr );
}


RESULTPTR	generate_step( vptr, rptr )
TCVARPTR	vptr;
RESULTPTR	rptr;
{
	RESULTPTR	lptr;
	if ( rptr != (RESULTPTR) 0) {
		if (((lptr = variable_result( vptr )) != (RESULTPTR) 0)
		&&  ((rptr = arithmetic('+',lptr,rptr)) != (RESULTPTR) 0)
		&&  ( generate_affectation( vptr, rptr,FAUX ) == 0 ))
			return( rptr );
		else	{
			(void) syntax_error(172);
			return((RESULTPTR) 0);
			}
		}
	else	return( increment_variable( vptr ) );
}

RESULTPTR	translate_step()
{
	RESULTPTR	rptr=(RESULTPTR) 0;
	if ( get_token() ) 
		if ( is_control_keyword() == _CTRL_STEP )
			rptr = evaluate_expression(0);

	if ( OtrOption.ListFlag  & 1)
		echo_step( rptr );

	return( rptr );
}

/*
 *	-----------------------------------
 *	FOR <variable> IN <source_variable>
 *	-----------------------------------
 *	This construction will cut the  source variable into white space
 *	separated tokens returned in the target variable at each iteration.
 *	The iteration will terminate when the source variable becomes an 
 *	empty string.
 *	
 *	WHILE ( LEN$(SV) <> 0 )
 *		V = TOKEN( SV )
 *	&CORPS
 *
 *	WEND
 *
 *	---------------------------------------------------------------
 *	FOR <variable> = <expression> TO <expression> STEP <expression>
 *	---------------------------------------------------------------
 *	The FOR NEXT iteration is probably the most complicated aspect 
 *	of ABAL translation constructions.
 *
 *		AFFECTATION
 *		GOTO &CORPS
 *
 *	&TO1	INITIALISATION OF TO EXPRESSION
 *		RETURN
 *	***	GOTO &TO2				(if TO_INIT has size)
 *
 *	-----------------------------------------
 *	e n t e r    i t e r a t i o n    h e r e
 *	-----------------------------------------
 *
 *	&STEP	STEP EXPRESSION
 *		PUSH REGISTER 
 *		GOSUB &TO1 
 *		POP  REGISTER 
 *	***	GOTO &TO1				(if TO_INIT has size)
 *
 *	&TO2	TO COMPARE EXPRESSIONS
 *
 *	&CORPS	BODY OF ITERATION
 *
 *	-----------------------------------------
 *	l e a v e    i t e r a t i o n    h e r e
 *	-----------------------------------------
 *
 *		GOTO &STEP
 *	&EXIT
 */

WORD	translate_for()
{
	WORD	HoldForce;
	WORD		status;
	WORD		adrcmp1;
	WORD		corps;
	WORD		labelT1;
	WORD		labelT2;
	int		xmode=0;

	TCVARPTR	vptr=(TCVARPTR) 0;
	RESULTPTR	toptr=(RESULTPTR) 0;
	RESULTPTR	steptr=(RESULTPTR) 0;
	RESULTPTR	cmptr=(RESULTPTR) 0;

	/* ----------------------------- */
	/* FOR <variable> = <expression> */
	/* ----------------------------- */

	if ( OtrOption.ListFlag & 1 )
		echo_for_prefix();
	if (!( get_token() ))
		return( syntax_error(173) );
	else if ((vptr = for_initialisation(&xmode)) == (TCVARPTR) 0) {
		if (!( xmode ))
			return( syntax_error(174) );
		else	return( 0 );
		}
	else if ((status = implicite_goto((corps = new_implicite_label()) )) != 0)
		return( status );
	else if ((status = dcl_implicite_label((labelT1 = new_implicite_label()))) != 0)
		return( status );
	else	labelT2 = new_implicite_label();

	/* --------------- */
	/* TO <expression> */
	/* --------------- */

	adrcmp1 = current_tcode_offset();

	if ((toptr = translate_to()) == (RESULTPTR) 0)
		return( syntax_error(175) );
	else if (adrcmp1 != current_tcode_offset()) {
#ifndef	OLDFORNEXT
		generate_return();
#else
		if ((status = implicite_goto(labelT2)) != 0)
			return( status );
#endif
		}		
	else	labelT1 = labelT2;


	if ( OtrOption.ListFlag & 1)
		echo_to( toptr );

	/* ----------------- */
	/* STEP <expression> */
	/* ----------------- */

	if ((status = enter_iteration( _ITERATION_FOR, vptr )) != 0)
		return( status );

	steptr = translate_step();

	HoldForce = ForceLDV;
	ForceLDV = VRAI;
	cmptr = generate_step( vptr, steptr );
	ForceLDV = HoldForce;
	if (!( cmptr ))
		return( syntax_error(176) );

#ifndef	OLDFORNEXT
	if ( labelT1 != labelT2 ) {
		if ((status = generate_push(cmptr->value)) != 0)
			return( status );
		else if ((status = implicite_gosub(labelT1)) != 0)
			return( status );
		else if ((status = generate_pop(cmptr->value)) != 0)
			return( status );
		}
#else

	if (( labelT1 != labelT2 )
	&&  ((status = implicite_goto(labelT1)) != 0))
		return( status );
	else if ((status = dcl_implicite_label(labelT2)) != 0)
		return( status );
#endif
	if ((status = generate_to( cmptr, toptr, steptr, corps )) != 0)
		return( status );
	if ( OtrOption.ListFlag & 1 )
		restart_echo();
	return( dcl_implicite_label(corps) );

}

WORD	translate_next()
{
	TCVARPTR	vptr;
	trace("translate_next()\n");
	signal_new_line(FAUX);
	if (( get_token() )
	&&  (iteration_type() == _ITERATION_FOR)
	&&  ((vptr = primary_variable()) != (TCVARPTR) 0)) {
		if (!( check_iteration_variable( vptr ) ))
			return(syntax_error(177));
		if ( OtrOption.ListFlag & 1 )
			echo_next( vptr );
		leave_iteration();
		return(0);
		}
	return(syntax_error(177));
}

WORD	translate_indirect_call()
{
	RESULTPTR	rptr;
	trace("translate_indirect_call()\n");
	if ( OtrOption.ListFlag & 1 )
		set_echo_prefix();
	if (((rptr = evaluate_expression(0)) != (RESULTPTR) 0)
	&&  ( is_right_brace()))
		return( activate_procedure((TCPRCPTR) 0, rptr,(TCPRCPTR) 0) );
	else	return( syntax_error(178) );
}

WORD	extern_call_procedure(TCPRCPTR pptr)
{
	RESULTPTR	rptr;
	TCVARPTR	vptr;

	trace("extern_call_procedure()\n");
	if (!( pptr ))
		return( syntax_error( 178 ) );
	else if (!( pptr->extcall ))
		return( syntax_error( 178 ) );
	else if (!( pptr->extitem ))
		return( syntax_error( 178 ) );
	else 	{
		if ((!(vptr = temp_variable( pptr->extcall )))
		||  (!(vptr->firstdim = (VPTR) integer_result( pptr->extitem )))
		||  (!(rptr = variable_result( vptr ))))  {
			return( syntax_error( 178 ) );
			}
		if ( OtrOption.ListFlag & 1 )
			set_echo_prefix();

		return( activate_procedure((TCPRCPTR) 0, rptr,pptr) );
		}
}

WORD	translate_callproc()
{
	TCPRCPTR	pptr;
	RESULTPTR	rptr;
	trace("translate_callproc()\n");
	if ((pptr = is_procedure()) == (TCPRCPTR) 0)
		return( MOINS_UN );
	else if (pptr->extcall != (TCVARPTR) 0) 
		return( extern_call_procedure( pptr ) );
	if ( OtrOption.ListFlag & 1 )
		set_echo_prefix();
	if ((rptr = integer_result( pptr->identity )) != (RESULTPTR) 0)
		return( activate_procedure(pptr, rptr,pptr) );
	else	return( allocation_failure() );
}

WORD	translate_dll_function()
{
	TCDLFPTR	fptr;

	trace("translate_dll_function()\n");
	if ((fptr = is_dll_function()) == (TCDLFPTR) 0)
		return( MOINS_UN );
	return( activate_dll_function(fptr) );
}

WORD	translate_call()
{
	trace("translate_call()\n");
	if ( is_left_brace() ) 
		return( translate_indirect_call() );
	else if (!( get_token() ))
		return( syntax_error(179) );
	else	return( translate_callproc() );
}

WORD	showme( msg )
BPTR	msg;
{
	sysprintf("%s",msg);
	return(1);
}	


RESULTPTR	ensure_LDV_register( RESULTPTR rptr )
{
	WORD	holder;
	holder = instruction_requires_LDV(1);
	rptr = ensure_register( rptr );
	holder = instruction_requires_LDV(holder);
	return( rptr );
}

WORD		translate_function_exit( rptr, tptr )
RESULTPTR	rptr;
TCTYPPTR	tptr;
{
	WORD	status=0;
	if ((tptr->type & _TYPE_POINTER) != _TYPE_POINTER) {
		/* procedure requires a string type */
		/* -------------------------------- */
		if (( tptr->type & 3 ) > 1) {
			/* String types are always converted to a temporary form */
			/* ----------------------------------------------------- */
				if (!(rptr->contents))	/*BGI???*/
					if (!( rptr = convert_to_type( rptr, (WORD)(tptr->type & 3) )))
						return( syntax_error(180) );
				}
		if ( ( result_type( rptr ) & 3 ) > 1 ) {
			/* provided type mismatch so convert to required integer type */
			/* ---------------------------------------------------------- */
			if (!( rptr = convert_to_type( rptr, (WORD)(tptr->type & 7) )))
				return( syntax_error(180) );
			}
		if (!( rptr = ensure_LDV_register( rptr )))
			return( allocation_failure() );
		}
	else if ( is_method_function() ) {
		if (!(rptr->nature & _RESULT_POINTER )) {
			if (!(rptr = clf_reg_alias( rptr )))
				return( syntax_error(182) );
			}
		}
	else if (!( rptr = ensure_LDV_register( rptr )))
			return( allocation_failure() );

	if ((status = generate_copy_register( _EXIT_REGISTER, rptr->value )) != 0)
		return( status );
	else	return( generate_exit(rptr) );
}

WORD	overlay_method_parameter( object, field )
TCVARPTR	object;
WORD		field;
{
	RESULTPTR	rptr;
	if (( object != (TCVARPTR) 0 )
	&&  ( field == 0 )
	&&  ( object->type->size != 0 )) {
		if ((rptr = variable_result( object )) == (RESULTPTR) 0)
			return( allocation_failure() );
		else if ((rptr = clf_reg_alias( rptr )) == (RESULTPTR) 0)
			return( syntax_error(182) );
		return( generate_copy_register( _EXIT_REGISTER, rptr->value ));
		}
	return( 0 );
}

WORD	translate_procedure_exit( pptr )
TCPRCPTR	pptr;
{
	WORD		status=0;
	WORD		options=0;
	TCTYPPTR	tptr;
	RESULTPTR	rptr;
/*ESULTPTR	convert_to_type( RESULTPTR, WORD ); */

	if (((pptr->options & _RETURN_PROC))
	&&  ((tptr  = pptr->result) != (TCTYPPTR) 0 )) {
		if (( is_left_brace() ) 
		&&  (( rptr = evaluate_expression(0)) != (RESULTPTR) 0)
		&&  ( is_right_brace() )) {
			if ((status = comma_option(&options,'d', 'D' )) != 0 )
				return(status);
			else	return( translate_function_exit( rptr, tptr ) );
			}
		else	return( syntax_error(184)  );
		}
	else	{
		if ( is_left_brace() )
			return( syntax_error(185) );
		else if ((status = comma_option(&options,'d', 'D' )) != 0 )
			return(status);
		else	return( generate_exit((RESULTPTR) 0) );
		}
}

WORD	translate_exit()
{
	TCPRCPTR	pptr;
	WORD		status=0;
	trace("translate_exit()\n");
	if ( is_inline_function() )
		return( translate_inline_exit() );
	else if ((pptr = Context->PRC) == (TCPRCPTR) 0)
		return( syntax_error(183) );
	else if ((status = verify_destruction_abort()) != 0)
		return( status );
	else	return( translate_procedure_exit( pptr ) );
}

WORD	translate_leave()
{
	TCPRCPTR	pptr;
	trace("translate_exit()\n");
	if ( is_inline_function() )
		return( translate_inline_exit() );
	else if ((pptr = Context->PRC) == (TCPRCPTR) 0)
		return( translate_segment_return() );
	else	return( translate_procedure_exit( pptr ) );
}

WORD	translate_break()
{
	return( break_from_iteration() );
}

RESULTPTR	select_expression()
{
	RESULTPTR	lptr;
	if (((lptr = evaluate_expression(0)) != (RESULTPTR) 0)
	&&  ( is_constant_expression( lptr ) ))
		issue_warning( 8 );
	return( lptr );
}

WORD	translate_try()
{
	WORD		status;
	TCVARPTR	vptr=(TCVARPTR) 0;
	RESULTPTR	rptr=(RESULTPTR) 0;
	BYTE		label[64];
	trace("translate_try()\n");
	if ((status = enter_iteration( _ITERATION_TRY, (TCVARPTR) 0 )) != 0)
		return( status );
	else if (!( get_token() )) 
		return( syntax_error(143) );
	else if (!(vptr = is_variable(1))) 
		return( syntax_error(143) );
	else if ((rptr = variable_result( vptr )) == (RESULTPTR) 0)
		return( allocation_failure() );
	else if ((status = try_operand(rptr)) != 0 )
		return( allocation_failure() );
	else if (!( get_iteration_label( label ) ))
		return( allocation_failure() );
	else	return( explicite_on_error( rptr->contents, _CTRL_LOCAL, label ) );
}

WORD	translate_catch()
{
	RESULTPTR	lptr=(RESULTPTR) 0;
	RESULTPTR	rptr=(RESULTPTR) 0;
	WORD		nombre=0;
	WORD		status;
	WORD		operator;
	trace("\ntranslate_catch()\n");
	if (( iteration_type() == _ITERATION_TRY )
	&&  ((lptr = iteration_operand()) !=(RESULTPTR) 0)
	&&  ((status = break_prior_to_case()) == 0)
	&&  ((status = dcl_iteration_label()) != 0)
	&&  ((status = new_iterate_label()) != 0)) {
		if ( OtrOption.ListFlag & 1 )
			set_echo_prefix();
		do	{
			trace("catch_expression\n");
			if ((lptr = mark_live_result( lptr )) == (RESULTPTR) 0)
				return( internal_error(7) );
			if ((operator = comparison_operator(0)) == 0)
				operator = _CMP_IN;
			if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
				return( syntax_error(187) );
			if ( OtrOption.ListFlag & 1 )
				echo_case( nombre++, rptr );
			if ((status = evaluate_comparison(operator,lptr,rptr,_LOGICAL_OR,0)) != 0 )
				return( status );
			}
		while ( is_comma() );
		if ((status = verify_end_of_line()) != 0)
			return( status );
		if ( OtrOption.ListFlag & 1 )
			echo_case_end();
		generate_iteration();
		if (((status = dcl_operate_label()) != 0)
		&&  ((lptr = mark_dead_result( lptr )) != (RESULTPTR) 0)
		&&  ((status = new_operate_label()) != 0)) {
			force_newline();
			return(0);
			}
		}
	return( syntax_error(188) );
}

WORD	translate_endtry()
{
	if ( iteration_type() != _ITERATION_TRY )
		return( syntax_error(190) );
	leave_iteration();
	return( 0 );
}

WORD	translate_select()
{
	WORD	status;
	RESULTPTR	lptr=(RESULTPTR) 0;
	trace("translate_select()\n");
	if ( is_equals() ) {
		unget_byte();
		return( translate_sql_select() );
		}
	if ((status = enter_iteration( _ITERATION_SELECT, (TCVARPTR) 0 )) != 0)
		return( status );
	else if (((lptr = select_expression()) != (RESULTPTR) 0)
	     &&  ((lptr = ensure_register(lptr)) != (RESULTPTR) 0)
	     &&  ((status = select_operand(lptr)) == 0 )) {
		if ( OtrOption.ListFlag & 1 )
			echo_select( lptr );
		generate_iteration();
		return(0);
		}
	else	return( syntax_error(186) );
}

WORD	translate_case()
{
	RESULTPTR	lptr=(RESULTPTR) 0;
	RESULTPTR	rptr=(RESULTPTR) 0;
	WORD		nombre=0;
	WORD		status;
	WORD		operator;
	trace("\ntranslate_case()\n");
	if (( iteration_type() == _ITERATION_SELECT )
	&&  ((lptr = iteration_operand()) !=(RESULTPTR) 0)
	&&  ((status = break_prior_to_case()) == 0)
	&&  ((status = dcl_iteration_label()) != 0)
	&&  ((status = new_iterate_label()) != 0)) {
		if ( OtrOption.ListFlag & 1 )
			set_echo_prefix();
		do	{
			trace("case_expression\n");
			if ((lptr = mark_live_result( lptr )) == (RESULTPTR) 0)
				return( internal_error(7) );
			if ((operator = comparison_operator(0)) == 0)
				operator = _CMP_IN;
			if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
				return( syntax_error(187) );
			
			/* IJM 17/11/2006 : MASSA WEB SERVICE CASE BUG */
			operator = check_case_operator( rptr, operator );

			if ( OtrOption.ListFlag & 1 )
				echo_case( nombre++, rptr );
			if ((status = evaluate_case_comparison(operator,lptr,rptr,_LOGICAL_OR,0)) != 0 )
				return( status );
			}
		while ( is_comma() );
		if ((status = verify_end_of_line()) != 0)
			return( status );
		if ( OtrOption.ListFlag & 1 )
			echo_case_end();
		generate_iteration();
		if (((status = dcl_operate_label()) != 0)
		&&  ((lptr = mark_dead_result( lptr )) != (RESULTPTR) 0)
		&&  ((status = new_operate_label()) != 0)) {
			force_newline();
			return(0);
			}
		}
	return( syntax_error(188) );
}
WORD	translate_default()
{
	WORD	status;
	if (((status = iteration_type())  == _ITERATION_SELECT )
	&&  ((status = break_prior_to_case()) 		  == 0 )
	&&  ((status = dcl_iteration_label())   	  != 0 ))
		return( 0 );
	else	return( syntax_error(189) );
}
WORD	translate_endsel()
{
	if ( iteration_type() != _ITERATION_SELECT )
		return( syntax_error(190) );
	leave_iteration();
	return( 0 );
}

WORD	translate_then()
{
	WORD	status;
	trace("translate_then()\n");
	if ( iteration_type() != _ITERATION_EVENT )
		return( syntax_error(191) );
	else if ((status = generate_event_false()) != 0)
		return( status );
	else if ( dcl_abandon_label() == 0 )
		return( syntax_error(192) );
	else if ((status = generate_event_type( 1 )) != 0)
		return( status );
	else if ((status = enter_event_then()) != 0 )
		return( status );
	else	return( 0 );
}

WORD	translate_event_do()
{
	WORD	status;
	trace("translate_event_do()\n");
	if ((status = generate_event_false()) != 0)
		return( status );
	else if ( dcl_abandon_label() == 0 )
		return( syntax_error(193) );
	else if ((status = generate_event_type( 2 )) != 0)
		return( status );
	else if ((status = enter_event_do()) != 0 )
		return( status );
	else	return( 0 );
}

WORD	translate_do()
{
	WORD	status=0;
	trace("translate_do()\n");
	if ( awaiting_event_do() )
		return( translate_event_do() );
	else if ((status = enter_iteration( _ITERATION_DO,(TCVARPTR) 0 )) != 0)
		return( status );
	return(0);
}

WORD	translate_soft_event()
{
	WORD	status;

	trace("translate_soft_event()\n");
	if ((status = enter_iteration( _ITERATION_EVENT,(TCVARPTR) 0 )) != 0)
		return( status );
	else if ((status = generate_event()) != 0)
		return( status );
	else if ((status = goto_operation_label()) != 0)
		return( status );
	else if ((status = dcl_iteration_label()) == 0)
		return( syntax_error(194) );
	else if ((status = conditional_expression(2)) != 0 )
		return( status );
	else	return( 0 );
}

WORD	translate_end_code()
{
	WORD	n;

	if ( get_token() ) {
		switch 	((n = is_dcl_keyword())) {
			case _DCL_PROC	:	
				return( generate_proc_end() );
			case _DCL_USER  :
				strcpy(TokenBuffer,"END_USER");
				return( translate_clf() );
			default		:
				if  ( is_control_keyword() == _CTRL_SEG )
					return( generate_segm_end() );
				else 	return( syntax_error(195) );
			}
		}
	return( syntax_error(196) );
}

WORD	terminate_soft_event()
{
	WORD	type;
	trace("terminate_soft_event()\n");
	if ( is_period() ) 
		return( translate_end_code() );
	else	{
		if ( iteration_type() == _ITERATION_EVENT ) {
			if (( get_token()  )
			&&  ((type = is_control_keyword()) == _CTRL_EVENT )) {
				leave_iteration();
				return(0);
				}
			else	return( syntax_error(197) );
			}
		else if (( is_mnemonic("EXTERN") )
		     &&  ( is_mnemonic("EVENT" ) ))
			return( generate_event_off() );
		else	return( translate_end() );
		}
}

#ifdef	_BEFORE_19121996
WORD	translate_event_call()
{
	TCVARPTR	vptr=(TCVARPTR) 0;
	TCPRCPTR	pptr=(TCPRCPTR) 0;
	trace("translate_event_call()\n");
	if ( get_token() ) {
		if ((pptr = is_procedure()) != (TCPRCPTR) 0)
			return( event_call_procedure( pptr ) );
		else if ((vptr = is_variable(1))  != (TCVARPTR) 0)
			return( event_call_variable( vptr ) );
		else	return( syntax_error( 1198 ) ); 
		}
	else	return( syntax_error(1199) );
}
#else
WORD	translate_event_call(mode)
WORD	mode;
{
	TCVARPTR	vptr=(TCVARPTR) 0;
	TCPRCPTR	pptr=(TCPRCPTR) 0;
	trace("translate_event_call()\n");
	if ( get_token() ) {
		if ((pptr = is_procedure()) != (TCPRCPTR) 0)
			return( event_call_procedure( pptr,mode ) );
		else if ((vptr = is_variable(1))  != (TCVARPTR) 0)
			return( event_call_variable( vptr,mode ) );
		else	return( syntax_error( 1198 ) ); 
		}
	else	return( syntax_error(1199) );
}
#endif


WORD	translate_event(mode)
WORD	mode;
{
	WORD	type;
	WORD	label;

	if ( mode == MOINS_UN )
		return( translate_soft_event() );
	else	{
		if  ( get_token() ) {
			switch (((type = is_control_keyword()))) {
#ifdef	_BEFORE_19121996
				case _CTRL_GOTO  	: mode = 0; break;
				case _CTRL_GOSUB 	: mode = 1; break;
				case _CTRL_CALL		: return( translate_event_call() );
#else
				case _CTRL_CALLBACK	: return( translate_event_call(1) );
				case _CTRL_GOTO  	: mode = 0; break;
				case _CTRL_GOSUB 	: mode = 1; break;
				case _CTRL_CALL		: return( translate_event_call(0) );
#endif
				default			: return( translate_event_member() );
				}
			if (( get_label() )
			&&  ((label = use_explicite_label( TokenBuffer,2)) != 0)
			&&  ( generate_extern_event( mode,0 ) == 0))
				return( generate_label( label ) );

			}
		}
	return( syntax_error(199) );	
}

WORD	translate_on_error( mode )
WORD	mode;
{
	WORD		type;
	RESULTPTR	rptr;
	BYTE		label[64];
	if  ( get_token() ) {
		switch (((type = is_control_keyword()))) {
			case _CTRL_GOTO  	:	
				if ( get_label() ) {
					strcpy( label,TokenBuffer );
					if (( is_comma() )
					&&  ((rptr = evaluate_expression(0)) != (RESULTPTR) 0))
						return( explicite_on_error( rptr->contents, mode, label ) );
					}
				break;

			case _CTRL_ABORT 	: 
				return( generate_error_abort() );
			}
		}
	return( syntax_error(200) );	

}

WORD	translate_error(mode)
WORD	mode;	/* 0 : ERROR,  1 : RAISE THROW */
{
	WORD		braces;
	RESULTPTR	rptr;
	braces = is_left_brace();
	if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0) {
		if (!( mode ))
			return( syntax_error(201) );
		else if (((rptr = exception_operand()) == (RESULTPTR) 0)
		     &&  ((rptr = integer_result( pragma_throw() )) == (RESULTPTR) 0))
			return( allocation_failure() );
		}
	if ((braces)
	&&  (!(is_right_brace())))
		return( unmatched_braces() );
	else	return( generate_error(rptr) );
}

WORD	translate_timer( mode )
WORD	mode;
{
	TCPRCPTR	pptr;
	WORD		type;
	RESULTPTR	rptr;
	if  (((rptr = evaluate_expression(0)) != (RESULTPTR) 0) 
	&&   ( get_token() )) {
		switch (((type = is_control_keyword()))) {
			case _CTRL_GOTO  	: type = 1; break;
			case _CTRL_GOSUB 	: type = 2; break;
			case _CTRL_CALL		: type = 3; break;
			default			: return( syntax_error(202) );	
			}
		if ( type < 3 ) {
		if ( get_label() ) {
			if ( OtrOption.ListFlag & 1 )
				echo_on_timer( rptr, type, TokenBuffer );
			if ( generate_on_timer( rptr, type ) == 0 )
				return( generate_label( use_explicite_label( TokenBuffer, 0 ) ) );
			}
		}
		else if ( get_token() ) {
			/* optional braces */
			/* --------------- */
			if ( is_left_brace() )
				if (!( is_right_brace() ))
					return( unmatched_braces() );
			if ((pptr = is_procedure()) != (TCPRCPTR) 0) {
				if ( pptr->identity == MOINS_UN )
					(void) rellocate_external_procedure( pptr );
				if ( generate_on_timer( rptr, type ) == 0 )
					return( tcode_procedure( pptr ) );
				}

			}
		}
	return( syntax_error(203) );	
}

WORD	translate_timer_off()
{
	WORD	type;
	if ((get_token())
	&&  ((type = is_control_keyword()) == _CTRL_OFF)) {
		if ( OtrOption.ListFlag & 1 )
			echo_timer_off();
		return( generate_on_timer((RESULTPTR) 0, 0 ));
		}
	else	return( syntax_error(218) );
}

/*
 *
 *	ON <expression> GOTO <label_less>, <label_zero>, <label_more>
 *
 *	Note : In BAL/ABAL Compatible mode all labels are mandatory !
 *
 */

WORD	translate_on_expression( braces )
WORD	braces;
{
	RESULTPTR	rptr;
	RESULTPTR	zptr;
	WORD		status;
	WORD		label;

	trace("translate_on()\n");

	if ( braces ) {
		if ((rptr = evaluate_expression(0))   == (RESULTPTR) 0)
			return( syntax_error(204) );
		else if (!( is_right_brace() ))
			return( unmatched_braces() );
		}
	else if ((rptr = symbolic_term()) == (RESULTPTR) 0)
		return( syntax_error(205) );

	if (((rptr = ensure_register( rptr )) != (RESULTPTR) 0)
	&&  ((zptr = integer_result( 0 ))     != (RESULTPTR) 0)
	&&  ( get_token() )) {

		if (((status = is_control_keyword()) == _CTRL_GOTO)
		&&   ( get_label() )) {
			label = use_explicite_label( TokenBuffer, 2+WORDSIZE );
			if ((status = evaluate_comparison(_CMP_LS,rptr,zptr,_LOGICAL_LAB,label)) != 0 )
				return( status );
			if (( is_comma() )
			&&  ( get_label())) {
				label = use_explicite_label( TokenBuffer, 2+WORDSIZE );
				if ((status = evaluate_comparison(_CMP_EQ,rptr,zptr,_LOGICAL_LAB,label)) != 0 )
					return( status );
				if ( is_comma() )
					return( translate_goto() );
				}
			}
		}
	return( syntax_error(206) );
}

WORD		reset_affectation( status )
WORD		status;
{
	Context->TargetVariable = (TCVARPTR) 0;
	Context->UseTarget	= 0;
	Context->OperandType    = 2;
	Context->ConvertType    = 2;
	AllowAutoConv(0);
	return( status );
}

WORD	translate_of()
{
	RESULTPTR	rptr;
	RESULTPTR	zptr;
	WORD		status;
	WORD		label;
	WORD		type;
	WORD		nombre=0;
	WORD		backpatch=0;

	trace("translate_of()\n");

	Context->OperandType = 
	Context->ConvertType = _TYPE_INT16;

	rptr = evaluate_expression(0);
	(void) reset_affectation(0);

	if (!( rptr ))
		return( syntax_error(209) );

	if ( of_requires_register() ) {
		if (!(rptr = ensure_register( rptr  )))
			return( syntax_error(209) );
		of_release_register();
		}
		
	if (!(zptr = integer_result( 0 )))
		return( syntax_error(209) );

	if  ( get_token() ) {

		switch ((type = is_control_keyword())) {
			case _CTRL_GOTO  : type = 0; break;
			case _CTRL_GOSUB : type = 1; break;
 			default		 : return( syntax_error(207) );
			}
		if ( OtrOption.ListFlag & 1 )
			start_echo_of( rptr, type );

		if ((backpatch = generate_of( rptr, type )) == MOINS_UN)
			return( internal_error(20) );
		do	{
			if (!( get_label() ))	
				return( syntax_error(208) );
			if ( OtrOption.ListFlag & 1 )
				echo_of_label( nombre, TokenBuffer );
			tcode_label((label = use_explicite_label( TokenBuffer, 0 )));
			nombre++;
			}
		while ( is_comma() );
		if ( OtrOption.ListFlag & 1 )
			echo_line();
		if ((status = verify_end_of_line()) != 0)
			return( status );
		(void) backpatch_value( backpatch, nombre );
		return( 0 );
		}
	return( syntax_error(209) );
}

WORD	translate_on(level)
WORD	level;
{
	WORD	type;
	if ( is_left_brace() )
		return( translate_on_expression( VRAI ) );
	else if  ( get_token() ) {
		switch (((type = is_control_keyword()))) {
			case _CTRL_EXTERN	: 
			case _CTRL_LOCAL	: return( translate_on(type)      	);
			case _CTRL_EVENT	: return( translate_event(level)    	);
			case _CTRL_TIMER	: return( translate_timer(level)    	);
			case _CTRL_ERROR	: return( translate_on_error(level)    	);
			case MOINS_UN		: return( translate_on_expression(FAUX) );
			}
		}
	return( syntax_error(210) );	
}

WORD	translate_data()
{
	WORD	status;
	start_data_control();
	do	{
		if (get_token()) {
			if ((status = add_data_item( TokenBuffer )) != 0)
				return( status );
			}
		else	return( syntax_error(211) ); 
		Context->DataCount++;
		}
	while ( is_comma() );
	return( verify_end_of_line() );
}

WORD	translate_read_data()
{
	RESULTPTR	rptr;

	if (!( is_colon() ))
		return( syntax_error(212) );
	do	{
		if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
			return( syntax_error(213) ); 
		else if ( generate_read_data( rptr ) != 0 )
			return( syntax_error(214) );
		}
	while ( is_comma() );
	return( verify_end_of_line() );
}

WORD	translate_resume()
{
	WORD	label=0;
	WORD	mode;
	if ( is_ampersand() ) {
		unget_byte();
		if (!( get_token() ))
			return( syntax_error(215) );
		label = use_explicite_label( TokenBuffer, 1 );
		mode = VRAI;
		}
	else	mode = FAUX;
	if ( OtrOption.ListFlag & 1 )
		echo_resume( mode, TokenBuffer );
	return( generate_resume( mode, label ) );
}

WORD	translate_control_keyword()
{
	WORD	type;
	switch (((type = is_control_keyword()))) {
		case _CTRL_IF		: return(translate_if());
		case _CTRL_ELSE		: return(translate_else());
		case _CTRL_ENDIF	: return(translate_endif());
		case _CTRL_WHILE	: return(translate_while());
		case _CTRL_WEND		: return(translate_wend());
		case _CTRL_REPEAT	: return(translate_repeat());
		case _CTRL_UNTIL	: return(translate_until());	
		case _CTRL_FOR		: return(translate_for());
		case _CTRL_NEXT		: return(translate_next());
		case _CTRL_TRY		: return(translate_try());
		case _CTRL_CATCH	: return(translate_catch());
		case _CTRL_ENDTRY	: return(translate_endtry());
		case _CTRL_SELECT	: return(translate_select());
		case _CTRL_CASE		: return(translate_case());
		case _CTRL_DEFAULT	: return(translate_default());
		case _CTRL_ENDSEL	: return(translate_endsel());
		case _CTRL_THEN		: return( translate_then() );
		case _CTRL_OFF		:
		case _CTRL_TO		:	
		case _CTRL_STEP		: return( syntax_error(216) );
		case _CTRL_DO		: return(translate_do());
		case _CTRL_LOOP		: return(translate_loop());
		case _CTRL_BREAK	: 
			if ( exception_method_active() )
				(void) generate_exception_abort();
			return(translate_break());

		case _CTRL_GOSUB	: return( translate_gosub() );
		case _CTRL_RETURN	: return( generate_return() );
		case _CTRL_GOTO		: return( translate_goto() );
		case _CTRL_FMT		: return( translate_fmt()  );
		case _CTRL_CALL		: return( translate_call() );
		case _CTRL_EXIT		: return( translate_exit() );
		case _CTRL_LDGO		: 
			if (!( is_period() ))
				return( MOINS_UN );
			else	return( translate_ldgo_ret_seg(type) );

		case _CTRL_SEG		: return( syntax_error(217) );
		case _CTRL_RET		: 
			if (!( is_period() ))
				return( MOINS_UN );
			else	return( translate_ldgo_ret_seg(type) );

		case _CTRL_STOP		: return( translate_stop() );
		case _CTRL_DATA		: return( translate_data() );
		case _CTRL_ON		: return( translate_on( MOINS_UN ) );
		case _CTRL_OF		: return( translate_of() );
		case _CTRL_EVENT	: return( MOINS_UN ); /* See CLF7 */
		case _CTRL_RESUME	: return( translate_resume() );
		case _CTRL_ERROR	: return( translate_error(0) );
		case _CTRL_LOCAL	: return( translate_local() );
		case _CTRL_TIMER	: return( translate_timer_off() );
		case _CTRL_INITLOCAL	: return( clf_initlocal() );
		case _CTRL_INITGLOBAL	: return( clf_initglobal() );
		case _CTRL_EXTERN	: 	
		case MOINS_UN 		: return( MOINS_UN );
		default			: return( syntax_error(219) );
		}
	return( 0 );
}

WORD	translate_enter()
{
	return( not_yet_available() );
}

WORD	translate_level_two()
{
	WORD	type;
	switch (((type = is_level2_keyword()))) {
		case _KW2_ENDPROC: return( translate_endproc());
		case _KW2_ENDLOC : return( translate_endloc() );
		case _KW2_ESEG   : return( translate_eseg()   );
		case _KW2_ENTER	 : return( translate_enter()  );
		case _KW2_LEAVE	 : return( translate_leave()  );
		case MOINS_UN	 : return( MOINS_UN );
		}
	return( 0 );
}

WORD	level_one_extension()
{
	WORD	type;
	if ((type = translate_instance()) != MOINS_UN)
		return( type );
#ifdef	WITH_NURAL
	else if ((type = is_nural_keyword()) != MOINS_UN)
		return( translate_nural_keyword( type ) );
	else
#endif
	return( MOINS_UN );
}

WORD	translate_level_one()
{
	WORD	type;
	switch (((type = is_level1_keyword() ))) {
		case _KW1_LOCAL	    : return( translate_local() );
		case _KW1_CONST	    :
		case _KW1_DCL	    :
		case _KW1_PTR	    :
		case _KW1_ARG       : return( translate_declaration(type) );	
		case _KW1_CLASS     : return( translate_class(type,0));
		case _KW1_UNION     : return( translate_union(0,type));
		case _KW1_STRUCT    : return( translate_struct(type) );
		case _KW1_ENDCLASS  : return( translate_endclass(type));
		case _KW1_ENDUNION  : 
		case _KW1_ENDSTRUCT : return( translate_endstruct(type) );
		case _KW1_FIELD     : return( translate_field()    );
#ifdef	_KW1_EXPORT
		case _KW1_EXPORT   : return( translate_export()   );
#endif
		case _KW1_EXTERN    : return( translate_extern()   );
		case _KW1_FORWARD   : return( translate_forward()  );
		case _KW1_END	    : return( terminate_soft_event() );
		case _KW1_PUBLIC    : return( translate_public()   );
		case _KW1_PRIVATE   : return( translate_private()  );
		case _KW1_LIBRARY   : return( translate_class_dll());
		case MOINS_UN	    : return( level_one_extension() );
		default		    : return( syntax_error(220)     );
		}
  	return( 0 );
}

WORD	translate_affect_label( vptr )
TCVARPTR	vptr;
{
	RESULTPTR	rptr;
	if ((!( OtrOption.Enhanced & _ENHANCED_LABEL ))
	||  (!( get_token()        )) )
		return( syntax_error(221) );
	else if ((rptr = integer_result( use_explicite_label( TokenBuffer, 2) )) == (RESULTPTR) 0)
		return( allocation_failure() );
	else if ((rptr = ensure_register( rptr )) == (RESULTPTR) 0)
		return( allocation_failure() );
	else	return( generate_affectation( vptr , rptr,VRAI ) );
}

WORD	variable_affectation( vptr )
TCVARPTR	vptr;
{
	RESULTPTR	rptr;
	WORD		status;

	if ( OtrOption.ListFlag & 1 )
		set_echo_prefix();

	Context->TargetVariable = vptr;
	Context->OperandType =
	Context->ConvertType = (vptr->type->type & _TYPE_BASIC);

	if ( is_equals() ) {
		if ( is_ampersand() ) {
			unget_byte();
			return( reset_affectation(translate_affect_label( vptr )) );
			}
		if  ((rptr = evaluate_expression(1)) != (RESULTPTR) 0) {
			if ( Context->TargetVariable != (TCVARPTR) 0)
				return((status = reset_affectation( generate_affectation( vptr, rptr,VRAI ) )) );
			else	return((status = reset_affectation(  0 )));
			}
		else	return((status = reset_affectation( syntax_error(222) )) );
		}
	else	{
		if (( OtrOption.Enhanced & _ENHANCED_AFFECTATION )
		/* ------------------------------------------------- */
		/* Heiroglyphic C operations += -= *= /= %= != -- ++ */
		/* ------------------------------------------------- */
		&&  ((status = affectation_expression(vptr)) == 0))
			return((status = reset_affectation( 0 )) );
		else	return((status = reset_affectation( syntax_error(223) )) );
		}
}

WORD	translate_affectation()
{
	TCVARPTR	vptr;
	trace("translate_affectation()\n");

	if ((vptr = is_variable(1)) == (TCVARPTR) 0)
		return( MOINS_UN );

	return( variable_affectation( vptr ) );

}

WORD	translate_terminal_member( vptr )
TCVARPTR	vptr;
{
	return( variable_affectation(collect_dimensions( vptr ) ));
}

WORD	translate_statement()
{
	WORD	status;
	if (((status = translate_parameter_statement()) == MOINS_UN )
	&&  ((status = translate_local_statement())     == MOINS_UN )
	&&  ((status = translate_member_statement())    == MOINS_UN )
	&&  ((status = translate_object_statement())    == MOINS_UN )
	&&  ((status = translate_affectation())  	== MOINS_UN )
	&&  ((status = translate_callproc())     	== MOINS_UN )
	&&  ((status = translate_dll_function()) 	== MOINS_UN ))
		return( MOINS_UN );
	else	return( status   );
}

WORD	segmental_translation()
{
	WORD	type;
	if ( remove_white_space() ) {
		if ((type = set_correspondance()) != 0)
				return( type );
		else if (get_token()) {
			if (( translate_control_keyword() == MOINS_UN )
			&&  ( translate_statement()       == MOINS_UN )
			&&  ( translate_clf()             == MOINS_UN )
			&&  ( translate_iof()             == MOINS_UN )
			&&  ( translate_ngf()             == MOINS_UN )
			&&  ( translate_level_one() 	  == MOINS_UN )
			&&  ( translate_level_two() 	  == MOINS_UN ))
				return( syntax_error(224) );
			else	return( 0 );
			}
		else	return( verify_end_of_line() );
		}
	else	return(0);
		
}


WORD	translate_segment()
{
	WORD	identity=MOINS_UN;
	WORD	options=0;
	WORD	c;
	WORD	status=0;
	BYTE	nomseg[256];
	BPTR	nptr=(BPTR) 0;

	trace("translate_segment()\n");

	/* ensure complete closure of external fields */
	while ( close_extern_field(0) != 0 );

	if ((c = is_numeric()) != 0)
		identity = integer_expression();
	else if (!( get_token() ))
		return( syntax_error(225) );
	else 	strcpy( (nptr = (BPTR) nomseg), TokenBuffer );

	if ( is_known_segment(identity, nptr ) ) {
		return( syntax_error(225) );
		}

	if ( is_comma() ) {
		if (remove_white_space()) {
			c = get_byte();
			if (( c == 'r') || (c == 'R'))
				options = 1;
			else	return( syntax_error(226));
			}
		else	return( syntax_error(227));
		}
	if ((status = add_segment( identity, options, nptr, VRAI )) != 0 )
		return( status );
	else	return( enter_segmental_translation() );

}

WORD	no_operation( )
{
	return( 48 );
}

WORD	translate_end()
{
	WORD status=0;

	if (Context->CurrentSegment != (TCSEGPTR) 0) {
		status += terminate_segment( Context->CurrentSegment->identity, (BPTR) 0, 0 );
		leave_segmental_translation();
		issue_warning(9);
		}
	else if (Context->PRC != (TCPRCPTR) 0) {
		status += terminate_procedure();
		leave_segmental_translation();
		issue_warning(9);
		}

	/* Check for Segment 0 */
	/* ------------------- */
	if ((!(context_is_module))
	&&  (Context->Started != 2)
	&&  (!(Context->SegmentZero))) {
		status += implicite_segment_zero();
		signal_new_line(0);
		status += terminate_segment( 0, (BPTR) 0, FAUX );
		}

	status += terminate_tcode();
	flush_operation_pointers();
	Context->operation = no_operation;
	/* close all sources */
	terminate_world_endif();
	return( terminate_world_input( status ) );
}

WORD	enter_procedure_translation()
{
	push_operation_pointer();
	set_operation_pointer(segmental_translation);
	return(0);
}

WORD	translate_procedure()
{
	WORD	status;

	/* ensure complete closure of external fields */
	while ( close_extern_field(0) != 0 );

	if ((status = translate_proc()) == 0)
		return( enter_procedure_translation() );
	else	return( status );
}

WORD	translator_code_or_data()
{
	WORD	type=0;
	WORD	status;

	if ( remove_white_space() ) {
		set_correspondance();
		if (get_token()) {
			switch (((type = is_level1_keyword()))) {
				case _KW1_LOCAL	    : return( translate_local() );
				case _KW1_CONST     :
				case _KW1_DCL	    :
				case _KW1_PTR	    :
				case _KW1_ARG       : return( translate_declaration(type) );	
				case _KW1_CLASS     : return( translate_class(type,0)     );
				case _KW1_UNION     : return( translate_union(0,type)     );
				case _KW1_STRUCT    : return( translate_struct(type)      );
				case _KW1_ENDCLASS  : return( translate_endclass(type)    );
				case _KW1_ENDUNION  : 
				case _KW1_ENDSTRUCT : return( translate_endstruct(type)   );
				case _KW1_FIELD     : return( translate_field()    );
				case _KW1_EXTERN    : return( translate_extern()   );
				case _KW1_EXPORT    : return( translate_export()   );
				case _KW1_FORWARD   : return( translate_forward()  );
				case _KW1_PROC      : return( translate_procedure());
				case _KW1_SEGMENT   : return( translate_segment()  );
				case _KW1_END       : return( translate_end()      );
				case _KW1_PUBLIC    : return( translate_public()   );
				case _KW1_PRIVATE   : return( translate_private()  );
				case _KW1_LIBRARY   : return( translate_class_dll());
				case MOINS_UN	    : 
					if ((status = level_one_extension()) != MOINS_UN)
						return( status );
					else	return( translate_object_message() );
				default		    : return( syntax_error(228)       );
				}
			}
		else	return( verify_end_of_line() );
  		}
	else	return(0);
}

WORD	enter_global_translation()
{
	push_operation_pointer();
	set_operation_pointer(translator_code_or_data);
	set_global_scope();
	return(0);
}

WORD	leave_global_translation()
{
	pop_operation_pointer();
	return(0);
}

static	WORD	translate_module_instance()
{
	WORD	status;

	if (!( get_token() ))
		return( syntax_error( 1001 ) );

	else if ((status = instance_module( TokenBuffer )) == 0)
		return( await_target_end() );
	else	return( status );
}


static	WORD	translate_program_instance()
{
	WORD	status;

	if (!( get_token() ))
		return( syntax_error( 1001 ) );

	else if ((status = instance_program( TokenBuffer )) == 0)
		return( await_target_end() );
	else	return( status );
}

static	WORD	translate_program_object( type )
WORD	type;
{
	WORD	status;

	if ( is_mnemonic("OVERLAY") )
		Context->options |= _CONTEXT_OVERLAY;
	else if ( is_mnemonic("OCX") )
		Context->options |= _CONTEXT_OCX;

	if (( status = start_tcode()) != 0)
		return( status );

	generate_header( Context->identity, Context->options, MOINS_UN );

	if ((status = enter_global_translation()) != 0 )
		return( status );

	push_operation_pointer();
	set_operation_pointer(translate_program_instance);

	return( 0 );
}

static	WORD	translate_module_object( type )
WORD	type;
{
	WORD	status;

	if ( is_mnemonic("OVERLAY") )
		return( syntax_error( 56 ) );
	if (( status = start_tcode()) != 0)
		return( status );
	generate_header( Context->identity, Context->options, MOINS_UN );
	if ((status = enter_global_translation()) != 0 )
		return( status );

	push_operation_pointer();
	set_operation_pointer(translate_module_instance);

	return( 0 );
}

static	WORD	translate_noclr()
{
	if ( is_comma() ) {
		if (!( remove_white_space() ))
			return( syntax_error( 981 ) );
		else if ( is_mnemonic( "NOCLR" ) )
			return(0);
		else if ( is_mnemonic( "NOFLUSH" ) ) {
			OtrOption.NoFlush = 1;
			return(0);
			}
		else	return( syntax_error( 981 ) );
		}
	else	{
		Context->options |= _CONTEXT_NOCLR;
		return( 0 );
		}
}

static	WORD	translate_program( type )
WORD	type;
{
	WORD	status=0;

	if ( get_token() ) {
		tcode_program_identity();
		if ((status = translate_noclr()) != 0)
			return( status );
		else if (( status = start_tcode()) != 0)
			return( status );
		else	{
			generate_header( Context->identity, Context->options, MOINS_UN );
			if ((status = enter_global_translation()) != 0)
				return( status );
			else	return( flush_world_members() );
			}
		}
	else	return(syntax_error(229));

}

static	WORD	translate_module( type )
WORD	type;
{
	WORD	status=0;

	if ( get_token() ) {
		tcode_program_identity();
		if ((status = translate_noclr()) != 0)
			return( status );
		else if (( status = start_tcode()) != 0)
			return( status );
		else	{
			generate_header( Context->identity, Context->options, MOINS_UN );
			return( enter_global_translation() );
			}
		}
	else	return(syntax_error(229));

}

WORD	start_program_or_module( type )
WORD	type;
{
	WORD	status=0;

	Context->options = type;

	if ( is_quote() ) {
		unget_byte();
		if ( type == _KW1_PROGRAM )
			return( translate_program(type) );
		else	return( translate_module(type)  );
		}
	else if ( type == _KW1_PROGRAM )
		return( translate_program_object(type) );
	else	return( translate_module_object(type)  );
}

WORD	translator_startup()
{
	WORD	type=0;
	if (get_uppercase_token()) {
		switch (((type = is_level1_keyword()))) {
			case _KW1_PROGRAM :
				return(start_program_or_module( _CONTEXT_PROGRAM ));
			case _KW1_MODULE  : 
				return(start_program_or_module( _CONTEXT_MODULE  ));
			case _KW1_LIBRARY :
				return(instance_library());
			case _KW1_STDC :
				return(instance_stdc());
			}
		}
	return(syntax_error(230));
}

/*	-------------------------------------------	*/
/*	PUBLIC REGION	:	INTERFACE FUNCTIONS	*/
/*	-------------------------------------------	*/

WORD	terminate_translation( abandon )
WORD	abandon;
{
	if (( Context != (TCFDTPTR) 0 )
	&&  ( Context->Started        )
	&&  (!( abandon              )))
		error_message( "End instruction expected" );

	terminate_tcode_context();

	return( abandon );
}

WORD	line_translation( line_buffer )
BPTR	line_buffer;
{
	WORD	status=0;

#ifdef WIN32
MI_TRACE_DCL_TFN("line_translation");
MI_TRACE((CI_TRA_F_PARAM, FILTER_OS, TFN, "line_buffer = %s", line_buffer));
#endif

	if (initialise_line_parser( line_buffer )) {

		if ((status = is_directive()) != MOINS_UN )
			return( translate_directive(status) );
		else if ((status = is_active_region()) != FAUX) {

			signal_new_line(VRAI);
			reset_symbol_module();
			do	{
				if ((status = (*Context->operation)()) != 0) {
					if ( status != MOINS_UN ) {
						if (!( OtrOption.TraceErrors ))
							return(status);
						else if ( error_limit_reached() )
							return( status );
						else	{
							status = 0;
							break;
							}
						}
					else	return( syntax_error( 6006 ) );
					}
				}
			while ( soft_newline() );
			}
		}
	return(status);
}

RESULTPTR	intrinsic_functions()
{
	return( (RESULTPTR) 0 );
}

VOID	echo_source_line( lptr )
BPTR	lptr;
{
	echo_line_prefix();
	if ( verify_world_list() ) {
		while (( *lptr ) && ( *lptr != 0x001A ) && ( *lptr != '\n'))
			fprintf( World->ListHandle ,"%c",*(lptr++));
		fprintf( World->ListHandle ,"\n");
		}
	else	{
	while (( *lptr ) && ( *lptr != 0x001A ) && ( *lptr != '\n'))
		sysprintf("%c",*(lptr++));
	sysprintf("\n");
		}
	return;
}


/*
 *	Called during MAIN after initialisation of Options to
 *	detect and honour any options specified by the relevant
 *	environment variable.
 *
 */

VOID	default_language_options()
{
	BPTR	eptr;
	BPTR	fptr;
	WORD	term;
#ifndef	PROLOGUE
	if ((eptr = sysgetenv("OTRDEF")) != (BPTR) 0) {
		while ( strlen(eptr) != 0 ) {
			fptr = eptr;
			while ( *fptr ) {
				if ( *fptr == ENV_FIELD )
					break;
				else 	fptr++;
				}
			if ((term = *fptr) == ENV_FIELD)
				*fptr = 0;
			(void) analyse_translator_options(eptr);			
			if ( term == ENV_FIELD )
				*(fptr++) = term;
			eptr = fptr;
			}		
		}
	return;
#endif
}

#endif 	/* _TRANSLAT_C */
	/* ----------- */

