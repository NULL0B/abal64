#ifndef	_TRCOMETH_C
#define	_TRCOMETH_C

/*	------------------------------		*/
/*	Normaly included by TRMETHOD.C		*/
/*	------------------------------		*/
#ifndef	UNIX
#else
WORD	flush_exception_handler();
#endif

static	TCMEMBERPTR	locate_special_method( nature, object, method, parent )
WORD			nature;
TCVARPTR XPTR		object;
TCMBMETHPTR		method;
TCVARPTR		parent;
{
	TCMEMBERPTR	member=(TCMEMBERPTR) 0;
	COMETHODPTR	cptr;

	if (( method != (TCMBMETHPTR) 0)
	&&  ((cptr = method->comethod) != (COMETHODPTR) 0)) {
		do	{
			if ( cptr->nature == nature )
				break;
			}
		while ((cptr = cptr->next) != (COMETHODPTR) 0);
		if (( cptr   != (COMETHODPTR) 0)
		&&  ( parent != (TCVARPTR) 0)
		&&  ((member = locate_class_member( (TCVARPTR XPTR) & parent, cptr->name )) != (TCMEMBERPTR) 0))
			*object = parent;
		else	*object = (TCVARPTR) 0;
		}
	return( member );
}

static	EXCEPTIONPTR	allocate_for_exception()
{
	EXCEPTIONPTR	eptr;
	trace("allocate_for_exception(");
	if ((eptr = (EXCEPTIONPTR) allocate( sizeof( struct tcode_exception ) )) != (EXCEPTIONPTR) 0) {
		eptr->start = new_implicite_label();
		eptr->finish = new_implicite_label();
		eptr->operate = new_implicite_label();
		eptr->variable = (TCVARPTR) 0;
		eptr->context  = (TCMBAUTOPTR) 0;
		}
	return( eptr );
}

TCVARPTR	exception_variable(nptr)
BPTR		nptr;
{
	TCVARPTR	vptr;

	strcpy( TokenBuffer, nptr );

	if ((vptr = is_variable(0)) != (TCVARPTR) 0) {
		while ( vptr->parent != (TCVARPTR) 0)
			vptr = vptr->parent;
		}
	TokenBuffer[0] = 0;
	return( vptr );
}

WORD	exception_method_active()
{
	TCMBMETHPTR	method;
	if (((method = (TCMBMETHPTR)input_method()) != (TCMBMETHPTR) 0)
	&&  (method->special == _CLASS_EXCEPTION ))
		return( VRAI );
	else	return( FAUX );
}

RESULTPTR	exception_operand()
{
	RESULTPTR	rptr=(RESULTPTR) 0;
	TCVARPTR	vptr;

	if (( exception_method_active() )
	&&  ((vptr = exception_variable("X1_ERROR")) != (TCVARPTR) 0))
		rptr = variable_result( vptr );

	return( rptr );
}

TCVARPTR	instance_exception_variable( nptr )
BPTR		nptr;
{
	TCVARPTR	vptr=(TCVARPTR) 0;
	vptr = exception_variable(nptr);
	if ( vptr == (TCVARPTR) 0) {
		if ( add_variable( nptr, 1, 2, 1, 1, 0, 0, 0 ) == 0 ) {
			if (( Context->scope & ISLOCAL)
			&&  ( Context->LDT  )) {
				vptr = Context->LDT->variable;
				}
			else	{
				vptr = Context->GDT->variable;
				}
			}
		}
	return( vptr );
}

static	WORD	generate_exception( eptr )
EXCEPTIONPTR	eptr;
{
	RESULTPTR	rptr;
	WORD		status=0;
	if ( EnhancedConstruction ) {
		(void) translate_do();
		if ((status = validate_exception_router(VRAI,0)) == 0) {
			eptr->variable = AutoContext->Catcher;
			set_exception_handler( eptr );
			}
		}
	else	{
		if (((eptr->variable = instance_exception_variable( "X1_ERROR" )) != (TCVARPTR) 0)
		&&  ((rptr = variable_result( eptr->variable )) != (RESULTPTR) 0)) {
			/* ON LOCAL ERROR GOTO */
			if ((status = implicite_on_error( rptr->contents, _CTRL_LOCAL, eptr->operate )) != 0)
				return( status );
			signal_new_line(1);
			(void) translate_do();
			}
		}
	return(status);
}

