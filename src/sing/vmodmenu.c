
#ifndef _vmodmenu_c
#define _vmodmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : vmodmenu.xml                                             */
/* Target         : vmodmenu.c                                               */
/* Identification : 0.0-1196372205-2906.2905                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Auto317   "Sing Version 2.1a"
#define fr_Auto317   "Sing Version 2.1a"
#define it_Auto317   "Sing Version 2.1a"
#define es_Auto317   "Sing Version 2.1a"
#define de_Auto317   "Sing Version 2.1a"
#define nl_Auto317   "Sing Version 2.1a"
#define pt_Auto317   "Sing Version 2.1a"
#define xx_Auto317   "Sing Version 2.1a"
#define en__Auto317   ""
#define fr__Auto317   ""
#define it__Auto317   ""
#define es__Auto317   ""
#define de__Auto317   ""
#define nl__Auto317   ""
#define pt__Auto317   ""
#define xx__Auto317   ""
#define en_Auto318   "&Database Model"
#define fr_Auto318   "&ModŠle de base de donn‚es"
#define it_Auto318   "&Database Model"
#define es_Auto318   "&Database Model"
#define de_Auto318   "&Database Model"
#define nl_Auto318   "&Database Model"
#define pt_Auto318   "&Database Model"
#define xx_Auto318   "&Database Model"
#define en__Auto318   ""
#define fr__Auto318   ""
#define it__Auto318   ""
#define es__Auto318   ""
#define de__Auto318   ""
#define nl__Auto318   ""
#define pt__Auto318   ""
#define xx__Auto318   ""
#define en_Auto319   "&Flow chart"
#define fr_Auto319   "&Flux des Formulaires"
#define it_Auto319   "&Flow chart"
#define es_Auto319   "&Flow chart"
#define de_Auto319   "&Flow chart"
#define nl_Auto319   "&Flow chart"
#define pt_Auto319   "&Flow chart"
#define xx_Auto319   "&Flow chart"
#define en__Auto319   ""
#define fr__Auto319   ""
#define it__Auto319   ""
#define es__Auto319   ""
#define de__Auto319   ""
#define nl__Auto319   ""
#define pt__Auto319   ""
#define xx__Auto319   ""
#define en_Auto320   "&Style Dependance Graph"
#define fr_Auto320   "&Graphe de d‚pendance des styles"
#define it_Auto320   "&Style Dependance"
#define es_Auto320   "&Style Dependance"
#define de_Auto320   "&Style Dependance"
#define nl_Auto320   "&Style Dependance"
#define pt_Auto320   "&Style Dependance"
#define xx_Auto320   "&Style Dependance"
#define en__Auto320   ""
#define fr__Auto320   ""
#define it__Auto320   ""
#define es__Auto320   ""
#define de__Auto320   ""
#define nl__Auto320   ""
#define pt__Auto320   ""
#define xx__Auto320   ""

private struct view_model_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto317[8];
	char * hint_Auto317[8];
	int	s_Auto317;
	void *	p_Auto317;
	int	x_Auto317;
	int	y_Auto317;
	int	w_Auto317;
	int	h_Auto317;
	char * msg_Auto318[8];
	int	trigger_Auto318;
	char * hint_Auto318[8];
	char * msg_Auto319[8];
	int	trigger_Auto319;
	char * hint_Auto319[8];
	char * msg_Auto320[8];
	int	trigger_Auto320;
	char * hint_Auto320[8];
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct view_model_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = view_model_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}

private int on_Auto317_create(struct view_model_menu_context * _Context) {
	mouse_move_on();
	return(-1);
}

public	int	view_model_menu_create(struct view_model_menu_context **cptr)
{

	int i;
	struct view_model_menu_context * _Context=(struct view_model_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct view_model_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=3;
	for (i=0; i < 8; i++)_Context->msg_Auto317[i]=" ";
	_Context->msg_Auto317[0]=en_Auto317;
	_Context->msg_Auto317[1]=fr_Auto317;
	_Context->msg_Auto317[2]=it_Auto317;
	_Context->msg_Auto317[3]=es_Auto317;
	_Context->msg_Auto317[4]=de_Auto317;
	_Context->msg_Auto317[5]=nl_Auto317;
	_Context->msg_Auto317[6]=pt_Auto317;
	_Context->msg_Auto317[7]=xx_Auto317;
	_Context->hint_Auto317[0]=en__Auto317;
	_Context->hint_Auto317[1]=fr__Auto317;
	_Context->hint_Auto317[2]=it__Auto317;
	_Context->hint_Auto317[3]=es__Auto317;
	_Context->hint_Auto317[4]=de__Auto317;
	_Context->hint_Auto317[5]=nl__Auto317;
	_Context->hint_Auto317[6]=pt__Auto317;
	_Context->hint_Auto317[7]=xx__Auto317;
	_Context->s_Auto317=0;
	_Context->p_Auto317=visual_buffer(280,210,230+2,80+2);
	_Context->x_Auto317=280;
	_Context->y_Auto317=210;
	_Context->w_Auto317=230;
	_Context->h_Auto317=80;
	_Context->window_col=280;
	_Context->window_row=210;
	(void) on_Auto317_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Auto318[i]=" ";
	_Context->msg_Auto318[0]=en_Auto318;
	_Context->msg_Auto318[1]=fr_Auto318;
	_Context->msg_Auto318[2]=it_Auto318;
	_Context->msg_Auto318[3]=es_Auto318;
	_Context->msg_Auto318[4]=de_Auto318;
	_Context->msg_Auto318[5]=nl_Auto318;
	_Context->msg_Auto318[6]=pt_Auto318;
	_Context->msg_Auto318[7]=xx_Auto318;
	_Context->hint_Auto318[0]=en__Auto318;
	_Context->hint_Auto318[1]=fr__Auto318;
	_Context->hint_Auto318[2]=it__Auto318;
	_Context->hint_Auto318[3]=es__Auto318;
	_Context->hint_Auto318[4]=de__Auto318;
	_Context->hint_Auto318[5]=nl__Auto318;
	_Context->hint_Auto318[6]=pt__Auto318;
	_Context->hint_Auto318[7]=xx__Auto318;
	for (i=0; i < 8; i++)_Context->msg_Auto319[i]=" ";
	_Context->msg_Auto319[0]=en_Auto319;
	_Context->msg_Auto319[1]=fr_Auto319;
	_Context->msg_Auto319[2]=it_Auto319;
	_Context->msg_Auto319[3]=es_Auto319;
	_Context->msg_Auto319[4]=de_Auto319;
	_Context->msg_Auto319[5]=nl_Auto319;
	_Context->msg_Auto319[6]=pt_Auto319;
	_Context->msg_Auto319[7]=xx_Auto319;
	_Context->hint_Auto319[0]=en__Auto319;
	_Context->hint_Auto319[1]=fr__Auto319;
	_Context->hint_Auto319[2]=it__Auto319;
	_Context->hint_Auto319[3]=es__Auto319;
	_Context->hint_Auto319[4]=de__Auto319;
	_Context->hint_Auto319[5]=nl__Auto319;
	_Context->hint_Auto319[6]=pt__Auto319;
	_Context->hint_Auto319[7]=xx__Auto319;
	for (i=0; i < 8; i++)_Context->msg_Auto320[i]=" ";
	_Context->msg_Auto320[0]=en_Auto320;
	_Context->msg_Auto320[1]=fr_Auto320;
	_Context->msg_Auto320[2]=it_Auto320;
	_Context->msg_Auto320[3]=es_Auto320;
	_Context->msg_Auto320[4]=de_Auto320;
	_Context->msg_Auto320[5]=nl_Auto320;
	_Context->msg_Auto320[6]=pt_Auto320;
	_Context->msg_Auto320[7]=xx_Auto320;
	_Context->hint_Auto320[0]=en__Auto320;
	_Context->hint_Auto320[1]=fr__Auto320;
	_Context->hint_Auto320[2]=it__Auto320;
	_Context->hint_Auto320[3]=es__Auto320;
	_Context->hint_Auto320[4]=de__Auto320;
	_Context->hint_Auto320[5]=nl__Auto320;
	_Context->hint_Auto320[6]=pt__Auto320;
	_Context->hint_Auto320[7]=xx__Auto320;
	return(0);
}

public 	int	view_model_menu_hide(struct view_model_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto317 != (void *) 0)
	&& (_Context->s_Auto317 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto317,280,210);
		_Context->s_Auto317=0;
		}

	return(result);
}

public	int	view_model_menu_remove(struct view_model_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	mouse_move_off();
	if (_Context->p_Auto317 != (void *) 0)
		_Context->p_Auto317 = visual_drop(_Context->p_Auto317);
	_Context=liberate(_Context);

	return(result);
}

public	int	view_model_menu_show(struct view_model_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if ((_Context->p_Auto317 != (void *) 0)
	&& (_Context->s_Auto317 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto317,280,210);
		_Context->s_Auto317=1;
		}
	if (((_Context->status = visual_styled_element(280,210,230,80,GetWidgetStyle(1),_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]))) != 0)
) {
		visual_window(280,210,230,80,vfh[1],_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]),0x4);
		}
	_Context->trigger_Auto318=visual_trigger_code(_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]));
	if (((_Context->status = visual_styled_element(290,220,210,16,GetWidgetStyle(2),_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]))) != 0)
) {
	visual_button(290,220,210,16,vfh[2],16,0,_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]),32);
		}
	_Context->trigger_Auto319=visual_trigger_code(_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]));
	if (((_Context->status = visual_styled_element(290,240,210,16,GetWidgetStyle(2),_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]))) != 0)
) {
	visual_button(290,240,210,16,vfh[2],16,0,_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]),32);
		}
	_Context->trigger_Auto320=visual_trigger_code(_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]));
	if (((_Context->status = visual_styled_element(290,260,200,16,GetWidgetStyle(2),_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]))) != 0)
) {
	visual_button(290,260,200,16,vfh[2],16,0,_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]),32);
		}
	visual_thaw(280,210,230,80);

	return(0);
}
private int on_Auto318_event(struct view_model_menu_context * _Context) {
	return(_EDIT_DATAMODEL);
	return(-1);
}
private int on_Auto319_event(struct view_model_menu_context * _Context) {
	return(_EDIT_FLOWCHART);
	return(-1);
}
private int on_Auto320_event(struct view_model_menu_context * _Context) {
	return(_EDIT_DEPEND);
	return(-1);
}


public	int	view_model_menu_event(
struct view_model_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto318 == mb ) return(1);
		if (_Context->trigger_Auto319 == mb ) return(2);
		if (_Context->trigger_Auto320 == mb ) return(3);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 290 ) 
	&&  ( my >= 220 ) 
	&&  ( mx <= 500 ) 
	&&  ( my <= 236 )) {
		return(1); /* Auto318 */
		}
	if (( mx >= 290 ) 
	&&  ( my >= 240 ) 
	&&  ( mx <= 500 ) 
	&&  ( my <= 256 )) {
		return(2); /* Auto319 */
		}
	if (( mx >= 290 ) 
	&&  ( my >= 260 ) 
	&&  ( mx <= 490 ) 
	&&  ( my <= 276 )) {
		return(3); /* Auto320 */
		}

	return(-1);
}


