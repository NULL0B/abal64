#define DEBUG
/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRFCTRL.C				*/
/*		Version :	2.1c					*/
/*		Date	:	27/01/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRFCTRL_C
#define	_TRFCTRL_C
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

OPERNODE	allocate_operand_node( operand )
RESULTPTR	operand;
{
	OPERNODE	optr;

	if ((optr = (OPERNODE) allocate( sizeof( struct operand_node ) )) != (OPERNODE) 0) {
		optr->next = (OPERNODE) 0;
		optr->operand = operand;
		}
	return( optr );
}

RCTRLPTR	allocate_for_rctrl( nptr )
BPTR		nptr;
{
	RCTRLPTR	rptr;
	if ((rptr = (RCTRLPTR) allocate( sizeof ( struct cobol_rctrl ) )) != (RCTRLPTR) 0) {
		if ((rptr->name = allocate_for_string( nptr )) != (BPTR) 0) {
			rptr->next = (RCTRLPTR) 0;
			return( rptr );
			}
		liberate( rptr );
		}
	return( (RCTRLPTR) 0 );
}	

WORD		add_fctrl_record( fptr, nptr )
FCTRLPTR	fptr;
BPTR		nptr;
{
	RCTRLPTR	rptr;

	if ((rptr = allocate_for_rctrl( nptr )) != (RCTRLPTR) 0) {
		rptr->next = fptr->records;
		fptr->records = rptr;
		return( 0 );			
		}
	return( allocation_failure() );
}

WORD	create_records( fptr )
FCTRLPTR	fptr;
{
	RCTRLPTR	rctrl;
	VCTRLPTR	vptr;
	TCVARPTR	tcvptr;
	RESULTPTR	rptr;
	WORD		status;

	if ((rctrl = fptr->records) != (RCTRLPTR) 0) {
		do	{
			if (((vptr = locate_vctrl( rctrl->name )) != (VCTRLPTR) 0)
			&&  ((tcvptr = (TCVARPTR) vptr->contents) != (TCVARPTR) 0)
			&&  ((rptr = variable_result( tcvptr   )) != (RESULTPTR) 0))
				if ((status = clf_create( rptr )) != 0)
					return( status );
			}
		while ((rctrl = rctrl->next) != (RCTRLPTR) 0);
		}
	return(0);
}

WORD	remove_records( fptr )
FCTRLPTR	fptr;
{
	RCTRLPTR	rctrl;
	VCTRLPTR	vptr;
	TCVARPTR	tcvptr;
	RESULTPTR	rptr;
	WORD		status;

	if ((rctrl = fptr->records) != (RCTRLPTR) 0) {
		do	{
			if (((vptr = locate_vctrl( rctrl->name )) != (VCTRLPTR) 0)
			&&  ((tcvptr = (TCVARPTR) vptr->contents) != (TCVARPTR) 0)
			&&  ((rptr = variable_result( tcvptr   )) != (RESULTPTR) 0))
				if ((status = clf_remove( rptr )) != 0)
					return( status );
			}
		while ((rctrl = rctrl->next) != (RCTRLPTR) 0);
		}
	return(0);
}


FCTRLPTR	allocate_for_fctrl( nptr )
BPTR		nptr;
{
	FCTRLPTR	fptr;
	if ((fptr = (FCTRLPTR) allocate( sizeof( struct cobol_fctrl ) )) != (FCTRLPTR) 0) {
		if ((fptr->select = (BPTR) allocate_for_string( nptr )) != (BPTR) 0 ) {
			fptr->assign = (BPTR) 0;
			fptr->access = _FCTRL_SEQUENTIAL;
			fptr->organisation = _FCTRL_SEQUENTIAL;
			fptr->nature    = _FCTRL_NATURE_FILE;
			fptr->recordkey = (BPTR) 0;
			fptr->recordbuf = (BPTR) 0;
			fptr->status = (BPTR) 0;
			fptr->recordsize = 0;
			fptr->handle = SelectHandle++;
			fptr->records = (RCTRLPTR) 0;
			fptr->next = Cobol->SelectHeap;
			return((Cobol->SelectHeap = fptr));
			}
		liberate( fptr );
		}
	return( (FCTRLPTR) 0 );
}

FCTRLPTR	locate_fctrl( nptr )
BPTR		nptr;
{
	FCTRLPTR	fptr;
	if ((fptr = Cobol->SelectHeap) != (FCTRLPTR) 0) {
		do	{
			if ( compare_tokens( nptr, fptr->select ) )
				break;
			}
		while ((fptr = fptr->next) != (FCTRLPTR) 0);
		}
	return( fptr );
}

VOID	liberate_fctrl()
{
	FCTRLPTR	fptr;
	RCTRLPTR	rptr;
	trace("liberate_fctrl()\n");
	while ((fptr = Cobol->SelectHeap) != (FCTRLPTR) 0) {
		Cobol->SelectHeap = fptr->next;
		if ( fptr->select != (BPTR) 0)
			liberate( fptr->select );
		if ( fptr->assign != (BPTR) 0)
			liberate( fptr->assign );
		if ( fptr->recordkey != (BPTR) 0)
			liberate( fptr->recordkey );
		if ( fptr->recordbuf != (BPTR) 0)
			liberate( fptr->recordbuf );
		if ( fptr->status != (BPTR) 0)
			liberate( fptr->status );
		while ((rptr = fptr->records) != (RCTRLPTR) 0) {
			fptr->records = rptr->next;
			if ( rptr->name != (BPTR) 0 )
				liberate( rptr->name );
			liberate( rptr );
			}
		liberate( fptr );
		}
	return;
}

COBOLPTR	allocate_for_cobol()
{
	COBOLPTR	cptr;
	trace("allocate_for_cobol()");
	if ((cptr = (COBOLPTR) allocate( sizeof(struct cobol_context) )) != (COBOLPTR) 0) {
		trace(" : OK\n");
		cptr->CurrentProgram	= (BPTR) 0;
		cptr->FillerCount       = 1;
		cptr->comma		= '.';
		cptr->version           = 0;
		cptr->options		= 0;
		cptr->CurrentDivision 	= 0;
		cptr->PctrlHeap		= (PCTRLPTR) 0;
		cptr->CurrentPctrl	= (PCTRLPTR) 0;
		cptr->ProcedureLabel	= 0;
		cptr->PerformInit       = MOINS_UN;
		cptr->SelectHeap	= (FCTRLPTR) 0;
		cptr->CurrentFctrl	= (FCTRLPTR) 0;
		cptr->ErrorVariable	= (TCVARPTR) 0;
		cptr->VctrlHeap	= (VCTRLPTR) 0;
		cptr->VctrlLast	= (VCTRLPTR) 0;
		cptr->CurrentVctrl	= (VCTRLPTR) 0;
		cptr->Next		= (COBOLPTR) 0;
		}
	else	trace(" : FAIL\n");
	return( cptr );
}

COBOLPTR	liberate_for_cobol()
{
	COBOLPTR	cbptr=(COBOLPTR) 0;
	trace("liberate_for_cobol()\n");
	if ( Cobol != (COBOLPTR) 0) {
		cbptr = Cobol->Next;
		liberate_fctrl();
		liberate_vctrl();
		if ( Cobol->CurrentProgram != (BPTR) 0 )
			liberate( Cobol->CurrentProgram );
		liberate_pctrl();
		liberate( Cobol );
		}
	return( cbptr );
}

WORD	cobol_ngf_translate()
{
	WORD	status;
	BPTR	xptr;
	WORD	label;
	strcat( CobolToAbal, " \r\n" );
	xptr = get_parser_buffer();
	if (OtrOption.Verbose)
		sysprintf("%s",CobolToAbal);
	if (((status = initialise_line_parser( CobolToAbal )) != 0 )
	&&  ( get_token() ))
		status = translate_ngf();
	terminate_line_parser();
	set_parser_buffer( xptr );
	return( status );
}

RESULTPTR	resolve_vctrl( nptr )
BPTR		nptr;
{
	VCTRLPTR	vptr;
	TCVARPTR	tcvptr;
	RESULTPTR	rptr;
	if  ((( vptr = locate_vctrl( nptr ))          != (VCTRLPTR)  0)
	&&   (( tcvptr = (TCVARPTR) vptr->contents)   != (TCVARPTR)  0)
	&&   (( rptr = variable_result( tcvptr ))     != (RESULTPTR) 0))
		return( rptr );
	else	return((RESULTPTR) 0);
}

WORD	avoid_file_error( fptr,label,error_value, cmptype )
FCTRLPTR	fptr;
WORD		label;
WORD		error_value;
WORD		cmptype;
{
	WORD		status;
	RESULTPTR	rptr;
	RESULTPTR	zptr;

	if ((rptr = resolve_vctrl( fptr->status )) == (RESULTPTR) 0)
		return( expected_variable() );
	else if ((zptr = integer_result( error_value )) == (RESULTPTR) 0)
		return( allocation_failure() );
	else if ((zptr = convert_to_type( zptr, 3 )) == (RESULTPTR) 0)
		return( allocation_failure() );
	else	return((status = evaluate_comparison(cmptype,rptr,zptr,_LOGICAL_USE,label)));
}

WORD	fctrl_error_test( fptr, error_value, opcode )
FCTRLPTR	fptr;
WORD		error_value;
WORD		opcode;
{
	RESULTPTR	rptr;
	RESULTPTR	zptr;
	WORD		status;
	if ((rptr = resolve_vctrl( fptr->status )) == (RESULTPTR) 0)
		return( expected_variable() );
	else if (((zptr = integer_result( error_value )) == (RESULTPTR) 0)
	     ||  ((zptr = convert_to_type( zptr, 3 ))    == (RESULTPTR) 0))
		return( allocation_failure() );
	else	return((status = evaluate_comparison(opcode,rptr,zptr,_LOGICAL_AND,0)));
}

WORD	locate_fctrl_iteration()
{
	while ( 1 ) {
		switch ( iteration_type() ) {
			case _ITERATION_READ	:
			case _ITERATION_WRITE	:
			case _ITERATION_REWRITE	:
			case _ITERATION_START	:
			case _ITERATION_DELETE	:
				return( 0 );
			case 0			:
				return( syntax_error(1009) );
			default			:
				leave_iteration();
			}
		}
}

static	WORD	translate_at( mode )
WORD		mode;
{
	WORD		status;
	FCTRLPTR	fptr;
	trace("translate_at()\n");
	if (!( is_mnemonic("END") ))
		return( expected_keyword("END") );
	if ((status = locate_fctrl_iteration()) != 0)
		return( status );
	if ((fptr = (FCTRLPTR) get_iteration_context()) == (FCTRLPTR) 0)
		return( syntax_error(1010) );
	if ( iteration_usage() != 0 ) {
		generate_iteration();
		dcl_abandon_label();
		new_abandon_label();
		}
	adjust_iteration_usage();
	return( fctrl_error_test( fptr, 48, mode ) );
}

static	WORD	translate_invalid( mode )
WORD		mode;
{
	WORD		status;
	FCTRLPTR	fptr;
	WORD		error_value;

	trace("translate_invalid()\n");
	(void) is_mnemonic("KEY");
	if ((status = locate_fctrl_iteration()) != 0)
		return( status );
	if ( iteration_type() == _COBOL_WRITE )
		error_value = 81;
	else	error_value = 78;
	if ((fptr = (FCTRLPTR) get_iteration_context()) == (FCTRLPTR) 0)
		return( syntax_error(1011) );
	if ( iteration_usage() != 0 ) {
		generate_iteration();
		dcl_abandon_label();
		new_abandon_label();
		}
	adjust_iteration_usage();
	return( fctrl_error_test( fptr, error_value, mode ) );
}

static	WORD	translate_not()
{
	trace("translate_not()\n");
	if ( is_mnemonic("AT") )
		return( translate_at( _CMP_EQ ) );
	else if ( is_mnemonic("INVALID") )
		return( translate_invalid( _CMP_EQ ) );
	else	return( syntax_error(1012) );
}

WORD	handle_fctrl_exception(fptr,operation,direction)
FCTRLPTR	fptr;
WORD		operation;
WORD		direction;
{
	WORD		type;
	WORD		label;
	WORD		status;
	WORD		error_value;
	WORD		opcode;

	if ( operation == _COBOL_READ )
		type = _ITERATION_READ;
	else if ( operation == _COBOL_WRITE )
		type = _ITERATION_WRITE;
	else	type = _ITERATION_REWRITE;

	if (((status = enter_iteration( type,(TCVARPTR) 0  )) != 0)
	||  ((status = set_iteration_context( fptr )) != 0))
		return( status );

	/* Determine Exception Type */
	/* ------------------------ */
	if ( is_mnemonic("NOT") )
		return( translate_not() );

	if ( is_mnemonic("INVALID" ) )
		return( translate_invalid( _CMP_NE ) );
	else if ( is_mnemonic("AT" ) )
		return( translate_at( _CMP_NE ) ); 		
	else	return( 0 );

}

