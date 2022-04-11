
#ifndef _imagmenu_c
#define _imagmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.44  */
/* Production     : C  */
/* Project        : imagmenu.xml  */
/* Target         : imagmenu.c  */
/* Identification : 0.0-1100082933-2314.2299 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Auto1726   ""
#define en_Auto1727   "&Copy"
#define fr_Auto1727   "&Copier"
#define it_Auto1727   "&Copy"
#define es_Auto1727   "&Copy"
#define de_Auto1727   "&Copy"
#define nl_Auto1727   "&Copy"
#define pt_Auto1727   "&Copy"
#define xx_Auto1727   "&Copy"
#define en_Auto1728   "&Paste"
#define fr_Auto1728   "C&oller"
#define it_Auto1728   "&Paste"
#define es_Auto1728   "&Paste"
#define de_Auto1728   "&Paste"
#define nl_Auto1728   "&Paste"
#define pt_Auto1728   "&Paste"
#define xx_Auto1728   "&Paste"
#define en_Auto1729   "&Rotate 90"
#define fr_Auto1729   "&Rotation 90"
#define it_Auto1729   "&Rotate 90"
#define es_Auto1729   "&Rotate 90"
#define de_Auto1729   "&Rotate 90"
#define nl_Auto1729   "&Rotate 90"
#define pt_Auto1729   "&Rotate 90"
#define xx_Auto1729   "&Rotate 90"
#define en_Auto1730   "R&otate 180"
#define fr_Auto1730   "Ro&tation 180"
#define it_Auto1730   "R&otate 180"
#define es_Auto1730   "R&otate 180"
#define de_Auto1730   "R&otate 180"
#define nl_Auto1730   "R&otate 180"
#define pt_Auto1730   "R&otate 180"
#define xx_Auto1730   "R&otate 180"
#define en_Auto1731   "Ro&tate 270"
#define fr_Auto1731   "Rot&ation 270"
#define it_Auto1731   "Ro&tate 270"
#define es_Auto1731   "Ro&tate 270"
#define de_Auto1731   "Ro&tate 270"
#define nl_Auto1731   "Ro&tate 270"
#define pt_Auto1731   "Ro&tate 270"
#define xx_Auto1731   "Ro&tate 270"
#define en_Auto1732   "C&hange Colour"
#define fr_Auto1732   "C&hangement de Couleur"
#define it_Auto1732   "C&hange Colour"
#define es_Auto1732   "C&hange Colour"
#define de_Auto1732   "C&hange Colour"
#define nl_Auto1732   "C&hange Colour"
#define pt_Auto1732   "C&hange Colour"
#define xx_Auto1732   "C&hange Colour"
#define en_Auto1733   "&Grey Scale"
#define fr_Auto1733   "To&ns de Gris"
#define it_Auto1733   "&Grey Scale"
#define es_Auto1733   "&Grey Scale"
#define de_Auto1733   "&Grey Scale"
#define nl_Auto1733   "&Grey Scale"
#define pt_Auto1733   "&Grey Scale"
#define xx_Auto1733   "&Grey Scale"
#define en_Auto1734   "&Vertical Mirror"
#define fr_Auto1734   "&Miroir Vertical"
#define it_Auto1734   "&Vertical Mirror"
#define es_Auto1734   "&Vertical Mirror"
#define de_Auto1734   "&Vertical Mirror"
#define nl_Auto1734   "&Vertical Mirror"
#define pt_Auto1734   "&Vertical Mirror"
#define xx_Auto1734   "&Vertical Mirror"
#define en_Auto1735   "Hor&izontal Mirror"
#define fr_Auto1735   "M&iroir Horizontal"
#define it_Auto1735   "Hor&izontal Mirror"
#define es_Auto1735   "Hor&izontal Mirror"
#define de_Auto1735   "Hor&izontal Mirror"
#define nl_Auto1735   "Hor&izontal Mirror"
#define pt_Auto1735   "Hor&izontal Mirror"
#define xx_Auto1735   "Hor&izontal Mirror"
#define en_Auto1736   "&Dimensions"
#define fr_Auto1736   "&Dimensions"
#define it_Auto1736   "&Dimensions"
#define es_Auto1736   "&Dimensions"
#define de_Auto1736   "&Dimensions"
#define nl_Auto1736   "&Dimensions"
#define pt_Auto1736   "&Dimensions"
#define xx_Auto1736   "&Dimensions"
static int	vfh[10];

private struct image_editor_menu_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	s_Auto1726;
	void *	p_Auto1726;
	char * msg_Auto1727[8];
	int	trigger_Auto1727;
	char * msg_Auto1728[8];
	int	trigger_Auto1728;
	char * msg_Auto1729[8];
	int	trigger_Auto1729;
	char * msg_Auto1730[8];
	int	trigger_Auto1730;
	char * msg_Auto1731[8];
	int	trigger_Auto1731;
	char * msg_Auto1732[8];
	int	trigger_Auto1732;
	char * msg_Auto1733[8];
	int	trigger_Auto1733;
	char * msg_Auto1734[8];
	int	trigger_Auto1734;
	char * msg_Auto1735[8];
	int	trigger_Auto1735;
	char * msg_Auto1736[8];
	int	trigger_Auto1736;
	char	signature[1];
	};

public	int	image_editor_menu_create(struct image_editor_menu_context **cptr)
{

	int i;
	struct image_editor_menu_context * _Context=(struct image_editor_menu_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct image_editor_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=10;
	_Context->s_Auto1726=0;
	_Context->p_Auto1726=visual_buffer(264,36,168,188);
	mouse_move_on();
	for (i=0; i < 8; i++)_Context->msg_Auto1727[i]=" ";
	_Context->msg_Auto1727[0]=en_Auto1727;
	_Context->msg_Auto1727[1]=fr_Auto1727;
	_Context->msg_Auto1727[2]=it_Auto1727;
	_Context->msg_Auto1727[3]=es_Auto1727;
	_Context->msg_Auto1727[4]=de_Auto1727;
	_Context->msg_Auto1727[5]=nl_Auto1727;
	_Context->msg_Auto1727[6]=pt_Auto1727;
	_Context->msg_Auto1727[7]=xx_Auto1727;
	for (i=0; i < 8; i++)_Context->msg_Auto1728[i]=" ";
	_Context->msg_Auto1728[0]=en_Auto1728;
	_Context->msg_Auto1728[1]=fr_Auto1728;
	_Context->msg_Auto1728[2]=it_Auto1728;
	_Context->msg_Auto1728[3]=es_Auto1728;
	_Context->msg_Auto1728[4]=de_Auto1728;
	_Context->msg_Auto1728[5]=nl_Auto1728;
	_Context->msg_Auto1728[6]=pt_Auto1728;
	_Context->msg_Auto1728[7]=xx_Auto1728;
	for (i=0; i < 8; i++)_Context->msg_Auto1729[i]=" ";
	_Context->msg_Auto1729[0]=en_Auto1729;
	_Context->msg_Auto1729[1]=fr_Auto1729;
	_Context->msg_Auto1729[2]=it_Auto1729;
	_Context->msg_Auto1729[3]=es_Auto1729;
	_Context->msg_Auto1729[4]=de_Auto1729;
	_Context->msg_Auto1729[5]=nl_Auto1729;
	_Context->msg_Auto1729[6]=pt_Auto1729;
	_Context->msg_Auto1729[7]=xx_Auto1729;
	for (i=0; i < 8; i++)_Context->msg_Auto1730[i]=" ";
	_Context->msg_Auto1730[0]=en_Auto1730;
	_Context->msg_Auto1730[1]=fr_Auto1730;
	_Context->msg_Auto1730[2]=it_Auto1730;
	_Context->msg_Auto1730[3]=es_Auto1730;
	_Context->msg_Auto1730[4]=de_Auto1730;
	_Context->msg_Auto1730[5]=nl_Auto1730;
	_Context->msg_Auto1730[6]=pt_Auto1730;
	_Context->msg_Auto1730[7]=xx_Auto1730;
	for (i=0; i < 8; i++)_Context->msg_Auto1731[i]=" ";
	_Context->msg_Auto1731[0]=en_Auto1731;
	_Context->msg_Auto1731[1]=fr_Auto1731;
	_Context->msg_Auto1731[2]=it_Auto1731;
	_Context->msg_Auto1731[3]=es_Auto1731;
	_Context->msg_Auto1731[4]=de_Auto1731;
	_Context->msg_Auto1731[5]=nl_Auto1731;
	_Context->msg_Auto1731[6]=pt_Auto1731;
	_Context->msg_Auto1731[7]=xx_Auto1731;
	for (i=0; i < 8; i++)_Context->msg_Auto1732[i]=" ";
	_Context->msg_Auto1732[0]=en_Auto1732;
	_Context->msg_Auto1732[1]=fr_Auto1732;
	_Context->msg_Auto1732[2]=it_Auto1732;
	_Context->msg_Auto1732[3]=es_Auto1732;
	_Context->msg_Auto1732[4]=de_Auto1732;
	_Context->msg_Auto1732[5]=nl_Auto1732;
	_Context->msg_Auto1732[6]=pt_Auto1732;
	_Context->msg_Auto1732[7]=xx_Auto1732;
	for (i=0; i < 8; i++)_Context->msg_Auto1733[i]=" ";
	_Context->msg_Auto1733[0]=en_Auto1733;
	_Context->msg_Auto1733[1]=fr_Auto1733;
	_Context->msg_Auto1733[2]=it_Auto1733;
	_Context->msg_Auto1733[3]=es_Auto1733;
	_Context->msg_Auto1733[4]=de_Auto1733;
	_Context->msg_Auto1733[5]=nl_Auto1733;
	_Context->msg_Auto1733[6]=pt_Auto1733;
	_Context->msg_Auto1733[7]=xx_Auto1733;
	for (i=0; i < 8; i++)_Context->msg_Auto1734[i]=" ";
	_Context->msg_Auto1734[0]=en_Auto1734;
	_Context->msg_Auto1734[1]=fr_Auto1734;
	_Context->msg_Auto1734[2]=it_Auto1734;
	_Context->msg_Auto1734[3]=es_Auto1734;
	_Context->msg_Auto1734[4]=de_Auto1734;
	_Context->msg_Auto1734[5]=nl_Auto1734;
	_Context->msg_Auto1734[6]=pt_Auto1734;
	_Context->msg_Auto1734[7]=xx_Auto1734;
	for (i=0; i < 8; i++)_Context->msg_Auto1735[i]=" ";
	_Context->msg_Auto1735[0]=en_Auto1735;
	_Context->msg_Auto1735[1]=fr_Auto1735;
	_Context->msg_Auto1735[2]=it_Auto1735;
	_Context->msg_Auto1735[3]=es_Auto1735;
	_Context->msg_Auto1735[4]=de_Auto1735;
	_Context->msg_Auto1735[5]=nl_Auto1735;
	_Context->msg_Auto1735[6]=pt_Auto1735;
	_Context->msg_Auto1735[7]=xx_Auto1735;
	for (i=0; i < 8; i++)_Context->msg_Auto1736[i]=" ";
	_Context->msg_Auto1736[0]=en_Auto1736;
	_Context->msg_Auto1736[1]=fr_Auto1736;
	_Context->msg_Auto1736[2]=it_Auto1736;
	_Context->msg_Auto1736[3]=es_Auto1736;
	_Context->msg_Auto1736[4]=de_Auto1736;
	_Context->msg_Auto1736[5]=nl_Auto1736;
	_Context->msg_Auto1736[6]=pt_Auto1736;
	_Context->msg_Auto1736[7]=xx_Auto1736;
	return(0);
}

public 	int	image_editor_menu_hide(struct image_editor_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto1726 != (void *) 0)
	&& (_Context->s_Auto1726 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto1726,264,36);
		_Context->s_Auto1726=0;
		}

	return(result);
}

public	int	image_editor_menu_remove(struct image_editor_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	mouse_move_off();
	if (_Context->p_Auto1726 != (void *) 0)
		_Context->p_Auto1726 = visual_drop(_Context->p_Auto1726);
	_Context=liberate(_Context);

	return(result);
}

public	int	image_editor_menu_show(struct image_editor_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if ((_Context->p_Auto1726 != (void *) 0)
	&& (_Context->s_Auto1726 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto1726,264,36);
		_Context->s_Auto1726=1;
		}
	visual_filzone(264,36,168,188,27,11);
	_Context->trigger_Auto1727=visual_trigger_code(_Context->msg_Auto1727[_Context->language],strlen(_Context->msg_Auto1727[_Context->language]));
	visual_button(280,48,128,20,vfh[2],16,0,_Context->msg_Auto1727[_Context->language],strlen(_Context->msg_Auto1727[_Context->language]),32);
	_Context->trigger_Auto1728=visual_trigger_code(_Context->msg_Auto1728[_Context->language],strlen(_Context->msg_Auto1728[_Context->language]));
	visual_button(280,64,128,20,vfh[2],16,0,_Context->msg_Auto1728[_Context->language],strlen(_Context->msg_Auto1728[_Context->language]),32);
	_Context->trigger_Auto1729=visual_trigger_code(_Context->msg_Auto1729[_Context->language],strlen(_Context->msg_Auto1729[_Context->language]));
	visual_button(280,80,128,20,vfh[2],16,0,_Context->msg_Auto1729[_Context->language],strlen(_Context->msg_Auto1729[_Context->language]),32);
	_Context->trigger_Auto1730=visual_trigger_code(_Context->msg_Auto1730[_Context->language],strlen(_Context->msg_Auto1730[_Context->language]));
	visual_button(280,96,128,20,vfh[2],16,0,_Context->msg_Auto1730[_Context->language],strlen(_Context->msg_Auto1730[_Context->language]),32);
	_Context->trigger_Auto1731=visual_trigger_code(_Context->msg_Auto1731[_Context->language],strlen(_Context->msg_Auto1731[_Context->language]));
	visual_button(280,112,128,20,vfh[2],16,0,_Context->msg_Auto1731[_Context->language],strlen(_Context->msg_Auto1731[_Context->language]),32);
	_Context->trigger_Auto1732=visual_trigger_code(_Context->msg_Auto1732[_Context->language],strlen(_Context->msg_Auto1732[_Context->language]));
	visual_button(280,128,128,20,vfh[2],16,0,_Context->msg_Auto1732[_Context->language],strlen(_Context->msg_Auto1732[_Context->language]),32);
	_Context->trigger_Auto1733=visual_trigger_code(_Context->msg_Auto1733[_Context->language],strlen(_Context->msg_Auto1733[_Context->language]));
	visual_button(280,144,128,20,vfh[2],16,0,_Context->msg_Auto1733[_Context->language],strlen(_Context->msg_Auto1733[_Context->language]),32);
	_Context->trigger_Auto1734=visual_trigger_code(_Context->msg_Auto1734[_Context->language],strlen(_Context->msg_Auto1734[_Context->language]));
	visual_button(280,160,128,20,vfh[2],16,0,_Context->msg_Auto1734[_Context->language],strlen(_Context->msg_Auto1734[_Context->language]),32);
	_Context->trigger_Auto1735=visual_trigger_code(_Context->msg_Auto1735[_Context->language],strlen(_Context->msg_Auto1735[_Context->language]));
	visual_button(280,176,128,20,vfh[2],16,0,_Context->msg_Auto1735[_Context->language],strlen(_Context->msg_Auto1735[_Context->language]),32);
	_Context->trigger_Auto1736=visual_trigger_code(_Context->msg_Auto1736[_Context->language],strlen(_Context->msg_Auto1736[_Context->language]));
	visual_button(280,192,128,20,vfh[2],16,0,_Context->msg_Auto1736[_Context->language],strlen(_Context->msg_Auto1736[_Context->language]),32);
	visual_thaw(264,36,168,188);

	return(0);
}
private int on_Auto1727_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_COPY);
	return(-1);
}
private int on_Auto1728_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_PASTE);
	return(-1);
}
private int on_Auto1729_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_ROTATE1);
	return(-1);
}
private int on_Auto1730_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_ROTATE2);
	return(-1);
}
private int on_Auto1731_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_ROTATE3);
	return(-1);
}
private int on_Auto1732_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_COLOUR);
	return(-1);
}
private int on_Auto1733_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_GREY);
	return(-1);
}
private int on_Auto1734_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_REFLECTY);
	return(-1);
}
private int on_Auto1735_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_REFLECTX);
	return(-1);
}
private int on_Auto1736_event(struct image_editor_menu_context * _Context) {
	return(_ZOOM_CHANGE);
	return(-1);
}


public	int	image_editor_menu_event(
struct image_editor_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto1727 == mb ) return(1);
		if (_Context->trigger_Auto1728 == mb ) return(2);
		if (_Context->trigger_Auto1729 == mb ) return(3);
		if (_Context->trigger_Auto1730 == mb ) return(4);
		if (_Context->trigger_Auto1731 == mb ) return(5);
		if (_Context->trigger_Auto1732 == mb ) return(6);
		if (_Context->trigger_Auto1733 == mb ) return(7);
		if (_Context->trigger_Auto1734 == mb ) return(8);
		if (_Context->trigger_Auto1735 == mb ) return(9);
		if (_Context->trigger_Auto1736 == mb ) return(10);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 280 ) 
	&&  ( my >= 48 ) 
	&&  ( mx <= 408 ) 
	&&  ( my <= 68 )) {
		return(1); /* Auto1727 */
		}
	if (( mx >= 280 ) 
	&&  ( my >= 64 ) 
	&&  ( mx <= 408 ) 
	&&  ( my <= 84 )) {
		return(2); /* Auto1728 */
		}
	if (( mx >= 280 ) 
	&&  ( my >= 80 ) 
	&&  ( mx <= 408 ) 
	&&  ( my <= 100 )) {
		return(3); /* Auto1729 */
		}
	if (( mx >= 280 ) 
	&&  ( my >= 96 ) 
	&&  ( mx <= 408 ) 
	&&  ( my <= 116 )) {
		return(4); /* Auto1730 */
		}
	if (( mx >= 280 ) 
	&&  ( my >= 112 ) 
	&&  ( mx <= 408 ) 
	&&  ( my <= 132 )) {
		return(5); /* Auto1731 */
		}
	if (( mx >= 280 ) 
	&&  ( my >= 128 ) 
	&&  ( mx <= 408 ) 
	&&  ( my <= 148 )) {
		return(6); /* Auto1732 */
		}
	if (( mx >= 280 ) 
	&&  ( my >= 144 ) 
	&&  ( mx <= 408 ) 
	&&  ( my <= 164 )) {
		return(7); /* Auto1733 */
		}
	if (( mx >= 280 ) 
	&&  ( my >= 160 ) 
	&&  ( mx <= 408 ) 
	&&  ( my <= 180 )) {
		return(8); /* Auto1734 */
		}
	if (( mx >= 280 ) 
	&&  ( my >= 176 ) 
	&&  ( mx <= 408 ) 
	&&  ( my <= 196 )) {
		return(9); /* Auto1735 */
		}
	if (( mx >= 280 ) 
	&&  ( my >= 192 ) 
	&&  ( mx <= 408 ) 
	&&  ( my <= 212 )) {
		return(10); /* Auto1736 */
		}

	return(-1);
}


