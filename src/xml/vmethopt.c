
#ifndef _vmethopt_c
#define _vmethopt_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : vmethopt.xml                                             */
/* Target         : vmethopt.c                                               */
/* Identification : 0.0-1197099568-13229.13228                               */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Auto334   ""
#define en__Auto334   ""
#define en_Auto335   "&Create without sizes"
#define fr_Auto335   "&Create without sizes"
#define it_Auto335   "&Create without sizes"
#define es_Auto335   "&Create without sizes"
#define de_Auto335   "&Create without sizes"
#define nl_Auto335   "&Create without sizes"
#define pt_Auto335   "&Create without sizes"
#define xx_Auto335   "&Create without sizes"
#define en__Auto335   ""
#define fr__Auto335   ""
#define it__Auto335   ""
#define es__Auto335   ""
#define de__Auto335   ""
#define nl__Auto335   ""
#define pt__Auto335   ""
#define xx__Auto335   ""
#define en_Auto336   "C&reate with sizes"
#define fr_Auto336   "C&reate with sizes"
#define it_Auto336   "C&reate with sizes"
#define es_Auto336   "C&reate with sizes"
#define de_Auto336   "C&reate with sizes"
#define nl_Auto336   "C&reate with sizes"
#define pt_Auto336   "C&reate with sizes"
#define xx_Auto336   "C&reate with sizes"
#define en__Auto336   ""
#define fr__Auto336   ""
#define it__Auto336   ""
#define es__Auto336   ""
#define de__Auto336   ""
#define nl__Auto336   ""
#define pt__Auto336   ""
#define xx__Auto336   ""
#define en_Auto337   "&Show Automatic"
#define fr_Auto337   "&Show Automatic"
#define it_Auto337   "&Show Automatic"
#define es_Auto337   "&Show Automatic"
#define de_Auto337   "&Show Automatic"
#define nl_Auto337   "&Show Automatic"
#define pt_Auto337   "&Show Automatic"
#define xx_Auto337   "&Show Automatic"
#define en__Auto337   ""
#define fr__Auto337   ""
#define it__Auto337   ""
#define es__Auto337   ""
#define de__Auto337   ""
#define nl__Auto337   ""
#define pt__Auto337   ""
#define xx__Auto337   ""
#define en_Auto338   "S&how Conditional"
#define fr_Auto338   "S&how Conditional"
#define it_Auto338   "S&how Conditional"
#define es_Auto338   "S&how Conditional"
#define de_Auto338   "S&how Conditional"
#define nl_Auto338   "S&how Conditional"
#define pt_Auto338   "S&how Conditional"
#define xx_Auto338   "S&how Conditional"
#define en__Auto338   ""
#define fr__Auto338   ""
#define it__Auto338   ""
#define es__Auto338   ""
#define de__Auto338   ""
#define nl__Auto338   ""
#define pt__Auto338   ""
#define xx__Auto338   ""
#define en_Auto339   "&With Focus"
#define fr_Auto339   "&With Focus"
#define it_Auto339   "&With Focus"
#define es_Auto339   "&With Focus"
#define de_Auto339   "&With Focus"
#define nl_Auto339   "&With Focus"
#define pt_Auto339   "&With Focus"
#define xx_Auto339   "&With Focus"
#define en__Auto339   ""
#define fr__Auto339   ""
#define it__Auto339   ""
#define es__Auto339   ""
#define de__Auto339   ""
#define nl__Auto339   ""
#define pt__Auto339   ""
#define xx__Auto339   ""
#define en_Auto340   "W&ithout Focus"
#define fr_Auto340   "W&ithout Focus"
#define it_Auto340   "W&ithout Focus"
#define es_Auto340   "W&ithout Focus"
#define de_Auto340   "W&ithout Focus"
#define nl_Auto340   "W&ithout Focus"
#define pt_Auto340   "W&ithout Focus"
#define xx_Auto340   "W&ithout Focus"
#define en__Auto340   ""
#define fr__Auto340   ""
#define it__Auto340   ""
#define es__Auto340   ""
#define de__Auto340   ""
#define nl__Auto340   ""
#define pt__Auto340   ""
#define xx__Auto340   ""
#define en_Auto341   "Wi&th Event"
#define fr_Auto341   "Wi&th Event"
#define it_Auto341   "Wi&th Event"
#define es_Auto341   "Wi&th Event"
#define de_Auto341   "Wi&th Event"
#define nl_Auto341   "Wi&th Event"
#define pt_Auto341   "Wi&th Event"
#define xx_Auto341   "Wi&th Event"
#define en__Auto341   ""
#define fr__Auto341   ""
#define it__Auto341   ""
#define es__Auto341   ""
#define de__Auto341   ""
#define nl__Auto341   ""
#define pt__Auto341   ""
#define xx__Auto341   ""
#define en_Auto342   "With&out Event"
#define fr_Auto342   "With&out Event"
#define it_Auto342   "With&out Event"
#define es_Auto342   "With&out Event"
#define de_Auto342   "With&out Event"
#define nl_Auto342   "With&out Event"
#define pt_Auto342   "With&out Event"
#define xx_Auto342   "With&out Event"
#define en__Auto342   ""
#define fr__Auto342   ""
#define it__Auto342   ""
#define es__Auto342   ""
#define de__Auto342   ""
#define nl__Auto342   ""
#define pt__Auto342   ""
#define xx__Auto342   ""
#define en_Auto343   "Witho&ut Popup"
#define fr_Auto343   "Witho&ut Popup"
#define it_Auto343   "Witho&ut Popup"
#define es_Auto343   "Witho&ut Popup"
#define de_Auto343   "Witho&ut Popup"
#define nl_Auto343   "Witho&ut Popup"
#define pt_Auto343   "Witho&ut Popup"
#define xx_Auto343   "Witho&ut Popup"
#define en__Auto343   ""
#define fr__Auto343   ""
#define it__Auto343   ""
#define es__Auto343   ""
#define de__Auto343   ""
#define nl__Auto343   ""
#define pt__Auto343   ""
#define xx__Auto343   ""
#define en_Auto344   "With &Popup"
#define fr_Auto344   "With &Popup"
#define it_Auto344   "With &Popup"
#define es_Auto344   "With &Popup"
#define de_Auto344   "With &Popup"
#define nl_Auto344   "With &Popup"
#define pt_Auto344   "With &Popup"
#define xx_Auto344   "With &Popup"
#define en__Auto344   ""
#define fr__Auto344   ""
#define it__Auto344   ""
#define es__Auto344   ""
#define de__Auto344   ""
#define nl__Auto344   ""
#define pt__Auto344   ""
#define xx__Auto344   ""

