
#ifndef _vcppprod_c
#define _vcppprod_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.37                                                */
/* Production     : C                                                        */
/* Project        : vcppprod.xml                                             */
/* Target         : vcppprod.c                                               */
/* Identification : 0.0-1200413291-16399.2413                                */
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
#define en_Auto482   "ok.gif"
#define fr_Auto482   "ok.gif"
#define it_Auto482   "ok.gif"
#define es_Auto482   "ok.gif"
#define de_Auto482   "ok.gif"
#define nl_Auto482   "ok.gif"
#define pt_Auto482   "ok.gif"
#define xx_Auto482   "ok.gif"
#define en__Auto482   ""
#define en_Auto483   "cancel.gif"
#define fr_Auto483   "cancel.gif"
#define it_Auto483   "cancel.gif"
#define es_Auto483   "cancel.gif"
#define de_Auto483   "cancel.gif"
#define nl_Auto483   "cancel.gif"
#define pt_Auto483   "cancel.gif"
#define xx_Auto483   "cancel.gif"
#define en__Auto483   ""
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
#define en_Auto484   "C++ production"
#define fr_Auto484   "C++ production"
#define it_Auto484   "C++ production"
#define es_Auto484   "C++ production"
#define de_Auto484   "C++ production"
#define nl_Auto484   "C++ production"
#define pt_Auto484   "C++ production"
#define xx_Auto484   "C++ production"
#define en__Auto484   ""
#define fr__Auto484   ""
#define it__Auto484   ""
#define es__Auto484   ""
#define de__Auto484   ""
#define nl__Auto484   ""
#define pt__Auto484   ""
#define xx__Auto484   ""
#define en_Auto485   ""
#define en__Auto485   ""
#define en_auto7   "C++ Production Filename"
#define fr_auto7   "Nom de Fichier Cible C++"
#define it_auto7   "C++ production Filename"
#define es_auto7   "C++ Production Filename"
#define de_auto7   "C++ Production Filename"
#define nl_auto7   "C++ Production Filename"
#define pt_auto7   "C++ Production Filename"
#define xx_auto7   "C++ Production Filename"
#define en__auto7   ""
#define fr__auto7   ""
#define it__auto7   ""
#define es__auto7   ""
#define de__auto7   ""
#define nl__auto7   ""
#define pt__auto7   ""
#define xx__auto7   ""
#define en_FileName   ""
#define en__FileName   ""
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
#define en_Identifier   ""
#define en__Identifier   ""
#define en_IsProgram   "&Alone Unit"
#define fr_IsProgram   "&Module autonome"
#define it_IsProgram   "&Alone Unit"
#define es_IsProgram   "&Alone Unit"
#define de_IsProgram   "&Alone Unit"
#define nl_IsProgram   "&Alone Unit"
#define pt_IsProgram   "&Alone Unit"
#define xx_IsProgram   "&Alone Unit"
#define en__IsProgram   ""
#define fr__IsProgram   ""
#define it__IsProgram   ""
#define es__IsProgram   ""
#define de__IsProgram   ""
#define nl__IsProgram   ""
#define pt__IsProgram   ""
#define xx__IsProgram   ""
#define en_IsOverlay   "&Overlay or Library"
#define fr_IsOverlay   "&Overlay ou Librairie"
#define it_IsOverlay   "&Overlay or Library"
#define es_IsOverlay   "&Overlay or Library"
#define de_IsOverlay   "&Overlay or Library"
#define nl_IsOverlay   "&Overlay or Library"
#define pt_IsOverlay   "&Overlay or Library"
#define xx_IsOverlay   "&Overlay or Library"
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
#define en_auto641   "Inclusions"
#define fr_auto641   "Inclusions"
#define it_auto641   "Inclusions"
#define es_auto641   "Inclusions"
#define de_auto641   "Inclusions"
#define nl_auto641   "Inclusions"
#define pt_auto641   "Inclusions"
#define xx_auto641   "Inclusions"
#define en__auto641   ""
#define en_Inclusions   ""
#define en__Inclusions   ""
#define en_Dimensions   "320x200|640x400|640x480|800x600|1024x786|1280x1024"
#define fr_Dimensions   "320x200|640x400|640x480|800x600|1024x786|1280x1024"
#define en__Dimensions   ""
#define en_Auto486   "C++ compilation"
#define fr_Auto486   "C++ compilation"
#define it_Auto486   "C++ compilation"
#define es_Auto486   "C++ compilation"
#define de_Auto486   "C++ compilation"
#define nl_Auto486   "C++ compilation"
#define pt_Auto486   "C++ compilation"
#define xx_Auto486   "C++ compilation"
#define en__Auto486   ""
#define fr__Auto486   ""
#define it__Auto486   ""
#define es__Auto486   ""
#define de__Auto486   ""
#define nl__Auto486   ""
#define pt__Auto486   ""
#define xx__Auto486   ""
#define en_OptionCompile   ""
#define en__OptionCompile   ""
#define en_Auto487   "Compilation options"
#define fr_Auto487   "Options de compilation"
#define it_Auto487   "Compilation options"
#define es_Auto487   "Compilation options"
#define de_Auto487   "Compilation options"
#define nl_Auto487   "Compilation options"
#define pt_Auto487   "Compilation options"
#define xx_Auto487   "Compilation options"
#define en__Auto487   ""
#define fr__Auto487   ""
#define it__Auto487   ""
#define es__Auto487   ""
#define de__Auto487   ""
#define nl__Auto487   ""
#define pt__Auto487   ""
#define xx__Auto487   ""
#define en_Auto488   "C++ linkage"
#define fr_Auto488   "C++ linkage"
#define it_Auto488   "C++ linkage"
#define es_Auto488   "C++ linkage"
#define de_Auto488   "C++ linkage"
#define nl_Auto488   "C++ linkage"
#define pt_Auto488   "C++ linkage"
#define xx_Auto488   "C++ linkage"
#define en__Auto488   ""
#define fr__Auto488   ""
#define it__Auto488   ""
#define es__Auto488   ""
#define de__Auto488   ""
#define nl__Auto488   ""
#define pt__Auto488   ""
#define xx__Auto488   ""
#define en_Auto489   "Linkage Options"
#define fr_Auto489   "Linkage options"
#define it_Auto489   "Linkage options"
#define es_Auto489   "Linkage options"
#define de_Auto489   "Linkage options"
#define nl_Auto489   "Linkage options"
#define pt_Auto489   "Linkage options"
#define xx_Auto489   "Linkage options"
#define en__Auto489   ""
#define fr__Auto489   ""
#define it__Auto489   ""
#define es__Auto489   ""
#define de__Auto489   ""
#define nl__Auto489   ""
#define pt__Auto489   ""
#define xx__Auto489   ""
#define en_OptionLinkage   ""
#define en__OptionLinkage   ""

