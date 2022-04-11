
#ifndef _viload_c
#define _viload_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : viload.xml                                               */
/* Target         : viload.c                                                 */
/* Identification : 0.0-1334659659-14025.1163                                */
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
#define en_auto8   "Name of Image to Load"
#define fr_auto8   "Nom du fichier d'image … charger"
#define it_auto8   "Name of Image to Load"
#define es_auto8   "Name of Image to Load"
#define de_auto8   "Name of Image to Load"
#define nl_auto8   "Name of Image to Load"
#define pt_auto8   "Name of Image to Load"
#define xx_auto8   "Name of Image to Load"
#define en_FileName   ""
#define en_Auto3566   "ok.gif"
#define fr_Auto3566   "ok.gif"
#define it_Auto3566   "ok.gif"
#define es_Auto3566   "ok.gif"
#define de_Auto3566   "ok.gif"
#define nl_Auto3566   "ok.gif"
#define pt_Auto3566   "ok.gif"
#define xx_Auto3566   "ok.gif"
#define en_Select   "&Select"
#define fr_Select   "&S‚lectionner"
#define it_Select   "&Select"
#define es_Select   "&Select"
#define de_Select   "&Select"
#define nl_Select   "&Select"
#define pt_Select   "&Select"
#define xx_Select   "&Select"
#define en_Auto3567   "cancel.gif"
#define fr_Auto3567   "cancel.gif"
#define it_Auto3567   "cancel.gif"
#define es_Auto3567   "cancel.gif"
#define de_Auto3567   "cancel.gif"
#define nl_Auto3567   "cancel.gif"
#define pt_Auto3567   "cancel.gif"
#define xx_Auto3567   "cancel.gif"
#define en_auto710   "imgicon.gif"
#define fr_auto710   "imgicon.gif"
#define it_auto710   "imgicon.gif"
#define es_auto710   "imgicon.gif"
#define de_auto710   "imgicon.gif"
#define nl_auto710   "imgicon.gif"
#define pt_auto710   "imgicon.gif"
#define xx_auto710   "imgicon.gif"

private struct accept_imageload_context {
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
	char * msg_Auto3566[8];
	int	trigger_Auto3566;
	char * hint_Auto3566[8];
	char * msg_Select[8];
	int	trigger_Select;
	char * hint_Select[8];
	char * msg_Auto3567[8];
	int	trigger_Auto3567;
	char * hint_Auto3567[8];
	char * msg_auto710[8];
	char * hint_auto710[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};
static int	vfh[16];
private int on_Auto3566_event(struct accept_imageload_context * _Context);
private int on_Select_event(struct accept_imageload_context * _Context);
private int on_Auto3567_event(struct accept_imageload_context * _Context);

public	int	accept_imageload_create(
	struct accept_imageload_context ** cptr,
	char * pFileName)
{

	int i;
	struct accept_imageload_context * _Context=(struct accept_imageload_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_imageload_context ) ) ))
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
	_Context->y_auto6=220;
	_Context->w_auto6=600;
	_Context->h_auto6=160;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3566[i]=" ";
	_Context->msg_Auto3566[0]=en_Auto3566;
	_Context->msg_Auto3566[1]=fr_Auto3566;
	_Context->msg_Auto3566[2]=it_Auto3566;
	_Context->msg_Auto3566[3]=es_Auto3566;
	_Context->msg_Auto3566[4]=de_Auto3566;
	_Context->msg_Auto3566[5]=nl_Auto3566;
	_Context->msg_Auto3566[6]=pt_Auto3566;
	_Context->msg_Auto3566[7]=xx_Auto3566;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	_Context->msg_Select[2]=it_Select;
	_Context->msg_Select[3]=es_Select;
	_Context->msg_Select[4]=de_Select;
	_Context->msg_Select[5]=nl_Select;
	_Context->msg_Select[6]=pt_Select;
	_Context->msg_Select[7]=xx_Select;
	for (i=0; i < 8; i++)_Context->msg_Auto3567[i]=" ";
	_Context->msg_Auto3567[0]=en_Auto3567;
	_Context->msg_Auto3567[1]=fr_Auto3567;
	_Context->msg_Auto3567[2]=it_Auto3567;
	_Context->msg_Auto3567[3]=es_Auto3567;
	_Context->msg_Auto3567[4]=de_Auto3567;
	_Context->msg_Auto3567[5]=nl_Auto3567;
	_Context->msg_Auto3567[6]=pt_Auto3567;
	_Context->msg_Auto3567[7]=xx_Auto3567;
	for (i=0; i < 8; i++)_Context->msg_auto710[i]=" ";
	_Context->msg_auto710[0]=en_auto710;
	_Context->msg_auto710[1]=fr_auto710;
	_Context->msg_auto710[2]=it_auto710;
	_Context->msg_auto710[3]=es_auto710;
	_Context->msg_auto710[4]=de_auto710;
	_Context->msg_auto710[5]=nl_auto710;
	_Context->msg_auto710[6]=pt_auto710;
	_Context->msg_auto710[7]=xx_auto710;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto6,_Context->y_auto6,600+10,160+10);
	return(0);
}

