#ifndef	_phpform_c
#define	_phpform_c

private	char	RadioName[512];

private	int	show_status = 0;
private	int	SoapAgent=0;

private	int	abal_php_soap_method( FILE * h, struct form_item * iptr, char * nptr, char * mptr );
private	void	php_instance_style(FILE * h);
private	void	php_style_construction(FILE * h);
private	void	php_style_invocation( FILE * h );
public  void    php_current_payload( FILE * h, struct form_item * iptr, int comma );

public	int	php_can_show() { return( show_status ); }

private	int	is_valid_string( char * sptr )
{
	if (!( sptr ))
		return( 0 );
	else if (!( strlen( sptr ) ))
		return( 0 );
	else 	return( 1 );
}

/*	----------------------------------------------------------	*/
/*	     r e s o l v e _ w i d g e t _ f i l e _ c l a s s		*/
/*	----------------------------------------------------------	*/
/*	resolves the class filename of a data widget element.		*/
/*	----------------------------------------------------------	*/
public	char * resolve_widget_file_class( struct form_item * iptr )
{
	struct	data_control * 	dptr=(struct data_control *) 0;
	int			fields;
	char	*		cptr;
	char	*		nptr;
	char			classname[1024];
	int	i;

	if (!( is_file_Widget( iptr ) ))
		return((char *) 0);
	else if (!(dptr = iptr->Contents.extra ))
		return((char *) 0);
	else if (!( fields = dptr->indexfields + dptr->datafields ))
		return((char *) 0);
	else if (!( cptr = iptr->Contents.format ))
		return((char *) 0);
	else if ( *(cptr++) != '(' )
		return((char *) 0);
	else	{
		for (i=0; i < 1023; i++ ) {
			if ((*cptr == ' ')
			||  (*cptr == '.')
			||  (*cptr == ',')
			||  (*cptr == ';')
			||  (*cptr == ':')
			||  (*cptr == ')'))
				break;
			classname[i] = *(cptr++);
			}
		classname[i] = 0;
		return( allocate_string( classname ) );
		}
}

/*	----------------------------------------------------------	*/
/*		     p h p _ w i d g e t _ n a m e 			*/
/*	----------------------------------------------------------	*/
/*	returns a name string for use for widget identification		*/
/*	----------------------------------------------------------	*/
private	char	PhpWidgetName[2048];
private	char * php_widget_name( struct form_item * iptr )
{
	struct	form_control * fptr;
	if ((iptr->Contents.style & _FRAME_TYPE) != _RADIO_FRAME) 
	{
		if (!( fptr = iptr->parent ))
			return( iptr->Contents.name );
		else if (!( is_valid_string( fptr->extends ) ))
			return( iptr->Contents.name );
		{
			sprintf(PhpWidgetName, "%s_%s",fptr->identifier,iptr->Contents.name);
			return( PhpWidgetName );
		}
		/* return( iptr->Contents.name ); */
	}
	else	
	{
		sprintf(RadioName,"%s_%u",iptr->Contents.name,iptr->Contents.radio);
		return( RadioName );
	}
}

/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
private	void	php_open_method(FILE * h, char * sptr)
{
	fprintf(h,"\n\tpublic function %s\n\t{\n",sptr);
}

/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
private	void	php_close_method(FILE * h)
{
	fprintf(h,"\n\t}\n");
}

/*	----------------------------------------------------------	*/
/*		p h p _ w i d g e t _ l a b e l				*/
/*	----------------------------------------------------------	*/
/*	indicates true or false if the widget can carry a label		*/
/*	----------------------------------------------------------	*/
private	int	php_widget_label( struct form_item * iptr )
{
	switch ((iptr->Contents.style & _FRAME_TYPE)) 
	{
	case	_FORM_FRAME	:
	case	_SELECT_FRAME	:
	case	_IMAGE_FRAME	:
	case	_TEXT_FRAME	:
	case	_BUTTON_FRAME	:
	case	_CHECK_FRAME	:
	case	_RADIO_FRAME	:
	case	_WINDOW_FRAME	:
	case	_SWITCH_FRAME	:
	case	_TAB_FRAME	:
		return( 1 );
	default			:
		return( 0 );	
	}
}

/*	----------------------------------------------------------	*/
/*		p h p _ w i d g e t _ f o c u s 			*/
/*	----------------------------------------------------------	*/
/*	indicates true or false if the widget can take the focus	*/
/*	----------------------------------------------------------	*/
private	int	php_widget_focus( struct form_item * iptr )
{
	switch ((iptr->Contents.style & _FRAME_TYPE)) 
	{
	case	_FORM_FRAME	:
	case	_EDIT_FRAME	:
	case	_SELECT_FRAME	:
	case	_BUTTON_FRAME	:
	case	_CHECK_FRAME	:
	case	_RADIO_FRAME	:
	case	_SWITCH_FRAME	:
	case	_TAB_FRAME	:
		return( 1 );
	default			:
		return( 0 );	
	}
}

/*	----------------------------------------------------------	*/
/*		p h p _ m u l t i _ l a n g u a g e			*/
/*	----------------------------------------------------------	*/
/*	indicates if multiple language mode is required			*/
/*	----------------------------------------------------------	*/
private	int	php_multi_language( struct form_control * fptr )
{
	if ( fptr->formflags & _FORM_CONSTANTS )
		return( 0 );
	else if (!( fptr->formflags &_MULTILINGUAL )) 
		return( 0 );
	else	return( 1 );
}

/*	----------------------------------------------------------	*/
/*		p h p _ i n s t a n c e _ l a b e l s			*/
/*	----------------------------------------------------------	*/
private	void	php_instance_labels(FILE * h, struct form_control * fptr)
{
	char *	mptr;
	struct	form_item * iptr;
	char	prefix[16];
	char *	eptr;
	char *	nptr;
	int	nl;

	if (!( php_multi_language( fptr ) ))
		return;

	else
	{
		for  ( 	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )  
		{
			if (!( php_widget_label( iptr ) ))
				continue;
			else if (!( method_is_valid((eptr = abal_payload(iptr)))))
				continue;
			else if ( *eptr != _UNQUOTED_STRING ) 
				fprintf(h,"\tpublic $msg_%s = NULL;\n",iptr->Contents.name);
		}
		return;
	}
}

/*	----------------------------------------------------------	*/
/*		p h p _ u s e _ h i n t					*/
/*	----------------------------------------------------------	*/
private	char *	php_use_hint( struct form_item * iptr )
{
	char *	eptr;
	if (!( php_widget_focus( iptr ) ))
		return((char *) 0);
	else if (!( method_is_valid((eptr = abal_hint(iptr)))))
		return((char *) 0);
	else	return(eptr);
}

/*	----------------------------------------------------------	*/
/*		p h p _ i n s t a n c e _ h i n t s 			*/
/*	----------------------------------------------------------	*/
private	void	php_instance_hints(FILE * h, struct form_control * fptr)
{
	char *	mptr;
	struct	form_item * iptr;
	char	prefix[16];
	char *	eptr;
	char *	nptr;
	int	nl;

	if (!( php_multi_language( fptr ) ))
		return;

	else
	{
		for  ( 	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )  
		{
			if (!( eptr = php_use_hint( iptr ) ))
				continue;
			else if ( *eptr != _UNQUOTED_STRING ) 
				fprintf(h,"\tpublic $hint_%s = NULL;\n",iptr->Contents.name);
		}
		return;
	}
}

/*	----------------------------------------------------------	*/
/*		p h p _ l a b e l _ c o n s t r u c t i o n		*/
/*	----------------------------------------------------------	*/
private	void	php_label_construction(FILE * h, struct form_control * fptr)
{
	char *	mptr;
	struct	form_item * iptr;
	char	prefix[16];
	char *	eptr;
	char *	nptr;
	int	nl;

	if (!( php_multi_language( fptr ) ))
		return;

	else
	{
		for  ( 	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )  
		{
			/* ------------------------ */
			/* Widget Payload Constants */
			/* ------------------------ */
			if (!( php_widget_label( iptr ) ))
				continue;
			else if (!( method_is_valid((eptr = abal_payload(iptr)))))
				eptr = "";

			if ( *eptr != _UNQUOTED_STRING ) 
			{
				fprintf(h,"\t\t$this->msg_%s = array( ",iptr->Contents.name);

				for (nl=0; nl < MAXNATLANG; nl++ ) 
					php_national_payload( h, iptr, nl, nl );
				fprintf(h," );\n");
			}
		}
	}
	return;
}

/*	----------------------------------------------------------	*/
/*		p h p _ h i n t _ c o n s t r u c t i o n		*/
/*	----------------------------------------------------------	*/
private	void	php_hint_construction(FILE * h, struct form_control * fptr)
{
	char *	mptr;
	struct	form_item * iptr;
	char	prefix[16];
	char *	eptr;
	char *	nptr;
	int	nl;

	if (!( php_multi_language( fptr ) ))
		return;

	else
	{
		for  ( 	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )  
		{
			/* ------------------------ */
			/* Widget Payload Constants */
			/* ------------------------ */
			if (!( eptr = php_use_hint( iptr ) ))
				continue;

			else if ( *eptr != _UNQUOTED_STRING ) 
			{
				fprintf(h,"\t\t$this->hint_%s = array( ",iptr->Contents.name);

				for (nl=0; nl < MAXNATLANG; nl++ ) 
					php_national_hint( h, iptr, nl, nl );
				fprintf(h," );\n");
			}
		}
	}
	return;
}

/*	----------------------------------------------------------	*/
/*		p h p _ i n s t a n c e _ g l o b a l s			*/
/*	----------------------------------------------------------	*/
private	void	php_instance_globals(FILE * h, struct form_control * fptr)
{
	struct	form_item * iptr;
	/* ------------------------------ */
	/* instance all form global stuff */
	/* ------------------------------ */
	if ( SoapAgent ) 
	{
		fprintf(h,"\tpublic $soapClient = NULL;\n");
	}
	fprintf(h,"\tpublic $className=%c%s%c;\n",__QUOTE,fptr->identifier,__QUOTE);
	fprintf(h,"\tpublic $ArgV = NULL;\n");
	fprintf(h,"\tpublic $formKeyCode = -1;\n");
	fprintf(h,"\tpublic $reponseFile=NULL;\n");
	fprintf(h,"\tpublic $clientRedirect=0;\n");
	fprintf(h,"\tpublic $language=%u;\n",fptr->natlang);

}

/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
private	void	php_instance_widgets(FILE * h, struct form_control * fptr)
{
	struct	form_item * iptr;
	/* ------------------------------ */
	/* instance all widget components */
	/* ------------------------------ */
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		fprintf(h,"\tpublic $%s = NULL;\n",php_widget_name(iptr));
		}
	return;
}

/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
private	void	php_instance_members(FILE * h, struct form_control * fptr)
{
	struct	forms_data_member * mptr;
	if (!( SoapAgent )) {
		for (	mptr=fptr->rootmember;
			mptr != (struct forms_data_member *) 0;
			mptr = mptr->next ) {
			fprintf (h,"\tpublic $%s=NULL;\n",mptr->name);
			}
		}
	return;
}


/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
private	int	is_token_legal(int c)
{
	if (( c >= 'a' ) && ( c <= 'z' ))
		return(1);
	else if (( c >= 'A' ) && ( c <= 'Z' ))
		return(1);
	else if (( c >= '0' ) && ( c <= '1' ))
		return(1);
	else if ( c == '_' )
		return(1);
	else	return(0);
}

/*	----------------------------------------------------------	*/
/*		p h p _ d e t e c t _ f o r m s  m e t h o d		*/
/*	----------------------------------------------------------	*/
private	struct forms_method * php_detect_forms_method(struct form_control * fptr,char * nptr)
{
	struct	forms_method * mptr;
	for (	mptr=fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) 
	{
		if (!( mptr->name ))
			continue;
		else if (!( strcasecmp( mptr->name, nptr ) ))
			break;
	}
	return( mptr );
}

/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
private	void	php_instance_methods(FILE * h, struct form_control * fptr)
{
	int	status;
	int	paras=0;
	struct	forms_method * mptr;
	char	* sptr;
	int	c;
	char 	* xptr;	
	char 	* nptr;
	if (!( SoapAgent )) {
		for (	mptr=fptr->rootmethod;
			mptr != (struct forms_method *) 0;
			mptr = mptr->next ) {
			/* filter out special methods */
			if ((!( strcasecmp( mptr->name,  "NoPdoMysql" )))
			||  (!( strcasecmp( mptr->name,  "StdMysql"   )))
			||  (!( strcasecmp( mptr->name,  "PdoMysql"   ))))
				continue;
			fprintf(h,"\tpublic function %s($psn=0",mptr->name);
			if ((sptr=mptr->signature) != (char *) 0) {
				xptr = sptr = allocate_string( sptr );
				paras=0;
				while ( *sptr ) {
					while ( *sptr == ' ' ) sptr++;
					nptr = sptr;
					while ( is_token_legal ( *sptr ) )
						sptr++;
					c = *sptr;
					*sptr = 0;
					paras++;
					fprintf(h,",");
					fprintf(h,"$%s",nptr);
					*sptr = c;
					while ( *sptr ) {
						if ( *sptr == ',' )
							break;
						else	sptr++;
						}
					/* its a comma so consume */
					/* ---------------------- */
					if ( *sptr ) sptr++; 
					}
				liberate( xptr );
				}
			fprintf(h,")\n\t{\n");
			
			if (SoapAgent) {
				status = abal_php_soap_method( h,(struct form_item *) 0, fptr->identifier, mptr->name );
				}
			else	{
				status = abal_php_method_body(h,
					mptr->text,
					mptr->name,1);
				}
			
			
			php_close_method(h);
			}
		}
	return;
}


struct	php_required {
	struct	php_required * 	next;
	char *			name;
	};

struct	php_required *	PhpStyles=(struct php_required *) 0;


/*	----------------------------------------------------------	*/
/*		p h p _ i n s t a n c e _ s t y l e 			*/
/*	----------------------------------------------------------	*/
/*	instances all style objects post global member instancing	*/
/*	----------------------------------------------------------	*/
private	void	php_instance_style( FILE * h )
{
	struct	php_required * sptr;
	/* ------------------------------------ */
	/* instance all explicite style objects */
	/* ------------------------------------ */
	for (	sptr=PhpStyles;
		sptr != (struct php_required *) 0;
		sptr = sptr->next )
		fprintf(h,"\tpublic $__%s = NULL;\n",sptr->name);
	return;
}

/*	----------------------------------------------------------	*/
/*		p h p _ s t y l e _ c o n s t r u c t i o n		*/
/*	----------------------------------------------------------	*/
/*	construction of all style objects 				*/
/*	----------------------------------------------------------	*/
private	void	php_style_construction( FILE * h )
{
	struct	php_required * sptr;
	/* ------------------------------------ */
	/* instance all explicite style objects */
	/* ------------------------------------ */
	for (	sptr=PhpStyles;
		sptr != (struct php_required *) 0;
		sptr = sptr->next )
		fprintf(h,"\t\t$this->__%s = new %s;\n",
			sptr->name,sptr->name);
	return;
}

/*	----------------------------------------------------------	*/
/*		p h p _ s t y l e _ i n v o c a t i o n    		*/
/*	----------------------------------------------------------	*/
/*	invocation of explicite style production methods		*/
/*	----------------------------------------------------------	*/
private	void	php_style_invocation( FILE * h )
{
	struct	php_required * sptr;
	/* ------------------------------------ */
	/* instance all explicite style objects */
	/* ------------------------------------ */
	for (	sptr=PhpStyles;
		sptr != (struct php_required *) 0;
		sptr = sptr->next )
		fprintf(h,"\t\t$this->__%s->OnStyle($psn.%c_%s%c);\n",sptr->name,0x0022,sptr->name,0x0022);
	return;
}

/*	----------------------------------------------------------	*/
/*		l i b e r a t e _ p h p _ s t y l e s    		*/
/*	----------------------------------------------------------	*/
/*	liberate the list of style classes  for a php production	*/
/*	----------------------------------------------------------	*/
public	int	liberate_php_styles()
{
	struct	php_required * sptr;
	while ((sptr = PhpStyles) != (struct php_required *) 0) {
		PhpStyles = sptr->next;
		if ( sptr->name )
			liberate( sptr->name );
		liberate( sptr );
		}
	return(0);
}

/*	----------------------------------------------------------	*/
/*	       i n i t i a l i s e _ p h p _ s t y l e s    		*/
/*	----------------------------------------------------------	*/
/*	initialise the list of style classes  prior to processing	*/
/*	----------------------------------------------------------	*/
private	int	initialise_php_styles()
{
	PhpStyles = (struct php_required *) 0;
	return(0);
}

