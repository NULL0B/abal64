#define DEBUG
/* -------------------------------------------------------------------- */
/*                                                                      */
/*              Project ABAL : Macro pre-processer                      */
/*                                                                      */
/*               Copyright (c) 1990, 1994 Amenesik / Sologic s.a.                 */
/*                                                                      */
/*                                                                      */
/*              File    :       TRANSLAT.C                              */
/*              Version :       2.1c                                    */
/*              Date    :       28/09/1994                              */
/*                                                                      */
/* -------------------------------------------------------------------- */
#ifndef _TRANSLAT_C
#define _TRANSLAT_C

#include <stdio.h>              /* Standard IO handling routines        */
#include <errno.h>              /* Error return definitions             */
#include "stdtypes.h"
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
#include "trproc.h"
#include "trldf.h"
#include "trdebug.h"
#include "trgenc.h"
#include "trabc.h"

#ifdef  UNIX
WORD    translate_filler();
#else
WORD    translate_filler(VOID);
#endif

/* 
 * These Four Stub Functions are necessary in order to allow link of ATC
 * since the TRAPL module now calls these functions for the OTR ATOC
 * generation operations. They will have no effect in this old C 
 * generation version IJM April 98
 */

WORD atoc_create_library() { return(0); }

WORD atoc_close_library() { return(0); }

WORD atoc_constants() { return(0); } 

WORD atoc_put_class() { return(0); }

static  WORD    translator_code()
{
	return(57);
}

WORD    reverse_compare( opcode )
WORD    opcode;
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

WORD    collect_normal_operator()
{
	WORD    result=0;
	WORD    c;

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
				else    unget_byte();
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
				else    unget_byte();
				break;
					
			default  : unget_byte();
			}

		}
	return( result );       
}

#ifdef  _BEFORE_19031998

WORD    translate_variable(type,nature)
WORD    type;           /* DCL, PTR, ARG, CONST         */
WORD    nature;         /* DCL, PROC, SEGM, USER, CODE  */
{
	TCVARPTR        lvarb;
	WORD            l;
	BYTE            vname[65];
	WORD            vsize=8;
	WORD            vone=1;
	WORD            vtwo=1;
	WORD            vtype=2;
	WORD            i;

	l = strlen( TokenBuffer );

	if ( copy_token( vname, 64 ) == 0 )
		return( 30 );

	if ( type == _KW1_CONST ) {
		if (!( is_equals() ))
			return( syntax_error(23200) );
		switch ((TokenBuffer[(l-1)])) {
			case '#' : vsize = 1;
				   vtype = 0;
				   vname[(l-1)]=0;
				   break;
			case '%' : vsize = 2;  
				   vtype = 1;
				   vname[(l-1)]=0;
				   break;
			case '$' : vsize = 15;
				   vtype = 3;
				   vname[(l-1)]=0;
				   break;
			}

		/* Collect constant value */
		/* ---------------------- */
		if ( get_token() )
			return( add_constant( vname, vtype, TokenBuffer ) );
		else    return( syntax_error(23201) );
		}
	else if ( nature == _DCL_NORMAL ) {

		/* Collect possible length */
		/* ----------------------- */
		switch ((TokenBuffer[(l-1)])) {
			case '#' : if ( is_equals() )
					return(syntax_error(23202));
				   vsize = 1;
				   vtype = 0;
				   vname[(l-1)]=0;
				   break;
			case '%' : if ( is_equals() )
					return(syntax_error(23203));
				   vsize = 2;  
				   vtype = 1;
				   vname[(l-1)]=0;
				   break;
			case '$' : vsize = 15;
				   vtype = 3;
				   vname[(l-1)]=0;
			default  :
				if ( is_equals() )
					vsize = integer_expression();
			}
		}
	else    {
		/* PROC,SEGM,USER,CODE pointers */
		/* ---------------------------- */
		switch ((TokenBuffer[(l-1)])) {
			case '#'        :
			case '%'        :
			case '$'        :
				return( syntax_error(23204) );
			}
		vsize = 5;
		vtype = 3;
		}

	/* Collect possible dimensions */
	/* --------------------------- */
	if ( is_left_brace() ) {
		vone = integer_expression();
		vtype |= 0x0040;
		if ( is_comma() ) {
			vtwo = integer_expression();
			vtype |= 0x0020;
			}
		if (!( is_right_brace()))
			return( syntax_error(23205) );
		}

	if ( World->CurrentStructure != (TCSTRUCTPTR) 0)
		return( add_to_structure( vname, vtype, vsize, vone, vtwo, type, nature ) );
	else    return( add_variable( vname, vtype, vsize, vone, vtwo, type, nature, 0 ) );

}

WORD    translate_declaration(type) 
WORD    type;
{
	WORD    status=0;
	WORD    nature=0;
	WORD    n;

	while   (1)     {
		if (get_token()) {
			switch  ((n = is_dcl_keyword())) {
				case _DCL_LIKE  : return(syntax_error(23206));
				case _DCL_FILLER: if ( type != _KW1_CONST )
							return(translate_filler());
						  else  return(syntax_error(23207)); 
				case _DCL_PROC  :       
				case _DCL_SEGM  :
				case _DCL_USER  :
				case _DCL_CODE  : if ( type == _KW1_CONST )
							return( syntax_error(23208) );
						  nature = n;
						  continue;
				default         :
					if ((n = is_level1_keyword()) == _KW1_SEGMENT) {
						if ( type == _KW1_CONST )
							return( syntax_error(23209) );
						nature = _DCL_SEGM;
						continue;
						}
					else if ((status = translate_variable(type,nature)) != 0)
						return( status );
					else if (is_comma())
						continue;
					else    return(0);
				}
			}
		else    return(syntax_error(23210) );
		}

}

#else   /* AFTER_19031998   */
WORD    translate_variable( type, nature )
WORD    type;           /* DCL, PTR, ARG, CONST         */
WORD    nature;         /* DCL, PROC, SEGM, USER, CODE  */
{
	WORD            l;
	BYTE            vname[65];
	WORD            vsize=8;
	WORD            vone=1;
	WORD            vtwo=1;
	WORD            vtype=2;
	WORD            i;
	BPTR            vptr;

	trace("translate_variable()\n");

	l = strlen( TokenBuffer );

	if ( copy_token( vname, 64 ) == 0 )
		return( 30 );

	if ( type == _KW1_CONST ) {

		if (!( is_equals() ))
			return( syntax_error(140) );

		switch ((TokenBuffer[(l-1)])) {
			case '#' : vsize = 1;
				   vtype = 0;
				   vname[(l-1)]=0;
				   sprintf(TokenBuffer,"%u",integer_expression());
				   break;
			case '%' : vsize = 2;  
				   vtype = 1;
				   vname[(l-1)]=0;
				   sprintf(TokenBuffer,"%u",integer_expression());
				   break;
			case '$' : vsize = 15;
				   vtype = 3;
				   vname[(l-1)]=0;
				   if ( collect_string_litteral() == 0)
					return( syntax_error( 141 ) );
				   else break;
			default   :
				   if (!( evaluate_token() ))
					return( syntax_error(141) );
				   break;
			}

		/* Collect constant value */
		/* ---------------------- */
		if ( World->CurrentStructure != (TCSTRUCTPTR) 0)
			return( add_structure_constant( vname, vtype, TokenBuffer ) );
		else    return( add_constant( vname, vtype, TokenBuffer ) );
		}

	else if ( nature == _DCL_NORMAL ) {

		/* Collect possible length */
		/* ----------------------- */
		switch ((TokenBuffer[(l-1)])) {
			case '#' : if ( is_equals() )
					return(syntax_error(142));
				   vsize = 1;
				   vtype = 0;
				   vname[(l-1)]=0;
				   break;
			case '%' : if ( is_equals() )
					return(syntax_error(143));
				   vsize = 2;  
				   vtype = 1;
				   vname[(l-1)]=0;
				   break;
			case '$' : vsize = 15;
				   vtype = 3;
				   vname[(l-1)]=0;
			default  :
				if ( is_equals() )
					vsize = integer_expression();
			}
		}
	else    {
		/* PROC,SEGM,USER,CODE pointers */
		/* ---------------------------- */
		switch ((TokenBuffer[(l-1)])) {
			case '#'        :
			case '%'        :
			case '$'        :
				return( syntax_error(144) );
			}
		vsize = 5;
		vtype = 3;
		}

	/* Collect possible dimensions */
	/* --------------------------- */
	if ( is_left_brace() ) {
		vone = integer_expression();
		vtype |= 0x0040;
		if ( is_comma() ) {
			vtwo = integer_expression();
			vtype |= 0x0020;
			}
		if (!( is_right_brace()))
			return( unmatched_braces() );
		}

	if ( World->CurrentStructure != (TCSTRUCTPTR) 0)
		return( add_to_structure( vname, vtype, vsize, vone, vtwo, type, nature ) );
	else    return( declare_terminal( vname, vtype, vsize, vone, vtwo, type, nature, 0 ) );

}


