/*	-----------------------		*/
/*	ABAL METHOD LINE PARSER		*/
/*	-----------------------		*/

extern	struct	line_parser LineParser;

public	char * widget_x_position( struct form_item * iptr, int mode );
public	char * widget_y_position( struct form_item * iptr, int mode );
public	char * widget_w_dimension( struct form_item * iptr, int mode );
public	char * widget_h_dimension( struct form_item * iptr, int mode );
private	char *	abal_convert_token( FILE * h, char * tptr );
private	char *	abal_data_reset(FILE * h, struct form_item * iptr );

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
		case	0x0027	:
			if ( LineParser.folding )
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

public	char *	abal_get_token(int uppercase)
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

public	char *	abal_get_jointure()
{
	int	c;
	char *	tptr;
	if ((c = abal_get_punctuation()) !=  '(')
		return((char *) 0);
	else if (!( tptr = abal_get_token(0)))
		return( tptr );
	else if ((c = abal_get_punctuation()) !=  ')')
		return((char *) 0);
	else	return( allocate_string( tptr ) );
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

static	int	delete_brackets()
{
	char *	tptr;
	int	c;
	int	braces;
	if ((c = abal_get_punctuation()) !=  '(')
		return( 1 );
	else	{
		braces=1;
		}
	while (braces) {
		if (!(c = abal_get_punctuation() )) {
			if (!( tptr = abal_get_token(0) ))
				return(2);
			continue;
			}
		else if ( c == '(' )
			braces++;
		else if ( c == ')' )
			braces--;
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
	int	direction=0;
	int	c;
	char * tptr;

	if (( c = not_white_space()) != '.') {
		return(0);
		}
	else if (!(c = abal_get_punctuation() ))
		return( 0 );
	else if (!( c = not_white_space()))
		return(0);

	while (1) {
		if (!(c = parser_getch() ))
			return(direction);

		switch ( c ) {
			case	'J'	:
			case	'j'	:
				direction |= 2;
				continue;
			case	'D'	:
			case	'd'	:
				direction |= 1;
				continue;
			default		:
				parser_ungetch();
				return(direction);
			}
		}
}

int	check_lock()
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
		case	'M'	:
		case	'm'	:
			return('M');
		case	'L'	:
		case	'l'	:
			return('L');
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

char * collect_abal_expression()
{
	int	quoting=0;
	int	bracing=0;
	int	c;
	char * tptr;
	char *	rptr=(char *) 0;
	char *	wptr=(char *) 0;
	bracing=1;
	while (1) {
		if (( tptr = abal_get_token(0)) != (char *) 0)  {
			if (!( rptr ))
				rptr = allocate_string(tptr);
			else if (!( wptr = allocate( strlen( tptr ) + strlen( rptr ) + 4 ) ))
				break;
			else	{
				sprintf(wptr,"%s%s",rptr,tptr);
				liberate( rptr );
				rptr = wptr;
				}
			continue;
			}
		else if (!(c = abal_get_punctuation() ))
			break;
		else if ( c == ')' ) {
			bracing--;
			if (!( bracing ))
				break;
			}
		else if ( c == '(' )
			bracing++;
			if (!( rptr )) {
			if (!( rptr = allocate( 16 )))
				break;
			else	sprintf(rptr,"%c",(c & 0x00FF));
			}
		else if (!( wptr = allocate( strlen( rptr ) + 16 ) ))
			break;
		else	{
			sprintf(wptr,"%s%c",rptr,(c & 0x00FF));
			liberate( rptr );
			rptr = wptr;
			}
		}
	if ( bracing ) {
		liberate( rptr );
		return((char *) 0);
		}
	else	return( rptr );
}

char * abal_expression()
{
	int	c;
	if (!(c = abal_get_punctuation() ))
		return( (char *) 0 );
	else if (c != '(' )
		return( (char *) 0 );
	else 	{
		return( collect_abal_expression() );
		}
}

public int	abal_syntax_error(FILE * h, char * vptr,int v)
{
	fprintf(h,"\r\n#error ** abal syntax error (%u): %s **\r\n",v,vptr);
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
	else if (!( bptr = allocate( 2048 )))
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

		if (!( tptr = resolve_filepath( allocate_string( tptr ),get_translator_inclusion() ))) {
			liberate( bptr );
			return(40);
			}

		while (!(sh = fopen(tptr,"r")))  {
			if ( file_not_found( tptr ) == 27 ) {
				LineParser.status = failure = 40;
				break;
				}
			}
		if ( sh != (FILE *) 0) {
			while (!( failure = abal_include_line(sh,h,bptr,2040)));
			if ( failure == 48 ) failure = 0;
			fclose(sh);
			}	

		liberate(tptr);
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
				abal_syntax_error(h, tptr,1 );
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
		abal_syntax_error(h, keyword_include,2 );
		return((char *) 0);
		}
	else	{
		abal_include_source(h,tptr);		
		return((char *) 0);
		}
}

private	char *	abal_macro_reset( FILE * h, struct form_item * iptr )
{
	if ( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS ) {
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
	else if (!( iptr->Contents.payload ))
		return( iptr->Contents.messages[ fptr->natlang ] );
	else	return( iptr->Contents.payload );
}

public	char *	abal_hint( struct form_item * iptr )
{
	struct	form_control * fptr;
	if (!( fptr = iptr->parent ))
		return( iptr->Contents.hint );
	else if (!( fptr->formflags & _INTERNATIONAL ))
		return( iptr->Contents.hint );
	else 	return( iptr->Contents.hmessages[ fptr->natlang ] );
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

public	char *	abal_hint_length_parameter(FILE * h, struct form_item * iptr )
{
	char	*	sptr;
	if (!( sptr = abal_hint(iptr) ))
		fprintf(h,",0");
	else if ( *sptr == _UNQUOTED_STRING )
		fprintf(h,",Len(%s)",(sptr+1));
	else 	fprintf(h,",%u",strlen(sptr));
	return((char *) 0);
}

public 	int	calculate_widget_fields( struct form_item * iptr,	int* fieldwidth, int maxfields, int width )
{
	char * 	sptr;
	if ( is_valid_format((sptr = iptr->Contents.format) ) )
		return( vformat(sptr,fieldwidth,maxfields,width) );
	else if (!( sptr = abal_payload( iptr ) ))
		return(0);
	else	return( vfields( sptr,fieldwidth,maxfields,width ) );
}

private	char *	abal_macro_column( FILE * h, struct form_item * iptr, char * tptr )
{
	int	linesize=1;
	int	linecount=1;
	int	fields;
	int	fieldwidth[_MAX_FORM_FIELDS];
	int	f=0;
	char *	sptr;

	if ((iptr->Contents.style & _FRAME_TYPE) != _DATA_FRAME) {
		if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
			calculate_edit_lines( iptr, &linesize, &linecount );
		else	calculate_form_lines( iptr, &linesize, &linecount );
		}
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
	else if ((fields = calculate_widget_fields(iptr, fieldwidth, _MAX_FORM_FIELDS, linesize )) <= 1) {
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
	int	fieldwidth[_MAX_FORM_FIELDS];
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

			calculate_form_lines( iptr, &linesize, &linecount );

			if (!( sptr = abal_payload(iptr) )) {
				fprintf(h,"0");
				return((char *) 0);
				}
			else if ( *sptr == _UNQUOTED_STRING ) {
				fprintf(h,"0");
				return((char *) 0);
				}
			else	{
				fields = calculate_widget_fields(iptr, fieldwidth, _MAX_FORM_FIELDS, linesize );
				fprintf(h,"%u",fields);
				return((char *) 0);
				}
		default		:
			return((char *) 0);
		}

}

private	char *	abal_function_columnsize( FILE * h, struct form_item * iptr )
{
	fprintf(h,"cw_%s",iptr->Contents.name);
	return((char *) 0);
}

private	char *	abal_macro_columnsize( FILE * h, struct form_item * iptr, char * tptr )
{
	int	i;
	int	linesize=1;
	int	linecount=1;
	int	fields;
	int	offset=0;
	int	field=0;
	int	f=0;
	int	fieldwidth[_MAX_FORM_FIELDS];
	char *	sptr;

	if (( iptr->Contents.style & _FRAME_TYPE ) == _FORM_FRAME )
		calculate_form_lines( iptr, &linesize, &linecount );
	else	calculate_edit_lines( iptr, &linesize, &linecount );

	if (!( tptr )) {
		abal_syntax_error(h, iptr->Contents.name,3 );
		return((char *) 0);
		}
	else if (!( sptr = abal_payload(iptr) )) {
		abal_syntax_error(h, iptr->Contents.name,4 );
		return((char *) 0);
		}
	else if ((fields = calculate_widget_fields(iptr, fieldwidth,_MAX_FORM_FIELDS, linesize )) >= 1) {
		field = 0;
		while ( *tptr ) {
			if (( *tptr >= '0' ) && ( *tptr <= '9'))
				field = ((field * 10) + (*(tptr++) - '0'));
			else	break;
			}
		if ( field <= fields )
			fprintf(h,"%u",fieldwidth[(field-1)]);
		else	abal_syntax_error(h, iptr->Contents.name,5 );
		return((char *) 0);
		}
	else	{
		abal_syntax_error(h, iptr->Contents.name,6 );
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
	int	fieldwidth[_MAX_FORM_FIELDS];
	int	position=0;
	char *	sptr;

	if (( iptr->Contents.style & _FRAME_TYPE ) == _FORM_FRAME )
		calculate_form_lines( iptr, &linesize, &linecount );
	else	calculate_edit_lines( iptr, &linesize, &linecount );

	if (!( tptr )) {
		abal_syntax_error(h, iptr->Contents.name,7 );
		return((char *) 0);
		}
	else if (!( sptr = abal_payload(iptr) )) {
		abal_syntax_error(h, iptr->Contents.name,8);
		return((char *) 0);
		}
	else if ( *sptr == _UNQUOTED_STRING ) {
		abal_syntax_error(h, iptr->Contents.name,9);
		return((char *) 0);
		}
	else if ((fields = calculate_widget_fields(iptr, fieldwidth, _MAX_FORM_FIELDS, linesize )) >= 1) {
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
		else	abal_syntax_error(h, iptr->Contents.name,10);
		return((char *) 0);
		}
	else	{
		abal_syntax_error(h, iptr->Contents.name,11);
		return((char *) 0);
		}
}

public	char	* abal_form_member_alias(
			FILE * h,
			struct form_item * iptr,
			char *	tptr,
			int	margin )
{
	int	linelength=0;
	int	nblines=0;
	if ( margin != 0 ) 
		indent(h,margin);
	if (!( tptr )) {
		fprintf(h,"if (v_%s = 0) :: v_%s = 1 :: endif",
			iptr->Contents.name,iptr->Contents.name);
		linefeed(h);
		indent(h,margin);
		if (is_w_modif(iptr)) {
			calculate_form_lines( iptr, &linelength, &nblines );
			fprintf(h,"r_%s = %s(l_%s((v_%s-1)*nc_%s+1))",
				iptr->Contents.name,__abal_keyword_alias,
				iptr->Contents.name,iptr->Contents.name,
				iptr->Contents.name);
			}
		else	{
			fprintf(h,"r_%s = %s(l_%s(v_%s))",
				iptr->Contents.name,__abal_keyword_alias,
				iptr->Contents.name,iptr->Contents.name);
			}
		}
	else	{
		if (is_w_modif(iptr))
			fprintf(h,"r_%s = %s(l_%s((",
				iptr->Contents.name,__abal_keyword_alias,
				iptr->Contents.name);
		else	{
			fprintf(h,"r_%s = %s(l_%s(",
			iptr->Contents.name,__abal_keyword_alias,
			iptr->Contents.name);
			};

		abal_macro_conversion( h, tptr, iptr->Contents.name );

		if (is_w_modif(iptr))
			fprintf(h,"-1)*nc_%s+1))",iptr->Contents.name);
		else	fprintf(h,"))");
		}
	return((char *) 0);
}

public	char	* abal_form_member_aliassort(
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
		fprintf(h,"r_%s = %s(ls_%s(v_%s))",
			iptr->Contents.name,__abal_keyword_alias,
			iptr->Contents.name,iptr->Contents.name);
		}
	else	{
		fprintf(h,"r_%s = %s(ls_%s(",
			iptr->Contents.name,__abal_keyword_alias,
			iptr->Contents.name);

		abal_macro_conversion( h, tptr, iptr->Contents.name );

		fprintf(h,"))");
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
		if (!( tptr = collect_abal_expression() ))	/* abal_get_token(0) */
			return( tptr );
		else	return( abal_form_member_alias(h,iptr,tptr,1) );
		}
	else 	{
		parser_ungetch();
		return( abal_line_variable(h,iptr) );
		}
}

private	char *	abal_form_linesort(FILE * h, struct form_item * iptr )
{
	int	c;
	char * tptr;
	if (!(c = abal_get_punctuation() ))
		return( (char *)0 );
	else if (c == '(' ) {
		if (!( tptr = abal_get_token(0) ))
			return( tptr );
		else if (!(c = abal_get_punctuation() ))
			return( (char *) 0 );
		else if (c != ')' )
			return( (char *) 0 );
		else	return( abal_form_member_aliassort(h,iptr,tptr,1) );
		}
	else 	{
		parser_ungetch();
		return( (char *)0 );
		}
}

private	char *	abal_form_resize(FILE * h)
{
	int	c;
	char * tptr;
	if (!(c = abal_get_punctuation() ))
		return( (char *)0 );
	fprintf(h,"%sResize",Abal_Config.cname);
	
	if (c!='(') {
		parser_ungetch();
		return((char *)0);
	};

	fprintf(h,"(",Abal_Config.cname);

	if (!( tptr = abal_get_token(0) ))
			return( tptr );
	if ((tptr =  abal_convert_token(h,tptr) ))
		fprintf(h,"%s",tptr);
	
	if (!(c = abal_get_punctuation() ))
			return( (char *) 0 );
	fprintf(h,"%c",c);
	if (c != ',') return((char *)0);


	if (!( tptr = abal_get_token(0) ))
			return( tptr );
	if ((tptr =  abal_convert_token(h,tptr) ))
		fprintf(h,"%s",tptr);

	if (!(c = abal_get_punctuation() ))
			return( (char *) 0 );
	fprintf(h,"%c",c);
	return((char *)0);
	
}

private	int abal_form_access()
{
	int	c;
	char * tptr;
	if (!(c = abal_get_punctuation() ))
		return(1);
	else if (c == '(' ) {
		if (!( tptr = abal_get_token(0) ))
			return( 1 );
		else if (!(c = abal_get_punctuation() ))
			return( 1 );
		else if (c != ')' )
			return(  1 );
		else	return( atoi(tptr) );
		}
	else 	{
		parser_ungetch();
		return( 1 );
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

private	void	hint_value( FILE * h, struct form_item * iptr)
{
	char *	hptr;
	struct	form_control * fptr;
	if (!( iptr ))
		return;
	else if (!( fptr = iptr->parent ))
		return;
	else if (!( hptr = abal_hint( iptr )))
		return;
	else if (!( fptr->formflags & _INTERNATIONAL ))
		string_value(h,hptr);
	else if (!( fptr->formflags & _MULTILINGUAL ))
		string_value(h,hptr);
	else	string_value(h,hptr);
	return;
}

public	int	forms_dynamic_position( char * sptr )
{
	struct	form_control * fptr;
	if (!( sptr ))
		return(0);
	else if (!(fptr = locate_form_control( sptr ) ))
		return(0);
	if (!( fptr->isdynamic ))
		return(0);
	else	return(1);
}
		
public	char *	is_public_module_method( char * tptr, struct form_item * iptr )
{
	if (!( tptr ))
		return((char *)0);
	else if (!( iptr ))
		return((char *)0);

	switch ((iptr->Contents.style & _FRAME_TYPE)) {
		case	_EDIT_FRAME	:
		case	_BUTTON_FRAME	:
		case	_RADIO_FRAME	:
		case	_CHECK_FRAME	:
		case	_SWITCH_FRAME	:
		case	_SCROLL_FRAME	:
		case	_PROGRESS_FRAME	:
		case	_SELECT_FRAME	:
			if ( string_compare( tptr, "OnSet" ) )
				return("OnSet");
			else if ( string_compare( tptr, "OnGet" ) )
				return("OnGet");
		}
	if (( is_named_edit  ( iptr ) )
	||  ( is_named_select( iptr ) )) {
		if ( string_compare( tptr, "OnShow" ) )
			return("OnShow");
		}		
	if (( iptr->Contents.events->xo_create & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_create))) {
		if ( string_compare( tptr, "Create" ) )
			return("Create");
		}		
	if (( iptr->Contents.events->xo_remove & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_remove))) {
		if ( string_compare( tptr, "Remove" ) )
			return("Remove");
		}		
	if (( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_show))) {
		if ( string_compare( tptr, "Show" ) )
			return("Show");
		}		
	if (( iptr->Contents.events->xo_hide & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_hide))) {
		if ( string_compare( tptr, "Hide" ) )
			return("Hide");
		}		
	if (( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_get_focus))) {
		if ( string_compare( tptr, "GetFocus" ) )
			return("GetFocus");
		}		
	if (( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_lose_focus))) {
		if ( string_compare( tptr, "LoseFocus" ) )
			return("LoseFocus");
		}		
	if (( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_event))) {
		if ( string_compare( tptr, "Event" ) )
			return("Event");
		}		
	return((char *)0);
}

