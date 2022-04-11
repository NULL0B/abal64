
#ifndef _vfexport_c
#define _vfexport_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vfexport.xml                                             */
/* Target         : vfexport.c                                               */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Auto3627   "Sing : Version 2.1a"
#define en__Auto3627   ""
#define en_Auto3628   "Font   Export   Parameters"
#define en__Auto3628   ""
#define en_Auto3630   "Image File"
#define en__Auto3630   ""
#define en_Auto3631   "Font"
#define en__Auto3631   ""
#define en_Auto3632   "Font Width"
#define en__Auto3632   ""
#define en_Auto3633   "Font Height"
#define en__Auto3633   ""
#define en_Auto3634   "Align"
#define en__Auto3634   ""
#define en_Auto3635   "Foreground"
#define en__Auto3635   ""
#define en_Auto3636   "Background"
#define en__Auto3636   ""
#define en_Auto3637   "Padd Width"
#define en__Auto3637   ""
#define en_Auto3638   "Padd Height"
#define en__Auto3638   ""
#define en_FontFileName   ""
#define fr_FontFileName   ""
#define it_FontFileName   ""
#define es_FontFileName   ""
#define de_FontFileName   ""
#define nl_FontFileName   ""
#define pt_FontFileName   ""
#define xx_FontFileName   ""
#define en__FontFileName   ""
#define fr__FontFileName   ""
#define it__FontFileName   ""
#define es__FontFileName   ""
#define de__FontFileName   ""
#define nl__FontFileName   ""
#define pt__FontFileName   ""
#define xx__FontFileName   ""
#define en__TextFont   ""
#define fr__TextFont   ""
#define en_FontWidth   ""
#define en__FontWidth   ""
#define en_FontHeight   ""
#define en__FontHeight   ""
#define en_IsBold   "Bold"
#define fr_IsBold   "Gras"
#define it_IsBold   "Bold"
#define es_IsBold   "Bold"
#define de_IsBold   "Bold"
#define nl_IsBold   "Bold"
#define pt_IsBold   "Bold"
#define xx_IsBold   "Bold"
#define en__IsBold   ""
#define fr__IsBold   ""
#define it__IsBold   ""
#define es__IsBold   ""
#define de__IsBold   ""
#define nl__IsBold   ""
#define pt__IsBold   ""
#define xx__IsBold   ""
#define en_vPadd   ""
#define en__vPadd   ""
#define en_hPadd   ""
#define en__hPadd   ""
#define en__Align   ""
#define fr__Align   ""
#define it__Align   ""
#define es__Align   ""
#define de__Align   ""
#define nl__Align   ""
#define pt__Align   ""
#define xx__Align   ""
#define en_FgColour   ""
#define en__FgColour   ""
#define en_BgColour   ""
#define en__BgColour   ""
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

private struct accept_font_export_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3627[8];
	char * hint_Auto3627[8];
	int	x_Auto3627;
	int	y_Auto3627;
	int	w_Auto3627;
	int	h_Auto3627;
	char * msg_Auto3628[8];
	char * hint_Auto3628[8];
	char * hint_Auto3629[8];
	char * msg_Auto3630[8];
	char * hint_Auto3630[8];
	char * msg_Auto3631[8];
	char * hint_Auto3631[8];
	char * msg_Auto3632[8];
	char * hint_Auto3632[8];
	char * msg_Auto3633[8];
	char * hint_Auto3633[8];
	char * msg_Auto3634[8];
	char * hint_Auto3634[8];
	char * msg_Auto3635[8];
	char * hint_Auto3635[8];
	char * msg_Auto3636[8];
	char * hint_Auto3636[8];
	char * msg_Auto3637[8];
	char * hint_Auto3637[8];
	char * msg_Auto3638[8];
	char * hint_Auto3638[8];
	char * hint_FontFileName[8];
	char	buffer_FontFileName[256];
	char * msg_TextFont[8];
	char * hint_TextFont[8];
	int	value_TextFont;
	char * hint_FontWidth[8];
	char	buffer_FontWidth[11];
	char * hint_FontHeight[8];
	char	buffer_FontHeight[9];
	char * msg_IsBold[8];
	int	trigger_IsBold;
	char * hint_IsBold[8];
	int	value_IsBold;
	char * hint_vPadd[8];
	char	buffer_vPadd[9];
	char * hint_hPadd[8];
	char	buffer_hPadd[9];
	char * msg_Align[8];
	char * hint_Align[8];
	int	value_Align;
	char * hint_FgColour[8];
	char	buffer_FgColour[11];
	char * hint_BgColour[8];
	char	buffer_BgColour[11];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[9];
	};
