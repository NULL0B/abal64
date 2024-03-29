
#ifndef _vpage_c
#define _vpage_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vpage.xml                                                */
/* Target         : vpage.c                                                  */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto3581   ""
#define fr__Auto3581   ""
#define it__Auto3581   ""
#define es__Auto3581   ""
#define de__Auto3581   ""
#define nl__Auto3581   ""
#define pt__Auto3581   ""
#define xx__Auto3581   ""
#define en_Auto3582   "Page Layout"
#define fr_Auto3582   "Orientation"
#define it_Auto3582   "Page Layout"
#define es_Auto3582   "Page Layout"
#define de_Auto3582   "Page Layout"
#define nl_Auto3582   "Page Layout"
#define pt_Auto3582   "Page Layout"
#define xx_Auto3582   "Page Layout"
#define en_Auto3583   "Draft Document Page Parameters"
#define fr_Auto3583   "Param�tres des pages d'impression"
#define it_Auto3583   "Draft Document Page Parameters"
#define es_Auto3583   "Draft Document Page Parameters"
#define de_Auto3583   "Draft Document Page Parameters"
#define nl_Auto3583   "Draft Document Page Parameters"
#define pt_Auto3583   "Draft Document Page Parameters"
#define xx_Auto3583   "Draft Document Page Parameters"
#define en_Auto3584   "Paper Type"
#define fr_Auto3584   "Format de la page"
#define it_Auto3584   "Paper Type"
#define es_Auto3584   "Paper Type"
#define de_Auto3584   "Paper Type"
#define nl_Auto3584   "Paper Type"
#define pt_Auto3584   "Paper Type"
#define xx_Auto3584   "Paper Type"
#define en_Auto3585   "Print Resolution"
#define fr_Auto3585   "R�solution (ppp)"
#define it_Auto3585   "Print Resolution"
#define es_Auto3585   "Print Resolution"
#define de_Auto3585   "Print Resolution"
#define nl_Auto3585   "Print Resolution"
#define pt_Auto3585   "Print Resolution"
#define xx_Auto3585   "Print Resolution"
#define en_Auto3586   "Top Margin"
#define fr_Auto3586   "Marge haute"
#define it_Auto3586   "Top Margin"
#define es_Auto3586   "Top Margin"
#define de_Auto3586   "Top Margin"
#define nl_Auto3586   "Top Margin"
#define pt_Auto3586   "Top Margin"
#define xx_Auto3586   "Top Margin"
#define en_Auto3587   "Left Margin"
#define fr_Auto3587   "Marge gauche"
#define it_Auto3587   "Left Margin"
#define es_Auto3587   "Left Margin"
#define de_Auto3587   "Left Margin"
#define nl_Auto3587   "Left Margin"
#define pt_Auto3587   "Left Margin"
#define xx_Auto3587   "Left Margin"
#define en_Auto3588   "Logical Printer and Driver"
#define fr_Auto3588   "Imprimante logique et nom de pilote"
#define it_Auto3588   "Logical Printer and Driver"
#define es_Auto3588   "Logical Printer and Driver"
#define de_Auto3588   "Logical Printer and Driver"
#define nl_Auto3588   "Logical Printer and Driver"
#define pt_Auto3588   "Logical Printer and Driver"
#define xx_Auto3588   "Logical Printer and Driver"
#define en_Auto3589   "Page Previewing"
#define fr_Auto3589   "Pr�visualisation"
#define it_Auto3589   "Page Previewing"
#define es_Auto3589   "Page Previewing"
#define de_Auto3589   "Page Previewing"
#define nl_Auto3589   "Page Previewing"
#define pt_Auto3589   "Page Previewing"
#define xx_Auto3589   "Page Previewing"
#define en_Auto3590   "Page Feed"
#define fr_Auto3590   "Saut de page"
#define it_Auto3590   "Page Feed"
#define es_Auto3590   "Page Feed"
#define de_Auto3590   "Page Feed"
#define nl_Auto3590   "Page Feed"
#define pt_Auto3590   "Page Feed"
#define xx_Auto3590   "Page Feed"
#define en_Auto3591   "Page Alignment"
#define fr_Auto3591   "Alignement de page"
#define it_Auto3591   "Page Alignment"
#define es_Auto3591   "Page Alignment"
#define de_Auto3591   "Page Alignment"
#define nl_Auto3591   "Page Alignment"
#define pt_Auto3591   "Page Alignment"
#define xx_Auto3591   "Page Alignment"
#define en_DeviceLo   ""
#define en_DriverLo   ""
#define en_Pagination   ""
#define en_Auto3592   "Pagination Message"
#define fr_Auto3592   "Message de pagination"
#define it_Auto3592   "Pagination Message"
#define es_Auto3592   "Pagination Message"
#define de_Auto3592   "Pagination Message"
#define nl_Auto3592   "Pagination Message"
#define pt_Auto3592   "Pagination Message"
#define xx_Auto3592   "Pagination Message"
#define en__PaperType   ""
#define en__PrintDensity   ""
#define en_PageLayout   "Portrait|Landscape"
#define fr_PageLayout   "Normale|Italienne"
#define it_PageLayout   "Portrait|Landscape"
#define es_PageLayout   "Portrait|Landscape"
#define de_PageLayout   "Portrait|Landscape"
#define nl_PageLayout   "Portrait|Landscape"
#define pt_PageLayout   "Portrait|Landscape"
#define xx_PageLayout   "Portrait|Landscape"
#define en__PageLayout   ""
#define en_PageFeed   "None|Before|After|Flush"
#define fr_PageFeed   "Sans|Avant|Apres|Purge"
#define it_PageFeed   "None|Before|After|Flush"
#define es_PageFeed   "None|Before|After|Flush"
#define de_PageFeed   "None|Before|After|Flush"
#define nl_PageFeed   "None|Before|After|Flush"
#define pt_PageFeed   "None|Before|After|Flush"
#define xx_PageFeed   "None|Before|After|Flush"
#define en__PageFeed   ""
#define en_PageAlign   "none|left|right|center|margin"
#define fr_PageAlign   "sans|gauche|droite|centre"
#define it_PageAlign   "none|left|right|center"
#define es_PageAlign   "none|left|right|center"
#define de_PageAlign   "none|left|right|center"
#define nl_PageAlign   "none|left|right|center"
#define pt_PageAlign   "none|left|right|center"
#define xx_PageAlign   "none|left|right|center"
#define en__PageAlign   ""
#define en_Preview   "None|Screen"
#define fr_Preview   "Sans|Ecran|Zoom"
#define it_Preview   "None|Screen|Zoom"
#define es_Preview   "None|Screen|Zoom"
#define de_Preview   "None|Screen|Zoom"
#define nl_Preview   "None|Screen|Zoom"
#define pt_Preview   "None|Screen|Zoom"
#define xx_Preview   "None|Screen|Zoom"
#define en__Preview   ""
#define en_LeftMargin   ""
#define en__LeftMargin   ""
#define en_LeftMarginUnits   "pixels|inches|mm"
#define fr_LeftMarginUnits   "pixels|pouces|mm"
#define it_LeftMarginUnits   "pixels|inches|mm"
#define es_LeftMarginUnits   "pixels|inches|mm"
#define de_LeftMarginUnits   "pixels|inches|mm"
#define nl_LeftMarginUnits   "pixels|inches|mm"
#define pt_LeftMarginUnits   "pixels|inches|mm"
#define xx_LeftMarginUnits   "pixels|inches|mm"
#define en__LeftMarginUnits   ""
#define en_TopMargin   ""
#define en__TopMargin   ""
#define en_TopMarginUnits   "pixels|inches|mm"
#define fr_TopMarginUnits   "pixels|pouces|mm"
#define it_TopMarginUnits   "pixels|inches|mm"
#define es_TopMarginUnits   "pixels|inches|mm"
#define de_TopMarginUnits   "pixels|inches|mm"
#define nl_TopMarginUnits   "pixels|inches|mm"
#define pt_TopMarginUnits   "pixels|inches|mm"
#define xx_TopMarginUnits   "pixels|inches|mm"
#define en__TopMarginUnits   ""
#define en_Auto3593   "ok.gif"
#define fr_Auto3593   "ok.gif"
#define it_Auto3593   "ok.gif"
#define es_Auto3593   "ok.gif"
#define de_Auto3593   "ok.gif"
#define nl_Auto3593   "ok.gif"
#define pt_Auto3593   "ok.gif"
#define xx_Auto3593   "ok.gif"
#define en_Auto3594   "cancel.gif"
#define fr_Auto3594   "cancel.gif"
#define it_Auto3594   "cancel.gif"
#define es_Auto3594   "cancel.gif"
#define de_Auto3594   "cancel.gif"
#define nl_Auto3594   "cancel.gif"
#define pt_Auto3594   "cancel.gif"
#define xx_Auto3594   "cancel.gif"

