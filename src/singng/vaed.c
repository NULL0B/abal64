
#ifndef _vaed_c
#define _vaed_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vaed.xml                                                 */
/* Target         : vaed.c                                                   */
/* Identification : 0.0-1177511933-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto2703   ""
#define fr__Auto2703   ""
#define it__Auto2703   ""
#define es__Auto2703   ""
#define de__Auto2703   ""
#define nl__Auto2703   ""
#define pt__Auto2703   ""
#define xx__Auto2703   ""
#define en_Auto2704   "Normal"
#define fr_Auto2704   "Normal"
#define it_Auto2704   "Normal"
#define es_Auto2704   "Normal"
#define de_Auto2704   "Normal"
#define nl_Auto2704   "Normal"
#define pt_Auto2704   "Normal"
#define xx_Auto2704   "Normal"
#define en_Auto2705   "Strings"
#define fr_Auto2705   "ChaŒnes"
#define it_Auto2705   "Strings"
#define es_Auto2705   "Strings"
#define de_Auto2705   "Strings"
#define nl_Auto2705   "Strings"
#define pt_Auto2705   "Strings"
#define xx_Auto2705   "Strings"
#define en_Auto2706   "Keywords"
#define fr_Auto2706   "Mots cl‚s"
#define it_Auto2706   "Keywords"
#define es_Auto2706   "Keywords"
#define de_Auto2706   "Keywords"
#define nl_Auto2706   "Keywords"
#define pt_Auto2706   "Keywords"
#define xx_Auto2706   "Keywords"
#define en_Auto2707   "Comments"
#define fr_Auto2707   "Commentaires"
#define it_Auto2707   "Comments"
#define es_Auto2707   "Comments"
#define de_Auto2707   "Comments"
#define nl_Auto2707   "Comments"
#define pt_Auto2707   "Comments"
#define xx_Auto2707   "Comments"
#define en_Auto2708   "Abal Editor Configuration"
#define fr_Auto2708   "Configuration de l'Editeur ABAL"
#define it_Auto2708   "Abal Editor Configuration"
#define es_Auto2708   "Abal Editor Configuration"
#define de_Auto2708   "Abal Editor Configuration"
#define nl_Auto2708   "Abal Editor Configuration"
#define pt_Auto2708   "Abal Editor Configuration"
#define xx_Auto2708   "Abal Editor Configuration"
#define en_auto777   "Name of file to Edit"
#define fr_auto777   "Nom du fichier … ‚diter"
#define it_auto777   "Name of file to Edit"
#define es_auto777   "Name of file to Edit"
#define de_auto777   "Name of file to Edit"
#define nl_auto777   "Name of file to Edit"
#define pt_auto777   "Name of file to Edit"
#define xx_auto777   "Name of file to Edit"
#define en__auto777   ""
#define fr__auto777   ""
#define it__auto777   ""
#define es__auto777   ""
#define de__auto777   ""
#define nl__auto777   ""
#define pt__auto777   ""
#define xx__auto777   ""
#define en_FileName   ""
#define fr_FileName   ""
#define it_FileName   ""
#define es_FileName   ""
#define de_FileName   ""
#define nl_FileName   ""
#define pt_FileName   ""
#define xx_FileName   ""
#define en_auto599   "Path and Filename of Editor"
#define fr_auto599   "Chemin et nom de l'‚diteur"
#define it_auto599   "Path and Filename of Editor"
#define es_auto599   "Path and Filename of Editor"
#define de_auto599   "Path and Filename of Editor"
#define nl_auto599   "Path and Filename of Editor"
#define pt_auto599   "Path and Filename of Editor"
#define xx_auto599   "Path and Filename of Editor"
#define en__auto599   ""
#define fr__auto599   ""
#define it__auto599   ""
#define es__auto599   ""
#define de__auto599   ""
#define nl__auto599   ""
#define pt__auto599   ""
#define xx__auto599   ""
#define en_EditorName   ""
#define en_Auto2709   "ok.gif"
#define fr_Auto2709   "ok.gif"
#define it_Auto2709   "ok.gif"
#define es_Auto2709   "ok.gif"
#define de_Auto2709   "ok.gif"
#define nl_Auto2709   "ok.gif"
#define pt_Auto2709   "ok.gif"
#define xx_Auto2709   "ok.gif"
#define en_Auto2710   "cancel.gif"
#define fr_Auto2710   "cancel.gif"
#define it_Auto2710   "cancel.gif"
#define es_Auto2710   "cancel.gif"
#define de_Auto2710   "cancel.gif"
#define nl_Auto2710   "cancel.gif"
#define pt_Auto2710   "cancel.gif"
#define xx_Auto2710   "cancel.gif"
#define en_FrameInhibit   "&Inhibit this Frame"
#define fr_FrameInhibit   "&Inhiber cette boŒte"
#define it_FrameInhibit   "&Inhibit this Frame"
#define es_FrameInhibit   "&Inhibit this Frame"
#define de_FrameInhibit   "&Inhibit this Frame"
#define nl_FrameInhibit   "&Inhibit this Frame"
#define pt_FrameInhibit   "&Inhibit this Frame"
#define xx_FrameInhibit   "&Inhibit this Frame"
#define en__FrameInhibit   ""
#define fr__FrameInhibit   ""
#define it__FrameInhibit   ""
#define es__FrameInhibit   ""
#define de__FrameInhibit   ""
#define nl__FrameInhibit   ""
#define pt__FrameInhibit   ""
#define xx__FrameInhibit   ""

private struct accept_editor_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto2703[8];
	char * hint_Auto2703[8];
	int	x_Auto2703;
	int	y_Auto2703;
	int	w_Auto2703;
	int	h_Auto2703;
	char * msg_Auto2704[8];
	char * hint_Auto2704[8];
	char * msg_Auto2705[8];
	char * hint_Auto2705[8];
	char * msg_Auto2706[8];
	char * hint_Auto2706[8];
	char * msg_Auto2707[8];
	char * hint_Auto2707[8];
	char * msg_Auto2708[8];
	char * hint_Auto2708[8];
	char * msg_auto777[8];
	char * hint_auto777[8];
	char * hint_FileName[8];
	char	buffer_FileName[256];
	char * msg_auto599[8];
	char * hint_auto599[8];
	char * hint_EditorName[8];
	char	buffer_EditorName[256];
	char * msg_RazColour[8];
	char * hint_RazColour[8];
	int	value_RazColour;
	char * msg_QuoteColour[8];
	char * hint_QuoteColour[8];
	int	value_QuoteColour;
	char * msg_KeyWordColour[8];
	char * hint_KeyWordColour[8];
	int	value_KeyWordColour;
	char * msg_CommentColour[8];
	char * hint_CommentColour[8];
	int	value_CommentColour;
	char * msg_Auto2709[8];
	int	trigger_Auto2709;
	char * hint_Auto2709[8];
	char * msg_Auto2710[8];
	int	trigger_Auto2710;
	char * hint_Auto2710[8];
	char * msg_FrameInhibit[8];
	int	trigger_FrameInhibit;
	char * hint_FrameInhibit[8];
	int	value_FrameInhibit;
	char * msg_TextFont[8];
	char * hint_TextFont[8];
	int	value_TextFont;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[9];
	};
static int	vfh[16];

public	int	accept_editor_create(
	struct accept_editor_context ** cptr,
	char * pFileName,
	char * pEditorName,
	char * pRazColour,
	char * pQuoteColour,
	char * pKeyWordColour,
	char * pCommentColour,
	char * pFrameInhibit,
	char * pTextFont)
{

	int i;
	struct accept_editor_context * _Context=(struct accept_editor_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_editor_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=10;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"KSWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 255, pFileName);
		visual_transferin(_Context->buffer_EditorName, 255, pEditorName);
		visual_transferin((void *) 0, 0, pRazColour);
		if (!( pRazColour )) _Context->value_RazColour=0;
		else	_Context->value_RazColour = *((int *)pRazColour);
		visual_transferin((void *) 0, 0, pQuoteColour);
		if (!( pQuoteColour )) _Context->value_QuoteColour=0;
		else	_Context->value_QuoteColour = *((int *)pQuoteColour);
		visual_transferin((void *) 0, 0, pKeyWordColour);
		if (!( pKeyWordColour )) _Context->value_KeyWordColour=0;
		else	_Context->value_KeyWordColour = *((int *)pKeyWordColour);
		visual_transferin((void *) 0, 0, pCommentColour);
		if (!( pCommentColour )) _Context->value_CommentColour=0;
		else	_Context->value_CommentColour = *((int *)pCommentColour);
		visual_transferin((void *) 0, 0, pFrameInhibit);
		if (!( pFrameInhibit )) _Context->value_FrameInhibit=0;
		else	_Context->value_FrameInhibit = *((int *)pFrameInhibit);
		visual_transferin((void *) 0, 0, pTextFont);
		if (!( pTextFont )) _Context->value_TextFont=0;
		else	_Context->value_TextFont = *((int *)pTextFont);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto2703[i]=" ";
	_Context->hint_Auto2703[0]=en__Auto2703;
	_Context->hint_Auto2703[1]=fr__Auto2703;
	_Context->hint_Auto2703[2]=it__Auto2703;
	_Context->hint_Auto2703[3]=es__Auto2703;
	_Context->hint_Auto2703[4]=de__Auto2703;
	_Context->hint_Auto2703[5]=nl__Auto2703;
	_Context->hint_Auto2703[6]=pt__Auto2703;
	_Context->hint_Auto2703[7]=xx__Auto2703;
	_Context->x_Auto2703=145;
	_Context->y_Auto2703=140;
	_Context->w_Auto2703=510;
	_Context->h_Auto2703=320;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2704[i]=" ";
	_Context->msg_Auto2704[0]=en_Auto2704;
	_Context->msg_Auto2704[1]=fr_Auto2704;
	_Context->msg_Auto2704[2]=it_Auto2704;
	_Context->msg_Auto2704[3]=es_Auto2704;
	_Context->msg_Auto2704[4]=de_Auto2704;
	_Context->msg_Auto2704[5]=nl_Auto2704;
	_Context->msg_Auto2704[6]=pt_Auto2704;
	_Context->msg_Auto2704[7]=xx_Auto2704;
	for (i=0; i < 8; i++)_Context->msg_Auto2705[i]=" ";
	_Context->msg_Auto2705[0]=en_Auto2705;
	_Context->msg_Auto2705[1]=fr_Auto2705;
	_Context->msg_Auto2705[2]=it_Auto2705;
	_Context->msg_Auto2705[3]=es_Auto2705;
	_Context->msg_Auto2705[4]=de_Auto2705;
	_Context->msg_Auto2705[5]=nl_Auto2705;
	_Context->msg_Auto2705[6]=pt_Auto2705;
	_Context->msg_Auto2705[7]=xx_Auto2705;
	for (i=0; i < 8; i++)_Context->msg_Auto2706[i]=" ";
	_Context->msg_Auto2706[0]=en_Auto2706;
	_Context->msg_Auto2706[1]=fr_Auto2706;
	_Context->msg_Auto2706[2]=it_Auto2706;
	_Context->msg_Auto2706[3]=es_Auto2706;
	_Context->msg_Auto2706[4]=de_Auto2706;
	_Context->msg_Auto2706[5]=nl_Auto2706;
	_Context->msg_Auto2706[6]=pt_Auto2706;
	_Context->msg_Auto2706[7]=xx_Auto2706;
	for (i=0; i < 8; i++)_Context->msg_Auto2707[i]=" ";
	_Context->msg_Auto2707[0]=en_Auto2707;
	_Context->msg_Auto2707[1]=fr_Auto2707;
	_Context->msg_Auto2707[2]=it_Auto2707;
	_Context->msg_Auto2707[3]=es_Auto2707;
	_Context->msg_Auto2707[4]=de_Auto2707;
	_Context->msg_Auto2707[5]=nl_Auto2707;
	_Context->msg_Auto2707[6]=pt_Auto2707;
	_Context->msg_Auto2707[7]=xx_Auto2707;
	for (i=0; i < 8; i++)_Context->msg_Auto2708[i]=" ";
	_Context->msg_Auto2708[0]=en_Auto2708;
	_Context->msg_Auto2708[1]=fr_Auto2708;
	_Context->msg_Auto2708[2]=it_Auto2708;
	_Context->msg_Auto2708[3]=es_Auto2708;
	_Context->msg_Auto2708[4]=de_Auto2708;
	_Context->msg_Auto2708[5]=nl_Auto2708;
	_Context->msg_Auto2708[6]=pt_Auto2708;
	_Context->msg_Auto2708[7]=xx_Auto2708;
	for (i=0; i < 8; i++)_Context->msg_auto777[i]=" ";
	_Context->msg_auto777[0]=en_auto777;
	_Context->msg_auto777[1]=fr_auto777;
	_Context->msg_auto777[2]=it_auto777;
	_Context->msg_auto777[3]=es_auto777;
	_Context->msg_auto777[4]=de_auto777;
	_Context->msg_auto777[5]=nl_auto777;
	_Context->msg_auto777[6]=pt_auto777;
	_Context->msg_auto777[7]=xx_auto777;
	_Context->hint_auto777[0]=en__auto777;
	_Context->hint_auto777[1]=fr__auto777;
	_Context->hint_auto777[2]=it__auto777;
	_Context->hint_auto777[3]=es__auto777;
	_Context->hint_auto777[4]=de__auto777;
	_Context->hint_auto777[5]=nl__auto777;
	_Context->hint_auto777[6]=pt__auto777;
	_Context->hint_auto777[7]=xx__auto777;
	for (i=0; i < 8; i++)_Context->msg_auto599[i]=" ";
	_Context->msg_auto599[0]=en_auto599;
	_Context->msg_auto599[1]=fr_auto599;
	_Context->msg_auto599[2]=it_auto599;
	_Context->msg_auto599[3]=es_auto599;
	_Context->msg_auto599[4]=de_auto599;
	_Context->msg_auto599[5]=nl_auto599;
	_Context->msg_auto599[6]=pt_auto599;
	_Context->msg_auto599[7]=xx_auto599;
	_Context->hint_auto599[0]=en__auto599;
	_Context->hint_auto599[1]=fr__auto599;
	_Context->hint_auto599[2]=it__auto599;
	_Context->hint_auto599[3]=es__auto599;
	_Context->hint_auto599[4]=de__auto599;
	_Context->hint_auto599[5]=nl__auto599;
	_Context->hint_auto599[6]=pt__auto599;
	_Context->hint_auto599[7]=xx__auto599;
	for (i=0; i < 8; i++)_Context->msg_RazColour[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_QuoteColour[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_KeyWordColour[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_CommentColour[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_Auto2709[i]=" ";
	_Context->msg_Auto2709[0]=en_Auto2709;
	_Context->msg_Auto2709[1]=fr_Auto2709;
	_Context->msg_Auto2709[2]=it_Auto2709;
	_Context->msg_Auto2709[3]=es_Auto2709;
	_Context->msg_Auto2709[4]=de_Auto2709;
	_Context->msg_Auto2709[5]=nl_Auto2709;
	_Context->msg_Auto2709[6]=pt_Auto2709;
	_Context->msg_Auto2709[7]=xx_Auto2709;
	for (i=0; i < 8; i++)_Context->msg_Auto2710[i]=" ";
	_Context->msg_Auto2710[0]=en_Auto2710;
	_Context->msg_Auto2710[1]=fr_Auto2710;
	_Context->msg_Auto2710[2]=it_Auto2710;
	_Context->msg_Auto2710[3]=es_Auto2710;
	_Context->msg_Auto2710[4]=de_Auto2710;
	_Context->msg_Auto2710[5]=nl_Auto2710;
	_Context->msg_Auto2710[6]=pt_Auto2710;
	_Context->msg_Auto2710[7]=xx_Auto2710;
	for (i=0; i < 8; i++)_Context->msg_FrameInhibit[i]=" ";
	_Context->msg_FrameInhibit[0]=en_FrameInhibit;
	_Context->msg_FrameInhibit[1]=fr_FrameInhibit;
	_Context->msg_FrameInhibit[2]=it_FrameInhibit;
	_Context->msg_FrameInhibit[3]=es_FrameInhibit;
	_Context->msg_FrameInhibit[4]=de_FrameInhibit;
	_Context->msg_FrameInhibit[5]=nl_FrameInhibit;
	_Context->msg_FrameInhibit[6]=pt_FrameInhibit;
	_Context->msg_FrameInhibit[7]=xx_FrameInhibit;
	_Context->hint_FrameInhibit[0]=en__FrameInhibit;
	_Context->hint_FrameInhibit[1]=fr__FrameInhibit;
	_Context->hint_FrameInhibit[2]=it__FrameInhibit;
	_Context->hint_FrameInhibit[3]=es__FrameInhibit;
	_Context->hint_FrameInhibit[4]=de__FrameInhibit;
	_Context->hint_FrameInhibit[5]=nl__FrameInhibit;
	_Context->hint_FrameInhibit[6]=pt__FrameInhibit;
	_Context->hint_FrameInhibit[7]=xx__FrameInhibit;
	for (i=0; i < 8; i++)_Context->msg_TextFont[i]=" ";
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto2703,_Context->y_Auto2703,510+10,320+10);
	return(0);
}

public 	int	accept_editor_hide(struct accept_editor_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto2703,_Context->y_Auto2703);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_editor_remove(
	struct accept_editor_context * _Context,
	char * pFileName,
	char * pEditorName,
	char * pRazColour,
	char * pQuoteColour,
	char * pKeyWordColour,
	char * pCommentColour,
	char * pFrameInhibit,
	char * pTextFont)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"KSWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 255, pFileName);
		visual_transferout(_Context->buffer_EditorName, 255, pEditorName);
		visual_transferout((void *) 0, 0, pRazColour);
		if ( pRazColour != (char *) 0)
			*((int*)pRazColour) = _Context->value_RazColour;
		visual_transferout((void *) 0, 0, pQuoteColour);
		if ( pQuoteColour != (char *) 0)
			*((int*)pQuoteColour) = _Context->value_QuoteColour;
		visual_transferout((void *) 0, 0, pKeyWordColour);
		if ( pKeyWordColour != (char *) 0)
			*((int*)pKeyWordColour) = _Context->value_KeyWordColour;
		visual_transferout((void *) 0, 0, pCommentColour);
		if ( pCommentColour != (char *) 0)
			*((int*)pCommentColour) = _Context->value_CommentColour;
		visual_transferout((void *) 0, 0, pFrameInhibit);
		if ( pFrameInhibit != (char *) 0)
			*((int*)pFrameInhibit) = _Context->value_FrameInhibit;
		visual_transferout((void *) 0, 0, pTextFont);
		if ( pTextFont != (char *) 0)
			*((int*)pTextFont) = _Context->value_TextFont;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_editor_show(struct accept_editor_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto2703,_Context->y_Auto2703);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto2703,_Context->y_Auto2703,510,320,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto2703,_Context->y_Auto2703,510,320,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto2703+20,_Context->y_Auto2703+170,110,20,vfh[2],27,0,_Context->msg_Auto2704[_Context->language],strlen(_Context->msg_Auto2704[_Context->language]),3);
	visual_text(_Context->x_Auto2703+140,_Context->y_Auto2703+170,110,20,vfh[2],27,0,_Context->msg_Auto2705[_Context->language],strlen(_Context->msg_Auto2705[_Context->language]),3);
	visual_text(_Context->x_Auto2703+260,_Context->y_Auto2703+170,110,20,vfh[2],27,0,_Context->msg_Auto2706[_Context->language],strlen(_Context->msg_Auto2706[_Context->language]),3);
	visual_text(_Context->x_Auto2703+380,_Context->y_Auto2703+170,110,20,vfh[2],27,0,_Context->msg_Auto2707[_Context->language],strlen(_Context->msg_Auto2707[_Context->language]),3);
	visual_text(_Context->x_Auto2703+20,_Context->y_Auto2703+30,460,20,vfh[3],27,0,_Context->msg_Auto2708[_Context->language],strlen(_Context->msg_Auto2708[_Context->language]),1282);
	visual_text(_Context->x_Auto2703+20,_Context->y_Auto2703+60,470,20,vfh[2],27,0,_Context->msg_auto777[_Context->language],strlen(_Context->msg_auto777[_Context->language]),0);
	visual_frame(_Context->x_Auto2703+20,_Context->y_Auto2703+80,470+2,20+2,5);
	visual_text(_Context->x_Auto2703+20+1,_Context->y_Auto2703+80+1,470,20,vfh[1],26,0,_Context->buffer_FileName,255,0);
	visual_text(_Context->x_Auto2703+20,_Context->y_Auto2703+120,470,20,vfh[2],27,0,_Context->msg_auto599[_Context->language],strlen(_Context->msg_auto599[_Context->language]),0);
	visual_frame(_Context->x_Auto2703+20,_Context->y_Auto2703+140,470+2,20+2,5);
	visual_text(_Context->x_Auto2703+20+1,_Context->y_Auto2703+140+1,470,20,vfh[1],26,0,_Context->buffer_EditorName,255,0);
	visual_select(_Context->x_Auto2703+20,_Context->y_Auto2703+190,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_RazColour),768);
	visual_select(_Context->x_Auto2703+140,_Context->y_Auto2703+190,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_QuoteColour),768);
	visual_select(_Context->x_Auto2703+260,_Context->y_Auto2703+190,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_KeyWordColour),768);
	visual_select(_Context->x_Auto2703+380,_Context->y_Auto2703+190,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_CommentColour),768);
	_Context->trigger_Auto2709=visual_trigger_code(_Context->msg_Auto2709[_Context->language],strlen(_Context->msg_Auto2709[_Context->language]));
	visual_button(_Context->x_Auto2703+20,_Context->y_Auto2703+250,56,48,vfh[2],34,0,_Context->msg_Auto2709[_Context->language],strlen(_Context->msg_Auto2709[_Context->language]),1040);
	_Context->trigger_Auto2710=visual_trigger_code(_Context->msg_Auto2710[_Context->language],strlen(_Context->msg_Auto2710[_Context->language]));
	visual_button(_Context->x_Auto2703+430,_Context->y_Auto2703+250,56,48,vfh[2],34,0,_Context->msg_Auto2710[_Context->language],strlen(_Context->msg_Auto2710[_Context->language]),1040);
	_Context->trigger_FrameInhibit=visual_trigger_code(_Context->msg_FrameInhibit[_Context->language],strlen(_Context->msg_FrameInhibit[_Context->language]));
	visual_check(_Context->x_Auto2703+190,_Context->y_Auto2703+280,168,16,vfh[2],26,0,_Context->msg_FrameInhibit[_Context->language],strlen(_Context->msg_FrameInhibit[_Context->language]),_Context->value_FrameInhibit|0);
	visual_select(_Context->x_Auto2703+190,_Context->y_Auto2703+240,150,70,vfh[1],0,0,parse_selection(TextFontList,&_Context->value_TextFont),0);
	visual_thaw(_Context->x_Auto2703,_Context->y_Auto2703,510,320);

	return(0);
}

private int FileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The FILENAME edit field presents the name of the file to be edited. ";
			mptr[1]=" ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Le champ NOM DE FICHIER  fournit le nom du fichier devant ˆtre ‚dit‚. ";
			mptr[1]=" ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int EditorName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "The EDITOR NAME edit field presents the full path and filename of ";
			mptr[1]="the program to be  used for the editing of all source and text files. ";
			mptr[2]="If this string is prefixed by the !  character then the internal standard text editor will be used. ";
			mptr[3]=" ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Le champ NOM DE L'EDITEUR fournit le chemin complet et le nom du programme ";
			mptr[1]="… utiliser  pour l'‚dition de tous les fichiers  source ou texte. ";
			mptr[2]="Si la chaŒne est  pr‚fix‚e par le caractŠre !, alors l'‚diteur standard interne sera utilis‚.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int RazColour_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This colour selection control allows the standard text colour to be ";
			mptr[1]="selected for the new  syntaxical colouration mechansims for ABAL, ";
			mptr[2]="C and HTML source files.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Ce contr“le de s‚lection de couleur permet de s‚lectionner la couleur ";
			mptr[1]="des textes standard dans les nouveaux m‚canismes de coloration syntaxique ";
			mptr[2]="pour les fichiers sources ABAL, C et HTML.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int QuoteColour_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This colour selection control allows the colour to be used to display ";
			mptr[1]="string litteral values to be selected for use by the new syntaxical ";
			mptr[2]="colouration mechansims.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Ce contr“le de s‚lection de couleur permet de s‚lectionner la couleur ";
			mptr[1]="qui sera utilis‚e  pour afficher les valeurs de chaŒnes litt‚rales, ";
			mptr[2]="dans les nouveaux m‚canismes de  coloration syntaxique.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int KeyWordColour_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This colour selection control allows the colour to be used for the ";
			mptr[1]="display of language keywords  to be chosen for the syntaxical colouration ";
			mptr[2]="mechansims of the standard text editor..   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[4];
			mptr[0] = "Ce contr“le de s‚lection de couleur permet de s‚lectionner la couleur ";
			mptr[1]="qui sera utilis‚e  pour afficher les mots-cl‚s du langage  dans les ";
			mptr[2]="m‚canismes de coloration syntaxique de l'‚diteur de texte standard. ";
			mptr[3]=" ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CommentColour_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This colour selection control allows selection of the colour to be ";
			mptr[1]="used for the display of comments.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Ce contr“le de s‚lection de couleur permet de s‚lectionner la couleur ";
			mptr[1]="qui sera utilis‚e  pour afficher les commentaires.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2709_help()
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

private int Auto2710_help()
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

private int FrameInhibit_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "If this checkbox is checked then this dialog box will no longer be ";
			mptr[1]="presented for validation  prior to editing text or source files.  ";
			mptr[2]="The Editor will be simply activated without confirmation.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = " Si cette case est coch‚e, la boŒte de dialogue ne sera plus pr‚sent‚e ";
			mptr[1]="pour validation  avant l'‚dition des fichiers source ou texte. L'Editeur ";
			mptr[2]="sera simplement activ‚ sans confirmation.   ";
			return(visual_online_help(mptr,3));
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
			mptr[0] = "This select control allows the editor text font to be chosen. Proportional ";
			mptr[1]="spacing fonts are not recommended as the internal editor is built ";
			mptr[2]="around aed which has a strong character orientation.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[4];
			mptr[0] = "Ce contr“le de s‚lection permet de choisir la fonte de l'‚diteur de ";
			mptr[1]="texte. Les polices proportionnelles ne sont pas recommand‚es, l'‚diteur ";
			mptr[2]="interne ‚tant construit autour d'aed qui a une forte orientation caractŠres. ";
			mptr[3]=" ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2703action(struct accept_editor_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_editor_hide(_Context);

		_Context->x_Auto2703 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto2703 < 0) { _Context->x_Auto2703=0; }
		_Context->y_Auto2703 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto2703 < 0) { _Context->y_Auto2703=0; }
			accept_editor_show(_Context);

		visual_thaw(_Context->x_Auto2703,_Context->y_Auto2703,510,320);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto2709_event(struct accept_editor_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto2710_event(struct accept_editor_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_editor_event(
struct accept_editor_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto2709 == mb ) return(7);
		if (_Context->trigger_Auto2710 == mb ) return(8);
		if (_Context->trigger_FrameInhibit == mb ) return(9);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto2703+489) )  
	&&  (my >= (_Context->y_Auto2703+4) )  
	&&  (mx <= (_Context->x_Auto2703+506) )  
	&&  (my <= (_Context->y_Auto2703+20) )) {
		return(1);	/* Auto2703 */

		}
	if ((mx >= (_Context->x_Auto2703+473) )  
	&&  (my >= (_Context->y_Auto2703+4) )  
	&&  (mx <= (_Context->x_Auto2703+490) )  
	&&  (my <= (_Context->y_Auto2703+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vaed.htm");
			};
		return(-1);	/* Auto2703 */

		}
	if ((mx >= (_Context->x_Auto2703+457) )  
	&&  (my >= (_Context->y_Auto2703+4) )  
	&&  (mx <= (_Context->x_Auto2703+474) )  
	&&  (my <= (_Context->y_Auto2703+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_editor_show(_Context);
		return(-1);	/* Auto2703 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto2703+4) )  
		&&  (my >= (_Context->y_Auto2703+4) )  
		&&  (mx <= (_Context->x_Auto2703+442) )  
		&&  (my <= (_Context->y_Auto2703+20) )) {
			return( Auto2703action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto2703+20) ) 
	&&  ( my >= (_Context->y_Auto2703+140) ) 
	&&  ( mx <= (_Context->x_Auto2703+20+470) ) 
	&&  ( my <= (_Context->y_Auto2703+140+20))) {
		return(2); /* EditorName */
		}
	if (( mx >= (_Context->x_Auto2703+20+0) ) 
	&&  ( my >= (_Context->y_Auto2703+190) ) 
	&&  ( mx <= (_Context->x_Auto2703+20+112) ) 
	&&  ( my <= (_Context->y_Auto2703+190+16))) {
		return(3); /* RazColour */
		}
	if (( mx >= (_Context->x_Auto2703+140+0) ) 
	&&  ( my >= (_Context->y_Auto2703+190) ) 
	&&  ( mx <= (_Context->x_Auto2703+140+112) ) 
	&&  ( my <= (_Context->y_Auto2703+190+16))) {
		return(4); /* QuoteColour */
		}
	if (( mx >= (_Context->x_Auto2703+260+0) ) 
	&&  ( my >= (_Context->y_Auto2703+190) ) 
	&&  ( mx <= (_Context->x_Auto2703+260+112) ) 
	&&  ( my <= (_Context->y_Auto2703+190+16))) {
		return(5); /* KeyWordColour */
		}
	if (( mx >= (_Context->x_Auto2703+380+0) ) 
	&&  ( my >= (_Context->y_Auto2703+190) ) 
	&&  ( mx <= (_Context->x_Auto2703+380+112) ) 
	&&  ( my <= (_Context->y_Auto2703+190+16))) {
		return(6); /* CommentColour */
		}
	if (( mx >= (_Context->x_Auto2703+20) ) 
	&&  ( my >= (_Context->y_Auto2703+250) ) 
	&&  ( mx <= (_Context->x_Auto2703+20+56) ) 
	&&  ( my <= (_Context->y_Auto2703+250+48))) {
		return(7); /* Auto2709 */
		}
	if (( mx >= (_Context->x_Auto2703+430) ) 
	&&  ( my >= (_Context->y_Auto2703+250) ) 
	&&  ( mx <= (_Context->x_Auto2703+430+56) ) 
	&&  ( my <= (_Context->y_Auto2703+250+48))) {
		return(8); /* Auto2710 */
		}
	if (( mx >= (_Context->x_Auto2703+190) ) 
	&&  ( my >= (_Context->y_Auto2703+280) ) 
	&&  ( mx <= (_Context->x_Auto2703+190+168) ) 
	&&  ( my <= (_Context->y_Auto2703+280+16))) {
		return(9); /* FrameInhibit */
		}
	if (( mx >= (_Context->x_Auto2703+190+0) ) 
	&&  ( my >= (_Context->y_Auto2703+240) ) 
	&&  ( mx <= (_Context->x_Auto2703+190+150) ) 
	&&  ( my <= (_Context->y_Auto2703+240+16))) {
		return(10); /* TextFont */
		}

	return(-1);
}


public	int	accept_editor_focus(struct accept_editor_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* EditorName */
				_Context->keycode = visual_edit(_Context->x_Auto2703+20+1,_Context->y_Auto2703+140+1,470,20,vfh[1],_Context->buffer_EditorName,255);
			break;
			case	0x3 :
				/* RazColour */
				_Context->keycode = visual_select(_Context->x_Auto2703+20,_Context->y_Auto2703+190,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_RazColour),770);
				break;
			case	0x4 :
				/* QuoteColour */
				_Context->keycode = visual_select(_Context->x_Auto2703+140,_Context->y_Auto2703+190,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_QuoteColour),770);
				break;
			case	0x5 :
				/* KeyWordColour */
				_Context->keycode = visual_select(_Context->x_Auto2703+260,_Context->y_Auto2703+190,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_KeyWordColour),770);
				break;
			case	0x6 :
				/* CommentColour */
				_Context->keycode = visual_select(_Context->x_Auto2703+380,_Context->y_Auto2703+190,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_CommentColour),770);
				break;
			case	0x7 :
				/* Auto2709 */
				_Context->trigger_Auto2709=visual_trigger_code(_Context->msg_Auto2709[_Context->language],strlen(_Context->msg_Auto2709[_Context->language]));
				visual_button(_Context->x_Auto2703+20,_Context->y_Auto2703+250,56,48,vfh[2],34,0,_Context->msg_Auto2709[_Context->language],strlen(_Context->msg_Auto2709[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2709=visual_trigger_code(_Context->msg_Auto2709[_Context->language],strlen(_Context->msg_Auto2709[_Context->language]));
	visual_button(_Context->x_Auto2703+20,_Context->y_Auto2703+250,56,48,vfh[2],34,0,_Context->msg_Auto2709[_Context->language],strlen(_Context->msg_Auto2709[_Context->language]),1040);
				break;
			case	0x8 :
				/* Auto2710 */
				_Context->trigger_Auto2710=visual_trigger_code(_Context->msg_Auto2710[_Context->language],strlen(_Context->msg_Auto2710[_Context->language]));
				visual_button(_Context->x_Auto2703+430,_Context->y_Auto2703+250,56,48,vfh[2],34,0,_Context->msg_Auto2710[_Context->language],strlen(_Context->msg_Auto2710[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2710=visual_trigger_code(_Context->msg_Auto2710[_Context->language],strlen(_Context->msg_Auto2710[_Context->language]));
	visual_button(_Context->x_Auto2703+430,_Context->y_Auto2703+250,56,48,vfh[2],34,0,_Context->msg_Auto2710[_Context->language],strlen(_Context->msg_Auto2710[_Context->language]),1040);
				break;
			case	0x9 :
				/* FrameInhibit */
				visual_check(_Context->x_Auto2703+190,_Context->y_Auto2703+280,168,16,vfh[2],26,0,_Context->msg_FrameInhibit[_Context->language],strlen(_Context->msg_FrameInhibit[_Context->language]),(_Context->value_FrameInhibit |2));
				_Context->keycode = visual_getch();
				_Context->trigger_FrameInhibit=visual_trigger_code(_Context->msg_FrameInhibit[_Context->language],strlen(_Context->msg_FrameInhibit[_Context->language]));
	visual_check(_Context->x_Auto2703+190,_Context->y_Auto2703+280,168,16,vfh[2],26,0,_Context->msg_FrameInhibit[_Context->language],strlen(_Context->msg_FrameInhibit[_Context->language]),_Context->value_FrameInhibit|0);
				break;
			case	0xa :
				/* TextFont */
				_Context->keycode = visual_select(_Context->x_Auto2703+190,_Context->y_Auto2703+240,150,70,vfh[1],0,0,parse_selection(TextFontList,&_Context->value_TextFont),2);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_editor_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=10;
			accept_editor_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_editor_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (EditorName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (RazColour_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (QuoteColour_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (KeyWordColour_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (CommentColour_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (Auto2709_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (Auto2710_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (FrameInhibit_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (TextFont_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto2703 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* EditorName */
					continue;
				case	0x3 :
					/* RazColour */
					continue;
				case	0x4 :
					/* QuoteColour */
					continue;
				case	0x5 :
					/* KeyWordColour */
					continue;
				case	0x6 :
					/* CommentColour */
					continue;
				case	0x7 :
					/* Auto2709 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2709=visual_trigger_code(_Context->msg_Auto2709[_Context->language],strlen(_Context->msg_Auto2709[_Context->language]));
						visual_button(_Context->x_Auto2703+20,_Context->y_Auto2703+250,56,48,vfh[2],34,0,_Context->msg_Auto2709[_Context->language],strlen(_Context->msg_Auto2709[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2709=visual_trigger_code(_Context->msg_Auto2709[_Context->language],strlen(_Context->msg_Auto2709[_Context->language]));
	visual_button(_Context->x_Auto2703+20,_Context->y_Auto2703+250,56,48,vfh[2],34,0,_Context->msg_Auto2709[_Context->language],strlen(_Context->msg_Auto2709[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2709_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Auto2710 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2710=visual_trigger_code(_Context->msg_Auto2710[_Context->language],strlen(_Context->msg_Auto2710[_Context->language]));
						visual_button(_Context->x_Auto2703+430,_Context->y_Auto2703+250,56,48,vfh[2],34,0,_Context->msg_Auto2710[_Context->language],strlen(_Context->msg_Auto2710[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2710=visual_trigger_code(_Context->msg_Auto2710[_Context->language],strlen(_Context->msg_Auto2710[_Context->language]));
	visual_button(_Context->x_Auto2703+430,_Context->y_Auto2703+250,56,48,vfh[2],34,0,_Context->msg_Auto2710[_Context->language],strlen(_Context->msg_Auto2710[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2710_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* FrameInhibit */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_FrameInhibit += 1;
						_Context->value_FrameInhibit &= 1;
						}
					continue;
				case	0xa :
					/* TextFont */
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
				_Context->focus_item=10;
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

public	int	accept_editor(
	char * pFileName,
	char * pEditorName,
	char * pRazColour,
	char * pQuoteColour,
	char * pKeyWordColour,
	char * pCommentColour,
	char * pFrameInhibit,
	char * pTextFont)
{
	int	status=0;
	struct accept_editor_context * _Context=(struct accept_editor_context*) 0;
	status = accept_editor_create(
	&_Context,
	 pFileName,
	 pEditorName,
	 pRazColour,
	 pQuoteColour,
	 pKeyWordColour,
	 pCommentColour,
	 pFrameInhibit,
	 pTextFont);
	if ( status != 0) return(status);
	status = accept_editor_show(_Context);
		enter_modal();
	status = accept_editor_focus(_Context);
		leave_modal();
	status = accept_editor_hide(_Context);
	status = accept_editor_remove(
	_Context,
	 pFileName,
	 pEditorName,
	 pRazColour,
	 pQuoteColour,
	 pKeyWordColour,
	 pCommentColour,
	 pFrameInhibit,
	 pTextFont);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vaed_c */
