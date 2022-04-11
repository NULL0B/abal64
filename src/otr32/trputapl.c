#ifndef	_TRPUTAPL_C
#define	_TRPUTAPL_C

#include "trsyntax.h"
/*	------------------------	----------------------------	*/
/*	ABAL++ OTR : VERSION 2.2	APL CLASS LIBRARY GENERATION	*/
/*	------------------------	----------------------------	*/

#ifndef	UNIX
static WORD	apl_put_member( TCMEMBERPTR );
#else
static WORD	apl_put_member();
#endif

static	WORD	apl_put_index( iptr, number )
APLIDXPTR	iptr;
WORD		number;
{
	apl_put_word( number );
	apl_put_string( iptr->class->name );
	apl_put_word( (iptr->class->access & _MEMBER_APL) 
#ifdef	ABAL32A
		| ( LibraryExtension == 2 ? _MEMBER_EXTERN : 0)
#endif
	 ); /* Remove Locked/Sized */
	apl_put_byte( iptr->class->nature );
	apl_put_word( iptr->class->enhanced );
	apl_put_word( iptr->class->virtual  );
	apl_put_word( iptr->class->explicite );
	apl_put_word( iptr->sector );
	apl_put_byte( iptr->offset );
	liberate( iptr );
	return( 0 );
}

static	WORD	apl_put_type( type )
TCTYPPTR	type;
{
	TCSTRUCTPTR	class;
	if (( type == (TCTYPPTR) 0 )
	||  ( type->type == MOINS_UN ))
		apl_put_word( MOINS_UN );
	else	{
		apl_put_word( type->type );
		if ( type->type & _TYPE_DEFINED ) {
			if ((class = (TCSTRUCTPTR)type->class) != (TCSTRUCTPTR) 0)
				apl_put_string( class->name );
			else	apl_put_byte( _APL_NULL );
			}
		else 	{
			if (( type->type & _TYPE_BASIC ) > _TYPE_INT16 ) {
				if (( type->type & _TYPE_BASIC ) != _TYPE_INT32 ) 
					apl_put_word( type->size );
				}
			if ( type->type & _TYPE_FIRST ) {
				apl_put_word( type->first );
				if ( type->type & _TYPE_SECOND )
					apl_put_word( type->second );
				}
			}
		}
	return( 0 );
}


static	WORD	apl_put_text( text )
TCTEXTPTR	text;
{
	WORD	status=0;
	WORD	c;

	if (( text != (TCTEXTPTR) 0)
	&&  ((status = establish_value_input( text->buffer )) == 0)) {

		while ((c = get_source_character()) != MOINS_UN)
			apl_put_byte( c );

		/* Remove Current Context */
		/* ---------------------- */
		(void) pop_source_context(1);
		}
	apl_put_byte( _APL_NULL );
	return( status );
}

static	WORD	apl_put_parameters( parameter )
TCVARPTR	parameter;
{
	while ( parameter != (TCVARPTR) 0 ) {
		apl_put_string( parameter->name );
		apl_put_type( parameter->type );
		apl_put_byte( parameter->access );
		parameter = parameter->next;
		}
	apl_put_byte( _APL_NULL );
	return( 0 );
}


static	WORD	apl_put_co_methods( mptr )
COMETHODPTR	mptr;
{
	while ( mptr != (COMETHODPTR) 0 ) {
		apl_put_byte( mptr->nature );
		apl_put_string( mptr->name );
		mptr = mptr->next;
		}
	apl_put_byte( _APL_NULL );
	return( 0 );
}

static	WORD	apl_put_members( member )
TCMEMBERPTR	member;
{
	WORD	status=0;
	if ( member != (TCMEMBERPTR) 0 ) {	
		do	{
			if ((status = apl_put_member( member )) != 0)
				return( status );
			}
		while ((member = member->next) != (TCMEMBERPTR) 0);
		}
	return( status );
}

static	WORD	apl_put_method_symbolic( method )
TCMBMETHPTR	method;
{
#ifndef	_APL_NOT_SYMBOLIC
	apl_put_word( apl_logical_handle( method->file ) );
	apl_put_word( method->line   );
	apl_put_long( method->offset );
#endif
	return( 0 );
}