WORD    translate_declaration(type) 
WORD    type;
{
	WORD    status=0;
	WORD    nature=0;
	WORD    n;

	while   (1)     {
		if (get_token()) {
			switch  ((n = is_dcl_keyword())) {
				case _DCL_LIKE  : return(syntax_error(0));
				case _DCL_FILLER: 
					if ( type != _KW1_CONST )
						return(translate_filler());
					else    return(syntax_error(145)); 
				case _DCL_PROC  :       
				case _DCL_SEGM  :
				case _DCL_USER  :
				case _DCL_CODE  : 
					if ( type == _KW1_CONST )
						return( syntax_error(146) );
					nature = n;
					continue;
				default         :
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
					else    return(verify_end_of_line());
				}
			}
		else if (!( class_definition_active() ))
			return(syntax_error(148) );
		else if (!( new_input_line() ))
			return( syntax_error(148) );
		}

}


#endif  /* _BEFORE_19031998 */


WORD    translate_filler()
{
	WORD    status;
	WORD    filler=0;
	if ( is_equals() ) {
		if (((status = dcl_filler((filler = integer_expression()))) == 0)
		&&  (is_comma()))
			return(translate_declaration(_KW1_DCL) );
		else    return( status );
		}
	else    return( syntax_error(23211) );  
}

WORD    translate_field() 
{
	WORD    c;
	WORD    status;
	if ( is_equals() ) {
		if (!(remove_white_space()))
			return(syntax_error(23212));
		if ( is_mnemonic("E") )
			field_equals_e();
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
		else    {                               
			Context->ThisField->Field = integer_expression();
			Context->ThisField->FileField = 0L;
			}

		Context->ThisField->Host = 0;

		if ( is_comma() ) {
			if ( get_token() )
				return( redefine_variable() );
			else    return( syntax_error(23213) );
			}
		else    {
			return(0);
			}
		}
	else    return( syntax_error(23214) );
}


WORD    translator_code_or_data(VOID);

WORD    enter_global_translation()
{
	push_operation_pointer();
	set_operation_pointer(translator_code_or_data);
	set_global_scope();
	return(0);
}

WORD    leave_global_translation()
{
	pop_operation_pointer();
	return(0);
}

VOID    leave_segmental_translation()
{
	liberate_local_symbols();
	initialise_field((FIELDPTR) & Context->LocalField );
	pop_operation_pointer();
	set_global_scope();
	return;
}

WORD    translate_endproc()
{
	WORD    status=0;
	BYTE    vname[65];
	trace("translate_endproc()\n");
	if ( Context->PRC == (TCPRCPTR) 0)
		return( syntax_error(23215) );
	else if (( get_token() )
	     &&  ( copy_token( vname, 64 ) )
	     &&  (!( compare_tokens( Context->PRC->name, vname ) )))
		return( syntax_error(23216) );
	status = terminate_procedure();
	leave_segmental_translation();
	return( status );
}


WORD    translate_eseg()
{
	WORD    status;
	WORD    identity;
	BYTE    nomseg[65];
	BPTR    nptr=(BPTR) 0;
	WORD    c;

	trace("translate_eseg()\n");

	if ((c = is_numeric()) != 0)
		identity = integer_expression();
	else if (!( get_token() ))
		return( syntax_error(155) );
	else    strcpy( (nptr = (BPTR) nomseg), TokenBuffer );

	status = terminate_segment( identity, nptr, FAUX );

	leave_segmental_translation();

	return( status );

}

WORD    translate_endloc()
{
	WORD    c;
	WORD    options=0;

	trace("translate_endloc()\n");
	if ( is_comma() ) {
		if (remove_white_space()) {
			c = get_byte();
			if (( c == 's') || (c == 'S'))
				options = 1;
			else    return( syntax_error(23218));
			}
		else    return( syntax_error(23218));
		}
	return( 0 );
}

#ifdef  _BEFORE_19031998

WORD    translate_ldgo_ret_seg( type )
{
	WORD            segid;
	BPTR            rptr;
	if (( is_period() )
	&&  ( get_token() )
	&&  ( is_control_keyword() == _CTRL_SEG )) {
		trace("translate_ldgo_ret_seg()\n");
		if ( type == _CTRL_RET )
			return( generate_retseg() );
		else    {
			if ((rptr = IntegerExpression()) != (BPTR) 0)
				return( generate_ldgoseg(rptr,MOINS_UN,MOINS_UN) );
			else    return( generate_ldgoseg_name( TokenBuffer ) );
			}
		}
	else    return( syntax_error(23220) );

}

#else

WORD    translate_segment_return()
{
	return( generate_retseg() );
}

WORD    translate_ldgo_ret_seg( type )
{
	WORD            segid;
	WORD            status=0;
	BPTR            rptr;
	if (( is_period() )
	&&  ( get_token() )
	&&  ( is_control_keyword() == _CTRL_SEG )) {
		trace("translate_ldgo_ret_seg()\n");
		if ( type == _CTRL_RET ) {
			if ((status = verify_destruction_abort()) != 0)
				return( status );
			else    return( translate_segment_return() );
			}
		else    {
			if ((rptr = IntegerExpression()) != (BPTR) 0)
				return( generate_ldgoseg(rptr,MOINS_UN,MOINS_UN) );
			else    return( generate_ldgoseg_name( TokenBuffer ) );
			}
		}
	else    return( syntax_error(158) );

}
#endif  /* _BEFORE_19031998 */
	/* ---------------- */

WORD    translate_gosub()
{
	TCVARPTR        vptr;
	RESULTPTR       rptr;
	trace("translate_gosub()\n"); 
	if ( get_token() )
		return( generate_gosub( TokenBuffer ) );
	else    return( syntax_error(23221) );
}

WORD    translate_goto()
{
	TCVARPTR        vptr;
	RESULTPTR       rptr;
	trace("translate_goto()\n"); 
	if ( get_token() )
		return( generate_goto_instruction( TokenBuffer ) );
	else    return( syntax_error(23222) );
}


