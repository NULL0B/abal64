#ifndef	_singdhtm_c
#define	_singdhtm_c

private	char *	html_dynamic_extra(char * xptr, char * sptr )
{
	char *	rptr;
	if (!( sptr ))
		return( xptr );
	else if (!( xptr ))
		return( allocate_string( sptr ) );
	else if (!( rptr = allocate( strlen( xptr ) + strlen( sptr ) + 16 )))
		return( xptr );
	else	{
		sprintf(rptr,"%s %s",xptr,sptr);
		liberate( xptr );
		return( rptr );
		}
}

private	char *	html_dynamic_rgb_colour( char * extra , int colourid )
{
	int	rvalue=0;
	int	gvalue=0;
	int	bvalue=0;
	char	travail[64];
	get_rgb_values(colourid,&rvalue,&gvalue,&bvalue );
	sprintf(travail,"#%02.2X%02.2X%02.2X;",(rvalue&0x00FF),(gvalue&0x00FF),(bvalue&0x00FF));
	extra = html_dynamic_extra( extra, travail );
	return( extra );
}

private	char *	html_dynamic_colours(char * extra ,int fg, int bg  )
{
	extra = html_dynamic_extra(extra,"color:");
	extra = html_dynamic_rgb_colour(extra,fg);
	if ( bg ) {
		extra = html_dynamic_extra(extra,"background-color:");
		extra = html_dynamic_rgb_colour(extra,bg);
		}
	return( extra );
}

private	char *	html_dynamic_text_style(char * extra , struct form_item * iptr,int fg, int bg  )
{
	if ( iptr->Contents.align & _A_BOLD )
		extra = html_dynamic_extra(extra,"font-weight: bold;");

	if ( iptr->Contents.align & _A_SHADOW )
		extra = html_dynamic_extra(extra,"font-style: italic;");

	if ( iptr->Contents.align & _A_LINE )
		extra = html_dynamic_extra(extra,"text-decoration: underline;");

	extra = html_dynamic_extra(extra,"vertical-align: middle;");
	extra = html_dynamic_extra(extra,"text-align:");

	switch ( iptr->Contents.align & 7 ) {
		case	1 :	extra = html_dynamic_extra(extra,"right;"); break;
		case	2 :	extra = html_dynamic_extra(extra,"left;"); break;
		case	3 :	extra = html_dynamic_extra(extra,"center;"); break;
		case	4 :	extra = html_dynamic_extra(extra,"justify;"); break;
		default	  : 	extra = html_dynamic_extra(extra,"none;"); break;
		}

	extra = html_dynamic_colours( extra, fg, bg );
	

	return( extra );
}

private	void	html_reset_dynamic_margins(FILE * h)
{
	fprintf(h,"\tbugAbsolute=1;");
	linefeed(h);
	fprintf(h,"\tlmargin=0;");
	linefeed(h);
	fprintf(h,"\ttmargin=0;");
	linefeed(h);
	return;
}

private	void	html_reset_microsoft_margins(FILE * h)
{
	fprintf(h,"if (navigator.appName.indexOf('Microsoft') > -1) {");
	linefeed(h);
	html_reset_dynamic_margins(h);
	fprintf(h,"\t}");
	linefeed(h);
	fprintf(h,"else if (navigator.userAgent.indexOf('Firefox/9.9') > -1) {");
	linefeed(h);
	html_reset_dynamic_margins(h);
	fprintf(h,"\t}");
	linefeed(h);
	fprintf(h,"else { bugAbsolute=0; }");
	linefeed(h);
	return;
}