public	void	abal_invoke_position_at( FILE * h, struct form_item * iptr )
{
	char	*	sptr;
	int	interf=_OVL_ONLOSE ;
	struct	form_control * fptr;
	if (!( iptr ))
		return;
	else if (!( sptr = abal_payload( iptr )))
		return;
	else if (!(fptr = locate_form_control( sptr ) ))
		return;
	else if (!( use_visual_interface(fptr,1) ))
		return;
	else	{
		if (( fptr->isdynamic ) &&  (!( fptr->PositionAt))) {
			indent(h,1);
			if ( iptr->Contents.datatype == _WIDGET_MODULE )
				fprintf(h,"%sOnPositionAt(",fptr->identifier);
			else	{
				interf++;
				fprintf(h,"%s (%s%s(%u))(",__abal_keyword_call, _IMT_PREFIX,iptr->Contents.name, interf );
				fprintf(h,"%s%s,",_OVL_PREFIX,iptr->Contents.name);
				}
			fprintf(h,"x_%s,y_%s)",iptr->Contents.name,iptr->Contents.name);
			linefeed(h);
			}
		return;
		}
	
}

private	char *	abal_widget_module_method( FILE * h, struct form_item * iptr, char * tptr )
{
	char	*	nptr;
	int	c;
	struct	form_item    * wptr;
	struct	forms_method * mptr;
	struct	form_control * fptr;
	char *	sptr;
	if (!( sptr = abal_payload( iptr )))
		return((char *) 0);
	else if (!(fptr = locate_form_control( sptr ) ))
		return((char *) 0);
	if ( detect_forms_special_method( tptr ) == _FORMS_POSITIONAT ) {
		if (( fptr->isdynamic ) &&  (!( fptr->PositionAt))) {
			fprintf(h,"%sOnPositionAt",fptr->identifier);
			return((char *) 0);
			}
		}
	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if (!( mptr->name ))
			continue;
		else if (!( mptr->type & _METHOD_PUBLIC ))
			continue;
		else if (!( mptr->type & _METHOD_FUNCTION ))
			continue;
		else if (!( string_compare( tptr, mptr->name )))
			continue;
		else	{
			fprintf(h,"%s",tptr);
			break;
			}
		}
	/* ----------------------------------------- */
	/* Detect Invocation of Public Widget Method */
	/* ----------------------------------------- */
	for ( 	wptr=fptr->first;
		wptr != (struct form_item *) 0;
		wptr = wptr->next ) {
		/* -------------------- */
		/* detect public widget */
		/* -------------------- */
		if (!( wptr->Contents.access & _WIDGET_PUBLIC ))
			continue;
		/* --------------------- */
		/* detect matching token */
		/* --------------------- */
		else if (!( string_compare( tptr, wptr->Contents.name )))
			continue;

		/* ---------------------- */
		/* ensure member operator */
		/* ---------------------- */
		else if ((c = parser_getch()) != '.' ) {
			abal_syntax_error(h,wptr->Contents.name,112);
			break;
			}
		/* --------------------- */
		/* collect member method */
		/* --------------------- */
		else if (!( tptr = abal_get_token(0) )) {
			abal_syntax_error(h,wptr->Contents.name,113);
			return( tptr );
			}
		/* ------------------ */
		/* verify method name */
		/* ------------------ */
		else if (!(nptr = is_public_module_method( tptr, wptr ))) {
			abal_syntax_error(h,tptr,114);
			break;
			}
		/* --------------------- */
		/* check for punctuation */
		/* --------------------- */
		else if ((c = abal_get_punctuation()) !=  '(') {
			abal_syntax_error(h,tptr,115);
			break;
			}
		else	{
			/* ------------------------------ */
			/* generate invocation expression */
			/* ------------------------------ */
			fprintf(h,"%s%s%s(",fptr->identifier,wptr->Contents.name,nptr);
			break;
			}
		}
	return((char *) 0);
}

