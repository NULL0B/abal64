/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRJAVA.C				*/
/*		Version :	2.1c					*/
/*		Date	:	14/06/1996				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRANSLAT_C
#define	_TRANSLAT_C

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include "stdtypes.h"		/* Standard translator type definitions	*/
#include "translat.h"		/* Translation types and definitions	*/
#include "trparser.h"		/* Stream parser definitions		*/
#include "trjvsynt.h"		/* Java Syntaxical Definitions		*/
#include "trerrors.h"
#include "trsymbol.h"
#include "troption.h"
#include "trexpres.h"
#include "trlabels.h"
#include "triter.h"
#include "trclf.h"
#include "trproc.h"
#include "trldf.h"
#include "trmethod.h"
#include "trclass.h"
#include "trmember.h"
#include "trjava.h"
#include "trdebug.h"

BPTR		allocate_for_string( BPTR );
TCVARPTR	input_object( VOID );


/*
 *	These function prototypes are necessary for the push/pop
 *	operation pointer phases
 *
 */

static 	WORD	java_class_translation( VOID );
static 	WORD	java_function_translation( VOID );
	WORD	translator_startup( VOID );


/*
 *	JAVA PARSER Operational Context
 *	-------------------------------
 *
 */

static	JAVAPTR		JavaClassMember=(JAVAPTR) 0;
static	TCTYPPTR	JavaType=(TCTYPPTR) 0;
static	WORD		JavaBlockNesting=0;
static	TCMBMETHPTR	JavaClassMethod=(TCMBMETHPTR) 0;
static	TCVARPTR	JavaFirstParameter=(TCVARPTR) 0;
static	TCVARPTR	JavaLastParameter=(TCVARPTR) 0;


/*
 *	These dummy functions are necessary in order to avoid
 *	the link time errors due to there non-existance.
 */

WORD reverse_compare(WORD opcode) { return( 0 ); }
WORD collect_normal_operator(VOID) { return( 0 ); }
WORD translate_variable(WORD type,WORD nature) { return( 0 ); }
WORD translate_declaration(WORD type) { return( 0 ); }
WORD translate_filler(VOID) { return( 0 ); }
WORD translate_field(VOID) { return( 0 ); }
WORD translate_endproc(VOID) { return( 0 ); }
WORD translate_eseg(VOID) { return( 0 ); }
WORD translate_endloc(VOID) { return( 0 ); }
WORD translate_segment_return(VOID) { return( 0 ); }
WORD translate_ldgo_ret_seg(WORD type) { return( 0 ); }
WORD translate_gosub(VOID) { return( 0 ); }
WORD translate_goto(VOID) { return( 0 ); }
WORD translate_endif(VOID) { return( 0 ); }
WORD conditional_expression(WORD repeat_until) { return( 0 ); }
WORD translate_if(VOID) { return( 0 ); }
WORD translate_else(VOID) { return( 0 ); }
WORD translate_while(VOID) { return( 0 ); }
WORD translate_wend(VOID) { return( 0 ); }
WORD translate_break(VOID) { return( 0 ); }
WORD translate_loop(VOID) { return( 0 ); }
WORD translate_repeat(VOID) { return( 0 ); }
WORD translate_until(VOID) { return( 0 ); }
TCVARPTR for_initialisation(VOID) { return((TCVARPTR) 0 ); }
WORD generate_to(RESULTPTR lptr,RESULTPTR rptr,RESULTPTR steptr,WORD corps) { return( 0 ); }
RESULTPTR translate_to(VOID) { return((RESULTPTR)  0 ); }
RESULTPTR generate_step(TCVARPTR vptr,RESULTPTR rptr) { return( (RESULTPTR) 0 ); }
RESULTPTR translate_step(VOID) { return((RESULTPTR) 0 ); }
WORD translate_for(VOID) { return( 0 ); }
WORD translate_next(VOID) { return( 0 ); }
WORD translate_callproc(VOID) { return( 0 ); }
WORD translate_dll_function(VOID) { return( 0 ); }
WORD translate_indirect_call(VOID) { return( 0 ); }
WORD translate_call(VOID) { return( 0 ); }
WORD showme(BPTR msg) { return( 0 ); }
WORD translate_function_exit(RESULTPTR rptr,TCTYPPTR tptr) { return( 0 ); }
WORD overlay_method_parameter(TCVARPTR object,WORD field) { return( 0 ); }
WORD translate_procedure_exit(TCPRCPTR pptr) { return( 0 ); }
WORD translate_exit(VOID) { return( 0 ); }
WORD translate_leave(VOID) { return( 0 ); }
RESULTPTR select_expression(VOID) { return( (RESULTPTR) 0 ); }
WORD translate_select(VOID) { return( 0 ); }
WORD translate_case(VOID) { return( 0 ); }
WORD translate_default(VOID) { return( 0 ); }
WORD translate_endsel(VOID) { return( 0 ); }
WORD translate_then(VOID) { return( 0 ); }
WORD translate_event_do(VOID) { return( 0 ); }
WORD translate_do(VOID) { return( 0 ); }
WORD translate_soft_event(VOID) { return( 0 ); }
WORD translate_end_code(VOID) { return( 0 ); }
WORD terminate_soft_event(VOID) { return( 0 ); }
WORD translate_event_call(VOID) { return( 0 ); }
WORD translate_event(WORD mode) { return( 0 ); }
WORD translate_on_error(WORD mode) { return( 0 ); }
WORD translate_error(WORD mode) { return( 0 ); }
WORD translate_timer(WORD mode) { return( 0 ); }
WORD translate_timer_off(VOID) { return( 0 ); }
WORD translate_on_expression(WORD braces) { return( 0 ); }
WORD translate_of(VOID) { return( 0 ); }
WORD translate_on(WORD level) { return( 0 ); }
WORD translate_data(VOID) { return( 0 ); }
WORD translate_read_data(VOID) { return( 0 ); }
WORD translate_resume(VOID) { return( 0 ); }
WORD translate_control_keyword(VOID) { return( 0 ); }
WORD translate_enter(VOID) { return( 0 ); }
WORD translate_level_two(VOID) { return( 0 ); }
WORD level_one_extension(VOID) { return( 0 ); }
WORD translate_level_one(VOID) { return( 0 ); }
WORD translate_segment(VOID) { return( 0 ); }
WORD no_operation(VOID) { return( 0 ); }
WORD translate_end(VOID) { return( 0 ); }
WORD translate_procedure(VOID) { return( 0 ); }
WORD enter_global_translation(VOID) { return( 0 ); }
WORD leave_global_translation(VOID) { return( 0 ); }


