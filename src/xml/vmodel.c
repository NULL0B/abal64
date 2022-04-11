
#ifndef _vmodel_c
#define _vmodel_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vmodel.xml                                               */
/* Target         : vmodel.c                                                 */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en__Auto3633   ""
#define en_Auto3634   "File Model Characteristics"
#define fr_Auto3634   "CaractŠristiques du modŠle de fichier"
#define it_Auto3634   "File Model Characteristics"
#define es_Auto3634   "File Model Characteristics"
#define de_Auto3634   "File Model Characteristics"
#define nl_Auto3634   "File Model Characteristics"
#define pt_Auto3634   "File Model Characteristics"
#define xx_Auto3634   "File Model Characteristics"
#define en__Auto3634   ""
#define fr__Auto3634   ""
#define it__Auto3634   ""
#define es__Auto3634   ""
#define de__Auto3634   ""
#define nl__Auto3634   ""
#define pt__Auto3634   ""
#define xx__Auto3634   ""
#define en_Auto3638   "Class"
#define fr_Auto3638   "Classe"
#define it_Auto3638   "Class"
#define es_Auto3638   "Class"
#define de_Auto3638   "Class"
#define nl_Auto3638   "Class"
#define pt_Auto3638   "Class"
#define xx_Auto3638   "Class"
#define fr__Auto3638   ""
#define en_Auto3639   "Instance"
#define fr_Auto3639   "Instance"
#define it_Auto3639   "Instance"
#define es_Auto3639   "Instance"
#define de_Auto3639   "Instance"
#define nl_Auto3639   "Instance"
#define pt_Auto3639   "Instance"
#define xx_Auto3639   "Instance"
#define en_Auto3640   "Filename"
#define fr_Auto3640   "Fichier"
#define it_Auto3640   "File"
#define es_Auto3640   "File"
#define de_Auto3640   "Filename"
#define nl_Auto3640   "Filename"
#define pt_Auto3640   "Filename"
#define xx_Auto3640   "Filename"
#define en_Auto3641   "Filetype"
#define fr_Auto3641   "M‚thode"
#define it_Auto3641   "Format"
#define es_Auto3641   "Format"
#define de_Auto3641   "Format"
#define nl_Auto3641   "Format"
#define pt_Auto3641   "Format"
#define xx_Auto3641   "Format"
#define en_Auto3642   "Align"
#define fr_Auto3642   "Align."
#define it_Auto3642   "Align"
#define es_Auto3642   "Align"
#define de_Auto3642   "Align"
#define nl_Auto3642   "Align"
#define pt_Auto3642   "Align"
#define xx_Auto3642   "Align"
#define en_Auto3643   "Size"
#define fr_Auto3643   "Taille"
#define it_Auto3643   "Size"
#define es_Auto3643   "Size"
#define de_Auto3643   "Size"
#define nl_Auto3643   "Size"
#define pt_Auto3643   "Size"
#define xx_Auto3643   "Size"
#define en__Auto3643   ""
#define en_Auto3644   "Members"
#define fr_Auto3644   "Membres"
#define it_Auto3644   "Primary Index Members"
#define es_Auto3644   "Primary Index Members"
#define de_Auto3644   "Primary Index Members"
#define nl_Auto3644   "Primary Index Members"
#define pt_Auto3644   "Primary Index Members"
#define xx_Auto3644   "Primary Index Members"
#define en__Auto3644   ""
#define fr_Auto3645   "Index Primaire"
#define it_Auto3645   "Primary Index Size"
#define es_Auto3645   "Primary Index Size"
#define de_Auto3645   "Primary Index Size"
#define nl_Auto3645   "Primary Index Size"
#define pt_Auto3645   "Primary Index Size"
#define xx_Auto3645   "Primary Index Size"
#define fr_Auto3646   "Enregistrement"
#define it_Auto3646   "Data Record Size"
#define es_Auto3646   "Data Record Size"
#define de_Auto3646   "Data Record Size"
#define nl_Auto3646   "Data Record Size"
#define pt_Auto3646   "Data Record Size"
#define xx_Auto3646   "Data Record Size"
#define en_ClassName   ""
#define en__ClassName   ""
#define en_Instance   ""
#define en__Instance   ""
#define en_Filename   ""
#define en__Filename   ""
#define en__FileType   ""
#define en_IndexType   "K=|LK=|RK="
#define fr_IndexType   "K=|LK=|RK="
#define it_IndexType   "K=|LK=|RK="
#define es_IndexType   "K=|LK=|RK="
#define de_IndexType   "K=|LK=|RK="
#define nl_IndexType   "K=|LK=|RK="
#define pt_IndexType   "K=|LK=|RK="
#define xx_IndexType   "K=|LK=|RK="
#define en__IndexType   ""
#define en_RecordType   "VD"
#define fr_RecordType   "VD="
#define it_RecordType   "VD="
#define es_RecordType   "VD="
#define de_RecordType   "VD="
#define nl_RecordType   "VD="
#define pt_RecordType   "VD="
#define xx_RecordType   "VD="
#define en__RecordType   ""
#define en_Modext   "MODEXT"
#define fr_Modext   "MODEXT"
#define it_Modext   "MODEXT"
#define es_Modext   "MODEXT"
#define de_Modext   "MODEXT"
#define nl_Modext   "MODEXT"
#define pt_Modext   "MODEXT"
#define xx_Modext   "MODEXT"
#define en__Modext   ""
#define en_MarkerUseage   "MQ"
#define fr_MarkerUseage   "VD="
#define it_MarkerUseage   "VD="
#define es_MarkerUseage   "VD="
#define de_MarkerUseage   "VD="
#define nl_MarkerUseage   "VD="
#define pt_MarkerUseage   "VD="
#define xx_MarkerUseage   "VD="
#define en__MarkerUseage   ""
#define en_IndexSize   ""
#define en__IndexSize   ""
#define en_NbIndex   ""
#define en__NbIndex   ""
#define en_RecordSize   ""
#define en__RecordSize   ""
#define en_NbData   ""
#define en__NbData   ""
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
#define it_Cancel   "ok.gif"
#define es_Cancel   "ok.gif"
#define de_Cancel   "ok.gif"
#define nl_Cancel   "ok.gif"
#define pt_Cancel   "ok.gif"
#define xx_Cancel   "ok.gif"
#define en__Cancel   ""
#define fr__Cancel   ""
#define it__Cancel   ""
#define es__Cancel   ""
#define de__Cancel   ""
#define nl__Cancel   ""
#define pt__Cancel   ""
#define xx__Cancel   ""
#define en_ModelOpen   "Inhibit display of File Members"
#define fr_ModelOpen   "Inhiber l'affichage des membres"
#define it_ModelOpen   "Inhibit display of File Members"
#define es_ModelOpen   "Inhibit display of File Members"
#define de_ModelOpen   "Inhibit display of File Members"
#define nl_ModelOpen   "Inhibit display of File Members"
#define pt_ModelOpen   "Inhibit display of File Members"
#define xx_ModelOpen   "Inhibit display of File Members"
#define en__ModelOpen   ""
#define fr__ModelOpen   ""
#define it__ModelOpen   ""
#define es__ModelOpen   ""
#define de__ModelOpen   ""
#define nl__ModelOpen   ""
#define pt__ModelOpen   ""
#define xx__ModelOpen   ""
#define en_ModelLock   "Lock File Model"
#define fr_ModelLock   "Verouillage du modŠle"
#define it_ModelLock   "Lock File Model"
#define es_ModelLock   "Lock File Model"
#define de_ModelLock   "Lock File Model"
#define nl_ModelLock   "Lock File Model"
#define pt_ModelLock   "Lock File Model"
#define xx_ModelLock   "Lock File Model"
#define en__ModelLock   ""
#define fr__ModelLock   ""
#define it__ModelLock   ""
#define es__ModelLock   ""
#define de__ModelLock   ""
#define nl__ModelLock   ""
#define pt__ModelLock   ""
#define xx__ModelLock   ""