public	int	is_public_widget_method( char * tptr, struct form_item * iptr )
{
	int	methodid=1;
	if (!( tptr ))
		return(0);
	else if (!( iptr ))
		return(0);

	switch ((iptr->Contents.style & _FRAME_TYPE)) {
		case	_EDIT_FRAME	:
		case	_BUTTON_FRAME	:
		case	_RADIO_FRAME	:
		case	_CHECK_FRAME	:
		case	_SWITCH_FRAME	:
		case	_SCROLL_FRAME	:
		case	_PROGRESS_FRAME	:
		case	_SELECT_FRAME	:
			if ( string_compare( tptr, "OnSet" ) )
				return(methodid);
			else	methodid++;
			if ( string_compare( tptr, "OnGet" ) )
				return(methodid);
			else	methodid++;
		}
	if (( is_named_edit  ( iptr ) )
	||  ( is_named_select( iptr ) )) {
		if ( string_compare( tptr, "OnShow" ) )
			return(methodid);
		else	methodid++;
		}		
	if (( iptr->Contents.events->xo_create & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_create))) {
		if ( string_compare( tptr, "Create" ) )
			return(methodid);
		else	methodid++;
		}		
	if (( iptr->Contents.events->xo_remove & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_remove))) {
		if ( string_compare( tptr, "Remove" ) )
			return(methodid);
		else	methodid++;
		}		
	if (( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_show))) {
		if ( string_compare( tptr, "Show" ) )
			return(methodid);
		else	methodid++;
		}		
	if (( iptr->Contents.events->xo_hide & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_hide))) {
		if ( string_compare( tptr, "Hide" ) )
			return(methodid);
		else	methodid++;
		}		
	if (( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_get_focus))) {
		if ( string_compare( tptr, "GetFocus" ) )
			return(methodid);
		else	methodid++;
		}		
	if (( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_lose_focus))) {
		if ( string_compare( tptr, "LoseFocus" ) )
			return(methodid);
		else	methodid++;
		}		
	if (( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_event))) {
		if ( string_compare( tptr, "Event" ) )
			return(methodid);
		else	methodid++;
		}		
	return(0);
}

