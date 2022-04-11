/* #define	DEBUG */
/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRSTRUCT.C				*/
/*		Version :	2.1d					*/
/*		Date	:	23/02/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRSTRUCT_C
#define	_TRSTRUCT_C

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
#include "trtree.h"
#include "trmethod.h"
#include "trmember.h"
#include "trcommon.h"
#include "trinput.h"
#include "trdebug.h"
#include "trclass.h"
#include "trshadow.h"
#include "trabal.h"
#include "trclf.h"
#include "trproc.h"
#include "triof.h"
#include "troutput.h"

#ifndef	UNIX
static	TCFRIENDPTR	allocate_for_friend( BPTR );
static	WORD	declare_member( TCSTRUCTPTR, TCMEMBERPTR, WORD, WORD, WORD );
static	WORD	member_occupation( TCMEMBERPTR );
static	WORD	ll_structure_occupation( TCSTRUCTPTR, TCMEMBERPTR );
static	WORD	declare_member_construction( TCVARPTR, TCMEMBERPTR, TCSTRUCTPTR, TCTEXTPTR, WORD );
static	WORD	declare_object_construction( TCVARPTR, TCVARPTR, TCSTRUCTPTR, TCMEMBERPTR, TCTEXTPTR, WORD, WORD );
static	WORD	indirect_method_count( TCSTRUCTPTR, TCMEMBERPTR, WORD );
static	WORD	eimt_base( TCSTRUCTPTR, WORD, WORD );
static	WORD	declare_eimt_vectors( TCSTRUCTPTR , WORD, WORD );
static	WORD	declare_eimt( TCSTRUCTPTR , WORD, WORD );
static	WORD	declare_enhanced_overlay( TCSTRUCTPTR , BPTR, WORD, WORD );
static	WORD	declare_standard_overlay( TCSTRUCTPTR , BPTR, WORD, WORD );
static	WORD	declare_indirect_object( TCSTRUCTPTR , BPTR, WORD, WORD );
static	WORD	redefine_overlay_object( TCSTRUCTPTR , BPTR, WORD, WORD );
static	WORD	declare_overlay_object( TCSTRUCTPTR , BPTR, WORD );
static	WORD	declare_static_inheritance( TCSTRUCTPTR, WORD );
static	WORD	ll_declare_structure( TCSTRUCTPTR, TCMEMBERPTR, BPTR, WORD, WORD, WORD, TCTEXTPTR, WORD );
static	WORD	class_specialisation( TCSTRUCTPTR, TCMEMBERPTR );
static	WORD	new_class_number();
static	WORD	is_strict_member( TCMEMBERPTR );
static	VOID	detect_external_member( TCSTRUCTPTR, TCMEMBERPTR );
static	WORD	inherit_dynamic_member( TCMEMBERPTR, TCSTRUCTPTR );
static	WORD	overload_member( TCSTRUCTPTR, TCMEMBERPTR );
static	WORD	overload_members( TCSTRUCTPTR, TCSTRUCTPTR );
static	WORD	expand_sizeof();
static	RESULTPTR	evaluate_alias_operator( BPTR, RESULTPTR, RESULTPTR );

#else
WORD		expand_class_constant();
TCVARPTR	dcl_object_alias();
TCTYPPTR	register_alias();
TCVARPTR	register_variable();
TCVARPTR	is_local_variable();
TCSTRUCTPTR	base_class_componant();
TCMEMBERPTR	resolve_method_member();
TCMEMBERPTR	locate_alternative_method();
WORD		class_tree_node();
TCMEMBERPTR	locate_strict_alternative();
RESULTPTR	build_string_constant();
RESULTPTR	build_numeric_term();
RESULTPTR	allocate_for_result();
TCVARPTR	temp_variable();
TCTEXTPTR	collect_construction_parameters();
WORD		translate_object_member();
static WORD	ll_declare_structure();
static WORD	ll_structure_occupation();
static WORD	declare_object_construction();
#endif

EXTERN	TCVARPTR	OverloadHost;

static	WORD	ExpliciteUnion=0;
static	WORD	WorldAnnounce=0;

WORD	set_world_announce()
{
	WorldAnnounce = 1;
	return(0);
}

WORD	translate_extern_keyword()
{
	Context->Visibility |= _MEMBER_EXTERN;
	return(0);
}

WORD	translate_overlay_keyword()
{
	Context->Visibility |= _MEMBER_OVERLAY;
	return(0);
}

WORD	translate_ocx_keyword()
{
	Context->Visibility |= _MEMBER_OCX;
	return(0);
}

VOID	cancel_extern_overlay()
{
	Context->Visibility &= ~_MEMBER_OVERLAY;
	Context->Visibility &= ~_MEMBER_EXTERN;
	Context->Visibility &= ~_MEMBER_OCX;
	return;
}

WORD	translate_protect()
{
	Context->Visibility |= _MEMBER_PROTECT;
	return(0);
}

WORD	translate_local_keyword()
{
	Context->Visibility |= _MEMBER_LOCAL;
	return(0);
}

WORD	translate_overload()
{
	Context->Visibility |= _MEMBER_OVERLOAD;
	return(0);
}

WORD	translate_static_keyword()
{
	trace("translate_static_keyword()\n");
	Context->Visibility &= ~_MEMBER_DYNAMIC;
	return(0);
}

WORD	translate_dynamic_keyword()
{
	Context->Visibility |= _MEMBER_DYNAMIC;
	return(0);
}


WORD	translate_virtual()
{
	Context->Visibility |= _MEMBER_VIRTUAL;
	return(0);
}

WORD	translate_generic()
{
	Context->Visibility |= _MEMBER_GENERIC;
	return(0);
}

WORD	translate_private()
{
	if ( Context->Visibility & _MEMBER_PROTECT )
		return( syntax_error( 1004 ) );
	else if ( Context->Visibility & _MEMBER_COMMON )
		return( syntax_error( 1006 ) );
	else	{
		Context->Visibility &= _MEMBER_SPECIAL;
		Context->Visibility |= _MEMBER_PRIVATE;
		return(0);
		}
}

WORD	translate_public()
{
	if ( Context->Visibility & _MEMBER_PROTECT )
		return( syntax_error( 1004 ) );
	else if ( Context->Visibility & _MEMBER_COMMON )
		return( syntax_error( 1006 ) );
	else	{
		Context->Visibility &= _MEMBER_SPECIAL;
		Context->Visibility |= _MEMBER_PUBLIC;
		return(0);
		}
}

VOID	liberate_structure_data( dptr )
TCMBDATAPTR	dptr;
{
	if ( dptr != (TCMBDATAPTR) 0 ) {
		trace("liberate_structure_data()\n");
		if ( dptr->type != (TCTYPPTR) 0 )
			liberate_for_type( dptr->type );
		if ( dptr->structname != (BPTR) 0)
			liberate( dptr->structname );
		if ( dptr->construction != (TCTEXTPTR) 0 )
			liberate_text_value( dptr->construction );
		liberate( dptr );
		}
	return;
}

VOID	liberate_structure_const( cptr )
TCMBCONSTPTR	cptr;
{
	if ( cptr != (TCMBCONSTPTR) 0) {
		trace("liberate_structure_const()\n");
		if ( cptr->value != (BPTR) 0 )
			liberate( cptr->value );
		if ( cptr->type != (TCTYPPTR) 0)
			liberate_for_type( cptr->type );
		liberate( cptr );
		}
	return;
}

VOID	liberate_structure_member( mptr )
TCMEMBERPTR	mptr;
{
	if ( mptr != (TCMEMBERPTR) 0 ) {
		trace("liberate_structure_member(");
		if ( mptr->name != (BPTR) 0 ) {
			trace( mptr->name );
			liberate( mptr->name );
			}
		trace(")\n");
		if ( mptr->special != (VPTR) 0 ) {
			switch ( mptr->nature ) {
				case _KW1_IND   :
				case _KW1_CMN   :
				case _KW1_OBJ   :
				case _KW1_OVL   :
				case _KW1_DCL	:
				case _KW1_PTR   :
				case _KW1_ARG   :
					liberate_structure_data( mptr->special );
					break;
				case _KW1_CONST :
					liberate_structure_const( mptr->special );
					break;
				default		: 
					liberate_structure_method( mptr->special );
					break;
				}
			}
		liberate( mptr );
		}	
	return;
}

VOID	liberate_friends( fptr )
TCFRIENDPTR	fptr;
{
	TCFRIENDPTR	xptr;
	while ((xptr = fptr) != (TCFRIENDPTR) 0) {
		trace("liberate_friend()\n");
		fptr = fptr->next;
		if ( xptr->name != (BPTR) 0 )
			liberate( xptr->name );
		liberate( xptr );
		}
	return;
}

VOID	liberate_for_structure( sptr )
TCSTRUCTPTR	sptr;
{
	TCMEMBERPTR	mptr;
	if ( sptr != (TCSTRUCTPTR) 0 ) {

		if ( sptr->friend != (TCFRIENDPTR) 0 )
			liberate_friends( sptr->friend );

		while ((mptr = sptr->first) != (TCMEMBERPTR) 0) {
			sptr->first = mptr->next;
			liberate_structure_member( mptr );
			}

		if ( sptr->name != (BPTR) 0 )
			liberate( sptr->name );

		if ( sptr->source != (BPTR) 0)
			liberate( sptr->source );

		if ( sptr->module != (BPTR) 0)
			liberate( sptr->module );

		liberate( sptr );
		}
	return;
}

TCMBDATAPTR	allocate_structure_data()
{
	TCMBDATAPTR	dptr;
	trace("allocate_structure_data(");
	if ((dptr = (TCMBDATAPTR) allocate( sizeof( struct tcode_structure_data ) )) != (TCMBDATAPTR) 0) {
		dptr->structname = (BPTR) 0;
		dptr->structure  = (TCSTRUCTPTR) 0;
		dptr->type       = (TCTYPPTR) 0;
		dptr->construction = (TCTEXTPTR) 0;
		dptr->field	 = 0;
		}
	return( dptr );
}

TCMBCONSTPTR	allocate_structure_const(value,type)
BPTR		value;
TCTYPPTR	type;
{
	TCMBCONSTPTR	dptr;

	trace("allocate_structure_const(");
	if ((dptr = (TCMBCONSTPTR) allocate( sizeof( struct tcode_structure_const ) )) != (TCMBCONSTPTR) 0) {
		dptr->value = (BPTR) 0;
		dptr->type  = type;
		if (( dptr->value = allocate_for_string( value )) != (BPTR) 0)
			return( dptr );
		else	liberate_for_type( dptr->type );
		liberate( dptr );
		dptr = (TCMBCONSTPTR) 0;
		}
	return( dptr );
}

TCMEMBERPTR	allocate_structure_member( nptr )
BPTR		nptr;
{
	TCMEMBERPTR	mptr;
	trace("allocate_structure_member(");
	if ((mptr = (TCMEMBERPTR) allocate( sizeof( struct tcode_structure_member ) )) != (TCMEMBERPTR) 0) {
		if ((mptr->name = allocate_for_string( nptr )) != (BPTR) 0) {
			mptr->hash       = keyword_hash( nptr );
			mptr->access     = Context->Visibility;
			mptr->lock	 = 0;
			mptr->size       = 0;
			mptr->nature     = 0;
			mptr->common	 = (TCVARPTR) 0;
			mptr->class	 = World->CurrentStructure;
			mptr->special	 = (VPTR) 0;
			mptr->next       = (TCMEMBERPTR) 0;
			mptr->prev       = (TCMEMBERPTR) 0;
			return( mptr );
			}
		liberate( mptr );
		}
	return((TCMEMBERPTR) 0);
}

WORD	copy_structure_data( nptr, mptr )
TCMEMBERPTR	nptr;
TCMEMBERPTR	mptr;
{
	TCMBDATAPTR	xdptr;
	TCMBDATAPTR	dptr;
	if (((xdptr = (TCMBDATAPTR) mptr->special) != (TCMBDATAPTR) 0)
	&&  ((dptr = allocate_structure_data()) != (TCMBDATAPTR) 0)) {
		nptr->special = (VPTR)dptr;
		if (xdptr->structname != (BPTR) 0)
			dptr->structname = allocate_for_string( xdptr->structname );
		else	dptr->structname = (BPTR) 0;
		if (xdptr->type != (TCTYPPTR) 0)
			dptr->type      = copy_type(xdptr->type);
		else	dptr->type	= (TCTYPPTR) 0;
		dptr->structure    = xdptr->structure;
		dptr->construction = copy_text_value( xdptr->construction );
		if ( dptr->construction != (TCTEXTPTR) 0 )
			trace("copy_instance_construction()\n");
		dptr->field	   = xdptr->field;
		return( 0 );
		}
	else	return(allocation_failure());
}

WORD	copy_structure_const(  nptr, mptr )
TCMEMBERPTR	nptr;
TCMEMBERPTR	mptr;
{
	TCMBCONSTPTR	xdptr;
	TCMBCONSTPTR	dptr;
	TCTYPPTR	tptr;

	if (((xdptr = (TCMBCONSTPTR) mptr->special) != (TCMBCONSTPTR) 0)
	&&  ((tptr  = allocate_for_type(xdptr->type->type,strlen(xdptr->value),1,1,(VPTR) 0)) != (TCTYPPTR) 0)
	&&  ((dptr  = allocate_structure_const(xdptr->value,tptr)) != (TCMBCONSTPTR) 0)) {
		nptr->special = (VPTR)dptr;
		return(0);
		}
	else	return( allocation_failure() );
}

TCMEMBERPTR		copy_member( mptr )
TCMEMBERPTR		mptr;
{
	WORD		status;
	TCMEMBERPTR	nptr=(TCMEMBERPTR) 0;
	if ((nptr = allocate_structure_member(mptr->name)) != (TCMEMBERPTR) 0) {
		switch ((nptr->nature = mptr->nature)) {
			case _KW1_IND	:
			case _KW1_CMN   :
			case _KW1_OBJ   :
			case _KW1_DCL	:
			case _KW1_PTR   :
			case _KW1_OVL   :
			case _KW1_ARG   :
				if ((status = copy_structure_data( nptr, mptr )) != 0)
					return((TCMEMBERPTR) 0);
				else	break;
			case _KW1_CONST :
				if ((status = copy_structure_const( nptr, mptr )) != 0)
					return((TCMEMBERPTR) 0);
				else	break;
			default		:
				if ((status = copy_structure_method( nptr, mptr )) != 0)
					return((TCMEMBERPTR) 0);
				else	break;
			}
		nptr->common	 = mptr->common;
		nptr->class	 = mptr->class;
		nptr->size       = mptr->size;
		nptr->access     = mptr->access;
		nptr->next       = (TCMEMBERPTR) 0;
		nptr->prev       = (TCMEMBERPTR) 0;
		}
	return( nptr );
}

static TCFRIENDPTR	allocate_for_friend( name )
BPTR		name;
{
	TCFRIENDPTR	fptr;

	trace("allocate_for_friend(");
	if ((fptr = (TCFRIENDPTR) allocate( sizeof ( struct tcode_friend ) )) != (TCFRIENDPTR) 0) {
		fptr->next = (TCFRIENDPTR) 0;
		if ((fptr->name = allocate_for_string( name )) == (BPTR) 0) {
			liberate( fptr );
			fptr = (TCFRIENDPTR) 0;
			}
		}
	return( fptr );
}

TCSTRUCTPTR	allocate_for_structure( nptr )
BPTR		nptr;
{
	TCSTRUCTPTR	sptr;
	trace("allocate_for_structure(");
	if ((sptr = (TCSTRUCTPTR) allocate( sizeof( struct tcode_structure ) )) != (TCSTRUCTPTR) 0) {
		if ((sptr->name = allocate_for_string( nptr )) != (BPTR) 0) {
			sptr->hash       = keyword_hash( nptr );
			sptr->number	 = 0;
			sptr->scope	 = World->Scope;
			sptr->enhanced	 = OtrOption.Enhanced;
			sptr->announce	 = WorldAnnounce;
			WorldAnnounce    = 0;
			sptr->virtual	 = get_world_virtual();
			sptr->dll	 = (TCDLBPTR) 0;
			sptr->first      = (TCMEMBERPTR) 0;
			sptr->last       = (TCMEMBERPTR) 0;
			sptr->friend	 = (TCFRIENDPTR) 0;
			sptr->commonroot = (TCVARPTR) 0;
			sptr->commonlock = 0;
			sptr->lock	 = 0;
			sptr->access     = (Context->Visibility | _MEMBER_DYNAMIC);
			sptr->size       = 0;
			sptr->explicite  = 0;
			sptr->nature     = 0;
			sptr->source	 = (BPTR) 0;
			sptr->module	 = (BPTR) 0;
			sptr->next       = (TCSTRUCTPTR) 0;
			sptr->previous   = (TCSTRUCTPTR) 0;
			return( sptr );
			}
		liberate( sptr );
		}
	return((TCSTRUCTPTR) 0);
}

TCSTRUCTPTR	locate_structure( nptr )
BPTR		nptr;
{
	WORD		h;
	TCSTRUCTPTR	sptr;
	h = keyword_hash( nptr );
	if ((sptr = World->CurrentStructure) != (TCSTRUCTPTR) 0) {
		do	{
			if (( h == sptr->hash )
			&&  ( compare_tokens(sptr->name, nptr) ))
				break;
			}
		while ((sptr = sptr->next) != (TCSTRUCTPTR) 0);
		}
	return( sptr );
}

#include "trtree.c"

static	LONG	KnownClassCall=0L;
static	LONG	KnownClassFail=0L;

VOID	kc_statistics()
{
	sysprintf("known_class() calls : %lu \n",KnownClassCall);
	sysprintf("known_class() calls : %lu \n",KnownClassFail);
	return;
}

TCSTRUCTPTR	known_structure( nptr )
BPTR		nptr;
{
	TCSTRUCTPTR	xptr;
	trace("known_structure()\n");
	KnownClassCall++;
	if ((xptr = is_known_structure( nptr )) != (TCSTRUCTPTR) 0)
		return( xptr );
	else if ((xptr = locate_structure( nptr )) != (TCSTRUCTPTR) 0)
		return( xptr );
	KnownClassFail++;
	return( (TCSTRUCTPTR) 0);
}

TCMEMBERPTR	locate_member( sptr, nptr )
TCSTRUCTPTR	sptr;
BPTR		nptr;
{
	TCMEMBERPTR	mptr=(TCMEMBERPTR) 0;
	WORD		h;

	if (( sptr != (TCSTRUCTPTR) 0)
	&&  ((mptr = sptr->first) != (TCMEMBERPTR) 0)) {
		trace("locate_member("); trace( nptr ); trace(" in ");
		trace( sptr->name ); trace(")\n");
		h = keyword_hash( nptr );
		do	{
			if (( h == mptr->hash )
			&&  ( compare_tokens( mptr->name, nptr ) ))
				break;
			}
		while (( mptr = mptr->next ) != (TCMEMBERPTR) 0);
		}
	return( mptr );
}

static	TCVARPTR	resolve_new_variable( variable )
	TCVARPTR	variable;
{
	if ( variable == (TCVARPTR) 0 ) {
		if (!( Context->CurrentXFT )) 	
			return( Context->GDT->first );
		else	return( Context->XDT->first );
		}
	else	return( variable->prev );
}

static	TCVARPTR	extern_or_global()
{
	if ( Context->CurrentXFT )
		return( Context->XDT->variable );
	else	return( Context->GDT->variable );
}

static	TCVARPTR	local_extern_global()
{
	if ( Context->CurrentXFT )
		return( Context->XDT->variable );
	else if ( Context->scope & ISLOCAL)
		return( Context->LDT->variable );
	else	return( Context->GDT->variable );
}

WORD	dcl_method_pointer( member, level, master, occupation, hostclass )
TCMEMBERPTR	member;
WORD		level;
WORD		master;
WORD		occupation;
TCSTRUCTPTR	hostclass;
{
	WORD		status;
	TCVARPTR	variable;

	if ( member == (TCMEMBERPTR) 0 )
		return( 0 );

	trace("dcl_method_pointer("); trace(member->name); trace(")\n");

	if ( member->access & _MEMBER_COMMON ) {
		if (method_occupation( member, member->special ) == 0)
			return( 0 );
		}
	else	{		
		if ((  member->size == 0 )
		&&  (!(member->access & _MEMBER_OVERLOAD)))
			return( 0 );
		else if ( is_overlay_indirect( member->special ) )
			return( 0 );

		}


	/* Detect Base Indirect Method Overloading */
	/* --------------------------------------- */
	if (  member->access & _MEMBER_OVERLOAD ) {
		if ((status = base_member_field( master, member, member->special )) != 0)
			return( status );
		else if ( member->access & _MEMBER_COMMON ) {
			field_equals_r(); 
			return( 0 );
			}
		}

	trace("dcl_variable("); trace( member->name ); trace(")\n");

	status = dcl_variable(
			 	member->name,		/* Variable name */
				3,			/* Data type	 */
				5,			/* Data length	 */
				1,			/* 1st dimension */
				1,			/* 2nd dimension */
				_KW1_DCL,		/* DCL type	 */
				0,			/* Already typed */
				level, master );	/* Symbol Flag   */

	if (( status == 0 ) && ( member->access & (_MEMBER_OVERLOAD | _MEMBER_VIRTUAL) )) {

		variable = local_extern_global();

		if (( variable != (TCVARPTR) 0)
		&&  ( variable->type != (TCTYPPTR) 0)) {
			variable->type->class = (VPTR) member->special;
			if ( member->access & _MEMBER_OVERLOAD )
				variable->overloads = OverloadHost;
			}

		if (!( occupation ))
			occupation++;

		if ((status = dcl_variable(
			 	member->name,		/* Variable name */
				(3 | _TYPE_DEFINED),	/* Data type	 */
				occupation,		/* Data length	 */
				1,			/* 1st dimension */
				1,			/* 2nd dimension */
				_KW1_PTR,		/* Parent Object */
				0,			/* Already typed */
				(level+1), master )) == 0) { 	/* Symbol Flag   */

			variable = local_extern_global();

			if  ( variable != (TCVARPTR) 0) {
				variable->type->class = (VPTR) hostclass;
				if (( member->access & _MEMBER_OVERLOAD )
				&&  ( OverloadHost != (TCVARPTR) 0))
					variable->overloads = OverloadHost->prev;
				}
			}
		}

	/* Restore Current Field if Base Overload */
	/* -------------------------------------- */
	if ( member->access & _MEMBER_OVERLOAD ) {
		field_equals_r();
		OverloadHost = (TCVARPTR) 0;
		}

	if ( status )
		return( status );

	trace(" fixup class / method id (2) \n");

	variable = local_extern_global();

	if (( variable != (TCVARPTR) 0)
	&&  ( variable->type != (TCTYPPTR) 0)
	&&  (!(variable->type->type & _TYPE_DEFINED)))
		variable->type->class = (VPTR) member->special;

	return( 0 );

}

