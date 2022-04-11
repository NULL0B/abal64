#ifndef	_TRINFORM_C
#define	_TRINFORM_C

#ifndef	UNIX
RESULTPTR	string_result( BPTR );
#else
RESULTPTR	string_result();
#endif

static	BPTR	string_information( result, sptr )
BPTR	result;
BPTR	sptr;
{
	strcpy( result, sptr );
	return( (result + strlen(sptr) ) );
}


static	BPTR	type_information( type, result )
TCTYPPTR	type;
BPTR		result;
{
	switch ((type->type & _TYPE_BASIC)) {
		case	0 : *(result++) ='#'; break;
		case	1 : *(result++) ='%'; break;
		case	2 : *(result++) ='N'; break;
		case	3 : *(result++) ='$'; break;
		case	5 : *(result++) =':'; break;
		}
	return( result );
}

static	BPTR	method_parameter_information( result, method )
BPTR		result;
TCMBMETHPTR	method;
{
	WORD		nombre=0;
	TCVARPTR	parameters;

	if ((parameters = explicite_method_parameters( method )) != (TCVARPTR) 0) {
		do	{
			if ( nombre++ )
				*(result++) = ',';
			else	*(result++) = '(';
			result = type_information( parameters->type, result );
			}
		while (( parameters = parameters->next ) != (TCVARPTR) 0 );
		}

	if (nombre)
		*(result++) = ')';

	if ( method->type != (TCTYPPTR) 0 ) {
		*(result++) = ' ';
		*(result++) = ':';
		*(result++) = ' ';
		result = type_information( method->type, result );
		}		

	*(result++) = ' ';
	return( result );
}

static	BYTE		InfoBuffer[256];

WORD	print_information( format, text )
BPTR	format;
BPTR	text;
{
	WORD		status=0;
	RESULTPTR	device;

	signal_new_line(1);
	if (((status = start_iof()) != 0)
	||  ((device = integer_result(1)) == (RESULTPTR) 0)
	||  ((status = store_iof_fmt( format )) != 0)
	||  ((status = store_iof_prn(string_result( text ))) != 0)
	||  ((status = flush_print( device, VRAI )) != 0))
		return( status );
	else	return( 0 );
}

static	WORD	print_interface_method( member, method )
TCMEMBERPTR	member;
TCMBMETHPTR	method;
{
	BPTR		result;

	result = InfoBuffer;

	if (( method == (TCMBMETHPTR) 0)
	||  ( method->nature != _CLASS_FUNCTION )
	||  (!( method->options & _METHOD_INDIRECT )))
		return( 0 );

	if ( method->special ) {
		result = string_information( result, get_class_keyword(method->special) );
		*(result++) = ' ';
		}
	result = string_information( result, get_class_keyword(method->nature) );
	*(result++) = ' ';
	result = string_information( result, member->name );
	*(result++) = ':';
	result = method_parameter_information( result, method );
	*(result++) = 0;

	return( print_information( "X3,$,/1", InfoBuffer ) );
}

static	WORD	print_interface_members( member )
TCMEMBERPTR	member;
{
	WORD	status=0;
	while ( member != (TCMEMBERPTR) 0 ) {
		if (( member->access & _MEMBER_PUBLIC )		
		&&  (!( member->nature ))
		&&  ((status = print_interface_method( member, member->special )) != 0))
			break;
		else 	member = member->next;
		}
	return( 0 );
}

static	WORD	print_common_interface( class )
TCSTRUCTPTR	class;
{
	TCSTRUCTPTR	sptr;
	TCVARPTR	liste;
	TCVARPTR	variable;
	WORD		status;
	BPTR		result;
	if ((liste = overlay_common_pointers( (TCVARPTR) 0, class, class->first )) != (TCVARPTR) 0) {
		if ((status = print_information( "/1,X3,$,/2", "Common Interface :" )) != 0)
			return( status );

		do	{
			variable = liste;
			liste = liste->next;
			if ((sptr = (TCSTRUCTPTR)variable->type->class) != (TCSTRUCTPTR) 0) {
				result = string_information( InfoBuffer, sptr->name );
				*(result++) = ' ';
				result = string_information( result, variable->name );
				*(result++) = 0;
				status = print_information("X3,$,/1",InfoBuffer);
				}
			else	status = 0;
			liberate_for_variable( variable );
			if ( status )
				return( status );
			}
		while ( liste != (TCVARPTR) 0 );
		}
	return( 0 );
}


WORD		overlay_identification( class )
TCSTRUCTPTR	class;
{
	WORD		status;
	RESULTPTR	device;
	BPTR		message;
	if ( class->enhanced & _ENHANCED_INDIRECT )
		message = "Enhanced";
	else	message = "Standard";
	signal_new_line(1);
	if (((status = start_iof()) == 0)
	&&  ((device = integer_result(1)) != (RESULTPTR) 0)
	&&  ((status = store_iof_fmt("/1,X3,$,X,$,X,$,/2,X3,$,X,$,/2")) == 0)
	&&  ((status = store_iof_prn(string_result( "ABAL++ Version 2.2a" ))) == 0)
	&&  ((status = store_iof_prn(string_result( message ))) == 0)
	&&  ((status = store_iof_prn(string_result( "Object Overlay" ))) == 0)
	&&  ((status = store_iof_prn(string_result( "Class :" ))) == 0)
	&&  ((status = store_iof_prn(string_result( class->name ))) == 0)
	&&  ((status = flush_print(device,VRAI)) == 0)
	&&  ((status = print_interface_members( class->first )) == 0))
		return( print_common_interface(class) );
	else	return( status );
}

#endif	/* _TRINFORM_C */
	/* ----------- */