/*	----------------------------------------------------------	*/
/*			a d d _ p h p _ s t y l e    			*/
/*	----------------------------------------------------------	*/
/*	attempts to add a style class   to the list of style    	*/
/*	class and returns true if this is a new list element. 		*/
/*	returns false if the file has already been produced.		*/
/*	----------------------------------------------------------	*/
private	int	php_widget_style( FILE * h, char* nomfic );

private	int	add_php_style( FILE * h, char* nomfic )
{
	struct	php_required * sptr;
	for (	sptr=PhpStyles;
		sptr != (struct php_required *) 0;
		sptr = sptr->next ) {
		if (!( strcmp( sptr->name, nomfic ) ))
			return( 0 );
		}
	if (!( sptr = allocate(sizeof( struct php_required ) ) ))
		return(1);
	else if (!( sptr->name = allocate_string( nomfic ) )) {
		liberate( sptr );
		return(1);
		}
	else	{
 		sptr->next = PhpStyles;
		PhpStyles = sptr;
		php_widget_style( h, nomfic );
		return(1);
		}
}

private	int	add_php_styles( FILE * h, char * sptr )
{
	int	item=0;
	char *	vptr;
	while ((vptr = selection_item(item++,sptr )) != (char *) 0) 
	{
		add_php_style( h, vptr );
	}
	return(item);
}

private	int	add_php_form_styles( FILE * h, char * sptr )
{
	char	stylename[1024];
	int	items=0;
	sprintf(stylename,"%sframe",sptr);
	items += add_php_style(h, stylename );
	sprintf(stylename,"%sheader",sptr);
	items += add_php_style(h, stylename );
	sprintf(stylename,"%scell",sptr);
	items += add_php_style(h, stylename );
}

private	int	add_php_scroll_styles( FILE * h, char * sptr )
{
	char	stylename[1024];
	int	items=0;
	sprintf(stylename,"%sframe",sptr);
	items += add_php_style(h, stylename );
	sprintf(stylename,"%sup",sptr);
	items += add_php_style(h, stylename );
	sprintf(stylename,"%sbar",sptr);
	items += add_php_style(h, stylename );
	sprintf(stylename,"%sdown",sptr);
	items += add_php_style(h, stylename );
}

private	int	add_php_select_styles( FILE * h, char * sptr )
{
	char	stylename[1024];
	int	items=0;
	sprintf(stylename,"%sframe",sptr);
	items += add_php_style(h, stylename );
	sprintf(stylename,"%strue",sptr);
	items += add_php_style(h, stylename );
	sprintf(stylename,"%sfalse",sptr);
	items += add_php_style(h, stylename );
}

private	int	add_php_aliases( FILE * h, char * sptr )
{
	int	item=0;
	char *	vptr;
	while ((vptr = selection_item(item++,sptr )) != (char *) 0) 
	{
		add_php_style( h, vptr );
	}
	return(item);
}

struct	php_required *	PhpRequired=(struct php_required *) 0;

/*	----------------------------------------------------------	*/
/*		l i b e r a t e _ p h p _ r e q u i r e s		*/
/*	----------------------------------------------------------	*/
/*	liberate the list of required files for a php production	*/
/*	----------------------------------------------------------	*/
public	int	liberate_php_requires()
{
	struct	php_required * sptr;
	while ((sptr = PhpRequired) != (struct php_required *) 0) {
		PhpRequired = sptr->next;
		if ( sptr->name )
			liberate( sptr->name );
		liberate( sptr );
		}
	return(0);
}

/*	----------------------------------------------------------	*/
/*	       i n i t i a l i s e _ p h p _ r e q u i r e s		*/
/*	----------------------------------------------------------	*/
/*	initialise the list of required files prior to processing	*/
/*	----------------------------------------------------------	*/
private	int	initialise_php_requires()
{
	PhpRequired = (struct php_required *) 0;
	return(0);
}

/*	----------------------------------------------------------	*/
/*			a d d _ p h p _ r e q u i r e			*/
/*	----------------------------------------------------------	*/
/*	attempts to add a required file to the list of required 	*/
/*	files and returns true if this is a new list element. 		*/
/*	returns false if the file has already been required.		*/
/*	----------------------------------------------------------	*/
private	int	add_php_require( FILE * h, char* nomfic )
{
	struct	php_required * sptr;
	for (	sptr=PhpRequired;
		sptr != (struct php_required *) 0;
		sptr = sptr->next ) {
		if (!( strcmp( sptr->name, nomfic ) ))
			return( 0 );
		}
	if (!( sptr = allocate(sizeof( struct php_required ) ) ))
		return(1);
	else if (!( sptr->name = allocate_string( nomfic ) )) {
		liberate( sptr );
		return(1);
		}
	else	{
 		sptr->next = PhpRequired;
		PhpRequired = sptr;
		php_require( h, nomfic );
		return(1);
		}
}

/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
public	void	php_component_requires(FILE * h, struct form_control * fptr)
{
	char * sptr;
	char * fnptr;
	struct	form_item * iptr;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if ( iptr->Contents.style != _DATA_FRAME )
			continue;
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME) {
			if (( iptr->Contents.align & 0x00FF) == _VGROUP_FRAME) 
				continue;
			/* maybe its a file :) */
			/* ------------------- */
			if (( sptr = resolve_widget_file_class( iptr )) != (char *) 0) {
				if (!( fnptr = allocate_string( sptr )))
					continue;
				else if (!( fnptr = enforce_extension( fnptr, ".inc" )))
					continue;
				else if ( add_php_require(h,fnptr) != 0 ) 
					php_generate_database_class(fnptr, sptr, fptr, iptr );
				else	liberate( fnptr );
				}
			continue;
			}
		else if ( iptr->Contents.datatype == _WIDGET_IFRAME )
			continue;
		else if ( iptr->Contents.datatype == _WIDGET_AUDIO )
			continue;
		else if ( iptr->Contents.datatype == _WIDGET_VIDEO )
			continue;
		else if ( iptr->Contents.datatype == _WIDGET_AJAX  )
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!( fnptr = allocate_string( fnptr ) ))
			continue;
		else if (!( fnptr = enforce_extension( fnptr, ".inc" )))
			continue;
		else	{
			add_php_require(h,fnptr);
			liberate( fnptr);
			}
		}
	return;
}

/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
public	void	php_file_requires(FILE * h, struct form_control * fptr)
{
	char * sptr;
	char * fnptr;
	struct	form_control * ffptr;
	struct	form_item * iptr;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) 
	{
		if ( iptr->Contents.style != _DATA_FRAME )
			continue;
		else if ( is_file_Widget( iptr ) )
		{
			if (!( sptr = resolve_widget_file_class( iptr )))
				continue;
			else if (!( fnptr = allocate_string( sptr )))
				continue;
			else if (!( fnptr = enforce_extension( fnptr, ".inc" )))
				continue;
			else if ( add_php_require(h,fnptr) != 0 )
				php_generate_database_class(fnptr, sptr, fptr, iptr );
			else	liberate( fnptr );
		}
		else if ( iptr->Contents.datatype == _WIDGET_IFRAME )
			continue;
		else if ( iptr->Contents.datatype == _WIDGET_AUDIO )
			continue;
		else if ( iptr->Contents.datatype == _WIDGET_VIDEO )
			continue;
		else if ( iptr->Contents.datatype == _WIDGET_AJAX )
			continue;
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	php_file_requires( h, ffptr );
	}
	return;
}

/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
private	int	abal_php_soap_method( FILE * h, struct form_item * iptr, char * nptr, char * mptr )
{
	if ( 1 > 1 ) {
		fprintf(h,"\t\tif ( $this->soapClient )\n\t\t{\n");
		fprintf(h,"\t\t\tif (!( $psn ))\n\t\t\t{\n");
		fprintf(h,"\t\t\t$this->soapClient->invokeMethod(%c%s_%s%c,%c %c);\n\t\t\t}\n",__QUOTE,nptr,mptr,__QUOTE,__QUOTE,__QUOTE);
		fprintf(h,"\t\t\telse\n\t\t\t{\n");
		fprintf(h,"\t\t\t$this->soapClient->invokeMethod($psn.%c_%s_%s%c,%c %c);\n\t\t\t}\n",__QUOTE,nptr,mptr,__QUOTE,__QUOTE,__QUOTE);
		fprintf(h,"\t\t}\n");
		}
	else	{
		fprintf(h,"\t\tif ( $this->soapClient )\n\t\t{\n");
		fprintf(h,"$this->OnInvoke($psn,$psn.%c_%s_%s%c);\n",__QUOTE,nptr,mptr,__QUOTE);
		fprintf(h,"\t\t}\n");
		}
	return(0);
}

/*	-------------------------------------------------------------------	*/
/*	    	p h p _ c r e a t e _ m e t h o d s ( h, fptr )			*/
/*	-------------------------------------------------------------------	*/
/*	generation of explicite Create methods for the widgets of the form.	*/
/*	-------------------------------------------------------------------	*/
private	void	php_create_methods(FILE * h, struct form_control * fptr)
{
	int			status=0;
	struct	form_item * 	iptr;

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		else if (!( method_is_valid( iptr->Contents.events->on_create ) ))
			continue;
		else	{
			fprintf(h,"\tfunction %sCreate($psn)\n",php_widget_name(iptr));
			fprintf(h,"\t{\n");
			if (SoapAgent) {
				status = abal_php_soap_method( h, iptr, php_widget_name(iptr), "Create" );
				}
			else	{
				status = abal_php_method_body(h,
					iptr->Contents.events->on_create,
					php_use_widget_name(iptr),1);
				}
			fprintf(h,"\t}\n");
			}
		}
	return;
}


/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
private char* php_widget_class( int style )
{
	if ( style != _FORM_FRAME )
		return( get_widget_class( style ) );
	else	return( "table" );
}

