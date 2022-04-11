
#ifndef _formmenu_c
#define _formmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : formmenu.xml                                             */
/* Target         : formmenu.c                                               */
/* Identification : 0.0-1196640078-26078.26077                               */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Frame   ""
#define fr_Frame   ""
#define en__Frame   ""
#define en_Auto332   "&Properties..."
#define fr_Auto332   "&Propri‚t‚s..."
#define it_Auto332   "&Properties..."
#define es_Auto332   "&Properties..."
#define de_Auto332   "&Properties..."
#define nl_Auto332   "&Properties..."
#define pt_Auto332   "&Properties..."
#define xx_Auto332   "&Properties..."
#define en__Auto332   ""
#define fr__Auto332   ""
#define it__Auto332   ""
#define es__Auto332   ""
#define de__Auto332   ""
#define nl__Auto332   ""
#define pt__Auto332   ""
#define xx__Auto332   ""
#define en_Auto333   "&Methods..."
#define fr_Auto333   "&M‚thodes..."
#define it_Auto333   "&Methods..."
#define es_Auto333   "&Methods..."
#define de_Auto333   "&Methods..."
#define nl_Auto333   "&Methods..."
#define pt_Auto333   "&Methods..."
#define xx_Auto333   "&Methods..."
#define en__Auto333   ""
#define fr__Auto333   ""
#define it__Auto333   ""
#define es__Auto333   ""
#define de__Auto333   ""
#define nl__Auto333   ""
#define pt__Auto333   ""
#define xx__Auto333   ""
#define en_Auto334   "&Document..."
#define fr_Auto334   "&Document..."
#define it_Auto334   "&Document..."
#define es_Auto334   "&Document..."
#define de_Auto334   "&Document..."
#define nl_Auto334   "&Document..."
#define pt_Auto334   "&Document..."
#define xx_Auto334   "&Document..."
#define en__Auto334   ""
#define fr__Auto334   ""
#define it__Auto334   ""
#define es__Auto334   ""
#define de__Auto334   ""
#define nl__Auto334   ""
#define pt__Auto334   ""
#define xx__Auto334   ""
#define en_Auto335   "&Help..."
#define fr_Auto335   "&Aide..."
#define it_Auto335   "&Help..."
#define es_Auto335   "&Help..."
#define de_Auto335   "&Hilfe..."
#define nl_Auto335   "&Help..."
#define pt_Auto335   "&Help..."
#define xx_Auto335   "&Help..."
#define en__Auto335   ""
#define fr__Auto335   ""
#define it__Auto335   ""
#define es__Auto335   ""
#define de__Auto335   ""
#define nl__Auto335   ""
#define pt__Auto335   ""
#define xx__Auto335   ""
#define en_Auto336   "&ReNumerate"
#define fr_Auto336   "&Renum‚roter"
#define it_Auto336   "&Re>Numerate"
#define es_Auto336   "&Re>Numerate"
#define de_Auto336   "&Re>Numerate"
#define nl_Auto336   "&Re>Numerate"
#define pt_Auto336   "&Re>Numerate"
#define xx_Auto336   "&Re>Numerate"
#define en__Auto336   ""
#define fr__Auto336   ""
#define it__Auto336   ""
#define es__Auto336   ""
#define de__Auto336   ""
#define nl__Auto336   ""
#define pt__Auto336   ""
#define xx__Auto336   ""
#define en_Auto337   "&Triggers"
#define fr_Auto337   "Ra&ccourcis"
#define it_Auto337   "&Triggers"
#define es_Auto337   "&Triggers"
#define de_Auto337   "&Triggers"
#define nl_Auto337   "&Triggers"
#define pt_Auto337   "&Triggers"
#define xx_Auto337   "&Triggers"
#define en__Auto337   ""
#define fr__Auto337   ""
#define it__Auto337   ""
#define es__Auto337   ""
#define de__Auto337   ""
#define nl__Auto337   ""
#define pt__Auto337   ""
#define xx__Auto337   ""
#define en_Auto338   "&Interface"
#define fr_Auto338   "&Interface"
#define it_Auto338   "&Interface"
#define es_Auto338   "&Interface"
#define de_Auto338   "&Interface"
#define nl_Auto338   "&Interface"
#define pt_Auto338   "&Interface"
#define xx_Auto338   "&Interface"
#define en_Auto339   "D&ocumentation..."
#define fr_Auto339   "D&ocumentation..."
#define it_Auto339   "D&ocumentation..."
#define es_Auto339   "D&ocumentation..."
#define de_Auto339   "D&ocumentation..."
#define nl_Auto339   "D&ocumentation..."
#define pt_Auto339   "D&ocumentation..."
#define xx_Auto339   "D&ocumentation..."
#define en__Auto339   ""
#define fr__Auto339   ""
#define it__Auto339   ""
#define es__Auto339   ""
#define de__Auto339   ""
#define nl__Auto339   ""
#define pt__Auto339   ""
#define xx__Auto339   ""
#define en_FullScreen   "&Full Screen"
#define fr_FullScreen   "P&lein ‚cran"
#define it_FullScreen   "&Fullscreen"
#define es_FullScreen   "&Fullscreen"
#define de_FullScreen   "&Fullscreen"
#define nl_FullScreen   "&Fullscreen"
#define pt_FullScreen   "&Fullscreen"
#define xx_FullScreen   "&Fullscreen"
#define en__FullScreen   ""
#define fr__FullScreen   ""
#define it__FullScreen   ""
#define es__FullScreen   ""
#define de__FullScreen   ""
#define nl__FullScreen   ""
#define pt__FullScreen   ""
#define xx__FullScreen   ""
#define en_FormStyle   "&Style"
#define fr_FormStyle   "&Style"
#define it_FormStyle   "&Style"
#define es_FormStyle   "&Style"
#define de_FormStyle   "&Style"
#define nl_FormStyle   "&Style"
#define pt_FormStyle   "&Style"
#define xx_FormStyle   "&Style"
#define en__FormStyle   ""
#define fr__FormStyle   ""
#define it__FormStyle   ""
#define es__FormStyle   ""
#define de__FormStyle   ""
#define nl__FormStyle   ""
#define pt__FormStyle   ""
#define xx__FormStyle   ""
#define en_Undo   "&Undo"
#define fr_Undo   "A&nnuler op‚ration"
#define it_Undo   "&Undo"
#define es_Undo   "&Undo"
#define de_Undo   "&Undo"
#define nl_Undo   "&Undo"
#define pt_Undo   "&Undo"
#define xx_Undo   "&Undo"
#define en__Undo   ""
#define fr__Undo   ""
#define it__Undo   ""
#define es__Undo   ""
#define de__Undo   ""
#define nl__Undo   ""
#define pt__Undo   ""
#define xx__Undo   ""
#define en_RollForeward   "R&edo"
#define fr_RollForeward   "R&efaire op‚ration"
#define it_RollForeward   "R&edo"
#define es_RollForeward   "R&edo"
#define de_RollForeward   "R&edo"
#define nl_RollForeward   "R&edo"
#define pt_RollForeward   "R&edo"
#define xx_RollForeward   "R&edo"
#define en__RollForeward   ""
#define fr__RollForeward   ""
#define it__RollForeward   ""
#define es__RollForeward   ""
#define de__RollForeward   ""
#define nl__RollForeward   ""
#define pt__RollForeward   ""
#define xx__RollForeward   ""
#define en_CompareForms   "&Compare"
#define fr_CompareForms   "Compare"
#define it_CompareForms   "&Compare"
#define es_CompareForms   "&Compare"
#define de_CompareForms   "&Compare"
#define nl_CompareForms   "&Compare"
#define pt_CompareForms   "&Compare"
#define xx_CompareForms   "&Compare"
#define en__CompareForms   ""
#define fr__CompareForms   ""
#define it__CompareForms   ""
#define es__CompareForms   ""
#define de__CompareForms   ""
#define nl__CompareForms   ""
#define pt__CompareForms   ""
#define xx__CompareForms   ""
#define en_ImportAbal   "Import &Abal Source"
#define fr_ImportAbal   "Import Source Abal"
#define it_ImportAbal   "Import &Abal Source"
#define es_ImportAbal   "Import &Abal Source"
#define de_ImportAbal   "Import &Abal Source"
#define nl_ImportAbal   "Import &Abal Source"
#define pt_ImportAbal   "Import &Abal Source"
#define xx_ImportAbal   "Import &Abal Source"
#define en__ImportAbal   ""
#define fr__ImportAbal   ""
#define it__ImportAbal   ""
#define es__ImportAbal   ""
#define de__ImportAbal   ""
#define nl__ImportAbal   ""
#define pt__ImportAbal   ""
#define xx__ImportAbal   ""

