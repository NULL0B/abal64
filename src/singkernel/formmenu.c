
#ifndef _formmenu_c
#define _formmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : formmenu.xml  */
/* Target         : formmenu.c  */
/* Identification : 0.0-1100084446-2590.2589 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Frame   ""
#define fr_Frame   ""
#define en_Auto1607   "&Properties"
#define fr_Auto1607   "&PropriŠt‚s"
#define it_Auto1607   "&Properties"
#define es_Auto1607   "&Properties"
#define de_Auto1607   "&Properties"
#define nl_Auto1607   "&Properties"
#define pt_Auto1607   "&Properties"
#define xx_Auto1607   "&Properties"
#define en_Auto1609   "&Document"
#define fr_Auto1609   "&Document"
#define it_Auto1609   "&Document"
#define es_Auto1609   "&Document"
#define de_Auto1609   "&Document"
#define nl_Auto1609   "&Document"
#define pt_Auto1609   "&Document"
#define xx_Auto1609   "&Document"
#define en_Auto1610   "&ReNumerate"
#define fr_Auto1610   "&R‚numŠroter"
#define it_Auto1610   "&Re>Numerate"
#define es_Auto1610   "&Re>Numerate"
#define de_Auto1610   "&Re>Numerate"
#define nl_Auto1610   "&Re>Numerate"
#define pt_Auto1610   "&Re>Numerate"
#define xx_Auto1610   "&Re>Numerate"
#define en_Auto1611   "&Triggers"
#define fr_Auto1611   "R&acourcies"
#define it_Auto1611   "&Triggers"
#define es_Auto1611   "&Triggers"
#define de_Auto1611   "&Triggers"
#define nl_Auto1611   "&Triggers"
#define pt_Auto1611   "&Triggers"
#define xx_Auto1611   "&Triggers"
#define en_Auto1613   "&UnDo"
#define fr_Auto1613   "D‚&faire"
#define it_Auto1613   "&UnDo"
#define es_Auto1613   "&UnDo"
#define de_Auto1613   "&UnDo"
#define nl_Auto1613   "&UnDo"
#define pt_Auto1613   "&UnDo"
#define xx_Auto1613   "&UnDo"
#define en_Auto1614   "&Interface"
#define fr_Auto1614   "&Interface"
#define it_Auto1614   "&Interface"
#define es_Auto1614   "&Interface"
#define de_Auto1614   "&Interface"
#define nl_Auto1614   "&Interface"
#define pt_Auto1614   "&Interface"
#define xx_Auto1614   "&Interface"
static int	vfh[10];

private struct forms_editor_menu_context {
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
	char * msg_Auto1613[8];
	int	trigger_Auto1613;
	char * msg_Auto1614[8];
	int	trigger_Auto1614;
	char	signature[1];
	};
private int on_Frame_create(struct forms_editor_menu_context * _Context) {
	mouse_move_on();
	return(-1);
}

public	int	forms_editor_menu_create(struct forms_editor_menu_context **cptr)
{

	int i;
	struct forms_editor_menu_context * _Context=(struct forms_editor_menu_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct forms_editor_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=6;
	_Context->s_Frame=0;
	_Context->p_Frame=visual_buffer(328,32,168,124);
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
	for (i=0; i < 8; i++)_Context->msg_Auto1613[i]=" ";
	_Context->msg_Auto1613[0]=en_Auto1613;
	_Context->msg_Auto1613[1]=fr_Auto1613;
	_Context->msg_Auto1613[2]=it_Auto1613;
	_Context->msg_Auto1613[3]=es_Auto1613;
	_Context->msg_Auto1613[4]=de_Auto1613;
	_Context->msg_Auto1613[5]=nl_Auto1613;
	_Context->msg_Auto1613[6]=pt_Auto1613;
	_Context->msg_Auto1613[7]=xx_Auto1613;
	for (i=0; i < 8; i++)_Context->msg_Auto1614[i]=" ";
	_Context->msg_Auto1614[0]=en_Auto1614;
	_Context->msg_Auto1614[1]=fr_Auto1614;
	_Context->msg_Auto1614[2]=it_Auto1614;
	_Context->msg_Auto1614[3]=es_Auto1614;
	_Context->msg_Auto1614[4]=de_Auto1614;
	_Context->msg_Auto1614[5]=nl_Auto1614;
	_Context->msg_Auto1614[6]=pt_Auto1614;
	_Context->msg_Auto1614[7]=xx_Auto1614;
	return(0);
}

public 	int	forms_editor_menu_hide(struct forms_editor_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Frame != (void *) 0)
	&& (_Context->s_Frame != 0)) {
		(void)visual_buffer_put(_Context->p_Frame,328,32);
		_Context->s_Frame=0;
		}

	return(result);
}
private int on_Frame_remove(struct forms_editor_menu_context * _Context) {
	mouse_move_off();
	return(-1);
}

public	int	forms_editor_menu_remove(struct forms_editor_menu_context * _Context)
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

public	int	forms_editor_menu_show(struct forms_editor_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if ((_Context->p_Frame != (void *) 0)
	&& (_Context->s_Frame == 0)) {
		(void)visual_buffer_get(_Context->p_Frame,328,32);
		_Context->s_Frame=1;
		}
	visual_filzone(328,32,168,124,27,11);
	_Context->trigger_Auto1607=visual_trigger_code(_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]));
	visual_button(344,44,136,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
	_Context->trigger_Auto1609=visual_trigger_code(_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]));
	visual_button(344,60,136,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
	_Context->trigger_Auto1610=visual_trigger_code(_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]));
	visual_button(344,76,136,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
	_Context->trigger_Auto1611=visual_trigger_code(_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]));
	visual_button(344,92,136,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
	_Context->trigger_Auto1613=visual_trigger_code(_Context->msg_Auto1613[_Context->language],strlen(_Context->msg_Auto1613[_Context->language]));
	visual_button(344,108,136,20,vfh[2],16,0,_Context->msg_Auto1613[_Context->language],strlen(_Context->msg_Auto1613[_Context->language]),32);
	_Context->trigger_Auto1614=visual_trigger_code(_Context->msg_Auto1614[_Context->language],strlen(_Context->msg_Auto1614[_Context->language]));
	visual_button(344,124,136,20,vfh[2],16,0,_Context->msg_Auto1614[_Context->language],strlen(_Context->msg_Auto1614[_Context->language]),32);
	visual_thaw(328,32,168,124);

	return(0);
}
private int on_Auto1607_event(struct forms_editor_menu_context * _Context) {
	return(_FORM_PARA);
	return(-1);
}
private int on_Auto1609_event(struct forms_editor_menu_context * _Context) {
	int result;
		forms_editor_menu_hide(_Context);
;
	on_Frame_remove(_Context);
	result=page_parameters();
	on_Frame_create(_Context);
		forms_editor_menu_show(_Context);
;
	return(result);
	return(-1);
}
private int on_Auto1610_event(struct forms_editor_menu_context * _Context) {
	return(_FORM_NUMBER);
	return(-1);
}
private int on_Auto1611_event(struct forms_editor_menu_context * _Context) {
	return(_FORM_TRIGGER);
	return(-1);
}
private int on_Auto1613_event(struct forms_editor_menu_context * _Context) {
	return(_FORM_UNDO);
	return(-1);
}
private int on_Auto1614_event(struct forms_editor_menu_context * _Context) {
	return(_FORM_FACE);
	return(-1);
}


public	int	forms_editor_menu_event(
struct forms_editor_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto1607 == mb ) return(1);
		if (_Context->trigger_Auto1609 == mb ) return(2);
		if (_Context->trigger_Auto1610 == mb ) return(3);
		if (_Context->trigger_Auto1611 == mb ) return(4);
		if (_Context->trigger_Auto1613 == mb ) return(5);
		if (_Context->trigger_Auto1614 == mb ) return(6);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 344 ) 
	&&  ( my >= 44 ) 
	&&  ( mx <= 480 ) 
	&&  ( my <= 64 )) {
		return(1); /* Auto1607 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 60 ) 
	&&  ( mx <= 480 ) 
	&&  ( my <= 80 )) {
		return(2); /* Auto1609 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 76 ) 
	&&  ( mx <= 480 ) 
	&&  ( my <= 96 )) {
		return(3); /* Auto1610 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 92 ) 
	&&  ( mx <= 480 ) 
	&&  ( my <= 112 )) {
		return(4); /* Auto1611 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 108 ) 
	&&  ( mx <= 480 ) 
	&&  ( my <= 128 )) {
		return(5); /* Auto1613 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 124 ) 
	&&  ( mx <= 480 ) 
	&&  ( my <= 144 )) {
		return(6); /* Auto1614 */
		}

	return(-1);
}


