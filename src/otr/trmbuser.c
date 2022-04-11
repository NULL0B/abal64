#ifndef	_TRMBUSER_C
#define	_TRMBUSER_C

#ifndef	UNIX
#else
TCMBOVLPTR	locate_overlay_method();
TCMBOVLPTR	build_overlay_method();
TCMEMBERPTR	locate_strict_alternative();
TCMBPARAPTR	collect_strict_parameters();
TCMBPARAPTR	translate_method_parameters();
TCDLFPTR	locate_dynamic_function();
VPTR		start_ldf();
TCDLFPTR	allocate_for_dlf();
RESULTPTR	flush_ldf();
RESULTPTR	flush_indirect_ldf();
#endif

/*	---------------------	*/
/*	store_user_parameters	*/
/*	---------------------	*/
static	WORD	store_user_parameters( xptr, fptr, pptr )
VPTR		xptr;
TCDLFPTR	fptr;
TCMBPARAPTR	pptr;
{
	TCVARPTR	vptr;
	
	if ((vptr = fptr->parameter) != (TCVARPTR) 0) 
	{
		while ( pptr != (TCMBPARAPTR) 0) 
		{
		 	store_ldf( xptr, pptr->result,( pptr->retmode + (vptr->access & _TYPE_QUESTION) ));
			if ( vptr->next != (TCVARPTR) 0 )
				vptr = vptr->next;
			pptr = pptr->next;
		}
		return( 0 );
	}
	else if ( pptr != (TCMBPARAPTR) 0 )
		return( syntax_error( 6208 ) );
	else	return( 0 );
}

/*	------------------------	*/
/*	store_userptr_parameters	*/
/*	------------------------	*/
static	WORD	store_userptr_parameters( xptr, pptr )
VPTR		xptr;
TCMBPARAPTR	pptr;
{
	while ( pptr != (TCMBPARAPTR) 0) 
	{
		store_ldf( xptr, pptr->result,pptr->retmode );
		pptr = pptr->next;
	}
	return( 0 );
}

/*	------------------	*/
/*	call_dll_procedure	*/
/*	------------------	*/
WORD		call_dll_procedure( fptr, pptr )
TCDLFPTR	fptr;
TCMBPARAPTR	pptr;
{
	RESULTPTR	iptr;
	VPTR		xptr;
	WORD		status;

	if ((xptr = start_ldf( fptr )) == (VPTR) 0)
		return( syntax_error( 6205 ) );
	else if ((iptr = integer_result( fptr->identity )) == (RESULTPTR) 0)
		return( allocation_failure() );
	else	if ((status = store_user_parameters( xptr, fptr, pptr )) != 0)
		return( status );
	else	return( flush_void_ldf( xptr, iptr ) );

}

/*	-------------	*/
/*	call_dll_pptr	*/
/*	-------------	*/
WORD		call_dll_pptr( procptr, pptr )
TCVARPTR	procptr;
TCMBPARAPTR	pptr;
{
	RESULTPTR	iptr;
	VPTR		xptr;
	WORD		status;

	if ((xptr = start_ldf( (VPTR) 0 )) == (VPTR) 0)
		return( syntax_error( 6205 ) );
	else if ((iptr = variable_result( procptr )) == (RESULTPTR) 0)
		return( allocation_failure() );
	else if ((status = store_userptr_parameters( xptr, pptr )) != 0)
		return( status );
	else	return( flush_void_ldf( xptr, iptr ) );

}

/*	-----------------	*/
/*	call_dll_function	*/
/*	-----------------	*/
RESULTPTR	call_dll_function( fptr, pptr )
TCDLFPTR	fptr;
TCMBPARAPTR	pptr;
{
	RESULTPTR	iptr;
	VPTR		xptr;
	WORD		status;

	if ((xptr = start_ldf( fptr )) == (VPTR) 0) 
	{
		(void) syntax_error( 6225 );
		return( (RESULTPTR) 0 );
	}
	else if ((iptr = integer_result( fptr->identity )) == (RESULTPTR) 0) 
	{
		(void) allocation_failure();
		return( (RESULTPTR) 0 );
	}
	else if ((status = store_user_parameters( xptr, fptr, pptr )) != 0)
		return((RESULTPTR) 0 );
	else	return( flush_ldf( xptr, iptr ) );
}

/*	-------------	*/
/*	call_dll_fptr	*/
/*	-------------	*/
RESULTPTR	call_dll_fptr( fptr, pptr, tptr )
TCVARPTR	fptr;
TCMBPARAPTR	pptr;
TCTYPPTR	tptr;
{
	RESULTPTR	iptr;
	VPTR		xptr;
	WORD		status;

	if ((xptr = start_ldf( (VPTR) 0 )) == (VPTR) 0) 
	{
		(void) syntax_error( 6225 );
		return( (RESULTPTR) 0 );
	}
	else if ((iptr = variable_result( fptr )) == (RESULTPTR) 0) 
	{
		(void) allocation_failure();
		return( (RESULTPTR) 0 );
	}
	else if ((status = store_userptr_parameters( xptr, pptr )) != 0)
		return((RESULTPTR) 0 );
	else	return( flush_indirect_ldf( xptr, iptr, tptr ) );
}

