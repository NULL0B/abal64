#ifndef	_gencss_c
#define	_gencss_c

/*	-----------------------------------------------------------------	*/
/*	G e n e r a t i o n  o f  CSS S t y le    I n s t r u c t i o n s 	*/
/*	-----------------------------------------------------------------	*/
/*										*/
/*	This file provides functions fro the production of CSS from Style 	*/
/*										*/
/*	-----------------------------------------------------------------	*/

static	char	cssbuffer[1024];
static	char	cssresult[8192];

/*	-----------------------------------------------------------------	*/
/*			f l u s h _ c s s _ b u f f e r				*/
/*	-----------------------------------------------------------------	*/
/*	adds the current css srtring expression to the output buffer		*/
/*	-----------------------------------------------------------------	*/
private	void	flush_css_buffer()
{
	strcat( cssresult, cssbuffer );
	return;
}

/*	-----------------------------------------------------------------	*/
/*		g e n e r a t e _ c s s _ d i m e n s i o n			*/
/*	-----------------------------------------------------------------	*/
/*	generates a dimensioned element and value for any css expression 	*/
/*	that takes a standard pixeled or metric dimension type.			*/
/*	-----------------------------------------------------------------	*/
private	void	generate_css_dimension(   struct element_dimension * lptr, char * tptr )
{
	if (!( lptr->state & 1 ))
		return;
	else	{
		switch (lptr->type) {
			case _CELL_DIMENSION	:
				sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[ _keyword_cell ]);
				flush_css_buffer();
				break;
			case _TEXT_DIMENSION	:
				sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[ _keyword_text ]);
				flush_css_buffer();
				break;
			case _FIXED_DIMENSION	:
				sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[ _keyword_fixed ]);
				flush_css_buffer();
				break;
			case _AUTO_DIMENSION	:
				sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[ _keyword_auto ]);
				flush_css_buffer();
				break;
			default			:
				sprintf(cssbuffer," %s: %s; ",tptr,lptr->token);
				flush_css_buffer();
				break;
#ifdef	_no_dimension_token
			case	_PLUS_DIMENSION	:
				sprintf(cssbuffer," %s: %d+; ",tptr,lptr->value);
				flush_css_buffer();
				break;
			case	_PERCENT_DIMENSION	:
				sprintf(cssbuffer," %s: %d%c; ",tptr,lptr->value,0x0025);
				flush_css_buffer();
				break;
			case	_PIXEL_DIMENSION	:
				sprintf(cssbuffer," %s: %dpx; ",tptr,lptr->value);
				flush_css_buffer();
				break;
			case	_ELEMENT_DIMENSION	:
				sprintf(cssbuffer," %s: %del; ",tptr,lptr->value);
				flush_css_buffer();
				break;
			case	_IN_DIMENSION	:
				sprintf(cssbuffer," %s: %din; ",tptr,lptr->value);
				flush_css_buffer();
				break;
			case	_MM_DIMENSION	:
				sprintf(cssbuffer," %s: %dmm; ",tptr,lptr->value);
				flush_css_buffer();
				break;
			case	_CM_DIMENSION	:
				sprintf(cssbuffer," %s: %dcm; ",tptr,lptr->value);
				flush_css_buffer();
				break;
			case	_PT_DIMENSION	:
				sprintf(cssbuffer," %s: %dpt; ",tptr,lptr->value);
				flush_css_buffer();
				break;
			case	_PC_DIMENSION	:
				sprintf(cssbuffer," %s: %dpc; ",tptr,lptr->value);
				flush_css_buffer();
				break;
#endif
			}
		}
	return;
}

