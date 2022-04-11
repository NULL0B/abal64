#ifndef	_singBIFS_c
#define	_singBIFS_c

#define	_EXT_PROTO	".bth"

static	struct	bifs_configuration {
	int	KeySensorID;
	int	KeySensorOD;
	int	fontWidth;
	int	fontHeight;

	int	od;
	int	es;

	int	width;
	int	height;

	int	AudioLevel;
	int	VisualLevel;
	int	SceneLevel;
	int	GraphicsLevel;
	int	ODLevel;

	} BC = 	{ 
		0,0,
		0,0,
		0,0,
		800,600,
		254,254,254,254,254 
		};


void	bifs_open_tag( FILE * h, char * nptr )
{
	mpeg_indent(h);
	fprintf(h,"%s {\n",nptr);
	mpeg_enter();
	return;
}

void	bifs_close_tag( FILE * h, char * nptr )
{
	mpeg_indent(h);
	fprintf(h,"}\n");
	mpeg_leave();
}

void	bifs_end_tag( FILE * h, int v )
{
	if ( v )
		bifs_close_tag( h, "empty" );
	return;
}

void	bifs_end_collection( FILE * h, int v )
{
	if ( v )
		bifs_close_collection( h, "empty" );
	return;
}

void	bifs_tag( FILE * h, char * nptr )
{
	bifs_open_tag(h,nptr);
	bifs_end_tag(h,0);
	return;
}

void	bifs_def_tag( FILE * h, char * nptr, char * xptr )
{
	mpeg_indent(h);
	fprintf(h,"DEF %s %s {\n",xptr,nptr);
	mpeg_enter();
	return;
}

void	bifs_touch_sensor( FILE * h, char * nptr )
{
	mpeg_indent(h);
	fprintf(h,"DEF SENSOR_%s %s {}\n",nptr,"TouchSensor");
	return;
}

void	bifs_edit_route( FILE * h, char * nptr )
{
	mpeg_indent(h);
	fprintf(h,"ROUTE SENSOR_%s.isActive TO FOCUS_%s.width\n",nptr,nptr);
	return;
}

void	bifs_field( FILE * h, char * nptr, char * vptr )
{
	mpeg_indent(h);
	fprintf(h,"%s %s\n",nptr, vptr);
	return;
}

void	bifs_quoted( FILE * h, char * nptr, char * vptr )
{
	mpeg_indent(h);
	fprintf(h,"%s %c%s%c\n",nptr, 0x0022,vptr,0x0022);
	return;
}

void	bifs_string( FILE * h, char * nptr, char * vptr )
{
	mpeg_indent(h);
	fprintf(h,"%s %c%s%c\n",nptr, 0x0022,vptr,0x0022);
	return;
}

/*	----------------------------------------	*/
/*	    b i f s _ s t r i n g _ p a i r 		*/
/*	----------------------------------------	*/
/*	used for text alignment or justification 	*/
/*	----------------------------------------	*/
void	bifs_string_pair( FILE * h, char * nptr, char * vptr, char * wptr )
{
	mpeg_indent(h);
	fprintf(h,"%s [ %c%s%c %c%s%c ]\n",nptr, 0x0022,vptr,0x0022, 0x0022,wptr,0x0022);
	return;
}

void	bifs_integer_field( FILE * h, char * nptr, int vptr )
{
	char	value[32];
	sprintf(value,"%d",vptr);
	bifs_field(h,nptr,value);
	return;
}

void	bifs_collection( FILE * h, char * nptr )
{
	mpeg_indent(h);
	fprintf(h,"%s [\n",nptr);
	mpeg_enter();
	return;
}


void	bifs_close_collection( FILE * h, char * nptr )
{
	mpeg_indent(h);
	fprintf(h,"]\n");
	mpeg_leave();
}

void	bifs_background( FILE * h, int colour )
{
	char	work[1024];
	mpeg_colour( (colour & 0x00FF) , work);
	bifs_tag(h,"Background");
		bifs_field(h,"skyColor",work);
	bifs_end_tag(h,1);
	return;
}

void	bifs_background2d( FILE * h, int colour,char * member )
{
	char	work[1024];
	if ( member )
		sprintf( work,"%s Background2D",member);
	else	strcpy(work,"Background2D");
	bifs_tag(h,work);
		mpeg_colour( (colour & 0x00FF) , work);
		bifs_field(h,"backColor",work);
	bifs_end_tag(h,1);
	return;
}

void	bifs_worldinfo( FILE * h, char * info, char * title )
{
	char	work[1024];
	bifs_tag(h,"WorldInfo");
		bifs_string_pair(h,"info",info,"Copyright (c) Amenesik / Sologic");
		bifs_string(h,"title",title);
	bifs_end_tag(h,1);
	return;
}

void	bifs_material( FILE * handle, char * colour, int filled, int framewidth )
{
	bifs_tag(handle,"appearance Appearance");
		bifs_tag(handle,"material Material2D");
			bifs_field(handle,"emissiveColor",colour);
			if ( filled )
				bifs_field(handle,"filled","true");
			else	bifs_field(handle,"filled","true");
			bifs_tag(handle,"lineProps LineProperties");
				bifs_integer_field(handle,"width",framewidth);
			bifs_close_tag(handle,"lineProps LineProperties");
		bifs_close_tag(handle,"Material2D");
	bifs_close_tag(handle,"appearance");
	return;
}

void	bifs_filzone( FILE * handle, int x, int y, int w, int h, int colour, char * name )
{
	char	work[1024];

	//printf("bifs_filzone( %u,%u, %u,%u : %s )\n",x,y,w,h,(name ? name : "\0" ));

	// --------------------------------
	// generate translation to position
	// --------------------------------
	bifs_tag(handle,"Transform2D");
		mpeg_translation( work, x, y, w, h );
		// printf("bifs_transform( %s )\n",work);
		bifs_field(handle,"translation",work);

	bifs_collection(handle,"children");

	if (!( name ))
		bifs_tag(handle,"Shape");
	else	bifs_def_tag(handle,"Shape",name);

	// ----------------------------
	// generate the widget geometry
	// ----------------------------
	bifs_tag(handle,"geometry Rectangle");
		sprintf(work,"%u %u",w,h);
		bifs_field(handle,"size",work);
		bifs_end_tag(handle,1);

	// ------------------------------
	// generate the widget appearance
	// ------------------------------
	mpeg_colour( (colour & 0x00FF) , work);
	bifs_material(handle,work,1,0);

	// ------------------------------
	// close all open groups and tags 
	// ------------------------------
	bifs_close_tag(handle,"Shape");
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	return;
}

