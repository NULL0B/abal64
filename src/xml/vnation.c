
#ifndef _vnation_c
#define _vnation_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vnation.xml                                              */
/* Target         : vnation.c                                                */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto3578   ""
#define fr__Auto3578   ""
#define it__Auto3578   ""
#define es__Auto3578   ""
#define de__Auto3578   ""
#define nl__Auto3578   ""
#define pt__Auto3578   ""
#define xx__Auto3578   ""
#define en_Auto3579   "International Message Editor"
#define fr_Auto3579   "Editeur de messages multilingues"
#define it_Auto3579   "International Message Editor"
#define es_Auto3579   "International Message Editor"
#define de_Auto3579   "International Message Editor"
#define nl_Auto3579   "International Message Editor"
#define pt_Auto3579   "International Message Editor"
#define xx_Auto3579   "International Message Editor"
#define en_TabEnglish   "&English"
#define fr_TabEnglish   "&English"
#define it_TabEnglish   "English"
#define es_TabEnglish   "English"
#define de_TabEnglish   "English"
#define nl_TabEnglish   "English"
#define pt_TabEnglish   "English"
#define xx_TabEnglish   "English"
#define en_Auto3580   "Payload"
#define fr_Auto3580   "Libell‚"
#define it_Auto3580   "Payload"
#define es_Auto3580   "Payload"
#define de_Auto3580   "Payload"
#define nl_Auto3580   "Payload"
#define pt_Auto3580   "Payload"
#define xx_Auto3580   "Payload"
#define en__Auto3580   ""
#define en_Auto3581   "Hint"
#define fr_Auto3581   "Infobulle"
#define it_Auto3581   "Hint"
#define es_Auto3581   "Hint"
#define de_Auto3581   "Hint"
#define nl_Auto3581   "Hint"
#define pt_Auto3581   "Hint"
#define xx_Auto3581   "Hint"
#define en__Auto3581   ""
#define en_HintEnglish   ""
#define en__HintEnglish   ""
#define en_TabFrancais   "&Fran‡ais"
#define fr_TabFrancais   "&Fran‡ais"
#define it_TabFrancais   "Fran‡ais"
#define es_TabFrancais   "Fran‡ais"
#define de_TabFrancais   "Fran‡ais"
#define nl_TabFrancais   "Fran‡ais"
#define pt_TabFrancais   "Fran‡ais"
#define xx_TabFrancais   "Fran‡ais"
#define en_Auto3582   "Payload"
#define fr_Auto3582   "Zone de donnee"
#define it_Auto3582   "Payload"
#define es_Auto3582   "Payload"
#define de_Auto3582   "Payload"
#define nl_Auto3582   "Payload"
#define pt_Auto3582   "Payload"
#define xx_Auto3582   "Payload"
#define en__Auto3582   ""
#define en_Auto3583   "Hint"
#define fr_Auto3583   "Hint (infobulle)"
#define it_Auto3583   "Hint"
#define es_Auto3583   "Hint"
#define de_Auto3583   "Hint"
#define nl_Auto3583   "Hint"
#define pt_Auto3583   "Hint"
#define xx_Auto3583   "Hint"
#define en__Auto3583   ""
#define en_HintFrancais   ""
#define en__HintFrancais   ""
#define en_TabItaliano   "&Italiano"
#define fr_TabItaliano   "&Italiano"
#define it_TabItaliano   "Italiano"
#define es_TabItaliano   "Italiano"
#define de_TabItaliano   "Italiano"
#define nl_TabItaliano   "Italiano"
#define pt_TabItaliano   "Italiano"
#define xx_TabItaliano   "Italiano"
#define en_Auto3584   "Payload"
#define fr_Auto3584   "Zone de donnee"
#define it_Auto3584   "Payload"
#define es_Auto3584   "Payload"
#define de_Auto3584   "Payload"
#define nl_Auto3584   "Payload"
#define pt_Auto3584   "Payload"
#define xx_Auto3584   "Payload"
#define en__Auto3584   ""
#define en_Auto3585   "Hint"
#define fr_Auto3585   "Hint (infobulle)"
#define it_Auto3585   "Hint"
#define es_Auto3585   "Hint"
#define de_Auto3585   "Hint"
#define nl_Auto3585   "Hint"
#define pt_Auto3585   "Hint"
#define xx_Auto3585   "Hint"
#define en__Auto3585   ""
#define en_HintItaliano   ""
#define en__HintItaliano   ""
#define en_TabEspagnol   "E&spagnol"
#define fr_TabEspagnol   "E&spagnol"
#define it_TabEspagnol   "Espagnol"
#define es_TabEspagnol   "Espagnol"
#define de_TabEspagnol   "Espagnol"
#define nl_TabEspagnol   "Espagnol"
#define pt_TabEspagnol   "Espagnol"
#define xx_TabEspagnol   "Espagnol"
#define en_HintEspagnol   ""
#define en__HintEspagnol   ""
#define en_Auto3586   "Payload"
#define fr_Auto3586   "Zone de donnee"
#define it_Auto3586   "Payload"
#define es_Auto3586   "Payload"
#define de_Auto3586   "Payload"
#define nl_Auto3586   "Payload"
#define pt_Auto3586   "Payload"
#define xx_Auto3586   "Payload"
#define en__Auto3586   ""
#define en_Auto3587   "Hint"
#define fr_Auto3587   "Hint (infobulle)"
#define it_Auto3587   "Hint"
#define es_Auto3587   "Hint"
#define de_Auto3587   "Hint"
#define nl_Auto3587   "Hint"
#define pt_Auto3587   "Hint"
#define xx_Auto3587   "Hint"
#define en__Auto3587   ""
#define en_TabDeutsch   "&Deutsch"
#define fr_TabDeutsch   "&Deutsch"
#define it_TabDeutsch   "Deutsch"
#define es_TabDeutsch   "Deutsch"
#define de_TabDeutsch   "Deutsch"
#define nl_TabDeutsch   "Deutsch"
#define pt_TabDeutsch   "Deutsch"
#define xx_TabDeutsch   "Deutsch"
#define en_Auto3588   "Payload"
#define fr_Auto3588   "Zone de donnee"
#define it_Auto3588   "Payload"
#define es_Auto3588   "Payload"
#define de_Auto3588   "Payload"
#define nl_Auto3588   "Payload"
#define pt_Auto3588   "Payload"
#define xx_Auto3588   "Payload"
#define en__Auto3588   ""
#define en_Auto3589   "Hint"
#define fr_Auto3589   "Hint (infobulle)"
#define it_Auto3589   "Hint"
#define es_Auto3589   "Hint"
#define de_Auto3589   "Hint"
#define nl_Auto3589   "Hint"
#define pt_Auto3589   "Hint"
#define xx_Auto3589   "Hint"
#define en__Auto3589   ""
#define en_HintDeutsch   ""
#define en__HintDeutsch   ""
#define en_TabNederlands   "Nede&rlands"
#define fr_TabNederlands   "&Nederlands"
#define it_TabNederlands   "Nederlands"
#define es_TabNederlands   "Nederlands"
#define de_TabNederlands   "Nederlands"
#define nl_TabNederlands   "Nederlands"
#define pt_TabNederlands   "Nederlands"
#define xx_TabNederlands   "Nederlands"
#define en_Auto3590   "Payload"
#define fr_Auto3590   "Zone de donnee"
#define it_Auto3590   "Payload"
#define es_Auto3590   "Payload"
#define de_Auto3590   "Payload"
#define nl_Auto3590   "Payload"
#define pt_Auto3590   "Payload"
#define xx_Auto3590   "Payload"
#define en__Auto3590   ""
#define en_Auto3591   "Hint"
#define fr_Auto3591   "Hint (infobulle)"
#define it_Auto3591   "Hint"
#define es_Auto3591   "Hint"
#define de_Auto3591   "Hint"
#define nl_Auto3591   "Hint"
#define pt_Auto3591   "Hint"
#define xx_Auto3591   "Hint"
#define en__Auto3591   ""
#define en_HintNederlands   ""
#define en__HintNederlands   ""
#define en_TabPortugues   "&Portugues"
#define fr_TabPortugues   "&Portugues"
#define it_TabPortugues   "Portugues"
#define es_TabPortugues   "Portugues"
#define de_TabPortugues   "Portugues"
#define nl_TabPortugues   "Portugues"
#define pt_TabPortugues   "Portugues"
#define xx_TabPortugues   "Portugues"
#define en_Auto3592   "Payload"
#define fr_Auto3592   "Zone de donnee"
#define it_Auto3592   "Payload"
#define es_Auto3592   "Payload"
#define de_Auto3592   "Payload"
#define nl_Auto3592   "Payload"
#define pt_Auto3592   "Payload"
#define xx_Auto3592   "Payload"
#define en__Auto3592   ""
#define en_Auto3593   "Hint"
#define fr_Auto3593   "Hint (infobulle)"
#define it_Auto3593   "Hint"
#define es_Auto3593   "Hint"
#define de_Auto3593   "Hint"
#define nl_Auto3593   "Hint"
#define pt_Auto3593   "Hint"
#define xx_Auto3593   "Hint"
#define en__Auto3593   ""
#define en_HintPortugues   ""
#define en__HintPortugues   ""
#define en_TabOther   "&Other"
#define fr_TabOther   "A&utre"
#define it_TabOther   "Other"
#define es_TabOther   "Other"
#define de_TabOther   "Andere"
#define nl_TabOther   "Other"
#define pt_TabOther   "Other"
#define xx_TabOther   "Eile"
#define en_Auto3594   "Payload"
#define fr_Auto3594   "Zone de donnee"
#define it_Auto3594   "Payload"
#define es_Auto3594   "Payload"
#define de_Auto3594   "Payload"
#define nl_Auto3594   "Payload"
#define pt_Auto3594   "Payload"
#define xx_Auto3594   "Payload"
#define en__Auto3594   ""
#define en_Auto3595   "Hint"
#define fr_Auto3595   "Hint (infobulle)"
#define it_Auto3595   "Hint"
#define es_Auto3595   "Hint"
#define de_Auto3595   "Hint"
#define nl_Auto3595   "Hint"
#define pt_Auto3595   "Hint"
#define xx_Auto3595   "Hint"
#define en__Auto3595   ""
#define en_HintOther   ""
#define en__HintOther   ""
#define en_Auto3596   "ok.gif"
#define fr_Auto3596   "ok.gif"
#define it_Auto3596   "ok.gif"
#define es_Auto3596   "ok.gif"
#define de_Auto3596   "ok.gif"
#define nl_Auto3596   "ok.gif"
#define pt_Auto3596   "ok.gif"
#define xx_Auto3596   "ok.gif"
#define en_Reset   "&Reset"
#define fr_Reset   "&Raz"
#define it_Reset   "&Reset"
#define es_Reset   "&Reset"
#define de_Reset   "&Reset"
#define nl_Reset   "&Reset"
#define pt_Reset   "&Reset"
#define xx_Reset   "&Reset"
#define en__Reset   ""
#define en_Copy   "&Copy"
#define fr_Copy   "&Copier"
#define it_Copy   "&Copy"
#define es_Copy   "&Copy"
#define de_Copy   "&Copy"
#define nl_Copy   "&Copy"
#define pt_Copy   "&Copy"
#define xx_Copy   "&Leth-Breac"
#define en__Copy   ""
#define en_Auto3597   "cancel.gif"
#define fr_Auto3597   "cancel.gif"
#define it_Auto3597   "cancel.gif"
#define es_Auto3597   "cancel.gif"
#define de_Auto3597   "cancel.gif"
#define nl_Auto3597   "cancel.gif"
#define pt_Auto3597   "cancel.gif"
#define xx_Auto3597   "cancel.gif"

