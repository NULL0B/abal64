/* _TRACE_COMMON */

#ifndef	_TRCOMMON_C
#define	_TRCOMMON_C

WORD	translate_common()
{
	Context->Visibility |= _MEMBER_COMMON;
	if ( OtrOption.PublicCommon )
		Context->Visibility |= _MEMBER_PUBLIC;
	return(0);
}

static	WORD	common_instance_nature( member, field )
TCMEMBERPTR	member;
WORD		field;
{
	if ( context_is_overlay ) {
		if ( field )
			return( _KW1_DCL );
		else	return( _KW1_PTR );
		}
	else if (( member->nature != _KW1_PTR )
	     &&  ( member->nature != _KW1_IND )
	     &&  ( member->nature != _KW1_OVL )) {
		if ( field )
			return( _KW1_DCL );
		else if ( member->access & _MEMBER_PUBLIC )
			return( _KW1_OBJ );
		else	return( _KW1_CMN );
		}
	else	return( member->nature );
}

TCMEMBERPTR	locate_common_member( class, member )
TCSTRUCTPTR	class;
TCMEMBERPTR	member;
{
	COMMONPTR	common;
	TCMEMBERPTR	mptr=(TCMEMBERPTR) 0;
#ifdef	_TRACE_COMMON
	sysprintf("locate_common_member(%s,%u:%u)\n",member->name,member->hash,(member->access & _MEMBER_PUBLIC));
#endif
	if ((common = (COMMONPTR)World->Common) != (COMMONPTR) 0) {
		do	{

			if ((mptr = common->member) == (TCMEMBERPTR) 0)
				continue;

#ifdef	_TRACE_COMMON
			sysprintf("\t member ? %s,%u:%u\n",mptr->name,mptr->hash,(mptr->access & _MEMBER_PUBLIC));
#endif
			/* Test if members match */
			/* --------------------- */
			if ((mptr->hash != member->hash)
			||  (!( compare_tokens( mptr->name, member->name ))))
				continue;

			/* PUBLIC COMMON : The member is unique */
			/* ------------------------------------ */
			if  (( mptr->access & _MEMBER_PUBLIC ))
				break;

#ifdef	_TRACE_COMMON
			sysprintf("\t class  ? %s,%u =?= %s,%u \n",
				class->name, class->hash,
				mptr->class->name,mptr->class->hash);
#endif
			/* PRIVATE COMMON : Verify correct class */
			/* ------------------------------------- */
			if (( class->hash == mptr->class->hash)
			&&  ( compare_tokens( class->name, mptr->class->name ) ))
				break;
			}
		while ((common = common->next) != (COMMONPTR) 0);
		}
	if ( common == (COMMONPTR) 0)
		return( (TCMEMBERPTR) 0 );
	else	return( common->member );

}

VOID	liberate_common_member( cptr )
COMMONPTR	cptr;
{
	if ( cptr != (COMMONPTR) 0 ) {
		if ( cptr->member != (TCMEMBERPTR) 0 )
			liberate_structure_member( cptr->member );
		liberate( cptr );
		}
	return;
}


TCMEMBERPTR	store_world_member( sptr, member )
TCSTRUCTPTR	sptr;
TCMEMBERPTR	member;
{
	COMMONPTR	common;

#ifdef	_TRACE_COMMON
	sysprintf("store_world_member(%s,%s)\n",sptr->name,member->name);
#endif
	if ((common = (COMMONPTR) allocate( sizeof ( struct tcode_common ) )) != (COMMONPTR) 0) {
		common->next = (COMMONPTR) 0;
		common->member = member;
		common->class  = member->class;
		common->scope  = World->Scope;
		if ( World->LastCommon == (COMMONPTR) 0)
			World->Common = common;
		else	World->LastCommon->next = common;
		World->LastCommon = common;
		return( member );
		}
	else	{
		liberate_common_member( common );
		return( (TCMEMBERPTR) 0 );
		}
}

TCMEMBERPTR	add_common_member( class, mptr )
TCSTRUCTPTR	class;
TCMEMBERPTR	mptr;
{
	TCMEMBERPTR	member;

	if  ((member = copy_member( mptr )) == (TCMEMBERPTR) 0)
		return( member );
	else 	return( store_world_member( class, member ) );
}