void	bifs_focuszone( FILE * handle, int x, int y, int w, int h, int colour, char * name )
{
	char	work[1024];

	// --------------------------------
	// generate translation to position
	// --------------------------------
	bifs_tag(handle,"Transform2D");
		mpeg_translation( work, x, y, w, h );
		bifs_field(handle,"translation",work);

	bifs_collection(handle,"children");

	bifs_touch_sensor(handle,name);

	bifs_tag(handle,"Shape");

	// ----------------------------
	// generate the widget geometry
	// ----------------------------
	bifs_tag(handle,"geometry Rectangle");
		sprintf(work,"%u %u",w,h);
		bifs_field(handle,"size",work);
		bifs_end_tag(handle,1);

	// ------------------------------
	// generate the widget appearance
	// ------------------------------
	bifs_tag(handle,"appearance Appearance");
		bifs_tag(handle,"material Material2D");
			mpeg_colour( (colour & 0x00FF) , work);
			bifs_field(handle,"emissiveColor",work);
			bifs_field(handle,"filled","false");
			sprintf(work,"lineProps DEF FOCUS_%s LineProperties",name);
			bifs_tag(handle,work);
			bifs_integer_field(handle,"width",0);
			bifs_close_tag(handle,1);
		bifs_close_tag(handle,1);
	bifs_close_tag(handle,"appearance");

	// ------------------------------
	// close all open groups and tags 
	// ------------------------------
	bifs_close_tag(handle,"Shape");
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	return;
}

void	bifs_circle( FILE * handle, int x, int y, int w, int h, int colour, int border, char * name )
{
	char	work[1024];

	// --------------------------------
	// generate translation to position
	// --------------------------------
	bifs_tag(handle,"Transform2D");
		mpeg_translation( work, x, y, w, h );
		bifs_field(handle,"translation",work);

	bifs_collection(handle,"children");

	bifs_touch_sensor(handle,name);

	bifs_tag(handle,"Shape");

	// ----------------------------
	// generate the widget geometry
	// ----------------------------
	bifs_tag(handle,"geometry Circle");
		bifs_integer_field(handle,"radius",( w > h ? h/2 : w / 2 ));
		bifs_end_tag(handle,1);

	// ------------------------------
	// generate the widget appearance
	// ------------------------------
	bifs_tag(handle,"appearance Appearance");
		bifs_tag(handle,"material Material2D");
			mpeg_colour( (colour & 0x00FF) , work);
			bifs_field(handle,"emissiveColor",work);
			bifs_field(handle,"filled","true");
			sprintf(work,"lineProps DEF FOCUS_%s LineProperties",name);
			bifs_tag(handle,work);
				mpeg_colour( (colour & 0x00FF) , work);
				bifs_field(handle,"lineColor",work);
				bifs_integer_field(handle,"width",1);
			bifs_close_tag(handle,1);
		bifs_close_tag(handle,1);
	bifs_close_tag(handle,"appearance");

	// ------------------------------
	// close all open groups and tags 
	// ------------------------------
	bifs_close_tag(handle,"Shape");
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	return;
}

void	bifs_draw_relief(FILE * h, int atx,int aty, int nbx, int nby, int hl, int bg, int ll )
{
	if ( bg != transparent )
		bifs_filzone(h,atx,aty,nbx,nby,bg,(char *) 0);
	bifs_filzone(h,atx,aty,nbx,1,hl,(char *) 0);
	bifs_filzone(h,atx,aty,1,nby,hl,(char *) 0);
	bifs_filzone(h,(atx+nbx),aty,1,nby,ll,(char *) 0);
	bifs_filzone(h,atx,(aty+nby),nbx,1,ll,(char *) 0);
	return;
}

void	bifs_relief( FILE * handle, int atx, int aty, int nbx, int nby, int style, char * name )
{
	int	bg;

	if (( nbx > 0 ) && ( nby > 0 )) {

	switch (( style & _FRAME_TYPE )) {

		case	_RADIO_FRAME :
			bifs_circle(handle, atx,aty,nbx,nby,standard_white,standard_black,name);
			break;

		case	_EDIT_FRAME :
			bifs_draw_relief(handle, atx,aty,nbx,nby,standard_black,standard_white,standard_black);
			break;

		case	_OUTSET_FRAME :
			bifs_draw_relief(handle, atx,aty,nbx,nby,standard_hilight,transparent,standard_lolight);
			break;

		case	_BUTTON_FRAME :
			bifs_draw_relief(handle, atx,aty,nbx,nby,standard_hilight,standard_backwash,standard_lolight);
			break;

		case	_WINDOW_FRAME :
			bifs_draw_relief(handle, atx,aty,nbx,nby,standard_hilight,standard_backwash,standard_lolight);
			break;

		case	_SCROLL_FRAME  :
			bifs_draw_relief(handle, atx,aty,nbx,nby,standard_lolight,standard_backwash-1,standard_hilight);
			break;

		case	_INSET_FRAME  :
			bifs_draw_relief(handle, atx,aty,nbx,nby,standard_lolight,transparent,standard_hilight);
			break;

		case	_RIDGE_FRAME  :
			bifs_draw_relief(handle, atx,aty,nbx,nby,standard_hilight,transparent,standard_lolight);
			if (( nbx > 2 ) && ( nby > 2 )) 
				bifs_draw_relief(handle,(atx+1),(aty+1),(nbx-2),(nby-2),standard_lolight,transparent,standard_hilight);
			break;

		case	_GROOVE_FRAME :
			transparent = transparent;
			bifs_draw_relief(handle, atx,aty,nbx,nby,standard_lolight,transparent,standard_hilight);
			if (( nbx > 2 ) && ( nby > 2 )) 
				bifs_draw_relief(handle, (atx+1),(aty+1),(nbx-2),(nby-2),standard_hilight,transparent,standard_lolight);
			break;

		}
	}
	return;
}

