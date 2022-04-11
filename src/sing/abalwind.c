#ifndef	_abalwind_c
#define	_abalwind_c

/*	------------------------------------------------------------------------------		*/
/*												*/
/*				-------------------						*/
/*				a b a l w i n d . c						*/
/*				-------------------						*/
/*												*/
/*	This included source provides for the requirements of window event generation		*/
/*	for the abal source production language model						*/
/*												*/
/*	The following cases are now correctly handled and catered for by this source 		*/
/*												*/
/*	------------------------------------------------------------------------------		*/

struct	abal_window_zone	{
	int	x;	/* left offset of style region	*/
	int	y;	/* top offset o style region	*/
	int	w;	/* width of style region 	*/
	int	h;	/* height of style region 	*/
	int	sw;
	int	sh;
	int	t;
	int	r;
	int	l;
	int	b;
	int	v;
	} awz;

public	int	abal_window_style_info( char * sptr, struct form_item * iptr, int fh, int n )
{
	struct	form_control * fptr;

	awz.x = ((iptr->Contents.x+iptr->Contents.w)-((fh*n)+((n*2)+1)));
	awz.y = (iptr->Contents.y+4);
	awz.h = fh;
	awz.w = fh;
	awz.v = 0;

	if (!( fptr = iptr->parent ))
		return(0);
	else if (!( method_is_valid( fptr->stylesheet) ))
		return(0);
	else if (!( awz.v = resolve_style_dimensions( sptr, &awz.sw, &awz.sh )))
		return(0);
	else if (!(awz.v = resolve_style_position(sptr, &awz.t,&awz.r,&awz.b,&awz.l )))
		return(0);
	else	{
		if ( awz.v & 8 )
			awz.x = (iptr->Contents.x+awz.l);						

		else if ( awz.v & 2 )
			awz.x = (iptr->Contents.x+(iptr->Contents.w - awz.r));

		if ( awz.v & 1 )
			awz.y = (iptr->Contents.y+awz.t);

		else if ( awz.v & 4 )
			awz.y = (iptr->Contents.y+(iptr->Contents.h - awz.b));

		awz.w = awz.sw; awz.h = awz.sh;
		return(1);
		}
}

public	int	get_window_style_x()	{	return( awz.x );	}
public	int	get_window_style_y()	{	return( awz.y );	}
public	int	get_window_style_xx()	{	return( awz.x+awz.w );	}
public	int	get_window_style_yy()	{	return( awz.y+awz.h );	}

private	void	abal_window_avoid_event(FILE * handle, struct form_item * iptr )
{
	indent(handle,2);
	abal_comment(handle,iptr->Contents.name,1);
	indent(handle,2);
	fprintf(handle,"Exit(-1)");
	linefeed(handle);
	return;
}


