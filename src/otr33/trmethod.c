/* #define	DEBUG_IMT */
/* #define	DEBUG	  */
/* #define	DEBUG_TRACE_ACTIVE */
/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRCLASS.C				*/
/*		Version :	2.1d					*/
/*		Date	:	23/02/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRMETHOD_C
#define	_TRMETHOD_C

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include <string.h>
#include "stdtypes.h"
#include "translat.h"
#include "trparser.h"
#include "trsyntax.h"
#include "trerrors.h"
#include "trsymbol.h"
#include "troption.h"
#include "trtables.h"
#include "trexpres.h"
#include "trlabels.h"
#include "triter.h"
#include "trinput.h"
#include "trclf.h"
#include "trproc.h"
#include "trclass.h"
#include "trmethod.h"
#include "trmember.h"
#include "trdebug.h"
#include "trcommon.h"
#include "trabal.h"
#include "trdirect.h"
#include "trshadow.h"
#include "triof.h"
#include "troutput.h"
#include "trecho.h"

TCVARPTR	OverloadHost=(TCVARPTR) 0;
EXTERN	BYTE	TokenBuffer[];

EXTERN	WORD	ModuleObject;

EXTERN	WORD	ListMemberCounter;

#ifndef	UNIX
static WORD	ll_activate_method( TCVARPTR,TCMEMBERPTR,TCMBMETHPTR,TCMBPARAPTR,WORD,WORD);
static	WORD	method_translation( TCMEMBERPTR );
static	WORD	parameter_expansion( TCMBPARAPTR, WORD );
#else
GENERICPTR	allocate_for_genericity();
GENERICPTR	copy_genericity( GENERICPTR );
TCSEGPTR	build_segment();
XTSEGPTR	build_external_segment();
TCVARPTR	segment_pseudo_object();
TCVARPTR	register_variable();
WORD		is_method_definition();
TCMEMBERPTR	resolve_baseclass_member();
RESULTPTR	evaluate_user_method();
RESULTPTR	copy_result();
RESULTPTR	build_string_constant();
TCVARPTR	collect_typed_parameters();
WORD		translate_class_keyword();
TCVARPTR	locate_master_object();
TCVARPTR	next_master_object();
TCVARPTR	resolve_member_variable();
TCPRCPTR	add_function_method();
PRCPTR		start_prc();
static WORD	ll_activate_method();
static WORD	method_translation();
static WORD	parameter_expansion();
WORD		perform_destruction();
WORD		allow_construction();
#endif

static	BYTE	FunctionName[128];

static	TCMBPARAPTR	FreeParameters=(TCMBPARAPTR) 0;

#include "trvalue.c"

static	TCMBPARAPTR	allocate_method_parameter()
{
	TCMBPARAPTR	pptr;

	trace("allocate_method_parameter(");

	if ((pptr = FreeParameters) != (TCMBPARAPTR) 0)
		FreeParameters = pptr->next;
	else if ((pptr = (TCMBPARAPTR) allocate( sizeof( struct tcode_method_parameter ) )) == (TCMBPARAPTR) 0)
		return( pptr );

	pptr->mode		= 0;
	pptr->retmode		= 0;
	pptr->variable        	= (TCVARPTR)    0;
	pptr->result		= (RESULTPTR)   0;
	pptr->parameters	= (TCMBPARAPTR) 0;
	pptr->object		= (TCVARPTR) 	0;
	pptr->method		= (TCMBMETHPTR) 0;
	pptr->text		= (TCTEXTPTR) 	0;
	pptr->next            	= (TCMBPARAPTR) 0;

	return( pptr );
}

WORD	release_method_parameters()
{
	TCMBPARAPTR	pptr;
	WORD		nombre=0;
	trace("release_method_parameters()\n");
	while ((pptr = FreeParameters) != (TCMBPARAPTR) 0) {
		FreeParameters = pptr->next;
		liberate( pptr );
		nombre++;
		}
	return(nombre);
}

TCMBPARAPTR	liberate_method_parameters( pptr )
TCMBPARAPTR		pptr;
{
	TCMBPARAPTR	qptr;

	trace("liberate_method_parameters()\n");

	while ((qptr = pptr) != (TCMBPARAPTR) 0) {
		pptr = pptr->next;
		if ( qptr->mode == 2 ) {
			trace("liberate_result_parameter()\n");
			if ( qptr->result != (RESULTPTR) 0 )
				forget_protected_result( qptr->result );
			}
		else if ( qptr->mode == 1 ) {
			trace("liberate_text_parameter()\n");
			if ( qptr->text != (TCTEXTPTR) 0 )
				qptr->text = liberate_text_value( qptr->text );
			}
		qptr->next = FreeParameters;
		FreeParameters = qptr;
		}
	return( qptr );
}

static	TCMBFUNCPTR	allocate_function_method()
{
	TCMBFUNCPTR	mptr;
	trace("allocate_function_method(");
	if ((mptr = (TCMBFUNCPTR) allocate( sizeof(struct tcode_function_method) )) != (TCMBFUNCPTR) 0) {
		mptr->procedure  = (TCPRCPTR) 0;
		mptr->status	 = 0;
		mptr->class	 = (TCSTRUCTPTR) 0;
		mptr->member	 = (TCMEMBERPTR) 0;
		mptr->parameters = (TCVARPTR) 0;
		mptr->type	 = (TCTYPPTR) 0;;
		mptr->next	 = (TCMBFUNCPTR) 0;
		}
	return( mptr );
}

static	TCMBGSBPTR	allocate_routine_method()
{
	TCMBGSBPTR	mptr;
	trace("allocate_routine_method(");
	if ((mptr = (TCMBGSBPTR) allocate( sizeof(struct tcode_routine_method) )) != (TCMBGSBPTR) 0) {
		mptr->label	= MOINS_UN;
		mptr->status	= 0;
		mptr->object 	= (TCVARPTR) 0;
		mptr->member 	= (TCMEMBERPTR) 0;
		mptr->next	= (TCMBGSBPTR) 0;
		}
	return( mptr );
}

static	TCMBOVLPTR	allocate_overlay_method()
{
	TCMBOVLPTR	mptr;
	trace("allocate_overlay_method(");
	if ((mptr = (TCMBOVLPTR) allocate( sizeof(struct tcode_overlay_method) )) != (TCMBOVLPTR) 0) {
		mptr->segment   = (TCSEGPTR) 0;
		mptr->segptr    = (XTSEGPTR) 0;
		mptr->status	= 0;
		mptr->field     = 0;
		mptr->object 	= (TCVARPTR) 0;
		mptr->class	= (TCSTRUCTPTR) 0;
		mptr->member 	= (TCMEMBERPTR) 0;
		mptr->next	= (TCMBOVLPTR) 0;
		}
	return( mptr );
}

static	TCMBFUNCPTR	locate_function_method(class,member,parameters)
TCSTRUCTPTR	class;
TCMEMBERPTR	member;
TCVARPTR	parameters;
{
	TCMBFUNCPTR	mptr;
	if ((mptr = FunctionHeap) != (TCMBFUNCPTR) 0) {
		do	{
			if ((class->hash == mptr->class->hash)
			&&  (member->hash == mptr->member->hash)
			&&  (compare_tokens( class->name,  mptr->class->name ) != 0)
			&&  (compare_tokens( member->name, mptr->member->name) != 0)
			&&  (compare_parameter_list( mptr->parameters, parameters ) != 0 ))
				break;
			}
		while ((mptr = mptr->next) != (TCMBFUNCPTR) 0);
		}
	return( mptr );
}

static	TCMBGSBPTR	locate_routine_method(object,member)
TCVARPTR	object;
TCMEMBERPTR	member;
{
	TCMBGSBPTR	mptr;
	if ((mptr = RoutineHeap) != (TCMBGSBPTR) 0) {
		do	{
			if ((object->identity == mptr->object->identity )
			&&  (object->hash == mptr->object->hash)
			&&  (member->hash == mptr->member->hash)
			&&  (compare_tokens( object->name, mptr->object->name ) != 0)
			&&  (compare_tokens( member->name, mptr->member->name ) != 0))
				break;
			}
		while ((mptr = mptr->next) != (TCMBGSBPTR) 0);
		}
	return( mptr );
}

TCMBOVLPTR		locate_overlay_method(class,member,field)
TCSTRUCTPTR		class;
TCMEMBERPTR		member;
WORD			field;
{
	TCMBOVLPTR	mptr;
	if ((mptr = OverlayHeap) != (TCMBOVLPTR) 0) {
		do	{
			if  ((class->hash == mptr->class->hash )
			&&  (member->hash == mptr->member->hash )
			&&  (field        == mptr->field)
			&&  (compare_tokens( class->name, mptr->class->name ) != 0)
			&&  (compare_tokens( member->name, mptr->member->name ) != 0))
				break;
			}
		while ((mptr = mptr->next) != (TCMBOVLPTR) 0);
		}
	return( mptr );
}

TCMBOVLPTR	build_overlay_method( object, class, member, field )
TCVARPTR	object;
TCSTRUCTPTR	class;
TCMEMBERPTR	member;
WORD		field;
{
	TCMBOVLPTR	overlay;
	TCMBOVLPTR	rptr;
	WORD		module=MOINS_UN;

	if ((overlay = allocate_overlay_method()) != (TCMBOVLPTR) 0) {

		if ( class->access & _MEMBER_EXTERN ) {
			module = resolve_module_number( class->module, 1 );
			if ((overlay->segptr = build_external_segment( member->name, MOINS_UN, class->name, module, VRAI )) == (XTSEGPTR) 0) {
				liberate( overlay );
				(void) allocation_failure();
				return((TCMBOVLPTR) 0);
				}
			else	overlay->status = VRAI;
			}
		else if ((overlay->segment = build_segment( MOINS_UN, member->name, 0)) == (TCSEGPTR) 0) {
			liberate( overlay );
			(void) allocation_failure();
			return((TCMBOVLPTR) 0);
			}

		overlay->object  = copy_variable( object );
		overlay->member  = member;
		overlay->class   = class;
		overlay->field   = field;

		if ( OtrOption.Verbose & 8 )
			sysprintf("Pending Overlay: %s(%s).%s Field= %X \n",object->name,class->name,member->name,field);

		if ((rptr = OverlayHeap) == (TCMBOVLPTR) 0)
			OverlayHeap     = overlay;
		else 	{
			while (rptr->next != (TCMBOVLPTR) 0)
				rptr = rptr->next;
			rptr->next = overlay;
			}
		}
	return( overlay );
}

VOID	liberate_special_method( mptr )
COMETHODPTR	mptr;
{

	if ( mptr != (COMETHODPTR) 0) {
		trace("liberate_special_method()");
		if ( mptr->name != (BPTR) 0 )
			liberate( mptr->name );
		liberate( mptr );
		}
	return;
}

COMETHODPTR	allocate_special_method( name, type )
BPTR	name;
WORD	type;
{
	COMETHODPTR	mptr;
	trace("allocate_special_method(");
	if ((mptr = (COMETHODPTR) allocate( sizeof( struct tcode_special_method ) )) != (COMETHODPTR) 0) {
		mptr->next   = (COMETHODPTR) 0;
		mptr->nature = type;
		if ((mptr->name = (BPTR) allocate_for_string( name )) == (BPTR) 0) {
			liberate( mptr );
			mptr = (COMETHODPTR) 0;
			}
		}
	return( mptr );
}

static	WORD	copy_comethods( target, source )
TCMBMETHPTR	target;
TCMBMETHPTR	source;
{
	COMETHODPTR	sptr;
	COMETHODPTR	tptr;

	if ((sptr = source->comethod) != (COMETHODPTR) 0) {
		trace("copy_comethods()\n");
		do	{
			if ((tptr = allocate_special_method( sptr->name, sptr->nature )) == (COMETHODPTR) 0) 
				return( allocation_failure() );
			else	{
				tptr->next = target->comethod;
				target->comethod = tptr;
				}
			}
		while ((sptr = sptr->next) != (COMETHODPTR) 0);
		}
	return( 0 );

}

TCMBMETHPTR	allocate_structure_method()
{
	TCMBMETHPTR	mptr;
	trace("allocate_structure_method(");
	if ((mptr = (TCMBMETHPTR) allocate( sizeof( struct tcode_structure_method ) )) != (TCMBMETHPTR) 0) {
		mptr->users		= 0;
		mptr->nature		= 0;
		mptr->options		= 0;
		mptr->file		= 0;
		mptr->line		= 0;
		mptr->thisline		= 0;
		mptr->offset		= 0L;
		mptr->number		= 0;
/*		mptr->alternative	= 0;	*/
		mptr->invocation	= 0;
		mptr->local		= (TCSTRUCTPTR) 0;
		mptr->generic		= (GENERICPTR) 0;
		mptr->pending		= (TCAUTOPTR) 0;
		mptr->comethod 		= (COMETHODPTR) 0;
		mptr->parameters	= (TCVARPTR) 0;
		mptr->type		= (TCTYPPTR) 0;
		mptr->value		= (TCTEXTPTR) 0;
		mptr->member		= (TCMEMBERPTR) 0;
		}
	return( mptr );
}

VOID	establish_method_member( method , member )
TCMBMETHPTR	method;
TCMEMBERPTR	member;
{
	if ( method != (TCMBMETHPTR) 0)
		method->member = member;
	return;
}

TCMEMBERPTR	resolve_method_member( method )
TCMBMETHPTR	method;
{
	if ( method != (TCMBMETHPTR) 0)
		return( method->member );
	else 	return((TCMEMBERPTR) 0 );
}

WORD		build_pseudo_object( mptr, class )
TCMBMETHPTR	mptr;
TCSTRUCTPTR	class;
{
	TCVARPTR	object;
	trace("build_pseudo_object()\n");

	if (( class == (TCSTRUCTPTR) 0 )
	||  ( mptr  == (TCMBMETHPTR) 0 ))
		return( syntax_error( 9797 ) );
	else if ((object = allocate_for_variable()) == (TCVARPTR) 0)
		return( allocation_failure() );
	else if ((object->name = allocate_for_token("THIS")) == (BPTR) 0)
		return( allocation_failure() );

	object->hash = keyword_hash("THIS");

	if ((object->type = allocate_for_type(((class->access & _MEMBER_OVERLAY) ? (_TYPE_OVERLAY | 0x901B) : 0x901B),object_occupation(class),1,1,class)) == (TCTYPPTR) 0)
		return( allocation_failure() );
	else	{
		object->next = mptr->parameters;
		mptr->parameters = object;
		return(0);
		}
}

