#ifndef	_genstyle_c
#define	_genstyle_c

/*	-----------------------------------------------------------------	*/
/*	G e n e r a t i o n    o f    S t y le    I n s t r u c t i o n s 	*/
/*	-----------------------------------------------------------------	*/
/*										*/
/*	This is quite a complex operation requiring a class to be compared	*/
/*	against its base class ( if this exists ) or the empty class.     	*/
/*	The resulting differences are then generated as style instructions	*/
/*										*/
/*	-----------------------------------------------------------------	*/
	int	type;		/* type of the quantity 	*/		
	int	value;		/* value of the quantity 	*/
#ifdef	ABAL32A
	int	state;		/* set or default		*/
#endif
private	void	generate_style_dimension(FILE * h,   struct element_dimension * lptr, struct element_dimension * rptr, char * tptr )
{
	if (!( lptr->state & 1 ))
		return;
	else	{
		switch (lptr->type) {
			case _CELL_DIMENSION	:
				fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[ _keyword_cell ]);
				break;
			case _TEXT_DIMENSION	:
				fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[ _keyword_text ]);
				break;
			case _FIXED_DIMENSION	:
				fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[ _keyword_fixed ]);
				break;
			case _AUTO_DIMENSION	:
				fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[ _keyword_auto ]);
				break;
			default			:
				fprintf(h,"\t%s: %s;\r\n",tptr,lptr->token);
				break;
#ifdef	_no_dimension_token
			case	_PLUS_DIMENSION	:
				fprintf(h,"\t%s: %d+;\r\n",tptr,lptr->value);
				break;
			case	_PERCENT_DIMENSION	:
				fprintf(h,"\t%s: %d%c;\r\n",tptr,lptr->value,0x0025);
				break;
			case	_PIXEL_DIMENSION	:
				fprintf(h,"\t%s: %dpx;\r\n",tptr,lptr->value);
				break;
			case	_ELEMENT_DIMENSION	:
				fprintf(h,"\t%s: %del;\r\n",tptr,lptr->value);
				break;
			case	_IN_DIMENSION	:
				fprintf(h,"\t%s: %din;\r\n",tptr,lptr->value);
				break;
			case	_MM_DIMENSION	:
				fprintf(h,"\t%s: %dmm;\r\n",tptr,lptr->value);
				break;
			case	_CM_DIMENSION	:
				fprintf(h,"\t%s: %dcm;\r\n",tptr,lptr->value);
				break;
			case	_PT_DIMENSION	:
				fprintf(h,"\t%s: %dpt;\r\n",tptr,lptr->value);
				break;
			case	_PC_DIMENSION	:
				fprintf(h,"\t%s: %dpc;\r\n",tptr,lptr->value);
				break;
#endif
			}
		}
	return;
}

private	void	generate_style_position(FILE * h,  struct element_position * lptr, struct element_position * rptr )
{
	if ( lptr->type != rptr->type ) {
		fprintf(h,"\tposition: %s;\r\n",_style_keyword[lptr->type]);
		}
	if ( lptr->option != rptr->option ) {
		fprintf(h,"\tfloat: %s;\r\n",_style_keyword[lptr->option]);
		}
	generate_style_dimension( h, &lptr->top, &rptr->top,"top" );
	generate_style_dimension( h, &lptr->right, &rptr->right,"right" );
	generate_style_dimension( h, &lptr->bottom, &rptr->bottom,"bottom" );
	generate_style_dimension( h, &lptr->left, &rptr->left,"left" );
	return;
}

private	void	generate_style_sizes(FILE * h,   struct element_sizes * lptr, struct element_sizes * rptr, char * tptr, char * xptr )
{
	char	tagbuffer[256];
	sprintf(tagbuffer,"%s-top%s",tptr,xptr);
	generate_style_dimension( h, &lptr->top, &rptr->top,tagbuffer );
	sprintf(tagbuffer,"%s-right%s",tptr,xptr);
	generate_style_dimension( h, &lptr->right, &rptr->right,tagbuffer );
	sprintf(tagbuffer,"%s-bottom%s",tptr,xptr);
	generate_style_dimension( h, &lptr->bottom, &rptr->bottom,tagbuffer );
	sprintf(tagbuffer,"%s-left%s",tptr,xptr);
	generate_style_dimension( h, &lptr->left, &rptr->left,tagbuffer );
	return;
}