/*	-------------------------------------------------------------------	*/
/*		     p h p _ t a b l e _ p a r a m e t e r s 			*/
/*	-------------------------------------------------------------------	*/
/*	generation of secondary construction parameter valuse for the table	*/
/*	-------------------------------------------------------------------	*/
private	void	php_table_parameters(FILE * h, struct form_item * iptr)
{
	char	value[32];
	char *	buffer=(char *) 0;
	int	fh;
	int	fw;
	int 	linelength, nblines,i,fields,posit;
	int	fieldwidth[_MAX_FORM_FIELDS];

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return;

	calculate_edit_size( &iptr->Contents );
	calculate_form_lines( iptr, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
		return;
	else if (!( buffer = allocate( (fields * 16) )))
		return;

	fw = guifontsize(iptr->Contents.font);
	fh = (fw >> 8); fw &= 0x00FF;	

	/* titles */
	/* ------ */
	php_current_payload(h, iptr, 1 );

	/* format */
	/* ------ */
	fprintf(h,",%c%s%c",__QUOTE,iptr->Contents.format,__QUOTE);

	/* sizes */
	/* ----- */
	for (i=0; i < fields; i++ ) {
		if ( i ) strcat(buffer,",");
		sprintf(value,"%u",fieldwidth[i]);
		strcat(buffer,value);
		}
	fprintf(h,",%c%s%c",__QUOTE,buffer,__QUOTE);
	liberate( buffer );

	/* others stuff */
	/* ------------ */
	fprintf(h,",%u,%u,%u,%u",fields,nblines,fw,fh);
	return;
}

/*	----------------------------------------------------------	*/
/*		a b a l _ p h p _ p a y l o a d				*/
/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
public	void	php_national_payload( FILE * h, struct form_item * iptr,int nl, int comma )
{
	char *	sptr;
	char *	mptr;
	int	c;
	if ( comma )
		fprintf(h,",");

	if (!( sptr = iptr->Contents.messages[nl] ))
		fprintf(h,"%c%c",__QUOTE,__QUOTE);
	else
	{
		if ( *sptr != _UNQUOTED_STRING )
		{
			fprintf(h,"%c",__QUOTE );
			while ((c = *(sptr++)) != 0 )
			{
				if ( c == '&' )
					fprintf(h,"~",c);
				else if (!( mptr = html_accent( c ) ))
						fprintf(h,"%c",c);
				else	fprintf(h,"%s",mptr);			
			}
			fprintf(h,"%c",__QUOTE );
		}
		else	abal_php_macro_conversion(h,(sptr+1), php_use_widget_name(iptr) );
	}
}

/*	----------------------------------------------------------	*/
/*		a b a l _ n a t i o n a l _ h i n t			*/
/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
public	void	php_national_hint( FILE * h, struct form_item * iptr,int nl, int comma )
{
	char *	sptr;
	char *	mptr;
	int	c;
	if ( comma )
		fprintf(h,",");

	if (!( sptr = iptr->Contents.hmessages[nl] ))
		fprintf(h,"%c%c",__QUOTE,__QUOTE);
	else
	{
		if ( *sptr != _UNQUOTED_STRING )
		{
			fprintf(h,"%c",__QUOTE );
			while ((c = *(sptr++)) != 0 )
			{
				if ( c == '&' )
					fprintf(h,"~",c);
				else if (!( mptr = html_accent( c ) ))
						fprintf(h,"%c",c);
				else	fprintf(h,"%s",mptr);			
			}
			fprintf(h,"%c",__QUOTE );
		}
		else	abal_php_macro_conversion(h,(sptr+1), php_use_widget_name(iptr) );
	}
}

/*	----------------------------------------------------------	*/
/*		p h p _ c u r r e n t _ p a y l o a d			*/
/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
public	void	php_current_payload( FILE * h, struct form_item * iptr, int comma )
{
	char *	sptr;
	char *	mptr;
	int	c;

	if ( comma )
		fprintf(h,",");

	if ( php_multi_language( iptr->parent ) )
	{
		if (!( sptr = abal_payload( iptr ) ))
			fprintf(h,"%c%c",__QUOTE,__QUOTE);
		else if ( *sptr != _UNQUOTED_STRING )
			fprintf(h,"$this->msg_%s[$this->language]",iptr->Contents.name);
		else	abal_php_macro_conversion(h,(sptr+1), php_use_widget_name(iptr) );
	}
	else if (!( sptr = abal_payload( iptr ) ))
		fprintf(h,"%c%c",__QUOTE,__QUOTE);
	else
	{
		if ( *sptr != _UNQUOTED_STRING )
		{
			fprintf(h,"%c",__QUOTE );
			while ((c = *(sptr++)) != 0 )
			{
				if ( c == '&' )
					fprintf(h,"~",c);
				else if (!( mptr = html_accent( c ) ))
						fprintf(h,"%c",c);
				else	fprintf(h,"%s",mptr);			
			}
			fprintf(h,"%c",__QUOTE );
		}
		else	abal_php_macro_conversion(h,(sptr+1), php_use_widget_name(iptr) );
	}
}

/*	----------------------------------------------------------	*/
/*		p h p _ c u r r e n t _ p a y l o a d			*/
/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
public	void	php_object_payload( FILE * h, struct form_item * iptr, char * nptr )
{
	char *	sptr;
	char *	mptr;
	int	c;

	if ( php_multi_language( iptr->parent ) )
		fprintf(h,"$i%s->msg_%s[$i%s->language]",nptr,iptr->Contents.name,nptr);

	else if (!( sptr = abal_payload( iptr ) ))
		fprintf(h,"%c%c",__QUOTE,__QUOTE);
	else
	{
		if ( *sptr != _UNQUOTED_STRING )
		{
			fprintf(h,"%c",__QUOTE );
			while ((c = *(sptr++)) != 0 )
			{
				if ( c == '&' )
					fprintf(h,"~",c);
				else if (!( mptr = html_accent( c ) ))
						fprintf(h,"%c",c);
				else	fprintf(h,"%s",mptr);			
			}
			fprintf(h,"%c",__QUOTE );
		}
		else	abal_php_macro_conversion(h,(sptr+1), php_use_widget_name(iptr) );
	}
}

private	void	php_widget_factor( FILE * h, int v, int w, int n )
{
	float fv=(float) v;
	float fw=(float) w;
	float fx=((fv * 100) / w);
	if ( n ) fprintf(h,",");
	fprintf(h,"\"%f%c\"",fx,'%');
	return;
}

private	void	php_forms_widget_position( FILE * h, struct form_control * fptr, struct form_item * wptr, struct form_item * iptr, int fh )
{
	if (!( fptr->resizeauto ))
	{
		fprintf(h,"%u,%u",iptr->Contents.x - wptr->Contents.x,iptr->Contents.y - wptr->Contents.y );	
	}
	else
	{
		php_widget_factor(h, iptr->Contents.x - wptr->Contents.x, wptr->Contents.w,0 );
		php_widget_factor(h, iptr->Contents.y - wptr->Contents.y, wptr->Contents.h,1 );
	}
}

private	void	php_widget_position( FILE * h, struct form_control * fptr, struct form_item * wptr, struct form_item * iptr, int fh )
{
	if (!( fptr->resizeauto ))
	{
		fprintf(h,"%u,%u,%u",
			iptr->Contents.x - wptr->Contents.x,
			iptr->Contents.y - wptr->Contents.y,
			iptr->Contents.w  );

		if (iptr->Contents.style == _SELECT_FRAME )
			fprintf(h,",%u",fh);
		else	fprintf(h,",%u",iptr->Contents.h);
	}
	else
	{
		php_widget_factor(h, iptr->Contents.x - wptr->Contents.x, wptr->Contents.w,0 );
		php_widget_factor(h, iptr->Contents.y - wptr->Contents.y, wptr->Contents.h,1 );
		php_widget_factor(h, iptr->Contents.w, wptr->Contents.w,1 );
		php_widget_factor(h, (iptr->Contents.style == _SELECT_FRAME  ? fh : iptr->Contents.h), wptr->Contents.h,1 );
	}
}

/*	-------------------------------------------------------------------	*/
/*	       p h p _ c on s t r u c t o r _ m e t h o d ( h, fptr )		*/
/*	-------------------------------------------------------------------	*/
/*	generation of implicite construction of froms widgets			*/
/*	-------------------------------------------------------------------	*/
private	void	php_constructor_method(FILE * h, struct form_control * fptr)
{
	char *	databasename="mydatabase";
	char *	target=(char *) 0;
	int	options=0;
	int	txfh;
	int	fh;
	int	fw;
	int			colcount=0;
	int			rowcount=0;
	int			haswindow=0;
	char *			sptr;
	char *			vptr;
	char *			fnptr=(char *) 0;
	char *			eptr=(char *) 0;
	struct	form_control * ffptr=(struct form_control *) 0;
	struct	form_item * iptr=(struct form_item *) 0;
	struct	form_item * wptr=(struct form_item *) 0;
	struct	form_item * wwptr=(struct form_item *) 0;
	struct	forms_method * mptr;
	struct	standard_zone	awz;

	/* -------------------------------------- */
	/* detect window widget if one is present */
	/* -------------------------------------- */
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) 
	{
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ((iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME) 
		{
			wptr = iptr;
			break;
		}
	}


	if ( fptr->isdynamic ) 
	{
		if ( fptr->pages ) 
		{
			fprintf(h,"\tpublic function %s($px,$py,$pw,$ph,$pn,$pcl,$psn='')\n\t{\n",fptr->identifier);
			if ((!( is_valid_string( fptr->extends ) ))
			||  (!( ffptr = locate_form_control( fptr->extends ))))
				fprintf(h,"\t\t$this->visual_paged_form($px,$py,$pw,$ph,$pn);\n");

			else if ( ffptr->isdynamic )
			{
				if ( ffptr->pages ) 
					fprintf(h,"\t\t%s::%s($px,$py,$pw,$ph,$pn,$pcl);\n",fptr->extends,fptr->extends);
				else	fprintf(h,"\t\t%s::%s($px,$py,$pw,$ph,$pcl);\n",fptr->extends,fptr->extends);
			}
			else	fprintf(h,"\t\t%s::%s($pcl);\n",fptr->extends,fptr->extends);
		}
		else	
		{
			fprintf(h,"\tpublic function %s($px,$py,$pw,$ph,$pcl,$psn='')\n\t{\n",fptr->identifier);
			if ((!( is_valid_string( fptr->extends )))
			||  (!( ffptr = locate_form_control( fptr->extends ))))
				fprintf(h,"\t\t$this->visual_form($px,$py,$pw,$ph);\n");
			else if ( ffptr->isdynamic )
			{
				if ( ffptr->pages ) 
					fprintf(h,"\t\ts::%s($px,$py,$pw,$ph,%u,$pcl);\n",fptr->extends,fptr->extends,ffptr->pages);
				else	fprintf(h,"\t\t%s::%s($px,$py,$pw,$ph,$pcl);\n",fptr->extends,fptr->extends);
			}
			else	fprintf(h,"\t\t%s::%s($pcl);\n",fptr->extends,fptr->extends);
		}
	}
	else	
	{
		if ( fptr->pages ) 
		{
			fprintf(h,"\tpublic function %s($pcl,$psn='')\n\t{\n",fptr->identifier);
			if ((!( is_valid_string( fptr->extends ) ))
			||  (!( ffptr = locate_form_control( fptr->extends ))))
				fprintf(h,"\t\t$this->visual_paged_form(0,0,0,0,$this->pagecount);\n");
			else if ( ffptr->isdynamic )
			{
				if ( ffptr->pages ) 
					fprintf(h,"\t\t%s::%s(0,0,0,0,%u,$pcl);\n",fptr->extends,fptr->extends,ffptr->pages);
				else	fprintf(h,"\t\t%s::%s(0,0,0,0,$pcl);\n",fptr->extends,fptr->extends);
			}
			else	fprintf(h,"\t\t%s::%s($pcl);\n",fptr->extends,fptr->extends);
		}
		else	
		{
			fprintf(h,"\tpublic function %s($pcl,$psn='')\n\t{\n",fptr->identifier);
			if ((!( is_valid_string( fptr->extends ) ))
			||  (!( ffptr = locate_form_control( fptr->extends ))))
				fprintf(h,"\t\t$this->visual_form(0,0,0,0);\n");
			else if ( ffptr->isdynamic )
			{
				if ( ffptr->pages ) 
					fprintf(h,"\t\t%s::%s(0,0,0,0,%u,$pcl);\n",fptr->extends,fptr->extends,ffptr->pages);
				else	fprintf(h,"\t\t%s::%s(0,0,0,0,$pcl);\n",fptr->extends,fptr->extends);
			}
			else	fprintf(h,"\t\t%s::%s($pcl);\n",fptr->extends,fptr->extends);
		}
	}

	fprintf(h,"\t\t$psn=\"\";\n");
	fprintf(h,"\t\t$this->ArgV = explode(%c,%c,$pcl);",__QUOTE,__QUOTE);
	linefeed(h);

	if ( php_multi_language( fptr ) )
	{
		fprintf(h,"\t\tif ( isset( $_REQUEST['method'] ) ) {\n");
		fprintf(h,"\t\tif      ( $_REQUEST['method'] == 'nl0' ) { $this->language = '0'; setcookie('nl','0'); }\n");
		fprintf(h,"\t\telse if ( $_REQUEST['method'] == 'nl1' ) { $this->language = '1'; setcookie('nl','1'); }\n");
		fprintf(h,"\t\telse if ( isset($_COOKIE['nl'] ) )\n     { $this->language = $_COOKIE['nl']; }\n");
		fprintf(h,"\t\telse { $this->language = '1'; setcookie('nl','1'); }\n");
		fprintf(h,"\t\t} else if ( isset($_COOKIE['nl'] ) )\n     { $this->language = $_COOKIE['nl']; }\n");
		fprintf(h,"\t\telse { $this->language = '1'; setcookie('nl','1'); }\n");
	}
	else	fprintf(h,"\t\t$this->language = '1';\n");

	if (!( fptr->resizeauto ))
	{	fprintf(h,"\t\t$this->units = %cpx%c;\n",0x0022,0x0022);		}
	else
	{	fprintf(h,"\t\t$this->units = %c%c%c;\n",0x0022,0x0025,0x0022);	}

	/* ----------------------------------------- */
	/* allow constant initialisation if required */
	/* ----------------------------------------- */
	php_label_construction( h, fptr );
	php_hint_construction( h, fptr );
	php_style_construction( h );

	/* ------------------------------ */
	/* instance all widget components */
	/* ------------------------------ */
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) 
	{
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		fw = guifontsize(iptr->Contents.font);
		fh = (fw >> 8); fw &= 0x00FF;

		txfh = ((fh * 5) / 6);

		/* ---------------------- */
		/* Implicite Construction */
		/* ---------------------- */
		if ( iptr->Contents.style == _DATA_FRAME ) 
		{
			if (( iptr->Contents.align & 0x00FF) == _VGROUP_FRAME) 
			{
				if (!( fnptr = abal_payload(iptr) )) 
					continue;
				else
				{
					fprintf(h,"\t\t$this->%s = new %s;\n",
						php_widget_name(iptr),fnptr);
					fprintf(h,"\t\t$this->%s->parent = $this;\n",php_widget_name(iptr));
					if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
					{
						fprintf(h,"\t\t$this->%s->ishidden = 1;\n",php_widget_name(iptr) );
					}
					continue;
				}
			}
			else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME) 
			{
				/* ------------------- */
				/* maybe its a file :) */
				/* ------------------- */
				if (!( sptr = resolve_widget_file_class( iptr )))
					continue;
				else if ( SoapAgent )
					continue;
				else if (!( databasename = application_databasename() ))
					databasename = "mydatabase";
				fprintf(h,"\t\t$this->%s = new %s(%c%s%c,",
					php_widget_name(iptr),sptr,
					__QUOTE,databasename,__QUOTE );
				if (!( sptr = abal_payload( iptr ) ))
					fprintf(h,"%cfilename%c",__QUOTE,__QUOTE);
				else if ( *sptr != '$' )
					fprintf(h,"%c%s%c",	__QUOTE,abal_payload(iptr),__QUOTE);
				else	abal_php_macro_conversion(h,(sptr+1), php_use_widget_name(iptr) );
				fprintf(h,");\n");
				fprintf(h,"\t\t$this->%s->OnStartSession();\n",php_widget_name(iptr));
				/* Check for PDO */
				if (((mptr = php_detect_forms_method( fptr, "NoPdoMySql" )) != (struct forms_method *) 0)
				||  ((mptr = php_detect_forms_method( fptr, "StdMySql" )) != (struct forms_method *) 0))
					fprintf(h,"\t\t$this->%s->OnUsePDO(0);\n",php_widget_name(iptr));
				else if ((mptr = php_detect_forms_method( fptr, "PdoMySql" )) != (struct forms_method *) 0)
					fprintf(h,"\t\t$this->%s->OnUsePDO(1);\n",php_widget_name(iptr));
				else if (!( use_php_pdo()))
					fprintf(h,"\t\t$this->%s->OnUsePDO(0);\n",php_widget_name(iptr));
				else	fprintf(h,"\t\t$this->%s->OnUsePDO(1);\n",php_widget_name(iptr));

				continue;
			}
			/* --------------------------- */
			/* it must be a complex widget */
			/* --------------------------- */
			else if (( iptr->Contents.datatype != _WIDGET_IFRAME )
			     &&  ( iptr->Contents.datatype != _WIDGET_AJAX   )
			     &&  ( iptr->Contents.datatype != _WIDGET_VIDEO  )
			     &&  ( iptr->Contents.datatype != _WIDGET_AUDIO  ))
			{
				/* --------------------------- */
				/* the old way without iframes */
				/* --------------------------- */
				if (!( fnptr = abal_payload(iptr) )) 
					continue;
				fprintf(h,"\t\t$this->%s = new %s(",
				php_widget_name(iptr),fnptr);

				if (!(ffptr = locate_form_control( fnptr ) ))
					fprintf(h,"%c%c);\n",__QUOTE,__QUOTE);
				else if (!( ffptr->isdynamic )) 
				{ 
					fprintf(h,"%c%c);\n",__QUOTE,__QUOTE);
					if ( fptr->pages ) 
					{
						fprintf(h,"\t\t$this->%s->pagecount = %u;\n",
							php_widget_name(iptr),
							ffptr->pages);
					}
				}
				else if ( wptr ) 
				{
					fprintf(h,"%u,%u,%u",
						iptr->Contents.x - wptr->Contents.x,
						iptr->Contents.y - wptr->Contents.y,
						iptr->Contents.w  );
					if (iptr->Contents.style == _SELECT_FRAME )
						fprintf(h,",%u",fh);
					else	fprintf(h,",%u",iptr->Contents.h);
					if ( ffptr->pages ) 
					{
						fprintf(h,",%u",ffptr->pages);
					}
					fprintf(h,",%c%c);\n",__QUOTE,__QUOTE);
				}
				else	
				{
					fprintf(h,"%u,%u,%u",
						iptr->Contents.x,
						iptr->Contents.y,
						iptr->Contents.w  );

					if (iptr->Contents.style == _SELECT_FRAME )
						fprintf(h,",%u",fh);
					else	fprintf(h,",%u",iptr->Contents.h);

					if ( ffptr->pages ) 
					{
						fprintf(h,",%u",ffptr->pages);
					}
					fprintf(h,",%c%c);\n",__QUOTE,__QUOTE);
				}
				fprintf(h,"\t\t$this->%s->parent = $this;\n",php_widget_name(iptr));
				if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
				{
					fprintf(h,"\t\t$this->%s->ishidden = 1;\n",php_widget_name(iptr) );
				}
				/* ---------------------------------- */
				/* visual frames may mask full screen */
				/* ---------------------------------- */
				if ( iptr->Contents.align & _A_LINE  )
				{
					fprintf(h,"\t\t$this->%s->shadow = 1;\n",php_widget_name(iptr));
				}
				continue;
			}
			else
			{
				/* ---------------------------------- */
				/* the new way with iframe components */
				/* ---------------------------------- */
				if (!( fnptr = abal_payload(iptr) )) 
					continue;

				else 	fprintf(h,"\t\t$this->%s = new visual_vframe(",php_widget_name(iptr));

				/* --------------------------- */
				/* Widget Provides Position XY */
				/* do we have an active window */
				/* --------------------------- */
				if ( wptr ) 
				{
					php_forms_widget_position(h,fptr,wptr, iptr, fh );
				}
				else	
				{	
					fprintf(h,"%u,%u",iptr->Contents.x,iptr->Contents.y );
				}

				if (!(ffptr = locate_form_control( fnptr ) ))
				{
					fprintf(h,",0,0,%c%c,0);\n",__QUOTE,__QUOTE);
					continue;
				}
				else if (!( wwptr = locate_forms_window( ffptr )))
				{
					haswindow=0;
					wwptr = iptr;
				}
				else	haswindow= 1;

				fprintf(h,",%u,%u",wwptr->Contents.w,wwptr->Contents.h);

				if (!( target = allocate_string( fnptr ) ))
				{
					fprintf(h,",%c%c,0);\n",__QUOTE,__QUOTE);
					continue;
				}
				else if ( *target == _UNQUOTED_STRING )
				{
					php_current_payload(h,iptr,1);
					liberate( target );	
				}
				else if (!( target = enforce_extension( target,PHP_EXTENSION ) ))
				{
					php_current_payload(h,iptr,1);
				}
				else
				{
					fprintf(h,",%c%s%c",__QUOTE,target,__QUOTE);
					liberate( target );		
				}
				fprintf(h,",%u);\n",haswindow);
				fprintf(h,"\t\t$this->%s->parent = $this;\n",php_widget_name(iptr));
				if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
				{
					fprintf(h,"\t\t$this->%s->ishidden = 1;\n",php_widget_name(iptr) );
				}
				/* ---------------------------------- */
				/* visual frames may mask full screen */
				/* ---------------------------------- */
				if ( iptr->Contents.align & _A_LINE  )
				{
					fprintf(h,"\t\t$this->%s->shadow = 1;\n",php_widget_name(iptr));
				}
				continue;
			}
		}
		else	
		{
			switch ((iptr->Contents.style & _FRAME_TYPE)) 
			{
			case	_EDIT_FRAME	:
				calculate_edit_lines(iptr,&colcount,&rowcount);
				if ( rowcount > 1 )
				{
					fprintf(h,"\t\t$this->%s = new visual_textarea(",
						php_widget_name(iptr));
				}
				else
				{
					fprintf(h,"\t\t$this->%s = new visual_%s(",
						php_widget_name(iptr),
						php_widget_class(iptr->Contents.style));
				}
				break;
			case	_BUTTON_FRAME	:
				if ( iptr->Contents.datatype == _WIDGET_UPLOAD )
				{
					fprintf(h,"\t\t$this->%s = new visual_file_upload(",php_widget_name(iptr) );
					break;
				}
				else if ( iptr->Contents.datatype == _WIDGET_NETWORK  )
				{
					fprintf(h,"\t\t$this->%s = new visual_network(",php_widget_name(iptr) );
					break;
				}
				else if ( iptr->Contents.datatype == _WIDGET_DROPZONE )
				{
					fprintf(h,"\t\t$this->%s = new visual_dropzone(",php_widget_name(iptr) );
					break;
				}
				else if ( iptr->Contents.datatype == _WIDGET_IFRAME )
				{
					fprintf(h,"\t\t$this->%s = new visual_iframe(",php_widget_name(iptr) );
					break;
				}
				else if ( iptr->Contents.datatype == _WIDGET_VIDEO )
				{
					fprintf(h,"\t\t$this->%s = new visual_video(",php_widget_name(iptr) );
					break;
				}
				else if ( iptr->Contents.datatype == _WIDGET_AUDIO )
				{
					fprintf(h,"\t\t$this->%s = new visual_audio(",php_widget_name(iptr) );
					break;
				}
				else if ( iptr->Contents.datatype == _WIDGET_AJAX )
				{
					fprintf(h,"\t\t$this->%s = new visual_ajax(",php_widget_name(iptr) );
					break;
				}
				else if (iptr->Contents.align & 1)
				{
					if ( iptr->Contents.datatype == _WIDGET_HYPERLINK )
					{
						fprintf(h,"\t\t$this->%s = new visual_hyperlink_icon(",php_widget_name(iptr) );
					}
					else if ( iptr->Contents.datatype == _WIDGET_AJAX )
					{
						fprintf(h,"\t\t$this->%s = new visual_ajax_icon(",php_widget_name(iptr) );
					}
					else
					{
						fprintf(h,"\t\t$this->%s = new visual_icon(",php_widget_name(iptr) );
					}	
					break;
				}
				else if (iptr->Contents.align & 2)
				{
					fprintf(h,"\t\t$this->%s = new visual_trigger(",php_widget_name(iptr) );
					break;
				}

			case	_FORM_FRAME	:
				if ( iptr->Contents.datatype == _WIDGET_IMAGE )
				{
					fprintf(h,"\t\t$this->%s = new visual_image_table(",
						php_widget_name(iptr),
						php_widget_class(iptr->Contents.style));
					break;
				}
			default			:
				if ( iptr->Contents.datatype == _WIDGET_HYPERLINK )
				{
					fprintf(h,"\t\t$this->%s = new visual_hyperlink_%s(",
						php_widget_name(iptr),
						php_widget_class(iptr->Contents.style));
				}
				else if ( iptr->Contents.datatype == _WIDGET_AJAX )
				{
					fprintf(h,"\t\t$this->%s = new visual_ajax_%s(",
						php_widget_name(iptr),
						php_widget_class(iptr->Contents.style));
				}
				else
				{
					fprintf(h,"\t\t$this->%s = new visual_%s(",
						php_widget_name(iptr),
						php_widget_class(iptr->Contents.style));
				}
			}

			if ( wptr ) 
			{

				php_widget_position(h,fptr,wptr, iptr, fh );

			}
			else	
			{
				fprintf(h,"%u,%u,%u",
					iptr->Contents.x,
					iptr->Contents.y,
					iptr->Contents.w  );

				if (iptr->Contents.style == _SELECT_FRAME )
					fprintf(h,",%u",fh);
				else	fprintf(h,",%u",iptr->Contents.h);

			}

			/* Special Cases Table/Scroll */
			/* -------------------------- */
			switch ((iptr->Contents.style & _FRAME_TYPE)) 
			{
				case	_EDIT_FRAME	:
					if ( rowcount > 1 )
					{
						fprintf(h,",%u,%u",rowcount,colcount);
					}
					break;

				case	_FORM_FRAME	:
					/* x,y,w,h,t,f,s,nc,nr,fw,fh */
					php_table_parameters(h,iptr);
					break;
			}

			/* Widgets with messages */
			/* --------------------- */
			switch ((iptr->Contents.style & _FRAME_TYPE)) 
			{
				case	_FILL_FRAME	:
					fprintf(h,",%u",iptr->Contents.align);
					break;
				case	_SELECT_FRAME	:
				case	_IMAGE_FRAME	:
				case	_TEXT_FRAME	:
				case	_BUTTON_FRAME	:
				case	_CHECK_FRAME	:
				case	_RADIO_FRAME	:
				case	_WINDOW_FRAME	:
				case	_SWITCH_FRAME	:
				case	_TAB_FRAME	:
					php_current_payload(h,iptr,1);
					break;
			}	

			/* Aligned Widgets */
			/* --------------- */
			switch ((iptr->Contents.style & _FRAME_TYPE)) 
			{
				case	_IMAGE_FRAME	:
					fprintf(h,",%u",iptr->Contents.align);
					break;
				case	_TEXT_FRAME	:
				case	_WINDOW_FRAME	:
				case	_SWITCH_FRAME	:
					fprintf(h,",%u",iptr->Contents.align);
					break;
			}	

			/* Widgets with Colour */
			/* ------------------- */
			switch ((iptr->Contents.style & _FRAME_TYPE)) 
			{
				case	_FILL_FRAME	:
				case	_SWITCH_FRAME	:
				case	_TEXT_FRAME	:
					fprintf(h,",%c",__QUOTE);
					html_rgb_colour(h,(iptr->Contents.colour & 0x00FF));
					fprintf(h,"%c,%c",__QUOTE,__QUOTE);
					html_rgb_colour(h,((iptr->Contents.colour & 0xFF00) >> 8));
					fprintf(h,"%c",__QUOTE);
					break;
			}

			/* Widgets with text */
			/* ----------------- */
			switch ((iptr->Contents.style & _FRAME_TYPE)) 
			{
			case	_TEXT_FRAME	:
			case	_SWITCH_FRAME	:
			case	_CHECK_FRAME	:
			case	_RADIO_FRAME	:
			case	_WINDOW_FRAME	:
			case	_TAB_FRAME	:
			case	_BUTTON_FRAME	:
				fprintf(h,",%u",txfh);
				break;
			}

			/* Special Cases */
			/* ------------- */
			switch ((iptr->Contents.style & _FRAME_TYPE)) 
			{
			case	_TAB_FRAME	:
				if ( resolve_style_margin("pageframe", &awz.y,&awz.w,&awz.h,&awz.x ) != 0)
					iptr->Contents.ylimit = awz.y;
				else if ( resolve_style_margin("pagebutton", &awz.y,&awz.w,&awz.h,&awz.x ) != 0)
					iptr->Contents.ylimit = awz.h;
				else 	iptr->Contents.ylimit = 24;
				fprintf(h,",%u,%u,%u,%u",iptr->Contents.page,iptr->Contents.adjust,iptr->Contents.xlimit,iptr->Contents.ylimit);
				break;
			}
			fprintf(h,");\n");
			fprintf(h,"\t\t$this->%s->parent = $this;\n",php_widget_name(iptr));
			if ( iptr->Contents.events->xo_show & _EVENT_IS_COND )
			{
				fprintf(h,"\t\t$this->%s->ishidden = 1;\n",php_widget_name(iptr) );
			}
			if ((( sptr = iptr->Contents.stylesheet) != (char *) 0)
			&&  (( vptr = selection_item(0,sptr ))   != (char *) 0)) 
			{
				fprintf(h,"\t\t$this->%s->appearance = \"%s\";\n",php_widget_name(iptr),vptr);
			}
			/* -------------------------------- */
			/* widget specific extra operations */
			/* -------------------------------- */
			switch ((iptr->Contents.style & _FRAME_TYPE)) 
			{
			case	_WINDOW_FRAME	:
				/* ------------------------------------------- */
				/* should the window shadow the previous layer */
				/* ------------------------------------------- */
				if ( iptr->Contents.align & _A_SHADOW )
				{
					fprintf(h,"\t\t$this->%s->shadow = 1;\n",php_widget_name(iptr));
				}
				break;

			case	_FORM_FRAME	:
			case	_EDIT_FRAME	:
				if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS ))
				{
					fprintf(h,"\t\t$this->%s->readonly = 1;\n",php_widget_name(iptr));
				}
				if ( iptr->Contents.align & _A_LINE )
				{
					fprintf(h,"\t\t$this->%s->password = 1;\n",php_widget_name(iptr));
				}
			break;
			}

			/* extra post construction */
			/* ----------------------- */
			options = 0;
			switch ((iptr->Contents.style & _FRAME_TYPE)) 
			{
			case	_WINDOW_FRAME	:
				if (!( php_multi_language( fptr ) ))
					break;
				else
				{
					fprintf(h,"\t\t$this->%s->SetLanguage($this->language);\n",php_widget_name(iptr));
					break;
				}

			case	_FORM_FRAME	:
			case	_EDIT_FRAME	:
			case	_CHECK_FRAME	:
			case	_SELECT_FRAME	:
			case	_SCROLL_FRAME	:
				if (method_is_valid( iptr->Contents.events->on_event ) )
					options |= 1;
				if (method_is_valid( iptr->Contents.events->on_lose_focus ) )
					options |= 2;
				if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS ))
					options |= 4;
				break;
			}

			if ( iptr->Contents.datatype  == _WIDGET_CHAINTOP )
			{ fprintf(h,"\t\t$this->%s->SetTarget( \"_top\" );\n",php_widget_name(iptr)); }

			if ((eptr = php_use_hint( iptr )))
			{
				fprintf(h,"\t\t$this->%s->SetHint($this->hint_%s[$this->language]);\n",
					php_widget_name(iptr),php_widget_name(iptr));

			}

			if ( options ) 
			{
				fprintf(h,"\t\t$this->%s->SetEvents(%u);\n",php_widget_name(iptr),options);
			}
		}
	}
	php_close_method(h);
	return;
}