static WORD		declare_member( class,mptr, level, master, occupation )
TCSTRUCTPTR	class;
TCMEMBERPTR	mptr;
WORD		level;
WORD		master;
WORD		occupation;
{
	TCMEMBERPTR		common;
	WORD			hold_access;
	WORD			status;
	TCVARPTR		variable=(TCVARPTR) 0;
	TCMBDATAPTR		dptr;
	struct tcode_field 	HoldField;
	WORD			mastermode;

	trace("declare_member("); trace( mptr->name ); trace(")\n");

	/* Eliminate Constant Members */
	/* -------------------------- */
	if ( mptr->nature == _KW1_CONST )
		return( 0 );

	/* ------------------------------ */
	/* Detect Common Member Variables */
	/* ------------------------------ */
	else if (( mptr->access & _MEMBER_COMMON )
	     && (!( mptr->lock & _MEMBER_LOCKED ))) {
		if ( mptr->common != (TCVARPTR) 0 )
			return( 0 );
		else if (((common = locate_common_member( mptr->class,mptr )) == (TCMEMBERPTR) 0)
		     &&  ((common = add_common_member( mptr->class, mptr ))   == (TCMEMBERPTR) 0))
			return( allocation_failure() );
		else if ((mptr->common = common->common) != (TCVARPTR) 0)
			return( 0 );
		else	{
			copy_field( & HoldField, Context->ThisField );
			if ((mastermode = ( Context->scope & ISLOCAL)))
				field_equals_g();
			else	field_equals_r();
			variable = extern_or_global();
			}
		}

	/* Eliminate Non-data members */
	/* -------------------------- */
	if (!( mptr->nature ))

		/* ------------------------------------------------ */
		/* !  Members which are METHOD POINTERS have size ! */
		/* ------------------------------------------------ */
		/* Declare Variable without Symbol unicity checking */
		/* ------------------------------------------------ */
		status = dcl_method_pointer( mptr, level, master, occupation, class );

	else	{

		dptr = (TCMBDATAPTR) mptr->special;

		/* Establish Public / Private Atribut for Member */
		/* --------------------------------------------- */
		hold_access = Context->Visibility; 
		Context->Visibility = mptr->access;

		if ( level )
			/* Declare Variable without Symbol unicity checking */
			/* ------------------------------------------------ */
			status = dcl_variable( 	mptr->name,	/* Variable name */
					dptr->type->type,	/* Data type	 */
					dptr->type->size,	/* Data length	 */
					dptr->type->first,	/* 1st dimension */
					dptr->type->second,	/* 2nd dimension */
					mptr->nature,		/* ARG required  */
					0,			/* Already typed */
					level, master );	/* Symbol Flag   */

			/* Declare Variable WITH    Symbol unicity checking */
			/* ------------------------------------------------ */
		else 	status = add_variable( 	mptr->name,	/* Variable name */
					dptr->type->type,	/* Data type	 */
					dptr->type->size,	/* Data length	 */
					dptr->type->first,	/* 1st dimension */
					dptr->type->second,	/* 2nd dimension */
					mptr->nature,	/* ARG required  */
					0, master );		/* Already typed */


		/* Restore Public / Private Atribut for others */
		/* ------------------------------------------- */
		Context->Visibility = hold_access;

		}


	if (( mptr->access & _MEMBER_COMMON )
	&&  (!( mptr->lock & _MEMBER_LOCKED ))
	&&  ( mptr->common == (TCVARPTR) 0 )) {
		mptr->common = common->common = resolve_new_variable( variable );
		if (mastermode)
			field_equals_l();
		else	field_equals_s();
		copy_field( Context->ThisField, & HoldField );
		}

	return( status );
}

WORD		structure_occupation( sptr )
TCSTRUCTPTR	sptr;
{
	TCMEMBERPTR	mptr;
	WORD		status;
	if ((mptr = sptr->first) == (TCMEMBERPTR) 0)
		return( illegal_recursivity(sptr->name,0) );
	else if ( sptr->lock & _MEMBER_SIZED )
		return( sptr->size );
	else	{
		sptr->first = (TCMEMBERPTR) 0;
		status = ll_structure_occupation( sptr, mptr );
		sptr->first = mptr;
		return( status );
		}
}
#ifdef	_TRACE_OCCUPATION
WORD		structure_occupation( sptr )
TCSTRUCTPTR	sptr;
{
	WORD	size;
	BYTE	buffer[16];
	trace("structure_occupation("); trace( sptr->name );
	size = ml_structure_occupation( sptr );
	sprintf(buffer,"[%u]",size);
	trace( buffer ); trace(")\n");
	return( size );
}
#endif

WORD		ll_member_occupation( mptr )
TCMEMBERPTR	mptr;
{
	TCMBDATAPTR	dptr;
	
	if (( mptr->size )
	     ||  ( mptr->lock & _MEMBER_SIZED ))	
		return( mptr->size );
	else	mptr->lock |= _MEMBER_SIZED;

	/* Eliminate Non-data members */
	/* -------------------------- */
	if (!( mptr->nature )) {
		mptr->size = method_occupation( mptr, mptr->special );
		return( mptr->size );
		}
	else if (( mptr->nature == _KW1_CONST )
	     ||  ( mptr->access & _MEMBER_INHERIT ))
		return( 0 );

	else if ((dptr = (TCMBDATAPTR) mptr->special) == (TCMBDATAPTR) 0)
		return( internal_error( 676 ) );

	if ( dptr->field )
		return( 0 );

	if ( dptr->structname != (BPTR) 0 ) {
		if (( mptr->nature == _KW1_PTR )
		||  ( mptr->nature == _KW1_IND )
		||  ( mptr->nature == _KW1_OVL ))
			return((mptr->size = 5 ));
		if ((dptr->structure == (TCSTRUCTPTR) 0)
		&&  ((dptr->structure = known_structure( dptr->structname )) == (TCSTRUCTPTR) 0))
			return( 0 );
		else	return((mptr->size = structure_occupation(dptr->structure) ));
		}
	else if (( dptr->type->type & _TYPE_POINTER ) == _TYPE_POINTER)
		return((mptr->size = 5 ));
	else	return((mptr->size = (dptr->type->size * dptr->type->first * dptr->type->second) ));
}

static	WORD	member_occupation( mptr )
TCMEMBERPTR	mptr;
{
	if ( mptr->access & _MEMBER_COMMON )
		return( 0 );
	else	return( ll_member_occupation( mptr ) );
}


static	WORD	ll_structure_occupation( sptr, mptr )
TCSTRUCTPTR	sptr;
TCMEMBERPTR	mptr;
{
	WORD		size=0;
	WORD		msize;

	trace("ll_structure_occupation("); trace( sptr->name ); trace(")\n");

	if (( sptr->size )
	||  ( sptr->lock & _MEMBER_SIZED ))
		return( sptr->size );
	else if (mptr != (TCMEMBERPTR) 0) {
		do	{
			msize = member_occupation( mptr );
			if ( sptr->nature != _KW1_UNION )
				size += msize;
			else if (msize > size )
				size = msize;
			}
		while ((mptr = mptr->next) != (TCMEMBERPTR) 0);
		}

	sptr->lock |= _MEMBER_SIZED;
	return((sptr->size = size));
}

WORD		declare_structure( sptr, nptr, nature, level, master, valptr, field )
TCSTRUCTPTR	sptr;
BPTR		nptr;
WORD		nature;
WORD		level;
WORD		master;
TCTEXTPTR	valptr;
WORD		field;
{
	WORD		hold_access;
	WORD		status;
	WORD		hold;

/*	sysprintf("declare_structure(%s %s)\n",sptr->name,nptr);	*/

	/* Establish Public / Private Atribut for Member */
	/* --------------------------------------------- */
	hold_access = Context->Visibility; 
	Context->Visibility = sptr->access;

	hold = sptr->lock;
	sptr->lock = ((((hold & _MEMBER_LOCKED) ^ _MEMBER_LOCKED) & _MEMBER_LOCKED) | (hold & ~_MEMBER_LOCKED));

	status = ll_declare_structure( sptr, sptr->first, nptr, nature, level, master, valptr, field );
	sptr->lock = ( hold | (sptr->lock & _MEMBER_SIZED ));

	/* Restore Public / Private Atribut for others */
	/* ------------------------------------------- */
	Context->Visibility = hold_access;

	return( status );
}

TCSTRUCTPTR	input_class()
{
	TCVARPTR	object;
	TCSTRUCTPTR	class;
	if  (((object = (TCVARPTR)input_object()) != (TCVARPTR) 0)
	&&   ( object->type != (TCTYPPTR) 0)
	&&   ((class = (TCSTRUCTPTR)object->type->class) != (TCSTRUCTPTR) 0))
		return( class );
	else	return((TCSTRUCTPTR) 0);
}


WORD		declare_instance( sptr, nptr, nature, level, master, valptr, field )
TCSTRUCTPTR	sptr;
BPTR		nptr;
WORD		nature;
WORD		level;
WORD		master;
TCTEXTPTR	valptr;
WORD		field;
{
	TCVARPTR		optr=(TCVARPTR) 0;
	TCMEMBERPTR		common=(TCMEMBERPTR) 0;
	WORD			status;
	WORD			mastermode=0;
	struct tcode_field 	HoldField;

	if ( Context->Visibility & _MEMBER_COMMON ) {

		if (((common = locate_common_object( nptr , sptr, input_class() )) == (TCMEMBERPTR) 0)
		&&  ((common = build_common_object( nptr, sptr, nature, valptr, field )) == (TCMEMBERPTR) 0))
			return( allocation_failure() );
		else if (common->common != (TCVARPTR) 0)
			return( 0 );
		else if (!( common->access & _MEMBER_DYNAMIC )) {

			/* Static Common objects may be Predefined */
			/* --------------------------------------- */
			if (!( build_token( TokenBuffer, common->name ) ))
				return( syntax_error( 1005 ) );

			else if ((optr = is_object()) != (TCVARPTR) 0) {
				while ( optr->parent != (TCVARPTR) 0 ) 
					optr = optr->parent;
				common->common = optr;
				return( 0 );
				}
			}

		optr = extern_or_global();
		nptr = common->name;

		if (Context->Visibility & _MEMBER_DYNAMIC)
			level++;

		copy_field( & HoldField, Context->ThisField );

		if ((mastermode = (Context->scope & ISLOCAL)))
			field_equals_g();

		field_equals_m();

		}

	status = declare_structure( sptr, nptr, nature, level, master, valptr, field );

	if ( common != (TCMEMBERPTR) 0) {

		common->common = resolve_new_variable( optr );

		if ( mastermode )
			field_equals_l();

		copy_field( Context->ThisField, & HoldField );

		}

	return( status );

}

