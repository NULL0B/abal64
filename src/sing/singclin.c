extern	struct line_parser LineParser;
extern	char *	keyword_include	;
extern	char *	keyword_user	;
extern	char *	keyword_this	;
extern	char *	keyword_thisform;
extern	char *	keyword_exit	;
extern	char *	keyword_dcl 	;
extern	char *	keyword_ptr 	;
extern	char *	keyword_field	;
extern	char *	keyword_onshow	;
extern	char *	keyword_onhide	;
extern	char *	keyword_onevent ;
extern	char *	keyword_keycode ;
extern	char *	keyword_focusitem ;

public	char * widget_x_position( struct form_item * iptr, int mode );
public	char * widget_y_position( struct form_item * iptr, int mode );
public	char * widget_w_dimension( struct form_item * iptr, int mode );
public	char * widget_h_dimension( struct form_item * iptr, int mode );

private	int	is_punctuation( int c )
{
	switch ( c ) {
		case	'['	:
		case	']'	:
		case	'{'	:
		case	'}'	:
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
		case	'%'	:
		case	'?'	:
		case	'|'	:
		case	'^'	:
		case	'&'	:
		case	'='	:
		case	'<'	:
		case	'>'	:
			return(c);
		default		:
			return(0);
		}
}

public int	c_get_punctuation()
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

public	char *	c_get_token(int uppercase)
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

static	int	remove_brackets()
{
	int	c;
	char * tptr;
	if (!(c = c_get_punctuation() ))
		return( 0 );
	else if (c != '(' )
		return( 0 );
	else if (!(c = c_get_punctuation() ))
		return( 0 );
	else if (c != ')' )
		return( 0 );
	else	return( 1 );
}

public	char * c_dimension()
{
	int	c;
	char * tptr;
	if (!(c = c_get_punctuation() ))
		return( (char *) 0 );
	else if (c != '(' )
		return( (char *) 0 );
	else if (!( tptr = c_get_token(0) ))
		return( tptr );
	else if (!(c = c_get_punctuation() ))
		return( (char *) 0 );
	else if (c != ')' )
		return( (char *) 0 );
	else	return( tptr );

}

public int	c_syntax_error( char * vptr, int n )
{
	printf("\r\n** c syntax error (%u) : %s **\r\n",n,vptr);
	return( line_parser_error(n) );
}

private	int	c_method_line( FILE * h, char * eptr, int l, char * hptr, int * feeder );

public	int	c_include_line( FILE * sh, FILE * th, char * bptr, int  blen )
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
		status = c_method_line(th, bptr, i, LineParser.thisname, &feeder );
		linefeed(th);
		return(status);
		}
}

public	int	c_include_source( FILE * h, char * tptr )
{
	FILE *	sh;
	char *	bptr;
	int	failure=0;
	int	i;
	if (!( tptr ))	
		return((failure=30));
	else if (!( h    ))  
		return((failure=30));
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
		while (!(sh = fopen(tptr,"r")))  {
			if ( file_not_found( tptr ) == 27 ) {
				LineParser.status = 40;
				break;
				}
			}

		if ( sh != (FILE *) 0) {
			while (!(failure = c_include_line(sh,h,bptr,2040)));
			if ( failure == 48 ) failure = 0;
			fclose(sh);
			}	
		liberate( bptr );
		return( pop_line_parser() );
		}
}

private	char *	c_method_statement( FILE * h, char * tptr )
{
	int	c;
	int	token;
	struct forms_method *	mptr;
	struct forms_method *	is_forms_Method( char *, struct form_control *);

	if ( string_compare( tptr, keyword_include ) ) {
		if (!( tptr = c_get_token(0) )) {
			c_syntax_error( keyword_include,1 );
			return((char *) 0);
			}
		else	{
			c_include_source(h,tptr);		
			return((char *) 0);
			}
		}

	else if ((mptr = is_forms_Method( tptr, Context.Form )) != (struct forms_method *) 0 ) {
		if (!(c = c_get_punctuation() ))
			return( tptr );
		else if (c != '(' )
			return( tptr );
		else	{
			fprintf(h,"%s(%s",tptr,__c_instance_prefix);
			if ( method_is_valid( mptr->signature ) )
				fprintf(h,",");
			return((char *) 0);
			}

		}
	else	{
		switch ( is_visual_member( tptr, 1 ) ) {

			case	VISUAL_MEMBER_ONHIDE	:
				if (!( remove_brackets() ))
					break;
				else	{
					c_call(h,C_Config.cname, __method_hide, 0,1,(char *) 0 );
					return((char *) 0);
					}

			case	VISUAL_MEMBER_ONSHOW	:
				if (!( remove_brackets() ))
					break;
				else	{
					c_call(h,C_Config.cname,__method_show, 0,1,(char *) 0 );
					return((char *) 0);
					}
			case	VISUAL_MEMBER_ONFOCUS	:
				if (!( remove_brackets() ))
					break;
				else	{
					c_call(h,C_Config.cname,__method_focus, 0,1,(char *) 0 );
					return((char *) 0);
					}
			}
		return( tptr );
		}
}

