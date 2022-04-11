
#ifndef _vreader_c
#define _vreader_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : vreader.xml                                              */
/* Target         : vreader.c                                                */
/* Identification : 0.0-1196372571-3079.3078                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singlang.h"
#define en__auto2   ""
#define fr__auto2   ""
#define it__auto2   ""
#define es__auto2   ""
#define de__auto2   ""
#define nl__auto2   ""
#define pt__auto2   ""
#define xx__auto2   ""
#define en_Auto3333   "Database File Declaration from Abal Source"
#define fr_Auto3333   "Database File Declaration from Abal Source"
#define it_Auto3333   "Database File Declaration from Abal Source"
#define es_Auto3333   "Database File Declaration from Abal Source"
#define de_Auto3333   "Database File Declaration from Abal Source"
#define nl_Auto3333   "Database File Declaration from Abal Source"
#define pt_Auto3333   "Database File Declaration from Abal Source"
#define xx_Auto3333   "Database File Declaration from Abal Source"
#define en__Auto3333   ""
#define fr__Auto3333   ""
#define it__Auto3333   ""
#define es__Auto3333   ""
#define de__Auto3333   ""
#define nl__Auto3333   ""
#define pt__Auto3333   ""
#define xx__Auto3333   ""
#define en_Auto3334   "Source Filename"
#define fr_Auto3334   "Source Filename"
#define it_Auto3334   "Source Filename"
#define es_Auto3334   "Source Filename"
#define de_Auto3334   "Source Filename"
#define nl_Auto3334   "Source Filename"
#define pt_Auto3334   "Source Filename"
#define xx_Auto3334   "Source Filename"
#define en__Auto3334   ""
#define fr__Auto3334   ""
#define it__Auto3334   ""
#define es__Auto3334   ""
#define de__Auto3334   ""
#define nl__Auto3334   ""
#define pt__Auto3334   ""
#define xx__Auto3334   ""
#define en_Auto3335   "File Classname"
#define fr_Auto3335   "File Classname"
#define it_Auto3335   "File Classname"
#define es_Auto3335   "File Classname"
#define de_Auto3335   "File Classname"
#define nl_Auto3335   "File Classname"
#define pt_Auto3335   "File Classname"
#define xx_Auto3335   "File Classname"
#define en__Auto3335   ""
#define fr__Auto3335   ""
#define it__Auto3335   ""
#define es__Auto3335   ""
#define de__Auto3335   ""
#define nl__Auto3335   ""
#define pt__Auto3335   ""
#define xx__Auto3335   ""
#define en_Auto3336   "File Instance name"
#define fr_Auto3336   "File Instancename"
#define it_Auto3336   "File Instancename"
#define es_Auto3336   "File Instancename"
#define de_Auto3336   "File Instancename"
#define nl_Auto3336   "File Instancename"
#define pt_Auto3336   "File Instancename"
#define xx_Auto3336   "File Instancename"
#define en__Auto3336   ""
#define fr__Auto3336   ""
#define it__Auto3336   ""
#define es__Auto3336   ""
#define de__Auto3336   ""
#define nl__Auto3336   ""
#define pt__Auto3336   ""
#define xx__Auto3336   ""
#define en_Auto3337   "Data Filename"
#define fr_Auto3337   "Data Filename"
#define it_Auto3337   "Data Filename"
#define es_Auto3337   "Data Filename"
#define de_Auto3337   "Data Filename"
#define nl_Auto3337   "Data Filename"
#define pt_Auto3337   "Data Filename"
#define xx_Auto3337   "Data Filename"
#define en__Auto3337   ""
#define fr__Auto3337   ""
#define it__Auto3337   ""
#define es__Auto3337   ""
#define de__Auto3337   ""
#define nl__Auto3337   ""
#define pt__Auto3337   ""
#define xx__Auto3337   ""
#define en_Auto3338   "Index Variable Name"
#define fr_Auto3338   "Index Variable Name"
#define it_Auto3338   "Index Variable Name"
#define es_Auto3338   "Index Variable Name"
#define de_Auto3338   "Index Variable Name"
#define nl_Auto3338   "Index Variable Name"
#define pt_Auto3338   "Index Variable Name"
#define xx_Auto3338   "Index Variable Name"
#define en__Auto3338   ""
#define fr__Auto3338   ""
#define it__Auto3338   ""
#define es__Auto3338   ""
#define de__Auto3338   ""
#define nl__Auto3338   ""
#define pt__Auto3338   ""
#define xx__Auto3338   ""
#define en_Auto3339   "Marker Variable Name"
#define fr_Auto3339   "Index Variable Name"
#define it_Auto3339   "Index Variable Name"
#define es_Auto3339   "Index Variable Name"
#define de_Auto3339   "Index Variable Name"
#define nl_Auto3339   "Index Variable Name"
#define pt_Auto3339   "Index Variable Name"
#define xx_Auto3339   "Index Variable Name"
#define en__Auto3339   ""
#define fr__Auto3339   ""
#define it__Auto3339   ""
#define es__Auto3339   ""
#define de__Auto3339   ""
#define nl__Auto3339   ""
#define pt__Auto3339   ""
#define xx__Auto3339   ""
#define en_Auto3340   "Record Variable Name"
#define fr_Auto3340   "Record Variable Name"
#define it_Auto3340   "Record Variable Name"
#define es_Auto3340   "Record Variable Name"
#define de_Auto3340   "Record Variable Name"
#define nl_Auto3340   "Record Variable Name"
#define pt_Auto3340   "Record Variable Name"
#define xx_Auto3340   "Record Variable Name"
#define en__Auto3340   ""
#define fr__Auto3340   ""
#define it__Auto3340   ""
#define es__Auto3340   ""
#define de__Auto3340   ""
#define nl__Auto3340   ""
#define pt__Auto3340   ""
#define xx__Auto3340   ""
#define en_Auto3341   "Name Conversion"
#define fr_Auto3341   "Name Conversion"
#define it_Auto3341   "Name Conversion"
#define es_Auto3341   "Name Conversion"
#define de_Auto3341   "Name Conversion"
#define nl_Auto3341   "Name Conversion"
#define pt_Auto3341   "Name Conversion"
#define xx_Auto3341   "Name Conversion"
#define en__Auto3341   ""
#define fr__Auto3341   ""
#define it__Auto3341   ""
#define es__Auto3341   ""
#define de__Auto3341   ""
#define nl__Auto3341   ""
#define pt__Auto3341   ""
#define xx__Auto3341   ""
#define en_Accept   "ok.gif"
#define en__Accept   ""
#define en_Cancel   "cancel.gif"
#define en__Cancel   ""
#define en_IncludeName   ""
#define en__IncludeName   ""
#define en_EditStyle   "edit"
#define fr_EditStyle   "edit"
#define it_EditStyle   "edit"
#define es_EditStyle   "edit"
#define de_EditStyle   "edit"
#define nl_EditStyle   "edit"
#define pt_EditStyle   "edit"
#define xx_EditStyle   "edit"
#define en__EditStyle   ""
#define fr__EditStyle   ""
#define it__EditStyle   ""
#define es__EditStyle   ""
#define de__EditStyle   ""
#define nl__EditStyle   ""
#define pt__EditStyle   ""
#define xx__EditStyle   ""
#define en_ClassName   ""
#define en__ClassName   ""
#define en_InstanceName   ""
#define en__InstanceName   ""
#define en_DataFileName   ""
#define en__DataFileName   ""
#define en_IndexName   ""
#define en__IndexName   ""
#define en_MarkerName   ""
#define en__MarkerName   ""
#define en_RecordName   ""
#define en__RecordName   ""
#define en_ConvertCase   "convert to uppercase|convert to lowercase|preserve original case"
#define en__ConvertCase   ""

private struct accept_inclusion_parameters_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_auto2[8];
	char * hint_auto2[8];
	int	x_auto2;
	int	y_auto2;
	int	w_auto2;
	int	h_auto2;
	char * msg_Auto3333[8];
	char * hint_Auto3333[8];
	char * msg_Auto3334[8];
	char * hint_Auto3334[8];
	char * msg_Auto3335[8];
	char * hint_Auto3335[8];
	char * msg_Auto3336[8];
	char * hint_Auto3336[8];
	char * msg_Auto3337[8];
	char * hint_Auto3337[8];
	char * msg_Auto3338[8];
	char * hint_Auto3338[8];
	char * msg_Auto3339[8];
	char * hint_Auto3339[8];
	char * msg_Auto3340[8];
	char * hint_Auto3340[8];
	char * msg_Auto3341[8];
	char * hint_Auto3341[8];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	char * hint_IncludeName[8];
	char	buffer_IncludeName[256];
	char * msg_EditStyle[8];
	int	trigger_EditStyle;
	char * hint_EditStyle[8];
	char * hint_ClassName[8];
	char	buffer_ClassName[256];
	char * hint_InstanceName[8];
	char	buffer_InstanceName[256];
	char * hint_DataFileName[8];
	char	buffer_DataFileName[256];
	char * hint_IndexName[8];
	char	buffer_IndexName[256];
	char * hint_MarkerName[8];
	char	buffer_MarkerName[256];
	char * hint_RecordName[8];
	char	buffer_RecordName[256];
	char * msg_ConvertCase[8];
	char * hint_ConvertCase[8];
	int	value_ConvertCase;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[9];
	};
static int	vfh[16];

public	int	accept_inclusion_parameters_create(
	struct accept_inclusion_parameters_context ** cptr,
	char * pIncludeName,
	char * pClassName,
	char * pInstanceName,
	char * pDataFileName,
	char * pIndexName,
	char * pMarkerName,
	char * pRecordName,
	char * pConvertCase)
{

	int i;
	struct accept_inclusion_parameters_context * _Context=(struct accept_inclusion_parameters_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_inclusion_parameters_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=11;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSSW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_IncludeName, 255, pIncludeName);
		visual_transferin(_Context->buffer_ClassName, 255, pClassName);
		visual_transferin(_Context->buffer_InstanceName, 255, pInstanceName);
		visual_transferin(_Context->buffer_DataFileName, 255, pDataFileName);
		visual_transferin(_Context->buffer_IndexName, 255, pIndexName);
		visual_transferin(_Context->buffer_MarkerName, 255, pMarkerName);
		visual_transferin(_Context->buffer_RecordName, 255, pRecordName);
		visual_transferin((void *) 0, 0, pConvertCase);
		if (!( pConvertCase )) _Context->value_ConvertCase=0;
		else	_Context->value_ConvertCase = *((int *)pConvertCase);
		}
	for (i=0; i < 8; i++)_Context->msg_auto2[i]=" ";
	_Context->hint_auto2[0]=en__auto2;
	_Context->hint_auto2[1]=fr__auto2;
	_Context->hint_auto2[2]=it__auto2;
	_Context->hint_auto2[3]=es__auto2;
	_Context->hint_auto2[4]=de__auto2;
	_Context->hint_auto2[5]=nl__auto2;
	_Context->hint_auto2[6]=pt__auto2;
	_Context->hint_auto2[7]=xx__auto2;
	_Context->x_auto2=50;
	_Context->y_auto2=140;
	_Context->w_auto2=700;
	_Context->h_auto2=320;
	_Context->window_col=0;
	_Context->window_row=0;
	if(((_Context->y_auto2=visual_event(6))+320)>hardrows())
	_Context->y_auto2=(hardrows()-320);
	if(((_Context->x_auto2=visual_event(7))+700)>hardcolumns())
	_Context->x_auto2=(hardcolumns()-700);
	for (i=0; i < 8; i++)_Context->msg_Auto3333[i]=" ";
	_Context->msg_Auto3333[0]=en_Auto3333;
	_Context->msg_Auto3333[1]=fr_Auto3333;
	_Context->msg_Auto3333[2]=it_Auto3333;
	_Context->msg_Auto3333[3]=es_Auto3333;
	_Context->msg_Auto3333[4]=de_Auto3333;
	_Context->msg_Auto3333[5]=nl_Auto3333;
	_Context->msg_Auto3333[6]=pt_Auto3333;
	_Context->msg_Auto3333[7]=xx_Auto3333;
	_Context->hint_Auto3333[0]=en__Auto3333;
	_Context->hint_Auto3333[1]=fr__Auto3333;
	_Context->hint_Auto3333[2]=it__Auto3333;
	_Context->hint_Auto3333[3]=es__Auto3333;
	_Context->hint_Auto3333[4]=de__Auto3333;
	_Context->hint_Auto3333[5]=nl__Auto3333;
	_Context->hint_Auto3333[6]=pt__Auto3333;
	_Context->hint_Auto3333[7]=xx__Auto3333;
	for (i=0; i < 8; i++)_Context->msg_Auto3334[i]=" ";
	_Context->msg_Auto3334[0]=en_Auto3334;
	_Context->msg_Auto3334[1]=fr_Auto3334;
	_Context->msg_Auto3334[2]=it_Auto3334;
	_Context->msg_Auto3334[3]=es_Auto3334;
	_Context->msg_Auto3334[4]=de_Auto3334;
	_Context->msg_Auto3334[5]=nl_Auto3334;
	_Context->msg_Auto3334[6]=pt_Auto3334;
	_Context->msg_Auto3334[7]=xx_Auto3334;
	_Context->hint_Auto3334[0]=en__Auto3334;
	_Context->hint_Auto3334[1]=fr__Auto3334;
	_Context->hint_Auto3334[2]=it__Auto3334;
	_Context->hint_Auto3334[3]=es__Auto3334;
	_Context->hint_Auto3334[4]=de__Auto3334;
	_Context->hint_Auto3334[5]=nl__Auto3334;
	_Context->hint_Auto3334[6]=pt__Auto3334;
	_Context->hint_Auto3334[7]=xx__Auto3334;
	for (i=0; i < 8; i++)_Context->msg_Auto3335[i]=" ";
	_Context->msg_Auto3335[0]=en_Auto3335;
	_Context->msg_Auto3335[1]=fr_Auto3335;
	_Context->msg_Auto3335[2]=it_Auto3335;
	_Context->msg_Auto3335[3]=es_Auto3335;
	_Context->msg_Auto3335[4]=de_Auto3335;
	_Context->msg_Auto3335[5]=nl_Auto3335;
	_Context->msg_Auto3335[6]=pt_Auto3335;
	_Context->msg_Auto3335[7]=xx_Auto3335;
	_Context->hint_Auto3335[0]=en__Auto3335;
	_Context->hint_Auto3335[1]=fr__Auto3335;
	_Context->hint_Auto3335[2]=it__Auto3335;
	_Context->hint_Auto3335[3]=es__Auto3335;
	_Context->hint_Auto3335[4]=de__Auto3335;
	_Context->hint_Auto3335[5]=nl__Auto3335;
	_Context->hint_Auto3335[6]=pt__Auto3335;
	_Context->hint_Auto3335[7]=xx__Auto3335;
	for (i=0; i < 8; i++)_Context->msg_Auto3336[i]=" ";
	_Context->msg_Auto3336[0]=en_Auto3336;
	_Context->msg_Auto3336[1]=fr_Auto3336;
	_Context->msg_Auto3336[2]=it_Auto3336;
	_Context->msg_Auto3336[3]=es_Auto3336;
	_Context->msg_Auto3336[4]=de_Auto3336;
	_Context->msg_Auto3336[5]=nl_Auto3336;
	_Context->msg_Auto3336[6]=pt_Auto3336;
	_Context->msg_Auto3336[7]=xx_Auto3336;
	_Context->hint_Auto3336[0]=en__Auto3336;
	_Context->hint_Auto3336[1]=fr__Auto3336;
	_Context->hint_Auto3336[2]=it__Auto3336;
	_Context->hint_Auto3336[3]=es__Auto3336;
	_Context->hint_Auto3336[4]=de__Auto3336;
	_Context->hint_Auto3336[5]=nl__Auto3336;
	_Context->hint_Auto3336[6]=pt__Auto3336;
	_Context->hint_Auto3336[7]=xx__Auto3336;
	for (i=0; i < 8; i++)_Context->msg_Auto3337[i]=" ";
	_Context->msg_Auto3337[0]=en_Auto3337;
	_Context->msg_Auto3337[1]=fr_Auto3337;
	_Context->msg_Auto3337[2]=it_Auto3337;
	_Context->msg_Auto3337[3]=es_Auto3337;
	_Context->msg_Auto3337[4]=de_Auto3337;
	_Context->msg_Auto3337[5]=nl_Auto3337;
	_Context->msg_Auto3337[6]=pt_Auto3337;
	_Context->msg_Auto3337[7]=xx_Auto3337;
	_Context->hint_Auto3337[0]=en__Auto3337;
	_Context->hint_Auto3337[1]=fr__Auto3337;
	_Context->hint_Auto3337[2]=it__Auto3337;
	_Context->hint_Auto3337[3]=es__Auto3337;
	_Context->hint_Auto3337[4]=de__Auto3337;
	_Context->hint_Auto3337[5]=nl__Auto3337;
	_Context->hint_Auto3337[6]=pt__Auto3337;
	_Context->hint_Auto3337[7]=xx__Auto3337;
	for (i=0; i < 8; i++)_Context->msg_Auto3338[i]=" ";
	_Context->msg_Auto3338[0]=en_Auto3338;
	_Context->msg_Auto3338[1]=fr_Auto3338;
	_Context->msg_Auto3338[2]=it_Auto3338;
	_Context->msg_Auto3338[3]=es_Auto3338;
	_Context->msg_Auto3338[4]=de_Auto3338;
	_Context->msg_Auto3338[5]=nl_Auto3338;
	_Context->msg_Auto3338[6]=pt_Auto3338;
	_Context->msg_Auto3338[7]=xx_Auto3338;
	_Context->hint_Auto3338[0]=en__Auto3338;
	_Context->hint_Auto3338[1]=fr__Auto3338;
	_Context->hint_Auto3338[2]=it__Auto3338;
	_Context->hint_Auto3338[3]=es__Auto3338;
	_Context->hint_Auto3338[4]=de__Auto3338;
	_Context->hint_Auto3338[5]=nl__Auto3338;
	_Context->hint_Auto3338[6]=pt__Auto3338;
	_Context->hint_Auto3338[7]=xx__Auto3338;
	for (i=0; i < 8; i++)_Context->msg_Auto3339[i]=" ";
	_Context->msg_Auto3339[0]=en_Auto3339;
	_Context->msg_Auto3339[1]=fr_Auto3339;
	_Context->msg_Auto3339[2]=it_Auto3339;
	_Context->msg_Auto3339[3]=es_Auto3339;
	_Context->msg_Auto3339[4]=de_Auto3339;
	_Context->msg_Auto3339[5]=nl_Auto3339;
	_Context->msg_Auto3339[6]=pt_Auto3339;
	_Context->msg_Auto3339[7]=xx_Auto3339;
	_Context->hint_Auto3339[0]=en__Auto3339;
	_Context->hint_Auto3339[1]=fr__Auto3339;
	_Context->hint_Auto3339[2]=it__Auto3339;
	_Context->hint_Auto3339[3]=es__Auto3339;
	_Context->hint_Auto3339[4]=de__Auto3339;
	_Context->hint_Auto3339[5]=nl__Auto3339;
	_Context->hint_Auto3339[6]=pt__Auto3339;
	_Context->hint_Auto3339[7]=xx__Auto3339;
	for (i=0; i < 8; i++)_Context->msg_Auto3340[i]=" ";
	_Context->msg_Auto3340[0]=en_Auto3340;
	_Context->msg_Auto3340[1]=fr_Auto3340;
	_Context->msg_Auto3340[2]=it_Auto3340;
	_Context->msg_Auto3340[3]=es_Auto3340;
	_Context->msg_Auto3340[4]=de_Auto3340;
	_Context->msg_Auto3340[5]=nl_Auto3340;
	_Context->msg_Auto3340[6]=pt_Auto3340;
	_Context->msg_Auto3340[7]=xx_Auto3340;
	_Context->hint_Auto3340[0]=en__Auto3340;
	_Context->hint_Auto3340[1]=fr__Auto3340;
	_Context->hint_Auto3340[2]=it__Auto3340;
	_Context->hint_Auto3340[3]=es__Auto3340;
	_Context->hint_Auto3340[4]=de__Auto3340;
	_Context->hint_Auto3340[5]=nl__Auto3340;
	_Context->hint_Auto3340[6]=pt__Auto3340;
	_Context->hint_Auto3340[7]=xx__Auto3340;
	for (i=0; i < 8; i++)_Context->msg_Auto3341[i]=" ";
	_Context->msg_Auto3341[0]=en_Auto3341;
	_Context->msg_Auto3341[1]=fr_Auto3341;
	_Context->msg_Auto3341[2]=it_Auto3341;
	_Context->msg_Auto3341[3]=es_Auto3341;
	_Context->msg_Auto3341[4]=de_Auto3341;
	_Context->msg_Auto3341[5]=nl_Auto3341;
	_Context->msg_Auto3341[6]=pt_Auto3341;
	_Context->msg_Auto3341[7]=xx_Auto3341;
	_Context->hint_Auto3341[0]=en__Auto3341;
	_Context->hint_Auto3341[1]=fr__Auto3341;
	_Context->hint_Auto3341[2]=it__Auto3341;
	_Context->hint_Auto3341[3]=es__Auto3341;
	_Context->hint_Auto3341[4]=de__Auto3341;
	_Context->hint_Auto3341[5]=nl__Auto3341;
	_Context->hint_Auto3341[6]=pt__Auto3341;
	_Context->hint_Auto3341[7]=xx__Auto3341;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->hint_Accept[0]=en__Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->hint_Cancel[0]=en__Cancel;
	_Context->hint_IncludeName[0]=en__IncludeName;
	for (i=0; i < 8; i++)_Context->msg_EditStyle[i]=" ";
	_Context->msg_EditStyle[0]=en_EditStyle;
	_Context->msg_EditStyle[1]=fr_EditStyle;
	_Context->msg_EditStyle[2]=it_EditStyle;
	_Context->msg_EditStyle[3]=es_EditStyle;
	_Context->msg_EditStyle[4]=de_EditStyle;
	_Context->msg_EditStyle[5]=nl_EditStyle;
	_Context->msg_EditStyle[6]=pt_EditStyle;
	_Context->msg_EditStyle[7]=xx_EditStyle;
	_Context->hint_EditStyle[0]=en__EditStyle;
	_Context->hint_EditStyle[1]=fr__EditStyle;
	_Context->hint_EditStyle[2]=it__EditStyle;
	_Context->hint_EditStyle[3]=es__EditStyle;
	_Context->hint_EditStyle[4]=de__EditStyle;
	_Context->hint_EditStyle[5]=nl__EditStyle;
	_Context->hint_EditStyle[6]=pt__EditStyle;
	_Context->hint_EditStyle[7]=xx__EditStyle;
	_Context->hint_ClassName[0]=en__ClassName;
	_Context->hint_InstanceName[0]=en__InstanceName;
	_Context->hint_DataFileName[0]=en__DataFileName;
	_Context->hint_IndexName[0]=en__IndexName;
	_Context->hint_MarkerName[0]=en__MarkerName;
	_Context->hint_RecordName[0]=en__RecordName;
	for (i=0; i < 8; i++)_Context->msg_ConvertCase[i]=" ";
	_Context->msg_ConvertCase[0]=en_ConvertCase;
	_Context->hint_ConvertCase[0]=en__ConvertCase;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto2,_Context->y_auto2,700+10,320+10);
	return(0);
}

public 	int	accept_inclusion_parameters_hide(struct accept_inclusion_parameters_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_auto2,_Context->y_auto2);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_inclusion_parameters_remove(
	struct accept_inclusion_parameters_context * _Context,
	char * pIncludeName,
	char * pClassName,
	char * pInstanceName,
	char * pDataFileName,
	char * pIndexName,
	char * pMarkerName,
	char * pRecordName,
	char * pConvertCase)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSSW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_IncludeName, 255, pIncludeName);
		visual_transferout(_Context->buffer_ClassName, 255, pClassName);
		visual_transferout(_Context->buffer_InstanceName, 255, pInstanceName);
		visual_transferout(_Context->buffer_DataFileName, 255, pDataFileName);
		visual_transferout(_Context->buffer_IndexName, 255, pIndexName);
		visual_transferout(_Context->buffer_MarkerName, 255, pMarkerName);
		visual_transferout(_Context->buffer_RecordName, 255, pRecordName);
		visual_transferout((void *) 0, 0, pConvertCase);
		if ( pConvertCase != (char *) 0)
			*((int*)pConvertCase) = _Context->value_ConvertCase;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_inclusion_parameters_show(struct accept_inclusion_parameters_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto2,_Context->y_auto2);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_auto2,_Context->y_auto2,700,320,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_auto2,_Context->y_auto2,700,320,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_auto2+20,_Context->y_auto2+30,660,30,vfh[3],16,0,_Context->msg_Auto3333[_Context->language],strlen(_Context->msg_Auto3333[_Context->language]),1283);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+80,136,16,vfh[2],16,0,_Context->msg_Auto3334[_Context->language],strlen(_Context->msg_Auto3334[_Context->language]),1282);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+110,136,16,vfh[2],16,0,_Context->msg_Auto3335[_Context->language],strlen(_Context->msg_Auto3335[_Context->language]),1282);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+130,136,16,vfh[2],16,0,_Context->msg_Auto3336[_Context->language],strlen(_Context->msg_Auto3336[_Context->language]),1282);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+150,136,16,vfh[2],16,0,_Context->msg_Auto3337[_Context->language],strlen(_Context->msg_Auto3337[_Context->language]),1282);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+180,136,16,vfh[2],16,0,_Context->msg_Auto3338[_Context->language],strlen(_Context->msg_Auto3338[_Context->language]),1282);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+200,136,16,vfh[2],16,0,_Context->msg_Auto3339[_Context->language],strlen(_Context->msg_Auto3339[_Context->language]),1282);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+220,136,16,vfh[2],16,0,_Context->msg_Auto3340[_Context->language],strlen(_Context->msg_Auto3340[_Context->language]),1282);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+250,136,16,vfh[2],16,0,_Context->msg_Auto3341[_Context->language],strlen(_Context->msg_Auto3341[_Context->language]),1282);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_auto2+570,_Context->y_auto2+250,48,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto2+630,_Context->y_auto2+250,48,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_frame(_Context->x_auto2+160,_Context->y_auto2+80,480+2,16+2,5);
	visual_text(_Context->x_auto2+160+1,_Context->y_auto2+80+1,480,16,vfh[1],27,28,_Context->buffer_IncludeName,255,0);
	_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
	visual_button(_Context->x_auto2+650,_Context->y_auto2+80,32,16,vfh[8],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),768);
	visual_frame(_Context->x_auto2+160,_Context->y_auto2+110,520+2,16+2,5);
	visual_text(_Context->x_auto2+160+1,_Context->y_auto2+110+1,520,16,vfh[1],27,28,_Context->buffer_ClassName,255,0);
	visual_frame(_Context->x_auto2+160,_Context->y_auto2+130,520+2,16+2,5);
	visual_text(_Context->x_auto2+160+1,_Context->y_auto2+130+1,520,16,vfh[1],27,28,_Context->buffer_InstanceName,255,0);
	visual_frame(_Context->x_auto2+160,_Context->y_auto2+150,520+2,16+2,5);
	visual_text(_Context->x_auto2+160+1,_Context->y_auto2+150+1,520,16,vfh[1],27,28,_Context->buffer_DataFileName,255,0);
	visual_frame(_Context->x_auto2+160,_Context->y_auto2+180,520+2,16+2,5);
	visual_text(_Context->x_auto2+160+1,_Context->y_auto2+180+1,520,16,vfh[1],27,28,_Context->buffer_IndexName,255,0);
	visual_frame(_Context->x_auto2+160,_Context->y_auto2+200,520+2,16+2,5);
	visual_text(_Context->x_auto2+160+1,_Context->y_auto2+200+1,520,16,vfh[1],27,28,_Context->buffer_MarkerName,255,0);
	visual_frame(_Context->x_auto2+160,_Context->y_auto2+220,520+2,16+2,5);
	visual_text(_Context->x_auto2+160+1,_Context->y_auto2+220+1,520,16,vfh[1],27,28,_Context->buffer_RecordName,255,0);
	visual_select(_Context->x_auto2+160,_Context->y_auto2+250,182,64,vfh[2],0,0,parse_selection(_Context->msg_ConvertCase[_Context->language],&_Context->value_ConvertCase),768);
	visual_thaw(_Context->x_auto2,_Context->y_auto2,700,320);

	return(0);
}

private int auto2action(struct accept_inclusion_parameters_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_inclusion_parameters_hide(_Context);

		_Context->x_auto2 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto2 < 0) { _Context->x_auto2=0; }
		_Context->y_auto2 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto2 < 0) { _Context->y_auto2=0; }
			accept_inclusion_parameters_show(_Context);

		visual_thaw(_Context->x_auto2,_Context->y_auto2,700,320);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_inclusion_parameters_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_inclusion_parameters_context * _Context) {
	return(27);
	return(-1);
}
private int on_EditStyle_event(struct accept_inclusion_parameters_context * _Context) {
		accept_inclusion_parameters_hide(_Context);
;
	use_editor(_Context->buffer_IncludeName,_GENERATE_BAL);
		accept_inclusion_parameters_show(_Context);
;
	return(-1);
}


public	int	accept_inclusion_parameters_event(
struct accept_inclusion_parameters_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(1);
		if (_Context->trigger_Cancel == mb ) return(2);
		if (_Context->trigger_EditStyle == mb ) return(4);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_auto2+570) ) 
	&&  ( my >= (_Context->y_auto2+250) ) 
	&&  ( mx <= (_Context->x_auto2+570+48) ) 
	&&  ( my <= (_Context->y_auto2+250+48))) {
		return(1); /* Accept */
		}
	if (( mx >= (_Context->x_auto2+630) ) 
	&&  ( my >= (_Context->y_auto2+250) ) 
	&&  ( mx <= (_Context->x_auto2+630+48) ) 
	&&  ( my <= (_Context->y_auto2+250+48))) {
		return(2); /* Cancel */
		}
	if (( mx >= (_Context->x_auto2+160) ) 
	&&  ( my >= (_Context->y_auto2+80) ) 
	&&  ( mx <= (_Context->x_auto2+160+480) ) 
	&&  ( my <= (_Context->y_auto2+80+16))) {
		return(3); /* IncludeName */
		}
	if (( mx >= (_Context->x_auto2+650) ) 
	&&  ( my >= (_Context->y_auto2+80) ) 
	&&  ( mx <= (_Context->x_auto2+650+32) ) 
	&&  ( my <= (_Context->y_auto2+80+16))) {
		return(4); /* EditStyle */
		}
	if (( mx >= (_Context->x_auto2+160) ) 
	&&  ( my >= (_Context->y_auto2+110) ) 
	&&  ( mx <= (_Context->x_auto2+160+520) ) 
	&&  ( my <= (_Context->y_auto2+110+16))) {
		return(5); /* ClassName */
		}
	if (( mx >= (_Context->x_auto2+160) ) 
	&&  ( my >= (_Context->y_auto2+130) ) 
	&&  ( mx <= (_Context->x_auto2+160+520) ) 
	&&  ( my <= (_Context->y_auto2+130+16))) {
		return(6); /* InstanceName */
		}
	if (( mx >= (_Context->x_auto2+160) ) 
	&&  ( my >= (_Context->y_auto2+150) ) 
	&&  ( mx <= (_Context->x_auto2+160+520) ) 
	&&  ( my <= (_Context->y_auto2+150+16))) {
		return(7); /* DataFileName */
		}
	if (( mx >= (_Context->x_auto2+160) ) 
	&&  ( my >= (_Context->y_auto2+180) ) 
	&&  ( mx <= (_Context->x_auto2+160+520) ) 
	&&  ( my <= (_Context->y_auto2+180+16))) {
		return(8); /* IndexName */
		}
	if (( mx >= (_Context->x_auto2+160) ) 
	&&  ( my >= (_Context->y_auto2+200) ) 
	&&  ( mx <= (_Context->x_auto2+160+520) ) 
	&&  ( my <= (_Context->y_auto2+200+16))) {
		return(9); /* MarkerName */
		}
	if (( mx >= (_Context->x_auto2+160) ) 
	&&  ( my >= (_Context->y_auto2+220) ) 
	&&  ( mx <= (_Context->x_auto2+160+520) ) 
	&&  ( my <= (_Context->y_auto2+220+16))) {
		return(10); /* RecordName */
		}
	if (( mx >= (_Context->x_auto2+160+0) ) 
	&&  ( my >= (_Context->y_auto2+250) ) 
	&&  ( mx <= (_Context->x_auto2+160+182) ) 
	&&  ( my <= (_Context->y_auto2+250+16))) {
		return(11); /* ConvertCase */
		}

	return(-1);
}


