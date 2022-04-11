#ifndef	_singjs_c
#define	_singjs_c

/*	-----------------------------------------------------------------------	*/
/*				s i n g j s _ c 				*/
/*	-----------------------------------------------------------------------	*/
/*	IJM August 2010								*/
/*	-----------------------------------------------------------------------	*/
/*	This source provides the collection of functions and variables needed	*/
/*	for the conversion of sing method blocks to produce a resolved JS form.	*/
/*	The method blocks are presumed to be already JS complient and only the	*/
/*	various SiNG macro extensions are detected for transformation.		*/ 
/*	This has been developed for us by the LASeR and BiFS extensions to the	*/
/*	standard production engine for the production of MPEG content a either	*/
/*	SVG,XSR or BT text streams, or MP4 binary packages.			*/
/*	-----------------------------------------------------------------------	*/

private	char * __JS_mouse_type  ="visual_event(1)";
private	char * __JS_mouse_button="visual_event(2)";
private	char * __JS_mouse_column="visual_event(7)";
private	char * __JS_mouse_row   ="visual_event(6)";
private	char * __JS_get_event   ="visual_getch";
private	char * __JS_put_error   ="visual_error";
private	char * __JS_test_event  ="visual_kbhit()";
private	char * __JS_visual_event="visual_event";
private	char * __JS_page_number ="page_number";
private	char * __JS_focus_item  ="focus_item";
private	char * __JS_keycode     ="keycode";
private	char * __JS_status      ="status";
private	char * __JS_stdinput    ="stdinput";

private	char * 	__JS_instance_prefix	="_Context";
private	char * 	__JS_instance_suffix	="_context";
private	int	_JS_margin=0;

char *	_JS_file_member( FILE * h, struct form_item * iptr, int i, char * tptr );
private	char *	_JS_convert_token( FILE * h, char * tptr );