private struct accept_cpp_production_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[3+1];
	char * msg_auto2[8];
	char * hint_auto2[8];
	int	x_auto2;
	int	y_auto2;
	int	w_auto2;
	int	h_auto2;
	char * msg_Auto482[8];
	int	trigger_Auto482;
	char * hint_Auto482[8];
	char * msg_Auto483[8];
	int	trigger_Auto483;
	char * hint_Auto483[8];
	char * msg_Edit[8];
	int	trigger_Edit;
	char * hint_Edit[8];
	char * msg_Select[8];
	int	trigger_Select;
	char * hint_Select[8];
	char * msg_Auto484[8];
	int	trigger_Auto484;
	char * hint_Auto484[8];
	int	page_number;
	char * hint_Auto485[8];
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
	char * msg_auto641[8];
	char * hint_auto641[8];
	char * hint_Inclusions[8];
	char	buffer_Inclusions[256];
	char * msg_Dimensions[8];
	char * hint_Dimensions[8];
	int	value_Dimensions;
	char * msg_Auto486[8];
	int	trigger_Auto486;
	char * hint_Auto486[8];
	char * hint_OptionCompile[8];
	char	buffer_OptionCompile[631];
	char * msg_Auto487[8];
	char * hint_Auto487[8];
	char * msg_Auto488[8];
	int	trigger_Auto488;
	char * hint_Auto488[8];
	char * msg_Auto489[8];
	char * hint_Auto489[8];
	char * hint_OptionLinkage[8];
	char	buffer_OptionLinkage[631];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[10];
	};
static int	vfh[16];

