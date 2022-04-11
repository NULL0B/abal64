#define	DEBUG
/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRCLF.C    				*/
/*		Version :	2.1c					*/
/*		Date	:	17/10/1996				*/
/*									*/
/* --------------------------------------------------------------------	*/
/*	17/10/1996 : 	Correction to allow V = Proc Ptr <procedure>	*/
/*			which previously returned an error 1090 due	*/
/*			to incorrect CLF parameter for storage.		*/
/* --------------------------------------------------------------------	*/
/*	20/01/2004 :	Implementation of CLF 1 TRACE Functions		*/
/* --------------------------------------------------------------------	*/

#ifndef	_TRCLF_C
#define	_TRCLF_C

/*	Syntax Errors	:	700	to	723			*/
/*	-------------------------------------------			*/

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include <string.h>		/* string functions */
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
#include "trnurone.h"
#include "trdebug.h"
#include "trproc.h"
#include "triof.h"
#include "troutput.h"	
#include "trmethod.h"	
#include "trshadow.h"	
#include "trecho.h"		
#include "trcometh.h"	
#include "trngf.h"		
#include "trtables.h"	
#include "trinput.h"		
#include "trabal.h"		

#ifndef	UNIX
#else
BPTR		source_file_name();
BPTR		convert_explicite_format();
RESULTPTR	build_string_constant();
RESULTPTR	build_numeric_term();
RESULTPTR	variable_operand();
RESULTPTR	translate_class_name();
RESULTPTR	translate_object_name();
RESULTPTR	translate_class_number();
RESULTPTR	translate_object_number();
RESULTPTR	translate_sizeof();
#endif

EXTERN	BYTE	KeyWord[65];
EXTERN	WORD	KeyWordHash;

#include "trarg.c"

static	WORD	UseDimensions=VRAI;

WORD	use_dimensions()
{
	return( UseDimensions );
}

static	RESULTPTR	make_clf_target( CLFPTR xptr );


static	RESULTPTR	make_target_register(mode)
WORD	mode;
{
	RESULTPTR	tptr=(RESULTPTR) 0;
	if ((tptr = next_free_register()) != (RESULTPTR) 0)
		(void) set_shadow_type( tptr->contents, mode );
	else	(void) syntax_error(233);
	return(tptr);
}

static	CLFPTR	start_clf( type, group )
WORD	type;
WORD	group;
{
	CLFPTR	xptr;
	if ((xptr = (CLFPTR) allocate( sizeof( struct clf_context ))) != (CLFPTR) 0) {
		xptr->code = type;
		xptr->group = group;
		xptr->last = xptr->root = (ARGPTR) 0;
		xptr->Target=(RESULTPTR) 0;
		xptr->Error=(RESULTPTR) 0;
		xptr->ErrorFlag  = MOINS_UN;
		xptr->ErrorAdr   = MOINS_UN;
		memset(xptr->ErrorLabel, 0, _MAX_ERROR_LABEL );
		memset(xptr->descriptor,0,_MAX_CLF_DESCRIPTOR);
		switch ( xptr->group ) {
			case	6	:
				if ( xptr->code == 15 )
					xptr->code = 3;
				else	xptr->Target = make_clf_target( xptr );
				break;

			case	1	:
			case	7	:
			case	16	: 
				break;
			case	0x0E	:	/* MOD		*/
				if ( xptr->code != 9 )
					xptr->Target = make_clf_target( xptr );
				break;

			case	13	:
				switch ( xptr->code ) {
					case	_CLF_PROC	:
					case	_CLF_USER	:
					case	_CLF_SEGM	:
						break;
					}
			default		:
				xptr->Target = make_clf_target( xptr );
			}
		}
	return( xptr );
}

VOID	release_clf_context( xptr )
CLFPTR	xptr;
{
	if ( xptr != (CLFPTR) 0) {
		release_operands( xptr->root );
		liberate( xptr );
		}
	return;
}

WORD	release_void_context( xptr, status )
CLFPTR	xptr;
WORD	status;
{
	release_clf_context( xptr );
	return( status );
}

RESULTPTR	release_context( xptr, rptr )
CLFPTR		xptr;
RESULTPTR	rptr;
{
	release_clf_context( xptr );
	return( rptr );
}

static	WORD	flush_clf_error_trap(CLFPTR xptr)
{
	if ((xptr->ErrorFlag != MOINS_UN )
	&&  (xptr->Error     != (RESULTPTR) 0)) {
		if ((xptr->Error = mark_dead_result( xptr->Error )) == (RESULTPTR) 0)
			return( internal_error(5) );
		if ( xptr->ErrorFlag != 0  )
			return( implicite_on_error( xptr->Error->contents, _CTRL_LOCAL, xptr->ErrorAdr  ) );
		else	return( explicite_on_error( xptr->Error->contents, _CTRL_BREAK, xptr->ErrorLabel ) );
		}
	return( 0 );
}


static	WORD	flush_clf_descriptors(xptr, rptr )
CLFPTR		xptr;
RESULTPTR	rptr;
{
	WORD		i=0;
	WORD		phase;
	WORD		descriptor;
	WORD		d;
	RESULTPTR	lparam;
	WORD		n=0;
	ARGPTR		cptr;
	WORD	status;

	if ((status = flush_clf_error_trap(xptr)) != 0)
		return(status);

	else if ( rptr != (RESULTPTR) 0) {
		if (( rptr = mark_live_result( rptr )) == (RESULTPTR) 0)
			return( internal_error(1) );
		xptr->descriptor[0] = (( rptr->nature & _RESULT_NATURE) << 5 );
		n=1;
		}
	else	n=0;

	if ((cptr = xptr->root) != (ARGPTR) 0) {
		cptr = xptr->last;
		do	{
			if ((lparam = cptr->operand) != (RESULTPTR) 0) {
				/* ----------------------------------------- */
				/* IJM : 09/01/1998 MOVE,SWAP,FIX TABLES etc */
				/* ----------------------------------------- */
				/* This code has been added since this date  */
				/* to ensure that expressions resembling     */
				/*    VAR(index1) = MOVE(VAR(index2),etc)    */
				/* Which operates on a MEMORY result in the  */
				/* form of VAR(index1) do not give rise to   */
				/* incorrect code. Previously the index      */
				/* loaded for the parameter VAR(index2) was  */
				/* loaded into the Register ZERO which over  */
				/* wrote the index expression for the result */
				/* variable and the expression became        */
				/*    VAR1(index2) = MOVE(VAR2(index2),etc)  */
				/* Which does not amount to the same thing   */
				/* ----------------------------------------- */
				if ( rptr != (RESULTPTR) 0 )
					/* ------------------------------- */
					/* Dimensioned Variables : REG > 0 */
					/* ------------------------------- */
					cptr->operand = mark_dead_result( lparam );

				else if ( cptr->prev != (ARGPTR) 0 )

					/* ------------------------------- */
					/* Dimensioned Variables : REG > 0 */
					/* ------------------------------- */
					cptr->operand = mark_dead_result( lparam );

					/* ------------------------------- */
					/* Dimensioned Variables : REG = 0 */
					/* ------------------------------- */
				else	cptr->operand = mark_dead_target( lparam );

				}
			}
		while ((cptr = cptr->prev) != (ARGPTR) 0);
		cptr = xptr->root;
		do	{
			/* Calculate descriptor access information */
			/* --------------------------------------- */
			phase = (n & 1);
			descriptor = (n/2);

			if ( cptr->format == (BPTR) 0 ) {
				if ((lparam = cptr->operand) == (RESULTPTR) 0)
					return( syntax_error(701) );
		
				/* Check for dimensioned */
				/* --------------------- */
				if (( xptr->code == 5 )
			     	&&  ( xptr->group == 10 )) {
					if  (lparam->nature == _RESULT_EXPR)
						xptr->code = 6;
					}

				/* Indicate more parameters to follow */
				/* ---------------------------------- */
				if ( phase )
					xptr->descriptor[descriptor]     |= 0x0010;
				else if ( descriptor )
					xptr->descriptor[(descriptor-1)] |= 0x0001;

				/* Establish Parameter Nature */
				/* -------------------------- */  
				if (!( phase ))
					xptr->descriptor[descriptor]  = ((lparam->nature & _RESULT_NATURE) << 5);
				else	xptr->descriptor[descriptor] |= ((lparam->nature & _RESULT_NATURE) << 1);
				}
			else if (( xptr->code == 5 )
			     &&  ( xptr->group == 10 ))
				xptr->code = 7;
			n++;
			}
		while ((cptr = cptr->next) != (ARGPTR) 0);
		}

	i = 0;

	/* generate target zero dimensions now */
	/* ----------------------------------- */
	if ((rptr != (RESULTPTR) 0) 
	&&  ((rptr->nature & _RESULT_BASIC) == _RESULT_VARB)) {
		if ( xptr->group != 6 )
			generate_dimensions(0, rptr->contents );
		}

	if ( generate_clf( xptr->code, xptr->group )  == 0) {
		/* CLF FM : No Argument Descriptors Needed */
		if (( xptr->group == 10 )
		&&  (( xptr->code >= 5 )
		&&   ( xptr->code <= 7 )))
			return( 0 );

/*
		if ( xptr->group == 1 )
			{
			tcputbyte(xptr->data);
			set_accelerator_begin();
			tcputword(0);
			}
*/

		while ( 1 ) {
			tcputbyte((d = xptr->descriptor[i]));
			if ( d & 1 )
				i++;
			else	break;
			}
		}
	return(0);
}

static	WORD	flush_clf_parameter(lparam)
RESULTPTR	lparam;
{
	if (lparam == (RESULTPTR) 0)
		return( syntax_error(702) );
	else	tcode_operand( lparam );
	return( 0 );
}

VOID	flush_clf_format( fptr )
BPTR	fptr;
{
	WORD	l;
	l = *(fptr++);
	generate_byte( l );
	while ( l ) {
		generate_byte( *(fptr++) );
		l--;
		}
	return;
}

static	WORD	flush_clf_parameters(xptr, rptr )
CLFPTR		xptr;
RESULTPTR	rptr;
{
	ARGPTR		cptr;
	WORD		status=0;
	if ( rptr != (RESULTPTR) 0)
		flush_clf_parameter( rptr );

	if ((cptr = xptr->root) != (ARGPTR) 0) {
		do	{
			if ( cptr->format != (BPTR) 0 ) 
				flush_clf_format( cptr->format );
			else if ((status = flush_clf_parameter( cptr->operand )) != 0)
				return( status );
			}
		while ((cptr = cptr->next) != (ARGPTR) 0);
		}

	if ( xptr->ErrorFlag != MOINS_UN ) {
		if ( xptr->ErrorFlag != 0 ) {
			if ((status = dcl_implicite_label( xptr->ErrorAdr )) != 0)
				return(status);
			else	return( generate_error_abort() );
			}
		}
	return(	0 );
}