public	int	image_editor_menu_focus(struct image_editor_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto1727 */
				visual_button(280,48,128,20,vfh[2],16,0,_Context->msg_Auto1727[_Context->language],strlen(_Context->msg_Auto1727[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(280,48,128,20,vfh[2],16,0,_Context->msg_Auto1727[_Context->language],strlen(_Context->msg_Auto1727[_Context->language]),32);
				break;
			case	0x2 :
				/* Auto1728 */
				visual_button(280,64,128,20,vfh[2],16,0,_Context->msg_Auto1728[_Context->language],strlen(_Context->msg_Auto1728[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(280,64,128,20,vfh[2],16,0,_Context->msg_Auto1728[_Context->language],strlen(_Context->msg_Auto1728[_Context->language]),32);
				break;
			case	0x3 :
				/* Auto1729 */
				visual_button(280,80,128,20,vfh[2],16,0,_Context->msg_Auto1729[_Context->language],strlen(_Context->msg_Auto1729[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(280,80,128,20,vfh[2],16,0,_Context->msg_Auto1729[_Context->language],strlen(_Context->msg_Auto1729[_Context->language]),32);
				break;
			case	0x4 :
				/* Auto1730 */
				visual_button(280,96,128,20,vfh[2],16,0,_Context->msg_Auto1730[_Context->language],strlen(_Context->msg_Auto1730[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(280,96,128,20,vfh[2],16,0,_Context->msg_Auto1730[_Context->language],strlen(_Context->msg_Auto1730[_Context->language]),32);
				break;
			case	0x5 :
				/* Auto1731 */
				visual_button(280,112,128,20,vfh[2],16,0,_Context->msg_Auto1731[_Context->language],strlen(_Context->msg_Auto1731[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(280,112,128,20,vfh[2],16,0,_Context->msg_Auto1731[_Context->language],strlen(_Context->msg_Auto1731[_Context->language]),32);
				break;
			case	0x6 :
				/* Auto1732 */
				visual_button(280,128,128,20,vfh[2],16,0,_Context->msg_Auto1732[_Context->language],strlen(_Context->msg_Auto1732[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(280,128,128,20,vfh[2],16,0,_Context->msg_Auto1732[_Context->language],strlen(_Context->msg_Auto1732[_Context->language]),32);
				break;
			case	0x7 :
				/* Auto1733 */
				visual_button(280,144,128,20,vfh[2],16,0,_Context->msg_Auto1733[_Context->language],strlen(_Context->msg_Auto1733[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(280,144,128,20,vfh[2],16,0,_Context->msg_Auto1733[_Context->language],strlen(_Context->msg_Auto1733[_Context->language]),32);
				break;
			case	0x8 :
				/* Auto1734 */
				visual_button(280,160,128,20,vfh[2],16,0,_Context->msg_Auto1734[_Context->language],strlen(_Context->msg_Auto1734[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(280,160,128,20,vfh[2],16,0,_Context->msg_Auto1734[_Context->language],strlen(_Context->msg_Auto1734[_Context->language]),32);
				break;
			case	0x9 :
				/* Auto1735 */
				visual_button(280,176,128,20,vfh[2],16,0,_Context->msg_Auto1735[_Context->language],strlen(_Context->msg_Auto1735[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(280,176,128,20,vfh[2],16,0,_Context->msg_Auto1735[_Context->language],strlen(_Context->msg_Auto1735[_Context->language]),32);
				break;
			case	0xa :
				/* Auto1736 */
				visual_button(280,192,128,20,vfh[2],16,0,_Context->msg_Auto1736[_Context->language],strlen(_Context->msg_Auto1736[_Context->language]),34);
				_Context->keycode = visual_getch();
				visual_button(280,192,128,20,vfh[2],16,0,_Context->msg_Auto1736[_Context->language],strlen(_Context->msg_Auto1736[_Context->language]),32);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			image_editor_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=10;
			image_editor_menu_show(_Context);
			continue;
			case	0x100 :
				if (!( visual_event(1)  & _MIMO_ALT )) { 
					if (( visual_event(7) <  264 )
					|| ( visual_event(6) <  36 )
					|| ( visual_event(7) >  432 )
					|| ( visual_event(6) >  224 )) {
						if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
						else { return(256); }
						}
					}
				if ((retcode=image_editor_menu_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1727 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(280,48,128,20,vfh[2],16,0,_Context->msg_Auto1727[_Context->language],strlen(_Context->msg_Auto1727[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(280,48,128,20,vfh[2],16,0,_Context->msg_Auto1727[_Context->language],strlen(_Context->msg_Auto1727[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1727_event(_Context)) != -1) break;

							}
						continue;
					case	0x2 :
						/* Auto1728 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(280,64,128,20,vfh[2],16,0,_Context->msg_Auto1728[_Context->language],strlen(_Context->msg_Auto1728[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(280,64,128,20,vfh[2],16,0,_Context->msg_Auto1728[_Context->language],strlen(_Context->msg_Auto1728[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1728_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* Auto1729 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(280,80,128,20,vfh[2],16,0,_Context->msg_Auto1729[_Context->language],strlen(_Context->msg_Auto1729[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(280,80,128,20,vfh[2],16,0,_Context->msg_Auto1729[_Context->language],strlen(_Context->msg_Auto1729[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1729_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* Auto1730 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(280,96,128,20,vfh[2],16,0,_Context->msg_Auto1730[_Context->language],strlen(_Context->msg_Auto1730[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(280,96,128,20,vfh[2],16,0,_Context->msg_Auto1730[_Context->language],strlen(_Context->msg_Auto1730[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1730_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* Auto1731 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(280,112,128,20,vfh[2],16,0,_Context->msg_Auto1731[_Context->language],strlen(_Context->msg_Auto1731[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(280,112,128,20,vfh[2],16,0,_Context->msg_Auto1731[_Context->language],strlen(_Context->msg_Auto1731[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1731_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* Auto1732 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(280,128,128,20,vfh[2],16,0,_Context->msg_Auto1732[_Context->language],strlen(_Context->msg_Auto1732[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(280,128,128,20,vfh[2],16,0,_Context->msg_Auto1732[_Context->language],strlen(_Context->msg_Auto1732[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1732_event(_Context)) != -1) break;

							}
						continue;
					case	0x7 :
						/* Auto1733 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(280,144,128,20,vfh[2],16,0,_Context->msg_Auto1733[_Context->language],strlen(_Context->msg_Auto1733[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(280,144,128,20,vfh[2],16,0,_Context->msg_Auto1733[_Context->language],strlen(_Context->msg_Auto1733[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1733_event(_Context)) != -1) break;

							}
						continue;
					case	0x8 :
						/* Auto1734 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(280,160,128,20,vfh[2],16,0,_Context->msg_Auto1734[_Context->language],strlen(_Context->msg_Auto1734[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(280,160,128,20,vfh[2],16,0,_Context->msg_Auto1734[_Context->language],strlen(_Context->msg_Auto1734[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1734_event(_Context)) != -1) break;

							}
						continue;
					case	0x9 :
						/* Auto1735 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(280,176,128,20,vfh[2],16,0,_Context->msg_Auto1735[_Context->language],strlen(_Context->msg_Auto1735[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(280,176,128,20,vfh[2],16,0,_Context->msg_Auto1735[_Context->language],strlen(_Context->msg_Auto1735[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1735_event(_Context)) != -1) break;

							}
						continue;
					case	0xa :
						/* Auto1736 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(280,192,128,20,vfh[2],16,0,_Context->msg_Auto1736[_Context->language],strlen(_Context->msg_Auto1736[_Context->language]),34);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(280,192,128,20,vfh[2],16,0,_Context->msg_Auto1736[_Context->language],strlen(_Context->msg_Auto1736[_Context->language]),32);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1736_event(_Context)) != -1) break;

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
				_Context->focus_item=10;
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

public	int	image_editor_menu()
{
	int	status=0;
	struct image_editor_menu_context * _Context=(struct image_editor_menu_context*) 0;
	status = image_editor_menu_create(&_Context);
	if ( status != 0) return(status);
	status = image_editor_menu_show(_Context);
		enter_modal();
	status = image_editor_menu_focus(_Context);
		leave_modal();
	status = image_editor_menu_hide(_Context);
	status = image_editor_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _imagmenu_c */
