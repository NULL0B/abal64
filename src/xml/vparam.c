
#ifndef _vparam_c
#define _vparam_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vparam.xml                                               */
/* Target         : vparam.c                                                 */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto3582   ""
#define fr__Auto3582   ""
#define it__Auto3582   ""
#define es__Auto3582   ""
#define de__Auto3582   ""
#define nl__Auto3582   ""
#define pt__Auto3582   ""
#define xx__Auto3582   ""
#define en_Auto3586   "General Parameters"
#define fr_Auto3586   "ParamŠtres g‚n‚raux"
#define it_Auto3586   "General Parameters"
#define es_Auto3586   "General Parameters"
#define de_Auto3586   "General Parameters"
#define nl_Auto3586   "General Parameters"
#define pt_Auto3586   "General Parameters"
#define xx_Auto3586   "General Parameters"
#define en_Auto3587   "Production Language"
#define fr_Auto3587   "Langage de production"
#define it_Auto3587   "Production Language"
#define es_Auto3587   "Production Language"
#define de_Auto3587   "Production Language"
#define nl_Auto3587   "Production Language"
#define pt_Auto3587   "Production Language"
#define xx_Auto3587   "Production Language"
#define en_Auto3588   "Image Production"
#define fr_Auto3588   "Production d'image"
#define it_Auto3588   "Image Production"
#define es_Auto3588   "Image Production"
#define de_Auto3588   "Image Production"
#define nl_Auto3588   "Image Production"
#define pt_Auto3588   "Image Production"
#define xx_Auto3588   "Image Production"
#define en_Auto3589   "Current Text Font"
#define fr_Auto3589   "Police courant"
#define it_Auto3589   "Current Text Font"
#define es_Auto3589   "Current Text Font"
#define de_Auto3589   "Current Text Font"
#define nl_Auto3589   "Current Text Font"
#define pt_Auto3589   "Current Text Font"
#define xx_Auto3589   "Current Text Font"
#define en_Auto3590   "Alignment"
#define fr_Auto3590   "Alignement"
#define it_Auto3590   "Alignment"
#define es_Auto3590   "Alignment"
#define de_Auto3590   "Alignment"
#define nl_Auto3590   "Alignment"
#define pt_Auto3590   "Alignment"
#define xx_Auto3590   "Alignment"
#define en_Auto3591   "Line Thickness"
#define fr_Auto3591   "Epaisseur de Ligne"
#define it_Auto3591   "Line Thickness"
#define es_Auto3591   "Line Thickness"
#define de_Auto3591   "Line Thickness"
#define nl_Auto3591   "Line Thickness"
#define pt_Auto3591   "Line Thickness"
#define xx_Auto3591   "Line Thickness"
#define en_Auto3592   "Grid Width"
#define fr_Auto3592   "Largeur de grille"
#define it_Auto3592   "Grid Width"
#define es_Auto3592   "Grid Width"
#define de_Auto3592   "Grid Width"
#define nl_Auto3592   "Grid Width"
#define pt_Auto3592   "Grid Width"
#define xx_Auto3592   "Grid Width"
#define en_Auto3593   "Grid Height"
#define fr_Auto3593   "Hauteur de grille"
#define it_Auto3593   "Grid Height"
#define es_Auto3593   "Grid Height"
#define de_Auto3593   "Grid Height"
#define nl_Auto3593   "Grid Height"
#define pt_Auto3593   "Grid Height"
#define xx_Auto3593   "Grid Height"
#define en__ProductionLanguage   ""
#define en__ImageFormat   ""
#define en__TextFont   ""
#define en__Alignment   ""
#define en_IsBold   "&Bold"
#define fr_IsBold   "&Gras"
#define it_IsBold   "&Bold"
#define es_IsBold   "&Bold"
#define de_IsBold   "&Bold"
#define nl_IsBold   "&Bold"
#define pt_IsBold   "&Bold"
#define xx_IsBold   "&Bold"
#define en_IsUnderline   "&Underline"
#define fr_IsUnderline   "&Soulign‚"
#define it_IsUnderline   "&Underline"
#define es_IsUnderline   "&Underline"
#define de_IsUnderline   "&Underline"
#define nl_IsUnderline   "&Underline"
#define pt_IsUnderline   "&Underline"
#define xx_IsUnderline   "&Underline"
#define en_IsShadow   "&Shadow"
#define fr_IsShadow   "&Ombr‚"
#define it_IsShadow   "&Shadow"
#define es_IsShadow   "&Shadow"
#define de_IsShadow   "&Shadow"
#define nl_IsShadow   "&Shadow"
#define pt_IsShadow   "&Shadow"
#define xx_IsShadow   "&Shadow"
#define en_SnapOn   "None|Desktop|Window"
#define fr_SnapOn   "Sans|Bureau|Fenetre"
#define it_SnapOn   "None|Desktop|Window"
#define es_SnapOn   "None|Desktop|Window"
#define de_SnapOn   "None|Desktop|Window"
#define nl_SnapOn   "None|Desktop|Window"
#define pt_SnapOn   "None|Desktop|Window"
#define xx_SnapOn   "None|Desktop|Window"
#define en__SnapOn   ""
#define fr__SnapOn   ""
#define it__SnapOn   ""
#define es__SnapOn   ""
#define de__SnapOn   ""
#define nl__SnapOn   ""
#define pt__SnapOn   ""
#define xx__SnapOn   ""
#define en_Auto3594   "Grid Type"
#define fr_Auto3594   "Type grille"
#define it_Auto3594   "Grid Type"
#define es_Auto3594   "Grid Type"
#define de_Auto3594   "Grid Type"
#define nl_Auto3594   "Grid Type"
#define pt_Auto3594   "Grid Type"
#define xx_Auto3594   "Grid Type"
#define en__Auto3594   ""
#define fr__Auto3594   ""
#define it__Auto3594   ""
#define es__Auto3594   ""
#define de__Auto3594   ""
#define nl__Auto3594   ""
#define pt__Auto3594   ""
#define xx__Auto3594   ""
#define en_Auto3595   "Resize"
#define fr_Auto3595   "Resize"
#define it_Auto3595   "Resize"
#define es_Auto3595   "Resize"
#define de_Auto3595   "Resize"
#define nl_Auto3595   "Resize"
#define pt_Auto3595   "Resize"
#define xx_Auto3595   "Resize"
#define en__Auto3595   ""
#define fr__Auto3595   ""
#define it__Auto3595   ""
#define es__Auto3595   ""
#define de__Auto3595   ""
#define nl__Auto3595   ""
#define pt__Auto3595   ""
#define xx__Auto3595   ""
#define en_LockOn   "&Lock On"
#define fr_LockOn   "&Verrouill‚"
#define it_LockOn   "&Lock On"
#define es_LockOn   "&Lock On"
#define de_LockOn   "&Lock On"
#define nl_LockOn   "&Lock On"
#define pt_LockOn   "&Lock On"
#define xx_LockOn   "&Lock On"
#define en_TestData   "&Test Data"
#define fr_TestData   "&Donn‚es teste"
#define it_TestData   "&Test Data"
#define es_TestData   "&Test Data"
#define de_TestData   "&Test Data"
#define nl_TestData   "&Test Data"
#define pt_TestData   "&Test Data"
#define xx_TestData   "&Test Data"
#define en__TestData   ""
#define fr__TestData   ""
#define it__TestData   ""
#define es__TestData   ""
#define de__TestData   ""
#define nl__TestData   ""
#define pt__TestData   ""
#define xx__TestData   ""
#define en_Auto3596   "Auto sa&ve"
#define fr_Auto3596   "Sau&v auto."
#define it_Auto3596   "Auto sa&ve"
#define es_Auto3596   "Auto sa&ve"
#define de_Auto3596   "Auto sa&ve"
#define nl_Auto3596   "Auto sa&ve"
#define pt_Auto3596   "Auto sa&ve"
#define xx_Auto3596   "Auto sa&ve"
#define en__Auto3596   ""
#define en_DropTool   "&DropTool"
#define fr_DropTool   "&Lƒcher"
#define it_DropTool   "&DropTool"
#define es_DropTool   "&DropTool"
#define de_DropTool   "&DropTool"
#define nl_DropTool   "&DropTool"
#define pt_DropTool   "&DropTool"
#define xx_DropTool   "&DropTool"
#define en_GridWidth   ""
#define en_UseTextFont   "Te&xtFont"
#define fr_UseTextFont   "&Police"
#define it_UseTextFont   "Te&xtFont"
#define es_UseTextFont   "Te&xtFont"
#define de_UseTextFont   "Te&xtFont"
#define nl_UseTextFont   "Te&xtFont"
#define pt_UseTextFont   "Te&xtFont"
#define xx_UseTextFont   "Te&xtFont"
#define en_GridLock   "GridLock"
#define fr_GridLock   "Grille"
#define it_GridLock   "GridLock"
#define es_GridLock   "GridLock"
#define de_GridLock   "GridLock"
#define nl_GridLock   "GridLock"
#define pt_GridLock   "GridLock"
#define xx_GridLock   "GridLock"
#define en__GridLock   ""
#define fr__GridLock   ""
#define it__GridLock   ""
#define es__GridLock   ""
#define de__GridLock   ""
#define nl__GridLock   ""
#define pt__GridLock   ""
#define xx__GridLock   ""
#define en_ResizeBy   "Widget Frame|Right Button"
#define fr_ResizeBy   "Widget Cadre|Bouton Droit"
#define it_ResizeBy   "Widget Frame|Right Button"
#define es_ResizeBy   "Widget Frame|Right Button"
#define de_ResizeBy   "Widget Frame|Right Button"
#define nl_ResizeBy   "Widget Frame|Right Button"
#define pt_ResizeBy   "Widget Frame|Right Button"
#define xx_ResizeBy   "Widget Frame|Right Button"
#define en__ResizeBy   ""
#define fr__ResizeBy   ""
#define it__ResizeBy   ""
#define es__ResizeBy   ""
#define de__ResizeBy   ""
#define nl__ResizeBy   ""
#define pt__ResizeBy   ""
#define xx__ResizeBy   ""
#define en_Accept   "ok.gif"
#define fr_Accept   "ok.gif"
#define it_Accept   "ok.gif"
#define es_Accept   "ok.gif"
#define de_Accept   "ok.gif"
#define nl_Accept   "ok.gif"
#define pt_Accept   "ok.gif"
#define xx_Accept   "ok.gif"
#define en__Accept   ""
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"
#define en__Cancel   ""