private struct accept_widget_messages_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[8+1];
	char * msg_Auto3578[8];
	char * hint_Auto3578[8];
	int	x_Auto3578;
	int	y_Auto3578;
	int	w_Auto3578;
	int	h_Auto3578;
	char * msg_Auto3579[8];
	char * hint_Auto3579[8];
	char * msg_TabEnglish[8];
	int	trigger_TabEnglish;
	char * hint_TabEnglish[8];
	int	page_number;
	char * msg_Auto3580[8];
	char * hint_Auto3580[8];
	char * msg_Auto3581[8];
	char * hint_Auto3581[8];
	char * hint_English[8];
	char	buffer_English[851];
	char * hint_HintEnglish[8];
	char	buffer_HintEnglish[851];
	char * msg_TabFrancais[8];
	int	trigger_TabFrancais;
	char * hint_TabFrancais[8];
	char * msg_Auto3582[8];
	char * hint_Auto3582[8];
	char * msg_Auto3583[8];
	char * hint_Auto3583[8];
	char * hint_Francais[8];
	char	buffer_Francais[851];
	char * hint_HintFrancais[8];
	char	buffer_HintFrancais[851];
	char * msg_TabItaliano[8];
	int	trigger_TabItaliano;
	char * hint_TabItaliano[8];
	char * msg_Auto3584[8];
	char * hint_Auto3584[8];
	char * msg_Auto3585[8];
	char * hint_Auto3585[8];
	char * hint_Italiano[8];
	char	buffer_Italiano[851];
	char * hint_HintItaliano[8];
	char	buffer_HintItaliano[851];
	char * msg_TabEspagnol[8];
	int	trigger_TabEspagnol;
	char * hint_TabEspagnol[8];
	char * hint_Espagnol[8];
	char	buffer_Espagnol[851];
	char * hint_HintEspagnol[8];
	char	buffer_HintEspagnol[851];
	char * msg_Auto3586[8];
	char * hint_Auto3586[8];
	char * msg_Auto3587[8];
	char * hint_Auto3587[8];
	char * msg_TabDeutsch[8];
	int	trigger_TabDeutsch;
	char * hint_TabDeutsch[8];
	char * msg_Auto3588[8];
	char * hint_Auto3588[8];
	char * msg_Auto3589[8];
	char * hint_Auto3589[8];
	char * hint_Deutsch[8];
	char	buffer_Deutsch[851];
	char * hint_HintDeutsch[8];
	char	buffer_HintDeutsch[851];
	char * msg_TabNederlands[8];
	int	trigger_TabNederlands;
	char * hint_TabNederlands[8];
	char * msg_Auto3590[8];
	char * hint_Auto3590[8];
	char * msg_Auto3591[8];
	char * hint_Auto3591[8];
	char * hint_Nederlands[8];
	char	buffer_Nederlands[851];
	char * hint_HintNederlands[8];
	char	buffer_HintNederlands[851];
	char * msg_TabPortugues[8];
	int	trigger_TabPortugues;
	char * hint_TabPortugues[8];
	char * msg_Auto3592[8];
	char * hint_Auto3592[8];
	char * msg_Auto3593[8];
	char * hint_Auto3593[8];
	char * hint_Portugues[8];
	char	buffer_Portugues[851];
	char * hint_HintPortugues[8];
	char	buffer_HintPortugues[851];
	char * msg_TabOther[8];
	int	trigger_TabOther;
	char * hint_TabOther[8];
	char * msg_Auto3594[8];
	char * hint_Auto3594[8];
	char * msg_Auto3595[8];
	char * hint_Auto3595[8];
	char * hint_Other[8];
	char	buffer_Other[851];
	char * hint_HintOther[8];
	char	buffer_HintOther[851];
	char * msg_Auto3596[8];
	int	trigger_Auto3596;
	char * hint_Auto3596[8];
	char * msg_Reset[8];
	int	trigger_Reset;
	char * hint_Reset[8];
	char * msg_Copy[8];
	int	trigger_Copy;
	char * hint_Copy[8];
	char * msg_Auto3597[8];
	int	trigger_Auto3597;
	char * hint_Auto3597[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[17];
	};
static int	vfh[16];
private int on_Auto3596_event(struct accept_widget_messages_context * _Context);
private int on_Reset_event(struct accept_widget_messages_context * _Context);
private int on_Copy_event(struct accept_widget_messages_context * _Context);
private int on_Auto3597_event(struct accept_widget_messages_context * _Context);