static	WORD	fctrl_error_trap( fptr )
FCTRLPTR	fptr;
{
	if ( fptr->status != (BPTR) 0 ) {
		strcat( CobolToAbal, ":" );
		strcat( CobolToAbal, "Next"   );
		strcat( CobolToAbal, "," );
		strcat( CobolToAbal, fptr->status );
		return( VRAI );
		}
	return( FAUX );
}

WORD	assign_chain_stop( h, n )
WORD	h;
BPTR	n;
{
	WORD	status;
	sprintf(CobolToAbal,"Assign=%u,%s ",h,n);
	if ((status = cobol_ngf_translate()) != 0)
		return( status );
	sprintf(CobolToAbal,"Chain=%u ",h);
	if ((status = cobol_ngf_translate()) != 0)
		return( status );
	return( generate_stop() );
}

WORD	assign_fctrl( fptr )
FCTRLPTR	fptr;
{
	WORD	status;

	if (!( fptr->nature & ( _CAN_OPEN | _CAN_CREATE ) ))
		return( 0 );

	sprintf(CobolToAbal,"Assign=%u,%s,WR ",fptr->handle,fptr->assign);
	switch ( fptr->nature ) {
		case _FCTRL_NATURE_FILE	:
			switch ( fptr->organisation ) {
				case _FCTRL_SEQUENTIAL :
					strcat( CobolToAbal, ",SQ " );
					break;
				case _FCTRL_INDEXED    :
					strcat( CobolToAbal, ",SI " );
					break;
				}
			break;
		case _FCTRL_NATURE_DISK	   :
			break;
		case _FCTRL_NATURE_PRINTER :
			strcat(CobolToAbal,",IM,EX,C ");
			break;
		default			   :
			return( 0 );
		}

	if ((status = fctrl_error_trap( fptr )) == MOINS_UN)
		return( not_yet_available() );
	else 	return((status = cobol_ngf_translate()));

}

