
#ifndef _filemenu_c
#define _filemenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : filemenu.xml  */
/* Target         : filemenu.c  */
/* Identification : 0.0-1100084413-2590.2589 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Auto1605   ""
#define en_Auto1607   "&New"
#define fr_Auto1607   "&Nouveau"
#define it_Auto1607   "&New"
#define es_Auto1607   "&New"
#define de_Auto1607   "&New"
#define nl_Auto1607   "&New"
#define pt_Auto1607   "&New"
#define xx_Auto1607   "&New"
#define en_Auto1609   "&Save"
#define fr_Auto1609   "&Sauver"
#define it_Auto1609   "&Save"
#define es_Auto1609   "&Save"
#define de_Auto1609   "&Save"
#define nl_Auto1609   "&Save"
#define pt_Auto1609   "&Save"
#define xx_Auto1609   "&Save"
#define en_Auto1610   "S&ave As"
#define fr_Auto1610   "S&auver sur"
#define it_Auto1610   "S&ave As"
#define es_Auto1610   "S&ave As"
#define de_Auto1610   "S&ave As"
#define nl_Auto1610   "S&ave As"
#define pt_Auto1610   "S&ave As"
#define xx_Auto1610   "S&ave As"
#define en_Auto1611   "&Open"
#define fr_Auto1611   "&Ouvrir"
#define it_Auto1611   "&Open"
#define es_Auto1611   "&Open"
#define de_Auto1611   "&Open"
#define nl_Auto1611   "&Open"
#define pt_Auto1611   "&Open"
#define xx_Auto1611   "&Open"
#define en_Auto1712   "&Production"
#define fr_Auto1712   "&Production"
#define it_Auto1712   "&Production"
#define es_Auto1712   "&Production"
#define de_Auto1712   "&Production"
#define nl_Auto1712   "&Production"
#define pt_Auto1712   "&Production"
#define xx_Auto1712   "&Production"
#define en_Auto139   "&Compare"
#define fr_Auto139   "&Production"
#define it_Auto139   "&Production"
#define es_Auto139   "&Production"
#define de_Auto139   "&Production"
#define nl_Auto139   "&Production"
#define pt_Auto139   "&Production"
#define xx_Auto139   "&Production"
#define en_Auto1714   "&Drop"
#define fr_Auto1714   "&Fermer"
#define it_Auto1714   "&Drop"
#define es_Auto1714   "&Drop"
#define de_Auto1714   "&Drop"
#define nl_Auto1714   "&Drop"
#define pt_Auto1714   "&Drop"
#define xx_Auto1714   "&Drop"
#define en_Auto1612   "&Quit"
#define fr_Auto1612   "&Quitter"
#define it_Auto1612   "&Quit"
#define es_Auto1612   "&Quit"
#define de_Auto1612   "&Quit"
#define nl_Auto1612   "&Quit"
#define pt_Auto1612   "&Quit"
#define xx_Auto1612   "&Quit"
static int	vfh[10];

private struct standard_file_menu_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	s_Auto1605;
	void *	p_Auto1605;
	char * msg_Auto1607[8];
	int	trigger_Auto1607;
	char * msg_Auto1609[8];
	int	trigger_Auto1609;
	char * msg_Auto1610[8];
	int	trigger_Auto1610;
	char * msg_Auto1611[8];
	int	trigger_Auto1611;
	char * msg_Auto1712[8];
	int	trigger_Auto1712;
	char * msg_Auto139[8];
	int	trigger_Auto139;
	char * msg_Auto1714[8];
	int	trigger_Auto1714;
	char * msg_Auto1612[8];
	int	trigger_Auto1612;
	char	signature[1];
	};

public	int	standard_file_menu_create(struct standard_file_menu_context **cptr)
{

	int i;
	struct standard_file_menu_context * _Context=(struct standard_file_menu_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct standard_file_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=8;
	_Context->s_Auto1605=0;
	_Context->p_Auto1605=visual_buffer(56,32,168,156);
	mouse_move_on();
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
	for (i=0; i < 8; i++)_Context->msg_Auto1712[i]=" ";
	_Context->msg_Auto1712[0]=en_Auto1712;
	_Context->msg_Auto1712[1]=fr_Auto1712;
	_Context->msg_Auto1712[2]=it_Auto1712;
	_Context->msg_Auto1712[3]=es_Auto1712;
	_Context->msg_Auto1712[4]=de_Auto1712;
	_Context->msg_Auto1712[5]=nl_Auto1712;
	_Context->msg_Auto1712[6]=pt_Auto1712;
	_Context->msg_Auto1712[7]=xx_Auto1712;
	for (i=0; i < 8; i++)_Context->msg_Auto139[i]=" ";
	_Context->msg_Auto139[0]=en_Auto139;
	_Context->msg_Auto139[1]=fr_Auto139;
	_Context->msg_Auto139[2]=it_Auto139;
	_Context->msg_Auto139[3]=es_Auto139;
	_Context->msg_Auto139[4]=de_Auto139;
	_Context->msg_Auto139[5]=nl_Auto139;
	_Context->msg_Auto139[6]=pt_Auto139;
	_Context->msg_Auto139[7]=xx_Auto139;
	for (i=0; i < 8; i++)_Context->msg_Auto1714[i]=" ";
	_Context->msg_Auto1714[0]=en_Auto1714;
	_Context->msg_Auto1714[1]=fr_Auto1714;
	_Context->msg_Auto1714[2]=it_Auto1714;
	_Context->msg_Auto1714[3]=es_Auto1714;
	_Context->msg_Auto1714[4]=de_Auto1714;
	_Context->msg_Auto1714[5]=nl_Auto1714;
	_Context->msg_Auto1714[6]=pt_Auto1714;
	_Context->msg_Auto1714[7]=xx_Auto1714;
	for (i=0; i < 8; i++)_Context->msg_Auto1612[i]=" ";
	_Context->msg_Auto1612[0]=en_Auto1612;
	_Context->msg_Auto1612[1]=fr_Auto1612;
	_Context->msg_Auto1612[2]=it_Auto1612;
	_Context->msg_Auto1612[3]=es_Auto1612;
	_Context->msg_Auto1612[4]=de_Auto1612;
	_Context->msg_Auto1612[5]=nl_Auto1612;
	_Context->msg_Auto1612[6]=pt_Auto1612;
	_Context->msg_Auto1612[7]=xx_Auto1612;
	return(0);
}

public 	int	standard_file_menu_hide(struct standard_file_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto1605 != (void *) 0)
	&& (_Context->s_Auto1605 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto1605,56,32);
		_Context->s_Auto1605=0;
		}

	return(result);
}

public	int	standard_file_menu_remove(struct standard_file_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	mouse_move_off();
	if (_Context->p_Auto1605 != (void *) 0)
		_Context->p_Auto1605 = visual_drop(_Context->p_Auto1605);
	_Context=liberate(_Context);

	return(result);
}

public	int	standard_file_menu_show(struct standard_file_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if ((_Context->p_Auto1605 != (void *) 0)
	&& (_Context->s_Auto1605 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto1605,56,32);
		_Context->s_Auto1605=1;
		}
	visual_filzone(56,32,168,156,27,11);
	_Context->trigger_Auto1607=visual_trigger_code(_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]));
	visual_button(72,44,136,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
	_Context->trigger_Auto1609=visual_trigger_code(_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]));
	visual_button(72,60,136,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
	_Context->trigger_Auto1610=visual_trigger_code(_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]));
	visual_button(72,76,136,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
	_Context->trigger_Auto1611=visual_trigger_code(_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]));
	visual_button(72,92,136,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
	_Context->trigger_Auto1712=visual_trigger_code(_Context->msg_Auto1712[_Context->language],strlen(_Context->msg_Auto1712[_Context->language]));
	visual_button(72,108,136,20,vfh[2],16,0,_Context->msg_Auto1712[_Context->language],strlen(_Context->msg_Auto1712[_Context->language]),32);
	_Context->trigger_Auto139=visual_trigger_code(_Context->msg_Auto139[_Context->language],strlen(_Context->msg_Auto139[_Context->language]));
	visual_button(72,124,136,20,vfh[2],16,0,_Context->msg_Auto139[_Context->language],strlen(_Context->msg_Auto139[_Context->language]),32);
	_Context->trigger_Auto1714=visual_trigger_code(_Context->msg_Auto1714[_Context->language],strlen(_Context->msg_Auto1714[_Context->language]));
	visual_button(72,140,136,20,vfh[2],16,0,_Context->msg_Auto1714[_Context->language],strlen(_Context->msg_Auto1714[_Context->language]),32);
	_Context->trigger_Auto1612=visual_trigger_code(_Context->msg_Auto1612[_Context->language],strlen(_Context->msg_Auto1612[_Context->language]));
	visual_button(72,156,136,20,vfh[2],16,0,_Context->msg_Auto1612[_Context->language],strlen(_Context->msg_Auto1612[_Context->language]),32);
	visual_thaw(56,32,168,156);

	return(0);
}
private int on_Auto1607_event(struct standard_file_menu_context * _Context) {
	return(_FILE_NEW);
	return(-1);
}
private int on_Auto1609_event(struct standard_file_menu_context * _Context) {
	return(_FILE_QSAVE);
	return(-1);
}
private int on_Auto1610_event(struct standard_file_menu_context * _Context) {
	return(_FILE_SAVE);
	return(-1);
}
private int on_Auto1611_event(struct standard_file_menu_context * _Context) {
	return(_FILE_LOAD);
	return(-1);
}
private int on_Auto1712_event(struct standard_file_menu_context * _Context) {
	return(_FILE_PRODUCE);
	return(-1);
}
private int on_Auto139_event(struct standard_file_menu_context * _Context) {
	return(_FILE_COMPARE);
	return(-1);
}
private int on_Auto1714_event(struct standard_file_menu_context * _Context) {
	return(_FILE_DROP);
	return(-1);
}
private int on_Auto1612_event(struct standard_file_menu_context * _Context) {
	return(_LEAVE_SING);
	return(-1);
}


public	int	standard_file_menu_event(
struct standard_file_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto1607 == mb ) return(1);
		if (_Context->trigger_Auto1609 == mb ) return(2);
		if (_Context->trigger_Auto1610 == mb ) return(3);
		if (_Context->trigger_Auto1611 == mb ) return(4);
		if (_Context->trigger_Auto1712 == mb ) return(5);
		if (_Context->trigger_Auto139 == mb ) return(6);
		if (_Context->trigger_Auto1714 == mb ) return(7);
		if (_Context->trigger_Auto1612 == mb ) return(8);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 72 ) 
	&&  ( my >= 44 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 64 )) {
		return(1); /* Auto1607 */
		}
	if (( mx >= 72 ) 
	&&  ( my >= 60 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 80 )) {
		return(2); /* Auto1609 */
		}
	if (( mx >= 72 ) 
	&&  ( my >= 76 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 96 )) {
		return(3); /* Auto1610 */
		}
	if (( mx >= 72 ) 
	&&  ( my >= 92 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 112 )) {
		return(4); /* Auto1611 */
		}
	if (( mx >= 72 ) 
	&&  ( my >= 108 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 128 )) {
		return(5); /* Auto1712 */
		}
	if (( mx >= 72 ) 
	&&  ( my >= 124 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 144 )) {
		return(6); /* Auto139 */
		}
	if (( mx >= 72 ) 
	&&  ( my >= 140 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 160 )) {
		return(7); /* Auto1714 */
		}
	if (( mx >= 72 ) 
	&&  ( my >= 156 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 176 )) {
		return(8); /* Auto1612 */
		}

	return(-1);
}