/*	-------------------------------------------------------------------	*/
/*	    	p h p _ o n c l i e n t _ m e t h o d ( h, fptr )		*/
/*	-------------------------------------------------------------------	*/
/*	generation of implicite Client method to ensure linkage to Soap		*/
/*	-------------------------------------------------------------------	*/
private	void	php_onclient_method(FILE * h, struct form_control * fptr)
{
	struct	form_item * iptr=(struct form_item *) 0;
	php_open_method(h,"OnClient($psc)");
	fprintf(h,"\t\t$this->soapClient = $psc;\n");
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if ( iptr->Contents.style != _DATA_FRAME )
			continue;
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else	{
			fprintf(h,"\t\t$this->%s->OnClient($psc);\n", php_widget_name(iptr) );
			continue;
			}
		}
	php_close_method(h);
	return;
}

/*	-------------------------------------------------------------------	*/
/*	p h p _ o n i n v o k e _ t a b l e _ p a r a m e t e r s ( h,fptr)	*/
/*	-------------------------------------------------------------------	*/
/*	generation of table request parameters for Invoke method for Soap	*/
/*	-------------------------------------------------------------------	*/
private	void	php_oninvoke_table_parameters(FILE * h, struct form_item * iptr, char * rname,char * pname)
{
	int	r;
	int	c;
	char	value[32];
	char *	buffer=(char *) 0;
	int	fh;
	int	fw;
	int 	linelength, nblines,i,fields,posit;
	int	fieldwidth[_MAX_FORM_FIELDS];

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return;

	calculate_edit_size( &iptr->Contents );
	calculate_form_lines( iptr, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
		return;
	else if (!( buffer = allocate( (fields * 16) )))
		return;

	fw = guifontsize(iptr->Contents.font);
	fh = (fw >> 8); fw &= 0x00FF;	

	for (	r=0; r < nblines; r ++ ) {
		fprintf(h,"\t$this->%s->setLine(%u);\n",php_widget_name(iptr),r+1);
		for ( c=0; c < fields; c++ ) {
			fprintf(h,"$this->soapClient->stringParameter($psc.'%s%s_%sr%uc%u',",( rname ? "_" : "\0"),( rname ? rname : "\0" ),php_widget_name(iptr),r,c);
			fprintf(h,"\t$this->%s->getColumn(%u));\n",php_widget_name(iptr),c+1);
			}
		}
	return;
}

/*	-------------------------------------------------------------------	*/
/*	   p h p _ o n i n v o k e _ t a b l e _ r e s u l t s ( h,fptr)	*/
/*	-------------------------------------------------------------------	*/
/*	generation of table request results for Invoke method for Soap		*/
/*	-------------------------------------------------------------------	*/
private	void	php_oninvoke_table_results(FILE * h, struct form_item * iptr, char * rname,char * pname)
{
	int	r;
	int	c;
	char	value[32];
	char *	buffer=(char *) 0;
	int	fh;
	int	fw;
	int 	linelength, nblines,i,fields,posit;
	int	fieldwidth[_MAX_FORM_FIELDS];

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return;

	calculate_edit_size( &iptr->Contents );
	calculate_form_lines( iptr, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
		return;
	else if (!( buffer = allocate( (fields * 16) )))
		return;

	fw = guifontsize(iptr->Contents.font);
	fh = (fw >> 8); fw &= 0x00FF;	

	for (	r=0; r < nblines; r ++ ) {
		fprintf(h,"\t$this->%s->setLine(%u);\n",php_widget_name(iptr),r+1);
		for ( c=0; c < fields; c++ ) {
			fprintf(h,"\t$this->%s->setColumn(%u,",php_widget_name(iptr),c+1);
			fprintf(h,"$this->soapClient->stringResult($psc.'%s%s_%sr%uc%u'));\n",
				( rname ? "_" : "\0"),
				( rname ? rname : "\0" ),
				php_widget_name(iptr),r,c);
			}
		}
	return;
}

/*	-------------------------------------------------------------------	*/
/*	    p h p _ o n i n v o k e _ p a r a m e t e r s ( h, fptr )		*/
/*	-------------------------------------------------------------------	*/
/*	generation of request parameters for the Invoke method for Soap		*/
/*	-------------------------------------------------------------------	*/
private	void	php_oninvoke_parameters(
	FILE * h, struct form_control * fptr, char * rname,char * pname
	)
{
	struct	form_item 	* iptr;
	struct	form_control 	* ffptr;
	char			* fnptr;
	char	nbuffer[8192];
	char	pbuffer[8192];
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		/* Transfer Values to Request */
		/* -------------------------- */
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_EDIT_FRAME	:
				fprintf(h,"$this->soapClient->stringParameter($psc.'%s%s_%s',%s->%s->buffer);\n",( rname ? "_" : "\0"),( rname ? rname : "\0" ),php_widget_name(iptr),pname,php_widget_name(iptr));
				break;
			case	_CHECK_FRAME	:
				fprintf(h,"$this->soapClient->integerParameter($psc.'%s%s_%s',%s->%s->value);\n",( rname ? "_" : "\0"),( rname ? rname : "\0" ),php_widget_name(iptr),pname,php_widget_name(iptr));
				break;
			case	_SELECT_FRAME	:
				fprintf(h,"$this->soapClient->integerParameter($psc.'%s%s_%s',%s->%s->value);\n",( rname ? "_" : "\0"),( rname ? rname : "\0" ),php_widget_name(iptr),pname,php_widget_name(iptr));
				break;
			case	_SWITCH_FRAME	:
				fprintf(h,"$this->soapClient->integerParameter($psc.'%s%s_%s',%s->%s->value);\n",( rname ? "_" : "\0"),( rname ? rname : "\0" ),php_widget_name(iptr),pname,php_widget_name(iptr));
				break;
			case	_SCROLL_FRAME	:
				fprintf(h,"$this->soapClient->integerParameter($psc.'%s%s_%s',%s->%s->value);\n",( rname ? "_" : "\0"),( rname ? rname : "\0" ),php_widget_name(iptr),pname,php_widget_name(iptr));
				break;
			case	_FORM_FRAME	:
				php_oninvoke_table_parameters(h,iptr,rname,pname);
				break;
			case	_DATA_FRAME	:
				if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
					continue;
				else if (!( fnptr = abal_payload(iptr) )) 
					continue;
				else if (!(ffptr = locate_form_control( fnptr ) ))
					continue;
				else	{
					if ( rname )
						sprintf(nbuffer,"%s_%s",rname,php_widget_name(iptr));
					else	strcpy(nbuffer,php_widget_name(iptr));
					fprintf(h,"$this->%s->OnParameters($psc.%c_%s%c);\n",php_widget_name(iptr),0x0022,php_widget_name(iptr),0x0022);
					continue;
					}
			}
		}
	return;
}

/*	-------------------------------------------------------------------	*/
/*	    	p h p _ o n i n v o k e _ r e s u l t s ( h, fptr )		*/
/*	-------------------------------------------------------------------	*/
/*	generation of request results from the Invoke method of Soap		*/
/*	-------------------------------------------------------------------	*/