/*
 *	The following functions define the JAVA language syntax
 *
 */

static	WORD	reset_java_oneshot()
{
	reset_oneshot_options();
	translate_strict();
	return;
}

static	WORD	java_semi_colon()
{
	if ( is_semi_colon() ) {
		reset_java_oneshot();
		return( 0 );
		}
	else	return( syntax_error( _JTR_EXPECTED_SEMICOLON ) );
}

static	WORD	java_package()
{
	WORD	parts=0;
	while (1) {
		if (get_token() != 0) {
			if ( is_period() )
				parts++;
			else	return( java_semi_colon() );
			}
		else	return( syntax_error( _JTR_EXPECTED_TOKEN ) );
		}
}

static	WORD	java_import()
{
	WORD	parts=0;
	while (1) {
		if (( is_star() )
		||  (get_token() != 0)) {
			if ( is_period() )
				parts++;
			else if ( is_comma() )
				parts = 0;
			else	return( java_semi_colon() );
			}
		else	return( syntax_error( _JTR_EXPECTED_TOKEN ) );
		}
}

static	WORD	add_java_method( jptr )
JAVAPTR		jptr;
{
	TCSTRUCTPTR	class=(TCSTRUCTPTR) 0;
	TCMEMBERPTR	xptr=(TCMEMBERPTR) 0;
	TCMEMBERPTR	mptr=(TCMEMBERPTR) 0;
	TCMBMETHPTR	method=(TCMBMETHPTR) 0;
	WORD		status=0;
	if ((class = World->CurrentStructure) != (TCSTRUCTPTR) 0) {
		xptr = locate_member(class,jptr->name);
		if ((mptr = allocate_structure_member( jptr->name  )) == (TCMEMBERPTR) 0)
			return( allocation_failure() );
		else if ((method = allocate_structure_method()) == (TCMBMETHPTR) 0)
			return( allocation_failure() );

		if ( jptr->type != MOINS_UN ) {
			if ((method->type 
				= allocate_for_type( 	jptr->type,
							jptr->size,
							jptr->first,
							jptr->second,
							(VPTR) 0 ))
				== (TCTYPPTR) 0)
				return( allocation_failure() );
			}
		else	method->type = (TCTYPPTR) 0;

		/* detect a constructor */

		if ( compare_tokens( class->name, jptr->name ) )
			method->special = _CLASS_CONSTRUCTOR;

		method->options |= _METHOD_STRICT;
		method->nature  = _CLASS_FUNCTION;
		mptr->special = method;
		JavaClassMethod = method;
		method->parameters = JavaFirstParameter;

		if ((status = build_pseudo_object( method, World->CurrentStructure )) != 0)
			return( status );

		if ( xptr != (TCMEMBERPTR) 0)
			return( replace_member( class, xptr, mptr ) );
		else	return( add_member( class, mptr ) );

		}
	
	return(0);
}

WORD	add_to_structure( BPTR, WORD, WORD, WORD, WORD, WORD, WORD );

static	WORD	add_java_member( jptr )
JAVAPTR		jptr;
{
	WORD	status;
	if ( jptr != (JAVAPTR) 0 ) {
		status = add_to_structure(	jptr->name,
						jptr->type,
						jptr->size,
						jptr->first,
						jptr->second,
						jptr->nature,
						0 );
		liberate( jptr );
		}
	return( status );
}