private struct accept_visual_page_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3581[8];
	char * hint_Auto3581[8];
	int	x_Auto3581;
	int	y_Auto3581;
	int	w_Auto3581;
	int	h_Auto3581;
	char * msg_Auto3582[8];
	char * hint_Auto3582[8];
	char * msg_Auto3583[8];
	char * hint_Auto3583[8];
	char * msg_Auto3584[8];
	char * hint_Auto3584[8];
	char * msg_Auto3585[8];
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
	char * hint_DeviceLo[8];
	char	buffer_DeviceLo[256];
	char * hint_DriverLo[8];
	char	buffer_DriverLo[256];
	char * hint_Pagination[8];
	char	buffer_Pagination[256];
	char * msg_Auto3592[8];
	char * hint_Auto3592[8];
	char * msg_PaperType[8];
	char * hint_PaperType[8];
	int	value_PaperType;
	char * msg_PrintDensity[8];
	char * hint_PrintDensity[8];
	int	value_PrintDensity;
	char * msg_PageLayout[8];
	char * hint_PageLayout[8];
	int	value_PageLayout;
	char * msg_PageFeed[8];
	char * hint_PageFeed[8];
	int	value_PageFeed;
	char * msg_PageAlign[8];
	char * hint_PageAlign[8];
	int	value_PageAlign;
	char * msg_Preview[8];
	char * hint_Preview[8];
	int	value_Preview;
	char * hint_LeftMargin[8];
	char	buffer_LeftMargin[9];
	char * msg_LeftMarginUnits[8];
	char * hint_LeftMarginUnits[8];
	int	value_LeftMarginUnits;
	char * hint_TopMargin[8];
	char	buffer_TopMargin[9];
	char * msg_TopMarginUnits[8];
	char * hint_TopMarginUnits[8];
	int	value_TopMarginUnits;
	char * msg_Auto3593[8];
	int	trigger_Auto3593;
	char * hint_Auto3593[8];
	char * msg_Auto3594[8];
	int	trigger_Auto3594;
	char * hint_Auto3594[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[14];
	};
static int	vfh[16];
private int on_Auto3593_event(struct accept_visual_page_context * _Context);
private int on_Auto3594_event(struct accept_visual_page_context * _Context);