private	void	set_window_internals( FILE * handle, struct form_item * iptr, int fh, int n)
{
	if ( FixedWindows ) {
		if (is_w_modif(iptr)) {
			if ( awz.v & 8 ) {
				/* position from the left edge */
				/* --------------------------- */
				fprintf(handle,"\tx_internal = ((%u*_wref)/%u)+%d",
					iptr->Contents.x+WindowCol,
					w_base_resize(iptr),
					awz.l);
				}
			else if ( awz.v & 2 ) {
				/* position from the right edge */
				/* --------------------------- */
				fprintf(handle,"\tx_internal = ((%u*_wref)/%u)-%d",
					iptr->Contents.x+iptr->Contents.w+WindowCol,
					w_base_resize(iptr),
					awz.r);
				}
			else	{
				/* No positioning style */
				/* -------------------- */
				fprintf(handle,"\tx_internal = ((%u*_wref)/%u)-%d",
					iptr->Contents.x+iptr->Contents.w+WindowCol,
					w_base_resize(iptr),
					(fh*n)+((n*2)+1));
				}
			}
		else	{
			if ( awz.v & 8 ) {
				fprintf(handle,"\tx_internal = ((%u*_wref)/%u)+%u",
					iptr->Contents.x+WindowCol,
					w_base_resize(iptr),
					awz.l);
				}
			else if ( awz.v & 2 ) {
				fprintf(handle,"\tx_internal = (((%u*_wref)/%u)+%u)-%u",
					iptr->Contents.x+WindowCol,
					w_base_resize(iptr),
					iptr->Contents.w,
					awz.r);
				}
			else	{
				fprintf(handle,"\tx_internal = (((%u*_wref)/%u)+%u)-%u",
					iptr->Contents.x+WindowCol,
					w_base_resize(iptr),
					iptr->Contents.w,
					(fh*n)+((n*2)+1));
				}
			}
		linefeed(handle);
		fprintf(handle,"\ty_internal = ((%u*_href)/%d)+4",
			iptr->Contents.y+WindowRow,
			h_base_resize(iptr));
		linefeed(handle);
		}
	else	{
		if (is_w_modif(iptr)) {
			if ( awz.v & 8 ) {
				fprintf(handle,"\tx_internal = %s+%d",
					widget_x_position(iptr,1),
					awz.l);
				}
			else if ( awz.v & 2 ) {
				fprintf(handle,"\tx_internal = %s+((%u*_wref)/%d)-%d",
					widget_x_position(iptr,1),
					iptr->Contents.w,
					w_base_resize(iptr),
					awz.r);
				}
			else	{
				fprintf(handle,"\tx_internal = %s+((%u*_wref)/%d)-%d",
					widget_x_position(iptr,1),
					iptr->Contents.w,
					w_base_resize(iptr),
					(fh*n)+((n*2)+1));
				}
			}
		else	{
			if ( awz.v & 8 ) {
				fprintf(handle,"\tx_internal = %s+%u",
					widget_x_position(iptr,1),
					awz.l);
				}
			else if ( awz.v & 2 ) {
				fprintf(handle,"\tx_internal = %s+%u",
					widget_x_position(iptr,1),
					iptr->Contents.w-awz.r);
				}
			else	{
				fprintf(handle,"\tx_internal = %s+%u",
					widget_x_position(iptr,1),
					iptr->Contents.w-((fh*n)+((n*2)+1)));
				}
			}
		linefeed(handle);
		}
	return;
}

private	int	abal_window_flag_position(FILE * handle, struct form_item * iptr, char * optr, int multilingual, int fw, int fh )
{

	abal_window_style_info( "windowlang", iptr, fh, 3 ); 

	if ( FixedWindows ) {
		/* Windows are fixed and consequently use constant position values */
		if (is_xy_modif(iptr)) {
			/* windows may redimension */
			/* ----------------------- */
			set_window_internals(handle,iptr,fh,3);
			fprintf(handle,"\tif ((%s >= x_internal ) '",__abal_mouse_column);	
			linefeed(handle);
			fprintf(handle,"\tand (%s >= y_internal ) '",__abal_mouse_row);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (x_internal+%u) ) '",__abal_mouse_column,awz.w);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (y_internal+%u) ))",__abal_mouse_row,awz.h);
			linefeed(handle);
			return(1);
			}
		else	{
			fprintf(handle,"\tif ((%s >= %u ) '",__abal_mouse_column,awz.x+WindowCol);
			linefeed(handle);
			fprintf(handle,"\tand (%s >= %u ) '",__abal_mouse_row,awz.y+WindowRow);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= %u ) '",__abal_mouse_column,awz.x+awz.w+WindowCol);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= %u ))",__abal_mouse_row,awz.y+awz.h+WindowRow);
			linefeed(handle);
			return(1);
			}
		}
	else	{
		/* Windows are not fixed and consequently use variable position values */
		if (is_xy_modif(iptr)) {
			set_window_internals(handle,iptr,fh,3);
			fprintf(handle,"\tif ((%s >= x_internal ) '",__abal_mouse_column);
			linefeed(handle);
			fprintf(handle,"\tand (%s >= (%s+%u) ) '",__abal_mouse_row,widget_y_position(iptr,1),awz.y);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (x_internal + %u) ) '",__abal_mouse_column,awz.w);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (%s+%u) ))",__abal_mouse_row,widget_y_position(iptr,1),awz.y+awz.h);
			linefeed(handle);
			return(1);
			}
		else	{
			awz.x -= iptr->Contents.x;
			awz.y -= iptr->Contents.y;
			fprintf(handle,"\tif ((%s >= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),awz.x);
			linefeed(handle);
			fprintf(handle,"\tand (%s >= (%s+%u) ) '",__abal_mouse_row,widget_y_position(iptr,1),awz.y);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),awz.x+awz.w);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (%s+%u) ))",__abal_mouse_row,widget_y_position(iptr,1),awz.y+awz.h);
			linefeed(handle);
			return(1);
			}
		}
	return(0);
}

