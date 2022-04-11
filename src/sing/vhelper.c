
#ifndef _vhelper_c
#define _vhelper_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vhelper.xml                                              */
/* Target         : vhelper.c                                                */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#include "singlang.h"
#define en__Auto3563   ""
#define fr__Auto3563   ""
#define it__Auto3563   ""
#define es__Auto3563   ""
#define de__Auto3563   ""
#define nl__Auto3563   ""
#define pt__Auto3563   ""
#define xx__Auto3563   ""
#define en_Auto3564   "International Document Editor"
#define fr_Auto3564   "Editeur des Documents Multi-Nationales"
#define it_Auto3564   "International Document Editor"
#define es_Auto3564   "International Document Editor"
#define de_Auto3564   "International Document Editor"
#define nl_Auto3564   "International Document Editor"
#define pt_Auto3564   "International Document Editor"
#define xx_Auto3564   "International Document Editor"
#define en_TabEnglish   "&English"
#define fr_TabEnglish   "&English"
#define it_TabEnglish   "English"
#define es_TabEnglish   "English"
#define de_TabEnglish   "English"
#define nl_TabEnglish   "English"
#define pt_TabEnglish   "English"
#define xx_TabEnglish   "English"
#define en_English   ""
#define en__English   ""
#define en_TabFrancais   "F&rancais"
#define fr_TabFrancais   "F&rancais"
#define it_TabFrancais   "F&rancais"
#define es_TabFrancais   "F&rancais"
#define de_TabFrancais   "F&rancais"
#define nl_TabFrancais   "F&rancais"
#define pt_TabFrancais   "F&rancais"
#define xx_TabFrancais   "F&rancais"
#define en__TabFrancais   ""
#define fr__TabFrancais   ""
#define it__TabFrancais   ""
#define es__TabFrancais   ""
#define de__TabFrancais   ""
#define nl__TabFrancais   ""
#define pt__TabFrancais   ""
#define xx__TabFrancais   ""
#define en_Francais   ""
#define en__Francais   ""
#define en_TabItaliano   "&Italiano"
#define fr_TabItaliano   "&Italiano"
#define it_TabItaliano   "Italiano"
#define es_TabItaliano   "Italiano"
#define de_TabItaliano   "Italiano"
#define nl_TabItaliano   "Italiano"
#define pt_TabItaliano   "Italiano"
#define xx_TabItaliano   "Italiano"
#define en_Italiano   ""
#define en__Italiano   ""
#define en_TabEspagnol   "E&spagnol"
#define fr_TabEspagnol   "E&spagnol"
#define it_TabEspagnol   "Espagnol"
#define es_TabEspagnol   "Espagnol"
#define de_TabEspagnol   "Espagnol"
#define nl_TabEspagnol   "Espagnol"
#define pt_TabEspagnol   "Espagnol"
#define xx_TabEspagnol   "Espagnol"
#define en_Espagnol   ""
#define en__Espagnol   ""
#define en_TabDeutsch   "&Deutsch"
#define fr_TabDeutsch   "&Deutsch"
#define it_TabDeutsch   "Deutsch"
#define es_TabDeutsch   "Deutsch"
#define de_TabDeutsch   "Deutsch"
#define nl_TabDeutsch   "Deutsch"
#define pt_TabDeutsch   "Deutsch"
#define xx_TabDeutsch   "Deutsch"
#define en_Deutsch   ""
#define en__Deutsch   ""
#define en_TabNederlands   "&Nederlands"
#define fr_TabNederlands   "&Nederlands"
#define it_TabNederlands   "Nederlands"
#define es_TabNederlands   "Nederlands"
#define de_TabNederlands   "Nederlands"
#define nl_TabNederlands   "Nederlands"
#define pt_TabNederlands   "Nederlands"
#define xx_TabNederlands   "Nederlands"
#define en_Nederlands   ""
#define en__Nederlands   ""
#define en_TabPortugues   "&Portugues"
#define fr_TabPortugues   "P&ortugues"
#define it_TabPortugues   "Portugues"
#define es_TabPortugues   "Portugues"
#define de_TabPortugues   "Portugues"
#define nl_TabPortugues   "Portugues"
#define pt_TabPortugues   "Portugues"
#define xx_TabPortugues   "Portugues"
#define en_Portugues   ""
#define en__Portugues   ""
#define en_TabOther   "&Other"
#define fr_TabOther   "A&utre"
#define it_TabOther   "Other"
#define es_TabOther   "Other"
#define de_TabOther   "Andere"
#define nl_TabOther   "Other"
#define pt_TabOther   "Other"
#define xx_TabOther   "Eile"
#define en_Other   ""
#define en__Other   ""
#define en_Auto3565   "ok.gif"
#define fr_Auto3565   "ok.gif"
#define it_Auto3565   "ok.gif"
#define es_Auto3565   "ok.gif"
#define de_Auto3565   "ok.gif"
#define nl_Auto3565   "ok.gif"
#define pt_Auto3565   "ok.gif"
#define xx_Auto3565   "ok.gif"
#define en_FullScreen   "screen.gif"
#define fr_FullScreen   "screen.gif"
#define it_FullScreen   "screen.gif"
#define es_FullScreen   "screen.gif"
#define de_FullScreen   "screen.gif"
#define nl_FullScreen   "screen.gif"
#define pt_FullScreen   "screen.gif"
#define xx_FullScreen   "screen.gif"
#define en__FullScreen   ""
#define fr__FullScreen   ""
#define it__FullScreen   ""
#define es__FullScreen   ""
#define de__FullScreen   ""
#define nl__FullScreen   ""
#define pt__FullScreen   ""
#define xx__FullScreen   ""
#define en_Auto3566   "cancel.gif"
#define fr_Auto3566   "cancel.gif"
#define it_Auto3566   "cancel.gif"
#define es_Auto3566   "cancel.gif"
#define de_Auto3566   "cancel.gif"
#define nl_Auto3566   "cancel.gif"
#define pt_Auto3566   "cancel.gif"
#define xx_Auto3566   "cancel.gif"

private struct accept_help_messages_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[8+1];
	char * msg_Auto3563[8];
	char * hint_Auto3563[8];
	int	x_Auto3563;
	int	y_Auto3563;
	int	w_Auto3563;
	int	h_Auto3563;
	char * msg_Auto3564[8];
	char * hint_Auto3564[8];
	char * msg_TabEnglish[8];
	int	trigger_TabEnglish;
	char * hint_TabEnglish[8];
	int	page_number;
	char * hint_English[8];
	char * buffer_English;
	char * msg_TabFrancais[8];
	int	trigger_TabFrancais;
	char * hint_TabFrancais[8];
	char * hint_Francais[8];
	char * buffer_Francais;
	char * msg_TabItaliano[8];
	int	trigger_TabItaliano;
	char * hint_TabItaliano[8];
	char * hint_Italiano[8];
	char * buffer_Italiano;
	char * msg_TabEspagnol[8];
	int	trigger_TabEspagnol;
	char * hint_TabEspagnol[8];
	char * hint_Espagnol[8];
	char * buffer_Espagnol;
	char * msg_TabDeutsch[8];
	int	trigger_TabDeutsch;
	char * hint_TabDeutsch[8];
	char * hint_Deutsch[8];
	char * buffer_Deutsch;
	char * msg_TabNederlands[8];
	int	trigger_TabNederlands;
	char * hint_TabNederlands[8];
	char * hint_Nederlands[8];
	char * buffer_Nederlands;
	char * msg_TabPortugues[8];
	int	trigger_TabPortugues;
	char * hint_TabPortugues[8];
	char * hint_Portugues[8];
	char * buffer_Portugues;
	char * msg_TabOther[8];
	int	trigger_TabOther;
	char * hint_TabOther[8];
	char * hint_Other[8];
	char * buffer_Other;
	char * msg_Auto3565[8];
	int	trigger_Auto3565;
	char * hint_Auto3565[8];
	char * msg_FullScreen[8];
	int	trigger_FullScreen;
	char * hint_FullScreen[8];
	char * msg_Auto3566[8];
	int	trigger_Auto3566;
	char * hint_Auto3566[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[9];
	};