public	int	accept_visual_page_create(
	struct accept_visual_page_context ** cptr,
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
	struct accept_visual_page_context * _Context=(struct accept_visual_page_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_visual_page_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=16;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSWWWWWWSWSW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_DeviceLo, 255, pDeviceLo);
		visual_transferin(_Context->buffer_DriverLo, 255, pDriverLo);
		visual_transferin(_Context->buffer_Pagination, 255, pPagination);
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
	for (i=0; i < 8; i++)_Context->msg_Auto3581[i]=" ";
	_Context->hint_Auto3581[0]=en__Auto3581;
	_Context->hint_Auto3581[1]=fr__Auto3581;
	_Context->hint_Auto3581[2]=it__Auto3581;
	_Context->hint_Auto3581[3]=es__Auto3581;
	_Context->hint_Auto3581[4]=de__Auto3581;
	_Context->hint_Auto3581[5]=nl__Auto3581;
	_Context->hint_Auto3581[6]=pt__Auto3581;
	_Context->hint_Auto3581[7]=xx__Auto3581;
	_Context->x_Auto3581=200;
	_Context->y_Auto3581=30;
	_Context->w_Auto3581=400;
	_Context->h_Auto3581=540;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3582[i]=" ";
	_Context->msg_Auto3582[0]=en_Auto3582;
	_Context->msg_Auto3582[1]=fr_Auto3582;
	_Context->msg_Auto3582[2]=it_Auto3582;
	_Context->msg_Auto3582[3]=es_Auto3582;
	_Context->msg_Auto3582[4]=de_Auto3582;
	_Context->msg_Auto3582[5]=nl_Auto3582;
	_Context->msg_Auto3582[6]=pt_Auto3582;
	_Context->msg_Auto3582[7]=xx_Auto3582;
	for (i=0; i < 8; i++)_Context->msg_Auto3583[i]=" ";
	_Context->msg_Auto3583[0]=en_Auto3583;
	_Context->msg_Auto3583[1]=fr_Auto3583;
	_Context->msg_Auto3583[2]=it_Auto3583;
	_Context->msg_Auto3583[3]=es_Auto3583;
	_Context->msg_Auto3583[4]=de_Auto3583;
	_Context->msg_Auto3583[5]=nl_Auto3583;
	_Context->msg_Auto3583[6]=pt_Auto3583;
	_Context->msg_Auto3583[7]=xx_Auto3583;
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
	for (i=0; i < 8; i++)_Context->msg_PaperType[i]=" ";
	_Context->hint_PaperType[0]=en__PaperType;
	for (i=0; i < 8; i++)_Context->msg_PrintDensity[i]=" ";
	_Context->hint_PrintDensity[0]=en__PrintDensity;
	for (i=0; i < 8; i++)_Context->msg_PageLayout[i]=" ";
	_Context->msg_PageLayout[0]=en_PageLayout;
	_Context->msg_PageLayout[1]=fr_PageLayout;
	_Context->msg_PageLayout[2]=it_PageLayout;
	_Context->msg_PageLayout[3]=es_PageLayout;
	_Context->msg_PageLayout[4]=de_PageLayout;
	_Context->msg_PageLayout[5]=nl_PageLayout;
	_Context->msg_PageLayout[6]=pt_PageLayout;
	_Context->msg_PageLayout[7]=xx_PageLayout;
	_Context->hint_PageLayout[0]=en__PageLayout;
	for (i=0; i < 8; i++)_Context->msg_PageFeed[i]=" ";
	_Context->msg_PageFeed[0]=en_PageFeed;
	_Context->msg_PageFeed[1]=fr_PageFeed;
	_Context->msg_PageFeed[2]=it_PageFeed;
	_Context->msg_PageFeed[3]=es_PageFeed;
	_Context->msg_PageFeed[4]=de_PageFeed;
	_Context->msg_PageFeed[5]=nl_PageFeed;
	_Context->msg_PageFeed[6]=pt_PageFeed;
	_Context->msg_PageFeed[7]=xx_PageFeed;
	_Context->hint_PageFeed[0]=en__PageFeed;
	for (i=0; i < 8; i++)_Context->msg_PageAlign[i]=" ";
	_Context->msg_PageAlign[0]=en_PageAlign;
	_Context->msg_PageAlign[1]=fr_PageAlign;
	_Context->msg_PageAlign[2]=it_PageAlign;
	_Context->msg_PageAlign[3]=es_PageAlign;
	_Context->msg_PageAlign[4]=de_PageAlign;
	_Context->msg_PageAlign[5]=nl_PageAlign;
	_Context->msg_PageAlign[6]=pt_PageAlign;
	_Context->msg_PageAlign[7]=xx_PageAlign;
	_Context->hint_PageAlign[0]=en__PageAlign;
	for (i=0; i < 8; i++)_Context->msg_Preview[i]=" ";
	_Context->msg_Preview[0]=en_Preview;
	_Context->msg_Preview[1]=fr_Preview;
	_Context->msg_Preview[2]=it_Preview;
	_Context->msg_Preview[3]=es_Preview;
	_Context->msg_Preview[4]=de_Preview;
	_Context->msg_Preview[5]=nl_Preview;
	_Context->msg_Preview[6]=pt_Preview;
	_Context->msg_Preview[7]=xx_Preview;
	_Context->hint_Preview[0]=en__Preview;
	_Context->hint_LeftMargin[0]=en__LeftMargin;
	for (i=0; i < 8; i++)_Context->msg_LeftMarginUnits[i]=" ";
	_Context->msg_LeftMarginUnits[0]=en_LeftMarginUnits;
	_Context->msg_LeftMarginUnits[1]=fr_LeftMarginUnits;
	_Context->msg_LeftMarginUnits[2]=it_LeftMarginUnits;
	_Context->msg_LeftMarginUnits[3]=es_LeftMarginUnits;
	_Context->msg_LeftMarginUnits[4]=de_LeftMarginUnits;
	_Context->msg_LeftMarginUnits[5]=nl_LeftMarginUnits;
	_Context->msg_LeftMarginUnits[6]=pt_LeftMarginUnits;
	_Context->msg_LeftMarginUnits[7]=xx_LeftMarginUnits;
	_Context->hint_LeftMarginUnits[0]=en__LeftMarginUnits;
	_Context->hint_TopMargin[0]=en__TopMargin;
	for (i=0; i < 8; i++)_Context->msg_TopMarginUnits[i]=" ";
	_Context->msg_TopMarginUnits[0]=en_TopMarginUnits;
	_Context->msg_TopMarginUnits[1]=fr_TopMarginUnits;
	_Context->msg_TopMarginUnits[2]=it_TopMarginUnits;
	_Context->msg_TopMarginUnits[3]=es_TopMarginUnits;
	_Context->msg_TopMarginUnits[4]=de_TopMarginUnits;
	_Context->msg_TopMarginUnits[5]=nl_TopMarginUnits;
	_Context->msg_TopMarginUnits[6]=pt_TopMarginUnits;
	_Context->msg_TopMarginUnits[7]=xx_TopMarginUnits;
	_Context->hint_TopMarginUnits[0]=en__TopMarginUnits;
	for (i=0; i < 8; i++)_Context->msg_Auto3593[i]=" ";
	_Context->msg_Auto3593[0]=en_Auto3593;
	_Context->msg_Auto3593[1]=fr_Auto3593;
	_Context->msg_Auto3593[2]=it_Auto3593;
	_Context->msg_Auto3593[3]=es_Auto3593;
	_Context->msg_Auto3593[4]=de_Auto3593;
	_Context->msg_Auto3593[5]=nl_Auto3593;
	_Context->msg_Auto3593[6]=pt_Auto3593;
	_Context->msg_Auto3593[7]=xx_Auto3593;
	for (i=0; i < 8; i++)_Context->msg_Auto3594[i]=" ";
	_Context->msg_Auto3594[0]=en_Auto3594;
	_Context->msg_Auto3594[1]=fr_Auto3594;
	_Context->msg_Auto3594[2]=it_Auto3594;
	_Context->msg_Auto3594[3]=es_Auto3594;
	_Context->msg_Auto3594[4]=de_Auto3594;
	_Context->msg_Auto3594[5]=nl_Auto3594;
	_Context->msg_Auto3594[6]=pt_Auto3594;
	_Context->msg_Auto3594[7]=xx_Auto3594;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3581,_Context->y_Auto3581,400+10,540+10);
	return(0);
}

