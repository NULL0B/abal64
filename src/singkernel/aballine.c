/*	-----------------------		*/
/*	ABAL METHOD LINE PARSER		*/
/*	-----------------------		*/

extern	struct	line_parser LineParser;

public	char * widget_x_position( struct form_item * iptr, int mode );
public	char * widget_y_position( struct form_item * iptr, int mode );
public	char * widget_w_dimension( struct form_item * iptr, int mode );
public	char * widget_h_dimension( struct form_item * iptr, int mode );

private	int	is_punctuation( int c )
{
	switch ( c ) {
		case	'('	:
		case	')'	:
		case	'.'	:
		case	','	:
		case	';'	:
		case	':'	:
		case	'+'	:
		case	'-'	:
		case	'*'	:
		case	'/'	:
		case	'!'	:
		case	'?'	:
		case	'&'	:
		case	'='	:
		case	'<'	:
		case	'>'	:
			return(c);
		default		:
			return(0);
		}
}

private	int	abal_get_punctuation()
{
	int	c;
	int	status;
	if (!( not_white_space() ))
		return( 0 );
	else if (!( c = parser_getch() ))
		return(0);
	else if (!( is_punctuation(c))) {
		parser_ungetch();
		return(0);
		}
	else	return(c);
}

private	char *	abal_get_token(int uppercase)
{
	int	c;
	int	quoting=0;
	LineParser.tokenlen=0;

	if (!( c =  not_white_space() ))
		return( (char *) 0);

	while ( LineParser.tokenlen<256 ) {

		if ((c = parser_getch()) == '"' ) {
			if ( quoting )
				quoting=0;
			else if (!( LineParser.tokenlen ))
				quoting=1;
			else	{
				parser_ungetch();
				break;
				}
			LineParser.token[LineParser.tokenlen++] = c;
			if (!( quoting ))
				break;
			else	continue;
			}
		else if ( quoting ) {
			LineParser.token[LineParser.tokenlen++] = c;
			continue;
			}
		else if ( is_punctuation(c) ) {
			parser_ungetch();
			break;
			}
		else if ( is_white_space(c) ) {
			break;
			}
		else if (!( uppercase )) {
			LineParser.token[LineParser.tokenlen++] = c;
			continue;
			}
		else if (( c >= 'a' ) && ( c <= 'z' )) {
			LineParser.token[LineParser.tokenlen++] = ((c-'a')+'A');
			continue;
			}
		else	{
			LineParser.token[LineParser.tokenlen++] = c;
			continue;
			}

		}

	if (!( LineParser.tokenlen ))
		return( (char *) 0 );
	else	{
		LineParser.token[LineParser.tokenlen++] = 0;
		return(LineParser.token);
		}
}

static	int	copy_brackets(FILE * h)
{
	char *	tptr;
	int	c;
	int	braces;
	if ((c = abal_get_punctuation()) !=  '(')
		return( 1 );
	else	{
		braces=1;
		fprintf(h,"%c",c);
		}
	while (braces) {

		if (!(c = abal_get_punctuation() )) {
			if (!( tptr = abal_get_token(0) ))
				return(2);
			else 	fprintf(h,"%s",tptr);
			continue;
			}
		else if ( c == '(' )
			braces++;
		else if ( c == ')' )
			braces--;
		fprintf(h,"%c",c);
		}
	return( 0 );
}

int	remove_brackets()
{
	int	c;
	char * tptr;
	if (( c = not_white_space()) != '(')
		return(1);
	else if (!(c = abal_get_punctuation() ))
		return( 0 );
	else if (c != '(' )
		return( 0 );
	else if (!(c = abal_get_punctuation() ))
		return( 0 );
	else if (c != ')' )
		return( 0 );
	else	return( 2 );
}

int	check_direction()
{
	int	c;
	char * tptr;

	if (( c = not_white_space()) != '.') {
		return(0);
		}
	else if (!(c = abal_get_punctuation() ))
		return( 0 );
	else if (!( c = not_white_space()))
		return(0);

	else if (!(c = parser_getch() ))
		return(0);

	switch ( c ) {
		case	'D'	:
		case	'd'	:
			return(1);
		default		:
			parser_ungetch();
			return(0);
		}
}

char * abal_dimension()
{
	int	c;
	char * tptr;
	if (!(c = abal_get_punctuation() ))
		return( (char *) 0 );
	else if (c != '(' )
		return( (char *) 0 );
	else 	{
		tptr = abal_get_token(0);
		if (!(c = abal_get_punctuation() ))
			return( (char *) 0 );
		else if (c != ')' )
			return( (char *) 0 );
		else	return( tptr );
		}
}

public int	abal_syntax_error( char * vptr,int v)
{
	printf("\r\n** abal syntax error (%u): %s **\r\n",v,vptr);
	return(line_parser_error( v ) );
}