/*	-----------------------------------------------------------------	*/
/*		g e n e r a t e _ c s s _ p o s i t i o n			*/
/*	-----------------------------------------------------------------	*/
/*	generates the css position expression elements.				*/
/*	-----------------------------------------------------------------	*/
private	void	generate_css_position(  struct element_position * lptr )
{
	sprintf(cssbuffer," position: %s; ",_style_keyword[lptr->type]);
	flush_css_buffer();
	sprintf(cssbuffer," float: %s; ",_style_keyword[lptr->option]);
	flush_css_buffer();
	generate_css_dimension(  &lptr->top,"top" );
	generate_css_dimension(  &lptr->right,"right" );
	generate_css_dimension(  &lptr->bottom,"bottom" );
	generate_css_dimension(  &lptr->left,"left" );
	return;
}

/*	-----------------------------------------------------------------	*/
/*			g e n e r a t e _ c s s _ s i z e s			*/
/*	-----------------------------------------------------------------	*/
/*	generates the dimension elements for margins, paddings and border	*/
/*	-----------------------------------------------------------------	*/
private	void	generate_css_sizes(   struct element_sizes * lptr, char * tptr, char * xptr )
{
	char	tagbuffer[256];
	sprintf(tagbuffer,"%s%s",tptr,xptr);
	generate_css_dimension(  &lptr->top, tagbuffer );
	/*
	sprintf(tagbuffer,"%s-right%s",tptr,xptr);
	generate_css_dimension(  &lptr->right, tagbuffer );
	sprintf(tagbuffer,"%s-bottom%s",tptr,xptr);
	generate_css_dimension(  &lptr->bottom, tagbuffer );
	sprintf(tagbuffer,"%s-left%s",tptr,xptr);
	generate_css_dimension(  &lptr->left, tagbuffer );
	*/
	return;
}

/*	-----------------------------------------------------------------	*/
/*		g e n e r a t e _ c s s _ f r a m e _ i t e m			*/
/*	-----------------------------------------------------------------	*/
/*	generates a single border or frame element expression.				*/
/*	-----------------------------------------------------------------	*/
private	void	generate_css_frame_item(   int l, char * lptr, char * tptr, int value )
{
	if ( l == _keyword_url )
		sprintf(cssbuffer," %s: url(%s); ",tptr,lptr);
	else if ( l == _keyword_rounded )
		sprintf(cssbuffer," %s: %s(%u); ",tptr,_style_keyword[l],value);
	else	sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[l]);
	flush_css_buffer();
	return;
}

/*	-----------------------------------------------------------------	*/
/*			g e n e r a t e _ c s s _ f r a m e			*/
/*	-----------------------------------------------------------------	*/
/*	generates a complete css frame expression which may define corners	*/
/*	-----------------------------------------------------------------	*/
private	void	generate_css_frame(   struct element_frame * lptr, int value )
{
	if ( lptr->top != _keyword_url ) {
		generate_css_frame_item(  lptr->top, lptr->topimage, "border-style" , value);
		}
	else	{
		/* ---------------------------------------------------------------------------  */
		/* this will need to be adapted to produce the required css 3 format using a  	*/
		/* single image comprising the different image parts and needing precise info 	*/
		/* concerning widths and cuts for its use in style.				*/
		/* ---------------------------------------------------------------------------  */
		generate_css_frame_item(  lptr->top, lptr->topleftimage, "corner-top_left-style" , value);
		generate_css_frame_item(  lptr->top, lptr->topimage, "border-top-style" , value);
		generate_css_frame_item(  lptr->top, lptr->toprightimage, "corner-top-right-style" , value);
		generate_css_frame_item(  lptr->top, lptr->rightimage, "border-right-style" , value);
		generate_css_frame_item(  lptr->top, lptr->bottomrightimage, "corner-bottom-right-style" , value);
		generate_css_frame_item(  lptr->top, lptr->bottomimage, "border-bottom-style" , value);
		generate_css_frame_item(  lptr->top, lptr->bottomleftimage, "corner-bottom-left-style" , value);
		generate_css_frame_item(  lptr->top, lptr->leftimage, "border-left-style" , value);
		}
	return;
}