public 	int	accept_visual_page_hide(struct accept_visual_page_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3581,_Context->y_Auto3581);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_visual_page_remove(
	struct accept_visual_page_context * _Context,
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

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSWWWWWWSWSW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_DeviceLo, 255, pDeviceLo);
		visual_transferout(_Context->buffer_DriverLo, 255, pDriverLo);
		visual_transferout(_Context->buffer_Pagination, 255, pPagination);
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

public	int	accept_visual_page_show(struct accept_visual_page_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3581,_Context->y_Auto3581);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3581,_Context->y_Auto3581,400,540,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3581,_Context->y_Auto3581,400,540,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto3581+30,_Context->y_Auto3581+260,160,16,vfh[2],16,0,_Context->msg_Auto3582[_Context->language],strlen(_Context->msg_Auto3582[_Context->language]),3);
	visual_frame(_Context->x_Auto3581+30,_Context->y_Auto3581+276,160,44,4);
	visual_text(_Context->x_Auto3581+40,_Context->y_Auto3581+20,322,40,vfh[3],16,0,_Context->msg_Auto3583[_Context->language],strlen(_Context->msg_Auto3583[_Context->language]),1283);
	visual_text(_Context->x_Auto3581+30,_Context->y_Auto3581+190,160,16,vfh[2],16,0,_Context->msg_Auto3584[_Context->language],strlen(_Context->msg_Auto3584[_Context->language]),3);
	visual_frame(_Context->x_Auto3581+30,_Context->y_Auto3581+206,160,44,4);
	visual_text(_Context->x_Auto3581+200,_Context->y_Auto3581+190,160,16,vfh[2],16,0,_Context->msg_Auto3585[_Context->language],strlen(_Context->msg_Auto3585[_Context->language]),3);
	visual_frame(_Context->x_Auto3581+200,_Context->y_Auto3581+206,160,44,4);
	visual_text(_Context->x_Auto3581+200,_Context->y_Auto3581+400,160,16,vfh[2],16,0,_Context->msg_Auto3586[_Context->language],strlen(_Context->msg_Auto3586[_Context->language]),3);
	visual_frame(_Context->x_Auto3581+200,_Context->y_Auto3581+416,160,44,4);
	visual_text(_Context->x_Auto3581+30,_Context->y_Auto3581+400,160,16,vfh[2],16,0,_Context->msg_Auto3587[_Context->language],strlen(_Context->msg_Auto3587[_Context->language]),3);
	visual_frame(_Context->x_Auto3581+30,_Context->y_Auto3581+416,160,44,4);
	visual_text(_Context->x_Auto3581+30,_Context->y_Auto3581+60,330,16,vfh[2],16,0,_Context->msg_Auto3588[_Context->language],strlen(_Context->msg_Auto3588[_Context->language]),3);
	visual_frame(_Context->x_Auto3581+30,_Context->y_Auto3581+76,330,104,4);
	visual_text(_Context->x_Auto3581+200,_Context->y_Auto3581+330,160,16,vfh[2],16,0,_Context->msg_Auto3589[_Context->language],strlen(_Context->msg_Auto3589[_Context->language]),3);
	visual_frame(_Context->x_Auto3581+200,_Context->y_Auto3581+346,160,44,4);
	visual_text(_Context->x_Auto3581+200,_Context->y_Auto3581+260,160,16,vfh[2],16,0,_Context->msg_Auto3590[_Context->language],strlen(_Context->msg_Auto3590[_Context->language]),3);
	visual_frame(_Context->x_Auto3581+200,_Context->y_Auto3581+276,160,44,4);
	visual_text(_Context->x_Auto3581+30,_Context->y_Auto3581+330,160,16,vfh[2],16,0,_Context->msg_Auto3591[_Context->language],strlen(_Context->msg_Auto3591[_Context->language]),3);
	visual_frame(_Context->x_Auto3581+30,_Context->y_Auto3581+346,160,44,4);
	visual_frame(_Context->x_Auto3581+40,_Context->y_Auto3581+90,304+2,16+2,5);
	visual_text(_Context->x_Auto3581+40+1,_Context->y_Auto3581+90+1,304,16,vfh[1],27,0,_Context->buffer_DeviceLo,255,0);
	visual_frame(_Context->x_Auto3581+40,_Context->y_Auto3581+110,304+2,16+2,5);
	visual_text(_Context->x_Auto3581+40+1,_Context->y_Auto3581+110+1,304,16,vfh[1],27,0,_Context->buffer_DriverLo,255,0);
	visual_frame(_Context->x_Auto3581+40,_Context->y_Auto3581+150,304+2,16+2,5);
	visual_text(_Context->x_Auto3581+40+1,_Context->y_Auto3581+150+1,304,16,vfh[1],0,0,_Context->buffer_Pagination,255,0);
	visual_text(_Context->x_Auto3581+40,_Context->y_Auto3581+130,300,20,vfh[2],16,0,_Context->msg_Auto3592[_Context->language],strlen(_Context->msg_Auto3592[_Context->language]),3);
	visual_select(_Context->x_Auto3581+40,_Context->y_Auto3581+220,126,64,vfh[2],27,26,parse_selection(WidgetPaperTypes,&_Context->value_PaperType),768);
	visual_select(_Context->x_Auto3581+210,_Context->y_Auto3581+220,126,64,vfh[2],27,26,parse_selection(WidgetPrintResolution,&_Context->value_PrintDensity),768);
	visual_select(_Context->x_Auto3581+40,_Context->y_Auto3581+290,140,48,vfh[2],0,0,parse_selection(_Context->msg_PageLayout[_Context->language],&_Context->value_PageLayout),768);
	visual_select(_Context->x_Auto3581+210,_Context->y_Auto3581+290,140,70,vfh[2],27,0,parse_selection(_Context->msg_PageFeed[_Context->language],&_Context->value_PageFeed),768);
	visual_select(_Context->x_Auto3581+40,_Context->y_Auto3581+360,136,64,vfh[2],0,0,parse_selection(_Context->msg_PageAlign[_Context->language],&_Context->value_PageAlign),768);
	visual_select(_Context->x_Auto3581+210,_Context->y_Auto3581+360,144,64,vfh[2],16,0,parse_selection(_Context->msg_Preview[_Context->language],&_Context->value_Preview),768);
	visual_frame(_Context->x_Auto3581+40,_Context->y_Auto3581+430,64+2,16+2,5);
	visual_text(_Context->x_Auto3581+40+1,_Context->y_Auto3581+430+1,64,16,vfh[1],27,0,_Context->buffer_LeftMargin,8,0);
	visual_select(_Context->x_Auto3581+110,_Context->y_Auto3581+430,72,48,vfh[2],0,0,parse_selection(_Context->msg_LeftMarginUnits[_Context->language],&_Context->value_LeftMarginUnits),768);
	visual_frame(_Context->x_Auto3581+210,_Context->y_Auto3581+430,64+2,16+2,5);
	visual_text(_Context->x_Auto3581+210+1,_Context->y_Auto3581+430+1,64,16,vfh[1],27,0,_Context->buffer_TopMargin,8,0);
	visual_select(_Context->x_Auto3581+280,_Context->y_Auto3581+430,72,48,vfh[2],0,0,parse_selection(_Context->msg_TopMarginUnits[_Context->language],&_Context->value_TopMarginUnits),768);
	_Context->trigger_Auto3593=visual_trigger_code(_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]));
	visual_button(_Context->x_Auto3581+130,_Context->y_Auto3581+480,56,48,vfh[2],34,0,_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]),1040);
	_Context->trigger_Auto3594=visual_trigger_code(_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]));
	visual_button(_Context->x_Auto3581+200,_Context->y_Auto3581+480,56,48,vfh[2],34,0,_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3581,_Context->y_Auto3581,400,540);

	return(0);
}

