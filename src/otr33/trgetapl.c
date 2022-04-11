#ifndef	_TRGETAPL_C
#define	_TRGETAPL_C

/*	------------------------	-------------------------   	*/
/*	ABAL++ OTR : VERSION 2.2	APL CLASS LIBRARY LOADING   	*/
/*	------------------------	-------------------------   	*/

#ifndef	UNIX
static	WORD	apl_get_class_members( TCSTRUCTPTR, WORD );
static	WORD	apl_loader( BPTR );
#else
static	WORD	apl_get_class_members();
static	WORD	apl_loader();
#endif

static	TCSTRUCTPTR	apl_get_class()
{
	TCSTRUCTPTR	class=(TCSTRUCTPTR) 0;
	WORD		status;
	if ( apl_get_string() ) {
		trace("apl_get_class()\n");
		if ((class  = known_structure( TokenBuffer)) != (TCSTRUCTPTR) 0)
			return( class );
		else	{
			if (((status = open_structure_definition( TokenBuffer, _KW1_CLASS )) == 0  )
			&&  ((class  = World->CurrentStructure) != (TCSTRUCTPTR) 0)
			&&  ((status = close_structure_definition(class)) != 0))
				return( class );
			}
		}
	return((TCSTRUCTPTR) 0);
}

static	TCTYPPTR apl_get_type(mode)
WORD	mode;
{
	TCTYPPTR	tptr=(TCTYPPTR) 0;
	WORD		type;
	WORD		size=0;
	WORD		first=1;
	WORD		second=1;
	TCSTRUCTPTR	class=(TCSTRUCTPTR) 0;

	trace("apl_get_type()\n");
	if ((type = apl_get_word()) != MOINS_UN) {
		if ( type & _TYPE_DEFINED )
			class = apl_get_class();
		else	{
			if ((size = (type & _TYPE_BASIC)) > _TYPE_INT16) {
				if ( size > 4 ) 
					size = 4;
				else	size = apl_get_word();
				}
			else	size++;
			if ( type & _TYPE_FIRST ) {
				first = apl_get_word();
				if ( type & _TYPE_SECOND )
					second = apl_get_word();
				}
			}				
		}
	else if ( mode )
		return( (TCTYPPTR) 0 );
	return( allocate_for_type( type, size, first, second, class ) );
}

static	WORD	apl_get_data( class )
TCSTRUCTPTR	class;
{
	WORD		status=0;
	TCMEMBERPTR	mptr;
	TCMEMBERPTR	xptr;
	TCMBDATAPTR	dptr;

	trace("apl_get_data()\n");
	if ( apl_get_string()) {

		if (((xptr = locate_member(class,TokenBuffer)) != (TCMEMBERPTR) 0)
		&&  ( class->nature != _KW1_CLASS ))
			return( symbol_already_defined(TokenBuffer) );
		else if ((mptr = allocate_structure_member( TokenBuffer )) == (TCMEMBERPTR) 0)
			return( allocation_failure() );
		else if ((dptr = allocate_structure_data()) == (TCMBDATAPTR) 0)
			return( allocation_failure() );

		mptr->special = (VPTR)dptr;

		mptr->access = apl_get_word();
		mptr->nature = apl_get_byte();
		dptr->type   = apl_get_type(0);

		if ( OtrOption.ListFlag == 2 )
			sysprintf("Class Member : %s \n",TokenBuffer);
		
		if ( xptr != (TCMEMBERPTR) 0)
			return( replace_member( class, xptr, mptr ) );
		else	return( add_member( class, mptr ) );

		}
	return( syntax_error( 7007 ) );
}

static WORD	apl_get_text( method )
TCMBMETHPTR	method;
{
	WORD	c;
	WORD	status=0;

	trace("apl_get_text()\n");
	if (((c = apl_get_byte()) != 0)
	&&  ((status = push_operation_pointer()) == 0)
	&&  ((status = activate_method_target( method )) == 0)) {
		do	{
			if ((status = put_method_byte( c )) != 0)
				break;
			}
		while ((c = apl_get_byte()) != 0);
		}
	terminate_method_text();
	return( status );
}

