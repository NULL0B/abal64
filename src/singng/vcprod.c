
#ifndef _vcprod_c
#define _vcprod_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vcprod.xml                                               */
/* Target         : vcprod.c                                                 */
/* Identification : 0.0-1177511934-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#include "singlang.h"
#define en__auto2   ""
#define fr__auto2   ""
#define it__auto2   ""
#define es__auto2   ""
#define de__auto2   ""
#define nl__auto2   ""
#define pt__auto2   ""
#define xx__auto2   ""
#define en_auto7   "C Production Filename"
#define fr_auto7   "Nom du fichier cible C"
#define it_auto7   "C Production Filename"
#define es_auto7   "C Production Filename"
#define de_auto7   "C Production Filename"
#define nl_auto7   "C Production Filename"
#define pt_auto7   "C Production Filename"
#define xx_auto7   "C Production Filename"
#define en__auto7   ""
#define fr__auto7   ""
#define it__auto7   ""
#define es__auto7   ""
#define de__auto7   ""
#define nl__auto7   ""
#define pt__auto7   ""
#define xx__auto7   ""
#define en_FileName   ""
#define en_choixFileName   ".."
#define fr_choixFileName   ".."
#define it_choixFileName   ".."
#define es_choixFileName   ".."
#define de_choixFileName   ".."
#define nl_choixFileName   ".."
#define pt_choixFileName   ".."
#define xx_choixFileName   ".."
#define en__choixFileName   ""
#define en_auto52   "Identifier"
#define fr_auto52   "Identifiant"
#define it_auto52   "Identifier"
#define es_auto52   "Identifier"
#define de_auto52   "Identifier"
#define nl_auto52   "Identifier"
#define pt_auto52   "Identifier"
#define xx_auto52   "Identifier"
#define en__auto52   ""
#define fr__auto52   ""
#define it__auto52   ""
#define es__auto52   ""
#define de__auto52   ""
#define nl__auto52   ""
#define pt__auto52   ""
#define xx__auto52   ""
#define en_Identifier   ""
#define en_IsProgram   "&Program with Main"
#define fr_IsProgram   "&Programme avec Main"
#define it_IsProgram   "&Program with Main"
#define es_IsProgram   "&Program with Main"
#define de_IsProgram   "&Program with Main"
#define nl_IsProgram   "&Program with Main"
#define pt_IsProgram   "&Program with Main"
#define xx_IsProgram   "&Program with Main"
#define en__IsProgram   ""
#define fr__IsProgram   ""
#define it__IsProgram   ""
#define es__IsProgram   ""
#define de__IsProgram   ""
#define nl__IsProgram   ""
#define pt__IsProgram   ""
#define xx__IsProgram   ""
#define en_IsOverlay   "&Visual Interface"
#define fr_IsOverlay   "Interface &Visual"
#define it_IsOverlay   "&Visual Interface"
#define es_IsOverlay   "&Visual Interface"
#define de_IsOverlay   "&Visual Interface"
#define nl_IsOverlay   "&Visual Interface"
#define pt_IsOverlay   "&Visual Interface"
#define xx_IsOverlay   "&Visual Interface"
#define en__IsOverlay   ""
#define fr__IsOverlay   ""
#define it__IsOverlay   ""
#define es__IsOverlay   ""
#define de__IsOverlay   ""
#define nl__IsOverlay   ""
#define pt__IsOverlay   ""
#define xx__IsOverlay   ""
#define en_IsTrueColour   "&TrueColour"
#define fr_IsTrueColour   "&TrueColour"
#define it_IsTrueColour   "&TrueColour"
#define es_IsTrueColour   "&TrueColour"
#define de_IsTrueColour   "&TrueColour"
#define nl_IsTrueColour   "&TrueColour"
#define pt_IsTrueColour   "&TrueColour"
#define xx_IsTrueColour   "&TrueColour"
#define en__IsTrueColour   ""
#define fr__IsTrueColour   ""
#define it__IsTrueColour   ""
#define es__IsTrueColour   ""
#define de__IsTrueColour   ""
#define nl__IsTrueColour   ""
#define pt__IsTrueColour   ""
#define xx__IsTrueColour   ""
#define en_Auto2714   "ok.gif"
#define fr_Auto2714   "ok.gif"
#define it_Auto2714   "ok.gif"
#define es_Auto2714   "ok.gif"
#define de_Auto2714   "ok.gif"
#define nl_Auto2714   "ok.gif"
#define pt_Auto2714   "ok.gif"
#define xx_Auto2714   "ok.gif"
#define en_Auto2715   "cancel.gif"
#define fr_Auto2715   "cancel.gif"
#define it_Auto2715   "cancel.gif"
#define es_Auto2715   "cancel.gif"
#define de_Auto2715   "cancel.gif"
#define nl_Auto2715   "cancel.gif"
#define pt_Auto2715   "cancel.gif"
#define xx_Auto2715   "cancel.gif"
#define en_auto641   "Inclusions"
#define fr_auto641   "Inclusions"
#define it_auto641   "Inclusions"
#define es_auto641   "Inclusions"
#define de_auto641   "Inclusions"
#define nl_auto641   "Inclusions"
#define pt_auto641   "Inclusions"
#define xx_auto641   "Inclusions"
#define en__auto641   ""
#define fr__auto641   ""
#define it__auto641   ""
#define es__auto641   ""
#define de__auto641   ""
#define nl__auto641   ""
#define pt__auto641   ""
#define xx__auto641   ""
#define en_Inclusions   ""
#define en_Dimensions   "320x200|640x400|640x480|800x600|1024x786|1280x1024"
#define fr_Dimensions   "320x200|640x400|640x480|800x600|1024x786|1280x1024"
#define en_Edit   "cicon.gif"
#define fr_Edit   "cicon.gif"
#define it_Edit   "cicon.gif"
#define es_Edit   "cicon.gif"
#define de_Edit   "cicon.gif"
#define nl_Edit   "cicon.gif"
#define pt_Edit   "cicon.gif"
#define xx_Edit   "cicon.gif"
#define en__Edit   ""
#define en_Select   "&Select"
#define fr_Select   "&S‚lection"
#define it_Select   "&Select"
#define es_Select   "&Select"
#define de_Select   "&Select"
#define nl_Select   "&Select"
#define pt_Select   "&Select"
#define xx_Select   "&Select"
#define en__Select   ""
#define fr__Select   ""
#define it__Select   ""
#define es__Select   ""
#define de__Select   ""
#define nl__Select   ""
#define pt__Select   ""
#define xx__Select   ""

private struct accept_c_production_context {
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
	char * hint_Auto2713[8];
	char * msg_auto7[8];
	char * hint_auto7[8];
	char * hint_FileName[8];
	char	buffer_FileName[256];
	char * msg_choixFileName[8];
	int	trigger_choixFileName;
	char * hint_choixFileName[8];
	char * msg_auto52[8];
	char * hint_auto52[8];
	char * hint_Identifier[8];
	char	buffer_Identifier[256];
	char * msg_IsProgram[8];
	int	trigger_IsProgram;
	char * hint_IsProgram[8];
	int	value_IsProgram;
	char * msg_IsOverlay[8];
	int	trigger_IsOverlay;
	char * hint_IsOverlay[8];
	int	value_IsOverlay;
	char * msg_IsTrueColour[8];
	int	trigger_IsTrueColour;
	char * hint_IsTrueColour[8];
	int	value_IsTrueColour;
	char * msg_Auto2714[8];
	int	trigger_Auto2714;
	char * hint_Auto2714[8];
	char * msg_Auto2715[8];
	int	trigger_Auto2715;
	char * hint_Auto2715[8];
	char * msg_auto641[8];
	char * hint_auto641[8];
	char * hint_Inclusions[8];
	char	buffer_Inclusions[256];
	char * msg_Dimensions[8];
	char * hint_Dimensions[8];
	int	value_Dimensions;
	char * msg_Edit[8];
	int	trigger_Edit;
	char * hint_Edit[8];
	char * msg_Select[8];
	int	trigger_Select;
	char * hint_Select[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[8];
	};
static int	vfh[16];

public	int	accept_c_production_create(
	struct accept_c_production_context ** cptr,
	char * pFileName,
	char * pIdentifier,
	char * pIsProgram,
	char * pIsOverlay,
	char * pIsTrueColour,
	char * pInclusions,
	char * pDimensions)
{

	int i;
	struct accept_c_production_context * _Context=(struct accept_c_production_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_c_production_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=16;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWSW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 255, pFileName);
		visual_transferin(_Context->buffer_Identifier, 255, pIdentifier);
		visual_transferin((void *) 0, 0, pIsProgram);
		if (!( pIsProgram )) _Context->value_IsProgram=0;
		else	_Context->value_IsProgram = *((int *)pIsProgram);
		visual_transferin((void *) 0, 0, pIsOverlay);
		if (!( pIsOverlay )) _Context->value_IsOverlay=0;
		else	_Context->value_IsOverlay = *((int *)pIsOverlay);
		visual_transferin((void *) 0, 0, pIsTrueColour);
		if (!( pIsTrueColour )) _Context->value_IsTrueColour=0;
		else	_Context->value_IsTrueColour = *((int *)pIsTrueColour);
		visual_transferin(_Context->buffer_Inclusions, 255, pInclusions);
		visual_transferin((void *) 0, 0, pDimensions);
		if (!( pDimensions )) _Context->value_Dimensions=0;
		else	_Context->value_Dimensions = *((int *)pDimensions);
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
	_Context->x_auto2=100;
	_Context->y_auto2=135;
	_Context->w_auto2=600;
	_Context->h_auto2=330;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_auto7[i]=" ";
	_Context->msg_auto7[0]=en_auto7;
	_Context->msg_auto7[1]=fr_auto7;
	_Context->msg_auto7[2]=it_auto7;
	_Context->msg_auto7[3]=es_auto7;
	_Context->msg_auto7[4]=de_auto7;
	_Context->msg_auto7[5]=nl_auto7;
	_Context->msg_auto7[6]=pt_auto7;
	_Context->msg_auto7[7]=xx_auto7;
	_Context->hint_auto7[0]=en__auto7;
	_Context->hint_auto7[1]=fr__auto7;
	_Context->hint_auto7[2]=it__auto7;
	_Context->hint_auto7[3]=es__auto7;
	_Context->hint_auto7[4]=de__auto7;
	_Context->hint_auto7[5]=nl__auto7;
	_Context->hint_auto7[6]=pt__auto7;
	_Context->hint_auto7[7]=xx__auto7;
	for (i=0; i < 8; i++)_Context->msg_choixFileName[i]=" ";
	_Context->msg_choixFileName[0]=en_choixFileName;
	_Context->msg_choixFileName[1]=fr_choixFileName;
	_Context->msg_choixFileName[2]=it_choixFileName;
	_Context->msg_choixFileName[3]=es_choixFileName;
	_Context->msg_choixFileName[4]=de_choixFileName;
	_Context->msg_choixFileName[5]=nl_choixFileName;
	_Context->msg_choixFileName[6]=pt_choixFileName;
	_Context->msg_choixFileName[7]=xx_choixFileName;
	_Context->hint_choixFileName[0]=en__choixFileName;
	for (i=0; i < 8; i++)_Context->msg_auto52[i]=" ";
	_Context->msg_auto52[0]=en_auto52;
	_Context->msg_auto52[1]=fr_auto52;
	_Context->msg_auto52[2]=it_auto52;
	_Context->msg_auto52[3]=es_auto52;
	_Context->msg_auto52[4]=de_auto52;
	_Context->msg_auto52[5]=nl_auto52;
	_Context->msg_auto52[6]=pt_auto52;
	_Context->msg_auto52[7]=xx_auto52;
	_Context->hint_auto52[0]=en__auto52;
	_Context->hint_auto52[1]=fr__auto52;
	_Context->hint_auto52[2]=it__auto52;
	_Context->hint_auto52[3]=es__auto52;
	_Context->hint_auto52[4]=de__auto52;
	_Context->hint_auto52[5]=nl__auto52;
	_Context->hint_auto52[6]=pt__auto52;
	_Context->hint_auto52[7]=xx__auto52;
	for (i=0; i < 8; i++)_Context->msg_IsProgram[i]=" ";
	_Context->msg_IsProgram[0]=en_IsProgram;
	_Context->msg_IsProgram[1]=fr_IsProgram;
	_Context->msg_IsProgram[2]=it_IsProgram;
	_Context->msg_IsProgram[3]=es_IsProgram;
	_Context->msg_IsProgram[4]=de_IsProgram;
	_Context->msg_IsProgram[5]=nl_IsProgram;
	_Context->msg_IsProgram[6]=pt_IsProgram;
	_Context->msg_IsProgram[7]=xx_IsProgram;
	_Context->hint_IsProgram[0]=en__IsProgram;
	_Context->hint_IsProgram[1]=fr__IsProgram;
	_Context->hint_IsProgram[2]=it__IsProgram;
	_Context->hint_IsProgram[3]=es__IsProgram;
	_Context->hint_IsProgram[4]=de__IsProgram;
	_Context->hint_IsProgram[5]=nl__IsProgram;
	_Context->hint_IsProgram[6]=pt__IsProgram;
	_Context->hint_IsProgram[7]=xx__IsProgram;
	for (i=0; i < 8; i++)_Context->msg_IsOverlay[i]=" ";
	_Context->msg_IsOverlay[0]=en_IsOverlay;
	_Context->msg_IsOverlay[1]=fr_IsOverlay;
	_Context->msg_IsOverlay[2]=it_IsOverlay;
	_Context->msg_IsOverlay[3]=es_IsOverlay;
	_Context->msg_IsOverlay[4]=de_IsOverlay;
	_Context->msg_IsOverlay[5]=nl_IsOverlay;
	_Context->msg_IsOverlay[6]=pt_IsOverlay;
	_Context->msg_IsOverlay[7]=xx_IsOverlay;
	_Context->hint_IsOverlay[0]=en__IsOverlay;
	_Context->hint_IsOverlay[1]=fr__IsOverlay;
	_Context->hint_IsOverlay[2]=it__IsOverlay;
	_Context->hint_IsOverlay[3]=es__IsOverlay;
	_Context->hint_IsOverlay[4]=de__IsOverlay;
	_Context->hint_IsOverlay[5]=nl__IsOverlay;
	_Context->hint_IsOverlay[6]=pt__IsOverlay;
	_Context->hint_IsOverlay[7]=xx__IsOverlay;
	for (i=0; i < 8; i++)_Context->msg_IsTrueColour[i]=" ";
	_Context->msg_IsTrueColour[0]=en_IsTrueColour;
	_Context->msg_IsTrueColour[1]=fr_IsTrueColour;
	_Context->msg_IsTrueColour[2]=it_IsTrueColour;
	_Context->msg_IsTrueColour[3]=es_IsTrueColour;
	_Context->msg_IsTrueColour[4]=de_IsTrueColour;
	_Context->msg_IsTrueColour[5]=nl_IsTrueColour;
	_Context->msg_IsTrueColour[6]=pt_IsTrueColour;
	_Context->msg_IsTrueColour[7]=xx_IsTrueColour;
	_Context->hint_IsTrueColour[0]=en__IsTrueColour;
	_Context->hint_IsTrueColour[1]=fr__IsTrueColour;
	_Context->hint_IsTrueColour[2]=it__IsTrueColour;
	_Context->hint_IsTrueColour[3]=es__IsTrueColour;
	_Context->hint_IsTrueColour[4]=de__IsTrueColour;
	_Context->hint_IsTrueColour[5]=nl__IsTrueColour;
	_Context->hint_IsTrueColour[6]=pt__IsTrueColour;
	_Context->hint_IsTrueColour[7]=xx__IsTrueColour;
	for (i=0; i < 8; i++)_Context->msg_Auto2714[i]=" ";
	_Context->msg_Auto2714[0]=en_Auto2714;
	_Context->msg_Auto2714[1]=fr_Auto2714;
	_Context->msg_Auto2714[2]=it_Auto2714;
	_Context->msg_Auto2714[3]=es_Auto2714;
	_Context->msg_Auto2714[4]=de_Auto2714;
	_Context->msg_Auto2714[5]=nl_Auto2714;
	_Context->msg_Auto2714[6]=pt_Auto2714;
	_Context->msg_Auto2714[7]=xx_Auto2714;
	for (i=0; i < 8; i++)_Context->msg_Auto2715[i]=" ";
	_Context->msg_Auto2715[0]=en_Auto2715;
	_Context->msg_Auto2715[1]=fr_Auto2715;
	_Context->msg_Auto2715[2]=it_Auto2715;
	_Context->msg_Auto2715[3]=es_Auto2715;
	_Context->msg_Auto2715[4]=de_Auto2715;
	_Context->msg_Auto2715[5]=nl_Auto2715;
	_Context->msg_Auto2715[6]=pt_Auto2715;
	_Context->msg_Auto2715[7]=xx_Auto2715;
	for (i=0; i < 8; i++)_Context->msg_auto641[i]=" ";
	_Context->msg_auto641[0]=en_auto641;
	_Context->msg_auto641[1]=fr_auto641;
	_Context->msg_auto641[2]=it_auto641;
	_Context->msg_auto641[3]=es_auto641;
	_Context->msg_auto641[4]=de_auto641;
	_Context->msg_auto641[5]=nl_auto641;
	_Context->msg_auto641[6]=pt_auto641;
	_Context->msg_auto641[7]=xx_auto641;
	_Context->hint_auto641[0]=en__auto641;
	_Context->hint_auto641[1]=fr__auto641;
	_Context->hint_auto641[2]=it__auto641;
	_Context->hint_auto641[3]=es__auto641;
	_Context->hint_auto641[4]=de__auto641;
	_Context->hint_auto641[5]=nl__auto641;
	_Context->hint_auto641[6]=pt__auto641;
	_Context->hint_auto641[7]=xx__auto641;
	for (i=0; i < 8; i++)_Context->msg_Dimensions[i]=" ";
	_Context->msg_Dimensions[0]=en_Dimensions;
	_Context->msg_Dimensions[1]=fr_Dimensions;
	for (i=0; i < 8; i++)_Context->msg_Edit[i]=" ";
	_Context->msg_Edit[0]=en_Edit;
	_Context->msg_Edit[1]=fr_Edit;
	_Context->msg_Edit[2]=it_Edit;
	_Context->msg_Edit[3]=es_Edit;
	_Context->msg_Edit[4]=de_Edit;
	_Context->msg_Edit[5]=nl_Edit;
	_Context->msg_Edit[6]=pt_Edit;
	_Context->msg_Edit[7]=xx_Edit;
	_Context->hint_Edit[0]=en__Edit;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	_Context->msg_Select[2]=it_Select;
	_Context->msg_Select[3]=es_Select;
	_Context->msg_Select[4]=de_Select;
	_Context->msg_Select[5]=nl_Select;
	_Context->msg_Select[6]=pt_Select;
	_Context->msg_Select[7]=xx_Select;
	_Context->hint_Select[0]=en__Select;
	_Context->hint_Select[1]=fr__Select;
	_Context->hint_Select[2]=it__Select;
	_Context->hint_Select[3]=es__Select;
	_Context->hint_Select[4]=de__Select;
	_Context->hint_Select[5]=nl__Select;
	_Context->hint_Select[6]=pt__Select;
	_Context->hint_Select[7]=xx__Select;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto2,_Context->y_auto2,600+10,330+10);
	return(0);
}

public 	int	accept_c_production_hide(struct accept_c_production_context * _Context)
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

public	int	accept_c_production_remove(
	struct accept_c_production_context * _Context,
	char * pFileName,
	char * pIdentifier,
	char * pIsProgram,
	char * pIsOverlay,
	char * pIsTrueColour,
	char * pInclusions,
	char * pDimensions)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWSW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 255, pFileName);
		visual_transferout(_Context->buffer_Identifier, 255, pIdentifier);
		visual_transferout((void *) 0, 0, pIsProgram);
		if ( pIsProgram != (char *) 0)
			*((int*)pIsProgram) = _Context->value_IsProgram;
		visual_transferout((void *) 0, 0, pIsOverlay);
		if ( pIsOverlay != (char *) 0)
			*((int*)pIsOverlay) = _Context->value_IsOverlay;
		visual_transferout((void *) 0, 0, pIsTrueColour);
		if ( pIsTrueColour != (char *) 0)
			*((int*)pIsTrueColour) = _Context->value_IsTrueColour;
		visual_transferout(_Context->buffer_Inclusions, 255, pInclusions);
		visual_transferout((void *) 0, 0, pDimensions);
		if ( pDimensions != (char *) 0)
			*((int*)pDimensions) = _Context->value_Dimensions;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_c_production_show(struct accept_c_production_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto2,_Context->y_auto2);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_auto2,_Context->y_auto2,600,330,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_auto2,_Context->y_auto2,600,330,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_frame(_Context->x_auto2+21,_Context->y_auto2+226,560,25,2);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+40,560,16,vfh[2],27,0,_Context->msg_auto7[_Context->language],strlen(_Context->msg_auto7[_Context->language]),258);
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+60,536+2,16+2,5);
	visual_text(_Context->x_auto2+20+1,_Context->y_auto2+60+1,536,16,vfh[1],34,0,_Context->buffer_FileName,255,0);
	_Context->trigger_choixFileName=visual_trigger_code(_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]));
	visual_button(_Context->x_auto2+560,_Context->y_auto2+60,20,18,vfh[1],27,28,_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]),0);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+90,560,16,vfh[2],27,0,_Context->msg_auto52[_Context->language],strlen(_Context->msg_auto52[_Context->language]),258);
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+110,560+2,16+2,5);
	visual_text(_Context->x_auto2+20+1,_Context->y_auto2+110+1,560,16,vfh[1],34,0,_Context->buffer_Identifier,255,0);
	_Context->trigger_IsProgram=visual_trigger_code(_Context->msg_IsProgram[_Context->language],strlen(_Context->msg_IsProgram[_Context->language]));
	visual_check(_Context->x_auto2+30,_Context->y_auto2+230,182,16,vfh[2],34,0,_Context->msg_IsProgram[_Context->language],strlen(_Context->msg_IsProgram[_Context->language]),_Context->value_IsProgram|0);
	_Context->trigger_IsOverlay=visual_trigger_code(_Context->msg_IsOverlay[_Context->language],strlen(_Context->msg_IsOverlay[_Context->language]));
	visual_check(_Context->x_auto2+210,_Context->y_auto2+230,154,16,vfh[2],16,0,_Context->msg_IsOverlay[_Context->language],strlen(_Context->msg_IsOverlay[_Context->language]),_Context->value_IsOverlay|0);
	_Context->trigger_IsTrueColour=visual_trigger_code(_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]));
	visual_check(_Context->x_auto2+350,_Context->y_auto2+230,126,16,vfh[2],16,0,_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]),_Context->value_IsTrueColour|0);
	_Context->trigger_Auto2714=visual_trigger_code(_Context->msg_Auto2714[_Context->language],strlen(_Context->msg_Auto2714[_Context->language]));
	visual_button(_Context->x_auto2+20,_Context->y_auto2+270,42,48,vfh[2],34,0,_Context->msg_Auto2714[_Context->language],strlen(_Context->msg_Auto2714[_Context->language]),1040);
	_Context->trigger_Auto2715=visual_trigger_code(_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]));
	visual_button(_Context->x_auto2+540,_Context->y_auto2+270,42,48,vfh[2],34,0,_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]),1040);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+140,560,16,vfh[2],27,0,_Context->msg_auto641[_Context->language],strlen(_Context->msg_auto641[_Context->language]),258);
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+160,560+2,60+2,5);
	visual_text(_Context->x_auto2+20+1,_Context->y_auto2+160+1,560,60,vfh[1],26,0,_Context->buffer_Inclusions,255,0);
	visual_select(_Context->x_auto2+470,_Context->y_auto2+230,104,80,vfh[1],0,0,parse_selection(_Context->msg_Dimensions[_Context->language],&_Context->value_Dimensions),0);
	_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
	visual_button(_Context->x_auto2+290,_Context->y_auto2+270,42,48,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),272);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto2+360,_Context->y_auto2+270,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	visual_thaw(_Context->x_auto2,_Context->y_auto2,600,330);

	return(0);
}

private int FileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The C Target Filename edit field allows the full path and file name ";
			mptr[1]="   of the production target to be specified.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Identifier_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The IDENTIFIER edit field allows the class name for C++ production ";
			mptr[1]="or the function name for C generation to be specified.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsProgram_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "When the PROGRAM check box has been checked then C program startup ";
			mptr[1]="   code will be generated to the production target. Otherwise, when ";
			mptr[2]="      unchecked, only the forms related functions or class code wil ";
			mptr[3]="l be     generated.  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsOverlay_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Activation of this check control causes graphical initialisation code ";
			mptr[1]="to be generated to the production target.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsTrueColour_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This check control may be activated for the selection of the True ";
			mptr[1]="Colour operational mode for the underlying graphical mechanisms.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2714_help()
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

private int Auto2715_help()
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

private int Inclusions_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The INCLUSIONS edit field allows the list of files required to be ";
			mptr[1]="   included for the correct compilation of the production target. ";
			mptr[2]=" ";
			return(visual_online_help(mptr,3));
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
			char * mptr[3];
			mptr[0] = "By pressing the EDIT button the production target file will be made ";
			mptr[1]="   available for inspection via the Standard Abal Text Editor mecha ";
			mptr[2]="nism.  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Select_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The Select button allows access  to the file selection dialog frame ";
			mptr[1]="allowing prompted selection of the filename.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int auto2action(struct accept_c_production_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_c_production_hide(_Context);

		_Context->x_auto2 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto2 < 0) { _Context->x_auto2=0; }
		_Context->y_auto2 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto2 < 0) { _Context->y_auto2=0; }
			accept_c_production_show(_Context);

		visual_thaw(_Context->x_auto2,_Context->y_auto2,600,330);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_choixFileName_event(struct accept_c_production_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_C);
		accept_c_production_show(_Context);
;
	return(-1);
}
private int on_Auto2714_event(struct accept_c_production_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto2715_event(struct accept_c_production_context * _Context) {
	return(27);
	return(-1);
}
private int on_Edit_event(struct accept_c_production_context * _Context) {
		accept_c_production_hide(_Context);
;
	use_editor(_Context->buffer_FileName,_GENERATE_C);
		accept_c_production_show(_Context);
;
	return(-1);
}
private int on_Select_event(struct accept_c_production_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_C);
		accept_c_production_show(_Context);
;
	return(-1);
}


public	int	accept_c_production_event(
struct accept_c_production_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_choixFileName == mb ) return(4);
		if (_Context->trigger_IsProgram == mb ) return(7);
		if (_Context->trigger_IsOverlay == mb ) return(8);
		if (_Context->trigger_IsTrueColour == mb ) return(9);
		if (_Context->trigger_Auto2714 == mb ) return(10);
		if (_Context->trigger_Auto2715 == mb ) return(11);
		if (_Context->trigger_Edit == mb ) return(15);
		if (_Context->trigger_Select == mb ) return(16);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_auto2+579) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+596) )  
	&&  (my <= (_Context->y_auto2+20) )) {
		return(1);	/* auto2 */

		}
	if ((mx >= (_Context->x_auto2+563) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+580) )  
	&&  (my <= (_Context->y_auto2+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcprod.htm");
			};
		return(-1);	/* auto2 */

		}
	if ((mx >= (_Context->x_auto2+547) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+564) )  
	&&  (my <= (_Context->y_auto2+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_c_production_show(_Context);
		return(-1);	/* auto2 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_auto2+4) )  
		&&  (my >= (_Context->y_auto2+4) )  
		&&  (mx <= (_Context->x_auto2+532) )  
		&&  (my <= (_Context->y_auto2+20) )) {
			return( auto2action(_Context) );
			}
		}
	if (( mx >= (_Context->x_auto2+20) ) 
	&&  ( my >= (_Context->y_auto2+60) ) 
	&&  ( mx <= (_Context->x_auto2+20+536) ) 
	&&  ( my <= (_Context->y_auto2+60+16))) {
		return(3); /* FileName */
		}
	if (( mx >= (_Context->x_auto2+560) ) 
	&&  ( my >= (_Context->y_auto2+60) ) 
	&&  ( mx <= (_Context->x_auto2+560+20) ) 
	&&  ( my <= (_Context->y_auto2+60+18))) {
		return(4); /* choixFileName */
		}
	if (( mx >= (_Context->x_auto2+20) ) 
	&&  ( my >= (_Context->y_auto2+110) ) 
	&&  ( mx <= (_Context->x_auto2+20+560) ) 
	&&  ( my <= (_Context->y_auto2+110+16))) {
		return(6); /* Identifier */
		}
	if (( mx >= (_Context->x_auto2+30) ) 
	&&  ( my >= (_Context->y_auto2+230) ) 
	&&  ( mx <= (_Context->x_auto2+30+182) ) 
	&&  ( my <= (_Context->y_auto2+230+16))) {
		return(7); /* IsProgram */
		}
	if (( mx >= (_Context->x_auto2+210) ) 
	&&  ( my >= (_Context->y_auto2+230) ) 
	&&  ( mx <= (_Context->x_auto2+210+154) ) 
	&&  ( my <= (_Context->y_auto2+230+16))) {
		return(8); /* IsOverlay */
		}
	if (( mx >= (_Context->x_auto2+350) ) 
	&&  ( my >= (_Context->y_auto2+230) ) 
	&&  ( mx <= (_Context->x_auto2+350+126) ) 
	&&  ( my <= (_Context->y_auto2+230+16))) {
		return(9); /* IsTrueColour */
		}
	if (( mx >= (_Context->x_auto2+20) ) 
	&&  ( my >= (_Context->y_auto2+270) ) 
	&&  ( mx <= (_Context->x_auto2+20+42) ) 
	&&  ( my <= (_Context->y_auto2+270+48))) {
		return(10); /* Auto2714 */
		}
	if (( mx >= (_Context->x_auto2+540) ) 
	&&  ( my >= (_Context->y_auto2+270) ) 
	&&  ( mx <= (_Context->x_auto2+540+42) ) 
	&&  ( my <= (_Context->y_auto2+270+48))) {
		return(11); /* Auto2715 */
		}
	if (( mx >= (_Context->x_auto2+20) ) 
	&&  ( my >= (_Context->y_auto2+160) ) 
	&&  ( mx <= (_Context->x_auto2+20+560) ) 
	&&  ( my <= (_Context->y_auto2+160+60))) {
		return(13); /* Inclusions */
		}
	if (( mx >= (_Context->x_auto2+470+0) ) 
	&&  ( my >= (_Context->y_auto2+230) ) 
	&&  ( mx <= (_Context->x_auto2+470+104) ) 
	&&  ( my <= (_Context->y_auto2+230+16))) {
		return(14); /* Dimensions */
		}
	if (( mx >= (_Context->x_auto2+290) ) 
	&&  ( my >= (_Context->y_auto2+270) ) 
	&&  ( mx <= (_Context->x_auto2+290+42) ) 
	&&  ( my <= (_Context->y_auto2+270+48))) {
		return(15); /* Edit */
		}
	if (( mx >= (_Context->x_auto2+360) ) 
	&&  ( my >= (_Context->y_auto2+270) ) 
	&&  ( mx <= (_Context->x_auto2+360+100) ) 
	&&  ( my <= (_Context->y_auto2+270+30))) {
		return(16); /* Select */
		}

	return(-1);
}