private	int	generate_style_string(  char * lptr, char * rptr )
{
	if (!( lptr )) {
		if (!( rptr ))
			return(1);
		else 	return(0);
		}
	else if (!( rptr ))
		return(0);
	else if (!( strcmp( lptr, rptr ) ))
		return(1);
	else	return(0);
}

private	void	generate_style_frame_item(FILE * h,   int l, char * lptr, int r, char * rptr, char * tptr, int value )
{
	if ( l != r ) {
		if ( l == _keyword_url )
			fprintf(h,"\t%s: url(%s);\r\n",tptr,lptr);
		else if ( l == _keyword_rounded )
			fprintf(h,"\t%s: %s(%u);\r\n",tptr,_style_keyword[l],value);
		else	fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[l]);
		}
	else if ( l == _keyword_url ) {
		if (!( generate_style_string( lptr, rptr ) ))
			fprintf(h,"\t%s: url(%s);\r\n",tptr,lptr);
		}
	return;
}

private	void	generate_style_frame(FILE * h,   struct element_frame * lptr, struct element_frame * rptr, int value )
{
	if ( lptr->top != _keyword_url ) {
		generate_style_frame_item( h, lptr->top, lptr->topimage, rptr->top, rptr->topimage,"border-style" , value);
		}
	else	{
		generate_style_frame_item( h, lptr->top, lptr->topleftimage, rptr->top, rptr->topleftimage,"corner-top_left-style" , value);
		generate_style_frame_item( h, lptr->top, lptr->topimage, rptr->top, rptr->topimage,"border-top-style" , value);
		generate_style_frame_item( h, lptr->top, lptr->toprightimage, rptr->top, rptr->toprightimage,"corner-top-right-style" , value);
		generate_style_frame_item( h, lptr->top, lptr->rightimage, rptr->top, rptr->rightimage,"border-right-style" , value);
		generate_style_frame_item( h, lptr->top, lptr->bottomrightimage, rptr->top, rptr->bottomrightimage,"corner-bottom-right-style" , value);
		generate_style_frame_item( h, lptr->top, lptr->bottomimage, rptr->top, rptr->bottomimage,"border-bottom-style" , value);
		generate_style_frame_item( h, lptr->top, lptr->bottomleftimage, rptr->top, rptr->bottomleftimage,"corner-bottom-left-style" , value);
		generate_style_frame_item( h, lptr->top, lptr->leftimage, rptr->top, rptr->leftimage,"border-left-style" , value);
		}
	return;
}

private	void	generate_style_colour(FILE * h,   struct element_colour * lptr, struct element_colour * rptr, char *tptr )
{
	if (( lptr->type != rptr->type )
	||  ( lptr->red  != rptr->red  )
	||  ( lptr->green!= rptr->green)
	||  ( lptr->blue != rptr->blue )) {
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
				fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[lptr->type]);
				break;
			case	_keyword_ihm		:
				fprintf(h,"\t%s: ihm(%u);\r\n",tptr,lptr->entry-16);
				break;

			case	_keyword_rgb		:
				fprintf(h,"\t%s: rgb(%02.2X%02.2X%02.2X);\r\n",tptr,
					lptr->red,lptr->green,lptr->blue);
				break;
			case	_keyword_colour		:
				fprintf(h,"\t%s: colour(%u);\r\n",tptr,lptr->entry);
				break;
			}
		}
	return;	
}

private	int	generate_style_image_align(FILE * h, char * tptr, int value )
{
	switch ((value & ~_ALIGN_SPRITE)) {

		case _ALIGN_NONE	:
			fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[_keyword_none]);
			break;
		case _ALIGN_LEFT	:
			fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[_keyword_left]);
			break;
		case _ALIGN_RIGHT	:
			fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[_keyword_right]);	 
			break;
		case _ALIGN_CENTER	:
			fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[_keyword_center]);	 
			break;
		case _ALIGN_JUSTIFY	:
			fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[_keyword_tile]);    
			break;
		case _ALIGN_STRETCH	:
			fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[_keyword_makefit]);
			break;
		case _ALIGN_ADJUST	:
			fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[_keyword_bestfit]); 
			break;

		}
	if ( value & _ALIGN_SPRITE )
		fprintf(h,"\t%s: transparent;\r\n",tptr);
	return;
}

