static	int	apply_textual_style(struct element_style * sptr, struct style_object * optr )
{
	int			hrf=8;		/* hold rounding factor (eighth of dimension )	*/
	int			qstyle=0;
	int			holder[5];
	int			dx=0,dy=0;
	struct	style_zone	margin;		/* dimensions and position of the margin	*/
	struct	style_zone	border;		/* dimensions and position of the border	*/
	struct	style_zone	corner;		/* dimensions and position of the corners	*/
	struct	style_zone	padding;	/* dimensions of the padding			*/
	struct	style_zone	content;	/* dimensions and position of the contents 	*/
	struct	style_zone	frame;		/* dimensions and position of the contents 	*/
	struct standard_image * iptr;

	struct standard_image *  load_visual_image( char * filename );
	int			colourmapped=get_pixel_format();

	sptr->applied++;

	/* Detect replaced content and resolve it */
	/* -------------------------------------- */
	if ( sptr->nature  == _keyword_url ) {
		if ((iptr = load_visual_image(optr->message)) != (struct standard_image *) 0) {
			if ( sptr->cellwidth.type  == _FIXED_DIMENSION )
				optr->nbx = 
				iptr->columns;
			if ( sptr->cellheight.type  == _FIXED_DIMENSION )
				optr->nby = 
				iptr->rows;
			}
		}

	/* Calculate Initial Content Size and Position */
	/* ------------------------------------------- */
	switch ( sptr->cellwidth.type ) {
		case	_TEXT_DIMENSION	:
			if (!( sptr->textfont ))
				content.w = optr->nbx;
			else	content.w = textsizelen(sptr->textfont,optr->message,optr->length);
			break;
		case	_PERCENT_DIMENSION :
			content.w = ((optr->vpw*sptr->cellwidth.value)/100);
			break;
		case	_PIXEL_DIMENSION :
			content.w = sptr->cellwidth.value;
			break;
		case	_FIXED_DIMENSION:
		case	_AUTO_DIMENSION	:
		default			:
			content.w = optr->nbx;
			break;
			
		}

	switch ( sptr->cellheight.type ) {
		case	_TEXT_DIMENSION	:
			if (!( sptr->textfont ))
				content.h = optr->nby;
			else	content.h = ((guifontsize(sptr->textfont) >> 8) & 0x00FF);
			break;
		case	_PERCENT_DIMENSION :
			content.h = ((optr->vph*sptr->cellheight.value)/100);
			break;
		case	_PIXEL_DIMENSION :
			content.h = sptr->cellheight.value;
			break;
		case	_FIXED_DIMENSION:
		case	_AUTO_DIMENSION	:
		default			:
			content.h = optr->nby;
			break;
		}


	/* ----------------------------------------------------------- */
	/* calculate position, dimensions, margins, border and padding */
	/* ----------------------------------------------------------- */
	switch (  sptr->cellposition.option ) {


		case	_keyword_left	:	/* float : left;	*/
			content.x = optr->lmi;
			content.y = optr->aty;
			break;

		case	_keyword_top	:	/* float : top; 	*/
			content.y = optr->tmi;
			content.x = optr->atx;
			break;

		case	_keyword_right	:	/* float : right; 	*/
			if ( optr->vpw >= content.w )
				content.x = optr->lmi+(optr->vpw-content.w);
			else	content.x = optr->lmi;
			content.y = optr->aty;
			break;
		case	_keyword_bottom	:	/* float : bottom; 	*/
			if ( optr->vph >= content.h )
				content.y = optr->tmi+(optr->vph-content.h);
			else	content.y = optr->tmi;
			content.x = optr->atx;
			break;

		case	_keyword_home	:	/* float : home; 	*/
			content.x =  optr->lmi; 
			content.y =  optr->tmi;
			break;


		case	_keyword_none	:
		default			:

			switch ( sptr->cellposition.type ) {
				case	_keyword_home	:
					content.x =  optr->lmi; 
					content.y =  optr->tmi;
					break;

				case	_keyword_line	:
					content.x =  optr->lmi; 
					content.y =  optr->aty;
					break;
	
				case	_keyword_absolute	:
				case	_keyword_fixed		:
	
					switch ( sptr->cellposition.left.type ) {
						case	_PIXEL_DIMENSION	:
							content.x = sptr->cellposition.left.value;
							break;

						case	_PERCENT_DIMENSION	:
							content.x = optr->lmi + ((optr->vpw*sptr->cellposition.left.value)/100);
							break;
						}

					switch ( sptr->cellposition.top.type ) {
						case	_PIXEL_DIMENSION	:
							content.y = sptr->cellposition.top.value;
							break;

						case	_PERCENT_DIMENSION	:
							content.y = optr->tmi + ((optr->vph*sptr->cellposition.top.value)/100);
							break;
						}
					break;

				case	_keyword_relative	:
					switch ( sptr->cellposition.left.type ) {
						case	_PIXEL_DIMENSION	:
							content.x = optr->atx + sptr->cellposition.left.value;
							break;

						case	_PERCENT_DIMENSION	:
							content.x = optr->atx + ((optr->vpw*sptr->cellposition.left.value)/100);
							break;
						}

					switch ( sptr->cellposition.top.type ) {
						case	_PIXEL_DIMENSION	:
							content.y = optr->aty + sptr->cellposition.top.value;
							break;

						case	_PERCENT_DIMENSION	:
							content.y = optr->aty + ((optr->vph*sptr->cellposition.top.value)/100);
							break;
						}
					break;

				case	_keyword_static		:
				case	_keyword_auto	:
				default			:
					content.x =  optr->atx;
					content.y =  optr->aty;
					break;

				}
	
		} /* float : nature */
#ifdef	_TRACE_STYLE
	showzone( "initial content", &content );
#endif

	/* Calculate Content Padding : Added outside of Contents */
	/* ----------------------------------------------------- */
	switch ( sptr->paddingsize.top.type ) {
		case	_PIXEL_DIMENSION :
			padding.y = sptr->paddingsize.top.value;
			break;
		case	_PERCENT_DIMENSION :
			padding.y = ((optr->vph*sptr->paddingsize.top.value)/100);
			break;
		default			:
			padding.y = 0;
		}

	switch ( sptr->paddingsize.bottom.type ) {
		case	_PIXEL_DIMENSION :
			padding.h = sptr->paddingsize.bottom.value;
			break;
		case	_PERCENT_DIMENSION :
			padding.h = ((optr->vph*sptr->paddingsize.bottom.value)/100);
			break;
		default			:
			padding.h = 0;
		}

	switch ( sptr->paddingsize.left.type ) {
		case	_PIXEL_DIMENSION :
			padding.x = sptr->paddingsize.left.value;
			break;
		case	_PERCENT_DIMENSION :
			padding.x = ((optr->vpw*sptr->paddingsize.left.value)/100);
			break;
		default			:
			padding.x = 0;
		}

	switch ( sptr->paddingsize.right.type ) {
		case	_PIXEL_DIMENSION :
			padding.w = sptr->paddingsize.right.value;
			break;
		case	_PERCENT_DIMENSION :
			padding.w = ((optr->vpw*sptr->paddingsize.right.value)/100);
			break;
		default			:
			padding.w = 0;
		}


#ifdef	_TRACE_STYLE
	showzone( "padding", &padding );
#endif

	/* Calculate Content Padding : Added outside of Contents */
	/* ----------------------------------------------------- */
	switch ( sptr->bordersize.top.type ) {
		case	_PIXEL_DIMENSION :
			frame.y = sptr->bordersize.top.value;
			break;
		case	_PERCENT_DIMENSION :
			frame.y = ((optr->vph*sptr->bordersize.top.value)/100);
			break;
		default			:
			frame.y = 0;
		}

	switch ( sptr->bordersize.bottom.type ) {
		case	_PIXEL_DIMENSION :
			frame.h = sptr->bordersize.bottom.value;
			break;
		case	_PERCENT_DIMENSION :
			frame.h = ((optr->vph*sptr->bordersize.bottom.value)/100);
			break;
		default			:
			frame.h = 0;
		}

	switch ( sptr->bordersize.left.type ) {
		case	_PIXEL_DIMENSION :
			frame.x = sptr->bordersize.left.value;
			break;
		case	_PERCENT_DIMENSION :
			frame.x = ((optr->vpw*sptr->bordersize.left.value)/100);
			break;
		default			:
			frame.x = 0;
		}

	switch ( sptr->bordersize.right.type ) {
		case	_PIXEL_DIMENSION :
			frame.w = sptr->bordersize.right.value;
			break;
		case	_PERCENT_DIMENSION :
			frame.w = ((optr->vpw*sptr->bordersize.right.value)/100);
			break;
		default			:
			frame.w = 0;
		}

#ifdef	_TRACE_STYLE
	showzone( "border size ", &frame   );
#endif

	/* Calculate Border : Added Outside of Padding */
	/* ------------------------------------------- */
	if ( content.y > (padding.y+frame.y) )
		border.y = (content.y - (padding.y+frame.y));
	else 	{
		content.y += ((padding.y+frame.y) - content.y);
		border.y = 0;
		}


	if ( content.x > (padding.x+frame.x) )
		border.x = (content.x - (padding.x+frame.x));
	else	{
		content.x += ((padding.x+frame.x) - content.x);
		border.x = 0;
		}

	border.h = (content.h + (padding.y + padding.h + frame.y + frame.h));
	border.w = (content.w + (padding.x + padding.w + frame.x + frame.w));

#ifdef	_TRACE_STYLE
	showzone( "border position", &border  );
	showzone( "final padding  ", &padding );
	showzone( "final content  ", &content );
	printf("\r\n");
#endif

	/* Calculate Margin : Top and Left push border, padding and contents */
	/* ----------------------------------------------------------------- */
	switch ( sptr->marginsize.top.type ) {
		case	_PIXEL_DIMENSION :
			margin.y = sptr->marginsize.top.value;
			break;
		case	_PERCENT_DIMENSION :
			margin.y = ((optr->vph*sptr->marginsize.top.value)/100);
			break;
		default			:
			margin.y = 0;
		}

	switch ( sptr->marginsize.bottom.type ) {
		case	_PIXEL_DIMENSION :
			margin.h = sptr->marginsize.bottom.value;
			break;
		case	_PERCENT_DIMENSION :
			margin.h = ((optr->vph*sptr->marginsize.bottom.value)/100);
				break;
		default			:
			margin.h = 0;
		}

	switch ( sptr->marginsize.left.type ) {
		case	_PIXEL_DIMENSION :
			margin.x = sptr->marginsize.left.value;
			break;
		case	_PERCENT_DIMENSION :
			margin.x = ((optr->vpw*sptr->marginsize.left.value)/100);
			break;
		default			:
			margin.x = 0;
		}
	switch ( sptr->marginsize.right.type ) {
		case	_PIXEL_DIMENSION :
			margin.w = sptr->marginsize.right.value;
			break;
		case	_PERCENT_DIMENSION :
			margin.w = ((optr->vpw*sptr->marginsize.right.value)/100);
			break;
		default			:
			margin.w = 0;
		}

	/* ------------------ */
	/* Drame Frame border */
	/* ------------------ */
	switch ( sptr->bordertype.top ) {
		case	_keyword_url		:
			corner.x = corner.y = corner.w = corner.h = 0;

			if ( sptr->bordertype.topleftimage     ) {
				visual_image(
					margin.x+border.x,margin.y+border.y,
					frame.x,frame.y,
					sptr->bordertype.topleftimage,
					sptr->borderalign | ImageQuality );
				corner.x = frame.x;
				}
			if ( sptr->bordertype.bottomleftimage ) {
				visual_image(
					margin.x+border.x,margin.y+border.y+(border.h-frame.h),
					frame.x,frame.y,
					sptr->bordertype.bottomleftimage,
					sptr->borderalign | ImageQuality );
				corner.y = frame.x; 
				}
			if ( sptr->bordertype.toprightimage     ) {
				visual_image(
					margin.x+border.x+(border.w-frame.w),
					margin.y+border.y,
					frame.x,frame.y,
					sptr->bordertype.toprightimage,
					sptr->borderalign | ImageQuality );
				corner.w = frame.w;
				}
			if ( sptr->bordertype.bottomrightimage ) {
				visual_image(
					margin.x+border.x+(border.w-frame.w),
					margin.y+border.y+(border.h-frame.h),
					frame.x,frame.y,
					sptr->bordertype.bottomrightimage,
					sptr->borderalign | ImageQuality );
				corner.h = frame.w;
				}

			if ( sptr->bordertype.leftimage ) {
				if ( border.h > (frame.h+frame.y) ) {
					visual_image(
						border.x+margin.x,border.y+margin.y+frame.y,
						sptr->bordersize.left.value,(border.h-(frame.h+frame.y)),
						sptr->bordertype.leftimage,
						sptr->borderalign );
					}
				}
			if ( sptr->bordertype.rightimage ) {
				if ( border.h > (frame.h+frame.y) ) {
					visual_image(
						border.x+margin.x+border.w-sptr->bordersize.right.value,
						border.y+margin.y+frame.y,
						sptr->bordersize.right.value,(border.h-(frame.h+frame.y)),
						sptr->bordertype.rightimage,
						sptr->borderalign );
					}
				}
			if ( sptr->bordertype.topimage ) {
				if ( border.w > (corner.x+corner.w)) {
					visual_image(
						border.x+margin.x+corner.x,border.y+margin.y,
						border.w-(corner.x+corner.w),sptr->bordersize.top.value,
						sptr->bordertype.topimage,
						sptr->borderalign );
					}
				}
			if ( sptr->bordertype.bottomimage ) {
				if ( border.w > (corner.y+corner.h)) {
					visual_image(
						border.x+margin.x+corner.y,border.y+margin.y+border.h-sptr->bordersize.bottom.value,
						border.w-(corner.y+corner.h),sptr->bordersize.bottom.value,
						sptr->bordertype.bottomimage,
						sptr->borderalign );
					}
				}
			break;

		case	_keyword_outset		:
			if (!( sptr->backgroundalign & _ALIGN_SPRITE ))
				visual_frame(	border.x+margin.x,border.y+margin.y,
						border.w,border.h,1);
			else	visual_frame(	border.x+margin.x,border.y+margin.y,
						border.w,border.h,1);
			break;

		case	_keyword_inset		:
			if (!( sptr->backgroundalign & _ALIGN_SPRITE ))
				visual_frame(	border.x+margin.x,border.y+margin.y,
						border.w,border.h,2);
			else	visual_frame(	border.x+margin.x,border.y+margin.y,
						border.w,border.h,2);
			break;

		case	_keyword_ridge		:
			if (!( sptr->backgroundalign & _ALIGN_SPRITE ))
				visual_frame(	border.x+margin.x,border.y+margin.y,
						border.w,border.h,3);
			else	visual_frame(	border.x+margin.x,border.y+margin.y,
						border.w,border.h,3);
			break;

		case	_keyword_groove		:
			if (!( sptr->backgroundalign & _ALIGN_SPRITE ))
				visual_frame(	border.x+margin.x,border.y+margin.y,
						border.w,border.h,4);
			else	visual_frame(	border.x+margin.x,border.y+margin.y,
						border.w,border.h,4);
			break;

		case	_keyword_edit		:
			visual_frame(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,5);
			break;

		case	_keyword_convex		:
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,0,10);
			break;

		case	_keyword_concave	:
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,0,11);
			break;