public	int	accept_inclusion_parameters_focus(struct accept_inclusion_parameters_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(_Context->x_auto2+570,_Context->y_auto2+250,48,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_auto2+570,_Context->y_auto2+250,48,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0x2 :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_auto2+630,_Context->y_auto2+250,48,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto2+630,_Context->y_auto2+250,48,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;
			case	0x3 :
				/* IncludeName */
				_Context->keycode = visual_edit(_Context->x_auto2+160+1,_Context->y_auto2+80+1,480,16,vfh[1],_Context->buffer_IncludeName,255);
			break;
			case	0x4 :
				/* EditStyle */
				_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
				visual_button(_Context->x_auto2+650,_Context->y_auto2+80,32,16,vfh[8],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),770);
				_Context->keycode = visual_getch();
				_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
	visual_button(_Context->x_auto2+650,_Context->y_auto2+80,32,16,vfh[8],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),768);
				break;
			case	0x5 :
				/* ClassName */
				_Context->keycode = visual_edit(_Context->x_auto2+160+1,_Context->y_auto2+110+1,520,16,vfh[1],_Context->buffer_ClassName,255);
			break;
			case	0x6 :
				/* InstanceName */
				_Context->keycode = visual_edit(_Context->x_auto2+160+1,_Context->y_auto2+130+1,520,16,vfh[1],_Context->buffer_InstanceName,255);
			break;
			case	0x7 :
				/* DataFileName */
				_Context->keycode = visual_edit(_Context->x_auto2+160+1,_Context->y_auto2+150+1,520,16,vfh[1],_Context->buffer_DataFileName,255);
			break;
			case	0x8 :
				/* IndexName */
				_Context->keycode = visual_edit(_Context->x_auto2+160+1,_Context->y_auto2+180+1,520,16,vfh[1],_Context->buffer_IndexName,255);
			break;
			case	0x9 :
				/* MarkerName */
				_Context->keycode = visual_edit(_Context->x_auto2+160+1,_Context->y_auto2+200+1,520,16,vfh[1],_Context->buffer_MarkerName,255);
			break;
			case	0xa :
				/* RecordName */
				_Context->keycode = visual_edit(_Context->x_auto2+160+1,_Context->y_auto2+220+1,520,16,vfh[1],_Context->buffer_RecordName,255);
			break;
			case	0xb :
				/* ConvertCase */
				_Context->keycode = visual_select(_Context->x_auto2+160,_Context->y_auto2+250,182,64,vfh[2],0,0,parse_selection(_Context->msg_ConvertCase[_Context->language],&_Context->value_ConvertCase),770);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_inclusion_parameters_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=11;
			accept_inclusion_parameters_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_inclusion_parameters_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_auto2+570,_Context->y_auto2+250,48,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_auto2+570,_Context->y_auto2+250,48,48,vfh[1],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_auto2+630,_Context->y_auto2+250,48,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto2+630,_Context->y_auto2+250,48,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* IncludeName */
					continue;
				case	0x4 :
					/* EditStyle */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
						visual_button(_Context->x_auto2+650,_Context->y_auto2+80,32,16,vfh[8],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),770);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
	visual_button(_Context->x_auto2+650,_Context->y_auto2+80,32,16,vfh[8],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),768);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_EditStyle_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* ClassName */
					continue;
				case	0x6 :
					/* InstanceName */
					continue;
				case	0x7 :
					/* DataFileName */
					continue;
				case	0x8 :
					/* IndexName */
					continue;
				case	0x9 :
					/* MarkerName */
					continue;
				case	0xa :
					/* RecordName */
					continue;
				case	0xb :
					/* ConvertCase */
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

public	int	accept_inclusion_parameters(
	char * pIncludeName,
	char * pClassName,
	char * pInstanceName,
	char * pDataFileName,
	char * pIndexName,
	char * pMarkerName,
	char * pRecordName,
	char * pConvertCase)
{
	int	status=0;
	struct accept_inclusion_parameters_context * _Context=(struct accept_inclusion_parameters_context*) 0;
	status = accept_inclusion_parameters_create(
	&_Context,
	 pIncludeName,
	 pClassName,
	 pInstanceName,
	 pDataFileName,
	 pIndexName,
	 pMarkerName,
	 pRecordName,
	 pConvertCase);
	if ( status != 0) return(status);
	status = accept_inclusion_parameters_show(_Context);
		enter_modal();
	status = accept_inclusion_parameters_focus(_Context);
		leave_modal();
	status = accept_inclusion_parameters_hide(_Context);
	status = accept_inclusion_parameters_remove(
	_Context,
	 pIncludeName,
	 pClassName,
	 pInstanceName,
	 pDataFileName,
	 pIndexName,
	 pMarkerName,
	 pRecordName,
	 pConvertCase);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vreader_c */