private	int	generate_style_text_align(FILE * h, char * tptr, int value )
{
	switch ((value & ~_ALIGN_SPRITE)) {

		case _ALIGN_NONE	:
			fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[_keyword_none]);
			break;
		case _ALIGN_LEFT	:
			fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[_keyword_left]);
			break;
		case _ALIGN_RIGHT	:
			fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[_keyword_right]);	 
			break;
		case _ALIGN_CENTER	:
			fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[_keyword_center]);	 
			break;
		case _ALIGN_JUSTIFY	:
			fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[_keyword_justify]);
			break;
		case _ALIGN_STRETCH	:
			fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[_keyword_makefit]);
			break;
		case _ALIGN_ADJUST	:
			fprintf(h,"\t%s: %s;\r\n",tptr,_style_keyword[_keyword_bestfit]); 
			break;
		}
	if ( value & _ALIGN_SPRITE )
		fprintf(h,"\t%s: transparent;\r\n",tptr);
	return;
}

private	int	generate_style_text_atribut(FILE * h, int v )
{
	if (!( v ))
		fprintf(h,"\ttext-decoration: none;\r\n");
	else	{
		if ( v & _TEXT_BOLD )
			fprintf(h,"\ttext-decoration: bold;\r\n");
		if ( v & _TEXT_UNDERLINE )
			fprintf(h,"\ttext-decoration: underline;\r\n");
		if ( v & _TEXT_OVERLINE )
			fprintf(h,"\ttext-decoration: overline;\r\n");
		if ( v & _TEXT_STRIKE )
			fprintf(h,"\ttext-decoration: strike-through;\r\n");
		if ( v & _TEXT_BLINK )
			fprintf(h,"\ttext-decoration: blink;\r\n");
		if ( v & _TEXT_SHADOW )
			fprintf(h,"\ttext-decoration: shadow;\r\n");
		}
	return;
}