private struct accept_model_properties_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3633[8];
	char * hint_Auto3633[8];
	int	x_Auto3633;
	int	y_Auto3633;
	int	w_Auto3633;
	int	h_Auto3633;
	char * msg_Auto3634[8];
	char * hint_Auto3634[8];
	char * hint_Auto3635[8];
	char * hint_Auto3636[8];
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
	char * msg_Auto3643[8];
	char * hint_Auto3643[8];
	char * msg_Auto3644[8];
	char * hint_Auto3644[8];
	char * msg_Auto3645[8];
	char * hint_Auto3645[8];
	char * msg_Auto3646[8];
	char * hint_Auto3646[8];
	char * hint_ClassName[8];
	char	buffer_ClassName[256];
	char * hint_Auto3647[8];
	char * hint_Instance[8];
	char	buffer_Instance[256];
	char * hint_Filename[8];
	char	buffer_Filename[256];
	char * hint_Auto3648[8];
	char * msg_FileType[8];
	char * hint_FileType[8];
	int	value_FileType;
	char * hint_Auto3649[8];
	char * msg_IndexType[8];
	char * hint_IndexType[8];
	int	value_IndexType;
	char * msg_RecordType[8];
	int	trigger_RecordType;
	char * hint_RecordType[8];
	int	value_RecordType;
	char * msg_Modext[8];
	int	trigger_Modext;
	char * hint_Modext[8];
	int	value_Modext;
	char * msg_MarkerUseage[8];
	int	trigger_MarkerUseage;
	char * hint_MarkerUseage[8];
	int	value_MarkerUseage;
	char * hint_Auto3650[8];
	char * hint_IndexSize[8];
	char	buffer_IndexSize[9];
	char * hint_NbIndex[8];
	char	buffer_NbIndex[9];
	char * hint_RecordSize[8];
	char	buffer_RecordSize[9];
	char * hint_NbData[8];
	char	buffer_NbData[9];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	char * msg_ModelOpen[8];
	int	trigger_ModelOpen;
	char * hint_ModelOpen[8];
	int	value_ModelOpen;
	char * msg_ModelLock[8];
	int	trigger_ModelLock;
	char * hint_ModelLock[8];
	int	value_ModelLock;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[15];
	};
static int	vfh[16];
private int on_Accept_event(struct accept_model_properties_context * _Context);
private int on_Cancel_event(struct accept_model_properties_context * _Context);
static char	 * DataRecordLabel(struct accept_model_properties_context * _Context);
static char	 * PrimaryIndexLabel(struct accept_model_properties_context * _Context);

/*	--------------------------------	*/
/*	D a t a R e c o r d L a b e l ()	*/
/*	--------------------------------	*/
static char	 * DataRecordLabel(struct accept_model_properties_context * _Context){
	switch(_Context->value_FileType){
	case 5:
	return("File Handle");
	case 3:
	case 4:
	case 6:
	case 7:
	return("Data Record");
	default:
	return("N/A");
	}

}

/*	------------------------------------	*/
/*	P r i m a r y I n d e x L a b e l ()	*/
/*	------------------------------------	*/
static char	 * PrimaryIndexLabel(struct accept_model_properties_context * _Context){
	switch(_Context->value_FileType){
	case 3:
	case 4:
	case 7:
	return("Primary Index");
	default:
	return("N/A");
	}

}

