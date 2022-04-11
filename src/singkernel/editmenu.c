
#ifndef _editmenu_c
#define _editmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : editmenu.xml  */
/* Target         : editmenu.c  */
/* Identification : 0.0-1100084464-2590.2589 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Frame   ""
#define en_Auto1607   "&Find"
#define fr_Auto1607   "&Rechercher"
#define it_Auto1607   "&Find"
#define es_Auto1607   "&Find"
#define de_Auto1607   "&Find"
#define nl_Auto1607   "&Find"
#define pt_Auto1607   "&Find"
#define xx_Auto1607   "&Find"
#define en_Auto1609   "&Replace"
#define fr_Auto1609   "R&emplacer"
#define it_Auto1609   "&Replace"
#define es_Auto1609   "&Replace"
#define de_Auto1609   "&Replace"
#define nl_Auto1609   "&Replace"
#define pt_Auto1609   "&Replace"
#define xx_Auto1609   "&Replace"
#define en_Auto1610   "&Syntax"
#define fr_Auto1610   "&Syntaxe"
#define it_Auto1610   "&Syntax"
#define es_Auto1610   "&Syntax"
#define de_Auto1610   "&Syntax"
#define nl_Auto1610   "&Syntax"
#define pt_Auto1610   "&Syntax"
#define xx_Auto1610   "&Syntax"
#define en_Auto1611   "S&earch"
#define fr_Auto1611   "Re&chercher Fich"
#define it_Auto1611   "S&earch"
#define es_Auto1611   "S&earch"
#define de_Auto1611   "S&earch"
#define nl_Auto1611   "S&earch"
#define pt_Auto1611   "S&earch"
#define xx_Auto1611   "S&earch"
static int	vfh[10];

private struct text_editor_menu_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	s_Frame;
	void *	p_Frame;
	char * msg_Auto1607[8];
	int	trigger_Auto1607;
	char * msg_Auto1609[8];
	int	trigger_Auto1609;
	char * msg_Auto1610[8];
	int	trigger_Auto1610;
	char * msg_Auto1611[8];
	int	trigger_Auto1611;
	char	signature[1];
	};
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
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct text_editor_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=4;
	_Context->s_Frame=0;
	_Context->p_Frame=visual_buffer(328,36,136,88);
	(void) on_Frame_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Auto1607[i]=" ";
	_Context->msg_Auto1607[0]=en_Auto1607;
	_Context->msg_Auto1607[1]=fr_Auto1607;
	_Context->msg_Auto1607[2]=it_Auto1607;
	_Context->msg_Auto1607[3]=es_Auto1607;
	_Context->msg_Auto1607[4]=de_Auto1607;
	_Context->msg_Auto1607[5]=nl_Auto1607;
	_Context->msg_Auto1607[6]=pt_Auto1607;
	_Context->msg_Auto1607[7]=xx_Auto1607;
	for (i=0; i < 8; i++)_Context->msg_Auto1609[i]=" ";
	_Context->msg_Auto1609[0]=en_Auto1609;
	_Context->msg_Auto1609[1]=fr_Auto1609;
	_Context->msg_Auto1609[2]=it_Auto1609;
	_Context->msg_Auto1609[3]=es_Auto1609;
	_Context->msg_Auto1609[4]=de_Auto1609;
	_Context->msg_Auto1609[5]=nl_Auto1609;
	_Context->msg_Auto1609[6]=pt_Auto1609;
	_Context->msg_Auto1609[7]=xx_Auto1609;
	for (i=0; i < 8; i++)_Context->msg_Auto1610[i]=" ";
	_Context->msg_Auto1610[0]=en_Auto1610;
	_Context->msg_Auto1610[1]=fr_Auto1610;
	_Context->msg_Auto1610[2]=it_Auto1610;
	_Context->msg_Auto1610[3]=es_Auto1610;
	_Context->msg_Auto1610[4]=de_Auto1610;
	_Context->msg_Auto1610[5]=nl_Auto1610;
	_Context->msg_Auto1610[6]=pt_Auto1610;
	_Context->msg_Auto1610[7]=xx_Auto1610;
	for (i=0; i < 8; i++)_Context->msg_Auto1611[i]=" ";
	_Context->msg_Auto1611[0]=en_Auto1611;
	_Context->msg_Auto1611[1]=fr_Auto1611;
	_Context->msg_Auto1611[2]=it_Auto1611;
	_Context->msg_Auto1611[3]=es_Auto1611;
	_Context->msg_Auto1611[4]=de_Auto1611;
	_Context->msg_Auto1611[5]=nl_Auto1611;
	_Context->msg_Auto1611[6]=pt_Auto1611;
	_Context->msg_Auto1611[7]=xx_Auto1611;
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
	visual_filzone(328,36,136,88,27,11);
	_Context->trigger_Auto1607=visual_trigger_code(_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]));
	visual_button(344,48,104,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
	_Context->trigger_Auto1609=visual_trigger_code(_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]));
	visual_button(344,64,104,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
	_Context->trigger_Auto1610=visual_trigger_code(_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]));
	visual_button(344,80,104,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
	_Context->trigger_Auto1611=visual_trigger_code(_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]));
	visual_button(344,96,104,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
	visual_thaw(328,36,136,88);

	return(0);
}
private int on_Auto1607_event(struct text_editor_menu_context * _Context) {
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
private int on_Auto1609_event(struct text_editor_menu_context * _Context) {
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
private int on_Auto1610_event(struct text_editor_menu_context * _Context) {
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
private int on_Auto1611_event(struct text_editor_menu_context * _Context) {
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
		if (_Context->trigger_Auto1607 == mb ) return(1);
		if (_Context->trigger_Auto1609 == mb ) return(2);
		if (_Context->trigger_Auto1610 == mb ) return(3);
		if (_Context->trigger_Auto1611 == mb ) return(4);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 344 ) 
	&&  ( my >= 48 ) 
	&&  ( mx <= 448 ) 
	&&  ( my <= 68 )) {
		return(1); /* Auto1607 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 64 ) 
	&&  ( mx <= 448 ) 
	&&  ( my <= 84 )) {
		return(2); /* Auto1609 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 80 ) 
	&&  ( mx <= 448 ) 
	&&  ( my <= 100 )) {
		return(3); /* Auto1610 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 96 ) 
	&&  ( mx <= 448 ) 
	&&  ( my <= 116 )) {
		return(4); /* Auto1611 */
		}

	return(-1);
}


