#define DEBUG
/* -------------------------------------------------------------------- */
/*                                                                      */
/*              Project ABAL : Macro pre-processer                      */
/*                                                                      */
/*               Copyright (c) 1990, 1995 Amenesik / Sologic s.a.                 */
/*                                                                      */
/*                                                                      */
/*              File    :       TRPCTRL.C                               */
/*              Version :       2.1c                                    */
/*              Date    :       14/02/1995                              */
/*                                                                      */
/* -------------------------------------------------------------------- */
#ifndef _TRPCTRL_C
#define _TRPCTRL_C
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

UCTRLPTR        allocate_for_uctrl()
{
	UCTRLPTR        uptr;

	if ((uptr = (UCTRLPTR) allocate( sizeof( struct cobol_uctrl ) )) != (UCTRLPTR) 0) {
		uptr->label  = 0;
		uptr->nombre = 0;
		uptr->next   = (UCTRLPTR) 0;
		}
	return( uptr );
}

PCTRLPTR        allocate_for_pctrl( nptr )
BPTR            nptr;
{
	PCTRLPTR        pptr;

	if ((pptr = (PCTRLPTR) allocate( sizeof( struct cobol_pctrl ) )) != (PCTRLPTR) 0) {
		if (( pptr->name = allocate_for_string( nptr )) != (BPTR) 0) {
			pptr->users = 0;
			pptr->usage = (UCTRLPTR) 0;
			pptr->intro = 0;
			pptr->callback = 0;
			pptr->control = (TCVARPTR) 0;
			pptr->next  = (PCTRLPTR) 0;
			return( pptr );
			}
		liberate( pptr );
		}
	return((PCTRLPTR) 0);
}

PCTRLPTR        locate_pctrl( nptr )
BPTR            nptr;
{
	PCTRLPTR        pptr;
	if ((pptr = Cobol->PctrlHeap) != (PCTRLPTR) 0) {
		do      {
			if ( compare_tokens( nptr, pptr->name ) )
				break;
			}
		while ((pptr = pptr->next) != (PCTRLPTR) 0);
		}
	return( pptr );
}

WORD            add_pctrl_callback( pptr, label )
PCTRLPTR        pptr;
WORD            label;
{
	WORD            status;
	WORD            linkage;
	UCTRLPTR        uptr;
	UCTRLPTR        xptr=(UCTRLPTR) 0;

	if ((uptr = allocate_for_uctrl()) == (UCTRLPTR) 0)
		return( MOINS_UN );
	uptr->label   = label;
	uptr->nombre  = ++pptr->users;
	if ((xptr = pptr->usage) == (UCTRLPTR) 0)
		pptr->usage = uptr;
	else    {
		while (xptr->next != (UCTRLPTR) 0)
			xptr = xptr->next;
		xptr->next = uptr;
		}
	return( uptr->nombre );
}

VOID    liberate_for_pctrl( pptr )
PCTRLPTR        pptr;
{
	UCTRLPTR        uptr;
	if ( pptr->name != (BPTR) 0)
		liberate( pptr->name );
	while ((uptr = pptr->usage) != (UCTRLPTR) 0) {
		pptr->usage = uptr->next;
		liberate( uptr );
		}
	liberate( pptr );
}

PCTRLPTR        resolve_pctrl( nptr )
BPTR            nptr;
{
	PCTRLPTR        pptr;
	WORD            status;
	BYTE            vname[32];
	
	if ((pptr = locate_pctrl( nptr )) == (PCTRLPTR) 0) {
		if ((pptr = allocate_for_pctrl( nptr )) == (PCTRLPTR) 0)
			return( pptr );
		if ((status = add_pctrl_callback( pptr, new_implicite_label() )) == MOINS_UN ) {
			liberate_for_pctrl( pptr );
			return((PCTRLPTR) 0);
			}
		pptr->intro = new_implicite_label();
		pptr->callback = new_implicite_label();
		sprintf(vname,"$%u$%u",pptr->intro,pptr->callback);

		if ((status = add_variable( vname, 1, 2, 1, 1, 0, 0, 0 )) != 0) {
			liberate_for_pctrl(pptr);
			return((PCTRLPTR) 0);
			}
		if ((pptr->control = Context->LDT->variable) == (TCVARPTR) 0) {
			liberate_for_pctrl( pptr );
			(void) allocation_failure();
			return((PCTRLPTR) 0);
			}
		else    {
			pptr->next = Cobol->PctrlHeap;
			Cobol->PctrlHeap = pptr;
			}
		}
	return( pptr );
}