private	char *	c_macro_reset( FILE * h, struct form_item * iptr )
{
	if ( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS ) {
		/* Generate Position and Dimensions Variables */
		fprintf(h,"%s->x_%s=%s;",__c_instance_prefix,iptr->Contents.name,widget_x_position(iptr,1));
		fprintf(h,"%s->y_%s=%s;",__c_instance_prefix,iptr->Contents.name,widget_y_position(iptr,1));
		fprintf(h,"%s->w_%s=%s;",__c_instance_prefix,iptr->Contents.name,widget_w_dimension(iptr,1));
		fprintf(h,"%s->h_%s=%s;",__c_instance_prefix,iptr->Contents.name,widget_h_dimension(iptr,1));
		}
	return((char*)0);
}

private	char *	c_macro_column( FILE * h, struct form_item * iptr, char * tptr )
{
	int	linesize=1;
	int	linecount=1;
	int	fields;
	int	offset=0;
	int	field=0;
	int	f=0;
	int	fieldwidth[_MAX_FORM_FIELDS];
	char *	sptr;

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME )
		calculate_edit_lines( iptr, &linesize, &linecount );
	else	calculate_form_lines( iptr, &linesize, &linecount );

	if (!( tptr )) {
		/* Use This Column Variable */

		c_syntax_error( iptr->Contents.name,2 );
		return((char *) 0);
		}

	else if ((fields = calculate_form_fields(iptr, fieldwidth,_MAX_FORM_FIELDS, linesize )) > 0) {
		field = 0;
		while ( *tptr ) {
			if (( *tptr >= '0' ) && ( *tptr <= '9'))
				field = ((field * 10) + (*(tptr++) - '0'));
			else	break;
			}
		if ( field > 0 ) field--;
		for (	offset=0,f=0; f < field; f++ )
			offset+= fieldwidth[f];
		fprintf(h,"(%s->row_%s+%u)",
			__c_instance_prefix,iptr->Contents.name,offset);
		return((char *) 0);
		}
	else	{
		c_syntax_error( iptr->Contents.name,5 );
		return((char *) 0);
		}
}

private	char *	c_macro_columnsize( FILE * h, struct form_item * iptr, char * tptr )
{
	int	linesize=1;
	int	linecount=1;
	int	fields;
	int	offset=0;
	int	field=0;
	int	f=0;
	int	fieldwidth[_MAX_FORM_FIELDS];
	char *	sptr;

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME )
		calculate_edit_lines( iptr, &linesize, &linecount );
	else	calculate_form_lines( iptr, &linesize, &linecount );

	if (!( tptr )) {
		c_syntax_error( iptr->Contents.name,3 );
		return((char *) 0);
		}
	else if (!( sptr = c_payload(iptr) )) {
		c_syntax_error( iptr->Contents.name,4 );
		return((char *) 0);
		}
	else if ( *sptr == _UNQUOTED_STRING ) {
		c_syntax_error( iptr->Contents.name,5 );
		return((char *) 0);
		}
	else if ((fields = calculate_widget_fields(iptr, fieldwidth, 32, linesize )) >= 1) {
		field = 0;
		while ( *tptr ) {
			if (( *tptr >= '0' ) && ( *tptr <= '9'))
				field = ((field * 10) + (*(tptr++) - '0'));
			else	break;
			}
		if ( field <= fields )
			fprintf(h,"%u",fieldwidth[(field-1)]);
		else	c_syntax_error( iptr->Contents.name,6 );
		return((char *) 0);
		}
	else	{
		c_syntax_error( iptr->Contents.name,7 );
		return((char *) 0);
		}
}