/*	-----------------------------------------------------------------	*/
/*			g e n e r a t e _ c s s _ c o l o u r			*/
/*	-----------------------------------------------------------------	*/
/*	generates a css colour expression using the colour item code or 	*/
/*	the colour triad information as the case may be.			*/
/*	-----------------------------------------------------------------	*/
private	void	generate_css_colour(   struct element_colour * lptr, char *tptr )
{
	switch ( lptr->type ) {
		case	_keyword_transparent	:
		case	_keyword_black		:
		case	_keyword_navy		:
		case	_keyword_green		:
		case	_keyword_cyan		:
		case	_keyword_red		:
		case	_keyword_magenta	:
		case	_keyword_brown		:
		case	_keyword_grey		:
		case	_keyword_silver		:
		case	_keyword_blue		:
		case	_keyword_lime		:
		case	_keyword_sky		:
		case	_keyword_pink		:
		case	_keyword_purple		:
		case	_keyword_yellow		:
		case	_keyword_white		:
			sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[lptr->type]);
			flush_css_buffer();
			break;
		case	_keyword_ihm		:
			sprintf(cssbuffer," %s: ihm(%u); ",tptr,lptr->entry-16);
			flush_css_buffer();
			break;
		case	_keyword_rgb		:
			sprintf(cssbuffer," %s: #%02.2X%02.2X%02.2X; ",tptr,
				lptr->red,lptr->green,lptr->blue);
			flush_css_buffer();
			break;
		case	_keyword_colour		:
			sprintf(cssbuffer," %s: color(%u); ",tptr,lptr->entry);
			flush_css_buffer();
			break;
		}
	return;	
}

/*	-----------------------------------------------------------------	*/
/*		g e n e r a t e _ c s s _ i m a g e _ a l i g n			*/
/*	-----------------------------------------------------------------	*/
/*	generates an image alignment expression field.				*/
/*	-----------------------------------------------------------------	*/
private	int	generate_css_image_align( char * tptr, int value )
{
	switch ((value & ~_ALIGN_SPRITE)) {

		case _ALIGN_NONE	:
			sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[_keyword_none]);
			flush_css_buffer();
			break;
		case _ALIGN_LEFT	:
			sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[_keyword_left]);
			flush_css_buffer();
			break;
		case _ALIGN_RIGHT	:
			sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[_keyword_right]);	 
			flush_css_buffer();
			break;
		case _ALIGN_CENTER	:
			sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[_keyword_center]);	 
			flush_css_buffer();
			break;
		case _ALIGN_JUSTIFY	:
			sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[_keyword_tile]);    
			flush_css_buffer();
			break;
		case _ALIGN_STRETCH	:
			sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[_keyword_makefit]);
			flush_css_buffer();
			break;
		case _ALIGN_ADJUST	:
			sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[_keyword_bestfit]); 
			flush_css_buffer();
			break;

		}
	if ( value & _ALIGN_SPRITE )
	{
		sprintf(cssbuffer," %s: transparent; ",tptr);
		flush_css_buffer();
	}
	return;
}

/*	-----------------------------------------------------------------	*/
/*		g e n e r a t e _ c s s _ t e x t _ a l i g n			*/
/*	-----------------------------------------------------------------	*/
/*	generates a text alignement expression field.				*/
/*	-----------------------------------------------------------------	*/
private	int	generate_css_text_align( char * tptr, int value )
{
	switch ((value & ~_ALIGN_SPRITE)) {

		case _ALIGN_NONE	:
			sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[_keyword_none]);
			flush_css_buffer();
			break;
		case _ALIGN_LEFT	:
			sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[_keyword_left]);
			flush_css_buffer();
			break;
		case _ALIGN_RIGHT	:
			sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[_keyword_right]);	 
			flush_css_buffer();
			break;
		case _ALIGN_CENTER	:
			sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[_keyword_center]);	 
			flush_css_buffer();
			break;
		case _ALIGN_JUSTIFY	:
			sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[_keyword_justify]);
			flush_css_buffer();
			break;
		case _ALIGN_STRETCH	:
			sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[_keyword_makefit]);
			flush_css_buffer();
			break;
		case _ALIGN_ADJUST	:
			sprintf(cssbuffer," %s: %s; ",tptr,_style_keyword[_keyword_bestfit]); 
			flush_css_buffer();
			break;
		}
	if ( value & _ALIGN_SPRITE )
	{
		sprintf(cssbuffer," %s: transparent; ",tptr);
		flush_css_buffer();
	}
	return;
}