static int	vfh[16];
private int on_FontWidth_show(struct accept_font_export_context * _Context);
private int on_FontHeight_show(struct accept_font_export_context * _Context);
private int on_TextFont_event(struct accept_font_export_context * _Context);
private int on_Accept_event(struct accept_font_export_context * _Context);
private int on_Cancel_event(struct accept_font_export_context * _Context);

public	int	accept_font_export_create(
	struct accept_font_export_context ** cptr,
	char * pFontFileName,
	char * pTextFont,
	char * pIsBold,
	char * pvPadd,
	char * phPadd,
	char * pAlign,
	char * pFgColour,
	char * pBgColour)
{

	int i;
	struct accept_font_export_context * _Context=(struct accept_font_export_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_font_export_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=13;
		for (i=0; i < 10; i++)  *(_Context->buffer_FontWidth+i)=' ';
		for (i=0; i < 8; i++)  *(_Context->buffer_FontHeight+i)=' ';
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FontFileName, 255, pFontFileName);
		visual_transferin((void *) 0, 0, pTextFont);
		if (!( pTextFont )) _Context->value_TextFont=0;
		else	_Context->value_TextFont = *((int *)pTextFont);
		visual_transferin((void *) 0, 0, pIsBold);
		if (!( pIsBold )) _Context->value_IsBold=0;
		else	_Context->value_IsBold = *((int *)pIsBold);
		visual_transferin(_Context->buffer_vPadd, 8, pvPadd);
		visual_transferin(_Context->buffer_hPadd, 8, phPadd);
		visual_transferin((void *) 0, 0, pAlign);
		if (!( pAlign )) _Context->value_Align=0;
		else	_Context->value_Align = *((int *)pAlign);
		visual_transferin(_Context->buffer_FgColour, 10, pFgColour);
		visual_transferin(_Context->buffer_BgColour, 10, pBgColour);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3627[i]=" ";
	_Context->msg_Auto3627[0]=en_Auto3627;
	_Context->hint_Auto3627[0]=en__Auto3627;
	_Context->x_Auto3627=95;
	_Context->y_Auto3627=165;
	_Context->w_Auto3627=610;
	_Context->h_Auto3627=270;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3628[i]=" ";
	_Context->msg_Auto3628[0]=en_Auto3628;
	_Context->hint_Auto3628[0]=en__Auto3628;
	for (i=0; i < 8; i++)_Context->msg_Auto3630[i]=" ";
	_Context->msg_Auto3630[0]=en_Auto3630;
	_Context->hint_Auto3630[0]=en__Auto3630;
	for (i=0; i < 8; i++)_Context->msg_Auto3631[i]=" ";
	_Context->msg_Auto3631[0]=en_Auto3631;
	_Context->hint_Auto3631[0]=en__Auto3631;
	for (i=0; i < 8; i++)_Context->msg_Auto3632[i]=" ";
	_Context->msg_Auto3632[0]=en_Auto3632;
	_Context->hint_Auto3632[0]=en__Auto3632;
	for (i=0; i < 8; i++)_Context->msg_Auto3633[i]=" ";
	_Context->msg_Auto3633[0]=en_Auto3633;
	_Context->hint_Auto3633[0]=en__Auto3633;
	for (i=0; i < 8; i++)_Context->msg_Auto3634[i]=" ";
	_Context->msg_Auto3634[0]=en_Auto3634;
	_Context->hint_Auto3634[0]=en__Auto3634;
	for (i=0; i < 8; i++)_Context->msg_Auto3635[i]=" ";
	_Context->msg_Auto3635[0]=en_Auto3635;
	_Context->hint_Auto3635[0]=en__Auto3635;
	for (i=0; i < 8; i++)_Context->msg_Auto3636[i]=" ";
	_Context->msg_Auto3636[0]=en_Auto3636;
	_Context->hint_Auto3636[0]=en__Auto3636;
	for (i=0; i < 8; i++)_Context->msg_Auto3637[i]=" ";
	_Context->msg_Auto3637[0]=en_Auto3637;
	_Context->hint_Auto3637[0]=en__Auto3637;
	for (i=0; i < 8; i++)_Context->msg_Auto3638[i]=" ";
	_Context->msg_Auto3638[0]=en_Auto3638;
	_Context->hint_Auto3638[0]=en__Auto3638;
	_Context->hint_FontFileName[0]=en__FontFileName;
	_Context->hint_FontFileName[1]=fr__FontFileName;
	_Context->hint_FontFileName[2]=it__FontFileName;
	_Context->hint_FontFileName[3]=es__FontFileName;
	_Context->hint_FontFileName[4]=de__FontFileName;
	_Context->hint_FontFileName[5]=nl__FontFileName;
	_Context->hint_FontFileName[6]=pt__FontFileName;
	_Context->hint_FontFileName[7]=xx__FontFileName;
	for (i=0; i < 8; i++)_Context->msg_TextFont[i]=" ";
	_Context->hint_TextFont[0]=en__TextFont;
	_Context->hint_TextFont[1]=fr__TextFont;
	_Context->hint_FontWidth[0]=en__FontWidth;
	_Context->hint_FontHeight[0]=en__FontHeight;
	for (i=0; i < 8; i++)_Context->msg_IsBold[i]=" ";
	_Context->msg_IsBold[0]=en_IsBold;
	_Context->msg_IsBold[1]=fr_IsBold;
	_Context->msg_IsBold[2]=it_IsBold;
	_Context->msg_IsBold[3]=es_IsBold;
	_Context->msg_IsBold[4]=de_IsBold;
	_Context->msg_IsBold[5]=nl_IsBold;
	_Context->msg_IsBold[6]=pt_IsBold;
	_Context->msg_IsBold[7]=xx_IsBold;
	_Context->hint_IsBold[0]=en__IsBold;
	_Context->hint_IsBold[1]=fr__IsBold;
	_Context->hint_IsBold[2]=it__IsBold;
	_Context->hint_IsBold[3]=es__IsBold;
	_Context->hint_IsBold[4]=de__IsBold;
	_Context->hint_IsBold[5]=nl__IsBold;
	_Context->hint_IsBold[6]=pt__IsBold;
	_Context->hint_IsBold[7]=xx__IsBold;
	_Context->hint_vPadd[0]=en__vPadd;
	_Context->hint_hPadd[0]=en__hPadd;
	for (i=0; i < 8; i++)_Context->msg_Align[i]=" ";
	_Context->hint_Align[0]=en__Align;
	_Context->hint_Align[1]=fr__Align;
	_Context->hint_Align[2]=it__Align;
	_Context->hint_Align[3]=es__Align;
	_Context->hint_Align[4]=de__Align;
	_Context->hint_Align[5]=nl__Align;
	_Context->hint_Align[6]=pt__Align;
	_Context->hint_Align[7]=xx__Align;
	_Context->hint_FgColour[0]=en__FgColour;
	_Context->hint_BgColour[0]=en__BgColour;
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
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3627,_Context->y_Auto3627,610+10,270+10);
	return(0);
}

