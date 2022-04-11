
#ifndef _depmenu_c
#define _depmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : depmenu.xml                                              */
/* Target         : depmenu.c                                                */
/* Identification : 0.0-1195988747-16216.16215                               */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#include "singfmed.h"
#define en_Auto306   "Sing Version 2.1a"
#define fr_Auto306   "Sing Version 2.1a"
#define it_Auto306   "Sing Version 2.1a"
#define es_Auto306   "Sing Version 2.1a"
#define de_Auto306   "Sing Version 2.1a"
#define nl_Auto306   "Sing Version 2.1a"
#define pt_Auto306   "Sing Version 2.1a"
#define xx_Auto306   "Sing Version 2.1a"
#define en__Auto306   ""
#define fr__Auto306   ""
#define it__Auto306   ""
#define es__Auto306   ""
#define de__Auto306   ""
#define nl__Auto306   ""
#define pt__Auto306   ""
#define xx__Auto306   ""
#define en_Auto307   "&Model Editor Properties and Options"
#define fr_Auto307   "&Model Editor Properties and Options"
#define it_Auto307   "&Model Editor Properties and Options"
#define es_Auto307   "&Model Editor Properties and Options"
#define de_Auto307   "&Model Editor Properties and Options"
#define nl_Auto307   "&Model Editor Properties and Options"
#define pt_Auto307   "&Model Editor Properties and Options"
#define xx_Auto307   "&Model Editor Properties and Options"
#define en__Auto307   ""
#define fr__Auto307   ""
#define it__Auto307   ""
#define es__Auto307   ""
#define de__Auto307   ""
#define nl__Auto307   ""
#define pt__Auto307   ""
#define xx__Auto307   ""
#define en_Auto308   "&Reset and Recalculate Flowchart Display"
#define fr_Auto308   "&Recalculation de l'affichage de la base de donn‚es"
#define it_Auto308   "&Reset and Recalculate Database Display"
#define es_Auto308   "&Reset and Recalculate Database Display"
#define de_Auto308   "&Reset and Recalculate Database Display"
#define nl_Auto308   "&Reset and Recalculate Database Display"
#define pt_Auto308   "&Reset and Recalculate Database Display"
#define xx_Auto308   "&Reset and Recalculate Database Display"
#define en__Auto308   ""
#define fr__Auto308   ""
#define it__Auto308   ""
#define es__Auto308   ""
#define de__Auto308   ""
#define nl__Auto308   ""
#define pt__Auto308   ""
#define xx__Auto308   ""
#define en_Auto309   "&Calculate Best Positioning"
#define fr_Auto309   "&Calculate Best Positioning"
#define it_Auto309   "&Calculate Best Positioning"
#define es_Auto309   "&Calculate Best Positioning"
#define de_Auto309   "&Calculate Best Positioning"
#define nl_Auto309   "&Calculate Best Positioning"
#define pt_Auto309   "&Calculate Best Positioning"
#define xx_Auto309   "&Calculate Best Positioning"
#define en__Auto309   ""
#define fr__Auto309   ""
#define it__Auto309   ""
#define es__Auto309   ""
#define de__Auto309   ""
#define nl__Auto309   ""
#define pt__Auto309   ""
#define xx__Auto309   ""
#define en_Auto310   "R&efresh Screen Display"
#define fr_Auto310   "R&efresh Screen Display"
#define it_Auto310   "R&efresh Screen Display"
#define es_Auto310   "R&efresh Screen Display"
#define de_Auto310   "R&efresh Screen Display"
#define nl_Auto310   "R&efresh Screen Display"
#define pt_Auto310   "R&efresh Screen Display"
#define xx_Auto310   "R&efresh Screen Display"
#define en__Auto310   ""
#define fr__Auto310   ""
#define it__Auto310   ""
#define es__Auto310   ""
#define de__Auto310   ""
#define nl__Auto310   ""
#define pt__Auto310   ""
#define xx__Auto310   ""
#define en_Auto312   "&Toggle Relation Tracing : Direct/Routed"
#define fr_Auto312   "&Toggle Relation Tracing : Direct/Routed"
#define it_Auto312   "&Toggle Relation Tracing : Direct/Routed"
#define es_Auto312   "&Toggle Relation Tracing : Direct/Routed"
#define de_Auto312   "&Toggle Relation Tracing : Direct/Routed"
#define nl_Auto312   "&Toggle Relation Tracing : Direct/Routed"
#define pt_Auto312   "&Toggle Relation Tracing : Direct/Routed"
#define xx_Auto312   "&Toggle Relation Tracing : Direct/Routed"
#define en__Auto312   ""
#define fr__Auto312   ""
#define it__Auto312   ""
#define es__Auto312   ""
#define de__Auto312   ""
#define nl__Auto312   ""
#define pt__Auto312   ""
#define xx__Auto312   ""
#define en_Auto313   "T&oggle display of Help Bubble messages"
#define fr_Auto313   "T&oggle display of Help Bubble messages"
#define it_Auto313   "T&oggle display of Help Bubble messages"
#define es_Auto313   "T&oggle display of Help Bubble messages"
#define de_Auto313   "T&oggle display of Help Bubble messages"
#define nl_Auto313   "T&oggle display of Help Bubble messages"
#define pt_Auto313   "T&oggle display of Help Bubble messages"
#define xx_Auto313   "T&oggle display of Help Bubble messages"
#define en__Auto313   ""
#define fr__Auto313   ""
#define it__Auto313   ""
#define es__Auto313   ""
#define de__Auto313   ""
#define nl__Auto313   ""
#define pt__Auto313   ""
#define xx__Auto313   ""
#define en_previous   "To&ggle Hyperspace Navigator"
#define fr_previous   "To&ggle Hyperspace Navigator"
#define it_previous   "To&ggle Hyperspace Navigator"
#define es_previous   "To&ggle Hyperspace Navigator"
#define de_previous   "To&ggle Hyperspace Navigator"
#define nl_previous   "To&ggle Hyperspace Navigator"
#define pt_previous   "To&ggle Hyperspace Navigator"
#define xx_previous   "To&ggle Hyperspace Navigator"
#define en__previous   ""
#define fr__previous   ""
#define it__previous   ""
#define es__previous   ""
#define de__previous   ""
#define nl__previous   ""
#define pt__previous   ""
#define xx__previous   ""
#define en_Auto314   "Togg&le Flowchart Display : Selection / All"
#define fr_Auto314   "Togg&le Database display : Project/Forms"
#define it_Auto314   "Togg&le Database display : Project/Forms"
#define es_Auto314   "Togg&le Database display : Project/Forms"
#define de_Auto314   "Togg&le Database display : Project/Forms"
#define nl_Auto314   "Togg&le Database display : Project/Forms"
#define pt_Auto314   "Togg&le Database display : Project/Forms"
#define xx_Auto314   "Togg&le Database display : Project/Forms"
#define en__Auto314   ""
#define fr__Auto314   ""
#define it__Auto314   ""
#define es__Auto314   ""
#define de__Auto314   ""
#define nl__Auto314   ""
#define pt__Auto314   ""
#define xx__Auto314   ""
#define en_Auto315   "Toggle &Flowchart Detail"
#define fr_Auto315   "Toggle &Flowchart Detail"
#define it_Auto315   "Toggle &Flowchart Detail"
#define es_Auto315   "Toggle &Flowchart Detail"
#define de_Auto315   "Toggle &Flowchart Detail"
#define nl_Auto315   "Toggle &Flowchart Detail"
#define pt_Auto315   "Toggle &Flowchart Detail"
#define xx_Auto315   "Toggle &Flowchart Detail"
#define en__Auto315   ""
#define fr__Auto315   ""
#define it__Auto315   ""
#define es__Auto315   ""
#define de__Auto315   ""
#define nl__Auto315   ""
#define pt__Auto315   ""
#define xx__Auto315   ""
#define en_Auto317   "&Define Class Domain / Selection"
#define fr_Auto317   "&Define Class Domain / Selection"
#define it_Auto317   "&Define Class Domain / Selection"
#define es_Auto317   "&Define Class Domain / Selection"
#define de_Auto317   "&Define Class Domain / Selection"
#define nl_Auto317   "&Define Class Domain / Selection"
#define pt_Auto317   "&Define Class Domain / Selection"
#define xx_Auto317   "&Define Class Domain / Selection"
#define en__Auto317   ""
#define fr__Auto317   ""
#define it__Auto317   ""
#define es__Auto317   ""
#define de__Auto317   ""
#define nl__Auto317   ""
#define pt__Auto317   ""
#define xx__Auto317   ""
#define en_Auto318   "&Save to Image File"
#define fr_Auto318   "S&ave to Image File"
#define it_Auto318   "S&ave to Image File"
#define es_Auto318   "S&ave to Image File"
#define de_Auto318   "S&ave to Image File"
#define nl_Auto318   "S&ave to Image File"
#define pt_Auto318   "S&ave to Image File"
#define xx_Auto318   "S&ave to Image File"
#define en__Auto318   ""
#define fr__Auto318   ""
#define it__Auto318   ""
#define es__Auto318   ""
#define de__Auto318   ""
#define nl__Auto318   ""
#define pt__Auto318   ""
#define xx__Auto318   ""

