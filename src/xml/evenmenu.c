
#ifndef _evenmenu_c
#define _evenmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : evenmenu.xml                                             */
/* Target         : evenmenu.c                                               */
/* Identification : 0.0-1177512018-5209.5208                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Auto617   ""
#define en__Auto617   ""
#define en_Auto618   "On&Create"
#define fr_Auto618   "On&Create"
#define it_Auto618   "On&Create"
#define es_Auto618   "On&Create"
#define de_Auto618   "On&Create"
#define nl_Auto618   "On&Create"
#define pt_Auto618   "On&Create"
#define xx_Auto618   "On&Create"
#define en__Auto618   ""
#define en_Auto619   "On&Remove"
#define fr_Auto619   "On&Remove"
#define it_Auto619   "On&Remove"
#define es_Auto619   "On&Remove"
#define de_Auto619   "On&Remove"
#define nl_Auto619   "On&Remove"
#define pt_Auto619   "On&Remove"
#define xx_Auto619   "On&Remove"
#define en__Auto619   ""
#define en_Auto620   "On&Show"
#define fr_Auto620   "On&Show"
#define it_Auto620   "On&Show"
#define es_Auto620   "On&Show"
#define de_Auto620   "On&Show"
#define nl_Auto620   "On&Show"
#define pt_Auto620   "On&Show"
#define xx_Auto620   "On&Show"
#define en__Auto620   ""
#define en_Auto621   "On&Hide"
#define fr_Auto621   "On&Hide"
#define it_Auto621   "On&Hide"
#define es_Auto621   "On&Hide"
#define de_Auto621   "On&Hide"
#define nl_Auto621   "On&Hide"
#define pt_Auto621   "On&Hide"
#define xx_Auto621   "On&Hide"
#define en__Auto621   ""
#define en_Auto622   "On&Focus"
#define fr_Auto622   "On&Focus"
#define it_Auto622   "On&Focus"
#define es_Auto622   "On&Focus"
#define de_Auto622   "On&Focus"
#define nl_Auto622   "On&Focus"
#define pt_Auto622   "On&Focus"
#define xx_Auto622   "On&Focus"
#define en__Auto622   ""
#define en_Auto623   "On&Lose"
#define fr_Auto623   "On&Lose"
#define it_Auto623   "On&Lose"
#define es_Auto623   "On&Lose"
#define de_Auto623   "On&Lose"
#define nl_Auto623   "On&Lose"
#define pt_Auto623   "On&Lose"
#define xx_Auto623   "On&Lose"
#define en__Auto623   ""
#define en_Auto624   "On&Event"
#define fr_Auto624   "On&Event"
#define it_Auto624   "On&Event"
#define es_Auto624   "On&Event"
#define de_Auto624   "On&Event"
#define nl_Auto624   "On&Event"
#define pt_Auto624   "On&Event"
#define xx_Auto624   "On&Event"
#define en__Auto624   ""
#define en_Auto625   "&Item Document"
#define fr_Auto625   "&Item Document"
#define it_Auto625   "&Item Document"
#define es_Auto625   "&Item Document"
#define de_Auto625   "&Item Document"
#define nl_Auto625   "&Item Document"
#define pt_Auto625   "&Item Document"
#define xx_Auto625   "&Item Document"
#define en__Auto625   ""
#define en_Auto626   "Form &Document"
#define fr_Auto626   "Form &Document"
#define it_Auto626   "Form &Document"
#define es_Auto626   "Form &Document"
#define de_Auto626   "Form &Document"
#define nl_Auto626   "Form &Document"
#define pt_Auto626   "Form &Document"
#define xx_Auto626   "Form &Document"
#define en__Auto626   ""

private struct standard_event_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * hint_Auto617[8];
	int	s_Auto617;
	void *	p_Auto617;
	char * msg_Auto618[8];
	int	trigger_Auto618;
	char * hint_Auto618[8];
	char * msg_Auto619[8];
	int	trigger_Auto619;
	char * hint_Auto619[8];
	char * msg_Auto620[8];
	int	trigger_Auto620;
	char * hint_Auto620[8];
	char * msg_Auto621[8];
	int	trigger_Auto621;
	char * hint_Auto621[8];
	char * msg_Auto622[8];
	int	trigger_Auto622;
	char * hint_Auto622[8];
	char * msg_Auto623[8];
	int	trigger_Auto623;
	char * hint_Auto623[8];
	char * msg_Auto624[8];
	int	trigger_Auto624;
	char * hint_Auto624[8];
	char * msg_Auto625[8];
	int	trigger_Auto625;
	char * hint_Auto625[8];
	char * msg_Auto626[8];
	int	trigger_Auto626;
	char * hint_Auto626[8];
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct standard_event_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = standard_event_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}


public	int	standard_event_menu_create(struct standard_event_menu_context **cptr)
{

	int i;
	struct standard_event_menu_context * _Context=(struct standard_event_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct standard_event_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=9;
	_Context->hint_Auto617[0]=en__Auto617;
	_Context->s_Auto617=0;
	_Context->p_Auto617=visual_buffer(184,32,176+2,204+2);
	mouse_move_on();
	for (i=0; i < 8; i++)_Context->msg_Auto618[i]=" ";
	_Context->msg_Auto618[0]=en_Auto618;
	_Context->msg_Auto618[1]=fr_Auto618;
	_Context->msg_Auto618[2]=it_Auto618;
	_Context->msg_Auto618[3]=es_Auto618;
	_Context->msg_Auto618[4]=de_Auto618;
	_Context->msg_Auto618[5]=nl_Auto618;
	_Context->msg_Auto618[6]=pt_Auto618;
	_Context->msg_Auto618[7]=xx_Auto618;
	_Context->hint_Auto618[0]=en__Auto618;
	for (i=0; i < 8; i++)_Context->msg_Auto619[i]=" ";
	_Context->msg_Auto619[0]=en_Auto619;
	_Context->msg_Auto619[1]=fr_Auto619;
	_Context->msg_Auto619[2]=it_Auto619;
	_Context->msg_Auto619[3]=es_Auto619;
	_Context->msg_Auto619[4]=de_Auto619;
	_Context->msg_Auto619[5]=nl_Auto619;
	_Context->msg_Auto619[6]=pt_Auto619;
	_Context->msg_Auto619[7]=xx_Auto619;
	_Context->hint_Auto619[0]=en__Auto619;
	for (i=0; i < 8; i++)_Context->msg_Auto620[i]=" ";
	_Context->msg_Auto620[0]=en_Auto620;
	_Context->msg_Auto620[1]=fr_Auto620;
	_Context->msg_Auto620[2]=it_Auto620;
	_Context->msg_Auto620[3]=es_Auto620;
	_Context->msg_Auto620[4]=de_Auto620;
	_Context->msg_Auto620[5]=nl_Auto620;
	_Context->msg_Auto620[6]=pt_Auto620;
	_Context->msg_Auto620[7]=xx_Auto620;
	_Context->hint_Auto620[0]=en__Auto620;
	for (i=0; i < 8; i++)_Context->msg_Auto621[i]=" ";
	_Context->msg_Auto621[0]=en_Auto621;
	_Context->msg_Auto621[1]=fr_Auto621;
	_Context->msg_Auto621[2]=it_Auto621;
	_Context->msg_Auto621[3]=es_Auto621;
	_Context->msg_Auto621[4]=de_Auto621;
	_Context->msg_Auto621[5]=nl_Auto621;
	_Context->msg_Auto621[6]=pt_Auto621;
	_Context->msg_Auto621[7]=xx_Auto621;
	_Context->hint_Auto621[0]=en__Auto621;
	for (i=0; i < 8; i++)_Context->msg_Auto622[i]=" ";
	_Context->msg_Auto622[0]=en_Auto622;
	_Context->msg_Auto622[1]=fr_Auto622;
	_Context->msg_Auto622[2]=it_Auto622;
	_Context->msg_Auto622[3]=es_Auto622;
	_Context->msg_Auto622[4]=de_Auto622;
	_Context->msg_Auto622[5]=nl_Auto622;
	_Context->msg_Auto622[6]=pt_Auto622;
	_Context->msg_Auto622[7]=xx_Auto622;
	_Context->hint_Auto622[0]=en__Auto622;
	for (i=0; i < 8; i++)_Context->msg_Auto623[i]=" ";
	_Context->msg_Auto623[0]=en_Auto623;
	_Context->msg_Auto623[1]=fr_Auto623;
	_Context->msg_Auto623[2]=it_Auto623;
	_Context->msg_Auto623[3]=es_Auto623;
	_Context->msg_Auto623[4]=de_Auto623;
	_Context->msg_Auto623[5]=nl_Auto623;
	_Context->msg_Auto623[6]=pt_Auto623;
	_Context->msg_Auto623[7]=xx_Auto623;
	_Context->hint_Auto623[0]=en__Auto623;
	for (i=0; i < 8; i++)_Context->msg_Auto624[i]=" ";
	_Context->msg_Auto624[0]=en_Auto624;
	_Context->msg_Auto624[1]=fr_Auto624;
	_Context->msg_Auto624[2]=it_Auto624;
	_Context->msg_Auto624[3]=es_Auto624;
	_Context->msg_Auto624[4]=de_Auto624;
	_Context->msg_Auto624[5]=nl_Auto624;
	_Context->msg_Auto624[6]=pt_Auto624;
	_Context->msg_Auto624[7]=xx_Auto624;
	_Context->hint_Auto624[0]=en__Auto624;
	for (i=0; i < 8; i++)_Context->msg_Auto625[i]=" ";
	_Context->msg_Auto625[0]=en_Auto625;
	_Context->msg_Auto625[1]=fr_Auto625;
	_Context->msg_Auto625[2]=it_Auto625;
	_Context->msg_Auto625[3]=es_Auto625;
	_Context->msg_Auto625[4]=de_Auto625;
	_Context->msg_Auto625[5]=nl_Auto625;
	_Context->msg_Auto625[6]=pt_Auto625;
	_Context->msg_Auto625[7]=xx_Auto625;
	_Context->hint_Auto625[0]=en__Auto625;
	for (i=0; i < 8; i++)_Context->msg_Auto626[i]=" ";
	_Context->msg_Auto626[0]=en_Auto626;
	_Context->msg_Auto626[1]=fr_Auto626;
	_Context->msg_Auto626[2]=it_Auto626;
	_Context->msg_Auto626[3]=es_Auto626;
	_Context->msg_Auto626[4]=de_Auto626;
	_Context->msg_Auto626[5]=nl_Auto626;
	_Context->msg_Auto626[6]=pt_Auto626;
	_Context->msg_Auto626[7]=xx_Auto626;
	_Context->hint_Auto626[0]=en__Auto626;
	return(0);
}

public 	int	standard_event_menu_hide(struct standard_event_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto617 != (void *) 0)
	&& (_Context->s_Auto617 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto617,184,32);
		_Context->s_Auto617=0;
		}

	return(result);
}

public	int	standard_event_menu_remove(struct standard_event_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	mouse_move_off();
	if (_Context->p_Auto617 != (void *) 0)
		_Context->p_Auto617 = visual_drop(_Context->p_Auto617);
	_Context=liberate(_Context);

	return(result);
}

public	int	standard_event_menu_show(struct standard_event_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if ((_Context->p_Auto617 != (void *) 0)
	&& (_Context->s_Auto617 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto617,184,32);
		_Context->s_Auto617=1;
		}
	if (((_Context->status = visual_styled_element(184,32,176,204,GetWidgetStyle(1)," ",0)) != 0)
) {
		visual_filzone(184,32,176,204,27,11);
		}
	_Context->trigger_Auto618=visual_trigger_code(_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]));
	if (((_Context->status = visual_styled_element(200,44,144,20,GetWidgetStyle(2),_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]))) != 0)
) {
	visual_button(200,44,144,20,vfh[2],16,0,_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]),32);
		}
	_Context->trigger_Auto619=visual_trigger_code(_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]));
	if (((_Context->status = visual_styled_element(200,64,144,20,GetWidgetStyle(2),_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]))) != 0)
) {
	visual_button(200,64,144,20,vfh[2],16,0,_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]),32);
		}
	_Context->trigger_Auto620=visual_trigger_code(_Context->msg_Auto620[_Context->language],strlen(_Context->msg_Auto620[_Context->language]));
	if (((_Context->status = visual_styled_element(200,84,144,20,GetWidgetStyle(2),_Context->msg_Auto620[_Context->language],strlen(_Context->msg_Auto620[_Context->language]))) != 0)
) {
	visual_button(200,84,144,20,vfh[2],16,0,_Context->msg_Auto620[_Context->language],strlen(_Context->msg_Auto620[_Context->language]),32);
		}
	_Context->trigger_Auto621=visual_trigger_code(_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]));
	if (((_Context->status = visual_styled_element(200,104,144,20,GetWidgetStyle(2),_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]))) != 0)
) {
	visual_button(200,104,144,20,vfh[2],16,0,_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]),32);
		}
	_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
	if (((_Context->status = visual_styled_element(200,124,144,20,GetWidgetStyle(2),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
	visual_button(200,124,144,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),32);
		}
	_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
	if (((_Context->status = visual_styled_element(200,144,144,20,GetWidgetStyle(2),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
	visual_button(200,144,144,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),32);
		}
	_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
	if (((_Context->status = visual_styled_element(200,164,144,20,GetWidgetStyle(2),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
	visual_button(200,164,144,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),32);
		}
	_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
	if (((_Context->status = visual_styled_element(200,184,144,20,GetWidgetStyle(2),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
	visual_button(200,184,144,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),32);
		}
	_Context->trigger_Auto626=visual_trigger_code(_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]));
	if (((_Context->status = visual_styled_element(200,204,144,20,GetWidgetStyle(2),_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]))) != 0)
) {
	visual_button(200,204,144,20,vfh[2],16,0,_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]),32);
		}
	visual_thaw(184,32,176,204);

	return(0);
}
private int on_Auto618_event(struct standard_event_menu_context * _Context) {
	return(_EVENT_CREATE);
	return(-1);
}
private int on_Auto619_event(struct standard_event_menu_context * _Context) {
	return(_EVENT_REMOVE);
	return(-1);
}
private int on_Auto620_event(struct standard_event_menu_context * _Context) {
	return(_EVENT_SHOW);
	return(-1);
}
private int on_Auto621_event(struct standard_event_menu_context * _Context) {
	return(_EVENT_HIDE);
	return(-1);
}
private int on_Auto622_event(struct standard_event_menu_context * _Context) {
	return(_EVENT_FOCUS);
	return(-1);
}
private int on_Auto623_event(struct standard_event_menu_context * _Context) {
	return(_EVENT_LOSE);
	return(-1);
}
private int on_Auto624_event(struct standard_event_menu_context * _Context) {
	return(_EVENT_EVENT);
	return(-1);
}
private int on_Auto625_event(struct standard_event_menu_context * _Context) {
	return(_EVENT_ITEMDOC);
	return(-1);
}
private int on_Auto626_event(struct standard_event_menu_context * _Context) {
	return(_EVENT_FORMDOC);
	return(-1);
}


public	int	standard_event_menu_event(
struct standard_event_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto618 == mb ) return(1);
		if (_Context->trigger_Auto619 == mb ) return(2);
		if (_Context->trigger_Auto620 == mb ) return(3);
		if (_Context->trigger_Auto621 == mb ) return(4);
		if (_Context->trigger_Auto622 == mb ) return(5);
		if (_Context->trigger_Auto623 == mb ) return(6);
		if (_Context->trigger_Auto624 == mb ) return(7);
		if (_Context->trigger_Auto625 == mb ) return(8);
		if (_Context->trigger_Auto626 == mb ) return(9);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 200 ) 
	&&  ( my >= 44 ) 
	&&  ( mx <= 344 ) 
	&&  ( my <= 64 )) {
		return(1); /* Auto618 */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 64 ) 
	&&  ( mx <= 344 ) 
	&&  ( my <= 84 )) {
		return(2); /* Auto619 */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 84 ) 
	&&  ( mx <= 344 ) 
	&&  ( my <= 104 )) {
		return(3); /* Auto620 */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 104 ) 
	&&  ( mx <= 344 ) 
	&&  ( my <= 124 )) {
		return(4); /* Auto621 */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 124 ) 
	&&  ( mx <= 344 ) 
	&&  ( my <= 144 )) {
		return(5); /* Auto622 */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 144 ) 
	&&  ( mx <= 344 ) 
	&&  ( my <= 164 )) {
		return(6); /* Auto623 */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 164 ) 
	&&  ( mx <= 344 ) 
	&&  ( my <= 184 )) {
		return(7); /* Auto624 */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 184 ) 
	&&  ( mx <= 344 ) 
	&&  ( my <= 204 )) {
		return(8); /* Auto625 */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 204 ) 
	&&  ( mx <= 344 ) 
	&&  ( my <= 224 )) {
		return(9); /* Auto626 */
		}

	return(-1);
}