public 	int	abal_method_line( FILE * h, char * eptr, int l, char * hptr, int * feeder );

public	int	abal_include_line( FILE * sh, FILE * th, char * bptr, int  blen )
{
	int	i=0;
	int	c;
	int	status=0;
	int	feeder=0;
	while ( i < blen ) {

		if ((c = fgetc(sh)) <= 0)	break;
		else if ( c == '\r' )		continue;
		else if ( c == '\n' ) {
			if (!( i ))	continue;
			else 		break;
			}
		else 	{
			if ( c == '\t' )	c = ' ';
			if ( c != ' ' )		*(bptr+i)=c;
			else if (!( i ))	continue;
			else			*(bptr+i)=c;
			i++;
			}
		}
	if (!( i ))
		return(48);
	else	{
		*(bptr+i) = 0;
		indent(th,1);
		status = abal_method_line(th, bptr, i, LineParser.thisname, &feeder );
		linefeed(th);
		return(status);
		}
}

public	int	abal_include_source( FILE * h, char * tptr )
{
	FILE *	sh;
	char *	bptr;
	int	i;
	int	failure;
	if (!( tptr ))	
		return((failure=30));
	else if (!( h    ))  
		return((failure=31));
	else if (!( bptr = allocate( 1025 )))
		return((failure=27));
	else if (!( push_line_parser() )) {
		liberate( bptr );
		return((failure=27));
		}
	else 	{
		if ( *tptr == '"' ) {
			tptr++;
			for (i=0; *(tptr+i) != 0; i++ ) {
				if ( *(tptr+i) == '"' ) {
					*(tptr+i) = 0;
					break;
					}
				}
			}
		while (!(sh = fopen(tptr,"r")))  {
			if ( file_not_found( tptr ) == 27 ) {
				LineParser.status = failure = 40;
				break;
				}
			}
		if ( sh != (FILE *) 0) {
			while (!( failure = abal_include_line(sh,h,bptr,1024)));
			if ( failure == 48 ) failure = 0;
			fclose(sh);
			}	

		liberate( bptr );
		return( pop_line_parser() );
		}
}

private	char *	abal_forms_method_statement( FILE * h, char * tptr )
{
	struct	form_control 	* fptr;
	struct	forms_method 	* mptr;
	if (!( fptr = Context.Form ))
		return( tptr );
	else if (!( fptr->isprogram ))
		return( tptr );
	else if (!( fptr->isoverlay ))
		return( tptr );
	else if (!( fptr->rootmethod ))
		return( tptr );
	else	{
		for (	mptr=fptr->rootmethod;
			mptr != (struct forms_method *) 0;
			mptr = mptr->next ) {
			if (!( mptr->name ))
				continue;
			if (!( string_compare( tptr, mptr->name )))
				continue;
			else if (abal_get_punctuation() !=  '(') {
				abal_syntax_error( keyword_include,1 );
				return((char *) 0);
				}
			else 	{
				if (!( method_is_valid(  mptr->signature ) ))
					fprintf(h,"%s(o",mptr->name);
				else	fprintf(h,"%s(o,",mptr->name);
				return((char *) 0);
				}
			}
		return( tptr );
		}
}

private	char *	abal_method_statement( FILE * h, char * tptr )
{
	if (!( string_compare( tptr, keyword_include ) ))
		return( abal_forms_method_statement(h,tptr) );

	else if (!( tptr = abal_get_token(0) )) {
		abal_syntax_error( keyword_include,2 );
		return((char *) 0);
		}
	else	{
		abal_include_source(h,tptr);		
		return((char *) 0);
		}
}

private	char *	abal_macro_reset( FILE * h, struct form_item * iptr )
{
	if ( iptr->Contents.events.xo_create & _EVENT_IS_FOCUS ) {
		/* Generate Position and Dimensions Variables */
		fprintf(h,"x_%s=%s",iptr->Contents.name,widget_x_position(iptr,1));
		fprintf(h,"::y_%s=%s",iptr->Contents.name,widget_y_position(iptr,1));
		fprintf(h,"::w_%s=%s",iptr->Contents.name,widget_w_dimension(iptr,1));
		fprintf(h,"::h_%s=%s",iptr->Contents.name,widget_h_dimension(iptr,1));
		}
	return((char*)0);
}

private	char	* integer_expression( FILE * h, int value )
{
	fprintf(h,"%u",value);
	return((char *) 0);
}

private	char *	widget_text_column( FILE * h, struct form_item * iptr )
{
	int	fw;
	char	* sptr;
	if (!( fw = (guifontsize(1)  & 0x00FF)))
		return(integer_expression(h,1));
	else if (!( sptr = widget_x_position(iptr,0) ))
		return(integer_expression(h,1));
	else	{
		fprintf(h,"(((%s)/%u)+1)",sptr,fw);
		return((char *) 0);
		}
}

