
#ifndef _viewmenu32a_c
#define _viewmenu32a_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : viewmenu32a.xml                                          */
/* Target         : viewmenu32a.c                                            */
/* Identification : 0.0-1196418873-3019.3018                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Frame   ""
#define en__Frame   ""
#define en_Auto331   "&Run..."
#define fr_Auto331   "&Ex‚cuter..."
#define it_Auto331   "&Run..."
#define es_Auto331   "&Run..."
#define de_Auto331   "&Run..."
#define nl_Auto331   "&Run..."
#define pt_Auto331   "&Run..."
#define xx_Auto331   "&Run..."
#define en__Auto331   ""
#define fr__Auto331   ""
#define it__Auto331   ""
#define es__Auto331   ""
#define de__Auto331   ""
#define nl__Auto331   ""
#define pt__Auto331   ""
#define xx__Auto331   ""
#define en_Auto332   "&Text"
#define fr_Auto332   "&Texte"
#define it_Auto332   "&Text"
#define es_Auto332   "&Text"
#define de_Auto332   "&Text"
#define nl_Auto332   "&Text"
#define pt_Auto332   "&Text"
#define xx_Auto332   "&Text"
#define en_Auto333   "&Image"
#define fr_Auto333   "&Image"
#define it_Auto333   "&Image"
#define es_Auto333   "&Image"
#define de_Auto333   "&Image"
#define nl_Auto333   "&Image"
#define pt_Auto333   "&Image"
#define xx_Auto333   "&Image"
#define en__Auto333   ""
#define en_Auto334   "&Font..."
#define fr_Auto334   "&Police..."
#define it_Auto334   "&Font..."
#define es_Auto334   "&Font..."
#define de_Auto334   "&Font..."
#define nl_Auto334   "&Font..."
#define pt_Auto334   "&Font..."
#define xx_Auto334   "&Font..."
#define en__Auto334   ""
#define fr__Auto334   ""
#define it__Auto334   ""
#define es__Auto334   ""
#define de__Auto334   ""
#define nl__Auto334   ""
#define pt__Auto334   ""
#define xx__Auto334   ""
#define en_Auto335   "&Properties..."
#define fr_Auto335   "P&ropri‚t‚s..."
#define it_Auto335   "&Production..."
#define es_Auto335   "&Production..."
#define de_Auto335   "&Produktion..."
#define nl_Auto335   "&Production..."
#define pt_Auto335   "&Production..."
#define xx_Auto335   "&Production..."
#define en__Auto335   ""
#define fr__Auto335   ""
#define it__Auto335   ""
#define es__Auto335   ""
#define de__Auto335   ""
#define nl__Auto335   ""
#define pt__Auto335   ""
#define xx__Auto335   ""
#define en_Auto336   "&Visual"
#define fr_Auto336   "E&space de travail"
#define it_Auto336   "&Visual"
#define es_Auto336   "&Visual"
#define de_Auto336   "&Visual"
#define nl_Auto336   "&Visual"
#define pt_Auto336   "&Visual"
#define xx_Auto336   "&Visual"
#define en__Auto336   ""
#define fr__Auto336   ""
#define it__Auto336   ""
#define es__Auto336   ""
#define de__Auto336   ""
#define nl__Auto336   ""
#define pt__Auto336   ""
#define xx__Auto336   ""
#define en_Auto337   "&Database"
#define fr_Auto337   "&Base de donn‚es..."
#define it_Auto337   "&DataBase..."
#define es_Auto337   "&DataBase..."
#define de_Auto337   "&DataBase..."
#define nl_Auto337   "&DataBase..."
#define pt_Auto337   "&DataBase..."
#define xx_Auto337   "&DataBase..."
#define en__Auto337   ""
#define fr__Auto337   ""
#define it__Auto337   ""
#define es__Auto337   ""
#define de__Auto337   ""
#define nl__Auto337   ""
#define pt__Auto337   ""
#define xx__Auto337   ""
#define en_Auto338   "&Style..."
#define fr_Auto338   "St&yle..."
#define it_Auto338   "&Style..."
#define es_Auto338   "&Style..."
#define de_Auto338   "&Style..."
#define nl_Auto338   "&Style..."
#define pt_Auto338   "&Style..."
#define xx_Auto338   "&Style..."
#define en__Auto338   ""
#define fr__Auto338   ""
#define it__Auto338   ""
#define es__Auto338   ""
#define de__Auto338   ""
#define nl__Auto338   ""
#define pt__Auto338   ""
#define xx__Auto338   ""
#define en_Auto339   "Tr&eeView"
#define fr_Auto339   "Arb&oresence projet"
#define it_Auto339   "Tr&eeView"
#define es_Auto339   "Tr&eeView"
#define de_Auto339   "Tr&eeView"
#define nl_Auto339   "Tr&eeView"
#define pt_Auto339   "Tr&eeView"
#define xx_Auto339   "Tr&eeView"
#define en__Auto339   ""
#define fr__Auto339   ""
#define it__Auto339   ""
#define es__Auto339   ""
#define de__Auto339   ""
#define nl__Auto339   ""
#define pt__Auto339   ""
#define xx__Auto339   ""
#define en_Auto340   "Appli&cation"
#define fr_Auto340   "Appli&cation"
#define it_Auto340   "Appli&cation"
#define es_Auto340   "Appli&cation"
#define de_Auto340   "Appli&cation"
#define nl_Auto340   "Appli&cation"
#define pt_Auto340   "Appli&cation"
#define xx_Auto340   "Appli&cation"
#define en__Auto340   ""

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
	char * msg_Auto331[8];
	int	trigger_Auto331;
	char * hint_Auto331[8];
	char * msg_Auto332[8];
	int	trigger_Auto332;
	char * hint_Auto332[8];
	char * msg_Auto333[8];
	int	trigger_Auto333;
	char * hint_Auto333[8];
	char * msg_Auto334[8];
	int	trigger_Auto334;
	char * hint_Auto334[8];
	char * msg_Auto335[8];
	int	trigger_Auto335;
	char * hint_Auto335[8];
	char * msg_Auto336[8];
	int	trigger_Auto336;
	char * hint_Auto336[8];
	char * msg_Auto337[8];
	int	trigger_Auto337;
	char * hint_Auto337[8];
	char * msg_Auto338[8];
	int	trigger_Auto338;
	char * hint_Auto338[8];
	char * msg_Auto339[8];
	int	trigger_Auto339;
	char * hint_Auto339[8];
	char * msg_Auto340[8];
	int	trigger_Auto340;
	char * hint_Auto340[8];
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
	_Context->focus_items=10;
	_Context->hint_Frame[0]=en__Frame;
	_Context->s_Frame=0;
	_Context->p_Frame=visual_buffer(128,32,168+2,220+2);
	(void) on_Frame_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Auto331[i]=" ";
	_Context->msg_Auto331[0]=en_Auto331;
	_Context->msg_Auto331[1]=fr_Auto331;
	_Context->msg_Auto331[2]=it_Auto331;
	_Context->msg_Auto331[3]=es_Auto331;
	_Context->msg_Auto331[4]=de_Auto331;
	_Context->msg_Auto331[5]=nl_Auto331;
	_Context->msg_Auto331[6]=pt_Auto331;
	_Context->msg_Auto331[7]=xx_Auto331;
	_Context->hint_Auto331[0]=en__Auto331;
	_Context->hint_Auto331[1]=fr__Auto331;
	_Context->hint_Auto331[2]=it__Auto331;
	_Context->hint_Auto331[3]=es__Auto331;
	_Context->hint_Auto331[4]=de__Auto331;
	_Context->hint_Auto331[5]=nl__Auto331;
	_Context->hint_Auto331[6]=pt__Auto331;
	_Context->hint_Auto331[7]=xx__Auto331;
	for (i=0; i < 8; i++)_Context->msg_Auto332[i]=" ";
	_Context->msg_Auto332[0]=en_Auto332;
	_Context->msg_Auto332[1]=fr_Auto332;
	_Context->msg_Auto332[2]=it_Auto332;
	_Context->msg_Auto332[3]=es_Auto332;
	_Context->msg_Auto332[4]=de_Auto332;
	_Context->msg_Auto332[5]=nl_Auto332;
	_Context->msg_Auto332[6]=pt_Auto332;
	_Context->msg_Auto332[7]=xx_Auto332;
	for (i=0; i < 8; i++)_Context->msg_Auto333[i]=" ";
	_Context->msg_Auto333[0]=en_Auto333;
	_Context->msg_Auto333[1]=fr_Auto333;
	_Context->msg_Auto333[2]=it_Auto333;
	_Context->msg_Auto333[3]=es_Auto333;
	_Context->msg_Auto333[4]=de_Auto333;
	_Context->msg_Auto333[5]=nl_Auto333;
	_Context->msg_Auto333[6]=pt_Auto333;
	_Context->msg_Auto333[7]=xx_Auto333;
	_Context->hint_Auto333[0]=en__Auto333;
	for (i=0; i < 8; i++)_Context->msg_Auto334[i]=" ";
	_Context->msg_Auto334[0]=en_Auto334;
	_Context->msg_Auto334[1]=fr_Auto334;
	_Context->msg_Auto334[2]=it_Auto334;
	_Context->msg_Auto334[3]=es_Auto334;
	_Context->msg_Auto334[4]=de_Auto334;
	_Context->msg_Auto334[5]=nl_Auto334;
	_Context->msg_Auto334[6]=pt_Auto334;
	_Context->msg_Auto334[7]=xx_Auto334;
	_Context->hint_Auto334[0]=en__Auto334;
	_Context->hint_Auto334[1]=fr__Auto334;
	_Context->hint_Auto334[2]=it__Auto334;
	_Context->hint_Auto334[3]=es__Auto334;
	_Context->hint_Auto334[4]=de__Auto334;
	_Context->hint_Auto334[5]=nl__Auto334;
	_Context->hint_Auto334[6]=pt__Auto334;
	_Context->hint_Auto334[7]=xx__Auto334;
	for (i=0; i < 8; i++)_Context->msg_Auto335[i]=" ";
	_Context->msg_Auto335[0]=en_Auto335;
	_Context->msg_Auto335[1]=fr_Auto335;
	_Context->msg_Auto335[2]=it_Auto335;
	_Context->msg_Auto335[3]=es_Auto335;
	_Context->msg_Auto335[4]=de_Auto335;
	_Context->msg_Auto335[5]=nl_Auto335;
	_Context->msg_Auto335[6]=pt_Auto335;
	_Context->msg_Auto335[7]=xx_Auto335;
	_Context->hint_Auto335[0]=en__Auto335;
	_Context->hint_Auto335[1]=fr__Auto335;
	_Context->hint_Auto335[2]=it__Auto335;
	_Context->hint_Auto335[3]=es__Auto335;
	_Context->hint_Auto335[4]=de__Auto335;
	_Context->hint_Auto335[5]=nl__Auto335;
	_Context->hint_Auto335[6]=pt__Auto335;
	_Context->hint_Auto335[7]=xx__Auto335;
	for (i=0; i < 8; i++)_Context->msg_Auto336[i]=" ";
	_Context->msg_Auto336[0]=en_Auto336;
	_Context->msg_Auto336[1]=fr_Auto336;
	_Context->msg_Auto336[2]=it_Auto336;
	_Context->msg_Auto336[3]=es_Auto336;
	_Context->msg_Auto336[4]=de_Auto336;
	_Context->msg_Auto336[5]=nl_Auto336;
	_Context->msg_Auto336[6]=pt_Auto336;
	_Context->msg_Auto336[7]=xx_Auto336;
	_Context->hint_Auto336[0]=en__Auto336;
	_Context->hint_Auto336[1]=fr__Auto336;
	_Context->hint_Auto336[2]=it__Auto336;
	_Context->hint_Auto336[3]=es__Auto336;
	_Context->hint_Auto336[4]=de__Auto336;
	_Context->hint_Auto336[5]=nl__Auto336;
	_Context->hint_Auto336[6]=pt__Auto336;
	_Context->hint_Auto336[7]=xx__Auto336;
	for (i=0; i < 8; i++)_Context->msg_Auto337[i]=" ";
	_Context->msg_Auto337[0]=en_Auto337;
	_Context->msg_Auto337[1]=fr_Auto337;
	_Context->msg_Auto337[2]=it_Auto337;
	_Context->msg_Auto337[3]=es_Auto337;
	_Context->msg_Auto337[4]=de_Auto337;
	_Context->msg_Auto337[5]=nl_Auto337;
	_Context->msg_Auto337[6]=pt_Auto337;
	_Context->msg_Auto337[7]=xx_Auto337;
	_Context->hint_Auto337[0]=en__Auto337;
	_Context->hint_Auto337[1]=fr__Auto337;
	_Context->hint_Auto337[2]=it__Auto337;
	_Context->hint_Auto337[3]=es__Auto337;
	_Context->hint_Auto337[4]=de__Auto337;
	_Context->hint_Auto337[5]=nl__Auto337;
	_Context->hint_Auto337[6]=pt__Auto337;
	_Context->hint_Auto337[7]=xx__Auto337;
	for (i=0; i < 8; i++)_Context->msg_Auto338[i]=" ";
	_Context->msg_Auto338[0]=en_Auto338;
	_Context->msg_Auto338[1]=fr_Auto338;
	_Context->msg_Auto338[2]=it_Auto338;
	_Context->msg_Auto338[3]=es_Auto338;
	_Context->msg_Auto338[4]=de_Auto338;
	_Context->msg_Auto338[5]=nl_Auto338;
	_Context->msg_Auto338[6]=pt_Auto338;
	_Context->msg_Auto338[7]=xx_Auto338;
	_Context->hint_Auto338[0]=en__Auto338;
	_Context->hint_Auto338[1]=fr__Auto338;
	_Context->hint_Auto338[2]=it__Auto338;
	_Context->hint_Auto338[3]=es__Auto338;
	_Context->hint_Auto338[4]=de__Auto338;
	_Context->hint_Auto338[5]=nl__Auto338;
	_Context->hint_Auto338[6]=pt__Auto338;
	_Context->hint_Auto338[7]=xx__Auto338;
	for (i=0; i < 8; i++)_Context->msg_Auto339[i]=" ";
	_Context->msg_Auto339[0]=en_Auto339;
	_Context->msg_Auto339[1]=fr_Auto339;
	_Context->msg_Auto339[2]=it_Auto339;
	_Context->msg_Auto339[3]=es_Auto339;
	_Context->msg_Auto339[4]=de_Auto339;
	_Context->msg_Auto339[5]=nl_Auto339;
	_Context->msg_Auto339[6]=pt_Auto339;
	_Context->msg_Auto339[7]=xx_Auto339;
	_Context->hint_Auto339[0]=en__Auto339;
	_Context->hint_Auto339[1]=fr__Auto339;
	_Context->hint_Auto339[2]=it__Auto339;
	_Context->hint_Auto339[3]=es__Auto339;
	_Context->hint_Auto339[4]=de__Auto339;
	_Context->hint_Auto339[5]=nl__Auto339;
	_Context->hint_Auto339[6]=pt__Auto339;
	_Context->hint_Auto339[7]=xx__Auto339;
	for (i=0; i < 8; i++)_Context->msg_Auto340[i]=" ";
	_Context->msg_Auto340[0]=en_Auto340;
	_Context->msg_Auto340[1]=fr_Auto340;
	_Context->msg_Auto340[2]=it_Auto340;
	_Context->msg_Auto340[3]=es_Auto340;
	_Context->msg_Auto340[4]=de_Auto340;
	_Context->msg_Auto340[5]=nl_Auto340;
	_Context->msg_Auto340[6]=pt_Auto340;
	_Context->msg_Auto340[7]=xx_Auto340;
	_Context->hint_Auto340[0]=en__Auto340;
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
	if (((_Context->status = visual_styled_element(128,32,168,220,GetWidgetStyle(1)," ",0)) != 0)
) {
		visual_filzone(128,32,168,220,27,11);
		}
	_Context->trigger_Auto331=visual_trigger_code(_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]));
	if (((_Context->status = visual_styled_element(144,44,134,20,GetWidgetStyle(2),_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]))) != 0)
) {
	visual_button(144,44,134,20,vfh[2],16,0,_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]),32);
		}
	_Context->trigger_Auto332=visual_trigger_code(_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]));
	if (((_Context->status = visual_styled_element(144,64,134,20,GetWidgetStyle(2),_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]))) != 0)
) {
	visual_button(144,64,134,20,vfh[2],16,0,_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]),32);
		}
	_Context->trigger_Auto333=visual_trigger_code(_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]));
	if (((_Context->status = visual_styled_element(144,84,134,20,GetWidgetStyle(2),_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]))) != 0)
) {
	visual_button(144,84,134,20,vfh[2],16,0,_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]),32);
		}
	_Context->trigger_Auto334=visual_trigger_code(_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]));
	if (((_Context->status = visual_styled_element(144,104,134,20,GetWidgetStyle(2),_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]))) != 0)
) {
	visual_button(144,104,134,20,vfh[2],16,0,_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]),32);
		}
	_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
	if (((_Context->status = visual_styled_element(144,124,134,20,GetWidgetStyle(2),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
	visual_button(144,124,134,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),32);
		}
	_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
	if (((_Context->status = visual_styled_element(144,144,134,20,GetWidgetStyle(2),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
	visual_button(144,144,134,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),32);
		}
	_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
	if (((_Context->status = visual_styled_element(144,164,134,20,GetWidgetStyle(2),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
	visual_button(144,164,134,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),32);
		}
	_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
	if (((_Context->status = visual_styled_element(144,224,134,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(144,224,134,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
		}
	_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
	if (((_Context->status = visual_styled_element(144,184,134,20,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(144,184,134,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
		}
	_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
	if (((_Context->status = visual_styled_element(144,204,134,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(144,204,134,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
		}
	visual_thaw(128,32,168,220);

	return(0);
}
private int on_Auto331_event(struct standard_view_menu_context * _Context) {
	return(_EXEC_PROG);
	return(-1);
}
private int on_Auto332_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_TEXT);
	return(-1);
}
private int on_Auto333_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_IMAGE);
	return(-1);
}
private int on_Auto334_event(struct standard_view_menu_context * _Context) {
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
private int on_Auto335_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_PROPERTIES);
	return(-1);
}
private int on_Auto336_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_FORM);
	return(-1);
}
private int on_Auto337_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_DATABASE);
	return(-1);
}
private int on_Auto338_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_STYLE);
	return(-1);
}
private int on_Auto339_event(struct standard_view_menu_context * _Context) {
	int result;
		standard_view_menu_hide(_Context);
;
	result=toggle_treeview();
		standard_view_menu_show(_Context);
;
	return(result);
	return(-1);
}
private int on_Auto340_event(struct standard_view_menu_context * _Context) {
	return(_EDIT_GRAPH);
	return(-1);
}


public	int	standard_view_menu_event(
struct standard_view_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto331 == mb ) return(1);
		if (_Context->trigger_Auto332 == mb ) return(2);
		if (_Context->trigger_Auto333 == mb ) return(3);
		if (_Context->trigger_Auto334 == mb ) return(4);
		if (_Context->trigger_Auto335 == mb ) return(5);
		if (_Context->trigger_Auto336 == mb ) return(6);
		if (_Context->trigger_Auto337 == mb ) return(7);
		if (_Context->trigger_Auto338 == mb ) return(8);
		if (_Context->trigger_Auto339 == mb ) return(9);
		if (_Context->trigger_Auto340 == mb ) return(10);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 144 ) 
	&&  ( my >= 44 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 64 )) {
		return(1); /* Auto331 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 64 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 84 )) {
		return(2); /* Auto332 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 84 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 104 )) {
		return(3); /* Auto333 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 104 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 124 )) {
		return(4); /* Auto334 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 124 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 144 )) {
		return(5); /* Auto335 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 144 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 164 )) {
		return(6); /* Auto336 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 164 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 184 )) {
		return(7); /* Auto337 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 224 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 244 )) {
		return(8); /* Auto338 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 184 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 204 )) {
		return(9); /* Auto339 */
		}
	if (( mx >= 144 ) 
	&&  ( my >= 204 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 224 )) {
		return(10); /* Auto340 */
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
				/* Auto331 */
				_Context->trigger_Auto331=visual_trigger_code(_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]));
				if (((_Context->status = visual_styled_element(144,44,134,20,GetWidgetStyle(3),_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]))) != 0)
) {
					visual_button(144,44,134,20,vfh[2],16,0,_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto331=visual_trigger_code(_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]));
				if (((_Context->status = visual_styled_element(144,44,134,20,GetWidgetStyle(2),_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]))) != 0)
) {
	visual_button(144,44,134,20,vfh[2],16,0,_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto332 */
				_Context->trigger_Auto332=visual_trigger_code(_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]));
				if (((_Context->status = visual_styled_element(144,64,134,20,GetWidgetStyle(3),_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]))) != 0)
) {
					visual_button(144,64,134,20,vfh[2],16,0,_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto332=visual_trigger_code(_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]));
				if (((_Context->status = visual_styled_element(144,64,134,20,GetWidgetStyle(2),_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]))) != 0)
) {
	visual_button(144,64,134,20,vfh[2],16,0,_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto333 */
				_Context->trigger_Auto333=visual_trigger_code(_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]));
				if (((_Context->status = visual_styled_element(144,84,134,20,GetWidgetStyle(3),_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]))) != 0)
) {
					visual_button(144,84,134,20,vfh[2],16,0,_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto333=visual_trigger_code(_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]));
				if (((_Context->status = visual_styled_element(144,84,134,20,GetWidgetStyle(2),_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]))) != 0)
) {
	visual_button(144,84,134,20,vfh[2],16,0,_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto334 */
				_Context->trigger_Auto334=visual_trigger_code(_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]));
				if (((_Context->status = visual_styled_element(144,104,134,20,GetWidgetStyle(3),_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]))) != 0)
) {
					visual_button(144,104,134,20,vfh[2],16,0,_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto334=visual_trigger_code(_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]));
				if (((_Context->status = visual_styled_element(144,104,134,20,GetWidgetStyle(2),_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]))) != 0)
) {
	visual_button(144,104,134,20,vfh[2],16,0,_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto335 */
				_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
				if (((_Context->status = visual_styled_element(144,124,134,20,GetWidgetStyle(3),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
					visual_button(144,124,134,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
				if (((_Context->status = visual_styled_element(144,124,134,20,GetWidgetStyle(2),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
	visual_button(144,124,134,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),32);
				}
				break;
			case	0x6 :
				/* Auto336 */
				_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
				if (((_Context->status = visual_styled_element(144,144,134,20,GetWidgetStyle(3),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
					visual_button(144,144,134,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
				if (((_Context->status = visual_styled_element(144,144,134,20,GetWidgetStyle(2),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
	visual_button(144,144,134,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),32);
				}
				break;
			case	0x7 :
				/* Auto337 */
				_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
				if (((_Context->status = visual_styled_element(144,164,134,20,GetWidgetStyle(3),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
					visual_button(144,164,134,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
				if (((_Context->status = visual_styled_element(144,164,134,20,GetWidgetStyle(2),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
	visual_button(144,164,134,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),32);
				}
				break;
			case	0x8 :
				/* Auto338 */
				_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
				if (((_Context->status = visual_styled_element(144,224,134,20,GetWidgetStyle(3),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
					visual_button(144,224,134,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
				if (((_Context->status = visual_styled_element(144,224,134,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(144,224,134,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
				}
				break;
			case	0x9 :
				/* Auto339 */
				_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
				if (((_Context->status = visual_styled_element(144,184,134,20,GetWidgetStyle(3),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
					visual_button(144,184,134,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
				if (((_Context->status = visual_styled_element(144,184,134,20,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(144,184,134,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
				}
				break;
			case	0xa :
				/* Auto340 */
				_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
				if (((_Context->status = visual_styled_element(144,204,134,20,GetWidgetStyle(3),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
					visual_button(144,204,134,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
				if (((_Context->status = visual_styled_element(144,204,134,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(144,204,134,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
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
			_Context->focus_item=10;
			standard_view_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  128 )
				|| ( visual_event(6) <  32 )
				|| ( visual_event(7) >  296 )
				|| ( visual_event(6) >  252 )) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=standard_view_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto331 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto331=visual_trigger_code(_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]));
						if (((_Context->status = visual_styled_element(144,44,134,20,GetWidgetStyle(3),_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]))) != 0)
) {
							visual_button(144,44,134,20,vfh[2],16,0,_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto331=visual_trigger_code(_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]));
						if (((_Context->status = visual_styled_element(144,44,134,20,GetWidgetStyle(2),_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]))) != 0)
) {
	visual_button(144,44,134,20,vfh[2],16,0,_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto331_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto332 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto332=visual_trigger_code(_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]));
						if (((_Context->status = visual_styled_element(144,64,134,20,GetWidgetStyle(3),_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]))) != 0)
) {
							visual_button(144,64,134,20,vfh[2],16,0,_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto332=visual_trigger_code(_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]));
						if (((_Context->status = visual_styled_element(144,64,134,20,GetWidgetStyle(2),_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]))) != 0)
) {
	visual_button(144,64,134,20,vfh[2],16,0,_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto332_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto333 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto333=visual_trigger_code(_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]));
						if (((_Context->status = visual_styled_element(144,84,134,20,GetWidgetStyle(3),_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]))) != 0)
) {
							visual_button(144,84,134,20,vfh[2],16,0,_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto333=visual_trigger_code(_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]));
						if (((_Context->status = visual_styled_element(144,84,134,20,GetWidgetStyle(2),_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]))) != 0)
) {
	visual_button(144,84,134,20,vfh[2],16,0,_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto333_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto334 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto334=visual_trigger_code(_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]));
						if (((_Context->status = visual_styled_element(144,104,134,20,GetWidgetStyle(3),_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]))) != 0)
) {
							visual_button(144,104,134,20,vfh[2],16,0,_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto334=visual_trigger_code(_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]));
						if (((_Context->status = visual_styled_element(144,104,134,20,GetWidgetStyle(2),_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]))) != 0)
) {
	visual_button(144,104,134,20,vfh[2],16,0,_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto334_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto335 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
						if (((_Context->status = visual_styled_element(144,124,134,20,GetWidgetStyle(3),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
							visual_button(144,124,134,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
						if (((_Context->status = visual_styled_element(144,124,134,20,GetWidgetStyle(2),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
	visual_button(144,124,134,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto335_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto336 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
						if (((_Context->status = visual_styled_element(144,144,134,20,GetWidgetStyle(3),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
							visual_button(144,144,134,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
						if (((_Context->status = visual_styled_element(144,144,134,20,GetWidgetStyle(2),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
	visual_button(144,144,134,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto336_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Auto337 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
						if (((_Context->status = visual_styled_element(144,164,134,20,GetWidgetStyle(3),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
							visual_button(144,164,134,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
						if (((_Context->status = visual_styled_element(144,164,134,20,GetWidgetStyle(2),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
	visual_button(144,164,134,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto337_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Auto338 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
						if (((_Context->status = visual_styled_element(144,224,134,20,GetWidgetStyle(3),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
							visual_button(144,224,134,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
						if (((_Context->status = visual_styled_element(144,224,134,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(144,224,134,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto338_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Auto339 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
						if (((_Context->status = visual_styled_element(144,184,134,20,GetWidgetStyle(3),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
							visual_button(144,184,134,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
						if (((_Context->status = visual_styled_element(144,184,134,20,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(144,184,134,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto339_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Auto340 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
						if (((_Context->status = visual_styled_element(144,204,134,20,GetWidgetStyle(3),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
							visual_button(144,204,134,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
						if (((_Context->status = visual_styled_element(144,204,134,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(144,204,134,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto340_event(_Context)) != -1) break;

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

#endif /* _viewmenu32a_c */