TCVARPTR	explicite_method_parameters( method )
TCMBMETHPTR	method;
{
	if ( method->nature == _CLASS_FUNCTION ) {
		if ( method->parameters != (TCVARPTR) 0 )
			return( method->parameters->next );
		else	return( (TCVARPTR) 0 );
		}
	else	return( method->parameters );
}

TCVARPTR	copy_method_parameters( method )
TCMBMETHPTR	method;
{
	TCVARPTR	vptr;
	TCVARPTR	root=(TCVARPTR) 0;
	TCVARPTR	temp=(TCVARPTR) 0;
	TCVARPTR	last=(TCVARPTR) 0;
	if ((vptr = explicite_method_parameters( method )) != (TCVARPTR) 0) {
		do	{
			if ((temp = copy_variable( vptr )) == (TCVARPTR) 0)
				break;
			else if ( last == (TCVARPTR) 0 )
				root = temp;
			else	last->next = temp;
			last = temp;
			}
		while ((vptr = vptr->next) != (TCVARPTR) 0);
		}
	return( root );
}


WORD	copy_structure_method( nptr, mptr )
TCMEMBERPTR	nptr;			/* New member being created */
TCMEMBERPTR	mptr;			/* Old member to be copied  */
{
	WORD		status;
	TCMBMETHPTR	zptr;
	TCMBMETHPTR	wptr;
	TCSTRUCTPTR	class;

	trace("copy_structure_method("); trace( mptr->name ); trace(")\n");
	if (((zptr = (TCMBMETHPTR) mptr->special) != (TCMBMETHPTR) 0)
	&&  ((wptr = allocate_structure_method()) != (TCMBMETHPTR) 0)) {
		nptr->special    = (VPTR) wptr;
		wptr->nature     = zptr->nature;	/* Inline etc  */
		wptr->options    = zptr->options;	/* Strict Etc  */
		wptr->special    = zptr->special;	/* Constructor */
		wptr->member     = nptr;
		wptr->number     = zptr->number;
		if (!(wptr->options & _METHOD_STATIC)) {

			wptr->generic = copy_genericity( zptr->generic );

			/* Check if copy occurs outside of Class Definition */
			/* ------------------------------------------------ */
			if ((class = World->CurrentStructure) == (TCSTRUCTPTR) 0)
				class = (TCSTRUCTPTR)zptr->parameters->type->class;

			wptr->parameters = copy_method_parameters( zptr );

			if (( wptr->nature == _CLASS_FUNCTION )
			&&  ((status = build_pseudo_object( wptr, class )) != 0))
				return( status );
			}	
		else	wptr->parameters = zptr->parameters;
		wptr->file       = zptr->file;
		wptr->line       = zptr->line;
		if ( zptr->type != (TCTYPPTR) 0)
			wptr->type = copy_type( zptr->type );
		else	wptr->type = (TCTYPPTR) 0;
		if ( zptr->value != (TCTEXTPTR) 0) 
			wptr->value = copy_text_value( zptr->value );
		wptr->users++;
		wptr->local      = zptr->local;
		return( copy_comethods( wptr, zptr ) );
		}
	else	return(allocation_failure());
}

VOID	liberate_structure_method( method )
TCMBMETHPTR	method;
{
	TCVARPTR	vptr;
	COMETHODPTR	cptr;

	if ( method != (TCMBMETHPTR) 0) {

		trace("liberate_structure_method()\n");

		if ( method->type != (TCTYPPTR) 0 )
			liberate_for_type( method->type );

		/* Note : Locals are shared across INHERIT */
		/* --------------------------------------- */
		if (!( method->users ))
			if ( method->local != (TCSTRUCTPTR) 0)
				liberate_for_structure( method->local );


		/* Parameters are shared across INHERIT for DYNAMIC methods */
		/* -------------------------------------------------------- */
		if (!( method->users )) {
			while ((vptr = method->parameters) != (TCVARPTR) 0) {
				method->parameters = vptr->next;
				liberate_parameter_variable( vptr );
				}
			}


		liberate_for_genericity( method->generic );

		while ((cptr = method->comethod) != (COMETHODPTR) 0) {
			method->comethod = cptr->next;
			liberate_special_method( cptr );
			}

		method->value = liberate_text_value( method->value );

		liberate( method );

		}
	return;
}

WORD	put_method_byte( c )
WORD	c;
{
	if ( OtrOption.TargetTrace )
		sysprintf("%c",c);
	if ((ClassOptions.MethodText = memory_target( ClassOptions.MethodText, c )) != (VALUEPTR) 0)
		return( 0 );
	else	return( internal_error( 696 ) );
}

#define	put_method_eol() put_method_byte('\n')

WORD	put_method_string( s )
BPTR	s;
{
	WORD	status;
	while ( *s )
		if ((status = put_method_byte( *(s++) )) != 0)
			return( status );
	return( put_method_byte(' ') );
}

#include "trtext.c"

TCTEXTPTR	collect_construction_parameters()
{
	WORD		braces=1;
	WORD		c;
	WORD		scc_state;
	WORD		bal_state;
	WORD		status=0;
	TCTEXTPTR	tptr=(TCTEXTPTR) 0;

	trace("collect_construction_parameters()\n");

	if ((tptr = allocate_text_value()) == (TCTEXTPTR) 0) {
		(void) allocation_failure();
		return( tptr );
		}		
	else	ClassOptions.MethodText = tptr->buffer;

	scc_state = inhibit_semi_colon_comment();
	bal_state = inhibit_bal_comments();

	status = put_method_byte('('); braces = 1;

	while (!(status)) {
		if ( get_token() ) {
			if ((status = put_method_string(TokenBuffer)) != 0 )
				break;
			else	continue;
			}
		else 	{
			switch ((c = get_byte())) {
				case 0   :
				case MOINS_UN :
					status = syntax_error(850);
					break;
				case ')' :
					if ((status = put_method_byte(c)) != 0)
						break;
					braces--;
					if (!( braces ))
						break;
					else 	continue;					
				case '(' :
					braces++;
				default	 :
					if ((status = put_method_byte(c)) != 0 )
						break;
					else 	continue;					
				}
			}
		break;
		}

	if (!( status ))
		status = put_method_byte('\n');

	ClassOptions.MethodText = (VALUEPTR) 0;
	bal_state = restore_bal_comments( bal_state );
	scc_state = restore_semi_colon_comment( scc_state );

	if ( status )
		return( liberate_text_value( tptr ) );
	else	return( tptr );
}

VOID	dump_white_space( c )
WORD	c;
{
	if ( ClassOptions.MethodText != (VALUEPTR) 0 )
		put_method_byte( c );
	return;
}

TCMBMETHPTR	output_method()
{
	return(((TCMBMETHPTR) ClassOptions.WorkingMethod));
}

static	WORD	translate_co_method( nature )
WORD	nature;
{
	COMETHODPTR	cptr;	
	TCMBMETHPTR	mptr;

	if (!( get_token() ))
		return( syntax_error( 877 ) );
	else if ((cptr = allocate_special_method( TokenBuffer, nature )) == (COMETHODPTR) 0)
		return( allocation_failure() );
	else if ((mptr = output_method()) == (TCMBMETHPTR) 0)
		return( internal_error( 877 ) );
	else	{
		cptr->next = mptr->comethod;
		mptr->comethod = cptr;
		return( 0 );
		}

}

#include "trlocal.c"

TCMBPARAPTR	parameter_term()
{
	TCMBPARAPTR	pptr;
	trace("parameter_term("); trace(TokenBuffer); trace(")\n");
	if ((pptr = (TCMBPARAPTR) input_parameters()) != (TCMBPARAPTR) 0) {
		do	{
			if ((TokenHash == pptr->variable->hash)
			&&  ( compare_tokens( TokenBuffer, pptr->variable->name ) ))
				break;
			}
		while ((pptr = pptr->next) != (TCMBPARAPTR) 0);
		}
	return( pptr );

}

RESULTPTR	is_parameter_term()
{
	TCMBPARAPTR	pptr;

	if ((pptr = parameter_term()) != (TCMBPARAPTR) 0) {
		if ( pptr->mode == 2 )
			return( copy_result( pptr->result ) );
		else if (( pptr->mode == 1)
		     &&	 (parameter_expansion( pptr, 0 ) == 0))
			return( evaluate_expression(0) );
		}
	return((RESULTPTR) 0);
}



WORD	transmit_method_label( name )
BPTR	name;
{
	WORD	status;
	if ((status = put_method_string( name )) != 0)
		return( 0 );
	else	return( 1 );
}

WORD	method_directive( name )
BPTR	name;
{
	WORD	status;
	WORD	c;
	if ((status = put_method_string( name )) != 0)
		return( status );

	while ( 1 ) {
		if ( get_token() ) {
			if ((status = put_method_string( TokenBuffer )) != 0)
				return( status );
			}
		if (!(c = get_byte()))
			break;
#ifdef	_BEFORE_20121996
#else
		else if ( c == '\n' )
			break;
#endif
		else if ((status = put_method_byte( c )) != 0)
			return( status );	
	
		}
	return((status = put_method_byte( '\n' )));
}

static	WORD	parameter_exists( pptr )
TCMBPARAPTR	pptr;
{
	if ( pptr->mode == 2 ) {
		if ( pptr->result != (RESULTPTR) 0 )
			return( VRAI );
		else	return( FAUX );
		}
	else if ( pptr->mode == 1 ) {
		if ( pptr->text != (TCTEXTPTR) 0 )
			return( VRAI );
		else	return( FAUX );
		}
	else	return( FAUX );
}
	

WORD	evaluate_ifexist()
{
	TCMBPARAPTR	pptr;
	if (!( ll_get_token() )) {
		(void) syntax_error( 6001);
		return( MOINS_UN );
		}
	else if ((pptr = parameter_term()) != (TCMBPARAPTR) 0) {
	     	if (parameter_exists( pptr ))
			return( VRAI );
		else	return( FAUX );
		}
	else if ( object_exists() )
		return( VRAI );
	else	return( FAUX );
}

WORD	evaluate_ifnexist()
{
	TCMBPARAPTR	pptr;
	if (!( ll_get_token() )) {
		(void) syntax_error( 6001);
		return( MOINS_UN );
		}
	else if ((pptr = parameter_term()) != (TCMBPARAPTR) 0) {
	     	if (parameter_exists( pptr ))
			return( FAUX );
		else	return( VRAI );
		}
	else if ( object_exists() )
		return( FAUX );
	else	return( VRAI );
}

static	WORD	flush_pending_linefeeds()
{
	WORD	status=0;
	WORD	nblines=source_file_line();
	TCMBMETHPTR mptr;
	if (( OtrOption.Symbolic & 1 )
	&&  ((mptr = (TCMBMETHPTR)ClassOptions.WorkingMethod) != (TCMBMETHPTR) 0))
		mptr->thisline++;
		while ( mptr->thisline < nblines ) {
			if ((status = put_method_eol()) != 0)
				return( status );
			else	mptr->thisline++;
			}
	return(0);			
}

static	WORD	ll_translate_method_text(analyse)
WORD	analyse;	/* 0 : Macro, 1: Method	*/
{
	WORD	c;
	WORD	status;
	WORD	keyword;
	trace("translate_method_text()\n");
/*
 *	if ((status = flush_pending_linefeeds()) != 0)
 *		return( status );
 */
	while (1) {
		if (!( get_token() )) {
			if (!(c = get_byte())) {
				return((status = put_method_eol()));
				}
			else if ((analyse)
			     &&  (c == ';')) {
				while ((c = get_byte()));
				return((status = put_method_eol()));
				}				
			else if ((status = put_method_byte( c )) != 0)
				return( status );
			}
		else if (uppercase_compare(TokenBuffer,"END")) {
			if ((status = analyse_method_end()) != 0 )
				return( status );
			}
		else if ((analyse)
		     && ((keyword = is_class_keyword()) != MOINS_UN)) {
			if ( keyword != _CLASS_LOCAL )
				return( MOINS_UN );
			else if ((status = translate_local_statement()) != 0)
				return( status );
			}
		else if ((status = put_method_string( TokenBuffer )) != 0)
			return( status );
		analyse=0;
		}
}

static	WORD	ll_translate_macro_text()
{
	WORD	c;
	WORD	status;
	trace("translate_macro_text()\n");
	while (1) {
		if ( is_directive_endmacro() )
			return( terminate_macro_text() );
		else if (!( get_token() )) {
			if (!(c = get_byte()))
				return((status = put_method_byte( '\n' )));
			else if ((status = put_method_byte( c )) != 0)
				return( status );
			else	continue;
			}
		else if ((status = put_method_string( TokenBuffer )) != 0)
			return( status );
		}
}

static	WORD	translate_method_text()
{
	WORD	scc_state;
	WORD	apc_state;
	WORD	bal_state;
	WORD	status;
	WORD	qstatus;
	qstatus   = OtrOption.KeepQuote;
	OtrOption.KeepQuote=1;
	scc_state = inhibit_semi_colon_comment();
	apc_state = inhibit_apostrophe_comment();
	bal_state = inhibit_bal_comments();
	inhibit_dieze_constants();
	status = ll_translate_method_text(1);
	restore_dieze_constants();
	bal_state = restore_bal_comments( bal_state );
	apc_state = restore_apostrophe_comment( apc_state );
	scc_state = restore_semi_colon_comment( scc_state );
	OtrOption.KeepQuote = qstatus;
	if ( status == MOINS_UN ) {
		terminate_method_text();
		return( translate_class_keyword() );
		}
	else	return( status );
}

static	WORD	translate_macro_text()
{
	WORD	scc_state;
	WORD	apc_state;
	WORD	bal_state;
	WORD	status;

	scc_state = inhibit_semi_colon_comment();
	apc_state = inhibit_apostrophe_comment();
	bal_state = inhibit_bal_comments();
	status = ll_translate_macro_text();
	bal_state = restore_bal_comments( bal_state );
	apc_state = restore_apostrophe_comment( apc_state );
	scc_state = restore_semi_colon_comment( scc_state );
	return( status );
}

