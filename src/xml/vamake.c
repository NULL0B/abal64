
#ifndef _vamake_c
#define _vamake_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vamake.xml                                               */
/* Target         : vamake.c                                                 */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto3534   ""
#define fr__Auto3534   ""
#define it__Auto3534   ""
#define es__Auto3534   ""
#define de__Auto3534   ""
#define nl__Auto3534   ""
#define pt__Auto3534   ""
#define xx__Auto3534   ""
#define en_Auto3535   "Project Builder : Amake"
#define fr_Auto3535   "Construction de Projet : Amake"
#define it_Auto3535   "Project Builder : Amake"
#define es_Auto3535   "Project Builder : Amake"
#define de_Auto3535   "Project Builder : Amake"
#define nl_Auto3535   "Project Builder : Amake"
#define pt_Auto3535   "Project Builder : Amake"
#define xx_Auto3535   "Project Builder : Amake"
#define en_Auto3536   "Program Tool Name"
#define fr_Auto3536   "Nom de l'outil"
#define it_Auto3536   "Program Tool Name"
#define es_Auto3536   "Program Tool Name"
#define de_Auto3536   "Program Tool Name"
#define nl_Auto3536   "Program Tool Name"
#define pt_Auto3536   "Program Tool Name"
#define xx_Auto3536   "Program Tool Name"
#define en__Auto3536   ""
#define fr__Auto3536   ""
#define it__Auto3536   ""
#define es__Auto3536   ""
#define de__Auto3536   ""
#define nl__Auto3536   ""
#define pt__Auto3536   ""
#define xx__Auto3536   ""
#define en_Auto3537   "Make Filename"
#define fr_Auto3537   "Fichier de construction"
#define it_Auto3537   "Make Filename"
#define es_Auto3537   "Make Filename"
#define de_Auto3537   "Make Filename"
#define nl_Auto3537   "Make Filename"
#define pt_Auto3537   "Make Filename"
#define xx_Auto3537   "Make Filename"
#define en__Auto3537   ""
#define fr__Auto3537   ""
#define it__Auto3537   ""
#define es__Auto3537   ""
#define de__Auto3537   ""
#define nl__Auto3537   ""
#define pt__Auto3537   ""
#define xx__Auto3537   ""
#define en_Auto3538   "Output Name"
#define fr_Auto3538   "Fichier de sortie"
#define it_Auto3538   "Output Name"
#define es_Auto3538   "Output Name"
#define de_Auto3538   "Output Name"
#define nl_Auto3538   "Output Name"
#define pt_Auto3538   "Output Name"
#define xx_Auto3538   "Output Name"
#define en_Auto3539   "Definitions"
#define fr_Auto3539   "D‚finitions"
#define it_Auto3539   "Definitions"
#define es_Auto3539   "Definitions"
#define de_Auto3539   "Definitions"
#define nl_Auto3539   "Definitions"
#define pt_Auto3539   "Definitions"
#define xx_Auto3539   "Definitions"
#define en_ToolName   ""
#define en__ToolName   ""
#define en_FileName   ""
#define en_Output   ""
#define en_ForceBuild   "&Force Build"
#define fr_ForceBuild   "&Forc‚e"
#define it_ForceBuild   "&Force Build"
#define es_ForceBuild   "&Force Build"
#define de_ForceBuild   "&Force Build"
#define nl_ForceBuild   "&Force Build"
#define pt_ForceBuild   "&Force Build"
#define xx_ForceBuild   "&Force Build"
#define en_ShowDates   "&Show Dependance Dates"
#define fr_ShowDates   "&Dates de D‚pendance"
#define it_ShowDates   "&Show Dependance Dates"
#define es_ShowDates   "&Show Dependance Dates"
#define de_ShowDates   "&Show Dependance Dates"
#define nl_ShowDates   "&Show Dependance Dates"
#define pt_ShowDates   "&Show Dependance Dates"
#define xx_ShowDates   "&Show Dependance Dates"
#define en_Touch_Only   "&Touch Only"
#define fr_Touch_Only   "&Touche"
#define it_Touch_Only   "&Touch Only"
#define es_Touch_Only   "&Touch Only"
#define de_Touch_Only   "&Touch Only"
#define nl_Touch_Only   "&Touch Only"
#define pt_Touch_Only   "&Touch Only"
#define xx_Touch_Only   "&Touch Only"
#define en_Auto3540   "ok.gif"
#define fr_Auto3540   "ok.gif"
#define it_Auto3540   "ok.gif"
#define es_Auto3540   "ok.gif"
#define de_Auto3540   "ok.gif"
#define nl_Auto3540   "ok.gif"
#define pt_Auto3540   "ok.gif"
#define xx_Auto3540   "ok.gif"
#define en_Edit   "&Edit"
#define fr_Edit   "&Editer"
#define it_Edit   "&Edit"
#define es_Edit   "&Edit"
#define de_Edit   "&Edit"
#define nl_Edit   "&Edit"
#define pt_Edit   "&Edit"
#define xx_Edit   "&Edit"
#define en_Auto3541   "cancel.gif"
#define fr_Auto3541   "cancel.gif"
#define it_Auto3541   "cancel.gif"
#define es_Auto3541   "cancel.gif"
#define de_Auto3541   "cancel.gif"
#define nl_Auto3541   "cancel.gif"
#define pt_Auto3541   "cancel.gif"
#define xx_Auto3541   "cancel.gif"

