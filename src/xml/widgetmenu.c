
#ifndef _widgetmenu_c
#define _widgetmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : widgetmenu.xml                                           */
/* Target         : widgetmenu.c                                             */
/* Identification : 0.0-1197227120-30772.30771                               */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#include "singfmed.h"
#define en_Auto336   "Sing Version 2.1a"
#define fr_Auto336   "Sing Version 2.1a"
#define it_Auto336   "Sing Version 2.1a"
#define es_Auto336   "Sing Version 2.1a"
#define de_Auto336   "Sing Version 2.1a"
#define nl_Auto336   "Sing Version 2.1a"
#define pt_Auto336   "Sing Version 2.1a"
#define xx_Auto336   "Sing Version 2.1a"
#define en__Auto336   ""
#define fr__Auto336   ""
#define it__Auto336   ""
#define es__Auto336   ""
#define de__Auto336   ""
#define nl__Auto336   ""
#define pt__Auto336   ""
#define xx__Auto336   ""
#define en_Auto337   "&Inspect Widget Properties and Method"
#define fr_Auto337   "&PropriŠt‚s et Methodes du Widget"
#define it_Auto337   "&Inspect Widget Properties and Method"
#define es_Auto337   "&Inspect Widget Properties and Method"
#define de_Auto337   "&Inspect Widget Properties and Method"
#define nl_Auto337   "&Inspect Widget Properties and Method"
#define pt_Auto337   "&Inspect Widget Properties and Method"
#define xx_Auto337   "&Inspect Widget Properties and Method"
#define en__Auto337   ""
#define fr__Auto337   ""
#define it__Auto337   ""
#define es__Auto337   ""
#define de__Auto337   ""
#define nl__Auto337   ""
#define pt__Auto337   ""
#define xx__Auto337   ""
#define en_Auto338   "&Toggle Widget Method Detail"
#define fr_Auto338   "&Bascule d‚tail du Widget"
#define it_Auto338   "&Toggle Widget Method Detail"
#define es_Auto338   "&Toggle Widget Method Detail"
#define de_Auto338   "&Toggle Widget Method Detail"
#define nl_Auto338   "&Toggle Widget Method Detail"
#define pt_Auto338   "&Toggle Widget Method Detail"
#define xx_Auto338   "&Toggle Widget Method Detail"
#define en__Auto338   ""
#define fr__Auto338   ""
#define it__Auto338   ""
#define es__Auto338   ""
#define de__Auto338   ""
#define nl__Auto338   ""
#define pt__Auto338   ""
#define xx__Auto338   ""
#define en_Auto339   "T&oggle Widget Method Solo"
#define fr_Auto339   "B&ascule ‚tat Solo du Widget"
#define it_Auto339   "T&oggle Widget Method Solo"
#define es_Auto339   "T&oggle Widget Method Solo"
#define de_Auto339   "T&oggle Widget Method Solo"
#define nl_Auto339   "T&oggle Widget Method Solo"
#define pt_Auto339   "T&oggle Widget Method Solo"
#define xx_Auto339   "T&oggle Widget Method Solo"
#define en__Auto339   ""
#define fr__Auto339   ""
#define it__Auto339   ""
#define es__Auto339   ""
#define de__Auto339   ""
#define nl__Auto339   ""
#define pt__Auto339   ""
#define xx__Auto339   ""
#define en_Auto340   "&Calculate Best Positioning"
#define fr_Auto340   "&Recalculation positionnement a partir de formulaire"
#define it_Auto340   "&Calculate Best Positioning"
#define es_Auto340   "&Calculate Best Positioning"
#define de_Auto340   "&Calculate Best Positioning"
#define nl_Auto340   "&Calculate Best Positioning"
#define pt_Auto340   "&Calculate Best Positioning"
#define xx_Auto340   "&Calculate Best Positioning"
#define en__Auto340   ""
#define fr__Auto340   ""
#define it__Auto340   ""
#define es__Auto340   ""
#define de__Auto340   ""
#define nl__Auto340   ""
#define pt__Auto340   ""
#define xx__Auto340   ""

private struct flowchart_widget_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto336[8];
	char * hint_Auto336[8];
	int	s_Auto336;
	void *	p_Auto336;
	int	x_Auto336;
	int	y_Auto336;
	int	w_Auto336;
	int	h_Auto336;
	char * msg_Auto337[8];
	int	trigger_Auto337;
	char * hint_Auto337[8];
	char * msg_Auto338[8];
	int	trigger_Auto338;
	char * hint_Auto338[8];
	char * msg_Auto339[8];
	int	trigger_Auto339;
	char * hint_Auto339[8];
	char * msg_Auto340[8];
	int	trigger_Auto340;
	char * hint_Auto340[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct flowchart_widget_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = flowchart_widget_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}