private	char *	widget_text_line( FILE * h, struct form_item * iptr )
{
	int	fh;
	char	*	sptr;
	if (!( fh = ((guifontsize(1) >> 8)  & 0x00FF)))
		return(integer_expression(h,1));
	else if (!( sptr = widget_y_position(iptr,0) ))
		return(integer_expression(h,1));
	else	{
		fprintf(h,"(((%s)/%u)+1)",sptr,fh);
		return((char *) 0);
		}
}

private	char *	widget_text_columns( FILE * h, struct form_item * iptr )
{
	int	fw;
	if (!( fw = (guifontsize(1) & 0x00FF)))
		return(integer_expression(h,1));
	else	return(integer_expression(h,(iptr->Contents.w/fw)));
}

private	char *	widget_text_lines( FILE * h, struct form_item * iptr )
{
	int	fh;
	if (!( fh = ((guifontsize(1) >> 8) & 0x00FF)))
		return(integer_expression(h,1));
	else	return(integer_expression(h,(iptr->Contents.h/fh)));
}

public	char *	abal_payload( struct form_item * iptr )
{
	struct	form_control * fptr;
	if (!( fptr = iptr->parent ))
		return( iptr->Contents.payload );
	else if (!( fptr->formflags & _INTERNATIONAL ))
		return( iptr->Contents.payload );
	else 	return( iptr->Contents.messages[ fptr->natlang ] );
}

public	char *	abal_payload_length_parameter(FILE * h, struct form_item * iptr )
{
	char	*	sptr;
	if (!( sptr = abal_payload(iptr) ))
		fprintf(h,",0");
	else if ( *sptr == _UNQUOTED_STRING )
		fprintf(h,",Len(%s)",(sptr+1));
	else 	fprintf(h,",%u",strlen(sptr));
	return((char *) 0);
}

private	char *	abal_macro_column( FILE * h, struct form_item * iptr, char * tptr )
{
	int	linesize=1;
	int	linecount=1;
	int	fields;
	int	fieldwidth[32];
	int	f=0;
	char *	sptr;

	if ((iptr->Contents.style & _FRAME_TYPE) != _DATA_FRAME)
		calculate_edit_lines( &iptr->Contents, &linesize, &linecount );
	else	{
		for (	f=0,sptr=tptr;
			*sptr != 0;
			sptr++ ) {
			if (( *sptr >= '0') && ( *sptr <= '9' ))
				f = ((f * 10 ) + ( *(sptr++) - '0' ));
			else	break;
			}
		if (!( f )) f=1;
		abal_file_member_name( h, iptr, (f-1) );
		return((char *) 0);
		}

	if (!( sptr = abal_payload(iptr) )) {
		fprintf(h,"r_%s",iptr->Contents.name);
		return((char *) 0);
		}
	else if ( *sptr == _UNQUOTED_STRING ) {
		fprintf(h,"m%s_%s",tptr,iptr->Contents.name);
		return((char *) 0);
		}
	else if ((fields = vfields(sptr, fieldwidth, 32, linesize )) <= 1) {
		fprintf(h,"r_%s",iptr->Contents.name);
		return((char *) 0);
		}
	else	{
		fprintf(h,"m%s_%s",tptr,iptr->Contents.name);
		return((char *) 0);
		}
}

private	char *	abal_macro_columns( FILE * h, struct form_item * iptr )
{
	int	linesize=1;
	int	linecount=1;
	int	fields;
	int	fieldwidth[32];
	char *	sptr;

	switch ( iptr->Contents.style & _FRAME_TYPE ) {
		case	_EDIT_FRAME	:
			fields = iptr->Contents.size;
			fprintf(h,"%u",fields);
			return((char *) 0);

		case	_GRAPH_FRAME	:
			switch ( iptr->Contents.datatype ) {
				case	_WIDGET_BYTE :
					fields = iptr->Contents.size;
					break;
				case	_WIDGET_WORD :
					fields = (iptr->Contents.size/2);
					break;
				case	_WIDGET_LONG :
					fields = (iptr->Contents.size/4);
					break;
				default			:
					fields = 0;
				}
			fprintf(h,"%u",fields);
			return((char *) 0);

		case	_FORM_FRAME	:

			calculate_edit_lines( &iptr->Contents, &linesize, &linecount );

			if (!( sptr = abal_payload(iptr) )) {
				fprintf(h,"0");
				return((char *) 0);
				}
			else if ( *sptr == _UNQUOTED_STRING ) {
				fprintf(h,"0");
				return((char *) 0);
				}
			else	{
				fields = vfields(sptr, fieldwidth, 32, linesize );
				fprintf(h,"%u",fields);
				return((char *) 0);
				}
		default		:
			return((char *) 0);
		}

}