WORD    translate_endif()
{
	WORD    status=0;
	if ( iteration_type() != _ITERATION_IF )
		return( syntax_error(23223) );
	leave_iteration();
	return(generate_endif());
}

BPTR    conditional_expression(repeat_until)
WORD    repeat_until;
{
	BPTR            lptr=(BPTR) 0;
	BPTR            rptr=(BPTR) 0;
	BPTR            xptr=(BPTR) "\0";
	WORD            operation;
	WORD            status;
	WORD            logic=_LOGICAL_END;
	WORD            more_logic=VRAI;
	WORD            braces;

	while (1) {

		if ((lptr = EvaluateExpression()) == (BPTR) 0)
			return(lptr);

		while ( is_right_brace() );

		if ((operation = comparison_operator(repeat_until)) != 0) {

			if ((rptr = EvaluateExpression()) == (BPTR) 0)
				return(rptr);

			}
		else    {
			if ( OtrOption.Enhanced & _ENHANCED_COMPARE ) {
				/* Allow Boolean Comparison (ie Not False) */
				/* --------------------------------------- */
				rptr = "0";
				if ( repeat_until)
					operation = _CMP_EQ;
				else    operation = _CMP_NE;
				}
			else    {
				(void) syntax_error(23224);
				return((BPTR) 0);
				}
			}

		while ( is_right_brace() );

		if ((more_logic = get_token()))  {
			if ((logic = is_logical_keyword()) == MOINS_UN) {
				(void) syntax_error(23225);
				return( (BPTR) 0 );
				}
			}
		else    logic = _LOGICAL_END;

		if ( repeat_until ) {
			if ( logic == _LOGICAL_AND )
				logic = _LOGICAL_OR;
			else if ( logic == _LOGICAL_OR )
				logic = _LOGICAL_AND;
			}

		if ((xptr = EvaluateComparison(operation,xptr,lptr,rptr,logic,0)) == (BPTR) 0)
			return( xptr );

		/* Terminate if Terminal Logic */
		/* --------------------------- */
		if (!(more_logic)) {
			while ( is_right_brace() );
			return( xptr );
			}
		}

}

WORD    translate_if()
{
	WORD            status=0;
	BPTR            condition;
	if ((status = enter_iteration( _ITERATION_IF,(TCVARPTR) 0 )) != 0)
		return( status );
	else if ((condition = conditional_expression(0)) == (BPTR) 0 )
		return( syntax_error(23226) );
	else if ( dcl_operate_label() == 0 )
		return( syntax_error(23227) );
	else if ( is_colon() ) {
		if ((status = generate_if(condition)) != 0)
			return( status );
		if ((status = (*Context->operation)()) != 0)
			return(status);
		else    return( translate_endif() );
		}
	else    return( generate_if(condition) );
}

WORD    translate_else()
{
	WORD    status=0;
	WORD    holder;
	if ( iteration_type() != _ITERATION_IF )
		return( syntax_error(23228) );
	generate_iteration();
	dcl_abandon_label();    
	return(generate_else());
}

WORD    translate_while()
{
	WORD    status=0;
	BPTR    condition;
	trace("translate_while()\n");
	if ((status = enter_iteration( _ITERATION_WHILE,(TCVARPTR) 0  )) != 0)
		return( status );
	else if ((condition = conditional_expression(0)) == (BPTR) 0) 
		return( syntax_error(23229)  );
	else    return( generate_while(condition) );
}

WORD    translate_wend()
{
	WORD    status=0;
	trace("translate_wend()\n");
	if ( iteration_type() != _ITERATION_WHILE )
		return( syntax_error(23230) );
	leave_iteration();
	return(generate_wend());
}

WORD    translate_break()
{
	return(generate_break());
}

WORD    translate_loop()
{
	WORD    status=0;
	if ( iteration_type() != _ITERATION_DO )
		return( syntax_error(23231) );
	leave_iteration();
	return( generate_loop() );
}

WORD    translate_repeat()
{
	WORD    status=0;
	if ((status = enter_iteration( _ITERATION_REPEAT,(TCVARPTR) 0  )) != 0)
		return( status );
	else if ( dcl_operate_label() == 0 )
		return( syntax_error(23232) );
	else    return( generate_repeat() );
}

WORD    translate_until()
{
	WORD    status=0;
	BPTR    condition;
	if ( iteration_type() != _ITERATION_REPEAT )
		return( syntax_error(23233) );
	condition = conditional_expression(1);
	leave_iteration();
	if ( condition != (BPTR) 0 )
		return(generate_until(condition));
	else    return( syntax_error(23234) );
}

/*
 *      ---------------------------------------------------------------
 *      FOR <variable> = <expression> TO <expression> STEP <expression>
 *      ---------------------------------------------------------------
 *      The FOR NEXT iteration is probably the most complicated aspect 
 *      of ABAL translation constructions.
 *
 *              AFFECTATION
 *              GOTO &CORPS
 *
 *      &TO1    INITIALISATION OF TO EXPRESSION
 *              GOTO &TO2                               (if TO_INIT has size)
 *
 *      -----------------------------------------
 *      e n t e r    i t e r a t i o n    h e r e
 *      -----------------------------------------
 *
 *      &STEP   STEP EXPRESSION
 *              GOTO &TO1                               (if TO_INIT has size)
 *
 *      &TO2    TO COMPARE EXPRESSIONS
 *
 *      &CORPS  BODY OF ITERATION
 *
 *      -----------------------------------------
 *      l e a v e    i t e r a t i o n    h e r e
 *      -----------------------------------------
 *
 *              GOTO &STEP
 *      &EXIT
 */

WORD    translate_for()
{

	RESULTPTR       rptr;
	TCVARPTR        vptr=(TCVARPTR) 0;
	BPTR            iptr=(BPTR) 0;
	BPTR            cptr=(BPTR) 0;
	BPTR            sptr=(BPTR) 0;
	WORD            status;
	RESULTPTR       primary_term();

	/* ----------------------------- */
	/* FOR <variable> = <expression> */
	/* ----------------------------- */

	if ((!( get_token() ))
	||  ((rptr = primary_term()) == (RESULTPTR) 0)
	||  (!( is_equals() )))
		return( syntax_error(23235) );
	else    vptr = rptr->contents;
	if ((status = enter_iteration( _ITERATION_FOR,vptr )) != 0)
		return( status );

	if ((iptr = TypedExpression((vptr->type->type & 3))) == (BPTR) 0)
		return( syntax_error(23236) );

	if ((!( is_mnemonic("TO") ))
	||  ((cptr = TypedExpression((vptr->type->type & 3))) == (BPTR) 0))
		return( syntax_error(23237) );

	if (( is_mnemonic("STEP") )
	&&  ((sptr = TypedExpression((vptr->type->type & 3))) == (BPTR) 0))
		return( syntax_error(23238) );

	return( generate_for(vptr,iptr,cptr,sptr) );

}

WORD    translate_next()
{
	trace("translate_next()\n");
	if (( get_token() )
	&&  (iteration_type() == _ITERATION_FOR)) {
		if ( is_left_brace() ) {
			(void) EvaluateExpression();
			(void) is_right_brace();
			}
		leave_iteration();
		return(generate_next());
		}
	return(syntax_error(23239));
}

WORD    translate_callproc()
{
	TCPRCPTR        pptr;
	BPTR            rptr;
	trace("translate_callproc()\n");
	if ((pptr = is_procedure()) == (TCPRCPTR) 0)
		return( MOINS_UN );
	else if ((rptr = IntegerResult( pptr->identity )) != (RESULTPTR) 0)
		return( activate_rtl_procedure(pptr, rptr) );
	else    return( allocation_failure() );
}

