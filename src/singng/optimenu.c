
#ifndef _optimenu_c
#define _optimenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : optimenu.xml                                             */
/* Target         : optimenu.c                                               */
/* Identification : 0.0-1177512018-5209.5208                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Frame   ""
#define en__Frame   ""
#define en_Auto618   "&Parameters..."
#define fr_Auto618   "&ParamŠtres..."
#define it_Auto618   "&Parameters..."
#define es_Auto618   "&Parameters..."
#define de_Auto618   "&Parameters..."
#define nl_Auto618   "&Parameters.."
#define pt_Auto618   "&Parameters..."
#define xx_Auto618   "&Parameters..."
#define en__Auto618   ""
#define fr__Auto618   ""
#define it__Auto618   ""
#define es__Auto618   ""
#define de__Auto618   ""
#define nl__Auto618   ""
#define pt__Auto618   ""
#define xx__Auto618   ""
#define en_Auto619   "&Refresh"
#define fr_Auto619   "&R‚afficher"
#define it_Auto619   "&Refresh"
#define es_Auto619   "&Refresh"
#define de_Auto619   "&Refresh"
#define nl_Auto619   "&Refresh"
#define pt_Auto619   "&Refresh"
#define xx_Auto619   "&Refresh"
#define en_Auto621   "&Configure..."
#define fr_Auto621   "&Configuration..."
#define it_Auto621   "&Configure..."
#define es_Auto621   "&Configure..."
#define de_Auto621   "&Configure..."
#define nl_Auto621   "&Configure..."
#define pt_Auto621   "&Configure..."
#define xx_Auto621   "&Configure..."
#define en__Auto621   ""
#define fr__Auto621   ""
#define it__Auto621   ""
#define es__Auto621   ""
#define de__Auto621   ""
#define nl__Auto621   ""
#define pt__Auto621   ""
#define xx__Auto621   ""
#define en_Auto622   "&Screen Capture..."
#define fr_Auto622   "C&apture d'‚cran..."
#define it_Auto622   "&Screen Capture..."
#define es_Auto622   "&Screen Capture..."
#define de_Auto622   "&Screen Capture..."
#define nl_Auto622   "&Screen Capture..."
#define pt_Auto622   "&Screen Capture..."
#define xx_Auto622   "&Screen Capture..."
#define en__Auto622   ""
#define fr__Auto622   ""
#define it__Auto622   ""
#define es__Auto622   ""
#define de__Auto622   ""
#define nl__Auto622   ""
#define pt__Auto622   ""
#define xx__Auto622   ""
#define en_Auto623   "&Animate"
#define fr_Auto623   "A&nimation"
#define it_Auto623   "&Animate"
#define es_Auto623   "&Animate"
#define de_Auto623   "&Animate"
#define nl_Auto623   "&Animate"
#define pt_Auto623   "&Animate"
#define xx_Auto623   "&Animate"
#define en_Auto624   "&Html"
#define fr_Auto624   "Production &Html"
#define it_Auto624   "&Html"
#define es_Auto624   "&Html"
#define de_Auto624   "&Html"
#define nl_Auto624   "&Html"
#define pt_Auto624   "&Html"
#define xx_Auto624   "&Html"
#define en__Auto624   ""
#define fr__Auto624   ""
#define it__Auto624   ""
#define es__Auto624   ""
#define de__Auto624   ""
#define nl__Auto624   ""
#define pt__Auto624   ""
#define xx__Auto624   ""
#define en_Auto625   "&TreeView..."
#define fr_Auto625   "Ar&boresence projet..."
#define it_Auto625   "&Animate..."
#define es_Auto625   "&Animate..."
#define de_Auto625   "&Animate..."
#define nl_Auto625   "&Animate..."
#define pt_Auto625   "&Animate..."
#define xx_Auto625   "&Animate..."
#define en__Auto625   ""
#define fr__Auto625   ""
#define it__Auto625   ""
#define es__Auto625   ""
#define de__Auto625   ""
#define nl__Auto625   ""
#define pt__Auto625   ""
#define xx__Auto625   ""

private struct standard_option_menu_context {
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
	char * msg_Auto618[8];
	int	trigger_Auto618;
	char * hint_Auto618[8];
	char * msg_Auto619[8];
	int	trigger_Auto619;
	char * hint_Auto619[8];
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

static int stdinput(struct standard_option_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = standard_option_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}

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
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct standard_option_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=7;
	_Context->hint_Frame[0]=en__Frame;
	_Context->s_Frame=0;
	_Context->p_Frame=visual_buffer(256,32,184+2,164+2);
	(void) on_Frame_create(_Context);
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
	_Context->hint_Auto618[1]=fr__Auto618;
	_Context->hint_Auto618[2]=it__Auto618;
	_Context->hint_Auto618[3]=es__Auto618;
	_Context->hint_Auto618[4]=de__Auto618;
	_Context->hint_Auto618[5]=nl__Auto618;
	_Context->hint_Auto618[6]=pt__Auto618;
	_Context->hint_Auto618[7]=xx__Auto618;
	for (i=0; i < 8; i++)_Context->msg_Auto619[i]=" ";
	_Context->msg_Auto619[0]=en_Auto619;
	_Context->msg_Auto619[1]=fr_Auto619;
	_Context->msg_Auto619[2]=it_Auto619;
	_Context->msg_Auto619[3]=es_Auto619;
	_Context->msg_Auto619[4]=de_Auto619;
	_Context->msg_Auto619[5]=nl_Auto619;
	_Context->msg_Auto619[6]=pt_Auto619;
	_Context->msg_Auto619[7]=xx_Auto619;
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
	if (((_Context->status = visual_styled_element(256,32,184,164,GetWidgetStyle(1)," ",0)) != 0)
) {
		visual_filzone(256,32,184,164,27,11);
		}
	_Context->trigger_Auto618=visual_trigger_code(_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]));
	if (((_Context->status = visual_styled_element(272,44,152,20,GetWidgetStyle(2),_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]))) != 0)
) {
	visual_button(272,44,152,20,vfh[2],16,0,_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]),32);
		}
	_Context->trigger_Auto619=visual_trigger_code(_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]));
	if (((_Context->status = visual_styled_element(272,64,152,20,GetWidgetStyle(2),_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]))) != 0)
) {
	visual_button(272,64,152,20,vfh[2],16,0,_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]),32);
		}
	_Context->trigger_Auto621=visual_trigger_code(_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]));
	if (((_Context->status = visual_styled_element(272,84,152,20,GetWidgetStyle(2),_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]))) != 0)
) {
	visual_button(272,84,152,20,vfh[2],16,0,_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]),32);
		}
	_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
	if (((_Context->status = visual_styled_element(272,104,152,20,GetWidgetStyle(2),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
	visual_button(272,104,152,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),32);
		}
	_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
	if (((_Context->status = visual_styled_element(272,124,152,20,GetWidgetStyle(2),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
	visual_button(272,124,152,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),32);
		}
	_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
	if (((_Context->status = visual_styled_element(272,144,152,20,GetWidgetStyle(2),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
	visual_button(272,144,152,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),32);
		}
	_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
	if (((_Context->status = visual_styled_element(272,164,152,20,GetWidgetStyle(2),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
	visual_button(272,164,152,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),32);
		}
	visual_thaw(256,32,184,164);

	return(0);
}
private int on_Auto618_event(struct standard_option_menu_context * _Context) {
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
private int on_Auto619_event(struct standard_option_menu_context * _Context) {
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
private int on_Auto621_event(struct standard_option_menu_context * _Context) {
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
private int on_Auto622_event(struct standard_option_menu_context * _Context) {
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
private int on_Auto623_event(struct standard_option_menu_context * _Context) {
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
private int on_Auto624_event(struct standard_option_menu_context * _Context) {
	int result;
		standard_option_menu_hide(_Context);
;
	on_Frame_remove(_Context);
	result=camera_document_Properties(0);
	on_Frame_create(_Context);
		standard_option_menu_show(_Context);
;
	return(result);
	return(-1);
}
private int on_Auto625_event(struct standard_option_menu_context * _Context) {
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
		if (_Context->trigger_Auto618 == mb ) return(1);
		if (_Context->trigger_Auto619 == mb ) return(2);
		if (_Context->trigger_Auto621 == mb ) return(3);
		if (_Context->trigger_Auto622 == mb ) return(4);
		if (_Context->trigger_Auto623 == mb ) return(5);
		if (_Context->trigger_Auto624 == mb ) return(6);
		if (_Context->trigger_Auto625 == mb ) return(7);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 272 ) 
	&&  ( my >= 44 ) 
	&&  ( mx <= 424 ) 
	&&  ( my <= 64 )) {
		return(1); /* Auto618 */
		}
	if (( mx >= 272 ) 
	&&  ( my >= 64 ) 
	&&  ( mx <= 424 ) 
	&&  ( my <= 84 )) {
		return(2); /* Auto619 */
		}
	if (( mx >= 272 ) 
	&&  ( my >= 84 ) 
	&&  ( mx <= 424 ) 
	&&  ( my <= 104 )) {
		return(3); /* Auto621 */
		}
	if (( mx >= 272 ) 
	&&  ( my >= 104 ) 
	&&  ( mx <= 424 ) 
	&&  ( my <= 124 )) {
		return(4); /* Auto622 */
		}
	if (( mx >= 272 ) 
	&&  ( my >= 124 ) 
	&&  ( mx <= 424 ) 
	&&  ( my <= 144 )) {
		return(5); /* Auto623 */
		}
	if (( mx >= 272 ) 
	&&  ( my >= 144 ) 
	&&  ( mx <= 424 ) 
	&&  ( my <= 164 )) {
		return(6); /* Auto624 */
		}
	if (( mx >= 272 ) 
	&&  ( my >= 164 ) 
	&&  ( mx <= 424 ) 
	&&  ( my <= 184 )) {
		return(7); /* Auto625 */
		}

	return(-1);
}


