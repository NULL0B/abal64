
#ifndef _vcss_c
#define _vcss_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vcss.xml                                                 */
/* Target         : vcss.c                                                   */
/* Identification : 0.0-1177511934-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "vcss.h"
#define en__Auto2714   ""
#define fr__Auto2714   ""
#define it__Auto2714   ""
#define es__Auto2714   ""
#define de__Auto2714   ""
#define nl__Auto2714   ""
#define pt__Auto2714   ""
#define xx__Auto2714   ""
#define en_Auto2715   "Widget Style Selection"
#define fr_Auto2715   "Selection du style d'un widget"
#define it_Auto2715   "Widget Style Selection"
#define es_Auto2715   "Widget Style Selection"
#define de_Auto2715   "Widget Style Selection"
#define nl_Auto2715   "Widget Style Selection"
#define pt_Auto2715   "Widget Style Selection"
#define xx_Auto2715   "Widget Style Selection"
#define en__Auto2715   ""
#define fr__Auto2715   ""
#define it__Auto2715   ""
#define es__Auto2715   ""
#define de__Auto2715   ""
#define nl__Auto2715   ""
#define pt__Auto2715   ""
#define xx__Auto2715   ""
#define en__WidgetStyle   ""
#define fr__WidgetStyle   ""
#define it__WidgetStyle   ""
#define es__WidgetStyle   ""
#define de__WidgetStyle   ""
#define nl__WidgetStyle   ""
#define pt__WidgetStyle   ""
#define xx__WidgetStyle   ""
#define en_Auto2716   "ok.gif"
#define fr_Auto2716   "ok.gif"
#define it_Auto2716   "ok.gif"
#define es_Auto2716   "ok.gif"
#define de_Auto2716   "ok.gif"
#define nl_Auto2716   "ok.gif"
#define pt_Auto2716   "ok.gif"
#define xx_Auto2716   "ok.gif"
#define en__Auto2716   ""
#define fr__Auto2716   ""
#define it__Auto2716   ""
#define es__Auto2716   ""
#define de__Auto2716   ""
#define nl__Auto2716   ""
#define pt__Auto2716   ""
#define xx__Auto2716   ""
#define en_Auto2717   "cancel.gif"
#define fr_Auto2717   "cancel.gif"
#define it_Auto2717   "cancel.gif"
#define es_Auto2717   "cancel.gif"
#define de_Auto2717   "cancel.gif"
#define nl_Auto2717   "cancel.gif"
#define pt_Auto2717   "cancel.gif"
#define xx_Auto2717   "cancel.gif"
#define en__Auto2717   ""
#define fr__Auto2717   ""
#define it__Auto2717   ""
#define es__Auto2717   ""
#define de__Auto2717   ""
#define nl__Auto2717   ""
#define pt__Auto2717   ""
#define xx__Auto2717   ""

private struct accept_widget_style_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto2714[8];
	char * hint_Auto2714[8];
	int	x_Auto2714;
	int	y_Auto2714;
	int	w_Auto2714;
	int	h_Auto2714;
	char * msg_Auto2715[8];
	char * hint_Auto2715[8];
	char * msg_WidgetStyle[8];
	char * hint_WidgetStyle[8];
	int	value_WidgetStyle;
	char * msg_Auto2716[8];
	int	trigger_Auto2716;
	char * hint_Auto2716[8];
	char * msg_Auto2717[8];
	int	trigger_Auto2717;
	char * hint_Auto2717[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};
static int	vfh[16];

public	int	accept_widget_style_create(
	struct accept_widget_style_context ** cptr,
	char * pWidgetStyle)
{

	int i;
	struct accept_widget_style_context * _Context=(struct accept_widget_style_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_widget_style_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=4;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"W");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pWidgetStyle);
		if (!( pWidgetStyle )) _Context->value_WidgetStyle=0;
		else	_Context->value_WidgetStyle = *((int *)pWidgetStyle);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto2714[i]=" ";
	_Context->hint_Auto2714[0]=en__Auto2714;
	_Context->hint_Auto2714[1]=fr__Auto2714;
	_Context->hint_Auto2714[2]=it__Auto2714;
	_Context->hint_Auto2714[3]=es__Auto2714;
	_Context->hint_Auto2714[4]=de__Auto2714;
	_Context->hint_Auto2714[5]=nl__Auto2714;
	_Context->hint_Auto2714[6]=pt__Auto2714;
	_Context->hint_Auto2714[7]=xx__Auto2714;
	_Context->x_Auto2714=160;
	_Context->y_Auto2714=220;
	_Context->w_Auto2714=480;
	_Context->h_Auto2714=160;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2715[i]=" ";
	_Context->msg_Auto2715[0]=en_Auto2715;
	_Context->msg_Auto2715[1]=fr_Auto2715;
	_Context->msg_Auto2715[2]=it_Auto2715;
	_Context->msg_Auto2715[3]=es_Auto2715;
	_Context->msg_Auto2715[4]=de_Auto2715;
	_Context->msg_Auto2715[5]=nl_Auto2715;
	_Context->msg_Auto2715[6]=pt_Auto2715;
	_Context->msg_Auto2715[7]=xx_Auto2715;
	_Context->hint_Auto2715[0]=en__Auto2715;
	_Context->hint_Auto2715[1]=fr__Auto2715;
	_Context->hint_Auto2715[2]=it__Auto2715;
	_Context->hint_Auto2715[3]=es__Auto2715;
	_Context->hint_Auto2715[4]=de__Auto2715;
	_Context->hint_Auto2715[5]=nl__Auto2715;
	_Context->hint_Auto2715[6]=pt__Auto2715;
	_Context->hint_Auto2715[7]=xx__Auto2715;
	for (i=0; i < 8; i++)_Context->msg_WidgetStyle[i]=" ";
	_Context->hint_WidgetStyle[0]=en__WidgetStyle;
	_Context->hint_WidgetStyle[1]=fr__WidgetStyle;
	_Context->hint_WidgetStyle[2]=it__WidgetStyle;
	_Context->hint_WidgetStyle[3]=es__WidgetStyle;
	_Context->hint_WidgetStyle[4]=de__WidgetStyle;
	_Context->hint_WidgetStyle[5]=nl__WidgetStyle;
	_Context->hint_WidgetStyle[6]=pt__WidgetStyle;
	_Context->hint_WidgetStyle[7]=xx__WidgetStyle;
	for (i=0; i < 8; i++)_Context->msg_Auto2716[i]=" ";
	_Context->msg_Auto2716[0]=en_Auto2716;
	_Context->msg_Auto2716[1]=fr_Auto2716;
	_Context->msg_Auto2716[2]=it_Auto2716;
	_Context->msg_Auto2716[3]=es_Auto2716;
	_Context->msg_Auto2716[4]=de_Auto2716;
	_Context->msg_Auto2716[5]=nl_Auto2716;
	_Context->msg_Auto2716[6]=pt_Auto2716;
	_Context->msg_Auto2716[7]=xx_Auto2716;
	_Context->hint_Auto2716[0]=en__Auto2716;
	_Context->hint_Auto2716[1]=fr__Auto2716;
	_Context->hint_Auto2716[2]=it__Auto2716;
	_Context->hint_Auto2716[3]=es__Auto2716;
	_Context->hint_Auto2716[4]=de__Auto2716;
	_Context->hint_Auto2716[5]=nl__Auto2716;
	_Context->hint_Auto2716[6]=pt__Auto2716;
	_Context->hint_Auto2716[7]=xx__Auto2716;
	for (i=0; i < 8; i++)_Context->msg_Auto2717[i]=" ";
	_Context->msg_Auto2717[0]=en_Auto2717;
	_Context->msg_Auto2717[1]=fr_Auto2717;
	_Context->msg_Auto2717[2]=it_Auto2717;
	_Context->msg_Auto2717[3]=es_Auto2717;
	_Context->msg_Auto2717[4]=de_Auto2717;
	_Context->msg_Auto2717[5]=nl_Auto2717;
	_Context->msg_Auto2717[6]=pt_Auto2717;
	_Context->msg_Auto2717[7]=xx_Auto2717;
	_Context->hint_Auto2717[0]=en__Auto2717;
	_Context->hint_Auto2717[1]=fr__Auto2717;
	_Context->hint_Auto2717[2]=it__Auto2717;
	_Context->hint_Auto2717[3]=es__Auto2717;
	_Context->hint_Auto2717[4]=de__Auto2717;
	_Context->hint_Auto2717[5]=nl__Auto2717;
	_Context->hint_Auto2717[6]=pt__Auto2717;
	_Context->hint_Auto2717[7]=xx__Auto2717;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto2714,_Context->y_Auto2714,480+10,160+10);
	return(0);
}

public 	int	accept_widget_style_hide(struct accept_widget_style_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto2714,_Context->y_Auto2714);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_widget_style_remove(
	struct accept_widget_style_context * _Context,
	char * pWidgetStyle)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"W");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pWidgetStyle);
		if ( pWidgetStyle != (char *) 0)
			*((int*)pWidgetStyle) = _Context->value_WidgetStyle;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_widget_style_show(struct accept_widget_style_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto2714,_Context->y_Auto2714);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto2714,_Context->y_Auto2714,480,160,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto2714,_Context->y_Auto2714,480,160,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto2714+50,_Context->y_Auto2714+40,378,16,vfh[2],16,22,_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]),259);
	visual_select(_Context->x_Auto2714+50,_Context->y_Auto2714+60,376,96,vfh[1],27,28,parse_selection(WidgetStyleList(),&_Context->value_WidgetStyle),0);
	_Context->trigger_Auto2716=visual_trigger_code(_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]));
	visual_button(_Context->x_Auto2714+50,_Context->y_Auto2714+100,56,48,vfh[2],34,0,_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]),1040);
	_Context->trigger_Auto2717=visual_trigger_code(_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]));
	visual_button(_Context->x_Auto2714+370,_Context->y_Auto2714+100,56,48,vfh[2],34,0,_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]),1040);
	visual_thaw(_Context->x_Auto2714,_Context->y_Auto2714,480,160);

	return(0);
}

private int WidgetStyle_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control presents the list of style classes loaded from the  style ";
			mptr[1]="sheet defined in the forms properties dialog box.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2716_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the ACCEPT button any changes made to the various    parameters ";
			mptr[1]="will take effect.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2717_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the CANCEL button any modifications performed will be ";
			mptr[1]="   discarded.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2714action(struct accept_widget_style_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_widget_style_hide(_Context);

		_Context->x_Auto2714 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto2714 < 0) { _Context->x_Auto2714=0; }
		_Context->y_Auto2714 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto2714 < 0) { _Context->y_Auto2714=0; }
			accept_widget_style_show(_Context);

		visual_thaw(_Context->x_Auto2714,_Context->y_Auto2714,480,160);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto2716_event(struct accept_widget_style_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto2717_event(struct accept_widget_style_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_widget_style_event(
struct accept_widget_style_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto2716 == mb ) return(3);
		if (_Context->trigger_Auto2717 == mb ) return(4);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto2714+459) )  
	&&  (my >= (_Context->y_Auto2714+4) )  
	&&  (mx <= (_Context->x_Auto2714+476) )  
	&&  (my <= (_Context->y_Auto2714+20) )) {
		return(1);	/* Auto2714 */

		}
	if ((mx >= (_Context->x_Auto2714+443) )  
	&&  (my >= (_Context->y_Auto2714+4) )  
	&&  (mx <= (_Context->x_Auto2714+460) )  
	&&  (my <= (_Context->y_Auto2714+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcss.htm");
			};
		return(-1);	/* Auto2714 */

		}
	if ((mx >= (_Context->x_Auto2714+427) )  
	&&  (my >= (_Context->y_Auto2714+4) )  
	&&  (mx <= (_Context->x_Auto2714+444) )  
	&&  (my <= (_Context->y_Auto2714+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_widget_style_show(_Context);
		return(-1);	/* Auto2714 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto2714+4) )  
		&&  (my >= (_Context->y_Auto2714+4) )  
		&&  (mx <= (_Context->x_Auto2714+412) )  
		&&  (my <= (_Context->y_Auto2714+20) )) {
			return( Auto2714action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto2714+50+0) ) 
	&&  ( my >= (_Context->y_Auto2714+60) ) 
	&&  ( mx <= (_Context->x_Auto2714+50+376) ) 
	&&  ( my <= (_Context->y_Auto2714+60+16))) {
		return(2); /* WidgetStyle */
		}
	if (( mx >= (_Context->x_Auto2714+50) ) 
	&&  ( my >= (_Context->y_Auto2714+100) ) 
	&&  ( mx <= (_Context->x_Auto2714+50+56) ) 
	&&  ( my <= (_Context->y_Auto2714+100+48))) {
		return(3); /* Auto2716 */
		}
	if (( mx >= (_Context->x_Auto2714+370) ) 
	&&  ( my >= (_Context->y_Auto2714+100) ) 
	&&  ( mx <= (_Context->x_Auto2714+370+56) ) 
	&&  ( my <= (_Context->y_Auto2714+100+48))) {
		return(4); /* Auto2717 */
		}

	return(-1);
}


public	int	accept_widget_style_focus(struct accept_widget_style_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* WidgetStyle */
				_Context->keycode = visual_select(_Context->x_Auto2714+50,_Context->y_Auto2714+60,376,96,vfh[1],27,28,parse_selection(WidgetStyleList(),&_Context->value_WidgetStyle),2);
				break;
			case	0x3 :
				/* Auto2716 */
				_Context->trigger_Auto2716=visual_trigger_code(_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]));
				visual_button(_Context->x_Auto2714+50,_Context->y_Auto2714+100,56,48,vfh[2],34,0,_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2716=visual_trigger_code(_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]));
	visual_button(_Context->x_Auto2714+50,_Context->y_Auto2714+100,56,48,vfh[2],34,0,_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]),1040);
				break;
			case	0x4 :
				/* Auto2717 */
				_Context->trigger_Auto2717=visual_trigger_code(_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]));
				visual_button(_Context->x_Auto2714+370,_Context->y_Auto2714+100,56,48,vfh[2],34,0,_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2717=visual_trigger_code(_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]));
	visual_button(_Context->x_Auto2714+370,_Context->y_Auto2714+100,56,48,vfh[2],34,0,_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_widget_style_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=4;
			accept_widget_style_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_widget_style_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (WidgetStyle_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Auto2716_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Auto2717_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto2714 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* WidgetStyle */
					continue;
				case	0x3 :
					/* Auto2716 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2716=visual_trigger_code(_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]));
						visual_button(_Context->x_Auto2714+50,_Context->y_Auto2714+100,56,48,vfh[2],34,0,_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2716=visual_trigger_code(_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]));
	visual_button(_Context->x_Auto2714+50,_Context->y_Auto2714+100,56,48,vfh[2],34,0,_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2716_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto2717 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2717=visual_trigger_code(_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]));
						visual_button(_Context->x_Auto2714+370,_Context->y_Auto2714+100,56,48,vfh[2],34,0,_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2717=visual_trigger_code(_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]));
	visual_button(_Context->x_Auto2714+370,_Context->y_Auto2714+100,56,48,vfh[2],34,0,_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2717_event(_Context)) != -1) break;

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

public	int	accept_widget_style(
	char * pWidgetStyle)
{
	int	status=0;
	struct accept_widget_style_context * _Context=(struct accept_widget_style_context*) 0;
	status = accept_widget_style_create(
	&_Context,
	 pWidgetStyle);
	if ( status != 0) return(status);
	status = accept_widget_style_show(_Context);
		enter_modal();
	status = accept_widget_style_focus(_Context);
		leave_modal();
	status = accept_widget_style_hide(_Context);
	status = accept_widget_style_remove(
	_Context,
	 pWidgetStyle);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcss_c */