TCTYPPTR	resolve_method_type( mptr )
	TCMBMETHPTR	mptr;
{
	if ( mptr != (TCMBMETHPTR) 0 )
		return( mptr->type );
	else	return( (TCTYPPTR) 0 );
}

TCVARPTR	resolve_method_parameters( mptr )
	TCMBMETHPTR	mptr;
{
	if ( mptr != (TCMBMETHPTR) 0 )
		return( mptr->parameters );
	else	return( (TCVARPTR) 0 );
}


WORD	translate_method_type( type )
WORD	type;
{
	if (( type == _CLASS_USER )
	&&  ( is_left_brace()     )) {
		ClassOptions.Number = integer_expression();
		if (!( is_right_brace() ))
			return( unmatched_braces() );
		}

	if ( ClassOptions.Method ) {
		if ((ClassOptions.Method == _CLASS_METHOD )
		&&  ( type == _CLASS_METHOD ))
			return( syntax_error(851) );
		else if ( type == _CLASS_METHOD )
			return( 0 );
		else if ((ClassOptions.Method == _CLASS_INLINE)
		     &&  (type == _CLASS_FUNCTION ))
			return( 0 );
		else if ((ClassOptions.Method == _CLASS_USER)
		     &&  (type == _CLASS_FUNCTION ))
			return( 0 );
		else if ( ClassOptions.Method != _CLASS_METHOD )
			return( syntax_error(852) );
		}
	ClassOptions.Method = type;
	return( 0 );
}

static	WORD	establish_method_type( mptr )
TCMBMETHPTR	mptr;
{
	TCTYPPTR	tptr;
	trace("establish_method_type()\n");
	if ( ClassOptions.Type ) {
		if ((tptr = allocate_for_type( ClassOptions.Type, ClassOptions.Size, 1, 1, ClassOptions.ReturnType)) == (TCTYPPTR) 0)
			return( allocation_failure() );
		else	mptr->type = tptr;
		}
	else	mptr->type = ClassOptions.ReturnType;
	return( 0 );
}

WORD	is_static_function( method )
TCMBMETHPTR	method;
{
	if (( method->nature == _CLASS_FUNCTION )
	&&  ( method->options & _METHOD_STATIC  ))
		return( VRAI );
	else if (( method->nature == _CLASS_OVERLAY  )
	     &&  ( method->options & _METHOD_STATIC  ))
		return( VRAI );
	else	return( FAUX );
}

WORD	is_overlay_indirect( method )
TCMBMETHPTR	method;
{
	/* The ENHANCED INDIRECT option cancels automatic detection */
	/* -------------------------------------------------------- */
	if  (( method == (TCMBMETHPTR) 0 )
	||   ( member_enhanced_indirect( method->member ) ))
		return( FAUX );
	else if (( method->nature == _CLASS_FUNCTION  )
	     &&  ( method->options & _METHOD_INDIRECT ))
		return( VRAI );
	else	return( FAUX );
}

WORD	identify_indirect_method( method, nombre )
TCMBMETHPTR	method;
WORD		nombre;
{
	if (( method->nature == _CLASS_FUNCTION  )
	&&  ( method->options & _METHOD_INDIRECT )) {
		nombre++;
		if (!( member_enhanced_indirect( method->member ) ))
			method->number = nombre;
		}
	return( nombre );
}


		
WORD		set_method_options( mptr, mode )
TCMBMETHPTR	mptr;
WORD		mode;
{
	WORD	status;
	trace("set_method_options()\n");

	mptr->special = ClassOptions.Special;

	if ( ClassOptions.Strict == _CLASS_STRICT )
		mptr->options |= _METHOD_STRICT;
	if ( ClassOptions.Static == _CLASS_STATIC )
		mptr->options |= _METHOD_STATIC;
	if ( ClassOptions.Direct == _CLASS_INDIRECT )
		mptr->options |= _METHOD_INDIRECT;
	if ( ClassOptions.Virtual == _CLASS_VIRTUAL )
		mptr->options |= _METHOD_VIRTUAL;
	if ( ClassOptions.Overload == _CLASS_OVERLOAD )
		mptr->options |= _METHOD_OVERLOAD;
	if ( ClassOptions.Resident == _CLASS_RESIDENT )
		mptr->options |= _METHOD_RESIDENT;
#ifdef	_BEFORE_19121996
#else
	if ( ClassOptions.CallBack == _CLASS_CALLBACK )
		mptr->options |= _METHOD_CALLBACK;
#endif
	if ( mode )
		mptr->options |= ( _METHOD_POINTER | _METHOD_INDIRECT );

	switch ((mptr->nature  = ClassOptions.Method)) {
		case	_CLASS_ROUTINE	:
			if (( ClassOptions.Type )
			||  ( ClassOptions.ReturnType != (TCTYPPTR) 0 )) {
				issue_warning(5);
				mptr->nature = _CLASS_INLINE;
				if ((status = establish_method_type( mptr )) != 0)
					return( status );
				}
			break;
				
		case	_CLASS_INLINE	:
			if (( ClassOptions.Type )
			||  ( ClassOptions.ReturnType != (TCTYPPTR) 0 )) {
				if (!( OtrOption.Enhanced & _ENHANCED_INLINE ))
					return( syntax_error( 5677 ) );
				else if ((status = establish_method_type( mptr )) != 0)
					return( status );
				}
			break;

		case	_CLASS_OVERLAY	:
			if (( ClassOptions.Type )
			||  ( ClassOptions.ReturnType != (TCTYPPTR) 0 )) {
				issue_warning(6);
				mptr->nature = _CLASS_FUNCTION;
				if ((status = establish_method_type( mptr )) != 0)
					return( status );
				}
			break;
		case	_CLASS_FUNCTION	:
		case	_CLASS_USER	:
			if (( ClassOptions.Type )
			||  ( ClassOptions.ReturnType != (TCTYPPTR) 0 )) {
				if ((status = establish_method_type( mptr )) != 0)
					return( status );
				}
			break;
		}

	/* Ensure VIRTUAL or OVERLOAD applied only to INDIRECT FUNCTIONS */
	/* ------------------------------------------------------------- */
	if  (Context->Visibility & (_MEMBER_VIRTUAL | _MEMBER_OVERLOAD )) {
		if (!( world_enhanced_indirect() ))
			return( syntax_error( 5676 ) );
		else if ((!(mptr->options & _METHOD_INDIRECT))
		     &&  ( mptr->nature != _CLASS_FUNCTION ))
			return( syntax_error( 2121 ) ); 
		}

	return( 0 );
}

static	TCVARPTR	build_exception_variable( nptr )
BPTR	nptr;
{
	TCVARPTR	object;
	if ((object = allocate_for_variable()) != (TCVARPTR) 0) {
		if ((object->name = allocate_for_token(nptr)) != (BPTR) 0) {
			object->hash = keyword_hash(nptr);
			if ((object->type = allocate_for_type(1,2,1,1,(VPTR) 0)) != (TCTYPPTR) 0)
				return( object );
			liberate( object->name );
			}
		liberate( object );
		}
	return( (TCVARPTR) 0 );
}

WORD		activate_method_target( method )
TCMBMETHPTR	method;
{
	if ((method->value = allocate_text_value()) == (TCTEXTPTR) 0)
		return( allocation_failure() );
	else	{
		ClassOptions.MethodText    = method->value->buffer;
		ClassOptions.WorkingMethod = (VPTR) method;
		return( 0 );
		}
}

VOID	establish_method_symbolic( method )
TCMBMETHPTR	method;
{
	method->file    = current_file_number();
	method->thisline = method->line     = source_file_line();
	method->offset  = current_file_offset();
	return;
}

static	WORD	verify_method_syntax(mode)
WORD		mode;		/* POINTER or METHOD */
{
	/* COMMON methods must be POINTERS */
	/* ------------------------------- */
	if ( Context->Visibility & _MEMBER_COMMON ) {
		if  (!(mode))
			return( syntax_error( 2878 ) );
		if (( Context->Visibility & _MEMBER_PRIVATE )
	        &&  ( ClassOptions.Overload == _CLASS_OVERLOAD ))
			return( syntax_error( 2886 ) );
		}

	/* Illegal INLINE/ROUTINE method POINTER */
	/* ------------------------------------- */
	if ( mode ) {
		if (( ClassOptions.Method   == _CLASS_INLINE )
	  	||  ( ClassOptions.Method   == _CLASS_ROUTINE))
			return( syntax_error( 2883 ) );
		}

	switch ( ClassOptions.Special ) {

		case _CLASS_EXCEPTION		:
		case _CLASS_INVARIANT		:
		case _CLASS_PRECONDITION	:
		case _CLASS_POSTCONDITION	:

			/* EXCEPTION/INVARIANT/CONDITION must be INLINE */
			/* -------------------------------------------- */
			if ( ClassOptions.Method != _CLASS_INLINE )
				return( syntax_error( 2877 ) );
			else	break;

		case _CLASS_OPERATOR		:
#ifndef	_INLINE_OPERATORS
			if ( ClassOptions.Method == _CLASS_INLINE )
				return( syntax_error( 2888 ) );
#endif
		case _CLASS_CONSTRUCTOR 	:
		case _CLASS_DESTRUCTOR   	:
			if ( mode )
				return( syntax_error( 2884 ) );
			else	break;
		}

	/* USER or OPERATOR must be STRICT */
	/* ------------------------------- */
	if ( ClassOptions.Strict != _CLASS_STRICT )
		if (( ClassOptions.Special == _CLASS_OPERATOR ) || ( ClassOptions.Method  == _CLASS_USER     )) 
			return( syntax_error( 2887 ) );

	/* Illegal INDIRECT/VIRTUAL/OVERLOAD INLINE/ROUTINE */
	/* ------------------------------------------------ */
	if (( ClassOptions.Virtual  == _CLASS_VIRTUAL ) || ( ClassOptions.Overload == _CLASS_OVERLOAD ) || ( ClassOptions.Direct   == _CLASS_INDIRECT ))	
		if (( ClassOptions.Method   == _CLASS_INLINE ) || ( ClassOptions.Method   == _CLASS_ROUTINE))
			return( syntax_error( 2879 ) );

	/* Illegal ROUTINE/OVERLAY OPERATOR */
	/* -------------------------------- */
	if ( ClassOptions.Special == _CLASS_OPERATOR )
		if (( ClassOptions.Method == _CLASS_ROUTINE ) || ( ClassOptions.Method == _CLASS_OVERLAY ))
			return( syntax_error( 2880 ) );

	/* Illegal RESIDENT INLINE/ROUTINE/USER */
	/* ------------------------------------ */
#ifdef	_BEFORE_19121996
	if ( ClassOptions.Resident ) {
#else
	/* Illegal CALLBACK INLINE/ROUTINE/USER */
	/* ------------------------------------ */
	if (( ClassOptions.Resident ) ||  ( ClassOptions.Resident )) {
#endif
		switch ( ClassOptions.Method ) {
			case	_CLASS_INLINE	:
			case	_CLASS_ROUTINE	:
			case	_CLASS_USER  	:
				return( syntax_error( 2881 ) );
			}
		}

	return( 0 );
}

static	WORD	translate_method_signature(mode)
WORD	mode;		/* 0 : Method, 1 : Method Pointer */
{
	WORD		status;
	WORD		option=0;
	TCMBMETHPTR	mptr;
	BYTE		vname[_MAX_OTR_TOKEN+1];

	trace("translate_method_signature()\n");

	if ((status = verify_method_syntax(mode)) != 0)
		return( status );

	if (!( copy_token( vname, 48 ) ))
		return( syntax_error(853) );

	if ((mptr = allocate_structure_method()) == (TCMBMETHPTR) 0)
		return( allocation_failure() );
	else	establish_method_symbolic( mptr );

	if ( ClassOptions.Special == _CLASS_EXCEPTION )
		mptr->parameters = build_exception_variable( vname );

	if ( next_is_left_brace() ) {
		if ((status = method_allows_parameters()) != 0)
			return( status );
		else	mptr->parameters = collect_typed_parameters((ClassOptions.Method == _CLASS_INLINE ? 1: 0));
		}
	else if ((status = method_requires_parameters()) != 0)
		return( status );

	if (!( mode )) {
		if ( ClassOptions.Method == _CLASS_USER )
			ClassOptions.WorkingMethod = (VPTR)mptr;
		else if ((status = activate_method_target( mptr )) != 0 )
			return( status );
		else if (( ClassOptions.Method == _CLASS_INLINE )
		     &&  ( remove_white_space() ))
			option = _METHOD_MACRO;
		}

	if ((status = set_method_options( mptr, mode )) != 0)
		return( status );
	else	mptr->options |= option;

	if (( ClassOptions.Method == _CLASS_FUNCTION )
	&&  ((status = build_pseudo_object( mptr, World->CurrentStructure )) != 0))
		return( status );
	else	return( add_structure_method( vname, mptr ));
}

static	WORD	method_pointer_type()
{
	TCTYPPTR	tptr;

	trace("method_pointer_type()\n");

	if (( tptr = ClassOptions.ReturnType ) == (TCTYPPTR) 0)
		return( syntax_error(854) );

	else 	{
		switch (( tptr->type & 0x0700 )) {
			case	0x0100 : 
				trace("Overlay Pointer\n");
				ClassOptions.Method = _CLASS_OVERLAY;
				break;	
			case	0x0200 :
				trace("User    Pointer\n");
				ClassOptions.Method = _CLASS_USER;
				break;	
			case	0x0400 :
				trace("Function Pointer\n");
				ClassOptions.Method = _CLASS_FUNCTION;
				break;	
			default		:
				return( syntax_error(855) );
			}
		ClassOptions.ReturnType = (TCTYPPTR) tptr->class;
		ClassOptions.Direct     = _CLASS_INDIRECT;
		tptr->class = (VPTR) 0;
		liberate_for_type( tptr );
		}	
	return( 0 );
}

WORD	translate_pointer_method()
{
	WORD		status;

	trace("translate_pointer_method()\n");

	if ((status = method_pointer_type()) != 0 )
		return( status );

	else if ((status = translate_method_signature(1)) != 0)
		return( status );

	reset_oneshot_options();
	return( 0 );

}

WORD	translate_method()
{
	WORD	status;

	trace("translate_method()\n");

	OtrOption.LabelGroup++;
	if ((!(ClassOptions.Method))
	||  ( ClassOptions.Method == _CLASS_METHOD )) {
		if ( ClassOptions.Direct == _CLASS_INDIRECT )
			ClassOptions.Method = _CLASS_FUNCTION;
		else	ClassOptions.Method = _CLASS_INLINE;
		}
	if ((status = translate_method_signature(0)) != 0)
		return( status );
	else if (ClassOptions.Method == _CLASS_USER )
		return( add_user_function(ClassOptions.WorkingMethod,ClassOptions.Number) );		
	else if ( ClassOptions.MethodText != (VALUEPTR) 0) {
		push_operation_pointer();
		set_operation_pointer(translate_method_text);
		return( translate_method_text() );
		}
	else	{
		reset_oneshot_options();
		return( 0 );
		}
}

WORD	translate_macro_method( member )
TCMEMBERPTR	member;
{
	TCMBMETHPTR	method;
	WORD		status;

	if ((method = allocate_structure_method()) == (TCMBMETHPTR) 0)
		return( allocation_failure() );

	if ( next_is_left_brace() )
		method->parameters = collect_typed_parameters( 1 );

	if ((status = activate_method_target( method )) != 0)
		return( status );

	method->nature  = _CLASS_INLINE;
	method->options = _METHOD_MACRO;
	member->special = (VPTR) method;

	push_operation_pointer();
	set_operation_pointer(translate_macro_text);
	return( translate_macro_text() );

}

WORD	translate_operator()
{
	WORD	operation;
	WORD	status=0;

	if (!( OtrOption.Enhanced | _ENHANCED_OPERATORS ))
		return( syntax_error( 5678 ) );

	switch ((operation = is_operator())) {
		case	0   :
			if ( is_equals() ) {
				operation = '=';
				break;
				}
		case	';' :
		case    ':' :
		case    ',' :
		case	')' :
			return(syntax_error(856));
		}

	if ( is_colon() ) 
		(void) remove_white_space();

	TokenBuffer[0] = (BYTE) operation;
	TokenBuffer[1] = 0;

	if ( ClassOptions.Special )
		return( syntax_error( 2785 ) );
	else	ClassOptions.Special = _CLASS_OPERATOR;

	if ((status = verify_method_syntax(0)) != 0)
		return( status );

	return( translate_method() );
}

static	TCMBPARAPTR	build_operation_parameters( vptr, rterm )
TCVARPTR		vptr;
RESULTPTR		rterm;
{
	TCMBPARAPTR	pptr=(TCMBPARAPTR) 0;

	trace("build_operation_parameters()\n");

	if ((vptr != (TCVARPTR) 0)
	&&  ( vptr->next == (TCVARPTR) 0)
	&&  ((rterm = allocate_protected_result( rterm )) != (RESULTPTR) 0)
	&&  ((pptr  = allocate_method_parameter()) != (TCMBPARAPTR) 0)) {
		pptr->mode     = 2;
		pptr->variable = vptr;
		pptr->result   = rterm;
		}
	else	(void) syntax_error(857);
	return( pptr );
}

static	TCMBPARAPTR	collect_text_parameter( pptr )
TCMBPARAPTR	pptr;
{
	TCMBPARAPTR	wptr;
	WORD		status=0;
	WORD		c;
	WORD		braces=0;

	trace("collect_text_parameter()\n");

	if ((wptr = allocate_method_parameter()) == (TCMBPARAPTR) 0) {
		(void) allocation_failure();
		return( liberate_method_parameters( pptr ) );
		}
	else if ((wptr->text = allocate_text_value()) == (TCTEXTPTR) 0) {
		(void) allocation_failure();
		(void) liberate_method_parameters( wptr );
		return( liberate_method_parameters( pptr ) );
		}

	ClassOptions.MethodText = wptr->text->buffer;
	wptr->mode       = 1;
	wptr->method 	 = (TCMBMETHPTR)input_method();
	wptr->object 	 = (TCVARPTR)input_object();
	wptr->parameters = (TCMBPARAPTR)input_parameters();

	while (1) {
		if ( get_token() ) {
			if ((status = put_method_string( TokenBuffer )) != 0)
				break;
			else	continue;
			}
		else 	{
			switch ((c = get_byte())) {
				case	0 	 :
				case	MOINS_UN :
				case	'\n'	 :
					status = syntax_error( 3877 );
					break;
#ifdef	_BEFORE_10121996
	/*
	 * This code renders it impossible to pass the result of a method
	 * requiring more than one parameter, as a parameter value to 
         * method whose parameter is of type text ie (param). IJM
	 */
				case	';'	 :
					if ( braces )
						status = syntax_error( 878 );
					else	unget_byte();
					break;
#else
				case	';'	 :
					if ( braces ) {
						if ((status = put_method_byte( c )) != 0)
							break;
						else	continue;
						}
					else	{
						unget_byte();
						break;
						}
#endif
				case	')'	 :

					if (!( braces )) {
						unget_byte();
						break;
						}
					else	braces--;

					if ((status = put_method_byte( c )) != 0)
						break;
					else	continue;


				case	'('	 :
					braces++;

				default		 :
					if ((status = put_method_byte( c )) != 0)
						break;
					else	continue;
				}
			}
		break;
		}

	ClassOptions.MethodText = (VALUEPTR) 0;

	if ( status ) {
		(void) allocation_failure();
		(void) liberate_method_parameters( wptr );
		return( liberate_method_parameters( pptr ) );
		}
	else	return( wptr );

}

static	TCMBPARAPTR	collect_optimised_parameter( pptr )
TCMBPARAPTR	pptr;
{
	RESULTPTR	rptr;
	TCMBPARAPTR	wptr;

	trace("collect_optimised_parameter()\n");
	if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0) {
		(void) syntax_error( 858 );
		return( (TCMBPARAPTR) 0);
		}
	else if ((rptr = allocate_protected_result( rptr )) == (RESULTPTR) 0) {
		(void) allocation_failure();
		return( liberate_method_parameters( pptr ) );
		}
	else if ((wptr = allocate_method_parameter()) == (TCMBPARAPTR) 0) {
		(void) allocation_failure();
		return( liberate_method_parameters( pptr ) );
		}
	wptr->mode     = 2;
	wptr->result   = rptr;

	if ( is_question() )
		wptr->retmode = 1;
	else	wptr->retmode = 0;

	return( wptr );
}