private	void	php_oninvoke_results(FILE * h, struct form_control * fptr, char * rname,char * pname)
{
	struct	form_item 	* iptr;
	struct	form_control 	* ffptr;
	char			* fnptr;
	char	nbuffer[8192];
	char	pbuffer[8192];
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		/* Transfer Values to Request */
		/* -------------------------- */
		switch ((iptr->Contents.style & _FRAME_TYPE)) {
			case	_EDIT_FRAME	:
				fprintf(h,"%s->%s->buffer = $this->soapClient->stringResult($psc.'%s%s_%s');\n",pname,php_widget_name(iptr),( rname ? "_" : "\0"),( rname ? rname : "\0" ),php_widget_name(iptr));
				break;
			case	_CHECK_FRAME	:
				fprintf(h,"%s->%s->value = $this->soapClient->integerResult($psc.'%s%s_%s');\n",pname,php_widget_name(iptr),( rname ? "_" : "\0"),( rname ? rname : "\0" ),php_widget_name(iptr));
				break;
			case	_SELECT_FRAME	:
				fprintf(h,"%s->%s->value = $this->soapClient->integerResult($psc.'%s%s_%s');\n",pname,php_widget_name(iptr),( rname ? "_" : "\0"),( rname ? rname : "\0" ),php_widget_name(iptr));
				break;
			case	_SWITCH_FRAME	:
				fprintf(h,"%s->%s->value = $this->soapClient->integerResult($psc.'%s%s_%s');\n",pname,php_widget_name(iptr),( rname ? "_" : "\0"),( rname ? rname : "\0" ),php_widget_name(iptr));
				break;
			case	_SCROLL_FRAME	:
				fprintf(h,"%s->%s->value = $this->soapClient->integerResult($psc.'%s%s_%s');\n",pname,php_widget_name(iptr),( rname ? "_" : "\0"),( rname ? rname : "\0" ),php_widget_name(iptr));
				break;
			case	_FORM_FRAME	:
				php_oninvoke_table_results(h,iptr,rname,pname);
				break;
			case	_DATA_FRAME	:
				if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
					continue;
				else if (!( fnptr = abal_payload(iptr) )) 
					continue;
				else if (!(ffptr = locate_form_control( fnptr ) ))
					continue;
				else	{
					if ( rname )
						sprintf(nbuffer,"%s_%s",rname,php_widget_name(iptr));
					else	strcat(nbuffer,php_widget_name(iptr));
					fprintf(h,"$this->%s->OnResults($psc.%c_%s%c);\n",php_widget_name(iptr),0x0022,php_widget_name(iptr),0x0022);
					continue;
					}
			}
		}
	return;
}

/*	-------------------------------------------------------------------	*/
/*	    	p h p _ o n i n v o k e _ m e t h o d ( h, fptr )		*/
/*	-------------------------------------------------------------------	*/
/*	generation of implicite Invoke method to prepare message for Soap	*/
/*	-------------------------------------------------------------------	*/

private	void	php_oninvoke_method(FILE * h, struct form_control * fptr)
{
	struct	form_item * iptr=(struct form_item *) 0;

	php_open_method(h,"OnParameters($psc)");
		php_oninvoke_parameters(h,fptr,(char *)0,"$this");
	php_close_method(h);

	php_open_method(h,"OnResults($psc)");
		php_oninvoke_results(h,fptr,(char *)0,"$this");
	php_close_method(h);

	php_open_method(h,"OnInvoke($psc,$pmn)");
		fprintf(h,"\t\t$this->soapClient->resetClient();\n");
		fprintf(h,"\t\t$this->soapClient->method = $pmn;\n");
		fprintf(h,"\t\t$this->OnParameters($psc);\n");
		fprintf(h,"\t\t$this->soapClient->invokeRequest();\n");
		fprintf(h,"\t\t$this->OnResults($psc);\n");
	php_close_method(h);

	return;
}

/*	-------------------------------------------------------------------	*/
/*	    	p h p _ o n r e m o v e _ m e t h o d ( h, fptr )		*/
/*	-------------------------------------------------------------------	*/
/*	generation of implicite Remove methods of the form.			*/
/*	this is important for the preservation of SESSION information for 	*/
/*	an underlying database manager.						*/
/*	-------------------------------------------------------------------	*/
private	void	php_onremove_method(FILE * h, struct form_control * fptr)
{
	struct	form_item * iptr=(struct form_item *) 0;
	php_open_method(h,"OnRemove()");
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) 
	{
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		switch (( iptr->Contents.style & _FRAME_TYPE )) 
		{
		case	_SCROLL_FRAME	:
			fprintf(h,"\t$_SESSION['max_%s'] = $this->%s->max;\n",php_widget_name(iptr),php_widget_name(iptr));
			continue;
		case	_DATA_FRAME	:
			if (( iptr->Contents.align & 0x00FF) == _VISUAL_FRAME)
				fprintf(h,"\t$this->%s->OnRemove();\n",php_widget_name(iptr));
			else if (( iptr->Contents.align & 0x00FF) == _VGROUP_FRAME)
				fprintf(h,"\t$this->%s->OnRemove();\n",php_widget_name(iptr));
			else  if ( is_file_Widget( iptr ) ) 
			{
				if ( SoapAgent ) 
				{ fprintf(h,"\tif (!( $this->soapClient )) {\n"); }
				fprintf(h,"\t$this->%s->OnSaveSession();\n",php_widget_name(iptr));
				if ( SoapAgent ) 
				{ fprintf(h,"\t}\n"); }
			}
		default			:
			continue;
		}
	}
	if ( is_valid_string( fptr->extends ))
		fprintf(h,"\t\t%s::OnRemove($psn.\"_%s\");\n",fptr->extends,fptr->extends);
	php_close_method(h);
}

/*	-------------------------------------------------------------------	*/
/*	    	p h p _ o n c r e a t e _ m e t h o d ( h, fptr )		*/
/*	-------------------------------------------------------------------	*/
/*	generation of implicite Create methods of the form.			*/
/*	-------------------------------------------------------------------	*/
private	void	php_oncreate_method(FILE * h, struct form_control * fptr)
{
	struct	form_item * iptr=(struct form_item *) 0;
	php_open_method(h,"OnCreate($psn)");

	if (is_valid_string(  fptr->extends ))
		fprintf(h,"\t\t%s::OnCreate($psn.\"_%s\");\n",fptr->extends,fptr->extends);

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (!( method_is_valid( iptr->Contents.events->on_create ) ))
			continue;
		else if ( 1 > 1 ) {
			if (!( SoapAgent )) {
				fprintf(h,"\t\t$this->%sCreate($psn.%c_%s%c);\n",
					php_widget_name(iptr),__QUOTE,
					php_widget_name(iptr),__QUOTE);
				}
			else	{
				fprintf(h,"\t\t$this->%sCreate($psn);\n",
					php_widget_name(iptr));
				}

			}
		}
	php_close_method(h);
	return;
}

/*	-------------------------------------------------------------------	*/
/*		     p h p _ t a b l e _ r e q u e s t  			*/
/*	-------------------------------------------------------------------	*/
/*	reception of request values forthe various fields of the table		*/
/*	-------------------------------------------------------------------	*/
private	void	php_table_request(FILE * h, struct form_item * iptr)
{
	int	r;
	int	c;
	char	value[32];
	char *	buffer=(char *) 0;
	int	fh;
	int	fw;
	int 	linelength, nblines,i,fields,posit;
	int	fieldwidth[_MAX_FORM_FIELDS];

	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return;

	calculate_edit_size( &iptr->Contents );
	calculate_form_lines( iptr, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
		return;
	else if (!( buffer = allocate( (fields * 16) )))
		return;

	fw = guifontsize(iptr->Contents.font);
	fh = (fw >> 8); fw &= 0x00FF;	

	fprintf(h,"\tif(!( $this->%s->row = ",php_widget_name(iptr));
		fprintf(h,"$preq[$psn.'_'.'%s_row'] ))\n",php_widget_name(iptr));
	fprintf(h,"\t\t$this->%s->row = 1;\n",php_widget_name(iptr));

	fprintf(h,"\tif (!( $this->%s->column = ",php_widget_name(iptr));
		fprintf(h,"$preq[$psn.'_'.'%s_column'] ))\n",php_widget_name(iptr));
	fprintf(h,"\t\t$this->%s->column = 1;\n",php_widget_name(iptr));

	for (	r=0; r < nblines; r ++ ) {
		fprintf(h,"\t$this->%s->setLine(%u);\n",php_widget_name(iptr),r+1);
		for ( c=0; c < fields; c++ ) {
			fprintf(h,"\t$this->%s->setColumn(%u,$preq[$psn.'_'.'%sr%uc%u']);\n",php_widget_name(iptr),c+1,php_widget_name(iptr),r,c);
			}
		}
	return;
}

/*	-------------------------------------------------------------------	*/
/*	    	p h p _ o n r e q u e s t _  m e t h o d ( h, fptr )		*/
/*	-------------------------------------------------------------------	*/
/*	generation of implicite Request method of the form. This method is	*/
/*	responsible for the recovery of POST/GET request variable name and	*/
/*	value pairs to ste the internal forms object field values.		*/
/*	-------------------------------------------------------------------	*/
private	void	php_onrequest_method(FILE * h, struct form_control * fptr)
{
	struct	form_item * iptr=(struct form_item *) 0;

	php_open_method(h,"OnRequest($psn,$preq)");

	if ( is_valid_string( fptr->extends) )
		fprintf(h,"\t\t%s::OnRequest($psn.\"_%s\",$preq);\n",fptr->extends,fptr->extends);

	if ( fptr->pages ) {
		fprintf(h,"\t\tif ( isset( $_REQUEST['_page_number_'] ) ) {\n");
		fprintf(h,"\t\tswitch (( $this->pagenumber = $_REQUEST['_page_number_'] ))\n");
		fprintf(h,"\t\t{\n");
		for (	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next ) {
			if ((!( iptr->Contents.w  ))
			||  (!( iptr->Contents.h  )))
				continue;
			else if ( iptr->Contents.style != _TAB_FRAME )
				continue;
			else	{
				fprintf(h,"\t\tcase %u :",iptr->Contents.page);
				fprintf(h," $this->%s->OnTrigger(%c%c);",
					php_widget_name(iptr),
					__QUOTE,__QUOTE);
				fprintf(h," break;\n",iptr->Contents.page);
				}
			}
		fprintf(h,"\t\t}\n");
		fprintf(h,"\t\t}\n");
		fprintf(h,"\t\telse { $this->pagenumber = 0; }\n");
		}

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) 
	{

		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		else if ( iptr->Contents.style == _DATA_FRAME ) 
		{
			if ((( iptr->Contents.align & 0x00FF) == _VISUAL_FRAME) 
			||  (( iptr->Contents.align & 0x00FF) == _VGROUP_FRAME)) {
				fprintf(h,"\t\t$this->%s->OnRequest($psn.%c_%s%c,$preq);\n",
				php_widget_name(iptr),__QUOTE,
				php_widget_name(iptr),__QUOTE);
				}
			continue;
		}
		
		/* Transfer Values from Request */
		/* ---------------------------- */
		switch ((iptr->Contents.style & _FRAME_TYPE)) 
		{
		case	_BUTTON_FRAME	:
			if ( iptr->Contents.datatype != _WIDGET_DROPZONE )
				break;
		case	_EDIT_FRAME	:
			fprintf(h,"\tif ( isset( $preq[$psn.'_'.'%s'] ))\n",php_widget_name(iptr));
			fprintf(h,"\t{ $this->%s->buffer = $preq[$psn.'_'.'%s']; }\n",php_widget_name(iptr),php_widget_name(iptr));
			fprintf(h,"\telse { $this->%s->buffer = ''; }\n",php_widget_name(iptr));
			break;
		case	_CHECK_FRAME	:
			fprintf(h,"\tif ( isset( $preq[$psn.'_'.'%s'] ))\n",php_widget_name(iptr));
			fprintf(h,"\t{ if ( $preq[$psn.'_'.'%s'] == 'on') {\n",php_widget_name(iptr));
			fprintf(h,"\t$this->%s->value = 1; } else { \n",php_widget_name(iptr));
			fprintf(h,"\t$this->%s->value = 0; }}\n",php_widget_name(iptr));
			fprintf(h,"\telse { $this->%s->value = 0; }\n",php_widget_name(iptr));
			break;
		case	_SELECT_FRAME	:
			fprintf(h,"\tif ( isset( $preq[$psn.'_'.'%s'] ))\n",php_widget_name(iptr));
			fprintf(h,"\t{ $this->%s->value = $preq[$psn.'_'.'%s']; }\n",php_widget_name(iptr),php_widget_name(iptr));
			fprintf(h,"\telse { $this->%s->value = 0; }\n",php_widget_name(iptr));
			break;
		case	_SWITCH_FRAME	:
			fprintf(h,"\tif ( isset( $preq[$psn.'_'.'%s'] ))\n",php_widget_name(iptr));
			fprintf(h,"\t{ $this->%s->value = $preq[$psn.'_'.'%s']; }\n",php_widget_name(iptr),php_widget_name(iptr));
			fprintf(h,"\telse { $this->%s->value = 0; }\n",php_widget_name(iptr));
			break;
		case	_SCROLL_FRAME	:
			fprintf(h,"\tif ( isset( $_SESSION['max_%s'] ) ) { $this->%s->max = $_SESSION['max_%s']; }\n",
					php_widget_name(iptr),php_widget_name(iptr),php_widget_name(iptr));
			fprintf(h,"\tif ( isset( $preq[$psn.'_'.'%s'] ))\n",php_widget_name(iptr));
			fprintf(h,"\t{ $this->%s->value = $preq[$psn.'_'.'%s']; }\n",php_widget_name(iptr),php_widget_name(iptr));
			fprintf(h,"\telse { $this->%s->value = 0; }\n",php_widget_name(iptr));
			break;
		case	_FORM_FRAME	:
			fprintf(h,"\t$this->%s->OnRequest($psn.'_'.'%s',$preq);\n",
					php_widget_name(iptr),php_widget_name(iptr));
			fprintf(h,"\tif ( isset( $preq[$psn.'_'.'%s_direction'] ))\n",php_widget_name(iptr));
			fprintf(h,"\t{ $this->%s->direction= $preq[$psn.'_'.'%s_direction']; }\n",php_widget_name(iptr),php_widget_name(iptr));
			break;
		}

		/* ------------------------------------------- */
		/* check if any construction has been declared */
		/* ------------------------------------------- */
		if ( method_is_valid( iptr->Contents.events->on_create ) ) 
		{
			if (!( SoapAgent )) 
			{
				fprintf(h,"\t\t$this->%sCreate($psn.%c_%s%c);\n",
				php_widget_name(iptr),__QUOTE,
				php_widget_name(iptr),__QUOTE);
			}
			else	
			{
				/*
				fprintf(h,"\t\t$this->%sCreate($psn);\n",
					php_widget_name(iptr));
				*/
			}
		}


	}
	php_close_method(h);
	return;
}

/*	-------------------------------------------------------------------	*/
/*	    	p h p _ o n s t y l e  _  m e t h o d ( h, fptr )		*/
/*	-------------------------------------------------------------------	*/
/*	generation of implicite Style method of the form. This method is	*/
/*	responsible for the production of the style class description of  	*/
/*	each widget of the form in terms of position, dimension and colour.	*/
/*	-------------------------------------------------------------------	*/
private	void	php_onstyle_method(FILE * h, struct form_control * fptr)
{
	struct	form_item * iptr=(struct form_item *) 0;

	php_open_method(h,"OnStyle($psn)");

	fprintf(h,"\t\tif ( $this->ishidden ) { return; }\n");

	if ( fptr->isdynamic ) 
	{
		if ( is_valid_string( fptr->extends ) )
			fprintf(h,"\t\t%s::OnStyle($psn.\"_%s\");\n",fptr->extends,fptr->extends);
		else	fprintf(h,"\tvisual_form::OnStyle($psn);\n");
		
	}
	else if ( is_valid_string( fptr->extends ))
		fprintf(h,"\t\t%s::OnStyle($psn.\"_%s\");\n",fptr->extends,fptr->extends);

	php_style_invocation( h );
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (( iptr->Contents.style == _DATA_FRAME ) && ( is_file_Widget( iptr )))
			continue;
		else	{
			fprintf(h,"\t\t$this->%s->OnStyle($psn.%c_%s%c);\n",
			php_widget_name(iptr),__QUOTE,
			php_widget_name(iptr),__QUOTE);
			}
		}
	php_close_method(h);
	return;
}

/*	-------------------------------------------------------------------	*/
/*	    	p h p _ o n s c r i p t _  m e t h o d ( h, fptr )		*/
/*	-------------------------------------------------------------------	*/
/*	generation of implicite Script method of the form. This method is	*/
/*	responsible for the production of all javascript widget event link	*/
/*	functions allowing event activity to be reported to the server.		*/
/*	-------------------------------------------------------------------	*/
private	void	php_onscript_method(FILE * h, struct form_control * fptr)
{
	struct	form_item * iptr=(struct form_item *) 0;

	php_open_method(h,"OnScript($psn)");
	fprintf(h,"\t\tif ( $this->ishidden ) { return; }\n");

	if ( is_valid_string( fptr->extends ))
		fprintf(h,"\t\t%s::OnScript($psn.\"_%s\");\n",fptr->extends,fptr->extends);

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (( iptr->Contents.style == _DATA_FRAME ) && ( is_file_Widget( iptr )))
			continue;
		else	{
			fprintf(h,"\t\t$this->%s->OnScript($psn.%c_%s%c);\n",
			php_widget_name(iptr),__QUOTE,
			php_widget_name(iptr),__QUOTE);
			}
		}
	php_close_method(h);
	return;
}