public	int	accept_model_properties_create(
	struct accept_model_properties_context ** cptr,
	char * pClassName,
	char * pInstance,
	char * pFilename,
	char * pFileType,
	char * pIndexType,
	char * pRecordType,
	char * pModext,
	char * pMarkerUseage,
	char * pIndexSize,
	char * pNbIndex,
	char * pRecordSize,
	char * pNbData,
	char * pModelOpen,
	char * pModelLock)
{

	int i;
	struct accept_model_properties_context * _Context=(struct accept_model_properties_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_model_properties_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=17;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSWWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_ClassName, 255, pClassName);
		visual_transferin(_Context->buffer_Instance, 255, pInstance);
		visual_transferin(_Context->buffer_Filename, 255, pFilename);
		visual_transferin((void *) 0, 0, pFileType);
		if (!( pFileType )) _Context->value_FileType=0;
		else	_Context->value_FileType = *((int *)pFileType);
		visual_transferin((void *) 0, 0, pIndexType);
		if (!( pIndexType )) _Context->value_IndexType=0;
		else	_Context->value_IndexType = *((int *)pIndexType);
		visual_transferin((void *) 0, 0, pRecordType);
		if (!( pRecordType )) _Context->value_RecordType=0;
		else	_Context->value_RecordType = *((int *)pRecordType);
		visual_transferin((void *) 0, 0, pModext);
		if (!( pModext )) _Context->value_Modext=0;
		else	_Context->value_Modext = *((int *)pModext);
		visual_transferin((void *) 0, 0, pMarkerUseage);
		if (!( pMarkerUseage )) _Context->value_MarkerUseage=0;
		else	_Context->value_MarkerUseage = *((int *)pMarkerUseage);
		visual_transferin(_Context->buffer_IndexSize, 8, pIndexSize);
		visual_transferin(_Context->buffer_NbIndex, 8, pNbIndex);
		visual_transferin(_Context->buffer_RecordSize, 8, pRecordSize);
		visual_transferin(_Context->buffer_NbData, 8, pNbData);
		visual_transferin((void *) 0, 0, pModelOpen);
		if (!( pModelOpen )) _Context->value_ModelOpen=0;
		else	_Context->value_ModelOpen = *((int *)pModelOpen);
		visual_transferin((void *) 0, 0, pModelLock);
		if (!( pModelLock )) _Context->value_ModelLock=0;
		else	_Context->value_ModelLock = *((int *)pModelLock);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3633[i]=" ";
	_Context->hint_Auto3633[0]=en__Auto3633;
	_Context->x_Auto3633=170;
	_Context->y_Auto3633=140;
	_Context->w_Auto3633=460;
	_Context->h_Auto3633=320;
	_Context->window_col=0;
	_Context->window_row=0;
	if(((_Context->y_Auto3633=visual_event(6))+320)>hardrows())
	_Context->y_Auto3633=(hardrows()-320);
	if(((_Context->x_Auto3633=visual_event(7))+460)>hardcolumns())
	_Context->x_Auto3633=(hardcolumns()-460);
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
	for (i=0; i < 8; i++)_Context->msg_Auto3638[i]=" ";
	_Context->msg_Auto3638[0]=en_Auto3638;
	_Context->msg_Auto3638[1]=fr_Auto3638;
	_Context->msg_Auto3638[2]=it_Auto3638;
	_Context->msg_Auto3638[3]=es_Auto3638;
	_Context->msg_Auto3638[4]=de_Auto3638;
	_Context->msg_Auto3638[5]=nl_Auto3638;
	_Context->msg_Auto3638[6]=pt_Auto3638;
	_Context->msg_Auto3638[7]=xx_Auto3638;
	_Context->hint_Auto3638[1]=fr__Auto3638;
	for (i=0; i < 8; i++)_Context->msg_Auto3639[i]=" ";
	_Context->msg_Auto3639[0]=en_Auto3639;
	_Context->msg_Auto3639[1]=fr_Auto3639;
	_Context->msg_Auto3639[2]=it_Auto3639;
	_Context->msg_Auto3639[3]=es_Auto3639;
	_Context->msg_Auto3639[4]=de_Auto3639;
	_Context->msg_Auto3639[5]=nl_Auto3639;
	_Context->msg_Auto3639[6]=pt_Auto3639;
	_Context->msg_Auto3639[7]=xx_Auto3639;
	for (i=0; i < 8; i++)_Context->msg_Auto3640[i]=" ";
	_Context->msg_Auto3640[0]=en_Auto3640;
	_Context->msg_Auto3640[1]=fr_Auto3640;
	_Context->msg_Auto3640[2]=it_Auto3640;
	_Context->msg_Auto3640[3]=es_Auto3640;
	_Context->msg_Auto3640[4]=de_Auto3640;
	_Context->msg_Auto3640[5]=nl_Auto3640;
	_Context->msg_Auto3640[6]=pt_Auto3640;
	_Context->msg_Auto3640[7]=xx_Auto3640;
	for (i=0; i < 8; i++)_Context->msg_Auto3641[i]=" ";
	_Context->msg_Auto3641[0]=en_Auto3641;
	_Context->msg_Auto3641[1]=fr_Auto3641;
	_Context->msg_Auto3641[2]=it_Auto3641;
	_Context->msg_Auto3641[3]=es_Auto3641;
	_Context->msg_Auto3641[4]=de_Auto3641;
	_Context->msg_Auto3641[5]=nl_Auto3641;
	_Context->msg_Auto3641[6]=pt_Auto3641;
	_Context->msg_Auto3641[7]=xx_Auto3641;
	for (i=0; i < 8; i++)_Context->msg_Auto3642[i]=" ";
	_Context->msg_Auto3642[0]=en_Auto3642;
	_Context->msg_Auto3642[1]=fr_Auto3642;
	_Context->msg_Auto3642[2]=it_Auto3642;
	_Context->msg_Auto3642[3]=es_Auto3642;
	_Context->msg_Auto3642[4]=de_Auto3642;
	_Context->msg_Auto3642[5]=nl_Auto3642;
	_Context->msg_Auto3642[6]=pt_Auto3642;
	_Context->msg_Auto3642[7]=xx_Auto3642;
	for (i=0; i < 8; i++)_Context->msg_Auto3643[i]=" ";
	_Context->msg_Auto3643[0]=en_Auto3643;
	_Context->msg_Auto3643[1]=fr_Auto3643;
	_Context->msg_Auto3643[2]=it_Auto3643;
	_Context->msg_Auto3643[3]=es_Auto3643;
	_Context->msg_Auto3643[4]=de_Auto3643;
	_Context->msg_Auto3643[5]=nl_Auto3643;
	_Context->msg_Auto3643[6]=pt_Auto3643;
	_Context->msg_Auto3643[7]=xx_Auto3643;
	_Context->hint_Auto3643[0]=en__Auto3643;
	for (i=0; i < 8; i++)_Context->msg_Auto3644[i]=" ";
	_Context->msg_Auto3644[0]=en_Auto3644;
	_Context->msg_Auto3644[1]=fr_Auto3644;
	_Context->msg_Auto3644[2]=it_Auto3644;
	_Context->msg_Auto3644[3]=es_Auto3644;
	_Context->msg_Auto3644[4]=de_Auto3644;
	_Context->msg_Auto3644[5]=nl_Auto3644;
	_Context->msg_Auto3644[6]=pt_Auto3644;
	_Context->msg_Auto3644[7]=xx_Auto3644;
	_Context->hint_Auto3644[0]=en__Auto3644;
	for (i=0; i < 8; i++)_Context->msg_Auto3645[i]=" ";
	_Context->msg_Auto3645[1]=fr_Auto3645;
	_Context->msg_Auto3645[2]=it_Auto3645;
	_Context->msg_Auto3645[3]=es_Auto3645;
	_Context->msg_Auto3645[4]=de_Auto3645;
	_Context->msg_Auto3645[5]=nl_Auto3645;
	_Context->msg_Auto3645[6]=pt_Auto3645;
	_Context->msg_Auto3645[7]=xx_Auto3645;
	for (i=0; i < 8; i++)_Context->msg_Auto3646[i]=" ";
	_Context->msg_Auto3646[1]=fr_Auto3646;
	_Context->msg_Auto3646[2]=it_Auto3646;
	_Context->msg_Auto3646[3]=es_Auto3646;
	_Context->msg_Auto3646[4]=de_Auto3646;
	_Context->msg_Auto3646[5]=nl_Auto3646;
	_Context->msg_Auto3646[6]=pt_Auto3646;
	_Context->msg_Auto3646[7]=xx_Auto3646;
	_Context->hint_ClassName[0]=en__ClassName;
	_Context->hint_Instance[0]=en__Instance;
	_Context->hint_Filename[0]=en__Filename;
	for (i=0; i < 8; i++)_Context->msg_FileType[i]=" ";
	_Context->hint_FileType[0]=en__FileType;
	for (i=0; i < 8; i++)_Context->msg_IndexType[i]=" ";
	_Context->msg_IndexType[0]=en_IndexType;
	_Context->msg_IndexType[1]=fr_IndexType;
	_Context->msg_IndexType[2]=it_IndexType;
	_Context->msg_IndexType[3]=es_IndexType;
	_Context->msg_IndexType[4]=de_IndexType;
	_Context->msg_IndexType[5]=nl_IndexType;
	_Context->msg_IndexType[6]=pt_IndexType;
	_Context->msg_IndexType[7]=xx_IndexType;
	_Context->hint_IndexType[0]=en__IndexType;
	for (i=0; i < 8; i++)_Context->msg_RecordType[i]=" ";
	_Context->msg_RecordType[0]=en_RecordType;
	_Context->msg_RecordType[1]=fr_RecordType;
	_Context->msg_RecordType[2]=it_RecordType;
	_Context->msg_RecordType[3]=es_RecordType;
	_Context->msg_RecordType[4]=de_RecordType;
	_Context->msg_RecordType[5]=nl_RecordType;
	_Context->msg_RecordType[6]=pt_RecordType;
	_Context->msg_RecordType[7]=xx_RecordType;
	_Context->hint_RecordType[0]=en__RecordType;
	for (i=0; i < 8; i++)_Context->msg_Modext[i]=" ";
	_Context->msg_Modext[0]=en_Modext;
	_Context->msg_Modext[1]=fr_Modext;
	_Context->msg_Modext[2]=it_Modext;
	_Context->msg_Modext[3]=es_Modext;
	_Context->msg_Modext[4]=de_Modext;
	_Context->msg_Modext[5]=nl_Modext;
	_Context->msg_Modext[6]=pt_Modext;
	_Context->msg_Modext[7]=xx_Modext;
	_Context->hint_Modext[0]=en__Modext;
	for (i=0; i < 8; i++)_Context->msg_MarkerUseage[i]=" ";
	_Context->msg_MarkerUseage[0]=en_MarkerUseage;
	_Context->msg_MarkerUseage[1]=fr_MarkerUseage;
	_Context->msg_MarkerUseage[2]=it_MarkerUseage;
	_Context->msg_MarkerUseage[3]=es_MarkerUseage;
	_Context->msg_MarkerUseage[4]=de_MarkerUseage;
	_Context->msg_MarkerUseage[5]=nl_MarkerUseage;
	_Context->msg_MarkerUseage[6]=pt_MarkerUseage;
	_Context->msg_MarkerUseage[7]=xx_MarkerUseage;
	_Context->hint_MarkerUseage[0]=en__MarkerUseage;
	_Context->hint_IndexSize[0]=en__IndexSize;
	_Context->hint_NbIndex[0]=en__NbIndex;
	_Context->hint_RecordSize[0]=en__RecordSize;
	_Context->hint_NbData[0]=en__NbData;
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
	for (i=0; i < 8; i++)_Context->msg_ModelOpen[i]=" ";
	_Context->msg_ModelOpen[0]=en_ModelOpen;
	_Context->msg_ModelOpen[1]=fr_ModelOpen;
	_Context->msg_ModelOpen[2]=it_ModelOpen;
	_Context->msg_ModelOpen[3]=es_ModelOpen;
	_Context->msg_ModelOpen[4]=de_ModelOpen;
	_Context->msg_ModelOpen[5]=nl_ModelOpen;
	_Context->msg_ModelOpen[6]=pt_ModelOpen;
	_Context->msg_ModelOpen[7]=xx_ModelOpen;
	_Context->hint_ModelOpen[0]=en__ModelOpen;
	_Context->hint_ModelOpen[1]=fr__ModelOpen;
	_Context->hint_ModelOpen[2]=it__ModelOpen;
	_Context->hint_ModelOpen[3]=es__ModelOpen;
	_Context->hint_ModelOpen[4]=de__ModelOpen;
	_Context->hint_ModelOpen[5]=nl__ModelOpen;
	_Context->hint_ModelOpen[6]=pt__ModelOpen;
	_Context->hint_ModelOpen[7]=xx__ModelOpen;
	for (i=0; i < 8; i++)_Context->msg_ModelLock[i]=" ";
	_Context->msg_ModelLock[0]=en_ModelLock;
	_Context->msg_ModelLock[1]=fr_ModelLock;
	_Context->msg_ModelLock[2]=it_ModelLock;
	_Context->msg_ModelLock[3]=es_ModelLock;
	_Context->msg_ModelLock[4]=de_ModelLock;
	_Context->msg_ModelLock[5]=nl_ModelLock;
	_Context->msg_ModelLock[6]=pt_ModelLock;
	_Context->msg_ModelLock[7]=xx_ModelLock;
	_Context->hint_ModelLock[0]=en__ModelLock;
	_Context->hint_ModelLock[1]=fr__ModelLock;
	_Context->hint_ModelLock[2]=it__ModelLock;
	_Context->hint_ModelLock[3]=es__ModelLock;
	_Context->hint_ModelLock[4]=de__ModelLock;
	_Context->hint_ModelLock[5]=nl__ModelLock;
	_Context->hint_ModelLock[6]=pt__ModelLock;
	_Context->hint_ModelLock[7]=xx__ModelLock;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3633,_Context->y_Auto3633,460+10,320+10);
	return(0);
}

