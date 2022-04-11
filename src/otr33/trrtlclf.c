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
/*		Date	:	28/09/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRRTLCLF_C
#define	_TRRTLCLF_C
#define	_TRCLF_C
#define	_GEN_C_RTL
#define	_C_RTL_GEN

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
#include "trgenc.h"
#include "trdebug.h"
#include "trtnode.h"

#ifndef	UNIX
BPTR		source_file_name( VOID );
BPTR		convert_explicite_format();
RESULTPTR	build_string_constant( RESULTPTR, BPTR );
RESULTPTR	build_numeric_term( RESULTPTR, BPTR );
RESULTPTR	variable_operand( VOID );
#else
BPTR		source_file_name();
BPTR		convert_explicite_format();
RESULTPTR	build_string_constant();
RESULTPTR	build_numeric_term();
RESULTPTR	variable_operand();
#endif

EXTERN	BYTE	KeyWord[65];
EXTERN	WORD	KeyWordHash;


#include "trarg.c"

static	WORD	UseDimensions=VRAI;

WORD	use_dimensions()
{
	return( UseDimensions );
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
		memset(xptr->descriptor,0,16);
		}
	return( xptr );
}

VOID	release_clf_context( xptr )
CLFPTR	xptr;
{
	ARGPTR	aptr;
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

BPTR	release_context( xptr, rptr )
CLFPTR		xptr;
BPTR	rptr;
{
	release_clf_context( xptr );
	return( rptr );
}


static	WORD	flush_clf_parameter(lparam,mode)
BPTR	lparam;
WORD	mode;
{
	if (lparam == (BPTR) 0)
		return( syntax_error(3100) );
	else	generate_clf_operand( lparam, mode );
	return( 0 );
}

VOID	flush_clf_format( fptr )
BPTR	fptr;
{
	(void) generate_clf_format( fptr );
	return;
}

static	WORD	flush_clf_parameters(xptr, rptr )
CLFPTR		xptr;
BPTR	rptr;
{
	ARGPTR		cptr;
	WORD		status=0;
	WORD		nombre=0;
	if ( rptr != (BPTR) 0)
		flush_clf_parameter( rptr );
	if ((( xptr->group == 7 ) && ( xptr->code == 2 ))
	||  (( xptr->group == 15) && ( xptr->code == 7 ))) {
		if ((status = flush_clf_parameter(RtlDataManagerName() , nombre++ )) != 0)
			return( status );
		}		
	if ((cptr = xptr->root) != (ARGPTR) 0) {
		do	{
			if ( cptr->format != (BPTR) 0 ) 
				flush_clf_format( cptr->format );
			else if ((status = flush_clf_parameter( cptr->operand, nombre++)) != 0)
				return( status );
			}
		while ((cptr = cptr->next) != (ARGPTR) 0);
		}
	return( 0 );
}

static	BPTR	clf_prefixed( nptr )
BPTR	nptr;
{
	BPTR	tptr;
	BYTE	buffer[32];
	WORD	i=0;
	WORD	c;

	while ((c = *(nptr++)) != 0) {
		if (( c >= 'A' ) && ( c <= 'Z'))
			buffer[i++] = ((c - 'A') + 'a');
		else if ( c == '$' )
			break;
		else buffer[i++] = c;
		}
	buffer[i] = 0;
	if ((tptr = allocate_for_tnode( strlen( buffer ) + 5 )) != (BPTR) 0)
		sprintf(tptr,"clf_%s",buffer);

	return( tptr );
}
static	BPTR	clf_at_prefixed( nptr )
BPTR	nptr;
{
	BPTR	tptr;
	BYTE	buffer[32];
	WORD	i=0;
	WORD	c;

	while ((c = *(nptr++)) != 0) {
		if (( c >= 'A' ) && ( c <= 'Z'))
			buffer[i++] = ((c - 'A') + 'a');
		else if ( c == '$' )
			break;
		else buffer[i++] = c;
		}
	buffer[i] = 0;
	if ((tptr = allocate_for_tnode( strlen( buffer ) + 5 )) != (BPTR) 0)
		sprintf(tptr,"@clf_%s",buffer);

	return( tptr );
}

static	BPTR	rtl_function_name( group, code )
WORD	group;
WORD	code;
{
	switch ( group ) {
		case	5	:
			return( "clf_validptr" );
		case	6	: 
			if ( code == 3 )
				return( "@clf_alias" );
			else if ( code == 14 )
				return( "@clf_attach_handle" );
			else if ( code == 34 )
				return( "@clf_attach_filename");
			else	return( clf_at_prefixed(clf6_keywords[code]) );
		case	7	: 
			if ( code == 2 )
				return( "clf_setrestore" );
			else if ( code == 4 )
				return( "@clf_setkbf" );
			else if ( code == 3 )
				return( "@clf_setdate" );
			else	return( clf_prefixed(clf7_keywords[code]) );

		case	8	: return( clf_prefixed(clf8_keywords[code]) );
		case	9	: return( clf_prefixed(clf9_keywords[code]) );
		case	10	: return( clf_prefixed(clfa_keywords[code]) );
		case	11	: 
			if ( code != 2 )
				return( clf_prefixed(clfb_keywords[code]) );
			else	return( "clf_length" );
		case	12	: return( clf_prefixed(clfc_keywords[code]) );
		case	13	: 
			if ( code == 3 ) 
				return( "@clf_kbf" );
			else 	return( clf_prefixed(clfd_keywords[code]) );
		case	14	: return( clf_prefixed(clfe_keywords[code]) );
		case	15	: 
			if ( code != 7 )
				return( clf_prefixed(clff_keywords[code]) );
			else	return( "clf_getrestore" );
		default		: return( "clf_generic" );
		}	
}

static	WORD	flush_void_clf(xptr)
CLFPTR	xptr;
{
	WORD		status;
	BPTR	rptr=(BPTR) 0;
	open_void_rtlclf( rtl_function_name( xptr->group, xptr->code ) );
	if  ((status = flush_clf_parameters(xptr, rptr ))   == 0)
		return( close_void_rtlclf() );
	else	return( status );
}

BPTR	make_target_pointer(mode)
WORD		mode;			/* VRAI : Error if not Var 	*/
{
	BPTR	tptr=(BPTR) 0;

	if (Context->TargetVariable != (TCVARPTR) 0 ) {
		if ((tptr = generate_pointer_vector(Context->TargetVariable)) != (BPTR) 0) {
			Context->TargetVariable = (TCVARPTR) 0;
			Context->ConvertType    = 2;
			}
		else	(void) allocation_failure();
		}
	else if (!( mode )) {
		tptr = NewStringRegister(0);
		}
	else	(void) syntax_error(3100);
	return( tptr );
}

