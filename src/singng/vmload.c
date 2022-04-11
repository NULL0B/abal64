
#ifndef _vmload_c
#define _vmload_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vmload.xml                                               */
/* Target         : vmload.c                                                 */
/* Identification : 0.0-1177511936-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__auto703   ""
#define fr__auto703   ""
#define it__auto703   ""
#define es__auto703   ""
#define de__auto703   ""
#define nl__auto703   ""
#define pt__auto703   ""
#define xx__auto703   ""
#define en_auto706   "Name of Application to Load"
#define fr_auto706   "Nom du projet … charger"
#define it_auto706   "Name of Application to Load"
#define es_auto706   "Name of Application to Load"
#define de_auto706   "Name of Application to Load"
#define nl_auto706   "Name of Application to Load"
#define pt_auto706   "Name of Application to Load"
#define xx_auto706   "Name of Application to Load"
#define en_FileName   ""
#define en__FileName   ""
#define en_Auto2746   "ok.gif"
#define fr_Auto2746   "ok.gif"
#define it_Auto2746   "ok.gif"
#define es_Auto2746   "ok.gif"
#define de_Auto2746   "ok.gif"
#define nl_Auto2746   "ok.gif"
#define pt_Auto2746   "ok.gif"
#define xx_Auto2746   "ok.gif"
#define en__Auto2746   ""
#define en_Select   "&Select"
#define fr_Select   "&S‚lectionner"
#define it_Select   "&Select"
#define es_Select   "&Select"
#define de_Select   "&Select"
#define nl_Select   "&Select"
#define pt_Select   "&Select"
#define xx_Select   "&Select"
#define en_auto711   "fileicon.gif"
#define fr_auto711   "fileicon.gif"
#define it_auto711   "fileicon.gif"
#define es_auto711   "fileicon.gif"
#define de_auto711   "fileicon.gif"
#define nl_auto711   "fileicon.gif"
#define pt_auto711   "fileicon.gif"
#define xx_auto711   "fileicon.gif"
#define en_Auto2747   "cancel.gif"
#define fr_Auto2747   "cancel.gif"
#define it_Auto2747   "cancel.gif"
#define es_Auto2747   "cancel.gif"
#define de_Auto2747   "cancel.gif"
#define nl_Auto2747   "cancel.gif"
#define pt_Auto2747   "cancel.gif"
#define xx_Auto2747   "cancel.gif"
#define en__Auto2747   ""

private struct accept_modelfilename_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_auto703[8];
	char * hint_auto703[8];
	int	x_auto703;
	int	y_auto703;
	int	w_auto703;
	int	h_auto703;
	char * msg_auto706[8];
	char * hint_auto706[8];
	char * hint_FileName[8];
	char	buffer_FileName[256];
	char * msg_Auto2746[8];
	int	trigger_Auto2746;
	char * hint_Auto2746[8];
	char * msg_Select[8];
	int	trigger_Select;
	char * hint_Select[8];
	char * msg_auto711[8];
	char * hint_auto711[8];
	char * msg_Auto2747[8];
	int	trigger_Auto2747;
	char * hint_Auto2747[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};
static int	vfh[16];

public	int	accept_modelfilename_create(
	struct accept_modelfilename_context ** cptr,
	char * pFileName)
{

	int i;
	struct accept_modelfilename_context * _Context=(struct accept_modelfilename_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_modelfilename_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=5;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 255, pFileName);
		}
	for (i=0; i < 8; i++)_Context->msg_auto703[i]=" ";
	_Context->hint_auto703[0]=en__auto703;
	_Context->hint_auto703[1]=fr__auto703;
	_Context->hint_auto703[2]=it__auto703;
	_Context->hint_auto703[3]=es__auto703;
	_Context->hint_auto703[4]=de__auto703;
	_Context->hint_auto703[5]=nl__auto703;
	_Context->hint_auto703[6]=pt__auto703;
	_Context->hint_auto703[7]=xx__auto703;
	_Context->x_auto703=105;
	_Context->y_auto703=195;
	_Context->w_auto703=590;
	_Context->h_auto703=210;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_auto706[i]=" ";
	_Context->msg_auto706[0]=en_auto706;
	_Context->msg_auto706[1]=fr_auto706;
	_Context->msg_auto706[2]=it_auto706;
	_Context->msg_auto706[3]=es_auto706;
	_Context->msg_auto706[4]=de_auto706;
	_Context->msg_auto706[5]=nl_auto706;
	_Context->msg_auto706[6]=pt_auto706;
	_Context->msg_auto706[7]=xx_auto706;
	_Context->hint_FileName[0]=en__FileName;
	for (i=0; i < 8; i++)_Context->msg_Auto2746[i]=" ";
	_Context->msg_Auto2746[0]=en_Auto2746;
	_Context->msg_Auto2746[1]=fr_Auto2746;
	_Context->msg_Auto2746[2]=it_Auto2746;
	_Context->msg_Auto2746[3]=es_Auto2746;
	_Context->msg_Auto2746[4]=de_Auto2746;
	_Context->msg_Auto2746[5]=nl_Auto2746;
	_Context->msg_Auto2746[6]=pt_Auto2746;
	_Context->msg_Auto2746[7]=xx_Auto2746;
	_Context->hint_Auto2746[0]=en__Auto2746;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	_Context->msg_Select[2]=it_Select;
	_Context->msg_Select[3]=es_Select;
	_Context->msg_Select[4]=de_Select;
	_Context->msg_Select[5]=nl_Select;
	_Context->msg_Select[6]=pt_Select;
	_Context->msg_Select[7]=xx_Select;
	for (i=0; i < 8; i++)_Context->msg_auto711[i]=" ";
	_Context->msg_auto711[0]=en_auto711;
	_Context->msg_auto711[1]=fr_auto711;
	_Context->msg_auto711[2]=it_auto711;
	_Context->msg_auto711[3]=es_auto711;
	_Context->msg_auto711[4]=de_auto711;
	_Context->msg_auto711[5]=nl_auto711;
	_Context->msg_auto711[6]=pt_auto711;
	_Context->msg_auto711[7]=xx_auto711;
	for (i=0; i < 8; i++)_Context->msg_Auto2747[i]=" ";
	_Context->msg_Auto2747[0]=en_Auto2747;
	_Context->msg_Auto2747[1]=fr_Auto2747;
	_Context->msg_Auto2747[2]=it_Auto2747;
	_Context->msg_Auto2747[3]=es_Auto2747;
	_Context->msg_Auto2747[4]=de_Auto2747;
	_Context->msg_Auto2747[5]=nl_Auto2747;
	_Context->msg_Auto2747[6]=pt_Auto2747;
	_Context->msg_Auto2747[7]=xx_Auto2747;
	_Context->hint_Auto2747[0]=en__Auto2747;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto703,_Context->y_auto703,590+10,210+10);
	return(0);
}

public 	int	accept_modelfilename_hide(struct accept_modelfilename_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_auto703,_Context->y_auto703);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_modelfilename_remove(
	struct accept_modelfilename_context * _Context,
	char * pFileName)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 255, pFileName);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_modelfilename_show(struct accept_modelfilename_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto703,_Context->y_auto703);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_auto703,_Context->y_auto703,590,210,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_auto703,_Context->y_auto703,590,210,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_auto703+20,_Context->y_auto703+50,546,16,vfh[2],27,0,_Context->msg_auto706[_Context->language],strlen(_Context->msg_auto706[_Context->language]),258);
	visual_frame(_Context->x_auto703+20,_Context->y_auto703+70,552+2,16+2,5);
	visual_text(_Context->x_auto703+20+1,_Context->y_auto703+70+1,552,16,vfh[1],26,0,_Context->buffer_FileName,255,0);
	_Context->trigger_Auto2746=visual_trigger_code(_Context->msg_Auto2746[_Context->language],strlen(_Context->msg_Auto2746[_Context->language]));
	visual_button(_Context->x_auto703+20,_Context->y_auto703+140,56,48,vfh[2],34,0,_Context->msg_Auto2746[_Context->language],strlen(_Context->msg_Auto2746[_Context->language]),1040);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto703+350,_Context->y_auto703+150,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	visual_image(_Context->x_auto703+222,_Context->y_auto703+140,50,50,_Context->msg_auto711[_Context->language],0);
	_Context->trigger_Auto2747=visual_trigger_code(_Context->msg_Auto2747[_Context->language],strlen(_Context->msg_Auto2747[_Context->language]));
	visual_button(_Context->x_auto703+510,_Context->y_auto703+140,56,48,vfh[2],34,0,_Context->msg_Auto2747[_Context->language],strlen(_Context->msg_Auto2747[_Context->language]),1040);
	visual_thaw(_Context->x_auto703,_Context->y_auto703,590,210);

	return(0);
}

private int FileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Theis edit field presents the full path and file name of the application ";
			mptr[1]="model to be loaded.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Specifiez ici le nom de fichier complete du fichier projet a ouvrir. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2746_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the ACCEPT button any changes made to the various parameters ";
			mptr[1]="will take effect and the project load operation will occur.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Clickez sur ce bouton pour valider l'operation et pour charger un ";
			mptr[1]="fichier projet.   ";
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
			mptr[0] = "This push button allows access to the standard file selection  mechanisms ";
			mptr[1]="for prompted selection of the file to be loaded.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Clickez sur ce bouton a fin d'acceder … la boite de dialogue standard ";
			mptr[1]="de Selection de Fichier … fin de pouvoir choisir le nom de fichier projet ";
			mptr[2]="… ouvrir.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2747_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "By pressing the CANCEL button any modifications performed will be ";
			mptr[1]="discarded and the project file load operation will be cancelled.  ";
			mptr[2]=" ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Clickez sur ce bouton pour abandoner l'operation de chargement d'un ";
			mptr[1]="fichier projet.     ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int auto703action(struct accept_modelfilename_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_modelfilename_hide(_Context);

		_Context->x_auto703 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto703 < 0) { _Context->x_auto703=0; }
		_Context->y_auto703 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto703 < 0) { _Context->y_auto703=0; }
			accept_modelfilename_show(_Context);

		visual_thaw(_Context->x_auto703,_Context->y_auto703,590,210);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto2746_event(struct accept_modelfilename_context * _Context) {
	return(13);
	return(-1);
}
private int on_Select_event(struct accept_modelfilename_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_XML);
		accept_modelfilename_show(_Context);
;
	return(-1);
}
private int on_Auto2747_event(struct accept_modelfilename_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_modelfilename_event(
struct accept_modelfilename_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto2746 == mb ) return(3);
		if (_Context->trigger_Select == mb ) return(4);
		if (_Context->trigger_Auto2747 == mb ) return(5);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_auto703+569) )  
	&&  (my >= (_Context->y_auto703+4) )  
	&&  (mx <= (_Context->x_auto703+586) )  
	&&  (my <= (_Context->y_auto703+20) )) {
		return(1);	/* auto703 */

		}
	if ((mx >= (_Context->x_auto703+553) )  
	&&  (my >= (_Context->y_auto703+4) )  
	&&  (mx <= (_Context->x_auto703+570) )  
	&&  (my <= (_Context->y_auto703+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vmload.htm");
			};
		return(-1);	/* auto703 */

		}
	if ((mx >= (_Context->x_auto703+537) )  
	&&  (my >= (_Context->y_auto703+4) )  
	&&  (mx <= (_Context->x_auto703+554) )  
	&&  (my <= (_Context->y_auto703+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_modelfilename_show(_Context);
		return(-1);	/* auto703 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_auto703+4) )  
		&&  (my >= (_Context->y_auto703+4) )  
		&&  (mx <= (_Context->x_auto703+522) )  
		&&  (my <= (_Context->y_auto703+20) )) {
			return( auto703action(_Context) );
			}
		}
	if (( mx >= (_Context->x_auto703+20) ) 
	&&  ( my >= (_Context->y_auto703+70) ) 
	&&  ( mx <= (_Context->x_auto703+20+552) ) 
	&&  ( my <= (_Context->y_auto703+70+16))) {
		return(2); /* FileName */
		}
	if (( mx >= (_Context->x_auto703+20) ) 
	&&  ( my >= (_Context->y_auto703+140) ) 
	&&  ( mx <= (_Context->x_auto703+20+56) ) 
	&&  ( my <= (_Context->y_auto703+140+48))) {
		return(3); /* Auto2746 */
		}
	if (( mx >= (_Context->x_auto703+350) ) 
	&&  ( my >= (_Context->y_auto703+150) ) 
	&&  ( mx <= (_Context->x_auto703+350+100) ) 
	&&  ( my <= (_Context->y_auto703+150+30))) {
		return(4); /* Select */
		}
	if (( mx >= (_Context->x_auto703+510) ) 
	&&  ( my >= (_Context->y_auto703+140) ) 
	&&  ( mx <= (_Context->x_auto703+510+56) ) 
	&&  ( my <= (_Context->y_auto703+140+48))) {
		return(5); /* Auto2747 */
		}

	return(-1);
}


public	int	accept_modelfilename_focus(struct accept_modelfilename_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(_Context->x_auto703+20+1,_Context->y_auto703+70+1,552,16,vfh[1],_Context->buffer_FileName,255);
			break;
			case	0x3 :
				/* Auto2746 */
				_Context->trigger_Auto2746=visual_trigger_code(_Context->msg_Auto2746[_Context->language],strlen(_Context->msg_Auto2746[_Context->language]));
				visual_button(_Context->x_auto703+20,_Context->y_auto703+140,56,48,vfh[2],34,0,_Context->msg_Auto2746[_Context->language],strlen(_Context->msg_Auto2746[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2746=visual_trigger_code(_Context->msg_Auto2746[_Context->language],strlen(_Context->msg_Auto2746[_Context->language]));
	visual_button(_Context->x_auto703+20,_Context->y_auto703+140,56,48,vfh[2],34,0,_Context->msg_Auto2746[_Context->language],strlen(_Context->msg_Auto2746[_Context->language]),1040);
				break;
			case	0x4 :
				/* Select */
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
				visual_button(_Context->x_auto703+350,_Context->y_auto703+150,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto703+350,_Context->y_auto703+150,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;
			case	0x5 :
				/* Auto2747 */
				_Context->trigger_Auto2747=visual_trigger_code(_Context->msg_Auto2747[_Context->language],strlen(_Context->msg_Auto2747[_Context->language]));
				visual_button(_Context->x_auto703+510,_Context->y_auto703+140,56,48,vfh[2],34,0,_Context->msg_Auto2747[_Context->language],strlen(_Context->msg_Auto2747[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2747=visual_trigger_code(_Context->msg_Auto2747[_Context->language],strlen(_Context->msg_Auto2747[_Context->language]));
	visual_button(_Context->x_auto703+510,_Context->y_auto703+140,56,48,vfh[2],34,0,_Context->msg_Auto2747[_Context->language],strlen(_Context->msg_Auto2747[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_modelfilename_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=5;
			accept_modelfilename_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_modelfilename_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (FileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Auto2746_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Select_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Auto2747_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* auto703 */
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
					/* Auto2746 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2746=visual_trigger_code(_Context->msg_Auto2746[_Context->language],strlen(_Context->msg_Auto2746[_Context->language]));
						visual_button(_Context->x_auto703+20,_Context->y_auto703+140,56,48,vfh[2],34,0,_Context->msg_Auto2746[_Context->language],strlen(_Context->msg_Auto2746[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2746=visual_trigger_code(_Context->msg_Auto2746[_Context->language],strlen(_Context->msg_Auto2746[_Context->language]));
	visual_button(_Context->x_auto703+20,_Context->y_auto703+140,56,48,vfh[2],34,0,_Context->msg_Auto2746[_Context->language],strlen(_Context->msg_Auto2746[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2746_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Select */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
						visual_button(_Context->x_auto703+350,_Context->y_auto703+150,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto703+350,_Context->y_auto703+150,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Select_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto2747 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2747=visual_trigger_code(_Context->msg_Auto2747[_Context->language],strlen(_Context->msg_Auto2747[_Context->language]));
						visual_button(_Context->x_auto703+510,_Context->y_auto703+140,56,48,vfh[2],34,0,_Context->msg_Auto2747[_Context->language],strlen(_Context->msg_Auto2747[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2747=visual_trigger_code(_Context->msg_Auto2747[_Context->language],strlen(_Context->msg_Auto2747[_Context->language]));
	visual_button(_Context->x_auto703+510,_Context->y_auto703+140,56,48,vfh[2],34,0,_Context->msg_Auto2747[_Context->language],strlen(_Context->msg_Auto2747[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2747_event(_Context)) != -1) break;

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
				_Context->focus_item=5;
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

public	int	accept_modelfilename(
	char * pFileName)
{
	int	status=0;
	struct accept_modelfilename_context * _Context=(struct accept_modelfilename_context*) 0;
	status = accept_modelfilename_create(
	&_Context,
	 pFileName);
	if ( status != 0) return(status);
	status = accept_modelfilename_show(_Context);
		enter_modal();
	status = accept_modelfilename_focus(_Context);
		leave_modal();
	status = accept_modelfilename_hide(_Context);
	status = accept_modelfilename_remove(
	_Context,
	 pFileName);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vmload_c */