private	void	html_dynamic_table_style( FILE * handle,struct form_item * iptr )
{
	int	atx;
	int	aty;
	int	nby;
	int	nbx;
	int		bytes=0;
	char	*	sptr;
	int		i;
	int		n;
	int		mode=0;
	int		xfi=0;
	int		f=0;
	int		fields=0;
	int		fieldwidth[_MAX_FORM_FIELDS];
	int		linelength=0;
	int		nblines=0;
	int		fw;
	int		fh;
	int		jsevent=0;
	char *	extra=(char *) 0;
	
	if ((iptr->Contents.style & _FRAME_TYPE) != _FORM_FRAME)
		return;

	calculate_edit_size( &iptr->Contents );
	calculate_form_lines( iptr, &linelength, &nblines );

	if (!( fields = calculate_form_fields(iptr,fieldwidth,_MAX_FORM_FIELDS,linelength) ))
		return;

	fw = guifontsize(iptr->Contents.font);
	fh = (fw >> 8); fw &= 0x00FF;	

	nby = html_scale_quantity( (iptr->Contents.h/nblines) );
	nby--; /* for frame */

	/* ----------------------------------- */
	/* Generation of the Table Cell Styles */
	/* ----------------------------------- */
	aty  = html_scale_quantity(iptr->Contents.y);
	atx  = html_scale_quantity(iptr->Contents.x);
	for ( i=0; i < fields; i++ ) {
		nbx = html_scale_quantity( fieldwidth[i]*fw);
		fprintf(handle,"wx=(lmargin+%u);",atx);
		fprintf(handle,"wy=(tmargin+%u);",aty);
		fprintf(handle,"Widget(%c",__QUOTE);
		fprintf(handle,"%s%u",iptr->Contents.name,i+1);
		fprintf(handle,"%c,%s",__QUOTE,"tabletitle");
		fprintf(handle,",wx,wy,%u,%u,%c%s%c",nbx,nby,__QUOTE,_metrics,__QUOTE);
		fprintf(handle,",%c background-color: navy; color: yellow;%c);",__QUOTE,__QUOTE);
		linefeed(handle);
		atx += nbx;
		}
	aty = html_scale_quantity(iptr->Contents.y);
	for ( n=0; n < nblines; n++ ) {
		aty += (nby+1);
		atx  = html_scale_quantity(iptr->Contents.x);
		for ( i=0; i < fields; i++ ) {
			nbx = html_scale_quantity( fieldwidth[i]*fw);
			fprintf(handle,"wx=(lmargin+%u);",atx);
			fprintf(handle,"wy=(tmargin+%u);",aty);
			fprintf(handle,"Widget(%c",__QUOTE);
			fprintf(handle,"%s%u_%u",iptr->Contents.name,i+1,n+1);
			fprintf(handle,"%c,%s",__QUOTE,"tablecell",__QUOTE);
			fprintf(handle,",wx,wy,%u,%u,%c%s%c",nbx,nby,__QUOTE,_metrics,__QUOTE);
			switch ( iptr->Contents.align & 0x0007 ) {
				case	0	: 
					fprintf(handle,",%c background-color: #FFFFFF; color: black;%c);",__QUOTE,__QUOTE); 
					break;
				case	1	: 
					if ( n & 1 )
						fprintf(handle,",%c background-color: #DDDDDD; color: navy;%c);",__QUOTE,__QUOTE);
					else	fprintf(handle,",%c background-color: #CCCCCC; color: navy;%c);",__QUOTE,__QUOTE);
					break;
				case	2	:
					extra = (char *) 0;
					extra = html_dynamic_rgb_colour( extra, iptr->Contents.colour & 0x00FF);
					fprintf(handle,",%c background-color: %s",__QUOTE,extra);
					liberate( extra ); extra = (char *) 0;
					extra = html_dynamic_rgb_colour( extra, ((iptr->Contents.colour & 0xFF00) >> 8));
					fprintf(handle," color: %s%c);",extra,__QUOTE);
					liberate( extra ); extra = (char *) 0;
					break;
				case	3	:
					if( n & 1 )  {
						extra = (char *) 0;
						extra = html_dynamic_rgb_colour( extra, iptr->Contents.colour & 0x00FF);
						fprintf(handle,",%c background-color: %s",__QUOTE,extra);
						liberate( extra ); extra = (char *) 0;
						extra = html_dynamic_rgb_colour( extra, ((iptr->Contents.colour & 0xFF00) >> 8));
						fprintf(handle," color: %s%c);",extra,__QUOTE);
						liberate( extra ); extra = (char *) 0;
						}
					else	{
						extra = (char *) 0;
						extra = html_dynamic_rgb_colour( extra, iptr->Contents.colour & 0x00FF);
						fprintf(handle,",%c color: %s",__QUOTE,extra);
						liberate( extra ); extra = (char *) 0;
						extra = html_dynamic_rgb_colour( extra, ((iptr->Contents.colour & 0xFF00) >> 8));
						fprintf(handle," background-color: %s%c);",extra,__QUOTE);
						liberate( extra ); extra = (char *) 0;
						}
					break;

				default		: 
					fprintf(handle,",%c %c);",__QUOTE,__QUOTE);
					break;
				}
			linefeed(handle);
			atx += nbx;
			}
		}
	linefeed(handle);
	return;
}