WORD    translate_dll_function()
{
	TCDLFPTR        fptr;
	RESULTPTR       rptr;
	trace("translate_dll_function()\n");
	if ((fptr = is_dll_function()) == (TCDLFPTR) 0)
		return( MOINS_UN );
	return( activate_dll_function(fptr) );
}

WORD    translate_indirect_call()
{
	BPTR    rptr;
	trace("translate_indirect_call()\n");
	if (((rptr = RtlProcedurePointer()) != (BPTR) 0)
	&&  ( is_right_brace()))
		return( activate_rtl_procedure((TCPRCPTR) 0, rptr) );
	else    return( syntax_error(23240) );
}

WORD    translate_call()
{
	trace("translate_call()\n");
	if ( is_left_brace() ) 
		return( translate_indirect_call() );
	else if (!( get_token() ))
		return( syntax_error(23241) );
	else    return( translate_callproc() );
}

WORD    showme( msg )
BPTR    msg;
{
	sysprintf("%s",msg);
	return(1);
}       

#ifdef  _BEFORE_19031998

WORD    translate_exit()
{
	WORD            status;
	WORD            rtype;
	TCPRCPTR        pptr;
	WORD            ptype;
	BPTR            rptr;
	BPTR            RtlConvertToType( BPTR, WORD );
	trace("translate_exit()\n");
	if ((pptr = Context->PRC) == (TCPRCPTR) 0)
		return( syntax_error(23242) );
	else if ((rtype = pptr->options & _RETURN_PROC) ) {
		if (( is_left_brace() ) 
		&&  (( rptr = TypedExpression((ptype = (((rtype >> 8) & 7) - 1)))) != (BPTR) 0)
		&&  ( is_right_brace() )) {
			if ((status = RtlExitValue( rptr, ptype )) != 0)
				return( status );
			else    return( generate_exit() );
			}
		return( syntax_error(23243)  );
		}
	else    {
		if ( is_left_brace() )
			return( syntax_error(23244) );
		else    return( generate_exit() );
		}
}

#else

WORD            translate_function_exit( rptr, tptr )
BPTR            rptr;
TCTYPPTR        tptr;
{
	BPTR            RtlConvertToType( BPTR, WORD );
	WORD    status=0;

	if ((status = RtlExitValue( rptr, tptr->type )) != 0)
		return( status );
	else    return( generate_exit() );
}

WORD    overlay_method_parameter( object, field )
TCVARPTR        object;
WORD            field;
{
#ifdef  _BEFORE_19031998
	RESULTPTR       rptr;
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
#else
	return( 56 );
#endif
}

WORD    translate_procedure_exit( pptr )
TCPRCPTR        pptr;
{
	WORD            status;
	WORD            rtype;
	TCTYPPTR        tptr;
	WORD            ptype;
	BPTR            rptr;
	BPTR            RtlConvertToType( BPTR, WORD );

	if (((rtype = pptr->options & _RETURN_PROC) )
	&&  ((tptr  = pptr->result) != (TCTYPPTR) 0 )) {
		if (( is_left_brace() ) 
		&&  (( rptr = TypedExpression((ptype = (((rtype >> 8) & 7) - 1)))) != (BPTR) 0)
		&&  ( is_right_brace() ))
			return( translate_function_exit( rptr, tptr ) );
		else    return( syntax_error(184)  );
		}
	else    {
		if ( is_left_brace() )
			return( syntax_error(185) );
		else    return( generate_exit() );
		}
}

WORD    translate_leave()
{
	TCPRCPTR        pptr;
	trace("translate_leave()\n");
	if ( is_inline_function() )
		return( translate_inline_exit() );
	else if ((pptr = Context->PRC) == (TCPRCPTR) 0)
		return( translate_segment_return() );
	else    return( translate_procedure_exit( pptr ) );
}

WORD    translate_exit()
{
	TCPRCPTR        pptr;
	WORD            status=0;
	trace("translate_exit()\n");
	if ( is_inline_function() )
		return( translate_inline_exit() );
	else if ((pptr = Context->PRC) == (TCPRCPTR) 0)
		return( syntax_error(183) );
	else if ((status = verify_destruction_abort()) != 0)
		return( status );
	else    return( translate_procedure_exit( pptr ) );
}

#endif  /* _BEFORE_19031998 */
	/* ---------------- */

WORD    translate_select()
{
	WORD    status;
	BPTR    lptr=(BPTR) 0;
	trace("translate_select()\n");
	if ((status = enter_iteration( _ITERATION_SELECT,(TCVARPTR) 0  )) != 0)
		return( status );
	else if ((lptr = EvaluateExpression()) != (BPTR) 0) {
		generate_iteration();
		return(generate_select(lptr));
		}
	else    return( syntax_error(23245) );
}

WORD    translate_case()
{
	BPTR            rptr=(BPTR) 0;
	WORD            status;
	WORD            operator;
	WORD            mode=1;
	WORD            cases=0;
	trace("\ntranslate_case()\n");
	if ( iteration_type() == _ITERATION_SELECT ) {
		while (mode) {
			trace("case_expression\n");
			if ((rptr = EvaluateExpression()) == (RESULTPTR) 0)
				return( syntax_error(23246) );
			mode = is_comma();
			if (!( cases ))
				generate_case( rptr, !mode );
			else    generate_or_case( rptr, !mode );
			cases++;
			}
		return(0);
		}
	return( syntax_error(23247) );
}
WORD    translate_default()
{
	WORD    status;
	if (((status = iteration_type())  == _ITERATION_SELECT )
	&&  ((status = break_prior_to_case())             == 0 )
	&&  ((status = dcl_iteration_label())             != 0 ))
		return( generate_default() );
	else    return( syntax_error(23248) );
}

WORD    translate_endsel()
{
	if ( iteration_type() != _ITERATION_SELECT )
		return( syntax_error(23249) );
	leave_iteration();
	return( generate_endsel() );
}

WORD    translate_then()
{
	WORD    status;
	if ( iteration_type() != _ITERATION_EVENT )
		return( syntax_error(23250) );
	else if ((status = generate_event_false()) != 0)
		return( status );
	else if ( dcl_abandon_label() == 0 )
		return( syntax_error(23251) );
	else if ((status = generate_event_type( 1 )) != 0)
		return( status );
	else if ((status = enter_event_then()) != 0 )
		return( status );
	else    return( 0 );
}

WORD    translate_event_do()
{
	WORD    status;
	if ((status = generate_event_false()) != 0)
		return( status );
	else if ( dcl_abandon_label() == 0 )
		return( syntax_error(23252) );
	else if ((status = generate_event_type( 2 )) != 0)
		return( status );
	else if ((status = enter_event_do()) != 0 )
		return( status );
	else    return( 0 );
}

WORD    translate_do()
{
	WORD    status=0;
	if ( awaiting_event_do() )
		return( translate_event_do() );
	else if ((status = enter_iteration( _ITERATION_DO,(TCVARPTR) 0  )) != 0)
		return( status );
	else    return( generate_do() );
}

WORD    translate_soft_event()
{
	WORD    type;
	WORD    status;
	BPTR    condition;
	if ((status = enter_iteration( _ITERATION_EVENT )) != 0)
		return( status );
	else if ((status = generate_event()) != 0)
		return( status );
	else if ((status = goto_operation_label()) != 0)
		return( status );
	else if ((status = dcl_iteration_label()) == 0)
		return( syntax_error(23253) );
	else if ((condition = conditional_expression(1)) == (BPTR) 0)
		return( syntax_error(23254) );
	else    return( 0 );
}

