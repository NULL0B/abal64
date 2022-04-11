
#ifndef _vreader_c
#define _vreader_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vreader.xml                                              */
/* Target         : vreader.c                                                */
/* Identification : 0.0-1334659660-14025.1163                                */
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
#define en_Auto3634   "Database File Declaration from Abal Source"
#define fr_Auto3634   "Import de D‚clarations de donn‚es d'Abal"
#define it_Auto3634   "Database File Declaration from Abal Source"
#define es_Auto3634   "Database File Declaration from Abal Source"
#define de_Auto3634   "Database File Declaration from Abal Source"
#define nl_Auto3634   "Database File Declaration from Abal Source"
#define pt_Auto3634   "Database File Declaration from Abal Source"
#define xx_Auto3634   "Database File Declaration from Abal Source"
#define en__Auto3634   ""
#define fr__Auto3634   ""
#define it__Auto3634   ""
#define es__Auto3634   ""
#define de__Auto3634   ""
#define nl__Auto3634   ""
#define pt__Auto3634   ""
#define xx__Auto3634   ""
#define en_Auto3635   "Source Filename"
#define fr_Auto3635   "Fichier de d‚clarations"
#define it_Auto3635   "Source Filename"
#define es_Auto3635   "Source Filename"
#define de_Auto3635   "Source Filename"
#define nl_Auto3635   "Source Filename"
#define pt_Auto3635   "Source Filename"
#define xx_Auto3635   "Source Filename"
#define en__Auto3635   ""
#define fr__Auto3635   ""
#define it__Auto3635   ""
#define es__Auto3635   ""
#define de__Auto3635   ""
#define nl__Auto3635   ""
#define pt__Auto3635   ""
#define xx__Auto3635   ""
#define en_Auto3636   "File Classname"
#define fr_Auto3636   "Nom de la classe"
#define it_Auto3636   "File Classname"
#define es_Auto3636   "File Classname"
#define de_Auto3636   "File Classname"
#define nl_Auto3636   "File Classname"
#define pt_Auto3636   "File Classname"
#define xx_Auto3636   "File Classname"
#define en__Auto3636   ""
#define fr__Auto3636   ""
#define it__Auto3636   ""
#define es__Auto3636   ""
#define de__Auto3636   ""
#define nl__Auto3636   ""
#define pt__Auto3636   ""
#define xx__Auto3636   ""
#define en_Auto3637   "File Instance name"
#define fr_Auto3637   "Nom de l'instance"
#define it_Auto3637   "File Instancename"
#define es_Auto3637   "File Instancename"
#define de_Auto3637   "File Instancename"
#define nl_Auto3637   "File Instancename"
#define pt_Auto3637   "File Instancename"
#define xx_Auto3637   "File Instancename"
#define en__Auto3637   ""
#define fr__Auto3637   ""
#define it__Auto3637   ""
#define es__Auto3637   ""
#define de__Auto3637   ""
#define nl__Auto3637   ""
#define pt__Auto3637   ""
#define xx__Auto3637   ""
#define en_Auto3638   "Data Filename"
#define fr_Auto3638   "Fichier des donn‚es"
#define it_Auto3638   "Data Filename"
#define es_Auto3638   "Data Filename"
#define de_Auto3638   "Data Filename"
#define nl_Auto3638   "Data Filename"
#define pt_Auto3638   "Data Filename"
#define xx_Auto3638   "Data Filename"
#define en__Auto3638   ""
#define fr__Auto3638   ""
#define it__Auto3638   ""
#define es__Auto3638   ""
#define de__Auto3638   ""
#define nl__Auto3638   ""
#define pt__Auto3638   ""
#define xx__Auto3638   ""
#define en_Auto3639   "Index Variable Name"
#define fr_Auto3639   "Variable d'indexe"
#define it_Auto3639   "Index Variable Name"
#define es_Auto3639   "Index Variable Name"
#define de_Auto3639   "Index Variable Name"
#define nl_Auto3639   "Index Variable Name"
#define pt_Auto3639   "Index Variable Name"
#define xx_Auto3639   "Index Variable Name"
#define en__Auto3639   ""
#define fr__Auto3639   ""
#define it__Auto3639   ""
#define es__Auto3639   ""
#define de__Auto3639   ""
#define nl__Auto3639   ""
#define pt__Auto3639   ""
#define xx__Auto3639   ""
#define en_Auto3640   "Marker Variable Name"
#define fr_Auto3640   "Variable marker"
#define it_Auto3640   "Index Variable Name"
#define es_Auto3640   "Index Variable Name"
#define de_Auto3640   "Index Variable Name"
#define nl_Auto3640   "Index Variable Name"
#define pt_Auto3640   "Index Variable Name"
#define xx_Auto3640   "Index Variable Name"
#define en__Auto3640   ""
#define fr__Auto3640   ""
#define it__Auto3640   ""
#define es__Auto3640   ""
#define de__Auto3640   ""
#define nl__Auto3640   ""
#define pt__Auto3640   ""
#define xx__Auto3640   ""
#define en_Auto3641   "Record Variable Name"
#define fr_Auto3641   "Variable des donn‚es"
#define it_Auto3641   "Record Variable Name"
#define es_Auto3641   "Record Variable Name"
#define de_Auto3641   "Record Variable Name"
#define nl_Auto3641   "Record Variable Name"
#define pt_Auto3641   "Record Variable Name"
#define xx_Auto3641   "Record Variable Name"
#define en__Auto3641   ""
#define fr__Auto3641   ""
#define it__Auto3641   ""
#define es__Auto3641   ""
#define de__Auto3641   ""
#define nl__Auto3641   ""
#define pt__Auto3641   ""
#define xx__Auto3641   ""
#define en_Auto3642   "Name Conversion"
#define fr_Auto3642   "Conversion des noms"
#define it_Auto3642   "Name Conversion"
#define es_Auto3642   "Name Conversion"
#define de_Auto3642   "Name Conversion"
#define nl_Auto3642   "Name Conversion"
#define pt_Auto3642   "Name Conversion"
#define xx_Auto3642   "Name Conversion"
#define en__Auto3642   ""
#define fr__Auto3642   ""
#define it__Auto3642   ""
#define es__Auto3642   ""
#define de__Auto3642   ""
#define nl__Auto3642   ""
#define pt__Auto3642   ""
#define xx__Auto3642   ""
#define en_Accept   "ok.gif"
#define fr_Accept   "ok.gif"
#define it_Accept   "ok.gif"
#define es_Accept   "ok.gif"
#define de_Accept   "ok.gif"
#define nl_Accept   "ok.gif"
#define pt_Accept   "ok.gif"
#define xx_Accept   "ok.gif"
#define en__Accept   ""
#define fr__Accept   ""
#define it__Accept   ""
#define es__Accept   ""
#define de__Accept   ""
#define nl__Accept   ""
#define pt__Accept   ""
#define xx__Accept   ""
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"
#define en__Cancel   ""
#define fr__Cancel   ""
#define it__Cancel   ""
#define es__Cancel   ""
#define de__Cancel   ""
#define nl__Cancel   ""
#define pt__Cancel   ""
#define xx__Cancel   ""
#define en_IncludeName   ""
#define en__IncludeName   ""
#define en_EditStyle   "edit"
#define fr_EditStyle   "voir"
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
#define fr_ConvertCase   "convertir en majescules|convertir en minescules|preserver le cas"
#define it_ConvertCase   "convert to uppercase|convert to lowercase|preserve original case"
#define es_ConvertCase   "convert to uppercase|convert to lowercase|preserve original case"
#define de_ConvertCase   "convert to uppercase|convert to lowercase|preserve original case"
#define nl_ConvertCase   "convert to uppercase|convert to lowercase|preserve original case"
#define pt_ConvertCase   "convert to uppercase|convert to lowercase|preserve original case"
#define xx_ConvertCase   "convert to uppercase|convert to lowercase|preserve original case"
#define en__ConvertCase   ""
#define fr__ConvertCase   ""
#define it__ConvertCase   ""
#define es__ConvertCase   ""
#define de__ConvertCase   ""
#define nl__ConvertCase   ""
#define pt__ConvertCase   ""
#define xx__ConvertCase   ""

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
	char * msg_Auto3634[8];
	char * hint_Auto3634[8];
	char * msg_Auto3635[8];
	char * hint_Auto3635[8];
	char * msg_Auto3636[8];
	char * hint_Auto3636[8];
	char * msg_Auto3637[8];
	char * hint_Auto3637[8];
	char * msg_Auto3638[8];
	char * hint_Auto3638[8];
	char * msg_Auto3639[8];
	char * hint_Auto3639[8];
	char * msg_Auto3640[8];
	char * hint_Auto3640[8];
	char * msg_Auto3641[8];
	char * hint_Auto3641[8];
	char * msg_Auto3642[8];
	char * hint_Auto3642[8];
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
private int on_Accept_event(struct accept_inclusion_parameters_context * _Context);
private int on_Cancel_event(struct accept_inclusion_parameters_context * _Context);
private int on_EditStyle_event(struct accept_inclusion_parameters_context * _Context);

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
	vfh[10] = visual_font("bmap0414.fmf",12);
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
	for (i=0; i < 8; i++)_Context->msg_Auto3634[i]=" ";
	_Context->msg_Auto3634[0]=en_Auto3634;
	_Context->msg_Auto3634[1]=fr_Auto3634;
	_Context->msg_Auto3634[2]=it_Auto3634;
	_Context->msg_Auto3634[3]=es_Auto3634;
	_Context->msg_Auto3634[4]=de_Auto3634;
	_Context->msg_Auto3634[5]=nl_Auto3634;
	_Context->msg_Auto3634[6]=pt_Auto3634;
	_Context->msg_Auto3634[7]=xx_Auto3634;
	_Context->hint_Auto3634[0]=en__Auto3634;
	_Context->hint_Auto3634[1]=fr__Auto3634;
	_Context->hint_Auto3634[2]=it__Auto3634;
	_Context->hint_Auto3634[3]=es__Auto3634;
	_Context->hint_Auto3634[4]=de__Auto3634;
	_Context->hint_Auto3634[5]=nl__Auto3634;
	_Context->hint_Auto3634[6]=pt__Auto3634;
	_Context->hint_Auto3634[7]=xx__Auto3634;
	for (i=0; i < 8; i++)_Context->msg_Auto3635[i]=" ";
	_Context->msg_Auto3635[0]=en_Auto3635;
	_Context->msg_Auto3635[1]=fr_Auto3635;
	_Context->msg_Auto3635[2]=it_Auto3635;
	_Context->msg_Auto3635[3]=es_Auto3635;
	_Context->msg_Auto3635[4]=de_Auto3635;
	_Context->msg_Auto3635[5]=nl_Auto3635;
	_Context->msg_Auto3635[6]=pt_Auto3635;
	_Context->msg_Auto3635[7]=xx_Auto3635;
	_Context->hint_Auto3635[0]=en__Auto3635;
	_Context->hint_Auto3635[1]=fr__Auto3635;
	_Context->hint_Auto3635[2]=it__Auto3635;
	_Context->hint_Auto3635[3]=es__Auto3635;
	_Context->hint_Auto3635[4]=de__Auto3635;
	_Context->hint_Auto3635[5]=nl__Auto3635;
	_Context->hint_Auto3635[6]=pt__Auto3635;
	_Context->hint_Auto3635[7]=xx__Auto3635;
	for (i=0; i < 8; i++)_Context->msg_Auto3636[i]=" ";
	_Context->msg_Auto3636[0]=en_Auto3636;
	_Context->msg_Auto3636[1]=fr_Auto3636;
	_Context->msg_Auto3636[2]=it_Auto3636;
	_Context->msg_Auto3636[3]=es_Auto3636;
	_Context->msg_Auto3636[4]=de_Auto3636;
	_Context->msg_Auto3636[5]=nl_Auto3636;
	_Context->msg_Auto3636[6]=pt_Auto3636;
	_Context->msg_Auto3636[7]=xx_Auto3636;
	_Context->hint_Auto3636[0]=en__Auto3636;
	_Context->hint_Auto3636[1]=fr__Auto3636;
	_Context->hint_Auto3636[2]=it__Auto3636;
	_Context->hint_Auto3636[3]=es__Auto3636;
	_Context->hint_Auto3636[4]=de__Auto3636;
	_Context->hint_Auto3636[5]=nl__Auto3636;
	_Context->hint_Auto3636[6]=pt__Auto3636;
	_Context->hint_Auto3636[7]=xx__Auto3636;
	for (i=0; i < 8; i++)_Context->msg_Auto3637[i]=" ";
	_Context->msg_Auto3637[0]=en_Auto3637;
	_Context->msg_Auto3637[1]=fr_Auto3637;
	_Context->msg_Auto3637[2]=it_Auto3637;
	_Context->msg_Auto3637[3]=es_Auto3637;
	_Context->msg_Auto3637[4]=de_Auto3637;
	_Context->msg_Auto3637[5]=nl_Auto3637;
	_Context->msg_Auto3637[6]=pt_Auto3637;
	_Context->msg_Auto3637[7]=xx_Auto3637;
	_Context->hint_Auto3637[0]=en__Auto3637;
	_Context->hint_Auto3637[1]=fr__Auto3637;
	_Context->hint_Auto3637[2]=it__Auto3637;
	_Context->hint_Auto3637[3]=es__Auto3637;
	_Context->hint_Auto3637[4]=de__Auto3637;
	_Context->hint_Auto3637[5]=nl__Auto3637;
	_Context->hint_Auto3637[6]=pt__Auto3637;
	_Context->hint_Auto3637[7]=xx__Auto3637;
	for (i=0; i < 8; i++)_Context->msg_Auto3638[i]=" ";
	_Context->msg_Auto3638[0]=en_Auto3638;
	_Context->msg_Auto3638[1]=fr_Auto3638;
	_Context->msg_Auto3638[2]=it_Auto3638;
	_Context->msg_Auto3638[3]=es_Auto3638;
	_Context->msg_Auto3638[4]=de_Auto3638;
	_Context->msg_Auto3638[5]=nl_Auto3638;
	_Context->msg_Auto3638[6]=pt_Auto3638;
	_Context->msg_Auto3638[7]=xx_Auto3638;
	_Context->hint_Auto3638[0]=en__Auto3638;
	_Context->hint_Auto3638[1]=fr__Auto3638;
	_Context->hint_Auto3638[2]=it__Auto3638;
	_Context->hint_Auto3638[3]=es__Auto3638;
	_Context->hint_Auto3638[4]=de__Auto3638;
	_Context->hint_Auto3638[5]=nl__Auto3638;
	_Context->hint_Auto3638[6]=pt__Auto3638;
	_Context->hint_Auto3638[7]=xx__Auto3638;
	for (i=0; i < 8; i++)_Context->msg_Auto3639[i]=" ";
	_Context->msg_Auto3639[0]=en_Auto3639;
	_Context->msg_Auto3639[1]=fr_Auto3639;
	_Context->msg_Auto3639[2]=it_Auto3639;
	_Context->msg_Auto3639[3]=es_Auto3639;
	_Context->msg_Auto3639[4]=de_Auto3639;
	_Context->msg_Auto3639[5]=nl_Auto3639;
	_Context->msg_Auto3639[6]=pt_Auto3639;
	_Context->msg_Auto3639[7]=xx_Auto3639;
	_Context->hint_Auto3639[0]=en__Auto3639;
	_Context->hint_Auto3639[1]=fr__Auto3639;
	_Context->hint_Auto3639[2]=it__Auto3639;
	_Context->hint_Auto3639[3]=es__Auto3639;
	_Context->hint_Auto3639[4]=de__Auto3639;
	_Context->hint_Auto3639[5]=nl__Auto3639;
	_Context->hint_Auto3639[6]=pt__Auto3639;
	_Context->hint_Auto3639[7]=xx__Auto3639;
	for (i=0; i < 8; i++)_Context->msg_Auto3640[i]=" ";
	_Context->msg_Auto3640[0]=en_Auto3640;
	_Context->msg_Auto3640[1]=fr_Auto3640;
	_Context->msg_Auto3640[2]=it_Auto3640;
	_Context->msg_Auto3640[3]=es_Auto3640;
	_Context->msg_Auto3640[4]=de_Auto3640;
	_Context->msg_Auto3640[5]=nl_Auto3640;
	_Context->msg_Auto3640[6]=pt_Auto3640;
	_Context->msg_Auto3640[7]=xx_Auto3640;
	_Context->hint_Auto3640[0]=en__Auto3640;
	_Context->hint_Auto3640[1]=fr__Auto3640;
	_Context->hint_Auto3640[2]=it__Auto3640;
	_Context->hint_Auto3640[3]=es__Auto3640;
	_Context->hint_Auto3640[4]=de__Auto3640;
	_Context->hint_Auto3640[5]=nl__Auto3640;
	_Context->hint_Auto3640[6]=pt__Auto3640;
	_Context->hint_Auto3640[7]=xx__Auto3640;
	for (i=0; i < 8; i++)_Context->msg_Auto3641[i]=" ";
	_Context->msg_Auto3641[0]=en_Auto3641;
	_Context->msg_Auto3641[1]=fr_Auto3641;
	_Context->msg_Auto3641[2]=it_Auto3641;
	_Context->msg_Auto3641[3]=es_Auto3641;
	_Context->msg_Auto3641[4]=de_Auto3641;
	_Context->msg_Auto3641[5]=nl_Auto3641;
	_Context->msg_Auto3641[6]=pt_Auto3641;
	_Context->msg_Auto3641[7]=xx_Auto3641;
	_Context->hint_Auto3641[0]=en__Auto3641;
	_Context->hint_Auto3641[1]=fr__Auto3641;
	_Context->hint_Auto3641[2]=it__Auto3641;
	_Context->hint_Auto3641[3]=es__Auto3641;
	_Context->hint_Auto3641[4]=de__Auto3641;
	_Context->hint_Auto3641[5]=nl__Auto3641;
	_Context->hint_Auto3641[6]=pt__Auto3641;
	_Context->hint_Auto3641[7]=xx__Auto3641;
	for (i=0; i < 8; i++)_Context->msg_Auto3642[i]=" ";
	_Context->msg_Auto3642[0]=en_Auto3642;
	_Context->msg_Auto3642[1]=fr_Auto3642;
	_Context->msg_Auto3642[2]=it_Auto3642;
	_Context->msg_Auto3642[3]=es_Auto3642;
	_Context->msg_Auto3642[4]=de_Auto3642;
	_Context->msg_Auto3642[5]=nl_Auto3642;
	_Context->msg_Auto3642[6]=pt_Auto3642;
	_Context->msg_Auto3642[7]=xx_Auto3642;
	_Context->hint_Auto3642[0]=en__Auto3642;
	_Context->hint_Auto3642[1]=fr__Auto3642;
	_Context->hint_Auto3642[2]=it__Auto3642;
	_Context->hint_Auto3642[3]=es__Auto3642;
	_Context->hint_Auto3642[4]=de__Auto3642;
	_Context->hint_Auto3642[5]=nl__Auto3642;
	_Context->hint_Auto3642[6]=pt__Auto3642;
	_Context->hint_Auto3642[7]=xx__Auto3642;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	_Context->hint_Accept[0]=en__Accept;
	_Context->hint_Accept[1]=fr__Accept;
	_Context->hint_Accept[2]=it__Accept;
	_Context->hint_Accept[3]=es__Accept;
	_Context->hint_Accept[4]=de__Accept;
	_Context->hint_Accept[5]=nl__Accept;
	_Context->hint_Accept[6]=pt__Accept;
	_Context->hint_Accept[7]=xx__Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->msg_Cancel[2]=it_Cancel;
	_Context->msg_Cancel[3]=es_Cancel;
	_Context->msg_Cancel[4]=de_Cancel;
	_Context->msg_Cancel[5]=nl_Cancel;
	_Context->msg_Cancel[6]=pt_Cancel;
	_Context->msg_Cancel[7]=xx_Cancel;
	_Context->hint_Cancel[0]=en__Cancel;
	_Context->hint_Cancel[1]=fr__Cancel;
	_Context->hint_Cancel[2]=it__Cancel;
	_Context->hint_Cancel[3]=es__Cancel;
	_Context->hint_Cancel[4]=de__Cancel;
	_Context->hint_Cancel[5]=nl__Cancel;
	_Context->hint_Cancel[6]=pt__Cancel;
	_Context->hint_Cancel[7]=xx__Cancel;
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
	_Context->msg_ConvertCase[1]=fr_ConvertCase;
	_Context->msg_ConvertCase[2]=it_ConvertCase;
	_Context->msg_ConvertCase[3]=es_ConvertCase;
	_Context->msg_ConvertCase[4]=de_ConvertCase;
	_Context->msg_ConvertCase[5]=nl_ConvertCase;
	_Context->msg_ConvertCase[6]=pt_ConvertCase;
	_Context->msg_ConvertCase[7]=xx_ConvertCase;
	_Context->hint_ConvertCase[0]=en__ConvertCase;
	_Context->hint_ConvertCase[1]=fr__ConvertCase;
	_Context->hint_ConvertCase[2]=it__ConvertCase;
	_Context->hint_ConvertCase[3]=es__ConvertCase;
	_Context->hint_ConvertCase[4]=de__ConvertCase;
	_Context->hint_ConvertCase[5]=nl__ConvertCase;
	_Context->hint_ConvertCase[6]=pt__ConvertCase;
	_Context->hint_ConvertCase[7]=xx__ConvertCase;
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
	visual_text(_Context->x_auto2+20,_Context->y_auto2+30,660,30,vfh[3],16,0,_Context->msg_Auto3634[_Context->language],strlen(_Context->msg_Auto3634[_Context->language]),1283);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+80,136,16,vfh[2],16,0,_Context->msg_Auto3635[_Context->language],strlen(_Context->msg_Auto3635[_Context->language]),1282);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+110,136,16,vfh[2],16,0,_Context->msg_Auto3636[_Context->language],strlen(_Context->msg_Auto3636[_Context->language]),1282);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+130,136,16,vfh[2],16,0,_Context->msg_Auto3637[_Context->language],strlen(_Context->msg_Auto3637[_Context->language]),1282);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+150,136,16,vfh[2],16,0,_Context->msg_Auto3638[_Context->language],strlen(_Context->msg_Auto3638[_Context->language]),1282);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+180,136,16,vfh[2],16,0,_Context->msg_Auto3639[_Context->language],strlen(_Context->msg_Auto3639[_Context->language]),1282);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+200,136,16,vfh[2],16,0,_Context->msg_Auto3640[_Context->language],strlen(_Context->msg_Auto3640[_Context->language]),1282);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+220,136,16,vfh[2],16,0,_Context->msg_Auto3641[_Context->language],strlen(_Context->msg_Auto3641[_Context->language]),1282);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+250,136,16,vfh[2],16,0,_Context->msg_Auto3642[_Context->language],strlen(_Context->msg_Auto3642[_Context->language]),1282);
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