public	int	forms_editor_menu_focus(struct forms_editor_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto1607 */
				visual_button(344,44,136,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(344,44,136,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
				break;
			case	0x2 :
				/* Auto1609 */
				visual_button(344,60,136,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(344,60,136,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
				break;
			case	0x3 :
				/* Auto1610 */
				visual_button(344,76,136,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(344,76,136,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
				break;
			case	0x4 :
				/* Auto1611 */
				visual_button(344,92,136,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(344,92,136,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
				break;
			case	0x5 :
				/* Auto1613 */
				visual_button(344,108,136,20,vfh[2],16,0,_Context->msg_Auto1613[_Context->language],strlen(_Context->msg_Auto1613[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(344,108,136,20,vfh[2],16,0,_Context->msg_Auto1613[_Context->language],strlen(_Context->msg_Auto1613[_Context->language]),32);
				break;
			case	0x6 :
				/* Auto1614 */
				visual_button(344,124,136,20,vfh[2],16,0,_Context->msg_Auto1614[_Context->language],strlen(_Context->msg_Auto1614[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(344,124,136,20,vfh[2],16,0,_Context->msg_Auto1614[_Context->language],strlen(_Context->msg_Auto1614[_Context->language]),32);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			forms_editor_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=6;
			forms_editor_menu_show(_Context);
			continue;
			case	0x100 :
				if (!( visual_event(1)  & _MIMO_ALT )) { 
					if (( visual_event(7) <  328 )
					|| ( visual_event(6) <  32 )
					|| ( visual_event(7) >  496 )
					|| ( visual_event(6) >  156 )) {
						if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
						else { return(256); }
						}
					}
				if ((retcode=forms_editor_menu_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1607 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(344,44,136,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(344,44,136,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1607_event(_Context)) != -1) break;

							}
						continue;
					case	0x2 :
						/* Auto1609 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(344,60,136,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(344,60,136,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1609_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* Auto1610 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(344,76,136,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(344,76,136,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1610_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* Auto1611 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(344,92,136,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(344,92,136,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1611_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* Auto1613 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(344,108,136,20,vfh[2],16,0,_Context->msg_Auto1613[_Context->language],strlen(_Context->msg_Auto1613[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(344,108,136,20,vfh[2],16,0,_Context->msg_Auto1613[_Context->language],strlen(_Context->msg_Auto1613[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1613_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* Auto1614 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(344,124,136,20,vfh[2],16,0,_Context->msg_Auto1614[_Context->language],strlen(_Context->msg_Auto1614[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(344,124,136,20,vfh[2],16,0,_Context->msg_Auto1614[_Context->language],strlen(_Context->msg_Auto1614[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1614_event(_Context)) != -1) break;

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


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	forms_editor_menu()
{
	int	status=0;
	struct forms_editor_menu_context * _Context=(struct forms_editor_menu_context*) 0;
	status = forms_editor_menu_create(&_Context);
	if ( status != 0) return(status);
	status = forms_editor_menu_show(_Context);
		enter_modal();
	status = forms_editor_menu_focus(_Context);
		leave_modal();
	status = forms_editor_menu_hide(_Context);
	status = forms_editor_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _formmenu_c */