static WORD	apl_get_value( dptr )
TCMBDATAPTR	dptr;
{
	WORD		c;
	WORD		status=0;
	TCTEXTPTR	tptr;

	trace("apl_get_value()\n");

	if ((c = apl_get_byte()) != 0) {

		if ((tptr = allocate_text_value()) == (TCTEXTPTR) 0)
			return( allocation_failure() );

		set_method_target( tptr->buffer );
		dptr->construction      = tptr;

		do	{
			if ((status = put_method_byte(c)) != 0)
				break;
			}
		while ((c = apl_get_byte()) != 0);

		set_method_target( (VALUEPTR) 0 );

		}
	return( status );

}

static	WORD	apl_get_baseclass( class )
TCSTRUCTPTR	class;
{
	WORD		status=0;
	TCMEMBERPTR	mptr;
	TCMEMBERPTR	xptr;
	TCMBDATAPTR	dptr;

	trace("apl_get_baseclass()\n");
	if ( apl_get_string()) {

		if (((xptr = locate_member(class,TokenBuffer)) != (TCMEMBERPTR) 0)
		&&  ( class->nature != _KW1_CLASS ))
			return( symbol_already_defined(TokenBuffer) );
		else if ((mptr = allocate_structure_member( TokenBuffer )) == (TCMEMBERPTR) 0)
			return( allocation_failure() );
		else if ((dptr = allocate_structure_data()) == (TCMBDATAPTR) 0)
			return( allocation_failure() );

		mptr->special = (VPTR)dptr;

		mptr->access = apl_get_word();
		mptr->nature = apl_get_byte();

		if ((dptr->structname = allocate_for_string( mptr->name )) == (BPTR) 0)
			return( allocation_failure() );

		if ((status = apl_get_value( dptr )) != 0)
			return( status );

		if ( OtrOption.ListFlag == 2 )
			sysprintf("BaseClass    : %s \n",mptr->name);;
		
		if ( xptr != (TCMEMBERPTR) 0)
			return( replace_member( class, xptr, mptr ) );
		else	return( add_member( class, mptr ) );

		}
	return( syntax_error( 7007 ) );
}

static	WORD	apl_get_object( class )
TCSTRUCTPTR	class;
{
	WORD		status=0;
	TCMEMBERPTR	mptr;
	TCMEMBERPTR	xptr;
	TCMBDATAPTR	dptr;

	trace("apl_get_object()\n");
	if ( apl_get_string()) {

		if (((xptr = locate_member(class,TokenBuffer)) != (TCMEMBERPTR) 0)
		&&  ( class->nature != _KW1_CLASS ))
			return( symbol_already_defined(TokenBuffer) );
		else if ((mptr = allocate_structure_member( TokenBuffer )) == (TCMEMBERPTR) 0)
			return( allocation_failure() );
		else if ((dptr = allocate_structure_data()) == (TCMBDATAPTR) 0)
			return( allocation_failure() );

		mptr->special = (VPTR)dptr;

		mptr->access = apl_get_word();
		mptr->nature = apl_get_byte();

		if (!( apl_get_string() ))
			return( syntax_error( 7007 ) );
		else if ((dptr->structname = allocate_for_string( TokenBuffer )) == (BPTR) 0)
			return( allocation_failure() );

		dptr->field  = apl_get_word();

		if ((status = apl_get_value( dptr )) != 0)
			return( status );

		if ( OtrOption.ListFlag == 2 )
			sysprintf("Object Member: %s \n",mptr->name);;
		
		if ( xptr != (TCMEMBERPTR) 0)
			return( replace_member( class, xptr, mptr ) );
		else	return( add_member( class, mptr ) );

		}
	return( syntax_error( 7007 ) );
}

static	WORD	apl_get_inherit( class )
TCSTRUCTPTR	class;
{
	trace("apl_get_inherit()\n");

	if ( apl_get_string() )
		return( perform_inheritance( class, TokenBuffer ) );
	else	return( syntax_error( 7007 ) );
}