WORD	declare_terminal( vname, vtype, vsize, vone, vtwo, type, nature, master )
BPTR	vname;
WORD	vtype;
WORD	vsize;
WORD	vone;
WORD	vtwo;
WORD	type;
WORD	nature;
WORD	master;
{
	TCVARPTR		optr=(TCVARPTR) 0;
	TCMEMBERPTR		common=(TCMEMBERPTR) 0;
	WORD			status;
	WORD			mastermode=0;
	WORD			level=0;
	struct tcode_field 	HoldField;

	if ( Context->Visibility & _MEMBER_COMMON ) {

		if (((common = locate_common_terminal( vname )) == (TCMEMBERPTR) 0)
		&&  ((common = build_common_terminal( vname, vtype, vsize, vone, vtwo, nature )) == (TCMEMBERPTR) 0))
			return( allocation_failure() );
		else if (common->common != (TCVARPTR) 0)
			return( 0 );
		else	{
			optr = extern_or_global();
			vname = common->name;
			}

		if ( common->access & _MEMBER_DYNAMIC )
			level++;

		copy_field( & HoldField, Context->ThisField );

		if ((mastermode = (Context->scope & ISLOCAL)))
			field_equals_g();

		field_equals_m();

		}

	if ( level )
		status = dcl_variable( vname, vtype, vsize, vone, vtwo, type, nature, level, master );
	else	status = add_variable( vname, vtype, vsize, vone, vtwo, type, nature, master );

	if ( common != (TCMEMBERPTR) 0) {

		common->common = resolve_new_variable( optr );

		if ( mastermode )
			field_equals_l();

		copy_field( Context->ThisField, & HoldField );

		}

	return( status );

}


static	WORD	declare_member_construction( world, member, class, valptr, mode )
TCVARPTR	world;
TCMEMBERPTR	member;
TCSTRUCTPTR	class;
TCTEXTPTR	valptr;
WORD		mode;
{
	WORD		status;
	TCVARPTR	object=(TCVARPTR) 0;
	TCMEMBERPTR	xmember=member;

	/* Ensure Structured Member */
	/* ------------------------ */
	if (( class == (TCSTRUCTPTR) 0 )
	||  ( member == (TCMEMBERPTR) 0))
		return( 0 );

	/* Common member objects will be constructed alone */
	/* ----------------------------------------------- */
	else if ( member->access & _MEMBER_COMMON )
		return( 0 );

	/* Explicite Pointers do not require Construction */
	/* ---------------------------------------------- */
	else if (( member->nature == _KW1_PTR )
	     ||  ( member->nature == _KW1_OVL ))
		return( 0 );

	trace("declare_member_construction("); 
	trace( world->name ); 
	trace(".");
	trace( member->name ); 
	trace(")\n");

	if ((object = resolve_member_variable( world, member->name, member->hash )) == (TCVARPTR) 0)
		return( internal_error( 323 ) );
	else if ((class  = (TCSTRUCTPTR) object->type->class) == (TCSTRUCTPTR) 0)
		return( internal_error( 333 ) );

	/* The class should have members */
	/* ----------------------------- */
	if ((member = (TCMEMBERPTR) class->first) == (TCMEMBERPTR) 0)
		return( internal_error( 343 ) );

	if ((status = start_member_construction( object, xmember )) == 0) {
		status = declare_object_construction( 	world,
							object, 
							class, 
							member, 
							valptr, 
							mode, MOINS_UN );

		status += terminate_member_construction();
		}

	TokenBuffer[0] = 0;
	return( status );
}

WORD	allocate_indirect_object( object )
TCVARPTR	object;
{
	WORD	status=0;

	while ( object->parent != (TCVARPTR) 0)
		object = object->parent;

	if (( object != (TCVARPTR) 0 )
	&&  ( object->type->size != 0)
	&&  ((status = add_indirect_construction( object, object, (VPTR) 0, (VPTR) 0,(_AUTO_CONSTRUCTION | _AUTO_DESTRUCTION) )) == 0)
	&&  ((status = add_destruction_method(object, object, (VPTR) 0, (VPTR) 0, (VPTR) 0,(_AUTO_CONSTRUCTION | _AUTO_DESTRUCTION) )) == 0))
		return( 0 );
	else	return( status );

}

static	WORD	declare_object_construction( world, object, class, member, valptr, mode, allocation )
TCVARPTR	world;
TCVARPTR	object;
TCSTRUCTPTR	class;
TCMEMBERPTR	member;
TCTEXTPTR	valptr;
WORD		mode;
WORD		allocation;	/* Explicite CREATE:0, ATTACH:1	*/
				/* Implicite MOINS_UN		*/
{
	TCMBDATAPTR	dptr;
	WORD		status;

	if ( object->type->type & _TYPE_OVERLAY ) {
		if ((allocation == MOINS_UN)
		&&  (!( class->enhanced & _ENHANCED_INDIRECT))
		&&  ((status = allocate_indirect_object( object )) != 0))
			return( status );
		else if ((status = declare_overlay_construction( world, object, mode, allocation )) != 0)
			return( status );

		}

	if (member != (TCMEMBERPTR) 0) {

		trace("declare_object_construction("); 
		trace( object->name );
		trace(")\n");

		do	{
			if (!( member->nature )) {
				if ((status = detect_auto_method( world,object, member, member->special, valptr, mode, allocation )) != 0)
					return( status );
				}
			else if ( member->nature == _KW1_CONST )
				continue;
			else if ( member->access & _MEMBER_INHERIT )
				continue;
			else if ( allocation == 1 )
				continue;
			else if ((dptr = (TCMBDATAPTR) member->special) == (TCMBDATAPTR) 0)
				return( internal_error( 313 ) );
			else if ((status = declare_member_construction( 
						object, 
						member, 
						dptr->structure, 
						dptr->construction, 
						mode )) != 0)
				return( status );
				
			}
		while ((member = member->next) != (TCMEMBERPTR) 0);
		}				
	return( 0 );
}

TCVARPTR	base_member_host( host )
TCVARPTR	host;
{
	TCVARPTR	member;

	/* Locate Original Descriptor Node */
	/* ------------------------------- */
	while (host->parent != (TCVARPTR) 0)
		host = host->parent;

	member = host;

	/* Locate Host of Member Node */
	/* -------------------------- */
	while (( host = host->next) != (TCVARPTR) 0 )
		if ( host->identity == member->master )
			return( temp_variable( host ) );

	return((TCVARPTR) 0);
	
}

TCTEXTPTR	default_construction( object )
TCVARPTR	object;
{
	while ( object->parent != (TCVARPTR) 0 )
		object = object->parent;
	return( copy_text_value( object->construction ) );
}


WORD		explicite_construction( object, nature )
TCVARPTR	object;
WORD		nature;	/* CREATE=0, ATTACH=1 */
{
	TCSTRUCTPTR	class;
	TCTEXTPTR	valptr=(TCTEXTPTR) 0;
	WORD		status;

	if (( object->type->type & (_TYPE_DEFINED | _TYPE_OVERLAY))
	&&  (( class = (TCSTRUCTPTR)object->type->class) != (TCSTRUCTPTR) 0)) {

		/* Ensure ! CREATE OVERLAY and ! ATTACH NON-OVERLAY */
		/* ------------------------------------------------ */
		if (object->type->type & _TYPE_OVERLAY) {
			if (!( nature ))
				return( syntax_error( 3330 ) );
			}
		else if ( nature )
			return( syntax_error( 3331 ) );		

		trace("explicite_construction()\n");

		if ( is_left_brace()) {
			if ((valptr = collect_construction_parameters()) == (TCTEXTPTR) 0)
				return( allocation_failure() );
			}
		else	valptr = default_construction( object );

		if (((status = start_instance_construction( object, variable_nature( object ) )) == 0)
		||  (status == MOINS_UN)) {
			status = declare_object_construction( input_object(), object, class, class->first, valptr ,(_AUTO_EXPLICITE | _AUTO_CONSTRUCTION) ,nature );
			status += terminate_instance_construction( object, 0 );
			}
		valptr = liberate_text_value( valptr );

		if ( status ) 
			return( status );
		else if (( object->type->type & _TYPE_POINTER ) != _TYPE_POINTER )
			return( MOINS_UN );
		else	return( 0 );
		}
	return( 0 );
}

WORD		explicite_destruction( object, nature )
TCVARPTR	object;
WORD		nature;	/* REMOVE=0, DETACH=1 */
{
	TCSTRUCTPTR	class;
	TCTEXTPTR	valptr=(TCTEXTPTR) 0;
	WORD		status;

	if (( object->type->type & (_TYPE_DEFINED | _TYPE_OVERLAY))
	&&  (( class = (TCSTRUCTPTR)object->type->class) != (TCSTRUCTPTR) 0)) {

		/* Ensure ! REMOVE OVERLAY and ! DETACH NON-OVERLAY */
		/* ------------------------------------------------ */
		if (object->type->type & _TYPE_OVERLAY) {
			if (!( nature ))
				return( syntax_error( 3332 ) );
			}
		else if ( nature )
			return( syntax_error( 3333 ) );		

		trace("explicite_destruction()\n");

		if ( is_left_brace()) {
			if ((valptr = collect_construction_parameters()) == (TCTEXTPTR) 0)
				return( allocation_failure() );
			}
		else	valptr = default_construction( object );

		if (((status = start_instance_construction( object, variable_nature( object ) )) == 0)
		||  (status == MOINS_UN)) {
			status = declare_object_construction( input_object(),object, class, class->first, valptr ,(_AUTO_EXPLICITE | _AUTO_DESTRUCTION) ,nature );
			status += terminate_instance_construction( object, 0 );
			}

		valptr = liberate_text_value( valptr );


		if ( status )
			return( status );
		else if ((status = flush_explicite_destructors()) != 0)
			return( status );
		else if (( object->type->type & _TYPE_POINTER ) != _TYPE_POINTER )
			return( MOINS_UN );
		else	return( 0 );
		}
	return( 0 );
}

#include "trcommon.c"


static	WORD	indirect_method_count( class, member, nombre )
TCSTRUCTPTR	class;
TCMEMBERPTR	member;
WORD		nombre;
{
	TCSTRUCTPTR	sptr;
	while ( member != (TCMEMBERPTR) 0 ) {
		if  ( member->access & _MEMBER_PUBLIC ) {
			if (!( member->nature ))
				nombre = identify_indirect_method( member->special, nombre );
			else 	{
				if (( class->enhanced & _ENHANCED_INDIRECT )
				&&  ( member->nature != _KW1_CONST )
				&&  ((sptr = base_class_componant( member )) != (TCSTRUCTPTR) 0))
					nombre = indirect_method_count( sptr, sptr->first, nombre );
				}
			}
		member = member->next;
		}
	return( nombre );
}

static	WORD	eimt_base( class, level, master )
TCSTRUCTPTR	class;
WORD		level;
WORD		master;
{
	TCVARPTR	variable;
	WORD		functions;
	WORD		status=0;

	if ((functions = indirect_method_count( class,class->first, 0 )) == 0)
		return( 0 );
	else	variable = local_extern_global();

	if ((status = dcl_variable( 
				class->name,	/* Variable name 	*/
				(_TYPE_DEFINED | _TYPE_STRING),	/* Table Type		*/
				(functions * 10),/* Table Size     	*/
				1,		/* 1st dimension	*/
				1,		/* 2nd dimension 	*/
				_KW1_DCL, 	/* DCL, PTR, OVL 	*/
				0,level, master )) != 0)
		return( 0 );

	variable = variable->prev;

	if ((status = redefine_base_variable( variable )) != 0)
		return( 0 );

	variable->type->class = (VPTR)class;
	return( variable->identity );
}

static	WORD	declare_eimt_vectors( class , level, master )
TCSTRUCTPTR	class;
WORD		level;
WORD		master;
{
	TCMEMBERPTR	member;
	TCSTRUCTPTR	sptr;
	WORD		status=0;
	if (( class != (TCSTRUCTPTR) 0)
	&&  ( master != 0 )
	&&  ((member = class->first) != (TCMEMBERPTR) 0)) {
		do	{
			if  ( member->access & _MEMBER_PUBLIC ) {
				if (!( member->nature )) {
					if ((status = dcl_method_pointer( member, level, master, member->size, class )) != 0)
						break;
					}
				else 	{
					if (( class->enhanced & _ENHANCED_INDIRECT )
					&&  ( member->nature != _KW1_CONST )
					&&  ((sptr = base_class_componant( member )) != (TCSTRUCTPTR) 0)
					&&  ((status = declare_eimt_vectors(sptr,level,eimt_base( sptr, (level+1), master ) )) != 0))
						break;
					}
				}
			}
		while ((member = member->next) != (TCMEMBERPTR) 0);
		}
	return(status);
}

static	WORD	declare_eimt( class, level, master )
TCSTRUCTPTR	class;
WORD		level;
WORD		master;
{
	WORD		status;
	TCVARPTR	variable;

	if ((status = field_equals_s()) != 0)
		return( status );

	variable = local_extern_global();

	if ((status = redefine_base_variable( variable )) != 0 )
		return( status );

	if ((status = dcl_filler( 10 )) == 0 )
		/* Declare Interface Method Vectors */
		/* -------------------------------- */
		status = declare_eimt_vectors( class, level, master );

	field_equals_r();
	
	return( status );

}

static	WORD	declare_enhanced_overlay( sptr , nptr, level, master )
TCSTRUCTPTR	sptr;
BPTR		nptr;
WORD		level;
WORD		master;
{
	WORD		functions=1;
	WORD		status;

	functions = indirect_method_count( sptr, sptr->first, functions );

	if ((status = dcl_variable( 
				nptr,		/* Variable name 	*/
				(_TYPE_FIRST | _TYPE_STRING),	/* Table Type		*/
				5,		/* EIMT size 		*/
				(functions * 2),/* First dimension	*/
				1,		/* 2nd dimension 	*/
				_KW1_PTR, 	/* DCL, PTR, OVL 	*/
				0,level, master )) != 0)

		return( status );

	else if ((status = declare_eimt( sptr, level, master )) != 0)
		return( status );

	else if ((status = dcl_variable(
				nptr,		/* Variable name */
				(_TYPE_STRING | _TYPE_DEFINED),
				sptr->size, 	/* Data Length 	 */
				1,		/* 1st dimension */
				1,		/* 2nd dimension */
				_KW1_PTR, 	/* DCL, PTR, OVL */
				0,level, master )) != 0)

		return( status  );

	
	return( 0 );

}

static	WORD	declare_standard_overlay( sptr , nptr, level, master )
TCSTRUCTPTR	sptr;
BPTR		nptr;
WORD		level;
WORD		master;
{
	WORD		functions=2;
	WORD		status;

	functions = indirect_method_count( sptr, sptr->first, functions );

	if ((status = dcl_variable( 
				nptr,		/* Variable name 	*/
				(_TYPE_FIRST | _TYPE_STRING),
				5,		/* Size of Proc Ptr	*/
				functions,	/* Indirect Method count */
				1,		/* 2nd dimension 	*/
				_KW1_PTR, 	/* DCL, PTR, OVL 	*/
				0,level, master )) != 0)

		return( status );

	else if ((sptr->size) && ((status = dcl_variable(
				nptr,		/* Variable name */
				_TYPE_STRING,
				sptr->size, 	/* Data Length 	 */
				1,		/* 1st dimension */
				1,		/* 2nd dimension */
				_KW1_PTR, 	/* DCL, PTR, OVL */
				0,level, master )) != 0))

		return( status  );

	else	return( 0 );

}

static	WORD	declare_indirect_object( sptr , nptr, level, master )
TCSTRUCTPTR	sptr;
BPTR		nptr;
WORD		level;
WORD		master;
{
	if ( sptr->enhanced & _ENHANCED_INDIRECT )
		return( declare_enhanced_overlay( sptr, nptr, level, master ) );
	else	return( declare_standard_overlay( sptr, nptr, level, master ) );

}

static	WORD	redefine_overlay_object( sptr , nptr, level, master )
TCSTRUCTPTR	sptr;
BPTR		nptr;
WORD		level;
WORD		master;
{
	WORD		status;
	TCVARPTR	bptr;

	if ((status = declare_indirect_object( sptr, nptr, level, master)) != 0)
		return( status );

	else if (!( sptr->size ))
		return( 0 );

	bptr = local_extern_global();

	return( redefine_base_variable( bptr ) );
}


static	WORD	declare_overlay_object( sptr , nptr, level )
TCSTRUCTPTR	sptr;
BPTR		nptr;
WORD		level;
{
	WORD		functions=2;
	WORD		status;
	TCVARPTR	bptr;
	WORD		master=0;

	bptr = local_extern_global();

	if ( bptr != (TCVARPTR) 0) {
		bptr->type->class = (VPTR)sptr;
		master = bptr->identity;
		}

	if ((status = redefine_base_variable( bptr )) != 0)
		return( 0 );

	if ((status = declare_indirect_object( sptr, bptr->name, level, master)) != 0)
		return( 0 );
	else	return( master );
}

static	WORD	declare_static_inheritance( sptr, master )
TCSTRUCTPTR	sptr;
WORD		master;
{
	WORD		status;
	TCVARPTR	object;

	/* Declare Variable without Symbol unicity checking */
	/* ------------------------------------------------ */
	if ((status = dcl_variable( 
		sptr->name,	/* Variable name */
		(_TYPE_STRING | _TYPE_DEFINED),	
		sptr->size,
		1,		/* 1st dimension */
		1,		/* 2nd dimension */
		_KW1_DCL,	/* DCL, PTR, OVL */
		0,1, master )) != 0)
		return( status );

	object = local_extern_global();

	object->type->class = (VPTR)sptr;

	if ((status = redefine_base_variable( object )) != 0)
		return( status );
	else	return( 0 );

}

