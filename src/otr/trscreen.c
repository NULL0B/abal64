#define DEBUG
/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRSCREEN.C				*/
/*		Version :	2.1d					*/
/*		Date	:	09/02/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRSCREEN_C
#define	_TRSCREEN_C

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
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
#include "trvctrl.h"
#include "trpctrl.h"
#include "trcobol.h"
#include "trscreen.h"

SCREENPTR	allocate_for_screen( nptr )
BPTR		nptr;
{
	SCREENPTR	sptr;
	if ((sptr = (SCREENPTR) allocate( sizeof( struct cobol_screen ) )) != (SCREENPTR) 0) {
		if ((sptr->name = allocate_for_string( nptr )) != (BPTR) 0) {
			sptr->contents = (SCREENITEM) 0;
			sptr->next = ScreenHeap;
			return((ScreenHeap = sptr));
			}
		liberate( sptr );
		}
	return( (SCREENPTR) 0 );
}

SCREENITEM	allocate_screen_item()
{
	SCREENITEM	iptr;
	if ((iptr = (SCREENITEM) allocate( sizeof( struct cobol_screen_item ) )) != (SCREENITEM) 0 ) {
		iptr->special	= MOINS_UN;
		iptr->tabv	= MOINS_UN;
		iptr->cno  	= MOINS_UN;
		iptr->lno  	= MOINS_UN;
		iptr->atb  	= MOINS_UN;
		iptr->fore 	= MOINS_UN;
		iptr->back 	= MOINS_UN;
		iptr->picture	= (BPTR) 0;
		iptr->value   	= (BPTR) 0;
		iptr->mask	= MOINS_UN;
		iptr->variable  = (VCTRLPTR) 0;
		iptr->next	= (SCREENITEM) 0;
		}
	return( iptr );
}

VOID	liberate_screen_item( iptr )
SCREENITEM	iptr;
{
	if ( iptr->picture != (BPTR) 0 )
		liberate( iptr->picture );
	if ( iptr->value != (BPTR) 0 )
		liberate( iptr->value );
	liberate( iptr );
	return;
}

VOID	liberate_screens()
{
	SCREENPTR	sptr;
	SCREENITEM	iptr;

	while ((sptr = ScreenHeap) != (SCREENPTR) 0) {
		ScreenHeap = sptr->next;
		while ((iptr = sptr->contents) != (SCREENITEM) 0) {
			sptr->contents = iptr->next;
			liberate_screen_item( iptr );
			}
		if ( sptr->name != (BPTR) 0 )
			liberate( sptr->name );
		liberate( sptr );
		}
	return;
}


WORD	is_screen_keyword()
{
	WORD	i;

	for ( i = 0; i < _SCREEN_KEYWORD_MAX; i++ )
		if ( compare_tokens( TokenBuffer , screen_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

SCREENITEM	translate_screen_syntax( mode )
WORD		mode;
{
	SCREENITEM	iptr=(SCREENITEM) 0;
	WORD		status;
	WORD		nombre=0;
	WORD		type;
	if ((iptr = allocate_screen_item()) == (SCREENITEM) 0)
		(void) allocation_failure();
	else	{
		while ( get_token() ) {
			nombre++;
			switch (( type = is_screen_keyword())) {
				case	_SCREEN_FORECOLOR 	:
				case	_SCREEN_FORECOLOUR 	:
					if ( iptr->fore != MOINS_UN ) {
						(void) syntax_error(1026);
						liberate_screen_item( iptr );
						return((SCREENITEM) 0);
						}
					iptr->fore = collect_integer();
					continue;

				case	_SCREEN_BACKCOLOR 	:
				case	_SCREEN_BACKCOLOUR	:
					if ( iptr->back != MOINS_UN ){
						(void) syntax_error(1026);
						liberate_screen_item( iptr );
						return((SCREENITEM) 0);
						}
					iptr->back = collect_integer();
					continue;

				case	_SCREEN_LINE		:
					if ( iptr->lno != MOINS_UN ){
						(void) syntax_error(1026);
						liberate_screen_item( iptr );
						return((SCREENITEM) 0);
						}
					if (( is_mnemonic( "PLUS" ) )
					||  ( is_plus() ))
						iptr->tabv = collect_integer();
					else	iptr->lno = collect_integer();
					continue;

				case	_SCREEN_COLUMN		:
				case	_SCREEN_COL   		:
					if ( iptr->cno != MOINS_UN ){
						(void) syntax_error(1026);
						liberate_screen_item( iptr );
						return((SCREENITEM) 0);
						}
					iptr->cno = collect_integer();
					break;

				case	_SCREEN_VALUE		:
					if (collect_cobol_value() == 0){
						(void) syntax_error(1026);
						liberate_screen_item( iptr );
						return((SCREENITEM) 0);
						}
					else if ((iptr->value = allocate_for_string( CobolToAbal )) == (BPTR) 0){
						(void) allocation_failure();
						liberate_screen_item( iptr );
						return((SCREENITEM) 0);
						}
					else	break;

				case	_SCREEN_REVERSE_VIDEO 	:
					iptr->atb = 2;
					break;

				case	_SCREEN_ERASE		:
					if ( is_mnemonic("EOL" )) {
						if ( iptr->atb != MOINS_UN ){
							(void) syntax_error(1026);
							liberate_screen_item( iptr );
							return((SCREENITEM) 0);
							}
						iptr->atb = 21;
						break;
						}
					else if ( is_mnemonic("EOP") ) {
						if ( iptr->atb != MOINS_UN ){
							(void) syntax_error(1026);
							liberate_screen_item( iptr );
							return((SCREENITEM) 0);
							}
						iptr->atb = 22;
						break;
						}
					else	{
						(void) syntax_error(1026);
						liberate_screen_item( iptr );
						return((SCREENITEM) 0);
 						}

				case	_SCREEN_BLANK		:
					if (!( get_token() )){
						(void) syntax_error(1026);
						liberate_screen_item( iptr );
						return((SCREENITEM) 0);
						}
					switch ( is_screen_keyword() ) {
						case	_SCREEN_LINE	:
							if ( iptr->atb != MOINS_UN ){
								(void) syntax_error(1026);
								liberate_screen_item( iptr );
								return((SCREENITEM) 0);
								}
							iptr->atb = 21;
							break;
						case	_SCREEN_SCREEN	:
							if ( iptr->special == MOINS_UN )
								iptr->special = 2;
							else	iptr->special |= 2;
							break;
						default			:
							(void) syntax_error(1026);
							liberate_screen_item( iptr );
							return((SCREENITEM) 0);
						}
					break;
				case	_SCREEN_USING		:
					if (!( get_token() )){
						(void) syntax_error(1026);
						liberate_screen_item( iptr );
						return((SCREENITEM) 0);
						}
					else if ((iptr->variable = locate_vctrl( TokenBuffer )) == (VCTRLPTR) 0){
						(void) syntax_error(1026);
						liberate_screen_item( iptr );
						return((SCREENITEM) 0);
						}
					else	break;
				case	_SCREEN_PIC		:
				case	_SCREEN_PICTURE		:
					if ((status = translate_picture( (VCTRLPTR) 0 )) != 0){
						(void) syntax_error(1026);
						liberate_screen_item( iptr );
						return((SCREENITEM) 0);
						}
					else if ((iptr->picture = allocate_for_string(TokenBuffer)) == (BPTR) 0){
						(void) syntax_error(1026);
						liberate_screen_item( iptr );
						return((SCREENITEM) 0);
						}
					else	break;
				case	_SCREEN_BELL		:
				case	_SCREEN_BEEP		:
					if ( iptr->special == MOINS_UN )
						iptr->special = 1;
					else	iptr->special |= 1;
					break;

				case	_SCREEN_BLINK		:
					iptr->atb = 3;
					break;

				case	_SCREEN_HIGHLIGHT	:
					iptr->atb = 1;
					break;

				case	_SCREEN_LOWLIGHT	:
					iptr->atb = 4;
					break;

				case	_SCREEN_GRID		:
				case	_SCREEN_LEFTLINE	:
					break;
				case	_SCREEN_OVERLINE	:
				case	_SCREEN_UNDERLINE	:
					iptr->atb = 5;
					break;

				case	_SCREEN_SIZE		:
				case	_SCREEN_AUTOSKIP	:
				case	_SCREEN_AUTO		:
					if ( iptr->mask == MOINS_UN )
						iptr->mask = 0;
					iptr->mask |= 8;
					break;
				case	_SCREEN_SECURE		:
				case	_SCREEN_REQUIRED	:
				case	_SCREEN_FULL		:
				case	_SCREEN_CONTROL		:
					break;
				default				:
					nombre--;
					if ( mode ) {
						liberate_screen_item( iptr );
 						(void) syntax_error(1026);
						return((SCREENITEM) 0);
						}
					else	{
						unget_token();
						if ( nombre == 0 ) {
							liberate_screen_item( iptr );
							return((SCREENITEM) 0);
							}
						else	return( iptr );
						}
				}
			}
		if ( nombre == 0 ) {
			liberate_screen_item( iptr );
			return( (SCREENITEM) 0 );
			}
		}
	return( iptr );
}

WORD	translate_screen_item()
{
	WORD		status;
	WORD		level=0;
	SCREENPTR	sptr=(SCREENPTR) 0;
	SCREENITEM	iptr=(SCREENITEM) 0;
	SCREENITEM	zptr=(SCREENITEM) 0;

	if ((level = collect_integer()) == 1) {
		if (!( get_token() ))
			return( syntax_error(1026) );
		else if ((sptr = allocate_for_screen( TokenBuffer )) == (SCREENPTR) 0)
			return( allocation_failure() );
		}
	else	{
		if ((sptr = ScreenHeap) == (SCREENPTR) 0)
			return( syntax_error(1026) );
		if ((iptr = translate_screen_syntax(1)) == (SCREENITEM) 0)
			return( syntax_error(1026) );

		if ((zptr = sptr->contents) == (SCREENITEM) 0 )
			sptr->contents = iptr;
		else	{
			while ( zptr->next != (SCREENITEM) 0 )
				zptr = zptr->next;
			zptr->next = iptr;
			}

		}
	return( verify_period() );
}


WORD	translate_data_screen()
{
	if ( is_numeric() )
		return( translate_screen_item() );
	else if ( get_token() )
		return( enter_data_section() );
	else	return( syntax_error(1026) );
}

WORD	enter_data_screen()
{
	WORD	status;
	trace("enter_data_screen()\n");
	if (!( Cobol->version & _COBOL_ANS85SS ))
		return( syntax_error(1026) );
	else if ((status = is_section()) != 0)
		return( status );
	push_operation_pointer();
	set_operation_pointer( translate_data_screen );
	return( 0 );
}

WORD		generate_screen_item( iptr, mode )
SCREENITEM	iptr;
WORD		mode;
{
	WORD		status;
	RESULTPTR	rptr;
	BPTR		vptr;
	if (( mode ) && ( iptr->mask != MOINS_UN ))
		clf_mask( (iptr->mask | 3) );
	if ( iptr->special != MOINS_UN ) {
		if (( iptr->special & 1 )
		&&  ((status = translate_iof_bell()) != 0))
			return( status );
		if (( iptr->special & 2 )
		&&  ((status = translate_iof_clear()) != 0))
			return( status );
		}
	if ( iptr->tabv != MOINS_UN )
		if ((status = store_iof_tabv( integer_result(iptr->tabv) )) != 0)
			return( status );
	if ( iptr->cno != MOINS_UN ) {
		if (( iptr->lno != MOINS_UN )
		&&  ((status = store_iof_tabl( integer_result( iptr->lno ) )) != 0))
			return( status );
		if ((status = store_iof_tabc( integer_result( iptr->cno ) )) != 0)
			return( status );
		}

	if (( iptr->fore != MOINS_UN )
	&&  ((status = store_iof_foreground( integer_result( iptr->fore ) )) != 0))
		return( status );

	if (( iptr->back != MOINS_UN )
	&&  ((status = store_iof_background( integer_result( iptr->back ) )) != 0))
		return( status );

	if (( iptr->atb != MOINS_UN )
	&&  ((status = store_iof_atb( integer_result( iptr->atb ) )) != 0))
		return( status );

	if (( iptr->picture != (BPTR) 0 )
	&&  ((status = store_iof_fmt( iptr->picture )) != 0))
		return( status );

	if ((vptr = iptr->value) != (BPTR) 0 ) {
		if (( iptr->picture == (BPTR) 0 )
		&&  (( status = store_iof_fmt( "E" )) != 0))
			return( status );
		if ( *vptr == '"' ) {
			if ((rptr = allocate_for_result()) == (RESULTPTR) 0)
				return( allocation_failure() );
			else if ((rptr = build_string_constant( rptr, vptr )) == (RESULTPTR) 0)
				return( syntax_error(1026) );
			else if ((status = store_iof_prn( rptr )) != 0 )
				return( status );
			}
		else if ((status = store_iof_prn( integer_result( convert_numeric_token( vptr ) ) )) != 0)
			return( status );
		}
	else if ( iptr->variable != (VCTRLPTR) 0 ) {
		if (( iptr->picture == (BPTR) 0 )
		&&  ( iptr->variable->picture != (BPTR) 0 ))
			if ((status = store_iof_fmt( iptr->variable->picture )) != 0)
				return( status );
		if ((status = store_iof_prn( variable_result( iptr->variable->contents ) )) != 0)
			return( status );
		}

	if (( iptr->atb != MOINS_UN )
	&&  ((status = store_iof_atb( integer_result( 0 ) )) != 0))
		return( status );
	return( 0 );
}

SCREENPTR	is_screen_expression( nptr )
BPTR		nptr;
{
	SCREENPTR	sptr;
	if ((sptr = ScreenHeap) != (SCREENPTR) 0) {
		do	{
			if ((nptr != (BPTR) 0)
			&&  (sptr->name != (BPTR) 0)
			&&  (compare_tokens(nptr,sptr->name)))
				break;
			}
		while ((sptr = sptr->next) != (SCREENPTR) 0);
		}
	return( sptr );
}

/*
 *	S C R E E N _ E X P R E S S I O N ()
 *	------------------------------------
 *
 *	Called during the "translate_display()" operation cycle to
 *	detect screen expressions.
 *	
 *	Returns MOINS_UN to indicate not screen expression
 *		FAUX     to indicate no error on screen expression.
 *	    other values indicate errors during screen expression.
 *
 *	When a screen expression is detected by this function
 *	it will be generated to the current IOF context which
 *	must have been initiated by the calling function.
 *
 */

