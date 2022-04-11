struct	function * Functions=(struct function *) 0;


struct function * locate_function( char * nptr )
{
	int	h;
	struct function * fptr=(struct function *) 0;
	if ( nptr != (char *) 0 )
		for (h=calculate_hash_code(nptr),fptr=Functions; fptr != (struct function *) 0; fptr = fptr->next)
			if ( fptr->name != (char *) 0 )
				if (( h == fptr->hash )
				&&  ( compare(nptr,fptr->name ) ))
					break;
	return(fptr);
}

struct function * liberate_function(	struct function * fptr )
{
	struct variable * vptr;
	if ( fptr ) {

		if ( fptr->name )
			fptr->name = liberate( fptr->name );

		while ((vptr = fptr->first) != (struct variable *) 0) {
			fptr->first = vptr->next;
			vptr = liberate_variable( vptr );
			}

		fptr = liberate( fptr );

		}
	return( (struct function *) 0 );
}

void	release_functions()
{
	struct function * fptr=(struct function *) 0;
	while ((fptr = Functions) != (struct function *) 0) {
		Functions = fptr->next;
		fptr = liberate_function( fptr );
		}
	return;
}


int	add_parameter( struct function * fptr, char * nptr )
{
	struct variable * vptr;

	if (!(vptr = new_variable( nptr )))
		return( 27 );
	else 	{
		if ((vptr->previous = fptr->last))
			fptr->last->next = vptr;
		else	fptr->first = vptr;
		fptr->last = vptr;
		return(0);
		}
}

int	add_function( struct function * fptr )
{
	if ( fptr ) {
		if ( debug )
			printf("add_function(%s)\n",fptr->name);
		if ((fptr->next = Functions) != (struct function *) 0)
			Functions->previous = fptr;
		Functions = fptr;
		}
	return(0);
}

struct function * new_function( char * nptr )
{
	struct function * fptr=(struct function *) 0;
	if ((fptr = allocate( sizeof( 	struct function ) )) != (struct function *) 0) {
		fptr->next = fptr->previous = fptr->caller = fptr->first = fptr->next = fptr->name = 0;
		if (!(fptr->name = allocate_string( nptr )))
			fptr = liberate_function(fptr);
		else	fptr->hash = calculate_hash_code( nptr );
		}
	return(fptr);
}


int	translate_function()
{
	int	c;
	int	braces=0;
	int	status=0;
	struct function * fptr=(struct function *) 0;
	if (!( get_token() ))
		return( 30 );
	else if (!(fptr = new_function( token_buffer ) ))
		return( 27 );
	else	add_function( fptr );

	if ( not_white() != '(' )
		return( 31 );
	else	{
		do	{
			if ( get_token() )
				if ((status = add_parameter( fptr, token_buffer )) != 0)
					return(status );
			}
		while ((c = not_white()) == ',');
		if ( c != ')' ) 
			return(33);
		else if ((c = not_white()) != '{' )
			ungetch(c);
		else	braces=1;
		while ( braces ) {
			if (!( remove_white_space()))
				return( 0 );
			else if ( get_token() )
				continue;
			else if ((c = not_white()) == '{')
				braces++;
			else if ( c == '}' ) {
				if ( braces )
					braces--;
				else	break;
				}
			}
		return(0);
		}
}

int	call_method( struct function * fptr )
{
	int	status=0;
	struct variable * vptr=(struct variable *)0;
	struct operand * rptr;
	int	c;
	vptr=fptr->first; 

	if (( c = not_white()) != '(' )
		return(jserror(109));

	while ( vptr ) {
		if (!(rptr = expression() ))
			return(jserror(110));
		else if ((status = store( vptr, rptr )) != 0)
			return( jserror(status));
		else if ((c = not_white()) == ',' )
			vptr = vptr->next;
		else if (c != ')' )
			return( jserror(111) );
		else if (!(vptr = vptr->next))
			break;
		else	return( jserror(112) );
		}

	return(0);
}

struct operand * call_function( struct function * fptr )
{
	int	status;
	struct variable * vptr=(struct variable *)0;
	struct operand * rptr=(struct operand*)0;
	int	c;
	vptr=fptr->first; 

	if (( c = not_white()) != '(' )
		return(jserror(109));

	while ( vptr ) {

		if (!(rptr = expression() )) {
			jserror(110);
			return(0);
			}
		else if ((status = store( vptr, rptr )) != 0) {
			jserror(status);
			return(0);
			}
		else if ((c = not_white()) == ',' )
			vptr = vptr->next;
		else if (c != ')' ) {
			jserror(111);
			return(0);
			}
		else if (!(vptr = vptr->next))
			break;
		else	{
			jserror(112);
			return(0);
			}
		}

	return(make_number(0L));
}