private	void	abal_window_flag_event(FILE * handle, struct form_item * iptr, char * optr, int multilingual, int fw, int fh )
{
	if ( abal_window_flag_position(handle,iptr,optr,multilingual,fw,fh ) ) {
		indent(handle,2);
		abal_comment(handle,iptr->Contents.name,1);
		abal_lang_event( handle, iptr, 2 );
		abal_endif(handle,1);
		}
	return;
}

private	void	abal_window_flag_avoid(FILE * handle, struct form_item * iptr, char * optr, int multilingual, int fw, int fh )
{
	if ( abal_window_flag_position(handle,iptr,optr,multilingual,fw,fh ) ) {
		abal_window_avoid_event(handle,iptr);
		abal_endif(handle,1);
		}
	return;
}

private	int	abal_window_help_position(FILE * handle, struct form_item * iptr, char * optr, int multilingual, int fw, int fh )
{
	abal_window_style_info( "windowhelp", iptr, fh, 2 ); 

	if ( FixedWindows ) {
		if (is_xy_modif(iptr)) {
			set_window_internals(handle,iptr,fh,2);
			fprintf(handle,"\tif ((%s >= x_internal ) '",__abal_mouse_column);	
			linefeed(handle);
			fprintf(handle,"\tand (%s >= y_internal ) '",__abal_mouse_row);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (x_internal+%u) ) '",__abal_mouse_column,awz.w);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (y_internal+%u) ))",__abal_mouse_row,awz.h);
			linefeed(handle);
			return(1);
			}
		else	{
			fprintf(handle,"\tif ((%s >= %u ) '",__abal_mouse_column,awz.x+WindowCol);
			linefeed(handle);
			fprintf(handle,"\tand (%s >= %u ) '",__abal_mouse_row,awz.y+WindowRow);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= %u ) '",__abal_mouse_column,awz.x+awz.w+WindowCol);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= %u ))",__abal_mouse_row,awz.y+awz.h+WindowRow);
			linefeed(handle);
			return(1);
			}
		}
	else	{
		if (is_xy_modif(iptr)) {
			set_window_internals(handle,iptr,fh,2);
			fprintf(handle,"\tif ((%s >= x_internal ) '",__abal_mouse_column);
			linefeed(handle);
			fprintf(handle,"\tand (%s >= (%s+%u) ) '",__abal_mouse_row,widget_y_position(iptr,1),awz.y);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (x_internal + %u) ) '",__abal_mouse_column,awz.w);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (%s+%u) ))",__abal_mouse_row,widget_y_position(iptr,1),awz.y+awz.h);
			linefeed(handle);
			return(1);
			}
		else	{
			awz.x -= iptr->Contents.x;
			awz.y -= iptr->Contents.y;
			fprintf(handle,"\tif ((%s >= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),awz.x);
			linefeed(handle);
			fprintf(handle,"\tand (%s >= (%s+%u) ) '",__abal_mouse_row,widget_y_position(iptr,1),awz.y);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),awz.x+awz.w);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (%s+%u) ))",__abal_mouse_row,widget_y_position(iptr,1),awz.y+awz.h);
			linefeed(handle);
			return(1);
			}
		}
	return(0);
}

private	void	abal_window_help_event(FILE * handle, struct form_item * iptr, char * optr, int multilingual, int fw, int fh )
{
	if ( abal_window_help_position(handle,iptr,optr, multilingual,fw,fh ) ) {
		indent(handle,2);
		abal_comment(handle,iptr->Contents.name,1);
		abal_help_event( handle, iptr, 2 );
		abal_endif(handle,1);
		}
	return;
}

private	void	abal_window_help_avoid(FILE * handle, struct form_item * iptr, char * optr, int multilingual, int fw, int fh )
{
	if ( abal_window_help_position(handle,iptr,optr, multilingual,fw,fh ) ) {
		abal_window_avoid_event(handle,iptr);
		abal_endif(handle,1);
		}
	return;
}