public	int	standard_event_menu_focus(struct standard_event_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto618 */
				_Context->trigger_Auto618=visual_trigger_code(_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]));
				if (((_Context->status = visual_styled_element(200,44,144,20,GetWidgetStyle(3),_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]))) != 0)
) {
					visual_button(200,44,144,20,vfh[2],16,0,_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto618=visual_trigger_code(_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]));
				if (((_Context->status = visual_styled_element(200,44,144,20,GetWidgetStyle(2),_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]))) != 0)
) {
	visual_button(200,44,144,20,vfh[2],16,0,_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto619 */
				_Context->trigger_Auto619=visual_trigger_code(_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]));
				if (((_Context->status = visual_styled_element(200,64,144,20,GetWidgetStyle(3),_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]))) != 0)
) {
					visual_button(200,64,144,20,vfh[2],16,0,_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto619=visual_trigger_code(_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]));
				if (((_Context->status = visual_styled_element(200,64,144,20,GetWidgetStyle(2),_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]))) != 0)
) {
	visual_button(200,64,144,20,vfh[2],16,0,_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto620 */
				_Context->trigger_Auto620=visual_trigger_code(_Context->msg_Auto620[_Context->language],strlen(_Context->msg_Auto620[_Context->language]));
				if (((_Context->status = visual_styled_element(200,84,144,20,GetWidgetStyle(3),_Context->msg_Auto620[_Context->language],strlen(_Context->msg_Auto620[_Context->language]))) != 0)
) {
					visual_button(200,84,144,20,vfh[2],16,0,_Context->msg_Auto620[_Context->language],strlen(_Context->msg_Auto620[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto620=visual_trigger_code(_Context->msg_Auto620[_Context->language],strlen(_Context->msg_Auto620[_Context->language]));
				if (((_Context->status = visual_styled_element(200,84,144,20,GetWidgetStyle(2),_Context->msg_Auto620[_Context->language],strlen(_Context->msg_Auto620[_Context->language]))) != 0)
) {
	visual_button(200,84,144,20,vfh[2],16,0,_Context->msg_Auto620[_Context->language],strlen(_Context->msg_Auto620[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto621 */
				_Context->trigger_Auto621=visual_trigger_code(_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]));
				if (((_Context->status = visual_styled_element(200,104,144,20,GetWidgetStyle(3),_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]))) != 0)
) {
					visual_button(200,104,144,20,vfh[2],16,0,_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto621=visual_trigger_code(_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]));
				if (((_Context->status = visual_styled_element(200,104,144,20,GetWidgetStyle(2),_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]))) != 0)
) {
	visual_button(200,104,144,20,vfh[2],16,0,_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto622 */
				_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
				if (((_Context->status = visual_styled_element(200,124,144,20,GetWidgetStyle(3),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
					visual_button(200,124,144,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
				if (((_Context->status = visual_styled_element(200,124,144,20,GetWidgetStyle(2),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
	visual_button(200,124,144,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),32);
				}
				break;
			case	0x6 :
				/* Auto623 */
				_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
				if (((_Context->status = visual_styled_element(200,144,144,20,GetWidgetStyle(3),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
					visual_button(200,144,144,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
				if (((_Context->status = visual_styled_element(200,144,144,20,GetWidgetStyle(2),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
	visual_button(200,144,144,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),32);
				}
				break;
			case	0x7 :
				/* Auto624 */
				_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
				if (((_Context->status = visual_styled_element(200,164,144,20,GetWidgetStyle(3),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
					visual_button(200,164,144,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
				if (((_Context->status = visual_styled_element(200,164,144,20,GetWidgetStyle(2),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
	visual_button(200,164,144,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),32);
				}
				break;
			case	0x8 :
				/* Auto625 */
				_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
				if (((_Context->status = visual_styled_element(200,184,144,20,GetWidgetStyle(3),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
					visual_button(200,184,144,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
				if (((_Context->status = visual_styled_element(200,184,144,20,GetWidgetStyle(2),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
	visual_button(200,184,144,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),32);
				}
				break;
			case	0x9 :
				/* Auto626 */
				_Context->trigger_Auto626=visual_trigger_code(_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]));
				if (((_Context->status = visual_styled_element(200,204,144,20,GetWidgetStyle(3),_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]))) != 0)
) {
					visual_button(200,204,144,20,vfh[2],16,0,_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto626=visual_trigger_code(_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]));
				if (((_Context->status = visual_styled_element(200,204,144,20,GetWidgetStyle(2),_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]))) != 0)
) {
	visual_button(200,204,144,20,vfh[2],16,0,_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			standard_event_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=9;
			standard_event_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  184 )
				|| ( visual_event(6) <  32 )
				|| ( visual_event(7) >  360 )
				|| ( visual_event(6) >  236 )) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=standard_event_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto618 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto618=visual_trigger_code(_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]));
						if (((_Context->status = visual_styled_element(200,44,144,20,GetWidgetStyle(3),_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]))) != 0)
) {
							visual_button(200,44,144,20,vfh[2],16,0,_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto618=visual_trigger_code(_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]));
						if (((_Context->status = visual_styled_element(200,44,144,20,GetWidgetStyle(2),_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]))) != 0)
) {
	visual_button(200,44,144,20,vfh[2],16,0,_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto618_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto619 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto619=visual_trigger_code(_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]));
						if (((_Context->status = visual_styled_element(200,64,144,20,GetWidgetStyle(3),_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]))) != 0)
) {
							visual_button(200,64,144,20,vfh[2],16,0,_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto619=visual_trigger_code(_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]));
						if (((_Context->status = visual_styled_element(200,64,144,20,GetWidgetStyle(2),_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]))) != 0)
) {
	visual_button(200,64,144,20,vfh[2],16,0,_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto619_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto620 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto620=visual_trigger_code(_Context->msg_Auto620[_Context->language],strlen(_Context->msg_Auto620[_Context->language]));
						if (((_Context->status = visual_styled_element(200,84,144,20,GetWidgetStyle(3),_Context->msg_Auto620[_Context->language],strlen(_Context->msg_Auto620[_Context->language]))) != 0)
) {
							visual_button(200,84,144,20,vfh[2],16,0,_Context->msg_Auto620[_Context->language],strlen(_Context->msg_Auto620[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto620=visual_trigger_code(_Context->msg_Auto620[_Context->language],strlen(_Context->msg_Auto620[_Context->language]));
						if (((_Context->status = visual_styled_element(200,84,144,20,GetWidgetStyle(2),_Context->msg_Auto620[_Context->language],strlen(_Context->msg_Auto620[_Context->language]))) != 0)
) {
	visual_button(200,84,144,20,vfh[2],16,0,_Context->msg_Auto620[_Context->language],strlen(_Context->msg_Auto620[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto620_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto621 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto621=visual_trigger_code(_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]));
						if (((_Context->status = visual_styled_element(200,104,144,20,GetWidgetStyle(3),_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]))) != 0)
) {
							visual_button(200,104,144,20,vfh[2],16,0,_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto621=visual_trigger_code(_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]));
						if (((_Context->status = visual_styled_element(200,104,144,20,GetWidgetStyle(2),_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]))) != 0)
) {
	visual_button(200,104,144,20,vfh[2],16,0,_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto621_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto622 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
						if (((_Context->status = visual_styled_element(200,124,144,20,GetWidgetStyle(3),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
							visual_button(200,124,144,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
						if (((_Context->status = visual_styled_element(200,124,144,20,GetWidgetStyle(2),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
	visual_button(200,124,144,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto622_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto623 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
						if (((_Context->status = visual_styled_element(200,144,144,20,GetWidgetStyle(3),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
							visual_button(200,144,144,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
						if (((_Context->status = visual_styled_element(200,144,144,20,GetWidgetStyle(2),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
	visual_button(200,144,144,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto623_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Auto624 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
						if (((_Context->status = visual_styled_element(200,164,144,20,GetWidgetStyle(3),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
							visual_button(200,164,144,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
						if (((_Context->status = visual_styled_element(200,164,144,20,GetWidgetStyle(2),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
	visual_button(200,164,144,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto624_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Auto625 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
						if (((_Context->status = visual_styled_element(200,184,144,20,GetWidgetStyle(3),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
							visual_button(200,184,144,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
						if (((_Context->status = visual_styled_element(200,184,144,20,GetWidgetStyle(2),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
	visual_button(200,184,144,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto625_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Auto626 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto626=visual_trigger_code(_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]));
						if (((_Context->status = visual_styled_element(200,204,144,20,GetWidgetStyle(3),_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]))) != 0)
) {
							visual_button(200,204,144,20,vfh[2],16,0,_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto626=visual_trigger_code(_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]));
						if (((_Context->status = visual_styled_element(200,204,144,20,GetWidgetStyle(2),_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]))) != 0)
) {
	visual_button(200,204,144,20,vfh[2],16,0,_Context->msg_Auto626[_Context->language],strlen(_Context->msg_Auto626[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto626_event(_Context)) != -1) break;

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
				_Context->focus_item=9;
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

public	int	standard_event_menu()
{
	int	status=0;
	struct standard_event_menu_context * _Context=(struct standard_event_menu_context*) 0;
	status = standard_event_menu_create(&_Context);
	if ( status != 0) return(status);
	status = standard_event_menu_show(_Context);
		enter_modal();
	status = standard_event_menu_focus(_Context);
		leave_modal();
	status = standard_event_menu_hide(_Context);
	status = standard_event_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _evenmenu_c */