private	char *	old_c_macro_columnsize( FILE * h, struct form_item * iptr, char * tptr )
{
	int	linesize=1;
	int	linecount=1;
	int	fields;
	int	offset=0;
	int	field=0;
	int	f=0;
	int	fieldwidth[_MAX_FORM_FIELDS];
	char *	sptr;

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME )
		calculate_edit_lines( iptr, &linesize, &linecount );
	else	calculate_form_lines( iptr, &linesize, &linecount );

	if (!( tptr )) {
		c_syntax_error( iptr->Contents.name,6 );
		return((char *) 0);
		}
	else if ((fields = calculate_form_fields(iptr, fieldwidth,_MAX_FORM_FIELDS, linesize )) > 0) {
		field = 0;
		while ( *tptr ) {
			if (( *tptr >= '0' ) && ( *tptr <= '9'))
				field = ((field * 10) + (*(tptr++) - '0'));
			else	break;
			}
		if ( field > 0 ) field--;
		if ( field < fields )
			fprintf(h,"%u",fieldwidth[field]);
		else	c_syntax_error( iptr->Contents.name,9 );
		return((char *) 0);
		}
	else	{
		c_syntax_error( iptr->Contents.name,10 );
		return((char *) 0);
		}
}

public	char *	c_macro_position( FILE * h, struct form_item * iptr, char * tptr )
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

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME )
		calculate_edit_lines( iptr, &linesize, &linecount );
	else	calculate_form_lines( iptr, &linesize, &linecount );

	if (!( tptr )) {
		c_syntax_error( iptr->Contents.name,6 );
		return((char *) 0);
		}

	else if ((fields = calculate_form_fields(iptr, fieldwidth,_MAX_FORM_FIELDS, linesize )) > 0) {
		field = 0;
		while ( *tptr ) {
			if (( *tptr >= '0' ) && ( *tptr <= '9'))
				field = ((field * 10) + (*(tptr++) - '0'));
			else	break;
			}
		if ( field > 0 ) field--;
		if ( field < fields ) {
			for ( position=0,f=0; f < field; f++ )
				position += fieldwidth[f];
			fprintf(h,"%u",position);
			}
		else	c_syntax_error( iptr->Contents.name,9 );
		return((char *) 0);
		}
	else	{
		c_syntax_error( iptr->Contents.name,10 );
		return((char *) 0);
		}
}

public	char *	c_macro_columns( FILE * h, struct form_item * iptr )
{
	int	linesize=1;
	int	linecount=1;
	int	fields;
	int	fieldwidth[_MAX_FORM_FIELDS];
	char *	sptr;

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME )
		calculate_edit_lines( iptr, &linesize, &linecount );
	else	calculate_form_lines( iptr, &linesize, &linecount );

	if (!( sptr = c_payload(iptr) )) {
		fprintf(h,"0");
		return((char *) 0);
		}
	else if ( *sptr == _UNQUOTED_STRING ) {
		fprintf(h,"0");
		return((char *) 0);
		}
	else	{
		fields = calculate_form_fields(iptr, fieldwidth,_MAX_FORM_FIELDS, linesize );
		fprintf(h,"%u",fields);
		return((char *) 0);
		}
}

public	char *	c_macro_line( 
		FILE * h, struct form_item * iptr, char * tptr 
		)
{
	if (!( iptr->Contents.name ))
		return((char *) 0);
	else	{
		fprintf(h,"if ( %s > 0 ) { ",tptr);
		fprintf(h,"%s->row_%s=",__c_instance_prefix,iptr->Contents.name);
		fprintf(h,"&%s->buffer_%s[%s-1][0]; } ",__c_instance_prefix,iptr->Contents.name,tptr );
		return((char *) 0);
		}	
}

public	char *	c_macro_linesort( 
		FILE * h, struct form_item * iptr, char * tptr 
		)
{
int linelength,nblines;

	if (!( iptr->Contents.name ))
		return((char *) 0);
	else	{
		fprintf(h,"if ( %s > 0 ) { ",tptr);
		fprintf(h,"%s->row_%s=",__c_instance_prefix,iptr->Contents.name);
		calculate_edit_size( &iptr->Contents );
		calculate_form_lines( iptr, &linelength, &nblines );
		fprintf(h,"&%s->libsort_%s[(%s-1)*%d]; } ",__c_instance_prefix,iptr->Contents.name,tptr,linelength );
		return((char *) 0);
		}	
}

