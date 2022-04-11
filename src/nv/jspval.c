struct operand * 	ValueHeap=(struct operand *) 0;
struct operand * 	WorkHeap=(struct operand *) 0;

char	longbuffer[64];

char *	allocate_string( char * sptr )
{
	char * rptr;
	if ((rptr = allocate( strlen( sptr ) + 1 )) != (char *) 0)
		strcpy(rptr, sptr );
	return(rptr);
}

char	*	longtostring( long value )
{
	sprintf(longbuffer,"%ld",value);
	return(value);
}

long	stringtolong( char * tptr, int indent )
{
	long	result=0L;
	tptr += indent;	
	
	if (( *tptr == '0' )
	&&  (( *(tptr+1) == 'x' ) &&  ( *(tptr+1) == 'X' ))) {
		// Hexadecimal conversion
		tptr += 2;
		while ( *tptr ) {
			if (( *tptr >= '0') && ( *tptr <= '9'))
				result = ((result * 16) + (*(tptr++) - '0'));
			else if (( *tptr >= 'a') && ( *tptr <= 'f'))
				result = ((result * 16) + (*(tptr++) - 'a') + 10);
			else if (( *tptr >= 'A') && ( *tptr <= 'F'))
				result = ((result * 16) + (*(tptr++) - 'A') + 10);
			else	break;
			}
		}
	else	{
		// Decimal conversion
		while ( *tptr ) {
			if (( *tptr >= '0') && ( *tptr <= '9'))
				result = ((result * 10) + (*(tptr++) - '0'));
			else	break;
			}
		}
	if ( indent )
		result *= -1L;

	return( result );

}

struct operand * liberate_operand( struct operand * rptr )
{
	if ( rptr ) {
		if (!( rptr->linkage )) {
			switch ( rptr->type ) {
				case	_STRING :
				case	_ARRAY  :
					rptr->pointer = liberate( rptr->pointer );
				}
			rptr->pointer = ValueHeap;
			ValueHeap = rptr;
			}
		}
	return( (struct operand *) 0 );
}

struct operand * allocate_operand()
{
	struct operand * rptr;
	if ((rptr = ValueHeap) != (struct operand *) 0)
		ValueHeap = rptr->pointer;

	else if ((rptr = allocate( sizeof( struct operand ) )) == (struct operand *) 0) 
		return( rptr );

	rptr->pointer = (void *) 0;
	rptr->type    = _NUMBER;
	rptr->value   = 0L;
	return( rptr );
}
	

struct operand * make_string( char * sptr )
{
	struct operand * rptr;
	if ((rptr = allocate_operand())!=(struct operand *) 0) {
		if ((rptr->pointer = allocate_string( sptr )) != (char *) 0) {
			rptr->type  = _STRING;
			rptr->linkage = WorkHeap;
			}
		else	rptr = liberate_operand( rptr );
		}
	return(rptr);
}

struct operand * make_number( long value )
{
	struct operand * rptr;
	if ((rptr = allocate_operand())!=(struct operand *) 0) {
		rptr->type  = _NUMBER;
		rptr->value = value;
		rptr->linkage = WorkHeap;
		}
	return(rptr);
}

void release_operands()
{
	struct operand * rptr;
	while ((rptr = ValueHeap) != (struct operand *) 0) {
		ValueHeap = rptr->pointer;
		rptr = liberate( rptr );
		}
	return;
}

void 	release_temporary()
{
	struct operand * rptr;
	while ((rptr = WorkHeap) != (struct operand *) 0) {
		ValueHeap = rptr->linkage;
		rptr->linkage = (struct operand *) 0;
		rptr = liberate_operand( rptr );
		}
	return;
}


struct operand * number_term( char * tptr )
{
	struct operand * rptr=(struct operand *) 0;
	int	negative=0;
	long	result=0L;

	if ( debug )
		printf("number_term()\n");

	if (( *tptr >= '0' )
	&&  ( *tptr <= '9' ))
		return( make_number( stringtolong( tptr, 0) ) );
	else if ( *tptr == '-' )
		return( make_number( stringtolong( tptr, 1) ) );
	else if ( compare( tptr, "false" ) )
		return( make_number( 0L ) );
	else if ( compare( tptr, "true" ) )
		return( make_number( 1L ) );
	else	return( rptr );
}


struct operand * string_term( char * tptr )
{
	int	i;
	int	c;
	struct operand * rptr=(struct operand *) 0;

	if (((c = *tptr) == 0x0022 )
	||  ( c          == 0x0027 )) {
		tptr++;
		for (i=0; *(tptr +i) != 0; i++ )
			if ( *(tptr + i) == c )
				break;
		*(tptr + i) =0;
		rptr = make_string( tptr );
		}
	return(rptr);
}