private struct widget_event_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * hint_Auto334[8];
	int	s_Auto334;
	void *	p_Auto334;
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
	char * msg_Auto341[8];
	int	trigger_Auto341;
	char * hint_Auto341[8];
	char * msg_Auto342[8];
	int	trigger_Auto342;
	char * hint_Auto342[8];
	char * msg_Auto343[8];
	int	trigger_Auto343;
	char * hint_Auto343[8];
	char * msg_Auto344[8];
	int	trigger_Auto344;
	char * hint_Auto344[8];
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct widget_event_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = widget_event_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}


public	int	widget_event_menu_create(struct widget_event_menu_context **cptr)
{

	int i;
	struct widget_event_menu_context * _Context=(struct widget_event_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct widget_event_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=10;
	_Context->hint_Auto334[0]=en__Auto334;
	_Context->s_Auto334=0;
	_Context->p_Auto334=visual_buffer(384,32,248+2,224+2);
	mouse_move_on();
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
	_Context->hint_Auto340[1]=fr__Auto340;
	_Context->hint_Auto340[2]=it__Auto340;
	_Context->hint_Auto340[3]=es__Auto340;
	_Context->hint_Auto340[4]=de__Auto340;
	_Context->hint_Auto340[5]=nl__Auto340;
	_Context->hint_Auto340[6]=pt__Auto340;
	_Context->hint_Auto340[7]=xx__Auto340;
	for (i=0; i < 8; i++)_Context->msg_Auto341[i]=" ";
	_Context->msg_Auto341[0]=en_Auto341;
	_Context->msg_Auto341[1]=fr_Auto341;
	_Context->msg_Auto341[2]=it_Auto341;
	_Context->msg_Auto341[3]=es_Auto341;
	_Context->msg_Auto341[4]=de_Auto341;
	_Context->msg_Auto341[5]=nl_Auto341;
	_Context->msg_Auto341[6]=pt_Auto341;
	_Context->msg_Auto341[7]=xx_Auto341;
	_Context->hint_Auto341[0]=en__Auto341;
	_Context->hint_Auto341[1]=fr__Auto341;
	_Context->hint_Auto341[2]=it__Auto341;
	_Context->hint_Auto341[3]=es__Auto341;
	_Context->hint_Auto341[4]=de__Auto341;
	_Context->hint_Auto341[5]=nl__Auto341;
	_Context->hint_Auto341[6]=pt__Auto341;
	_Context->hint_Auto341[7]=xx__Auto341;
	for (i=0; i < 8; i++)_Context->msg_Auto342[i]=" ";
	_Context->msg_Auto342[0]=en_Auto342;
	_Context->msg_Auto342[1]=fr_Auto342;
	_Context->msg_Auto342[2]=it_Auto342;
	_Context->msg_Auto342[3]=es_Auto342;
	_Context->msg_Auto342[4]=de_Auto342;
	_Context->msg_Auto342[5]=nl_Auto342;
	_Context->msg_Auto342[6]=pt_Auto342;
	_Context->msg_Auto342[7]=xx_Auto342;
	_Context->hint_Auto342[0]=en__Auto342;
	_Context->hint_Auto342[1]=fr__Auto342;
	_Context->hint_Auto342[2]=it__Auto342;
	_Context->hint_Auto342[3]=es__Auto342;
	_Context->hint_Auto342[4]=de__Auto342;
	_Context->hint_Auto342[5]=nl__Auto342;
	_Context->hint_Auto342[6]=pt__Auto342;
	_Context->hint_Auto342[7]=xx__Auto342;
	for (i=0; i < 8; i++)_Context->msg_Auto343[i]=" ";
	_Context->msg_Auto343[0]=en_Auto343;
	_Context->msg_Auto343[1]=fr_Auto343;
	_Context->msg_Auto343[2]=it_Auto343;
	_Context->msg_Auto343[3]=es_Auto343;
	_Context->msg_Auto343[4]=de_Auto343;
	_Context->msg_Auto343[5]=nl_Auto343;
	_Context->msg_Auto343[6]=pt_Auto343;
	_Context->msg_Auto343[7]=xx_Auto343;
	_Context->hint_Auto343[0]=en__Auto343;
	_Context->hint_Auto343[1]=fr__Auto343;
	_Context->hint_Auto343[2]=it__Auto343;
	_Context->hint_Auto343[3]=es__Auto343;
	_Context->hint_Auto343[4]=de__Auto343;
	_Context->hint_Auto343[5]=nl__Auto343;
	_Context->hint_Auto343[6]=pt__Auto343;
	_Context->hint_Auto343[7]=xx__Auto343;
	for (i=0; i < 8; i++)_Context->msg_Auto344[i]=" ";
	_Context->msg_Auto344[0]=en_Auto344;
	_Context->msg_Auto344[1]=fr_Auto344;
	_Context->msg_Auto344[2]=it_Auto344;
	_Context->msg_Auto344[3]=es_Auto344;
	_Context->msg_Auto344[4]=de_Auto344;
	_Context->msg_Auto344[5]=nl_Auto344;
	_Context->msg_Auto344[6]=pt_Auto344;
	_Context->msg_Auto344[7]=xx_Auto344;
	_Context->hint_Auto344[0]=en__Auto344;
	_Context->hint_Auto344[1]=fr__Auto344;
	_Context->hint_Auto344[2]=it__Auto344;
	_Context->hint_Auto344[3]=es__Auto344;
	_Context->hint_Auto344[4]=de__Auto344;
	_Context->hint_Auto344[5]=nl__Auto344;
	_Context->hint_Auto344[6]=pt__Auto344;
	_Context->hint_Auto344[7]=xx__Auto344;
	return(0);
}

public 	int	widget_event_menu_hide(struct widget_event_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto334 != (void *) 0)
	&& (_Context->s_Auto334 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto334,384,32);
		_Context->s_Auto334=0;
		}

	return(result);
}

