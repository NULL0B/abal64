#ifndef	_styled_c
#define	_styled_c

/*	----------------------------------------------------------	*/
/*	Styled Frames	:	outset,inset,groove,ridge and edit	*/
/*	----------------------------------------------------------	*/

#include "valign.h"
#include "sframe.c"
#include "stable.c"
#include "sselect.c"
#include "sscroll.c"
#include "sprogres.c"

public	int	styled_visual_window(EXAWORD x,EXAWORD y,EXAWORD w,EXAWORD h,EXAWORD fid,BPTR title,EXAWORD length,EXAWORD options)
{
	if ( use_default_style(visual_window_frame) ) {
		style_visual_freeze();
		if ( options & _A_SHADOW ) 
			visual_element( x,y,w,h, "windowshadow", " ",0);
		visual_element( x,y,w,h, "windowtray", " ",0);
		visual_element( x,y,w,h, "windowframe", " ",0);
		visual_element( x,y,w,h, "windowinner", title,length );
		visual_element( x,y,w,h, "windowtitle", title,length );
		if ( options & _WINDOW_EXIT_BUTTON )
			visual_element( x,y,w,h, "windowexit", "X",1);
		if ( options & _WINDOW_HELP_BUTTON )
			visual_element( x,y,w,h, "windowhelp", "?",1);
		if ( options & _WINDOW_LANG_BUTTON )
			visual_element( x,y,w,h, "windowlang", "*",1);
		if ( options & _WINDOW_MINIMIZE )
			visual_element( x,y,w,h, "windowmini", "-",1);
		if ( options & _WINDOW_MAXIMIZE )
			visual_element( x,y,w,h, "windowmaxi", "+",1);
		style_visual_thaw(x,y,w,h);
		}
	else	{
		visual_window(x,y,w,h,fid,title,length,options);
		}
	return(0);
}

public	int	styled_visual_button(EXAWORD x,EXAWORD y,EXAWORD w,EXAWORD h,EXAWORD fid,EXAWORD fg, EXAWORD bg,BPTR message,EXAWORD length,EXAWORD state)
{
	if ( use_default_style( visual_button_frame ) ) {
		style_visual_freeze();
		if ( state & _VISUAL_IMAGE ) {
			visual_element( x,y,w,h, "icontray", message, length );
			if ( state & _VISUAL_PRESS )
				visual_element( x,y,w,h, "iconpress", message, length );
			else	visual_element( x,y,w,h, "iconframe", message, length );
			if ( state & _VISUAL_FOCUS )
				visual_element( x,y,w,h, "iconfocus", message, length );
			}
		else	{
			visual_element( x,y,w,h, "buttontray", message, length );
			if ( state & _VISUAL_PRESS )
				visual_element( x,y,w,h, "buttonpress", message, length );
			else	visual_element( x,y,w,h, "buttonframe", message, length );
			if ( state & _VISUAL_FOCUS )
				visual_element( x,y,w,h, "buttonfocus", message, length );
			}
		style_visual_thaw(x,y,w,h);
		}
	else	{
		visual_button(x,y,w,h,fid,fg,bg,message,length,state);
		}
	return(0);
}

public	int	styled_visual_check(EXAWORD x,EXAWORD y,EXAWORD w,EXAWORD h,EXAWORD fid,EXAWORD fg, EXAWORD bg,BPTR message,EXAWORD length,EXAWORD state)
{
	if ( use_default_style( visual_check_frame ) ) {
		style_visual_freeze();
		visual_element( x,y,w,h, "checktray", " ", 0);
		visual_element( x,y,w,h, "checkframe", " ", 0);
		if ( state & _VISUAL_CHECK )
			visual_element( x,y,w,h, "checktrue", " ", 0);
		if ( state & _VISUAL_FOCUS )
			visual_element( x,y,w,h, "checkfocus", message, length );
		else	visual_element( x,y,w,h, "checklabel", message, length );
		style_visual_thaw(x,y,w,h);
		}
	else	{
		visual_check(x,y,w,h,fid,fg,bg,message,length,state);
		}
	return(0);
}

public	int	styled_visual_switch(EXAWORD x,EXAWORD y,EXAWORD w,EXAWORD h,EXAWORD fid,EXAWORD fg, EXAWORD bg, BPTR message,EXAWORD length,EXAWORD state)
{
	char *	vptr;
	int	vlen;
	int	i;
	vptr = message; vlen = length;
	for (i=0; i < length; i++) {
		if (*(message+i) == '|') {
			vptr = (message+i+1);
			vlen = (length-(i+1));
			length = i;
			break;
			}
		}
	if ( use_default_style( visual_switch_frame ) ) {
		style_visual_freeze();
		visual_element( x,y,w,h, "switchtray", message,length);
		visual_element( x,y,w,h, "switchframe", message,length);
		if ( state & _VISUAL_CHECK )
			visual_element( x,y,w,h, "switchtrue", vptr,vlen);
		else 	visual_element( x,y,w,h, "switchlabel", message,length);
		if ( state & _VISUAL_FOCUS )
			visual_element( x,y,w,h, "switchfocus", message,length);
		style_visual_thaw(x,y,w,h);
		}
	else	{
		visual_switch(x,y,w,h,fid,fg,bg,message,length,state);
		}
	return(0);
}