private	char *	abal_macro_columnsize( FILE * h, struct form_item * iptr, char * tptr )
{
	int	linesize=1;
	int	linecount=1;
	int	fields;
	int	offset=0;
	int	field=0;
	int	f=0;
	int	fieldwidth[32];
	char *	sptr;

	calculate_edit_lines( &iptr->Contents, &linesize, &linecount );

	if (!( tptr )) {
		abal_syntax_error( iptr->Contents.name,3 );
		return((char *) 0);
		}
	else if (!( sptr = abal_payload(iptr) )) {
		abal_syntax_error( iptr->Contents.name,4 );
		return((char *) 0);
		}
	else if ( *sptr == _UNQUOTED_STRING ) {
		abal_syntax_error( iptr->Contents.name,5 );
		return((char *) 0);
		}
	else if ((fields = vfields(sptr, fieldwidth, 32, linesize )) <= 1) {
		field = 0;
		while ( *tptr ) {
			if (( *tptr >= '0' ) && ( *tptr <= '9'))
				field = ((field * 10) + (*(tptr++) - '0'));
			else	break;
			}
		if ( field < fields )
			fprintf(h,"%u",fieldwidth[field]);
		else	abal_syntax_error( iptr->Contents.name,6 );
		return((char *) 0);
		}
	else	{
		abal_syntax_error( iptr->Contents.name,7 );
		return((char *) 0);
		}
}

private	char *	abal_macro_position( FILE * h, struct form_item * iptr, char * tptr )
{
	int	linesize=1;
	int	linecount=1;
	int	fields;
	int	offset=0;
	int	field=0;
	int	f=0;
	int	fieldwidth[32];
	int	position=0;
	char *	sptr;

	calculate_edit_lines( &iptr->Contents, &linesize, &linecount );

	if (!( tptr )) {
		abal_syntax_error( iptr->Contents.name,8 );
		return((char *) 0);
		}
	else if (!( sptr = abal_payload(iptr) )) {
		abal_syntax_error( iptr->Contents.name,9);
		return((char *) 0);
		}
	else if ( *sptr == _UNQUOTED_STRING ) {
		abal_syntax_error( iptr->Contents.name,10 );
		return((char *) 0);
		}
	else if ((fields = vfields(sptr, fieldwidth, 32, linesize )) > 0) {
		field = 0;
		while ( *tptr ) {
			if (( *tptr >= '0' ) && ( *tptr <= '9'))
				field = ((field * 10) + (*(tptr++) - '0'));
			else	break;
			}
		if ( field < fields ) {
			for ( position=1,f=0; f < field; f++ )
				position += fieldwidth[f];
			fprintf(h,"%u",position);
			}
		else	abal_syntax_error( iptr->Contents.name,11);
		return((char *) 0);
		}
	else	{
		abal_syntax_error( iptr->Contents.name,12 );
		return((char *) 0);
		}
}

public	char	* abal_form_member_alias(
			FILE * h,
			struct form_item * iptr,
			char *	tptr,
			int	margin )
{
	if ( margin != 0 ) 
		indent(h,margin);
	if (!( tptr )) {
		fprintf(h,"if (v_%s = 0) :: v_%s = 1 :: endif",
			iptr->Contents.name,iptr->Contents.name);
		linefeed(h);
		indent(h,margin);
		fprintf(h,"r_%s = %s(l_%s(v_%s))",
			iptr->Contents.name,__abal_keyword_alias,
			iptr->Contents.name,iptr->Contents.name);
		}
	else	{
		fprintf(h,"r_%s = %s(l_%s(%s))",
			iptr->Contents.name,__abal_keyword_alias,
			iptr->Contents.name,tptr );
		}
	return((char *) 0);
}

private	char *	abal_column_variable(FILE * h, struct form_item * iptr )
{
	if (!( iptr->Contents.name ))
		return((char *) 0);
	else	{
		fprintf(h,"c_%s",iptr->Contents.name);
		return((char *) 0);
		}
}

private	char *	abal_line_variable(FILE * h, struct form_item * iptr )
{
	if (!( iptr->Contents.name ))
		return((char *) 0);
	else	{
		fprintf(h,"v_%s",iptr->Contents.name);
		return((char *) 0);
		}
}

private	char *	abal_form_column(FILE * h, struct form_item * iptr )
{
	int	c;
	char * tptr;
	if (!(c = abal_get_punctuation() ))
		return( abal_column_variable(h,iptr) );
	else if (c == '(' ) {
		if (!( tptr = abal_get_token(0) ))
			return( tptr );
		else if (!(c = abal_get_punctuation() ))
			return( (char *) 0 );
		else if (c != ')' )
			return( (char *) 0 );
		else 	return( abal_macro_column( h, iptr, tptr ) );
		}
	else 	{
		parser_ungetch();
		return( abal_column_variable(h,iptr) );
		}
}