BPTR	make_target_variable(mode)
WORD		mode;			/* VRAI : Error if not Var 	*/
					/* FAUX : Register if not VAR 	*/
{
	BPTR	tptr=(BPTR) 0;
	if (Context->TargetVariable != (TCVARPTR) 0 ) {
		if ((tptr = variable_svalue(Context->TargetVariable)) != (BPTR) 0) {
			Context->TargetVariable = (TCVARPTR) 0;
			Context->ConvertType    = 2;
			}
		else	(void) allocation_failure();
		}
	else if (!( mode )) {
		tptr = NewStringRegister(0);
		}
	else	(void) syntax_error(3100);
	return( tptr );
}

static	BPTR	make_clf_target( xptr )
CLFPTR	xptr;
{
	BPTR	rptr;
	switch ( (xptr->group | (xptr->code << 4)) ) {
		case 0x0015	:	/* ALIAS	*/
			xptr->group = 6;
			xptr->code  = 3;
			return( make_target_pointer(FAUX) );

		case 0x0018	:	/* INCLUD 	*/
		case 0x0028	:	/* INSERT	*/
		case 0x0038	:	/* TRANS	*/

		case 0x005A 	:	/* FM		*/
		case 0x006A	:	/* FM		*/
		case 0x007A	:	/* FM		*/

		case 0x003C	:	/* MOVE 	*/
		case 0x004C	:	/* SWAP 	*/

		case 0x003D	:	/* KBF(get)	*/
		case 0x009D	:	/* CRYPT 	*/
		case 0x00BD     :	/* PROC		*/
		case 0x00CD     :	/* SEGM		*/
		case 0x00DD     :	/* USER		*/
		case 0x00ED	:	/* IPCTEST	*/
		case 0x00FD	:	/* IPCWAIT	*/

			return( make_target_variable(VRAI) );

		default		:

				switch ( xptr->group ) {
					case	11 :
					case	15 :
					case 	5  : 
						rptr = "\0";
						break;

					case	8  :
					case 	9  :
						rptr = NewBcdRegister();
						break;
					case	14 :
						if ( xptr->code <= 6 )
							rptr = NewBcdRegister();
						else	rptr = NewStringRegister(0);
						break;
					case	10 : 
					case	12 :
					case	13 :
						rptr = NewStringRegister(0);
						break;

					}
			return( rptr );
		}
}

static	BPTR	function_filter( xptr )
CLFPTR	xptr;
{
	switch ( (xptr->group | (xptr->code << 4)) ) {
		case	0x009E	:	/* MOD		*/
/*	return( arithmetic( '%', xptr->root->operand, xptr->root->next->operand ) );	*/
		default		:
			return((BPTR) 0);
		}
}

WORD	RecentClfType=MOINS_UN;

VOID	set_recent_clf_type( xptr )
CLFPTR	xptr;
{
	switch ( xptr->group ) {
		case	11 :
		case	15 :
		case 	5  : 
			RecentClfType = 1;
			break;
		case	8  :
		case 	9  :
		case	14 :
			RecentClfType = 2;
			break;
		case	10 : 
		case	12 :
		case	13 :
			RecentClfType = 3;
			break;
		default	:
			RecentClfType = MOINS_UN;
			break;

		}
	return;
}

/*
 *	F L U S H _ C L P
 *	-----------------
 *
 *
 */