public	int	accept_widget_messages_create(
	struct accept_widget_messages_context ** cptr,
	char * pEnglish,
	char * pHintEnglish,
	char * pFrancais,
	char * pHintFrancais,
	char * pItaliano,
	char * pHintItaliano,
	char * pEspagnol,
	char * pHintEspagnol,
	char * pDeutsch,
	char * pHintDeutsch,
	char * pNederlands,
	char * pHintNederlands,
	char * pPortugues,
	char * pHintPortugues,
	char * pOther,
	char * pHintOther)
{

	int i;
	struct accept_widget_messages_context * _Context=(struct accept_widget_messages_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_widget_messages_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=29;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSSSSSSSSSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_English, 850, pEnglish);
		visual_transferin(_Context->buffer_HintEnglish, 850, pHintEnglish);
		visual_transferin(_Context->buffer_Francais, 850, pFrancais);
		visual_transferin(_Context->buffer_HintFrancais, 850, pHintFrancais);
		visual_transferin(_Context->buffer_Italiano, 850, pItaliano);
		visual_transferin(_Context->buffer_HintItaliano, 850, pHintItaliano);
		visual_transferin(_Context->buffer_Espagnol, 850, pEspagnol);
		visual_transferin(_Context->buffer_HintEspagnol, 850, pHintEspagnol);
		visual_transferin(_Context->buffer_Deutsch, 850, pDeutsch);
		visual_transferin(_Context->buffer_HintDeutsch, 850, pHintDeutsch);
		visual_transferin(_Context->buffer_Nederlands, 850, pNederlands);
		visual_transferin(_Context->buffer_HintNederlands, 850, pHintNederlands);
		visual_transferin(_Context->buffer_Portugues, 850, pPortugues);
		visual_transferin(_Context->buffer_HintPortugues, 850, pHintPortugues);
		visual_transferin(_Context->buffer_Other, 850, pOther);
		visual_transferin(_Context->buffer_HintOther, 850, pHintOther);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3578[i]=" ";
	_Context->hint_Auto3578[0]=en__Auto3578;
	_Context->hint_Auto3578[1]=fr__Auto3578;
	_Context->hint_Auto3578[2]=it__Auto3578;
	_Context->hint_Auto3578[3]=es__Auto3578;
	_Context->hint_Auto3578[4]=de__Auto3578;
	_Context->hint_Auto3578[5]=nl__Auto3578;
	_Context->hint_Auto3578[6]=pt__Auto3578;
	_Context->hint_Auto3578[7]=xx__Auto3578;
	_Context->x_Auto3578=35;
	_Context->y_Auto3578=25;
	_Context->w_Auto3578=730;
	_Context->h_Auto3578=550;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3579[i]=" ";
	_Context->msg_Auto3579[0]=en_Auto3579;
	_Context->msg_Auto3579[1]=fr_Auto3579;
	_Context->msg_Auto3579[2]=it_Auto3579;
	_Context->msg_Auto3579[3]=es_Auto3579;
	_Context->msg_Auto3579[4]=de_Auto3579;
	_Context->msg_Auto3579[5]=nl_Auto3579;
	_Context->msg_Auto3579[6]=pt_Auto3579;
	_Context->msg_Auto3579[7]=xx_Auto3579;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3580[i]=" ";
	_Context->msg_Auto3580[0]=en_Auto3580;
	_Context->msg_Auto3580[1]=fr_Auto3580;
	_Context->msg_Auto3580[2]=it_Auto3580;
	_Context->msg_Auto3580[3]=es_Auto3580;
	_Context->msg_Auto3580[4]=de_Auto3580;
	_Context->msg_Auto3580[5]=nl_Auto3580;
	_Context->msg_Auto3580[6]=pt_Auto3580;
	_Context->msg_Auto3580[7]=xx_Auto3580;
	_Context->hint_Auto3580[0]=en__Auto3580;
	for (i=0; i < 8; i++)_Context->msg_Auto3581[i]=" ";
	_Context->msg_Auto3581[0]=en_Auto3581;
	_Context->msg_Auto3581[1]=fr_Auto3581;
	_Context->msg_Auto3581[2]=it_Auto3581;
	_Context->msg_Auto3581[3]=es_Auto3581;
	_Context->msg_Auto3581[4]=de_Auto3581;
	_Context->msg_Auto3581[5]=nl_Auto3581;
	_Context->msg_Auto3581[6]=pt_Auto3581;
	_Context->msg_Auto3581[7]=xx_Auto3581;
	_Context->hint_Auto3581[0]=en__Auto3581;
	_Context->hint_HintEnglish[0]=en__HintEnglish;
	for (i=0; i < 8; i++)_Context->msg_TabFrancais[i]=" ";
	_Context->msg_TabFrancais[0]=en_TabFrancais;
	_Context->msg_TabFrancais[1]=fr_TabFrancais;
	_Context->msg_TabFrancais[2]=it_TabFrancais;
	_Context->msg_TabFrancais[3]=es_TabFrancais;
	_Context->msg_TabFrancais[4]=de_TabFrancais;
	_Context->msg_TabFrancais[5]=nl_TabFrancais;
	_Context->msg_TabFrancais[6]=pt_TabFrancais;
	_Context->msg_TabFrancais[7]=xx_TabFrancais;
	_Context->focus_pages[2]=5;
	for (i=0; i < 8; i++)_Context->msg_Auto3582[i]=" ";
	_Context->msg_Auto3582[0]=en_Auto3582;
	_Context->msg_Auto3582[1]=fr_Auto3582;
	_Context->msg_Auto3582[2]=it_Auto3582;
	_Context->msg_Auto3582[3]=es_Auto3582;
	_Context->msg_Auto3582[4]=de_Auto3582;
	_Context->msg_Auto3582[5]=nl_Auto3582;
	_Context->msg_Auto3582[6]=pt_Auto3582;
	_Context->msg_Auto3582[7]=xx_Auto3582;
	_Context->hint_Auto3582[0]=en__Auto3582;
	for (i=0; i < 8; i++)_Context->msg_Auto3583[i]=" ";
	_Context->msg_Auto3583[0]=en_Auto3583;
	_Context->msg_Auto3583[1]=fr_Auto3583;
	_Context->msg_Auto3583[2]=it_Auto3583;
	_Context->msg_Auto3583[3]=es_Auto3583;
	_Context->msg_Auto3583[4]=de_Auto3583;
	_Context->msg_Auto3583[5]=nl_Auto3583;
	_Context->msg_Auto3583[6]=pt_Auto3583;
	_Context->msg_Auto3583[7]=xx_Auto3583;
	_Context->hint_Auto3583[0]=en__Auto3583;
	_Context->hint_HintFrancais[0]=en__HintFrancais;
	for (i=0; i < 8; i++)_Context->msg_TabItaliano[i]=" ";
	_Context->msg_TabItaliano[0]=en_TabItaliano;
	_Context->msg_TabItaliano[1]=fr_TabItaliano;
	_Context->msg_TabItaliano[2]=it_TabItaliano;
	_Context->msg_TabItaliano[3]=es_TabItaliano;
	_Context->msg_TabItaliano[4]=de_TabItaliano;
	_Context->msg_TabItaliano[5]=nl_TabItaliano;
	_Context->msg_TabItaliano[6]=pt_TabItaliano;
	_Context->msg_TabItaliano[7]=xx_TabItaliano;
	_Context->focus_pages[3]=8;
	for (i=0; i < 8; i++)_Context->msg_Auto3584[i]=" ";
	_Context->msg_Auto3584[0]=en_Auto3584;
	_Context->msg_Auto3584[1]=fr_Auto3584;
	_Context->msg_Auto3584[2]=it_Auto3584;
	_Context->msg_Auto3584[3]=es_Auto3584;
	_Context->msg_Auto3584[4]=de_Auto3584;
	_Context->msg_Auto3584[5]=nl_Auto3584;
	_Context->msg_Auto3584[6]=pt_Auto3584;
	_Context->msg_Auto3584[7]=xx_Auto3584;
	_Context->hint_Auto3584[0]=en__Auto3584;
	for (i=0; i < 8; i++)_Context->msg_Auto3585[i]=" ";
	_Context->msg_Auto3585[0]=en_Auto3585;
	_Context->msg_Auto3585[1]=fr_Auto3585;
	_Context->msg_Auto3585[2]=it_Auto3585;
	_Context->msg_Auto3585[3]=es_Auto3585;
	_Context->msg_Auto3585[4]=de_Auto3585;
	_Context->msg_Auto3585[5]=nl_Auto3585;
	_Context->msg_Auto3585[6]=pt_Auto3585;
	_Context->msg_Auto3585[7]=xx_Auto3585;
	_Context->hint_Auto3585[0]=en__Auto3585;
	_Context->hint_HintItaliano[0]=en__HintItaliano;
	for (i=0; i < 8; i++)_Context->msg_TabEspagnol[i]=" ";
	_Context->msg_TabEspagnol[0]=en_TabEspagnol;
	_Context->msg_TabEspagnol[1]=fr_TabEspagnol;
	_Context->msg_TabEspagnol[2]=it_TabEspagnol;
	_Context->msg_TabEspagnol[3]=es_TabEspagnol;
	_Context->msg_TabEspagnol[4]=de_TabEspagnol;
	_Context->msg_TabEspagnol[5]=nl_TabEspagnol;
	_Context->msg_TabEspagnol[6]=pt_TabEspagnol;
	_Context->msg_TabEspagnol[7]=xx_TabEspagnol;
	_Context->focus_pages[4]=11;
	_Context->hint_HintEspagnol[0]=en__HintEspagnol;
	for (i=0; i < 8; i++)_Context->msg_Auto3586[i]=" ";
	_Context->msg_Auto3586[0]=en_Auto3586;
	_Context->msg_Auto3586[1]=fr_Auto3586;
	_Context->msg_Auto3586[2]=it_Auto3586;
	_Context->msg_Auto3586[3]=es_Auto3586;
	_Context->msg_Auto3586[4]=de_Auto3586;
	_Context->msg_Auto3586[5]=nl_Auto3586;
	_Context->msg_Auto3586[6]=pt_Auto3586;
	_Context->msg_Auto3586[7]=xx_Auto3586;
	_Context->hint_Auto3586[0]=en__Auto3586;
	for (i=0; i < 8; i++)_Context->msg_Auto3587[i]=" ";
	_Context->msg_Auto3587[0]=en_Auto3587;
	_Context->msg_Auto3587[1]=fr_Auto3587;
	_Context->msg_Auto3587[2]=it_Auto3587;
	_Context->msg_Auto3587[3]=es_Auto3587;
	_Context->msg_Auto3587[4]=de_Auto3587;
	_Context->msg_Auto3587[5]=nl_Auto3587;
	_Context->msg_Auto3587[6]=pt_Auto3587;
	_Context->msg_Auto3587[7]=xx_Auto3587;
	_Context->hint_Auto3587[0]=en__Auto3587;
	for (i=0; i < 8; i++)_Context->msg_TabDeutsch[i]=" ";
	_Context->msg_TabDeutsch[0]=en_TabDeutsch;
	_Context->msg_TabDeutsch[1]=fr_TabDeutsch;
	_Context->msg_TabDeutsch[2]=it_TabDeutsch;
	_Context->msg_TabDeutsch[3]=es_TabDeutsch;
	_Context->msg_TabDeutsch[4]=de_TabDeutsch;
	_Context->msg_TabDeutsch[5]=nl_TabDeutsch;
	_Context->msg_TabDeutsch[6]=pt_TabDeutsch;
	_Context->msg_TabDeutsch[7]=xx_TabDeutsch;
	_Context->focus_pages[5]=14;
	for (i=0; i < 8; i++)_Context->msg_Auto3588[i]=" ";
	_Context->msg_Auto3588[0]=en_Auto3588;
	_Context->msg_Auto3588[1]=fr_Auto3588;
	_Context->msg_Auto3588[2]=it_Auto3588;
	_Context->msg_Auto3588[3]=es_Auto3588;
	_Context->msg_Auto3588[4]=de_Auto3588;
	_Context->msg_Auto3588[5]=nl_Auto3588;
	_Context->msg_Auto3588[6]=pt_Auto3588;
	_Context->msg_Auto3588[7]=xx_Auto3588;
	_Context->hint_Auto3588[0]=en__Auto3588;
	for (i=0; i < 8; i++)_Context->msg_Auto3589[i]=" ";
	_Context->msg_Auto3589[0]=en_Auto3589;
	_Context->msg_Auto3589[1]=fr_Auto3589;
	_Context->msg_Auto3589[2]=it_Auto3589;
	_Context->msg_Auto3589[3]=es_Auto3589;
	_Context->msg_Auto3589[4]=de_Auto3589;
	_Context->msg_Auto3589[5]=nl_Auto3589;
	_Context->msg_Auto3589[6]=pt_Auto3589;
	_Context->msg_Auto3589[7]=xx_Auto3589;
	_Context->hint_Auto3589[0]=en__Auto3589;
	_Context->hint_HintDeutsch[0]=en__HintDeutsch;
	for (i=0; i < 8; i++)_Context->msg_TabNederlands[i]=" ";
	_Context->msg_TabNederlands[0]=en_TabNederlands;
	_Context->msg_TabNederlands[1]=fr_TabNederlands;
	_Context->msg_TabNederlands[2]=it_TabNederlands;
	_Context->msg_TabNederlands[3]=es_TabNederlands;
	_Context->msg_TabNederlands[4]=de_TabNederlands;
	_Context->msg_TabNederlands[5]=nl_TabNederlands;
	_Context->msg_TabNederlands[6]=pt_TabNederlands;
	_Context->msg_TabNederlands[7]=xx_TabNederlands;
	_Context->focus_pages[6]=17;
	for (i=0; i < 8; i++)_Context->msg_Auto3590[i]=" ";
	_Context->msg_Auto3590[0]=en_Auto3590;
	_Context->msg_Auto3590[1]=fr_Auto3590;
	_Context->msg_Auto3590[2]=it_Auto3590;
	_Context->msg_Auto3590[3]=es_Auto3590;
	_Context->msg_Auto3590[4]=de_Auto3590;
	_Context->msg_Auto3590[5]=nl_Auto3590;
	_Context->msg_Auto3590[6]=pt_Auto3590;
	_Context->msg_Auto3590[7]=xx_Auto3590;
	_Context->hint_Auto3590[0]=en__Auto3590;
	for (i=0; i < 8; i++)_Context->msg_Auto3591[i]=" ";
	_Context->msg_Auto3591[0]=en_Auto3591;
	_Context->msg_Auto3591[1]=fr_Auto3591;
	_Context->msg_Auto3591[2]=it_Auto3591;
	_Context->msg_Auto3591[3]=es_Auto3591;
	_Context->msg_Auto3591[4]=de_Auto3591;
	_Context->msg_Auto3591[5]=nl_Auto3591;
	_Context->msg_Auto3591[6]=pt_Auto3591;
	_Context->msg_Auto3591[7]=xx_Auto3591;
	_Context->hint_Auto3591[0]=en__Auto3591;
	_Context->hint_HintNederlands[0]=en__HintNederlands;
	for (i=0; i < 8; i++)_Context->msg_TabPortugues[i]=" ";
	_Context->msg_TabPortugues[0]=en_TabPortugues;
	_Context->msg_TabPortugues[1]=fr_TabPortugues;
	_Context->msg_TabPortugues[2]=it_TabPortugues;
	_Context->msg_TabPortugues[3]=es_TabPortugues;
	_Context->msg_TabPortugues[4]=de_TabPortugues;
	_Context->msg_TabPortugues[5]=nl_TabPortugues;
	_Context->msg_TabPortugues[6]=pt_TabPortugues;
	_Context->msg_TabPortugues[7]=xx_TabPortugues;
	_Context->focus_pages[7]=20;
	for (i=0; i < 8; i++)_Context->msg_Auto3592[i]=" ";
	_Context->msg_Auto3592[0]=en_Auto3592;
	_Context->msg_Auto3592[1]=fr_Auto3592;
	_Context->msg_Auto3592[2]=it_Auto3592;
	_Context->msg_Auto3592[3]=es_Auto3592;
	_Context->msg_Auto3592[4]=de_Auto3592;
	_Context->msg_Auto3592[5]=nl_Auto3592;
	_Context->msg_Auto3592[6]=pt_Auto3592;
	_Context->msg_Auto3592[7]=xx_Auto3592;
	_Context->hint_Auto3592[0]=en__Auto3592;
	for (i=0; i < 8; i++)_Context->msg_Auto3593[i]=" ";
	_Context->msg_Auto3593[0]=en_Auto3593;
	_Context->msg_Auto3593[1]=fr_Auto3593;
	_Context->msg_Auto3593[2]=it_Auto3593;
	_Context->msg_Auto3593[3]=es_Auto3593;
	_Context->msg_Auto3593[4]=de_Auto3593;
	_Context->msg_Auto3593[5]=nl_Auto3593;
	_Context->msg_Auto3593[6]=pt_Auto3593;
	_Context->msg_Auto3593[7]=xx_Auto3593;
	_Context->hint_Auto3593[0]=en__Auto3593;
	_Context->hint_HintPortugues[0]=en__HintPortugues;
	for (i=0; i < 8; i++)_Context->msg_TabOther[i]=" ";
	_Context->msg_TabOther[0]=en_TabOther;
	_Context->msg_TabOther[1]=fr_TabOther;
	_Context->msg_TabOther[2]=it_TabOther;
	_Context->msg_TabOther[3]=es_TabOther;
	_Context->msg_TabOther[4]=de_TabOther;
	_Context->msg_TabOther[5]=nl_TabOther;
	_Context->msg_TabOther[6]=pt_TabOther;
	_Context->msg_TabOther[7]=xx_TabOther;
	_Context->focus_pages[8]=23;
	for (i=0; i < 8; i++)_Context->msg_Auto3594[i]=" ";
	_Context->msg_Auto3594[0]=en_Auto3594;
	_Context->msg_Auto3594[1]=fr_Auto3594;
	_Context->msg_Auto3594[2]=it_Auto3594;
	_Context->msg_Auto3594[3]=es_Auto3594;
	_Context->msg_Auto3594[4]=de_Auto3594;
	_Context->msg_Auto3594[5]=nl_Auto3594;
	_Context->msg_Auto3594[6]=pt_Auto3594;
	_Context->msg_Auto3594[7]=xx_Auto3594;
	_Context->hint_Auto3594[0]=en__Auto3594;
	for (i=0; i < 8; i++)_Context->msg_Auto3595[i]=" ";
	_Context->msg_Auto3595[0]=en_Auto3595;
	_Context->msg_Auto3595[1]=fr_Auto3595;
	_Context->msg_Auto3595[2]=it_Auto3595;
	_Context->msg_Auto3595[3]=es_Auto3595;
	_Context->msg_Auto3595[4]=de_Auto3595;
	_Context->msg_Auto3595[5]=nl_Auto3595;
	_Context->msg_Auto3595[6]=pt_Auto3595;
	_Context->msg_Auto3595[7]=xx_Auto3595;
	_Context->hint_Auto3595[0]=en__Auto3595;
	_Context->hint_HintOther[0]=en__HintOther;
	for (i=0; i < 8; i++)_Context->msg_Auto3596[i]=" ";
	_Context->msg_Auto3596[0]=en_Auto3596;
	_Context->msg_Auto3596[1]=fr_Auto3596;
	_Context->msg_Auto3596[2]=it_Auto3596;
	_Context->msg_Auto3596[3]=es_Auto3596;
	_Context->msg_Auto3596[4]=de_Auto3596;
	_Context->msg_Auto3596[5]=nl_Auto3596;
	_Context->msg_Auto3596[6]=pt_Auto3596;
	_Context->msg_Auto3596[7]=xx_Auto3596;
	for (i=0; i < 8; i++)_Context->msg_Reset[i]=" ";
	_Context->msg_Reset[0]=en_Reset;
	_Context->msg_Reset[1]=fr_Reset;
	_Context->msg_Reset[2]=it_Reset;
	_Context->msg_Reset[3]=es_Reset;
	_Context->msg_Reset[4]=de_Reset;
	_Context->msg_Reset[5]=nl_Reset;
	_Context->msg_Reset[6]=pt_Reset;
	_Context->msg_Reset[7]=xx_Reset;
	_Context->hint_Reset[0]=en__Reset;
	for (i=0; i < 8; i++)_Context->msg_Copy[i]=" ";
	_Context->msg_Copy[0]=en_Copy;
	_Context->msg_Copy[1]=fr_Copy;
	_Context->msg_Copy[2]=it_Copy;
	_Context->msg_Copy[3]=es_Copy;
	_Context->msg_Copy[4]=de_Copy;
	_Context->msg_Copy[5]=nl_Copy;
	_Context->msg_Copy[6]=pt_Copy;
	_Context->msg_Copy[7]=xx_Copy;
	_Context->hint_Copy[0]=en__Copy;
	for (i=0; i < 8; i++)_Context->msg_Auto3597[i]=" ";
	_Context->msg_Auto3597[0]=en_Auto3597;
	_Context->msg_Auto3597[1]=fr_Auto3597;
	_Context->msg_Auto3597[2]=it_Auto3597;
	_Context->msg_Auto3597[3]=es_Auto3597;
	_Context->msg_Auto3597[4]=de_Auto3597;
	_Context->msg_Auto3597[5]=nl_Auto3597;
	_Context->msg_Auto3597[6]=pt_Auto3597;
	_Context->msg_Auto3597[7]=xx_Auto3597;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3578,_Context->y_Auto3578,730+10,550+10);
	return(0);
}

