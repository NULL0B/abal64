
#ifndef _vhtml_c
#define _vhtml_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vhtml.xml                                                */
/* Target         : vhtml.c                                                  */
/* Identification : 0.0-1177511935-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__auto113   ""
#define fr__auto113   ""
#define it__auto113   ""
#define es__auto113   ""
#define de__auto113   ""
#define nl__auto113   ""
#define pt__auto113   ""
#define xx__auto113   ""
#define en_Auto2735   "Html Document Production Parameters"
#define fr_Auto2735   "ParamŠtres de production de documents Html"
#define it_Auto2735   "Html Document Production Parameters"
#define es_Auto2735   "Html Document Production Parameters"
#define de_Auto2735   "Html Document Production Parameters"
#define nl_Auto2735   "Html Document Production Parameters"
#define pt_Auto2735   "Html Document Production Parameters"
#define xx_Auto2735   "Html Document Production Parameters"
#define en__Auto2735   ""
#define fr__Auto2735   ""
#define it__Auto2735   ""
#define es__Auto2735   ""
#define de__Auto2735   ""
#define nl__Auto2735   ""
#define pt__Auto2735   ""
#define xx__Auto2735   ""
#define en_auto116   "Title"
#define fr_auto116   "Titre"
#define it_auto116   "Title"
#define es_auto116   "Title"
#define de_auto116   "Title"
#define nl_auto116   "Title"
#define pt_auto116   "Title"
#define xx_auto116   "Title"
#define en_Auto2736   "Path Root"
#define fr_Auto2736   "Chemin"
#define it_Auto2736   "Path Root"
#define es_Auto2736   "Path Root"
#define de_Auto2736   "Path Root"
#define nl_Auto2736   "Path Root"
#define pt_Auto2736   "Path Root"
#define xx_Auto2736   "Path Root"
#define en_auto117   "Screen Style"
#define fr_auto117   "Style ‚cran"
#define it_auto117   "Screen Style"
#define es_auto117   "Screen Style"
#define de_auto117   "Screen Style"
#define nl_auto117   "Screen Style"
#define pt_auto117   "Screen Style"
#define xx_auto117   "Screen Style"
#define en_auto118   "Footer"
#define fr_auto118   "Pied de page"
#define it_auto118   "Footer"
#define es_auto118   "Footer"
#define de_auto118   "Footer"
#define nl_auto118   "Footer"
#define pt_auto118   "Footer"
#define xx_auto118   "Footer"
#define en_auto234   "Print Style"
#define fr_auto234   "Style ‚dition"
#define it_auto234   "Print Style"
#define es_auto234   "Print Style"
#define de_auto234   "Print Style"
#define nl_auto234   "Print Style"
#define pt_auto234   "Print Style"
#define xx_auto234   "Print Style"
#define en_auto233   "Logo"
#define fr_auto233   "Logo"
#define it_auto233   "Logo"
#define es_auto233   "Logo"
#define de_auto233   "Logo"
#define nl_auto233   "Logo"
#define pt_auto233   "Logo"
#define xx_auto233   "Logo"
#define en_Auto2737   "htmlicon.gif"
#define fr_Auto2737   "htmlicon.gif"
#define it_Auto2737   "htmlicon.gif"
#define es_Auto2737   "htmlicon.gif"
#define de_Auto2737   "htmlicon.gif"
#define nl_Auto2737   "htmlicon.gif"
#define pt_Auto2737   "htmlicon.gif"
#define xx_Auto2737   "htmlicon.gif"
#define en_TitleHeading   ""
#define en_PathRoot   ""
#define fr_PathRoot   ""
#define en_ScreenStyle   ""
#define en_PrintStyle   ""
#define en_Logo   ""
#define en_FooterCopyright   ""
#define en_IsSeparate   "&Separate Page Generation"
#define fr_IsSeparate   "&Pages individuelles"
#define it_IsSeparate   "&Separate Page Generation"
#define es_IsSeparate   "&Separate Page Generation"
#define de_IsSeparate   "&Separate Page Generation"
#define nl_IsSeparate   "&Separate Page Generation"
#define pt_IsSeparate   "&Separate Page Generation"
#define xx_IsSeparate   "&Separate Page Generation"
#define en_ForceLanguage   "&Force Language"
#define fr_ForceLanguage   "&Force la langage"
#define it_ForceLanguage   "&Force Language"
#define es_ForceLanguage   "&Force Language"
#define de_ForceLanguage   "&Force Language"
#define nl_ForceLanguage   "&Force Language"
#define pt_ForceLanguage   "&Force Language"
#define xx_ForceLanguage   "&Force Language"
#define en__NationalLanguage   ""
#define en_Metrics   "pixels|points|millimeters|inches"
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
#define en_Auto2738   "Metrics"
#define fr_Auto2738   "Unit‚"
#define it_Auto2738   "Metrics"
#define es_Auto2738   "Metrics"
#define de_Auto2738   "Metrics"
#define nl_Auto2738   "Metrics"
#define pt_Auto2738   "Metrics"
#define xx_Auto2738   "Metrics"
#define en__Auto2738   ""
#define fr__Auto2738   ""
#define it__Auto2738   ""
#define es__Auto2738   ""
#define de__Auto2738   ""
#define nl__Auto2738   ""
#define pt__Auto2738   ""
#define xx__Auto2738   ""
#define en_Auto2739   "Scale"
#define fr_Auto2739   "Echelle"
#define it_Auto2739   "Generation"
#define es_Auto2739   "Generation"
#define de_Auto2739   "Generation"
#define nl_Auto2739   "Generation"
#define pt_Auto2739   "Generation"
#define xx_Auto2739   "Generation"
#define en__Auto2739   ""
#define fr__Auto2739   ""
#define it__Auto2739   ""
#define es__Auto2739   ""
#define de__Auto2739   ""
#define nl__Auto2739   ""
#define pt__Auto2739   ""
#define xx__Auto2739   ""
#define en_IsReport   "&Parts Listing"
#define fr_IsReport   "Liste des &piŠces"
#define it_IsReport   "&Parts Listing"
#define es_IsReport   "&Parts Listing"
#define de_IsReport   "&Parts Listing"
#define nl_IsReport   "&Parts Listing"
#define pt_IsReport   "&Parts Listing"
#define xx_IsReport   "&Parts Listing"
#define en_Auto2740   "ok.gif"
#define fr_Auto2740   "ok.gif"
#define it_Auto2740   "ok.gif"
#define es_Auto2740   "ok.gif"
#define de_Auto2740   "ok.gif"
#define nl_Auto2740   "ok.gif"
#define pt_Auto2740   "ok.gif"
#define xx_Auto2740   "ok.gif"
#define en_Auto2741   "cancel.gif"
#define fr_Auto2741   "cancel.gif"
#define it_Auto2741   "cancel.gif"
#define es_Auto2741   "cancel.gif"
#define de_Auto2741   "cancel.gif"
#define nl_Auto2741   "cancel.gif"
#define pt_Auto2741   "cancel.gif"
#define xx_Auto2741   "cancel.gif"

private struct accept_document_parameters_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_auto113[8];
	char * hint_auto113[8];
	int	x_auto113;
	int	y_auto113;
	int	w_auto113;
	int	h_auto113;
	char * msg_Auto2735[8];
	char * hint_Auto2735[8];
	char * msg_auto116[8];
	char * hint_auto116[8];
	char * msg_Auto2736[8];
	char * hint_Auto2736[8];
	char * msg_auto117[8];
	char * hint_auto117[8];
	char * msg_auto118[8];
	char * hint_auto118[8];
	char * msg_auto234[8];
	char * hint_auto234[8];
	char * msg_auto233[8];
	char * hint_auto233[8];
	char * msg_Auto2737[8];
	char * hint_Auto2737[8];
	char * hint_TitleHeading[8];
	char	buffer_TitleHeading[256];
	char * hint_PathRoot[8];
	char	buffer_PathRoot[256];
	char * hint_ScreenStyle[8];
	char	buffer_ScreenStyle[256];
	char * hint_PrintStyle[8];
	char	buffer_PrintStyle[256];
	char * hint_Logo[8];
	char	buffer_Logo[256];
	char * hint_FooterCopyright[8];
	char	buffer_FooterCopyright[256];
	char * msg_IsSeparate[8];
	int	trigger_IsSeparate;
	char * hint_IsSeparate[8];
	int	value_IsSeparate;
	char * msg_ForceLanguage[8];
	int	trigger_ForceLanguage;
	char * hint_ForceLanguage[8];
	int	value_ForceLanguage;
	char * msg_NationalLanguage[8];
	char * hint_NationalLanguage[8];
	int	value_NationalLanguage;
	char * msg_Metrics[8];
	char * hint_Metrics[8];
	int	value_Metrics;
	char * msg_Points[8];
	char * hint_Points[8];
	int	value_Points;
	char * msg_Auto2738[8];
	char * hint_Auto2738[8];
	char * msg_Auto2739[8];
	char * hint_Auto2739[8];
	char * msg_IsReport[8];
	int	trigger_IsReport;
	char * hint_IsReport[8];
	int	value_IsReport;
	char * msg_Auto2740[8];
	int	trigger_Auto2740;
	char * hint_Auto2740[8];
	char * msg_Auto2741[8];
	int	trigger_Auto2741;
	char * hint_Auto2741[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[13];
	};
static int	vfh[16];

public	int	accept_document_parameters_create(
	struct accept_document_parameters_context ** cptr,
	char * pTitleHeading,
	char * pPathRoot,
	char * pScreenStyle,
	char * pPrintStyle,
	char * pLogo,
	char * pFooterCopyright,
	char * pIsSeparate,
	char * pForceLanguage,
	char * pNationalLanguage,
	char * pMetrics,
	char * pPoints,
	char * pIsReport)
{

	int i;
	struct accept_document_parameters_context * _Context=(struct accept_document_parameters_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_document_parameters_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=15;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSWWWWSW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_TitleHeading, 255, pTitleHeading);
		visual_transferin(_Context->buffer_PathRoot, 255, pPathRoot);
		visual_transferin(_Context->buffer_ScreenStyle, 255, pScreenStyle);
		visual_transferin(_Context->buffer_PrintStyle, 255, pPrintStyle);
		visual_transferin(_Context->buffer_Logo, 255, pLogo);
		visual_transferin(_Context->buffer_FooterCopyright, 255, pFooterCopyright);
		visual_transferin((void *) 0, 0, pIsSeparate);
		if (!( pIsSeparate )) _Context->value_IsSeparate=0;
		else	_Context->value_IsSeparate = *((int *)pIsSeparate);
		visual_transferin((void *) 0, 0, pForceLanguage);
		if (!( pForceLanguage )) _Context->value_ForceLanguage=0;
		else	_Context->value_ForceLanguage = *((int *)pForceLanguage);
		visual_transferin((void *) 0, 0, pNationalLanguage);
		if (!( pNationalLanguage )) _Context->value_NationalLanguage=0;
		else	_Context->value_NationalLanguage = *((int *)pNationalLanguage);
		visual_transferin((void *) 0, 0, pMetrics);
		if (!( pMetrics )) _Context->value_Metrics=0;
		else	_Context->value_Metrics = *((int *)pMetrics);
		visual_transferin((void *) 0, 0, pPoints);
		if (!( pPoints )) _Context->value_Points=0;
		else	_Context->value_Points = *((int *)pPoints);
		visual_transferin((void *) 0, 0, pIsReport);
		if (!( pIsReport )) _Context->value_IsReport=0;
		else	_Context->value_IsReport = *((int *)pIsReport);
		}
	for (i=0; i < 8; i++)_Context->msg_auto113[i]=" ";
	_Context->hint_auto113[0]=en__auto113;
	_Context->hint_auto113[1]=fr__auto113;
	_Context->hint_auto113[2]=it__auto113;
	_Context->hint_auto113[3]=es__auto113;
	_Context->hint_auto113[4]=de__auto113;
	_Context->hint_auto113[5]=nl__auto113;
	_Context->hint_auto113[6]=pt__auto113;
	_Context->hint_auto113[7]=xx__auto113;
	_Context->x_auto113=90;
	_Context->y_auto113=105;
	_Context->w_auto113=620;
	_Context->h_auto113=390;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2735[i]=" ";
	_Context->msg_Auto2735[0]=en_Auto2735;
	_Context->msg_Auto2735[1]=fr_Auto2735;
	_Context->msg_Auto2735[2]=it_Auto2735;
	_Context->msg_Auto2735[3]=es_Auto2735;
	_Context->msg_Auto2735[4]=de_Auto2735;
	_Context->msg_Auto2735[5]=nl_Auto2735;
	_Context->msg_Auto2735[6]=pt_Auto2735;
	_Context->msg_Auto2735[7]=xx_Auto2735;
	_Context->hint_Auto2735[0]=en__Auto2735;
	_Context->hint_Auto2735[1]=fr__Auto2735;
	_Context->hint_Auto2735[2]=it__Auto2735;
	_Context->hint_Auto2735[3]=es__Auto2735;
	_Context->hint_Auto2735[4]=de__Auto2735;
	_Context->hint_Auto2735[5]=nl__Auto2735;
	_Context->hint_Auto2735[6]=pt__Auto2735;
	_Context->hint_Auto2735[7]=xx__Auto2735;
	for (i=0; i < 8; i++)_Context->msg_auto116[i]=" ";
	_Context->msg_auto116[0]=en_auto116;
	_Context->msg_auto116[1]=fr_auto116;
	_Context->msg_auto116[2]=it_auto116;
	_Context->msg_auto116[3]=es_auto116;
	_Context->msg_auto116[4]=de_auto116;
	_Context->msg_auto116[5]=nl_auto116;
	_Context->msg_auto116[6]=pt_auto116;
	_Context->msg_auto116[7]=xx_auto116;
	for (i=0; i < 8; i++)_Context->msg_Auto2736[i]=" ";
	_Context->msg_Auto2736[0]=en_Auto2736;
	_Context->msg_Auto2736[1]=fr_Auto2736;
	_Context->msg_Auto2736[2]=it_Auto2736;
	_Context->msg_Auto2736[3]=es_Auto2736;
	_Context->msg_Auto2736[4]=de_Auto2736;
	_Context->msg_Auto2736[5]=nl_Auto2736;
	_Context->msg_Auto2736[6]=pt_Auto2736;
	_Context->msg_Auto2736[7]=xx_Auto2736;
	for (i=0; i < 8; i++)_Context->msg_auto117[i]=" ";
	_Context->msg_auto117[0]=en_auto117;
	_Context->msg_auto117[1]=fr_auto117;
	_Context->msg_auto117[2]=it_auto117;
	_Context->msg_auto117[3]=es_auto117;
	_Context->msg_auto117[4]=de_auto117;
	_Context->msg_auto117[5]=nl_auto117;
	_Context->msg_auto117[6]=pt_auto117;
	_Context->msg_auto117[7]=xx_auto117;
	for (i=0; i < 8; i++)_Context->msg_auto118[i]=" ";
	_Context->msg_auto118[0]=en_auto118;
	_Context->msg_auto118[1]=fr_auto118;
	_Context->msg_auto118[2]=it_auto118;
	_Context->msg_auto118[3]=es_auto118;
	_Context->msg_auto118[4]=de_auto118;
	_Context->msg_auto118[5]=nl_auto118;
	_Context->msg_auto118[6]=pt_auto118;
	_Context->msg_auto118[7]=xx_auto118;
	for (i=0; i < 8; i++)_Context->msg_auto234[i]=" ";
	_Context->msg_auto234[0]=en_auto234;
	_Context->msg_auto234[1]=fr_auto234;
	_Context->msg_auto234[2]=it_auto234;
	_Context->msg_auto234[3]=es_auto234;
	_Context->msg_auto234[4]=de_auto234;
	_Context->msg_auto234[5]=nl_auto234;
	_Context->msg_auto234[6]=pt_auto234;
	_Context->msg_auto234[7]=xx_auto234;
	for (i=0; i < 8; i++)_Context->msg_auto233[i]=" ";
	_Context->msg_auto233[0]=en_auto233;
	_Context->msg_auto233[1]=fr_auto233;
	_Context->msg_auto233[2]=it_auto233;
	_Context->msg_auto233[3]=es_auto233;
	_Context->msg_auto233[4]=de_auto233;
	_Context->msg_auto233[5]=nl_auto233;
	_Context->msg_auto233[6]=pt_auto233;
	_Context->msg_auto233[7]=xx_auto233;
	for (i=0; i < 8; i++)_Context->msg_Auto2737[i]=" ";
	_Context->msg_Auto2737[0]=en_Auto2737;
	_Context->msg_Auto2737[1]=fr_Auto2737;
	_Context->msg_Auto2737[2]=it_Auto2737;
	_Context->msg_Auto2737[3]=es_Auto2737;
	_Context->msg_Auto2737[4]=de_Auto2737;
	_Context->msg_Auto2737[5]=nl_Auto2737;
	_Context->msg_Auto2737[6]=pt_Auto2737;
	_Context->msg_Auto2737[7]=xx_Auto2737;
	for (i=0; i < 8; i++)_Context->msg_IsSeparate[i]=" ";
	_Context->msg_IsSeparate[0]=en_IsSeparate;
	_Context->msg_IsSeparate[1]=fr_IsSeparate;
	_Context->msg_IsSeparate[2]=it_IsSeparate;
	_Context->msg_IsSeparate[3]=es_IsSeparate;
	_Context->msg_IsSeparate[4]=de_IsSeparate;
	_Context->msg_IsSeparate[5]=nl_IsSeparate;
	_Context->msg_IsSeparate[6]=pt_IsSeparate;
	_Context->msg_IsSeparate[7]=xx_IsSeparate;
	for (i=0; i < 8; i++)_Context->msg_ForceLanguage[i]=" ";
	_Context->msg_ForceLanguage[0]=en_ForceLanguage;
	_Context->msg_ForceLanguage[1]=fr_ForceLanguage;
	_Context->msg_ForceLanguage[2]=it_ForceLanguage;
	_Context->msg_ForceLanguage[3]=es_ForceLanguage;
	_Context->msg_ForceLanguage[4]=de_ForceLanguage;
	_Context->msg_ForceLanguage[5]=nl_ForceLanguage;
	_Context->msg_ForceLanguage[6]=pt_ForceLanguage;
	_Context->msg_ForceLanguage[7]=xx_ForceLanguage;
	for (i=0; i < 8; i++)_Context->msg_NationalLanguage[i]=" ";
	_Context->hint_NationalLanguage[0]=en__NationalLanguage;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2738[i]=" ";
	_Context->msg_Auto2738[0]=en_Auto2738;
	_Context->msg_Auto2738[1]=fr_Auto2738;
	_Context->msg_Auto2738[2]=it_Auto2738;
	_Context->msg_Auto2738[3]=es_Auto2738;
	_Context->msg_Auto2738[4]=de_Auto2738;
	_Context->msg_Auto2738[5]=nl_Auto2738;
	_Context->msg_Auto2738[6]=pt_Auto2738;
	_Context->msg_Auto2738[7]=xx_Auto2738;
	_Context->hint_Auto2738[0]=en__Auto2738;
	_Context->hint_Auto2738[1]=fr__Auto2738;
	_Context->hint_Auto2738[2]=it__Auto2738;
	_Context->hint_Auto2738[3]=es__Auto2738;
	_Context->hint_Auto2738[4]=de__Auto2738;
	_Context->hint_Auto2738[5]=nl__Auto2738;
	_Context->hint_Auto2738[6]=pt__Auto2738;
	_Context->hint_Auto2738[7]=xx__Auto2738;
	for (i=0; i < 8; i++)_Context->msg_Auto2739[i]=" ";
	_Context->msg_Auto2739[0]=en_Auto2739;
	_Context->msg_Auto2739[1]=fr_Auto2739;
	_Context->msg_Auto2739[2]=it_Auto2739;
	_Context->msg_Auto2739[3]=es_Auto2739;
	_Context->msg_Auto2739[4]=de_Auto2739;
	_Context->msg_Auto2739[5]=nl_Auto2739;
	_Context->msg_Auto2739[6]=pt_Auto2739;
	_Context->msg_Auto2739[7]=xx_Auto2739;
	_Context->hint_Auto2739[0]=en__Auto2739;
	_Context->hint_Auto2739[1]=fr__Auto2739;
	_Context->hint_Auto2739[2]=it__Auto2739;
	_Context->hint_Auto2739[3]=es__Auto2739;
	_Context->hint_Auto2739[4]=de__Auto2739;
	_Context->hint_Auto2739[5]=nl__Auto2739;
	_Context->hint_Auto2739[6]=pt__Auto2739;
	_Context->hint_Auto2739[7]=xx__Auto2739;
	for (i=0; i < 8; i++)_Context->msg_IsReport[i]=" ";
	_Context->msg_IsReport[0]=en_IsReport;
	_Context->msg_IsReport[1]=fr_IsReport;
	_Context->msg_IsReport[2]=it_IsReport;
	_Context->msg_IsReport[3]=es_IsReport;
	_Context->msg_IsReport[4]=de_IsReport;
	_Context->msg_IsReport[5]=nl_IsReport;
	_Context->msg_IsReport[6]=pt_IsReport;
	_Context->msg_IsReport[7]=xx_IsReport;
	for (i=0; i < 8; i++)_Context->msg_Auto2740[i]=" ";
	_Context->msg_Auto2740[0]=en_Auto2740;
	_Context->msg_Auto2740[1]=fr_Auto2740;
	_Context->msg_Auto2740[2]=it_Auto2740;
	_Context->msg_Auto2740[3]=es_Auto2740;
	_Context->msg_Auto2740[4]=de_Auto2740;
	_Context->msg_Auto2740[5]=nl_Auto2740;
	_Context->msg_Auto2740[6]=pt_Auto2740;
	_Context->msg_Auto2740[7]=xx_Auto2740;
	for (i=0; i < 8; i++)_Context->msg_Auto2741[i]=" ";
	_Context->msg_Auto2741[0]=en_Auto2741;
	_Context->msg_Auto2741[1]=fr_Auto2741;
	_Context->msg_Auto2741[2]=it_Auto2741;
	_Context->msg_Auto2741[3]=es_Auto2741;
	_Context->msg_Auto2741[4]=de_Auto2741;
	_Context->msg_Auto2741[5]=nl_Auto2741;
	_Context->msg_Auto2741[6]=pt_Auto2741;
	_Context->msg_Auto2741[7]=xx_Auto2741;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto113,_Context->y_auto113,620+10,390+10);
	return(0);
}

public 	int	accept_document_parameters_hide(struct accept_document_parameters_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_auto113,_Context->y_auto113);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_document_parameters_remove(
	struct accept_document_parameters_context * _Context,
	char * pTitleHeading,
	char * pPathRoot,
	char * pScreenStyle,
	char * pPrintStyle,
	char * pLogo,
	char * pFooterCopyright,
	char * pIsSeparate,
	char * pForceLanguage,
	char * pNationalLanguage,
	char * pMetrics,
	char * pPoints,
	char * pIsReport)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSWWWWSW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_TitleHeading, 255, pTitleHeading);
		visual_transferout(_Context->buffer_PathRoot, 255, pPathRoot);
		visual_transferout(_Context->buffer_ScreenStyle, 255, pScreenStyle);
		visual_transferout(_Context->buffer_PrintStyle, 255, pPrintStyle);
		visual_transferout(_Context->buffer_Logo, 255, pLogo);
		visual_transferout(_Context->buffer_FooterCopyright, 255, pFooterCopyright);
		visual_transferout((void *) 0, 0, pIsSeparate);
		if ( pIsSeparate != (char *) 0)
			*((int*)pIsSeparate) = _Context->value_IsSeparate;
		visual_transferout((void *) 0, 0, pForceLanguage);
		if ( pForceLanguage != (char *) 0)
			*((int*)pForceLanguage) = _Context->value_ForceLanguage;
		visual_transferout((void *) 0, 0, pNationalLanguage);
		if ( pNationalLanguage != (char *) 0)
			*((int*)pNationalLanguage) = _Context->value_NationalLanguage;
		visual_transferout((void *) 0, 0, pMetrics);
		if ( pMetrics != (char *) 0)
			*((int*)pMetrics) = _Context->value_Metrics;
		visual_transferout((void *) 0, 0, pPoints);
		if ( pPoints != (char *) 0)
			*((int*)pPoints) = _Context->value_Points;
		visual_transferout((void *) 0, 0, pIsReport);
		if ( pIsReport != (char *) 0)
			*((int*)pIsReport) = _Context->value_IsReport;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_document_parameters_show(struct accept_document_parameters_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto113,_Context->y_auto113);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_auto113,_Context->y_auto113,620,390,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_auto113,_Context->y_auto113,620,390,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_auto113+40,_Context->y_auto113+40,513,24,vfh[5],16,0,_Context->msg_Auto2735[_Context->language],strlen(_Context->msg_Auto2735[_Context->language]),1283);
	visual_text(_Context->x_auto113+20,_Context->y_auto113+90,84,32,vfh[2],27,0,_Context->msg_auto116[_Context->language],strlen(_Context->msg_auto116[_Context->language]),258);
	visual_text(_Context->x_auto113+20,_Context->y_auto113+130,70,16,vfh[2],27,0,_Context->msg_Auto2736[_Context->language],strlen(_Context->msg_Auto2736[_Context->language]),258);
	visual_text(_Context->x_auto113+20,_Context->y_auto113+160,84,16,vfh[2],27,0,_Context->msg_auto117[_Context->language],strlen(_Context->msg_auto117[_Context->language]),258);
	visual_text(_Context->x_auto113+20,_Context->y_auto113+230,84,32,vfh[2],27,0,_Context->msg_auto118[_Context->language],strlen(_Context->msg_auto118[_Context->language]),258);
	visual_text(_Context->x_auto113+20,_Context->y_auto113+180,84,16,vfh[2],27,0,_Context->msg_auto234[_Context->language],strlen(_Context->msg_auto234[_Context->language]),258);
	visual_text(_Context->x_auto113+20,_Context->y_auto113+200,84,16,vfh[2],27,0,_Context->msg_auto233[_Context->language],strlen(_Context->msg_auto233[_Context->language]),258);
	visual_image(_Context->x_auto113+550,_Context->y_auto113+30,50,50,_Context->msg_Auto2737[_Context->language],0);
	visual_frame(_Context->x_auto113+110,_Context->y_auto113+90,488+2,32+2,5);
	visual_text(_Context->x_auto113+110+1,_Context->y_auto113+90+1,488,32,vfh[1],27,0,_Context->buffer_TitleHeading,255,0);
	visual_frame(_Context->x_auto113+110,_Context->y_auto113+130,488+2,16+2,5);
	visual_text(_Context->x_auto113+110+1,_Context->y_auto113+130+1,488,16,vfh[1],0,0,_Context->buffer_PathRoot,255,0);
	visual_frame(_Context->x_auto113+110,_Context->y_auto113+160,488+2,16+2,5);
	visual_text(_Context->x_auto113+110+1,_Context->y_auto113+160+1,488,16,vfh[1],27,0,_Context->buffer_ScreenStyle,255,0);
	visual_frame(_Context->x_auto113+110,_Context->y_auto113+180,488+2,16+2,5);
	visual_text(_Context->x_auto113+110+1,_Context->y_auto113+180+1,488,16,vfh[1],0,0,_Context->buffer_PrintStyle,255,0);
	visual_frame(_Context->x_auto113+110,_Context->y_auto113+200,488+2,16+2,5);
	visual_text(_Context->x_auto113+110+1,_Context->y_auto113+200+1,488,16,vfh[1],27,0,_Context->buffer_Logo,255,0);
	visual_frame(_Context->x_auto113+110,_Context->y_auto113+230,488+2,32+2,5);
	visual_text(_Context->x_auto113+110+1,_Context->y_auto113+230+1,488,32,vfh[1],27,0,_Context->buffer_FooterCopyright,255,0);
	_Context->trigger_IsSeparate=visual_trigger_code(_Context->msg_IsSeparate[_Context->language],strlen(_Context->msg_IsSeparate[_Context->language]));
	visual_check(_Context->x_auto113+20,_Context->y_auto113+280,224,16,vfh[2],27,0,_Context->msg_IsSeparate[_Context->language],strlen(_Context->msg_IsSeparate[_Context->language]),_Context->value_IsSeparate|0);
	_Context->trigger_ForceLanguage=visual_trigger_code(_Context->msg_ForceLanguage[_Context->language],strlen(_Context->msg_ForceLanguage[_Context->language]));
	visual_check(_Context->x_auto113+250,_Context->y_auto113+280,154,16,vfh[2],28,28,_Context->msg_ForceLanguage[_Context->language],strlen(_Context->msg_ForceLanguage[_Context->language]),_Context->value_ForceLanguage|0);
	visual_select(_Context->x_auto113+250,_Context->y_auto113+330,144,48,vfh[2],27,0,parse_selection(NationalLanguageList,&_Context->value_NationalLanguage),768);
	visual_select(_Context->x_auto113+120,_Context->y_auto113+330,112,48,vfh[2],16,0,parse_selection(_Context->msg_Metrics[_Context->language],&_Context->value_Metrics),768);
	visual_select(_Context->x_auto113+410,_Context->y_auto113+330,88,48,vfh[2],0,0,parse_selection(_Context->msg_Points[_Context->language],&_Context->value_Points),768);
	visual_text(_Context->x_auto113+110,_Context->y_auto113+310,112,16,vfh[2],16,0,_Context->msg_Auto2738[_Context->language],strlen(_Context->msg_Auto2738[_Context->language]),259);
	visual_text(_Context->x_auto113+410,_Context->y_auto113+310,84,16,vfh[2],16,0,_Context->msg_Auto2739[_Context->language],strlen(_Context->msg_Auto2739[_Context->language]),259);
	_Context->trigger_IsReport=visual_trigger_code(_Context->msg_IsReport[_Context->language],strlen(_Context->msg_IsReport[_Context->language]));
	visual_check(_Context->x_auto113+450,_Context->y_auto113+280,154,16,vfh[2],27,0,_Context->msg_IsReport[_Context->language],strlen(_Context->msg_IsReport[_Context->language]),_Context->value_IsReport|0);
	_Context->trigger_Auto2740=visual_trigger_code(_Context->msg_Auto2740[_Context->language],strlen(_Context->msg_Auto2740[_Context->language]));
	visual_button(_Context->x_auto113+30,_Context->y_auto113+320,56,48,vfh[2],34,0,_Context->msg_Auto2740[_Context->language],strlen(_Context->msg_Auto2740[_Context->language]),1040);
	_Context->trigger_Auto2741=visual_trigger_code(_Context->msg_Auto2741[_Context->language],strlen(_Context->msg_Auto2741[_Context->language]));
	visual_button(_Context->x_auto113+540,_Context->y_auto113+320,56,48,vfh[2],34,0,_Context->msg_Auto2741[_Context->language],strlen(_Context->msg_Auto2741[_Context->language]),1040);
	visual_thaw(_Context->x_auto113,_Context->y_auto113,620,390);

	return(0);
}

private int TitleHeading_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The TITLE edit field will be used in the TITLE of the Document HEAD ";
			mptr[1]="section and in the initial HEADING of the document BODY.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PathRoot_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "This edit field provides the root path component or directory to which ";
			mptr[1]="the various html pages will be generated, and from which online documentation ";
			mptr[2]=" will be loaded. ";
			mptr[3]=" National language sub-directories will be created in this directory ";
			mptr[4]="as required for the generation alternative language documentation. ";
			mptr[5]="    ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ScreenStyle_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "The SCREEN STYLE edit field allows the name of an external style sh ";
			mptr[1]="eet to be specified. ";
			mptr[2]=" ";
			mptr[3]=" This style sheet will be used for Screen fo rmating of the document ";
			mptr[4]="or document suite and should contain style instrections for TABLE,TH,TD ";
			mptr[5]="and HEADING items.  ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PrintStyle_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The PRINT STYLE ezdit field allows an external style sheet url to ";
			mptr[1]="b e  specified for document printing operations.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Logo_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The LOGO edit field allows an url for a logo file name to be specif ";
			mptr[1]="ied. The image logo will be displayed to the right of the title tex ";
			mptr[2]="t at  the top of all relevant pages.  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FooterCopyright_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The FOOTER edit field allows copyright or other information to be ";
			mptr[1]="   included at the ens of the document to be specified.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsSeparate_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "This check box controls the way in which the document is generated. ";
			mptr[1]=" If this control is checked then the document will be generated as ";
			mptr[2]="a  collection of HTML pages, one per subcomponent, the master document ";
			mptr[3]=" comprising simply a header section and Table of Contents. Otherwise ";
			mptr[4]="the master document will be generated to contain documentation for ";
			mptr[5]="all components in one Html File.   ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ForceLanguage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This check control, when activated, indicates that the selected national ";
			mptr[1]="language is to be used for the production of all subsequent html documents. ";
			mptr[2]="Otherwise the language code of each individual subcomponent will be ";
			mptr[3]="respected.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int NationalLanguage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This select control allows the national language to be used by the ";
			mptr[1]="html  document production mechanisms to be specified. This value will ";
			mptr[2]="be ignored if the Force Language control is not active.   ";
			return(visual_online_help(mptr,3));
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

private int IsReport_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This check box when selected directs the HTML production  mechanisms ";
			mptr[1]="to generate a table of component providing detail for each component. ";
			mptr[2]="When unchecked the document will include only the user guide documentation ";
			mptr[3]="texts and images.  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2740_help()
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

private int Auto2741_help()
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

private int auto113action(struct accept_document_parameters_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_document_parameters_hide(_Context);

		_Context->x_auto113 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto113 < 0) { _Context->x_auto113=0; }
		_Context->y_auto113 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto113 < 0) { _Context->y_auto113=0; }
			accept_document_parameters_show(_Context);

		visual_thaw(_Context->x_auto113,_Context->y_auto113,620,390);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto2740_event(struct accept_document_parameters_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto2741_event(struct accept_document_parameters_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_document_parameters_event(
struct accept_document_parameters_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsSeparate == mb ) return(8);
		if (_Context->trigger_ForceLanguage == mb ) return(9);
		if (_Context->trigger_IsReport == mb ) return(13);
		if (_Context->trigger_Auto2740 == mb ) return(14);
		if (_Context->trigger_Auto2741 == mb ) return(15);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_auto113+599) )  
	&&  (my >= (_Context->y_auto113+4) )  
	&&  (mx <= (_Context->x_auto113+616) )  
	&&  (my <= (_Context->y_auto113+20) )) {
		return(1);	/* auto113 */

		}
	if ((mx >= (_Context->x_auto113+583) )  
	&&  (my >= (_Context->y_auto113+4) )  
	&&  (mx <= (_Context->x_auto113+600) )  
	&&  (my <= (_Context->y_auto113+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vhtml.htm");
			};
		return(-1);	/* auto113 */

		}
	if ((mx >= (_Context->x_auto113+567) )  
	&&  (my >= (_Context->y_auto113+4) )  
	&&  (mx <= (_Context->x_auto113+584) )  
	&&  (my <= (_Context->y_auto113+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_document_parameters_show(_Context);
		return(-1);	/* auto113 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_auto113+4) )  
		&&  (my >= (_Context->y_auto113+4) )  
		&&  (mx <= (_Context->x_auto113+552) )  
		&&  (my <= (_Context->y_auto113+20) )) {
			return( auto113action(_Context) );
			}
		}
	if (( mx >= (_Context->x_auto113+110) ) 
	&&  ( my >= (_Context->y_auto113+90) ) 
	&&  ( mx <= (_Context->x_auto113+110+488) ) 
	&&  ( my <= (_Context->y_auto113+90+32))) {
		return(2); /* TitleHeading */
		}
	if (( mx >= (_Context->x_auto113+110) ) 
	&&  ( my >= (_Context->y_auto113+130) ) 
	&&  ( mx <= (_Context->x_auto113+110+488) ) 
	&&  ( my <= (_Context->y_auto113+130+16))) {
		return(3); /* PathRoot */
		}
	if (( mx >= (_Context->x_auto113+110) ) 
	&&  ( my >= (_Context->y_auto113+160) ) 
	&&  ( mx <= (_Context->x_auto113+110+488) ) 
	&&  ( my <= (_Context->y_auto113+160+16))) {
		return(4); /* ScreenStyle */
		}
	if (( mx >= (_Context->x_auto113+110) ) 
	&&  ( my >= (_Context->y_auto113+180) ) 
	&&  ( mx <= (_Context->x_auto113+110+488) ) 
	&&  ( my <= (_Context->y_auto113+180+16))) {
		return(5); /* PrintStyle */
		}
	if (( mx >= (_Context->x_auto113+110) ) 
	&&  ( my >= (_Context->y_auto113+200) ) 
	&&  ( mx <= (_Context->x_auto113+110+488) ) 
	&&  ( my <= (_Context->y_auto113+200+16))) {
		return(6); /* Logo */
		}
	if (( mx >= (_Context->x_auto113+110) ) 
	&&  ( my >= (_Context->y_auto113+230) ) 
	&&  ( mx <= (_Context->x_auto113+110+488) ) 
	&&  ( my <= (_Context->y_auto113+230+32))) {
		return(7); /* FooterCopyright */
		}
	if (( mx >= (_Context->x_auto113+20) ) 
	&&  ( my >= (_Context->y_auto113+280) ) 
	&&  ( mx <= (_Context->x_auto113+20+224) ) 
	&&  ( my <= (_Context->y_auto113+280+16))) {
		return(8); /* IsSeparate */
		}
	if (( mx >= (_Context->x_auto113+250) ) 
	&&  ( my >= (_Context->y_auto113+280) ) 
	&&  ( mx <= (_Context->x_auto113+250+154) ) 
	&&  ( my <= (_Context->y_auto113+280+16))) {
		return(9); /* ForceLanguage */
		}
	if (( mx >= (_Context->x_auto113+250+0) ) 
	&&  ( my >= (_Context->y_auto113+330) ) 
	&&  ( mx <= (_Context->x_auto113+250+144) ) 
	&&  ( my <= (_Context->y_auto113+330+16))) {
		return(10); /* NationalLanguage */
		}
	if (( mx >= (_Context->x_auto113+120+0) ) 
	&&  ( my >= (_Context->y_auto113+330) ) 
	&&  ( mx <= (_Context->x_auto113+120+112) ) 
	&&  ( my <= (_Context->y_auto113+330+16))) {
		return(11); /* Metrics */
		}
	if (( mx >= (_Context->x_auto113+410+0) ) 
	&&  ( my >= (_Context->y_auto113+330) ) 
	&&  ( mx <= (_Context->x_auto113+410+88) ) 
	&&  ( my <= (_Context->y_auto113+330+16))) {
		return(12); /* Points */
		}
	if (( mx >= (_Context->x_auto113+450) ) 
	&&  ( my >= (_Context->y_auto113+280) ) 
	&&  ( mx <= (_Context->x_auto113+450+154) ) 
	&&  ( my <= (_Context->y_auto113+280+16))) {
		return(13); /* IsReport */
		}
	if (( mx >= (_Context->x_auto113+30) ) 
	&&  ( my >= (_Context->y_auto113+320) ) 
	&&  ( mx <= (_Context->x_auto113+30+56) ) 
	&&  ( my <= (_Context->y_auto113+320+48))) {
		return(14); /* Auto2740 */
		}
	if (( mx >= (_Context->x_auto113+540) ) 
	&&  ( my >= (_Context->y_auto113+320) ) 
	&&  ( mx <= (_Context->x_auto113+540+56) ) 
	&&  ( my <= (_Context->y_auto113+320+48))) {
		return(15); /* Auto2741 */
		}

	return(-1);
}


public	int	accept_document_parameters_focus(struct accept_document_parameters_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* TitleHeading */
				_Context->keycode = visual_edit(_Context->x_auto113+110+1,_Context->y_auto113+90+1,488,32,vfh[1],_Context->buffer_TitleHeading,255);
			break;
			case	0x3 :
				/* PathRoot */
				_Context->keycode = visual_edit(_Context->x_auto113+110+1,_Context->y_auto113+130+1,488,16,vfh[1],_Context->buffer_PathRoot,255);
			break;
			case	0x4 :
				/* ScreenStyle */
				_Context->keycode = visual_edit(_Context->x_auto113+110+1,_Context->y_auto113+160+1,488,16,vfh[1],_Context->buffer_ScreenStyle,255);
			break;
			case	0x5 :
				/* PrintStyle */
				_Context->keycode = visual_edit(_Context->x_auto113+110+1,_Context->y_auto113+180+1,488,16,vfh[1],_Context->buffer_PrintStyle,255);
			break;
			case	0x6 :
				/* Logo */
				_Context->keycode = visual_edit(_Context->x_auto113+110+1,_Context->y_auto113+200+1,488,16,vfh[1],_Context->buffer_Logo,255);
			break;
			case	0x7 :
				/* FooterCopyright */
				_Context->keycode = visual_edit(_Context->x_auto113+110+1,_Context->y_auto113+230+1,488,32,vfh[1],_Context->buffer_FooterCopyright,255);
			break;
			case	0x8 :
				/* IsSeparate */
				visual_check(_Context->x_auto113+20,_Context->y_auto113+280,224,16,vfh[2],27,0,_Context->msg_IsSeparate[_Context->language],strlen(_Context->msg_IsSeparate[_Context->language]),(_Context->value_IsSeparate |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsSeparate=visual_trigger_code(_Context->msg_IsSeparate[_Context->language],strlen(_Context->msg_IsSeparate[_Context->language]));
	visual_check(_Context->x_auto113+20,_Context->y_auto113+280,224,16,vfh[2],27,0,_Context->msg_IsSeparate[_Context->language],strlen(_Context->msg_IsSeparate[_Context->language]),_Context->value_IsSeparate|0);
				break;
			case	0x9 :
				/* ForceLanguage */
				visual_check(_Context->x_auto113+250,_Context->y_auto113+280,154,16,vfh[2],28,28,_Context->msg_ForceLanguage[_Context->language],strlen(_Context->msg_ForceLanguage[_Context->language]),(_Context->value_ForceLanguage |2));
				_Context->keycode = visual_getch();
				_Context->trigger_ForceLanguage=visual_trigger_code(_Context->msg_ForceLanguage[_Context->language],strlen(_Context->msg_ForceLanguage[_Context->language]));
	visual_check(_Context->x_auto113+250,_Context->y_auto113+280,154,16,vfh[2],28,28,_Context->msg_ForceLanguage[_Context->language],strlen(_Context->msg_ForceLanguage[_Context->language]),_Context->value_ForceLanguage|0);
				break;
			case	0xa :
				/* NationalLanguage */
				_Context->keycode = visual_select(_Context->x_auto113+250,_Context->y_auto113+330,144,48,vfh[2],27,0,parse_selection(NationalLanguageList,&_Context->value_NationalLanguage),770);
				break;
			case	0xb :
				/* Metrics */
				_Context->keycode = visual_select(_Context->x_auto113+120,_Context->y_auto113+330,112,48,vfh[2],16,0,parse_selection(_Context->msg_Metrics[_Context->language],&_Context->value_Metrics),770);
				break;
			case	0xc :
				/* Points */
				_Context->keycode = visual_select(_Context->x_auto113+410,_Context->y_auto113+330,88,48,vfh[2],0,0,parse_selection(_Context->msg_Points[_Context->language],&_Context->value_Points),770);
				break;
			case	0xd :
				/* IsReport */
				visual_check(_Context->x_auto113+450,_Context->y_auto113+280,154,16,vfh[2],27,0,_Context->msg_IsReport[_Context->language],strlen(_Context->msg_IsReport[_Context->language]),(_Context->value_IsReport |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsReport=visual_trigger_code(_Context->msg_IsReport[_Context->language],strlen(_Context->msg_IsReport[_Context->language]));
	visual_check(_Context->x_auto113+450,_Context->y_auto113+280,154,16,vfh[2],27,0,_Context->msg_IsReport[_Context->language],strlen(_Context->msg_IsReport[_Context->language]),_Context->value_IsReport|0);
				break;
			case	0xe :
				/* Auto2740 */
				_Context->trigger_Auto2740=visual_trigger_code(_Context->msg_Auto2740[_Context->language],strlen(_Context->msg_Auto2740[_Context->language]));
				visual_button(_Context->x_auto113+30,_Context->y_auto113+320,56,48,vfh[2],34,0,_Context->msg_Auto2740[_Context->language],strlen(_Context->msg_Auto2740[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2740=visual_trigger_code(_Context->msg_Auto2740[_Context->language],strlen(_Context->msg_Auto2740[_Context->language]));
	visual_button(_Context->x_auto113+30,_Context->y_auto113+320,56,48,vfh[2],34,0,_Context->msg_Auto2740[_Context->language],strlen(_Context->msg_Auto2740[_Context->language]),1040);
				break;
			case	0xf :
				/* Auto2741 */
				_Context->trigger_Auto2741=visual_trigger_code(_Context->msg_Auto2741[_Context->language],strlen(_Context->msg_Auto2741[_Context->language]));
				visual_button(_Context->x_auto113+540,_Context->y_auto113+320,56,48,vfh[2],34,0,_Context->msg_Auto2741[_Context->language],strlen(_Context->msg_Auto2741[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2741=visual_trigger_code(_Context->msg_Auto2741[_Context->language],strlen(_Context->msg_Auto2741[_Context->language]));
	visual_button(_Context->x_auto113+540,_Context->y_auto113+320,56,48,vfh[2],34,0,_Context->msg_Auto2741[_Context->language],strlen(_Context->msg_Auto2741[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_document_parameters_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=15;
			accept_document_parameters_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_document_parameters_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (TitleHeading_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (PathRoot_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (ScreenStyle_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (PrintStyle_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (Logo_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (FooterCopyright_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (IsSeparate_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (ForceLanguage_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (NationalLanguage_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Metrics_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (Points_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (IsReport_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (Auto2740_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (Auto2741_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* auto113 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* TitleHeading */
					continue;
				case	0x3 :
					/* PathRoot */
					continue;
				case	0x4 :
					/* ScreenStyle */
					continue;
				case	0x5 :
					/* PrintStyle */
					continue;
				case	0x6 :
					/* Logo */
					continue;
				case	0x7 :
					/* FooterCopyright */
					continue;
				case	0x8 :
					/* IsSeparate */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsSeparate += 1;
						_Context->value_IsSeparate &= 1;
						}
					continue;
				case	0x9 :
					/* ForceLanguage */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ForceLanguage += 1;
						_Context->value_ForceLanguage &= 1;
						}
					continue;
				case	0xa :
					/* NationalLanguage */
					continue;
				case	0xb :
					/* Metrics */
					continue;
				case	0xc :
					/* Points */
					continue;
				case	0xd :
					/* IsReport */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsReport += 1;
						_Context->value_IsReport &= 1;
						}
					continue;
				case	0xe :
					/* Auto2740 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2740=visual_trigger_code(_Context->msg_Auto2740[_Context->language],strlen(_Context->msg_Auto2740[_Context->language]));
						visual_button(_Context->x_auto113+30,_Context->y_auto113+320,56,48,vfh[2],34,0,_Context->msg_Auto2740[_Context->language],strlen(_Context->msg_Auto2740[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2740=visual_trigger_code(_Context->msg_Auto2740[_Context->language],strlen(_Context->msg_Auto2740[_Context->language]));
	visual_button(_Context->x_auto113+30,_Context->y_auto113+320,56,48,vfh[2],34,0,_Context->msg_Auto2740[_Context->language],strlen(_Context->msg_Auto2740[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2740_event(_Context)) != -1) break;

						}
					continue;
				case	0xf :
					/* Auto2741 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2741=visual_trigger_code(_Context->msg_Auto2741[_Context->language],strlen(_Context->msg_Auto2741[_Context->language]));
						visual_button(_Context->x_auto113+540,_Context->y_auto113+320,56,48,vfh[2],34,0,_Context->msg_Auto2741[_Context->language],strlen(_Context->msg_Auto2741[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2741=visual_trigger_code(_Context->msg_Auto2741[_Context->language],strlen(_Context->msg_Auto2741[_Context->language]));
	visual_button(_Context->x_auto113+540,_Context->y_auto113+320,56,48,vfh[2],34,0,_Context->msg_Auto2741[_Context->language],strlen(_Context->msg_Auto2741[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2741_event(_Context)) != -1) break;

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
				_Context->focus_item=15;
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

public	int	accept_document_parameters(
	char * pTitleHeading,
	char * pPathRoot,
	char * pScreenStyle,
	char * pPrintStyle,
	char * pLogo,
	char * pFooterCopyright,
	char * pIsSeparate,
	char * pForceLanguage,
	char * pNationalLanguage,
	char * pMetrics,
	char * pPoints,
	char * pIsReport)
{
	int	status=0;
	struct accept_document_parameters_context * _Context=(struct accept_document_parameters_context*) 0;
	status = accept_document_parameters_create(
	&_Context,
	 pTitleHeading,
	 pPathRoot,
	 pScreenStyle,
	 pPrintStyle,
	 pLogo,
	 pFooterCopyright,
	 pIsSeparate,
	 pForceLanguage,
	 pNationalLanguage,
	 pMetrics,
	 pPoints,
	 pIsReport);
	if ( status != 0) return(status);
	status = accept_document_parameters_show(_Context);
		enter_modal();
	status = accept_document_parameters_focus(_Context);
		leave_modal();
	status = accept_document_parameters_hide(_Context);
	status = accept_document_parameters_remove(
	_Context,
	 pTitleHeading,
	 pPathRoot,
	 pScreenStyle,
	 pPrintStyle,
	 pLogo,
	 pFooterCopyright,
	 pIsSeparate,
	 pForceLanguage,
	 pNationalLanguage,
	 pMetrics,
	 pPoints,
	 pIsReport);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vhtml_c */
