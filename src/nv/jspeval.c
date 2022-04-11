
void	write_operand( struct operand * optr )
{
	long	i;

	if (!( optr )) 

		printf(" Null ");

	else	{

		switch ( optr->type ) {
			case _NUMBER :
				printf(" %lu",optr->value);
				break;
			case _STRING :
				printf("%s",optr->pointer);
				break;
			case _ARRAY  :
				for (i=0L; i < optr->value; i++ )
					write_operand( array_member( optr->pointer, i ) );
			}
		}
	return;
}

int	document_write()
{
	int	c;
	struct operand * rptr;
	if ( not_white() != '(' )
		return(30);
	else	{
		while (1) {
			if ((rptr = expression())!=(struct operand*)0) {
				write_operand( rptr );
				if ((c = not_white()) == ',')
					continue;
				else	{
					ungetch(c);
					break;
					}
				}
			else	break;
			}
		printf("\n");
		if ( not_white() != ')' )
			return(30);
		else	return(0);
		}
}
		

int	evaluate_statement( char * token )
{
	int	c;
	struct variable * vptr;
	struct function * fptr;
	if ((fptr = locate_function( token )) != (struct function *) 0)
		return( call_method( fptr ) );
	else if ((vptr = locate_variable( token )) != (struct variable *) 0)
		return( use_variable( vptr ) );
	else if (!(c = not_white()))
		return( 48 );
	else	{
		ungetch(c);
		if (( c == '=' )
		&&  ((vptr = declare_variable(token))!= (struct variable *) 0))
			return( use_variable( vptr ) );
		else	return( 56 );
		}

}

int	statement( char * token )
{
	int	status=0;
	int	c;

	if (!(status = evaluate_statement( token )))
		if ((c = not_white()) != ';' )
			ungetch(c);

 	release_temporary();
	return( status );
}






