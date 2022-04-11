
#ifndef _optimenu_c
#define _optimenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : optimenu.xml  */
/* Target         : optimenu.c  */
/* Identification : 0.0-1100084435-2590.2589 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Frame   ""
#define en_Auto1607   "&Parameters"
#define fr_Auto1607   "&ParamŠtres"
#define it_Auto1607   "&Parameters"
#define es_Auto1607   "&Parameters"
#define de_Auto1607   "&Parameters"
#define nl_Auto1607   "&Parameters"
#define pt_Auto1607   "&Parameters"
#define xx_Auto1607   "&Parameters"
#define en_Auto1609   "&Refresh"
#define fr_Auto1609   "&R‚afficher"
#define it_Auto1609   "&Refresh"
#define es_Auto1609   "&Refresh"
#define de_Auto1609   "&Refresh"
#define nl_Auto1609   "&Refresh"
#define pt_Auto1609   "&Refresh"
#define xx_Auto1609   "&Refresh"
#define en_Auto1610   "&Configure"
#define fr_Auto1610   "&Configuration"
#define it_Auto1610   "&Configure"
#define es_Auto1610   "&Configure"
#define de_Auto1610   "&Configure"
#define nl_Auto1610   "&Configure"
#define pt_Auto1610   "&Configure"
#define xx_Auto1610   "&Configure"
#define en_Auto1611   "&Screen Capture"
#define fr_Auto1611   "C&apture ‚cran"
#define it_Auto1611   "&Screen Capture"
#define es_Auto1611   "&Screen Capture"
#define de_Auto1611   "&Screen Capture"
#define nl_Auto1611   "&Screen Capture"
#define pt_Auto1611   "&Screen Capture"
#define xx_Auto1611   "&Screen Capture"
#define en_Auto1675   "&Animate"
#define fr_Auto1675   "A&nimation"
#define it_Auto1675   "&Animate"
#define es_Auto1675   "&Animate"
#define de_Auto1675   "&Animate"
#define nl_Auto1675   "&Animate"
#define pt_Auto1675   "&Animate"
#define xx_Auto1675   "&Animate"
#define en_Auto1912   "&TreeView"
#define fr_Auto1912   "Ar&boresence"
#define it_Auto1912   "&Animate"
#define es_Auto1912   "&Animate"
#define de_Auto1912   "&Animate"
#define nl_Auto1912   "&Animate"
#define pt_Auto1912   "&Animate"
#define xx_Auto1912   "&Animate"
static int	vfh[10];

private struct standard_option_menu_context {
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
	char * msg_Auto1675[8];
	int	trigger_Auto1675;
	char * msg_Auto1912[8];
	int	trigger_Auto1912;
	char	signature[1];
	};
private int on_Frame_create(struct standard_option_menu_context * _Context) {
	mouse_move_on();
	return(-1);
}

public	int	standard_option_menu_create(struct standard_option_menu_context **cptr)
{

	int i;
	struct standard_option_menu_context * _Context=(struct standard_option_menu_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct standard_option_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=6;
	_Context->s_Frame=0;
	_Context->p_Frame=visual_buffer(256,32,184,120);
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
	for (i=0; i < 8; i++)_Context->msg_Auto1675[i]=" ";
	_Context->msg_Auto1675[0]=en_Auto1675;
	_Context->msg_Auto1675[1]=fr_Auto1675;
	_Context->msg_Auto1675[2]=it_Auto1675;
	_Context->msg_Auto1675[3]=es_Auto1675;
	_Context->msg_Auto1675[4]=de_Auto1675;
	_Context->msg_Auto1675[5]=nl_Auto1675;
	_Context->msg_Auto1675[6]=pt_Auto1675;
	_Context->msg_Auto1675[7]=xx_Auto1675;
	for (i=0; i < 8; i++)_Context->msg_Auto1912[i]=" ";
	_Context->msg_Auto1912[0]=en_Auto1912;
	_Context->msg_Auto1912[1]=fr_Auto1912;
	_Context->msg_Auto1912[2]=it_Auto1912;
	_Context->msg_Auto1912[3]=es_Auto1912;
	_Context->msg_Auto1912[4]=de_Auto1912;
	_Context->msg_Auto1912[5]=nl_Auto1912;
	_Context->msg_Auto1912[6]=pt_Auto1912;
	_Context->msg_Auto1912[7]=xx_Auto1912;
	return(0);
}

public 	int	standard_option_menu_hide(struct standard_option_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Frame != (void *) 0)
	&& (_Context->s_Frame != 0)) {
		(void)visual_buffer_put(_Context->p_Frame,256,32);
		_Context->s_Frame=0;
		}

	return(result);
}
private int on_Frame_remove(struct standard_option_menu_context * _Context) {
	mouse_move_off();
	return(-1);
}

public	int	standard_option_menu_remove(struct standard_option_menu_context * _Context)
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

public	int	standard_option_menu_show(struct standard_option_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if ((_Context->p_Frame != (void *) 0)
	&& (_Context->s_Frame == 0)) {
		(void)visual_buffer_get(_Context->p_Frame,256,32);
		_Context->s_Frame=1;
		}
	visual_filzone(256,32,184,120,27,11);
	_Context->trigger_Auto1607=visual_trigger_code(_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]));
	visual_button(272,44,152,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
	_Context->trigger_Auto1609=visual_trigger_code(_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]));
	visual_button(272,60,152,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
	_Context->trigger_Auto1610=visual_trigger_code(_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]));
	visual_button(272,76,152,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
	_Context->trigger_Auto1611=visual_trigger_code(_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]));
	visual_button(272,92,152,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
	_Context->trigger_Auto1675=visual_trigger_code(_Context->msg_Auto1675[_Context->language],strlen(_Context->msg_Auto1675[_Context->language]));
	visual_button(272,108,152,20,vfh[2],16,0,_Context->msg_Auto1675[_Context->language],strlen(_Context->msg_Auto1675[_Context->language]),32);
	_Context->trigger_Auto1912=visual_trigger_code(_Context->msg_Auto1912[_Context->language],strlen(_Context->msg_Auto1912[_Context->language]));
	visual_button(272,124,152,20,vfh[2],16,0,_Context->msg_Auto1912[_Context->language],strlen(_Context->msg_Auto1912[_Context->language]),32);
	visual_thaw(256,32,184,120);

	return(0);
}
private int on_Auto1607_event(struct standard_option_menu_context * _Context) {
	int result;
		standard_option_menu_hide(_Context);
;
	on_Frame_remove(_Context);
	result=general_parameters();
	on_Frame_create(_Context);
		standard_option_menu_show(_Context);
;
	return(result);
	return(-1);
}
private int on_Auto1609_event(struct standard_option_menu_context * _Context) {
	int result;
		standard_option_menu_hide(_Context);
;
	on_Frame_remove(_Context);
	result=menu_refresh();
	on_Frame_create(_Context);
		standard_option_menu_show(_Context);
;
	return(result);
	return(-1);
}
private int on_Auto1610_event(struct standard_option_menu_context * _Context) {
	int result;
		standard_option_menu_hide(_Context);
;
	on_Frame_remove(_Context);
	result=inspect_configuration();
	on_Frame_create(_Context);
		standard_option_menu_show(_Context);
;
	return(result);
		return(-1);
}
private int on_Auto1611_event(struct standard_option_menu_context * _Context) {
	int result;
		standard_option_menu_hide(_Context);
;
	on_Frame_remove(_Context);
	result=screen_capture();
	on_Frame_create(_Context);
		standard_option_menu_show(_Context);
;
	return(result);
	return(-1);
}
private int on_Auto1675_event(struct standard_option_menu_context * _Context) {
	int result;
		standard_option_menu_hide(_Context);
;
	on_Frame_remove(_Context);
	result=perform_animation();
	on_Frame_create(_Context);
		standard_option_menu_show(_Context);
;
	return(result);
	return(-1);
}
private int on_Auto1912_event(struct standard_option_menu_context * _Context) {
	int result;
		standard_option_menu_hide(_Context);
;
	on_Frame_remove(_Context);
	result=treeview_parameters();
	on_Frame_create(_Context);
		standard_option_menu_show(_Context);
;
	return(result);
	return(-1);
}


public	int	standard_option_menu_event(
struct standard_option_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto1607 == mb ) return(1);
		if (_Context->trigger_Auto1609 == mb ) return(2);
		if (_Context->trigger_Auto1610 == mb ) return(3);
		if (_Context->trigger_Auto1611 == mb ) return(4);
		if (_Context->trigger_Auto1675 == mb ) return(5);
		if (_Context->trigger_Auto1912 == mb ) return(6);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 272 ) 
	&&  ( my >= 44 ) 
	&&  ( mx <= 424 ) 
	&&  ( my <= 64 )) {
		return(1); /* Auto1607 */
		}
	if (( mx >= 272 ) 
	&&  ( my >= 60 ) 
	&&  ( mx <= 424 ) 
	&&  ( my <= 80 )) {
		return(2); /* Auto1609 */
		}
	if (( mx >= 272 ) 
	&&  ( my >= 76 ) 
	&&  ( mx <= 424 ) 
	&&  ( my <= 96 )) {
		return(3); /* Auto1610 */
		}
	if (( mx >= 272 ) 
	&&  ( my >= 92 ) 
	&&  ( mx <= 424 ) 
	&&  ( my <= 112 )) {
		return(4); /* Auto1611 */
		}
	if (( mx >= 272 ) 
	&&  ( my >= 108 ) 
	&&  ( mx <= 424 ) 
	&&  ( my <= 128 )) {
		return(5); /* Auto1675 */
		}
	if (( mx >= 272 ) 
	&&  ( my >= 124 ) 
	&&  ( mx <= 424 ) 
	&&  ( my <= 144 )) {
		return(6); /* Auto1912 */
		}

	return(-1);
}