static WORD	ll_declare_structure( sptr, mptr, nptr, nature, level, master, valptr, field )
TCSTRUCTPTR	sptr;
TCMEMBERPTR	mptr;
BPTR		nptr;
WORD		nature;
WORD		level;
WORD		master;
TCTEXTPTR	valptr;
WORD		field;
{
	TCMBDATAPTR		dptr;
	TCVARPTR		bptr;
	TCVARPTR		object=(TCVARPTR) 0;
	struct tcode_field 	MemoryField;
	struct tcode_field 	HoldField;
	struct tcode_field 	UnionField;
	WORD			status=0;
	WORD			adjust=1;
	WORD			hold_master= master;
	TCMEMBERPTR		hold_member= mptr;

	trace("ll_declare_structure("); trace(sptr->name); trace(")\n");

	if (( sptr->size == 0)
	&&  ((sptr->size =  ll_structure_occupation(sptr,mptr)) == 0)
	&&   (mptr == (TCMEMBERPTR) 0))
		return( syntax_error(731)  );

	if (strlen(nptr) == 0)
		adjust = 0;

	if ( field ) {
		copy_field( & MemoryField, Context->ThisField );
		if (( status = field_equals_file( field )) != 0)
			return( status );
		}

	/* Establish Unified Memory Start if required */
	/* ------------------------------------------ */
	if (( sptr->nature == _KW1_UNION )
	&&  ( adjust ))
		copy_field( & UnionField, Context->ThisField );

	if ( adjust ) {

		if ( level )

			/* Declare Variable without Symbol unicity checking */
			/* ------------------------------------------------ */
			status = dcl_variable( 
					nptr,		/* Variable name */
			( nature == _KW1_OVL ? (_TYPE_OVERLAY | _TYPE_DEFINED | _TYPE_STRING) : (_TYPE_DEFINED | _TYPE_STRING) ),
					object_occupation( sptr ),
					1,		/* 1st dimension */
					1,		/* 2nd dimension */
					nature,		/* DCL, PTR, OVL */
					0,level, master );

			/* Declare Variable with    Symbol unicity checking */
			/* ------------------------------------------------ */
		else	status = add_variable( 
					nptr,		/* Variable name */
			( nature == _KW1_OVL ? (_TYPE_OVERLAY | _TYPE_DEFINED | _TYPE_STRING) : (_TYPE_DEFINED | _TYPE_STRING) ),
					object_occupation( sptr ),
					1,		/* 1st dimension */
					1,		/* 2nd dimension */
					nature,		/* DCL, PTR, OVL */
					0, master );	/* not required  */



		if ( status )
			return( status );
		else	copy_field( & HoldField, Context->ThisField );

		if (!( master )) {
			field_equals_m();
			field_equals_s();
			if (( field )
			&&  (( status = field_equals_file( field )) != 0))
				return( status );
			}

		if ( nature == _KW1_OVL ) {

			object = local_extern_global();

			if (( master = declare_overlay_object( sptr, nptr, (level+adjust) )) == 0)
				return( syntax_error( 5000 ) );

			object->construction = copy_text_value( valptr );

			}
		}

	bptr = local_extern_global();

	if ( bptr != (TCVARPTR) 0) {
		bptr->type->class = (VPTR)sptr;
		bptr->construction = copy_text_value( valptr );
		}
	if ((mptr == (TCMEMBERPTR) 0)
	||  (!(sptr->lock & _MEMBER_LOCKED)))	
		return( issue_warning( 11 ) );

	if (!( sptr->access & _MEMBER_OVERLAY ))
		 object = bptr;

	if ( adjust ) {

		if ((status = redefine_base_variable( bptr )) != 0)
			return( status );

		if (!( sptr->access & _MEMBER_OVERLAY ))
			master = bptr->identity;

		/* Establish Unified Memory Start if required */
		/* ------------------------------------------ */
		if ( sptr->nature == _KW1_UNION )
			copy_field( & UnionField, Context->ThisField );

		}

	/* Overlay Objects do not require member generation */
	/* ------------------------------------------------ */
	if ( nature != _KW1_OVL ) {

	do	{
		/* Declaration of Indirect Method or Method Pointer */
		/* ------------------------------------------------ */
		if ( mptr->access & _MEMBER_COMMON )
			continue;

		if (!( mptr->nature )) {
			if ((status = declare_member(sptr,mptr,(level+adjust),master,( sptr->access & _MEMBER_OVERLAY ? 10 : sptr->size ))) != 0)
				return( status );
			else	continue;
			}
		else if ( mptr->nature == _KW1_CONST )
			continue;

		else	dptr = (TCMBDATAPTR) mptr->special;

		/* Declaration of Structural Element */
		/* --------------------------------- */
		if ( dptr->structname != (BPTR) 0 ) {

			if ((dptr->structure == (TCSTRUCTPTR) 0)
			&&  ((dptr->structure = known_structure( dptr->structname )) == (TCSTRUCTPTR) 0))
				return( syntax_error(732) );

			if ( dptr->structure->virtual )
				return( syntax_error( 1030 ) );
			else if ( mptr->access & _MEMBER_COMMON )
				continue;

			else if ( mptr->access & _MEMBER_INHERIT ) {
				if ((status = declare_static_inheritance( dptr->structure, master )) != 0)
					return( status );
				}
			else if ((status = declare_structure(dptr->structure,mptr->name,mptr->nature,(level+adjust),master,dptr->construction,dptr->field)) != 0)
				return( status );

			}

		/* Declaration of Terminal Data Member */
		/* ----------------------------------- */
		else if ((status = declare_member(sptr,mptr,(level+adjust),master,( sptr->access & _MEMBER_OVERLAY ? 10 : sptr->size ))) != 0)
			return( status );

		/* Reposition to start of UNION if required */
		/* ---------------------------------------- */
		if (( sptr->nature == _KW1_UNION )
		&&  ( adjust ))
			copy_field( Context->ThisField, & UnionField );
		}
	while ((mptr = mptr->next) != (TCMEMBERPTR) 0);
		}

	if ( adjust )
		copy_field( Context->ThisField, & HoldField );

	if (!( hold_master )) {

		field_equals_r();
		field_equals_m();

		if ((status = start_instance_construction( object, nature )) == MOINS_UN) {
			if ((( nature == _KW1_OBJ ) 
			||   ( nature == _KW1_CMN ))
			&&  ((status = allocate_indirect_object( object )) != 0))
				return( status );
			}
		else if ( status )
			return( status );
		if (( nature != _KW1_PTR )
		&&  ( nature != _KW1_OVL )
		&&  ((status = declare_object_construction( input_object(), object, sptr, hold_member, valptr, 3, MOINS_UN )) != 0))
			return( status );

		if ((status = terminate_instance_construction( object, 1 )) != 0)
			return( status );

		}

	if (( field )
	&&  ( hold_master ))
		copy_field( Context->ThisField, & MemoryField);

	return(0);
}

WORD	declare_local_members( sptr )
TCSTRUCTPTR	sptr;
{
	WORD		status;
	TCMEMBERPTR	mptr;
	TCMBDATAPTR	dptr;

	if ( sptr != (TCSTRUCTPTR) 0) {
		if ((mptr = sptr->first) != (TCMEMBERPTR) 0) {
			do	{
				/* Declaration of Indirect Method or Method Pointer */
				/* ------------------------------------------------ */
				if (!( mptr->nature )) {
					if ((status = declare_member(sptr,mptr,0,0,( sptr->access & _MEMBER_OVERLAY ? 10 : sptr->size ))) != 0)
						return( status );
					else	continue;
					}
				else if ( mptr->nature == _KW1_CONST )
					continue;
				else	dptr = (TCMBDATAPTR) mptr->special;

				/* Declaration of Structural Element */
				/* --------------------------------- */
				if ( dptr->structname != (BPTR) 0 ) {

					if ((dptr->structure == (TCSTRUCTPTR) 0)
					&&  ((dptr->structure = known_structure( dptr->structname )) == (TCSTRUCTPTR) 0))
						return( syntax_error(732) );

					if ( mptr->access & _MEMBER_COMMON ) {
						if (( mptr->common == (TCVARPTR) 0 )
						&&  ((status = declare_common_object(sptr, dptr->structure, mptr, dptr->construction, dptr->field )) != 0))
							return( status );
						continue;
						}
		
					else if ((status = declare_structure(dptr->structure,mptr->name,mptr->nature,0,0,dptr->construction,dptr->field)) != 0)
						return( status );

					}

				/* Declaration of Terminal Data Member */
				/* ----------------------------------- */
				else if ((status = declare_member(sptr,mptr,0,0,( sptr->access & _MEMBER_OVERLAY ? 10 : sptr->size ))) != 0)
					return( status );

				}
			while ((mptr = mptr->next) != (TCMEMBERPTR) 0);
			}
		}
	return(0);
}


/*
 *	D E F I N E _ S T R U C T U R E ()
 *	----------------------------------
 *
 *	Entry here to attempt the start of a new structure definition.
 *
 *	Called from 	:
 *	
 *			TRSTRUCT.translate_struct
 *	
 *		in response to the 'STRUCT' instruction.
 *	
 *	and from	:
 *
 *			TRSTRUCT.declare_structure
 *
 *		in response to the 'DCL STRUCT <struct> <instance> AS
 *		instruction for the immediate definition of a structure
 *		nested within another structure.
 *
 */

WORD	define_explicite_union()
{
	TCSTRUCTPTR	sptr;
	WORD		status;

	trace("define_explicite_union()\n");

	sprintf(TokenBuffer,"@au%u_%s",++ExpliciteUnion,World->CurrentStructure->name);	

	if ((sptr = allocate_for_structure( TokenBuffer )) == (TCSTRUCTPTR) 0)
		return( allocation_failure() );

	sptr->nature = _KW1_UNION;

	if ((status = class_tree_node( sptr )) != 0)
		return( status );

	sptr->next = World->CurrentStructure;
	World->CurrentStructure = sptr;

	return( 0 );
}

static	WORD	class_specialisation( sptr, mptr )
TCSTRUCTPTR	sptr;
TCMEMBERPTR	mptr;
{
	/* Classes may be specialised with respect to their methods */
	/* -------------------------------------------------------- */
	if  (!( mptr->nature )) {

		/* Detect Static Function and Signal Static Class */
		/* ---------------------------------------------- */
		if ( is_static_function( mptr->special ) )
			sptr->access &= ~_MEMBER_DYNAMIC;

		/* Detect and Signal Overlay Class */
		/* ------------------------------- */
		if ( is_overlay_indirect( mptr->special ) )
			sptr->access |= _MEMBER_OVERLAY;

		}
	

	if ( mptr->access & _MEMBER_COMMON )
		return( add_world_member( mptr->class,  mptr ) );
	else	return( 0 );

}

WORD		add_member( sptr, mptr )
TCSTRUCTPTR	sptr;
TCMEMBERPTR	mptr;
{
	WORD	status;
	if ((status = class_specialisation( sptr, mptr )) != 0)
		return( status );
	else	{
		if (sptr->first == (TCMEMBERPTR) 0)
			sptr->first = mptr;
		else	sptr->last->next = mptr;
		mptr->prev = sptr->last;
		sptr->last = mptr;
		return(0);
		}
}
	
WORD	terminate_explicite_union()
{
	TCSTRUCTPTR	sptr;
	TCMEMBERPTR	mptr;
	TCMBDATAPTR	dptr;

	trace("terminate_explicite_union()\n");

	if ((sptr = World->CurrentStructure) == (TCSTRUCTPTR) 0)
		return( internal_error( 6007 ) );
	else	{
		World->CurrentStructure = sptr->next;
		sptr->next = World->Structures;
		World->Structures = sptr;
		trace( sptr->name );
		if (((mptr = allocate_structure_member(sptr->name)) != (TCMEMBERPTR) 0)
		&&  ((dptr = allocate_structure_data()) != (TCMBDATAPTR) 0)) {
			mptr->nature = _KW1_DCL;
			dptr->structname = allocate_for_string( sptr->name );
			mptr->special = (VPTR)dptr;
			return( add_member( World->CurrentStructure , mptr ) );
			}
		else	return( allocation_failure() );
		}
}

static	WORD	new_class_number()
{
	TCSTRUCTPTR	sptr;
	if (((sptr = World->CurrentStructure) != (TCSTRUCTPTR) 0)
	||  ((sptr = World->Structures) != (TCSTRUCTPTR) 0))
		return(( sptr->number + 1 ));
	else	return( 1 );
}

WORD	open_structure_definition( nptr, type )
BPTR	nptr;
WORD	type;
{
	TCSTRUCTPTR	sptr;
	WORD		status;

	if ((sptr = known_structure( nptr )) != (TCSTRUCTPTR) 0) {
		if (( sptr->first != (TCMEMBERPTR) 0 )
		||  ( sptr->lock & _MEMBER_LOCKED  ))
			return( symbol_already_defined(nptr) );
		else if ( sptr->nature != type )
			return( syntax_error( 7171 ) );
		else	{
			/* Actual Definition of Class Prototype */
			/* ------------------------------------ */
			if ( sptr->next != (TCSTRUCTPTR) 0 )
				sptr->next->previous = sptr->previous;
			if ( sptr->previous != (TCSTRUCTPTR) 0)
				sptr->previous->next = sptr->next;
			else	World->Structures = sptr->next;
			}
		}
	else	{
		if ((sptr = allocate_for_structure( nptr )) == (TCSTRUCTPTR) 0)
			return( allocation_failure() );

		sptr->number = new_class_number();

		sptr->nature = type;

		if ((status = class_tree_node( sptr )) != 0)
			return( status );
		else if ( is_colon() ) {
			sptr->size      = integer_expression();
			sptr->explicite = sptr->size;
			}
		}

	sptr->previous = (TCSTRUCTPTR) 0;
	sptr->next     = World->CurrentStructure;

	World->CurrentStructure = sptr;

	return( 0 );
}

WORD	close_structure_definition( sptr )
TCSTRUCTPTR	sptr;
{
	World->CurrentStructure = sptr->next;
	if ((sptr->next = World->Structures) != (TCSTRUCTPTR) 0)
		sptr->next->previous = sptr;
	sptr->previous = (TCSTRUCTPTR) 0;
	World->Structures = sptr;
	/*  resolve_strict_alternatives( sptr ); */
	return( 0 );
}

WORD	define_structure( nptr, type )
BPTR	nptr;
WORD	type;
{
	WORD		status;

	trace("define_struct()\n");

	if ((status = open_structure_definition( nptr, type )) != 0)
		return( status );
	reset_oneshot_options();
	if (World->CurrentStructure->nature == _KW1_CLASS) {
		if ((status = translate_private()) != 0)
			return( status );
		}
	else if ((status = translate_public()) != 0)
		return( status );

	return( translate_base_classes() );
}

WORD	translate_struct(type)
WORD	type;	/* KW1_STRUCT,UNION,CLASS */
{
	WORD	status;
	trace("translate_struct()\n");
	while (1) {
		if ( is_mnemonic( "EXTERN" ) ) {
			if ((status = translate_extern_keyword()) != 0)
				return( status );
			}
		else if ( is_mnemonic( "OVERLAY" )) {
		     	if  ((status = translate_overlay_keyword()) != 0)
				return( status );
			}
		else if ( is_mnemonic( "GENERIC" )) {
		     	if ((status = translate_generic()) != 0)
				return( status );
			}
		else if ( is_mnemonic( "VIRTUAL" )) {
		     	if  ((status = set_world_virtual()) != 0)
				return( status );
			}
		else if ( is_mnemonic( "ANNOUNCE" )) {
		     	if ((status = set_world_announce()) != 0)
				return( status );
			}
		else if ( is_mnemonic( "OCX" )) {
		     	if ((status = translate_ocx_keyword()) != 0)
				return( status );
			}
		else	break;
		}		
	if (!( get_token() ))
		return( syntax_error(733) );
	(void) is_mnemonic("AS");
	status = define_structure( TokenBuffer, type );
	cancel_extern_overlay();
	return( status );
}

WORD	add_friend( sptr, name )
TCSTRUCTPTR	sptr;
BPTR		name;
{
	TCFRIENDPTR	fptr;

	if ((fptr = allocate_for_friend( name )) == (TCFRIENDPTR) 0)
		return( allocation_failure() );
	else	{
		fptr->next = sptr->friend;
		sptr->friend = fptr;
		return( 0 );
		}
}

WORD	translate_friend()
{
	TCSTRUCTPTR	sptr;
	WORD		status=0;
	
	if ((sptr = World->CurrentStructure) == (TCSTRUCTPTR) 0)
		return( syntax_error(710) );

	do	{
		if (!( get_token() ))
			return( syntax_error( 711 ) );
		else if ((status = add_friend( sptr, TokenBuffer)) != 0)
			break;

		}
	while ( is_comma() );
	return(verify_end_of_line());
}

