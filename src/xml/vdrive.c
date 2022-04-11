
#ifndef _vdrive_c
#define _vdrive_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.24  */
/* Production     : C  */
/* Project        : vdrive.xml  */
/* Target         : vdrive.c  */
/* Identification : 0.0-1083761394-9564.9563 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
static int	vfh[10];

private struct visual_driver_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char	signature[1];
	} * _Context;

private	int	visual_driver_create()
{

	int i;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	if (!(_Context = allocate( sizeof( struct visual_driver_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=0;
	return(0);
}

private	int	visual_driver_hide()
{
	int	result=_Context->keycode;

	return(result);
}

private	int	visual_driver_remove()
{

	int	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}

private	int	visual_driver_show()
{
	visual_filzone(0,0,56,60,27,11);
	visual_image(20,20,20,20,"plusicon.gif",0);
	visual_image(4,20,20,20,"lefticon.gif",0);
	visual_image(20,4,20,20,"upicon.gif",0);
	visual_image(20,36,20,20,"downicon.gif",0);
	visual_image(36,20,20,20,"riteicon.gif",0);

	return(0);
}


private	int	visual_driver_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);

	return(-1);
}


private	int	visual_driver_focus()
{
	int retcode=0;
	_Context->keycode=13;


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	visual_driver()
{
	int	status=0;
	status = visual_driver_create();
	if ( status != 0) return(status);
	status = visual_driver_show();
		enter_modal();
	status = visual_driver_focus();
		leave_modal();
	status = visual_driver_hide();
	status = visual_driver_remove();

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vdrive_c */
