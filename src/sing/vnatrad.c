
#ifndef _vnatrad_c
#define _vnatrad_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vnatrad.xml                                              */
/* Target         : vnatrad.c                                                */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Auto3623   "Sing : Version 2.1a"
#define fr_Auto3623   "Sing : Version 2.1a"
#define it_Auto3623   "Sing : Version 2.1a"
#define es_Auto3623   "Sing : Version 2.1a"
#define de_Auto3623   "Sing : Version 2.1a"
#define nl_Auto3623   "Sing : Version 2.1a"
#define pt_Auto3623   "Sing : Version 2.1a"
#define xx_Auto3623   "Sing : Version 2.1a"
#define en__Auto3623   ""
#define fr__Auto3623   ""
#define it__Auto3623   ""
#define es__Auto3623   ""
#define de__Auto3623   ""
#define nl__Auto3623   ""
#define pt__Auto3623   ""
#define xx__Auto3623   ""
#define en_Auto3625   "National Language Translation Options"
#define fr_Auto3625   "Options de Traduction Langues Nationaux"
#define it_Auto3625   "National Language Translation Options"
#define es_Auto3625   "National Language Translation Options"
#define de_Auto3625   "National Language Translation Options"
#define nl_Auto3625   "National Language Translation Options"
#define pt_Auto3625   "National Language Translation Options"
#define xx_Auto3625   "National Language Translation Options"
#define en__Auto3625   ""
#define fr__Auto3625   ""
#define it__Auto3625   ""
#define es__Auto3625   ""
#define de__Auto3625   ""
#define nl__Auto3625   ""
#define pt__Auto3625   ""
#define xx__Auto3625   ""
#define en_Auto3626   "Reference Language for Translation"
#define fr_Auto3626   "Langue de r‚f‚rence pour Traduction"
#define it_Auto3626   "Reference Language for Translation"
#define es_Auto3626   "Reference Language for Translation"
#define de_Auto3626   "Reference Language for Translation"
#define nl_Auto3626   "Reference Language for Translation"
#define pt_Auto3626   "Reference Language for Translation"
#define xx_Auto3626   "Reference Language for Translation"
#define en__Auto3626   ""
#define fr__Auto3626   ""
#define it__Auto3626   ""
#define es__Auto3626   ""
#define de__Auto3626   ""
#define nl__Auto3626   ""
#define pt__Auto3626   ""
#define xx__Auto3626   ""
#define en__NationalLanguage   ""
#define fr__NationalLanguage   ""
#define it__NationalLanguage   ""
#define es__NationalLanguage   ""
#define de__NationalLanguage   ""
#define nl__NationalLanguage   ""
#define pt__NationalLanguage   ""
#define xx__NationalLanguage   ""
#define en_Retranslate   "&Reset texts matching source"
#define fr_Retranslate   "RAZ texte identique au source"
#define it_Retranslate   "Reset texts matching source"
#define es_Retranslate   "Reset texts matching source"
#define de_Retranslate   "Reset texts matching source"
#define nl_Retranslate   "Reset texts matching source"
#define pt_Retranslate   "Reset texts matching source"
#define xx_Retranslate   "Reset texts matching source"
#define en__Retranslate   ""
#define fr__Retranslate   ""
#define it__Retranslate   ""
#define es__Retranslate   ""
#define de__Retranslate   ""
#define nl__Retranslate   ""
#define pt__Retranslate   ""
#define xx__Retranslate   ""
#define en_IgnoreImages   "&Ignore Images"
#define fr_IgnoreImages   "Ignoree des Images"
#define it_IgnoreImages   "Ignore Images"
#define es_IgnoreImages   "Ignore Images"
#define de_IgnoreImages   "Ignore Images"
#define nl_IgnoreImages   "Ignore Images"
#define pt_IgnoreImages   "Ignore Images"
#define xx_IgnoreImages   "Ignore Images"
#define en__IgnoreImages   ""
#define fr__IgnoreImages   ""
#define it__IgnoreImages   ""
#define es__IgnoreImages   ""
#define de__IgnoreImages   ""
#define nl__IgnoreImages   ""
#define pt__IgnoreImages   ""
#define xx__IgnoreImages   ""
#define en_DebugTrad   "&Debug Translation"
#define fr_DebugTrad   "&Debug Translation"
#define it_DebugTrad   "&Debug Translation"
#define es_DebugTrad   "&Debug Translation"
#define de_DebugTrad   "&Debug Translation"
#define nl_DebugTrad   "&Debug Translation"
#define pt_DebugTrad   "&Debug Translation"
#define xx_DebugTrad   "&Debug Translation"
#define en__DebugTrad   ""
#define fr__DebugTrad   ""
#define it__DebugTrad   ""
#define es__DebugTrad   ""
#define de__DebugTrad   ""
#define nl__DebugTrad   ""
#define pt__DebugTrad   ""
#define xx__DebugTrad   ""
#define en_Accept   "ok.gif"
#define fr_Accept   "ok.gif"
#define it_Accept   "ok.gif"
#define es_Accept   "ok.gif"
#define de_Accept   "ok.gif"
#define nl_Accept   "ok.gif"
#define pt_Accept   "ok.gif"
#define xx_Accept   "ok.gif"
#define en__Accept   ""
#define fr__Accept   ""
#define it__Accept   ""
#define es__Accept   ""
#define de__Accept   ""
#define nl__Accept   ""
#define pt__Accept   ""
#define xx__Accept   ""
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"
#define en__Cancel   ""