WORD	open_fctrl( fptr )
FCTRLPTR	fptr;
{
	WORD	status;
	if (!( fptr->nature & _CAN_OPEN ))
		return(0);
	sprintf(CobolToAbal,"Open=%u",fptr->handle);
	if ((status = fctrl_error_trap( fptr )) == MOINS_UN)
		return( not_yet_available() );
	else	return( cobol_ngf_translate() );
}

WORD	fctrl_variable_length( nptr, adjust )
BPTR	nptr;
WORD	adjust;
{
	BYTE		buffer[16];
	VCTRLPTR	vptr;
	if ((vptr = locate_vctrl( nptr )) == (VCTRLPTR) 0)
		return( expected_variable() );
	else	{
		trace("fctrl_varlen(OK)\n");
		sprintf(buffer,"%u",(vptr->size+adjust));
		strcat(CobolToAbal,buffer);
		return(0);
		}
}

WORD	cfile_fctrl( fptr )
FCTRLPTR	fptr;
{
	WORD	status;
	if (!( fptr->nature & _CAN_CREATE ))
		return(0);
	sprintf(CobolToAbal,"Cfile=%u",fptr->handle);
	switch ( fptr->organisation ) {
		case _FCTRL_LINE        :
		case _FCTRL_RELATIVE	:
			break;
		case _FCTRL_INDEXED	:
			strcat(CobolToAbal,",D=");
			if ( fptr->recordbuf == (BPTR) 0 )
				strcat(CobolToAbal,"0");
			else if ((status = fctrl_variable_length( fptr->recordbuf,0 )) != 0)
				return( status );
			strcat(CobolToAbal,",K=");
			if ( fptr->recordkey == (BPTR) 0 )
				return( syntax_error(1013) );
			else if ((status = fctrl_variable_length( fptr->recordkey,0 )) != 0)
				return( status );
			break;
		case _FCTRL_SEQUENTIAL  :
			strcat(CobolToAbal,",D=");
			if ( fptr->recordbuf == (BPTR) 0 )
				strcat(CobolToAbal,"256");
			else if ((status = fctrl_variable_length( fptr->recordbuf,0 )) != 0)
				return( status );
			break;	
		}
	if ((status = fctrl_error_trap( fptr )) == MOINS_UN)
		return( not_yet_available() );
	else	return( cobol_ngf_translate() );
}

WORD	read_write_fctrl( fptr )
FCTRLPTR	fptr;
{
	WORD	status;
	trace("read_write_fctrl()\n");
	if ((status = fctrl_error_trap( fptr )) == MOINS_UN)
		return( not_yet_available() );
	if ( fptr->recordbuf != (BPTR) 0 ) {
		if ( status == FAUX )
			strcat(CobolToAbal,":");
		else	strcat(CobolToAbal,",");
		strcat(CobolToAbal,fptr->recordbuf);
		strcat(CobolToAbal,",");
		if ((status = fctrl_variable_length( fptr->recordbuf,0 )) != 0)
			return( status );
		}
	return( cobol_ngf_translate() );
}

WORD	fctrl_next_index( fptr )
FCTRLPTR	fptr;
{
	VCTRLPTR	vptr;
	TCVARPTR	tcvptr;
	RESULTPTR	rptr;
	RESULTPTR	zptr;
	if (( fptr != (FCTRLPTR) 0 )
	&&  ( fptr->recordkey != (BPTR) 0)
	&&  (( vptr = locate_vctrl( fptr->recordkey )) 	!= (VCTRLPTR)  0)
	&&  (( tcvptr = (TCVARPTR) vptr->contents)     	!= (TCVARPTR)  0)
	&&  (( rptr = variable_result( tcvptr ))     	!= (RESULTPTR) 0)
	&&  (( rptr = ensure_register( rptr    ))      	!= (RESULTPTR) 0)
	&&  (( zptr = integer_result( 1 ))		!= (RESULTPTR) 0)
	&&  (( rptr = evaluate_operation( '+', rptr, zptr)) != (RESULTPTR) 0))
		return( generate_affectation( tcvptr, rptr,VRAI ) );
	else	return( syntax_error(1014) );
}	