static	VOID	echo_clf( xptr, target )
CLFPTR		xptr;
RESULTPTR	target;
{
	ARGPTR		cptr;
	WORD		status=0;
	WORD		voidflag=1;

	if (target != (RESULTPTR) 0) {
		if  ((target->nature == _RESULT_EXPR)
		||   (target->nature == _RESULT_ALEXPR)
		||   (target->nature == _RESULT_ALIAS))
			voidflag = 0;
		}

	if (!( echo_start(voidflag) ))
		return;

	if ( target != (RESULTPTR) 0 ) {
		if ( voidflag ) {
			echo_operand( target );
			echo_equals();
			}
		}

	cptr = xptr->root;

	switch ( xptr->group ) {
		case	5 	: echo_keyword( clf5_keywords[ xptr->code ] ); break;
		case	6 	:
			if ( xptr->code == 3 ) {
				if (( (cptr->operand->nature & _RESULT_BASIC) == _RESULT_VARB )
				&&  ( cptr->operand->next   != (RESULTPTR) 0)) {
					echo_operand( cptr->operand );
					echo_equals();
					cptr = cptr->next;
					}
				echo_keyword( clf5_keywords[ 1 ] );
				}
			else	{
				echo_keyword( clf6_keywords[ xptr->code ] );
				echo_operand( cptr->operand );
				cptr = cptr->next;
				}
			break;

		case	7 	: echo_keyword( clf7_keywords[ xptr->code ] ); break;
		case	8 	: echo_keyword( clf8_keywords[ xptr->code ] ); break;
		case	9 	: echo_keyword( clf9_keywords[ xptr->code ] ); break;
		case	0x000a  : echo_keyword( clfa_keywords[ xptr->code ] ); break;
		case	0x000b  : echo_keyword( clfb_keywords[ xptr->code ] ); break;
		case	0x000c  : echo_keyword( clfc_keywords[ xptr->code ] ); break;

		case	0x000d  : 
#ifdef	WHAT_THE_FUCK_IS_THIS_FOR
			if (( xptr->code >= _CLFD_PROC ) && ( xptr->code <= _CLFD_SEGM)) {
				echo_operand( cptr->operand );
				echo_equals();
				cptr = cptr->next;
				}
#endif
			echo_keyword( clfd_keywords[ xptr->code ] );

			if (( xptr->code >= _CLFD_PROC ) && ( xptr->code <= _CLFD_SEGM))
				echo_keyword( "PTR" );
			if ( xptr->code == _CLFD_PROC ) {
				if (( cptr ) 
				&&  ( cptr->operand )) {
					echo_procedure_name( cptr->operand );
					cptr = cptr->next;
					}
				}
			break;

		case	0x000e  : echo_keyword( clfe_keywords[ xptr->code ] ); break;
		case	0x000f  : echo_keyword( clff_keywords[ xptr->code ] ); break;
		}

	if (cptr != (ARGPTR) 0) {
		echo_left_brace();
		while (1) {
			if ( cptr->format != (BPTR) 0 ) 
				echo_format( cptr->format );
			else 	echo_operand( cptr->operand );
			if ((cptr = cptr->next) != (ARGPTR) 0)
				echo_comma();
			else	break;
			}
		echo_right_brace();
		}
	echo_line();
	if (!( voidflag ))
		set_shadow_text( target->contents );
	return;
}

static	WORD	flush_void_clf(xptr)
CLFPTR	xptr;
{
	WORD		status;
	RESULTPTR	rptr=(RESULTPTR) 0;

	if (( xptr->code  == 0)
	&&  ( xptr->group == 0))
		return( 0 );
	if ( OtrOption.ListFlag & 1)
		echo_clf( xptr,(RESULTPTR) 0);
	if (((status = flush_clf_descriptors(xptr, rptr ))  == 0)
	&&  ((status = flush_clf_parameters(xptr, rptr ))   == 0))
		return( 0 );
	else	return( status );
}

RESULTPTR	make_target_variable(mode)
WORD		mode;			/* VRAI   : Error if not Var 		*/
					/* FAUX   : Register if not VAR 	*/
					/* 2/3/4  : Variable if Possible	*/
{
	RESULTPTR	tptr=(RESULTPTR) 0;
	if ((Context->UseTarget != 0 )
	&&  (Context->TargetVariable != (TCVARPTR) 0 )) {
		if ((tptr = allocate_for_result()) != (RESULTPTR) 0) {
			/* zero dimensions not here 
			   generate_dimensions(0, Context->TargetVariable );
			   */
			tptr->nature   = _RESULT_VARB;
			tptr->value    = Context->TargetVariable->identity;
			tptr->contents = (VPTR) Context->TargetVariable;
			Context->TargetVariable = (TCVARPTR) 0;
			Context->ConvertType    = 2;
			}
		else	(void) allocation_failure();
		return( tptr );
		}
	else if (!( mode )) {
		if ((tptr = next_free_register()) != (RESULTPTR) 0)
			(void) set_shadow_type( tptr->contents, 3  );
		return( tptr );
		}
	else if ( mode < 2 ) {
		(void) syntax_error(703);
		return( tptr );
		}
	else	return( make_target_register( mode ) );

}

static	VOID	set_absolute_type( rptr, cptr )
RESULTPTR	rptr;
ARGPTR		cptr;
{
	WORD	rtype;
	if ((!( rptr )))
		return;
	else if (!( cptr ))
		set_shadow_type( rptr->contents, 2 );
	else if (!( cptr->operand ))
		set_shadow_type( rptr->contents, 2 );
	else if ((rtype = result_type( cptr->operand )) != MOINS_UN)
		set_shadow_type( rptr->contents, rtype );
	else	set_shadow_type( rptr->contents, 2 );
	return;
}

static	RESULTPTR	make_clf_target( xptr )
CLFPTR	xptr;
{
	RESULTPTR	rptr;
	switch ( (xptr->group | (xptr->code << 4)) ) {
		case 0x0015	:	/* ALIAS	*/
			xptr->group = 6;
			xptr->code  = 3;
			return( make_target_variable(FAUX) );

		case 0x00BD     :	/* PROC		*/
		case 0x00CD     :	/* SEGM		*/
		case 0x00DD     :	/* USER		*/
			return( make_target_variable(3) );

		case 0x009D	:	/* CRYPT 	*/

		case 0x003C	:	/* MOVE 	*/
		case 0x004C	:	/* SWAP 	*/
		case 0x0018	:	/* INCLUD 	*/
		case 0x0028	:	/* INSERT	*/
		case 0x0038	:	/* TRANS	*/
		case 0x005A 	:	/* FM		*/
		case 0x006A	:	/* FM		*/
		case 0x007A	:	/* FM		*/
		case 0x00ED	:	/* IPCTEST	*/
		case 0x00FD	:	/* IPCWAIT	*/
			return( make_target_variable(1) );

		case CLF_SHR	:
			return( make_target_variable(3) );
			
		case 0x000D	:	/* GENER	*/
		case 0x001D	:	/* SPACE	*/
		case 0x007D	:	/* CHR$ 	*/
			return( make_target_variable(3) );
		case 0x000E	:	/* FIX		*/
			return( make_target_variable(2) );

		default		:
			if ((rptr = next_free_register()) != (RESULTPTR) 0) {

				switch ( xptr->group ) {
					case	11 :
					case	15 :
					case 	5  : 
						set_shadow_type( rptr->contents, 1  );
						break;

					case	8  :
						/* ABS etc */
						if (!( xptr->code )) 
							set_absolute_type( rptr, xptr->root );
						else	set_shadow_type( rptr->contents, 2  );
						break;

					case	14 :
						if ( xptr->code == 7 ) { /* STRN */
							set_shadow_type( rptr->contents, 3  );
							break;
							}
						else if ( xptr->code == 8 ) { /* LONG */
							set_shadow_type( rptr->contents, 1  );
							break;
							}
					case 	9  :
						set_shadow_type( rptr->contents, 2  );
						break;

					case	13 :
						if ( xptr->code == 10 ) { /* SYSERROR */
							set_shadow_type( rptr->contents, 2  );
							break;
							}

					case	10 : 
					case	12 :
						set_shadow_type( rptr->contents, 3  );
						break;
					case	 4 :
						switch ( xptr->code ) {
						case	_CLF_OCXWAIT :
						case	_CLF_OCXPUT  :
							set_shadow_type( rptr->contents, 1  );
							break;
						case	_CLF_OCXNAME :
						case	_CLF_OCXCALL :
							set_shadow_type( rptr->contents, 3  );
							break;
						}
					}
				}
			return( rptr );
		}
}


static	void	drop_clf_target(xptr)
CLFPTR	xptr;
{
	RESULTPTR	rptr;
	VOID	 *	vptr;
	return;
	if (!( xptr ))
		return;
	else if (!( rptr = xptr->Target ))
		return;
	else if (!( vptr = rptr->contents ))
		return;
	else	{
		unuse_shadow_register( vptr );
		rptr->contents = (VPTR) 0;
		xptr->Target = (RESULTPTR) 0;
		return;
		}
}
	
static	RESULTPTR	function_filter( xptr, eptr )
CLFPTR	xptr;
WPTR	eptr;
{
	TCVARPTR	vptr;
	TCCONPTR	cptr;
	RESULTPTR	rptr;

	switch ( (xptr->group | (xptr->code << 4)) ) {

		case	CLF_MOD	:
			if (!( xptr->root->next )) {
				*eptr = 30;
				return((RESULTPTR) 0);
				}
			else	return( arithmetic( '%', xptr->root->operand, xptr->root->next->operand ) );

		case	CLF_LEN	:
			if (!( xptr ))
				return((RESULTPTR) 0);
			else if (!( xptr->root ))
				return((RESULTPTR) 0);
			else if (!( rptr = xptr->root->operand ))
				return( rptr );
			switch ((rptr->nature & _RESULT_BASIC)) {
				case _RESULT_INT   :    break;
				case _RESULT_EXPR  : 	return((RESULTPTR) 0);
				case _RESULT_CONST :    
					if (!( cptr = (TCCONPTR) rptr->contents))
						return((RESULTPTR) 0);
					else	return( integer_result( cptr->type->size ) );
 
				case _RESULT_VARB  :    
					if (!(vptr = (TCVARPTR) rptr->contents ))
						return((RESULTPTR) 0);
					else if (( vptr->type->type & _TYPE_POINTER ) == _TYPE_POINTER )
						return((RESULTPTR) 0);
					else	{
						drop_clf_target( xptr );
						return( integer_result( vptr->type->size ) );
						}		
				}

		default		:
			return((RESULTPTR) 0);
		}
}

static	RESULTPTR	collect_clf_target(xptr)
CLFPTR	xptr;
{
	if ( xptr->Target  != (RESULTPTR) 0)
		return( xptr->Target );
	else	return( make_clf_target( xptr ) );
}


