
#ifndef _vnation_c
#define _vnation_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vnation.xml                                              */
/* Target         : vnation.c                                                */
/* Identification : 0.0-1177511936-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto2749   ""
#define fr__Auto2749   ""
#define it__Auto2749   ""
#define es__Auto2749   ""
#define de__Auto2749   ""
#define nl__Auto2749   ""
#define pt__Auto2749   ""
#define xx__Auto2749   ""
#define en_Auto2750   "International Message Editor"
#define fr_Auto2750   "Editeur de messages multilingues"
#define it_Auto2750   "International Message Editor"
#define es_Auto2750   "International Message Editor"
#define de_Auto2750   "International Message Editor"
#define nl_Auto2750   "International Message Editor"
#define pt_Auto2750   "International Message Editor"
#define xx_Auto2750   "International Message Editor"
#define en_TabEnglish   "&English"
#define fr_TabEnglish   "&English"
#define it_TabEnglish   "English"
#define es_TabEnglish   "English"
#define de_TabEnglish   "English"
#define nl_TabEnglish   "English"
#define pt_TabEnglish   "English"
#define xx_TabEnglish   "English"
#define en_Auto2751   "Payload"
#define fr_Auto2751   "Libell‚"
#define it_Auto2751   "Payload"
#define es_Auto2751   "Payload"
#define de_Auto2751   "Payload"
#define nl_Auto2751   "Payload"
#define pt_Auto2751   "Payload"
#define xx_Auto2751   "Payload"
#define en__Auto2751   ""
#define en_Auto2752   "Hint"
#define fr_Auto2752   "Infobulle"
#define it_Auto2752   "Hint"
#define es_Auto2752   "Hint"
#define de_Auto2752   "Hint"
#define nl_Auto2752   "Hint"
#define pt_Auto2752   "Hint"
#define xx_Auto2752   "Hint"
#define en__Auto2752   ""
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
#define en_Auto2753   "Payload"
#define fr_Auto2753   "Zone de donnee"
#define it_Auto2753   "Payload"
#define es_Auto2753   "Payload"
#define de_Auto2753   "Payload"
#define nl_Auto2753   "Payload"
#define pt_Auto2753   "Payload"
#define xx_Auto2753   "Payload"
#define en__Auto2753   ""
#define en_Auto2754   "Hint"
#define fr_Auto2754   "Hint (infobulle)"
#define it_Auto2754   "Hint"
#define es_Auto2754   "Hint"
#define de_Auto2754   "Hint"
#define nl_Auto2754   "Hint"
#define pt_Auto2754   "Hint"
#define xx_Auto2754   "Hint"
#define en__Auto2754   ""
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
#define en_Auto2755   "Payload"
#define fr_Auto2755   "Zone de donnee"
#define it_Auto2755   "Payload"
#define es_Auto2755   "Payload"
#define de_Auto2755   "Payload"
#define nl_Auto2755   "Payload"
#define pt_Auto2755   "Payload"
#define xx_Auto2755   "Payload"
#define en__Auto2755   ""
#define en_Auto2756   "Hint"
#define fr_Auto2756   "Hint (infobulle)"
#define it_Auto2756   "Hint"
#define es_Auto2756   "Hint"
#define de_Auto2756   "Hint"
#define nl_Auto2756   "Hint"
#define pt_Auto2756   "Hint"
#define xx_Auto2756   "Hint"
#define en__Auto2756   ""
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
#define en_Auto2757   "Payload"
#define fr_Auto2757   "Zone de donnee"
#define it_Auto2757   "Payload"
#define es_Auto2757   "Payload"
#define de_Auto2757   "Payload"
#define nl_Auto2757   "Payload"
#define pt_Auto2757   "Payload"
#define xx_Auto2757   "Payload"
#define en__Auto2757   ""
#define en_Auto2758   "Hint"
#define fr_Auto2758   "Hint (infobulle)"
#define it_Auto2758   "Hint"
#define es_Auto2758   "Hint"
#define de_Auto2758   "Hint"
#define nl_Auto2758   "Hint"
#define pt_Auto2758   "Hint"
#define xx_Auto2758   "Hint"
#define en__Auto2758   ""
#define en_TabDeutsch   "&Deutsch"
#define fr_TabDeutsch   "&Deutsch"
#define it_TabDeutsch   "Deutsch"
#define es_TabDeutsch   "Deutsch"
#define de_TabDeutsch   "Deutsch"
#define nl_TabDeutsch   "Deutsch"
#define pt_TabDeutsch   "Deutsch"
#define xx_TabDeutsch   "Deutsch"
#define en_Auto2759   "Payload"
#define fr_Auto2759   "Zone de donnee"
#define it_Auto2759   "Payload"
#define es_Auto2759   "Payload"
#define de_Auto2759   "Payload"
#define nl_Auto2759   "Payload"
#define pt_Auto2759   "Payload"
#define xx_Auto2759   "Payload"
#define en__Auto2759   ""
#define en_Auto2760   "Hint"
#define fr_Auto2760   "Hint (infobulle)"
#define it_Auto2760   "Hint"
#define es_Auto2760   "Hint"
#define de_Auto2760   "Hint"
#define nl_Auto2760   "Hint"
#define pt_Auto2760   "Hint"
#define xx_Auto2760   "Hint"
#define en__Auto2760   ""
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
#define en_Auto2761   "Payload"
#define fr_Auto2761   "Zone de donnee"
#define it_Auto2761   "Payload"
#define es_Auto2761   "Payload"
#define de_Auto2761   "Payload"
#define nl_Auto2761   "Payload"
#define pt_Auto2761   "Payload"
#define xx_Auto2761   "Payload"
#define en__Auto2761   ""
#define en_Auto2762   "Hint"
#define fr_Auto2762   "Hint (infobulle)"
#define it_Auto2762   "Hint"
#define es_Auto2762   "Hint"
#define de_Auto2762   "Hint"
#define nl_Auto2762   "Hint"
#define pt_Auto2762   "Hint"
#define xx_Auto2762   "Hint"
#define en__Auto2762   ""
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
#define en_Auto2763   "Payload"
#define fr_Auto2763   "Zone de donnee"
#define it_Auto2763   "Payload"
#define es_Auto2763   "Payload"
#define de_Auto2763   "Payload"
#define nl_Auto2763   "Payload"
#define pt_Auto2763   "Payload"
#define xx_Auto2763   "Payload"
#define en__Auto2763   ""
#define en_Auto2764   "Hint"
#define fr_Auto2764   "Hint (infobulle)"
#define it_Auto2764   "Hint"
#define es_Auto2764   "Hint"
#define de_Auto2764   "Hint"
#define nl_Auto2764   "Hint"
#define pt_Auto2764   "Hint"
#define xx_Auto2764   "Hint"
#define en__Auto2764   ""
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
#define en_Auto2765   "Payload"
#define fr_Auto2765   "Zone de donnee"
#define it_Auto2765   "Payload"
#define es_Auto2765   "Payload"
#define de_Auto2765   "Payload"
#define nl_Auto2765   "Payload"
#define pt_Auto2765   "Payload"
#define xx_Auto2765   "Payload"
#define en__Auto2765   ""
#define en_Auto2766   "Hint"
#define fr_Auto2766   "Hint (infobulle)"
#define it_Auto2766   "Hint"
#define es_Auto2766   "Hint"
#define de_Auto2766   "Hint"
#define nl_Auto2766   "Hint"
#define pt_Auto2766   "Hint"
#define xx_Auto2766   "Hint"
#define en__Auto2766   ""
#define en_HintOther   ""
#define en__HintOther   ""
#define en_Auto2767   "ok.gif"
#define fr_Auto2767   "ok.gif"
#define it_Auto2767   "ok.gif"
#define es_Auto2767   "ok.gif"
#define de_Auto2767   "ok.gif"
#define nl_Auto2767   "ok.gif"
#define pt_Auto2767   "ok.gif"
#define xx_Auto2767   "ok.gif"
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
#define en_Auto2768   "cancel.gif"
#define fr_Auto2768   "cancel.gif"
#define it_Auto2768   "cancel.gif"
#define es_Auto2768   "cancel.gif"
#define de_Auto2768   "cancel.gif"
#define nl_Auto2768   "cancel.gif"
#define pt_Auto2768   "cancel.gif"
#define xx_Auto2768   "cancel.gif"

private struct accept_widget_messages_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[8+1];
	char * msg_Auto2749[8];
	char * hint_Auto2749[8];
	int	x_Auto2749;
	int	y_Auto2749;
	int	w_Auto2749;
	int	h_Auto2749;
	char * msg_Auto2750[8];
	char * hint_Auto2750[8];
	char * msg_TabEnglish[8];
	int	trigger_TabEnglish;
	char * hint_TabEnglish[8];
	int	page_number;
	char * msg_Auto2751[8];
	char * hint_Auto2751[8];
	char * msg_Auto2752[8];
	char * hint_Auto2752[8];
	char * hint_English[8];
	char	buffer_English[851];
	char * hint_HintEnglish[8];
	char	buffer_HintEnglish[851];
	char * msg_TabFrancais[8];
	int	trigger_TabFrancais;
	char * hint_TabFrancais[8];
	char * msg_Auto2753[8];
	char * hint_Auto2753[8];
	char * msg_Auto2754[8];
	char * hint_Auto2754[8];
	char * hint_Francais[8];
	char	buffer_Francais[851];
	char * hint_HintFrancais[8];
	char	buffer_HintFrancais[851];
	char * msg_TabItaliano[8];
	int	trigger_TabItaliano;
	char * hint_TabItaliano[8];
	char * msg_Auto2755[8];
	char * hint_Auto2755[8];
	char * msg_Auto2756[8];
	char * hint_Auto2756[8];
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
	char * msg_Auto2757[8];
	char * hint_Auto2757[8];
	char * msg_Auto2758[8];
	char * hint_Auto2758[8];
	char * msg_TabDeutsch[8];
	int	trigger_TabDeutsch;
	char * hint_TabDeutsch[8];
	char * msg_Auto2759[8];
	char * hint_Auto2759[8];
	char * msg_Auto2760[8];
	char * hint_Auto2760[8];
	char * hint_Deutsch[8];
	char	buffer_Deutsch[851];
	char * hint_HintDeutsch[8];
	char	buffer_HintDeutsch[851];
	char * msg_TabNederlands[8];
	int	trigger_TabNederlands;
	char * hint_TabNederlands[8];
	char * msg_Auto2761[8];
	char * hint_Auto2761[8];
	char * msg_Auto2762[8];
	char * hint_Auto2762[8];
	char * hint_Nederlands[8];
	char	buffer_Nederlands[851];
	char * hint_HintNederlands[8];
	char	buffer_HintNederlands[851];
	char * msg_TabPortugues[8];
	int	trigger_TabPortugues;
	char * hint_TabPortugues[8];
	char * msg_Auto2763[8];
	char * hint_Auto2763[8];
	char * msg_Auto2764[8];
	char * hint_Auto2764[8];
	char * hint_Portugues[8];
	char	buffer_Portugues[851];
	char * hint_HintPortugues[8];
	char	buffer_HintPortugues[851];
	char * msg_TabOther[8];
	int	trigger_TabOther;
	char * hint_TabOther[8];
	char * msg_Auto2765[8];
	char * hint_Auto2765[8];
	char * msg_Auto2766[8];
	char * hint_Auto2766[8];
	char * hint_Other[8];
	char	buffer_Other[851];
	char * hint_HintOther[8];
	char	buffer_HintOther[851];
	char * msg_Auto2767[8];
	int	trigger_Auto2767;
	char * hint_Auto2767[8];
	char * msg_Reset[8];
	int	trigger_Reset;
	char * hint_Reset[8];
	char * msg_Copy[8];
	int	trigger_Copy;
	char * hint_Copy[8];
	char * msg_Auto2768[8];
	int	trigger_Auto2768;
	char * hint_Auto2768[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[17];
	};
static int	vfh[16];

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
	vfh[10] = visual_font("font10.fmf",10);
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
	for (i=0; i < 8; i++)_Context->msg_Auto2749[i]=" ";
	_Context->hint_Auto2749[0]=en__Auto2749;
	_Context->hint_Auto2749[1]=fr__Auto2749;
	_Context->hint_Auto2749[2]=it__Auto2749;
	_Context->hint_Auto2749[3]=es__Auto2749;
	_Context->hint_Auto2749[4]=de__Auto2749;
	_Context->hint_Auto2749[5]=nl__Auto2749;
	_Context->hint_Auto2749[6]=pt__Auto2749;
	_Context->hint_Auto2749[7]=xx__Auto2749;
	_Context->x_Auto2749=35;
	_Context->y_Auto2749=25;
	_Context->w_Auto2749=730;
	_Context->h_Auto2749=550;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2750[i]=" ";
	_Context->msg_Auto2750[0]=en_Auto2750;
	_Context->msg_Auto2750[1]=fr_Auto2750;
	_Context->msg_Auto2750[2]=it_Auto2750;
	_Context->msg_Auto2750[3]=es_Auto2750;
	_Context->msg_Auto2750[4]=de_Auto2750;
	_Context->msg_Auto2750[5]=nl_Auto2750;
	_Context->msg_Auto2750[6]=pt_Auto2750;
	_Context->msg_Auto2750[7]=xx_Auto2750;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2751[i]=" ";
	_Context->msg_Auto2751[0]=en_Auto2751;
	_Context->msg_Auto2751[1]=fr_Auto2751;
	_Context->msg_Auto2751[2]=it_Auto2751;
	_Context->msg_Auto2751[3]=es_Auto2751;
	_Context->msg_Auto2751[4]=de_Auto2751;
	_Context->msg_Auto2751[5]=nl_Auto2751;
	_Context->msg_Auto2751[6]=pt_Auto2751;
	_Context->msg_Auto2751[7]=xx_Auto2751;
	_Context->hint_Auto2751[0]=en__Auto2751;
	for (i=0; i < 8; i++)_Context->msg_Auto2752[i]=" ";
	_Context->msg_Auto2752[0]=en_Auto2752;
	_Context->msg_Auto2752[1]=fr_Auto2752;
	_Context->msg_Auto2752[2]=it_Auto2752;
	_Context->msg_Auto2752[3]=es_Auto2752;
	_Context->msg_Auto2752[4]=de_Auto2752;
	_Context->msg_Auto2752[5]=nl_Auto2752;
	_Context->msg_Auto2752[6]=pt_Auto2752;
	_Context->msg_Auto2752[7]=xx_Auto2752;
	_Context->hint_Auto2752[0]=en__Auto2752;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2753[i]=" ";
	_Context->msg_Auto2753[0]=en_Auto2753;
	_Context->msg_Auto2753[1]=fr_Auto2753;
	_Context->msg_Auto2753[2]=it_Auto2753;
	_Context->msg_Auto2753[3]=es_Auto2753;
	_Context->msg_Auto2753[4]=de_Auto2753;
	_Context->msg_Auto2753[5]=nl_Auto2753;
	_Context->msg_Auto2753[6]=pt_Auto2753;
	_Context->msg_Auto2753[7]=xx_Auto2753;
	_Context->hint_Auto2753[0]=en__Auto2753;
	for (i=0; i < 8; i++)_Context->msg_Auto2754[i]=" ";
	_Context->msg_Auto2754[0]=en_Auto2754;
	_Context->msg_Auto2754[1]=fr_Auto2754;
	_Context->msg_Auto2754[2]=it_Auto2754;
	_Context->msg_Auto2754[3]=es_Auto2754;
	_Context->msg_Auto2754[4]=de_Auto2754;
	_Context->msg_Auto2754[5]=nl_Auto2754;
	_Context->msg_Auto2754[6]=pt_Auto2754;
	_Context->msg_Auto2754[7]=xx_Auto2754;
	_Context->hint_Auto2754[0]=en__Auto2754;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2755[i]=" ";
	_Context->msg_Auto2755[0]=en_Auto2755;
	_Context->msg_Auto2755[1]=fr_Auto2755;
	_Context->msg_Auto2755[2]=it_Auto2755;
	_Context->msg_Auto2755[3]=es_Auto2755;
	_Context->msg_Auto2755[4]=de_Auto2755;
	_Context->msg_Auto2755[5]=nl_Auto2755;
	_Context->msg_Auto2755[6]=pt_Auto2755;
	_Context->msg_Auto2755[7]=xx_Auto2755;
	_Context->hint_Auto2755[0]=en__Auto2755;
	for (i=0; i < 8; i++)_Context->msg_Auto2756[i]=" ";
	_Context->msg_Auto2756[0]=en_Auto2756;
	_Context->msg_Auto2756[1]=fr_Auto2756;
	_Context->msg_Auto2756[2]=it_Auto2756;
	_Context->msg_Auto2756[3]=es_Auto2756;
	_Context->msg_Auto2756[4]=de_Auto2756;
	_Context->msg_Auto2756[5]=nl_Auto2756;
	_Context->msg_Auto2756[6]=pt_Auto2756;
	_Context->msg_Auto2756[7]=xx_Auto2756;
	_Context->hint_Auto2756[0]=en__Auto2756;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2757[i]=" ";
	_Context->msg_Auto2757[0]=en_Auto2757;
	_Context->msg_Auto2757[1]=fr_Auto2757;
	_Context->msg_Auto2757[2]=it_Auto2757;
	_Context->msg_Auto2757[3]=es_Auto2757;
	_Context->msg_Auto2757[4]=de_Auto2757;
	_Context->msg_Auto2757[5]=nl_Auto2757;
	_Context->msg_Auto2757[6]=pt_Auto2757;
	_Context->msg_Auto2757[7]=xx_Auto2757;
	_Context->hint_Auto2757[0]=en__Auto2757;
	for (i=0; i < 8; i++)_Context->msg_Auto2758[i]=" ";
	_Context->msg_Auto2758[0]=en_Auto2758;
	_Context->msg_Auto2758[1]=fr_Auto2758;
	_Context->msg_Auto2758[2]=it_Auto2758;
	_Context->msg_Auto2758[3]=es_Auto2758;
	_Context->msg_Auto2758[4]=de_Auto2758;
	_Context->msg_Auto2758[5]=nl_Auto2758;
	_Context->msg_Auto2758[6]=pt_Auto2758;
	_Context->msg_Auto2758[7]=xx_Auto2758;
	_Context->hint_Auto2758[0]=en__Auto2758;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2759[i]=" ";
	_Context->msg_Auto2759[0]=en_Auto2759;
	_Context->msg_Auto2759[1]=fr_Auto2759;
	_Context->msg_Auto2759[2]=it_Auto2759;
	_Context->msg_Auto2759[3]=es_Auto2759;
	_Context->msg_Auto2759[4]=de_Auto2759;
	_Context->msg_Auto2759[5]=nl_Auto2759;
	_Context->msg_Auto2759[6]=pt_Auto2759;
	_Context->msg_Auto2759[7]=xx_Auto2759;
	_Context->hint_Auto2759[0]=en__Auto2759;
	for (i=0; i < 8; i++)_Context->msg_Auto2760[i]=" ";
	_Context->msg_Auto2760[0]=en_Auto2760;
	_Context->msg_Auto2760[1]=fr_Auto2760;
	_Context->msg_Auto2760[2]=it_Auto2760;
	_Context->msg_Auto2760[3]=es_Auto2760;
	_Context->msg_Auto2760[4]=de_Auto2760;
	_Context->msg_Auto2760[5]=nl_Auto2760;
	_Context->msg_Auto2760[6]=pt_Auto2760;
	_Context->msg_Auto2760[7]=xx_Auto2760;
	_Context->hint_Auto2760[0]=en__Auto2760;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2761[i]=" ";
	_Context->msg_Auto2761[0]=en_Auto2761;
	_Context->msg_Auto2761[1]=fr_Auto2761;
	_Context->msg_Auto2761[2]=it_Auto2761;
	_Context->msg_Auto2761[3]=es_Auto2761;
	_Context->msg_Auto2761[4]=de_Auto2761;
	_Context->msg_Auto2761[5]=nl_Auto2761;
	_Context->msg_Auto2761[6]=pt_Auto2761;
	_Context->msg_Auto2761[7]=xx_Auto2761;
	_Context->hint_Auto2761[0]=en__Auto2761;
	for (i=0; i < 8; i++)_Context->msg_Auto2762[i]=" ";
	_Context->msg_Auto2762[0]=en_Auto2762;
	_Context->msg_Auto2762[1]=fr_Auto2762;
	_Context->msg_Auto2762[2]=it_Auto2762;
	_Context->msg_Auto2762[3]=es_Auto2762;
	_Context->msg_Auto2762[4]=de_Auto2762;
	_Context->msg_Auto2762[5]=nl_Auto2762;
	_Context->msg_Auto2762[6]=pt_Auto2762;
	_Context->msg_Auto2762[7]=xx_Auto2762;
	_Context->hint_Auto2762[0]=en__Auto2762;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2763[i]=" ";
	_Context->msg_Auto2763[0]=en_Auto2763;
	_Context->msg_Auto2763[1]=fr_Auto2763;
	_Context->msg_Auto2763[2]=it_Auto2763;
	_Context->msg_Auto2763[3]=es_Auto2763;
	_Context->msg_Auto2763[4]=de_Auto2763;
	_Context->msg_Auto2763[5]=nl_Auto2763;
	_Context->msg_Auto2763[6]=pt_Auto2763;
	_Context->msg_Auto2763[7]=xx_Auto2763;
	_Context->hint_Auto2763[0]=en__Auto2763;
	for (i=0; i < 8; i++)_Context->msg_Auto2764[i]=" ";
	_Context->msg_Auto2764[0]=en_Auto2764;
	_Context->msg_Auto2764[1]=fr_Auto2764;
	_Context->msg_Auto2764[2]=it_Auto2764;
	_Context->msg_Auto2764[3]=es_Auto2764;
	_Context->msg_Auto2764[4]=de_Auto2764;
	_Context->msg_Auto2764[5]=nl_Auto2764;
	_Context->msg_Auto2764[6]=pt_Auto2764;
	_Context->msg_Auto2764[7]=xx_Auto2764;
	_Context->hint_Auto2764[0]=en__Auto2764;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2765[i]=" ";
	_Context->msg_Auto2765[0]=en_Auto2765;
	_Context->msg_Auto2765[1]=fr_Auto2765;
	_Context->msg_Auto2765[2]=it_Auto2765;
	_Context->msg_Auto2765[3]=es_Auto2765;
	_Context->msg_Auto2765[4]=de_Auto2765;
	_Context->msg_Auto2765[5]=nl_Auto2765;
	_Context->msg_Auto2765[6]=pt_Auto2765;
	_Context->msg_Auto2765[7]=xx_Auto2765;
	_Context->hint_Auto2765[0]=en__Auto2765;
	for (i=0; i < 8; i++)_Context->msg_Auto2766[i]=" ";
	_Context->msg_Auto2766[0]=en_Auto2766;
	_Context->msg_Auto2766[1]=fr_Auto2766;
	_Context->msg_Auto2766[2]=it_Auto2766;
	_Context->msg_Auto2766[3]=es_Auto2766;
	_Context->msg_Auto2766[4]=de_Auto2766;
	_Context->msg_Auto2766[5]=nl_Auto2766;
	_Context->msg_Auto2766[6]=pt_Auto2766;
	_Context->msg_Auto2766[7]=xx_Auto2766;
	_Context->hint_Auto2766[0]=en__Auto2766;
	_Context->hint_HintOther[0]=en__HintOther;
	for (i=0; i < 8; i++)_Context->msg_Auto2767[i]=" ";
	_Context->msg_Auto2767[0]=en_Auto2767;
	_Context->msg_Auto2767[1]=fr_Auto2767;
	_Context->msg_Auto2767[2]=it_Auto2767;
	_Context->msg_Auto2767[3]=es_Auto2767;
	_Context->msg_Auto2767[4]=de_Auto2767;
	_Context->msg_Auto2767[5]=nl_Auto2767;
	_Context->msg_Auto2767[6]=pt_Auto2767;
	_Context->msg_Auto2767[7]=xx_Auto2767;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2768[i]=" ";
	_Context->msg_Auto2768[0]=en_Auto2768;
	_Context->msg_Auto2768[1]=fr_Auto2768;
	_Context->msg_Auto2768[2]=it_Auto2768;
	_Context->msg_Auto2768[3]=es_Auto2768;
	_Context->msg_Auto2768[4]=de_Auto2768;
	_Context->msg_Auto2768[5]=nl_Auto2768;
	_Context->msg_Auto2768[6]=pt_Auto2768;
	_Context->msg_Auto2768[7]=xx_Auto2768;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto2749,_Context->y_Auto2749,730+10,550+10);
	return(0);
}

public 	int	accept_widget_messages_hide(struct accept_widget_messages_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto2749,_Context->y_Auto2749);
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
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto2749,_Context->y_Auto2749);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto2749,_Context->y_Auto2749,730,550,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto2749,_Context->y_Auto2749,730,550,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto2749+20,_Context->y_Auto2749+30,700,22,vfh[4],16,0,_Context->msg_Auto2750[_Context->language],strlen(_Context->msg_Auto2750[_Context->language]),1283);
	if (_Context->page_number == 1 ) {
	_Context->trigger_TabEnglish=visual_trigger_code(_Context->msg_TabEnglish[_Context->language],strlen(_Context->msg_TabEnglish[_Context->language]));
	visual_tabpage(_Context->x_Auto2749+10,_Context->y_Auto2749+50,710,430,vfh[2],_Context->msg_TabEnglish[_Context->language],strlen(_Context->msg_TabEnglish[_Context->language]),0,34);
	} else {
		visual_tabpage(_Context->x_Auto2749+10,_Context->y_Auto2749+50,710,430,vfh[2],_Context->msg_TabEnglish[_Context->language],strlen(_Context->msg_TabEnglish[_Context->language]),0,32);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto2749+20,_Context->y_Auto2749+90,140,16,vfh[2],16,0,_Context->msg_Auto2751[_Context->language],strlen(_Context->msg_Auto2751[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto2749+20,_Context->y_Auto2749+280,140,16,vfh[2],16,0,_Context->msg_Auto2752[_Context->language],strlen(_Context->msg_Auto2752[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto2749+20,_Context->y_Auto2749+110,680+2,160+2,5);
	visual_text(_Context->x_Auto2749+20+1,_Context->y_Auto2749+110+1,680,160,vfh[1],27,28,_Context->buffer_English,850,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto2749+20,_Context->y_Auto2749+300,680+2,160+2,5);
	visual_text(_Context->x_Auto2749+20+1,_Context->y_Auto2749+300+1,680,160,vfh[1],27,28,_Context->buffer_HintEnglish,850,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_TabFrancais=visual_trigger_code(_Context->msg_TabFrancais[_Context->language],strlen(_Context->msg_TabFrancais[_Context->language]));
	visual_tabpage(_Context->x_Auto2749+10,_Context->y_Auto2749+50,710,430,vfh[2],_Context->msg_TabFrancais[_Context->language],strlen(_Context->msg_TabFrancais[_Context->language]),81,34);
	} else {
		visual_tabpage(_Context->x_Auto2749+10,_Context->y_Auto2749+50,710,430,vfh[2],_Context->msg_TabFrancais[_Context->language],strlen(_Context->msg_TabFrancais[_Context->language]),81,32);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto2749+20,_Context->y_Auto2749+90,140,16,vfh[2],16,0,_Context->msg_Auto2753[_Context->language],strlen(_Context->msg_Auto2753[_Context->language]),258);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto2749+20,_Context->y_Auto2749+280,140,16,vfh[2],16,0,_Context->msg_Auto2754[_Context->language],strlen(_Context->msg_Auto2754[_Context->language]),258);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto2749+20,_Context->y_Auto2749+110,680+2,160+2,5);
	visual_text(_Context->x_Auto2749+20+1,_Context->y_Auto2749+110+1,680,160,vfh[1],16,0,_Context->buffer_Francais,850,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto2749+20,_Context->y_Auto2749+300,680+2,160+2,5);
	visual_text(_Context->x_Auto2749+20+1,_Context->y_Auto2749+300+1,680,160,vfh[1],16,0,_Context->buffer_HintFrancais,850,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_TabItaliano=visual_trigger_code(_Context->msg_TabItaliano[_Context->language],strlen(_Context->msg_TabItaliano[_Context->language]));
	visual_tabpage(_Context->x_Auto2749+10,_Context->y_Auto2749+50,710,430,vfh[2],_Context->msg_TabItaliano[_Context->language],strlen(_Context->msg_TabItaliano[_Context->language]),170,34);
	} else {
		visual_tabpage(_Context->x_Auto2749+10,_Context->y_Auto2749+50,710,430,vfh[2],_Context->msg_TabItaliano[_Context->language],strlen(_Context->msg_TabItaliano[_Context->language]),170,32);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto2749+20,_Context->y_Auto2749+90,140,16,vfh[2],16,0,_Context->msg_Auto2755[_Context->language],strlen(_Context->msg_Auto2755[_Context->language]),258);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto2749+20,_Context->y_Auto2749+280,140,16,vfh[2],16,0,_Context->msg_Auto2756[_Context->language],strlen(_Context->msg_Auto2756[_Context->language]),258);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto2749+20,_Context->y_Auto2749+110,680+2,160+2,5);
	visual_text(_Context->x_Auto2749+20+1,_Context->y_Auto2749+110+1,680,160,vfh[1],16,0,_Context->buffer_Italiano,850,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto2749+20,_Context->y_Auto2749+300,680+2,160+2,5);
	visual_text(_Context->x_Auto2749+20+1,_Context->y_Auto2749+300+1,680,160,vfh[1],16,0,_Context->buffer_HintItaliano,850,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_TabEspagnol=visual_trigger_code(_Context->msg_TabEspagnol[_Context->language],strlen(_Context->msg_TabEspagnol[_Context->language]));
	visual_tabpage(_Context->x_Auto2749+10,_Context->y_Auto2749+50,710,430,vfh[2],_Context->msg_TabEspagnol[_Context->language],strlen(_Context->msg_TabEspagnol[_Context->language]),250,34);
	} else {
		visual_tabpage(_Context->x_Auto2749+10,_Context->y_Auto2749+50,710,430,vfh[2],_Context->msg_TabEspagnol[_Context->language],strlen(_Context->msg_TabEspagnol[_Context->language]),250,32);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto2749+20,_Context->y_Auto2749+110,680+2,160+2,5);
	visual_text(_Context->x_Auto2749+20+1,_Context->y_Auto2749+110+1,680,160,vfh[1],16,0,_Context->buffer_Espagnol,850,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto2749+20,_Context->y_Auto2749+300,680+2,160+2,5);
	visual_text(_Context->x_Auto2749+20+1,_Context->y_Auto2749+300+1,680,160,vfh[1],16,0,_Context->buffer_HintEspagnol,850,0);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto2749+20,_Context->y_Auto2749+90,140,16,vfh[2],16,0,_Context->msg_Auto2757[_Context->language],strlen(_Context->msg_Auto2757[_Context->language]),258);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto2749+20,_Context->y_Auto2749+280,140,16,vfh[2],16,0,_Context->msg_Auto2758[_Context->language],strlen(_Context->msg_Auto2758[_Context->language]),258);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_TabDeutsch=visual_trigger_code(_Context->msg_TabDeutsch[_Context->language],strlen(_Context->msg_TabDeutsch[_Context->language]));
	visual_tabpage(_Context->x_Auto2749+10,_Context->y_Auto2749+50,710,430,vfh[2],_Context->msg_TabDeutsch[_Context->language],strlen(_Context->msg_TabDeutsch[_Context->language]),342,34);
	} else {
		visual_tabpage(_Context->x_Auto2749+10,_Context->y_Auto2749+50,710,430,vfh[2],_Context->msg_TabDeutsch[_Context->language],strlen(_Context->msg_TabDeutsch[_Context->language]),342,32);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto2749+20,_Context->y_Auto2749+90,140,16,vfh[2],16,0,_Context->msg_Auto2759[_Context->language],strlen(_Context->msg_Auto2759[_Context->language]),258);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto2749+20,_Context->y_Auto2749+280,140,16,vfh[2],16,0,_Context->msg_Auto2760[_Context->language],strlen(_Context->msg_Auto2760[_Context->language]),258);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto2749+20,_Context->y_Auto2749+110,680+2,160+2,5);
	visual_text(_Context->x_Auto2749+20+1,_Context->y_Auto2749+110+1,680,160,vfh[1],16,0,_Context->buffer_Deutsch,850,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto2749+20,_Context->y_Auto2749+300,680+2,160+2,5);
	visual_text(_Context->x_Auto2749+20+1,_Context->y_Auto2749+300+1,680,160,vfh[1],16,0,_Context->buffer_HintDeutsch,850,0);
		}
	if (_Context->page_number == 6 ) {
	_Context->trigger_TabNederlands=visual_trigger_code(_Context->msg_TabNederlands[_Context->language],strlen(_Context->msg_TabNederlands[_Context->language]));
	visual_tabpage(_Context->x_Auto2749+10,_Context->y_Auto2749+50,710,430,vfh[2],_Context->msg_TabNederlands[_Context->language],strlen(_Context->msg_TabNederlands[_Context->language]),429,34);
	} else {
		visual_tabpage(_Context->x_Auto2749+10,_Context->y_Auto2749+50,710,430,vfh[2],_Context->msg_TabNederlands[_Context->language],strlen(_Context->msg_TabNederlands[_Context->language]),429,32);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto2749+20,_Context->y_Auto2749+90,140,16,vfh[2],16,0,_Context->msg_Auto2761[_Context->language],strlen(_Context->msg_Auto2761[_Context->language]),258);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto2749+20,_Context->y_Auto2749+280,140,16,vfh[2],16,0,_Context->msg_Auto2762[_Context->language],strlen(_Context->msg_Auto2762[_Context->language]),258);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto2749+20,_Context->y_Auto2749+110,680+2,160+2,5);
	visual_text(_Context->x_Auto2749+20+1,_Context->y_Auto2749+110+1,680,160,vfh[1],16,0,_Context->buffer_Nederlands,850,0);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto2749+20,_Context->y_Auto2749+300,680+2,160+2,5);
	visual_text(_Context->x_Auto2749+20+1,_Context->y_Auto2749+300+1,680,160,vfh[1],16,0,_Context->buffer_HintNederlands,850,0);
		}
	if (_Context->page_number == 7 ) {
	_Context->trigger_TabPortugues=visual_trigger_code(_Context->msg_TabPortugues[_Context->language],strlen(_Context->msg_TabPortugues[_Context->language]));
	visual_tabpage(_Context->x_Auto2749+10,_Context->y_Auto2749+50,710,430,vfh[2],_Context->msg_TabPortugues[_Context->language],strlen(_Context->msg_TabPortugues[_Context->language]),533,34);
	} else {
		visual_tabpage(_Context->x_Auto2749+10,_Context->y_Auto2749+50,710,430,vfh[2],_Context->msg_TabPortugues[_Context->language],strlen(_Context->msg_TabPortugues[_Context->language]),533,32);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto2749+20,_Context->y_Auto2749+90,140,16,vfh[2],16,0,_Context->msg_Auto2763[_Context->language],strlen(_Context->msg_Auto2763[_Context->language]),258);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto2749+20,_Context->y_Auto2749+280,140,16,vfh[2],16,0,_Context->msg_Auto2764[_Context->language],strlen(_Context->msg_Auto2764[_Context->language]),258);
		}
	if (_Context->page_number == 7 ) {
	visual_frame(_Context->x_Auto2749+20,_Context->y_Auto2749+110,680+2,160+2,5);
	visual_text(_Context->x_Auto2749+20+1,_Context->y_Auto2749+110+1,680,160,vfh[1],16,0,_Context->buffer_Portugues,850,0);
		}
	if (_Context->page_number == 7 ) {
	visual_frame(_Context->x_Auto2749+20,_Context->y_Auto2749+300,680+2,160+2,5);
	visual_text(_Context->x_Auto2749+20+1,_Context->y_Auto2749+300+1,680,160,vfh[1],16,0,_Context->buffer_HintPortugues,850,0);
		}
	if (_Context->page_number == 8 ) {
	_Context->trigger_TabOther=visual_trigger_code(_Context->msg_TabOther[_Context->language],strlen(_Context->msg_TabOther[_Context->language]));
	visual_tabpage(_Context->x_Auto2749+10,_Context->y_Auto2749+50,710,430,vfh[2],_Context->msg_TabOther[_Context->language],strlen(_Context->msg_TabOther[_Context->language]),632,34);
	} else {
		visual_tabpage(_Context->x_Auto2749+10,_Context->y_Auto2749+50,710,430,vfh[2],_Context->msg_TabOther[_Context->language],strlen(_Context->msg_TabOther[_Context->language]),632,32);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto2749+20,_Context->y_Auto2749+90,140,16,vfh[2],16,0,_Context->msg_Auto2765[_Context->language],strlen(_Context->msg_Auto2765[_Context->language]),258);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto2749+20,_Context->y_Auto2749+280,140,16,vfh[2],16,0,_Context->msg_Auto2766[_Context->language],strlen(_Context->msg_Auto2766[_Context->language]),258);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(_Context->x_Auto2749+20,_Context->y_Auto2749+110,680+2,160+2,5);
	visual_text(_Context->x_Auto2749+20+1,_Context->y_Auto2749+110+1,680,160,vfh[1],16,0,_Context->buffer_Other,850,0);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(_Context->x_Auto2749+20,_Context->y_Auto2749+300,680+2,160+2,5);
	visual_text(_Context->x_Auto2749+20+1,_Context->y_Auto2749+300+1,680,160,vfh[1],16,0,_Context->buffer_HintOther,850,0);
		}
	_Context->trigger_Auto2767=visual_trigger_code(_Context->msg_Auto2767[_Context->language],strlen(_Context->msg_Auto2767[_Context->language]));
	visual_button(_Context->x_Auto2749+10,_Context->y_Auto2749+490,56,48,vfh[2],34,0,_Context->msg_Auto2767[_Context->language],strlen(_Context->msg_Auto2767[_Context->language]),1040);
	_Context->trigger_Reset=visual_trigger_code(_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]));
	visual_button(_Context->x_Auto2749+380,_Context->y_Auto2749+490,136,32,vfh[2],0,0,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),0);
	_Context->trigger_Copy=visual_trigger_code(_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]));
	visual_button(_Context->x_Auto2749+220,_Context->y_Auto2749+490,136,32,vfh[2],0,0,_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]),0);
	_Context->trigger_Auto2768=visual_trigger_code(_Context->msg_Auto2768[_Context->language],strlen(_Context->msg_Auto2768[_Context->language]));
	visual_button(_Context->x_Auto2749+660,_Context->y_Auto2749+490,56,48,vfh[2],34,0,_Context->msg_Auto2768[_Context->language],strlen(_Context->msg_Auto2768[_Context->language]),1040);
	visual_thaw(_Context->x_Auto2749,_Context->y_Auto2749,730,550);

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

private int Auto2767_help()
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

private int Auto2768_help()
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

private int Auto2749action(struct accept_widget_messages_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_widget_messages_hide(_Context);

		_Context->x_Auto2749 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto2749 < 0) { _Context->x_Auto2749=0; }
		_Context->y_Auto2749 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto2749 < 0) { _Context->y_Auto2749=0; }
			accept_widget_messages_show(_Context);

		visual_thaw(_Context->x_Auto2749,_Context->y_Auto2749,730,550);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto2767_event(struct accept_widget_messages_context * _Context) {
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
private int on_Auto2768_event(struct accept_widget_messages_context * _Context) {
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
		if (_Context->trigger_Auto2767 == mb ) return(26);
		if (_Context->trigger_Reset == mb ) return(27);
		if (_Context->trigger_Copy == mb ) return(28);
		if (_Context->trigger_Auto2768 == mb ) return(29);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto2749+709) )  
	&&  (my >= (_Context->y_Auto2749+4) )  
	&&  (mx <= (_Context->x_Auto2749+726) )  
	&&  (my <= (_Context->y_Auto2749+20) )) {
		return(1);	/* Auto2749 */

		}
	if ((mx >= (_Context->x_Auto2749+693) )  
	&&  (my >= (_Context->y_Auto2749+4) )  
	&&  (mx <= (_Context->x_Auto2749+710) )  
	&&  (my <= (_Context->y_Auto2749+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vnation.htm");
			};
		return(-1);	/* Auto2749 */

		}
	if ((mx >= (_Context->x_Auto2749+677) )  
	&&  (my >= (_Context->y_Auto2749+4) )  
	&&  (mx <= (_Context->x_Auto2749+694) )  
	&&  (my <= (_Context->y_Auto2749+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_widget_messages_show(_Context);
		return(-1);	/* Auto2749 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto2749+4) )  
		&&  (my >= (_Context->y_Auto2749+4) )  
		&&  (mx <= (_Context->x_Auto2749+662) )  
		&&  (my <= (_Context->y_Auto2749+20) )) {
			return( Auto2749action(_Context) );
			}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto2749+10+0) ) 
		&&  ( my >= (_Context->y_Auto2749+50) ) 
		&&  ( mx <= (_Context->x_Auto2749+10+80) ) 
		&&  ( my <= (_Context->y_Auto2749+50+24))) {
			return(2); /* TabEnglish */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto2749+20) ) 
		&&  ( my >= (_Context->y_Auto2749+110) ) 
		&&  ( mx <= (_Context->x_Auto2749+20+680) ) 
		&&  ( my <= (_Context->y_Auto2749+110+160))) {
			return(3); /* English */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto2749+20) ) 
		&&  ( my >= (_Context->y_Auto2749+300) ) 
		&&  ( mx <= (_Context->x_Auto2749+20+680) ) 
		&&  ( my <= (_Context->y_Auto2749+300+160))) {
			return(4); /* HintEnglish */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto2749+10+81) ) 
		&&  ( my >= (_Context->y_Auto2749+50) ) 
		&&  ( mx <= (_Context->x_Auto2749+10+169) ) 
		&&  ( my <= (_Context->y_Auto2749+50+24))) {
			return(5); /* TabFrancais */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto2749+20) ) 
		&&  ( my >= (_Context->y_Auto2749+110) ) 
		&&  ( mx <= (_Context->x_Auto2749+20+680) ) 
		&&  ( my <= (_Context->y_Auto2749+110+160))) {
			return(6); /* Francais */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto2749+20) ) 
		&&  ( my >= (_Context->y_Auto2749+300) ) 
		&&  ( mx <= (_Context->x_Auto2749+20+680) ) 
		&&  ( my <= (_Context->y_Auto2749+300+160))) {
			return(7); /* HintFrancais */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_Auto2749+10+170) ) 
		&&  ( my >= (_Context->y_Auto2749+50) ) 
		&&  ( mx <= (_Context->x_Auto2749+10+249) ) 
		&&  ( my <= (_Context->y_Auto2749+50+24))) {
			return(8); /* TabItaliano */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto2749+20) ) 
		&&  ( my >= (_Context->y_Auto2749+110) ) 
		&&  ( mx <= (_Context->x_Auto2749+20+680) ) 
		&&  ( my <= (_Context->y_Auto2749+110+160))) {
			return(9); /* Italiano */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto2749+20) ) 
		&&  ( my >= (_Context->y_Auto2749+300) ) 
		&&  ( mx <= (_Context->x_Auto2749+20+680) ) 
		&&  ( my <= (_Context->y_Auto2749+300+160))) {
			return(10); /* HintItaliano */
			}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if (( mx >= (_Context->x_Auto2749+10+250) ) 
		&&  ( my >= (_Context->y_Auto2749+50) ) 
		&&  ( mx <= (_Context->x_Auto2749+10+341) ) 
		&&  ( my <= (_Context->y_Auto2749+50+24))) {
			return(11); /* TabEspagnol */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto2749+20) ) 
		&&  ( my >= (_Context->y_Auto2749+110) ) 
		&&  ( mx <= (_Context->x_Auto2749+20+680) ) 
		&&  ( my <= (_Context->y_Auto2749+110+160))) {
			return(12); /* Espagnol */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto2749+20) ) 
		&&  ( my >= (_Context->y_Auto2749+300) ) 
		&&  ( mx <= (_Context->x_Auto2749+20+680) ) 
		&&  ( my <= (_Context->y_Auto2749+300+160))) {
			return(13); /* HintEspagnol */
			}
		}
	if (_Context->page_number == 5 ) {
	} else {
		if (( mx >= (_Context->x_Auto2749+10+342) ) 
		&&  ( my >= (_Context->y_Auto2749+50) ) 
		&&  ( mx <= (_Context->x_Auto2749+10+428) ) 
		&&  ( my <= (_Context->y_Auto2749+50+24))) {
			return(14); /* TabDeutsch */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto2749+20) ) 
		&&  ( my >= (_Context->y_Auto2749+110) ) 
		&&  ( mx <= (_Context->x_Auto2749+20+680) ) 
		&&  ( my <= (_Context->y_Auto2749+110+160))) {
			return(15); /* Deutsch */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto2749+20) ) 
		&&  ( my >= (_Context->y_Auto2749+300) ) 
		&&  ( mx <= (_Context->x_Auto2749+20+680) ) 
		&&  ( my <= (_Context->y_Auto2749+300+160))) {
			return(16); /* HintDeutsch */
			}
		}
	if (_Context->page_number == 6 ) {
	} else {
		if (( mx >= (_Context->x_Auto2749+10+429) ) 
		&&  ( my >= (_Context->y_Auto2749+50) ) 
		&&  ( mx <= (_Context->x_Auto2749+10+532) ) 
		&&  ( my <= (_Context->y_Auto2749+50+24))) {
			return(17); /* TabNederlands */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto2749+20) ) 
		&&  ( my >= (_Context->y_Auto2749+110) ) 
		&&  ( mx <= (_Context->x_Auto2749+20+680) ) 
		&&  ( my <= (_Context->y_Auto2749+110+160))) {
			return(18); /* Nederlands */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto2749+20) ) 
		&&  ( my >= (_Context->y_Auto2749+300) ) 
		&&  ( mx <= (_Context->x_Auto2749+20+680) ) 
		&&  ( my <= (_Context->y_Auto2749+300+160))) {
			return(19); /* HintNederlands */
			}
		}
	if (_Context->page_number == 7 ) {
	} else {
		if (( mx >= (_Context->x_Auto2749+10+533) ) 
		&&  ( my >= (_Context->y_Auto2749+50) ) 
		&&  ( mx <= (_Context->x_Auto2749+10+631) ) 
		&&  ( my <= (_Context->y_Auto2749+50+24))) {
			return(20); /* TabPortugues */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto2749+20) ) 
		&&  ( my >= (_Context->y_Auto2749+110) ) 
		&&  ( mx <= (_Context->x_Auto2749+20+680) ) 
		&&  ( my <= (_Context->y_Auto2749+110+160))) {
			return(21); /* Portugues */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto2749+20) ) 
		&&  ( my >= (_Context->y_Auto2749+300) ) 
		&&  ( mx <= (_Context->x_Auto2749+20+680) ) 
		&&  ( my <= (_Context->y_Auto2749+300+160))) {
			return(22); /* HintPortugues */
			}
		}
	if (_Context->page_number == 8 ) {
	} else {
		if (( mx >= (_Context->x_Auto2749+10+632) ) 
		&&  ( my >= (_Context->y_Auto2749+50) ) 
		&&  ( mx <= (_Context->x_Auto2749+10+704) ) 
		&&  ( my <= (_Context->y_Auto2749+50+24))) {
			return(23); /* TabOther */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto2749+20) ) 
		&&  ( my >= (_Context->y_Auto2749+110) ) 
		&&  ( mx <= (_Context->x_Auto2749+20+680) ) 
		&&  ( my <= (_Context->y_Auto2749+110+160))) {
			return(24); /* Other */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto2749+20) ) 
		&&  ( my >= (_Context->y_Auto2749+300) ) 
		&&  ( mx <= (_Context->x_Auto2749+20+680) ) 
		&&  ( my <= (_Context->y_Auto2749+300+160))) {
			return(25); /* HintOther */
			}
		}
	if (( mx >= (_Context->x_Auto2749+10) ) 
	&&  ( my >= (_Context->y_Auto2749+490) ) 
	&&  ( mx <= (_Context->x_Auto2749+10+56) ) 
	&&  ( my <= (_Context->y_Auto2749+490+48))) {
		return(26); /* Auto2767 */
		}
	if (( mx >= (_Context->x_Auto2749+380) ) 
	&&  ( my >= (_Context->y_Auto2749+490) ) 
	&&  ( mx <= (_Context->x_Auto2749+380+136) ) 
	&&  ( my <= (_Context->y_Auto2749+490+32))) {
		return(27); /* Reset */
		}
	if (( mx >= (_Context->x_Auto2749+220) ) 
	&&  ( my >= (_Context->y_Auto2749+490) ) 
	&&  ( mx <= (_Context->x_Auto2749+220+136) ) 
	&&  ( my <= (_Context->y_Auto2749+490+32))) {
		return(28); /* Copy */
		}
	if (( mx >= (_Context->x_Auto2749+660) ) 
	&&  ( my >= (_Context->y_Auto2749+490) ) 
	&&  ( mx <= (_Context->x_Auto2749+660+56) ) 
	&&  ( my <= (_Context->y_Auto2749+490+48))) {
		return(29); /* Auto2768 */
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
					_Context->keycode = visual_edit(_Context->x_Auto2749+20+1,_Context->y_Auto2749+110+1,680,160,vfh[1],_Context->buffer_English,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* HintEnglish */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto2749+20+1,_Context->y_Auto2749+300+1,680,160,vfh[1],_Context->buffer_HintEnglish,850);
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
					_Context->keycode = visual_edit(_Context->x_Auto2749+20+1,_Context->y_Auto2749+110+1,680,160,vfh[1],_Context->buffer_Francais,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* HintFrancais */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto2749+20+1,_Context->y_Auto2749+300+1,680,160,vfh[1],_Context->buffer_HintFrancais,850);
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
					_Context->keycode = visual_edit(_Context->x_Auto2749+20+1,_Context->y_Auto2749+110+1,680,160,vfh[1],_Context->buffer_Italiano,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* HintItaliano */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto2749+20+1,_Context->y_Auto2749+300+1,680,160,vfh[1],_Context->buffer_HintItaliano,850);
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
					_Context->keycode = visual_edit(_Context->x_Auto2749+20+1,_Context->y_Auto2749+110+1,680,160,vfh[1],_Context->buffer_Espagnol,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* HintEspagnol */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto2749+20+1,_Context->y_Auto2749+300+1,680,160,vfh[1],_Context->buffer_HintEspagnol,850);
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
					_Context->keycode = visual_edit(_Context->x_Auto2749+20+1,_Context->y_Auto2749+110+1,680,160,vfh[1],_Context->buffer_Deutsch,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* HintDeutsch */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto2749+20+1,_Context->y_Auto2749+300+1,680,160,vfh[1],_Context->buffer_HintDeutsch,850);
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
					_Context->keycode = visual_edit(_Context->x_Auto2749+20+1,_Context->y_Auto2749+110+1,680,160,vfh[1],_Context->buffer_Nederlands,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* HintNederlands */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_edit(_Context->x_Auto2749+20+1,_Context->y_Auto2749+300+1,680,160,vfh[1],_Context->buffer_HintNederlands,850);
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
					_Context->keycode = visual_edit(_Context->x_Auto2749+20+1,_Context->y_Auto2749+110+1,680,160,vfh[1],_Context->buffer_Portugues,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* HintPortugues */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_edit(_Context->x_Auto2749+20+1,_Context->y_Auto2749+300+1,680,160,vfh[1],_Context->buffer_HintPortugues,850);
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
					_Context->keycode = visual_edit(_Context->x_Auto2749+20+1,_Context->y_Auto2749+110+1,680,160,vfh[1],_Context->buffer_Other,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* HintOther */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_edit(_Context->x_Auto2749+20+1,_Context->y_Auto2749+300+1,680,160,vfh[1],_Context->buffer_HintOther,850);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* Auto2767 */
				_Context->trigger_Auto2767=visual_trigger_code(_Context->msg_Auto2767[_Context->language],strlen(_Context->msg_Auto2767[_Context->language]));
				visual_button(_Context->x_Auto2749+10,_Context->y_Auto2749+490,56,48,vfh[2],34,0,_Context->msg_Auto2767[_Context->language],strlen(_Context->msg_Auto2767[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2767=visual_trigger_code(_Context->msg_Auto2767[_Context->language],strlen(_Context->msg_Auto2767[_Context->language]));
	visual_button(_Context->x_Auto2749+10,_Context->y_Auto2749+490,56,48,vfh[2],34,0,_Context->msg_Auto2767[_Context->language],strlen(_Context->msg_Auto2767[_Context->language]),1040);
				break;
			case	0x1b :
				/* Reset */
				_Context->trigger_Reset=visual_trigger_code(_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]));
				visual_button(_Context->x_Auto2749+380,_Context->y_Auto2749+490,136,32,vfh[2],0,0,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Reset=visual_trigger_code(_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]));
	visual_button(_Context->x_Auto2749+380,_Context->y_Auto2749+490,136,32,vfh[2],0,0,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),0);
				break;
			case	0x1c :
				/* Copy */
				_Context->trigger_Copy=visual_trigger_code(_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]));
				visual_button(_Context->x_Auto2749+220,_Context->y_Auto2749+490,136,32,vfh[2],0,0,_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Copy=visual_trigger_code(_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]));
	visual_button(_Context->x_Auto2749+220,_Context->y_Auto2749+490,136,32,vfh[2],0,0,_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]),0);
				break;
			case	0x1d :
				/* Auto2768 */
				_Context->trigger_Auto2768=visual_trigger_code(_Context->msg_Auto2768[_Context->language],strlen(_Context->msg_Auto2768[_Context->language]));
				visual_button(_Context->x_Auto2749+660,_Context->y_Auto2749+490,56,48,vfh[2],34,0,_Context->msg_Auto2768[_Context->language],strlen(_Context->msg_Auto2768[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2768=visual_trigger_code(_Context->msg_Auto2768[_Context->language],strlen(_Context->msg_Auto2768[_Context->language]));
	visual_button(_Context->x_Auto2749+660,_Context->y_Auto2749+490,56,48,vfh[2],34,0,_Context->msg_Auto2768[_Context->language],strlen(_Context->msg_Auto2768[_Context->language]),1040);
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
						if (Auto2767_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1b :
						if (Reset_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1c :
						if (Copy_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1d :
						if (Auto2768_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto2749 */
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
					/* Auto2767 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2767=visual_trigger_code(_Context->msg_Auto2767[_Context->language],strlen(_Context->msg_Auto2767[_Context->language]));
						visual_button(_Context->x_Auto2749+10,_Context->y_Auto2749+490,56,48,vfh[2],34,0,_Context->msg_Auto2767[_Context->language],strlen(_Context->msg_Auto2767[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2767=visual_trigger_code(_Context->msg_Auto2767[_Context->language],strlen(_Context->msg_Auto2767[_Context->language]));
	visual_button(_Context->x_Auto2749+10,_Context->y_Auto2749+490,56,48,vfh[2],34,0,_Context->msg_Auto2767[_Context->language],strlen(_Context->msg_Auto2767[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2767_event(_Context)) != -1) break;

						}
					continue;
				case	0x1b :
					/* Reset */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Reset=visual_trigger_code(_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]));
						visual_button(_Context->x_Auto2749+380,_Context->y_Auto2749+490,136,32,vfh[2],0,0,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Reset=visual_trigger_code(_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]));
	visual_button(_Context->x_Auto2749+380,_Context->y_Auto2749+490,136,32,vfh[2],0,0,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Reset_event(_Context)) != -1) break;

						}
					continue;
				case	0x1c :
					/* Copy */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Copy=visual_trigger_code(_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]));
						visual_button(_Context->x_Auto2749+220,_Context->y_Auto2749+490,136,32,vfh[2],0,0,_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Copy=visual_trigger_code(_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]));
	visual_button(_Context->x_Auto2749+220,_Context->y_Auto2749+490,136,32,vfh[2],0,0,_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Copy_event(_Context)) != -1) break;

						}
					continue;
				case	0x1d :
					/* Auto2768 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2768=visual_trigger_code(_Context->msg_Auto2768[_Context->language],strlen(_Context->msg_Auto2768[_Context->language]));
						visual_button(_Context->x_Auto2749+660,_Context->y_Auto2749+490,56,48,vfh[2],34,0,_Context->msg_Auto2768[_Context->language],strlen(_Context->msg_Auto2768[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2768=visual_trigger_code(_Context->msg_Auto2768[_Context->language],strlen(_Context->msg_Auto2768[_Context->language]));
	visual_button(_Context->x_Auto2749+660,_Context->y_Auto2749+490,56,48,vfh[2],34,0,_Context->msg_Auto2768[_Context->language],strlen(_Context->msg_Auto2768[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2768_event(_Context)) != -1) break;

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
