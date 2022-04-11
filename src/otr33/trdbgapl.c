#ifndef	_TRDBAPL_C
#define	_TRDBAPL_C


static	APLSYMBPTR	allocate_apl_symbol()
{
	APLSYMBPTR	aptr;

	if ((aptr = (APLSYMBPTR) allocate( sizeof( struct apl_symbolic_entry ) )) != (APLSYMBPTR) 0) {
		aptr->logical  = MOINS_UN;
		aptr->resolved = MOINS_UN;
		aptr->next     = (APLSYMBPTR) 0;
		}
	else	allocation_failure();
	return( aptr );
}

static	WORD	known_local_handle( h )
WORD	h;
{
	APLSYMBPTR	aptr;
	if ((aptr = apl_input_symbols()) != (APLSYMBPTR) 0) {
		do	{
			if ( aptr->logical == h )
				return( aptr->resolved );
			}
		while ((aptr = aptr->next) != (APLSYMBPTR) 0);
		}
	return( MOINS_UN );
}

static	WORD	known_world_handle( h )
WORD	h;
{
	APLSYMBPTR	aptr;
	if ((aptr = AplSymbol) != (APLSYMBPTR) 0) {
		do	{
			if ( aptr->resolved == h )
				return( aptr->logical );
			}
		while ((aptr = aptr->next) != (APLSYMBPTR) 0);
		}
	return( MOINS_UN );
}

/*
 *	Returns a LOCAL (logical) handle to be stored by 
 *	put_apl_method_symbolic() into the target APL method
 *	record. The provided WORLD (resolved) handle if unknown
 *	will create a new symbolic controller for output to
 *	the library APL and calculate a new logical handle.
 *
 */

static	WORD	apl_logical_handle( whandle )
WORD		whandle;
{
	APLSYMBPTR	aptr;
	WORD		lhandle;
	if ((lhandle = known_world_handle( whandle )) != MOINS_UN)
		return( lhandle );
	else if ((aptr = allocate_apl_symbol()) == (APLSYMBPTR) 0)
		return( MOINS_UN );
	set_output_symbol( aptr );
	aptr->resolved = whandle;
	return( aptr->logical );
}

/*
 *	The provided LOCAL (logical) handle is saught in the 
 *	library symbols list to find the precalculated
 *	WORLD (resolved) handle. If it does not exist then
 *	some kind of error has occured but can be ignored for now.
 */

static	WORD	apl_resolved_handle( lhandle )
WORD		lhandle;
{
	WORD		whandle;
	if ((whandle = known_local_handle( lhandle )) != MOINS_UN)
		return( whandle );
	else	return( MOINS_UN );
}


#endif	/* _TRDBAPL_C */



