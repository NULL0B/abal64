#ifndef	_jsp_lang_c
#define	_jsp_lang_c

#define	_keyword_if		0x0000
#define	_keyword_do		0x0001
#define	_keyword_for		0x0002
#define	_keyword_var		0x0003
#define	_keyword_else		0x0004
#define	_keyword_case		0x0005
#define	_keyword_break		0x0006
#define	_keyword_while		0x0007
#define	_keyword_switch		0x0008
#define	_keyword_return		0x0009
#define	_keyword_continue	0x000A
#define	_keyword_function	0x000B
#define	_keyword_include 	0x000C
#define	_javascript_keywords 	0x000D

static	char * keyword[_javascript_keywords] = {
	(char *) "if",
	(char *) "do",
	(char *) "for",
	(char *) "var",
	(char *) "else",
	(char *) "case",
	(char *) "break",
	(char *) "while",
	(char *) "switch",
	(char *) "return",
	(char *) "continue",
	(char *) "function",
	(char *) "include"
	};

int	is_keyword( char *token )
{
	int	i;

	for (i=0; i < _javascript_keywords; i++ )
		if ( compare( token , keyword[i] ) )
			return(i);
	return(-1);
}


int	number_compare(	struct operand * lptr, int operator,struct operand * rptr )
{
	switch ( operator ) {
		case	_equal			:
			if ( lptr->value == rptr->value )
				return(1);
			else	return(0);
		case	_not_equal		:
			if ( lptr->value != rptr->value )
				return(1);
			else	return(0);
		case	_less_than		:
			if ( lptr->value < rptr->value )
				return(1);
			else	return(0);
		case	_greater_than		:
			if ( lptr->value > rptr->value )
				return(1);
			else	return(0);
		case	_greater_or_equal	:
			if ( lptr->value >= rptr->value )
				return(1);
			else	return(0);
		case	_less_or_equal		:
			if ( lptr->value <= rptr->value )
				return(1);
			else	return(0);
		default				:
			return(0);
		}
}

int	string_compare(	struct operand * lptr, int operator,struct operand * rptr )
{
	switch ( operator ) {
		case	_greater_or_equal	:
			if ( scompare( lptr->pointer , rptr->pointer) >= 0 )
				return(1);
			else	return(0);
		case	_less_or_equal		:
			if ( scompare( lptr->pointer , rptr->pointer) <= 0 )
				return(1);
			else	return(0);
		case	_equal			:
			if ( scompare( lptr->pointer , rptr->pointer) == 0 )
				return(1);
			else	return(0);

		case	_greater_than		:
			if ( scompare( lptr->pointer , rptr->pointer) > 0 )
				return(1);
			else	return(0);
		case	_less_than		:
			if ( scompare( lptr->pointer , rptr->pointer) < 0 )
				return(1);
			else	return(0);
		case	_not_equal		:
			if ( scompare( lptr->pointer , rptr->pointer) != 0)
				return(1);
			else	return(0);
		default				:
			return(0);
		}
}


int	test_condition(	struct operand * lptr, int operator,struct operand * rptr )
{
	if (!( lptr )) 	
		return(0);
	else if (!( rptr ))
		return(0);

	switch ( lptr->type ) {	
		case	_NUMBER	:
			switch ( rptr->type ) {	
				case	_STRING	:
					if (!(rptr = convert_number( rptr )))
						return(0);
				case	_NUMBER	:
					return( number_compare( lptr, operator, rptr ) );
				default		:
					return(0);	
				}


		case	_STRING	:
			switch ( rptr->type ) {	
				case	_NUMBER	:
					if (!(rptr = convert_string( rptr )))
						return(0);

				case	_STRING	:
					return( string_compare( lptr, operator, rptr ) );

				default		:
					return(0);	


				}

		default		:
			return(0);	


		}
}

int	conditional()
{
	struct operand * lptr;
	int	operator=0;
	struct operand * rptr;
	if (!(lptr = expression() )) {
		(void) jserror(70);
		return(0);
		}
	else if ((operator = get_condition()) == -1) {
		if (!( rptr = make_number(0) ))
			(void) jserror(71);
		else 	operator = _not_equal;
		}
	else if (!(rptr = expression() )) {
		(void) jserror(72);
		return(0);
		}
	return( test_condition( lptr, operator, rptr ) );
}

int	translate_if() 
{
	int	status;
	if ( not_white() != '(' )
		return(56);

	status = conditional();

	if ( not_white() != ')' )
		return(56);
	else if (!( status ))
		return( skip_block() );
	else	return(0);
}

int	translate_else() 
{
	return(56);
}

int	translate_for() 
{
	return(56);
}

int	translate_while() 
{
	return(56);
}

int	translate_do() 
{
	return(56);
}

int	translate_switch() 
{
	return(56);
}

int	translate_continue() 
{
	return(56);
}

int	translate_break() 
{
	return(56);
}

int	translate_return() 
{
	return(56);
}


int	include_file( char * nptr )
{
	FILE *	fholder=fh;
	int	status;
	fh = (FILE *) 0;
	status = include( nptr );
	fh = fholder;
	return(status);
}
	


int	translate_token( char * token )
{
	int	k=0;

	switch ((k = is_keyword( token ))) {

		case	_keyword_var		:
			return( translate_variable() );
		case	_keyword_function	:
			return( translate_function() );
		case	_keyword_if		:
			return( translate_if() );
		case	_keyword_else		:
			return( translate_else() );
		case	_keyword_for		:
			return( translate_for() );
		case	_keyword_while		:
			return( translate_while() );
		case	_keyword_do		:
			return( translate_do() );
		case	_keyword_switch		:
			return( translate_switch() );
		case	_keyword_continue	:
			return( translate_continue() );
		case	_keyword_break		:
			return( translate_break() );
		case	_keyword_return		:
			return( translate_return() );

		case	_keyword_include	:
			if (!( get_token() ))
				return(jserror(30));
			else	return( include_file( token_buffer ) );

		default		:
			return( statement( token ) );
		}

}


#endif	// _jsp_lang_c


