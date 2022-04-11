
#ifndef _viewmenu_c
#define _viewmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : viewmenu.xml  */
/* Target         : viewmenu.c  */
/* Identification : 0.0-1100084421-2590.2589 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Frame   ""
#define en_Auto1607   "&Run"
#define fr_Auto1607   "&Executer"
#define it_Auto1607   "&Run"
#define es_Auto1607   "&Run"
#define de_Auto1607   "&Run"
#define nl_Auto1607   "&Run"
#define pt_Auto1607   "&Run"
#define xx_Auto1607   "&Run"
#define en_Auto1609   "&Text"
#define fr_Auto1609   "&Texte"
#define it_Auto1609   "&Text"
#define es_Auto1609   "&Text"
#define de_Auto1609   "&Text"
#define nl_Auto1609   "&Text"
#define pt_Auto1609   "&Text"
#define xx_Auto1609   "&Text"
#define en_Auto1610   "&Image"
#define fr_Auto1610   "&Image"
#define it_Auto1610   "&Image"
#define es_Auto1610   "&Image"
#define de_Auto1610   "&Image"
#define nl_Auto1610   "&Image"
#define pt_Auto1610   "&Image"
#define xx_Auto1610   "&Image"
#define en_Auto1611   "&Font"
#define fr_Auto1611   "&Fonte"
#define it_Auto1611   "&Font"
#define es_Auto1611   "&Font"
#define de_Auto1611   "&Font"
#define nl_Auto1611   "&Font"
#define pt_Auto1611   "&Font"
#define xx_Auto1611   "&Font"
#define en_Auto1613   "&Properties"
#define fr_Auto1613   "&PropriŠt‚s"
#define it_Auto1613   "&Production"
#define es_Auto1613   "&Production"
#define de_Auto1613   "&Produktion"
#define nl_Auto1613   "&Production"
#define pt_Auto1613   "&Production"
#define xx_Auto1613   "&Production"
#define en_Auto1731   "&Visual"
#define fr_Auto1731   "&Visuelle"
#define it_Auto1731   "&Visual"
#define es_Auto1731   "&Visual"
#define de_Auto1731   "&Visual"
#define nl_Auto1731   "&Visual"
#define pt_Auto1731   "&Visual"
#define xx_Auto1731   "&Visual"
#define en_Auto1725   "&DataBase"
#define fr_Auto1725   "&Base de Donn‚es"
#define it_Auto1725   "&DataBase"
#define es_Auto1725   "&DataBase"
#define de_Auto1725   "&DataBase"
#define nl_Auto1725   "&DataBase"
#define pt_Auto1725   "&DataBase"
#define xx_Auto1725   "&DataBase"
#define en_Auto1729   "Tr&eeView"
#define fr_Auto1729   "&Arboresence"
#define it_Auto1729   "Tr&eeView"
#define es_Auto1729   "Tr&eeView"
#define de_Auto1729   "Tr&eeView"
#define nl_Auto1729   "Tr&eeView"
#define pt_Auto1729   "Tr&eeView"
#define xx_Auto1729   "Tr&eeView"
#define en_Auto1727   "&Application"
#define fr_Auto1727   "App&lication"
#define it_Auto1727   "&Application"
#define es_Auto1727   "&Application"
#define de_Auto1727   "&Application"
#define nl_Auto1727   "&Application"
#define pt_Auto1727   "&Application"
#define xx_Auto1727   "&Application"
static int	vfh[10];

private struct standard_view_menu_context {
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
	char * msg_Auto1731[8];
	int	trigger_Auto1731;
	char * msg_Auto1725[8];
	int	trigger_Auto1725;
	char * msg_Auto1729[8];
	int	trigger_Auto1729;
	char * msg_Auto1727[8];
	int	trigger_Auto1727;
	char	signature[1];
	};
private int on_Frame_create(struct standard_view_menu_context * _Context) {
	mouse_move_on();
	return(-1);
}

public	int	standard_view_menu_create(struct standard_view_menu_context **cptr)
{

	int i;
	struct standard_view_menu_context * _Context=(struct standard_view_menu_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct standard_view_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=9;
	_Context->s_Frame=0;
	_Context->p_Frame=visual_buffer(128,32,144,172);
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
	for (i=0; i < 8; i++)_Context->msg_Auto1731[i]=" ";
	_Context->msg_Auto1731[0]=en_Auto1731;
	_Context->msg_Auto1731[1]=fr_Auto1731;
	_Context->msg_Auto1731[2]=it_Auto1731;
	_Context->msg_Auto1731[3]=es_Auto1731;
	_Context->msg_Auto1731[4]=de_Auto1731;
	_Context->msg_Auto1731[5]=nl_Auto1731;
	_Context->msg_Auto1731[6]=pt_Auto1731;
	_Context->msg_Auto1731[7]=xx_Auto1731;
	for (i=0; i < 8; i++)_Context->msg_Auto1725[i]=" ";
	_Context->msg_Auto1725[0]=en_Auto1725;
	_Context->msg_Auto1725[1]=fr_Auto1725;
	_Context->msg_Auto1725[2]=it_Auto1725;
	_Context->msg_Auto1725[3]=es_Auto1725;
	_Context->msg_Auto1725[4]=de_Auto1725;
	_Context->msg_Auto1725[5]=nl_Auto1725;
	_Context->msg_Auto1725[6]=pt_Auto1725;
	_Context->msg_Auto1725[7]=xx_Auto1725;
	for (i=0; i < 8; i++)_Context->msg_Auto1729[i]=" ";
	_Context->msg_Auto1729[0]=en_Auto1729;
	_Context->msg_Auto1729[1]=fr_Auto1729;
	_Context->msg_Auto1729[2]=it_Auto1729;
	_Context->msg_Auto1729[3]=es_Auto1729;
	_Context->msg_Auto1729[4]=de_Auto1729;
	_Context->msg_Auto1729[5]=nl_Auto1729;
	_Context->msg_Auto1729[6]=pt_Auto1729;
	_Context->msg_Auto1729[7]=xx_Auto1729;
	for (i=0; i < 8; i++)_Context->msg_Auto1727[i]=" ";
	_Context->msg_Auto1727[0]=en_Auto1727;
	_Context->msg_Auto1727[1]=fr_Auto1727;
	_Context->msg_Auto1727[2]=it_Auto1727;
	_Context->msg_Auto1727[3]=es_Auto1727;
	_Context->msg_Auto1727[4]=de_Auto1727;
	_Context->msg_Auto1727[5]=nl_Auto1727;
	_Context->msg_Auto1727[6]=pt_Auto1727;
	_Context->msg_Auto1727[7]=xx_Auto1727;
	return(0);
}

public 	int	standard_view_menu_hide(struct standard_view_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Frame != (void *) 0)
	&& (_Context->s_Frame != 0)) {
		(void)visual_buffer_put(_Context->p_Frame,128,32);
		_Context->s_Frame=0;
		}

	return(result);
}
private int on_Frame_remove(struct standard_view_menu_context * _Context) {
	mouse_move_off();
	return(-1);
}

public	int	standard_view_menu_remove(struct standard_view_menu_context * _Context)
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

public	int	standard_view_menu_show(struct standard_view_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if ((_Context->p_Frame != (void *) 0)
	&& (_Context->s_Frame == 0)) {
		(void)visual_buffer_get(_Context->p_Frame,128,32);
		_Context->s_Frame=1;
		}
	visual_filzone(128,32,144,172,27,11);
	_Context->trigger_Auto1607=visual_trigger_code(_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]));
	visual_button(144,44,112,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
	_Context->trigger_Auto1609=visual_trigger_code(_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]));
	visual_button(144,60,112,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
	_Context->trigger_Auto1610=visual_trigger_code(_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]));
	visual_button(144,76,112,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
	_Context->trigger_Auto1611=visual_trigger_code(_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]));
	visual_button(144,92,112,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
	_Context->trigger_Auto1613=visual_trigger_code(_Context->msg_Auto1613[_Context->language],strlen(_Context->msg_Auto1613[_Context->language]));
	visual_button(144,108,112,20,vfh[2],16,0,_Context->msg_Auto1613[_Context->language],strlen(_Context->msg_Auto1613[_Context->language]),32);
	_Context->trigger_Auto1731=visual_trigger_code(_Context->msg_Auto1731[_Context->language],strlen(_Context->msg_Auto1731[_Context->language]));
	visual_button(144,124,112,20,vfh[2],16,0,_Context->msg_Auto1731[_Context->language],strlen(_Context->msg_Auto1731[_Context->language]),32);
	_Context->trigger_Auto1725=visual_trigger_code(_Context->msg_Auto1725[_Context->language],strlen(_Context->msg_Auto1725[_Context->language]));
	visual_button(144,140,112,20,vfh[2],16,0,_Context->msg_Auto1725[_Context->language],strlen(_Context->msg_Auto1725[_Context->language]),32);
	_Context->trigger_Auto1729=visual_trigger_code(_Context->msg_Auto1729[_Context->language],strlen(_Context->msg_Auto1729[_Context->language]));
	visual_button(144,156,112,20,vfh[2],16,0,_Context->msg_Auto1729[_Context->language],strlen(_Context->msg_Auto1729[_Context->language]),32);
	_Context->trigger_Auto1727=visual_trigger_code(_Context->msg_Auto1727[_Context->language],strlen(_Context->msg_Auto1727[_Context->language]));
	visual_button(144,172,112,20,vfh[2],16,0,_Context->msg_Auto1727[_Context->language],strlen(_Context->msg_Auto1727[_Context->language]),32);
	visual_thaw(128,32,144,172);

	return(0);
}
private int on_Auto1607_event(struct standard_view_menu_context * _Context) {
	return(_EXEC_PROG);
	return(-1);
}
private int on_Auto1609_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_TEXT);
	return(-1);
}
private int on_Auto1610_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_IMAGE);
	return(-1);
}
private int on_Auto1611_event(struct standard_view_menu_context * _Context) {
	int result;
		standard_view_menu_hide(_Context);
;
	on_Frame_remove(_Context);
	result=use_font_editor();
	on_Frame_create(_Context);
		standard_view_menu_show(_Context);
;
	return(result);
	return(-1);
}
private int on_Auto1613_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_PROPERTIES);
	return(-1);
}
private int on_Auto1731_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_FORM);
	return(-1);
}
private int on_Auto1725_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_DATABASE);
	return(-1);
}
private int on_Auto1729_event(struct standard_view_menu_context * _Context) {
	int result;
		standard_view_menu_hide(_Context);
;
	result=toggle_treeview();
		standard_view_menu_show(_Context);
;
	return(result);
	return(-1);
}
private int on_Auto1727_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_GRAPH);
	return(-1);
}


public	int	standard_view_menu_event(
struct standard_view_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto1607 == mb ) return(1);
		if (_Context->trigger_Auto1609 == mb ) return(2);
		if (_Context->trigger_Auto1610 == mb ) return(3);
		if (_Context->trigger_Auto1611 == mb ) return(4);
		if (_Context->trigger_Auto1613 == mb ) return(5);
		if (_Context->trigger_Auto1731 == mb ) return(6);
		if (_Context->trigger_Auto1725 == mb ) return(7);
		if (_Context->trigger_Auto1729 == mb ) return(8);
		if (_Context->trigger_Auto1727 == mb ) return(9);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 144 ) 
	&&  ( my >= 44 ) 
	&&  ( mx <= 256 ) 
	&&  ( my <= 64 )) {
		return(1); /* Auto1607 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 60 ) 
	&&  ( mx <= 256 ) 
	&&  ( my <= 80 )) {
		return(2); /* Auto1609 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 76 ) 
	&&  ( mx <= 256 ) 
	&&  ( my <= 96 )) {
		return(3); /* Auto1610 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 92 ) 
	&&  ( mx <= 256 ) 
	&&  ( my <= 112 )) {
		return(4); /* Auto1611 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 108 ) 
	&&  ( mx <= 256 ) 
	&&  ( my <= 128 )) {
		return(5); /* Auto1613 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 124 ) 
	&&  ( mx <= 256 ) 
	&&  ( my <= 144 )) {
		return(6); /* Auto1731 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 140 ) 
	&&  ( mx <= 256 ) 
	&&  ( my <= 160 )) {
		return(7); /* Auto1725 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 156 ) 
	&&  ( mx <= 256 ) 
	&&  ( my <= 176 )) {
		return(8); /* Auto1729 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 172 ) 
	&&  ( mx <= 256 ) 
	&&  ( my <= 192 )) {
		return(9); /* Auto1727 */
		}

	return(-1);
}