VOID    liberate_pctrl()
{
	PCTRLPTR        pptr;
	while (( pptr = Cobol->PctrlHeap ) != (PCTRLPTR) 0) {
		Cobol->PctrlHeap = pptr->next;
		liberate_for_pctrl( pptr );
		}
	return;
}


WORD    translate_perform_while(mode)
WORD    mode;
{
	WORD    status=0;
	trace("perform_while()\n");
	if ((status = enter_iteration( _ITERATION_WHILE,(TCVARPTR) 0  )) != 0)
		return( status );
	else if ((status = conditional_expression(mode)) != 0 )
		return( status );
	else    return( 0 );
}

WORD    translate_perform_wend()
{
	WORD    status=0;
	trace("perform_wend()\n");
	if ( iteration_type() != _ITERATION_WHILE )
		return( syntax_error(1002) );
	leave_iteration();
	return(status);
}

WORD    translate_perform_loop()
{
	WORD    status=0;
	trace("perform_loop()\n");
	if ( iteration_type() != _ITERATION_DO )
		return( syntax_error(1003) );
	leave_iteration();
	return(status);
}

/*
 *      PERFORM <procedure> [ THRU <procedure> ]
 *      ----------------------------------------
 *
 */

WORD    basic_perform( target1, target2 )
BPTR    target1;
BPTR    target2;
{
	WORD            status;
	WORD            label;
	WORD            linkage;
	PCTRLPTR        pptr;
	PCTRLPTR        qptr;

	trace("basic_perform()\n");
	if ( strlen(target1) != 0 ) {

		/* Establish Target Paragraph Identity */
		/* ----------------------------------- */
		if ((pptr = resolve_pctrl( target1 )) == (PCTRLPTR) 0)
			return( allocation_failure() );

		if ( strlen(target2) != 0 ) {
			if ((qptr = resolve_pctrl( target2 )) == (PCTRLPTR) 0)
				return( allocation_failure() );
			}
		else    qptr = pptr;

		/* New CALL BACK label */
		/* ------------------- */
		if ((linkage = add_pctrl_callback(qptr,(label = new_implicite_label()))) == MOINS_UN)
			return( allocation_failure() );

		if ( qptr->control != (TCVARPTR) 0) {
			if ( OtrOption.Optimise )
				status = generate_optimised_sti( qptr->control, use_implicite_label( label, 1 ));
			else    status = generate_optimised_sti( qptr->control, linkage );
			if ( status != 0 )
				return( status );
			}

		/* Goto the Procedure */
		/* ------------------ */
		if ((status = implicite_goto(pptr->intro)) != 0)
			return( status );

		/* Define CALL BACK label */
		/* ---------------------- */
		(void) dcl_implicite_label( label );

		/* Re-establish original Paragraph call back value */
		/* ----------------------------------------------- */
		if (qptr->control != (TCVARPTR) 0) {
			if ( OtrOption.Optimise )
				status = generate_optimised_sti( qptr->control, use_implicite_label( qptr->usage->label, 1 ));
			else    status = generate_optimised_sti( qptr->control, qptr->usage->nombre );
			if ( status != 0 )
				return( status );
			}
		}
	return( 0 );
}

/*
 *      PERFORM [ TEST [ BEFORE | AFTER ] ] UNTIL <expression>
 *      ------------------------------------------------------
 *
 */     