private	char *	c_column_variable(FILE * h, struct form_item * iptr )
{
	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return((char *) 0);
	else if (!( iptr->Contents.name ))
		return((char *) 0);
	else	{
		fprintf(h,"%s->column_%s",__c_instance_prefix,iptr->Contents.name);
		return((char *) 0);
		}
}

private	char *	c_line_variable(FILE * h, struct form_item * iptr )
{
	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return((char *) 0);
	else if (!( iptr->Contents.name ))
		return((char *) 0);
	else	{
		fprintf(h,"%s->value_%s",__c_instance_prefix,iptr->Contents.name);
		return((char *) 0);
		}
}

private	char *	c_member_column(FILE * h, struct form_item * iptr )
{
	int	c;
	char * tptr;
	if (!(c = c_get_punctuation() ))
		return( c_column_variable(h,iptr) );
	else if (c == '(' ) {
		if (!( tptr = c_get_token(0) ))
			return( tptr );
		else if (!(c = c_get_punctuation() ))
			return( (char *) 0 );
		else if (c != ')' )
			return( (char *) 0 );
		else 	return( c_macro_column( h, iptr, tptr ) );
		}
	else 	{
		parser_ungetch();
		return( c_column_variable(h,iptr) );
		}
}
private	char *	c_member_line(FILE * h, struct form_item * iptr )
{
	int	c;
	char * tptr;
	if (!(c = c_get_punctuation() ))
		return( c_line_variable(h,iptr) );
	else if (c == '(' ) {
		if (!( tptr = c_get_token(0) ))
			return( tptr );
		else if (!(c = c_get_punctuation() ))
			return( (char *) 0 );
		else if (c != ')' )
			return( (char *) 0 );
		else 	return( c_macro_line( h, iptr, tptr ) );
		}
	else 	{
		parser_ungetch();
		return( c_line_variable(h,iptr) );
		}
}

private	char *	c_member_linesort(FILE * h, struct form_item * iptr )
{
	int	c;
	char * tptr;
	if (!(c = c_get_punctuation() ))
		return( (char *)0);
	else if (c == '(' ) {
		if (!( tptr = c_get_token(0) ))
			return( tptr );
		else if (!(c = c_get_punctuation() ))
			return( (char *) 0 );
		else if (c != ')' )
			return( (char *) 0 );
		else 	return( c_macro_linesort( h, iptr, tptr ) );
		}
	else 	{
		parser_ungetch();
		return( (char *)0 );
		}
}

public	char *	c_widget_overlay_method( FILE * h, struct form_item * iptr, char * tptr )
{
	int	c;
	struct	forms_method * mptr;
	struct	form_control * fptr;
	char *	sptr;

	if (!( sptr = c_payload( iptr )))
		return((char *) 0);
	else if (!(fptr = locate_form_control( sptr ) ))
		return((char *) 0);
	else	{
		for (	mptr=fptr->rootmethod;
			mptr != (struct forms_method *) 0;
			mptr = mptr->next ) {
			if (!( mptr->name ))
				continue;
			else if (!( mptr->type & _METHOD_PUBLIC ))
				continue;
			else if (!( mptr->type & _METHOD_FUNCTION ))
				continue;
			if (!( string_compare( tptr, mptr->name )))
				continue;
			else if ((c = c_get_punctuation()) !=  '(')
				break;
			else	{
				fprintf(h,"%s_%s(%s->%s",sptr,tptr,__c_instance_prefix,iptr->Contents.name);
				if (method_is_valid(mptr->signature) )
					fprintf(h,",");
				break;
				}
			}
		return((char *) 0);
		}
}

public	void	invoke_c_widget_help( FILE * h, struct form_item * iptr )
{
	if ((iptr->Contents.style & _FRAME_TYPE ) != _RADIO_FRAME)
		fprintf(h,"%s_help(%s)",iptr->Contents.name,__c_instance_prefix);
	else	fprintf(h,"%s%u_help(%s)",iptr->Contents.name,iptr->Contents.radio,__c_instance_prefix);
	return;
}