static	TCMBPARAPTR	collect_method_parameters( vptr, mode, type )
TCVARPTR		vptr;
WORD			mode;
WORD			type;
{
	WORD		scc_state;
	TCMBPARAPTR	pptr=(TCMBPARAPTR) 0;
	TCMBPARAPTR	lptr=(TCMBPARAPTR) 0;
	TCMBPARAPTR	wptr=(TCMBPARAPTR) 0;
	WORD		more=0;

	trace("collect_method_parameters()\n");

	scc_state = inhibit_semi_colon_comment();

	while (vptr != (TCVARPTR) 0) {

		if (( vptr->type->type != MOINS_UN )
		&&  ( mode == 2 )) {
			if ((wptr = collect_optimised_parameter( pptr )) == (TCMBPARAPTR) 0)
				return( wptr );
			else if (!(more = is_comma()))
				more = is_semi_colon();
			}
		else if ((wptr = collect_text_parameter( pptr )) == (TCMBPARAPTR) 0 )
			return( wptr );
		else	more = is_semi_colon();

		if ( lptr == (TCMBPARAPTR) 0)
			pptr = wptr;
		else	lptr->next = wptr;
		lptr = wptr;
		wptr->variable = vptr;
		if ((vptr = vptr->next) != (TCVARPTR) 0) {
			if ( more )
				continue;
			else	{
				if ( type != _CLASS_INLINE ) {
					/* missing method parameter */
					/* ------------------------ */
					syntax_error( 789 );
					}
				break;
				}

			}
		else if (!( more  )) {
			break;
			}
		else	{
			if ( type != _CLASS_INLINE ) {
				/* too many parameters */
				/* ------------------- */
				syntax_error( 790 );
				}
			break;
			}
		}
	scc_state = restore_semi_colon_comment( scc_state );
	return( pptr );
}

TCMBPARAPTR		collect_strict_parameters()
{
	WORD		status=0;
	WORD		scc_state;
	RESULTPTR	rptr;
	TCMBPARAPTR	pptr=(TCMBPARAPTR) 0;
	TCMBPARAPTR	lptr=(TCMBPARAPTR) 0;
	TCMBPARAPTR	wptr=(TCMBPARAPTR) 0;

	trace("collect_strict_parameters()\n");

	if ( is_left_brace() ) {

		scc_state = inhibit_semi_colon_comment();

		while (1) {
			trace("strict_parameter()\n");
			if ((rptr = evaluate_expression(0)) == (RESULTPTR) 0) {
				/* status = syntax_error(808); */
				break;
				}
			if ((rptr = allocate_protected_result( rptr )) == (RESULTPTR) 0) {
				status = allocation_failure();
				break;
				}
			else if ((wptr = allocate_method_parameter()) == (TCMBPARAPTR) 0) {
				status = allocation_failure();
				break;
				}
			else if ( lptr == (TCMBPARAPTR) 0)
				pptr = wptr;
			else	lptr->next = wptr;
			lptr = wptr;
			wptr->mode     = 2;
			wptr->variable = (TCVARPTR) 0;
			wptr->result   = rptr;

			if ( is_question() )
				wptr->retmode = 1;
			else	wptr->retmode = 0;

			if ((!( is_comma() ))
			&&  (!( is_semi_colon() )))
				break;
			}

		scc_state = restore_semi_colon_comment( scc_state );

		if (!( is_right_brace() ))
			status = unmatched_braces();

		if ( status )
			return( liberate_method_parameters( pptr ) );
		else	return( pptr );
		}
	else	{
		return( pptr );
		}
}


TCVARPTR	is_parameter_variable()
{
	TCVARPTR	vptr=(TCVARPTR) 0;
	RESULTPTR	rptr=(RESULTPTR) 0;

	if  (((rptr = is_parameter_term()) != (RESULTPTR) 0)
	&&   ((rptr->nature & _RESULT_BASIC) == _RESULT_VARB )
	&&   ((vptr = (TCVARPTR)rptr->contents) != (TCVARPTR) 0))
		return( vptr );
	else	return( (TCVARPTR) 0 );
}

static	WORD	parameter_expansion( pptr, mode )
TCMBPARAPTR	pptr;
WORD		mode;
{
	WORD	status;

	trace("parameter_expansion()\n");
					
	/* Attempt to Activate Parameter Source */
	/* ------------------------------------ */
	if ((status = establish_parameter_input(
		 	pptr->object,
			pptr->method,
			pptr->text->buffer, 
			pptr->parameters )) != 0 )
		return( status );
	else if ((status = continue_translation(1)) != 0)
		return( status );
	else	return( 0 );
}

/*
 *	E X P A N D _ P A R A M E T E R ()
 *	----------------------------------
 *
 *	Called from TRPARSER.evaluate_token.expand_token()
 *
 *	The Token in "TokenBuffer" is checked for possible expansion
 *	as a source value parameter of the current context.
 *
 */

WORD	expand_parameter()
{
	TCMBPARAPTR	pptr;
	if ( is_method_definition() )
		return( FAUX );
	if (!(pptr = parameter_term()))
		return( FAUX );
	else if ( pptr->mode != 1 )
		return( FAUX );
	else if ( parameter_expansion( pptr, 0 ) == 0 )
		return( VRAI );
	else	return( FAUX );
}


WORD	translate_parameter_statement()
{
	TCVARPTR	optr;
	TCMBPARAPTR	pptr;
	RESULTPTR	rptr;

	if ((pptr = parameter_term()) != (TCMBPARAPTR) 0) {
		if  ( pptr->mode == 2 ) {
			if  ((rptr = pptr->result) != (RESULTPTR) 0) {
				if (( rptr->nature & _RESULT_BASIC) == _RESULT_VARB ) {
					if ((optr = (TCVARPTR)rptr->contents) != (TCVARPTR) 0)
						return( translate_instruction( optr ) );
					}
				else if (( rptr->nature & _RESULT_BASIC) == _RESULT_EXPR ) {
					if ((optr = register_variable( rptr->contents )) != (TCVARPTR) 0)
						return( translate_instruction( optr ) );
					}
				}
			return( syntax_error( 4508 ) );
			}
		else if ( pptr->mode == 1 )
			return( parameter_expansion( pptr, 1 ) );
		}
	return( MOINS_UN );
}

TCMBPARAPTR		formal_function_parameters( variables )
TCVARPTR		variables;
{
	TCMBPARAPTR	root=(TCMBPARAPTR) 0;
	TCMBPARAPTR	foot=(TCMBPARAPTR) 0;
	TCMBPARAPTR	pptr=(TCMBPARAPTR) 0;
	RESULTPTR	rterm;
	WORD		status=0;

	/* We need to remove the pseudo object : only called for function */
	/* -------------------------------------------------------------- */
	while ((variables = variables->next) != (TCVARPTR) 0) {

		if (((rterm = variable_result( variables->parent )) == (RESULTPTR) 0)
		||  ((rterm = allocate_protected_result( rterm )) == (RESULTPTR) 0)
		||  ((pptr  = allocate_method_parameter()) == (TCMBPARAPTR) 0)) {
			status = allocation_failure();
			break;
			}
		else	{
			pptr->mode     = 2;
			pptr->variable = variables;
			pptr->result   = rterm;
			if ( root == (TCMBPARAPTR) 0 )
				root = pptr;
			else	foot->next = pptr;
			foot = pptr;
			}
		}
	if ( status )
		return( liberate_method_parameters( root ) );
	else	return( root );
}

TCMBPARAPTR		translate_method_parameters( method )
TCMBMETHPTR		method;
{
	TCMBPARAPTR	pptr=(TCMBPARAPTR) 0;
	TCVARPTR	parameters;
	WORD		mode=2;

	trace("translate_method_parameters()\n");

	parameters = explicite_method_parameters( method );

	if ( parameters != (TCVARPTR) 0) {

		if (!( is_left_brace() ))
			return( pptr );

/*
 *		else if ((method->nature == _CLASS_FUNCTION)
 *		     ||  (method->nature == _CLASS_USER    ))
 *			mode = 2;
 */

 		else if (method->nature == _CLASS_INLINE)
			mode=0;
/*
 *		     && (!(OtrOption.Optimise & _OPTIMISE_PARAMETERS)))
 *			mode = 1;
 */
 
		if ((pptr = collect_method_parameters( parameters, mode, method->nature )) == (TCMBPARAPTR) 0)
			return( pptr );
		else if (!( is_right_brace() )) {
			(void) unmatched_braces();
			return( liberate_method_parameters( pptr ) );
			}
		}
	else if (( is_left_brace() )
	     &&  (!( is_right_brace() )) )
		(void) unmatched_braces();

	return( pptr );
}

