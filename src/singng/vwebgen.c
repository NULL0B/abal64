
#ifndef _vwebgen_c
#define _vwebgen_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : vwebgen.xml                                              */
/* Target         : vwebgen.c                                                */
/* Identification : 0.0-1195985875-14416.14415                               */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto3033   ""
#define fr__Auto3033   ""
#define it__Auto3033   ""
#define es__Auto3033   ""
#define de__Auto3033   ""
#define nl__Auto3033   ""
#define pt__Auto3033   ""
#define xx__Auto3033   ""
#define en_Auto3037   "Web Agent Production Parameters"
#define fr_Auto3037   "ParamŠtres de Production d'Agents Web"
#define it_Auto3037   "Web Agent Production Parameters"
#define es_Auto3037   "Web Agent Production Parameters"
#define de_Auto3037   "Web Agent Production Parameters"
#define nl_Auto3037   "Web Agent Production Parameters"
#define pt_Auto3037   "Web Agent Production Parameters"
#define xx_Auto3037   "Web Agent Production Parameters"
#define en__Auto3037   ""
#define fr__Auto3037   ""
#define it__Auto3037   ""
#define es__Auto3037   ""
#define de__Auto3037   ""
#define nl__Auto3037   ""
#define pt__Auto3037   ""
#define xx__Auto3037   ""
#define en_Auto3038   "Stub Filename"
#define fr_Auto3038   "Nom fichier"
#define it_Auto3038   "Nom fichier"
#define es_Auto3038   "Filename"
#define de_Auto3038   "Datei"
#define nl_Auto3038   "Filename"
#define pt_Auto3038   "Filename"
#define xx_Auto3038   "Filename"
#define en__Auto3038   ""
#define fr__Auto3038   ""
#define it__Auto3038   ""
#define es__Auto3038   ""
#define de__Auto3038   ""
#define nl__Auto3038   ""
#define pt__Auto3038   ""
#define xx__Auto3038   ""
#define en_HtmlFileName   ""
#define en__HtmlFileName   ""
#define en_EditHtml   "?"
#define fr_EditHtml   "?"
#define it_EditHtml   "?"
#define es_EditHtml   "?"
#define de_EditHtml   "?"
#define nl_EditHtml   "?"
#define pt_EditHtml   "?"
#define xx_EditHtml   "?"
#define en__EditHtml   ""
#define fr__EditHtml   ""
#define it__EditHtml   ""
#define es__EditHtml   ""
#define de__EditHtml   ""
#define nl__EditHtml   ""
#define pt__EditHtml   ""
#define xx__EditHtml   ""
#define en_EditStyle   "?"
#define fr_EditStyle   "?"
#define it_EditStyle   "?"
#define es_EditStyle   "?"
#define de_EditStyle   "?"
#define nl_EditStyle   "?"
#define pt_EditStyle   "?"
#define xx_EditStyle   "?"
#define en__EditStyle   ""
#define fr__EditStyle   ""
#define it__EditStyle   ""
#define es__EditStyle   ""
#define de__EditStyle   ""
#define nl__EditStyle   ""
#define pt__EditStyle   ""
#define xx__EditStyle   ""
#define en_Title   ""
#define en__Title   ""
#define en_StyleFileName   ""
#define en_Metrics   "pixels|points|millimeters|tenths"
#define fr_Metrics   "pixels|points|millimeters"
#define it_Metrics   "pixels|points|millimeters"
#define es_Metrics   "pixels|points|millimeters"
#define de_Metrics   "pixels|points|millimeters"
#define nl_Metrics   "pixels|points|millimeters"
#define pt_Metrics   "pixels|points|millimeters"
#define xx_Metrics   "pixels|points|millimeters"
#define en__Metrics   ""
#define fr__Metrics   ""
#define it__Metrics   ""
#define es__Metrics   ""
#define de__Metrics   ""
#define nl__Metrics   ""
#define pt__Metrics   ""
#define xx__Metrics   ""
#define en_Points   "10|11|12|13|14|15|16|17|18|19|20"
#define fr_Points   "10|11|12|13|14|15|16|17|18|19|20"
#define it_Points   "10|11|12|13|14|15|16|17|18|19|20"
#define es_Points   "10|11|12|13|14|15|16|17|18|19|20"
#define de_Points   "10|11|12|13|14|15|16|17|18|19|20"
#define nl_Points   "10|11|12|13|14|15|16|17|18|19|20"
#define pt_Points   "10|11|12|13|14|15|16|17|18|19|20"
#define xx_Points   "10|11|12|13|14|15|16|17|18|19|20"
#define en__Points   ""
#define en_WebAgent   "&Web Agent Generation"
#define fr_WebAgent   "G‚n‚ration d'Agent &Web"
#define it_WebAgent   "&Web Agent Generation"
#define es_WebAgent   "&Web Agent Generation"
#define de_WebAgent   "&Web Agent Generation"
#define nl_WebAgent   "&Web Agent Generation"
#define pt_WebAgent   "&Web Agent Generation"
#define xx_WebAgent   "&Web Agent Generation"
#define en__WebAgent   ""
#define fr__WebAgent   ""
#define it__WebAgent   ""
#define es__WebAgent   ""
#define de__WebAgent   ""
#define nl__WebAgent   ""
#define pt__WebAgent   ""
#define xx__WebAgent   ""
#define en_Translation   "&Automatic Secondary Production"
#define fr_Translation   "Production &Automatis‚e"
#define it_Translation   "&Automatic Production"
#define es_Translation   "&Automatic Production"
#define de_Translation   "&Automatic Production"
#define nl_Translation   "&Automatic Production"
#define pt_Translation   "&Automatic Production"
#define xx_Translation   "&Automatic Production"
#define en__Translation   ""
#define fr__Translation   ""
#define it__Translation   ""
#define es__Translation   ""
#define de__Translation   ""
#define nl__Translation   ""
#define pt__Translation   ""
#define xx__Translation   ""
#define en_Restrict   "&Restrict Screen Dimensions"
#define fr_Restrict   "&Restreindre aux dimensions de l'‚cran"
#define it_Restrict   "&Restrict Screen"
#define es_Restrict   "&Restrict Screen"
#define de_Restrict   "&Restrict Screen"
#define nl_Restrict   "&Restrict Screen"
#define pt_Restrict   "&Restrict Screen"
#define xx_Restrict   "&Restrict Screen"
#define en__Restrict   ""
#define fr__Restrict   ""
#define it__Restrict   ""
#define es__Restrict   ""
#define de__Restrict   ""
#define nl__Restrict   ""
#define pt__Restrict   ""
#define xx__Restrict   ""
#define en_Contextual   "Restrict &Contextual Menus"
#define fr_Contextual   "Restreindre Menus &Contexuelles"
#define it_Contextual   "&Restrict Screen"
#define es_Contextual   "&Restrict Screen"
#define de_Contextual   "&Restrict Screen"
#define nl_Contextual   "&Restrict Screen"
#define pt_Contextual   "&Restrict Screen"
#define xx_Contextual   "&Restrict Screen"
#define en__Contextual   ""
#define fr__Contextual   ""
#define it__Contextual   ""
#define es__Contextual   ""
#define de__Contextual   ""
#define nl__Contextual   ""
#define pt__Contextual   ""
#define xx__Contextual   ""
#define en_ActiveImage   "Active &Image Production"
#define fr_ActiveImage   "&Images actives"
#define it_ActiveImage   "Active &Images"
#define es_ActiveImage   "Active &Images"
#define de_ActiveImage   "Active &Images"
#define nl_ActiveImage   "Active &Images"
#define pt_ActiveImage   "Active &Images"
#define xx_ActiveImage   "Active &Images"
#define en__ActiveImage   ""
#define fr__ActiveImage   ""
#define it__ActiveImage   ""
#define es__ActiveImage   ""
#define de__ActiveImage   ""
#define nl__ActiveImage   ""
#define pt__ActiveImage   ""
#define xx__ActiveImage   ""
#define en_iQuality   "Use 100% JPEG &Quality"
#define fr_iQuality   "&Qualit‚ JPEG 100%"
#define it_iQuality   "100% JPEG &Quality"
#define es_iQuality   "100% JPEG &Quality"
#define de_iQuality   "100% JPEG &Quality"
#define nl_iQuality   "100% JPEG &Quality"
#define pt_iQuality   "100% JPEG &Quality"
#define xx_iQuality   "100% JPEG &Quality"
#define en__iQuality   ""
#define fr__iQuality   ""
#define it__iQuality   ""
#define es__iQuality   ""
#define de__iQuality   ""
#define nl__iQuality   ""
#define pt__iQuality   ""
#define xx__iQuality   ""
#define en_iCookie   "Require Session &Cookies"
#define fr_iCookie   "Utiliser les &Cookies"
#define it_iCookie   "Require &Cookies"
#define es_iCookie   "Require &Cookies"
#define de_iCookie   "Require &Cookies"
#define nl_iCookie   "Require &Cookies"
#define pt_iCookie   "Require &Cookies"
#define xx_iCookie   "Require &Cookies"
#define en__iCookie   ""
#define fr__iCookie   ""
#define it__iCookie   ""
#define es__iCookie   ""
#define de__iCookie   ""
#define nl__iCookie   ""
#define pt__iCookie   ""
#define xx__iCookie   ""
#define en_Auto3039   "Title"
#define fr_Auto3039   "Titre"
#define it_Auto3039   "Title"
#define es_Auto3039   "Title"
#define de_Auto3039   "Title"
#define nl_Auto3039   "Title"
#define pt_Auto3039   "Title"
#define xx_Auto3039   "Title"
#define en__Auto3039   ""
#define fr__Auto3039   ""
#define it__Auto3039   ""
#define es__Auto3039   ""
#define de__Auto3039   ""
#define nl__Auto3039   ""
#define pt__Auto3039   ""
#define xx__Auto3039   ""
#define en_Auto3040   "Style"
#define fr_Auto3040   "Style"
#define it_Auto3040   "Style"
#define es_Auto3040   "Style"
#define de_Auto3040   "Style"
#define nl_Auto3040   "Style"
#define pt_Auto3040   "Style"
#define xx_Auto3040   "Style"
#define en__Auto3040   ""
#define fr__Auto3040   ""
#define it__Auto3040   ""
#define es__Auto3040   ""
#define de__Auto3040   ""
#define nl__Auto3040   ""
#define pt__Auto3040   ""
#define xx__Auto3040   ""
#define en_Auto3041   "Metrics"
#define fr_Auto3041   "Unit‚"
#define it_Auto3041   "Metrics"
#define es_Auto3041   "Metrics"
#define de_Auto3041   "Metrics"
#define nl_Auto3041   "Metrics"
#define pt_Auto3041   "Metrics"
#define xx_Auto3041   "Metrics"
#define en__Auto3041   ""
#define fr__Auto3041   ""
#define it__Auto3041   ""
#define es__Auto3041   ""
#define de__Auto3041   ""
#define nl__Auto3041   ""
#define pt__Auto3041   ""
#define xx__Auto3041   ""
#define en_Auto3042   "Text Size"
#define fr_Auto3042   "Taille"
#define it_Auto3042   "Text Size"
#define es_Auto3042   "Text Size"
#define de_Auto3042   "Text Size"
#define nl_Auto3042   "Text Size"
#define pt_Auto3042   "Text Size"
#define xx_Auto3042   "Text Size"
#define en__Auto3042   ""
#define fr__Auto3042   ""
#define it__Auto3042   ""
#define es__Auto3042   ""
#define de__Auto3042   ""
#define nl__Auto3042   ""
#define pt__Auto3042   ""
#define xx__Auto3042   ""
#define en_Auto3043   "ok.gif"
#define fr_Auto3043   "ok.gif"
#define it_Auto3043   "ok.gif"
#define es_Auto3043   "ok.gif"
#define de_Auto3043   "ok.gif"
#define nl_Auto3043   "ok.gif"
#define pt_Auto3043   "ok.gif"
#define xx_Auto3043   "ok.gif"
#define en__Auto3043   ""
#define fr__Auto3043   ""
#define it__Auto3043   ""
#define es__Auto3043   ""
#define de__Auto3043   ""
#define nl__Auto3043   ""
#define pt__Auto3043   ""
#define xx__Auto3043   ""
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"