public	int	public_widget_method_count( struct form_item * iptr )
{
	int	public_methods=0;

	if (!( iptr ))
		return(0);
	else if (!( iptr->Contents.access & _WIDGET_PUBLIC ))
		return(0);

	switch ((iptr->Contents.style & _FRAME_TYPE)) {
		case	_EDIT_FRAME	:
		case	_BUTTON_FRAME	:
		case	_RADIO_FRAME	:
		case	_CHECK_FRAME	:
		case	_SWITCH_FRAME	:
		case	_SCROLL_FRAME	:
		case	_PROGRESS_FRAME	:
		case	_SELECT_FRAME	:
			public_methods += 2;
		}
	
	if (( is_named_edit  ( iptr ) )
	||  ( is_named_select( iptr ) ))
		public_methods++;
	if (( iptr->Contents.events->xo_create & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_create)))
		public_methods++;
	if (( iptr->Contents.events->xo_remove & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_remove)))
		public_methods++;
	if (( iptr->Contents.events->xo_show & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_show)))
		public_methods++;
	if (( iptr->Contents.events->xo_hide & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_hide)))
		public_methods++;
	if (( iptr->Contents.events->xo_get_focus & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_get_focus)))
		public_methods++;
	if (( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_lose_focus)))
		public_methods++;
	if (( iptr->Contents.events->xo_event & _EVENT_IS_FUNCTION )
	&&  ( method_is_valid(iptr->Contents.events->on_event)))
		public_methods++;
	return( public_methods );
}