void	bifs_text( FILE * handle, int x, int y, int w, int h, char * mptr, int colour, char * name, int align )
{
	char	work[1024];
	// --------------------------------
	// generate translation to position
	// --------------------------------
	bifs_tag(handle,"Transform2D");
		mpeg_translation( work, x, y, w, h );
		bifs_field(handle,"translation",work);

	bifs_collection(handle,"children");

	if (!( name ))
		bifs_tag(handle,"Shape");
	else	bifs_def_tag(handle,"Shape",name);

	// ----------------------------
	// generate the widget geometry
	// generate the text message
	// ----------------------------
	bifs_tag(handle,"geometry Text");
		bifs_string(handle,"string",mptr);
		bifs_tag(handle,"fontStyle FontStyle");
		if ( align != _A_NONE )
		{
			switch ( align )
			{
				case	_A_NONE	:
				case	_A_LEFT	:
					bifs_string_pair(handle,"justify","FIRST","MIDDLE");
					break;
				case	_A_CENTER	:
				case	_A_JUSTIFY	:
					bifs_string_pair(handle,"justify","MIDDLE","MIDDLE");
					break;
				case	_A_RIGHT	:
					bifs_string_pair(handle,"justify","END","MIDDLE");
					break;
			}
		}
		bifs_integer_field(handle,"size",BC.fontHeight);
		bifs_end_tag(handle,1);
	bifs_end_tag(handle,1);

	// ------------------------------
	// generate the widget appearance
	// ------------------------------
	mpeg_colour( (colour & 0x00FF) , work);
	bifs_material(handle,work,1,0);

	// ------------------------------
	// close all open groups and tags 
	// ------------------------------
	bifs_close_tag(handle,"Shape");
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	return;
}

void	bifs_od_url( FILE * h, char * nptr, int od )
{
	char	work[8192];
	if (!( od ))
	{
		sprintf(work,"[ %c%s%c ]",0x0022,nptr,0x0022);
		bifs_field(h,"url",work);
	}
	else
	{
		sprintf(work,"[ %cod:%u%c ]",0x0022,od,0x0022);
		bifs_field(h,"url",work);
	}
	return;
}

void	bifs_image( FILE * handle, int x, int y, int w, int h, char * iptr, char * name )
{
	char	work[1024];
	// --------------------------------
	// generate translation to position
	// --------------------------------
	bifs_tag(handle,"Transform2D");
		mpeg_translation( work, x, y, w, h );
		bifs_field(handle,"translation",work);

	bifs_collection(handle,"children");

	if (!( name ))
		bifs_tag(handle,"Shape");
	else	bifs_def_tag(handle,"Shape",name);

	// ----------------------------
	// generate the widget geometry
	// generate the text message
	// ----------------------------
	bifs_tag(handle,"geometry Rectangle");
		sprintf(work,"%u %u",w,h);
		bifs_field(handle,"size",work);
		bifs_end_tag(handle,1);

	// ------------------------------
	// generate the widget appearance
	// ------------------------------
	bifs_tag(handle,"appearance Appearance");
		bifs_tag(handle,"material Material2D");
		bifs_field(handle,"filled","true");
		bifs_close_tag(handle,"Material2D");
		if (( detect_extension( iptr, ".png"  ) )
		||  ( detect_extension( iptr, ".jpg"  ) )
		||  ( detect_extension( iptr, ".jpeg" ) )
		||  ( detect_extension( iptr, ".gif"  ) )
		||  ( detect_extension( iptr, ".bmp"  ) ))
		{
			bifs_tag(handle,"texture ImageTexture");
				bifs_od_url( handle, iptr, 0 );
			bifs_close_tag(handle,"ImageTexture");
		}
		else
		{
			bifs_tag(handle,"texture MovieTexture");
				bifs_od_url( handle, iptr, 0 );
			bifs_close_tag(handle,"MovieTexture");
		}
	bifs_close_tag(handle,"appearance");

	// ------------------------------
	// close all open groups and tags 
	// ------------------------------
	bifs_close_tag(handle,"Shape");
	bifs_close_collection(handle,"children");
	bifs_close_tag(handle,"Transform2D");
	return;
}

void	bifs_checkbox( FILE * handle, int x, int y, int w, int h, char * mptr, char * name )
{
	bifs_relief( handle, x,y,BC.fontHeight,BC.fontHeight, _EDIT_FRAME, name);
	bifs_text( handle, x+(2*BC.fontHeight),y,w-(2*BC.fontHeight),h, mptr, 16, (char *) 0,_A_LEFT);
	return;
}

void	bifs_radiobox( FILE * handle, int x, int y, int w, int h, char * mptr, char * name )
{
	bifs_relief( handle, x,y,BC.fontHeight,BC.fontHeight, _RADIO_FRAME, name);
	bifs_text( handle, x+(2*BC.fontHeight),y,w-(2*BC.fontHeight),h, mptr, 16, (char *) 0,_A_LEFT);
	return;
}

void	bifs_button( FILE * handle, int x, int y, int w, int h, char * message, char * name, int align )
{
	if ( align & 1 ) // is image
	{
		if ( align & 2 ) // no frame
		{
			bifs_image( handle, x,y,w,h, message, (char *) 0 );
		}
		else
		{
			bifs_relief( handle, x,y,w,h, _BUTTON_FRAME, name);
			bifs_image( handle, x+2,y+2,w-4,h-4, message, (char *) 0 );
		}
	}
	else
	{
		if (!( align & 2 )) // has frame
		{
			bifs_relief( handle, x,y,w,h, _BUTTON_FRAME, name);
			bifs_text( handle, x+2,y+2,w-4,h-4, message, 15, (char *) 0,_A_CENTER);
		}
		else
		{
			bifs_text( handle, x,y,w,h, message, 15, (char *) 0,_A_CENTER);
		}
	}
}