public	int	widget_event_menu_remove(struct widget_event_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	mouse_move_off();
	if (_Context->p_Auto334 != (void *) 0)
		_Context->p_Auto334 = visual_drop(_Context->p_Auto334);
	_Context=liberate(_Context);

	return(result);
}

public	int	widget_event_menu_show(struct widget_event_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if ((_Context->p_Auto334 != (void *) 0)
	&& (_Context->s_Auto334 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto334,384,32);
		_Context->s_Auto334=1;
		}
	if (((_Context->status = visual_styled_element(384,32,248,224,GetWidgetStyle(1)," ",0)) != 0)
) {
		visual_filzone(384,32,248,224,27,11);
		}
	_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
	if (((_Context->status = visual_styled_element(392,44,232,20,GetWidgetStyle(2),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
	visual_button(392,44,232,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),32);
		}
	_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
	if (((_Context->status = visual_styled_element(392,64,232,20,GetWidgetStyle(2),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
	visual_button(392,64,232,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),32);
		}
	_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
	if (((_Context->status = visual_styled_element(392,84,232,20,GetWidgetStyle(2),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
	visual_button(392,84,232,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),32);
		}
	_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
	if (((_Context->status = visual_styled_element(392,104,232,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(392,104,232,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
		}
	_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
	if (((_Context->status = visual_styled_element(392,124,232,20,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(392,124,232,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
		}
	_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
	if (((_Context->status = visual_styled_element(392,144,232,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(392,144,232,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
		}
	_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
	if (((_Context->status = visual_styled_element(392,164,232,20,GetWidgetStyle(2),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
	visual_button(392,164,232,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),32);
		}
	_Context->trigger_Auto342=visual_trigger_code(_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]));
	if (((_Context->status = visual_styled_element(392,184,232,20,GetWidgetStyle(2),_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]))) != 0)
) {
	visual_button(392,184,232,20,vfh[2],16,0,_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]),32);
		}
	_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
	if (((_Context->status = visual_styled_element(392,204,232,20,GetWidgetStyle(2),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
	visual_button(392,204,232,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),32);
		}
	_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
	if (((_Context->status = visual_styled_element(392,224,232,20,GetWidgetStyle(2),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
	visual_button(392,224,232,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),32);
		}
	visual_thaw(384,32,248,224);

	return(0);
}
private int on_Auto335_event(struct widget_event_menu_context * _Context) {
	return(_CREATE_WITHOUT_SIZE);
	return(-1);
}
private int on_Auto336_event(struct widget_event_menu_context * _Context) {
	return(_CREATE_WITH_SIZE);
	return(-1);
}
private int on_Auto337_event(struct widget_event_menu_context * _Context) {
	return(_SHOW_AUTOMATIC);
	return(-1);
}
private int on_Auto338_event(struct widget_event_menu_context * _Context) {
	return(_SHOW_CONDITIONAL);
	return(-1);
}
private int on_Auto339_event(struct widget_event_menu_context * _Context) {
	return(_FOCUS_WITH_FOCUS);
	return(-1);
}
private int on_Auto340_event(struct widget_event_menu_context * _Context) {
	return(_FOCUS_WITHOUT_FOCUS);
	return(-1);
}
private int on_Auto341_event(struct widget_event_menu_context * _Context) {
	return(_EVENT_WITH_EVENT);
	return(-1);
}
private int on_Auto342_event(struct widget_event_menu_context * _Context) {
	return(_EVENT_WITHOUT_EVENT);
	return(-1);
}
private int on_Auto343_event(struct widget_event_menu_context * _Context) {
	return(_HIDE_NO_POPUP);
	return(-1);
}
private int on_Auto344_event(struct widget_event_menu_context * _Context) {
	return(_HIDE_WITH_POPUP);
	return(-1);
}


public	int	widget_event_menu_event(
struct widget_event_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto335 == mb ) return(1);
		if (_Context->trigger_Auto336 == mb ) return(2);
		if (_Context->trigger_Auto337 == mb ) return(3);
		if (_Context->trigger_Auto338 == mb ) return(4);
		if (_Context->trigger_Auto339 == mb ) return(5);
		if (_Context->trigger_Auto340 == mb ) return(6);
		if (_Context->trigger_Auto341 == mb ) return(7);
		if (_Context->trigger_Auto342 == mb ) return(8);
		if (_Context->trigger_Auto343 == mb ) return(9);
		if (_Context->trigger_Auto344 == mb ) return(10);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 392 ) 
	&&  ( my >= 44 ) 
	&&  ( mx <= 624 ) 
	&&  ( my <= 64 )) {
		return(1); /* Auto335 */
		}
	if (( mx >= 392 ) 
	&&  ( my >= 64 ) 
	&&  ( mx <= 624 ) 
	&&  ( my <= 84 )) {
		return(2); /* Auto336 */
		}
	if (( mx >= 392 ) 
	&&  ( my >= 84 ) 
	&&  ( mx <= 624 ) 
	&&  ( my <= 104 )) {
		return(3); /* Auto337 */
		}
	if (( mx >= 392 ) 
	&&  ( my >= 104 ) 
	&&  ( mx <= 624 ) 
	&&  ( my <= 124 )) {
		return(4); /* Auto338 */
		}
	if (( mx >= 392 ) 
	&&  ( my >= 124 ) 
	&&  ( mx <= 624 ) 
	&&  ( my <= 144 )) {
		return(5); /* Auto339 */
		}
	if (( mx >= 392 ) 
	&&  ( my >= 144 ) 
	&&  ( mx <= 624 ) 
	&&  ( my <= 164 )) {
		return(6); /* Auto340 */
		}
	if (( mx >= 392 ) 
	&&  ( my >= 164 ) 
	&&  ( mx <= 624 ) 
	&&  ( my <= 184 )) {
		return(7); /* Auto341 */
		}
	if (( mx >= 392 ) 
	&&  ( my >= 184 ) 
	&&  ( mx <= 624 ) 
	&&  ( my <= 204 )) {
		return(8); /* Auto342 */
		}
	if (( mx >= 392 ) 
	&&  ( my >= 204 ) 
	&&  ( mx <= 624 ) 
	&&  ( my <= 224 )) {
		return(9); /* Auto343 */
		}
	if (( mx >= 392 ) 
	&&  ( my >= 224 ) 
	&&  ( mx <= 624 ) 
	&&  ( my <= 244 )) {
		return(10); /* Auto344 */
		}

	return(-1);
}


public	int	widget_event_menu_focus(struct widget_event_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto335 */
				_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
				if (((_Context->status = visual_styled_element(392,44,232,20,GetWidgetStyle(3),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
					visual_button(392,44,232,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
				if (((_Context->status = visual_styled_element(392,44,232,20,GetWidgetStyle(2),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
	visual_button(392,44,232,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto336 */
				_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
				if (((_Context->status = visual_styled_element(392,64,232,20,GetWidgetStyle(3),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
					visual_button(392,64,232,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
				if (((_Context->status = visual_styled_element(392,64,232,20,GetWidgetStyle(2),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
	visual_button(392,64,232,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto337 */
				_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
				if (((_Context->status = visual_styled_element(392,84,232,20,GetWidgetStyle(3),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
					visual_button(392,84,232,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
				if (((_Context->status = visual_styled_element(392,84,232,20,GetWidgetStyle(2),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
	visual_button(392,84,232,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto338 */
				_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
				if (((_Context->status = visual_styled_element(392,104,232,20,GetWidgetStyle(3),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
					visual_button(392,104,232,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
				if (((_Context->status = visual_styled_element(392,104,232,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(392,104,232,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto339 */
				_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
				if (((_Context->status = visual_styled_element(392,124,232,20,GetWidgetStyle(3),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
					visual_button(392,124,232,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
				if (((_Context->status = visual_styled_element(392,124,232,20,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(392,124,232,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
				}
				break;
			case	0x6 :
				/* Auto340 */
				_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
				if (((_Context->status = visual_styled_element(392,144,232,20,GetWidgetStyle(3),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
					visual_button(392,144,232,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
				if (((_Context->status = visual_styled_element(392,144,232,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(392,144,232,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
				}
				break;
			case	0x7 :
				/* Auto341 */
				_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
				if (((_Context->status = visual_styled_element(392,164,232,20,GetWidgetStyle(3),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
					visual_button(392,164,232,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
				if (((_Context->status = visual_styled_element(392,164,232,20,GetWidgetStyle(2),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
	visual_button(392,164,232,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),32);
				}
				break;
			case	0x8 :
				/* Auto342 */
				_Context->trigger_Auto342=visual_trigger_code(_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]));
				if (((_Context->status = visual_styled_element(392,184,232,20,GetWidgetStyle(3),_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]))) != 0)
) {
					visual_button(392,184,232,20,vfh[2],16,0,_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto342=visual_trigger_code(_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]));
				if (((_Context->status = visual_styled_element(392,184,232,20,GetWidgetStyle(2),_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]))) != 0)
) {
	visual_button(392,184,232,20,vfh[2],16,0,_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]),32);
				}
				break;
			case	0x9 :
				/* Auto343 */
				_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
				if (((_Context->status = visual_styled_element(392,204,232,20,GetWidgetStyle(3),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
					visual_button(392,204,232,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
				if (((_Context->status = visual_styled_element(392,204,232,20,GetWidgetStyle(2),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
	visual_button(392,204,232,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),32);
				}
				break;
			case	0xa :
				/* Auto344 */
				_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
				if (((_Context->status = visual_styled_element(392,224,232,20,GetWidgetStyle(3),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
					visual_button(392,224,232,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
				if (((_Context->status = visual_styled_element(392,224,232,20,GetWidgetStyle(2),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
	visual_button(392,224,232,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			widget_event_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=10;
			widget_event_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  384 )
				|| ( visual_event(6) <  32 )
				|| ( visual_event(7) >  632 )
				|| ( visual_event(6) >  256 )) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=widget_event_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto335 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
						if (((_Context->status = visual_styled_element(392,44,232,20,GetWidgetStyle(3),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
							visual_button(392,44,232,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
						if (((_Context->status = visual_styled_element(392,44,232,20,GetWidgetStyle(2),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
	visual_button(392,44,232,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto335_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto336 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
						if (((_Context->status = visual_styled_element(392,64,232,20,GetWidgetStyle(3),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
							visual_button(392,64,232,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
						if (((_Context->status = visual_styled_element(392,64,232,20,GetWidgetStyle(2),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
	visual_button(392,64,232,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto336_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto337 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
						if (((_Context->status = visual_styled_element(392,84,232,20,GetWidgetStyle(3),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
							visual_button(392,84,232,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
						if (((_Context->status = visual_styled_element(392,84,232,20,GetWidgetStyle(2),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
	visual_button(392,84,232,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto337_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto338 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
						if (((_Context->status = visual_styled_element(392,104,232,20,GetWidgetStyle(3),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
							visual_button(392,104,232,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
						if (((_Context->status = visual_styled_element(392,104,232,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(392,104,232,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto338_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto339 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
						if (((_Context->status = visual_styled_element(392,124,232,20,GetWidgetStyle(3),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
							visual_button(392,124,232,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
						if (((_Context->status = visual_styled_element(392,124,232,20,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(392,124,232,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto339_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto340 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
						if (((_Context->status = visual_styled_element(392,144,232,20,GetWidgetStyle(3),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
							visual_button(392,144,232,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
						if (((_Context->status = visual_styled_element(392,144,232,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(392,144,232,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto340_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Auto341 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
						if (((_Context->status = visual_styled_element(392,164,232,20,GetWidgetStyle(3),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
							visual_button(392,164,232,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
						if (((_Context->status = visual_styled_element(392,164,232,20,GetWidgetStyle(2),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
	visual_button(392,164,232,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto341_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Auto342 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto342=visual_trigger_code(_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]));
						if (((_Context->status = visual_styled_element(392,184,232,20,GetWidgetStyle(3),_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]))) != 0)
) {
							visual_button(392,184,232,20,vfh[2],16,0,_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto342=visual_trigger_code(_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]));
						if (((_Context->status = visual_styled_element(392,184,232,20,GetWidgetStyle(2),_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]))) != 0)
) {
	visual_button(392,184,232,20,vfh[2],16,0,_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto342_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Auto343 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
						if (((_Context->status = visual_styled_element(392,204,232,20,GetWidgetStyle(3),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
							visual_button(392,204,232,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
						if (((_Context->status = visual_styled_element(392,204,232,20,GetWidgetStyle(2),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
	visual_button(392,204,232,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto343_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Auto344 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
						if (((_Context->status = visual_styled_element(392,224,232,20,GetWidgetStyle(3),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
							visual_button(392,224,232,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
						if (((_Context->status = visual_styled_element(392,224,232,20,GetWidgetStyle(2),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
	visual_button(392,224,232,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto344_event(_Context)) != -1) break;

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

public	int	widget_event_menu()
{
	int	status=0;
	struct widget_event_menu_context * _Context=(struct widget_event_menu_context*) 0;
	status = widget_event_menu_create(&_Context);
	if ( status != 0) return(status);
	status = widget_event_menu_show(_Context);
		enter_modal();
	status = widget_event_menu_focus(_Context);
		leave_modal();
	status = widget_event_menu_hide(_Context);
	status = widget_event_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vmethopt_c */
