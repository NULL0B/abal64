
#ifndef _vdepmodmenu_c
#define _vdepmodmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : depmodmenu.xml                                           */
/* Target         : vdepmodmenu.c                                            */
/* Identification : 0.0-1196446367-5007.5006                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#include "singfmed.h"
#define en_Auto335   "Sing Version 2.1a"
#define fr_Auto335   "Sing Version 2.1a"
#define it_Auto335   "Sing Version 2.1a"
#define es_Auto335   "Sing Version 2.1a"
#define de_Auto335   "Sing Version 2.1a"
#define nl_Auto335   "Sing Version 2.1a"
#define pt_Auto335   "Sing Version 2.1a"
#define xx_Auto335   "Sing Version 2.1a"
#define en__Auto335   ""
#define fr__Auto335   ""
#define it__Auto335   ""
#define es__Auto335   ""
#define de__Auto335   ""
#define nl__Auto335   ""
#define pt__Auto335   ""
#define xx__Auto335   ""
#define en_Auto336   "&Inspect Style Class Instructions"
#define fr_Auto336   "&Inspect Style Class"
#define it_Auto336   "&Inspect Style Class"
#define es_Auto336   "&Inspect Style Class"
#define de_Auto336   "&Inspect Style Class"
#define nl_Auto336   "&Inspect Style Class"
#define pt_Auto336   "&Inspect Style Class"
#define xx_Auto336   "&Inspect Style Class"
#define en__Auto336   ""
#define fr__Auto336   ""
#define it__Auto336   ""
#define es__Auto336   ""
#define de__Auto336   ""
#define nl__Auto336   ""
#define pt__Auto336   ""
#define xx__Auto336   ""
#define en_Auto337   "I&nspect Efective Style Class"
#define fr_Auto337   "I&nspect Style Class"
#define it_Auto337   "I&nspect Style Class"
#define es_Auto337   "I&nspect Style Class"
#define de_Auto337   "I&nspect Style Class"
#define nl_Auto337   "I&nspect Style Class"
#define pt_Auto337   "I&nspect Style Class"
#define xx_Auto337   "I&nspect Style Class"
#define en__Auto337   ""
#define fr__Auto337   ""
#define it__Auto337   ""
#define es__Auto337   ""
#define de__Auto337   ""
#define nl__Auto337   ""
#define pt__Auto337   ""
#define xx__Auto337   ""
#define en_Auto338   "&Export Style Class to File"
#define fr_Auto338   "&Calculate Best Positioning"
#define it_Auto338   "&Calculate Best Positioning"
#define es_Auto338   "&Calculate Best Positioning"
#define de_Auto338   "&Calculate Best Positioning"
#define nl_Auto338   "&Calculate Best Positioning"
#define pt_Auto338   "&Calculate Best Positioning"
#define xx_Auto338   "&Calculate Best Positioning"
#define en__Auto338   ""
#define fr__Auto338   ""
#define it__Auto338   ""
#define es__Auto338   ""
#define de__Auto338   ""
#define nl__Auto338   ""
#define pt__Auto338   ""
#define xx__Auto338   ""
#define en_Auto340   "&Toggle Forms Solo"
#define fr_Auto340   "&Toggle Forms Detail"
#define it_Auto340   "&Toggle Forms Detail"
#define es_Auto340   "&Toggle Forms Detail"
#define de_Auto340   "&Toggle Forms Detail"
#define nl_Auto340   "&Toggle Forms Detail"
#define pt_Auto340   "&Toggle Forms Detail"
#define xx_Auto340   "&Toggle Forms Detail"
#define en__Auto340   ""
#define fr__Auto340   ""
#define it__Auto340   ""
#define es__Auto340   ""
#define de__Auto340   ""
#define nl__Auto340   ""
#define pt__Auto340   ""
#define xx__Auto340   ""
#define en_Auto341   "T&oggle Forms Detail"
#define fr_Auto341   "T&oggle Forms Detail"
#define it_Auto341   "T&oggle Forms Detail"
#define es_Auto341   "T&oggle Forms Detail"
#define de_Auto341   "T&oggle Forms Detail"
#define nl_Auto341   "T&oggle Forms Detail"
#define pt_Auto341   "T&oggle Forms Detail"
#define xx_Auto341   "T&oggle Forms Detail"
#define en__Auto341   ""
#define fr__Auto341   ""
#define it__Auto341   ""
#define es__Auto341   ""
#define de__Auto341   ""
#define nl__Auto341   ""
#define pt__Auto341   ""
#define xx__Auto341   ""
#define en_Auto342   "Add Class Relation"
#define fr_Auto342   "T&oggle Forms Detail"
#define it_Auto342   "T&oggle Forms Detail"
#define es_Auto342   "T&oggle Forms Detail"
#define de_Auto342   "T&oggle Forms Detail"
#define nl_Auto342   "T&oggle Forms Detail"
#define pt_Auto342   "T&oggle Forms Detail"
#define xx_Auto342   "T&oggle Forms Detail"
#define en__Auto342   ""
#define fr__Auto342   ""
#define it__Auto342   ""
#define es__Auto342   ""
#define de__Auto342   ""
#define nl__Auto342   ""
#define pt__Auto342   ""
#define xx__Auto342   ""
#define en_Auto344   "&Delete Style Class from Model"
#define fr_Auto344   "&Delete Style Class from Model"
#define it_Auto344   "&Delete Style Class from Model"
#define es_Auto344   "&Delete Style Class from Model"
#define de_Auto344   "&Delete Style Class from Model"
#define nl_Auto344   "&Delete Style Class from Model"
#define pt_Auto344   "&Delete Style Class from Model"
#define xx_Auto344   "&Delete Style Class from Model"
#define en__Auto344   ""
#define fr__Auto344   ""
#define it__Auto344   ""
#define es__Auto344   ""
#define de__Auto344   ""
#define nl__Auto344   ""
#define pt__Auto344   ""
#define xx__Auto344   ""
#define en_Auto345   "&Calculate Best Positioning"
#define fr_Auto345   "C&alculate Best Positioning"
#define it_Auto345   "C&alculate Best Positioning"
#define es_Auto345   "C&alculate Best Positioning"
#define de_Auto345   "C&alculate Best Positioning"
#define nl_Auto345   "C&alculate Best Positioning"
#define pt_Auto345   "C&alculate Best Positioning"
#define xx_Auto345   "C&alculate Best Positioning"
#define en__Auto345   ""
#define fr__Auto345   ""
#define it__Auto345   ""
#define es__Auto345   ""
#define de__Auto345   ""
#define nl__Auto345   ""
#define pt__Auto345   ""
#define xx__Auto345   ""

private struct dependance_model_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto335[8];
	char * hint_Auto335[8];
	int	s_Auto335;
	void *	p_Auto335;
	int	x_Auto335;
	int	y_Auto335;
	int	w_Auto335;
	int	h_Auto335;
	char * msg_Auto336[8];
	int	trigger_Auto336;
	char * hint_Auto336[8];
	char * msg_Auto337[8];
	int	trigger_Auto337;
	char * hint_Auto337[8];
	char * msg_Auto338[8];
	int	trigger_Auto338;
	char * hint_Auto338[8];
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
	char * hint_Auto343[8];
	char * msg_Auto344[8];
	int	trigger_Auto344;
	char * hint_Auto344[8];
	char * msg_Auto345[8];
	int	trigger_Auto345;
	char * hint_Auto345[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct dependance_model_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = dependance_model_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}

private int on_Auto335_create(struct dependance_model_menu_context * _Context) {
	mouse_move_on();
	if(((_Context->y_Auto335=visual_event(6))+220)>hardrows())
	_Context->y_Auto335=(hardrows()-220);
	if(((_Context->x_Auto335=visual_event(7))+304)>hardcolumns())
	_Context->x_Auto335=(hardcolumns()-304);
	return(-1);
}

public	int	dependance_model_menu_create(struct dependance_model_menu_context **cptr)
{

	int i;
	struct dependance_model_menu_context * _Context=(struct dependance_model_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct dependance_model_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=8;
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
	_Context->s_Auto335=0;
	_Context->p_Auto335=visual_buffer(_Context->x_Auto335,_Context->y_Auto335,304+2,220+2);
	_Context->x_Auto335=40;
	_Context->y_Auto335=44;
	_Context->w_Auto335=304;
	_Context->h_Auto335=220;
	_Context->window_col=40;
	_Context->window_row=44;
	(void) on_Auto335_create(_Context);
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
	for (i=0; i < 8; i++)_Context->msg_Auto345[i]=" ";
	_Context->msg_Auto345[0]=en_Auto345;
	_Context->msg_Auto345[1]=fr_Auto345;
	_Context->msg_Auto345[2]=it_Auto345;
	_Context->msg_Auto345[3]=es_Auto345;
	_Context->msg_Auto345[4]=de_Auto345;
	_Context->msg_Auto345[5]=nl_Auto345;
	_Context->msg_Auto345[6]=pt_Auto345;
	_Context->msg_Auto345[7]=xx_Auto345;
	_Context->hint_Auto345[0]=en__Auto345;
	_Context->hint_Auto345[1]=fr__Auto345;
	_Context->hint_Auto345[2]=it__Auto345;
	_Context->hint_Auto345[3]=es__Auto345;
	_Context->hint_Auto345[4]=de__Auto345;
	_Context->hint_Auto345[5]=nl__Auto345;
	_Context->hint_Auto345[6]=pt__Auto345;
	_Context->hint_Auto345[7]=xx__Auto345;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto335,_Context->y_Auto335,304,220);
	return(0);
}

public 	int	dependance_model_menu_hide(struct dependance_model_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto335 != (void *) 0)
	&& (_Context->s_Auto335 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto335,_Context->x_Auto335,_Context->y_Auto335);
		_Context->s_Auto335=0;
		}
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto335,_Context->y_Auto335);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	dependance_model_menu_remove(struct dependance_model_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	mouse_move_off();
	if (_Context->p_Auto335 != (void *) 0)
		_Context->p_Auto335 = visual_drop(_Context->p_Auto335);
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	dependance_model_menu_show(struct dependance_model_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto335,_Context->y_Auto335);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if ((_Context->p_Auto335 != (void *) 0)
	&& (_Context->s_Auto335 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto335,_Context->x_Auto335,_Context->y_Auto335);
		_Context->s_Auto335=1;
		}
	if (((_Context->status = visual_styled_element(_Context->x_Auto335,_Context->y_Auto335,304,220,GetWidgetStyle(1),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
		visual_window(_Context->x_Auto335,_Context->y_Auto335,304,220,vfh[1],_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),0x4);
		}
	_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+12,272,20,GetWidgetStyle(2),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+12,272,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),32);
		}
	_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+32,272,20,GetWidgetStyle(2),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+32,272,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),32);
		}
	_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+52,280,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+52,280,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
		}
	visual_filzone(_Context->x_Auto335+8,_Context->y_Auto335+80,288,4,26,18);
	_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+92,280,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+92,280,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
		}
	_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+112,280,20,GetWidgetStyle(2),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+112,280,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),32);
		}
	_Context->trigger_Auto342=visual_trigger_code(_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+148,280,20,GetWidgetStyle(2),_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+148,280,20,vfh[2],16,0,_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]),32);
		}
	visual_filzone(_Context->x_Auto335+8,_Context->y_Auto335+136,288,4,26,18);
	_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+168,280,20,GetWidgetStyle(2),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+168,280,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),32);
		}
	_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+188,280,20,GetWidgetStyle(2),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+188,280,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),32);
		}
	visual_thaw(_Context->x_Auto335,_Context->y_Auto335,304,220);

	return(0);
}
private int on_Auto336_event(struct dependance_model_menu_context * _Context) {
	return(_FLOW_INFO);
	return(-1);
}
private int on_Auto337_event(struct dependance_model_menu_context * _Context) {
	return(_FLOW_WORK);
	return(-1);
}
private int on_Auto338_event(struct dependance_model_menu_context * _Context) {
	return(_FLOW_EXPORT);
	return(-1);
}
private int on_Auto340_event(struct dependance_model_menu_context * _Context) {
	return(_FLOW_SOLO);
	return(-1);
}
private int on_Auto341_event(struct dependance_model_menu_context * _Context) {
	return(_FLOW_DETAIL);
	return(-1);
}
private int on_Auto342_event(struct dependance_model_menu_context * _Context) {
	return(_FLOW_ADD);
	return(-1);
}
private int on_Auto344_event(struct dependance_model_menu_context * _Context) {
	return(_FLOW_DELETE);
	return(-1);
}
private int on_Auto345_event(struct dependance_model_menu_context * _Context) {
	return(_FLOW_BEST);
	return(-1);
}


public	int	dependance_model_menu_event(
struct dependance_model_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto336 == mb ) return(1);
		if (_Context->trigger_Auto337 == mb ) return(2);
		if (_Context->trigger_Auto338 == mb ) return(3);
		if (_Context->trigger_Auto340 == mb ) return(4);
		if (_Context->trigger_Auto341 == mb ) return(5);
		if (_Context->trigger_Auto342 == mb ) return(6);
		if (_Context->trigger_Auto344 == mb ) return(7);
		if (_Context->trigger_Auto345 == mb ) return(8);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_Auto335+8) ) 
	&&  ( my >= (_Context->y_Auto335+12) ) 
	&&  ( mx <= (_Context->x_Auto335+8+272) ) 
	&&  ( my <= (_Context->y_Auto335+12+20))) {
		return(1); /* Auto336 */
		}
	if (( mx >= (_Context->x_Auto335+8) ) 
	&&  ( my >= (_Context->y_Auto335+32) ) 
	&&  ( mx <= (_Context->x_Auto335+8+272) ) 
	&&  ( my <= (_Context->y_Auto335+32+20))) {
		return(2); /* Auto337 */
		}
	if (( mx >= (_Context->x_Auto335+8) ) 
	&&  ( my >= (_Context->y_Auto335+52) ) 
	&&  ( mx <= (_Context->x_Auto335+8+280) ) 
	&&  ( my <= (_Context->y_Auto335+52+20))) {
		return(3); /* Auto338 */
		}
	if (( mx >= (_Context->x_Auto335+8) ) 
	&&  ( my >= (_Context->y_Auto335+92) ) 
	&&  ( mx <= (_Context->x_Auto335+8+280) ) 
	&&  ( my <= (_Context->y_Auto335+92+20))) {
		return(4); /* Auto340 */
		}
	if (( mx >= (_Context->x_Auto335+8) ) 
	&&  ( my >= (_Context->y_Auto335+112) ) 
	&&  ( mx <= (_Context->x_Auto335+8+280) ) 
	&&  ( my <= (_Context->y_Auto335+112+20))) {
		return(5); /* Auto341 */
		}
	if (( mx >= (_Context->x_Auto335+8) ) 
	&&  ( my >= (_Context->y_Auto335+148) ) 
	&&  ( mx <= (_Context->x_Auto335+8+280) ) 
	&&  ( my <= (_Context->y_Auto335+148+20))) {
		return(6); /* Auto342 */
		}
	if (( mx >= (_Context->x_Auto335+8) ) 
	&&  ( my >= (_Context->y_Auto335+168) ) 
	&&  ( mx <= (_Context->x_Auto335+8+280) ) 
	&&  ( my <= (_Context->y_Auto335+168+20))) {
		return(7); /* Auto344 */
		}
	if (( mx >= (_Context->x_Auto335+8) ) 
	&&  ( my >= (_Context->y_Auto335+188) ) 
	&&  ( mx <= (_Context->x_Auto335+8+280) ) 
	&&  ( my <= (_Context->y_Auto335+188+20))) {
		return(8); /* Auto345 */
		}

	return(-1);
}


