#define DEBUG
/* -------------------------------------------------------------------- */
/*                                                                      */
/*              Project ABAL : Macro pre-processer                      */
/*                                                                      */
/*               Copyright (c) 1990, 1995 Amenesik / Sologic s.a.                 */
/*                                                                      */
/*                                                                      */
/*              File    :       TRCOBOL.C                               */
/*              Version :       2.1c                                    */
/*              Date    :       26/01/1995                              */
/*                                                                      */
/* -------------------------------------------------------------------- */
#ifndef _TRANSLAT_C
#define _TRANSLAT_C
#define _TRCOBOL_C
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
#include "trfctrl.h"
#include "trpctrl.h"
#include "trvctrl.h"
#include "trcobol.h"

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
		default      : return( MOINS_UN );
		}
}

WORD    translate_variable(type,nature)
WORD    type;           /* DCL, PTR, ARG, CONST         */
WORD    nature;         /* DCL, PROC, SEGM, USER, CODE  */
{
	return( syntax_error(1027) );
}

WORD    translate_field()
{
	return( syntax_error(1027) );
}

WORD    translate_do()
{
	WORD    status=0;
	trace("translate_do()\n");
	if ((status = enter_iteration( _ITERATION_DO,(TCVARPTR) 0  )) != 0)
		return( status );
	else    return(0);
}


WORD    translate_error(mode)
WORD    mode;   /* 0 : ERROR,  1 : RAISE THROW */
{
	WORD            braces;
	RESULTPTR       rptr;
	braces = is_left_brace();
	if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0) {
		if (!( mode ))
			return( syntax_error(201) );
		else if ((rptr = integer_result( pragma_throw() )) == (RESULTPTR) 0)
			return( allocation_failure() );
		}
	if ((braces)
	&&  (!(is_right_brace())))
		return( unmatched_braces() );
	else    return( generate_error(rptr) );
}

WORD    translate_loop()
{
	WORD    status=0;
	if ( iteration_type() != _ITERATION_DO )
		return( syntax_error(168) );
	leave_iteration();
	return(status);
}

WORD    collect_normal_operator()
{
	WORD    result=0;
	WORD    inverse=FAUX;

	if ( remove_white_space() ) {

		/* Remove optional IS */
		(void) is_mnemonic( "IS" );

		if ( is_mnemonic( "NOT" ) ) {
			result = _CMP_NE;
			inverse = VRAI;
			}
		else    inverse = FAUX;

		if (( is_equals() )
		||  ( is_mnemonic( "EQUAL" ) ))
			result = _CMP_EQ;
		else if (( is_greater() )
		     ||  ( is_mnemonic( "GREATER" ) ))
			result = _CMP_GR;
		else if (( is_less()    )
		     ||  ( is_mnemonic( "LESS" ) ))
			result = _CMP_GR;
		else    return( result );

		(void) is_mnemonic( "TO" );
		(void) is_mnemonic( "THAN" );

		if ( inverse ) {
			if ( result == _CMP_EQ )
				return( _CMP_NE );
			else if ( result == _CMP_GR )
				return( _CMP_LE );
			else    return( _CMP_GR );
			}
		else    return( result );
		}
	else    return( syntax_error(1027) );
}

VCTRLPTR        allocate_for_vctrl( nptr )
BPTR            nptr;
{
	VCTRLPTR        vptr;
	if ((vptr = (VCTRLPTR) allocate( sizeof( struct cobol_vctrl ) )) != (VCTRLPTR) 0) {
		vptr->name = (BPTR) 0;
		if (( nptr == (BPTR) 0)
		||  ( compare_tokens( nptr, "FILLER" ) )
		||  ( compare_tokens( nptr, "FIL" ) )
		||  ((vptr->name = (BPTR) allocate_for_string( nptr )) != (BPTR) 0 )) {
			vptr->level=MOINS_UN;
			vptr->nature = _KW1_DCL;
			vptr->scope = _LOCAL_SCOPE;
			vptr->size=15;
			vptr->type=3;
			vptr->picsize=0;
			vptr->first=1;
			vptr->second=1;
			vptr->picture=(BPTR) 0;
			vptr->value=(BPTR) 0;
			vptr->redefines = (VCTRLPTR) 0;
			vptr->next = (VCTRLPTR) 0;
			vptr->fichier = (VPTR) 0;
			vptr->record  = (VPTR) 0;
			vptr->previous = (VCTRLPTR) 0;
			if (Cobol->VctrlHeap == (VCTRLPTR) 0)
				Cobol->VctrlHeap = vptr;
			else    {
				Cobol->VctrlLast->next = vptr;
				vptr->previous = Cobol->VctrlLast;
				}
			return((Cobol->VctrlLast = vptr));
			}
		liberate( vptr );
		}
	return( (VCTRLPTR) 0 );
}

WORD            vctrl_rounding( tcvptr )
TCVARPTR        tcvptr;
{
	VCTRLPTR        vptr;
	BPTR    pptr;
	WORD    nombre=0;
	WORD    temp;
	if (tcvptr == (TCVARPTR) 0)
		return( 0 );
	if (((vptr = locate_vctrl( tcvptr->name )) != (VCTRLPTR) 0)
	&&  ((pptr = vptr->picture) != (BPTR) 0)) {
		while ( *pptr )
			if ( *(pptr++) == '.' )
				break;
		while ( *pptr ) {
			switch ( *(pptr++) ) {
				case    'N' :
				case    'Z' :
					if ((*pptr >= '0') && ( *pptr <= '9' )) {
						temp = 0;
						do      {
							temp = ((temp * 10) + ( *(pptr++) - '0'));
							}
						while   ((*pptr >= '0') && ( *pptr <= '9' ));
						nombre += temp;
						}
					else    nombre++;
					continue;
				default     :
					break;
				}
			break;
			}
		}
	return( nombre );

}

VCTRLPTR        locate_vctrl( nptr )
BPTR            nptr;
{
	VCTRLPTR        vptr=(VCTRLPTR) 0;
	if ( nptr != (BPTR) 0 ) {
		if ((vptr = Cobol->VctrlHeap) != (VCTRLPTR) 0) {
			do      {
				if (( vptr->name != (BPTR) 0 )
				&&  ( compare_tokens( nptr, vptr->name ) ))
					break;
				}
			while ((vptr = vptr->next) != (VCTRLPTR) 0);
			}
		}
	return( vptr );
}

VOID    liberate_vctrl()
{
	VCTRLPTR        vptr;
	trace("liberate_vctrl()\n");
	while ((vptr = Cobol->VctrlHeap) != (VCTRLPTR) 0) {
		Cobol->VctrlHeap = vptr->next;
		if ( vptr->name != (BPTR) 0)
			liberate( vptr->name );
		if ( vptr->picture != (BPTR) 0)
			liberate( vptr->picture );
		liberate( vptr );
		}
	return;
}

WORD    translate_endif()
{
	WORD    status=0;
	if ((status = locate_iteration( _ITERATION_IF )) != 0)
		return( status );
	else    leave_iteration();
	return(status);
}
WORD    end_sentance()
{
	WORD    status;
	while ( iteration_type() ) 
		leave_iteration();
	return( 0 );
}

WORD    xverify_period()
{
	WORD    status;
	if ( is_period() )
		return( end_sentance() );
	else    return( 0 );
}

WORD    verify_period()
{
	WORD    status;
	if ( is_period() )
		return( end_sentance() );
	else    return( incorrect_punctuation() );
}