static int	vfh[16];
private int on_TabEnglish_show(struct accept_help_messages_context * _Context);
private int on_English_show(struct accept_help_messages_context * _Context);
private int on_TabFrancais_show(struct accept_help_messages_context * _Context);
private int on_Francais_show(struct accept_help_messages_context * _Context);
private int on_TabItaliano_show(struct accept_help_messages_context * _Context);
private int on_Italiano_show(struct accept_help_messages_context * _Context);
private int on_TabEspagnol_show(struct accept_help_messages_context * _Context);
private int on_Espagnol_show(struct accept_help_messages_context * _Context);
private int on_TabDeutsch_show(struct accept_help_messages_context * _Context);
private int on_Deutsch_show(struct accept_help_messages_context * _Context);
private int on_TabNederlands_show(struct accept_help_messages_context * _Context);
private int on_Nederlands_show(struct accept_help_messages_context * _Context);
private int on_TabPortugues_show(struct accept_help_messages_context * _Context);
private int on_Portugues_show(struct accept_help_messages_context * _Context);
private int on_TabOther_show(struct accept_help_messages_context * _Context);
private int on_Other_show(struct accept_help_messages_context * _Context);
private int on_English_getfocus(struct accept_help_messages_context * _Context);
private int on_Francais_getfocus(struct accept_help_messages_context * _Context);
private int on_Italiano_getfocus(struct accept_help_messages_context * _Context);
private int on_Espagnol_getfocus(struct accept_help_messages_context * _Context);
private int on_Deutsch_getfocus(struct accept_help_messages_context * _Context);
private int on_Nederlands_getfocus(struct accept_help_messages_context * _Context);
private int on_Portugues_getfocus(struct accept_help_messages_context * _Context);
private int on_Other_getfocus(struct accept_help_messages_context * _Context);
private int on_Auto3565_event(struct accept_help_messages_context * _Context);
private int on_FullScreen_event(struct accept_help_messages_context * _Context);
private int on_Auto3566_event(struct accept_help_messages_context * _Context);