public 	int	accept_widget_messages_hide(struct accept_widget_messages_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3578,_Context->y_Auto3578);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_widget_messages_remove(
	struct accept_widget_messages_context * _Context,
	char * pEnglish,
	char * pHintEnglish,
	char * pFrancais,
	char * pHintFrancais,
	char * pItaliano,
	char * pHintItaliano,
	char * pEspagnol,
	char * pHintEspagnol,
	char * pDeutsch,
	char * pHintDeutsch,
	char * pNederlands,
	char * pHintNederlands,
	char * pPortugues,
	char * pHintPortugues,
	char * pOther,
	char * pHintOther)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSSSSSSSSSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_English, 850, pEnglish);
		visual_transferout(_Context->buffer_HintEnglish, 850, pHintEnglish);
		visual_transferout(_Context->buffer_Francais, 850, pFrancais);
		visual_transferout(_Context->buffer_HintFrancais, 850, pHintFrancais);
		visual_transferout(_Context->buffer_Italiano, 850, pItaliano);
		visual_transferout(_Context->buffer_HintItaliano, 850, pHintItaliano);
		visual_transferout(_Context->buffer_Espagnol, 850, pEspagnol);
		visual_transferout(_Context->buffer_HintEspagnol, 850, pHintEspagnol);
		visual_transferout(_Context->buffer_Deutsch, 850, pDeutsch);
		visual_transferout(_Context->buffer_HintDeutsch, 850, pHintDeutsch);
		visual_transferout(_Context->buffer_Nederlands, 850, pNederlands);
		visual_transferout(_Context->buffer_HintNederlands, 850, pHintNederlands);
		visual_transferout(_Context->buffer_Portugues, 850, pPortugues);
		visual_transferout(_Context->buffer_HintPortugues, 850, pHintPortugues);
		visual_transferout(_Context->buffer_Other, 850, pOther);
		visual_transferout(_Context->buffer_HintOther, 850, pHintOther);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_widget_messages_show(struct accept_widget_messages_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3578,_Context->y_Auto3578);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3578,_Context->y_Auto3578,730,550,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3578,_Context->y_Auto3578,730,550,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto3578+20,_Context->y_Auto3578+30,700,22,vfh[4],16,0,_Context->msg_Auto3579[_Context->language],strlen(_Context->msg_Auto3579[_Context->language]),1283);
	if (_Context->page_number == 1 ) {
	_Context->trigger_TabEnglish=visual_trigger_code(_Context->msg_TabEnglish[_Context->language],strlen(_Context->msg_TabEnglish[_Context->language]));
	visual_tabpage(_Context->x_Auto3578+10,_Context->y_Auto3578+50,710,430,vfh[2],_Context->msg_TabEnglish[_Context->language],strlen(_Context->msg_TabEnglish[_Context->language]),0,34);
	} else {
		visual_tabpage(_Context->x_Auto3578+10,_Context->y_Auto3578+50,710,430,vfh[2],_Context->msg_TabEnglish[_Context->language],strlen(_Context->msg_TabEnglish[_Context->language]),0,32);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3578+20,_Context->y_Auto3578+90,140,16,vfh[2],16,0,_Context->msg_Auto3580[_Context->language],strlen(_Context->msg_Auto3580[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3578+20,_Context->y_Auto3578+280,140,16,vfh[2],16,0,_Context->msg_Auto3581[_Context->language],strlen(_Context->msg_Auto3581[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3578+20,_Context->y_Auto3578+110,680+2,160+2,5);
	visual_text(_Context->x_Auto3578+20+1,_Context->y_Auto3578+110+1,680,160,vfh[1],27,28,_Context->buffer_English,850,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3578+20,_Context->y_Auto3578+300,680+2,160+2,5);
	visual_text(_Context->x_Auto3578+20+1,_Context->y_Auto3578+300+1,680,160,vfh[1],27,28,_Context->buffer_HintEnglish,850,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_TabFrancais=visual_trigger_code(_Context->msg_TabFrancais[_Context->language],strlen(_Context->msg_TabFrancais[_Context->language]));
	visual_tabpage(_Context->x_Auto3578+10,_Context->y_Auto3578+50,710,430,vfh[2],_Context->msg_TabFrancais[_Context->language],strlen(_Context->msg_TabFrancais[_Context->language]),81,34);
	} else {
		visual_tabpage(_Context->x_Auto3578+10,_Context->y_Auto3578+50,710,430,vfh[2],_Context->msg_TabFrancais[_Context->language],strlen(_Context->msg_TabFrancais[_Context->language]),81,32);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3578+20,_Context->y_Auto3578+90,140,16,vfh[2],16,0,_Context->msg_Auto3582[_Context->language],strlen(_Context->msg_Auto3582[_Context->language]),258);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3578+20,_Context->y_Auto3578+280,140,16,vfh[2],16,0,_Context->msg_Auto3583[_Context->language],strlen(_Context->msg_Auto3583[_Context->language]),258);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3578+20,_Context->y_Auto3578+110,680+2,160+2,5);
	visual_text(_Context->x_Auto3578+20+1,_Context->y_Auto3578+110+1,680,160,vfh[1],16,0,_Context->buffer_Francais,850,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3578+20,_Context->y_Auto3578+300,680+2,160+2,5);
	visual_text(_Context->x_Auto3578+20+1,_Context->y_Auto3578+300+1,680,160,vfh[1],16,0,_Context->buffer_HintFrancais,850,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_TabItaliano=visual_trigger_code(_Context->msg_TabItaliano[_Context->language],strlen(_Context->msg_TabItaliano[_Context->language]));
	visual_tabpage(_Context->x_Auto3578+10,_Context->y_Auto3578+50,710,430,vfh[2],_Context->msg_TabItaliano[_Context->language],strlen(_Context->msg_TabItaliano[_Context->language]),170,34);
	} else {
		visual_tabpage(_Context->x_Auto3578+10,_Context->y_Auto3578+50,710,430,vfh[2],_Context->msg_TabItaliano[_Context->language],strlen(_Context->msg_TabItaliano[_Context->language]),170,32);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3578+20,_Context->y_Auto3578+90,140,16,vfh[2],16,0,_Context->msg_Auto3584[_Context->language],strlen(_Context->msg_Auto3584[_Context->language]),258);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3578+20,_Context->y_Auto3578+280,140,16,vfh[2],16,0,_Context->msg_Auto3585[_Context->language],strlen(_Context->msg_Auto3585[_Context->language]),258);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3578+20,_Context->y_Auto3578+110,680+2,160+2,5);
	visual_text(_Context->x_Auto3578+20+1,_Context->y_Auto3578+110+1,680,160,vfh[1],16,0,_Context->buffer_Italiano,850,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3578+20,_Context->y_Auto3578+300,680+2,160+2,5);
	visual_text(_Context->x_Auto3578+20+1,_Context->y_Auto3578+300+1,680,160,vfh[1],16,0,_Context->buffer_HintItaliano,850,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_TabEspagnol=visual_trigger_code(_Context->msg_TabEspagnol[_Context->language],strlen(_Context->msg_TabEspagnol[_Context->language]));
	visual_tabpage(_Context->x_Auto3578+10,_Context->y_Auto3578+50,710,430,vfh[2],_Context->msg_TabEspagnol[_Context->language],strlen(_Context->msg_TabEspagnol[_Context->language]),250,34);
	} else {
		visual_tabpage(_Context->x_Auto3578+10,_Context->y_Auto3578+50,710,430,vfh[2],_Context->msg_TabEspagnol[_Context->language],strlen(_Context->msg_TabEspagnol[_Context->language]),250,32);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3578+20,_Context->y_Auto3578+110,680+2,160+2,5);
	visual_text(_Context->x_Auto3578+20+1,_Context->y_Auto3578+110+1,680,160,vfh[1],16,0,_Context->buffer_Espagnol,850,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3578+20,_Context->y_Auto3578+300,680+2,160+2,5);
	visual_text(_Context->x_Auto3578+20+1,_Context->y_Auto3578+300+1,680,160,vfh[1],16,0,_Context->buffer_HintEspagnol,850,0);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto3578+20,_Context->y_Auto3578+90,140,16,vfh[2],16,0,_Context->msg_Auto3586[_Context->language],strlen(_Context->msg_Auto3586[_Context->language]),258);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto3578+20,_Context->y_Auto3578+280,140,16,vfh[2],16,0,_Context->msg_Auto3587[_Context->language],strlen(_Context->msg_Auto3587[_Context->language]),258);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_TabDeutsch=visual_trigger_code(_Context->msg_TabDeutsch[_Context->language],strlen(_Context->msg_TabDeutsch[_Context->language]));
	visual_tabpage(_Context->x_Auto3578+10,_Context->y_Auto3578+50,710,430,vfh[2],_Context->msg_TabDeutsch[_Context->language],strlen(_Context->msg_TabDeutsch[_Context->language]),342,34);
	} else {
		visual_tabpage(_Context->x_Auto3578+10,_Context->y_Auto3578+50,710,430,vfh[2],_Context->msg_TabDeutsch[_Context->language],strlen(_Context->msg_TabDeutsch[_Context->language]),342,32);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto3578+20,_Context->y_Auto3578+90,140,16,vfh[2],16,0,_Context->msg_Auto3588[_Context->language],strlen(_Context->msg_Auto3588[_Context->language]),258);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto3578+20,_Context->y_Auto3578+280,140,16,vfh[2],16,0,_Context->msg_Auto3589[_Context->language],strlen(_Context->msg_Auto3589[_Context->language]),258);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto3578+20,_Context->y_Auto3578+110,680+2,160+2,5);
	visual_text(_Context->x_Auto3578+20+1,_Context->y_Auto3578+110+1,680,160,vfh[1],16,0,_Context->buffer_Deutsch,850,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto3578+20,_Context->y_Auto3578+300,680+2,160+2,5);
	visual_text(_Context->x_Auto3578+20+1,_Context->y_Auto3578+300+1,680,160,vfh[1],16,0,_Context->buffer_HintDeutsch,850,0);
		}
	if (_Context->page_number == 6 ) {
	_Context->trigger_TabNederlands=visual_trigger_code(_Context->msg_TabNederlands[_Context->language],strlen(_Context->msg_TabNederlands[_Context->language]));
	visual_tabpage(_Context->x_Auto3578+10,_Context->y_Auto3578+50,710,430,vfh[2],_Context->msg_TabNederlands[_Context->language],strlen(_Context->msg_TabNederlands[_Context->language]),429,34);
	} else {
		visual_tabpage(_Context->x_Auto3578+10,_Context->y_Auto3578+50,710,430,vfh[2],_Context->msg_TabNederlands[_Context->language],strlen(_Context->msg_TabNederlands[_Context->language]),429,32);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3578+20,_Context->y_Auto3578+90,140,16,vfh[2],16,0,_Context->msg_Auto3590[_Context->language],strlen(_Context->msg_Auto3590[_Context->language]),258);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3578+20,_Context->y_Auto3578+280,140,16,vfh[2],16,0,_Context->msg_Auto3591[_Context->language],strlen(_Context->msg_Auto3591[_Context->language]),258);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto3578+20,_Context->y_Auto3578+110,680+2,160+2,5);
	visual_text(_Context->x_Auto3578+20+1,_Context->y_Auto3578+110+1,680,160,vfh[1],16,0,_Context->buffer_Nederlands,850,0);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto3578+20,_Context->y_Auto3578+300,680+2,160+2,5);
	visual_text(_Context->x_Auto3578+20+1,_Context->y_Auto3578+300+1,680,160,vfh[1],16,0,_Context->buffer_HintNederlands,850,0);
		}
	if (_Context->page_number == 7 ) {
	_Context->trigger_TabPortugues=visual_trigger_code(_Context->msg_TabPortugues[_Context->language],strlen(_Context->msg_TabPortugues[_Context->language]));
	visual_tabpage(_Context->x_Auto3578+10,_Context->y_Auto3578+50,710,430,vfh[2],_Context->msg_TabPortugues[_Context->language],strlen(_Context->msg_TabPortugues[_Context->language]),533,34);
	} else {
		visual_tabpage(_Context->x_Auto3578+10,_Context->y_Auto3578+50,710,430,vfh[2],_Context->msg_TabPortugues[_Context->language],strlen(_Context->msg_TabPortugues[_Context->language]),533,32);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3578+20,_Context->y_Auto3578+90,140,16,vfh[2],16,0,_Context->msg_Auto3592[_Context->language],strlen(_Context->msg_Auto3592[_Context->language]),258);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3578+20,_Context->y_Auto3578+280,140,16,vfh[2],16,0,_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]),258);
		}
	if (_Context->page_number == 7 ) {
	visual_frame(_Context->x_Auto3578+20,_Context->y_Auto3578+110,680+2,160+2,5);
	visual_text(_Context->x_Auto3578+20+1,_Context->y_Auto3578+110+1,680,160,vfh[1],16,0,_Context->buffer_Portugues,850,0);
		}
	if (_Context->page_number == 7 ) {
	visual_frame(_Context->x_Auto3578+20,_Context->y_Auto3578+300,680+2,160+2,5);
	visual_text(_Context->x_Auto3578+20+1,_Context->y_Auto3578+300+1,680,160,vfh[1],16,0,_Context->buffer_HintPortugues,850,0);
		}
	if (_Context->page_number == 8 ) {
	_Context->trigger_TabOther=visual_trigger_code(_Context->msg_TabOther[_Context->language],strlen(_Context->msg_TabOther[_Context->language]));
	visual_tabpage(_Context->x_Auto3578+10,_Context->y_Auto3578+50,710,430,vfh[2],_Context->msg_TabOther[_Context->language],strlen(_Context->msg_TabOther[_Context->language]),632,34);
	} else {
		visual_tabpage(_Context->x_Auto3578+10,_Context->y_Auto3578+50,710,430,vfh[2],_Context->msg_TabOther[_Context->language],strlen(_Context->msg_TabOther[_Context->language]),632,32);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto3578+20,_Context->y_Auto3578+90,140,16,vfh[2],16,0,_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]),258);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto3578+20,_Context->y_Auto3578+280,140,16,vfh[2],16,0,_Context->msg_Auto3595[_Context->language],strlen(_Context->msg_Auto3595[_Context->language]),258);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(_Context->x_Auto3578+20,_Context->y_Auto3578+110,680+2,160+2,5);
	visual_text(_Context->x_Auto3578+20+1,_Context->y_Auto3578+110+1,680,160,vfh[1],16,0,_Context->buffer_Other,850,0);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(_Context->x_Auto3578+20,_Context->y_Auto3578+300,680+2,160+2,5);
	visual_text(_Context->x_Auto3578+20+1,_Context->y_Auto3578+300+1,680,160,vfh[1],16,0,_Context->buffer_HintOther,850,0);
		}
	_Context->trigger_Auto3596=visual_trigger_code(_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]));
	visual_button(_Context->x_Auto3578+10,_Context->y_Auto3578+490,56,48,vfh[2],34,0,_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]),1040);
	_Context->trigger_Reset=visual_trigger_code(_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]));
	visual_button(_Context->x_Auto3578+380,_Context->y_Auto3578+490,136,32,vfh[2],0,0,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),0);
	_Context->trigger_Copy=visual_trigger_code(_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]));
	visual_button(_Context->x_Auto3578+220,_Context->y_Auto3578+490,136,32,vfh[2],0,0,_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]),0);
	_Context->trigger_Auto3597=visual_trigger_code(_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]));
	visual_button(_Context->x_Auto3578+660,_Context->y_Auto3578+490,56,48,vfh[2],34,0,_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3578,_Context->y_Auto3578,730,550);

	return(0);
}