WORD	fctrl_this_index( fptr )
FCTRLPTR	fptr;
{
	VCTRLPTR	vptr;
	TCVARPTR	tcvptr;
	RESULTPTR	rptr;

	if (!( is_mnemonic("KEY") ))
		return( 0 );
	(void) is_mnemonic("IS");

	if (( fptr != (FCTRLPTR) 0 )
	&&  ( fptr->recordkey != (BPTR) 0)
	&&  (( vptr = locate_vctrl( fptr->recordkey )) 	!= (VCTRLPTR)  0)
	&&  (( tcvptr = (TCVARPTR) vptr->contents)     	!= (TCVARPTR)  0)
	&&  (( rptr   = evaluate_expression(0))		!= (RESULTPTR) 0))
		return( generate_affectation( tcvptr, rptr,VRAI ) );
	else	return( syntax_error(1015) );
}

WORD	reset_relative_index( fptr )
FCTRLPTR	fptr;
{
	VCTRLPTR	vptr;
	TCVARPTR	tcvptr;
	RESULTPTR	zptr;
	if (( fptr != (FCTRLPTR) 0 )
	&&  ( fptr->recordkey != (BPTR) 0)
	&&  (( vptr = locate_vctrl( fptr->recordkey )) 	!= (VCTRLPTR)  0)
	&&  (( tcvptr = (TCVARPTR) vptr->contents)     	!= (TCVARPTR)  0)
	&&  (( zptr = integer_result( 0 ))		!= (RESULTPTR) 0))
		return( generate_affectation( tcvptr, zptr,VRAI ) );
	else	return( syntax_error(1016) );
}	

WORD	sequential_fctrl( fptr, sens )
FCTRLPTR	fptr;
BPTR		sens;
{
	WORD	status;
	if ( fptr->recordkey == (BPTR) 0 )
		return( syntax_error(1017) );
	sprintf(CobolToAbal,"%s=%u,/FF",sens,fptr->handle);
	switch ((status = fctrl_error_trap( fptr ))) {
		case MOINS_UN 	:
			return( not_yet_available() );
		case FAUX	:
			strcat(CobolToAbal,":");
			break;
		case VRAI	:
			strcat(CobolToAbal,",");
			break;
		}
	strcat(CobolToAbal,fptr->recordkey);
	strcat(CobolToAbal,",");
	if ((status = fctrl_variable_length( fptr->recordkey, 1 )) != 0)
		return( status );
	else	return( cobol_ngf_translate() );
}

WORD	down_fctrl( fptr )
FCTRLPTR	fptr;
{
	return( sequential_fctrl( fptr, "Down" ) );
}

WORD	up_fctrl( fptr )
FCTRLPTR	fptr;
{
	return( sequential_fctrl( fptr, "Up" ) );
}

WORD	read_fctrl( fptr, sens )
FCTRLPTR	fptr;
WORD		sens;
{
	WORD	status;
	WORD	calcnext=FAUX;
	WORD	label=MOINS_UN;
	BPTR	function;

	if ( fptr->nature == _FCTRL_NATURE_DISK )
		function = "/40";
	else	function = "/60";

	trace("read_fctrl()\n");
	switch ( fptr->organisation ) {

		case _FCTRL_INDEXED	:

			switch ( fptr->access ) {

				case _FCTRL_SEQUENTIAL	:
					if ( sens == _COBOL_PREVIOUS ) {
						if ((status = up_fctrl(fptr)) != 0)
							return( status );
						label = new_implicite_label();
						if ((status = avoid_file_error(fptr,label,64,_CMP_EQ)) != 0)
							return( status );
						else	sprintf(CobolToAbal,"Search=%u,%s,/FF",fptr->handle,fptr->recordkey);
						}
					else	{
						if ((status = down_fctrl(fptr)) != 0)
							return( status );
						label = new_implicite_label();
						if ((status = avoid_file_error(fptr,label,48,_CMP_EQ)) != 0)
							return( status );
						else 	sprintf(CobolToAbal,"Search=%u,%s,/FF",fptr->handle,fptr->recordkey);
						}
					break;

				case _FCTRL_RANDOM 	:
					if ((status = fctrl_this_index()) != 0)
						return( status );
					sprintf(CobolToAbal,"Search=%u,%s,/FF",fptr->handle,fptr->recordkey);
					break;

				case _FCTRL_DYNAMIC	:
					if ( sens == _COBOL_NEXT ) {
						if ((status = down_fctrl(fptr)) != 0)
							return( status );
						label = new_implicite_label();
						if ((status = avoid_file_error(fptr,label,48,_CMP_EQ)) != 0)
							return( status );
						else	sprintf(CobolToAbal,"Search=%u,%s,/FF",fptr->handle,fptr->recordkey);
						}
					else if ( sens == _COBOL_PREVIOUS ) {
						if ((status = up_fctrl(fptr)) != 0)
							return( status );
						label = new_implicite_label();
						if ((status = avoid_file_error(fptr,label,64,_CMP_EQ)) != 0)
							return( status );
						else	sprintf(CobolToAbal,"Search=%u,%s,/FF",fptr->handle,fptr->recordkey);
						}
					else if ((status = fctrl_this_index()) != 0)
						return( status );
					else 	sprintf(CobolToAbal,"Search=%u,%s,/FF",fptr->handle,fptr->recordkey);
					break;
				}
			break;

		case _FCTRL_RELATIVE	:

			switch ( fptr->access ) {
				case _FCTRL_SEQUENTIAL	:
					calcnext = VRAI;
					break;
				case _FCTRL_DYNAMIC	:
					if  ( sens == _COBOL_NEXT ) {
						calcnext = VRAI;
						break;
						}
				case _FCTRL_RANDOM 	:
					if ((status = fctrl_this_index( fptr )) != 0 )
						return( status );
					break;
				}
			sprintf(CobolToAbal,"Read=%u,%s,%s",fptr->handle,function,fptr->recordkey);
			break;

		case _FCTRL_LINE        :
		case _FCTRL_SEQUENTIAL  :
			if ( fptr->nature == _FCTRL_NATURE_DISK )
				sprintf(CobolToAbal,"Read=%u,%s,%s",fptr->handle,function,fptr->recordkey);
			else	sprintf(CobolToAbal,"Read=%u",fptr->handle);
			break;
		}
	if ((status = read_write_fctrl( fptr )) != 0)
		return( status );
	else if (( calcnext )
	     &&  ((status = fctrl_next_index( fptr )) != 0))
		return( status );
	else if ( label != MOINS_UN )
	     	dcl_implicite_label( label );

	return( handle_fctrl_exception( fptr, _COBOL_READ, sens, _ITERATION_READ ) );
}

