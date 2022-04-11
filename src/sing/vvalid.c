
#ifndef _vvalid_c
#define _vvalid_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vvalid.xml                                               */
/* Target         : vvalid.c                                                 */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"

private struct accept_valid_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	x_auto562;
	int	y_auto562;
	int	w_auto562;
	int	h_auto562;
	char	buffer_Message1[73];
	char	buffer_Message2[73];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};
static int	vfh[16];
private int on_Accept_event(struct accept_valid_context * _Context);

public	int	accept_valid_create(
	struct accept_valid_context ** cptr,
	char * pMessage1,
	char * pMessage2)
{

	int i;
	struct accept_valid_context * _Context=(struct accept_valid_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_valid_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=2;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"KK");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Message1, 72, pMessage1);
		visual_transferin(_Context->buffer_Message2, 72, pMessage2);
		}
	_Context->x_auto562=130;
	_Context->y_auto562=170;
	_Context->w_auto562=540;
	_Context->h_auto562=260;
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto562,_Context->y_auto562,540+10,260+10);
	return(0);
}

public 	int	accept_valid_hide(struct accept_valid_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_auto562,_Context->y_auto562);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_valid_remove(
	struct accept_valid_context * _Context,
	char * pMessage1,
	char * pMessage2)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"KK");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Message1, 72, pMessage1);
		visual_transferout(_Context->buffer_Message2, 72, pMessage2);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_valid_show(struct accept_valid_context * _Context)
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto562,_Context->y_auto562);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_auto562,_Context->y_auto562,540,260,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_auto562,_Context->y_auto562,540,260,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x403);
		}
	visual_button(_Context->x_auto562+230,_Context->y_auto562+190,56,48,vfh[2],34,0,"ok.gif",strlen("ok.gif"),1040);
	visual_frame(_Context->x_auto562+20,_Context->y_auto562+80,504+2,32+2,5);
	visual_text(_Context->x_auto562+20+1,_Context->y_auto562+80+1,504,32,vfh[2],176,31,_Context->buffer_Message1,72,3);
	visual_frame(_Context->x_auto562+20,_Context->y_auto562+130,504+2,32+2,5);
	visual_text(_Context->x_auto562+20+1,_Context->y_auto562+130+1,504,32,vfh[2],176,31,_Context->buffer_Message2,72,3);
	visual_thaw(_Context->x_auto562,_Context->y_auto562,540,260);

	return(0);
}

private int auto562action(struct accept_valid_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_valid_hide(_Context);

		_Context->x_auto562 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto562 < 0) { _Context->x_auto562=0; }
		_Context->y_auto562 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto562 < 0) { _Context->y_auto562=0; }
			accept_valid_show(_Context);

		visual_thaw(_Context->x_auto562,_Context->y_auto562,540,260);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_valid_context * _Context) {
	return(13);
	return(-1);
}


public	int	accept_valid_event(
struct accept_valid_context * _Context){
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_auto562+519) )  
	&&  (my >= (_Context->y_auto562+4) )  
	&&  (mx <= (_Context->x_auto562+536) )  
	&&  (my <= (_Context->y_auto562+20) )) {
		return(1);	/* auto562 */

		}
	if ((mx >= (_Context->x_auto562+503) )  
	&&  (my >= (_Context->y_auto562+4) )  
	&&  (mx <= (_Context->x_auto562+520) )  
	&&  (my <= (_Context->y_auto562+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vvalid.htm");
			};
		return(-1);	/* auto562 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_auto562+4) )  
		&&  (my >= (_Context->y_auto562+4) )  
		&&  (mx <= (_Context->x_auto562+472) )  
		&&  (my <= (_Context->y_auto562+20) )) {
			return( auto562action(_Context) );
			}
		}
	if (( mx >= (_Context->x_auto562+230) ) 
	&&  ( my >= (_Context->y_auto562+190) ) 
	&&  ( mx <= (_Context->x_auto562+230+56) ) 
	&&  ( my <= (_Context->y_auto562+190+48))) {
		return(2); /* Accept */
		}

	return(-1);
}


public	int	accept_valid_focus(struct accept_valid_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Accept */
				visual_button(_Context->x_auto562+230,_Context->y_auto562+190,56,48,vfh[2],34,0,"ok.gif",strlen("ok.gif"),1042);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_auto562+230,_Context->y_auto562+190,56,48,vfh[2],34,0,"ok.gif",strlen("ok.gif"),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_valid_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=2;
			accept_valid_show(_Context);
			continue;
		case	0x100 :
			if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
			if ((retcode=accept_valid_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* auto562 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_auto562+230,_Context->y_auto562+190,56,48,vfh[2],34,0,"ok.gif",strlen("ok.gif"),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_auto562+230,_Context->y_auto562+190,56,48,vfh[2],34,0,"ok.gif",strlen("ok.gif"),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

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
				_Context->focus_item=2;
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

public	int	accept_valid(
	char * pMessage1,
	char * pMessage2)
{
	int	status=0;
	struct accept_valid_context * _Context=(struct accept_valid_context*) 0;
	status = accept_valid_create(
	&_Context,
	 pMessage1,
	 pMessage2);
	if ( status != 0) return(status);
	status = accept_valid_show(_Context);
		enter_modal();
	status = accept_valid_focus(_Context);
		leave_modal();
	status = accept_valid_hide(_Context);
	status = accept_valid_remove(
	_Context,
	 pMessage1,
	 pMessage2);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vvalid_c */