public	int	overlay_interface_count( struct form_item * iptr )
{
	struct	forms_method * mptr;
	struct	form_control * fptr;
	char *	sptr;
	int	interf=0; /* 'interface' est un mot clé sous windows ! */
	switch ((iptr->Contents.style & _FRAME_TYPE)) {
		case	_DATA_FRAME	:
			if ((iptr->Contents.align & 0x000F) != _VISUAL_FRAME)
				return(0);
			else if (!( sptr = abal_payload( iptr )))
				return(0);
			else	break;
		default			:
			if (!( sptr = iptr->Contents.format))
				return(0);
			else	break;
		}
	if ( *sptr == _UNQUOTED_STRING )
		return( _OVL_METHODS );
	if (!(fptr = locate_form_control( sptr ) ))
		return(0);
	if (( fptr->isdynamic ) &&  (!( fptr->PositionAt)))
		interf++;
	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if (!( mptr->name ))
			continue;
		else if (!( mptr->type & _METHOD_PUBLIC ))
			continue;
		else if (!( mptr->type & _METHOD_FUNCTION ))
			continue;
		else	interf++;
		}
	interf += public_widgets_method_count( fptr );
	if ( fptr->language != _GENERATE_PHP )
		interf += _OVL_METHODS;
	else if (!( fptr->weboptions & _WEB_OPTION_AGENT ))
		interf += _OVL_METHODS;
	else	interf += _SOAP_OVL_METHODS;
	return(interf);
}

public	int	abal_forms_overlay_public_method_count( struct form_control * fptr )
{
	int	interf=0;
	struct	forms_method * mptr;
	/* --------------------------------- */
	/* Detect Invocation of Forms Method */
	/* --------------------------------- */
	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if (!( mptr->name ))
			continue;
		else if (!( mptr->type & _METHOD_PUBLIC ))
			continue;
		else if (!( mptr->type & _METHOD_FUNCTION ))
			continue;
		else	interf++;
		}
	return( interf );
}


public	void	overlay_widget_invocation_expression( FILE * h, struct form_item * iptr, int interf, int i )
{
	/* ------------------------------ */
	/* generate invocation expression */
	/* ------------------------------ */
	if ( (interf+i) > 4 )
		if (!( use_visual_interface(iptr->parent,1) ))
			return;
	fprintf(h,"%s (%s%s(%u))(",__abal_keyword_call, _IMT_PREFIX,iptr->Contents.name, interf+i );
	fprintf(h,"%s%s",_OVL_PREFIX,iptr->Contents.name);
	if ( i > 2 )
		fprintf(h,")");
	else	fprintf(h,",");
	return;
}

private	char *	abal_widget_overlay_method( FILE * h, struct form_item * iptr, char * tptr )
{
	int	c;
	struct	forms_method * mptr;
	struct	form_control * fptr;
	struct	form_item    * wptr;
	char *	sptr;
	int	interf=_OVL_ONLOSE ; /* 'interface' est un mot clé sous windows ! */
	int	i=0;
	if (!( sptr = abal_payload( iptr )))
		return((char *) 0);
	else if (!(fptr = locate_form_control( sptr ) ))
		return((char *) 0);
	else if (!( use_visual_interface(fptr,0) )) {
		delete_brackets();
		return((char *) 0);
		}

	/* ------------------------------------------------- */
	/* Detect Invocation of PositionAt for the Component */
	/* ------------------------------------------------- */
	if (( fptr->isdynamic ) &&  (!( fptr->PositionAt))) {
		interf++;
		if ( detect_forms_special_method( tptr ) == _FORMS_POSITIONAT ) {
			if ((c = abal_get_punctuation()) !=  '(')
				return((char *) 0);

			fprintf(h,"%s (%s%s(%u))(",__abal_keyword_call, _IMT_PREFIX,iptr->Contents.name, resolve_overlay_method_entry(fptr, interf ) );
			fprintf(h,"%s%s,",_OVL_PREFIX,iptr->Contents.name);
			return((char *) 0);
			}
		}
	/* --------------------------------- */
	/* Detect Invocation of Forms Method */
	/* --------------------------------- */
	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if (!( mptr->name ))
			continue;
		else if (!( mptr->type & _METHOD_PUBLIC ))
			continue;
		else if (!( mptr->type & _METHOD_FUNCTION ))
			continue;
		interf++;
		if (!( string_compare( tptr, mptr->name )))
			continue;
		else if ((c = abal_get_punctuation()) !=  '(')
			break;
		else	{
			fprintf(h,"%s (%s%s(%u))(",__abal_keyword_call, _IMT_PREFIX,iptr->Contents.name, interf);
			if ( method_is_valid( mptr->signature ) ) {
				fprintf(h,"%s%s,",_OVL_PREFIX,iptr->Contents.name);
				}
			else	{
				fprintf(h,"%s%s",_OVL_PREFIX,iptr->Contents.name);
				}
			break;
			}
		}
	/* ----------------------------------------- */
	/* Detect Invocation of Public Widget Method */
	/* ----------------------------------------- */
	for ( 	wptr=fptr->first;
		wptr != (struct form_item *) 0;
		wptr = wptr->next ) {
		/* -------------------- */
		/* detect public widget */
		/* -------------------- */
		if (!( wptr->Contents.access  & _WIDGET_PUBLIC ))
			continue;
		/* --------------------- */
		/* detect matching token */
		/* --------------------- */
		else if (!( string_compare( tptr, wptr->Contents.name ))) {
			interf += public_widget_method_count( wptr );
			continue;
			}
		/* ---------------------- */
		/* ensure member operator */
		/* ---------------------- */
		else if ((c = parser_getch()) != '.' ) {
			abal_syntax_error(h,wptr->Contents.name,12);
			break;
			}
		/* --------------------- */
		/* collect member method */
		/* --------------------- */
		else if (!( tptr = abal_get_token(0) )) {
			abal_syntax_error(h,wptr->Contents.name,12);
			return( tptr );
			}
		/* ------------------ */
		/* verify method name */
		/* ------------------ */
		else if (!(i = is_public_widget_method( tptr, wptr ))) {
			abal_syntax_error(h,tptr,12);
			break;
			}
		/* --------------------- */
		/* check for punctuation */
		/* --------------------- */
		else if ((c = abal_get_punctuation()) !=  '(') {
			abal_syntax_error(h,tptr,12);
			break;
			}
		else	{
			overlay_widget_invocation_expression( h, iptr, interf, i );
			break;

			}
		}
	return((char *) 0);
}

