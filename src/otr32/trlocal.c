#ifndef	_TRLOCAL_C
#define	_TRLOCAL_C


#ifndef	UNIX
#else
WORD	flush_exception_catcher();
WORD	detect_destruction();
#endif

static	WORD	resolve_genericity( gptr )
GENERICPTR	gptr;
{
	while ( gptr != (GENERICPTR) 0) {
		if (( TokenHash == gptr->old->hash )
		&&  ( compare_tokens( TokenBuffer, gptr->old->name ) )) {
			TokenHash = gptr->new->hash;
			strcpy( TokenBuffer, gptr->new->name );
			}
		gptr = gptr->next;
		}
	return( 0 );
}

static WORD	ll_translate_local_member()
{
	WORD		status;
	WORD		keyword;
	WORD		dcltype=_KW1_DCL;
	TCMBMETHPTR	method;
	GENERICPTR	gptr=(GENERICPTR) 0;

	if ((method = (TCMBMETHPTR)input_method()) != (TCMBMETHPTR) 0)
		gptr = method->generic;

	while (1) {

		/* Evaluate Class Keywords */
		/* ----------------------- */
		while (1) {
			if (!( evaluate_token() ))
				return( syntax_error( 5673 ) );
			else if ((keyword = is_class_keyword()) == MOINS_UN)
				break;
			switch ((keyword)) {

				case	_CLASS_PUBLIC	:
					if ((status = translate_public()) != 0)
						return( status );
					else	continue;

				case	_CLASS_PRIVATE	:
					if ((status = translate_private()) != 0)
						return( status );
					else	continue;

				case	_CLASS_PROTECT	:
					if ((status = translate_protect()) != 0)
						return( status );
					else	continue;

				case	_CLASS_COMMON	:
					if ((status = translate_common()) != 0)
						return( status );
					else	continue;

				case	_CLASS_STATIC	:
					if ((status = translate_static_keyword()) != 0)
						return( status );
					else	continue;

				case	_CLASS_DYNAMIC	:
					if ((status = translate_dynamic_keyword()) != 0)
						return( status );
					else	continue;

				case	_CLASS_EXTERN	:

					if ((status = translate_extern_keyword()) != 0)
						return( status );
					else	continue;
					continue;

				case	_CLASS_OVERLAY	:
					dcltype = _KW1_OVL;
					continue;

				case	_CLASS_POINTER  :
					dcltype = _KW1_PTR;
					continue;

				case	_CLASS_DCL	:
					dcltype = _KW1_DCL;
					continue;

				case	_CLASS_UNION	:
					if ((status = translate_structure( dcltype, _KW1_UNION )) != 0)
						return( status );
					else if (!( is_comma() ))
						return( verify_end_of_line() );
					else	continue;

				case	_CLASS_CLASS	:
					if (!( get_token() ))
						return( syntax_error( 5671 ) );
					if (( gptr != (GENERICPTR) 0 )
					&&  ((status = resolve_genericity(gptr)) != 0))
						return( status );
					else if ((status = translate_instance()) != 0)
						return( status );
					else if (!( is_comma() ))
						return( verify_end_of_line() );
					else	continue;

				case	_CLASS_ARGUMENT :
					return( syntax_error( 5672 ) );


				}
			}
	
		/* Evaluate ABAL declarations */
		/* -------------------------- */
		if ((status = translate_level_one()) != MOINS_UN)
			return( status );
		else if ((status = translate_variable(_KW1_DCL,0)) != 0)
			return( status );
		else if (!( is_comma() ))
			return( verify_end_of_line() );
		}

}

static	WORD	translate_local_member()
{
	WORD	status;
	status = ll_translate_local_member();
	reset_oneshot_options();
	return( status );
}

static	WORD	translate_compatible_local()
{
	TCMBMETHPTR	method;
	WORD		status=0;
	if ((method = output_method()) == (TCMBMETHPTR) 0)
		return( syntax_error( 5669 ) );
	if (( method->nature != _CLASS_INLINE  )
	&&  ( method->nature != _CLASS_ROUTINE )) {
		if (( method->local == (TCSTRUCTPTR) 0)
		&&  ((method->local = allocate_for_structure("local")) == (TCSTRUCTPTR) 0))
			return( allocation_failure() );
		method->local->next = World->CurrentStructure;
		World->CurrentStructure = method->local;
		}
	status = translate_local_member();
	if (( method->nature != _CLASS_INLINE  )
	&&  ( method->nature != _CLASS_ROUTINE )) {
		World->CurrentStructure = method->local->next;
		method->local->next = (TCSTRUCTPTR) 0;
		}
	return( status );
}

