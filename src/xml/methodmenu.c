
#ifndef _methodmenu_c
#define _methodmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : methodmenu.xml                                           */
/* Target         : methodmenu.c                                             */
/* Identification : 0.0-1197227250-30772.30771                               */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#include "singfmed.h"
#define en_Auto339   "Sing Version 2.1a"
#define fr_Auto339   "Sing Version 2.1a"
#define it_Auto339   "Sing Version 2.1a"
#define es_Auto339   "Sing Version 2.1a"
#define de_Auto339   "Sing Version 2.1a"
#define nl_Auto339   "Sing Version 2.1a"
#define pt_Auto339   "Sing Version 2.1a"
#define xx_Auto339   "Sing Version 2.1a"
#define en__Auto339   ""
#define fr__Auto339   ""
#define it__Auto339   ""
#define es__Auto339   ""
#define de__Auto339   ""
#define nl__Auto339   ""
#define pt__Auto339   ""
#define xx__Auto339   ""
#define en_Auto340   "&Inspect Forms Method"
#define fr_Auto340   "&Methode de Formulaire"
#define it_Auto340   "&Inspect Forms Method"
#define es_Auto340   "&Inspect Forms Method"
#define de_Auto340   "&Inspect Forms Method"
#define nl_Auto340   "&Inspect Forms Method"
#define pt_Auto340   "&Inspect Forms Method"
#define xx_Auto340   "&Inspect Forms Method"
#define en__Auto340   ""
#define fr__Auto340   ""
#define it__Auto340   ""
#define es__Auto340   ""
#define de__Auto340   ""
#define nl__Auto340   ""
#define pt__Auto340   ""
#define xx__Auto340   ""
#define en_Auto341   "&Toggle Forms Method Detail"
#define fr_Auto341   "&Bascule �tat D�tail du Widget"
#define it_Auto341   "&Toggle Forms Method Detail"
#define es_Auto341   "&Toggle Forms Method Detail"
#define de_Auto341   "&Toggle Forms Method Detail"
#define nl_Auto341   "&Toggle Forms Method Detail"
#define pt_Auto341   "&Toggle Forms Method Detail"
#define xx_Auto341   "&Toggle Forms Method Detail"
#define en__Auto341   ""
#define fr__Auto341   ""
#define it__Auto341   ""
#define es__Auto341   ""
#define de__Auto341   ""
#define nl__Auto341   ""
#define pt__Auto341   ""
#define xx__Auto341   ""
#define en_Auto342   "T&oggle Forms Method Solo"
#define fr_Auto342   "B&ascule �tat Solo du Widget"
#define it_Auto342   "T&oggle Forms Method Solo"
#define es_Auto342   "T&oggle Forms Method Solo"
#define de_Auto342   "T&oggle Forms Method Solo"
#define nl_Auto342   "T&oggle Forms Method Solo"
#define pt_Auto342   "T&oggle Forms Method Solo"
#define xx_Auto342   "T&oggle Forms Method Solo"
#define en__Auto342   ""
#define fr__Auto342   ""
#define it__Auto342   ""
#define es__Auto342   ""
#define de__Auto342   ""
#define nl__Auto342   ""
#define pt__Auto342   ""
#define xx__Auto342   ""
#define en_Auto343   "&Calculate Best Positioning"
#define fr_Auto343   "&Recalculation positionnement a partir de formulaire"
#define it_Auto343   "&Calculate Best Positioning"
#define es_Auto343   "&Calculate Best Positioning"
#define de_Auto343   "&Calculate Best Positioning"
#define nl_Auto343   "&Calculate Best Positioning"
#define pt_Auto343   "&Calculate Best Positioning"
#define xx_Auto343   "&Calculate Best Positioning"
#define en__Auto343   ""
#define fr__Auto343   ""
#define it__Auto343   ""
#define es__Auto343   ""
#define de__Auto343   ""
#define nl__Auto343   ""
#define pt__Auto343   ""
#define xx__Auto343   ""