private int DeviceLo_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field provides the name of the printer device or the name ";
			mptr[1]="of the file  to which the document will be printed.  This may be a ";
			mptr[2]="constant expression or a variable providing the name at runtime.  ";
			mptr[3]="Printer names are not necessarily platform portable so care should ";
			mptr[4]="be taken  in this respect.     ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DriverLo_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field provides the name of the printer driver to be used ";
			mptr[1]="for the conversion of the document image to the format required by ";
			mptr[2]="the actual physical printer device. This name will be used as the ";
			mptr[3]="ABAL dynamic library in place of the standard  printer dynamic library.    ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Pagination_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "This edit field allows a message text to be specified that  will be ";
			mptr[1]="used to control the generation of the screen report dialog frame showing ";
			mptr[2]="print page output progression.  ";
			mptr[3]=" ";
			mptr[4]="If this message is not supplied then the page progression mechanism ";
			mptr[5]="will be inhibited.    ";
			return(visual_online_help(mptr,6));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Ce champs de saisie permet de saisir un libell� a afficher par le ";
			mptr[1]="mecanism de suivi de progression de l'edition.  ";
			mptr[2]=" ";
			mptr[3]="Le generation de ce mecanism serait inhib� si aucun  message est fourni. ";
			mptr[4]="  ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PaperType_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[34];
			mptr[0] = "This select control allows selection of the paper type from the following ";
			mptr[1]="table  ";
			mptr[2]=" ";
			mptr[3]="   ";
			mptr[4]=" Page Type Width Height  ";
			mptr[5]=" A4 595     842  ";
			mptr[6]=" A3 842     1911  ";
			mptr[7]=" A2 1911    1684  ";
			mptr[8]=" A1 1684    2384  ";
			mptr[9]=" A0 2384    3370  ";
			mptr[10]=" A10 73      105  ";
			mptr[11]=" A9 105     148  ";
			mptr[12]=" A8 148     210  ";
			mptr[13]=" A7 210     297  ";
			mptr[14]=" A6 297     420  ";
			mptr[15]=" A5 420     595  ";
			mptr[16]=" B10 91      127  ";
			mptr[17]=" B9 127     181  ";
			mptr[18]=" B8 181     258  ";
			mptr[19]=" B7 258     363  ";
			mptr[20]=" B6 363     516  ";
			mptr[21]=" B5 516     729  ";
			mptr[22]=" B4 729     1032  ";
			mptr[23]=" B3 1032    1460  ";
			mptr[24]=" B2 1460    2064  ";
			mptr[25]=" B1 2064    2920  ";
			mptr[26]=" B0 2920    4127   ";
			mptr[27]=" ";
			mptr[28]=" For draft document production models the page size will be used in ";
			mptr[29]="conjunction with the print density to determine the number of pixels ";
			mptr[30]="per page. For high quality documents the page size alone will determine ";
			mptr[31]="the number of pixels per page since print density will be used to ";
			mptr[32]="influence the colour or greyscale depth hence the print quality.  ";
			mptr[33]="   ";
			return(visual_online_help(mptr,34));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PrintDensity_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[22];
			mptr[0] = "This select control allows selection of the print density from the ";
			mptr[1]="following list  ";
			mptr[2]=" ";
			mptr[3]="   ";
			mptr[4]=" 75 dpi  ";
			mptr[5]=" 100 dpi  ";
			mptr[6]=" 150 dpi  ";
			mptr[7]=" 300 dpi  ";
			mptr[8]=" 600 dpi  ";
			mptr[9]=" 1200 dpi   ";
			mptr[10]=" ";
			mptr[11]="The effect of the print density value will depend on the document ";
			mptr[12]="model production nature. In the case of draft document models, higher ";
			mptr[13]="print density values allow more logical information to be printed ";
			mptr[14]="on a particular page size. In the case of high quality documents the ";
			mptr[15]="print density will be used to increase the overall print quality. ";
			mptr[16]=" ";
			mptr[17]=" ";
			mptr[18]="For more information to this effect please consult the document  Sing ";
			mptr[19]=": Print Document Models.  ";
			mptr[20]=" ";
			mptr[21]="      ";
			return(visual_online_help(mptr,22));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PageLayout_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This select control allows definition of the page layout, portrait ";
			mptr[1]="or vertical, landscape or horizontal.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PageFeed_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[9];
			mptr[0] = "This select control allows selection of the way in which page feeding ";
			mptr[1]="is handled between completion of individual document page images. ";
			mptr[2]=" ";
			mptr[3]=" ";
			mptr[4]="Page feeding may be performed  prior to printing the page, upon completion ";
			mptr[5]="of the  page,  or inhibited.   ";
			mptr[6]=" ";
			mptr[7]="In certain cases physical closure of the print device may be required ";
			mptr[8]="to ensure physical ejection of each page on completion.    ";
			return(visual_online_help(mptr,9));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PageAlign_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[12];
			mptr[0] = "This select control allows page alignment to be specified. Page alignment ";
			mptr[1]="will be applied when the overall output is smaller than the target ";
			mptr[2]="surface and controls the distribution of the surplus.   ";
			mptr[3]=" ";
			mptr[4]="Left alignment implies to the top left corner of the paper.  ";
			mptr[5]=" ";
			mptr[6]="Right alignment implies to the bottom right corner of the paper.  ";
			mptr[7]=" ";
			mptr[8]="The alignment value of None defaults to Center in must cases.  ";
			mptr[9]=" ";
			mptr[10]="The alignment value must be set to Margin  for the page margins may ";
			mptr[11]="take effect.   ";
			return(visual_online_help(mptr,12));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Preview_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this check control has been activated then page preview print ";
			mptr[1]="control code will be generated to allows screen preview of the document ";
			mptr[2]="when a valid printer name has not been provided.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int LeftMargin_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field, in conjunction with the following select control, ";
			mptr[1]="allows precise control over the dimensions of the left margin allowing ";
			mptr[2]="exact page positioning of the printed document.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int LeftMarginUnits_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This select control provides the units of the preceeding margin value. ";
			mptr[1]=" ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TopMargin_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "As for the left margin this edit field allows definition of the top ";
			mptr[1]="margin and will be used in conjunction with the following select control ";
			mptr[2]="providing the units.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TopMarginUnits_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This select  control determines the units of the preceeding top margin ";
			mptr[1]="parameter value.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3593_help()
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

