
#ifndef _editmenu_c
#define _editmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : editmenu.xml                                             */
/* Target         : editmenu.c                                               */
/* Identification : 0.0-1177512019-5209.5208                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Frame   ""
#define en__Frame   ""
#define en_Auto621   "&Find..."
#define fr_Auto621   "&Rechercher..."
#define it_Auto621   "&Find..."
#define es_Auto621   "&Find..."
#define de_Auto621   "&Find..."
#define nl_Auto621   "&Find..."
#define pt_Auto621   "&Find..."
#define xx_Auto621   "&Find..."
#define en__Auto621   ""
#define fr__Auto621   ""
#define it__Auto621   ""
#define es__Auto621   ""
#define de__Auto621   ""
#define nl__Auto621   ""
#define pt__Auto621   ""
#define xx__Auto621   ""
#define en_Auto622   "&Replace..."
#define fr_Auto622   "Re&mplacer..."
#define it_Auto622   "&Replace..."
#define es_Auto622   "&Replace..."
#define de_Auto622   "&Replace..."
#define nl_Auto622   "&Replace..."
#define pt_Auto622   "&Replace..."
#define xx_Auto622   "&Replace..."
#define en__Auto622   ""
#define fr__Auto622   ""
#define it__Auto622   ""
#define es__Auto622   ""
#define de__Auto622   ""
#define nl__Auto622   ""
#define pt__Auto622   ""
#define xx__Auto622   ""
#define en_Auto623   "&Syntax..."
#define fr_Auto623   "&Syntaxe..."
#define it_Auto623   "&Syntax..."
#define es_Auto623   "&Syntax..."
#define de_Auto623   "&Syntax..."
#define nl_Auto623   "&Syntax..."
#define pt_Auto623   "&Syntax..."
#define xx_Auto623   "&Syntax..."
#define en__Auto623   ""
#define fr__Auto623   ""
#define it__Auto623   ""
#define es__Auto623   ""
#define de__Auto623   ""
#define nl__Auto623   ""
#define pt__Auto623   ""
#define xx__Auto623   ""
#define en_Auto624   "Resol&ve..."
#define fr_Auto624   "R‚&soudre..."
#define it_Auto624   "Resol&ve..."
#define es_Auto624   "Resol&ve..."
#define de_Auto624   "Resol&ve..."
#define nl_Auto624   "Resol&ve..."
#define pt_Auto624   "Resol&ve..."
#define xx_Auto624   "Resol&ve..."
#define en__Auto624   ""
#define fr__Auto624   ""
#define it__Auto624   ""
#define es__Auto624   ""
#define de__Auto624   ""
#define nl__Auto624   ""
#define pt__Auto624   ""
#define xx__Auto624   ""
#define en_Auto625   "S&earch..."
#define fr_Auto625   "Re&chercher fichier..."
#define it_Auto625   "S&earch..."
#define es_Auto625   "S&earch..."
#define de_Auto625   "S&earch..."
#define nl_Auto625   "S&earch..."
#define pt_Auto625   "S&earch..."
#define xx_Auto625   "S&earch..."
#define en__Auto625   ""
#define fr__Auto625   ""
#define it__Auto625   ""
#define es__Auto625   ""
#define de__Auto625   ""
#define nl__Auto625   ""
#define pt__Auto625   ""
#define xx__Auto625   ""

private struct text_editor_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * hint_Frame[8];
	int	s_Frame;
	void *	p_Frame;
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
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct text_editor_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = text_editor_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}

private int on_Frame_create(struct text_editor_menu_context * _Context) {
	mouse_move_on();
	return(-1);
}

public	int	text_editor_menu_create(struct text_editor_menu_context **cptr)
{

	int i;
	struct text_editor_menu_context * _Context=(struct text_editor_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct text_editor_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=5;
	_Context->hint_Frame[0]=en__Frame;
	_Context->s_Frame=0;
	_Context->p_Frame=visual_buffer(328,36,160+2,124+2);
	(void) on_Frame_create(_Context);
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
	_Context->hint_Auto621[1]=fr__Auto621;
	_Context->hint_Auto621[2]=it__Auto621;
	_Context->hint_Auto621[3]=es__Auto621;
	_Context->hint_Auto621[4]=de__Auto621;
	_Context->hint_Auto621[5]=nl__Auto621;
	_Context->hint_Auto621[6]=pt__Auto621;
	_Context->hint_Auto621[7]=xx__Auto621;
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
	_Context->hint_Auto622[1]=fr__Auto622;
	_Context->hint_Auto622[2]=it__Auto622;
	_Context->hint_Auto622[3]=es__Auto622;
	_Context->hint_Auto622[4]=de__Auto622;
	_Context->hint_Auto622[5]=nl__Auto622;
	_Context->hint_Auto622[6]=pt__Auto622;
	_Context->hint_Auto622[7]=xx__Auto622;
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
	_Context->hint_Auto623[1]=fr__Auto623;
	_Context->hint_Auto623[2]=it__Auto623;
	_Context->hint_Auto623[3]=es__Auto623;
	_Context->hint_Auto623[4]=de__Auto623;
	_Context->hint_Auto623[5]=nl__Auto623;
	_Context->hint_Auto623[6]=pt__Auto623;
	_Context->hint_Auto623[7]=xx__Auto623;
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
	_Context->hint_Auto624[1]=fr__Auto624;
	_Context->hint_Auto624[2]=it__Auto624;
	_Context->hint_Auto624[3]=es__Auto624;
	_Context->hint_Auto624[4]=de__Auto624;
	_Context->hint_Auto624[5]=nl__Auto624;
	_Context->hint_Auto624[6]=pt__Auto624;
	_Context->hint_Auto624[7]=xx__Auto624;
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
	_Context->hint_Auto625[1]=fr__Auto625;
	_Context->hint_Auto625[2]=it__Auto625;
	_Context->hint_Auto625[3]=es__Auto625;
	_Context->hint_Auto625[4]=de__Auto625;
	_Context->hint_Auto625[5]=nl__Auto625;
	_Context->hint_Auto625[6]=pt__Auto625;
	_Context->hint_Auto625[7]=xx__Auto625;
	return(0);
}

public 	int	text_editor_menu_hide(struct text_editor_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Frame != (void *) 0)
	&& (_Context->s_Frame != 0)) {
		(void)visual_buffer_put(_Context->p_Frame,328,36);
		_Context->s_Frame=0;
		}

	return(result);
}
private int on_Frame_remove(struct text_editor_menu_context * _Context) {
	mouse_move_off();
	return(-1);
}

public	int	text_editor_menu_remove(struct text_editor_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	(void) on_Frame_remove(_Context);
	if (_Context->p_Frame != (void *) 0)
		_Context->p_Frame = visual_drop(_Context->p_Frame);
	_Context=liberate(_Context);

	return(result);
}

public	int	text_editor_menu_show(struct text_editor_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if ((_Context->p_Frame != (void *) 0)
	&& (_Context->s_Frame == 0)) {
		(void)visual_buffer_get(_Context->p_Frame,328,36);
		_Context->s_Frame=1;
		}
	if (((_Context->status = visual_styled_element(328,36,160,124,GetWidgetStyle(1)," ",0)) != 0)
) {
		visual_filzone(328,36,160,124,27,11);
		}
	_Context->trigger_Auto621=visual_trigger_code(_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]));
	if (((_Context->status = visual_styled_element(344,48,128,20,GetWidgetStyle(2),_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]))) != 0)
) {
	visual_button(344,48,128,20,vfh[2],16,0,_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]),32);
		}
	_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
	if (((_Context->status = visual_styled_element(344,68,128,20,GetWidgetStyle(2),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
	visual_button(344,68,128,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),32);
		}
	_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
	if (((_Context->status = visual_styled_element(344,88,128,20,GetWidgetStyle(2),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
	visual_button(344,88,128,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),32);
		}
	_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
	if (((_Context->status = visual_styled_element(344,108,128,20,GetWidgetStyle(2),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
	visual_button(344,108,128,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),32);
		}
	_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
	if (((_Context->status = visual_styled_element(344,128,128,20,GetWidgetStyle(2),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
	visual_button(344,128,128,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),32);
		}
	visual_thaw(328,36,160,124);

	return(0);
}
private int on_Auto621_event(struct text_editor_menu_context * _Context) {
	int result;
		text_editor_menu_hide(_Context);
;
	on_Frame_remove(_Context);
	result=text_editor_find();
	on_Frame_create(_Context);
		text_editor_menu_show(_Context);
;
	return(27);
	return(-1);
}
private int on_Auto622_event(struct text_editor_menu_context * _Context) {
	int result;
		text_editor_menu_hide(_Context);
;
	on_Frame_remove(_Context);
	result=text_editor_replace();
	on_Frame_create(_Context);
		text_editor_menu_show(_Context);
;
	return(27);
	return(-1);
}
private int on_Auto623_event(struct text_editor_menu_context * _Context) {
	int result;
		text_editor_menu_hide(_Context);
;
	on_Frame_remove(_Context);
	result=syntax_composer();
	on_Frame_create(_Context);
		text_editor_menu_show(_Context);
;
	return(result);
	return(-1);
}
private int on_Auto624_event(struct text_editor_menu_context * _Context) {
	return(_EDIT_RESOLVE);
	return(-1);
}
private int on_Auto625_event(struct text_editor_menu_context * _Context) {
	int result;
		text_editor_menu_hide(_Context);
;
	on_Frame_remove(_Context);
	result=text_editor_search();
	on_Frame_create(_Context);
		text_editor_menu_show(_Context);
;
	return(result);
	return(-1);
}


public	int	text_editor_menu_event(
struct text_editor_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto621 == mb ) return(1);
		if (_Context->trigger_Auto622 == mb ) return(2);
		if (_Context->trigger_Auto623 == mb ) return(3);
		if (_Context->trigger_Auto624 == mb ) return(4);
		if (_Context->trigger_Auto625 == mb ) return(5);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 344 ) 
	&&  ( my >= 48 ) 
	&&  ( mx <= 472 ) 
	&&  ( my <= 68 )) {
		return(1); /* Auto621 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 68 ) 
	&&  ( mx <= 472 ) 
	&&  ( my <= 88 )) {
		return(2); /* Auto622 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 88 ) 
	&&  ( mx <= 472 ) 
	&&  ( my <= 108 )) {
		return(3); /* Auto623 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 108 ) 
	&&  ( mx <= 472 ) 
	&&  ( my <= 128 )) {
		return(4); /* Auto624 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 128 ) 
	&&  ( mx <= 472 ) 
	&&  ( my <= 148 )) {
		return(5); /* Auto625 */
		}

	return(-1);
}