private struct accept_general_options_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3582[8];
	char * hint_Auto3582[8];
	int	x_Auto3582;
	int	y_Auto3582;
	int	w_Auto3582;
	int	h_Auto3582;
	char * hint_Auto3583[8];
	char * hint_Auto3584[8];
	char * hint_Auto3585[8];
	char * msg_Auto3586[8];
	char * hint_Auto3586[8];
	char * msg_Auto3587[8];
	char * hint_Auto3587[8];
	char * msg_Auto3588[8];
	char * hint_Auto3588[8];
	char * msg_Auto3589[8];
	char * hint_Auto3589[8];
	char * msg_Auto3590[8];
	char * hint_Auto3590[8];
	char * msg_Auto3591[8];
	char * hint_Auto3591[8];
	char * msg_Auto3592[8];
	char * hint_Auto3592[8];
	char * msg_Auto3593[8];
	char * hint_Auto3593[8];
	char * msg_ProductionLanguage[8];
	char * hint_ProductionLanguage[8];
	int	value_ProductionLanguage;
	char * msg_ImageFormat[8];
	char * hint_ImageFormat[8];
	int	value_ImageFormat;
	char * msg_TextFont[8];
	char * hint_TextFont[8];
	int	value_TextFont;
	char * msg_Alignment[8];
	char * hint_Alignment[8];
	int	value_Alignment;
	char * msg_IsBold[8];
	int	trigger_IsBold;
	char * hint_IsBold[8];
	int	value_IsBold;
	char * msg_IsUnderline[8];
	int	trigger_IsUnderline;
	char * hint_IsUnderline[8];
	int	value_IsUnderline;
	char * msg_IsShadow[8];
	int	trigger_IsShadow;
	char * hint_IsShadow[8];
	int	value_IsShadow;
	char * msg_SnapOn[8];
	char * hint_SnapOn[8];
	int	value_SnapOn;
	char * msg_Auto3594[8];
	char * hint_Auto3594[8];
	char * msg_Auto3595[8];
	char * hint_Auto3595[8];
	char * msg_LockOn[8];
	int	trigger_LockOn;
	char * hint_LockOn[8];
	int	value_LockOn;
	char * msg_TestData[8];
	int	trigger_TestData;
	char * hint_TestData[8];
	int	value_TestData;
	char * msg_Auto3596[8];
	int	trigger_Auto3596;
	char * hint_Auto3596[8];
	int	value_Auto3596;
	char * msg_DropTool[8];
	int	trigger_DropTool;
	char * hint_DropTool[8];
	int	value_DropTool;
	char * hint_GridWidth[8];
	char	buffer_GridWidth[6];
	char * hint_GridHeight[8];
	char	buffer_GridHeight[6];
	char * msg_UseTextFont[8];
	int	trigger_UseTextFont;
	char * hint_UseTextFont[8];
	char * msg_GridLock[8];
	int	trigger_GridLock;
	char * hint_GridLock[8];
	char * hint_ThickNess[8];
	char	buffer_ThickNess[14];
	char * msg_ResizeBy[8];
	char * hint_ResizeBy[8];
	int	value_ResizeBy;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[17];
	};
static int	vfh[16];
private int on_UseTextFont_event(struct accept_general_options_context * _Context);
private int on_GridLock_event(struct accept_general_options_context * _Context);
private int on_Accept_event(struct accept_general_options_context * _Context);
private int on_Cancel_event(struct accept_general_options_context * _Context);