#ifdef	ABAL32A
		case	_keyword_vconvex		:
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					sptr->bordercolour.entry,
					18);
			break;

		case	_keyword_hconvex		:
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					sptr->bordercolour.entry,
					19);
			break;

		case	_keyword_vconcave	:
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					sptr->bordercolour.entry,
					20);
			break;

		case	_keyword_hconcave	:
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					sptr->bordercolour.entry,
					21);
			break;
#endif
		case	_keyword_solid		:
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					( colourmapped ? sptr->bordercolour.entry : rgbtriad(sptr->bordercolour )),
					1);
			break;

		case	_keyword_fill		:
			/* top edge */
			visual_filzone(	border.x,border.y,
					border.w,frame.y,
					( colourmapped ? sptr->bordercolour.entry : rgbtriad(sptr->bordercolour )),
					0);
			visual_filzone(	border.x,border.y,
					border.w,frame.h,
					( colourmapped ? sptr->bordercolour.entry : rgbtriad(sptr->bordercolour )),			/* bottom edge */
					0);
			/* left edge */
			visual_filzone(	border.x,border.y,
					frame.x,border.h,
					( colourmapped ? sptr->bordercolour.entry : rgbtriad(sptr->bordercolour )),			/* bottom edge */
					0);
			/* right edge */
			visual_filzone(	border.x,border.y,
					frame.w,border.h,
					( colourmapped ? sptr->bordercolour.entry : rgbtriad(sptr->bordercolour )),			/* bottom edge */
					0);
			break;

		case	_keyword_double		:
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					( colourmapped ? sptr->bordercolour.entry : rgbtriad(sptr->bordercolour )),			/* bottom edge */
					1);
			visual_filzone(	border.x+margin.x+2,border.y+margin.y+2,
					border.w-4,border.h-4,
					( colourmapped ? sptr->bordercolour.entry : rgbtriad(sptr->bordercolour )),			/* bottom edge */
					1);
			break;

		case	_keyword_dashed		:
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					( colourmapped ? sptr->bordercolour.entry : rgbtriad(sptr->bordercolour )),			/* bottom edge */
					15);
			visual_filzone(	border.x+margin.x+2,border.y+margin.y+2,
					border.w-4,border.h-4,
					( colourmapped ? sptr->bordercolour.entry : rgbtriad(sptr->bordercolour )),			/* bottom edge */
					15);
			break;

		case	_keyword_dotted		:
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					( colourmapped ? sptr->bordercolour.entry : rgbtriad(sptr->bordercolour )),			/* bottom edge */
					15);
				break;

		case	_keyword_shade    	:
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					( colourmapped ? sptr->bordercolour.entry : rgbtriad(sptr->bordercolour )),			/* bottom edge */
					16);
			break;

		case	_keyword_hole    	:
#ifdef	ABAL32A
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					( colourmapped ? sptr->bordercolour.entry : rgbtriad(sptr->bordercolour )),			/* bottom edge */
					17);
			break;
#endif
		case	_keyword_disk    	:
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					( colourmapped ? sptr->bordercolour.entry : rgbtriad(sptr->bordercolour )),			/* bottom edge */
					2);
			break;
		case	_keyword_rounded	:
			if ( sptr->rounding != -1 ) {
				hrf = set_rounding_factor( sptr->rounding );
				}
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					( colourmapped ? sptr->bordercolour.entry : rgbtriad(sptr->bordercolour )),			/* bottom edge */
					14);
			if ( sptr->rounding != -1 ) {
				hrf = set_rounding_factor( hrf );
				}
			break;

		}

	border.x += frame.x; border.y += frame.y;
	if ( border.w >= (frame.x+frame.w))
		border.w -= (frame.x+frame.w);
	else	border.w = 0;
	if ( border.h >= (frame.y+frame.h)) 
		border.h -= (frame.y+frame.h);
	else	border.h = 0;

	/* ------------------------------- */
	/* Fill Eventual Background Colour */
	/* ------------------------------- */
	switch ((qstyle = sptr->bordertype.top)) {

		case	_keyword_shade	:
			visual_filzone(
				border.x+margin.x,border.y+margin.y,
				border.w,border.h,
				( colourmapped ? sptr->backgroundcolour.entry : rgbtriad(sptr->backgroundcolour )),
				16);
			break;
		case	_keyword_hole	:
#ifdef	ABAL32A
			visual_filzone(
				border.x+margin.x,border.y+margin.y,
				border.w,border.h,
				( colourmapped ? sptr->backgroundcolour.entry : rgbtriad(sptr->backgroundcolour )),
				17);
			break;
#endif
		case	_keyword_disk	:
			if ( sptr->backgroundcolour.entry != 0 )
				visual_filzone(
					border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					( colourmapped ? sptr->backgroundcolour.entry : rgbtriad(sptr->backgroundcolour )),
					3);
			break;

		case	_keyword_rounded	:
			if ( sptr->backgroundcolour.entry != 0 ) {
				if ( sptr->rounding ) {
					hrf = set_rounding_factor( sptr->rounding );
					}
				visual_filzone(
					border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					( colourmapped ? sptr->backgroundcolour.entry : rgbtriad(sptr->backgroundcolour )),
					14);
				if ( sptr->rounding ) {
					hrf = set_rounding_factor( hrf );
					}
				}
			break;

		default				:
			if ( sptr->backgroundcolour.entry != 0 ) {
				if (!( sptr->backgroundalign & _ALIGN_SPRITE )) {
					filzone(border.x+margin.x,border.y+margin.y,
						border.w,border.h,
						( colourmapped ? sptr->backgroundcolour.entry : rgbtriad(sptr->backgroundcolour ))
						);
					}
				else	{
					visual_filzone(	border.x+margin.x,border.y+margin.y,
						border.w,border.h, 
						( colourmapped ? sptr->backgroundcolour.entry : rgbtriad(sptr->backgroundcolour )),
						12);
					}
				}
			break;

		}


	/* --------------------------------- */
	/* Display eventual background image */
	/* --------------------------------- */
	if ( sptr->backgroundimage ) {

		/* ----------------------- */
		/* adjust to inside border */
		/* ----------------------- */
#ifdef	not_needed
		border.x += frame.x;		/* sptr->bordersize.left.value;					*/
		border.y += frame.y;		/* sptr->bordersize.top.value;					*/
		border.w -= (frame.x+frame.w);	/* (sptr->bordersize.left.value+sptr->bordersize.right.value); 	*/
		border.h -= (frame.y+frame.h);	/* (sptr->bordersize.top.value+sptr->bordersize.bottom.value);	*/
#endif
		if ( qstyle != _keyword_disk ) {
			visual_image(
				border.x+margin.x,border.y+margin.y,
				border.w,border.h,
				sptr->backgroundimage,
				(sptr->backgroundalign +  ImageQuality ) );
			}
		}


	/* Display Contents */
	/* ---------------- */
	switch ( sptr->nature ) {
		case	_keyword_none	:
			break;
		case	_keyword_text	:
			if ( sptr->textfont != 0 ) {
				holder[0] = set_letter_spacing( sptr->letterspacing.value );
				holder[1] = set_line_spacing( sptr->linespacing.value );
#ifdef	ABAL32A
				if ( sptr->textatribut & _TEXT_SHADOW ) {
					if ( sptr->shadowcolour.type != -1 ) {
						holder[2] = set_shadow_colour( sptr->shadowcolour.entry );
						}
					if ( sptr->shadowwidth.state ) {
						holder[3] = set_shadow_width ( sptr->shadowwidth.value );
						}
					if ( sptr->shadowheight.state ) {
						holder[4] = set_shadow_height( sptr->shadowheight.value );
						}
					}
#endif
				visual_text	(
					content.x+margin.x,content.y+margin.y,
					content.w,content.h,
					sptr->textfont,
					( colourmapped ? sptr->textcolour.entry : newrgb(sptr->textcolour )),
					0, /* (qstyle == _keyword_disk ? 0 : sptr->backgroundcolour.entry), */
					optr->message,optr->length,
					( sptr->textalign | sptr->textatribut ));
#ifdef	ABAL32A
				if ( sptr->textatribut & _TEXT_SHADOW ) {
					if ( sptr->shadowheight.state ) {
						set_shadow_height( holder[4] );
						}
					if ( sptr->shadowwidth.state ) {
						set_shadow_width ( holder[3] );
						}
					if ( sptr->shadowcolour.type != -1 ) {
						set_shadow_colour( holder[2] );
						}
					}
#endif
				set_line_spacing( holder[1] );
				set_letter_spacing( holder[0] );
				}
			break;
		case	_keyword_trigger	:
			if ( sptr->textfont != 0 ) {
				holder[0] = set_letter_spacing( sptr->letterspacing.value );
				holder[1] = set_line_spacing( sptr->linespacing.value );
#ifdef	ABAL32A
				if ( sptr->textatribut & _TEXT_SHADOW ) {
					if ( sptr->shadowcolour.type != -1 ) {
						holder[2] = set_shadow_colour( sptr->shadowcolour.entry );
						}
					if ( sptr->shadowwidth.state ) {
						holder[3] = set_shadow_width ( sptr->shadowwidth.value );
						}
					if ( sptr->shadowheight.state ) {
						holder[4] = set_shadow_height( sptr->shadowheight.value );
						}
					}
#endif
				visual_trigger	(
					content.x+margin.x,content.y+margin.y,
					content.w,content.h,
					sptr->textfont,
					( colourmapped ? sptr->textcolour.entry : newrgb(sptr->textcolour )),
					0, /* (qstyle == _keyword_disk ? 0 : sptr->backgroundcolour.entry),*/
					optr->message,optr->length,
					( sptr->textalign | sptr->textatribut ));
#ifdef	ABAL32A
				if ( sptr->textatribut & _TEXT_SHADOW ) {
					if ( sptr->shadowheight.state ) {
						set_shadow_height( holder[4] );
						}
					if ( sptr->shadowwidth.state ) {
						set_shadow_width ( holder[3] );
						}
					if ( sptr->shadowcolour.type != -1 ) {
						set_shadow_colour( holder[2] );
						}
					}
#endif
				set_line_spacing( holder[1] );
				set_letter_spacing( holder[0] );
				}
			break;
		case	_keyword_left	:
			visual_arrow(content.x,content.y,content.w,content.h,16,_ARROW_LEFT);
			break;
		case	_keyword_right	:
			visual_arrow(content.x,content.y,content.w,content.h,16,_ARROW_RIGHT);
			break;
		case	_keyword_up	:
			visual_arrow(content.x,content.y,content.w,content.h,16,_ARROW_UP);
			break;
		case	_keyword_down	:
			visual_arrow(content.x,content.y,content.w,content.h,16,_ARROW_DOWN);
			break;
		case	_keyword_grip	:
			visual_arrow(content.x,content.y,content.w,content.h,16,_ARROW_FOCUS);
			break;
		case	_keyword_top 	:
			visual_arrow(content.x,content.y,content.w,content.h,16,_ARROW_TOP);
			break;
		case	_keyword_bottom	:
			visual_arrow(content.x,content.y,content.w,content.h,16,_ARROW_BOTTOM);
			break;
		case	_keyword_url	:
			visual_image	(
				content.x+margin.x,content.y+margin.y,
				content.w,content.h,
				optr->message,
				( sptr->textalign | sptr->textatribut  | ImageQuality ));
			break;
		}



	return(0);

}
 

