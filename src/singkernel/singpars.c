/*	-----------------------		*/
/*	   METHOD LINE PARSER		*/
/*	-----------------------		*/


public	char *	VisualMember[MAX_VISUAL_MEMBER] = {

/*	DATA PROPERTIES		*/
/*	---------------		*/
	(char *) "X",
	(char *) "Y",
	(char *) "W",
	(char *) "H",
	(char *) "FONT",
	(char *) "FG",
	(char *) "BG",
	(char *) "VALUE",
	(char *) "BUFFER",
	(char *) "LIMIT",
	(char *) "MAX",
	(char *) "LINE",
	(char *) "LINES",
	(char *) "LINESIZE",
	(char *) "FONTWIDTH",
	(char *) "FONTHEIGHT",
	(char *) "COLUMN",
	(char *) "COLUMNS",
	(char *) "SIZE",
	(char *) "COLUMNSIZE",
	(char *) "POSITION",
	(char *) "PAYLOAD",
	(char *) "FORMAT",

/*	METHOD PROPERTIES	*/
/*	-----------------	*/
	(char *) "CREATE",
	(char *) "SHOW",
	(char *) "GETFOCUS",
	(char *) "EVENT",
	(char *) "LOSEFOCUS",
	(char *) "HIDE",
	(char *) "REMOVE",
	(char *) "ONSHOW",
	(char *) "ONHIDE",
	(char *) "ONFOCUS",
	(char *) "TRIGGER",
	(char *) "FREEZE",
	(char *) "THAW",
	(char *) "FILL",
	(char *) "WIPE",
	(char *) "RESET",
	(char *) "VIEWPORT",
	(char *) "VISUALKEY"
	};

public	char *	DataMember[MAX_DATA_MEMBER] = {
	/* FILE Access */
	/* ----------- */
	(char *) "ASSIGN",
	(char *) "OPEN",
	(char *) "CLOSE",
	(char *) "CFILE",
	(char *) "DFILE",

	/* SI extensions */
	/* ------------- */
	(char *) "UPDATE",
	(char *) "INSERT",
	(char *) "MODIF",
	(char *) "DELETE",
	(char *) "SEARCH",
	(char *) "FIRST",
	(char *) "UP",
	(char *) "PREVIOUS",
	(char *) "DOWN",
	(char *) "NEXT",
	(char *) "LAST",
	(char *) "INDEX",
	(char *) "ERROR",
	(char *) "HANDLE",
	(char *) "LOCK",

	/* MC extensions */
	/* ------------- */
	(char *) "POSIT",
	(char *) "COUNT",
	(char *) "QUESTION",
	(char *) "RESPONSE",
	(char *) "LENGTH",
	(char *) "COLLECT",
	(char *) "LOCATE"

	};

public	is_visual_method( int m )
{
	if (( m >=VISUAL_MEMBER_CREATE )
	&&  ( m <=VISUAL_MEMBER_VIEWPORT))
		return(1);
	else	return(0);
}


public struct	line_parser	LineParser;

public	char *	widget_member_list()
{
	char 	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	int		i;
	for (i=0; i < MAX_VISUAL_MEMBER; i++ ) {
		if (!( rptr )) {
			if (!( rptr = allocate_string( VisualMember[i] ) ))
				break;
			}
		else if (!( wptr = allocate( strlen( rptr ) + strlen( VisualMember[i] ) + 4 ) ))
			break;
		else	{
			sprintf(wptr,"%s|%s",rptr,VisualMember[i]);
			liberate( rptr );
			rptr = wptr;
			}
		}
	return( rptr );
}

public	char *	data_member_list(struct form_item * iptr)
{
	char 	*	rptr=(char *) 0;
	char	*	wptr=(char *) 0;
	int		i;
	char 	*	file_member_list(struct form_item *, char *);	
	for (i=0; i < MAX_DATA_MEMBER; i++ ) {
		if (!( rptr )) {
			if (!( rptr = allocate_string( DataMember[i] ) ))
				break;
			}
		else if (!( wptr = allocate( strlen( rptr ) + strlen( DataMember[i] ) + 4 ) ))
			break;
		else	{
			sprintf(wptr,"%s|%s",rptr,DataMember[i]);
			liberate( rptr );
			rptr = wptr;
			}
		}
	if (!( iptr ))
		return( rptr );
	else	return( file_member_list( iptr, rptr ) );
}


public	int	is_visual_member( char * tptr, int uppercase )
{
	int	i;
	for (i=0; i < MAX_VISUAL_MEMBER; i++ ) {
		if ( uppercase ) {
			if ( upper_compare(VisualMember[i], tptr ) )
				return(i);
			}
		else	{
			if ( string_compare( VisualMember[i], tptr ) )
				return(i);
			}
		}
	return(-1);
}

public	int	is_data_member( char * tptr, int uppercase )
{
	int	i;
	for (i=0; i < MAX_DATA_MEMBER; i++ ) {
		if ( uppercase ) {
			if ( upper_compare(DataMember[i], tptr ) )
				return(i);
			}
		else	{
			if ( string_compare( DataMember[i], tptr ) )
				return(i);
			}
		}
	return(-1);
}

public	int	push_line_parser()
{
	struct line_parser * lptr;
	if (!( lptr = allocate( sizeof( struct line_parser ) ) ))
		return(0);
	else	{
		lptr->string 	= LineParser.string;
		lptr->offset 	= LineParser.offset;
		lptr->tokenlen 	= LineParser.tokenlen;
		strcpy(lptr->token, LineParser.token);
		lptr->nesting = LineParser.nesting;
		LineParser.nesting = lptr;
		return(1);
		}
}

public	int	pop_line_parser()
{
	int	status=0;
	struct line_parser * lptr;
	if (!( lptr = LineParser.nesting ))
		return( status );
	else	{
		status = LineParser.status;
		LineParser.string = lptr->string;
		LineParser.offset = lptr->offset;
		LineParser.tokenlen = lptr->tokenlen;
		strcpy(LineParser.token,lptr->token);
		LineParser.nesting = lptr->nesting;
		lptr = liberate( lptr );
		return(status);
		}
}

public	int	parser_getch()
{
	int	c;
	if (!( c = *(LineParser.string + LineParser.offset) ))
		return(0);
	else	{
		LineParser.offset++;
		return((c & 0x00FF));
		}
}

public	int	parser_ungetch()
{
	if ( LineParser.offset )
		LineParser.offset--;
	return(1);
}

public	is_white_space(int c )
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

public	int	not_white_space()
{
	int	c;
	while (1) {
		if (!( c = parser_getch()))
			return(0);
		else if ( is_white_space(c) )
			continue;
		else	{
			parser_ungetch();
			return(c);
			}
		}
}

public	int	is_valid_method( char * eptr )
{
	int	c;
	if (!( eptr ))
		return(0);
	while ((c = *(eptr++)) != 0) {
		if ( c == 0x001A )
			break;
		else  if ( is_white_space(c) )
			continue;
		else	return(c);
		}
	return(0);
}


public	int	initialise_line_parser( char * eptr, char * hptr )
{
	LineParser.thisname = hptr;

	if (!(LineParser.string = eptr))
		return(0);
	else	{
		LineParser.status = 0;
		LineParser.offset = 0;
		return( not_white_space() );
		}

}

public	int	line_parser_error( int e )
{
	LineParser.status = e;
	return(e);
}