WORD    perform_until( when, target1, target2, mode )
WORD    when;           /* 0 : TEST BEFORE, 1 : TEST AFTER */
BPTR    target1;
BPTR    target2;
WORD    mode;           /* 0 : WHILE,       1 : UNTIL      */
{
	WORD    label;
	WORD    status=0;
	trace("perform_until()\n");
	if (( when != 0 )
	&&  ((status = implicite_goto((label = new_implicite_label()))) != 0))
		return( status );
	if ((status = translate_perform_while(mode)) != 0)
		return( status );
	if ( when != 0 )
		dcl_implicite_label( label );
	if ((status = dcl_operate_label()) == 0)
		return( internal_error() );
	if ( strlen(target1) != 0 ) {
		if ((status = basic_perform( target1, target2 )) != 0)
			return( status );
		else if ((status = translate_perform_wend()) != 0)
			return( status );
		}
	return( 0 );
}

WORD            perform_times( when , tptr, target1, target2 )
WORD            when;
RESULTPTR       tptr;
BPTR            target1;
BPTR            target2;
{
	RESULTPTR       zptr;
	WORD            status;
	WORD            ltimesin;
	WORD            ltimesout;
	WORD            label;
	trace("perform_times()\n");
	if (!( is_mnemonic( "TIMES" ) ))
		return( expected_keyword("TIMES") );
	if (((zptr = integer_result( 0     )) == (RESULTPTR) 0)
	||  ((tptr = ensure_register( tptr )) == (RESULTPTR) 0)
	||  ((tptr = protect_operand( tptr )) == (RESULTPTR) 0))
		return( allocation_failure() );

	if (( when != 0 )
	&&  ((status = implicite_goto((label = new_implicite_label()))) != 0))
		return( status );

	if ((status = enter_iteration( _ITERATION_DO,(TCVARPTR) 0  )) != 0)
		return( status );

	if ((status = evaluate_comparison(_CMP_LE,tptr,zptr,MOINS_UN,0)) != 0)
		return( status );

	generate_decrement( tptr );

	if ( when != 0 )
		dcl_implicite_label( label );

	if ( strlen( target1 ) != 0 ) {
		if ((status = basic_perform( target1, target2 )) != 0)
			return( status );
		else    return( translate_perform_loop() );
		}
	else    return( 0 );
}

WORD            perform_varying( when , target1, target2 )
WORD            when;
BPTR            target1;
BPTR            target2;
{
	TCVARPTR        tcvptr;
	RESULTPTR       fromptr;
	RESULTPTR       byptr;
	RESULTPTR       rptr;
	WORD            status;
	WORD            label;

	trace("perform_varying()\n");

	if (!( get_token() ))
		return( expected_variable() );
	if (((tcvptr = is_variable(1)) == (TCVARPTR) 0)
	||  ((rptr = variable_result( tcvptr )) == (RESULTPTR) 0))
		return( expected_variable() );
	if (( is_mnemonic("FROM") )
	&&  ((fromptr = evaluate_expression(0)) != (RESULTPTR) 0)
	&&  ( is_mnemonic("BY")   )
	&&  ((byptr = evaluate_expression(0)) != (RESULTPTR) 0)
	&&  ( is_mnemonic("UNTIL" ))) {
		if ((status = picture_affectation( tcvptr, fromptr)) != 0)
			return( status );
		if ( strlen( target1 ) == 0 )
			return( not_yet_available() );
		if (( when != 0 )
		&&  ((status = implicite_goto((label = new_implicite_label()))) != 0))
			return( status );
		if ((status = translate_perform_while()) != 0)
			return( status );
		if ( when != 0 )
			dcl_implicite_label( label );
		if ((status = basic_perform(target1,target2)) != 0)
			return( status );
		if ((rptr = evaluate_operation( '+', rptr, byptr )) == (RESULTPTR) 0)
			return( syntax_error(1004) );
		else if ((status = picture_affectation( tcvptr, rptr)) != 0)
			return( status );
		else    return( translate_perform_wend() );
		}
	else    return( syntax_error(1005) );
}


/*
 *      PERFORM
 *              [ <procedure>   [ THROUGH | THRU <procedure> ]          ]
 *              [ WITH TEST     [ AFTER | BEFORE ]                      ]
 *              [ UNTIL <condition>                                     ]
 *              [ WHILE <condition>                                     ]
 *              [ VARYING <variable>                                    ]
 *              [               FROM <expression>                       ]
 *              [               BY <expression>                         ]
 *              [               AFTER <variable> FROM BY UNTIL...       ]
 *              [ UNTIL <condition>                                     ]
 *              [ <expression>  TIMES                                   ]
 *
 */