/*	-----------------------------------------------------------------------	*/
/*				_ J S _ p a y l o a d				*/
/*	-----------------------------------------------------------------------	*/
/*	recovery of the widget payload for use by all other functions.		*/
/*	-----------------------------------------------------------------------	*/
public	char *	_JS_payload( struct form_item * iptr )
{
	struct 	form_control * fptr;
	if (!( fptr = iptr->parent ))
		return( iptr->Contents.payload );
	else if (!( fptr->formflags & _INTERNATIONAL ))
		return( iptr->Contents.payload );
	else	return( iptr->Contents.messages[fptr->natlang] );
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ s y n t a x _ e r r o r				*/
/*	-----------------------------------------------------------------------	*/
/*	display and report a JS processing syntax error.			*/
/*	-----------------------------------------------------------------------	*/
public int	_JS_syntax_error( char * vptr, int n )
{
	printf("\r\n** c syntax error (%u) : %s **\r\n",n,vptr);
	return( line_parser_error(n) );
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ i s _ p u n c t u a t i o n			*/
/*	-----------------------------------------------------------------------	*/
/*	test to see if the provided character is a legal punctuation character.	*/
/*	-----------------------------------------------------------------------	*/
private	int	_JS_is_punctuation( int c )
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

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ g e t _ p u n c t u a t i o n			*/
/*	-----------------------------------------------------------------------	*/
/*	returns a punctuation character or ZERO if not punctuation.		*/
/*	-----------------------------------------------------------------------	*/
public int	_JS_get_punctuation()
{
	int	c;
	int	status;
	if (!( not_white_space() ))
		return( 0 );
	else if (!( c = parser_getch() ))
		return(0);
	else if (!( _JS_is_punctuation(c))) {
		parser_ungetch();
		return(0);
		}
	else	return(c);
}

/*	-----------------------------------------------------------------------	*/
/*				_ J S _ g e t _ t o k e n			*/
/*	-----------------------------------------------------------------------	*/
/*	returns a token from the parsing stream or a NULL pointer otherwise.	*/
/*	-----------------------------------------------------------------------	*/
public	char *	_JS_get_token(int uppercase)
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
		else if ( _JS_is_punctuation(c) ) {
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

/*	-----------------------------------------------------------------------	*/
/*				_ J S _ l i n e _ p a r s e r			*/
/*	-----------------------------------------------------------------------	*/
/*	this is the basic line parser that handles JS instructions.		*/
/*	-----------------------------------------------------------------------	*/
void	_JS_line_parser( FILE * h )
{
	int	punctuate=1;
	int	c;
	char *	tptr;
	while (1) {
		if ((c = _JS_get_punctuation())) {
			punctuate++;
			fprintf(h,"%c",c);
			}
		else if (!( tptr = _JS_get_token(0) ))
			break;
		else 	{
			if (!( punctuate ))
				fprintf(h," ");
			punctuate = 0;
			if (!(tptr =  _JS_convert_token(h,tptr) ))
				continue;
			else 	fprintf(h,"%s",tptr);
			}
		}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				_ J S _ d i m e n s i o n			*/
/*	-----------------------------------------------------------------------	*/
/*	parse and collect a dimension element from the stream.			*/
/*	-----------------------------------------------------------------------	*/
public	char * _JS_dimension()
{
	int	c;
	char * tptr;
	if (!(c = _JS_get_punctuation() ))
		return( (char *) 0 );
	else if (c != '(' )
		return( (char *) 0 );
	else if (!( tptr = _JS_get_token(0) ))
		return( tptr );
	else if (!(c = _JS_get_punctuation() ))
		return( (char *) 0 );
	else if (c != ')' )
		return( (char *) 0 );
	else	return( tptr );
}

/*	-----------------------------------------------------------------------	*/
/*		_ J S _ r e m o v e _ b e t w e e n _ b r a c e s		*/
/*	-----------------------------------------------------------------------	*/
/*	consumes all between a matched pair of braces.
/*	-----------------------------------------------------------------------	*/
void	_JS_remove_between_braces()
{
	int	nesting=0;
	int	quoting=0;
	int	c;
	char * tptr;
	if (!(c = _JS_get_punctuation() ))
		return;
	else if (c != '(' )
		return;
	else
	{
		nesting = 1;
		while ( nesting )
		{
			if (!(c = _JS_get_punctuation()))
			{
				if (!( tptr = _JS_get_token(0) ))
					break;
			}
			else if (( c == 0x0022 )
			     ||  ( c == 0x0027 ))
			{
				if ( c == quoting )
					quoting = 0;
				else if (!( quoting ))
					quoting = c;
				continue;
			}
			else if ( quoting ) 
				continue;
			else if ( c == ')' )
			{
				if ( nesting )
					nesting--;
			}
			else if ( c == '(' )
			{
				nesting++;
			}
		}
		return;
	}
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ w i d g e t _ m e m b e r 			*/
/*	-----------------------------------------------------------------------	*/
/*	generates the resolved JS version of a widget element.			*/
/*	-----------------------------------------------------------------------	*/
private	void	_JS_widget_member( FILE * h, struct form_item * iptr, char * prefix )
{
	fprintf(h,"document.getElementById(%c%s%s%c).textContent",
		0x0022,prefix,iptr->Contents.name,0x0022 );
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ w i d g e t _ p a y l o a d 			*/
/*	-----------------------------------------------------------------------	*/
/*	generates the resolved JS version of a widget element.			*/
/*	-----------------------------------------------------------------------	*/
private	void	_JS_widget_payload( FILE * h, struct form_item * iptr, char * prefix )
{
	char *	tptr;
	int	c;
	if ( iptr->Contents.style != _IMAGE_FRAME )
		return((char *) 0);
	else if ((c = _JS_get_punctuation( h )) != '=' )
	{
		fprintf(h,"document.getElementById(%c%s%s%c).getAttributeNS(%c%s%c,%c%s%c)",
			0x0022,_WIDGET_PREFIX,iptr->Contents.name,0x0022,
			0x0022,_XLINK_NAMESPACE,0x0022,
			0x0022,"xlink:href",0x0022);
	}
	else
	{
		/* set attribute */
		fprintf(h,"document.getElementById(%c%s%s%c).setAttributeNS(%c%s%c,%c%s%c,",
			0x0022,_WIDGET_PREFIX,iptr->Contents.name,0x0022,
			0x0022,_XLINK_NAMESPACE,0x0022,
			0x0022,"xlink:href",0x0022);
		if (!( tptr = _JS_get_token(0) ))
			return;
		else 	_JS_convert_token(h,tptr);
		fprintf(h,");\n");
	}
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			   _ J S _ h i d e _ w i d g e t  			*/
/*	-----------------------------------------------------------------------	*/
/*	disactivates the visibility attribute of a widget group.		*/
/*	-----------------------------------------------------------------------	*/
private	void	_JS_hide_widget( FILE * h, struct form_item * iptr )
{
	fprintf(h,"document.getElementById(%c%s%s%c).setAttribute(%c%s%c,%c%s%c)",
		0x0022,_WIDGET_PREFIX,iptr->Contents.name,0x0022,
		0x0022,"visibility",0x0022,
		0x0022,"hidden",0x0022 );
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			   _ J S _ s h o w _ w i d g e t  			*/
/*	-----------------------------------------------------------------------	*/
/*	activates the visibility attribute of a widget group.			*/
/*	-----------------------------------------------------------------------	*/
private	void	_JS_show_widget( FILE * h, struct form_item * iptr )
{
	fprintf(h,"document.getElementById(%c%s%s%c).setAttribute(%c%s%c,%c%s%c)",
		0x0022,_WIDGET_PREFIX,iptr->Contents.name,0x0022,
		0x0022,"visibility",0x0022,
		0x0022,"inherit",0x0022 );
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ m a c r o _ c o l u m n				*/
/*	-----------------------------------------------------------------------	*/
/*	analysis of the SiNG macro expression widget.COLUMN providing the text	*/
/*	from the indicated cell of the current row of the table.		*/
/*	-----------------------------------------------------------------------	*/
private	char *	_JS_macro_column( FILE * h, struct form_item * iptr, char * tptr )
{
fprintf(h,
"document.getElementById('r'+String(document.getElementById('%s%s').textContent)+'c%s_%s').textContent",
	_LINE_PREFIX,iptr->Contents.name,
	tptr,iptr->Contents.name);
return((char *) 0);
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ m a c r o _ c o l u m n s i z e			*/
/*	-----------------------------------------------------------------------	*/
/*	analysis of the SiNG macro expression widget.COLUMNSIZE providing the 	*/
/*	width of the required table column.					*/
/*	-----------------------------------------------------------------------	*/
private	char *	_JS_macro_columnsize( FILE * h, struct form_item * iptr, char * tptr )
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
		_JS_syntax_error( iptr->Contents.name,3 );
		return((char *) 0);
		}
	else if (!( sptr = _JS_payload(iptr) )) {
		_JS_syntax_error( iptr->Contents.name,4 );
		return((char *) 0);
		}
	else if ( *sptr == _UNQUOTED_STRING ) {
		_JS_syntax_error( iptr->Contents.name,5 );
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
		else	_JS_syntax_error( iptr->Contents.name,6 );
		return((char *) 0);
		}
	else	{
		_JS_syntax_error( iptr->Contents.name,7 );
		return((char *) 0);
		}
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ m a c r o _ p o s i t i o n			*/
/*	-----------------------------------------------------------------------	*/
/*	analysis of the SiNG macro expression widget.POSITION providing the x,y	*/
/*	coordinate position of the element.					*/
/*	-----------------------------------------------------------------------	*/
public	char *	_JS_macro_position( FILE * h, struct form_item * iptr, char * tptr )
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
		_JS_syntax_error( iptr->Contents.name,6 );
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
		else	_JS_syntax_error( iptr->Contents.name,9 );
		return((char *) 0);
		}
	else	{
		_JS_syntax_error( iptr->Contents.name,10 );
		return((char *) 0);
		}
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ m a c r o _ c o l u m n s			*/
/*	-----------------------------------------------------------------------	*/
/*	analysis of the SiNG macro expression widget.COLUMNS, providing the 	*/
/*	number of columns of a table element.					*/
/*	-----------------------------------------------------------------------	*/
public	char *	_JS_macro_columns( FILE * h, struct form_item * iptr )
{
	int	linesize=1;
	int	linecount=1;
	int	fields;
	int	fieldwidth[_MAX_FORM_FIELDS];
	char *	sptr;

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME )
		calculate_edit_lines( iptr, &linesize, &linecount );
	else	calculate_form_lines( iptr, &linesize, &linecount );

	if (!( sptr = _JS_payload(iptr) )) {
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

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ m a c r o _ l i n e				*/
/*	-----------------------------------------------------------------------	*/
/*	analysis of the SiNG macro expression widget.LINE or widget.LINE(n)	*/
/*	This may be a read operation in the first case where the current line	*/
/*	number of the table is returned. In the second case the current line of	*/
/*	the table is set to the provided value.					*/
/*	-----------------------------------------------------------------------	*/
public	char *	_JS_macro_line( 
		FILE * h, struct form_item * iptr, char * tptr 
		)
{
	if (!( iptr->Contents.name ))
		return((char *) 0);
	else	{
		_JS_widget_member(h,iptr,_LINE_PREFIX);
		fprintf(h," = ");
		if (( tptr = _JS_convert_token(h,tptr)) != (char *) 0)
			fprintf(h,"%s.toString()",tptr);
		return((char *) 0);
		}	
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ c o l u m n _ v a r i a b l e			*/
/*	-----------------------------------------------------------------------	*/
/*	results in the variable name of the table column counter.		*/
/*	-----------------------------------------------------------------------	*/
private	char *	_JS_column_variable(FILE * h, struct form_item * iptr )
{
	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return((char *) 0);
	else if (!( iptr->Contents.name ))
		return((char *) 0);
	else	{
		_JS_widget_member(h,iptr,_COLUMN_PREFIX);
		return((char *) 0);
		}
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ l i n e _ v a r i a b l e			*/
/*	-----------------------------------------------------------------------	*/
/*	results in the variable name of the table line counter.			*/
/*	-----------------------------------------------------------------------	*/
private	char *	_JS_line_variable(FILE * h, struct form_item * iptr )
{
	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return((char *) 0);
	else if (!( iptr->Contents.name ))
		return((char *) 0);
	else	{
		_JS_widget_member(h,iptr,_LINE_PREFIX);
		return((char *) 0);
		}
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ m e m b e r _ c o l u m n			*/
/*	-----------------------------------------------------------------------	*/
/*	differenciates between the read and write forms of the widget.COLUMN	*/
/*	expression and performs dispatching.					*/
/*	-----------------------------------------------------------------------	*/
private	char *	_JS_member_column(FILE * h, struct form_item * iptr )
{
	int	c;
	char * tptr;
	if (!(c = _JS_get_punctuation() ))
		return( _JS_column_variable(h,iptr) );
	else if (c == '(' ) {
		if (!( tptr = _JS_get_token(0) ))
			return( tptr );
		else if (!(c = _JS_get_punctuation() ))
			return( (char *) 0 );
		else if (c != ')' )
			return( (char *) 0 );
		else 	return( _JS_macro_column( h, iptr, tptr ) );
		}
	else 	{
		parser_ungetch();
		return( _JS_column_variable(h,iptr) );
		}
}
/*	-----------------------------------------------------------------------	*/
/*			_ J S _ m e m b e r _ l i n e				*/
/*	-----------------------------------------------------------------------	*/
/*	differenciates between the read and write forms of the widget.LINE  	*/
/*	expression and performs dispatching.					*/
/*	-----------------------------------------------------------------------	*/
private	char *	_JS_member_line(FILE * h, struct form_item * iptr )
{
	int	c;
	char * tptr;
	if (!(c = _JS_get_punctuation() ))
		return( _JS_line_variable(h,iptr) );
	else if (c == '(' ) {
		if (!( tptr = _JS_get_token(0) ))
			return( tptr );
		else if (!(c = _JS_get_punctuation() ))
			return( (char *) 0 );
		else if (c != ')' )
			return( (char *) 0 );
		else 	return( _JS_macro_line( h, iptr, tptr ) );
		}
	else 	{
		parser_ungetch();
		return( _JS_line_variable(h,iptr) );
		}
}

/*	-----------------------------------------------------------------------	*/
/*					_ J S _ c a l l 			*/
/*	-----------------------------------------------------------------------	*/
/*	generates a standard coll to a java script function.			*/
/*	-----------------------------------------------------------------------	*/
private	void	_JS_call( FILE * h,  char * name, char * prefix,int a, int b, char * signature )
{
	fprintf(h,"%s%s()",prefix,name);
	return;
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ m e t h o d _ s t a t e m e n t			*/
/*	-----------------------------------------------------------------------	*/
/*	analysis and conversion of an eventual forms method statement.		*/
/*	-----------------------------------------------------------------------	*/
private	char *	_JS_method_statement( FILE * h, char * tptr, struct form_control * fptr )
{
	int	c;
	int	token;
	struct forms_method *	mptr;
	struct forms_method *	is_forms_Method( char *, struct form_control *);

	if ((mptr = is_forms_Method( tptr,fptr )) != (struct forms_method *) 0 ) {
		if (!(c = _JS_get_punctuation() ))
			return( tptr );
		else if (c != '(' )
			return( tptr );
		else	{
		/* was ---> 	fprintf(h,"%s(%s",tptr,__JS_instance_prefix); */
			fprintf(h,"%s%s(",LC.form->identifier,tptr);
			/* if ( method_is_valid( mptr->signature ) ) fprintf(h,","); */
			return((char *) 0);
			}

		}
	else	{
		switch ( is_visual_member( tptr, 1 ) ) {

			case	VISUAL_MEMBER_ONHIDE	:
				if (!( remove_brackets() ))
					break;
				else	{
					_JS_call(h,LC.form->identifier, _HIDE_PREFIX, 0,1,(char *) 0 );
					return((char *) 0);
					}

			case	VISUAL_MEMBER_ONSHOW	:
				if (!( remove_brackets() ))
					break;
				else	{
					_JS_call(h,LC.form->identifier,_SHOW_PREFIX, 0,1,(char *) 0 );
					return((char *) 0);
					}
			case	VISUAL_MEMBER_ONFOCUS	:
				if (!( remove_brackets() ))
					break;
				else	{
					_JS_call(h,LC.form->identifier,_FOCUS_PREFIX, 0,1,(char *) 0 );
					return((char *) 0);
					}
			}
		return( tptr );
		}
}

/*	-----------------------------------------------------------------------	*/
/*		_ J S _ w i d g e t _ o v e r l a y _ m e t h o d		*/
/*	-----------------------------------------------------------------------	*/
/*	generates a call to a widget overlay component method. TODO		*/
/*	-----------------------------------------------------------------------	*/
private	char *	_JS_widget_overlay_method( FILE * h, struct form_item * iptr,char * tptr )
{
	_JS_remove_between_braces();
	return((char *) 0);
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ r a d i o _ v a l u e				*/
/*	-----------------------------------------------------------------------	*/
/*	special case: generates the resolved JS version of a radio value	*/
/*	-----------------------------------------------------------------------	*/
private	void	_JS_radio_value( FILE * h, struct form_item * iptr, char * prefix )
{
	int	c;
	fprintf(h,"document.getElementById(%c%s%s%c).getAttribute(%cx%c)",
		0x0022,prefix,iptr->Contents.name,0x0022,0x0022,0x0022 );
	return;
}

/*	-----------------------------------------------------------------------	*/
/*				_ J S _ f i l e _ m e t h o d			*/
/*	-----------------------------------------------------------------------	*/
/*	analysis, processing and conversion of a widget file method.		*/
/*	-----------------------------------------------------------------------	*/
char *	_JS_file_method( FILE * h, struct form_item * iptr, int method, int mode, char * name )
{
	char	work[1024];
	char *	tptr;
	strcpy( work, name );
	switch( method )
	{
	case	DATA_MEMBER_ONCREATE	:
		strcpy(work,"Create");
		break;		
	case	DATA_MEMBER_ONREMOVE	:
		strcpy(work,"Remove");
		break;		
	case	DATA_MEMBER_LOCATE	:
		_JS_file_member(h,iptr,-1,_COLLECT_ITEM);
		fprintf(h," = ");
		if (( tptr = _JS_dimension()) != (char *) 0)
		{
			if ((tptr = _JS_convert_token(h,tptr)) != (char *) 0)
				fprintf(h," %s",tptr);
			fprintf(h,".toString();\n");
			indent(h,_JS_margin);
		}
		break;
	default				:
		remove_brackets();
	}

	fprintf(h,"%s%s('%s')",_REQUEST_PREFIX,iptr->Contents.name,work);

	return((char *) 0);
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ f i l e _ m e m b e r				*/
/*	-----------------------------------------------------------------------	*/
/*	analysis, processing and conversion of a widget file expression.	*/
/*	-----------------------------------------------------------------------	*/
char *	_JS_file_member( FILE * h, struct form_item * iptr, int i, char * tptr )
{
	int	type=3;
	char * member;
	switch ( i )
	{
		case	DATA_MEMBER_INDEX	:	
			member = _RECORD_INDEX;
			break;
		case	DATA_MEMBER_ERROR	:	
			member = _FILE_ERROR;
			type   = 1;
			break;
		case	DATA_MEMBER_HANDLE	:	
			member = _FILE_HANDLE;
			type   = 1;
			break;
		case	DATA_MEMBER_QUESTION	:
			member = _RECORD_QUESTION;
			break;
		case	DATA_MEMBER_RESPONSE	:
			member = _COLLECT_COUNT;
			type   = 1;
			break;
		case	DATA_MEMBER_LENGTH	:	
			member = _RECORD_LENGTH;
			type   = 1;
			break;
		case	DATA_MEMBER_MARKER 	:
			member = _RECORD_MARKER;
			break;
		case	DATA_MEMBER_DIRECTION	:
			member = _RECORD_DIRECTION;
			break;
		case	DATA_MEMBER_SECTOR	:	
			member = _FILE_SECTOR;
			type   = 1;
			break;
		case	DATA_MEMBER_FLAG 	:	
			member = _COLLECT_TABLE;
			break;
		default				:
			member = tptr;
		}
	fprintf(h,"document.getElementById(%c%s%s%c).textContent",
		0x0022,iptr->Contents.name,member,0x0022 );
	return((char *) 0);	
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ f i l e _ e x p r e s s i o n			*/
/*	-----------------------------------------------------------------------	*/
/*	analysis, processing and conversion of a widget file expression.	*/
/*	-----------------------------------------------------------------------	*/
char *	_JS_file_expression( FILE * h, struct form_item * iptr )
{
	int	i;
	struct	data_control * 	dptr;
	char *	tptr;
	if (!( tptr = _JS_get_token(0) ))
		return( _JS_syntax_error(h,"missing token") );
	else if (!(dptr = iptr->Contents.extra ))
		return;
	else if ((i = is_data_member( tptr, 1 )) != -1)
	{
		switch ( i )
		{
		case	DATA_MEMBER_ASSIGN	:
		case	DATA_MEMBER_OPEN	:	 
		case	DATA_MEMBER_CLOSE	:	
		case	DATA_MEMBER_CFILE	:	
		case	DATA_MEMBER_DFILE	:	
		case	DATA_MEMBER_UPDATE	:	
		case	DATA_MEMBER_INSERT	:	
		case	DATA_MEMBER_MODIF	:	
		case	DATA_MEMBER_DELETE	:	
		case	DATA_MEMBER_SEARCH	:	
		case	DATA_MEMBER_FIRST	:	
		case	DATA_MEMBER_UP		:	
		case	DATA_MEMBER_PREVIOUS	:
		case	DATA_MEMBER_DOWN	:	
		case	DATA_MEMBER_NEXT	:	
		case	DATA_MEMBER_LAST	:	
		case	DATA_MEMBER_LOCK	:
		case	DATA_MEMBER_POSIT	:	
		case	DATA_MEMBER_COUNT	:	
		case	DATA_MEMBER_COLLECT	:
		case	DATA_MEMBER_LOCATE	:	
		case	DATA_MEMBER_LINK 	:	
		case	DATA_MEMBER_CLINK 	:	
		case	DATA_MEMBER_ONCREATE	:
		case	DATA_MEMBER_ONREMOVE	:
		case	DATA_MEMBER_RENAME 	:
		case	DATA_MEMBER_ATB 	:	
		case	DATA_MEMBER_KEY 	:	
		case	DATA_MEMBER_FKEY 	:	
		case	DATA_MEMBER_CKEY 	:	
		case	DATA_MEMBER_RKEY 	:	
		case	DATA_MEMBER_NKEY 	:	
		case	DATA_MEMBER_RECORD 	:
		case	DATA_MEMBER_JOIN 	:	
		case	DATA_MEMBER_CJOIN 	:	
		case	DATA_MEMBER_DJOIN 	:	
		case	DATA_MEMBER_RJOIN 	:	
		case	DATA_MEMBER_LJOIN 	:	
		case	DATA_MEMBER_LFILE 	:	
		case	DATA_MEMBER_LLIST 	:	
		case	DATA_MEMBER_LKEY 	:	
		case	DATA_MEMBER_EXPORT	:	
		case	DATA_MEMBER_IMPORT	:	
			return( _JS_file_method(h, iptr,i, 1,tptr ) );

		case	DATA_MEMBER_INDEX	:	
		case	DATA_MEMBER_ERROR	:	
		case	DATA_MEMBER_HANDLE	:	
		case	DATA_MEMBER_QUESTION	:
		case	DATA_MEMBER_RESPONSE	:
		case	DATA_MEMBER_LENGTH	:	
		case	DATA_MEMBER_MARKER 	:
		case	DATA_MEMBER_DIRECTION	:
		case	DATA_MEMBER_SECTOR	:	
		case	DATA_MEMBER_FLAG 	:	
			break;
		}
	}

	if (!( _JS_file_member(h, iptr, i, tptr ) ))
		return((char*)0);
	else	return( tptr );
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ c o n v e r t _ t o k e n 			*/
/*	-----------------------------------------------------------------------	*/
/*	analysis, processing and conversion of a token read from the stream.	*/
/*	-----------------------------------------------------------------------	*/
private	char *	_JS_convert_token( FILE * h, char * tptr )
{
	int	nbc=0;
	int	nbr=0;
	int	linesize=1;
	int	linecount=1;
	int	i;
	int	c;
	char * xtptr;
	char	work[1024];
	struct form_item * iptr;

	/* ---------------------------------------- */
	/* detect and handle simple transformations */
	/* ---------------------------------------- */
	/* THIS */
	/* ---- */
	if (( LineParser.thisname )
	&&  ( string_compare( tptr, keyword_this ) ))
		tptr = LineParser.thisname;

	/* EXIT */
	/* ---- */
	else if ( upper_compare( tptr, keyword_exit ) ) {
		if ( not_white_space() != '(' )
			return( tptr );
		else	{
			fprintf(h,"return");
			return((char *) 0);
			}
		}
	/* FOCUSITEM */
	/* --------- */
	else if ( upper_compare( tptr, keyword_focusitem ) ) {
		fprintf(h,"%s.%s",__JS_instance_prefix,__JS_focus_item);
		return((char *) 0);
		}
	/* THISFORM */
	/* -------- */
	else if ( upper_compare( tptr, keyword_thisform ) ) {
		if ((c = parser_getch()) != '.' ) {
			parser_ungetch();
			return( tptr );
			}
		else if (!( xtptr = _JS_get_token(1) )) {
			fprintf(h,"%s.",tptr);
			return( xtptr );
			}
		return( _JS_method_statement( h, xtptr, LC.form ) );
		}

	/* -------------------------- */
	/* Detect a Widget Identifier */
	/* -------------------------- */
	if (!( iptr = locate_widget( tptr,LC.form ) ))
		return( _JS_method_statement( h, tptr, LC.form ) );

	/* ---------------------- */
	/* Detect a Widget Member */
	/* ---------------------- */
	else if ((c = parser_getch()) != '.' ) {
		parser_ungetch();
		return( tptr );
		}

	/* -------------------------- */
	/* Detect a Widget Component  */
	/* -------------------------- */
	if ((iptr->Contents.style & _FRAME_TYPE) == _DATA_FRAME)
	{
		if ((iptr->Contents.align & 0x000F) == _VISUAL_FRAME) 
		{
			if (!( tptr = _JS_get_token(0) ))
				return( tptr );
			else if ((i = is_visual_member( tptr,1 )) == -1) 
			{
				if ( iptr->Contents.datatype == _WIDGET_MODULE  )
					return( _JS_widget_overlay_method(h,iptr,tptr) );
				else if ( iptr->Contents.datatype == _WIDGET_OVERLAY )
					return( _JS_widget_overlay_method(h,iptr,tptr) );
				else	return((char *) 0);
			}
			return(_JS_syntax_error( h, tptr ) );
		}
		else if (!( is_file_Widget( iptr ) ))
			return(_JS_syntax_error( h, tptr ) );
		else	return(_JS_file_expression(h,iptr));
	}

	/* ------------------------- */
	/* Collect Member Identifier */
	/* ------------------------- */
	else if (!( tptr = _JS_get_token(1) )) {
		fprintf(h,"%s.",iptr->Contents.name);
		return( tptr );
		}

	/* -------------------------- */
	/* Anaysis of Widget Member */
	/* -------------------------- */
	switch ((i = is_visual_member( tptr, 1 )))
	{
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
		switch ((iptr->Contents.style & _FRAME_TYPE)) 
		{
		case	_RADIO_FRAME	:
			_JS_radio_value(h,iptr,_VALUE_PREFIX);
			return((char *) 0);
		case	_CHECK_FRAME	:
		case	_SELECT_FRAME	:
		case	_SWITCH_FRAME	:
		case	_GRAPH_FRAME	:
		case	_SCROLL_FRAME	:
		case	_PROGRESS_FRAME	:
			_JS_widget_member(h,iptr,_VALUE_PREFIX);
			return((char *) 0);
		case	_FORM_FRAME	:
		case	_EDIT_FRAME	:
			sprintf(work,"%s%u_",_BUFFER_PREFIX,iptr->sequence);
			_JS_widget_member(h,iptr,work);
			return((char *) 0);
		default			:
			_JS_syntax_error(tptr,11);
			break;
		}
		return((char *) 0);

	case	VISUAL_MEMBER_HINT	:
		return((char *) 0);

	case	VISUAL_MEMBER_PAYLOAD	:
		sprintf(work,"%s%u_",_BUFFER_PREFIX,iptr->sequence);
		_JS_widget_payload(h,iptr,work);
		return((char *) 0);
	case	VISUAL_MEMBER_BUFFER	:
		sprintf(work,"%s%u_",_BUFFER_PREFIX,iptr->sequence);
		_JS_widget_member(h,iptr,work);
		return((char *) 0);
	case	VISUAL_MEMBER_LIMIT	:
		_JS_widget_member(h,iptr,_LIMIT_PREFIX);
		return((char *) 0);
	case	VISUAL_MEMBER_MAX	:
		_JS_widget_member(h,iptr,_MAX_PREFIX);
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
		return( _JS_member_column(h, iptr ) );

	case	VISUAL_MEMBER_LINE  	:
		return( _JS_member_line(h, iptr ) );

	case	VISUAL_MEMBER_COLUMNSIZE	:
		if (!( tptr = _JS_dimension() ))
			break;
		else	return( _JS_macro_columnsize( h, iptr, tptr ) );

	case	VISUAL_MEMBER_POSITION :
		if (!( tptr = _JS_dimension() ))
			break;
		else	return( _JS_macro_position( h, iptr, tptr ) );

	case	VISUAL_MEMBER_COLUMNS	:
		return( _JS_macro_columns( h, iptr ) );

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
		return((char *) 0);

	case	VISUAL_MEMBER_TABSORT	:
		return((char *) 0);

	case	VISUAL_MEMBER_LINESORT  	:
		return((char *) 0);

	case	VISUAL_MEMBER_START_SORT	:
		return((char *) 0);

	case	VISUAL_MEMBER_SORT	:
		if (!( tptr = _JS_dimension() ))
			break;
		else	return((char *) 0);				

	case	VISUAL_MEMBER_HELP	:
		remove_brackets();
		return((char *) 0);				

	case	VISUAL_MEMBER_ATTACH	:
		remove_brackets();
		return((char *) 0);

	case	VISUAL_MEMBER_DETACH	:
		remove_brackets();
		return((char *) 0);				

	case	VISUAL_MEMBER_ONHIDE	:
		remove_brackets();
		_JS_hide_widget(h,iptr);
		return((char *) 0);

	case	VISUAL_MEMBER_ONFOCUS	:
		remove_brackets();
		return((char *) 0);

	case	VISUAL_MEMBER_ONSHOW	:
		remove_brackets();
		_JS_show_widget(h,iptr);
		return((char *) 0);

	case	VISUAL_MEMBER_TRIGGER	:
		remove_brackets();
		return((char *) 0);

	case	VISUAL_MEMBER_FREEZE	:
		remove_brackets();
		return((char *) 0);

	case	VISUAL_MEMBER_VIEWPORT	:
		remove_brackets();
		return((char *) 0);

	case	VISUAL_MEMBER_THAW  	:
		remove_brackets();
		return((char *) 0);

	case	VISUAL_MEMBER_FILL  	:
		remove_brackets();
		return((char *) 0);

	case	VISUAL_MEMBER_WIPE  	:
		remove_brackets();
		return((char *) 0);

	case	VISUAL_MEMBER_RESET	:
		remove_brackets();
		return((char *) 0);

	case	VISUAL_MEMBER_CREATE	:
		if (!( remove_brackets() ))
			break;
		_JS_call(h,iptr->Contents.name,_CREATE_PREFIX,0,0,"");
		return((char *) 0);
	case	VISUAL_MEMBER_REMOVE	:
		if (!( remove_brackets() ))
			break;
		_JS_call(h,iptr->Contents.name,_REMOVE_PREFIX,0,0,"");
		return((char *) 0);
	case	VISUAL_MEMBER_SHOW  	:
		if (!( remove_brackets() ))
			break;
		_JS_call(h,iptr->Contents.name,_SHOW_PREFIX,0,0,"");
		return((char *) 0);
	case	VISUAL_MEMBER_HIDE  	:
		if (!( remove_brackets() ))
			break;
		_JS_call(h,iptr->Contents.name,_HIDE_PREFIX,0,0,"");
		return((char *) 0);
	case	VISUAL_MEMBER_EVENT 	:
		if (!( remove_brackets() ))
			break;
		_JS_call(h,iptr->Contents.name,_EVENT_PREFIX,0,0,"");
		return((char *) 0);
	case	VISUAL_MEMBER_GETFOCUS	:
		if (!( remove_brackets() ))
			break;
		_JS_call(h,iptr->Contents.name,_FOCUS_PREFIX,0,0,"");
		return((char *) 0);
	case	VISUAL_MEMBER_LOSEFOCUS	:
		if (!( remove_brackets() ))
			break;
		_JS_call(h,iptr->Contents.name,_LOSE_PREFIX,0,0,"");
		return((char *) 0);
	}
	_JS_syntax_error( tptr,12 );
	fprintf(h,"%s.",iptr->Contents.name);
	return( tptr );
		
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ m e t h o d _ l i n e				*/
/*	-----------------------------------------------------------------------	*/
/*	allows easy termnal parsing of the current line. required when 		*/
/*	encapsulating a collection under another expression call.		*/
/*	-----------------------------------------------------------------------	*/
private	int	_JS_method_line( FILE * h, char * eptr, int l, char * hptr, int * feeder )
{

	if ( feeder ) *feeder = 0;

	if (!( initialise_line_parser( eptr, hptr ) )) 
		return(0);
	
	_JS_line_parser( h );

	*feeder = 1;
	return(LineParser.status);
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ m a c r o _ c o n v e r s i o n 		*/
/*	-----------------------------------------------------------------------	*/
/*	conversion of an unquoted string to its JS equivalence. not used yet.	*/
/*	-----------------------------------------------------------------------	*/
public	int	_JS_macro_conversion( FILE * h, char * sptr, char * hptr )
{
	int	feeder=0;
	return( _JS_method_line( h, sptr, strlen(sptr), hptr, &feeder ) );
}

/*	-----------------------------------------------------------------------	*/
/*			_ J S _ m e t h o d _ b o d y				*/
/*	-----------------------------------------------------------------------	*/
/*	processing of a complete method body unit for either forms or widget	*/
/*	methods. the host parameter defines the current value of this.		*/
/*	-----------------------------------------------------------------------	*/
private	int	_JS_method_body( FILE * h, char * eptr, int l, char * hptr, int margin )
{
	int	i;
	int	c;
	char *	lptr;
	int	status=0;
	int	feeder=0;
	_JS_margin = margin;
	while ( *eptr != 0 ) {
		/* avoid empty lines */
		feeder=0;
		if (( *eptr == '\n' ) 
		||  ( *eptr == '\r' )) {
			eptr++;
			continue;
			}
		else	{
			/* scan till end of line or zero */
			/* ----------------------------- */
			for (	i=0,lptr = eptr;
				*eptr != 0;
				eptr++ ) {
				if (( *eptr == '\n' ) 
				||  ( *eptr == '\r' ))
					break;
				else	i++;
				}
			c = *eptr;
			*eptr = 0;
			indent(h,margin);
			status = _JS_method_line(h,lptr,i,hptr,&feeder);
			*eptr = c;
			if ( feeder ) linefeed(h);
			if ( status ) break;
			}
		}
	return(status);
}

#endif	/* _singjs_c */
	/* --------- */