private	void	html_dynamic_widget_style( FILE * h, struct form_item * iptr,int mode)
{
	char	*	extra=(char *) 0;
	int		fg;
	int		bg;
	struct window_control Widget;

	html_widget_scale(iptr,&Widget,mode);

	fg = (iptr->Contents.colour & 0x00FF);
	bg = ((iptr->Contents.colour & 0xFF00) >> 8);

	/* -------------------------------------- */
	/* Adjust dimensions wrt widget component */
	/* -------------------------------------- */
	switch (( iptr->Contents.style & _FRAME_TYPE )) {
		case	_SCROLL_FRAME	:
			switch ( mode ) {
				case	0 :
					Widget.h -= (Widget.w *2);
					Widget.y += Widget.w;
					break;
				case	1 :
					Widget.h = Widget.w;
					break;
				case	2 :
					Widget.y += (Widget.h-Widget.w);
					Widget.h = Widget.w;
					break;
				}
			break;
		case	_RADIO_FRAME	:
		case	_CHECK_FRAME	:
			switch ( mode ) {
				case	0 : Widget.w = Widget.h; break;
				case	1 :
					Widget.x += (Widget.h*2);
					Widget.w -= (Widget.h*2);
				}
			break;
		}

	if (!( mode )) {
		fprintf(h,"wx=(lmargin+%u);",Widget.x);
		fprintf(h,"wy=(tmargin+%u);",Widget.y);
		}
	else	{
		switch (( iptr->Contents.style & _FRAME_TYPE )) {
			case	_BUTTON_FRAME	:
				if ( iptr->Contents.align & 1 ) {
					fprintf(h,"if ( bugAbsolute > 0 ) { wx=0; wy=0; }");
					linefeed(h);
					fprintf(h,"else { wx=(lmargin+%u); wy=(tmargin+%u); }",Widget.x,Widget.y);
					linefeed(h);
					break;
					}	
			default			:
				fprintf(h,"wx=(lmargin+%u);",Widget.x);
				fprintf(h,"wy=(tmargin+%u);",Widget.y);
				linefeed(h);
			}
		}

	fprintf(h,"Widget(%c",__QUOTE);

	/* --------------------- */
	/* Widget Component Name */
	/* --------------------- */
	switch (( iptr->Contents.style & _FRAME_TYPE )) {

		case	_SCROLL_FRAME	:
			switch ( mode ) {
				case	0 : fprintf(h,"%sBar",iptr->Contents.name); 	break;
				case	1 : fprintf(h,"%sUp",iptr->Contents.name); 	break;
				case	2 : fprintf(h,"%sDown",iptr->Contents.name); 	break;
				}
			break;

		case	_RADIO_FRAME	:

			switch ( mode ) {
				case 0 : fprintf(h,"%s%u",iptr->Contents.name,iptr->Contents.radio);  		 break;
				case 1 : fprintf(h,"label%s%u",iptr->Contents.name,iptr->Contents.radio); 	 break;
				}
			break;

		case	_CHECK_FRAME	:

			switch ( mode ) {
				case 0 : fprintf(h,"%s",iptr->Contents.name);  		 break;
				case 1 : fprintf(h,"label%s",iptr->Contents.name);	 break;
				}

			break;

		case	_TAB_FRAME	:

			switch ( mode ) {
				case 0 : fprintf(h,"%s",iptr->Contents.name); 		break;
				case 1 : fprintf(h,"%sPage",iptr->Contents.name); 	break;
				}
			break;

		case	_BUTTON_FRAME	:
			if ( iptr->Contents.align & 1 ) {
				if ( mode ) {
					fprintf(h,"%sData",iptr->Contents.name);
				 	break;
					}
				}
			fprintf(h,"%s",iptr->Contents.name);
			break;
		case	_WINDOW_FRAME	:
			if (!( mode ))
				fprintf(h,"%s"   ,iptr->Contents.name);
			else	fprintf(h,"%sbis",iptr->Contents.name);
			break;

		default			:
			fprintf(h,"%s",iptr->Contents.name);
		}

	fprintf(h,"%c,",__QUOTE);

	/* ---------------------- */
	/* Widget Component Class */
	/* ---------------------- */
	switch (( iptr->Contents.style & _FRAME_TYPE )) {
		case	_TAB_FRAME	:
			switch ( mode ) {
				case	0 :
					if ( iptr->Contents.page != HtmlPageNumber )
						fprintf(h,"buttonframe");
					else	fprintf(h,"buttonfocus");
					break;
				case	1 :
					fprintf(h,"pageframe");
					break;
				}
			break;

		case	_BUTTON_FRAME	:
			if ( iptr->Contents.align & 1 ) {
				fprintf(h,"iconframe");
				}
			else if (!( iptr->Contents.align & 2)) {
				fprintf(h,"buttonframe");
				}
			else	{
				fprintf(h,"textfont%u",iptr->Contents.font);
				extra = html_dynamic_colours(extra,fg,bg);
				}
								
			extra = html_dynamic_extra(extra, "vertical-align: middle;");
			break;

		case	_EDIT_FRAME	:
			fprintf(h,"editframe");

			if (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS ))
				extra = html_dynamic_text_style(extra,iptr,fg,bg);
			break;

		case	_TEXT_FRAME	:
			fprintf(h,"textfont%u",iptr->Contents.font);
			extra = html_dynamic_text_style(extra,iptr,fg,bg);
			break;

		case	_OUTSET_FRAME	:
			fprintf(h,"outsetframe");
			break;

		case	_INSET_FRAME	:
			fprintf(h,"insetframe");
			break;
		case	_RIDGE_FRAME	:
			fprintf(h,"ridgeframe");
			break;

		case	_GROOVE_FRAME	:
			fprintf(h,"grooveframe");
			break;

		case	_FORM_FRAME	:
			fprintf(h,"tableframe");
			break;

		case	_WINDOW_FRAME	:
			fprintf(h,"windowframe");
			break;

		case	_CHECK_FRAME	:
			switch ( mode ) {
				case	0 : fprintf(h,"checkframe"); break;
				case	1 : fprintf(h,"checklabel"); break;
				}
			break;

		case	_RADIO_FRAME	:
			switch ( mode ) {
				case	0 : fprintf(h,"radioframe"); break;
				case	1 : fprintf(h,"radiolabel"); break;
				}
			break;

		case	_SWITCH_FRAME	:
			fprintf(h,"switchframe");
			break;

		case	_SCROLL_FRAME	:
			switch ( mode ) {
				case	0 : fprintf(h,"scrollbar"); 	break;
				case	1 : 
				case	2 : fprintf(h,"scrollbutton"); 	break;
				}
			break;
		default			:
			fprintf(h,"%c %c",__QUOTE,__QUOTE);
			break;

		}


	/* ---------------------------------------- */
	/* Widget Component Position and Dimensions */
	/* ---------------------------------------- */
	if ((iptr->Contents.style & _FRAME_TYPE) != _WINDOW_FRAME )
		fprintf(h,",wx,wy,%u,%u,%c%s%c",Widget.w,Widget.h,__QUOTE,_metrics,__QUOTE);
	else if (!( mode ))
		fprintf(h,",wx,wy,%u,%u,%c%s%c",Widget.w,24,__QUOTE,_metrics,__QUOTE);
	else	fprintf(h,",wx,wy+24,%u,%u,%c%s%c",Widget.w,Widget.h,__QUOTE,_metrics,__QUOTE);

	/* --------------------------- */
	/* Widget Component Supplement */
	/* --------------------------- */
	if ( extra ) {
		fprintf(h,",%c %s%c);",__QUOTE,extra,__QUOTE);
		liberate( extra );
		}
	else	fprintf(h,",%c %c);",__QUOTE,__QUOTE);
	linefeed(h);

	return;
}