void	bifs_pushbutton( FILE * h, struct form_item * iptr )
{
	int	isanchor=0;
	switch ( iptr->Contents.datatype )
	{
	case _WIDGET_OVERLAY :
	case _WIDGET_CHAIN   :
	case _WIDGET_SYSTEM  :
	case _WIDGET_TASK    :
	case _WIDGET_LOADGO  :
		if ((isanchor = bifs_anchor(h,iptr->Contents.format )) != 0)
			bifs_collection(h,"children");
		
	}
	bifs_button(
		h,
		iptr->Contents.x, iptr->Contents.y, 
		iptr->Contents.w, iptr->Contents.h, 
		abal_payload( iptr ),
		( iptr->Contents.name  ? iptr->Contents.name : (char *) 0),
		iptr->Contents.align
		);

	if ( isanchor )
	{
		bifs_end_collection(h,1);
		bifs_end_tag(h,1);
	}
	return;
}

void	bifs_tab_button( FILE * handle, struct form_item * iptr )
{
	int	fh = guifontsize(iptr->Contents.font);
	int	fw = (fh & 0x00FF);
	fh >>= 8;
	fh &= 0x00FF;
	bifs_button( handle, 
		iptr->Contents.x+iptr->Contents.adjust,
		iptr->Contents.y,
		iptr->Contents.xlimit,
		(fh + 8 ),
		abal_payload(iptr),
		iptr->Contents.name,
		iptr->Contents.align);
}

void	bifs_tab_frame( FILE * h, struct form_item * iptr )
{
	char	work[1024];
	int	fh = guifontsize(iptr->Contents.font);
	int	fw = (fh & 0x00FF);
	fh >>= 8;
	fh &= 0x00FF;
	bifs_tag(h,"Transform2D");
		mpeg_translation( work, 
				iptr->Contents.x, 
				iptr->Contents.y+(fh+8), 
				iptr->Contents.w, iptr->Contents.h-(fh+8) );
		bifs_field(h,"translation",work);
		bifs_collection(h,"children");
		bifs_tag(h,"Layer2D");
			bifs_background2d(h,standard_backwash,"background");
			sprintf(work,"%u %u",iptr->Contents.w,iptr->Contents.h-(fh+8));
			bifs_field(h,"size",work);
			bifs_collection(h,"children");
				bifs_relief( h, 
					iptr->Contents.x,
					iptr->Contents.y+(fh+8),
					iptr->Contents.w,
					iptr->Contents.h-(fh+8), 
					_OUTSET_FRAME,
					iptr->Contents.name);
	return;
}

void	bifs_edit( FILE * handle, int x, int y, int w, int h, char * name )
{
	// --------------------------------
	// generate translation to position
	// --------------------------------
	bifs_focuszone(handle, x-1,y-1,w+2,h+2, 4, name);
	bifs_relief( handle, x,y,w,h, _EDIT_FRAME, name);
}

void	bifs_window( FILE * handle, int x, int y, int w, int h, char * message, char * name )
{
	bifs_relief( handle, x,y,w,h, _WINDOW_FRAME, (char *) 0);
	bifs_filzone( handle, x+2,y+2,w-4,24, 18, (char *) 0);
	bifs_text( handle, x+2,y+2,w-4,24, message, 15, (char *) 0,_A_LEFT);
	return;
}

void	bifs_scrollframe( FILE * handle, struct form_item * iptr )
{
	int x;
	int y; 
	int w;
	int h;
	x = iptr->Contents.x;
	y = iptr->Contents.y;
	w = iptr->Contents.w;
	h = iptr->Contents.h;
	bifs_relief( handle, x,y,w,h, _SCROLL_FRAME, (char *) 0);
	if ( w > h )
	{
		bifs_relief( handle, x+1,y+1,h-2,h-2, _BUTTON_FRAME, (char *) 0);
		bifs_relief( handle, x+w-(h-1),y+1,h-2,h-2, _BUTTON_FRAME, (char *) 0);
		bifs_relief( handle, x+h, y+1,w-(h*2),h-2, _BUTTON_FRAME, (char *) 0);
	}
	else
	{
		bifs_relief( handle, x+1,y+1,w-2,w-2, _BUTTON_FRAME, (char *) 0);
		bifs_relief( handle, x+1,y+h-(w-1),w-2,w-2, _BUTTON_FRAME, (char *) 0);
		bifs_relief( handle, x+1, y+w,w-2,h-(w*2), _BUTTON_FRAME, (char *) 0);
	}
	return;
}

/*	-------------------------------------------	*/
/*	  b i f s _ p r o t o _ i n s t a n c e 	*/
/*	-------------------------------------------	*/
void	bifs_proto_instance( FILE * h, struct form_control * fptr, char * iname )
{
	char	work[1024];
	bifs_def_tag(h,fptr->identifier,iname);
	bifs_close_tag(h,fptr->identifier);
	return;
}

void	bifs_dataframe( FILE * h, struct form_item * iptr )
{
	char	work[1024];
	char	* fnptr;
	struct	form_control * ffptr;
	struct window_control Window;
	
	if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
		return;
	else if (!( fnptr = abal_payload(iptr) )) 
		return;
	else if (!(ffptr = locate_form_control( fnptr ) ))
		return;
	else
	{
		form_Dimensions( &Window, ffptr );
		bifs_tag(h,"Transform2D");
			mpeg_translation( work, iptr->Contents.x, iptr->Contents.y, Window.w, Window.h );
			bifs_field(h,"translation",work);
			bifs_collection(h,"children");
				bifs_proto_instance(h,ffptr,iptr->Contents.name);
			bifs_close_collection(h,"children");
		bifs_close_tag(h,"Transform2D");
		return;
	}
}