/*	-----------------------------------------------------------------	*/
/*		g e n e r a t e _ c s s _ t e x t _ a t r i b u t		*/
/*	-----------------------------------------------------------------	*/
/*	generates a text decoration atribut expression.				*/
/*	-----------------------------------------------------------------	*/
private	int	generate_css_text_atribut( int v )
{
	if (!( v ))
	{
		sprintf(cssbuffer," text-decoration: none; ");
		flush_css_buffer();
	}
	else	
	{
		if ( v & _TEXT_BOLD )
		{
			sprintf(cssbuffer," text-decoration: bold; ");
			flush_css_buffer();
		}
		if ( v & _TEXT_UNDERLINE )
		{
			sprintf(cssbuffer," text-decoration: underline; ");
			flush_css_buffer();
		}
		if ( v & _TEXT_OVERLINE )
		{
			sprintf(cssbuffer," text-decoration: overline; ");
			flush_css_buffer();
		}
		if ( v & _TEXT_STRIKE )
		{
			sprintf(cssbuffer," text-decoration: strike-through; ");
			flush_css_buffer();
		}
		if ( v & _TEXT_BLINK )
		{
			sprintf(cssbuffer," text-decoration: blink; ");
			flush_css_buffer();
		}
		if ( v & _TEXT_SHADOW )
		{
			sprintf(cssbuffer," text-decoration: shadow; ");
			flush_css_buffer();
		}
	}
	return;
}

#define	strxcasecmp( a, b ) strncasecmp( a, b, strlen(b) )
private void  generate_css_font_family( char * filename )
{
	char * family=(char *) 0;
	if (!( strxcasecmp( filename, "arial" ) ))
		family = "Arial";
	else if (!( strxcasecmp( filename, "comic" ) ))
		family = "Comic Sans MS";
	else if (!( strxcasecmp( filename, "treb" ) ))
		family = "Trebuchet MS";
	else if (!( strxcasecmp( filename, "tahoma" ) ))
		family = "Tahoma";
	else if (!( strxcasecmp( filename, "times" ) ))
		family = "Times New Roman";
	else if (!( strxcasecmp( filename, "cour" ) ))
		family = "Courier New";
	else if (!( strxcasecmp( filename, "lucida" ) ))
		family = "Lucida Sans Unicode";
	else if (!( strxcasecmp( filename, "helv" ) ))
		family = "Helvetica";
	else if (!( strxcasecmp( filename, "impact" ) ))
		family = "Impact";
	else if (!( strxcasecmp( filename, "gara" ) ))
		family = "Garamond";
	else if (!( strxcasecmp( filename, "georgia" ) ))
		family = "Georgia";
	else if (!( strxcasecmp( filename, "verd" ) ))
		family = "Verdana";
	else if (!( strxcasecmp( filename, "none" ) ))
		family = (char *) 0;
	else	family = (char *) 0;

	if ( family )
	{

		sprintf(cssbuffer," font-family: %s; ",family);
		flush_css_buffer();
	}
	return;
}