static	WORD	translate_enhanced_local()
{
	if ( class_definition_active() )
		return( translate_local_keyword() );
	else	return( translate_local_member() );
}


/*
 *	Keyword LOCAL encountered outside of method collection
 */

WORD	translate_local()
{
	if (!( OtrOption.Enhanced & _ENHANCED_LOCAL ))
		return( syntax_error( 5674 ) );
	else	return( translate_enhanced_local() );
}

static	WORD	translate_local_data()
{
	WORD	status;

	/* Enhanced local : will be evaluated upon method expansion */
	/* -------------------------------------------------------- */
	if ( OtrOption.Enhanced & _ENHANCED_LOCAL ) {
		if ((status = put_method_string( "LOCAL " )) != 0)
			return( status );
		else if (( is_mnemonic("POINTER") )
		     &&  ((status = put_method_string("PTR ")) != 0))
			return( status );
		if (!( get_token() ))
			return( syntax_error( 5674 ) );
		else 	{
			put_method_string( TokenBuffer );
			if ( is_dieze() )
				put_method_string("#");
			else if ( is_dollar() )
				put_method_string("$");
			else if ( is_percent() )
				put_method_string("%");
			else if ( is_colon() )
				put_method_string(":");
			return( 0 );
			}
		}
	else 	return( translate_compatible_local() );
	
}

static	WORD	translate_local_statement()
{
	TCMBMETHPTR	method;

	if ( is_mnemonic("EXCEPTION") )
		return( translate_co_method(_CLASS_EXCEPTION) );
	else if ( is_mnemonic("INVARIANT") )
		return( translate_co_method(_CLASS_INVARIANT) );
	else if ( is_mnemonic("PRECONDITION") )
		return( translate_co_method(_CLASS_PRECONDITION) );
	else if ( is_mnemonic("POSTCONDITION") )
		return( translate_co_method(_CLASS_POSTCONDITION) );
	else if ((method = output_method()) == (TCMBMETHPTR) 0)
		return( 0 );
	else	return( translate_local_data() );

}

WORD	initialise_method_local( method )
TCMBMETHPTR	method;
{
	WORD		status;

	if ( OtrOption.Enhanced & _ENHANCED_LOCAL ) {

		/* Enhanced Locals require local protected construction */
		/* ---------------------------------------------------- */
		if ((status = local_instance_manager()) != 0)
			return( status );
		else	new_symbol_owner();
		}

	else if (( method->nature != _CLASS_INLINE  )
	     &&  ( method->nature != _CLASS_ROUTINE )) {
		/* Compatible locals require implicite declaration */
		/* ----------------------------------------------- */
		if ((status = declare_local_members( method->local )) != 0)
			return( status );
		else	return( allow_construction() );
		}		

	return( 0 );
}

WORD	terminate_method_local( method )
TCMBMETHPTR	method;
{
	TCAUTOPTR	aptr;
	WORD		status=0;
	WORD		label=MOINS_UN;
	WORD		xlabel=MOINS_UN;
	if ( OtrOption.Enhanced & _ENHANCED_LOCAL ) {
		
		if ((aptr = AutoContext) != (TCAUTOPTR) 0) {

			if ( method->nature == _CLASS_FUNCTION )
				procedure_closure( Context->PRC );

			else if ( method->nature == _CLASS_OVERLAY )
				segmental_closure( 1 );

			else	{
				if ((label = detect_destruction()) != MOINS_UN) {
					xlabel = new_implicite_label();
					implicite_goto( xlabel );
					status = perform_destruction(label);
					dcl_implicite_label( xlabel );
					}
				else if (EnhancedConstruction)
					status = flush_exception_catcher( MOINS_UN );
				}

			/* Return to Previous Instance Controler */
			/* ------------------------------------- */
			drop_local_instance();

			if (( method->nature != _CLASS_FUNCTION )
			&&  ( method->nature != _CLASS_OVERLAY  ))
				drop_local_symbols();
			}
		}
	return( status );
}


#endif	/* _TRLOCAL_C */
	/* ---------- */