public	int	text_editor_menu_focus(struct text_editor_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto1607 */
				visual_button(344,48,104,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(344,48,104,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
				break;
			case	0x2 :
				/* Auto1609 */
				visual_button(344,64,104,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(344,64,104,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
				break;
			case	0x3 :
				/* Auto1610 */
				visual_button(344,80,104,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(344,80,104,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
				break;
			case	0x4 :
				/* Auto1611 */
				visual_button(344,96,104,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(344,96,104,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
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
			_Context->focus_item=4;
			text_editor_menu_show(_Context);
			continue;
			case	0x100 :
				if (!( visual_event(1)  & _MIMO_ALT )) { 
					if (( visual_event(7) <  328 )
					|| ( visual_event(6) <  36 )
					|| ( visual_event(7) >  464 )
					|| ( visual_event(6) >  124 )) {
						if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
						else { return(256); }
						}
					}
				if ((retcode=text_editor_menu_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1607 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(344,48,104,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(344,48,104,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1607_event(_Context)) != -1) break;

							}
						continue;
					case	0x2 :
						/* Auto1609 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(344,64,104,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(344,64,104,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1609_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* Auto1610 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(344,80,104,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(344,80,104,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1610_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* Auto1611 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(344,96,104,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(344,96,104,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1611_event(_Context)) != -1) break;

							}
						continue;
					case	0xffffffff :
					default :
						_Context->focus_item=1;
					continue;
					}
				break;
			case	0x1b :
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


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

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
