#define	_number_primatives	1

static	char * NumberPrimative[ _number_primatives ] = {
	(char *) "Square"
	};

#define _Square	0

int	is_number_primative( char * token_buffer )
{
	int	i;
	for (i=0; i < _number_primatives; i++ )
		if ( compare( token_buffer, NumberPrimative[i] ) )
			return(i);
	return(-1);
}


struct operand * Square(struct operand * rptr)
{
	if (( not_white() == '(')
	&&  ( not_white() == ')')
	&&  (( rptr = copy_operand( rptr )) != (struct operand*) 0))
		rptr->value *= rptr->value;
	return( rptr );
}

struct operand * number_method(struct operand * rptr)
{
	int	mid;
	if ( rptr->type != _STRING )
		return( rptr );
	else if (!( get_token() ))
		return( rptr );
	else if (( mid = is_number_primative(token_buffer)) == -1)
		return(rptr);
	else	{
		switch ( mid ) {
			case	_Square	:
				return( Square( rptr ) );
			default			:
				return( rptr );
			}
		}
}