private struct national_translation_options_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3623[8];
	char * hint_Auto3623[8];
	int	x_Auto3623;
	int	y_Auto3623;
	int	w_Auto3623;
	int	h_Auto3623;
	char * hint_Auto3624[8];
	char * msg_Auto3625[8];
	char * hint_Auto3625[8];
	char * msg_Auto3626[8];
	char * hint_Auto3626[8];
	char * msg_NationalLanguage[8];
	char * hint_NationalLanguage[8];
	int	value_NationalLanguage;
	char * msg_Retranslate[8];
	int	trigger_Retranslate;
	char * hint_Retranslate[8];
	int	value_Retranslate;
	char * msg_IgnoreImages[8];
	int	trigger_IgnoreImages;
	char * hint_IgnoreImages[8];
	int	value_IgnoreImages;
	char * msg_DebugTrad[8];
	int	trigger_DebugTrad;
	char * hint_DebugTrad[8];
	int	value_DebugTrad;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[5];
	};
static int	vfh[16];
private int on_Accept_event(struct national_translation_options_context * _Context);
private int on_Cancel_event(struct national_translation_options_context * _Context);

public	int	national_translation_options_create(
	struct national_translation_options_context ** cptr,
	char * pNationalLanguage,
	char * pRetranslate,
	char * pIgnoreImages,
	char * pDebugTrad)
{

	int i;
	struct national_translation_options_context * _Context=(struct national_translation_options_context*)0;
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
	if (!(_Context = allocate( sizeof( struct national_translation_options_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=7;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pNationalLanguage);
		if (!( pNationalLanguage )) _Context->value_NationalLanguage=0;
		else	_Context->value_NationalLanguage = *((int *)pNationalLanguage);
		visual_transferin((void *) 0, 0, pRetranslate);
		if (!( pRetranslate )) _Context->value_Retranslate=0;
		else	_Context->value_Retranslate = *((int *)pRetranslate);
		visual_transferin((void *) 0, 0, pIgnoreImages);
		if (!( pIgnoreImages )) _Context->value_IgnoreImages=0;
		else	_Context->value_IgnoreImages = *((int *)pIgnoreImages);
		visual_transferin((void *) 0, 0, pDebugTrad);
		if (!( pDebugTrad )) _Context->value_DebugTrad=0;
		else	_Context->value_DebugTrad = *((int *)pDebugTrad);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3623[i]=" ";
	_Context->msg_Auto3623[0]=en_Auto3623;
	_Context->msg_Auto3623[1]=fr_Auto3623;
	_Context->msg_Auto3623[2]=it_Auto3623;
	_Context->msg_Auto3623[3]=es_Auto3623;
	_Context->msg_Auto3623[4]=de_Auto3623;
	_Context->msg_Auto3623[5]=nl_Auto3623;
	_Context->msg_Auto3623[6]=pt_Auto3623;
	_Context->msg_Auto3623[7]=xx_Auto3623;
	_Context->hint_Auto3623[0]=en__Auto3623;
	_Context->hint_Auto3623[1]=fr__Auto3623;
	_Context->hint_Auto3623[2]=it__Auto3623;
	_Context->hint_Auto3623[3]=es__Auto3623;
	_Context->hint_Auto3623[4]=de__Auto3623;
	_Context->hint_Auto3623[5]=nl__Auto3623;
	_Context->hint_Auto3623[6]=pt__Auto3623;
	_Context->hint_Auto3623[7]=xx__Auto3623;
	_Context->x_Auto3623=180;
	_Context->y_Auto3623=190;
	_Context->w_Auto3623=440;
	_Context->h_Auto3623=220;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3625[i]=" ";
	_Context->msg_Auto3625[0]=en_Auto3625;
	_Context->msg_Auto3625[1]=fr_Auto3625;
	_Context->msg_Auto3625[2]=it_Auto3625;
	_Context->msg_Auto3625[3]=es_Auto3625;
	_Context->msg_Auto3625[4]=de_Auto3625;
	_Context->msg_Auto3625[5]=nl_Auto3625;
	_Context->msg_Auto3625[6]=pt_Auto3625;
	_Context->msg_Auto3625[7]=xx_Auto3625;
	_Context->hint_Auto3625[0]=en__Auto3625;
	_Context->hint_Auto3625[1]=fr__Auto3625;
	_Context->hint_Auto3625[2]=it__Auto3625;
	_Context->hint_Auto3625[3]=es__Auto3625;
	_Context->hint_Auto3625[4]=de__Auto3625;
	_Context->hint_Auto3625[5]=nl__Auto3625;
	_Context->hint_Auto3625[6]=pt__Auto3625;
	_Context->hint_Auto3625[7]=xx__Auto3625;
	for (i=0; i < 8; i++)_Context->msg_Auto3626[i]=" ";
	_Context->msg_Auto3626[0]=en_Auto3626;
	_Context->msg_Auto3626[1]=fr_Auto3626;
	_Context->msg_Auto3626[2]=it_Auto3626;
	_Context->msg_Auto3626[3]=es_Auto3626;
	_Context->msg_Auto3626[4]=de_Auto3626;
	_Context->msg_Auto3626[5]=nl_Auto3626;
	_Context->msg_Auto3626[6]=pt_Auto3626;
	_Context->msg_Auto3626[7]=xx_Auto3626;
	_Context->hint_Auto3626[0]=en__Auto3626;
	_Context->hint_Auto3626[1]=fr__Auto3626;
	_Context->hint_Auto3626[2]=it__Auto3626;
	_Context->hint_Auto3626[3]=es__Auto3626;
	_Context->hint_Auto3626[4]=de__Auto3626;
	_Context->hint_Auto3626[5]=nl__Auto3626;
	_Context->hint_Auto3626[6]=pt__Auto3626;
	_Context->hint_Auto3626[7]=xx__Auto3626;
	for (i=0; i < 8; i++)_Context->msg_NationalLanguage[i]=" ";
	_Context->hint_NationalLanguage[0]=en__NationalLanguage;
	_Context->hint_NationalLanguage[1]=fr__NationalLanguage;
	_Context->hint_NationalLanguage[2]=it__NationalLanguage;
	_Context->hint_NationalLanguage[3]=es__NationalLanguage;
	_Context->hint_NationalLanguage[4]=de__NationalLanguage;
	_Context->hint_NationalLanguage[5]=nl__NationalLanguage;
	_Context->hint_NationalLanguage[6]=pt__NationalLanguage;
	_Context->hint_NationalLanguage[7]=xx__NationalLanguage;
	for (i=0; i < 8; i++)_Context->msg_Retranslate[i]=" ";
	_Context->msg_Retranslate[0]=en_Retranslate;
	_Context->msg_Retranslate[1]=fr_Retranslate;
	_Context->msg_Retranslate[2]=it_Retranslate;
	_Context->msg_Retranslate[3]=es_Retranslate;
	_Context->msg_Retranslate[4]=de_Retranslate;
	_Context->msg_Retranslate[5]=nl_Retranslate;
	_Context->msg_Retranslate[6]=pt_Retranslate;
	_Context->msg_Retranslate[7]=xx_Retranslate;
	_Context->hint_Retranslate[0]=en__Retranslate;
	_Context->hint_Retranslate[1]=fr__Retranslate;
	_Context->hint_Retranslate[2]=it__Retranslate;
	_Context->hint_Retranslate[3]=es__Retranslate;
	_Context->hint_Retranslate[4]=de__Retranslate;
	_Context->hint_Retranslate[5]=nl__Retranslate;
	_Context->hint_Retranslate[6]=pt__Retranslate;
	_Context->hint_Retranslate[7]=xx__Retranslate;
	for (i=0; i < 8; i++)_Context->msg_IgnoreImages[i]=" ";
	_Context->msg_IgnoreImages[0]=en_IgnoreImages;
	_Context->msg_IgnoreImages[1]=fr_IgnoreImages;
	_Context->msg_IgnoreImages[2]=it_IgnoreImages;
	_Context->msg_IgnoreImages[3]=es_IgnoreImages;
	_Context->msg_IgnoreImages[4]=de_IgnoreImages;
	_Context->msg_IgnoreImages[5]=nl_IgnoreImages;
	_Context->msg_IgnoreImages[6]=pt_IgnoreImages;
	_Context->msg_IgnoreImages[7]=xx_IgnoreImages;
	_Context->hint_IgnoreImages[0]=en__IgnoreImages;
	_Context->hint_IgnoreImages[1]=fr__IgnoreImages;
	_Context->hint_IgnoreImages[2]=it__IgnoreImages;
	_Context->hint_IgnoreImages[3]=es__IgnoreImages;
	_Context->hint_IgnoreImages[4]=de__IgnoreImages;
	_Context->hint_IgnoreImages[5]=nl__IgnoreImages;
	_Context->hint_IgnoreImages[6]=pt__IgnoreImages;
	_Context->hint_IgnoreImages[7]=xx__IgnoreImages;
	for (i=0; i < 8; i++)_Context->msg_DebugTrad[i]=" ";
	_Context->msg_DebugTrad[0]=en_DebugTrad;
	_Context->msg_DebugTrad[1]=fr_DebugTrad;
	_Context->msg_DebugTrad[2]=it_DebugTrad;
	_Context->msg_DebugTrad[3]=es_DebugTrad;
	_Context->msg_DebugTrad[4]=de_DebugTrad;
	_Context->msg_DebugTrad[5]=nl_DebugTrad;
	_Context->msg_DebugTrad[6]=pt_DebugTrad;
	_Context->msg_DebugTrad[7]=xx_DebugTrad;
	_Context->hint_DebugTrad[0]=en__DebugTrad;
	_Context->hint_DebugTrad[1]=fr__DebugTrad;
	_Context->hint_DebugTrad[2]=it__DebugTrad;
	_Context->hint_DebugTrad[3]=es__DebugTrad;
	_Context->hint_DebugTrad[4]=de__DebugTrad;
	_Context->hint_DebugTrad[5]=nl__DebugTrad;
	_Context->hint_DebugTrad[6]=pt__DebugTrad;
	_Context->hint_DebugTrad[7]=xx__DebugTrad;
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
	_Context->hint_Accept[1]=fr__Accept;
	_Context->hint_Accept[2]=it__Accept;
	_Context->hint_Accept[3]=es__Accept;
	_Context->hint_Accept[4]=de__Accept;
	_Context->hint_Accept[5]=nl__Accept;
	_Context->hint_Accept[6]=pt__Accept;
	_Context->hint_Accept[7]=xx__Accept;
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
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3623,_Context->y_Auto3623,440+10,220+10);
	return(0);
}

public 	int	national_translation_options_hide(struct national_translation_options_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3623,_Context->y_Auto3623);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	national_translation_options_remove(
	struct national_translation_options_context * _Context,
	char * pNationalLanguage,
	char * pRetranslate,
	char * pIgnoreImages,
	char * pDebugTrad)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pNationalLanguage);
		if ( pNationalLanguage != (char *) 0)
			*((int*)pNationalLanguage) = _Context->value_NationalLanguage;
		visual_transferout((void *) 0, 0, pRetranslate);
		if ( pRetranslate != (char *) 0)
			*((int*)pRetranslate) = _Context->value_Retranslate;
		visual_transferout((void *) 0, 0, pIgnoreImages);
		if ( pIgnoreImages != (char *) 0)
			*((int*)pIgnoreImages) = _Context->value_IgnoreImages;
		visual_transferout((void *) 0, 0, pDebugTrad);
		if ( pDebugTrad != (char *) 0)
			*((int*)pDebugTrad) = _Context->value_DebugTrad;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	national_translation_options_show(struct national_translation_options_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3623,_Context->y_Auto3623);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto3623,_Context->y_Auto3623,440,220,vfh[2],_Context->msg_Auto3623[_Context->language],strlen(_Context->msg_Auto3623[_Context->language]),0x407);
	visual_frame(_Context->x_Auto3623+10,_Context->y_Auto3623+30,420,180,4);
	visual_text(_Context->x_Auto3623+20,_Context->y_Auto3623+50,400,20,vfh[3],16,0,_Context->msg_Auto3625[_Context->language],strlen(_Context->msg_Auto3625[_Context->language]),1283);
	visual_text(_Context->x_Auto3623+20,_Context->y_Auto3623+90,252,16,vfh[2],16,0,_Context->msg_Auto3626[_Context->language],strlen(_Context->msg_Auto3626[_Context->language]),2);
	visual_select(_Context->x_Auto3623+280,_Context->y_Auto3623+90,140,112,vfh[2],27,0,parse_selection(NationalLanguageList,&_Context->value_NationalLanguage),768);
	_Context->trigger_Retranslate=visual_trigger_code(_Context->msg_Retranslate[_Context->language],strlen(_Context->msg_Retranslate[_Context->language]));
	visual_check(_Context->x_Auto3623+120,_Context->y_Auto3623+130,224,16,vfh[2],16,28,_Context->msg_Retranslate[_Context->language],strlen(_Context->msg_Retranslate[_Context->language]),_Context->value_Retranslate|0);
	_Context->trigger_IgnoreImages=visual_trigger_code(_Context->msg_IgnoreImages[_Context->language],strlen(_Context->msg_IgnoreImages[_Context->language]));
	visual_check(_Context->x_Auto3623+120,_Context->y_Auto3623+150,224,16,vfh[2],16,28,_Context->msg_IgnoreImages[_Context->language],strlen(_Context->msg_IgnoreImages[_Context->language]),_Context->value_IgnoreImages|0);
	_Context->trigger_DebugTrad=visual_trigger_code(_Context->msg_DebugTrad[_Context->language],strlen(_Context->msg_DebugTrad[_Context->language]));
	visual_check(_Context->x_Auto3623+120,_Context->y_Auto3623+170,224,16,vfh[2],16,28,_Context->msg_DebugTrad[_Context->language],strlen(_Context->msg_DebugTrad[_Context->language]),_Context->value_DebugTrad|0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3623+20,_Context->y_Auto3623+150,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3623+360,_Context->y_Auto3623+150,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3623,_Context->y_Auto3623,440,220);

	return(0);
}

