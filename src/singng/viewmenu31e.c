
#ifndef _viewmenu31e_c
#define _viewmenu31e_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : viewmenu31e.xml                                          */
/* Target         : viewmenu31e.c                                            */
/* Identification : 0.0-1177512019-5209.5208                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Frame   ""
#define en__Frame   ""
#define en_Auto627   "&Run..."
#define fr_Auto627   "&Ex‚cuter..."
#define it_Auto627   "&Run..."
#define es_Auto627   "&Run..."
#define de_Auto627   "&Run..."
#define nl_Auto627   "&Run..."
#define pt_Auto627   "&Run..."
#define xx_Auto627   "&Run..."
#define en__Auto627   ""
#define fr__Auto627   ""
#define it__Auto627   ""
#define es__Auto627   ""
#define de__Auto627   ""
#define nl__Auto627   ""
#define pt__Auto627   ""
#define xx__Auto627   ""
#define en_Auto628   "&Text"
#define fr_Auto628   "&Texte"
#define it_Auto628   "&Text"
#define es_Auto628   "&Text"
#define de_Auto628   "&Text"
#define nl_Auto628   "&Text"
#define pt_Auto628   "&Text"
#define xx_Auto628   "&Text"
#define en_Auto629   "&Image"
#define fr_Auto629   "&Image"
#define it_Auto629   "&Image"
#define es_Auto629   "&Image"
#define de_Auto629   "&Image"
#define nl_Auto629   "&Image"
#define pt_Auto629   "&Image"
#define xx_Auto629   "&Image"
#define en__Auto629   ""
#define en_Auto630   "&Font..."
#define fr_Auto630   "P&olice..."
#define it_Auto630   "&Font..."
#define es_Auto630   "&Font..."
#define de_Auto630   "&Font..."
#define nl_Auto630   "&Font..."
#define pt_Auto630   "&Font..."
#define xx_Auto630   "&Font..."
#define en__Auto630   ""
#define fr__Auto630   ""
#define it__Auto630   ""
#define es__Auto630   ""
#define de__Auto630   ""
#define nl__Auto630   ""
#define pt__Auto630   ""
#define xx__Auto630   ""
#define en_Auto631   "&Properties..."
#define fr_Auto631   "&Propri‚t‚s..."
#define it_Auto631   "&Production..."
#define es_Auto631   "&Production..."
#define de_Auto631   "&Produktion..."
#define nl_Auto631   "&Production..."
#define pt_Auto631   "&Production..."
#define xx_Auto631   "&Production..."
#define en__Auto631   ""
#define fr__Auto631   ""
#define it__Auto631   ""
#define es__Auto631   ""
#define de__Auto631   ""
#define nl__Auto631   ""
#define pt__Auto631   ""
#define xx__Auto631   ""
#define en_Auto632   "&Visual"
#define fr_Auto632   "Espa&ce de travail"
#define it_Auto632   "&Visual"
#define es_Auto632   "&Visual"
#define de_Auto632   "&Visual"
#define nl_Auto632   "&Visual"
#define pt_Auto632   "&Visual"
#define xx_Auto632   "&Visual"
#define en__Auto632   ""
#define fr__Auto632   ""
#define it__Auto632   ""
#define es__Auto632   ""
#define de__Auto632   ""
#define nl__Auto632   ""
#define pt__Auto632   ""
#define xx__Auto632   ""
#define en_Auto633   "&DataBase..."
#define fr_Auto633   "&Base de donn‚es..."
#define it_Auto633   "&DataBase..."
#define es_Auto633   "&DataBase..."
#define de_Auto633   "&DataBase..."
#define nl_Auto633   "&DataBase..."
#define pt_Auto633   "&DataBase..."
#define xx_Auto633   "&DataBase..."
#define en__Auto633   ""
#define fr__Auto633   ""
#define it__Auto633   ""
#define es__Auto633   ""
#define de__Auto633   ""
#define nl__Auto633   ""
#define pt__Auto633   ""
#define xx__Auto633   ""
#define en_Auto634   "Tr&eeView"
#define fr_Auto634   "&Arboresence projet"
#define it_Auto634   "Tr&eeView"
#define es_Auto634   "Tr&eeView"
#define de_Auto634   "Tr&eeView"
#define nl_Auto634   "Tr&eeView"
#define pt_Auto634   "Tr&eeView"
#define xx_Auto634   "Tr&eeView"
#define en__Auto634   ""
#define fr__Auto634   ""
#define it__Auto634   ""
#define es__Auto634   ""
#define de__Auto634   ""
#define nl__Auto634   ""
#define pt__Auto634   ""
#define xx__Auto634   ""
#define en_Auto635   "&Application"
#define fr_Auto635   "App&lication"
#define it_Auto635   "&Application"
#define es_Auto635   "&Application"
#define de_Auto635   "&Application"
#define nl_Auto635   "&Application"
#define pt_Auto635   "&Application"
#define xx_Auto635   "&Application"
#define en__Auto635   ""

private struct standard_view_menu_context {
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
	char * msg_Auto627[8];
	int	trigger_Auto627;
	char * hint_Auto627[8];
	char * msg_Auto628[8];
	int	trigger_Auto628;
	char * hint_Auto628[8];
	char * msg_Auto629[8];
	int	trigger_Auto629;
	char * hint_Auto629[8];
	char * msg_Auto630[8];
	int	trigger_Auto630;
	char * hint_Auto630[8];
	char * msg_Auto631[8];
	int	trigger_Auto631;
	char * hint_Auto631[8];
	char * msg_Auto632[8];
	int	trigger_Auto632;
	char * hint_Auto632[8];
	char * msg_Auto633[8];
	int	trigger_Auto633;
	char * hint_Auto633[8];
	char * msg_Auto634[8];
	int	trigger_Auto634;
	char * hint_Auto634[8];
	char * msg_Auto635[8];
	int	trigger_Auto635;
	char * hint_Auto635[8];
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct standard_view_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = standard_view_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}

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
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct standard_view_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=9;
	_Context->hint_Frame[0]=en__Frame;
	_Context->s_Frame=0;
	_Context->p_Frame=visual_buffer(128,32,152+2,204+2);
	(void) on_Frame_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Auto627[i]=" ";
	_Context->msg_Auto627[0]=en_Auto627;
	_Context->msg_Auto627[1]=fr_Auto627;
	_Context->msg_Auto627[2]=it_Auto627;
	_Context->msg_Auto627[3]=es_Auto627;
	_Context->msg_Auto627[4]=de_Auto627;
	_Context->msg_Auto627[5]=nl_Auto627;
	_Context->msg_Auto627[6]=pt_Auto627;
	_Context->msg_Auto627[7]=xx_Auto627;
	_Context->hint_Auto627[0]=en__Auto627;
	_Context->hint_Auto627[1]=fr__Auto627;
	_Context->hint_Auto627[2]=it__Auto627;
	_Context->hint_Auto627[3]=es__Auto627;
	_Context->hint_Auto627[4]=de__Auto627;
	_Context->hint_Auto627[5]=nl__Auto627;
	_Context->hint_Auto627[6]=pt__Auto627;
	_Context->hint_Auto627[7]=xx__Auto627;
	for (i=0; i < 8; i++)_Context->msg_Auto628[i]=" ";
	_Context->msg_Auto628[0]=en_Auto628;
	_Context->msg_Auto628[1]=fr_Auto628;
	_Context->msg_Auto628[2]=it_Auto628;
	_Context->msg_Auto628[3]=es_Auto628;
	_Context->msg_Auto628[4]=de_Auto628;
	_Context->msg_Auto628[5]=nl_Auto628;
	_Context->msg_Auto628[6]=pt_Auto628;
	_Context->msg_Auto628[7]=xx_Auto628;
	for (i=0; i < 8; i++)_Context->msg_Auto629[i]=" ";
	_Context->msg_Auto629[0]=en_Auto629;
	_Context->msg_Auto629[1]=fr_Auto629;
	_Context->msg_Auto629[2]=it_Auto629;
	_Context->msg_Auto629[3]=es_Auto629;
	_Context->msg_Auto629[4]=de_Auto629;
	_Context->msg_Auto629[5]=nl_Auto629;
	_Context->msg_Auto629[6]=pt_Auto629;
	_Context->msg_Auto629[7]=xx_Auto629;
	_Context->hint_Auto629[0]=en__Auto629;
	for (i=0; i < 8; i++)_Context->msg_Auto630[i]=" ";
	_Context->msg_Auto630[0]=en_Auto630;
	_Context->msg_Auto630[1]=fr_Auto630;
	_Context->msg_Auto630[2]=it_Auto630;
	_Context->msg_Auto630[3]=es_Auto630;
	_Context->msg_Auto630[4]=de_Auto630;
	_Context->msg_Auto630[5]=nl_Auto630;
	_Context->msg_Auto630[6]=pt_Auto630;
	_Context->msg_Auto630[7]=xx_Auto630;
	_Context->hint_Auto630[0]=en__Auto630;
	_Context->hint_Auto630[1]=fr__Auto630;
	_Context->hint_Auto630[2]=it__Auto630;
	_Context->hint_Auto630[3]=es__Auto630;
	_Context->hint_Auto630[4]=de__Auto630;
	_Context->hint_Auto630[5]=nl__Auto630;
	_Context->hint_Auto630[6]=pt__Auto630;
	_Context->hint_Auto630[7]=xx__Auto630;
	for (i=0; i < 8; i++)_Context->msg_Auto631[i]=" ";
	_Context->msg_Auto631[0]=en_Auto631;
	_Context->msg_Auto631[1]=fr_Auto631;
	_Context->msg_Auto631[2]=it_Auto631;
	_Context->msg_Auto631[3]=es_Auto631;
	_Context->msg_Auto631[4]=de_Auto631;
	_Context->msg_Auto631[5]=nl_Auto631;
	_Context->msg_Auto631[6]=pt_Auto631;
	_Context->msg_Auto631[7]=xx_Auto631;
	_Context->hint_Auto631[0]=en__Auto631;
	_Context->hint_Auto631[1]=fr__Auto631;
	_Context->hint_Auto631[2]=it__Auto631;
	_Context->hint_Auto631[3]=es__Auto631;
	_Context->hint_Auto631[4]=de__Auto631;
	_Context->hint_Auto631[5]=nl__Auto631;
	_Context->hint_Auto631[6]=pt__Auto631;
	_Context->hint_Auto631[7]=xx__Auto631;
	for (i=0; i < 8; i++)_Context->msg_Auto632[i]=" ";
	_Context->msg_Auto632[0]=en_Auto632;
	_Context->msg_Auto632[1]=fr_Auto632;
	_Context->msg_Auto632[2]=it_Auto632;
	_Context->msg_Auto632[3]=es_Auto632;
	_Context->msg_Auto632[4]=de_Auto632;
	_Context->msg_Auto632[5]=nl_Auto632;
	_Context->msg_Auto632[6]=pt_Auto632;
	_Context->msg_Auto632[7]=xx_Auto632;
	_Context->hint_Auto632[0]=en__Auto632;
	_Context->hint_Auto632[1]=fr__Auto632;
	_Context->hint_Auto632[2]=it__Auto632;
	_Context->hint_Auto632[3]=es__Auto632;
	_Context->hint_Auto632[4]=de__Auto632;
	_Context->hint_Auto632[5]=nl__Auto632;
	_Context->hint_Auto632[6]=pt__Auto632;
	_Context->hint_Auto632[7]=xx__Auto632;
	for (i=0; i < 8; i++)_Context->msg_Auto633[i]=" ";
	_Context->msg_Auto633[0]=en_Auto633;
	_Context->msg_Auto633[1]=fr_Auto633;
	_Context->msg_Auto633[2]=it_Auto633;
	_Context->msg_Auto633[3]=es_Auto633;
	_Context->msg_Auto633[4]=de_Auto633;
	_Context->msg_Auto633[5]=nl_Auto633;
	_Context->msg_Auto633[6]=pt_Auto633;
	_Context->msg_Auto633[7]=xx_Auto633;
	_Context->hint_Auto633[0]=en__Auto633;
	_Context->hint_Auto633[1]=fr__Auto633;
	_Context->hint_Auto633[2]=it__Auto633;
	_Context->hint_Auto633[3]=es__Auto633;
	_Context->hint_Auto633[4]=de__Auto633;
	_Context->hint_Auto633[5]=nl__Auto633;
	_Context->hint_Auto633[6]=pt__Auto633;
	_Context->hint_Auto633[7]=xx__Auto633;
	for (i=0; i < 8; i++)_Context->msg_Auto634[i]=" ";
	_Context->msg_Auto634[0]=en_Auto634;
	_Context->msg_Auto634[1]=fr_Auto634;
	_Context->msg_Auto634[2]=it_Auto634;
	_Context->msg_Auto634[3]=es_Auto634;
	_Context->msg_Auto634[4]=de_Auto634;
	_Context->msg_Auto634[5]=nl_Auto634;
	_Context->msg_Auto634[6]=pt_Auto634;
	_Context->msg_Auto634[7]=xx_Auto634;
	_Context->hint_Auto634[0]=en__Auto634;
	_Context->hint_Auto634[1]=fr__Auto634;
	_Context->hint_Auto634[2]=it__Auto634;
	_Context->hint_Auto634[3]=es__Auto634;
	_Context->hint_Auto634[4]=de__Auto634;
	_Context->hint_Auto634[5]=nl__Auto634;
	_Context->hint_Auto634[6]=pt__Auto634;
	_Context->hint_Auto634[7]=xx__Auto634;
	for (i=0; i < 8; i++)_Context->msg_Auto635[i]=" ";
	_Context->msg_Auto635[0]=en_Auto635;
	_Context->msg_Auto635[1]=fr_Auto635;
	_Context->msg_Auto635[2]=it_Auto635;
	_Context->msg_Auto635[3]=es_Auto635;
	_Context->msg_Auto635[4]=de_Auto635;
	_Context->msg_Auto635[5]=nl_Auto635;
	_Context->msg_Auto635[6]=pt_Auto635;
	_Context->msg_Auto635[7]=xx_Auto635;
	_Context->hint_Auto635[0]=en__Auto635;
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
	if (((_Context->status = visual_styled_element(128,32,152,204,GetWidgetStyle(1)," ",0)) != 0)
) {
		visual_filzone(128,32,152,204,27,11);
		}
	_Context->trigger_Auto627=visual_trigger_code(_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]));
	if (((_Context->status = visual_styled_element(144,44,120,20,"menutray_label",_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]))) != 0)
) {
	visual_button(144,44,120,20,vfh[2],16,0,_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]),32);
		}
	_Context->trigger_Auto628=visual_trigger_code(_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]));
	if (((_Context->status = visual_styled_element(144,64,120,20,"menutray_label",_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]))) != 0)
) {
	visual_button(144,64,120,20,vfh[2],16,0,_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]),32);
		}
	_Context->trigger_Auto629=visual_trigger_code(_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]));
	if (((_Context->status = visual_styled_element(144,84,120,20,"menutray_label",_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]))) != 0)
) {
	visual_button(144,84,120,20,vfh[2],16,0,_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]),32);
		}
	_Context->trigger_Auto630=visual_trigger_code(_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]));
	if (((_Context->status = visual_styled_element(144,104,120,20,"menutray_label",_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]))) != 0)
) {
	visual_button(144,104,120,20,vfh[2],16,0,_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]),32);
		}
	_Context->trigger_Auto631=visual_trigger_code(_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]));
	if (((_Context->status = visual_styled_element(144,124,120,20,"menutray_label",_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]))) != 0)
) {
	visual_button(144,124,120,20,vfh[2],16,0,_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]),32);
		}
	_Context->trigger_Auto632=visual_trigger_code(_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]));
	if (((_Context->status = visual_styled_element(144,144,120,20,"menutray_label",_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]))) != 0)
) {
	visual_button(144,144,120,20,vfh[2],16,0,_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]),32);
		}
	_Context->trigger_Auto633=visual_trigger_code(_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]));
	if (((_Context->status = visual_styled_element(144,164,120,20,"menutray_label",_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]))) != 0)
) {
	visual_button(144,164,120,20,vfh[2],16,0,_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]),32);
		}
	_Context->trigger_Auto634=visual_trigger_code(_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]));
	if (((_Context->status = visual_styled_element(144,184,120,20,"menutray_label",_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]))) != 0)
) {
	visual_button(144,184,120,20,vfh[2],16,0,_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]),32);
		}
	_Context->trigger_Auto635=visual_trigger_code(_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]));
	if (((_Context->status = visual_styled_element(144,204,120,20,"menutray_label",_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]))) != 0)
) {
	visual_button(144,204,120,20,vfh[2],16,0,_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]),32);
		}
	visual_thaw(128,32,152,204);

	return(0);
}
private int on_Auto627_event(struct standard_view_menu_context * _Context) {
	return(_EXEC_PROG);
	return(-1);
}
private int on_Auto628_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_TEXT);
	return(-1);
}
private int on_Auto629_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_IMAGE);
	return(-1);
}
private int on_Auto630_event(struct standard_view_menu_context * _Context) {
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
private int on_Auto631_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_PROPERTIES);
	return(-1);
}
private int on_Auto632_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_FORM);
	return(-1);
}
private int on_Auto633_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_DATABASE);
	return(-1);
}
private int on_Auto634_event(struct standard_view_menu_context * _Context) {
	int result;
		standard_view_menu_hide(_Context);
;
	result=toggle_treeview();
		standard_view_menu_show(_Context);
;
	return(result);
	return(-1);
}
private int on_Auto635_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_GRAPH);
	return(-1);
}


public	int	standard_view_menu_event(
struct standard_view_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto627 == mb ) return(1);
		if (_Context->trigger_Auto628 == mb ) return(2);
		if (_Context->trigger_Auto629 == mb ) return(3);
		if (_Context->trigger_Auto630 == mb ) return(4);
		if (_Context->trigger_Auto631 == mb ) return(5);
		if (_Context->trigger_Auto632 == mb ) return(6);
		if (_Context->trigger_Auto633 == mb ) return(7);
		if (_Context->trigger_Auto634 == mb ) return(8);
		if (_Context->trigger_Auto635 == mb ) return(9);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 144 ) 
	&&  ( my >= 44 ) 
	&&  ( mx <= 264 ) 
	&&  ( my <= 64 )) {
		return(1); /* Auto627 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 64 ) 
	&&  ( mx <= 264 ) 
	&&  ( my <= 84 )) {
		return(2); /* Auto628 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 84 ) 
	&&  ( mx <= 264 ) 
	&&  ( my <= 104 )) {
		return(3); /* Auto629 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 104 ) 
	&&  ( mx <= 264 ) 
	&&  ( my <= 124 )) {
		return(4); /* Auto630 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 124 ) 
	&&  ( mx <= 264 ) 
	&&  ( my <= 144 )) {
		return(5); /* Auto631 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 144 ) 
	&&  ( mx <= 264 ) 
	&&  ( my <= 164 )) {
		return(6); /* Auto632 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 164 ) 
	&&  ( mx <= 264 ) 
	&&  ( my <= 184 )) {
		return(7); /* Auto633 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 184 ) 
	&&  ( mx <= 264 ) 
	&&  ( my <= 204 )) {
		return(8); /* Auto634 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 204 ) 
	&&  ( mx <= 264 ) 
	&&  ( my <= 224 )) {
		return(9); /* Auto635 */
		}

	return(-1);
}