private struct accept_amake_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3534[8];
	char * hint_Auto3534[8];
	int	x_Auto3534;
	int	y_Auto3534;
	int	w_Auto3534;
	int	h_Auto3534;
	char * msg_Auto3535[8];
	char * hint_Auto3535[8];
	char * msg_Auto3536[8];
	char * hint_Auto3536[8];
	char * msg_Auto3537[8];
	char * hint_Auto3537[8];
	char * msg_Auto3538[8];
	char * hint_Auto3538[8];
	char * msg_Auto3539[8];
	char * hint_Auto3539[8];
	char * hint_ToolName[8];
	char	buffer_ToolName[256];
	char * hint_FileName[8];
	char	buffer_FileName[256];
	char * hint_Output[8];
	char	buffer_Output[256];
	char * hint_Define[8];
	char	buffer_Define[231];
	char * msg_ForceBuild[8];
	int	trigger_ForceBuild;
	char * hint_ForceBuild[8];
	int	value_ForceBuild;
	char * msg_ShowDates[8];
	int	trigger_ShowDates;
	char * hint_ShowDates[8];
	int	value_ShowDates;
	char * msg_Touch_Only[8];
	int	trigger_Touch_Only;
	char * hint_Touch_Only[8];
	int	value_Touch_Only;
	char * msg_Auto3540[8];
	int	trigger_Auto3540;
	char * hint_Auto3540[8];
	char * msg_Edit[8];
	int	trigger_Edit;
	char * hint_Edit[8];
	char * msg_Auto3541[8];
	int	trigger_Auto3541;
	char * hint_Auto3541[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[8];
	};
static int	vfh[16];
private int on_Auto3540_event(struct accept_amake_context * _Context);
private int on_Edit_event(struct accept_amake_context * _Context);
private int on_Auto3541_event(struct accept_amake_context * _Context);

