FILE	*	fh=(FILE *) 0;
int		ungotc=0;
char		token_buffer[1024];

int	calculate_hash_code( char * nptr )
{
	int	r=0;
	while ( *nptr )
		r += *(nptr++);
	return( (r % _JSP_HASH_VALUE) );
}

int	jserror( int value )
{
	if ( value ) {
		printf("\njavascript error : %u near %s \n",value,token_buffer);
		}
	return(value);
}

int	compare( char * aptr, char * bptr )
{
	while (( *aptr != 0 )
	&&     ( *bptr != 0 ))
		if ( *(aptr++) != *(bptr++) )
			return(0);

	if ( *aptr != *bptr )
		return(0);
	else	return(1);
}

int	scompare( char * aptr, char * bptr )
{
	while (( *aptr != 0 )
	&&     ( *bptr != 0 )) {
		if ( *aptr != *bptr )
			return(*aptr - *bptr);
		else	{
			aptr++; bptr++;
			}
		}

	return(*aptr - *bptr);
}


void	ungetch( int c )
{
	if ( c != 0 )
		ungotc = ((ungotc << 8) | (c & 0x00FF));
	return;
}

int	getch()
{
	int	c;
	if ((c = (ungotc & 0x00FF)) != 0)  {
		ungotc = ((ungotc >> 8) & 0x00FF);
		return(c);
		}
	else if ( fh != (FILE *) 0)
		if ((c = fgetc( fh )) < 0)
			c = 0;

	if ( c == 0x001A ) 
		c = 0;

	else if ( echo != 0) 
		if ( c )
			printf("%c",c);

	return(c);
}

int	monolinecomment()
{
	int	c;
	while (((c = getch()) != 0)
	&&     ( c != '\n'));
	return(c);
}

int	multilinecomment()
{
	int	c;
	while ((c = getch()) != 0) {
		if ( c == '*' ) {
			if ((c = getch()) == '/' )
				break;
			else	ungetch(c);
			}
		}
	return(c);
}

int	is_white(int c )
{
	int	cc;
	switch ((c & 0x00FF)) {
		case	'\n'	:
		case	'\r'	:
		case	'\t'	:
		case	' '	:
			return(c);
		case	'/'	:
			switch ((cc = getch())) {
				case	'/'	: return( monolinecomment() );
				case	'*'	: return( multilinecomment() );
				default		:
					ungetch(cc);
					return(0);
				}
		default		:
			return(0);
		}
}


int	remove_white_space()
{
	int	c;
	while ((c = getch()) != 0) {
		if ( is_white( c ) )
			continue;
		else	{
			ungetch( c );
			return( c );
			}
		}
	return(0);
}

int	is_punctuation( int c )
{
	if (( c >='a' )
	&& ( c <='z' ))
		return(0);
	else if (( c >='A' )
	     && ( c <='Z' ))
		return(0);
	else if (( c >='0' )
	     && ( c <='9' ))
		return(0);
	else if ( c == '_' )
		return(0);
	else if ( c == '$' )
		return(0);
	else	return(c);
}
	
int	skip_block()
{
	int	c;

	int	bracing=0;
	int	quoting=0;
	int	nesting=0;

	while (1) {

		switch ((c = not_white())) {
			case	0	:
			case	-1	:
				return( jserror(48) );
			case	'{'	:
				if (!( quoting ))
					nesting++;
				continue;
			case	'}'	:
				if (!( quoting )) {
					nesting--;
					if (!( nesting ))
						return(0);
					}
				continue;

			case	0x0022	:	// double quote
			case	0x0027	:	// single quote
				if (!( quoting ))
					quoting = c;
				else if ( quoting == c )
					quoting = 0;
				continue;
			case	'('	:
				if (!( quoting ))
					bracing++;
				continue;
			case	')'	:
				if (!( quoting ))
					if (bracing)
						bracing--;
				continue;

			case	';'	:
				if ((!( quoting ))
				&&  (!( bracing ))
				&&  (!( nesting )))
					return(0);

			}
		}

}


int	get_token()
{
	int	c;
	int	i=0;
	int	quoting=0;
	char *	tptr = token_buffer;
	int	tlen = 1024;

	if (!( remove_white_space() ))
		return(0);

	while ((c = getch()) > 0) {

		if ( c == quoting ) {
			*(tptr+(i++)) = c;
			break;
			}
		else if (quoting ) {
			if ( i < (tlen-1) ) {
				*(tptr+(i++)) = c;
				continue;
				}
			else	{
				ungetch(c);
				break;
				}
			}

		else if ( is_white( c ) ) {
			ungetch(c);
			break;
			}

		else if (( c == 0x0022 )
		     ||  ( c == 0x0027 )) {
			*(tptr+(i++)) = c;
			quoting = c;
			continue;
			}
		else if ( is_punctuation( c ) ) {
			ungetch(c);
			break;
			}
		else if ( i < (tlen-1) ) {
			*(tptr+(i++)) = c;
			continue;
			}
		else	{
			ungetch(c);
			break;
			}
		}
	*(tptr +i) = 0;
//	if ( debug ) printf("[%s]",token_buffer);
	return( i );
}

int	not_white()
{
	int	c;
	while(1) {
		if (!(c = getch()))
			return(c);
		else if (!( is_white(c) ))
			return(c);
		}
}

int	get_operator()
{
	int	value;

	if ( debug )
		printf("get_operator()\n");
	switch ((value = not_white())) {
		case	'+'	:
		case	'-'	:
		case	'/'	:
		case	'*'	:
		case	'&'	:
		case	'|'	:
		case	'^'	:
		case	'%'	:
		case	'~'	:
			return(value);
		default		:
			ungetch(value);
			return(0);
		}
}

int	get_condition()
{
	int	value;

	if ( debug )
		printf("get_condition()\n");

	switch ((value = not_white())) {
		case	'='	: return( _equal );
		case	'>'	:
			if ((value = not_white()) == '=')
				return( _greater_or_equal );
			else	{
				ungetch( value );
				return( _greater_than );
				}

		case	'<'	:
			if ((value = not_white()) == '=')
				return( _less_or_equal );
			else	{
				ungetch( value );
				return( _less_than );
				}
		case	'!'	:
			if ((value = not_white()) == '=')
				return( _not_equal );
			else	ungetch( value );

		default		:
			ungetch(value);
			return(-1);
		}
}