/*	---------------------------------------------------	*/
/*			B I F S _ w i d g e t			*/
/*	---------------------------------------------------	*/
/*	called from the upper level forms production cycle	*/
/*	for the translation of a widget to BiFS.		*/
/*	---------------------------------------------------	*/
void	BIFS_widget( FILE * h, struct form_item * iptr )
{
	char	work[1024];
	int	isdef;
	int	align;

	if (!( iptr )) 	return;

	isdef = is_named_widget( iptr );

	BC.fontWidth  = guifontsize(iptr->Contents.font);
	BC.fontHeight = (BC.fontWidth >> 8); 
	BC.fontWidth  &= 0x00FF;

	switch (iptr->Contents.style)
	{

	case	_FILL_FRAME	:	//	0
		bifs_filzone( 	
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			(iptr->Contents.colour & 0x00FF),
			( isdef ? iptr->Contents.name : (char *) 0)
			);
		break;

	case	_EDIT_FRAME	:	//	5
		bifs_edit( 	
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			iptr->Contents.name
			);
		break;
	case	_OUTSET_FRAME	:	//	1
	case	_INSET_FRAME	:	//	2
	case	_RIDGE_FRAME	:	//	3
	case	_GROOVE_FRAME	:	//	4
		bifs_relief( 	
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			iptr->Contents.style,
			( isdef ? iptr->Contents.name : (char *) 0)
			);
		break;

	case	_TEXT_FRAME	:	//	6
		align = (iptr->Contents.align & 0x0007);
		bifs_text(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			iptr->Contents.colour,
			( isdef ? iptr->Contents.name : (char *) 0),
			align
	
			);
		break;
	case	_IMAGE_FRAME	:	//	7
		bifs_image(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			( isdef ? iptr->Contents.name : (char *) 0)
			);
		break;

	case	_SWITCH_FRAME	:	//	18
	case	_BUTTON_FRAME	:	//	9
		bifs_pushbutton( h, iptr );
		break;

	case	_WINDOW_FRAME	:	//	10
		bifs_window(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			( isdef ? iptr->Contents.name : (char *) 0)
			);
		break;

	case	_CHECK_FRAME	:	//	12
		bifs_checkbox(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			( isdef ? iptr->Contents.name : (char *) 0)
			);
		break;

	case	_SCROLL_FRAME	:	//	16
		bifs_scrollframe( h, iptr );
		break;

	case	_RADIO_FRAME	:	//	13
		if ( isdef )
			sprintf(work,"%s_%u",iptr->Contents.name,iptr->Contents.radio);
		bifs_radiobox(
			h,
			iptr->Contents.x, iptr->Contents.y, 
			iptr->Contents.w, iptr->Contents.h, 
			abal_payload( iptr ),
			( isdef ? work : (char *) 0)
			);
		break;

	case	_DATA_FRAME	:

		bifs_dataframe( h, iptr );
		break;

	case	_LINE_FRAME	:	//	8
	case	_TAB_FRAME	:	//	11
	case	_SELECT_FRAME	:	//	14
	case	_FORM_FRAME	:	//	15
	case	_PROGRESS_FRAME	:	//	17	
	case	_GRAPH_FRAME	:	//	19
		break;

	}
	return;
}

/*	-------------------------------------------	*/
/*	b i f s _ o b j e c t _ d e s c r i p t o r 	*/
/*	-------------------------------------------	*/
/*	adds an object descriptor prior to addition	*/
/*	of scene children to handle images, video	*/
/*	and audio streams as textures in scene.		*/
/*	-------------------------------------------	*/
static	int	od_update_started=0;
int	bifs_start_od_update( FILE * h )
{
	if (!( od_update_started ))
	{
		od_update_started = 1;
		bifs_tag(h,"AT 0");
		bifs_collection(h,"UPDATE OD");
	}
	return(0);
}
int	bifs_close_od_update( FILE * h )
{
	if ( od_update_started )
	{
		bifs_end_collection(h,1);
		bifs_end_tag(h,1);
		od_update_started = 0;
	}
	return(0);
}

int	bifs_object_descriptor( FILE * h, char * nptr )
{
	int	result=0;
	bifs_start_od_update( h );
	bifs_tag(h,"ObjectDescriptor");
		bifs_integer_field(h,"objectDescriptorID",(result = ++BC.od));
		bifs_collection(h,"esDescr");
			bifs_tag(h,"ES_Descriptor");
				bifs_integer_field(h,"ES_ID",++BC.es);
				bifs_tag(h,"muxInfo muxInfo");
					bifs_quoted(h,"fileName", nptr );
				bifs_end_tag(h,1);
			bifs_end_tag(h,1);
		bifs_end_collection(h,1);
	bifs_end_tag(h,1);
	return( result );
}

/*	---------------------------------------------------------	*/
/*	 k e y _ s e n s o r _ o b j e c t _ d e s c r i p t o r 	*/
/*	---------------------------------------------------------	*/
/*	update of the object descriptor for the key sensor stream	*/
/*	---------------------------------------------------------	*/
int	key_sensor_object_descriptor( FILE * h )
{
	int	result=0;
	bifs_tag(h,"AT 0");
		bifs_collection(h,"UPDATE OD");
			bifs_tag(h,"ObjectDescriptor");
				bifs_integer_field(h,"objectDescriptorID",(result = BC.KeySensorOD));
				bifs_collection(h,"esDescr");
					key_sensor_es_descriptor(h);
				bifs_end_collection(h,1);
			bifs_end_tag(h,1);
		bifs_end_collection(h,1);
	bifs_end_tag(h,1);
	return( result );
}

/*	------------------------------------------------------------	*/
/*		k e y _ s e n s o r _ e s _ d e s c r i p t o r		*/
/*	------------------------------------------------------------	*/
/*	this function is called from the initial object descriptor	*/
/*	productionand also from the initial UPDATE OD description.	*/
/*	------------------------------------------------------------	*/
void	key_sensor_es_descriptor( FILE * h )
{
	bifs_tag(h,"ES_Descriptor");
		bifs_integer_field(h,"ES_ID",BC.KeySensorID);
		bifs_tag(h,"decConfigDescr DecoderConfigDescriptor");
			bifs_field(h,"streamType","10");
			bifs_tag(h,"decSpecificInfo UIConfig");
				bifs_string(h,"deviceName","KeySensor");
			bifs_end_tag(h,1);
		bifs_end_tag(h,1);
	bifs_end_tag(h,1);
	return;
}

