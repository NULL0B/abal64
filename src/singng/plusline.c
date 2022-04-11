extern	char * keyword_dcl;
extern	char * keyword_ptr;
extern	char * keyword_field;

private	char *	aplus_macro_reset( FILE * h, struct form_item * iptr )
{
	if ( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS ) {
		/* Generate Position and Dimensions Variables */
		fprintf(h,"%s.x=%s",iptr->Contents.name,widget_x_position(iptr,1));
		fprintf(h,"::%s.y=%s",iptr->Contents.name,widget_y_position(iptr,1));
		fprintf(h,"::%s.w=%s",iptr->Contents.name,widget_w_dimension(iptr,1));
		fprintf(h,"::%s.h=%s",iptr->Contents.name,widget_h_dimension(iptr,1));
		}
	if (( iptr->Contents.style & _FRAME_TYPE ) == _EDIT_FRAME ) {
		linefeed(h);
		indent(h,1);
		fprintf(h,"%s.reset",iptr->Contents.name);
		}
	else if (( iptr->Contents.style & _FRAME_TYPE ) == _DATA_FRAME ) {
		linefeed(h);
		indent(h,1);
		fprintf(h,"%s.reset",iptr->Contents.name);
		}
	return((char*)0);
}

private	void	lower_string( FILE * h, char * tptr )
{
	int	c;
	while ((c =  *(tptr++)) != 0) {
		if (( c >= 'A') && ( c <= 'Z'))
			c += ('a' - 'A');
		fprintf(h,"%c",c);
		}
	return;
}

private	void	aplus_use_prefix( FILE * h, char * prefix )
{
	if ( prefix )
		fprintf(h,"%s.",prefix);
	return;
}

