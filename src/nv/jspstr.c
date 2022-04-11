#define	_string_primatives	2

static	char * StringPrimative[ _string_primatives ] = {
	(char *) "toUpperCase",
	(char *) "toLowerCase"
	};

#define _toUpperCase	0
#define _toLowerCase	1

int	is_string_primative( char * token_buffer )
{
	int	i;
	for (i=0; i < _string_primatives; i++ )
		if ( compare( token_buffer, StringPrimative[i] ) )
			return(i);
	return(-1);
}


struct operand * toUpperCase(struct operand * rptr)
{
	char	*sptr;
	if (( not_white() == '(')
	&&  ( not_white() == ')')
	&&  (( rptr = copy_operand( rptr )) != (struct operand*) 0))
	 	for( sptr=rptr->pointer; *sptr != 0; sptr++ )
			if (( *sptr >= 'a' ) && ( *sptr <= 'z' ))
				*sptr &= ~0x0020;
	return( rptr );
}

struct operand * toLowerCase(struct operand * rptr)
{
	char	*sptr;
	if (( not_white() == '(')
	&&  ( not_white() == ')')
	&&  (( rptr = copy_operand( rptr )) != (struct operand*) 0))
	 	for( sptr=rptr->pointer; *sptr != 0; sptr++ )
			if (( *sptr >= 'A' ) && ( *sptr <= 'Z' ))
				*sptr |= 0x0020;
	return( rptr );
}

struct operand * string_method(struct operand * rptr)
{
	int	mid;
	if ( rptr->type != _STRING )
		return( rptr );
	else if (!( get_token() ))
		return( rptr );
	else if (( mid = is_string_primative(token_buffer)) == -1)
		return(rptr);
	else	{
		switch ( mid ) {
			case	_toUpperCase	:
				return( toUpperCase( rptr ) );
			case	_toLowerCase	:
				return( toLowerCase( rptr ) );
			default			:
				return( rptr );
			}
		}
}