public 	int	accept_imageload_hide(struct accept_imageload_context * _Context)
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

public	int	accept_imageload_remove(
	struct accept_imageload_context * _Context,
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

public	int	accept_imageload_show(struct accept_imageload_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto6,_Context->y_auto6);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_auto6,_Context->y_auto6,600,160,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_auto6,_Context->y_auto6,600,160,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_auto6+20,_Context->y_auto6+40,560,16,vfh[2],27,0,_Context->msg_auto8[_Context->language],strlen(_Context->msg_auto8[_Context->language]),258);
	visual_frame(_Context->x_auto6+20,_Context->y_auto6+60,560+2,16+2,5);
	visual_text(_Context->x_auto6+20+1,_Context->y_auto6+60+1,560,16,vfh[1],16,24,_Context->buffer_FileName,255,0);
	_Context->trigger_Auto3566=visual_trigger_code(_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]));
	visual_button(_Context->x_auto6+20,_Context->y_auto6+90,56,48,vfh[2],34,0,_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]),1040);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto6+360,_Context->y_auto6+100,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	_Context->trigger_Auto3567=visual_trigger_code(_Context->msg_Auto3567[_Context->language],strlen(_Context->msg_Auto3567[_Context->language]));
	visual_button(_Context->x_auto6+520,_Context->y_auto6+90,56,48,vfh[2],34,0,_Context->msg_Auto3567[_Context->language],strlen(_Context->msg_Auto3567[_Context->language]),1040);
	visual_image(_Context->x_auto6+230,_Context->y_auto6+90,50,54,_Context->msg_auto710[_Context->language],0);
	visual_thaw(_Context->x_auto6,_Context->y_auto6,600,160);

	return(0);
}

private int FileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "This edit field allows the name of the image file to be specified. ";
			mptr[1]=" ";
			mptr[2]=" ";
			mptr[3]="The configuration variable IMAGEPATH will be used to localise the ";
			mptr[4]="image if no explicite path information is provided with the filename. ";
			mptr[5]="  ";
			return(visual_online_help(mptr,6));
			}
			break;
		case 4 : 
			{
			char * mptr[1];
			mptr[0] = "  ";
			return(visual_online_help(mptr,1));
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
			mptr[0] = "By pressing the ACCEPT button any changes made to the various    parameters ";
			mptr[1]="will take effect.  ";
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
			mptr[0] = "This push button gives access to the  File Selection mechanisms allowing ";
			mptr[1]="prompted selection of the image file to be loaded.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3567_help()
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

private int auto6action(struct accept_imageload_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_imageload_hide(_Context);

		_Context->x_auto6 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto6 < 0) { _Context->x_auto6=0; }
		_Context->y_auto6 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto6 < 0) { _Context->y_auto6=0; }
			accept_imageload_show(_Context);

		visual_thaw(_Context->x_auto6,_Context->y_auto6,600,160);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3566_event(struct accept_imageload_context * _Context) {
	return(13);
	return(-1);
}
private int on_Select_event(struct accept_imageload_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_GIF);
		accept_imageload_show(_Context);
