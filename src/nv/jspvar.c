
struct	variable * Variables=(struct variable *) 0;


struct variable * locate_variable( char * nptr )
{
	int	h;
	struct variable * vptr=(struct variable *) 0;
	if ( nptr != (char *) 0 )
		for (h=calculate_hash_code(nptr),vptr=Variables; vptr != (struct variable *) 0; vptr = vptr->next)
			if ( vptr->name != (char *) 0 )
				if (( h == vptr->hash )
				&&  ( compare(nptr,vptr->name ) ))
					break;
	return(vptr);
}

struct variable * liberate_variable(	struct variable * vptr )
{
	if ( vptr ) {

		if ( vptr->name )
			vptr->name = liberate( vptr->name );

		if ( vptr->value )
			vptr->value = liberate_operand( vptr->value );

		vptr = liberate( vptr );

		}
	return( (struct variable *) 0 );
}

void	release_variables()
{
	struct variable * vptr=(struct variable *) 0;
	while ((vptr = Variables) != (struct variable *) 0) {
		Variables = vptr->next;
		vptr = liberate_variable( vptr );
		}
	return;
}


int	add_variable( struct variable * vptr )
{
	if ( vptr ) {
		if ( debug )
			printf("add_variable(%s)\n",vptr->name);
		if ((vptr->next = Variables) != (struct variable *) 0)
			Variables->previous = vptr;
		Variables = vptr;
		}
	return(0);
}

struct variable * new_variable( char * nptr )
{
	struct variable * vptr=(struct variable *) 0;
	if ((vptr = allocate( sizeof( 	struct variable ) )) != (struct variable *) 0) {
		vptr->next = vptr->previous = vptr->name = vptr->value = 0;
		if (!(vptr->name = allocate_string( nptr )))
			vptr = liberate_variable(vptr);
		else	vptr->hash = calculate_hash_code( nptr );
		}
	return(vptr);
}

struct operand * expression()
{
	struct operand * lptr;
	int	operator;
	struct operand * rptr;

	if ( debug )
		printf("expression()\n");

	if (!(lptr = evaluate_term() ))
		return( lptr );

	while (( operator = get_operator()) != 0) {

		if (!( rptr = evaluate_term() ))
			break;
		else if (!(lptr = perform_operation( lptr, operator, rptr )))
			break;

		}

	return( lptr );
}

struct operand * number_expression()
{
	struct operand * rptr;
	if (( rptr = expression() ) != (struct operand *) 0)
		if ( rptr->type != _NUMBER )
			rptr = convert_number( rptr );
	return( rptr );
}

struct operand * string_expression()
{
	struct operand * rptr;
	if (( rptr = expression() ) != (struct operand *) 0)
		if ( rptr->type != _STRING )
			rptr = convert_string( rptr );
	return( rptr );
}

int	store( 	struct variable * vptr,
		struct operand * rptr 	)
{
	if (vptr->value )
		vptr->value = liberate_operand( vptr->value );

	if (!(vptr->value = copy_operand( rptr )))
		return(jserror(27));
	else	return(0);

}

void	* array_member( void** aptr, long item )
{
	return( aptr[item] );
}

int	store_array( void** aptr, long item, void * rptr)
{
	if (!(rptr))
		return(30);
	else	{
		aptr[item] = rptr;
		return(0);
		}
}