/*	-------------------------------------------	*/
/*		s i n g _ o p e n _ B i F S  		*/
/*	-------------------------------------------	*/
int	sing_open_BIFS( FILE * h, struct form_control * fptr )
{
	struct	form_item * iptr;

	bifs_tag(h,"InitialObjectDescriptor");
		bifs_integer_field(h,"objectDescriptorID",++BC.od);
		bifs_integer_field(h,"audioProfileLevelIndication",BC.AudioLevel);
		bifs_integer_field(h,"visualProfileLevelIndication",BC.VisualLevel);
		bifs_integer_field(h,"sceneProfileLevelIndication",BC.SceneLevel);
		bifs_integer_field(h,"graphicsProfileLevelIndication",BC.GraphicsLevel);
		bifs_integer_field(h,"ODProfileLevelIndication",BC.ODLevel);

		bifs_collection(h,"esDescr");

			/* --------------------------------------- */
			/* Elementary Stream : BiFS Command Stream */
			/* --------------------------------------- */
			bifs_tag(h,"ES_Descriptor");
				bifs_integer_field(h,"ES_ID",++BC.es);
				bifs_tag(h,"decConfigDescr DecoderConfigDescriptor");
					bifs_field(h,"streamType","3");
					bifs_tag(h,"decSpecificInfo BIFSConfig");
						bifs_field(h,"isCommandStream","true");
						bifs_field(h,"pixelMetric","true");
						bifs_integer_field(h,"pixelWidth",BC.width);
						bifs_integer_field(h,"pixelHeight",BC.height);
					bifs_end_tag(h,1);
					/* bifs_field(h,"objectTypeIndication","2");*/
				bifs_end_tag(h,1);
			bifs_end_tag(h,1);

			/* --------------------------------------- */
			/* Elementary Stream : Object Descriptors  */
			/* --------------------------------------- */
			bifs_tag(h,"ES_Descriptor");
				bifs_integer_field(h,"ES_ID",++BC.es);
				bifs_tag(h,"decConfigDescr DecoderConfigDescriptor");
					bifs_field(h,"streamType","1");
				bifs_end_tag(h,1);
			bifs_end_tag(h,1);

			/* --------------------------------------- */
			/* Elementary Stream : Key Sensor Infos    */
			/* --------------------------------------- */
			BC.KeySensorID = ++BC.es;			
			BC.KeySensorOD = ++BC.od;			
			key_sensor_es_descriptor(h);


		bifs_end_collection(h,1);
	bifs_end_tag(h,1);

	return(0);
}

int	bifs_show_image3d( FILE * h, char * nptr, int od, struct coordinate3d * tl, struct coordinate3d * d )
{
	char	work[1024];

	bifs_tag(h,"Transform");
		mpeg_translation3d( work, tl->x, tl->y, d->x, d->y, tl->z );
		bifs_field(h,"translation",work);

	bifs_collection(h,"children");

	bifs_tag(h,"Shape");

		// ------------------------------
		// generate the widget appearance
		// ------------------------------
		bifs_tag(h,"appearance Appearance");
			bifs_tag(h,"material Material");
				bifs_field(h,"transparency","0");
			bifs_end_tag(h,1);
			bifs_tag(h,"texture ImageTexture");
				bifs_od_url( h, nptr, od );
			bifs_end_tag(h,1);

		bifs_close_tag(h,"appearance");

		// ----------------------------
		// generate the widget geometry
		// ----------------------------
		bifs_tag(h,"geometry Box");
			sprintf(work,"%u %u %u",d->x,d->y,d->z);
			bifs_field(h,"size",work);
		bifs_end_tag(h,1);

	bifs_close_tag(h,"Shape");

	bifs_close_collection(h,"children");
	bifs_close_tag(h,"Transform2D");

	return(0);
}

int	bifs_show_movie3d( FILE * h, char * nptr, int od, struct coordinate3d * tl, struct coordinate3d * d )
{
	char	work[1024];

	bifs_tag(h,"Transform");
		mpeg_translation3d( work, tl->x, tl->y, d->x, d->y, tl->z );
		bifs_field(h,"translation",work);

	bifs_collection(h,"children");

	bifs_tag(h,"Shape");

		// ------------------------------
		// generate the widget appearance
		// ------------------------------
		bifs_tag(h,"appearance Appearance");
			bifs_tag(h,"material Material");
				bifs_field(h,"transparency","0");
			bifs_end_tag(h,1);
			bifs_tag(h,"texture MovieTexture");
				bifs_od_url( h, nptr, od );
			bifs_end_tag(h,1);

		bifs_close_tag(h,"appearance");

		// ----------------------------
		// generate the widget geometry
		// ----------------------------
		bifs_tag(h,"geometry Box");
			sprintf(work,"%u %u %u",d->x,d->y,d->z);
			bifs_field(h,"size",work);
		bifs_end_tag(h,1);

	bifs_close_tag(h,"Shape");

	bifs_close_collection(h,"children");
	bifs_close_tag(h,"Transform");

	return(0);
}

int	bifs_show_audio3d( FILE * h, char * nptr, int od, struct coordinate3d * tl, struct coordinate3d * d )
{
	char	work[1024];

	bifs_tag(h,"Transform");
		mpeg_translation3d( work, tl->x, tl->y, d->x, d->y, tl->z );
		bifs_field(h,"translation",work);

	bifs_collection(h,"children");

	bifs_tag(h,"Sound");
		bifs_tag(h,"source AudioSource");
		bifs_od_url( h, nptr, od );
	bifs_end_tag(h,1);

	bifs_tag(h,"Shape");

		// ------------------------------
		// generate the widget appearance
		// ------------------------------
		bifs_tag(h,"appearance Appearance");
			bifs_tag(h,"material Material");
				bifs_field(h,"transparency","0");
			bifs_end_tag(h,1);
		bifs_close_tag(h,"appearance");

		// ----------------------------
		// generate the widget geometry
		// ----------------------------
		bifs_tag(h,"geometry Box");
			sprintf(work,"%u %u %u",d->x,d->y,d->z);
			bifs_field(h,"size",work);
		bifs_end_tag(h,1);

	bifs_close_tag(h,"Shape");

	bifs_close_collection(h,"children");
	bifs_close_tag(h,"Transform");

	return(0);
}

int	bifs_show_image2d( FILE * h, char * nptr, int od, int w, int hx )
{
	char	work[1024];

	bifs_tag(h,"Shape");

		// ------------------------------
		// generate the widget appearance
		// ------------------------------
		bifs_tag(h,"appearance Appearance");
			bifs_tag(h,"material Material2D");
				bifs_field(h,"filled","true");
			bifs_end_tag(h,1);
			bifs_tag(h,"texture ImageTexture");
				bifs_od_url( h, nptr, od );
			bifs_end_tag(h,1);

		bifs_close_tag(h,"appearance");

		// ----------------------------
		// generate the widget geometry
		// ----------------------------
		bifs_tag(h,"geometry Rectangle");
			sprintf(work,"%u %u" ,w,hx);
			bifs_field(h,"size",work);
		bifs_end_tag(h,1);

	bifs_close_tag(h,"Shape");

	return(0);
}