private struct forms_editor_menu_context {
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
	char * msg_FullScreen[8];
	int	trigger_FullScreen;
	char * hint_FullScreen[8];
	char * msg_FormStyle[8];
	int	trigger_FormStyle;
	char * hint_FormStyle[8];
	char * msg_Undo[8];
	int	trigger_Undo;
	char * hint_Undo[8];
	char * msg_RollForeward[8];
	int	trigger_RollForeward;
	char * hint_RollForeward[8];
	char * msg_CompareForms[8];
	int	trigger_CompareForms;
	char * hint_CompareForms[8];
	char * msg_ImportAbal[8];
	int	trigger_ImportAbal;
	char * hint_ImportAbal[8];
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct forms_editor_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = forms_editor_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}

private int on_Frame_create(struct forms_editor_menu_context * _Context) {
	mouse_move_on();
	return(-1);
}

public	int	forms_editor_menu_create(struct forms_editor_menu_context **cptr)
{

	int i;
	struct forms_editor_menu_context * _Context=(struct forms_editor_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct forms_editor_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=14;
	_Context->hint_Frame[0]=en__Frame;
	_Context->s_Frame=0;
	_Context->p_Frame=visual_buffer(328,32,176+2,304+2);
	(void) on_Frame_create(_Context);
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
	_Context->hint_Auto333[1]=fr__Auto333;
	_Context->hint_Auto333[2]=it__Auto333;
	_Context->hint_Auto333[3]=es__Auto333;
	_Context->hint_Auto333[4]=de__Auto333;
	_Context->hint_Auto333[5]=nl__Auto333;
	_Context->hint_Auto333[6]=pt__Auto333;
	_Context->hint_Auto333[7]=xx__Auto333;
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
	for (i=0; i < 8; i++)_Context->msg_FullScreen[i]=" ";
	_Context->msg_FullScreen[0]=en_FullScreen;
	_Context->msg_FullScreen[1]=fr_FullScreen;
	_Context->msg_FullScreen[2]=it_FullScreen;
	_Context->msg_FullScreen[3]=es_FullScreen;
	_Context->msg_FullScreen[4]=de_FullScreen;
	_Context->msg_FullScreen[5]=nl_FullScreen;
	_Context->msg_FullScreen[6]=pt_FullScreen;
	_Context->msg_FullScreen[7]=xx_FullScreen;
	_Context->hint_FullScreen[0]=en__FullScreen;
	_Context->hint_FullScreen[1]=fr__FullScreen;
	_Context->hint_FullScreen[2]=it__FullScreen;
	_Context->hint_FullScreen[3]=es__FullScreen;
	_Context->hint_FullScreen[4]=de__FullScreen;
	_Context->hint_FullScreen[5]=nl__FullScreen;
	_Context->hint_FullScreen[6]=pt__FullScreen;
	_Context->hint_FullScreen[7]=xx__FullScreen;
	for (i=0; i < 8; i++)_Context->msg_FormStyle[i]=" ";
	_Context->msg_FormStyle[0]=en_FormStyle;
	_Context->msg_FormStyle[1]=fr_FormStyle;
	_Context->msg_FormStyle[2]=it_FormStyle;
	_Context->msg_FormStyle[3]=es_FormStyle;
	_Context->msg_FormStyle[4]=de_FormStyle;
	_Context->msg_FormStyle[5]=nl_FormStyle;
	_Context->msg_FormStyle[6]=pt_FormStyle;
	_Context->msg_FormStyle[7]=xx_FormStyle;
	_Context->hint_FormStyle[0]=en__FormStyle;
	_Context->hint_FormStyle[1]=fr__FormStyle;
	_Context->hint_FormStyle[2]=it__FormStyle;
	_Context->hint_FormStyle[3]=es__FormStyle;
	_Context->hint_FormStyle[4]=de__FormStyle;
	_Context->hint_FormStyle[5]=nl__FormStyle;
	_Context->hint_FormStyle[6]=pt__FormStyle;
	_Context->hint_FormStyle[7]=xx__FormStyle;
	for (i=0; i < 8; i++)_Context->msg_Undo[i]=" ";
	_Context->msg_Undo[0]=en_Undo;
	_Context->msg_Undo[1]=fr_Undo;
	_Context->msg_Undo[2]=it_Undo;
	_Context->msg_Undo[3]=es_Undo;
	_Context->msg_Undo[4]=de_Undo;
	_Context->msg_Undo[5]=nl_Undo;
	_Context->msg_Undo[6]=pt_Undo;
	_Context->msg_Undo[7]=xx_Undo;
	_Context->hint_Undo[0]=en__Undo;
	_Context->hint_Undo[1]=fr__Undo;
	_Context->hint_Undo[2]=it__Undo;
	_Context->hint_Undo[3]=es__Undo;
	_Context->hint_Undo[4]=de__Undo;
	_Context->hint_Undo[5]=nl__Undo;
	_Context->hint_Undo[6]=pt__Undo;
	_Context->hint_Undo[7]=xx__Undo;
	for (i=0; i < 8; i++)_Context->msg_RollForeward[i]=" ";
	_Context->msg_RollForeward[0]=en_RollForeward;
	_Context->msg_RollForeward[1]=fr_RollForeward;
	_Context->msg_RollForeward[2]=it_RollForeward;
	_Context->msg_RollForeward[3]=es_RollForeward;
	_Context->msg_RollForeward[4]=de_RollForeward;
	_Context->msg_RollForeward[5]=nl_RollForeward;
	_Context->msg_RollForeward[6]=pt_RollForeward;
	_Context->msg_RollForeward[7]=xx_RollForeward;
	_Context->hint_RollForeward[0]=en__RollForeward;
	_Context->hint_RollForeward[1]=fr__RollForeward;
	_Context->hint_RollForeward[2]=it__RollForeward;
	_Context->hint_RollForeward[3]=es__RollForeward;
	_Context->hint_RollForeward[4]=de__RollForeward;
	_Context->hint_RollForeward[5]=nl__RollForeward;
	_Context->hint_RollForeward[6]=pt__RollForeward;
	_Context->hint_RollForeward[7]=xx__RollForeward;
	for (i=0; i < 8; i++)_Context->msg_CompareForms[i]=" ";
	_Context->msg_CompareForms[0]=en_CompareForms;
	_Context->msg_CompareForms[1]=fr_CompareForms;
	_Context->msg_CompareForms[2]=it_CompareForms;
	_Context->msg_CompareForms[3]=es_CompareForms;
	_Context->msg_CompareForms[4]=de_CompareForms;
	_Context->msg_CompareForms[5]=nl_CompareForms;
	_Context->msg_CompareForms[6]=pt_CompareForms;
	_Context->msg_CompareForms[7]=xx_CompareForms;
	_Context->hint_CompareForms[0]=en__CompareForms;
	_Context->hint_CompareForms[1]=fr__CompareForms;
	_Context->hint_CompareForms[2]=it__CompareForms;
	_Context->hint_CompareForms[3]=es__CompareForms;
	_Context->hint_CompareForms[4]=de__CompareForms;
	_Context->hint_CompareForms[5]=nl__CompareForms;
	_Context->hint_CompareForms[6]=pt__CompareForms;
	_Context->hint_CompareForms[7]=xx__CompareForms;
	for (i=0; i < 8; i++)_Context->msg_ImportAbal[i]=" ";
	_Context->msg_ImportAbal[0]=en_ImportAbal;
	_Context->msg_ImportAbal[1]=fr_ImportAbal;
	_Context->msg_ImportAbal[2]=it_ImportAbal;
	_Context->msg_ImportAbal[3]=es_ImportAbal;
	_Context->msg_ImportAbal[4]=de_ImportAbal;
	_Context->msg_ImportAbal[5]=nl_ImportAbal;
	_Context->msg_ImportAbal[6]=pt_ImportAbal;
	_Context->msg_ImportAbal[7]=xx_ImportAbal;
	_Context->hint_ImportAbal[0]=en__ImportAbal;
	_Context->hint_ImportAbal[1]=fr__ImportAbal;
	_Context->hint_ImportAbal[2]=it__ImportAbal;
	_Context->hint_ImportAbal[3]=es__ImportAbal;
	_Context->hint_ImportAbal[4]=de__ImportAbal;
	_Context->hint_ImportAbal[5]=nl__ImportAbal;
	_Context->hint_ImportAbal[6]=pt__ImportAbal;
	_Context->hint_ImportAbal[7]=xx__ImportAbal;
	return(0);
}

public 	int	forms_editor_menu_hide(struct forms_editor_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Frame != (void *) 0)
	&& (_Context->s_Frame != 0)) {
		(void)visual_buffer_put(_Context->p_Frame,328,32);
		_Context->s_Frame=0;
		}

	return(result);
}
private int on_Frame_remove(struct forms_editor_menu_context * _Context) {
	mouse_move_off();
	return(-1);
}