public	int	text_editor_menu_focus(struct text_editor_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto621 */
				_Context->trigger_Auto621=visual_trigger_code(_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]));
				if (((_Context->status = visual_styled_element(344,48,128,20,GetWidgetStyle(3),_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]))) != 0)
) {
					visual_button(344,48,128,20,vfh[2],16,0,_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto621=visual_trigger_code(_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]));
				if (((_Context->status = visual_styled_element(344,48,128,20,GetWidgetStyle(2),_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]))) != 0)
) {
	visual_button(344,48,128,20,vfh[2],16,0,_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto622 */
				_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
				if (((_Context->status = visual_styled_element(344,68,128,20,GetWidgetStyle(3),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
					visual_button(344,68,128,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
				if (((_Context->status = visual_styled_element(344,68,128,20,GetWidgetStyle(2),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
	visual_button(344,68,128,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto623 */
				_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
				if (((_Context->status = visual_styled_element(344,88,128,20,GetWidgetStyle(3),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
					visual_button(344,88,128,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
				if (((_Context->status = visual_styled_element(344,88,128,20,GetWidgetStyle(2),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
	visual_button(344,88,128,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto624 */
				_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
				if (((_Context->status = visual_styled_element(344,108,128,20,GetWidgetStyle(3),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
					visual_button(344,108,128,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
				if (((_Context->status = visual_styled_element(344,108,128,20,GetWidgetStyle(2),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
	visual_button(344,108,128,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto625 */
				_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
				if (((_Context->status = visual_styled_element(344,128,128,20,GetWidgetStyle(3),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
					visual_button(344,128,128,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
				if (((_Context->status = visual_styled_element(344,128,128,20,GetWidgetStyle(2),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
	visual_button(344,128,128,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			text_editor_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=5;
			text_editor_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  328 )
				|| ( visual_event(6) <  36 )
				|| ( visual_event(7) >  488 )
				|| ( visual_event(6) >  160 )) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=text_editor_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto621 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto621=visual_trigger_code(_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]));
						if (((_Context->status = visual_styled_element(344,48,128,20,GetWidgetStyle(3),_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]))) != 0)
) {
							visual_button(344,48,128,20,vfh[2],16,0,_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto621=visual_trigger_code(_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]));
						if (((_Context->status = visual_styled_element(344,48,128,20,GetWidgetStyle(2),_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]))) != 0)
) {
	visual_button(344,48,128,20,vfh[2],16,0,_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto621_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto622 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
						if (((_Context->status = visual_styled_element(344,68,128,20,GetWidgetStyle(3),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
							visual_button(344,68,128,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
						if (((_Context->status = visual_styled_element(344,68,128,20,GetWidgetStyle(2),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
	visual_button(344,68,128,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto622_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto623 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
						if (((_Context->status = visual_styled_element(344,88,128,20,GetWidgetStyle(3),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
							visual_button(344,88,128,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
						if (((_Context->status = visual_styled_element(344,88,128,20,GetWidgetStyle(2),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
	visual_button(344,88,128,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto623_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto624 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
						if (((_Context->status = visual_styled_element(344,108,128,20,GetWidgetStyle(3),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
							visual_button(344,108,128,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
						if (((_Context->status = visual_styled_element(344,108,128,20,GetWidgetStyle(2),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
	visual_button(344,108,128,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto624_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto625 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
						if (((_Context->status = visual_styled_element(344,128,128,20,GetWidgetStyle(3),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
							visual_button(344,128,128,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
						if (((_Context->status = visual_styled_element(344,128,128,20,GetWidgetStyle(2),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
	visual_button(344,128,128,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto625_event(_Context)) != -1) break;

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
				_Context->focus_item=5;
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

public	int	text_editor_menu()
{
	int	status=0;
	struct text_editor_menu_context * _Context=(struct text_editor_menu_context*) 0;
	status = text_editor_menu_create(&_Context);
	if ( status != 0) return(status);
	status = text_editor_menu_show(_Context);
		enter_modal();
	status = text_editor_menu_focus(_Context);
		leave_modal();
	status = text_editor_menu_hide(_Context);
	status = text_editor_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _editmenu_c */