JAVAPTR	allocate_java_member( ctype, token )
WORD	ctype;
BPTR	token;
{
	JAVAPTR	jptr=(JAVAPTR) 0;
	if ((jptr = allocate( sizeof ( struct java_class_member ) )) != (JAVAPTR) 0) {
		if ((jptr->name = allocate_for_string( token )) != (BPTR) 0) {
			jptr->first  = 1;
			jptr->second = 1;
			jptr->type   = MOINS_UN;
			jptr->nature = 7;
			switch (ctype) {
				case	1 :
					jptr->type = _TYPE_INT8;
					jptr->size = 1;
					break;
				case	2 :
					jptr->type = _TYPE_INT16;
					jptr->size = 2;
					break;
				case	3 :
					jptr->type = _TYPE_NUMERIC;
					jptr->size = 4;
					break;
				case	4 :
					jptr->type = _TYPE_NUMERIC;
					jptr->size = 8;
					break;
				case	5 :
					jptr->type = _TYPE_NUMERIC;
					jptr->size = 12;
					break;
				}
			}
		else	{
			liberate( jptr );
			jptr = (JAVAPTR) 0;
			}
		}
	return( jptr );
}

static	WORD	java_data_initialise()
{
	WORD	c;
	while (1) {
		if ( is_semi_colon() )
			break;
		else if (!(c = get_byte()))
			return( 0 );
		}
 	reset_java_oneshot();
	pop_operation_pointer();
	return(0);
}

static	WORD	java_initialise_data()
{
	push_operation_pointer();
	set_operation_pointer(java_data_initialise);
	return(0);
}

static	WORD	java_data_dimensions(jptr)
JAVAPTR	jptr;
{
	WORD	c;
	while (!( is_close_bracket() ))
		c = get_byte();
	return( 0 );
}

static	WORD	java_function_translation()
{
	WORD	status=0;
	WORD	c;
	while (1) {
		if ( is_close_block() ) {
			if ( JavaBlockNesting ) {
				put_method_byte('}');
				JavaBlockNesting--;
				}
			else	{
				put_method_byte('\n');
				terminate_method_text();
				reset_java_oneshot();
				return( status );
				}
			}
		else if ( is_open_block() ) {
			put_method_byte('{');
			JavaBlockNesting++;
			}
		else if ( get_token() != 0 ) {
			put_method_string( TokenBuffer );
			continue;
			}
		else if (!(c = get_byte())) {
			put_method_byte('\n');
			return(0);
			}
		else	put_method_byte(c);
		}
}


static	WORD	java_define_function()
{
	WORD	status=0;
	if ((status = add_java_method( JavaClassMember )) != 0)
		return( status );
	else	{
		if  ((status = activate_method_target( JavaClassMethod )) != 0)
			return( status );
		else	{
			push_operation_pointer();
			set_operation_pointer(java_function_translation);
			JavaBlockNesting = 0;
			return(0);
			}
		}
}

static	WORD	java_translate_parameter()
{
	TCVARPTR	vptr=(TCVARPTR) 0;
	WORD		status=0;
	if ( get_token() ) {
		pop_operation_pointer();
		if ((vptr = allocate_for_variable()) == (TCVARPTR) 0)
			return( allocation_failure() );
		else if ((vptr->name = allocate_for_token( TokenBuffer )) == (BPTR) 0)
			return( allocation_failure() );
		else	{
			vptr->type = JavaType;
			JavaType = (TCTYPPTR) 0;
			if ( JavaLastParameter == (TCVARPTR) 0 )
				JavaFirstParameter = vptr;
			else	JavaLastParameter->next = vptr;
			JavaLastParameter = vptr;
			if (( is_open_bracket() )
			&&  ((status = java_data_dimensions( (JAVAPTR) 0)) != 0))
				return( status );
			}
		}
	return( 0 );
}

static	WORD	java_endclass()
{
	TCSTRUCTPTR	sptr;
	if ((sptr = World->CurrentStructure) == (TCSTRUCTPTR) 0)
		return( syntax_error(734) );
	else	return( close_structure_definition( sptr ) );
}