private int on_Auto336_create(struct flowchart_widget_menu_context * _Context) {
	mouse_move_on();
	if(((_Context->y_Auto336=visual_event(6))+112)>hardrows())
	_Context->y_Auto336=(hardrows()-112);
	if(((_Context->x_Auto336=visual_event(7))+352)>hardcolumns())
	_Context->x_Auto336=(hardcolumns()-352);
	return(-1);
}

public	int	flowchart_widget_menu_create(struct flowchart_widget_menu_context **cptr)
{

	int i;
	struct flowchart_widget_menu_context * _Context=(struct flowchart_widget_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct flowchart_widget_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=4;
	for (i=0; i < 8; i++)_Context->msg_Auto336[i]=" ";
	_Context->msg_Auto336[0]=en_Auto336;
	_Context->msg_Auto336[1]=fr_Auto336;
	_Context->msg_Auto336[2]=it_Auto336;
	_Context->msg_Auto336[3]=es_Auto336;
	_Context->msg_Auto336[4]=de_Auto336;
	_Context->msg_Auto336[5]=nl_Auto336;
	_Context->msg_Auto336[6]=pt_Auto336;
	_Context->msg_Auto336[7]=xx_Auto336;
	_Context->hint_Auto336[0]=en__Auto336;
	_Context->hint_Auto336[1]=fr__Auto336;
	_Context->hint_Auto336[2]=it__Auto336;
	_Context->hint_Auto336[3]=es__Auto336;
	_Context->hint_Auto336[4]=de__Auto336;
	_Context->hint_Auto336[5]=nl__Auto336;
	_Context->hint_Auto336[6]=pt__Auto336;
	_Context->hint_Auto336[7]=xx__Auto336;
	_Context->s_Auto336=0;
	_Context->p_Auto336=visual_buffer(_Context->x_Auto336,_Context->y_Auto336,352+2,112+2);
	_Context->x_Auto336=40;
	_Context->y_Auto336=44;
	_Context->w_Auto336=352;
	_Context->h_Auto336=112;
	_Context->window_col=40;
	_Context->window_row=44;
	(void) on_Auto336_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Auto337[i]=" ";
	_Context->msg_Auto337[0]=en_Auto337;
	_Context->msg_Auto337[1]=fr_Auto337;
	_Context->msg_Auto337[2]=it_Auto337;
	_Context->msg_Auto337[3]=es_Auto337;
	_Context->msg_Auto337[4]=de_Auto337;
	_Context->msg_Auto337[5]=nl_Auto337;
	_Context->msg_Auto337[6]=pt_Auto337;
	_Context->msg_Auto337[7]=xx_Auto337;
	_Context->hint_Auto337[0]=en__Auto337;
	_Context->hint_Auto337[1]=fr__Auto337;
	_Context->hint_Auto337[2]=it__Auto337;
	_Context->hint_Auto337[3]=es__Auto337;
	_Context->hint_Auto337[4]=de__Auto337;
	_Context->hint_Auto337[5]=nl__Auto337;
	_Context->hint_Auto337[6]=pt__Auto337;
	_Context->hint_Auto337[7]=xx__Auto337;
	for (i=0; i < 8; i++)_Context->msg_Auto338[i]=" ";
	_Context->msg_Auto338[0]=en_Auto338;
	_Context->msg_Auto338[1]=fr_Auto338;
	_Context->msg_Auto338[2]=it_Auto338;
	_Context->msg_Auto338[3]=es_Auto338;
	_Context->msg_Auto338[4]=de_Auto338;
	_Context->msg_Auto338[5]=nl_Auto338;
	_Context->msg_Auto338[6]=pt_Auto338;
	_Context->msg_Auto338[7]=xx_Auto338;
	_Context->hint_Auto338[0]=en__Auto338;
	_Context->hint_Auto338[1]=fr__Auto338;
	_Context->hint_Auto338[2]=it__Auto338;
	_Context->hint_Auto338[3]=es__Auto338;
	_Context->hint_Auto338[4]=de__Auto338;
	_Context->hint_Auto338[5]=nl__Auto338;
	_Context->hint_Auto338[6]=pt__Auto338;
	_Context->hint_Auto338[7]=xx__Auto338;
	for (i=0; i < 8; i++)_Context->msg_Auto339[i]=" ";
	_Context->msg_Auto339[0]=en_Auto339;
	_Context->msg_Auto339[1]=fr_Auto339;
	_Context->msg_Auto339[2]=it_Auto339;
	_Context->msg_Auto339[3]=es_Auto339;
	_Context->msg_Auto339[4]=de_Auto339;
	_Context->msg_Auto339[5]=nl_Auto339;
	_Context->msg_Auto339[6]=pt_Auto339;
	_Context->msg_Auto339[7]=xx_Auto339;
	_Context->hint_Auto339[0]=en__Auto339;
	_Context->hint_Auto339[1]=fr__Auto339;
	_Context->hint_Auto339[2]=it__Auto339;
	_Context->hint_Auto339[3]=es__Auto339;
	_Context->hint_Auto339[4]=de__Auto339;
	_Context->hint_Auto339[5]=nl__Auto339;
	_Context->hint_Auto339[6]=pt__Auto339;
	_Context->hint_Auto339[7]=xx__Auto339;
	for (i=0; i < 8; i++)_Context->msg_Auto340[i]=" ";
	_Context->msg_Auto340[0]=en_Auto340;
	_Context->msg_Auto340[1]=fr_Auto340;
	_Context->msg_Auto340[2]=it_Auto340;
	_Context->msg_Auto340[3]=es_Auto340;
	_Context->msg_Auto340[4]=de_Auto340;
	_Context->msg_Auto340[5]=nl_Auto340;
	_Context->msg_Auto340[6]=pt_Auto340;
	_Context->msg_Auto340[7]=xx_Auto340;
	_Context->hint_Auto340[0]=en__Auto340;
	_Context->hint_Auto340[1]=fr__Auto340;
	_Context->hint_Auto340[2]=it__Auto340;
	_Context->hint_Auto340[3]=es__Auto340;
	_Context->hint_Auto340[4]=de__Auto340;
	_Context->hint_Auto340[5]=nl__Auto340;
	_Context->hint_Auto340[6]=pt__Auto340;
	_Context->hint_Auto340[7]=xx__Auto340;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto336,_Context->y_Auto336,352,112);
	return(0);
}

