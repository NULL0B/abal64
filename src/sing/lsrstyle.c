#ifndef	_lsrstyle_c
#define	_lsrstyle_c

#include "styleobj.h"
#include "varrow.h"

static	int	ImageQuality=0;

static	void	laser_zone( FILE * handle, int x, int y, int w, int h, int colour, int style )
{
	return;
}


static	int	laser_apply_style(FILE * handle, struct element_style * sptr, struct style_object * optr )
{
	int			hrf;		/* hold rounding factor */
	int			a;
	int			holder[5];
	int			dx=0,dy=0;
	int			qstyle;
	struct	style_zone	content;
	struct	style_zone	margin;
	struct	style_zone	border;
	struct	style_zone	corner;
	struct	style_zone	frame;
	struct	style_zone	padding;

	struct standard_image *	iptr=(struct standard_image *) 0;
	struct standard_image * load_visual_image( char * filename );
	int			colourmapped=get_pixel_format();

	sptr->applied++;

	/* Detect replaced content and resolve it */
	/* -------------------------------------- */
	if ( sptr->nature  == _keyword_url ) {
		if ((iptr = load_visual_image(optr->message)) != (struct standard_image *) 0) {
			if ( sptr->cellwidth.type  == _FIXED_DIMENSION )
				optr->nbx = iptr->columns;
			if ( sptr->cellheight.type  == _FIXED_DIMENSION )
				optr->nby = iptr->rows;
			}
		}

	/* Calculate Cell Width */
	/* -------------------- */
	switch ( sptr->cellwidth.type ) {
		case	_PLUS_DIMENSION	:
			content.w = optr->nbx+sptr->cellwidth.value;
			break;
		case	_CELL_DIMENSION	:
			if ( sptr->nature  == _keyword_url )
				content.w = optr->nbx;
			else if (!( sptr->textfont ))
				content.w = optr->nbx;
			else	content.w = textsizelen(sptr->textfont,optr->message,optr->length);
			content.w += sptr->paddingsize.left.value;
			content.w += sptr->paddingsize.right.value;
			content.w += sptr->bordersize.left.value;
			content.w += sptr->bordersize.right.value;
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
		case	_FIXED_DIMENSION:
		case	_AUTO_DIMENSION	:
		default			:
			content.w = optr->nbx;
			break;
			
		}

	/* Calculate Cell Height */
	/* --------------------- */
	switch ( sptr->cellheight.type ) {
		case	_PLUS_DIMENSION	:
			content.h = optr->nby+sptr->cellheight.value;
			break;
		case	_CELL_DIMENSION	:
			if ( sptr->nature  == _keyword_url )
				content.h = optr->nby;
			else if (!( sptr->textfont ))
				content.h = optr->nby;
			else	content.h = ((guifontsize(sptr->textfont) >> 8) & 0x00FF);
			content.h += sptr->paddingsize.top.value;
			content.h += sptr->paddingsize.bottom.value;
			content.h += sptr->bordersize.top.value;
			content.h += sptr->bordersize.bottom.value;
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
		case	_FIXED_DIMENSION:
		case	_AUTO_DIMENSION	:
		default			:
			content.h = optr->nby;
			break;
		}


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

			/* ---------------------- */
			/* F L O A T :  N O N E ; */
			/* ---------------------- */
			/* Calculate Cell Position */
			/* ----------------------- */
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
						default				:
							content.x = optr->lmi;
							}
	
					switch ( sptr->cellposition.top.type ) {
						case	_PIXEL_DIMENSION	:
							content.y = sptr->cellposition.top.value;
							break;
	
						case	_PERCENT_DIMENSION	:
							content.y = optr->tmi + ((optr->vph*sptr->cellposition.top.value)/100);
							break;
						default				:
							content.y = optr->tmi;
						}
					break;

				case	_keyword_relative	:

					switch ( sptr->cellposition.left.type ) {
						case	_PIXEL_DIMENSION	:
							content.x = optr->atx + sptr->cellposition.left.value;
							break;
		
						case	_PERCENT_DIMENSION	:
							content.x = optr->atx + ((optr->nbx*sptr->cellposition.left.value)/100);
							break;

						case	_AUTO_DIMENSION		:
	
							switch ( sptr->cellposition.right.type ) {
								case	_PIXEL_DIMENSION	:
									content.x = optr->atx + (optr->nbx - sptr->cellposition.right.value);
									break;
	
								case	_PERCENT_DIMENSION	:
									content.x = optr->atx + (optr->nbx - ((optr->nbx*sptr->cellposition.right.value)/100));
									break;
								default				:
									content.x = optr->atx;
								}
							break;
						default				:
							content.x = optr->atx;
	
						}

					switch ( sptr->cellposition.top.type ) {
						case	_PIXEL_DIMENSION	:
							content.y = optr->aty + sptr->cellposition.top.value;
							break;

						case	_PERCENT_DIMENSION	:
							content.y = optr->aty + ((optr->nby*sptr->cellposition.top.value)/100);
							break;
						case	_AUTO_DIMENSION		:
							switch ( sptr->cellposition.bottom.type ) {
								case	_PIXEL_DIMENSION	:
									content.y = optr->aty + (optr->nby - sptr->cellposition.bottom.value);
									break;

								case	_PERCENT_DIMENSION	:
									content.y = optr->aty + (optr->nby - ((optr->nby*sptr->cellposition.bottom.value)/100));
									break;
								default				:
									content.y = optr->aty;
								}
							break;
	
						default				:
							content.y = optr->aty;
						}
					break;
	
				case	_keyword_static		:
				case	_keyword_auto	:
				default			:
					content.x =  optr->atx;
					content.y =  optr->aty;
					break;

				}
			break;


		}		

	/* Calculate Content Padding */
	/* ------------------------- */
	switch ( sptr->paddingsize.top.type ) {
		case	_PIXEL_DIMENSION :
			padding.y = sptr->paddingsize.top.value;
			break;
		case	_PERCENT_DIMENSION :
			padding.y = ((content.h*sptr->paddingsize.top.value)/100);
			break;
		default			:
			padding.y = 0;
		}

	switch ( sptr->paddingsize.bottom.type ) {
		case	_PIXEL_DIMENSION :
			padding.h = sptr->paddingsize.bottom.value;
			break;
		case	_PERCENT_DIMENSION :
			padding.h = ((content.h*sptr->paddingsize.bottom.value)/100);
			break;
		default			:
			padding.h = 0;
		}

	switch ( sptr->paddingsize.left.type ) {
		case	_PIXEL_DIMENSION :
			padding.x = sptr->paddingsize.left.value;
			break;
		case	_PERCENT_DIMENSION :
			padding.x = ((content.w*sptr->paddingsize.left.value)/100);
			break;
		default			:
			padding.x = 0;
		}

	switch ( sptr->paddingsize.right.type ) {
		case	_PIXEL_DIMENSION :
			padding.w = sptr->paddingsize.right.value;
			break;
		case	_PERCENT_DIMENSION :
			padding.w = ((content.w*sptr->paddingsize.right.value)/100);
			break;
		default			:
			padding.w = 0;
		}


	/* Calculate Margins */
	/* ----------------- */
	switch ( sptr->marginsize.top.type ) {
		case	_PIXEL_DIMENSION :
			margin.y = sptr->marginsize.top.value;
			break;
		case	_PERCENT_DIMENSION :
			margin.y = ((content.h*sptr->marginsize.top.value)/100);
			break;
		default			:
			margin.y = 0;
		}

	switch ( sptr->marginsize.bottom.type ) {
		case	_PIXEL_DIMENSION :
			margin.h = sptr->marginsize.bottom.value;
			break;
		case	_PERCENT_DIMENSION :
			margin.h = ((content.h*sptr->marginsize.bottom.value)/100);
				break;
		default			:
			margin.h = 0;
		}

	switch ( sptr->marginsize.left.type ) {
		case	_PIXEL_DIMENSION :
			margin.x = sptr->marginsize.left.value;
			break;
		case	_PERCENT_DIMENSION :
			margin.x = ((content.w*sptr->marginsize.left.value)/100);
			break;
		default			:
			margin.x = 0;
		}
	switch ( sptr->marginsize.right.type ) {
		case	_PIXEL_DIMENSION :
			margin.w = sptr->marginsize.right.value;
			break;
		case	_PERCENT_DIMENSION :
			margin.w = ((content.w*sptr->marginsize.right.value)/100);
			break;
		default			:
			margin.w = 0;
		}



	/* Calculate Border Frame Dimensions */
	/* --------------------------------- */

	border.x = content.x; border.y = content.y;
	border.w = content.w; border.h = content.h;

	switch ( sptr->bordersize.top.type ) {
		case	_PIXEL_DIMENSION :
			frame.y = sptr->bordersize.top.value;
			break;
		case	_PERCENT_DIMENSION :
			frame.y = ((border.h*sptr->bordersize.top.value)/100);
			break;
		default			:
			frame.y = 0;
		}

	switch ( sptr->bordersize.bottom.type ) {
		case	_PIXEL_DIMENSION :
			frame.h = sptr->bordersize.bottom.value;
			break;
		case	_PERCENT_DIMENSION :
			frame.h = ((border.h*sptr->bordersize.bottom.value)/100);
			break;
		default			:
			frame.h = 0;
		}

	switch ( sptr->bordersize.left.type ) {
		case	_PIXEL_DIMENSION :
			frame.x = sptr->bordersize.left.value;
			break;
		case	_PERCENT_DIMENSION :
			frame.x = ((border.w*sptr->bordersize.left.value)/100);
			break;
		default			:
			frame.x = 0;
		}

	switch ( sptr->bordersize.right.type ) {
		case	_PIXEL_DIMENSION :
			frame.w = sptr->bordersize.right.value;
			break;
		case	_PERCENT_DIMENSION :
			frame.w = ((border.w*sptr->bordersize.right.value)/100);
			break;
		default			:
			frame.w = 0;
		}
		
	/* ----------------------- */
	/* Apply margin colour now */
	/* ----------------------- */
	if ( sptr->margincolour.entry != 0 ) {
		laser_filzone(handle,border.x,border.y,
			border.w,border.h,
			sptr->margincolour.entry
			);
		}
	/* ----------------------------- */
	/* Display eventual margin image */
	/* ----------------------------- */
	if ( sptr->marginimage ) {
		visual_image(
			border.x,border.y,
			border.w,border.h,
			sptr->marginimage,
			sptr->marginalign  | ImageQuality);
		}


	/* ----------------------------------------------- */
	/* Adjust Border Position and Dimension for Margin */
	/* ----------------------------------------------- */
	border.x += margin.x; border.y += margin.y;
	
	/* Watch out for Textual Content : */
	/* ------------------------------- */
	switch ( sptr->cellwidth.type ) {
		case	_TEXT_DIMENSION	:
			border.w += (frame.x+frame.w+padding.x+padding.w);
			break;
		default			:
			if (( margin.x+margin.w) <= border.w )
				border.w -= (margin.x+margin.w);
			else	border.x = 0;
		}

	switch ( sptr->cellheight.type ) {
		case	_TEXT_DIMENSION	:
			border.h += (frame.y+frame.h+padding.y+padding.h);
			break;
		default			:
			if ((margin.y+margin.h) <= border.h)
				border.h -= (margin.y+margin.h);
			else	border.h = 0;
		}