static	WORD	java_translate_type()
{
	WORD		type=MOINS_UN;
	WORD		status=0;
	TCSTRUCTPTR	sptr=(TCSTRUCTPTR) 0;

	if (!(get_token() ))
		return(0);
		
	switch (((type = is_level2_keyword()))) {
		case _KW2_SHORT     :
		case _KW2_UNSIGNED  :
		case _KW2_SIGNED    : return( 0 );
		case _KW2_CHAR	    :
			if ((JavaType = allocate_for_type( _TYPE_INT8, 1, 1, 1, (VPTR) 0)) ==(TCTYPPTR) 0)
				return( allocation_failure() );
			else	break;
		case _KW2_BOOLEAN   :
		case _KW2_INT       :
			if ((JavaType = allocate_for_type( _TYPE_INT16, 2, 1, 1, (VPTR) 0)) == (TCTYPPTR) 0)
				return( allocation_failure() );
			else	break;
		case _KW2_LONG	    :
			if ((JavaType = allocate_for_type( _TYPE_NUMERIC, 4, 1, 1, (VPTR) 0)) == (TCTYPPTR) 0)
				return( allocation_failure() );
			else	break;
		case _KW2_DOUBLE    :
			if ((JavaType = allocate_for_type( _TYPE_NUMERIC, 8, 1, 1, (VPTR) 0)) == (TCTYPPTR) 0)
				return( allocation_failure() );
			else	break;
		case _KW2_FLOAT     :
			if ((JavaType = allocate_for_type( _TYPE_NUMERIC, 12, 1, 1, (VPTR) 0)) == (TCTYPPTR) 0)
				return( allocation_failure() );
			else	break;
		case MOINS_UN	    :
			if ((sptr = known_structure( TokenBuffer )) == (TCSTRUCTPTR) 0) {
				if ((status = open_structure_definition( TokenBuffer, 18 )) != 0)
					return( status );
				else	sptr = World->CurrentStructure;
				if ((status = java_endclass()) != 0)
					return( status );
				}
			if ((JavaType = allocate_for_type( 0x0013, (sptr->access & _MEMBER_OVERLAY ? 10 : sptr->size), 1, 1, sptr )) == (TCTYPPTR) 0)
				return( allocation_failure() );
			else	break;
		default		    :
			return( syntax_error( _JTR_EXPECTED_TYPE ) );
		}
	pop_operation_pointer();
	return(0);
}

static	WORD	java_parameter()
{
	push_operation_pointer();
	set_operation_pointer( java_translate_parameter );
	push_operation_pointer();
	set_operation_pointer( java_translate_type );
	JavaType = (TCTYPPTR) 0;
	return(0);
}

static	WORD	java_function_signature()
{	
	WORD	c;
	WORD	status;

	if ( is_right_brace() ) {
		pop_operation_pointer();
		return(0);
		}
	if ( is_comma() ) {
		if ( JavaFirstParameter == (TCVARPTR) 0 )
			return( syntax_error( _JTR_SYNTAX_ERROR ) );
		else	return( java_parameter() );
		}
	else	{
		if ( JavaFirstParameter != (TCVARPTR) 0 )
			return( syntax_error( _JTR_EXPECTED_COMMA ) );
		else	return( java_parameter() );
		}
}


static	WORD	java_throws()
{
	do	{
		if (!( get_token() ))
			return( syntax_error( _JTR_EXPECTED_TOKEN ) );

		/* TODO : verify exception class */

		}
	while ( is_comma() );
	return(0);
}


static	WORD	java_function_nature()
{
	WORD	status=0;
	if ( remove_white_space() ) {
		pop_operation_pointer();
		while (1) {
			if ( is_open_block() )
				return( java_define_function() );
			else if ( is_open_bracket() ) {
				if ((status = java_data_dimensions( JavaClassMember )) != 0)
					return(status);
				else if ( is_equals() )
					return( java_initialise_data( JavaClassMember ) );
				else	continue;
				}
			else if ( is_semi_colon() ) {
				reset_java_oneshot();
				return(  add_java_method( JavaClassMember ) );
				}
			else if (!(get_token() ))
				return( syntax_error( _JTR_EXPECTED_TOKEN ) );
			else  if ( is_level3_keyword() != _KW3_THROWS )
				return( syntax_error( _JTR_SYNTAX_ERROR ) );
			else if ((status = java_throws()) != 0)
				return( status );
			else	continue;
			}
		}
	else	return(0);
}

static	WORD	java_declare_function(jptr)
JAVAPTR		jptr;
{
	JavaClassMember = jptr;
	push_operation_pointer();
	set_operation_pointer(java_function_nature);
	JavaFirstParameter = (TCVARPTR) 0;
	JavaLastParameter = (TCVARPTR) 0;
	push_operation_pointer();
	set_operation_pointer(java_function_signature);
	return(0);
}



static WORD java_define_member( nature )
WORD nature;
{
	WORD	pointer_flag=0;
	WORD	status=0;
	JAVAPTR	jptr=(JAVAPTR) 0;

	while (1) {
		
		while ( is_star() )
			pointer_flag++;
		if (!( get_token() ))
			return( syntax_error( _JTR_EXPECTED_TOKEN ) );
		if ((jptr = allocate_java_member( nature, TokenBuffer )) == (JAVAPTR) 0)
			return( allocation_failure() );
		if ( is_open_bracket() )
			if ((status = java_data_dimensions( jptr )) != 0)
				return( status );
		if ( is_equals() )
			return( java_initialise_data( jptr ) );
		else if ( is_left_brace() )
			return( java_declare_function( jptr ) );
		else if ((status = add_java_member( jptr )) != 0)
			return( status );
		else if (!( is_comma() ))
			return( java_semi_colon() );
		}
}

static WORD java_void()		{ return( java_define_member(0) ); }
static WORD java_short()	{ return( 0 ); }
static WORD java_unsigned()	{ return( 0 ); }
static WORD java_signed()	{ return( 0 ); }