private int Auto3594_help()
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

private int Auto3581action(struct accept_visual_page_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_visual_page_hide(_Context);

		_Context->x_Auto3581 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3581 < 0) { _Context->x_Auto3581=0; }
		_Context->y_Auto3581 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3581 < 0) { _Context->y_Auto3581=0; }
			accept_visual_page_show(_Context);

		visual_thaw(_Context->x_Auto3581,_Context->y_Auto3581,400,540);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3593_event(struct accept_visual_page_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto3594_event(struct accept_visual_page_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_visual_page_event(
struct accept_visual_page_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto3593 == mb ) return(15);
		if (_Context->trigger_Auto3594 == mb ) return(16);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3581+379) )  
	&&  (my >= (_Context->y_Auto3581+4) )  
	&&  (mx <= (_Context->x_Auto3581+396) )  
	&&  (my <= (_Context->y_Auto3581+20) )) {
		return(1);	/* Auto3581 */

		}
	if ((mx >= (_Context->x_Auto3581+363) )  
	&&  (my >= (_Context->y_Auto3581+4) )  
	&&  (mx <= (_Context->x_Auto3581+380) )  
	&&  (my <= (_Context->y_Auto3581+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vpage.htm");
			};
		return(-1);	/* Auto3581 */

		}
	if ((mx >= (_Context->x_Auto3581+347) )  
	&&  (my >= (_Context->y_Auto3581+4) )  
	&&  (mx <= (_Context->x_Auto3581+364) )  
	&&  (my <= (_Context->y_Auto3581+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_visual_page_show(_Context);
		return(-1);	/* Auto3581 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3581+4) )  
		&&  (my >= (_Context->y_Auto3581+4) )  
		&&  (mx <= (_Context->x_Auto3581+332) )  
		&&  (my <= (_Context->y_Auto3581+20) )) {
			return( Auto3581action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3581+40) ) 
	&&  ( my >= (_Context->y_Auto3581+90) ) 
	&&  ( mx <= (_Context->x_Auto3581+40+304) ) 
	&&  ( my <= (_Context->y_Auto3581+90+16))) {
		return(2); /* DeviceLo */
		}
	if (( mx >= (_Context->x_Auto3581+40) ) 
	&&  ( my >= (_Context->y_Auto3581+110) ) 
	&&  ( mx <= (_Context->x_Auto3581+40+304) ) 
	&&  ( my <= (_Context->y_Auto3581+110+16))) {
		return(3); /* DriverLo */
		}
	if (( mx >= (_Context->x_Auto3581+40) ) 
	&&  ( my >= (_Context->y_Auto3581+150) ) 
	&&  ( mx <= (_Context->x_Auto3581+40+304) ) 
	&&  ( my <= (_Context->y_Auto3581+150+16))) {
		return(4); /* Pagination */
		}
	if (( mx >= (_Context->x_Auto3581+40+0) ) 
	&&  ( my >= (_Context->y_Auto3581+220) ) 
	&&  ( mx <= (_Context->x_Auto3581+40+126) ) 
	&&  ( my <= (_Context->y_Auto3581+220+16))) {
		return(5); /* PaperType */
		}
	if (( mx >= (_Context->x_Auto3581+210+0) ) 
	&&  ( my >= (_Context->y_Auto3581+220) ) 
	&&  ( mx <= (_Context->x_Auto3581+210+126) ) 
	&&  ( my <= (_Context->y_Auto3581+220+16))) {
		return(6); /* PrintDensity */
		}
	if (( mx >= (_Context->x_Auto3581+40+0) ) 
	&&  ( my >= (_Context->y_Auto3581+290) ) 
	&&  ( mx <= (_Context->x_Auto3581+40+140) ) 
	&&  ( my <= (_Context->y_Auto3581+290+16))) {
		return(7); /* PageLayout */
		}
	if (( mx >= (_Context->x_Auto3581+210+0) ) 
	&&  ( my >= (_Context->y_Auto3581+290) ) 
	&&  ( mx <= (_Context->x_Auto3581+210+140) ) 
	&&  ( my <= (_Context->y_Auto3581+290+16))) {
		return(8); /* PageFeed */
		}
	if (( mx >= (_Context->x_Auto3581+40+0) ) 
	&&  ( my >= (_Context->y_Auto3581+360) ) 
	&&  ( mx <= (_Context->x_Auto3581+40+136) ) 
	&&  ( my <= (_Context->y_Auto3581+360+16))) {
		return(9); /* PageAlign */
		}
	if (( mx >= (_Context->x_Auto3581+210+0) ) 
	&&  ( my >= (_Context->y_Auto3581+360) ) 
	&&  ( mx <= (_Context->x_Auto3581+210+144) ) 
	&&  ( my <= (_Context->y_Auto3581+360+16))) {
		return(10); /* Preview */
		}
	if (( mx >= (_Context->x_Auto3581+40) ) 
	&&  ( my >= (_Context->y_Auto3581+430) ) 
	&&  ( mx <= (_Context->x_Auto3581+40+64) ) 
	&&  ( my <= (_Context->y_Auto3581+430+16))) {
		return(11); /* LeftMargin */
		}
	if (( mx >= (_Context->x_Auto3581+110+0) ) 
	&&  ( my >= (_Context->y_Auto3581+430) ) 
	&&  ( mx <= (_Context->x_Auto3581+110+72) ) 
	&&  ( my <= (_Context->y_Auto3581+430+16))) {
		return(12); /* LeftMarginUnits */
		}
	if (( mx >= (_Context->x_Auto3581+210) ) 
	&&  ( my >= (_Context->y_Auto3581+430) ) 
	&&  ( mx <= (_Context->x_Auto3581+210+64) ) 
	&&  ( my <= (_Context->y_Auto3581+430+16))) {
		return(13); /* TopMargin */
		}
	if (( mx >= (_Context->x_Auto3581+280+0) ) 
	&&  ( my >= (_Context->y_Auto3581+430) ) 
	&&  ( mx <= (_Context->x_Auto3581+280+72) ) 
	&&  ( my <= (_Context->y_Auto3581+430+16))) {
		return(14); /* TopMarginUnits */
		}
	if (( mx >= (_Context->x_Auto3581+130) ) 
	&&  ( my >= (_Context->y_Auto3581+480) ) 
	&&  ( mx <= (_Context->x_Auto3581+130+56) ) 
	&&  ( my <= (_Context->y_Auto3581+480+48))) {
		return(15); /* Auto3593 */
		}
	if (( mx >= (_Context->x_Auto3581+200) ) 
	&&  ( my >= (_Context->y_Auto3581+480) ) 
	&&  ( mx <= (_Context->x_Auto3581+200+56) ) 
	&&  ( my <= (_Context->y_Auto3581+480+48))) {
		return(16); /* Auto3594 */
		}

	return(-1);
}


public	int	accept_visual_page_focus(struct accept_visual_page_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* DeviceLo */
				_Context->keycode = visual_edit(_Context->x_Auto3581+40+1,_Context->y_Auto3581+90+1,304,16,vfh[1],_Context->buffer_DeviceLo,255);
			break;
			case	0x3 :
				/* DriverLo */
				_Context->keycode = visual_edit(_Context->x_Auto3581+40+1,_Context->y_Auto3581+110+1,304,16,vfh[1],_Context->buffer_DriverLo,255);
			break;
			case	0x4 :
				/* Pagination */
				_Context->keycode = visual_edit(_Context->x_Auto3581+40+1,_Context->y_Auto3581+150+1,304,16,vfh[1],_Context->buffer_Pagination,255);
			break;
			case	0x5 :
				/* PaperType */
				_Context->keycode = visual_select(_Context->x_Auto3581+40,_Context->y_Auto3581+220,126,64,vfh[2],27,26,parse_selection(WidgetPaperTypes,&_Context->value_PaperType),770);
				break;
			case	0x6 :
				/* PrintDensity */
				_Context->keycode = visual_select(_Context->x_Auto3581+210,_Context->y_Auto3581+220,126,64,vfh[2],27,26,parse_selection(WidgetPrintResolution,&_Context->value_PrintDensity),770);
				break;
			case	0x7 :
				/* PageLayout */
				_Context->keycode = visual_select(_Context->x_Auto3581+40,_Context->y_Auto3581+290,140,48,vfh[2],0,0,parse_selection(_Context->msg_PageLayout[_Context->language],&_Context->value_PageLayout),770);
				break;
			case	0x8 :
				/* PageFeed */
				_Context->keycode = visual_select(_Context->x_Auto3581+210,_Context->y_Auto3581+290,140,70,vfh[2],27,0,parse_selection(_Context->msg_PageFeed[_Context->language],&_Context->value_PageFeed),770);
				break;
			case	0x9 :
				/* PageAlign */
				_Context->keycode = visual_select(_Context->x_Auto3581+40,_Context->y_Auto3581+360,136,64,vfh[2],0,0,parse_selection(_Context->msg_PageAlign[_Context->language],&_Context->value_PageAlign),770);
				break;
			case	0xa :
				/* Preview */
				_Context->keycode = visual_select(_Context->x_Auto3581+210,_Context->y_Auto3581+360,144,64,vfh[2],16,0,parse_selection(_Context->msg_Preview[_Context->language],&_Context->value_Preview),770);
				break;
			case	0xb :
				/* LeftMargin */
				_Context->keycode = visual_edit(_Context->x_Auto3581+40+1,_Context->y_Auto3581+430+1,64,16,vfh[1],_Context->buffer_LeftMargin,8);
			break;
			case	0xc :
				/* LeftMarginUnits */
				_Context->keycode = visual_select(_Context->x_Auto3581+110,_Context->y_Auto3581+430,72,48,vfh[2],0,0,parse_selection(_Context->msg_LeftMarginUnits[_Context->language],&_Context->value_LeftMarginUnits),770);
				break;
			case	0xd :
				/* TopMargin */
				_Context->keycode = visual_edit(_Context->x_Auto3581+210+1,_Context->y_Auto3581+430+1,64,16,vfh[1],_Context->buffer_TopMargin,8);
			break;
			case	0xe :
				/* TopMarginUnits */
				_Context->keycode = visual_select(_Context->x_Auto3581+280,_Context->y_Auto3581+430,72,48,vfh[2],0,0,parse_selection(_Context->msg_TopMarginUnits[_Context->language],&_Context->value_TopMarginUnits),770);
				break;
			case	0xf :
				/* Auto3593 */
				_Context->trigger_Auto3593=visual_trigger_code(_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]));
				visual_button(_Context->x_Auto3581+130,_Context->y_Auto3581+480,56,48,vfh[2],34,0,_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3593=visual_trigger_code(_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]));
	visual_button(_Context->x_Auto3581+130,_Context->y_Auto3581+480,56,48,vfh[2],34,0,_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]),1040);
				break;
			case	0x10 :
				/* Auto3594 */
				_Context->trigger_Auto3594=visual_trigger_code(_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]));
				visual_button(_Context->x_Auto3581+200,_Context->y_Auto3581+480,56,48,vfh[2],34,0,_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3594=visual_trigger_code(_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]));
	visual_button(_Context->x_Auto3581+200,_Context->y_Auto3581+480,56,48,vfh[2],34,0,_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_visual_page_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=16;
			accept_visual_page_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_visual_page_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (DeviceLo_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (DriverLo_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Pagination_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (PaperType_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (PrintDensity_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (PageLayout_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (PageFeed_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (PageAlign_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (Preview_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (LeftMargin_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (LeftMarginUnits_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (TopMargin_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (TopMarginUnits_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (Auto3593_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (Auto3594_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3581 */
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
					/* Auto3593 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3593=visual_trigger_code(_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]));
						visual_button(_Context->x_Auto3581+130,_Context->y_Auto3581+480,56,48,vfh[2],34,0,_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3593=visual_trigger_code(_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]));
	visual_button(_Context->x_Auto3581+130,_Context->y_Auto3581+480,56,48,vfh[2],34,0,_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3593_event(_Context)) != -1) break;

						}
					continue;
				case	0x10 :
					/* Auto3594 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3594=visual_trigger_code(_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]));
						visual_button(_Context->x_Auto3581+200,_Context->y_Auto3581+480,56,48,vfh[2],34,0,_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3594=visual_trigger_code(_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]));
	visual_button(_Context->x_Auto3581+200,_Context->y_Auto3581+480,56,48,vfh[2],34,0,_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3594_event(_Context)) != -1) break;

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
	struct accept_visual_page_context * _Context=(struct accept_visual_page_context*) 0;
	status = accept_visual_page_create(
	&_Context,
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
	status = accept_visual_page_show(_Context);
		enter_modal();
	status = accept_visual_page_focus(_Context);
		leave_modal();
	status = accept_visual_page_hide(_Context);
	status = accept_visual_page_remove(
	_Context,
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