private struct flowchart_method_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto339[8];
	char * hint_Auto339[8];
	int	s_Auto339;
	void *	p_Auto339;
	int	x_Auto339;
	int	y_Auto339;
	int	w_Auto339;
	int	h_Auto339;
	char * msg_Auto340[8];
	int	trigger_Auto340;
	char * hint_Auto340[8];
	char * msg_Auto341[8];
	int	trigger_Auto341;
	char * hint_Auto341[8];
	char * msg_Auto342[8];
	int	trigger_Auto342;
	char * hint_Auto342[8];
	char * msg_Auto343[8];
	int	trigger_Auto343;
	char * hint_Auto343[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct flowchart_method_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = flowchart_method_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}

private int on_Auto339_create(struct flowchart_method_menu_context * _Context) {
	mouse_move_on();
	if(((_Context->y_Auto339=visual_event(6))+112)>hardrows())
	_Context->y_Auto339=(hardrows()-112);
	if(((_Context->x_Auto339=visual_event(7))+344)>hardcolumns())
	_Context->x_Auto339=(hardcolumns()-344);
	return(-1);
}

public	int	flowchart_method_menu_create(struct flowchart_method_menu_context **cptr)
{

	int i;
	struct flowchart_method_menu_context * _Context=(struct flowchart_method_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct flowchart_method_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=4;
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
	_Context->s_Auto339=0;
	_Context->p_Auto339=visual_buffer(_Context->x_Auto339,_Context->y_Auto339,344+2,112+2);
	_Context->x_Auto339=40;
	_Context->y_Auto339=44;
	_Context->w_Auto339=344;
	_Context->h_Auto339=112;
	_Context->window_col=40;
	_Context->window_row=44;
	(void) on_Auto339_create(_Context);
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
	for (i=0; i < 8; i++)_Context->msg_Auto341[i]=" ";
	_Context->msg_Auto341[0]=en_Auto341;
	_Context->msg_Auto341[1]=fr_Auto341;
	_Context->msg_Auto341[2]=it_Auto341;
	_Context->msg_Auto341[3]=es_Auto341;
	_Context->msg_Auto341[4]=de_Auto341;
	_Context->msg_Auto341[5]=nl_Auto341;
	_Context->msg_Auto341[6]=pt_Auto341;
	_Context->msg_Auto341[7]=xx_Auto341;
	_Context->hint_Auto341[0]=en__Auto341;
	_Context->hint_Auto341[1]=fr__Auto341;
	_Context->hint_Auto341[2]=it__Auto341;
	_Context->hint_Auto341[3]=es__Auto341;
	_Context->hint_Auto341[4]=de__Auto341;
	_Context->hint_Auto341[5]=nl__Auto341;
	_Context->hint_Auto341[6]=pt__Auto341;
	_Context->hint_Auto341[7]=xx__Auto341;
	for (i=0; i < 8; i++)_Context->msg_Auto342[i]=" ";
	_Context->msg_Auto342[0]=en_Auto342;
	_Context->msg_Auto342[1]=fr_Auto342;
	_Context->msg_Auto342[2]=it_Auto342;
	_Context->msg_Auto342[3]=es_Auto342;
	_Context->msg_Auto342[4]=de_Auto342;
	_Context->msg_Auto342[5]=nl_Auto342;
	_Context->msg_Auto342[6]=pt_Auto342;
	_Context->msg_Auto342[7]=xx_Auto342;
	_Context->hint_Auto342[0]=en__Auto342;
	_Context->hint_Auto342[1]=fr__Auto342;
	_Context->hint_Auto342[2]=it__Auto342;
	_Context->hint_Auto342[3]=es__Auto342;
	_Context->hint_Auto342[4]=de__Auto342;
	_Context->hint_Auto342[5]=nl__Auto342;
	_Context->hint_Auto342[6]=pt__Auto342;
	_Context->hint_Auto342[7]=xx__Auto342;
	for (i=0; i < 8; i++)_Context->msg_Auto343[i]=" ";
	_Context->msg_Auto343[0]=en_Auto343;
	_Context->msg_Auto343[1]=fr_Auto343;
	_Context->msg_Auto343[2]=it_Auto343;
	_Context->msg_Auto343[3]=es_Auto343;
	_Context->msg_Auto343[4]=de_Auto343;
	_Context->msg_Auto343[5]=nl_Auto343;
	_Context->msg_Auto343[6]=pt_Auto343;
	_Context->msg_Auto343[7]=xx_Auto343;
	_Context->hint_Auto343[0]=en__Auto343;
	_Context->hint_Auto343[1]=fr__Auto343;
	_Context->hint_Auto343[2]=it__Auto343;
	_Context->hint_Auto343[3]=es__Auto343;
	_Context->hint_Auto343[4]=de__Auto343;
	_Context->hint_Auto343[5]=nl__Auto343;
	_Context->hint_Auto343[6]=pt__Auto343;
	_Context->hint_Auto343[7]=xx__Auto343;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto339,_Context->y_Auto339,344,112);
	return(0);
}