private	int	abal_window_size_position(FILE * handle, struct form_item * iptr, char * optr, int multilingual, int fw, int fh )
{
	abal_window_style_info( "windowmaxi", iptr, fh, 3+multilingual ); 

	if ( FixedWindows ) {
		if (is_xy_modif(iptr)) {
			set_window_internals(handle,iptr,fh,3+multilingual);
			fprintf(handle,"\tif ((%s >= x_internal ) '",__abal_mouse_column);	
			linefeed(handle);
			fprintf(handle,"\tand (%s >= y_internal ) '",__abal_mouse_row);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (x_internal+%u) ) '",__abal_mouse_column,awz.w);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (y_internal+%u) ))",__abal_mouse_row,awz.h);
			linefeed(handle);
			return(1);
			}
		else	{
			fprintf(handle,"\tif ((%s >= %u ) '",__abal_mouse_column,awz.x+WindowCol);
			linefeed(handle);
			fprintf(handle,"\tand (%s >= %u ) '",__abal_mouse_row,awz.y+WindowRow);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= %u ) '",__abal_mouse_column,awz.x+awz.w+WindowCol);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= %u ))",__abal_mouse_row,awz.y+awz.h+WindowRow);
			linefeed(handle);
			return(1);
			}
		}
	else	{
		if (is_xy_modif(iptr)) {
			set_window_internals(handle,iptr,fh,3+multilingual);
			fprintf(handle,"\tif ((%s >= x_internal ) '",__abal_mouse_column);
			linefeed(handle);
			fprintf(handle,"\tand (%s >= (%s+%u) ) '",__abal_mouse_row,widget_y_position(iptr,1),awz.y);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (x_internal + %u) ) '",__abal_mouse_column,awz.w);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (%s+%u) ))",__abal_mouse_row,widget_y_position(iptr,1),awz.y+awz.h);
			linefeed(handle);
			return(1);
			}
		else	{
			awz.x -= iptr->Contents.x;
			awz.y -= iptr->Contents.y;
			fprintf(handle,"\tif ((%s >= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),awz.x);
			linefeed(handle);
			fprintf(handle,"\tand (%s >= (%s+%u) ) '",__abal_mouse_row,widget_y_position(iptr,1),awz.y);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),awz.x+awz.w);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (%s+%u) ))",__abal_mouse_row,widget_y_position(iptr,1),awz.y+awz.h);
			linefeed(handle);
			return(1);
			}
		}
	return(0);
}

private	void	abal_window_size_event(FILE * handle, struct form_item * iptr, char * optr, int multilingual, int fw, int fh )
{
	char *	tptr=(char *) 0;

	if ( abal_window_size_position(handle,iptr,optr, multilingual,fw,fh ) ) {
		indent(handle,2);
		if ((tptr=allocate(32+method_is_valid(iptr->Contents.name))) != (char *) 0) {
			sprintf(tptr,"Redimensionner %s",iptr->Contents.name);
			abal_comment(handle,tptr,1);
			liberate(tptr);
			}
		indent(handle,2);
		fprintf(handle,"if ((_wref = %u) AND (_href=%u))",w_base_resize(iptr),h_base_resize(iptr));
		linefeed(handle);
			indent(handle,3);
			fprintf(handle,"%sResize(%sConf(69),Conf(68))",Abal_Config.cname,optr);
			linefeed(handle);
		abal_else(handle,2);						
			indent(handle,3);
			fprintf(handle,"%sResize(%s%u,%u)",Abal_Config.cname,optr,w_base_resize(iptr),h_base_resize(iptr));
			linefeed(handle);
		abal_endif(handle,2);
		abal_endif(handle,1);
		}
	return;
}

private	void	abal_window_size_avoid(FILE * handle, struct form_item * iptr, char * optr, int multilingual, int fw, int fh )
{
	if ( abal_window_size_position(handle,iptr,optr, multilingual,fw,fh ) ) {
		abal_window_avoid_event( handle, iptr );
		abal_endif(handle,1);
		}
	return;
}