/*	--------------------	*/
/*	activate_user_method	*/
/*	--------------------	*/
WORD 		activate_user_method( object, member, method, parameters, mode, option )
TCVARPTR	object;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
TCMBPARAPTR	parameters;
WORD		mode;
WORD		option;
{
	WORD		status;
	TCSTRUCTPTR	class;
	TCDLBPTR	library;
	TCDLFPTR	function;
	TCVARPTR	container;
	TCVARPTR	procptr;

	trace("activate_user_method("); 
	trace( object->name ); trace("."); trace( member->name );
	trace(")\n");

	if (( method->options & _METHOD_INDIRECT )
	&&  ( option )) 
	{
		if ((status = locate_method_pointer( object, method, & container, & procptr , member )) != 0)
			return( status );
	}

	else if (((class = member->class) == (TCSTRUCTPTR) 0)
	     ||  ((library = class->dll)  == (TCDLBPTR) 0)
	     ||  ((function = locate_dynamic_function( library, method->number )) == (TCDLFPTR) 0))
		return( syntax_error( 6204 ) ); 

	if ( parameters == (TCMBPARAPTR) 0)
		parameters = translate_method_parameters( method );

	if (( method->options & _METHOD_INDIRECT )
	&&  ( option ))
		status = call_dll_pptr( procptr, parameters );
	else	status = call_dll_procedure( function, parameters );

	liberate_method_parameters( parameters );

	return( status );
}

/*	-------------------------	*/
/*	 ll_evaluate_user_method	*/
/*	-------------------------	*/
static RESULTPTR	ll_evaluate_user_method( object, member, method, parameters, mode, option )
TCVARPTR		object;
TCMEMBERPTR		member;
TCMBMETHPTR		method;
TCMBPARAPTR		parameters;
WORD			mode;
WORD			option;
{
	WORD		status;
	TCSTRUCTPTR	class;
	TCDLBPTR	library;
	TCDLFPTR	function;
	TCVARPTR	container;
	TCVARPTR	procptr;
	RESULTPTR	rptr=(RESULTPTR) 0;

	trace("ll_evaluate_user_method("); 
	trace( object->name ); trace("."); trace( member->name );
	trace(")\n");

	if (( method->options & _METHOD_INDIRECT )
	&&  ( option )) 
	{
		if ((status = locate_method_pointer( object, method, & container, & procptr , member )) != 0)
			return((RESULTPTR) 0);
	}

	else if (((class = member->class) == (TCSTRUCTPTR) 0)
	     ||  ((library = class->dll)    == (TCDLBPTR) 0)
	     ||  ((function = locate_dynamic_function( library, method->number )) == (TCDLFPTR) 0)) 
	{
		(void) syntax_error( 6224 ); 
		return( (RESULTPTR) 0 );
	}

	if ( parameters == (TCMBPARAPTR) 0)
		parameters = translate_method_parameters( method );

	if (( method->options & _METHOD_INDIRECT )
	&&  ( option ))
		rptr = call_dll_fptr( procptr, parameters, method->type );
	else	rptr = call_dll_function( function, parameters );

	liberate_method_parameters( parameters );

	return( rptr );
}

/*	--------------------	*/
/*	evaluate_user_method	*/
/*	--------------------	*/
RESULTPTR	evaluate_user_method( object, member, method, parameters, mode, option )
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

	trace("evaluate_user_method()\n");

	if (!( method->options & _METHOD_STRICT )) 
	 	return( ll_evaluate_user_method( object, member, method, parameters, mode, option ) );

	if (( parameters == (TCMBPARAPTR) 0 )
	&&  (( parameters = collect_strict_parameters()) != (TCMBPARAPTR) 0))
		paraflag = 1;

	while ( 1 ) 
	{

		variables = explicite_method_parameters( method );

		if ( verify_strict_parameters( variables, parameters ) )
		 	return( ll_evaluate_user_method( object, member, method, parameters, mode, option ) );

		/* Construction Mode : No Locate Alterative */
		/* ---------------------------------------- */
		if ( mode ) 
		{
			if ( paraflag )
				liberate_method_parameters( parameters );
			return( (RESULTPTR) 0 );
		}
		else if ((member = locate_strict_alternative( original, member->next )) == (TCMEMBERPTR) 0)
			break;
		else if ((method = (TCMBMETHPTR) member->special) == (TCMBMETHPTR) 0)
			break;

	}

	if ( paraflag )
		liberate_method_parameters( parameters );
	issue_warning(7);
	trace("no_strict_alterative()\n");
	return( (RESULTPTR) 0 );
}