private struct accept_html_production_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3033[8];
	char * hint_Auto3033[8];
	int	x_Auto3033;
	int	y_Auto3033;
	int	w_Auto3033;
	int	h_Auto3033;
	char * hint_Auto3034[8];
	char * hint_Auto3035[8];
	char * hint_Auto3036[8];
	char * msg_Auto3037[8];
	char * hint_Auto3037[8];
	char * msg_Auto3038[8];
	char * hint_Auto3038[8];
	char * hint_HtmlFileName[8];
	char	buffer_HtmlFileName[256];
	char * msg_EditHtml[8];
	int	trigger_EditHtml;
	char * hint_EditHtml[8];
	char * msg_EditStyle[8];
	int	trigger_EditStyle;
	char * hint_EditStyle[8];
	char * hint_Title[8];
	char	buffer_Title[256];
	char * hint_StyleFileName[8];
	char	buffer_StyleFileName[256];
	char * msg_Metrics[8];
	char * hint_Metrics[8];
	int	value_Metrics;
	char * msg_Points[8];
	char * hint_Points[8];
	int	value_Points;
	char * msg_WebAgent[8];
	int	trigger_WebAgent;
	char * hint_WebAgent[8];
	int	value_WebAgent;
	char * msg_Translation[8];
	int	trigger_Translation;
	char * hint_Translation[8];
	int	value_Translation;
	char * msg_Restrict[8];
	int	trigger_Restrict;
	char * hint_Restrict[8];
	int	value_Restrict;
	char * msg_Contextual[8];
	int	trigger_Contextual;
	char * hint_Contextual[8];
	int	value_Contextual;
	char * msg_ActiveImage[8];
	int	trigger_ActiveImage;
	char * hint_ActiveImage[8];
	int	value_ActiveImage;
	char * msg_iQuality[8];
	int	trigger_iQuality;
	char * hint_iQuality[8];
	int	value_iQuality;
	char * msg_iCookie[8];
	int	trigger_iCookie;
	char * hint_iCookie[8];
	int	value_iCookie;
	char * msg_Auto3039[8];
	char * hint_Auto3039[8];
	char * msg_Auto3040[8];
	char * hint_Auto3040[8];
	char * msg_Auto3041[8];
	char * hint_Auto3041[8];
	char * msg_Auto3042[8];
	char * hint_Auto3042[8];
	char * msg_Auto3043[8];
	int	trigger_Auto3043;
	char * hint_Auto3043[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[13];
	};
static int	vfh[16];