public	int	forms_editor_menu_remove(struct forms_editor_menu_context * _Context)
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

public	int	forms_editor_menu_show(struct forms_editor_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if ((_Context->p_Frame != (void *) 0)
	&& (_Context->s_Frame == 0)) {
		(void)visual_buffer_get(_Context->p_Frame,328,32);
		_Context->s_Frame=1;
		}
	if (((_Context->status = visual_styled_element(328,32,176,304,GetWidgetStyle(1)," ",0)) != 0)
) {
		visual_filzone(328,32,176,304,27,11);
		}
	_Context->trigger_Auto332=visual_trigger_code(_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]));
	if (((_Context->status = visual_styled_element(344,44,144,20,GetWidgetStyle(2),_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]))) != 0)
) {
	visual_button(344,44,144,20,vfh[2],16,0,_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]),32);
		}
	_Context->trigger_Auto333=visual_trigger_code(_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]));
	if (((_Context->status = visual_styled_element(344,64,144,20,GetWidgetStyle(2),_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]))) != 0)
) {
	visual_button(344,64,144,20,vfh[2],16,0,_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]),32);
		}
	_Context->trigger_Auto334=visual_trigger_code(_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]));
	if (((_Context->status = visual_styled_element(344,84,144,20,GetWidgetStyle(2),_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]))) != 0)
) {
	visual_button(344,84,144,20,vfh[2],16,0,_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]),32);
		}
	_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
	if (((_Context->status = visual_styled_element(344,104,144,20,GetWidgetStyle(2),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
	visual_button(344,104,144,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),32);
		}
	_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
	if (((_Context->status = visual_styled_element(344,124,144,20,GetWidgetStyle(2),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
	visual_button(344,124,144,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),32);
		}
	_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
	if (((_Context->status = visual_styled_element(344,144,144,20,GetWidgetStyle(2),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
	visual_button(344,144,144,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),32);
		}
	_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
	if (((_Context->status = visual_styled_element(344,164,144,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(344,164,144,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
		}
	_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
	if (((_Context->status = visual_styled_element(344,184,144,20,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(344,184,144,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
		}
	_Context->trigger_FullScreen=visual_trigger_code(_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]));
	if (((_Context->status = visual_styled_element(344,204,144,20,GetWidgetStyle(2),_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]))) != 0)
) {
	visual_button(344,204,144,20,vfh[2],16,0,_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]),32);
		}
	_Context->trigger_FormStyle=visual_trigger_code(_Context->msg_FormStyle[_Context->language],strlen(_Context->msg_FormStyle[_Context->language]));
	if (((_Context->status = visual_styled_element(344,224,144,20,GetWidgetStyle(2),_Context->msg_FormStyle[_Context->language],strlen(_Context->msg_FormStyle[_Context->language]))) != 0)
) {
	visual_button(344,224,144,20,vfh[2],16,0,_Context->msg_FormStyle[_Context->language],strlen(_Context->msg_FormStyle[_Context->language]),32);
		}
	_Context->trigger_Undo=visual_trigger_code(_Context->msg_Undo[_Context->language],strlen(_Context->msg_Undo[_Context->language]));
	if (((_Context->status = visual_styled_element(344,244,144,20,GetWidgetStyle(2),_Context->msg_Undo[_Context->language],strlen(_Context->msg_Undo[_Context->language]))) != 0)
) {
	visual_button(344,244,144,20,vfh[2],16,0,_Context->msg_Undo[_Context->language],strlen(_Context->msg_Undo[_Context->language]),32);
		}
	_Context->trigger_RollForeward=visual_trigger_code(_Context->msg_RollForeward[_Context->language],strlen(_Context->msg_RollForeward[_Context->language]));
	if (((_Context->status = visual_styled_element(344,264,144,20,GetWidgetStyle(2),_Context->msg_RollForeward[_Context->language],strlen(_Context->msg_RollForeward[_Context->language]))) != 0)
) {
	visual_button(344,264,144,20,vfh[2],16,0,_Context->msg_RollForeward[_Context->language],strlen(_Context->msg_RollForeward[_Context->language]),32);
		}
	_Context->trigger_CompareForms=visual_trigger_code(_Context->msg_CompareForms[_Context->language],strlen(_Context->msg_CompareForms[_Context->language]));
	if (((_Context->status = visual_styled_element(344,284,144,20,GetWidgetStyle(2),_Context->msg_CompareForms[_Context->language],strlen(_Context->msg_CompareForms[_Context->language]))) != 0)
) {
	visual_button(344,284,144,20,vfh[2],16,0,_Context->msg_CompareForms[_Context->language],strlen(_Context->msg_CompareForms[_Context->language]),32);
		}
	_Context->trigger_ImportAbal=visual_trigger_code(_Context->msg_ImportAbal[_Context->language],strlen(_Context->msg_ImportAbal[_Context->language]));
	if (((_Context->status = visual_styled_element(344,304,144,20,GetWidgetStyle(2),_Context->msg_ImportAbal[_Context->language],strlen(_Context->msg_ImportAbal[_Context->language]))) != 0)
) {
	visual_button(344,304,144,20,vfh[2],16,0,_Context->msg_ImportAbal[_Context->language],strlen(_Context->msg_ImportAbal[_Context->language]),32);
		}
	visual_thaw(328,32,176,304);

	return(0);
}
private int on_Auto332_event(struct forms_editor_menu_context * _Context) {
	return(_FORM_PARA);
	return(-1);
}
private int on_Auto333_event(struct forms_editor_menu_context * _Context) {
	return(_FORM_METH);
	return(-1);
}
private int on_Auto334_event(struct forms_editor_menu_context * _Context) {
	int result;
		forms_editor_menu_hide(_Context);
;
	on_Frame_remove(_Context);
	result=page_parameters();
	on_Frame_create(_Context);
		forms_editor_menu_show(_Context);
;
	return(result);
	return(-1);
}
private int on_Auto335_event(struct forms_editor_menu_context * _Context) {
	return(_WIDGET_FORM);
	return(-1);
}
private int on_Auto336_event(struct forms_editor_menu_context * _Context) {
	return(_FORM_NUMBER);
	return(-1);
}
private int on_Auto337_event(struct forms_editor_menu_context * _Context) {
	return(_FORM_TRIGGER);
	return(-1);
}
private int on_Auto338_event(struct forms_editor_menu_context * _Context) {
	return(_FORM_FACE);
	return(-1);
}
private int on_Auto339_event(struct forms_editor_menu_context * _Context) {
	return(_FORM_HELP);
	return(-1);
}
private int on_FullScreen_event(struct forms_editor_menu_context * _Context) {
	return(_FORM_FIT);
	return(-1);
}
private int on_FormStyle_event(struct forms_editor_menu_context * _Context) {
	return(_FORM_STYLE);
	return(-1);
}
private int on_Undo_event(struct forms_editor_menu_context * _Context) {
	return(_FORM_ROLLBACK);
	return(-1);
}
private int on_RollForeward_event(struct forms_editor_menu_context * _Context) {
	return(_FORM_ROLLFORE);
	return(-1);
}
private int on_CompareForms_event(struct forms_editor_menu_context * _Context) {
	return(_FORM_COMPARE);
	return(-1);
}
private int on_ImportAbal_event(struct forms_editor_menu_context * _Context) {
	return(_FORM_IMPORT);
	return(-1);
}


public	int	forms_editor_menu_event(
struct forms_editor_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto332 == mb ) return(1);
		if (_Context->trigger_Auto333 == mb ) return(2);
		if (_Context->trigger_Auto334 == mb ) return(3);
		if (_Context->trigger_Auto335 == mb ) return(4);
		if (_Context->trigger_Auto336 == mb ) return(5);
		if (_Context->trigger_Auto337 == mb ) return(6);
		if (_Context->trigger_Auto338 == mb ) return(7);
		if (_Context->trigger_Auto339 == mb ) return(8);
		if (_Context->trigger_FullScreen == mb ) return(9);
		if (_Context->trigger_FormStyle == mb ) return(10);
		if (_Context->trigger_Undo == mb ) return(11);
		if (_Context->trigger_RollForeward == mb ) return(12);
		if (_Context->trigger_CompareForms == mb ) return(13);
		if (_Context->trigger_ImportAbal == mb ) return(14);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 344 ) 
	&&  ( my >= 44 ) 
	&&  ( mx <= 488 ) 
	&&  ( my <= 64 )) {
		return(1); /* Auto332 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 64 ) 
	&&  ( mx <= 488 ) 
	&&  ( my <= 84 )) {
		return(2); /* Auto333 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 84 ) 
	&&  ( mx <= 488 ) 
	&&  ( my <= 104 )) {
		return(3); /* Auto334 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 104 ) 
	&&  ( mx <= 488 ) 
	&&  ( my <= 124 )) {
		return(4); /* Auto335 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 124 ) 
	&&  ( mx <= 488 ) 
	&&  ( my <= 144 )) {
		return(5); /* Auto336 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 144 ) 
	&&  ( mx <= 488 ) 
	&&  ( my <= 164 )) {
		return(6); /* Auto337 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 164 ) 
	&&  ( mx <= 488 ) 
	&&  ( my <= 184 )) {
		return(7); /* Auto338 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 184 ) 
	&&  ( mx <= 488 ) 
	&&  ( my <= 204 )) {
		return(8); /* Auto339 */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 204 ) 
	&&  ( mx <= 488 ) 
	&&  ( my <= 224 )) {
		return(9); /* FullScreen */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 224 ) 
	&&  ( mx <= 488 ) 
	&&  ( my <= 244 )) {
		return(10); /* FormStyle */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 244 ) 
	&&  ( mx <= 488 ) 
	&&  ( my <= 264 )) {
		return(11); /* Undo */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 264 ) 
	&&  ( mx <= 488 ) 
	&&  ( my <= 284 )) {
		return(12); /* RollForeward */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 284 ) 
	&&  ( mx <= 488 ) 
	&&  ( my <= 304 )) {
		return(13); /* CompareForms */
		}
	if (( mx >= 344 ) 
	&&  ( my >= 304 ) 
	&&  ( mx <= 488 ) 
	&&  ( my <= 324 )) {
		return(14); /* ImportAbal */
		}

	return(-1);
}