WORD	add_world_member( class, mptr )
TCSTRUCTPTR	class;
TCMEMBERPTR	mptr;
{
	TCMEMBERPTR	member;

	trace("add_world_member(");
	if ( class == (TCSTRUCTPTR) 0 ) {
		trace("<nulclass>");
		}
	else	{
		trace(class->name);
		}
	trace(","); trace(mptr->name); trace(")\n");

	if ((member = locate_common_member( class, mptr )) != (TCMEMBERPTR) 0)
		return( 0 );
	else if (add_common_member( class, mptr ) == (TCMEMBERPTR) 0)
		return( allocation_failure() );
	else	return( 0 );
}

WORD		declare_common_object( class, sptr, member, valptr, field )
TCSTRUCTPTR	class;
TCSTRUCTPTR	sptr;
TCMEMBERPTR	member;
TCTEXTPTR	valptr;
WORD		field;
{
	TCMEMBERPTR		common;
	TCVARPTR		optr;
	WORD			status;
	WORD			mastermode;
	WORD			nature;
	struct tcode_field 	HoldField;

	trace("declare_common_object("); trace( member->name ); trace(")\n");

	if ( member->common != (TCVARPTR) 0 )
		return( 0 );

	else if (((common = locate_common_member( class, member )) == (TCMEMBERPTR) 0)
	     &&  ((common = add_common_member( class, member )) == (TCMEMBERPTR) 0))
		return( allocation_failure() );

	else if ((member->common = common->common) != (TCVARPTR) 0)
		return( 0 );

	else if ( member->access & _MEMBER_PUBLIC ) {

		/* Public Common objects may be Predefined */
		/* --------------------------------------- */
		if (!( build_token( TokenBuffer, member->name ) ))
			return( syntax_error( 1005 ) );

		else if ((optr = is_object()) != (TCVARPTR) 0) {
			while ( optr->parent != (TCVARPTR) 0 ) 
				optr = optr->parent;
			common->common = member->common = optr;
			return( 0 );
			}
		}

	trace("declare_common_object("); trace( member->name ); trace(")\n");

	copy_field( & HoldField, Context->ThisField );
	if ((mastermode = (Context->scope & ISLOCAL)))
		field_equals_g();
	else	field_equals_r();

	optr = Context->GDT->variable;

	/* Note : PUBLIC is SYMBOL, PRIVATE is not SYMBOL */
	/* ---------------------------------------------- */
	nature = common_instance_nature( member, field );

	status = declare_structure( sptr, member->name, nature, (member->access & _MEMBER_DYNAMIC), 0, valptr, field );

	if ( mastermode )
		field_equals_l();
	else	field_equals_s();
	copy_field( Context->ThisField, & HoldField );

	if ( status )
		return( status );

	trace("post_resolve_common_object("); trace( member->name ); trace(")\n");

	if ( optr == (TCVARPTR) 0 )
		common->common = member->common = Context->GDT->first;
	else	common->common = member->common = optr->prev;

	return( 0 );

}

TCMEMBERPTR	build_common_object( nptr, sptr, nature, valptr, field)
BPTR		nptr;
TCSTRUCTPTR	sptr;
WORD		nature;
TCTEXTPTR	valptr;
WORD		field;
{
	TCMEMBERPTR	member;
	TCMBDATAPTR	dptr;
	WORD		type;

	trace("build_common_object("); trace( nptr ); trace(")\n");
	if ((member = allocate_structure_member( nptr )) != (TCMEMBERPTR) 0) {
		if ((member->nature = nature) == _KW1_PTR)
			type = (_TYPE_DEFINED | _TYPE_STRING | _TYPE_POINTER);
		else	type = (_TYPE_DEFINED | _TYPE_STRING );
		member->class = input_class();
		if ((dptr = allocate_structure_data()) != (TCMBDATAPTR) 0) {
			if ((dptr->structname = allocate_for_string( sptr->name )) != (BPTR) 0) {
				dptr->field	 = field;
				dptr->structure  = sptr;
				dptr->construction = copy_text_value( valptr );
				if ((dptr->type = allocate_for_type( type, sptr->size, 1, 1, sptr )) != (TCTYPPTR) 0) {
					member->special = (VPTR) dptr;
					return( store_world_member( member->class, member ) );
					}
				else	(void) allocation_failure();
				liberate( dptr->structname );
				}
			else	(void) allocation_failure();
			liberate_structure_data( dptr );
			}
		else	(void) allocation_failure();
		liberate_structure_member( member );
		}
	else	(void) allocation_failure();
	return( (TCMEMBERPTR) 0);
}

