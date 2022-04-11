
#ifndef _vorder_c
#define _vorder_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vorder.xml                                               */
/* Target         : vorder.c                                                 */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en__Auto3580   ""
#define fr__Auto3580   ""
#define it__Auto3580   ""
#define es__Auto3580   ""
#define de__Auto3580   ""
#define nl__Auto3580   ""
#define pt__Auto3580   ""
#define xx__Auto3580   ""
#define en_Auto3581   "Sort Camera"
#define fr_Auto3581   "Trier les composants"
#define it_Auto3581   "Sort Camera"
#define es_Auto3581   "Sort Camera"
#define de_Auto3581   "Sort Camera"
#define nl_Auto3581   "Sort Camera"
#define pt_Auto3581   "Sort Camera"
#define xx_Auto3581   "Sort Camera"
#define en_Auto3584   "Sort"
#define fr_Auto3584   "Trier"
#define it_Auto3584   "Sort"
#define es_Auto3584   "Sort"
#define de_Auto3584   "Sort"
#define nl_Auto3584   "Sort"
#define pt_Auto3584   "Sort"
#define xx_Auto3584   "Sort"
#define en_Auto3585   "Position"
#define fr_Auto3585   "Position"
#define it_Auto3585   "Position"
#define es_Auto3585   "Position"
#define de_Auto3585   "Position"
#define nl_Auto3585   "Position"
#define pt_Auto3585   "Position"
#define xx_Auto3585   "Position"
#define en_Auto3586   "Column Count"
#define fr_Auto3586   "Nombre colonnes"
#define it_Auto3586   "Column Count"
#define es_Auto3586   "Column Count"
#define de_Auto3586   "Column Count"
#define nl_Auto3586   "Column Count"
#define pt_Auto3586   "Column Count"
#define xx_Auto3586   "Column Count"
#define en_Auto3587   "Row Count"
#define fr_Auto3587   "Nombre rang‚s"
#define it_Auto3587   "Row Count"
#define es_Auto3587   "Row Count"
#define de_Auto3587   "Row Count"
#define nl_Auto3587   "Row Count"
#define pt_Auto3587   "Row Count"
#define xx_Auto3587   "Row Count"
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
#define en_Auto3588   "ok.gif"
#define fr_Auto3588   "ok.gif"
#define it_Auto3588   "ok.gif"
#define es_Auto3588   "ok.gif"
#define de_Auto3588   "ok.gif"
#define nl_Auto3588   "ok.gif"
#define pt_Auto3588   "ok.gif"
#define xx_Auto3588   "ok.gif"
#define en_Auto3589   "cancel.gif"
#define fr_Auto3589   "cancel.gif"
#define it_Auto3589   "cancel.gif"
#define es_Auto3589   "cancel.gif"
#define de_Auto3589   "cancel.gif"
#define nl_Auto3589   "cancel.gif"
#define pt_Auto3589   "cancel.gif"
#define xx_Auto3589   "cancel.gif"

private struct accept_sort_camera_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3580[8];
	char * hint_Auto3580[8];
	int	x_Auto3580;
	int	y_Auto3580;
	int	w_Auto3580;
	int	h_Auto3580;
	char * msg_Auto3581[8];
	char * hint_Auto3581[8];
	char * hint_Auto3582[8];
	char * hint_Auto3583[8];
	char * msg_Auto3584[8];
	char * hint_Auto3584[8];
	char * msg_Auto3585[8];
	char * hint_Auto3585[8];
	char * msg_Auto3586[8];
	char * hint_Auto3586[8];
	char * msg_Auto3587[8];
	char * hint_Auto3587[8];
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
	char * msg_Auto3588[8];
	int	trigger_Auto3588;
	char * hint_Auto3588[8];
	char * msg_Auto3589[8];
	int	trigger_Auto3589;
	char * hint_Auto3589[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[9];
	};