public	int	accept_help_messages_create(
	struct accept_help_messages_context ** cptr,
	char * pEnglish,
	char * pFrancais,
	char * pItaliano,
	char * pEspagnol,
	char * pDeutsch,
	char * pNederlands,
	char * pPortugues,
	char * pOther)
{

	int i;
	struct accept_help_messages_context * _Context=(struct accept_help_messages_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_help_messages_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=20;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"TTTTTTTT");
		visual_signature(_Context->signature,_Context->signature);
				_Context->buffer_English=(char *) 0;
		visual_transferin(&_Context->buffer_English, 1978, pEnglish);
				_Context->buffer_Francais=(char *) 0;
		visual_transferin(&_Context->buffer_Francais, 1978, pFrancais);
				_Context->buffer_Italiano=(char *) 0;
		visual_transferin(&_Context->buffer_Italiano, 1978, pItaliano);
				_Context->buffer_Espagnol=(char *) 0;
		visual_transferin(&_Context->buffer_Espagnol, 1978, pEspagnol);
				_Context->buffer_Deutsch=(char *) 0;
		visual_transferin(&_Context->buffer_Deutsch, 1978, pDeutsch);
				_Context->buffer_Nederlands=(char *) 0;
		visual_transferin(&_Context->buffer_Nederlands, 1978, pNederlands);
				_Context->buffer_Portugues=(char *) 0;
		visual_transferin(&_Context->buffer_Portugues, 1978, pPortugues);
				_Context->buffer_Other=(char *) 0;
		visual_transferin(&_Context->buffer_Other, 1978, pOther);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3563[i]=" ";
	_Context->hint_Auto3563[0]=en__Auto3563;
	_Context->hint_Auto3563[1]=fr__Auto3563;
	_Context->hint_Auto3563[2]=it__Auto3563;
	_Context->hint_Auto3563[3]=es__Auto3563;
	_Context->hint_Auto3563[4]=de__Auto3563;
	_Context->hint_Auto3563[5]=nl__Auto3563;
	_Context->hint_Auto3563[6]=pt__Auto3563;
	_Context->hint_Auto3563[7]=xx__Auto3563;
	_Context->x_Auto3563=70;
	_Context->y_Auto3563=50;
	_Context->w_Auto3563=730;
	_Context->h_Auto3563=540;
	_Context->window_col=70;
	_Context->window_row=50;
	_Context->page_number+=visual_national_language(-1);
	editorConfiguration(_GENERATE_HTML);
	use_html_tools();
	for (i=0; i < 8; i++)_Context->msg_Auto3564[i]=" ";
	_Context->msg_Auto3564[0]=en_Auto3564;
	_Context->msg_Auto3564[1]=fr_Auto3564;
	_Context->msg_Auto3564[2]=it_Auto3564;
	_Context->msg_Auto3564[3]=es_Auto3564;
	_Context->msg_Auto3564[4]=de_Auto3564;
	_Context->msg_Auto3564[5]=nl_Auto3564;
	_Context->msg_Auto3564[6]=pt_Auto3564;
	_Context->msg_Auto3564[7]=xx_Auto3564;
	for (i=0; i < 8; i++)_Context->msg_TabEnglish[i]=" ";
	_Context->msg_TabEnglish[0]=en_TabEnglish;
	_Context->msg_TabEnglish[1]=fr_TabEnglish;
	_Context->msg_TabEnglish[2]=it_TabEnglish;
	_Context->msg_TabEnglish[3]=es_TabEnglish;
	_Context->msg_TabEnglish[4]=de_TabEnglish;
	_Context->msg_TabEnglish[5]=nl_TabEnglish;
	_Context->msg_TabEnglish[6]=pt_TabEnglish;
	_Context->msg_TabEnglish[7]=xx_TabEnglish;
	_Context->focus_pages[1]=2;
	_Context->hint_English[0]=en__English;
	for (i=0; i < 8; i++)_Context->msg_TabFrancais[i]=" ";
	_Context->msg_TabFrancais[0]=en_TabFrancais;
	_Context->msg_TabFrancais[1]=fr_TabFrancais;
	_Context->msg_TabFrancais[2]=it_TabFrancais;
	_Context->msg_TabFrancais[3]=es_TabFrancais;
	_Context->msg_TabFrancais[4]=de_TabFrancais;
	_Context->msg_TabFrancais[5]=nl_TabFrancais;
	_Context->msg_TabFrancais[6]=pt_TabFrancais;
	_Context->msg_TabFrancais[7]=xx_TabFrancais;
	_Context->hint_TabFrancais[0]=en__TabFrancais;
	_Context->hint_TabFrancais[1]=fr__TabFrancais;
	_Context->hint_TabFrancais[2]=it__TabFrancais;
	_Context->hint_TabFrancais[3]=es__TabFrancais;
	_Context->hint_TabFrancais[4]=de__TabFrancais;
	_Context->hint_TabFrancais[5]=nl__TabFrancais;
	_Context->hint_TabFrancais[6]=pt__TabFrancais;
	_Context->hint_TabFrancais[7]=xx__TabFrancais;
	_Context->focus_pages[2]=4;
	_Context->hint_Francais[0]=en__Francais;
	for (i=0; i < 8; i++)_Context->msg_TabItaliano[i]=" ";
	_Context->msg_TabItaliano[0]=en_TabItaliano;
	_Context->msg_TabItaliano[1]=fr_TabItaliano;
	_Context->msg_TabItaliano[2]=it_TabItaliano;
	_Context->msg_TabItaliano[3]=es_TabItaliano;
	_Context->msg_TabItaliano[4]=de_TabItaliano;
	_Context->msg_TabItaliano[5]=nl_TabItaliano;
	_Context->msg_TabItaliano[6]=pt_TabItaliano;
	_Context->msg_TabItaliano[7]=xx_TabItaliano;
	_Context->focus_pages[3]=6;
	_Context->hint_Italiano[0]=en__Italiano;
	show_window_editor();
	for (i=0; i < 8; i++)_Context->msg_TabEspagnol[i]=" ";
	_Context->msg_TabEspagnol[0]=en_TabEspagnol;
	_Context->msg_TabEspagnol[1]=fr_TabEspagnol;
	_Context->msg_TabEspagnol[2]=it_TabEspagnol;
	_Context->msg_TabEspagnol[3]=es_TabEspagnol;
	_Context->msg_TabEspagnol[4]=de_TabEspagnol;
	_Context->msg_TabEspagnol[5]=nl_TabEspagnol;
	_Context->msg_TabEspagnol[6]=pt_TabEspagnol;
	_Context->msg_TabEspagnol[7]=xx_TabEspagnol;
	_Context->focus_pages[4]=8;
	_Context->hint_Espagnol[0]=en__Espagnol;
	for (i=0; i < 8; i++)_Context->msg_TabDeutsch[i]=" ";
	_Context->msg_TabDeutsch[0]=en_TabDeutsch;
	_Context->msg_TabDeutsch[1]=fr_TabDeutsch;
	_Context->msg_TabDeutsch[2]=it_TabDeutsch;
	_Context->msg_TabDeutsch[3]=es_TabDeutsch;
	_Context->msg_TabDeutsch[4]=de_TabDeutsch;
	_Context->msg_TabDeutsch[5]=nl_TabDeutsch;
	_Context->msg_TabDeutsch[6]=pt_TabDeutsch;
	_Context->msg_TabDeutsch[7]=xx_TabDeutsch;
	_Context->focus_pages[5]=10;
	_Context->hint_Deutsch[0]=en__Deutsch;
	for (i=0; i < 8; i++)_Context->msg_TabNederlands[i]=" ";
	_Context->msg_TabNederlands[0]=en_TabNederlands;
	_Context->msg_TabNederlands[1]=fr_TabNederlands;
	_Context->msg_TabNederlands[2]=it_TabNederlands;
	_Context->msg_TabNederlands[3]=es_TabNederlands;
	_Context->msg_TabNederlands[4]=de_TabNederlands;
	_Context->msg_TabNederlands[5]=nl_TabNederlands;
	_Context->msg_TabNederlands[6]=pt_TabNederlands;
	_Context->msg_TabNederlands[7]=xx_TabNederlands;
	_Context->focus_pages[6]=12;
	_Context->hint_Nederlands[0]=en__Nederlands;
	for (i=0; i < 8; i++)_Context->msg_TabPortugues[i]=" ";
	_Context->msg_TabPortugues[0]=en_TabPortugues;
	_Context->msg_TabPortugues[1]=fr_TabPortugues;
	_Context->msg_TabPortugues[2]=it_TabPortugues;
	_Context->msg_TabPortugues[3]=es_TabPortugues;
	_Context->msg_TabPortugues[4]=de_TabPortugues;
	_Context->msg_TabPortugues[5]=nl_TabPortugues;
	_Context->msg_TabPortugues[6]=pt_TabPortugues;
	_Context->msg_TabPortugues[7]=xx_TabPortugues;
	_Context->focus_pages[7]=14;
	_Context->hint_Portugues[0]=en__Portugues;
	for (i=0; i < 8; i++)_Context->msg_TabOther[i]=" ";
	_Context->msg_TabOther[0]=en_TabOther;
	_Context->msg_TabOther[1]=fr_TabOther;
	_Context->msg_TabOther[2]=it_TabOther;
	_Context->msg_TabOther[3]=es_TabOther;
	_Context->msg_TabOther[4]=de_TabOther;
	_Context->msg_TabOther[5]=nl_TabOther;
	_Context->msg_TabOther[6]=pt_TabOther;
	_Context->msg_TabOther[7]=xx_TabOther;
	_Context->focus_pages[8]=16;
	_Context->hint_Other[0]=en__Other;
	for (i=0; i < 8; i++)_Context->msg_Auto3565[i]=" ";
	_Context->msg_Auto3565[0]=en_Auto3565;
	_Context->msg_Auto3565[1]=fr_Auto3565;
	_Context->msg_Auto3565[2]=it_Auto3565;
	_Context->msg_Auto3565[3]=es_Auto3565;
	_Context->msg_Auto3565[4]=de_Auto3565;
	_Context->msg_Auto3565[5]=nl_Auto3565;
	_Context->msg_Auto3565[6]=pt_Auto3565;
	_Context->msg_Auto3565[7]=xx_Auto3565;
	for (i=0; i < 8; i++)_Context->msg_FullScreen[i]=" ";
	_Context->msg_FullScreen[0]=en_FullScreen;
	_Context->msg_FullScreen[1]=fr_FullScreen;
	_Context->msg_FullScreen[2]=it_FullScreen;
	_Context->msg_FullScreen[3]=es_FullScreen;
	_Context->msg_FullScreen[4]=de_FullScreen;
	_Context->msg_FullScreen[5]=nl_FullScreen;
	_Context->msg_FullScreen[6]=pt_FullScreen;
	_Context->msg_FullScreen[7]=xx_FullScreen;
	_Context->hint_FullScreen[0]=en__FullScreen;
	_Context->hint_FullScreen[1]=fr__FullScreen;
	_Context->hint_FullScreen[2]=it__FullScreen;
	_Context->hint_FullScreen[3]=es__FullScreen;
	_Context->hint_FullScreen[4]=de__FullScreen;
	_Context->hint_FullScreen[5]=nl__FullScreen;
	_Context->hint_FullScreen[6]=pt__FullScreen;
	_Context->hint_FullScreen[7]=xx__FullScreen;
	for (i=0; i < 8; i++)_Context->msg_Auto3566[i]=" ";
	_Context->msg_Auto3566[0]=en_Auto3566;
	_Context->msg_Auto3566[1]=fr_Auto3566;
	_Context->msg_Auto3566[2]=it_Auto3566;
	_Context->msg_Auto3566[3]=es_Auto3566;
	_Context->msg_Auto3566[4]=de_Auto3566;
	_Context->msg_Auto3566[5]=nl_Auto3566;
	_Context->msg_Auto3566[6]=pt_Auto3566;
	_Context->msg_Auto3566[7]=xx_Auto3566;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3563,_Context->y_Auto3563,730+10,540+10);
	return(0);
}