/*	-----------------	*/
/*	add_user_function	*/
/*	-----------------	*/
WORD		add_user_function( method, number )
TCMBMETHPTR	method;
WORD		number;
{
	TCDLFPTR	fptr;
	TCSTRUCTPTR	class;

	reset_oneshot_options();

	if ((class = World->CurrentStructure) == (TCSTRUCTPTR) 0)
		return( syntax_error( 6200 ) );

	else if (class->dll == (TCDLBPTR) 0) 
	{
		method->number = number;
		return( 0 );
	}

	else if ((fptr = allocate_for_dlf()) == (TCDLFPTR) 0)
		return( allocation_failure() );

	else	
	{
		method->options |= _METHOD_STRICT;
		fptr->identity 	= number;
		fptr->name	= method->member->name;
		fptr->library	= class->dll;

		if ( method->type == (TCTYPPTR) 0)
			fptr->type = MOINS_UN;
		else	fptr->type = method->type->type;

		fptr->parameter = method->parameters;

		method->number = add_dll_function( class->dll, fptr );
		return( 0 );

	}
}

/*	-------------------	*/
/*	affect_user_pointer	*/
/*	-------------------	*/
WORD	affect_user_pointer( procptr, object, class, member, method )
TCVARPTR	procptr;
TCVARPTR	object;
TCSTRUCTPTR	class;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
{
	RESULTPTR	result;
	RESULTPTR	source;
	RESULTPTR	lptr;
	TCDLBPTR	library;
	TCDLFPTR	function;
	WORD		status;

	trace("affect_user_pointer()\n");

	if (( class == (TCSTRUCTPTR) 0)
	||  ((library = class->dll)  == (TCDLBPTR) 0)
	||  ((function = locate_dynamic_function( library, method->number )) == (TCDLFPTR) 0))
		return( syntax_error( 6204 ) ); 

	if ((result  = variable_result( procptr )) == (RESULTPTR) 0)
		return( allocation_failure() );

	else if ((source = integer_result( function->identity )) == (RESULTPTR) 0)
		return( allocation_failure() );
	else if ((lptr = integer_result( library->identity )) == (RESULTPTR) 0)
		return( allocation_failure() );
	else if ((status = clf_userptr( result, source, lptr )) != 0)
		return( status );
	else	return( 0 );
}

/*	------------------------	*/
/*	initialise_indirect_user	*/
/*	------------------------	*/
WORD		initialise_indirect_user( aptr )
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


	if ((status = affect_user_pointer( procptr, object, aptr->member->class, aptr->member, aptr->method )) != 0)
		return( status );
	else if ( aptr->member->access & (_MEMBER_OVERLOAD | _MEMBER_VIRTUAL) )
		return( method_object_alias( procptr, object ) );
	else	return( 0 );

}

/*	----------------------	*/
/*	affect_overlay_pointer	*/
/*	----------------------	*/
WORD	affect_overlay_pointer( procptr, object, class, member, method )
TCVARPTR	procptr;
TCVARPTR	object;
TCSTRUCTPTR	class;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
{
	RESULTPTR	result;
	RESULTPTR	source;
	TCMBOVLPTR	overlay;
	WORD		status;

	trace("affect_overlay_pointer()\n");

	if ((result  = variable_result( procptr )) == (RESULTPTR) 0)
		return( allocation_failure() );

	else if (((overlay = locate_overlay_method( class, member, 0 )) == (TCMBOVLPTR) 0)
	     &&  ((overlay = build_overlay_method( object,  member->class, member, 0 )) == (TCMBOVLPTR) 0))
		return( allocation_failure() );

	else if ((source = integer_result( overlay->segment->identity )) == (RESULTPTR) 0)
		return( allocation_failure() );
	else if ((status = clf_segmptr( result, source )) != 0)
		return( status );
	else	return( 0 );
}

/*	---------------------------	*/
/*	initialise_indirect_overlay	*/
/*	---------------------------	*/
WORD		initialise_indirect_overlay( aptr )
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

	if ((status = affect_overlay_pointer( procptr, object, aptr->member->class, aptr->member, aptr->method )) != 0)
		return( status );
	else if ( aptr->member->access & (_MEMBER_OVERLOAD | _MEMBER_VIRTUAL) )
		return( method_object_alias( procptr, object ) );
	else	return( 0 );
}

/*	--------------------	*/
/*	call_overlay_pointer	*/
/*	--------------------	*/
WORD		call_overlay_pointer( vptr )
TCVARPTR	vptr;
{
	return( syntax_error( 7000 ) );
}

/*	---------------------	*/
/*	affect_method_pointer	*/
/*	---------------------	*/
WORD	affect_method_pointer( procptr, object, class, member, method )
TCVARPTR	procptr;
TCVARPTR	object;
TCSTRUCTPTR	class;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
{
	switch ( method->nature ) 
	{
	case	_CLASS_FUNCTION :
		return( affect_function_pointer( procptr, object, class, member, method ) );
	case	_CLASS_OVERLAY	:
		return( affect_overlay_pointer( procptr, object, class, member, method ) );
	case	_CLASS_USER	:
		return( affect_user_pointer( procptr, object, class, member, method ) );
	default			:
		return( internal_error( 5656 ) );
	}
}

	/* ----------- */
#endif	/* _TRMBUSER_C */
	/* ----------- */