static	EXCEPTIONPTR	build_special_method( type, method, world )
WORD		type;
TCMBMETHPTR	method;
TCVARPTR	world;
{
	TCMEMBERPTR	member;
	TCMBAUTOPTR	aptr;
	TCVARPTR	object;
	EXCEPTIONPTR	eptr=(EXCEPTIONPTR) 0;
	if ((member = locate_special_method( type, (TCVARPTR XPTR) & object, method, world )) != (TCMEMBERPTR) 0) {
		if ((aptr = allocate_auto_method()) != (TCMBAUTOPTR) 0) {
			if ((eptr = allocate_for_exception()) != (EXCEPTIONPTR) 0) {
				aptr->world  = (TCVARPTR) input_object();
				aptr->object = object;
				aptr->member = member;
				aptr->method = (TCMBMETHPTR)member->special;
				eptr->context = aptr;
				return( eptr );
				}
			else	aptr = liberate_auto_method( aptr );
			}
		(void) allocation_failure();
		}
	return( (EXCEPTIONPTR) 0 );
}

WORD		activate_explicite_exception( eptr )
EXCEPTIONPTR	eptr;
{
	TCMBAUTOPTR	mptr;
	TCVARPTR	vptr;
	TCMBPARAPTR	parameters;
	RESULTPTR	rptr;
	WORD		status=0;
	if ((eptr != (EXCEPTIONPTR) 0)
	&&  ((mptr = eptr->context) != (TCMBAUTOPTR) 0)
	&&  ((vptr = eptr->variable) != (TCVARPTR) 0  )
	&&  ((rptr = variable_result( vptr )) != (RESULTPTR) 0)
	&&  ((parameters = build_operation_parameters( mptr->method->parameters, rptr )) != (TCMBPARAPTR) 0)) {
		status = ll_activate_method( mptr->object, mptr->member, mptr->method, parameters, 1, 1 );
		eptr->variable = (TCVARPTR) 0;
		}
	return( status );
}

static	EXCEPTIONPTR	activate_exception()
{
	EXCEPTIONPTR	eptr=(EXCEPTIONPTR) 0;
	if ((eptr = build_special_method( _CLASS_EXCEPTION, input_method(), input_object() )) != (EXCEPTIONPTR) 0) {
		if ( generate_exception( eptr ) == 0 )
			dcl_implicite_label( eptr->start );
		}
	return( eptr );
}

static	WORD	terminate_exception( eptr, label )
EXCEPTIONPTR	eptr;
WORD		label;
{
	TCMBAUTOPTR	mptr;
	TCMBPARAPTR	parameters;
	RESULTPTR	rptr;
	WORD		status=0;
	if (( eptr != (EXCEPTIONPTR) 0)
	&&  ((mptr = eptr->context) != (TCMBAUTOPTR) 0)) {
		if (( eptr->variable != (TCVARPTR) 0)
		&&  ((rptr = variable_result( eptr->variable )) != (RESULTPTR) 0)
		&&  ((parameters = build_operation_parameters( mptr->method->parameters, rptr )) != (TCMBPARAPTR) 0)) {
			if (!( EnhancedConstruction )) {
				translate_break();
				dcl_implicite_label( eptr->operate );
				status = ll_activate_method( mptr->object, mptr->member, mptr->method, parameters, 1, 1 );
				}
			else	{
				if ( detect_destruction() == MOINS_UN )
					status = flush_exception_handler( label );
				}
			}
		translate_loop();
		dcl_implicite_label( eptr->finish );
		signal_new_line(1);
		if (!( EnhancedConstruction ))
			generate_error_abort();
		signal_new_line(1);
		eptr->context = liberate_auto_method( eptr->context );
		liberate( eptr );
		}
	return(status);
}

