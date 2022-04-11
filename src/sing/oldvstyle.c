static	int	apply_visual_style(struct element_style * sptr, struct style_object * optr )
{


	int			holder[2];
	int			dx=0,dy=0;
	int			qstyle;
	struct	style_zone	content;
	struct	style_zone	margin;
	struct	style_zone	border;
	struct	style_zone	padding;

	/* ------------------------------- */
	/* Adjust total output for margins */
	/* ------------------------------- */
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
	dy += margin.y;

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
	dy += margin.h;

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
	dx += margin.x;
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
	dx += margin.w;

	optr->vph -= dy; optr->vpw -= dx;

	/* ------------------------ */
	/* Calculate Padding Values */
	/* ------------------------ */

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

	/* ----------------------------------------------------------- */
	/* calculate position, dimensions, margins, border and padding */
	/* ----------------------------------------------------------- */
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

	/* ----------------------------------------- */
	/* Calculate Content position and Dimensions */
	/* ----------------------------------------- */
	switch ( sptr->cellwidth.type ) {
		case	_AUTO_DIMENSION	:
			content.w = optr->nbx;
			break;
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
		}

	switch ( sptr->cellheight.type ) {
		case	_AUTO_DIMENSION	:
			content.h = optr->nby;
			break;
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
		}

	/* ----------------------------------------------- */
	/* Calculate border position and sizes information */
	/* ----------------------------------------------- */
	
	border.y = content.y;	border.h = content.h;
	border.x = content.x; 	border.w = content.w; 

	if ( sptr->cellheight.type != _TEXT_DIMENSION )
		border.h += ((padding.y+padding.h)+(sptr->bordersize.left.value+sptr->bordersize.right.value));
		
	if ( sptr->cellwidth.type != _TEXT_DIMENSION )
		border.w += ((padding.x+padding.w)+(sptr->bordersize.left.value+sptr->bordersize.right.value));

	/* ---------------------------------------------- */
	/* Adjust Content Position for Border and Padding */
	/* ---------------------------------------------- */
	switch ( sptr->bordertype.top ) {
		case	_keyword_disk	:
			content.x += border.w/4;
			content.y += border.h/4;
			break;
		default			:
			content.x += (padding.x+sptr->bordersize.left.value);
			content.y += (padding.y+sptr->bordersize.top.value);
			break;
		}
	if ( sptr->cellheight.type == _TEXT_DIMENSION )
		content.h -= (sptr->bordersize.top.value + sptr->bordersize.bottom.value );

	if ( sptr->cellwidth.type == _TEXT_DIMENSION )
		content.w -= (sptr->bordersize.left.value + sptr->bordersize.right.value );

#ifdef	_DEBUG_VISUAL_STYLE
	printf("content (%u,%u,%u,%u) margin ( %u,%u,%u,%u ) border( %u, %u, %u, %u ) padding( %u, %u,%u,%u )\r\n",
		content.x,content.y,content.w,content.h,
		margin.x,margin.y,margin.w,margin.h,
		border.x,border.y,border.w,border.h,
		padding.x,padding.y,padding.w,padding.h
		);
#endif
	/* ------------------------------- */
	/* Fill Eventual Background Colour */
	/* ------------------------------- */
	switch ((qstyle = sptr->bordertype.top)) {

		case	_keyword_solid		:
		case	_keyword_double		:
		case	_keyword_dashed		:
		case	_keyword_dotted		:
		case	_keyword_none		:
			if ( sptr->backgroundcolour.entry != 0 )
				filzone(border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					sptr->backgroundcolour.entry);
			break;

		case	_keyword_disk	:
			if ( sptr->backgroundcolour.entry != 0 )
				visual_filzone(
					border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					sptr->backgroundcolour.entry,3);
			break;
		case	_keyword_rounded	:
			if ( sptr->backgroundcolour.entry != 0 )
				visual_filzone(
					border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					sptr->backgroundcolour.entry,14);
			break;
		}


	/* ------------------ */
	/* Drame Frame border */
	/* ------------------ */
	switch ( sptr->bordertype.top ) {
		case	_keyword_url		:
			if ( sptr->bordertype.leftimage ) {
				visual_image(
					border.x+margin.x,border.y+margin.y,
					sptr->bordersize.left.value,border.h,
					sptr->bordertype.leftimage,
					sptr->backgroundalign );
				}
			if ( sptr->bordertype.rightimage ) {
				visual_image(
					border.x+margin.x+border.w-sptr->bordersize.right.value,border.y+margin.y,
					sptr->bordersize.right.value,border.h,
					sptr->bordertype.rightimage,
					sptr->backgroundalign );
				}
			if ( sptr->bordertype.topimage ) {
				visual_image(
					border.x+margin.x,border.y+margin.y,
					border.w,sptr->bordersize.top.value,
					sptr->bordertype.topimage,
					sptr->backgroundalign );
				}
			if ( sptr->bordertype.bottomimage ) {
				visual_image(
					border.x+margin.x,border.y+margin.y+border.h-sptr->bordersize.bottom.value,
					border.w,sptr->bordersize.bottom.value,
					sptr->bordertype.bottomimage,
					sptr->backgroundalign );
				}
			break;

		case	_keyword_outset		:
			visual_frame(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,1);
			break;

		case	_keyword_inset		:
			visual_frame(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,2);
			break;

		case	_keyword_ridge		:
			visual_frame(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,3);
			break;

		case	_keyword_groove		:
			visual_frame(	border.x+margin.x,border.y+margin.y,
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

		case	_keyword_solid		:
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					sptr->bordercolour.entry,1);
			break;

		case	_keyword_double		:
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					sptr->bordercolour.entry,1);
			visual_filzone(	border.x+margin.x+2,border.y+margin.y+2,
					border.w-4,border.h-4,
					sptr->bordercolour.entry,1);
			break;

		case	_keyword_dashed		:
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					sptr->bordercolour.entry,15);
			visual_filzone(	border.x+margin.x+2,border.y+margin.y+2,
					border.w-4,border.h-4,
					sptr->bordercolour.entry,15);
			break;

		case	_keyword_dotted		:
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					sptr->bordercolour.entry,15);
				break;

		case	_keyword_disk    	:
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					sptr->bordercolour.entry,2);
			break;

		case	_keyword_rounded	:
			visual_filzone(	border.x+margin.x,border.y+margin.y,
					border.w,border.h,
					sptr->bordercolour.entry,14);
			break;

		}

	/* --------------------------------- */
	/* Display eventual background image */
	/* --------------------------------- */
	if ( sptr->backgroundimage ) {

		/* ----------------------- */
		/* adjust to inside border */
		/* ----------------------- */
		border.x += sptr->bordersize.left.value;
		border.y += sptr->bordersize.top.value;
		border.w -= (sptr->bordersize.left.value+sptr->bordersize.right.value);
		border.h -= (sptr->bordersize.top.value+sptr->bordersize.bottom.value);
		if ( qstyle != _keyword_disk ) {
			visual_image(
				border.x+margin.x,border.y+margin.y,
				border.w,border.h,
				sptr->backgroundimage,
				sptr->backgroundalign );
			}
		}

	/* ----------------------- */
	/* Display Message or Text */
	/* ----------------------- */
	switch ( sptr->nature ) {
		case	_keyword_none	:
			break;
		case	_keyword_text	:
			if ( sptr->textfont != 0 ) {
				holder[0] = set_letter_spacing( sptr->letterspacing.value );
				holder[1] = set_line_spacing( sptr->linespacing.value );
				visual_text	(
					content.x+margin.x,content.y+margin.y,
					content.w,content.h,
					sptr->textfont,
					sptr->textcolour.entry,
					(qstyle == _keyword_disk ? 0 : sptr->backgroundcolour.entry),	
					optr->message,optr->length,
					( sptr->textalign | sptr->textatribut ));
				set_line_spacing( holder[1] );
				set_letter_spacing( holder[0] );
				}
			break;
		case	_keyword_url	:
			visual_image	(
				content.x+margin.x,content.y+margin.y,
				content.w,content.h,
				optr->message,
				( sptr->textalign | sptr->textatribut ));
			break;
		}

	return(0);
}

