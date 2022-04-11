
#ifndef _vseek_c
#define _vseek_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vview.xml                                                */
/* Target         : vseek.c                                                  */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto3598   ""
#define fr__Auto3598   ""
#define it__Auto3598   ""
#define es__Auto3598   ""
#define de__Auto3598   ""
#define nl__Auto3598   ""
#define pt__Auto3598   ""
#define xx__Auto3598   ""
#define en_Pattern   ""
#define en__Pattern   ""
#define en_Auto3599   "Tree View Item Search Pattern"
#define fr_Auto3599   "Chemin du motif d'un item de l'arborecence projet"
#define it_Auto3599   "Tree View Item Search Pattern"
#define es_Auto3599   "Tree View Item Search Pattern"
#define de_Auto3599   "Tree View Item Search Pattern"
#define nl_Auto3599   "Tree View Item Search Pattern"
#define pt_Auto3599   "Tree View Item Search Pattern"
#define xx_Auto3599   "Tree View Item Search Pattern"
#define en_Launch   "OK"
#define fr_Launch   "Ok"
#define it_Launch   "Ok"
#define es_Launch   "Ok"
#define de_Launch   "Ok"
#define nl_Launch   "Ok"
#define pt_Launch   "Ok"
#define xx_Launch   "Ok"
#define en__Launch   ""

private struct accept_treeviewitem_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3598[8];
	char * hint_Auto3598[8];
	int	x_Auto3598;
	int	y_Auto3598;
	int	w_Auto3598;
	int	h_Auto3598;
	char * hint_Pattern[8];
	char	buffer_Pattern[256];
	char * msg_Auto3599[8];
	char * hint_Auto3599[8];
	char * msg_Launch[8];
	int	trigger_Launch;
	char * hint_Launch[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};
static int	vfh[16];
private int on_Launch_event(struct accept_treeviewitem_context * _Context);

public	int	accept_treeviewitem_create(
	struct accept_treeviewitem_context ** cptr,
	char * pPattern)
{

	int i;
	struct accept_treeviewitem_context * _Context=(struct accept_treeviewitem_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_treeviewitem_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=3;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Pattern, 255, pPattern);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3598[i]=" ";
	_Context->hint_Auto3598[0]=en__Auto3598;
	_Context->hint_Auto3598[1]=fr__Auto3598;
	_Context->hint_Auto3598[2]=it__Auto3598;
	_Context->hint_Auto3598[3]=es__Auto3598;
	_Context->hint_Auto3598[4]=de__Auto3598;
	_Context->hint_Auto3598[5]=nl__Auto3598;
	_Context->hint_Auto3598[6]=pt__Auto3598;
	_Context->hint_Auto3598[7]=xx__Auto3598;
	_Context->x_Auto3598=50;
	_Context->y_Auto3598=30;
	_Context->w_Auto3598=510;
	_Context->h_Auto3598=80;
	_Context->window_col=50;
	_Context->window_row=30;
	_Context->hint_Pattern[0]=en__Pattern;
	for (i=0; i < 8; i++)_Context->msg_Auto3599[i]=" ";
	_Context->msg_Auto3599[0]=en_Auto3599;
	_Context->msg_Auto3599[1]=fr_Auto3599;
	_Context->msg_Auto3599[2]=it_Auto3599;
	_Context->msg_Auto3599[3]=es_Auto3599;
	_Context->msg_Auto3599[4]=de_Auto3599;
	_Context->msg_Auto3599[5]=nl_Auto3599;
	_Context->msg_Auto3599[6]=pt_Auto3599;
	_Context->msg_Auto3599[7]=xx_Auto3599;
	for (i=0; i < 8; i++)_Context->msg_Launch[i]=" ";
	_Context->msg_Launch[0]=en_Launch;
	_Context->msg_Launch[1]=fr_Launch;
	_Context->msg_Launch[2]=it_Launch;
	_Context->msg_Launch[3]=es_Launch;
	_Context->msg_Launch[4]=de_Launch;
	_Context->msg_Launch[5]=nl_Launch;
	_Context->msg_Launch[6]=pt_Launch;
	_Context->msg_Launch[7]=xx_Launch;
	_Context->hint_Launch[0]=en__Launch;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3598,_Context->y_Auto3598,510+10,80+10);
	return(0);
}

public 	int	accept_treeviewitem_hide(struct accept_treeviewitem_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3598,_Context->y_Auto3598);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_treeviewitem_remove(
	struct accept_treeviewitem_context * _Context,
	char * pPattern)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Pattern, 255, pPattern);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_treeviewitem_show(struct accept_treeviewitem_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3598,_Context->y_Auto3598);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3598,_Context->y_Auto3598,510,80,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3598,_Context->y_Auto3598,510,80,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_frame(_Context->x_Auto3598+10,_Context->y_Auto3598+50,456+2,16+2,5);
	visual_text(_Context->x_Auto3598+10+1,_Context->y_Auto3598+50+1,456,16,vfh[1],27,28,_Context->buffer_Pattern,255,0);
	visual_text(_Context->x_Auto3598+10,_Context->y_Auto3598+30,460,20,vfh[2],16,0,_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]),1282);
	_Context->trigger_Launch=visual_trigger_code(_Context->msg_Launch[_Context->language],strlen(_Context->msg_Launch[_Context->language]));
	visual_button(_Context->x_Auto3598+470,_Context->y_Auto3598+30,32,40,vfh[2],27,28,_Context->msg_Launch[_Context->language],strlen(_Context->msg_Launch[_Context->language]),0);
	visual_thaw(_Context->x_Auto3598,_Context->y_Auto3598,510,80);

	return(0);
}