public 	int	accept_font_export_hide(struct accept_font_export_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3627,_Context->y_Auto3627);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_font_export_remove(
	struct accept_font_export_context * _Context,
	char * pFontFileName,
	char * pTextFont,
	char * pIsBold,
	char * pvPadd,
	char * phPadd,
	char * pAlign,
	char * pFgColour,
	char * pBgColour)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FontFileName, 255, pFontFileName);
		visual_transferout((void *) 0, 0, pTextFont);
		if ( pTextFont != (char *) 0)
			*((int*)pTextFont) = _Context->value_TextFont;
		visual_transferout((void *) 0, 0, pIsBold);
		if ( pIsBold != (char *) 0)
			*((int*)pIsBold) = _Context->value_IsBold;
		visual_transferout(_Context->buffer_vPadd, 8, pvPadd);
		visual_transferout(_Context->buffer_hPadd, 8, phPadd);
		visual_transferout((void *) 0, 0, pAlign);
		if ( pAlign != (char *) 0)
			*((int*)pAlign) = _Context->value_Align;
		visual_transferout(_Context->buffer_FgColour, 10, pFgColour);
		visual_transferout(_Context->buffer_BgColour, 10, pBgColour);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_FontWidth_show(struct accept_font_export_context * _Context) {
	int v;
	v=(guifontsize((_Context->value_TextFont+1))&0x00FF);
	sprintf(_Context->buffer_FontWidth,"%u",v);
	visual_frame(_Context->x_Auto3627+130,_Context->y_Auto3627+140,80+2,16+2,5);
visual_text(_Context->x_Auto3627+130+1,_Context->y_Auto3627+140+1,80,16,vfh[1],0,0,_Context->buffer_FontWidth,10,0);
;
	return(-1);
}
private int on_FontHeight_show(struct accept_font_export_context * _Context) {
	int v;
	v=guifontsize((_Context->value_TextFont+1));
	v>>=8;
	sprintf(_Context->buffer_FontHeight,"%u",v);
	visual_frame(_Context->x_Auto3627+320,_Context->y_Auto3627+140,64+2,16+2,5);
visual_text(_Context->x_Auto3627+320+1,_Context->y_Auto3627+140+1,64,16,vfh[1],0,0,_Context->buffer_FontHeight,8,0);
;
	return(-1);
}

