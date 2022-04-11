
#ifndef _vpage_c
#define _vpage_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.04  */
/* Production     : C  */
/* Project        : vpage.sng  */
/* Target         : vpage.c  */
/* Identification : 0.0-1067562623-2163.2162 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Auto1   "Sing : Version 1.0a"
#define fr_Auto1   "Sing : Version 1.0a"
#define it_Auto1   "Sing : Version 1.0a"
#define es_Auto1   "Sing : Version 1.0a"
#define de_Auto1   "Sing : Version 1.0a"
#define nl_Auto1   "Sing : Version 1.0a"
#define pt_Auto1   "Sing : Version 1.0a"
#define xx_Auto1   "Sing : Version 1.0a"
#define en_Auto412   "skin.gif"
#define fr_Auto412   "skin.gif"
#define it_Auto412   "skin.gif"
#define es_Auto412   "skin.gif"
#define de_Auto412   "skin.gif"
#define nl_Auto412   "skin.gif"
#define pt_Auto412   "skin.gif"
#define xx_Auto412   "skin.gif"
#define en_Auto78   "Page Layout"
#define fr_Auto78   "Orientation"
#define en_Auto4920   "Draft Document Page Parameters"
#define fr_Auto4920   "ParamŠtres de Pages d'Impression"
#define en_Auto58   "Paper Type"
#define fr_Auto58   "Format de Papier"
#define en_Auto59   "Print Resolution"
#define fr_Auto59   "R‚solution (ppp)"
#define en_Auto60   "Top Margin"
#define fr_Auto60   "Marge Haut"
#define en_Auto62   "Left Margin"
#define fr_Auto62   "Marge Gauche"
#define en_Auto5661   "Logical Printer and Driver"
#define fr_Auto5661   "Imprimante logique et nom de pilote"
#define en_Auto5665   "Page Previewing"
#define fr_Auto5665   "Previsualisation"
#define en_Auto5663   "Page Feed"
#define fr_Auto5663   "Saut de Page"
#define en_Auto5667   "Page Alignment"
#define fr_Auto5667   "Alignement de Page"
#define en_Pagination   ""
#define en_Auto6603   "Pagination Message"
#define fr_Auto6603   "Message de pagination"
#define en_PageLayout   "Portrait|Landscape"
#define fr_PageLayout   "Normale|Italienne"
#define en_PageFeed   "None|Before|After|Flush"
#define fr_PageFeed   "Sans|Avant|Apres|Purge"
#define en_PageAlign   "none|left|right|center"
#define en_Preview   "Screen &Preview"
#define fr_Preview   "&Prevue Ecran"
#define en_LeftMarginUnits   "pixels|inches|mm"
#define fr_LeftMarginUnits   "pixels|pouces|mm"
#define en_TopMarginUnits   "pixels|inches|mm"
#define fr_TopMarginUnits   "pixels|pouces|mm"
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Abandoner"

private struct accept_visual_page_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto1[8];
	char * msg_Auto412[8];
	char * msg_Auto78[8];
	char * msg_Auto4920[8];
	char * msg_Auto58[8];
	char * msg_Auto59[8];
	char * msg_Auto60[8];
	char * msg_Auto62[8];
	char * msg_Auto5661[8];
	char * msg_Auto5665[8];
	char * msg_Auto5663[8];
	char * msg_Auto5667[8];
	char	buffer_DeviceLo[39];
	char	buffer_DriverLo[39];
	char	buffer_Pagination[39];
	char * msg_Auto6603[8];
	char * msg_PaperType[8];
	int	value_PaperType;
	char * msg_PrintDensity[8];
	int	value_PrintDensity;
	char * msg_PageLayout[8];
	int	value_PageLayout;
	char * msg_PageFeed[8];
	int	value_PageFeed;
	char * msg_PageAlign[8];
	int	value_PageAlign;
	char * msg_Preview[8];
	int	trigger_Preview;
	int	value_Preview;
	char	buffer_LeftMargin[9];
	char * msg_LeftMarginUnits[8];
	int	value_LeftMarginUnits;
	char	buffer_TopMargin[9];
	char * msg_TopMarginUnits[8];
	int	value_TopMarginUnits;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[14];
	} * _Context;

private	int	accept_visual_page_create(
	char * pDeviceLo,
	char * pDriverLo,
	char * pPagination,
	char * pPaperType,
	char * pPrintDensity,
	char * pPageLayout,
	char * pPageFeed,
	char * pPageAlign,
	char * pPreview,
	char * pLeftMargin,
	char * pLeftMarginUnits,
	char * pTopMargin,
	char * pTopMarginUnits)
{

	int i;
	if (!(_Context = allocate( sizeof( struct accept_visual_page_context ) ) ))
		return(27);
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=16;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_DeviceLo, 38, pDeviceLo);
		visual_transferin(_Context->buffer_DriverLo, 38, pDriverLo);
		visual_transferin(_Context->buffer_Pagination, 38, pPagination);
		visual_transferin((void *) 0, 0, pPaperType);
		if (!( pPaperType )) _Context->value_PaperType=0;
		else	_Context->value_PaperType = *((int *)pPaperType);
		visual_transferin((void *) 0, 0, pPrintDensity);
		if (!( pPrintDensity )) _Context->value_PrintDensity=0;
		else	_Context->value_PrintDensity = *((int *)pPrintDensity);
		visual_transferin((void *) 0, 0, pPageLayout);
		if (!( pPageLayout )) _Context->value_PageLayout=0;
		else	_Context->value_PageLayout = *((int *)pPageLayout);
		visual_transferin((void *) 0, 0, pPageFeed);
		if (!( pPageFeed )) _Context->value_PageFeed=0;
		else	_Context->value_PageFeed = *((int *)pPageFeed);
		visual_transferin((void *) 0, 0, pPageAlign);
		if (!( pPageAlign )) _Context->value_PageAlign=0;
		else	_Context->value_PageAlign = *((int *)pPageAlign);
		visual_transferin((void *) 0, 0, pPreview);
		if (!( pPreview )) _Context->value_Preview=0;
		else	_Context->value_Preview = *((int *)pPreview);
		visual_transferin(_Context->buffer_LeftMargin, 8, pLeftMargin);
		visual_transferin((void *) 0, 0, pLeftMarginUnits);
		if (!( pLeftMarginUnits )) _Context->value_LeftMarginUnits=0;
		else	_Context->value_LeftMarginUnits = *((int *)pLeftMarginUnits);
		visual_transferin(_Context->buffer_TopMargin, 8, pTopMargin);
		visual_transferin((void *) 0, 0, pTopMarginUnits);
		if (!( pTopMarginUnits )) _Context->value_TopMarginUnits=0;
		else	_Context->value_TopMarginUnits = *((int *)pTopMarginUnits);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto1[i]=" ";
	_Context->msg_Auto1[0]=en_Auto1;
	_Context->msg_Auto1[1]=fr_Auto1;
	_Context->msg_Auto1[2]=it_Auto1;
	_Context->msg_Auto1[3]=es_Auto1;
	_Context->msg_Auto1[4]=de_Auto1;
	_Context->msg_Auto1[5]=nl_Auto1;
	_Context->msg_Auto1[6]=pt_Auto1;
	_Context->msg_Auto1[7]=xx_Auto1;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto412[i]=" ";
	_Context->msg_Auto412[0]=en_Auto412;
	_Context->msg_Auto412[1]=fr_Auto412;
	_Context->msg_Auto412[2]=it_Auto412;
	_Context->msg_Auto412[3]=es_Auto412;
	_Context->msg_Auto412[4]=de_Auto412;
	_Context->msg_Auto412[5]=nl_Auto412;
	_Context->msg_Auto412[6]=pt_Auto412;
	_Context->msg_Auto412[7]=xx_Auto412;
	for (i=0; i < 8; i++)_Context->msg_Auto78[i]=" ";
	_Context->msg_Auto78[0]=en_Auto78;
	_Context->msg_Auto78[1]=fr_Auto78;
	for (i=0; i < 8; i++)_Context->msg_Auto4920[i]=" ";
	_Context->msg_Auto4920[0]=en_Auto4920;
	_Context->msg_Auto4920[1]=fr_Auto4920;
	for (i=0; i < 8; i++)_Context->msg_Auto58[i]=" ";
	_Context->msg_Auto58[0]=en_Auto58;
	_Context->msg_Auto58[1]=fr_Auto58;
	for (i=0; i < 8; i++)_Context->msg_Auto59[i]=" ";
	_Context->msg_Auto59[0]=en_Auto59;
	_Context->msg_Auto59[1]=fr_Auto59;
	for (i=0; i < 8; i++)_Context->msg_Auto60[i]=" ";
	_Context->msg_Auto60[0]=en_Auto60;
	_Context->msg_Auto60[1]=fr_Auto60;
	for (i=0; i < 8; i++)_Context->msg_Auto62[i]=" ";
	_Context->msg_Auto62[0]=en_Auto62;
	_Context->msg_Auto62[1]=fr_Auto62;
	for (i=0; i < 8; i++)_Context->msg_Auto5661[i]=" ";
	_Context->msg_Auto5661[0]=en_Auto5661;
	_Context->msg_Auto5661[1]=fr_Auto5661;
	for (i=0; i < 8; i++)_Context->msg_Auto5665[i]=" ";
	_Context->msg_Auto5665[0]=en_Auto5665;
	_Context->msg_Auto5665[1]=fr_Auto5665;
	for (i=0; i < 8; i++)_Context->msg_Auto5663[i]=" ";
	_Context->msg_Auto5663[0]=en_Auto5663;
	_Context->msg_Auto5663[1]=fr_Auto5663;
	for (i=0; i < 8; i++)_Context->msg_Auto5667[i]=" ";
	_Context->msg_Auto5667[0]=en_Auto5667;
	_Context->msg_Auto5667[1]=fr_Auto5667;
	for (i=0; i < 8; i++)_Context->msg_Auto6603[i]=" ";
	_Context->msg_Auto6603[0]=en_Auto6603;
	_Context->msg_Auto6603[1]=fr_Auto6603;
	for (i=0; i < 8; i++)_Context->msg_PaperType[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_PrintDensity[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_PageLayout[i]=" ";
	_Context->msg_PageLayout[0]=en_PageLayout;
	_Context->msg_PageLayout[1]=fr_PageLayout;
	for (i=0; i < 8; i++)_Context->msg_PageFeed[i]=" ";
	_Context->msg_PageFeed[0]=en_PageFeed;
	_Context->msg_PageFeed[1]=fr_PageFeed;
	for (i=0; i < 8; i++)_Context->msg_PageAlign[i]=" ";
	_Context->msg_PageAlign[0]=en_PageAlign;
	for (i=0; i < 8; i++)_Context->msg_Preview[i]=" ";
	_Context->msg_Preview[0]=en_Preview;
	_Context->msg_Preview[1]=fr_Preview;
	for (i=0; i < 8; i++)_Context->msg_LeftMarginUnits[i]=" ";
	_Context->msg_LeftMarginUnits[0]=en_LeftMarginUnits;
	_Context->msg_LeftMarginUnits[1]=fr_LeftMarginUnits;
	for (i=0; i < 8; i++)_Context->msg_TopMarginUnits[i]=" ";
	_Context->msg_TopMarginUnits[0]=en_TopMarginUnits;
	_Context->msg_TopMarginUnits[1]=fr_TopMarginUnits;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(200,30,400+10,540+10);
	return(0);
}

private	int	accept_visual_page_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,200,30);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_visual_page_remove(
	char * pDeviceLo,
	char * pDriverLo,
	char * pPagination,
	char * pPaperType,
	char * pPrintDensity,
	char * pPageLayout,
	char * pPageFeed,
	char * pPageAlign,
	char * pPreview,
	char * pLeftMargin,
	char * pLeftMarginUnits,
	char * pTopMargin,
	char * pTopMarginUnits)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_DeviceLo, 38, pDeviceLo);
		visual_transferout(_Context->buffer_DriverLo, 38, pDriverLo);
		visual_transferout(_Context->buffer_Pagination, 38, pPagination);
		visual_transferout((void *) 0, 0, pPaperType);
		if ( pPaperType != (char *) 0)
			*((int*)pPaperType) = _Context->value_PaperType;
		visual_transferout((void *) 0, 0, pPrintDensity);
		if ( pPrintDensity != (char *) 0)
			*((int*)pPrintDensity) = _Context->value_PrintDensity;
		visual_transferout((void *) 0, 0, pPageLayout);
		if ( pPageLayout != (char *) 0)
			*((int*)pPageLayout) = _Context->value_PageLayout;
		visual_transferout((void *) 0, 0, pPageFeed);
		if ( pPageFeed != (char *) 0)
			*((int*)pPageFeed) = _Context->value_PageFeed;
		visual_transferout((void *) 0, 0, pPageAlign);
		if ( pPageAlign != (char *) 0)
			*((int*)pPageAlign) = _Context->value_PageAlign;
		visual_transferout((void *) 0, 0, pPreview);
		if ( pPreview != (char *) 0)
			*((int*)pPreview) = _Context->value_Preview;
		visual_transferout(_Context->buffer_LeftMargin, 8, pLeftMargin);
		visual_transferout((void *) 0, 0, pLeftMarginUnits);
		if ( pLeftMarginUnits != (char *) 0)
			*((int*)pLeftMarginUnits) = _Context->value_LeftMarginUnits;
		visual_transferout(_Context->buffer_TopMargin, 8, pTopMargin);
		visual_transferout((void *) 0, 0, pTopMarginUnits);
		if ( pTopMarginUnits != (char *) 0)
			*((int*)pTopMarginUnits) = _Context->value_TopMarginUnits;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_visual_page_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,200,30);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(200,30,400,540,2,_Context->msg_Auto1[_Context->language],strlen(_Context->msg_Auto1[_Context->language]),0x407);
	visual_image(204,53,390,510,_Context->msg_Auto412[_Context->language],4);
	visual_text(230,290,160,16,2,16,0,_Context->msg_Auto78[_Context->language],strlen(_Context->msg_Auto78[_Context->language]),3);
	visual_frame(230,306,160,44,4);
	visual_text(240,50,322,40,3,16,0,_Context->msg_Auto4920[_Context->language],strlen(_Context->msg_Auto4920[_Context->language]),1283);
	visual_text(230,220,160,16,2,16,0,_Context->msg_Auto58[_Context->language],strlen(_Context->msg_Auto58[_Context->language]),3);
	visual_frame(230,236,160,44,4);
	visual_text(400,220,160,16,2,16,0,_Context->msg_Auto59[_Context->language],strlen(_Context->msg_Auto59[_Context->language]),3);
	visual_frame(400,236,160,44,4);
	visual_text(400,430,160,16,2,16,0,_Context->msg_Auto60[_Context->language],strlen(_Context->msg_Auto60[_Context->language]),3);
	visual_frame(400,446,160,44,4);
	visual_text(230,430,160,16,2,16,0,_Context->msg_Auto62[_Context->language],strlen(_Context->msg_Auto62[_Context->language]),3);
	visual_frame(230,446,160,44,4);
	visual_text(230,90,330,16,2,16,0,_Context->msg_Auto5661[_Context->language],strlen(_Context->msg_Auto5661[_Context->language]),3);
	visual_frame(230,106,330,104,4);
	visual_text(400,360,160,16,2,16,0,_Context->msg_Auto5665[_Context->language],strlen(_Context->msg_Auto5665[_Context->language]),3);
	visual_frame(400,376,160,44,4);
	visual_text(400,290,160,16,2,16,0,_Context->msg_Auto5663[_Context->language],strlen(_Context->msg_Auto5663[_Context->language]),3);
	visual_frame(400,306,160,44,4);
	visual_text(230,360,160,16,2,16,0,_Context->msg_Auto5667[_Context->language],strlen(_Context->msg_Auto5667[_Context->language]),3);
	visual_frame(230,376,160,44,4);
	visual_frame(240,120,304+2,16+2,5);
	visual_text(240+1,120+1,304,16,1,27,0,_Context->buffer_DeviceLo,38,0);
	visual_frame(240,140,304+2,16+2,5);
	visual_text(240+1,140+1,304,16,1,27,0,_Context->buffer_DriverLo,38,0);
	visual_frame(240,180,304+2,16+2,5);
	visual_text(240+1,180+1,304,16,1,0,0,_Context->buffer_Pagination,38,0);
	visual_text(240,160,300,20,2,16,0,_Context->msg_Auto6603[_Context->language],strlen(_Context->msg_Auto6603[_Context->language]),3);
	visual_select(240,250,126,64,1,27,26,parse_selection(WidgetPaperTypes,&_Context->value_PaperType),768);
	visual_select(410,250,126,64,1,27,26,parse_selection(WidgetPrintResolution,&_Context->value_PrintDensity),768);
	visual_select(240,320,140,48,1,0,0,parse_selection(_Context->msg_PageLayout[_Context->language],&_Context->value_PageLayout),768);
	visual_select(410,320,140,70,1,27,0,parse_selection(_Context->msg_PageFeed[_Context->language],&_Context->value_PageFeed),768);
	visual_select(240,390,136,64,1,0,0,parse_selection(_Context->msg_PageAlign[_Context->language],&_Context->value_PageAlign),768);
	_Context->trigger_Preview=visual_trigger_code(_Context->msg_Preview[_Context->language],strlen(_Context->msg_Preview[_Context->language]));
	visual_check(410,390,140,16,2,16,0,_Context->msg_Preview[_Context->language],strlen(_Context->msg_Preview[_Context->language]),_Context->value_Preview|0);
	visual_frame(240,460,64+2,16+2,5);
	visual_text(240+1,460+1,64,16,1,27,0,_Context->buffer_LeftMargin,8,0);
	visual_select(310,460,72,48,1,0,0,parse_selection(_Context->msg_LeftMarginUnits[_Context->language],&_Context->value_LeftMarginUnits),768);
	visual_frame(410,460,64+2,16+2,5);
	visual_text(410+1,460+1,64,16,1,27,0,_Context->buffer_TopMargin,8,0);
	visual_select(480,460,72,48,1,0,0,parse_selection(_Context->msg_TopMarginUnits[_Context->language],&_Context->value_TopMarginUnits),768);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(250,510,112,32,2,27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(420,510,112,32,2,27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_thaw(200,30,400,540);

	return(0);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}


private	int	accept_visual_page_event()
{
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Preview == mb ) return(10);
		if (_Context->trigger_Accept == mb ) return(15);
		if (_Context->trigger_Cancel == mb ) return(16);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (mt & _MIMO_UP) {
	if ((mx >= 579 )  
	&&  (my >= 34 )  
	&&  (mx <= 595 )  
	&&  (my <= 50 )) {
		return(1);	/* Auto1 */

		}
	if ((mx >= 563 )  
	&&  (my >= 34 )  
	&&  (mx <= 579 )  
	&&  (my <= 50 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vpage.htm");
			};
		return(-1);	/* Auto1 */

		}
	if ((mx >= 547 )  
	&&  (my >= 34 )  
	&&  (mx <= 563 )  
	&&  (my <= 50 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		_Context->language--; _Context->language %=8;
			}
		(void) visual_national_language(_Context->language);
		accept_visual_page_show();
		return(-1);	/* Auto1 */

		}
		}
	if (( mx >= 240 ) 
	&&  ( my >= 120 ) 
	&&  ( mx <= 544 ) 
	&&  ( my <= 136 )) {
		return(2); /* DeviceLo */
		}
	if (( mx >= 240 ) 
	&&  ( my >= 140 ) 
	&&  ( mx <= 544 ) 
	&&  ( my <= 156 )) {
		return(3); /* DriverLo */
		}
	if (( mx >= 240 ) 
	&&  ( my >= 180 ) 
	&&  ( mx <= 544 ) 
	&&  ( my <= 196 )) {
		return(4); /* Pagination */
		}
	if ((mx >= 240 ) 
	&&  (my >= 250 ) 
	&&  (mx <= 366 ) 
	&&  (my <= 266 )) {
		return(5); /* PaperType */
		}
	if ((mx >= 410 ) 
	&&  (my >= 250 ) 
	&&  (mx <= 536 ) 
	&&  (my <= 266 )) {
		return(6); /* PrintDensity */
		}
	if ((mx >= 240 ) 
	&&  (my >= 320 ) 
	&&  (mx <= 380 ) 
	&&  (my <= 336 )) {
		return(7); /* PageLayout */
		}
	if ((mx >= 410 ) 
	&&  (my >= 320 ) 
	&&  (mx <= 550 ) 
	&&  (my <= 336 )) {
		return(8); /* PageFeed */
		}
	if ((mx >= 240 ) 
	&&  (my >= 390 ) 
	&&  (mx <= 376 ) 
	&&  (my <= 406 )) {
		return(9); /* PageAlign */
		}
	if (( mx >= 410 ) 
	&&  ( my >= 390 ) 
	&&  ( mx <= 550 ) 
	&&  ( my <= 406 )) {
		return(10); /* Preview */
		}
	if (( mx >= 240 ) 
	&&  ( my >= 460 ) 
	&&  ( mx <= 304 ) 
	&&  ( my <= 476 )) {
		return(11); /* LeftMargin */
		}
	if ((mx >= 310 ) 
	&&  (my >= 460 ) 
	&&  (mx <= 382 ) 
	&&  (my <= 476 )) {
		return(12); /* LeftMarginUnits */
		}
	if (( mx >= 410 ) 
	&&  ( my >= 460 ) 
	&&  ( mx <= 474 ) 
	&&  ( my <= 476 )) {
		return(13); /* TopMargin */
		}
	if ((mx >= 480 ) 
	&&  (my >= 460 ) 
	&&  (mx <= 552 ) 
	&&  (my <= 476 )) {
		return(14); /* TopMarginUnits */
		}
	if (( mx >= 250 ) 
	&&  ( my >= 510 ) 
	&&  ( mx <= 362 ) 
	&&  ( my <= 542 )) {
		return(15); /* Accept */
		}
	if (( mx >= 420 ) 
	&&  ( my >= 510 ) 
	&&  ( mx <= 532 ) 
	&&  ( my <= 542 )) {
		return(16); /* Cancel */
		}

	return(-1);
}


