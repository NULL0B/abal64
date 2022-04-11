
#ifndef _flowmenu_c
#define _flowmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : flowmenu.xml                                             */
/* Target         : flowmenu.c                                               */
/* Identification : 0.0-1197471957-4032.4031                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#include "singfmed.h"
#define en_Auto337   "Sing Version 2.1a"
#define fr_Auto337   "Sing Version 2.1a"
#define it_Auto337   "Sing Version 2.1a"
#define es_Auto337   "Sing Version 2.1a"
#define de_Auto337   "Sing Version 2.1a"
#define nl_Auto337   "Sing Version 2.1a"
#define pt_Auto337   "Sing Version 2.1a"
#define xx_Auto337   "Sing Version 2.1a"
#define en__Auto337   ""
#define fr__Auto337   ""
#define it__Auto337   ""
#define es__Auto337   ""
#define de__Auto337   ""
#define nl__Auto337   ""
#define pt__Auto337   ""
#define xx__Auto337   ""
#define en_Auto338   "&Model Editor Properties and Options"
#define fr_Auto338   "&PropriŠt‚s et options de l'‚diteur de ModŠle"
#define it_Auto338   "&Model Editor Properties and Options"
#define es_Auto338   "&Model Editor Properties and Options"
#define de_Auto338   "&Model Editor Properties and Options"
#define nl_Auto338   "&Model Editor Properties and Options"
#define pt_Auto338   "&Model Editor Properties and Options"
#define xx_Auto338   "&Model Editor Properties and Options"
#define en__Auto338   ""
#define fr__Auto338   ""
#define it__Auto338   ""
#define es__Auto338   ""
#define de__Auto338   ""
#define nl__Auto338   ""
#define pt__Auto338   ""
#define xx__Auto338   ""
#define en_Auto339   "&Reset and Recalculate Flowchart Display"
#define fr_Auto339   "&Recalculer l'affichage du diagramme de flux"
#define it_Auto339   "&Reset and Recalculate Flowchart Display"
#define es_Auto339   "&Reset and Recalculate Flowchart Display"
#define de_Auto339   "&Reset and Recalculate Flowchart Display"
#define nl_Auto339   "&Reset and Recalculate Flowchart Display"
#define pt_Auto339   "&Reset and Recalculate Flowchart Display"
#define xx_Auto339   "&Reset and Recalculate Flowchart Display"
#define en__Auto339   ""
#define fr__Auto339   ""
#define it__Auto339   ""
#define es__Auto339   ""
#define de__Auto339   ""
#define nl__Auto339   ""
#define pt__Auto339   ""
#define xx__Auto339   ""
#define en_Auto340   "&Calculate Best Positioning"
#define fr_Auto340   "R&ecalculer positionnement optimale"
#define it_Auto340   "&Calculate Best Positioning"
#define es_Auto340   "&Calculate Best Positioning"
#define de_Auto340   "&Calculate Best Positioning"
#define nl_Auto340   "&Calculate Best Positioning"
#define pt_Auto340   "&Calculate Best Positioning"
#define xx_Auto340   "&Calculate Best Positioning"
#define en__Auto340   ""
#define fr__Auto340   ""
#define it__Auto340   ""
#define es__Auto340   ""
#define de__Auto340   ""
#define nl__Auto340   ""
#define pt__Auto340   ""
#define xx__Auto340   ""
#define en_Auto341   "R&efresh Screen Display"
#define fr_Auto341   "Re&affichage de l'‚cran"
#define it_Auto341   "R&efresh Screen Display"
#define es_Auto341   "R&efresh Screen Display"
#define de_Auto341   "R&efresh Screen Display"
#define nl_Auto341   "R&efresh Screen Display"
#define pt_Auto341   "R&efresh Screen Display"
#define xx_Auto341   "R&efresh Screen Display"
#define en__Auto341   ""
#define fr__Auto341   ""
#define it__Auto341   ""
#define es__Auto341   ""
#define de__Auto341   ""
#define nl__Auto341   ""
#define pt__Auto341   ""
#define xx__Auto341   ""
#define en_Auto343   "&Toggle Relation Tracing : Direct/Routed"
#define fr_Auto343   "&Bascule le type de routage"
#define it_Auto343   "&Toggle Relation Tracing : Direct/Routed"
#define es_Auto343   "&Toggle Relation Tracing : Direct/Routed"
#define de_Auto343   "&Toggle Relation Tracing : Direct/Routed"
#define nl_Auto343   "&Toggle Relation Tracing : Direct/Routed"
#define pt_Auto343   "&Toggle Relation Tracing : Direct/Routed"
#define xx_Auto343   "&Toggle Relation Tracing : Direct/Routed"
#define en__Auto343   ""
#define fr__Auto343   ""
#define it__Auto343   ""
#define es__Auto343   ""
#define de__Auto343   ""
#define nl__Auto343   ""
#define pt__Auto343   ""
#define xx__Auto343   ""
#define en_Auto344   "T&oggle display of Help Bubble messages"
#define fr_Auto344   "Ba&scule l‚tat des bulles d'aide"
#define it_Auto344   "T&oggle display of Help Bubble messages"
#define es_Auto344   "T&oggle display of Help Bubble messages"
#define de_Auto344   "T&oggle display of Help Bubble messages"
#define nl_Auto344   "T&oggle display of Help Bubble messages"
#define pt_Auto344   "T&oggle display of Help Bubble messages"
#define xx_Auto344   "T&oggle display of Help Bubble messages"
#define en__Auto344   ""
#define fr__Auto344   ""
#define it__Auto344   ""
#define es__Auto344   ""
#define de__Auto344   ""
#define nl__Auto344   ""
#define pt__Auto344   ""
#define xx__Auto344   ""
#define en_previous   "To&ggle Hyperspace Navigator"
#define fr_previous   "Bas&culer l'‚tat du visioneur d'hyper-espace"
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
#define en_Auto345   "Togg&le Flowchart Display : Project/All"
#define fr_Auto345   "Basc&uler l'affichage entre Project / Tout"
#define it_Auto345   "Togg&le Flowchart Display : Project/All"
#define es_Auto345   "Togg&le Flowchart Display : Project/All"
#define de_Auto345   "Togg&le Flowchart Display : Project/All"
#define nl_Auto345   "Togg&le Flowchart Display : Project/All"
#define pt_Auto345   "Togg&le Flowchart Display : Project/All"
#define xx_Auto345   "Togg&le Flowchart Display : Project/All"
#define en__Auto345   ""
#define fr__Auto345   ""
#define it__Auto345   ""
#define es__Auto345   ""
#define de__Auto345   ""
#define nl__Auto345   ""
#define pt__Auto345   ""
#define xx__Auto345   ""
#define en_Auto346   "Toggle &Flowchart Detail"
#define fr_Auto346   "Bascu&le l'affichage D‚tail"
#define it_Auto346   "Toggle &Flowchart Detail"
#define es_Auto346   "Toggle &Flowchart Detail"
#define de_Auto346   "Toggle &Flowchart Detail"
#define nl_Auto346   "Toggle &Flowchart Detail"
#define pt_Auto346   "Toggle &Flowchart Detail"
#define xx_Auto346   "Toggle &Flowchart Detail"
#define en__Auto346   ""
#define fr__Auto346   ""
#define it__Auto346   ""
#define es__Auto346   ""
#define de__Auto346   ""
#define nl__Auto346   ""
#define pt__Auto346   ""
#define xx__Auto346   ""
#define en_Auto347   "Toggle &Flowchart Images"
#define fr_Auto347   "Bascu&le l'affichage Image"
#define it_Auto347   "Toggle &Flowchart Images"
#define es_Auto347   "Toggle &Flowchart Images"
#define de_Auto347   "Toggle &Flowchart Images"
#define nl_Auto347   "Toggle &Flowchart Images"
#define pt_Auto347   "Toggle &Flowchart Images"
#define xx_Auto347   "Toggle &Flowchart Images"
#define en__Auto347   ""
#define fr__Auto347   ""
#define it__Auto347   ""
#define es__Auto347   ""
#define de__Auto347   ""
#define nl__Auto347   ""
#define pt__Auto347   ""
#define xx__Auto347   ""
#define en_Auto349   "&Save to Image File"
#define fr_Auto349   "Sau&ver un fichier d'image"
#define it_Auto349   "&Save to Image File"
#define es_Auto349   "&Save to Image File"
#define de_Auto349   "&Save to Image File"
#define nl_Auto349   "&Save to Image File"
#define pt_Auto349   "&Save to Image File"
#define xx_Auto349   "&Save to Image File"
#define en__Auto349   ""
#define fr__Auto349   ""
#define it__Auto349   ""
#define es__Auto349   ""
#define de__Auto349   ""
#define nl__Auto349   ""
#define pt__Auto349   ""
#define xx__Auto349   ""
#define en_Auto350   "Set Glo&bal Forms Style"
#define fr_Auto350   "C&hanger le style global des formulaires"
#define it_Auto350   "Set Glo&bal Forms Style"
#define es_Auto350   "Set Glo&bal Forms Style"
#define de_Auto350   "Set Glo&bal Forms Style"
#define nl_Auto350   "Set Glo&bal Forms Style"
#define pt_Auto350   "Set Glo&bal Forms Style"
#define xx_Auto350   "Set Glo&bal Forms Style"
#define en__Auto350   ""
#define fr__Auto350   ""
#define it__Auto350   ""
#define es__Auto350   ""
#define de__Auto350   ""
#define nl__Auto350   ""
#define pt__Auto350   ""
#define xx__Auto350   ""

private struct flowchart_main_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto337[8];
	char * hint_Auto337[8];
	int	s_Auto337;
	void *	p_Auto337;
	int	x_Auto337;
	int	y_Auto337;
	int	w_Auto337;
	int	h_Auto337;
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
	char * hint_Auto342[8];
	char * msg_Auto343[8];
	int	trigger_Auto343;
	char * hint_Auto343[8];
	char * msg_Auto344[8];
	int	trigger_Auto344;
	char * hint_Auto344[8];
	char * msg_previous[8];
	int	trigger_previous;
	char * hint_previous[8];
	char * msg_Auto345[8];
	int	trigger_Auto345;
	char * hint_Auto345[8];
	char * msg_Auto346[8];
	int	trigger_Auto346;
	char * hint_Auto346[8];
	char * msg_Auto347[8];
	int	trigger_Auto347;
	char * hint_Auto347[8];
	char * hint_Auto348[8];
	char * msg_Auto349[8];
	int	trigger_Auto349;
	char * hint_Auto349[8];
	char * msg_Auto350[8];
	int	trigger_Auto350;
	char * hint_Auto350[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct flowchart_main_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = flowchart_main_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}

private int on_Auto337_create(struct flowchart_main_menu_context * _Context) {
	mouse_move_on();
	if(((_Context->y_Auto337=visual_event(6))+304)>hardrows())
	_Context->y_Auto337=(hardrows()-304);
	if(((_Context->x_Auto337=visual_event(7))+328)>hardcolumns())
	_Context->x_Auto337=(hardcolumns()-328);
	return(-1);
}

public	int	flowchart_main_menu_create(struct flowchart_main_menu_context **cptr)
{

	int i;
	struct flowchart_main_menu_context * _Context=(struct flowchart_main_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct flowchart_main_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=12;
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
	_Context->s_Auto337=0;
	_Context->p_Auto337=visual_buffer(_Context->x_Auto337,_Context->y_Auto337,328+2,304+2);
	_Context->x_Auto337=32;
	_Context->y_Auto337=52;
	_Context->w_Auto337=328;
	_Context->h_Auto337=304;
	_Context->window_col=32;
	_Context->window_row=52;
	(void) on_Auto337_create(_Context);
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
	for (i=0; i < 8; i++)_Context->msg_Auto346[i]=" ";
	_Context->msg_Auto346[0]=en_Auto346;
	_Context->msg_Auto346[1]=fr_Auto346;
	_Context->msg_Auto346[2]=it_Auto346;
	_Context->msg_Auto346[3]=es_Auto346;
	_Context->msg_Auto346[4]=de_Auto346;
	_Context->msg_Auto346[5]=nl_Auto346;
	_Context->msg_Auto346[6]=pt_Auto346;
	_Context->msg_Auto346[7]=xx_Auto346;
	_Context->hint_Auto346[0]=en__Auto346;
	_Context->hint_Auto346[1]=fr__Auto346;
	_Context->hint_Auto346[2]=it__Auto346;
	_Context->hint_Auto346[3]=es__Auto346;
	_Context->hint_Auto346[4]=de__Auto346;
	_Context->hint_Auto346[5]=nl__Auto346;
	_Context->hint_Auto346[6]=pt__Auto346;
	_Context->hint_Auto346[7]=xx__Auto346;
	for (i=0; i < 8; i++)_Context->msg_Auto347[i]=" ";
	_Context->msg_Auto347[0]=en_Auto347;
	_Context->msg_Auto347[1]=fr_Auto347;
	_Context->msg_Auto347[2]=it_Auto347;
	_Context->msg_Auto347[3]=es_Auto347;
	_Context->msg_Auto347[4]=de_Auto347;
	_Context->msg_Auto347[5]=nl_Auto347;
	_Context->msg_Auto347[6]=pt_Auto347;
	_Context->msg_Auto347[7]=xx_Auto347;
	_Context->hint_Auto347[0]=en__Auto347;
	_Context->hint_Auto347[1]=fr__Auto347;
	_Context->hint_Auto347[2]=it__Auto347;
	_Context->hint_Auto347[3]=es__Auto347;
	_Context->hint_Auto347[4]=de__Auto347;
	_Context->hint_Auto347[5]=nl__Auto347;
	_Context->hint_Auto347[6]=pt__Auto347;
	_Context->hint_Auto347[7]=xx__Auto347;
	for (i=0; i < 8; i++)_Context->msg_Auto349[i]=" ";
	_Context->msg_Auto349[0]=en_Auto349;
	_Context->msg_Auto349[1]=fr_Auto349;
	_Context->msg_Auto349[2]=it_Auto349;
	_Context->msg_Auto349[3]=es_Auto349;
	_Context->msg_Auto349[4]=de_Auto349;
	_Context->msg_Auto349[5]=nl_Auto349;
	_Context->msg_Auto349[6]=pt_Auto349;
	_Context->msg_Auto349[7]=xx_Auto349;
	_Context->hint_Auto349[0]=en__Auto349;
	_Context->hint_Auto349[1]=fr__Auto349;
	_Context->hint_Auto349[2]=it__Auto349;
	_Context->hint_Auto349[3]=es__Auto349;
	_Context->hint_Auto349[4]=de__Auto349;
	_Context->hint_Auto349[5]=nl__Auto349;
	_Context->hint_Auto349[6]=pt__Auto349;
	_Context->hint_Auto349[7]=xx__Auto349;
	for (i=0; i < 8; i++)_Context->msg_Auto350[i]=" ";
	_Context->msg_Auto350[0]=en_Auto350;
	_Context->msg_Auto350[1]=fr_Auto350;
	_Context->msg_Auto350[2]=it_Auto350;
	_Context->msg_Auto350[3]=es_Auto350;
	_Context->msg_Auto350[4]=de_Auto350;
	_Context->msg_Auto350[5]=nl_Auto350;
	_Context->msg_Auto350[6]=pt_Auto350;
	_Context->msg_Auto350[7]=xx_Auto350;
	_Context->hint_Auto350[0]=en__Auto350;
	_Context->hint_Auto350[1]=fr__Auto350;
	_Context->hint_Auto350[2]=it__Auto350;
	_Context->hint_Auto350[3]=es__Auto350;
	_Context->hint_Auto350[4]=de__Auto350;
	_Context->hint_Auto350[5]=nl__Auto350;
	_Context->hint_Auto350[6]=pt__Auto350;
	_Context->hint_Auto350[7]=xx__Auto350;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto337,_Context->y_Auto337,328,304);
	return(0);
}

public 	int	flowchart_main_menu_hide(struct flowchart_main_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto337 != (void *) 0)
	&& (_Context->s_Auto337 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto337,_Context->x_Auto337,_Context->y_Auto337);
		_Context->s_Auto337=0;
		}
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto337,_Context->y_Auto337);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	flowchart_main_menu_remove(struct flowchart_main_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	mouse_move_off();
	if (_Context->p_Auto337 != (void *) 0)
		_Context->p_Auto337 = visual_drop(_Context->p_Auto337);
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	flowchart_main_menu_show(struct flowchart_main_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto337,_Context->y_Auto337);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if ((_Context->p_Auto337 != (void *) 0)
	&& (_Context->s_Auto337 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto337,_Context->x_Auto337,_Context->y_Auto337);
		_Context->s_Auto337=1;
		}
	if (((_Context->status = visual_styled_element(_Context->x_Auto337,_Context->y_Auto337,328,304,GetWidgetStyle(1),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
		visual_window(_Context->x_Auto337,_Context->y_Auto337,328,304,vfh[1],_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),0x4);
		}
	_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+12,312,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+12,312,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
		}
	_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+32,312,20,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+32,312,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
		}
	_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+52,296,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+52,296,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
		}
	_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+72,296,20,GetWidgetStyle(2),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+72,296,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),32);
		}
	visual_filzone(_Context->x_Auto337+8,_Context->y_Auto337+92,312,4,26,18);
	_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+104,296,20,GetWidgetStyle(2),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+104,296,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),32);
		}
	_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+124,296,20,GetWidgetStyle(2),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+124,296,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),32);
		}
	_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+148,296,20,GetWidgetStyle(2),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+148,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),32);
		}
	_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+168,296,20,GetWidgetStyle(2),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+168,296,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),32);
		}
	_Context->trigger_Auto346=visual_trigger_code(_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+192,296,20,GetWidgetStyle(2),_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+192,296,20,vfh[2],16,0,_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]),32);
		}
	_Context->trigger_Auto347=visual_trigger_code(_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+212,296,20,GetWidgetStyle(2),_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+212,296,20,vfh[2],16,0,_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]),32);
		}
	visual_filzone(_Context->x_Auto337+8,_Context->y_Auto337+236,312,4,26,18);
	_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+248,296,20,GetWidgetStyle(2),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+248,296,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),32);
		}
	_Context->trigger_Auto350=visual_trigger_code(_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+272,296,20,GetWidgetStyle(2),_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+272,296,20,vfh[2],16,0,_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]),32);
		}
	visual_thaw(_Context->x_Auto337,_Context->y_Auto337,328,304);

	return(0);
}
private int on_Auto338_event(struct flowchart_main_menu_context * _Context) {
	return(_FLOW_INFO);
	return(-1);
}
private int on_Auto339_event(struct flowchart_main_menu_context * _Context) {
	return(_FLOW_RESET);
	return(-1);
}
private int on_Auto340_event(struct flowchart_main_menu_context * _Context) {
	return(_FLOW_BEST);
	return(-1);
}
private int on_Auto341_event(struct flowchart_main_menu_context * _Context) {
	return(_FLOW_SCREEN);
	return(-1);
}
private int on_Auto343_event(struct flowchart_main_menu_context * _Context) {
	return(_FLOW_TRACE);
	return(-1);
}
private int on_Auto344_event(struct flowchart_main_menu_context * _Context) {
	return(_FLOW_HELP);
	return(-1);
}
private int on_previous_event(struct flowchart_main_menu_context * _Context) {
	return(_FLOW_HYPER);
	return(-1);
}
private int on_Auto345_event(struct flowchart_main_menu_context * _Context) {
	return(_FLOW_INHIBIT);
	return(-1);
}
private int on_Auto346_event(struct flowchart_main_menu_context * _Context) {
	return(_FLOW_DETAIL);
	return(-1);
}
private int on_Auto347_event(struct flowchart_main_menu_context * _Context) {
	return(_FLOW_SIGHT);
	return(-1);
}
private int on_Auto349_event(struct flowchart_main_menu_context * _Context) {
	return(_FLOW_IMAGE);
	return(-1);
}
private int on_Auto350_event(struct flowchart_main_menu_context * _Context) {
	return(_FLOW_STYLE);
	return(-1);
}


public	int	flowchart_main_menu_event(
struct flowchart_main_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto338 == mb ) return(1);
		if (_Context->trigger_Auto339 == mb ) return(2);
		if (_Context->trigger_Auto340 == mb ) return(3);
		if (_Context->trigger_Auto341 == mb ) return(4);
		if (_Context->trigger_Auto343 == mb ) return(5);
		if (_Context->trigger_Auto344 == mb ) return(6);
		if (_Context->trigger_previous == mb ) return(7);
		if (_Context->trigger_Auto345 == mb ) return(8);
		if (_Context->trigger_Auto346 == mb ) return(9);
		if (_Context->trigger_Auto347 == mb ) return(10);
		if (_Context->trigger_Auto349 == mb ) return(11);
		if (_Context->trigger_Auto350 == mb ) return(12);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_Auto337+8) ) 
	&&  ( my >= (_Context->y_Auto337+12) ) 
	&&  ( mx <= (_Context->x_Auto337+8+312) ) 
	&&  ( my <= (_Context->y_Auto337+12+20))) {
		return(1); /* Auto338 */
		}
	if (( mx >= (_Context->x_Auto337+8) ) 
	&&  ( my >= (_Context->y_Auto337+32) ) 
	&&  ( mx <= (_Context->x_Auto337+8+312) ) 
	&&  ( my <= (_Context->y_Auto337+32+20))) {
		return(2); /* Auto339 */
		}
	if (( mx >= (_Context->x_Auto337+8) ) 
	&&  ( my >= (_Context->y_Auto337+52) ) 
	&&  ( mx <= (_Context->x_Auto337+8+296) ) 
	&&  ( my <= (_Context->y_Auto337+52+20))) {
		return(3); /* Auto340 */
		}
	if (( mx >= (_Context->x_Auto337+8) ) 
	&&  ( my >= (_Context->y_Auto337+72) ) 
	&&  ( mx <= (_Context->x_Auto337+8+296) ) 
	&&  ( my <= (_Context->y_Auto337+72+20))) {
		return(4); /* Auto341 */
		}
	if (( mx >= (_Context->x_Auto337+8) ) 
	&&  ( my >= (_Context->y_Auto337+104) ) 
	&&  ( mx <= (_Context->x_Auto337+8+296) ) 
	&&  ( my <= (_Context->y_Auto337+104+20))) {
		return(5); /* Auto343 */
		}
	if (( mx >= (_Context->x_Auto337+8) ) 
	&&  ( my >= (_Context->y_Auto337+124) ) 
	&&  ( mx <= (_Context->x_Auto337+8+296) ) 
	&&  ( my <= (_Context->y_Auto337+124+20))) {
		return(6); /* Auto344 */
		}
	if (( mx >= (_Context->x_Auto337+8) ) 
	&&  ( my >= (_Context->y_Auto337+148) ) 
	&&  ( mx <= (_Context->x_Auto337+8+296) ) 
	&&  ( my <= (_Context->y_Auto337+148+20))) {
		return(7); /* previous */
		}
	if (( mx >= (_Context->x_Auto337+8) ) 
	&&  ( my >= (_Context->y_Auto337+168) ) 
	&&  ( mx <= (_Context->x_Auto337+8+296) ) 
	&&  ( my <= (_Context->y_Auto337+168+20))) {
		return(8); /* Auto345 */
		}
	if (( mx >= (_Context->x_Auto337+8) ) 
	&&  ( my >= (_Context->y_Auto337+192) ) 
	&&  ( mx <= (_Context->x_Auto337+8+296) ) 
	&&  ( my <= (_Context->y_Auto337+192+20))) {
		return(9); /* Auto346 */
		}
	if (( mx >= (_Context->x_Auto337+8) ) 
	&&  ( my >= (_Context->y_Auto337+212) ) 
	&&  ( mx <= (_Context->x_Auto337+8+296) ) 
	&&  ( my <= (_Context->y_Auto337+212+20))) {
		return(10); /* Auto347 */
		}
	if (( mx >= (_Context->x_Auto337+8) ) 
	&&  ( my >= (_Context->y_Auto337+248) ) 
	&&  ( mx <= (_Context->x_Auto337+8+296) ) 
	&&  ( my <= (_Context->y_Auto337+248+20))) {
		return(11); /* Auto349 */
		}
	if (( mx >= (_Context->x_Auto337+8) ) 
	&&  ( my >= (_Context->y_Auto337+272) ) 
	&&  ( mx <= (_Context->x_Auto337+8+296) ) 
	&&  ( my <= (_Context->y_Auto337+272+20))) {
		return(12); /* Auto350 */
		}

	return(-1);
}