private	int	abal_window_exit_position(FILE * handle, struct form_item * iptr, char * optr, int multilingual, int fw, int fh )
{
	int	b=0;
	int	wy = (iptr->Contents.y+4);

	abal_window_style_info( "windowexit", iptr, fh, 1 ); 

	if ( FixedWindows ) {
		if (is_xy_modif(iptr)) {
			set_window_internals(handle,iptr,fh,1);
			fprintf(handle,"\tif ((%s >= x_internal ) '",__abal_mouse_column);	
			linefeed(handle);
			fprintf(handle,"\tand (%s >= y_internal ) '",__abal_mouse_row);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (x_internal+%u) ) '",__abal_mouse_column,awz.w);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (y_internal+%u) ))",__abal_mouse_row,awz.h);
			linefeed(handle);
			return(1);
			}
		else if ( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS ) {
			/* Widget has sizes */
			/* ---------------- */
			/* IJM : 21/04/2007 */
			/* ---------------- */
			fprintf(handle,"\tif ((%s >= (%s) ) '",__abal_mouse_column,widget_x_position(iptr,0));
			linefeed(handle);
			fprintf(handle,"\tand (%s >= (%s) ) '",__abal_mouse_row,widget_y_position(iptr,0));
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (%s+w_%s) ) '",__abal_mouse_column,widget_x_position(iptr,0),iptr->Contents.name);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (%s+h_%s) ))",__abal_mouse_row,widget_y_position(iptr,0),iptr->Contents.name);
			linefeed(handle);
			return(1);
			}
		else	{
			fprintf(handle,"\tif ((%s >= %u ) '",__abal_mouse_column,awz.x+WindowCol);	
			linefeed(handle);
			fprintf(handle,"\tand (%s >= %u ) '",__abal_mouse_row,awz.y+WindowRow);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= %u ) '",__abal_mouse_column,awz.x+awz.w+WindowCol);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= %u ))",__abal_mouse_row,awz.y+awz.h+WindowRow);
			linefeed(handle);
			return(1);
			}
		}
	else	{
		if (is_xy_modif(iptr)) {
			set_window_internals(handle,iptr,fh,1);
			fprintf(handle,"\tif ((%s >= x_internal ) '",__abal_mouse_column);	
			linefeed(handle);
			fprintf(handle,"\tand (%s >= (%s+%u) ) '",__abal_mouse_row,widget_y_position(iptr,1),awz.y);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (x_internal + %u) ) '",__abal_mouse_column,awz.w);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (%s+%u) ))",__abal_mouse_row,widget_y_position(iptr,1),awz.y+awz.h);
			linefeed(handle);
			return(1);
			} 
		else if ( iptr->Contents.events->xo_create & _EVENT_IS_FOCUS ) {
			/* Widget has sizes */
			/* ---------------- */
			/* IJM : 21/04/2007 */
			/* ---------------- */	
			awz.x -= iptr->Contents.x;
			awz.y -= iptr->Contents.y;
			fprintf(handle,"\tif ((%s >= (%s) ) '",__abal_mouse_column,widget_x_position(iptr,0));
			linefeed(handle);
			fprintf(handle,"\tand (%s >= (%s) ) '",__abal_mouse_row,widget_y_position(iptr,0));	
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (%s+w_%s) ) '",__abal_mouse_column,widget_x_position(iptr,0),iptr->Contents.name);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (%s+h_%s) ))",__abal_mouse_row,widget_y_position(iptr,0),iptr->Contents.name);
			linefeed(handle);
			return(1);
			}
		else 	{
			awz.x -= iptr->Contents.x;
			awz.y -= iptr->Contents.y;
			fprintf(handle,"\tif ((%s >= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),awz.x);
			linefeed(handle);
			fprintf(handle,"\tand (%s >= (%s+%u) ) '",__abal_mouse_row,widget_y_position(iptr,1),awz.y);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),awz.x+awz.w);
			linefeed(handle);
			fprintf(handle,"\tand (%s <= (%s+%u) ))",__abal_mouse_row,widget_y_position(iptr,1),awz.y+awz.h);
			linefeed(handle);
			return(1);
			}
		}
	return(0);
}

private	void	abal_window_exit_event(FILE * handle, struct form_item * iptr, char * optr, int multilingual, int fw, int fh )
{
	int	b;
	if ( abal_window_exit_position(handle,iptr,optr,multilingual,fw,fh ) ) {
		indent(handle,2);
		abal_comment(handle,iptr->Contents.name,1);
		b = abal_widget_mouse_filter(handle,iptr,1);
		abal_mouse_event( handle, iptr, 2 );
		if ( b ) { 
			abal_endsel(handle,1); 
			}
		abal_endif(handle,1);
		}
	return;
}

private	void	abal_window_exit_avoid(FILE * handle, struct form_item * iptr, char * optr, int multilingual, int fw, int fh )
{
	int	b;
	if ( abal_window_exit_position(handle,iptr,optr,multilingual,fw,fh ) ) {
		abal_window_avoid_event(handle, iptr );
		abal_endif(handle,1);
		}
	return;
}

