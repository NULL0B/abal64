
#ifndef _vcmpform_c
#define _vcmpform_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vcmpform.xml                                             */
/* Target         : vcmpform.c                                               */
/* Identification : 0.0-1177511934-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en__Auto2708   ""
#define fr__Auto2708   ""
#define it__Auto2708   ""
#define es__Auto2708   ""
#define de__Auto2708   ""
#define nl__Auto2708   ""
#define pt__Auto2708   ""
#define xx__Auto2708   ""
#define en_Auto2709   "Compare forms"
#define fr_Auto2709   "Comparaison de formulaires"
#define it_Auto2709   "Compare forms"
#define es_Auto2709   "Compare forms"
#define de_Auto2709   "Compare forms"
#define nl_Auto2709   "Compare forms"
#define pt_Auto2709   "Compare forms"
#define xx_Auto2709   "Compare forms"
#define en__Auto2709   ""
#define fr__Auto2709   ""
#define it__Auto2709   ""
#define es__Auto2709   ""
#define de__Auto2709   ""
#define nl__Auto2709   ""
#define pt__Auto2709   ""
#define xx__Auto2709   ""
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"
#define en_Auto2710   "Forms Filenames"
#define fr_Auto2710   "Noms"
#define it_Auto2710   "Forms Filenames"
#define es_Auto2710   "Forms Filenames"
#define de_Auto2710   "Name Datai"
#define nl_Auto2710   "Forms Filenames"
#define pt_Auto2710   "Forms Filenames"
#define xx_Auto2710   "Forms Filenames"
#define en__Auto2710   ""
#define fr__Auto2710   ""
#define it__Auto2710   ""
#define es__Auto2710   ""
#define de__Auto2710   ""
#define nl__Auto2710   ""
#define pt__Auto2710   ""
#define xx__Auto2710   ""
#define en_Auto2711   "1)"
#define fr_Auto2711   "1)"
#define it_Auto2711   "1)"
#define es_Auto2711   "1)"
#define de_Auto2711   "1)"
#define nl_Auto2711   "1)"
#define pt_Auto2711   "1)"
#define xx_Auto2711   "1)"
#define en__Auto2711   ""
#define fr__Auto2711   ""
#define it__Auto2711   ""
#define es__Auto2711   ""
#define de__Auto2711   ""
#define nl__Auto2711   ""
#define pt__Auto2711   ""
#define xx__Auto2711   ""
#define en_Auto2712   "2)"
#define fr_Auto2712   "2)"
#define it_Auto2712   "2)"
#define es_Auto2712   "2)"
#define de_Auto2712   "2)"
#define nl_Auto2712   "2)"
#define pt_Auto2712   "2)"
#define xx_Auto2712   "2)"
#define en__Auto2712   ""
#define fr__Auto2712   ""
#define it__Auto2712   ""
#define es__Auto2712   ""
#define de__Auto2712   ""
#define nl__Auto2712   ""
#define pt__Auto2712   ""
#define xx__Auto2712   ""
#define en_Auto2713   "Log Filename"
#define fr_Auto2713   "Fichier log"
#define it_Auto2713   "Log Filename"
#define es_Auto2713   "Log Filename"
#define de_Auto2713   "Log Filename"
#define nl_Auto2713   "Log Filename"
#define pt_Auto2713   "Log Filename"
#define xx_Auto2713   "Log Filename"
#define en__Auto2713   ""
#define fr__Auto2713   ""
#define it__Auto2713   ""
#define es__Auto2713   ""
#define de__Auto2713   ""
#define nl__Auto2713   ""
#define pt__Auto2713   ""
#define xx__Auto2713   ""
#define en_FormName1   ""
#define en__FormName1   ""
#define en_FormName2   ""
#define en__FormName2   ""
#define en_FixMsg   "National Language Message Correction"
#define fr_FixMsg   "Correction de messages nationales"
#define it_FixMsg   "National Language Message Correction"
#define es_FixMsg   "National Language Message Correction"
#define de_FixMsg   "National Language Message Correction"
#define nl_FixMsg   "National Language Message Correction"
#define pt_FixMsg   "National Language Message Correction"
#define xx_FixMsg   "National Language Message Correction"
#define en__FixMsg   ""
#define fr__FixMsg   ""
#define it__FixMsg   ""
#define es__FixMsg   ""
#define de__FixMsg   ""
#define nl__FixMsg   ""
#define pt__FixMsg   ""
#define xx__FixMsg   ""
#define en_FixMethods   "Forms Method Correction"
#define fr_FixMethods   "M‚thodes du formulaire"
#define it_FixMethods   ""
#define es_FixMethods   ""
#define de_FixMethods   ""
#define nl_FixMethods   ""
#define pt_FixMethods   ""
#define xx_FixMethods   ""
#define en__FixMethods   ""
#define fr__FixMethods   ""
#define it__FixMethods   ""
#define es__FixMethods   ""
#define de__FixMethods   ""
#define nl__FixMethods   ""
#define pt__FixMethods   ""
#define xx__FixMethods   ""
#define en_FixEvents   "Widget Event Method Correction"
#define fr_FixEvents   "M‚thodes Event des widget"
#define it_FixEvents   ""
#define es_FixEvents   ""
#define de_FixEvents   ""
#define nl_FixEvents   ""
#define pt_FixEvents   ""
#define xx_FixEvents   ""
#define en__FixEvents   ""
#define fr__FixEvents   ""
#define it__FixEvents   ""
#define es__FixEvents   ""
#define de__FixEvents   ""
#define nl__FixEvents   ""
#define pt__FixEvents   ""
#define xx__FixEvents   ""
#define en_FixFormat   "Format Information Correction"
#define fr_FixFormat   "Informations de format"
#define it_FixFormat   ""
#define es_FixFormat   ""
#define de_FixFormat   ""
#define nl_FixFormat   ""
#define pt_FixFormat   ""
#define xx_FixFormat   ""
#define en__FixFormat   ""
#define fr__FixFormat   ""
#define it__FixFormat   ""
#define es__FixFormat   ""
#define de__FixFormat   ""
#define nl__FixFormat   ""
#define pt__FixFormat   ""
#define xx__FixFormat   ""
#define en_FixList   "Generate Difference list"
#define fr_FixList   "G‚n‚rer le fichier des diff‚rences"
#define it_FixList   "Generate Difference list"
#define es_FixList   "Generate Difference list"
#define de_FixList   "Generate Difference list"
#define nl_FixList   "Generate Difference list"
#define pt_FixList   "Generate Difference list"
#define xx_FixList   "Generate Difference list"
#define en__FixList   ""
#define fr__FixList   ""
#define it__FixList   ""
#define es__FixList   ""
#define de__FixList   ""
#define nl__FixList   ""
#define pt__FixList   ""
#define xx__FixList   ""
#define en_ShowMethod   "Show Detail"
#define fr_ShowMethod   "D‚tails"
#define it_ShowMethod   "Show Detail"
#define es_ShowMethod   "Show Detail"
#define de_ShowMethod   "Show Detail"
#define nl_ShowMethod   "Show Detail"
#define pt_ShowMethod   "Show Detail"
#define xx_ShowMethod   "Show Detail"
#define en__ShowMethod   ""
#define fr__ShowMethod   ""
#define it__ShowMethod   ""
#define es__ShowMethod   ""
#define de__ShowMethod   ""
#define nl__ShowMethod   ""
#define pt__ShowMethod   ""
#define xx__ShowMethod   ""
#define en_DiffList   ""
#define en__DiffList   ""
#define en_Accept   "ok.gif"
#define fr_Accept   "ok.gif"
#define it_Accept   "ok.gif"
#define es_Accept   "ok.gif"
#define de_Accept   "ok.gif"
#define nl_Accept   "ok.gif"
#define pt_Accept   "ok.gif"
#define xx_Accept   "ok.gif"

private struct accept_form_compare_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto2708[8];
	char * hint_Auto2708[8];
	int	x_Auto2708;
	int	y_Auto2708;
	int	w_Auto2708;
	int	h_Auto2708;
	char * msg_Auto2709[8];
	char * hint_Auto2709[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	char * msg_Auto2710[8];
	char * hint_Auto2710[8];
	char * msg_Auto2711[8];
	char * hint_Auto2711[8];
	char * msg_Auto2712[8];
	char * hint_Auto2712[8];
	char * msg_Auto2713[8];
	char * hint_Auto2713[8];
	char * hint_FormName1[8];
	char	buffer_FormName1[256];
	char * hint_FormName2[8];
	char	buffer_FormName2[256];
	char * msg_FixMsg[8];
	int	trigger_FixMsg;
	char * hint_FixMsg[8];
	int	value_FixMsg;
	char * msg_FixMethods[8];
	int	trigger_FixMethods;
	char * hint_FixMethods[8];
	int	value_FixMethods;
	char * msg_FixEvents[8];
	int	trigger_FixEvents;
	char * hint_FixEvents[8];
	int	value_FixEvents;
	char * msg_FixFormat[8];
	int	trigger_FixFormat;
	char * hint_FixFormat[8];
	int	value_FixFormat;
	char * msg_FixList[8];
	int	trigger_FixList;
	char * hint_FixList[8];
	int	value_FixList;
	char * msg_ShowMethod[8];
	int	trigger_ShowMethod;
	char * hint_ShowMethod[8];
	int	value_ShowMethod;
	char * hint_DiffList[8];
	char	buffer_DiffList[69];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[10];
	};
static int	vfh[16];

public	int	accept_form_compare_create(
	struct accept_form_compare_context ** cptr,
	char * pFormName1,
	char * pFormName2,
	char * pFixMsg,
	char * pFixMethods,
	char * pFixEvents,
	char * pFixFormat,
	char * pFixList,
	char * pShowMethod,
	char * pDiffList)
{

	int i;
	struct accept_form_compare_context * _Context=(struct accept_form_compare_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_form_compare_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=12;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWWWWS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FormName1, 255, pFormName1);
		visual_transferin(_Context->buffer_FormName2, 255, pFormName2);
		visual_transferin((void *) 0, 0, pFixMsg);
		if (!( pFixMsg )) _Context->value_FixMsg=0;
		else	_Context->value_FixMsg = *((int *)pFixMsg);
		visual_transferin((void *) 0, 0, pFixMethods);
		if (!( pFixMethods )) _Context->value_FixMethods=0;
		else	_Context->value_FixMethods = *((int *)pFixMethods);
		visual_transferin((void *) 0, 0, pFixEvents);
		if (!( pFixEvents )) _Context->value_FixEvents=0;
		else	_Context->value_FixEvents = *((int *)pFixEvents);
		visual_transferin((void *) 0, 0, pFixFormat);
		if (!( pFixFormat )) _Context->value_FixFormat=0;
		else	_Context->value_FixFormat = *((int *)pFixFormat);
		visual_transferin((void *) 0, 0, pFixList);
		if (!( pFixList )) _Context->value_FixList=0;
		else	_Context->value_FixList = *((int *)pFixList);
		visual_transferin((void *) 0, 0, pShowMethod);
		if (!( pShowMethod )) _Context->value_ShowMethod=0;
		else	_Context->value_ShowMethod = *((int *)pShowMethod);
		visual_transferin(_Context->buffer_DiffList, 68, pDiffList);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto2708[i]=" ";
	_Context->hint_Auto2708[0]=en__Auto2708;
	_Context->hint_Auto2708[1]=fr__Auto2708;
	_Context->hint_Auto2708[2]=it__Auto2708;
	_Context->hint_Auto2708[3]=es__Auto2708;
	_Context->hint_Auto2708[4]=de__Auto2708;
	_Context->hint_Auto2708[5]=nl__Auto2708;
	_Context->hint_Auto2708[6]=pt__Auto2708;
	_Context->hint_Auto2708[7]=xx__Auto2708;
	_Context->x_Auto2708=95;
	_Context->y_Auto2708=125;
	_Context->w_Auto2708=610;
	_Context->h_Auto2708=350;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2709[i]=" ";
	_Context->msg_Auto2709[0]=en_Auto2709;
	_Context->msg_Auto2709[1]=fr_Auto2709;
	_Context->msg_Auto2709[2]=it_Auto2709;
	_Context->msg_Auto2709[3]=es_Auto2709;
	_Context->msg_Auto2709[4]=de_Auto2709;
	_Context->msg_Auto2709[5]=nl_Auto2709;
	_Context->msg_Auto2709[6]=pt_Auto2709;
	_Context->msg_Auto2709[7]=xx_Auto2709;
	_Context->hint_Auto2709[0]=en__Auto2709;
	_Context->hint_Auto2709[1]=fr__Auto2709;
	_Context->hint_Auto2709[2]=it__Auto2709;
	_Context->hint_Auto2709[3]=es__Auto2709;
	_Context->hint_Auto2709[4]=de__Auto2709;
	_Context->hint_Auto2709[5]=nl__Auto2709;
	_Context->hint_Auto2709[6]=pt__Auto2709;
	_Context->hint_Auto2709[7]=xx__Auto2709;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->msg_Cancel[2]=it_Cancel;
	_Context->msg_Cancel[3]=es_Cancel;
	_Context->msg_Cancel[4]=de_Cancel;
	_Context->msg_Cancel[5]=nl_Cancel;
	_Context->msg_Cancel[6]=pt_Cancel;
	_Context->msg_Cancel[7]=xx_Cancel;
	for (i=0; i < 8; i++)_Context->msg_Auto2710[i]=" ";
	_Context->msg_Auto2710[0]=en_Auto2710;
	_Context->msg_Auto2710[1]=fr_Auto2710;
	_Context->msg_Auto2710[2]=it_Auto2710;
	_Context->msg_Auto2710[3]=es_Auto2710;
	_Context->msg_Auto2710[4]=de_Auto2710;
	_Context->msg_Auto2710[5]=nl_Auto2710;
	_Context->msg_Auto2710[6]=pt_Auto2710;
	_Context->msg_Auto2710[7]=xx_Auto2710;
	_Context->hint_Auto2710[0]=en__Auto2710;
	_Context->hint_Auto2710[1]=fr__Auto2710;
	_Context->hint_Auto2710[2]=it__Auto2710;
	_Context->hint_Auto2710[3]=es__Auto2710;
	_Context->hint_Auto2710[4]=de__Auto2710;
	_Context->hint_Auto2710[5]=nl__Auto2710;
	_Context->hint_Auto2710[6]=pt__Auto2710;
	_Context->hint_Auto2710[7]=xx__Auto2710;
	for (i=0; i < 8; i++)_Context->msg_Auto2711[i]=" ";
	_Context->msg_Auto2711[0]=en_Auto2711;
	_Context->msg_Auto2711[1]=fr_Auto2711;
	_Context->msg_Auto2711[2]=it_Auto2711;
	_Context->msg_Auto2711[3]=es_Auto2711;
	_Context->msg_Auto2711[4]=de_Auto2711;
	_Context->msg_Auto2711[5]=nl_Auto2711;
	_Context->msg_Auto2711[6]=pt_Auto2711;
	_Context->msg_Auto2711[7]=xx_Auto2711;
	_Context->hint_Auto2711[0]=en__Auto2711;
	_Context->hint_Auto2711[1]=fr__Auto2711;
	_Context->hint_Auto2711[2]=it__Auto2711;
	_Context->hint_Auto2711[3]=es__Auto2711;
	_Context->hint_Auto2711[4]=de__Auto2711;
	_Context->hint_Auto2711[5]=nl__Auto2711;
	_Context->hint_Auto2711[6]=pt__Auto2711;
	_Context->hint_Auto2711[7]=xx__Auto2711;
	for (i=0; i < 8; i++)_Context->msg_Auto2712[i]=" ";
	_Context->msg_Auto2712[0]=en_Auto2712;
	_Context->msg_Auto2712[1]=fr_Auto2712;
	_Context->msg_Auto2712[2]=it_Auto2712;
	_Context->msg_Auto2712[3]=es_Auto2712;
	_Context->msg_Auto2712[4]=de_Auto2712;
	_Context->msg_Auto2712[5]=nl_Auto2712;
	_Context->msg_Auto2712[6]=pt_Auto2712;
	_Context->msg_Auto2712[7]=xx_Auto2712;
	_Context->hint_Auto2712[0]=en__Auto2712;
	_Context->hint_Auto2712[1]=fr__Auto2712;
	_Context->hint_Auto2712[2]=it__Auto2712;
	_Context->hint_Auto2712[3]=es__Auto2712;
	_Context->hint_Auto2712[4]=de__Auto2712;
	_Context->hint_Auto2712[5]=nl__Auto2712;
	_Context->hint_Auto2712[6]=pt__Auto2712;
	_Context->hint_Auto2712[7]=xx__Auto2712;
	for (i=0; i < 8; i++)_Context->msg_Auto2713[i]=" ";
	_Context->msg_Auto2713[0]=en_Auto2713;
	_Context->msg_Auto2713[1]=fr_Auto2713;
	_Context->msg_Auto2713[2]=it_Auto2713;
	_Context->msg_Auto2713[3]=es_Auto2713;
	_Context->msg_Auto2713[4]=de_Auto2713;
	_Context->msg_Auto2713[5]=nl_Auto2713;
	_Context->msg_Auto2713[6]=pt_Auto2713;
	_Context->msg_Auto2713[7]=xx_Auto2713;
	_Context->hint_Auto2713[0]=en__Auto2713;
	_Context->hint_Auto2713[1]=fr__Auto2713;
	_Context->hint_Auto2713[2]=it__Auto2713;
	_Context->hint_Auto2713[3]=es__Auto2713;
	_Context->hint_Auto2713[4]=de__Auto2713;
	_Context->hint_Auto2713[5]=nl__Auto2713;
	_Context->hint_Auto2713[6]=pt__Auto2713;
	_Context->hint_Auto2713[7]=xx__Auto2713;
	_Context->hint_FormName1[0]=en__FormName1;
	_Context->hint_FormName2[0]=en__FormName2;
	for (i=0; i < 8; i++)_Context->msg_FixMsg[i]=" ";
	_Context->msg_FixMsg[0]=en_FixMsg;
	_Context->msg_FixMsg[1]=fr_FixMsg;
	_Context->msg_FixMsg[2]=it_FixMsg;
	_Context->msg_FixMsg[3]=es_FixMsg;
	_Context->msg_FixMsg[4]=de_FixMsg;
	_Context->msg_FixMsg[5]=nl_FixMsg;
	_Context->msg_FixMsg[6]=pt_FixMsg;
	_Context->msg_FixMsg[7]=xx_FixMsg;
	_Context->hint_FixMsg[0]=en__FixMsg;
	_Context->hint_FixMsg[1]=fr__FixMsg;
	_Context->hint_FixMsg[2]=it__FixMsg;
	_Context->hint_FixMsg[3]=es__FixMsg;
	_Context->hint_FixMsg[4]=de__FixMsg;
	_Context->hint_FixMsg[5]=nl__FixMsg;
	_Context->hint_FixMsg[6]=pt__FixMsg;
	_Context->hint_FixMsg[7]=xx__FixMsg;
	for (i=0; i < 8; i++)_Context->msg_FixMethods[i]=" ";
	_Context->msg_FixMethods[0]=en_FixMethods;
	_Context->msg_FixMethods[1]=fr_FixMethods;
	_Context->msg_FixMethods[2]=it_FixMethods;
	_Context->msg_FixMethods[3]=es_FixMethods;
	_Context->msg_FixMethods[4]=de_FixMethods;
	_Context->msg_FixMethods[5]=nl_FixMethods;
	_Context->msg_FixMethods[6]=pt_FixMethods;
	_Context->msg_FixMethods[7]=xx_FixMethods;
	_Context->hint_FixMethods[0]=en__FixMethods;
	_Context->hint_FixMethods[1]=fr__FixMethods;
	_Context->hint_FixMethods[2]=it__FixMethods;
	_Context->hint_FixMethods[3]=es__FixMethods;
	_Context->hint_FixMethods[4]=de__FixMethods;
	_Context->hint_FixMethods[5]=nl__FixMethods;
	_Context->hint_FixMethods[6]=pt__FixMethods;
	_Context->hint_FixMethods[7]=xx__FixMethods;
	for (i=0; i < 8; i++)_Context->msg_FixEvents[i]=" ";
	_Context->msg_FixEvents[0]=en_FixEvents;
	_Context->msg_FixEvents[1]=fr_FixEvents;
	_Context->msg_FixEvents[2]=it_FixEvents;
	_Context->msg_FixEvents[3]=es_FixEvents;
	_Context->msg_FixEvents[4]=de_FixEvents;
	_Context->msg_FixEvents[5]=nl_FixEvents;
	_Context->msg_FixEvents[6]=pt_FixEvents;
	_Context->msg_FixEvents[7]=xx_FixEvents;
	_Context->hint_FixEvents[0]=en__FixEvents;
	_Context->hint_FixEvents[1]=fr__FixEvents;
	_Context->hint_FixEvents[2]=it__FixEvents;
	_Context->hint_FixEvents[3]=es__FixEvents;
	_Context->hint_FixEvents[4]=de__FixEvents;
	_Context->hint_FixEvents[5]=nl__FixEvents;
	_Context->hint_FixEvents[6]=pt__FixEvents;
	_Context->hint_FixEvents[7]=xx__FixEvents;
	for (i=0; i < 8; i++)_Context->msg_FixFormat[i]=" ";
	_Context->msg_FixFormat[0]=en_FixFormat;
	_Context->msg_FixFormat[1]=fr_FixFormat;
	_Context->msg_FixFormat[2]=it_FixFormat;
	_Context->msg_FixFormat[3]=es_FixFormat;
	_Context->msg_FixFormat[4]=de_FixFormat;
	_Context->msg_FixFormat[5]=nl_FixFormat;
	_Context->msg_FixFormat[6]=pt_FixFormat;
	_Context->msg_FixFormat[7]=xx_FixFormat;
	_Context->hint_FixFormat[0]=en__FixFormat;
	_Context->hint_FixFormat[1]=fr__FixFormat;
	_Context->hint_FixFormat[2]=it__FixFormat;
	_Context->hint_FixFormat[3]=es__FixFormat;
	_Context->hint_FixFormat[4]=de__FixFormat;
	_Context->hint_FixFormat[5]=nl__FixFormat;
	_Context->hint_FixFormat[6]=pt__FixFormat;
	_Context->hint_FixFormat[7]=xx__FixFormat;
	for (i=0; i < 8; i++)_Context->msg_FixList[i]=" ";
	_Context->msg_FixList[0]=en_FixList;
	_Context->msg_FixList[1]=fr_FixList;
	_Context->msg_FixList[2]=it_FixList;
	_Context->msg_FixList[3]=es_FixList;
	_Context->msg_FixList[4]=de_FixList;
	_Context->msg_FixList[5]=nl_FixList;
	_Context->msg_FixList[6]=pt_FixList;
	_Context->msg_FixList[7]=xx_FixList;
	_Context->hint_FixList[0]=en__FixList;
	_Context->hint_FixList[1]=fr__FixList;
	_Context->hint_FixList[2]=it__FixList;
	_Context->hint_FixList[3]=es__FixList;
	_Context->hint_FixList[4]=de__FixList;
	_Context->hint_FixList[5]=nl__FixList;
	_Context->hint_FixList[6]=pt__FixList;
	_Context->hint_FixList[7]=xx__FixList;
	for (i=0; i < 8; i++)_Context->msg_ShowMethod[i]=" ";
	_Context->msg_ShowMethod[0]=en_ShowMethod;
	_Context->msg_ShowMethod[1]=fr_ShowMethod;
	_Context->msg_ShowMethod[2]=it_ShowMethod;
	_Context->msg_ShowMethod[3]=es_ShowMethod;
	_Context->msg_ShowMethod[4]=de_ShowMethod;
	_Context->msg_ShowMethod[5]=nl_ShowMethod;
	_Context->msg_ShowMethod[6]=pt_ShowMethod;
	_Context->msg_ShowMethod[7]=xx_ShowMethod;
	_Context->hint_ShowMethod[0]=en__ShowMethod;
	_Context->hint_ShowMethod[1]=fr__ShowMethod;
	_Context->hint_ShowMethod[2]=it__ShowMethod;
	_Context->hint_ShowMethod[3]=es__ShowMethod;
	_Context->hint_ShowMethod[4]=de__ShowMethod;
	_Context->hint_ShowMethod[5]=nl__ShowMethod;
	_Context->hint_ShowMethod[6]=pt__ShowMethod;
	_Context->hint_ShowMethod[7]=xx__ShowMethod;
	_Context->hint_DiffList[0]=en__DiffList;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto2708,_Context->y_Auto2708,610+10,350+10);
	return(0);
}

public 	int	accept_form_compare_hide(struct accept_form_compare_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto2708,_Context->y_Auto2708);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_form_compare_remove(
	struct accept_form_compare_context * _Context,
	char * pFormName1,
	char * pFormName2,
	char * pFixMsg,
	char * pFixMethods,
	char * pFixEvents,
	char * pFixFormat,
	char * pFixList,
	char * pShowMethod,
	char * pDiffList)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWWWWS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FormName1, 255, pFormName1);
		visual_transferout(_Context->buffer_FormName2, 255, pFormName2);
		visual_transferout((void *) 0, 0, pFixMsg);
		if ( pFixMsg != (char *) 0)
			*((int*)pFixMsg) = _Context->value_FixMsg;
		visual_transferout((void *) 0, 0, pFixMethods);
		if ( pFixMethods != (char *) 0)
			*((int*)pFixMethods) = _Context->value_FixMethods;
		visual_transferout((void *) 0, 0, pFixEvents);
		if ( pFixEvents != (char *) 0)
			*((int*)pFixEvents) = _Context->value_FixEvents;
		visual_transferout((void *) 0, 0, pFixFormat);
		if ( pFixFormat != (char *) 0)
			*((int*)pFixFormat) = _Context->value_FixFormat;
		visual_transferout((void *) 0, 0, pFixList);
		if ( pFixList != (char *) 0)
			*((int*)pFixList) = _Context->value_FixList;
		visual_transferout((void *) 0, 0, pShowMethod);
		if ( pShowMethod != (char *) 0)
			*((int*)pShowMethod) = _Context->value_ShowMethod;
		visual_transferout(_Context->buffer_DiffList, 68, pDiffList);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_form_compare_show(struct accept_form_compare_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto2708,_Context->y_Auto2708);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto2708,_Context->y_Auto2708,610,350,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto2708,_Context->y_Auto2708,610,350,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto2708+10,_Context->y_Auto2708+30,590,16,vfh[2],16,0,_Context->msg_Auto2709[_Context->language],strlen(_Context->msg_Auto2709[_Context->language]),258);
	visual_frame(_Context->x_Auto2708+10,_Context->y_Auto2708+46,590,234,4);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto2708+540,_Context->y_Auto2708+290,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_text(_Context->x_Auto2708+30,_Context->y_Auto2708+60,544,16,vfh[2],16,0,_Context->msg_Auto2710[_Context->language],strlen(_Context->msg_Auto2710[_Context->language]),258);
	visual_text(_Context->x_Auto2708+20,_Context->y_Auto2708+80,28,16,vfh[2],16,0,_Context->msg_Auto2711[_Context->language],strlen(_Context->msg_Auto2711[_Context->language]),257);
	visual_text(_Context->x_Auto2708+20,_Context->y_Auto2708+100,28,16,vfh[2],16,0,_Context->msg_Auto2712[_Context->language],strlen(_Context->msg_Auto2712[_Context->language]),257);
	visual_text(_Context->x_Auto2708+30,_Context->y_Auto2708+220,544,16,vfh[2],16,0,_Context->msg_Auto2713[_Context->language],strlen(_Context->msg_Auto2713[_Context->language]),258);
	visual_frame(_Context->x_Auto2708+50,_Context->y_Auto2708+80,528+2,16+2,5);
	visual_text(_Context->x_Auto2708+50+1,_Context->y_Auto2708+80+1,528,16,vfh[1],16,0,_Context->buffer_FormName1,255,0);
	visual_frame(_Context->x_Auto2708+50,_Context->y_Auto2708+100,528+2,16+2,5);
	visual_text(_Context->x_Auto2708+50+1,_Context->y_Auto2708+100+1,528,16,vfh[1],16,0,_Context->buffer_FormName2,255,0);
	_Context->trigger_FixMsg=visual_trigger_code(_Context->msg_FixMsg[_Context->language],strlen(_Context->msg_FixMsg[_Context->language]));
	visual_check(_Context->x_Auto2708+30,_Context->y_Auto2708+130,280,16,vfh[2],27,28,_Context->msg_FixMsg[_Context->language],strlen(_Context->msg_FixMsg[_Context->language]),_Context->value_FixMsg|0);
	_Context->trigger_FixMethods=visual_trigger_code(_Context->msg_FixMethods[_Context->language],strlen(_Context->msg_FixMethods[_Context->language]));
	visual_check(_Context->x_Auto2708+320,_Context->y_Auto2708+130,252,16,vfh[2],27,28,_Context->msg_FixMethods[_Context->language],strlen(_Context->msg_FixMethods[_Context->language]),_Context->value_FixMethods|0);
	_Context->trigger_FixEvents=visual_trigger_code(_Context->msg_FixEvents[_Context->language],strlen(_Context->msg_FixEvents[_Context->language]));
	visual_check(_Context->x_Auto2708+30,_Context->y_Auto2708+160,280,16,vfh[2],27,28,_Context->msg_FixEvents[_Context->language],strlen(_Context->msg_FixEvents[_Context->language]),_Context->value_FixEvents|0);
	_Context->trigger_FixFormat=visual_trigger_code(_Context->msg_FixFormat[_Context->language],strlen(_Context->msg_FixFormat[_Context->language]));
	visual_check(_Context->x_Auto2708+320,_Context->y_Auto2708+160,252,16,vfh[2],27,28,_Context->msg_FixFormat[_Context->language],strlen(_Context->msg_FixFormat[_Context->language]),_Context->value_FixFormat|0);
	_Context->trigger_FixList=visual_trigger_code(_Context->msg_FixList[_Context->language],strlen(_Context->msg_FixList[_Context->language]));
	visual_check(_Context->x_Auto2708+30,_Context->y_Auto2708+190,252,16,vfh[2],27,28,_Context->msg_FixList[_Context->language],strlen(_Context->msg_FixList[_Context->language]),_Context->value_FixList|0);
	_Context->trigger_ShowMethod=visual_trigger_code(_Context->msg_ShowMethod[_Context->language],strlen(_Context->msg_ShowMethod[_Context->language]));
	visual_check(_Context->x_Auto2708+320,_Context->y_Auto2708+190,252,16,vfh[2],27,28,_Context->msg_ShowMethod[_Context->language],strlen(_Context->msg_ShowMethod[_Context->language]),_Context->value_ShowMethod|0);
	visual_frame(_Context->x_Auto2708+30,_Context->y_Auto2708+240,544+2,16+2,5);
	visual_text(_Context->x_Auto2708+30+1,_Context->y_Auto2708+240+1,544,16,vfh[1],0,0,_Context->buffer_DiffList,68,0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto2708+10,_Context->y_Auto2708+290,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	visual_thaw(_Context->x_Auto2708,_Context->y_Auto2708,610,350);

	return(0);
}

private int Cancel_help()
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

private int Accept_help()
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
private int on_Cancel_event(struct accept_form_compare_context * _Context) {
	return(27);
	return(-1);
}
private int on_Accept_event(struct accept_form_compare_context * _Context) {
	return(13);
	return(-1);
}


public	int	accept_form_compare_event(
struct accept_form_compare_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Cancel == mb ) return(2);
		if (_Context->trigger_FixMsg == mb ) return(5);
		if (_Context->trigger_FixMethods == mb ) return(6);
		if (_Context->trigger_FixEvents == mb ) return(7);
		if (_Context->trigger_FixFormat == mb ) return(8);
		if (_Context->trigger_FixList == mb ) return(9);
		if (_Context->trigger_ShowMethod == mb ) return(10);
		if (_Context->trigger_Accept == mb ) return(12);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto2708+589) )  
	&&  (my >= (_Context->y_Auto2708+4) )  
	&&  (mx <= (_Context->x_Auto2708+606) )  
	&&  (my <= (_Context->y_Auto2708+20) )) {
		return(1);	/* Auto2708 */

		}
	if ((mx >= (_Context->x_Auto2708+573) )  
	&&  (my >= (_Context->y_Auto2708+4) )  
	&&  (mx <= (_Context->x_Auto2708+590) )  
	&&  (my <= (_Context->y_Auto2708+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcmpform.htm");
			};
		return(-1);	/* Auto2708 */

		}
	if ((mx >= (_Context->x_Auto2708+557) )  
	&&  (my >= (_Context->y_Auto2708+4) )  
	&&  (mx <= (_Context->x_Auto2708+574) )  
	&&  (my <= (_Context->y_Auto2708+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_form_compare_show(_Context);
		return(-1);	/* Auto2708 */

		}
		}
	if (( mx >= (_Context->x_Auto2708+540) ) 
	&&  ( my >= (_Context->y_Auto2708+290) ) 
	&&  ( mx <= (_Context->x_Auto2708+540+56) ) 
	&&  ( my <= (_Context->y_Auto2708+290+48))) {
		return(2); /* Cancel */
		}
	if (( mx >= (_Context->x_Auto2708+50) ) 
	&&  ( my >= (_Context->y_Auto2708+80) ) 
	&&  ( mx <= (_Context->x_Auto2708+50+528) ) 
	&&  ( my <= (_Context->y_Auto2708+80+16))) {
		return(3); /* FormName1 */
		}
	if (( mx >= (_Context->x_Auto2708+50) ) 
	&&  ( my >= (_Context->y_Auto2708+100) ) 
	&&  ( mx <= (_Context->x_Auto2708+50+528) ) 
	&&  ( my <= (_Context->y_Auto2708+100+16))) {
		return(4); /* FormName2 */
		}
	if (( mx >= (_Context->x_Auto2708+30) ) 
	&&  ( my >= (_Context->y_Auto2708+130) ) 
	&&  ( mx <= (_Context->x_Auto2708+30+280) ) 
	&&  ( my <= (_Context->y_Auto2708+130+16))) {
		return(5); /* FixMsg */
		}
	if (( mx >= (_Context->x_Auto2708+320) ) 
	&&  ( my >= (_Context->y_Auto2708+130) ) 
	&&  ( mx <= (_Context->x_Auto2708+320+252) ) 
	&&  ( my <= (_Context->y_Auto2708+130+16))) {
		return(6); /* FixMethods */
		}
	if (( mx >= (_Context->x_Auto2708+30) ) 
	&&  ( my >= (_Context->y_Auto2708+160) ) 
	&&  ( mx <= (_Context->x_Auto2708+30+280) ) 
	&&  ( my <= (_Context->y_Auto2708+160+16))) {
		return(7); /* FixEvents */
		}
	if (( mx >= (_Context->x_Auto2708+320) ) 
	&&  ( my >= (_Context->y_Auto2708+160) ) 
	&&  ( mx <= (_Context->x_Auto2708+320+252) ) 
	&&  ( my <= (_Context->y_Auto2708+160+16))) {
		return(8); /* FixFormat */
		}
	if (( mx >= (_Context->x_Auto2708+30) ) 
	&&  ( my >= (_Context->y_Auto2708+190) ) 
	&&  ( mx <= (_Context->x_Auto2708+30+252) ) 
	&&  ( my <= (_Context->y_Auto2708+190+16))) {
		return(9); /* FixList */
		}
	if (( mx >= (_Context->x_Auto2708+320) ) 
	&&  ( my >= (_Context->y_Auto2708+190) ) 
	&&  ( mx <= (_Context->x_Auto2708+320+252) ) 
	&&  ( my <= (_Context->y_Auto2708+190+16))) {
		return(10); /* ShowMethod */
		}
	if (( mx >= (_Context->x_Auto2708+30) ) 
	&&  ( my >= (_Context->y_Auto2708+240) ) 
	&&  ( mx <= (_Context->x_Auto2708+30+544) ) 
	&&  ( my <= (_Context->y_Auto2708+240+16))) {
		return(11); /* DiffList */
		}
	if (( mx >= (_Context->x_Auto2708+10) ) 
	&&  ( my >= (_Context->y_Auto2708+290) ) 
	&&  ( mx <= (_Context->x_Auto2708+10+56) ) 
	&&  ( my <= (_Context->y_Auto2708+290+48))) {
		return(12); /* Accept */
		}

	return(-1);
}


public	int	accept_form_compare_focus(struct accept_form_compare_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_Auto2708+540,_Context->y_Auto2708+290,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto2708+540,_Context->y_Auto2708+290,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;
			case	0x4 :
				/* FormName2 */
				_Context->keycode = visual_edit(_Context->x_Auto2708+50+1,_Context->y_Auto2708+100+1,528,16,vfh[1],_Context->buffer_FormName2,255);
			break;
			case	0x5 :
				/* FixMsg */
				visual_check(_Context->x_Auto2708+30,_Context->y_Auto2708+130,280,16,vfh[2],27,28,_Context->msg_FixMsg[_Context->language],strlen(_Context->msg_FixMsg[_Context->language]),(_Context->value_FixMsg |2));
				_Context->keycode = visual_getch();
				_Context->trigger_FixMsg=visual_trigger_code(_Context->msg_FixMsg[_Context->language],strlen(_Context->msg_FixMsg[_Context->language]));
	visual_check(_Context->x_Auto2708+30,_Context->y_Auto2708+130,280,16,vfh[2],27,28,_Context->msg_FixMsg[_Context->language],strlen(_Context->msg_FixMsg[_Context->language]),_Context->value_FixMsg|0);
				break;
			case	0x6 :
				/* FixMethods */
				visual_check(_Context->x_Auto2708+320,_Context->y_Auto2708+130,252,16,vfh[2],27,28,_Context->msg_FixMethods[_Context->language],strlen(_Context->msg_FixMethods[_Context->language]),(_Context->value_FixMethods |2));
				_Context->keycode = visual_getch();
				_Context->trigger_FixMethods=visual_trigger_code(_Context->msg_FixMethods[_Context->language],strlen(_Context->msg_FixMethods[_Context->language]));
	visual_check(_Context->x_Auto2708+320,_Context->y_Auto2708+130,252,16,vfh[2],27,28,_Context->msg_FixMethods[_Context->language],strlen(_Context->msg_FixMethods[_Context->language]),_Context->value_FixMethods|0);
				break;
			case	0x7 :
				/* FixEvents */
				visual_check(_Context->x_Auto2708+30,_Context->y_Auto2708+160,280,16,vfh[2],27,28,_Context->msg_FixEvents[_Context->language],strlen(_Context->msg_FixEvents[_Context->language]),(_Context->value_FixEvents |2));
				_Context->keycode = visual_getch();
				_Context->trigger_FixEvents=visual_trigger_code(_Context->msg_FixEvents[_Context->language],strlen(_Context->msg_FixEvents[_Context->language]));
	visual_check(_Context->x_Auto2708+30,_Context->y_Auto2708+160,280,16,vfh[2],27,28,_Context->msg_FixEvents[_Context->language],strlen(_Context->msg_FixEvents[_Context->language]),_Context->value_FixEvents|0);
				break;
			case	0x8 :
				/* FixFormat */
				visual_check(_Context->x_Auto2708+320,_Context->y_Auto2708+160,252,16,vfh[2],27,28,_Context->msg_FixFormat[_Context->language],strlen(_Context->msg_FixFormat[_Context->language]),(_Context->value_FixFormat |2));
				_Context->keycode = visual_getch();
				_Context->trigger_FixFormat=visual_trigger_code(_Context->msg_FixFormat[_Context->language],strlen(_Context->msg_FixFormat[_Context->language]));
	visual_check(_Context->x_Auto2708+320,_Context->y_Auto2708+160,252,16,vfh[2],27,28,_Context->msg_FixFormat[_Context->language],strlen(_Context->msg_FixFormat[_Context->language]),_Context->value_FixFormat|0);
				break;
			case	0x9 :
				/* FixList */
				visual_check(_Context->x_Auto2708+30,_Context->y_Auto2708+190,252,16,vfh[2],27,28,_Context->msg_FixList[_Context->language],strlen(_Context->msg_FixList[_Context->language]),(_Context->value_FixList |2));
				_Context->keycode = visual_getch();
				_Context->trigger_FixList=visual_trigger_code(_Context->msg_FixList[_Context->language],strlen(_Context->msg_FixList[_Context->language]));
	visual_check(_Context->x_Auto2708+30,_Context->y_Auto2708+190,252,16,vfh[2],27,28,_Context->msg_FixList[_Context->language],strlen(_Context->msg_FixList[_Context->language]),_Context->value_FixList|0);
				break;
			case	0xa :
				/* ShowMethod */
				visual_check(_Context->x_Auto2708+320,_Context->y_Auto2708+190,252,16,vfh[2],27,28,_Context->msg_ShowMethod[_Context->language],strlen(_Context->msg_ShowMethod[_Context->language]),(_Context->value_ShowMethod |2));
				_Context->keycode = visual_getch();
				_Context->trigger_ShowMethod=visual_trigger_code(_Context->msg_ShowMethod[_Context->language],strlen(_Context->msg_ShowMethod[_Context->language]));
	visual_check(_Context->x_Auto2708+320,_Context->y_Auto2708+190,252,16,vfh[2],27,28,_Context->msg_ShowMethod[_Context->language],strlen(_Context->msg_ShowMethod[_Context->language]),_Context->value_ShowMethod|0);
				break;
			case	0xb :
				/* DiffList */
				_Context->keycode = visual_edit(_Context->x_Auto2708+30+1,_Context->y_Auto2708+240+1,544,16,vfh[1],_Context->buffer_DiffList,68);
			break;
			case	0xc :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(_Context->x_Auto2708+10,_Context->y_Auto2708+290,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto2708+10,_Context->y_Auto2708+290,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_form_compare_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=12;
			accept_form_compare_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_form_compare_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (Cancel_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (Accept_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto2708 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Auto2708+540,_Context->y_Auto2708+290,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto2708+540,_Context->y_Auto2708+290,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* FormName1 */
					continue;
				case	0x4 :
					/* FormName2 */
					continue;
				case	0x5 :
					/* FixMsg */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_FixMsg += 1;
						_Context->value_FixMsg &= 1;
						}
					continue;
				case	0x6 :
					/* FixMethods */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_FixMethods += 1;
						_Context->value_FixMethods &= 1;
						}
					continue;
				case	0x7 :
					/* FixEvents */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_FixEvents += 1;
						_Context->value_FixEvents &= 1;
						}
					continue;
				case	0x8 :
					/* FixFormat */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_FixFormat += 1;
						_Context->value_FixFormat &= 1;
						}
					continue;
				case	0x9 :
					/* FixList */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_FixList += 1;
						_Context->value_FixList &= 1;
						}
					continue;
				case	0xa :
					/* ShowMethod */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ShowMethod += 1;
						_Context->value_ShowMethod &= 1;
						}
					continue;
				case	0xb :
					/* DiffList */
					continue;
				case	0xc :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_Auto2708+10,_Context->y_Auto2708+290,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto2708+10,_Context->y_Auto2708+290,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

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
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_form_compare(
	char * pFormName1,
	char * pFormName2,
	char * pFixMsg,
	char * pFixMethods,
	char * pFixEvents,
	char * pFixFormat,
	char * pFixList,
	char * pShowMethod,
	char * pDiffList)
{
	int	status=0;
	struct accept_form_compare_context * _Context=(struct accept_form_compare_context*) 0;
	status = accept_form_compare_create(
	&_Context,
	 pFormName1,
	 pFormName2,
	 pFixMsg,
	 pFixMethods,
	 pFixEvents,
	 pFixFormat,
	 pFixList,
	 pShowMethod,
	 pDiffList);
	if ( status != 0) return(status);
	status = accept_form_compare_show(_Context);
		enter_modal();
	status = accept_form_compare_focus(_Context);
		leave_modal();
	status = accept_form_compare_hide(_Context);
	status = accept_form_compare_remove(
	_Context,
	 pFormName1,
	 pFormName2,
	 pFixMsg,
	 pFixMethods,
	 pFixEvents,
	 pFixFormat,
	 pFixList,
	 pShowMethod,
	 pDiffList);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcmpform_c */