private	int	accept_visual_page_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* DeviceLo */
				_Context->keycode = visual_edit(240+1,120+1,304,16,1,_Context->buffer_DeviceLo,38);
				break;
			case	0x3 :
				/* DriverLo */
				_Context->keycode = visual_edit(240+1,140+1,304,16,1,_Context->buffer_DriverLo,38);
				break;
			case	0x4 :
				/* Pagination */
				_Context->keycode = visual_edit(240+1,180+1,304,16,1,_Context->buffer_Pagination,38);
				break;
			case	0x5 :
				/* PaperType */
				_Context->keycode = visual_select(240,250,126,64,1,27,26,parse_selection(WidgetPaperTypes,&_Context->value_PaperType),770);
				break;
			case	0x6 :
				/* PrintDensity */
				_Context->keycode = visual_select(410,250,126,64,1,27,26,parse_selection(WidgetPrintResolution,&_Context->value_PrintDensity),770);
				break;
			case	0x7 :
				/* PageLayout */
				_Context->keycode = visual_select(240,320,140,48,1,0,0,parse_selection(_Context->msg_PageLayout[_Context->language],&_Context->value_PageLayout),770);
				break;
			case	0x8 :
				/* PageFeed */
				_Context->keycode = visual_select(410,320,140,70,1,27,0,parse_selection(_Context->msg_PageFeed[_Context->language],&_Context->value_PageFeed),770);
				break;
			case	0x9 :
				/* PageAlign */
				_Context->keycode = visual_select(240,390,136,64,1,0,0,parse_selection(_Context->msg_PageAlign[_Context->language],&_Context->value_PageAlign),770);
				break;
			case	0xa :
				/* Preview */
				visual_check(410,390,140,16,2,16,0,_Context->msg_Preview[_Context->language],strlen(_Context->msg_Preview[_Context->language]),(_Context->value_Preview |2));
				_Context->keycode = visual_getch();
				visual_check(410,390,140,16,2,16,0,_Context->msg_Preview[_Context->language],strlen(_Context->msg_Preview[_Context->language]),(_Context->value_Preview |0));
				break;
			case	0xb :
				/* LeftMargin */
				_Context->keycode = visual_edit(240+1,460+1,64,16,1,_Context->buffer_LeftMargin,8);
				break;
			case	0xc :
				/* LeftMarginUnits */
				_Context->keycode = visual_select(310,460,72,48,1,0,0,parse_selection(_Context->msg_LeftMarginUnits[_Context->language],&_Context->value_LeftMarginUnits),770);
				break;
			case	0xd :
				/* TopMargin */
				_Context->keycode = visual_edit(410+1,460+1,64,16,1,_Context->buffer_TopMargin,8);
				break;
			case	0xe :
				/* TopMarginUnits */
				_Context->keycode = visual_select(480,460,72,48,1,0,0,parse_selection(_Context->msg_TopMarginUnits[_Context->language],&_Context->value_TopMarginUnits),770);
				break;
			case	0xf :
				/* Accept */
				visual_button(250,510,112,32,2,27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(250,510,112,32,2,27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x10 :
				/* Cancel */
				visual_button(420,510,112,32,2,27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(420,510,112,32,2,27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_visual_page_show();
			continue;
		case	0x2 :
			_Context->focus_item=16;
			accept_visual_page_show();
			continue;
			case	0x100 :
				if ((retcode=accept_visual_page_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* DeviceLo */
						continue;
					case	0x3 :
						/* DriverLo */
						continue;
					case	0x4 :
						/* Pagination */
						continue;
					case	0x5 :
						/* PaperType */
						continue;
					case	0x6 :
						/* PrintDensity */
						continue;
					case	0x7 :
						/* PageLayout */
						continue;
					case	0x8 :
						/* PageFeed */
						continue;
					case	0x9 :
						/* PageAlign */
						continue;
					case	0xa :
						/* Preview */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Preview += 1;
							_Context->value_Preview &= 1;
							}
						continue;
					case	0xb :
						/* LeftMargin */
						continue;
					case	0xc :
						/* LeftMarginUnits */
						continue;
					case	0xd :
						/* TopMargin */
						continue;
					case	0xe :
						/* TopMarginUnits */
						continue;
					case	0xf :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(250,510,112,32,2,27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(250,510,112,32,2,27,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x10 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(420,510,112,32,2,27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(420,510,112,32,2,27,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

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

public	int	accept_visual_page(
	char * pDeviceLo,
	char * pDriverLo,
	char * pPagination,
	char * pPaperType,
	char * pPrintDensity,
	char * pPageLayout,
	char * pPageFeed,
	char * pPageAlign,
	char * pPreview,
	char * pLeftMargin,
	char * pLeftMarginUnits,
	char * pTopMargin,
	char * pTopMarginUnits)
{
	int	status=0;
	status = accept_visual_page_create(
	 pDeviceLo,
	 pDriverLo,
	 pPagination,
	 pPaperType,
	 pPrintDensity,
	 pPageLayout,
	 pPageFeed,
	 pPageAlign,
	 pPreview,
	 pLeftMargin,
	 pLeftMarginUnits,
	 pTopMargin,
	 pTopMarginUnits);
	if ( status != 0) return(status);
	status = accept_visual_page_show();
		enter_modal();
	status = accept_visual_page_focus();
		leave_modal();
	status = accept_visual_page_hide();
	status = accept_visual_page_remove(
	 pDeviceLo,
	 pDriverLo,
	 pPagination,
	 pPaperType,
	 pPrintDensity,
	 pPageLayout,
	 pPageFeed,
	 pPageAlign,
	 pPreview,
	 pLeftMargin,
	 pLeftMarginUnits,
	 pTopMargin,
	 pTopMarginUnits);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vpage_c */