public	int	standard_view_menu_focus(struct standard_view_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto627 */
				_Context->trigger_Auto627=visual_trigger_code(_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]));
				visual_button(144,44,120,20,vfh[2],16,0,_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]),34);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto627=visual_trigger_code(_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]));
				if (((_Context->status = visual_styled_element(144,44,120,20,"menutray_label",_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]))) != 0)
) {
	visual_button(144,44,120,20,vfh[2],16,0,_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto628 */
				_Context->trigger_Auto628=visual_trigger_code(_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]));
				visual_button(144,64,120,20,vfh[2],16,0,_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]),34);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto628=visual_trigger_code(_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]));
				if (((_Context->status = visual_styled_element(144,64,120,20,"menutray_label",_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]))) != 0)
) {
	visual_button(144,64,120,20,vfh[2],16,0,_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto629 */
				_Context->trigger_Auto629=visual_trigger_code(_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]));
				visual_button(144,84,120,20,vfh[2],16,0,_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]),34);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto629=visual_trigger_code(_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]));
				if (((_Context->status = visual_styled_element(144,84,120,20,"menutray_label",_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]))) != 0)
) {
	visual_button(144,84,120,20,vfh[2],16,0,_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto630 */
				_Context->trigger_Auto630=visual_trigger_code(_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]));
				visual_button(144,104,120,20,vfh[2],16,0,_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]),34);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto630=visual_trigger_code(_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]));
				if (((_Context->status = visual_styled_element(144,104,120,20,"menutray_label",_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]))) != 0)
) {
	visual_button(144,104,120,20,vfh[2],16,0,_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto631 */
				_Context->trigger_Auto631=visual_trigger_code(_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]));
				visual_button(144,124,120,20,vfh[2],16,0,_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]),34);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto631=visual_trigger_code(_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]));
				if (((_Context->status = visual_styled_element(144,124,120,20,"menutray_label",_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]))) != 0)
) {
	visual_button(144,124,120,20,vfh[2],16,0,_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]),32);
				}
				break;
			case	0x6 :
				/* Auto632 */
				_Context->trigger_Auto632=visual_trigger_code(_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]));
				visual_button(144,144,120,20,vfh[2],16,0,_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]),34);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto632=visual_trigger_code(_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]));
				if (((_Context->status = visual_styled_element(144,144,120,20,"menutray_label",_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]))) != 0)
) {
	visual_button(144,144,120,20,vfh[2],16,0,_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]),32);
				}
				break;
			case	0x7 :
				/* Auto633 */
				_Context->trigger_Auto633=visual_trigger_code(_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]));
				visual_button(144,164,120,20,vfh[2],16,0,_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]),34);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto633=visual_trigger_code(_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]));
				if (((_Context->status = visual_styled_element(144,164,120,20,"menutray_label",_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]))) != 0)
) {
	visual_button(144,164,120,20,vfh[2],16,0,_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]),32);
				}
				break;
			case	0x8 :
				/* Auto634 */
				_Context->trigger_Auto634=visual_trigger_code(_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]));
				visual_button(144,184,120,20,vfh[2],16,0,_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]),34);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto634=visual_trigger_code(_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]));
				if (((_Context->status = visual_styled_element(144,184,120,20,"menutray_label",_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]))) != 0)
) {
	visual_button(144,184,120,20,vfh[2],16,0,_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]),32);
				}
				break;
			case	0x9 :
				/* Auto635 */
				_Context->trigger_Auto635=visual_trigger_code(_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]));
				visual_button(144,204,120,20,vfh[2],16,0,_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]),34);
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto635=visual_trigger_code(_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]));
				if (((_Context->status = visual_styled_element(144,204,120,20,"menutray_label",_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]))) != 0)
) {
	visual_button(144,204,120,20,vfh[2],16,0,_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]),32);
				}
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
				|| ( visual_event(7) >  280 )
				|| ( visual_event(6) >  236 )) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=standard_view_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto627 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto627=visual_trigger_code(_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]));
						visual_button(144,44,120,20,vfh[2],16,0,_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]),34);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto627=visual_trigger_code(_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]));
						if (((_Context->status = visual_styled_element(144,44,120,20,"menutray_label",_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]))) != 0)
) {
	visual_button(144,44,120,20,vfh[2],16,0,_Context->msg_Auto627[_Context->language],strlen(_Context->msg_Auto627[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto627_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto628 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto628=visual_trigger_code(_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]));
						visual_button(144,64,120,20,vfh[2],16,0,_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]),34);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto628=visual_trigger_code(_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]));
						if (((_Context->status = visual_styled_element(144,64,120,20,"menutray_label",_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]))) != 0)
) {
	visual_button(144,64,120,20,vfh[2],16,0,_Context->msg_Auto628[_Context->language],strlen(_Context->msg_Auto628[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto628_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto629 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto629=visual_trigger_code(_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]));
						visual_button(144,84,120,20,vfh[2],16,0,_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]),34);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto629=visual_trigger_code(_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]));
						if (((_Context->status = visual_styled_element(144,84,120,20,"menutray_label",_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]))) != 0)
) {
	visual_button(144,84,120,20,vfh[2],16,0,_Context->msg_Auto629[_Context->language],strlen(_Context->msg_Auto629[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto629_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto630 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto630=visual_trigger_code(_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]));
						visual_button(144,104,120,20,vfh[2],16,0,_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]),34);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto630=visual_trigger_code(_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]));
						if (((_Context->status = visual_styled_element(144,104,120,20,"menutray_label",_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]))) != 0)
) {
	visual_button(144,104,120,20,vfh[2],16,0,_Context->msg_Auto630[_Context->language],strlen(_Context->msg_Auto630[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto630_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto631 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto631=visual_trigger_code(_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]));
						visual_button(144,124,120,20,vfh[2],16,0,_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]),34);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto631=visual_trigger_code(_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]));
						if (((_Context->status = visual_styled_element(144,124,120,20,"menutray_label",_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]))) != 0)
) {
	visual_button(144,124,120,20,vfh[2],16,0,_Context->msg_Auto631[_Context->language],strlen(_Context->msg_Auto631[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto631_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto632 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto632=visual_trigger_code(_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]));
						visual_button(144,144,120,20,vfh[2],16,0,_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]),34);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto632=visual_trigger_code(_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]));
						if (((_Context->status = visual_styled_element(144,144,120,20,"menutray_label",_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]))) != 0)
) {
	visual_button(144,144,120,20,vfh[2],16,0,_Context->msg_Auto632[_Context->language],strlen(_Context->msg_Auto632[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto632_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Auto633 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto633=visual_trigger_code(_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]));
						visual_button(144,164,120,20,vfh[2],16,0,_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]),34);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto633=visual_trigger_code(_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]));
						if (((_Context->status = visual_styled_element(144,164,120,20,"menutray_label",_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]))) != 0)
) {
	visual_button(144,164,120,20,vfh[2],16,0,_Context->msg_Auto633[_Context->language],strlen(_Context->msg_Auto633[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto633_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Auto634 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto634=visual_trigger_code(_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]));
						visual_button(144,184,120,20,vfh[2],16,0,_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]),34);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto634=visual_trigger_code(_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]));
						if (((_Context->status = visual_styled_element(144,184,120,20,"menutray_label",_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]))) != 0)
) {
	visual_button(144,184,120,20,vfh[2],16,0,_Context->msg_Auto634[_Context->language],strlen(_Context->msg_Auto634[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto634_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Auto635 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto635=visual_trigger_code(_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]));
						visual_button(144,204,120,20,vfh[2],16,0,_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]),34);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto635=visual_trigger_code(_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]));
						if (((_Context->status = visual_styled_element(144,204,120,20,"menutray_label",_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]))) != 0)
) {
	visual_button(144,204,120,20,vfh[2],16,0,_Context->msg_Auto635[_Context->language],strlen(_Context->msg_Auto635[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto635_event(_Context)) != -1) break;

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

#endif /* _viewmenu31e_c */