public	int	accept_amake_create(
	struct accept_amake_context ** cptr,
	char * pToolName,
	char * pFileName,
	char * pOutput,
	char * pDefine,
	char * pForceBuild,
	char * pShowDates,
	char * pTouch_Only)
{

	int i;
	struct accept_amake_context * _Context=(struct accept_amake_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("bmap0414.fmf",12);
	if (!(_Context = allocate( sizeof( struct accept_amake_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=11;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_ToolName, 255, pToolName);
		visual_transferin(_Context->buffer_FileName, 255, pFileName);
		visual_transferin(_Context->buffer_Output, 255, pOutput);
		visual_transferin(_Context->buffer_Define, 230, pDefine);
		visual_transferin((void *) 0, 0, pForceBuild);
		if (!( pForceBuild )) _Context->value_ForceBuild=0;
		else	_Context->value_ForceBuild = *((int *)pForceBuild);
		visual_transferin((void *) 0, 0, pShowDates);
		if (!( pShowDates )) _Context->value_ShowDates=0;
		else	_Context->value_ShowDates = *((int *)pShowDates);
		visual_transferin((void *) 0, 0, pTouch_Only);
		if (!( pTouch_Only )) _Context->value_Touch_Only=0;
		else	_Context->value_Touch_Only = *((int *)pTouch_Only);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3534[i]=" ";
	_Context->hint_Auto3534[0]=en__Auto3534;
	_Context->hint_Auto3534[1]=fr__Auto3534;
	_Context->hint_Auto3534[2]=it__Auto3534;
	_Context->hint_Auto3534[3]=es__Auto3534;
	_Context->hint_Auto3534[4]=de__Auto3534;
	_Context->hint_Auto3534[5]=nl__Auto3534;
	_Context->hint_Auto3534[6]=pt__Auto3534;
	_Context->hint_Auto3534[7]=xx__Auto3534;
	_Context->x_Auto3534=110;
	_Context->y_Auto3534=100;
	_Context->w_Auto3534=580;
	_Context->h_Auto3534=400;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3535[i]=" ";
	_Context->msg_Auto3535[0]=en_Auto3535;
	_Context->msg_Auto3535[1]=fr_Auto3535;
	_Context->msg_Auto3535[2]=it_Auto3535;
	_Context->msg_Auto3535[3]=es_Auto3535;
	_Context->msg_Auto3535[4]=de_Auto3535;
	_Context->msg_Auto3535[5]=nl_Auto3535;
	_Context->msg_Auto3535[6]=pt_Auto3535;
	_Context->msg_Auto3535[7]=xx_Auto3535;
	for (i=0; i < 8; i++)_Context->msg_Auto3536[i]=" ";
	_Context->msg_Auto3536[0]=en_Auto3536;
	_Context->msg_Auto3536[1]=fr_Auto3536;
	_Context->msg_Auto3536[2]=it_Auto3536;
	_Context->msg_Auto3536[3]=es_Auto3536;
	_Context->msg_Auto3536[4]=de_Auto3536;
	_Context->msg_Auto3536[5]=nl_Auto3536;
	_Context->msg_Auto3536[6]=pt_Auto3536;
	_Context->msg_Auto3536[7]=xx_Auto3536;
	_Context->hint_Auto3536[0]=en__Auto3536;
	_Context->hint_Auto3536[1]=fr__Auto3536;
	_Context->hint_Auto3536[2]=it__Auto3536;
	_Context->hint_Auto3536[3]=es__Auto3536;
	_Context->hint_Auto3536[4]=de__Auto3536;
	_Context->hint_Auto3536[5]=nl__Auto3536;
	_Context->hint_Auto3536[6]=pt__Auto3536;
	_Context->hint_Auto3536[7]=xx__Auto3536;
	for (i=0; i < 8; i++)_Context->msg_Auto3537[i]=" ";
	_Context->msg_Auto3537[0]=en_Auto3537;
	_Context->msg_Auto3537[1]=fr_Auto3537;
	_Context->msg_Auto3537[2]=it_Auto3537;
	_Context->msg_Auto3537[3]=es_Auto3537;
	_Context->msg_Auto3537[4]=de_Auto3537;
	_Context->msg_Auto3537[5]=nl_Auto3537;
	_Context->msg_Auto3537[6]=pt_Auto3537;
	_Context->msg_Auto3537[7]=xx_Auto3537;
	_Context->hint_Auto3537[0]=en__Auto3537;
	_Context->hint_Auto3537[1]=fr__Auto3537;
	_Context->hint_Auto3537[2]=it__Auto3537;
	_Context->hint_Auto3537[3]=es__Auto3537;
	_Context->hint_Auto3537[4]=de__Auto3537;
	_Context->hint_Auto3537[5]=nl__Auto3537;
	_Context->hint_Auto3537[6]=pt__Auto3537;
	_Context->hint_Auto3537[7]=xx__Auto3537;
	for (i=0; i < 8; i++)_Context->msg_Auto3538[i]=" ";
	_Context->msg_Auto3538[0]=en_Auto3538;
	_Context->msg_Auto3538[1]=fr_Auto3538;
	_Context->msg_Auto3538[2]=it_Auto3538;
	_Context->msg_Auto3538[3]=es_Auto3538;
	_Context->msg_Auto3538[4]=de_Auto3538;
	_Context->msg_Auto3538[5]=nl_Auto3538;
	_Context->msg_Auto3538[6]=pt_Auto3538;
	_Context->msg_Auto3538[7]=xx_Auto3538;
	for (i=0; i < 8; i++)_Context->msg_Auto3539[i]=" ";
	_Context->msg_Auto3539[0]=en_Auto3539;
	_Context->msg_Auto3539[1]=fr_Auto3539;
	_Context->msg_Auto3539[2]=it_Auto3539;
	_Context->msg_Auto3539[3]=es_Auto3539;
	_Context->msg_Auto3539[4]=de_Auto3539;
	_Context->msg_Auto3539[5]=nl_Auto3539;
	_Context->msg_Auto3539[6]=pt_Auto3539;
	_Context->msg_Auto3539[7]=xx_Auto3539;
	_Context->hint_ToolName[0]=en__ToolName;
	for (i=0; i < 8; i++)_Context->msg_ForceBuild[i]=" ";
	_Context->msg_ForceBuild[0]=en_ForceBuild;
	_Context->msg_ForceBuild[1]=fr_ForceBuild;
	_Context->msg_ForceBuild[2]=it_ForceBuild;
	_Context->msg_ForceBuild[3]=es_ForceBuild;
	_Context->msg_ForceBuild[4]=de_ForceBuild;
	_Context->msg_ForceBuild[5]=nl_ForceBuild;
	_Context->msg_ForceBuild[6]=pt_ForceBuild;
	_Context->msg_ForceBuild[7]=xx_ForceBuild;
	for (i=0; i < 8; i++)_Context->msg_ShowDates[i]=" ";
	_Context->msg_ShowDates[0]=en_ShowDates;
	_Context->msg_ShowDates[1]=fr_ShowDates;
	_Context->msg_ShowDates[2]=it_ShowDates;
	_Context->msg_ShowDates[3]=es_ShowDates;
	_Context->msg_ShowDates[4]=de_ShowDates;
	_Context->msg_ShowDates[5]=nl_ShowDates;
	_Context->msg_ShowDates[6]=pt_ShowDates;
	_Context->msg_ShowDates[7]=xx_ShowDates;
	for (i=0; i < 8; i++)_Context->msg_Touch_Only[i]=" ";
	_Context->msg_Touch_Only[0]=en_Touch_Only;
	_Context->msg_Touch_Only[1]=fr_Touch_Only;
	_Context->msg_Touch_Only[2]=it_Touch_Only;
	_Context->msg_Touch_Only[3]=es_Touch_Only;
	_Context->msg_Touch_Only[4]=de_Touch_Only;
	_Context->msg_Touch_Only[5]=nl_Touch_Only;
	_Context->msg_Touch_Only[6]=pt_Touch_Only;
	_Context->msg_Touch_Only[7]=xx_Touch_Only;
	for (i=0; i < 8; i++)_Context->msg_Auto3540[i]=" ";
	_Context->msg_Auto3540[0]=en_Auto3540;
	_Context->msg_Auto3540[1]=fr_Auto3540;
	_Context->msg_Auto3540[2]=it_Auto3540;
	_Context->msg_Auto3540[3]=es_Auto3540;
	_Context->msg_Auto3540[4]=de_Auto3540;
	_Context->msg_Auto3540[5]=nl_Auto3540;
	_Context->msg_Auto3540[6]=pt_Auto3540;
	_Context->msg_Auto3540[7]=xx_Auto3540;
	for (i=0; i < 8; i++)_Context->msg_Edit[i]=" ";
	_Context->msg_Edit[0]=en_Edit;
	_Context->msg_Edit[1]=fr_Edit;
	_Context->msg_Edit[2]=it_Edit;
	_Context->msg_Edit[3]=es_Edit;
	_Context->msg_Edit[4]=de_Edit;
	_Context->msg_Edit[5]=nl_Edit;
	_Context->msg_Edit[6]=pt_Edit;
	_Context->msg_Edit[7]=xx_Edit;
	for (i=0; i < 8; i++)_Context->msg_Auto3541[i]=" ";
	_Context->msg_Auto3541[0]=en_Auto3541;
	_Context->msg_Auto3541[1]=fr_Auto3541;
	_Context->msg_Auto3541[2]=it_Auto3541;
	_Context->msg_Auto3541[3]=es_Auto3541;
	_Context->msg_Auto3541[4]=de_Auto3541;
	_Context->msg_Auto3541[5]=nl_Auto3541;
	_Context->msg_Auto3541[6]=pt_Auto3541;
	_Context->msg_Auto3541[7]=xx_Auto3541;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3534,_Context->y_Auto3534,580,400);
	return(0);
}

public 	int	accept_amake_hide(struct accept_amake_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3534,_Context->y_Auto3534);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_amake_remove(
	struct accept_amake_context * _Context,
	char * pToolName,
	char * pFileName,
	char * pOutput,
	char * pDefine,
	char * pForceBuild,
	char * pShowDates,
	char * pTouch_Only)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_ToolName, 255, pToolName);
		visual_transferout(_Context->buffer_FileName, 255, pFileName);
		visual_transferout(_Context->buffer_Output, 255, pOutput);
		visual_transferout(_Context->buffer_Define, 230, pDefine);
		visual_transferout((void *) 0, 0, pForceBuild);
		if ( pForceBuild != (char *) 0)
			*((int*)pForceBuild) = _Context->value_ForceBuild;
		visual_transferout((void *) 0, 0, pShowDates);
		if ( pShowDates != (char *) 0)
			*((int*)pShowDates) = _Context->value_ShowDates;
		visual_transferout((void *) 0, 0, pTouch_Only);
		if ( pTouch_Only != (char *) 0)
			*((int*)pTouch_Only) = _Context->value_Touch_Only;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_amake_show(struct accept_amake_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3534,_Context->y_Auto3534);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3534,_Context->y_Auto3534,580,400,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3534,_Context->y_Auto3534,580,400,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x7);
		}
	visual_text(_Context->x_Auto3534+30,_Context->y_Auto3534+30,510,30,vfh[4],16,0,_Context->msg_Auto3535[_Context->language],strlen(_Context->msg_Auto3535[_Context->language]),1283);
	visual_text(_Context->x_Auto3534+20,_Context->y_Auto3534+80,154,16,vfh[2],16,0,_Context->msg_Auto3536[_Context->language],strlen(_Context->msg_Auto3536[_Context->language]),258);
	visual_text(_Context->x_Auto3534+20,_Context->y_Auto3534+120,154,16,vfh[2],16,0,_Context->msg_Auto3537[_Context->language],strlen(_Context->msg_Auto3537[_Context->language]),258);
	visual_text(_Context->x_Auto3534+20,_Context->y_Auto3534+160,154,16,vfh[2],16,0,_Context->msg_Auto3538[_Context->language],strlen(_Context->msg_Auto3538[_Context->language]),258);
	visual_text(_Context->x_Auto3534+20,_Context->y_Auto3534+200,154,16,vfh[2],16,0,_Context->msg_Auto3539[_Context->language],strlen(_Context->msg_Auto3539[_Context->language]),258);
	visual_frame(_Context->x_Auto3534+180,_Context->y_Auto3534+80,368+2,16+2,5);
	visual_text(_Context->x_Auto3534+180+1,_Context->y_Auto3534+80+1,368,16,vfh[1],16,0,_Context->buffer_ToolName,255,0);
	visual_frame(_Context->x_Auto3534+180,_Context->y_Auto3534+120,368+2,16+2,5);
	visual_text(_Context->x_Auto3534+180+1,_Context->y_Auto3534+120+1,368,16,vfh[1],16,0,_Context->buffer_FileName,255,0);
	visual_frame(_Context->x_Auto3534+180,_Context->y_Auto3534+160,368+2,16+2,5);
	visual_text(_Context->x_Auto3534+180+1,_Context->y_Auto3534+160+1,368,16,vfh[1],16,0,_Context->buffer_Output,255,0);
	visual_frame(_Context->x_Auto3534+180,_Context->y_Auto3534+200,368+2,80+2,5);
	visual_text(_Context->x_Auto3534+180+1,_Context->y_Auto3534+200+1,368,80,vfh[1],16,0,_Context->buffer_Define,230,0);
	_Context->trigger_ForceBuild=visual_trigger_code(_Context->msg_ForceBuild[_Context->language],strlen(_Context->msg_ForceBuild[_Context->language]));
	visual_check(_Context->x_Auto3534+20,_Context->y_Auto3534+290,154,32,vfh[2],16,0,_Context->msg_ForceBuild[_Context->language],strlen(_Context->msg_ForceBuild[_Context->language]),_Context->value_ForceBuild|0);
	_Context->trigger_ShowDates=visual_trigger_code(_Context->msg_ShowDates[_Context->language],strlen(_Context->msg_ShowDates[_Context->language]));
	visual_check(_Context->x_Auto3534+180,_Context->y_Auto3534+290,238,32,vfh[2],16,0,_Context->msg_ShowDates[_Context->language],strlen(_Context->msg_ShowDates[_Context->language]),_Context->value_ShowDates|0);
	_Context->trigger_Touch_Only=visual_trigger_code(_Context->msg_Touch_Only[_Context->language],strlen(_Context->msg_Touch_Only[_Context->language]));
	visual_check(_Context->x_Auto3534+420,_Context->y_Auto3534+290,126,32,vfh[2],16,0,_Context->msg_Touch_Only[_Context->language],strlen(_Context->msg_Touch_Only[_Context->language]),_Context->value_Touch_Only|0);
	_Context->trigger_Auto3540=visual_trigger_code(_Context->msg_Auto3540[_Context->language],strlen(_Context->msg_Auto3540[_Context->language]));
	visual_button(_Context->x_Auto3534+30,_Context->y_Auto3534+340,56,48,vfh[2],34,0,_Context->msg_Auto3540[_Context->language],strlen(_Context->msg_Auto3540[_Context->language]),1040);
	_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
	visual_button(_Context->x_Auto3534+230,_Context->y_Auto3534+340,126,32,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),0);
	_Context->trigger_Auto3541=visual_trigger_code(_Context->msg_Auto3541[_Context->language],strlen(_Context->msg_Auto3541[_Context->language]));
	visual_button(_Context->x_Auto3534+490,_Context->y_Auto3534+340,56,48,vfh[2],34,0,_Context->msg_Auto3541[_Context->language],strlen(_Context->msg_Auto3541[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3534,_Context->y_Auto3534,580,400);

	return(0);
}

private int ToolName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field provides the full path and filename of the ABAL makefile ";
			mptr[1]="build utility amake.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Ce champ  fournit le chemin complet et le nom de fichier de l'utilitaire ";
			mptr[1]="de construction de makefile ABAL amake.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field provides the full path and file name of the project ";
			mptr[1]="description file or makefile.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Ce champ fournit le chemin complet et le nom du fichier de description ";
			mptr[1]="de projet (makefile).   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Output_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This field allows an output or report file name to be specified. If ";
			mptr[1]="this field provides a value it will be used to collect al messages ";
			mptr[2]="output by the project  update operation and will be presented for ";
			mptr[3]="inspection upon completion.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[4];
			mptr[0] = "Ce champ permet d'indiquer le nom d'un fichier de rapport ou de sortie. ";
			mptr[1]="Si ce champ  fournit une valeur, le fichier sera utilis‚  par l'op‚ration ";
			mptr[2]="de mise … jour du projet pour collecter  toutes les sorties de messages ";
			mptr[3]="et il sera fournit pour examen … la fin du traitement.  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Define_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows project build options to be specified. These ";
			mptr[1]="are usually  variable or definition names which will be used to control ";
			mptr[2]="the update operation.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Ce champ permet de pr‚ciser des options de construction du projet. ";
			mptr[1]="Ce sont  g‚n‚ralement des noms de variables ou de d‚finition qui seront ";
			mptr[2]="utilis‚s pour contr“ler l'op‚ration de mise … jour.  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ForceBuild_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "When this check control is active the update operation will be an ";
			mptr[1]="unconditional rebuild of all targets. Otherwise target and source ";
			mptr[2]="dates will be compared and only out of date targets will be rebuilt. ";
			mptr[3]="  ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[4];
			mptr[0] = "Si cette case … cocher est active, l'op‚ration de mise … jour sera ";
			mptr[1]="une reconstruction de toutes les cibles, sans condition particuliŠre. ";
			mptr[2]="Sinon, les dates des sources et des cibles seront compar‚es et seules ";
			mptr[3]="les cibles hors des dates seront reconstruites.  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ShowDates_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this check control is active target and source file dates and ";
			mptr[1]="times will be generated to the output log if this has been requested. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Quand cette case … cocher est active, les dates et les heures des ";
			mptr[1]="fichiers sources et cibles seront g‚n‚r‚r‚es dans le fichier journal ";
			mptr[2]="si cela a ‚t‚ demand‚.  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Touch_Only_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "When this check control is active out of date targets will be date ";
			mptr[1]="and time stamped instaed of being rebuilt. This may be used in conjunction ";
			mptr[2]="with the force build flag causing all target date and time stamps ";
			mptr[3]="to be refreshed.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Quand cette case … cocher est active, les cibles hors des dates seront ";
			mptr[1]="mises … la date et … l'heure courantes, plut“t que d'ˆtre reconstruites. ";
			mptr[2]="Cela peut ˆtre utilis‚ en conjonction avec une indication de construction ";
			mptr[3]="forc‚e, causant le rafraŒchissement de toutes  les dates et heures ";
			mptr[4]="des cibles.  ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3540_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the ACCEPT button any changes made to the various    parameters ";
			mptr[1]="will take effect.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Edit_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing this button the makefile named will be made available ";
			mptr[1]="for inspection by the Standard Text Editor Mechanisms   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "En pressant ce bouton, le makefile nomm‚ sera disponible pour  examen ";
			mptr[1]="par les m‚canismes de l'Editeur de textes standard.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3541_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the CANCEL button any modifications performed will be ";
			mptr[1]="   discarded.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3534action(struct accept_amake_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_amake_hide(_Context);

		_Context->x_Auto3534 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3534 < 0) { _Context->x_Auto3534=0; }
		_Context->y_Auto3534 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3534 < 0) { _Context->y_Auto3534=0; }
			accept_amake_show(_Context);

		visual_thaw(_Context->x_Auto3534,_Context->y_Auto3534,580,400);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3540_event(struct accept_amake_context * _Context) {
	return(13);
	return(-1);
}
private int on_Edit_event(struct accept_amake_context * _Context) {
		accept_amake_hide(_Context);
;
	use_editor(_Context->buffer_FileName,0);
		accept_amake_show(_Context);
;
	return(-1);
}
private int on_Auto3541_event(struct accept_amake_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_amake_event(
struct accept_amake_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_ForceBuild == mb ) return(6);
		if (_Context->trigger_ShowDates == mb ) return(7);
		if (_Context->trigger_Touch_Only == mb ) return(8);
		if (_Context->trigger_Auto3540 == mb ) return(9);
		if (_Context->trigger_Edit == mb ) return(10);
		if (_Context->trigger_Auto3541 == mb ) return(11);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3534+559) )  
	&&  (my >= (_Context->y_Auto3534+4) )  
	&&  (mx <= (_Context->x_Auto3534+576) )  
	&&  (my <= (_Context->y_Auto3534+20) )) {
		return(1);	/* Auto3534 */

		}
	if ((mx >= (_Context->x_Auto3534+543) )  
	&&  (my >= (_Context->y_Auto3534+4) )  
	&&  (mx <= (_Context->x_Auto3534+560) )  
	&&  (my <= (_Context->y_Auto3534+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vamake.htm");
			};
		return(-1);	/* Auto3534 */

		}
	if ((mx >= (_Context->x_Auto3534+527) )  
	&&  (my >= (_Context->y_Auto3534+4) )  
	&&  (mx <= (_Context->x_Auto3534+544) )  
	&&  (my <= (_Context->y_Auto3534+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_amake_show(_Context);
		return(-1);	/* Auto3534 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3534+4) )  
		&&  (my >= (_Context->y_Auto3534+4) )  
		&&  (mx <= (_Context->x_Auto3534+512) )  
		&&  (my <= (_Context->y_Auto3534+20) )) {
			return( Auto3534action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3534+180) ) 
	&&  ( my >= (_Context->y_Auto3534+80) ) 
	&&  ( mx <= (_Context->x_Auto3534+180+368) ) 
	&&  ( my <= (_Context->y_Auto3534+80+16))) {
		return(2); /* ToolName */
		}
	if (( mx >= (_Context->x_Auto3534+180) ) 
	&&  ( my >= (_Context->y_Auto3534+120) ) 
	&&  ( mx <= (_Context->x_Auto3534+180+368) ) 
	&&  ( my <= (_Context->y_Auto3534+120+16))) {
		return(3); /* FileName */
		}
	if (( mx >= (_Context->x_Auto3534+180) ) 
	&&  ( my >= (_Context->y_Auto3534+160) ) 
	&&  ( mx <= (_Context->x_Auto3534+180+368) ) 
	&&  ( my <= (_Context->y_Auto3534+160+16))) {
		return(4); /* Output */
		}
	if (( mx >= (_Context->x_Auto3534+180) ) 
	&&  ( my >= (_Context->y_Auto3534+200) ) 
	&&  ( mx <= (_Context->x_Auto3534+180+368) ) 
	&&  ( my <= (_Context->y_Auto3534+200+80))) {
		return(5); /* Define */
		}
	if (( mx >= (_Context->x_Auto3534+20) ) 
	&&  ( my >= (_Context->y_Auto3534+290) ) 
	&&  ( mx <= (_Context->x_Auto3534+20+154) ) 
	&&  ( my <= (_Context->y_Auto3534+290+32))) {
		return(6); /* ForceBuild */
		}
	if (( mx >= (_Context->x_Auto3534+180) ) 
	&&  ( my >= (_Context->y_Auto3534+290) ) 
	&&  ( mx <= (_Context->x_Auto3534+180+238) ) 
	&&  ( my <= (_Context->y_Auto3534+290+32))) {
		return(7); /* ShowDates */
		}
	if (( mx >= (_Context->x_Auto3534+420) ) 
	&&  ( my >= (_Context->y_Auto3534+290) ) 
	&&  ( mx <= (_Context->x_Auto3534+420+126) ) 
	&&  ( my <= (_Context->y_Auto3534+290+32))) {
		return(8); /* Touch_Only */
		}
	if (( mx >= (_Context->x_Auto3534+30) ) 
	&&  ( my >= (_Context->y_Auto3534+340) ) 
	&&  ( mx <= (_Context->x_Auto3534+30+56) ) 
	&&  ( my <= (_Context->y_Auto3534+340+48))) {
		return(9); /* Auto3540 */
		}
	if (( mx >= (_Context->x_Auto3534+230) ) 
	&&  ( my >= (_Context->y_Auto3534+340) ) 
	&&  ( mx <= (_Context->x_Auto3534+230+126) ) 
	&&  ( my <= (_Context->y_Auto3534+340+32))) {
		return(10); /* Edit */
		}
	if (( mx >= (_Context->x_Auto3534+490) ) 
	&&  ( my >= (_Context->y_Auto3534+340) ) 
	&&  ( mx <= (_Context->x_Auto3534+490+56) ) 
	&&  ( my <= (_Context->y_Auto3534+340+48))) {
		return(11); /* Auto3541 */
		}

	return(-1);
}


public	int	accept_amake_focus(struct accept_amake_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* ToolName */
				_Context->keycode = visual_edit(_Context->x_Auto3534+180+1,_Context->y_Auto3534+80+1,368,16,vfh[1],_Context->buffer_ToolName,255);
			break;
			case	0x3 :
				/* FileName */
				_Context->keycode = visual_edit(_Context->x_Auto3534+180+1,_Context->y_Auto3534+120+1,368,16,vfh[1],_Context->buffer_FileName,255);
			break;
			case	0x4 :
				/* Output */
				_Context->keycode = visual_edit(_Context->x_Auto3534+180+1,_Context->y_Auto3534+160+1,368,16,vfh[1],_Context->buffer_Output,255);
			break;
			case	0x5 :
				/* Define */
				_Context->keycode = visual_edit(_Context->x_Auto3534+180+1,_Context->y_Auto3534+200+1,368,80,vfh[1],_Context->buffer_Define,230);
			break;
			case	0x6 :
				/* ForceBuild */
				visual_check(_Context->x_Auto3534+20,_Context->y_Auto3534+290,154,32,vfh[2],16,0,_Context->msg_ForceBuild[_Context->language],strlen(_Context->msg_ForceBuild[_Context->language]),(_Context->value_ForceBuild |2));
				_Context->keycode = visual_getch();
				_Context->trigger_ForceBuild=visual_trigger_code(_Context->msg_ForceBuild[_Context->language],strlen(_Context->msg_ForceBuild[_Context->language]));
	visual_check(_Context->x_Auto3534+20,_Context->y_Auto3534+290,154,32,vfh[2],16,0,_Context->msg_ForceBuild[_Context->language],strlen(_Context->msg_ForceBuild[_Context->language]),_Context->value_ForceBuild|0);
				break;
			case	0x7 :
				/* ShowDates */
				visual_check(_Context->x_Auto3534+180,_Context->y_Auto3534+290,238,32,vfh[2],16,0,_Context->msg_ShowDates[_Context->language],strlen(_Context->msg_ShowDates[_Context->language]),(_Context->value_ShowDates |2));
				_Context->keycode = visual_getch();
				_Context->trigger_ShowDates=visual_trigger_code(_Context->msg_ShowDates[_Context->language],strlen(_Context->msg_ShowDates[_Context->language]));
	visual_check(_Context->x_Auto3534+180,_Context->y_Auto3534+290,238,32,vfh[2],16,0,_Context->msg_ShowDates[_Context->language],strlen(_Context->msg_ShowDates[_Context->language]),_Context->value_ShowDates|0);
				break;
			case	0x8 :
				/* Touch_Only */
				visual_check(_Context->x_Auto3534+420,_Context->y_Auto3534+290,126,32,vfh[2],16,0,_Context->msg_Touch_Only[_Context->language],strlen(_Context->msg_Touch_Only[_Context->language]),(_Context->value_Touch_Only |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Touch_Only=visual_trigger_code(_Context->msg_Touch_Only[_Context->language],strlen(_Context->msg_Touch_Only[_Context->language]));
	visual_check(_Context->x_Auto3534+420,_Context->y_Auto3534+290,126,32,vfh[2],16,0,_Context->msg_Touch_Only[_Context->language],strlen(_Context->msg_Touch_Only[_Context->language]),_Context->value_Touch_Only|0);
				break;
			case	0x9 :
				/* Auto3540 */
				_Context->trigger_Auto3540=visual_trigger_code(_Context->msg_Auto3540[_Context->language],strlen(_Context->msg_Auto3540[_Context->language]));
				visual_button(_Context->x_Auto3534+30,_Context->y_Auto3534+340,56,48,vfh[2],34,0,_Context->msg_Auto3540[_Context->language],strlen(_Context->msg_Auto3540[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3540=visual_trigger_code(_Context->msg_Auto3540[_Context->language],strlen(_Context->msg_Auto3540[_Context->language]));
	visual_button(_Context->x_Auto3534+30,_Context->y_Auto3534+340,56,48,vfh[2],34,0,_Context->msg_Auto3540[_Context->language],strlen(_Context->msg_Auto3540[_Context->language]),1040);
				break;
			case	0xa :
				/* Edit */
				_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
				visual_button(_Context->x_Auto3534+230,_Context->y_Auto3534+340,126,32,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
	visual_button(_Context->x_Auto3534+230,_Context->y_Auto3534+340,126,32,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),0);
				break;
			case	0xb :
				/* Auto3541 */
				_Context->trigger_Auto3541=visual_trigger_code(_Context->msg_Auto3541[_Context->language],strlen(_Context->msg_Auto3541[_Context->language]));
				visual_button(_Context->x_Auto3534+490,_Context->y_Auto3534+340,56,48,vfh[2],34,0,_Context->msg_Auto3541[_Context->language],strlen(_Context->msg_Auto3541[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3541=visual_trigger_code(_Context->msg_Auto3541[_Context->language],strlen(_Context->msg_Auto3541[_Context->language]));
	visual_button(_Context->x_Auto3534+490,_Context->y_Auto3534+340,56,48,vfh[2],34,0,_Context->msg_Auto3541[_Context->language],strlen(_Context->msg_Auto3541[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_amake_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=11;
			accept_amake_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_amake_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (ToolName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (FileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Output_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Define_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (ForceBuild_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (ShowDates_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (Touch_Only_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (Auto3540_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (Edit_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Auto3541_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3534 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* ToolName */
					continue;
				case	0x3 :
					/* FileName */
					continue;
				case	0x4 :
					/* Output */
					continue;
				case	0x5 :
					/* Define */
					continue;
				case	0x6 :
					/* ForceBuild */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ForceBuild += 1;
						_Context->value_ForceBuild &= 1;
						}
					continue;
				case	0x7 :
					/* ShowDates */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ShowDates += 1;
						_Context->value_ShowDates &= 1;
						}
					continue;
				case	0x8 :
					/* Touch_Only */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Touch_Only += 1;
						_Context->value_Touch_Only &= 1;
						}
					continue;
				case	0x9 :
					/* Auto3540 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3540=visual_trigger_code(_Context->msg_Auto3540[_Context->language],strlen(_Context->msg_Auto3540[_Context->language]));
						visual_button(_Context->x_Auto3534+30,_Context->y_Auto3534+340,56,48,vfh[2],34,0,_Context->msg_Auto3540[_Context->language],strlen(_Context->msg_Auto3540[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3540=visual_trigger_code(_Context->msg_Auto3540[_Context->language],strlen(_Context->msg_Auto3540[_Context->language]));
	visual_button(_Context->x_Auto3534+30,_Context->y_Auto3534+340,56,48,vfh[2],34,0,_Context->msg_Auto3540[_Context->language],strlen(_Context->msg_Auto3540[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3540_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Edit */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
						visual_button(_Context->x_Auto3534+230,_Context->y_Auto3534+340,126,32,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
	visual_button(_Context->x_Auto3534+230,_Context->y_Auto3534+340,126,32,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Edit_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Auto3541 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3541=visual_trigger_code(_Context->msg_Auto3541[_Context->language],strlen(_Context->msg_Auto3541[_Context->language]));
						visual_button(_Context->x_Auto3534+490,_Context->y_Auto3534+340,56,48,vfh[2],34,0,_Context->msg_Auto3541[_Context->language],strlen(_Context->msg_Auto3541[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3541=visual_trigger_code(_Context->msg_Auto3541[_Context->language],strlen(_Context->msg_Auto3541[_Context->language]));
	visual_button(_Context->x_Auto3534+490,_Context->y_Auto3534+340,56,48,vfh[2],34,0,_Context->msg_Auto3541[_Context->language],strlen(_Context->msg_Auto3541[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3541_event(_Context)) != -1) break;

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
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_amake(
	char * pToolName,
	char * pFileName,
	char * pOutput,
	char * pDefine,
	char * pForceBuild,
	char * pShowDates,
	char * pTouch_Only)
{
	int	status=0;
	struct accept_amake_context * _Context=(struct accept_amake_context*) 0;
	status = accept_amake_create(
	&_Context,
	 pToolName,
	 pFileName,
	 pOutput,
	 pDefine,
	 pForceBuild,
	 pShowDates,
	 pTouch_Only);
	if ( status != 0) return(status);
	status = accept_amake_show(_Context);
		enter_modal();
	status = accept_amake_focus(_Context);
		leave_modal();
	status = accept_amake_hide(_Context);
	status = accept_amake_remove(
	_Context,
	 pToolName,
	 pFileName,
	 pOutput,
	 pDefine,
	 pForceBuild,
	 pShowDates,
	 pTouch_Only);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vamake_c */