public	int	accept_general_options_create(
	struct accept_general_options_context ** cptr,
	char * pProductionLanguage,
	char * pImageFormat,
	char * pTextFont,
	char * pAlignment,
	char * pIsBold,
	char * pIsUnderline,
	char * pIsShadow,
	char * pSnapOn,
	char * pLockOn,
	char * pTestData,
	char * pAuto3596,
	char * pDropTool,
	char * pGridWidth,
	char * pGridHeight,
	char * pThickNess,
	char * pResizeBy)
{

	int i;
	struct accept_general_options_context * _Context=(struct accept_general_options_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_general_options_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=21;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWW WWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pProductionLanguage);
		if (!( pProductionLanguage )) _Context->value_ProductionLanguage=0;
		else	_Context->value_ProductionLanguage = *((int *)pProductionLanguage);
		visual_transferin((void *) 0, 0, pImageFormat);
		if (!( pImageFormat )) _Context->value_ImageFormat=0;
		else	_Context->value_ImageFormat = *((int *)pImageFormat);
		visual_transferin((void *) 0, 0, pTextFont);
		if (!( pTextFont )) _Context->value_TextFont=0;
		else	_Context->value_TextFont = *((int *)pTextFont);
		visual_transferin((void *) 0, 0, pAlignment);
		if (!( pAlignment )) _Context->value_Alignment=0;
		else	_Context->value_Alignment = *((int *)pAlignment);
		visual_transferin((void *) 0, 0, pIsBold);
		if (!( pIsBold )) _Context->value_IsBold=0;
		else	_Context->value_IsBold = *((int *)pIsBold);
		visual_transferin((void *) 0, 0, pIsUnderline);
		if (!( pIsUnderline )) _Context->value_IsUnderline=0;
		else	_Context->value_IsUnderline = *((int *)pIsUnderline);
		visual_transferin((void *) 0, 0, pIsShadow);
		if (!( pIsShadow )) _Context->value_IsShadow=0;
		else	_Context->value_IsShadow = *((int *)pIsShadow);
		visual_transferin((void *) 0, 0, pSnapOn);
		if (!( pSnapOn )) _Context->value_SnapOn=0;
		else	_Context->value_SnapOn = *((int *)pSnapOn);
		visual_transferin((void *) 0, 0, pLockOn);
		if (!( pLockOn )) _Context->value_LockOn=0;
		else	_Context->value_LockOn = *((int *)pLockOn);
		visual_transferin((void *) 0, 0, pTestData);
		if (!( pTestData )) _Context->value_TestData=0;
		else	_Context->value_TestData = *((int *)pTestData);
		visual_transferin((void *) 0, 0, pAuto3596);
		if (!( pAuto3596 )) _Context->value_Auto3596=0;
		else	_Context->value_Auto3596 = *((int *)pAuto3596);
		visual_transferin((void *) 0, 0, pDropTool);
		if (!( pDropTool )) _Context->value_DropTool=0;
		else	_Context->value_DropTool = *((int *)pDropTool);
		visual_transferin(_Context->buffer_GridWidth, 5, pGridWidth);
		visual_transferin(_Context->buffer_GridHeight, 5, pGridHeight);
		visual_transferin(_Context->buffer_ThickNess, 13, pThickNess);
		visual_transferin((void *) 0, 0, pResizeBy);
		if (!( pResizeBy )) _Context->value_ResizeBy=0;
		else	_Context->value_ResizeBy = *((int *)pResizeBy);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3582[i]=" ";
	_Context->hint_Auto3582[0]=en__Auto3582;
	_Context->hint_Auto3582[1]=fr__Auto3582;
	_Context->hint_Auto3582[2]=it__Auto3582;
	_Context->hint_Auto3582[3]=es__Auto3582;
	_Context->hint_Auto3582[4]=de__Auto3582;
	_Context->hint_Auto3582[5]=nl__Auto3582;
	_Context->hint_Auto3582[6]=pt__Auto3582;
	_Context->hint_Auto3582[7]=xx__Auto3582;
	_Context->x_Auto3582=215;
	_Context->y_Auto3582=90;
	_Context->w_Auto3582=370;
	_Context->h_Auto3582=420;
	_Context->window_col=0;
	_Context->window_row=0;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3590[i]=" ";
	_Context->msg_Auto3590[0]=en_Auto3590;
	_Context->msg_Auto3590[1]=fr_Auto3590;
	_Context->msg_Auto3590[2]=it_Auto3590;
	_Context->msg_Auto3590[3]=es_Auto3590;
	_Context->msg_Auto3590[4]=de_Auto3590;
	_Context->msg_Auto3590[5]=nl_Auto3590;
	_Context->msg_Auto3590[6]=pt_Auto3590;
	_Context->msg_Auto3590[7]=xx_Auto3590;
	for (i=0; i < 8; i++)_Context->msg_Auto3591[i]=" ";
	_Context->msg_Auto3591[0]=en_Auto3591;
	_Context->msg_Auto3591[1]=fr_Auto3591;
	_Context->msg_Auto3591[2]=it_Auto3591;
	_Context->msg_Auto3591[3]=es_Auto3591;
	_Context->msg_Auto3591[4]=de_Auto3591;
	_Context->msg_Auto3591[5]=nl_Auto3591;
	_Context->msg_Auto3591[6]=pt_Auto3591;
	_Context->msg_Auto3591[7]=xx_Auto3591;
	for (i=0; i < 8; i++)_Context->msg_Auto3592[i]=" ";
	_Context->msg_Auto3592[0]=en_Auto3592;
	_Context->msg_Auto3592[1]=fr_Auto3592;
	_Context->msg_Auto3592[2]=it_Auto3592;
	_Context->msg_Auto3592[3]=es_Auto3592;
	_Context->msg_Auto3592[4]=de_Auto3592;
	_Context->msg_Auto3592[5]=nl_Auto3592;
	_Context->msg_Auto3592[6]=pt_Auto3592;
	_Context->msg_Auto3592[7]=xx_Auto3592;
	for (i=0; i < 8; i++)_Context->msg_Auto3593[i]=" ";
	_Context->msg_Auto3593[0]=en_Auto3593;
	_Context->msg_Auto3593[1]=fr_Auto3593;
	_Context->msg_Auto3593[2]=it_Auto3593;
	_Context->msg_Auto3593[3]=es_Auto3593;
	_Context->msg_Auto3593[4]=de_Auto3593;
	_Context->msg_Auto3593[5]=nl_Auto3593;
	_Context->msg_Auto3593[6]=pt_Auto3593;
	_Context->msg_Auto3593[7]=xx_Auto3593;
	for (i=0; i < 8; i++)_Context->msg_ProductionLanguage[i]=" ";
	_Context->hint_ProductionLanguage[0]=en__ProductionLanguage;
	for (i=0; i < 8; i++)_Context->msg_ImageFormat[i]=" ";
	_Context->hint_ImageFormat[0]=en__ImageFormat;
	for (i=0; i < 8; i++)_Context->msg_TextFont[i]=" ";
	_Context->hint_TextFont[0]=en__TextFont;
	for (i=0; i < 8; i++)_Context->msg_Alignment[i]=" ";
	_Context->hint_Alignment[0]=en__Alignment;
	for (i=0; i < 8; i++)_Context->msg_IsBold[i]=" ";
	_Context->msg_IsBold[0]=en_IsBold;
	_Context->msg_IsBold[1]=fr_IsBold;
	_Context->msg_IsBold[2]=it_IsBold;
	_Context->msg_IsBold[3]=es_IsBold;
	_Context->msg_IsBold[4]=de_IsBold;
	_Context->msg_IsBold[5]=nl_IsBold;
	_Context->msg_IsBold[6]=pt_IsBold;
	_Context->msg_IsBold[7]=xx_IsBold;
	for (i=0; i < 8; i++)_Context->msg_IsUnderline[i]=" ";
	_Context->msg_IsUnderline[0]=en_IsUnderline;
	_Context->msg_IsUnderline[1]=fr_IsUnderline;
	_Context->msg_IsUnderline[2]=it_IsUnderline;
	_Context->msg_IsUnderline[3]=es_IsUnderline;
	_Context->msg_IsUnderline[4]=de_IsUnderline;
	_Context->msg_IsUnderline[5]=nl_IsUnderline;
	_Context->msg_IsUnderline[6]=pt_IsUnderline;
	_Context->msg_IsUnderline[7]=xx_IsUnderline;
	for (i=0; i < 8; i++)_Context->msg_IsShadow[i]=" ";
	_Context->msg_IsShadow[0]=en_IsShadow;
	_Context->msg_IsShadow[1]=fr_IsShadow;
	_Context->msg_IsShadow[2]=it_IsShadow;
	_Context->msg_IsShadow[3]=es_IsShadow;
	_Context->msg_IsShadow[4]=de_IsShadow;
	_Context->msg_IsShadow[5]=nl_IsShadow;
	_Context->msg_IsShadow[6]=pt_IsShadow;
	_Context->msg_IsShadow[7]=xx_IsShadow;
	for (i=0; i < 8; i++)_Context->msg_SnapOn[i]=" ";
	_Context->msg_SnapOn[0]=en_SnapOn;
	_Context->msg_SnapOn[1]=fr_SnapOn;
	_Context->msg_SnapOn[2]=it_SnapOn;
	_Context->msg_SnapOn[3]=es_SnapOn;
	_Context->msg_SnapOn[4]=de_SnapOn;
	_Context->msg_SnapOn[5]=nl_SnapOn;
	_Context->msg_SnapOn[6]=pt_SnapOn;
	_Context->msg_SnapOn[7]=xx_SnapOn;
	_Context->hint_SnapOn[0]=en__SnapOn;
	_Context->hint_SnapOn[1]=fr__SnapOn;
	_Context->hint_SnapOn[2]=it__SnapOn;
	_Context->hint_SnapOn[3]=es__SnapOn;
	_Context->hint_SnapOn[4]=de__SnapOn;
	_Context->hint_SnapOn[5]=nl__SnapOn;
	_Context->hint_SnapOn[6]=pt__SnapOn;
	_Context->hint_SnapOn[7]=xx__SnapOn;
	for (i=0; i < 8; i++)_Context->msg_Auto3594[i]=" ";
	_Context->msg_Auto3594[0]=en_Auto3594;
	_Context->msg_Auto3594[1]=fr_Auto3594;
	_Context->msg_Auto3594[2]=it_Auto3594;
	_Context->msg_Auto3594[3]=es_Auto3594;
	_Context->msg_Auto3594[4]=de_Auto3594;
	_Context->msg_Auto3594[5]=nl_Auto3594;
	_Context->msg_Auto3594[6]=pt_Auto3594;
	_Context->msg_Auto3594[7]=xx_Auto3594;
	_Context->hint_Auto3594[0]=en__Auto3594;
	_Context->hint_Auto3594[1]=fr__Auto3594;
	_Context->hint_Auto3594[2]=it__Auto3594;
	_Context->hint_Auto3594[3]=es__Auto3594;
	_Context->hint_Auto3594[4]=de__Auto3594;
	_Context->hint_Auto3594[5]=nl__Auto3594;
	_Context->hint_Auto3594[6]=pt__Auto3594;
	_Context->hint_Auto3594[7]=xx__Auto3594;
	for (i=0; i < 8; i++)_Context->msg_Auto3595[i]=" ";
	_Context->msg_Auto3595[0]=en_Auto3595;
	_Context->msg_Auto3595[1]=fr_Auto3595;
	_Context->msg_Auto3595[2]=it_Auto3595;
	_Context->msg_Auto3595[3]=es_Auto3595;
	_Context->msg_Auto3595[4]=de_Auto3595;
	_Context->msg_Auto3595[5]=nl_Auto3595;
	_Context->msg_Auto3595[6]=pt_Auto3595;
	_Context->msg_Auto3595[7]=xx_Auto3595;
	_Context->hint_Auto3595[0]=en__Auto3595;
	_Context->hint_Auto3595[1]=fr__Auto3595;
	_Context->hint_Auto3595[2]=it__Auto3595;
	_Context->hint_Auto3595[3]=es__Auto3595;
	_Context->hint_Auto3595[4]=de__Auto3595;
	_Context->hint_Auto3595[5]=nl__Auto3595;
	_Context->hint_Auto3595[6]=pt__Auto3595;
	_Context->hint_Auto3595[7]=xx__Auto3595;
	for (i=0; i < 8; i++)_Context->msg_LockOn[i]=" ";
	_Context->msg_LockOn[0]=en_LockOn;
	_Context->msg_LockOn[1]=fr_LockOn;
	_Context->msg_LockOn[2]=it_LockOn;
	_Context->msg_LockOn[3]=es_LockOn;
	_Context->msg_LockOn[4]=de_LockOn;
	_Context->msg_LockOn[5]=nl_LockOn;
	_Context->msg_LockOn[6]=pt_LockOn;
	_Context->msg_LockOn[7]=xx_LockOn;
	for (i=0; i < 8; i++)_Context->msg_TestData[i]=" ";
	_Context->msg_TestData[0]=en_TestData;
	_Context->msg_TestData[1]=fr_TestData;
	_Context->msg_TestData[2]=it_TestData;
	_Context->msg_TestData[3]=es_TestData;
	_Context->msg_TestData[4]=de_TestData;
	_Context->msg_TestData[5]=nl_TestData;
	_Context->msg_TestData[6]=pt_TestData;
	_Context->msg_TestData[7]=xx_TestData;
	_Context->hint_TestData[0]=en__TestData;
	_Context->hint_TestData[1]=fr__TestData;
	_Context->hint_TestData[2]=it__TestData;
	_Context->hint_TestData[3]=es__TestData;
	_Context->hint_TestData[4]=de__TestData;
	_Context->hint_TestData[5]=nl__TestData;
	_Context->hint_TestData[6]=pt__TestData;
	_Context->hint_TestData[7]=xx__TestData;
	for (i=0; i < 8; i++)_Context->msg_Auto3596[i]=" ";
	_Context->msg_Auto3596[0]=en_Auto3596;
	_Context->msg_Auto3596[1]=fr_Auto3596;
	_Context->msg_Auto3596[2]=it_Auto3596;
	_Context->msg_Auto3596[3]=es_Auto3596;
	_Context->msg_Auto3596[4]=de_Auto3596;
	_Context->msg_Auto3596[5]=nl_Auto3596;
	_Context->msg_Auto3596[6]=pt_Auto3596;
	_Context->msg_Auto3596[7]=xx_Auto3596;
	_Context->hint_Auto3596[0]=en__Auto3596;
	for (i=0; i < 8; i++)_Context->msg_DropTool[i]=" ";
	_Context->msg_DropTool[0]=en_DropTool;
	_Context->msg_DropTool[1]=fr_DropTool;
	_Context->msg_DropTool[2]=it_DropTool;
	_Context->msg_DropTool[3]=es_DropTool;
	_Context->msg_DropTool[4]=de_DropTool;
	_Context->msg_DropTool[5]=nl_DropTool;
	_Context->msg_DropTool[6]=pt_DropTool;
	_Context->msg_DropTool[7]=xx_DropTool;
	for (i=0; i < 8; i++)_Context->msg_UseTextFont[i]=" ";
	_Context->msg_UseTextFont[0]=en_UseTextFont;
	_Context->msg_UseTextFont[1]=fr_UseTextFont;
	_Context->msg_UseTextFont[2]=it_UseTextFont;
	_Context->msg_UseTextFont[3]=es_UseTextFont;
	_Context->msg_UseTextFont[4]=de_UseTextFont;
	_Context->msg_UseTextFont[5]=nl_UseTextFont;
	_Context->msg_UseTextFont[6]=pt_UseTextFont;
	_Context->msg_UseTextFont[7]=xx_UseTextFont;
	for (i=0; i < 8; i++)_Context->msg_GridLock[i]=" ";
	_Context->msg_GridLock[0]=en_GridLock;
	_Context->msg_GridLock[1]=fr_GridLock;
	_Context->msg_GridLock[2]=it_GridLock;
	_Context->msg_GridLock[3]=es_GridLock;
	_Context->msg_GridLock[4]=de_GridLock;
	_Context->msg_GridLock[5]=nl_GridLock;
	_Context->msg_GridLock[6]=pt_GridLock;
	_Context->msg_GridLock[7]=xx_GridLock;
	_Context->hint_GridLock[0]=en__GridLock;
	_Context->hint_GridLock[1]=fr__GridLock;
	_Context->hint_GridLock[2]=it__GridLock;
	_Context->hint_GridLock[3]=es__GridLock;
	_Context->hint_GridLock[4]=de__GridLock;
	_Context->hint_GridLock[5]=nl__GridLock;
	_Context->hint_GridLock[6]=pt__GridLock;
	_Context->hint_GridLock[7]=xx__GridLock;
	for (i=0; i < 8; i++)_Context->msg_ResizeBy[i]=" ";
	_Context->msg_ResizeBy[0]=en_ResizeBy;
	_Context->msg_ResizeBy[1]=fr_ResizeBy;
	_Context->msg_ResizeBy[2]=it_ResizeBy;
	_Context->msg_ResizeBy[3]=es_ResizeBy;
	_Context->msg_ResizeBy[4]=de_ResizeBy;
	_Context->msg_ResizeBy[5]=nl_ResizeBy;
	_Context->msg_ResizeBy[6]=pt_ResizeBy;
	_Context->msg_ResizeBy[7]=xx_ResizeBy;
	_Context->hint_ResizeBy[0]=en__ResizeBy;
	_Context->hint_ResizeBy[1]=fr__ResizeBy;
	_Context->hint_ResizeBy[2]=it__ResizeBy;
	_Context->hint_ResizeBy[3]=es__ResizeBy;
	_Context->hint_ResizeBy[4]=de__ResizeBy;
	_Context->hint_ResizeBy[5]=nl__ResizeBy;
	_Context->hint_ResizeBy[6]=pt__ResizeBy;
	_Context->hint_ResizeBy[7]=xx__ResizeBy;
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
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3582,_Context->y_Auto3582,370+10,420+10);
	return(0);
}