TCMEMBERPTR	build_common_terminal( nptr, type, size, first, second, nature )
BPTR		nptr;
WORD		type;
WORD		size;
WORD		first;
WORD		second;
WORD		nature;
{
	TCMEMBERPTR	member;
	TCMBDATAPTR	dptr;
	trace("build_common_terminal("); trace( nptr ); trace(")\n");
	if ((member = allocate_structure_member( nptr )) != (TCMEMBERPTR) 0) {
		if (( type & _TYPE_POINTER) == _TYPE_POINTER )
			member->nature  = _KW1_PTR;
		else	member->nature  = _KW1_DCL;
		member->class   = input_class();
		if ((dptr = allocate_structure_data()) != (TCMBDATAPTR) 0) {
			if ((dptr->type = allocate_for_type( type, size, first, second, (VPTR) 0)) != (TCTYPPTR) 0) {
				member->special = (VPTR) dptr;
				return( store_world_member( member->class, member ) );
				}
			else	(void) allocation_failure();
			liberate_structure_data( dptr );
			}
		else	(void) allocation_failure();
		liberate_structure_member( member );
		}
	else	(void) allocation_failure();
	return( (TCMEMBERPTR) 0);
}


TCMEMBERPTR	locate_common_object( vptr, class, sptr )
BPTR		vptr;	/* Name of instance	*/
TCSTRUCTPTR	class;	/* Class of object	*/
TCSTRUCTPTR	sptr;	/* Parent of member	*/
{
	COMMONPTR	common=(COMMONPTR) 0;

	if (( vptr != (BPTR) 0)
	&&  ((common = World->Common) != (COMMONPTR) 0)) {
		trace("locate_common_object("); trace( vptr ); trace(")\n");
		do	{
			if ( compare_tokens( common->member->name, vptr )) {
				if  ( common->member->access & _MEMBER_PUBLIC)
					break;
				else if ((sptr != (TCSTRUCTPTR) 0)
				     &&  ( sptr->hash == common->member->class->hash )
				     &&  ( compare_tokens( sptr->name, common->member->class->name )))
					break;
				}
			}
		while ((common = common->next) != (COMMONPTR) 0);
		}

	if ( common == (COMMONPTR) 0)
		return( (TCMEMBERPTR) 0 );
	else	return( common->member );
}

TCMEMBERPTR	locate_common_terminal( vptr )
BPTR		vptr;
{
	COMMONPTR	common=(COMMONPTR) 0;
	TCSTRUCTPTR	sptr;

	sptr = input_class();

	if (( vptr != (BPTR) 0)
	&&  ((common = World->Common) != (COMMONPTR) 0)) {
		do	{
			if ( compare_tokens( common->member->name, vptr )) {
				if  ( common->member->access & _MEMBER_PUBLIC)
					break;
				else if (( sptr->hash == common->member->class->hash )
				     &&	 ( compare_tokens( sptr->name, common->member->class->name ) ))
					break;
				}
			}
		while ((common = common->next) != (COMMONPTR) 0);
		}

	if ( common == (COMMONPTR) 0)
		return( (TCMEMBERPTR) 0 );
	else	return( common->member );
}