public 	int	flowchart_method_menu_hide(struct flowchart_method_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto339 != (void *) 0)
	&& (_Context->s_Auto339 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto339,_Context->x_Auto339,_Context->y_Auto339);
		_Context->s_Auto339=0;
		}
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto339,_Context->y_Auto339);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	flowchart_method_menu_remove(struct flowchart_method_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	mouse_move_off();
	if (_Context->p_Auto339 != (void *) 0)
		_Context->p_Auto339 = visual_drop(_Context->p_Auto339);
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	flowchart_method_menu_show(struct flowchart_method_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto339,_Context->y_Auto339);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if ((_Context->p_Auto339 != (void *) 0)
	&& (_Context->s_Auto339 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto339,_Context->x_Auto339,_Context->y_Auto339);
		_Context->s_Auto339=1;
		}
	if (((_Context->status = visual_styled_element(_Context->x_Auto339,_Context->y_Auto339,344,112,GetWidgetStyle(1),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
		visual_window(_Context->x_Auto339,_Context->y_Auto339,344,112,vfh[1],_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),0x4);
		}
	_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+12,312,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+12,312,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
		}
	_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+36,312,16,GetWidgetStyle(2),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+36,312,16,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),32);
		}
	_Context->trigger_Auto342=visual_trigger_code(_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+60,312,16,GetWidgetStyle(2),_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+60,312,16,vfh[2],16,0,_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]),32);
		}
	_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+84,320,20,GetWidgetStyle(2),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+84,320,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),32);
		}
	visual_thaw(_Context->x_Auto339,_Context->y_Auto339,344,112);

	return(0);
}
private int on_Auto340_event(struct flowchart_method_menu_context * _Context) {
	return(_FORM_PARA);
	return(-1);
}
private int on_Auto341_event(struct flowchart_method_menu_context * _Context) {
	return(_FLOW_DETAIL);
	return(-1);
}
private int on_Auto342_event(struct flowchart_method_menu_context * _Context) {
	return(_FLOW_SOLO);
	return(-1);
}
private int on_Auto343_event(struct flowchart_method_menu_context * _Context) {
	return(_FLOW_BEST);
	return(-1);
}


