#ifndef	_yparse_c
#define _yparse_c

#define	maxtokensize 1024
#define	maxvaluesize 2048
char	tokenbuffer[maxtokensize];
char	valuebuffer[maxvaluesize];

int	igetch( FILE * h )
{
	int	c;
	if ((c = ungotch) != 0)
		ungotch = 0;
	else if ((c = fgetc(h)) <= 0)
		c =0;
	else if ( c == 0x001A)
		c = 0;
	else 	{
#ifdef	UNIX
		if ( c == '\\' ) c = '/';
#else
		if ( c == '/' ) c = '\\';
#endif	
		if ( echo )
			printf("%c",c);
		}
	return( c );
}

int	ungetch( int c )
{
	return((ungotch = c));
}

int	testch( FILE * h , int c)
{
	int	cc;
	if (!(cc = igetch(h)))
		return(0);
	else if ( cc == c )
		return(1);
	else	{
		ungetch(cc);
		return(0);
		}
}		

int	iswhitespace(int c)
{
	switch ( c ) {
		case	' '	:
		case	'\t'	:
		case	'\r'	:
		case	'\n'	:
			return(1);
		default		:
			return(0);
		}
}

int	iscomment( FILE * h, int c )
{
	if ( c != ';' )
		return(c);
	else	{
		while (1) {
			if (!(c = igetch(h)))
				return(0);
			else if ( c == '\n' )
				return(0);
			else	continue;
			}
		}
}



int	remove_white_space( FILE * h )
{
	int	c;
	while ((c = igetch(h)) != 0) {
		if (!( c=iscomment(h,c) ))
			continue;
		else if ( c == -1 ) 
			return(0); 
		else if ( iswhitespace(c) )
			continue;
		else 	return( ungetch(c) );
		}
	return(0);
}

int	getoken( FILE * h ) 
{
	int	i;
	int	c;

	if (!( remove_white_space( h ) )) return( 0 );

	for (i=0; i < maxtokensize; i++ ) {
		if (!( c = igetch(h)))
			break;
		if (( c == ']' )
		||  ( c == '=' )
		||  ( iswhitespace(c) )) {
			ungetch(c);
			break;
			}
		else if (!(c= iscomment( h, c ) ))
			break;
		else	{
			tokenbuffer[i] = c;
			continue;
			}
		}
	tokenbuffer[i] = 0;
	return(i);
}

int	addtoken( FILE * h ) 
{
	int	i;
	int	c;

	if (!( remove_white_space( h ) )) return( 0 );

	for (i=0; i < maxtokensize; i++ ) {
		if (!( tokenbuffer[i] )) {
			tokenbuffer[i++]='.';
			break;
			}
		}

	for ( ; i < maxtokensize; i++ ) {
		if (!( c = igetch(h)))
			break;
		if (( c == ']' )
		||  ( c == '=' )
		||  ( iswhitespace(c) )) {
			ungetch(c);
			break;
			}
		else if (!(c=iscomment(h,c ) ))
			break;
		else	{
			tokenbuffer[i] = c;
			continue;
			}
		}
	tokenbuffer[i] = 0;
	return(i);
}

int	addvalue( FILE * h ) 
{
	int	status;
	int	i;
	int	c;
	struct member * mptr;

	for (i=0; i < maxvaluesize; i++ ) {
		if (!( c = igetch(h)))
			break;
		else if (c == '\r')
			break;
		else if ( c == '\n' )
			break;
		else if ( c == '\t' )
			c = ' ';
		valuebuffer[i] = c;
		}
	valuebuffer[i] = 0;
	if (( mptr = allocate( sizeof( struct member ) )) != (struct member *) 0) {
		mptr->prev = mptr->next = (struct member *) 0;
		if (( mptr->name = allocate( strlen( tokenbuffer ) + 1 )) != (char *) 0) {
			strcpy( mptr->name,tokenbuffer );
			if (( mptr->value = allocate( strlen( valuebuffer ) + 1 )) != (char *) 0) {
				strcpy( mptr->value,valuebuffer );
				if (( foot != (struct project *) 0 )
				&&  ( foot->last != (struct section *) 0)) { 
					if (!( mptr->prev = foot->last->last))
						foot->last->root = mptr;
					else 	foot->last->last->next = mptr;
					foot->last->last = mptr;
					return(0);
					}
				else	status = 56;
				liberate( mptr->value );
				}
			else	status = 29;
			liberate( mptr->name );
			}
		else	status = 28;
		liberate( mptr );
		}
	else	status = 27;
	return( report_error(status) );
}

int	addsection()
{
	struct section * sptr;
	if (!( sptr = allocate( sizeof( struct section ) )))
		return( report_error(27) );
	else	{	
		sptr->root = sptr->last = (struct member *) 0;
		sptr->next = sptr->prev = (struct section *) 0;
		if (!(sptr->name = allocate( strlen( tokenbuffer ) + 1 ) )) {
			liberate( sptr );
			return( report_error(27) );
			}
		else	{
			strcpy( sptr->name, tokenbuffer );
			if ( root ) {	
				if (!(sptr->prev = foot->last))
					foot->root = sptr;
				else 	foot->last->next = sptr;
				foot->last = sptr;
				return(0);
				}
			else	{
				liberate( sptr );
				return( report_error( 55 ) );
				}
			}
		}
}



int	expression( FILE * h )
{
	int	l;
	switch ( state ) {
		case	0 :	/* open section */
			if (!( testch( h,'[' ) ))
				return(report_error(30));
			else	{
				state = 1;
				return(0);
				}
		case	1 :	/* section name component */
			if (!( l = getoken(h) ))
				return(report_error(31));
			else	{
				state = 2;
				return(0);
				}
		case	2 : 	/* section name compoent or  closure */
			if ( testch( h, ']' ) ) {
				state = 3;
				return( addsection() );
				}
			else if (!( l = addtoken(h) ))
				return(report_error(32));
			else	return( 0 );
		case	3 :	/* member or new section */
			if ( testch( h, '[' ) ) {
				state = 1;
				return(0);
				}
			else if (!(l = getoken(h) ))
				return(report_error( 33 ) );
			else	{
				state = 4;
				return(0);
				}
		case	4 :	/* member . member or = value */
			if ( testch(h, '=' ) ) {
				state = 3;
				return( addvalue(h) );
				}
			else if (!( addtoken(h) ))
				return(report_error( 34 ) );
			else	return( 0 );
		default	:	/* illegal machine states */
			return(report_error( 35 ) );
		}
}


int	loadfile( char * nptr )
{
	struct project * pptr;
	FILE * h;
	int	status;
	if ( verbose )
		printf("opening : %s\n",nptr);
	if (!( h = fopen( nptr, "r")))
		return( report_error(40) );
	else	{
		if (( pptr = allocate( sizeof( struct project ) )) != (struct project *) 0) {
			pptr->root = pptr->last = (struct section *) 0;
			pptr->next = pptr->prev = (struct project *) 0;
			if (( pptr->name = allocate( strlen( nptr ) + 1 )) != (char *) 0) 
				strcpy(pptr->name,nptr);
			if (!(pptr->prev = foot))
				root = pptr;
			else 	foot->next = pptr;	
			foot = pptr;
			state = 0;
			ungotch = 0;
			while ( remove_white_space( h ) )
				if ((status = expression(h)) != 0)
					break;
			}
		else	status = report_error(27);
		fclose(h);
		return(status);
		}
}

#endif	// _yparse_c

