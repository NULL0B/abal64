
#ifndef _vintro_c 
#define _vintro_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vintro.xml  */
/* Target         : vintro.c  */
/* Identification : 0.0-1100085447-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "version.h"
#include "singprot.h"
#define en_Auto1736   "Sing : Version 1.0a"
#define en_Auto1740   ""
#define en_Auto1805   "/home/abal3/images/logo.jpg"
#define en_Auto1811   "abal3.jpg"
#define fr_Auto1811   "abal3.jpg"
#define it_Auto1811   "abal3.jpg"
#define es_Auto1811   "abal3.jpg"
#define de_Auto1811   "abal3.jpg"
#define nl_Auto1811   "abal3.jpg"
#define pt_Auto1811   "abal3.jpg"
#define xx_Auto1811   "abal3.jpg"
#define en_Auto1807   "Copyright (c) 2004 Amenesik / Sologic "
#define fr_Auto1807   "Copyright (c) 2003-2004 Amenesik / Sologic "
#define it_Auto1807   "Copyright (c) 2003-2004 Amenesik / Sologic "
#define es_Auto1807   "Copyright (c) 2003-2004 Amenesik / Sologic "
#define de_Auto1807   "Copyright (c) 2003-2004 Amenesik / Sologic "
#define nl_Auto1807   "Copyright (c) 2003-2004 Amenesik / Sologic "
#define pt_Auto1807   "Copyright (c) 2003-2004 Amenesik / Sologic "
#define xx_Auto1807   "Copyright (c) 2003-2004 Amenesik / Sologic "
#define en_Auto1809   "Sing"
#define fr_Auto1809   "Sing Version 1.0a"
#define it_Auto1809   "Sing Version 1.0a"
#define es_Auto1809   "Sing Version 1.0a"
#define de_Auto1809   "Sing Version 1.0a"
#define nl_Auto1809   "Sing Version 1.0a"
#define pt_Auto1809   "Sing Version 1.0a"
#define xx_Auto1809   "Sing Version 1.0a"
static int	vfh[10];

private struct accept_introduction_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto1736[8];
	int	x_Auto1736;
	int	y_Auto1736;
	int	w_Auto1736;
	int	h_Auto1736;
	char * msg_Auto1805[8];
	char * msg_Auto1811[8];
	char * msg_Auto1807[8];
	char * msg_Auto1809[8];
	char * msg_Auto1806[8];
	char	signature[1];
	};

public	int	accept_introduction_create(struct accept_introduction_context **cptr)
{

	int i;
	struct accept_introduction_context * _Context=(struct accept_introduction_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_introduction_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=0;
	for (i=0; i < 8; i++)_Context->msg_Auto1736[i]=" ";
	_Context->msg_Auto1736[0]=en_Auto1736;
	_Context->x_Auto1736=170;
	_Context->y_Auto1736=90;
	_Context->w_Auto1736=460;
	_Context->h_Auto1736=420;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto1805[i]=" ";
	_Context->msg_Auto1805[0]=en_Auto1805;
	for (i=0; i < 8; i++)_Context->msg_Auto1811[i]=" ";
	_Context->msg_Auto1811[0]=en_Auto1811;
	_Context->msg_Auto1811[1]=fr_Auto1811;
	_Context->msg_Auto1811[2]=it_Auto1811;
	_Context->msg_Auto1811[3]=es_Auto1811;
	_Context->msg_Auto1811[4]=de_Auto1811;
	_Context->msg_Auto1811[5]=nl_Auto1811;
	_Context->msg_Auto1811[6]=pt_Auto1811;
	_Context->msg_Auto1811[7]=xx_Auto1811;
	for (i=0; i < 8; i++)_Context->msg_Auto1807[i]=" ";
	_Context->msg_Auto1807[0]=en_Auto1807;
	_Context->msg_Auto1807[1]=fr_Auto1807;
	_Context->msg_Auto1807[2]=it_Auto1807;
	_Context->msg_Auto1807[3]=es_Auto1807;
	_Context->msg_Auto1807[4]=de_Auto1807;
	_Context->msg_Auto1807[5]=nl_Auto1807;
	_Context->msg_Auto1807[6]=pt_Auto1807;
	_Context->msg_Auto1807[7]=xx_Auto1807;
	for (i=0; i < 8; i++)_Context->msg_Auto1809[i]=" ";
	_Context->msg_Auto1809[0]=en_Auto1809;
	_Context->msg_Auto1809[1]=fr_Auto1809;
	_Context->msg_Auto1809[2]=it_Auto1809;
	_Context->msg_Auto1809[3]=es_Auto1809;
	_Context->msg_Auto1809[4]=de_Auto1809;
	_Context->msg_Auto1809[5]=nl_Auto1809;
	_Context->msg_Auto1809[6]=pt_Auto1809;
	_Context->msg_Auto1809[7]=xx_Auto1809;
	for (i=0; i < 8; i++)_Context->msg_Auto1806[i]=" ";
	return(0);
}

public 	int	accept_introduction_hide(struct accept_introduction_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;

	return(result);
}

public	int	accept_introduction_remove(struct accept_introduction_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_introduction_show(struct accept_introduction_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	visual_window(170,90,460,420,vfh[2],_Context->msg_Auto1736[_Context->language],strlen(_Context->msg_Auto1736[_Context->language]),0x404);
	visual_filzone(172,92,456,416,7952,8);
	visual_image(198,194,382,262,_Context->msg_Auto1805[_Context->language],515);
	visual_image(208,100,400,120,_Context->msg_Auto1811[_Context->language],515);
	visual_text(224,464,336,32,vfh[2],168,0,_Context->msg_Auto1807[_Context->language],strlen(_Context->msg_Auto1807[_Context->language]),259);
	visual_text(274,414,240,30,vfh[6],47,0,_Context->msg_Auto1809[_Context->language],strlen(_Context->msg_Auto1809[_Context->language]),1283);
	visual_text(274,444,240,30,vfh[2],47,0,sing_version(),strlen(sing_version()),259);
	visual_thaw(170,90,460,420);
	visual_thaw(170,90,460,420);

	return(0);
}


public	int	accept_introduction_event(
struct accept_introduction_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);

	return(-1);
}


public	int	accept_introduction_focus(struct accept_introduction_context * _Context)
{
	int retcode=0;
	_Context->keycode=13;


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_introduction()
{
	int	status=0;
	struct accept_introduction_context * _Context=(struct accept_introduction_context*) 0;
	status = accept_introduction_create(&_Context);
	if ( status != 0) return(status);
	status = accept_introduction_show(_Context);
		enter_modal();
	status = accept_introduction_focus(_Context);
		leave_modal();
	status = accept_introduction_hide(_Context);
	status = accept_introduction_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vintro_c */