public 	int	accept_model_properties_hide(struct accept_model_properties_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3633,_Context->y_Auto3633);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_model_properties_remove(
	struct accept_model_properties_context * _Context,
	char * pClassName,
	char * pInstance,
	char * pFilename,
	char * pFileType,
	char * pIndexType,
	char * pRecordType,
	char * pModext,
	char * pMarkerUseage,
	char * pIndexSize,
	char * pNbIndex,
	char * pRecordSize,
	char * pNbData,
	char * pModelOpen,
	char * pModelLock)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSWWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_ClassName, 255, pClassName);
		visual_transferout(_Context->buffer_Instance, 255, pInstance);
		visual_transferout(_Context->buffer_Filename, 255, pFilename);
		visual_transferout((void *) 0, 0, pFileType);
		if ( pFileType != (char *) 0)
			*((int*)pFileType) = _Context->value_FileType;
		visual_transferout((void *) 0, 0, pIndexType);
		if ( pIndexType != (char *) 0)
			*((int*)pIndexType) = _Context->value_IndexType;
		visual_transferout((void *) 0, 0, pRecordType);
		if ( pRecordType != (char *) 0)
			*((int*)pRecordType) = _Context->value_RecordType;
		visual_transferout((void *) 0, 0, pModext);
		if ( pModext != (char *) 0)
			*((int*)pModext) = _Context->value_Modext;
		visual_transferout((void *) 0, 0, pMarkerUseage);
		if ( pMarkerUseage != (char *) 0)
			*((int*)pMarkerUseage) = _Context->value_MarkerUseage;
		visual_transferout(_Context->buffer_IndexSize, 8, pIndexSize);
		visual_transferout(_Context->buffer_NbIndex, 8, pNbIndex);
		visual_transferout(_Context->buffer_RecordSize, 8, pRecordSize);
		visual_transferout(_Context->buffer_NbData, 8, pNbData);
		visual_transferout((void *) 0, 0, pModelOpen);
		if ( pModelOpen != (char *) 0)
			*((int*)pModelOpen) = _Context->value_ModelOpen;
		visual_transferout((void *) 0, 0, pModelLock);
		if ( pModelLock != (char *) 0)
			*((int*)pModelLock) = _Context->value_ModelLock;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_model_properties_show(struct accept_model_properties_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3633,_Context->y_Auto3633);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3633,_Context->y_Auto3633,460,320,GetWidgetStyle(0),"\0",strlen("\0"))) != 0)
) {
		visual_window(_Context->x_Auto3633,_Context->y_Auto3633,460,320,vfh[2],"\0",strlen("\0"),0x407);
		}
	visual_text(_Context->x_Auto3633+10,_Context->y_Auto3633+30,440,30,vfh[3],16,0,_Context->msg_Auto3634[_Context->language],strlen(_Context->msg_Auto3634[_Context->language]),259);
	visual_frame(_Context->x_Auto3633+10,_Context->y_Auto3633+70,440,100,4);
	visual_frame(_Context->x_Auto3633+10,_Context->y_Auto3633+170,440,70,4);
	visual_frame(_Context->x_Auto3633+10,_Context->y_Auto3633+250,440,60,4);
	visual_text(_Context->x_Auto3633+30,_Context->y_Auto3633+80,70,16,vfh[2],16,0,_Context->msg_Auto3638[_Context->language],strlen(_Context->msg_Auto3638[_Context->language]),1281);
	visual_text(_Context->x_Auto3633+30,_Context->y_Auto3633+100,70,16,vfh[2],16,0,_Context->msg_Auto3639[_Context->language],strlen(_Context->msg_Auto3639[_Context->language]),1281);
	visual_text(_Context->x_Auto3633+30,_Context->y_Auto3633+120,70,16,vfh[2],16,0,_Context->msg_Auto3640[_Context->language],strlen(_Context->msg_Auto3640[_Context->language]),1281);
	visual_text(_Context->x_Auto3633+30,_Context->y_Auto3633+140,70,16,vfh[2],16,0,_Context->msg_Auto3641[_Context->language],strlen(_Context->msg_Auto3641[_Context->language]),1281);
	visual_text(_Context->x_Auto3633+210,_Context->y_Auto3633+140,42,16,vfh[2],16,0,_Context->msg_Auto3642[_Context->language],strlen(_Context->msg_Auto3642[_Context->language]),1281);
	visual_text(_Context->x_Auto3633+200,_Context->y_Auto3633+175,70,16,vfh[2],16,0,_Context->msg_Auto3643[_Context->language],strlen(_Context->msg_Auto3643[_Context->language]),1283);
	visual_text(_Context->x_Auto3633+280,_Context->y_Auto3633+175,84,16,vfh[2],16,0,_Context->msg_Auto3644[_Context->language],strlen(_Context->msg_Auto3644[_Context->language]),1283);
	visual_text(_Context->x_Auto3633+30,_Context->y_Auto3633+190,154,16,vfh[2],16,0,_Context->msg_Auto3645[_Context->language],strlen(_Context->msg_Auto3645[_Context->language]),1281);
	visual_text(_Context->x_Auto3633+30,_Context->y_Auto3633+210,154,16,vfh[2],16,0,_Context->msg_Auto3646[_Context->language],strlen(_Context->msg_Auto3646[_Context->language]),1281);
	visual_frame(_Context->x_Auto3633+110,_Context->y_Auto3633+80,328+2,16+2,5);
	visual_text(_Context->x_Auto3633+110+1,_Context->y_Auto3633+80+1,328,16,vfh[1],16,0,_Context->buffer_ClassName,255,0);
	visual_frame(_Context->x_Auto3633+130,_Context->y_Auto3633+120,8,16,4);
	visual_frame(_Context->x_Auto3633+110,_Context->y_Auto3633+100,328+2,16+2,5);
	visual_text(_Context->x_Auto3633+110+1,_Context->y_Auto3633+100+1,328,16,vfh[1],16,0,_Context->buffer_Instance,255,0);
	visual_frame(_Context->x_Auto3633+110,_Context->y_Auto3633+120,328+2,16+2,5);
	visual_text(_Context->x_Auto3633+110+1,_Context->y_Auto3633+120+1,328,16,vfh[1],16,0,_Context->buffer_Filename,255,0);
	visual_frame(_Context->x_Auto3633+160,_Context->y_Auto3633+140,8,16,4);
	visual_select(_Context->x_Auto3633+110,_Context->y_Auto3633+140,98,96,vfh[2],0,28,parse_selection(WidgetDataList,&_Context->value_FileType),768);
	visual_frame(_Context->x_Auto3633+290,_Context->y_Auto3633+140,8,16,4);
	visual_select(_Context->x_Auto3633+260,_Context->y_Auto3633+140,48,64,vfh[1],0,0,parse_selection(_Context->msg_IndexType[_Context->language],&_Context->value_IndexType),0);
	_Context->trigger_RecordType=visual_trigger_code(_Context->msg_RecordType[_Context->language],strlen(_Context->msg_RecordType[_Context->language]));
	visual_switch(_Context->x_Auto3633+310,_Context->y_Auto3633+140,30,22,vfh[2],27,28,_Context->msg_RecordType[_Context->language],strlen(_Context->msg_RecordType[_Context->language]),_Context->value_RecordType| 0x0030);
	_Context->trigger_Modext=visual_trigger_code(_Context->msg_Modext[_Context->language],strlen(_Context->msg_Modext[_Context->language]));
	visual_switch(_Context->x_Auto3633+342,_Context->y_Auto3633+140,65,22,vfh[2],27,28,_Context->msg_Modext[_Context->language],strlen(_Context->msg_Modext[_Context->language]),_Context->value_Modext| 0x0030);
	_Context->trigger_MarkerUseage=visual_trigger_code(_Context->msg_MarkerUseage[_Context->language],strlen(_Context->msg_MarkerUseage[_Context->language]));
	visual_switch(_Context->x_Auto3633+410,_Context->y_Auto3633+140,30,22,vfh[2],27,28,_Context->msg_MarkerUseage[_Context->language],strlen(_Context->msg_MarkerUseage[_Context->language]),_Context->value_MarkerUseage| 0x0030);
	visual_frame(_Context->x_Auto3633+230,_Context->y_Auto3633+190,8,16,4);
	visual_frame(_Context->x_Auto3633+200,_Context->y_Auto3633+190,64+2,16+2,5);
	visual_text(_Context->x_Auto3633+200+1,_Context->y_Auto3633+190+1,64,16,vfh[1],16,0,_Context->buffer_IndexSize,8,0);
	visual_frame(_Context->x_Auto3633+290,_Context->y_Auto3633+190,64+2,16+2,5);
	visual_text(_Context->x_Auto3633+290+1,_Context->y_Auto3633+190+1,64,16,vfh[1],16,0,_Context->buffer_NbIndex,8,0);
	visual_frame(_Context->x_Auto3633+200,_Context->y_Auto3633+210,64+2,16+2,5);
	visual_text(_Context->x_Auto3633+200+1,_Context->y_Auto3633+210+1,64,16,vfh[1],16,0,_Context->buffer_RecordSize,8,0);
	visual_frame(_Context->x_Auto3633+290,_Context->y_Auto3633+210,64+2,16+2,5);
	visual_text(_Context->x_Auto3633+290+1,_Context->y_Auto3633+210+1,64,16,vfh[1],16,0,_Context->buffer_NbData,8,0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3633+17,_Context->y_Auto3633+256,56,48,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3633+387,_Context->y_Auto3633+256,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	_Context->trigger_ModelOpen=visual_trigger_code(_Context->msg_ModelOpen[_Context->language],strlen(_Context->msg_ModelOpen[_Context->language]));
	visual_check(_Context->x_Auto3633+110,_Context->y_Auto3633+260,252,16,vfh[2],16,28,_Context->msg_ModelOpen[_Context->language],strlen(_Context->msg_ModelOpen[_Context->language]),_Context->value_ModelOpen|0);
	_Context->trigger_ModelLock=visual_trigger_code(_Context->msg_ModelLock[_Context->language],strlen(_Context->msg_ModelLock[_Context->language]));
	visual_check(_Context->x_Auto3633+110,_Context->y_Auto3633+280,252,16,vfh[2],16,28,_Context->msg_ModelLock[_Context->language],strlen(_Context->msg_ModelLock[_Context->language]),_Context->value_ModelLock|0);
	visual_thaw(_Context->x_Auto3633,_Context->y_Auto3633,460,320);

	return(0);
}