static	WORD	generate_invariant( eptr )
EXCEPTIONPTR	eptr;
{
	TCMBAUTOPTR	mptr;
	TCMBPARAPTR	parameters=(TCMBPARAPTR) 0;
	WORD		status=0;

	if (( eptr != (EXCEPTIONPTR) 0)
	&&  ((mptr = eptr->context) != (TCMBAUTOPTR) 0)) {

		/* Attempt to Activate Inline Method */
		/* --------------------------------- */
		if ((status = establish_macro_input( 	mptr->object,
							mptr->method,
							mptr->method->value->buffer, 
							parameters, 
							1 )) != 0 )

			return(status);

		else	set_method_infos( mptr->method->file, mptr->method->line, mptr->method->offset );

		if (((status = continue_translation(0)) == 0)
		&&  ((status = translate_soft_event())  == 0)) {
			status = method_translation(mptr->member);
			leave_iteration();
			}

		/* Remove Current Context */
		/* ---------------------- */
		(void) pop_source_context(1);

		}
	return(status);

}

static	WORD	terminate_invariant( iptr )
EXCEPTIONPTR	iptr;
{
	WORD		status=0;
	TCMBAUTOPTR	mptr;

	if (( iptr != (EXCEPTIONPTR) 0)
	&&  ((mptr = iptr->context) != (TCMBAUTOPTR) 0)) {
		dcl_implicite_label( iptr->start );
		dcl_implicite_label( iptr->operate);
		dcl_implicite_label( iptr->finish );
		signal_new_line(1);
		status = generate_event_off();
		signal_new_line(1);
		iptr->context = liberate_auto_method( iptr->context );
		liberate( iptr );
		}
	return(status);
}

static	WORD	generate_condition( eptr )
EXCEPTIONPTR	eptr;
{
	TCMBAUTOPTR	mptr;
	TCMBPARAPTR	parameters=(TCMBPARAPTR) 0;
	WORD		status=0;

	if (( eptr != (EXCEPTIONPTR) 0)
	&&  ((mptr = eptr->context) != (TCMBAUTOPTR) 0)) {

		/* Attempt to Activate Inline Method */
		/* --------------------------------- */
		if ((status = establish_macro_input( 	mptr->object,
							mptr->method,
							mptr->method->value->buffer, 
							parameters, 
							0 )) != 0 )

			return(status);

		else	set_method_infos( mptr->method->file, mptr->method->line, mptr->method->offset );

		if (((status = continue_translation(0)) == 0)
		&&  ((status = translate_if())  == 0))
			status = method_translation(mptr->member);

		/* Remove Current Context */
		/* ---------------------- */
		(void) pop_source_context(1);

		}
	return(status);

}

static	WORD	terminate_condition( eptr )
EXCEPTIONPTR	eptr;
{
	WORD	status=0;
	if ( eptr != (EXCEPTIONPTR) 0) {
		status = translate_endif();
		eptr->context = liberate_auto_method( eptr->context );
		liberate( eptr );
		}
	return( status );
}


static	WORD	activate_postcondition()
{
	EXCEPTIONPTR	eptr=(EXCEPTIONPTR) 0;
	WORD		status=0;

	if ((eptr = build_special_method( _CLASS_POSTCONDITION, input_method(), input_object() )) != (EXCEPTIONPTR) 0) {
		status = generate_condition( eptr );
		status += terminate_condition( eptr );
		return( status );
		}
	return( status );
}

static	EXCEPTIONPTR	activate_invariant()
{
	EXCEPTIONPTR	eptr=(EXCEPTIONPTR) 0;

	if ((eptr = build_special_method( _CLASS_INVARIANT, input_method(), input_object() )) != (EXCEPTIONPTR) 0) {
		if ((generate_invariant( eptr )) != 0) {
			(void) terminate_invariant( eptr );
			eptr = (EXCEPTIONPTR) 0;
			}
		}
	return(eptr);
}

static	EXCEPTIONPTR	activate_precondition(method,world)
TCMBMETHPTR		method;
TCVARPTR		world;
{
	EXCEPTIONPTR	eptr=(EXCEPTIONPTR) 0;

	if ((eptr = build_special_method( _CLASS_PRECONDITION, method, world )) != (EXCEPTIONPTR) 0) {
		if ((generate_condition( eptr )) != 0) {
			(void) terminate_condition( eptr );
			eptr = (EXCEPTIONPTR) 0;
			}
		}
	return(eptr);
}

#endif	/* _TRCOMETH_C */
	/* ----------- */