static	WORD	apl_get_constant( class )
TCSTRUCTPTR	class;
{
	WORD		status=0;
	TCMEMBERPTR	mptr;
	TCMEMBERPTR	xptr;
	TCTYPPTR	tptr;
	TCMBCONSTPTR	cptr;

	trace("apl_get_constant()\n");
	if ( apl_get_string()) {

		if (((xptr = locate_member(class,TokenBuffer)) != (TCMEMBERPTR) 0)
		&&  ( class->nature != _KW1_CLASS ))
			return( symbol_already_defined(TokenBuffer) );
		else if ((mptr = allocate_structure_member( TokenBuffer )) == (TCMEMBERPTR) 0)
			return( allocation_failure() );

		mptr->access  = apl_get_word();
		mptr->nature  = _KW1_CONST;

		if (((tptr = apl_get_type(0)) != (TCTYPPTR) 0)
		&&  ( apl_get_string() )
		&&  ((cptr  = allocate_structure_const(TokenBuffer,tptr)) != (TCMBCONSTPTR) 0)) {
			mptr->special = (VPTR)cptr;
			if ( xptr != (TCMEMBERPTR) 0)
				return( replace_member( class, xptr, mptr ) );
			else	return( add_member( class, mptr ) );
			}

		}

	return( syntax_error( 7007 ) );

}

static	TCVARPTR	apl_get_parameters()
{
	TCVARPTR	root=(TCVARPTR) 0;
	TCVARPTR	last=(TCVARPTR) 0;
	TCVARPTR	vptr;
	WORD		status;

	trace("apl_get_parameters()\n");
	while ( apl_get_string() ) {
		trace("apl_get_parameter()\n");
		if (((vptr = allocate_for_variable()) == (TCVARPTR) 0)
		||  ((vptr->name = allocate_for_string( TokenBuffer )) == (BPTR) 0)
		||  (( vptr->type = apl_get_type(0)) == (TCTYPPTR) 0)) {
			status = allocation_failure();
			break;
			}
		else	{
			vptr->hash   = keyword_hash(vptr->name);
			vptr->access = (WORD) apl_get_byte();
			if ((vptr->prev = last) == (TCVARPTR) 0 )
				root = vptr;
			else 	last->next = vptr;
			last = vptr;
			}
		}
	return( root );
}

static	WORD	apl_get_co_methods( method  )
TCMBMETHPTR	method;
{
	COMETHODPTR	mptr=(COMETHODPTR) 0;
	COMETHODPTR	prev=(COMETHODPTR) 0;
	WORD		nature;

	while ((nature = apl_get_byte()) != _APL_NULL ) {
		trace("apl_get_co_method()\n");
		if (!( apl_get_string() ))
			return( syntax_error( 7007 ) );
		else if ((mptr = allocate_special_method(TokenBuffer, nature)) == (COMETHODPTR) 0)
			return( allocation_failure() );
		else	{
			if ( method->comethod == (COMETHODPTR) 0)
				method->comethod = mptr;
			else	prev->next       = mptr;
			prev = mptr;
			}
		}
	return( 0 );
}

static	WORD	apl_get_local( method )
TCMBMETHPTR	method;
{
	WORD		record;
	WORD		status=0;

	/* Detect Local member list present */
	if ((record = apl_get_byte()) == _APL_NULL)
		return( 0 );

	trace("apl_get_local()\n");

	if ((method->local = allocate_for_structure( "@local" )) == (TCSTRUCTPTR) 0)
		return( allocation_failure() );
	else	return( apl_get_class_members( method->local, record ) );
}

static	WORD	apl_get_method_symbolic( method )
TCMBMETHPTR	method;
{
#ifndef	_APL_NOT_SYMBOLIC
	method->file    = apl_resolved_handle( apl_get_word() );
	method->line    = apl_get_word();
	method->offset  = apl_get_long();
#else
	establish_method_symbolic( method );	
#endif
	return( 0 );
}