int	use_dimensioned( struct variable * vptr, struct operand * rptr  )
{
	int	cc;
	int	c;
	int	operator;
	struct operand * xptr;
	struct operand * lptr;
	if ( not_white() != '[' )
		return(99);
	else if (!( xptr = expression() ))
		return(98);
	else if ( not_white() != ']' )
		return(973);
	else if ( xptr->type != _NUMBER )
		xptr = convert_number( xptr );
	if ( xptr->value > rptr->value )
		return(103 );
	else if ((c = not_white()) == '=' )
		return( store_array( rptr->pointer, xptr->value, expression() ) );
	else	{
		ungetch(c);
		if ((operator = get_operator()) != 0) {

			if (( cc = not_white() ) == operator ) {
				// increment or decrement pehaps
				lptr = make_number( 1L );
				return( 
					store_array( 
						rptr->pointer, xptr->value, 
						perform_operation( array_member(rptr->pointer, xptr->value),
						 operator, lptr ) ));

				}
			else if ( cc == '=' )
				return( 
					store_array( 
						rptr->pointer, xptr->value, 
						perform_operation( array_member(rptr->pointer, xptr->value),
						 operator, expression() ) ));

			else	return( jserror(555) );
			}
		else	
			return( jserror( 777) );							

		}
}

struct variable * resolve_member( struct variable * vptr )
{
	int	c;
	if ((c = not_white()) != '.' ) {
		ungetch(c);
		return((struct variable *) 0);
		}
	else if (!( get_token() ))
		return((struct variable *) 0);
	else 	return( locate_member( vptr, token_buffer ) );
}


int	native_method( struct variable * vptr )
{


}



int	use_variable( struct variable * vptr )
{
	int	c;
	int	cc;
	int	operator;
	int	(*operation)();

	struct operand * rptr;
	struct variable * wptr;
	// This function will allow the lvalue : vptr to be
	// operated upon either by affectation or incrmenetation/decremation
	// and by the usual unary operators.

	while ((rptr = vptr->value) != (struct operand*) 0) {
		if ( rptr->type == _ARRAY )
			return( use_dimensioned(vptr, rptr) );
		else if ( rptr->type == _OBJECT ) {
			if (!(wptr = resolve_member(vptr) ))
				break;
			else	{
				vptr = wptr;
				continue;
				}
			}
		else if ( rptr->type == _FUNCTION) {
			operation = rptr->pointer;
			return( (*operation)() );
			}
		}

	if (( c = not_white()) == '=')

		return( store( vptr, expression() ) );

	else	{


		ungetch(c);

		if ((operator = get_operator()) != 0) {

			if (( cc = not_white() ) == operator ) {
				// increment or decrement pehaps
				rptr = make_number( 1L );
				return( store( vptr, perform_operation( vptr->value, operator, rptr ) ));
				}
			else if ( cc == '=' )
				return( store( vptr, perform_operation( vptr->value, operator, expression() ) ));

			else	return( jserror(555) );
			}
		else	
			return( jserror( 777) );							

		}

}


//	-----------------------------------------------------------------
//	This function will scan the member array of the object variable
//	to locate an entry of the required name which will be returned
//	to the caller.
//	-----------------------------------------------------------------

struct variable * locate_member(struct variable * vptr, char * nptr )
{
	struct	operand * rptr;
	long		  i=0L;
	struct variable * mptr;
	int		  h;

	// Ensure valid variable parameter
	// -------------------------------
	if (( vptr != (struct variable*) 0)

	// Ensure variable has valid value
	// -------------------------------
	&&  ((rptr = vptr->value) != (struct operand *) 0)

	// Ensure the variable value is of type object
	// -------------------------------------------
	&&  ( rptr->type == _OBJECT )

	// Ensure that the Object Member Array is Valid
	// --------------------------------------------
	&&  ( rptr->pointer != (void *) 0))

		// Scan Object Member Array to detect named member
		// -----------------------------------------------
		for (h=calculate_hash_code(nptr),i=0L; i < rptr->value; i++ )

			// Ensure Valid member entry
			// -------------------------
			if (((mptr = array_member( rptr->pointer, i )) != (struct variable *) 0)

			// Ensure Valid member name
			// ------------------------
			&&  ( mptr->name != (char *) 0 )

			// Ensure member name match found
			// ------------------------------
			&& ( h == mptr->hash )
			&& ( compare( mptr->name, nptr ) ))