public 	int	flowchart_widget_menu_hide(struct flowchart_widget_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto336 != (void *) 0)
	&& (_Context->s_Auto336 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto336,_Context->x_Auto336,_Context->y_Auto336);
		_Context->s_Auto336=0;
		}
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto336,_Context->y_Auto336);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	flowchart_widget_menu_remove(struct flowchart_widget_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	mouse_move_off();
	if (_Context->p_Auto336 != (void *) 0)
		_Context->p_Auto336 = visual_drop(_Context->p_Auto336);
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	flowchart_widget_menu_show(struct flowchart_widget_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto336,_Context->y_Auto336);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if ((_Context->p_Auto336 != (void *) 0)
	&& (_Context->s_Auto336 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto336,_Context->x_Auto336,_Context->y_Auto336);
		_Context->s_Auto336=1;
		}
	if (((_Context->status = visual_styled_element(_Context->x_Auto336,_Context->y_Auto336,352,112,GetWidgetStyle(1),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
		visual_window(_Context->x_Auto336,_Context->y_Auto336,352,112,vfh[1],_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),0x4);
		}
	_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+12,304,20,GetWidgetStyle(2),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto336+16,_Context->y_Auto336+12,304,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),32);
		}
	_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+36,304,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto336+16,_Context->y_Auto336+36,304,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
		}
	_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+60,296,16,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto336+16,_Context->y_Auto336+60,296,16,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
		}
	_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+84,312,16,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto336+16,_Context->y_Auto336+84,312,16,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
		}
	visual_thaw(_Context->x_Auto336,_Context->y_Auto336,352,112);

	return(0);
}
private int on_Auto337_event(struct flowchart_widget_menu_context * _Context) {
	return(_FORM_PARA);
	return(-1);
}
private int on_Auto338_event(struct flowchart_widget_menu_context * _Context) {
	return(_FLOW_DETAIL);
	return(-1);
}
private int on_Auto339_event(struct flowchart_widget_menu_context * _Context) {
	return(_FLOW_SOLO);
	return(-1);
}
private int on_Auto340_event(struct flowchart_widget_menu_context * _Context) {
	return(_FLOW_BEST);
	return(-1);
}