#ifdef	_TRACE_STYLE
	showzone( "initial ", &content );
	showzone( "margin  ", &margin  );
	showzone( "border  ", &border  );
	showzone( "frame   ", &frame   );
	showzone( "padding ", &padding );
#endif
	/* ------------------ */
	/* Drame Frame border */
	/* ------------------ */
	switch ((qstyle = sptr->bordertype.top)) {
		case	_keyword_url		:

			corner.x = corner.y = corner.w = corner.h = 0;

			if ( sptr->bordertype.topleftimage     ) {
				visual_image(
					border.x,border.y,
					frame.x,frame.y,
					sptr->bordertype.topleftimage,
					sptr->borderalign | ImageQuality );
				corner.x = frame.x;
				}
			if ( sptr->bordertype.bottomleftimage ) {
				visual_image(
					border.x,border.y+(border.h-frame.h),
					frame.x,frame.y,
					sptr->bordertype.bottomleftimage,
					sptr->borderalign | ImageQuality );
				corner.y = frame.x; 
				}
			if ( sptr->bordertype.toprightimage     ) {
				visual_image(
					border.x+(border.w-frame.w),border.y,
					frame.x,frame.y,
					sptr->bordertype.toprightimage,
					sptr->borderalign | ImageQuality );
				corner.w = frame.w;
				}
			if ( sptr->bordertype.bottomrightimage ) {
				visual_image(
					border.x+(border.w-frame.w),
					border.y+(border.h-frame.h),
					frame.x,frame.y,
					sptr->bordertype.bottomrightimage,
					sptr->borderalign | ImageQuality );
				corner.h = frame.w;
				}

			if ( sptr->bordertype.topimage ) {
				if ( border.w > (corner.x+corner.w)) {
					visual_image(
						border.x+corner.x,border.y,
						border.w-(corner.x+corner.w),frame.y,
						sptr->bordertype.topimage,
						sptr->borderalign | ImageQuality );
					}
				}
			if ( sptr->bordertype.bottomimage ) {
				if ( border.w > (corner.y+corner.h)) {
					visual_image(
						border.x+corner.y,border.y+(border.h-frame.h),
						border.w-(corner.y+corner.h),frame.h,
						sptr->bordertype.bottomimage,
						sptr->borderalign  | ImageQuality);
					}
				}
			if ( sptr->bordertype.rightimage ) {
				if ( border.h > (frame.y+frame.h)) {
					visual_image(
						border.x+(border.w-frame.w),
						border.y+frame.y,
						frame.w,
						border.h-(frame.y+frame.h),
						sptr->bordertype.rightimage,
						sptr->borderalign  | ImageQuality);
					}
				}
			if ( sptr->bordertype.leftimage ) {
				if ( border.h > (frame.y+frame.h)) {
					visual_image(
						border.x,border.y+frame.y,
						frame.x,
						border.h-(frame.y+frame.h),
						sptr->bordertype.leftimage,
						sptr->borderalign  | ImageQuality);
					}
				}
			break;

		case	_keyword_outset		:
			if (!( sptr->backgroundalign & _ALIGN_SPRITE ))
				visual_frame(	border.x,border.y,
						border.w,border.h,1);
			else	relief_frame(	border.x,border.y,
						border.w,border.h,1);
			break;

		case	_keyword_inset		:
			if (!( sptr->backgroundalign & _ALIGN_SPRITE ))
				visual_frame(	border.x,border.y,
						border.w,border.h,2);
			else	relief_frame(	border.x,border.y,
						border.w,border.h,2);
			break;

		case	_keyword_ridge		:
			if (!( sptr->backgroundalign & _ALIGN_SPRITE ))
				visual_frame(	border.x,border.y,
						border.w,border.h,3);
			else	relief_frame(	border.x,border.y,
						border.w,border.h,1);
			break;

		case	_keyword_groove		:
			if (!( sptr->backgroundalign & _ALIGN_SPRITE ))
				visual_frame(	border.x,border.y,
						border.w,border.h,4);
			else	relief_frame(	border.x,border.y,
						border.w,border.h,1);
			break;

		case	_keyword_edit		:
			visual_frame(	handle,border.x,border.y,
					border.w,border.h,5);
			break;

		case	_keyword_convex		:
			laser_zone(	handle, border.x,border.y,
					border.w,border.h,0,10);
			break;

		case	_keyword_concave	:
			laser_zone(	handle,border.x,border.y,
					border.w,border.h,0,11);
			break;
		case	_keyword_solid		:
			laser_zone(	handle,border.x,border.y,
					border.w,border.h,
					sptr->bordercolour.entry,
					1);
			break;

		case	_keyword_fill		:
			/* top edge */
			laser_zone(	handle,border.x,border.y,
					border.w,frame.y,
					sptr->bordercolour.entry,
					0);
			/* bottom edge */
			laser_zone(	handle,border.x,border.y,
					border.w,frame.h,
					sptr->bordercolour.entry,
					0);
			/* left edge */
			laser_zone(	handle,border.x,border.y,
					frame.x,border.h,
					sptr->bordercolour.entry,
					0);
			/* right edge */
			laser_zone(	handle,border.x,border.y,
					frame.w,border.h,
					sptr->bordercolour.entry,
					0);
			break;

		case	_keyword_double		:
			laser_zone(	handle,border.x,border.y,
					border.w,border.h,
					sptr->bordercolour.entry,
					1);
			laser_zone(	handle,border.x+2,border.y+2,
					border.w-4,border.h-4,
					sptr->bordercolour.entry,
					1);
			break;

		case	_keyword_dashed		:
			laser_zone(	handle,border.x,border.y,
					border.w,border.h,
					sptr->bordercolour.entry,
					15);
			laser_zone(	handle,border.x+2,border.y+2,
					border.w-4,border.h-4,
					sptr->bordercolour.entry,
					15);
			break;

		case	_keyword_dotted		:
			laser_zone(	handle,border.x,border.y,
					border.w,border.h,
					sptr->bordercolour.entry,
					15);
				break;

		case	_keyword_shade    	:
			laser_zone(	handle,border.x,border.y,
					border.w,border.h,
					sptr->bordercolour.entry,
					16);
			break;
		case	_keyword_hole    	:
#ifdef	ABAL32A
			laser_zone(	handle,border.x,border.y,
					border.w,border.h,
					sptr->bordercolour.entry,
					17);
			break;
#endif
		case	_keyword_disk    	:
			laser_zone(	handle,border.x,border.y,
					border.w,border.h,
					sptr->bordercolour.entry,
					2);
			break;

		case	_keyword_rounded	:
			if ( sptr->rounding != -1 ) {
				hrf = set_rounding_factor( sptr->rounding );
				}
			laser_zone(	handle,border.x,border.y,
					border.w,border.h,
					sptr->bordercolour.entry,
					14);
			if ( sptr->rounding != -1 ) {
				hrf = set_rounding_factor( hrf );
				}
			break;

		}
	
	/* Step Inside Border */
	/* ------------------ */
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
	switch (sptr->bordertype.top) {

		case	_keyword_shade    	:
			if (( frame.w ) || ( frame.h )) {
				/* do not double shade */
				laser_zone(	handle,border.x,border.y,
					border.w,border.h,
					sptr->backgroundcolour.entry,
					16);
				}
			break;
		case	_keyword_hole	:
#ifdef	ABAL32A
			if ( sptr->backgroundcolour.entry != 0 )
				laser_zone(
					handle,border.x,border.y,
					border.w,border.h,
					sptr->backgroundcolour.entry,
					17);
			break;
#endif
		case	_keyword_disk	:
			if ( sptr->backgroundcolour.entry != 0 )
				laser_zone(
					handle,border.x,border.y,
					border.w,border.h,
					sptr->backgroundcolour.entry,
					3);
			break;

		case	_keyword_rounded	:
			if ( sptr->backgroundcolour.entry != 0 ) {
				if ( sptr->rounding ) {
					hrf = set_rounding_factor( sptr->rounding );
					}
				laser_zone(
					handle,border.x,border.y,
					border.w,border.h,
					sptr->backgroundcolour.entry,
					14);
				if ( sptr->rounding ) {
					hrf = set_rounding_factor( hrf );
					}
				}
			break;

		default				:
			if ( sptr->backgroundcolour.entry != 0 ) {
				if (!( sptr->backgroundalign & _ALIGN_SPRITE )) {
					laser_filzone(handle,border.x,border.y,
						border.w,border.h,
						sptr->backgroundcolour.entry
						);
					}
				else	{
					laser_zone(	handle,border.x,border.y,
						border.w,border.h, 
						sptr->backgroundcolour.entry,
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
		if ( qstyle != _keyword_disk ) {
			laser_image(
				handle,
				border.x,border.y,
				border.w,border.h,
				sptr->backgroundimage,
				(char *) 0,
				sptr->backgroundalign  | ImageQuality);
			}
		}


	/* ------------------ */
	/* Drame Frame border */
	/* ------------------ */
	switch ((qstyle = sptr->bordertype.top)) {
#ifdef	ABAL32A
		case	_keyword_vconvex		:
			laser_zone(	handle,border.x,border.y,
					border.w,border.h,
					sptr->bordercolour.entry,
					18);
			break;

		case	_keyword_hconvex		:
			laser_zone(	handle,border.x,border.y,
					border.w,border.h,
					sptr->bordercolour.entry,
					19);
			break;

		case	_keyword_vconcave	:
			laser_zone(	handle,border.x,border.y,
					border.w,border.h,
					sptr->bordercolour.entry,
					20);
			break;

		case	_keyword_hconcave	:
			laser_zone(	handle,border.x,border.y,
					border.w,border.h,
					sptr->bordercolour.entry,
					21);
			break;
		case	_keyword_rounded	:
			if ( sptr->backgroundcolour.entry != 0 ) {
				if ( sptr->rounding ) {
					hrf = set_rounding_factor( sptr->rounding );
					}
				laser_zone(
					handle,border.x,border.y,
					border.w,border.h,
					sptr->backgroundcolour.entry,
					13);
				if ( sptr->rounding ) {
					hrf = set_rounding_factor( hrf );
					}
				}
#endif
		default				:
			break;
		}

	/* Step over Eventual Padding */
	/* -------------------------- */
	content.x = (border.x+padding.x); 
	content.y = (border.y+padding.y);
	content.w = (border.w - (padding.x+padding.w)); 
	content.h = (border.h - (padding.y+padding.h)); 

#ifdef	_TRACE_STYLE
	showzone( "final   ", &content );
#endif
	/* ----------------------- */
	/* Display Message or Text */
	/* ----------------------- */
	switch ( sptr->nature ) {
		case	_keyword_none	:
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
				visual_trigger (
					content.x,content.y,
					content.w,content.h,
					sptr->textfont,
					sptr->textcolour.entry,
					0,
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
				visual_text (
					content.x,content.y,
					content.w,content.h,
					sptr->textfont,
					sptr->textcolour.entry,
					0,
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
			if ( iptr ) {
				switch ( sptr->textalign ) {
					case	_ALIGN_RIGHT	:
						if ( iptr->columns < content.w ) {
							a = (content.w - iptr->columns);
							content.x += a;
							content.w = iptr->columns;
							}
						if ( iptr->rows < content.h ) {
							a = (content.h - iptr->rows);
							content.y += a;
							content.h = iptr->rows;
							}
						break;
					case	_ALIGN_CENTER	:
					case	_ALIGN_JUSTIFY	:
						if ( iptr->columns < content.w ) {
							a = (content.w - iptr->columns);
							content.x += (a/2);
							content.w = iptr->columns;
							}
						if ( iptr->rows < content.h ) {
							a = (content.h - iptr->rows);
							content.y += (a/2);
							content.h = iptr->rows;
							}

					}
				}
			laser_image	(
				handle,
				content.x,content.y,
				content.w,content.h,
				optr->message,
				(char *) 0,
				( sptr->textalign | sptr->textatribut  | ImageQuality));
			break;
		}

	return(0);
}

int	laser_style( FILE * handle, int x, int y, int w, int h, char * style, char * mptr, int mlen )
{
	struct	style_object	context;
	struct	element_style * sptr;
	if (!( sptr = resolve_style_class( style ) ))
		return(78);
	else
	{
		memset(&context,0,sizeof(struct style_object));
		context.atx = x;	context.aty = y;	
		context.nbx = w;	context.nby = h;
		context.message = mptr;
		context.length  = mlen;
		laser_apply_style( handle, sptr, &context );
		return(0);
	}
}


	/* ----------- */
#endif	/* _lsrstyle_c */
	/* ----------- */