public 	int	accept_help_messages_hide(struct accept_help_messages_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	close_window_editor();
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3563,_Context->y_Auto3563);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_help_messages_remove(
	struct accept_help_messages_context * _Context,
	char * pEnglish,
	char * pFrancais,
	char * pItaliano,
	char * pEspagnol,
	char * pDeutsch,
	char * pNederlands,
	char * pPortugues,
	char * pOther)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	drop_tool_manager();
	if (_Context->keycode == 27 ) {
		filetransferdrop(_Context->buffer_English);
		filetransferdrop(_Context->buffer_Francais);
		filetransferdrop(_Context->buffer_Italiano);
		filetransferdrop(_Context->buffer_Espagnol);
		filetransferdrop(_Context->buffer_Deutsch);
		filetransferdrop(_Context->buffer_Nederlands);
		filetransferdrop(_Context->buffer_Portugues);
		filetransferdrop(_Context->buffer_Other);
		
	} else {
		strcpy(_Context->signature,"TTTTTTTT");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(&_Context->buffer_English, 1978, pEnglish);
		visual_transferout(&_Context->buffer_Francais, 1978, pFrancais);
		visual_transferout(&_Context->buffer_Italiano, 1978, pItaliano);
		visual_transferout(&_Context->buffer_Espagnol, 1978, pEspagnol);
		visual_transferout(&_Context->buffer_Deutsch, 1978, pDeutsch);
		visual_transferout(&_Context->buffer_Nederlands, 1978, pNederlands);
		visual_transferout(&_Context->buffer_Portugues, 1978, pPortugues);
		visual_transferout(&_Context->buffer_Other, 1978, pOther);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_TabEnglish_show(struct accept_help_messages_context * _Context) {
	open_window_editor(_Context->x_Auto3563+20,_Context->y_Auto3563+90,
	688,368,_Context->buffer_English);
	return(-1);
}
private int on_English_show(struct accept_help_messages_context * _Context) {
	toggle_colour_control('H');
	show_window_editor();
	return(-1);
}
private int on_TabFrancais_show(struct accept_help_messages_context * _Context) {
	open_window_editor(_Context->x_Auto3563+20,_Context->y_Auto3563+90,
	688,368,_Context->buffer_Francais);
	return(-1);
}
private int on_Francais_show(struct accept_help_messages_context * _Context) {
	toggle_colour_control('H');
	show_window_editor();
	return(-1);
}
private int on_TabItaliano_show(struct accept_help_messages_context * _Context) {
	open_window_editor(_Context->x_Auto3563+20,_Context->y_Auto3563+90,
	688,368,_Context->buffer_Italiano);
	return(-1);
}
private int on_Italiano_show(struct accept_help_messages_context * _Context) {
	toggle_colour_control('H');
	show_window_editor();
	return(-1);
}
private int on_TabEspagnol_show(struct accept_help_messages_context * _Context) {
	open_window_editor(_Context->x_Auto3563+20,_Context->y_Auto3563+90,
	688,368,_Context->buffer_Espagnol);
	return(-1);
}
private int on_Espagnol_show(struct accept_help_messages_context * _Context) {
	toggle_colour_control('H');
	show_window_editor();
	return(-1);
}
private int on_TabDeutsch_show(struct accept_help_messages_context * _Context) {
	open_window_editor(_Context->x_Auto3563+20,_Context->y_Auto3563+90,
	688,368,_Context->buffer_Deutsch);
	return(-1);
}
private int on_Deutsch_show(struct accept_help_messages_context * _Context) {
	toggle_colour_control('H');
	show_window_editor();
	return(-1);
}
private int on_TabNederlands_show(struct accept_help_messages_context * _Context) {
	open_window_editor(_Context->x_Auto3563+20,_Context->y_Auto3563+90,
	688,368,_Context->buffer_Nederlands);
	return(-1);
}
private int on_Nederlands_show(struct accept_help_messages_context * _Context) {
	toggle_colour_control('H');
	show_window_editor();
	return(-1);
}
private int on_TabPortugues_show(struct accept_help_messages_context * _Context) {
	open_window_editor(_Context->x_Auto3563+20,_Context->y_Auto3563+90,
	688,368,_Context->buffer_Portugues);
	return(-1);
}
private int on_Portugues_show(struct accept_help_messages_context * _Context) {
	toggle_colour_control('H');
	show_window_editor();
	return(-1);
}
private int on_TabOther_show(struct accept_help_messages_context * _Context) {
	open_window_editor(_Context->x_Auto3563+20,_Context->y_Auto3563+90,
	688,368,_Context->buffer_Other);
	return(-1);
}
private int on_Other_show(struct accept_help_messages_context * _Context) {
	toggle_colour_control('H');
	show_window_editor();
	return(-1);
}

public	int	accept_help_messages_show(struct accept_help_messages_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3563,_Context->y_Auto3563);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3563,_Context->y_Auto3563,730,540,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3563,_Context->y_Auto3563,730,540,vfh[1],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto3563+20,_Context->y_Auto3563+24,650,22,vfh[4],16,0,_Context->msg_Auto3564[_Context->language],strlen(_Context->msg_Auto3564[_Context->language]),1283);
	if (_Context->page_number == 1 ) {
	_Context->trigger_TabEnglish=visual_trigger_code(_Context->msg_TabEnglish[_Context->language],strlen(_Context->msg_TabEnglish[_Context->language]));
	visual_tabpage(_Context->x_Auto3563+10,_Context->y_Auto3563+50,710,420,vfh[2],_Context->msg_TabEnglish[_Context->language],strlen(_Context->msg_TabEnglish[_Context->language]),0,34);
		(void) on_TabEnglish_show(_Context);
	} else {
		visual_tabpage(_Context->x_Auto3563+10,_Context->y_Auto3563+50,710,420,vfh[2],_Context->msg_TabEnglish[_Context->language],strlen(_Context->msg_TabEnglish[_Context->language]),0,32);
		}
	if (_Context->page_number == 1 ) {
	(void) on_English_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_TabFrancais=visual_trigger_code(_Context->msg_TabFrancais[_Context->language],strlen(_Context->msg_TabFrancais[_Context->language]));
	visual_tabpage(_Context->x_Auto3563+10,_Context->y_Auto3563+50,710,420,vfh[2],_Context->msg_TabFrancais[_Context->language],strlen(_Context->msg_TabFrancais[_Context->language]),81,34);
		(void) on_TabFrancais_show(_Context);
	} else {
		visual_tabpage(_Context->x_Auto3563+10,_Context->y_Auto3563+50,710,420,vfh[2],_Context->msg_TabFrancais[_Context->language],strlen(_Context->msg_TabFrancais[_Context->language]),81,32);
		}
	if (_Context->page_number == 2 ) {
	(void) on_Francais_show(_Context);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_TabItaliano=visual_trigger_code(_Context->msg_TabItaliano[_Context->language],strlen(_Context->msg_TabItaliano[_Context->language]));
	visual_tabpage(_Context->x_Auto3563+10,_Context->y_Auto3563+50,710,420,vfh[2],_Context->msg_TabItaliano[_Context->language],strlen(_Context->msg_TabItaliano[_Context->language]),170,34);
		(void) on_TabItaliano_show(_Context);
	} else {
		visual_tabpage(_Context->x_Auto3563+10,_Context->y_Auto3563+50,710,420,vfh[2],_Context->msg_TabItaliano[_Context->language],strlen(_Context->msg_TabItaliano[_Context->language]),170,32);
		}
	if (_Context->page_number == 3 ) {
	(void) on_Italiano_show(_Context);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_TabEspagnol=visual_trigger_code(_Context->msg_TabEspagnol[_Context->language],strlen(_Context->msg_TabEspagnol[_Context->language]));
	visual_tabpage(_Context->x_Auto3563+10,_Context->y_Auto3563+50,710,420,vfh[2],_Context->msg_TabEspagnol[_Context->language],strlen(_Context->msg_TabEspagnol[_Context->language]),250,34);
		(void) on_TabEspagnol_show(_Context);
	} else {
		visual_tabpage(_Context->x_Auto3563+10,_Context->y_Auto3563+50,710,420,vfh[2],_Context->msg_TabEspagnol[_Context->language],strlen(_Context->msg_TabEspagnol[_Context->language]),250,32);
		}
	if (_Context->page_number == 4 ) {
	(void) on_Espagnol_show(_Context);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_TabDeutsch=visual_trigger_code(_Context->msg_TabDeutsch[_Context->language],strlen(_Context->msg_TabDeutsch[_Context->language]));
	visual_tabpage(_Context->x_Auto3563+10,_Context->y_Auto3563+50,710,420,vfh[2],_Context->msg_TabDeutsch[_Context->language],strlen(_Context->msg_TabDeutsch[_Context->language]),342,34);
		(void) on_TabDeutsch_show(_Context);
	} else {
		visual_tabpage(_Context->x_Auto3563+10,_Context->y_Auto3563+50,710,420,vfh[2],_Context->msg_TabDeutsch[_Context->language],strlen(_Context->msg_TabDeutsch[_Context->language]),342,32);
		}
	if (_Context->page_number == 5 ) {
	(void) on_Deutsch_show(_Context);
		}
	if (_Context->page_number == 6 ) {
	_Context->trigger_TabNederlands=visual_trigger_code(_Context->msg_TabNederlands[_Context->language],strlen(_Context->msg_TabNederlands[_Context->language]));
	visual_tabpage(_Context->x_Auto3563+10,_Context->y_Auto3563+50,710,420,vfh[2],_Context->msg_TabNederlands[_Context->language],strlen(_Context->msg_TabNederlands[_Context->language]),429,34);
		(void) on_TabNederlands_show(_Context);
	} else {
		visual_tabpage(_Context->x_Auto3563+10,_Context->y_Auto3563+50,710,420,vfh[2],_Context->msg_TabNederlands[_Context->language],strlen(_Context->msg_TabNederlands[_Context->language]),429,32);
		}
	if (_Context->page_number == 6 ) {
	(void) on_Nederlands_show(_Context);
		}
	if (_Context->page_number == 7 ) {
	_Context->trigger_TabPortugues=visual_trigger_code(_Context->msg_TabPortugues[_Context->language],strlen(_Context->msg_TabPortugues[_Context->language]));
	visual_tabpage(_Context->x_Auto3563+10,_Context->y_Auto3563+50,710,420,vfh[2],_Context->msg_TabPortugues[_Context->language],strlen(_Context->msg_TabPortugues[_Context->language]),533,34);
		(void) on_TabPortugues_show(_Context);
	} else {
		visual_tabpage(_Context->x_Auto3563+10,_Context->y_Auto3563+50,710,420,vfh[2],_Context->msg_TabPortugues[_Context->language],strlen(_Context->msg_TabPortugues[_Context->language]),533,32);
		}
	if (_Context->page_number == 7 ) {
	(void) on_Portugues_show(_Context);
		}
	if (_Context->page_number == 8 ) {
	_Context->trigger_TabOther=visual_trigger_code(_Context->msg_TabOther[_Context->language],strlen(_Context->msg_TabOther[_Context->language]));
	visual_tabpage(_Context->x_Auto3563+10,_Context->y_Auto3563+50,710,420,vfh[2],_Context->msg_TabOther[_Context->language],strlen(_Context->msg_TabOther[_Context->language]),632,34);
		(void) on_TabOther_show(_Context);
	} else {
		visual_tabpage(_Context->x_Auto3563+10,_Context->y_Auto3563+50,710,420,vfh[2],_Context->msg_TabOther[_Context->language],strlen(_Context->msg_TabOther[_Context->language]),632,32);
		}
	if (_Context->page_number == 8 ) {
	(void) on_Other_show(_Context);
		}
	_Context->trigger_Auto3565=visual_trigger_code(_Context->msg_Auto3565[_Context->language],strlen(_Context->msg_Auto3565[_Context->language]));
	visual_button(_Context->x_Auto3563+10,_Context->y_Auto3563+480,56,48,vfh[2],34,0,_Context->msg_Auto3565[_Context->language],strlen(_Context->msg_Auto3565[_Context->language]),1040);
	_Context->trigger_FullScreen=visual_trigger_code(_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]));
	visual_button(_Context->x_Auto3563+340,_Context->y_Auto3563+480,56,48,vfh[2],28,28,_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]),1040);
	_Context->trigger_Auto3566=visual_trigger_code(_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]));
	visual_button(_Context->x_Auto3563+660,_Context->y_Auto3563+480,56,48,vfh[2],34,0,_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3563,_Context->y_Auto3563,730,540);

	return(0);
}