/*	-----------------------------------------------------------------	*/
/*			g e n e r a t e _ c s s _ c l a s s			*/
/*	-----------------------------------------------------------------	*/
/*	generates a complete css class comprising style expressions.		*/
/*	this is the interface function of this source and takes a pair		*/
/*	of style class structure pointers as parameters. The function will	*/
/*	reduce the output of style instructions to the collection of 		*/
/*	elements in the first set that are not in the second set which is	*/
/*	presumed to be the base class omponent.					*/
/*	-----------------------------------------------------------------	*/
char * generate_css_class( struct element_style * lptr )
{
	int	fh;
	int	fw;
	int	fheight;
	char *	sptr;
	int	c;
	/* Generate Class identification and Derivation information */
	/* -------------------------------------------------------- */
	cssresult[0] = 0;

	if ( lptr->name )
	{
		sprintf(cssbuffer, ".%s { ",lptr->name);	
		flush_css_buffer();
	}

	/* Compare Global Cell Information : Poition/Width/Height */
	/* ------------------------------------------------------ */
	generate_css_position(&lptr->cellposition);
	generate_css_dimension(&lptr->cellwidth,"width" );
	generate_css_dimension(&lptr->cellheight,"height" );
	
	/* Compare Style Cell Margin Area */
	/* ------------------------------ */
	generate_css_sizes( &lptr->marginsize, "margin","\0" );

	/* these other margin atributs don not exist in CSS 
		generate_css_colour( &lptr->margincolour, "margin-color" );
		if ( lptr->marginimage )
		{
			sprintf(cssbuffer,"margin-image: url(%s); ",lptr->marginimage);
			flush_css_buffer();
		}
		generate_css_image_align("margin-align",lptr->marginalign);
		sprintf(cssbuffer," margin-repeat: %s; ",_style_keyword[lptr->marginrepeat]);
		flush_css_buffer();
	*/

	/* Compare Style Cell Border Area */
	/* ------------------------------ */
	generate_css_sizes( &lptr->bordersize, "border","-width" );
	generate_css_frame( &lptr->bordertype, lptr->rounding );
	generate_css_colour( &lptr->bordercolour, "border-color" );

	/* generate_css_image_align("border-align",lptr->borderalign); */

	/* Compare Style Cell Background Area */
	/* ---------------------------------- */
	generate_css_colour( &lptr->backgroundcolour, "background-color" );

	if ( lptr->backgroundimage )
	{
		sprintf(cssbuffer," background-image: url(%s); ",lptr->backgroundimage);
		flush_css_buffer();
		if ( lptr->backgroundalign == _keyword_tile )
		{
			sprintf(cssbuffer," background-repeat: repeat; ");
			flush_css_buffer();
		}
		else
		{
			sprintf(cssbuffer," background-repeat: none; ");
			flush_css_buffer();
			generate_css_image_align("background-align",lptr->backgroundalign);
		}
		flush_css_buffer();
	}

	/* Compare Style Cell Padding Area */
	/* ------------------------------- */
	generate_css_sizes( &lptr->paddingsize, "padding","\0" );

	generate_css_dimension( &lptr->textindent, "text-indent" );
	generate_css_dimension( &lptr->wordspacing, "word-spacing" );
	generate_css_dimension( &lptr->linespacing, "line-height" );
	generate_css_dimension( &lptr->letterspacing, "letter-spacing" );
	generate_css_colour( &lptr->textcolour, "color" );

	generate_css_text_align("vertical-align",lptr->verticalalign);
	generate_css_text_align("text-align",lptr->textalign);
	generate_css_text_atribut(  lptr->textatribut );

	if ( lptr->fontname )
	{
		generate_css_font_family( lptr->fontname );
		fw = guifontsize(lptr->textfont);
		fh = ((fw & 0xFF00) >> 8);
		fheight = ((fh * 4) / 5);
		sprintf(cssbuffer," font-size: %upt; ",fheight);
		flush_css_buffer();
	}
	sprintf(cssbuffer," }\\n ");
	flush_css_buffer();
	return(cssresult);
}


#endif	/* _gencss_c */
	/* --------- */