public	int	flowchart_method_menu_event(
struct flowchart_method_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto340 == mb ) return(1);
		if (_Context->trigger_Auto341 == mb ) return(2);
		if (_Context->trigger_Auto342 == mb ) return(3);
		if (_Context->trigger_Auto343 == mb ) return(4);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_Auto339+16) ) 
	&&  ( my >= (_Context->y_Auto339+12) ) 
	&&  ( mx <= (_Context->x_Auto339+16+312) ) 
	&&  ( my <= (_Context->y_Auto339+12+20))) {
		return(1); /* Auto340 */
		}
	if (( mx >= (_Context->x_Auto339+16) ) 
	&&  ( my >= (_Context->y_Auto339+36) ) 
	&&  ( mx <= (_Context->x_Auto339+16+312) ) 
	&&  ( my <= (_Context->y_Auto339+36+16))) {
		return(2); /* Auto341 */
		}
	if (( mx >= (_Context->x_Auto339+16) ) 
	&&  ( my >= (_Context->y_Auto339+60) ) 
	&&  ( mx <= (_Context->x_Auto339+16+312) ) 
	&&  ( my <= (_Context->y_Auto339+60+16))) {
		return(3); /* Auto342 */
		}
	if (( mx >= (_Context->x_Auto339+16) ) 
	&&  ( my >= (_Context->y_Auto339+84) ) 
	&&  ( mx <= (_Context->x_Auto339+16+320) ) 
	&&  ( my <= (_Context->y_Auto339+84+20))) {
		return(4); /* Auto343 */
		}

	return(-1);
}


public	int	flowchart_method_menu_focus(struct flowchart_method_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto340 */
				_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+12,312,20,GetWidgetStyle(3),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto339+16,_Context->y_Auto339+12,312,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+12,312,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+12,312,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto341 */
				_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+36,312,16,GetWidgetStyle(3),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto339+16,_Context->y_Auto339+36,312,16,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+36,312,16,GetWidgetStyle(2),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+36,312,16,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto342 */
				_Context->trigger_Auto342=visual_trigger_code(_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+60,312,16,GetWidgetStyle(3),_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto339+16,_Context->y_Auto339+60,312,16,vfh[2],16,0,_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto342=visual_trigger_code(_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+60,312,16,GetWidgetStyle(2),_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+60,312,16,vfh[2],16,0,_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto343 */
				_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+84,320,20,GetWidgetStyle(3),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto339+16,_Context->y_Auto339+84,320,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+84,320,20,GetWidgetStyle(2),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+84,320,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			flowchart_method_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=4;
			flowchart_method_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  _Context->x_Auto339 )
				|| ( visual_event(6) < _Context->y_Auto339  )
				|| ( visual_event(7) > (_Context->x_Auto339+_Context->w_Auto339))
				|| ( visual_event(6) >  (_Context->y_Auto339+_Context->h_Auto339))) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=flowchart_method_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto340 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+12,312,20,GetWidgetStyle(3),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto339+16,_Context->y_Auto339+12,312,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+12,312,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+12,312,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto340_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto341 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+36,312,16,GetWidgetStyle(3),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto339+16,_Context->y_Auto339+36,312,16,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+36,312,16,GetWidgetStyle(2),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+36,312,16,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto341_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto342 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto342=visual_trigger_code(_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+60,312,16,GetWidgetStyle(3),_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto339+16,_Context->y_Auto339+60,312,16,vfh[2],16,0,_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto342=visual_trigger_code(_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+60,312,16,GetWidgetStyle(2),_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+60,312,16,vfh[2],16,0,_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto342_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto343 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+84,320,20,GetWidgetStyle(3),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto339+16,_Context->y_Auto339+84,320,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto339+16,_Context->y_Auto339+84,320,20,GetWidgetStyle(2),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto339+16,_Context->y_Auto339+84,320,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto343_event(_Context)) != -1) break;

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

public	int	flowchart_method_menu()
{
	int	status=0;
	struct flowchart_method_menu_context * _Context=(struct flowchart_method_menu_context*) 0;
	status = flowchart_method_menu_create(&_Context);
	if ( status != 0) return(status);
	status = flowchart_method_menu_show(_Context);
		enter_modal();
	status = flowchart_method_menu_focus(_Context);
		leave_modal();
	status = flowchart_method_menu_hide(_Context);
	status = flowchart_method_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _methodmenu_c */