public	void	invoke_abal_widget_help( FILE * h, struct form_item * iptr )
{
	char *	optr;
	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay ))
		optr = "o";
	else	optr = "\0";
	if ((iptr->Contents.style & _FRAME_TYPE) != _RADIO_FRAME)
		fprintf(h,"%sHelp(%s)",iptr->Contents.name,optr);
	else	fprintf(h,"%s%uHelp(%s)",iptr->Contents.name,iptr->Contents.radio,optr);
	return;
}

private	char *	visual_member_getset( FILE * h, struct form_item * iptr, char * modname )
{
	if (!( iptr->Contents.access & _WIDGET_PUBLIC )) {
		abal_syntax_error(h,iptr->Contents.name,17);
		}
	else	{
		if (((iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME)
		&&  ((iptr->Contents.align & 0x000F) == _VISUAL_FRAME)) {
			switch ( iptr->Contents.datatype ) {
				case	_WIDGET_MODULE	:
					fprintf(h,"%s%s()",abal_payload(iptr),modname);
					return((char *) 0);
//FCH				case	_WIDGET_OVERLAY	:
				}
			}
		}
	abal_syntax_error(h,iptr->Contents.name,18);
	return((char *) 0);
}

private	int	check_onshow_mode(FILE * h,struct form_item * iptr)
{
	char *	tptr;
	int	c;
	if (( c = not_white_space()) != '.') {
		return(0);
		}
	else if (!(c = abal_get_punctuation() )) {
		abal_syntax_error(h,iptr->Contents.name,20);
		return( 0 );
		}
	else if (!( c = not_white_space())) {
		abal_syntax_error(h,iptr->Contents.name,20);
		return(0);
		}
	else if (!( tptr = abal_get_token(0) )) {
		abal_syntax_error(h,iptr->Contents.name,20);
		return(0);
		}

	switch ( is_visual_member( tptr,1 ) ) {
		case	VISUAL_MEMBER_FOCUS	:
			return(2);
		case	VISUAL_MEMBER_PRESS	:
			return(4);
		default				:
			abal_syntax_error(h,tptr,21);
			return(0);
		}
}

private	char *	abal_convert_token( FILE * h, char * tptr )
{
	int	showmode=0;
	int	linesize=1;
	int	linecount=1;
	int	i;
	int	c;
	int	fh;
	char	tokenizer[32];
	struct form_control * fptr;
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
				fprintf(h,"%sEvent(%s)",Abal_Config.cname,mptr);
			else	fprintf(h,"%sEvent()",Abal_Config.cname);
			return((char *) 0);
			}
		}

	else if ( upper_compare( tptr, keyword_oncreate) ) {
		if (!( remove_brackets() ))
			return( tptr );
		else	{
			if (( Abal_Config.generate_program )
			&&  ( Abal_Config.generate_overlay ))
				fprintf(h,"Status = %sCreate(%s)",Abal_Config.cname,mptr);
			else	fprintf(h,"%sCreate()",Abal_Config.cname);
			return((char *) 0);
			}
		}

	else if ( upper_compare( tptr, keyword_onremove) ) {
		if (!( remove_brackets() ))
			return( tptr );
		else	{
			if (( Abal_Config.generate_program )
			&&  ( Abal_Config.generate_overlay ))
				fprintf(h,"Status = %sRemove(%s)",Abal_Config.cname,mptr);
			else	fprintf(h,"%sRemove()",Abal_Config.cname);
			return((char *) 0);
			}
		}

	else if ( upper_compare( tptr, keyword_onfocus) ) {
		if (!( remove_brackets() ))
			return( tptr );
		else	{
			if (( Abal_Config.generate_program )
			&&  ( Abal_Config.generate_overlay ))
				fprintf(h,"Status = %sFocus(%s)",Abal_Config.cname,mptr);
			else	fprintf(h,"%sFocus()",Abal_Config.cname);
			return((char *) 0);
			}
		}
	else if ( upper_compare( tptr, keyword_FormResize) ) {
		abal_form_resize(h);
		return((char *) 0);
		}
	else if ( upper_compare( tptr, keyword_w_BaseResize) ) {
		fprintf(h,"%u",	Context.Form->resizew);
		return((char *) 0);
		}
	else if ( upper_compare( tptr, keyword_h_BaseResize) ) {
		fprintf(h,"%u",	Context.Form->resizeh);
		return((char *) 0);
		}

	if (!( iptr = locate_widget( tptr, Context.Form) ))
		return( abal_method_statement( h, tptr ) );
	else if (!( fptr = iptr->parent ))
		return( tptr );

	if ((c = parser_getch()) != '.' ) {
		if ( c != 0 )
			parser_ungetch();
		return( tptr );
		}

	if (((iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME)
	&&  ((iptr->Contents.align & 0x000F) == _VISUAL_FRAME)) {
		if (!( tptr = abal_get_token(0) )) {
			abal_syntax_error(h,iptr->Contents.name,12);
			return( tptr );
			}
		if ((i = is_visual_member( tptr,1 )) == -1) {
			if (( iptr->Contents.datatype == _WIDGET_CLASS )
			||  ( iptr->Contents.datatype == _WIDGET_POINTER ))
				return( aplus_convert_visual(h,iptr->Contents.name, tptr, abal_payload(iptr) ) );
			else if ( iptr->Contents.datatype == _WIDGET_MODULE  )
				return( abal_widget_module_method(h,iptr,tptr) );
			else if ( iptr->Contents.datatype == _WIDGET_OVERLAY )
				return( abal_widget_overlay_method(h,iptr,tptr) );
			else	{
				abal_syntax_error(h,tptr,13);
				return((char *) 0);
				}
			}
		}
	else if (((iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME)
	     &&  ((iptr->Contents.align & 0x000F) == _OBJECT_FRAME)) {
		fprintf(h,"%s.",iptr->Contents.name);
		return( (char *) 0);
		}
	else	{
		if (!( tptr = abal_get_token(1) )) {
			fprintf(h,"%s.",iptr->Contents.name);
			abal_syntax_error(h,iptr->Contents.name,12);
			return( tptr );
			}
		else if ( is_file_Widget( iptr ) ) {
			if ( abal_data_member_expression(h,iptr,tptr) != 0 )
				return((char *) 0);	
			else if ((i = is_visual_member( tptr,1 )) == -1) {
				if ((i = is_data_member( tptr, 1 )) != -1)
					abal_data_expression(h, iptr,i, 1,tptr );
				else	abal_syntax_error( h, tptr, 12 );
				return( (char *) 0);
				}
			}
		else if ((i = is_visual_member( tptr,1 )) == -1) {
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
			fprintf(h,"%s",widget_foreground( iptr ));
			return((char *) 0);
		case	VISUAL_MEMBER_BG	:
			fprintf(h,"%s",widget_background( iptr ));
			return((char *) 0);
		case	VISUAL_MEMBER_OFFSET	:
			if ((iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME)
				fprintf(h,"v_%s",iptr->Contents.name);
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
					abal_syntax_error(h,iptr->Contents.name,14);
					abal_syntax_error(h,tptr,13);
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
					if ( iptr->Contents.format ) {
						string_value(h,iptr->Contents.format);
						return((char *) 0);
						}
					else	return("(E)");
				}

		case	VISUAL_MEMBER_HINT	:
			hint_value( h, iptr );
			return((char *) 0);

		case	VISUAL_MEMBER_PAYLOAD	:
			if ( abal_payload(iptr) ) {
				payload_value( h, iptr );
				}
			return((char *) 0);

		case	VISUAL_MEMBER_BUFFER	:
			fprintf(h,"b_%s",iptr->Contents.name);
			return((char *) 0);

		case	VISUAL_MEMBER_HOTKEYS	:
			fprintf(h,"k_%s",iptr->Contents.name);
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
			if (!( is_file_Widget( iptr ) )) {
				calculate_edit_size( iptr );
				fprintf(h,"%u",iptr->Contents.size);
				}
			else	{
				fprintf(h,"%u",iptr->Contents.ylimit);
				}
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
			if ( fptr->resizeauto ) 
				return( abal_function_columnsize( h, iptr ) );
			else if (!( tptr = abal_dimension() ))
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
				calculate_form_lines( iptr, &linesize, &linecount );
				if (is_h_modif(iptr))
					fprintf(h,"((%u*_href)/%u)",linecount,h_base_resize(iptr));
				else	fprintf(h,"%u",linecount);
				return((char *) 0);
				}

		case	VISUAL_MEMBER_LINESIZE	:
			if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
				calculate_edit_lines( iptr, &linesize, &linecount );
			else	calculate_form_lines( iptr, &linesize, &linecount );
			fprintf(h,"%u",linesize);
			return((char *) 0);

		case	VISUAL_MEMBER_FORMSORT	:
			fprintf(h,"f_%s",iptr->Contents.name);
			return((char *) 0);

		case	VISUAL_MEMBER_TABSORT	:
			fprintf(h,"ts_%s",iptr->Contents.name);
			return((char *) 0);

		case	VISUAL_MEMBER_LINESORT  	:
			return( abal_form_linesort(h, iptr ) );

		case	VISUAL_MEMBER_START_SORT	:
			fprintf(h,"als_%s",iptr->Contents.name);
			return((char *) 0);			

		case	VISUAL_MEMBER_SORT	:
			fprintf(h,"sort_%s",iptr->Contents.name);
			return((char *) 0);				
		
		case	VISUAL_MEMBER_TRIGGER	:
			if (!( remove_brackets() ))
				break;
			generate_abal_trigger(h,iptr,1);
			return((char *) 0);

		case	VISUAL_MEMBER_HELP	:
			if (!( remove_brackets() ))
				break;
			if (!( use_visual_interface(iptr->parent,1) ))
				return((char*) 0);
			else 	{
				if ( (Context.Form->onlinehelp & 7) ) {
					if ( detect_widget_help( iptr ) ) {
						invoke_abal_widget_help(h,iptr);
						}
					}
				return((char *) 0);				
				}

		case	VISUAL_MEMBER_ACCESS	:
			if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
				fprintf(h,"a%d_%s",abal_form_access(),iptr->Contents.name);
			else
				{
				if (!( remove_brackets() ))
					break;
				else
					fprintf(h,"a_%s",iptr->Contents.name);
				}
			return((char *) 0);

		case	VISUAL_MEMBER_ENABLE	:
			if (!( remove_brackets() ))
				break;
			else if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
				fprintf(h,"a%d_%s=0",abal_form_access(),iptr->Contents.name);
			else	fprintf(h,"a_%s=0",iptr->Contents.name);
			return((char *) 0);

		case	VISUAL_MEMBER_DISABLE	:
			if (!( remove_brackets() ))
				break;
			else if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
				fprintf(h,"a%d_%s=1",abal_form_access(),iptr->Contents.name);
			else	fprintf(h,"a_%s=1",iptr->Contents.name);
			return((char *) 0);


		case	VISUAL_MEMBER_INIBIT	:
			if (!( remove_brackets() ))
				break;
			else if ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)
				fprintf(h,"a%d_%s=2",abal_form_access(),iptr->Contents.name);
			else	fprintf(h,"a_%s=2",iptr->Contents.name);
			return((char *) 0);


		case	VISUAL_MEMBER_ONGET 	:
			return( visual_member_getset( h, iptr, "OnSet" ));
		case	VISUAL_MEMBER_ONSET 	:
			return( visual_member_getset( h, iptr, "OnGet" ));

		case	VISUAL_MEMBER_ONEVENT 	:
			if (!( remove_brackets() ))
				break;
			if (((iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME)
			&&  ((iptr->Contents.align & 0x000F) == _VISUAL_FRAME)) {
				switch ( iptr->Contents.datatype ) {
					case	_WIDGET_MODULE	:
						fprintf(h,"%sOnEvent()",abal_payload(iptr));
						break;
					case	_WIDGET_OVERLAY	:
						invoke_widget_overlay_method(h,iptr,_OVL_ONEVENT);
						break;
					}
				}
			return((char *) 0);
								
		case	VISUAL_MEMBER_ONHIDE	:
			if (!( remove_brackets() ))
				break;
			if (!( use_visual_interface(iptr->parent,1) ))
				return((char*) 0);
			if (((iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME)
			&&  ((iptr->Contents.align & 0x000F) == _VISUAL_FRAME)) {
				switch ( iptr->Contents.datatype ) {
					case	_WIDGET_MODULE	:
						fprintf(h,"%sOnHide()",abal_payload(iptr));
						return((char *) 0);
					case	_WIDGET_OVERLAY	:
						invoke_widget_overlay_method(h,iptr,_OVL_ONHIDE);
						return((char *) 0);
					}
				}
			if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP ) {
				generate_abal_popdown(h,iptr,1);
				}
			return((char *) 0);

		case	VISUAL_MEMBER_ONFOCUS	:
			if (!( remove_brackets() ))
				break;
			else	abal_onfocus_widget(h,iptr,1);
			return((char *) 0);

		case	VISUAL_MEMBER_PAGE	:
			fprintf(h,"%u",iptr->Contents.page);
			return((char *) 0);

		case	VISUAL_MEMBER_STYLE	:
			string_value(h,iptr->Contents.stylesheet);
			return((char *) 0);

		case	VISUAL_MEMBER_ONSHOW	:
			showmode = check_onshow_mode(h,iptr);
			if (!( remove_brackets() ))
				break;
			if (!( use_visual_interface(iptr->parent,1) ))
				return((char*) 0);
			/* better use the standard method instead */
			/* -------------------------------------- */
			if (!( abal_onshow_widget(h,iptr,1,showmode) ))
				fprintf(h,"%s%s(%s)",iptr->Contents.name,tptr,mptr);
			return((char *) 0);

		case	VISUAL_MEMBER_DROP	:
			if (!( remove_brackets() ))
				break;
			abal_form_popup_remove(h,iptr);
			return((char *) 0);

		case	VISUAL_MEMBER_ALLOCATE	:
			if (!( remove_brackets() ))
				break;
			abal_form_popup_create(h,iptr);
			return((char *) 0);

		case	VISUAL_MEMBER_ACTION 	:
			if (!( remove_brackets() ))
				break;
			abal_widget_action(h,iptr);
			return((char *) 0);

		case	VISUAL_MEMBER_GET 	:
			if (!( remove_brackets() ))
				break;
			abal_form_popup_get(h,iptr);
			return((char *) 0);

		case	VISUAL_MEMBER_PUT	:
			if (!( remove_brackets() ))
				break;
			abal_form_popup_put(h,iptr);
			return((char *) 0);

		case	VISUAL_MEMBER_FREEZE	:
			if (!( remove_brackets() ))
				break;
			if (!( use_visual_interface(iptr->parent,1) ))
				return((char*) 0);
			fprintf(h,"%s=%s()",__abal_keyword_status,__abal_visual_freeze);
			return((char *) 0);

		case	VISUAL_MEMBER_THAW  	:
			if (!( remove_brackets() ))
				break;
			if (!( use_visual_interface(iptr->parent,1) ))
				return((char*) 0);
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
		case	VISUAL_MEMBER_FOCUS	:
			fprintf(h,"%u",iptr->Contents.focus);
			return((char *) 0);

		case	VISUAL_MEMBER_HOTKEY	:
			if (( iptr->Contents.trigger >= 'a' )
			&&  ( iptr->Contents.trigger <= 'z' ))
				fprintf(h,"%c%c%c",0x0022,iptr->Contents.trigger-('a'-'A'),0x0022);
			else if (( iptr->Contents.trigger >= 'A' )
			     &&  ( iptr->Contents.trigger <= 'Z' ))
				fprintf(h,"%c%c%c",0x0022,iptr->Contents.trigger,0x0022);
			else	fprintf(h,"%c %c",0x0022,0x0022);
			return((char *) 0);


		case	VISUAL_MEMBER_VIEWPORT	:
			if (!( remove_brackets() ))
				break;
			if (!( use_visual_interface(iptr->parent,1) ))
				return((char*) 0);
			abal_widget_viewport(h,iptr);
			return((char *) 0);

		case	VISUAL_MEMBER_FILL  	:
			if (!( remove_brackets() ))
				break;
			if (!( use_visual_interface(iptr->parent,1) ))
				return((char*) 0);
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
			if (!( use_visual_interface(iptr->parent,1) ))
				return((char*) 0);
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

		case	VISUAL_MEMBER_PRESS	:
			if (!( remove_brackets() ))
				break;
			if (!( use_visual_interface(iptr->parent,1) ))
				return((char*) 0);
			abal_button_press( h, iptr );
			return((char *) 0 );


		case	VISUAL_MEMBER_ONCREATE	:
			if (!( remove_brackets() ))
				break;
			else	{
				abal_widget_oncreate( h, iptr, 0 );
				return((char *) 0);
				}

		case	VISUAL_MEMBER_ONREMOVE	:
			if (!( remove_brackets() ))
				break;
			else	{
				abal_widget_onremove( h, iptr,0 );
				return((char *) 0);
				}
						
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
			if (!( iptr->Contents.access & _WIDGET_PUBLIC ))
				fprintf(h,"%s%s(%s)",iptr->Contents.name,tokenizer,mptr);
			else if (!( fptr = iptr->parent ))
				fprintf(h,"%s%s(%s)",iptr->Contents.name,tokenizer,mptr);
			else if ( fptr->isprogram )
				fprintf(h,"%s%s(%s)",iptr->Contents.name,tokenizer,mptr);
			else if (!( fptr->isoverlay ))
				fprintf(h,"%s%s(%s)",iptr->Contents.name,tokenizer,mptr);
			else	{
				/* Public Module Method */
				fprintf(h,"%s%s%s(%s)",fptr->identifier,iptr->Contents.name,tokenizer,mptr);
				}
			return((char *) 0);
		}

	abal_syntax_error(h, tptr,15 );
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
	int	status;
	if (!( push_line_parser() )) {
		return((status =27));
		}
	else	{
		status = abal_method_line( h, sptr, strlen(sptr), hptr, &feeder );
		(void) pop_line_parser();
		return( status );
		}
}

#include "phpline.c"
#include "plusline.c"

