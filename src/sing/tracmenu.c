
#ifndef _tracmenu_c
#define _tracmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : tracmenu.xml                                             */
/* Target         : tracmenu.c                                               */
/* Identification : 0.0-1195828012-3053.3052                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singtrac.h"
#include "singmenu.h"
#define en_Auto288   ""
#define en__Auto288   ""
#define en_Auto289   "&First"
#define fr_Auto289   "&Premier"
#define it_Auto289   "&First"
#define es_Auto289   "&First"
#define de_Auto289   "&First"
#define nl_Auto289   "&First"
#define pt_Auto289   "&First"
#define xx_Auto289   "&First"
#define en__Auto289   ""
#define fr__Auto289   ""
#define it__Auto289   ""
#define es__Auto289   ""
#define de__Auto289   ""
#define nl__Auto289   ""
#define pt__Auto289   ""
#define xx__Auto289   ""
#define en_Auto290   "&Previous"
#define fr_Auto290   "Pr‚&cŠdent"
#define it_Auto290   "&Previous"
#define es_Auto290   "&Previous"
#define de_Auto290   "&Previous"
#define nl_Auto290   "&Previous"
#define pt_Auto290   "&Previous"
#define xx_Auto290   "&Previous"
#define en__Auto290   ""
#define fr__Auto290   ""
#define it__Auto290   ""
#define es__Auto290   ""
#define de__Auto290   ""
#define nl__Auto290   ""
#define pt__Auto290   ""
#define xx__Auto290   ""
#define en_Auto291   "&Widget"
#define fr_Auto291   "&Widget"
#define it_Auto291   "&Widget"
#define es_Auto291   "&Widget"
#define de_Auto291   "&Widget"
#define nl_Auto291   "&Widget"
#define pt_Auto291   "&Widget"
#define xx_Auto291   "&Widget"
#define en__Auto291   ""
#define fr__Auto291   ""
#define it__Auto291   ""
#define es__Auto291   ""
#define de__Auto291   ""
#define nl__Auto291   ""
#define pt__Auto291   ""
#define xx__Auto291   ""
#define en_Auto292   "&Method"
#define fr_Auto292   "&M‚thode"
#define it_Auto292   "&Method"
#define es_Auto292   "&Method"
#define de_Auto292   "&Method"
#define nl_Auto292   "&Method"
#define pt_Auto292   "&Method"
#define xx_Auto292   "&Method"
#define en__Auto292   ""
#define fr__Auto292   ""
#define it__Auto292   ""
#define es__Auto292   ""
#define de__Auto292   ""
#define nl__Auto292   ""
#define pt__Auto292   ""
#define xx__Auto292   ""
#define en_Auto293   "&Next"
#define fr_Auto293   "&Suivant"
#define it_Auto293   "&Next"
#define es_Auto293   "&Next"
#define de_Auto293   "&Next"
#define nl_Auto293   "&Next"
#define pt_Auto293   "&Next"
#define xx_Auto293   "&Next"
#define en__Auto293   ""
#define fr__Auto293   ""
#define it__Auto293   ""
#define es__Auto293   ""
#define de__Auto293   ""
#define nl__Auto293   ""
#define pt__Auto293   ""
#define xx__Auto293   ""
#define en_Auto294   "&Last"
#define fr_Auto294   "D&ernier"
#define it_Auto294   "&Last"
#define es_Auto294   "&Last"
#define de_Auto294   "&Last"
#define nl_Auto294   "&Last"
#define pt_Auto294   "&Last"
#define xx_Auto294   "&Last"
#define en__Auto294   ""
#define fr__Auto294   ""
#define it__Auto294   ""
#define es__Auto294   ""
#define de__Auto294   ""
#define nl__Auto294   ""
#define pt__Auto294   ""
#define xx__Auto294   ""

private struct trace_editor_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * hint_Auto288[8];
	int	s_Auto288;
	void *	p_Auto288;
	char * msg_Auto289[8];
	int	trigger_Auto289;
	char * hint_Auto289[8];
	char * msg_Auto290[8];
	int	trigger_Auto290;
	char * hint_Auto290[8];
	char * msg_Auto291[8];
	int	trigger_Auto291;
	char * hint_Auto291[8];
	char * msg_Auto292[8];
	int	trigger_Auto292;
	char * hint_Auto292[8];
	char * msg_Auto293[8];
	int	trigger_Auto293;
	char * hint_Auto293[8];
	char * msg_Auto294[8];
	int	trigger_Auto294;
	char * hint_Auto294[8];
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct trace_editor_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = trace_editor_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}


public	int	trace_editor_menu_create(struct trace_editor_menu_context **cptr)
{

	int i;
	struct trace_editor_menu_context * _Context=(struct trace_editor_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct trace_editor_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=6;
	_Context->hint_Auto288[0]=en__Auto288;
	_Context->s_Auto288=0;
	_Context->p_Auto288=visual_buffer(328,40,152+2,140+2);
	mouse_move_on();
	for (i=0; i < 8; i++)_Context->msg_Auto289[i]=" ";
	_Context->msg_Auto289[0]=en_Auto289;
	_Context->msg_Auto289[1]=fr_Auto289;
	_Context->msg_Auto289[2]=it_Auto289;
	_Context->msg_Auto289[3]=es_Auto289;
	_Context->msg_Auto289[4]=de_Auto289;
	_Context->msg_Auto289[5]=nl_Auto289;
	_Context->msg_Auto289[6]=pt_Auto289;
	_Context->msg_Auto289[7]=xx_Auto289;
	_Context->hint_Auto289[0]=en__Auto289;
	_Context->hint_Auto289[1]=fr__Auto289;
	_Context->hint_Auto289[2]=it__Auto289;
	_Context->hint_Auto289[3]=es__Auto289;
	_Context->hint_Auto289[4]=de__Auto289;
	_Context->hint_Auto289[5]=nl__Auto289;
	_Context->hint_Auto289[6]=pt__Auto289;
	_Context->hint_Auto289[7]=xx__Auto289;
	for (i=0; i < 8; i++)_Context->msg_Auto290[i]=" ";
	_Context->msg_Auto290[0]=en_Auto290;
	_Context->msg_Auto290[1]=fr_Auto290;
	_Context->msg_Auto290[2]=it_Auto290;
	_Context->msg_Auto290[3]=es_Auto290;
	_Context->msg_Auto290[4]=de_Auto290;
	_Context->msg_Auto290[5]=nl_Auto290;
	_Context->msg_Auto290[6]=pt_Auto290;
	_Context->msg_Auto290[7]=xx_Auto290;
	_Context->hint_Auto290[0]=en__Auto290;
	_Context->hint_Auto290[1]=fr__Auto290;
	_Context->hint_Auto290[2]=it__Auto290;
	_Context->hint_Auto290[3]=es__Auto290;
	_Context->hint_Auto290[4]=de__Auto290;
	_Context->hint_Auto290[5]=nl__Auto290;
	_Context->hint_Auto290[6]=pt__Auto290;
	_Context->hint_Auto290[7]=xx__Auto290;
	for (i=0; i < 8; i++)_Context->msg_Auto291[i]=" ";
	_Context->msg_Auto291[0]=en_Auto291;
	_Context->msg_Auto291[1]=fr_Auto291;
	_Context->msg_Auto291[2]=it_Auto291;
	_Context->msg_Auto291[3]=es_Auto291;
	_Context->msg_Auto291[4]=de_Auto291;
	_Context->msg_Auto291[5]=nl_Auto291;
	_Context->msg_Auto291[6]=pt_Auto291;
	_Context->msg_Auto291[7]=xx_Auto291;
	_Context->hint_Auto291[0]=en__Auto291;
	_Context->hint_Auto291[1]=fr__Auto291;
	_Context->hint_Auto291[2]=it__Auto291;
	_Context->hint_Auto291[3]=es__Auto291;
	_Context->hint_Auto291[4]=de__Auto291;
	_Context->hint_Auto291[5]=nl__Auto291;
	_Context->hint_Auto291[6]=pt__Auto291;
	_Context->hint_Auto291[7]=xx__Auto291;
	for (i=0; i < 8; i++)_Context->msg_Auto292[i]=" ";
	_Context->msg_Auto292[0]=en_Auto292;
	_Context->msg_Auto292[1]=fr_Auto292;
	_Context->msg_Auto292[2]=it_Auto292;
	_Context->msg_Auto292[3]=es_Auto292;
	_Context->msg_Auto292[4]=de_Auto292;
	_Context->msg_Auto292[5]=nl_Auto292;
	_Context->msg_Auto292[6]=pt_Auto292;
	_Context->msg_Auto292[7]=xx_Auto292;
	_Context->hint_Auto292[0]=en__Auto292;
	_Context->hint_Auto292[1]=fr__Auto292;
	_Context->hint_Auto292[2]=it__Auto292;
	_Context->hint_Auto292[3]=es__Auto292;
	_Context->hint_Auto292[4]=de__Auto292;
	_Context->hint_Auto292[5]=nl__Auto292;
	_Context->hint_Auto292[6]=pt__Auto292;
	_Context->hint_Auto292[7]=xx__Auto292;
	for (i=0; i < 8; i++)_Context->msg_Auto293[i]=" ";
	_Context->msg_Auto293[0]=en_Auto293;
	_Context->msg_Auto293[1]=fr_Auto293;
	_Context->msg_Auto293[2]=it_Auto293;
	_Context->msg_Auto293[3]=es_Auto293;
	_Context->msg_Auto293[4]=de_Auto293;
	_Context->msg_Auto293[5]=nl_Auto293;
	_Context->msg_Auto293[6]=pt_Auto293;
	_Context->msg_Auto293[7]=xx_Auto293;
	_Context->hint_Auto293[0]=en__Auto293;
	_Context->hint_Auto293[1]=fr__Auto293;
	_Context->hint_Auto293[2]=it__Auto293;
	_Context->hint_Auto293[3]=es__Auto293;
	_Context->hint_Auto293[4]=de__Auto293;
	_Context->hint_Auto293[5]=nl__Auto293;
	_Context->hint_Auto293[6]=pt__Auto293;
	_Context->hint_Auto293[7]=xx__Auto293;
	for (i=0; i < 8; i++)_Context->msg_Auto294[i]=" ";
	_Context->msg_Auto294[0]=en_Auto294;
	_Context->msg_Auto294[1]=fr_Auto294;
	_Context->msg_Auto294[2]=it_Auto294;
	_Context->msg_Auto294[3]=es_Auto294;
	_Context->msg_Auto294[4]=de_Auto294;
	_Context->msg_Auto294[5]=nl_Auto294;
	_Context->msg_Auto294[6]=pt_Auto294;
	_Context->msg_Auto294[7]=xx_Auto294;
	_Context->hint_Auto294[0]=en__Auto294;
	_Context->hint_Auto294[1]=fr__Auto294;
	_Context->hint_Auto294[2]=it__Auto294;
	_Context->hint_Auto294[3]=es__Auto294;
	_Context->hint_Auto294[4]=de__Auto294;
	_Context->hint_Auto294[5]=nl__Auto294;
	_Context->hint_Auto294[6]=pt__Auto294;
	_Context->hint_Auto294[7]=xx__Auto294;
	return(0);
}

public 	int	trace_editor_menu_hide(struct trace_editor_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto288 != (void *) 0)
	&& (_Context->s_Auto288 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto288,328,40);
		_Context->s_Auto288=0;
		}

	return(result);
}

public	int	trace_editor_menu_remove(struct trace_editor_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	mouse_move_off();
	if (_Context->p_Auto288 != (void *) 0)
		_Context->p_Auto288 = visual_drop(_Context->p_Auto288);
	_Context=liberate(_Context);

	return(result);
}

public	int	trace_editor_menu_show(struct trace_editor_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if ((_Context->p_Auto288 != (void *) 0)
	&& (_Context->s_Auto288 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto288,328,40);
		_Context->s_Auto288=1;
		}
	if (((_Context->status = visual_styled_element(328,40,152,140,GetWidgetStyle(1)," ",0)) != 0)
) {
		visual_filzone(328,40,152,140,27,11);
		}
	_Context->trigger_Auto289=visual_trigger_code(_Context->msg_Auto289[_Context->language],strlen(_Context->msg_Auto289[_Context->language]));
	if (((_Context->status = visual_styled_element(344,48,120,20,GetWidgetStyle(2),_Context->msg_Auto289[_Context->language],strlen(_Context->msg_Auto289[_Context->language]))) != 0)
) {
	visual_button(344,48,120,20,vfh[2],16,0,_Context->msg_Auto289[_Context->language],strlen(_Context->msg_Auto289[_Context->language]),32);
		}
	_Context->trigger_Auto290=visual_trigger_code(_Context->msg_Auto290[_Context->language],strlen(_Context->msg_Auto290[_Context->language]));
	if (((_Context->status = visual_styled_element(344,68,120,20,GetWidgetStyle(2),_Context->msg_Auto290[_Context->language],strlen(_Context->msg_Auto290[_Context->language]))) != 0)
) {
	visual_button(344,68,120,20,vfh[2],16,0,_Context->msg_Auto290[_Context->language],strlen(_Context->msg_Auto290[_Context->language]),32);
		}
	_Context->trigger_Auto291=visual_trigger_code(_Context->msg_Auto291[_Context->language],strlen(_Context->msg_Auto291[_Context->language]));
	if (((_Context->status = visual_styled_element(344,88,120,20,GetWidgetStyle(2),_Context->msg_Auto291[_Context->language],strlen(_Context->msg_Auto291[_Context->language]))) != 0)
) {
	visual_button(344,88,120,20,vfh[2],16,0,_Context->msg_Auto291[_Context->language],strlen(_Context->msg_Auto291[_Context->language]),32);
		}
	_Context->trigger_Auto292=visual_trigger_code(_Context->msg_Auto292[_Context->language],strlen(_Context->msg_Auto292[_Context->language]));
	if (((_Context->status = visual_styled_element(344,108,120,20,GetWidgetStyle(2),_Context->msg_Auto292[_Context->language],strlen(_Context->msg_Auto292[_Context->language]))) != 0)
) {
	visual_button(344,108,120,20,vfh[2],16,0,_Context->msg_Auto292[_Context->language],strlen(_Context->msg_Auto292[_Context->language]),32);
		}
	_Context->trigger_Auto293=visual_trigger_code(_Context->msg_Auto293[_Context->language],strlen(_Context->msg_Auto293[_Context->language]));
	if (((_Context->status = visual_styled_element(344,128,120,20,GetWidgetStyle(2),_Context->msg_Auto293[_Context->language],strlen(_Context->msg_Auto293[_Context->language]))) != 0)
) {
	visual_button(344,128,120,20,vfh[2],16,0,_Context->msg_Auto293[_Context->language],strlen(_Context->msg_Auto293[_Context->language]),32);
		}
	_Context->trigger_Auto294=visual_trigger_code(_Context->msg_Auto294[_Context->language],strlen(_Context->msg_Auto294[_Context->language]));
	if (((_Context->status = visual_styled_element(344,148,120,20,GetWidgetStyle(2),_Context->msg_Auto294[_Context->language],strlen(_Context->msg_Auto294[_Context->language]))) != 0)
) {
	visual_button(344,148,120,20,vfh[2],16,0,_Context->msg_Auto294[_Context->language],strlen(_Context->msg_Auto294[_Context->language]),32);
		}
	visual_thaw(328,40,152,140);

	return(0);
}
private int on_Auto289_event(struct trace_editor_menu_context * _Context) {
	return(__TRACE_FIRST);
	return(-1);
}
private int on_Auto290_event(struct trace_editor_menu_context * _Context) {
	return(__TRACE_PREVIOUS);
	return(-1);
}
private int on_Auto291_event(struct trace_editor_menu_context * _Context) {
	return(__TRACE_WIDGET);
	return(-1);
}
private int on_Auto292_event(struct trace_editor_menu_context * _Context) {
	return(__TRACE_METHOD);
	return(-1);
}
private int on_Auto293_event(struct trace_editor_menu_context * _Context) {
	return(__TRACE_NEXT);
	return(-1);
}
private int on_Auto294_event(struct trace_editor_menu_context * _Context) {
	return(__TRACE_LAST);
	return(-1);
}


public	int	trace_editor_menu_event(
struct trace_editor_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto289 == mb ) return(1);
		if (_Context->trigger_Auto290 == mb ) return(2);
		if (_Context->trigger_Auto291 == mb ) return(3);
		if (_Context->trigger_Auto292 == mb ) return(4);
		if (_Context->trigger_Auto293 == mb ) return(5);
		if (_Context->trigger_Auto294 == mb ) return(6);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 344 ) 
	&&  ( my >= 48 ) 
	&&  ( mx <= 464 ) 
	&&  ( my <= 68 )) {
		return(1); /* Auto289 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 464 ) 
	&&  ( my <= 88 )) {
		return(2); /* Auto290 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 88 ) 
	&&  ( mx <= 464 ) 
	&&  ( my <= 108 )) {
		return(3); /* Auto291 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 108 ) 
	&&  ( mx <= 464 ) 
	&&  ( my <= 128 )) {
		return(4); /* Auto292 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 128 ) 
	&&  ( mx <= 464 ) 
	&&  ( my <= 148 )) {
		return(5); /* Auto293 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 148 ) 
	&&  ( mx <= 464 ) 
	&&  ( my <= 168 )) {
		return(6); /* Auto294 */
		}

	return(-1);
}