WORD	translate_endstruct(type)
WORD	type;
{
	WORD		status;
	TCSTRUCTPTR	sptr;

	trace("translate_endstruct()\n");

	if ((sptr = World->CurrentStructure) == (TCSTRUCTPTR) 0)
		return( syntax_error(734) );

	if  (( sptr->nature == _KW1_STRUCT )
	&&   ( type != _KW1_ENDSTRUCT ))
		return( expected_keyword("ENDSTRUCT") );
	else if  (( sptr->nature == _KW1_UNION  )
	     &&   ( type != _KW1_ENDUNION  ))
		return( expected_keyword("ENDUNION") );
	else if  (( sptr->nature == _KW1_CLASS  )
	     &&   ( type != _KW1_ENDCLASS  ))
		return( expected_keyword("ENDCLASS") );
	else if ((status = close_structure_definition( sptr )) != 0)
		return( status );

	else if  (  get_token() ) {
		if  (( sptr->hash != TokenHash )
		||   (!( compare_tokens( sptr->name, TokenBuffer ) )))
			return( syntax_error(735) );
		}

	/* Calculate size now if not prototype class */
	/* ----------------------------------------- */
	if ( sptr->first != (TCMEMBERPTR) 0) {
		sptr->lock &= ~_MEMBER_SIZED;
		sptr->size   = structure_occupation( sptr );
		sptr->lock |= _MEMBER_SIZED;
		}

	/* Detect Class Definition and Instance */
	/* ------------------------------------ */
	if ((World->CurrentStructure == (TCSTRUCTPTR) 0)
	&&  (Context->DclStruct != (TCMEMBERPTR) 0)) {
		status = declare_structure( sptr, Context->DclStruct->name, Context->DclStruct->nature, 0,0, (TCTEXTPTR) 0, 0 );
		liberate_structure_member( Context->DclStruct );
		Context->DclStruct = (TCMEMBERPTR) 0;
		return( status );
		}
	else	return( 0 );
}

static	WORD	is_strict_member( member )
TCMEMBERPTR	member;
{
	if ( member->nature )
		return( FAUX );
	else	return( is_strict_method( member->special ) );
}

WORD			replace_member( sptr, xptr, mptr )
TCSTRUCTPTR		sptr;
TCMEMBERPTR		xptr;	/* Member to be replaced */
TCMEMBERPTR		mptr;	/* with this new member  */
{
	WORD	state;
	WORD	status;
	trace("replace_member()\n");
	if ((state = is_strict_member(xptr)) != (is_strict_member(mptr)))
		return( syntax_error( 741 ) );

	else if (state) {

		do	{
		     	if ( compare_strict_methods( xptr->special, mptr->special ) )
				break;
			}
		while ((xptr = 	locate_strict_alternative( mptr, xptr->next )) != (TCMEMBERPTR) 0);

		if ( xptr == (TCMEMBERPTR) 0)
			return( add_member( sptr, mptr ) );
		}

	if ( xptr->access & _MEMBER_PROTECT ) {
		if ( mptr->nature )
			liberate_structure_member( mptr );
		return( issue_warning( 12 ) );
		}
	else	(void)  issue_warning( 13 );

	if ((status = class_specialisation( sptr, mptr )) != 0)
		return( status );
	else	{
		if ((mptr->next = xptr->next) != (TCMEMBERPTR) 0)
			mptr->next->prev = mptr;
		else	sptr->last       = mptr;
		if ((mptr->prev = xptr->prev) != (TCMEMBERPTR) 0)
			mptr->prev->next = mptr;
		else	sptr->first      = mptr;
		trace("remove_previous_member()\n");
		liberate_structure_member( xptr );
		return( 0 );
		}
}

static	VOID	detect_external_member( sptr, mptr )
TCSTRUCTPTR	sptr;
TCMEMBERPTR	mptr;
{
	if (( sptr != (TCSTRUCTPTR) 0)
	&&  ( mptr != (TCMEMBERPTR) 0)) 
		mptr->access |= ( sptr->access & _MEMBER_EXTERN );
	return;
}

WORD	add_to_structure( vname, vtype, vsize, vone, vtwo, vmem, vnat )
BPTR	vname;
WORD	vtype;
WORD	vsize;
WORD	vone;
WORD	vtwo;
WORD	vmem;
WORD	vnat;
{
	TCSTRUCTPTR	sptr;
	TCMEMBERPTR	mptr;
	TCMEMBERPTR	xptr;
	TCMBDATAPTR	dptr;

	trace("add_to_structure()\n");


	if (( vmem == _KW1_PTR )
	||  ( vmem == _KW1_OBJ )
	||  ( vmem == _KW1_CMN )
	||  ( vmem == _KW1_IND )
	||  ( vmem == _KW1_OVL ))
		vtype |= _TYPE_POINTER; 

	if (World == (WORLDPTR) 0)
		return( internal_error( 101 ) );
	else if ((sptr = World->CurrentStructure) == (TCSTRUCTPTR) 0) 
		return( internal_error(111) );
/*	sysprintf("add_to_structure(%s) %s %x %u %u %u\n",sptr->name,vname,vtype, vsize, vone, vtwo ); */
	if (((xptr = locate_member(sptr,vname)) != (TCMEMBERPTR) 0)
	     &&  ( sptr->nature != _KW1_CLASS ))
		return( symbol_already_defined(vname) );
	if ((mptr = allocate_structure_member( vname )) == (TCMEMBERPTR) 0)
		return( allocation_failure() );
	if ((dptr = allocate_structure_data()) == (TCMBDATAPTR) 0)
		return( allocation_failure() );
	if ((dptr->type = allocate_for_type( vtype, vsize, vone, vtwo, (VPTR) 0 )) == (TCTYPPTR) 0)
		return( allocation_failure() );

	mptr->special = (VPTR)dptr;
	mptr->nature  = vmem;

	if ( xptr != (TCMEMBERPTR) 0) 
		return( replace_member( sptr, xptr, mptr ) );
	else	return( add_member( sptr, mptr ) );
}

WORD	add_structure_method(vname,type)
BPTR		vname;
VPTR       	type;
{
	TCSTRUCTPTR	sptr;
	TCMEMBERPTR	mptr;
	TCMEMBERPTR	xptr;
	trace("add_structure_method()\n");
	if ((sptr = World->CurrentStructure) == (TCSTRUCTPTR) 0)
		return( internal_error(111) );
	else if (((xptr = locate_member(sptr,	vname)) != (TCMEMBERPTR) 0)
	     &&  ( sptr->nature != _KW1_CLASS ))
		return( symbol_already_defined(vname) );
	else if ((mptr = allocate_structure_member( vname )) == (TCMEMBERPTR) 0)
		return( allocation_failure() );
	mptr->special = type;
	establish_method_member((mptr->special = type),mptr);
	if ( xptr != (TCMEMBERPTR) 0)
		return( replace_member( sptr, xptr, mptr ) );
	else	return( add_member( sptr, mptr ) );
}

WORD	add_structure_constant( vname, type, value )
BPTR	vname;
WORD	type;
BPTR	value;
{
	TCSTRUCTPTR	sptr;
	TCMEMBERPTR	mptr;
	TCMEMBERPTR	xptr;
	TCTYPPTR	tptr;

	trace("add_structure_constant()\n");
	if ((sptr = World->CurrentStructure) == (TCSTRUCTPTR) 0)
		return( internal_error(111) );
	else if (((xptr = locate_member(sptr,	vname)) != (TCMEMBERPTR) 0)
	     &&  ( sptr->nature != _KW1_CLASS ))
		return( symbol_already_defined(vname) );
	else if ((mptr = allocate_structure_member( vname )) == (TCMEMBERPTR) 0)
		return( allocation_failure() );

	mptr->nature = _KW1_CONST;
	
	if (((tptr = allocate_for_type( type, strlen( value ), 1, 1, (VPTR) 0)) == (TCTYPPTR) 0)
	||  ((mptr->special = (VPTR) allocate_structure_const( value, tptr)) == (VPTR) 0)) {
		liberate_structure_member( mptr );
		return( allocation_failure() );
		}
	else	if ( xptr != (TCMEMBERPTR) 0)
		return( replace_member( sptr, xptr, mptr ) );
	else	return( add_member( sptr, mptr ) );

}

VOID	unnamed_structure( sptr )
BPTR	sptr;
{
	strcpy(TokenBuffer,sptr);
	return;
}

WORD	add_member_structure( sptr, nptr, nature, type )
TCSTRUCTPTR	sptr;		/* Target Host Structure	*/
BPTR		nptr;		/* Structure of this member	*/
WORD		nature;		/* Nature DCL, PTR, CONST, ARG 	*/
WORD		type;		/* STRUCT UNION or CLASS	*/
{
	WORD		check;
	BPTR		xptr;
	WORD		status;
	TCMBDATAPTR	dptr;
	TCSTRUCTPTR	zptr;
	TCMEMBERPTR	mptr;
	TCMEMBERPTR	wptr;

	trace("add_member_structure()\n");

	if ((xptr = allocate_for_string( nptr )) == (BPTR) 0)
		return( allocation_failure() );

	if (( nature != _KW1_PTR )
	&&  ( nature != _KW1_OVL )
	&&  ((zptr = locate_structure( xptr )) != (TCSTRUCTPTR) 0))
		return( illegal_recursivity( xptr, 1 ) );

	if ((!( check = is_mnemonic("AS") ))
	&&  ( get_token() )) {
		/* Named Structure */
		/* --------------- */
		if (((wptr = locate_member( sptr, TokenBuffer )) != (TCMEMBERPTR) 0)
		&&  ( sptr->nature != _KW1_CLASS ))
			return( symbol_already_defined(TokenBuffer) );
		else	{
			/* Build Named Member Instance */
			/* --------------------------- */
			if (((mptr = allocate_structure_member( TokenBuffer )) != (TCMEMBERPTR) 0)
			&&  ((dptr = allocate_structure_data()) != (TCMBDATAPTR) 0)) {
				mptr->nature = nature;
				dptr->structname = xptr;
				mptr->special = (VPTR)dptr;

				/* Collect explicite field information */
				/* ----------------------------------- */
				if ( is_equals() )
					dptr->field = integer_expression();

				/* Collect member instance construction */
				/* ------------------------------------ */
				if (( sptr->nature == _KW1_CLASS )
				&&  ( is_left_brace()            )
				&&  ((dptr->construction = collect_construction_parameters()) == (TCTEXTPTR) 0))
					return( allocation_failure() );

				/* ADD or REPLACE class member */
				/* --------------------------- */
				if (wptr == (TCMEMBERPTR) 0) {
					if ((status = add_member( sptr, mptr )) != 0)
						return( status );
					}
				else if ((status = replace_member( sptr, wptr, mptr )) != 0)
					return( status );

				/* Check for defined Now */
				/* --------------------- */
				if ( is_mnemonic( "AS" ) )
					return( define_structure( xptr, type ) );
				else	return(0);
				}
			return( allocation_failure() );
			}
		}
	else	{
		unnamed_structure( xptr );

		/* Build Un-Named Member Instance */
		/* ------------------------------ */
		if (((mptr = allocate_structure_member(TokenBuffer)) != (TCMEMBERPTR) 0)
		&&  ((dptr = allocate_structure_data()) != (TCMBDATAPTR) 0)) {
			mptr->nature = nature;
			dptr->structname = xptr;
			mptr->special = (VPTR)dptr;

			/* Collect Construction parameters */
			/* ------------------------------- */
			if (( sptr->nature == _KW1_CLASS )
			&&  ( is_left_brace()            )
			&&  ((dptr->construction = collect_construction_parameters()) == (TCTEXTPTR) 0))
				return( allocation_failure() );

			/* ADD or REPLACE un-named class instance */
			/* -------------------------------------- */
			if ((wptr = locate_member( sptr, TokenBuffer)) == (TCMEMBERPTR) 0) {
				if ((status = add_member( sptr, mptr )) != 0) {
					liberate( xptr );
					return( status );
					}
				}

			else if ((status = replace_member( sptr, wptr, mptr )) != 0) {
				liberate( xptr );
				return( status );
				}

			if ( check )
				return( define_structure( xptr, type ) );
			else	return(0);
			}
		else	(void) allocation_failure();
		}

	liberate( xptr );
	return( 30 );
}


/*
 *	T R A N S L A T E _ S T R U C T U R E ()
 *	----------------------------------------
 *
 *	Entry from	:
 *	
 *		TRABAL.translate_code_or_data
 *
 *	To translate a structure instance (declaration) instruction.
 *
 *	[ DCL | PTR ] STRUCT
 *				<structure_name>
 *
 *						<instance_name>
 *
 */

WORD	translate_structure( nature, type )
WORD	nature;		/* DCL, PTR, CONST, ARG */
WORD	type;
{
	TCTEXTPTR	valptr=(TCTEXTPTR) 0;
	TCSTRUCTPTR	sptr;
	TCMBDATAPTR	dptr;
	BPTR		nptr;
	BPTR		xptr;
	BYTE		vname[64];
	WORD		check;
	WORD		status;
	WORD		field=0;

	trace("translate_structure()\n");

	/* Structure identifier required */
	/* ----------------------------- */
	if (!( get_token() ))
		return( syntax_error(737) );

	else if ((sptr = World->CurrentStructure) != (TCSTRUCTPTR) 0 ) {
		if ( type != sptr->nature )
			return( syntax_error(738) );
		else	return( add_member_structure(sptr, TokenBuffer, nature, type ) );
		}
	else if ((sptr = known_structure( TokenBuffer )) == (TCSTRUCTPTR) 0) {
		if ((xptr = allocate_for_string( TokenBuffer )) == (BPTR) 0)
			return( allocation_failure() );
		check = is_mnemonic( "AS" );
		if ((!( get_token() ))
		||  (!( copy_token((nptr = vname), 32 ) )))
			nptr = "\0";
		if ((!( check ))
		&&  (!( is_mnemonic("AS") )))
			return( expected_keyword("AS") );
		else if (((Context->DclStruct = allocate_structure_member( nptr )) == (TCMEMBERPTR) 0)
		     ||  ((dptr = allocate_structure_data()) == (TCMBDATAPTR) 0))
			return( allocation_failure() );
		Context->DclStruct->special = (VPTR)dptr;
		Context->DclStruct->nature = nature;
		dptr->structname = xptr;
		return( define_structure( xptr, type ) );
		}	
	else if ( type != sptr->nature )
		return( syntax_error(739) );
	else if ((!( get_token() ))
	     ||  (!( copy_token( vname, 32 ) )))
		vname[0] = 0;

	if ( is_equals() )
		field = integer_expression();

	if (( sptr->nature == _KW1_CLASS )
	&&  ( is_left_brace()            )
	&&  ((valptr = collect_construction_parameters()) == (TCTEXTPTR) 0))
		return( allocation_failure() );
	else 	{
		status = declare_instance( sptr, vname, nature, 0, 0, valptr, field );
		valptr = liberate_text_value( valptr );
		return( status );
		}
}

/*
 *	Called from TRPROC whilst analysing procedure parameters.
 *
 */

WORD	translate_instance_option( mode )
WORD	mode;
{
	WORD	nature;
	if ( is_mnemonic("POINTER") )
		nature = _KW1_PTR;
	else if ( is_mnemonic("OVERLAY") )
		nature = _KW1_OVL;
	else	nature = mode;
	return( nature );
}



WORD	translate_structured_parameter( vptr, vtype, type, sptr )
TCVARPTR	vptr;		/* HOST variable node 		*/
WORD		vtype;		/* Prepared Variable Type	*/
WORD		type;		/* UNION CLASS or STRUCT 	*/
TCSTRUCTPTR	sptr;
{
	WORD		nature;
	WORD		xnature=MOINS_UN;

	if  (!( sptr->size ))
		if (( locate_structure( TokenBuffer ) == (TCSTRUCTPTR) 0)
		&&  ((sptr->size =  structure_occupation(sptr)) == 0)
		&&   (sptr->first == (TCMEMBERPTR) 0))
			return( syntax_error(754) );

	if ((sptr->access & _MEMBER_OVERLAY)
	&& (!(sptr->enhanced & _ENHANCED_INDIRECT )))
		nature = _KW1_IND;
	else if (OtrOption.Enhanced & _ENHANCED_PARAMETERS)
		xnature = nature = _KW1_DCL;
	else	xnature = nature = _KW1_OBJ;

	if ((nature = translate_instance_option(nature)) == MOINS_UN)
		return( syntax_error(755) );
	if ( xnature == nature  )
		(void) issue_warning( 10 );
	if ( nature == _KW1_DCL )
		vtype = 0x0008;
	else	vtype = 0x9008;

	if (!( get_token() ))
		unnamed_structure( sptr->name );
	if ((vptr->name = allocate_for_token( TokenBuffer )) == (BPTR) 0)
		return( allocation_failure() );
	else 	vptr->hash = keyword_hash( TokenBuffer );
	if ((vptr->type = allocate_for_type( (vtype | 0x0013) , (sptr->access & _MEMBER_OVERLAY ? 10 : sptr->size), 1, 1, sptr )) == (TCTYPPTR) 0)
		return( allocation_failure() );
	else	return( 0 );

}

