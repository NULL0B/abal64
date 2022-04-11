#define DEBUG
/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRACCEPT.C				*/
/*		Version :	2.1d					*/
/*		Date	:	09/02/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRACCEPT_C
#define	_TRACCEPT_C

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
#include "trpctrl.h"
#include "trvctrl.h"
#include "trcobol.h"
#include "trscreen.h"

WORD		accept_from_sysin( vptr, operand, device )
VCTRLPTR	vptr;
RESULTPTR	operand;
RESULTPTR	device;
{
	WORD	status;
	if ((status = store_implicite_hotkeys( "IUDL", "NEXT" )) != 0)
		return( status );
	else if ((status = store_iof_fmt( vptr->picture )) != 0)
		return( status );
	else if ((status = flush_iof_ask( device, operand )) != 0)
		return( status );
	else	return( xverify_period() );
}

VCTRLPTR	accept_from_group( vptr, device, master )
VCTRLPTR	vptr;
RESULTPTR	device;
WORD		master;
{
	RESULTPTR	operand;
	while (1) {
		if ( vptr->level <= master )
			break;
		else if ( vptr->next == (VCTRLPTR) 0 ) {
			if ((operand = variable_result( vptr->contents )) == (RESULTPTR) 0)
				(void) allocation_failure();
			else if ( vptr->name != (BPTR) 0 ) 
				(void) accept_from_sysin( vptr, operand, device );
			break;
			}
		else if (( vptr->next->level > vptr->level )
		     &&  ( vptr->next->level != 88 )) {
			if ((vptr = accept_from_group( vptr->next, device, master )) == (VCTRLPTR) 0)
				break;
			}
		else	{
			if (( vptr->name  != (BPTR) 0 )
			&&  ( vptr->level != 88 )) {
				if ((operand = variable_result( vptr->contents )) == (RESULTPTR) 0) {
					(void) allocation_failure();
					break;
					}
				else if ( accept_from_sysin( vptr, operand, device ) != 0)
					break;
				}

			if ((vptr = vptr->next) == (VCTRLPTR) 0)
				break;
			}
		if ( start_iof() != 0 )
			break;
		}
	return((VCTRLPTR) 0);
}

WORD		accept_from_sysinput( vptr, operand, mode )
VCTRLPTR	vptr;
RESULTPTR	operand;
WORD		mode;		/* 1 Check Group : 0 As is */
{
	WORD		status;
	RESULTPTR	device;
	VCTRLPTR	xvptr;

	if ((device = integer_result(1)) == (RESULTPTR) 0)
		return( allocation_failure() );

	if ((!( mode ))
	||  ((xvptr = vptr->next) == (VCTRLPTR) 0 )
	||  ( xvptr->level == 88 )
	||  ( xvptr->level <= vptr->level ))
		return( accept_from_sysin( vptr, operand, device ) );

	(void) accept_from_group( vptr->next, device, vptr->level );
	return( 0 );

}

WORD		accept_from_crt(vptr, operand )
VCTRLPTR	vptr;
RESULTPTR	operand;
{
	WORD	mode=VRAI;
	WORD	status;
	if ( is_mnemonic("MODE") ) {
		(void) is_mnemonic("IS");
		if ( is_mnemonic("BLOCK") )
			mode = FAUX;
		else	return( expected_keyword("BLOCK") );
		}
	if ( is_mnemonic("WITH") ) {
		switch ((status = screen_expression(1))) {
			case MOINS_UN	:
			case	    0	:
				break;
			default		:
				return( status );				
			}
		}
	return( accept_from_sysinput( vptr, operand, mode ) );
}

WORD	console_is_crt()
{
	return( ( Cobol->version & _COBOL_ANS85SS ) );
}