public	int	trace_editor_menu_focus(struct trace_editor_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto289 */
				_Context->trigger_Auto289=visual_trigger_code(_Context->msg_Auto289[_Context->language],strlen(_Context->msg_Auto289[_Context->language]));
				if (((_Context->status = visual_styled_element(344,48,120,20,GetWidgetStyle(3),_Context->msg_Auto289[_Context->language],strlen(_Context->msg_Auto289[_Context->language]))) != 0)
) {
					visual_button(344,48,120,20,vfh[2],16,0,_Context->msg_Auto289[_Context->language],strlen(_Context->msg_Auto289[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto289=visual_trigger_code(_Context->msg_Auto289[_Context->language],strlen(_Context->msg_Auto289[_Context->language]));
				if (((_Context->status = visual_styled_element(344,48,120,20,GetWidgetStyle(2),_Context->msg_Auto289[_Context->language],strlen(_Context->msg_Auto289[_Context->language]))) != 0)
) {
	visual_button(344,48,120,20,vfh[2],16,0,_Context->msg_Auto289[_Context->language],strlen(_Context->msg_Auto289[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto290 */
				_Context->trigger_Auto290=visual_trigger_code(_Context->msg_Auto290[_Context->language],strlen(_Context->msg_Auto290[_Context->language]));
				if (((_Context->status = visual_styled_element(344,68,120,20,GetWidgetStyle(3),_Context->msg_Auto290[_Context->language],strlen(_Context->msg_Auto290[_Context->language]))) != 0)
) {
					visual_button(344,68,120,20,vfh[2],16,0,_Context->msg_Auto290[_Context->language],strlen(_Context->msg_Auto290[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto290=visual_trigger_code(_Context->msg_Auto290[_Context->language],strlen(_Context->msg_Auto290[_Context->language]));
				if (((_Context->status = visual_styled_element(344,68,120,20,GetWidgetStyle(2),_Context->msg_Auto290[_Context->language],strlen(_Context->msg_Auto290[_Context->language]))) != 0)
) {
	visual_button(344,68,120,20,vfh[2],16,0,_Context->msg_Auto290[_Context->language],strlen(_Context->msg_Auto290[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto291 */
				_Context->trigger_Auto291=visual_trigger_code(_Context->msg_Auto291[_Context->language],strlen(_Context->msg_Auto291[_Context->language]));
				if (((_Context->status = visual_styled_element(344,88,120,20,GetWidgetStyle(3),_Context->msg_Auto291[_Context->language],strlen(_Context->msg_Auto291[_Context->language]))) != 0)
) {
					visual_button(344,88,120,20,vfh[2],16,0,_Context->msg_Auto291[_Context->language],strlen(_Context->msg_Auto291[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto291=visual_trigger_code(_Context->msg_Auto291[_Context->language],strlen(_Context->msg_Auto291[_Context->language]));
				if (((_Context->status = visual_styled_element(344,88,120,20,GetWidgetStyle(2),_Context->msg_Auto291[_Context->language],strlen(_Context->msg_Auto291[_Context->language]))) != 0)
) {
	visual_button(344,88,120,20,vfh[2],16,0,_Context->msg_Auto291[_Context->language],strlen(_Context->msg_Auto291[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto292 */
				_Context->trigger_Auto292=visual_trigger_code(_Context->msg_Auto292[_Context->language],strlen(_Context->msg_Auto292[_Context->language]));
				if (((_Context->status = visual_styled_element(344,108,120,20,GetWidgetStyle(3),_Context->msg_Auto292[_Context->language],strlen(_Context->msg_Auto292[_Context->language]))) != 0)
) {
					visual_button(344,108,120,20,vfh[2],16,0,_Context->msg_Auto292[_Context->language],strlen(_Context->msg_Auto292[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto292=visual_trigger_code(_Context->msg_Auto292[_Context->language],strlen(_Context->msg_Auto292[_Context->language]));
				if (((_Context->status = visual_styled_element(344,108,120,20,GetWidgetStyle(2),_Context->msg_Auto292[_Context->language],strlen(_Context->msg_Auto292[_Context->language]))) != 0)
) {
	visual_button(344,108,120,20,vfh[2],16,0,_Context->msg_Auto292[_Context->language],strlen(_Context->msg_Auto292[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto293 */
				_Context->trigger_Auto293=visual_trigger_code(_Context->msg_Auto293[_Context->language],strlen(_Context->msg_Auto293[_Context->language]));
				if (((_Context->status = visual_styled_element(344,128,120,20,GetWidgetStyle(3),_Context->msg_Auto293[_Context->language],strlen(_Context->msg_Auto293[_Context->language]))) != 0)
) {
					visual_button(344,128,120,20,vfh[2],16,0,_Context->msg_Auto293[_Context->language],strlen(_Context->msg_Auto293[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto293=visual_trigger_code(_Context->msg_Auto293[_Context->language],strlen(_Context->msg_Auto293[_Context->language]));
				if (((_Context->status = visual_styled_element(344,128,120,20,GetWidgetStyle(2),_Context->msg_Auto293[_Context->language],strlen(_Context->msg_Auto293[_Context->language]))) != 0)
) {
	visual_button(344,128,120,20,vfh[2],16,0,_Context->msg_Auto293[_Context->language],strlen(_Context->msg_Auto293[_Context->language]),32);
				}
				break;
			case	0x6 :
				/* Auto294 */
				_Context->trigger_Auto294=visual_trigger_code(_Context->msg_Auto294[_Context->language],strlen(_Context->msg_Auto294[_Context->language]));
				if (((_Context->status = visual_styled_element(344,148,120,20,GetWidgetStyle(3),_Context->msg_Auto294[_Context->language],strlen(_Context->msg_Auto294[_Context->language]))) != 0)
) {
					visual_button(344,148,120,20,vfh[2],16,0,_Context->msg_Auto294[_Context->language],strlen(_Context->msg_Auto294[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto294=visual_trigger_code(_Context->msg_Auto294[_Context->language],strlen(_Context->msg_Auto294[_Context->language]));
				if (((_Context->status = visual_styled_element(344,148,120,20,GetWidgetStyle(2),_Context->msg_Auto294[_Context->language],strlen(_Context->msg_Auto294[_Context->language]))) != 0)
) {
	visual_button(344,148,120,20,vfh[2],16,0,_Context->msg_Auto294[_Context->language],strlen(_Context->msg_Auto294[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			trace_editor_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=6;
			trace_editor_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  328 )
				|| ( visual_event(6) <  40 )
				|| ( visual_event(7) >  480 )
				|| ( visual_event(6) >  180 )) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=trace_editor_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto289 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto289=visual_trigger_code(_Context->msg_Auto289[_Context->language],strlen(_Context->msg_Auto289[_Context->language]));
						if (((_Context->status = visual_styled_element(344,48,120,20,GetWidgetStyle(3),_Context->msg_Auto289[_Context->language],strlen(_Context->msg_Auto289[_Context->language]))) != 0)
) {
							visual_button(344,48,120,20,vfh[2],16,0,_Context->msg_Auto289[_Context->language],strlen(_Context->msg_Auto289[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto289=visual_trigger_code(_Context->msg_Auto289[_Context->language],strlen(_Context->msg_Auto289[_Context->language]));
						if (((_Context->status = visual_styled_element(344,48,120,20,GetWidgetStyle(2),_Context->msg_Auto289[_Context->language],strlen(_Context->msg_Auto289[_Context->language]))) != 0)
) {
	visual_button(344,48,120,20,vfh[2],16,0,_Context->msg_Auto289[_Context->language],strlen(_Context->msg_Auto289[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto289_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto290 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto290=visual_trigger_code(_Context->msg_Auto290[_Context->language],strlen(_Context->msg_Auto290[_Context->language]));
						if (((_Context->status = visual_styled_element(344,68,120,20,GetWidgetStyle(3),_Context->msg_Auto290[_Context->language],strlen(_Context->msg_Auto290[_Context->language]))) != 0)
) {
							visual_button(344,68,120,20,vfh[2],16,0,_Context->msg_Auto290[_Context->language],strlen(_Context->msg_Auto290[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto290=visual_trigger_code(_Context->msg_Auto290[_Context->language],strlen(_Context->msg_Auto290[_Context->language]));
						if (((_Context->status = visual_styled_element(344,68,120,20,GetWidgetStyle(2),_Context->msg_Auto290[_Context->language],strlen(_Context->msg_Auto290[_Context->language]))) != 0)
) {
	visual_button(344,68,120,20,vfh[2],16,0,_Context->msg_Auto290[_Context->language],strlen(_Context->msg_Auto290[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto290_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto291 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto291=visual_trigger_code(_Context->msg_Auto291[_Context->language],strlen(_Context->msg_Auto291[_Context->language]));
						if (((_Context->status = visual_styled_element(344,88,120,20,GetWidgetStyle(3),_Context->msg_Auto291[_Context->language],strlen(_Context->msg_Auto291[_Context->language]))) != 0)
) {
							visual_button(344,88,120,20,vfh[2],16,0,_Context->msg_Auto291[_Context->language],strlen(_Context->msg_Auto291[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto291=visual_trigger_code(_Context->msg_Auto291[_Context->language],strlen(_Context->msg_Auto291[_Context->language]));
						if (((_Context->status = visual_styled_element(344,88,120,20,GetWidgetStyle(2),_Context->msg_Auto291[_Context->language],strlen(_Context->msg_Auto291[_Context->language]))) != 0)
) {
	visual_button(344,88,120,20,vfh[2],16,0,_Context->msg_Auto291[_Context->language],strlen(_Context->msg_Auto291[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto291_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto292 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto292=visual_trigger_code(_Context->msg_Auto292[_Context->language],strlen(_Context->msg_Auto292[_Context->language]));
						if (((_Context->status = visual_styled_element(344,108,120,20,GetWidgetStyle(3),_Context->msg_Auto292[_Context->language],strlen(_Context->msg_Auto292[_Context->language]))) != 0)
) {
							visual_button(344,108,120,20,vfh[2],16,0,_Context->msg_Auto292[_Context->language],strlen(_Context->msg_Auto292[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto292=visual_trigger_code(_Context->msg_Auto292[_Context->language],strlen(_Context->msg_Auto292[_Context->language]));
						if (((_Context->status = visual_styled_element(344,108,120,20,GetWidgetStyle(2),_Context->msg_Auto292[_Context->language],strlen(_Context->msg_Auto292[_Context->language]))) != 0)
) {
	visual_button(344,108,120,20,vfh[2],16,0,_Context->msg_Auto292[_Context->language],strlen(_Context->msg_Auto292[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto292_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto293 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto293=visual_trigger_code(_Context->msg_Auto293[_Context->language],strlen(_Context->msg_Auto293[_Context->language]));
						if (((_Context->status = visual_styled_element(344,128,120,20,GetWidgetStyle(3),_Context->msg_Auto293[_Context->language],strlen(_Context->msg_Auto293[_Context->language]))) != 0)
) {
							visual_button(344,128,120,20,vfh[2],16,0,_Context->msg_Auto293[_Context->language],strlen(_Context->msg_Auto293[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto293=visual_trigger_code(_Context->msg_Auto293[_Context->language],strlen(_Context->msg_Auto293[_Context->language]));
						if (((_Context->status = visual_styled_element(344,128,120,20,GetWidgetStyle(2),_Context->msg_Auto293[_Context->language],strlen(_Context->msg_Auto293[_Context->language]))) != 0)
) {
	visual_button(344,128,120,20,vfh[2],16,0,_Context->msg_Auto293[_Context->language],strlen(_Context->msg_Auto293[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto293_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto294 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto294=visual_trigger_code(_Context->msg_Auto294[_Context->language],strlen(_Context->msg_Auto294[_Context->language]));
						if (((_Context->status = visual_styled_element(344,148,120,20,GetWidgetStyle(3),_Context->msg_Auto294[_Context->language],strlen(_Context->msg_Auto294[_Context->language]))) != 0)
) {
							visual_button(344,148,120,20,vfh[2],16,0,_Context->msg_Auto294[_Context->language],strlen(_Context->msg_Auto294[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto294=visual_trigger_code(_Context->msg_Auto294[_Context->language],strlen(_Context->msg_Auto294[_Context->language]));
						if (((_Context->status = visual_styled_element(344,148,120,20,GetWidgetStyle(2),_Context->msg_Auto294[_Context->language],strlen(_Context->msg_Auto294[_Context->language]))) != 0)
) {
	visual_button(344,148,120,20,vfh[2],16,0,_Context->msg_Auto294[_Context->language],strlen(_Context->msg_Auto294[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto294_event(_Context)) != -1) break;

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
				_Context->focus_item=6;
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

public	int	trace_editor_menu()
{
	int	status=0;
	struct trace_editor_menu_context * _Context=(struct trace_editor_menu_context*) 0;
	status = trace_editor_menu_create(&_Context);
	if ( status != 0) return(status);
	status = trace_editor_menu_show(_Context);
		enter_modal();
	status = trace_editor_menu_focus(_Context);
		leave_modal();
	status = trace_editor_menu_hide(_Context);
	status = trace_editor_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _tracmenu_c */