/*	----------------------------------------------------	*/ 
/*	    C H E C K _ C L F _ P R O B L E M ( xptr )		*/
/*	----------------------------------------------------	*/ 
/*	This function is called priorto the generation of	*/
/*	a clf instruction in order to detect and correct	*/
/*	target variable hogging effects caused by greedy	*/
/*	functions FIX,GENER,SPACE,CHR$ which have differnet	*/
/*	semantics when used in expressions as to when used	*/
/*	in solitary affectation operations			*/
/*	----------------------------------------------------	*/ 

static	WORD		check_clf_problem(xptr)
CLFPTR	xptr;
{
	TCVARPTR	vptr=(TCVARPTR) 0;

	/* Check for target usage and target used */
	/* -------------------------------------- */
	if (!( Context->UseTarget )) 	
		return(0);
	else if (Context->TargetVariable != (TCVARPTR) 0)
 		return(0);

	/* Check for special case of FIX,CHR,SPACE,GENER */
	/* --------------------------------------------- */
	else if (   (( xptr->group == 0x000E ) &&   ( xptr->code  == 0x0000 )) /* FIX 	*/
	        ||  (( xptr->group == 0x000D ) &&   ( xptr->code  == 0x0000 )) /* GENER	*/
		||  (( xptr->group == 0x000D ) &&   ( xptr->code  == 0x0001 )) /* SPACE	*/
		||  (( xptr->group == 0x000D ) &&   ( xptr->code  == 0x0007 )) /* CHR$	*/
		) {
		/* Detect valid variable result */
		/* ---------------------------- */
		if (!( xptr->Target ))
			return(0);
		else if (!(vptr = is_variable_result( xptr->Target )))
			return(0);
		else if (!( remove_white_space() )) {
			/* end of logical line so ok */
			return(0);
			}
		else	{
			/* not end of line so greedy function */
			/* ---------------------------------- */
			Context->TargetVariable = vptr;
			Context->UseTarget      = 0;
			Context->ConvertType = (vptr->type->type & _TYPE_BASIC);
			if (!( xptr->Target  = make_target_register( (xptr->group == 0x000E ? 2 : 3 ) )))
				return(27);
			}
		}
	return(0);
}

static	RESULTPTR	flush_clf(xptr)
CLFPTR	xptr;
{
	RESULTPTR	rptr=(RESULTPTR) 0;
	WORD		status;
	WORD		failure=0;
	trace("flush_clf()\n");

	/* Filter out special functions (Mod etc) */
	/* -------------------------------------- */
	if ((rptr = function_filter( xptr, &failure )) != (RESULTPTR) 0)
		return( rptr );
	else if ( failure )
		return( (RESULTPTR) 0);

	/* Detect problem functions FIX,GENER,SPACE and CHR$ */
	/* which might have stolen the target variable	     */
	/* ------------------------------------------------- */
	else if ((status = check_clf_problem( xptr )) != 0)
		return( rptr );
	

	if ((rptr = collect_clf_target(xptr))     != (RESULTPTR) 0) {
		if ( OtrOption.ListFlag & 1 )
			echo_clf( xptr, rptr );
		if  (((status = flush_clf_descriptors(xptr, rptr ))  == 0)
		&&   ((status = flush_clf_parameters(xptr, rptr ))   == 0))
			return( rptr );
		}
	return( (RESULTPTR) 0 );
}

WORD	store_clf_fmt( xptr, fptr )
CLFPTR	xptr;
BPTR	fptr;
{
	ARGPTR	cptr;
	if ((cptr = allocate_for_operand()) == (ARGPTR) 0)
		return( allocation_failure() );
	cptr->format = fptr;
	if ((cptr->prev = xptr->last) == (ARGPTR) 0)
		xptr->root = cptr;
	else	xptr->last->next = cptr;
	xptr->last = cptr;
	return( 0 );
}

WORD		store_clf(xptr, rptr )
CLFPTR		xptr;
RESULTPTR	rptr;
{
	ARGPTR	cptr;
	trace("store_clf()\n");
	if ( rptr == (RESULTPTR) 0 )
		return( syntax_error( 1090 ) );
	else if ((cptr = allocate_for_operand()) == (ARGPTR) 0)
		return( allocation_failure() );
	cptr->operand = mark_live_result(rptr);
	if ((cptr->prev = xptr->last) == (ARGPTR) 0)
		xptr->root = cptr;
	else	xptr->last->next = cptr;
	xptr->last = cptr;
	return( 0 );
}

WORD		store_clf_data( CLFPTR xptr, WORD data )
{
	xptr->data = data;
	return( 0 );
}


WORD	set_clf_parameter_type( datatype )
WORD	datatype;
{
	WORD	ht;
	ht=Context->OperandType;
	Context->OperandType = datatype;
	return( ht );
}


WORD	get_string_parameter(xptr)
CLFPTR	xptr;
{
	RESULTPTR	rptr;
	WORD		ht;
	ht = set_clf_parameter_type(3);
	if ((rptr = evaluate_expression(0)) != (RESULTPTR) 0) {
		if  ((rptr = ensure_string( rptr )) != (RESULTPTR) 0) {
			ht = set_clf_parameter_type(3);
			return( store_clf(xptr, rptr ) );
			}
		}
	ht = set_clf_parameter_type(3);
	return( syntax_error(704) ); 
}

WORD	get_integer_parameter(xptr)
CLFPTR	xptr;
{
	RESULTPTR	rptr;
	WORD		ht;
	ht = set_clf_parameter_type(1);
	if ((rptr = evaluate_expression(0)) != (RESULTPTR) 0) {
		if  ((rptr = ensure_integer( rptr )) != (RESULTPTR) 0) {
			set_clf_parameter_type(ht);
			return( store_clf(xptr, rptr ) );
			}
		}
	set_clf_parameter_type(ht);
	return( syntax_error(705) ); 
}

WORD	get_numeric_parameter(xptr)
CLFPTR	xptr;
{
	RESULTPTR	rptr;
	WORD		ht;
	ht = set_clf_parameter_type(2);
	if ((rptr = evaluate_expression(0)) != (RESULTPTR) 0) {
		if ((rptr = ensure_numeric( rptr )) != (RESULTPTR) 0) {
			set_clf_parameter_type(ht);
			return( store_clf(xptr, rptr ) );
			}
		}
	set_clf_parameter_type(ht);
	return( syntax_error(706) ); 
}


WORD	get_parameter( xptr )
CLFPTR	xptr;
{
	RESULTPTR	rptr;
	if ((rptr = evaluate_expression(0)) != (RESULTPTR) 0)
		return( store_clf(xptr, rptr ) );
	else	return( syntax_error(707) ); 
}

WORD	get_zone_parameter( xptr )
CLFPTR	xptr;
{
	RESULTPTR	rptr;
	if ((rptr = evaluate_expression(0)) != (RESULTPTR) 0) {
		if (( rptr->nature & _RESULT_BASIC ) == _RESULT_VARB)
			rptr->nature = _RESULT_VPTR;
		return( store_clf(xptr, rptr ) );
		}
	else	return( syntax_error(707) ); 
}

WORD	get_address_parameter(xptr)
CLFPTR	xptr;
{
	WORD	localinhibitalias;
	WORD	status;
	RESULTPTR	rptr;
	localinhibitalias = OtrOption.InhibitAlias;
	OtrOption.InhibitAlias = 1;
	if ((rptr = evaluate_expression(0)) != (RESULTPTR) 0) {
		if (( rptr->nature & _RESULT_BASIC ) == _RESULT_VARB)
			rptr->nature = _RESULT_VPTR;
		status = store_clf(xptr, rptr );
		}
	else	status = syntax_error(707); 
	OtrOption.InhibitAlias = localinhibitalias;
	return( status );
}

static	BPTR	clf_parameter_types( xptr )
CLFPTR	xptr;
{
	switch ( xptr->group ) {
		case  0x0001 :
			switch ( xptr->code ) {
				case	0	: /* SET	*/
					return((BPTR) "SS");
				case	1	: /* OFF	*/
					return((BPTR) "");
				case	2	: /* PRINT */
					return((BPTR) "WWSS");
				case	3	: /* DUMP */
					return((BPTR) "WWSSS");
				case	4	: /* SETDEF	*/
					return((BPTR) "");
				case	5	: /* SETMUTE	*/
					return((BPTR) "SS");
				case	6	: /* SETDEFMUTE */
					return((BPTR) "");
				}
		case	0x0007 :
			switch ( xptr->code ) {
				case	0	: /* LEFT  	*/
				case	1	: /* RIGHT 	*/
					return((BPTR) "SW");
				case	2	: /* SUBSTR	*/
					return((BPTR) "SWW");
				case	3	: /* MOVE	*/
				case	4	: /* SWAP	*/
					return((BPTR) "?WW");
				case	5	: /* PARSE	*/
				case	6	: /* ABALANFC	*/
					return((BPTR) "SW");
				case	7	: /* TOKENISE	*/
					return((BPTR) "SWS");
				}
			break;
		case	0x0009 :
			return((BPTR) "F");
		case	0x000A :
			return((BPTR) "S");
		case	0x000B : 
			switch ( xptr->code ) {
				case	0 :
				case	1 : return((BPTR) "SW");
				case	2 : return((BPTR) "?");
				case	3 : return((BPTR) "S");
				case	4 : return((BPTR) "F");
				case	6 : return((BPTR) "SSW");
				case	5 : return((BPTR) "SS");
				case	7 : return((BPTR) "?");
				case	8 :
				case	9 :
				case   10 : return((BPTR) "F");
				case   11 : return((BPTR) "?S" );
				case   12 : return((BPTR) "???" );
				case   13 : return((BPTR) "S" );
				case   14 : return((BPTR) "SS" );
				case   15 : return((BPTR) "S" );
				}
			break;				

		case	0x000C :
			switch ( xptr->code ) {
				case	0 :
				case	1 : return((BPTR) "SW");
				case	2 : return((BPTR) "SWW");
				case	3 :
				case	4 : return((BPTR) "MWW");
				case	5 : return((BPTR) "SW");
				}
			break;				
		case	0x000D :
			switch ( xptr->code ) {
				case	 0	: return((BPTR) "WS"); 	/* GENER	*/
				case	 1 	: return((BPTR) "W" );	/* SPACE	*/
				case	 2	:			/* DATE		*/
				case	 3	: return((BPTR) "W");	/* KBF		*/
				case	 4	:			/* CURDIR	*/
				case	 5	: return((BPTR) "?");	/* CURVOL	*/
				case	 6	: return((BPTR) "W");	/* HEX		*/

				case	 7	: return((BPTR) "W");	/* CHR$		*/
				case	 8	: return((BPTR) "WS");	/* REPSTR	*/
				case	 9	: return((BPTR) "WW");	/* CRYPT	*/
				case	 10	: return((BPTR) "?");	/* SYSERROR	*/

				case	 11	:
				case	 12	:
				case	 13	: return((BPTR) "W");	/* PROC,USER,SEGM	*/
				}
			break;
		case	0x000E :
			switch ( xptr->code ) {
				case	0 :
				case	1 : return((BPTR) "Fw");
				case	2 :
				case	3 :
				case	5 :
				case	7 :
				case	8 : return((BPTR) "F");
				case	4 : return((BPTR) "SW");
				case	6 : return((BPTR) "FW");
				case	9 : return((BPTR) "??");
				}
			break;				
		case	0x000F :
			switch ( xptr->code ) {
				case	0 :
				case	1 :
				case	3 : return((BPTR) "w");
				case	10:
				case	5 : return((BPTR) "W");
				}
			break;				
		case	0x0006	:
			switch ( xptr->code ) {
				case	3	: return( (BPTR) "A" );
				case	0	:
				case	1	:
				case	2	:
				case	6	: return( (BPTR) "www" );
				}
		}
	return((BPTR) "????????");
}