public	int	accept_html_production_create(
	struct accept_html_production_context ** cptr,
	char * pHtmlFileName,
	char * pTitle,
	char * pStyleFileName,
	char * pMetrics,
	char * pPoints,
	char * pWebAgent,
	char * pTranslation,
	char * pRestrict,
	char * pContextual,
	char * pActiveImage,
	char * piQuality,
	char * piCookie)
{

	int i;
	struct accept_html_production_context * _Context=(struct accept_html_production_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_html_production_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=17;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSWSWWWWWSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_HtmlFileName, 255, pHtmlFileName);
		visual_transferin(_Context->buffer_Title, 255, pTitle);
		visual_transferin(_Context->buffer_StyleFileName, 255, pStyleFileName);
		visual_transferin((void *) 0, 0, pMetrics);
		if (!( pMetrics )) _Context->value_Metrics=0;
		else	_Context->value_Metrics = *((int *)pMetrics);
		visual_transferin((void *) 0, 0, pPoints);
		if (!( pPoints )) _Context->value_Points=0;
		else	_Context->value_Points = *((int *)pPoints);
		visual_transferin((void *) 0, 0, pWebAgent);
		if (!( pWebAgent )) _Context->value_WebAgent=0;
		else	_Context->value_WebAgent = *((int *)pWebAgent);
		visual_transferin((void *) 0, 0, pTranslation);
		if (!( pTranslation )) _Context->value_Translation=0;
		else	_Context->value_Translation = *((int *)pTranslation);
		visual_transferin((void *) 0, 0, pRestrict);
		if (!( pRestrict )) _Context->value_Restrict=0;
		else	_Context->value_Restrict = *((int *)pRestrict);
		visual_transferin((void *) 0, 0, pContextual);
		if (!( pContextual )) _Context->value_Contextual=0;
		else	_Context->value_Contextual = *((int *)pContextual);
		visual_transferin((void *) 0, 0, pActiveImage);
		if (!( pActiveImage )) _Context->value_ActiveImage=0;
		else	_Context->value_ActiveImage = *((int *)pActiveImage);
		visual_transferin((void *) 0, 0, piQuality);
		if (!( piQuality )) _Context->value_iQuality=0;
		else	_Context->value_iQuality = *((int *)piQuality);
		visual_transferin((void *) 0, 0, piCookie);
		if (!( piCookie )) _Context->value_iCookie=0;
		else	_Context->value_iCookie = *((int *)piCookie);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3033[i]=" ";
	_Context->hint_Auto3033[0]=en__Auto3033;
	_Context->hint_Auto3033[1]=fr__Auto3033;
	_Context->hint_Auto3033[2]=it__Auto3033;
	_Context->hint_Auto3033[3]=es__Auto3033;
	_Context->hint_Auto3033[4]=de__Auto3033;
	_Context->hint_Auto3033[5]=nl__Auto3033;
	_Context->hint_Auto3033[6]=pt__Auto3033;
	_Context->hint_Auto3033[7]=xx__Auto3033;
	_Context->x_Auto3033=80;
	_Context->y_Auto3033=95;
	_Context->w_Auto3033=640;
	_Context->h_Auto3033=410;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3037[i]=" ";
	_Context->msg_Auto3037[0]=en_Auto3037;
	_Context->msg_Auto3037[1]=fr_Auto3037;
	_Context->msg_Auto3037[2]=it_Auto3037;
	_Context->msg_Auto3037[3]=es_Auto3037;
	_Context->msg_Auto3037[4]=de_Auto3037;
	_Context->msg_Auto3037[5]=nl_Auto3037;
	_Context->msg_Auto3037[6]=pt_Auto3037;
	_Context->msg_Auto3037[7]=xx_Auto3037;
	_Context->hint_Auto3037[0]=en__Auto3037;
	_Context->hint_Auto3037[1]=fr__Auto3037;
	_Context->hint_Auto3037[2]=it__Auto3037;
	_Context->hint_Auto3037[3]=es__Auto3037;
	_Context->hint_Auto3037[4]=de__Auto3037;
	_Context->hint_Auto3037[5]=nl__Auto3037;
	_Context->hint_Auto3037[6]=pt__Auto3037;
	_Context->hint_Auto3037[7]=xx__Auto3037;
	for (i=0; i < 8; i++)_Context->msg_Auto3038[i]=" ";
	_Context->msg_Auto3038[0]=en_Auto3038;
	_Context->msg_Auto3038[1]=fr_Auto3038;
	_Context->msg_Auto3038[2]=it_Auto3038;
	_Context->msg_Auto3038[3]=es_Auto3038;
	_Context->msg_Auto3038[4]=de_Auto3038;
	_Context->msg_Auto3038[5]=nl_Auto3038;
	_Context->msg_Auto3038[6]=pt_Auto3038;
	_Context->msg_Auto3038[7]=xx_Auto3038;
	_Context->hint_Auto3038[0]=en__Auto3038;
	_Context->hint_Auto3038[1]=fr__Auto3038;
	_Context->hint_Auto3038[2]=it__Auto3038;
	_Context->hint_Auto3038[3]=es__Auto3038;
	_Context->hint_Auto3038[4]=de__Auto3038;
	_Context->hint_Auto3038[5]=nl__Auto3038;
	_Context->hint_Auto3038[6]=pt__Auto3038;
	_Context->hint_Auto3038[7]=xx__Auto3038;
	_Context->hint_HtmlFileName[0]=en__HtmlFileName;
	for (i=0; i < 8; i++)_Context->msg_EditHtml[i]=" ";
	_Context->msg_EditHtml[0]=en_EditHtml;
	_Context->msg_EditHtml[1]=fr_EditHtml;
	_Context->msg_EditHtml[2]=it_EditHtml;
	_Context->msg_EditHtml[3]=es_EditHtml;
	_Context->msg_EditHtml[4]=de_EditHtml;
	_Context->msg_EditHtml[5]=nl_EditHtml;
	_Context->msg_EditHtml[6]=pt_EditHtml;
	_Context->msg_EditHtml[7]=xx_EditHtml;
	_Context->hint_EditHtml[0]=en__EditHtml;
	_Context->hint_EditHtml[1]=fr__EditHtml;
	_Context->hint_EditHtml[2]=it__EditHtml;
	_Context->hint_EditHtml[3]=es__EditHtml;
	_Context->hint_EditHtml[4]=de__EditHtml;
	_Context->hint_EditHtml[5]=nl__EditHtml;
	_Context->hint_EditHtml[6]=pt__EditHtml;
	_Context->hint_EditHtml[7]=xx__EditHtml;
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
	_Context->hint_Title[0]=en__Title;
	for (i=0; i < 8; i++)_Context->msg_Metrics[i]=" ";
	_Context->msg_Metrics[0]=en_Metrics;
	_Context->msg_Metrics[1]=fr_Metrics;
	_Context->msg_Metrics[2]=it_Metrics;
	_Context->msg_Metrics[3]=es_Metrics;
	_Context->msg_Metrics[4]=de_Metrics;
	_Context->msg_Metrics[5]=nl_Metrics;
	_Context->msg_Metrics[6]=pt_Metrics;
	_Context->msg_Metrics[7]=xx_Metrics;
	_Context->hint_Metrics[0]=en__Metrics;
	_Context->hint_Metrics[1]=fr__Metrics;
	_Context->hint_Metrics[2]=it__Metrics;
	_Context->hint_Metrics[3]=es__Metrics;
	_Context->hint_Metrics[4]=de__Metrics;
	_Context->hint_Metrics[5]=nl__Metrics;
	_Context->hint_Metrics[6]=pt__Metrics;
	_Context->hint_Metrics[7]=xx__Metrics;
	for (i=0; i < 8; i++)_Context->msg_Points[i]=" ";
	_Context->msg_Points[0]=en_Points;
	_Context->msg_Points[1]=fr_Points;
	_Context->msg_Points[2]=it_Points;
	_Context->msg_Points[3]=es_Points;
	_Context->msg_Points[4]=de_Points;
	_Context->msg_Points[5]=nl_Points;
	_Context->msg_Points[6]=pt_Points;
	_Context->msg_Points[7]=xx_Points;
	_Context->hint_Points[0]=en__Points;
	for (i=0; i < 8; i++)_Context->msg_WebAgent[i]=" ";
	_Context->msg_WebAgent[0]=en_WebAgent;
	_Context->msg_WebAgent[1]=fr_WebAgent;
	_Context->msg_WebAgent[2]=it_WebAgent;
	_Context->msg_WebAgent[3]=es_WebAgent;
	_Context->msg_WebAgent[4]=de_WebAgent;
	_Context->msg_WebAgent[5]=nl_WebAgent;
	_Context->msg_WebAgent[6]=pt_WebAgent;
	_Context->msg_WebAgent[7]=xx_WebAgent;
	_Context->hint_WebAgent[0]=en__WebAgent;
	_Context->hint_WebAgent[1]=fr__WebAgent;
	_Context->hint_WebAgent[2]=it__WebAgent;
	_Context->hint_WebAgent[3]=es__WebAgent;
	_Context->hint_WebAgent[4]=de__WebAgent;
	_Context->hint_WebAgent[5]=nl__WebAgent;
	_Context->hint_WebAgent[6]=pt__WebAgent;
	_Context->hint_WebAgent[7]=xx__WebAgent;
	for (i=0; i < 8; i++)_Context->msg_Translation[i]=" ";
	_Context->msg_Translation[0]=en_Translation;
	_Context->msg_Translation[1]=fr_Translation;
	_Context->msg_Translation[2]=it_Translation;
	_Context->msg_Translation[3]=es_Translation;
	_Context->msg_Translation[4]=de_Translation;
	_Context->msg_Translation[5]=nl_Translation;
	_Context->msg_Translation[6]=pt_Translation;
	_Context->msg_Translation[7]=xx_Translation;
	_Context->hint_Translation[0]=en__Translation;
	_Context->hint_Translation[1]=fr__Translation;
	_Context->hint_Translation[2]=it__Translation;
	_Context->hint_Translation[3]=es__Translation;
	_Context->hint_Translation[4]=de__Translation;
	_Context->hint_Translation[5]=nl__Translation;
	_Context->hint_Translation[6]=pt__Translation;
	_Context->hint_Translation[7]=xx__Translation;
	for (i=0; i < 8; i++)_Context->msg_Restrict[i]=" ";
	_Context->msg_Restrict[0]=en_Restrict;
	_Context->msg_Restrict[1]=fr_Restrict;
	_Context->msg_Restrict[2]=it_Restrict;
	_Context->msg_Restrict[3]=es_Restrict;
	_Context->msg_Restrict[4]=de_Restrict;
	_Context->msg_Restrict[5]=nl_Restrict;
	_Context->msg_Restrict[6]=pt_Restrict;
	_Context->msg_Restrict[7]=xx_Restrict;
	_Context->hint_Restrict[0]=en__Restrict;
	_Context->hint_Restrict[1]=fr__Restrict;
	_Context->hint_Restrict[2]=it__Restrict;
	_Context->hint_Restrict[3]=es__Restrict;
	_Context->hint_Restrict[4]=de__Restrict;
	_Context->hint_Restrict[5]=nl__Restrict;
	_Context->hint_Restrict[6]=pt__Restrict;
	_Context->hint_Restrict[7]=xx__Restrict;
	for (i=0; i < 8; i++)_Context->msg_Contextual[i]=" ";
	_Context->msg_Contextual[0]=en_Contextual;
	_Context->msg_Contextual[1]=fr_Contextual;
	_Context->msg_Contextual[2]=it_Contextual;
	_Context->msg_Contextual[3]=es_Contextual;
	_Context->msg_Contextual[4]=de_Contextual;
	_Context->msg_Contextual[5]=nl_Contextual;
	_Context->msg_Contextual[6]=pt_Contextual;
	_Context->msg_Contextual[7]=xx_Contextual;
	_Context->hint_Contextual[0]=en__Contextual;
	_Context->hint_Contextual[1]=fr__Contextual;
	_Context->hint_Contextual[2]=it__Contextual;
	_Context->hint_Contextual[3]=es__Contextual;
	_Context->hint_Contextual[4]=de__Contextual;
	_Context->hint_Contextual[5]=nl__Contextual;
	_Context->hint_Contextual[6]=pt__Contextual;
	_Context->hint_Contextual[7]=xx__Contextual;
	for (i=0; i < 8; i++)_Context->msg_ActiveImage[i]=" ";
	_Context->msg_ActiveImage[0]=en_ActiveImage;
	_Context->msg_ActiveImage[1]=fr_ActiveImage;
	_Context->msg_ActiveImage[2]=it_ActiveImage;
	_Context->msg_ActiveImage[3]=es_ActiveImage;
	_Context->msg_ActiveImage[4]=de_ActiveImage;
	_Context->msg_ActiveImage[5]=nl_ActiveImage;
	_Context->msg_ActiveImage[6]=pt_ActiveImage;
	_Context->msg_ActiveImage[7]=xx_ActiveImage;
	_Context->hint_ActiveImage[0]=en__ActiveImage;
	_Context->hint_ActiveImage[1]=fr__ActiveImage;
	_Context->hint_ActiveImage[2]=it__ActiveImage;
	_Context->hint_ActiveImage[3]=es__ActiveImage;
	_Context->hint_ActiveImage[4]=de__ActiveImage;
	_Context->hint_ActiveImage[5]=nl__ActiveImage;
	_Context->hint_ActiveImage[6]=pt__ActiveImage;
	_Context->hint_ActiveImage[7]=xx__ActiveImage;
	for (i=0; i < 8; i++)_Context->msg_iQuality[i]=" ";
	_Context->msg_iQuality[0]=en_iQuality;
	_Context->msg_iQuality[1]=fr_iQuality;
	_Context->msg_iQuality[2]=it_iQuality;
	_Context->msg_iQuality[3]=es_iQuality;
	_Context->msg_iQuality[4]=de_iQuality;
	_Context->msg_iQuality[5]=nl_iQuality;
	_Context->msg_iQuality[6]=pt_iQuality;
	_Context->msg_iQuality[7]=xx_iQuality;
	_Context->hint_iQuality[0]=en__iQuality;
	_Context->hint_iQuality[1]=fr__iQuality;
	_Context->hint_iQuality[2]=it__iQuality;
	_Context->hint_iQuality[3]=es__iQuality;
	_Context->hint_iQuality[4]=de__iQuality;
	_Context->hint_iQuality[5]=nl__iQuality;
	_Context->hint_iQuality[6]=pt__iQuality;
	_Context->hint_iQuality[7]=xx__iQuality;
	for (i=0; i < 8; i++)_Context->msg_iCookie[i]=" ";
	_Context->msg_iCookie[0]=en_iCookie;
	_Context->msg_iCookie[1]=fr_iCookie;
	_Context->msg_iCookie[2]=it_iCookie;
	_Context->msg_iCookie[3]=es_iCookie;
	_Context->msg_iCookie[4]=de_iCookie;
	_Context->msg_iCookie[5]=nl_iCookie;
	_Context->msg_iCookie[6]=pt_iCookie;
	_Context->msg_iCookie[7]=xx_iCookie;
	_Context->hint_iCookie[0]=en__iCookie;
	_Context->hint_iCookie[1]=fr__iCookie;
	_Context->hint_iCookie[2]=it__iCookie;
	_Context->hint_iCookie[3]=es__iCookie;
	_Context->hint_iCookie[4]=de__iCookie;
	_Context->hint_iCookie[5]=nl__iCookie;
	_Context->hint_iCookie[6]=pt__iCookie;
	_Context->hint_iCookie[7]=xx__iCookie;
	for (i=0; i < 8; i++)_Context->msg_Auto3039[i]=" ";
	_Context->msg_Auto3039[0]=en_Auto3039;
	_Context->msg_Auto3039[1]=fr_Auto3039;
	_Context->msg_Auto3039[2]=it_Auto3039;
	_Context->msg_Auto3039[3]=es_Auto3039;
	_Context->msg_Auto3039[4]=de_Auto3039;
	_Context->msg_Auto3039[5]=nl_Auto3039;
	_Context->msg_Auto3039[6]=pt_Auto3039;
	_Context->msg_Auto3039[7]=xx_Auto3039;
	_Context->hint_Auto3039[0]=en__Auto3039;
	_Context->hint_Auto3039[1]=fr__Auto3039;
	_Context->hint_Auto3039[2]=it__Auto3039;
	_Context->hint_Auto3039[3]=es__Auto3039;
	_Context->hint_Auto3039[4]=de__Auto3039;
	_Context->hint_Auto3039[5]=nl__Auto3039;
	_Context->hint_Auto3039[6]=pt__Auto3039;
	_Context->hint_Auto3039[7]=xx__Auto3039;
	for (i=0; i < 8; i++)_Context->msg_Auto3040[i]=" ";
	_Context->msg_Auto3040[0]=en_Auto3040;
	_Context->msg_Auto3040[1]=fr_Auto3040;
	_Context->msg_Auto3040[2]=it_Auto3040;
	_Context->msg_Auto3040[3]=es_Auto3040;
	_Context->msg_Auto3040[4]=de_Auto3040;
	_Context->msg_Auto3040[5]=nl_Auto3040;
	_Context->msg_Auto3040[6]=pt_Auto3040;
	_Context->msg_Auto3040[7]=xx_Auto3040;
	_Context->hint_Auto3040[0]=en__Auto3040;
	_Context->hint_Auto3040[1]=fr__Auto3040;
	_Context->hint_Auto3040[2]=it__Auto3040;
	_Context->hint_Auto3040[3]=es__Auto3040;
	_Context->hint_Auto3040[4]=de__Auto3040;
	_Context->hint_Auto3040[5]=nl__Auto3040;
	_Context->hint_Auto3040[6]=pt__Auto3040;
	_Context->hint_Auto3040[7]=xx__Auto3040;
	for (i=0; i < 8; i++)_Context->msg_Auto3041[i]=" ";
	_Context->msg_Auto3041[0]=en_Auto3041;
	_Context->msg_Auto3041[1]=fr_Auto3041;
	_Context->msg_Auto3041[2]=it_Auto3041;
	_Context->msg_Auto3041[3]=es_Auto3041;
	_Context->msg_Auto3041[4]=de_Auto3041;
	_Context->msg_Auto3041[5]=nl_Auto3041;
	_Context->msg_Auto3041[6]=pt_Auto3041;
	_Context->msg_Auto3041[7]=xx_Auto3041;
	_Context->hint_Auto3041[0]=en__Auto3041;
	_Context->hint_Auto3041[1]=fr__Auto3041;
	_Context->hint_Auto3041[2]=it__Auto3041;
	_Context->hint_Auto3041[3]=es__Auto3041;
	_Context->hint_Auto3041[4]=de__Auto3041;
	_Context->hint_Auto3041[5]=nl__Auto3041;
	_Context->hint_Auto3041[6]=pt__Auto3041;
	_Context->hint_Auto3041[7]=xx__Auto3041;
	for (i=0; i < 8; i++)_Context->msg_Auto3042[i]=" ";
	_Context->msg_Auto3042[0]=en_Auto3042;
	_Context->msg_Auto3042[1]=fr_Auto3042;
	_Context->msg_Auto3042[2]=it_Auto3042;
	_Context->msg_Auto3042[3]=es_Auto3042;
	_Context->msg_Auto3042[4]=de_Auto3042;
	_Context->msg_Auto3042[5]=nl_Auto3042;
	_Context->msg_Auto3042[6]=pt_Auto3042;
	_Context->msg_Auto3042[7]=xx_Auto3042;
	_Context->hint_Auto3042[0]=en__Auto3042;
	_Context->hint_Auto3042[1]=fr__Auto3042;
	_Context->hint_Auto3042[2]=it__Auto3042;
	_Context->hint_Auto3042[3]=es__Auto3042;
	_Context->hint_Auto3042[4]=de__Auto3042;
	_Context->hint_Auto3042[5]=nl__Auto3042;
	_Context->hint_Auto3042[6]=pt__Auto3042;
	_Context->hint_Auto3042[7]=xx__Auto3042;
	for (i=0; i < 8; i++)_Context->msg_Auto3043[i]=" ";
	_Context->msg_Auto3043[0]=en_Auto3043;
	_Context->msg_Auto3043[1]=fr_Auto3043;
	_Context->msg_Auto3043[2]=it_Auto3043;
	_Context->msg_Auto3043[3]=es_Auto3043;
	_Context->msg_Auto3043[4]=de_Auto3043;
	_Context->msg_Auto3043[5]=nl_Auto3043;
	_Context->msg_Auto3043[6]=pt_Auto3043;
	_Context->msg_Auto3043[7]=xx_Auto3043;
	_Context->hint_Auto3043[0]=en__Auto3043;
	_Context->hint_Auto3043[1]=fr__Auto3043;
	_Context->hint_Auto3043[2]=it__Auto3043;
	_Context->hint_Auto3043[3]=es__Auto3043;
	_Context->hint_Auto3043[4]=de__Auto3043;
	_Context->hint_Auto3043[5]=nl__Auto3043;
	_Context->hint_Auto3043[6]=pt__Auto3043;
	_Context->hint_Auto3043[7]=xx__Auto3043;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->msg_Cancel[2]=it_Cancel;
	_Context->msg_Cancel[3]=es_Cancel;
	_Context->msg_Cancel[4]=de_Cancel;
	_Context->msg_Cancel[5]=nl_Cancel;
	_Context->msg_Cancel[6]=pt_Cancel;
	_Context->msg_Cancel[7]=xx_Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3033,_Context->y_Auto3033,640+10,410+10);
	return(0);
}