public 	int	accept_general_options_hide(struct accept_general_options_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3582,_Context->y_Auto3582);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_general_options_remove(
	struct accept_general_options_context * _Context,
	char * pProductionLanguage,
	char * pImageFormat,
	char * pTextFont,
	char * pAlignment,
	char * pIsBold,
	char * pIsUnderline,
	char * pIsShadow,
	char * pSnapOn,
	char * pLockOn,
	char * pTestData,
	char * pAuto3596,
	char * pDropTool,
	char * pGridWidth,
	char * pGridHeight,
	char * pThickNess,
	char * pResizeBy)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWW WWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pProductionLanguage);
		if ( pProductionLanguage != (char *) 0)
			*((int*)pProductionLanguage) = _Context->value_ProductionLanguage;
		visual_transferout((void *) 0, 0, pImageFormat);
		if ( pImageFormat != (char *) 0)
			*((int*)pImageFormat) = _Context->value_ImageFormat;
		visual_transferout((void *) 0, 0, pTextFont);
		if ( pTextFont != (char *) 0)
			*((int*)pTextFont) = _Context->value_TextFont;
		visual_transferout((void *) 0, 0, pAlignment);
		if ( pAlignment != (char *) 0)
			*((int*)pAlignment) = _Context->value_Alignment;
		visual_transferout((void *) 0, 0, pIsBold);
		if ( pIsBold != (char *) 0)
			*((int*)pIsBold) = _Context->value_IsBold;
		visual_transferout((void *) 0, 0, pIsUnderline);
		if ( pIsUnderline != (char *) 0)
			*((int*)pIsUnderline) = _Context->value_IsUnderline;
		visual_transferout((void *) 0, 0, pIsShadow);
		if ( pIsShadow != (char *) 0)
			*((int*)pIsShadow) = _Context->value_IsShadow;
		visual_transferout((void *) 0, 0, pSnapOn);
		if ( pSnapOn != (char *) 0)
			*((int*)pSnapOn) = _Context->value_SnapOn;
		visual_transferout((void *) 0, 0, pLockOn);
		if ( pLockOn != (char *) 0)
			*((int*)pLockOn) = _Context->value_LockOn;
		visual_transferout((void *) 0, 0, pTestData);
		if ( pTestData != (char *) 0)
			*((int*)pTestData) = _Context->value_TestData;
		visual_transferout((void *) 0, 0, pAuto3596);
		if ( pAuto3596 != (char *) 0)
			*((int*)pAuto3596) = _Context->value_Auto3596;
		visual_transferout((void *) 0, 0, pDropTool);
		if ( pDropTool != (char *) 0)
			*((int*)pDropTool) = _Context->value_DropTool;
		visual_transferout(_Context->buffer_GridWidth, 5, pGridWidth);
		visual_transferout(_Context->buffer_GridHeight, 5, pGridHeight);
		visual_transferout(_Context->buffer_ThickNess, 13, pThickNess);
		visual_transferout((void *) 0, 0, pResizeBy);
		if ( pResizeBy != (char *) 0)
			*((int*)pResizeBy) = _Context->value_ResizeBy;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_general_options_show(struct accept_general_options_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3582,_Context->y_Auto3582);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3582,_Context->y_Auto3582,370,420,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3582,_Context->y_Auto3582,370,420,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_frame(_Context->x_Auto3582+10,_Context->y_Auto3582+60,350,130,4);
	visual_frame(_Context->x_Auto3582+10,_Context->y_Auto3582+200,350,80,4);
	visual_frame(_Context->x_Auto3582+10,_Context->y_Auto3582+290,350,60,4);
	visual_text(_Context->x_Auto3582+10,_Context->y_Auto3582+30,350,20,vfh[3],27,0,_Context->msg_Auto3586[_Context->language],strlen(_Context->msg_Auto3586[_Context->language]),1282);
	visual_text(_Context->x_Auto3582+20,_Context->y_Auto3582+70,180,20,vfh[2],16,0,_Context->msg_Auto3587[_Context->language],strlen(_Context->msg_Auto3587[_Context->language]),258);
	visual_text(_Context->x_Auto3582+20,_Context->y_Auto3582+100,180,20,vfh[2],16,0,_Context->msg_Auto3588[_Context->language],strlen(_Context->msg_Auto3588[_Context->language]),258);
	visual_text(_Context->x_Auto3582+20,_Context->y_Auto3582+130,180,20,vfh[2],16,0,_Context->msg_Auto3589[_Context->language],strlen(_Context->msg_Auto3589[_Context->language]),258);
	visual_text(_Context->x_Auto3582+20,_Context->y_Auto3582+160,180,20,vfh[2],16,0,_Context->msg_Auto3590[_Context->language],strlen(_Context->msg_Auto3590[_Context->language]),258);
	visual_text(_Context->x_Auto3582+240,_Context->y_Auto3582+230,112,16,vfh[2],16,0,_Context->msg_Auto3591[_Context->language],strlen(_Context->msg_Auto3591[_Context->language]),258);
	visual_text(_Context->x_Auto3582+20,_Context->y_Auto3582+300,98,16,vfh[2],16,0,_Context->msg_Auto3592[_Context->language],strlen(_Context->msg_Auto3592[_Context->language]),258);
	visual_text(_Context->x_Auto3582+20,_Context->y_Auto3582+320,98,16,vfh[2],16,0,_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]),258);
	visual_select(_Context->x_Auto3582+200,_Context->y_Auto3582+70,150,60,vfh[2],27,0,parse_selection(ProductionLanguageList,&_Context->value_ProductionLanguage),768);
	visual_select(_Context->x_Auto3582+200,_Context->y_Auto3582+100,150,30,vfh[2],27,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),768);
	visual_select(_Context->x_Auto3582+200,_Context->y_Auto3582+130,150,48,vfh[2],0,0,parse_selection(TextFontList,&_Context->value_TextFont),768);
	visual_select(_Context->x_Auto3582+200,_Context->y_Auto3582+160,150,56,vfh[2],0,0,parse_selection(WidgetAlignList,&_Context->value_Alignment),768);
	_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_Auto3582+20,_Context->y_Auto3582+210,112,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
	_Context->trigger_IsUnderline=visual_trigger_code(_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]));
	visual_check(_Context->x_Auto3582+20,_Context->y_Auto3582+230,112,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),_Context->value_IsUnderline|0);
	_Context->trigger_IsShadow=visual_trigger_code(_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]));
	visual_check(_Context->x_Auto3582+20,_Context->y_Auto3582+250,98,16,vfh[2],175,0,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),_Context->value_IsShadow|0);
	visual_select(_Context->x_Auto3582+250,_Context->y_Auto3582+300,98,64,vfh[2],0,0,parse_selection(_Context->msg_SnapOn[_Context->language],&_Context->value_SnapOn),768);
	visual_text(_Context->x_Auto3582+180,_Context->y_Auto3582+300,70,16,vfh[2],16,0,_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]),258);
	visual_text(_Context->x_Auto3582+180,_Context->y_Auto3582+320,70,16,vfh[2],16,0,_Context->msg_Auto3595[_Context->language],strlen(_Context->msg_Auto3595[_Context->language]),258);
	_Context->trigger_LockOn=visual_trigger_code(_Context->msg_LockOn[_Context->language],strlen(_Context->msg_LockOn[_Context->language]));
	visual_check(_Context->x_Auto3582+130,_Context->y_Auto3582+210,112,16,vfh[2],27,0,_Context->msg_LockOn[_Context->language],strlen(_Context->msg_LockOn[_Context->language]),_Context->value_LockOn|0);
	_Context->trigger_TestData=visual_trigger_code(_Context->msg_TestData[_Context->language],strlen(_Context->msg_TestData[_Context->language]));
	visual_check(_Context->x_Auto3582+240,_Context->y_Auto3582+210,126,16,vfh[2],27,0,_Context->msg_TestData[_Context->language],strlen(_Context->msg_TestData[_Context->language]),_Context->value_TestData|0);
	_Context->trigger_Auto3596=visual_trigger_code(_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]));
	visual_check(_Context->x_Auto3582+130,_Context->y_Auto3582+230,112,16,vfh[2],16,0,_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]),_Context->value_Auto3596|0);
	_Context->trigger_DropTool=visual_trigger_code(_Context->msg_DropTool[_Context->language],strlen(_Context->msg_DropTool[_Context->language]));
	visual_check(_Context->x_Auto3582+130,_Context->y_Auto3582+250,112,16,vfh[2],27,0,_Context->msg_DropTool[_Context->language],strlen(_Context->msg_DropTool[_Context->language]),_Context->value_DropTool|0);
	visual_frame(_Context->x_Auto3582+130,_Context->y_Auto3582+300,40+2,16+2,5);
	visual_text(_Context->x_Auto3582+130+1,_Context->y_Auto3582+300+1,40,16,vfh[1],0,0,_Context->buffer_GridWidth,5,0);
	visual_frame(_Context->x_Auto3582+130,_Context->y_Auto3582+320,40+2,16+2,5);
	visual_text(_Context->x_Auto3582+130+1,_Context->y_Auto3582+320+1,40,16,vfh[1],0,0,_Context->buffer_GridHeight,5,0);
	_Context->trigger_UseTextFont=visual_trigger_code(_Context->msg_UseTextFont[_Context->language],strlen(_Context->msg_UseTextFont[_Context->language]));
	visual_button(_Context->x_Auto3582+80,_Context->y_Auto3582+360,98,32,vfh[2],27,28,_Context->msg_UseTextFont[_Context->language],strlen(_Context->msg_UseTextFont[_Context->language]),0);
	_Context->trigger_GridLock=visual_trigger_code(_Context->msg_GridLock[_Context->language],strlen(_Context->msg_GridLock[_Context->language]));
	visual_button(_Context->x_Auto3582+190,_Context->y_Auto3582+360,98,32,vfh[2],27,28,_Context->msg_GridLock[_Context->language],strlen(_Context->msg_GridLock[_Context->language]),0);
	visual_frame(_Context->x_Auto3582+240,_Context->y_Auto3582+250,104+2,16+2,5);
	visual_text(_Context->x_Auto3582+240+1,_Context->y_Auto3582+250+1,104,16,vfh[1],0,0,_Context->buffer_ThickNess,13,0);
	visual_select(_Context->x_Auto3582+250,_Context->y_Auto3582+320,98,48,vfh[2],0,0,parse_selection(_Context->msg_ResizeBy[_Context->language],&_Context->value_ResizeBy),768);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3582+10,_Context->y_Auto3582+360,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3582+300,_Context->y_Auto3582+360,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3582,_Context->y_Auto3582,370,420);

	return(0);
}