WORD	screen_expression(mode)
WORD	mode;		/* DISPLAY : 0, ACCEPT : 1	*/
{
	WORD		status;
	SCREENPTR	sptr=(SCREENPTR) 0;
	SCREENITEM	iptr=(SCREENITEM) 0;

	if (!( console_is_crt() ))
		return( MOINS_UN );

	if (!( get_token() ))
		return( MOINS_UN );
	else if ((sptr = is_screen_expression( TokenBuffer )) == (SCREENPTR) 0) {
		unget_token();
		if ((iptr = translate_screen_syntax(0)) != (SCREENITEM) 0) {
			status = generate_screen_item( iptr, mode );
			liberate_screen_item( iptr );
			return( status );
			}
		else	return( MOINS_UN );
		}
	if ((iptr = sptr->contents) != (SCREENITEM) 0) {
		do	{
			if ((status = generate_screen_item( iptr, mode )) != 0)
				return( status );
			}
		while ((iptr = iptr->next) != (SCREENITEM) 0);
		}
	return( 0 );
	
}


/* DISPLAY */


WORD	accept_display_format(comma)
WORD	comma;
{
	VCTRLPTR	vptr;
	if (((vptr = locate_vctrl( TokenBuffer )) != (VCTRLPTR) 0) 
	&&  (vptr->picture != (BPTR) 0)) {
		if ( comma )
			strcat(CobolToAbal,",");
		strcat(CobolToAbal,"(");
		strcat(CobolToAbal,vptr->picture);
		strcat(CobolToAbal,")");
		return(1);
		}
	else	{
		if ( comma )
			strcat(CobolToAbal,",");
		strcat(CobolToAbal,"(E)");
		return(0);
		}
}