WORD    translate_end_code()
{
	WORD    n;

	if ( get_token() ) {
		switch  ((n = is_dcl_keyword())) {
			case _DCL_PROC  :       
				return( generate_proc_end() );
			case _DCL_USER  :
				strcpy(TokenBuffer,"END_USER");
				return( translate_clf() );
			default         :
				if  ( is_control_keyword() == _CTRL_SEG )
					return( generate_segm_end() );
				else    return( syntax_error(23255) );
			}
		}
	return( syntax_error(23256) );
}

WORD    terminate_soft_event()
{
	WORD    type;
	if ( is_period() ) 
		return( translate_end_code() );
	else    {
		if (( iteration_type() == _ITERATION_EVENT )
		&&  ( get_token()  )
		&&  ((type = is_control_keyword()) == _CTRL_EVENT )) {
			leave_iteration();
			return(0);
			}
		else    return( syntax_error(23257) );
		}
}


WORD    translate_event(mode)
WORD    mode;
{
	WORD    type;
	WORD    label;

	if ( mode == MOINS_UN )
		return( translate_soft_event() );
	else    {
		if  ( get_token() ) {
			switch (((type = is_control_keyword()))) {
				case _CTRL_GOTO         : mode = 0; break;
				case _CTRL_GOSUB        : mode = 1; break;
				case _CTRL_CALL         : 
				default                 : return( syntax_error(23258) );
				}
			if (( get_token() )
			&&  ((label = use_explicite_label( TokenBuffer,2)) != 0)
			&&  ( generate_extern_event( mode,0 ) == 0))
				return( generate_label( label ) );

			}
		}
	return( syntax_error(23258) );  
}

WORD    translate_on_error( mode )
WORD    mode;
{
	WORD            type;
	RESULTPTR       rptr;
	BYTE            label[64];
	if  ( get_token() ) {
		switch (((type = is_control_keyword()))) {
			case _CTRL_GOTO         :       
				if ( get_token() ) {
					strcpy( label,TokenBuffer );
					if (( is_comma() )
					&&  ((rptr = evaluate_expression(0)) != (RESULTPTR) 0))
						return( explicite_on_error( rptr->contents, mode, label ) );
					}
				break;

			case _CTRL_ABORT        : 
				return( generate_error_abort() );
			}
		}
	return( syntax_error(200) );    

}

WORD    translate_error()
{
	WORD            braces;
	BPTR            rptr;
	braces = is_left_brace();
	if ((rptr = IntegerExpression()) == (BPTR) 0)
		return( syntax_error(23260) );
	if ((braces)
	&&  (!(is_right_brace())))
		return( unmatched_braces() );
	else    return( generate_rtl_error(rptr) );
}

WORD    translate_timer( mode )
WORD    mode;
{
	WORD            type;
	BPTR            rptr;
	if  (((rptr = IntegerExpression()) != (BPTR) 0) 
	&&   ( get_token() )) {
		switch (((type = is_control_keyword()))) {
			case _CTRL_GOTO         : type = 1; break;
			case _CTRL_GOSUB        : type = 2; break;
			default                 : return( syntax_error(23261) );        
			}
		if (( get_token() )
		&&  ( generate_on_timer( rptr, type ) == 0 ))
			return( generate_label( use_explicite_label( TokenBuffer, 0 ) ) );
		}
	return( syntax_error(23262) );  
}

/*
 *
 *      ON <expression> GOTO <label_less>, <label_zero>, <label_more>
 *
 *      Note : In BAL/ABAL Compatible mode all labels are mandatory !
 *
 */

WORD    translate_on_expression( braces )
WORD    braces;
{
	BPTR            rptr;
	BPTR            xptr=(BPTR) "\0";
	BPTR            zptr;
	WORD            status;
	WORD            label;
	TCVARPTR        vptr;
	trace("translate_on()\n");

	if ( braces ) {
		if ((rptr = EvaluateExpression())   == (BPTR) 0)
			return( syntax_error(23263) );
		else if (!( is_right_brace() ))
			return( unmatched_braces() );
		}
	else if ((vptr = is_variable(1)) == (BPTR) 0)
		return( syntax_error(23264) );
	else if ((rptr = variable_rvalue( vptr )) == (BPTR) 0)
		return( syntax_error(23265) );

	if  (((zptr = IntegerResult( 0 ))     != (BPTR) 0)
	&&  ( is_mnemonic("GOTO") ) ) {
		if ((xptr = EvaluateComparison(_CMP_LS,(BPTR) "\0",rptr,zptr,MOINS_UN,label)) != (BPTR) 0 ) {
			if ((status = generate_if( xptr )) != 0)
				return( status );
			else if ((status = translate_goto()) != 0)
				return( status );
			}
		if (( is_comma() )) {
			if ((xptr = EvaluateComparison(_CMP_EQ,(BPTR) "\0",rptr,zptr,MOINS_UN,label)) != (BPTR) 0 ) {
				if ((status = generate_else_if( xptr )) != 0)
					return( status );
				else if ((status = translate_goto()) != 0) 
					return( status );
				}
			if ( is_comma() ) {
				if ((status = generate_else()) != 0)
					return( status );
				else if ((status = translate_goto() ) != 0)
					return( status );
				else    return( generate_endif() );
				}
			}
		}
	return( syntax_error(23266) );
}

WORD    translate_of()
{
	BPTR            rptr;
	BPTR            zptr;
	BPTR            xptr;
	WORD            status;
	WORD            type;
	WORD            nombre=1;

	trace("translate_of()\n");

	if (((rptr = EvaluateExpression())   != (BPTR) 0)
	&&  ( get_token() )) {

		switch ((type = is_control_keyword())) {
			case _CTRL_GOTO  : type = 0; break;
			case _CTRL_GOSUB : type = 1; break;
			default          : return( syntax_error(23267) );
			}

		do      {
			if (((zptr = IntegerResult( nombre )) == (BPTR) 0)
			||  ((xptr = EvaluateComparison(_CMP_EQ,(BPTR) "\0",rptr,zptr,MOINS_UN,0)) == (BPTR) 0 ))
				return( allocation_failure() );
			
			if ( nombre == 1 )
				status = generate_if( xptr );
			else    status = generate_else_if( xptr );
			if ( status != 0 )
				return( status );
			if ( type )
				status = translate_gosub();
			else    status = translate_goto();
			if ( status != 0 )
				return( status );
			nombre++;
			}
		while ( is_comma() );

		return(generate_endif());
		}
	return( syntax_error(23268) );
}

WORD    translate_on(level)
WORD    level;
{
	WORD    type;
	if ( is_left_brace() )
		return( translate_on_expression( VRAI ) );
	else if  ( get_token() ) {
		switch (((type = is_control_keyword()))) {
			case _CTRL_EXTERN       : 
			case _CTRL_LOCAL        : return( translate_on(type)            );
			case _CTRL_EVENT        : return( translate_event(level)        );
			case _CTRL_TIMER        : return( translate_timer(level)        );
			case _CTRL_ERROR        : return( translate_on_error(level)     );
			case MOINS_UN           : return( translate_on_expression(FAUX) );
			}
		}
	return( syntax_error(23269) );  
}

WORD    translate_data()
{
	WORD    status;
	start_data_control();
	do      {
		if (get_token()) {
			if ((status = add_data_item( TokenBuffer )) != 0)
				return( status );
			}
		else    return( syntax_error(23270) ); 
		Context->DataCount++;
		}
	while ( is_comma() );
	return( 0 );
}