public	int	accept_cpp_production_create(
	struct accept_cpp_production_context ** cptr,
	char * pFileName,
	char * pIdentifier,
	char * pIsProgram,
	char * pIsOverlay,
	char * pIsTrueColour,
	char * pInclusions,
	char * pDimensions,
	char * pOptionCompile,
	char * pOptionLinkage)
{

	int i;
	struct accept_cpp_production_context * _Context=(struct accept_cpp_production_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_cpp_production_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=21;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWSWSS");
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
		visual_transferin(_Context->buffer_OptionCompile, 630, pOptionCompile);
		visual_transferin(_Context->buffer_OptionLinkage, 630, pOptionLinkage);
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
	_Context->y_auto2=120;
	_Context->w_auto2=600;
	_Context->h_auto2=360;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto482[i]=" ";
	_Context->msg_Auto482[0]=en_Auto482;
	_Context->msg_Auto482[1]=fr_Auto482;
	_Context->msg_Auto482[2]=it_Auto482;
	_Context->msg_Auto482[3]=es_Auto482;
	_Context->msg_Auto482[4]=de_Auto482;
	_Context->msg_Auto482[5]=nl_Auto482;
	_Context->msg_Auto482[6]=pt_Auto482;
	_Context->msg_Auto482[7]=xx_Auto482;
	_Context->hint_Auto482[0]=en__Auto482;
	for (i=0; i < 8; i++)_Context->msg_Auto483[i]=" ";
	_Context->msg_Auto483[0]=en_Auto483;
	_Context->msg_Auto483[1]=fr_Auto483;
	_Context->msg_Auto483[2]=it_Auto483;
	_Context->msg_Auto483[3]=es_Auto483;
	_Context->msg_Auto483[4]=de_Auto483;
	_Context->msg_Auto483[5]=nl_Auto483;
	_Context->msg_Auto483[6]=pt_Auto483;
	_Context->msg_Auto483[7]=xx_Auto483;
	_Context->hint_Auto483[0]=en__Auto483;
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
	for (i=0; i < 8; i++)_Context->msg_Auto484[i]=" ";
	_Context->msg_Auto484[0]=en_Auto484;
	_Context->msg_Auto484[1]=fr_Auto484;
	_Context->msg_Auto484[2]=it_Auto484;
	_Context->msg_Auto484[3]=es_Auto484;
	_Context->msg_Auto484[4]=de_Auto484;
	_Context->msg_Auto484[5]=nl_Auto484;
	_Context->msg_Auto484[6]=pt_Auto484;
	_Context->msg_Auto484[7]=xx_Auto484;
	_Context->hint_Auto484[0]=en__Auto484;
	_Context->hint_Auto484[1]=fr__Auto484;
	_Context->hint_Auto484[2]=it__Auto484;
	_Context->hint_Auto484[3]=es__Auto484;
	_Context->hint_Auto484[4]=de__Auto484;
	_Context->hint_Auto484[5]=nl__Auto484;
	_Context->hint_Auto484[6]=pt__Auto484;
	_Context->hint_Auto484[7]=xx__Auto484;
	_Context->focus_pages[1]=6;
	_Context->hint_Auto485[0]=en__Auto485;
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
	_Context->hint_FileName[0]=en__FileName;
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
	_Context->hint_Identifier[0]=en__Identifier;
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
	_Context->hint_Inclusions[0]=en__Inclusions;
	for (i=0; i < 8; i++)_Context->msg_Dimensions[i]=" ";
	_Context->msg_Dimensions[0]=en_Dimensions;
	_Context->msg_Dimensions[1]=fr_Dimensions;
	_Context->hint_Dimensions[0]=en__Dimensions;
	for (i=0; i < 8; i++)_Context->msg_Auto486[i]=" ";
	_Context->msg_Auto486[0]=en_Auto486;
	_Context->msg_Auto486[1]=fr_Auto486;
	_Context->msg_Auto486[2]=it_Auto486;
	_Context->msg_Auto486[3]=es_Auto486;
	_Context->msg_Auto486[4]=de_Auto486;
	_Context->msg_Auto486[5]=nl_Auto486;
	_Context->msg_Auto486[6]=pt_Auto486;
	_Context->msg_Auto486[7]=xx_Auto486;
	_Context->hint_Auto486[0]=en__Auto486;
	_Context->hint_Auto486[1]=fr__Auto486;
	_Context->hint_Auto486[2]=it__Auto486;
	_Context->hint_Auto486[3]=es__Auto486;
	_Context->hint_Auto486[4]=de__Auto486;
	_Context->hint_Auto486[5]=nl__Auto486;
	_Context->hint_Auto486[6]=pt__Auto486;
	_Context->hint_Auto486[7]=xx__Auto486;
	_Context->focus_pages[2]=18;
	_Context->hint_OptionCompile[0]=en__OptionCompile;
	for (i=0; i < 8; i++)_Context->msg_Auto487[i]=" ";
	_Context->msg_Auto487[0]=en_Auto487;
	_Context->msg_Auto487[1]=fr_Auto487;
	_Context->msg_Auto487[2]=it_Auto487;
	_Context->msg_Auto487[3]=es_Auto487;
	_Context->msg_Auto487[4]=de_Auto487;
	_Context->msg_Auto487[5]=nl_Auto487;
	_Context->msg_Auto487[6]=pt_Auto487;
	_Context->msg_Auto487[7]=xx_Auto487;
	_Context->hint_Auto487[0]=en__Auto487;
	_Context->hint_Auto487[1]=fr__Auto487;
	_Context->hint_Auto487[2]=it__Auto487;
	_Context->hint_Auto487[3]=es__Auto487;
	_Context->hint_Auto487[4]=de__Auto487;
	_Context->hint_Auto487[5]=nl__Auto487;
	_Context->hint_Auto487[6]=pt__Auto487;
	_Context->hint_Auto487[7]=xx__Auto487;
	for (i=0; i < 8; i++)_Context->msg_Auto488[i]=" ";
	_Context->msg_Auto488[0]=en_Auto488;
	_Context->msg_Auto488[1]=fr_Auto488;
	_Context->msg_Auto488[2]=it_Auto488;
	_Context->msg_Auto488[3]=es_Auto488;
	_Context->msg_Auto488[4]=de_Auto488;
	_Context->msg_Auto488[5]=nl_Auto488;
	_Context->msg_Auto488[6]=pt_Auto488;
	_Context->msg_Auto488[7]=xx_Auto488;
	_Context->hint_Auto488[0]=en__Auto488;
	_Context->hint_Auto488[1]=fr__Auto488;
	_Context->hint_Auto488[2]=it__Auto488;
	_Context->hint_Auto488[3]=es__Auto488;
	_Context->hint_Auto488[4]=de__Auto488;
	_Context->hint_Auto488[5]=nl__Auto488;
	_Context->hint_Auto488[6]=pt__Auto488;
	_Context->hint_Auto488[7]=xx__Auto488;
	_Context->focus_pages[3]=20;
	for (i=0; i < 8; i++)_Context->msg_Auto489[i]=" ";
	_Context->msg_Auto489[0]=en_Auto489;
	_Context->msg_Auto489[1]=fr_Auto489;
	_Context->msg_Auto489[2]=it_Auto489;
	_Context->msg_Auto489[3]=es_Auto489;
	_Context->msg_Auto489[4]=de_Auto489;
	_Context->msg_Auto489[5]=nl_Auto489;
	_Context->msg_Auto489[6]=pt_Auto489;
	_Context->msg_Auto489[7]=xx_Auto489;
	_Context->hint_Auto489[0]=en__Auto489;
	_Context->hint_Auto489[1]=fr__Auto489;
	_Context->hint_Auto489[2]=it__Auto489;
	_Context->hint_Auto489[3]=es__Auto489;
	_Context->hint_Auto489[4]=de__Auto489;
	_Context->hint_Auto489[5]=nl__Auto489;
	_Context->hint_Auto489[6]=pt__Auto489;
	_Context->hint_Auto489[7]=xx__Auto489;
	_Context->hint_OptionLinkage[0]=en__OptionLinkage;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto2,_Context->y_auto2,600+10,360+10);
	return(0);
}