private struct dependance_main_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto306[8];
	char * hint_Auto306[8];
	int	s_Auto306;
	void *	p_Auto306;
	int	x_Auto306;
	int	y_Auto306;
	int	w_Auto306;
	int	h_Auto306;
	char * msg_Auto307[8];
	int	trigger_Auto307;
	char * hint_Auto307[8];
	char * msg_Auto308[8];
	int	trigger_Auto308;
	char * hint_Auto308[8];
	char * msg_Auto309[8];
	int	trigger_Auto309;
	char * hint_Auto309[8];
	char * msg_Auto310[8];
	int	trigger_Auto310;
	char * hint_Auto310[8];
	char * hint_Auto311[8];
	char * msg_Auto312[8];
	int	trigger_Auto312;
	char * hint_Auto312[8];
	char * msg_Auto313[8];
	int	trigger_Auto313;
	char * hint_Auto313[8];
	char * msg_previous[8];
	int	trigger_previous;
	char * hint_previous[8];
	char * msg_Auto314[8];
	int	trigger_Auto314;
	char * hint_Auto314[8];
	char * msg_Auto315[8];
	int	trigger_Auto315;
	char * hint_Auto315[8];
	char * hint_Auto316[8];
	char * msg_Auto317[8];
	int	trigger_Auto317;
	char * hint_Auto317[8];
	char * msg_Auto318[8];
	int	trigger_Auto318;
	char * hint_Auto318[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct dependance_main_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = dependance_main_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}

private int on_Auto306_create(struct dependance_main_menu_context * _Context) {
	mouse_move_on();
	_Context->y_Auto306=visual_event(6);
	_Context->x_Auto306=visual_event(7);
	return(-1);
}