static int	vfh[16];
private int on_Auto3588_event(struct accept_sort_camera_context * _Context);
private int on_Auto3589_event(struct accept_sort_camera_context * _Context);

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
	vfh[10] = visual_font("bmap0414.fmf",12);
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
	for (i=0; i < 8; i++)_Context->msg_Auto3580[i]=" ";
	_Context->hint_Auto3580[0]=en__Auto3580;
	_Context->hint_Auto3580[1]=fr__Auto3580;
	_Context->hint_Auto3580[2]=it__Auto3580;
	_Context->hint_Auto3580[3]=es__Auto3580;
	_Context->hint_Auto3580[4]=de__Auto3580;
	_Context->hint_Auto3580[5]=nl__Auto3580;
	_Context->hint_Auto3580[6]=pt__Auto3580;
	_Context->hint_Auto3580[7]=xx__Auto3580;
	_Context->x_Auto3580=150;
	_Context->y_Auto3580=170;
	_Context->w_Auto3580=500;
	_Context->h_Auto3580=260;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3581[i]=" ";
	_Context->msg_Auto3581[0]=en_Auto3581;
	_Context->msg_Auto3581[1]=fr_Auto3581;
	_Context->msg_Auto3581[2]=it_Auto3581;
	_Context->msg_Auto3581[3]=es_Auto3581;
	_Context->msg_Auto3581[4]=de_Auto3581;
	_Context->msg_Auto3581[5]=nl_Auto3581;
	_Context->msg_Auto3581[6]=pt_Auto3581;
	_Context->msg_Auto3581[7]=xx_Auto3581;
	for (i=0; i < 8; i++)_Context->msg_Auto3584[i]=" ";
	_Context->msg_Auto3584[0]=en_Auto3584;
	_Context->msg_Auto3584[1]=fr_Auto3584;
	_Context->msg_Auto3584[2]=it_Auto3584;
	_Context->msg_Auto3584[3]=es_Auto3584;
	_Context->msg_Auto3584[4]=de_Auto3584;
	_Context->msg_Auto3584[5]=nl_Auto3584;
	_Context->msg_Auto3584[6]=pt_Auto3584;
	_Context->msg_Auto3584[7]=xx_Auto3584;
	for (i=0; i < 8; i++)_Context->msg_Auto3585[i]=" ";
	_Context->msg_Auto3585[0]=en_Auto3585;
	_Context->msg_Auto3585[1]=fr_Auto3585;
	_Context->msg_Auto3585[2]=it_Auto3585;
	_Context->msg_Auto3585[3]=es_Auto3585;
	_Context->msg_Auto3585[4]=de_Auto3585;
	_Context->msg_Auto3585[5]=nl_Auto3585;
	_Context->msg_Auto3585[6]=pt_Auto3585;
	_Context->msg_Auto3585[7]=xx_Auto3585;
	for (i=0; i < 8; i++)_Context->msg_Auto3586[i]=" ";
	_Context->msg_Auto3586[0]=en_Auto3586;
	_Context->msg_Auto3586[1]=fr_Auto3586;
	_Context->msg_Auto3586[2]=it_Auto3586;
	_Context->msg_Auto3586[3]=es_Auto3586;
	_Context->msg_Auto3586[4]=de_Auto3586;
	_Context->msg_Auto3586[5]=nl_Auto3586;
	_Context->msg_Auto3586[6]=pt_Auto3586;
	_Context->msg_Auto3586[7]=xx_Auto3586;
	for (i=0; i < 8; i++)_Context->msg_Auto3587[i]=" ";
	_Context->msg_Auto3587[0]=en_Auto3587;
	_Context->msg_Auto3587[1]=fr_Auto3587;
	_Context->msg_Auto3587[2]=it_Auto3587;
	_Context->msg_Auto3587[3]=es_Auto3587;
	_Context->msg_Auto3587[4]=de_Auto3587;
	_Context->msg_Auto3587[5]=nl_Auto3587;
	_Context->msg_Auto3587[6]=pt_Auto3587;
	_Context->msg_Auto3587[7]=xx_Auto3587;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3588[i]=" ";
	_Context->msg_Auto3588[0]=en_Auto3588;
	_Context->msg_Auto3588[1]=fr_Auto3588;
	_Context->msg_Auto3588[2]=it_Auto3588;
	_Context->msg_Auto3588[3]=es_Auto3588;
	_Context->msg_Auto3588[4]=de_Auto3588;
	_Context->msg_Auto3588[5]=nl_Auto3588;
	_Context->msg_Auto3588[6]=pt_Auto3588;
	_Context->msg_Auto3588[7]=xx_Auto3588;
	for (i=0; i < 8; i++)_Context->msg_Auto3589[i]=" ";
	_Context->msg_Auto3589[0]=en_Auto3589;
	_Context->msg_Auto3589[1]=fr_Auto3589;
	_Context->msg_Auto3589[2]=it_Auto3589;
	_Context->msg_Auto3589[3]=es_Auto3589;
	_Context->msg_Auto3589[4]=de_Auto3589;
	_Context->msg_Auto3589[5]=nl_Auto3589;
	_Context->msg_Auto3589[6]=pt_Auto3589;
	_Context->msg_Auto3589[7]=xx_Auto3589;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3580,_Context->y_Auto3580,500+10,260+10);
	return(0);
}