;
	return(-1);
}
private int on_Auto3567_event(struct accept_imageload_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_imageload_event(
struct accept_imageload_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto3566 == mb ) return(3);
		if (_Context->trigger_Select == mb ) return(4);
		if (_Context->trigger_Auto3567 == mb ) return(5);
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
			visual_help("viload.htm");
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
		accept_imageload_show(_Context);
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
	&&  ( my >= (_Context->y_auto6+90) ) 
	&&  ( mx <= (_Context->x_auto6+20+56) ) 
	&&  ( my <= (_Context->y_auto6+90+48))) {
		return(3); /* Auto3566 */
		}
	if (( mx >= (_Context->x_auto6+360) ) 
	&&  ( my >= (_Context->y_auto6+100) ) 
	&&  ( mx <= (_Context->x_auto6+360+100) ) 
	&&  ( my <= (_Context->y_auto6+100+30))) {
		return(4); /* Select */
		}
	if (( mx >= (_Context->x_auto6+520) ) 
	&&  ( my >= (_Context->y_auto6+90) ) 
	&&  ( mx <= (_Context->x_auto6+520+56) ) 
	&&  ( my <= (_Context->y_auto6+90+48))) {
		return(5); /* Auto3567 */
		}

	return(-1);
}


public	int	accept_imageload_focus(struct accept_imageload_context * _Context)
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
				/* Auto3566 */
				_Context->trigger_Auto3566=visual_trigger_code(_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]));
				visual_button(_Context->x_auto6+20,_Context->y_auto6+90,56,48,vfh[2],34,0,_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3566=visual_trigger_code(_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]));
	visual_button(_Context->x_auto6+20,_Context->y_auto6+90,56,48,vfh[2],34,0,_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]),1040);
				break;
			case	0x4 :
				/* Select */
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
				visual_button(_Context->x_auto6+360,_Context->y_auto6+100,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto6+360,_Context->y_auto6+100,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;
			case	0x5 :
				/* Auto3567 */
				_Context->trigger_Auto3567=visual_trigger_code(_Context->msg_Auto3567[_Context->language],strlen(_Context->msg_Auto3567[_Context->language]));
				visual_button(_Context->x_auto6+520,_Context->y_auto6+90,56,48,vfh[2],34,0,_Context->msg_Auto3567[_Context->language],strlen(_Context->msg_Auto3567[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3567=visual_trigger_code(_Context->msg_Auto3567[_Context->language],strlen(_Context->msg_Auto3567[_Context->language]));
	visual_button(_Context->x_auto6+520,_Context->y_auto6+90,56,48,vfh[2],34,0,_Context->msg_Auto3567[_Context->language],strlen(_Context->msg_Auto3567[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_imageload_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=5;
			accept_imageload_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_imageload_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (FileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Auto3566_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Select_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Auto3567_help(_Context) != 0) { continue; }
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
					/* Auto3566 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3566=visual_trigger_code(_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]));
						visual_button(_Context->x_auto6+20,_Context->y_auto6+90,56,48,vfh[2],34,0,_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3566=visual_trigger_code(_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]));
	visual_button(_Context->x_auto6+20,_Context->y_auto6+90,56,48,vfh[2],34,0,_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3566_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Select */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
						visual_button(_Context->x_auto6+360,_Context->y_auto6+100,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto6+360,_Context->y_auto6+100,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Select_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto3567 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3567=visual_trigger_code(_Context->msg_Auto3567[_Context->language],strlen(_Context->msg_Auto3567[_Context->language]));
						visual_button(_Context->x_auto6+520,_Context->y_auto6+90,56,48,vfh[2],34,0,_Context->msg_Auto3567[_Context->language],strlen(_Context->msg_Auto3567[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3567=visual_trigger_code(_Context->msg_Auto3567[_Context->language],strlen(_Context->msg_Auto3567[_Context->language]));
	visual_button(_Context->x_auto6+520,_Context->y_auto6+90,56,48,vfh[2],34,0,_Context->msg_Auto3567[_Context->language],strlen(_Context->msg_Auto3567[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3567_event(_Context)) != -1) break;

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

public	int	accept_imageload(
	char * pFileName)
{
	int	status=0;
	struct accept_imageload_context * _Context=(struct accept_imageload_context*) 0;
	status = accept_imageload_create(
	&_Context,
	 pFileName);
	if ( status != 0) return(status);
	status = accept_imageload_show(_Context);
		enter_modal();
	status = accept_imageload_focus(_Context);
		leave_modal();
	status = accept_imageload_hide(_Context);
	status = accept_imageload_remove(
	_Context,
	 pFileName);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _viload_c */