private int Auto3633action(struct accept_model_properties_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_model_properties_hide(_Context);

		_Context->x_Auto3633 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3633 < 0) { _Context->x_Auto3633=0; }
		_Context->y_Auto3633 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3633 < 0) { _Context->y_Auto3633=0; }
			accept_model_properties_show(_Context);

		visual_thaw(_Context->x_Auto3633,_Context->y_Auto3633,460,320);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_model_properties_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_model_properties_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_model_properties_event(
struct accept_model_properties_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_RecordType == mb ) return(7);
		if (_Context->trigger_Modext == mb ) return(8);
		if (_Context->trigger_MarkerUseage == mb ) return(9);
		if (_Context->trigger_Accept == mb ) return(14);
		if (_Context->trigger_Cancel == mb ) return(15);
		if (_Context->trigger_ModelOpen == mb ) return(16);
		if (_Context->trigger_ModelLock == mb ) return(17);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3633+439) )  
	&&  (my >= (_Context->y_Auto3633+4) )  
	&&  (mx <= (_Context->x_Auto3633+456) )  
	&&  (my <= (_Context->y_Auto3633+20) )) {
		return(1);	/* Auto3633 */

		}
	if ((mx >= (_Context->x_Auto3633+423) )  
	&&  (my >= (_Context->y_Auto3633+4) )  
	&&  (mx <= (_Context->x_Auto3633+440) )  
	&&  (my <= (_Context->y_Auto3633+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vmodel.htm");
			};
		return(-1);	/* Auto3633 */

		}
	if ((mx >= (_Context->x_Auto3633+407) )  
	&&  (my >= (_Context->y_Auto3633+4) )  
	&&  (mx <= (_Context->x_Auto3633+424) )  
	&&  (my <= (_Context->y_Auto3633+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_model_properties_show(_Context);
		return(-1);	/* Auto3633 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3633+4) )  
		&&  (my >= (_Context->y_Auto3633+4) )  
		&&  (mx <= (_Context->x_Auto3633+392) )  
		&&  (my <= (_Context->y_Auto3633+20) )) {
			return( Auto3633action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3633+110) ) 
	&&  ( my >= (_Context->y_Auto3633+80) ) 
	&&  ( mx <= (_Context->x_Auto3633+110+328) ) 
	&&  ( my <= (_Context->y_Auto3633+80+16))) {
		return(2); /* ClassName */
		}
	if (( mx >= (_Context->x_Auto3633+110) ) 
	&&  ( my >= (_Context->y_Auto3633+100) ) 
	&&  ( mx <= (_Context->x_Auto3633+110+328) ) 
	&&  ( my <= (_Context->y_Auto3633+100+16))) {
		return(3); /* Instance */
		}
	if (( mx >= (_Context->x_Auto3633+110) ) 
	&&  ( my >= (_Context->y_Auto3633+120) ) 
	&&  ( mx <= (_Context->x_Auto3633+110+328) ) 
	&&  ( my <= (_Context->y_Auto3633+120+16))) {
		return(4); /* Filename */
		}
	if (( mx >= (_Context->x_Auto3633+110+0) ) 
	&&  ( my >= (_Context->y_Auto3633+140) ) 
	&&  ( mx <= (_Context->x_Auto3633+110+98) ) 
	&&  ( my <= (_Context->y_Auto3633+140+16))) {
		return(5); /* FileType */
		}
	if (( mx >= (_Context->x_Auto3633+260+0) ) 
	&&  ( my >= (_Context->y_Auto3633+140) ) 
	&&  ( mx <= (_Context->x_Auto3633+260+48) ) 
	&&  ( my <= (_Context->y_Auto3633+140+16))) {
		return(6); /* IndexType */
		}
	if (( mx >= (_Context->x_Auto3633+310) ) 
	&&  ( my >= (_Context->y_Auto3633+140) ) 
	&&  ( mx <= (_Context->x_Auto3633+310+30) ) 
	&&  ( my <= (_Context->y_Auto3633+140+22))) {
		return(7); /* RecordType */
		}
	if (( mx >= (_Context->x_Auto3633+342) ) 
	&&  ( my >= (_Context->y_Auto3633+140) ) 
	&&  ( mx <= (_Context->x_Auto3633+342+65) ) 
	&&  ( my <= (_Context->y_Auto3633+140+22))) {
		return(8); /* Modext */
		}
	if (( mx >= (_Context->x_Auto3633+410) ) 
	&&  ( my >= (_Context->y_Auto3633+140) ) 
	&&  ( mx <= (_Context->x_Auto3633+410+30) ) 
	&&  ( my <= (_Context->y_Auto3633+140+22))) {
		return(9); /* MarkerUseage */
		}
	if (( mx >= (_Context->x_Auto3633+200) ) 
	&&  ( my >= (_Context->y_Auto3633+190) ) 
	&&  ( mx <= (_Context->x_Auto3633+200+64) ) 
	&&  ( my <= (_Context->y_Auto3633+190+16))) {
		return(10); /* IndexSize */
		}
	if (( mx >= (_Context->x_Auto3633+290) ) 
	&&  ( my >= (_Context->y_Auto3633+190) ) 
	&&  ( mx <= (_Context->x_Auto3633+290+64) ) 
	&&  ( my <= (_Context->y_Auto3633+190+16))) {
		return(11); /* NbIndex */
		}
	if (( mx >= (_Context->x_Auto3633+200) ) 
	&&  ( my >= (_Context->y_Auto3633+210) ) 
	&&  ( mx <= (_Context->x_Auto3633+200+64) ) 
	&&  ( my <= (_Context->y_Auto3633+210+16))) {
		return(12); /* RecordSize */
		}
	if (( mx >= (_Context->x_Auto3633+290) ) 
	&&  ( my >= (_Context->y_Auto3633+210) ) 
	&&  ( mx <= (_Context->x_Auto3633+290+64) ) 
	&&  ( my <= (_Context->y_Auto3633+210+16))) {
		return(13); /* NbData */
		}
	if (( mx >= (_Context->x_Auto3633+17) ) 
	&&  ( my >= (_Context->y_Auto3633+256) ) 
	&&  ( mx <= (_Context->x_Auto3633+17+56) ) 
	&&  ( my <= (_Context->y_Auto3633+256+48))) {
		return(14); /* Accept */
		}
	if (( mx >= (_Context->x_Auto3633+387) ) 
	&&  ( my >= (_Context->y_Auto3633+256) ) 
	&&  ( mx <= (_Context->x_Auto3633+387+56) ) 
	&&  ( my <= (_Context->y_Auto3633+256+48))) {
		return(15); /* Cancel */
		}
	if (( mx >= (_Context->x_Auto3633+110) ) 
	&&  ( my >= (_Context->y_Auto3633+260) ) 
	&&  ( mx <= (_Context->x_Auto3633+110+252) ) 
	&&  ( my <= (_Context->y_Auto3633+260+16))) {
		return(16); /* ModelOpen */
		}
	if (( mx >= (_Context->x_Auto3633+110) ) 
	&&  ( my >= (_Context->y_Auto3633+280) ) 
	&&  ( mx <= (_Context->x_Auto3633+110+252) ) 
	&&  ( my <= (_Context->y_Auto3633+280+16))) {
		return(17); /* ModelLock */
		}

	return(-1);
}


public	int	accept_model_properties_focus(struct accept_model_properties_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* ClassName */
				_Context->keycode = visual_edit(_Context->x_Auto3633+110+1,_Context->y_Auto3633+80+1,328,16,vfh[1],_Context->buffer_ClassName,255);
			break;
			case	0x3 :
				/* Instance */
				_Context->keycode = visual_edit(_Context->x_Auto3633+110+1,_Context->y_Auto3633+100+1,328,16,vfh[1],_Context->buffer_Instance,255);
			break;
			case	0x4 :
				/* Filename */
				_Context->keycode = visual_edit(_Context->x_Auto3633+110+1,_Context->y_Auto3633+120+1,328,16,vfh[1],_Context->buffer_Filename,255);
			break;
			case	0x5 :
				/* FileType */
				_Context->keycode = visual_select(_Context->x_Auto3633+110,_Context->y_Auto3633+140,98,96,vfh[2],0,28,parse_selection(WidgetDataList,&_Context->value_FileType),770);
				break;
			case	0x6 :
				/* IndexType */
				_Context->keycode = visual_select(_Context->x_Auto3633+260,_Context->y_Auto3633+140,48,64,vfh[1],0,0,parse_selection(_Context->msg_IndexType[_Context->language],&_Context->value_IndexType),2);
				break;
			case	0x7 :
				/* RecordType */
				visual_switch(_Context->x_Auto3633+310,_Context->y_Auto3633+140,30,22,vfh[2],27,28,_Context->msg_RecordType[_Context->language],strlen(_Context->msg_RecordType[_Context->language]),(_Context->value_RecordType | 2 | 0x0030 ));
				_Context->keycode = visual_getch();
				_Context->trigger_RecordType=visual_trigger_code(_Context->msg_RecordType[_Context->language],strlen(_Context->msg_RecordType[_Context->language]));
	visual_switch(_Context->x_Auto3633+310,_Context->y_Auto3633+140,30,22,vfh[2],27,28,_Context->msg_RecordType[_Context->language],strlen(_Context->msg_RecordType[_Context->language]),_Context->value_RecordType| 0x0030);
				break;
			case	0x8 :
				/* Modext */
				visual_switch(_Context->x_Auto3633+342,_Context->y_Auto3633+140,65,22,vfh[2],27,28,_Context->msg_Modext[_Context->language],strlen(_Context->msg_Modext[_Context->language]),(_Context->value_Modext | 2 | 0x0030 ));
				_Context->keycode = visual_getch();
				_Context->trigger_Modext=visual_trigger_code(_Context->msg_Modext[_Context->language],strlen(_Context->msg_Modext[_Context->language]));
	visual_switch(_Context->x_Auto3633+342,_Context->y_Auto3633+140,65,22,vfh[2],27,28,_Context->msg_Modext[_Context->language],strlen(_Context->msg_Modext[_Context->language]),_Context->value_Modext| 0x0030);
				break;
			case	0x9 :
				/* MarkerUseage */
				visual_switch(_Context->x_Auto3633+410,_Context->y_Auto3633+140,30,22,vfh[2],27,28,_Context->msg_MarkerUseage[_Context->language],strlen(_Context->msg_MarkerUseage[_Context->language]),(_Context->value_MarkerUseage | 2 | 0x0030 ));
				_Context->keycode = visual_getch();
				_Context->trigger_MarkerUseage=visual_trigger_code(_Context->msg_MarkerUseage[_Context->language],strlen(_Context->msg_MarkerUseage[_Context->language]));
	visual_switch(_Context->x_Auto3633+410,_Context->y_Auto3633+140,30,22,vfh[2],27,28,_Context->msg_MarkerUseage[_Context->language],strlen(_Context->msg_MarkerUseage[_Context->language]),_Context->value_MarkerUseage| 0x0030);
				break;
			case	0xa :
				/* IndexSize */
				_Context->keycode = visual_edit(_Context->x_Auto3633+200+1,_Context->y_Auto3633+190+1,64,16,vfh[1],_Context->buffer_IndexSize,8);
			break;
			case	0xc :
				/* RecordSize */
				_Context->keycode = visual_edit(_Context->x_Auto3633+200+1,_Context->y_Auto3633+210+1,64,16,vfh[1],_Context->buffer_RecordSize,8);
			break;
			case	0xe :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(_Context->x_Auto3633+17,_Context->y_Auto3633+256,56,48,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3633+17,_Context->y_Auto3633+256,56,48,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0xf :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_Auto3633+387,_Context->y_Auto3633+256,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3633+387,_Context->y_Auto3633+256,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;
			case	0x10 :
				/* ModelOpen */
				visual_check(_Context->x_Auto3633+110,_Context->y_Auto3633+260,252,16,vfh[2],16,28,_Context->msg_ModelOpen[_Context->language],strlen(_Context->msg_ModelOpen[_Context->language]),(_Context->value_ModelOpen |2));
				_Context->keycode = visual_getch();
				_Context->trigger_ModelOpen=visual_trigger_code(_Context->msg_ModelOpen[_Context->language],strlen(_Context->msg_ModelOpen[_Context->language]));
	visual_check(_Context->x_Auto3633+110,_Context->y_Auto3633+260,252,16,vfh[2],16,28,_Context->msg_ModelOpen[_Context->language],strlen(_Context->msg_ModelOpen[_Context->language]),_Context->value_ModelOpen|0);
				break;
			case	0x11 :
				/* ModelLock */
				visual_check(_Context->x_Auto3633+110,_Context->y_Auto3633+280,252,16,vfh[2],16,28,_Context->msg_ModelLock[_Context->language],strlen(_Context->msg_ModelLock[_Context->language]),(_Context->value_ModelLock |2));
				_Context->keycode = visual_getch();
				_Context->trigger_ModelLock=visual_trigger_code(_Context->msg_ModelLock[_Context->language],strlen(_Context->msg_ModelLock[_Context->language]));
	visual_check(_Context->x_Auto3633+110,_Context->y_Auto3633+280,252,16,vfh[2],16,28,_Context->msg_ModelLock[_Context->language],strlen(_Context->msg_ModelLock[_Context->language]),_Context->value_ModelLock|0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_model_properties_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=17;
			accept_model_properties_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_model_properties_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3633 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* ClassName */
					continue;
				case	0x3 :
					/* Instance */
					continue;
				case	0x4 :
					/* Filename */
					continue;
				case	0x5 :
					/* FileType */
					continue;
				case	0x6 :
					/* IndexType */
					continue;
				case	0x7 :
					/* RecordType */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_RecordType += 1;
						_Context->value_RecordType &= 1;
						}
					continue;
				case	0x8 :
					/* Modext */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Modext += 1;
						_Context->value_Modext &= 1;
						}
					continue;
				case	0x9 :
					/* MarkerUseage */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_MarkerUseage += 1;
						_Context->value_MarkerUseage &= 1;
						}
					continue;
				case	0xa :
					/* IndexSize */
					continue;
				case	0xb :
					/* NbIndex */
					continue;
				case	0xc :
					/* RecordSize */
					continue;
				case	0xd :
					/* NbData */
					continue;
				case	0xe :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_Auto3633+17,_Context->y_Auto3633+256,56,48,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3633+17,_Context->y_Auto3633+256,56,48,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0xf :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Auto3633+387,_Context->y_Auto3633+256,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3633+387,_Context->y_Auto3633+256,56,48,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

						}
					continue;
				case	0x10 :
					/* ModelOpen */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ModelOpen += 1;
						_Context->value_ModelOpen &= 1;
						}
					continue;
				case	0x11 :
					/* ModelLock */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ModelLock += 1;
						_Context->value_ModelLock &= 1;
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
				_Context->focus_item=17;
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