public 	int	accept_html_production_hide(struct accept_html_production_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3033,_Context->y_Auto3033);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_html_production_remove(
	struct accept_html_production_context * _Context,
	char * pHtmlFileName,
	char * pTitle,
	char * pStyleFileName,
	char * pMetrics,
	char * pPoints,
	char * pWebAgent,
	char * pTranslation,
	char * pRestrict,
	char * pContextual,
	char * pActiveImage,
	char * piQuality,
	char * piCookie)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSWSWWWWWSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_HtmlFileName, 255, pHtmlFileName);
		visual_transferout(_Context->buffer_Title, 255, pTitle);
		visual_transferout(_Context->buffer_StyleFileName, 255, pStyleFileName);
		visual_transferout((void *) 0, 0, pMetrics);
		if ( pMetrics != (char *) 0)
			*((int*)pMetrics) = _Context->value_Metrics;
		visual_transferout((void *) 0, 0, pPoints);
		if ( pPoints != (char *) 0)
			*((int*)pPoints) = _Context->value_Points;
		visual_transferout((void *) 0, 0, pWebAgent);
		if ( pWebAgent != (char *) 0)
			*((int*)pWebAgent) = _Context->value_WebAgent;
		visual_transferout((void *) 0, 0, pTranslation);
		if ( pTranslation != (char *) 0)
			*((int*)pTranslation) = _Context->value_Translation;
		visual_transferout((void *) 0, 0, pRestrict);
		if ( pRestrict != (char *) 0)
			*((int*)pRestrict) = _Context->value_Restrict;
		visual_transferout((void *) 0, 0, pContextual);
		if ( pContextual != (char *) 0)
			*((int*)pContextual) = _Context->value_Contextual;
		visual_transferout((void *) 0, 0, pActiveImage);
		if ( pActiveImage != (char *) 0)
			*((int*)pActiveImage) = _Context->value_ActiveImage;
		visual_transferout((void *) 0, 0, piQuality);
		if ( piQuality != (char *) 0)
			*((int*)piQuality) = _Context->value_iQuality;
		visual_transferout((void *) 0, 0, piCookie);
		if ( piCookie != (char *) 0)
			*((int*)piCookie) = _Context->value_iCookie;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_html_production_show(struct accept_html_production_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3033,_Context->y_Auto3033);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3033,_Context->y_Auto3033,640,410,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3033,_Context->y_Auto3033,640,410,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_frame(_Context->x_Auto3033+110,_Context->y_Auto3033+210,430,180,4);
	visual_frame(_Context->x_Auto3033+600,_Context->y_Auto3033+100,20,20,2);
	visual_frame(_Context->x_Auto3033+600,_Context->y_Auto3033+178,20,20,2);
	visual_text(_Context->x_Auto3033+20,_Context->y_Auto3033+40,610,30,vfh[3],16,0,_Context->msg_Auto3037[_Context->language],strlen(_Context->msg_Auto3037[_Context->language]),1283);
	visual_text(_Context->x_Auto3033+30,_Context->y_Auto3033+80,560,16,vfh[2],16,0,_Context->msg_Auto3038[_Context->language],strlen(_Context->msg_Auto3038[_Context->language]),258);
	visual_frame(_Context->x_Auto3033+30,_Context->y_Auto3033+100,568+2,16+2,5);
	visual_text(_Context->x_Auto3033+30+1,_Context->y_Auto3033+100+1,568,16,vfh[1],16,0,_Context->buffer_HtmlFileName,255,0);
	_Context->trigger_EditHtml=visual_trigger_code(_Context->msg_EditHtml[_Context->language],strlen(_Context->msg_EditHtml[_Context->language]));
	visual_button(_Context->x_Auto3033+602,_Context->y_Auto3033+102,16,16,vfh[8],27,28,_Context->msg_EditHtml[_Context->language],strlen(_Context->msg_EditHtml[_Context->language]),768);
	_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
	visual_button(_Context->x_Auto3033+602,_Context->y_Auto3033+180,16,16,vfh[8],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),768);
	visual_frame(_Context->x_Auto3033+30,_Context->y_Auto3033+140,584+2,16+2,5);
	visual_text(_Context->x_Auto3033+30+1,_Context->y_Auto3033+140+1,584,16,vfh[1],16,0,_Context->buffer_Title,255,0);
	visual_frame(_Context->x_Auto3033+30,_Context->y_Auto3033+180,568+2,16+2,5);
	visual_text(_Context->x_Auto3033+30+1,_Context->y_Auto3033+180+1,568,16,vfh[1],16,0,_Context->buffer_StyleFileName,255,0);
	visual_select(_Context->x_Auto3033+410,_Context->y_Auto3033+310,112,48,vfh[2],16,0,parse_selection(_Context->msg_Metrics[_Context->language],&_Context->value_Metrics),768);
	visual_select(_Context->x_Auto3033+410,_Context->y_Auto3033+360,112,64,vfh[2],0,0,parse_selection(_Context->msg_Points[_Context->language],&_Context->value_Points),768);
	_Context->trigger_WebAgent=visual_trigger_code(_Context->msg_WebAgent[_Context->language],strlen(_Context->msg_WebAgent[_Context->language]));
	visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+220,252,16,vfh[2],16,0,_Context->msg_WebAgent[_Context->language],strlen(_Context->msg_WebAgent[_Context->language]),_Context->value_WebAgent|0);
	_Context->trigger_Translation=visual_trigger_code(_Context->msg_Translation[_Context->language],strlen(_Context->msg_Translation[_Context->language]));
	visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+240,252,16,vfh[2],16,0,_Context->msg_Translation[_Context->language],strlen(_Context->msg_Translation[_Context->language]),_Context->value_Translation|0);
	_Context->trigger_Restrict=visual_trigger_code(_Context->msg_Restrict[_Context->language],strlen(_Context->msg_Restrict[_Context->language]));
	visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+270,271,16,vfh[2],16,0,_Context->msg_Restrict[_Context->language],strlen(_Context->msg_Restrict[_Context->language]),_Context->value_Restrict|0);
	_Context->trigger_Contextual=visual_trigger_code(_Context->msg_Contextual[_Context->language],strlen(_Context->msg_Contextual[_Context->language]));
	visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+290,266,16,vfh[2],16,0,_Context->msg_Contextual[_Context->language],strlen(_Context->msg_Contextual[_Context->language]),_Context->value_Contextual|0);
	_Context->trigger_ActiveImage=visual_trigger_code(_Context->msg_ActiveImage[_Context->language],strlen(_Context->msg_ActiveImage[_Context->language]));
	visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+320,252,16,vfh[2],16,0,_Context->msg_ActiveImage[_Context->language],strlen(_Context->msg_ActiveImage[_Context->language]),_Context->value_ActiveImage|0);
	_Context->trigger_iQuality=visual_trigger_code(_Context->msg_iQuality[_Context->language],strlen(_Context->msg_iQuality[_Context->language]));
	visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+340,252,16,vfh[2],0,0,_Context->msg_iQuality[_Context->language],strlen(_Context->msg_iQuality[_Context->language]),_Context->value_iQuality|0);
	_Context->trigger_iCookie=visual_trigger_code(_Context->msg_iCookie[_Context->language],strlen(_Context->msg_iCookie[_Context->language]));
	visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+360,252,16,vfh[2],0,0,_Context->msg_iCookie[_Context->language],strlen(_Context->msg_iCookie[_Context->language]),_Context->value_iCookie|0);
	visual_text(_Context->x_Auto3033+30,_Context->y_Auto3033+120,200,20,vfh[2],16,0,_Context->msg_Auto3039[_Context->language],strlen(_Context->msg_Auto3039[_Context->language]),258);
	visual_text(_Context->x_Auto3033+30,_Context->y_Auto3033+160,200,20,vfh[2],16,0,_Context->msg_Auto3040[_Context->language],strlen(_Context->msg_Auto3040[_Context->language]),258);
	visual_text(_Context->x_Auto3033+410,_Context->y_Auto3033+290,112,16,vfh[2],16,0,_Context->msg_Auto3041[_Context->language],strlen(_Context->msg_Auto3041[_Context->language]),259);
	visual_text(_Context->x_Auto3033+410,_Context->y_Auto3033+340,112,16,vfh[2],16,0,_Context->msg_Auto3042[_Context->language],strlen(_Context->msg_Auto3042[_Context->language]),259);
	_Context->trigger_Auto3043=visual_trigger_code(_Context->msg_Auto3043[_Context->language],strlen(_Context->msg_Auto3043[_Context->language]));
	visual_button(_Context->x_Auto3033+30,_Context->y_Auto3033+340,56,48,vfh[2],34,0,_Context->msg_Auto3043[_Context->language],strlen(_Context->msg_Auto3043[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3033+560,_Context->y_Auto3033+340,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3033,_Context->y_Auto3033,640,410);

	return(0);
}

private int HtmlFileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[9];
			mptr[0] = " ";
			mptr[1]=" This edit fields presents and accepts the full path and filename ";
			mptr[2]="of the target file to which output will be written by the html generation ";
			mptr[3]="mechanisms.  ";
			mptr[4]=" ";
			mptr[5]=" This filename will be used to generate individual html filesnames ";
			mptr[6]="for multiple language productionand for multiple tab page systems. ";
			mptr[7]=" ";
			mptr[8]="   ";
			return(visual_online_help(mptr,9));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int EditHtml_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The html production file may be opened for inspection activetool the standard ";
			mptr[1]="editor by pressing on this button.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int EditStyle_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The style sheet file may be opened for inspection activetool the standard ";
			mptr[1]="editor by pressing on this button.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Title_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "A value specified in this edit field will be used as the title of ";
			mptr[1]="the html document.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int StyleFileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows the name of an external style sheet to be specified. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Metrics_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "Here you may select the html production metrics as required by your ";
			mptr[1]="documents. These may be measured in pixesl, points, millimetres or ";
			mptr[2]="inches.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Points_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "Here you may establish the default scale required to be applied to ";
			mptr[1]="the coordinates of  your documents. The scale of 10 represents unity ";
			mptr[2]="dimensions or 100 percent, whilst the scale of 20 represents a 200 ";
			mptr[3]="percent enlargement.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int WebAgent_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[8];
			mptr[0] = " ";
			mptr[1]=" This check control when selected activates production of the wasa ";
			mptr[2]=" compatible web agent comprising source production, translation and ";
			mptr[3]="eventual linking.  ";
			mptr[4]=" ";
			mptr[5]=" It this option is uncheck then the web agent will not be rebuilt, ";
			mptr[6]="the web pages and images will however be regenerated.  ";
			mptr[7]="    ";
			return(visual_online_help(mptr,8));
			}
			break;
		case 1 : 
			{
			char * mptr[9];
			mptr[0] = " ";
			mptr[1]=" Lorsque ce checkbox est active il y aura production d'une agent web ";
			mptr[2]="compatible avec les mecanismes de gestion d'agents web de WASP et ";
			mptr[3]="WASA. Ceci comprends la generation d'une source ABAL suivi par traduction ";
			mptr[4]="et linkage eventuelle.  ";
			mptr[5]=" ";
			mptr[6]=" Si ce checkbox n'est active il n y aura production que des pages ";
			mptr[7]="html et des images.  ";
			mptr[8]="   ";
			return(visual_online_help(mptr,9));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Translation_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[15];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" The three stage production cycle involves the generation of the various ";
			mptr[3]=" source files, images and scripts followed by source translation then ";
			mptr[4]=" object linking .  ";
			mptr[5]=" ";
			mptr[6]=" This check control when selected allows both translation and link ";
			mptr[7]="phases of the  web agent post production cycle to proceed without ";
			mptr[8]="user intervention.  ";
			mptr[9]=" ";
			mptr[10]=" When unchecked the corresponding dialog frames will be presented ";
			mptr[11]="for inspection and confiration of the various post production parameters. ";
			mptr[12]=" ";
			mptr[13]=" ";
			mptr[14]="   ";
			return(visual_online_help(mptr,15));
			}
			break;
		case 1 : 
			{
			char * mptr[9];
			mptr[0] = " ";
			mptr[1]=" Lorsque ce checkbox est active il permet l'acces, pendant la generation, ";
			mptr[2]="aux boite de dialogue des etapes de production secondaires, de traduction ";
			mptr[3]="et de link pour la consultation et modification des parametres particulaires ";
			mptr[4]="a ces operations.  ";
			mptr[5]=" ";
			mptr[6]=" Sinon les operations secondaires s'enchainent sans demander confirmation ";
			mptr[7]=" de l'utilisateur.  ";
			mptr[8]="    ";
			return(visual_online_help(mptr,9));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Restrict_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[10];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" This check control when active causes javascript instructions to ";
			mptr[3]="be generated to the web agent graphical user interface web pages to ";
			mptr[4]="perform window resizing to the exact forms model dimensions.  ";
			mptr[5]=" ";
			mptr[6]=" When unchecked the web page is simply loaded into the current browser ";
			mptr[7]="window dimensions.  ";
			mptr[8]=" ";
			mptr[9]="   ";
			return(visual_online_help(mptr,10));
			}
			break;
		case 1 : 
			{
			char * mptr[9];
			mptr[0] = " ";
			mptr[1]=" Lorsque ce check box est active des instructions en javascript vont ";
			mptr[2]="estre produit dans les pages html a fin de contraindre les dimensions ";
			mptr[3]="du browser web aux dimensions exactes requises pour le composant. ";
			mptr[4]=" ";
			mptr[5]=" ";
			mptr[6]=" Sinon le page web s'afficherais dans le fenetre d'acceuil du browser ";
			mptr[7]="avec ces dimensions au moement du chargement.  ";
			mptr[8]="      ";
			return(visual_online_help(mptr,9));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Contextual_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[16];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" This check control when active causes javascript instructions to ";
			mptr[3]="be generated to the web agent graphical user interface web pages to ";
			mptr[4]="inhibit the window contextual menu from appearing when the end user ";
			mptr[5]="performs a right button mouse click in the document area.  ";
			mptr[6]=" ";
			mptr[7]=" When unchecked the web page will not inhibit this browser feature. ";
			mptr[8]=" ";
			mptr[9]=" ";
			mptr[10]=" This option may be required to enforce first level security concerning ";
			mptr[11]="sensitive information presented by the web page and is of particular ";
			mptr[12]="importance to inhibit the downloading of images present in the page. ";
			mptr[13]=" ";
			mptr[14]=" ";
			mptr[15]="    ";
			return(visual_online_help(mptr,16));
			}
			break;
		case 1 : 
			{
			char * mptr[9];
			mptr[0] = " ";
			mptr[1]=" Lorsque ce check box est active des instructions en javascript vont ";
			mptr[2]="estre produit dans les pages html a fin de contraindre les dimensions ";
			mptr[3]="du browser web aux dimensions exactes requises pour le composant. ";
			mptr[4]=" ";
			mptr[5]=" ";
			mptr[6]=" Sinon le page web s'afficherais dans le fenetre d'acceuil du browser ";
			mptr[7]="avec ces dimensions au moement du chargement.  ";
			mptr[8]="      ";
			return(visual_online_help(mptr,9));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ActiveImage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[17];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]="During the standard web agent production cycle the forms model image ";
			mptr[3]="will be generated to an image file. This image will be loaded by the ";
			mptr[4]="web browser as requested by the web agent html page.  ";
			mptr[5]=" ";
			mptr[6]="When this check control is active, web agents will regenerate forms ";
			mptr[7]="model images at each invocation of their OnResponse method prior to  processing and integration of widget data ";
			mptr[8]="into the response page. The forms image will evolve during web agent ";
			mptr[9]="operation but will require higher bandwidth for its repetitive delivery. ";
			mptr[10]=" ";
			mptr[11]=" ";
			mptr[12]="When unchecked the original forms model image will be delivered as ";
			mptr[13]="required by the web page image instructions and its delivery may eventually ";
			mptr[14]="be optimised by browser cache mechanisms.  ";
			mptr[15]=" ";
			mptr[16]="   ";
			return(visual_online_help(mptr,17));
			}
			break;
		case 1 : 
			{
			char * mptr[12];
			mptr[0] = " ";
			mptr[1]=" Pendant la cycle de production standarde d'une agent web il y a generation ";
			mptr[2]="de le program overay de l'agent, generation des pages html par langue ";
			mptr[3]="et par onglet, et generation des images de fond, aussi par langue ";
			mptr[4]="national et par onglet.  ";
			mptr[5]=" ";
			mptr[6]=" Lorsque ce checkbox est active, la production des images de fond ";
			mptr[7]="se voit retard‚  a l'execution de l'agent web, jusque avant l'integration ";
			mptr[8]="des valeurs de retour dans la page html correspondant a l'etat d'affichage ";
			mptr[9]="actuelle. Ansi l'image de fond se trouve actualiser pour refleter ";
			mptr[10]="des aspects dynamiques de son evolution.  ";
			mptr[11]="       ";
			return(visual_online_help(mptr,12));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int iQuality_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[12];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" This check control allows JPEG image production quality to be increased ";
			mptr[3]="to the maximum of 100%. This will result in the production of much ";
			mptr[4]="larger image files that  will require higher bandwidth for efficient ";
			mptr[5]="delivery.  ";
			mptr[6]=" ";
			mptr[7]=" When unchecked JPEG image production quality will be reduced to 90% ";
			mptr[8]="which produces much smaller images of almost identical visual appearance. ";
			mptr[9]=" ";
			mptr[10]=" ";
			mptr[11]="   ";
			return(visual_online_help(mptr,12));
			}
			break;
		case 1 : 
			{
			char * mptr[9];
			mptr[0] = " ";
			mptr[1]=" Ce checkbox permet d'indique aux routine de production d'image  d'augmenter ";
			mptr[2]="au maximum la qualit‚ des images JPEG a produire. Ceci a pour effet ";
			mptr[3]="d'augmenter la taille des fichiers d'images.  ";
			mptr[4]=" ";
			mptr[5]=" Par default la qualit‚ de production d'images JPEG est reduite a ";
			mptr[6]="90% qui present une bonne compromis entre taille et qualit‚ d'image. ";
			mptr[7]=" ";
			mptr[8]="   ";
			return(visual_online_help(mptr,9));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int iCookie_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[9];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]="This check control, when active, requests that javascript instructions ";
			mptr[3]="be generated to the html web page to detect and alert the user that ";
			mptr[4]="cookies should be enabled for the correct operation of the page.  ";
			mptr[5]=" ";
			mptr[6]="When unchecked cookie aactivation detection is not generated.  ";
			mptr[7]=" ";
			mptr[8]="   ";
			return(visual_online_help(mptr,9));
			}
			break;
		case 1 : 
			{
			char * mptr[7];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" Ce checkbox, lorsque il est actif, permet d'inclure dans les pages ";
			mptr[3]="htmls  des mecanismes de verification des droits d'utilisation de ";
			mptr[4]="cookies par le browser web.  ";
			mptr[5]=" ";
			mptr[6]="     ";
			return(visual_online_help(mptr,7));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3043_help()
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

private int Auto3033action(struct accept_html_production_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_html_production_hide(_Context);

		_Context->x_Auto3033 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3033 < 0) { _Context->x_Auto3033=0; }
		_Context->y_Auto3033 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3033 < 0) { _Context->y_Auto3033=0; }
			accept_html_production_show(_Context);

		visual_thaw(_Context->x_Auto3033,_Context->y_Auto3033,640,410);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_EditHtml_event(struct accept_html_production_context * _Context) {
		accept_html_production_hide(_Context);
;
	standard_text_editor(_Context->buffer_HtmlFileName,255);
		accept_html_production_show(_Context);
;
	return(-1);
}
private int on_EditStyle_event(struct accept_html_production_context * _Context) {
		accept_html_production_hide(_Context);
;
	standard_text_editor(_Context->buffer_StyleFileName,255);
		accept_html_production_show(_Context);
;
	return(-1);
}
private int on_Auto3043_event(struct accept_html_production_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_html_production_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_html_production_event(
struct accept_html_production_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_EditHtml == mb ) return(3);
		if (_Context->trigger_EditStyle == mb ) return(4);
		if (_Context->trigger_WebAgent == mb ) return(9);
		if (_Context->trigger_Translation == mb ) return(10);
		if (_Context->trigger_Restrict == mb ) return(11);
		if (_Context->trigger_Contextual == mb ) return(12);
		if (_Context->trigger_ActiveImage == mb ) return(13);
		if (_Context->trigger_iQuality == mb ) return(14);
		if (_Context->trigger_iCookie == mb ) return(15);
		if (_Context->trigger_Auto3043 == mb ) return(16);
		if (_Context->trigger_Cancel == mb ) return(17);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3033+619) )  
	&&  (my >= (_Context->y_Auto3033+4) )  
	&&  (mx <= (_Context->x_Auto3033+636) )  
	&&  (my <= (_Context->y_Auto3033+20) )) {
		return(1);	/* Auto3033 */

		}
	if ((mx >= (_Context->x_Auto3033+603) )  
	&&  (my >= (_Context->y_Auto3033+4) )  
	&&  (mx <= (_Context->x_Auto3033+620) )  
	&&  (my <= (_Context->y_Auto3033+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vwebgen.htm");
			};
		return(-1);	/* Auto3033 */

		}
	if ((mx >= (_Context->x_Auto3033+587) )  
	&&  (my >= (_Context->y_Auto3033+4) )  
	&&  (mx <= (_Context->x_Auto3033+604) )  
	&&  (my <= (_Context->y_Auto3033+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_html_production_show(_Context);
		return(-1);	/* Auto3033 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3033+4) )  
		&&  (my >= (_Context->y_Auto3033+4) )  
		&&  (mx <= (_Context->x_Auto3033+572) )  
		&&  (my <= (_Context->y_Auto3033+20) )) {
			return( Auto3033action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3033+30) ) 
	&&  ( my >= (_Context->y_Auto3033+100) ) 
	&&  ( mx <= (_Context->x_Auto3033+30+568) ) 
	&&  ( my <= (_Context->y_Auto3033+100+16))) {
		return(2); /* HtmlFileName */
		}
	if (( mx >= (_Context->x_Auto3033+602) ) 
	&&  ( my >= (_Context->y_Auto3033+102) ) 
	&&  ( mx <= (_Context->x_Auto3033+602+16) ) 
	&&  ( my <= (_Context->y_Auto3033+102+16))) {
		return(3); /* EditHtml */
		}
	if (( mx >= (_Context->x_Auto3033+602) ) 
	&&  ( my >= (_Context->y_Auto3033+180) ) 
	&&  ( mx <= (_Context->x_Auto3033+602+16) ) 
	&&  ( my <= (_Context->y_Auto3033+180+16))) {
		return(4); /* EditStyle */
		}
	if (( mx >= (_Context->x_Auto3033+30) ) 
	&&  ( my >= (_Context->y_Auto3033+140) ) 
	&&  ( mx <= (_Context->x_Auto3033+30+584) ) 
	&&  ( my <= (_Context->y_Auto3033+140+16))) {
		return(5); /* Title */
		}
	if (( mx >= (_Context->x_Auto3033+30) ) 
	&&  ( my >= (_Context->y_Auto3033+180) ) 
	&&  ( mx <= (_Context->x_Auto3033+30+568) ) 
	&&  ( my <= (_Context->y_Auto3033+180+16))) {
		return(6); /* StyleFileName */
		}
	if (( mx >= (_Context->x_Auto3033+410+0) ) 
	&&  ( my >= (_Context->y_Auto3033+310) ) 
	&&  ( mx <= (_Context->x_Auto3033+410+112) ) 
	&&  ( my <= (_Context->y_Auto3033+310+16))) {
		return(7); /* Metrics */
		}
	if (( mx >= (_Context->x_Auto3033+410+0) ) 
	&&  ( my >= (_Context->y_Auto3033+360) ) 
	&&  ( mx <= (_Context->x_Auto3033+410+112) ) 
	&&  ( my <= (_Context->y_Auto3033+360+16))) {
		return(8); /* Points */
		}
	if (( mx >= (_Context->x_Auto3033+130) ) 
	&&  ( my >= (_Context->y_Auto3033+220) ) 
	&&  ( mx <= (_Context->x_Auto3033+130+252) ) 
	&&  ( my <= (_Context->y_Auto3033+220+16))) {
		return(9); /* WebAgent */
		}
	if (( mx >= (_Context->x_Auto3033+130) ) 
	&&  ( my >= (_Context->y_Auto3033+240) ) 
	&&  ( mx <= (_Context->x_Auto3033+130+252) ) 
	&&  ( my <= (_Context->y_Auto3033+240+16))) {
		return(10); /* Translation */
		}
	if (( mx >= (_Context->x_Auto3033+130) ) 
	&&  ( my >= (_Context->y_Auto3033+270) ) 
	&&  ( mx <= (_Context->x_Auto3033+130+271) ) 
	&&  ( my <= (_Context->y_Auto3033+270+16))) {
		return(11); /* Restrict */
		}
	if (( mx >= (_Context->x_Auto3033+130) ) 
	&&  ( my >= (_Context->y_Auto3033+290) ) 
	&&  ( mx <= (_Context->x_Auto3033+130+266) ) 
	&&  ( my <= (_Context->y_Auto3033+290+16))) {
		return(12); /* Contextual */
		}
	if (( mx >= (_Context->x_Auto3033+130) ) 
	&&  ( my >= (_Context->y_Auto3033+320) ) 
	&&  ( mx <= (_Context->x_Auto3033+130+252) ) 
	&&  ( my <= (_Context->y_Auto3033+320+16))) {
		return(13); /* ActiveImage */
		}
	if (( mx >= (_Context->x_Auto3033+130) ) 
	&&  ( my >= (_Context->y_Auto3033+340) ) 
	&&  ( mx <= (_Context->x_Auto3033+130+252) ) 
	&&  ( my <= (_Context->y_Auto3033+340+16))) {
		return(14); /* iQuality */
		}
	if (( mx >= (_Context->x_Auto3033+130) ) 
	&&  ( my >= (_Context->y_Auto3033+360) ) 
	&&  ( mx <= (_Context->x_Auto3033+130+252) ) 
	&&  ( my <= (_Context->y_Auto3033+360+16))) {
		return(15); /* iCookie */
		}
	if (( mx >= (_Context->x_Auto3033+30) ) 
	&&  ( my >= (_Context->y_Auto3033+340) ) 
	&&  ( mx <= (_Context->x_Auto3033+30+56) ) 
	&&  ( my <= (_Context->y_Auto3033+340+48))) {
		return(16); /* Auto3043 */
		}
	if (( mx >= (_Context->x_Auto3033+560) ) 
	&&  ( my >= (_Context->y_Auto3033+340) ) 
	&&  ( mx <= (_Context->x_Auto3033+560+56) ) 
	&&  ( my <= (_Context->y_Auto3033+340+48))) {
		return(17); /* Cancel */
		}

	return(-1);
}


public	int	accept_html_production_focus(struct accept_html_production_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* HtmlFileName */
				_Context->keycode = visual_edit(_Context->x_Auto3033+30+1,_Context->y_Auto3033+100+1,568,16,vfh[1],_Context->buffer_HtmlFileName,255);
			break;
			case	0x3 :
				/* EditHtml */
				_Context->trigger_EditHtml=visual_trigger_code(_Context->msg_EditHtml[_Context->language],strlen(_Context->msg_EditHtml[_Context->language]));
				visual_button(_Context->x_Auto3033+602,_Context->y_Auto3033+102,16,16,vfh[8],27,28,_Context->msg_EditHtml[_Context->language],strlen(_Context->msg_EditHtml[_Context->language]),770);
				_Context->keycode = visual_getch();
				_Context->trigger_EditHtml=visual_trigger_code(_Context->msg_EditHtml[_Context->language],strlen(_Context->msg_EditHtml[_Context->language]));
	visual_button(_Context->x_Auto3033+602,_Context->y_Auto3033+102,16,16,vfh[8],27,28,_Context->msg_EditHtml[_Context->language],strlen(_Context->msg_EditHtml[_Context->language]),768);
				break;
			case	0x4 :
				/* EditStyle */
				_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
				visual_button(_Context->x_Auto3033+602,_Context->y_Auto3033+180,16,16,vfh[8],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),770);
				_Context->keycode = visual_getch();
				_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
	visual_button(_Context->x_Auto3033+602,_Context->y_Auto3033+180,16,16,vfh[8],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),768);
				break;
			case	0x5 :
				/* Title */
				_Context->keycode = visual_edit(_Context->x_Auto3033+30+1,_Context->y_Auto3033+140+1,584,16,vfh[1],_Context->buffer_Title,255);
			break;
			case	0x6 :
				/* StyleFileName */
				_Context->keycode = visual_edit(_Context->x_Auto3033+30+1,_Context->y_Auto3033+180+1,568,16,vfh[1],_Context->buffer_StyleFileName,255);
			break;
			case	0x7 :
				/* Metrics */
				_Context->keycode = visual_select(_Context->x_Auto3033+410,_Context->y_Auto3033+310,112,48,vfh[2],16,0,parse_selection(_Context->msg_Metrics[_Context->language],&_Context->value_Metrics),770);
				break;
			case	0x8 :
				/* Points */
				_Context->keycode = visual_select(_Context->x_Auto3033+410,_Context->y_Auto3033+360,112,64,vfh[2],0,0,parse_selection(_Context->msg_Points[_Context->language],&_Context->value_Points),770);
				break;
			case	0x9 :
				/* WebAgent */
				visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+220,252,16,vfh[2],16,0,_Context->msg_WebAgent[_Context->language],strlen(_Context->msg_WebAgent[_Context->language]),(_Context->value_WebAgent |2));
				_Context->keycode = visual_getch();
				_Context->trigger_WebAgent=visual_trigger_code(_Context->msg_WebAgent[_Context->language],strlen(_Context->msg_WebAgent[_Context->language]));
	visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+220,252,16,vfh[2],16,0,_Context->msg_WebAgent[_Context->language],strlen(_Context->msg_WebAgent[_Context->language]),_Context->value_WebAgent|0);
				break;
			case	0xa :
				/* Translation */
				visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+240,252,16,vfh[2],16,0,_Context->msg_Translation[_Context->language],strlen(_Context->msg_Translation[_Context->language]),(_Context->value_Translation |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Translation=visual_trigger_code(_Context->msg_Translation[_Context->language],strlen(_Context->msg_Translation[_Context->language]));
	visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+240,252,16,vfh[2],16,0,_Context->msg_Translation[_Context->language],strlen(_Context->msg_Translation[_Context->language]),_Context->value_Translation|0);
				break;
			case	0xb :
				/* Restrict */
				visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+270,271,16,vfh[2],16,0,_Context->msg_Restrict[_Context->language],strlen(_Context->msg_Restrict[_Context->language]),(_Context->value_Restrict |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Restrict=visual_trigger_code(_Context->msg_Restrict[_Context->language],strlen(_Context->msg_Restrict[_Context->language]));
	visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+270,271,16,vfh[2],16,0,_Context->msg_Restrict[_Context->language],strlen(_Context->msg_Restrict[_Context->language]),_Context->value_Restrict|0);
				break;
			case	0xc :
				/* Contextual */
				visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+290,266,16,vfh[2],16,0,_Context->msg_Contextual[_Context->language],strlen(_Context->msg_Contextual[_Context->language]),(_Context->value_Contextual |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Contextual=visual_trigger_code(_Context->msg_Contextual[_Context->language],strlen(_Context->msg_Contextual[_Context->language]));
	visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+290,266,16,vfh[2],16,0,_Context->msg_Contextual[_Context->language],strlen(_Context->msg_Contextual[_Context->language]),_Context->value_Contextual|0);
				break;
			case	0xd :
				/* ActiveImage */
				visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+320,252,16,vfh[2],16,0,_Context->msg_ActiveImage[_Context->language],strlen(_Context->msg_ActiveImage[_Context->language]),(_Context->value_ActiveImage |2));
				_Context->keycode = visual_getch();
				_Context->trigger_ActiveImage=visual_trigger_code(_Context->msg_ActiveImage[_Context->language],strlen(_Context->msg_ActiveImage[_Context->language]));
	visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+320,252,16,vfh[2],16,0,_Context->msg_ActiveImage[_Context->language],strlen(_Context->msg_ActiveImage[_Context->language]),_Context->value_ActiveImage|0);
				break;
			case	0xe :
				/* iQuality */
				visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+340,252,16,vfh[2],0,0,_Context->msg_iQuality[_Context->language],strlen(_Context->msg_iQuality[_Context->language]),(_Context->value_iQuality |2));
				_Context->keycode = visual_getch();
				_Context->trigger_iQuality=visual_trigger_code(_Context->msg_iQuality[_Context->language],strlen(_Context->msg_iQuality[_Context->language]));
	visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+340,252,16,vfh[2],0,0,_Context->msg_iQuality[_Context->language],strlen(_Context->msg_iQuality[_Context->language]),_Context->value_iQuality|0);
				break;
			case	0xf :
				/* iCookie */
				visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+360,252,16,vfh[2],0,0,_Context->msg_iCookie[_Context->language],strlen(_Context->msg_iCookie[_Context->language]),(_Context->value_iCookie |2));
				_Context->keycode = visual_getch();
				_Context->trigger_iCookie=visual_trigger_code(_Context->msg_iCookie[_Context->language],strlen(_Context->msg_iCookie[_Context->language]));
	visual_check(_Context->x_Auto3033+130,_Context->y_Auto3033+360,252,16,vfh[2],0,0,_Context->msg_iCookie[_Context->language],strlen(_Context->msg_iCookie[_Context->language]),_Context->value_iCookie|0);
				break;
			case	0x10 :
				/* Auto3043 */
				_Context->trigger_Auto3043=visual_trigger_code(_Context->msg_Auto3043[_Context->language],strlen(_Context->msg_Auto3043[_Context->language]));
				visual_button(_Context->x_Auto3033+30,_Context->y_Auto3033+340,56,48,vfh[2],34,0,_Context->msg_Auto3043[_Context->language],strlen(_Context->msg_Auto3043[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3043=visual_trigger_code(_Context->msg_Auto3043[_Context->language],strlen(_Context->msg_Auto3043[_Context->language]));
	visual_button(_Context->x_Auto3033+30,_Context->y_Auto3033+340,56,48,vfh[2],34,0,_Context->msg_Auto3043[_Context->language],strlen(_Context->msg_Auto3043[_Context->language]),1040);
				break;
			case	0x11 :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_Auto3033+560,_Context->y_Auto3033+340,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3033+560,_Context->y_Auto3033+340,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_html_production_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=17;
			accept_html_production_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_html_production_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (HtmlFileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (EditHtml_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (EditStyle_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Title_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (StyleFileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (Metrics_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (Points_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (WebAgent_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (Translation_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Restrict_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (Contextual_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (ActiveImage_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (iQuality_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (iCookie_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (Auto3043_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (Cancel_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3033 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* HtmlFileName */
					continue;
				case	0x3 :
					/* EditHtml */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_EditHtml=visual_trigger_code(_Context->msg_EditHtml[_Context->language],strlen(_Context->msg_EditHtml[_Context->language]));
						visual_button(_Context->x_Auto3033+602,_Context->y_Auto3033+102,16,16,vfh[8],27,28,_Context->msg_EditHtml[_Context->language],strlen(_Context->msg_EditHtml[_Context->language]),770);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_EditHtml=visual_trigger_code(_Context->msg_EditHtml[_Context->language],strlen(_Context->msg_EditHtml[_Context->language]));
	visual_button(_Context->x_Auto3033+602,_Context->y_Auto3033+102,16,16,vfh[8],27,28,_Context->msg_EditHtml[_Context->language],strlen(_Context->msg_EditHtml[_Context->language]),768);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_EditHtml_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* EditStyle */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
						visual_button(_Context->x_Auto3033+602,_Context->y_Auto3033+180,16,16,vfh[8],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),770);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
	visual_button(_Context->x_Auto3033+602,_Context->y_Auto3033+180,16,16,vfh[8],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),768);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_EditStyle_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Title */
					continue;
				case	0x6 :
					/* StyleFileName */
					continue;
				case	0x7 :
					/* Metrics */
					continue;
				case	0x8 :
					/* Points */
					continue;
				case	0x9 :
					/* WebAgent */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_WebAgent += 1;
						_Context->value_WebAgent &= 1;
						}
					continue;
				case	0xa :
					/* Translation */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Translation += 1;
						_Context->value_Translation &= 1;
						}
					continue;
				case	0xb :
					/* Restrict */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Restrict += 1;
						_Context->value_Restrict &= 1;
						}
					continue;
				case	0xc :
					/* Contextual */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Contextual += 1;
						_Context->value_Contextual &= 1;
						}
					continue;
				case	0xd :
					/* ActiveImage */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ActiveImage += 1;
						_Context->value_ActiveImage &= 1;
						}
					continue;
				case	0xe :
					/* iQuality */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_iQuality += 1;
						_Context->value_iQuality &= 1;
						}
					continue;
				case	0xf :
					/* iCookie */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_iCookie += 1;
						_Context->value_iCookie &= 1;
						}
					continue;
				case	0x10 :
					/* Auto3043 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3043=visual_trigger_code(_Context->msg_Auto3043[_Context->language],strlen(_Context->msg_Auto3043[_Context->language]));
						visual_button(_Context->x_Auto3033+30,_Context->y_Auto3033+340,56,48,vfh[2],34,0,_Context->msg_Auto3043[_Context->language],strlen(_Context->msg_Auto3043[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3043=visual_trigger_code(_Context->msg_Auto3043[_Context->language],strlen(_Context->msg_Auto3043[_Context->language]));
	visual_button(_Context->x_Auto3033+30,_Context->y_Auto3033+340,56,48,vfh[2],34,0,_Context->msg_Auto3043[_Context->language],strlen(_Context->msg_Auto3043[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3043_event(_Context)) != -1) break;

						}
					continue;
				case	0x11 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Auto3033+560,_Context->y_Auto3033+340,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3033+560,_Context->y_Auto3033+340,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
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

public	int	accept_html_production(
	char * pHtmlFileName,
	char * pTitle,
	char * pStyleFileName,
	char * pMetrics,
	char * pPoints,
	char * pWebAgent,
	char * pTranslation,
	char * pRestrict,
	char * pContextual,
	char * pActiveImage,
	char * piQuality,
	char * piCookie)
{
	int	status=0;
	struct accept_html_production_context * _Context=(struct accept_html_production_context*) 0;
	status = accept_html_production_create(
	&_Context,
	 pHtmlFileName,
	 pTitle,
	 pStyleFileName,
	 pMetrics,
	 pPoints,
	 pWebAgent,
	 pTranslation,
	 pRestrict,
	 pContextual,
	 pActiveImage,
	 piQuality,
	 piCookie);
	if ( status != 0) return(status);
	status = accept_html_production_show(_Context);
		enter_modal();
	status = accept_html_production_focus(_Context);
		leave_modal();
	status = accept_html_production_hide(_Context);
	status = accept_html_production_remove(
	_Context,
	 pHtmlFileName,
	 pTitle,
	 pStyleFileName,
	 pMetrics,
	 pPoints,
	 pWebAgent,
	 pTranslation,
	 pRestrict,
	 pContextual,
	 pActiveImage,
	 piQuality,
	 piCookie);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwebgen_c */