private int ProductionLanguage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This select control allows selection of the current default value ";
			mptr[1]="to be used as the production language for new forms models.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ImageFormat_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This select control allows selection of the default image production ";
			mptr[1]="type.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TextFont_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This select control allows selection of the current value to be used ";
			mptr[1]="as the default font number for the creation of new  forms widgets. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Alignment_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This select control allows the default alignment value to be defined ";
			mptr[1]="to be used during the creation of new forms  widgets.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsBold_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This check control provides the default value of the  bold atribut ";
			mptr[1]="or primary option to be used for the creation of  new forms widgets. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsUnderline_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This check control provides the value of the underline option to be ";
			mptr[1]="used in thecreation of new forms widgets.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsShadow_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This check control provides the value of the underline option to be ";
			mptr[1]="used in the creation of new forms widgets.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SnapOn_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[9];
			mptr[0] = "This select control allows selection of the widget alignement grid ";
			mptr[1]="from the following list of choices :  ";
			mptr[2]="  ";
			mptr[3]=" - None : no grid is displayed and no alignment is enforced  ";
			mptr[4]=" - Desktop : the mandatory widget alignment grid is displayed on the ";
			mptr[5]="desktop under the form image.  ";
			mptr[6]=" - Window : the advisory widget grid is displayed over the form window ";
			mptr[7]="area.   ";
			mptr[8]="   ";
			return(visual_online_help(mptr,9));
			}
			break;
		case 1 : 
			{
			char * mptr[9];
			mptr[0] = "Cette controle permet de choisir la nature de la grille d'alignement ";
			mptr[1]="des widgets parmi les options suivants :  ";
			mptr[2]="  ";
			mptr[3]=" - Sans : l'affichage et l'action de la grille est inhib‚.  ";
			mptr[4]=" - Bureau : la grille d'alignment des widgets est active et visible derriere ";
			mptr[5]="l'image ou la fenetre du formulaire.  ";
			mptr[6]=" - Fenetre : la grille d'alignment est visible par dessus de la fenetre ";
			mptr[7]="sans  etre active.   ";
			mptr[8]="   ";
			return(visual_online_help(mptr,9));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int LockOn_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This check control provides the default value of the widget lock to ";
			mptr[1]="be used in the creation of new forms widgets.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TestData_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This check control activates use of test data by the visual table ";
			mptr[1]="instructions used to display Table Widgets. This allows alignment ";
			mptr[2]="and format checking to be performed.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3596_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This check control when active causes model data to be saved to disk ";
			mptr[1]="after sucessful production operations.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DropTool_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "When this check control is active, forms widget tools will be dropped, ";
			mptr[1]="returning to the standard pointer tool, after each new widget item ";
			mptr[2]="is added to the form. Otherwise the widget tool will remain active ";
			mptr[3]="for re-use.  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int GridWidth_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field provides the x or width factor used by the active ";
			mptr[1]="forms editor grid lock mechanism.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int GridHeight_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field provides the y or height factor to be used by the ";
			mptr[1]="active grid lock mechanism of the forms editor.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int UseTextFont_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This push button may be pressed to commit the current  default font ";
			mptr[1]="dimensions to the corresponding grid lock factors width and height. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int GridLock_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This push button may be pressed to gain access to the forms editor ";
			mptr[1]="widget font/grid lock configuration information.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ThickNess_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field provides the default line thickness to be used for ";
			mptr[1]="the creation of new line widgets.   ";
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

private int Auto3582action(struct accept_general_options_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_general_options_hide(_Context);

		_Context->x_Auto3582 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3582 < 0) { _Context->x_Auto3582=0; }
		_Context->y_Auto3582 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3582 < 0) { _Context->y_Auto3582=0; }
			accept_general_options_show(_Context);

		visual_thaw(_Context->x_Auto3582,_Context->y_Auto3582,370,420);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_UseTextFont_event(struct accept_general_options_context * _Context) {
	int fw=guifontsize(_Context->value_TextFont+1);
	int fh=((fw&0xFF00)>>8);
	fw=(fw&0x00FF);
	sprintf(_Context->buffer_GridWidth,"%u",fw);
	sprintf(_Context->buffer_GridHeight,"%u",fh);
		accept_general_options_show(_Context);
;
	return(-1);
}
private int on_GridLock_event(struct accept_general_options_context * _Context) {
	accept_widget_gridlock();
	return(-1);
}
private int on_Accept_event(struct accept_general_options_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_general_options_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_general_options_event(
struct accept_general_options_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsBold == mb ) return(6);
		if (_Context->trigger_IsUnderline == mb ) return(7);
		if (_Context->trigger_IsShadow == mb ) return(8);
		if (_Context->trigger_LockOn == mb ) return(10);
		if (_Context->trigger_TestData == mb ) return(11);
		if (_Context->trigger_Auto3596 == mb ) return(12);
		if (_Context->trigger_DropTool == mb ) return(13);
		if (_Context->trigger_UseTextFont == mb ) return(16);
		if (_Context->trigger_GridLock == mb ) return(17);
		if (_Context->trigger_Accept == mb ) return(20);
		if (_Context->trigger_Cancel == mb ) return(21);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3582+349) )  
	&&  (my >= (_Context->y_Auto3582+4) )  
	&&  (mx <= (_Context->x_Auto3582+366) )  
	&&  (my <= (_Context->y_Auto3582+20) )) {
		return(1);	/* Auto3582 */

		}
	if ((mx >= (_Context->x_Auto3582+333) )  
	&&  (my >= (_Context->y_Auto3582+4) )  
	&&  (mx <= (_Context->x_Auto3582+350) )  
	&&  (my <= (_Context->y_Auto3582+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vparam.htm");
			};
		return(-1);	/* Auto3582 */

		}
	if ((mx >= (_Context->x_Auto3582+317) )  
	&&  (my >= (_Context->y_Auto3582+4) )  
	&&  (mx <= (_Context->x_Auto3582+334) )  
	&&  (my <= (_Context->y_Auto3582+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_general_options_show(_Context);
		return(-1);	/* Auto3582 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3582+4) )  
		&&  (my >= (_Context->y_Auto3582+4) )  
		&&  (mx <= (_Context->x_Auto3582+302) )  
		&&  (my <= (_Context->y_Auto3582+20) )) {
			return( Auto3582action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3582+200+0) ) 
	&&  ( my >= (_Context->y_Auto3582+70) ) 
	&&  ( mx <= (_Context->x_Auto3582+200+150) ) 
	&&  ( my <= (_Context->y_Auto3582+70+16))) {
		return(2); /* ProductionLanguage */
		}
	if (( mx >= (_Context->x_Auto3582+200+0) ) 
	&&  ( my >= (_Context->y_Auto3582+100) ) 
	&&  ( mx <= (_Context->x_Auto3582+200+150) ) 
	&&  ( my <= (_Context->y_Auto3582+100+16))) {
		return(3); /* ImageFormat */
		}
	if (( mx >= (_Context->x_Auto3582+200+0) ) 
	&&  ( my >= (_Context->y_Auto3582+130) ) 
	&&  ( mx <= (_Context->x_Auto3582+200+150) ) 
	&&  ( my <= (_Context->y_Auto3582+130+16))) {
		return(4); /* TextFont */
		}
	if (( mx >= (_Context->x_Auto3582+200+0) ) 
	&&  ( my >= (_Context->y_Auto3582+160) ) 
	&&  ( mx <= (_Context->x_Auto3582+200+150) ) 
	&&  ( my <= (_Context->y_Auto3582+160+16))) {
		return(5); /* Alignment */
		}
	if (( mx >= (_Context->x_Auto3582+20) ) 
	&&  ( my >= (_Context->y_Auto3582+210) ) 
	&&  ( mx <= (_Context->x_Auto3582+20+112) ) 
	&&  ( my <= (_Context->y_Auto3582+210+16))) {
		return(6); /* IsBold */
		}
	if (( mx >= (_Context->x_Auto3582+20) ) 
	&&  ( my >= (_Context->y_Auto3582+230) ) 
	&&  ( mx <= (_Context->x_Auto3582+20+112) ) 
	&&  ( my <= (_Context->y_Auto3582+230+16))) {
		return(7); /* IsUnderline */
		}
	if (( mx >= (_Context->x_Auto3582+20) ) 
	&&  ( my >= (_Context->y_Auto3582+250) ) 
	&&  ( mx <= (_Context->x_Auto3582+20+98) ) 
	&&  ( my <= (_Context->y_Auto3582+250+16))) {
		return(8); /* IsShadow */
		}
	if (( mx >= (_Context->x_Auto3582+250+0) ) 
	&&  ( my >= (_Context->y_Auto3582+300) ) 
	&&  ( mx <= (_Context->x_Auto3582+250+98) ) 
	&&  ( my <= (_Context->y_Auto3582+300+16))) {
		return(9); /* SnapOn */
		}
	if (( mx >= (_Context->x_Auto3582+130) ) 
	&&  ( my >= (_Context->y_Auto3582+210) ) 
	&&  ( mx <= (_Context->x_Auto3582+130+112) ) 
	&&  ( my <= (_Context->y_Auto3582+210+16))) {
		return(10); /* LockOn */
		}
	if (( mx >= (_Context->x_Auto3582+240) ) 
	&&  ( my >= (_Context->y_Auto3582+210) ) 
	&&  ( mx <= (_Context->x_Auto3582+240+126) ) 
	&&  ( my <= (_Context->y_Auto3582+210+16))) {
		return(11); /* TestData */
		}
	if (( mx >= (_Context->x_Auto3582+130) ) 
	&&  ( my >= (_Context->y_Auto3582+230) ) 
	&&  ( mx <= (_Context->x_Auto3582+130+112) ) 
	&&  ( my <= (_Context->y_Auto3582+230+16))) {
		return(12); /* Auto3596 */
		}
	if (( mx >= (_Context->x_Auto3582+130) ) 
	&&  ( my >= (_Context->y_Auto3582+250) ) 
	&&  ( mx <= (_Context->x_Auto3582+130+112) ) 
	&&  ( my <= (_Context->y_Auto3582+250+16))) {
		return(13); /* DropTool */
		}
	if (( mx >= (_Context->x_Auto3582+130) ) 
	&&  ( my >= (_Context->y_Auto3582+300) ) 
	&&  ( mx <= (_Context->x_Auto3582+130+40) ) 
	&&  ( my <= (_Context->y_Auto3582+300+16))) {
		return(14); /* GridWidth */
		}
	if (( mx >= (_Context->x_Auto3582+130) ) 
	&&  ( my >= (_Context->y_Auto3582+320) ) 
	&&  ( mx <= (_Context->x_Auto3582+130+40) ) 
	&&  ( my <= (_Context->y_Auto3582+320+16))) {
		return(15); /* GridHeight */
		}
	if (( mx >= (_Context->x_Auto3582+80) ) 
	&&  ( my >= (_Context->y_Auto3582+360) ) 
	&&  ( mx <= (_Context->x_Auto3582+80+98) ) 
	&&  ( my <= (_Context->y_Auto3582+360+32))) {
		return(16); /* UseTextFont */
		}
	if (( mx >= (_Context->x_Auto3582+190) ) 
	&&  ( my >= (_Context->y_Auto3582+360) ) 
	&&  ( mx <= (_Context->x_Auto3582+190+98) ) 
	&&  ( my <= (_Context->y_Auto3582+360+32))) {
		return(17); /* GridLock */
		}
	if (( mx >= (_Context->x_Auto3582+240) ) 
	&&  ( my >= (_Context->y_Auto3582+250) ) 
	&&  ( mx <= (_Context->x_Auto3582+240+104) ) 
	&&  ( my <= (_Context->y_Auto3582+250+16))) {
		return(18); /* ThickNess */
		}
	if (( mx >= (_Context->x_Auto3582+250+0) ) 
	&&  ( my >= (_Context->y_Auto3582+320) ) 
	&&  ( mx <= (_Context->x_Auto3582+250+98) ) 
	&&  ( my <= (_Context->y_Auto3582+320+16))) {
		return(19); /* ResizeBy */
		}
	if (( mx >= (_Context->x_Auto3582+10) ) 
	&&  ( my >= (_Context->y_Auto3582+360) ) 
	&&  ( mx <= (_Context->x_Auto3582+10+56) ) 
	&&  ( my <= (_Context->y_Auto3582+360+48))) {
		return(20); /* Accept */
		}
	if (( mx >= (_Context->x_Auto3582+300) ) 
	&&  ( my >= (_Context->y_Auto3582+360) ) 
	&&  ( mx <= (_Context->x_Auto3582+300+56) ) 
	&&  ( my <= (_Context->y_Auto3582+360+48))) {
		return(21); /* Cancel */
		}

	return(-1);
}


public	int	accept_general_options_focus(struct accept_general_options_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* ProductionLanguage */
				_Context->keycode = visual_select(_Context->x_Auto3582+200,_Context->y_Auto3582+70,150,60,vfh[2],27,0,parse_selection(ProductionLanguageList,&_Context->value_ProductionLanguage),770);
				break;
			case	0x3 :
				/* ImageFormat */
				_Context->keycode = visual_select(_Context->x_Auto3582+200,_Context->y_Auto3582+100,150,30,vfh[2],27,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),770);
				break;
			case	0x4 :
				/* TextFont */
				_Context->keycode = visual_select(_Context->x_Auto3582+200,_Context->y_Auto3582+130,150,48,vfh[2],0,0,parse_selection(TextFontList,&_Context->value_TextFont),770);
				break;
			case	0x5 :
				/* Alignment */
				_Context->keycode = visual_select(_Context->x_Auto3582+200,_Context->y_Auto3582+160,150,56,vfh[2],0,0,parse_selection(WidgetAlignList,&_Context->value_Alignment),770);
				break;
			case	0x6 :
				/* IsBold */
				visual_check(_Context->x_Auto3582+20,_Context->y_Auto3582+210,112,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),(_Context->value_IsBold |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_Auto3582+20,_Context->y_Auto3582+210,112,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
				break;
			case	0x7 :
				/* IsUnderline */
				visual_check(_Context->x_Auto3582+20,_Context->y_Auto3582+230,112,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),(_Context->value_IsUnderline |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsUnderline=visual_trigger_code(_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]));
	visual_check(_Context->x_Auto3582+20,_Context->y_Auto3582+230,112,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),_Context->value_IsUnderline|0);
				break;
			case	0x8 :
				/* IsShadow */
				visual_check(_Context->x_Auto3582+20,_Context->y_Auto3582+250,98,16,vfh[2],175,0,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),(_Context->value_IsShadow |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsShadow=visual_trigger_code(_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]));
	visual_check(_Context->x_Auto3582+20,_Context->y_Auto3582+250,98,16,vfh[2],175,0,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),_Context->value_IsShadow|0);
				break;
			case	0x9 :
				/* SnapOn */
				_Context->keycode = visual_select(_Context->x_Auto3582+250,_Context->y_Auto3582+300,98,64,vfh[2],0,0,parse_selection(_Context->msg_SnapOn[_Context->language],&_Context->value_SnapOn),770);
				break;
			case	0xa :
				/* LockOn */
				visual_check(_Context->x_Auto3582+130,_Context->y_Auto3582+210,112,16,vfh[2],27,0,_Context->msg_LockOn[_Context->language],strlen(_Context->msg_LockOn[_Context->language]),(_Context->value_LockOn |2));
				_Context->keycode = visual_getch();
				_Context->trigger_LockOn=visual_trigger_code(_Context->msg_LockOn[_Context->language],strlen(_Context->msg_LockOn[_Context->language]));
	visual_check(_Context->x_Auto3582+130,_Context->y_Auto3582+210,112,16,vfh[2],27,0,_Context->msg_LockOn[_Context->language],strlen(_Context->msg_LockOn[_Context->language]),_Context->value_LockOn|0);
				break;
			case	0xb :
				/* TestData */
				visual_check(_Context->x_Auto3582+240,_Context->y_Auto3582+210,126,16,vfh[2],27,0,_Context->msg_TestData[_Context->language],strlen(_Context->msg_TestData[_Context->language]),(_Context->value_TestData |2));
				_Context->keycode = visual_getch();
				_Context->trigger_TestData=visual_trigger_code(_Context->msg_TestData[_Context->language],strlen(_Context->msg_TestData[_Context->language]));
	visual_check(_Context->x_Auto3582+240,_Context->y_Auto3582+210,126,16,vfh[2],27,0,_Context->msg_TestData[_Context->language],strlen(_Context->msg_TestData[_Context->language]),_Context->value_TestData|0);
				break;
			case	0xd :
				/* DropTool */
				visual_check(_Context->x_Auto3582+130,_Context->y_Auto3582+250,112,16,vfh[2],27,0,_Context->msg_DropTool[_Context->language],strlen(_Context->msg_DropTool[_Context->language]),(_Context->value_DropTool |2));
				_Context->keycode = visual_getch();
				_Context->trigger_DropTool=visual_trigger_code(_Context->msg_DropTool[_Context->language],strlen(_Context->msg_DropTool[_Context->language]));
	visual_check(_Context->x_Auto3582+130,_Context->y_Auto3582+250,112,16,vfh[2],27,0,_Context->msg_DropTool[_Context->language],strlen(_Context->msg_DropTool[_Context->language]),_Context->value_DropTool|0);
				break;
			case	0xe :
				/* GridWidth */
				_Context->keycode = visual_edit(_Context->x_Auto3582+130+1,_Context->y_Auto3582+300+1,40,16,vfh[1],_Context->buffer_GridWidth,5);
			break;
			case	0xf :
				/* GridHeight */
				_Context->keycode = visual_edit(_Context->x_Auto3582+130+1,_Context->y_Auto3582+320+1,40,16,vfh[1],_Context->buffer_GridHeight,5);
			break;
			case	0x10 :
				/* UseTextFont */
				_Context->trigger_UseTextFont=visual_trigger_code(_Context->msg_UseTextFont[_Context->language],strlen(_Context->msg_UseTextFont[_Context->language]));
				visual_button(_Context->x_Auto3582+80,_Context->y_Auto3582+360,98,32,vfh[2],27,28,_Context->msg_UseTextFont[_Context->language],strlen(_Context->msg_UseTextFont[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_UseTextFont=visual_trigger_code(_Context->msg_UseTextFont[_Context->language],strlen(_Context->msg_UseTextFont[_Context->language]));
	visual_button(_Context->x_Auto3582+80,_Context->y_Auto3582+360,98,32,vfh[2],27,28,_Context->msg_UseTextFont[_Context->language],strlen(_Context->msg_UseTextFont[_Context->language]),0);
				break;
			case	0x12 :
				/* ThickNess */
				_Context->keycode = visual_edit(_Context->x_Auto3582+240+1,_Context->y_Auto3582+250+1,104,16,vfh[1],_Context->buffer_ThickNess,13);
			break;
			case	0x13 :
				/* ResizeBy */
				_Context->keycode = visual_select(_Context->x_Auto3582+250,_Context->y_Auto3582+320,98,48,vfh[2],0,0,parse_selection(_Context->msg_ResizeBy[_Context->language],&_Context->value_ResizeBy),770);
				break;
			case	0x14 :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(_Context->x_Auto3582+10,_Context->y_Auto3582+360,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3582+10,_Context->y_Auto3582+360,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0x15 :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_Auto3582+300,_Context->y_Auto3582+360,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3582+300,_Context->y_Auto3582+360,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_general_options_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=21;
			accept_general_options_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_general_options_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (ProductionLanguage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (ImageFormat_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (TextFont_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Alignment_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (IsBold_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (IsUnderline_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (IsShadow_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (SnapOn_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (LockOn_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (TestData_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (Auto3596_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (DropTool_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (GridWidth_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (GridHeight_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (UseTextFont_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (GridLock_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (ThickNess_help(_Context) != 0) { continue; }
						else { break; }
					case	0x14 :
						if (Accept_help(_Context) != 0) { continue; }
						else { break; }
					case	0x15 :
						if (Cancel_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3582 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* ProductionLanguage */
					continue;
				case	0x3 :
					/* ImageFormat */
					continue;
				case	0x4 :
					/* TextFont */
					continue;
				case	0x5 :
					/* Alignment */
					continue;
				case	0x6 :
					/* IsBold */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsBold += 1;
						_Context->value_IsBold &= 1;
						}
					continue;
				case	0x7 :
					/* IsUnderline */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsUnderline += 1;
						_Context->value_IsUnderline &= 1;
						}
					continue;
				case	0x8 :
					/* IsShadow */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsShadow += 1;
						_Context->value_IsShadow &= 1;
						}
					continue;
				case	0x9 :
					/* SnapOn */
					continue;
				case	0xa :
					/* LockOn */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_LockOn += 1;
						_Context->value_LockOn &= 1;
						}
					continue;
				case	0xb :
					/* TestData */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_TestData += 1;
						_Context->value_TestData &= 1;
						}
					continue;
				case	0xc :
					/* Auto3596 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Auto3596 += 1;
						_Context->value_Auto3596 &= 1;
						_Context->trigger_Auto3596=visual_trigger_code(_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]));
	visual_check(_Context->x_Auto3582+130,_Context->y_Auto3582+230,112,16,vfh[2],16,0,_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]),_Context->value_Auto3596|0);
						}
					continue;
				case	0xd :
					/* DropTool */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_DropTool += 1;
						_Context->value_DropTool &= 1;
						}
					continue;
				case	0xe :
					/* GridWidth */
					continue;
				case	0xf :
					/* GridHeight */
					continue;
				case	0x10 :
					/* UseTextFont */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_UseTextFont=visual_trigger_code(_Context->msg_UseTextFont[_Context->language],strlen(_Context->msg_UseTextFont[_Context->language]));
						visual_button(_Context->x_Auto3582+80,_Context->y_Auto3582+360,98,32,vfh[2],27,28,_Context->msg_UseTextFont[_Context->language],strlen(_Context->msg_UseTextFont[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_UseTextFont=visual_trigger_code(_Context->msg_UseTextFont[_Context->language],strlen(_Context->msg_UseTextFont[_Context->language]));
	visual_button(_Context->x_Auto3582+80,_Context->y_Auto3582+360,98,32,vfh[2],27,28,_Context->msg_UseTextFont[_Context->language],strlen(_Context->msg_UseTextFont[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_UseTextFont_event(_Context)) != -1) break;

						}
					continue;
				case	0x11 :
					/* GridLock */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_GridLock=visual_trigger_code(_Context->msg_GridLock[_Context->language],strlen(_Context->msg_GridLock[_Context->language]));
						visual_button(_Context->x_Auto3582+190,_Context->y_Auto3582+360,98,32,vfh[2],27,28,_Context->msg_GridLock[_Context->language],strlen(_Context->msg_GridLock[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_GridLock=visual_trigger_code(_Context->msg_GridLock[_Context->language],strlen(_Context->msg_GridLock[_Context->language]));
	visual_button(_Context->x_Auto3582+190,_Context->y_Auto3582+360,98,32,vfh[2],27,28,_Context->msg_GridLock[_Context->language],strlen(_Context->msg_GridLock[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_GridLock_event(_Context)) != -1) break;

						}
					continue;
				case	0x12 :
					/* ThickNess */
					continue;
				case	0x13 :
					/* ResizeBy */
					continue;
				case	0x14 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_Auto3582+10,_Context->y_Auto3582+360,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3582+10,_Context->y_Auto3582+360,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x15 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Auto3582+300,_Context->y_Auto3582+360,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3582+300,_Context->y_Auto3582+360,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

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
				_Context->focus_item=21;
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

public	int	accept_general_options(
	char * pProductionLanguage,
	char * pImageFormat,
	char * pTextFont,
	char * pAlignment,
	char * pIsBold,
	char * pIsUnderline,
	char * pIsShadow,
	char * pSnapOn,
	char * pLockOn,
	char * pTestData,
	char * pAuto3596,
	char * pDropTool,
	char * pGridWidth,
	char * pGridHeight,
	char * pThickNess,
	char * pResizeBy)
{
	int	status=0;
	struct accept_general_options_context * _Context=(struct accept_general_options_context*) 0;
	status = accept_general_options_create(
	&_Context,
	 pProductionLanguage,
	 pImageFormat,
	 pTextFont,
	 pAlignment,
	 pIsBold,
	 pIsUnderline,
	 pIsShadow,
	 pSnapOn,
	 pLockOn,
	 pTestData,
	 pAuto3596,
	 pDropTool,
	 pGridWidth,
	 pGridHeight,
	 pThickNess,
	 pResizeBy);
	if ( status != 0) return(status);
	status = accept_general_options_show(_Context);
		enter_modal();
	status = accept_general_options_focus(_Context);
		leave_modal();
	status = accept_general_options_hide(_Context);
	status = accept_general_options_remove(
	_Context,
	 pProductionLanguage,
	 pImageFormat,
	 pTextFont,
	 pAlignment,
	 pIsBold,
	 pIsUnderline,
	 pIsShadow,
	 pSnapOn,
	 pLockOn,
	 pTestData,
	 pAuto3596,
	 pDropTool,
	 pGridWidth,
	 pGridHeight,
	 pThickNess,
	 pResizeBy);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vparam_c */