WORD	write_fctrl( fptr, mode, target )
FCTRLPTR	fptr;
WORD		mode;
VCTRLPTR	target;
{
	WORD		status;
	WORD		calcnext=FAUX;
	BYTE		buffer[16];
	BPTR		function;

	if ( fptr->nature == _FCTRL_NATURE_DISK )
		function = "/80";
	else	function = "/A0";

	switch ( fptr->organisation ) {

		case _FCTRL_INDEXED	:
			if ( mode  == _COBOL_WRITE )
				sprintf(CobolToAbal,"Insert=%u,",fptr->handle);
			else	sprintf(CobolToAbal,"Modif=%u,",fptr->handle);
			strcat(CobolToAbal,fptr->recordkey);
			break;

		case _FCTRL_RELATIVE	:
			switch ( fptr->access ) {
				case _FCTRL_SEQUENTIAL	:
					calcnext = VRAI;
					break;
				case _FCTRL_DYNAMIC	:
					if  ( mode == _COBOL_WRITE) {
						calcnext = VRAI;
						break;
						}
				case _FCTRL_RANDOM 	:
					break;
				}
			sprintf(CobolToAbal,"Write=%u,%s,%s",fptr->handle,function,fptr->recordkey);
			break;

		case _FCTRL_LINE        :
		case _FCTRL_SEQUENTIAL  :
			if ( fptr->nature == _FCTRL_NATURE_PRINTER ) {
				if ( mode != _COBOL_WRITE )
					return( syntax_error(1018) );
				else	sprintf(CobolToAbal,"Write=%u,%s,0",fptr->handle,function);
				}
			else if ( fptr->nature == _FCTRL_NATURE_DISK )
				sprintf(CobolToAbal,"Write=%u,%s,%s",fptr->handle,function,fptr->recordkey);
			else	{			
				if ( mode  == _COBOL_WRITE )
					sprintf(CobolToAbal,"Write=%u",fptr->handle);
				else	sprintf(CobolToAbal,"Modif=%u",fptr->handle);
				}
			break;
		}
	if ((status = fctrl_error_trap( fptr )) == MOINS_UN)
		return( not_yet_available() );
	if ( target != (VCTRLPTR) 0 ) {
		if ( status == FAUX )
			strcat(CobolToAbal,":");
		else	strcat(CobolToAbal,",");
		strcat(CobolToAbal,target->name);
		strcat(CobolToAbal,",");
		sprintf(buffer,"%u",target->size);
		strcat(CobolToAbal,buffer);
		}
	if ((status = cobol_ngf_translate()) != 0)
		return( status );
	else if (( calcnext )
	     &&  ((status = fctrl_next_index( fptr )) != 0))
		return( status );
	return( handle_fctrl_exception( fptr, mode, _COBOL_NEXT ) );
}

WORD	dfile_fctrl( fptr )
FCTRLPTR	fptr;
{
	WORD	status;
	if (!( fptr->nature & _CAN_CREATE ))
		return(0);
	sprintf(CobolToAbal,"Dfile=%u",fptr->handle);
	if ((status = fctrl_error_trap( fptr )) == MOINS_UN)
		return( not_yet_available() );
	else	return( cobol_ngf_translate() );


}

WORD	close_fctrl( fptr )
FCTRLPTR	fptr;
{
	WORD	status;
	if (!( fptr->nature & _CAN_OPEN ))
		return(0);
	sprintf(CobolToAbal,"Close=%u",fptr->handle);
	if ((status = fctrl_error_trap( fptr )) == MOINS_UN)
		return( not_yet_available() );
	else	return( cobol_ngf_translate() );
}

WORD	generate_fctrl_startup()
{
	WORD	status;
	FCTRLPTR	fptr;
	terminate_line_parser();
	if ((fptr = Cobol->SelectHeap) != (FCTRLPTR) 0) {
		do	{
			if ((status = assign_fctrl( fptr )) != 0)
				return( status );
			}
		while (( fptr = fptr->next ) != (FCTRLPTR) 0);
		}
	terminate_line_parser();
	return( 0 );
}

WORD	translate_fctrl_open()
{
	FCTRLPTR	fptr;
	WORD		mode=MOINS_UN;
	WORD		status;
	WORD		nombre=0;

	while (1)	{
		if ( is_mnemonic( "INPUT" ) )
			mode = _COBOL_INPUT;
		else if ( is_mnemonic( "OUTPUT" ) )
			mode = _COBOL_OUTPUT;
		else if ( is_mnemonic( "EXTEND" ) )
			mode = _COBOL_EXTEND;
		else if ( is_mnemonic( "I-O" ) )
			mode = _COBOL_I_O;
		else if ( mode == MOINS_UN )
			return( syntax_error(1019) );

		if (!( get_token() ))	{
			if ( nombre  )
				return( xverify_period() );
			else	return( syntax_error(1020) );
			}
		else if ((fptr = locate_fctrl( TokenBuffer )) != (FCTRLPTR) 0) {
			if ((!( fptr->nature & _CAN_WRITE ))
			&&  ( mode != _COBOL_INPUT  ))
				return( syntax_error(1021) );

			if ((!( fptr->nature & _CAN_READ  ))
			&&  (( mode == _COBOL_INPUT  ) 
			  || ( mode == _COBOL_I_O    )
			  || ( mode == _COBOL_EXTEND )))
				return( syntax_error(1022) );

			if ((status = create_records( fptr )) != 0 )
				return( status );
			nombre++;
			switch ( mode ) {
				case _COBOL_INPUT	:
					if ((status = open_fctrl( fptr )) != 0)
						return( status );
					break;
				case _COBOL_OUTPUT	:
					if (!( fptr->nature & _CAN_CREATE )) {
						if ((status = open_fctrl( fptr )) != 0)
							return( status );
						}
					else if ((status = dfile_fctrl( fptr )) != 0)
						return( status );
					else if ((status = cfile_fctrl( fptr )) != 0)
						return( status );
					break;
				case _COBOL_EXTEND	:
				case _COBOL_I_O		:
					if (!( fptr->nature & _CAN_CREATE )) {
						if ((status = open_fctrl( fptr )) != 0)
							return( status );
						}
					else if ((status = cfile_fctrl( fptr )) != 0)
						return( status );
					break;
				}
			if ( fptr->organisation == _FCTRL_RELATIVE )
				if ((status = reset_relative_index( fptr )) != 0)
					return( status );
			}
		else if ( nombre )
			return( unget_token()  );
		else	return( syntax_error(1023) );
		}
}