public	int	standard_option_menu_focus(struct standard_option_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto1607 */
				visual_button(272,44,152,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(272,44,152,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
				break;
			case	0x2 :
				/* Auto1609 */
				visual_button(272,60,152,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(272,60,152,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
				break;
			case	0x3 :
				/* Auto1610 */
				visual_button(272,76,152,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(272,76,152,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
				break;
			case	0x4 :
				/* Auto1611 */
				visual_button(272,92,152,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(272,92,152,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
				break;
			case	0x5 :
				/* Auto1675 */
				visual_button(272,108,152,20,vfh[2],16,0,_Context->msg_Auto1675[_Context->language],strlen(_Context->msg_Auto1675[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(272,108,152,20,vfh[2],16,0,_Context->msg_Auto1675[_Context->language],strlen(_Context->msg_Auto1675[_Context->language]),32);
				break;
			case	0x6 :
				/* Auto1912 */
				visual_button(272,124,152,20,vfh[2],16,0,_Context->msg_Auto1912[_Context->language],strlen(_Context->msg_Auto1912[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(272,124,152,20,vfh[2],16,0,_Context->msg_Auto1912[_Context->language],strlen(_Context->msg_Auto1912[_Context->language]),32);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			standard_option_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=6;
			standard_option_menu_show(_Context);
			continue;
			case	0x100 :
				if (!( visual_event(1)  & _MIMO_ALT )) { 
					if (( visual_event(7) <  256 )
					|| ( visual_event(6) <  32 )
					|| ( visual_event(7) >  440 )
					|| ( visual_event(6) >  152 )) {
						if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
						else { return(256); }
						}
					}
				if ((retcode=standard_option_menu_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1607 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(272,44,152,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(272,44,152,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1607_event(_Context)) != -1) break;

							}
						continue;
					case	0x2 :
						/* Auto1609 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(272,60,152,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(272,60,152,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1609_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* Auto1610 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(272,76,152,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(272,76,152,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1610_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* Auto1611 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(272,92,152,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(272,92,152,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1611_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* Auto1675 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(272,108,152,20,vfh[2],16,0,_Context->msg_Auto1675[_Context->language],strlen(_Context->msg_Auto1675[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(272,108,152,20,vfh[2],16,0,_Context->msg_Auto1675[_Context->language],strlen(_Context->msg_Auto1675[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1675_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* Auto1912 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(272,124,152,20,vfh[2],16,0,_Context->msg_Auto1912[_Context->language],strlen(_Context->msg_Auto1912[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(272,124,152,20,vfh[2],16,0,_Context->msg_Auto1912[_Context->language],strlen(_Context->msg_Auto1912[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1912_event(_Context)) != -1) break;

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

public	int	standard_option_menu()
{
	int	status=0;
	struct standard_option_menu_context * _Context=(struct standard_option_menu_context*) 0;
	status = standard_option_menu_create(&_Context);
	if ( status != 0) return(status);
	status = standard_option_menu_show(_Context);
		enter_modal();
	status = standard_option_menu_focus(_Context);
		leave_modal();
	status = standard_option_menu_hide(_Context);
	status = standard_option_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _optimenu_c */