WORD	accept_from_crt_mnemonic()
{
	RESULTPTR	operand;
	WORD		status;

	if ( is_mnemonic("ESCAPE") ) {
		(void) is_mnemonic("KEY");
		if ((status = store_iof_fmt( "Z2" )) != 0)
			return( status );
		if ((operand = clf_hotkey()) == (RESULTPTR) 0)
			return( allocation_failure() );
		else if ((status = store_iof_prn( operand )) != 0)
			return( status );
		else	return( 0 );
		}
	else	return( not_yet_available() );
}

WORD		accept_from_mnemonic( vptr, device )
VCTRLPTR	vptr;
RESULTPTR	device;
{
	WORD		status;
	RESULTPTR	operand;
	WORD		dval;

	if (( console_is_crt()   )
	&&  ( is_mnemonic("CRT") ))
		return( accept_from_crt( vptr, device ) );

	else if ( is_mnemonic("DATE") ) {
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
		if ((status = store_iof_fmt( "Z2,Z2,Z2,Z2" )) != 0)
			return( status );
		for ( dval = 5; dval <= 8; dval++ ) {
			if ((operand = convert_to_type(clf_date( dval ),_TYPE_INT)) == (RESULTPTR) 0)
				return( allocation_failure() );
			else if ((status = store_iof_prn( operand )) != 0)
				return( status );
			}
		}
	else if ( is_mnemonic("DAY") ) {
		if ((status = store_iof_fmt( "Z2,Z3" )) != 0)
			return( status );
		else if ((operand = convert_to_type(clf_date( 1 ),_TYPE_INT)) == (RESULTPTR) 0)
			return( allocation_failure() );
		else if ((status = store_iof_prn( operand )) != 0)
			return( status );
		if ((operand = convert_to_type(clf_date( 4 ),_TYPE_INT)) == (RESULTPTR) 0)
			return( allocation_failure() );
		else if ((status = store_iof_prn( operand )) != 0)
			return( status );
		}
	else if ( is_mnemonic("DAY-OF-WEEK") ) {
		if ((status = store_iof_fmt( "Z" )) != 0)
			return( status );
		else if ((operand = convert_to_type(clf_date( 9 ),_TYPE_INT)) == (RESULTPTR) 0)
			return( allocation_failure() );
		else if ((status = store_iof_prn( operand )) != 0)
			return( status );
		}
	else if ( console_is_crt() ) {
		if ((status = accept_from_crt_mnemonic()) != 0)
			return( status );
		}
	else	return( not_yet_available() );

	if ((status = flush_print( device, FAUX )) != 0)
		return( status );
	else	return( xverify_period() );

}

WORD	translate_crt_tabulation()
{
	RESULTPTR	operand;
	WORD		status;
	WORD		mode=0;
	WORD		prevmode=0;

	while ( 1 ) {
		mode = 0;
		if (!( is_mnemonic("AT") )) {
			if (!( is_mnemonic("LINE") )) {
				if ((!( is_mnemonic("COLUMN") ))
				&&  (!( is_mnemonic("COL")    ))) {
					if (!(is_left_brace() ))
						return((prevmode != 0 ? 0 : MOINS_UN ));
					else	mode = 3;	/* BOTH */
					}
				else	mode |= 2;	/* COLUMN */
				}
			else	mode = 1;	/* LINE */
			}
		else	mode = 0;	/* SPECIAL */

		if ( mode == 0 ) {
			if ( is_mnemonic("LINE" ) )
				mode = 1;
			else if (( is_mnemonic("COL" )  )
			     ||  ( is_mnemonic("COLUMN")))
				mode = 2;
			}

		if (( mode == 1 ) || ( mode == 2 ))
			(void) is_mnemonic("NUMBER");

		if ( mode & prevmode )
			return( syntax_error(1000) );
		else	prevmode = mode;

		if ((operand = evaluate_expression(0)) == (RESULTPTR) 0)
			return( expected_variable() );
		
		switch ( mode ) {
			case	0	: /* Special 1 variable */
				return( not_yet_available() );

			case	1	: /* Line expression	*/
				if ((store_iof_tabl( operand )) != 0)
					return( status );
				else	continue;

			case	2	: /* Column expression	*/
				return( store_iof_tabc( operand ) );

			case	3	: /* ( Line Column ) expressions */
					  /* --------------------------- */
				if ((store_iof_tabl( operand )) != 0)
					return( status );

				(void) is_comma();

				if (((operand = evaluate_expression(0)) == (RESULTPTR) 0)
				     ||  ((status = store_iof_tabc(operand)) != 0 ))
					return(syntax_error(1001));
				else if ( is_right_brace() )
					return( 0 );
				else	return( unmatched_braces() );
			}	

		}
}