private int TabEnglish_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Each of the tab pages allows data input of text or expressions for ";
			mptr[1]="the payload values and hints of their parent widgts.   ";
			return(visual_online_help(mptr,2));
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
			mptr[0] = "Specify the string or expression to use as the payload when the english ";
			mptr[1]="language has been selected.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int HintEnglish_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Specify the string or expression to use as the hint when the english ";
			mptr[1]="language has been selected.   ";
			return(visual_online_help(mptr,2));
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
			mptr[0] = "Specify the string or expression to use as the payload when the french ";
			mptr[1]=" language has been selected.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int HintFrancais_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Specify the string or expression to use as the hint when the french ";
			mptr[1]=" language has been selected.   ";
			return(visual_online_help(mptr,2));
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
			mptr[0] = "Specify the string or expression to use as the payload when the italian ";
			mptr[1]=" language has been selected.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int HintItaliano_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Specify the string or expression to use as the hint  when the italien ";
			mptr[1]="language has been selected.    ";
			return(visual_online_help(mptr,2));
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
			mptr[0] = "Specify the string or expression to use as the payload when the spanish ";
			mptr[1]="language has been selected.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int HintEspagnol_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Specify the string or expression to use as the hint  when the spanish ";
			mptr[1]="language has been selected.   ";
			return(visual_online_help(mptr,2));
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
			mptr[0] = "Specify the string or expression to use as the payload when the german ";
			mptr[1]="language has been selected.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int HintDeutsch_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Specify the string or expression to use as the hint  when the german ";
			mptr[1]="language has been selected.   ";
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
			mptr[0] = "Specify the string or expression to use as the payload when the dutch ";
			mptr[1]=" language has been selected.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int HintNederlands_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Specify the string or expression to use as the hint  when the dutch ";
			mptr[1]="language has been selected.   ";
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
			mptr[0] = "Specify the string or expression to use as the payload when the portugese ";
			mptr[1]="language has been selected.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int HintPortugues_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Specify the string or expression to use as the hint  when the portugese ";
			mptr[1]="language has been selected.   ";
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
			mptr[0] = "Specify the string or expression to use as the payload when the alternative ";
			mptr[1]=" language has been selected.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int HintOther_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Specify the string or expression to use as the hint when the alternative ";
			mptr[1]=" language has been selected.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3596_help()
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