WORD    translate_read_data()
{
	TCVARPTR        vptr;
	WORD            status;
	if (!( is_colon() ))
		return( syntax_error(23271) );
	do      {
		if (!( get_token() ))
			return( syntax_error(23272) );
		else if ((vptr = is_variable(1)) == (TCVARPTR) 0)
			return( syntax_error(23273) );
		else if ((status = generate_read_data( vptr )) != 0)
			return( status );
		}
	while ( is_comma() );
	return( 0 );
}

WORD    translate_resume()
{
	BPTR    label=(BPTR) 0;
	WORD    mode;
	if ( is_ampersand() ) {
		unget_byte();
		if (!( get_token() ))
			return( syntax_error(23274) );
		label = (BPTR) TokenBuffer;
		mode = VRAI;
		}
	else    mode = FAUX;
	return( generate_resume( mode, label ) );
}

WORD    translate_control_keyword()
{
	WORD    type;
	switch (((type = is_control_keyword()))) {
		case _CTRL_IF           : return(translate_if());
		case _CTRL_ELSE         : return(translate_else());
		case _CTRL_ENDIF        : return(translate_endif());
		case _CTRL_WHILE        : return(translate_while());
		case _CTRL_WEND         : return(translate_wend());
		case _CTRL_REPEAT       : return(translate_repeat());
		case _CTRL_UNTIL        : return(translate_until());    
		case _CTRL_FOR          : return(translate_for());
		case _CTRL_NEXT         : return(translate_next());
		case _CTRL_SELECT       : return(translate_select());
		case _CTRL_CASE         : return(translate_case());
		case _CTRL_DEFAULT      : return(translate_default());
		case _CTRL_ENDSEL       : return(translate_endsel());
		case _CTRL_THEN         : return( translate_then() );
		case _CTRL_OFF          :
		case _CTRL_TO           :       
		case _CTRL_STEP         : return( syntax_error(23275) );
		case _CTRL_DO           : return(translate_do());
		case _CTRL_LOOP         : return(translate_loop());
		case _CTRL_BREAK        : return(translate_break());
		case _CTRL_GOSUB        : return( translate_gosub() );
		case _CTRL_RETURN       : return( generate_return() );
		case _CTRL_GOTO         : return( translate_goto() );
		case _CTRL_CALL         : return( translate_call() );
		case _CTRL_EXIT         : return( translate_exit() );
		case _CTRL_LDGO         : return( translate_ldgo_ret_seg(type) );
		case _CTRL_SEG          : return( syntax_error(23276) );
		case _CTRL_RET          : return( translate_ldgo_ret_seg(type) );
		case _CTRL_STOP         : return( generate_stop() );
		case _CTRL_DATA         : return( translate_data() );
		case _CTRL_ON           : return( translate_on( MOINS_UN ) );
		case _CTRL_OF           : return( translate_of() );
		case _CTRL_EVENT        : return( MOINS_UN ); /* See CLF7 */
		case _CTRL_RESUME       : return( translate_resume() );
		case _CTRL_ERROR        : return( translate_error() );
		case _CTRL_TIMER        :
			if ((get_token())
			&&  ((type = is_control_keyword()) == _CTRL_OFF))
				return( generate_on_timer((RESULTPTR) 0, 0 ));
			else    return( syntax_error(23277) );

		case _CTRL_EXTERN       :       
		case MOINS_UN           : return( MOINS_UN );
		default                 : return( syntax_error(23278) );
		}
	return( 0 );
}

#ifdef  _BEFORE_19031998

WORD    translate_level_two()
{
	WORD    type;
	switch (((type = is_level2_keyword()))) {
		case _KW2_ENDPROC: return( translate_endproc());
		case _KW2_ENDLOC : return( translate_endloc() );
		case _KW2_ESEG   : return( translate_eseg()   );
		case MOINS_UN    : return( MOINS_UN );
		}
	return( 0 );
}

WORD    translate_level_one()
{
	WORD    type;
	switch (((type = is_level1_keyword() ))) {
		case _KW1_CONST     :
		case _KW1_DCL       :
		case _KW1_PTR       :
		case _KW1_ARG       : return( translate_declaration(type) );    
		case _KW1_FIELD     : return( translate_field()    );
		case _KW1_EXTERN    : return( translate_extern()   );
		case _KW1_FORWARD   : return( translate_forward()  );
		case _KW1_END       : return( terminate_soft_event() );
		case _KW1_PUBLIC    :
		case _KW1_PRIVATE   : Context->Visibility = type;
				      return(0);
		case MOINS_UN       : return( MOINS_UN );
		default             : return( syntax_error(23279)       );
		}
	return( 0 );
}
#else
WORD    translate_enter()
{
	return( not_yet_available() );
}

WORD    translate_level_two()
{
	WORD    type;
	switch (((type = is_level2_keyword()))) {
		case _KW2_ENDPROC: return( translate_endproc());
		case _KW2_ENDLOC : return( translate_endloc() );
		case _KW2_ESEG   : return( translate_eseg()   );
		case _KW2_ENTER  : return( translate_enter()  );
		case _KW2_LEAVE  : return( translate_leave()  );
		case MOINS_UN    : return( MOINS_UN );
		}
	return( 0 );
}

WORD    level_one_extension()
{
	WORD    type;
	if ((type = translate_instance()) != MOINS_UN)
		return( type );
	else if ((type = is_nural_keyword()) != MOINS_UN)
		return( translate_nural_keyword( type ) );
	else    return( MOINS_UN );
}

WORD    translate_level_one()
{
	WORD    type;
	switch (((type = is_level1_keyword() ))) {
		case _KW1_LOCAL     : return( translate_local() );
		case _KW1_CONST     :
		case _KW1_DCL       :
		case _KW1_PTR       :
		case _KW1_ARG       : return( translate_declaration(type) );    
		case _KW1_CLASS     : return( translate_class(type,0));
		case _KW1_UNION     : return( translate_union(0,type));
		case _KW1_STRUCT    : return( translate_struct(type) );
		case _KW1_ENDCLASS  : return( translate_endclass(type));
		case _KW1_ENDUNION  : 
		case _KW1_ENDSTRUCT : return( translate_endstruct(type) );
		case _KW1_FIELD     : return( translate_field()    );
		case _KW1_EXTERN    : return( translate_extern()   );
		case _KW1_FORWARD   : return( translate_forward()  );
		case _KW1_END       : return( terminate_soft_event() );
		case _KW1_PUBLIC    : return( translate_public()   );
		case _KW1_PRIVATE   : return( translate_private()  );
		case _KW1_LIBRARY   : return( translate_class_dll());
		case MOINS_UN       : return( level_one_extension() );
		default             : return( syntax_error(220)     );
		}
	return( 0 );
}
#endif  /* _BEFORE_19031998 */
	/* ---------------- */

WORD    reset_affectation( status )
WORD    status;
{
	Context->TargetVariable = (TCVARPTR) 0;
	Context->ConvertType    = 2;
	return( status );
}

WORD    is_memory_operation(nptr)
BPTR    nptr;
{
	if ( is_mnemonic("MOVE") )
		return( 0 );
	else    if ( is_mnemonic("SWAP") )
		return( 1 );
	else    if ( is_mnemonic("INSERT") )
		return( 2 );
	else    if ( is_mnemonic("INCLUD") )
		return( 3 );
	else    if ( is_mnemonic("CRYPT") )
		return( 4 );
	else    return( MOINS_UN );
}