private	char *	abal_form_line(FILE * h, struct form_item * iptr )
{
	int	c;
	char * tptr;
	if (!(c = abal_get_punctuation() ))
		return( abal_line_variable(h,iptr) );
	else if (c == '(' ) {
		if (!( tptr = abal_get_token(0) ))
			return( tptr );
		else if (!(c = abal_get_punctuation() ))
			return( (char *) 0 );
		else if (c != ')' )
			return( (char *) 0 );
		else	return( abal_form_member_alias(h,iptr,tptr,1) );
		}
	else 	{
		parser_ungetch();
		return( abal_line_variable(h,iptr) );
		}
}

private	void	abal_form_member_format( FILE * h, struct form_item * iptr, int i )
{
	int	c;
	int		n;
	char	*	wptr;
	char	*	fptr=iptr->Contents.format;
	char	*	eptr="(E)";
	if ((!( fptr ))
	|| (*(fptr++) != '(' )) {
		string_value(h,eptr);
		return;
		}		
	for (n=0,wptr=fptr; *wptr != 0; wptr++ ) {
		if (!( *wptr ))
			break;
		if (( *wptr == ',' ) 
		||  ( *wptr == ')' )) {
			n++;
			if ( n == i ) {
				c = *wptr;
				*wptr = 0;
				format_string_value(h,fptr);
				*wptr = c;
				return;
				}
			else	fptr = wptr;
			}
		}
	string_value(h,eptr);
	return;
}

public	void	abal_member_format_value( FILE * h, struct form_item * iptr, int i )
{
	int	c;
	int		n;
	char	*	wptr;
	char	*	fptr=iptr->Contents.format;
	char	*	eptr="(E)";
	if ((!( fptr ))
	|| (*(fptr++) != '(' )) {
		fprintf(h,"%s",eptr);
		return;
		}		
	for (n=0,wptr=fptr; *wptr != 0; wptr++ ) {
		if (!( *wptr ))
			break;
		if (( *wptr == ',' ) 
		||  ( *wptr == ')' )) {
			n++;
			if ( n == i ) {
				c = *wptr;
				*wptr = 0;
				format_value(h,fptr);
				*wptr = c;
				return;
				}
			else	fptr = wptr;
			}
		}
	fprintf(h,"%s",eptr);
	return;
}

private	char *	abal_member_format( FILE * h, struct form_item * iptr )
{
	int		i;
	int		c;
	char	*	wptr;
	char	*	fptr;
	char	*	eptr="(E)";
	char	*	tptr;
	if (!(c = abal_get_punctuation() )) {
		if (!(fptr = iptr->Contents.format ))
			return(eptr);
		else	{
			string_value(h,fptr);
			return((char *) 0);
			}
		}
	else if (c != '(' )
		return(eptr);
	else if (!( tptr = abal_get_token(0) ))
		return( tptr );
	else if (!(c = abal_get_punctuation() ))
		return( eptr );
	else if (c != ')' )
		return( eptr );
	else if (!(fptr = iptr->Contents.format ))
		return(eptr);
	else if ( *(fptr++) != '(' )
		return(eptr);
	else	{
		for (i=0,wptr=tptr; *wptr != 0 ; wptr++ ) {
			if ((*wptr >= '0') && ( *wptr <= '9'))
				i = ((i*10) + ( *(wptr++) - '0') );
			else	break;
			}
		abal_form_member_format( h,iptr, i);
		return((char *) 0);
		}
}

public	char *	aplus_token_expression( FILE * h, struct form_item * iptr, char * tptr, int i, char * prefix );
public	char *	aplus_convert_visual( FILE * h,char * prefix, char * membernameptr, char * classname );

private	void	payload_value( FILE * h, struct form_item * iptr)
{
	struct	form_control * fptr;
	if (!( iptr ))
		return;
	else if (!( fptr = iptr->parent ))
		return;
	else if (!( fptr->formflags & _INTERNATIONAL ))
		string_value(h,abal_payload(iptr));
	else if (!( fptr->formflags & _MULTILINGUAL ))
		string_value(h,abal_payload(iptr));
	else	{
		switch ( (iptr->Contents.style & _FRAME_TYPE) ) {
			case	_TEXT_FRAME	:
			case	_WINDOW_FRAME	:
			case	_CHECK_FRAME	:
			case	_RADIO_FRAME	:
			case	_SWITCH_FRAME	:
				constant_value(h,iptr);
				break;		
			default			:
				string_value(h,abal_payload(iptr));
			}
		}
	return;
}