public	int	standard_option_menu_focus(struct standard_option_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto618 */
				_Context->trigger_Auto618=visual_trigger_code(_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]));
				if (((_Context->status = visual_styled_element(272,44,152,20,GetWidgetStyle(3),_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]))) != 0)
) {
					visual_button(272,44,152,20,vfh[2],16,0,_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto618=visual_trigger_code(_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]));
				if (((_Context->status = visual_styled_element(272,44,152,20,GetWidgetStyle(2),_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]))) != 0)
) {
	visual_button(272,44,152,20,vfh[2],16,0,_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto619 */
				_Context->trigger_Auto619=visual_trigger_code(_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]));
				if (((_Context->status = visual_styled_element(272,64,152,20,GetWidgetStyle(3),_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]))) != 0)
) {
					visual_button(272,64,152,20,vfh[2],16,0,_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto619=visual_trigger_code(_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]));
				if (((_Context->status = visual_styled_element(272,64,152,20,GetWidgetStyle(2),_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]))) != 0)
) {
	visual_button(272,64,152,20,vfh[2],16,0,_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto621 */
				_Context->trigger_Auto621=visual_trigger_code(_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]));
				if (((_Context->status = visual_styled_element(272,84,152,20,GetWidgetStyle(3),_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]))) != 0)
) {
					visual_button(272,84,152,20,vfh[2],16,0,_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto621=visual_trigger_code(_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]));
				if (((_Context->status = visual_styled_element(272,84,152,20,GetWidgetStyle(2),_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]))) != 0)
) {
	visual_button(272,84,152,20,vfh[2],16,0,_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto622 */
				_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
				if (((_Context->status = visual_styled_element(272,104,152,20,GetWidgetStyle(3),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
					visual_button(272,104,152,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
				if (((_Context->status = visual_styled_element(272,104,152,20,GetWidgetStyle(2),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
	visual_button(272,104,152,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto623 */
				_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
				if (((_Context->status = visual_styled_element(272,124,152,20,GetWidgetStyle(3),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
					visual_button(272,124,152,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
				if (((_Context->status = visual_styled_element(272,124,152,20,GetWidgetStyle(2),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
	visual_button(272,124,152,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),32);
				}
				break;
			case	0x6 :
				/* Auto624 */
				_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
				if (((_Context->status = visual_styled_element(272,144,152,20,GetWidgetStyle(3),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
					visual_button(272,144,152,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
				if (((_Context->status = visual_styled_element(272,144,152,20,GetWidgetStyle(2),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
	visual_button(272,144,152,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),32);
				}
				break;
			case	0x7 :
				/* Auto625 */
				_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
				if (((_Context->status = visual_styled_element(272,164,152,20,GetWidgetStyle(3),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
					visual_button(272,164,152,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
				if (((_Context->status = visual_styled_element(272,164,152,20,GetWidgetStyle(2),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
	visual_button(272,164,152,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),32);
				}
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
			_Context->focus_item=7;
			standard_option_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  256 )
				|| ( visual_event(6) <  32 )
				|| ( visual_event(7) >  440 )
				|| ( visual_event(6) >  196 )) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=standard_option_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto618 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto618=visual_trigger_code(_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]));
						if (((_Context->status = visual_styled_element(272,44,152,20,GetWidgetStyle(3),_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]))) != 0)
) {
							visual_button(272,44,152,20,vfh[2],16,0,_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto618=visual_trigger_code(_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]));
						if (((_Context->status = visual_styled_element(272,44,152,20,GetWidgetStyle(2),_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]))) != 0)
) {
	visual_button(272,44,152,20,vfh[2],16,0,_Context->msg_Auto618[_Context->language],strlen(_Context->msg_Auto618[_Context->language]),32);
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
						if (((_Context->status = visual_styled_element(272,64,152,20,GetWidgetStyle(3),_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]))) != 0)
) {
							visual_button(272,64,152,20,vfh[2],16,0,_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto619=visual_trigger_code(_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]));
						if (((_Context->status = visual_styled_element(272,64,152,20,GetWidgetStyle(2),_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]))) != 0)
) {
	visual_button(272,64,152,20,vfh[2],16,0,_Context->msg_Auto619[_Context->language],strlen(_Context->msg_Auto619[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto619_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto621 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto621=visual_trigger_code(_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]));
						if (((_Context->status = visual_styled_element(272,84,152,20,GetWidgetStyle(3),_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]))) != 0)
) {
							visual_button(272,84,152,20,vfh[2],16,0,_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto621=visual_trigger_code(_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]));
						if (((_Context->status = visual_styled_element(272,84,152,20,GetWidgetStyle(2),_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]))) != 0)
) {
	visual_button(272,84,152,20,vfh[2],16,0,_Context->msg_Auto621[_Context->language],strlen(_Context->msg_Auto621[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto621_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto622 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
						if (((_Context->status = visual_styled_element(272,104,152,20,GetWidgetStyle(3),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
							visual_button(272,104,152,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto622=visual_trigger_code(_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]));
						if (((_Context->status = visual_styled_element(272,104,152,20,GetWidgetStyle(2),_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]))) != 0)
) {
	visual_button(272,104,152,20,vfh[2],16,0,_Context->msg_Auto622[_Context->language],strlen(_Context->msg_Auto622[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto622_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto623 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
						if (((_Context->status = visual_styled_element(272,124,152,20,GetWidgetStyle(3),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
							visual_button(272,124,152,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto623=visual_trigger_code(_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]));
						if (((_Context->status = visual_styled_element(272,124,152,20,GetWidgetStyle(2),_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]))) != 0)
) {
	visual_button(272,124,152,20,vfh[2],16,0,_Context->msg_Auto623[_Context->language],strlen(_Context->msg_Auto623[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto623_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto624 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
						if (((_Context->status = visual_styled_element(272,144,152,20,GetWidgetStyle(3),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
							visual_button(272,144,152,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto624=visual_trigger_code(_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]));
						if (((_Context->status = visual_styled_element(272,144,152,20,GetWidgetStyle(2),_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]))) != 0)
) {
	visual_button(272,144,152,20,vfh[2],16,0,_Context->msg_Auto624[_Context->language],strlen(_Context->msg_Auto624[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto624_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Auto625 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
						if (((_Context->status = visual_styled_element(272,164,152,20,GetWidgetStyle(3),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
							visual_button(272,164,152,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto625=visual_trigger_code(_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]));
						if (((_Context->status = visual_styled_element(272,164,152,20,GetWidgetStyle(2),_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]))) != 0)
) {
	visual_button(272,164,152,20,vfh[2],16,0,_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),32);
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
				_Context->focus_item=7;
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