WORD    is_division_keyword()
{
	WORD    i;

	for ( i = 0; i < _DIVISION_KEYWORD_MAX; i++ )
		if ( compare_tokens( TokenBuffer , division_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD    is_statement()
{
	WORD    i;

	for ( i = 0; i < _STATEMENT_MAX; i++ )
		if ( compare_tokens( TokenBuffer , statement_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD    is_declarative()
{
	WORD    i;

	for ( i = 0; i < _DECLARATIVE_MAX; i++ )
		if ( compare_tokens( TokenBuffer , declarative_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD    is_ngf_statement()
{
	WORD    i;

	for ( i = 0; i < _NGF_STATEMENT_MAX; i++ )
		if ( compare_tokens( TokenBuffer , ngf_statement_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD    is_identif_keyword()
{
	WORD    i;

	for ( i = 0; i < _IDENTIF_KEYWORD_MAX; i++ )
		if ( compare_tokens( TokenBuffer , identif_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}
WORD    is_environ_keyword()
{
	WORD    i;

	for ( i = 0; i < _ENVIRON_KEYWORD_MAX; i++ )
		if ( compare_tokens( TokenBuffer , environ_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}
WORD    is_envcfg_keyword()
{
	WORD    i;

	for ( i = 0; i < _ENVCFG_KEYWORD_MAX; i++ )
		if ( compare_tokens( TokenBuffer , envcfg_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}
WORD    is_envio_keyword()
{
	WORD    i;

	for ( i = 0; i < _ENVIO_KEYWORD_MAX; i++ )
		if ( compare_tokens( TokenBuffer , envio_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}
WORD    is_ioctrl_keyword()
{
	WORD    i;

	for ( i = 0; i < _IOCTRL_KEYWORD_MAX; i++ )
		if ( compare_tokens( TokenBuffer , ioctrl_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD    is_fctrl_keyword()
{
	WORD    i;

	for ( i = 0; i < _FCTRL_KEYWORD_MAX; i++ )
		if ( compare_tokens( TokenBuffer , fctrl_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD    is_vctrl_keyword()
{
	WORD    i;

	for ( i = 0; i < _VCTRL_KEYWORD_MAX; i++ )
		if ( compare_tokens( TokenBuffer , vctrl_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD    is_datadiv_keyword()
{
	WORD    i;

	for ( i = 0; i < _DATADIV_KEYWORD_MAX; i++ )
		if ( compare_tokens( TokenBuffer , datadiv_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD    is_procdiv_keyword()
{
	WORD    i;

	for ( i = 0; i < _PROCDIV_KEYWORD_MAX; i++ )
		if ( compare_tokens( TokenBuffer , procdiv_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD    translate_read_data()
{
	return( syntax_error(1027) );
}

RESULTPTR       intrinsic_functions()
{
	if (( compare_tokens( TokenBuffer, "LOW_VALUE" ) )
	||  ( compare_tokens( TokenBuffer, "LOW_VALUES" ) )
	||  ( compare_tokens( TokenBuffer, "ZERO" ) )
	||  ( compare_tokens( TokenBuffer, "ZEROS" ) ))
		return( integer_result(0) );
	if (( compare_tokens( TokenBuffer, "HIGH_VALUE" ) )
	||  ( compare_tokens( TokenBuffer, "HIGH_VALUES" ) ))
		return( integer_result(MOINS_UN) );
	if (( compare_tokens( TokenBuffer, "SPACE" ) )
	||  ( compare_tokens( TokenBuffer, "SPACES" ) ))
		return( clf_space(1) );
	else    return((RESULTPTR) 0);
}

WORD    start_program_or_module( type )
WORD    type;
{
	WORD    noclr=0;
	WORD    status=0;

	trace("start_program()\n");

	Context->options = type;

	tcode_program_identity();

	if (( status = start_tcode()) != 0)
		return( status );
	else    {
		generate_header( Context->identity, Context->options, MOINS_UN );
		set_global_scope();
		return(0);
		}
}

WORD    translate_program_id()
{
	WORD    status;
	trace("translate_program_id()\n");
	if ( get_token() ) {
		if (Cobol->CurrentProgram != (BPTR) 0)
			return( symbol_already_defined(Cobol->CurrentProgram) );
		else if ((Cobol->CurrentProgram = allocate_for_string( TokenBuffer )) == (BPTR) 0)
			return( allocation_failure() );
		(void) is_mnemonic("IS");
		if ( is_mnemonic( "COMMON" ) )
			Cobol->options = 1;
		if ( is_mnemonic("INITIAL") )
			Cobol->options = 2;
		if (( Cobol->Next == (COBOLPTR) 0 )
		&&  ((status = start_program_or_module( _CONTEXT_PROGRAM )) != 0))
			return( status );
		else    return( verify_period() );
		}
	else    return( expected_program() );
}

WORD    translate_comment_entry()
{
	terminate_line_parser();
	return( 0 );
}

WORD    translate_id_div()
{
	WORD    type;
	if ( get_token() ) {
		switch ((type = is_identif_keyword())) {
			case _IDENTIF_PROGRAM_ID        :
				if ( is_period() )
					return( translate_program_id() );
				else    return( incorrect_punctuation() );

			case _IDENTIF_AUTHOR            :
			case _IDENTIF_INSTALLATION      :
			case _IDENTIF_DATE_WRITTEN      :
			case _IDENTIF_DATE_COMPILED     :
			case _IDENTIF_SECURITY          :
				if ( is_period() )
					return( translate_comment_entry() );
				else    return( incorrect_punctuation() );
			case    MOINS_UN                :
				return( enter_division() );
			}
		}
	return( syntax_error(1027) );
}

WORD    enter_file_select()
{
	FCTRLPTR        fptr;

	(void) is_mnemonic("OPTIONAL");

	if ( get_token() ) {
		/* Token Buffer Contains Logical File Name */
		/* --------------------------------------- */
		if ((fptr = allocate_for_fctrl( TokenBuffer )) == (FCTRLPTR) 0)
			return( allocation_failure() );
		push_operation_pointer();
		set_operation_pointer(translate_file_select);
		return(0);
		}
	else    return( syntax_error(1027) );
}

WORD    translate_file_control()
{
	WORD    type;
	if ( get_token()  ) {
		switch ((type = is_fctrl_keyword())) {
			case _FCTRL_SELECT      :
				return( enter_file_select() );
			case MOINS_UN           :
				return( enter_control_section() );
			}
		}
	return( syntax_error(1027) );
}

WORD    translate_io_control()
{
	WORD    type;
	if ( get_token()  ) {
		switch ((type = is_ioctrl_keyword())) {
			case _IOCTRL_RERUN      :
				return( translate_comment_entry() );
			case _IOCTRL_SAME       :
				return( translate_comment_entry() );
			case MOINS_UN           :
				return( enter_control_section() );
			}
		}
	return( syntax_error(1027) );
}

WORD    enter_file_control()
{
	push_operation_pointer();
	set_operation_pointer(translate_file_control);
	return(0);
}

WORD    enter_io_control()
{
	push_operation_pointer();
	set_operation_pointer(translate_io_control);
	return(0);
}

WORD    enter_control_section()
{
	WORD    type;
	switch ((type = is_envio_keyword())) {
		case _ENVIO_FILE_CONTROL        :
			if ( is_period() )
				return( enter_file_control() );
			else    return( incorrect_punctuation() );

		case _ENVIO_I_O_CONTROL         :
			if ( is_period() )
				return( enter_io_control() );
			else    return( incorrect_punctuation() );

		case MOINS_UN                   :
			return( enter_environ_section() );
		}
	return( syntax_error(1027) );
}

WORD    translate_env_io()
{
	if ( get_token() )
		return( enter_control_section() );
	else    return( syntax_error(1027) );
}

WORD    translate_special_value( nptr )
{
	(void)  is_mnemonic("IS");
	if (!( get_token() ))
		return( syntax_error(1027) );
	return( 0 );
}

WORD    translate_env_config();

WORD    translate_console_is()
{
	(void)  is_mnemonic("IS");
	if ( is_mnemonic("CRT") ) {
		Cobol->version |= _COBOL_ANS85SS;
		return( 0 );
		}
	else    return( expected_keyword("CRT") );
}

WORD    translate_decimal_point()
{
	(void)  is_mnemonic("IS");
	if ( is_mnemonic("COMMA") ) {
		Cobol->comma = ',';
		return( 0 );
		}
	else    return( expected_keyword("COMMA") );
}

WORD    translate_special_names()
{
	trace("translate_special_names()\n");
	if ( is_period() ) {
		pop_operation_pointer();
		return(0);
		}
	else if ( is_mnemonic("CURRENCY" ) )
		return( translate_special_value("CURRENCY") );
	else if ( is_mnemonic("ALPHABET" ) )
		return( translate_special_value("ALPHABET") );
	else if ( is_mnemonic("DECIMAL-POINT" ) )
		return( translate_decimal_point() );
	else if ( is_mnemonic("CONSOLE" ) )
		return( translate_console_is() );
	else if (!( Cobol->version & _COBOL_ANS85SS ))
		return( syntax_error(1027) );
	else if ( is_mnemonic("CURSER" ) )
		return( translate_special_value("CURSER") );
	else if ( is_mnemonic("CRT" ) ) {
		if ( is_mnemonic( "STATUS") )
			return( translate_special_value("CRT") );
		else    return( expected_keyword("STATUS") );
		}
	else    return( syntax_error(1027) );
}


WORD    translate_env_config()
{
	WORD    type;
	trace("translate_env_config()\n");
	if ( get_token() ) {
		switch ((type = is_envcfg_keyword())) {
			case    _ENVCFG_SOURCE_COMPUTER :
			case    _ENVCFG_OBJECT_COMPUTER :
				if ( is_period() )
					return( translate_comment_entry() );
				else    return( incorrect_punctuation() );
			case    _ENVCFG_SPECIAL_NAMES   :
				if ( is_period() ) {
					push_operation_pointer();
					set_operation_pointer(translate_special_names);
					return( 0 );
					}
				else    return( incorrect_punctuation() );
			default :
				return( enter_environ_section() );
			}
		}
	else    return( syntax_error(1027) );
}

WORD    picture_count( c )
WORD    c;
{
	WORD    x;
	WORD    n=1;
	while ((x = uppercase_byte()) == c)
		n++;
	if ( x == '(' ) {
		n--;
		n += collect_integer();
		if ( get_byte() != ')' )
			return( unmatched_braces() );
		}
	else    unget_byte();
	return( n );
}

WORD    translate_picture( vptr )
VCTRLPTR        vptr;
{
	BYTE    picture[64];
	WORD    picdex=0;
	WORD    length=0;
	WORD    c=0;
	WORD    xc=0;
	WORD    rlen=0;
	BPTR    picptr=(BPTR) 0;

	trace("translate_picture()\n");

	if (!( remove_white_space() ))
		return( 0 );

	/* Collect Real Componant */
	while ( 1 ) {
		switch ((xc = (c = uppercase_byte()))) {
			case    'Z'     :
				xc = 'N';
				rlen = picture_count( c );
				sprintf((BPTR) &picture[picdex],"%c%u",xc,rlen);
				picdex = strlen( picture );
				length += rlen;
				continue;
			case    '9'     :
				xc = 'Z';
			case    '-'     :
			case    '+'     :
				rlen = picture_count( c );
				sprintf((BPTR) &picture[picdex],"%c%u",xc,rlen);
				picdex = strlen( picture );
				length += rlen;
				continue;
			case    'X'     :
				xc = 'W';
			case    'A'     :
			case    'B'     :
				rlen = picture_count( c );
				sprintf((BPTR) &picture[picdex],"%c%u",xc,rlen);
				picdex = strlen( picture );
				length += rlen;
				continue;

			case    'P'     :
			case    'V'     :
				picture[picdex++] = 'V';
				continue;

			case    ','     :
				if ( Cobol->comma == ',' )
					xc = 'V';
				else    unget_byte();
				break;

			case    '.'     : 
				if ( is_end_of_sentance() )
					unget_byte();
				else if ( Cobol->comma == '.' )
					xc = 'V';
				else    unget_byte();
				break;

			case    '*'     :
			case    'S'     :
				picture[picdex++] = xc;
				continue;

			default         :
				unget_byte();
				break;

			}
		break;
		}
	if ( xc == 'V' ) {
		picture[picdex++] = '.';
		length++;
		while ( 1 ) {
			switch ((xc = (c = uppercase_byte()))) {
				case    '9'     :
					xc = 'Z';
					rlen = picture_count( c );
					sprintf((BPTR) &picture[picdex],"%c%u",xc,rlen);
					picdex = strlen( picture );
					length += rlen;
					continue;
				case    'Z'     :
					xc = 'N';
					rlen = picture_count( c );
					sprintf((BPTR) &picture[picdex],"%c%u",xc,rlen);
					picdex = strlen( picture );
					length += rlen;
					continue;
				case    'X'     :
					xc = 'W';
				case    'A'     :
				case    'B'     :
					rlen = picture_count( c );
					sprintf((BPTR) &picture[picdex],"%c%u",xc,rlen);
					picdex = strlen( picture );
					length += rlen;
					continue;

				case    'I'     :                                       
				case    'C'     :
					xc = 'N';
					rlen = picture_count( c );
					sprintf((BPTR) &picture[picdex],"%c%u",xc,rlen);
					picdex = strlen( picture );
					length += rlen;
					continue;

				case    'P'     :
					picture[picdex++] = 'V';
					continue;
				default         :
					unget_byte();
					break;

				}
			break;
			}
		}

	if ( vptr != (VCTRLPTR) 0 ) {
		/* Called from Data Picture Analysis */
		/* --------------------------------- */
		vptr->picsize = length;
		switch ((vptr->type & 3)) {
			case    2       :
				vptr->size = length;
				vptr->size++;
				if ( vptr->size & 1 )
					vptr->size++;
				vptr->size /= 2;
				break;

			case    3       :
				vptr->size = length;
				break;
			case    0       :
				vptr->size = 1;
				break;
			case    1       :
				vptr->size = 2;
				break;

			}

		if ( picdex > 0 ) {
			picture[picdex++] = 0;
			if ((picptr = allocate_for_string( picture )) == (BPTR) 0)
				return( allocation_failure() );
			}

		vptr->picture = picptr;

		}
	else    {
		/* Called from elsewhere to collect Picture Token */
		/* ---------------------------------------------- */
		if ( picdex > 0 ) {
			picture[picdex++] = 0;
			strcpy(TokenBuffer,picture);
			}
		else    TokenBuffer[0] = 0;
		}
	return( 0 );
}

WORD    translate_redefines( vptr )
VCTRLPTR        vptr;
{
	VCTRLPTR        xptr;
	trace("translate_redefines()\n");
	if (!( get_token() ))
		return( expected_variable() );
	else if ((xptr = locate_vctrl( TokenBuffer )) == (VCTRLPTR) 0)
		return( expected_variable() );
	
	vptr->redefines = xptr;
	return( 0 );    
}

WORD    collect_cobol_value()
{
	WORD    i=0;
	WORD    c;
	WORD    quote=0;

	if (!( remove_white_space() ))
		return( syntax_error(1027) );

	while ( 1 ) {
		if ( ! (quote ) )  {
			if ( is_mnemonic("SPACE") ) {
				CobolToAbal[i++] = '"';
				CobolToAbal[i++] = ' ';
				CobolToAbal[i++] = '"';
				}
			else if ( is_mnemonic("ZERO") ) {
				CobolToAbal[i++] = '0';
				CobolToAbal[i++] = ' ';
				}
			}
		c = get_byte();
		switch ( c ) {
			case    MOINS_UN:
			case    0       :
			case    '\n'    :
			case    '\r'    :
				return( 0 );
			case    '.'     :
				if (!( quote )) {
					unget_byte();
					CobolToAbal[i] = 0;
					return( i );
					}
				else    {
					CobolToAbal[i++] = 0;
					continue;
					}
			
			case    0x0027  :
			case    '"'	:
				if ( quote == c ) {
					quote = 0;
					c = '"';
					}
				else if (!(quote)) {
					quote = c;
					c = '"';
					}

			default         :
				CobolToAbal[i++] = c;
			}
		}
}

WORD    translate_value( vptr )
VCTRLPTR        vptr;
{
	if (collect_cobol_value() == 0)
		return( syntax_error(1027) );
	else if ((vptr->value = allocate_for_string( CobolToAbal )) == (BPTR) 0)
		return( allocation_failure() );
	else    return( 0 );
}


WORD    translate_indexed( vptr )
VCTRLPTR        vptr;
{
	(void) is_mnemonic( "BY" );
	do      {
		if (!( get_token() ))
			return( syntax_error(1027) );
		}
	while ( is_comma() );
	return( 0 );
}

WORD    translate_occurs( vptr )
VCTRLPTR        vptr;
{
	vptr->first = collect_integer();
	vptr->type  |= 0x0040;
	(void) is_mnemonic( "TIMES" );
	return( 0 );
}

WORD    translate_usage(vptr)
VCTRLPTR        vptr;
{
	(void) is_mnemonic( "IS" );
	if (!( get_token() ))
		return( syntax_error(1027) );   

	switch ( is_vctrl_keyword() ) {

		case _VCTRL_DISPLAY             :
			vptr->type &= 0xFFFC;
			vptr->type |= 3;
			if ( vptr->picsize != 0 )
				vptr->size = vptr->picsize;
			return( 0 );

		case _VCTRL_POINTER             :
			vptr->type |= _TYPE_POINTER;
			if ( vptr->picsize != 0 )
				vptr->size = vptr->picsize;
			return( 0 );

		case _VCTRL_PACKED_DECIMAL      :
		case _VCTRL_COMP_3              :
		case _VCTRL_COMPUTATIONAL_3     :
			vptr->type &= 0xFFFC;
			vptr->type |= 2;
			if ( vptr->picsize != 0 ) {
				vptr->size = vptr->picsize;
				vptr->size++;
				if ( vptr->size & 1 )
					vptr->size++;
				vptr->size /= 2;
				}
			else    vptr->size = 8;
			return( 0 );
			
		case _VCTRL_INDEX       :
		case _VCTRL_BINARY              :
		case _VCTRL_COMP                :
		case _VCTRL_COMPUTATIONAL       :
			vptr->type &= 0xFFFC;
			vptr->type |= 1;
			vptr->size = 2;
			return( 0 );

		default             :
			return( syntax_error(1027) );
		}
}

WORD    translate_sign( vptr )
VCTRLPTR        vptr;
{
	(void) is_mnemonic( "IS" );
	if (!( get_token() ))
		return( syntax_error(1027) );
	switch ( is_vctrl_keyword() ) {
		case _VCTRL_LEADING     :
		case _VCTRL_TRAILING    :
			break;
		default                 :
			return( syntax_error(1027) );
		}
	if ( is_mnemonic("SEPARATE") )
		(void) is_mnemonic( "CHARACTER" );
	return( 0 );

}

WORD    translate_blank( vptr )
VCTRLPTR        vptr;
{
	(void) is_mnemonic( "WHEN" );
	if (!( is_mnemonic( "ZERO" ) ))
		return( expected_keyword("ZERO") );
	else    return( 0 );
}

WORD    translate_justified( vptr )
VCTRLPTR        vptr;
{
	(void) is_mnemonic("RIGHT");
	return( 0 );
}

WORD    translate_synchronized( vptr )
VCTRLPTR        vptr;
{
	WORD    mode;
	if ( is_mnemonic("RIGHT") )
		mode = 1;
	else if ( is_mnemonic("LEFT") )
		mode = 2;
	else    mode = 0;
	return( 0 );
}

WORD    commit_vctrl_size( lptr, vptr, adjust, level )
VCTRLPTR        lptr;
VCTRLPTR        vptr;
WORD            adjust;
WORD            level;
{
	while ( lptr != (VCTRLPTR) 0 ) {
		if ( lptr->level < vptr->level ) {
/* sysprintf("\t[ %u : ] commit_vctrl_size( %s(%u) + %s(%u) ",level,lptr->name,lptr->size,vptr->name,adjust); */
			lptr->size += adjust;
/* sysprintf(":= %s(%u) ) )\n",lptr->name,lptr->size); */
			return( commit_vctrl_size( lptr->previous, lptr, adjust, (level+1) ) );
			}
		else    lptr = lptr->previous;
		}
	return( 0 );
}

WORD    translate_declaration()
{
	WORD            status;
	WORD            adjust;
	VCTRLPTR        vptr;
	if ( is_period() ) {
		if (( Cobol->CurrentVctrl != (VCTRLPTR) 0)
		&&  ((adjust = (Cobol->CurrentVctrl->size * Cobol->CurrentVctrl->first * Cobol->CurrentVctrl->second)) != 0     )
		&&  ( Cobol->CurrentVctrl->level != 77   )
		&&  ( Cobol->CurrentVctrl->level != 88   )
		&&  ((status = commit_vctrl_size( Cobol->CurrentVctrl->previous, Cobol->CurrentVctrl, adjust,1 )) != 0))
			return( status );
		Cobol->CurrentVctrl = (VCTRLPTR) 0;
		pop_operation_pointer();
		return( 0 );
		}
	else if ((vptr = Cobol->CurrentVctrl) == (VCTRLPTR) 0)
		return( expected_variable() );
	else if (!( get_token() ))
		return( syntax_error(1027) );

	switch ( is_vctrl_keyword() ) {

		case _VCTRL_DISPLAY             :
			vptr->type &= 0xFFFC;
			vptr->type |= 3;
			if ( vptr->picsize != 0 )
				vptr->size = vptr->picsize;
			return( 0 );

		case _VCTRL_PACKED_DECIMAL      :
		case _VCTRL_COMP_3              :
		case _VCTRL_COMPUTATIONAL_3     :
			vptr->type &= 0xFFFC;
			vptr->type |= 2;
			if ( vptr->picsize != 0 ) {
				vptr->size = vptr->picsize;
				vptr->size++;
				if ( vptr->size & 1 )
					vptr->size++;
				vptr->size /= 2;
				}
			else    vptr->size = 8;
			return( 0 );
			
		case _VCTRL_INDEX               :
		case _VCTRL_BINARY              :
		case _VCTRL_COMP                :
		case _VCTRL_COMPUTATIONAL       :
			vptr->type &= 0xFFFC;
			vptr->type |= 1;
			vptr->size = 2;
			return( 0 );

		case _VCTRL_SIGN                :
			return( translate_sign(vptr) );
		case _VCTRL_JUST                :
		case _VCTRL_JUSTIFIED           :
			return( translate_justified(vptr) );
		case _VCTRL_SYNC                :
		case _VCTRL_SYNCHRONIZED        :
			return( translate_synchronized(vptr) );
		case _VCTRL_BLANK               :
			return( translate_blank( vptr ) );
		case _VCTRL_REDEFINES   :
			return( translate_redefines( vptr ) );
		case _VCTRL_OCCURS      :
			return( translate_occurs( vptr ) );
		case _VCTRL_USAGE       :
			return( translate_usage(vptr) );
		case _VCTRL_INDEXED     :
			return( translate_indexed( vptr ) );
		case _VCTRL_PIC         :
		case _VCTRL_PICTURE     :
			return( translate_picture( vptr ) );
		case _VCTRL_VALUE       :
			if (( Cobol->CurrentFctrl != (FCTRLPTR) 0 )
			||  ( vptr->first > 1 ))
				return( syntax_error(1027) );
			else    return( translate_value( vptr ) );
		case _VCTRL_GLOBAL      :
			vptr->scope = _GLOBAL_SCOPE;
			return( 0 );
		case _VCTRL_EXTERNAL    :
			vptr->scope = (_EXTERNAL_SCOPE | _GLOBAL_SCOPE);
			return( 0 );
		default                 :
			return( syntax_error(1027) );
		}
}

WORD            build_88_thru( vptr )
VCTRLPTR        vptr;
{
	RCTRLPTR        rptr;

	if ((rptr = allocate_for_rctrl(TokenBuffer)) == (RCTRLPTR) 0)
		return( allocation_failure() );
	else if (!( get_token() ))
		return( syntax_error(1027) );
	else if ((rptr->next = allocate_for_rctrl(TokenBuffer)) == (RCTRLPTR) 0)
		return( allocation_failure() );
	else    {
		vptr->record = rptr;
		vptr->type = 0x00FF;
		return( verify_period() );
		}
}

WORD            build_88_list( vptr )
VCTRLPTR        vptr;
{
	RCTRLPTR        rptr;


	do      {
		if ((rptr = allocate_for_rctrl(TokenBuffer)) == (RCTRLPTR) 0)
			return( allocation_failure() );
		rptr->next = vptr->record;
		vptr->record = rptr;
		}
	while ( get_token() );
	vptr->type = 0x00FE;
	return( verify_period() );
}

WORD    translate_cobol_data88(mode)
WORD    mode;
{
	VCTRLPTR        vptr;

	/* Ensure in WORKING-STORAGE SECTION */
	/* --------------------------------- */
	if ( mode !=  0)
		return( syntax_error(1027) );

	if (!( get_token() ))
		return( syntax_error(1027) );
	if ((vptr = locate_vctrl( TokenBuffer )) != (VCTRLPTR) 0)
		return( symbol_already_defined(TokenBuffer) );
	if ((vptr = allocate_for_vctrl( TokenBuffer)) == (VCTRLPTR) 0)
		return( allocation_failure() );

	vptr->level = 88;

	if (!( is_mnemonic("VALUE")  ))
		return( expected_keyword("VALUE") );

	if (!( get_token() ))
		return( syntax_error(1027) );

	if (( is_mnemonic( "THRU"    ) )
	||  ( is_mnemonic( "THROUGH" ) ))
		return( build_88_thru( vptr ) );
	else    return( build_88_list( vptr ) );

}

WORD    translate_cobol_data(mode)
WORD    mode;
{
	WORD            level;
	VCTRLPTR        vptr;
	trace("translate_cobol_data()\n");
	if ((level = collect_integer()) == 88)
		return( translate_cobol_data88(mode) );
	if ((is_mnemonic("FILLER"))
	||  (is_mnemonic("FIL")))
		sprintf(TokenBuffer,"$F%u$F",Cobol->FillerCount++);
	else if (!( get_token() ))
		return( syntax_error(1027) );
	if ((vptr = locate_vctrl( TokenBuffer )) != (VCTRLPTR) 0)
		return( symbol_already_defined(TokenBuffer) );
	if ((vptr = allocate_for_vctrl( TokenBuffer)) == (VCTRLPTR) 0)
		return( allocation_failure() );
	vptr->level = level;
	if ((mode)
	&&  (Cobol->CurrentFctrl != (FCTRLPTR) 0))
		vptr->size   = Cobol->CurrentFctrl->recordsize;
	else    vptr->size   = 0;
	vptr->type   = 3;
	vptr->first  = 1;
	vptr->second = 1;
	Cobol->CurrentVctrl = vptr;
	push_operation_pointer();
	set_operation_pointer(translate_declaration);
	if (( mode ) 
	&&  ( level == 1 )
	&&  ( Cobol->CurrentFctrl != (FCTRLPTR) 0)) {
		if (( Cobol->CurrentFctrl->recordbuf == (BPTR) 0)
		&&  ( vptr->name != (BPTR) 0))
			if  ((Cobol->CurrentFctrl->recordbuf = allocate_for_string( vptr->name )) == (BPTR) 0)
				return( allocation_failure() );
		vptr->fichier = (VPTR) Cobol->CurrentFctrl;
		vptr->nature = _KW1_PTR;
		return( add_fctrl_record( Cobol->CurrentFctrl, vptr->name ) );
		}
	return( 0 );
}

WORD    translate_file_id()
{
	FCTRLPTR        fptr;

	if (!( get_filename() ))
		return( syntax_error(1027) );
	if ( TokenBuffer[0] == 0x0027 ) {
		TokenBuffer[0] = '"';
		TokenBuffer[(strlen(TokenBuffer)-1)] = '"';
		}

	if ((fptr = Cobol->CurrentFctrl ) != (FCTRLPTR) 0) {
		if ( fptr->assign != (BPTR) 0 )
			liberate( fptr->assign );
		if ((fptr->assign = allocate_for_string( TokenBuffer )) == (BPTR) 0)
			return( allocation_failure() );
		else    return( verify_period() );
		}
	else    return( syntax_error(1027) );
}

WORD    translate_label_record()
{
	if ( is_mnemonic("RECORD") )
		(void) is_mnemonic("IS");
	else if ( is_mnemonic("RECORDS") )
		(void) is_mnemonic("ARE");
	else    return( syntax_error(1027) );   
	if ((!(  is_mnemonic("STANDARD") ))
	&&  (!(  is_mnemonic("OMITTED")  )))
		return( syntax_error(1027) );
	else    return( 0 );
}

WORD    translate_data_file()
{
	WORD    status;
	if ( is_numeric() ) {
		if ( Cobol->CurrentFctrl == (FCTRLPTR) 0)
			return( syntax_error(1027) );
		else    return( translate_cobol_data(1) );
		}
	if ( get_token() ) {
		switch ( is_vctrl_keyword() ) {
			case _VCTRL_SD  :
			case _VCTRL_RD  :
				return( not_yet_available() );
			case _VCTRL_FD  :
				if ((!( get_token() ))
				||  ((Cobol->CurrentFctrl = locate_fctrl( TokenBuffer )) == (FCTRLPTR) 0))
					return( syntax_error(1027) );

				if ( is_mnemonic("RECORD") ) {
					(void) is_mnemonic("CONTAINS");
					Cobol->CurrentFctrl->recordsize = collect_integer();
					(void) is_mnemonic("CHARACTERS");
					}
				else if ( is_mnemonic("BLOCK") ) {
					(void) is_mnemonic("CONTAINS");
					Cobol->CurrentFctrl->recordsize = collect_integer();
					(void) is_mnemonic("CHARACTERS");
					(void) is_mnemonic("RECORDS");
					}
				else if (( is_mnemonic("LABEL") )
				     &&  ((status = translate_label_record()) != 0))
					return( status );
				return( verify_period() );

			case _VCTRL_LABEL   :
				if ((status = translate_label_record()) != 0)
					return( status );
				return( xverify_period() );

			case _VCTRL_VALUE   :
				if ((!(get_token()))
				||  (is_vctrl_keyword() != _VCTRL_OF )
				||  (!(get_token()))
				||  (is_vctrl_keyword() != _VCTRL_FILE_ID ))
					return( syntax_error(1027) );

			case _VCTRL_FILE_ID :
				if (( get_token() )
				&&  (is_vctrl_keyword() == _VCTRL_IS ))
					return( translate_file_id() );
				else    return( expected_keyword("IS" ));

			case MOINS_UN   :
				Cobol->CurrentFctrl = (FCTRLPTR) 0;
				return( enter_data_section() );
			}
		}
	Cobol->CurrentFctrl = (FCTRLPTR) 0;
	return( syntax_error(1027) );
}

WORD    translate_data_work()
{
	if ( is_numeric() )
		return( translate_cobol_data(0) );
	else if ( get_token() )
		return( enter_data_section() );
	else    return( syntax_error(1027) );
}

WORD    translate_data_link()
{
	if ( is_numeric() )
		return( translate_cobol_data(2) );
	else if ( get_token() )
		return( enter_data_section() );
	else    return( syntax_error(1027) );
}



WORD    is_section()
{
	if ((get_token())
	&&  (is_environ_keyword() == _ENVIRON_SECTION)) {
		if (is_period())
			return( 0);
		else    return( incorrect_punctuation() );
		}
	else    return( expected_keyword("SECTION") );
}

WORD     enter_env_config()
{
	WORD    status;
	trace("enter_env_config()\n");
	if ((status = is_section()) != 0)
		return( status );
	push_operation_pointer();
	set_operation_pointer(translate_env_config);
	return( 0 );
}

WORD     enter_env_io()
{
	WORD    status;
	trace("enter_env_io()\n");
	if ((status = is_section()) != 0)
		return( status );
	push_operation_pointer();
	set_operation_pointer(translate_env_io);
	return( 0 );
}

WORD    enter_data_file()
{
	WORD    status;
	trace("enter_data_file()\n");
	if ((status = is_section()) != 0)
		return( status );
	push_operation_pointer();
	set_operation_pointer(translate_data_file);
	return( 0 );
}

WORD    enter_data_work()
{
	WORD    status;
	trace("enter_data_work()\n");
	if ((status = is_section()) != 0)
		return( status );
	push_operation_pointer();
	set_operation_pointer(translate_data_work);
	return( 0 );
}
WORD    enter_data_link()
{
	WORD    status;
	trace("enter_data_link()\n");
	if ((status = is_section()) != 0)
		return( status );
	push_operation_pointer();
	set_operation_pointer(translate_data_link);
	/* Indicate Module */
	/* --------------- */
	Context->options |= _CONTEXT_MODULE;
	return( 0 );
}
WORD    enter_environ_section()
{
	WORD    type;
	switch ((type = is_environ_keyword())) {
		case _ENVIRON_SECTION           :
			return( syntax_error(1027) );
		case _ENVIRON_CONFIGURATION     :
			return( enter_env_config() );
		case _ENVIRON_INPUT_OUTPUT      :
			return( enter_env_io() );
		case    MOINS_UN                :
			return( enter_division() );
		}
	return( syntax_error(1027) );
}

WORD    enter_data_section()
{
	WORD    type;
	switch ((type = is_datadiv_keyword())) {
		case _DATADIV_SECTION           :
			return( syntax_error(1027) );
		case _DATADIV_FILE              :
			return( enter_data_file() );
		case _DATADIV_WORKING_STORAGE   :
			return( enter_data_work() );
		case _DATADIV_LINKAGE           :
			return( enter_data_link() );
		case _DATADIV_SCREEN            :
			return( enter_data_screen() );
		case    MOINS_UN                :
			return( enter_division() );
		}
	return( syntax_error(1027) );
}

WORD    translate_env_div()
{
	WORD    type;
	trace("translate_env_div()\n");
	if ( get_token() )
		return( enter_environ_section() );
	else    return( syntax_error(1027) );
}

WORD    translate_data_div()
{
	
	trace("translate_data_div()\n");
	if ( get_token() )
		return( enter_data_section() );
	return( syntax_error(1027) );
}

WORD    no_operation()
{
	return( 0 );
}

WORD    enter_procedure_translation()
{
	return(0);
}

WORD    enter_segmental_translation()
{
	set_local_scope();
	return(0);
}

VOID    leave_segmental_translation()
{
	liberate_local_symbols();
	initialise_field((FIELDPTR) & Context->LocalField );
	set_global_scope();
	return;
}


WORD    terminate_proc_div()
{
	WORD    status=0;
	WORD    segnumber=MOINS_UN;
	BPTR    segname=(BPTR) 0;
	if ( Cobol != (COBOLPTR) 0) {
		if (( Cobol->Next != (COBOLPTR) 0)
		||  ( context_is_module ))
			segname   = Cobol->CurrentProgram;
		else    segnumber = 0;
		status = terminate_procedure_label();
		status = terminate_for_perform();
		status = terminate_segment( segnumber, segname,0 );
		leave_segmental_translation();
		}
	return( status );
}

WORD    translate_end()
{
	WORD            status=0;
	COBOLPTR        cbptr;
	trace("translate_end()\n");
	if ( Cobol != (COBOLPTR) 0 ) {
		if ( Cobol->CurrentDivision == _PROC_DIV )
			status = terminate_proc_div();
		if ((cbptr = Cobol->Next) == (COBOLPTR) 0) {
			status = terminate_tcode();
			Context->operation = no_operation;
			}
		else    {
			push_operation_pointer();
			set_operation_pointer(translator_startup);
			}
		Cobol = liberate_for_cobol();
		}
	return( status );
}

WORD    reset_affectation( status )
WORD    status;
{
	Context->TargetVariable = (TCVARPTR) 0;
	Context->ConvertType    = 2;
	return( status );
}

WORD    picture_affectation( vptr, rptr )
TCVARPTR        vptr;
RESULTPTR       rptr;
{
	VCTRLPTR        vctrl;
	if (((vctrl = locate_vctrl( vptr->name )) != (VCTRLPTR) 0)
	&&  (( vctrl->type & 3 ) == 3)
	&&  ( vctrl->picture != (BPTR) 0 ))
		return( clf_print( variable_result( vptr ), vctrl->picture, rptr ) );
	else    return( generate_affectation( vptr, rptr,VRAI ) );
}

WORD    translate_move_statement()
{
	RESULTPTR       rptr;
	TCVARPTR        vptr;
	WORD            status;
	(void) is_mnemonic("CORRESPONDING");
	if  ((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
		return( expected_variable() );
	if (!( is_mnemonic("TO") ))
		return( expected_keyword("TO") );
	while(1) {
		if (!( get_token() ))
			return( xverify_period() );
		else if ((vptr = is_variable(0)) == (TCVARPTR) 0)
			return( unget_token() );
		else if ((status = reset_affectation( 
					picture_affectation( vptr, rptr ))) != 0)
			return( status );
		(void) is_comma();
		}
}

RESULTPTR       xevaluate_operation( mode, op, rptr, lptr )
WORD            mode;
WORD            op;
RESULTPTR       rptr;
RESULTPTR       lptr;
{
	if ( mode == VRAI )
		return(evaluate_operation( op, lptr, rptr ));
	else    return(evaluate_operation( op, rptr, lptr ));
}

WORD    translate_arithmetic_statement(operation)
WORD    operation;
{
	RESULTPTR       rptr;
	RESULTPTR       lptr;
	RESULTPTR       aptr;
	RESULTPTR       xptr;
	TCVARPTR        vptr;
	WORD            status;
	WORD            type=FAUX;

	/* Collect first operand */
	/* --------------------- */
	if ((lptr = evaluate_expression(0)) == (RESULTPTR) 0)
		return( expected_variable() );

	/* Sumate possible list to first operand (Normally only '-') */
	/* --------------------------------------------------------- */
	if (( operation == '-' )
	||  ( OtrOption.Enhanced )) {
		while (1) {
			(void) is_comma();
			if ( is_mnemonic("FROM") ) {
				type  = _STATEMENT_FROM;
				break;
				}
			else if ( is_mnemonic("BY") ) {
				type  = _STATEMENT_BY;
				break;
				}
			else if ( is_mnemonic("INTO") ) {
				type  = _STATEMENT_INTO;
				break;
				}
			if (((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
			||  ((lptr = evaluate_operation( '+', lptr, rptr )) == (RESULTPTR) 0))
				return( syntax_error(1027) );
			}
		}

	/* Collect and verify operation */
	/* ---------------------------- */
	switch ( type ) {
		case _STATEMENT_FROM    :
			if ( operation != '-' )
				return( syntax_error(1027) );
			else    break;
		case _STATEMENT_BY      :
			if ( operation == '*' )
				break;
			else if ( operation != '/' )
				return( syntax_error(1027) );
			else    {
				type = VRAI;
				break;
				}
		case _STATEMENT_INTO    :
			if ( operation == '/' )
				break;
		default                 :
			return( syntax_error(1027) );
		}

	if (((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
	||  ((xptr = xevaluate_operation( type, operation, rptr, lptr )) == (RESULTPTR) 0))
		return( syntax_error(1027) );

	if ( is_mnemonic( "GIVING" ) ) {
		while (1) {
			if (!( get_token() ))
				break;
			if ((vptr = is_variable(0)) == (TCVARPTR) 0) {
				unget_token();
				break;
				}

			if  ( is_mnemonic("ROUNDED" )) {
				if ((aptr = clf_round(xptr,vctrl_rounding(vptr))) == (RESULTPTR) 0)
					return( syntax_error(1027) );
				}
			else    aptr = xptr;

			if ((status = reset_affectation( picture_affectation( vptr, aptr ))) != 0)
				return( status );
			(void) is_comma();
			}

		if (( operation == '/' )
		&&  ( is_mnemonic("REMAINDER"))) {
			if ((xptr = xevaluate_operation( type, '%', rptr, lptr )) == (RESULTPTR) 0)
				return( syntax_error(1027) );
			while (1) {
				if (!( get_token() ))
					break;
				if ((vptr = is_variable(0)) == (TCVARPTR) 0) {
					unget_token();
					break;
					}
				if  ( is_mnemonic("ROUNDED" )) {
					if ((lptr = clf_round(xptr,vctrl_rounding(vptr))) == (RESULTPTR) 0)
						return( syntax_error(1027) );
					}
				else    lptr = xptr;
				if ((status = reset_affectation( picture_affectation( vptr, lptr ))) != 0)
					return( status );
				(void) is_comma();
				}
			}
		}
	else    {
		if (( (rptr->nature & _RESULT_BASIC) != _RESULT_VARB )
		||  ((vptr = (TCVARPTR) rptr->contents) == (TCVARPTR) 0))
			return( syntax_error(1027) );
		if (( is_mnemonic("ROUNDED" ))
		&&  ((xptr = clf_round(xptr,vctrl_rounding(vptr))) == (RESULTPTR) 0))
			return( syntax_error(1027) );
		if ((status = reset_affectation( picture_affectation( vptr, xptr ))) != 0)
			return( status );
		while (1) {
			(void) is_comma();
			if (!( get_token() ))
				break;
			else if ((vptr = is_variable(0)) == (TCVARPTR) 0) {
				unget_token();
				break;
				}       
			else if ((xptr = xevaluate_operation( type, operation, variable_result(vptr), lptr )) == (RESULTPTR) 0)
				return( syntax_error(1027) );
			if (( is_mnemonic("ROUNDED" ))
			&&  ((xptr = clf_round(xptr,vctrl_rounding(vptr))) == (RESULTPTR) 0))
				return( syntax_error(1027) );
			if ((status = reset_affectation( picture_affectation( vptr, xptr ))) != 0)
				return( status );
			}
		}
	return( xverify_period() );
}

WORD    translate_compute()
{
	TCVARPTR        vptr;
	RESULTPTR       rptr;
	WORD            status;
	WORD            rounded=FAUX;

	trace("translate_compute()\n");
	if (!(get_token()))
		return( expected_variable() );
	if ((vptr = is_variable(1)) == (TCVARPTR) 0)
		return( expected_variable() );
	Context->TargetVariable = vptr;
	Context->ConvertType = (vptr->type->type & 3);

	if ( is_mnemonic("ROUNDED") )
		rounded = VRAI;

	if ( is_equals() ) {
		if  ((rptr = evaluate_expression(0)) != (RESULTPTR) 0) {
			if ((rounded)
			&&  ((rptr = clf_round(rptr,vctrl_rounding(vptr))) == (RESULTPTR) 0))
				return( syntax_error(1027) );
			if ( Context->TargetVariable != (TCVARPTR) 0)
				return((status = reset_affectation( picture_affectation( vptr, rptr ) )) );
			else    return((status = reset_affectation( 0 )));
			}
		return((status = reset_affectation( syntax_error(1027) )) );
		}
	else    return((status = reset_affectation( syntax_error(1027) )) );
}

WORD    translate_add_statement()
{
	RESULTPTR       xptr;
	RESULTPTR       rptr;
	RESULTPTR       lptr;
	TCVARPTR        vptr;
	WORD            rounded=FAUX;
	WORD            status;
	WORD            type;
	WORD            keyword=0;

	if ((lptr = evaluate_expression(0)) == (RESULTPTR) 0)
		return( expected_variable() );
	while (1) {
		(void) is_comma();
		if ( is_mnemonic("TO") ) {
			type  = _STATEMENT_TO;
			break;
			}
		else if ( is_mnemonic("GIVING") ) {
			type  = _STATEMENT_GIVING;
			break;
			}
		if (((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
		||  ((lptr = evaluate_operation( '+', lptr, rptr )) == (RESULTPTR) 0))
			return( syntax_error(1027) );
		}
	switch (type) {
		case _STATEMENT_TO      :
			while (1) {
				if (!( get_token() ))
					break;
				else if ((vptr = is_variable(0)) == (TCVARPTR) 0) {
					unget_token();
					break;
					}
				if  ( is_mnemonic("ROUNDED" ))
					rounded = VRAI;
				else    rounded = FAUX;
				if ((rptr = evaluate_operation( '+', lptr, variable_result(vptr) )) == (RESULTPTR) 0)
					return( syntax_error(1027) );
				if (( rounded )
				&&  ((rptr = clf_round(rptr,vctrl_rounding(vptr))) == (RESULTPTR) 0))
					return( syntax_error(1027) );
				if ((status = reset_affectation( picture_affectation( vptr, rptr ))) != 0)
					return( status );
				(void) is_comma();
				}
			break;
		case _STATEMENT_GIVING  :
			while (1) {
				if (!( get_token() ))
					break;
				else if ((vptr = is_variable(0)) == (TCVARPTR) 0) {
					unget_token();
					break;
					}
				if ( is_mnemonic("ROUNDED" )) {
					if  ((xptr = clf_round(lptr,vctrl_rounding(vptr))) == (RESULTPTR) 0)
						return( syntax_error(1027) );
					}
				else    xptr = lptr;
				if ((status = reset_affectation( picture_affectation( vptr, xptr ))) != 0)
					return( status );
				(void) is_comma();
				}
			break;
		default                 :
			return( syntax_error(1027) );
		}
	return( xverify_period() );
}

WORD    get_more_logic()
{
	WORD    status;
	trace("get_more_logic()\n");
	while (1) {
		if ((status = get_token()) != 0)
			return( status );
		if ((status = remove_white_space()) != 0)
			return( 0 );
		if ((status = new_input_line()) != 0)
			continue;
		else    return(0);
		}
}

WORD    conditional_expression(repeat_until)
WORD    repeat_until;
{
	RESULTPTR       lptr=(RESULTPTR) 0;
	RESULTPTR       rptr=(RESULTPTR) 0;
	WORD            operation;
	WORD            status;
	WORD            logic=_LOGICAL_END;
	WORD            more_logic=VRAI;
	WORD            braces;
	trace("conditional_expression()\n");
	while (1) {

		if ((lptr = evaluate_expression(0)) == (RESULTPTR) 0)
			return(1);

		while ( is_right_brace() );

		if ((operation = comparison_operator(repeat_until)) != 0) {

			if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
				return(1);

			}
		else    rptr = (RESULTPTR) 0;

		while ( is_right_brace() );

		if ((more_logic = get_more_logic()))  {
			if ((logic = is_logical_keyword()) == MOINS_UN) {
				(void) unget_token();
				logic = ( repeat_until ? _LOGICAL_OR : _LOGICAL_AND );
				more_logic = 0;
				}
			}
		else    logic = ( repeat_until ? _LOGICAL_OR : _LOGICAL_AND );

		switch (logic) {
			case _LOGICAL_END:
			case _LOGICAL_AND:
				if (!(repeat_until))
					operation = reverse_compare( operation );
				break;
			case _LOGICAL_OR : /* AND LOGIC : INVCMP : TRUE  */
				if (repeat_until)
					operation = reverse_compare( operation );
				break;
			}

		if ( repeat_until ) {
			if ( logic == _LOGICAL_AND )
				logic = _LOGICAL_OR;
			else    logic = _LOGICAL_AND;
			}

		if ((status = evaluate_comparison(operation,lptr,rptr,logic,0)) != 0 )
			return( status );

		/* Terminate if Terminal Logic */
		/* --------------------------- */
		if (!(more_logic)) {
			while ( is_right_brace() );
			return( 0 );
			}
		}

}

WORD    translate_if()
{
	WORD            status=0;

	if ((status = enter_iteration( _ITERATION_IF,(TCVARPTR) 0  )) != 0)
		return( status );
	else if ((status = conditional_expression(0)) != 0 )
		return( status );
	else if ( dcl_operate_label() == 0 )
		return( syntax_error(1027) );
	(void)  is_mnemonic("THEN");
	if (  is_mnemonic("NEXT") ) {
		if (!(is_mnemonic("SENTANCE")))
			return( expected_keyword("SENTANCE") );
		else    generate_iteration() ;
		}
	return( 0 );    
}

WORD    translate_else()
{
	WORD    status=0;
	WORD    holder;
	BPTR    ifstate;
	while (1) {
		if ((status = locate_iteration( _ITERATION_IF )) != 0)
			return( syntax_error(1027) );
		if ((ifstate = (BPTR) get_iteration_context()) != (BPTR) 0)
			leave_iteration();
		else if ((status = set_iteration_context("ELSE")) != 0)
			return( status );
		else    break;
		}
	generate_iteration();
	dcl_abandon_label();    
	return(status);
}

WORD    translate_chain()
{
	WORD    status;
	if (!( get_filename() ))
		return( syntax_error(1027) );
	if ((status = assign_chain_stop(1,TokenBuffer)) != 0)
		return( status );
	else    return( verify_period() );
}       


static WORD     translate_use()
{
	WORD            mode;
	WORD            sens=3;
	FCTRLPTR        fptr;
	if (!(is_mnemonic( "AFTER")))
		return( expected_keyword("AFTER") );
	(void) is_mnemonic("STANDARD");
	if ( is_mnemonic( "EXCEPTION" ) )
		mode = 1;
	else if ( is_mnemonic( "ERROR" ) )
		mode = 0;
	else    mode = MOINS_UN;
	if (!( is_mnemonic( "PROCEDURE" ) ))
		return( expected_keyword("PROCEDURE") );
	(void) is_mnemonic("ON");
	if ( is_mnemonic( "INPUT" ) )
		sens = 1;
	else if ( is_mnemonic( "OUTPUT" ) )
		sens = 2;
	else if ( is_mnemonic( "I-O" ) )
		sens = 3;
	else    {
		if ((!( get_token() ))
		||  (( fptr = locate_fctrl( TokenBuffer )) == (FCTRLPTR) 0))
			return( expected_file() );
		}               
	return( xverify_period() );
}

WORD    translate_end_program()
{
	WORD    status;
	if ( is_mnemonic("PROGRAM") ) {
		if (( get_token() )
		&&  ( Cobol != (COBOLPTR) 0 )
		&&  ( Cobol->CurrentProgram != (BPTR) 0 )
		&&  ( compare_tokens( Cobol->CurrentProgram, TokenBuffer ))) {
			if ((status = translate_end()) != 0)
				return( status );
			else    return( verify_period() );
			}
		return( expected_program() );
		}
	return( MOINS_UN );
}

WORD    translate_declaratives()
{
	WORD    status;
	switch ( is_declarative() ) {
		case _DECLARE_END               :
			if ((status = translate_end_program()) != MOINS_UN )
				return( status );
			else if (( get_token() )
			     && ( is_procdiv_keyword() == _PROCDIV_DECLARATIVES ))
				return( verify_period() );

			return( syntax_error(1027) );

		case _DECLARE_USE               :
			return( translate_use() );
		case MOINS_UN                   :
			return( MOINS_UN );
		default                         :
			return( syntax_error(1027) );
		}
}

WORD    translate_enter()
{
	WORD    lang;
	if ( is_mnemonic( "ABAL" ) )
		lang = 1;
	else if ( is_mnemonic( "COBOL" ) )
		lang = 0;
	else    return( syntax_error(1027) );
	(void) get_token();
	return( verify_period() );
}

RESULTPTR       resolve_segment_identifier( nptr )
BPTR            nptr;   /* Expected to be a SEGMENT/PROGRAM identifier */
{
	RESULTPTR       rptr=(RESULTPTR) 0;
	WORD            nombre=MOINS_UN;
	WORD            status=0;

	if (((nombre = resolve_external_segment( nptr )) == 0 )
	&&  ((nombre = resolve_internal_segment( nptr )) == MOINS_UN )) {
		if  (((status = add_external_segment( nptr, (nombre = MOINS_UN), (BPTR) 0, MOINS_UN, FAUX)) != 0)
		||   ((nombre = resolve_external_segment( nptr )) == 0 ))
			return( rptr );
		}
	return( integer_result( nombre ) );
}

WORD    translate_cancel()
{
	WORD    status;

	trace("translate_cancel()\n");

	if ( is_mnemonic("PROGRAM") ) {
		if ((status = generate_segm_end()) != 0)
			return( status );
		else    return(verify_period());
		}
	else if (!( get_token() ))
		return( expected_program() );
	else if ((status = generate_clfendseg( named_segment(TokenBuffer) )) != 0)
		return( status );
	else    return(verify_period());
}

WORD    translate_call()
{
	WORD            status;
	RESULTPTR       number;

	trace("translate_call()\n");

	if ((!( get_token() ))
	||  ((number = resolve_segment_identifier( TokenBuffer )) == (RESULTPTR) 0))
		return( expected_program() );
	
	if ( is_mnemonic("USING") )
		return( not_yet_available() );

	else if ((status = generate_ldgoseg( number, MOINS_UN,MOINS_UN )) != 0)
		return( status );
	else    return(verify_period());
	
}

RESULTPTR       evaluation_expression()
{
	if ( is_mnemonic("TRUE") )
		return( integer_result(1) );
	else if ( is_mnemonic("FALSE") )
		return( integer_result(0) );
	else    return( evaluate_expression(0) );
}

WORD    translate_evaluate()
{
	WORD            status;
	WORD            iterfois=1;
	RESULTPTR       lptr=(RESULTPTR) 0;
	trace("translate_examine()\n");
	if ((status = enter_iteration( _ITERATION_SELECT,(TCVARPTR) 0  )) != 0)
		return( status );
	else    {
		if (((lptr = evaluation_expression()) != (RESULTPTR) 0)
		&&  ((lptr = ensure_register(lptr)) != (RESULTPTR) 0)
		&&  ((status = select_operand(lptr)) == 0 )) {
			while ( is_mnemonic("ALSO") ) {
				if (((lptr = evaluate_expression(0)) != (RESULTPTR) 0)
				&&  ((lptr = ensure_register(lptr)) != (RESULTPTR) 0)
				&&  ((status = SelectOperand(lptr,iterfois++)) == 0 ))
					continue;
				else    return( syntax_error(1027) );
				}
			generate_iteration();
			return( xverify_period() );
			}
		else    return( syntax_error(1027) );
		}

}

WORD    translate_other()
{
	WORD    status;
	if ((status = locate_iteration( _ITERATION_SELECT )) != 0)
		return( syntax_error(1027) );
	if (((status = iteration_type())  == _ITERATION_SELECT )
	&&  ((status = break_prior_to_case())             == 0 )
	&&  ((status = dcl_iteration_label())             != 0 ))
		return( xverify_period() );
	else    return( syntax_error(1027) );
}

WORD    translate_when()
{
	RESULTPTR       lptr=(RESULTPTR) 0;
	RESULTPTR       rptr=(RESULTPTR) 0;
	WORD            status;
	WORD            operator;
	WORD            iterfois=1;
	WORD            mode=_LOGICAL_OR;
	trace("\ntranslate_when()\n");
	if ( is_mnemonic("OTHER") )
		return( translate_other() );
	if ((status = locate_iteration( _ITERATION_SELECT )) != 0)
		return( syntax_error(1027) );
	if (( iteration_type() == _ITERATION_SELECT )
	&&  ((lptr = iteration_operand()) !=(RESULTPTR) 0)
	&&  ((status = break_prior_to_case()) == 0)
	&&  ((status = dcl_iteration_label()) != 0)
	&&  ((status = new_iterate_label()) != 0)) {
		while ( 1 ) {
			trace("when_expression\n");
			if ((lptr = mark_live_result( lptr )) == (RESULTPTR) 0)
				return( internal_error(7) );
			if ((operator = comparison_operator(0)) == 0)
				operator = _CMP_EQ;
			if ( is_mnemonic("ANY")  )
				rptr = lptr;
			else if ( is_mnemonic("TRUE") )
				rptr = integer_result(1);
			else if ( is_mnemonic("FALSE") )
				rptr = integer_result(0);
			else    rptr = evaluate_expression(0);
			if ( rptr == (RESULTPTR) 0 )
				return( syntax_error(1027) );

			if ( is_mnemonic("ALSO") ) {
				mode = _LOGICAL_NEX;
				operator = reverse_compare(operator);
				}
			else    mode = _LOGICAL_OR;

			if ((status = evaluate_comparison(operator,lptr,rptr,mode,0)) != 0 )
				return( status );
			if ( mode == _LOGICAL_NEX ) {
				if ((lptr = IterationOperand(iterfois++)) == (RESULTPTR) 0)
					return( syntax_error(1027) );
				}
			else    break;
			}
		generate_iteration();
		if (((status = dcl_operate_label()) != 0)
		&&  ((lptr = mark_dead_result( lptr )) != (RESULTPTR) 0)
		&&  ((status = new_operate_label()) != 0))
			return(xverify_period());
		}
	return( syntax_error(1027) );
}

WORD    translate_end_evaluate()
{
	WORD    status;
	if ((status = locate_iteration( _ITERATION_SELECT )) != 0)
		return( syntax_error(1027) );
	leave_iteration();
	return( xverify_period());
}

/*
 *      INSPECT <v> REPLACING   [ CHARACTERS  BY <r> ]
 *                              [ ALL     <s> BY <r> ]
 *                              [ FIRST   <s> BY <r> ]
 *                              [ LEADING <s> BY <r> ]
 */

static WORD     inspect_options()
{
	if ( is_mnemonic( "CHARACTERS" ) )
		return( 1 );
	else if ( is_mnemonic("ALL" ) )
		return( 2 );
	else if ( is_mnemonic("LEADING" ) )
		return(3);
	else if ( is_mnemonic("FIRST" ) )
		return( 4 );
	else    return( MOINS_UN );
}

static WORD     inspect_replacing( vptr )
RESULTPTR       vptr;
{
	WORD            mode;
	WORD            label;
	WORD            fin;
	WORD            status;
	TCVARPTR        tcvptr;
	RESULTPTR       sptr;
	RESULTPTR       rptr;
	RESULTPTR       zptr;
	RESULTPTR       xptr;

	if ((mode = inspect_options()) == MOINS_UN)
		return( syntax_error(1027) );
	else if (( mode > 1  )
	     &&  ((sptr = evaluate_expression(0)) == (RESULTPTR) 0))
		return( expected_variable() );
	else if (!( is_mnemonic("BY") ))
		return( expected_keyword("BY") );
	else if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
		return( expected_variable() );
	else if ( mode == 1 ) {
		if ((tcvptr = vptr->contents) == (TCVARPTR) 0)
			return( expected_variable() );
		else if ((xptr = clf_gener(rptr,integer_result(tcvptr->type->size))) == (RESULTPTR) 0)
			return( allocation_failure() );
		else    return( generate_affectation( tcvptr, xptr,VRAI ) );
		}
	else    {
		/* &DEBUT */
		/* ------ */
		if ( mode != 4 )
			(void) dcl_implicite_label((label = new_implicite_label()));
		/* ---------------------------------- */
		/* <reg> = CLF_INDEX(<var>,<pattern>) */
		/* ---------------------------------- */
		if ((xptr = clf_index(vptr,sptr)) == (RESULTPTR) 0)
			return( syntax_error(1027) );

		fin = new_implicite_label();

		/* ------------------------ */
		/* IF <reg> = 0 : Goto &Fin */
		/* ------------------------ */
		if ((zptr = integer_result( 0 )) == (RESULTPTR) 0)
			return( allocation_failure() );
		else if ((status = evaluate_comparison(_CMP_EQ,xptr,zptr,_LOGICAL_USE,fin)) != 0 )
			return( status );

		/* <var> = CLF_INCLUD( <reg>, <replacement> ) */
		/* ------------------------------------------ */
		Context->TargetVariable = (TCVARPTR) vptr->contents;
		Context->ConvertType    = 3;
		
		(void) clf_includ(xptr,rptr);

		/* GOTO &Debut */
		/* ----------- */
		if ( mode == 2 )
			if ((status = implicite_goto( label )) != 0)
				return( status );

		/* &FIN */
		/* ---- */
		dcl_implicite_label(fin);

		}

	return(0);
}

static WORD     inspect_tallying( vptr )
RESULTPTR       vptr;
{
	RESULTPTR       rptr;
	RESULTPTR       sptr;
	TCVARPTR        tcvptr;
	WORD            mode;
	WORD            label;
	WORD            fin;
	WORD            status;
	RESULTPTR       tally;
	RESULTPTR       section;
	RESULTPTR       debut;
	RESULTPTR       result; 
	RESULTPTR       xfer;
	RESULTPTR       taille;
	RESULTPTR       max;
	RESULTPTR       zptr;
	
	if ((!( get_token() ))
	||  ((rptr = resolve_vctrl( TokenBuffer )) == (RESULTPTR) 0))
		return( expected_variable() );
	else if (!( is_mnemonic("FOR") ))
		return( expected_keyword("FOR") );
	else if ((mode = inspect_options()) == MOINS_UN)
		return( syntax_error(1027) );
	else if ((mode > 1 )
	     &&  ((sptr = evaluate_expression(0)) == (RESULTPTR) 0))
		return( expected_variable() );
	else if ( mode == 1 )
		return( not_yet_available() );
	else    {
		if (((tally = ensure_register(rptr))    == (RESULTPTR) 0)
		||  ((zptr  = integer_result( 0 ))      == (RESULTPTR) 0)
		||  ((debut = integer_result(1))        == (RESULTPTR) 0)
		||  ((debut = ensure_register(debut))   == (RESULTPTR) 0))
			return( allocation_failure() );
		if ((tcvptr = (TCVARPTR) vptr->contents) == (TCVARPTR) 0)
			return( expected_variable() );
		else if ((max = integer_result( tcvptr->type->size )) == (RESULTPTR) 0)
			return( allocation_failure() );
		else if (((taille = integer_result( tcvptr->type->size )) == (RESULTPTR) 0)
		     ||  ((taille = ensure_register( taille )) == (RESULTPTR) 0))
			return( allocation_failure() );
		
		/* &DEBUT */
		/* ------ */
		if ( mode == 2 )
			(void) dcl_implicite_label((label = new_implicite_label()));
		if ((section = clf_substr(vptr,debut,taille)) == (RESULTPTR) 0)
			return( syntax_error(1027) );
/*              else if ((status = generate_pause( section )) != 0)     */
/*                      return(status);                                 */
		else if ((result = clf_index(section,sptr)) == (RESULTPTR) 0)
			return( syntax_error(1027) );
		else if ((status = evaluate_comparison(_CMP_EQ,result,zptr,_LOGICAL_USE,fin)) != 0 )
			return( status );
		else if ((tally = incrementation( tally )) == (RESULTPTR) 0)
			return( allocation_failure() );
		else if ( mode == 2 ) {
			if ((result = evaluate_operation('+',debut,result)) == (RESULTPTR) 0)
				return( syntax_error(1027) );
			else if (((xfer = evaluate_operation('-',max,result)) == (RESULTPTR) 0)
			     ||  ((xfer = incrementation( xfer )) == (RESULTPTR) 0))
				return( allocation_failure() );
			else if ((status = generate_copy_register( debut->value, result->value )) != 0)
				return( status );
			else if ((status = generate_copy_register( taille->value, xfer->value )) != 0)
				return( status );
			else if ((status = implicite_goto( label )) != 0)
				return( status );
			}

		/* &FIN */
		/* ---- */
		dcl_implicite_label(fin);

		if ((tcvptr = (TCVARPTR) rptr->contents) == (TCVARPTR) 0)
			return( expected_variable() );
		else    return( generate_affectation( tcvptr, tally,VRAI ) );

		}       
	return( not_yet_available() );
}

static WORD     inspect_converting( vptr )
RESULTPTR       vptr;
{
	return( not_yet_available() );
}


WORD    translate_inspect()
{
	RESULTPTR       vptr;
	WORD            status;
	if ((!( get_token() ))
	||  (( vptr = resolve_vctrl( TokenBuffer )) == (RESULTPTR) 0))
		return( expected_variable() );

	while ( 1 ) {
		if ( is_mnemonic("TALLYING") ) {
			if ((status = inspect_tallying(vptr)) != 0)
				return( status );
			}
		else if ( is_mnemonic( "REPLACING" ) ) {
			if ((status = inspect_replacing(vptr)) != 0)
				return( status );
			}
		else if ( is_mnemonic( "CONVERTING" ) ) {
			if ((status = inspect_converting(vptr)) != 0)
				return( status );
			}
		else    return( xverify_period() );
		}

}

WORD    translate_string()
{
	return( not_yet_available() );
}
WORD    translate_unstring()
{
	return( not_yet_available() );
}

WORD    translate_continue()
{
	if (!( iteration_type() ))
		return( syntax_error(1027) );
	generate_iteration();
	return( xverify_period() );
}

WORD    translate_set()
{
	WORD            mode;
	RESULTPTR       rptr;
	RESULTPTR       vptr;
	WORD            status;

	if ( is_mnemonic("ADDRESS") ) {
		if (!( is_mnemonic("OF") ))
			return( expected_keyword("OF") );
		if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
			return( syntax_error(1027) );
		mode = 1;
		}
	else    {
		mode = 0;
		if ((!( get_token() ))
		||  ((vptr = resolve_vctrl( TokenBuffer )) == (RESULTPTR) 0))
			return( expected_variable() );

		}

	if (!( is_mnemonic("TO") ))
		return( expected_keyword("TO") );

	if (!( mode )) {
		if ( is_mnemonic("ADDRESS") ) {
			if (!( is_mnemonic("OF") ))
				return( expected_keyword("OF") );
			if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
				return( syntax_error(1027) );
			}
		else if ( is_mnemonic("NULL") ) {
			if ((rptr = integer_result(0)) == (RESULTPTR) 0)
				return( syntax_error(1027) );
			}
		else    return( expected_keyword("ADDRESS") );
		}
	else    {
		if ((!( get_token() ))
		||  ((vptr = resolve_vctrl( TokenBuffer )) == (RESULTPTR) 0))
			return( expected_variable() );
		}

	if ((status =  clf_alias(vptr, rptr )) != 0)
		return( status );
	else    return( xverify_period() );
}


WORD            translate_function_exit( rptr, tptr )
RESULTPTR       rptr;
TCTYPPTR        tptr;
{
	WORD    status=0;

	if ((tptr->type & _TYPE_POINTER) != _TYPE_POINTER) {
		if ((( tptr->type & 3 ) > 1)
		&&  (( rptr = convert_to_type( rptr, (tptr->type & 3) )) == (RESULTPTR) 0))
			return( syntax_error(180) );
		if (( rptr = ensure_register( rptr )) == (RESULTPTR) 0)
			return( allocation_failure() );
		}
	else if ( is_method_function() ) {
		if (!(rptr->nature & _RESULT_POINTER )) {
			if ((rptr = clf_reg_alias( rptr )) == (RESULTPTR) 0)
				return( syntax_error(182) );
			}
		}

	if ((status = generate_copy_register( _EXIT_REGISTER, rptr->value )) != 0)
		return( status );
	else    return( generate_exit((RESULTPTR) 0) );
}

WORD    overlay_method_parameter( object, field )
TCVARPTR        object;
WORD            field;
{
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
}

WORD    translate_basic_statement()
{
	WORD            type;
	WORD            status;
	RESULTPTR       rptr;
	switch ((type = is_statement())) {
		case _STATEMENT_DISPLAY         :
			return( translate_display() );
		case _STATEMENT_ACCEPT          :
			return( translate_accept() );
		case _STATEMENT_ADD             :
			return( translate_add_statement() );
		case _STATEMENT_END_ADD         :
		case _STATEMENT_END_MULTIPLY    :
		case _STATEMENT_END_DIVIDE      :
		case _STATEMENT_END_SUBTRACT    :
			return( xverify_period() );
		case _STATEMENT_SUBTRACT        :
			return( translate_arithmetic_statement('-') );
		case _STATEMENT_MULTIPLY        :
			return( translate_arithmetic_statement('*') );
		case _STATEMENT_DIVIDE          :
			return( translate_arithmetic_statement('/') );
		case _STATEMENT_MOVE            :
			return( translate_move_statement() );
		case _STATEMENT_INITIALIZE      :
			return( translate_initialize() );
		case _STATEMENT_COMPUTE         :
			if ((status = translate_compute()) != 0)
				return( status );
		case _STATEMENT_END_COMPUTE     :
			return( xverify_period() );

		case _STATEMENT_INSPECT         :
			return( translate_inspect() );
		case _STATEMENT_STRING          :
			return( translate_string() );
		case _STATEMENT_UNSTRING        :
			return( translate_unstring() );

		case _STATEMENT_EVALUATE        :
			return( translate_evaluate() );
		case _STATEMENT_WHEN            :
			return( translate_when() );
		case _STATEMENT_END_EVALUATE    :
			return( translate_end_evaluate() );

		case _STATEMENT_CONTINUE        :
			return( translate_continue() );

		case _STATEMENT_STOP            :
			if ( is_mnemonic("RUN") ) {
				generate_stop();
				return( xverify_period() );
				}
			else if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
				return( syntax_error(1027) );
			else if ((status = generate_pause( rptr )) != 0)
				return( status );
			else    return( xverify_period() );

		case _STATEMENT_GO              :
			return( translate_goto() );
		case _STATEMENT_CALL            :
			return( translate_call() );
		case _STATEMENT_CHAIN           :
			return( translate_chain() );
		case _STATEMENT_CANCEL          :
			return( translate_cancel() );

		case _STATEMENT_PERFORM         :
			return( translate_perform() );
		case _STATEMENT_END_PERFORM     :
			return( translate_end_perform() );
		case _STATEMENT_ALTER           :
			return( translate_alter() );
		case _STATEMENT_SET             :
			return( translate_set() );
		case _STATEMENT_EXIT            :
			return( translate_exit(0) );
		case _STATEMENT_GOBACK          :
			return( translate_exit(1) );
		case _STATEMENT_ENTER           :
			return( translate_enter() );

		case _STATEMENT_IF              :
			return( translate_if() );
		case _STATEMENT_END_IF          :
			if ((status = translate_endif()) != 0)
				return(status );
			else    return( xverify_period() );

		case _STATEMENT_ELSE            :
			return( translate_else() );

		case _STATEMENT_SORT            :
		case _STATEMENT_SEARCH          :
		case _STATEMENT_MERGE           :
		case _STATEMENT_RETURN          :
		case _STATEMENT_RELEASE         :
		case _STATEMENT_END_SEARCH      :
			return( not_yet_available() );

		case MOINS_UN                   :
			switch ( is_procdiv_keyword() ) {
				case _PROCDIV_DECLARATIVES      :
					return( verify_period() );
				case    MOINS_UN                :
					return( translate_declaratives() );
				}
		}
	return( syntax_error(1027) );

}


WORD    translate_proc_div()
{
	WORD    status;
	trace("translate_proc_div()\n");
	if (!( get_token() ))
		return( translate_end() );
	if ((status = translate_basic_statement()) != MOINS_UN)
		return( status );
	else if ((status = translate_ngf_statement()) != MOINS_UN)
		return( status );
	else if ((status = translate_division()) != MOINS_UN)
		return( status );
	else    return( translate_procedure_label() );
}

WORD    ensure_division()
{
	if (!( get_token() ))
		return( expected_keyword("DIVISION") );
	else if ( is_division_keyword() != _DIVISION_DIVISION )
		return( expected_keyword("DIVISION") );
	else if (!( is_period() ))
		return( incorrect_punctuation() );
	else    return( 0 );
}

RESULTPTR       build_numeric_term( RESULTPTR, BPTR );

RESULTPTR       resolve_88_value( rptr )
RCTRLPTR        rptr;
{
	BPTR            vptr;
	RESULTPTR       tptr;
	if ((rptr == (RCTRLPTR) 0)
	||  (rptr->name == (BPTR) 0))
		return( (RESULTPTR) 0 );
	else    vptr = rptr->name;

	if ((tptr = allocate_for_result()) != (RESULTPTR) 0) {
		if ( *vptr == '"' )
			tptr = build_string_constant( tptr, vptr );
		else if (( *vptr == '/' ) || ( is_integer(vptr) )) {
			tptr->nature = _RESULT_INT;
			tptr->value  = convert_numeric_token( vptr );
			}
		else    tptr = build_numeric_term( tptr,vptr );
		}
	return( tptr );
}


RESULTPTR       resolve_88_thru( rptr, vptr )
RESULTPTR       rptr;
RCTRLPTR        vptr;
{
	RESULTPTR       xptr=(RESULTPTR) 0;
	RESULTPTR       lptr;
	RESULTPTR       hptr;
	WORD            labelfalse;
	WORD            labelexit;
	WORD            status;
	trace("resolve_88_thru()\n");
	if (((lptr = resolve_88_value( vptr ))       != (RESULTPTR) 0)
	&&  ((hptr = resolve_88_value( vptr->next )) != (RESULTPTR) 0)
	&&  ((rptr = ensure_register( rptr ))        != (RESULTPTR) 0)
	&&  ((xptr = integer_result(1))              != (RESULTPTR) 0)) {
		labelfalse = new_implicite_label();
		labelexit  = new_implicite_label();
		if (((status = evaluate_comparison(_CMP_LS,rptr,lptr,_LOGICAL_USE,labelfalse)) == 0 )
		&&  ((status = evaluate_comparison(_CMP_GR,rptr,hptr,_LOGICAL_USE,labelfalse)) == 0 )
		&&  ((xptr   = ensure_register( xptr )) != (RESULTPTR) 0)
		&&  ((status = implicite_goto( labelexit )) == 0)) {
			(void) dcl_implicite_label( labelfalse );
			explicite_ldi( xptr->value, 0 );
			(void) dcl_implicite_label( labelexit );
			return( xptr );
			}
		}       
	return((RESULTPTR) 0);
}

RESULTPTR       resolve_88_list( rptr, vptr )
RESULTPTR       rptr;
RCTRLPTR        vptr;
{
	RESULTPTR       xptr;
	RESULTPTR       tptr;
	WORD            status;
	WORD            labeltrue;
	WORD            labelfalse;
	WORD            labelexit;
	trace("resolve_88_list()\n");
	if  (((xptr = integer_result(0))        == (RESULTPTR) 0)
	||   ((rptr = ensure_register(rptr))    == (RESULTPTR) 0))
		return((RESULTPTR) 0);
	labeltrue  = new_implicite_label();
	labelexit  = new_implicite_label();
	while ( vptr != (RCTRLPTR) 0 ) {
		if ((tptr = resolve_88_value( vptr )) == (RESULTPTR) 0)
			return( tptr );
		else if ((status = evaluate_comparison(_CMP_EQ,rptr,tptr,_LOGICAL_USE,labeltrue)) != 0 )
			return((RESULTPTR) 0);
		else    vptr = vptr->next;
		}
	if (((xptr   = ensure_register(xptr)) != (RESULTPTR) 0)
	&&  ((status = implicite_goto(labelexit)) == 0)) {
		(void) dcl_implicite_label( labeltrue );
		explicite_ldi( xptr->value, 1 );
		(void) dcl_implicite_label( labelexit );
		return( xptr );
		}
	else    return((RESULTPTR) 0);
}


RESULTPTR       resolve_level_88( vptr )
VCTRLPTR        vptr;
{
	VCTRLPTR        dptr;
	RESULTPTR       rptr;
	trace("resolve_level_88()\n");
	if ((dptr = vptr) != (VCTRLPTR) 0) {
		while ( dptr->level == 88 )
			dptr = dptr->previous;
		if ((rptr = variable_result( dptr->contents )) != (RESULTPTR) 0) {
			if ( vptr->type == 0x00FF )
				return( resolve_88_thru( rptr, vptr->record ) );
			else if ( vptr->type == 0x00FE )
				return( resolve_88_list( rptr, vptr->record ) );
			else    (void) syntax_error(1027);
			}
		else    (void)  allocation_failure();
		}
	else    (void) syntax_error(1027);
	return((RESULTPTR) 0);
}

RESULTPTR       cobol_symbolic_term()
{
	VCTRLPTR        vptr;
	trace("cobol_symbolic_term()\n");
	if (((vptr = locate_vctrl( TokenBuffer )) == (VCTRLPTR) 0)
	||  (vptr->level != 88))
		return( symbolic_term() );
	else    return( resolve_level_88( vptr ) );
}

WORD     enter_identification_division()
{
	WORD            status;
	COBOLPTR        cbptr;
	WORD            options=0;
	if ((status = ensure_division()) != 0)
		return( status );
	if  (Cobol != (COBOLPTR) 0) {
		if (Cobol->CurrentDivision != _PROC_DIV)
			return( syntax_error(1027) );
		else if ((status = terminate_proc_div()) != 0) {
			(void) internal_error(77);
			return( status );
			}
		}
	else    {
		if ( OtrOption.LocalConstant )
			OtrOption.LocalConstant = FAUX;
		else    OtrOption.LocalConstant = VRAI;
		Context->symbolic_term = cobol_symbolic_term;
		Context->LanguageCode   = 0x0001;       /* COBOL  */
		Context->DebugNature    = 0x0000;       /* Offset */
		}

	if ((cbptr = allocate_for_cobol()) == (COBOLPTR) 0)
		return( allocation_failure() );
	else    {
		if ( Cobol != (COBOLPTR) 0 ) {
			cbptr->version = Cobol->version;
			cbptr->comma   = Cobol->comma;
			}
		cbptr->Next = Cobol;
		Cobol       = cbptr;
		}

	if ( is_mnemonic("ANS74") )
		options |= _COBOL_ANS74;
	if ( is_mnemonic("ANS85") )
		options |= _COBOL_ANS85;
	if ( is_mnemonic("ANS91") )
		options |= _COBOL_ANS91;
	if ( is_mnemonic("ANS95") )
		options |= _COBOL_ANS95;
		
	Cobol->CurrentDivision = _ID_DIV;
	push_operation_pointer();
	set_operation_pointer(translate_id_div);
	if ( options ) {
		Cobol->version |= options;
		return( verify_period() );
		}
	else    return( 0 );
}

WORD     enter_environment_division()
{
	WORD    status;
	if ((status = ensure_division()) != 0)
		return( status );
	if  ( Cobol == (COBOLPTR) 0 )
		return( internal_error() );
	if ((Cobol->Next == (COBOLPTR) 0)
	&&  ( Cobol->CurrentDivision != _ID_DIV ))
		return( syntax_error(1027) );
	Cobol->CurrentDivision = _ENV_DIV;
	push_operation_pointer();
	set_operation_pointer(translate_env_div);
	return( 0 );
}

WORD     enter_data_division()
{
	WORD    status;
	if ((status = ensure_division()) != 0)
		return( status );
	if ( Cobol == (COBOLPTR) 0 )
		return( internal_error() );
	if ((Cobol->Next == (COBOLPTR) 0)
	&&  ( Cobol->CurrentDivision != _ENV_DIV ))
		return( syntax_error(1027) );
	Cobol->CurrentDivision = _DATA_DIV;
	push_operation_pointer();
	set_operation_pointer(translate_data_div);
	return( 0 );
}

WORD    cobol_affectation( nptr, vptr )
BPTR    nptr;
BPTR    vptr;
{
	WORD    status;
	sprintf(CobolToAbal,"MOVE %s TO %s . \n",vptr,nptr);
	return( line_translation( CobolToAbal ) );
	return( status );
}

WORD    initialise_data_division()
{
	WORD            status;
	VCTRLPTR        vptr;
	if ((vptr = Cobol->VctrlHeap) != (VCTRLPTR) 0) {
		do      {
			if (( vptr->value != (BPTR) 0 )
			&&  ( vptr->name  != (BPTR) 0 )
			&&  ((status = cobol_affectation( vptr->name, vptr->value )) != 0))
				return( status );
			}
		while ((vptr = vptr->next) != (VCTRLPTR) 0);
		}
	return(0);
}

WORD    translate_initialize()
{
	WORD            status;
	WORD            mode=0;
	BPTR            iptr;
	VCTRLPTR        vptr;

	if (!( get_token() ))
		return( expected_variable() );

	while ( 1 ) {

		if ((vptr = locate_vctrl( TokenBuffer )) == (VCTRLPTR) 0)
			return( expected_variable() );

		if (!( is_mnemonic("REPLACING") )) {
			if ((iptr = vptr->value) == (BPTR) 0) {
				if ((vptr->type & 3 ) > 2)
					iptr = (BPTR) "0";
				else    iptr = (BPTR) "SPACE";
				}
			if ((status = cobol_affectation(vptr->name,vptr->value)) != 0)
				return( status );
			}
		else    {
			if (( is_mnemonic("ALPHABETIC"))
			||  ( is_mnemonic("ALPHANUMERIC"))
			||  ( is_mnemonic("ALPHANUMERIC-EDITED")))
				mode = 1;
			else if (( is_mnemonic("NUMERIC"))
			     ||  ( is_mnemonic("NUMERIC-EDITED")))
				mode = 2;
			else    return( syntax_error(1027) );

			(void) is_mnemonic("DATA");

			if (!( is_mnemonic("BY") ))
				return( expected_keyword("BY") );

			if (!( get_token() ))
				return( expected_variable() );
			else if ((status = cobol_affectation(vptr->name,TokenBuffer)) != 0)
				return( status );

			}

		(void) is_comma();
		if (!( get_token() ))   
			return( xverify_period() );

		}

}


VCTRLPTR        declare_data_item( vptr,scope )
VCTRLPTR        vptr;
WORD            scope;
{
	WORD            status;
	VCTRLPTR        xptr;
	VCTRLPTR        parent=(VCTRLPTR) 0;

	while (1) {

		/* Check for end of list */
		/* --------------------- */
		if ( vptr == (VCTRLPTR) 0 )
			break;
		else if ( vptr->level == 88 ) {
			vptr = vptr->next;
			continue;
			}
		if (( vptr->level == 77 ) || ( vptr->level == 1 ))
			field_equals_m();

		/* Check for Level Return required */
		/* ------------------------------- */
		if ((parent != (VCTRLPTR) 0)
		&&  ((vptr->level < parent->level)
		  || (vptr->level == 77)))
			return( vptr );

		/* Ensure Correct Scope */
		/* -------------------- */
		if (!(vptr->scope & scope)) {
			parent = (VCTRLPTR) 0;
			vptr = vptr->next;
			continue;
			}

		/* Check for Explicite Redefinition */
		/* -------------------------------- */
		if ((xptr = vptr->redefines) != (VCTRLPTR) 0 ) {
			vptr->size      = xptr->size;
			vptr->type      = xptr->type;
			vptr->first     = xptr->first;
			vptr->second    = xptr->second;
			vptr->picture   = xptr->picture;
			strcpy(TokenBuffer,xptr->name);
			if ((status = redefine_variable()) != 0)
				return( (VCTRLPTR) 0 );
			}

		/* Check for Implicite Redefinition */
		/* -------------------------------- */
		else if ((parent != (VCTRLPTR) 0)
		     &&  (vptr->level != 77 )
		     &&  (parent->level < vptr->level )) {

			/* FIELD=M,PARENT */
			/* -------------- */
			if ( OtrOption.Verbose )
				sysprintf("FIELD=M,%s\n",parent->name);
			strcpy(TokenBuffer,parent->name);
			if ((status = redefine_variable()) != 0)
				return( (VCTRLPTR) 0 );
			else    vptr = declare_data_item( vptr,_LOCAL_SCOPE );

			/* FIELD=M,PARENT */
			/* -------------- */
			if ( OtrOption.Verbose )
				sysprintf("FIELD=M,%s\n",parent->name);
			strcpy(TokenBuffer,parent->name);
			if ((status = redefine_variable()) != 0)
				return( (VCTRLPTR) 0 );

			if ( OtrOption.Verbose )
				sysprintf("DCL FILLER=%u\n",parent->size);

			/* DCL FILLER LEN(PARENT) */
			/* ---------------------- */
			if ((status = dcl_filler( parent->size )) != 0 )
				return( (VCTRLPTR) 0 );
			if ( vptr == (VCTRLPTR) 0 )
				break;
			else    continue;
			}

		/* Check for Explicite Filler Item */
		/* ------------------------------- */
		if ( vptr->name == (BPTR) 0 ) {
			if ( OtrOption.Verbose )
				sysprintf("DCL FILLER=%u\n",vptr->size);
			if ((status = dcl_filler( vptr->size )) != 0 )
				return( (VCTRLPTR) 0 );
			}
		else    {
			/* Declare Variable */
			/* ---------------- */
			if ( OtrOption.Verbose )
				sysprintf("DCL %s \n",vptr->name);
			if ((status = add_variable( vptr->name, vptr->type, vptr->size, vptr->first, vptr->second,vptr->nature,0,  0 )) != 0) {
				(void) allocation_failure();
				return( (VCTRLPTR) 0 );
				}
			else if ( scope & _GLOBAL_SCOPE )
				vptr->contents = Context->GDT->variable;
			else if ( scope & _LOCAL_SCOPE  )
				vptr->contents = Context->LDT->variable;

			}
		parent = vptr;
		vptr = vptr->next;
		}
	return( vptr );
}

WORD    declare_data_division(scope)
WORD    scope;
{
	VCTRLPTR        vptr;
	if ((vptr = Cobol->VctrlHeap) != (VCTRLPTR) 0)
		while ((vptr = declare_data_item( vptr, scope)) != (VCTRLPTR) 0);
	return(0);
}

WORD    establish_national_language()
{
	if ( Cobol->comma == ',' )
		return(clf_lang(0));
	else    return(clf_lang(1));
}

WORD    cobol_startup_code()
{
	WORD            status;
	WORD            segnumber=MOINS_UN;
	BPTR            segname=(BPTR) 0;
	WORD            segopt=3;
	TCVARPTR        control;
	RESULTPTR       lptr;
	RESULTPTR       rptr;
	WORD            label;

	/* Detect Embeded Program or Program with Linkage */
	/* ---------------------------------------------- */
	if (( Cobol->Next != (COBOLPTR) 0) 
	||  ( context_is_module )) {
		if ((segname   = Cobol->CurrentProgram) == (BPTR) 0)
			return( syntax_error(1027) );
		}
	else    segnumber = 0;
	if ( Cobol->options & 2 )
		segopt = 0;
	if ((status = declare_data_division((_GLOBAL_SCOPE | _EXTERNAL_SCOPE))) != 0)
		return( status );
	if ((status = add_segment( segnumber, segopt, segname,VRAI)) != 0 )
		return( status );
	set_local_scope();
	if ((status = declare_data_division(_LOCAL_SCOPE)) != 0)
		return( status );
#ifndef  _JAVA_COBOL_TR 
	inhibit_source_newline();
	if ( segopt ) {
		if ((status = add_variable( "$0$0", 1, 2, 1, 1, 0, 0,0 )) != 0)
			return( status );
		control = Context->LDT->variable;
		if ((status = add_variable( "$E$E", 1, 2, 1, 1, 0, 0,0 )) != 0)
			return( status );
		Cobol->ErrorVariable = Context->LDT->variable;
		if (((lptr = variable_result( control )) == (RESULTPTR) 0)
		||  ((rptr = clf_conf(25)) == (RESULTPTR) 0)
		||  ((rptr = incrementation( rptr )) == (RESULTPTR) 0))
			return( allocation_failure() );
		label = new_implicite_label();
		if ((status = evaluate_comparison(_CMP_EQ,lptr,rptr,_LOGICAL_USE,label)) != 0 )
			return( status );
		if ((status = generate_affectation( control, rptr,VRAI )) != 0)
			return( status );
		}
	(void) initialise_for_perform();
	(void) establish_national_language();
	(void) initialise_data_division();
	(void) generate_fctrl_startup();
	if ( segopt )
		(void) dcl_implicite_label(label);
	allow_source_newline();
#else
	(void) initialise_for_perform();
#endif
	return( status );
}

WORD     enter_procedure_division()
{
	WORD    status;
	if ((status = ensure_division()) != 0)
		return( status );
	if ( Cobol == (COBOLPTR) 0 )
		return( internal_error() );
	if ((Cobol->Next == (COBOLPTR) 0)
	&&  ( Cobol->CurrentDivision != _DATA_DIV ))
		return( syntax_error(1027) );
	Cobol->CurrentDivision = _PROC_DIV;
	push_operation_pointer();
	set_operation_pointer(translate_proc_div);
	return( cobol_startup_code() );
}

WORD    translate_division()
{
	WORD    type;
	switch ((type = is_division_keyword())) {
		case _IDENTIFICATION_DIVISION   :
			return( enter_identification_division() );
		case _ENVIRONMENT_DIVISION      :
			return( enter_environment_division() );
		case _DATA_DIVISION             :
			return( enter_data_division() );
		case _PROCEDURE_DIVISION        :
			return( enter_procedure_division() );
		case _END_DIVISION              :
			return( translate_end_program() );
		}
	return( MOINS_UN );
}

WORD    enter_division()
{
	WORD    status;
	if ((status = translate_division()) != MOINS_UN)
		return( status );
	else    return( syntax_error(1027) );
}

WORD    translator_startup()
{
	WORD    type;
	if ( get_token() )
		return( enter_division() );
	return(syntax_error(1027));
}


/*      -------------------------------------------     */
/*      PUBLIC REGION   :       INTERFACE FUNCTIONS     */
/*      -------------------------------------------     */

WORD    terminate_translation( abandon )
WORD    abandon;
{
	trace("terminate_translation()\n");
	if (( Context != (TCFDTPTR) 0 )
	&&  ( Context->Started        )
	&&  ( Cobol   != (COBOLPTR) 0 ))
		translate_end();

	while ( Cobol != (COBOLPTR) 0 )
		Cobol = liberate_for_cobol();
	liberate_screens();

	terminate_tcode_context();

	return( abandon );
}

WORD    translate_soft_event()
{
	WORD    type;
	WORD    status;
	trace("translate_soft_event()\n");
	if ((status = enter_iteration( _ITERATION_EVENT,(TCVARPTR) 0  )) != 0)
		return( status );
	else if ((status = generate_event()) != 0)
		return( status );
	else if ((status = goto_operation_label()) != 0)
		return( status );
	else if ((status = dcl_iteration_label()) == 0)
		return( syntax_error(194) );
	else if ((status = conditional_expression(1)) != 0 )
		return( status );
	else    return( 0 );
}

WORD    translate_copy()
{
	if (!( get_filename() ))
		return( syntax_error(1027) );
	else    return( include_source_file(TokenBuffer,OtrOption.Extension) );
}

WORD    line_translation( line_buffer )
BPTR    line_buffer;
{
	WORD    status=0;
	if (initialise_line_parser( line_buffer )) {

		if (is_mnemonic( "COPY" ))
			return( translate_copy() );
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

VOID    echo_source_line( lptr )
BPTR    lptr;
{
	sysprintf("CTR: ");
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
#define ENV_FIELD ';'
#else
BPTR    getenv(BPTR);
#define ENV_FIELD ':'
#endif

VOID    default_language_options()
{
	BPTR    eptr;
	BPTR    fptr;
	WORD    term;
	OtrOption.UpperCase = VRAI;
	OtrOption.TokenSize = 48;
#ifndef PROLOGUE
	OtrOption.Optimise = FAUX;
	if ((eptr = getenv("CTRDEF")) != (BPTR) 0) {
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
#endif
	return;
}

WORD    enter_global_translation()
{
	set_global_scope();
	return(0);
}

WORD    leave_global_translation()
{
	return(0);
}
WORD    translate_level_one()
{
	return( MOINS_UN );
}

WORD    translate_terminal_member( vptr )
TCVARPTR        vptr;
{
	return( syntax_error(1027) );
}

WORD    translate_break()
{
	return( break_from_iteration() );
}


#endif  /* _TRANSLATE_C */
	/* ------------ */