private	char *	c_convert_token( FILE * h, char * tptr )
{
	int	nbc=0;
	int	nbr=0;
	int	linesize=1;
	int	linecount=1;
	int	i;
	int	c;
	char * xtptr;

	struct form_item * iptr;

	if (( LineParser.thisname )
	&&  ( string_compare( tptr, keyword_this ) ))
		tptr = LineParser.thisname;

	else if ( upper_compare( tptr, keyword_exit ) ) {
		if ( not_white_space() != '(' )
			return( tptr );
		else	{
			fprintf(h,"return");
			return((char *) 0);
			}
		}
	else if ( upper_compare( tptr, keyword_keycode ) ) {
		fprintf(h,"%s->keycode",__c_instance_prefix);
		return((char *) 0);
		}
	else if ( upper_compare( tptr, keyword_focusitem ) ) {
		fprintf(h,"%s->%s",__c_instance_prefix,__c_focus_item);
		return((char *) 0);
		}
	else if ( upper_compare( tptr, keyword_thisform ) ) {
		if ((c = parser_getch()) != '.' ) {
			parser_ungetch();
			return( tptr );
			}
		else if (!( xtptr = c_get_token(1) )) {
			fprintf(h,"%s.",tptr);
			return( xtptr );
			}
		return( c_method_statement( h, xtptr ) );
		}


	if (!( iptr = locate_widget( tptr,Context.Form ) ))
		return( c_method_statement( h, tptr ) );
	else if ((c = parser_getch()) != '.' ) {
		parser_ungetch();
		return( tptr );
		}



	if (((iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME)
	&&  ((iptr->Contents.align & 0x000F) == _VISUAL_FRAME)) {
		if (!( tptr = c_get_token(0) ))
			return( tptr );
		if ((i = is_visual_member( tptr,1 )) == -1) {
			if ( iptr->Contents.datatype == _WIDGET_MODULE  )
				return( c_widget_overlay_method(h,iptr,tptr) );
			else if ( iptr->Contents.datatype == _WIDGET_OVERLAY )
				return( c_widget_overlay_method(h,iptr,tptr) );
			else	return((char *) 0);
			}
		}


	else if (!( tptr = c_get_token(1) )) {
		fprintf(h,"%s.",iptr->Contents.name);
		return( tptr );
		}

	i = is_visual_member( tptr, 1 );

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
			logical_c_font(h,iptr);
			return((char *) 0);
		case	VISUAL_MEMBER_FONTWIDTH	:
			fprintf(h,"%u", Context.FontTable[iptr->Contents.font].width );
			return((char *) 0);
		case	VISUAL_MEMBER_FONTHEIGHT :
			fprintf(h,"%u", Context.FontTable[iptr->Contents.font].height );
			return((char *) 0);
		case	VISUAL_MEMBER_FG	:
			fprintf(h,"%u",widget_foreground_value( iptr ));
			return((char *) 0);
		case	VISUAL_MEMBER_BG	:
			fprintf(h,"%u",widget_background_value( iptr ));
			return((char *) 0);
		case	VISUAL_MEMBER_FOCUS	:
			fprintf(h,"%u",iptr->Contents.focus);
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
					fprintf(h,"%s->value_%s",__c_instance_prefix,iptr->Contents.name);
					break;
				case	_FORM_FRAME	:
				case	_EDIT_FRAME	:
					fprintf(h,"Conv(%s->buffer_%s)",__c_instance_prefix,iptr->Contents.name);
					break;
				default			:
					c_syntax_error(tptr,11);
					break;
				}
			return((char *) 0);

		case	VISUAL_MEMBER_HINT	:
			c_hint_value( h, iptr );
			return((char *) 0);

		case	VISUAL_MEMBER_PAYLOAD	:
			c_payload_value(h,iptr);
			return((char *) 0);
		case	VISUAL_MEMBER_BUFFER	:
			fprintf(h,"%s->buffer_%s",__c_instance_prefix,iptr->Contents.name);
			return((char *) 0);
		case	VISUAL_MEMBER_LIMIT	:
			fprintf(h,"%s->limit_%s",__c_instance_prefix,iptr->Contents.name);
			return((char *) 0);

		case	VISUAL_MEMBER_MAX	:
			fprintf(h,"%s->max_%s",__c_instance_prefix,iptr->Contents.name);
			return((char *) 0);

		case	VISUAL_MEMBER_SIZE	:
			if ((iptr->Contents.style & _FRAME_TYPE) == _FORM_FRAME) {
				nbc = 0; nbr= 0;
				calculate_form_lines( iptr, &nbc, &nbr );
				iptr->Contents.size = (nbc*nbr);
				}
			else	calculate_edit_size( &iptr->Contents );
			fprintf(h,"%u",iptr->Contents.size);
			return((char *) 0);

		case	VISUAL_MEMBER_COLUMN	:
			return( c_member_column(h, iptr ) );

		case	VISUAL_MEMBER_LINE  	:
			return( c_member_line(h, iptr ) );

		case	VISUAL_MEMBER_COLUMNSIZE	:
			if (!( tptr = c_dimension() ))
				break;
			else	{
				return( c_macro_columnsize( h, iptr, tptr ) );
				}

		case	VISUAL_MEMBER_POSITION :
			if (!( tptr = c_dimension() ))
				break;
			else	{
				return( c_macro_position( h, iptr, tptr ) );
				}

		case	VISUAL_MEMBER_COLUMNS	:
			return( c_macro_columns( h, iptr ) );

		case	VISUAL_MEMBER_LINES	:
			if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME )
				calculate_edit_lines( iptr, &linesize, &linecount );
			else	calculate_form_lines( iptr, &linesize, &linecount );
			fprintf(h,"%u",linecount);
			return((char *) 0);

		case	VISUAL_MEMBER_LINESIZE	:
			if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME )
				calculate_edit_lines( iptr, &linesize, &linecount );
			else	calculate_form_lines( iptr, &linesize, &linecount );
			fprintf(h,"%u",linesize);
			return((char *) 0);

		case	VISUAL_MEMBER_FORMSORT	:
			fprintf(h,"%s->formsort_%s",__c_instance_prefix,iptr->Contents.name);
			return((char *) 0);

		case	VISUAL_MEMBER_TABSORT	:
			if (!( tptr = c_dimension() ))
				break;
			else	{
				fprintf(h,"sort_item_%s(%s,%s)",iptr->Contents.name,__c_instance_prefix,tptr);
				return((char *) 0);
				}

		case	VISUAL_MEMBER_LINESORT  	:
			return( c_member_linesort(h, iptr ) );

		case	VISUAL_MEMBER_START_SORT	:
			if (!( tptr = c_dimension() ))
				break;
			else	{
				fprintf(h,"start_sort_%s(%s,%s)",iptr->Contents.name,__c_instance_prefix,tptr);
				return((char *) 0);			
				}

		case	VISUAL_MEMBER_SORT	:
			if (!( tptr = c_dimension() ))
				break;
			else	{
				fprintf(h,"sort_%s(%s,%s)",iptr->Contents.name,__c_instance_prefix,tptr);
				return((char *) 0);				
				}

		case	VISUAL_MEMBER_HELP	:
			if (!( remove_brackets() ))
				break;
			else 	{
				if ( Context.Form->onlinehelp & 7 ) {
 					if ( detect_widget_help( iptr ) ) {
						invoke_c_widget_help(h,iptr);
						}
					}
				return((char *) 0);				
				}

		case	VISUAL_MEMBER_ATTACH	:
			if (!( remove_brackets() ))
				break;
			else	{
				fprintf(h,"%s_attach()",c_payload(iptr));
				return((char *) 0);
				}

		case	VISUAL_MEMBER_DETACH	:
			if (!( remove_brackets() ))
				break;
			else	{
				fprintf(h,"%s_detach()",c_payload(iptr));
				return((char *) 0);				
				}

		case	VISUAL_MEMBER_ONHIDE	:
			if (!( remove_brackets() ))
				break;
			if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP ) {
				generate_c_popdown(h,iptr,1);
				}
			if (( iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME) {
				c_hide_visual_widget(h,iptr,1);
				}
			return((char *) 0);

		case	VISUAL_MEMBER_ONFOCUS	:
			if (!( remove_brackets() ))
				break;
			else	c_onfocus_widget(h,iptr,1);
			return((char *) 0);

		case	VISUAL_MEMBER_ONSHOW	:
			if (!( remove_brackets() ))
				break;
			if ( iptr->Contents.events->xo_hide & _EVENT_IS_POP ) {
				generate_c_popup(h,iptr,1);
				}
			/* better use the standard method instead */
			/* -------------------------------------- */
			if ((iptr->Contents.style&_FRAME_TYPE) != _TAB_FRAME) {
				if (!( c_onshow_widget(h,iptr,1,0) ))
					fprintf(h,"on_%s_%s(%s);",iptr->Contents.name,tptr,__c_instance_prefix);
				}
			else	generate_c_show(h,iptr,1); 
			return((char *) 0);

		case	VISUAL_MEMBER_TRIGGER	:
			if (!( remove_brackets() ))
				break;
			generate_c_trigger(h,iptr,1);
			return((char *) 0);

		case	VISUAL_MEMBER_FREEZE	:
			if (!( remove_brackets() ))
				break;
			fprintf(h,"%s()",__visual_freeze);
			return((char *) 0);

		case	VISUAL_MEMBER_VIEWPORT	:
			if (!( remove_brackets() ))
				break;
			c_widget_viewport(h,iptr);
			return((char *) 0);

		case	VISUAL_MEMBER_THAW  	:
			if (!( remove_brackets() ))
				break;
			if ((( iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME )
			&&  ( iptr->Contents.align & _A_SHADOW )) {
				fprintf(h,"%s(%s,%s,%s+%u,%s+%u)",
					__visual_thaw,
					widget_x_position(iptr,0),
					widget_y_position(iptr,0),
					widget_w_dimension(iptr,0),10,
					widget_h_dimension(iptr,0),10);
				}
			else	{
				fprintf(h,"%s(%s,%s,%s,%s)",
					__visual_thaw,
					widget_x_position(iptr,0),
					widget_y_position(iptr,0),
					widget_w_dimension(iptr,0),
					widget_h_dimension(iptr,0));
				}
			return((char *) 0);

		case	VISUAL_MEMBER_FILL  	:
			if (!( remove_brackets() ))
				break;
			fprintf(h,"%s->%s=%s(%s,%s,%s,%s,%u,0)",
				__c_instance_prefix,"status",__visual_filzone,
				widget_x_position(iptr,0),
				widget_y_position(iptr,0),
				widget_w_dimension(iptr,0),
				widget_h_dimension(iptr,0),
				iptr->Contents.colour & 0x00FF,0 );
			return((char *) 0);

		case	VISUAL_MEMBER_WIPE  	:
			if (!( remove_brackets() ))
				break;
			fprintf(h,"%s->%s=%s(%s,%s,%s,%s,%u,0)",
				__c_instance_prefix,"status",__visual_filzone,
				widget_x_position(iptr,0),
				widget_y_position(iptr,0),
				widget_w_dimension(iptr,0),
				widget_h_dimension(iptr,0),
				((iptr->Contents.colour >> 8) & 0x00FF), 0 );
			return((char *) 0);

		case	VISUAL_MEMBER_RESET	:
			if (!( remove_brackets() ))
				break;
			return( c_macro_reset(h,iptr) );

		case	VISUAL_MEMBER_CREATE	:
		case	VISUAL_MEMBER_REMOVE	:
		case	VISUAL_MEMBER_SHOW  	:
		case	VISUAL_MEMBER_HIDE  	:
		case	VISUAL_MEMBER_EVENT 	:
		case	VISUAL_MEMBER_GETFOCUS	:
		case	VISUAL_MEMBER_LOSEFOCUS	:
			if (!( remove_brackets() ))
				break;
			for (i=0;*(tptr+i)!=0;i++)
				if (( *(tptr+i) >= 'A' )
				&&  ( *(tptr+i) <= 'Z' ))
					*(tptr+i) += ('a' - 'A');
			fprintf(h,"on_%s_%s(%s)",iptr->Contents.name,tptr,__c_instance_prefix);
			return((char *) 0);
			
		}
	c_syntax_error( tptr,12 );
	fprintf(h,"%s.",iptr->Contents.name);
	return( tptr );
			
}

private	int	c_method_line( FILE * h, char * eptr, int l, char * hptr, int * feeder )
{
	int	punctuate=1;
	int	c;
	char *	tptr;
	if ( feeder ) *feeder = 0;
	if (!( initialise_line_parser( eptr, hptr ) )) 
		return(0);
	while (1) {
		if ((c = c_get_punctuation())) {
			punctuate++;
			fprintf(h,"%c",c);
			}
		else if (!( tptr = c_get_token(0) ))
			break;
		else 	{
			if (!( punctuate ))
				fprintf(h," ");
			punctuate = 0;
			if (!(tptr =  c_convert_token(h,tptr) ))
				continue;
			else 	fprintf(h,"%s",tptr);
			}
		}
	*feeder = 1;
	return(LineParser.status);
}

public	int	c_macro_conversion( FILE * h, char * sptr, char * hptr )
{
	int	feeder=0;
	return( c_method_line( h, sptr, strlen(sptr), hptr, &feeder ) );
}