WORD	translate_struct_parameter( vptr, vtype, type )
TCVARPTR	vptr;		/* HOST variable node 		*/
WORD		vtype;		/* Prepared Variable Type	*/
WORD		type;		/* UNION CLASS or STRUCT 	*/
{
	TCSTRUCTPTR	sptr;
	trace("translate_struct_parameter()\n");

	/* Structure identifier required */
	/* ----------------------------- */
	if (!( get_token() ))
		return( syntax_error(751) );
	else if ((sptr = known_structure( TokenBuffer )) == (TCSTRUCTPTR) 0)
		return( syntax_error(752) );
	else if ( type != sptr->nature )
		return( syntax_error(753) );
	else if ( sptr->virtual )
		return( syntax_error( 1030 ) );
	else	return( translate_structured_parameter( vptr, vtype, type, sptr ) );
}

WORD	implicite_struct_parameter( vptr, vtype )
TCVARPTR	vptr;		/* HOST variable node 		*/
WORD		vtype;		/* Prepared Variable Type	*/
{
	TCSTRUCTPTR	sptr;
	if ((sptr = known_structure( TokenBuffer )) != (TCSTRUCTPTR) 0)
		return( translate_structured_parameter( vptr, vtype, sptr->nature, sptr ) );
	else	return( MOINS_UN );
}

WORD	generate_struct_parameter( vptr )
TCVARPTR	vptr;
{
	TCSTRUCTPTR		sptr;
	TCMEMBERPTR		mptr;
	TCMBDATAPTR		dptr;
	WORD			level=0;
	struct tcode_field 	HoldField;
	struct tcode_field 	UnionField;
	WORD			status=0;
	WORD			adjust=1;
	WORD			master;

	trace("generate_struct_parameter()\n");

	if ((sptr = (TCSTRUCTPTR) vptr->type->class) == (TCSTRUCTPTR) 0)
		return( syntax_error(750) );
	else if ((mptr = sptr->first) == (TCMEMBERPTR) 0)
		return( 0 );
	else if (( sptr->size == 0)
	     &&  ((sptr->size =  ll_structure_occupation(sptr,mptr)) == 0)
	     &&  ( sptr->first == (TCMEMBERPTR) 0))
		return(syntax_error(751) );

	copy_field( & HoldField, Context->ThisField );

	if ((status = redefine_base_variable( vptr )) != 0)
		return( status );
	else	master = vptr->identity;

	if  ( sptr->access & _MEMBER_OVERLAY ) {

		if ((status =  redefine_overlay_object( sptr, vptr->name, (level+adjust), vptr->identity )) != 0)
			return( syntax_error( 5000 ) );

/*		if ( sptr->enhanced & _ENHANCED_INDIRECT )
 *			master = Context->LDT->variable->identity;
 */

		}

	/* Establish Unified Memory Start if required */
	/* ------------------------------------------ */
	if ( sptr->nature == _KW1_UNION )
		copy_field( & UnionField, Context->ThisField );

	do	{

		if ( mptr->access & _MEMBER_COMMON )
			if ( OtrOption.ExternCommon )
				continue;

		if (!( mptr->nature )) {
			if ((status = declare_member(sptr,mptr,(level+adjust),master,object_occupation(sptr))) != 0)
				return( status );
			else	continue;
			}
		else if ( mptr->nature == _KW1_CONST )
			continue;
		else if ((dptr = (TCMBDATAPTR) mptr->special) == (TCMBDATAPTR) 0)
			return( internal_error( 676 ) );

		if ( dptr->structname != (BPTR) 0 ) {

			if ((dptr->structure == (TCSTRUCTPTR) 0)
			&&  ((dptr->structure = known_structure( dptr->structname )) == (TCSTRUCTPTR) 0))
				return( syntax_error(752) );

//			else if ( mptr->access & _MEMBER_COMMON )	// #BG
//				continue;

			else if ( mptr->access & _MEMBER_INHERIT ) {
				if ((status = declare_static_inheritance( dptr->structure, master )) != 0)
					return( status );
				}
			else if ((status = declare_structure(dptr->structure,mptr->name,mptr->nature,(level+adjust),master,dptr->construction,dptr->field)) != 0)
				return( status );
			}
		else if ((status = declare_member(sptr,mptr,(level+adjust),master,( sptr->access & _MEMBER_OVERLAY ? 10 : sptr->size ))) != 0)
			return( status );

		/* Reposition to start of UNION if required */
		/* ---------------------------------------- */
		if (( sptr->nature == _KW1_UNION )
		&&  ( adjust ))
			copy_field( Context->ThisField, & UnionField );
		}
	while ((mptr = mptr->next) != (TCMEMBERPTR) 0);
	copy_field( Context->ThisField, & HoldField );
	return(0);
}

WORD	verify_structure_type( type, nptr )
WORD	type;	/* UNION, CLASS, STRUCT */
BPTR	nptr;	/* Name of structure	*/
{
	TCSTRUCTPTR	sptr;
	if ((sptr = known_structure( nptr )) == (TCSTRUCTPTR) 0)
		return( syntax_error(753) );
	else if ( type != sptr->nature )
		return( syntax_error(754) );
	else	return( 0 );
}

static	WORD	inherit_dynamic_member( mptr, sptr )
TCMEMBERPTR	mptr;
TCSTRUCTPTR	sptr;
{
	TCMBDATAPTR	dptr;
	TCSTRUCTPTR	class;
	WORD		status;
	if (((class = mptr->class) != (TCSTRUCTPTR) 0)
	&&  ( class->access & _MEMBER_GENERIC )
	&&  ((dptr = (TCMBDATAPTR)mptr->special) != (TCMBDATAPTR) 0)) {
		switch ( mptr->nature ) {
			case _KW1_IND   :
			case _KW1_CMN   :
			case _KW1_OBJ   :
			case _KW1_OVL   :
			case _KW1_DCL	:
			case _KW1_PTR   :
			case _KW1_ARG   :
				if ((dptr->structname != (BPTR) 0)
				&&  (compare_tokens( dptr->structname, class->name ))) {
					liberate( dptr->structname );
					if ((dptr->structname = allocate_for_string( sptr->name ))  == (BPTR) 0)
						return( allocation_failure() );
					dptr->structure = sptr;
					}
				break;
			case _KW1_CONST :
				break;
			default		: 
				if ((status = inherit_dynamic_method( (TCMBMETHPTR)dptr, class, sptr )) != 0)
					return( status );
				else	break;
			}
		}
	mptr->class = sptr;
	return( 0 );
}

static	WORD		overload_member( sptr, mptr )
TCSTRUCTPTR		sptr;
TCMEMBERPTR		mptr;
{
	WORD		status=0;
	TCMEMBERPTR	xptr;
	TCMEMBERPTR	nptr;
	trace("overload_member( "); trace( mptr->name ); trace(" )\n");
#ifdef	_INSPECT_OVERLAOD
	if (!( mptr->nature ))
		sysprintf("Inherit Method %s \n",mptr->name);
	else if ( mptr->nature == _KW1_CONST )
		sysprintf("Inherit Const  %s \n",mptr->name);
	else	sysprintf("Inherit Data   %s \n",mptr->name);
#endif
	if ((nptr = copy_member( mptr )) == (TCMEMBERPTR) 0)
		return( allocation_failure() );
	else if ( mptr->access & _MEMBER_DYNAMIC )
		if ((status = inherit_dynamic_member( nptr, sptr )) != 0)
			return( status );
	if ((xptr = locate_member( sptr, mptr->name )) != (TCMEMBERPTR) 0)
		return( replace_member( sptr, xptr, nptr ) );
	else	return( add_member( sptr, nptr ) );
}

static	WORD		overload_members( sptr, iptr )
TCSTRUCTPTR	sptr;
TCSTRUCTPTR	iptr;
{
	TCMEMBERPTR	mptr;
	WORD		status;
	trace("overload_members()\n");
	if ((mptr = iptr->first) != (TCMEMBERPTR) 0) {
		do	{
			if ((status = overload_member(sptr,mptr)) != 0)
				return( status );
			}
		while ((mptr = mptr->next) != (TCMEMBERPTR) 0);
		}
	return( 0 );
}

WORD	static_inheritance( sptr, iptr )
TCSTRUCTPTR	sptr;
TCSTRUCTPTR	iptr;
{
	TCMEMBERPTR	mptr;
	TCMBDATAPTR	dptr;
	WORD		status;

	if ((mptr = allocate_structure_member(iptr->name)) == (TCMEMBERPTR) 0)
		return( allocation_failure() );
	else if ((dptr = allocate_structure_data()) == (TCMBDATAPTR) 0)
		return( allocation_failure() );
	else if ((dptr->structname = allocate_for_string( iptr->name )) == (BPTR) 0)
		return( allocation_failure() );

	dptr->structure  = iptr;
	mptr->nature     = _KW1_DCL;
	mptr->special    = (VPTR)dptr;
	
	mptr->access |= _MEMBER_INHERIT;

	if ((status = add_member( sptr, mptr )) != 0)
		return( status );
	else	return( overload_members( sptr, iptr ) );

}

WORD	delayed_inheritance(sptr, iptr )
TCSTRUCTPTR	sptr;
TCSTRUCTPTR	iptr;
{
	TCMEMBERPTR	mptr;
	TCMBDATAPTR	dptr;
	WORD		status;

	trace("delayed_inheritance()\n");

	if ((mptr = allocate_structure_member(iptr->name)) == (TCMEMBERPTR) 0)
		return( allocation_failure() );
	else if ((dptr = allocate_structure_data()) == (TCMBDATAPTR) 0)
		return( allocation_failure() );
	else if ((dptr->structname = allocate_for_string( iptr->name )) == (BPTR) 0)
		return( allocation_failure() );

	dptr->structure  = iptr;
	mptr->nature     = _KW1_DCL;
	mptr->special    = (VPTR)dptr;
	
	mptr->access |= _MEMBER_DELAYED;

	if ((status = add_member( sptr, mptr )) != 0)
		return( status );
	else	return( 0 ) ;

}


WORD	perform_inheritance( sptr, nptr )
TCSTRUCTPTR	sptr;
BPTR		nptr;
{
	TCSTRUCTPTR	iptr;

	trace("perform_inheritance()\n");

	if  ((iptr = known_structure( nptr)) == (TCSTRUCTPTR) 0)
		return( syntax_error(1755) );
	else if (Context->Started == 2)
		return( delayed_inheritance( sptr, iptr ) );

	if ( sptr->dll != (TCDLBPTR) 0 ) {
		if (( iptr->dll != (TCDLBPTR) 0)
		&&  (!( compare_tokens( iptr->dll->name, sptr->dll->name ) )))
			return( syntax_error( 6477 ) );
		}
	else 	sptr->dll = iptr->dll;

	if (iptr->access & _MEMBER_DYNAMIC)
		return( overload_members( sptr, iptr ) );
	else	return( static_inheritance( sptr , iptr ) );
}

WORD	inherit_struct( nptr )
BPTR	nptr;
{
	TCSTRUCTPTR	sptr;
	trace("inherit_struct( "); trace( nptr ); trace(" )\n");
	if ((sptr = World->CurrentStructure) == (TCSTRUCTPTR) 0 )
		return( syntax_error(755) );
	else	return( perform_inheritance( sptr, nptr ) );
}

WORD	translate_instance()
{
	TCSTRUCTPTR	sptr;
	TCSTRUCTPTR	hptr;
	TCTEXTPTR	vptr=(TCTEXTPTR) 0;
	BYTE		vname[64];
	WORD		nature;
	WORD		status;
	WORD		field=0;

	if ((sptr = known_structure( TokenBuffer)) == (TCSTRUCTPTR) 0)
		return( MOINS_UN );

	if (sptr->virtual)
		return( syntax_error( 1030 ) );

	trace("translate_instance( "); trace( TokenBuffer ); trace(" )\n");

	if ((sptr->access & _MEMBER_OVERLAY)
	&& (!(sptr->enhanced & _ENHANCED_INDIRECT )))
		nature = _KW1_IND;
	else	nature = _KW1_OBJ;

	if ((nature = translate_instance_option(nature)) == MOINS_UN)
		return( syntax_error(756) );

/*
	<class_name> 

	[ OVERLAY | POINTER ] 

	[ ( <first> , <second> ) ] 

	<instance_name> 

	[ =<field_expression> ]

	[ ( <construction> ) ]


	if ( is_left_brace() ) {


		if ( is_comma() ) {

			}

		if (!( is_right_brace() )) {

			}
		}

 */

	if ((hptr = World->CurrentStructure) != (TCSTRUCTPTR) 0 )
		return( add_member_structure(hptr, sptr->name, nature, sptr->nature ) );

	if ((!( get_token() ))
	||  (!( copy_token( vname, 32 ) )))
		vname[0] = 0;

	/* Collect explicite Memory Field and convert nature if required */
	/* ------------------------------------------------------------- */
	if (( is_equals() )
	&&  ((field = integer_expression()) != 0)) {
		if ( nature == _KW1_OBJ )
			nature = _KW1_DCL;
		else if ( nature == _KW1_IND )
			return( syntax_error( 891 ) );
		}

	/* Collect explicite construction parameters if class */
	/* -------------------------------------------------- */
	if (( sptr->nature == _KW1_CLASS )
	&&  ( is_left_brace()            )
	&&  ((vptr = collect_construction_parameters()) == (TCTEXTPTR) 0))
		return( allocation_failure() );
	else 	{
		status = declare_instance( sptr, vname, nature, 0, 0, vptr, field );
		vptr = liberate_text_value( vptr );
		return( status );
		}
}

WORD	translate_base_instance(nature)
WORD	nature;
{
	TCSTRUCTPTR	sptr;
	TCSTRUCTPTR	hptr;

	trace("translate_base_instance()\n");

	if ((sptr = known_structure( TokenBuffer)) == (TCSTRUCTPTR) 0)
		return( MOINS_UN );

	if ( sptr->virtual )
		return( syntax_error( 1030 ) );

	if ((!( class_enhanced_indirect( sptr ) ))
	&&  ( sptr->access & _MEMBER_OVERLAY)
	&&  ( nature == _KW1_DCL ))
		nature = _KW1_IND;

	trace("translate_base_instance( "); trace( TokenBuffer ); trace(" )\n");

	if ((hptr = World->CurrentStructure) != (TCSTRUCTPTR) 0 )
		return( add_member_structure(hptr, sptr->name, nature, sptr->nature ) );
	else	return( syntax_error(757) );

}


WORD	translate_object_data( optr, mptr, vname )
TCVARPTR	optr;
TCMEMBERPTR	mptr;
BPTR		vname;
{
	TCMBDATAPTR	dptr;
	TCVARPTR	vptr;

	trace("translate_object_data("); 
	trace( optr->name ); trace("."); trace( mptr->name );
	trace(")\n");

	if (((vptr = resolve_member_variable( optr, vname, mptr->hash )) == (TCVARPTR) 0)
	||  ((dptr = (TCMBDATAPTR)mptr->special) == (TCMBDATAPTR) 0))
		return( internal_error( 757 ) );
	if (( dptr->structname == (BPTR) 0 ) 
	||  (!( is_period() )) )
		return( translate_terminal_member( vptr ) );
	else	return( translate_object_member( vptr ) );

}

TCMEMBERPTR	resolve_baseclass_member( optr, object, class, nptr )
TCVARPTR XPTR	optr;
TCVARPTR	object;
TCSTRUCTPTR	class;
BPTR		nptr;
{
	TCMEMBERPTR	member;
	TCMEMBERPTR	wptr;
	TCVARPTR	componant;
	WORD		valid=1;

	if ((member = class->first) != (TCMEMBERPTR) 0) {

		trace("resolve_baseclass_member("); trace( nptr ); trace(")\n");

		/* Attempt to find a member of a Base Class */
		/* ---------------------------------------- */
		do	{
			valid = 1;
			if (( member->nature )
			&&  ( member->nature != _KW1_CONST )
			&&  ((class = base_class_componant( member )) != (TCSTRUCTPTR) 0)) {
				if ((componant = resolve_member_componant( object, member )) == (TCVARPTR) 0) {
					if ( structure_occupation( class ) == 0 ) {
						(void) internal_error( 5000 );
						return((TCMEMBERPTR) 0);
						}
					else	{
						componant = object;
						valid = 0;
						}
					}
				if ((wptr = locate_member( class /* dptr->structure */, nptr )) != (TCMEMBERPTR) 0) {
					*optr = componant;
					return( wptr );
					}
				else if ((valid) && ((wptr = resolve_baseclass_member( optr, componant, class /* dptr->structure */ , nptr )) != (TCMEMBERPTR) 0))
					return( wptr );
				}
			}
		while ((member = member->next) != (TCMEMBERPTR) 0);
		}
	return( member );
}