WORD	translate_fctrl_close()
{
	FCTRLPTR	fptr;
	WORD		status;
	trace("translate_fctrl_close()\n");
	while (1) {
		if (!( get_token() ))
			return( xverify_period() );
		else if ((fptr = locate_fctrl( TokenBuffer )) != (FCTRLPTR) 0) {
			if ((status = close_fctrl( fptr )) != 0)
				return( status );
			if ( Cobol->version & _COBOL_ANS74 ) {
				(void) is_mnemonic("REEL");
				(void) is_mnemonic("UNIT");
				}
			if ((status = remove_records( fptr )) != 0 )
				return( status );
			}
		else	return( unget_token() );
		}
}

WORD	translate_fctrl_read()
{
	FCTRLPTR	fptr;
	WORD		status;
	WORD		sens=MOINS_UN;
	VCTRLPTR	target=(VCTRLPTR) 0;
	VCTRLPTR	source=(VCTRLPTR) 0;

	if ((!(get_token()))
	||  ((fptr = locate_fctrl( TokenBuffer )) == (FCTRLPTR) 0))
		return( syntax_error(1024) );

	if (!( fptr->nature & _CAN_READ ))
		return( syntax_error(1025) );

	if ( is_mnemonic("NEXT") )
		sens = _COBOL_NEXT;
	else if ( is_mnemonic("PREVIOUS") )
		sens = _COBOL_PREVIOUS;

	(void) is_mnemonic("RECORD");
	
	/* Translate possible INTO <variable> clause */
	/* ----------------------------------------- */
	if ( is_mnemonic("INTO") ) {
		if  ((!( get_token() ))
		||   ((target = locate_vctrl( TokenBuffer )) == (VCTRLPTR) 0))
			return( expected_variable() );
		}

	if ((status = read_fctrl( fptr, sens )) != 0)
		return( status );

	/* Generate possible INTO <variable> clause */
	/* ---------------------------------------- */
	if ( target != (VCTRLPTR) 0 ) {
		if ((source = locate_vctrl( fptr->recordbuf )) == (VCTRLPTR) 0)
			return( syntax_error(1025) );
		if ((!( target->contents))
		||  (!( source->contents)))
			return( internal_error() );
		else if ((status = variable_to_variable( source->contents, target->contents )) != 0)
			return( status );
		}
	return( xverify_period() );
}

static WORD	print_fctrl_options( mptr )
BPTR	mptr;
{
	WORD	status;
	while ( is_mnemonic( mptr ) ) {
		(void) is_mnemonic("ADVANCING");
		if ( is_mnemonic("PAGE") ) {
			if ((status = translate_iof_clear()) != 0)
				return( status );
			}
		else if ((status = store_iof_tabv( evaluate_expression(0) )) != 0)
			return( status );
		else	{
			(void) is_mnemonic("LINE");
			(void) is_mnemonic("LINES");
			}
		}
	return( 0 );
}

WORD	print_fctrl( fptr, vptr )
FCTRLPTR	fptr;
VCTRLPTR	vptr;
{
	RESULTPTR	target;
	WORD		status;
	trace("print_fctrl()\n");

	if ((status = start_iof()) != 0 )
		return( status );

	else if ((status = print_fctrl_options("AFTER")) != 0)
		return( status );

	else if ((status = store_iof_prn(variable_result( vptr->contents) )) != 0)
		return( status );

	else if ((status = print_fctrl_options("BEFORE")) != 0)
		return( status );

	else if ( fptr->nature & _CAN_OPEN )
		target = integer_result( fptr->handle );
	else	target = integer_result( 1 );

	if (target == (RESULTPTR) 0)
		return( allocation_failure() );
	else	return( flush_print( target, VRAI ) );	
}

WORD	translate_fctrl_write(mode)
WORD	mode;
{
	FCTRLPTR	fptr;
	WORD		status;
	VCTRLPTR	target=(VCTRLPTR) 0;
	VCTRLPTR	source=(VCTRLPTR) 0;

	if ((!(get_token()))
	||  ((target = locate_vctrl( TokenBuffer )) == (VCTRLPTR) 0)
	||  ((fptr   = (FCTRLPTR) target->fichier)  == (FCTRLPTR) 0))
		return( syntax_error(1025) );
	
	if ((!( fptr->nature & _CAN_WRITE ))
	||  ( ( mode ==_COBOL_REWRITE )
	   && (!( fptr->nature & _CAN_READ  )) ))
		return( syntax_error(1025) );

	/* Translate possible FROM <variable> clause */
	/* ----------------------------------------- */
	if ( is_mnemonic("FROM") ) {
		if  ((!( get_token() ))
		||   ((source = locate_vctrl( TokenBuffer )) == (VCTRLPTR) 0))
			return( expected_variable() );
		}

	/* Generate possible FROM <variable> clause */
	/* ---------------------------------------- */
	if ( source != (VCTRLPTR) 0 ) {
		if ((!( target->contents ))
		||  (!( source->contents )))
			return( internal_error() );
		if ((status = variable_to_variable( source->contents, target->contents )) != 0)
			return( status );
		}

	if ( fptr->nature & _CAN_CREATE ) {
		if ((status = write_fctrl( fptr, mode, target )) != 0)
			return( status );
		}
	else if ((status = print_fctrl( fptr, target )) != 0)
		return( status );

	return( xverify_period() );
}

WORD	translate_fctrl_delete()
{
	FCTRLPTR	fptr;
	WORD		status;
	if ((!(get_token()))
	||  ((fptr = locate_fctrl( TokenBuffer )) == (FCTRLPTR) 0))
		return( syntax_error(1025) );
	if (!( fptr->nature & _CAN_WRITE ))
		return( syntax_error(1025) );

	(void) is_mnemonic("RECORD");
	return( xverify_period() );
}


WORD	translate_fctrl_start()
{
	FCTRLPTR	fptr;
	RESULTPTR	vptr=(RESULTPTR) 0;
	TCVARPTR	tcvptr;
	WORD		status;
	WORD		operation=_CMP_EQ;

	trace("translate_start()\n");
	if ((!(get_token()))
	||  ((fptr = locate_fctrl( TokenBuffer )) == (FCTRLPTR) 0))
		return( syntax_error(1025) );

	if (!( fptr->nature & _CAN_READ ))
		return( syntax_error(1025) );

	if ( is_mnemonic("KEY") ) {
		if (((vptr = resolve_vctrl( fptr->recordkey )) == (RESULTPTR) 0)
		||  ((tcvptr = (TCVARPTR) vptr->contents) == (TCVARPTR) 0))
			return( expected_variable() );
		operation = comparison_operator(0);
		if ((!( get_token() ))
		||  ((vptr = resolve_vctrl( TokenBuffer )) == (RESULTPTR) 0))
			return( expected_variable() );
		if ((status = generate_affectation(tcvptr , vptr,VRAI)) != 0)
			return( status );
		}
	switch ( fptr->organisation ) {

		case _FCTRL_INDEXED	:
			sprintf(CobolToAbal,"Search=%u,%s,/FF",fptr->handle,fptr->recordkey);
			break;
		case _FCTRL_RELATIVE	:
			sprintf(CobolToAbal,"Read=%u,/60,%s",fptr->handle,fptr->recordkey);
			break;
		case _FCTRL_LINE        :
		case _FCTRL_SEQUENTIAL  :
			return( syntax_error(1025) );
		}

	if ((status = read_write_fctrl( fptr )) != 0)
		return( status );
	else	return( handle_fctrl_exception( fptr, _COBOL_READ, MOINS_UN, _ITERATION_START ) );
}