WORD  optional_parameters_without_brace( CLFPTR xptr )
{
	WORD		status;
	BPTR		tptr;

	if ((tptr = clf_parameter_types( xptr )) != (BPTR) 0) {
		do	{
			switch ( *(tptr++) ) {
				case	0   :
					return( syntax_error( 1040 ) );
				case	'I' :
				case	'i' :
				case	'l' :
				case	'L' :
				case	'w' :
				case	'W' :
				case	'b' :
				case	'B' :
					if ((status = get_integer_parameter( xptr )) != 0)
						return( status );
					else	break;
				case	's' :
				case	'S' :
					if ((status = get_string_parameter( xptr )) != 0)
						return( status );
					else	break;

				case	'f' :
				case	'F' :
					if ((status = get_numeric_parameter( xptr )) != 0)
						return( status );
					else	break;
				case	'a' :
				case	'A' : /* ALIAS VALIDPTR */
					if ((status = get_address_parameter( xptr )) != 0)
						return(status);
					else	break;

				case	'm' :
				case	'M' :
					if ((status = get_zone_parameter( xptr )) != 0)
						return( status );
					else	break;
				case	'?' :
					if ((status = get_parameter( xptr )) != 0)
						return( status );
					else	break;
				}
			}
		while ( is_comma() );
		if (( *tptr >= 'A' ) && ( *tptr <= 'Z' )) 
			return( syntax_error( 1050 ) );
		}

	return(0);
}

WORD	optional_parameters( xptr )
CLFPTR	xptr;
{
	WORD		status;
	BPTR		tptr;
	WORD		c;

	trace("optional_parameters()\n");
	if ( is_left_brace() ) {
		status = optional_parameters_without_brace(xptr);
		if (status)
			return status;
		if (!(is_right_brace()))
			return( unmatched_braces());
		else	return(0);
		}
	else if (!(tptr = clf_parameter_types( xptr )))
		return(0);
	else 	{
		while ((c = *(tptr++)) !=0) {
			if ( c == '?' )
				continue;
			else if (( c >= 'A' ) && ( c <= 'Z' )) 
				return( syntax_error( 1050 ) );
		}
	return(0);
}
}

static	WORD	semaphore( n )
WORD	n;
{
	switch ( n ) {
		case 0 : return(4);
		case 1 : return(5);
		case 2 : return(6);
		case 3 : return(9);
		case 4 : return(12);
		case 5 : return(10);
		case 6 : return(11);
		default: return( MOINS_UN );
		}
}

/* -------------------------------------------------------------- */
/* 		is_trace_instruction				  */
/* -------------------------------------------------------------- */
WORD	is_trace_instruction()
{
	WORD	i;
	uppercase_keyword();
	for ( i = 0; i < _TRACE_KEYWORD_MAX; i++ )
		if ( compare_tokens( KeyWord, trace_keywords[i] ) )
			return( i );
	return( MOINS_UN );
}

static	RESULTPTR	translate_tr_name()
{
	RESULTPTR	rptr;
	if ((rptr = allocate_for_result()) != (RESULTPTR) 0)
		return( build_string_constant( rptr, Context->identity ));
	else	return( rptr );
}

static	RESULTPTR	translate_tr_proc()
{
	RESULTPTR	rptr;
	TCPRCPTR	pptr;
	BPTR		nptr;
	if (!( pptr = Context->PRC ))
		nptr = " ";
	else if (!( nptr = pptr->name ))
		nptr = " ";
	if ((rptr = allocate_for_result()) != (RESULTPTR) 0)
		return( build_string_constant( rptr, nptr ));
	else	return( rptr );
}

/* -------------------------------------------------------------- */
/*  		t r a n s l a t e _ c l f 1 ( item )		  */
/* -------------------------------------------------------------- */
/*	TRACE = <integer> :  					  */
/*			SET 		, [ parameters ] 	  */
/*			OFF					  */
/*			PRINT 		, [ parameters ] 	  */
/*			DUMP  		, [ parameters ]	  */
/*			SETDEF					  */
/*			SETMUTE 	, [ parameters ]	  */
/*			SETDEFMUTE				  */
/* -------------------------------------------------------------- */

static	WORD	translate_clf1( item )
	WORD	item;		/* dummy parameter */
{
	WORD			status;
	CLFPTR		xptr;
	RESULTPTR	rptr;
	WORD			type;

	if (!(is_equals()))
		return( syntax_error(427) );

	else if (!(rptr = evaluate_expression(0)))
		return( syntax_error(427) );

	else if (!(is_colon()))
		return( syntax_error(427) );

	else if (!(evaluate_token()))
		return( syntax_error(427) );

	else if (( type = is_trace_instruction()) == MOINS_UN)
		return( syntax_error(427) );

	else if (!( xptr = start_clf(type,1) ))
		return( release_void_context(xptr,27) );

	else if ((status = store_clf( xptr, rptr )) != 0)
		return( release_void_context(xptr,status) );

	switch ( type ) {

		case	_CLF_TRACE_OFF		:
		case	_CLF_TRACE_SETDEF	:
		case	_CLF_TRACE_SETDEFMUTE	:
			/* these three do not take parameters */
			/* ---------------------------------- */
			if ( is_comma() )
				return( release_void_context(xptr, syntax_error(427) ));
			else	break;

		case	_CLF_TRACE_SET		:
		case	_CLF_TRACE_PRINT	:
		case	_CLF_TRACE_DUMP		:
		case	_CLF_TRACE_SETMUTE	:
			/* these four require parameters */
			/* ----------------------------- */
			if (!( is_comma() ))
				return( release_void_context(xptr, syntax_error(427) ));
			else if ((status = optional_parameters_without_brace(xptr)) != 0)
				return( release_void_context(xptr,status) );
			else	break;

		}

	if ((status = flush_void_clf(xptr)) != 0)
		return( release_void_context(xptr,status) );
	else	{
		/* set_accelerator_end(); */
		return( release_void_context(xptr,status));
		}
}