public	char *	aplus_token_expression( 
		FILE * h,
		struct form_item * iptr,
		char *		tptr,
		int		i,
		char *		prefix )
{

	switch ( i ) {
		case	VISUAL_MEMBER_BUFFER	:
			if ( not_white_space() == '=' ) {
				aplus_use_prefix(h,prefix);
				fprintf(h,"%s.validate",iptr->Contents.name);
				linefeed(h);
				indent(h,1);
				aplus_use_prefix(h,prefix);
				fprintf(h,"%s.",iptr->Contents.name);
				lower_string(h,tptr);
				}
			else	{
				aplus_use_prefix(h,prefix);
				fprintf(h,"%s.getbuffer",iptr->Contents.name);
				}			
			return((char *) 0);

		case	VISUAL_MEMBER_PAYLOAD	:
			if ( abal_payload( iptr ) )
				string_value(h,abal_payload( iptr ) );
			return((char *) 0);

		case	VISUAL_MEMBER_ONFOCUS	:
			if (!( remove_brackets() ))
				break;
			aplus_use_prefix(h,prefix);
			fprintf(h,"%s.on_focus",iptr->Contents.name);
			return((char *) 0);

		case	VISUAL_MEMBER_ONSHOW	:
			if (!( remove_brackets() ))
				break;
			aplus_use_prefix(h,prefix);
			fprintf(h,"%s.on_show",iptr->Contents.name);
			return((char *) 0);

		case	VISUAL_MEMBER_ONHIDE	:
			if (!( remove_brackets() ))
				break;
			aplus_use_prefix(h,prefix);
			fprintf(h,"%s.on_hide",iptr->Contents.name);
			return((char *) 0);

		case	VISUAL_MEMBER_FREEZE	:
			if (!( remove_brackets() ))
				break;
			aplus_use_prefix(h,prefix);
			fprintf(h,"%s=%s()","result",__abal_visual_freeze);
			return((char *) 0);

		case	VISUAL_MEMBER_THAW  	:
			if (!( remove_brackets() ))
				break;
			aplus_use_prefix(h,prefix);
			fprintf(h,"%s=%s(%s,%s,%s,%s)",
				"result",__abal_visual_thaw,
				widget_x_position(iptr,0),
				widget_y_position(iptr,0),
				widget_w_dimension(iptr,0),
				widget_h_dimension(iptr,0));
			return((char *) 0);

		case	VISUAL_MEMBER_VIEWPORT		:
			if (!( remove_brackets() ))
				break;
			aplus_use_prefix(h,iptr->Contents.name);
			fprintf(h,"viewport");
			return((char *) 0);

		case	VISUAL_MEMBER_KEY  	:
			aplus_use_prefix(h,iptr->Contents.name);
			fprintf(h,"VisualKey");
			return((char *) 0);
			

		case	VISUAL_MEMBER_FILL  	:
			if (!( remove_brackets() ))
				break;
			aplus_use_prefix(h,prefix);
			fprintf(h,"%s=%s(%s,%s,%s,%s,%u,0)",
				"result",__abal_visual_fill,
				widget_x_position(iptr,0),
				widget_y_position(iptr,0),
				widget_w_dimension(iptr,0),
				widget_h_dimension(iptr,0),
				iptr->Contents.colour & 0x00FF );
			return((char *) 0);

		case	VISUAL_MEMBER_WIPE  	:
			if (!( remove_brackets() ))
				break;
			aplus_use_prefix(h,prefix);
			fprintf(h,"%s=%s(%s,%s,%s,%s,%u,0)",
				"result",__abal_visual_fill,
				widget_x_position(iptr,0),
				widget_y_position(iptr,0),
				widget_w_dimension(iptr,0),
				widget_h_dimension(iptr,0),
				((iptr->Contents.colour >> 8) & 0x00FF) );
			return((char *) 0);

		case	VISUAL_MEMBER_RESET	:
			if (!( remove_brackets() ))
				break;
			return( aplus_macro_reset(h,iptr) );

		case	VISUAL_MEMBER_SHOW  	:
			if (!( remove_brackets() ))
				break;
/*
			aplus_use_prefix(h,prefix);
			fprintf(h,"%s.on_show",iptr->Contents.name);
			linefeed(h);
 */
			indent(h,1);
			fprintf(h,"on_%s_",iptr->Contents.name);
			lower_string(h,tptr);
			return((char *) 0);

		case	VISUAL_MEMBER_COLUMN	:
			aplus_use_prefix(h,prefix);
			fprintf(h,"%s.member",iptr->Contents.name);
			copy_brackets(h);
			linefeed(h);
			indent(h,1);
			aplus_use_prefix(h,prefix);
			fprintf(h,"%s.colbuffer",iptr->Contents.name);
			return( (char *) 0);
		case	VISUAL_MEMBER_CREATE	:
		case	VISUAL_MEMBER_REMOVE	:
		case	VISUAL_MEMBER_HIDE  	:
		case	VISUAL_MEMBER_EVENT 	:
		case	VISUAL_MEMBER_GETFOCUS	:
		case	VISUAL_MEMBER_LOSEFOCUS	:
			if (!( remove_brackets() ))
				break;
			aplus_use_prefix(h,prefix);
			fprintf(h,"on_%s_",iptr->Contents.name);
			lower_string(h,tptr);
			return((char *) 0);

		default			:
			aplus_use_prefix(h,prefix);
			if ((i = is_data_member( tptr, 1 )) == DATA_MEMBER_ERROR )
				fprintf(h,"%s.error_value",iptr->Contents.name);
			else	fprintf(h,"%s.%s",iptr->Contents.name,tptr);
			return((char *) 0);
		}
	abal_syntax_error(h, tptr,15 );
	fprintf(h,"%s.",iptr->Contents.name);
	return( tptr );
}

private	char * AplusToken[] = {
	"EXIT",
	"ONSHOW",
	"ONHIDE",
	"KEYCODE",
	"VISUALKEY",
	"VISUALFILL"
	"VISUALFREEZE",
	"VISUALTHAW"

	};
#define	_APLUS_EXIT		0x0000
#define	_APLUS_ONSHOW		0x0001
#define	_APLUS_ONHIDE		0x0002
#define	_APLUS_KEYCODE		0x0003
#define	_APLUS_VISUALKEY	0x0004
#define	_APLUS_VISUALFILL	0x0005
#define	_APLUS_VISUALFREEZE	0x0006
#define	_APLUS_VISUALTHAW	0x0007
#define	MAX_APLUS_TOKENS	0x0008