WORD	translate_display_tabulation()
{
	WORD		status;
	RESULTPTR	lptr;
	RESULTPTR	cptr;
	if ((lptr = evaluate_expression(0)) == (RESULTPTR) 0)
		return( expected_variable() );
	(void) is_comma();
	if ((cptr = evaluate_expression(0)) == (RESULTPTR) 0)
		return( expected_variable() );
	if ( Cobol->version & _COBOL_ANS74 ) {
		if ((status = store_iof_tabl( lptr )) != 0 )
			return( status );
		if ((status = store_iof_tabc( cptr )) != 0 )
			return( status );
		}
	else	{
		if ((status = store_iof_tabl( cptr )) != 0 )
			return( status );
		if ((status = store_iof_tabc( lptr )) != 0 )
			return( status );
		}
	if ( is_right_brace() )
		return( 0 );
	else	return( unmatched_braces() );
}

WORD	translate_crt_display()
{
	TCVARPTR	tcvptr;
	VCTRLPTR	vptr;
	RESULTPTR	device=(RESULTPTR) 0;
	RESULTPTR	operand;
	WORD		status=0;
	WORD		tabulate=1;

	if  ((status = start_iof()) != 0)
		return( status );

	while ( 1 ) {
		(void) is_mnemonic("WITH");
		if ( is_mnemonic("NO") ) {
			if ( is_mnemonic("ADVANCING" ) )
				tabulate=0;
			else	return( expected_keyword("ADVANCING") );
			}
		else if ( is_mnemonic("UPON") ) {
			if ((device = evaluate_expression(0)) == (RESULTPTR) 0)
				return( expected_variable() );
			}
		else if ( is_mnemonic( "SPACE" ) ) {
			if ((status = translate_iof_clear()) != 0)
				return( status );
			}
		else if ( is_mnemonic( "ERASE" ) ) {
			if ((status = store_iof_atb( integer_result(21) )) != 0)
				return( status );
			}
		else if (!( screen_expression(0) )) {
			if ( is_left_brace() ) {
				if ((status = translate_display_tabulation()) != 0)
					return( status );
					}
			if ( is_mnemonic( "ERASE" ) ) {
				if ((status = store_iof_atb( integer_result(21) )) != 0)
					return( status );
				}
			else	{
				if (!(get_token()))
					break;
				else  if ((status = is_statement()) == MOINS_UN)
					status = is_ngf_statement();
				unget_token();
				if ( status != MOINS_UN )
					break;
				if ((operand = evaluate_expression(0)) != (RESULTPTR) 0) {
					if ((tcvptr = is_variable_result( operand )) != (TCVARPTR) 0) {
						if ((vptr = locate_vctrl( tcvptr->name )) == (VCTRLPTR) 0)
							return( expected_variable() );
						else if ((status = store_iof_fmt( vptr->picture )) != 0)
							return( status );
						}
					else if ((status = store_iof_fmt( "E" )) != 0)
						return( status );
					if ((status = store_iof_prn( operand )) != 0)
						return( status );
					}
				else	return( syntax_error(1026) );
				}
			}
		(void) is_comma();
		}
	if (( device == (RESULTPTR) 0 )
	&&  ((device = integer_result(1)) == (RESULTPTR) 0))
		return( allocation_failure() );

	if (( tabulate )
	&&  ((status = store_iof_tabv( integer_result(1) )) != 0))
		return( status );

	if ((status = flush_print( device,VRAI )) != 0)
		return( status );
	else	return( xverify_period() );
}