WORD    translate_perform()
{
	WORD            status;
	BYTE            target1[64];
	BYTE            target2[64];
	RESULTPTR       rptr;
	WORD            when=0;         /* Default ANS74 COBOL : BEFORE */

	trace("translate_perform()\n");

	target1[0] = 0; target2[0] = 0;

	while (1)       {

		/*      [ WITH TEST [ BEFORE | AFTER ] ]        */
		/*      --------------------------------        */
		(void) is_mnemonic("WITH");
		if ( is_mnemonic("TEST") ) {
			if ( is_mnemonic("BEFORE") )
				when = 0;
			else if ( is_mnemonic("AFTER") )
				when = 1;
			}

		/*      [ UNTIL <condition> ]                   */
		/*      ---------------------                   */
		if ( is_mnemonic("UNTIL") ) {
			if ((status = perform_until( when, target1, target2, 1 )) != 0)
				return( status );
			else    return( xverify_period() );
			}

		/*      [ WHILE <condition> ]                   */
		/*      ---------------------                   */
		if ( is_mnemonic("WHILE") ) {
			if ((status = perform_until( when, target1, target2, 0 )) != 0)
				return( status );
			else    return( xverify_period() );
			}

		/*      [ VARYING <variable> FROM <ex> BY <ex> UNTIL <cond> */
		/*      --------------------------------------------------- */
		else if ( is_mnemonic("VARYING") ) {
			if ((status = perform_varying( when, target1, target2 )) != 0)
				return( status );
			else    return( xverify_period() );
			}

		/*      [ <expression>  TIMES ]                 */
		/*      -----------------------                 */
		else if ((rptr = evaluate_expression(0)) != (RESULTPTR) 0) {
			if ((status = perform_times( when, rptr, target1, target2 )) != 0)
				return(status);
			else    return( xverify_period() );
			}

		/*      [ <procedure> [[ THRU | THROUGH ] <procedure> ] */
		/*      ----------------------------------------------- */
		else if ( strlen(target1) > 0 ) {
			unget_token();
			if ((status = basic_perform(target1,target2)) != 0)
				return( status );
			else    return( xverify_period() );
			}
		else    strcpy( target1, TokenBuffer );
		if (( is_mnemonic("THRU" )  )
		||  ( is_mnemonic("THROUGH"))) {
			if (!( get_token() ))
				return( expected_paragraph() );
			else    strcpy(target2,TokenBuffer);
			}

		}
}

WORD    translate_end_perform()
{
	WORD    status;
	while ( 1 ) {
		switch ( iteration_type() )     {
			case _ITERATION_WHILE   :
			case _ITERATION_DO      :
				leave_iteration();
				return( xverify_period() );
			case    0               :
				return( syntax_error(1006) );
			default                 :
				leave_iteration();
				continue;
			}
		}
}

WORD    initialise_for_perform()
{
	trace("initialise_for_perform()\n");
	return(generate_gosub(use_implicite_label((Cobol->PerformInit = new_implicite_label()),1)));
}