static WORD java_char()		{ return( java_define_member(1) ); }
static WORD java_int()		{ return( java_define_member(2) ); }
static WORD java_long()		{ return( java_define_member(3) ); }
static WORD java_double()	{ return( java_define_member(4) ); }
static WORD java_float()	{ return( java_define_member(5) ); }


static WORD	java_define_class()
{
	push_operation_pointer();
	set_operation_pointer(java_class_translation);
	return(0);
}

static WORD	java_declare_class()
{
	return(0);
}

static	WORD	java_extends()
{ 
	if (get_token() != 0)
		return(0); 
	else	return( syntax_error( _JTR_EXPECTED_TOKEN ) );
}

static	WORD	java_implements()
{ 
	if (get_token() != 0)
		return(0); 
	else	return( syntax_error( _JTR_EXPECTED_TOKEN ) );
}

static	WORD	java_class() 
{ 
	WORD	status=0;
	WORD	type=0;
	if (get_token() != 0) {
		if ((status = open_structure_definition( TokenBuffer, 18 )) != 0)
			return( status );

		while ( get_token() != 0 ) {
			switch (((type = is_level1_keyword()))) {
				case _KW1_EXTENDS :
					if ((status = java_extends()) != 0)
						break;
					else	continue;
				case _KW1_IMPLEMENTS :
					if ((status = java_implements()) != 0)
						break;
					else	continue;
				default	:
					status = syntax_error( _JTR_CLASS_QUALIFIER );
					break;
				}
			}
		if ( status ) {
			(void) java_endclass();
			return( status );
			}
		else if ( is_open_block() )
			return( java_define_class() );
		else if ((status = java_endclass()) != 0)
			return( status );
		else if ( is_semi_colon() )
			return( java_declare_class() );
		else	return( syntax_error( _JTR_EXPECTED_SEMICOLON ) );
		}
	else	return( syntax_error( _JTR_EXPECTED_TOKEN ) );
}

static	WORD	java_final() { return(0); }
static	WORD	java_native() { return(0); }
static	WORD	java_abstract() { return(0); }
static	WORD	java_static() { return(translate_common()); }
static	WORD	java_public() { return(translate_public()); }
static	WORD	java_private() { return(translate_private()); }
static	WORD	java_protected() { return(0); }
static	WORD	java_synchronized() { return(0); }

static	WORD	java_ensure_class( nptr )
BPTR	nptr;
{
	TCSTRUCTPTR	sptr;
	WORD		status=1;
	if ((sptr = known_structure( nptr )) != (TCSTRUCTPTR) 0)
		return( java_define_member( 0 ) );
	else if ((status = open_structure_definition( nptr, 18 )) != 0)
		return( status );
	else if ((status = java_endclass()) != 0)
		return( status );
	else	return( java_define_member( 0 ) );
}

static	WORD	java_implicite_function()
{
	JAVAPTR	jptr=(JAVAPTR) 0;

	if ((jptr = allocate_java_member( 0, TokenBuffer )) == (JAVAPTR) 0)
		return( allocation_failure() );
	else	return( java_declare_function( jptr ) );

}


static WORD	java_class_translation()
{
	WORD	type=0;
	if (get_token()) {
		switch (((type = is_level1_keyword()))) {
			case _KW1_NATIVE :
				return(java_native());
			case _KW1_FINAL  :
				return(java_final());
			case _KW1_ABSTRACT :
				return(java_abstract());
			case _KW1_STATIC  :
				return(java_static());
			case _KW1_PRIVATE  : 
				return(java_private());
			case _KW1_PUBLIC  : 
				return(java_public());
			case _KW1_PROTECTED :
				return(java_protected());
			case _KW1_SYNCHRONIZED :
				return(java_synchronized());
			case _KW1_CLASS     :
				return(java_class());
			case	MOINS_UN    :
				switch (((type = is_level2_keyword()))) {
					case _KW2_VOID	    :
						return( java_void() );
					case _KW2_SHORT     :
						return( java_short() );
					case _KW2_UNSIGNED  :
						return( java_unsigned() );
					case _KW2_SIGNED    :
						return( java_signed() );
					case _KW2_CHAR	    :
						return( java_char() );
					case _KW2_INT       :
					case _KW2_BOOLEAN   :
						return( java_int() );
					case _KW2_LONG	    :
						return( java_long() );
					case _KW2_DOUBLE    :
						return( java_double() );
					case _KW2_FLOAT     :
						return( java_float() );
					case MOINS_UN	    :
						if ( is_left_brace() )
							return( java_implicite_function() );
						else 	return( java_ensure_class(TokenBuffer) );
					}
			}
		}
	else if ( is_open_block() ) {
		push_operation_pointer();
		set_operation_pointer(java_function_translation);
		JavaBlockNesting = 0;
		return(java_function_translation());
		}
	else if ( is_close_block() ) {
		pop_operation_pointer();
		return( java_endclass() );
		}
	return(syntax_error(_JTR_SYNTAX_ERROR));
}