public	int	dependance_main_menu_create(struct dependance_main_menu_context **cptr)
{

	int i;
	struct dependance_main_menu_context * _Context=(struct dependance_main_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct dependance_main_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=11;
	for (i=0; i < 8; i++)_Context->msg_Auto306[i]=" ";
	_Context->msg_Auto306[0]=en_Auto306;
	_Context->msg_Auto306[1]=fr_Auto306;
	_Context->msg_Auto306[2]=it_Auto306;
	_Context->msg_Auto306[3]=es_Auto306;
	_Context->msg_Auto306[4]=de_Auto306;
	_Context->msg_Auto306[5]=nl_Auto306;
	_Context->msg_Auto306[6]=pt_Auto306;
	_Context->msg_Auto306[7]=xx_Auto306;
	_Context->hint_Auto306[0]=en__Auto306;
	_Context->hint_Auto306[1]=fr__Auto306;
	_Context->hint_Auto306[2]=it__Auto306;
	_Context->hint_Auto306[3]=es__Auto306;
	_Context->hint_Auto306[4]=de__Auto306;
	_Context->hint_Auto306[5]=nl__Auto306;
	_Context->hint_Auto306[6]=pt__Auto306;
	_Context->hint_Auto306[7]=xx__Auto306;
	_Context->s_Auto306=0;
	_Context->p_Auto306=visual_buffer(_Context->x_Auto306,_Context->y_Auto306,328+2,284+2);
	_Context->x_Auto306=32;
	_Context->y_Auto306=52;
	_Context->w_Auto306=328;
	_Context->h_Auto306=284;
	_Context->window_col=32;
	_Context->window_row=52;
	(void) on_Auto306_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Auto307[i]=" ";
	_Context->msg_Auto307[0]=en_Auto307;
	_Context->msg_Auto307[1]=fr_Auto307;
	_Context->msg_Auto307[2]=it_Auto307;
	_Context->msg_Auto307[3]=es_Auto307;
	_Context->msg_Auto307[4]=de_Auto307;
	_Context->msg_Auto307[5]=nl_Auto307;
	_Context->msg_Auto307[6]=pt_Auto307;
	_Context->msg_Auto307[7]=xx_Auto307;
	_Context->hint_Auto307[0]=en__Auto307;
	_Context->hint_Auto307[1]=fr__Auto307;
	_Context->hint_Auto307[2]=it__Auto307;
	_Context->hint_Auto307[3]=es__Auto307;
	_Context->hint_Auto307[4]=de__Auto307;
	_Context->hint_Auto307[5]=nl__Auto307;
	_Context->hint_Auto307[6]=pt__Auto307;
	_Context->hint_Auto307[7]=xx__Auto307;
	for (i=0; i < 8; i++)_Context->msg_Auto308[i]=" ";
	_Context->msg_Auto308[0]=en_Auto308;
	_Context->msg_Auto308[1]=fr_Auto308;
	_Context->msg_Auto308[2]=it_Auto308;
	_Context->msg_Auto308[3]=es_Auto308;
	_Context->msg_Auto308[4]=de_Auto308;
	_Context->msg_Auto308[5]=nl_Auto308;
	_Context->msg_Auto308[6]=pt_Auto308;
	_Context->msg_Auto308[7]=xx_Auto308;
	_Context->hint_Auto308[0]=en__Auto308;
	_Context->hint_Auto308[1]=fr__Auto308;
	_Context->hint_Auto308[2]=it__Auto308;
	_Context->hint_Auto308[3]=es__Auto308;
	_Context->hint_Auto308[4]=de__Auto308;
	_Context->hint_Auto308[5]=nl__Auto308;
	_Context->hint_Auto308[6]=pt__Auto308;
	_Context->hint_Auto308[7]=xx__Auto308;
	for (i=0; i < 8; i++)_Context->msg_Auto309[i]=" ";
	_Context->msg_Auto309[0]=en_Auto309;
	_Context->msg_Auto309[1]=fr_Auto309;
	_Context->msg_Auto309[2]=it_Auto309;
	_Context->msg_Auto309[3]=es_Auto309;
	_Context->msg_Auto309[4]=de_Auto309;
	_Context->msg_Auto309[5]=nl_Auto309;
	_Context->msg_Auto309[6]=pt_Auto309;
	_Context->msg_Auto309[7]=xx_Auto309;
	_Context->hint_Auto309[0]=en__Auto309;
	_Context->hint_Auto309[1]=fr__Auto309;
	_Context->hint_Auto309[2]=it__Auto309;
	_Context->hint_Auto309[3]=es__Auto309;
	_Context->hint_Auto309[4]=de__Auto309;
	_Context->hint_Auto309[5]=nl__Auto309;
	_Context->hint_Auto309[6]=pt__Auto309;
	_Context->hint_Auto309[7]=xx__Auto309;
	for (i=0; i < 8; i++)_Context->msg_Auto310[i]=" ";
	_Context->msg_Auto310[0]=en_Auto310;
	_Context->msg_Auto310[1]=fr_Auto310;
	_Context->msg_Auto310[2]=it_Auto310;
	_Context->msg_Auto310[3]=es_Auto310;
	_Context->msg_Auto310[4]=de_Auto310;
	_Context->msg_Auto310[5]=nl_Auto310;
	_Context->msg_Auto310[6]=pt_Auto310;
	_Context->msg_Auto310[7]=xx_Auto310;
	_Context->hint_Auto310[0]=en__Auto310;
	_Context->hint_Auto310[1]=fr__Auto310;
	_Context->hint_Auto310[2]=it__Auto310;
	_Context->hint_Auto310[3]=es__Auto310;
	_Context->hint_Auto310[4]=de__Auto310;
	_Context->hint_Auto310[5]=nl__Auto310;
	_Context->hint_Auto310[6]=pt__Auto310;
	_Context->hint_Auto310[7]=xx__Auto310;
	for (i=0; i < 8; i++)_Context->msg_Auto312[i]=" ";
	_Context->msg_Auto312[0]=en_Auto312;
	_Context->msg_Auto312[1]=fr_Auto312;
	_Context->msg_Auto312[2]=it_Auto312;
	_Context->msg_Auto312[3]=es_Auto312;
	_Context->msg_Auto312[4]=de_Auto312;
	_Context->msg_Auto312[5]=nl_Auto312;
	_Context->msg_Auto312[6]=pt_Auto312;
	_Context->msg_Auto312[7]=xx_Auto312;
	_Context->hint_Auto312[0]=en__Auto312;
	_Context->hint_Auto312[1]=fr__Auto312;
	_Context->hint_Auto312[2]=it__Auto312;
	_Context->hint_Auto312[3]=es__Auto312;
	_Context->hint_Auto312[4]=de__Auto312;
	_Context->hint_Auto312[5]=nl__Auto312;
	_Context->hint_Auto312[6]=pt__Auto312;
	_Context->hint_Auto312[7]=xx__Auto312;
	for (i=0; i < 8; i++)_Context->msg_Auto313[i]=" ";
	_Context->msg_Auto313[0]=en_Auto313;
	_Context->msg_Auto313[1]=fr_Auto313;
	_Context->msg_Auto313[2]=it_Auto313;
	_Context->msg_Auto313[3]=es_Auto313;
	_Context->msg_Auto313[4]=de_Auto313;
	_Context->msg_Auto313[5]=nl_Auto313;
	_Context->msg_Auto313[6]=pt_Auto313;
	_Context->msg_Auto313[7]=xx_Auto313;
	_Context->hint_Auto313[0]=en__Auto313;
	_Context->hint_Auto313[1]=fr__Auto313;
	_Context->hint_Auto313[2]=it__Auto313;
	_Context->hint_Auto313[3]=es__Auto313;
	_Context->hint_Auto313[4]=de__Auto313;
	_Context->hint_Auto313[5]=nl__Auto313;
	_Context->hint_Auto313[6]=pt__Auto313;
	_Context->hint_Auto313[7]=xx__Auto313;
	for (i=0; i < 8; i++)_Context->msg_previous[i]=" ";
	_Context->msg_previous[0]=en_previous;
	_Context->msg_previous[1]=fr_previous;
	_Context->msg_previous[2]=it_previous;
	_Context->msg_previous[3]=es_previous;
	_Context->msg_previous[4]=de_previous;
	_Context->msg_previous[5]=nl_previous;
	_Context->msg_previous[6]=pt_previous;
	_Context->msg_previous[7]=xx_previous;
	_Context->hint_previous[0]=en__previous;
	_Context->hint_previous[1]=fr__previous;
	_Context->hint_previous[2]=it__previous;
	_Context->hint_previous[3]=es__previous;
	_Context->hint_previous[4]=de__previous;
	_Context->hint_previous[5]=nl__previous;
	_Context->hint_previous[6]=pt__previous;
	_Context->hint_previous[7]=xx__previous;
	for (i=0; i < 8; i++)_Context->msg_Auto314[i]=" ";
	_Context->msg_Auto314[0]=en_Auto314;
	_Context->msg_Auto314[1]=fr_Auto314;
	_Context->msg_Auto314[2]=it_Auto314;
	_Context->msg_Auto314[3]=es_Auto314;
	_Context->msg_Auto314[4]=de_Auto314;
	_Context->msg_Auto314[5]=nl_Auto314;
	_Context->msg_Auto314[6]=pt_Auto314;
	_Context->msg_Auto314[7]=xx_Auto314;
	_Context->hint_Auto314[0]=en__Auto314;
	_Context->hint_Auto314[1]=fr__Auto314;
	_Context->hint_Auto314[2]=it__Auto314;
	_Context->hint_Auto314[3]=es__Auto314;
	_Context->hint_Auto314[4]=de__Auto314;
	_Context->hint_Auto314[5]=nl__Auto314;
	_Context->hint_Auto314[6]=pt__Auto314;
	_Context->hint_Auto314[7]=xx__Auto314;
	for (i=0; i < 8; i++)_Context->msg_Auto315[i]=" ";
	_Context->msg_Auto315[0]=en_Auto315;
	_Context->msg_Auto315[1]=fr_Auto315;
	_Context->msg_Auto315[2]=it_Auto315;
	_Context->msg_Auto315[3]=es_Auto315;
	_Context->msg_Auto315[4]=de_Auto315;
	_Context->msg_Auto315[5]=nl_Auto315;
	_Context->msg_Auto315[6]=pt_Auto315;
	_Context->msg_Auto315[7]=xx_Auto315;
	_Context->hint_Auto315[0]=en__Auto315;
	_Context->hint_Auto315[1]=fr__Auto315;
	_Context->hint_Auto315[2]=it__Auto315;
	_Context->hint_Auto315[3]=es__Auto315;
	_Context->hint_Auto315[4]=de__Auto315;
	_Context->hint_Auto315[5]=nl__Auto315;
	_Context->hint_Auto315[6]=pt__Auto315;
	_Context->hint_Auto315[7]=xx__Auto315;
	for (i=0; i < 8; i++)_Context->msg_Auto317[i]=" ";
	_Context->msg_Auto317[0]=en_Auto317;
	_Context->msg_Auto317[1]=fr_Auto317;
	_Context->msg_Auto317[2]=it_Auto317;
	_Context->msg_Auto317[3]=es_Auto317;
	_Context->msg_Auto317[4]=de_Auto317;
	_Context->msg_Auto317[5]=nl_Auto317;
	_Context->msg_Auto317[6]=pt_Auto317;
	_Context->msg_Auto317[7]=xx_Auto317;
	_Context->hint_Auto317[0]=en__Auto317;
	_Context->hint_Auto317[1]=fr__Auto317;
	_Context->hint_Auto317[2]=it__Auto317;
	_Context->hint_Auto317[3]=es__Auto317;
	_Context->hint_Auto317[4]=de__Auto317;
	_Context->hint_Auto317[5]=nl__Auto317;
	_Context->hint_Auto317[6]=pt__Auto317;
	_Context->hint_Auto317[7]=xx__Auto317;
	for (i=0; i < 8; i++)_Context->msg_Auto318[i]=" ";
	_Context->msg_Auto318[0]=en_Auto318;
	_Context->msg_Auto318[1]=fr_Auto318;
	_Context->msg_Auto318[2]=it_Auto318;
	_Context->msg_Auto318[3]=es_Auto318;
	_Context->msg_Auto318[4]=de_Auto318;
	_Context->msg_Auto318[5]=nl_Auto318;
	_Context->msg_Auto318[6]=pt_Auto318;
	_Context->msg_Auto318[7]=xx_Auto318;
	_Context->hint_Auto318[0]=en__Auto318;
	_Context->hint_Auto318[1]=fr__Auto318;
	_Context->hint_Auto318[2]=it__Auto318;
	_Context->hint_Auto318[3]=es__Auto318;
	_Context->hint_Auto318[4]=de__Auto318;
	_Context->hint_Auto318[5]=nl__Auto318;
	_Context->hint_Auto318[6]=pt__Auto318;
	_Context->hint_Auto318[7]=xx__Auto318;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto306,_Context->y_Auto306,328,284);
	return(0);
}