public	int	forms_editor_menu_focus(struct forms_editor_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto332 */
				_Context->trigger_Auto332=visual_trigger_code(_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]));
				if (((_Context->status = visual_styled_element(344,44,144,20,GetWidgetStyle(3),_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]))) != 0)
) {
					visual_button(344,44,144,20,vfh[2],16,0,_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto332=visual_trigger_code(_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]));
				if (((_Context->status = visual_styled_element(344,44,144,20,GetWidgetStyle(2),_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]))) != 0)
) {
	visual_button(344,44,144,20,vfh[2],16,0,_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto333 */
				_Context->trigger_Auto333=visual_trigger_code(_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]));
				if (((_Context->status = visual_styled_element(344,64,144,20,GetWidgetStyle(3),_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]))) != 0)
) {
					visual_button(344,64,144,20,vfh[2],16,0,_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto333=visual_trigger_code(_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]));
				if (((_Context->status = visual_styled_element(344,64,144,20,GetWidgetStyle(2),_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]))) != 0)
) {
	visual_button(344,64,144,20,vfh[2],16,0,_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto334 */
				_Context->trigger_Auto334=visual_trigger_code(_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]));
				if (((_Context->status = visual_styled_element(344,84,144,20,GetWidgetStyle(3),_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]))) != 0)
) {
					visual_button(344,84,144,20,vfh[2],16,0,_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto334=visual_trigger_code(_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]));
				if (((_Context->status = visual_styled_element(344,84,144,20,GetWidgetStyle(2),_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]))) != 0)
) {
	visual_button(344,84,144,20,vfh[2],16,0,_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto335 */
				_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
				if (((_Context->status = visual_styled_element(344,104,144,20,GetWidgetStyle(3),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
					visual_button(344,104,144,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
				if (((_Context->status = visual_styled_element(344,104,144,20,GetWidgetStyle(2),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
	visual_button(344,104,144,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto336 */
				_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
				if (((_Context->status = visual_styled_element(344,124,144,20,GetWidgetStyle(3),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
					visual_button(344,124,144,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
				if (((_Context->status = visual_styled_element(344,124,144,20,GetWidgetStyle(2),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
	visual_button(344,124,144,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),32);
				}
				break;
			case	0x6 :
				/* Auto337 */
				_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
				if (((_Context->status = visual_styled_element(344,144,144,20,GetWidgetStyle(3),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
					visual_button(344,144,144,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
				if (((_Context->status = visual_styled_element(344,144,144,20,GetWidgetStyle(2),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
	visual_button(344,144,144,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),32);
				}
				break;
			case	0x7 :
				/* Auto338 */
				_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
				if (((_Context->status = visual_styled_element(344,164,144,20,GetWidgetStyle(3),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
					visual_button(344,164,144,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
				if (((_Context->status = visual_styled_element(344,164,144,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(344,164,144,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
				}
				break;
			case	0x8 :
				/* Auto339 */
				_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
				if (((_Context->status = visual_styled_element(344,184,144,20,GetWidgetStyle(3),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
					visual_button(344,184,144,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
				if (((_Context->status = visual_styled_element(344,184,144,20,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(344,184,144,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
				}
				break;
			case	0x9 :
				/* FullScreen */
				_Context->trigger_FullScreen=visual_trigger_code(_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]));
				if (((_Context->status = visual_styled_element(344,204,144,20,GetWidgetStyle(3),_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]))) != 0)
) {
					visual_button(344,204,144,20,vfh[2],16,0,_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_FullScreen=visual_trigger_code(_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]));
				if (((_Context->status = visual_styled_element(344,204,144,20,GetWidgetStyle(2),_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]))) != 0)
) {
	visual_button(344,204,144,20,vfh[2],16,0,_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]),32);
				}
				break;
			case	0xa :
				/* FormStyle */
				_Context->trigger_FormStyle=visual_trigger_code(_Context->msg_FormStyle[_Context->language],strlen(_Context->msg_FormStyle[_Context->language]));
				if (((_Context->status = visual_styled_element(344,224,144,20,GetWidgetStyle(3),_Context->msg_FormStyle[_Context->language],strlen(_Context->msg_FormStyle[_Context->language]))) != 0)
) {
					visual_button(344,224,144,20,vfh[2],16,0,_Context->msg_FormStyle[_Context->language],strlen(_Context->msg_FormStyle[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_FormStyle=visual_trigger_code(_Context->msg_FormStyle[_Context->language],strlen(_Context->msg_FormStyle[_Context->language]));
				if (((_Context->status = visual_styled_element(344,224,144,20,GetWidgetStyle(2),_Context->msg_FormStyle[_Context->language],strlen(_Context->msg_FormStyle[_Context->language]))) != 0)
) {
	visual_button(344,224,144,20,vfh[2],16,0,_Context->msg_FormStyle[_Context->language],strlen(_Context->msg_FormStyle[_Context->language]),32);
				}
				break;
			case	0xb :
				/* Undo */
				_Context->trigger_Undo=visual_trigger_code(_Context->msg_Undo[_Context->language],strlen(_Context->msg_Undo[_Context->language]));
				if (((_Context->status = visual_styled_element(344,244,144,20,GetWidgetStyle(3),_Context->msg_Undo[_Context->language],strlen(_Context->msg_Undo[_Context->language]))) != 0)
) {
					visual_button(344,244,144,20,vfh[2],16,0,_Context->msg_Undo[_Context->language],strlen(_Context->msg_Undo[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Undo=visual_trigger_code(_Context->msg_Undo[_Context->language],strlen(_Context->msg_Undo[_Context->language]));
				if (((_Context->status = visual_styled_element(344,244,144,20,GetWidgetStyle(2),_Context->msg_Undo[_Context->language],strlen(_Context->msg_Undo[_Context->language]))) != 0)
) {
	visual_button(344,244,144,20,vfh[2],16,0,_Context->msg_Undo[_Context->language],strlen(_Context->msg_Undo[_Context->language]),32);
				}
				break;
			case	0xc :
				/* RollForeward */
				_Context->trigger_RollForeward=visual_trigger_code(_Context->msg_RollForeward[_Context->language],strlen(_Context->msg_RollForeward[_Context->language]));
				if (((_Context->status = visual_styled_element(344,264,144,20,GetWidgetStyle(3),_Context->msg_RollForeward[_Context->language],strlen(_Context->msg_RollForeward[_Context->language]))) != 0)
) {
					visual_button(344,264,144,20,vfh[2],16,0,_Context->msg_RollForeward[_Context->language],strlen(_Context->msg_RollForeward[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_RollForeward=visual_trigger_code(_Context->msg_RollForeward[_Context->language],strlen(_Context->msg_RollForeward[_Context->language]));
				if (((_Context->status = visual_styled_element(344,264,144,20,GetWidgetStyle(2),_Context->msg_RollForeward[_Context->language],strlen(_Context->msg_RollForeward[_Context->language]))) != 0)
) {
	visual_button(344,264,144,20,vfh[2],16,0,_Context->msg_RollForeward[_Context->language],strlen(_Context->msg_RollForeward[_Context->language]),32);
				}
				break;
			case	0xd :
				/* CompareForms */
				_Context->trigger_CompareForms=visual_trigger_code(_Context->msg_CompareForms[_Context->language],strlen(_Context->msg_CompareForms[_Context->language]));
				if (((_Context->status = visual_styled_element(344,284,144,20,GetWidgetStyle(3),_Context->msg_CompareForms[_Context->language],strlen(_Context->msg_CompareForms[_Context->language]))) != 0)
) {
					visual_button(344,284,144,20,vfh[2],16,0,_Context->msg_CompareForms[_Context->language],strlen(_Context->msg_CompareForms[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_CompareForms=visual_trigger_code(_Context->msg_CompareForms[_Context->language],strlen(_Context->msg_CompareForms[_Context->language]));
				if (((_Context->status = visual_styled_element(344,284,144,20,GetWidgetStyle(2),_Context->msg_CompareForms[_Context->language],strlen(_Context->msg_CompareForms[_Context->language]))) != 0)
) {
	visual_button(344,284,144,20,vfh[2],16,0,_Context->msg_CompareForms[_Context->language],strlen(_Context->msg_CompareForms[_Context->language]),32);
				}
				break;
			case	0xe :
				/* ImportAbal */
				_Context->trigger_ImportAbal=visual_trigger_code(_Context->msg_ImportAbal[_Context->language],strlen(_Context->msg_ImportAbal[_Context->language]));
				if (((_Context->status = visual_styled_element(344,304,144,20,GetWidgetStyle(3),_Context->msg_ImportAbal[_Context->language],strlen(_Context->msg_ImportAbal[_Context->language]))) != 0)
) {
					visual_button(344,304,144,20,vfh[2],16,0,_Context->msg_ImportAbal[_Context->language],strlen(_Context->msg_ImportAbal[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_ImportAbal=visual_trigger_code(_Context->msg_ImportAbal[_Context->language],strlen(_Context->msg_ImportAbal[_Context->language]));
				if (((_Context->status = visual_styled_element(344,304,144,20,GetWidgetStyle(2),_Context->msg_ImportAbal[_Context->language],strlen(_Context->msg_ImportAbal[_Context->language]))) != 0)
) {
	visual_button(344,304,144,20,vfh[2],16,0,_Context->msg_ImportAbal[_Context->language],strlen(_Context->msg_ImportAbal[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			forms_editor_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=14;
			forms_editor_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  328 )
				|| ( visual_event(6) <  32 )
				|| ( visual_event(7) >  504 )
				|| ( visual_event(6) >  336 )) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=forms_editor_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto332 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto332=visual_trigger_code(_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]));
						if (((_Context->status = visual_styled_element(344,44,144,20,GetWidgetStyle(3),_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]))) != 0)
) {
							visual_button(344,44,144,20,vfh[2],16,0,_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto332=visual_trigger_code(_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]));
						if (((_Context->status = visual_styled_element(344,44,144,20,GetWidgetStyle(2),_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]))) != 0)
) {
	visual_button(344,44,144,20,vfh[2],16,0,_Context->msg_Auto332[_Context->language],strlen(_Context->msg_Auto332[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto332_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto333 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto333=visual_trigger_code(_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]));
						if (((_Context->status = visual_styled_element(344,64,144,20,GetWidgetStyle(3),_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]))) != 0)
) {
							visual_button(344,64,144,20,vfh[2],16,0,_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto333=visual_trigger_code(_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]));
						if (((_Context->status = visual_styled_element(344,64,144,20,GetWidgetStyle(2),_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]))) != 0)
) {
	visual_button(344,64,144,20,vfh[2],16,0,_Context->msg_Auto333[_Context->language],strlen(_Context->msg_Auto333[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto333_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto334 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto334=visual_trigger_code(_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]));
						if (((_Context->status = visual_styled_element(344,84,144,20,GetWidgetStyle(3),_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]))) != 0)
) {
							visual_button(344,84,144,20,vfh[2],16,0,_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto334=visual_trigger_code(_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]));
						if (((_Context->status = visual_styled_element(344,84,144,20,GetWidgetStyle(2),_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]))) != 0)
) {
	visual_button(344,84,144,20,vfh[2],16,0,_Context->msg_Auto334[_Context->language],strlen(_Context->msg_Auto334[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto334_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto335 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
						if (((_Context->status = visual_styled_element(344,104,144,20,GetWidgetStyle(3),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
							visual_button(344,104,144,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto335=visual_trigger_code(_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]));
						if (((_Context->status = visual_styled_element(344,104,144,20,GetWidgetStyle(2),_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]))) != 0)
) {
	visual_button(344,104,144,20,vfh[2],16,0,_Context->msg_Auto335[_Context->language],strlen(_Context->msg_Auto335[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto335_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto336 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
						if (((_Context->status = visual_styled_element(344,124,144,20,GetWidgetStyle(3),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
							visual_button(344,124,144,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto336=visual_trigger_code(_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]));
						if (((_Context->status = visual_styled_element(344,124,144,20,GetWidgetStyle(2),_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]))) != 0)
) {
	visual_button(344,124,144,20,vfh[2],16,0,_Context->msg_Auto336[_Context->language],strlen(_Context->msg_Auto336[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto336_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto337 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
						if (((_Context->status = visual_styled_element(344,144,144,20,GetWidgetStyle(3),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
							visual_button(344,144,144,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto337=visual_trigger_code(_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]));
						if (((_Context->status = visual_styled_element(344,144,144,20,GetWidgetStyle(2),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
	visual_button(344,144,144,20,vfh[2],16,0,_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto337_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Auto338 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
						if (((_Context->status = visual_styled_element(344,164,144,20,GetWidgetStyle(3),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
							visual_button(344,164,144,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
						if (((_Context->status = visual_styled_element(344,164,144,20,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(344,164,144,20,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto338_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Auto339 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
						if (((_Context->status = visual_styled_element(344,184,144,20,GetWidgetStyle(3),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
							visual_button(344,184,144,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
						if (((_Context->status = visual_styled_element(344,184,144,20,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(344,184,144,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto339_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* FullScreen */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_FullScreen=visual_trigger_code(_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]));
						if (((_Context->status = visual_styled_element(344,204,144,20,GetWidgetStyle(3),_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]))) != 0)
) {
							visual_button(344,204,144,20,vfh[2],16,0,_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_FullScreen=visual_trigger_code(_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]));
						if (((_Context->status = visual_styled_element(344,204,144,20,GetWidgetStyle(2),_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]))) != 0)
) {
	visual_button(344,204,144,20,vfh[2],16,0,_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_FullScreen_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* FormStyle */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_FormStyle=visual_trigger_code(_Context->msg_FormStyle[_Context->language],strlen(_Context->msg_FormStyle[_Context->language]));
						if (((_Context->status = visual_styled_element(344,224,144,20,GetWidgetStyle(3),_Context->msg_FormStyle[_Context->language],strlen(_Context->msg_FormStyle[_Context->language]))) != 0)
) {
							visual_button(344,224,144,20,vfh[2],16,0,_Context->msg_FormStyle[_Context->language],strlen(_Context->msg_FormStyle[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_FormStyle=visual_trigger_code(_Context->msg_FormStyle[_Context->language],strlen(_Context->msg_FormStyle[_Context->language]));
						if (((_Context->status = visual_styled_element(344,224,144,20,GetWidgetStyle(2),_Context->msg_FormStyle[_Context->language],strlen(_Context->msg_FormStyle[_Context->language]))) != 0)
) {
	visual_button(344,224,144,20,vfh[2],16,0,_Context->msg_FormStyle[_Context->language],strlen(_Context->msg_FormStyle[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_FormStyle_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Undo */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Undo=visual_trigger_code(_Context->msg_Undo[_Context->language],strlen(_Context->msg_Undo[_Context->language]));
						if (((_Context->status = visual_styled_element(344,244,144,20,GetWidgetStyle(3),_Context->msg_Undo[_Context->language],strlen(_Context->msg_Undo[_Context->language]))) != 0)
) {
							visual_button(344,244,144,20,vfh[2],16,0,_Context->msg_Undo[_Context->language],strlen(_Context->msg_Undo[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Undo=visual_trigger_code(_Context->msg_Undo[_Context->language],strlen(_Context->msg_Undo[_Context->language]));
						if (((_Context->status = visual_styled_element(344,244,144,20,GetWidgetStyle(2),_Context->msg_Undo[_Context->language],strlen(_Context->msg_Undo[_Context->language]))) != 0)
) {
	visual_button(344,244,144,20,vfh[2],16,0,_Context->msg_Undo[_Context->language],strlen(_Context->msg_Undo[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Undo_event(_Context)) != -1) break;

						}
					continue;
				case	0xc :
					/* RollForeward */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_RollForeward=visual_trigger_code(_Context->msg_RollForeward[_Context->language],strlen(_Context->msg_RollForeward[_Context->language]));
						if (((_Context->status = visual_styled_element(344,264,144,20,GetWidgetStyle(3),_Context->msg_RollForeward[_Context->language],strlen(_Context->msg_RollForeward[_Context->language]))) != 0)
) {
							visual_button(344,264,144,20,vfh[2],16,0,_Context->msg_RollForeward[_Context->language],strlen(_Context->msg_RollForeward[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_RollForeward=visual_trigger_code(_Context->msg_RollForeward[_Context->language],strlen(_Context->msg_RollForeward[_Context->language]));
						if (((_Context->status = visual_styled_element(344,264,144,20,GetWidgetStyle(2),_Context->msg_RollForeward[_Context->language],strlen(_Context->msg_RollForeward[_Context->language]))) != 0)
) {
	visual_button(344,264,144,20,vfh[2],16,0,_Context->msg_RollForeward[_Context->language],strlen(_Context->msg_RollForeward[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_RollForeward_event(_Context)) != -1) break;

						}
					continue;
				case	0xd :
					/* CompareForms */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_CompareForms=visual_trigger_code(_Context->msg_CompareForms[_Context->language],strlen(_Context->msg_CompareForms[_Context->language]));
						if (((_Context->status = visual_styled_element(344,284,144,20,GetWidgetStyle(3),_Context->msg_CompareForms[_Context->language],strlen(_Context->msg_CompareForms[_Context->language]))) != 0)
) {
							visual_button(344,284,144,20,vfh[2],16,0,_Context->msg_CompareForms[_Context->language],strlen(_Context->msg_CompareForms[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_CompareForms=visual_trigger_code(_Context->msg_CompareForms[_Context->language],strlen(_Context->msg_CompareForms[_Context->language]));
						if (((_Context->status = visual_styled_element(344,284,144,20,GetWidgetStyle(2),_Context->msg_CompareForms[_Context->language],strlen(_Context->msg_CompareForms[_Context->language]))) != 0)
) {
	visual_button(344,284,144,20,vfh[2],16,0,_Context->msg_CompareForms[_Context->language],strlen(_Context->msg_CompareForms[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_CompareForms_event(_Context)) != -1) break;

						}
					continue;
				case	0xe :
					/* ImportAbal */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ImportAbal=visual_trigger_code(_Context->msg_ImportAbal[_Context->language],strlen(_Context->msg_ImportAbal[_Context->language]));
						if (((_Context->status = visual_styled_element(344,304,144,20,GetWidgetStyle(3),_Context->msg_ImportAbal[_Context->language],strlen(_Context->msg_ImportAbal[_Context->language]))) != 0)
) {
							visual_button(344,304,144,20,vfh[2],16,0,_Context->msg_ImportAbal[_Context->language],strlen(_Context->msg_ImportAbal[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ImportAbal=visual_trigger_code(_Context->msg_ImportAbal[_Context->language],strlen(_Context->msg_ImportAbal[_Context->language]));
						if (((_Context->status = visual_styled_element(344,304,144,20,GetWidgetStyle(2),_Context->msg_ImportAbal[_Context->language],strlen(_Context->msg_ImportAbal[_Context->language]))) != 0)
) {
	visual_button(344,304,144,20,vfh[2],16,0,_Context->msg_ImportAbal[_Context->language],strlen(_Context->msg_ImportAbal[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ImportAbal_event(_Context)) != -1) break;

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
				_Context->focus_item=14;
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

public	int	forms_editor_menu()
{
	int	status=0;
	struct forms_editor_menu_context * _Context=(struct forms_editor_menu_context*) 0;
	status = forms_editor_menu_create(&_Context);
	if ( status != 0) return(status);
	status = forms_editor_menu_show(_Context);
		enter_modal();
	status = forms_editor_menu_focus(_Context);
		leave_modal();
	status = forms_editor_menu_hide(_Context);
	status = forms_editor_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _formmenu_c */