public	int	view_model_menu_focus(struct view_model_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto318 */
				_Context->trigger_Auto318=visual_trigger_code(_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]));
				if (((_Context->status = visual_styled_element(290,220,210,16,GetWidgetStyle(3),_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]))) != 0)
) {
					visual_button(290,220,210,16,vfh[2],16,0,_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto318=visual_trigger_code(_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]));
				if (((_Context->status = visual_styled_element(290,220,210,16,GetWidgetStyle(2),_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]))) != 0)
) {
	visual_button(290,220,210,16,vfh[2],16,0,_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto319 */
				_Context->trigger_Auto319=visual_trigger_code(_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]));
				if (((_Context->status = visual_styled_element(290,240,210,16,GetWidgetStyle(3),_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]))) != 0)
) {
					visual_button(290,240,210,16,vfh[2],16,0,_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto319=visual_trigger_code(_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]));
				if (((_Context->status = visual_styled_element(290,240,210,16,GetWidgetStyle(2),_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]))) != 0)
) {
	visual_button(290,240,210,16,vfh[2],16,0,_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto320 */
				_Context->trigger_Auto320=visual_trigger_code(_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]));
				if (((_Context->status = visual_styled_element(290,260,200,16,GetWidgetStyle(3),_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]))) != 0)
) {
					visual_button(290,260,200,16,vfh[2],16,0,_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto320=visual_trigger_code(_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]));
				if (((_Context->status = visual_styled_element(290,260,200,16,GetWidgetStyle(2),_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]))) != 0)
) {
	visual_button(290,260,200,16,vfh[2],16,0,_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			view_model_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=3;
			view_model_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  280 )
				|| ( visual_event(6) <  210 )
				|| ( visual_event(7) >  510 )
				|| ( visual_event(6) >  290 )) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=view_model_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto318 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto318=visual_trigger_code(_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]));
						if (((_Context->status = visual_styled_element(290,220,210,16,GetWidgetStyle(3),_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]))) != 0)
) {
							visual_button(290,220,210,16,vfh[2],16,0,_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto318=visual_trigger_code(_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]));
						if (((_Context->status = visual_styled_element(290,220,210,16,GetWidgetStyle(2),_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]))) != 0)
) {
	visual_button(290,220,210,16,vfh[2],16,0,_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto318_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto319 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto319=visual_trigger_code(_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]));
						if (((_Context->status = visual_styled_element(290,240,210,16,GetWidgetStyle(3),_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]))) != 0)
) {
							visual_button(290,240,210,16,vfh[2],16,0,_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto319=visual_trigger_code(_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]));
						if (((_Context->status = visual_styled_element(290,240,210,16,GetWidgetStyle(2),_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]))) != 0)
) {
	visual_button(290,240,210,16,vfh[2],16,0,_Context->msg_Auto319[_Context->language],strlen(_Context->msg_Auto319[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto319_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto320 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto320=visual_trigger_code(_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]));
						if (((_Context->status = visual_styled_element(290,260,200,16,GetWidgetStyle(3),_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]))) != 0)
) {
							visual_button(290,260,200,16,vfh[2],16,0,_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto320=visual_trigger_code(_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]));
						if (((_Context->status = visual_styled_element(290,260,200,16,GetWidgetStyle(2),_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]))) != 0)
) {
	visual_button(290,260,200,16,vfh[2],16,0,_Context->msg_Auto320[_Context->language],strlen(_Context->msg_Auto320[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto320_event(_Context)) != -1) break;

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
		case	0x0 :
			
			continue;
		case	0xffffffff :
			
			continue;

			}
		break;
		}

	return( _Context->keycode );
}

public	int	view_model_menu()
{
	int	status=0;
	struct view_model_menu_context * _Context=(struct view_model_menu_context*) 0;
	status = view_model_menu_create(&_Context);
	if ( status != 0) return(status);
	status = view_model_menu_show(_Context);
		enter_modal();
	status = view_model_menu_focus(_Context);
		leave_modal();
	status = view_model_menu_hide(_Context);
	status = view_model_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vmodmenu_c */