static	WORD	apl_put_method( member, method )
TCMEMBERPTR	member;
TCMBMETHPTR	method;
{
	WORD	status;
	if ( OtrOption.ListFlag == 2 )
		sysprintf("Member Method   : %s \n",member->name);

	apl_put_byte( _APL_METHOD );
	apl_put_string ( member->name   );
	if ( OtrOption.Symbolic & 1 )
		apl_put_method_symbolic( method );
	apl_put_word( member->access & _MEMBER_APL );
	apl_put_byte( method->nature );
	apl_put_byte( method->special);
	apl_put_word( method->options);
	apl_put_type( method->type );
	apl_put_parameters( method->parameters );
	apl_put_co_methods( method->comethod   );
	if ( method->local != (TCSTRUCTPTR) 0 ) {
		if ((status = apl_put_members( method->local->first )) != 0)
			return( status );	
		}
	apl_put_byte( _APL_NULL );
	apl_put_text( method->value );
	return( 0 );
}

static	WORD	apl_put_constant( member, cptr )
TCMEMBERPTR	member;
TCMBCONSTPTR	cptr;
{
	if ( OtrOption.ListFlag == 2 )
		sysprintf("Member Constant : %s \n",member->name);

	apl_put_byte( _APL_CONST );
	apl_put_string ( member->name   );
	apl_put_word( member->access & _MEMBER_APL );
	apl_put_type( cptr->type );
	apl_put_string(  cptr->value  );
	return( 0 );
}

static	WORD	apl_put_data( member, type )
TCMEMBERPTR	member;
TCTYPPTR	type;
{
	if ( OtrOption.ListFlag == 2 )
		sysprintf("Member Variable : %s \n",member->name);

	apl_put_byte( _APL_DATA );
	apl_put_string ( member->name   );
	apl_put_word( member->access & _MEMBER_APL );
	apl_put_byte( member->nature );
	return( apl_put_type( type ) );
}

static	WORD	apl_put_object( member, dptr )
TCMEMBERPTR	member;
TCMBDATAPTR	dptr;
{
	if ( OtrOption.ListFlag == 2 )
		sysprintf("Member Instance : %s \n",member->name);

	apl_put_byte( _APL_OBJECT );
	apl_put_string ( member->name     );
	apl_put_word( member->access & _MEMBER_APL );
	apl_put_byte( member->nature   );
	apl_put_string ( dptr->structname );
	apl_put_word( dptr->field );
	return( apl_put_text( dptr->construction ) );
}

static	WORD	apl_put_baseclass( member, dptr )
TCMEMBERPTR	member;
TCMBDATAPTR	dptr;
{
	if ( OtrOption.ListFlag == 2 )
		sysprintf("BaseClass       : %s \n",member->name);

	apl_put_byte( _APL_BASECLASS );
	apl_put_string ( member->name   );
	apl_put_word( member->access & _MEMBER_APL );
	apl_put_byte( member->nature );
	return( apl_put_text( dptr->construction ) );
}

static	WORD	apl_put_inherit( member )
TCMEMBERPTR	member;
{
	if ( OtrOption.ListFlag == 2 )
		sysprintf("Inheritance     : %s \n",member->name);

	apl_put_byte( _APL_INHERIT );
	apl_put_string( member->name );
	return( 0 );
}

static	WORD	apl_put_componant( member, dptr )
TCMEMBERPTR	member;
TCMBDATAPTR	dptr;
{
	if ( member->access & _MEMBER_DELAYED )
		return( apl_put_inherit( member ) );
	else if ( dptr->structname == (BPTR) 0 )	
		return( apl_put_data( member, dptr->type ) );
	else if ( compare_tokens( member->name, dptr->structname ) )
		return( apl_put_baseclass( member, dptr ) );
	else	return( apl_put_object( member, dptr ) );
}

static	WORD	apl_put_member( member )
TCMEMBERPTR	member;
{
	if ( member != (TCMEMBERPTR) 0) {

		if (!( member->nature ))
			return( apl_put_method( member, member->special ) );
		else if ( member->nature == _KW1_CONST )
			return( apl_put_constant( member, member->special ));
		else	return( apl_put_componant( member, member->special ));

		}
	return( 0 );
}

static	WORD	apl_put_library( lptr )
TCDLBPTR	lptr;
{
	if ( lptr != (TCDLBPTR) 0 ) {

		if ( OtrOption.ListFlag == 2 )
			sysprintf("Library Record  : %s \n",lptr->name );

		apl_put_byte( _APL_LIBRARY );
		apl_put_string( lptr->name );
		apl_put_word( lptr->access );

		}
	return( 0 );
}