/*	-------------------------------------------------------------------	*/
/*	    	p h p _ r e m o v e _ m e t h o d s ( h, fptr )			*/
/*	-------------------------------------------------------------------	*/
/*	generation of explicite Remove methods for the widgets of the form.	*/
/*	-------------------------------------------------------------------	*/
private	void	php_remove_methods(FILE * h, struct form_control * fptr)
{
	int			status=0;
	struct	form_item * 	iptr;

	for (	iptr=fptr->last;
		iptr != (struct form_item *) 0;
		iptr = iptr->previous ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		else if (( iptr->Contents.style == _DATA_FRAME ) && ( is_file_Widget( iptr )))
			continue;

		else if (!( method_is_valid( iptr->Contents.events->on_remove ) ))
			continue;

		else	{
			fprintf(h,"\tfunction %sRemove($psn)\n",php_widget_name(iptr));
			fprintf(h,"\t{\n");
			if (SoapAgent) {
				status = abal_php_soap_method( h, iptr, php_widget_name(iptr), "Remove" );
				}
			else	{
				status = abal_php_method_body(h,
					iptr->Contents.events->on_remove,
					php_use_widget_name(iptr),1);
				}
			fprintf(h,"\t}\n");
			}
		}
	return;
}

/*	------------------------------------------------------------------	*/
/*		    p h p _ h i d e _ m e t h o d s ( h, fptr )			*/
/*	------------------------------------------------------------------	*/
/*	generation of explicite Hide methods for the widgets of the form.	*/
/*	------------------------------------------------------------------	*/
private	void	php_hide_methods(FILE * h, struct form_control * fptr)
{

	int			status=0;
	struct	form_item * iptr;
	show_status = 1;
	for (	iptr=fptr->last;
		iptr != (struct form_item *) 0;
		iptr = iptr->previous) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (( iptr->Contents.style == _DATA_FRAME ) && ( is_file_Widget( iptr )))
			continue;
		else if (!( method_is_valid( iptr->Contents.events->on_hide ) ))
			continue;
		else	{
			fprintf(h,"\tfunction %sHide($psn)\n",php_widget_name(iptr));
			fprintf(h,"\t{\n");
			switch ( SoapAgent ) {
				case	2 :
					status = abal_php_soap_method( h, iptr, php_widget_name(iptr), "Hide" );
				case	1 :
					indent(h,1);
					fprintf(h,"$this->%s->OnHide($psn.%c_%s%c);",	
						php_widget_name(iptr),__QUOTE,
						php_widget_name(iptr),__QUOTE);
					linefeed(h);
					break;
				case	0 :
					status = abal_php_method_body(h,
						iptr->Contents.events->on_hide,
						php_use_widget_name(iptr),1);
				}
			fprintf(h,"\t}\n");
			}
		}
	show_status = 0;
	return;
}

/*	------------------------------------------------------------------	*/
/*		    p h p _ s h o w _ m e t h o d s ( h, fptr )			*/
/*	------------------------------------------------------------------	*/
/*	generation of explicite Show methods for the widgets of the form.	*/
/*	------------------------------------------------------------------	*/
private	void	php_show_methods(FILE * h, struct form_control * fptr)
{
	int			status=0;
	struct	form_item * iptr;
	show_status = 1;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (( iptr->Contents.style == _DATA_FRAME ) && ( is_file_Widget( iptr )))
			continue;
		else if (!( method_is_valid( iptr->Contents.events->on_show ) ))
			continue;
		else	{
			fprintf(h,"\tfunction %sShow($psn)\n",php_widget_name(iptr));
			fprintf(h,"\t{\n");
			switch ( SoapAgent ) {
				case	2 :
					status = abal_php_soap_method( h, iptr, php_widget_name(iptr), "Show" );
				case	1 :
					indent(h,1);
					fprintf(h,"$this->%s->OnShow($psn.%c_%s%c);",	
						php_widget_name(iptr),__QUOTE,
						php_widget_name(iptr),__QUOTE);
					linefeed(h);
					break;
				case	0 :
					status = abal_php_method_body(h,
						iptr->Contents.events->on_show,
						php_use_widget_name(iptr),1);
				}
			fprintf(h,"\t}\n");
			}
		}
	show_status = 0;
	return;
}

/*	------------------------------------------------------------------	*/
/*	     p h p _ o n s h o w _ m e t h o d ( h, iptr, margin )		*/
/*	------------------------------------------------------------------	*/
/*	generation of implicite OnPayload method of the widget.			*/
/*	------------------------------------------------------------------	*/
private	void	php_onpayload_method(FILE * h, struct form_item * iptr, char * payload, int margin )
{
	indent(h,margin);
	fprintf(h,"$this->%s->OnPayloadChange(", php_widget_name(iptr) );
	abal_php_macro_conversion(h, payload,php_use_widget_name(iptr) );
	fprintf(h,");\n");
	return;
}

private	void	abal_php_show_conditional( FILE * h, struct form_item * iptr )
{
	if (!( iptr->Contents.events->xo_show & _EVENT_IS_COND ))
	{
		fprintf(h,"\t\t$this->%s->ishidden=$this->ishidden;\n",php_widget_name(iptr));
	}
}

/*	------------------------------------------------------------------	*/
/*		  p h p _ o n s h o w _ m e t h o d ( h, fptr )			*/
/*	------------------------------------------------------------------	*/
/*	generation of implicite OnShow method of the form.			*/
/*	------------------------------------------------------------------	*/
private	void	php_onshow_method(FILE * h, struct form_control * fptr)
{
	char	*		sptr;
	int			thispage=0;
	int			status=0;
	struct	form_item * iptr;
	struct	form_item * pptr=(struct form_item *) 0;

	php_open_method(h,"OnShow($psn)");

	fprintf(h,"\t\tif ( $this->ishidden ) { return; }\n");

	if (!( fptr->pages ))
	{
		if ( fptr->isdynamic ) 
		{
			if ( is_valid_string( fptr->extends ) )
				fprintf(h,"\t\t%s::OnShow($psn.\"_%s\");\n",fptr->extends,fptr->extends);
			else	fprintf(h,"\t\tvisual_form::OnShow($psn);\n");
		}
		else if (is_valid_string(  fptr->extends ))
			fprintf(h,"\t\t%s::OnShow($psn.\"_%s\");\n",fptr->extends,fptr->extends);
		fprintf(h,"\t\t$this->OnGlobal($psn);\n");
	}
	else
	{
		if ( fptr->isdynamic ) 
		{
			if ( is_valid_string( fptr->extends ) )
				fprintf(h,"\t\t%s::OnShow($psn.\"_%s\");\n",fptr->extends,fptr->extends);
			else	fprintf(h,"\t\tvisual_paged_form::OnShow($psn);\n");
		}
		else if (is_valid_string(  fptr->extends ))
			fprintf(h,"\t\t%s::OnShow($psn.\"_%s\");\n",fptr->extends,fptr->extends);
		fprintf(h,"\t\t$this->OnGlobal($psn);\n");
	}
	switch (SoapAgent) 
	{
		case	1	:
			status = abal_php_soap_method( h, iptr, "On", "Show" );
			linefeed(h);
	}

	if ( fptr->pages ) 
	{
		fprintf(h,"\t\tif (!( $this->pagenumber ))\n\t\t{\n");
		fprintf(h,"\t\t$this->pagenumber=1;\n");
		/* activate the first page */
		for (	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next ) 
		{
			if ((!( iptr->Contents.w  ))
			||  (!( iptr->Contents.h  )))
				continue;
			else if ( iptr->Contents.style != _TAB_FRAME )
				continue;
			else	
			{
				fprintf(h,"\t\t$this->%s->OnTrigger(%c%c);\n",
					php_widget_name(iptr),
					__QUOTE,__QUOTE);
				break;
			}
		}
		fprintf(h,"\t\t};\n");
		fprintf(h,"\t\t$this->pageholder=$this->pagenumber;\n");
		fprintf(h,"\t\t$this->pagenumber=0;\n");
	}

	for ( thispage=0; thispage <= fptr->pages; thispage++ ) 
	{
		if ( fptr->pages ) 
		{
			for (	iptr=fptr->first;
				iptr != (struct form_item *) 0;
				iptr = iptr->next ) 
			{
				if ((!( iptr->Contents.w  ))
				||  (!( iptr->Contents.h  )))
					continue;
				else if ( iptr->Contents.style != _TAB_FRAME )
					continue;
				else if ( iptr->Contents.page != thispage )
					continue;
				else if (!( method_is_valid( iptr->Contents.events->on_show ) )) 
				{
					abal_php_show_conditional( h, iptr );
					fprintf(h,"\t\t$this->%s->OnShow($psn.%c_%s%c);\n",
						php_widget_name(iptr),__QUOTE,
						php_widget_name(iptr),__QUOTE);
				}
				else	
				{
					indent(h,2);
					fprintf(h,"$this->%sShow($psn);",
						php_widget_name(iptr));
					linefeed(h);
				}
			}
			fprintf(h,"\t\tif ( $this->pagenumber == %u )\n\t\t{\n",thispage);
		}

		for (	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next ) 
		{
			if ((!( iptr->Contents.w  ))
			||  (!( iptr->Contents.h  )))
				continue;
			else if (( iptr->Contents.style == _DATA_FRAME ) && ( is_file_Widget( iptr )))
				continue;

			else if ( iptr->Contents.style == _TAB_FRAME )
				continue;
			else if (!( thispage ) && (  iptr->Contents.page ))
				continue;
			else if (( fptr->pages ) && ( iptr->Contents.page != thispage )) 
				continue;
			else
			{
				switch ( iptr->Contents.style ) 
				{
				case	_WINDOW_FRAME	:
				case	_EDIT_FRAME	:
				case	_CHECK_FRAME	:
				case	_RADIO_FRAME	:
				case	_SWITCH_FRAME	:
				case	_SCROLL_FRAME	:
				case	_SELECT_FRAME	:
#ifdef	BEFORE_04082014
					if (!( SoapAgent )) 
					{
						abal_php_show_conditional( h, iptr );
						fprintf(h,"\t\t$this->%s->OnShow($psn.%c_%s%c);\n",
							php_widget_name(iptr),__QUOTE,
							php_widget_name(iptr),__QUOTE);
						break;
					}
#endif
				default			:
					abal_php_show_conditional( h, iptr );
				}
			}

			/* ------------------------------ */
			/* detect and set dynamic payload */
			/* ------------------------------ */
			if (( sptr = abal_payload( iptr )) != (char *) 0)
				if ( *sptr == _UNQUOTED_STRING )
					php_onpayload_method(h,iptr,(sptr+1),2);

			if (!( method_is_valid( iptr->Contents.events->on_show ) )) 
			{
				fprintf(h,"\t\t$this->wpage=%u;\n",iptr->Contents.page);
				fprintf(h,"\t\t$this->%s->OnShow($psn.%c_%s%c);\n",
					php_widget_name(iptr),__QUOTE,
					php_widget_name(iptr),__QUOTE);
			}
			else	
			{
				indent(h,2);
				fprintf(h,"\t\t$this->wpage=%u;\n",iptr->Contents.page);
				fprintf(h,"\t\t$this->%sShow($psn);",
					php_widget_name(iptr));
				linefeed(h);
			}
		}

		if ( fptr->pages ) 
		{
			fprintf(h,"\t\t}\n");
			if (!( thispage )) 
			{
				fprintf(h,"\t\t$this->pagenumber=$this->pageholder;\n");
			}
		}
	}

	if ( fptr->isdynamic ) 
	{
		fprintf(h,"\t\t$this->OnHide($psn);\n");
	}
	php_close_method(h);
	return;
}

/*	------------------------------------------------------------------	*/
/*		     p h p _ t r i g g e r _ u n q u o t e d 			*/
/*	------------------------------------------------------------------	*/
/*	called to generate a cal lto an unquoted string target for a push	*/
/*	button element.								*/
/*	------------------------------------------------------------------	*/
private	void	php_trigger_unquoted( FILE * h, char * sptr, struct form_item * iptr )
{
	fprintf(h,"\t\t$this->%s->OnTrigger(",php_widget_name(iptr) );
	abal_php_macro_conversion(h, sptr,php_use_widget_name(iptr) );
	fprintf(h,");\n");
	return;
}

/*	-------------------------------------	*/
/*	  p h p _ w i d g e t _ u p l o a d	*/
/*	-------------------------------------	*/
public	void	php_widget_upload( FILE * h, struct form_item * iptr )
{
	fprintf(h,"\t\tcopy( $_FILES[$psn.'_%s_file']['tmp_name'],$this->%s->buffer);\n",php_widget_name(iptr),php_widget_name(iptr));
	fprintf(h,"\t\t$this->%s->buffer = $_FILES[$psn.'_%s_file']['name'];\n",php_widget_name(iptr),php_widget_name(iptr));
	return;
}

/*	------------------------------------------------------------------	*/
/*		p h p _ e v e n t _ m e t h o d s ( h, fptr )			*/
/*	------------------------------------------------------------------	*/
/*	generation of explicite Event methods for the widgets of the form.	*/
/*	------------------------------------------------------------------	*/
private	void	php_event_methods(FILE * h, struct form_control * fptr)
{
	int			status=0;
	struct	form_item * iptr;
	char		*	target;

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (( iptr->Contents.style != _BUTTON_FRAME )
		     &&  ( iptr->Contents.style != _FORM_FRAME  ) 
		     &&  ( iptr->Contents.style != _EDIT_FRAME  ) 
		     &&  ( iptr->Contents.style != _CHECK_FRAME  ) 
		     &&  ( iptr->Contents.style != _RADIO_FRAME  ) 
		     &&  ( iptr->Contents.style != _SELECT_FRAME  ) 
		     &&  ( iptr->Contents.style != _DATA_FRAME  ) 
		     &&  ( iptr->Contents.style != _SCROLL_FRAME  ) 
		     &&  ( iptr->Contents.style != _TAB_FRAME    )) 
			continue;
		else if (( iptr->Contents.style == _DATA_FRAME )
		     &&  (( iptr->Contents.align & 0x00FF) != _VGROUP_FRAME) 
		     &&  (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)) 
			continue;
		else	
		{
			if ( iptr->Contents.datatype == _WIDGET_UPLOAD   ) 
			{
				fprintf(h,"\tfunction %sUpload($psn)\n",php_widget_name(iptr));
				fprintf(h,"\t{\n");
					php_widget_upload( h, iptr );
				fprintf(h,"\t}\n");
			}

			fprintf(h,"\tfunction %sEvent($psn)\n",php_widget_name(iptr));
			fprintf(h,"\t{\n");
			if (SoapAgent) 
			{
				status = abal_php_soap_method( h, iptr, php_widget_name(iptr), "Event" );
			}
			else	
			{
				status = abal_php_method_body(h,
					iptr->Contents.events->on_event,
					php_use_widget_name(iptr),1);
			}
			switch ( iptr->Contents.datatype ) 
			{
			case	_WIDGET_UPLOAD		:
				fprintf(h,"\t$this->%sUpload($psn);\n",php_widget_name(iptr));
				break;
			case	_WIDGET_HYPERLINK	:
				if (!( method_is_valid ( iptr->Contents.format )))
					break;
				else if (!( target = allocate_string( iptr->Contents.format ) ))
					break;
				else if ( *target == _UNQUOTED_STRING )
				{
					php_trigger_unquoted( h, (target+1),iptr );
					liberate( target );
					break;
				}
				else
				{
					fprintf(h,"\t\t$this->%s->OnTrigger(%c%s%c);\n",
						php_widget_name(iptr),
						__QUOTE,target,__QUOTE);
					liberate( target );
					break;
				}					
			case	_WIDGET_CLASS	:
			case	_WIDGET_POINTER	:
			case	_WIDGET_MODULE 	:
			case	_WIDGET_CHAIN 	:
			case	_WIDGET_CHAINTOP :
			case	_WIDGET_LOADGO 	:
			case	_WIDGET_SYSTEM	:
			case	_WIDGET_OVERLAY	:
				if (!( method_is_valid ( iptr->Contents.format )))
					break;
				else if (!( target = allocate_string( iptr->Contents.format ) ))
					break;
				else if ( *target == _UNQUOTED_STRING )
				{
					php_trigger_unquoted( h, (target+1),iptr );
					liberate( target );
					break;
				}
				else if (!( target = enforce_extension( target,PHP_EXTENSION ) ))
					break;
				else
				{
					fprintf(h,"\t\t$this->%s->OnTrigger(%c%s%c);\n",
						php_widget_name(iptr),
						__QUOTE,target,__QUOTE);
					liberate( target );
					break;
				}
			default			:
				if ( iptr->Contents.style == _TAB_FRAME    ) 
				{
					fprintf(h,"\t\t$this->%s->OnTrigger(%c%c);\n",
						php_widget_name(iptr),
						__QUOTE,__QUOTE);
					}
				break;
			}

			fprintf(h,"\t\treturn(-1);\n");
			fprintf(h,"\t}\n");
			}
		}
	return;
}