static	BPTR	flush_clf(xptr)
CLFPTR	xptr;
{
	BPTR	rptr=(BPTR) 0;
	WORD	status;
	BPTR	wptr=(BPTR) 0;
	WORD	nombre=0;
	ARGPTR	cptr;

	trace("flush_clf()\n");
	/* Filter out special functions (Mod etc) */
	/* -------------------------------------- */
	if ((rptr = function_filter( xptr )) != (BPTR) 0)
		return( rptr );

	set_recent_clf_type( xptr );

	if ((rptr = make_clf_target(xptr))     != (BPTR) 0) {
		if ((wptr = open_rtlclf(rtl_function_name( xptr->group, xptr->code ))) == (BPTR) 0)
			return(wptr);
		if ((( xptr->group == 7 ) && ( xptr->code == 2 ))
		||  (( xptr->group == 15) && ( xptr->code == 7 ))) {
			if ((wptr = add_rtlclf(wptr,RtlDataManagerName(),nombre++ )) == (BPTR) 0)
				return( wptr  );
			}		
		if (strlen(rptr)) {
			if ((wptr = add_rtlclf(wptr,rptr,nombre++)) == (BPTR) 0)
				return( wptr );
			}
		else	trace("integer_or_void_clf\n");
		if ((cptr = xptr->root) != (ARGPTR) 0) {
			do	{
				if ( cptr->format != (BPTR) 0 ) {
					if ((wptr = add_rtlclf_format(wptr,cptr->format,nombre++)) == (BPTR) 0)
						return( wptr );
					}
				else if ((wptr = add_rtlclf(wptr,cptr->operand, nombre++)) == (BPTR) 0)
					return(wptr);
				}
			while ((cptr = cptr->next) != (ARGPTR) 0);
			}

		if ((wptr = close_rtlclf(wptr)) ==(BPTR) 0)
			return(wptr);

		if (strlen(rptr)) {
			output_rtlclf(wptr);
			return(rptr);
			}
		else	return(wptr);
		}
	return( rptr );
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
BPTR	rptr;
{
	ARGPTR	cptr;
	trace("store_clf()\n");
	if ( rptr == (BPTR) 0 )
		return( syntax_error(3100) );
	if ( *rptr == '#' )
		rptr += 2;
	if ((cptr = allocate_for_operand()) == (ARGPTR) 0)
		return( allocation_failure() );
	cptr->operand = rptr;
	if ((cptr->prev = xptr->last) == (ARGPTR) 0)
		xptr->root = cptr;
	else	xptr->last->next = cptr;
	xptr->last = cptr;
	return( 0 );
}

WORD	get_string_parameter(xptr)
CLFPTR	xptr;
{
	BPTR	rptr;
	if ((rptr = StringExpression()) != (BPTR) 0)
		return( store_clf(xptr, rptr ) );
	else	return( syntax_error(3100) ); 
}

WORD	get_integer_parameter(xptr)
CLFPTR	xptr;
{
	BPTR	rptr;
	if ((rptr = IntegerExpression()) != (BPTR) 0)
		return( store_clf(xptr, rptr ) );
	else	return( syntax_error(3100) ); 
}

WORD	get_numeric_parameter(xptr)
CLFPTR	xptr;
{
	BPTR	rptr;
	if ((rptr = BcdExpression()) != (BPTR) 0)
		return( store_clf(xptr, rptr ) );
	else	return( syntax_error(3100) ); 
}

WORD	get_parameter( xptr )
CLFPTR	xptr;
{
	BPTR	rptr;
	if ((rptr = EvaluateExpression()) != (BPTR) 0)
		return( store_clf(xptr, rptr ) );
	else	return( syntax_error(3100) ); 
}

WORD	optional_parameters( xptr )
CLFPTR	xptr;
{
	BPTR	rptr;
	WORD		status;
	trace("optional_parameters()\n");
	if ( is_left_brace() ) {
		do	{
			if ((rptr   = EvaluateExpression()) == (BPTR) 0)
				return( syntax_error(3100) );
			else if  ((status = store_clf(xptr, rptr )) != 0)
				return( syntax_error(3100) ); 
			}
		while ( is_comma() );
		if (!(is_right_brace()))
			return( unmatched_braces());
		}
	return(0);
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

static	WORD	translate_clf1( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr=(CLFPTR) 0;

	if (((xptr = start_clf(13,7))        != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, integer_result(semaphore(type)))) == 0)
	&&  ((status = optional_parameters(xptr))	== 0)
	&&  ((status = flush_void_clf(xptr))		== 0))
		return( release_void_context(xptr,status) );
	else	return( release_void_context(xptr,status) );
}

static	BPTR	translate_clf2( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr=(CLFPTR) 0;

	if (((xptr = start_clf(10,15))        != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, integer_result(type+10))) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(BPTR) 0));
}

#ifdef	_BEFORE_19031998

/*
 *	CREATE	<pointer> [ ( <dimensions> ) ]
 *	REMOVE	<pointer> [ ( <dimensions> ) ]
 *	FORGET	<pointer> 
 *	ATTACH	<pointer> ( <handle> | <filename> )
 *	DETACH	<pointer> 
 *	ALTER	<pointer> [ ( <dimensions> ) ]
 */

static	WORD	collect_pointer_operands( xptr )
CLFPTR		xptr;
{
	BPTR		aptr;
	TCVARPTR	vptr;
	WORD		status;
	WORD		mode=0;

	if ((!( get_token() ))
	||  (( vptr = VariableOperand()) == (TCVARPTR) 0))
		return( syntax_error(3100) );
	if ((status = store_clf( xptr, generate_pointer_adresse( vptr ))) != 0)
		return( status );
	if ( is_left_brace() ) {
		if ( xptr->code == 4 ) {	/* ATTACH */
			if ((status = store_clf( xptr, (aptr = EvaluateExpression() ))) != 0)
				return( status );
			if ( *(aptr+1) != '3' )
				xptr->code = 14;
			else	xptr->code = 34;

			if (!( is_right_brace() ))
				return( unmatched_braces() );
			else	return( 0 );
			}
		else	{
			do	{
				if ((status = store_clf( xptr, IntegerExpression())) != 0)
					return( status );
				else	mode++;
				}
			while ( is_comma() );
			if (!( is_right_brace() ))
				return( unmatched_braces() );
			}
		}

	/* Test ATTACH/DETACH 4 or 5 */
	if (( xptr->code == 4 ) || ( xptr->code == 5))
		return( 0 );
	if ( mode < 1 ) {
		if ((status = store_clf( xptr, IntegerResult( vptr->type->size ))) != 0)
			return( status );
		mode++;
		}
	if ( mode < 2 ) {
		if ((status = store_clf( xptr, IntegerResult( vptr->type->first))) != 0)
			return( status );
		mode++;
		}
	if ( mode < 3 ) {
		if ((status = store_clf( xptr, IntegerResult( vptr->type->second))) != 0)
			return( status );
		mode++;
		}
	if ( mode < 4 )
		return( 0 );
	else	return( syntax_error(3100) );
}