WORD	declare_world_member( member )
TCMEMBERPTR	member;
{
	WORD		status=0;
	WORD		nature;
	TCMBDATAPTR	dptr;
	TCVARPTR	variable;

	if (( member->nature == _KW1_CONST )
	||  ( member->common != (TCVARPTR) 0))
		return( 0 );
	else	variable = Context->GDT->variable;

	trace("dcl_world_member("); trace(member->name); trace(")\n");

	if (( member->nature )
	&&  ((dptr = (TCMBDATAPTR)member->special) != (TCMBDATAPTR) 0)
	&&  ( dptr->structname != (BPTR) 0 )) {

		if ((dptr->structure == (TCSTRUCTPTR) 0)
		&&  ((dptr->structure = known_structure( dptr->structname )) == (TCSTRUCTPTR) 0))
			return( internal_error( 8744 ) );

		/* Note : PUBLIC is SYMBOL, PRIVATE is not SYMBOL */
		/* ---------------------------------------------- */
		nature = common_instance_nature( member, dptr->field );

		if ((status = declare_structure( dptr->structure, member->name, nature ,(member->access & _MEMBER_PRIVATE),0,dptr->construction, dptr->field )) != 0)
			return( status );
		}

	else 	{
		member->lock |= _MEMBER_LOCKED;
		status = declare_member( member->class, member, (member->access & _MEMBER_PRIVATE),0,( member->class->access & _MEMBER_OVERLAY ? 10 : structure_occupation( member->class ) ));
		member->lock &= ~_MEMBER_LOCKED;
		if ( status )
			return( status );
		}
	if ( variable == (TCVARPTR) 0 )
		member->common = Context->GDT->first;
	else	member->common = variable->prev;

	return( 0 );
}

WORD	declare_module_common( member, sptr )
TCMEMBERPTR	member;
TCSTRUCTPTR	sptr;
{
	WORD		status=0;
	WORD		nature;
	TCMBDATAPTR	dptr;
	TCVARPTR	variable;
	WORD		first=0;

	if (( member->nature == _KW1_CONST )
	||  ( member->common != (TCVARPTR) 0))
		return( 0 );

	/* Ensure parameters are at least correct */
	/* -------------------------------------- */
	if ((!( sptr )) || (!( sptr->name )))
		return(0);
	if ((!( member->class )) || (!( member->class->name )))
		return(0);

	/* ensure common membor of required class */
	/* -------------------------------------- */
	if (!( compare_tokens( sptr->name, member->class->name )))
		return(0);

	/* IJM32A */
	/* ------ */
	if ( member->nature == _KW1_ARG ) {
		return(0);
	 	/* member->access |= _MEMBER_PUBLIC; */
		}

	if ( member->access & _MEMBER_PUBLIC ) {
		if (( status = add_external_field(MOINS_UN,'m',(BPTR) 0,(LONG)-1L)) != 0)
			return( status );
		if (!( Context->XDT ))
			variable = (TCVARPTR) 0;
		else	variable = Context->XDT->variable;
		}
	else 	variable = Context->GDT->variable;

	trace("dcl_world_member("); trace(member->name); trace(")\n");

	if (( member->nature )
	&&  ((dptr = (TCMBDATAPTR)member->special) != (TCMBDATAPTR) 0)
	&&  ( dptr->structname != (BPTR) 0 )) {

		if ((dptr->structure == (TCSTRUCTPTR) 0)
		&&  ((dptr->structure = known_structure( dptr->structname )) == (TCSTRUCTPTR) 0))
			return( internal_error( 8744 ) );

		/* Note : PUBLIC is SYMBOL, PRIVATE is not SYMBOL */
		/* ---------------------------------------------- */
		nature = common_instance_nature( member, dptr->field );

		if ((status = declare_structure( dptr->structure, member->name, nature ,(member->access & _MEMBER_PRIVATE),0,dptr->construction, dptr->field )) != 0)
			return( status );
		}

	else 	{
		member->lock |= _MEMBER_LOCKED;
		status = declare_member( member->class, member, (member->access & _MEMBER_PRIVATE),0,( member->class->access & _MEMBER_OVERLAY ? 10 : structure_occupation( member->class ) ));
		member->lock &= ~_MEMBER_LOCKED;
		if ( status )
			return( status );
		}


	if (!( member->access & _MEMBER_PUBLIC )) {
		if ( variable == (TCVARPTR) 0 )
			member->common = Context->GDT->first;
		else	member->common = variable->prev;
		return(0);
		}
	else	{
		if ( variable == (TCVARPTR) 0 )
			member->common = Context->XDT->first;
		else	member->common = variable->prev;
		return(close_extern_field(1));
		}
}

#endif	/* _TRCOMMON_C */
	/* ----------- */