public 	int	accept_cpp_production_hide(struct accept_cpp_production_context * _Context)
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

public	int	accept_cpp_production_remove(
	struct accept_cpp_production_context * _Context,
	char * pFileName,
	char * pIdentifier,
	char * pIsProgram,
	char * pIsOverlay,
	char * pIsTrueColour,
	char * pInclusions,
	char * pDimensions,
	char * pOptionCompile,
	char * pOptionLinkage)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWSWSS");
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
		visual_transferout(_Context->buffer_OptionCompile, 630, pOptionCompile);
		visual_transferout(_Context->buffer_OptionLinkage, 630, pOptionLinkage);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Identifier_show(struct accept_cpp_production_context * _Context) {
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+140,560+2,16+2,5);
visual_text(_Context->x_auto2+20+1,_Context->y_auto2+140+1,560,16,vfh[1],34,0,_Context->buffer_Identifier,255,0);
;
	return(-1);
}

public	int	accept_cpp_production_show(struct accept_cpp_production_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto2,_Context->y_auto2);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_auto2,_Context->y_auto2,600,360,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_auto2,_Context->y_auto2,600,360,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	_Context->trigger_Auto482=visual_trigger_code(_Context->msg_Auto482[_Context->language],strlen(_Context->msg_Auto482[_Context->language]));
	visual_button(_Context->x_auto2+20,_Context->y_auto2+300,42,48,vfh[2],34,0,_Context->msg_Auto482[_Context->language],strlen(_Context->msg_Auto482[_Context->language]),1040);
	_Context->trigger_Auto483=visual_trigger_code(_Context->msg_Auto483[_Context->language],strlen(_Context->msg_Auto483[_Context->language]));
	visual_button(_Context->x_auto2+540,_Context->y_auto2+300,42,48,vfh[2],34,0,_Context->msg_Auto483[_Context->language],strlen(_Context->msg_Auto483[_Context->language]),1040);
	_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
	visual_button(_Context->x_auto2+290,_Context->y_auto2+300,42,48,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),272);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto2+360,_Context->y_auto2+300,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	if (_Context->page_number == 1 ) {
	_Context->trigger_Auto484=visual_trigger_code(_Context->msg_Auto484[_Context->language],strlen(_Context->msg_Auto484[_Context->language]));
	visual_tabpage(_Context->x_auto2+10,_Context->y_auto2+30,580,260,vfh[2],_Context->msg_Auto484[_Context->language],strlen(_Context->msg_Auto484[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_auto2+10,_Context->y_auto2+30,580,260,vfh[2],_Context->msg_Auto484[_Context->language],strlen(_Context->msg_Auto484[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+250,560,30,2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_auto2+20,_Context->y_auto2+70,560,16,vfh[2],27,0,_Context->msg_auto7[_Context->language],strlen(_Context->msg_auto7[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+90,536+2,16+2,5);
	visual_text(_Context->x_auto2+20+1,_Context->y_auto2+90+1,536,16,vfh[1],34,0,_Context->buffer_FileName,255,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_choixFileName=visual_trigger_code(_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]));
	visual_button(_Context->x_auto2+560,_Context->y_auto2+90,20,18,vfh[1],27,28,_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_auto2+20,_Context->y_auto2+120,560,16,vfh[2],27,0,_Context->msg_auto52[_Context->language],strlen(_Context->msg_auto52[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	(void) on_Identifier_show(_Context);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_IsProgram=visual_trigger_code(_Context->msg_IsProgram[_Context->language],strlen(_Context->msg_IsProgram[_Context->language]));
	visual_check(_Context->x_auto2+30,_Context->y_auto2+260,168,16,vfh[2],34,0,_Context->msg_IsProgram[_Context->language],strlen(_Context->msg_IsProgram[_Context->language]),_Context->value_IsProgram|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_IsOverlay=visual_trigger_code(_Context->msg_IsOverlay[_Context->language],strlen(_Context->msg_IsOverlay[_Context->language]));
	visual_check(_Context->x_auto2+190,_Context->y_auto2+260,180,16,vfh[2],16,0,_Context->msg_IsOverlay[_Context->language],strlen(_Context->msg_IsOverlay[_Context->language]),_Context->value_IsOverlay|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_IsTrueColour=visual_trigger_code(_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]));
	visual_check(_Context->x_auto2+340,_Context->y_auto2+260,126,16,vfh[2],16,0,_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]),_Context->value_IsTrueColour|0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_auto2+20,_Context->y_auto2+170,560,16,vfh[2],27,0,_Context->msg_auto641[_Context->language],strlen(_Context->msg_auto641[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+190,560+2,60+2,5);
	visual_text(_Context->x_auto2+20+1,_Context->y_auto2+190+1,560,60,vfh[1],26,0,_Context->buffer_Inclusions,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_auto2+470,_Context->y_auto2+260,104,80,vfh[1],0,0,parse_selection(_Context->msg_Dimensions[_Context->language],&_Context->value_Dimensions),0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Auto486=visual_trigger_code(_Context->msg_Auto486[_Context->language],strlen(_Context->msg_Auto486[_Context->language]));
	visual_tabpage(_Context->x_auto2+10,_Context->y_auto2+30,580,260,vfh[2],_Context->msg_Auto486[_Context->language],strlen(_Context->msg_Auto486[_Context->language]),119,2);
	} else {
		visual_tabpage(_Context->x_auto2+10,_Context->y_auto2+30,580,260,vfh[2],_Context->msg_Auto486[_Context->language],strlen(_Context->msg_Auto486[_Context->language]),119,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+110,560+2,150+2,5);
	visual_text(_Context->x_auto2+20+1,_Context->y_auto2+110+1,560,150,vfh[1],27,28,_Context->buffer_OptionCompile,630,0);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_auto2+20,_Context->y_auto2+80,230,20,vfh[3],0,0,_Context->msg_Auto487[_Context->language],strlen(_Context->msg_Auto487[_Context->language]),259);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_Auto488=visual_trigger_code(_Context->msg_Auto488[_Context->language],strlen(_Context->msg_Auto488[_Context->language]));
	visual_tabpage(_Context->x_auto2+10,_Context->y_auto2+30,580,260,vfh[2],_Context->msg_Auto488[_Context->language],strlen(_Context->msg_Auto488[_Context->language]),243,2);
	} else {
		visual_tabpage(_Context->x_auto2+10,_Context->y_auto2+30,580,260,vfh[2],_Context->msg_Auto488[_Context->language],strlen(_Context->msg_Auto488[_Context->language]),243,0);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_auto2+20,_Context->y_auto2+80,230,20,vfh[3],0,0,_Context->msg_Auto489[_Context->language],strlen(_Context->msg_Auto489[_Context->language]),259);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+110,560+2,150+2,5);
	visual_text(_Context->x_auto2+20+1,_Context->y_auto2+110+1,560,150,vfh[1],27,28,_Context->buffer_OptionLinkage,630,0);
		}
	visual_thaw(_Context->x_auto2,_Context->y_auto2,600,360);

	return(0);
}

private int Auto482_help()
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

private int Auto483_help()
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

private int auto2action(struct accept_cpp_production_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_cpp_production_hide(_Context);

		_Context->x_auto2 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto2 < 0) { _Context->x_auto2=0; }
		_Context->y_auto2 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto2 < 0) { _Context->y_auto2=0; }
			accept_cpp_production_show(_Context);

		visual_thaw(_Context->x_auto2,_Context->y_auto2,600,360);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto482_event(struct accept_cpp_production_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto483_event(struct accept_cpp_production_context * _Context) {
	return(27);
	return(-1);
}
private int on_Edit_event(struct accept_cpp_production_context * _Context) {
		accept_cpp_production_hide(_Context);
;
	use_editor(_Context->buffer_FileName,_GENERATE_C);
		accept_cpp_production_show(_Context);
;
	return(-1);
}
private int on_Select_event(struct accept_cpp_production_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_C);
		accept_cpp_production_show(_Context);
;
	return(-1);
}
private int on_choixFileName_event(struct accept_cpp_production_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_C);
		accept_cpp_production_show(_Context);
;
	return(-1);
}


public	int	accept_cpp_production_event(
struct accept_cpp_production_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto482 == mb ) return(2);
		if (_Context->trigger_Auto483 == mb ) return(3);
		if (_Context->trigger_Edit == mb ) return(4);
		if (_Context->trigger_Select == mb ) return(5);
		if (_Context->trigger_Auto484 == mb ) return(6);
		if (_Context->trigger_choixFileName == mb ) return(9);
		if (_Context->trigger_IsProgram == mb ) return(12);
		if (_Context->trigger_IsOverlay == mb ) return(13);
		if (_Context->trigger_IsTrueColour == mb ) return(14);
		if (_Context->trigger_Auto486 == mb ) return(18);
		if (_Context->trigger_Auto488 == mb ) return(20);
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
			visual_help("vcppprod.htm");
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
		accept_cpp_production_show(_Context);
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
	&&  ( my >= (_Context->y_auto2+300) ) 
	&&  ( mx <= (_Context->x_auto2+20+42) ) 
	&&  ( my <= (_Context->y_auto2+300+48))) {
		return(2); /* Auto482 */
		}
	if (( mx >= (_Context->x_auto2+540) ) 
	&&  ( my >= (_Context->y_auto2+300) ) 
	&&  ( mx <= (_Context->x_auto2+540+42) ) 
	&&  ( my <= (_Context->y_auto2+300+48))) {
		return(3); /* Auto483 */
		}
	if (( mx >= (_Context->x_auto2+290) ) 
	&&  ( my >= (_Context->y_auto2+300) ) 
	&&  ( mx <= (_Context->x_auto2+290+42) ) 
	&&  ( my <= (_Context->y_auto2+300+48))) {
		return(4); /* Edit */
		}
	if (( mx >= (_Context->x_auto2+360) ) 
	&&  ( my >= (_Context->y_auto2+300) ) 
	&&  ( mx <= (_Context->x_auto2+360+100) ) 
	&&  ( my <= (_Context->y_auto2+300+30))) {
		return(5); /* Select */
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_auto2+10+0) ) 
		&&  ( my >= (_Context->y_auto2+30) ) 
		&&  ( mx <= (_Context->x_auto2+10+118) ) 
		&&  ( my <= (_Context->y_auto2+30+24))) {
			return(6); /* Auto484 */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+20) ) 
		&&  ( my >= (_Context->y_auto2+90) ) 
		&&  ( mx <= (_Context->x_auto2+20+536) ) 
		&&  ( my <= (_Context->y_auto2+90+16))) {
			return(8); /* FileName */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+560) ) 
		&&  ( my >= (_Context->y_auto2+90) ) 
		&&  ( mx <= (_Context->x_auto2+560+20) ) 
		&&  ( my <= (_Context->y_auto2+90+18))) {
			return(9); /* choixFileName */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+20) ) 
		&&  ( my >= (_Context->y_auto2+140) ) 
		&&  ( mx <= (_Context->x_auto2+20+560) ) 
		&&  ( my <= (_Context->y_auto2+140+16))) {
			return(11); /* Identifier */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+30) ) 
		&&  ( my >= (_Context->y_auto2+260) ) 
		&&  ( mx <= (_Context->x_auto2+30+168) ) 
		&&  ( my <= (_Context->y_auto2+260+16))) {
			return(12); /* IsProgram */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+190) ) 
		&&  ( my >= (_Context->y_auto2+260) ) 
		&&  ( mx <= (_Context->x_auto2+190+180) ) 
		&&  ( my <= (_Context->y_auto2+260+16))) {
			return(13); /* IsOverlay */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+340) ) 
		&&  ( my >= (_Context->y_auto2+260) ) 
		&&  ( mx <= (_Context->x_auto2+340+126) ) 
		&&  ( my <= (_Context->y_auto2+260+16))) {
			return(14); /* IsTrueColour */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+20) ) 
		&&  ( my >= (_Context->y_auto2+190) ) 
		&&  ( mx <= (_Context->x_auto2+20+560) ) 
		&&  ( my <= (_Context->y_auto2+190+60))) {
			return(16); /* Inclusions */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+470+0) ) 
		&&  ( my >= (_Context->y_auto2+260) ) 
		&&  ( mx <= (_Context->x_auto2+470+104) ) 
		&&  ( my <= (_Context->y_auto2+260+16))) {
			return(17); /* Dimensions */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_auto2+10+119) ) 
		&&  ( my >= (_Context->y_auto2+30) ) 
		&&  ( mx <= (_Context->x_auto2+10+242) ) 
		&&  ( my <= (_Context->y_auto2+30+24))) {
			return(18); /* Auto486 */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_auto2+20) ) 
		&&  ( my >= (_Context->y_auto2+110) ) 
		&&  ( mx <= (_Context->x_auto2+20+560) ) 
		&&  ( my <= (_Context->y_auto2+110+150))) {
			return(19); /* OptionCompile */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_auto2+10+243) ) 
		&&  ( my >= (_Context->y_auto2+30) ) 
		&&  ( mx <= (_Context->x_auto2+10+340) ) 
		&&  ( my <= (_Context->y_auto2+30+24))) {
			return(20); /* Auto488 */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_auto2+20) ) 
		&&  ( my >= (_Context->y_auto2+110) ) 
		&&  ( mx <= (_Context->x_auto2+20+560) ) 
		&&  ( my <= (_Context->y_auto2+110+150))) {
			return(21); /* OptionLinkage */
			}
		}

	return(-1);
}


