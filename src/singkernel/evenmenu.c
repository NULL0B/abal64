
#ifndef _evenmenu_c
#define _evenmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : evenmenu.xml  */
/* Target         : evenmenu.c  */
/* Identification : 0.0-1100084428-2590.2589 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Auto1605   ""
#define en_Auto1607   "On&Create"
#define fr_Auto1607   "On&Create"
#define it_Auto1607   "On&Create"
#define es_Auto1607   "On&Create"
#define de_Auto1607   "On&Create"
#define nl_Auto1607   "On&Create"
#define pt_Auto1607   "On&Create"
#define xx_Auto1607   "On&Create"
#define en_Auto1609   "On&Remove"
#define fr_Auto1609   "On&Remove"
#define it_Auto1609   "On&Remove"
#define es_Auto1609   "On&Remove"
#define de_Auto1609   "On&Remove"
#define nl_Auto1609   "On&Remove"
#define pt_Auto1609   "On&Remove"
#define xx_Auto1609   "On&Remove"
#define en_Auto1610   "On&Show"
#define fr_Auto1610   "On&Show"
#define it_Auto1610   "On&Show"
#define es_Auto1610   "On&Show"
#define de_Auto1610   "On&Show"
#define nl_Auto1610   "On&Show"
#define pt_Auto1610   "On&Show"
#define xx_Auto1610   "On&Show"
#define en_Auto1611   "On&Hide"
#define fr_Auto1611   "On&Hide"
#define it_Auto1611   "On&Hide"
#define es_Auto1611   "On&Hide"
#define de_Auto1611   "On&Hide"
#define nl_Auto1611   "On&Hide"
#define pt_Auto1611   "On&Hide"
#define xx_Auto1611   "On&Hide"
#define en_Auto1726   "On&Focus"
#define fr_Auto1726   "On&Focus"
#define it_Auto1726   "On&Focus"
#define es_Auto1726   "On&Focus"
#define de_Auto1726   "On&Focus"
#define nl_Auto1726   "On&Focus"
#define pt_Auto1726   "On&Focus"
#define xx_Auto1726   "On&Focus"
#define en_Auto1728   "On&Lose"
#define fr_Auto1728   "On&Lose"
#define it_Auto1728   "On&Lose"
#define es_Auto1728   "On&Lose"
#define de_Auto1728   "On&Lose"
#define nl_Auto1728   "On&Lose"
#define pt_Auto1728   "On&Lose"
#define xx_Auto1728   "On&Lose"
#define en_Auto1612   "On&Event"
#define fr_Auto1612   "On&Event"
#define it_Auto1612   "On&Event"
#define es_Auto1612   "On&Event"
#define de_Auto1612   "On&Event"
#define nl_Auto1612   "On&Event"
#define pt_Auto1612   "On&Event"
#define xx_Auto1612   "On&Event"
#define en_Auto1730   "&Item Document"
#define fr_Auto1730   "&Item Document"
#define it_Auto1730   "&Item Document"
#define es_Auto1730   "&Item Document"
#define de_Auto1730   "&Item Document"
#define nl_Auto1730   "&Item Document"
#define pt_Auto1730   "&Item Document"
#define xx_Auto1730   "&Item Document"
#define en_Auto1629   "Form &Document"
#define fr_Auto1629   "Form &Document"
#define it_Auto1629   "Form &Document"
#define es_Auto1629   "Form &Document"
#define de_Auto1629   "Form &Document"
#define nl_Auto1629   "Form &Document"
#define pt_Auto1629   "Form &Document"
#define xx_Auto1629   "Form &Document"
static int	vfh[10];

private struct standard_event_menu_context {
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
	char * msg_Auto1726[8];
	int	trigger_Auto1726;
	char * msg_Auto1728[8];
	int	trigger_Auto1728;
	char * msg_Auto1612[8];
	int	trigger_Auto1612;
	char * msg_Auto1730[8];
	int	trigger_Auto1730;
	char * msg_Auto1629[8];
	int	trigger_Auto1629;
	char	signature[1];
	};

public	int	standard_event_menu_create(struct standard_event_menu_context **cptr)
{

	int i;
	struct standard_event_menu_context * _Context=(struct standard_event_menu_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct standard_event_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=9;
	_Context->s_Auto1605=0;
	_Context->p_Auto1605=visual_buffer(184,32,176,172);
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
	for (i=0; i < 8; i++)_Context->msg_Auto1726[i]=" ";
	_Context->msg_Auto1726[0]=en_Auto1726;
	_Context->msg_Auto1726[1]=fr_Auto1726;
	_Context->msg_Auto1726[2]=it_Auto1726;
	_Context->msg_Auto1726[3]=es_Auto1726;
	_Context->msg_Auto1726[4]=de_Auto1726;
	_Context->msg_Auto1726[5]=nl_Auto1726;
	_Context->msg_Auto1726[6]=pt_Auto1726;
	_Context->msg_Auto1726[7]=xx_Auto1726;
	for (i=0; i < 8; i++)_Context->msg_Auto1728[i]=" ";
	_Context->msg_Auto1728[0]=en_Auto1728;
	_Context->msg_Auto1728[1]=fr_Auto1728;
	_Context->msg_Auto1728[2]=it_Auto1728;
	_Context->msg_Auto1728[3]=es_Auto1728;
	_Context->msg_Auto1728[4]=de_Auto1728;
	_Context->msg_Auto1728[5]=nl_Auto1728;
	_Context->msg_Auto1728[6]=pt_Auto1728;
	_Context->msg_Auto1728[7]=xx_Auto1728;
	for (i=0; i < 8; i++)_Context->msg_Auto1612[i]=" ";
	_Context->msg_Auto1612[0]=en_Auto1612;
	_Context->msg_Auto1612[1]=fr_Auto1612;
	_Context->msg_Auto1612[2]=it_Auto1612;
	_Context->msg_Auto1612[3]=es_Auto1612;
	_Context->msg_Auto1612[4]=de_Auto1612;
	_Context->msg_Auto1612[5]=nl_Auto1612;
	_Context->msg_Auto1612[6]=pt_Auto1612;
	_Context->msg_Auto1612[7]=xx_Auto1612;
	for (i=0; i < 8; i++)_Context->msg_Auto1730[i]=" ";
	_Context->msg_Auto1730[0]=en_Auto1730;
	_Context->msg_Auto1730[1]=fr_Auto1730;
	_Context->msg_Auto1730[2]=it_Auto1730;
	_Context->msg_Auto1730[3]=es_Auto1730;
	_Context->msg_Auto1730[4]=de_Auto1730;
	_Context->msg_Auto1730[5]=nl_Auto1730;
	_Context->msg_Auto1730[6]=pt_Auto1730;
	_Context->msg_Auto1730[7]=xx_Auto1730;
	for (i=0; i < 8; i++)_Context->msg_Auto1629[i]=" ";
	_Context->msg_Auto1629[0]=en_Auto1629;
	_Context->msg_Auto1629[1]=fr_Auto1629;
	_Context->msg_Auto1629[2]=it_Auto1629;
	_Context->msg_Auto1629[3]=es_Auto1629;
	_Context->msg_Auto1629[4]=de_Auto1629;
	_Context->msg_Auto1629[5]=nl_Auto1629;
	_Context->msg_Auto1629[6]=pt_Auto1629;
	_Context->msg_Auto1629[7]=xx_Auto1629;
	return(0);
}

public 	int	standard_event_menu_hide(struct standard_event_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto1605 != (void *) 0)
	&& (_Context->s_Auto1605 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto1605,184,32);
		_Context->s_Auto1605=0;
		}

	return(result);
}

public	int	standard_event_menu_remove(struct standard_event_menu_context * _Context)
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

public	int	standard_event_menu_show(struct standard_event_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if ((_Context->p_Auto1605 != (void *) 0)
	&& (_Context->s_Auto1605 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto1605,184,32);
		_Context->s_Auto1605=1;
		}
	visual_filzone(184,32,176,172,27,11);
	_Context->trigger_Auto1607=visual_trigger_code(_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]));
	visual_button(200,44,144,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
	_Context->trigger_Auto1609=visual_trigger_code(_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]));
	visual_button(200,60,144,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
	_Context->trigger_Auto1610=visual_trigger_code(_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]));
	visual_button(200,76,144,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
	_Context->trigger_Auto1611=visual_trigger_code(_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]));
	visual_button(200,92,144,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
	_Context->trigger_Auto1726=visual_trigger_code(_Context->msg_Auto1726[_Context->language],strlen(_Context->msg_Auto1726[_Context->language]));
	visual_button(200,108,144,20,vfh[2],16,0,_Context->msg_Auto1726[_Context->language],strlen(_Context->msg_Auto1726[_Context->language]),32);
	_Context->trigger_Auto1728=visual_trigger_code(_Context->msg_Auto1728[_Context->language],strlen(_Context->msg_Auto1728[_Context->language]));
	visual_button(200,124,144,20,vfh[2],16,0,_Context->msg_Auto1728[_Context->language],strlen(_Context->msg_Auto1728[_Context->language]),32);
	_Context->trigger_Auto1612=visual_trigger_code(_Context->msg_Auto1612[_Context->language],strlen(_Context->msg_Auto1612[_Context->language]));
	visual_button(200,140,144,20,vfh[2],16,0,_Context->msg_Auto1612[_Context->language],strlen(_Context->msg_Auto1612[_Context->language]),32);
	_Context->trigger_Auto1730=visual_trigger_code(_Context->msg_Auto1730[_Context->language],strlen(_Context->msg_Auto1730[_Context->language]));
	visual_button(200,156,144,20,vfh[2],16,0,_Context->msg_Auto1730[_Context->language],strlen(_Context->msg_Auto1730[_Context->language]),32);
	_Context->trigger_Auto1629=visual_trigger_code(_Context->msg_Auto1629[_Context->language],strlen(_Context->msg_Auto1629[_Context->language]));
	visual_button(200,172,144,20,vfh[2],16,0,_Context->msg_Auto1629[_Context->language],strlen(_Context->msg_Auto1629[_Context->language]),32);
	visual_thaw(184,32,176,172);

	return(0);
}
private int on_Auto1607_event(struct standard_event_menu_context * _Context) {
	return(_EVENT_CREATE);
	return(-1);
}
private int on_Auto1609_event(struct standard_event_menu_context * _Context) {
	return(_EVENT_REMOVE);
	return(-1);
}
private int on_Auto1610_event(struct standard_event_menu_context * _Context) {
	return(_EVENT_SHOW);
	return(-1);
}
private int on_Auto1611_event(struct standard_event_menu_context * _Context) {
	return(_EVENT_HIDE);
	return(-1);
}
private int on_Auto1726_event(struct standard_event_menu_context * _Context) {
	return(_EVENT_FOCUS);
	return(-1);
}
private int on_Auto1728_event(struct standard_event_menu_context * _Context) {
	return(_EVENT_LOSE);
	return(-1);
}
private int on_Auto1612_event(struct standard_event_menu_context * _Context) {
	return(_EVENT_EVENT);
	return(-1);
}
private int on_Auto1730_event(struct standard_event_menu_context * _Context) {
	return(_EVENT_ITEMDOC);
	return(-1);
}
private int on_Auto1629_event(struct standard_event_menu_context * _Context) {
	return(_EVENT_FORMDOC);
	return(-1);
}


public	int	standard_event_menu_event(
struct standard_event_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto1607 == mb ) return(1);
		if (_Context->trigger_Auto1609 == mb ) return(2);
		if (_Context->trigger_Auto1610 == mb ) return(3);
		if (_Context->trigger_Auto1611 == mb ) return(4);
		if (_Context->trigger_Auto1726 == mb ) return(5);
		if (_Context->trigger_Auto1728 == mb ) return(6);
		if (_Context->trigger_Auto1612 == mb ) return(7);
		if (_Context->trigger_Auto1730 == mb ) return(8);
		if (_Context->trigger_Auto1629 == mb ) return(9);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 200 ) 
	&&  ( my >= 44 ) 
	&&  ( mx <= 344 ) 
	&&  ( my <= 64 )) {
		return(1); /* Auto1607 */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 60 ) 
	&&  ( mx <= 344 ) 
	&&  ( my <= 80 )) {
		return(2); /* Auto1609 */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 76 ) 
	&&  ( mx <= 344 ) 
	&&  ( my <= 96 )) {
		return(3); /* Auto1610 */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 92 ) 
	&&  ( mx <= 344 ) 
	&&  ( my <= 112 )) {
		return(4); /* Auto1611 */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 108 ) 
	&&  ( mx <= 344 ) 
	&&  ( my <= 128 )) {
		return(5); /* Auto1726 */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 124 ) 
	&&  ( mx <= 344 ) 
	&&  ( my <= 144 )) {
		return(6); /* Auto1728 */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 140 ) 
	&&  ( mx <= 344 ) 
	&&  ( my <= 160 )) {
		return(7); /* Auto1612 */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 156 ) 
	&&  ( mx <= 344 ) 
	&&  ( my <= 176 )) {
		return(8); /* Auto1730 */
		}
	if (( mx >= 200 ) 
	&&  ( my >= 172 ) 
	&&  ( mx <= 344 ) 
	&&  ( my <= 192 )) {
		return(9); /* Auto1629 */
		}

	return(-1);
}