public	int	standard_view_menu_focus(struct standard_view_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto1607 */
				visual_button(144,44,112,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(144,44,112,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
				break;
			case	0x2 :
				/* Auto1609 */
				visual_button(144,60,112,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(144,60,112,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
				break;
			case	0x3 :
				/* Auto1610 */
				visual_button(144,76,112,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(144,76,112,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
				break;
			case	0x4 :
				/* Auto1611 */
				visual_button(144,92,112,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(144,92,112,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
				break;
			case	0x5 :
				/* Auto1613 */
				visual_button(144,108,112,20,vfh[2],16,0,_Context->msg_Auto1613[_Context->language],strlen(_Context->msg_Auto1613[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(144,108,112,20,vfh[2],16,0,_Context->msg_Auto1613[_Context->language],strlen(_Context->msg_Auto1613[_Context->language]),32);
				break;
			case	0x6 :
				/* Auto1731 */
				visual_button(144,124,112,20,vfh[2],16,0,_Context->msg_Auto1731[_Context->language],strlen(_Context->msg_Auto1731[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(144,124,112,20,vfh[2],16,0,_Context->msg_Auto1731[_Context->language],strlen(_Context->msg_Auto1731[_Context->language]),32);
				break;
			case	0x7 :
				/* Auto1725 */
				visual_button(144,140,112,20,vfh[2],16,0,_Context->msg_Auto1725[_Context->language],strlen(_Context->msg_Auto1725[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(144,140,112,20,vfh[2],16,0,_Context->msg_Auto1725[_Context->language],strlen(_Context->msg_Auto1725[_Context->language]),32);
				break;
			case	0x8 :
				/* Auto1729 */
				visual_button(144,156,112,20,vfh[2],16,0,_Context->msg_Auto1729[_Context->language],strlen(_Context->msg_Auto1729[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(144,156,112,20,vfh[2],16,0,_Context->msg_Auto1729[_Context->language],strlen(_Context->msg_Auto1729[_Context->language]),32);
				break;
			case	0x9 :
				/* Auto1727 */
				visual_button(144,172,112,20,vfh[2],16,0,_Context->msg_Auto1727[_Context->language],strlen(_Context->msg_Auto1727[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(144,172,112,20,vfh[2],16,0,_Context->msg_Auto1727[_Context->language],strlen(_Context->msg_Auto1727[_Context->language]),32);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			standard_view_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=9;
			standard_view_menu_show(_Context);
			continue;
			case	0x100 :
				if (!( visual_event(1)  & _MIMO_ALT )) { 
					if (( visual_event(7) <  128 )
					|| ( visual_event(6) <  32 )
					|| ( visual_event(7) >  272 )
					|| ( visual_event(6) >  204 )) {
						if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
						else { return(256); }
						}
					}
				if ((retcode=standard_view_menu_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1607 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(144,44,112,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(144,44,112,20,vfh[2],16,0,_Context->msg_Auto1607[_Context->language],strlen(_Context->msg_Auto1607[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1607_event(_Context)) != -1) break;

							}
						continue;
					case	0x2 :
						/* Auto1609 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(144,60,112,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(144,60,112,20,vfh[2],16,0,_Context->msg_Auto1609[_Context->language],strlen(_Context->msg_Auto1609[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1609_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* Auto1610 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(144,76,112,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(144,76,112,20,vfh[2],16,0,_Context->msg_Auto1610[_Context->language],strlen(_Context->msg_Auto1610[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1610_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* Auto1611 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(144,92,112,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(144,92,112,20,vfh[2],16,0,_Context->msg_Auto1611[_Context->language],strlen(_Context->msg_Auto1611[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1611_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* Auto1613 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(144,108,112,20,vfh[2],16,0,_Context->msg_Auto1613[_Context->language],strlen(_Context->msg_Auto1613[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(144,108,112,20,vfh[2],16,0,_Context->msg_Auto1613[_Context->language],strlen(_Context->msg_Auto1613[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1613_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* Auto1731 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(144,124,112,20,vfh[2],16,0,_Context->msg_Auto1731[_Context->language],strlen(_Context->msg_Auto1731[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(144,124,112,20,vfh[2],16,0,_Context->msg_Auto1731[_Context->language],strlen(_Context->msg_Auto1731[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1731_event(_Context)) != -1) break;

							}
						continue;
					case	0x7 :
						/* Auto1725 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(144,140,112,20,vfh[2],16,0,_Context->msg_Auto1725[_Context->language],strlen(_Context->msg_Auto1725[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(144,140,112,20,vfh[2],16,0,_Context->msg_Auto1725[_Context->language],strlen(_Context->msg_Auto1725[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1725_event(_Context)) != -1) break;

							}
						continue;
					case	0x8 :
						/* Auto1729 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(144,156,112,20,vfh[2],16,0,_Context->msg_Auto1729[_Context->language],strlen(_Context->msg_Auto1729[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(144,156,112,20,vfh[2],16,0,_Context->msg_Auto1729[_Context->language],strlen(_Context->msg_Auto1729[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1729_event(_Context)) != -1) break;

							}
						continue;
					case	0x9 :
						/* Auto1727 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(144,172,112,20,vfh[2],16,0,_Context->msg_Auto1727[_Context->language],strlen(_Context->msg_Auto1727[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(144,172,112,20,vfh[2],16,0,_Context->msg_Auto1727[_Context->language],strlen(_Context->msg_Auto1727[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1727_event(_Context)) != -1) break;

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

public	int	standard_view_menu()
{
	int	status=0;
	struct standard_view_menu_context * _Context=(struct standard_view_menu_context*) 0;
	status = standard_view_menu_create(&_Context);
	if ( status != 0) return(status);
	status = standard_view_menu_show(_Context);
		enter_modal();
	status = standard_view_menu_focus(_Context);
		leave_modal();
	status = standard_view_menu_hide(_Context);
	status = standard_view_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _viewmenu_c */