/* -------------------------------------------------------------- */
/*  		t r a n s l a t e _ c l f 2 ( type )		  */
/* -------------------------------------------------------------- */
static	RESULTPTR	translate_clf2( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr=(CLFPTR) 0;

	if (((xptr = start_clf(10,15))        != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, integer_result(type+10))) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

#ifdef	ABAL32A

/*	----------------------------------------------------------	*/
/*	Abal 3.2 Web Services Tcode Thread Management Instructions 	*/
/*	----------------------------------------------------------	*/
static	RESULTPTR	null_syntax_error(CLFPTR xptr, WORD status)
{
	syntax_error( status );

	if (!( xptr ))
		return((RESULTPTR) 0);
	else	return( release_context(xptr,(RESULTPTR) 0) );
}

WORD	is_thread_keyword()
{
	WORD	i;
	uppercase_keyword();
	for ( i = 0; i < _THREAD_MAX; i++ )
		if ( compare_tokens( KeyWord , thread_keyword[ i ] ) )
			return(i);

	return(MOINS_UN);
}

static	RESULTPTR	evaluate_thread()
{
	RESULTPTR	rptr;
	WORD		type;
	WORD		status;
	CLFPTR		xptr=(CLFPTR) 0;
	if (!( is_period() ))
		return((RESULTPTR) 0);
	else if (!( get_token() ))
		return( null_syntax_error(xptr, 300 ) );
	else if ((type = is_thread_keyword()) == MOINS_UN)
		return( null_syntax_error(xptr, 301 ) );
	else	{
		switch ( type ) {
			case	_THREAD_WAIT	:
			case	_THREAD_ABQT	:
			case	_THREAD_REMOVE 	:
				return( null_syntax_error(xptr, 302 ) );
			default			:
				/* Use CLF EVENT Instruction */
				if (!(xptr = start_clf(10,15)))
					return( null_syntax_error(xptr, 303 ) );
				else if (!( rptr = integer_result( (type + 160) ) ))
					return( null_syntax_error( xptr,304 ) );
				else if ((status = store_clf( xptr, rptr )) != 0)
					return( null_syntax_error(xptr, status) );
				else	return( release_context(xptr,flush_clf(xptr)));
			}
		}
}
static	WORD	translate_thread()
{
	RESULTPTR	rptr;
	WORD		type;
	WORD		status;
	CLFPTR		xptr=(CLFPTR) 0;
	if (!( is_period() ))
		return(MOINS_UN);
	if (!( get_token() ))
		return( syntax_error( 300 ) );
	else if ((type = is_thread_keyword()) == MOINS_UN)
		return( syntax_error( 301 ) );
	else	{
		switch ( type ) {

			case	_THREAD_ABQT	:
				/* Use CLF VOID EVENT Instruction */
				if (!(xptr = start_clf(13,7)))
					return( release_void_context(xptr,303) );
				else if (!( rptr = integer_result( (type + 160) ) ))
					return( release_void_context(xptr,304) );
				else if ((status = store_clf( xptr, rptr )) != 0)
					return( release_void_context(xptr,status) );
				else if (!( rptr = integer_result( 0 ) ))
					return( release_void_context(xptr,304) );
				else if ((status = store_clf( xptr, rptr )) != 0)
					return( release_void_context(xptr,status) );
				else	return( release_void_context(xptr,flush_void_clf(xptr)));


			case	_THREAD_PRIORITY :
			case	_THREAD_DURATION :

				/* Remove potential '=' */
				/* -------------------- */
				(void) is_equals();

			case	_THREAD_WAIT	:
			case	_THREAD_EVENT 	 :
			case	_THREAD_REMOVE 	:

				/* Use CLF VOID EVENT Instruction */
				if (!(xptr = start_clf(13,7)))
					return( release_void_context(xptr,303) );
				else if (!( rptr = integer_result( (type + 160) ) ))
					return( release_void_context(xptr,304) );
				else if ((status = store_clf( xptr, rptr )) != 0)
					return( release_void_context(xptr,status) );
				else if ((status = optional_parameters_without_brace(xptr)) != 0)
					return( release_void_context(xptr,status) );
				else	return( release_void_context(xptr,flush_void_clf(xptr)));

			default			:
				return( syntax_error( 302 ) );
			}
		}
}
#endif

/* -------------------------------------------------------------- */
/*  		t r a n s l a t e _ c l f 3 ( type )		  */
/* -------------------------------------------------------------- */
static	WORD	translate_clf3( type )
WORD	type;
{
	switch ( type ) {
#ifdef	ABAL32A
		case	_CLF3_THREAD	:
			return( translate_thread() );
#endif
		case	_CLF_HALT  : return( generate_stop()   );
		case	_CLF_THROW : 
		case	_CLF_RAISE : 

			if ( exception_method_active() ) {
				(void) generate_error_abort();
				(void) detect_destruction();
				}
			return( translate_error(1) );
		}

	return( 0 );
}

/* -------------------------------------------------------------- */
/*  		t r a n s l a t e _ c l f 4 ( type )		  */
/* -------------------------------------------------------------- */
static	RESULTPTR	translate_clf4( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr;
#ifdef	ABAL32A
	if ( type == _CLF4_THREAD )
		return( evaluate_thread() );
#endif
	if (((xptr = start_clf(type,4))  != (CLFPTR) 0)
	&&  ((status = optional_parameters(xptr)) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

WORD	eligible_for_clf6( code , object )
WORD		code;
TCVARPTR	object;
{
	if (( object->type->type & _TYPE_POINTER ) == _TYPE_POINTER)
		return( VRAI );
	else if ( object->type->type & (_TYPE_DEFINED | _TYPE_OVERLAY) )
		return( FAUX );
	else if ( is_method_pointer( object->type->class ) )
		return( 2 );
	else	return( MOINS_UN );
}

/*
 *	CREATE	<pointer> [ ( <dimensions> ) ] [ : [next|&ett] , var ]
 *	REMOVE	<pointer> [ ( <dimensions> ) ] [ : [next|&ett] , var ]
 *	FORGET	<pointer>  [ : [next|&ett] , var ]
 *	ATTACH	<pointer> ( <handle> | <filename> ) [ : [next|&ett] , var ]
 *	DETACH	<pointer>  [ : [next|&ett] , var ]
 *	ALTER	<pointer> ( <dimensions> ) [ : [next|&ett] , var ]
 */

WORD	clf6_parameters(xptr)
CLFPTR	xptr;
{
	WORD		status;
	RESULTPTR	rptr;
	TCVARPTR	object;
	WORD		nature=0;
	WORD		eligible=1;

	trace("clf6_parameters()\n");

	if (( xptr->code == _CLF_SYNAPSE )
	&&  ( is_mnemonic("OUTPUT")      ))
		xptr->code++;
	else if (( xptr->code == _CLF_WEIGHT  )
	     &&  ( is_mnemonic("OUTPUT")      ))
		xptr->code++;
	else if (( xptr->code == _CLF_THRESHOLD )
	     &&  ( is_mnemonic("OUTPUT")        ))
		xptr->code++;

	UseDimensions = FAUX;
	rptr = evaluate_expression(0);
	UseDimensions = VRAI;
	switch ( xptr->code ) {
		case	_CLF_DETACH :
		case	_CLF_REMOVE :
			if (( rptr != (RESULTPTR) 0)
			&&  ((rptr = protect_operand( rptr )) == (RESULTPTR) 0))
				return( allocation_failure() );
		}
	if (!( rptr ))
		return( syntax_error( 235 ) );

	if ((status = store_clf( xptr, rptr )) != 0)
		return( status );

	if ((object = (TCVARPTR)rptr->contents) != (TCVARPTR) 0) {

		switch ((eligible = eligible_for_clf6( xptr->code, object ))) {
			case	2	 :
				/* Method Pointer */
				/* -------------- */
				xptr->group = 0;
				return( build_method_pointer( object, object->type->class ) );

			case	0 	 : 
				/* Object but not Allocation */
				/* ------------------------- */	   
				xptr->group = 0;

			case	1	 : 
				/* Allocated and maybe object */
				/* -------------------------- */
				break;

			case	MOINS_UN : 
				strcpy(TokenBuffer,object->name);
				issue_warning( 18 );
				xptr->group = 0;
			}
 
		switch ( xptr->code ) {

			case	_CLF_ALTER  :
				if ((status = optional_parameters(xptr)) != 0)
					return( status );
				else	return( 0 );

			case	_CLF_ATTACH :
				/* Collect attachment handle or name */
				/* --------------------------------- */
				if ((status = optional_parameters(xptr)) != 0)
					return( status );
				else	nature = 1;

			case	_CLF_CREATE :
				if ((status = explicite_construction( object, nature )) != 0) {
					if ( status == MOINS_UN ) {
						xptr->code = xptr->group = 0;
						return( 0 );
						}
					else	return( status );
					}
				else	break;

			case	_CLF_DETACH :
				nature = 1;
			case	_CLF_REMOVE :
				if ((status = explicite_destruction( object, nature )) != 0) {
					if ( status == MOINS_UN ) {
						xptr->code = xptr->group = 0;
						return( 0 );
						}
					else	return( status );
					}
				else	break;			
			}
		}

	if ( xptr->code == _CLF_ATTACH)
		return( 0 );
	else if ( xptr->code != _CLF_BUILD ) {
		if (((status = optional_parameters(xptr)) == 0)
		&&  ( xptr->code == _CLF_EVALUATE )
		&&  ( is_comma() ))
			return( optional_parameters( xptr ) );
		else	return( status );
		}
#ifdef	WITH_NURAL
	else	return( store_clf( xptr, integer_result( nural_class_identity( rptr->contents ) ) ) );
#else
	else	return( MOINS_UN );
#endif
}

WORD	clf_explicite_label(CLFPTR xptr)
{
	if ( get_token() ) {
		xptr->ErrorFlag = 0;
		strcpy(xptr->ErrorLabel,TokenBuffer);
		if ( is_comma() )
			return(0);
		}
	return( syntax_error(110) );
}

WORD	clf_implicite_label(CLFPTR xptr ,WORD nature)
{
	xptr->ErrorFlag = nature;
	if ( is_comma() ) {
		xptr->ErrorAdr = new_implicite_label();
		return( 0 );
		}
	else	return( syntax_error(111) );
}

WORD	clf_error_trap(	CLFPTR	xptr )
{
	WORD	status=0;
	trace("clf_error_trap()\n");
	if ( is_colon() ) {
		if ((status = is_ampersand()) != FAUX ) {  
			unget_byte();
			if (clf_explicite_label(xptr) != 0)
				return( syntax_error(112) );
			}
		else if ((status = is_mnemonic_label()) != FAUX) {
			if ( clf_implicite_label(xptr,status) != 0 )
				return( syntax_error(113) );
			}
		if (( status )
		&&  ((xptr->Error = evaluate_expression(0)) == (RESULTPTR) 0))
			return(syntax_error(114));
		}
	return(0);
}

/* -------------------------------------------------------------- */
/*  		t r a n s l a t e _ c l f 6 ( type )		  */
/* -------------------------------------------------------------- */
WORD	translate_clf6( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr=(CLFPTR) 0;
	do 	{
		if (((xptr = start_clf(type,6))         != (CLFPTR) 0)
		&&  ((status = clf6_parameters(xptr))	== 0)) {
			if ((status = clf_error_trap(xptr)) != 0)
				return( release_void_context(xptr,status) );
			if ((xptr->group)
			&&  ((status = flush_void_clf(xptr)) != 0))
				return( release_void_context(xptr,status) );
			else if ((status = release_void_context(xptr,status)) != 0)
				return( status );
			else	{
				xptr = (CLFPTR) 0;
				if (( type == _CLF_CREATE )
				||  ( type == _CLF_ATTACH ))
					if (( status = flush_explicite_constructors()) != 0)
						return( status );
				}
			}
		else	return( release_void_context(xptr,status) );
		}
	while ( is_comma() );
	return(0);
}

/*
 *	CLF GROUP 7	:	MISC FUNCTIONS WITH NO RESULT
 *	-----------		-----------------------------
 *
 *	WAIT	    =	( <expression> )
 *	MASK	    =	( <expression> )
 *	RESTORE	    =	( <expression> )
 *	DATE		( <expression> ) = <expression>
 *	KBF 		( <expression> ) = <expression>
 *	EVENT		( <expression> ) = <expression>
 *	SEND		( <expression> ) = <expression>
 * 	ASKCOLOR    =	( <expression> , <expression> )
 *	ASKATB	    =	( <expression> )
 *	HOTKEY	    =   ( <expression> )
 *	LANG	    =	( <expression> )
 *	INITDATA
 *
 *	NB: In the following algorithm :
 *
 *		1 )  	the initial '=' is optional
 *		2 )  	the braces are optional but must be matched
 *		3 )  	the subsequent '=' and ',' punctuation must
 *			be present to allow second parameter collection.
 *		4 )	RESTORE may omit its parameter
 *	 
 *	----------------------------------------------------
 *	These will not arrive here : They are handled by END
 *	----------------------------------------------------
 *	END.USER	( <library>    )
 *	END.PROC	( <procedure>  )
 *	END.SEG		( <segment>    )
 *	----------------------------------------------------
 *
 */

static	WORD	get_clf7_parameters(xptr)
CLFPTR	xptr;
{
	WORD		status=FAUX;
	WORD		braces=FAUX;
	RESULTPTR	rptr=(RESULTPTR) 0;

	/* Remove potential '=' */
	/* -------------------- */
	(void) is_equals();

	/* Collect potential '(' */
	/* --------------------- */
	if ( xptr->code != _CLF_RESTORE )
		braces = is_left_brace();
	else	braces = 0;


	/* Collect Potential First Parameter */
	/* --------------------------------- */
	if ((rptr = evaluate_integer_expression()) == (RESULTPTR) 0) {
		if (!( xptr->code == _CLF_RESTORE ))
			return(0);
		else if (!(rptr = integer_result(1)))
			return(0);
		}
		
	/* And attempt to Store it */
	/* ----------------------- */
	if ((status = store_clf(xptr, rptr )) != 0)
		return( syntax_error(709) ); 

	/* Collect Potential Second Parameter */
	/* ---------------------------------- */
	if ( is_comma() ) {
		if (((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
		||  ((status = store_clf(xptr, rptr )) != 0))
			return( syntax_error(709) ); 
		}

	/* Check for braces closed if Opened */
	/* --------------------------------- */
	if (( braces )
	&&  (!( is_right_brace() )))
		return( unmatched_braces() );
 
	/* Check for final possible Pseudo Affectation */
	/* ------------------------------------------- */
	if ( is_equals() ) {
		if (((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
		||  ((status = store_clf(xptr, rptr )) != 0))
			return( syntax_error(712) ); 
		}

	return(0);
}

/* -------------------------------------------------------------- */
/*  		t r a n s l a t e _ c l f 7 ( type )		  */
/* -------------------------------------------------------------- */
static	WORD	translate_clf7( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr;
	
	/* Check for EVENT OFF instruction */
	/* ------------------------------- */
	if (type == _CLF_EVENT) {
		if (!(is_left_brace())) {
			if (( get_token() )
			&&  ((status = is_control_keyword()) == _CTRL_OFF))
				return( generate_event_off() );
			else	return( syntax_error(713) );
			}
		else	unget_byte();
		}
		
	/* Perform normal CLF GROUP 7 translation */
	/* -------------------------------------- */
	if (((xptr = start_clf(type,7))        != (CLFPTR) 0)
	&&  ((status = get_clf7_parameters(xptr))	== 0)
	&&  ((status = flush_void_clf(xptr))		== 0))
		return( release_void_context(xptr,status) );
	else	return( release_void_context(xptr,status) );

}

/* -------------------------------------------------------------- */
/*  		t r a n s l a t e _ c l f 8 ( type )		  */
/* -------------------------------------------------------------- */
static	RESULTPTR	translate_clf8( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr;
	if (((xptr = start_clf(type,8))  != (CLFPTR) 0)
	&&  ((status = optional_parameters(xptr)) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

/* -------------------------------------------------------------- */
/*  		t r a n s l a t e _ c l f 9 ( type )		  */
/* -------------------------------------------------------------- */
static	RESULTPTR	translate_clf9( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr;
	if (((xptr = start_clf(type,9))  != (CLFPTR) 0)
	&&  ((status = optional_parameters(xptr)) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}


static	RESULTPTR	translate_clf_fm( type )
WORD	type;
{
	WORD		status;
	RESULTPTR	rptr;
	CLFPTR		xptr;
	BPTR		fptr;

	if ((xptr = start_clf(type,10)) != (CLFPTR) 0) {
		if (!( is_left_brace() ))
			syntax_error(714);
		else	{
			if ( is_left_brace() ) {
				if (((rptr   = evaluate_expression(0)) == (RESULTPTR) 0)
				||  ((status = store_clf(xptr, rptr )) != 0))
					(void) syntax_error(715);
				if (!( is_right_brace() ))
					(void) unmatched_braces();
				}
			else	{
				if (((fptr = convert_explicite_format()) == (BPTR) 0)
				||  ((status = store_clf_fmt( xptr, fptr )) != 0))
					(void) syntax_error(716);
				}
			if (!( is_right_brace()))
				(void) unmatched_braces();
			else	{
				return( release_context(xptr,flush_clf(xptr)));
				}
			}
		}
	return( release_context(xptr,(RESULTPTR) 0));
}

/* -------------------------------------------------------------- */
/*  		t r a n s l a t e _ c l f a ( type )		  */
/* -------------------------------------------------------------- */
static	RESULTPTR	translate_clfa( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr;
	if ( type == 5 ) /* CLF_FM */
		return( translate_clf_fm( type ) );

	if (((xptr = start_clf(type,10)) != (CLFPTR) 0)
	&&  ((status = optional_parameters(xptr)) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

/* -------------------------------------------------------------- */
/*  		t r a n s l a t e _ c l f b ( type )		  */
/* -------------------------------------------------------------- */
static	RESULTPTR	translate_clfb( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr;

	if (( type == _CLFB_LEN )
	&&  ( is_dollar()       ))
		type = _CLFB_LEN$;

	if (((xptr = start_clf(type,11)) != (CLFPTR) 0)
	&&  ((status = optional_parameters(xptr)) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}


/* -------------------------------------------------------------- */
/*  		t r a n s l a t e _ c l f c ( type )		  */
/* -------------------------------------------------------------- */
static	RESULTPTR	translate_clfc( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr;
	if (((xptr = start_clf(type,12)) != (CLFPTR) 0)
	&&  ((status = optional_parameters(xptr)) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

static	RESULTPTR	clf_affect_pointer( type, rptr, sptr )
WORD		type;
RESULTPTR	rptr;
RESULTPTR	sptr;
{
	CLFPTR	xptr;
	WORD	status;
	trace("clf_affect_pointer()\n");
	if ((xptr = start_clf(type,13)) != (CLFPTR) 0) {
		if (( sptr != (RESULTPTR) 0 )
		&&  ((status = store_clf( xptr, sptr )) != 0))
			return( release_context(xptr,(RESULTPTR) 0));
		if ((status = store_clf( xptr, rptr ))   == 0)
			return( release_context(xptr,flush_clf(xptr)));
		}
	return( release_context(xptr,(RESULTPTR) 0));
}

RESULTPTR	affect_proc_pointer( WORD type )
{
	TCPRCPTR	pptr;
	TCVARPTR	vptr;
	RESULTPTR	rptr=(RESULTPTR) 0;
	WORD		braces;

	trace("affect_proc_pointer()\n");

	braces = is_left_brace();

	if (!( get_token() )) {
		(void) syntax_error( 833 );
		return( (RESULTPTR) 0 );
		}
	else if ((pptr = is_procedure()) != (TCPRCPTR) 0) {
		if ( pptr->identity == MOINS_UN )
			(void) rellocate_external_procedure( pptr );
		rptr = codeptr_result( pptr->identity, _RESULT_PROCPTR, pptr );
		}
	else if ((vptr = is_variable(1)) != (TCVARPTR) 0)
		rptr = variable_result( vptr );
	
	if ( rptr == (RESULTPTR) 0 ) {
		(void) syntax_error( 712 );
		return( (RESULTPTR) 0 );
		}
		
	if ((braces)
	&& (!( is_right_brace()))) {
		(void) syntax_error(717);
		return( (RESULTPTR) 0 );
		}
	else	return( clf_affect_pointer( type, rptr, (RESULTPTR) 0 ) );
}

static	RESULTPTR	affect_user_pointer( type )
WORD	type;
{
	TCDLFPTR	fptr;
	TCVARPTR	vptr;
	RESULTPTR	rptr=(RESULTPTR) 0;
	RESULTPTR	lptr=(RESULTPTR) 0;
	WORD		braces;

	braces = is_left_brace();

	if (!( get_token() )) {
		(void) syntax_error( 833 );
		return( (RESULTPTR) 0 );
		}

	if ((fptr = is_dll_function()) != (TCDLFPTR) 0) {
		if (!(rptr = integer_result( fptr->identity )))
			return( rptr );
		else if (!(lptr = codeptr_result( fptr->library->identity,_RESULT_USERPTR, fptr->library )))
			return( lptr );
		}
	else if (((vptr = is_variable(1)) == (TCVARPTR) 0)
	     ||  ((rptr = variable_result( vptr )) == (RESULTPTR) 0)) {
		(void) syntax_error( 712 );
		return( (RESULTPTR) 0 );
		}

	if ((braces)
	&& (!( is_right_brace()))) {
		(void) syntax_error(717);
		return( (RESULTPTR) 0 );
		}
	else	return( clf_affect_pointer( type, lptr, rptr ) );
}

static	RESULTPTR	affect_segm_pointer( type )
WORD	type;
{
	RESULTPTR	rptr=(RESULTPTR) 0;
	WORD		braces;

	braces = is_left_brace();

	if (((rptr = evaluate_expression(0)) == (RESULTPTR) 0)
	&&  ((rptr = named_segment(TokenBuffer)) == (RESULTPTR) 0)) {
		(void) syntax_error( 712 );
		return( (RESULTPTR) 0 );
		}
		
	if ((braces)
	&& (!( is_right_brace()))) {
		(void) syntax_error(717);
		return( (RESULTPTR) 0 );
		}
	else	return( clf_affect_pointer( type, rptr, (RESULTPTR) 0 ) );
}

static	RESULTPTR	affect_code_pointer( type )
WORD	type;
{
	trace("affect_code_pointer()\n");
	if (( get_token() )
	&&  ( is_level1_keyword() == _KW1_PTR ))  {
		switch ( type ) {
			case _CLF_PROC 	:
				return( affect_proc_pointer( type ) );
			case _CLF_SEGM 	:
				return( affect_segm_pointer( type ) );
			case _CLF_USER 	:
				return( affect_user_pointer( type ) );
			}
		}
	else	(void) syntax_error(718);
	return( (RESULTPTR) 0 );
}

/* -------------------------------------------------------------- */
/*  		t r a n s l a t e _ c l f d ( type )		  */
/* -------------------------------------------------------------- */
static	RESULTPTR	translate_clfd( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr;
	trace("translate_clfd()\n");
	switch ( type ) {
		case _CLF_PROC 	:
		case _CLF_SEGM 	:
		case _CLF_USER 	:
			return( affect_code_pointer( type ) );

		case _CLFD_CHR	:
			if (!( is_dollar() )) {
				(void)  syntax_error( 718 );
				return((RESULTPTR) 0);
				}

		default		:
		
			if (((xptr = start_clf(type,13)) != (CLFPTR) 0)
			&&  ((status = optional_parameters(xptr)) == 0))
				return( release_context(xptr,flush_clf(xptr)));
			else	return( release_context(xptr,(RESULTPTR) 0));
		}
}

/* -------------------------------------------------------------- */
/*  		t r a n s l a t e _ c l f e ( type )		  */
/* -------------------------------------------------------------- */
static	RESULTPTR	translate_clfe( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr;
	if (((xptr = start_clf(type,14)) != (CLFPTR) 0)
	&&  ((status = optional_parameters(xptr)) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

static	RESULTPTR	translate_conv( type )
WORD	type;
{
	RESULTPTR	rptr;
	if (( is_left_brace() ) 
	&&  ((rptr = evaluate_expression(0)) != (RESULTPTR) 0)
	&&  ( is_right_brace() )) {
		/* this allows ATR compatible STV V,V instead of CONV */
		/* it is essentiel for integer to string types 	      */
		if ( type == 666 ) {
			if (!( remove_white_space() )) {
				AllowAutoConv(1);
				return( rptr );
				}
			else if ( is_comma() ) {
				unget_byte();
				AllowAutoConv(1);
				return( rptr );
				}
			else if ( is_right_brace() ) {
				unget_byte();
				AllowAutoConv(1);
				return( rptr );
				}
			else	type = _CLF_CONV3;
			}
		return ((rptr = convert_to_type(rptr, type)));
		}
	else	return( (RESULTPTR) 0);
}

static	RESULTPTR	translate_tr_date()
{
	RESULTPTR	rptr;
	if ((rptr = allocate_for_result()) != (RESULTPTR) 0)
		return( build_string_constant( rptr, "#DATE" ));
	else	return( rptr );
}

static	RESULTPTR	translate_tr_time()
{
	RESULTPTR	rptr;
	if ((rptr = allocate_for_result()) != (RESULTPTR) 0)
		return( build_string_constant( rptr, "#TIME" ));
	else	return( rptr );
}

static	RESULTPTR	translate_tr_file()
{
	RESULTPTR	rptr;
	if ((rptr = allocate_for_result()) != (RESULTPTR) 0)
		return( build_string_constant( rptr, source_file_name() ));
	else	return( rptr );
}

static	RESULTPTR	translate_tr_line()
{
	return( integer_result( source_file_line() ) );
}


/* -------------------------------------------------------------- */
/*  		t r a n s l a t e _ c l f 0 ( type )		  */
/* -------------------------------------------------------------- */
static	RESULTPTR	translate_clf0( type )
WORD	type;
{
	WORD		ht;
	WORD		status;
	RESULTPTR	rptr;
	WORD		temptype;

	switch ((type)) {

		case 	_CLF_CONV 	:

			if ( is_dollar() )
				type = _CLF_CONV3;
			else if ( is_dieze() )
				type = _CLF_CONV0;
			else if ( is_percent() )
				type = _CLF_CONV1;
			else if ( is_star() ) {
				type = _CLF_CONV;
				return( translate_conv( type ) );
				}
			else 	{
				if ( Context->Depth == 0 )
					type = Context->ConvertType;
				else	type = Context->OperandType;
				if ( type == 3 )
					Context->OperandType=2;
				}

		case	_CLF_CONV3	:

			if (( type == _CLF_CONV3 ) 
			||  ( type == _CLF_CONV  )) {
				if (( Context->Depth == 1 )
				&&  ( Context->UseTarget  )
				&&  ( Context->TargetVariable != (TCVARPTR) 0 )
				&&  ( Context->TargetVariable->type != (TCTYPPTR) 0)) {
					/* this allows ATR compatible STV V,V instead of CONV 	*/
					/* it is essentiel for integer to string types 	 	*/
					if ((temptype = (Context->TargetVariable->type->type & 3)) == 3 ) {
						if ( type != _CLF_CONV )
							Context->OperandType=2;
						type = 666;
					}
					else	type = temptype;
					}
				else	type = type; /* 2; */ /* Context->ConvertType; */
				}

		case	_CLF_CONV0	:
		case	_CLF_CONV1	:
			return( translate_conv( type ) );

		case	_CLF_MOD  	:
			return( translate_clfe( 9 ) );

		case	_CLF_PRINT	:
			ht = set_clf_parameter_type(2);
			status=translate_clf_print((rptr = make_target_variable(FAUX)));
			ht = set_clf_parameter_type(ht);
			if ( status != 0 )
				return( (RESULTPTR) 0 );
			else	return( rptr );

		case	_CLF_TRDATE	:
			return( translate_tr_date() );
		case	_CLF_TRTIME	:
			return( translate_tr_time() );
		case	_CLF_TRFILE	:
			return( translate_tr_file() );
		case	_CLF_TRLINE	:
			return( translate_tr_line() );
		case	_CLF_NULL	:
			return( integer_result(0) );
		case	_CLF_CLASS_NAME :
			return( translate_class_name() );
		case	_CLF_OBJECT_NAME:
			return( translate_object_name() );
		case	_CLF_CLASS_NUMBER :
			return( translate_class_number() );
		case	_CLF_OBJECT_NUMBER:
			return( translate_object_number() );
		case	_CLF_SIZEOF     :
			return( translate_sizeof() );
		}
	
	return( (RESULTPTR) 0 );
}

/* -------------------------------------------------------------- */
/*  		t r a n s l a t e _ c l f f ( type )		  */
/* -------------------------------------------------------------- */
static	RESULTPTR	translate_clff( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr;
	if (((xptr = start_clf(type,15)) != (CLFPTR) 0)
	&&  ((status = optional_parameters(xptr)) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

static	WORD	translate_train( xptr )
CLFPTR	xptr;
{
#ifdef	WITH_NURAL
	NUROBJPTR	nptr;
	TCVARPTR	vptr;
	WORD	status;
	trace("translate_train(\n");
	if (!( get_token() ))
		return( syntax_error(719) );
	else if ((nptr = is_nural_network_object( TokenBuffer )) == (NUROBJPTR) 0)
		return( syntax_error(720) );
	else if ((vptr = is_variable(1)) == (TCVARPTR) 0)
		return( syntax_error(721) );
	else if ((status = store_clf( xptr, variable_result( vptr ))) != 0)
		return( status );
	else if ((status = optional_parameters(xptr)) != 0)
		return( status );
	if (( is_colon() )
	&&  ((status = optional_parameters(xptr)) != 0))
		return( status );
	else
#endif
		return( 0 );
}

static	WORD	validptr_member( xptr ) 
CLFPTR	xptr;
{
	if (!( get_token() ))
		return( syntax_error( 723 ) );
	else	return( syntax_error( 723 ) );
}

static	RESULTPTR	translate_clf5( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr;
	if ((xptr = start_clf(type,5)) != (CLFPTR) 0) {
		switch ( type ) {
			case	0	:	/* VALIDPTR 	*/
			case	1	:	/* ALIAS	*/

				if (( type == 0 )
				&&  ( is_period() )) {
					if ((status = validptr_member( xptr )) != 0)
						return( release_context(xptr,(RESULTPTR) 0));
					}
				else if ((status = optional_parameters(xptr)) != 0)
					return( release_context(xptr,(RESULTPTR) 0));
				else	return( release_context(xptr,flush_clf(xptr)));
			case	3	:	/* LOADGO : ABAL 3 */
				if ((status = optional_parameters(xptr)) != 0)
					return( release_context(xptr,(RESULTPTR) 0));
				else	return( release_context(xptr,flush_clf(xptr)));
			case	2	:	/* TRAIN	*/
				if ((status = translate_train( xptr )) == 0)
					return( release_context(xptr,flush_clf(xptr)));
				else return( release_context(xptr,(RESULTPTR) 0));
			}
		}
	return( release_context(xptr,(RESULTPTR) 0));
}

/*	--------------------------------------------	*/
/*	Translation of VOID Common Library Functions	*/
/*	--------------------------------------------	*/

WORD	is_clf0()
{
	WORD	i;
	for ( i = 0; i < _MAX_CLF0; i++ )
		if ( compare_tokens( KeyWord , clf0_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD	is_clf1()
{
	WORD	i;
	for ( i = 0; i < _MAX_CLF1; i++ )
		if ( compare_tokens( KeyWord , clf1_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD	is_clf2()
{
	WORD	i;
	for ( i = 0; i < _MAX_CLF2; i++ )
		if ( compare_tokens( KeyWord , clf2_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD	is_clf3()
{
	WORD	i;
	for ( i = 0; i < _MAX_CLF3; i++ )
		if ( compare_tokens( KeyWord , clf3_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD	is_clf4()
{
	WORD	i;
	for ( i = 0; i < _MAX_CLF4; i++ )
		if ( compare_tokens( KeyWord , clf4_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD	is_clf6()
{
	WORD	i;
	for ( i = 0; i < _MAX_CLF6; i++ )
		if ( compare_tokens( KeyWord , clf6_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD	is_clf5()
{
	WORD	i;
	for ( i = 0; i < _MAX_CLF5; i++ )
		if ( compare_tokens( KeyWord , clf5_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD	is_clf7()
{
	WORD	i;

	for ( i = 0; i < _MAX_CLF7; i++ )
		if ( compare_tokens( KeyWord , clf7_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD	is_clf8()
{
	WORD	i;

	for ( i = 0; i < _MAX_CLF8; i++ )
		if ( compare_tokens( KeyWord , clf8_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD	is_clf9()
{
	WORD	i;
	if (!( OtrOption.BibMath ))
		for ( i = 0; i < _MAX_CLF9; i++ )
			if ( compare_tokens( KeyWord , clf9_keywords[ i ] ) )
				return(i);

	return(MOINS_UN);
}

WORD	is_clfa()
{
	WORD	i;

	for ( i = 0; i < _MAX_CLFA; i++ )
		if ( compare_tokens( KeyWord , clfa_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD	is_clfb()
{
	WORD	i;

	for ( i = 0; i < _MAX_CLFB; i++ )
		if ( compare_tokens( KeyWord , clfb_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD	is_clfc()
{
	WORD	i;

	for ( i = 0; i < _MAX_CLFC; i++ )
		if ( compare_tokens( KeyWord , clfc_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD	is_clfd()
{
	WORD	i;

	for ( i = 0; i < _MAX_CLFD; i++ )
		if ( compare_tokens( KeyWord , clfd_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD	is_clfe()
{
	WORD	i;

	for ( i = 0; i < _MAX_CLFE; i++ )
		if ( compare_tokens( KeyWord , clfe_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD	is_clff()
{
	WORD	i;

	for ( i = 0; i < _MAX_CLFF; i++ )
		if ( compare_tokens( KeyWord , clff_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD	translate_clf()
{
	WORD	type;

	trace("translate_clf()\n");
	uppercase_keyword();
	if ((type = is_clf6()) != MOINS_UN)
		return( translate_clf6(type) );
	else if ((type = is_clf1()) != MOINS_UN)
		return( translate_clf1(type) );
	else if ((type = is_clf7()) != MOINS_UN)
		return( translate_clf7(type) );
	else if ((type = is_clf3()) != MOINS_UN)
		return( translate_clf3(type) );
	else	return( MOINS_UN );

}

/*	Evaluation of NON-VOID Common Library Functions		*/
/*	-----------------------------------------------		*/

RESULTPTR    evaluate_clf()
{
	WORD	type;
	trace("evaluate_clf()\n");
	uppercase_keyword();
	if ((type = is_clf0()) != MOINS_UN)
		return( translate_clf0(type) );
	else if ((type = is_clf2()) != MOINS_UN)
		return( translate_clf2(type) );
	else if ((type = is_clf5()) != MOINS_UN)
		return( translate_clf5(type) );
	else if ((type = is_clf8()) != MOINS_UN)
		return( translate_clf8(type) );
	else if ((type = is_clf9()) != MOINS_UN)
		return( translate_clf9(type) );
	else if ((type = is_clfa()) != MOINS_UN)
		return( translate_clfa(type) );
	else if ((type = is_clfb()) != MOINS_UN)
		return( translate_clfb(type) );
	else if ((type = is_clfc()) != MOINS_UN)
		return( translate_clfc(type) );
	else if ((type = is_clfd()) != MOINS_UN)
		return( translate_clfd(type) );
	else if ((type = is_clfe()) != MOINS_UN)
		return( translate_clfe(type) );
	else if ((type = is_clff()) != MOINS_UN)
		return( translate_clff(type) );
	else if ((type = is_clf4()) != MOINS_UN)
		return( translate_clf4(type) );
	else	return( intrinsic_functions() );
}

RESULTPTR	clf_abs_zero()
{
	CLFPTR		xptr;
	WORD		status;
	RESULTPTR	lptr;

	trace("clf_abs()\n");
	if (((xptr = start_clf(0,8)) != (CLFPTR) 0)
	&&  ((lptr = allocate_for_result()) != (RESULTPTR) 0)
	&&  ((lptr = build_numeric_term( lptr, (BPTR) "0" )) != (RESULTPTR) 0)
	&&  ((status = store_clf(xptr, lptr )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

RESULTPTR	clf_space( l )
WORD		l;
{
	CLFPTR		xptr;
	WORD		status;
	RESULTPTR	lptr;

	trace("clf_space()\n");
	if (((xptr = start_clf(1,13)) != (CLFPTR) 0)
	&&  ((lptr = integer_result( l )) != (RESULTPTR) 0)
	&&  ((status = store_clf(xptr, lptr )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

WORD	clf_initlocal()
{
	CLFPTR		xptr;
	WORD		status=27;
	RESULTPTR	lptr;
	if (((xptr = start_clf(9,7))        	 != (CLFPTR) 0)
	&&  ((lptr = integer_result( 1 )) != (RESULTPTR) 0)
	&&  ((status = store_clf(xptr, lptr )) == 0))
		status = flush_void_clf(xptr);
	return((status = release_void_context(xptr,status)));
}

WORD	clf_initglobal()
{
	CLFPTR		xptr;
	WORD		status=27;
	RESULTPTR	lptr;
	if (((xptr = start_clf(9,7))        	 != (CLFPTR) 0)
	&&  ((lptr = integer_result( 0 )) != (RESULTPTR) 0)
	&&  ((status = store_clf(xptr, lptr )) == 0))
		status = flush_void_clf(xptr);
	return((status = release_void_context(xptr,status)));
}

RESULTPTR	clf_reg_alias( rptr )
RESULTPTR	rptr;
{
	CLFPTR		xptr;
	WORD		status;

	trace("clf_space()\n");
	if (((xptr = start_clf(1,5)) != (CLFPTR) 0)
	&&  ((status = store_clf(xptr, rptr )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

RESULTPTR	clf_date( n )
WORD		n;
{
	CLFPTR		xptr;
	WORD		status;
	RESULTPTR	lptr;
	trace("clf_date()\n");
	if (((xptr = start_clf(2,13)) != (CLFPTR) 0)
	&&  ((lptr = integer_result( n )) != (RESULTPTR) 0)
	&&  ((status = store_clf(xptr, lptr )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

RESULTPTR	clf_validptr( vptr )
TCVARPTR	vptr;
{
	CLFPTR		xptr;
	WORD		status;
	RESULTPTR	lptr;
	trace("clf_validptr()\n");
	if (((xptr = start_clf(0,5)) != (CLFPTR) 0)
	&&  ((lptr = variable_result( vptr )) != (RESULTPTR) 0)
	&&  ((status = store_clf(xptr, lptr )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

WORD		clf_create( target )
RESULTPTR	target;
{
	CLFPTR		xptr;
	WORD		status=27;
	if (((xptr = start_clf(0,6))        	 != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, target)) == 0))
		status = flush_void_clf(xptr);
	return((status = release_void_context(xptr,status)));
}

WORD		clf_alias( pvarb, target )
RESULTPTR	pvarb;
RESULTPTR	target;
{
	CLFPTR		xptr;
	WORD		status=27;
	/* forces special case to avoid standard alias */
	if (((xptr = start_clf(15,6))        	 != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, pvarb )) == 0)
	&&  ((status = store_clf( xptr, target)) == 0))
		status = flush_void_clf(xptr);
	return((status = release_void_context(xptr,status)));
}

WORD		clf_funcptr( pvarb, target, pptr )
RESULTPTR	pvarb;
RESULTPTR	target;
TCPRCPTR	pptr;
{
	CLFPTR		xptr;
	WORD		status=27;

	if ( pptr != (TCPRCPTR) 0 ) { /* was && ( pptr->identity == MOINS_UN ) */
		if ( pptr->identity == MOINS_UN )
			(void) rellocate_external_procedure( pptr );
		target = codeptr_result( pptr->identity, _RESULT_PROCPTR, pptr );
		}
	if (((xptr = start_clf(_CLF_PROC,13)) != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, pvarb )) == 0)
	&&  ((status = store_clf( xptr, target)) == 0))
		status = flush_void_clf(xptr);
	return((status = release_void_context(xptr,status)));
}

WORD		clf_userptr( pvarb, target, library )
RESULTPTR	pvarb;
RESULTPTR	library;
RESULTPTR	target;
{
	CLFPTR		xptr;
	WORD		status=27;
	if (((xptr = start_clf(_CLF_USER,13)) != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, pvarb )) == 0)
	&&  ((status = store_clf( xptr, target)) == 0)
	&&  ((status = store_clf( xptr, library)) == 0))
		status = flush_void_clf(xptr);
	return((status = release_void_context(xptr,status)));
}

WORD		clf_segmptr( pvarb, target )
RESULTPTR	pvarb;
RESULTPTR	target;
{
	CLFPTR		xptr;
	WORD		status=27;
	if (((xptr = start_clf(_CLF_SEGM,13)) != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, pvarb )) == 0)
	&&  ((status = store_clf( xptr, target)) == 0))
		status = flush_void_clf(xptr);
	return((status = release_void_context(xptr,status)));
}

WORD		clf_remove( target )
RESULTPTR	target;
{
	CLFPTR		xptr;
	WORD		status=27;
	if (((xptr = start_clf(1,6)) != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, target)) == 0))
		status = flush_void_clf(xptr);
	return((status = release_void_context(xptr,status)));


}

WORD		clf_forget( target )
RESULTPTR	target;
{
	CLFPTR		xptr;
	WORD		status=27;
	if (((xptr = start_clf(2,6)) != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, target)) == 0))
		status = flush_void_clf(xptr);
	return((status = release_void_context(xptr,status)));
}

WORD	clf_mask( mvalue )
WORD	mvalue;
{
	CLFPTR		xptr;
	WORD		status=27;
	if (((xptr = start_clf(1,7)) != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, integer_result(mvalue))) == 0))
		status = flush_void_clf(xptr);
	return((status = release_void_context(xptr,status)));
}
WORD	clf_lang( mvalue )
WORD	mvalue;
{
	CLFPTR		xptr;
	WORD		status=27;
	if (((xptr = start_clf(8,7)) != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, integer_result(mvalue))) == 0))
		status = flush_void_clf(xptr);
	return((status = release_void_context(xptr,status)));
}

RESULTPTR	clf_hotkey()
{
	return( translate_clff(9) );
}

RESULTPTR	clf_conf(n)
WORD		n;
{
	CLFPTR		xptr;
	WORD		status;
	RESULTPTR	lptr;

	trace("clf_conf()\n");
	if (((xptr = start_clf(5,15)) != (CLFPTR) 0)
	&&  ((lptr = integer_result( n )) != (RESULTPTR) 0)
	&&  ((status = store_clf(xptr, lptr )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

RESULTPTR	clf_tokeniser( vptr, indent, rptr )
TCVARPTR	vptr;
WORD		indent;
RESULTPTR	rptr;
{
	CLFPTR		xptr;
	WORD		status;

	trace("clf_round()\n");
	if (((xptr = start_clf(7,12)) != (CLFPTR) 0)
	&&  ((status = store_clf(xptr, variable_result( vptr ) )) == 0)
	&&  ((status = store_clf(xptr,integer_result( indent ))) == 0)
	&&  ((status = store_clf(xptr, rptr )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

RESULTPTR	clf_round( rptr, nombre )
RESULTPTR	rptr;
WORD		nombre;
{
	CLFPTR		xptr;
	WORD		status;

	trace("clf_round()\n");
	if (((xptr = start_clf(1,14)) != (CLFPTR) 0)
	&&  ((status = store_clf(xptr, rptr )) == 0)
	&&  ((status = store_clf(xptr,integer_result( nombre ))) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

RESULTPTR	clf_len_dollar( vptr )
TCVARPTR	vptr;
{
	RESULTPTR	rptr;
	CLFPTR		xptr;
	WORD		status;

	trace("clf_len_dollar()\n");
	if (((xptr = start_clf(_CLFB_LEN$,11)) != (CLFPTR) 0)
	&&  ((rptr = variable_result( vptr )) != (RESULTPTR) 0)	
	&&  ((status = store_clf(xptr, rptr )) == 0)) 
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

RESULTPTR	clf_index( vptr, sptr )
RESULTPTR	vptr;
RESULTPTR	sptr;
{
	CLFPTR		xptr;
	WORD		status;

	trace("clf_index()\n");
	if (((xptr = start_clf(5,11)) != (CLFPTR) 0)
	&&  ((status = store_clf(xptr, vptr )) == 0)
	&&  ((status = store_clf(xptr, sptr )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

RESULTPTR	clf_includ( vptr, sptr )
RESULTPTR	vptr;
RESULTPTR	sptr;
{
	CLFPTR		xptr;
	WORD		status;

	trace("clf_includ()\n");
	if (((xptr = start_clf(1,8)) != (CLFPTR) 0)
	&&  ((status = store_clf(xptr, vptr )) == 0)
	&&  ((status = store_clf(xptr, sptr )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

RESULTPTR	clf_substr( sptr, debut, longueur )
RESULTPTR	sptr;
RESULTPTR	debut;
RESULTPTR	longueur;
{
	CLFPTR		xptr;
	WORD		status;

	trace("clf_substr()\n");
	if (((xptr = start_clf(2,12)) != (CLFPTR) 0)
	&&  ((status = store_clf(xptr, sptr )) == 0)
	&&  ((status = store_clf(xptr, debut)) == 0)
	&&  ((status = store_clf(xptr, longueur )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

RESULTPTR	clf_gener( vptr, rptr )
RESULTPTR	vptr;
RESULTPTR	rptr;
{
	CLFPTR		xptr;
	WORD		status;

	trace("clf_gener()\n");
	if (((xptr = start_clf(0,13)) != (CLFPTR) 0)
	&&  ((status = store_clf(xptr, vptr )) == 0)
	&&  ((status = store_clf(xptr, rptr )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(RESULTPTR) 0));
}

WORD	cancel_clf_instruction() 
{
	WORD	type;
	uppercase_keyword();
	if ((type = is_clf0()) != MOINS_UN)
		cancel_keyword( & clf0_keywords[type] );
	else if ((type = is_clf2()) != MOINS_UN)
		cancel_keyword( & clf2_keywords[type] );
	else if ((type = is_clf5()) != MOINS_UN)
		cancel_keyword( & clf5_keywords[type] );
	else if ((type = is_clf6()) != MOINS_UN)
		cancel_keyword( & clf6_keywords[type] );
	else if ((type = is_clf7()) != MOINS_UN)
		cancel_keyword( & clf6_keywords[type] );
	else if ((type = is_clf8()) != MOINS_UN)
		cancel_keyword( & clf8_keywords[type] );
	else if ((type = is_clf9()) != MOINS_UN)
		cancel_keyword( & clf9_keywords[type] );
	else if ((type = is_clfa()) != MOINS_UN)
		cancel_keyword( & clfa_keywords[type] );
	else if ((type = is_clfb()) != MOINS_UN)
		cancel_keyword( & clfb_keywords[type] );
	else if ((type = is_clfc()) != MOINS_UN)
		cancel_keyword( & clfc_keywords[type] );
	else if ((type = is_clfd()) != MOINS_UN)
		cancel_keyword( & clfd_keywords[type] );
	else if ((type = is_clfe()) != MOINS_UN)
		cancel_keyword( & clfe_keywords[type] );
	else if ((type = is_clff()) != MOINS_UN)
		cancel_keyword( & clff_keywords[type] );
	else	return( MOINS_UN );
	return( 0 );
}

#endif	/* _TRCLF_C */
	/* -------- */