private	void	abal_window_move_event(FILE * handle, struct form_item * iptr, char * optr, int multilingual, int fw, int fh )
{
	int	hwx = (iptr->Contents.w-((fh*4)+7));
	indent(handle,2);
	fprintf(handle,"if ((%s >= (%s+4) ) '",__abal_mouse_column,widget_x_position(iptr,1));
	linefeed(handle);
	indent(handle,2);
	fprintf(handle,"and (%s >= (%s+4) ) '",__abal_mouse_row,widget_y_position(iptr,1));
	linefeed(handle);
	indent(handle,2);
	if (is_w_modif(iptr))
		fprintf(handle,"and (%s <= (%s+((%u*_wref)/%d)-%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),iptr->Contents.w,w_base_resize(iptr),fh*4+7);
	else	fprintf(handle,"and (%s <= (%s+%u) ) '",__abal_mouse_column,widget_x_position(iptr,1),hwx);
	linefeed(handle);
	indent(handle,2);
	fprintf(handle,"and (%s <= (%s+4+%u) ))",__abal_mouse_row,widget_y_position(iptr,1),fh);
	linefeed(handle);
	indent(handle,3);
	abal_comment(handle,iptr->Contents.name,1);
	abal_move_event( handle, iptr, 3 );
	abal_endif(handle,2);
	return;
}

private	void	generate_abal_window_event(FILE * handle, struct form_item * iptr, char * optr, int multilingual )
{
	int	f;
	int	fw;
	int	fh;
	struct	form_control * fptr;

	/* no widget or no parent form : no window event */
	/* --------------------------------------------- */
	if ((!( iptr )) || (!( fptr = iptr->parent )))
		return;

	/* no focus and no event : no window event */
	/* --------------------------------------- */
	if ((!( iptr->Contents.events->xo_event & _EVENT_IS_FOCUS ))
	&&  (!( iptr->Contents.events->xo_get_focus & _EVENT_IS_FOCUS )))
		return;

	/* no font information : no window event */
	/* ------------------------------------- */
	if (!( f = iptr->Contents.font ))
		return;
	else if (!( fh = guifontsize(f) ))
		return;
	else if (!( fw = (fh & 0x00FF) ))
		return;
	else	fh = ((fh >>= 8) & 0x00FF);

	/* Open Mouse Event Switch */
	/* ----------------------- */
	if (( iptr->Contents.align & (_A_BOLD | _A_LINE) )
	||  ( multilingual )
	||  ( fptr->resizeauto )
	||  ( iptr->Contents.special )) {
		indent(handle,1);
		fprintf(handle,"Select ( %s )",__abal_mouse_type);
		linefeed(handle);
		}

	/* With at least an UP event */
	/* ------------------------- */
	if (( iptr->Contents.align & (_A_BOLD | _A_LINE) )
	||  ( multilingual )
	||  ( fptr->resizeauto )) {
		indent(handle,1);
		fprintf(handle,"Case _MIMO_UP");
		linefeed(handle);
		}

	/* ------------------------------------------ */
	/* Generate the appropriate Window Event Type */
	/* ------------------------------------------ */
	if ( iptr->Contents.align & _A_BOLD ) {	
		abal_window_exit_event(handle, iptr, optr, multilingual, fw, fh );
		}
	if ( iptr->Contents.align & _A_LINE ) {
		abal_window_help_event(handle, iptr, optr, multilingual, fw, fh );
		}
	if ( multilingual ) {
		abal_window_flag_event(handle, iptr, optr, multilingual, fw, fh );
		}
	if ( fptr->resizeauto ) {
		abal_window_size_event(handle, iptr, optr, multilingual, fw, fh );
		}
	if (( iptr->Contents.special ) && (!( FixedWindows ))) {
		indent(handle,1); 
		fprintf(handle,"Case _MIMO_DOWN"); 
		linefeed(handle);
		/* Avoid other events */
		if ( iptr->Contents.align & _A_BOLD ) {	
			abal_window_exit_avoid(handle, iptr, optr, multilingual, fw, fh );
			}
		if ( iptr->Contents.align & _A_LINE ) {
			abal_window_help_avoid(handle, iptr, optr, multilingual, fw, fh );
			}
		if ( multilingual ) {
			abal_window_flag_avoid(handle, iptr, optr, multilingual, fw, fh );
			}
		if ( fptr->resizeauto ) {
			abal_window_size_avoid(handle, iptr, optr, multilingual, fw, fh );
			}
		/* Handle Move Event */
		abal_window_move_event( handle, iptr, optr, multilingual, fw, fh );
		}
	
	/* Close the eventual Event Switch */
	/* ------------------------------- */
	if (( iptr->Contents.align & (_A_BOLD | _A_LINE) )
	|| ( multilingual )
	||  ( fptr->resizeauto )
	|| ( iptr->Contents.special )) {
		fprintf(handle,"\tEndSel");
		linefeed(handle);
		}
	return;
}


#endif	/* _abalwind_c */
	/* ----------- */