WORD    terminate_for_perform()
{
	WORD            label;
	WORD            status;
	PCTRLPTR        pptr;
	RESULTPTR       operand;
	UCTRLPTR        uptr;
	WORD            backpatch;
	trace("terminate_for_perform()\n");
	if ( Cobol->PerformInit != MOINS_UN ) {
		if ((status = generate_stop()) != 0)
			return( status );
		(void) dcl_implicite_label( Cobol->PerformInit );

		/* Initialise Paragraph Control Variables */
		/* -------------------------------------- */
		if ((pptr = Cobol->PctrlHeap) != (PCTRLPTR) 0) {
			do      {
				if ( pptr->control != (TCVARPTR) 0) {
					if ( OtrOption.Optimise ) 
						status = generate_optimised_sti( pptr->control, use_implicite_label( pptr->usage->label, 1 ));
					else    status = generate_optimised_sti( pptr->control, pptr->usage->nombre);
					if ( status != 0 )
						return( status );
					}
				else    return( internal_error(666) );
				}
			while ((pptr = pptr->next) != (PCTRLPTR) 0);
			}
		Cobol->PerformInit = MOINS_UN;
		if ((status = generate_return()) != 0)
			return( status );
		if ((pptr = Cobol->PctrlHeap) != (PCTRLPTR) 0) {
			do      {
				/* Ensure Re-usage of same register */
				/* -------------------------------- */
				(void) release_expressions(VRAI);
				(void) dcl_implicite_label( pptr->callback );
				if (((operand = variable_result( pptr->control )) == (RESULTPTR) 0)
				||  ((operand = ensure_register( operand       )) == (RESULTPTR) 0))
					return( internal_error(777) );

				if ( OtrOption.Optimise ) {
					/* ------------- */
					/* GOTO REGISTER */
					/* ------------- */
					if ((status = generate_goto_register( operand )) != 0)
						return( status );
					}
				else    {
					if ( pptr->users > 1 ) {
						/* -------------------------------- */
						/* ON CONTROL GOTO CALL BACK LABELS */
						/* -------------------------------- */
						if ((backpatch = generate_of( operand, 0 )) == MOINS_UN)
							return( internal_error() );
						if ((uptr = pptr->usage) != (UCTRLPTR) 0) {
							do      {
								tcode_label((label = use_implicite_label( uptr->label, 0 )));   
								}
							while (( uptr = uptr->next ) != (UCTRLPTR) 0);
							}
						(void) backpatch_value( backpatch, pptr->users );
						}
					else if ((status = implicite_goto( pptr->usage->label )) != 0 )
						return( status );
					}
				}
			while ((pptr = pptr->next) != (PCTRLPTR) 0);
			}
		}
	else    return( 0 );
}

WORD    terminate_procedure_label()
{
	WORD            status=0;
	PCTRLPTR        pptr;
	if ((pptr = Cobol->CurrentPctrl) != (PCTRLPTR) 0 ) {
		if ((status = implicite_goto( pptr->callback )) != 0)
			return( status );
		(void) dcl_implicite_label( pptr->usage->label );
		Cobol->CurrentPctrl = (PCTRLPTR) 0;
		}
	return( status );
}

WORD    translate_procedure_label()
{
	BPTR            proclabel[65];
	WORD            status=0;
	PCTRLPTR        pptr;
	trace("translate_procedure_label()\n");
	if  ( is_period() ) {
		if ((status = terminate_procedure_label()) != 0)
			return( status );
		if ((pptr = resolve_pctrl( TokenBuffer )) == (PCTRLPTR) 0)
			return( allocation_failure() );

		(void) dcl_implicite_label( pptr->intro );              
		Cobol->ProcedureLabel++;
		Cobol->CurrentPctrl = pptr;
		return( 0 );
		}
	else    return( syntax_error(1007) );
}

WORD    translate_exit(mode)
WORD    mode;
{
	WORD            status;
	WORD            label;
	RESULTPTR       rptr;
	trace("translate_exit()\n");
	if ((mode)
	||  ( is_mnemonic("PROGRAM") )) {
		label = new_implicite_label();
		if ((rptr = variable_result( Cobol->ErrorVariable )) == (RESULTPTR) 0)
			return( allocation_failure() );
		if ((status = implicite_on_error( rptr->contents, _CTRL_LOCAL, label )) != 0)
			return(status);
		if ((status = generate_retseg()) != 0)
			return( status );
		(void) dcl_implicite_label( label );
		if ((status = generate_error_abort()) != 0)
			return( status );
		if (( mode )
		&&  ((status = generate_stop()) != 0))
			return( status );
		}
	else if ((status = terminate_procedure_label()) != 0)
		return( status );
	return( xverify_period() );
}