#include "trcometh.c"

static	BYTE	AnnBuff[512];

WORD	pause_announcement( message )
BPTR	message;
{
	RESULTPTR	rptr;
	if ((rptr = allocate_for_result()) == (RESULTPTR) 0)
		return( allocation_failure() );
	else if ((rptr = build_string_constant( rptr, message )) == (RESULTPTR) 0)
		return( allocation_failure() );
	generate_pause( rptr );
	force_newline();
	return(0);
}

static	WORD	generate_announcement(object,member)
TCVARPTR	object;
TCMEMBERPTR	member;
{
	TCSTRUCTPTR	class;

	if ( member == (TCMEMBERPTR) 0)
		return( 0 );
	force_newline();
	if ( object == (TCVARPTR) 0 )
		strcpy(AnnBuff,"\0");
	else	sprintf(AnnBuff,"%s.",object->name);
	if ((class = member->class) != (TCSTRUCTPTR) 0)
		strcat(AnnBuff,class->name);
	else	strcat(AnnBuff,"[NULL]");
	strcat( AnnBuff, "." );
	strcat( AnnBuff, member->name );
	return( pause_announcement( AnnBuff ) );
}

static	WORD	is_class_announce( member )
TCMEMBERPTR	member;
{
	TCSTRUCTPTR	class;
	if (( member != (TCMEMBERPTR) 0)
	&&  ((class = member->class) != (TCSTRUCTPTR) 0))
		return( class->announce );
	else	return( 0 );
}

static	WORD	method_translation(member)
TCMEMBERPTR	member;
{
	WORD		status;
	EXCEPTIONPTR	exception;
	EXCEPTIONPTR	invariant;
	TCMBMETHPTR	method;

	trace("method_translation()\n");

	if ((method = (TCMBMETHPTR)input_method()) == (TCMBMETHPTR) 0)
		return( internal_error( 4455 ) );

	if (( is_pragma_announce( method->nature ) )
	||  ( is_class_announce( member ) )) {
		if ((status = generate_announcement((TCVARPTR) 0,member)) != 0)
			return( status );
		}

	if ( method->special != _CLASS_EXCEPTION )
		if ((status = initialise_method_local( method )) != 0)
			return( status );
 
	exception = activate_exception();

	invariant = activate_invariant();

	status = context_translation();

	signal_new_line( FAUX );

	if ( invariant != (EXCEPTIONPTR) 0)
		status += terminate_invariant( invariant );

	if ( method->special != _CLASS_EXCEPTION )
		status += terminate_method_local( method );

	if (!( EnhancedConstruction ))
		if ( exception != (EXCEPTIONPTR) 0 )
			status += terminate_exception( exception, MOINS_UN );

	status += activate_postcondition();

	return( status );

}

static	WORD	optimised_parameter_count( parameters )
TCMBPARAPTR	parameters;
{
	WORD	nombre=0;
	while ( parameters != (TCMBPARAPTR) 0) {
		if (( parameters->variable != (TCVARPTR) 0 )
		&&  ( parameters->variable->type->type != MOINS_UN ))
			nombre++;
		parameters = parameters->next;
		}
	return( nombre );
}

WORD	set_invocation_counter( TCMBMETHPTR mptr )
{
	return( mptr->invocation = ++OtrOption.Invocation );
}

WORD	get_invocation_counter( TCMBMETHPTR mptr )
{
	return( mptr->invocation );
}

static WORD activate_inline_method( object, member, method, parameters, mode )
TCVARPTR	object;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
TCMBPARAPTR	parameters;
WORD		mode;
{
	WORD		HoldUse;
	WORD		status;
	TCVARPTR	HoldVariable;
	WORD		HoldType;
	WORD		action;
	WORD		razstatus=0;
	TCSTRUCTPTR	class;
	EXCEPTIONPTR	precond=(EXCEPTIONPTR) 0;

	if ( object != (TCVARPTR) 0 ) {
		while ( object->parent != (TCVARPTR) 0 )
			object = object->parent;

		trace("activate_inline_method("); 
		trace( object->name ); trace("."); trace( member->name );
		trace(")\n");
		}

	class = member->class;

	/* Check for and Activate  Precondition */
	/* ------------------------------------ */
	if ((!( method->options & _METHOD_MACRO ))
	||  ( mode )) {
/*		if ( method->parameters != (TCVARPTR) 0 )
			razstatus = generate_new();
 */
		precond = activate_precondition(method,object);
		}

	/* Check for and Collect Method Parameters */
	/* --------------------------------------- */
	if ( parameters == (TCMBPARAPTR) 0)
		parameters = translate_method_parameters( method );

	/* Establish Macro/Method action mode */
	/* ---------------------------------- */
	if ( method->options & _METHOD_MACRO )
		action = FAUX;
	else if ( method->type != (TCTYPPTR) 0)
		action = VRAI;
	else	action = optimised_parameter_count( parameters );

	/* Attempt to Activate Inline Method */
	/* --------------------------------- */
	if ((status = establish_macro_input( 	object,
						method,
						method->value->buffer, 
						parameters, 
						action )) != 0 )

		return( status );

	else	set_method_infos( method->file, method->line, method->offset );

	if (( method->options & _METHOD_MACRO )
	&&  (!( mode )))
		return( continue_translation(1) );

	/* Translate Inline Method */
	/* ----------------------- */
	HoldVariable = Context->TargetVariable;
	HoldType     = Context->ConvertType;
	HoldUse	     = Context->UseTarget;
	
	status = method_translation(member);

	Context->UseTarget      = HoldUse;
	Context->TargetVariable = HoldVariable;
	Context->ConvertType    = HoldType;

	/* Remove Current Context */
	/* ---------------------- */
	(void) pop_source_context(1);

	/* Check for and Terminate Precondition */
	/* ------------------------------------ */
	if ( precond != (EXCEPTIONPTR) 0)
		status += terminate_condition( precond );

/*	if ( razstatus )
		generate_raz();
 */
	return( status );

}

WORD	activate_macro( member, method )
TCMEMBERPTR	member;
TCMBMETHPTR	method;
{
	if ((member == (TCMEMBERPTR) 0 )
	||  (method == (TCMBMETHPTR) 0 ))
		return( 0 );
	else	return( activate_inline_method( input_object(), member, method ,(TCMBPARAPTR) 0, 0));
}

static	TCMBGSBPTR resolve_routine_method( object, member )
TCVARPTR	object;
TCMEMBERPTR	member;
{
	TCMBGSBPTR	routine;
	TCMBGSBPTR	rptr;

	if ((routine = locate_routine_method( object, member )) == (TCMBGSBPTR) 0) {
		if ((routine = allocate_routine_method()) == (TCMBGSBPTR) 0)
			return( routine );
		else	{
			routine->label  = new_implicite_label();
			routine->object = object;
			routine->member = member;
			if ((rptr = RoutineHeap) == (TCMBGSBPTR) 0)
				RoutineHeap = routine;
			else 	{
				while (rptr->next != (TCMBGSBPTR) 0)
					rptr = rptr->next;
				rptr->next = routine;
				}
			}
		}
	return( routine );
}

static WORD activate_routine_method( object, member, method, parameters, mode )
TCVARPTR	object;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
TCMBPARAPTR	parameters;
WORD		mode;
{
	TCMBGSBPTR	routine;
	WORD		status=0;
	EXCEPTIONPTR	precond=(EXCEPTIONPTR) 0;

	trace("activate_routine_method("); 
	trace( object->name ); trace("."); trace( member->name );
	trace(")\n");

	if (( parameters != (TCMBPARAPTR) 0)
	||  ( is_left_brace()              ))
		return( syntax_error(859) );
	
	while ( object->parent != (TCVARPTR) 0 )
		object = object->parent;

	if ((routine = resolve_routine_method(object,member)) == (TCMBGSBPTR) 0)
		return( allocation_failure() );

	/* Check for and Activate  Precondition */
	/* ------------------------------------ */
	precond = activate_precondition(method, object);


	if ( OtrOption.ListFlag & 1 )
		echo_gosub_routine( object->name, member->name );

	status = implicite_gosub( routine->label );

	/* Check for and Terminate Precondition */
	/* ------------------------------------ */
	if ( precond != (EXCEPTIONPTR) 0)
		status += terminate_condition( precond );

	return( status );
}

WORD	flush_routine_methods()
{
	TCMBGSBPTR	routine;
	TCMBMETHPTR	method;
	WORD		status=0;

	
	if  ((routine = RoutineHeap) != (TCMBGSBPTR) 0) {

		do	{
			if ( routine->status ) 
				continue;
			else	routine->status = VRAI;

			force_newline();

			dcl_implicite_label( routine->label );

			if ( OtrOption.ListFlag & 1 )
				echo_routine( routine->object->name, routine->member->name );

			if ( OtrOption.Verbose & 8  )
				sysprintf("Routine  : %s.%s : &%04.1X \n",routine->object->name,routine->member->name,current_tcode_offset());

			if (((method = (TCMBMETHPTR)routine->member->special) != (TCMBMETHPTR) 0)
			&&  ((status = establish_macro_input( 	routine->object,
								method,
								method->value->buffer, 
								(TCMBPARAPTR) 0, 
								0 )) == 0)) {

				set_method_infos( method->file, method->line, method->offset );

				/* Translate Method Text */
				/* --------------------- */
				status = method_translation(routine->member);

				/* Remove Current Context */
				/* ---------------------- */
				(void) pop_source_context(1);

				}

			if ( status != 0 ) {
				status = syntax_error( 1010 );
				break;
				}

			force_newline();
			implicite_return();

			}

		while ((routine = routine->next) != (TCMBGSBPTR) 0);
		force_newline();
		}

	while ((routine = RoutineHeap) != (TCMBGSBPTR) 0) {
		RoutineHeap = routine->next;
		liberate( routine );
		}
	return(status);
}

WORD	trace_message( mptr )
BPTR	mptr;
{
	trace("before:");
	trace( mptr );
	trace("()\n");
	return(1);
}

WORD		flush_function_method( class, member, method, procedure )
TCSTRUCTPTR	class;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
TCPRCPTR	procedure;
{
	WORD	status;

	if ( OtrOption.Verbose & 8 ) {
		sysprintf("%s : ",class->name);
		echo_method( member, method );
		echo_line();
		}

	method->parameters->type->size = object_occupation(class);
			
	/* Translate Method Text */
	/* --------------------- */
	if (((status = start_procedure( procedure, FAUX )) == 0)
	&&  ((status = enter_procedure_translation()) == 0)
	&&  ((status = establish_macro_input( 	
				method->parameters->parent,
				method,
				method->value->buffer, 
				(TCMBPARAPTR) 0, 0  )) == 0)) {
		set_method_infos( method->file, method->line, method->offset );
		status = method_translation(member);
		force_newline();
		status += terminate_procedure();
		drop_local_symbols();
		leave_segmental_translation();

		/* Remove Current Context */
		/* ---------------------- */
		(void) pop_source_context(1);

		method->parameters->parent = (TCVARPTR) 0;

		}
	return( status );
}

WORD	flush_function_methods( overlay_mode )
WORD	overlay_mode;
{
	TCMBFUNCPTR	function;
	WORD		status=0;

	if ((function = FunctionHeap) != (TCMBFUNCPTR) 0) {
		do	{

			if ( function->status )
				continue;
			else	{
				function->status = VRAI;
				status = flush_function_method( 
						function->class,
						function->member,
						function->member->special,
						function->procedure );		
				}

			if ( status != 0 )
				break;
			}
		while ((function = function->next) != (TCMBFUNCPTR) 0);
		}

	if (!( overlay_mode )) {
		while ((function = FunctionHeap) != (TCMBFUNCPTR) 0) {
			FunctionHeap = FunctionHeap->next;
			liberate( function );
			}
		}
	return(status);
}

WORD	flush_overlay_methods()
{
	TCMBOVLPTR	overlay;
	TCMBMETHPTR	method;
	TCVARPTR	object;
	WORD		status=0;
	WORD		nature;

	if ((overlay = OverlayHeap) != (TCMBOVLPTR) 0) {
		do	{

			if ( overlay->status )
				continue;
			else	overlay->status = VRAI;

			if ( OtrOption.Verbose & 8 ) {
				if ( overlay->field )
					sysprintf("Field=%u: ",overlay->field);
				sysprintf("Overlay  : %s.%s \n",overlay->class->name,overlay->member->name);
				}
			if ((method = (TCMBMETHPTR)overlay->member->special) == (TCMBMETHPTR) 0)
				break;
			else if ( method->options & _METHOD_RESIDENT )
				nature = 1;
			else	nature = 0;

			/* Build Segment then Translate Method Text */
			/* ---------------------------------------- */
			if ((status = start_segment( overlay->segment, nature, FAUX )) != 0) {
				status = internal_error( 5551 );
				break;
				}
			else if ((status = enter_segmental_translation()) != 0) {
				status = internal_error( 5552 );
				break;
				}
			release_expressions(1);
			if ((object = segment_pseudo_object( overlay->object, overlay->class, overlay->field )) == (TCVARPTR) 0) {
				status = internal_error( 5553 );
				break;
				}
			else if ((status = establish_macro_input( 
						object,
						method,
						method->value->buffer, 
						(TCMBPARAPTR) 0,
						0 )) != 0) {
				status = internal_error( 5554 );
				break;
				}
			else	{

				set_method_infos( method->file, method->line, method->offset );

				if ((status = method_translation(overlay->member)) != 0) {
					status = internal_error( 5555 );
					break;
					}
				else if ((status = terminate_segment( overlay->segment->identity, overlay->segment->name, VRAI)) != 0) {
					status = internal_error( 5556 );
					break;
					}
				drop_local_symbols();
				leave_segmental_translation();

				/* Remove Current Context */
				/* ---------------------- */
				(void) pop_source_context(1);

				}

			}
		while ((overlay = overlay->next) != (TCMBOVLPTR) 0);

		}

	while ((overlay  = OverlayHeap) != (TCMBOVLPTR) 0) {
		OverlayHeap = OverlayHeap->next;
		liberate( overlay );
		}

	return(status);
}