void	*	copy_array( struct operand * rptr, int extra )
{
	void **	vptr;
	void **	xptr;
	int	i,l;
	if (!( xptr = allocate((int)( sizeof(void *) * (rptr->value+extra) ) )))
		return(xptr);
	else	{
		vptr = (void **) rptr->pointer;
		for (i=0, l=(int)rptr->value; i < l; i++)
			xptr[i] = vptr[i];
		return( xptr );
		}
}

struct operand * copy_operand( struct operand * rptr )
{
	struct operand * xptr;
	if (!(xptr = allocate_operand()))
		return(xptr);
	else 	{
		switch ((xptr->type = rptr->type)) {
			case	_NUMBER	:
				xptr->value = rptr->value;
				break;

			case	_STRING	:
				xptr->pointer = allocate_string( rptr->pointer );
				break;

			case	_OBJECT		:
			case	_ARRAY	:
				xptr->value   = rptr->value;
				xptr->pointer = copy_array( rptr, 0 );
				break;

			case	_FUNCTION	:
				xptr->value   = rptr->value;
				xptr->pointer = rptr->pointer;
				break;


			}
		return( xptr );
		}
}
	



struct operand * convert_string( struct operand * rptr )
{
	while ( rptr ) {
		if ( rptr->type == _STRING  )
			return( rptr );
		else if ( rptr->type == _NUMBER )
			return( make_string( longtostring( rptr->value ) ) );
		else 	rptr = evaluate( rptr );
		}
	return( rptr );
}

struct operand * convert_number( struct operand * rptr )
{
	char	* tptr;
	while ( rptr ) {
		if ( rptr->type == _NUMBER )
			return( rptr );
		else if ( rptr->type == _STRING ) {
			if (!( tptr = rptr->pointer ))
				break;
			else	return( make_number( stringtolong( tptr, (*tptr == '-' ? 1 : 0) ) ) );
			}
		else 	rptr = evaluate( rptr );
		}
	return( rptr );
}


struct operand * variable_term( char * tptr )
{
	int	c;
	void	**	 lptr;
	struct operand * rptr=(struct operand *) 0;
	struct operand * xptr=(struct operand *) 0;
	struct variable * vptr;
	if ((vptr = locate_variable( tptr )) != (struct variable *) 0) {
		if ((rptr = vptr->value) != (struct operand *) 0) {
			while (1) {
				if ( rptr->type == _ARRAY ) {
					if ((c= not_white()) != '[') {
						ungetch(c); break;
						}
					else if (!(xptr = expression())) {
						jserror(203); break;
						}
					else if (not_white() != ']') {
						jserror(204); break;
						}
					if ( xptr->type != _NUMBER )
						xptr = convert_number( xptr );
					else if ( xptr->value > rptr->value ) {
						jserror(103); break;
						}
					else	{
						lptr = (void **) rptr->pointer;
						rptr = lptr[xptr->value];
						}
					}
				else if ( rptr->type == _OBJECT ) {
					if ((c= not_white()) != '.') {
						ungetch(c); break;
						}
					else if (!( get_token() )) {
						jserror(30); break;
						}
					else if (!(vptr = locate_member( vptr, token_buffer ))) {
						jserror(33); break;
						}
					else if (!(rptr = vptr->value )) {
						jserror(34); break;
						}
					else	continue;		
					}
				else if ((c = not_white()) == '.') {
					// The primative entity member
					// will be a method of its primative
					// class applied to itself
					// ---------------------------------
					if ( rptr->type == _NUMBER )
						rptr = number_method( rptr );
					else if ( rptr->type == _STRING )
						rptr = string_method( rptr );
					break;
					}
				else	{
					ungetch(c);
					break;
					}
				}
			}
		}
	return(rptr);
}

struct operand * function_term( char * tptr )
{
	struct operand * rptr=(struct operand *) 0;
	struct function * fptr;
	if ((fptr = locate_function( tptr )) != (struct function *) 0)
		rptr = call_function( fptr );
	return(rptr);
}

struct operand * new_array(long dimension)
{
	struct operand * rptr=(struct operand *) 0;
	void	*	vptr;
	if (!( rptr = allocate_operand()))
		return( rptr );
	else if (!( vptr = allocate((int)(sizeof( void * ) * dimension))))
		return( liberate_operand( rptr ) );
	else	{
		rptr->type = _ARRAY;
		rptr->value= dimension;
		rptr->pointer = vptr;
		return( rptr );
		}
}