private int TabEnglish_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This page allows the english help text to be specified.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int English_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Specify the help text content. You may use any body legal html constructions. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TabFrancais_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This page allows the french language help text to be specified.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Francais_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Specify the help text content. You may use any body legal html constructions. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TabItaliano_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This page allows the italian help text to be specified.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Italiano_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Specify the help text content. You may use any body legal html constructions. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TabEspagnol_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This page allows the spanish help text to be specified.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Espagnol_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Specify the help text content. You may use any body legal html constructions. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TabDeutsch_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This page allows the german help text to be specified.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Deutsch_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Specify the help text content. You may use any body legal html constructions. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TabNederlands_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This page allows the help text for the dutch language to be specified. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Nederlands_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Specify the help text content. You may use any body legal html constructions. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TabPortugues_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This page allows the help text for the portugese language to be specified. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Portugues_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Specify the help text content. You may use any body legal html constructions. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TabOther_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This page allows the help text for the final optional language to ";
			mptr[1]="be specified.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Other_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Specify the help text content. You may use any body legal html constructions. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3565_help()
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

private int FullScreen_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The current page of national language help text may be sent to the ";
			mptr[1]="full page internal editor for large documents requiring better visibility. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3566_help()
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

private int Auto3563action(struct accept_help_messages_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_help_messages_hide(_Context);

		_Context->x_Auto3563 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3563 < 0) { _Context->x_Auto3563=0; }
		_Context->y_Auto3563 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3563 < 0) { _Context->y_Auto3563=0; }
			accept_help_messages_show(_Context);

		visual_thaw(_Context->x_Auto3563,_Context->y_Auto3563,730,540);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3565_event(struct accept_help_messages_context * _Context) {
	return(13);
	return(-1);
}
private int on_FullScreen_event(struct accept_help_messages_context * _Context) {
		accept_help_messages_hide(_Context);
;
	switch(_Context->page_number){
	case 1:
	use_editor(_Context->buffer_English,_GENERATE_HTML);
		accept_help_messages_show(_Context);
;
	visual_frame(_Context->x_Auto3563+20,_Context->y_Auto3563+90,688+2,368+2,5);
;
		/* English */
	/* TabEnglish */
	accept_help_messages_losefocus(_Context);
	_Context->page_number = 1;
	accept_help_messages_show(_Context);
	_Context->focus_item=2;
	accept_help_messages_show(_Context);
	_Context->focus_item=3;
;
	break;
	case 2:
	use_editor(_Context->buffer_Francais,_GENERATE_HTML);
		accept_help_messages_show(_Context);
;
	visual_frame(_Context->x_Auto3563+20,_Context->y_Auto3563+90,688+2,368+2,5);
;
		/* Francais */
	/* TabFrancais */
	accept_help_messages_losefocus(_Context);
	_Context->page_number = 2;
	accept_help_messages_show(_Context);
	_Context->focus_item=4;
	accept_help_messages_show(_Context);
	_Context->focus_item=5;
;
	break;
	case 3:
	use_editor(_Context->buffer_Italiano,_GENERATE_HTML);
		accept_help_messages_show(_Context);
;
	visual_frame(_Context->x_Auto3563+20,_Context->y_Auto3563+90,688+2,368+2,5);
;
		/* Italiano */
	/* TabItaliano */
	accept_help_messages_losefocus(_Context);
	_Context->page_number = 3;
	accept_help_messages_show(_Context);
	_Context->focus_item=6;
	accept_help_messages_show(_Context);
	_Context->focus_item=7;
;
	break;
	case 4:
	use_editor(_Context->buffer_Espagnol,_GENERATE_HTML);
		accept_help_messages_show(_Context);
;
	visual_frame(_Context->x_Auto3563+20,_Context->y_Auto3563+90,688+2,368+2,5);
;
		/* Espagnol */
	/* TabEspagnol */
	accept_help_messages_losefocus(_Context);
	_Context->page_number = 4;
	accept_help_messages_show(_Context);
	_Context->focus_item=8;
	accept_help_messages_show(_Context);
	_Context->focus_item=9;
;
	break;
	case 5:
	use_editor(_Context->buffer_Deutsch,_GENERATE_HTML);
		accept_help_messages_show(_Context);
;
	visual_frame(_Context->x_Auto3563+20,_Context->y_Auto3563+90,688+2,368+2,5);
;
		/* Deutsch */
	/* TabDeutsch */
	accept_help_messages_losefocus(_Context);
	_Context->page_number = 5;
	accept_help_messages_show(_Context);
	_Context->focus_item=10;
	accept_help_messages_show(_Context);
	_Context->focus_item=11;
;
	break;
	case 6:
	use_editor(_Context->buffer_Nederlands,_GENERATE_HTML);
		accept_help_messages_show(_Context);
;
	visual_frame(_Context->x_Auto3563+20,_Context->y_Auto3563+90,688+2,368+2,5);
;
		/* Nederlands */
	/* TabNederlands */
	accept_help_messages_losefocus(_Context);
	_Context->page_number = 6;
	accept_help_messages_show(_Context);
	_Context->focus_item=12;
	accept_help_messages_show(_Context);
	_Context->focus_item=13;
;
	break;
	case 7:
	use_editor(_Context->buffer_Portugues,_GENERATE_HTML);
		accept_help_messages_show(_Context);
;
	visual_frame(_Context->x_Auto3563+20,_Context->y_Auto3563+90,688+2,368+2,5);
;
		/* Portugues */
	/* TabPortugues */
	accept_help_messages_losefocus(_Context);
	_Context->page_number = 7;
	accept_help_messages_show(_Context);
	_Context->focus_item=14;
	accept_help_messages_show(_Context);
	_Context->focus_item=15;
;
	break;
	case 8:
	use_editor(_Context->buffer_Other,_GENERATE_HTML);
		accept_help_messages_show(_Context);
;
	visual_frame(_Context->x_Auto3563+20,_Context->y_Auto3563+90,688+2,368+2,5);
;
		/* Other */
	/* TabOther */
	accept_help_messages_losefocus(_Context);
	_Context->page_number = 8;
	accept_help_messages_show(_Context);
	_Context->focus_item=16;
	accept_help_messages_show(_Context);
	_Context->focus_item=17;
;
	break;
	}
	return(-1);
}
private int on_Auto3566_event(struct accept_help_messages_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_help_messages_event(
struct accept_help_messages_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_TabEnglish == mb ) return(2);
		if (_Context->trigger_TabFrancais == mb ) return(4);
		if (_Context->trigger_TabItaliano == mb ) return(6);
		if (_Context->trigger_TabEspagnol == mb ) return(8);
		if (_Context->trigger_TabDeutsch == mb ) return(10);
		if (_Context->trigger_TabNederlands == mb ) return(12);
		if (_Context->trigger_TabPortugues == mb ) return(14);
		if (_Context->trigger_TabOther == mb ) return(16);
		if (_Context->trigger_Auto3565 == mb ) return(18);
		if (_Context->trigger_FullScreen == mb ) return(19);
		if (_Context->trigger_Auto3566 == mb ) return(20);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3563+709) )  
	&&  (my >= (_Context->y_Auto3563+4) )  
	&&  (mx <= (_Context->x_Auto3563+726) )  
	&&  (my <= (_Context->y_Auto3563+20) )) {
		return(1);	/* Auto3563 */

		}
	if ((mx >= (_Context->x_Auto3563+693) )  
	&&  (my >= (_Context->y_Auto3563+4) )  
	&&  (mx <= (_Context->x_Auto3563+710) )  
	&&  (my <= (_Context->y_Auto3563+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vhelper.htm");
			};
		return(-1);	/* Auto3563 */

		}
	if ((mx >= (_Context->x_Auto3563+677) )  
	&&  (my >= (_Context->y_Auto3563+4) )  
	&&  (mx <= (_Context->x_Auto3563+694) )  
	&&  (my <= (_Context->y_Auto3563+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_help_messages_show(_Context);
		return(-1);	/* Auto3563 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3563+4) )  
		&&  (my >= (_Context->y_Auto3563+4) )  
		&&  (mx <= (_Context->x_Auto3563+662) )  
		&&  (my <= (_Context->y_Auto3563+20) )) {
			return( Auto3563action(_Context) );
			}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto3563+10+0) ) 
		&&  ( my >= (_Context->y_Auto3563+50) ) 
		&&  ( mx <= (_Context->x_Auto3563+10+80) ) 
		&&  ( my <= (_Context->y_Auto3563+50+24))) {
			return(2); /* TabEnglish */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3563+20) ) 
		&&  ( my >= (_Context->y_Auto3563+90) ) 
		&&  ( mx <= (_Context->x_Auto3563+20+688) ) 
		&&  ( my <= (_Context->y_Auto3563+90+368))) {
			return(3); /* English */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto3563+10+81) ) 
		&&  ( my >= (_Context->y_Auto3563+50) ) 
		&&  ( mx <= (_Context->x_Auto3563+10+169) ) 
		&&  ( my <= (_Context->y_Auto3563+50+24))) {
			return(4); /* TabFrancais */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3563+20) ) 
		&&  ( my >= (_Context->y_Auto3563+90) ) 
		&&  ( mx <= (_Context->x_Auto3563+20+688) ) 
		&&  ( my <= (_Context->y_Auto3563+90+368))) {
			return(5); /* Francais */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_Auto3563+10+170) ) 
		&&  ( my >= (_Context->y_Auto3563+50) ) 
		&&  ( mx <= (_Context->x_Auto3563+10+249) ) 
		&&  ( my <= (_Context->y_Auto3563+50+24))) {
			return(6); /* TabItaliano */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3563+20) ) 
		&&  ( my >= (_Context->y_Auto3563+90) ) 
		&&  ( mx <= (_Context->x_Auto3563+20+688) ) 
		&&  ( my <= (_Context->y_Auto3563+90+368))) {
			return(7); /* Italiano */
			}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if (( mx >= (_Context->x_Auto3563+10+250) ) 
		&&  ( my >= (_Context->y_Auto3563+50) ) 
		&&  ( mx <= (_Context->x_Auto3563+10+341) ) 
		&&  ( my <= (_Context->y_Auto3563+50+24))) {
			return(8); /* TabEspagnol */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3563+20) ) 
		&&  ( my >= (_Context->y_Auto3563+90) ) 
		&&  ( mx <= (_Context->x_Auto3563+20+688) ) 
		&&  ( my <= (_Context->y_Auto3563+90+368))) {
			return(9); /* Espagnol */
			}
		}
	if (_Context->page_number == 5 ) {
	} else {
		if (( mx >= (_Context->x_Auto3563+10+342) ) 
		&&  ( my >= (_Context->y_Auto3563+50) ) 
		&&  ( mx <= (_Context->x_Auto3563+10+428) ) 
		&&  ( my <= (_Context->y_Auto3563+50+24))) {
			return(10); /* TabDeutsch */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3563+20) ) 
		&&  ( my >= (_Context->y_Auto3563+90) ) 
		&&  ( mx <= (_Context->x_Auto3563+20+688) ) 
		&&  ( my <= (_Context->y_Auto3563+90+368))) {
			return(11); /* Deutsch */
			}
		}
	if (_Context->page_number == 6 ) {
	} else {
		if (( mx >= (_Context->x_Auto3563+10+429) ) 
		&&  ( my >= (_Context->y_Auto3563+50) ) 
		&&  ( mx <= (_Context->x_Auto3563+10+532) ) 
		&&  ( my <= (_Context->y_Auto3563+50+24))) {
			return(12); /* TabNederlands */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3563+20) ) 
		&&  ( my >= (_Context->y_Auto3563+90) ) 
		&&  ( mx <= (_Context->x_Auto3563+20+688) ) 
		&&  ( my <= (_Context->y_Auto3563+90+368))) {
			return(13); /* Nederlands */
			}
		}
	if (_Context->page_number == 7 ) {
	} else {
		if (( mx >= (_Context->x_Auto3563+10+533) ) 
		&&  ( my >= (_Context->y_Auto3563+50) ) 
		&&  ( mx <= (_Context->x_Auto3563+10+631) ) 
		&&  ( my <= (_Context->y_Auto3563+50+24))) {
			return(14); /* TabPortugues */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3563+20) ) 
		&&  ( my >= (_Context->y_Auto3563+90) ) 
		&&  ( mx <= (_Context->x_Auto3563+20+688) ) 
		&&  ( my <= (_Context->y_Auto3563+90+368))) {
			return(15); /* Portugues */
			}
		}
	if (_Context->page_number == 8 ) {
	} else {
		if (( mx >= (_Context->x_Auto3563+10+632) ) 
		&&  ( my >= (_Context->y_Auto3563+50) ) 
		&&  ( mx <= (_Context->x_Auto3563+10+704) ) 
		&&  ( my <= (_Context->y_Auto3563+50+24))) {
			return(16); /* TabOther */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto3563+20) ) 
		&&  ( my >= (_Context->y_Auto3563+90) ) 
		&&  ( mx <= (_Context->x_Auto3563+20+688) ) 
		&&  ( my <= (_Context->y_Auto3563+90+368))) {
			return(17); /* Other */
			}
		}
	if (( mx >= (_Context->x_Auto3563+10) ) 
	&&  ( my >= (_Context->y_Auto3563+480) ) 
	&&  ( mx <= (_Context->x_Auto3563+10+56) ) 
	&&  ( my <= (_Context->y_Auto3563+480+48))) {
		return(18); /* Auto3565 */
		}
	if (( mx >= (_Context->x_Auto3563+340) ) 
	&&  ( my >= (_Context->y_Auto3563+480) ) 
	&&  ( mx <= (_Context->x_Auto3563+340+56) ) 
	&&  ( my <= (_Context->y_Auto3563+480+48))) {
		return(19); /* FullScreen */
		}
	if (( mx >= (_Context->x_Auto3563+660) ) 
	&&  ( my >= (_Context->y_Auto3563+480) ) 
	&&  ( mx <= (_Context->x_Auto3563+660+56) ) 
	&&  ( my <= (_Context->y_Auto3563+480+48))) {
		return(20); /* Auto3566 */
		}

	return(-1);
}