int	bifs_anchor( FILE * h, char * nptr )
{
	if (!( nptr ))
		return(0);
	else if (!( nptr = allocate_string( nptr ) ))
		return(0);
	else if (!( nptr = enforce_extension( nptr, ".mp4" ) ))
		return( 0 );
	else	{
		bifs_tag(h,"Anchor");
			bifs_od_url(h,nptr,0);
		liberate( nptr );
		return(1);
		}
}

int	bifs_inline_form3d( FILE * h, char * nptr,  struct coordinate3d * tl, struct coordinate3d * d )
{
	char	work[1024];
	if (!( nptr ))
		return(0);
	else if (!( nptr = allocate_string( nptr ) ))
		return(0);
	else if (!( nptr = enforce_extension( nptr, ".mp4" ) ))
		return( 0 );
	else	{
		bifs_tag(h,"Transform");
			mpeg_translation3d( work, tl->x, tl->y,d->x, d->y, tl->z );
			bifs_field(h,"translation",work);

		bifs_collection(h,"children");

		bifs_tag(h,"Inline");
			bifs_od_url(h,nptr,0);
			bifs_end_tag(h,1);

		bifs_close_collection(h,"children");
		bifs_close_tag(h,"Transform");
		liberate( nptr );
		return(0);
		}
}

int	bifs_inline_form2d( FILE * h, char * nptr, int w, int hx )
{
	if (!( nptr ))
		return(0);
	else if (!( nptr = allocate_string( nptr ) ))
		return(0);
	else if (!( nptr = enforce_extension( nptr, ".mp4" ) ))
		return( 0 );
	else	{
		bifs_tag(h,"Inline");
			bifs_od_url(h,nptr,0);
			bifs_end_tag(h,1);
		liberate( nptr );
		return(0);
		}
}


/*	--------------------------------------------	*/
/*	    b i f s _ o p e n _ p r o j e c t		*/
/*	--------------------------------------------	*/
/*	called from the 3d viewer production manager	*/
/*	--------------------------------------------	*/
int	bifs_open_project( FILE * h )
{
	int	status=0;
	return( sing_open_BIFS(h,(struct form_control *) 0) );
}

/*	--------------------------------------------	*/
/*	    b i f s _ s t a r t _ p r o j e c t		*/
/*	--------------------------------------------	*/
/*	called from the 3d viewer production manager	*/
/*	--------------------------------------------	*/
int	bifs_start_project( FILE * h )
{
	bifs_tag(h,"OrderedGroup");
	bifs_collection(h,"children");
	return( 0 );
}

/*	-------------------------------------------	*/
/*		s i n g _ c l o s e _ B i F S 		*/
/*	-------------------------------------------	*/
int	sing_close_BIFS( FILE * h, struct form_control * fptr )
{
	struct	form_item * iptr;
	if ( fptr )
	{
		for (	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )
		{
		
		}
	}
	return(0);
}

/*	--------------------------------------------	*/
/*	    b i f s _ c l o s e _ p r o j e c t		*
/*	--------------------------------------------	*/
/*	called from the 3d viewer production manager	*/
/*	--------------------------------------------	*/
int	bifs_close_project( FILE * h )
{
	bifs_close_collection(h,"children");
	bifs_close_tag(h,"OrderedGroup");
	sing_close_BIFS( h, (struct form_control *) 0);
	return(0);
}

void	bifs_string_data( FILE * h, char * nptr,char * value )
{
	mpeg_indent(h);
	fprintf(h,"field SFString %s %c%s%c\n",nptr,0x0022,value,0x0022);
	return;
}

void	bifs_integer_data( FILE * h, char * nptr,int value)
{
	mpeg_indent(h);
	fprintf(h,"field SFInt32 %s %u\n",nptr,value);
	return;
}

void	bifs_string_member( FILE * h, char * prefix, char * nptr, char * value)
{
	char	work[1024];
	sprintf(work,"%s_%s",prefix,nptr);
	bifs_string_data(h,work,value);
	return;
}

void	bifs_integer_member( FILE * h, char * prefix, char * nptr,int value )
{
	char	work[1024];
	sprintf(work,"%s_%s",prefix,nptr);
	bifs_integer_data(h,work,value);
	return;
}


/*	-------------------------------------------	*/
/*	 b i f s _ p r o t o _ i n t e r f a c e  	*/
/*	-------------------------------------------	*/
void	bifs_proto_interface( FILE * h, struct form_control * fptr )
{
	struct	form_item * iptr;
	/* forms members */
	if ( fptr->pages )
	{
		bifs_integer_data(h,"pageNumber",0);
		bifs_integer_data(h,"pageCount",fptr->pages);
	}
	bifs_integer_data(h,"focusItem",0);
	bifs_integer_data(h,"focusItems",fptr->items);
		/* widget members */
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		switch (iptr->Contents.style)
		{
		case	_EDIT_FRAME	:
			bifs_string_member(h,"b",iptr->Contents.name,"");
			break;
		case	_CHECK_FRAME	:
			bifs_integer_member(h,"v",iptr->Contents.name,0);
			break;
		case	_RADIO_FRAME	:
			bifs_integer_member(h,"v",iptr->Contents.name,0);
			break;
		case	_SWITCH_FRAME	:
			bifs_integer_member(h,"v",iptr->Contents.name,0);
			break;
		case	_SCROLL_FRAME	:
			bifs_integer_member(h,"v",iptr->Contents.name,0);
			bifs_integer_member(h,"m",iptr->Contents.name,0);
			bifs_integer_member(h,"l",iptr->Contents.name,0);
			break;
		case	_PROGRESS_FRAME	:
			bifs_integer_member(h,"v",iptr->Contents.name,0);
			bifs_integer_member(h,"m",iptr->Contents.name,0);
			break;
		}
	}
	return;
}