TCMEMBERPTR	locate_baseclass_member( optr, object, class, nptr, level )
TCVARPTR XPTR	optr;
TCVARPTR	object;
TCSTRUCTPTR	class;
BPTR		nptr;
WORD		level;		/* Initial Entry componant may be private */
{
	TCMEMBERPTR	member;
	TCMEMBERPTR	wptr;
	TCVARPTR	componant;
	WORD		valid=1;

	if ((member = class->first) != (TCMEMBERPTR) 0) {

		trace("locate_baseclass_member("); trace( nptr ); trace(")\n");

		/* Attempt to find a member of a Base Class */
		/* ---------------------------------------- */
		do	{
			if (( level )
			&& (!( member->access & _MEMBER_PUBLIC )))
				continue;
			if (( member->nature )
			&&  ( member->nature != _KW1_CONST )
			&&  (!( member->access & _MEMBER_INHERIT ))
			&&  ((class = base_class_componant( member )) != (TCSTRUCTPTR) 0)
			&&  ((componant = resolve_member_componant( object, member )) != (TCVARPTR) 0)) {
				if ((wptr = locate_member( class /* dptr->structure */, nptr )) != (TCMEMBERPTR) 0) {
					*optr = componant;
					return( wptr );
					}
				else if ((wptr = locate_baseclass_member( optr, componant, class, nptr,(level + 1) )) != (TCMEMBERPTR) 0)
					return( wptr );
				}
			}
		while ((member = member->next) != (TCMEMBERPTR) 0);
		}
	return( member );
}

TCMEMBERPTR	locate_class_member( optr, nptr )
TCVARPTR XPTR	optr;
BPTR		nptr;
{
	TCVARPTR	object;
	TCSTRUCTPTR	class;
	TCMEMBERPTR	member;

	trace("locate_class_member("); trace( nptr ); trace(")\n");

	if (( optr            == (TCVARPTR XPTR) 0)
	||  ((object = *optr )   == (TCVARPTR)  0 )
	||  ( object->type       == (TCTYPPTR) 0  )
	||  ((class = (TCSTRUCTPTR) object->type->class) == (TCSTRUCTPTR) 0))
		return( (TCMEMBERPTR) 0 );

	/* First attempt to find a member of this class */
	/* -------------------------------------------- */
	if ((member = locate_member( class, nptr )) != (TCMEMBERPTR) 0)
		return( member );

	/* This is required in order to find LOCAL COMMON members */
	/* ------------------------------------------------------ */
	else if (( member = locate_common_object( nptr, (TCSTRUCTPTR) 0,class )) != (TCMEMBERPTR) 0)
		return( member );

	/* Now attempt to find a member of a BASE CLASS of this class */
	/* ---------------------------------------------------------- */
	else	return( locate_baseclass_member(optr,object,class,nptr,0) );

}

RESULTPTR	evaluate_constant_member( cptr )
TCMBCONSTPTR	cptr;
{
	RESULTPTR	rptr;
	if (( cptr == (TCMBCONSTPTR) 0)
	||  ( cptr->type == (TCTYPPTR) 0))
		return( (RESULTPTR) 0 );
	else 	{
		switch (( cptr->type->type & _TYPE_BASIC )) {
			case _TYPE_STRING  : 
				if ((rptr = allocate_for_result()) == (RESULTPTR) 0)
					return( rptr );
				else	return(build_string_constant( rptr, cptr->value ));
			case _TYPE_NUMERIC :
				if ((rptr = allocate_for_result()) == (RESULTPTR) 0)
					return( rptr );
				else	return(build_numeric_term( rptr, cptr->value ));
			case _TYPE_INT8	   :
			case _TYPE_INT16   :
			case _TYPE_INT32   :
				return( integer_result( convert_numeric_token( cptr->value ) ) );
			default		   :
				return( (RESULTPTR) 0 );
			}
		}
}

WORD	encapsulation_violation( world, class, member )
TCVARPTR	world;
TCSTRUCTPTR	class;
TCMEMBERPTR	member;
{
	TCSTRUCTPTR	worldclass=(TCSTRUCTPTR) 0;
	TCFRIENDPTR	fptr;

	trace("encapsulation_violation(?)\n");

	if ( member->access & _MEMBER_PUBLIC )
		return( 0 );
	else if ( *class->name == '@' )
		return( 0 );
	else if ((world != (TCVARPTR) 0)
	     &&  (world->type != (TCTYPPTR) 0)
	     &&  ((worldclass = (TCSTRUCTPTR) world->type->class) != (TCSTRUCTPTR) 0)
	     &&  ( worldclass->hash == class->hash )
	     &&  ( compare_tokens( worldclass->name, class->name ) ))
			return( 0 );
	else if (((fptr = class->friend) != (TCFRIENDPTR) 0)
	     &&  ( worldclass != (TCSTRUCTPTR) 0)) {
		do	{
			if ( compare_tokens( fptr->name, worldclass->name ) )
				return( 0 );
			}
		while ((fptr = fptr->next) != (TCFRIENDPTR) 0);
		}
	return( syntax_error( 1000 ) );

}

WORD		expand_member_constant( cptr )
TCMBCONSTPTR	cptr;
{
	trace("expand_member_constant()\n");
	if (( cptr != (TCMBCONSTPTR) 0 )
	&&  ( cptr->value != (BPTR) 0 )) {
		strcpy(TokenBuffer, cptr->value );
		TokenHash = keyword_hash( TokenBuffer );
		}
	return( 0 );
}

WORD	legal_member_access( access, level )
WORD	access;
WORD	level;
{
	if (!( level ))
		return( VRAI );
	else if ( access & _MEMBER_PUBLIC )
		return( VRAI );
	else 	return( FAUX );
} 

WORD		expand_base_class_constant( class, level )
TCSTRUCTPTR	class;
WORD		level;
{
	WORD		status;
	TCMEMBERPTR	member;
	TCSTRUCTPTR	sptr;
	if ((member = class->first) != (TCMEMBERPTR) 0) {
		do	{
			if (( member->nature )
			&&  ( member->nature != _KW1_CONST )
			&&  ( legal_member_access( member->access, level ) )
			&&  ((sptr = base_class_componant( member )) != (TCSTRUCTPTR) 0)
			&&  ((status = expand_class_constant( sptr,(level+1) )) != MOINS_UN))
				return( status );
			}
		while ((member = member->next) != (TCMEMBERPTR) 0);
		}
	return( MOINS_UN );
}

WORD		expand_class_constant( class, level )
TCSTRUCTPTR	class;
WORD		level;
{
	TCMEMBERPTR	member;
	if ((member = class->first) != (TCMEMBERPTR) 0) {
		do	{
			if ((TokenHash == member->hash)
			&&  (compare_tokens( TokenBuffer, member->name ))) {
				if ( member->nature == _KW1_CONST )
					return( expand_member_constant( member->special ) );
				else	return( syntax_error( 8994 ) );
				} 
			}
		while ((member = member->next) != (TCMEMBERPTR) 0);
		}
	return( expand_base_class_constant( class, level ) );
}

WORD	expand_object_member( object )
TCVARPTR	object;
{
	WORD		status;
	TCVARPTR	world;
	TCMEMBERPTR	member;
	WORD		depth=0;

	world = object;
	while (1) {
		trace("expand_object_member("); trace( object->name );
		trace( " . " ); trace( TokenBuffer ); trace(")\n");

		if  ((member = locate_class_member( (TCVARPTR XPTR) & object, TokenBuffer )) == (TCMEMBERPTR) 0)
			break;

		if (!( member->nature ))
			return( expand_method_token( object,member,member->special ) );
		else if ( member->nature == _KW1_CONST ) {
			if ((status = expand_member_constant( member->special )) != MOINS_UN)
				return( status );
			else	return( FAUX );
			}
		/* Do not probe into depth */
		else	return( FAUX );
		}
	if ( depth )		
		return( syntax_error( 8997 ) );
	else	return( FAUX );
}

static	WORD	expand_sizeof()
{
	TCSTRUCTPTR	class;
	if (!( ll_get_token() ))
		return( syntax_error(8995) );
	else if ((class = known_structure( TokenBuffer )) == (TCSTRUCTPTR) 0)
		return( syntax_error( 8996 ) );
	sprintf(TokenBuffer,"%u",structure_occupation( class ));
	TokenHash = keyword_hash( TokenBuffer );
	return( FAUX );
}


WORD	expand_class_number()
{
	TCVARPTR	object;
	TCSTRUCTPTR	class;

	if  ((object = (TCVARPTR)input_object()) != (TCVARPTR) 0) {
		if  ((class  = (TCSTRUCTPTR)object->type->class) != (TCSTRUCTPTR) 0)
			sprintf(TokenBuffer,"%u",class->number);
		else	strcpy(TokenBuffer,"0");
		}

	else if ((class = World->CurrentStructure) != (TCSTRUCTPTR) 0)
		sprintf(TokenBuffer,"%u",class->number);

	else	strcpy(TokenBuffer,"0");

	TokenHash = keyword_hash( TokenBuffer );
	return( FAUX );
}

WORD	expand_this()
{
	if ( uppercase_compare(TokenBuffer,"THIS" )) {
		strcpy(TokenBuffer,"THIS");
		TokenHash = keyword_hash( TokenBuffer );
		}
	return( FAUX );
}

WORD		expand_member()
{
	TCVARPTR	object;
	TCSTRUCTPTR	class;
	WORD		status=FAUX;

	if ( uppercase_compare(TokenBuffer,"SIZEOF" ))
		return( expand_sizeof() );
	else if ( uppercase_compare( TokenBuffer, "CLASS_NUMBER" ) )
		return( expand_class_number() );
	else if ((object = (TCVARPTR)input_object()) != (TCVARPTR) 0)
		return( expand_object_member( object ) );

	else if ((class = World->CurrentStructure) != (TCSTRUCTPTR) 0) {
		do	{
			/* Avoid Auto Unions */
			/* ----------------- */
			if ( *class->name != '@' ) {
				if ((status = expand_class_constant( class, 0  ) ) != MOINS_UN)
					return( status );
				else	return( FAUX );
				}
			}
		while ((class = class->next) != (TCSTRUCTPTR) 0);
		}
	return( FAUX );
}

TCVARPTR	resolve_member_componant( object, member )
TCVARPTR	object;
TCMEMBERPTR	member;
{
	TCMEMBERPTR	common;
	trace("resolve_member_componant()\n");
	if ( member->access & _MEMBER_COMMON ) {
		if ( member->common != (TCVARPTR) 0 )
			return( temp_variable( member->common ) );
		else if ((common = locate_common_member( member->class, member )) == (TCMEMBERPTR) 0)
			return( (TCVARPTR) 0 );
		else 	return( temp_variable((member->common = common->common)) );
		}
	else 	return( resolve_member_variable( object, member->name, member->hash ) );
}

WORD			resolve_member_term( world, object, member, mode )
TCVARPTR		world;
TCVARPTR XPTR		object;
TCMEMBERPTR XPTR	member;
WPTR			mode;
{
	TCVARPTR	eptr;
	BPTR		tptr;
	TCSTRUCTPTR	cptr;
	WORD		depth=0;
	TCMEMBERPTR	mptr;
	TCMBDATAPTR	dptr;
	WORD		status;
	TCVARPTR	optr;

	if ((optr = *object) == (TCVARPTR) 0)
		return(syntax_error( 13131 ) );
	else	{
		eptr = optr;
		cptr = (TCSTRUCTPTR)optr->type->class;
		}

	*mode = VRAI;

	while ( 1 ) {

		trace("resolve_member_term("); trace( optr->name ); 
		trace("."); trace( TokenBuffer );
		trace(")\n");

	/* --------------------------------------------------------- */
	/* Scan current object class, and base class,  member lists  */
	/* for a match with the current token in TokenBuffer	     */
	/* Failure to find a match will raise an error if the depth  */
	/* is greater than zero otherwise simply indicate not member */
	/* --------------------------------------------------------- */
		if ((mptr = locate_class_member( (TCVARPTR XPTR) & optr, TokenBuffer )) == (TCMEMBERPTR) 0)
			break;

	/* --------------------------------- */
	/* Check for Encapsulation Violation */
	/* --------------------------------- */
		else if ((status = encapsulation_violation(world,optr->type->class,mptr)) != 0)
			break;

	/* -----------------------------------------------------*/
	/* Constant and Methods are Terminal : Return to Caller */
	/* -----------------------------------------------------*/
		else if ((!(mptr->nature))
		     ||  ( mptr->nature == _KW1_CONST )) {
			*member = mptr;
			*object = optr;
			return( 0 );
			}


	/* ------------------------------------------------------------ */
	/* Perform Conversion to Uppercase and attempt to locate the	*/
	/* Variable Table Control Structure representing this member	*/
	/* variable 							*/
	/* ------------------------------------------------------------ */
		else if ((optr = resolve_member_componant( optr, mptr )) == (TCVARPTR) 0) {
			status = internal_error( 1919 );
			break;
			}

	/* ------------------------------------------------------------ */
	/* Collect Member data control node and detect structural 	*/
	/* members which may require further in depth probing		*/
	/* ------------------------------------------------------------ */
		if ((dptr = (TCMBDATAPTR)mptr->special) == (TCMBDATAPTR) 0) {
			status = internal_error( 929 );
			break;
			}

		else if (( dptr->structname == (BPTR) 0 )
		     ||  (!( is_period() ))) {
			*member = mptr;
			*object = optr;
			return( 0 );
			}
		if ( is_period() )
			*mode = FAUX;

		if (!( ll_get_token() )) {
			status = syntax_error(759);
			break;
			}
		else 	depth++;
		}

	if (( depth ) && (!( status ))) {
		if ((tptr = allocate_for_string( TokenBuffer )) != (BPTR) 0) {
			sprintf(TokenBuffer,"%s(%s).%s",eptr->name,cptr->name,tptr);
			liberate( tptr );
			}
		return( syntax_error(760) );
		}
	else	return( status );

}

RESULTPTR	evaluate_method_pointer( optr, member )
TCVARPTR	optr;
TCMEMBERPTR	member;
{
	if (!( is_method_pointer( member->special ))) {
		(void) syntax_error( 1329 );
		return( (RESULTPTR) 0 );
		}

	else if (( optr = resolve_member_componant( optr, member )) == (TCVARPTR) 0) {
		(void) internal_error( 1328 );
		return( (RESULTPTR) 0 );
		}
	return( variable_result( collect_dimensions(optr) ) );

}

RESULTPTR	evaluate_member_term( optr, funcptr )
TCVARPTR	optr;
WORD		funcptr;
{
	RESULTPTR	rptr=(RESULTPTR) 0;
	TCMEMBERPTR	mptr=(TCMEMBERPTR) 0;
	WORD		status;
	WORD		mode;

/*	sysprintf("evaluate_member_term( %s . %s )\n",optr->name,TokenBuffer );	*/

	/* Attempt to resolve "TokenBuffer" as an object member */
	/* ---------------------------------------------------- */
	if (((status = resolve_member_term( input_object(),(TCVARPTR XPTR) & optr, (TCMEMBERPTR XPTR) & mptr, (WPTR) & mode)) != 0)
	||  ( mptr == (TCMEMBERPTR) 0))
		return( (RESULTPTR) 0 );

	/* ------------------------------------------------------------ */
	/* Detect and Handle Method   Members : Activate Method 	*/
	/* ------------------------------------------------------------ */
	else if (!( mptr->nature )) {

		if ( funcptr )
			return( evaluate_method_term( optr, mptr, mptr->special, mode ) );
		else	return( evaluate_method_pointer( optr, mptr ) );

		}

	/* ------------------------------------------------------------ */
	/* Detect and Handle Constant Members : Build Constant		*/
	/* ------------------------------------------------------------ */
	if ( mptr->nature == _KW1_CONST )
		return( evaluate_constant_member(mptr->special) );

	/* ------------------------------------------------------------ */
	/* It must be and OBJECT or a Variable: Build Variable		*/
	/* ------------------------------------------------------------ */
	else	return( variable_result( collect_dimensions(optr) ) );

}

static	RESULTPTR	evaluate_alias_operator( operation, lterm, rterm )
BPTR			operation;
RESULTPTR		lterm;
RESULTPTR		rterm;
{
	TCTYPPTR	tptr;
	TCVARPTR	object;
	TCSTRUCTPTR	class;
	TCMEMBERPTR	member;

	trace("evaluate_alias_operator(");
	trace( operation ); trace(")\n");

	if (((tptr = register_alias( lterm->contents )) != (TCTYPPTR) 0)
	&&  ((class = (TCSTRUCTPTR) tptr->class) != (TCSTRUCTPTR) 0)
	&&  ((member = locate_member( class, operation )) != (TCMEMBERPTR) 0)
	&&  ((object = dcl_object_alias( tptr, lterm->value )) != (TCVARPTR) 0)) {
		lterm->nature &= ~_RESULT_POINTER;
		(void) clf_alias( variable_result(object), lterm );
		return( evaluate_method_operator( object, class, member, rterm ) );
		}
	return((RESULTPTR) 0);
}