public	int	accept_help_messages_losefocus(struct accept_help_messages_context * _Context)
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;
		case 3 : 
			break;
		case 4 : 
			break;
		case 5 : 
			break;
		case 6 : 
			break;
		case 7 : 
			break;
		case 8 : 
			break;

		}
	return(0);

}
private int on_English_getfocus(struct accept_help_messages_context * _Context) {
	toggle_colour_control('H');
	return(focus_window_editor());
	return(-1);
}
private int on_Francais_getfocus(struct accept_help_messages_context * _Context) {
	toggle_colour_control('H');
	return(focus_window_editor());
	return(-1);
}
private int on_Italiano_getfocus(struct accept_help_messages_context * _Context) {
	toggle_colour_control('H');
	return(focus_window_editor());
	return(-1);
}
private int on_Espagnol_getfocus(struct accept_help_messages_context * _Context) {
	toggle_colour_control('H');
	return(focus_window_editor());
	return(-1);
}
private int on_Deutsch_getfocus(struct accept_help_messages_context * _Context) {
	toggle_colour_control('H');
	return(focus_window_editor());
	return(-1);
}
private int on_Nederlands_getfocus(struct accept_help_messages_context * _Context) {
	toggle_colour_control('H');
	return(focus_window_editor());
	return(-1);
}
private int on_Portugues_getfocus(struct accept_help_messages_context * _Context) {
	toggle_colour_control('H');
	return(focus_window_editor());
	return(-1);
}
private int on_Other_getfocus(struct accept_help_messages_context * _Context) {
	toggle_colour_control('H');
	return(focus_window_editor());
	return(-1);
}