/*
 *
 *	ASSIGN to PRINTER   [ <device_name> ] { ENV("LO")   }
 *	ASSIGN to PRINTER-1 [ <device_name> ] { ENV("PRN")  }
 *
 *	ASSIGN to DISPLAY   [ <device_name> ] { ENV("CO")   }
 *	ASSIGN to KEYBOARD  [ <device_name> ] { ENV("CI")   }
 *
 *	ASSIGN to DEVICE    [ <device_name> ] { ENV("IF")   }
 *	ASSIGN to DEVICE-1  [ <device_name> ] { ENV("IP")   }
 *	ASSIGN to DEVICE-2  [ <device_name> ] { ENV("IS")   }
 *
 *	ASSIGN to DISK	    [ <filename>    ] { DISK        }
 *	ASSIGN to <filename>
 *
 */

WORD	translate_file_assign()
{
	FCTRLPTR	fptr;
	if ((fptr = Cobol->SelectHeap) == (FCTRLPTR) 0)
		return( syntax_error(1025) );

	(void) is_mnemonic("TO");

	if ( is_mnemonic("PRINTER") ) {
		if (!( get_token() ))
			strcpy(TokenBuffer,"ENV(\"LO\")");
		fptr->nature = _FCTRL_NATURE_PRINTER;
		}
	else if ( is_mnemonic("PRINTER-1") ) {
		if (!( get_token() ))
			strcpy(TokenBuffer,"ENV(\"PRN\")");
		fptr->nature = _FCTRL_NATURE_PRINTER;
		}
	else if ( is_mnemonic("DISPLAY") ) {
		if (!( get_token() ))
			strcpy(TokenBuffer,"ENV(\"CO\")");
		fptr->nature = _FCTRL_NATURE_CO;
		}
	else if ( is_mnemonic("KEYBOARD") ) {
		if (!( get_token() ))
			strcpy(TokenBuffer,"ENV(\"CI\")");
		fptr->nature = _FCTRL_NATURE_CI;
		}
	else if ( is_mnemonic("DISK") )	{
		if (!( get_token() ))
			strcpy(TokenBuffer,"DISK");
		fptr->nature = _FCTRL_NATURE_FILE;
		}
	else if ( is_mnemonic("DEVICE") )	{
		if (!( get_token() ))
			strcpy(TokenBuffer,"ENV(\"IF\")");
		fptr->nature = _FCTRL_NATURE_DISK;
		}
	else if ( is_mnemonic("DEVICE-1") )	{
		if (!( get_token() ))
			strcpy(TokenBuffer,"ENV(\"IP\")");
		fptr->nature = _FCTRL_NATURE_DISK;
		}
	else if ( is_mnemonic("DEVICE-2") )	{
		if (!( get_token() ))
			strcpy(TokenBuffer,"ENV(\"IS\")");
		fptr->nature = _FCTRL_NATURE_DISK;
		}
	else if (!( get_token() ))
		return( syntax_error(1025) );
	else	fptr->nature = _FCTRL_NATURE_FILE;

	/* Token Buffer Contains FileName Operand */
	/* -------------------------------------- */
	if ((fptr->assign = allocate_for_string( TokenBuffer )) == (BPTR) 0)
		return( allocation_failure() );
	else	return( 0 );
}

/*
 *
 *	ORGANIZATION is [ LINE ] SEQUENTIAL
 *
 *	ORGANIZATION is INDEXED
 *
 *	ORGANIZATION is RELATIVE
 *
 */

WORD	translate_file_organization()
{
	WORD	type;
	FCTRLPTR	fptr;
	if ((fptr = Cobol->SelectHeap) == (FCTRLPTR) 0)
		return( syntax_error(1025) );

	(void) is_mnemonic("IS");

	if (!( get_token() ))
		return( syntax_error(1025) );

	switch ((type = is_fctrl_keyword())) {
		case _FCTRL_LINE        :
			if ((!( get_token() ))
			||  ( is_fctrl_keyword() != _FCTRL_SEQUENTIAL ))
				return( expected_keyword("SEQUENTIAL") );
			fptr->organisation = type;		
			return( 0 );

		case _FCTRL_INDEXED	:
			if ( fptr->nature == _FCTRL_NATURE_DISK )
				return( syntax_error(1025) );

		case _FCTRL_RELATIVE	:
			if ( fptr->nature == _FCTRL_NATURE_PRINTER )
				return( syntax_error(1025) );
								
		case _FCTRL_SEQUENTIAL  :
			fptr->organisation = type;		
			return( 0 );
		default			:
			return( syntax_error(1025) );
		}
}

/*
 *
 *	file STATUS is <variable>
 *
 */


WORD	translate_file_status()
{
	FCTRLPTR	fptr;
	if ((fptr = Cobol->SelectHeap) == (FCTRLPTR) 0)
		return( syntax_error(1025) );

	(void) is_mnemonic("IS");

	if (!( get_token() ))
		return( syntax_error(1025) );

	/* Token Buffer Contains Error Variable */
	/* ------------------------------------ */
	if ((fptr->status = allocate_for_string( TokenBuffer )) == (BPTR) 0)
		return( allocation_failure() );
	else	return( 0 );
}

/*
 *
 *	ALTERNATE RECORD key is <variable> with DUPLICATES
 *
 */

WORD	translate_secondary_index()
{
	FCTRLPTR	fptr;
	WORD		duplique=FAUX;

	if ((fptr = Cobol->SelectHeap) == (FCTRLPTR) 0)
		return( syntax_error(1025) );

	if (!( is_mnemonic( "RECORD" ) ))
		return( expected_keyword("RECORD") );

	(void) is_mnemonic("KEY");
	(void) is_mnemonic("IS");

	while (1) {

		(void) is_mnemonic("WITH");
		if ((duplique = is_mnemonic("DUPLICATES")) != FAUX)
			break;

		if (!( get_token() ))
			break;

		}

	return( 0 );
}