public	int	dependance_model_menu_focus(struct dependance_model_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto336 */
				_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+12,272,20,GetWidgetStyle(3),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto335+8,_Context->y_Auto335+12,272,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+12,272,20,GetWidgetStyle(2),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+12,272,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto337 */
				_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+32,272,20,GetWidgetStyle(3),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto335+8,_Context->y_Auto335+32,272,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+32,272,20,GetWidgetStyle(2),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+32,272,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto338 */
				_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+52,280,20,GetWidgetStyle(3),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto335+8,_Context->y_Auto335+52,280,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+52,280,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+52,280,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto340 */
				_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+92,280,20,GetWidgetStyle(3),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto335+8,_Context->y_Auto335+92,280,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+92,280,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+92,280,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto341 */
				_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+112,280,20,GetWidgetStyle(3),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto335+8,_Context->y_Auto335+112,280,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+112,280,20,GetWidgetStyle(2),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+112,280,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),32);
				}
				break;
			case	0x6 :
				/* Auto342 */
				_Context->trigger_Auto342=visual_trigger_code(_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+148,280,20,GetWidgetStyle(3),_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto335+8,_Context->y_Auto335+148,280,20,vfh[2],16,0,_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto342=visual_trigger_code(_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+148,280,20,GetWidgetStyle(2),_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+148,280,20,vfh[2],16,0,_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]),32);
				}
				break;
			case	0x7 :
				/* Auto344 */
				_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+168,280,20,GetWidgetStyle(3),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto335+8,_Context->y_Auto335+168,280,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+168,280,20,GetWidgetStyle(2),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+168,280,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),32);
				}
				break;
			case	0x8 :
				/* Auto345 */
				_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+188,280,20,GetWidgetStyle(3),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto335+8,_Context->y_Auto335+188,280,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+188,280,20,GetWidgetStyle(2),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+188,280,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			dependance_model_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=8;
			dependance_model_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  _Context->x_Auto335 )
				|| ( visual_event(6) < _Context->y_Auto335  )
				|| ( visual_event(7) > (_Context->x_Auto335+_Context->w_Auto335))
				|| ( visual_event(6) >  (_Context->y_Auto335+_Context->h_Auto335))) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=dependance_model_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto336 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+12,272,20,GetWidgetStyle(3),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto335+8,_Context->y_Auto335+12,272,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+12,272,20,GetWidgetStyle(2),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+12,272,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto336_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto337 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+32,272,20,GetWidgetStyle(3),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto335+8,_Context->y_Auto335+32,272,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+32,272,20,GetWidgetStyle(2),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+32,272,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto337_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto338 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+52,280,20,GetWidgetStyle(3),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto335+8,_Context->y_Auto335+52,280,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+52,280,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+52,280,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto338_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto340 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+92,280,20,GetWidgetStyle(3),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto335+8,_Context->y_Auto335+92,280,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+92,280,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+92,280,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto340_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto341 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+112,280,20,GetWidgetStyle(3),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto335+8,_Context->y_Auto335+112,280,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+112,280,20,GetWidgetStyle(2),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+112,280,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto341_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto342 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto342=visual_trigger_code(_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+148,280,20,GetWidgetStyle(3),_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto335+8,_Context->y_Auto335+148,280,20,vfh[2],16,0,_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto342=visual_trigger_code(_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+148,280,20,GetWidgetStyle(2),_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+148,280,20,vfh[2],16,0,_Context->msg_Auto342[_Context->language],strlen(_Context->msg_Auto342[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto342_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Auto344 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+168,280,20,GetWidgetStyle(3),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto335+8,_Context->y_Auto335+168,280,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+168,280,20,GetWidgetStyle(2),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+168,280,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto344_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Auto345 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+188,280,20,GetWidgetStyle(3),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto335+8,_Context->y_Auto335+188,280,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto335+8,_Context->y_Auto335+188,280,20,GetWidgetStyle(2),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto335+8,_Context->y_Auto335+188,280,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto345_event(_Context)) != -1) break;

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

	return( _Context->keycode );
}

public	int	dependance_model_menu()
{
	int	status=0;
	struct dependance_model_menu_context * _Context=(struct dependance_model_menu_context*) 0;
	status = dependance_model_menu_create(&_Context);
	if ( status != 0) return(status);
	status = dependance_model_menu_show(_Context);
		enter_modal();
	status = dependance_model_menu_focus(_Context);
		leave_modal();
	status = dependance_model_menu_hide(_Context);
	status = dependance_model_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vdepmodmenu_c */