public	int	accept_font_export_show(struct accept_font_export_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3627,_Context->y_Auto3627);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto3627,_Context->y_Auto3627,610,270,vfh[2],_Context->msg_Auto3627[_Context->language],strlen(_Context->msg_Auto3627[_Context->language]),0x407);
	visual_text(_Context->x_Auto3627+10,_Context->y_Auto3627+20,590,40,vfh[6],16,0,_Context->msg_Auto3628[_Context->language],strlen(_Context->msg_Auto3628[_Context->language]),1283);
	visual_frame(_Context->x_Auto3627+10,_Context->y_Auto3627+60,590,200,4);
	visual_text(_Context->x_Auto3627+20,_Context->y_Auto3627+70,96,16,vfh[2],16,0,_Context->msg_Auto3630[_Context->language],strlen(_Context->msg_Auto3630[_Context->language]),1);
	visual_text(_Context->x_Auto3627+20,_Context->y_Auto3627+100,96,16,vfh[2],16,0,_Context->msg_Auto3631[_Context->language],strlen(_Context->msg_Auto3631[_Context->language]),1);
	visual_text(_Context->x_Auto3627+20,_Context->y_Auto3627+140,96,16,vfh[2],16,0,_Context->msg_Auto3632[_Context->language],strlen(_Context->msg_Auto3632[_Context->language]),1);
	visual_text(_Context->x_Auto3627+210,_Context->y_Auto3627+140,98,16,vfh[2],16,0,_Context->msg_Auto3633[_Context->language],strlen(_Context->msg_Auto3633[_Context->language]),1);
	visual_text(_Context->x_Auto3627+30,_Context->y_Auto3627+170,84,16,vfh[2],16,0,_Context->msg_Auto3634[_Context->language],strlen(_Context->msg_Auto3634[_Context->language]),1);
	visual_text(_Context->x_Auto3627+20,_Context->y_Auto3627+200,96,16,vfh[2],16,0,_Context->msg_Auto3635[_Context->language],strlen(_Context->msg_Auto3635[_Context->language]),1);
	visual_text(_Context->x_Auto3627+20,_Context->y_Auto3627+220,96,16,vfh[2],16,0,_Context->msg_Auto3636[_Context->language],strlen(_Context->msg_Auto3636[_Context->language]),1);
	visual_text(_Context->x_Auto3627+210,_Context->y_Auto3627+200,98,16,vfh[2],16,0,_Context->msg_Auto3637[_Context->language],strlen(_Context->msg_Auto3637[_Context->language]),1);
	visual_text(_Context->x_Auto3627+210,_Context->y_Auto3627+220,96,16,vfh[2],16,0,_Context->msg_Auto3638[_Context->language],strlen(_Context->msg_Auto3638[_Context->language]),1);
	visual_frame(_Context->x_Auto3627+130,_Context->y_Auto3627+70,440+2,16+2,5);
	visual_text(_Context->x_Auto3627+130+1,_Context->y_Auto3627+70+1,440,16,vfh[1],27,28,_Context->buffer_FontFileName,255,0);
	visual_select(_Context->x_Auto3627+130,_Context->y_Auto3627+100,252,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),768);
	(void) on_FontWidth_show(_Context);
	(void) on_FontHeight_show(_Context);
	_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_Auto3627+320,_Context->y_Auto3627+170,70,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
	visual_frame(_Context->x_Auto3627+320,_Context->y_Auto3627+220,64+2,16+2,5);
	visual_text(_Context->x_Auto3627+320+1,_Context->y_Auto3627+220+1,64,16,vfh[1],27,28,_Context->buffer_vPadd,8,0);
	visual_frame(_Context->x_Auto3627+320,_Context->y_Auto3627+200,64+2,16+2,5);
	visual_text(_Context->x_Auto3627+320+1,_Context->y_Auto3627+200+1,64,16,vfh[1],27,28,_Context->buffer_hPadd,8,0);
	visual_select(_Context->x_Auto3627+130,_Context->y_Auto3627+170,112,96,vfh[2],0,0,parse_selection(WidgetOptionList(_TEXT_FRAME),&_Context->value_Align),768);
	visual_frame(_Context->x_Auto3627+130,_Context->y_Auto3627+200,80+2,16+2,5);
	visual_text(_Context->x_Auto3627+130+1,_Context->y_Auto3627+200+1,80,16,vfh[1],27,28,_Context->buffer_FgColour,10,0);
	visual_frame(_Context->x_Auto3627+130,_Context->y_Auto3627+220,80+2,16+2,5);
	visual_text(_Context->x_Auto3627+130+1,_Context->y_Auto3627+220+1,80,16,vfh[1],27,28,_Context->buffer_BgColour,10,0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3627+470,_Context->y_Auto3627+130,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3627+470,_Context->y_Auto3627+190,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3627,_Context->y_Auto3627,610,270);

	return(0);
}