WORD	translate_console_crt(mode)
WORD	mode;
{
	WORD	xstatus=0;
	WORD	ystatus=0;

	while (1) {
		switch ((xstatus = screen_expression(mode))) {
			case MOINS_UN	:
				if ( ystatus == MOINS_UN )
					return( 0 );
			case	    0	:
				break;
			default		:
				return( xstatus );				
			}
		switch ((ystatus = translate_crt_tabulation())) {
			case MOINS_UN	:
				if ( xstatus == MOINS_UN )
					return( 0 );
			case	    0	:
				break;
			default		:
				return( ystatus );				
			}
		}
}

WORD	translate_accept()
{
	TCVARPTR	tcvptr;
	VCTRLPTR	vptr;
	RESULTPTR	operand;
	WORD		status=0;


	if  ((status = start_iof()) != 0)
		return( status );

	/* CONSOLE IS CRT (allows explicite tabulation) */
	/* -------------------------------------------- */
	if (( console_is_crt() )
	&&  ((status = translate_console_crt(1)) != 0))
		return( status );


	if (((operand = evaluate_expression(0)) 		== (RESULTPTR)0)
	||  ((tcvptr = is_variable_result( operand )) 	== (TCVARPTR) 0)
	||  ((vptr = locate_vctrl( tcvptr->name )) 	== (VCTRLPTR) 0))
		return( expected_variable() );

	/* CONSOLE IS CRT (allows explicite tabulation) */
	/* -------------------------------------------- */
	if (( console_is_crt() )
	&&  ((status = translate_console_crt(1)) != 0))
		return( status );

	if ((!( is_mnemonic("FROM"   ) ))
	||  (   is_mnemonic("CONSOLE")  )
	||  (   is_mnemonic("SYSIN"  )  ))
		return( accept_from_sysinput( vptr, operand, 1 ) );
	else	return( accept_from_mnemonic( vptr, operand    ) );

}

WORD	display_to_sysout( fptr, operand )
BPTR		fptr;
RESULTPTR	operand;
{
	WORD	status;
	if ( fptr == (BPTR) 0 )
		fptr = (BPTR) "E";
	if ((status = store_iof_fmt( fptr )) != 0)
		return( status );
	else if ((status = store_iof_prn( operand )) != 0)
		return( status );
	else	return( 0 );
}

VCTRLPTR	display_group( vptr, master )
VCTRLPTR	vptr;
WORD		master;
{
	RESULTPTR	operand;
	while (1) {
		if ( vptr->level <= master )
			break;
		else if ( vptr->next == (VCTRLPTR) 0 ) {
			if ((operand = variable_result( vptr->contents )) == (RESULTPTR) 0)
				(void) allocation_failure();
			else if ( vptr->name != (BPTR) 0 )
				(void) display_to_sysout( vptr->picture, operand );
			break;
			}
		else if (( vptr->next->level > vptr->level )
		     &&  ( vptr->next->level != 88 )) {
			if ((vptr = display_group( vptr->next, master )) == (VCTRLPTR) 0)
				break;
			}
		else	{
			if (( vptr->name != (BPTR) 0 )
			&&  ( vptr->level != 88 )) {
				if ((operand = variable_result( vptr->contents )) == (RESULTPTR) 0) {
					(void) allocation_failure();
					break;
					}
				else if ( display_to_sysout( vptr->picture, operand ) != 0)
					break;
				}
			if ((vptr = vptr->next) == (VCTRLPTR) 0)
				break;
			}
		}
	return((VCTRLPTR) 0);
}