static	BPTR	function_name(nptr)
BPTR	nptr;
{
	sprintf(FunctionName,"_F%u_%s",NextFunction++,nptr);
	return( FunctionName );
}

static	BPTR	class_function_name(member,method)
TCMEMBERPTR	member;
TCMBMETHPTR	method;
{
	if (!( member->class ))
		return( function_name( member->name ) );

	else if ( method->options & _METHOD_STRICT ) {
		sprintf(FunctionName,"_F%u_%s.%s",NextFunction++ /* method->alternative */,member->class->name,member->name);
		return( (BPTR) FunctionName );
		}
	else	{
		sprintf(FunctionName,"%s.%s",member->class->name,member->name);
		return( (BPTR) FunctionName );
		}
}


static	WORD	call_function_method( prcptr, object, pptr )
TCPRCPTR	prcptr;
TCVARPTR	object;
TCMBPARAPTR	pptr;
{

	PRCPTR	context=(PRCPTR) 0;
	WORD	status;
	WORD	option=0;

	trace("call_function_method()\n");

	if ((context = start_prc( prcptr,(prcptr ? prcptr->result : (TCTYPPTR) 0) )) == (PRCPTR) 0)
		return( allocation_failure() );

	else if ((status = store_clp( context, integer_result( prcptr->identity ),0)) != 0)
		return( status );

	else if ((object->type->size)
	     &&  ((status = store_clp( context, variable_result( object ),0)) != 0))
		return( status );

	while ( pptr != (TCMBPARAPTR) 0 ) {
		if (( pptr->variable != (TCVARPTR) 0 )
		&&  ( pptr->variable->access & _TYPE_QUESTION ))
			option = 1;
		else if ( pptr->retmode )
			option = 1;
		else	option = 0;
		if ((status = store_clp( context, pptr->result, option )) != 0)
			return( status );
		else	pptr = pptr->next;
		}

	if ((status = clp_error_trap(context)) != 0)
		return( status );

	status = flush_clp( context );
	liberate_clp( context );
	return( status );
}

static	WORD	call_function_pointer( procptr, object, pptr, tptr )
TCVARPTR	procptr;
TCVARPTR	object;
TCMBPARAPTR	pptr;
TCTYPPTR	tptr;
{

	TCPRCPTR	prcptr=(TCPRCPTR) 0;
	PRCPTR		context=(PRCPTR) 0;
	RESULTPTR	rptr;
	WORD		status;
	WORD		option=0;

	trace("call_function_pointer()\n");

	if ( procptr == (TCVARPTR) 0 )
		return( internal_error( 6587 ) );

	if ((context = start_prc( prcptr, tptr )) == (PRCPTR) 0)
		return( allocation_failure() );

	if ((rptr = variable_result( procptr )) == (RESULTPTR) 0)
		return( allocation_failure() );

	if ((status = store_clp( context, rptr,0)) != 0)
		return( status );

	if ((object != (TCVARPTR) 0)
	&&  (object->type != (TCTYPPTR) 0)
        &&  (object->type->size != 0)
        &&  ((status = store_clp( context, variable_result( object ),0)) != 0))
		return( status );

	while ( pptr != (TCMBPARAPTR) 0 ) {
		if (( pptr->variable != (TCVARPTR) 0 )
		&&  ( pptr->variable->access & _TYPE_QUESTION ))
			option = 1;
		else if ( pptr->retmode )
			option = 1;
		else	option = 0;
		if ((status = store_clp( context, pptr->result, option )) != 0)
			return( status );
		else	pptr = pptr->next;
		}

	if ((status = clp_error_trap(context)) != 0)
		return( status );

	status = flush_clp( context );

	liberate_clp( context );

	return( status );
}


TCMBFUNCPTR	build_function_method( class, member, method, mode )
TCSTRUCTPTR	class;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
WORD		mode;	/* Extern */
{
	TCMBFUNCPTR	function;
	TCMBFUNCPTR	fptr;
	WORD		module=0;
	WORD		options;
	BPTR		fname=(BPTR) 0;

	if ((function = allocate_function_method()) != (TCMBFUNCPTR) 0) {

		if ( class->access & _MEMBER_EXTERN ) {
			module = resolve_module_number( class->module, 1 );
			function->status = VRAI;
			if ( member != (TCMEMBERPTR) 0)
				fname = class_function_name( member,method  );
			else	fname = function_name( class->name );
			}

		else if ( member == (TCMEMBERPTR) 0)
			fname = function_name( class->name );
/*
		else if ( mode )
			fname = member->name;
 */
		else	fname = class_function_name(member,method);

		if ( method->options & _METHOD_RESIDENT )
			options = 0;
		else	options = 1;
		if ((function->procedure = add_function_method(
				fname,
				method->parameters,
				method->type,0,module,options,
				( class->access & _MEMBER_EXTERN ? MOINS_UN : FAUX )
				)) != (TCPRCPTR) 0) {
			function->procedure->class = (VPTR) class;
			function->procedure->member= (VPTR)member;
			function->class  	= class;
			function->member 	= member;
			function->type   	= method->type;
			function->parameters	= method->parameters;
			if (( fptr = FunctionHeap ) == (TCMBFUNCPTR) 0)
				FunctionHeap = function;
			else	{
				while ( fptr->next != (TCMBFUNCPTR) 0 )
					fptr = fptr->next;
				fptr->next = function;
				}
			}
		else	{
			liberate( function );
			function = (TCMBFUNCPTR) 0;
			}
		}
	return( function );
}

TCVARPTR	resolve_method_pointer( variable, method )
TCVARPTR	variable;
TCMBMETHPTR	method;
{
	TCVARPTR	current;
	TCMBMETHPTR	special;
	TCVARPTR	parameters;

	if ( variable )
		while ( variable->parent != (TCVARPTR) 0 )
			variable = variable->parent;

	trace("resolve_method_pointer(");
		trace(variable->name);
	trace(")\n");

	/* Avoid Implicite Object First Parameter for Functions */
	/* ---------------------------------------------------- */
	parameters = explicite_method_parameters( method );

	if ((current = variable) != (TCVARPTR) 0) {
		do	{
			if ( current->hash != variable->hash )
				continue;
			else if ( current->master != variable->master )
				continue;
			else if ( current->type->type & _TYPE_DEFINED )
				continue;
			else if (!( compare_tokens( current->name, variable->name ) ))
				continue;
			else if (!(special = (TCMBMETHPTR)current->type->class))
				continue;
			else if ( compare_parameter_list( explicite_method_parameters( special ), parameters ))
				break;
			}
		while ((current = current->prev) != (TCVARPTR) 0);
		}
	return( current );
}

TCVARPTR	resolve_method_table( object )
TCVARPTR	object;
{
	TCVARPTR	imtptr;
#ifdef	DEBUG_IMT
 	sysprintf("resolve_method_table of %s\n",object->name);
#endif
	if ((imtptr = object->prev) != (TCVARPTR) 0) {
		do	{
#ifdef	DEBUG_IMT
 			sysprintf("\t test %s : %u =?= %u : %u =?= %u \n",
  				imtptr->name,object->hash,imtptr->hash,
 				object->identity, imtptr->master);
#endif

			if (( object->hash == imtptr->hash )
			&&  ( object->identity == imtptr->master ))
				break;			
			}
		while ((imtptr = imtptr->prev ) != (TCVARPTR) 0);
		}

#ifdef	DEBUG_IMT
 	if ( imtptr != (TCVARPTR) 0 )
 		sysprintf("\t found %s\n",imtptr->name);
 	else	sysprintf("\t fail   \n");
#endif
	return( imtptr );
}

TCVARPTR	overlay_object_method( object, number )
TCVARPTR	object;
WORD		number;
{
	TCVARPTR	procptr;
	RESULTPTR	result;

	trace("object_overlay_method()\n");
	if (((procptr = resolve_method_table(object)) != (TCVARPTR) 0)
	&&  ((procptr = temp_variable( procptr )) != (TCVARPTR) 0)
	&&  ((result  = integer_result( number )) != (RESULTPTR) 0)) {
		procptr->firstdim = (VPTR)result;
		return( procptr );
		}
	else	return( (TCVARPTR) 0 );
}

WORD	method_object_alias( procptr, object )
TCVARPTR	procptr;
TCVARPTR	object;
{
	RESULTPTR	result;
	RESULTPTR	source;

	trace("method_object_alias()\n");

	while ( procptr->parent != (TCVARPTR) 0 )
		procptr = procptr->parent;


	if ((result = variable_result( procptr->prev )) == (RESULTPTR) 0)
		return( allocation_failure() );
	else if ((source = variable_result( object )) == (RESULTPTR) 0)
		return( allocation_failure() );
	else	return( clf_alias( result, source ) );
}

WORD	affect_function_pointer( procptr, object, class, member, method )
TCVARPTR	procptr;
TCVARPTR	object;
TCSTRUCTPTR	class;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
{
	RESULTPTR	result;
	RESULTPTR	source;
	TCMBFUNCPTR	function;
	WORD		status;

	trace("affect_function_pointer()\n");

	Context->TargetVariable = procptr;
	Context->UseTarget = 1;

	if ((result  = variable_result(( Context->TargetVariable  ))) == (RESULTPTR) 0)
		return( allocation_failure() );

	else if (((function = locate_function_method( class, member, method->parameters )) == (TCMBFUNCPTR) 0)
	     &&  ((function = build_function_method( class, member, method, 0 )) == (TCMBFUNCPTR) 0)) {
		Context->UseTarget = 0;
		return( allocation_failure() );
		}

	else if ((source = integer_result( function->procedure->identity )) == (RESULTPTR) 0) {
		Context->UseTarget = 0;
		return( allocation_failure() );
		}
	status = clf_funcptr( result, source, function->procedure );
	Context->UseTarget = 0;
	if (status != 0)
		return( status );
	else	return( 0 );
}

WORD	resolve_method_context( world, member, sptr, optr )
TCVARPTR		world;
TCMEMBERPTR		member;
TCSTRUCTPTR XPTR	sptr;
TCVARPTR XPTR		optr;
{
	TCSTRUCTPTR	objclass;
	TCSTRUCTPTR	class=(TCSTRUCTPTR) 0;
	TCVARPTR	object;

	if ((member != (TCMEMBERPTR) 0)
	&&  (!( member->access & _MEMBER_DYNAMIC ))) {
		if ((class = member->class ) == (TCSTRUCTPTR) 0)
			return( internal_error( 9877 ) );
		else if ((objclass = (TCSTRUCTPTR)world->type->class) == (TCSTRUCTPTR) 0)
			return( syntax_error(9878) );
		if ((objclass->hash != class->hash ) 
		||  (!( compare_tokens( objclass->name, class->name ) )) ) {
			if (( object = resolve_member_variable( world, class->name, class->hash )) == (TCVARPTR) 0)
				return( internal_error( 9879 ) );
			}
		else	object = world;
		}
	else	object = world;

	if ((class == (TCSTRUCTPTR) 0)
	&& ((class = (TCSTRUCTPTR)world->type->class) == (TCSTRUCTPTR) 0))
		return( syntax_error(860) );
	else	{
		*sptr = class;
		*optr = object;
		return( 0 );
		}
}

WORD	resolve_method_componant( aptr, procptr )
TCMBAUTOPTR	aptr;
TCVARPTR XPTR	procptr;
{
	if (( aptr->method->number )
	&&  ( aptr->method->nature != _CLASS_USER )) {
		if ((*procptr = overlay_object_method( aptr->object, aptr->method->number )) == (TCVARPTR) 0) {
			strcpy( TokenBuffer, aptr->member->name );
			return( syntax_error( 7862 ) );
			}
		else	return( 0 );
		}
	else	{

		if ((*procptr = resolve_member_componant( aptr->object, aptr->member )) == (TCVARPTR) 0) {
			strcpy( TokenBuffer, aptr->member->name );
			return( syntax_error( 7833 ) );
			}
		if (( aptr->method->options & _METHOD_STRICT )
		&&  ((*procptr = resolve_method_pointer( *procptr, aptr->method )) == (TCVARPTR) 0))
			return( internal_error( 2002 ) );
		else	return( 0 );
		}
}
	
static	WORD	initialise_indirect_function( aptr )
TCMBAUTOPTR	aptr;
{
	TCSTRUCTPTR	class=(TCSTRUCTPTR) 0;
	TCVARPTR   	object=(TCVARPTR) 0;
	TCVARPTR	procptr=(TCVARPTR) 0;
	WORD		status;

	if ((status = resolve_method_context( 
				aptr->object, aptr->member,
				(TCSTRUCTPTR XPTR) & class, 
				(TCVARPTR XPTR) & object )) != 0 )
		return( status );

	else if ((status = resolve_method_componant( aptr, (TCVARPTR XPTR) & procptr )) != 0)
		return( status );


	if ((status = affect_function_pointer( procptr, object, aptr->member->class, aptr->member, aptr->method )) != 0)
		return( status );
	else if ( aptr->member->access & (_MEMBER_OVERLOAD | _MEMBER_VIRTUAL) )
		return( method_object_alias( procptr, object ) );
	else	return( 0 );
}

static	WORD	initialise_indirect_method( aptr )
TCMBAUTOPTR	aptr;
{
	switch ( aptr->method->nature ) {
		case	_CLASS_FUNCTION :
			return( initialise_indirect_function( aptr ) );
		case	_CLASS_USER     :
			return( initialise_indirect_user( aptr ) );
		case	_CLASS_OVERLAY  :
			return( initialise_indirect_overlay( aptr ) );
		default			:
			return( internal_error( 5656 ) );
		}
}

/*
 *	B A S E _ M E M B E R _ F I E L D ( master, member )
 *	----------------------------------------------------
 *
 *	This function is called in order to establish the vdt field
 *	information required for redefinition of : 
 *
 *		a BASE CLASS VIRTUAL INDIRECT FUNCTION METHOD
 *
 *	by	a DERIVED CLASS OVERLOAD INDIRECT FUNCTION METHOD
 *
 *	VIRTUAL and OVERLOAD INDIRECT members are composed of the
 *
 *	binome		DCL PROC <member>
 *			PTR      <member>$=sizeof <class>
 *
 */