/*
 *
 *	RECORD    key is <variable>
 *
 *	RELATIVE  key is <variable>
 *
 */

WORD	translate_primary_index()
{
	FCTRLPTR	fptr;

	if ((fptr = Cobol->SelectHeap) == (FCTRLPTR) 0)
		return( syntax_error(1025) );

	(void) is_mnemonic("KEY");
	(void) is_mnemonic("IS");

	if (!( get_token() ))
		return( syntax_error(1025) );

	/* Token Buffer Contains Cle Variable */
	/* ---------------------------------- */
	if ((fptr->recordkey = allocate_for_string( TokenBuffer )) == (BPTR) 0)
		return( allocation_failure() );
	else	return( 0 );
}

/*
 *
 *	ACCESS mode is	SEQUENTIAL
 * 
 *	ACCESS mode is	RANDOM    
 *
 *	ACCESS mode is	DYNAMIC
 *
 */

WORD	translate_file_access()
{
	WORD		type;
	FCTRLPTR	fptr;
	if ((fptr = Cobol->SelectHeap) == (FCTRLPTR) 0)
		return( syntax_error(1025) );

	(void) is_mnemonic("MODE");
	(void) is_mnemonic("IS");

	if (!( get_token() ))
		return( syntax_error(1025) );
	
	switch (( type = is_fctrl_keyword()) ) {
		case _FCTRL_SEQUENTIAL	:
		case _FCTRL_RANDOM 	:
		case _FCTRL_DYNAMIC	:
			fptr->access = type;
			return( 0 );
		default			:
			return( syntax_error(1025) );
		}
}

/*
 *
 *	PASSWORD is <vn>
 *
 */

WORD	translate_file_password()
{
	WORD		type;
	FCTRLPTR	fptr;
	if ((fptr = Cobol->SelectHeap) == (FCTRLPTR) 0)
		return( syntax_error(1025) );

	(void) is_mnemonic("IS");

	if (!( get_token() ))
		return( syntax_error(1025) );

	return( 0 );
}

/*
 *
 *	SELECT <logical_filename>
 *
 */

WORD	translate_file_select()
{
	FCTRLPTR	fptr;
	WORD		type;
	if ((fptr = Cobol->SelectHeap) == (FCTRLPTR) 0)
		return( syntax_error(1025) );
	if ( is_period() ) {
		pop_operation_pointer();
		return(0);
		}
	if (!( get_token() ))
		return( syntax_error(1025) );

	switch ((type = is_fctrl_keyword())) {
		case _FCTRL_ASSIGN	:
			return( translate_file_assign() );
		case _FCTRL_ORGANIZATION:
			return( translate_file_organization() );
		case _FCTRL_ACCESS	:
			return( translate_file_access() );
		case _FCTRL_FILE	:
			if ((!( get_token()))
			||  ((type = is_fctrl_keyword()) != _FCTRL_STATUS ))
				return( expected_keyword("STATUS") );
		case _FCTRL_STATUS	:
			return( translate_file_status() );
		case _FCTRL_RELATIVE    :
		case _FCTRL_RECORD	:
			return( translate_primary_index() );
		case _FCTRL_ALTERNATE	:
			return( translate_secondary_index() );
		case _FCTRL_PASSWORD	:
			return( translate_file_password() );
		case _FCTRL_INDEXED	:
		case _FCTRL_SEQUENTIAL	:
		case _FCTRL_RANDOM	:
		case _FCTRL_DYNAMIC	:
		default			:
			return( syntax_error(1025) );
		}
}

WORD	locate_iteration( mode )
WORD	mode;
{
	WORD	type;
	while ((type = iteration_type()) != mode ) {
		if (type) 
			leave_iteration();
		else	return( syntax_error(1025) );
		}
	return(0);
}

static	WORD	translate_end_read()
{
	WORD	status;
	trace("translate_end_read()\n");
	if ((status = locate_iteration( _ITERATION_READ )) != 0)
		return( status );
	else	leave_iteration();
	return( xverify_period() );
}

static	WORD	translate_end_write()
{
	WORD	status;
	if ((status = locate_iteration( _ITERATION_WRITE )) != 0)
		return( status );
	else	leave_iteration();
	return( xverify_period() );
}

static WORD	translate_end_rewrite()
{
	WORD	status;
	if ((status = locate_iteration( _ITERATION_REWRITE )) != 0)
		return( status );
	else	leave_iteration();
	return( xverify_period() );
}

static WORD	translate_end_start()
{
	WORD	status;
	if ((status = locate_iteration( _ITERATION_START )) != 0)
		return( status );
	else	leave_iteration();
	return( xverify_period() );
}

static WORD	translate_end_delete()
{
	WORD	status;
	if ((status = locate_iteration( _ITERATION_DELETE )) != 0)
		return( status );
	else	leave_iteration();
	return( xverify_period() );
}



WORD	translate_ngf_statement()
{
	WORD	type;
	switch ((type = is_ngf_statement())) {
		case	_COBOL_OPEN	:
			return( translate_fctrl_open() );
		case	_COBOL_CLOSE	:
			return( translate_fctrl_close() );
		case	_COBOL_READ	:
			return( translate_fctrl_read() );
		case	_COBOL_WRITE	:
			return( translate_fctrl_write(type) );
		case	_COBOL_REWRITE	:
			return( translate_fctrl_write(type) );
		case	_COBOL_START  	:
			return( translate_fctrl_start() );
		case	_COBOL_DELETE 	:
			return( translate_fctrl_delete() );
		case	_COBOL_END_READ	 	:
			return( translate_end_read() );
		case	_COBOL_END_WRITE 	:
			return( translate_end_write() );
		case	_COBOL_END_REWRITE	:
			return( translate_end_rewrite() );
		case	_COBOL_END_START	:
			return( translate_end_start() );
		case	_COBOL_END_DELETE	:
			return( translate_end_delete() );
		case	_COBOL_AT		:
			return( translate_at( _CMP_NE ) );
		case	_COBOL_INVALID		:
			return( translate_invalid(_CMP_NE) );
		case	_COBOL_NOT		:
			return( translate_not() );
		default			:
			return( MOINS_UN );
		}
}


#endif	/* _TRFCTRL_C */
	/* ---------- */