static	WORD	apl_put_friend( friend )
TCFRIENDPTR	friend;
{
	if ( OtrOption.ListFlag == 2 )
		sysprintf("Friend          : %s \n",friend->name);

	apl_put_byte( _APL_FRIEND );
	apl_put_string( friend->name );
	return( 0 );
}

static	WORD	initialise_class_record( class )
TCSTRUCTPTR	class;
{
	APLIDXPTR	iptr;

	if ( OtrOption.Verbose & 8 )
		sysprintf("Class Record    : %s \n",class->name);

	if ((iptr = (APLIDXPTR) allocate( sizeof ( struct apl_index_entry ) )) == (APLIDXPTR) 0)
		return( allocation_failure() );
	else	{
		iptr->class  = class;
		iptr->sector = current_target_sector();
		iptr->offset = current_sector_offset();
		iptr->next = AplIndex;
		AplIndex   = iptr;
		return( 0 );
		}
}

static	WORD	terminate_class_record( class )
TCSTRUCTPTR	class;
{
	if ( OtrOption.ListFlag == 2 )
		sysprintf("EndClass Record : %s \n\n",class->name);

	apl_put_byte( _APL_NULL );
	return( 0 );
}

static	WORD	apl_put_class( class )
TCSTRUCTPTR	class;
{
	TCMEMBERPTR	member;
	TCFRIENDPTR	friend;
	WORD		status;
#ifdef	ABAL32A
	if ( LibraryExtension )
		if ((status = library_extension_class( class )) != 0)
			return( status );
#endif
	if ((status = initialise_class_record( class )) != 0)
		return( status );

	else if ((member = class->first) != (TCMEMBERPTR) 0) {

		if ((status = apl_put_library( class->dll )) != 0 )
			return( status );
		else if (( status = apl_put_members( member )) != 0)
			return( status );

		if ((friend = class->friend) != (TCFRIENDPTR) 0) {
			do	{
				if ((status = apl_put_friend( friend )) != 0)
					return( status );
				}
			while ((friend = friend->next) != (TCFRIENDPTR) 0);
			}

		apl_put_byte( _APL_NULL );


		}
	return( terminate_class_record(class) );

}

static	WORD	apl_termination()
{
	WORD	status;
	pop_operation_pointer();
	if ((status = translate_end()) != 0)
		return( status );
#ifdef	ABAL32A
	else	return( instance_library_extension() );
#else
	else	return(status);
#endif
}

static	WORD	await_apl_termination()
{
	pop_operation_pointer();
	return(await_target_end());
}

static 	VOID	atoc_dependances()
{
#ifdef	WITH_ATOC
	TCAPLPTR	aptr;
	if ((aptr = AplRoot) != (TCAPLPTR) 0) {
		do	{
			if ( OtrOption.ListFlag == 2 )
				sysprintf("Apl   Record    : %s \n",aptr->name);
			atoc_dependance( aptr->name );
			}
		while ((aptr = aptr->next) != (TCAPLPTR) 0);
		}
#endif
	return;
}

static	WORD	apl_all_classes()
{
	TCSTRUCTPTR	class;
	WORD		status;

	if ((class = World->Structures) != (TCSTRUCTPTR) 0) {

#ifdef	WITH_ATOC
		if (!( OtrOption.Generate )) {
			atoc_create_library();
			atoc_dependances();
			}
#endif
		do	{
			if (!( is_member_library(class) )) {
#ifdef	WITH_ATOC
				if (!( OtrOption.Generate )) {
					if ((status = atoc_put_class( class )) != 0)
						break;
					}
				else 
#endif
					if ((status = apl_put_class( class )) != 0)
						break;
				}
			}
		while ((class = class->next) != (TCSTRUCTPTR) 0);

#ifdef	WITH_ATOC
		if (!( OtrOption.Generate ))
			atoc_close_library();
#endif
		}
	return( await_apl_termination() );
}

static	WORD	translate_library( )
{
	TCSTRUCTPTR	class;
	WORD		status=0;
	do	{
		if (!( get_token() ))
			return( 0 );
		else if (AplIndex == (APLIDXPTR) 0) {
		     	if  (uppercase_compare(TokenBuffer,"ALL"))
				return( apl_all_classes() );
			else if ( uppercase_compare(TokenBuffer, "CRYPT" )) {
				set_target_encryption( integer_expression() );
				continue;
				}
			}
		if ( uppercase_compare(TokenBuffer,"END") )
			return( apl_termination() );
		else if (((class = known_structure( TokenBuffer )) == (TCSTRUCTPTR) 0)
		     &&  ((status = syntax_error( 9402 )) != 0))
			break;
		else if ((status = apl_put_class( class )) != 0)
			break;
		}
	while ( is_comma() );
	return( status );
}