private	void	html_widget_dynamic( FILE * h, struct form_item * iptr)
{

	html_dynamic_widget_style(h,iptr,0);

	switch (( iptr->Contents.style & _FRAME_TYPE )) {
		case	_FORM_FRAME	:
			html_dynamic_table_style(h,iptr);
			break;
		case	_BUTTON_FRAME	:
			if ( iptr->Contents.align & 1 )
				html_dynamic_widget_style(h,iptr,1);
			break;
		case	_TAB_FRAME	:
			html_dynamic_widget_style(h,iptr,1);
			break;
		case	_CHECK_FRAME	:
			html_dynamic_widget_style(h,iptr,1);
			break;
		case	_RADIO_FRAME	:
			html_dynamic_widget_style(h,iptr,1);
			break;
		case	_SCROLL_FRAME	:
			html_dynamic_widget_style(h,iptr,1);
			html_dynamic_widget_style(h,iptr,2);
			break;
		case	_WINDOW_FRAME	:
			html_dynamic_widget_style(h,iptr,1);
			html_reset_microsoft_margins(h);
			break;

		}
	return;
}

private	void	html_form_dynamic_style( FILE * h, struct form_control * fptr, struct form_item * wptr)
{
	int	recalculate=0;
	struct window_control Widget;
	struct	form_item * iptr;

	if ( wptr ) {
		html_widget_scale(wptr,&Widget,0);
		linefeed(h);
		switch ( (wptr->Contents.align & 7) ) {
			case	0 :
			case	2 :
				html_reset_dynamic_margins(h);
				break;
			case	1 :

				fprintf(h,"if ( screen.width > %u) {",Widget.w);
				fprintf(h,"lmargin=(screen.width-%u); } else { lmargin=0; }",Widget.w);
				linefeed(h);
				fprintf(h,"if ( screen.height > %u) {",Widget.w);
				fprintf(h,"tmargin=(screen.height-%u); } else { tmargin=0; }",Widget.h);
				linefeed(h);
				break;
			default	:
				fprintf(h,"if ( screen.width > %u) { ",Widget.w);
				fprintf(h,"lmargin=((screen.width-%u)/2); } else { lmargin=0; }",Widget.w);
				linefeed(h);
				fprintf(h,"if ( screen.height > %u) { ",Widget.h);
				fprintf(h,"tmargin=((screen.height-%u)/4); } else { tmargin=0; }",Widget.h);
				linefeed(h);
				break;
			}

		}
	else	{
		html_reset_dynamic_margins(h);
		}

	fprintf(h,"document.write(%c<style>%c);",__QUOTE,__QUOTE);
	linefeed(h);
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;
		else if (iptr->Contents.events->xo_show & _EVENT_IS_COND )
			continue;
		else if ( is_file_Widget( iptr ) )
			continue;
		else if ((iptr->Contents.style & _FRAME_TYPE) == _LINE_FRAME)
			continue;
		else if (!( HtmlPageNumber ))
			html_widget_dynamic(h,iptr);
		else if (!( iptr->Contents.page ))
			html_widget_dynamic(h,iptr);
		else if (( iptr->Contents.style & _FRAME_TYPE) == _TAB_FRAME)
			html_widget_dynamic(h,iptr);
		else if ( iptr->Contents.page == HtmlPageNumber )
			html_widget_dynamic(h,iptr);
		}
	fprintf(h,"document.write(%c<%c+%c/style>%c);",__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	linefeed(h);

}


#endif  /* _singdhtm_c */
	/* ----------- */

