
#ifndef _vorder_c
#define _vorder_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vorder.xml                                               */
/* Target         : vorder.c                                                 */
/* Identification : 0.0-1177511936-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en__Auto2751   ""
#define fr__Auto2751   ""
#define it__Auto2751   ""
#define es__Auto2751   ""
#define de__Auto2751   ""
#define nl__Auto2751   ""
#define pt__Auto2751   ""
#define xx__Auto2751   ""
#define en_Auto2752   "Sort Camera"
#define fr_Auto2752   "Trier les composants"
#define it_Auto2752   "Sort Camera"
#define es_Auto2752   "Sort Camera"
#define de_Auto2752   "Sort Camera"
#define nl_Auto2752   "Sort Camera"
#define pt_Auto2752   "Sort Camera"
#define xx_Auto2752   "Sort Camera"
#define en_Auto2755   "Sort"
#define fr_Auto2755   "Trier"
#define it_Auto2755   "Sort"
#define es_Auto2755   "Sort"
#define de_Auto2755   "Sort"
#define nl_Auto2755   "Sort"
#define pt_Auto2755   "Sort"
#define xx_Auto2755   "Sort"
#define en_Auto2756   "Position"
#define fr_Auto2756   "Position"
#define it_Auto2756   "Position"
#define es_Auto2756   "Position"
#define de_Auto2756   "Position"
#define nl_Auto2756   "Position"
#define pt_Auto2756   "Position"
#define xx_Auto2756   "Position"
#define en_Auto2757   "Column Count"
#define fr_Auto2757   "Nombre colonnes"
#define it_Auto2757   "Column Count"
#define es_Auto2757   "Column Count"
#define de_Auto2757   "Column Count"
#define nl_Auto2757   "Column Count"
#define pt_Auto2757   "Column Count"
#define xx_Auto2757   "Column Count"
#define en_Auto2758   "Row Count"
#define fr_Auto2758   "Nombre rang‚s"
#define it_Auto2758   "Row Count"
#define es_Auto2758   "Row Count"
#define de_Auto2758   "Row Count"
#define nl_Auto2758   "Row Count"
#define pt_Auto2758   "Row Count"
#define xx_Auto2758   "Row Count"
#define en_SortMode   "By Column|By Row|By Structure"
#define fr_SortMode   "Par colonne|Par rang‚"
#define it_SortMode   "By Column|By Row"
#define es_SortMode   "By Column|By Row"
#define de_SortMode   "By Column|By Row"
#define nl_SortMode   "By Column|By Row"
#define pt_SortMode   "By Column|By Row"
#define xx_SortMode   "By Column|By Row"
#define en__SortMode   ""
#define en_SortType   "All Types|Forms|Sources|Images"
#define fr_SortType   "Tout Types|Formulaires|Sources|Images"
#define it_SortType   "All Types|Forms|Sources|Images"
#define es_SortType   "All Types|Forms|Sources|Images"
#define de_SortType   "All Types|Forms|Sources|Images"
#define nl_SortType   "All Types|Forms|Sources|Images"
#define pt_SortType   "All Types|Forms|Sources|Images"
#define xx_SortType   "All Types|Forms|Sources|Images"
#define en_Align   "Left|Center|Right|None"
#define fr_Align   "Gauche|Centr‚|Droite|Sans"
#define it_Align   "Left|Center|Right|None"
#define es_Align   "Left|Center|Right|None"
#define de_Align   "Left|Center|Right|None"
#define nl_Align   "Left|Center|Right|None"
#define pt_Align   "Left|Center|Right|None"
#define xx_Align   "Left|Center|Right|None"
#define en_atX   ""
#define en_atY   ""
#define en_atZ   ""
#define en_nbCols   ""
#define en_nbRows   ""
#define en_Auto2759   "ok.gif"
#define fr_Auto2759   "ok.gif"
#define it_Auto2759   "ok.gif"
#define es_Auto2759   "ok.gif"
#define de_Auto2759   "ok.gif"
#define nl_Auto2759   "ok.gif"
#define pt_Auto2759   "ok.gif"
#define xx_Auto2759   "ok.gif"
#define en_Auto2760   "cancel.gif"
#define fr_Auto2760   "cancel.gif"
#define it_Auto2760   "cancel.gif"
#define es_Auto2760   "cancel.gif"
#define de_Auto2760   "cancel.gif"
#define nl_Auto2760   "cancel.gif"
#define pt_Auto2760   "cancel.gif"
#define xx_Auto2760   "cancel.gif"

private struct accept_sort_camera_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto2751[8];
	char * hint_Auto2751[8];
	int	x_Auto2751;
	int	y_Auto2751;
	int	w_Auto2751;
	int	h_Auto2751;
	char * msg_Auto2752[8];
	char * hint_Auto2752[8];
	char * hint_Auto2753[8];
	char * hint_Auto2754[8];
	char * msg_Auto2755[8];
	char * hint_Auto2755[8];
	char * msg_Auto2756[8];
	char * hint_Auto2756[8];
	char * msg_Auto2757[8];
	char * hint_Auto2757[8];
	char * msg_Auto2758[8];
	char * hint_Auto2758[8];
	char * msg_SortMode[8];
	char * hint_SortMode[8];
	int	value_SortMode;
	char * msg_SortType[8];
	char * hint_SortType[8];
	int	value_SortType;
	char * msg_Align[8];
	char * hint_Align[8];
	int	value_Align;
	char * hint_atX[8];
	char	buffer_atX[13];
	char * hint_atY[8];
	char	buffer_atY[13];
	char * hint_atZ[8];
	char	buffer_atZ[13];
	char * hint_nbCols[8];
	char	buffer_nbCols[13];
	char * hint_nbRows[8];
	char	buffer_nbRows[13];
	char * msg_Auto2759[8];
	int	trigger_Auto2759;
	char * hint_Auto2759[8];
	char * msg_Auto2760[8];
	int	trigger_Auto2760;
	char * hint_Auto2760[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[9];
	};
static int	vfh[16];

public	int	accept_sort_camera_create(
	struct accept_sort_camera_context ** cptr,
	char * pSortMode,
	char * pSortType,
	char * pAlign,
	char * patX,
	char * patY,
	char * patZ,
	char * pnbCols,
	char * pnbRows)
{

	int i;
	struct accept_sort_camera_context * _Context=(struct accept_sort_camera_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_sort_camera_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=11;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pSortMode);
		if (!( pSortMode )) _Context->value_SortMode=0;
		else	_Context->value_SortMode = *((int *)pSortMode);
		visual_transferin((void *) 0, 0, pSortType);
		if (!( pSortType )) _Context->value_SortType=0;
		else	_Context->value_SortType = *((int *)pSortType);
		visual_transferin((void *) 0, 0, pAlign);
		if (!( pAlign )) _Context->value_Align=0;
		else	_Context->value_Align = *((int *)pAlign);
		visual_transferin(_Context->buffer_atX, 12, patX);
		visual_transferin(_Context->buffer_atY, 12, patY);
		visual_transferin(_Context->buffer_atZ, 12, patZ);
		visual_transferin(_Context->buffer_nbCols, 12, pnbCols);
		visual_transferin(_Context->buffer_nbRows, 12, pnbRows);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto2751[i]=" ";
	_Context->hint_Auto2751[0]=en__Auto2751;
	_Context->hint_Auto2751[1]=fr__Auto2751;
	_Context->hint_Auto2751[2]=it__Auto2751;
	_Context->hint_Auto2751[3]=es__Auto2751;
	_Context->hint_Auto2751[4]=de__Auto2751;
	_Context->hint_Auto2751[5]=nl__Auto2751;
	_Context->hint_Auto2751[6]=pt__Auto2751;
	_Context->hint_Auto2751[7]=xx__Auto2751;
	_Context->x_Auto2751=150;
	_Context->y_Auto2751=170;
	_Context->w_Auto2751=500;
	_Context->h_Auto2751=260;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2752[i]=" ";
	_Context->msg_Auto2752[0]=en_Auto2752;
	_Context->msg_Auto2752[1]=fr_Auto2752;
	_Context->msg_Auto2752[2]=it_Auto2752;
	_Context->msg_Auto2752[3]=es_Auto2752;
	_Context->msg_Auto2752[4]=de_Auto2752;
	_Context->msg_Auto2752[5]=nl_Auto2752;
	_Context->msg_Auto2752[6]=pt_Auto2752;
	_Context->msg_Auto2752[7]=xx_Auto2752;
	for (i=0; i < 8; i++)_Context->msg_Auto2755[i]=" ";
	_Context->msg_Auto2755[0]=en_Auto2755;
	_Context->msg_Auto2755[1]=fr_Auto2755;
	_Context->msg_Auto2755[2]=it_Auto2755;
	_Context->msg_Auto2755[3]=es_Auto2755;
	_Context->msg_Auto2755[4]=de_Auto2755;
	_Context->msg_Auto2755[5]=nl_Auto2755;
	_Context->msg_Auto2755[6]=pt_Auto2755;
	_Context->msg_Auto2755[7]=xx_Auto2755;
	for (i=0; i < 8; i++)_Context->msg_Auto2756[i]=" ";
	_Context->msg_Auto2756[0]=en_Auto2756;
	_Context->msg_Auto2756[1]=fr_Auto2756;
	_Context->msg_Auto2756[2]=it_Auto2756;
	_Context->msg_Auto2756[3]=es_Auto2756;
	_Context->msg_Auto2756[4]=de_Auto2756;
	_Context->msg_Auto2756[5]=nl_Auto2756;
	_Context->msg_Auto2756[6]=pt_Auto2756;
	_Context->msg_Auto2756[7]=xx_Auto2756;
	for (i=0; i < 8; i++)_Context->msg_Auto2757[i]=" ";
	_Context->msg_Auto2757[0]=en_Auto2757;
	_Context->msg_Auto2757[1]=fr_Auto2757;
	_Context->msg_Auto2757[2]=it_Auto2757;
	_Context->msg_Auto2757[3]=es_Auto2757;
	_Context->msg_Auto2757[4]=de_Auto2757;
	_Context->msg_Auto2757[5]=nl_Auto2757;
	_Context->msg_Auto2757[6]=pt_Auto2757;
	_Context->msg_Auto2757[7]=xx_Auto2757;
	for (i=0; i < 8; i++)_Context->msg_Auto2758[i]=" ";
	_Context->msg_Auto2758[0]=en_Auto2758;
	_Context->msg_Auto2758[1]=fr_Auto2758;
	_Context->msg_Auto2758[2]=it_Auto2758;
	_Context->msg_Auto2758[3]=es_Auto2758;
	_Context->msg_Auto2758[4]=de_Auto2758;
	_Context->msg_Auto2758[5]=nl_Auto2758;
	_Context->msg_Auto2758[6]=pt_Auto2758;
	_Context->msg_Auto2758[7]=xx_Auto2758;
	for (i=0; i < 8; i++)_Context->msg_SortMode[i]=" ";
	_Context->msg_SortMode[0]=en_SortMode;
	_Context->msg_SortMode[1]=fr_SortMode;
	_Context->msg_SortMode[2]=it_SortMode;
	_Context->msg_SortMode[3]=es_SortMode;
	_Context->msg_SortMode[4]=de_SortMode;
	_Context->msg_SortMode[5]=nl_SortMode;
	_Context->msg_SortMode[6]=pt_SortMode;
	_Context->msg_SortMode[7]=xx_SortMode;
	_Context->hint_SortMode[0]=en__SortMode;
	for (i=0; i < 8; i++)_Context->msg_SortType[i]=" ";
	_Context->msg_SortType[0]=en_SortType;
	_Context->msg_SortType[1]=fr_SortType;
	_Context->msg_SortType[2]=it_SortType;
	_Context->msg_SortType[3]=es_SortType;
	_Context->msg_SortType[4]=de_SortType;
	_Context->msg_SortType[5]=nl_SortType;
	_Context->msg_SortType[6]=pt_SortType;
	_Context->msg_SortType[7]=xx_SortType;
	for (i=0; i < 8; i++)_Context->msg_Align[i]=" ";
	_Context->msg_Align[0]=en_Align;
	_Context->msg_Align[1]=fr_Align;
	_Context->msg_Align[2]=it_Align;
	_Context->msg_Align[3]=es_Align;
	_Context->msg_Align[4]=de_Align;
	_Context->msg_Align[5]=nl_Align;
	_Context->msg_Align[6]=pt_Align;
	_Context->msg_Align[7]=xx_Align;
	for (i=0; i < 8; i++)_Context->msg_Auto2759[i]=" ";
	_Context->msg_Auto2759[0]=en_Auto2759;
	_Context->msg_Auto2759[1]=fr_Auto2759;
	_Context->msg_Auto2759[2]=it_Auto2759;
	_Context->msg_Auto2759[3]=es_Auto2759;
	_Context->msg_Auto2759[4]=de_Auto2759;
	_Context->msg_Auto2759[5]=nl_Auto2759;
	_Context->msg_Auto2759[6]=pt_Auto2759;
	_Context->msg_Auto2759[7]=xx_Auto2759;
	for (i=0; i < 8; i++)_Context->msg_Auto2760[i]=" ";
	_Context->msg_Auto2760[0]=en_Auto2760;
	_Context->msg_Auto2760[1]=fr_Auto2760;
	_Context->msg_Auto2760[2]=it_Auto2760;
	_Context->msg_Auto2760[3]=es_Auto2760;
	_Context->msg_Auto2760[4]=de_Auto2760;
	_Context->msg_Auto2760[5]=nl_Auto2760;
	_Context->msg_Auto2760[6]=pt_Auto2760;
	_Context->msg_Auto2760[7]=xx_Auto2760;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto2751,_Context->y_Auto2751,500+10,260+10);
	return(0);
}

public 	int	accept_sort_camera_hide(struct accept_sort_camera_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto2751,_Context->y_Auto2751);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_sort_camera_remove(
	struct accept_sort_camera_context * _Context,
	char * pSortMode,
	char * pSortType,
	char * pAlign,
	char * patX,
	char * patY,
	char * patZ,
	char * pnbCols,
	char * pnbRows)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pSortMode);
		if ( pSortMode != (char *) 0)
			*((int*)pSortMode) = _Context->value_SortMode;
		visual_transferout((void *) 0, 0, pSortType);
		if ( pSortType != (char *) 0)
			*((int*)pSortType) = _Context->value_SortType;
		visual_transferout((void *) 0, 0, pAlign);
		if ( pAlign != (char *) 0)
			*((int*)pAlign) = _Context->value_Align;
		visual_transferout(_Context->buffer_atX, 12, patX);
		visual_transferout(_Context->buffer_atY, 12, patY);
		visual_transferout(_Context->buffer_atZ, 12, patZ);
		visual_transferout(_Context->buffer_nbCols, 12, pnbCols);
		visual_transferout(_Context->buffer_nbRows, 12, pnbRows);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_sort_camera_show(struct accept_sort_camera_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto2751,_Context->y_Auto2751);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto2751,_Context->y_Auto2751,500,260,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto2751,_Context->y_Auto2751,500,260,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto2751+10,_Context->y_Auto2751+30,480,16,vfh[2],16,0,_Context->msg_Auto2752[_Context->language],strlen(_Context->msg_Auto2752[_Context->language]),258);
	visual_frame(_Context->x_Auto2751+10,_Context->y_Auto2751+46,480,204,4);
	visual_frame(_Context->x_Auto2751+20,_Context->y_Auto2751+60,460,100,2);
	visual_frame(_Context->x_Auto2751+20,_Context->y_Auto2751+170,460,70,2);
	visual_text(_Context->x_Auto2751+30,_Context->y_Auto2751+70,112,16,vfh[2],16,0,_Context->msg_Auto2755[_Context->language],strlen(_Context->msg_Auto2755[_Context->language]),258);
	visual_text(_Context->x_Auto2751+30,_Context->y_Auto2751+100,112,16,vfh[2],16,0,_Context->msg_Auto2756[_Context->language],strlen(_Context->msg_Auto2756[_Context->language]),258);
	visual_text(_Context->x_Auto2751+30,_Context->y_Auto2751+130,112,16,vfh[2],16,0,_Context->msg_Auto2757[_Context->language],strlen(_Context->msg_Auto2757[_Context->language]),258);
	visual_text(_Context->x_Auto2751+260,_Context->y_Auto2751+130,98,16,vfh[2],16,0,_Context->msg_Auto2758[_Context->language],strlen(_Context->msg_Auto2758[_Context->language]),258);
	visual_select(_Context->x_Auto2751+150,_Context->y_Auto2751+70,96,32,vfh[1],27,28,parse_selection(_Context->msg_SortMode[_Context->language],&_Context->value_SortMode),0);
	visual_select(_Context->x_Auto2751+260,_Context->y_Auto2751+70,96,48,vfh[1],27,28,parse_selection(_Context->msg_SortType[_Context->language],&_Context->value_SortType),0);
	visual_select(_Context->x_Auto2751+370,_Context->y_Auto2751+70,96,48,vfh[1],27,28,parse_selection(_Context->msg_Align[_Context->language],&_Context->value_Align),0);
	visual_frame(_Context->x_Auto2751+150,_Context->y_Auto2751+100,96+2,16+2,5);
	visual_text(_Context->x_Auto2751+150+1,_Context->y_Auto2751+100+1,96,16,vfh[1],27,28,_Context->buffer_atX,12,0);
	visual_frame(_Context->x_Auto2751+260,_Context->y_Auto2751+100,96+2,16+2,5);
	visual_text(_Context->x_Auto2751+260+1,_Context->y_Auto2751+100+1,96,16,vfh[1],27,28,_Context->buffer_atY,12,0);
	visual_frame(_Context->x_Auto2751+370,_Context->y_Auto2751+100,96+2,16+2,5);
	visual_text(_Context->x_Auto2751+370+1,_Context->y_Auto2751+100+1,96,16,vfh[1],27,28,_Context->buffer_atZ,12,0);
	visual_frame(_Context->x_Auto2751+150,_Context->y_Auto2751+130,96+2,16+2,5);
	visual_text(_Context->x_Auto2751+150+1,_Context->y_Auto2751+130+1,96,16,vfh[1],27,28,_Context->buffer_nbCols,12,0);
	visual_frame(_Context->x_Auto2751+370,_Context->y_Auto2751+130,96+2,16+2,5);
	visual_text(_Context->x_Auto2751+370+1,_Context->y_Auto2751+130+1,96,16,vfh[1],27,28,_Context->buffer_nbRows,12,0);
	_Context->trigger_Auto2759=visual_trigger_code(_Context->msg_Auto2759[_Context->language],strlen(_Context->msg_Auto2759[_Context->language]));
	visual_button(_Context->x_Auto2751+30,_Context->y_Auto2751+180,56,48,vfh[2],34,0,_Context->msg_Auto2759[_Context->language],strlen(_Context->msg_Auto2759[_Context->language]),1040);
	_Context->trigger_Auto2760=visual_trigger_code(_Context->msg_Auto2760[_Context->language],strlen(_Context->msg_Auto2760[_Context->language]));
	visual_button(_Context->x_Auto2751+410,_Context->y_Auto2751+180,56,48,vfh[2],34,0,_Context->msg_Auto2760[_Context->language],strlen(_Context->msg_Auto2760[_Context->language]),1040);
	visual_thaw(_Context->x_Auto2751,_Context->y_Auto2751,500,260);

	return(0);
}

private int SortMode_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "The project view reorganisation may be performed by column or by row. ";
			mptr[1]="In the former case the objects will be placed from left to right column ";
			mptr[2]="by column and row by row. When column count and row count is exceeded ";
			mptr[3]="an new z plane will be used and the  operation will be repeated. In ";
			mptr[4]="the later case objects will be placed row by row then column by column. ";
			mptr[5]="   ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SortType_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the type of object that will be included ";
			mptr[1]="in the reorganisation operation. This may be any individual type or ";
			mptr[2]="all types.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Align_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control provides alignment of an object within its region. Objects ";
			mptr[1]="smaller than the largest will be aligned either top left, centered ";
			mptr[2]="or bottom right within the larger region.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int atX_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows the initial upper left X coordinate to be specified. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int atY_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows the initial upper left Y coordinate to be specified. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int atZ_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows the initial upper left Z coordinate to be specified. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int nbCols_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This edit field allows the column count to be specified.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int nbRows_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This edit field allows the row count to be specified.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2759_help()
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

private int Auto2760_help()
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

private int Auto2751action(struct accept_sort_camera_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_sort_camera_hide(_Context);

		_Context->x_Auto2751 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto2751 < 0) { _Context->x_Auto2751=0; }
		_Context->y_Auto2751 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto2751 < 0) { _Context->y_Auto2751=0; }
			accept_sort_camera_show(_Context);

		visual_thaw(_Context->x_Auto2751,_Context->y_Auto2751,500,260);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto2759_event(struct accept_sort_camera_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto2760_event(struct accept_sort_camera_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_sort_camera_event(
struct accept_sort_camera_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto2759 == mb ) return(10);
		if (_Context->trigger_Auto2760 == mb ) return(11);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto2751+479) )  
	&&  (my >= (_Context->y_Auto2751+4) )  
	&&  (mx <= (_Context->x_Auto2751+496) )  
	&&  (my <= (_Context->y_Auto2751+20) )) {
		return(1);	/* Auto2751 */

		}
	if ((mx >= (_Context->x_Auto2751+463) )  
	&&  (my >= (_Context->y_Auto2751+4) )  
	&&  (mx <= (_Context->x_Auto2751+480) )  
	&&  (my <= (_Context->y_Auto2751+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vorder.htm");
			};
		return(-1);	/* Auto2751 */

		}
	if ((mx >= (_Context->x_Auto2751+447) )  
	&&  (my >= (_Context->y_Auto2751+4) )  
	&&  (mx <= (_Context->x_Auto2751+464) )  
	&&  (my <= (_Context->y_Auto2751+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_sort_camera_show(_Context);
		return(-1);	/* Auto2751 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto2751+4) )  
		&&  (my >= (_Context->y_Auto2751+4) )  
		&&  (mx <= (_Context->x_Auto2751+432) )  
		&&  (my <= (_Context->y_Auto2751+20) )) {
			return( Auto2751action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto2751+150+0) ) 
	&&  ( my >= (_Context->y_Auto2751+70) ) 
	&&  ( mx <= (_Context->x_Auto2751+150+96) ) 
	&&  ( my <= (_Context->y_Auto2751+70+16))) {
		return(2); /* SortMode */
		}
	if (( mx >= (_Context->x_Auto2751+260+0) ) 
	&&  ( my >= (_Context->y_Auto2751+70) ) 
	&&  ( mx <= (_Context->x_Auto2751+260+96) ) 
	&&  ( my <= (_Context->y_Auto2751+70+16))) {
		return(3); /* SortType */
		}
	if (( mx >= (_Context->x_Auto2751+370+0) ) 
	&&  ( my >= (_Context->y_Auto2751+70) ) 
	&&  ( mx <= (_Context->x_Auto2751+370+96) ) 
	&&  ( my <= (_Context->y_Auto2751+70+16))) {
		return(4); /* Align */
		}
	if (( mx >= (_Context->x_Auto2751+150) ) 
	&&  ( my >= (_Context->y_Auto2751+100) ) 
	&&  ( mx <= (_Context->x_Auto2751+150+96) ) 
	&&  ( my <= (_Context->y_Auto2751+100+16))) {
		return(5); /* atX */
		}
	if (( mx >= (_Context->x_Auto2751+260) ) 
	&&  ( my >= (_Context->y_Auto2751+100) ) 
	&&  ( mx <= (_Context->x_Auto2751+260+96) ) 
	&&  ( my <= (_Context->y_Auto2751+100+16))) {
		return(6); /* atY */
		}
	if (( mx >= (_Context->x_Auto2751+370) ) 
	&&  ( my >= (_Context->y_Auto2751+100) ) 
	&&  ( mx <= (_Context->x_Auto2751+370+96) ) 
	&&  ( my <= (_Context->y_Auto2751+100+16))) {
		return(7); /* atZ */
		}
	if (( mx >= (_Context->x_Auto2751+150) ) 
	&&  ( my >= (_Context->y_Auto2751+130) ) 
	&&  ( mx <= (_Context->x_Auto2751+150+96) ) 
	&&  ( my <= (_Context->y_Auto2751+130+16))) {
		return(8); /* nbCols */
		}
	if (( mx >= (_Context->x_Auto2751+370) ) 
	&&  ( my >= (_Context->y_Auto2751+130) ) 
	&&  ( mx <= (_Context->x_Auto2751+370+96) ) 
	&&  ( my <= (_Context->y_Auto2751+130+16))) {
		return(9); /* nbRows */
		}
	if (( mx >= (_Context->x_Auto2751+30) ) 
	&&  ( my >= (_Context->y_Auto2751+180) ) 
	&&  ( mx <= (_Context->x_Auto2751+30+56) ) 
	&&  ( my <= (_Context->y_Auto2751+180+48))) {
		return(10); /* Auto2759 */
		}
	if (( mx >= (_Context->x_Auto2751+410) ) 
	&&  ( my >= (_Context->y_Auto2751+180) ) 
	&&  ( mx <= (_Context->x_Auto2751+410+56) ) 
	&&  ( my <= (_Context->y_Auto2751+180+48))) {
		return(11); /* Auto2760 */
		}

	return(-1);
}


public	int	accept_sort_camera_focus(struct accept_sort_camera_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* SortMode */
				_Context->keycode = visual_select(_Context->x_Auto2751+150,_Context->y_Auto2751+70,96,32,vfh[1],27,28,parse_selection(_Context->msg_SortMode[_Context->language],&_Context->value_SortMode),2);
				break;
			case	0x3 :
				/* SortType */
				_Context->keycode = visual_select(_Context->x_Auto2751+260,_Context->y_Auto2751+70,96,48,vfh[1],27,28,parse_selection(_Context->msg_SortType[_Context->language],&_Context->value_SortType),2);
				break;
			case	0x4 :
				/* Align */
				_Context->keycode = visual_select(_Context->x_Auto2751+370,_Context->y_Auto2751+70,96,48,vfh[1],27,28,parse_selection(_Context->msg_Align[_Context->language],&_Context->value_Align),2);
				break;
			case	0x5 :
				/* atX */
				_Context->keycode = visual_edit(_Context->x_Auto2751+150+1,_Context->y_Auto2751+100+1,96,16,vfh[1],_Context->buffer_atX,12);
			break;
			case	0x6 :
				/* atY */
				_Context->keycode = visual_edit(_Context->x_Auto2751+260+1,_Context->y_Auto2751+100+1,96,16,vfh[1],_Context->buffer_atY,12);
			break;
			case	0x7 :
				/* atZ */
				_Context->keycode = visual_edit(_Context->x_Auto2751+370+1,_Context->y_Auto2751+100+1,96,16,vfh[1],_Context->buffer_atZ,12);
			break;
			case	0x8 :
				/* nbCols */
				_Context->keycode = visual_edit(_Context->x_Auto2751+150+1,_Context->y_Auto2751+130+1,96,16,vfh[1],_Context->buffer_nbCols,12);
			break;
			case	0x9 :
				/* nbRows */
				_Context->keycode = visual_edit(_Context->x_Auto2751+370+1,_Context->y_Auto2751+130+1,96,16,vfh[1],_Context->buffer_nbRows,12);
			break;
			case	0xa :
				/* Auto2759 */
				_Context->trigger_Auto2759=visual_trigger_code(_Context->msg_Auto2759[_Context->language],strlen(_Context->msg_Auto2759[_Context->language]));
				visual_button(_Context->x_Auto2751+30,_Context->y_Auto2751+180,56,48,vfh[2],34,0,_Context->msg_Auto2759[_Context->language],strlen(_Context->msg_Auto2759[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2759=visual_trigger_code(_Context->msg_Auto2759[_Context->language],strlen(_Context->msg_Auto2759[_Context->language]));
	visual_button(_Context->x_Auto2751+30,_Context->y_Auto2751+180,56,48,vfh[2],34,0,_Context->msg_Auto2759[_Context->language],strlen(_Context->msg_Auto2759[_Context->language]),1040);
				break;
			case	0xb :
				/* Auto2760 */
				_Context->trigger_Auto2760=visual_trigger_code(_Context->msg_Auto2760[_Context->language],strlen(_Context->msg_Auto2760[_Context->language]));
				visual_button(_Context->x_Auto2751+410,_Context->y_Auto2751+180,56,48,vfh[2],34,0,_Context->msg_Auto2760[_Context->language],strlen(_Context->msg_Auto2760[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2760=visual_trigger_code(_Context->msg_Auto2760[_Context->language],strlen(_Context->msg_Auto2760[_Context->language]));
	visual_button(_Context->x_Auto2751+410,_Context->y_Auto2751+180,56,48,vfh[2],34,0,_Context->msg_Auto2760[_Context->language],strlen(_Context->msg_Auto2760[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_sort_camera_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=11;
			accept_sort_camera_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_sort_camera_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (SortMode_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (SortType_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Align_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (atX_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (atY_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (atZ_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (nbCols_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (nbRows_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (Auto2759_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Auto2760_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto2751 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* SortMode */
					continue;
				case	0x3 :
					/* SortType */
					continue;
				case	0x4 :
					/* Align */
					continue;
				case	0x5 :
					/* atX */
					continue;
				case	0x6 :
					/* atY */
					continue;
				case	0x7 :
					/* atZ */
					continue;
				case	0x8 :
					/* nbCols */
					continue;
				case	0x9 :
					/* nbRows */
					continue;
				case	0xa :
					/* Auto2759 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2759=visual_trigger_code(_Context->msg_Auto2759[_Context->language],strlen(_Context->msg_Auto2759[_Context->language]));
						visual_button(_Context->x_Auto2751+30,_Context->y_Auto2751+180,56,48,vfh[2],34,0,_Context->msg_Auto2759[_Context->language],strlen(_Context->msg_Auto2759[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2759=visual_trigger_code(_Context->msg_Auto2759[_Context->language],strlen(_Context->msg_Auto2759[_Context->language]));
	visual_button(_Context->x_Auto2751+30,_Context->y_Auto2751+180,56,48,vfh[2],34,0,_Context->msg_Auto2759[_Context->language],strlen(_Context->msg_Auto2759[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2759_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Auto2760 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2760=visual_trigger_code(_Context->msg_Auto2760[_Context->language],strlen(_Context->msg_Auto2760[_Context->language]));
						visual_button(_Context->x_Auto2751+410,_Context->y_Auto2751+180,56,48,vfh[2],34,0,_Context->msg_Auto2760[_Context->language],strlen(_Context->msg_Auto2760[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2760=visual_trigger_code(_Context->msg_Auto2760[_Context->language],strlen(_Context->msg_Auto2760[_Context->language]));
	visual_button(_Context->x_Auto2751+410,_Context->y_Auto2751+180,56,48,vfh[2],34,0,_Context->msg_Auto2760[_Context->language],strlen(_Context->msg_Auto2760[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2760_event(_Context)) != -1) break;

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

public	int	accept_sort_camera(
	char * pSortMode,
	char * pSortType,
	char * pAlign,
	char * patX,
	char * patY,
	char * patZ,
	char * pnbCols,
	char * pnbRows)
{
	int	status=0;
	struct accept_sort_camera_context * _Context=(struct accept_sort_camera_context*) 0;
	status = accept_sort_camera_create(
	&_Context,
	 pSortMode,
	 pSortType,
	 pAlign,
	 patX,
	 patY,
	 patZ,
	 pnbCols,
	 pnbRows);
	if ( status != 0) return(status);
	status = accept_sort_camera_show(_Context);
		enter_modal();
	status = accept_sort_camera_focus(_Context);
		leave_modal();
	status = accept_sort_camera_hide(_Context);
	status = accept_sort_camera_remove(
	_Context,
	 pSortMode,
	 pSortType,
	 pAlign,
	 patX,
	 patY,
	 patZ,
	 pnbCols,
	 pnbRows);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vorder_c */