static	WORD	translate_clf6( type )
WORD	type;
{
	WORD		status;
	CLFPTR		xptr=(CLFPTR) 0;
	TCVARPTR	vptr;

	do 	{
		if (((xptr = start_clf(type,6))        != (CLFPTR) 0)
		&&  ((status = collect_pointer_operands(xptr)) ==  0) 
		&&  ((status = flush_void_clf(xptr))		== 0)) {
			if ((status = release_void_context(xptr,status)) != 0)
				return( status );
			else	xptr = (CLFPTR) 0;
			}
		else	return( release_void_context(xptr,status) );
		}
	while ( is_comma() );
	return(0);
}
#else

static	WORD	eligible_for_clf6( code , object )
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
 *	CREATE	<pointer> [ ( <dimensions> ) ]
 *	REMOVE	<pointer> [ ( <dimensions> ) ]
 *	FORGET	<pointer> 
 *	ATTACH	<pointer> ( <handle> | <filename> )
 *	DETACH	<pointer> 
 *	ALTER	<pointer> ( <dimensions> )
 */

static	WORD	clf6_parameters(xptr)
CLFPTR	xptr;
{
	WORD		status;
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

	if ((!( get_token() ))
	||  (( object = VariableOperand()) == (TCVARPTR) 0))
		return( syntax_error(3100) );
	if ((status = store_clf( xptr, generate_pointer_adresse( object ))) != 0)
		return( status );

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
			return(  syntax_error(722) );
		}
 
	switch ( xptr->code ) {

		case	_CLF_ALTER  :
			if ((status = optional_parameters(xptr)) != 0)
				return( status );
			else	return(0);
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

	if ( xptr->code == _CLF_ATTACH)
		return( 0 );
	else if ( xptr->code != _CLF_BUILD ) {
		if (((status = optional_parameters(xptr)) == 0)
		&&  ( xptr->code == _CLF_EVALUATE )
		&&  ( is_colon() ))
			return( optional_parameters( xptr ) );
		else	return( status );
		}
	else	return( 7756 );
}

static	WORD	translate_clf6( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr=(CLFPTR) 0;
	do 	{
		if (((xptr = start_clf(type,6))         != (CLFPTR) 0)
		&&  ((status = clf6_parameters(xptr))	== 0)) {
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

#endif	/* _BEFORE_19031998 */
	/* ---------------- */
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
	BPTR	rptr=(BPTR) 0;

	/* Remove potential '=' */
	/* -------------------- */
	(void) is_equals();

	/* Collect potential '(' */
	/* --------------------- */
	braces = is_left_brace();

	/* Collect Potential First Parameter */
	/* --------------------------------- */
	if ((rptr = EvaluateExpression()) == (BPTR) 0)
		return( 0 );

	/* And attempt to Store it */
	/* ----------------------- */
	else if ((status = store_clf(xptr, rptr )) != 0)
		return( syntax_error(3100) ); 

	/* Collect Potential Second Parameter */
	/* ---------------------------------- */
	if ( is_comma() ) {
		if (((rptr = EvaluateExpression()) == (BPTR) 0)
		||  ((status = store_clf(xptr, rptr )) != 0))
			return( syntax_error(3100) ); 
		}

	/* Check for braces closed if Opened */
	/* --------------------------------- */
	if (( braces )
	&&  (!( is_right_brace() )))
		return( unmatched_braces() );
 
	/* Check for final possible Pseudo Affectation */
	/* ------------------------------------------- */
	if ( is_equals() ) {
		if (((rptr = EvaluateExpression()) == (BPTR) 0)
		||  ((status = store_clf(xptr, rptr )) != 0))
			return( syntax_error(3100) ); 
		}

	return(0);
}

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
			else	return( syntax_error(3100) );
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
 

static	BPTR	translate_clf8( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr;
	if (((xptr = start_clf(type,8))  != (CLFPTR) 0)
	&&  ((status = optional_parameters(xptr)) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(BPTR) 0));
}


static	BPTR	translate_clf_mod()
{
	BPTR	lptr;
	BPTR	rptr;
	WORD	type;
	if (!( is_left_brace() ))
		return("<brace_expected>,0");
	if ((lptr = EvaluateExpression()) == (BPTR) 0)
		return((BPTR) 0);
	if (!( is_comma() ))
		return("<comma_expected>,0");
	if ( *lptr == '#' ) {
		lptr++;
		type = ( *(lptr++) - '0' );
		}
	else	type = 1;
	if ( type > 1 ) {
		RecentClfType = 2;
		if ((rptr = BcdExpression()) == (BPTR) 0)
			return( rptr );
		else if (!( is_right_brace() ))
			return("<unmatched_braces>,0");
		else 	return( BcdOperation('%',lptr,rptr) );
		}
	else	{
		RecentClfType = 1;
		if ((rptr = allocate_for_tnode( strlen( lptr ) + 8 )) == (BPTR) 0)
			return( rptr );
		sprintf(rptr,"(%s)",lptr);
		lptr = rptr;
		if ((rptr = IntegerExpression()) == (BPTR) 0)
			return( rptr );
		else if (!( is_right_brace() ))
			return("<unmatched_braces>,0");
		else if ((lptr = IntegerOperation('%',lptr,rptr)) == (BPTR) 0)
			return( lptr );
		else if ((rptr = allocate_for_tnode( strlen( lptr ) + 8 )) == (BPTR) 0)
			return( rptr );
		sprintf(rptr,"(%s)",lptr);
		return( rptr );
		}
}


static	BPTR	translate_clf9( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr;
	if (((xptr = start_clf(type,9))  != (CLFPTR) 0)
	&&  ((status = optional_parameters(xptr)) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(BPTR) 0));
}


static	BPTR	translate_clf_fm( type )
WORD	type;
{
	WORD		status;
	BPTR		rptr;
	CLFPTR		xptr;
	BPTR		fptr;
	WORD		l;
	WORD		varlen=0;

	if ((xptr = start_clf(type,10)) != (CLFPTR) 0) {
		if (!( is_left_brace() ))
			syntax_error(3100);
		else	{
			if ( is_left_brace() ) {
				if (((rptr   = VariableExpression((WPTR) & varlen)) == (BPTR) 0)
				||  ((status = store_clf(xptr, rptr )) != 0))
					(void) syntax_error(3100);
				else if (((rptr = IntegerResult( varlen )) == (BPTR) 0)
				     ||   ((status = store_clf(xptr, rptr )) != 0))
					(void) syntax_error(3100);
				if (!( is_right_brace() ))
					(void) unmatched_braces();
				}
			else	{
				if (( get_format() )
				&&  ((fptr = allocate_for_tnode( ((l = strlen(TokenBuffer)) + 16) )) != (BPTR) 0)) {
					sprintf(fptr,"%c%s%c,%u",0x0022,TokenBuffer,0x0022,l);
					(void) store_clf( xptr, fptr );
					}
				else	return( release_context(xptr,(BPTR) 0));
				}
			if (!( is_right_brace()))
				(void) unmatched_braces();
			else	{
				return( release_context(xptr,flush_clf(xptr)));
				}
			}
		}
	return( release_context(xptr,(BPTR) 0));
}

static	BPTR	translate_clfa( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr;

	trace("translate_clfa()\n");

	if ( type == 5 ) /* CLF_FM */
		return( translate_clf_fm( type ) );

	if (((xptr = start_clf(type,10)) != (CLFPTR) 0)
	&&  ((status = optional_parameters(xptr)) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(BPTR) 0));
}

static	BPTR	translate_clfb( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr;
	trace("translate_clfb()\n");

	if (( type == _CLFB_LEN )
	&&  ( is_dollar()       ))
		type = _CLFB_LEN$;

	if (((xptr = start_clf(type,11)) != (CLFPTR) 0)
	&&  ((status = optional_parameters(xptr)) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(BPTR) 0));
}


static	BPTR	translate_clfc( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr;
	trace("translate_clfc()\n");
	if (((xptr = start_clf(type,12)) != (CLFPTR) 0)
	&&  ((status = optional_parameters(xptr)) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(BPTR) 0));
}

static	BPTR	clf_affect_pointer( type, rptr )
WORD		type;
BPTR	rptr;
{
	CLFPTR	xptr;
	WORD	status;
	trace("clf_affect_pointer()\n");
	if (((xptr = start_clf(type,13)) != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, rptr ))   == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(BPTR) 0));
}

