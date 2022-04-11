
#ifndef _vpiece_c
#define _vpiece_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vpiece.xml                                               */
/* Target         : vpiece.c                                                 */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_component_selection_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	x_Auto3624;
	int	y_Auto3624;
	int	w_Auto3624;
	int	h_Auto3624;
	int	value_Auto3625;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};
static int	vfh[16];
private int on_Accept_event(struct accept_component_selection_context * _Context);
private int on_Cancel_event(struct accept_component_selection_context * _Context);

public	int	accept_component_selection_create(
	struct accept_component_selection_context ** cptr,
	char * pAuto3625)
{

	int i;
	struct accept_component_selection_context * _Context=(struct accept_component_selection_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_component_selection_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=4;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"W");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pAuto3625);
		if (!( pAuto3625 )) _Context->value_Auto3625=0;
		else	_Context->value_Auto3625 = *((int *)pAuto3625);
		}
	_Context->x_Auto3624=175;
	_Context->y_Auto3624=185;
	_Context->w_Auto3624=450;
	_Context->h_Auto3624=230;
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3624,_Context->y_Auto3624,450+10,230+10);
	return(0);
}

public 	int	accept_component_selection_hide(struct accept_component_selection_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3624,_Context->y_Auto3624);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_component_selection_remove(
	struct accept_component_selection_context * _Context,
	char * pAuto3625)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"W");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pAuto3625);
		if ( pAuto3625 != (char *) 0)
			*((int*)pAuto3625) = _Context->value_Auto3625;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_component_selection_show(struct accept_component_selection_context * _Context)
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3624,_Context->y_Auto3624);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto3624,_Context->y_Auto3624,450,230,vfh[2],"Sing : Version 1.0a",strlen("Sing : Version 1.0a"),0x403);
	visual_select(_Context->x_Auto3624+20,_Context->y_Auto3624+60,410,160,vfh[1],27,28,parse_selection(component_selection_list(),&_Context->value_Auto3625),0);
	visual_text(_Context->x_Auto3624+10,_Context->y_Auto3624+30,440,20,vfh[2],16,0,"Visual Component Selection",strlen("Visual Component Selection"),1283);
	visual_button(_Context->x_Auto3624+20,_Context->y_Auto3624+170,56,48,vfh[2],34,0,"ok.gif",strlen("ok.gif"),1040);
	visual_button(_Context->x_Auto3624+370,_Context->y_Auto3624+170,56,48,vfh[2],34,0,"cancel.gif",strlen("cancel.gif"),1040);
	visual_thaw(_Context->x_Auto3624,_Context->y_Auto3624,450,230);

	return(0);
}

private int Auto3624action(struct accept_component_selection_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_component_selection_hide(_Context);

		_Context->x_Auto3624 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3624 < 0) { _Context->x_Auto3624=0; }
		_Context->y_Auto3624 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3624 < 0) { _Context->y_Auto3624=0; }
			accept_component_selection_show(_Context);

		visual_thaw(_Context->x_Auto3624,_Context->y_Auto3624,450,230);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_component_selection_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_component_selection_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_component_selection_event(
struct accept_component_selection_context * _Context){
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3624+429) )  
	&&  (my >= (_Context->y_Auto3624+4) )  
	&&  (mx <= (_Context->x_Auto3624+446) )  
	&&  (my <= (_Context->y_Auto3624+20) )) {
		return(1);	/* Auto3624 */

		}
	if ((mx >= (_Context->x_Auto3624+413) )  
	&&  (my >= (_Context->y_Auto3624+4) )  
	&&  (mx <= (_Context->x_Auto3624+430) )  
	&&  (my <= (_Context->y_Auto3624+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vpiece.htm");
			};
		return(-1);	/* Auto3624 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3624+4) )  
		&&  (my >= (_Context->y_Auto3624+4) )  
		&&  (mx <= (_Context->x_Auto3624+382) )  
		&&  (my <= (_Context->y_Auto3624+20) )) {
			return( Auto3624action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3624+20+0) ) 
	&&  ( my >= (_Context->y_Auto3624+60) ) 
	&&  ( mx <= (_Context->x_Auto3624+20+410) ) 
	&&  ( my <= (_Context->y_Auto3624+60+16))) {
		return(2); /* Auto3625 */
		}
	if (( mx >= (_Context->x_Auto3624+20) ) 
	&&  ( my >= (_Context->y_Auto3624+170) ) 
	&&  ( mx <= (_Context->x_Auto3624+20+56) ) 
	&&  ( my <= (_Context->y_Auto3624+170+48))) {
		return(3); /* Accept */
		}
	if (( mx >= (_Context->x_Auto3624+370) ) 
	&&  ( my >= (_Context->y_Auto3624+170) ) 
	&&  ( mx <= (_Context->x_Auto3624+370+56) ) 
	&&  ( my <= (_Context->y_Auto3624+170+48))) {
		return(4); /* Cancel */
		}

	return(-1);
}


public	int	accept_component_selection_focus(struct accept_component_selection_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto3625 */
				_Context->keycode = visual_select(_Context->x_Auto3624+20,_Context->y_Auto3624+60,410,160,vfh[1],27,28,parse_selection(component_selection_list(),&_Context->value_Auto3625),2);
				break;
			case	0x3 :
				/* Accept */
				visual_button(_Context->x_Auto3624+20,_Context->y_Auto3624+170,56,48,vfh[2],34,0,"ok.gif",strlen("ok.gif"),1042);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_Auto3624+20,_Context->y_Auto3624+170,56,48,vfh[2],34,0,"ok.gif",strlen("ok.gif"),1040);
				break;
			case	0x4 :
				/* Cancel */
				visual_button(_Context->x_Auto3624+370,_Context->y_Auto3624+170,56,48,vfh[2],34,0,"cancel.gif",strlen("cancel.gif"),1042);
				_Context->keycode = visual_getch();
	visual_button(_Context->x_Auto3624+370,_Context->y_Auto3624+170,56,48,vfh[2],34,0,"cancel.gif",strlen("cancel.gif"),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_component_selection_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=4;
			accept_component_selection_show(_Context);
			continue;
		case	0x100 :
			if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
			if ((retcode=accept_component_selection_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3624 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Auto3625 */
					continue;
				case	0x3 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_Auto3624+20,_Context->y_Auto3624+170,56,48,vfh[2],34,0,"ok.gif",strlen("ok.gif"),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_Auto3624+20,_Context->y_Auto3624+170,56,48,vfh[2],34,0,"ok.gif",strlen("ok.gif"),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_button(_Context->x_Auto3624+370,_Context->y_Auto3624+170,56,48,vfh[2],34,0,"cancel.gif",strlen("cancel.gif"),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
	visual_button(_Context->x_Auto3624+370,_Context->y_Auto3624+170,56,48,vfh[2],34,0,"cancel.gif",strlen("cancel.gif"),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

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
				_Context->focus_item=4;
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

public	int	accept_component_selection(
	char * pAuto3625)
{
	int	status=0;
	struct accept_component_selection_context * _Context=(struct accept_component_selection_context*) 0;
	status = accept_component_selection_create(
	&_Context,
	 pAuto3625);
	if ( status != 0) return(status);
	status = accept_component_selection_show(_Context);
		enter_modal();
	status = accept_component_selection_focus(_Context);
		leave_modal();
	status = accept_component_selection_hide(_Context);
	status = accept_component_selection_remove(
	_Context,
	 pAuto3625);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vpiece_c */
