
#ifndef _vintro_c
#define _vintro_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vintro.sng  */
/* Target         : vintro.c  */
/* Identification : 0.0-1065019114-3524.3523 */
/* ------------------------------------------------------------------------- */

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

private	int	accept_introduction_hide()
{

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
	visual_freeze();
	visual_window(255,100,290,400,2,"Sing : Version 1.0",18,0x400);
	visual_image(258,122,282,374,"skin.gif",4);
	visual_frame(286,161,224,284,3);
	visual_image(291,165,220,276,"sing.gif",0);
	visual_text(285,130,224,32,3,27,0,"Sing",4,1027);
	visual_text(275,450,250,20,2,27,0,"Copyright 2003 Prologue Software",32,3);
	visual_thaw(255,100,290,400);

	return(0);
}


private	int	accept_introduction_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);

	return(-1);
}


private	int	accept_introduction_focus()
{
	int retcode=0;
	_Context->keycode=13;


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_introduction()
{
	int	status=0;
	status = accept_introduction_create();
	if ( status != 0) return(status);
	status = accept_introduction_show();
		enter_modal();
	status = accept_introduction_focus();
		leave_modal();
	status = accept_introduction_hide();
	status = accept_introduction_remove();

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vintro_c */