static	BPTR	affect_code_pointer( type )
WORD	type;
{
	TCPRCPTR	pptr;
	TCVARPTR	vptr;
	BPTR	rptr=(BPTR) 0;
	WORD		braces;
	trace("affect_code_pointer()\n");
	if (( get_token() )
	&&  ( is_level1_keyword() == _KW1_PTR ))  {
		braces = is_left_brace();
		if ( get_token() ) {

			if ((pptr = is_procedure()) != (TCPRCPTR) 0)
				rptr = pptr->name;
			else if ((vptr = is_variable(1)) != (TCVARPTR) 0)
				rptr = generate_variable_name( vptr );

			if ( rptr != (BPTR) 0 ) {
		
				if ((braces)
				&& (!( is_right_brace()))) {
					(void) syntax_error(3100);
					return( (BPTR) 0 );
					}
				return( clf_affect_pointer( type, rptr ) );
				}
			}
		}
	(void) syntax_error(3100);
	return( (BPTR) 0 );
}

static	BPTR	translate_clfd( type )
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
			if (!( is_dollar() ))
				return( syntax_error( 718 ) );

		default		:
		
			if (((xptr = start_clf(type,13)) != (CLFPTR) 0)
			&&  ((status = optional_parameters(xptr)) == 0))
				return( release_context(xptr,flush_clf(xptr)));
			else	return( release_context(xptr,(BPTR) 0));
		}
}

static	BPTR	translate_clfe( type )
WORD	type;
{
	WORD	status;
	CLFPTR	xptr;
	if ((xptr = start_clf(type,14)) != (CLFPTR) 0) {
		if ( is_left_brace() ) {
			if ( type == 4 )
				status = store_clf( xptr, StringExpression() );
			else	status = store_clf( xptr, BcdExpression() );
			if ( status == 0 ) {
				if (( type < 2 )	/* FIX / ROUND 	*/
				||  ( type == 6) 	/* REAL		*/
				||  ( type == 4)) { 	/* VAL 		*/
					if ( is_comma() )
						status = store_clf( xptr, IntegerExpression() );
					else	status = store_clf( xptr, IntegerResult( 0 )  );
					if ( status != 0 )
						return( release_context(xptr,(BPTR) 0));
					}
				if ( is_right_brace() )
					return( release_context(xptr,flush_clf(xptr)));
				}
			}
		}
	return( release_context(xptr,(BPTR) 0));
}

BPTR	RtlConvertToType( BPTR, WORD );

static	BPTR	translate_conv( type )
WORD	type;
{
	BPTR	rptr;
	trace("translate_conv()\n");
	if (( is_left_brace() ) 
	&&  ((rptr = EvaluateExpression()) != (BPTR) 0)
	&&  ( is_right_brace() )
	&&  ((rptr = RtlConvertToType(rptr, type)) != (BPTR) 0)) {
		RecentClfType = type;
		return( rptr );
		}
	else	return( (BPTR) 0);
}

static	BPTR	translate_tr_date()
{
	return( "#DATE" );
}

static	BPTR	translate_tr_time()
{
	return( "#TIME" );
}