/* Field = Virtual Base Member */
/* --------------------------- */
WORD	field_equals_vbm( vptr, indent, member )
TCVARPTR	vptr;
LONG		indent;
TCMEMBERPTR	member;
{
	if (( Context->LDT != (TCVDTPTR) 0 )
	&&  (!( vptr->identity & ISLOCAL ))) {
		while ( vptr->parent != (TCVARPTR) 0)
			vptr = vptr->parent;
		member->common = vptr;
		member->access  |= _MEMBER_COMMON;
		return( 0 );
		}
	else	return( field_equals_v( vptr, indent ) );
}

WORD		base_member_field( master, member, method )
WORD		master;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
{
	TCVARPTR	object;
	TCVARPTR	objet;
	TCMEMBERPTR	mptr;
	TCVARPTR	bptr;

	trace("base_member_field()\n");

	/* Collect current MASTER OBJECT variable */
	/* -------------------------------------- */
	if ((object = locate_master_object( master )) == (TCVARPTR) 0) {
		strcpy( TokenBuffer, member->name );
		return( syntax_error( 7447 ) );
		}
	else	objet = object;

	/* Locate applicable BASE CLASS MEMBER */
	/* ----------------------------------- */
	while ((mptr = locate_baseclass_member((TCVARPTR XPTR) & object, object, object->type->class, member->name,0)) == (TCMEMBERPTR) 0) {
		if ((object = next_master_object( object->prev, master)) == (TCVARPTR) 0) {
			sprintf( TokenBuffer,"%s in %s", member->name,objet->name );
			return( syntax_error( 7448 ) );
			}
		}

	/* Ensure Target is of required type : VIRTUAL and or OVERLOAD */
	/* ----------------------------------------------------------- */
	if (!( mptr->access & (_MEMBER_VIRTUAL | _MEMBER_OVERLOAD) )) {
		strcpy( TokenBuffer, member->name );
		return( syntax_error( 2323 ) );
		}

	/* Collect Target BASE CLASS MEMBER variable */
	/* ----------------------------------------- */
	if ((bptr = resolve_member_componant( object, mptr )) == (TCVARPTR) 0)
		return( internal_error( 7450 ) );

	if (( method->options & _METHOD_STRICT )
	&&  ((bptr = resolve_method_pointer( bptr, method )) == (TCVARPTR) 0))
		return( internal_error( 7451 ) );

	/* Save current field and establish BASE MEMBER field */
	/* -------------------------------------------------- */
	OverloadHost = bptr;
	while ( OverloadHost->parent != (TCVARPTR) 0)
		OverloadHost = OverloadHost->parent;
	field_equals_s();  return( field_equals_vbm( bptr, 0L, member ) );
}

WORD    	locate_method_pointer( object, method, host, result, member )
TCVARPTR	object;
TCMBMETHPTR	method;
TCVARPTR XPTR	host;
TCVARPTR XPTR	result;
TCMEMBERPTR	member;
{
	TCVARPTR	procptr;
	TCVARPTR	container;

	if (( method->number )
	&&  ( method->nature != _CLASS_USER )) {
		if ((procptr = overlay_object_method( object, method->number )) == (TCVARPTR) 0) {
			strcpy( TokenBuffer, member->name );
			return( syntax_error( 7861 ) );
			}
		}
	else	{
		if ((procptr = resolve_member_componant( object, member )) == (TCVARPTR) 0) {
			strcpy( TokenBuffer, member->name );
			return( syntax_error( 7862 ) );
			}
		if (( method->options & _METHOD_STRICT )
		&&  ((procptr = resolve_method_pointer( procptr, method )) == (TCVARPTR) 0)) {
			strcpy( TokenBuffer, member->name );
			return( syntax_error( 7863 ) );
			}
		else if (method->options & (_METHOD_VIRTUAL | _METHOD_OVERLOAD)) {

			/* Locate Object Container Pointer */
			/* ------------------------------- */
			container = procptr;
			while ( container->parent != (TCVARPTR) 0)
				container = container->parent;
			container = container->prev;
			*host = container;

			}

		}
	*result = procptr;
	return( 0 );
}

static WORD activate_function_method( object, member, method, parameters, mode, option )
TCVARPTR	object;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
TCMBPARAPTR	parameters;
WORD		mode;
WORD		option;
{
	TCMBFUNCPTR	function;
	TCSTRUCTPTR	class=(TCSTRUCTPTR) 0;
	TCSTRUCTPTR	objclass=(TCSTRUCTPTR) 0;
	TCVARPTR	procptr=(TCVARPTR) 0;
	WORD		status=0;
	TCVARPTR	container=(TCVARPTR) 0;
	EXCEPTIONPTR	precond=(EXCEPTIONPTR) 0;

	if ((status = resolve_method_context( object, member, & class, & container )) != 0)
		return( status );

	while ( object->parent != (TCVARPTR) 0 )
		object = object->parent;

	if (( method->options & _METHOD_INDIRECT )
	&&  ( option )) {

		if ((status = locate_method_pointer( object, method, & container, & procptr , member )) != 0)
			return( status );

		}
	else if ((function = locate_function_method( class, member, method->parameters )) == (TCMBFUNCPTR) 0)
		if ((function = build_function_method( class, member, method, 0 )) == (TCMBFUNCPTR) 0)
			return( allocation_failure() );

	/* Check for and Activate  Precondition */
	/* ------------------------------------ */
	precond = activate_precondition(method,object);

	if ( parameters == (TCMBPARAPTR) 0)
		parameters = translate_method_parameters( method );

	if (( method->options & _METHOD_INDIRECT ) &&  ( option ))
		status = call_function_pointer( procptr, container, parameters, method->type );
	else	status = call_function_method( function->procedure, container, parameters );

	/* Check for and Terminate Precondition */
	/* ------------------------------------ */
	if ( precond != (EXCEPTIONPTR) 0 )
		status += terminate_condition( precond );

	liberate_method_parameters( parameters );

	return( status );
}

WORD	detect_memory_field( container )
TCVARPTR	container;
{
	WORD	field=0;
	if ((field = (container->type->type & 0xFF00)) != 0 ) {
		if ( field > 0x4000 )
			field = 0;
		else	field >>= 8;
		}
	return( field );
}

static WORD activate_overlay_method( object, member, method, parameters, mode, option )
TCVARPTR	object;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
TCMBPARAPTR	parameters;
WORD		mode;
WORD		option;
{
	TCVARPTR	container;
	TCMBOVLPTR	overlay;
	TCSTRUCTPTR	class;
	TCVARPTR	procptr;
	EXCEPTIONPTR	precond=(EXCEPTIONPTR) 0;
	WORD		status=0;
	WORD		field;

	trace("activate_overlay_method("); 
	trace( object->name ); trace("."); trace( member->name );
	trace(")\n");

	if (( parameters != (TCMBPARAPTR) 0)
	||  ( is_left_brace()              ))
		return( syntax_error(862) );
	else if ( Context->PRC != (TCPRCPTR) 0 ) {
		(void) issue_warning( 6 );
		method->nature = _CLASS_FUNCTION;
		if ((status = build_pseudo_object( method, member->class )) != 0)
			return( syntax_error(888) );
		else	return( activate_function_method(object, member, method, parameters, mode, option ) );		
		}

	if ((status = resolve_method_context( object, member, & class, & container )) != 0)
		return( status );

	while ( object->parent != (TCVARPTR) 0 )
		object = object->parent;

	field = detect_memory_field( container );

	if (( method->options & _METHOD_INDIRECT )
	&&  ( option )) {

		if ((status = locate_method_pointer( object, method, & container, & procptr , member )) != 0)
			return( status );

		}
	else if ((overlay = locate_overlay_method( member->class,  member, field )) == (TCMBOVLPTR) 0)
		if ((overlay = build_overlay_method( object, member->class, member, field )) == (TCMBOVLPTR) 0)
			return( allocation_failure() );


	/* Check for and Activate  Precondition */
	/* ------------------------------------ */
	precond = activate_precondition(method, object);

	status = overlay_method_parameter( container, field );

	if ( OtrOption.ListFlag & 1 )
		echo_load_overlay( container->name, member->name );

	if (( method->options & _METHOD_INDIRECT )
	&&  ( option ))
		status = generate_call_segment( procptr );
	else if ( overlay->segptr  != (XTSEGPTR) 0)
		status += ldgo_extern_segment( overlay->segptr  );
	else if ( overlay->segment != (TCSEGPTR) 0)
		status += ldgo_intern_segment( overlay->segment );
	else	status += internal_error( 1414 );

	/* Check for and Terminate Precondition */
	/* ------------------------------------ */
	if ( precond != (EXCEPTIONPTR) 0)
		status += terminate_condition( precond );

	return( status );
}

WORD	is_method_pointer( method )
TCMBMETHPTR	method;
{
	if ( method != (TCMBMETHPTR) 0) {

		switch ( method->nature ) {
			case	_CLASS_FUNCTION	:
			case	_CLASS_USER	:
			case	_CLASS_OVERLAY	:
				return( (method->options & _METHOD_ISPOINTER) );
			}
		}

	return( FAUX );

}

WORD	method_occupation( member, method )
TCMEMBERPTR	member;
TCMBMETHPTR	method;
{
	switch ( method->nature ) {
		case	_CLASS_FUNCTION	:
		case	_CLASS_USER	:
		case	_CLASS_OVERLAY	:
			if ( method->options & _METHOD_INDIRECT ) {
				if (( method->number )
				&&  ( method->nature != _CLASS_USER ))
					return( 0 );
				else if ( member->access & _MEMBER_OVERLOAD )
					return( 0 );
				else if ( member->access & _MEMBER_VIRTUAL )
					return( 10 );
				else if ( member_enhanced_indirect( member ) )
					return( 5 );
				
				}
		default			:
			return( 0 );
		}
}

VOID	verbalise_method( object, class, member )
TCVARPTR	object;
TCSTRUCTPTR	class;
TCMEMBERPTR	member;
{
	BPTR	nptr;
	if ( member != (TCMEMBERPTR) 0) {
		if (!( nptr = member->name ))
			nptr = "unnamed";
		sysprintf("\nMethod : %s(%s).%s ",
			object->name,
			class->name,
			nptr);
		echo_method( member, member->special);
		sysprintf("\n");
		}
	return;
}

static WORD	ll_activate_method( object, member, method, parameters, mode, option )
TCVARPTR	object;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
TCMBPARAPTR	parameters;
WORD		mode;		/* Explicite Activation 	: 0	*/
				/* Implicite Construction	: 1	*/

WORD		option;
{
	trace("ll_activate_method()\n");

	if ( OtrOption.SourceTrace & 1 )
		verbalise_method( object, object->type->class, member );

	switch ( method->nature ) {

		case	_CLASS_INLINE	:
			return( activate_inline_method( object, member, method, parameters, mode ) );

		case	_CLASS_ROUTINE	:
			return( activate_routine_method( object, member, method, parameters, mode ) );

		case	_CLASS_FUNCTION	:
			return( activate_function_method( object, member, method, parameters, mode, option ) );

		case	_CLASS_OVERLAY	:
			return( activate_overlay_method( object, member, method, parameters, mode, option ) );

		case	_CLASS_USER   	:
			return( activate_user_method( object, member, method, parameters, mode, option ) );

		}

	return( internal_error( 5656 ) );
}

WORD	verify_operator_parameter( method, result )
TCMBMETHPTR	method;
RESULTPTR	result;
{
	TCVARPTR	vptr;
	if ( method != (TCMBMETHPTR) 0)
		if ( result != (RESULTPTR)   0)
			if ((vptr = explicite_method_parameters(method)) != (TCVARPTR) 0)
				return( verify_result_type( result, vptr->type ) );
	return( FAUX );
}

WORD		verify_strict_parameters( vptr, pptr )
TCVARPTR	vptr;
TCMBPARAPTR	pptr;
{
	trace("verify_strict_parameters()\n");
	while (1) {
		if ( vptr == (TCVARPTR) 0 ) {
			if ( pptr == (TCMBPARAPTR) 0 )
				return( VRAI );
			else	return( FAUX );
			}
		if ( pptr == (TCMBPARAPTR) 0 )
			return( FAUX );
		else if ( vptr->type->type == _TYPE_BASIC )
			return( VRAI );
		else if (!( verify_result_type( pptr->result, vptr->type ) ))
			return( FAUX );
		else	{
			pptr->variable = vptr;
			vptr = vptr->next;
			pptr = pptr->next;
			}
		}
}

WORD	is_strict_method( method )
TCMBMETHPTR	method;
{
	if (( method != (TCMBMETHPTR) 0 )
	&&  ( method->options & _METHOD_STRICT ))
		return( VRAI );
	else	return( FAUX );
}

WORD	compare_strict_methods( optr, nptr )
TCMBMETHPTR	optr;
TCMBMETHPTR	nptr;
{

	return( compare_parameter_list(	explicite_method_parameters(nptr), 
					explicite_method_parameters(optr) ) );
}

TCMEMBERPTR	locate_alternative_method( name, hash, member )
BPTR		name;
WORD		hash;
TCMEMBERPTR	member;
{
	trace("locate_alterative_method()\n");

	while ( member != (TCMEMBERPTR) 0 ) {
		if ((!( member->nature ))
		&&  ( hash == member->hash )
		&&  ( compare_tokens( name, member->name ) ))
			break;
		else	member = member->next;
		}
	return( member );
}

TCMEMBERPTR	locate_strict_alternative( original, member )
TCMEMBERPTR	original;
TCMEMBERPTR	member;
{
	trace("locate_strict_alterative()\n");
	return( locate_alternative_method( original->name, original->hash, member ) );
}


VOID	resolve_strict_alternatives( TCSTRUCTPTR sptr )
{
	WORD		number=0;
	TCMEMBERPTR	member;
	TCMBMETHPTR	method;

	return;
/*
	if (!( sptr ))
		return;
	for (	member =  sptr->first;
		member != (TCMEMBERPTR) 0;
		member =  member->next) {
		switch (member->nature) {
			case	_CLASS_FUNCTION	:
			case	_CLASS_OVERLAY	:
				if (!(method = (TCMBMETHPTR) member->special))
					break;
				else	method->alternative = ++number;

			}
		}
 */
}