public	int	accept_cpp_production_losefocus(struct accept_cpp_production_context * _Context)
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;
		case 3 : 
			break;

		}
	return(0);

}


public	int	accept_cpp_production_focus(struct accept_cpp_production_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto482 */
				_Context->trigger_Auto482=visual_trigger_code(_Context->msg_Auto482[_Context->language],strlen(_Context->msg_Auto482[_Context->language]));
				visual_button(_Context->x_auto2+20,_Context->y_auto2+300,42,48,vfh[2],34,0,_Context->msg_Auto482[_Context->language],strlen(_Context->msg_Auto482[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto482=visual_trigger_code(_Context->msg_Auto482[_Context->language],strlen(_Context->msg_Auto482[_Context->language]));
	visual_button(_Context->x_auto2+20,_Context->y_auto2+300,42,48,vfh[2],34,0,_Context->msg_Auto482[_Context->language],strlen(_Context->msg_Auto482[_Context->language]),1040);
				break;
			case	0x3 :
				/* Auto483 */
				_Context->trigger_Auto483=visual_trigger_code(_Context->msg_Auto483[_Context->language],strlen(_Context->msg_Auto483[_Context->language]));
				visual_button(_Context->x_auto2+540,_Context->y_auto2+300,42,48,vfh[2],34,0,_Context->msg_Auto483[_Context->language],strlen(_Context->msg_Auto483[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto483=visual_trigger_code(_Context->msg_Auto483[_Context->language],strlen(_Context->msg_Auto483[_Context->language]));
	visual_button(_Context->x_auto2+540,_Context->y_auto2+300,42,48,vfh[2],34,0,_Context->msg_Auto483[_Context->language],strlen(_Context->msg_Auto483[_Context->language]),1040);
				break;
			case	0x4 :
				/* Edit */
				_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
				visual_button(_Context->x_auto2+290,_Context->y_auto2+300,42,48,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),274);
				_Context->keycode = visual_getch();
				_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
	visual_button(_Context->x_auto2+290,_Context->y_auto2+300,42,48,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),272);
				break;
			case	0x5 :
				/* Select */
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
				visual_button(_Context->x_auto2+360,_Context->y_auto2+300,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto2+360,_Context->y_auto2+300,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;
			case	0x6 :
				/* Auto484 */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x8 :
				/* FileName */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+20+1,_Context->y_auto2+90+1,536,16,vfh[1],_Context->buffer_FileName,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* choixFileName */
				if (_Context->page_number == 1 ) {
					_Context->trigger_choixFileName=visual_trigger_code(_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]));
					visual_button(_Context->x_auto2+560,_Context->y_auto2+90,20,18,vfh[1],27,28,_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_choixFileName=visual_trigger_code(_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]));
	visual_button(_Context->x_auto2+560,_Context->y_auto2+90,20,18,vfh[1],27,28,_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* Identifier */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+20+1,_Context->y_auto2+140+1,560,16,vfh[1],_Context->buffer_Identifier,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* IsProgram */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_auto2+30,_Context->y_auto2+260,168,16,vfh[2],34,0,_Context->msg_IsProgram[_Context->language],strlen(_Context->msg_IsProgram[_Context->language]),(_Context->value_IsProgram |2));
					_Context->keycode = visual_getch();
					_Context->trigger_IsProgram=visual_trigger_code(_Context->msg_IsProgram[_Context->language],strlen(_Context->msg_IsProgram[_Context->language]));
	visual_check(_Context->x_auto2+30,_Context->y_auto2+260,168,16,vfh[2],34,0,_Context->msg_IsProgram[_Context->language],strlen(_Context->msg_IsProgram[_Context->language]),_Context->value_IsProgram|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* IsOverlay */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_auto2+190,_Context->y_auto2+260,180,16,vfh[2],16,0,_Context->msg_IsOverlay[_Context->language],strlen(_Context->msg_IsOverlay[_Context->language]),(_Context->value_IsOverlay |2));
					_Context->keycode = visual_getch();
					_Context->trigger_IsOverlay=visual_trigger_code(_Context->msg_IsOverlay[_Context->language],strlen(_Context->msg_IsOverlay[_Context->language]));
	visual_check(_Context->x_auto2+190,_Context->y_auto2+260,180,16,vfh[2],16,0,_Context->msg_IsOverlay[_Context->language],strlen(_Context->msg_IsOverlay[_Context->language]),_Context->value_IsOverlay|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* IsTrueColour */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_auto2+340,_Context->y_auto2+260,126,16,vfh[2],16,0,_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]),(_Context->value_IsTrueColour |2));
					_Context->keycode = visual_getch();
					_Context->trigger_IsTrueColour=visual_trigger_code(_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]));
	visual_check(_Context->x_auto2+340,_Context->y_auto2+260,126,16,vfh[2],16,0,_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]),_Context->value_IsTrueColour|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* Inclusions */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+20+1,_Context->y_auto2+190+1,560,60,vfh[1],_Context->buffer_Inclusions,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* Dimensions */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_auto2+470,_Context->y_auto2+260,104,80,vfh[1],0,0,parse_selection(_Context->msg_Dimensions[_Context->language],&_Context->value_Dimensions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* Auto486 */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x13 :
				/* OptionCompile */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+20+1,_Context->y_auto2+110+1,560,150,vfh[1],_Context->buffer_OptionCompile,630);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* Auto488 */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x15 :
				/* OptionLinkage */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+20+1,_Context->y_auto2+110+1,560,150,vfh[1],_Context->buffer_OptionLinkage,630);
				} else {
					_Context->keycode = 5;
					}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			accept_cpp_production_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_cpp_production_show(_Context);
			continue;
		case	0x2 :
			accept_cpp_production_losefocus(_Context);
			_Context->page_number=3;
			_Context->focus_item=21;
			accept_cpp_production_show(_Context);
			continue;
		case	0x3 :
			accept_cpp_production_losefocus(_Context);
			if ( _Context->page_number < 3 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_cpp_production_show(_Context);
			continue;
		case	0x12 :
			accept_cpp_production_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_cpp_production_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_cpp_production_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (Auto482_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Auto483_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Edit_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Select_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (FileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Identifier_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (IsProgram_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (IsOverlay_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (IsTrueColour_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (Inclusions_help(_Context) != 0) { continue; }
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
				case	0x2 :
					/* Auto482 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto482=visual_trigger_code(_Context->msg_Auto482[_Context->language],strlen(_Context->msg_Auto482[_Context->language]));
						visual_button(_Context->x_auto2+20,_Context->y_auto2+300,42,48,vfh[2],34,0,_Context->msg_Auto482[_Context->language],strlen(_Context->msg_Auto482[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto482=visual_trigger_code(_Context->msg_Auto482[_Context->language],strlen(_Context->msg_Auto482[_Context->language]));
	visual_button(_Context->x_auto2+20,_Context->y_auto2+300,42,48,vfh[2],34,0,_Context->msg_Auto482[_Context->language],strlen(_Context->msg_Auto482[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto482_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto483 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto483=visual_trigger_code(_Context->msg_Auto483[_Context->language],strlen(_Context->msg_Auto483[_Context->language]));
						visual_button(_Context->x_auto2+540,_Context->y_auto2+300,42,48,vfh[2],34,0,_Context->msg_Auto483[_Context->language],strlen(_Context->msg_Auto483[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto483=visual_trigger_code(_Context->msg_Auto483[_Context->language],strlen(_Context->msg_Auto483[_Context->language]));
	visual_button(_Context->x_auto2+540,_Context->y_auto2+300,42,48,vfh[2],34,0,_Context->msg_Auto483[_Context->language],strlen(_Context->msg_Auto483[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto483_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Edit */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
						visual_button(_Context->x_auto2+290,_Context->y_auto2+300,42,48,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),274);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Edit=visual_trigger_code(_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]));
	visual_button(_Context->x_auto2+290,_Context->y_auto2+300,42,48,vfh[2],26,0,_Context->msg_Edit[_Context->language],strlen(_Context->msg_Edit[_Context->language]),272);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Edit_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Select */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
						visual_button(_Context->x_auto2+360,_Context->y_auto2+300,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto2+360,_Context->y_auto2+300,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Select_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto484 */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_cpp_production_losefocus(_Context);
						_Context->page_number = 1;
						accept_cpp_production_show(_Context);
						}
					continue;
				case	0x8 :
					/* FileName */
					continue;
				case	0x9 :
					/* choixFileName */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_choixFileName=visual_trigger_code(_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]));
						visual_button(_Context->x_auto2+560,_Context->y_auto2+90,20,18,vfh[1],27,28,_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_choixFileName=visual_trigger_code(_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]));
	visual_button(_Context->x_auto2+560,_Context->y_auto2+90,20,18,vfh[1],27,28,_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_choixFileName_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Identifier */
					continue;
				case	0xc :
					/* IsProgram */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsProgram += 1;
						_Context->value_IsProgram &= 1;
						}
					continue;
				case	0xd :
					/* IsOverlay */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsOverlay += 1;
						_Context->value_IsOverlay &= 1;
						}
					continue;
				case	0xe :
					/* IsTrueColour */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsTrueColour += 1;
						_Context->value_IsTrueColour &= 1;
						}
					continue;
				case	0x10 :
					/* Inclusions */
					continue;
				case	0x11 :
					/* Dimensions */
					continue;
				case	0x12 :
					/* Auto486 */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_cpp_production_losefocus(_Context);
						_Context->page_number = 2;
						accept_cpp_production_show(_Context);
						}
					continue;
				case	0x13 :
					/* OptionCompile */
					continue;
				case	0x14 :
					/* Auto488 */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_cpp_production_losefocus(_Context);
						_Context->page_number = 3;
						accept_cpp_production_show(_Context);
						}
					continue;
				case	0x15 :
					/* OptionLinkage */
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

public	int	accept_cpp_production(
	char * pFileName,
	char * pIdentifier,
	char * pIsProgram,
	char * pIsOverlay,
	char * pIsTrueColour,
	char * pInclusions,
	char * pDimensions,
	char * pOptionCompile,
	char * pOptionLinkage)
{
	int	status=0;
	struct accept_cpp_production_context * _Context=(struct accept_cpp_production_context*) 0;
	status = accept_cpp_production_create(
	&_Context,
	 pFileName,
	 pIdentifier,
	 pIsProgram,
	 pIsOverlay,
	 pIsTrueColour,
	 pInclusions,
	 pDimensions,
	 pOptionCompile,
	 pOptionLinkage);
	if ( status != 0) return(status);
	status = accept_cpp_production_show(_Context);
		enter_modal();
	status = accept_cpp_production_focus(_Context);
		leave_modal();
	status = accept_cpp_production_hide(_Context);
	status = accept_cpp_production_remove(
	_Context,
	 pFileName,
	 pIdentifier,
	 pIsProgram,
	 pIsOverlay,
	 pIsTrueColour,
	 pInclusions,
	 pDimensions,
	 pOptionCompile,
	 pOptionLinkage);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcppprod_c */