public	int	styled_visual_radio(EXAWORD x,EXAWORD y,EXAWORD w,EXAWORD h,EXAWORD fid,EXAWORD fg, EXAWORD bg, BPTR message,EXAWORD length,EXAWORD storage, EXAWORD value)
{
	if ( use_default_style( visual_radio_frame ) ) {
		style_visual_freeze();
		visual_element( x,y,w,h, "radiotray", " ", 0);
		visual_element( x,y,w,h, "radioframe", " ", 0);
		if ( storage == value )
			visual_element( x,y,w,h, "radiotrue", " ", 0);
		visual_element( x,y,w,h, "radiolabel", message, length );
		style_visual_thaw(x,y,w,h);
		}
	else	{
		visual_radio(x,y,w,h,fid,fg,bg,message,length,storage,value);
		}
	return(0);
}


public	int	styled_visual_progress(EXAWORD x,EXAWORD y,EXAWORD w,EXAWORD h,EXAWORD f, EXAWORD fg, EXAWORD bg, EXAWORD l,EXAWORD v, EXAWORD o)
{
	if ( use_default_style( visual_progress_frame ) ) {
		StyledProgress( x,y,w,h,f,fg,bg,l,v,o);
		}
	else	{
		visual_progress( x,y,w,h,f,fg,bg,l,v,o);
		}
	return(0);
}

public	int	styled_visual_tabpage(EXAWORD x,EXAWORD y,EXAWORD w,EXAWORD h,EXAWORD fid,BPTR title,EXAWORD length,EXAWORD offset,EXAWORD control)
{
	if ( use_default_style(visual_page_frame) ) {
		if ( control & _VISUAL_FOCUS ) {
			style_visual_freeze();
			visual_element( x,y,w,h, "pageframe", " ",0);
			visual_element( x,y,w,h, "pageinner", " ",0);
			visual_element( x+offset,y,w-offset,h, "pagefocus", title,length );
			style_visual_thaw(x,y,w,h);
			}
		else	{
			style_visual_freeze();
			visual_element( x+offset,y,w-offset,h, "pagebutton", title,length );
			style_visual_thaw(x+offset,y,w-offset,h);
			}
		}
	else	{
		visual_tabpage(x,y,w,h,fid,title,length,offset,control);
		}
	return(0);
}

public	int	styled_visual_select(
		EXAWORD x,EXAWORD y,EXAWORD w,EXAWORD h,
		EXAWORD fid, EXAWORD fg, EXAWORD bg, 
		BPTR message,EXAWORD length,unsigned int * iptr,EXAWORD state)
{
	if ( use_default_style(visual_select_frame) )
		return( StyledSelect(x,y,w,h,fid,fg,bg,message,length,iptr,state) );
	else 	return( VisualSelect(x,y,w,h,fid,fg,bg,message,length,iptr,state) );
}

	
public	int	styled_visual_scroll(EXAWORD x,EXAWORD y,EXAWORD w,EXAWORD h,EXAWORD fid,EXAWORD fg, EXAWORD bg, EXAWORD item, EXAWORD limit, EXAWORD total, EXAWORD style)
{

	if (( use_default_style(visual_vscroll_frame) ) 
	||  ( use_default_style(visual_hscroll_frame) )) {
		StyleScrollBar(x,y,w,h,fid,fg,bg,item,limit,total,style);
		}
	else	{
		visual_scrollbar(x,y,w,h,fid,fg,bg,item,limit,total,style);
		}
	return(0);
}

public	int	styled_visual_table( EXAWORD x, EXAWORD y, EXAWORD w, EXAWORD h, EXAWORD f, EXAWORD fg, EXAWORD bg,
		BPTR tptr, BPTR vptr, EXAWORD options,BPTR fptr )
{
	if ( use_default_style(visual_table_frame) ) {
		if (!( options & 0x4000 ))
			styled_table(x,y,w,h,f,fg,bg,tptr,vptr,options,(BPTR) 0);
		else	styled_table(x,y,w,h,f,fg,bg,tptr,vptr,options,fptr);
		}
	else if (!( options & 0x4000 ))
		visual_table( x,y,w,h,f,fg,bg,tptr,vptr,options,(BPTR) 0);
	else	visual_table( x,y,w,h,f,fg,bg,tptr,vptr,options,fptr);
	return(0);
}


	/* --------- */
#endif	/* _styled_c */
	/* --------- */