static	BPTR	translate_tr_file()
{
	BPTR	rptr;
	if ((rptr = allocate_for_tnode(strlen(source_file_name())+3)) != (BPTR) 0)
		sprintf(rptr,"%c%s%c",0x0022,source_file_name(),0x0022);
	return( rptr );
}

static	BPTR	translate_tr_line()
{
	return( IntegerResult( source_file_line() ) );
}



static	BPTR	translate_clf0( type )
WORD	type;
{
	WORD		status;
	BPTR	rptr;

	switch ((type)) {

		case 	_CLF_CONV  	:
			if ( is_dollar() )
				type = _CLF_CONV3;
			if ( is_dieze() )
				type = _CLF_CONV0;
			if ( is_percent() )
				type = _CLF_CONV1;
			else	{
				if (( Context->Depth == 1 )
				&&  ( Context->TargetVariable != (TCVARPTR) 0 )
				&&  ( Context->TargetVariable->type != (TCTYPPTR) 0))
					type = (Context->TargetVariable->type->type & 3);
				else	type = 2;
				}

		case	_CLF_CONV0	:
		case	_CLF_CONV1	:
		case	_CLF_CONV3	:
			return( translate_conv( type ) );

		case	_CLF_MOD  	:
			return( translate_clf_mod() );

		case	_CLF_PRINT	:
			if ( translate_clf_print((rptr = make_target_variable())) != 0 )
				return( (BPTR) 0 );
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
			return( IntegerResult(0) );
		}

}

static	BPTR	translate_clff( type )
WORD	type;
{
	WORD	status;
	BPTR	rptr;
	CLFPTR	xptr;
	if ((xptr = start_clf(type,15)) != (CLFPTR) 0) {
		if ( type < 2 ) {
			if ((rptr = IntegerExpression()) == (BPTR) 0)
				rptr = IntegerResult(1);
			if ((rptr != (BPTR) 0)
			&&  ((status = store_clf( xptr, rptr )) == 0))
				return( release_context(xptr,flush_clf(xptr)));
			}
		else if ((status = optional_parameters(xptr)) == 0)
			return( release_context(xptr,flush_clf(xptr)));
		}
	return( release_context(xptr,(BPTR) 0));
}

static	BPTR	translate_clf5( type )
WORD	type;
{
	TCVARPTR	vptr;
	WORD		status;
	CLFPTR		xptr;
	if (((xptr = start_clf(type,5)) != (CLFPTR) 0)
	&&  ( is_left_brace() )) {
		if ( type == 0 ) { /* VALIDPTR */
			if ((!( get_token() ))
			||  (( vptr = is_variable(1)) == (TCVARPTR) 0)
			||  ((status = store_clf( xptr, generate_pointer_adresse( vptr ))) != 0))
				status = syntax_error(3100);
			}
		else	{
			if ( is_mnemonic("NULL") ) {
				status = store_clf( xptr, IntegerResult(0) );
				status = store_clf( xptr, IntegerResult(0) );
				}
			else	status = store_clf( xptr, EvaluateExpression());
			}
		if ((status == 0 )
		&&  ( is_right_brace() ))
			return( release_context(xptr,flush_clf(xptr)));
		}
	return( release_context(xptr,(BPTR) 0));
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
		if ( compare_tokens( KeyWord, clf2_keywords[ i ] ) )
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
	if ((type = is_clf6()) != MOINS_UN)
		return( translate_clf6(type) );
	else if ((type = is_clf1()) != MOINS_UN)
		return( translate_clf1(type) );
	else if ((type = is_clf7()) != MOINS_UN)
		return( translate_clf7(type) );
	else	return( MOINS_UN );

}

/*	Evaluation of NON-VOID Common Library Functions		*/
/*	-----------------------------------------------		*/

BPTR	evaluate_clf()
{
	WORD	type;
	trace("evaluate_clf(");
	trace( TokenBuffer );
	trace(")\n");
	
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
	else	return( intrinsic_functions() );
}

BPTR	clf_abs_zero()
{
	CLFPTR		xptr;
	WORD		status;
	BPTR	lptr;

	trace("clf_abs()\n");
	if (((xptr = start_clf(1,13)) != (CLFPTR) 0)
	&&  ((lptr = IntegerResult(0)) != (BPTR) 0)
	&&  ((status = store_clf(xptr, lptr )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(BPTR) 0));
}

BPTR	clf_space( l )
WORD		l;
{
	CLFPTR		xptr;
	WORD		status;
	BPTR	lptr;

	trace("clf_space()\n");
	if (((xptr = start_clf(1,13)) != (CLFPTR) 0)
	&&  ((lptr = IntegerResult( l )) != (BPTR) 0)
	&&  ((status = store_clf(xptr, lptr )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(BPTR) 0));
}

BPTR	TypePrefixed( BPTR, WORD );
BPTR	TypedClf()
{
	BPTR	rptr;
	if ((rptr = evaluate_clf()) != (BPTR) 0)
		return( TypePrefixed( rptr, RecentClfType ) );
	else	return( rptr );
}


#ifdef	_NEEDED_FOR_COBOL

BPTR	clf_date( n )
WORD		n;
{
	CLFPTR		xptr;
	WORD		status;
	BPTR	lptr;
	trace("clf_date()\n");
	if (((xptr = start_clf(2,13)) != (CLFPTR) 0)
	&&  ((lptr = IntegerResult( n )) != (BPTR) 0)
	&&  ((status = store_clf(xptr, lptr )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(BPTR) 0));
}

WORD		clf_create( target )
BPTR	target;
{
	CLFPTR		xptr;
	WORD		status=27;
	if (((xptr = start_clf(0,6))        	 != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, target)) == 0))
		status = flush_void_clf(xptr);
	return((status = release_void_context(xptr,status)));
}

WORD		clf_alias( pvarb, target )
BPTR	pvarb;
BPTR	target;
{
	CLFPTR		xptr;
	WORD		status=27;
	if (((xptr = start_clf(3,6))        	 != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, pvarb )) == 0)
	&&  ((status = store_clf( xptr, target)) == 0))
		status = flush_void_clf(xptr);
	return((status = release_void_context(xptr,status)));
}