private int Reset_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This push button will reset, to space, all national message texts ";
			mptr[1]="other than  the left most english version.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Copy_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This push button will copy the left most, english version, message ";
			mptr[1]="text into all blank national components.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3597_help()
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

private int Auto3578action(struct accept_widget_messages_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_widget_messages_hide(_Context);

		_Context->x_Auto3578 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3578 < 0) { _Context->x_Auto3578=0; }
		_Context->y_Auto3578 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3578 < 0) { _Context->y_Auto3578=0; }
			accept_widget_messages_show(_Context);

		visual_thaw(_Context->x_Auto3578,_Context->y_Auto3578,730,550);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3596_event(struct accept_widget_messages_context * _Context) {
	return(13);
	return(-1);
}
private int on_Reset_event(struct accept_widget_messages_context * _Context) {
	memset(_Context->buffer_Francais,32,850);
	memset(_Context->buffer_Italiano,32,850);
	memset(_Context->buffer_Espagnol,32,850);
	memset(_Context->buffer_Deutsch,32,850);
	memset(_Context->buffer_Nederlands,32,850);
	memset(_Context->buffer_Portugues,32,850);
	memset(_Context->buffer_Other,32,850);
	memset(_Context->buffer_HintFrancais,32,850);
	memset(_Context->buffer_HintItaliano,32,850);
	memset(_Context->buffer_HintEspagnol,32,850);
	memset(_Context->buffer_HintDeutsch,32,850);
	memset(_Context->buffer_HintNederlands,32,850);
	memset(_Context->buffer_HintPortugues,32,850);
	memset(_Context->buffer_HintOther,32,850);
		accept_widget_messages_show(_Context);
;
	return(-1);
}
private int on_Copy_event(struct accept_widget_messages_context * _Context) {
	if(_Context->buffer_Francais[0]==' '){
	memcpy(_Context->buffer_Francais,_Context->buffer_English,850);
	}
	if(_Context->buffer_Italiano[0]==' '){
	memcpy(_Context->buffer_Italiano,_Context->buffer_English,850);
	}
	if(_Context->buffer_Espagnol[0]==' '){
	memcpy(_Context->buffer_Espagnol,_Context->buffer_English,850);
	}
	if(_Context->buffer_Deutsch[0]==' '){
	memcpy(_Context->buffer_Deutsch,_Context->buffer_English,850);
	}
	if(_Context->buffer_Nederlands[0]==' '){
	memcpy(_Context->buffer_Nederlands,_Context->buffer_English,850);
	}
	if(_Context->buffer_Portugues[0]==' '){
	memcpy(_Context->buffer_Portugues,_Context->buffer_English,850);
	}
	if(_Context->buffer_Other[0]==' '){
	memcpy(_Context->buffer_Other,_Context->buffer_English,850);
	}
	if(_Context->buffer_HintFrancais[0]==' '){
	memcpy(_Context->buffer_HintFrancais,_Context->buffer_HintEnglish,850);
	}
	if(_Context->buffer_HintItaliano[0]==' '){
	memcpy(_Context->buffer_HintItaliano,_Context->buffer_HintEnglish,850);
	}
	if(_Context->buffer_HintEspagnol[0]==' '){
	memcpy(_Context->buffer_HintEspagnol,_Context->buffer_HintEnglish,850);
	}
	if(_Context->buffer_HintDeutsch[0]==' '){
	memcpy(_Context->buffer_HintDeutsch,_Context->buffer_HintEnglish,850);
	}
	if(_Context->buffer_HintNederlands[0]==' '){
	memcpy(_Context->buffer_HintNederlands,_Context->buffer_HintEnglish,850);
	}
	if(_Context->buffer_HintPortugues[0]==' '){
	memcpy(_Context->buffer_HintPortugues,_Context->buffer_HintEnglish,850);
	}
	if(_Context->buffer_HintOther[0]==' '){
	memcpy(_Context->buffer_HintOther,_Context->buffer_HintEnglish,850);
	}
		accept_widget_messages_show(_Context);
;
	return(-1);
}
private int on_Auto3597_event(struct accept_widget_messages_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_widget_messages_event(
struct accept_widget_messages_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_TabEnglish == mb ) return(2);
		if (_Context->trigger_TabFrancais == mb ) return(5);
		if (_Context->trigger_TabItaliano == mb ) return(8);
		if (_Context->trigger_TabEspagnol == mb ) return(11);
		if (_Context->trigger_TabDeutsch == mb ) return(14);
		if (_Context->trigger_TabNederlands == mb ) return(17);
		if (_Context->trigger_TabPortugues == mb ) return(20);
		if (_Context->trigger_TabOther == mb ) return(23);
		if (_Context->trigger_Auto3596 == mb ) return(26);
		if (_Context->trigger_Reset == mb ) return(27);
		if (_Context->trigger_Copy == mb ) return(28);
		if (_Context->trigger_Auto3597 == mb ) return(29);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3578+709) )  
	&&  (my >= (_Context->y_Auto3578+4) )  
	&&  (mx <= (_Context->x_Auto3578+726) )  
	&&  (my <= (_Context->y_Auto3578+20) )) {
		return(1);	/* Auto3578 */

		}
	if ((mx >= (_Context->x_Auto3578+693) )  
	&&  (my >= (_Context->y_Auto3578+4) )  
	&&  (mx <= (_Context->x_Auto3578+710) )  
	&&  (my <= (_Context->y_Auto3578+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vnation.htm");
			};
		return(-1);	/* Auto3578 */

		}
	if ((mx >= (_Context->x_Auto3578+677) )  
	&&  (my >= (_Context->y_Auto3578+4) )  
	&&  (mx <= (_Context->x_Auto3578+694) )  
	&&  (my <= (_Context->y_Auto3578+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_widget_messages_show(_Context);
		return(-1);	/* Auto3578 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3578+4) )  
		&&  (my >= (_Context->y_Auto3578+4) )  
		&&  (mx <= (_Context->x_Auto3578+662) )  
		&&  (my <= (_Context->y_Auto3578+20) )) {
			return( Auto3578action(_Context) );
			}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto3578+10+0) ) 
		&&  ( my >= (_Context->y_Auto3578+50) ) 
		&&  ( mx <= (_Context->x_Auto3578+10+80) ) 
		&&  ( my <= (_Context->y_Auto3578+50+24))) {
			return(2); /* TabEnglish */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3578+20) ) 
		&&  ( my >= (_Context->y_Auto3578+110) ) 
		&&  ( mx <= (_Context->x_Auto3578+20+680) ) 
		&&  ( my <= (_Context->y_Auto3578+110+160))) {
			return(3); /* English */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3578+20) ) 
		&&  ( my >= (_Context->y_Auto3578+300) ) 
		&&  ( mx <= (_Context->x_Auto3578+20+680) ) 
		&&  ( my <= (_Context->y_Auto3578+300+160))) {
			return(4); /* HintEnglish */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto3578+10+81) ) 
		&&  ( my >= (_Context->y_Auto3578+50) ) 
		&&  ( mx <= (_Context->x_Auto3578+10+169) ) 
		&&  ( my <= (_Context->y_Auto3578+50+24))) {
			return(5); /* TabFrancais */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3578+20) ) 
		&&  ( my >= (_Context->y_Auto3578+110) ) 
		&&  ( mx <= (_Context->x_Auto3578+20+680) ) 
		&&  ( my <= (_Context->y_Auto3578+110+160))) {
			return(6); /* Francais */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3578+20) ) 
		&&  ( my >= (_Context->y_Auto3578+300) ) 
		&&  ( mx <= (_Context->x_Auto3578+20+680) ) 
		&&  ( my <= (_Context->y_Auto3578+300+160))) {
			return(7); /* HintFrancais */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_Auto3578+10+170) ) 
		&&  ( my >= (_Context->y_Auto3578+50) ) 
		&&  ( mx <= (_Context->x_Auto3578+10+249) ) 
		&&  ( my <= (_Context->y_Auto3578+50+24))) {
			return(8); /* TabItaliano */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3578+20) ) 
		&&  ( my >= (_Context->y_Auto3578+110) ) 
		&&  ( mx <= (_Context->x_Auto3578+20+680) ) 
		&&  ( my <= (_Context->y_Auto3578+110+160))) {
			return(9); /* Italiano */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3578+20) ) 
		&&  ( my >= (_Context->y_Auto3578+300) ) 
		&&  ( mx <= (_Context->x_Auto3578+20+680) ) 
		&&  ( my <= (_Context->y_Auto3578+300+160))) {
			return(10); /* HintItaliano */
			}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if (( mx >= (_Context->x_Auto3578+10+250) ) 
		&&  ( my >= (_Context->y_Auto3578+50) ) 
		&&  ( mx <= (_Context->x_Auto3578+10+341) ) 
		&&  ( my <= (_Context->y_Auto3578+50+24))) {
			return(11); /* TabEspagnol */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3578+20) ) 
		&&  ( my >= (_Context->y_Auto3578+110) ) 
		&&  ( mx <= (_Context->x_Auto3578+20+680) ) 
		&&  ( my <= (_Context->y_Auto3578+110+160))) {
			return(12); /* Espagnol */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3578+20) ) 
		&&  ( my >= (_Context->y_Auto3578+300) ) 
		&&  ( mx <= (_Context->x_Auto3578+20+680) ) 
		&&  ( my <= (_Context->y_Auto3578+300+160))) {
			return(13); /* HintEspagnol */
			}
		}
	if (_Context->page_number == 5 ) {
	} else {
		if (( mx >= (_Context->x_Auto3578+10+342) ) 
		&&  ( my >= (_Context->y_Auto3578+50) ) 
		&&  ( mx <= (_Context->x_Auto3578+10+428) ) 
		&&  ( my <= (_Context->y_Auto3578+50+24))) {
			return(14); /* TabDeutsch */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3578+20) ) 
		&&  ( my >= (_Context->y_Auto3578+110) ) 
		&&  ( mx <= (_Context->x_Auto3578+20+680) ) 
		&&  ( my <= (_Context->y_Auto3578+110+160))) {
			return(15); /* Deutsch */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3578+20) ) 
		&&  ( my >= (_Context->y_Auto3578+300) ) 
		&&  ( mx <= (_Context->x_Auto3578+20+680) ) 
		&&  ( my <= (_Context->y_Auto3578+300+160))) {
			return(16); /* HintDeutsch */
			}
		}
	if (_Context->page_number == 6 ) {
	} else {
		if (( mx >= (_Context->x_Auto3578+10+429) ) 
		&&  ( my >= (_Context->y_Auto3578+50) ) 
		&&  ( mx <= (_Context->x_Auto3578+10+532) ) 
		&&  ( my <= (_Context->y_Auto3578+50+24))) {
			return(17); /* TabNederlands */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3578+20) ) 
		&&  ( my >= (_Context->y_Auto3578+110) ) 
		&&  ( mx <= (_Context->x_Auto3578+20+680) ) 
		&&  ( my <= (_Context->y_Auto3578+110+160))) {
			return(18); /* Nederlands */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3578+20) ) 
		&&  ( my >= (_Context->y_Auto3578+300) ) 
		&&  ( mx <= (_Context->x_Auto3578+20+680) ) 
		&&  ( my <= (_Context->y_Auto3578+300+160))) {
			return(19); /* HintNederlands */
			}
		}
	if (_Context->page_number == 7 ) {
	} else {
		if (( mx >= (_Context->x_Auto3578+10+533) ) 
		&&  ( my >= (_Context->y_Auto3578+50) ) 
		&&  ( mx <= (_Context->x_Auto3578+10+631) ) 
		&&  ( my <= (_Context->y_Auto3578+50+24))) {
			return(20); /* TabPortugues */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3578+20) ) 
		&&  ( my >= (_Context->y_Auto3578+110) ) 
		&&  ( mx <= (_Context->x_Auto3578+20+680) ) 
		&&  ( my <= (_Context->y_Auto3578+110+160))) {
			return(21); /* Portugues */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3578+20) ) 
		&&  ( my >= (_Context->y_Auto3578+300) ) 
		&&  ( mx <= (_Context->x_Auto3578+20+680) ) 
		&&  ( my <= (_Context->y_Auto3578+300+160))) {
			return(22); /* HintPortugues */
			}
		}
	if (_Context->page_number == 8 ) {
	} else {
		if (( mx >= (_Context->x_Auto3578+10+632) ) 
		&&  ( my >= (_Context->y_Auto3578+50) ) 
		&&  ( mx <= (_Context->x_Auto3578+10+704) ) 
		&&  ( my <= (_Context->y_Auto3578+50+24))) {
			return(23); /* TabOther */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto3578+20) ) 
		&&  ( my >= (_Context->y_Auto3578+110) ) 
		&&  ( mx <= (_Context->x_Auto3578+20+680) ) 
		&&  ( my <= (_Context->y_Auto3578+110+160))) {
			return(24); /* Other */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto3578+20) ) 
		&&  ( my >= (_Context->y_Auto3578+300) ) 
		&&  ( mx <= (_Context->x_Auto3578+20+680) ) 
		&&  ( my <= (_Context->y_Auto3578+300+160))) {
			return(25); /* HintOther */
			}
		}
	if (( mx >= (_Context->x_Auto3578+10) ) 
	&&  ( my >= (_Context->y_Auto3578+490) ) 
	&&  ( mx <= (_Context->x_Auto3578+10+56) ) 
	&&  ( my <= (_Context->y_Auto3578+490+48))) {
		return(26); /* Auto3596 */
		}
	if (( mx >= (_Context->x_Auto3578+380) ) 
	&&  ( my >= (_Context->y_Auto3578+490) ) 
	&&  ( mx <= (_Context->x_Auto3578+380+136) ) 
	&&  ( my <= (_Context->y_Auto3578+490+32))) {
		return(27); /* Reset */
		}
	if (( mx >= (_Context->x_Auto3578+220) ) 
	&&  ( my >= (_Context->y_Auto3578+490) ) 
	&&  ( mx <= (_Context->x_Auto3578+220+136) ) 
	&&  ( my <= (_Context->y_Auto3578+490+32))) {
		return(28); /* Copy */
		}
	if (( mx >= (_Context->x_Auto3578+660) ) 
	&&  ( my >= (_Context->y_Auto3578+490) ) 
	&&  ( mx <= (_Context->x_Auto3578+660+56) ) 
	&&  ( my <= (_Context->y_Auto3578+490+48))) {
		return(29); /* Auto3597 */
		}

	return(-1);
}