private int Auto3598action(struct accept_treeviewitem_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_treeviewitem_hide(_Context);

		_Context->x_Auto3598 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3598 < 0) { _Context->x_Auto3598=0; }
		_Context->y_Auto3598 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3598 < 0) { _Context->y_Auto3598=0; }
			accept_treeviewitem_show(_Context);

		visual_thaw(_Context->x_Auto3598,_Context->y_Auto3598,510,80);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Launch_event(struct accept_treeviewitem_context * _Context) {
	return(13);
	return(-1);
}


public	int	accept_treeviewitem_event(
struct accept_treeviewitem_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Launch == mb ) return(3);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3598+489) )  
	&&  (my >= (_Context->y_Auto3598+4) )  
	&&  (mx <= (_Context->x_Auto3598+506) )  
	&&  (my <= (_Context->y_Auto3598+20) )) {
		return(1);	/* Auto3598 */

		}
	if ((mx >= (_Context->x_Auto3598+473) )  
	&&  (my >= (_Context->y_Auto3598+4) )  
	&&  (mx <= (_Context->x_Auto3598+490) )  
	&&  (my <= (_Context->y_Auto3598+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vseek.htm");
			};
		return(-1);	/* Auto3598 */

		}
	if ((mx >= (_Context->x_Auto3598+457) )  
	&&  (my >= (_Context->y_Auto3598+4) )  
	&&  (mx <= (_Context->x_Auto3598+474) )  
	&&  (my <= (_Context->y_Auto3598+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_treeviewitem_show(_Context);
		return(-1);	/* Auto3598 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3598+4) )  
		&&  (my >= (_Context->y_Auto3598+4) )  
		&&  (mx <= (_Context->x_Auto3598+442) )  
		&&  (my <= (_Context->y_Auto3598+20) )) {
			return( Auto3598action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3598+10) ) 
	&&  ( my >= (_Context->y_Auto3598+50) ) 
	&&  ( mx <= (_Context->x_Auto3598+10+456) ) 
	&&  ( my <= (_Context->y_Auto3598+50+16))) {
		return(2); /* Pattern */
		}
	if (( mx >= (_Context->x_Auto3598+470) ) 
	&&  ( my >= (_Context->y_Auto3598+30) ) 
	&&  ( mx <= (_Context->x_Auto3598+470+32) ) 
	&&  ( my <= (_Context->y_Auto3598+30+40))) {
		return(3); /* Launch */
		}

	return(-1);
}


public	int	accept_treeviewitem_focus(struct accept_treeviewitem_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Pattern */
				_Context->keycode = visual_edit(_Context->x_Auto3598+10+1,_Context->y_Auto3598+50+1,456,16,vfh[1],_Context->buffer_Pattern,255);
			break;
			case	0x3 :
				/* Launch */
				_Context->trigger_Launch=visual_trigger_code(_Context->msg_Launch[_Context->language],strlen(_Context->msg_Launch[_Context->language]));
				visual_button(_Context->x_Auto3598+470,_Context->y_Auto3598+30,32,40,vfh[2],27,28,_Context->msg_Launch[_Context->language],strlen(_Context->msg_Launch[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Launch=visual_trigger_code(_Context->msg_Launch[_Context->language],strlen(_Context->msg_Launch[_Context->language]));
	visual_button(_Context->x_Auto3598+470,_Context->y_Auto3598+30,32,40,vfh[2],27,28,_Context->msg_Launch[_Context->language],strlen(_Context->msg_Launch[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_treeviewitem_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=3;
			accept_treeviewitem_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_treeviewitem_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3598 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Pattern */
					continue;
				case	0x3 :
					/* Launch */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Launch=visual_trigger_code(_Context->msg_Launch[_Context->language],strlen(_Context->msg_Launch[_Context->language]));
						visual_button(_Context->x_Auto3598+470,_Context->y_Auto3598+30,32,40,vfh[2],27,28,_Context->msg_Launch[_Context->language],strlen(_Context->msg_Launch[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Launch=visual_trigger_code(_Context->msg_Launch[_Context->language],strlen(_Context->msg_Launch[_Context->language]));
	visual_button(_Context->x_Auto3598+470,_Context->y_Auto3598+30,32,40,vfh[2],27,28,_Context->msg_Launch[_Context->language],strlen(_Context->msg_Launch[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Launch_event(_Context)) != -1) break;

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
				_Context->focus_item=3;
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

public	int	accept_treeviewitem(
	char * pPattern)
{
	int	status=0;
	struct accept_treeviewitem_context * _Context=(struct accept_treeviewitem_context*) 0;
	status = accept_treeviewitem_create(
	&_Context,
	 pPattern);
	if ( status != 0) return(status);
	status = accept_treeviewitem_show(_Context);
		enter_modal();
	status = accept_treeviewitem_focus(_Context);
		leave_modal();
	status = accept_treeviewitem_hide(_Context);
	status = accept_treeviewitem_remove(
	_Context,
	 pPattern);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vseek_c */