public 	int	dependance_main_menu_hide(struct dependance_main_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto306 != (void *) 0)
	&& (_Context->s_Auto306 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto306,_Context->x_Auto306,_Context->y_Auto306);
		_Context->s_Auto306=0;
		}
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto306,_Context->y_Auto306);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	dependance_main_menu_remove(struct dependance_main_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	mouse_move_off();
	if (_Context->p_Auto306 != (void *) 0)
		_Context->p_Auto306 = visual_drop(_Context->p_Auto306);
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	dependance_main_menu_show(struct dependance_main_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto306,_Context->y_Auto306);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if ((_Context->p_Auto306 != (void *) 0)
	&& (_Context->s_Auto306 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto306,_Context->x_Auto306,_Context->y_Auto306);
		_Context->s_Auto306=1;
		}
	if (((_Context->status = visual_styled_element(_Context->x_Auto306,_Context->y_Auto306,328,284,GetWidgetStyle(1),_Context->msg_Auto306[_Context->language],strlen(_Context->msg_Auto306[_Context->language]))) != 0)
) {
		visual_window(_Context->x_Auto306,_Context->y_Auto306,328,284,vfh[1],_Context->msg_Auto306[_Context->language],strlen(_Context->msg_Auto306[_Context->language]),0x4);
		}
	_Context->trigger_Auto307=visual_trigger_code(_Context->msg_Auto307[_Context->language],strlen(_Context->msg_Auto307[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+12,296,20,GetWidgetStyle(2),_Context->msg_Auto307[_Context->language],strlen(_Context->msg_Auto307[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+12,296,20,vfh[2],16,0,_Context->msg_Auto307[_Context->language],strlen(_Context->msg_Auto307[_Context->language]),32);
		}
	_Context->trigger_Auto308=visual_trigger_code(_Context->msg_Auto308[_Context->language],strlen(_Context->msg_Auto308[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+32,296,20,GetWidgetStyle(2),_Context->msg_Auto308[_Context->language],strlen(_Context->msg_Auto308[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+32,296,20,vfh[2],16,0,_Context->msg_Auto308[_Context->language],strlen(_Context->msg_Auto308[_Context->language]),32);
		}
	_Context->trigger_Auto309=visual_trigger_code(_Context->msg_Auto309[_Context->language],strlen(_Context->msg_Auto309[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+52,296,20,GetWidgetStyle(2),_Context->msg_Auto309[_Context->language],strlen(_Context->msg_Auto309[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+52,296,20,vfh[2],16,0,_Context->msg_Auto309[_Context->language],strlen(_Context->msg_Auto309[_Context->language]),32);
		}
	_Context->trigger_Auto310=visual_trigger_code(_Context->msg_Auto310[_Context->language],strlen(_Context->msg_Auto310[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+72,296,20,GetWidgetStyle(2),_Context->msg_Auto310[_Context->language],strlen(_Context->msg_Auto310[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+72,296,20,vfh[2],16,0,_Context->msg_Auto310[_Context->language],strlen(_Context->msg_Auto310[_Context->language]),32);
		}
	visual_filzone(_Context->x_Auto306+8,_Context->y_Auto306+92,312,4,26,18);
	_Context->trigger_Auto312=visual_trigger_code(_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+104,296,20,GetWidgetStyle(2),_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+104,296,20,vfh[2],16,0,_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]),32);
		}
	_Context->trigger_Auto313=visual_trigger_code(_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+128,296,20,GetWidgetStyle(2),_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+128,296,20,vfh[2],16,0,_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]),32);
		}
	_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+152,296,20,GetWidgetStyle(2),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+152,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),32);
		}
	_Context->trigger_Auto314=visual_trigger_code(_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+176,296,20,GetWidgetStyle(2),_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+176,296,20,vfh[2],16,0,_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]),32);
		}
	_Context->trigger_Auto315=visual_trigger_code(_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+196,296,20,GetWidgetStyle(2),_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+196,296,20,vfh[2],16,0,_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]),32);
		}
	visual_filzone(_Context->x_Auto306+8,_Context->y_Auto306+220,312,4,26,18);
	_Context->trigger_Auto317=visual_trigger_code(_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+252,296,20,GetWidgetStyle(2),_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+252,296,20,vfh[2],16,0,_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]),32);
		}
	_Context->trigger_Auto318=visual_trigger_code(_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+228,296,20,GetWidgetStyle(2),_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+228,296,20,vfh[2],16,0,_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]),32);
		}
	visual_thaw(_Context->x_Auto306,_Context->y_Auto306,328,284);

	return(0);
}
private int on_Auto307_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_INFO);
	return(-1);
}
private int on_Auto308_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_RESET);
	return(-1);
}
private int on_Auto309_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_BEST);
	return(-1);
}
private int on_Auto310_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_SCREEN);
	return(-1);
}
private int on_Auto312_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_TRACE);
	return(-1);
}
private int on_Auto313_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_HELP);
	return(-1);
}
private int on_previous_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_HYPER);
	return(-1);
}
private int on_Auto314_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_INHIBIT);
	return(-1);
}
private int on_Auto315_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_DETAIL);
	return(-1);
}
private int on_Auto317_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_SELECTION);
	return(-1);
}
private int on_Auto318_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_IMAGE);
	return(-1);
}