static	WORD	apl_get_method( class )
TCSTRUCTPTR	class;
{
	WORD		status=0;
	TCMEMBERPTR	mptr;
	TCMEMBERPTR	xptr;
	TCMBMETHPTR	method;

	trace("apl_get_method()\n");
	if ( apl_get_string()) {

		if (((xptr = locate_member(class,TokenBuffer)) != (TCMEMBERPTR) 0)
		&&  ( class->nature != _KW1_CLASS ))
			return( symbol_already_defined(TokenBuffer) );
		else if ((mptr = allocate_structure_member( TokenBuffer )) == (TCMEMBERPTR) 0)
			return( allocation_failure() );
		else if ((method = allocate_structure_method()) == (TCMBMETHPTR) 0)
			return( allocation_failure() );
		else if ( apl_option_symbolic() )
			apl_get_method_symbolic( method );
		else	establish_method_symbolic( method );

		mptr->special		= (VPTR)method;
		mptr->access 		= apl_get_word();
		method->member		= mptr;
		method->nature 		= apl_get_byte();
		method->special 	= apl_get_byte();
		method->options 	= apl_get_word();
		method->type 		= apl_get_type(1);
		method->parameters	= apl_get_parameters();

		if ((status = apl_get_co_methods( method )) != 0)
			return( status );
		else if ((status = apl_get_local( method )) != 0)
			return( status );
		else if ((status = apl_get_text( method )) != 0) 
			return( status );

		if ( OtrOption.ListFlag == 2 )
			sysprintf("Member Method: %s \n",mptr->name);

		if (( method->nature == _CLASS_USER )
		&&  ((status = add_user_function(method, MOINS_UN)) != 0))
			return( status );
		
		if ( xptr != (TCMEMBERPTR) 0)
			return( replace_member( class, xptr, mptr ) );
		else	return( add_member( class, mptr ) );

		}
	return( status );
}

static	WORD	apl_get_friend( class )
TCSTRUCTPTR	class;
{
	trace("apl_get_friend()\n");


	if ( apl_get_string() ) {
		if ( OtrOption.ListFlag == 2 )
			sysprintf("Friend Class : %s \n",TokenBuffer );
		return( add_friend( class, TokenBuffer ) );
		}
	else	return( syntax_error( 7007 ) );
}

static	WORD	apl_get_library( class )
TCSTRUCTPTR	class;
{
	TCDLBPTR	lptr;
	trace("apl_get_library()\n");

	if ( apl_get_string() ) {
		if ( OtrOption.ListFlag == 2 )
			sysprintf("Library      : %s \n",TokenBuffer );
		if ((lptr = locate_dynamic_library( TokenBuffer )) == (TCDLBPTR) 0)
			return( syntax_error( 7008 ) );
		lptr->access = apl_get_word();
		class->dll = lptr;
		return( 0 );
		}
	else	return( syntax_error( 7007 ) );
}

static	WORD	apl_get_class_members( class, record )
TCSTRUCTPTR	class;
WORD		record;
{
	WORD	status=0;

	trace("apl_get_class_members()\n");
	do	{
		switch ( record ) {

			case	_APL_DATA	:
				if ((status = apl_get_data(class)) == 0)
				continue;
				else	break;

			case	_APL_OBJECT	:
				if ((status = apl_get_object(class)) == 0)
					continue;
				else	break;

			case	_APL_BASECLASS	:
				if ((status = apl_get_baseclass(class)) == 0)
					continue;
				else	break;

			case	_APL_INHERIT	:
				if ((status = apl_get_inherit(class)) == 0)
					continue;
				else	break;

			case	_APL_CONST	:
				if ((status = apl_get_constant(class)) == 0)
					continue;
				else	break;

			case	_APL_METHOD	:
				if ((status = apl_get_method(class)) == 0)
					continue;
				else	break;

			case	_APL_FRIEND	:
				if ((status = apl_get_friend(class)) == 0)
					continue;
				else	break;

			case	_APL_LIBRARY	:
				if ((status = apl_get_library(class)) == 0)
					continue;
				else	break;

			default			:
				status = syntax_error( 7007 );
			}
		break;
		}
	while ((record = apl_get_byte()) != _APL_NULL );
	return( status );
}