public	int	accept_help_messages_focus(struct accept_help_messages_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* TabEnglish */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x3 :
				/* English */
				if (_Context->page_number == 1 ) {
					_Context->keycode = on_English_getfocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* TabFrancais */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x5 :
				/* Francais */
				if (_Context->page_number == 2 ) {
					_Context->keycode = on_Francais_getfocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* TabItaliano */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x7 :
				/* Italiano */
				if (_Context->page_number == 3 ) {
					_Context->keycode = on_Italiano_getfocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* TabEspagnol */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x9 :
				/* Espagnol */
				if (_Context->page_number == 4 ) {
					_Context->keycode = on_Espagnol_getfocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* TabDeutsch */
				if (_Context->page_number == 5 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xb :
				/* Deutsch */
				if (_Context->page_number == 5 ) {
					_Context->keycode = on_Deutsch_getfocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* TabNederlands */
				if (_Context->page_number == 6 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xd :
				/* Nederlands */
				if (_Context->page_number == 6 ) {
					_Context->keycode = on_Nederlands_getfocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* TabPortugues */
				if (_Context->page_number == 7 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xf :
				/* Portugues */
				if (_Context->page_number == 7 ) {
					_Context->keycode = on_Portugues_getfocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* TabOther */
				if (_Context->page_number == 8 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x11 :
				/* Other */
				if (_Context->page_number == 8 ) {
					_Context->keycode = on_Other_getfocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* Auto3565 */
				_Context->trigger_Auto3565=visual_trigger_code(_Context->msg_Auto3565[_Context->language],strlen(_Context->msg_Auto3565[_Context->language]));
				visual_button(_Context->x_Auto3563+10,_Context->y_Auto3563+480,56,48,vfh[2],34,0,_Context->msg_Auto3565[_Context->language],strlen(_Context->msg_Auto3565[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3565=visual_trigger_code(_Context->msg_Auto3565[_Context->language],strlen(_Context->msg_Auto3565[_Context->language]));
	visual_button(_Context->x_Auto3563+10,_Context->y_Auto3563+480,56,48,vfh[2],34,0,_Context->msg_Auto3565[_Context->language],strlen(_Context->msg_Auto3565[_Context->language]),1040);
				break;
			case	0x14 :
				/* Auto3566 */
				_Context->trigger_Auto3566=visual_trigger_code(_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]));
				visual_button(_Context->x_Auto3563+660,_Context->y_Auto3563+480,56,48,vfh[2],34,0,_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3566=visual_trigger_code(_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]));
	visual_button(_Context->x_Auto3563+660,_Context->y_Auto3563+480,56,48,vfh[2],34,0,_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			accept_help_messages_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_help_messages_show(_Context);
			continue;
		case	0x2 :
			accept_help_messages_losefocus(_Context);
			_Context->page_number=8;
			_Context->focus_item=20;
			accept_help_messages_show(_Context);
			continue;
		case	0x3 :
			accept_help_messages_losefocus(_Context);
			if ( _Context->page_number < 8 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_help_messages_show(_Context);
			continue;
		case	0x12 :
			accept_help_messages_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_help_messages_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_help_messages_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (TabEnglish_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (English_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (TabFrancais_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Francais_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (TabItaliano_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (Italiano_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (TabEspagnol_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (Espagnol_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (TabDeutsch_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Deutsch_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (TabNederlands_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (Nederlands_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (TabPortugues_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (Portugues_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (TabOther_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (Other_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (Auto3565_help(_Context) != 0) { continue; }
						else { break; }
					case	0x13 :
						if (FullScreen_help(_Context) != 0) { continue; }
						else { break; }
					case	0x14 :
						if (Auto3566_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3563 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* TabEnglish */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_help_messages_losefocus(_Context);
						_Context->page_number = 1;
						accept_help_messages_show(_Context);
						}
					continue;
				case	0x3 :
					/* English */
					continue;
				case	0x4 :
					/* TabFrancais */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_help_messages_losefocus(_Context);
						_Context->page_number = 2;
						accept_help_messages_show(_Context);
						}
					continue;
				case	0x5 :
					/* Francais */
					continue;
				case	0x6 :
					/* TabItaliano */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_help_messages_losefocus(_Context);
						_Context->page_number = 3;
						accept_help_messages_show(_Context);
						}
					continue;
				case	0x7 :
					/* Italiano */
					continue;
				case	0x8 :
					/* TabEspagnol */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_help_messages_losefocus(_Context);
						_Context->page_number = 4;
						accept_help_messages_show(_Context);
						}
					continue;
				case	0x9 :
					/* Espagnol */
					continue;
				case	0xa :
					/* TabDeutsch */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_help_messages_losefocus(_Context);
						_Context->page_number = 5;
						accept_help_messages_show(_Context);
						}
					continue;
				case	0xb :
					/* Deutsch */
					continue;
				case	0xc :
					/* TabNederlands */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_help_messages_losefocus(_Context);
						_Context->page_number = 6;
						accept_help_messages_show(_Context);
						}
					continue;
				case	0xd :
					/* Nederlands */
					continue;
				case	0xe :
					/* TabPortugues */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_help_messages_losefocus(_Context);
						_Context->page_number = 7;
						accept_help_messages_show(_Context);
						}
					continue;
				case	0xf :
					/* Portugues */
					continue;
				case	0x10 :
					/* TabOther */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_help_messages_losefocus(_Context);
						_Context->page_number = 8;
						accept_help_messages_show(_Context);
						}
					continue;
				case	0x11 :
					/* Other */
					continue;
				case	0x12 :
					/* Auto3565 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3565=visual_trigger_code(_Context->msg_Auto3565[_Context->language],strlen(_Context->msg_Auto3565[_Context->language]));
						visual_button(_Context->x_Auto3563+10,_Context->y_Auto3563+480,56,48,vfh[2],34,0,_Context->msg_Auto3565[_Context->language],strlen(_Context->msg_Auto3565[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3565=visual_trigger_code(_Context->msg_Auto3565[_Context->language],strlen(_Context->msg_Auto3565[_Context->language]));
	visual_button(_Context->x_Auto3563+10,_Context->y_Auto3563+480,56,48,vfh[2],34,0,_Context->msg_Auto3565[_Context->language],strlen(_Context->msg_Auto3565[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3565_event(_Context)) != -1) break;

						}
					continue;
				case	0x13 :
					/* FullScreen */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_FullScreen=visual_trigger_code(_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]));
						visual_button(_Context->x_Auto3563+340,_Context->y_Auto3563+480,56,48,vfh[2],28,28,_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_FullScreen=visual_trigger_code(_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]));
	visual_button(_Context->x_Auto3563+340,_Context->y_Auto3563+480,56,48,vfh[2],28,28,_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_FullScreen_event(_Context)) != -1) break;

						}
					continue;
				case	0x14 :
					/* Auto3566 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3566=visual_trigger_code(_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]));
						visual_button(_Context->x_Auto3563+660,_Context->y_Auto3563+480,56,48,vfh[2],34,0,_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3566=visual_trigger_code(_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]));
	visual_button(_Context->x_Auto3563+660,_Context->y_Auto3563+480,56,48,vfh[2],34,0,_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3566_event(_Context)) != -1) break;

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
				_Context->focus_item=20;
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

public	int	accept_help_messages(
	char * pEnglish,
	char * pFrancais,
	char * pItaliano,
	char * pEspagnol,
	char * pDeutsch,
	char * pNederlands,
	char * pPortugues,
	char * pOther)
{
	int	status=0;
	struct accept_help_messages_context * _Context=(struct accept_help_messages_context*) 0;
	status = accept_help_messages_create(
	&_Context,
	 pEnglish,
	 pFrancais,
	 pItaliano,
	 pEspagnol,
	 pDeutsch,
	 pNederlands,
	 pPortugues,
	 pOther);
	if ( status != 0) return(status);
	status = accept_help_messages_show(_Context);
		enter_modal();
	status = accept_help_messages_focus(_Context);
		leave_modal();
	status = accept_help_messages_hide(_Context);
	status = accept_help_messages_remove(
	_Context,
	 pEnglish,
	 pFrancais,
	 pItaliano,
	 pEspagnol,
	 pDeutsch,
	 pNederlands,
	 pPortugues,
	 pOther);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vhelper_c */