private	aplus_specific_syntax( FILE * h, char * tptr, char * prefix )
{
	int	i;
	for ( i=0; i < MAX_APLUS_TOKENS; i++ ) {
		if ( upper_compare(AplusToken[i],tptr) ) {
			switch ( i ) {
				case	_APLUS_EXIT	:
					if ( not_white_space() != '(' )
						return( -1 );
					else	{
						aplus_use_prefix(h,prefix);
						fprintf(h,"visual_event..pending");
						return(1);
						}
				case	_APLUS_ONSHOW	:
					if (!( remove_brackets() ))
						return( -1 );
					else	{
						aplus_use_prefix(h,prefix);
						fprintf(h,"on_show");
						return(1);
						}
				case	_APLUS_ONHIDE	:

					if (!( remove_brackets() ))
						return( -1 );
					else	{
						aplus_use_prefix(h,prefix);
						fprintf(h,"on_hide");
						return(1);
						}
				case	_APLUS_KEYCODE	:
					aplus_use_prefix(h,prefix);
					fprintf(h,"visual_event..keycode");
					return(1);

				case	_APLUS_VISUALKEY	:
					aplus_use_prefix(h,prefix);
					fprintf(h,"visual_event..VisualKey");
					return(1);

				case	_APLUS_VISUALFILL	:
					aplus_use_prefix(h,prefix);
					fprintf(h,"visual_library_interface..VisualFill");
					return(1);
				case	_APLUS_VISUALFREEZE	:
					aplus_use_prefix(h,prefix);
					fprintf(h,"visual_library_interface..VisualFreeze");
					return(1);
				case	_APLUS_VISUALTHAW	:
					aplus_use_prefix(h,prefix);
					fprintf(h,"visual_library_interface..VisualThaw");
					return(1);
				}
			return(1);
			}
		}
	return(0);
}

private	char *	aplus_convert_token( FILE * h, char * tptr, char * prefix )
{
	struct	form_item * iptr;
	struct 	forms_method *	mptr;
	struct 	forms_method *	is_forms_Method( char *);
	int	i;
	int	c;

	if (( LineParser.thisname )
	&&  ( upper_compare( tptr, keyword_this) ))
		tptr = LineParser.thisname;

	switch ( aplus_specific_syntax( h, tptr, prefix )) {
		case	 1 : return( (char *) 0 );
		case 	-1 : return( tptr );
		}

	if (( upper_compare( tptr, keyword_dcl   ))
	||  ( upper_compare( tptr, keyword_ptr   ))
	||  ( upper_compare( tptr, keyword_field ))) {
		fprintf(h,"local ");
		return( tptr );
		}

	if (!( iptr = locate_widget( tptr ) )) {
		if (!( mptr = is_forms_Method( tptr ) ))
			return( abal_method_statement( h, tptr ) );
		else	{
			if (!( prefix )) /* IJM/BG */
				fprintf(h,"%s",tptr);
			else	fprintf(h,"%s.%s",prefix,tptr);
			return( (char *) 0);
			}
		}
	else if ((c = parser_getch()) != '.' ) {
		parser_ungetch();
		return( tptr );
		}
	else if (!( tptr = abal_get_token(0) )) {
		aplus_use_prefix(h,prefix);
		fprintf(h,"%s.",iptr->Contents.name);
		return( tptr );
		}

	i = is_visual_member( tptr, 1 );

	return( aplus_token_expression(h, iptr, tptr, i, prefix ) );

}

public	struct form_control * locate_form_control( char * sptr );


public	char *	aplus_convert_visual(FILE * h,char * prefix , char * mptr, char * sptr)
{
	struct form_control * fptr;
	struct form_control * xptr;
	if (!( fptr = locate_form_control( sptr ) ))
		return( mptr );
	xptr = Context.Form;
	Context.Form  = fptr;
	sptr = aplus_convert_token( h, mptr, prefix );
	Context.Form  = xptr;
	return( sptr );
}

public	int	aplus_method_line( FILE * h, char * eptr, int l, char * hptr, int * feeder )
{
	int	punctuate=1;
	int	c;
	char *	tptr;
	if ( feeder ) * feeder = 0;
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
			if (!(tptr =  aplus_convert_token(h,tptr,(char *) 0) ))
				continue;
			else 	fprintf(h,"%s",tptr);
			}
		}
	if ( feeder ) * feeder = 1;
	return(LineParser.status);
}

public	int	aplus_macro_conversion( FILE * h, char * sptr, char * hptr )
{
	int	feeder=0;
	return( aplus_method_line( h, sptr, strlen(sptr), hptr, &feeder ) );
}