struct operand * native_term()
{
	struct operand * rptr=(struct operand *) 0;
	void	*	vptr;
	int	i;
	if ( get_token() != 0) {
		if (( rptr = allocate_operand()) != (struct operand*) 0) {
			for ( i=0; i < MAX_NATIVE; i++ ) {
				if ( compare( token_buffer, NativeName[i] ) ) {
					rptr->type = _FUNCTION;
					rptr->pointer = NativeFunction[i];
					break;
					}
				}
			}
		}
	return( rptr );
}

struct operand * new_term()
{
	long	 dimension=0L;
	if (!( remove_white_space() ))
		return((struct operand *) 0);
	else if (!(get_token()))
		return((struct operand *) 0);
	else if (!( compare( token_buffer, "Array" ) ))
		return((struct operand *) 0);
	else if ( not_white() != '(')
		return((struct operand *) 0);
	else if (!(get_token()))
		return((struct operand *) 0);
	else if ((dimension = stringtolong(token_buffer,0)) == 0L)
		return((struct operand *) 0);
	else if ( not_white() != ')')
		return((struct operand *) 0);
	else 	return( new_array( dimension ) );

}




struct operand * evaluate_term()
{
	int	c;
	struct operand * rptr=(struct operand *) 0;

	if ( debug )
		printf("evaluate_term()\n");

	if (( c = not_white()) == '(')

		return( expression() );

	else if (!( c ))
		return( rptr );

	else	{
		
		ungetch(c);

		if (!(get_token()))
			return(rptr);

		else if ( compare( token_buffer, "new" ) )
			return( new_term() );

		else if ( compare( token_buffer, "native" ) )
			return( native_term() );

		else if ((rptr = number_term ( token_buffer )) != (struct operand *) 0)
			return(rptr);

		else if ((rptr = string_term  ( token_buffer )) != (struct operand *) 0)
			return(rptr);

		else if ((rptr = variable_term( token_buffer )) != (struct operand *) 0)
			return(rptr);

		else 	return( function_term( token_buffer ) );

		}

}

struct operand * evaluate( struct operand * operand )
{
	struct variable * vptr;
	if (!( operand ))
		return( operand );
	switch ( operand->type ) {
		case	_NUMBER : 
		case	_STRING	 :
			return( operand );
		case	_VARIABLE:
			if ((vptr = operand->pointer) != (struct variable *) 0)
				return( vptr->value );
			else	return( (struct operand * ) 0 );
		default		:
			return( (struct operand * ) 0 );
		}
}

struct operand * string_operation( struct operand * lptr, int operation, struct operand * rptr )
{
	char * result="\0";
	char	*slptr;
	char	*rlptr;
	while ( rptr->type != _STRING )
		if (!(rptr = convert_string( rptr )))
			return( rptr );

	switch ( operation ) {
		case	'+'	: 
			if (((slptr = lptr->pointer) != (char *) 0)
			&&  ((rlptr = rptr->pointer) != (char *) 0)
			&&  ((result= allocate( strlen(slptr) + strlen(rlptr) + 1 )) != (char *) 0))
				sprintf(result,"%s%s",slptr,rlptr);
			else	result = "\0";

		}
	return( make_string( result ) );
	
}
struct operand * number_operation( struct operand * lptr, int operation, struct operand * rptr )
{
	long	rvalue=0L;
	while ( rptr->type != _NUMBER )
		if (!(rptr = convert_number( rptr )))
			return( rptr );

	switch ( operation ) {
		case	'+'	: rvalue = lptr->value + rptr->value; break;
		case	'-'	: rvalue = lptr->value - rptr->value; break;
		case	'*'	: rvalue = lptr->value * rptr->value; break;
		case	'/'	: rvalue = lptr->value / rptr->value; break;
		case	'%'	: rvalue = lptr->value % rptr->value; break;
		case	'^'	: rvalue = lptr->value ^ rptr->value; break;
		case	'&'	: rvalue = lptr->value & rptr->value; break;
		case	'|'	: rvalue = lptr->value | rptr->value; break;
		case	'!'	: rvalue = ! lptr->value; break;
		case	'~'	: rvalue = ~ lptr->value; break;
		}

	return( make_number( rvalue ) );
}
struct operand * perform_operation( struct operand * lptr, int operation, struct operand * rptr )
{
	if (!( lptr ))
		return( lptr );

	while (( lptr->type == _VARIABLE )
	   ||  ( lptr->type == _FUNCTION ))
		if (!( lptr = evaluate( lptr ) ))
			return( lptr );

	if ( lptr->type == _NUMBER )
		return( number_operation( lptr, operation, rptr ) );
	else if ( lptr->type == _STRING )
		return( string_operation( lptr, operation, rptr ) );
	else	return( (struct operand *) 0 );
}