static	WORD	apl_get_members( class )
TCSTRUCTPTR	class;
{
	WORD	status=0;
	WORD	record=0;

	trace("apl_get_members()\n");
	if ((record = apl_get_byte()) != _APL_NULL ) {

		status = apl_get_class_members( class, record );

		}
	return( status );
}

static	WORD	apl_get_classes(identity)
	BPTR	identity;
{
	TCSTRUCTPTR	class;
	WORD		number;
	WORD		status=0;
	WORD		sector;
	WORD		offset;
	WORD		holdsect;
	WORD		holdoffs;
	WORD		access;
	WORD		nature;


	if ( OtrOption.ListFlag == 2 )
		sysprintf("Loading Library : %s as %s\n",AplHandle->name,identity);

	while ((number = apl_get_word()) != MOINS_UN) {

		trace("apl_get_classes()\n");
		if ( apl_get_string() == 0 ) {
			status = syntax_error( 7010 );
			break;
			}
		else	{
			access = apl_get_word();
			nature = apl_get_byte();

			if ((status = open_structure_definition( TokenBuffer, nature )) != 0)
				break;

			else	class = World->CurrentStructure;

			if (!( 	class->module = allocate_for_string( identity ) ))
				break;

			set_member_library( class );

			class->access |= ( access & _MEMBER_EXTERN );
			class->enhanced = apl_get_word();
			class->virtual  = apl_get_word();
			if ((class->explicite = apl_get_word()) != 0)
				class->size = class->explicite;
	
			sector = apl_get_word();
			offset = apl_get_byte();

			holdsect = AplHandle->sector;
			holdoffs = AplHandle->offset;

			if (((status = apl_seek( sector, offset )) != 0)
			||  ((status = apl_get_members( class )) != 0)
			||  ((status = close_structure_definition( class )) != 0))
				break;
			else if ((status = apl_seek( holdsect, holdoffs )) != 0)
				break;
			}
		}

	if ( status )
		sysprintf("Error loading library\n");

	if ( OtrOption.ListFlag == 2 )
		sysprintf("End of Library \n");
	apl_drop();
	return( status );
}

static	WORD	apl_loaded( filename )
BPTR	filename;
{
	TCAPLPTR	aptr;
	WORD		i=0;

	if ((aptr = AplRoot) != (TCAPLPTR) 0) {
		do	{
			i++;
		/*	sysprintf("(%u) %s =?= %s\n",i,filename,aptr->name);	*/
			if ( compare_tokens( filename, aptr->name ) )
				return( VRAI );
			}
		while ((aptr = aptr->next) != (TCAPLPTR) 0);
		}
	return( FAUX );

}


static	WORD	apl_usage_log( filename )
BPTR	filename;
{
	TCAPLPTR	aptr;

	if ((aptr = (TCAPLPTR) allocate( sizeof( struct apl_log ) )) != (TCAPLPTR) 0) {
		if ((aptr->name = allocate_for_string( filename )) != (BPTR) 0) {
			aptr->next = (TCAPLPTR) 0;
			if ( AplRoot == (TCAPLPTR) 0 )
				AplRoot = aptr;
			else	AplFoot->next = aptr;
			AplFoot = aptr;
			return( 0 );
			}
		liberate( aptr );
		}
	return( allocation_failure() );

}

static 	WORD	apl_get_apl()
{
	WORD	status=0;
	while ( apl_get_string() != 0 )
		if (( apl_loaded( TokenBuffer ) ))
			continue;
		/* added to allow uce un-nested #use in apls*/
		else if ((status = apl_usage_log( TokenBuffer )) != 0)
			break;
		else if ((status = apl_loader( TokenBuffer )) != 0)
			break;
	return( status );		
}

static	WORD	apl_get_symbols()
{
	APLSYMBPTR	aptr;

	while ( apl_get_string() ) {
		if ((aptr = allocate_apl_symbol()) == (APLSYMBPTR) 0)
			return( allocation_failure() );
		aptr->resolved = symbolic_file_number( TokenBuffer );
		aptr->logical  = apl_get_word();
		set_input_symbol( aptr );
		if ( OtrOption.ListFlag == 2 )
			sysprintf("File Record  : %s \n",TokenBuffer);
		}
	return( 0 );

}