int	generate_style_class(FILE * h,  struct element_style * lptr , struct element_style * rptr, int mode )
{
	char *	sptr;
	int	c;
	/* Generate Class identification and Derivation information */
	/* -------------------------------------------------------- */
	if ( lptr->name     )	fprintf(h, "%s {\r\n",lptr->name);	
	if ( mode ) {
		if ( lptr->filename )	fprintf(h, "\tfile: url(%s);\r\n",lptr->filename);	
		}
	if ( lptr->alias    ) {
		fprintf(h, "\talias: ");
		for (	sptr=lptr->alias;
			*sptr != 0;
			sptr++ ) {
			if ((c = *sptr) == '|' )
				c = ',';
			fprintf(h,"%c",c);
			}
		fprintf(h, ";\r\n");
		} 	
	if ( lptr->basename )	fprintf(h, "\tclass: %s;\r\n",lptr->basename);	

	/* Compare Global Cell Information : Poition/Width/Height */
	/* ------------------------------------------------------ */
	generate_style_position(h,&lptr->cellposition, &rptr->cellposition );
	generate_style_dimension(h, &lptr->cellwidth, &rptr->cellwidth,"width" );
	generate_style_dimension(h, &lptr->cellheight, &rptr->cellheight,"height" );
	
	/* Compare Style Cell Margin Area */
	/* ------------------------------ */
	generate_style_sizes(h, &lptr->marginsize, &rptr->marginsize,"margin","\0" );
	generate_style_colour(h, &lptr->margincolour, &rptr->margincolour,"margin-colour" );

	if (!( generate_style_string( lptr->marginimage, rptr->marginimage ) ))
		if ( lptr->marginimage )
			fprintf(h,"margin-image: url(%s);\r\n",lptr->marginimage);

	if ( lptr->marginalign != rptr->marginalign )
		generate_style_image_align(h,"margin-align",lptr->marginalign);

	if ( lptr->marginrepeat != rptr->marginrepeat )
		fprintf(h,"\tmargin-repeat: %s;\r\n",_style_keyword[lptr->marginrepeat]);

	/* Compare Style Cell Border Area */
	/* ------------------------------ */
	generate_style_sizes(h, &lptr->bordersize, &rptr->bordersize,"border","-width" );
	generate_style_frame(h, &lptr->bordertype, &rptr->bordertype, lptr->rounding );
	generate_style_colour(h, &lptr->bordercolour, &rptr->bordercolour,"border-colour" );
	if ( lptr->borderalign != rptr->borderalign )
		generate_style_image_align(h,"border-align",lptr->borderalign);

	/* Compare Style Cell Background Area */
	/* ---------------------------------- */
	generate_style_colour(h, &lptr->backgroundcolour, &rptr->backgroundcolour,"background-colour" );

	if (!( generate_style_string( lptr->backgroundimage, rptr->backgroundimage ) ))
		if ( lptr->backgroundimage )
			fprintf(h,"\tbackground-image: url(%s);\r\n",lptr->backgroundimage);

	if ( lptr->backgroundalign != rptr->backgroundalign )
		generate_style_image_align(h,"background-align",lptr->backgroundalign);

	if ( lptr->backgroundrepeat != rptr->backgroundrepeat )
		fprintf(h,"\tbackground-repeat: %s;\r\n",_style_keyword[lptr->backgroundrepeat]);

	if ( lptr->backgroundattach != rptr->backgroundattach )
		fprintf(h,"\tbackground-attach: %s;\r\n",_style_keyword[lptr->backgroundattach]);

	/* Compare Style Cell Padding Area */
	/* ------------------------------- */
	generate_style_sizes(h, &lptr->paddingsize, &rptr->paddingsize, "padding","\0" );

	/* Compare Style Cell Context Atributs */
	/* ----------------------------------- */
	if ( lptr->nature != rptr->nature )
		fprintf(h,"\tcontent: %s;\r\n",_style_keyword[lptr->nature]);

	generate_style_dimension(h, &lptr->textindent, &rptr->textindent,"text-indent" );
	generate_style_dimension(h, &lptr->wordspacing, &rptr->wordspacing,"word-spacing" );
	generate_style_dimension(h, &lptr->linespacing, &rptr->linespacing,"line-spacing" );
	generate_style_dimension(h, &lptr->letterspacing, &rptr->letterspacing,"letter-spacing" );
	generate_style_colour(h, &lptr->textcolour, &rptr->textcolour,"text-colour" );
	generate_style_dimension(h, &lptr->shadowwidth, &rptr->shadowwidth,"shadow-width" );
	generate_style_dimension(h, &lptr->shadowheight, &rptr->shadowheight,"shadow-height" );
	generate_style_colour(h, &lptr->shadowcolour, &rptr->shadowcolour,"shadow-colour" );

	if ( lptr->verticalalign != rptr->verticalalign )
		generate_style_text_align(h,"vertical-align",lptr->verticalalign);

	if ( lptr->textalign != rptr->textalign )
		generate_style_text_align(h,"text-align",lptr->textalign);

	if ( lptr->textatribut != rptr->textatribut )
		generate_style_text_atribut( h, lptr->textatribut );

	if ( lptr->textfont != rptr->textfont )
		if ( lptr->fontname )
			fprintf(h,"\ttext-font: url(%s);\r\n",lptr->fontname);
	fprintf(h,"\t}\r\n");
	return(0);
}

public	char *	generate_style_file( struct element_style * lptr , struct element_style * rptr, int mode )
{
	int	status=0;
	int	flag=0;
	FILE *	h;
	if (!( lptr ))
		return((char *) 0);
	else if (!( rptr )) {
		if (!( rptr = allocate_for_style() ))
			return((char *) 0);
		else	flag=1;
		}
	if (( h = fopen( "tempfile.css", "w")) != (FILE *) 0) {
		generate_style_class(h, lptr, rptr, mode );
		fclose(h);
		if ( flag ) liberate_style( rptr );
		return( file_to_string( "tempfile.css" ) );
		}
	else	{
		if ( flag ) liberate_style( rptr );
		return((char *) 0);
		}
}

#endif	/* _genstyle_c */
	/* ----------- */