public	int	dependance_main_menu_event(
struct dependance_main_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto307 == mb ) return(1);
		if (_Context->trigger_Auto308 == mb ) return(2);
		if (_Context->trigger_Auto309 == mb ) return(3);
		if (_Context->trigger_Auto310 == mb ) return(4);
		if (_Context->trigger_Auto312 == mb ) return(5);
		if (_Context->trigger_Auto313 == mb ) return(6);
		if (_Context->trigger_previous == mb ) return(7);
		if (_Context->trigger_Auto314 == mb ) return(8);
		if (_Context->trigger_Auto315 == mb ) return(9);
		if (_Context->trigger_Auto317 == mb ) return(10);
		if (_Context->trigger_Auto318 == mb ) return(11);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_Auto306+8) ) 
	&&  ( my >= (_Context->y_Auto306+12) ) 
	&&  ( mx <= (_Context->x_Auto306+8+296) ) 
	&&  ( my <= (_Context->y_Auto306+12+20))) {
		return(1); /* Auto307 */
		}
	if (( mx >= (_Context->x_Auto306+8) ) 
	&&  ( my >= (_Context->y_Auto306+32) ) 
	&&  ( mx <= (_Context->x_Auto306+8+296) ) 
	&&  ( my <= (_Context->y_Auto306+32+20))) {
		return(2); /* Auto308 */
		}
	if (( mx >= (_Context->x_Auto306+8) ) 
	&&  ( my >= (_Context->y_Auto306+52) ) 
	&&  ( mx <= (_Context->x_Auto306+8+296) ) 
	&&  ( my <= (_Context->y_Auto306+52+20))) {
		return(3); /* Auto309 */
		}
	if (( mx >= (_Context->x_Auto306+8) ) 
	&&  ( my >= (_Context->y_Auto306+72) ) 
	&&  ( mx <= (_Context->x_Auto306+8+296) ) 
	&&  ( my <= (_Context->y_Auto306+72+20))) {
		return(4); /* Auto310 */
		}
	if (( mx >= (_Context->x_Auto306+8) ) 
	&&  ( my >= (_Context->y_Auto306+104) ) 
	&&  ( mx <= (_Context->x_Auto306+8+296) ) 
	&&  ( my <= (_Context->y_Auto306+104+20))) {
		return(5); /* Auto312 */
		}
	if (( mx >= (_Context->x_Auto306+8) ) 
	&&  ( my >= (_Context->y_Auto306+128) ) 
	&&  ( mx <= (_Context->x_Auto306+8+296) ) 
	&&  ( my <= (_Context->y_Auto306+128+20))) {
		return(6); /* Auto313 */
		}
	if (( mx >= (_Context->x_Auto306+8) ) 
	&&  ( my >= (_Context->y_Auto306+152) ) 
	&&  ( mx <= (_Context->x_Auto306+8+296) ) 
	&&  ( my <= (_Context->y_Auto306+152+20))) {
		return(7); /* previous */
		}
	if (( mx >= (_Context->x_Auto306+8) ) 
	&&  ( my >= (_Context->y_Auto306+176) ) 
	&&  ( mx <= (_Context->x_Auto306+8+296) ) 
	&&  ( my <= (_Context->y_Auto306+176+20))) {
		return(8); /* Auto314 */
		}
	if (( mx >= (_Context->x_Auto306+8) ) 
	&&  ( my >= (_Context->y_Auto306+196) ) 
	&&  ( mx <= (_Context->x_Auto306+8+296) ) 
	&&  ( my <= (_Context->y_Auto306+196+20))) {
		return(9); /* Auto315 */
		}
	if (( mx >= (_Context->x_Auto306+8) ) 
	&&  ( my >= (_Context->y_Auto306+252) ) 
	&&  ( mx <= (_Context->x_Auto306+8+296) ) 
	&&  ( my <= (_Context->y_Auto306+252+20))) {
		return(10); /* Auto317 */
		}
	if (( mx >= (_Context->x_Auto306+8) ) 
	&&  ( my >= (_Context->y_Auto306+228) ) 
	&&  ( mx <= (_Context->x_Auto306+8+296) ) 
	&&  ( my <= (_Context->y_Auto306+228+20))) {
		return(11); /* Auto318 */
		}

	return(-1);
}