static	WORD	apl_get_symbolic()
{
	WORD	sector;
	WORD	status;

	if ((status = apl_seek( 0, _APL_SYMBOLS_SECTOR )) != 0)
		return( status );
	if (((sector = apl_get_word()) != 0)
	&&  ( sector != MOINS_UN )) {
		if ((status = apl_seek( sector, 0 )) != 0)
			return( status );
		else if ((status = apl_get_symbols()) != 0 )
			return( status );
		}
	return( 0 );
}

static	WORD	apl_loader( filename )
BPTR	filename;
{
	BYTE	version[3];
	WORD	i;
	WORD	status;
	WORD	sector;
	WORD	aplsector;
	BYTE	identity[16];

	if (( OtrOption.Verbose & 4 )
	||  ( OtrOption.ListFlag == 2 ))
		sysprintf("Class Library : %s \n",filename);

	if ((status = apl_open( filename )) != 0)
		return( status );
	for (i=0; i < 3; i++ )
		version[i] = apl_get_byte();

	for (i=0; i < 15; i++ )
		if ((identity[i] = apl_get_byte()) == ' ')
			break;
	identity[i] = 0;

#ifdef	otr32
	if ((version[0] != '3' )
	&&  (version[0] != '2' )) {
		apl_drop();
		return( syntax_error( 7004 ) );
		}
#else
	if (( version[0] != '2' )
	||  ( version[1] != '1' )
	||  ( version[2] != '3' )) {
		apl_drop();
		return( syntax_error( 7004 ) );
		}
#endif
	/* Collect APL Options Byte : For Symbolic Info Presence */
	/* ----------------------------------------------------- */
	if ((status = apl_seek( 0, _APL_OPTIONS_BYTE )) != 0)
		return( status );

	else if ((status = set_input_options( apl_get_byte() )) != 0)
		return( status );

	/* Collect APL Class Table Sector Identity */
	/* --------------------------------------- */
	else if ((status = apl_seek( 0, _APL_CLASS_SECTOR )) != 0)
		return( status );

	else if ((sector = apl_get_word()) == 0) {
		apl_drop();
		return(0);
		}

	/* Collect APL Encryption Code */
	/* --------------------------- */

	else if ((status = apl_seek( 0, _APL_CRYPT_CODE )) != 0)
		return( status );

	else	set_input_encryption( apl_get_word() );

	/* Collect APL Library Dependance Table Sector */
	/* ------------------------------------------- */
	if ((status = apl_seek( 0, _APL_LIBRARY_SECTOR )) != 0)
		return( status );

	if (((aplsector = apl_get_word()) != 0)
	&&  (aplsector != MOINS_UN )) {
		if ((status = apl_seek( aplsector, 0 )) != 0)
			return( status );
		else if ((status = apl_get_apl()) != 0 )
			return( status );
		}

	/* Load Symbolic Filenames if APL is mode DEBUG */
	/* -------------------------------------------- */
	if (( apl_option_symbolic() )
	&&  ((status = apl_get_symbolic()) != 0))
		return( status );

	/* Load Class Index Table Entries and Members */
	/* ------------------------------------------ */
	if ((status = apl_seek( sector, 0 )) != 0)
		return( status );
	else if ((status = apl_get_classes(identity)) != 0)
		return( status );
	else	return( 0 );
}

WORD	translate_use( filename )
BPTR	filename;
{
	WORD	status;
	WORD	i;
	trace("translate_use()\n");

	if ( *filename == '"' ) {
		filename++;
		if ((i = strlen(filename)) > 0) {
			if ( *(filename+(i-1)) == '"')
				*(filename+(i-1)) = 0;
			}
		}
	if ( apl_loaded( filename ) != 0 )
		return( 0 );
	else if ((status = apl_usage_log( filename )) != 0)
		return( status );
	else if ((status = apl_loader( filename )) != 0)
		return( status );
	else	return( 0 );
}


#endif	/* _TRGETAPL_C */
	/* ----------- */