static	WORD	java_instance()
{
	TCSTRUCTPTR	sptr;
	WORD		status=0;
	BYTE		ObjectName[64];
	if ((sptr = known_structure( TokenBuffer )) == (TCSTRUCTPTR) 0)
		return( 0 );
	if (!( get_token() ))
		return( syntax_error( _JTR_EXPECTED_TOKEN ) );
	strcpy( ObjectName, TokenBuffer );
	if (( Context == (TCFDTPTR) 0 )
	||  (!( Context->Started        ))) {
		Context->options = _CONTEXT_PROGRAM;
		tcode_program_identity();
		if (( status = start_tcode()) != 0)
			return( status );
		generate_header( Context->identity, Context->options, MOINS_UN );
		if ((status = flush_world_members()) != 0)
			return( status );
		}
	if ((status = declare_instance( sptr, ObjectName, 66, 0, 0,(BPTR) 0, 0 )) != 0)
		return( status );
	else	return( java_semi_colon() );
}

static	WORD	java_end()
{
	WORD status=0;

	if (Context->CurrentSegment != (TCSEGPTR) 0)
		status += terminate_segment( Context->CurrentSegment->identity, (BPTR) 0, 0 );
	else if (Context->PRC != (TCPRCPTR) 0)
		status += terminate_procedure();

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
	return( status );
}

static	WORD	java_object_message()
{
	WORD	status=0;
	if ((status = translate_object_message()) == 0)
		return( java_semi_colon() );
	else	return(status);
}

static	WORD	java_program_instance()
{
	WORD	status;

	if (!( get_token() ))
		return( syntax_error( _JTR_EXPECTED_TOKEN ) );
	else if ((status = instance_program( TokenBuffer )) == 0)
		return( await_target_end() );
	else	return( status );
}

static	WORD	java_program_object()
{
	WORD	status;

	if (( status = start_tcode()) != 0)
		return( status );

	generate_header( Context->identity, Context->options, MOINS_UN );

	if ((status = enter_global_translation()) != 0 )
		return( status );

	push_operation_pointer();
	set_operation_pointer(java_program_instance);

	return( 0 );
}

static	WORD	java_module()
{
	WORD	status=0;

	if (!( get_token() ))
		return( syntax_error( _JTR_EXPECTED_TOKEN ) );
	else if ((status = java_instance()) != 0)
		return( status );
	else	return( java_end() );
}

static	WORD	java_overlay()
{
	WORD	status=0;

	if (!( get_token() ))
		return( syntax_error( _JTR_EXPECTED_TOKEN ) );
	else if ((status = java_instance()) != 0)
		return( status );
	else	return( java_end() );
}

static	WORD	java_library()
{

	if (!( get_token() ))
		return( syntax_error( _JTR_EXPECTED_TOKEN ) );
	else	return( 0 );
}

static	WORD	java_translation()
{
	WORD	type=0;
	WORD	status;
	if (get_token()) {
		switch (((type = is_level1_keyword()))) {
			case _KW1_PACKAGE :
				return(java_package());
			case _KW1_IMPORT  :
				return(java_import());
			case _KW1_FINAL   :
				return(java_final());
			case _KW1_NATIVE :
				return(java_native());
			case _KW1_STATIC  :
				return(java_static());
			case _KW1_PRIVATE  : 
				return(java_private());
			case _KW1_PUBLIC  : 
				return(java_public());
			case _KW1_PROTECTED :
				return(java_protected());
			case _KW1_CLASS     :
				return(java_class());
			case _KW1_INTERFACE :
				return(java_class());
			case _KW1_PROGRAM   :
				return(java_program_object());
			case _KW1_OVERLAY   :
				return(java_overlay());
			case _KW1_MODULE    :
				return(java_module());
			case _KW1_LIBRARY   :
				return(java_library());

			case	MOINS_UN    :
				if ((status = java_object_message()) != MOINS_UN)
					return( status );
				else if ((status = java_instance()) != MOINS_UN)
					return( status );
			}
		}
	else if ( is_close_block() )
		return( 0 );
	return(syntax_error(_JTR_SYNTAX_ERROR));
}


/*	-------------------------------------------	*/
/*	PUBLIC REGION	:	INTERFACE FUNCTIONS	*/
/*	-------------------------------------------	*/
WORD		reset_affectation( status )
WORD		status;
{
	Context->TargetVariable = (TCVARPTR) 0;
	Context->ConvertType    = 2;
	return( status );
}

WORD	variable_affectation( vptr )
TCVARPTR	vptr;
{
	RESULTPTR	rptr;
	WORD		status;

	if ( OtrOption.ListFlag & 1 )
		set_echo_prefix();

	Context->TargetVariable = vptr;
	Context->ConvertType = (vptr->type->type & 3);

	if ( is_equals() ) {
		if  ((rptr = evaluate_expression(0)) != (RESULTPTR) 0) {
			if ( Context->TargetVariable != (TCVARPTR) 0)
				return((status = reset_affectation( generate_affectation( vptr, rptr,VRAI ) )) );
			else	return((status = reset_affectation(  0 )));
			}
		else	return((status = reset_affectation( syntax_error(222) )) );
		}
	else	{
		/* ------------------------------------------------- */
		/* Heiroglyphic C operations += -= *= /= %= != -- ++ */
		/* ------------------------------------------------- */
		if ((status = affectation_expression(vptr)) == 0)
			return((status = reset_affectation( 0 )) );
		else	return((status = reset_affectation( syntax_error(223) )) );
		}
}