private int Auto3623action(struct national_translation_options_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			national_translation_options_hide(_Context);

		_Context->x_Auto3623 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3623 < 0) { _Context->x_Auto3623=0; }
		_Context->y_Auto3623 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3623 < 0) { _Context->y_Auto3623=0; }
			national_translation_options_show(_Context);

		visual_thaw(_Context->x_Auto3623,_Context->y_Auto3623,440,220);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct national_translation_options_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct national_translation_options_context * _Context) {
	return(27);
	return(-1);
}


public	int	national_translation_options_event(
struct national_translation_options_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Retranslate == mb ) return(3);
		if (_Context->trigger_IgnoreImages == mb ) return(4);
		if (_Context->trigger_DebugTrad == mb ) return(5);
		if (_Context->trigger_Accept == mb ) return(6);
		if (_Context->trigger_Cancel == mb ) return(7);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3623+419) )  
	&&  (my >= (_Context->y_Auto3623+4) )  
	&&  (mx <= (_Context->x_Auto3623+436) )  
	&&  (my <= (_Context->y_Auto3623+20) )) {
		return(1);	/* Auto3623 */

		}
	if ((mx >= (_Context->x_Auto3623+403) )  
	&&  (my >= (_Context->y_Auto3623+4) )  
	&&  (mx <= (_Context->x_Auto3623+420) )  
	&&  (my <= (_Context->y_Auto3623+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vnatrad.htm");
			};
		return(-1);	/* Auto3623 */

		}
	if ((mx >= (_Context->x_Auto3623+387) )  
	&&  (my >= (_Context->y_Auto3623+4) )  
	&&  (mx <= (_Context->x_Auto3623+404) )  
	&&  (my <= (_Context->y_Auto3623+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		national_translation_options_show(_Context);
		return(-1);	/* Auto3623 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3623+4) )  
		&&  (my >= (_Context->y_Auto3623+4) )  
		&&  (mx <= (_Context->x_Auto3623+372) )  
		&&  (my <= (_Context->y_Auto3623+20) )) {
			return( Auto3623action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3623+280+0) ) 
	&&  ( my >= (_Context->y_Auto3623+90) ) 
	&&  ( mx <= (_Context->x_Auto3623+280+140) ) 
	&&  ( my <= (_Context->y_Auto3623+90+16))) {
		return(2); /* NationalLanguage */
		}
	if (( mx >= (_Context->x_Auto3623+120) ) 
	&&  ( my >= (_Context->y_Auto3623+130) ) 
	&&  ( mx <= (_Context->x_Auto3623+120+224) ) 
	&&  ( my <= (_Context->y_Auto3623+130+16))) {
		return(3); /* Retranslate */
		}
	if (( mx >= (_Context->x_Auto3623+120) ) 
	&&  ( my >= (_Context->y_Auto3623+150) ) 
	&&  ( mx <= (_Context->x_Auto3623+120+224) ) 
	&&  ( my <= (_Context->y_Auto3623+150+16))) {
		return(4); /* IgnoreImages */
		}
	if (( mx >= (_Context->x_Auto3623+120) ) 
	&&  ( my >= (_Context->y_Auto3623+170) ) 
	&&  ( mx <= (_Context->x_Auto3623+120+224) ) 
	&&  ( my <= (_Context->y_Auto3623+170+16))) {
		return(5); /* DebugTrad */
		}
	if (( mx >= (_Context->x_Auto3623+20) ) 
	&&  ( my >= (_Context->y_Auto3623+150) ) 
	&&  ( mx <= (_Context->x_Auto3623+20+56) ) 
	&&  ( my <= (_Context->y_Auto3623+150+48))) {
		return(6); /* Accept */
		}
	if (( mx >= (_Context->x_Auto3623+360) ) 
	&&  ( my >= (_Context->y_Auto3623+150) ) 
	&&  ( mx <= (_Context->x_Auto3623+360+56) ) 
	&&  ( my <= (_Context->y_Auto3623+150+48))) {
		return(7); /* Cancel */
		}

	return(-1);
}


public	int	national_translation_options_focus(struct national_translation_options_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* NationalLanguage */
				_Context->keycode = visual_select(_Context->x_Auto3623+280,_Context->y_Auto3623+90,140,112,vfh[2],27,0,parse_selection(NationalLanguageList,&_Context->value_NationalLanguage),770);
				break;
			case	0x3 :
				/* Retranslate */
				visual_check(_Context->x_Auto3623+120,_Context->y_Auto3623+130,224,16,vfh[2],16,28,_Context->msg_Retranslate[_Context->language],strlen(_Context->msg_Retranslate[_Context->language]),(_Context->value_Retranslate |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Retranslate=visual_trigger_code(_Context->msg_Retranslate[_Context->language],strlen(_Context->msg_Retranslate[_Context->language]));
	visual_check(_Context->x_Auto3623+120,_Context->y_Auto3623+130,224,16,vfh[2],16,28,_Context->msg_Retranslate[_Context->language],strlen(_Context->msg_Retranslate[_Context->language]),_Context->value_Retranslate|0);
				break;
			case	0x4 :
				/* IgnoreImages */
				visual_check(_Context->x_Auto3623+120,_Context->y_Auto3623+150,224,16,vfh[2],16,28,_Context->msg_IgnoreImages[_Context->language],strlen(_Context->msg_IgnoreImages[_Context->language]),(_Context->value_IgnoreImages |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IgnoreImages=visual_trigger_code(_Context->msg_IgnoreImages[_Context->language],strlen(_Context->msg_IgnoreImages[_Context->language]));
	visual_check(_Context->x_Auto3623+120,_Context->y_Auto3623+150,224,16,vfh[2],16,28,_Context->msg_IgnoreImages[_Context->language],strlen(_Context->msg_IgnoreImages[_Context->language]),_Context->value_IgnoreImages|0);
				break;
			case	0x5 :
				/* DebugTrad */
				visual_check(_Context->x_Auto3623+120,_Context->y_Auto3623+170,224,16,vfh[2],16,28,_Context->msg_DebugTrad[_Context->language],strlen(_Context->msg_DebugTrad[_Context->language]),(_Context->value_DebugTrad |2));
				_Context->keycode = visual_getch();
				_Context->trigger_DebugTrad=visual_trigger_code(_Context->msg_DebugTrad[_Context->language],strlen(_Context->msg_DebugTrad[_Context->language]));
	visual_check(_Context->x_Auto3623+120,_Context->y_Auto3623+170,224,16,vfh[2],16,28,_Context->msg_DebugTrad[_Context->language],strlen(_Context->msg_DebugTrad[_Context->language]),_Context->value_DebugTrad|0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			national_translation_options_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=7;
			national_translation_options_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=national_translation_options_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3623 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* NationalLanguage */
					continue;
				case	0x3 :
					/* Retranslate */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Retranslate += 1;
						_Context->value_Retranslate &= 1;
						}
					continue;
				case	0x4 :
					/* IgnoreImages */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IgnoreImages += 1;
						_Context->value_IgnoreImages &= 1;
						}
					continue;
				case	0x5 :
					/* DebugTrad */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_DebugTrad += 1;
						_Context->value_DebugTrad &= 1;
						}
					continue;
				case	0x6 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_Auto3623+20,_Context->y_Auto3623+150,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3623+20,_Context->y_Auto3623+150,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Auto3623+360,_Context->y_Auto3623+150,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3623+360,_Context->y_Auto3623+150,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
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
				_Context->focus_item=7;
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

public	int	national_translation_options(
	char * pNationalLanguage,
	char * pRetranslate,
	char * pIgnoreImages,
	char * pDebugTrad)
{
	int	status=0;
	struct national_translation_options_context * _Context=(struct national_translation_options_context*) 0;
	status = national_translation_options_create(
	&_Context,
	 pNationalLanguage,
	 pRetranslate,
	 pIgnoreImages,
	 pDebugTrad);
	if ( status != 0) return(status);
	status = national_translation_options_show(_Context);
		enter_modal();
	status = national_translation_options_focus(_Context);
		leave_modal();
	status = national_translation_options_hide(_Context);
	status = national_translation_options_remove(
	_Context,
	 pNationalLanguage,
	 pRetranslate,
	 pIgnoreImages,
	 pDebugTrad);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vnatrad_c */