private int FontFileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Here you must specify the filename of the file to which the exported ";
			mptr[1]="font image is to be saved.  ";
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
			char * mptr[9];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]="This control allows selection of the text font used for the export ";
			mptr[3]="operation.  ";
			mptr[4]=" ";
			mptr[5]="The initial value of this field will be provided by the font editor ";
			mptr[6]="on startup.  ";
			mptr[7]=" ";
			mptr[8]="   ";
			return(visual_online_help(mptr,9));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Police de caractŠres pour le texte … afficher. ";
			mptr[1]=" Vous retrouverez dans le programme la valeur num‚rique de ce champ ";
			mptr[2]=" en utilisant la propri‚t‚ this.FONT. ";
			mptr[3]=" Les dimensions de la police sont donn‚es par les propri‚t‚s this.FONTWIDTH ";
			mptr[4]="et this.FONTHEIGHT.      ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FontWidth_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" This display field shows the character cell width of the font selected ";
			mptr[3]="for export.  ";
			mptr[4]=" ";
			mptr[5]="   ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FontHeight_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" This display field shows the character cell height of the font selected ";
			mptr[3]="for export.  ";
			mptr[4]=" ";
			mptr[5]="   ";
			return(visual_online_help(mptr,6));
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
			char * mptr[6];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]="The font characters will be printed to the exported image using the ";
			mptr[3]="bold atribut when this control is checked.  ";
			mptr[4]=" ";
			mptr[5]="       ";
			return(visual_online_help(mptr,6));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Affichage du texte en gras.  ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int vPadd_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[7];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" This edit field allows a vertical padding value to be specified to ";
			mptr[3]="allow the character cell height to be increased during the export ";
			mptr[4]="print operation.  ";
			mptr[5]=" ";
			mptr[6]="   ";
			return(visual_online_help(mptr,7));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int hPadd_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[7];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" This edit field allows a horizontal padd value to be specified to ";
			mptr[3]="allow the character cell width to be increased during the export print ";
			mptr[4]="operation.  ";
			mptr[5]=" ";
			mptr[6]="   ";
			return(visual_online_help(mptr,7));
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
			char * mptr[6];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" This control allows the alignement option to be specified for the ";
			mptr[3]="printing of the font characters to the exported image.  ";
			mptr[4]=" ";
			mptr[5]="    ";
			return(visual_online_help(mptr,6));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Liste des possibilit‚s mises … disposition pour aligner un texte. ";
			mptr[1]="   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FgColour_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" Here the foreground or text colour may be specified for the colour ";
			mptr[3]="of the characters printed to the exported font image.  ";
			mptr[4]=" ";
			mptr[5]="   ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int BgColour_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" Here the background colour may be specified to be used for the characters ";
			mptr[3]="printed to the exported font image.  ";
			mptr[4]=" ";
			mptr[5]="   ";
			return(visual_online_help(mptr,6));
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
			char * mptr[7];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" By pressing the ACCEPT button any changes made to the various parameters ";
			mptr[3]="will take effect and the font export to image operation will proceed. ";
			mptr[4]=" ";
			mptr[5]=" ";
			mptr[6]="   ";
			return(visual_online_help(mptr,7));
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
			char * mptr[7];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" By pressing the CANCEL button any modifications performed will be ";
			mptr[3]="discarded and the font export to image operation will be abandoned. ";
			mptr[4]=" ";
			mptr[5]=" ";
			mptr[6]="   ";
			return(visual_online_help(mptr,7));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3627action(struct accept_font_export_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_font_export_hide(_Context);

		_Context->x_Auto3627 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3627 < 0) { _Context->x_Auto3627=0; }
		_Context->y_Auto3627 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3627 < 0) { _Context->y_Auto3627=0; }
			accept_font_export_show(_Context);

		visual_thaw(_Context->x_Auto3627,_Context->y_Auto3627,610,270);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_TextFont_event(struct accept_font_export_context * _Context) {
	on_FontWidth_show(_Context);
	on_FontHeight_show(_Context);
	return(-1);
}
private int on_Accept_event(struct accept_font_export_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_font_export_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_font_export_event(
struct accept_font_export_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsBold == mb ) return(6);
		if (_Context->trigger_Accept == mb ) return(12);
		if (_Context->trigger_Cancel == mb ) return(13);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3627+589) )  
	&&  (my >= (_Context->y_Auto3627+4) )  
	&&  (mx <= (_Context->x_Auto3627+606) )  
	&&  (my <= (_Context->y_Auto3627+20) )) {
		return(1);	/* Auto3627 */

		}
	if ((mx >= (_Context->x_Auto3627+573) )  
	&&  (my >= (_Context->y_Auto3627+4) )  
	&&  (mx <= (_Context->x_Auto3627+590) )  
	&&  (my <= (_Context->y_Auto3627+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vfexport.htm");
			};
		return(-1);	/* Auto3627 */

		}
	if ((mx >= (_Context->x_Auto3627+557) )  
	&&  (my >= (_Context->y_Auto3627+4) )  
	&&  (mx <= (_Context->x_Auto3627+574) )  
	&&  (my <= (_Context->y_Auto3627+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_font_export_show(_Context);
		return(-1);	/* Auto3627 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3627+4) )  
		&&  (my >= (_Context->y_Auto3627+4) )  
		&&  (mx <= (_Context->x_Auto3627+542) )  
		&&  (my <= (_Context->y_Auto3627+20) )) {
			return( Auto3627action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3627+130) ) 
	&&  ( my >= (_Context->y_Auto3627+70) ) 
	&&  ( mx <= (_Context->x_Auto3627+130+440) ) 
	&&  ( my <= (_Context->y_Auto3627+70+16))) {
		return(2); /* FontFileName */
		}
	if (( mx >= (_Context->x_Auto3627+130+0) ) 
	&&  ( my >= (_Context->y_Auto3627+100) ) 
	&&  ( mx <= (_Context->x_Auto3627+130+252) ) 
	&&  ( my <= (_Context->y_Auto3627+100+16))) {
		return(3); /* TextFont */
		}
	if (( mx >= (_Context->x_Auto3627+130) ) 
	&&  ( my >= (_Context->y_Auto3627+140) ) 
	&&  ( mx <= (_Context->x_Auto3627+130+80) ) 
	&&  ( my <= (_Context->y_Auto3627+140+16))) {
		return(4); /* FontWidth */
		}
	if (( mx >= (_Context->x_Auto3627+320) ) 
	&&  ( my >= (_Context->y_Auto3627+140) ) 
	&&  ( mx <= (_Context->x_Auto3627+320+64) ) 
	&&  ( my <= (_Context->y_Auto3627+140+16))) {
		return(5); /* FontHeight */
		}
	if (( mx >= (_Context->x_Auto3627+320) ) 
	&&  ( my >= (_Context->y_Auto3627+170) ) 
	&&  ( mx <= (_Context->x_Auto3627+320+70) ) 
	&&  ( my <= (_Context->y_Auto3627+170+16))) {
		return(6); /* IsBold */
		}
	if (( mx >= (_Context->x_Auto3627+320) ) 
	&&  ( my >= (_Context->y_Auto3627+220) ) 
	&&  ( mx <= (_Context->x_Auto3627+320+64) ) 
	&&  ( my <= (_Context->y_Auto3627+220+16))) {
		return(7); /* vPadd */
		}
	if (( mx >= (_Context->x_Auto3627+320) ) 
	&&  ( my >= (_Context->y_Auto3627+200) ) 
	&&  ( mx <= (_Context->x_Auto3627+320+64) ) 
	&&  ( my <= (_Context->y_Auto3627+200+16))) {
		return(8); /* hPadd */
		}
	if (( mx >= (_Context->x_Auto3627+130+0) ) 
	&&  ( my >= (_Context->y_Auto3627+170) ) 
	&&  ( mx <= (_Context->x_Auto3627+130+112) ) 
	&&  ( my <= (_Context->y_Auto3627+170+16))) {
		return(9); /* Align */
		}
	if (( mx >= (_Context->x_Auto3627+130) ) 
	&&  ( my >= (_Context->y_Auto3627+200) ) 
	&&  ( mx <= (_Context->x_Auto3627+130+80) ) 
	&&  ( my <= (_Context->y_Auto3627+200+16))) {
		return(10); /* FgColour */
		}
	if (( mx >= (_Context->x_Auto3627+130) ) 
	&&  ( my >= (_Context->y_Auto3627+220) ) 
	&&  ( mx <= (_Context->x_Auto3627+130+80) ) 
	&&  ( my <= (_Context->y_Auto3627+220+16))) {
		return(11); /* BgColour */
		}
	if (( mx >= (_Context->x_Auto3627+470) ) 
	&&  ( my >= (_Context->y_Auto3627+130) ) 
	&&  ( mx <= (_Context->x_Auto3627+470+56) ) 
	&&  ( my <= (_Context->y_Auto3627+130+48))) {
		return(12); /* Accept */
		}
	if (( mx >= (_Context->x_Auto3627+470) ) 
	&&  ( my >= (_Context->y_Auto3627+190) ) 
	&&  ( mx <= (_Context->x_Auto3627+470+56) ) 
	&&  ( my <= (_Context->y_Auto3627+190+48))) {
		return(13); /* Cancel */
		}

	return(-1);
}


public	int	accept_font_export_focus(struct accept_font_export_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FontFileName */
				_Context->keycode = visual_edit(_Context->x_Auto3627+130+1,_Context->y_Auto3627+70+1,440,16,vfh[1],_Context->buffer_FontFileName,255);
			break;
			case	0x3 :
				/* TextFont */
				_Context->keycode = visual_select(_Context->x_Auto3627+130,_Context->y_Auto3627+100,252,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),770);
				on_FontWidth_show(_Context);
				on_FontHeight_show(_Context);
				break;
			case	0x6 :
				/* IsBold */
				visual_check(_Context->x_Auto3627+320,_Context->y_Auto3627+170,70,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),(_Context->value_IsBold |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_Auto3627+320,_Context->y_Auto3627+170,70,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
				break;
			case	0x7 :
				/* vPadd */
				_Context->keycode = visual_edit(_Context->x_Auto3627+320+1,_Context->y_Auto3627+220+1,64,16,vfh[1],_Context->buffer_vPadd,8);
			break;
			case	0x8 :
				/* hPadd */
				_Context->keycode = visual_edit(_Context->x_Auto3627+320+1,_Context->y_Auto3627+200+1,64,16,vfh[1],_Context->buffer_hPadd,8);
			break;
			case	0x9 :
				/* Align */
				_Context->keycode = visual_select(_Context->x_Auto3627+130,_Context->y_Auto3627+170,112,96,vfh[2],0,0,parse_selection(WidgetOptionList(_TEXT_FRAME),&_Context->value_Align),770);
				break;
			case	0xa :
				/* FgColour */
				_Context->keycode = visual_edit(_Context->x_Auto3627+130+1,_Context->y_Auto3627+200+1,80,16,vfh[1],_Context->buffer_FgColour,10);
			break;
			case	0xb :
				/* BgColour */
				_Context->keycode = visual_edit(_Context->x_Auto3627+130+1,_Context->y_Auto3627+220+1,80,16,vfh[1],_Context->buffer_BgColour,10);
			break;
			case	0xc :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(_Context->x_Auto3627+470,_Context->y_Auto3627+130,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3627+470,_Context->y_Auto3627+130,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0xd :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_Auto3627+470,_Context->y_Auto3627+190,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3627+470,_Context->y_Auto3627+190,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_font_export_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=13;
			accept_font_export_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_font_export_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (FontFileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (TextFont_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (FontWidth_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (FontHeight_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (IsBold_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (vPadd_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (hPadd_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (Align_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (FgColour_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (BgColour_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (Accept_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (Cancel_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3627 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* FontFileName */
					continue;
				case	0x3 :
					/* TextFont */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_TextFont_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* FontWidth */
					continue;
				case	0x5 :
					/* FontHeight */
					continue;
				case	0x6 :
					/* IsBold */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsBold += 1;
						_Context->value_IsBold &= 1;
						}
					continue;
				case	0x7 :
					/* vPadd */
					continue;
				case	0x8 :
					/* hPadd */
					continue;
				case	0x9 :
					/* Align */
					continue;
				case	0xa :
					/* FgColour */
					continue;
				case	0xb :
					/* BgColour */
					continue;
				case	0xc :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_Auto3627+470,_Context->y_Auto3627+130,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3627+470,_Context->y_Auto3627+130,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0xd :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Auto3627+470,_Context->y_Auto3627+190,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3627+470,_Context->y_Auto3627+190,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
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
				_Context->focus_item=13;
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

public	int	accept_font_export(
	char * pFontFileName,
	char * pTextFont,
	char * pIsBold,
	char * pvPadd,
	char * phPadd,
	char * pAlign,
	char * pFgColour,
	char * pBgColour)
{
	int	status=0;
	struct accept_font_export_context * _Context=(struct accept_font_export_context*) 0;
	status = accept_font_export_create(
	&_Context,
	 pFontFileName,
	 pTextFont,
	 pIsBold,
	 pvPadd,
	 phPadd,
	 pAlign,
	 pFgColour,
	 pBgColour);
	if ( status != 0) return(status);
	status = accept_font_export_show(_Context);
		enter_modal();
	status = accept_font_export_focus(_Context);
		leave_modal();
	status = accept_font_export_hide(_Context);
	status = accept_font_export_remove(
	_Context,
	 pFontFileName,
	 pTextFont,
	 pIsBold,
	 pvPadd,
	 phPadd,
	 pAlign,
	 pFgColour,
	 pBgColour);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vfexport_c */