				// Yes : matching member found
				// ---------------------------
				return(mptr);


	// Failure, member match not found
	// -------------------------------
	return((struct variable *) 0);

}

int	new_object( struct variable * vptr, struct variable * mptr )
{
	struct	operand * rptr;

	if (!(rptr = new_array(1)))
		return(27);
	else	{
		if ( vptr->value )
			vptr->value = liberate_operand( vptr->value );
		rptr->type = _OBJECT;
		vptr->value = rptr;
		return(store_array(rptr->pointer,0,mptr));
		}
}

int	add_member( struct variable * vptr, struct variable * mptr )
{
	struct	operand * rptr;
	void		* wptr;
	
	// Ensure valid variable parameter
	// -------------------------------
	if (!( vptr ))
		return(55);

	// Detect variable with valid value
	// --------------------------------
	if (!(rptr = vptr->value))
		return( new_object( vptr, mptr ) );

	// Is it already an object
	// -----------------------
	else if ( rptr->type != _OBJECT )
		return( new_object( vptr, mptr ) );

	// It is already an object and will need to be extended
	// ----------------------------------------------------
	else if (!(wptr = copy_array(rptr , 1) ))
		return( 27 );

	else	{
		// Release previous object
		// -----------------------
		rptr->pointer = liberate( rptr->pointer );

		// And set new extended object with new member
		// -------------------------------------------
		rptr->pointer = wptr;	
		return(store_array(rptr->pointer,rptr->value++,mptr));
		}
}



int	translate_member()
{
	int	status=0;
	int	c;
	struct variable * vptr=(struct variable *) 0;
	struct variable * mptr=(struct variable *) 0;

	// Locate Object Variable 
	// ----------------------
	if (!(vptr = locate_variable( token_buffer ))) {

		// Create new variable if not already existant
		// -------------------------------------------
		if (!(vptr = new_variable( token_buffer)))
			return( 27 );
		else if ((status = add_variable( vptr )) != 0) {
			vptr = liberate_variable(vptr);
			return( status );
			}
		}

	// collect member name create if not already existant
	// --------------------------------------------------
	do	{

		// Collect member name token
		// -------------------------
		if (!( get_token() ))
			return(30);

		// Locate member in current object
		// -------------------------------
		else if (!(mptr = locate_member( vptr, token_buffer ) )) {

			// Add new member to this object if not found
			// ------------------------------------------
			if (!(mptr = new_variable( token_buffer)))
				return( 27 );
			else if ((status = add_member( vptr, mptr )) != 0) {
				mptr = liberate_variable(mptr);
				return( status );
				}
			}
		// New member becomes the current object !
		// ---------------------------------------
		vptr = mptr;
		}
	while ((c = not_white()) == '.');

	if ( c == '=' ) 
		return( store( vptr, expression() ) );

	else	{
		ungetch(c);
		return(0);
		}

}

struct variable * declare_variable(char * vname)
{
	struct variable * vptr=(struct variable *) 0;
	if ((vptr = new_variable( vname )) != (struct variable *) 0)
		if ( add_variable( vptr ) != 0) 
			vptr = liberate_variable(vptr);
	return(vptr);
}

int	translate_variable()
{
	struct variable * vptr=(struct variable *) 0;
	int	status;
	int	c;

	while (1) {

		if (!( get_token() ))
			return( 30 );

		else if ((c = not_white()) == '.') {
			if ((status = translate_member()) != 0)
				return( status );
			}
		else	{
			ungetch(c);
			if (!(vptr = declare_variable(token_buffer)))
				return(27);
			else if ((c = not_white()) == '=') {
				if ((status = store( vptr, expression() )) != 0)
					return(status );
				}
			else	ungetch(c);
			}

		switch ((c = not_white())) {
			case	0  :
			case	-1 : return(48);
			case	',': continue;
			default	   : 
				ungetch(c);
				return(0);
			}
		}
}