WORD    translate_memory_operation( mode )
WORD    mode;
{
	trace("translate_memory_operation()\n");
	switch ( mode ) {
		case 0 : return( translate_rtlclf_move() );
		case 1 : return( translate_rtlclf_swap() );
		case 2 : return( translate_rtlclf_insert() );
		case 3 : return( translate_rtlclf_includ() );
		case 4 : return( translate_rtlclf_crypt() );
		}
	return( not_yet_available() );
}

WORD    variable_affectation( vptr )
TCVARPTR        vptr;
{
	BPTR            bptr;
	WORD            status;
	WORD            mode;

	trace("variable_affectation()\n");

	if ( is_equals() ) {

		Context->TargetVariable = vptr;
		Context->ConvertType = (vptr->type->type & 3);

		switch ((Context->ConvertType = (vptr->type->type & 3))) {
			case    0 : 
				if ((mode = is_memory_operation(TokenBuffer)) != MOINS_UN)
					return( translate_memory_operation( mode ) );
				else if ((bptr = IntegerExpression()) == (BPTR) 0)
					return( syntax_error(23280) );
				else    return( generate_int8_affectation( vptr, bptr, 1 ));
			case    1 :
				if ((mode = is_memory_operation(TokenBuffer)) != MOINS_UN)
					return( translate_memory_operation( mode ) );
				else if ((bptr = IntegerExpression()) == (BPTR) 0)
					return( syntax_error(23281) );
				else    return( generate_int16_affectation( vptr, bptr, 1 ));
			case    2 :
				if ((mode = is_memory_operation(TokenBuffer)) != MOINS_UN)
					return( translate_memory_operation( mode ) );
				else if ((bptr = BcdExpression()) == (BPTR) 0)
					return( syntax_error(23282) );
				else    return( generate_bcd_affectation( vptr, bptr, 1 ));
			case    3 :
				if ((mode = is_memory_operation(TokenBuffer)) != MOINS_UN)
					return( translate_memory_operation( mode ) );
				else if ((bptr = StringExpression()) == (BPTR) 0)
					return( syntax_error(23283) );
				else if ( Context->TargetVariable != (TCVARPTR) 0)
					return( generate_string_affectation( vptr, bptr, 1 ));
				else    return( 0 );
			}

	
		}
	else
#ifdef  _THIS_IS_NOT_EXCLUDED
		{
		/* ------------------------------------------------- */
		/* Heiroglyphic C operations += -= *= /= %= != -- ++ */
		/* ------------------------------------------------- */
		if (( OtrOption.Enhanced & _ENHANCED_AFFECTATION )
		&&  ((status = affectation_expression(vptr)) == 0))
			return((status = reset_affectation( 0 )) );
		else    return((status = reset_affectation( syntax_error(223) )) );
		}
#else
		return( syntax_error(223) );
#endif
}

WORD    translate_affectation()
{
	TCVARPTR        vptr;
	trace("translate_affectation()\n");

	if ((vptr = is_variable(1)) == (TCVARPTR) 0)
		return( MOINS_UN );

	return( variable_affectation( vptr ) );

}

WORD    translate_terminal_member( vptr )
TCVARPTR        vptr;
{
	return( variable_affectation(collect_dimensions( vptr ) ));
}

WORD    translate_statement()
{
	WORD    status;
	if (((status = translate_parameter_statement()) == MOINS_UN )
	&&  ((status = translate_local_statement())     == MOINS_UN )
	&&  ((status = translate_member_statement())    == MOINS_UN )
	&&  ((status = translate_object_statement())    == MOINS_UN )
	&&  ((status = translate_affectation())         == MOINS_UN )
	&&  ((status = translate_callproc())            == MOINS_UN )
	&&  ((status = translate_dll_function())        == MOINS_UN ))
		return( MOINS_UN );
	else    return( status   );
}

WORD    segmental_translation()
{
	WORD    type;
	if ( remove_white_space() ) {
		if (get_token()) {
			if (( translate_control_keyword() == MOINS_UN )
			&&  ( translate_statement()       == MOINS_UN )
			&&  ( translate_clf()             == MOINS_UN )
			&&  ( translate_iof()             == MOINS_UN )
			&&  ( translate_ngf()             == MOINS_UN )
			&&  ( translate_level_one()       == MOINS_UN )
			&&  ( translate_level_two()       == MOINS_UN ))
				return( syntax_error(224) );
			else    return( 0 );
			}
		else    return( verify_end_of_line() );
		}
	else    return(0);
		
}

WORD    enter_segmental_translation()
{
	push_operation_pointer();
	set_operation_pointer(segmental_translation);
	set_local_scope();
	return(0);
}

WORD    translate_segment()
{
	WORD    identity=MOINS_UN;
	WORD    options=0;
	WORD    c;
	WORD    status=0;
	BYTE    nomseg[65];
	BPTR    nptr=(BPTR) 0;

	trace("translate_segment()\n");

	if ((c = is_numeric()) != 0)
		identity = integer_expression();
	else if (!( get_token() ))
		return( syntax_error(23286) );
	else    strcpy( (nptr = (BPTR) nomseg), TokenBuffer );

	if ( is_comma() ) {
		if (remove_white_space()) {
			c = get_byte();
			if (( c == 'r') || (c == 'R'))
				options = 1;
			else    return( syntax_error(23287));
			}
		else    return( syntax_error(23288));
		}
	if ((status = add_segment( identity, options, nptr, VRAI )) != 0 )
		return( status );
	else    return( enter_segmental_translation() );

}

WORD    no_operation( )
{
	return( 48 );
}

WORD    translate_end()
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
	return( status );
}


WORD    enter_procedure_translation()
{
	push_operation_pointer();
	set_operation_pointer(segmental_translation);
	return(0);
}

WORD    translate_procedure()
{
	WORD    status;
	if ((status = translate_proc()) == 0)
		return( enter_procedure_translation() );
	else    return( status );
}

#ifdef   _BEFORE_19031998 

WORD    translator_code_or_data()
{
	WORD    type=0;
	WORD    c;

	if (get_token()) {
		switch (((type = is_level1_keyword()))) {
			case _KW1_CONST     :
			case _KW1_DCL       :
			case _KW1_PTR       :
			case _KW1_ARG       : return( translate_declaration(type) );    
			case _KW1_FIELD     : return( translate_field()    );
			case _KW1_EXTERN    : return( translate_extern()   );
			case _KW1_FORWARD   : return( translate_forward()  );
			case _KW1_PROC      : return( translate_procedure());
			case _KW1_SEGMENT   : return( translate_segment()  );
			case _KW1_END       : return( translate_end()      );
			case _KW1_PUBLIC    :
			case _KW1_PRIVATE   : Context->Visibility = type;
					      return(0);
			default             : return( syntax_error(23289)       );
			}
		}
	return(0);
}

#else   /* _BEFORE_19031998 */
	/* ---------------- */