public	int	standard_event_menu_focus(struct standard_event_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto1607 */
				visual_button(200,44,144,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(200,44,144,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
				break;
			case	0x2 :
				/* Auto1609 */
				visual_button(200,60,144,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(200,60,144,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
				break;
			case	0x3 :
				/* Auto1610 */
				visual_button(200,76,144,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(200,76,144,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
				break;
			case	0x4 :
				/* Auto1611 */
				visual_button(200,92,144,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(200,92,144,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
				break;
			case	0x5 :
				/* Auto1726 */
				visual_button(200,108,144,20,vfh[2],16,0,_Context->msg_Auto1726[_Context->language],strlen(_Context->msg_Auto1726[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(200,108,144,20,vfh[2],16,0,_Context->msg_Auto1726[_Context->language],strlen(_Context->msg_Auto1726[_Context->language]),32);
				break;
			case	0x6 :
				/* Auto1728 */
				visual_button(200,124,144,20,vfh[2],16,0,_Context->msg_Auto1728[_Context->language],strlen(_Context->msg_Auto1728[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(200,124,144,20,vfh[2],16,0,_Context->msg_Auto1728[_Context->language],strlen(_Context->msg_Auto1728[_Context->language]),32);
				break;
			case	0x7 :
				/* Auto1612 */
				visual_button(200,140,144,20,vfh[2],16,0,_Context->msg_Auto1612[_Context->language],strlen(_Context->msg_Auto1612[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(200,140,144,20,vfh[2],16,0,_Context->msg_Auto1612[_Context->language],strlen(_Context->msg_Auto1612[_Context->language]),32);
				break;
			case	0x8 :
				/* Auto1730 */
				visual_button(200,156,144,20,vfh[2],16,0,_Context->msg_Auto1730[_Context->language],strlen(_Context->msg_Auto1730[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(200,156,144,20,vfh[2],16,0,_Context->msg_Auto1730[_Context->language],strlen(_Context->msg_Auto1730[_Context->language]),32);
				break;
			case	0x9 :
				/* Auto1629 */
				visual_button(200,172,144,20,vfh[2],16,0,_Context->msg_Auto1629[_Context->language],strlen(_Context->msg_Auto1629[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(200,172,144,20,vfh[2],16,0,_Context->msg_Auto1629[_Context->language],strlen(_Context->msg_Auto1629[_Context->language]),32);
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
					|| ( visual_event(6) >  204 )) {
						if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
						else { return(256); }
						}
					}
				if ((retcode=standard_event_menu_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1607 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(200,44,144,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(200,44,144,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1607_event(_Context)) != -1) break;

							}
						continue;
					case	0x2 :
						/* Auto1609 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(200,60,144,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(200,60,144,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1609_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* Auto1610 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(200,76,144,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(200,76,144,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1610_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* Auto1611 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(200,92,144,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(200,92,144,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1611_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* Auto1726 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(200,108,144,20,vfh[2],16,0,_Context->msg_Auto1726[_Context->language],strlen(_Context->msg_Auto1726[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(200,108,144,20,vfh[2],16,0,_Context->msg_Auto1726[_Context->language],strlen(_Context->msg_Auto1726[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1726_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* Auto1728 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(200,124,144,20,vfh[2],16,0,_Context->msg_Auto1728[_Context->language],strlen(_Context->msg_Auto1728[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(200,124,144,20,vfh[2],16,0,_Context->msg_Auto1728[_Context->language],strlen(_Context->msg_Auto1728[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1728_event(_Context)) != -1) break;

							}
						continue;
					case	0x7 :
						/* Auto1612 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(200,140,144,20,vfh[2],16,0,_Context->msg_Auto1612[_Context->language],strlen(_Context->msg_Auto1612[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(200,140,144,20,vfh[2],16,0,_Context->msg_Auto1612[_Context->language],strlen(_Context->msg_Auto1612[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1612_event(_Context)) != -1) break;

							}
						continue;
					case	0x8 :
						/* Auto1730 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(200,156,144,20,vfh[2],16,0,_Context->msg_Auto1730[_Context->language],strlen(_Context->msg_Auto1730[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(200,156,144,20,vfh[2],16,0,_Context->msg_Auto1730[_Context->language],strlen(_Context->msg_Auto1730[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1730_event(_Context)) != -1) break;

							}
						continue;
					case	0x9 :
						/* Auto1629 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(200,172,144,20,vfh[2],16,0,_Context->msg_Auto1629[_Context->language],strlen(_Context->msg_Auto1629[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(200,172,144,20,vfh[2],16,0,_Context->msg_Auto1629[_Context->language],strlen(_Context->msg_Auto1629[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1629_event(_Context)) != -1) break;

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


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

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