WORD		clf_remove( target )
BPTR	target;
{
	CLFPTR		xptr;
	WORD		status=27;
	if (((xptr = start_clf(1,6)) != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, target)) == 0))
		status = flush_void_clf(xptr);
	return((status = release_void_context(xptr,status)));


}

WORD		clf_forget( target )
BPTR		target;
{
	CLFPTR		xptr;
	WORD		status=27;
	if (((xptr = start_clf(2,6)) != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, target)) == 0))
		status = flush_void_clf(xptr);
	return((status = release_void_context(xptr,status)));
}

WORD		clf_userptr( pvarb, target, library )
BPTR	pvarb;
BPTR	library;
BPTR	target;
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
BPTR	pvarb;
BPTR	target;
{
	CLFPTR		xptr;
	WORD		status=27;
	if (((xptr = start_clf(_CLF_SEGM,13)) != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, pvarb )) == 0)
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
	&&  ((status = store_clf( xptr, IntegerResult(mvalue))) == 0))
		status = flush_void_clf(xptr);
	return((status = release_void_context(xptr,status)));
}
WORD	clf_lang( mvalue )
WORD	mvalue;
{
	CLFPTR		xptr;
	WORD		status=27;
	if (((xptr = start_clf(8,7)) != (CLFPTR) 0)
	&&  ((status = store_clf( xptr, IntegerResult(mvalue))) == 0))
		status = flush_void_clf(xptr);
	return((status = release_void_context(xptr,status)));
}

BPTR	clf_hotkey()
{
	return( translate_clff(9) );
}