WORD	display_variable( mode, vptr, operand )
WORD		mode;
VCTRLPTR	vptr;
RESULTPTR	operand;
{
	VCTRLPTR	xvptr;

	if ((!( mode ))
	||  ((xvptr = vptr->next) == (VCTRLPTR) 0 )
	||  ( xvptr->level == 88 )
	||  ( xvptr->level <= vptr->level ))
		return( display_to_sysout( vptr->picture, operand ) );

	(void) display_group( vptr->next, vptr->level );
	return( 0 );


}

WORD	translate_display()
{
	TCVARPTR	tcvptr;
	VCTRLPTR	vptr;
	RESULTPTR	device=(RESULTPTR) 0;
	RESULTPTR	operand;
	WORD		status=0;
	WORD		tabulate=1;
	WORD		mode=1;	/* GROUP flag */
	OPERNODE	optr=(OPERNODE) 0;
	OPERNODE	nptr=(OPERNODE) 0;
	OPERNODE	xoptr=(OPERNODE) 0;

	if  ((status = start_iof()) != 0)
		return( status );

	while ( 1 ) {

		/* CONSOLE IS CRT (allows explicite tabulation) */
		/* -------------------------------------------- */
		if (( console_is_crt() )
		&&  ((status = translate_console_crt(0)) != 0))
			return( status );

		if ( is_mnemonic("UPON") ) {
			if ((!(is_mnemonic("CONSOLE")))
			&&  (!(is_mnemonic("CRT"    )))
			&&  (!(is_mnemonic("SYSOUT" )))
			&&  ((device = evaluate_expression(0)) == (RESULTPTR) 0))
				return( expected_variable() );
			break;
			}
		else if ( is_mnemonic( "SPACE" ) ) {
			if ((status = translate_iof_clear()) != 0)
				return( status );
			}
		else	{
			if (!(get_token()))
				break;
			if ((status = is_statement()) == MOINS_UN)
				status = is_ngf_statement();
			unget_token();
			if ( status != MOINS_UN )
				break;
			if ((operand = evaluate_expression(0)) != (RESULTPTR) 0) {
				if ((xoptr = allocate_operand_node( operand )) == (OPERNODE) 0)
					return( allocation_failure() );
				if (nptr == (OPERNODE) 0 )
					optr = xoptr;
				else 	nptr->next = xoptr;
				nptr = xoptr;
				}
			else	{
				unget_token();
				break;
				}
			}
		(void) is_comma();
		}

	if ( is_mnemonic("MODE") ) {
		(void) is_mnemonic("IS");
		if ( is_mnemonic("BLOCK") )
			mode = FAUX;
		else	return( expected_keyword("BLOCK") );
		}

	if ( is_mnemonic("WITH") ) {
		if ( console_is_crt() ) {
			if ((status = translate_console_crt(0)) != 0)
				return( status );
			}
		}
	if ( is_mnemonic("NO") ) {
		if ( is_mnemonic("ADVANCING" ) )
			tabulate=0;
		else	return( expected_keyword("ADVANCING") );
		}

	while ((xoptr = optr) != (OPERNODE) 0) {
		optr = optr->next;
		if ((tcvptr = is_variable_result( xoptr->operand )) != (TCVARPTR) 0) {
			if ((vptr = locate_vctrl( tcvptr->name )) == (VCTRLPTR) 0)
				return( expected_variable() );
			else if ((status = display_variable( mode, vptr, xoptr->operand )) != 0)
				return( status );
			}
		else if ((status = display_to_sysout( "E", xoptr->operand )) != 0)
			return( status );
		liberate( xoptr );
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

#endif	/* _TRACCEPT_C */
	/* ----------- */


