
#ifndef _vmsave_c
#define _vmsave_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vmsave.xml                                               */
/* Target         : vmsave.c                                                 */
/* Identification : 0.0-1177511936-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__auto6   ""
#define fr__auto6   ""
#define it__auto6   ""
#define es__auto6   ""
#define de__auto6   ""
#define nl__auto6   ""
#define pt__auto6   ""
#define xx__auto6   ""
#define en_auto8   "Name of Application to Save"
#define fr_auto8   "Nom du projet … sauvegarder"
#define it_auto8   "Name of Application to Save"
#define es_auto8   "Name of Application to Save"
#define de_auto8   "Name of Application to Save"
#define nl_auto8   "Name of Application to Save"
#define pt_auto8   "Name of Application to Save"
#define xx_auto8   "Name of Application to Save"
#define en_FileName   ""
#define en__FileName   ""
#define en_Auto2748   "ok.gif"
#define fr_Auto2748   "ok.gif"
#define it_Auto2748   "ok.gif"
#define es_Auto2748   "ok.gif"
#define de_Auto2748   "ok.gif"
#define nl_Auto2748   "ok.gif"
#define pt_Auto2748   "ok.gif"
#define xx_Auto2748   "ok.gif"
#define en__Auto2748   ""
#define en_Select   "&Select"
#define fr_Select   "&S‚lectionner"
#define it_Select   "&Select"
#define es_Select   "&Select"
#define de_Select   "&Select"
#define nl_Select   "&Select"
#define pt_Select   "&Select"
#define xx_Select   "&Select"
#define en__Select   ""
#define en_Auto2749   "cancel.gif"
#define fr_Auto2749   "cancel.gif"
#define it_Auto2749   "cancel.gif"
#define es_Auto2749   "cancel.gif"
#define de_Auto2749   "cancel.gif"
#define nl_Auto2749   "cancel.gif"
#define pt_Auto2749   "cancel.gif"
#define xx_Auto2749   "cancel.gif"
#define en_SaveImages   "Sa&ve Images"
#define fr_SaveImages   "Sa&uvegarder images"
#define it_SaveImages   "Sa&ve Images"
#define es_SaveImages   "Sa&ve Images"
#define de_SaveImages   "Sa&ve Images"
#define nl_SaveImages   "Sa&ve Images"
#define pt_SaveImages   "Sa&ve Images"
#define xx_SaveImages   "Sa&ve Images"
#define en_SaveForms   "Sav&e Forms"
#define fr_SaveForms   "Sauvegarder &Formulaires"
#define it_SaveForms   "Sav&e Forms"
#define es_SaveForms   "Sav&e Forms"
#define de_SaveForms   "Sav&e Forms"
#define nl_SaveForms   "Sav&e Forms"
#define pt_SaveForms   "Sav&e Forms"
#define xx_SaveForms   "Sav&e Forms"
#define en_SaveAll   "Save A&ll"
#define fr_SaveAll   "Sauvegarder &Tout"
#define it_SaveAll   "Save A&ll"
#define es_SaveAll   "Save A&ll"
#define de_SaveAll   "Save A&ll"
#define nl_SaveAll   "Save A&ll"
#define pt_SaveAll   "Save A&ll"
#define xx_SaveAll   "Save A&ll"
#define en_auto702   "fileicon.gif"
#define fr_auto702   "fileicon.gif"
#define it_auto702   "fileicon.gif"
#define es_auto702   "fileicon.gif"
#define de_auto702   "fileicon.gif"
#define nl_auto702   "fileicon.gif"
#define pt_auto702   "fileicon.gif"
#define xx_auto702   "fileicon.gif"

private struct accept_modelsave_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_auto6[8];
	char * hint_auto6[8];
	int	x_auto6;
	int	y_auto6;
	int	w_auto6;
	int	h_auto6;
	char * msg_auto8[8];
	char * hint_auto8[8];
	char * hint_FileName[8];
	char	buffer_FileName[256];
	char * msg_Auto2748[8];
	int	trigger_Auto2748;
	char * hint_Auto2748[8];
	char * msg_Select[8];
	int	trigger_Select;
	char * hint_Select[8];
	char * msg_Auto2749[8];
	int	trigger_Auto2749;
	char * hint_Auto2749[8];
	char * msg_SaveImages[8];
	int	trigger_SaveImages;
	char * hint_SaveImages[8];
	int	value_SaveImages;
	char * msg_SaveForms[8];
	int	trigger_SaveForms;
	char * hint_SaveForms[8];
	int	value_SaveForms;
	char * msg_SaveAll[8];
	int	trigger_SaveAll;
	char * hint_SaveAll[8];
	int	value_SaveAll;
	char * msg_auto702[8];
	char * hint_auto702[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[5];
	};
static int	vfh[16];

public	int	accept_modelsave_create(
	struct accept_modelsave_context ** cptr,
	char * pFileName,
	char * pSaveImages,
	char * pSaveForms,
	char * pSaveAll)
{

	int i;
	struct accept_modelsave_context * _Context=(struct accept_modelsave_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_modelsave_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=8;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 255, pFileName);
		visual_transferin((void *) 0, 0, pSaveImages);
		if (!( pSaveImages )) _Context->value_SaveImages=0;
		else	_Context->value_SaveImages = *((int *)pSaveImages);
		visual_transferin((void *) 0, 0, pSaveForms);
		if (!( pSaveForms )) _Context->value_SaveForms=0;
		else	_Context->value_SaveForms = *((int *)pSaveForms);
		visual_transferin((void *) 0, 0, pSaveAll);
		if (!( pSaveAll )) _Context->value_SaveAll=0;
		else	_Context->value_SaveAll = *((int *)pSaveAll);
		}
	for (i=0; i < 8; i++)_Context->msg_auto6[i]=" ";
	_Context->hint_auto6[0]=en__auto6;
	_Context->hint_auto6[1]=fr__auto6;
	_Context->hint_auto6[2]=it__auto6;
	_Context->hint_auto6[3]=es__auto6;
	_Context->hint_auto6[4]=de__auto6;
	_Context->hint_auto6[5]=nl__auto6;
	_Context->hint_auto6[6]=pt__auto6;
	_Context->hint_auto6[7]=xx__auto6;
	_Context->x_auto6=100;
	_Context->y_auto6=195;
	_Context->w_auto6=600;
	_Context->h_auto6=210;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_auto8[i]=" ";
	_Context->msg_auto8[0]=en_auto8;
	_Context->msg_auto8[1]=fr_auto8;
	_Context->msg_auto8[2]=it_auto8;
	_Context->msg_auto8[3]=es_auto8;
	_Context->msg_auto8[4]=de_auto8;
	_Context->msg_auto8[5]=nl_auto8;
	_Context->msg_auto8[6]=pt_auto8;
	_Context->msg_auto8[7]=xx_auto8;
	_Context->hint_FileName[0]=en__FileName;
	for (i=0; i < 8; i++)_Context->msg_Auto2748[i]=" ";
	_Context->msg_Auto2748[0]=en_Auto2748;
	_Context->msg_Auto2748[1]=fr_Auto2748;
	_Context->msg_Auto2748[2]=it_Auto2748;
	_Context->msg_Auto2748[3]=es_Auto2748;
	_Context->msg_Auto2748[4]=de_Auto2748;
	_Context->msg_Auto2748[5]=nl_Auto2748;
	_Context->msg_Auto2748[6]=pt_Auto2748;
	_Context->msg_Auto2748[7]=xx_Auto2748;
	_Context->hint_Auto2748[0]=en__Auto2748;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	_Context->msg_Select[2]=it_Select;
	_Context->msg_Select[3]=es_Select;
	_Context->msg_Select[4]=de_Select;
	_Context->msg_Select[5]=nl_Select;
	_Context->msg_Select[6]=pt_Select;
	_Context->msg_Select[7]=xx_Select;
	_Context->hint_Select[0]=en__Select;
	for (i=0; i < 8; i++)_Context->msg_Auto2749[i]=" ";
	_Context->msg_Auto2749[0]=en_Auto2749;
	_Context->msg_Auto2749[1]=fr_Auto2749;
	_Context->msg_Auto2749[2]=it_Auto2749;
	_Context->msg_Auto2749[3]=es_Auto2749;
	_Context->msg_Auto2749[4]=de_Auto2749;
	_Context->msg_Auto2749[5]=nl_Auto2749;
	_Context->msg_Auto2749[6]=pt_Auto2749;
	_Context->msg_Auto2749[7]=xx_Auto2749;
	for (i=0; i < 8; i++)_Context->msg_SaveImages[i]=" ";
	_Context->msg_SaveImages[0]=en_SaveImages;
	_Context->msg_SaveImages[1]=fr_SaveImages;
	_Context->msg_SaveImages[2]=it_SaveImages;
	_Context->msg_SaveImages[3]=es_SaveImages;
	_Context->msg_SaveImages[4]=de_SaveImages;
	_Context->msg_SaveImages[5]=nl_SaveImages;
	_Context->msg_SaveImages[6]=pt_SaveImages;
	_Context->msg_SaveImages[7]=xx_SaveImages;
	for (i=0; i < 8; i++)_Context->msg_SaveForms[i]=" ";
	_Context->msg_SaveForms[0]=en_SaveForms;
	_Context->msg_SaveForms[1]=fr_SaveForms;
	_Context->msg_SaveForms[2]=it_SaveForms;
	_Context->msg_SaveForms[3]=es_SaveForms;
	_Context->msg_SaveForms[4]=de_SaveForms;
	_Context->msg_SaveForms[5]=nl_SaveForms;
	_Context->msg_SaveForms[6]=pt_SaveForms;
	_Context->msg_SaveForms[7]=xx_SaveForms;
	for (i=0; i < 8; i++)_Context->msg_SaveAll[i]=" ";
	_Context->msg_SaveAll[0]=en_SaveAll;
	_Context->msg_SaveAll[1]=fr_SaveAll;
	_Context->msg_SaveAll[2]=it_SaveAll;
	_Context->msg_SaveAll[3]=es_SaveAll;
	_Context->msg_SaveAll[4]=de_SaveAll;
	_Context->msg_SaveAll[5]=nl_SaveAll;
	_Context->msg_SaveAll[6]=pt_SaveAll;
	_Context->msg_SaveAll[7]=xx_SaveAll;
	for (i=0; i < 8; i++)_Context->msg_auto702[i]=" ";
	_Context->msg_auto702[0]=en_auto702;
	_Context->msg_auto702[1]=fr_auto702;
	_Context->msg_auto702[2]=it_auto702;
	_Context->msg_auto702[3]=es_auto702;
	_Context->msg_auto702[4]=de_auto702;
	_Context->msg_auto702[5]=nl_auto702;
	_Context->msg_auto702[6]=pt_auto702;
	_Context->msg_auto702[7]=xx_auto702;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto6,_Context->y_auto6,600+10,210+10);
	return(0);
}

public 	int	accept_modelsave_hide(struct accept_modelsave_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_auto6,_Context->y_auto6);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_modelsave_remove(
	struct accept_modelsave_context * _Context,
	char * pFileName,
	char * pSaveImages,
	char * pSaveForms,
	char * pSaveAll)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 255, pFileName);
		visual_transferout((void *) 0, 0, pSaveImages);
		if ( pSaveImages != (char *) 0)
			*((int*)pSaveImages) = _Context->value_SaveImages;
		visual_transferout((void *) 0, 0, pSaveForms);
		if ( pSaveForms != (char *) 0)
			*((int*)pSaveForms) = _Context->value_SaveForms;
		visual_transferout((void *) 0, 0, pSaveAll);
		if ( pSaveAll != (char *) 0)
			*((int*)pSaveAll) = _Context->value_SaveAll;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_modelsave_show(struct accept_modelsave_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto6,_Context->y_auto6);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_auto6,_Context->y_auto6,600,210,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_auto6,_Context->y_auto6,600,210,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_auto6+20,_Context->y_auto6+40,560,16,vfh[2],38,0,_Context->msg_auto8[_Context->language],strlen(_Context->msg_auto8[_Context->language]),258);
	visual_frame(_Context->x_auto6+20,_Context->y_auto6+60,560+2,16+2,5);
	visual_text(_Context->x_auto6+20+1,_Context->y_auto6+60+1,560,16,vfh[1],16,24,_Context->buffer_FileName,255,0);
	_Context->trigger_Auto2748=visual_trigger_code(_Context->msg_Auto2748[_Context->language],strlen(_Context->msg_Auto2748[_Context->language]));
	visual_button(_Context->x_auto6+20,_Context->y_auto6+140,56,48,vfh[2],34,0,_Context->msg_Auto2748[_Context->language],strlen(_Context->msg_Auto2748[_Context->language]),1040);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto6+360,_Context->y_auto6+150,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	_Context->trigger_Auto2749=visual_trigger_code(_Context->msg_Auto2749[_Context->language],strlen(_Context->msg_Auto2749[_Context->language]));
	visual_button(_Context->x_auto6+520,_Context->y_auto6+140,56,48,vfh[2],34,0,_Context->msg_Auto2749[_Context->language],strlen(_Context->msg_Auto2749[_Context->language]),1040);
	_Context->trigger_SaveImages=visual_trigger_code(_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]));
	visual_check(_Context->x_auto6+20,_Context->y_auto6+90,168,16,vfh[2],34,0,_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]),_Context->value_SaveImages|0);
	_Context->trigger_SaveForms=visual_trigger_code(_Context->msg_SaveForms[_Context->language],strlen(_Context->msg_SaveForms[_Context->language]));
	visual_check(_Context->x_auto6+190,_Context->y_auto6+90,196,16,vfh[2],34,0,_Context->msg_SaveForms[_Context->language],strlen(_Context->msg_SaveForms[_Context->language]),_Context->value_SaveForms|0);
	_Context->trigger_SaveAll=visual_trigger_code(_Context->msg_SaveAll[_Context->language],strlen(_Context->msg_SaveAll[_Context->language]));
	visual_check(_Context->x_auto6+390,_Context->y_auto6+90,182,16,vfh[2],34,0,_Context->msg_SaveAll[_Context->language],strlen(_Context->msg_SaveAll[_Context->language]),_Context->value_SaveAll|0);
	visual_image(_Context->x_auto6+226,_Context->y_auto6+136,50,50,_Context->msg_auto702[_Context->language],0);
	visual_thaw(_Context->x_auto6,_Context->y_auto6,600,210);

	return(0);
}

private int FileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field presents, for inspection and eventual modification, ";
			mptr[1]="the full  path and file name of the file to which the application ";
			mptr[2]="or project model is  to be saved.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Specifiez ici le nom de fichier complete du fichier vers lequel vous ";
			mptr[1]="souhaitez sauver le projet courant.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2748_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the ACCEPT button any changes made to the various parameters ";
			mptr[1]="will take effect and the model save operation will be performed.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Clickez sur ce bouton pour valider l'operation et pour sauver le projet ";
			mptr[1]="courant.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Select_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This button allows the target model filename to be selected activetool ";
			mptr[1]="the standard file selection mechanisms of th visual design tool.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Clickez sur ce bouton a fin d'acceder a la boite de dialogue standard ";
			mptr[1]="de Selection de Fichier a fin de pouvoir choisir le nom de fichier a ";
			mptr[2]="recevoir le sauvegarde du projet en cours.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2749_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the CANCEL button any modifications performed will be ";
			mptr[1]="discarded and the project save operation will be abandoned.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Clickez sur ce bouton pour abandoner l'operation de sauvegarde du ";
			mptr[1]="projet courant.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SaveImages_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "If this check box has been checked then out-of-date model images will ";
			mptr[1]="be saved  to their corresponding image file.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Lorsque ce check contr“le est active les images plus recents que leurs ";
			mptr[1]="fichiers se verrent sauver a nouveau sur disque.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SaveForms_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "If this check box has been selected then out-of-date forms  data will ";
			mptr[1]="be written to  the corresponding disk file during the model save operation. ";
			mptr[2]=" ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Lorsque ce check contr“le est active des formulaires ayant ‚t‚ modifi‚s ";
			mptr[1]="se verrent sauver sur disque.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SaveAll_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "If this check box has been selected then all form data and image data ";
			mptr[1]="will be considered to be out-of-date consequently causing them to ";
			mptr[2]="be rewritten to disk if the corresponding check box controls   have ";
			mptr[3]="been selected.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Lorsque ce check contr“le est active, toutes les images ainsi que ";
			mptr[1]="toutes les  formulaires serrent inconditionellement sauv‚s sur disque. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int auto6action(struct accept_modelsave_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_modelsave_hide(_Context);

		_Context->x_auto6 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto6 < 0) { _Context->x_auto6=0; }
		_Context->y_auto6 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto6 < 0) { _Context->y_auto6=0; }
			accept_modelsave_show(_Context);

		visual_thaw(_Context->x_auto6,_Context->y_auto6,600,210);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto2748_event(struct accept_modelsave_context * _Context) {
	return(13);
	return(-1);
}
private int on_Select_event(struct accept_modelsave_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_XML);
		accept_modelsave_show(_Context);
;
	return(-1);
}
private int on_Auto2749_event(struct accept_modelsave_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_modelsave_event(
struct accept_modelsave_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto2748 == mb ) return(3);
		if (_Context->trigger_Select == mb ) return(4);
		if (_Context->trigger_Auto2749 == mb ) return(5);
		if (_Context->trigger_SaveImages == mb ) return(6);
		if (_Context->trigger_SaveForms == mb ) return(7);
		if (_Context->trigger_SaveAll == mb ) return(8);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_auto6+579) )  
	&&  (my >= (_Context->y_auto6+4) )  
	&&  (mx <= (_Context->x_auto6+596) )  
	&&  (my <= (_Context->y_auto6+20) )) {
		return(1);	/* auto6 */

		}
	if ((mx >= (_Context->x_auto6+563) )  
	&&  (my >= (_Context->y_auto6+4) )  
	&&  (mx <= (_Context->x_auto6+580) )  
	&&  (my <= (_Context->y_auto6+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vmsave.htm");
			};
		return(-1);	/* auto6 */

		}
	if ((mx >= (_Context->x_auto6+547) )  
	&&  (my >= (_Context->y_auto6+4) )  
	&&  (mx <= (_Context->x_auto6+564) )  
	&&  (my <= (_Context->y_auto6+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_modelsave_show(_Context);
		return(-1);	/* auto6 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_auto6+4) )  
		&&  (my >= (_Context->y_auto6+4) )  
		&&  (mx <= (_Context->x_auto6+532) )  
		&&  (my <= (_Context->y_auto6+20) )) {
			return( auto6action(_Context) );
			}
		}
	if (( mx >= (_Context->x_auto6+20) ) 
	&&  ( my >= (_Context->y_auto6+60) ) 
	&&  ( mx <= (_Context->x_auto6+20+560) ) 
	&&  ( my <= (_Context->y_auto6+60+16))) {
		return(2); /* FileName */
		}
	if (( mx >= (_Context->x_auto6+20) ) 
	&&  ( my >= (_Context->y_auto6+140) ) 
	&&  ( mx <= (_Context->x_auto6+20+56) ) 
	&&  ( my <= (_Context->y_auto6+140+48))) {
		return(3); /* Auto2748 */
		}
	if (( mx >= (_Context->x_auto6+360) ) 
	&&  ( my >= (_Context->y_auto6+150) ) 
	&&  ( mx <= (_Context->x_auto6+360+100) ) 
	&&  ( my <= (_Context->y_auto6+150+30))) {
		return(4); /* Select */
		}
	if (( mx >= (_Context->x_auto6+520) ) 
	&&  ( my >= (_Context->y_auto6+140) ) 
	&&  ( mx <= (_Context->x_auto6+520+56) ) 
	&&  ( my <= (_Context->y_auto6+140+48))) {
		return(5); /* Auto2749 */
		}
	if (( mx >= (_Context->x_auto6+20) ) 
	&&  ( my >= (_Context->y_auto6+90) ) 
	&&  ( mx <= (_Context->x_auto6+20+168) ) 
	&&  ( my <= (_Context->y_auto6+90+16))) {
		return(6); /* SaveImages */
		}
	if (( mx >= (_Context->x_auto6+190) ) 
	&&  ( my >= (_Context->y_auto6+90) ) 
	&&  ( mx <= (_Context->x_auto6+190+196) ) 
	&&  ( my <= (_Context->y_auto6+90+16))) {
		return(7); /* SaveForms */
		}
	if (( mx >= (_Context->x_auto6+390) ) 
	&&  ( my >= (_Context->y_auto6+90) ) 
	&&  ( mx <= (_Context->x_auto6+390+182) ) 
	&&  ( my <= (_Context->y_auto6+90+16))) {
		return(8); /* SaveAll */
		}

	return(-1);
}


public	int	accept_modelsave_focus(struct accept_modelsave_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(_Context->x_auto6+20+1,_Context->y_auto6+60+1,560,16,vfh[1],_Context->buffer_FileName,255);
			break;
			case	0x3 :
				/* Auto2748 */
				_Context->trigger_Auto2748=visual_trigger_code(_Context->msg_Auto2748[_Context->language],strlen(_Context->msg_Auto2748[_Context->language]));
				visual_button(_Context->x_auto6+20,_Context->y_auto6+140,56,48,vfh[2],34,0,_Context->msg_Auto2748[_Context->language],strlen(_Context->msg_Auto2748[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2748=visual_trigger_code(_Context->msg_Auto2748[_Context->language],strlen(_Context->msg_Auto2748[_Context->language]));
	visual_button(_Context->x_auto6+20,_Context->y_auto6+140,56,48,vfh[2],34,0,_Context->msg_Auto2748[_Context->language],strlen(_Context->msg_Auto2748[_Context->language]),1040);
				break;
			case	0x4 :
				/* Select */
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
				visual_button(_Context->x_auto6+360,_Context->y_auto6+150,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto6+360,_Context->y_auto6+150,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;
			case	0x5 :
				/* Auto2749 */
				_Context->trigger_Auto2749=visual_trigger_code(_Context->msg_Auto2749[_Context->language],strlen(_Context->msg_Auto2749[_Context->language]));
				visual_button(_Context->x_auto6+520,_Context->y_auto6+140,56,48,vfh[2],34,0,_Context->msg_Auto2749[_Context->language],strlen(_Context->msg_Auto2749[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2749=visual_trigger_code(_Context->msg_Auto2749[_Context->language],strlen(_Context->msg_Auto2749[_Context->language]));
	visual_button(_Context->x_auto6+520,_Context->y_auto6+140,56,48,vfh[2],34,0,_Context->msg_Auto2749[_Context->language],strlen(_Context->msg_Auto2749[_Context->language]),1040);
				break;
			case	0x6 :
				/* SaveImages */
				visual_check(_Context->x_auto6+20,_Context->y_auto6+90,168,16,vfh[2],34,0,_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]),(_Context->value_SaveImages |2));
				_Context->keycode = visual_getch();
				_Context->trigger_SaveImages=visual_trigger_code(_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]));
	visual_check(_Context->x_auto6+20,_Context->y_auto6+90,168,16,vfh[2],34,0,_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]),_Context->value_SaveImages|0);
				break;
			case	0x7 :
				/* SaveForms */
				visual_check(_Context->x_auto6+190,_Context->y_auto6+90,196,16,vfh[2],34,0,_Context->msg_SaveForms[_Context->language],strlen(_Context->msg_SaveForms[_Context->language]),(_Context->value_SaveForms |2));
				_Context->keycode = visual_getch();
				_Context->trigger_SaveForms=visual_trigger_code(_Context->msg_SaveForms[_Context->language],strlen(_Context->msg_SaveForms[_Context->language]));
	visual_check(_Context->x_auto6+190,_Context->y_auto6+90,196,16,vfh[2],34,0,_Context->msg_SaveForms[_Context->language],strlen(_Context->msg_SaveForms[_Context->language]),_Context->value_SaveForms|0);
				break;
			case	0x8 :
				/* SaveAll */
				visual_check(_Context->x_auto6+390,_Context->y_auto6+90,182,16,vfh[2],34,0,_Context->msg_SaveAll[_Context->language],strlen(_Context->msg_SaveAll[_Context->language]),(_Context->value_SaveAll |2));
				_Context->keycode = visual_getch();
				_Context->trigger_SaveAll=visual_trigger_code(_Context->msg_SaveAll[_Context->language],strlen(_Context->msg_SaveAll[_Context->language]));
	visual_check(_Context->x_auto6+390,_Context->y_auto6+90,182,16,vfh[2],34,0,_Context->msg_SaveAll[_Context->language],strlen(_Context->msg_SaveAll[_Context->language]),_Context->value_SaveAll|0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_modelsave_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=8;
			accept_modelsave_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_modelsave_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (FileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Auto2748_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Select_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Auto2749_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (SaveImages_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (SaveForms_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (SaveAll_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* auto6 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* FileName */
					continue;
				case	0x3 :
					/* Auto2748 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2748=visual_trigger_code(_Context->msg_Auto2748[_Context->language],strlen(_Context->msg_Auto2748[_Context->language]));
						visual_button(_Context->x_auto6+20,_Context->y_auto6+140,56,48,vfh[2],34,0,_Context->msg_Auto2748[_Context->language],strlen(_Context->msg_Auto2748[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2748=visual_trigger_code(_Context->msg_Auto2748[_Context->language],strlen(_Context->msg_Auto2748[_Context->language]));
	visual_button(_Context->x_auto6+20,_Context->y_auto6+140,56,48,vfh[2],34,0,_Context->msg_Auto2748[_Context->language],strlen(_Context->msg_Auto2748[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2748_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Select */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
						visual_button(_Context->x_auto6+360,_Context->y_auto6+150,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto6+360,_Context->y_auto6+150,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Select_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto2749 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2749=visual_trigger_code(_Context->msg_Auto2749[_Context->language],strlen(_Context->msg_Auto2749[_Context->language]));
						visual_button(_Context->x_auto6+520,_Context->y_auto6+140,56,48,vfh[2],34,0,_Context->msg_Auto2749[_Context->language],strlen(_Context->msg_Auto2749[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2749=visual_trigger_code(_Context->msg_Auto2749[_Context->language],strlen(_Context->msg_Auto2749[_Context->language]));
	visual_button(_Context->x_auto6+520,_Context->y_auto6+140,56,48,vfh[2],34,0,_Context->msg_Auto2749[_Context->language],strlen(_Context->msg_Auto2749[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2749_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* SaveImages */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_SaveImages += 1;
						_Context->value_SaveImages &= 1;
						}
					continue;
				case	0x7 :
					/* SaveForms */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_SaveForms += 1;
						_Context->value_SaveForms &= 1;
						}
					continue;
				case	0x8 :
					/* SaveAll */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_SaveAll += 1;
						_Context->value_SaveAll &= 1;
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
				_Context->focus_item=8;
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

public	int	accept_modelsave(
	char * pFileName,
	char * pSaveImages,
	char * pSaveForms,
	char * pSaveAll)
{
	int	status=0;
	struct accept_modelsave_context * _Context=(struct accept_modelsave_context*) 0;
	status = accept_modelsave_create(
	&_Context,
	 pFileName,
	 pSaveImages,
	 pSaveForms,
	 pSaveAll);
	if ( status != 0) return(status);
	status = accept_modelsave_show(_Context);
		enter_modal();
	status = accept_modelsave_focus(_Context);
		leave_modal();
	status = accept_modelsave_hide(_Context);
	status = accept_modelsave_remove(
	_Context,
	 pFileName,
	 pSaveImages,
	 pSaveForms,
	 pSaveAll);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vmsave_c */