TCMEMBERPTR	locate_operator_member( class, optr, mode, operand )
TCSTRUCTPTR	class;
BPTR		optr;
WORD		mode;
RESULTPTR	operand;
{
	TCMEMBERPTR	mptr;
	WORD		h;

	trace("locate_operator_member()\n");

	if (( class != (TCSTRUCTPTR) 0)
	&&  ((mptr = class->first) != (TCMEMBERPTR) 0)) {
		h = keyword_hash( optr );
		do	{
			if ((!( mptr->nature ))
			&&  ( h == mptr->hash )
			&&  ( compare_tokens( mptr->name, optr ) ))
				if ( verify_operator_parameter( mptr->special, operand ) )
					break;
			}
		while (( mptr = mptr->next ) != (TCMEMBERPTR) 0);
		}
	return( mptr );
}

RESULTPTR	evaluate_object_operator( opcode, lterm, rterm, mode, nature )
WORD		opcode;
RESULTPTR	lterm;
RESULTPTR	rterm;
WORD		mode;
WORD		nature;
{
	BYTE		operation[8];
	TCVARPTR	object=(TCVARPTR) 0;
	TCSTRUCTPTR	class;
	TCMEMBERPTR	member;

	operation[0] = (BYTE) opcode;
	operation[1] = 0;

/*	sysprintf("evaluate_object_operator( %s : %u, %x )\n",operation,mode,nature);	*/

	if ((lterm->nature & _RESULT_BASIC) == _RESULT_VARB )
		object = (TCVARPTR) lterm->contents;
	else  if ( lterm->nature == (_RESULT_ALEXPR) )
		return( evaluate_alias_operator( operation, lterm, rterm ) );
	else if (( lterm->nature & _RESULT_BASIC) == _RESULT_EXPR )
		object = register_variable( lterm->contents );

	if (( object != (TCVARPTR) 0)
	&&  ( object->type != (TCTYPPTR) 0)
	&&  ((nature |= (object->type->type & (_TYPE_DEFINED | _TYPE_OVERLAY)) ))
	&&  ((class = (TCSTRUCTPTR) object->type->class) != (TCSTRUCTPTR) 0)
	&&  ((member = locate_operator_member( class, operation, mode, rterm )) != (TCMEMBERPTR) 0))
		return( evaluate_method_operator( object, class, member, rterm ) );

	else if (!(mode))
		return( evaluate_object_operator( opposite_operator( opcode ),  rterm, lterm, VRAI, nature ) );

	else 	{
		if ( nature )
			issue_warning( 15 );
		return((RESULTPTR) 0);
		}
}

WORD	object_affectation( object, result )
TCVARPTR	object;
RESULTPTR	result;
{
	TCSTRUCTPTR	class;
	TCMEMBERPTR	member;
	if (( object != (TCVARPTR) 0 )
	&&  ( object->type != (TCTYPPTR) 0)
	&&  ( object->type->type & (_TYPE_DEFINED | _TYPE_OVERLAY) )
	&&  ((class = (TCSTRUCTPTR) object->type->class) != (TCSTRUCTPTR) 0)
	&&  ((member = locate_member( class, "=" )) != (TCMEMBERPTR) 0))
		return( method_affectation( object, class, member, result ) );
	else	return(MOINS_UN);
}


WORD	translate_object_member( optr )
TCVARPTR	optr;
{
	WORD		depth=0;
	RESULTPTR	rptr=(RESULTPTR) 0;
	TCMEMBERPTR	mptr;
	TCMBDATAPTR	dptr;
	TCVARPTR	vptr;
	TCVARPTR	world;
	WORD		status;
	WORD		mode=VRAI;

	world = (TCVARPTR)input_object();

	while ( 1 ) {

		trace("translate_object_member("); trace( optr->name ); 
		trace(" . "); trace(TokenBuffer);
		trace(")\n");

	/* --------------------------------------------------------- */
	/* Scan current object class, and base class,  member lists  */
	/* for a match with the current token in TokenBuffer	     */
	/* Failure to find a match will raise an error if the depth  */
	/* is greater than zero otherwise simply indicate not member */
	/* --------------------------------------------------------- */
		if ((mptr = locate_class_member((TCVARPTR XPTR) & optr, TokenBuffer )) == (TCMEMBERPTR) 0)
			break;

	/* --------------------------------- */
	/* Check for Encapsulation Violation */
	/* --------------------------------- */
		else if ((status = encapsulation_violation(world,optr->type->class,mptr)) != 0)
			return( status );

	/* ------------------------------------------------------------ */
	/* Detect Member Methods and return result of Method Evaluation */
	/* ------------------------------------------------------------ */
		else if (!( mptr->nature ))
			return( activate_object_method( optr, mptr, mode ) );

	/* ------------------------------------------------------------ */
	/* Detect and Handle Constant Members : Illegal Constant lvalue */
	/* ------------------------------------------------------------ */
		else if ( mptr->nature == _KW1_CONST )
			return( syntax_error( 777 ) );

	/* ------------------------------------------------------------ */
	/* Perform Conversion to Uppercase and attempt to locate the	*/
	/* Variable Table Control Structure representing this member	*/
	/* variable 							*/
	/* ------------------------------------------------------------ */
		else if ((vptr = resolve_member_componant( optr, mptr )) == (TCVARPTR) 0) {
			return( internal_error( 2929 ) );
			}

	/* ------------------------------------------------------------ */
	/* Collect Member data control node and detect structural 	*/
	/* members which may require further in depth probing		*/
	/* ------------------------------------------------------------ */
		if ((dptr = (TCMBDATAPTR)mptr->special) == (TCMBDATAPTR) 0)
			return(internal_error( 929 ));
		else if (( dptr->structname == (BPTR) 0 )
		     ||  (!( is_period() )))
			return( translate_terminal_member( vptr ) );

		if ( is_period() )
			mode = FAUX;

		if (!( ll_get_token() ))
			return( syntax_error(762) );
		else 	{
			trace("iterate\n");
			depth++;
			optr = vptr;
			}
		}

	if ( depth )
		return( syntax_error(763) );
	else	return( MOINS_UN );

}

WORD	translate_member_statement()
{
	TCVARPTR	optr;
	if ((optr = (TCVARPTR) input_object()) == (TCVARPTR) 0) 
		return( MOINS_UN );
	else	return( translate_object_member( optr ) );
}

WORD	translate_event_member()
{
	TCVARPTR	optr=(TCVARPTR) 0;
	TCMEMBERPTR	mptr=(TCMEMBERPTR) 0;
	WORD		status=0;
	WORD		mode=0;
	if ((optr = (TCVARPTR)input_object()) != (TCVARPTR) 0) {
		if ((status = resolve_member_term( optr,(TCVARPTR XPTR) & optr, (TCMEMBERPTR XPTR) & mptr, (WPTR) & mode)) != 0)
			return( status );
		}
	if ( mptr == (TCMEMBERPTR) 0) {
		if (((optr = is_object()) == (TCVARPTR) 0)
		||  (!( is_period() ))
		||  (!( get_token() )))
			return( syntax_error( 198 ) );
		else if ((status = resolve_member_term( optr,(TCVARPTR XPTR) & optr, (TCMEMBERPTR XPTR) & mptr, (WPTR) & mode)) != 0)
			return( status );
		else if ( mptr == (TCMEMBERPTR) 0)
			return( syntax_error( 198 ) );
		}

	if ( mptr->nature == _KW1_CONST )
		return( syntax_error( 198 ) );

	else if ( mptr->nature )
		return( event_call_variable( optr,0 ) );

	else	return( event_call_method( optr, mptr->class, mptr, mptr->special ) );
}

WORD	translate_instruction( object )
TCVARPTR	object;
{
	WORD	status;
	if (( object->type->type & _TYPE_DEFINED )
	&&  ( is_period() )) {
		if (!( ll_get_token() ))
			return( syntax_error(764) );
		else if ((status = translate_object_member( object )) != 0) {
			return( syntax_error(765) );
			}
		else	return( 0 );
		}
	else	return( translate_terminal_member( object ) );
}

WORD	translate_local_statement()
{
	TCVARPTR	vptr;
	if ((vptr = is_local_variable()) == (TCVARPTR) 0)
		return( MOINS_UN );
	else	return( translate_instruction( vptr ) );
}

WORD	translate_object_statement()
{
	TCVARPTR	optr;

	if ((optr = is_object()) != (TCVARPTR) 0)
		return( translate_instruction( optr ) );
	else	return( MOINS_UN );
}

TCVARPTR	resolve_parent_object( variable )
TCVARPTR	variable;
{
	TCVARPTR	vptr;

	trace("resolve_parent_object()\n");
	while ( variable->parent != (TCVARPTR) 0 )
		variable = variable->parent;

	if ((vptr = variable->next) != (TCVARPTR) 0) {
		do	{
			if ( vptr->identity == variable->master )
				return( vptr );
			}
		while ((vptr = vptr->next) != (TCVARPTR) 0);
		}
	return((TCVARPTR) input_object() );
}

WORD	build_method_pointer( target, method )
TCVARPTR	target;
VPTR		method;
{
	TCMEMBERPTR	member=(TCMEMBERPTR) 0;
	TCVARPTR	object=(TCVARPTR) 0;
	TCVARPTR	source=(TCVARPTR) 0;
	WORD		status;
	WORD		target_virtual;
	WORD		mode;

	trace("build_method_pointer()\n");

	target_virtual = is_method_pointer( method );

	if (!( is_left_brace() )) {

		/* CREATE <method_or_pointer> */
		/* -------------------------- */
		if ((object = resolve_parent_object( target )) == (TCVARPTR) 0)
			return( internal_error( 1329 ) );
		else if ((member = resolve_method_member( method )) == (TCMEMBERPTR) 0)
			return( internal_error( 1330 ) );
		else if ((status = affect_method_pointer( target, object, object->type->class, member, method )) != 0)
			return( status );

		if ( target_virtual & _METHOD_VIRTUAL )
			return( method_object_alias( target, object ) );
		else	return( 0 );

		}
	else	{
		/* ----------------------------------------------- */
		/* CREATE <method_pointer> ( <method_or_pointer> ) */
		/* ----------------------------------------------- */
		if ((object = (TCVARPTR)input_object()) == (TCVARPTR) 0)
			return( syntax_error( 1330 ) );
		else if (!( get_token() ))
			return( syntax_error( 1331 ) );
		else if ((status = resolve_member_term( object, (TCVARPTR XPTR) & object, (TCMEMBERPTR XPTR) & member, (WPTR) & mode )) != 0)
			return( status );
		else if ( member == (TCMEMBERPTR) 0 )
			return( syntax_error( 1332 ) );
		else if ( member->nature )
			return( syntax_error( 1333 ) );
		if (is_strict_method( method )) {
		     	while (!( compare_strict_methods( method, member->special ) )) {
				if ((member = locate_alternative_method( member->name, member->hash, member->next )) == (TCMEMBERPTR) 0)
					return( syntax_error( 1334 ) );
				}
			}
		else if (!( compare_strict_methods( method, member->special ) ))
			(void) issue_warning(7);

		if ( is_comma() )
			return( syntax_error( 1335 ) );
		if (!( is_right_brace() ))
			return( unmatched_braces() );

		/* Test if Source is Method Pointer */
		/* -------------------------------- */
		if ( is_method_pointer( member->special ) ) {
			if ((status = locate_method_pointer( object, member->special, & object, & source , member )) != 0)
				return( status );
			if ((status = generate_affectation( target, variable_result( source ),VRAI )) != 0)
				return( status );
			if (( member->access & (_MEMBER_VIRTUAL | _MEMBER_OVERLOAD) )
			&&  (!( target_virtual & _METHOD_VIRTUAL )))
				return( syntax_error( 1336 ) );
			}
		else if ((status = affect_method_pointer( target, object, object->type->class, member, member->special )) != 0)
			return( status );

		if ( target_virtual & _METHOD_VIRTUAL )
			return( method_object_alias( target, object ) );
		else	return( 0 );
		}

}

RESULTPTR	translate_class_name()
{
	TCVARPTR	object;
	TCSTRUCTPTR	class;
	BPTR		name;
	RESULTPTR	rptr;
	trace("translate_class_name()\n");
	if (((object = (TCVARPTR)input_object()) != (TCVARPTR) 0)
	&&  ((class  = (TCSTRUCTPTR)object->type->class) != (TCSTRUCTPTR) 0))
		name = class->name;
	else	name = " ";
	trace( name );
	if ((rptr = allocate_for_result()) != (RESULTPTR) 0)
		return( build_string_constant( rptr, name ) );
	else	return( rptr );
}

RESULTPTR	translate_class_number()
{
	TCVARPTR	object;
	TCSTRUCTPTR	class;
	WORD		number=0;

	trace("translate_class_name()\n");
	if (((object = (TCVARPTR)input_object()) != (TCVARPTR) 0)
	&&  ((class  = (TCSTRUCTPTR)object->type->class) != (TCSTRUCTPTR) 0))
		number = class->number;
	return( integer_result( number ) );
}

RESULTPTR	translate_object_number()
{
	TCVARPTR	object;

	if ((object = (TCVARPTR)input_object()) != (TCVARPTR) 0)
		return( integer_result( object->identity ) );
	else	return( integer_result( 0 ) );
}

RESULTPTR	translate_object_name()
{
	TCVARPTR	object;
	RESULTPTR	rptr;
	BPTR		name;

	if ((object = (TCVARPTR)input_object()) != (TCVARPTR) 0)
		name = object->name;
	else	name = " ";
	if ((rptr = allocate_for_result()) != (RESULTPTR) 0)
		return( build_string_constant( rptr, name ) );
	else	return( rptr );
}

RESULTPTR	translate_sizeof()
{
	TCSTRUCTPTR	class;
	if (( get_token() )
	&&  ((class = known_structure( TokenBuffer)) != (TCSTRUCTPTR) 0))
		return( integer_result( class->size ) );
	else	return( integer_result( 0 ) );
}

WORD	base_member_constant( token )
BPTR	token;
{
	TCSTRUCTPTR	sptr;
	TCMEMBERPTR	mptr;
	TCSTRUCTPTR	class;
	TCMEMBERPTR	member;
	TCMBCONSTPTR	cptr;
	if (((sptr = World->CurrentStructure) != (TCSTRUCTPTR) 0)
	&&  ((mptr = sptr->first) != (TCMEMBERPTR) 0)) {
		do	{
			if (( mptr->nature )
			&&  ( mptr->nature != _KW1_CONST )
			&&  ((class = base_class_componant( mptr )) != (TCSTRUCTPTR) 0)
			&&  ((member = class->first) != (TCMEMBERPTR) 0)) {				
				do	{
					if (( member->nature == _KW1_CONST ) 
					&&  ( compare_tokens( member->name, token ) )) {
		 				if (((cptr = (TCMBCONSTPTR) member->special) != (TCMBCONSTPTR) 0)
						&&  (((cptr->type->type & _TYPE_BASIC) <= _TYPE_INT16)
						  || ((cptr->type->type & _TYPE_BASIC) == _TYPE_INT32))
						&&  ( cptr->value != (BPTR) 0))
							return( convert_integer_token( cptr->value ) );
						else	return( 0 );
						}
					}
				while ((member = member->next) != (TCMEMBERPTR) 0);
				}
			}
		while ((mptr = mptr->next) != (TCMEMBERPTR) 0);
		}
	return( 0);
}


#include "trmacro.c"


VOID	trace_class_dependance( class, level, access )
TCSTRUCTPTR	class;
WORD		level;
WORD		access;
{
	TCSTRUCTPTR	sptr;
	TCMEMBERPTR	member;
	WORD	i=0;
	WORD	nombre=0;
	if ( !( level )) {
		sysprintf("Class ");
		if ( class->virtual )
			sysprintf("Virtual ");
		if ( class->access & _MEMBER_GENERIC )
			sysprintf("Generic ");
		}
	else 	{
		for ( i = 0; i < level; i++ )
			sysprintf("\t");
		if ( access & _MEMBER_PUBLIC )
			sysprintf("Public  ");
		else	sysprintf("Private ");
		if ( access & _MEMBER_COMMON ) {
			sysprintf("Common  ");
			if ((!( access & _MEMBER_PUBLIC ))  
			&&  (!( access & _MEMBER_DYNAMIC)))
				sysprintf("Static ");
			}
		}
	sysprintf("%s",class->name);
	show_class_source( class );

	if (( access & _MEMBER_PUBLIC )
	&&  ((member = class->first) != (TCMEMBERPTR) 0)) {
		do	{
			if (( member->nature )
			&&  ( member->nature != _KW1_CONST )
			&&  ((sptr = base_class_componant( member )) != (TCSTRUCTPTR) 0)) {
				if (nombre++)
					sysprintf(",\n");
				else	sysprintf("(\n");
				trace_class_dependance( sptr, (level+1), member->access );
				}
			}
		while ((member = member->next) != (TCMEMBERPTR) 0);
		if ( nombre ) 
			sysprintf(")");
		}
	if (!( level ))
		sysprintf("\n");
	return;
}


#endif	/* _TRSTRUCT_C */
	/* ----------- */