public	int	accept_widget_messages_losefocus(struct accept_widget_messages_context * _Context)
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


public	int	accept_widget_messages_focus(struct accept_widget_messages_context * _Context)
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
					_Context->keycode = visual_edit(_Context->x_Auto3578+20+1,_Context->y_Auto3578+110+1,680,160,vfh[1],_Context->buffer_English,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* HintEnglish */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3578+20+1,_Context->y_Auto3578+300+1,680,160,vfh[1],_Context->buffer_HintEnglish,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* TabFrancais */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x6 :
				/* Francais */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3578+20+1,_Context->y_Auto3578+110+1,680,160,vfh[1],_Context->buffer_Francais,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* HintFrancais */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3578+20+1,_Context->y_Auto3578+300+1,680,160,vfh[1],_Context->buffer_HintFrancais,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* TabItaliano */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x9 :
				/* Italiano */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3578+20+1,_Context->y_Auto3578+110+1,680,160,vfh[1],_Context->buffer_Italiano,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* HintItaliano */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3578+20+1,_Context->y_Auto3578+300+1,680,160,vfh[1],_Context->buffer_HintItaliano,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* TabEspagnol */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xc :
				/* Espagnol */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3578+20+1,_Context->y_Auto3578+110+1,680,160,vfh[1],_Context->buffer_Espagnol,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* HintEspagnol */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3578+20+1,_Context->y_Auto3578+300+1,680,160,vfh[1],_Context->buffer_HintEspagnol,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* TabDeutsch */
				if (_Context->page_number == 5 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xf :
				/* Deutsch */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3578+20+1,_Context->y_Auto3578+110+1,680,160,vfh[1],_Context->buffer_Deutsch,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* HintDeutsch */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3578+20+1,_Context->y_Auto3578+300+1,680,160,vfh[1],_Context->buffer_HintDeutsch,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* TabNederlands */
				if (_Context->page_number == 6 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x12 :
				/* Nederlands */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3578+20+1,_Context->y_Auto3578+110+1,680,160,vfh[1],_Context->buffer_Nederlands,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* HintNederlands */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3578+20+1,_Context->y_Auto3578+300+1,680,160,vfh[1],_Context->buffer_HintNederlands,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* TabPortugues */
				if (_Context->page_number == 7 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x15 :
				/* Portugues */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3578+20+1,_Context->y_Auto3578+110+1,680,160,vfh[1],_Context->buffer_Portugues,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* HintPortugues */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3578+20+1,_Context->y_Auto3578+300+1,680,160,vfh[1],_Context->buffer_HintPortugues,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x17 :
				/* TabOther */
				if (_Context->page_number == 8 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x18 :
				/* Other */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3578+20+1,_Context->y_Auto3578+110+1,680,160,vfh[1],_Context->buffer_Other,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* HintOther */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3578+20+1,_Context->y_Auto3578+300+1,680,160,vfh[1],_Context->buffer_HintOther,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* Auto3596 */
				_Context->trigger_Auto3596=visual_trigger_code(_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]));
				visual_button(_Context->x_Auto3578+10,_Context->y_Auto3578+490,56,48,vfh[2],34,0,_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3596=visual_trigger_code(_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]));
	visual_button(_Context->x_Auto3578+10,_Context->y_Auto3578+490,56,48,vfh[2],34,0,_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]),1040);
				break;
			case	0x1b :
				/* Reset */
				_Context->trigger_Reset=visual_trigger_code(_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]));
				visual_button(_Context->x_Auto3578+380,_Context->y_Auto3578+490,136,32,vfh[2],0,0,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Reset=visual_trigger_code(_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]));
	visual_button(_Context->x_Auto3578+380,_Context->y_Auto3578+490,136,32,vfh[2],0,0,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),0);
				break;
			case	0x1c :
				/* Copy */
				_Context->trigger_Copy=visual_trigger_code(_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]));
				visual_button(_Context->x_Auto3578+220,_Context->y_Auto3578+490,136,32,vfh[2],0,0,_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Copy=visual_trigger_code(_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]));
	visual_button(_Context->x_Auto3578+220,_Context->y_Auto3578+490,136,32,vfh[2],0,0,_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]),0);
				break;
			case	0x1d :
				/* Auto3597 */
				_Context->trigger_Auto3597=visual_trigger_code(_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]));
				visual_button(_Context->x_Auto3578+660,_Context->y_Auto3578+490,56,48,vfh[2],34,0,_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3597=visual_trigger_code(_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]));
	visual_button(_Context->x_Auto3578+660,_Context->y_Auto3578+490,56,48,vfh[2],34,0,_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			accept_widget_messages_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_widget_messages_show(_Context);
			continue;
		case	0x2 :
			accept_widget_messages_losefocus(_Context);
			_Context->page_number=8;
			_Context->focus_item=29;
			accept_widget_messages_show(_Context);
			continue;
		case	0x3 :
			accept_widget_messages_losefocus(_Context);
			if ( _Context->page_number < 8 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_widget_messages_show(_Context);
			continue;
		case	0x12 :
			accept_widget_messages_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_widget_messages_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_widget_messages_event(_Context)) == -1)
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
						if (HintEnglish_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (Francais_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (HintFrancais_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (Italiano_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (HintItaliano_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (Espagnol_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (HintEspagnol_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (Deutsch_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (HintDeutsch_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (Nederlands_help(_Context) != 0) { continue; }
						else { break; }
					case	0x13 :
						if (HintNederlands_help(_Context) != 0) { continue; }
						else { break; }
					case	0x15 :
						if (Portugues_help(_Context) != 0) { continue; }
						else { break; }
					case	0x16 :
						if (HintPortugues_help(_Context) != 0) { continue; }
						else { break; }
					case	0x18 :
						if (Other_help(_Context) != 0) { continue; }
						else { break; }
					case	0x19 :
						if (HintOther_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1a :
						if (Auto3596_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1b :
						if (Reset_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1c :
						if (Copy_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1d :
						if (Auto3597_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3578 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* TabEnglish */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_widget_messages_losefocus(_Context);
						_Context->page_number = 1;
						accept_widget_messages_show(_Context);
						}
					continue;
				case	0x3 :
					/* English */
					continue;
				case	0x4 :
					/* HintEnglish */
					continue;
				case	0x5 :
					/* TabFrancais */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_widget_messages_losefocus(_Context);
						_Context->page_number = 2;
						accept_widget_messages_show(_Context);
						}
					continue;
				case	0x6 :
					/* Francais */
					continue;
				case	0x7 :
					/* HintFrancais */
					continue;
				case	0x8 :
					/* TabItaliano */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_widget_messages_losefocus(_Context);
						_Context->page_number = 3;
						accept_widget_messages_show(_Context);
						}
					continue;
				case	0x9 :
					/* Italiano */
					continue;
				case	0xa :
					/* HintItaliano */
					continue;
				case	0xb :
					/* TabEspagnol */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_widget_messages_losefocus(_Context);
						_Context->page_number = 4;
						accept_widget_messages_show(_Context);
						}
					continue;
				case	0xc :
					/* Espagnol */
					continue;
				case	0xd :
					/* HintEspagnol */
					continue;
				case	0xe :
					/* TabDeutsch */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_widget_messages_losefocus(_Context);
						_Context->page_number = 5;
						accept_widget_messages_show(_Context);
						}
					continue;
				case	0xf :
					/* Deutsch */
					continue;
				case	0x10 :
					/* HintDeutsch */
					continue;
				case	0x11 :
					/* TabNederlands */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_widget_messages_losefocus(_Context);
						_Context->page_number = 6;
						accept_widget_messages_show(_Context);
						}
					continue;
				case	0x12 :
					/* Nederlands */
					continue;
				case	0x13 :
					/* HintNederlands */
					continue;
				case	0x14 :
					/* TabPortugues */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_widget_messages_losefocus(_Context);
						_Context->page_number = 7;
						accept_widget_messages_show(_Context);
						}
					continue;
				case	0x15 :
					/* Portugues */
					continue;
				case	0x16 :
					/* HintPortugues */
					continue;
				case	0x17 :
					/* TabOther */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_widget_messages_losefocus(_Context);
						_Context->page_number = 8;
						accept_widget_messages_show(_Context);
						}
					continue;
				case	0x18 :
					/* Other */
					continue;
				case	0x19 :
					/* HintOther */
					continue;
				case	0x1a :
					/* Auto3596 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3596=visual_trigger_code(_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]));
						visual_button(_Context->x_Auto3578+10,_Context->y_Auto3578+490,56,48,vfh[2],34,0,_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3596=visual_trigger_code(_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]));
	visual_button(_Context->x_Auto3578+10,_Context->y_Auto3578+490,56,48,vfh[2],34,0,_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3596_event(_Context)) != -1) break;

						}
					continue;
				case	0x1b :
					/* Reset */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Reset=visual_trigger_code(_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]));
						visual_button(_Context->x_Auto3578+380,_Context->y_Auto3578+490,136,32,vfh[2],0,0,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Reset=visual_trigger_code(_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]));
	visual_button(_Context->x_Auto3578+380,_Context->y_Auto3578+490,136,32,vfh[2],0,0,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Reset_event(_Context)) != -1) break;

						}
					continue;
				case	0x1c :
					/* Copy */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Copy=visual_trigger_code(_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]));
						visual_button(_Context->x_Auto3578+220,_Context->y_Auto3578+490,136,32,vfh[2],0,0,_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Copy=visual_trigger_code(_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]));
	visual_button(_Context->x_Auto3578+220,_Context->y_Auto3578+490,136,32,vfh[2],0,0,_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Copy_event(_Context)) != -1) break;

						}
					continue;
				case	0x1d :
					/* Auto3597 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3597=visual_trigger_code(_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]));
						visual_button(_Context->x_Auto3578+660,_Context->y_Auto3578+490,56,48,vfh[2],34,0,_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3597=visual_trigger_code(_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]));
	visual_button(_Context->x_Auto3578+660,_Context->y_Auto3578+490,56,48,vfh[2],34,0,_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3597_event(_Context)) != -1) break;

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
				_Context->focus_item=29;
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

public	int	accept_widget_messages(
	char * pEnglish,
	char * pHintEnglish,
	char * pFrancais,
	char * pHintFrancais,
	char * pItaliano,
	char * pHintItaliano,
	char * pEspagnol,
	char * pHintEspagnol,
	char * pDeutsch,
	char * pHintDeutsch,
	char * pNederlands,
	char * pHintNederlands,
	char * pPortugues,
	char * pHintPortugues,
	char * pOther,
	char * pHintOther)
{
	int	status=0;
	struct accept_widget_messages_context * _Context=(struct accept_widget_messages_context*) 0;
	status = accept_widget_messages_create(
	&_Context,
	 pEnglish,
	 pHintEnglish,
	 pFrancais,
	 pHintFrancais,
	 pItaliano,
	 pHintItaliano,
	 pEspagnol,
	 pHintEspagnol,
	 pDeutsch,
	 pHintDeutsch,
	 pNederlands,
	 pHintNederlands,
	 pPortugues,
	 pHintPortugues,
	 pOther,
	 pHintOther);
	if ( status != 0) return(status);
	status = accept_widget_messages_show(_Context);
		enter_modal();
	status = accept_widget_messages_focus(_Context);
		leave_modal();
	status = accept_widget_messages_hide(_Context);
	status = accept_widget_messages_remove(
	_Context,
	 pEnglish,
	 pHintEnglish,
	 pFrancais,
	 pHintFrancais,
	 pItaliano,
	 pHintItaliano,
	 pEspagnol,
	 pHintEspagnol,
	 pDeutsch,
	 pHintDeutsch,
	 pNederlands,
	 pHintNederlands,
	 pPortugues,
	 pHintPortugues,
	 pOther,
	 pHintOther);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vnation_c */