WORD    translator_code_or_data()
{
	WORD    type=0;
	WORD    status;

	if ( remove_white_space() ) {
/*              set_correspondance();           */
		if (get_token()) {
			switch (((type = is_level1_keyword()))) {
				case _KW1_LOCAL     : return( translate_local() );
				case _KW1_CONST     :
				case _KW1_DCL       :
				case _KW1_PTR       :
				case _KW1_ARG       : return( translate_declaration(type) );    
				case _KW1_CLASS     : return( translate_class(type,0)     );
				case _KW1_UNION     : return( translate_union(0,type)     );
				case _KW1_STRUCT    : return( translate_struct(type)      );
				case _KW1_ENDCLASS  : return( translate_endclass(type)    );
				case _KW1_ENDUNION  : 
				case _KW1_ENDSTRUCT : return( translate_endstruct(type)   );
				case _KW1_FIELD     : return( translate_field()    );
				case _KW1_EXTERN    : return( translate_extern()   );
				case _KW1_FORWARD   : return( translate_forward()  );
				case _KW1_PROC      : return( translate_procedure());
				case _KW1_SEGMENT   : return( translate_segment()  );
				case _KW1_END       : return( translate_end()      );
				case _KW1_PUBLIC    : return( translate_public()   );
				case _KW1_PRIVATE   : return( translate_private()  );
				case _KW1_LIBRARY   : return( translate_class_dll());
				case MOINS_UN       : 
					if ((status = level_one_extension()) != MOINS_UN)
						return( status );
					else    return( translate_object_message() );
				default             : return( syntax_error(228)       );
				}
			}
		else    return( verify_end_of_line() );
		}
	else    return(0);
}

#endif  /* _BEFORE_19031998 */
	/* ---------------- */

#ifdef _BEFORE_19031998

WORD    start_program_or_module( type )
WORD    type;
{
	WORD    noclr;
	WORD    status=0;

	Context->options = type;
	if ( get_token() ) {
		tcode_program_identity();
		if (( is_comma() )
		&&  ( remove_white_space() )
		&&  ( is_mnemonic( "NOCLR" )))
			noclr = 0;
		else    noclr = 2;
		Context->options |= _CONTEXT_NOCLR;
		if (( status = start_tcode()) != 0)
			return( status );
		else    {
			generate_header( Context->identity, Context->options, MOINS_UN );
			return(enter_global_translation());
			}
		}
	else    return(syntax_error(23290));
}

WORD    translator_startup()
{
	WORD    type=0;
	if (get_token()) {
		switch (((type = is_level1_keyword()))) {
			case _KW1_PROGRAM :
				return(start_program_or_module( _CONTEXT_PROGRAM ));
			case _KW1_MODULE  : 
				return(start_program_or_module( _CONTEXT_MODULE  ));
			}
		}
	return(syntax_error(23291));
}

#else

static  WORD    translate_module_instance()
{
	WORD    status;

	if (!( get_token() ))
		return( syntax_error( 1001 ) );

	else if ((status = instance_module( TokenBuffer )) == 0)
		return( await_target_end() );
	else    return( status );
}


static  WORD    translate_program_instance()
{
	WORD    status;

	if (!( get_token() ))
		return( syntax_error( 1001 ) );

	else if ((status = instance_program( TokenBuffer )) == 0)
		return( await_target_end() );
	else    return( status );
}

static  WORD    translate_program_object( type )
WORD    type;
{
	WORD    status;

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

static  WORD    translate_module_object( type )
WORD    type;
{
	WORD    status;

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

static  WORD    translate_noclr()
{
	if ( is_comma() ) {
		if (( remove_white_space() )
		&&  ( is_mnemonic( "NOCLR" )))
			return(0);
		else    return( syntax_error( 981 ) );
		}
	else    {
		Context->options |= _CONTEXT_NOCLR;
		return( 0 );
		}
}

static  WORD    translate_program( type )
WORD    type;
{
	WORD    status=0;

	if ( get_token() ) {
		tcode_program_identity();
		if ((status = translate_noclr()) != 0)
			return( status );
		else if (( status = start_tcode()) != 0)
			return( status );
		else    {
			generate_header( Context->identity, Context->options, MOINS_UN );
			if ((status = enter_global_translation()) != 0)
				return( status );
			else    return( flush_world_members() );
			}
		}
	else    return(syntax_error(229));

}

static  WORD    translate_module( type )
WORD    type;
{
	WORD    status=0;

	if ( get_token() ) {
		tcode_program_identity();
		if ((status = translate_noclr()) != 0)
			return( status );
		else if (( status = start_tcode()) != 0)
			return( status );
		else    {
			generate_header( Context->identity, Context->options, MOINS_UN );
			return( enter_global_translation() );
			}
		}
	else    return(syntax_error(229));

}

WORD    start_program_or_module( type )
WORD    type;
{
	WORD    noclr;
	WORD    status=0;

	Context->options = type;

	if ( is_quote() ) {
		unget_byte();
		if ( type == _KW1_PROGRAM )
			return( translate_program(type) );
		else    return( translate_module(type)  );
		}
	else if ( type == _KW1_PROGRAM )
		return( translate_program_object(type) );
	else    return( translate_module_object(type)  );
}

WORD    translator_startup()
{
	WORD    type=0;
	if (get_uppercase_token()) {
		switch (((type = is_level1_keyword()))) {
			case _KW1_PROGRAM :
				return(start_program_or_module( _CONTEXT_PROGRAM ));
			case _KW1_MODULE  : 
				return(start_program_or_module( _CONTEXT_MODULE  ));
			case _KW1_LIBRARY :
				return(instance_library());
#ifdef  DO_STDC
			case _KW1_STDC :
				return(instance_stdc());
#endif
			}
		}
	return(syntax_error(230));
}
#endif

/*      -------------------------------------------     */
/*      PUBLIC REGION   :       INTERFACE FUNCTIONS     */
/*      -------------------------------------------     */

WORD    terminate_translation( abandon )
WORD    abandon;
{
	if (( Context != (TCFDTPTR) 0 )
	&&  ( Context->Started        )
	&&  (!( abandon              )))
		error_message( "End instruction expected" );


	terminate_tcode_context();

	return( abandon );
}

WORD    line_translation( line_buffer )
BPTR    line_buffer;
{
	WORD    status=0;
	if (initialise_line_parser( line_buffer )) {

		if ((status = is_directive()) != MOINS_UN )
			return( translate_directive(status) );
		else if ((status = is_active_region()) != FAUX) {

			signal_new_line(VRAI);
			do      {
				if ((status = (*Context->operation)()) != 0)
						return(status);
				}
			while ( soft_newline() );
			}
		}
	return(status);
}

RESULTPTR       intrinsic_functions()
{
	return( (RESULTPTR) 0 );
}


VOID    echo_source_line( lptr )
BPTR    lptr;
{
	sysprintf("ATC: ");
	while (( *lptr ) && ( *lptr != 0x001A ))
		sysprintf("%c",*(lptr++));
	sysprintf("\n");
	return;
}

/*
 *      Called during MAIN after initialisation of Options to
 *      detect and honour any options specified by the relevant
 *      environment variable.
 *
 */

#ifndef UNIX
BPTR    getenv(BPTR);
#endif
#define ENV_FIELD ';'

VOID    default_language_options()
{
	BPTR    eptr;
	BPTR    fptr;
	WORD    term;
#ifndef PROLOGUE
	if ((eptr = getenv("ATCDEF")) != (BPTR) 0) {
		while ( strlen(eptr) != 0 ) {
			fptr = eptr;
			while ( *fptr ) {
				if ( *fptr == ENV_FIELD )
					break;
				else    fptr++;
				}
			if ((term = *fptr) == ENV_FIELD)
				*fptr = 0;
			(void) analyse_translator_options(eptr);                        
			if ( term == ENV_FIELD )
				*(fptr++) = term;
			eptr = fptr;
			}               
		}
	if ((eptr = getenv("ATCHUGE")) != (BPTR) 0)
		set_rtl_huge( eptr );
	return;
#endif
}

#endif  /* _TRANSLAT_C */