WORD	translate_crt_accept()
{
	TCVARPTR	tcvptr;
	VCTRLPTR	vptr;
	RESULTPTR	device=(RESULTPTR) 0;
	RESULTPTR	operand;
	WORD		status=0;
	WORD		tabulate=1;
	WORD		dval;
	WORD		flag;
	if  ((status = start_iof()) != 0)
		return( status );

	flag = screen_expression(1);

	if ( is_left_brace() ) {
		if ((status = translate_display_tabulation()) != 0)
			return( status );
		}
	if (((operand = evaluate_expression(0)) 		== (RESULTPTR)0)
	||  ((tcvptr = is_variable_result( operand )) 	== (TCVARPTR) 0)
	||  ((vptr = locate_vctrl( tcvptr->name )) 	== (VCTRLPTR) 0))
		return( expected_variable() );

	if ( is_mnemonic("FROM" ) ) {
		device = operand;
		if ( is_mnemonic("DATE") ) {
			if ( flag )
				return( syntax_error(1026) );
			if ((status = store_iof_fmt( "Z2,Z2,Z2" )) != 0)
				return( status );
			for ( dval = 1; dval <= 3; dval++ ) {
				if ((operand = convert_to_type(clf_date( dval ),_TYPE_INT)) == (RESULTPTR) 0)
					return( allocation_failure() );
				else if ((status = store_iof_prn( operand )) != 0)
					return( status );
				}
			}
		else if ( is_mnemonic("TIME") ) {
			if ( flag )
				return( syntax_error(1026) );
			if ((status = store_iof_fmt( "Z2,Z2,Z2" )) != 0)
				return( status );
			for ( dval = 5; dval <= 7; dval++ ) {
				if ((operand = convert_to_type(clf_date( dval ),_TYPE_INT)) == (RESULTPTR) 0)
					return( allocation_failure() );
				else if ((status = store_iof_prn( operand )) != 0)
					return( status );
				}
			}
		else if ( is_mnemonic("ESCAPE") ) {
			if ( flag )
				return( syntax_error(1026) );
			(void) is_mnemonic("KEY");
			if ((status = store_iof_fmt( "Z2" )) != 0)
				return( status );
			if ((operand = clf_hotkey()) == (RESULTPTR) 0)
				return( allocation_failure() );
			else if ((status = store_iof_prn( operand )) != 0)
				return( status );
			}
		else	return( not_yet_available() );
		if ((status = flush_print( device, VRAI )) != 0)
			return( status );
		else	return( xverify_period() );

		}
	else 	{
		/* Keyboard input Required : ASK */
		/* ----------------------------- */
		if ((status = store_implicite_hotkeys( "IUDL", "NEXT" )) != 0)
			return( status );
		if ((status = store_iof_fmt( vptr->picture )) != 0)
			return( status );
		if ((device = integer_result(1)) == (RESULTPTR) 0)
			return( allocation_failure() );
		if ((status = flush_iof_ask( device, operand )) != 0)
			return( status );
		else	return( xverify_period() );
		}


}

#endif	/* _TRSCREEN_C */
	/* ----------- */