WORD		strict_elimination( paraflag, parameters, member )
WORD		paraflag;
TCMBPARAPTR	parameters;
TCMEMBERPTR	member;
{
	if ( paraflag )
		liberate_method_parameters( parameters );

	if ( member != (TCMEMBERPTR) 0 )
		strcpy( TokenBuffer, member->name );
	else	cancel_token_buffer();

	issue_warning(7);

	return( MOINS_UN );
}

WORD	activate_method( object, member, method, parameters, mode, option )
TCVARPTR	object;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
TCMBPARAPTR	parameters;
WORD		mode;
WORD		option;
{
	TCMEMBERPTR	original=member;
	TCVARPTR	variables;
	WORD		paraflag=0;

	trace("activate_method()\n");

	if (!( method->options & _METHOD_STRICT )) 
	 	return( ll_activate_method( object, member, method, parameters, mode, option ) );

	if (( parameters == (TCMBPARAPTR) 0 )
	&&  (( parameters = collect_strict_parameters()) != (TCMBPARAPTR) 0))
		paraflag = 1;

	if (!( member )) {
		/* do this now : implicite preconstruction/postdestruction if no member */
		/* -------------------------------------------------------------------- */
	 	return( ll_activate_method( object, member, method, parameters, mode, option ) );
		}

	while ( 1 ) {

		variables = explicite_method_parameters( method );

		if ( verify_strict_parameters( variables, parameters ) )
		 	return( ll_activate_method( object, member, method, parameters, mode, option ) );

		/* Construction Mode : No Locate Alterative */
		/* ---------------------------------------- */
		if ( mode )
			return( strict_elimination( paraflag, parameters, original ) );
		else if ((member = locate_strict_alternative( original, member->next )) == (TCMEMBERPTR) 0)
			break;
		else if ((method = (TCMBMETHPTR) member->special) == (TCMBMETHPTR) 0)
			break;


		}

	return( strict_elimination( paraflag, parameters, original ) );

}

WORD	activate_object_method( object, member, option )
TCVARPTR	object;
TCMEMBERPTR	member;
WORD		option;
{
	TCMBMETHPTR	method;
	WORD		status;

	trace("activate_object_method("); 
	trace( object->name ); trace("."); trace( member->name );
	trace(")\n");

	if ((method = (TCMBMETHPTR) member->special) == (TCMBMETHPTR) 0)
		return( internal_error( 767 ) );
	else if ((status = activate_method( object, member, method, (TCMBPARAPTR) 0, 0, option )) != MOINS_UN)
		return( status );
	else	return( 0 );
}

RESULTPTR	evaluate_inline_macro( object, member, method )
TCVARPTR	object;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
{
	WORD	status;
	if ((status = activate_inline_method( object, member, method, (TCMBPARAPTR) 0, 0 )) != 0)
		return( (RESULTPTR) 0 );
	else	return( evaluate_expression(0) );
}

WORD		expand_method_token( object, member, method )
TCVARPTR	object;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
{
	if (( method != (TCMBMETHPTR) 0)
	&&  ( method->nature == _CLASS_INLINE )
	&&  ( method->options & _METHOD_MACRO )
	&&  ( activate_inline_method( object, member, method, (TCMBPARAPTR) 0, 0 ) == 0))
		return( VRAI );
	else	return( FAUX );
}

RESULTPTR	evaluate_method_term( object, member, method, mode )
TCVARPTR	object;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
WORD		mode;
{
	WORD		status;
	TCVARPTR	procptr;

	trace("evaluate_method_term()\n");

	if ( method == (TCMBMETHPTR) 0) {
		(void) internal_error( 768 );
		return( (RESULTPTR) 0 );
		}

	if ( method->type != (TCTYPPTR) 0 ) {

		if ((use_dimensions()) 
		||  (!(method->options & _METHOD_ISPOINTER))) {

			if ( method->nature == _CLASS_USER )
				return( evaluate_user_method(object, member, method, (TCMBPARAPTR) 0, 0, mode ) );
			else if ((status = activate_method( object, member, method, (TCMBPARAPTR) 0, 0, mode )) != 0)
				return( (RESULTPTR) 0 );
			else	return( procedure_result( method->type ) );
			}

		}

	if (( method->options & _METHOD_MACRO )
	&&  ( method->nature == _CLASS_INLINE ))
		return( evaluate_inline_macro( object, member, method ) );

	else if ( is_method_pointer( method ) ) {
		if ((procptr = resolve_member_componant( object, member )) == (TCVARPTR) 0) {
			(void) internal_error( 22001 );
			return((RESULTPTR) 0);
			}
		if (( method->options & _METHOD_STRICT )
		&&  ((procptr = resolve_method_pointer( procptr, method )) == (TCVARPTR) 0)) {
			(void) internal_error( 22002 );
			return((RESULTPTR) 0);
			}
		else	return( variable_result( procptr ) );
		}
	else	{
		(void) syntax_error(863);
		return( (RESULTPTR) 0);
		}
}

RESULTPTR	evaluate_method_operator( object, class, member, rterm )
TCVARPTR	object;
TCSTRUCTPTR	class;
TCMEMBERPTR	member;
RESULTPTR	rterm;
{
	TCMBMETHPTR	method;
	TCMBPARAPTR	parameters;
	TCVARPTR	pptr;
	WORD		status;

	trace("evaluate_method_operator(");
	trace( object->name );
	trace( "." );
	trace( member->name );
	trace("\n");

	if ((method = (TCMBMETHPTR) member->special) == (TCMBMETHPTR) 0) {
		(void) internal_error( 767 );
		return( (RESULTPTR) 0 );
		}

	pptr = explicite_method_parameters( method );

	if ((parameters = build_operation_parameters( pptr, rterm )) == (TCMBPARAPTR) 0) {
		(void) syntax_error(864);
		return( (RESULTPTR) 0 );
		}

	else if ((status = activate_method( object, member, method, parameters, 0, 1 )) != 0)
		return( (RESULTPTR) 0 );

	else if ( method->type == (TCTYPPTR) 0 ) {
		(void) syntax_error(865);
		return( (RESULTPTR) 0);
		}
	else	return( procedure_result( method->type ) );


}

WORD		method_affectation( object, class, member, rterm )
TCVARPTR	object;
TCSTRUCTPTR	class;
TCMEMBERPTR	member;
RESULTPTR	rterm;
{
	TCMBMETHPTR	method;
	TCMBPARAPTR	parameters;
	TCVARPTR	pptr;

	trace("method_affectation(");
	trace( object->name );
	trace( "." );
	trace( member->name );
	trace("\n");

	if ((method = (TCMBMETHPTR) member->special) == (TCMBMETHPTR) 0)
		return(internal_error( 767 ));

	pptr = explicite_method_parameters( method );

	if ((parameters = build_operation_parameters( pptr, rterm )) == (TCMBPARAPTR) 0)
		return(syntax_error(866));

	else 	return( activate_method( object, member, method, parameters, 0, 1 ) );

}

WORD	is_inline_function()
{
	TCMBMETHPTR	method;
	if (((method = (TCMBMETHPTR)input_method()) != (TCMBMETHPTR) 0)
	&&  (method->nature == _CLASS_INLINE)
	&&  (method->type   != (TCTYPPTR) 0 ))
		return( 1 );
	else	return(0);
}

WORD	is_method_function()
{
	TCMBMETHPTR	method;
	if (((method = (TCMBMETHPTR)input_method()) != (TCMBMETHPTR) 0)
	&&  (method->nature == _CLASS_FUNCTION)
	&&  (method->type   != (TCTYPPTR) 0 ))
		return( 1 );
	else	return(0);
}

WORD	translate_inline_exit()
{
	RESULTPTR	rptr;
	TCMBMETHPTR	method;
	TCTYPPTR	tptr;
	TCVARPTR	HoldVar=(TCVARPTR) 0;


	if (((method = (TCMBMETHPTR)input_method()) != (TCMBMETHPTR) 0)
	&&  ( method->nature           == _CLASS_INLINE  )
	&&  ((tptr = method->type)     != (TCTYPPTR) 0   )) {
		if ((tptr->type & _TYPE_POINTER) == _TYPE_POINTER) {
			HoldVar = Context->TargetVariable;
			Context->TargetVariable = (TCVARPTR) 0;
			}
		if (( is_left_brace() ) 
		&&  (( rptr = evaluate_expression(0)) != (RESULTPTR) 0)
		&&  ( is_right_brace() )) {
			if ((tptr->type & _TYPE_POINTER) != _TYPE_POINTER) {
				if (( rptr = ensure_register( rptr )) == (RESULTPTR) 0)
					return( allocation_failure() );
				}
			else if ((rptr = clf_reg_alias( rptr )) == (RESULTPTR) 0)
				return( syntax_error(867) );

			if ( generate_copy_register( _EXIT_REGISTER, rptr->value ) != 0 )
				return( syntax_error(868) );
			}

		if ((tptr->type & _TYPE_POINTER) != _TYPE_POINTER)
			Context->TargetVariable = HoldVar;
		
		return( goto_input_label() );
		}
	else	return( syntax_error(869) );
}


#include "trauto.c"

WORD	declare_module_method( object, class, member, method )
TCVARPTR	object;
TCSTRUCTPTR	class;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
{
	WORD	field;
	switch ( method->nature ) {
		case	_CLASS_FUNCTION	:
			if ( build_function_method( member->class, member, method, 1 ) == (TCMBFUNCPTR) 0)
				return( allocation_failure() );
			else	return( 0 );
		case	_CLASS_OVERLAY  :
			field = detect_memory_field( object );
			if ( build_overlay_method( object, member->class, member, field ) == (TCMBOVLPTR) 0)
				return( allocation_failure() );
			else	return( 0 );
		}
	return( 0 );
}

WORD	declare_module_methods( object, class )
TCVARPTR	object;
TCSTRUCTPTR	class;
{
	TCMEMBERPTR	member;
	TCMBMETHPTR	method;
	WORD		status;
	if ((member = class->first) != (TCMEMBERPTR) 0) {
		do	{
			if ((!( member->nature ))
			&&  ((method = (TCMBMETHPTR) member->special) != (TCMBMETHPTR) 0)
			&&  ((status = declare_module_method( object, class, member, method )) != 0))
				return( status );
			}
		while ((member = member->next) != (TCMEMBERPTR) 0);
		}
	return( 0 );
}

WORD	inherit_dynamic_method( method, oldclass, newclass )
TCMBMETHPTR	method;
TCSTRUCTPTR	oldclass;
TCSTRUCTPTR	newclass;
{
	TCVARPTR	vptr;
	WORD		status;
	GENERICPTR	gptr;
	GENERICPTR	xptr;

	if (method != (TCMBMETHPTR) 0) {
		if ((status = inherit_dynamic_type( method->type, oldclass, newclass )) != 0)
			return( status );
		if ((vptr = explicite_method_parameters( method )) != (TCVARPTR) 0) {
			do	{
				if ((status = inherit_dynamic_type( vptr->type, oldclass, newclass )) != 0)
					return( status );
				}
			while ((vptr = vptr->next) != (TCVARPTR) 0);
			}
		if ((gptr = allocate_for_genericity( oldclass, newclass )) == (GENERICPTR) 0)
			return( allocation_failure() );
		else	{
			if (( xptr = method->generic ) == (GENERICPTR) 0)
				method->generic = gptr;
			else	{
				while ( xptr->next != (GENERICPTR) 0)
					xptr = xptr->next;
				xptr->next = gptr;
				}
			}
		}
	return( 0 );
}

WORD		event_call_method( object, class, member, method )
TCVARPTR	object;
TCSTRUCTPTR	class;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
{
	WORD		status;
	WORD		after;
	WORD		before;
	WORD		modecall=0;
	TCMBGSBPTR	routine=(TCMBGSBPTR) 0;
	TCVARPTR	container=(TCVARPTR) 0;
	TCVARPTR	procptr=(TCVARPTR) 0;
	TCMBFUNCPTR	function=(TCMBFUNCPTR) 0;

	switch ( method->nature ) {

		case	_CLASS_INLINE	:
			if ( method->parameters != (TCVARPTR) 0 )
				return( syntax_error( 1194 ) );
			else if ( method->type != (TCTYPPTR) 0 )
				return( syntax_error( 1195 ) );

			before = new_implicite_label();
			after  = new_implicite_label();

			if ((status = generate_extern_event( 0,0 )) != 0)
				return( status );
			implicite_label( before );
			implicite_goto( after );
			dcl_implicite_label( before );
			status = activate_inline_method( object, member, method, (TCMBPARAPTR) 0, 0 );
			dcl_implicite_label( after );
			return( status );

		case	_CLASS_ROUTINE	:

			while ( object->parent != (TCVARPTR) 0 )
				object = object->parent;

			if ((routine = resolve_routine_method(object,member)) == (TCMBGSBPTR) 0)
				return( allocation_failure() );
			if ((status = generate_extern_event( 1,0 )) != 0)
				return( status );
			implicite_label( routine->label );
			return( 0 );

		case	_CLASS_FUNCTION	:
			if ((status = resolve_method_context( object, member, & class, & container )) != 0)
				return( status );

			while ( object->parent != (TCVARPTR) 0 )
				object = object->parent;

#ifdef	_BEFORE_19121996
#else
			if ( method->options & _METHOD_CALLBACK )
				modecall = 1;
#endif
			if ( method->options & _METHOD_INDIRECT )  {
				if ((status = locate_method_pointer( object, method, & container, & procptr , member )) != 0)
					return( status );
#ifdef	_BEFORE_19121996
				else	return( event_call_variable( procptr ) );
#else
				else	return( event_call_variable( procptr, modecall ) );
#endif
				}
			else if ((function = locate_function_method( class, member, method->parameters )) == (TCMBFUNCPTR) 0)
				if ((function = build_function_method( class, member, method, 0 )) == (TCMBFUNCPTR) 0)
					return( allocation_failure() );

#ifdef	_BEFORE_19121996
			return( event_call_procedure( function->procedure ) );
#else
			return( event_call_procedure( function->procedure, modecall ) );
#endif
		case	_CLASS_OVERLAY	:
		case	_CLASS_USER   	:
			return( syntax_error(198) );

		}

	return( 0 );
}

#endif	/* _TRMETHOD_C */
	/* ----------- */