WORD    translate_depending( initial )
BPTR    initial;
{
	RESULTPTR       rptr;
	RESULTPTR       zptr;
	VCTRLPTR        vptr;
	PCTRLPTR        pptr;
	WORD            status;
	WORD            label;
	WORD            nombre=0;
	WORD            backpatch=0;
	BPTR            xptr;

	trace("translate_depending()\n");

	/* GO to <proc>, <proc> DEPENDING on <expr> */
	/* ---------------------------------------- */
	strcpy( CobolToAbal, initial );
	while (1) {
		strcat( CobolToAbal, ",");
		strcat( CobolToAbal, TokenBuffer );
		(void) is_comma();
		if ( is_mnemonic("DEPENDING") ) {
			(void) is_mnemonic("ON");
			break;
			}
		else if (!(get_token()))
			return( expected_paragraph() );
		}

	if (!( get_token() ))
		return( expected_variable() );

	if ((vptr = locate_vctrl( TokenBuffer )) == (VCTRLPTR) 0)
		return( expected_variable() );

	if (((rptr = variable_result(vptr->contents))  != (RESULTPTR) 0)
	&&  ((rptr = ensure_register( rptr )) != (RESULTPTR) 0)
	&&  ((zptr = integer_result( 0 ))     != (RESULTPTR) 0)) {

		if ((backpatch = generate_of( rptr, 0 )) == MOINS_UN)
			return( internal_error() );
		xptr = get_parser_buffer();
		set_parser_buffer( CobolToAbal );
		do      {
			if (!( get_token() ))   
				return( expected_paragraph() );
			if ((pptr = resolve_pctrl( TokenBuffer )) == (PCTRLPTR) 0)
				return( allocation_failure() );
			tcode_label((label = use_implicite_label( pptr->intro, 0 )));   
			nombre++;
			}
		while ( is_comma() );
		set_parser_buffer( xptr );
		(void) backpatch_value( backpatch, nombre );
		return( xverify_period() );
		}
	return( syntax_error(1008) );
}

/*
 *      GO [ TO ] .
 *
 *      GO [ TO ] <paragraph> [ . ]
 *
 *      GO [ TO ] <paragraph_list>  DEPENDING [ ON ] <variable> [ . ]
 *
 */


WORD    translate_goto()
{
	BYTE            label[64];
	WORD            status;
	PCTRLPTR        pptr;

	status = is_mnemonic("TO");

	if ((Cobol->version & _COBOL_ANS85)
	&&  (!( status )))
		return( expected_keyword("TO") );

	if ( is_period() )
		return( terminate_procedure_label() );
	else if (!( get_token() ))
		return( expected_paragraph() );
	strcpy(label,TokenBuffer);

	(void) is_comma();

	if ( get_token() )
		return( translate_depending( label ) );
	else    {               
		if ((pptr = resolve_pctrl( label )) == (PCTRLPTR) 0)
			return( allocation_failure() );
		/* GO to <proc> */
		/* ------------ */
		if ((status = implicite_goto(pptr->intro)) != 0)
			return( status );
		else    return( xverify_period() );
		}
}

WORD    translate_alter()
{
	WORD            status;
	WORD            linkage;
	PCTRLPTR        pptr;
	PCTRLPTR        qptr;
	if (!( get_token() ))
		return( expected_paragraph() );
	else if ((pptr = resolve_pctrl( TokenBuffer )) == (PCTRLPTR) 0)
		return( allocation_failure() );
	else if (!( is_mnemonic("TO") ))
		return( expected_keyword("TO") );
	
	(void) is_mnemonic("PROCEED");
	(void) is_mnemonic("TO");

	if (!( get_token() ))
		return( expected_paragraph() );
	else if ((qptr = resolve_pctrl( TokenBuffer )) == (PCTRLPTR) 0)
		return( allocation_failure() );

	if ( OtrOption.Optimise )
		status = generate_optimised_sti( pptr->control, use_implicite_label( qptr->intro, 1 ));
	else if ((linkage = add_pctrl_callback(pptr,qptr->intro)) == MOINS_UN)
		return( allocation_failure() );
	else    status = generate_optimised_sti( pptr->control, linkage );
	if ( status != 0 )
		return( status );
	else    return( xverify_period() );
}

#endif  /* _TRPCTRL_C */
	/* ---------- */