public	int	standard_file_menu_focus(struct standard_file_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto1607 */
				visual_button(72,44,136,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(72,44,136,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
				break;
			case	0x2 :
				/* Auto1609 */
				visual_button(72,60,136,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(72,60,136,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
				break;
			case	0x3 :
				/* Auto1610 */
				visual_button(72,76,136,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(72,76,136,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
				break;
			case	0x4 :
				/* Auto1611 */
				visual_button(72,92,136,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(72,92,136,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
				break;
			case	0x5 :
				/* Auto1712 */
				visual_button(72,108,136,20,vfh[2],16,0,_Context->msg_Auto1712[_Context->language],strlen(_Context->msg_Auto1712[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(72,108,136,20,vfh[2],16,0,_Context->msg_Auto1712[_Context->language],strlen(_Context->msg_Auto1712[_Context->language]),32);
				break;
			case	0x6 :
				/* Auto139 */
				visual_button(72,124,136,20,vfh[2],16,0,_Context->msg_Auto139[_Context->language],strlen(_Context->msg_Auto139[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(72,124,136,20,vfh[2],16,0,_Context->msg_Auto139[_Context->language],strlen(_Context->msg_Auto139[_Context->language]),32);
				break;
			case	0x7 :
				/* Auto1714 */
				visual_button(72,140,136,20,vfh[2],16,0,_Context->msg_Auto1714[_Context->language],strlen(_Context->msg_Auto1714[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(72,140,136,20,vfh[2],16,0,_Context->msg_Auto1714[_Context->language],strlen(_Context->msg_Auto1714[_Context->language]),32);
				break;
			case	0x8 :
				/* Auto1612 */
				visual_button(72,156,136,20,vfh[2],16,0,_Context->msg_Auto1612[_Context->language],strlen(_Context->msg_Auto1612[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(72,156,136,20,vfh[2],16,0,_Context->msg_Auto1612[_Context->language],strlen(_Context->msg_Auto1612[_Context->language]),32);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			standard_file_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=8;
			standard_file_menu_show(_Context);
			continue;
			case	0x100 :
				if (!( visual_event(1)  & _MIMO_ALT )) { 
					if (( visual_event(7) <  56 )
					|| ( visual_event(6) <  32 )
					|| ( visual_event(7) >  224 )
					|| ( visual_event(6) >  188 )) {
						if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
						else { return(256); }
						}
					}
				if ((retcode=standard_file_menu_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1607 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(72,44,136,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(72,44,136,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1607_event(_Context)) != -1) break;

							}
						continue;
					case	0x2 :
						/* Auto1609 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(72,60,136,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(72,60,136,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1609_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* Auto1610 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(72,76,136,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(72,76,136,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1610_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* Auto1611 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(72,92,136,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(72,92,136,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1611_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* Auto1712 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(72,108,136,20,vfh[2],16,0,_Context->msg_Auto1712[_Context->language],strlen(_Context->msg_Auto1712[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(72,108,136,20,vfh[2],16,0,_Context->msg_Auto1712[_Context->language],strlen(_Context->msg_Auto1712[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1712_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* Auto139 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(72,124,136,20,vfh[2],16,0,_Context->msg_Auto139[_Context->language],strlen(_Context->msg_Auto139[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(72,124,136,20,vfh[2],16,0,_Context->msg_Auto139[_Context->language],strlen(_Context->msg_Auto139[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto139_event(_Context)) != -1) break;

							}
						continue;
					case	0x7 :
						/* Auto1714 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(72,140,136,20,vfh[2],16,0,_Context->msg_Auto1714[_Context->language],strlen(_Context->msg_Auto1714[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(72,140,136,20,vfh[2],16,0,_Context->msg_Auto1714[_Context->language],strlen(_Context->msg_Auto1714[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1714_event(_Context)) != -1) break;

							}
						continue;
					case	0x8 :
						/* Auto1612 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(72,156,136,20,vfh[2],16,0,_Context->msg_Auto1612[_Context->language],strlen(_Context->msg_Auto1612[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(72,156,136,20,vfh[2],16,0,_Context->msg_Auto1612[_Context->language],strlen(_Context->msg_Auto1612[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1612_event(_Context)) != -1) break;

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
				_Context->focus_item=8;
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

public	int	standard_file_menu()
{
	int	status=0;
	struct standard_file_menu_context * _Context=(struct standard_file_menu_context*) 0;
	status = standard_file_menu_create(&_Context);
	if ( status != 0) return(status);
	status = standard_file_menu_show(_Context);
		enter_modal();
	status = standard_file_menu_focus(_Context);
		leave_modal();
	status = standard_file_menu_hide(_Context);
	status = standard_file_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _filemenu_c */
