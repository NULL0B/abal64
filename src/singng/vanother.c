
#ifndef _vanother_c
#define _vanother_c
#include <stdio.h>
#include "visual.h"

private struct accept_introduction_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	signature[1];
	} * _Context;

private	int	accept_introduction_create()
{

	if (!(_Context = allocate( sizeof( struct accept_introduction_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=0;
	_Context->window_col=0;
	_Context->window_row=0;
	return(0);
}

private	int	accept_introduction_remove()
{

	int	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_introduction_show()
{
	freeze();
	window(255,100,290,400,2,"Sing : Version 1.0",18,3);
	text(283,140,238,16,2,26,0,"Sing",4,259);
	vimage(259,122,282,374,VisualSkin,4);
	frame(286,161,224,284,3);
	vimage(291,165,220,276,"sing.gif",0);
	text(275,450,250,20,2,26,0,"Copyright 2002 Amenesik / Sologic ",32,259);
	thaw(255,100,290,400);

	return(0);
}


private	int	accept_introduction_event()
{
	int	mx,my,mt,mb;
	if ((mt = visual_event(1)) != _MIMO_UP) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);

	return(-1);
}


private	int	accept_introduction_focus()
{
	_Context->keycode = 13;
	return(0);

}

public	int	accept_introduction()
{
	int	status=0;
	status = accept_introduction_create();
	if ( status != 0) return(status);
	status = accept_introduction_show();
	status = accept_introduction_focus();
	status = accept_introduction_remove();
	return(status);
}
/* End of File */

#endif /* _vanother_c */