/*	------------------------------------------------------------------	*/
/*		p h p _  l o s e  _ m e t h o d s ( h, fptr )			*/
/*	------------------------------------------------------------------	*/
/*	generation of explicite Lose  methods for the widgets of the form.	*/
/*	------------------------------------------------------------------	*/
private	void	php_lose_methods(FILE * h, struct form_control * fptr)
{
	int			status=0;
	struct	form_item * iptr;
	char		*	target;

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (( iptr->Contents.style != _EDIT_FRAME )
		     &&  ( iptr->Contents.style != _DATA_FRAME )
		     &&  ( iptr->Contents.style != _SELECT_FRAME )
		     &&  ( iptr->Contents.style != _FORM_FRAME ))
			continue;
		else if (( iptr->Contents.style == _DATA_FRAME )
		     &&  (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)) 
			continue;
		else if (!( method_is_valid ( iptr->Contents.events->on_lose_focus ) ))
			continue;
		else	{
			fprintf(h,"\tfunction %sLose($psn)\n",php_widget_name(iptr));
			fprintf(h,"\t{\n");
			if (SoapAgent) {
				status = abal_php_soap_method( h, iptr, php_widget_name(iptr), "Lose" );
				}
			else	{
				status = abal_php_method_body(h,
					iptr->Contents.events->on_lose_focus,
					php_use_widget_name(iptr),1);
				}
			fprintf(h,"\t}\n");
			}
		}
	return;
}

/*	------------------------------------------------------------------	*/
/*		  p h p _ o n m e t h o d _ m e t h o d ( h, fptr )		*/
/*	------------------------------------------------------------------	*/
/*	generation of implicite OnMethod method of the form. This method 	*/
/*	will be called after the OnRequest method to detect and activate	*/
/*	any event or lose focus requests required by the remote form.		*/
/*	------------------------------------------------------------------	*/
private	void	php_onmethod_method(FILE * h, struct form_control * fptr)
{
	int			status=0;
	struct	form_item * iptr;

	/* -------------------- */
	/* PHP ON METHOD METHOD */
	/* -------------------- */
	php_open_method(h,"OnMethod($psn,$preq)");
	fprintf(h,"\t\tif ( isset( $preq['method'] ) ) { \n");
	fprintf(h,"\t\tswitch ( $preq['method'] )\n");
	fprintf(h,"\t\t{\n");
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if ( iptr->Contents.style == _TAB_FRAME ) {
			fprintf(h,"\t\tcase $psn.%c_%sEvent%c : \n",
				__QUOTE,php_widget_name(iptr),__QUOTE);
			fprintf(h,"\t\t\t$this->formKeyCode = $this->%sEvent($psn);\n",php_widget_name(iptr));
			fprintf(h,"\t\t\tbreak;\n");
			}
		else if (( iptr->Contents.style == _BUTTON_FRAME )
		     ||  ( iptr->Contents.style == _EDIT_FRAME   ) 
		     ||  ( iptr->Contents.style == _FORM_FRAME   )) 
		{
			if (method_is_valid( iptr->Contents.events->on_event ) ) 
			{
				fprintf(h,"\t\tcase $psn.%c_%sEvent%c : \n",
					__QUOTE,php_widget_name(iptr),__QUOTE);
				fprintf(h,"\t\t\t$this->formKeyCode = $this->%sEvent($psn);\n",php_widget_name(iptr));
				fprintf(h,"\t\t\tbreak;\n");
			}
			else 
			{
				switch( iptr->Contents.datatype )
				{
				case	_WIDGET_HYPERLINK	:
				case	_WIDGET_CHAIN		:
				case	_WIDGET_CHAINTOP	:
				case	_WIDGET_TASK		:
				case	_WIDGET_SYSTEM		:
				case	_WIDGET_OVERLAY		:
				case	_WIDGET_MODULE		:
					fprintf(h,"\t\tcase $psn.%c_%sEvent%c : \n",
						__QUOTE,php_widget_name(iptr),__QUOTE);
					fprintf(h,"\t\t\t$this->formKeyCode = $this->%sEvent($psn);\n",php_widget_name(iptr));
					fprintf(h,"\t\t\tbreak;\n");
				}
			}
		}
		else if ( iptr->Contents.style == _SCROLL_FRAME ) {
			if (method_is_valid( iptr->Contents.events->on_event ) ) {
				fprintf(h,"\t\tcase $psn.%c_%sUpEvent%c : \n",
					__QUOTE,php_widget_name(iptr),__QUOTE);
				fprintf(h,"if ( $this->%s->value > 0 ) { $this->%s->value--; }\n",
					php_widget_name(iptr),
					php_widget_name(iptr));
				fprintf(h,"\t\t\t$this->formKeyCode = $this->%sEvent($psn);\n",php_widget_name(iptr));
				fprintf(h,"\t\t\tbreak;\n");
				fprintf(h,"\t\tcase $psn.%c_%sBarEvent%c : \n",
					__QUOTE,php_widget_name(iptr),__QUOTE);
				fprintf(h,"\t\t\t$this->formKeyCode = $this->%sEvent($psn);\n",php_widget_name(iptr));
				fprintf(h,"\t\t\tbreak;\n");
				fprintf(h,"\t\tcase $psn.%c_%sDownEvent%c : \n",
					__QUOTE,php_widget_name(iptr),__QUOTE);

#ifdef	_DEBUG_PHP_SCROLL
				fprintf(h,"print '%s->value = '.$this->%s->value.'<br>';\n",
					php_widget_name(iptr),
					php_widget_name(iptr));
				fprintf(h,"print '%s->max = '.$this->%s->max.'<br>';\n",
					php_widget_name(iptr),
					php_widget_name(iptr));
				fprintf(h,"print '%s->limit = '.$this->%s->limit.'<br>';\n",
					php_widget_name(iptr),
					php_widget_name(iptr));
#endif					
				fprintf(h,"if (( $this->%s->value+$this->%s->limit) < $this->%s->max ) { $this->%s->value++; }\n",
					php_widget_name(iptr),
					php_widget_name(iptr),
					php_widget_name(iptr),
					php_widget_name(iptr));
				fprintf(h,"\t\t\t$this->formKeyCode = $this->%sEvent($psn);\n",php_widget_name(iptr));
				fprintf(h,"\t\t\tbreak;\n");
				}
			}
		if (( iptr->Contents.style == _EDIT_FRAME   )
		||  ( iptr->Contents.style == _SELECT_FRAME ) 
		||  ( iptr->Contents.style == _FORM_FRAME   )) {
			if (method_is_valid( iptr->Contents.events->on_lose_focus ) ) {
				fprintf(h,"\t\tcase $psn.%c_%sLose%c : \n",
					__QUOTE,php_widget_name(iptr),__QUOTE);
				fprintf(h,"\t\tcase $psn.%c_%sEvent%c : \n",
					__QUOTE,php_widget_name(iptr),__QUOTE);
				fprintf(h,"\t\t\t$this->%sLose($psn);\n",php_widget_name(iptr));
				fprintf(h,"\t\t\tbreak;\n");
				}
			}
		else if (( iptr->Contents.style == _DATA_FRAME )
		     &&  (( iptr->Contents.align & 0x00FF) == _VISUAL_FRAME)) {

			if (method_is_valid( iptr->Contents.events->on_event ) ) {
				fprintf(h,"\t\tcase $psn.%c_%sEvent%c : \n",
					__QUOTE,php_widget_name(iptr),__QUOTE);
				fprintf(h,"\t\t\t$this->formKeyCode = $this->%sEvent($psn);\n",php_widget_name(iptr));
				fprintf(h,"\t\t\tbreak;\n");
				}

			if (method_is_valid( iptr->Contents.events->on_lose_focus ) ) {
				fprintf(h,"\t\tcase $psn.%c_%sLose%c : \n",
					__QUOTE,php_widget_name(iptr),__QUOTE);
				fprintf(h,"\t\t\t$this->%sLose($psn);\n",php_widget_name(iptr));
				fprintf(h,"\t\t\tbreak;\n");
				}
			}
		}
	fprintf(h,"\t\tdefault :\n");
#ifdef	NEWSING
	if ( method_is_valid( fptr->extends ) )
	{
		fprintf(h,"\t\t\t$prefix = $psn.\"_%s\";\n",fptr->extends);
		fprintf(h,"\t\t\tif ( isset( $preq['method'] ) ) { \n");
		fprintf(h,"\t\t\tif ( $prefix == substr($preq['method'],0,strlen($prefix) ))\n");
		fprintf(h,"\t\t\t{\n");
		fprintf(h,"\t\t\t\t%s::OnMethod($prefix,$preq);\n",fptr->extends);
		fprintf(h,"\t\t\t\tbreak;\n");
		fprintf(h,"\t\t\t}\n");
		fprintf(h,"\t\t\t}\n");
		
	}
#endif
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if ( iptr->Contents.style == _DATA_FRAME ) {
			if ((( iptr->Contents.align & 0x00FF) == _VISUAL_FRAME) 
			||  (( iptr->Contents.align & 0x00FF) == _VGROUP_FRAME)) {
				// ----------------------------
				// recalculate the prefix value
				// ----------------------------
				fprintf(h,"\t\t\tif ( isset( $preq['method'] ) ) { \n");
				fprintf(h,"\t\t\t$prefix = $preq['method'];\n");
				fprintf(h,"\t\t\t$prefix = substr($prefix,0,strlen($psn.%c_%s%c));\n",
					__QUOTE,php_widget_name(iptr),__QUOTE);
				fprintf(h,"//\t\t\tprint $prefix . \" == \" . $psn.%c_%s%c . \"<br>\"; \n",
					__QUOTE,php_widget_name(iptr),__QUOTE);
				fprintf(h,"\t\t\tif ( $prefix == $psn.%c_%s%c ) \n",
					__QUOTE,php_widget_name(iptr),__QUOTE);
				fprintf(h,"\t\t\t{\n");
				if (( iptr->Contents.align & 0x00FF) == _VISUAL_FRAME) 
				{
					fprintf(h,"\t\t\t\t$__tempKeyCode = $this->%s->formKeyCode;\n",
						php_widget_name(iptr)); 
					fprintf(h,"\t\t\t\t$this->%s->OnMethod($psn.%c_%s%c,$preq);\n",
						php_widget_name(iptr),__QUOTE,
						php_widget_name(iptr),__QUOTE);
				}
				else
				{
					fprintf(h,"\t\t\t\tif ( $this->%s->OnMethod($psn.%c_%s%c,$preq) != NULL )\n",
						php_widget_name(iptr),__QUOTE,
						php_widget_name(iptr),__QUOTE);
					fprintf(h,"\t\t\t\t\t$this->formKeyCode = $this->%sEvent($psn);\n",php_widget_name(iptr));
					fprintf(h,"\t\t\t\tbreak;\n");
				}
				// ----------------------------------
				// Test for a component exit type key 
				// and handle lose focus is true.
				// ----------------------------------
				if (( iptr->Contents.align & 0x00FF) == _VISUAL_FRAME) 
				{
					fprintf(h,"\t\t\t\tif ( $this->%s->formKeyCode == 13 )",
						php_widget_name(iptr)); 
					fprintf(h,"\t\t\t\t{\n");
					fprintf(h,"\t\t\t\t\t$this->%sLose($psn);\n",
						php_widget_name(iptr)); 
					fprintf(h,"\t\t\t\t}\n");
				}
				fprintf(h,"\t\t\t}\n");
				fprintf(h,"\t\t\t}\n");
				}
			continue;
			}
		}
	fprintf(h,"\t\t}\n");
	fprintf(h,"\t\t}\n");
	php_close_method(h);
	return;
}

/*	------------------------------------------------------------------	*/
/*	      p h p _ i n t e r f a c e _ m e t h o d s ( h, fptr )		*/
/*	------------------------------------------------------------------	*/
/*	generation of all implicte interface methods of the form.		*/
/*	------------------------------------------------------------------	*/
private	void	php_interface_methods(FILE * h, struct form_control * fptr)
{
	int			status=0;
	struct	form_item * iptr;

	php_constructor_method(h,fptr);

	/* -------------------- */
	/*  PHP ONCREATE METHOD */
	/* -------------------- */
	php_create_methods(h,fptr);
	if ( SoapAgent )
	{
		php_onclient_method(h,fptr);
		php_oninvoke_method(h,fptr);
	}
	php_oncreate_method(h,fptr);

	/* --------------------- */
	/*  PHP ONREQUEST METHOD */
	/* --------------------- */
	php_onrequest_method(h,fptr);

	/* ------------------- */
	/* PHP ON STYLE METHOD */
	/* ------------------- */
	php_onstyle_method(h,fptr);

	/* ------------------- */
	/* PHP ONSCRIPT METHOD */
	/* ------------------- */
	php_onscript_method(h,fptr);

	/* ------------------- */
	/*  PHP ON SHOW METHOD */
	/* ------------------- */
	php_hide_methods(h,fptr);
	php_show_methods(h,fptr);
	php_onshow_method(h,fptr);

	/* ------------------- */
	/*  PHP EVENT METHODS  */
	/* ------------------- */
	php_event_methods(h,fptr);

	/* ------------------- */
	/*  PHP LOSE  METHODS  */
	/* ------------------- */
	php_lose_methods(h,fptr);

	/* -------------------- */
	/*  PHP ONMETHOD METHOD */
	/* -------------------- */
	php_onmethod_method(h,fptr);

	php_open_method(h,"OnFocus($psn)");
	php_close_method(h);
	php_open_method(h,"OnLoseFocus($psn)");
	php_close_method(h);

	/* ------------------ */
	/* PHP ON HIDE METHOD */
	/* ------------------ */
	php_open_method(h,"OnHide($psn)");

	for (	iptr=fptr->last;
		iptr != (struct form_item *) 0;
		iptr = iptr->previous) 
	{
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if ( iptr->Contents.style == _DATA_FRAME ) 
		{
			continue;
		}
		else if (!( method_is_valid( iptr->Contents.events->on_hide ) )) 
		{
			fprintf(h,"\t\t$this->%s->OnHide($psn.%c_%s%c);\n",
				php_widget_name(iptr),__QUOTE,
				php_widget_name(iptr),__QUOTE);
		}
		else	
		{
			indent(h,2);
			fprintf(h,"$this->%sHide($psn);",
				php_widget_name(iptr));
			linefeed(h);
		}
	}

	if (!( fptr->pages ))
	{
		if ( fptr->isdynamic ) 
		{
			if ( is_valid_string( fptr->extends ))
				fprintf(h,"\t\t%s::OnHide($psn.\"_%s\");\n",fptr->extends,fptr->extends);
			else	fprintf(h,"\t\tvisual_form::OnHide($psn);\n");
		}
		else if ( is_valid_string( fptr->extends ))
			fprintf(h,"\t\t%s::OnHide($psn.\"_%s\");\n",fptr->extends,fptr->extends);
	}
	else
	{
		if ( fptr->isdynamic ) 
		{
			if ( is_valid_string( fptr->extends ))
				fprintf(h,"\t\t%s::OnHide($psn.\"_%s\");\n",fptr->extends,fptr->extends);
			else	fprintf(h,"\t\tvisual_paged_form::OnHide($psn);\n");
		}
		else if ( is_valid_string( fptr->extends ))
			fprintf(h,"\t\t%s::OnHide($psn.\"_%s\");\n",fptr->extends,fptr->extends);
	}

	php_close_method(h);


	/* -------------------- */
	/*  PHP ONREMOVE METHOD */
	/* -------------------- */
	php_onremove_method(h,fptr);
	return;
}


/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
public  void	export_php_page( FILE * h )
{
	return;
}

/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
public  void	export_php_web_service( FILE * h )
{
	return;
}

#include "wsdlform.c"
#include "soapform.c"

/*	-----------------------------------	*/
/*	PHP / SOAP / WEB SERVICE PRODUCTION	*/
/*	-----------------------------------	*/
public  int	php_soap_method_name( FILE * h, int count, char * rname)
{
	if (!( count++ ))
		fprintf(h,"\n\t\t%ctns:%sResponse%c=>0",__QUOTE,rname,__QUOTE);
	else	fprintf(h,",\n\t\t%ctns:%sResponse%c=>0",__QUOTE,rname,__QUOTE);
	return(count);
}