/*	-------------------------------------------	*/
/*	 b i f s _ p r o t o _ d e f i n i t i o n	*/
/*	-------------------------------------------	*/
void	bifs_ext_proto_definition( FILE * h, struct form_control * fptr )
{
	char* 	extname=(char *) 0;
	char	work[1024];
	struct	form_item * iptr;

	/* extern prototype definition */
	sprintf(work,"EXTERNPROTO %s",fptr->identifier);
	/* prototype field definitions */
	bifs_collection( h, work );
	bifs_proto_interface(h,fptr);
	bifs_close_collection(h,"");


	if (!( extname = allocate_string( fptr->prodname ) ))
		return;
	else if (!( enforce_extension( extname, _EXT_PROTO ) ))
		return;
	else
	{
		fprintf(h," %c%s#%s%c \n",0x0022,extname,fptr->identifier,0x0022);
		liberate( extname );
		return;
	}
}

/*	-------------------------------------------	*/
/*		b i f s _ p r o t o _ b o d y 		*/
/*	-------------------------------------------	*/
int	bifs_proto_body( FILE * h, struct form_control * fptr )
{
	int	i;
	struct	form_item * iptr;

	/* prototype nodes definitions */
	bifs_tag( h,"\0" );
	if ( fptr->first )
	{
		bifs_tag(h,"OrderedGroup");
		bifs_collection(h,"children");
		if ( fptr->pages )
		{
			for ( i=0; i <= fptr->pages; i++ )
			{
				for (	iptr=fptr->first;
					iptr != (struct form_item *) 0;
					iptr = iptr->next )
				{
					if ( iptr->Contents.page != i )
					{
						continue;
					}
					else if ( iptr->Contents.style == _TAB_FRAME )
					{
						bifs_tab_button( h, iptr );
						bifs_tab_frame ( h, iptr );
					}
					else	BIFS_widget( h, iptr );
				}
				if ( i )
				{
					bifs_close_collection(h,"children");
					bifs_close_tag(h,"Layer2D");
					bifs_close_collection(h,"children");
					bifs_close_tag(h,"Transform2D");
				}
			}
		}
		else
		{
			// ----------------------------------------
			// Generate order group of children widgets 
			// ----------------------------------------
			for (	iptr=fptr->first;
				iptr != (struct form_item *) 0;
				iptr = iptr->next )
			{
				// -----------------------------------------
				// Each widget is an ordered group of shapes
				// -----------------------------------------
				BIFS_widget( h, iptr );
			}
		}
		bifs_close_collection(h,"children");
		bifs_close_tag(h,"OrderedGroup");


		// --------------------------		
		// Generate Route Information 
		// --------------------------		
		for (	iptr=fptr->first;
			iptr != (struct form_item *) 0;
			iptr = iptr->next )
		{
			switch ( iptr->Contents.style )
			{
			case	_EDIT_FRAME	:
				bifs_edit_route( h, iptr->Contents.name );
				break;
			}
		}
	}
	bifs_close_tag(h,"\0");
	return(0);
}

/*	-------------------------------------------	*/
/*	 b i f s _ p r o t o _ d e f i n i t i o n	*/
/*	-------------------------------------------	*/
/* 	this function generates the prototype file	*/
/*	that will be referenced by the externproto	*/
/*	instructions for the description of the obj	*/
/*	-------------------------------------------	*/
void	bifs_proto_dependance( FILE * h, struct form_control * fptr )
{
	struct	form_item * 	iptr;
	char *			fnptr;
	struct	form_control * 	ffptr;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if (iptr->Contents.style != _DATA_FRAME	)
			continue;
		else if (( iptr->Contents.align & 0x00FF) != _VISUAL_FRAME)
			continue;
		else if (!( fnptr = abal_payload(iptr) )) 
			continue;
		else if (!(ffptr = locate_form_control( fnptr ) ))
			continue;
		else	bifs_ext_proto_definition( h, ffptr );
	}
	return;
}

void	bifs_proto_definition( FILE * handle, struct form_control * fptr )
{
	FILE *	h;
	char	work[1024];
	struct	form_item * iptr;
	char *	extname;

	if (!( extname = allocate_string( fptr->prodname ) ))
		return;
	else if (!( enforce_extension( extname, _EXT_PROTO ) ))
		return;
	else if (!( h = open_production_target(extname,0))) 
	{
		liberate(h);
		return;
	}
	else
	{
		bifs_proto_dependance(h,fptr);
		/* prototype definition */
		sprintf(work,"PROTO %s",fptr->identifier);
		/* prototype field definitions */
		bifs_collection( h, work );
		bifs_proto_interface(h,fptr);
		bifs_close_collection(h,"");
		bifs_proto_body(h, fptr );
		close_production_target(h,extname);	
		return;
	}
}

/*	-------------------------------------------	*/
/*	      e x p o r t _ B i F S _ f o r m 		*/
/*	-------------------------------------------	*/
int	export_BIFS_form( FILE * h, struct form_control * fptr )
{
	int	i;
	struct	form_item * iptr;

	prepare_Form( fptr );

	BC.width = 800; BC.height = 600;
	for (	iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next )
	{
		if ( iptr->Contents.style == _WINDOW_FRAME )
		{
			BC.width = iptr->Contents.w;
			BC.height = iptr->Contents.h;
			mpeg_production( BC.width, BC.height );
			break;
		}
	}

	bifs_proto_definition( h, fptr );

	sing_open_BIFS( h, fptr );

	bifs_ext_proto_definition( h, fptr );

	bifs_tag(h,"OrderedGroup");
	bifs_collection(h,"children");
	bifs_background2d(h,0,(char *) 0);
	bifs_worldinfo(h,"Bifs Text Generated by Sing",fptr->identifier);
	bifs_proto_instance(h,fptr,"This");
	bifs_close_collection(h,"children");
	bifs_close_tag(h,"OrderedGroup");
	key_sensor_object_descriptor( h );
	sing_close_BIFS( h, fptr );
	return(0);
}

/*	-------------------------------------------	*/
/*	     e x p o r t _ B i F S _ p a g e 		*/
/*	-------------------------------------------	*/
int	export_BIFS_page( FILE * h, struct form_control * fptr )
{
	return(0);
}


#endif	/* _singBIFS_c */


