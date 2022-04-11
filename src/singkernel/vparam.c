
#ifndef _vparam_c
#define _vparam_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vparam.xml  */
/* Target         : vparam.c  */
/* Identification : 0.0-1100085336-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto553   "Sing : Version 1.0a"
#define fr_Auto553   "Sing : Version 1.0a"
#define en_Auto1195   "skin.gif"
#define fr_Auto1195   "skin.gif"
#define en_Auto573   "General Parameters"
#define fr_Auto573   "ParamŠtres Generaux"
#define it_Auto573   "General Parameters"
#define es_Auto573   "General Parameters"
#define de_Auto573   "General Parameters"
#define nl_Auto573   "General Parameters"
#define pt_Auto573   "General Parameters"
#define xx_Auto573   "General Parameters"
#define en_Auto555   "Production Language"
#define fr_Auto555   "Langage de Production"
#define it_Auto555   ""
#define es_Auto555   ""
#define de_Auto555   ""
#define nl_Auto555   ""
#define pt_Auto555   ""
#define xx_Auto555   ""
#define en_Auto556   "Image Production"
#define fr_Auto556   "Production d'Image"
#define it_Auto556   "Image Production"
#define es_Auto556   "Image Production"
#define de_Auto556   "Image Production"
#define nl_Auto556   "Image Production"
#define pt_Auto556   "Image Production"
#define xx_Auto556   "Image Production"
#define en_Auto557   "Current Text Font"
#define fr_Auto557   "Fonte courant"
#define it_Auto557   "Current Text Font"
#define es_Auto557   "Current Text Font"
#define de_Auto557   "Current Text Font"
#define nl_Auto557   "Current Text Font"
#define pt_Auto557   "Current Text Font"
#define xx_Auto557   "Current Text Font"
#define en_Auto558   "Alignment"
#define fr_Auto558   "Alignment"
#define it_Auto558   "Alignment"
#define es_Auto558   "Alignment"
#define de_Auto558   "Alignment"
#define nl_Auto558   "Alignment"
#define pt_Auto558   "Alignment"
#define xx_Auto558   "Alignment"
#define en_Auto595   "Line Thickness"
#define fr_Auto595   "Epaisseur de Ligne"
#define it_Auto595   ""
#define es_Auto595   ""
#define de_Auto595   ""
#define nl_Auto595   ""
#define pt_Auto595   ""
#define xx_Auto595   ""
#define en_Auto616   "Grid Width"
#define fr_Auto616   "Largeur de Grille"
#define it_Auto616   "Grid Width"
#define es_Auto616   "Grid Width"
#define de_Auto616   "Grid Width"
#define nl_Auto616   "Grid Width"
#define pt_Auto616   "Grid Width"
#define xx_Auto616   "Grid Width"
#define en_AutoSave   "Auto sa&ve"
#define fr_AutoSave   "M‚morisation‚"
#define it_AutoSave   ""
#define es_AutoSave   ""
#define de_AutoSave   ""
#define nl_AutoSave   ""
#define pt_AutoSave   ""
#define xx_AutoSave   ""
#define en_Auto5571   "Grid Height"
#define fr_Auto5571   "Hauteur de Grille"
#define it_Auto5571   "Grid Height"
#define es_Auto5571   "Grid Height"
#define de_Auto5571   "Grid Height"
#define nl_Auto5571   "Grid Height"
#define pt_Auto5571   "Grid Height"
#define xx_Auto5571   "Grid Height"
#define en_IsBold   "&Bold"
#define fr_IsBold   "&Gras"
#define en_IsUnderline   "&Underline"
#define fr_IsUnderline   "&Soulign‚"
#define en_IsShadow   "&Shadow"
#define fr_IsShadow   "&Ombr‚"
#define en_SnapOn   "&Grid On"
#define fr_SnapOn   "&Grille"
#define it_SnapOn   "&Grid On"
#define es_SnapOn   "&Grid On"
#define de_SnapOn   "&Grid On"
#define nl_SnapOn   "&Grid On"
#define pt_SnapOn   "&Grid On"
#define xx_SnapOn   "&Grid On"
#define en_GridWidth   ""
#define en_UseTextFont   "Te&xtFont"
#define fr_UseTextFont   "&Fonte"
#define it_UseTextFont   "Te&xtFont"
#define es_UseTextFont   "Te&xtFont"
#define de_UseTextFont   "Te&xtFont"
#define nl_UseTextFont   "Te&xtFont"
#define pt_UseTextFont   "Te&xtFont"
#define xx_UseTextFont   "Te&xtFont"
#define en_LockOn   "&Lock On"
#define fr_LockOn   "&Verouill‚"
#define it_LockOn   "&Lock On"
#define es_LockOn   "&Lock On"
#define de_LockOn   "&Lock On"
#define nl_LockOn   "&Lock On"
#define pt_LockOn   "&Lock On"
#define xx_LockOn   "&Lock On"
#define en_DropTool   "&DropTool"
#define fr_DropTool   "&Lacher"
#define it_DropTool   "&DropTool"
#define es_DropTool   "&DropTool"
#define de_DropTool   "&DropTool"
#define nl_DropTool   "&DropTool"
#define pt_DropTool   "&DropTool"
#define xx_DropTool   "&DropTool"
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_Auto3413   "&Cancel"
#define fr_Auto3413   "&Annuler"
static int	vfh[10];

private struct accept_general_options_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto553[8];
	int	x_Auto553;
	int	y_Auto553;
	int	w_Auto553;
	int	h_Auto553;
	char * msg_Auto1195[8];
	char * msg_Auto573[8];
	char * msg_Auto555[8];
	char * msg_Auto556[8];
	char * msg_Auto557[8];
	char * msg_Auto558[8];
	char * msg_Auto595[8];
	char * msg_Auto616[8];
	char * msg_AutoSave[8];
	int	trigger_AutoSave;
	int	value_AutoSave;
	char * msg_Auto5571[8];
	char * msg_ProductionLanguage[8];
	int	value_ProductionLanguage;
	char * msg_ImageFormat[8];
	int	value_ImageFormat;
	char * msg_TextFont[8];
	int	value_TextFont;
	char * msg_Alignment[8];
	int	value_Alignment;
	char * msg_IsBold[8];
	int	trigger_IsBold;
	int	value_IsBold;
	char * msg_IsUnderline[8];
	int	trigger_IsUnderline;
	int	value_IsUnderline;
	char * msg_IsShadow[8];
	int	trigger_IsShadow;
	int	value_IsShadow;
	char * msg_SnapOn[8];
	int	trigger_SnapOn;
	int	value_SnapOn;
	char	buffer_GridWidth[8];
	char	buffer_GridHeight[8];
	char * msg_UseTextFont[8];
	int	trigger_UseTextFont;
	char	buffer_ThickNess[8];
	char * msg_LockOn[8];
	int	trigger_LockOn;
	int	value_LockOn;
	char * msg_DropTool[8];
	int	trigger_DropTool;
	int	value_DropTool;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Auto3413[8];
	int	trigger_Auto3413;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[15];
	};

public	int	accept_general_options_create(
	struct accept_general_options_context ** cptr,
	char * pAutoSave,
	char * pProductionLanguage,
	char * pImageFormat,
	char * pTextFont,
	char * pAlignment,
	char * pIsBold,
	char * pIsUnderline,
	char * pIsShadow,
	char * pSnapOn,
	char * pGridWidth,
	char * pGridHeight,
	char * pThickNess,
	char * pLockOn,
	char * pDropTool)
{

	int i;
	struct accept_general_options_context * _Context=(struct accept_general_options_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_general_options_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=18;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature," WWWWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pAutoSave);
		if (!( pAutoSave )) _Context->value_AutoSave=0;
		else	_Context->value_AutoSave = *((int *)pAutoSave);
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
		visual_transferin(_Context->buffer_GridWidth, 7, pGridWidth);
		visual_transferin(_Context->buffer_GridHeight, 7, pGridHeight);
		visual_transferin(_Context->buffer_ThickNess, 7, pThickNess);
		visual_transferin((void *) 0, 0, pLockOn);
		if (!( pLockOn )) _Context->value_LockOn=0;
		else	_Context->value_LockOn = *((int *)pLockOn);
		visual_transferin((void *) 0, 0, pDropTool);
		if (!( pDropTool )) _Context->value_DropTool=0;
		else	_Context->value_DropTool = *((int *)pDropTool);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto553[i]=" ";
	_Context->msg_Auto553[0]=en_Auto553;
	_Context->msg_Auto553[1]=fr_Auto553;
	_Context->x_Auto553=215;
	_Context->y_Auto553=95;
	_Context->w_Auto553=370;
	_Context->h_Auto553=410;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto1195[i]=" ";
	_Context->msg_Auto1195[0]=en_Auto1195;
	_Context->msg_Auto1195[1]=fr_Auto1195;
	for (i=0; i < 8; i++)_Context->msg_Auto573[i]=" ";
	_Context->msg_Auto573[0]=en_Auto573;
	_Context->msg_Auto573[1]=fr_Auto573;
	_Context->msg_Auto573[2]=it_Auto573;
	_Context->msg_Auto573[3]=es_Auto573;
	_Context->msg_Auto573[4]=de_Auto573;
	_Context->msg_Auto573[5]=nl_Auto573;
	_Context->msg_Auto573[6]=pt_Auto573;
	_Context->msg_Auto573[7]=xx_Auto573;
	for (i=0; i < 8; i++)_Context->msg_Auto555[i]=" ";
	_Context->msg_Auto555[0]=en_Auto555;
	_Context->msg_Auto555[1]=fr_Auto555;
	_Context->msg_Auto555[2]=it_Auto555;
	_Context->msg_Auto555[3]=es_Auto555;
	_Context->msg_Auto555[4]=de_Auto555;
	_Context->msg_Auto555[5]=nl_Auto555;
	_Context->msg_Auto555[6]=pt_Auto555;
	_Context->msg_Auto555[7]=xx_Auto555;
	for (i=0; i < 8; i++)_Context->msg_Auto556[i]=" ";
	_Context->msg_Auto556[0]=en_Auto556;
	_Context->msg_Auto556[1]=fr_Auto556;
	_Context->msg_Auto556[2]=it_Auto556;
	_Context->msg_Auto556[3]=es_Auto556;
	_Context->msg_Auto556[4]=de_Auto556;
	_Context->msg_Auto556[5]=nl_Auto556;
	_Context->msg_Auto556[6]=pt_Auto556;
	_Context->msg_Auto556[7]=xx_Auto556;
	for (i=0; i < 8; i++)_Context->msg_Auto557[i]=" ";
	_Context->msg_Auto557[0]=en_Auto557;
	_Context->msg_Auto557[1]=fr_Auto557;
	_Context->msg_Auto557[2]=it_Auto557;
	_Context->msg_Auto557[3]=es_Auto557;
	_Context->msg_Auto557[4]=de_Auto557;
	_Context->msg_Auto557[5]=nl_Auto557;
	_Context->msg_Auto557[6]=pt_Auto557;
	_Context->msg_Auto557[7]=xx_Auto557;
	for (i=0; i < 8; i++)_Context->msg_Auto558[i]=" ";
	_Context->msg_Auto558[0]=en_Auto558;
	_Context->msg_Auto558[1]=fr_Auto558;
	_Context->msg_Auto558[2]=it_Auto558;
	_Context->msg_Auto558[3]=es_Auto558;
	_Context->msg_Auto558[4]=de_Auto558;
	_Context->msg_Auto558[5]=nl_Auto558;
	_Context->msg_Auto558[6]=pt_Auto558;
	_Context->msg_Auto558[7]=xx_Auto558;
	for (i=0; i < 8; i++)_Context->msg_Auto595[i]=" ";
	_Context->msg_Auto595[0]=en_Auto595;
	_Context->msg_Auto595[1]=fr_Auto595;
	_Context->msg_Auto595[2]=it_Auto595;
	_Context->msg_Auto595[3]=es_Auto595;
	_Context->msg_Auto595[4]=de_Auto595;
	_Context->msg_Auto595[5]=nl_Auto595;
	_Context->msg_Auto595[6]=pt_Auto595;
	_Context->msg_Auto595[7]=xx_Auto595;
	for (i=0; i < 8; i++)_Context->msg_Auto616[i]=" ";
	_Context->msg_Auto616[0]=en_Auto616;
	_Context->msg_Auto616[1]=fr_Auto616;
	_Context->msg_Auto616[2]=it_Auto616;
	_Context->msg_Auto616[3]=es_Auto616;
	_Context->msg_Auto616[4]=de_Auto616;
	_Context->msg_Auto616[5]=nl_Auto616;
	_Context->msg_Auto616[6]=pt_Auto616;
	_Context->msg_Auto616[7]=xx_Auto616;
	for (i=0; i < 8; i++)_Context->msg_AutoSave[i]=" ";
	_Context->msg_AutoSave[0]=en_AutoSave;
	_Context->msg_AutoSave[1]=fr_AutoSave;
	_Context->msg_AutoSave[2]=it_AutoSave;
	_Context->msg_AutoSave[3]=es_AutoSave;
	_Context->msg_AutoSave[4]=de_AutoSave;
	_Context->msg_AutoSave[5]=nl_AutoSave;
	_Context->msg_AutoSave[6]=pt_AutoSave;
	_Context->msg_AutoSave[7]=xx_AutoSave;
	for (i=0; i < 8; i++)_Context->msg_Auto5571[i]=" ";
	_Context->msg_Auto5571[0]=en_Auto5571;
	_Context->msg_Auto5571[1]=fr_Auto5571;
	_Context->msg_Auto5571[2]=it_Auto5571;
	_Context->msg_Auto5571[3]=es_Auto5571;
	_Context->msg_Auto5571[4]=de_Auto5571;
	_Context->msg_Auto5571[5]=nl_Auto5571;
	_Context->msg_Auto5571[6]=pt_Auto5571;
	_Context->msg_Auto5571[7]=xx_Auto5571;
	for (i=0; i < 8; i++)_Context->msg_ProductionLanguage[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_ImageFormat[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_TextFont[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_Alignment[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_IsBold[i]=" ";
	_Context->msg_IsBold[0]=en_IsBold;
	_Context->msg_IsBold[1]=fr_IsBold;
	for (i=0; i < 8; i++)_Context->msg_IsUnderline[i]=" ";
	_Context->msg_IsUnderline[0]=en_IsUnderline;
	_Context->msg_IsUnderline[1]=fr_IsUnderline;
	for (i=0; i < 8; i++)_Context->msg_IsShadow[i]=" ";
	_Context->msg_IsShadow[0]=en_IsShadow;
	_Context->msg_IsShadow[1]=fr_IsShadow;
	for (i=0; i < 8; i++)_Context->msg_SnapOn[i]=" ";
	_Context->msg_SnapOn[0]=en_SnapOn;
	_Context->msg_SnapOn[1]=fr_SnapOn;
	_Context->msg_SnapOn[2]=it_SnapOn;
	_Context->msg_SnapOn[3]=es_SnapOn;
	_Context->msg_SnapOn[4]=de_SnapOn;
	_Context->msg_SnapOn[5]=nl_SnapOn;
	_Context->msg_SnapOn[6]=pt_SnapOn;
	_Context->msg_SnapOn[7]=xx_SnapOn;
	for (i=0; i < 8; i++)_Context->msg_UseTextFont[i]=" ";
	_Context->msg_UseTextFont[0]=en_UseTextFont;
	_Context->msg_UseTextFont[1]=fr_UseTextFont;
	_Context->msg_UseTextFont[2]=it_UseTextFont;
	_Context->msg_UseTextFont[3]=es_UseTextFont;
	_Context->msg_UseTextFont[4]=de_UseTextFont;
	_Context->msg_UseTextFont[5]=nl_UseTextFont;
	_Context->msg_UseTextFont[6]=pt_UseTextFont;
	_Context->msg_UseTextFont[7]=xx_UseTextFont;
	for (i=0; i < 8; i++)_Context->msg_LockOn[i]=" ";
	_Context->msg_LockOn[0]=en_LockOn;
	_Context->msg_LockOn[1]=fr_LockOn;
	_Context->msg_LockOn[2]=it_LockOn;
	_Context->msg_LockOn[3]=es_LockOn;
	_Context->msg_LockOn[4]=de_LockOn;
	_Context->msg_LockOn[5]=nl_LockOn;
	_Context->msg_LockOn[6]=pt_LockOn;
	_Context->msg_LockOn[7]=xx_LockOn;
	for (i=0; i < 8; i++)_Context->msg_DropTool[i]=" ";
	_Context->msg_DropTool[0]=en_DropTool;
	_Context->msg_DropTool[1]=fr_DropTool;
	_Context->msg_DropTool[2]=it_DropTool;
	_Context->msg_DropTool[3]=es_DropTool;
	_Context->msg_DropTool[4]=de_DropTool;
	_Context->msg_DropTool[5]=nl_DropTool;
	_Context->msg_DropTool[6]=pt_DropTool;
	_Context->msg_DropTool[7]=xx_DropTool;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Auto3413[i]=" ";
	_Context->msg_Auto3413[0]=en_Auto3413;
	_Context->msg_Auto3413[1]=fr_Auto3413;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto553,_Context->y_Auto553,370+10,410+10);
	return(0);
}

public 	int	accept_general_options_hide(struct accept_general_options_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto553,_Context->y_Auto553);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_general_options_remove(
	struct accept_general_options_context * _Context,
	char * pAutoSave,
	char * pProductionLanguage,
	char * pImageFormat,
	char * pTextFont,
	char * pAlignment,
	char * pIsBold,
	char * pIsUnderline,
	char * pIsShadow,
	char * pSnapOn,
	char * pGridWidth,
	char * pGridHeight,
	char * pThickNess,
	char * pLockOn,
	char * pDropTool)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature," WWWWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pAutoSave);
		if ( pAutoSave != (char *) 0)
			*((int*)pAutoSave) = _Context->value_AutoSave;
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
		visual_transferout(_Context->buffer_GridWidth, 7, pGridWidth);
		visual_transferout(_Context->buffer_GridHeight, 7, pGridHeight);
		visual_transferout(_Context->buffer_ThickNess, 7, pThickNess);
		visual_transferout((void *) 0, 0, pLockOn);
		if ( pLockOn != (char *) 0)
			*((int*)pLockOn) = _Context->value_LockOn;
		visual_transferout((void *) 0, 0, pDropTool);
		if ( pDropTool != (char *) 0)
			*((int*)pDropTool) = _Context->value_DropTool;
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
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto553,_Context->y_Auto553);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto553,_Context->y_Auto553,370,410,vfh[2],_Context->msg_Auto553[_Context->language],strlen(_Context->msg_Auto553[_Context->language]),0x407);
	visual_image(_Context->x_Auto553+3,_Context->y_Auto553+24,363,382,_Context->msg_Auto1195[_Context->language],4);
	visual_text(_Context->x_Auto553+10,_Context->y_Auto553+30,350,20,vfh[3],27,0,_Context->msg_Auto573[_Context->language],strlen(_Context->msg_Auto573[_Context->language]),1282);
	visual_text(_Context->x_Auto553+20,_Context->y_Auto553+70,180,20,vfh[2],16,0,_Context->msg_Auto555[_Context->language],strlen(_Context->msg_Auto555[_Context->language]),258);
	visual_text(_Context->x_Auto553+20,_Context->y_Auto553+100,180,20,vfh[2],16,0,_Context->msg_Auto556[_Context->language],strlen(_Context->msg_Auto556[_Context->language]),258);
	visual_text(_Context->x_Auto553+20,_Context->y_Auto553+130,180,20,vfh[2],16,0,_Context->msg_Auto557[_Context->language],strlen(_Context->msg_Auto557[_Context->language]),258);
	visual_text(_Context->x_Auto553+20,_Context->y_Auto553+160,180,20,vfh[2],16,0,_Context->msg_Auto558[_Context->language],strlen(_Context->msg_Auto558[_Context->language]),258);
	visual_text(_Context->x_Auto553+20,_Context->y_Auto553+310,98,16,vfh[2],16,0,_Context->msg_Auto595[_Context->language],strlen(_Context->msg_Auto595[_Context->language]),258);
	visual_text(_Context->x_Auto553+20,_Context->y_Auto553+270,98,16,vfh[2],16,0,_Context->msg_Auto616[_Context->language],strlen(_Context->msg_Auto616[_Context->language]),258);
	_Context->trigger_AutoSave=visual_trigger_code(_Context->msg_AutoSave[_Context->language],strlen(_Context->msg_AutoSave[_Context->language]));
	visual_check(_Context->x_Auto553+240,_Context->y_Auto553+270,110,20,vfh[2],16,0,_Context->msg_AutoSave[_Context->language],strlen(_Context->msg_AutoSave[_Context->language]),_Context->value_AutoSave|0);
	visual_text(_Context->x_Auto553+20,_Context->y_Auto553+290,98,16,vfh[2],16,0,_Context->msg_Auto5571[_Context->language],strlen(_Context->msg_Auto5571[_Context->language]),258);
	visual_select(_Context->x_Auto553+200,_Context->y_Auto553+70,150,60,vfh[1],27,0,parse_selection(ProductionLanguageList,&_Context->value_ProductionLanguage),0);
	visual_select(_Context->x_Auto553+200,_Context->y_Auto553+100,150,30,vfh[1],27,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),0);
	visual_select(_Context->x_Auto553+200,_Context->y_Auto553+130,150,48,vfh[1],0,0,parse_selection(TextFontList,&_Context->value_TextFont),0);
	visual_select(_Context->x_Auto553+200,_Context->y_Auto553+160,150,56,vfh[1],0,0,parse_selection(WidgetAlignList,&_Context->value_Alignment),0);
	_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_Auto553+20,_Context->y_Auto553+200,98,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
	_Context->trigger_IsUnderline=visual_trigger_code(_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]));
	visual_check(_Context->x_Auto553+130,_Context->y_Auto553+200,112,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),_Context->value_IsUnderline|0);
	_Context->trigger_IsShadow=visual_trigger_code(_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]));
	visual_check(_Context->x_Auto553+240,_Context->y_Auto553+200,98,16,vfh[2],175,0,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),_Context->value_IsShadow|0);
	_Context->trigger_SnapOn=visual_trigger_code(_Context->msg_SnapOn[_Context->language],strlen(_Context->msg_SnapOn[_Context->language]));
	visual_check(_Context->x_Auto553+20,_Context->y_Auto553+230,98,16,vfh[2],27,0,_Context->msg_SnapOn[_Context->language],strlen(_Context->msg_SnapOn[_Context->language]),_Context->value_SnapOn|0);
	visual_frame(_Context->x_Auto553+130,_Context->y_Auto553+270,56+2,16+2,5);
	visual_text(_Context->x_Auto553+130+1,_Context->y_Auto553+270+1,56,16,vfh[1],0,0,_Context->buffer_GridWidth,7,0);
	visual_frame(_Context->x_Auto553+130,_Context->y_Auto553+290,56+2,16+2,5);
	visual_text(_Context->x_Auto553+130+1,_Context->y_Auto553+290+1,56,16,vfh[1],0,0,_Context->buffer_GridHeight,7,0);
	_Context->trigger_UseTextFont=visual_trigger_code(_Context->msg_UseTextFont[_Context->language],strlen(_Context->msg_UseTextFont[_Context->language]));
	visual_button(_Context->x_Auto553+140,_Context->y_Auto553+360,98,32,vfh[2],27,28,_Context->msg_UseTextFont[_Context->language],strlen(_Context->msg_UseTextFont[_Context->language]),0);
	visual_frame(_Context->x_Auto553+130,_Context->y_Auto553+310,56+2,16+2,5);
	visual_text(_Context->x_Auto553+130+1,_Context->y_Auto553+310+1,56,16,vfh[1],0,0,_Context->buffer_ThickNess,7,0);
	_Context->trigger_LockOn=visual_trigger_code(_Context->msg_LockOn[_Context->language],strlen(_Context->msg_LockOn[_Context->language]));
	visual_check(_Context->x_Auto553+130,_Context->y_Auto553+230,112,16,vfh[2],27,0,_Context->msg_LockOn[_Context->language],strlen(_Context->msg_LockOn[_Context->language]),_Context->value_LockOn|0);
	_Context->trigger_DropTool=visual_trigger_code(_Context->msg_DropTool[_Context->language],strlen(_Context->msg_DropTool[_Context->language]));
	visual_check(_Context->x_Auto553+240,_Context->y_Auto553+300,112,16,vfh[2],27,0,_Context->msg_DropTool[_Context->language],strlen(_Context->msg_DropTool[_Context->language]),_Context->value_DropTool|0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto553+20,_Context->y_Auto553+360,98,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Auto3413=visual_trigger_code(_Context->msg_Auto3413[_Context->language],strlen(_Context->msg_Auto3413[_Context->language]));
	visual_button(_Context->x_Auto553+260,_Context->y_Auto553+360,98,32,vfh[2],27,0,_Context->msg_Auto3413[_Context->language],strlen(_Context->msg_Auto3413[_Context->language]),0);
	visual_thaw(_Context->x_Auto553,_Context->y_Auto553,370,410);
	visual_thaw(_Context->x_Auto553,_Context->y_Auto553,370,410);

	return(0);
}

private int Auto553action(struct accept_general_options_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_general_options_hide(_Context);

		_Context->x_Auto553 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto553 < 0) { _Context->x_Auto553=0; }
		_Context->y_Auto553 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto553 < 0) { _Context->y_Auto553=0; }
			accept_general_options_show(_Context);

		visual_thaw(_Context->x_Auto553,_Context->y_Auto553,370,410);
		}
	while (visual_event(1) != _MIMO_UP);
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
private int on_Accept_event(struct accept_general_options_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto3413_event(struct accept_general_options_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_general_options_event(
struct accept_general_options_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_AutoSave == mb ) return(2);
		if (_Context->trigger_IsBold == mb ) return(7);
		if (_Context->trigger_IsUnderline == mb ) return(8);
		if (_Context->trigger_IsShadow == mb ) return(9);
		if (_Context->trigger_SnapOn == mb ) return(10);
		if (_Context->trigger_UseTextFont == mb ) return(13);
		if (_Context->trigger_LockOn == mb ) return(15);
		if (_Context->trigger_DropTool == mb ) return(16);
		if (_Context->trigger_Accept == mb ) return(17);
		if (_Context->trigger_Auto3413 == mb ) return(18);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto553+349) )  
	&&  (my >= (_Context->y_Auto553+4) )  
	&&  (mx <= (_Context->x_Auto553+366) )  
	&&  (my <= (_Context->y_Auto553+20) )) {
		return(1);	/* Auto553 */

		}
	if ((mx >= (_Context->x_Auto553+333) )  
	&&  (my >= (_Context->y_Auto553+4) )  
	&&  (mx <= (_Context->x_Auto553+350) )  
	&&  (my <= (_Context->y_Auto553+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vparam.htm");
			};
		return(-1);	/* Auto553 */

		}
	if ((mx >= (_Context->x_Auto553+317) )  
	&&  (my >= (_Context->y_Auto553+4) )  
	&&  (mx <= (_Context->x_Auto553+334) )  
	&&  (my <= (_Context->y_Auto553+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_general_options_show(_Context);
		return(-1);	/* Auto553 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto553+4) )  
		&&  (my >= (_Context->y_Auto553+4) )  
		&&  (mx <= (_Context->x_Auto553+302) )  
		&&  (my <= (_Context->y_Auto553+20) )) {
			return( Auto553action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto553+240) ) 
	&&  ( my >= (_Context->y_Auto553+270) ) 
	&&  ( mx <= (_Context->x_Auto553+240+110) ) 
	&&  ( my <= (_Context->y_Auto553+270+20))) {
		return(2); /* AutoSave */
		}
	if (( mx >= (_Context->x_Auto553+200+0) ) 
	&&  ( my >= (_Context->y_Auto553+70) ) 
	&&  ( mx <= (_Context->x_Auto553+200+150) ) 
	&&  ( my <= (_Context->y_Auto553+70+16))) {
		return(3); /* ProductionLanguage */
		}
	if (( mx >= (_Context->x_Auto553+200+0) ) 
	&&  ( my >= (_Context->y_Auto553+100) ) 
	&&  ( mx <= (_Context->x_Auto553+200+150) ) 
	&&  ( my <= (_Context->y_Auto553+100+16))) {
		return(4); /* ImageFormat */
		}
	if (( mx >= (_Context->x_Auto553+200+0) ) 
	&&  ( my >= (_Context->y_Auto553+130) ) 
	&&  ( mx <= (_Context->x_Auto553+200+150) ) 
	&&  ( my <= (_Context->y_Auto553+130+16))) {
		return(5); /* TextFont */
		}
	if (( mx >= (_Context->x_Auto553+200+0) ) 
	&&  ( my >= (_Context->y_Auto553+160) ) 
	&&  ( mx <= (_Context->x_Auto553+200+150) ) 
	&&  ( my <= (_Context->y_Auto553+160+16))) {
		return(6); /* Alignment */
		}
	if (( mx >= (_Context->x_Auto553+20) ) 
	&&  ( my >= (_Context->y_Auto553+200) ) 
	&&  ( mx <= (_Context->x_Auto553+20+98) ) 
	&&  ( my <= (_Context->y_Auto553+200+16))) {
		return(7); /* IsBold */
		}
	if (( mx >= (_Context->x_Auto553+130) ) 
	&&  ( my >= (_Context->y_Auto553+200) ) 
	&&  ( mx <= (_Context->x_Auto553+130+112) ) 
	&&  ( my <= (_Context->y_Auto553+200+16))) {
		return(8); /* IsUnderline */
		}
	if (( mx >= (_Context->x_Auto553+240) ) 
	&&  ( my >= (_Context->y_Auto553+200) ) 
	&&  ( mx <= (_Context->x_Auto553+240+98) ) 
	&&  ( my <= (_Context->y_Auto553+200+16))) {
		return(9); /* IsShadow */
		}
	if (( mx >= (_Context->x_Auto553+20) ) 
	&&  ( my >= (_Context->y_Auto553+230) ) 
	&&  ( mx <= (_Context->x_Auto553+20+98) ) 
	&&  ( my <= (_Context->y_Auto553+230+16))) {
		return(10); /* SnapOn */
		}
	if (( mx >= (_Context->x_Auto553+130) ) 
	&&  ( my >= (_Context->y_Auto553+270) ) 
	&&  ( mx <= (_Context->x_Auto553+130+56) ) 
	&&  ( my <= (_Context->y_Auto553+270+16))) {
		return(11); /* GridWidth */
		}
	if (( mx >= (_Context->x_Auto553+130) ) 
	&&  ( my >= (_Context->y_Auto553+290) ) 
	&&  ( mx <= (_Context->x_Auto553+130+56) ) 
	&&  ( my <= (_Context->y_Auto553+290+16))) {
		return(12); /* GridHeight */
		}
	if (( mx >= (_Context->x_Auto553+140) ) 
	&&  ( my >= (_Context->y_Auto553+360) ) 
	&&  ( mx <= (_Context->x_Auto553+140+98) ) 
	&&  ( my <= (_Context->y_Auto553+360+32))) {
		return(13); /* UseTextFont */
		}
	if (( mx >= (_Context->x_Auto553+130) ) 
	&&  ( my >= (_Context->y_Auto553+310) ) 
	&&  ( mx <= (_Context->x_Auto553+130+56) ) 
	&&  ( my <= (_Context->y_Auto553+310+16))) {
		return(14); /* ThickNess */
		}
	if (( mx >= (_Context->x_Auto553+130) ) 
	&&  ( my >= (_Context->y_Auto553+230) ) 
	&&  ( mx <= (_Context->x_Auto553+130+112) ) 
	&&  ( my <= (_Context->y_Auto553+230+16))) {
		return(15); /* LockOn */
		}
	if (( mx >= (_Context->x_Auto553+240) ) 
	&&  ( my >= (_Context->y_Auto553+300) ) 
	&&  ( mx <= (_Context->x_Auto553+240+112) ) 
	&&  ( my <= (_Context->y_Auto553+300+16))) {
		return(16); /* DropTool */
		}
	if (( mx >= (_Context->x_Auto553+20) ) 
	&&  ( my >= (_Context->y_Auto553+360) ) 
	&&  ( mx <= (_Context->x_Auto553+20+98) ) 
	&&  ( my <= (_Context->y_Auto553+360+32))) {
		return(17); /* Accept */
		}
	if (( mx >= (_Context->x_Auto553+260) ) 
	&&  ( my >= (_Context->y_Auto553+360) ) 
	&&  ( mx <= (_Context->x_Auto553+260+98) ) 
	&&  ( my <= (_Context->y_Auto553+360+32))) {
		return(18); /* Auto3413 */
		}

	return(-1);
}


public	int	accept_general_options_focus(struct accept_general_options_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x3 :
				/* ProductionLanguage */
				_Context->keycode = visual_select(_Context->x_Auto553+200,_Context->y_Auto553+70,150,60,vfh[1],27,0,parse_selection(ProductionLanguageList,&_Context->value_ProductionLanguage),2);
				break;
			case	0x4 :
				/* ImageFormat */
				_Context->keycode = visual_select(_Context->x_Auto553+200,_Context->y_Auto553+100,150,30,vfh[1],27,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),2);
				break;
			case	0x5 :
				/* TextFont */
				_Context->keycode = visual_select(_Context->x_Auto553+200,_Context->y_Auto553+130,150,48,vfh[1],0,0,parse_selection(TextFontList,&_Context->value_TextFont),2);
				break;
			case	0x6 :
				/* Alignment */
				_Context->keycode = visual_select(_Context->x_Auto553+200,_Context->y_Auto553+160,150,56,vfh[1],0,0,parse_selection(WidgetAlignList,&_Context->value_Alignment),2);
				break;
			case	0x7 :
				/* IsBold */
				visual_check(_Context->x_Auto553+20,_Context->y_Auto553+200,98,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),(_Context->value_IsBold |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto553+20,_Context->y_Auto553+200,98,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),(_Context->value_IsBold |0));
				break;
			case	0x8 :
				/* IsUnderline */
				visual_check(_Context->x_Auto553+130,_Context->y_Auto553+200,112,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),(_Context->value_IsUnderline |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto553+130,_Context->y_Auto553+200,112,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),(_Context->value_IsUnderline |0));
				break;
			case	0x9 :
				/* IsShadow */
				visual_check(_Context->x_Auto553+240,_Context->y_Auto553+200,98,16,vfh[2],175,0,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),(_Context->value_IsShadow |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto553+240,_Context->y_Auto553+200,98,16,vfh[2],175,0,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),(_Context->value_IsShadow |0));
				break;
			case	0xa :
				/* SnapOn */
				visual_check(_Context->x_Auto553+20,_Context->y_Auto553+230,98,16,vfh[2],27,0,_Context->msg_SnapOn[_Context->language],strlen(_Context->msg_SnapOn[_Context->language]),(_Context->value_SnapOn |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto553+20,_Context->y_Auto553+230,98,16,vfh[2],27,0,_Context->msg_SnapOn[_Context->language],strlen(_Context->msg_SnapOn[_Context->language]),(_Context->value_SnapOn |0));
				break;
			case	0xb :
				/* GridWidth */
				_Context->keycode = visual_edit(_Context->x_Auto553+130+1,_Context->y_Auto553+270+1,56,16,vfh[1],_Context->buffer_GridWidth,7);
			break;
			case	0xc :
				/* GridHeight */
				_Context->keycode = visual_edit(_Context->x_Auto553+130+1,_Context->y_Auto553+290+1,56,16,vfh[1],_Context->buffer_GridHeight,7);
			break;
			case	0xd :
				/* UseTextFont */
				visual_button(_Context->x_Auto553+140,_Context->y_Auto553+360,98,32,vfh[2],27,28,_Context->msg_UseTextFont[_Context->language],strlen(_Context->msg_UseTextFont[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto553+140,_Context->y_Auto553+360,98,32,vfh[2],27,28,_Context->msg_UseTextFont[_Context->language],strlen(_Context->msg_UseTextFont[_Context->language]),0);
				break;
			case	0xe :
				/* ThickNess */
				_Context->keycode = visual_edit(_Context->x_Auto553+130+1,_Context->y_Auto553+310+1,56,16,vfh[1],_Context->buffer_ThickNess,7);
			break;
			case	0xf :
				/* LockOn */
				visual_check(_Context->x_Auto553+130,_Context->y_Auto553+230,112,16,vfh[2],27,0,_Context->msg_LockOn[_Context->language],strlen(_Context->msg_LockOn[_Context->language]),(_Context->value_LockOn |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto553+130,_Context->y_Auto553+230,112,16,vfh[2],27,0,_Context->msg_LockOn[_Context->language],strlen(_Context->msg_LockOn[_Context->language]),(_Context->value_LockOn |0));
				break;
			case	0x10 :
				/* DropTool */
				visual_check(_Context->x_Auto553+240,_Context->y_Auto553+300,112,16,vfh[2],27,0,_Context->msg_DropTool[_Context->language],strlen(_Context->msg_DropTool[_Context->language]),(_Context->value_DropTool |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto553+240,_Context->y_Auto553+300,112,16,vfh[2],27,0,_Context->msg_DropTool[_Context->language],strlen(_Context->msg_DropTool[_Context->language]),(_Context->value_DropTool |0));
				break;
			case	0x11 :
				/* Accept */
				visual_button(_Context->x_Auto553+20,_Context->y_Auto553+360,98,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto553+20,_Context->y_Auto553+360,98,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x12 :
				/* Auto3413 */
				visual_button(_Context->x_Auto553+260,_Context->y_Auto553+360,98,32,vfh[2],27,0,_Context->msg_Auto3413[_Context->language],strlen(_Context->msg_Auto3413[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto553+260,_Context->y_Auto553+360,98,32,vfh[2],27,0,_Context->msg_Auto3413[_Context->language],strlen(_Context->msg_Auto3413[_Context->language]),0);
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
			_Context->focus_item=18;
			accept_general_options_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_general_options_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto553 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* AutoSave */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_AutoSave += 1;
							_Context->value_AutoSave &= 1;
				visual_check(_Context->x_Auto553+240,_Context->y_Auto553+270,110,20,vfh[2],16,0,_Context->msg_AutoSave[_Context->language],strlen(_Context->msg_AutoSave[_Context->language]),(_Context->value_AutoSave |0));
							}
						continue;
					case	0x3 :
						/* ProductionLanguage */
						continue;
					case	0x4 :
						/* ImageFormat */
						continue;
					case	0x5 :
						/* TextFont */
						continue;
					case	0x6 :
						/* Alignment */
						continue;
					case	0x7 :
						/* IsBold */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsBold += 1;
							_Context->value_IsBold &= 1;
							}
						continue;
					case	0x8 :
						/* IsUnderline */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsUnderline += 1;
							_Context->value_IsUnderline &= 1;
							}
						continue;
					case	0x9 :
						/* IsShadow */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsShadow += 1;
							_Context->value_IsShadow &= 1;
							}
						continue;
					case	0xa :
						/* SnapOn */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SnapOn += 1;
							_Context->value_SnapOn &= 1;
							}
						continue;
					case	0xb :
						/* GridWidth */
						continue;
					case	0xc :
						/* GridHeight */
						continue;
					case	0xd :
						/* UseTextFont */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto553+140,_Context->y_Auto553+360,98,32,vfh[2],27,28,_Context->msg_UseTextFont[_Context->language],strlen(_Context->msg_UseTextFont[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto553+140,_Context->y_Auto553+360,98,32,vfh[2],27,28,_Context->msg_UseTextFont[_Context->language],strlen(_Context->msg_UseTextFont[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_UseTextFont_event(_Context)) != -1) break;

							}
						continue;
					case	0xe :
						/* ThickNess */
						continue;
					case	0xf :
						/* LockOn */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_LockOn += 1;
							_Context->value_LockOn &= 1;
							}
						continue;
					case	0x10 :
						/* DropTool */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_DropTool += 1;
							_Context->value_DropTool &= 1;
							}
						continue;
					case	0x11 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto553+20,_Context->y_Auto553+360,98,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto553+20,_Context->y_Auto553+360,98,32,vfh[2],27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0x12 :
						/* Auto3413 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto553+260,_Context->y_Auto553+360,98,32,vfh[2],27,0,_Context->msg_Auto3413[_Context->language],strlen(_Context->msg_Auto3413[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto553+260,_Context->y_Auto553+360,98,32,vfh[2],27,0,_Context->msg_Auto3413[_Context->language],strlen(_Context->msg_Auto3413[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto3413_event(_Context)) != -1) break;

							}
						continue;
					case	0xffffffff :
					default :
						_Context->focus_item=1;
					continue;
					}
				break;
			case	0x1b :
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
				_Context->focus_item=18;
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
	char * pAutoSave,
	char * pProductionLanguage,
	char * pImageFormat,
	char * pTextFont,
	char * pAlignment,
	char * pIsBold,
	char * pIsUnderline,
	char * pIsShadow,
	char * pSnapOn,
	char * pGridWidth,
	char * pGridHeight,
	char * pThickNess,
	char * pLockOn,
	char * pDropTool)
{
	int	status=0;
	struct accept_general_options_context * _Context=(struct accept_general_options_context*) 0;
	status = accept_general_options_create(
	&_Context,
	 pAutoSave,
	 pProductionLanguage,
	 pImageFormat,
	 pTextFont,
	 pAlignment,
	 pIsBold,
	 pIsUnderline,
	 pIsShadow,
	 pSnapOn,
	 pGridWidth,
	 pGridHeight,
	 pThickNess,
	 pLockOn,
	 pDropTool);
	if ( status != 0) return(status);
	status = accept_general_options_show(_Context);
		enter_modal();
	status = accept_general_options_focus(_Context);
		leave_modal();
	status = accept_general_options_hide(_Context);
	status = accept_general_options_remove(
	_Context,
	 pAutoSave,
	 pProductionLanguage,
	 pImageFormat,
	 pTextFont,
	 pAlignment,
	 pIsBold,
	 pIsUnderline,
	 pIsShadow,
	 pSnapOn,
	 pGridWidth,
	 pGridHeight,
	 pThickNess,
	 pLockOn,
	 pDropTool);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vparam_c */