static	WORD	enter_library_translation()
{
	push_operation_pointer();
	set_operation_pointer(translate_library);
	return( 0 );
}

static	WORD	start_library()
{
	WORD	status;

	if ( Context->Started )
		return( syntax_error(675) );

	else if ((status = initialise_apl_output( Context->TcodeFileName )) != 0)
		return( status );

	if ( OtrOption.ListFlag & 1 )
		echo_library();

	if ( OtrOption.Verbose )
		sysprintf("LIBRARY \n");

	Context->Started = 2;
	return( 0 );
}

WORD	instance_library()
{
	WORD	status;
	WORD	type;
	if ( get_token() ) {

#ifdef	ABAL32A
		if ( is_class_keyword()  == _CLASS_OVERLAY) {
			if (!( get_token() ))
				return(syntax_error(229));
			else	LibraryExtension=1;
			}
		else if ( is_level1_keyword() == _KW1_MODULE ) {
			if (!( get_token() ))
				return(syntax_error(229));
			else	LibraryExtension=2;
			}
		else	LibraryExtension=0;
#endif
		tcode_program_identity();
		if (( status = start_library()) != 0)
			return( status );
		else	{
			generate_header( Context->identity, Context->options, MOINS_UN );
			if ((status = enter_library_translation()) != 0)
				return(status);
			else	return(0);
			}
		}
	else	return(syntax_error(229));
}

static	WORD	flush_apl_dependance()
{
	WORD		data_table_sector;
	WORD		status=0;
	TCAPLPTR	aptr;
	if ((aptr = AplRoot) != (TCAPLPTR) 0) {
		data_table_sector = current_target_sector();
		do	{
			if ( OtrOption.ListFlag == 2 )
				sysprintf("Apl   Record    : %s \n",aptr->name);
			apl_put_string( aptr->name );
			}
		while ((aptr = aptr->next) != (TCAPLPTR) 0);
		apl_put_byte( _APL_NULL );
		flush_sector();
		Context->paras_ETD  = data_table_sector;
		}
	else	Context->paras_ETD  = 0;
	return( status );
}

static	WORD	flush_apl_symbolic()
{
	WORD		data_table_sector;
	WORD		status=0;
	APLSYMBPTR	aptr;
	if ((aptr = AplSymbol) != (APLSYMBPTR) 0) {
		data_table_sector = current_target_sector();
		do	{
			symbolic_file_name( aptr->resolved, TokenBuffer );
			if ( strlen( TokenBuffer ) != 0 ) {
				if ( OtrOption.ListFlag == 2 )
					sysprintf("File Record     : %s \n",TokenBuffer);
				apl_put_string( TokenBuffer );
				apl_put_word( aptr->logical );
				}
			}
		while ((aptr = aptr->next) != (APLSYMBPTR) 0);
		apl_put_byte( _APL_NULL );
		flush_sector();
		Context->sector_SDT  = data_table_sector;
		apl_drop_symbols( AplSymbol );
		AplSymbol = (APLSYMBPTR) 0;
		}
	else	Context->sector_SDT  = 0;
	return( status );
}

WORD	flush_library_index_table()
{
	WORD		data_table_sector;
	WORD		number=0;
	WORD		status=0;

	APLIDXPTR	iptr;
	
	flush_sector();

	if ((status = flush_apl_dependance()) != 0)
		return( 0 );

	else if ((status = flush_apl_symbolic()) != 0)
		return( 0 );

	data_table_sector = current_target_sector();

	if ((iptr = AplIndex) != (APLIDXPTR) 0) {

		do	{
			AplIndex = iptr->next;
			if ((status = apl_put_index( iptr, number++ )) != 0 )
				break;
			}

		while (( iptr = AplIndex ) != (APLIDXPTR) 0);

		}

	/* End of Table Marker */
	/* ------------------- */
	apl_put_word( MOINS_UN );

	Context->megas_ETD  = get_target_encryption();
	Context->length_GCT = output_byte_count();

	flush_sector();

	return( data_table_sector );
}


#endif	/* _TRPUTAPL_C */
	/* ----------- */