public	int	flowchart_main_menu_focus(struct flowchart_main_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto338 */
				_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+12,312,20,GetWidgetStyle(3),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto337+8,_Context->y_Auto337+12,312,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+12,312,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+12,312,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto339 */
				_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+32,312,20,GetWidgetStyle(3),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto337+8,_Context->y_Auto337+32,312,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+32,312,20,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+32,312,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto340 */
				_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+52,296,20,GetWidgetStyle(3),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto337+8,_Context->y_Auto337+52,296,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+52,296,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+52,296,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto341 */
				_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+72,296,20,GetWidgetStyle(3),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto337+8,_Context->y_Auto337+72,296,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+72,296,20,GetWidgetStyle(2),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+72,296,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto343 */
				_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+104,296,20,GetWidgetStyle(3),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto337+8,_Context->y_Auto337+104,296,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+104,296,20,GetWidgetStyle(2),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+104,296,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),32);
				}
				break;
			case	0x6 :
				/* Auto344 */
				_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+124,296,20,GetWidgetStyle(3),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto337+8,_Context->y_Auto337+124,296,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+124,296,20,GetWidgetStyle(2),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+124,296,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),32);
				}
				break;
			case	0x7 :
				/* previous */
				_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+148,296,20,GetWidgetStyle(3),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto337+8,_Context->y_Auto337+148,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+148,296,20,GetWidgetStyle(2),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+148,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),32);
				}
				break;
			case	0x8 :
				/* Auto345 */
				_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+168,296,20,GetWidgetStyle(3),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto337+8,_Context->y_Auto337+168,296,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+168,296,20,GetWidgetStyle(2),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+168,296,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),32);
				}
				break;
			case	0x9 :
				/* Auto346 */
				_Context->trigger_Auto346=visual_trigger_code(_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+192,296,20,GetWidgetStyle(3),_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto337+8,_Context->y_Auto337+192,296,20,vfh[2],16,0,_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto346=visual_trigger_code(_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+192,296,20,GetWidgetStyle(2),_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+192,296,20,vfh[2],16,0,_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]),32);
				}
				break;
			case	0xa :
				/* Auto347 */
				_Context->trigger_Auto347=visual_trigger_code(_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+212,296,20,GetWidgetStyle(3),_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto337+8,_Context->y_Auto337+212,296,20,vfh[2],16,0,_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto347=visual_trigger_code(_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+212,296,20,GetWidgetStyle(2),_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+212,296,20,vfh[2],16,0,_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]),32);
				}
				break;
			case	0xb :
				/* Auto349 */
				_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+248,296,20,GetWidgetStyle(3),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto337+8,_Context->y_Auto337+248,296,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+248,296,20,GetWidgetStyle(2),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+248,296,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),32);
				}
				break;
			case	0xc :
				/* Auto350 */
				_Context->trigger_Auto350=visual_trigger_code(_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+272,296,20,GetWidgetStyle(3),_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto337+8,_Context->y_Auto337+272,296,20,vfh[2],16,0,_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto350=visual_trigger_code(_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+272,296,20,GetWidgetStyle(2),_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+272,296,20,vfh[2],16,0,_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			flowchart_main_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=12;
			flowchart_main_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  _Context->x_Auto337 )
				|| ( visual_event(6) < _Context->y_Auto337  )
				|| ( visual_event(7) > (_Context->x_Auto337+_Context->w_Auto337))
				|| ( visual_event(6) >  (_Context->y_Auto337+_Context->h_Auto337))) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=flowchart_main_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto338 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+12,312,20,GetWidgetStyle(3),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto337+8,_Context->y_Auto337+12,312,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+12,312,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+12,312,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto338_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto339 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+32,312,20,GetWidgetStyle(3),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto337+8,_Context->y_Auto337+32,312,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+32,312,20,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+32,312,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto339_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto340 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+52,296,20,GetWidgetStyle(3),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto337+8,_Context->y_Auto337+52,296,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+52,296,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+52,296,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto340_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto341 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+72,296,20,GetWidgetStyle(3),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto337+8,_Context->y_Auto337+72,296,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+72,296,20,GetWidgetStyle(2),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+72,296,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto341_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto343 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+104,296,20,GetWidgetStyle(3),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto337+8,_Context->y_Auto337+104,296,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+104,296,20,GetWidgetStyle(2),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+104,296,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto343_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto344 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+124,296,20,GetWidgetStyle(3),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto337+8,_Context->y_Auto337+124,296,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+124,296,20,GetWidgetStyle(2),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+124,296,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto344_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* previous */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+148,296,20,GetWidgetStyle(3),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto337+8,_Context->y_Auto337+148,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_previous=visual_trigger_code(_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+148,296,20,GetWidgetStyle(2),_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+148,296,20,vfh[2],16,0,_Context->msg_previous[_Context->language],strlen(_Context->msg_previous[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_previous_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Auto345 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+168,296,20,GetWidgetStyle(3),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto337+8,_Context->y_Auto337+168,296,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+168,296,20,GetWidgetStyle(2),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+168,296,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto345_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Auto346 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto346=visual_trigger_code(_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+192,296,20,GetWidgetStyle(3),_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto337+8,_Context->y_Auto337+192,296,20,vfh[2],16,0,_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto346=visual_trigger_code(_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+192,296,20,GetWidgetStyle(2),_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+192,296,20,vfh[2],16,0,_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto346_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Auto347 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto347=visual_trigger_code(_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+212,296,20,GetWidgetStyle(3),_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto337+8,_Context->y_Auto337+212,296,20,vfh[2],16,0,_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto347=visual_trigger_code(_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+212,296,20,GetWidgetStyle(2),_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+212,296,20,vfh[2],16,0,_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto347_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Auto349 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+248,296,20,GetWidgetStyle(3),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto337+8,_Context->y_Auto337+248,296,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+248,296,20,GetWidgetStyle(2),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+248,296,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto349_event(_Context)) != -1) break;

						}
					continue;
				case	0xc :
					/* Auto350 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto350=visual_trigger_code(_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+272,296,20,GetWidgetStyle(3),_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto337+8,_Context->y_Auto337+272,296,20,vfh[2],16,0,_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto350=visual_trigger_code(_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+8,_Context->y_Auto337+272,296,20,GetWidgetStyle(2),_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+8,_Context->y_Auto337+272,296,20,vfh[2],16,0,_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto350_event(_Context)) != -1) break;

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
				_Context->focus_item=12;
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

public	int	flowchart_main_menu()
{
	int	status=0;
	struct flowchart_main_menu_context * _Context=(struct flowchart_main_menu_context*) 0;
	status = flowchart_main_menu_create(&_Context);
	if ( status != 0) return(status);
	status = flowchart_main_menu_show(_Context);
		enter_modal();
	status = flowchart_main_menu_focus(_Context);
		leave_modal();
	status = flowchart_main_menu_hide(_Context);
	status = flowchart_main_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _flowmenu_c */