WORD	translate_terminal_member( vptr )
TCVARPTR	vptr;
{
	return( variable_affectation(collect_dimensions( vptr ) ));
}

static	WORD	translate_affectation()
{
	TCVARPTR	vptr;
	int		status;
	trace("translate_affectation()\n");

	while (1) {
		if ((vptr = is_variable(1)) == (TCVARPTR) 0)
			return( MOINS_UN );
		else if ((status = variable_affectation( vptr )) != 0)
			return( status );
		else if (!( is_comma() ))
			return(0);
		}
}

static	WORD	java_statement()
{
	int	status;
	if (((status = translate_parameter_statement()) == MOINS_UN )
	&&  ((status = translate_local_statement())     == MOINS_UN )
	&&  ((status = translate_member_statement())    == MOINS_UN )
	&&  ((status = translate_object_statement())    == MOINS_UN )
	&&  ((status = translate_affectation())  	== MOINS_UN ))
		return( MOINS_UN );
	else	return( status );
}

WORD	translate_statement()
{
	WORD	status;

	if ((status = java_statement()) == MOINS_UN)
		return( status );
	else if ( status )
		return( status   );
	else	return( java_semi_colon() );
}

WORD	java_conditional()
{
	return(0);
}

static 	WORD	translate_java_iof()
{
	RESULTPTR	device=(RESULTPTR) 0;
	RESULTPTR	format=(RESULTPTR) 0;
	WORD		status;
	switch (((status = is_iof_keyword()))) {
	case	0		:	/* _JAVA_PRINTF */
	case	1		:	/* _JAVA_SPRINTF */
		if (!( is_left_brace() ))
			return( syntax_error( _JTR_EXPECTED_LEFTBRACE ) );
		else if ((status = start_iof()) != 0)
			return( status );
		if ( status == 1 ) {
			if ((device = evaluate_expression(0)) == (RESULTPTR) 0)
				return( syntax_error( _JTR_SYNTAX_ERROR ) );
			else if (!( is_comma() ))
				return( syntax_error( _JTR_EXPECTED_COMMA ) );
			}
		else 	{
			if ((device = integer_result(1)) == (RESULTPTR) 0)
				return( syntax_error( _JTR_SYNTAX_ERROR ) );
			}

		if ((format = evaluate_expression(0)) == (RESULTPTR) 0)
			return( syntax_error( _JTR_SYNTAX_ERROR ) );
		else if ( is_comma() ) {
			if ((status = iof_instructions(0)) != 0 )
				return( syntax_error( _JTR_SYNTAX_ERROR ) );
			}
		else	{
			if ((status = store_iof_prn( format )) != 0)
				return( syntax_error( _JTR_SYNTAX_ERROR ) );
			}
		if ((status = flush_print( device, VRAI )) != 0)
			return( status );
		else if (!( is_right_brace() ))
			return( syntax_error( _JTR_EXPECTED_RIGHTBRACE ) );
		else	return( java_semi_colon() );
		
	case	MOINS_UN	:
			return( status );
	
	}
}

static	WORD	translate_java_if()
{
	int	status;
	if (!( is_left_brace() ))
		return( syntax_error( _JTR_EXPECTED_LEFTBRACE ) );
	else if ((status = java_conditional()) != 0)
		return( status );
	else if (!( is_right_brace() ))
		return( syntax_error( _JTR_EXPECTED_RIGHTBRACE ) );
	else	return(0);
}

static	WORD	translate_java_else()
{
	return(0);
}

static	WORD	translate_java_for()
{
	int	status;
	if (!( is_left_brace() ))
		return( syntax_error( _JTR_EXPECTED_LEFTBRACE ) );

	/* affectation expressions */
	/* ----------------------- */
	else if (!( get_token() )) {
		if (!( is_semi_colon() )) return( syntax_error( _JTR_EXPECTED_TOKEN ) );
		}
	else if ((status = translate_affectation()) != 0)
		return(status);
	else if (!( is_semi_colon() ))
		return( syntax_error( _JTR_EXPECTED_SEMICOLON ) );

	if (!( is_semi_colon() )) {
		if ((status = java_conditional()) != 0)
			return( status );
		else if (!( is_semi_colon() ))
			return( syntax_error( _JTR_EXPECTED_SEMICOLON ) );
		}

	if ((status = java_statement()) != 0)
		return( status );

	else if (!( is_right_brace() ))
		return( syntax_error( _JTR_EXPECTED_RIGHTBRACE ) );

	else	return(0);
}

