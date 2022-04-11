
#ifndef _vintro_c
#define _vintro_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vintro.xml                                               */
/* Target         : vintro.c                                                 */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "version.h"
#include "singprot.h"
#define en_Auto3569   "Sing : Version 1.0a"
#define fr_Auto3569   "Sing : Version 1.0a"
#define it_Auto3569   "Sing : Version 1.0a"
#define es_Auto3569   "Sing : Version 1.0a"
#define de_Auto3569   "Sing : Version 1.0a"
#define nl_Auto3569   "Sing : Version 1.0a"
#define pt_Auto3569   "Sing : Version 1.0a"
#define xx_Auto3569   "Sing : Version 1.0a"
#define en_Auto3570   ""
#define en_Auto3572   "logo.jpg"
#define fr_Auto3572   "logo.jpg"
#define it_Auto3572   "logo.jpg"
#define es_Auto3572   "logo.jpg"
#define de_Auto3572   "logo.jpg"
#define nl_Auto3572   "logo.jpg"
#define pt_Auto3572   "logo.jpg"
#define xx_Auto3572   "logo.jpg"
#define en__Auto3572   ""
#define fr__Auto3572   ""
#define it__Auto3572   ""
#define es__Auto3572   ""
#define de__Auto3572   ""
#define nl__Auto3572   ""
#define pt__Auto3572   ""
#define xx__Auto3572   ""
#define en_Auto3573   "abal3.jpg"
#define fr_Auto3573   "abal3.jpg"
#define it_Auto3573   "abal3.jpg"
#define es_Auto3573   "abal3.jpg"
#define de_Auto3573   "abal3.jpg"
#define nl_Auto3573   "abal3.jpg"
#define pt_Auto3573   "abal3.jpg"
#define xx_Auto3573   "abal3.jpg"
#define en__Auto3573   ""
#define fr__Auto3573   ""
#define it__Auto3573   ""
#define es__Auto3573   ""
#define de__Auto3573   ""
#define nl__Auto3573   ""
#define pt__Auto3573   ""
#define xx__Auto3573   ""
#define en_Auto3574   "Copyright (c) 2002,2007 Amenesik / Sologic"
#define fr_Auto3574   "Copyright (c) 2002,2007 Amenesik / Sologic"
#define it_Auto3574   "Copyright (c) 2002,2007 Amenesik / Sologic"
#define es_Auto3574   "Copyright (c) 2002,2007 Amenesik / Sologic"
#define de_Auto3574   "Copyright (c) 2002,2007 Amenesik / Sologic"
#define nl_Auto3574   "Copyright (c) 2002,2007 Amenesik / Sologic"
#define pt_Auto3574   "Copyright (c) 2002,2007 Amenesik / Sologic"
#define xx_Auto3574   "Copyright (c) 2002,2007 Amenesik / Sologic"
#define en__Auto3574   ""
#define fr__Auto3574   ""
#define it__Auto3574   ""
#define es__Auto3574   ""
#define de__Auto3574   ""
#define nl__Auto3574   ""
#define pt__Auto3574   ""
#define xx__Auto3574   ""
#define en_Auto3575   "Sing"
#define fr_Auto3575   "Sing"
#define it_Auto3575   "Sing"
#define es_Auto3575   "Sing"
#define de_Auto3575   "Sing"
#define nl_Auto3575   "Sing"
#define pt_Auto3575   "Sing"
#define xx_Auto3575   "Sing"
#define en__Auto3575   ""
#define fr__Auto3575   ""
#define it__Auto3575   ""
#define es__Auto3575   ""
#define de__Auto3575   ""
#define nl__Auto3575   ""
#define pt__Auto3575   ""
#define xx__Auto3575   ""
#define en__Auto3576   ""
#define fr__Auto3576   ""
#define it__Auto3576   ""
#define es__Auto3576   ""
#define de__Auto3576   ""
#define nl__Auto3576   ""
#define pt__Auto3576   ""
#define xx__Auto3576   ""

private struct accept_introduction_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3569[8];
	char * hint_Auto3569[8];
	int	x_Auto3569;
	int	y_Auto3569;
	int	w_Auto3569;
	int	h_Auto3569;
	char * hint_Auto3570[8];
	char * msg_Auto3572[8];
	char * hint_Auto3572[8];
	char * msg_Auto3573[8];
	char * hint_Auto3573[8];
	char * msg_Auto3574[8];
	char * hint_Auto3574[8];
	char * msg_Auto3575[8];
	char * hint_Auto3575[8];
	char * msg_Auto3576[8];
	char * hint_Auto3576[8];
	char	signature[1];
	};