public	int	accept_c_production_focus(struct accept_c_production_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x3 :
				/* FileName */
				_Context->keycode = visual_edit(_Context->x_auto2+20+1,_Context->y_auto2+60+1,536,16,vfh[1],_Context->buffer_FileName,255);
			break;
			case	0x4 :
				/* choixFileName */
				_Context->trigger_choixFileName=visual_trigger_code(_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]));
				visual_button(_Context->x_auto2+560,_Context->y_auto2+60,20,18,vfh[1],27,28,_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_choixFileName=visual_trigger_code(_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]));
	visual_button(_Context->x_auto2+560,_Context->y_auto2+60,20,18,vfh[1],27,28,_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]),0);
				break;
			case	0x6 :
				/* Identifier */
				_Context->keycode = visual_edit(_Context->x_auto2+20+1,_Context->y_auto2+110+1,560,16,vfh[1],_Context->buffer_Identifier,255);
			break;
			case	0x7 :
				/* IsProgram */
				visual_check(_Context->x_auto2+30,_Context->y_auto2+230,182,16,vfh[2],34,0,_Context->msg_IsProgram[_Context->language],strlen(_Context->msg_IsProgram[_Context->language]),(_Context->value_IsProgram |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsProgram=visual_trigger_code(_Context->msg_IsProgram[_Context->language],strlen(_Context->msg_IsProgram[_Context->language]));
	visual_check(_Context->x_auto2+30,_Context->y_auto2+230,182,16,vfh[2],34,0,_Context->msg_IsProgram[_Context->language],strlen(_Context->msg_IsProgram[_Context->language]),_Context->value_IsProgram|0);
				break;
			case	0x8 :
				/* IsOverlay */
				visual_check(_Context->x_auto2+210,_Context->y_auto2+230,154,16,vfh[2],16,0,_Context->msg_IsOverlay[_Context->language],strlen(_Context->msg_IsOverlay[_Context->language]),(_Context->value_IsOverlay |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsOverlay=visual_trigger_code(_Context->msg_IsOverlay[_Context->language],strlen(_Context->msg_IsOverlay[_Context->language]));
	visual_check(_Context->x_auto2+210,_Context->y_auto2+230,154,16,vfh[2],16,0,_Context->msg_IsOverlay[_Context->language],strlen(_Context->msg_IsOverlay[_Context->language]),_Context->value_IsOverlay|0);
				break;
			case	0x9 :
				/* IsTrueColour */
				visual_check(_Context->x_auto2+350,_Context->y_auto2+230,126,16,vfh[2],16,0,_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]),(_Context->value_IsTrueColour |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsTrueColour=visual_trigger_code(_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]));
	visual_check(_Context->x_auto2+350,_Context->y_auto2+230,126,16,vfh[2],16,0,_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]),_Context->value_IsTrueColour|0);
				break;
			case	0xa :
				/* Auto2714 */
				_Context->trigger_Auto2714=visual_trigger_code(_Context->msg_Auto2714[_Context->language],strlen(_Context->msg_Auto2714[_Context->language]));
				visual_button(_Context->x_auto2+20,_Context->y_auto2+270,42,48,vfh[2],34,0,_Context->msg_Auto2714[_Context->language],strlen(_Context->msg_Auto2714[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2714=visual_trigger_code(_Context->msg_Auto2714[_Context->language],strlen(_Context->msg_Auto2714[_Context->language]));
	visual_button(_Context->x_auto2+20,_Context->y_auto2+270,42,48,vfh[2],34,0,_Context->msg_Auto2714[_Context->language],strlen(_Context->msg_Auto2714[_Context->language]),1040);
				break;
			case	0xb :
				/* Auto2715 */
				_Context->trigger_Auto2715=visual_trigger_code(_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]));
				visual_button(_Context->x_auto2+540,_Context->y_auto2+270,42,48,vfh[2],34,0,_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2715=visual_trigger_code(_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]));
	visual_button(_Context->x_auto2+540,_Context->y_auto2+270,42,48,vfh[2],34,0,_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]),1040);
				break;
			case	0xd :
				/* Inclusions */
				_Context->keycode = visual_edit(_Context->x_auto2+20+1,_Context->y_auto2+160+1,560,60,vfh[1],_Context->buffer_Inclusions,255);
			break;
			case	0xe :
				/* Dimensions */
				_Context->keycode = visual_select(_Context->x_auto2+470,_Context->y_auto2+230,104,80,vfh[1],0,0,parse_selection(_Context->msg_Dimensions[_Context->language],&_Context->value_Dimensions),2);
				break;
			case	0xf :
				/* Edit */
				_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
				visual_button(_Context->x_auto2+290,_Context->y_auto2+270,42,48,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),274);
				_Context->keycode = visual_getch();
				_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
	visual_button(_Context->x_auto2+290,_Context->y_auto2+270,42,48,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),272);
				break;
			case	0x10 :
				/* Select */
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
				visual_button(_Context->x_auto2+360,_Context->y_auto2+270,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto2+360,_Context->y_auto2+270,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_c_production_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=16;
			accept_c_production_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_c_production_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x3 :
						if (FileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (Identifier_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (IsProgram_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (IsOverlay_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (IsTrueColour_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (Auto2714_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Auto2715_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (Inclusions_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (Edit_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (Select_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* auto2 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x3 :
					/* FileName */
					continue;
				case	0x4 :
					/* choixFileName */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_choixFileName=visual_trigger_code(_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]));
						visual_button(_Context->x_auto2+560,_Context->y_auto2+60,20,18,vfh[1],27,28,_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_choixFileName=visual_trigger_code(_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]));
	visual_button(_Context->x_auto2+560,_Context->y_auto2+60,20,18,vfh[1],27,28,_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_choixFileName_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Identifier */
					continue;
				case	0x7 :
					/* IsProgram */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsProgram += 1;
						_Context->value_IsProgram &= 1;
						}
					continue;
				case	0x8 :
					/* IsOverlay */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsOverlay += 1;
						_Context->value_IsOverlay &= 1;
						}
					continue;
				case	0x9 :
					/* IsTrueColour */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsTrueColour += 1;
						_Context->value_IsTrueColour &= 1;
						}
					continue;
				case	0xa :
					/* Auto2714 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2714=visual_trigger_code(_Context->msg_Auto2714[_Context->language],strlen(_Context->msg_Auto2714[_Context->language]));
						visual_button(_Context->x_auto2+20,_Context->y_auto2+270,42,48,vfh[2],34,0,_Context->msg_Auto2714[_Context->language],strlen(_Context->msg_Auto2714[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2714=visual_trigger_code(_Context->msg_Auto2714[_Context->language],strlen(_Context->msg_Auto2714[_Context->language]));
	visual_button(_Context->x_auto2+20,_Context->y_auto2+270,42,48,vfh[2],34,0,_Context->msg_Auto2714[_Context->language],strlen(_Context->msg_Auto2714[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2714_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Auto2715 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2715=visual_trigger_code(_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]));
						visual_button(_Context->x_auto2+540,_Context->y_auto2+270,42,48,vfh[2],34,0,_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2715=visual_trigger_code(_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]));
	visual_button(_Context->x_auto2+540,_Context->y_auto2+270,42,48,vfh[2],34,0,_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2715_event(_Context)) != -1) break;

						}
					continue;
				case	0xd :
					/* Inclusions */
					continue;
				case	0xe :
					/* Dimensions */
					continue;
				case	0xf :
					/* Edit */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
						visual_button(_Context->x_auto2+290,_Context->y_auto2+270,42,48,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),274);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
	visual_button(_Context->x_auto2+290,_Context->y_auto2+270,42,48,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),272);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Edit_event(_Context)) != -1) break;

						}
					continue;
				case	0x10 :
					/* Select */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
						visual_button(_Context->x_auto2+360,_Context->y_auto2+270,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto2+360,_Context->y_auto2+270,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Select_event(_Context)) != -1) break;

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
				_Context->focus_item=16;
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

public	int	accept_c_production(
	char * pFileName,
	char * pIdentifier,
	char * pIsProgram,
	char * pIsOverlay,
	char * pIsTrueColour,
	char * pInclusions,
	char * pDimensions)
{
	int	status=0;
	struct accept_c_production_context * _Context=(struct accept_c_production_context*) 0;
	status = accept_c_production_create(
	&_Context,
	 pFileName,
	 pIdentifier,
	 pIsProgram,
	 pIsOverlay,
	 pIsTrueColour,
	 pInclusions,
	 pDimensions);
	if ( status != 0) return(status);
	status = accept_c_production_show(_Context);
		enter_modal();
	status = accept_c_production_focus(_Context);
		leave_modal();
	status = accept_c_production_hide(_Context);
	status = accept_c_production_remove(
	_Context,
	 pFileName,
	 pIdentifier,
	 pIsProgram,
	 pIsOverlay,
	 pIsTrueColour,
	 pInclusions,
	 pDimensions);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcprod_c */