static	WORD	translate_java_while()
{
	WORD	status;
	if (!( is_left_brace() ))
		return( syntax_error( _JTR_EXPECTED_LEFTBRACE ) );
	else if ((status = java_conditional()) != 0)
		return( status );
	else if (!( is_right_brace() ))
		return( syntax_error( _JTR_EXPECTED_RIGHTBRACE ) );
	else	return(0);
}

static	WORD	translate_java_do()
{
	return(0);
}

static	WORD	translate_java_switch()
{
	int	status;
	if (!( is_left_brace() ))
		return( syntax_error( _JTR_EXPECTED_LEFTBRACE ) );
	else if ((status = java_conditional()) != 0)
		return( status );
	else if (!( is_right_brace() ))
		return( syntax_error( _JTR_EXPECTED_RIGHTBRACE ) );

	else	return(0);
}

static	WORD	translate_java_case()
{
	int	status;

	if ((status = java_conditional()) != 0)
		return( status );

	else if (!( is_colon() ))
		return( syntax_error( _JTR_EXPECTED_COLON ) );

	else	return(0);
}

static	WORD	translate_java_default()
{
	if (!( is_colon() ))
		return( syntax_error( _JTR_EXPECTED_COLON ) );

	else	return(0);
}

static	WORD	translate_java_break()
{
	return( java_semi_colon() );
}

static	WORD	translate_java_continue()
{
	return( java_semi_colon() );
}

static	WORD	translate_java_return()
{
	return( java_semi_colon() );
}


static 	WORD	translate_level_four()
{
	int	type;
	switch ((type = is_level4_keyword())) {
		case	_KW4_IF		:
			return( translate_java_if() );
		case	_KW4_ELSE	:
			return( translate_java_else() );
		case	_KW4_FOR	:
			return( translate_java_for() );
		case	_KW4_WHILE	:
			return( translate_java_while() );
		case	_KW4_DO		:
			return( translate_java_do() );
		case	_KW4_SWITCH	:
			return( translate_java_switch() );
		case	_KW4_CASE	:
			return( translate_java_case() );
		case	_KW4_DEFAULT	:
			return( translate_java_default() );
		case	_KW4_BREAK	:
			return( translate_java_break() );
		case	_KW4_CONTINUE	:
			return( translate_java_continue() );
		case	_KW4_RETURN	:
			return( translate_java_return() );
		}
	return( type );
}

WORD	segmental_translation()
{
	WORD	type;
	WORD	status=0;
	if ( remove_white_space() ) {
		if ((type = set_correspondance()) != 0)
			return( type );
		else if (get_token()) {
			if (((status = translate_level_four()) == MOINS_UN )
			&&  ((status = translate_statement())  == MOINS_UN )
			&&  ((status = translate_clf())        == MOINS_UN )
			&&  ((status = translate_java_iof())   == MOINS_UN )
			&&  ((status = translate_ngf())        == MOINS_UN )
			&&  ((status = java_translation())     == MOINS_UN ))
				return( syntax_error(224) );
			else	return( status );
			}
		}
	return(0);
		
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

WORD	enter_procedure_translation()
{
	push_operation_pointer();
	set_operation_pointer(segmental_translation);
	return(0);
}

WORD	translator_startup()
{
	(void) inhibit_semi_colon_comment();
	(void) inhibit_apostrophe_comment();
	(void) inhibit_label_status();
	reset_java_oneshot();
	set_operation_pointer(java_translation);
	return( java_translation() );
}


WORD	terminate_translation( abandon )
WORD	abandon;
{
	if (( Context != (TCFDTPTR) 0 )
	&&  ( Context->Started        ))
		abandon += java_end();
	terminate_tcode_context();
	return( abandon );
}

WORD	line_translation( line_buffer )
BPTR	line_buffer;
{
	WORD	status=0;
	if (initialise_line_parser( line_buffer )) {

		if ((status = is_directive()) != MOINS_UN )
			return( translate_directive(status) );
		else if ((status = is_active_region()) != FAUX) {

			signal_new_line(VRAI);

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
				else if ( is_semi_colon() )
					continue;
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
	while (( *lptr ) && ( *lptr != 0x001A ) && ( *lptr != '\n'))
		sysprintf("%c",*(lptr++));
	sysprintf("\n");
	return;
}


/*
 *	Called during MAIN after initialisation of Options to
 *	detect and honour any options specified by the relevant
 *	environment variable.
 *
 */

#ifndef	UNIX
BPTR	getenv(BPTR);
#define	ENV_FIELD ';'
#else
BPTR	getenv(BPTR);
#define	ENV_FIELD ':'
#endif

WORD	start_program_or_module( type )
WORD	type;
{
	return(0);
}

VOID	default_language_options()
{
	BPTR	eptr;
	BPTR	fptr;
	WORD	term;
	OtrOption.UpperCase	= FAUX;
	OtrOption.BlockComment  = FAUX;
	OtrOption.AutoGetLine   = VRAI;
	double_bal_comments();
#ifndef	PROLOGUE
	if ((eptr = getenv(_TRANSLATOR_LANGUAGE_DEFAULT)) != (BPTR) 0) {
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

#endif	/* _ TRANSLAT_C */
	/* ------------ */