BPTR	clf_conf(n)
WORD		n;
{
	CLFPTR		xptr;
	WORD		status;
	BPTR	lptr;

	trace("clf_conf()\n");
	if (((xptr = start_clf(5,15)) != (CLFPTR) 0)
	&&  ((lptr = IntegerResult( n )) != (BPTR) 0)
	&&  ((status = store_clf(xptr, lptr )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(BPTR) 0));
}

BPTR	clf_round( rptr, nombre )
BPTR	rptr;
WORD	nombre;
{
	CLFPTR		xptr;
	WORD		status;

	trace("clf_round()\n");
	if (((xptr = start_clf(1,14)) != (CLFPTR) 0)
	&&  ((status = store_clf(xptr, rptr )) == 0)
	&&  ((status = store_clf(xptr,IntegerResult( nombre ))) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(BPTR) 0));
}

BPTR	clf_index( vptr, sptr )
BPTR	vptr;
BPTR	sptr;
{
	CLFPTR		xptr;
	WORD		status;

	trace("clf_index()\n");
	if (((xptr = start_clf(5,11)) != (CLFPTR) 0)
	&&  ((status = store_clf(xptr, vptr )) == 0)
	&&  ((status = store_clf(xptr, sptr )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(BPTR) 0));
}

BPTR	clf_includ( vptr, sptr )
BPTR	vptr;
BPTR	sptr;
{
	CLFPTR		xptr;
	WORD		status;
	trace("clf_includ()\n");
	if (((xptr = start_clf(1,8)) != (CLFPTR) 0)
	&&  ((status = store_clf(xptr, vptr )) == 0)
	&&  ((status = store_clf(xptr, sptr )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(BPTR) 0));
}

BPTR	clf_substr( sptr, debut, longueur )
BPTR	sptr;
BPTR	debut;
BPTR	longueur;
{
	CLFPTR		xptr;
	WORD		status;

	trace("clf_substr()\n");
	if (((xptr = start_clf(2,12)) != (CLFPTR) 0)
	&&  ((status = store_clf(xptr, sptr )) == 0)
	&&  ((status = store_clf(xptr, debut)) == 0)
	&&  ((status = store_clf(xptr, longueur )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(BPTR) 0));
}

BPTR	clf_gener( vptr, rptr )
BPTR	vptr;
BPTR	rptr;
{
	CLFPTR		xptr;
	WORD		status;

	trace("clf_gener()\n");
	if (((xptr = start_clf(0,13)) != (CLFPTR) 0)
	&&  ((status = store_clf(xptr, vptr )) == 0)
	&&  ((status = store_clf(xptr, rptr )) == 0))
		return( release_context(xptr,flush_clf(xptr)));
	else	return( release_context(xptr,(BPTR) 0));
}


#endif	/* */

RESULTPTR	clf_validptr( vptr )
TCVARPTR	vptr;
{
	return( (RESULTPTR) 0 );
}

WORD	clf_create( rptr )
RESULTPTR	rptr;
{
	return( generate_rtl_create( rptr->contents ) );
}

WORD	clf_remove( rptr )
RESULTPTR	rptr;
{
	return( generate_rtl_remove( rptr->contents ) );
}

WORD		clf_forget( rptr )
RESULTPTR	rptr;
{
	return( generate_rtl_forget( rptr->contents ) );
}

WORD		clf_userptr( pvarb, target, library )
RESULTPTR	pvarb;
RESULTPTR	library;
RESULTPTR	target;
{
	sysprintf("\n** USERPTR **\n");
	return( 0 );
}

WORD		clf_alias( rptr, sptr )
RESULTPTR	rptr;
RESULTPTR	sptr;
{
	return( generate_rtl_alias( rptr->contents, sptr->contents ) );
}

WORD		clf_funcptr( pvarb, target, pptr )
RESULTPTR	pvarb;
RESULTPTR	target;
TCPRCPTR	pptr;
{
	return( generate_rtl_funcptr( pvarb->contents, target->value ) );
}

WORD		clf_segmptr( pvarb, target )
RESULTPTR	pvarb;
RESULTPTR	target;
{
	return( generate_rtl_segmptr( pvarb->contents, target->value ) );
}


BPTR 	clf_reg_alias( rptr )
RESULTPTR	rptr;
{
	sysprintf("\n** ALIAS **\n");
	return( (BPTR) 0 );
}

BPTR	ExtractLength( rptr )
BPTR	rptr;
{
	BPTR	tptr;
	if (( tptr = allocate_for_tnode( strlen(rptr) + 16 )) != (BPTR) 0)
		sprintf(tptr,"clf_length(%s)",rptr);
	return( tptr );
}

BPTR	add_dummy_length( tptr )
BPTR	tptr;
{
	BPTR	rptr;
	if ((rptr = allocate_for_tnode( strlen( tptr ) + 16 )) != (BPTR) 0)
		sprintf(rptr,"%s,2",tptr);
	return( rptr );
}

WORD	translate_rtlclf_move()
{
	CLFPTR		xptr;
	WORD		status;
	WORD		varlen;
	BPTR		tptr;
	WORD		type;
	trace("rtlclf_move()\n");
	if (((xptr = start_clf(3,12)) != (CLFPTR) 0)
	&&  ( is_left_brace() )
	&&  ((tptr   = EvaluateExpression()) != (BPTR) 0)) {
		if ( *tptr == '#' ) {
			tptr++;
			type = ( *(tptr++) - '0' );
			if ( type < 2 )
				tptr = add_dummy_length( tptr );
			}
		if (((status = store_clf(xptr, tptr)) == 0 )
		&&  ( is_comma() )
		&&  ((status = store_clf(xptr, IntegerExpression())) == 0)
		&&  ( is_comma() )
		&&  ((status = store_clf(xptr, IntegerExpression())) == 0)
		&&  ( is_right_brace() )) {
			(void) release_context(xptr,flush_clf(xptr));
			return( 0 );
			}
		}
	(void) release_context(xptr,(BPTR) 0);
	return( syntax_error(3100) );
}

WORD	translate_rtlclf_swap()
{
	CLFPTR		xptr;
	WORD		status;
	WORD	varlen;

	trace("rtlclf_swap()\n");
	if (((xptr = start_clf(4,12)) != (CLFPTR) 0)
	&&  ( is_left_brace() )
	&&  ((status = store_clf(xptr, VariableExpression((WPTR) & varlen))) == 0)
	&&  ( is_comma() )
	&&  ((status = store_clf(xptr, IntegerExpression())) == 0)
	&&  ( is_comma() )
	&&  ((status = store_clf(xptr, IntegerExpression())) == 0)
	&&  ( is_right_brace() )) {
		(void) release_context(xptr,flush_clf(xptr));
		return( 0 );
		}
	(void) release_context(xptr,(BPTR) 0);
	return( syntax_error(3100) );
}

WORD	translate_rtlclf_insert()
{
	CLFPTR		xptr;
	WORD		status;
	WORD		varlen;
	BPTR		rptr;
	trace("rtlclf_insert()\n");
	if (((xptr = start_clf(3,8)) != (CLFPTR) 0)
	&&  ( is_left_brace() )
	&&  ((status = store_clf(xptr, IntegerExpression())) == 0)
	&&  ( is_comma() )
	&&  ((status = store_clf(xptr,(rptr = StringExpression()))) == 0)) {
		if ( is_comma() )
			status = store_clf(xptr, IntegerExpression());
		else	status = store_clf(xptr, ExtractLength(rptr));
		if (( status == 0 )
		&&  ( is_right_brace() )) {
			(void) release_context(xptr,flush_clf(xptr));
			return( 0 );
			}
		}
	(void) release_context(xptr,(BPTR) 0);
	return( syntax_error(3100) );
}

WORD	translate_rtlclf_includ()
{
	CLFPTR		xptr;
	WORD		status;
	BPTR		rptr;
	trace("rtlclf_includ()\n");
	if (((xptr = start_clf(1,8)) != (CLFPTR) 0)
	&&  ( is_left_brace() )
	&&  ((status = store_clf(xptr, IntegerExpression())) == 0)
	&&  ( is_comma() )
	&&  ((status = store_clf(xptr,(rptr = StringExpression()))) == 0)) {
		if ( is_comma() )
			status = store_clf(xptr, IntegerExpression());
		else	status = store_clf(xptr, ExtractLength(rptr));
		if (( status == 0 )
		&&  ( is_right_brace() )) {
			(void) release_context(xptr,flush_clf(xptr));
			return( 0 );
			}
		}
	(void) release_context(xptr,(BPTR) 0);
	return( syntax_error(3100) );
}

WORD	translate_rtlclf_crypt()
{
	CLFPTR		xptr;
	WORD		status;
	BPTR		rptr;
	trace("rtlclf_includ()\n");
	if (((xptr = start_clf(9,13)) != (CLFPTR) 0)
	&&  ( is_left_brace() )
	&&  ((status = store_clf(xptr, IntegerExpression())) == 0)
	&&  ( is_comma() )
	&&  ((status = store_clf(xptr,(rptr = IntegerExpression()))) == 0)
	&&  ( is_right_brace() )) {
		(void) release_context(xptr,flush_clf(xptr));
		return( 0 );
		}
	(void) release_context(xptr,(BPTR) 0);
	return( syntax_error(3100) );
}

WORD	cancel_clf_instruction( state )
WORD	state;
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


#endif	/* _TRRTLCLF_C */
	/* ----------- */