public	int	dependance_main_menu_focus(struct dependance_main_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto307 */
				_Context->trigger_Auto307=visual_trigger_code(_Context->msg_Auto307[_Context->language],strlen(_Context->msg_Auto307[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+12,296,20,GetWidgetStyle(3),_Context->msg_Auto307[_Context->language],strlen(_Context->msg_Auto307[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto306+8,_Context->y_Auto306+12,296,20,vfh[2],16,0,_Context->msg_Auto307[_Context->language],strlen(_Context->msg_Auto307[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto307=visual_trigger_code(_Context->msg_Auto307[_Context->language],strlen(_Context->msg_Auto307[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+12,296,20,GetWidgetStyle(2),_Context->msg_Auto307[_Context->language],strlen(_Context->msg_Auto307[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+12,296,20,vfh[2],16,0,_Context->msg_Auto307[_Context->language],strlen(_Context->msg_Auto307[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto308 */
				_Context->trigger_Auto308=visual_trigger_code(_Context->msg_Auto308[_Context->language],strlen(_Context->msg_Auto308[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+32,296,20,GetWidgetStyle(3),_Context->msg_Auto308[_Context->language],strlen(_Context->msg_Auto308[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto306+8,_Context->y_Auto306+32,296,20,vfh[2],16,0,_Context->msg_Auto308[_Context->language],strlen(_Context->msg_Auto308[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto308=visual_trigger_code(_Context->msg_Auto308[_Context->language],strlen(_Context->msg_Auto308[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+32,296,20,GetWidgetStyle(2),_Context->msg_Auto308[_Context->language],strlen(_Context->msg_Auto308[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+32,296,20,vfh[2],16,0,_Context->msg_Auto308[_Context->language],strlen(_Context->msg_Auto308[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto309 */
				_Context->trigger_Auto309=visual_trigger_code(_Context->msg_Auto309[_Context->language],strlen(_Context->msg_Auto309[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+52,296,20,GetWidgetStyle(3),_Context->msg_Auto309[_Context->language],strlen(_Context->msg_Auto309[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto306+8,_Context->y_Auto306+52,296,20,vfh[2],16,0,_Context->msg_Auto309[_Context->language],strlen(_Context->msg_Auto309[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto309=visual_trigger_code(_Context->msg_Auto309[_Context->language],strlen(_Context->msg_Auto309[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+52,296,20,GetWidgetStyle(2),_Context->msg_Auto309[_Context->language],strlen(_Context->msg_Auto309[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+52,296,20,vfh[2],16,0,_Context->msg_Auto309[_Context->language],strlen(_Context->msg_Auto309[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto310 */
				_Context->trigger_Auto310=visual_trigger_code(_Context->msg_Auto310[_Context->language],strlen(_Context->msg_Auto310[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+72,296,20,GetWidgetStyle(3),_Context->msg_Auto310[_Context->language],strlen(_Context->msg_Auto310[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto306+8,_Context->y_Auto306+72,296,20,vfh[2],16,0,_Context->msg_Auto310[_Context->language],strlen(_Context->msg_Auto310[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto310=visual_trigger_code(_Context->msg_Auto310[_Context->language],strlen(_Context->msg_Auto310[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+72,296,20,GetWidgetStyle(2),_Context->msg_Auto310[_Context->language],strlen(_Context->msg_Auto310[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+72,296,20,vfh[2],16,0,_Context->msg_Auto310[_Context->language],strlen(_Context->msg_Auto310[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto312 */
				_Context->trigger_Auto312=visual_trigger_code(_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+104,296,20,GetWidgetStyle(3),_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto306+8,_Context->y_Auto306+104,296,20,vfh[2],16,0,_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto312=visual_trigger_code(_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+104,296,20,GetWidgetStyle(2),_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+104,296,20,vfh[2],16,0,_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]),32);
				}
				break;
			case	0x6 :
				/* Auto313 */
				_Context->trigger_Auto313=visual_trigger_code(_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+128,296,20,GetWidgetStyle(3),_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto306+8,_Context->y_Auto306+128,296,20,vfh[2],16,0,_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto313=visual_trigger_code(_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+128,296,20,GetWidgetStyle(2),_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+128,296,20,vfh[2],16,0,_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]),32);
				}
				break;
			case	0x7 :
				/* previous */
				_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+152,296,20,GetWidgetStyle(3),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto306+8,_Context->y_Auto306+152,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+152,296,20,GetWidgetStyle(2),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+152,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),32);
				}
				break;
			case	0x8 :
				/* Auto314 */
				_Context->trigger_Auto314=visual_trigger_code(_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+176,296,20,GetWidgetStyle(3),_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto306+8,_Context->y_Auto306+176,296,20,vfh[2],16,0,_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto314=visual_trigger_code(_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+176,296,20,GetWidgetStyle(2),_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+176,296,20,vfh[2],16,0,_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]),32);
				}
				break;
			case	0x9 :
				/* Auto315 */
				_Context->trigger_Auto315=visual_trigger_code(_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+196,296,20,GetWidgetStyle(3),_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto306+8,_Context->y_Auto306+196,296,20,vfh[2],16,0,_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto315=visual_trigger_code(_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+196,296,20,GetWidgetStyle(2),_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+196,296,20,vfh[2],16,0,_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]),32);
				}
				break;
			case	0xa :
				/* Auto317 */
				_Context->trigger_Auto317=visual_trigger_code(_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+252,296,20,GetWidgetStyle(3),_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto306+8,_Context->y_Auto306+252,296,20,vfh[2],16,0,_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto317=visual_trigger_code(_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+252,296,20,GetWidgetStyle(2),_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+252,296,20,vfh[2],16,0,_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]),32);
				}
				break;
			case	0xb :
				/* Auto318 */
				_Context->trigger_Auto318=visual_trigger_code(_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+228,296,20,GetWidgetStyle(3),_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto306+8,_Context->y_Auto306+228,296,20,vfh[2],16,0,_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto318=visual_trigger_code(_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+228,296,20,GetWidgetStyle(2),_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+228,296,20,vfh[2],16,0,_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			dependance_main_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=11;
			dependance_main_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  _Context->x_Auto306 )
				|| ( visual_event(6) < _Context->y_Auto306  )
				|| ( visual_event(7) > (_Context->x_Auto306+_Context->w_Auto306))
				|| ( visual_event(6) >  (_Context->y_Auto306+_Context->h_Auto306))) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=dependance_main_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto307 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto307=visual_trigger_code(_Context->msg_Auto307[_Context->language],strlen(_Context->msg_Auto307[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+12,296,20,GetWidgetStyle(3),_Context->msg_Auto307[_Context->language],strlen(_Context->msg_Auto307[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto306+8,_Context->y_Auto306+12,296,20,vfh[2],16,0,_Context->msg_Auto307[_Context->language],strlen(_Context->msg_Auto307[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto307=visual_trigger_code(_Context->msg_Auto307[_Context->language],strlen(_Context->msg_Auto307[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+12,296,20,GetWidgetStyle(2),_Context->msg_Auto307[_Context->language],strlen(_Context->msg_Auto307[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+12,296,20,vfh[2],16,0,_Context->msg_Auto307[_Context->language],strlen(_Context->msg_Auto307[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto307_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto308 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto308=visual_trigger_code(_Context->msg_Auto308[_Context->language],strlen(_Context->msg_Auto308[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+32,296,20,GetWidgetStyle(3),_Context->msg_Auto308[_Context->language],strlen(_Context->msg_Auto308[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto306+8,_Context->y_Auto306+32,296,20,vfh[2],16,0,_Context->msg_Auto308[_Context->language],strlen(_Context->msg_Auto308[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto308=visual_trigger_code(_Context->msg_Auto308[_Context->language],strlen(_Context->msg_Auto308[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+32,296,20,GetWidgetStyle(2),_Context->msg_Auto308[_Context->language],strlen(_Context->msg_Auto308[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+32,296,20,vfh[2],16,0,_Context->msg_Auto308[_Context->language],strlen(_Context->msg_Auto308[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto308_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto309 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto309=visual_trigger_code(_Context->msg_Auto309[_Context->language],strlen(_Context->msg_Auto309[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+52,296,20,GetWidgetStyle(3),_Context->msg_Auto309[_Context->language],strlen(_Context->msg_Auto309[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto306+8,_Context->y_Auto306+52,296,20,vfh[2],16,0,_Context->msg_Auto309[_Context->language],strlen(_Context->msg_Auto309[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto309=visual_trigger_code(_Context->msg_Auto309[_Context->language],strlen(_Context->msg_Auto309[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+52,296,20,GetWidgetStyle(2),_Context->msg_Auto309[_Context->language],strlen(_Context->msg_Auto309[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+52,296,20,vfh[2],16,0,_Context->msg_Auto309[_Context->language],strlen(_Context->msg_Auto309[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto309_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto310 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto310=visual_trigger_code(_Context->msg_Auto310[_Context->language],strlen(_Context->msg_Auto310[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+72,296,20,GetWidgetStyle(3),_Context->msg_Auto310[_Context->language],strlen(_Context->msg_Auto310[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto306+8,_Context->y_Auto306+72,296,20,vfh[2],16,0,_Context->msg_Auto310[_Context->language],strlen(_Context->msg_Auto310[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto310=visual_trigger_code(_Context->msg_Auto310[_Context->language],strlen(_Context->msg_Auto310[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+72,296,20,GetWidgetStyle(2),_Context->msg_Auto310[_Context->language],strlen(_Context->msg_Auto310[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+72,296,20,vfh[2],16,0,_Context->msg_Auto310[_Context->language],strlen(_Context->msg_Auto310[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto310_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto312 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto312=visual_trigger_code(_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+104,296,20,GetWidgetStyle(3),_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto306+8,_Context->y_Auto306+104,296,20,vfh[2],16,0,_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto312=visual_trigger_code(_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+104,296,20,GetWidgetStyle(2),_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+104,296,20,vfh[2],16,0,_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto312_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto313 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto313=visual_trigger_code(_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+128,296,20,GetWidgetStyle(3),_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto306+8,_Context->y_Auto306+128,296,20,vfh[2],16,0,_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto313=visual_trigger_code(_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+128,296,20,GetWidgetStyle(2),_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+128,296,20,vfh[2],16,0,_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto313_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* previous */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+152,296,20,GetWidgetStyle(3),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto306+8,_Context->y_Auto306+152,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+152,296,20,GetWidgetStyle(2),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+152,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_previous_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Auto314 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto314=visual_trigger_code(_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+176,296,20,GetWidgetStyle(3),_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto306+8,_Context->y_Auto306+176,296,20,vfh[2],16,0,_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto314=visual_trigger_code(_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+176,296,20,GetWidgetStyle(2),_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+176,296,20,vfh[2],16,0,_Context->msg_Auto314[_Context->language],strlen(_Context->msg_Auto314[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto314_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Auto315 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto315=visual_trigger_code(_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+196,296,20,GetWidgetStyle(3),_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto306+8,_Context->y_Auto306+196,296,20,vfh[2],16,0,_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto315=visual_trigger_code(_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+196,296,20,GetWidgetStyle(2),_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+196,296,20,vfh[2],16,0,_Context->msg_Auto315[_Context->language],strlen(_Context->msg_Auto315[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto315_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Auto317 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto317=visual_trigger_code(_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+252,296,20,GetWidgetStyle(3),_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto306+8,_Context->y_Auto306+252,296,20,vfh[2],16,0,_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto317=visual_trigger_code(_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+252,296,20,GetWidgetStyle(2),_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+252,296,20,vfh[2],16,0,_Context->msg_Auto317[_Context->language],strlen(_Context->msg_Auto317[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto317_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Auto318 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto318=visual_trigger_code(_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+228,296,20,GetWidgetStyle(3),_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto306+8,_Context->y_Auto306+228,296,20,vfh[2],16,0,_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto318=visual_trigger_code(_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto306+8,_Context->y_Auto306+228,296,20,GetWidgetStyle(2),_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto306+8,_Context->y_Auto306+228,296,20,vfh[2],16,0,_Context->msg_Auto318[_Context->language],strlen(_Context->msg_Auto318[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto318_event(_Context)) != -1) break;

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
				_Context->focus_item=11;
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

public	int	dependance_main_menu()
{
	int	status=0;
	struct dependance_main_menu_context * _Context=(struct dependance_main_menu_context*) 0;
	status = dependance_main_menu_create(&_Context);
	if ( status != 0) return(status);
	status = dependance_main_menu_show(_Context);
		enter_modal();
	status = dependance_main_menu_focus(_Context);
		leave_modal();
	status = dependance_main_menu_hide(_Context);
	status = dependance_main_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _depmenu_c */
