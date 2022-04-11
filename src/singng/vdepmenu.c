
#ifndef _vdepmenu_c
#define _vdepmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : depmenu.xml                                              */
/* Target         : vdepmenu.c                                               */
/* Identification : 0.0-1196377892-4433.4432                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#include "singfmed.h"
#define en_Auto322   "Sing Version 2.1a"
#define fr_Auto322   "Sing Version 2.1a"
#define it_Auto322   "Sing Version 2.1a"
#define es_Auto322   "Sing Version 2.1a"
#define de_Auto322   "Sing Version 2.1a"
#define nl_Auto322   "Sing Version 2.1a"
#define pt_Auto322   "Sing Version 2.1a"
#define xx_Auto322   "Sing Version 2.1a"
#define en__Auto322   ""
#define fr__Auto322   ""
#define it__Auto322   ""
#define es__Auto322   ""
#define de__Auto322   ""
#define nl__Auto322   ""
#define pt__Auto322   ""
#define xx__Auto322   ""
#define en_Auto323   "&Model Editor Properties and Options"
#define fr_Auto323   "&Model Editor Properties and Options"
#define it_Auto323   "&Model Editor Properties and Options"
#define es_Auto323   "&Model Editor Properties and Options"
#define de_Auto323   "&Model Editor Properties and Options"
#define nl_Auto323   "&Model Editor Properties and Options"
#define pt_Auto323   "&Model Editor Properties and Options"
#define xx_Auto323   "&Model Editor Properties and Options"
#define en__Auto323   ""
#define fr__Auto323   ""
#define it__Auto323   ""
#define es__Auto323   ""
#define de__Auto323   ""
#define nl__Auto323   ""
#define pt__Auto323   ""
#define xx__Auto323   ""
#define en_Auto324   "&Reset and Recalculate Dependance Display"
#define fr_Auto324   "&Reset and Recalculate Dependance Display"
#define it_Auto324   "&Reset and Recalculate Dependance Display"
#define es_Auto324   "&Reset and Recalculate Dependance Display"
#define de_Auto324   "&Reset and Recalculate Dependance Display"
#define nl_Auto324   "&Reset and Recalculate Dependance Display"
#define pt_Auto324   "&Reset and Recalculate Dependance Display"
#define xx_Auto324   "&Reset and Recalculate Dependance Display"
#define en__Auto324   ""
#define fr__Auto324   ""
#define it__Auto324   ""
#define es__Auto324   ""
#define de__Auto324   ""
#define nl__Auto324   ""
#define pt__Auto324   ""
#define xx__Auto324   ""
#define en_Auto325   "&Calculate Best Positioning"
#define fr_Auto325   "&Calculate Best Positioning"
#define it_Auto325   "&Calculate Best Positioning"
#define es_Auto325   "&Calculate Best Positioning"
#define de_Auto325   "&Calculate Best Positioning"
#define nl_Auto325   "&Calculate Best Positioning"
#define pt_Auto325   "&Calculate Best Positioning"
#define xx_Auto325   "&Calculate Best Positioning"
#define en__Auto325   ""
#define fr__Auto325   ""
#define it__Auto325   ""
#define es__Auto325   ""
#define de__Auto325   ""
#define nl__Auto325   ""
#define pt__Auto325   ""
#define xx__Auto325   ""
#define en_Auto326   "R&efresh Screen Display"
#define fr_Auto326   "R&efresh Screen Display"
#define it_Auto326   "R&efresh Screen Display"
#define es_Auto326   "R&efresh Screen Display"
#define de_Auto326   "R&efresh Screen Display"
#define nl_Auto326   "R&efresh Screen Display"
#define pt_Auto326   "R&efresh Screen Display"
#define xx_Auto326   "R&efresh Screen Display"
#define en__Auto326   ""
#define fr__Auto326   ""
#define it__Auto326   ""
#define es__Auto326   ""
#define de__Auto326   ""
#define nl__Auto326   ""
#define pt__Auto326   ""
#define xx__Auto326   ""
#define en_Auto328   "&Toggle Relation Tracing : Direct/Routed"
#define fr_Auto328   "&Toggle Relation Tracing : Direct/Routed"
#define it_Auto328   "&Toggle Relation Tracing : Direct/Routed"
#define es_Auto328   "&Toggle Relation Tracing : Direct/Routed"
#define de_Auto328   "&Toggle Relation Tracing : Direct/Routed"
#define nl_Auto328   "&Toggle Relation Tracing : Direct/Routed"
#define pt_Auto328   "&Toggle Relation Tracing : Direct/Routed"
#define xx_Auto328   "&Toggle Relation Tracing : Direct/Routed"
#define en__Auto328   ""
#define fr__Auto328   ""
#define it__Auto328   ""
#define es__Auto328   ""
#define de__Auto328   ""
#define nl__Auto328   ""
#define pt__Auto328   ""
#define xx__Auto328   ""
#define en_Auto329   "T&oggle display of Help Bubble messages"
#define fr_Auto329   "T&oggle display of Help Bubble messages"
#define it_Auto329   "T&oggle display of Help Bubble messages"
#define es_Auto329   "T&oggle display of Help Bubble messages"
#define de_Auto329   "T&oggle display of Help Bubble messages"
#define nl_Auto329   "T&oggle display of Help Bubble messages"
#define pt_Auto329   "T&oggle display of Help Bubble messages"
#define xx_Auto329   "T&oggle display of Help Bubble messages"
#define en__Auto329   ""
#define fr__Auto329   ""
#define it__Auto329   ""
#define es__Auto329   ""
#define de__Auto329   ""
#define nl__Auto329   ""
#define pt__Auto329   ""
#define xx__Auto329   ""
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
#define en_Auto330   "Togg&le Model Display : Selection / All"
#define fr_Auto330   "Togg&le Database display : Project/Forms"
#define it_Auto330   "Togg&le Database display : Project/Forms"
#define es_Auto330   "Togg&le Database display : Project/Forms"
#define de_Auto330   "Togg&le Database display : Project/Forms"
#define nl_Auto330   "Togg&le Database display : Project/Forms"
#define pt_Auto330   "Togg&le Database display : Project/Forms"
#define xx_Auto330   "Togg&le Database display : Project/Forms"
#define en__Auto330   ""
#define fr__Auto330   ""
#define it__Auto330   ""
#define es__Auto330   ""
#define de__Auto330   ""
#define nl__Auto330   ""
#define pt__Auto330   ""
#define xx__Auto330   ""
#define en_Auto331   "Toggle Mo&del Detail"
#define fr_Auto331   "Toggle &Flowchart Detail"
#define it_Auto331   "Toggle &Flowchart Detail"
#define es_Auto331   "Toggle &Flowchart Detail"
#define de_Auto331   "Toggle &Flowchart Detail"
#define nl_Auto331   "Toggle &Flowchart Detail"
#define pt_Auto331   "Toggle &Flowchart Detail"
#define xx_Auto331   "Toggle &Flowchart Detail"
#define en__Auto331   ""
#define fr__Auto331   ""
#define it__Auto331   ""
#define es__Auto331   ""
#define de__Auto331   ""
#define nl__Auto331   ""
#define pt__Auto331   ""
#define xx__Auto331   ""
#define en_Auto332   "Toggle Model Mode &: Dependance / Dependants"
#define fr_Auto332   "Toggle Mo&del View : Dependance / Dependants"
#define it_Auto332   "Toggle Mo&del View : Dependance / Dependants"
#define es_Auto332   "Toggle Mo&del View : Dependance / Dependants"
#define de_Auto332   "Toggle Mo&del View : Dependance / Dependants"
#define nl_Auto332   "Toggle Mo&del View : Dependance / Dependants"
#define pt_Auto332   "Toggle Mo&del View : Dependance / Dependants"
#define xx_Auto332   "Toggle Mo&del View : Dependance / Dependants"
#define en__Auto332   ""
#define fr__Auto332   ""
#define it__Auto332   ""
#define es__Auto332   ""
#define de__Auto332   ""
#define nl__Auto332   ""
#define pt__Auto332   ""
#define xx__Auto332   ""
#define en_Auto334   "De&fine Dependance Model Domain/Class Selection"
#define fr_Auto334   "Def&ine Class Domain / Selection"
#define it_Auto334   "Def&ine Class Domain / Selection"
#define es_Auto334   "Def&ine Class Domain / Selection"
#define de_Auto334   "Def&ine Class Domain / Selection"
#define nl_Auto334   "Def&ine Class Domain / Selection"
#define pt_Auto334   "Def&ine Class Domain / Selection"
#define xx_Auto334   "Def&ine Class Domain / Selection"
#define en__Auto334   ""
#define fr__Auto334   ""
#define it__Auto334   ""
#define es__Auto334   ""
#define de__Auto334   ""
#define nl__Auto334   ""
#define pt__Auto334   ""
#define xx__Auto334   ""
#define en_Auto335   "&Save Dependance Model to Image File"
#define fr_Auto335   "&Save to Image File"
#define it_Auto335   "&Save to Image File"
#define es_Auto335   "&Save to Image File"
#define de_Auto335   "&Save to Image File"
#define nl_Auto335   "&Save to Image File"
#define pt_Auto335   "&Save to Image File"
#define xx_Auto335   "&Save to Image File"
#define en__Auto335   ""
#define fr__Auto335   ""
#define it__Auto335   ""
#define es__Auto335   ""
#define de__Auto335   ""
#define nl__Auto335   ""
#define pt__Auto335   ""
#define xx__Auto335   ""
#define en_Auto336   "E&xport all Style Class to File"
#define fr_Auto336   "S&ave to Image File"
#define it_Auto336   "S&ave to Image File"
#define es_Auto336   "S&ave to Image File"
#define de_Auto336   "S&ave to Image File"
#define nl_Auto336   "S&ave to Image File"
#define pt_Auto336   "S&ave to Image File"
#define xx_Auto336   "S&ave to Image File"
#define en__Auto336   ""
#define fr__Auto336   ""
#define it__Auto336   ""
#define es__Auto336   ""
#define de__Auto336   ""
#define nl__Auto336   ""
#define pt__Auto336   ""
#define xx__Auto336   ""
#define en_Auto337   "&Import Style Classes from File"
#define fr_Auto337   "Sa&ve to Image File"
#define it_Auto337   "Sa&ve to Image File"
#define es_Auto337   "Sa&ve to Image File"
#define de_Auto337   "Sa&ve to Image File"
#define nl_Auto337   "Sa&ve to Image File"
#define pt_Auto337   "Sa&ve to Image File"
#define xx_Auto337   "Sa&ve to Image File"
#define en__Auto337   ""
#define fr__Auto337   ""
#define it__Auto337   ""
#define es__Auto337   ""
#define de__Auto337   ""
#define nl__Auto337   ""
#define pt__Auto337   ""
#define xx__Auto337   ""
#define en_Auto338   "&Add New Style Class"
#define fr_Auto338   "Add &New Style Class"
#define it_Auto338   "Add &New Style Class"
#define es_Auto338   "Add &New Style Class"
#define de_Auto338   "Add &New Style Class"
#define nl_Auto338   "Add &New Style Class"
#define pt_Auto338   "Add &New Style Class"
#define xx_Auto338   "Add &New Style Class"
#define en__Auto338   ""
#define fr__Auto338   ""
#define it__Auto338   ""
#define es__Auto338   ""
#define de__Auto338   ""
#define nl__Auto338   ""
#define pt__Auto338   ""
#define xx__Auto338   ""

private struct dependance_main_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto322[8];
	char * hint_Auto322[8];
	int	s_Auto322;
	void *	p_Auto322;
	int	x_Auto322;
	int	y_Auto322;
	int	w_Auto322;
	int	h_Auto322;
	char * msg_Auto323[8];
	int	trigger_Auto323;
	char * hint_Auto323[8];
	char * msg_Auto324[8];
	int	trigger_Auto324;
	char * hint_Auto324[8];
	char * msg_Auto325[8];
	int	trigger_Auto325;
	char * hint_Auto325[8];
	char * msg_Auto326[8];
	int	trigger_Auto326;
	char * hint_Auto326[8];
	char * hint_Auto327[8];
	char * msg_Auto328[8];
	int	trigger_Auto328;
	char * hint_Auto328[8];
	char * msg_Auto329[8];
	int	trigger_Auto329;
	char * hint_Auto329[8];
	char * msg_previous[8];
	int	trigger_previous;
	char * hint_previous[8];
	char * msg_Auto330[8];
	int	trigger_Auto330;
	char * hint_Auto330[8];
	char * msg_Auto331[8];
	int	trigger_Auto331;
	char * hint_Auto331[8];
	char * msg_Auto332[8];
	int	trigger_Auto332;
	char * hint_Auto332[8];
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

private int on_Auto322_create(struct dependance_main_menu_context * _Context) {
	mouse_move_on();
	if(((_Context->y_Auto322=visual_event(6))+356)>hardrows())
	_Context->y_Auto322=(hardrows()-356);
	if(((_Context->x_Auto322=visual_event(7))+344)>hardcolumns())
	_Context->x_Auto322=(hardcolumns()-344);
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
	_Context->focus_items=15;
	for (i=0; i < 8; i++)_Context->msg_Auto322[i]=" ";
	_Context->msg_Auto322[0]=en_Auto322;
	_Context->msg_Auto322[1]=fr_Auto322;
	_Context->msg_Auto322[2]=it_Auto322;
	_Context->msg_Auto322[3]=es_Auto322;
	_Context->msg_Auto322[4]=de_Auto322;
	_Context->msg_Auto322[5]=nl_Auto322;
	_Context->msg_Auto322[6]=pt_Auto322;
	_Context->msg_Auto322[7]=xx_Auto322;
	_Context->hint_Auto322[0]=en__Auto322;
	_Context->hint_Auto322[1]=fr__Auto322;
	_Context->hint_Auto322[2]=it__Auto322;
	_Context->hint_Auto322[3]=es__Auto322;
	_Context->hint_Auto322[4]=de__Auto322;
	_Context->hint_Auto322[5]=nl__Auto322;
	_Context->hint_Auto322[6]=pt__Auto322;
	_Context->hint_Auto322[7]=xx__Auto322;
	_Context->s_Auto322=0;
	_Context->p_Auto322=visual_buffer(_Context->x_Auto322,_Context->y_Auto322,344+2,356+2);
	_Context->x_Auto322=32;
	_Context->y_Auto322=64;
	_Context->w_Auto322=344;
	_Context->h_Auto322=356;
	_Context->window_col=32;
	_Context->window_row=64;
	(void) on_Auto322_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Auto323[i]=" ";
	_Context->msg_Auto323[0]=en_Auto323;
	_Context->msg_Auto323[1]=fr_Auto323;
	_Context->msg_Auto323[2]=it_Auto323;
	_Context->msg_Auto323[3]=es_Auto323;
	_Context->msg_Auto323[4]=de_Auto323;
	_Context->msg_Auto323[5]=nl_Auto323;
	_Context->msg_Auto323[6]=pt_Auto323;
	_Context->msg_Auto323[7]=xx_Auto323;
	_Context->hint_Auto323[0]=en__Auto323;
	_Context->hint_Auto323[1]=fr__Auto323;
	_Context->hint_Auto323[2]=it__Auto323;
	_Context->hint_Auto323[3]=es__Auto323;
	_Context->hint_Auto323[4]=de__Auto323;
	_Context->hint_Auto323[5]=nl__Auto323;
	_Context->hint_Auto323[6]=pt__Auto323;
	_Context->hint_Auto323[7]=xx__Auto323;
	for (i=0; i < 8; i++)_Context->msg_Auto324[i]=" ";
	_Context->msg_Auto324[0]=en_Auto324;
	_Context->msg_Auto324[1]=fr_Auto324;
	_Context->msg_Auto324[2]=it_Auto324;
	_Context->msg_Auto324[3]=es_Auto324;
	_Context->msg_Auto324[4]=de_Auto324;
	_Context->msg_Auto324[5]=nl_Auto324;
	_Context->msg_Auto324[6]=pt_Auto324;
	_Context->msg_Auto324[7]=xx_Auto324;
	_Context->hint_Auto324[0]=en__Auto324;
	_Context->hint_Auto324[1]=fr__Auto324;
	_Context->hint_Auto324[2]=it__Auto324;
	_Context->hint_Auto324[3]=es__Auto324;
	_Context->hint_Auto324[4]=de__Auto324;
	_Context->hint_Auto324[5]=nl__Auto324;
	_Context->hint_Auto324[6]=pt__Auto324;
	_Context->hint_Auto324[7]=xx__Auto324;
	for (i=0; i < 8; i++)_Context->msg_Auto325[i]=" ";
	_Context->msg_Auto325[0]=en_Auto325;
	_Context->msg_Auto325[1]=fr_Auto325;
	_Context->msg_Auto325[2]=it_Auto325;
	_Context->msg_Auto325[3]=es_Auto325;
	_Context->msg_Auto325[4]=de_Auto325;
	_Context->msg_Auto325[5]=nl_Auto325;
	_Context->msg_Auto325[6]=pt_Auto325;
	_Context->msg_Auto325[7]=xx_Auto325;
	_Context->hint_Auto325[0]=en__Auto325;
	_Context->hint_Auto325[1]=fr__Auto325;
	_Context->hint_Auto325[2]=it__Auto325;
	_Context->hint_Auto325[3]=es__Auto325;
	_Context->hint_Auto325[4]=de__Auto325;
	_Context->hint_Auto325[5]=nl__Auto325;
	_Context->hint_Auto325[6]=pt__Auto325;
	_Context->hint_Auto325[7]=xx__Auto325;
	for (i=0; i < 8; i++)_Context->msg_Auto326[i]=" ";
	_Context->msg_Auto326[0]=en_Auto326;
	_Context->msg_Auto326[1]=fr_Auto326;
	_Context->msg_Auto326[2]=it_Auto326;
	_Context->msg_Auto326[3]=es_Auto326;
	_Context->msg_Auto326[4]=de_Auto326;
	_Context->msg_Auto326[5]=nl_Auto326;
	_Context->msg_Auto326[6]=pt_Auto326;
	_Context->msg_Auto326[7]=xx_Auto326;
	_Context->hint_Auto326[0]=en__Auto326;
	_Context->hint_Auto326[1]=fr__Auto326;
	_Context->hint_Auto326[2]=it__Auto326;
	_Context->hint_Auto326[3]=es__Auto326;
	_Context->hint_Auto326[4]=de__Auto326;
	_Context->hint_Auto326[5]=nl__Auto326;
	_Context->hint_Auto326[6]=pt__Auto326;
	_Context->hint_Auto326[7]=xx__Auto326;
	for (i=0; i < 8; i++)_Context->msg_Auto328[i]=" ";
	_Context->msg_Auto328[0]=en_Auto328;
	_Context->msg_Auto328[1]=fr_Auto328;
	_Context->msg_Auto328[2]=it_Auto328;
	_Context->msg_Auto328[3]=es_Auto328;
	_Context->msg_Auto328[4]=de_Auto328;
	_Context->msg_Auto328[5]=nl_Auto328;
	_Context->msg_Auto328[6]=pt_Auto328;
	_Context->msg_Auto328[7]=xx_Auto328;
	_Context->hint_Auto328[0]=en__Auto328;
	_Context->hint_Auto328[1]=fr__Auto328;
	_Context->hint_Auto328[2]=it__Auto328;
	_Context->hint_Auto328[3]=es__Auto328;
	_Context->hint_Auto328[4]=de__Auto328;
	_Context->hint_Auto328[5]=nl__Auto328;
	_Context->hint_Auto328[6]=pt__Auto328;
	_Context->hint_Auto328[7]=xx__Auto328;
	for (i=0; i < 8; i++)_Context->msg_Auto329[i]=" ";
	_Context->msg_Auto329[0]=en_Auto329;
	_Context->msg_Auto329[1]=fr_Auto329;
	_Context->msg_Auto329[2]=it_Auto329;
	_Context->msg_Auto329[3]=es_Auto329;
	_Context->msg_Auto329[4]=de_Auto329;
	_Context->msg_Auto329[5]=nl_Auto329;
	_Context->msg_Auto329[6]=pt_Auto329;
	_Context->msg_Auto329[7]=xx_Auto329;
	_Context->hint_Auto329[0]=en__Auto329;
	_Context->hint_Auto329[1]=fr__Auto329;
	_Context->hint_Auto329[2]=it__Auto329;
	_Context->hint_Auto329[3]=es__Auto329;
	_Context->hint_Auto329[4]=de__Auto329;
	_Context->hint_Auto329[5]=nl__Auto329;
	_Context->hint_Auto329[6]=pt__Auto329;
	_Context->hint_Auto329[7]=xx__Auto329;
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
	for (i=0; i < 8; i++)_Context->msg_Auto330[i]=" ";
	_Context->msg_Auto330[0]=en_Auto330;
	_Context->msg_Auto330[1]=fr_Auto330;
	_Context->msg_Auto330[2]=it_Auto330;
	_Context->msg_Auto330[3]=es_Auto330;
	_Context->msg_Auto330[4]=de_Auto330;
	_Context->msg_Auto330[5]=nl_Auto330;
	_Context->msg_Auto330[6]=pt_Auto330;
	_Context->msg_Auto330[7]=xx_Auto330;
	_Context->hint_Auto330[0]=en__Auto330;
	_Context->hint_Auto330[1]=fr__Auto330;
	_Context->hint_Auto330[2]=it__Auto330;
	_Context->hint_Auto330[3]=es__Auto330;
	_Context->hint_Auto330[4]=de__Auto330;
	_Context->hint_Auto330[5]=nl__Auto330;
	_Context->hint_Auto330[6]=pt__Auto330;
	_Context->hint_Auto330[7]=xx__Auto330;
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
	_Context->hint_Auto332[0]=en__Auto332;
	_Context->hint_Auto332[1]=fr__Auto332;
	_Context->hint_Auto332[2]=it__Auto332;
	_Context->hint_Auto332[3]=es__Auto332;
	_Context->hint_Auto332[4]=de__Auto332;
	_Context->hint_Auto332[5]=nl__Auto332;
	_Context->hint_Auto332[6]=pt__Auto332;
	_Context->hint_Auto332[7]=xx__Auto332;
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
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto322,_Context->y_Auto322,344,356);
	return(0);
}

public 	int	dependance_main_menu_hide(struct dependance_main_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto322 != (void *) 0)
	&& (_Context->s_Auto322 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto322,_Context->x_Auto322,_Context->y_Auto322);
		_Context->s_Auto322=0;
		}
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto322,_Context->y_Auto322);
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
	if (_Context->p_Auto322 != (void *) 0)
		_Context->p_Auto322 = visual_drop(_Context->p_Auto322);
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
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto322,_Context->y_Auto322);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if ((_Context->p_Auto322 != (void *) 0)
	&& (_Context->s_Auto322 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto322,_Context->x_Auto322,_Context->y_Auto322);
		_Context->s_Auto322=1;
		}
	if (((_Context->status = visual_styled_element(_Context->x_Auto322,_Context->y_Auto322,344,356,GetWidgetStyle(1),_Context->msg_Auto322[_Context->language],strlen(_Context->msg_Auto322[_Context->language]))) != 0)
) {
		visual_window(_Context->x_Auto322,_Context->y_Auto322,344,356,vfh[1],_Context->msg_Auto322[_Context->language],strlen(_Context->msg_Auto322[_Context->language]),0x4);
		}
	_Context->trigger_Auto323=visual_trigger_code(_Context->msg_Auto323[_Context->language],strlen(_Context->msg_Auto323[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+8,296,20,GetWidgetStyle(2),_Context->msg_Auto323[_Context->language],strlen(_Context->msg_Auto323[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+8,296,20,vfh[2],16,0,_Context->msg_Auto323[_Context->language],strlen(_Context->msg_Auto323[_Context->language]),32);
		}
	_Context->trigger_Auto324=visual_trigger_code(_Context->msg_Auto324[_Context->language],strlen(_Context->msg_Auto324[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+28,296,20,GetWidgetStyle(2),_Context->msg_Auto324[_Context->language],strlen(_Context->msg_Auto324[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+28,296,20,vfh[2],16,0,_Context->msg_Auto324[_Context->language],strlen(_Context->msg_Auto324[_Context->language]),32);
		}
	_Context->trigger_Auto325=visual_trigger_code(_Context->msg_Auto325[_Context->language],strlen(_Context->msg_Auto325[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+48,296,20,GetWidgetStyle(2),_Context->msg_Auto325[_Context->language],strlen(_Context->msg_Auto325[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+48,296,20,vfh[2],16,0,_Context->msg_Auto325[_Context->language],strlen(_Context->msg_Auto325[_Context->language]),32);
		}
	_Context->trigger_Auto326=visual_trigger_code(_Context->msg_Auto326[_Context->language],strlen(_Context->msg_Auto326[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+68,296,20,GetWidgetStyle(2),_Context->msg_Auto326[_Context->language],strlen(_Context->msg_Auto326[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+68,296,20,vfh[2],16,0,_Context->msg_Auto326[_Context->language],strlen(_Context->msg_Auto326[_Context->language]),32);
		}
	visual_filzone(_Context->x_Auto322+8,_Context->y_Auto322+92,328,4,26,18);
	_Context->trigger_Auto328=visual_trigger_code(_Context->msg_Auto328[_Context->language],strlen(_Context->msg_Auto328[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+104,296,20,GetWidgetStyle(2),_Context->msg_Auto328[_Context->language],strlen(_Context->msg_Auto328[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+104,296,20,vfh[2],16,0,_Context->msg_Auto328[_Context->language],strlen(_Context->msg_Auto328[_Context->language]),32);
		}
	_Context->trigger_Auto329=visual_trigger_code(_Context->msg_Auto329[_Context->language],strlen(_Context->msg_Auto329[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+124,296,20,GetWidgetStyle(2),_Context->msg_Auto329[_Context->language],strlen(_Context->msg_Auto329[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+124,296,20,vfh[2],16,0,_Context->msg_Auto329[_Context->language],strlen(_Context->msg_Auto329[_Context->language]),32);
		}
	_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+144,296,20,GetWidgetStyle(2),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+144,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),32);
		}
	_Context->trigger_Auto330=visual_trigger_code(_Context->msg_Auto330[_Context->language],strlen(_Context->msg_Auto330[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+164,296,20,GetWidgetStyle(2),_Context->msg_Auto330[_Context->language],strlen(_Context->msg_Auto330[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+164,296,20,vfh[2],16,0,_Context->msg_Auto330[_Context->language],strlen(_Context->msg_Auto330[_Context->language]),32);
		}
	_Context->trigger_Auto331=visual_trigger_code(_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+184,296,20,GetWidgetStyle(2),_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+184,296,20,vfh[2],16,0,_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]),32);
		}
	_Context->trigger_Auto332=visual_trigger_code(_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+204,296,20,GetWidgetStyle(2),_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+204,296,20,vfh[2],16,0,_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]),32);
		}
	visual_filzone(_Context->x_Auto322+8,_Context->y_Auto322+228,328,4,26,18);
	_Context->trigger_Auto334=visual_trigger_code(_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+320,328,20,GetWidgetStyle(2),_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+320,328,20,vfh[2],16,0,_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]),32);
		}
	_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+240,296,20,GetWidgetStyle(2),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+240,296,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),32);
		}
	_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+260,296,20,GetWidgetStyle(2),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+260,296,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),32);
		}
	_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+280,296,20,GetWidgetStyle(2),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+280,296,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),32);
		}
	_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+300,296,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+300,296,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
		}
	visual_thaw(_Context->x_Auto322,_Context->y_Auto322,344,356);

	return(0);
}
private int on_Auto323_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_INFO);
	return(-1);
}
private int on_Auto324_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_RESET);
	return(-1);
}
private int on_Auto325_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_BEST);
	return(-1);
}
private int on_Auto326_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_SCREEN);
	return(-1);
}
private int on_Auto328_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_TRACE);
	return(-1);
}
private int on_Auto329_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_HELP);
	return(-1);
}
private int on_previous_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_HYPER);
	return(-1);
}
private int on_Auto330_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_INHIBIT);
	return(-1);
}
private int on_Auto331_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_DETAIL);
	return(-1);
}
private int on_Auto332_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_MODE);
	return(-1);
}
private int on_Auto334_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_DOMAIN);
	return(-1);
}
private int on_Auto335_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_IMAGE);
	return(-1);
}
private int on_Auto336_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_EXPORT);
	return(-1);
}
private int on_Auto337_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_IMPORT);
	return(-1);
}
private int on_Auto338_event(struct dependance_main_menu_context * _Context) {
	return(_FLOW_NEW);
	return(-1);
}


public	int	dependance_main_menu_event(
struct dependance_main_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto323 == mb ) return(1);
		if (_Context->trigger_Auto324 == mb ) return(2);
		if (_Context->trigger_Auto325 == mb ) return(3);
		if (_Context->trigger_Auto326 == mb ) return(4);
		if (_Context->trigger_Auto328 == mb ) return(5);
		if (_Context->trigger_Auto329 == mb ) return(6);
		if (_Context->trigger_previous == mb ) return(7);
		if (_Context->trigger_Auto330 == mb ) return(8);
		if (_Context->trigger_Auto331 == mb ) return(9);
		if (_Context->trigger_Auto332 == mb ) return(10);
		if (_Context->trigger_Auto334 == mb ) return(11);
		if (_Context->trigger_Auto335 == mb ) return(12);
		if (_Context->trigger_Auto336 == mb ) return(13);
		if (_Context->trigger_Auto337 == mb ) return(14);
		if (_Context->trigger_Auto338 == mb ) return(15);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_Auto322+8) ) 
	&&  ( my >= (_Context->y_Auto322+8) ) 
	&&  ( mx <= (_Context->x_Auto322+8+296) ) 
	&&  ( my <= (_Context->y_Auto322+8+20))) {
		return(1); /* Auto323 */
		}
	if (( mx >= (_Context->x_Auto322+8) ) 
	&&  ( my >= (_Context->y_Auto322+28) ) 
	&&  ( mx <= (_Context->x_Auto322+8+296) ) 
	&&  ( my <= (_Context->y_Auto322+28+20))) {
		return(2); /* Auto324 */
		}
	if (( mx >= (_Context->x_Auto322+8) ) 
	&&  ( my >= (_Context->y_Auto322+48) ) 
	&&  ( mx <= (_Context->x_Auto322+8+296) ) 
	&&  ( my <= (_Context->y_Auto322+48+20))) {
		return(3); /* Auto325 */
		}
	if (( mx >= (_Context->x_Auto322+8) ) 
	&&  ( my >= (_Context->y_Auto322+68) ) 
	&&  ( mx <= (_Context->x_Auto322+8+296) ) 
	&&  ( my <= (_Context->y_Auto322+68+20))) {
		return(4); /* Auto326 */
		}
	if (( mx >= (_Context->x_Auto322+8) ) 
	&&  ( my >= (_Context->y_Auto322+104) ) 
	&&  ( mx <= (_Context->x_Auto322+8+296) ) 
	&&  ( my <= (_Context->y_Auto322+104+20))) {
		return(5); /* Auto328 */
		}
	if (( mx >= (_Context->x_Auto322+8) ) 
	&&  ( my >= (_Context->y_Auto322+124) ) 
	&&  ( mx <= (_Context->x_Auto322+8+296) ) 
	&&  ( my <= (_Context->y_Auto322+124+20))) {
		return(6); /* Auto329 */
		}
	if (( mx >= (_Context->x_Auto322+8) ) 
	&&  ( my >= (_Context->y_Auto322+144) ) 
	&&  ( mx <= (_Context->x_Auto322+8+296) ) 
	&&  ( my <= (_Context->y_Auto322+144+20))) {
		return(7); /* previous */
		}
	if (( mx >= (_Context->x_Auto322+8) ) 
	&&  ( my >= (_Context->y_Auto322+164) ) 
	&&  ( mx <= (_Context->x_Auto322+8+296) ) 
	&&  ( my <= (_Context->y_Auto322+164+20))) {
		return(8); /* Auto330 */
		}
	if (( mx >= (_Context->x_Auto322+8) ) 
	&&  ( my >= (_Context->y_Auto322+184) ) 
	&&  ( mx <= (_Context->x_Auto322+8+296) ) 
	&&  ( my <= (_Context->y_Auto322+184+20))) {
		return(9); /* Auto331 */
		}
	if (( mx >= (_Context->x_Auto322+8) ) 
	&&  ( my >= (_Context->y_Auto322+204) ) 
	&&  ( mx <= (_Context->x_Auto322+8+296) ) 
	&&  ( my <= (_Context->y_Auto322+204+20))) {
		return(10); /* Auto332 */
		}
	if (( mx >= (_Context->x_Auto322+8) ) 
	&&  ( my >= (_Context->y_Auto322+320) ) 
	&&  ( mx <= (_Context->x_Auto322+8+328) ) 
	&&  ( my <= (_Context->y_Auto322+320+20))) {
		return(11); /* Auto334 */
		}
	if (( mx >= (_Context->x_Auto322+8) ) 
	&&  ( my >= (_Context->y_Auto322+240) ) 
	&&  ( mx <= (_Context->x_Auto322+8+296) ) 
	&&  ( my <= (_Context->y_Auto322+240+20))) {
		return(12); /* Auto335 */
		}
	if (( mx >= (_Context->x_Auto322+8) ) 
	&&  ( my >= (_Context->y_Auto322+260) ) 
	&&  ( mx <= (_Context->x_Auto322+8+296) ) 
	&&  ( my <= (_Context->y_Auto322+260+20))) {
		return(13); /* Auto336 */
		}
	if (( mx >= (_Context->x_Auto322+8) ) 
	&&  ( my >= (_Context->y_Auto322+280) ) 
	&&  ( mx <= (_Context->x_Auto322+8+296) ) 
	&&  ( my <= (_Context->y_Auto322+280+20))) {
		return(14); /* Auto337 */
		}
	if (( mx >= (_Context->x_Auto322+8) ) 
	&&  ( my >= (_Context->y_Auto322+300) ) 
	&&  ( mx <= (_Context->x_Auto322+8+296) ) 
	&&  ( my <= (_Context->y_Auto322+300+20))) {
		return(15); /* Auto338 */
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
				/* Auto323 */
				_Context->trigger_Auto323=visual_trigger_code(_Context->msg_Auto323[_Context->language],strlen(_Context->msg_Auto323[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+8,296,20,GetWidgetStyle(3),_Context->msg_Auto323[_Context->language],strlen(_Context->msg_Auto323[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto322+8,_Context->y_Auto322+8,296,20,vfh[2],16,0,_Context->msg_Auto323[_Context->language],strlen(_Context->msg_Auto323[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto323=visual_trigger_code(_Context->msg_Auto323[_Context->language],strlen(_Context->msg_Auto323[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+8,296,20,GetWidgetStyle(2),_Context->msg_Auto323[_Context->language],strlen(_Context->msg_Auto323[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+8,296,20,vfh[2],16,0,_Context->msg_Auto323[_Context->language],strlen(_Context->msg_Auto323[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto324 */
				_Context->trigger_Auto324=visual_trigger_code(_Context->msg_Auto324[_Context->language],strlen(_Context->msg_Auto324[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+28,296,20,GetWidgetStyle(3),_Context->msg_Auto324[_Context->language],strlen(_Context->msg_Auto324[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto322+8,_Context->y_Auto322+28,296,20,vfh[2],16,0,_Context->msg_Auto324[_Context->language],strlen(_Context->msg_Auto324[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto324=visual_trigger_code(_Context->msg_Auto324[_Context->language],strlen(_Context->msg_Auto324[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+28,296,20,GetWidgetStyle(2),_Context->msg_Auto324[_Context->language],strlen(_Context->msg_Auto324[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+28,296,20,vfh[2],16,0,_Context->msg_Auto324[_Context->language],strlen(_Context->msg_Auto324[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto325 */
				_Context->trigger_Auto325=visual_trigger_code(_Context->msg_Auto325[_Context->language],strlen(_Context->msg_Auto325[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+48,296,20,GetWidgetStyle(3),_Context->msg_Auto325[_Context->language],strlen(_Context->msg_Auto325[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto322+8,_Context->y_Auto322+48,296,20,vfh[2],16,0,_Context->msg_Auto325[_Context->language],strlen(_Context->msg_Auto325[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto325=visual_trigger_code(_Context->msg_Auto325[_Context->language],strlen(_Context->msg_Auto325[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+48,296,20,GetWidgetStyle(2),_Context->msg_Auto325[_Context->language],strlen(_Context->msg_Auto325[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+48,296,20,vfh[2],16,0,_Context->msg_Auto325[_Context->language],strlen(_Context->msg_Auto325[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto326 */
				_Context->trigger_Auto326=visual_trigger_code(_Context->msg_Auto326[_Context->language],strlen(_Context->msg_Auto326[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+68,296,20,GetWidgetStyle(3),_Context->msg_Auto326[_Context->language],strlen(_Context->msg_Auto326[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto322+8,_Context->y_Auto322+68,296,20,vfh[2],16,0,_Context->msg_Auto326[_Context->language],strlen(_Context->msg_Auto326[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto326=visual_trigger_code(_Context->msg_Auto326[_Context->language],strlen(_Context->msg_Auto326[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+68,296,20,GetWidgetStyle(2),_Context->msg_Auto326[_Context->language],strlen(_Context->msg_Auto326[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+68,296,20,vfh[2],16,0,_Context->msg_Auto326[_Context->language],strlen(_Context->msg_Auto326[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto328 */
				_Context->trigger_Auto328=visual_trigger_code(_Context->msg_Auto328[_Context->language],strlen(_Context->msg_Auto328[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+104,296,20,GetWidgetStyle(3),_Context->msg_Auto328[_Context->language],strlen(_Context->msg_Auto328[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto322+8,_Context->y_Auto322+104,296,20,vfh[2],16,0,_Context->msg_Auto328[_Context->language],strlen(_Context->msg_Auto328[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto328=visual_trigger_code(_Context->msg_Auto328[_Context->language],strlen(_Context->msg_Auto328[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+104,296,20,GetWidgetStyle(2),_Context->msg_Auto328[_Context->language],strlen(_Context->msg_Auto328[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+104,296,20,vfh[2],16,0,_Context->msg_Auto328[_Context->language],strlen(_Context->msg_Auto328[_Context->language]),32);
				}
				break;
			case	0x6 :
				/* Auto329 */
				_Context->trigger_Auto329=visual_trigger_code(_Context->msg_Auto329[_Context->language],strlen(_Context->msg_Auto329[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+124,296,20,GetWidgetStyle(3),_Context->msg_Auto329[_Context->language],strlen(_Context->msg_Auto329[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto322+8,_Context->y_Auto322+124,296,20,vfh[2],16,0,_Context->msg_Auto329[_Context->language],strlen(_Context->msg_Auto329[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto329=visual_trigger_code(_Context->msg_Auto329[_Context->language],strlen(_Context->msg_Auto329[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+124,296,20,GetWidgetStyle(2),_Context->msg_Auto329[_Context->language],strlen(_Context->msg_Auto329[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+124,296,20,vfh[2],16,0,_Context->msg_Auto329[_Context->language],strlen(_Context->msg_Auto329[_Context->language]),32);
				}
				break;
			case	0x7 :
				/* previous */
				_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+144,296,20,GetWidgetStyle(3),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto322+8,_Context->y_Auto322+144,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+144,296,20,GetWidgetStyle(2),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+144,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),32);
				}
				break;
			case	0x8 :
				/* Auto330 */
				_Context->trigger_Auto330=visual_trigger_code(_Context->msg_Auto330[_Context->language],strlen(_Context->msg_Auto330[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+164,296,20,GetWidgetStyle(3),_Context->msg_Auto330[_Context->language],strlen(_Context->msg_Auto330[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto322+8,_Context->y_Auto322+164,296,20,vfh[2],16,0,_Context->msg_Auto330[_Context->language],strlen(_Context->msg_Auto330[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto330=visual_trigger_code(_Context->msg_Auto330[_Context->language],strlen(_Context->msg_Auto330[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+164,296,20,GetWidgetStyle(2),_Context->msg_Auto330[_Context->language],strlen(_Context->msg_Auto330[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+164,296,20,vfh[2],16,0,_Context->msg_Auto330[_Context->language],strlen(_Context->msg_Auto330[_Context->language]),32);
				}
				break;
			case	0x9 :
				/* Auto331 */
				_Context->trigger_Auto331=visual_trigger_code(_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+184,296,20,GetWidgetStyle(3),_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto322+8,_Context->y_Auto322+184,296,20,vfh[2],16,0,_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto331=visual_trigger_code(_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+184,296,20,GetWidgetStyle(2),_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+184,296,20,vfh[2],16,0,_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]),32);
				}
				break;
			case	0xa :
				/* Auto332 */
				_Context->trigger_Auto332=visual_trigger_code(_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+204,296,20,GetWidgetStyle(3),_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto322+8,_Context->y_Auto322+204,296,20,vfh[2],16,0,_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto332=visual_trigger_code(_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+204,296,20,GetWidgetStyle(2),_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+204,296,20,vfh[2],16,0,_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]),32);
				}
				break;
			case	0xb :
				/* Auto334 */
				_Context->trigger_Auto334=visual_trigger_code(_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+320,328,20,GetWidgetStyle(3),_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto322+8,_Context->y_Auto322+320,328,20,vfh[2],16,0,_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto334=visual_trigger_code(_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+320,328,20,GetWidgetStyle(2),_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+320,328,20,vfh[2],16,0,_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]),32);
				}
				break;
			case	0xc :
				/* Auto335 */
				_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+240,296,20,GetWidgetStyle(3),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto322+8,_Context->y_Auto322+240,296,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+240,296,20,GetWidgetStyle(2),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+240,296,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),32);
				}
				break;
			case	0xd :
				/* Auto336 */
				_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+260,296,20,GetWidgetStyle(3),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto322+8,_Context->y_Auto322+260,296,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+260,296,20,GetWidgetStyle(2),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+260,296,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),32);
				}
				break;
			case	0xe :
				/* Auto337 */
				_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+280,296,20,GetWidgetStyle(3),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto322+8,_Context->y_Auto322+280,296,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+280,296,20,GetWidgetStyle(2),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+280,296,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),32);
				}
				break;
			case	0xf :
				/* Auto338 */
				_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+300,296,20,GetWidgetStyle(3),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto322+8,_Context->y_Auto322+300,296,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+300,296,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+300,296,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
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
			_Context->focus_item=15;
			dependance_main_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  _Context->x_Auto322 )
				|| ( visual_event(6) < _Context->y_Auto322  )
				|| ( visual_event(7) > (_Context->x_Auto322+_Context->w_Auto322))
				|| ( visual_event(6) >  (_Context->y_Auto322+_Context->h_Auto322))) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=dependance_main_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto323 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto323=visual_trigger_code(_Context->msg_Auto323[_Context->language],strlen(_Context->msg_Auto323[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+8,296,20,GetWidgetStyle(3),_Context->msg_Auto323[_Context->language],strlen(_Context->msg_Auto323[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto322+8,_Context->y_Auto322+8,296,20,vfh[2],16,0,_Context->msg_Auto323[_Context->language],strlen(_Context->msg_Auto323[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto323=visual_trigger_code(_Context->msg_Auto323[_Context->language],strlen(_Context->msg_Auto323[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+8,296,20,GetWidgetStyle(2),_Context->msg_Auto323[_Context->language],strlen(_Context->msg_Auto323[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+8,296,20,vfh[2],16,0,_Context->msg_Auto323[_Context->language],strlen(_Context->msg_Auto323[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto323_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto324 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto324=visual_trigger_code(_Context->msg_Auto324[_Context->language],strlen(_Context->msg_Auto324[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+28,296,20,GetWidgetStyle(3),_Context->msg_Auto324[_Context->language],strlen(_Context->msg_Auto324[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto322+8,_Context->y_Auto322+28,296,20,vfh[2],16,0,_Context->msg_Auto324[_Context->language],strlen(_Context->msg_Auto324[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto324=visual_trigger_code(_Context->msg_Auto324[_Context->language],strlen(_Context->msg_Auto324[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+28,296,20,GetWidgetStyle(2),_Context->msg_Auto324[_Context->language],strlen(_Context->msg_Auto324[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+28,296,20,vfh[2],16,0,_Context->msg_Auto324[_Context->language],strlen(_Context->msg_Auto324[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto324_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto325 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto325=visual_trigger_code(_Context->msg_Auto325[_Context->language],strlen(_Context->msg_Auto325[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+48,296,20,GetWidgetStyle(3),_Context->msg_Auto325[_Context->language],strlen(_Context->msg_Auto325[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto322+8,_Context->y_Auto322+48,296,20,vfh[2],16,0,_Context->msg_Auto325[_Context->language],strlen(_Context->msg_Auto325[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto325=visual_trigger_code(_Context->msg_Auto325[_Context->language],strlen(_Context->msg_Auto325[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+48,296,20,GetWidgetStyle(2),_Context->msg_Auto325[_Context->language],strlen(_Context->msg_Auto325[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+48,296,20,vfh[2],16,0,_Context->msg_Auto325[_Context->language],strlen(_Context->msg_Auto325[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto325_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto326 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto326=visual_trigger_code(_Context->msg_Auto326[_Context->language],strlen(_Context->msg_Auto326[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+68,296,20,GetWidgetStyle(3),_Context->msg_Auto326[_Context->language],strlen(_Context->msg_Auto326[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto322+8,_Context->y_Auto322+68,296,20,vfh[2],16,0,_Context->msg_Auto326[_Context->language],strlen(_Context->msg_Auto326[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto326=visual_trigger_code(_Context->msg_Auto326[_Context->language],strlen(_Context->msg_Auto326[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+68,296,20,GetWidgetStyle(2),_Context->msg_Auto326[_Context->language],strlen(_Context->msg_Auto326[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+68,296,20,vfh[2],16,0,_Context->msg_Auto326[_Context->language],strlen(_Context->msg_Auto326[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto326_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto328 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto328=visual_trigger_code(_Context->msg_Auto328[_Context->language],strlen(_Context->msg_Auto328[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+104,296,20,GetWidgetStyle(3),_Context->msg_Auto328[_Context->language],strlen(_Context->msg_Auto328[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto322+8,_Context->y_Auto322+104,296,20,vfh[2],16,0,_Context->msg_Auto328[_Context->language],strlen(_Context->msg_Auto328[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto328=visual_trigger_code(_Context->msg_Auto328[_Context->language],strlen(_Context->msg_Auto328[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+104,296,20,GetWidgetStyle(2),_Context->msg_Auto328[_Context->language],strlen(_Context->msg_Auto328[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+104,296,20,vfh[2],16,0,_Context->msg_Auto328[_Context->language],strlen(_Context->msg_Auto328[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto328_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto329 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto329=visual_trigger_code(_Context->msg_Auto329[_Context->language],strlen(_Context->msg_Auto329[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+124,296,20,GetWidgetStyle(3),_Context->msg_Auto329[_Context->language],strlen(_Context->msg_Auto329[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto322+8,_Context->y_Auto322+124,296,20,vfh[2],16,0,_Context->msg_Auto329[_Context->language],strlen(_Context->msg_Auto329[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto329=visual_trigger_code(_Context->msg_Auto329[_Context->language],strlen(_Context->msg_Auto329[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+124,296,20,GetWidgetStyle(2),_Context->msg_Auto329[_Context->language],strlen(_Context->msg_Auto329[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+124,296,20,vfh[2],16,0,_Context->msg_Auto329[_Context->language],strlen(_Context->msg_Auto329[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto329_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* previous */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+144,296,20,GetWidgetStyle(3),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto322+8,_Context->y_Auto322+144,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+144,296,20,GetWidgetStyle(2),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+144,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_previous_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Auto330 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto330=visual_trigger_code(_Context->msg_Auto330[_Context->language],strlen(_Context->msg_Auto330[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+164,296,20,GetWidgetStyle(3),_Context->msg_Auto330[_Context->language],strlen(_Context->msg_Auto330[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto322+8,_Context->y_Auto322+164,296,20,vfh[2],16,0,_Context->msg_Auto330[_Context->language],strlen(_Context->msg_Auto330[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto330=visual_trigger_code(_Context->msg_Auto330[_Context->language],strlen(_Context->msg_Auto330[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+164,296,20,GetWidgetStyle(2),_Context->msg_Auto330[_Context->language],strlen(_Context->msg_Auto330[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+164,296,20,vfh[2],16,0,_Context->msg_Auto330[_Context->language],strlen(_Context->msg_Auto330[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto330_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Auto331 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto331=visual_trigger_code(_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+184,296,20,GetWidgetStyle(3),_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto322+8,_Context->y_Auto322+184,296,20,vfh[2],16,0,_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto331=visual_trigger_code(_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+184,296,20,GetWidgetStyle(2),_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+184,296,20,vfh[2],16,0,_Context->msg_Auto331[_Context->language],strlen(_Context->msg_Auto331[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto331_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Auto332 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto332=visual_trigger_code(_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+204,296,20,GetWidgetStyle(3),_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto322+8,_Context->y_Auto322+204,296,20,vfh[2],16,0,_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto332=visual_trigger_code(_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+204,296,20,GetWidgetStyle(2),_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+204,296,20,vfh[2],16,0,_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto332_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Auto334 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto334=visual_trigger_code(_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+320,328,20,GetWidgetStyle(3),_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto322+8,_Context->y_Auto322+320,328,20,vfh[2],16,0,_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto334=visual_trigger_code(_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+320,328,20,GetWidgetStyle(2),_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+320,328,20,vfh[2],16,0,_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto334_event(_Context)) != -1) break;

						}
					continue;
				case	0xc :
					/* Auto335 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+240,296,20,GetWidgetStyle(3),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto322+8,_Context->y_Auto322+240,296,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+240,296,20,GetWidgetStyle(2),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+240,296,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto335_event(_Context)) != -1) break;

						}
					continue;
				case	0xd :
					/* Auto336 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+260,296,20,GetWidgetStyle(3),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto322+8,_Context->y_Auto322+260,296,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+260,296,20,GetWidgetStyle(2),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+260,296,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto336_event(_Context)) != -1) break;

						}
					continue;
				case	0xe :
					/* Auto337 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+280,296,20,GetWidgetStyle(3),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto322+8,_Context->y_Auto322+280,296,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+280,296,20,GetWidgetStyle(2),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+280,296,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto337_event(_Context)) != -1) break;

						}
					continue;
				case	0xf :
					/* Auto338 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+300,296,20,GetWidgetStyle(3),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto322+8,_Context->y_Auto322+300,296,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto322+8,_Context->y_Auto322+300,296,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto322+8,_Context->y_Auto322+300,296,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto338_event(_Context)) != -1) break;

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
				_Context->focus_item=15;
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

#endif /* _vdepmenu_c */