public 	int	accept_sort_camera_hide(struct accept_sort_camera_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3580,_Context->y_Auto3580);
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
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3580,_Context->y_Auto3580);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3580,_Context->y_Auto3580,500,260,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3580,_Context->y_Auto3580,500,260,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto3580+10,_Context->y_Auto3580+30,480,16,vfh[2],16,0,_Context->msg_Auto3581[_Context->language],strlen(_Context->msg_Auto3581[_Context->language]),258);
	visual_frame(_Context->x_Auto3580+10,_Context->y_Auto3580+46,480,204,4);
	visual_frame(_Context->x_Auto3580+20,_Context->y_Auto3580+60,460,100,2);
	visual_frame(_Context->x_Auto3580+20,_Context->y_Auto3580+170,460,70,2);
	visual_text(_Context->x_Auto3580+30,_Context->y_Auto3580+70,112,16,vfh[2],16,0,_Context->msg_Auto3584[_Context->language],strlen(_Context->msg_Auto3584[_Context->language]),258);
	visual_text(_Context->x_Auto3580+30,_Context->y_Auto3580+100,112,16,vfh[2],16,0,_Context->msg_Auto3585[_Context->language],strlen(_Context->msg_Auto3585[_Context->language]),258);
	visual_text(_Context->x_Auto3580+30,_Context->y_Auto3580+130,112,16,vfh[2],16,0,_Context->msg_Auto3586[_Context->language],strlen(_Context->msg_Auto3586[_Context->language]),258);
	visual_text(_Context->x_Auto3580+260,_Context->y_Auto3580+130,98,16,vfh[2],16,0,_Context->msg_Auto3587[_Context->language],strlen(_Context->msg_Auto3587[_Context->language]),258);
	visual_select(_Context->x_Auto3580+150,_Context->y_Auto3580+70,96,32,vfh[1],27,28,parse_selection(_Context->msg_SortMode[_Context->language],&_Context->value_SortMode),0);
	visual_select(_Context->x_Auto3580+260,_Context->y_Auto3580+70,96,48,vfh[1],27,28,parse_selection(_Context->msg_SortType[_Context->language],&_Context->value_SortType),0);
	visual_select(_Context->x_Auto3580+370,_Context->y_Auto3580+70,96,48,vfh[1],27,28,parse_selection(_Context->msg_Align[_Context->language],&_Context->value_Align),0);
	visual_frame(_Context->x_Auto3580+150,_Context->y_Auto3580+100,96+2,16+2,5);
	visual_text(_Context->x_Auto3580+150+1,_Context->y_Auto3580+100+1,96,16,vfh[1],27,28,_Context->buffer_atX,12,0);
	visual_frame(_Context->x_Auto3580+260,_Context->y_Auto3580+100,96+2,16+2,5);
	visual_text(_Context->x_Auto3580+260+1,_Context->y_Auto3580+100+1,96,16,vfh[1],27,28,_Context->buffer_atY,12,0);
	visual_frame(_Context->x_Auto3580+370,_Context->y_Auto3580+100,96+2,16+2,5);
	visual_text(_Context->x_Auto3580+370+1,_Context->y_Auto3580+100+1,96,16,vfh[1],27,28,_Context->buffer_atZ,12,0);
	visual_frame(_Context->x_Auto3580+150,_Context->y_Auto3580+130,96+2,16+2,5);
	visual_text(_Context->x_Auto3580+150+1,_Context->y_Auto3580+130+1,96,16,vfh[1],27,28,_Context->buffer_nbCols,12,0);
	visual_frame(_Context->x_Auto3580+370,_Context->y_Auto3580+130,96+2,16+2,5);
	visual_text(_Context->x_Auto3580+370+1,_Context->y_Auto3580+130+1,96,16,vfh[1],27,28,_Context->buffer_nbRows,12,0);
	_Context->trigger_Auto3588=visual_trigger_code(_Context->msg_Auto3588[_Context->language],strlen(_Context->msg_Auto3588[_Context->language]));
	visual_button(_Context->x_Auto3580+30,_Context->y_Auto3580+180,56,48,vfh[2],34,0,_Context->msg_Auto3588[_Context->language],strlen(_Context->msg_Auto3588[_Context->language]),1040);
	_Context->trigger_Auto3589=visual_trigger_code(_Context->msg_Auto3589[_Context->language],strlen(_Context->msg_Auto3589[_Context->language]));
	visual_button(_Context->x_Auto3580+410,_Context->y_Auto3580+180,56,48,vfh[2],34,0,_Context->msg_Auto3589[_Context->language],strlen(_Context->msg_Auto3589[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3580,_Context->y_Auto3580,500,260);

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

private int Auto3588_help()
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

private int Auto3589_help()
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

private int Auto3580action(struct accept_sort_camera_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_sort_camera_hide(_Context);

		_Context->x_Auto3580 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3580 < 0) { _Context->x_Auto3580=0; }
		_Context->y_Auto3580 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3580 < 0) { _Context->y_Auto3580=0; }
			accept_sort_camera_show(_Context);

		visual_thaw(_Context->x_Auto3580,_Context->y_Auto3580,500,260);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3588_event(struct accept_sort_camera_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto3589_event(struct accept_sort_camera_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_sort_camera_event(
struct accept_sort_camera_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto3588 == mb ) return(10);
		if (_Context->trigger_Auto3589 == mb ) return(11);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3580+479) )  
	&&  (my >= (_Context->y_Auto3580+4) )  
	&&  (mx <= (_Context->x_Auto3580+496) )  
	&&  (my <= (_Context->y_Auto3580+20) )) {
		return(1);	/* Auto3580 */

		}
	if ((mx >= (_Context->x_Auto3580+463) )  
	&&  (my >= (_Context->y_Auto3580+4) )  
	&&  (mx <= (_Context->x_Auto3580+480) )  
	&&  (my <= (_Context->y_Auto3580+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vorder.htm");
			};
		return(-1);	/* Auto3580 */

		}
	if ((mx >= (_Context->x_Auto3580+447) )  
	&&  (my >= (_Context->y_Auto3580+4) )  
	&&  (mx <= (_Context->x_Auto3580+464) )  
	&&  (my <= (_Context->y_Auto3580+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_sort_camera_show(_Context);
		return(-1);	/* Auto3580 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3580+4) )  
		&&  (my >= (_Context->y_Auto3580+4) )  
		&&  (mx <= (_Context->x_Auto3580+432) )  
		&&  (my <= (_Context->y_Auto3580+20) )) {
			return( Auto3580action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3580+150+0) ) 
	&&  ( my >= (_Context->y_Auto3580+70) ) 
	&&  ( mx <= (_Context->x_Auto3580+150+96) ) 
	&&  ( my <= (_Context->y_Auto3580+70+16))) {
		return(2); /* SortMode */
		}
	if (( mx >= (_Context->x_Auto3580+260+0) ) 
	&&  ( my >= (_Context->y_Auto3580+70) ) 
	&&  ( mx <= (_Context->x_Auto3580+260+96) ) 
	&&  ( my <= (_Context->y_Auto3580+70+16))) {
		return(3); /* SortType */
		}
	if (( mx >= (_Context->x_Auto3580+370+0) ) 
	&&  ( my >= (_Context->y_Auto3580+70) ) 
	&&  ( mx <= (_Context->x_Auto3580+370+96) ) 
	&&  ( my <= (_Context->y_Auto3580+70+16))) {
		return(4); /* Align */
		}
	if (( mx >= (_Context->x_Auto3580+150) ) 
	&&  ( my >= (_Context->y_Auto3580+100) ) 
	&&  ( mx <= (_Context->x_Auto3580+150+96) ) 
	&&  ( my <= (_Context->y_Auto3580+100+16))) {
		return(5); /* atX */
		}
	if (( mx >= (_Context->x_Auto3580+260) ) 
	&&  ( my >= (_Context->y_Auto3580+100) ) 
	&&  ( mx <= (_Context->x_Auto3580+260+96) ) 
	&&  ( my <= (_Context->y_Auto3580+100+16))) {
		return(6); /* atY */
		}
	if (( mx >= (_Context->x_Auto3580+370) ) 
	&&  ( my >= (_Context->y_Auto3580+100) ) 
	&&  ( mx <= (_Context->x_Auto3580+370+96) ) 
	&&  ( my <= (_Context->y_Auto3580+100+16))) {
		return(7); /* atZ */
		}
	if (( mx >= (_Context->x_Auto3580+150) ) 
	&&  ( my >= (_Context->y_Auto3580+130) ) 
	&&  ( mx <= (_Context->x_Auto3580+150+96) ) 
	&&  ( my <= (_Context->y_Auto3580+130+16))) {
		return(8); /* nbCols */
		}
	if (( mx >= (_Context->x_Auto3580+370) ) 
	&&  ( my >= (_Context->y_Auto3580+130) ) 
	&&  ( mx <= (_Context->x_Auto3580+370+96) ) 
	&&  ( my <= (_Context->y_Auto3580+130+16))) {
		return(9); /* nbRows */
		}
	if (( mx >= (_Context->x_Auto3580+30) ) 
	&&  ( my >= (_Context->y_Auto3580+180) ) 
	&&  ( mx <= (_Context->x_Auto3580+30+56) ) 
	&&  ( my <= (_Context->y_Auto3580+180+48))) {
		return(10); /* Auto3588 */
		}
	if (( mx >= (_Context->x_Auto3580+410) ) 
	&&  ( my >= (_Context->y_Auto3580+180) ) 
	&&  ( mx <= (_Context->x_Auto3580+410+56) ) 
	&&  ( my <= (_Context->y_Auto3580+180+48))) {
		return(11); /* Auto3589 */
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
				_Context->keycode = visual_select(_Context->x_Auto3580+150,_Context->y_Auto3580+70,96,32,vfh[1],27,28,parse_selection(_Context->msg_SortMode[_Context->language],&_Context->value_SortMode),2);
				break;
			case	0x3 :
				/* SortType */
				_Context->keycode = visual_select(_Context->x_Auto3580+260,_Context->y_Auto3580+70,96,48,vfh[1],27,28,parse_selection(_Context->msg_SortType[_Context->language],&_Context->value_SortType),2);
				break;
			case	0x4 :
				/* Align */
				_Context->keycode = visual_select(_Context->x_Auto3580+370,_Context->y_Auto3580+70,96,48,vfh[1],27,28,parse_selection(_Context->msg_Align[_Context->language],&_Context->value_Align),2);
				break;
			case	0x5 :
				/* atX */
				_Context->keycode = visual_edit(_Context->x_Auto3580+150+1,_Context->y_Auto3580+100+1,96,16,vfh[1],_Context->buffer_atX,12);
			break;
			case	0x6 :
				/* atY */
				_Context->keycode = visual_edit(_Context->x_Auto3580+260+1,_Context->y_Auto3580+100+1,96,16,vfh[1],_Context->buffer_atY,12);
			break;
			case	0x7 :
				/* atZ */
				_Context->keycode = visual_edit(_Context->x_Auto3580+370+1,_Context->y_Auto3580+100+1,96,16,vfh[1],_Context->buffer_atZ,12);
			break;
			case	0x8 :
				/* nbCols */
				_Context->keycode = visual_edit(_Context->x_Auto3580+150+1,_Context->y_Auto3580+130+1,96,16,vfh[1],_Context->buffer_nbCols,12);
			break;
			case	0x9 :
				/* nbRows */
				_Context->keycode = visual_edit(_Context->x_Auto3580+370+1,_Context->y_Auto3580+130+1,96,16,vfh[1],_Context->buffer_nbRows,12);
			break;
			case	0xa :
				/* Auto3588 */
				_Context->trigger_Auto3588=visual_trigger_code(_Context->msg_Auto3588[_Context->language],strlen(_Context->msg_Auto3588[_Context->language]));
				visual_button(_Context->x_Auto3580+30,_Context->y_Auto3580+180,56,48,vfh[2],34,0,_Context->msg_Auto3588[_Context->language],strlen(_Context->msg_Auto3588[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3588=visual_trigger_code(_Context->msg_Auto3588[_Context->language],strlen(_Context->msg_Auto3588[_Context->language]));
	visual_button(_Context->x_Auto3580+30,_Context->y_Auto3580+180,56,48,vfh[2],34,0,_Context->msg_Auto3588[_Context->language],strlen(_Context->msg_Auto3588[_Context->language]),1040);
				break;
			case	0xb :
				/* Auto3589 */
				_Context->trigger_Auto3589=visual_trigger_code(_Context->msg_Auto3589[_Context->language],strlen(_Context->msg_Auto3589[_Context->language]));
				visual_button(_Context->x_Auto3580+410,_Context->y_Auto3580+180,56,48,vfh[2],34,0,_Context->msg_Auto3589[_Context->language],strlen(_Context->msg_Auto3589[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3589=visual_trigger_code(_Context->msg_Auto3589[_Context->language],strlen(_Context->msg_Auto3589[_Context->language]));
	visual_button(_Context->x_Auto3580+410,_Context->y_Auto3580+180,56,48,vfh[2],34,0,_Context->msg_Auto3589[_Context->language],strlen(_Context->msg_Auto3589[_Context->language]),1040);
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
						if (Auto3588_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Auto3589_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3580 */
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
					/* Auto3588 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3588=visual_trigger_code(_Context->msg_Auto3588[_Context->language],strlen(_Context->msg_Auto3588[_Context->language]));
						visual_button(_Context->x_Auto3580+30,_Context->y_Auto3580+180,56,48,vfh[2],34,0,_Context->msg_Auto3588[_Context->language],strlen(_Context->msg_Auto3588[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3588=visual_trigger_code(_Context->msg_Auto3588[_Context->language],strlen(_Context->msg_Auto3588[_Context->language]));
	visual_button(_Context->x_Auto3580+30,_Context->y_Auto3580+180,56,48,vfh[2],34,0,_Context->msg_Auto3588[_Context->language],strlen(_Context->msg_Auto3588[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3588_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Auto3589 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3589=visual_trigger_code(_Context->msg_Auto3589[_Context->language],strlen(_Context->msg_Auto3589[_Context->language]));
						visual_button(_Context->x_Auto3580+410,_Context->y_Auto3580+180,56,48,vfh[2],34,0,_Context->msg_Auto3589[_Context->language],strlen(_Context->msg_Auto3589[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3589=visual_trigger_code(_Context->msg_Auto3589[_Context->language],strlen(_Context->msg_Auto3589[_Context->language]));
	visual_button(_Context->x_Auto3580+410,_Context->y_Auto3580+180,56,48,vfh[2],34,0,_Context->msg_Auto3589[_Context->language],strlen(_Context->msg_Auto3589[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3589_event(_Context)) != -1) break;

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
