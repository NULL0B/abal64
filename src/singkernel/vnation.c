
#ifndef _vnation_c
#define _vnation_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vnation.xml  */
/* Target         : vnation.c  */
/* Identification : 0.0-1100085348-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto6300   "Sing : Version 1.0a"
#define fr_Auto6300   "Sing : Version 1.0a"
#define it_Auto6300   "Sing : Version 1.0a"
#define es_Auto6300   "Sing : Version 1.0a"
#define de_Auto6300   "Sing : Version 1.0a"
#define nl_Auto6300   "Sing : Version 1.0a"
#define pt_Auto6300   "Sing : Version 1.0a"
#define xx_Auto6300   "Sing : Version 1.0a"
#define en_Auto6312   "skin.gif"
#define fr_Auto6312   "skin.gif"
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define xx_Accept   "&Tha gu math"
#define en_Copy   "&Copy"
#define fr_Copy   "&Copier"
#define xx_Copy   "&Leth-Breac"
#define en_Reset   "&Reset"
#define fr_Reset   "&Copier"
#define xx_Reset   "&Leth-Breac"
#define en_Cancel   "Ca&ncel"
#define fr_Cancel   "&Annuler"
#define xx_Cancel   "Cha&n Eil"
#define en_Auto6313   "International Message Editor"
#define fr_Auto6313   "Editeur des Messages Multi-Nationale"
#define en_TabEnglish   "&English"
#define fr_TabEnglish   "&English"
#define it_TabEnglish   "English"
#define es_TabEnglish   "English"
#define de_TabEnglish   "English"
#define nl_TabEnglish   "English"
#define pt_TabEnglish   "English"
#define xx_TabEnglish   "English"
#define en_TabFrancais   "&Fran‡ais"
#define fr_TabFrancais   "&Fran‡ais"
#define it_TabFrancais   "Fran‡ais"
#define es_TabFrancais   "Fran‡ais"
#define de_TabFrancais   "Fran‡ais"
#define nl_TabFrancais   "Fran‡ais"
#define pt_TabFrancais   "Fran‡ais"
#define xx_TabFrancais   "Fran‡ais"
#define en_TabItaliano   "&Italiano"
#define fr_TabItaliano   "&Italiano"
#define it_TabItaliano   "Italiano"
#define es_TabItaliano   "Italiano"
#define de_TabItaliano   "Italiano"
#define nl_TabItaliano   "Italiano"
#define pt_TabItaliano   "Italiano"
#define xx_TabItaliano   "Italiano"
#define en_TabEspagnol   "E&spagnol"
#define fr_TabEspagnol   "E&spagnol"
#define it_TabEspagnol   "Espagnol"
#define es_TabEspagnol   "Espagnol"
#define de_TabEspagnol   "Espagnol"
#define nl_TabEspagnol   "Espagnol"
#define pt_TabEspagnol   "Espagnol"
#define xx_TabEspagnol   "Espagnol"
#define en_TabDeutsch   "&Deutsch"
#define fr_TabDeutsch   "&Deutsch"
#define it_TabDeutsch   "Deutsch"
#define es_TabDeutsch   "Deutsch"
#define de_TabDeutsch   "Deutsch"
#define nl_TabDeutsch   "Deutsch"
#define pt_TabDeutsch   "Deutsch"
#define xx_TabDeutsch   "Deutsch"
#define en_TabNederlands   "Nede&rlands"
#define fr_TabNederlands   "&Nederlands"
#define it_TabNederlands   "Nederlands"
#define es_TabNederlands   "Nederlands"
#define de_TabNederlands   "Nederlands"
#define nl_TabNederlands   "Nederlands"
#define pt_TabNederlands   "Nederlands"
#define xx_TabNederlands   "Nederlands"
#define en_TabPortugues   "&Portugues"
#define fr_TabPortugues   "&Portugues"
#define it_TabPortugues   "Portugues"
#define es_TabPortugues   "Portugues"
#define de_TabPortugues   "Portugues"
#define nl_TabPortugues   "Portugues"
#define pt_TabPortugues   "Portugues"
#define xx_TabPortugues   "Portugues"
#define en_TabOther   "&Other"
#define fr_TabOther   "A&utre"
#define it_TabOther   "Other"
#define es_TabOther   "Other"
#define de_TabOther   "Andere"
#define nl_TabOther   "Other"
#define pt_TabOther   "Other"
#define xx_TabOther   "Eile"
static int	vfh[10];

private struct accept_widget_messages_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[8+1];
	char * msg_Auto6300[8];
	int	x_Auto6300;
	int	y_Auto6300;
	int	w_Auto6300;
	int	h_Auto6300;
	char * msg_Auto6312[8];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Copy[8];
	int	trigger_Copy;
	char * msg_Reset[8];
	int	trigger_Reset;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * msg_Auto6313[8];
	char * msg_TabEnglish[8];
	int	trigger_TabEnglish;
	int	page_number;
	char	buffer_English[1979];
	char * msg_TabFrancais[8];
	int	trigger_TabFrancais;
	char	buffer_Francais[1979];
	char * msg_TabItaliano[8];
	int	trigger_TabItaliano;
	char	buffer_Italiano[1979];
	char * msg_TabEspagnol[8];
	int	trigger_TabEspagnol;
	char	buffer_Espagnol[1979];
	char * msg_TabDeutsch[8];
	int	trigger_TabDeutsch;
	char	buffer_Deutsch[1979];
	char * msg_TabNederlands[8];
	int	trigger_TabNederlands;
	char	buffer_Nederlands[1979];
	char * msg_TabPortugues[8];
	int	trigger_TabPortugues;
	char	buffer_Portugues[1979];
	char * msg_TabOther[8];
	int	trigger_TabOther;
	char	buffer_Other[1979];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[9];
	};

public	int	accept_widget_messages_create(
	struct accept_widget_messages_context ** cptr,
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
	struct accept_widget_messages_context * _Context=(struct accept_widget_messages_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_widget_messages_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=21;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_English, 1978, pEnglish);
		visual_transferin(_Context->buffer_Francais, 1978, pFrancais);
		visual_transferin(_Context->buffer_Italiano, 1978, pItaliano);
		visual_transferin(_Context->buffer_Espagnol, 1978, pEspagnol);
		visual_transferin(_Context->buffer_Deutsch, 1978, pDeutsch);
		visual_transferin(_Context->buffer_Nederlands, 1978, pNederlands);
		visual_transferin(_Context->buffer_Portugues, 1978, pPortugues);
		visual_transferin(_Context->buffer_Other, 1978, pOther);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto6300[i]=" ";
	_Context->msg_Auto6300[0]=en_Auto6300;
	_Context->msg_Auto6300[1]=fr_Auto6300;
	_Context->msg_Auto6300[2]=it_Auto6300;
	_Context->msg_Auto6300[3]=es_Auto6300;
	_Context->msg_Auto6300[4]=de_Auto6300;
	_Context->msg_Auto6300[5]=nl_Auto6300;
	_Context->msg_Auto6300[6]=pt_Auto6300;
	_Context->msg_Auto6300[7]=xx_Auto6300;
	_Context->x_Auto6300=35;
	_Context->y_Auto6300=35;
	_Context->w_Auto6300=730;
	_Context->h_Auto6300=530;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto6312[i]=" ";
	_Context->msg_Auto6312[0]=en_Auto6312;
	_Context->msg_Auto6312[1]=fr_Auto6312;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	for (i=0; i < 8; i++)_Context->msg_Copy[i]=" ";
	_Context->msg_Copy[0]=en_Copy;
	_Context->msg_Copy[1]=fr_Copy;
	_Context->msg_Copy[7]=xx_Copy;
	for (i=0; i < 8; i++)_Context->msg_Reset[i]=" ";
	_Context->msg_Reset[0]=en_Reset;
	_Context->msg_Reset[1]=fr_Reset;
	_Context->msg_Reset[7]=xx_Reset;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->msg_Cancel[7]=xx_Cancel;
	for (i=0; i < 8; i++)_Context->msg_Auto6313[i]=" ";
	_Context->msg_Auto6313[0]=en_Auto6313;
	_Context->msg_Auto6313[1]=fr_Auto6313;
	for (i=0; i < 8; i++)_Context->msg_TabEnglish[i]=" ";
	_Context->msg_TabEnglish[0]=en_TabEnglish;
	_Context->msg_TabEnglish[1]=fr_TabEnglish;
	_Context->msg_TabEnglish[2]=it_TabEnglish;
	_Context->msg_TabEnglish[3]=es_TabEnglish;
	_Context->msg_TabEnglish[4]=de_TabEnglish;
	_Context->msg_TabEnglish[5]=nl_TabEnglish;
	_Context->msg_TabEnglish[6]=pt_TabEnglish;
	_Context->msg_TabEnglish[7]=xx_TabEnglish;
	_Context->focus_pages[1]=6;
	for (i=0; i < 8; i++)_Context->msg_TabFrancais[i]=" ";
	_Context->msg_TabFrancais[0]=en_TabFrancais;
	_Context->msg_TabFrancais[1]=fr_TabFrancais;
	_Context->msg_TabFrancais[2]=it_TabFrancais;
	_Context->msg_TabFrancais[3]=es_TabFrancais;
	_Context->msg_TabFrancais[4]=de_TabFrancais;
	_Context->msg_TabFrancais[5]=nl_TabFrancais;
	_Context->msg_TabFrancais[6]=pt_TabFrancais;
	_Context->msg_TabFrancais[7]=xx_TabFrancais;
	_Context->focus_pages[2]=8;
	for (i=0; i < 8; i++)_Context->msg_TabItaliano[i]=" ";
	_Context->msg_TabItaliano[0]=en_TabItaliano;
	_Context->msg_TabItaliano[1]=fr_TabItaliano;
	_Context->msg_TabItaliano[2]=it_TabItaliano;
	_Context->msg_TabItaliano[3]=es_TabItaliano;
	_Context->msg_TabItaliano[4]=de_TabItaliano;
	_Context->msg_TabItaliano[5]=nl_TabItaliano;
	_Context->msg_TabItaliano[6]=pt_TabItaliano;
	_Context->msg_TabItaliano[7]=xx_TabItaliano;
	_Context->focus_pages[3]=10;
	for (i=0; i < 8; i++)_Context->msg_TabEspagnol[i]=" ";
	_Context->msg_TabEspagnol[0]=en_TabEspagnol;
	_Context->msg_TabEspagnol[1]=fr_TabEspagnol;
	_Context->msg_TabEspagnol[2]=it_TabEspagnol;
	_Context->msg_TabEspagnol[3]=es_TabEspagnol;
	_Context->msg_TabEspagnol[4]=de_TabEspagnol;
	_Context->msg_TabEspagnol[5]=nl_TabEspagnol;
	_Context->msg_TabEspagnol[6]=pt_TabEspagnol;
	_Context->msg_TabEspagnol[7]=xx_TabEspagnol;
	_Context->focus_pages[4]=12;
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
	for (i=0; i < 8; i++)_Context->msg_TabNederlands[i]=" ";
	_Context->msg_TabNederlands[0]=en_TabNederlands;
	_Context->msg_TabNederlands[1]=fr_TabNederlands;
	_Context->msg_TabNederlands[2]=it_TabNederlands;
	_Context->msg_TabNederlands[3]=es_TabNederlands;
	_Context->msg_TabNederlands[4]=de_TabNederlands;
	_Context->msg_TabNederlands[5]=nl_TabNederlands;
	_Context->msg_TabNederlands[6]=pt_TabNederlands;
	_Context->msg_TabNederlands[7]=xx_TabNederlands;
	_Context->focus_pages[6]=16;
	for (i=0; i < 8; i++)_Context->msg_TabPortugues[i]=" ";
	_Context->msg_TabPortugues[0]=en_TabPortugues;
	_Context->msg_TabPortugues[1]=fr_TabPortugues;
	_Context->msg_TabPortugues[2]=it_TabPortugues;
	_Context->msg_TabPortugues[3]=es_TabPortugues;
	_Context->msg_TabPortugues[4]=de_TabPortugues;
	_Context->msg_TabPortugues[5]=nl_TabPortugues;
	_Context->msg_TabPortugues[6]=pt_TabPortugues;
	_Context->msg_TabPortugues[7]=xx_TabPortugues;
	_Context->focus_pages[7]=18;
	for (i=0; i < 8; i++)_Context->msg_TabOther[i]=" ";
	_Context->msg_TabOther[0]=en_TabOther;
	_Context->msg_TabOther[1]=fr_TabOther;
	_Context->msg_TabOther[2]=it_TabOther;
	_Context->msg_TabOther[3]=es_TabOther;
	_Context->msg_TabOther[4]=de_TabOther;
	_Context->msg_TabOther[5]=nl_TabOther;
	_Context->msg_TabOther[6]=pt_TabOther;
	_Context->msg_TabOther[7]=xx_TabOther;
	_Context->focus_pages[8]=20;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto6300,_Context->y_Auto6300,730+10,530+10);
	return(0);
}

public 	int	accept_widget_messages_hide(struct accept_widget_messages_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto6300,_Context->y_Auto6300);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_widget_messages_remove(
	struct accept_widget_messages_context * _Context,
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
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_English, 1978, pEnglish);
		visual_transferout(_Context->buffer_Francais, 1978, pFrancais);
		visual_transferout(_Context->buffer_Italiano, 1978, pItaliano);
		visual_transferout(_Context->buffer_Espagnol, 1978, pEspagnol);
		visual_transferout(_Context->buffer_Deutsch, 1978, pDeutsch);
		visual_transferout(_Context->buffer_Nederlands, 1978, pNederlands);
		visual_transferout(_Context->buffer_Portugues, 1978, pPortugues);
		visual_transferout(_Context->buffer_Other, 1978, pOther);
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
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto6300,_Context->y_Auto6300);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto6300,_Context->y_Auto6300,730,530,vfh[2],_Context->msg_Auto6300[_Context->language],strlen(_Context->msg_Auto6300[_Context->language]),0x407);
	visual_image(_Context->x_Auto6300+3,_Context->y_Auto6300+22,724,504,_Context->msg_Auto6312[_Context->language],4);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto6300+10,_Context->y_Auto6300+490,140,32,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Copy=visual_trigger_code(_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]));
	visual_button(_Context->x_Auto6300+190,_Context->y_Auto6300+490,136,32,vfh[2],0,0,_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]),0);
	_Context->trigger_Reset=visual_trigger_code(_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]));
	visual_button(_Context->x_Auto6300+360,_Context->y_Auto6300+490,136,32,vfh[2],0,0,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto6300+530,_Context->y_Auto6300+490,140,32,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_text(_Context->x_Auto6300+20,_Context->y_Auto6300+30,700,22,vfh[4],16,0,_Context->msg_Auto6313[_Context->language],strlen(_Context->msg_Auto6313[_Context->language]),1283);
	if (_Context->page_number == 1 ) {
	_Context->trigger_TabEnglish=visual_trigger_code(_Context->msg_TabEnglish[_Context->language],strlen(_Context->msg_TabEnglish[_Context->language]));
	visual_tabpage(_Context->x_Auto6300+10,_Context->y_Auto6300+50,710,430,vfh[2],_Context->msg_TabEnglish[_Context->language],strlen(_Context->msg_TabEnglish[_Context->language]),0,34);
	} else {
		visual_tabpage(_Context->x_Auto6300+10,_Context->y_Auto6300+50,710,430,vfh[2],_Context->msg_TabEnglish[_Context->language],strlen(_Context->msg_TabEnglish[_Context->language]),0,32);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto6300+20,_Context->y_Auto6300+90,688+2,368+2,5);
	visual_text(_Context->x_Auto6300+20+1,_Context->y_Auto6300+90+1,688,368,vfh[1],27,28,_Context->buffer_English,1978,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_TabFrancais=visual_trigger_code(_Context->msg_TabFrancais[_Context->language],strlen(_Context->msg_TabFrancais[_Context->language]));
	visual_tabpage(_Context->x_Auto6300+10,_Context->y_Auto6300+50,710,430,vfh[2],_Context->msg_TabFrancais[_Context->language],strlen(_Context->msg_TabFrancais[_Context->language]),81,34);
	} else {
		visual_tabpage(_Context->x_Auto6300+10,_Context->y_Auto6300+50,710,430,vfh[2],_Context->msg_TabFrancais[_Context->language],strlen(_Context->msg_TabFrancais[_Context->language]),81,32);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto6300+20,_Context->y_Auto6300+90,688+2,368+2,5);
	visual_text(_Context->x_Auto6300+20+1,_Context->y_Auto6300+90+1,688,368,vfh[1],16,0,_Context->buffer_Francais,1978,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_TabItaliano=visual_trigger_code(_Context->msg_TabItaliano[_Context->language],strlen(_Context->msg_TabItaliano[_Context->language]));
	visual_tabpage(_Context->x_Auto6300+10,_Context->y_Auto6300+50,710,430,vfh[2],_Context->msg_TabItaliano[_Context->language],strlen(_Context->msg_TabItaliano[_Context->language]),170,34);
	} else {
		visual_tabpage(_Context->x_Auto6300+10,_Context->y_Auto6300+50,710,430,vfh[2],_Context->msg_TabItaliano[_Context->language],strlen(_Context->msg_TabItaliano[_Context->language]),170,32);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto6300+20,_Context->y_Auto6300+90,688+2,368+2,5);
	visual_text(_Context->x_Auto6300+20+1,_Context->y_Auto6300+90+1,688,368,vfh[1],16,0,_Context->buffer_Italiano,1978,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_TabEspagnol=visual_trigger_code(_Context->msg_TabEspagnol[_Context->language],strlen(_Context->msg_TabEspagnol[_Context->language]));
	visual_tabpage(_Context->x_Auto6300+10,_Context->y_Auto6300+50,710,430,vfh[2],_Context->msg_TabEspagnol[_Context->language],strlen(_Context->msg_TabEspagnol[_Context->language]),250,34);
	} else {
		visual_tabpage(_Context->x_Auto6300+10,_Context->y_Auto6300+50,710,430,vfh[2],_Context->msg_TabEspagnol[_Context->language],strlen(_Context->msg_TabEspagnol[_Context->language]),250,32);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto6300+20,_Context->y_Auto6300+90,688+2,368+2,5);
	visual_text(_Context->x_Auto6300+20+1,_Context->y_Auto6300+90+1,688,368,vfh[1],16,0,_Context->buffer_Espagnol,1978,0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_TabDeutsch=visual_trigger_code(_Context->msg_TabDeutsch[_Context->language],strlen(_Context->msg_TabDeutsch[_Context->language]));
	visual_tabpage(_Context->x_Auto6300+10,_Context->y_Auto6300+50,710,430,vfh[2],_Context->msg_TabDeutsch[_Context->language],strlen(_Context->msg_TabDeutsch[_Context->language]),342,34);
	} else {
		visual_tabpage(_Context->x_Auto6300+10,_Context->y_Auto6300+50,710,430,vfh[2],_Context->msg_TabDeutsch[_Context->language],strlen(_Context->msg_TabDeutsch[_Context->language]),342,32);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto6300+20,_Context->y_Auto6300+90,688+2,368+2,5);
	visual_text(_Context->x_Auto6300+20+1,_Context->y_Auto6300+90+1,688,368,vfh[1],16,0,_Context->buffer_Deutsch,1978,0);
		}
	if (_Context->page_number == 6 ) {
	_Context->trigger_TabNederlands=visual_trigger_code(_Context->msg_TabNederlands[_Context->language],strlen(_Context->msg_TabNederlands[_Context->language]));
	visual_tabpage(_Context->x_Auto6300+10,_Context->y_Auto6300+50,710,430,vfh[2],_Context->msg_TabNederlands[_Context->language],strlen(_Context->msg_TabNederlands[_Context->language]),429,34);
	} else {
		visual_tabpage(_Context->x_Auto6300+10,_Context->y_Auto6300+50,710,430,vfh[2],_Context->msg_TabNederlands[_Context->language],strlen(_Context->msg_TabNederlands[_Context->language]),429,32);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto6300+20,_Context->y_Auto6300+90,688+2,368+2,5);
	visual_text(_Context->x_Auto6300+20+1,_Context->y_Auto6300+90+1,688,368,vfh[1],16,0,_Context->buffer_Nederlands,1978,0);
		}
	if (_Context->page_number == 7 ) {
	_Context->trigger_TabPortugues=visual_trigger_code(_Context->msg_TabPortugues[_Context->language],strlen(_Context->msg_TabPortugues[_Context->language]));
	visual_tabpage(_Context->x_Auto6300+10,_Context->y_Auto6300+50,710,430,vfh[2],_Context->msg_TabPortugues[_Context->language],strlen(_Context->msg_TabPortugues[_Context->language]),533,34);
	} else {
		visual_tabpage(_Context->x_Auto6300+10,_Context->y_Auto6300+50,710,430,vfh[2],_Context->msg_TabPortugues[_Context->language],strlen(_Context->msg_TabPortugues[_Context->language]),533,32);
		}
	if (_Context->page_number == 7 ) {
	visual_frame(_Context->x_Auto6300+20,_Context->y_Auto6300+90,688+2,368+2,5);
	visual_text(_Context->x_Auto6300+20+1,_Context->y_Auto6300+90+1,688,368,vfh[1],16,0,_Context->buffer_Portugues,1978,0);
		}
	if (_Context->page_number == 8 ) {
	_Context->trigger_TabOther=visual_trigger_code(_Context->msg_TabOther[_Context->language],strlen(_Context->msg_TabOther[_Context->language]));
	visual_tabpage(_Context->x_Auto6300+10,_Context->y_Auto6300+50,710,430,vfh[2],_Context->msg_TabOther[_Context->language],strlen(_Context->msg_TabOther[_Context->language]),632,34);
	} else {
		visual_tabpage(_Context->x_Auto6300+10,_Context->y_Auto6300+50,710,430,vfh[2],_Context->msg_TabOther[_Context->language],strlen(_Context->msg_TabOther[_Context->language]),632,32);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(_Context->x_Auto6300+20,_Context->y_Auto6300+90,688+2,368+2,5);
	visual_text(_Context->x_Auto6300+20+1,_Context->y_Auto6300+90+1,688,368,vfh[1],16,0,_Context->buffer_Other,1978,0);
		}
	visual_thaw(_Context->x_Auto6300,_Context->y_Auto6300,730,530);
	visual_thaw(_Context->x_Auto6300,_Context->y_Auto6300,730,530);

	return(0);
}

private int Auto6300action(struct accept_widget_messages_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_widget_messages_hide(_Context);

		_Context->x_Auto6300 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto6300 < 0) { _Context->x_Auto6300=0; }
		_Context->y_Auto6300 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto6300 < 0) { _Context->y_Auto6300=0; }
			accept_widget_messages_show(_Context);

		visual_thaw(_Context->x_Auto6300,_Context->y_Auto6300,730,530);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_widget_messages_context * _Context) {
	return(13);
	return(-1);
}
private int on_Copy_event(struct accept_widget_messages_context * _Context) {
	if(_Context->buffer_Francais[0]==' '){
	memcpy(_Context->buffer_Francais,_Context->buffer_English,1978);
	}
	if(_Context->buffer_Italiano[0]==' '){
	memcpy(_Context->buffer_Italiano,_Context->buffer_English,1978);
	}
	if(_Context->buffer_Espagnol[0]==' '){
	memcpy(_Context->buffer_Espagnol,_Context->buffer_English,1978);
	}
	if(_Context->buffer_Deutsch[0]==' '){
	memcpy(_Context->buffer_Deutsch,_Context->buffer_English,1978);
	}
	if(_Context->buffer_Nederlands[0]==' '){
	memcpy(_Context->buffer_Nederlands,_Context->buffer_English,1978);
	}
	if(_Context->buffer_Portugues[0]==' '){
	memcpy(_Context->buffer_Portugues,_Context->buffer_English,1978);
	}
	if(_Context->buffer_Other[0]==' '){
	memcpy(_Context->buffer_Other,_Context->buffer_English,1978);
	}
		accept_widget_messages_show(_Context);
;
	return(-1);
}
private int on_Reset_event(struct accept_widget_messages_context * _Context) {
	memset(_Context->buffer_Francais,32,1978);
	memset(_Context->buffer_Italiano,32,1978);
	memset(_Context->buffer_Espagnol,32,1978);
	memset(_Context->buffer_Deutsch,32,1978);
	memset(_Context->buffer_Nederlands,32,1978);
	memset(_Context->buffer_Portugues,32,1978);
	memset(_Context->buffer_Other,32,1978);
		accept_widget_messages_show(_Context);
;
	return(-1);
}
private int on_Cancel_event(struct accept_widget_messages_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_widget_messages_event(
struct accept_widget_messages_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(2);
		if (_Context->trigger_Copy == mb ) return(3);
		if (_Context->trigger_Reset == mb ) return(4);
		if (_Context->trigger_Cancel == mb ) return(5);
		if (_Context->trigger_TabEnglish == mb ) return(6);
		if (_Context->trigger_TabFrancais == mb ) return(8);
		if (_Context->trigger_TabItaliano == mb ) return(10);
		if (_Context->trigger_TabEspagnol == mb ) return(12);
		if (_Context->trigger_TabDeutsch == mb ) return(14);
		if (_Context->trigger_TabNederlands == mb ) return(16);
		if (_Context->trigger_TabPortugues == mb ) return(18);
		if (_Context->trigger_TabOther == mb ) return(20);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto6300+709) )  
	&&  (my >= (_Context->y_Auto6300+4) )  
	&&  (mx <= (_Context->x_Auto6300+726) )  
	&&  (my <= (_Context->y_Auto6300+20) )) {
		return(1);	/* Auto6300 */

		}
	if ((mx >= (_Context->x_Auto6300+693) )  
	&&  (my >= (_Context->y_Auto6300+4) )  
	&&  (mx <= (_Context->x_Auto6300+710) )  
	&&  (my <= (_Context->y_Auto6300+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vnation.htm");
			};
		return(-1);	/* Auto6300 */

		}
	if ((mx >= (_Context->x_Auto6300+677) )  
	&&  (my >= (_Context->y_Auto6300+4) )  
	&&  (mx <= (_Context->x_Auto6300+694) )  
	&&  (my <= (_Context->y_Auto6300+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_widget_messages_show(_Context);
		return(-1);	/* Auto6300 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto6300+4) )  
		&&  (my >= (_Context->y_Auto6300+4) )  
		&&  (mx <= (_Context->x_Auto6300+662) )  
		&&  (my <= (_Context->y_Auto6300+20) )) {
			return( Auto6300action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto6300+10) ) 
	&&  ( my >= (_Context->y_Auto6300+490) ) 
	&&  ( mx <= (_Context->x_Auto6300+10+140) ) 
	&&  ( my <= (_Context->y_Auto6300+490+32))) {
		return(2); /* Accept */
		}
	if (( mx >= (_Context->x_Auto6300+190) ) 
	&&  ( my >= (_Context->y_Auto6300+490) ) 
	&&  ( mx <= (_Context->x_Auto6300+190+136) ) 
	&&  ( my <= (_Context->y_Auto6300+490+32))) {
		return(3); /* Copy */
		}
	if (( mx >= (_Context->x_Auto6300+360) ) 
	&&  ( my >= (_Context->y_Auto6300+490) ) 
	&&  ( mx <= (_Context->x_Auto6300+360+136) ) 
	&&  ( my <= (_Context->y_Auto6300+490+32))) {
		return(4); /* Reset */
		}
	if (( mx >= (_Context->x_Auto6300+530) ) 
	&&  ( my >= (_Context->y_Auto6300+490) ) 
	&&  ( mx <= (_Context->x_Auto6300+530+140) ) 
	&&  ( my <= (_Context->y_Auto6300+490+32))) {
		return(5); /* Cancel */
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto6300+10+0) ) 
		&&  ( my >= (_Context->y_Auto6300+50) ) 
		&&  ( mx <= (_Context->x_Auto6300+10+80) ) 
		&&  ( my <= (_Context->y_Auto6300+50+24))) {
			return(6); /* TabEnglish */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto6300+20) ) 
		&&  ( my >= (_Context->y_Auto6300+90) ) 
		&&  ( mx <= (_Context->x_Auto6300+20+688) ) 
		&&  ( my <= (_Context->y_Auto6300+90+368))) {
			return(7); /* English */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto6300+10+81) ) 
		&&  ( my >= (_Context->y_Auto6300+50) ) 
		&&  ( mx <= (_Context->x_Auto6300+10+169) ) 
		&&  ( my <= (_Context->y_Auto6300+50+24))) {
			return(8); /* TabFrancais */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto6300+20) ) 
		&&  ( my >= (_Context->y_Auto6300+90) ) 
		&&  ( mx <= (_Context->x_Auto6300+20+688) ) 
		&&  ( my <= (_Context->y_Auto6300+90+368))) {
			return(9); /* Francais */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_Auto6300+10+170) ) 
		&&  ( my >= (_Context->y_Auto6300+50) ) 
		&&  ( mx <= (_Context->x_Auto6300+10+249) ) 
		&&  ( my <= (_Context->y_Auto6300+50+24))) {
			return(10); /* TabItaliano */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto6300+20) ) 
		&&  ( my >= (_Context->y_Auto6300+90) ) 
		&&  ( mx <= (_Context->x_Auto6300+20+688) ) 
		&&  ( my <= (_Context->y_Auto6300+90+368))) {
			return(11); /* Italiano */
			}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if (( mx >= (_Context->x_Auto6300+10+250) ) 
		&&  ( my >= (_Context->y_Auto6300+50) ) 
		&&  ( mx <= (_Context->x_Auto6300+10+341) ) 
		&&  ( my <= (_Context->y_Auto6300+50+24))) {
			return(12); /* TabEspagnol */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto6300+20) ) 
		&&  ( my >= (_Context->y_Auto6300+90) ) 
		&&  ( mx <= (_Context->x_Auto6300+20+688) ) 
		&&  ( my <= (_Context->y_Auto6300+90+368))) {
			return(13); /* Espagnol */
			}
		}
	if (_Context->page_number == 5 ) {
	} else {
		if (( mx >= (_Context->x_Auto6300+10+342) ) 
		&&  ( my >= (_Context->y_Auto6300+50) ) 
		&&  ( mx <= (_Context->x_Auto6300+10+428) ) 
		&&  ( my <= (_Context->y_Auto6300+50+24))) {
			return(14); /* TabDeutsch */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto6300+20) ) 
		&&  ( my >= (_Context->y_Auto6300+90) ) 
		&&  ( mx <= (_Context->x_Auto6300+20+688) ) 
		&&  ( my <= (_Context->y_Auto6300+90+368))) {
			return(15); /* Deutsch */
			}
		}
	if (_Context->page_number == 6 ) {
	} else {
		if (( mx >= (_Context->x_Auto6300+10+429) ) 
		&&  ( my >= (_Context->y_Auto6300+50) ) 
		&&  ( mx <= (_Context->x_Auto6300+10+532) ) 
		&&  ( my <= (_Context->y_Auto6300+50+24))) {
			return(16); /* TabNederlands */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto6300+20) ) 
		&&  ( my >= (_Context->y_Auto6300+90) ) 
		&&  ( mx <= (_Context->x_Auto6300+20+688) ) 
		&&  ( my <= (_Context->y_Auto6300+90+368))) {
			return(17); /* Nederlands */
			}
		}
	if (_Context->page_number == 7 ) {
	} else {
		if (( mx >= (_Context->x_Auto6300+10+533) ) 
		&&  ( my >= (_Context->y_Auto6300+50) ) 
		&&  ( mx <= (_Context->x_Auto6300+10+631) ) 
		&&  ( my <= (_Context->y_Auto6300+50+24))) {
			return(18); /* TabPortugues */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto6300+20) ) 
		&&  ( my >= (_Context->y_Auto6300+90) ) 
		&&  ( mx <= (_Context->x_Auto6300+20+688) ) 
		&&  ( my <= (_Context->y_Auto6300+90+368))) {
			return(19); /* Portugues */
			}
		}
	if (_Context->page_number == 8 ) {
	} else {
		if (( mx >= (_Context->x_Auto6300+10+632) ) 
		&&  ( my >= (_Context->y_Auto6300+50) ) 
		&&  ( mx <= (_Context->x_Auto6300+10+704) ) 
		&&  ( my <= (_Context->y_Auto6300+50+24))) {
			return(20); /* TabOther */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto6300+20) ) 
		&&  ( my >= (_Context->y_Auto6300+90) ) 
		&&  ( mx <= (_Context->x_Auto6300+20+688) ) 
		&&  ( my <= (_Context->y_Auto6300+90+368))) {
			return(21); /* Other */
			}
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
				/* Accept */
				visual_button(_Context->x_Auto6300+10,_Context->y_Auto6300+490,140,32,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto6300+10,_Context->y_Auto6300+490,140,32,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x3 :
				/* Copy */
				visual_button(_Context->x_Auto6300+190,_Context->y_Auto6300+490,136,32,vfh[2],0,0,_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto6300+190,_Context->y_Auto6300+490,136,32,vfh[2],0,0,_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]),0);
				break;
			case	0x4 :
				/* Reset */
				visual_button(_Context->x_Auto6300+360,_Context->y_Auto6300+490,136,32,vfh[2],0,0,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto6300+360,_Context->y_Auto6300+490,136,32,vfh[2],0,0,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),0);
				break;
			case	0x5 :
				/* Cancel */
				visual_button(_Context->x_Auto6300+530,_Context->y_Auto6300+490,140,32,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto6300+530,_Context->y_Auto6300+490,140,32,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0x6 :
				/* TabEnglish */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x7 :
				/* English */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto6300+20+1,_Context->y_Auto6300+90+1,688,368,vfh[1],_Context->buffer_English,1978);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* TabFrancais */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x9 :
				/* Francais */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto6300+20+1,_Context->y_Auto6300+90+1,688,368,vfh[1],_Context->buffer_Francais,1978);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* TabItaliano */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xb :
				/* Italiano */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto6300+20+1,_Context->y_Auto6300+90+1,688,368,vfh[1],_Context->buffer_Italiano,1978);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* TabEspagnol */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xd :
				/* Espagnol */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto6300+20+1,_Context->y_Auto6300+90+1,688,368,vfh[1],_Context->buffer_Espagnol,1978);
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
					_Context->keycode = visual_edit(_Context->x_Auto6300+20+1,_Context->y_Auto6300+90+1,688,368,vfh[1],_Context->buffer_Deutsch,1978);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* TabNederlands */
				if (_Context->page_number == 6 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x11 :
				/* Nederlands */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_edit(_Context->x_Auto6300+20+1,_Context->y_Auto6300+90+1,688,368,vfh[1],_Context->buffer_Nederlands,1978);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* TabPortugues */
				if (_Context->page_number == 7 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x13 :
				/* Portugues */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_edit(_Context->x_Auto6300+20+1,_Context->y_Auto6300+90+1,688,368,vfh[1],_Context->buffer_Portugues,1978);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* TabOther */
				if (_Context->page_number == 8 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x15 :
				/* Other */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_edit(_Context->x_Auto6300+20+1,_Context->y_Auto6300+90+1,688,368,vfh[1],_Context->buffer_Other,1978);
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
			accept_widget_messages_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_widget_messages_show(_Context);
			continue;
		case	0x2 :
			accept_widget_messages_losefocus(_Context);
			_Context->page_number=8;
			_Context->focus_item=21;
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
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto6300 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto6300+10,_Context->y_Auto6300+490,140,32,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto6300+10,_Context->y_Auto6300+490,140,32,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* Copy */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto6300+190,_Context->y_Auto6300+490,136,32,vfh[2],0,0,_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto6300+190,_Context->y_Auto6300+490,136,32,vfh[2],0,0,_Context->msg_Copy[_Context->language],strlen(_Context->msg_Copy[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Copy_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* Reset */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto6300+360,_Context->y_Auto6300+490,136,32,vfh[2],0,0,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto6300+360,_Context->y_Auto6300+490,136,32,vfh[2],0,0,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Reset_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto6300+530,_Context->y_Auto6300+490,140,32,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto6300+530,_Context->y_Auto6300+490,140,32,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* TabEnglish */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_messages_losefocus(_Context);
							_Context->page_number = 1;
							accept_widget_messages_show(_Context);
							}
						continue;
					case	0x7 :
						/* English */
						continue;
					case	0x8 :
						/* TabFrancais */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_messages_losefocus(_Context);
							_Context->page_number = 2;
							accept_widget_messages_show(_Context);
							}
						continue;
					case	0x9 :
						/* Francais */
						continue;
					case	0xa :
						/* TabItaliano */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_messages_losefocus(_Context);
							_Context->page_number = 3;
							accept_widget_messages_show(_Context);
							}
						continue;
					case	0xb :
						/* Italiano */
						continue;
					case	0xc :
						/* TabEspagnol */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_messages_losefocus(_Context);
							_Context->page_number = 4;
							accept_widget_messages_show(_Context);
							}
						continue;
					case	0xd :
						/* Espagnol */
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
						/* TabNederlands */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_messages_losefocus(_Context);
							_Context->page_number = 6;
							accept_widget_messages_show(_Context);
							}
						continue;
					case	0x11 :
						/* Nederlands */
						continue;
					case	0x12 :
						/* TabPortugues */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_messages_losefocus(_Context);
							_Context->page_number = 7;
							accept_widget_messages_show(_Context);
							}
						continue;
					case	0x13 :
						/* Portugues */
						continue;
					case	0x14 :
						/* TabOther */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_messages_losefocus(_Context);
							_Context->page_number = 8;
							accept_widget_messages_show(_Context);
							}
						continue;
					case	0x15 :
						/* Other */
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

public	int	accept_widget_messages(
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
	struct accept_widget_messages_context * _Context=(struct accept_widget_messages_context*) 0;
	status = accept_widget_messages_create(
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
	status = accept_widget_messages_show(_Context);
		enter_modal();
	status = accept_widget_messages_focus(_Context);
		leave_modal();
	status = accept_widget_messages_hide(_Context);
	status = accept_widget_messages_remove(
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

#endif /* _vnation_c */