/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
/*	----------------------------------------------------------	*/
public  int	php_soap_method_array( FILE * h, struct form_control * fptr, char * rname, int count )
{
	struct	form_item 	* iptr;
	struct	form_control 	* ffptr;
	char			* fnptr;
	char	nbuffer[8192];

	sprintf(nbuffer,"%s_%s_%s",rname,"On","Show");
	count = php_soap_method_name(h,count,nbuffer);
	sprintf(nbuffer,"%s_%s_%s",rname,"On","Event");
	count = php_soap_method_name(h,count,nbuffer);
	sprintf(nbuffer,"%s_%s_%s",rname,"On","Hide");
	count = php_soap_method_name(h,count,nbuffer);
	sprintf(nbuffer,"%s_%s_%s",rname,"On","Losefocus");
	count = php_soap_method_name(h,count,nbuffer);
	sprintf(nbuffer,"%s_%s_%s",rname,"On","Focus");
	count = php_soap_method_name(h,count,nbuffer);

	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if (method_is_valid( iptr->Contents.events->on_create ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,php_widget_name(iptr),"Create");
			count = php_soap_method_name(h,count,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_show ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,php_widget_name(iptr),"Show");
			count = php_soap_method_name(h,count,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_get_focus ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,php_widget_name(iptr),"Focus");
			count = php_soap_method_name(h,count,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_lose_focus ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,php_widget_name(iptr),"LoseFocus");
			count = php_soap_method_name(h,count,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_event ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,php_widget_name(iptr),"Event");
			count = php_soap_method_name(h,count,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_hide ) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,php_widget_name(iptr),"Hide");
			count = php_soap_method_name(h,count,nbuffer);
			}
		if (method_is_valid( iptr->Contents.events->on_remove) ) {
			sprintf(nbuffer,"%s_%s_%s",rname,php_widget_name(iptr),"Remove");
			count = php_soap_method_name(h,count,nbuffer);
			}
		if ( iptr->Contents.style != _DATA_FRAME )
			continue;
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	{
			sprintf(nbuffer,"%s_%s",rname,php_widget_name(iptr));
			count = php_soap_method_array(h,ffptr,nbuffer,count);
			continue;
			}
		}
	return(count);
}

/*	----------------------------------------------------------	*/
/*		    p h p _ wi d g e t _ s t y l e			*/
/*	----------------------------------------------------------	*/
/*	generates a single style class derivation of the default	*/
/*	visual style base class.					*/
/*	----------------------------------------------------------	*/
private	int	php_widget_style( FILE * h, char * nptr )
{
	struct	element_style * eptr;
	struct	element_style * fptr;
	char * rptr;
	char * aptr;
	php_open_exclusion( h, nptr );
	php_extends( h, nptr,"visual_style" );
	php_open_method(h,"OnStyle($psn)");


	/* -------------------------------------- */
	/* locate style and generate details here */
	/* -------------------------------------- */
	if ((eptr = resolve_style_class( nptr )) != (struct element_style *) 0)
	{
		/* ------------------------------------------------------- */
		/* elaborate on style with conversion to CSS 1.0, 2.0, 3.0 */
		/* bearing in mind that the widget identitity provides the */
		/* positional and dimesnional information and is priority  */
		/* ------------------------------------------------------- */
		fptr = allocate_for_style();
		if (( rptr = generate_css_class( eptr, fptr )) != (char *) 0)
			fprintf(h,"\tprint(\"%s\");\n",rptr);
		else
		{
			fprintf(h,"\tprint ('.%s {\\n');\n",nptr);
			fprintf(h,"\tprint ('}\\n');\n");
		}
		liberate_style( fptr );
	}
	else
	{
		fprintf(h,"\tprint ('.%s {\\n');\n",nptr);
		fprintf(h,"\tprint ('}\\n');\n");

	}

	php_close_method(h);
	php_endclass( h, nptr );
	php_close_exclusion( h, nptr );

	if ((eptr) && ( method_is_valid((aptr = get_element_alias( eptr ))) ))
		add_php_aliases( h, aptr );

	return(0);
}

/*	----------------------------------------------------------	*/
/*		    p h p _ h a n d l e _ s t y l e			*/
/*	----------------------------------------------------------	*/
/*	generates the style classes inclusion file for to provide	*/
/*	style for the current form.					*/
/*	This is in all a complex operation which involves the 		*/
/*	generation of the different style information as individual	*/
/*	style class derivations of the base class visual style.		*/
/*	This is to be performed for each individual style class used	*/
/*	Then instances of the used classes are to be generated and	*/
/*	constructed and finally they will be invoked during the 	*/
/*	standard OnStyle invocation cycle.				*/
/*	----------------------------------------------------------	*/
private	int	php_handle_style( FILE * h, struct form_control * fptr )
{
	FILE *	hh;
	char *	nptr;
	struct	form_item * iptr;
	int	items=0;

	for ( 	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if (!( method_is_valid( iptr->Contents.stylesheet ) ))
			continue;
		else	items++;
	}
	if (!( items ))	
		return(0);
	else if (!( nptr = allocate_string( fptr->prodname )))
		return(0);
	else if (!( nptr = enforce_extension( nptr, ".ins" )))
		return(0);
	else if (!( hh = open_production_target( nptr, 0 ) ))
	{
		liberate( nptr );
		return(0);
	}
	else
	{
		php_start( hh );
		if ( method_is_valid(  fptr->clearscreen ) )
			add_php_styles( hh, fptr->clearscreen );
		for ( 	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )
		{
			if (!( method_is_valid( iptr->Contents.stylesheet ) ))
				continue;
			switch ((iptr->Contents.style & _FRAME_TYPE))
			{
			case	_FORM_FRAME	:
				add_php_form_styles( hh, iptr->Contents.stylesheet );
				break;
			case	_SCROLL_FRAME	:
				add_php_scroll_styles( hh, iptr->Contents.stylesheet );
				break;
			case	_SELECT_FRAME	:
			case	_SWITCH_FRAME	:
			case	_RADIO_FRAME	:
				add_php_select_styles( hh, iptr->Contents.stylesheet );
				break;
			case	_CHECK_FRAME	:
			default			:
				add_php_styles( hh, iptr->Contents.stylesheet );
			}
		}
		php_end( hh );
		close_production_target(hh,nptr);
		php_require(h,nptr);
		liberate( nptr );
		return(items);
	}
}

/*	----------------------------------------------------------	*/
/*			e x p o r t _ p h p _ f o r m			*/
/*	----------------------------------------------------------	*/
/*	called from the top level production routiens to generate	*/
/*	a php form.							*/
/*	----------------------------------------------------------	*/
public  void	export_php_form( FILE * h, int webagent, char * soaphost, int restriction, int contextual, int autotrad, char * prodname )
{
	FILE			*hh;
	int			withstyle=0;
	char		     	* eptr;
	char			* nptr;
	char			* pptr;
	char			* wsdlptr;
	char			* abalptr;
	char			* fnptr;
	struct	form_control 	* fptr;
	struct	forms_method 	* mptr;
	struct	form_item 	* iptr;
	struct	form_item 	* wptr;
	FILE			* hptr;
	int	i;
	int	isoverlay;


	if (!( fptr = Context.Form ))
		return;
	else if (!( fptr->identifier ))
		return;
	else if (!( nptr = allocate_string( fptr->identifier )))
		return;
	else if (!( pptr = allocate_string( fptr->identifier )))
		return;
	else if (!( wsdlptr = allocate_string( fptr->identifier )))
		return;
	else if (!( abalptr = allocate_string( fptr->identifier )))
		return;
	else if (!( pptr = enforce_extension( pptr, PHP_EXTENSION )))
		return;
	else if (!( nptr = enforce_extension( nptr, INC_EXTENSION )))
		return;
	else if (!( wsdlptr = enforce_extension( wsdlptr, WSDL_EXTENSION )))
		return;
	else if (!( abalptr = enforce_extension( abalptr, AS_EXTENSION )))
		return;

	/* force form conditions */
	/* --------------------- */
	set_abal_config_overlay(fptr->isoverlay);
	set_abal_config_program(fptr->isprogram);
	fptr->abal.flags |= 16;
	abal_function_methods( fptr );

	/* Generate Form Instance Page */
	/* --------------------------- */
	php_start( h );

	/* ---------------------------- */
	/* global command line handling */
	/* ---------------------------- */
	php_session( h, "command_line" );
	fprintf(h,"\tif (!( isset($_SESSION['COMMANDLINE'] ))) { $commandLine = NULL; }\n");
	fprintf(h,"\telse { $commandLine = $_SESSION['COMMANDLINE'];  unset($_SESSION['COMMANDLINE'] ) ;}\n");
	fprintf(h,"\tsession_commit();\n");

	/* --------------------------- */
	/* local command line handling */
	/* --------------------------- */
	php_session( h, fptr->identifier );
	php_require(h,nptr);
	fprintf(h,"\tif (!( ltrim($commandLine) )) { if (isset( $_SESSION['COMMANDLINE'])){ $commandLine = $_SESSION['COMMANDLINE']; } else { $commandline =\"\";}}\n");
	fprintf(h,"\telse { $_SESSION['COMMANDLINE'] = $commandLine; }\n");

	/* --------------------------- */
	/* event command line handling */
	/* --------------------------- */
	fprintf(h,"\tif (!( ltrim($commandLine) )) { if (isset( $_REQUEST['COMMANDLINE'])){ $commandLine = $_REQUEST['COMMANDLINE']; } else { $commandline =\"\";}}\n");

	/* ------------------------ */
	/* instance document object */
	/* ------------------------ */
	if (!( fptr->isdynamic )) {
		fprintf(h,"\n\t$i%s = new %s($commandLine);\n",fptr->identifier,fptr->identifier);
		fprintf(h,"\t$i%s->pagecount = %u;\n",fptr->identifier,fptr->pages);
		}
	else if (!( fptr->pages )) {
		fprintf(h,"\n\t$i%s = new %s(0,0,800,600,$commandLine);\n",fptr->identifier,fptr->identifier);
		}
	else	{
		fprintf(h,"\n\t$i%s = new %s(0,0,800,600,%u,$commandLine);\n",fptr->identifier,fptr->identifier,fptr->pages);
		}

	fprintf(h,"\t$document = new html_document;\n");

	if ( method_is_valid(  fptr->clearscreen ) )
		fprintf(h,"\t$document->bodyStyle = %c%s%c;\n",0x0022,fptr->clearscreen,0x0022);

	/* scan to locate the window widget */
	/* -------------------------------- */
	for (	wptr=(struct form_item*) 0,
		iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		if ((iptr->Contents.style & _FRAME_TYPE) == _WINDOW_FRAME) {
			wptr = iptr;
			break;
			}
		}
	/* use the window title as the document title */
	/* ------------------------------------------ */
	if ( wptr )
	{
		fprintf(h,"\t$document->title = ");
		php_object_payload(h,wptr,fptr->identifier);
		fprintf(h,";\n");
	}
	fprintf(h,"\t$document->generator = %c%s%c;\n",0x0022,"Sing Php Generator",0x0022);
	fprintf(h,"\t$document->version   = %cVersion %s%c;\n",0x0022,getpatternversion(),0x0022);

	if ((SoapAgent = webagent) != 0) {

		if (!( soaphost )) 
			soaphost = "http://127.0.0.1:8088";
		else if ( *soaphost == '$' )
			if (!( soaphost = getenv( (soaphost+1) ) ))
				soaphost = "http://127.0.0.1:8088";

		open_server_description(fptr,0);
		php_generate_wsdl( fptr, soaphost, wsdlptr );
		close_server_description();
		if (!( soaphost ))
			fprintf(h,"\t$wsdlname = \"%s\";\n",wsdlptr);
		else if ( *wsdlptr == '/' )
			fprintf(h,"\t$wsdlname = \"%s%s\";\n",soaphost,wsdlptr);
		else	fprintf(h,"\t$wsdlname = \"%s/%s\";\n",soaphost,wsdlptr);

		fprintf(h,"\t$soapmethods = array(");
		php_soap_method_array( h, fptr, fptr->identifier, 0 );		
		fprintf(h,");\n");
		fprintf(h,"\t$soapclient = new SingSoapClient($wsdlname,$soapmethods);\n");
		fprintf(h,"\t$soapclient->cookieValue = $_SESSION['COOKIE'];\n");
		fprintf(h,"\t$soapclient->ownerClass = %c%s%c;\n",__QUOTE,fptr->identifier,__QUOTE);
		fprintf(h,"\t$i%s->OnClient($soapclient);\n",fptr->identifier);
		}	

	fprintf(h,"\t$i%s->OnRequest(%c%s%c,$_REQUEST);\n",fptr->identifier,__QUOTE,fptr->identifier,__QUOTE);
	fprintf(h,"\t$i%s->OnCreate(%c%s%c);\n",fptr->identifier,__QUOTE,fptr->identifier,__QUOTE);
	fprintf(h,"\t$i%s->OnMethod(%c%s%c,$_REQUEST);\n",fptr->identifier,__QUOTE,fptr->identifier,__QUOTE);
	if ( SoapAgent ){
		fprintf(h,"\t$_SESSION['COOKIE'] = $soapclient->cookieValue;\n");
		}
	fprintf(h,"\t$document->OnHead();\n");
	if ( contextual ) {
		fprintf(h,"\t$document->OnScript();\n");
		fprintf(h,"\t$document->inhibitMenu();\n");
		fprintf(h,"\t$document->CloseScript();\n");
		}
	fprintf(h,"\t$document->OnBody();\n");

	if (!( fptr->formflags & _FORM_DEFAULT ))
	{
		fprintf(h,"\t$document->OpenForm(%c%s%c,%c%s%c);\n",
			__QUOTE,"POST",__QUOTE,
			__QUOTE,pptr,__QUOTE);
	}
	else
	{
		fprintf(h,"\t$document->OpenTargetForm(%c%s%c,%c%s%c,%c%s%c);\n",
			__QUOTE,"POST",__QUOTE,
			__QUOTE,pptr,__QUOTE,
			__QUOTE,"_top",__QUOTE);
	}

	fprintf(h,"\t\t$i%s->OnShow(%c%s%c);\n",fptr->identifier,__QUOTE,fptr->identifier,__QUOTE);
	fprintf(h,"\t\t$i%s->OnHide(%c%s%c);\n",fptr->identifier,__QUOTE,fptr->identifier,__QUOTE);
	fprintf(h,"\t$i%s->OnRemove();\n",fptr->identifier);
	fprintf(h,"\t$document->CloseForm();\n");
	fprintf(h,"\t$document->OnStyle();\n");
		fprintf(h,"\t\t$i%s->OnStyle(%c%s%c);\n",fptr->identifier,__QUOTE,fptr->identifier,__QUOTE);
	fprintf(h,"\t$document->CloseStyle();\n");
	fprintf(h,"\t$document->OnScript();\n");
		fprintf(h,"\t\t$i%s->OnScript(%c%s%c);\n",fptr->identifier,__QUOTE,fptr->identifier,__QUOTE);
	fprintf(h,"\t$document->CloseScript();\n");
	fprintf(h,"\t$document->OnFoot();\n");
	php_end( h );
	close_production_target(h,prodname);

	if ( SoapAgent ) {
		php_generate_abal( fptr, soaphost, abalptr );
		/* php_translate_abal( fptr, abalptr, autotrad ); */
		}

	/* We dont need H the original handle any more */
	/* ------------------------------------------- */
	if (!( h = open_production_target(nptr,0))) {
		liberate( nptr );
		return;
		}
	else	{
		initialise_php_requires();
		initialise_php_styles();
		php_start( h );
		php_require(h,"sing/html.inc");
		php_require(h,"sing/http.inc");
		php_require(h,"sing/soaparser.inc");
		php_require(h,"sing/soapclient.inc");
		php_require(h,"sing/visual.inc");
		if (((mptr = php_detect_forms_method( fptr, "NoPdoMySql" )) != (struct forms_method *) 0)
		||  ((mptr = php_detect_forms_method( fptr, "StdMySql" )) != (struct forms_method *) 0))
			php_require(h,"sing/mysql.inc");
		
		if ( is_valid_string( fptr->extends) )
			if (( fnptr = allocate_string( fptr->extends )) != (char *) 0)
				if (( fnptr = enforce_extension( fnptr, ".inc" )) != (char *) 0)
					add_php_require(h,fnptr);

		php_component_requires(h,fptr);
		php_open_exclusion( h, fptr->identifier );
		withstyle = php_handle_style( h, fptr );
		if ( is_valid_string( fptr->extends ) )
			php_extends( h, fptr->identifier,fptr->extends );
		else if ( fptr->pages )
			php_extends( h, fptr->identifier,"visual_paged_form" );
		else	php_extends( h, fptr->identifier,"visual_form" );
		php_instance_labels(h,fptr);
		php_instance_hints(h,fptr);
		php_instance_globals(h,fptr);
		php_instance_style(h);
		php_instance_widgets(h,fptr);
		php_instance_members(h,fptr);
		php_instance_methods(h,fptr);
		php_interface_methods(h,fptr);

		php_endclass( h, fptr->identifier );
		php_close_exclusion( h, fptr->identifier );
		php_end( h );
		liberate_php_styles();
		liberate_php_requires();
		close_production_target(h,nptr);
		liberate( nptr );
		return;
		}	
}

#endif	/* _phpform_c */
	/* ---------- */