private	char *	abal_convert_token( FILE * h, char * tptr )
{
	int	linesize=1;
	int	linecount=1;
	int	i;
	int	c;
	int	fh;
	char	tokenizer[32];

	struct form_item * iptr;

	char *	mptr;


	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		mptr = "o";
	else	mptr = "\0";

	if (( LineParser.thisname )
	&&  ( string_compare( tptr, keyword_this) ))
		tptr = LineParser.thisname;

	else if ( upper_compare( tptr, keyword_onshow ) ) {
		if (!( remove_brackets() ))
			return( tptr );
		else	{
			if (( Abal_Config.generate_program )
			&&  ( Abal_Config.generate_overlay ))
				fprintf(h,"Status = %sShow(%s)",Abal_Config.cname,mptr);
			else	fprintf(h,"%sShow()",Abal_Config.cname);
			return((char *) 0);
			}
		}
	else if ( upper_compare( tptr, keyword_onhide ) ) {
		if (!( remove_brackets() ))
			return( tptr );
		else	{
			if (( Abal_Config.generate_program )
			&&  ( Abal_Config.generate_overlay ))
				fprintf(h,"Status = %sHide(%s)",Abal_Config.cname,mptr);
			else	fprintf(h,"%sHide()",Abal_Config.cname);
			return((char *) 0);
			}
		}

	else if ( upper_compare( tptr, keyword_onevent) ) {
		if (!( remove_brackets() ))
			return( tptr );
		else	{
			if (( Abal_Config.generate_program )
			&&  ( Abal_Config.generate_overlay ))
				fprintf(h,"Status = %sEvent(%s)",Abal_Config.cname,mptr);
			else	fprintf(h,"%sEvent()",Abal_Config.cname);
			return((char *) 0);
			}
		}

	if (!( iptr = locate_widget( tptr ) ))
		return( abal_method_statement( h, tptr ) );


	if ((c = parser_getch()) != '.' ) {
		if ( c != 0 )
			parser_ungetch();
		return( tptr );
		}

	if (((iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME)
	&&  ((iptr->Contents.align & 0x000F) == _VISUAL_FRAME)) {
		if (!( tptr = abal_get_token(0) ))
			return( tptr );
		if ((i = is_visual_member( tptr,1 )) == -1)
			return( aplus_convert_visual(h,iptr->Contents.name, tptr, abal_payload(iptr) ) );
/*		else	return( aplus_token_expression(h, iptr, tptr, i, iptr->Contents.name ) );	*/	
		}
	else if (((iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME)
	     &&  ((iptr->Contents.align & 0x000F) == _OBJECT_FRAME)) {
		fprintf(h,"%s.",iptr->Contents.name);
		return( (char *) 0);
		}
	else	{
		if (!( tptr = abal_get_token(1) )) {
			fprintf(h,"%s.",iptr->Contents.name);
			return( tptr );
			}
		else if ( is_file_Widget( iptr ) ) {
			if ( abal_data_member_expression(h,iptr,tptr) != 0 )
				return((char *) 0);	
			}
		if ((i = is_visual_member( tptr,1 )) == -1) {
			i = is_data_member( tptr, 1 );
			abal_data_expression(h, iptr,i, 1,tptr );
			return( (char *) 0);
			}
		}

	switch ( i ) {
		case	VISUAL_MEMBER_X	:
			fprintf(h,"%s",widget_x_position(iptr,0));
			return((char *) 0);
		case	VISUAL_MEMBER_Y	:
			fprintf(h,"%s",widget_y_position(iptr,0));
			return((char *) 0);
		case	VISUAL_MEMBER_W	:
			fprintf(h,"%s",widget_w_dimension(iptr,0));
			return((char *) 0);
		case	VISUAL_MEMBER_H	:
			fprintf(h,"%s",widget_h_dimension(iptr,0));
			return((char *) 0);
		case	VISUAL_MEMBER_FONT	:
			logical_abal_font(h,iptr->Contents.font);
			return((char *) 0);
		case	VISUAL_MEMBER_FONTWIDTH	:
			fprintf(h,"%u", Context.FontTable[iptr->Contents.font].width );
			return((char *) 0);
		case	VISUAL_MEMBER_FONTHEIGHT :
			fprintf(h,"%u", Context.FontTable[iptr->Contents.font].height );
			return((char *) 0);
		case	VISUAL_MEMBER_FG	:
			fprintf(h,"%u",widget_foreground( iptr ));
			return((char *) 0);
		case	VISUAL_MEMBER_BG	:
			fprintf(h,"%u",widget_background( iptr ));
			return((char *) 0);
		case	VISUAL_MEMBER_VALUE	:
			switch ((iptr->Contents.style & _FRAME_TYPE)) {
				case	_RADIO_FRAME	:
				case	_CHECK_FRAME	:
				case	_SELECT_FRAME	:
				case	_SWITCH_FRAME	:
				case	_GRAPH_FRAME	:
				case	_SCROLL_FRAME	:
				case	_PROGRESS_FRAME	:
					fprintf(h,"v_%s",iptr->Contents.name);
					break;
				case	_FORM_FRAME	:
				case	_EDIT_FRAME	:
					fprintf(h,"Conv(b_%s)",iptr->Contents.name);
					break;
				default			:
					abal_syntax_error(tptr,13);
					break;
				}
			return((char *) 0);

		case	VISUAL_MEMBER_FORMAT	:
			switch ((iptr->Contents.style & _FRAME_TYPE)) {
				case	_DATA_FRAME	:
				case	_FORM_FRAME	:
					return( abal_member_format(h,iptr) );

				case	_EDIT_FRAME	:
				default			:
					if ( iptr->Contents.format )
						string_value(h,iptr->Contents.format);
					else	return("(E)");
				}

		case	VISUAL_MEMBER_PAYLOAD	:
			if ( abal_payload(iptr) ) {
				payload_value( h, iptr );
				}
			return((char *) 0);

		case	VISUAL_MEMBER_BUFFER	:
			fprintf(h,"b_%s",iptr->Contents.name);
			return((char *) 0);

		case	VISUAL_MEMBER_LIMIT	:
			fprintf(h,"l_%s",iptr->Contents.name);
			return((char *) 0);

		case	VISUAL_MEMBER_MAX	:

			switch ((iptr->Contents.style & _FRAME_TYPE)) {
				case	_GRAPH_FRAME	:
					switch ( iptr->Contents.datatype ) {
						case	_WIDGET_BYTE :
							fprintf(h,"%u",iptr->Contents.w);
							break;
						case	_WIDGET_WORD :
							fprintf(h,"%u",(iptr->Contents.w/2));
							break;
						case	_WIDGET_LONG :
							fprintf(h,"%u",(iptr->Contents.w/4));
							break;
						}
					return((char *) 0);
				default	:
					fprintf(h,"m_%s",iptr->Contents.name);
					return((char *) 0);
				}


		case	VISUAL_MEMBER_SIZE	:
			calculate_edit_size( &iptr->Contents );
			fprintf(h,"%u",iptr->Contents.size);
			return((char *) 0);

		case	VISUAL_MEMBER_COLUMN	:
			switch ((iptr->Contents.style & _FRAME_TYPE)) {
				case	_FORM_FRAME	:
				case	_DATA_FRAME	:
					return( abal_form_column(h,iptr) );
				default			:
					return( widget_text_column(h,iptr) );
				}

		case	VISUAL_MEMBER_LINE	:
			if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
				return( widget_text_line(h,iptr) );
			else	return( abal_form_line( h,iptr ) );
		case	VISUAL_MEMBER_COLUMNSIZE	:
			if (!( tptr = abal_dimension() ))
				break;
			else	{
				return( abal_macro_columnsize( h, iptr, tptr ) );
				}
		case	VISUAL_MEMBER_POSITION	:
			if (!( tptr = abal_dimension() ))
				break;
			else	{
				return( abal_macro_position( h, iptr, tptr ) );
				}

		case	VISUAL_MEMBER_COLUMNS	:
			if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
				return( widget_text_columns(h,iptr) );
			else 	return( abal_macro_columns( h, iptr ) );

		case	VISUAL_MEMBER_LINES	:
			if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
				return( widget_text_lines(h,iptr) );
			else	{
				calculate_edit_lines( &iptr->Contents, &linesize, &linecount );
				fprintf(h,"%u",linecount);
				return((char *) 0);
				}

		case	VISUAL_MEMBER_LINESIZE	:
			calculate_edit_lines( &iptr->Contents, &linesize, &linecount );
			fprintf(h,"%u",linesize);
			return((char *) 0);

		case	VISUAL_MEMBER_TRIGGER	:
			if (!( remove_brackets() ))
				break;
			generate_abal_trigger(h,iptr,1);
			return((char *) 0);

		case	VISUAL_MEMBER_ONHIDE	:
			if (!( remove_brackets() ))
				break;
			if ( iptr->Contents.events.xo_hide & _EVENT_IS_POP ) {
				generate_abal_popdown(h,iptr,1);
				}
			return((char *) 0);

		case	VISUAL_MEMBER_ONFOCUS	:
			if (!( remove_brackets() ))
				break;
			else	abal_onfocus_widget(h,iptr,1);
			return((char *) 0);

		case	VISUAL_MEMBER_ONSHOW	:
			if (!( remove_brackets() ))
				break;
			if ( iptr->Contents.events.xo_hide & _EVENT_IS_POP ) {
				generate_abal_popup(h,iptr,1);
				}
			/* better use the standard method instead */
			/* -------------------------------------- */
			if (!( abal_onshow_widget(h,iptr,1) ))
				fprintf(h,"%s%s(%s)",iptr->Contents.name,tptr,mptr);
			return((char *) 0);

		case	VISUAL_MEMBER_FREEZE	:
			if (!( remove_brackets() ))
				break;
			fprintf(h,"%s=%s()",__abal_keyword_status,__abal_visual_freeze);
			return((char *) 0);

		case	VISUAL_MEMBER_THAW  	:
			if (!( remove_brackets() ))
				break;
			if ((( iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME )
			&&  ( iptr->Contents.align & _A_SHADOW )) {
				fprintf(h,"%s=%s(%s,%s,%s+%u,%s+%u)",
					__abal_keyword_status,__abal_visual_thaw,
					widget_x_position(iptr,0),
					widget_y_position(iptr,0),
					widget_w_dimension(iptr,0),10,
					widget_h_dimension(iptr,0),10);
				}
			else	{
				fprintf(h,"%s=%s(%s,%s,%s,%s)",
					__abal_keyword_status,__abal_visual_thaw,
					widget_x_position(iptr,0),
					widget_y_position(iptr,0),
					widget_w_dimension(iptr,0),
					widget_h_dimension(iptr,0));
				}
			return((char *) 0);

		case	VISUAL_MEMBER_VIEWPORT	:
			if (!( remove_brackets() ))
				break;
			abal_widget_viewport(h,iptr);
			return((char *) 0);

		case	VISUAL_MEMBER_FILL  	:
			if (!( remove_brackets() ))
				break;
			fprintf(h,"%s=%s(%s,%s,%s,%s,%u,0)",
				__abal_keyword_status,__abal_visual_fill,
				widget_x_position(iptr,0),
				widget_y_position(iptr,0),
				widget_w_dimension(iptr,0),
				widget_h_dimension(iptr,0),
				iptr->Contents.colour & 0x00FF );
			return((char *) 0);

		case	VISUAL_MEMBER_WIPE  	:
			if (!( remove_brackets() ))
				break;
			fprintf(h,"%s=%s(%s,%s,%s,%s,%u,0)",
				__abal_keyword_status,__abal_visual_fill,
				widget_x_position(iptr,0),
				widget_y_position(iptr,0),
				widget_w_dimension(iptr,0),
				widget_h_dimension(iptr,0),
				((iptr->Contents.colour >> 8) & 0x00FF) );
			return((char *) 0);

		case	VISUAL_MEMBER_RESET	:
			if (!( remove_brackets() ))
				break;
			if (!( is_data_member( tptr, 1 )))
				return( abal_macro_reset(h,iptr) );
			else	return( abal_data_reset(h,iptr) );

		case	VISUAL_MEMBER_SHOW  	:
			if (!( remove_brackets() ))
				break;
			generate_abal_show( h, iptr,1 );
			return((char *) 0 );

		case	VISUAL_MEMBER_CREATE	:
		case	VISUAL_MEMBER_REMOVE	:
		case	VISUAL_MEMBER_HIDE  	:
		case	VISUAL_MEMBER_EVENT 	:
		case	VISUAL_MEMBER_GETFOCUS	:
		case	VISUAL_MEMBER_LOSEFOCUS	:
			if (!( remove_brackets() ))
				break;
			if (!( Context.Form->abal.flags & 16 ))
				strcpy(tokenizer,tptr);
			else	respectcase(tokenizer,tptr);
			fprintf(h,"%s%s(%s)",iptr->Contents.name,tokenizer,mptr);
			return((char *) 0);
			
		}
	abal_syntax_error( tptr,14 );
	fprintf(h,"%s.",iptr->Contents.name);
	return( tptr );
			
}

public	int	abal_method_line( FILE * h, char * eptr, int l, char * hptr, int * feeder )
{
	int	punctuate=1;
	int	c;
	char *	tptr;
	if ( feeder ) *feeder = 0;
	if (!( initialise_line_parser( eptr, hptr ) )) 
		return(0);
	while (1) {
		if ((c = abal_get_punctuation())) {
			punctuate++;
			fprintf(h,"%c",c);
			}
		else if (!( tptr = abal_get_token(0) ))
			break;
		else 	{
			if (!( punctuate ))
				fprintf(h," ");
			punctuate = 0;
			if (!(tptr =  abal_convert_token(h,tptr) ))
				continue;
			else 	fprintf(h,"%s",tptr);
			}
		}
	if ( feeder ) *feeder = 1;
	return(LineParser.status);
}

public	int	abal_macro_conversion( FILE * h, char * sptr, char * hptr )
{
	int	feeder=0;
	return( abal_method_line( h, sptr, strlen(sptr), hptr, &feeder ) );
}

#include "plusline.c"






































































































































































































































































































































































































































































































































































































































































