static int	vfh[16];
private int on_Auto3572_event(struct accept_introduction_context * _Context);

public	int	accept_introduction_create(struct accept_introduction_context **cptr)
{

	int i;
	struct accept_introduction_context * _Context=(struct accept_introduction_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("bmap0414.fmf",12);
	if (!(_Context = allocate( sizeof( struct accept_introduction_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=1;
	for (i=0; i < 8; i++)_Context->msg_Auto3569[i]=" ";
	_Context->msg_Auto3569[0]=en_Auto3569;
	_Context->msg_Auto3569[1]=fr_Auto3569;
	_Context->msg_Auto3569[2]=it_Auto3569;
	_Context->msg_Auto3569[3]=es_Auto3569;
	_Context->msg_Auto3569[4]=de_Auto3569;
	_Context->msg_Auto3569[5]=nl_Auto3569;
	_Context->msg_Auto3569[6]=pt_Auto3569;
	_Context->msg_Auto3569[7]=xx_Auto3569;
	_Context->x_Auto3569=170;
	_Context->y_Auto3569=90;
	_Context->w_Auto3569=460;
	_Context->h_Auto3569=420;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3572[i]=" ";
	_Context->msg_Auto3572[0]=en_Auto3572;
	_Context->msg_Auto3572[1]=fr_Auto3572;
	_Context->msg_Auto3572[2]=it_Auto3572;
	_Context->msg_Auto3572[3]=es_Auto3572;
	_Context->msg_Auto3572[4]=de_Auto3572;
	_Context->msg_Auto3572[5]=nl_Auto3572;
	_Context->msg_Auto3572[6]=pt_Auto3572;
	_Context->msg_Auto3572[7]=xx_Auto3572;
	_Context->hint_Auto3572[0]=en__Auto3572;
	_Context->hint_Auto3572[1]=fr__Auto3572;
	_Context->hint_Auto3572[2]=it__Auto3572;
	_Context->hint_Auto3572[3]=es__Auto3572;
	_Context->hint_Auto3572[4]=de__Auto3572;
	_Context->hint_Auto3572[5]=nl__Auto3572;
	_Context->hint_Auto3572[6]=pt__Auto3572;
	_Context->hint_Auto3572[7]=xx__Auto3572;
	for (i=0; i < 8; i++)_Context->msg_Auto3573[i]=" ";
	_Context->msg_Auto3573[0]=en_Auto3573;
	_Context->msg_Auto3573[1]=fr_Auto3573;
	_Context->msg_Auto3573[2]=it_Auto3573;
	_Context->msg_Auto3573[3]=es_Auto3573;
	_Context->msg_Auto3573[4]=de_Auto3573;
	_Context->msg_Auto3573[5]=nl_Auto3573;
	_Context->msg_Auto3573[6]=pt_Auto3573;
	_Context->msg_Auto3573[7]=xx_Auto3573;
	_Context->hint_Auto3573[0]=en__Auto3573;
	_Context->hint_Auto3573[1]=fr__Auto3573;
	_Context->hint_Auto3573[2]=it__Auto3573;
	_Context->hint_Auto3573[3]=es__Auto3573;
	_Context->hint_Auto3573[4]=de__Auto3573;
	_Context->hint_Auto3573[5]=nl__Auto3573;
	_Context->hint_Auto3573[6]=pt__Auto3573;
	_Context->hint_Auto3573[7]=xx__Auto3573;
	for (i=0; i < 8; i++)_Context->msg_Auto3574[i]=" ";
	_Context->msg_Auto3574[0]=en_Auto3574;
	_Context->msg_Auto3574[1]=fr_Auto3574;
	_Context->msg_Auto3574[2]=it_Auto3574;
	_Context->msg_Auto3574[3]=es_Auto3574;
	_Context->msg_Auto3574[4]=de_Auto3574;
	_Context->msg_Auto3574[5]=nl_Auto3574;
	_Context->msg_Auto3574[6]=pt_Auto3574;
	_Context->msg_Auto3574[7]=xx_Auto3574;
	_Context->hint_Auto3574[0]=en__Auto3574;
	_Context->hint_Auto3574[1]=fr__Auto3574;
	_Context->hint_Auto3574[2]=it__Auto3574;
	_Context->hint_Auto3574[3]=es__Auto3574;
	_Context->hint_Auto3574[4]=de__Auto3574;
	_Context->hint_Auto3574[5]=nl__Auto3574;
	_Context->hint_Auto3574[6]=pt__Auto3574;
	_Context->hint_Auto3574[7]=xx__Auto3574;
	for (i=0; i < 8; i++)_Context->msg_Auto3575[i]=" ";
	_Context->msg_Auto3575[0]=en_Auto3575;
	_Context->msg_Auto3575[1]=fr_Auto3575;
	_Context->msg_Auto3575[2]=it_Auto3575;
	_Context->msg_Auto3575[3]=es_Auto3575;
	_Context->msg_Auto3575[4]=de_Auto3575;
	_Context->msg_Auto3575[5]=nl_Auto3575;
	_Context->msg_Auto3575[6]=pt_Auto3575;
	_Context->msg_Auto3575[7]=xx_Auto3575;
	_Context->hint_Auto3575[0]=en__Auto3575;
	_Context->hint_Auto3575[1]=fr__Auto3575;
	_Context->hint_Auto3575[2]=it__Auto3575;
	_Context->hint_Auto3575[3]=es__Auto3575;
	_Context->hint_Auto3575[4]=de__Auto3575;
	_Context->hint_Auto3575[5]=nl__Auto3575;
	_Context->hint_Auto3575[6]=pt__Auto3575;
	_Context->hint_Auto3575[7]=xx__Auto3575;
	for (i=0; i < 8; i++)_Context->msg_Auto3576[i]=" ";
	_Context->hint_Auto3576[0]=en__Auto3576;
	_Context->hint_Auto3576[1]=fr__Auto3576;
	_Context->hint_Auto3576[2]=it__Auto3576;
	_Context->hint_Auto3576[3]=es__Auto3576;
	_Context->hint_Auto3576[4]=de__Auto3576;
	_Context->hint_Auto3576[5]=nl__Auto3576;
	_Context->hint_Auto3576[6]=pt__Auto3576;
	_Context->hint_Auto3576[7]=xx__Auto3576;
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
	visual_window(170,90,460,420,vfh[2],_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]),0x404);
	visual_filzone(172,92,456,416,7952,8);
	visual_image(198,194,382,262,_Context->msg_Auto3572[_Context->language],515);
	visual_image(208,100,400,120,_Context->msg_Auto3573[_Context->language],515);
	visual_text(232,472,336,32,vfh[2],168,0,_Context->msg_Auto3574[_Context->language],strlen(_Context->msg_Auto3574[_Context->language]),259);
	visual_text(274,414,240,30,vfh[6],47,0,_Context->msg_Auto3575[_Context->language],strlen(_Context->msg_Auto3575[_Context->language]),1283);
	visual_text(274,444,240,30,vfh[2],47,0,sing_version(),strlen(sing_version()),259);
	visual_thaw(170,90,460,420);

	return(0);
}
private int on_Auto3572_event(struct accept_introduction_context * _Context) {
	return(27);
	return(-1);
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
	if (( mx >= 198 ) 
	&&  ( my >= 194 ) 
	&&  ( mx <= 580 ) 
	&&  ( my <= 456 )) {
		return(1); /* Auto3572 */
		}

	return(-1);
}


public	int	accept_introduction_focus(struct accept_introduction_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto3572 */
				_Context->keycode = visual_getch();
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_introduction_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=1;
			accept_introduction_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_introduction_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3572 */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3572_event(_Context)) != -1) break;

						}
					continue;
				case	0xffffffff :
				default :
					_Context->focus_item=1;
				continue;
				}
				break;
		case	0x1b :
			break;
		case	0xd :
			break;
		case	0x9 :
		case	0x5 :
			if ( _Context->focus_item < _Context->focus_items ) {
				_Context->focus_item++;			} else {
				_Context->focus_item=1;
			}
			continue;
		case	0xb :
			if ( _Context->focus_item > 1 ) {
				_Context->focus_item--;
			} else {
				_Context->focus_item=1;
			}
			continue;
		default :
			continue;

			}
		break;
		}


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