public	int	accept_model_properties(
	char * pClassName,
	char * pInstance,
	char * pFilename,
	char * pFileType,
	char * pIndexType,
	char * pRecordType,
	char * pModext,
	char * pMarkerUseage,
	char * pIndexSize,
	char * pNbIndex,
	char * pRecordSize,
	char * pNbData,
	char * pModelOpen,
	char * pModelLock)
{
	int	status=0;
	struct accept_model_properties_context * _Context=(struct accept_model_properties_context*) 0;
	status = accept_model_properties_create(
	&_Context,
	 pClassName,
	 pInstance,
	 pFilename,
	 pFileType,
	 pIndexType,
	 pRecordType,
	 pModext,
	 pMarkerUseage,
	 pIndexSize,
	 pNbIndex,
	 pRecordSize,
	 pNbData,
	 pModelOpen,
	 pModelLock);
	if ( status != 0) return(status);
	status = accept_model_properties_show(_Context);
		enter_modal();
	status = accept_model_properties_focus(_Context);
		leave_modal();
	status = accept_model_properties_hide(_Context);
	status = accept_model_properties_remove(
	_Context,
	 pClassName,
	 pInstance,
	 pFilename,
	 pFileType,
	 pIndexType,
	 pRecordType,
	 pModext,
	 pMarkerUseage,
	 pIndexSize,
	 pNbIndex,
	 pRecordSize,
	 pNbData,
	 pModelOpen,
	 pModelLock);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vmodel_c */