public	int	flowchart_widget_menu_event(
struct flowchart_widget_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto337 == mb ) return(1);
		if (_Context->trigger_Auto338 == mb ) return(2);
		if (_Context->trigger_Auto339 == mb ) return(3);
		if (_Context->trigger_Auto340 == mb ) return(4);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_Auto336+16) ) 
	&&  ( my >= (_Context->y_Auto336+12) ) 
	&&  ( mx <= (_Context->x_Auto336+16+304) ) 
	&&  ( my <= (_Context->y_Auto336+12+20))) {
		return(1); /* Auto337 */
		}
	if (( mx >= (_Context->x_Auto336+16) ) 
	&&  ( my >= (_Context->y_Auto336+36) ) 
	&&  ( mx <= (_Context->x_Auto336+16+304) ) 
	&&  ( my <= (_Context->y_Auto336+36+20))) {
		return(2); /* Auto338 */
		}
	if (( mx >= (_Context->x_Auto336+16) ) 
	&&  ( my >= (_Context->y_Auto336+60) ) 
	&&  ( mx <= (_Context->x_Auto336+16+296) ) 
	&&  ( my <= (_Context->y_Auto336+60+16))) {
		return(3); /* Auto339 */
		}
	if (( mx >= (_Context->x_Auto336+16) ) 
	&&  ( my >= (_Context->y_Auto336+84) ) 
	&&  ( mx <= (_Context->x_Auto336+16+312) ) 
	&&  ( my <= (_Context->y_Auto336+84+16))) {
		return(4); /* Auto340 */
		}

	return(-1);
}


public	int	flowchart_widget_menu_focus(struct flowchart_widget_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto337 */
				_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+12,304,20,GetWidgetStyle(3),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto336+16,_Context->y_Auto336+12,304,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+12,304,20,GetWidgetStyle(2),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto336+16,_Context->y_Auto336+12,304,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto338 */
				_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+36,304,20,GetWidgetStyle(3),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto336+16,_Context->y_Auto336+36,304,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+36,304,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto336+16,_Context->y_Auto336+36,304,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto339 */
				_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+60,296,16,GetWidgetStyle(3),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto336+16,_Context->y_Auto336+60,296,16,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+60,296,16,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto336+16,_Context->y_Auto336+60,296,16,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto340 */
				_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+84,312,16,GetWidgetStyle(3),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto336+16,_Context->y_Auto336+84,312,16,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+84,312,16,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto336+16,_Context->y_Auto336+84,312,16,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			flowchart_widget_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=4;
			flowchart_widget_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  _Context->x_Auto336 )
				|| ( visual_event(6) < _Context->y_Auto336  )
				|| ( visual_event(7) > (_Context->x_Auto336+_Context->w_Auto336))
				|| ( visual_event(6) >  (_Context->y_Auto336+_Context->h_Auto336))) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=flowchart_widget_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto337 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+12,304,20,GetWidgetStyle(3),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto336+16,_Context->y_Auto336+12,304,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+12,304,20,GetWidgetStyle(2),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto336+16,_Context->y_Auto336+12,304,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto337_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto338 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+36,304,20,GetWidgetStyle(3),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto336+16,_Context->y_Auto336+36,304,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+36,304,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto336+16,_Context->y_Auto336+36,304,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto338_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto339 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+60,296,16,GetWidgetStyle(3),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto336+16,_Context->y_Auto336+60,296,16,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+60,296,16,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto336+16,_Context->y_Auto336+60,296,16,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto339_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto340 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+84,312,16,GetWidgetStyle(3),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto336+16,_Context->y_Auto336+84,312,16,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto336+16,_Context->y_Auto336+84,312,16,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto336+16,_Context->y_Auto336+84,312,16,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto340_event(_Context)) != -1) break;

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
		case	0x0 :
			
			continue;
		case	0xffffffff :
			
			continue;

			}
		break;
		}

	return( _Context->keycode );
}

public	int	flowchart_widget_menu()
{
	int	status=0;
	struct flowchart_widget_menu_context * _Context=(struct flowchart_widget_menu_context*) 0;
	status = flowchart_widget_menu_create(&_Context);
	if ( status != 0) return(status);
	status = flowchart_widget_menu_show(_Context);
		enter_modal();
	status = flowchart_widget_menu_focus(_Context);
		leave_modal();
	status = flowchart_widget_menu_hide(_Context);
	status = flowchart_widget_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _widgetmenu_c */
