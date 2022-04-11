
#ifndef _vfload_c
#define _vfload_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vfload.xml                                               */
/* Target         : vfload.c                                                 */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto3556   ""
#define fr__Auto3556   ""
#define it__Auto3556   ""
#define es__Auto3556   ""
#define de__Auto3556   ""
#define nl__Auto3556   ""
#define pt__Auto3556   ""
#define xx__Auto3556   ""
#define en_Auto3557   "Name of Font to Load"
#define fr_Auto3557   "Nom de police … charger"
#define it_Auto3557   "Name of Font to Load"
#define es_Auto3557   "Name of Font to Load"
#define de_Auto3557   "Name of Font to Load"
#define nl_Auto3557   "Name of Font to Load"
#define pt_Auto3557   "Name of Font to Load"
#define xx_Auto3557   "Name of Font to Load"
#define en_FileName   ""
#define en__FileName   ""
#define en_ConvIso   "Transparent|ISO 8859-1|ISO 8859-2"
#define en__ConvIso   ""
#define en_Auto3558   "ok.gif"
#define fr_Auto3558   "ok.gif"
#define it_Auto3558   "ok.gif"
#define es_Auto3558   "ok.gif"
#define de_Auto3558   "ok.gif"
#define nl_Auto3558   "ok.gif"
#define pt_Auto3558   "ok.gif"
#define xx_Auto3558   "ok.gif"
#define en__Auto3558   ""
#define en_Auto3559   "cancel.gif"
#define fr_Auto3559   "cancel.gif"
#define it_Auto3559   "cancel.gif"
#define es_Auto3559   "cancel.gif"
#define de_Auto3559   "cancel.gif"
#define nl_Auto3559   "cancel.gif"
#define pt_Auto3559   "cancel.gif"
#define xx_Auto3559   "cancel.gif"
#define en__Auto3559   ""
#define en_Select   "&Select File"
#define fr_Select   "&S‚lectionner"
#define it_Select   "&Select File"
#define es_Select   "&Select File"
#define de_Select   "&Select File"
#define nl_Select   "&Select File"
#define pt_Select   "&Select File"
#define xx_Select   "&Select File"
#define en__Select   ""
#define en_System   "System &Font"
#define fr_System   "&Polices systŠmes"
#define it_System   "System &Font"
#define es_System   "System &Font"
#define de_System   "System &Font"
#define nl_System   "System &Font"
#define pt_System   "System &Font"
#define xx_System   "System &Font"
#define en__System   ""

private struct accept_fontload_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3556[8];
	char * hint_Auto3556[8];
	int	x_Auto3556;
	int	y_Auto3556;
	int	w_Auto3556;
	int	h_Auto3556;
	char * msg_Auto3557[8];
	char * hint_Auto3557[8];
	char * hint_FileName[8];
	char	buffer_FileName[256];
	char * msg_ConvIso[8];
	char * hint_ConvIso[8];
	int	value_ConvIso;
	char * msg_Auto3558[8];
	int	trigger_Auto3558;
	char * hint_Auto3558[8];
	char * msg_Auto3559[8];
	int	trigger_Auto3559;
	char * hint_Auto3559[8];
	char * msg_Select[8];
	int	trigger_Select;
	char * hint_Select[8];
	char * msg_System[8];
	int	trigger_System;
	char * hint_System[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};
static int	vfh[16];
private int on_Auto3558_event(struct accept_fontload_context * _Context);
private int on_Auto3559_event(struct accept_fontload_context * _Context);
private int on_Select_event(struct accept_fontload_context * _Context);
private int on_System_event(struct accept_fontload_context * _Context);

public	int	accept_fontload_create(
	struct accept_fontload_context ** cptr,
	char * pFileName,
	char * pConvIso)
{

	int i;
	struct accept_fontload_context * _Context=(struct accept_fontload_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_fontload_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=7;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 255, pFileName);
		visual_transferin((void *) 0, 0, pConvIso);
		if (!( pConvIso )) _Context->value_ConvIso=0;
		else	_Context->value_ConvIso = *((int *)pConvIso);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3556[i]=" ";
	_Context->hint_Auto3556[0]=en__Auto3556;
	_Context->hint_Auto3556[1]=fr__Auto3556;
	_Context->hint_Auto3556[2]=it__Auto3556;
	_Context->hint_Auto3556[3]=es__Auto3556;
	_Context->hint_Auto3556[4]=de__Auto3556;
	_Context->hint_Auto3556[5]=nl__Auto3556;
	_Context->hint_Auto3556[6]=pt__Auto3556;
	_Context->hint_Auto3556[7]=xx__Auto3556;
	_Context->x_Auto3556=105;
	_Context->y_Auto3556=210;
	_Context->w_Auto3556=590;
	_Context->h_Auto3556=180;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3557[i]=" ";
	_Context->msg_Auto3557[0]=en_Auto3557;
	_Context->msg_Auto3557[1]=fr_Auto3557;
	_Context->msg_Auto3557[2]=it_Auto3557;
	_Context->msg_Auto3557[3]=es_Auto3557;
	_Context->msg_Auto3557[4]=de_Auto3557;
	_Context->msg_Auto3557[5]=nl_Auto3557;
	_Context->msg_Auto3557[6]=pt_Auto3557;
	_Context->msg_Auto3557[7]=xx_Auto3557;
	_Context->hint_FileName[0]=en__FileName;
	for (i=0; i < 8; i++)_Context->msg_ConvIso[i]=" ";
	_Context->msg_ConvIso[0]=en_ConvIso;
	_Context->hint_ConvIso[0]=en__ConvIso;
	for (i=0; i < 8; i++)_Context->msg_Auto3558[i]=" ";
	_Context->msg_Auto3558[0]=en_Auto3558;
	_Context->msg_Auto3558[1]=fr_Auto3558;
	_Context->msg_Auto3558[2]=it_Auto3558;
	_Context->msg_Auto3558[3]=es_Auto3558;
	_Context->msg_Auto3558[4]=de_Auto3558;
	_Context->msg_Auto3558[5]=nl_Auto3558;
	_Context->msg_Auto3558[6]=pt_Auto3558;
	_Context->msg_Auto3558[7]=xx_Auto3558;
	_Context->hint_Auto3558[0]=en__Auto3558;
	for (i=0; i < 8; i++)_Context->msg_Auto3559[i]=" ";
	_Context->msg_Auto3559[0]=en_Auto3559;
	_Context->msg_Auto3559[1]=fr_Auto3559;
	_Context->msg_Auto3559[2]=it_Auto3559;
	_Context->msg_Auto3559[3]=es_Auto3559;
	_Context->msg_Auto3559[4]=de_Auto3559;
	_Context->msg_Auto3559[5]=nl_Auto3559;
	_Context->msg_Auto3559[6]=pt_Auto3559;
	_Context->msg_Auto3559[7]=xx_Auto3559;
	_Context->hint_Auto3559[0]=en__Auto3559;
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
	for (i=0; i < 8; i++)_Context->msg_System[i]=" ";
	_Context->msg_System[0]=en_System;
	_Context->msg_System[1]=fr_System;
	_Context->msg_System[2]=it_System;
	_Context->msg_System[3]=es_System;
	_Context->msg_System[4]=de_System;
	_Context->msg_System[5]=nl_System;
	_Context->msg_System[6]=pt_System;
	_Context->msg_System[7]=xx_System;
	_Context->hint_System[0]=en__System;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3556,_Context->y_Auto3556,590+10,180+10);
	return(0);
}

public 	int	accept_fontload_hide(struct accept_fontload_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3556,_Context->y_Auto3556);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_fontload_remove(
	struct accept_fontload_context * _Context,
	char * pFileName,
	char * pConvIso)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 255, pFileName);
		visual_transferout((void *) 0, 0, pConvIso);
		if ( pConvIso != (char *) 0)
			*((int*)pConvIso) = _Context->value_ConvIso;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_fontload_show(struct accept_fontload_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3556,_Context->y_Auto3556);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3556,_Context->y_Auto3556,590,180,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3556,_Context->y_Auto3556,590,180,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto3556+20,_Context->y_Auto3556+40,560,20,vfh[2],38,0,_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]),256);
	visual_frame(_Context->x_Auto3556+20,_Context->y_Auto3556+60,552+2,48+2,5);
	visual_text(_Context->x_Auto3556+20+1,_Context->y_Auto3556+60+1,552,48,vfh[1],16,24,_Context->buffer_FileName,255,0);
	visual_select(_Context->x_Auto3556+230,_Context->y_Auto3556+130,128,48,vfh[2],0,0,parse_selection(_Context->msg_ConvIso[_Context->language],&_Context->value_ConvIso),768);
	_Context->trigger_Auto3558=visual_trigger_code(_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]));
	visual_button(_Context->x_Auto3556+20,_Context->y_Auto3556+120,56,48,vfh[2],34,0,_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]),1040);
	_Context->trigger_Auto3559=visual_trigger_code(_Context->msg_Auto3559[_Context->language],strlen(_Context->msg_Auto3559[_Context->language]));
	visual_button(_Context->x_Auto3556+510,_Context->y_Auto3556+120,56,48,vfh[2],34,0,_Context->msg_Auto3559[_Context->language],strlen(_Context->msg_Auto3559[_Context->language]),1040);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_Auto3556+90,_Context->y_Auto3556+120,126,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	_Context->trigger_System=visual_trigger_code(_Context->msg_System[_Context->language],strlen(_Context->msg_System[_Context->language]));
	visual_button(_Context->x_Auto3556+370,_Context->y_Auto3556+120,126,32,vfh[2],27,24,_Context->msg_System[_Context->language],strlen(_Context->msg_System[_Context->language]),0);
	visual_thaw(_Context->x_Auto3556,_Context->y_Auto3556,590,180);

	return(0);
}

private int FileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This edit field allows the font filename to be specified.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3558_help()
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

private int Auto3559_help()
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

private int Select_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The Select button provides access  to the file selection dialog frame ";
			mptr[1]="allowing prompted selection of the filename of the font to be loaded. ";
			mptr[2]=" ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int System_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This button provides access to the  system font selection dialog frame ";
			mptr[1]="allowing prompted construction of system fontname syntax for the selection ";
			mptr[2]="of system fonts to be loaded.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
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

private int Auto3556action(struct accept_fontload_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_fontload_hide(_Context);

		_Context->x_Auto3556 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3556 < 0) { _Context->x_Auto3556=0; }
		_Context->y_Auto3556 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3556 < 0) { _Context->y_Auto3556=0; }
			accept_fontload_show(_Context);

		visual_thaw(_Context->x_Auto3556,_Context->y_Auto3556,590,180);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3558_event(struct accept_fontload_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto3559_event(struct accept_fontload_context * _Context) {
	return(27);
	return(-1);
}
private int on_Select_event(struct accept_fontload_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_FMF);
		accept_fontload_show(_Context);
;
	return(-1);
}
private int on_System_event(struct accept_fontload_context * _Context) {
	char*allocate_string(char*);
	char*sptr;
	if((sptr=allocate_string(_Context->buffer_FileName))!=(char*)0){
	if(system_font_selector(&sptr)!=27){
	if(sptr)
	strcpy(_Context->buffer_FileName,sptr);
	}
	if(sptr)
	liberate(sptr);
		accept_fontload_show(_Context);
;
	}
	return(-1);
}


public	int	accept_fontload_event(
struct accept_fontload_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto3558 == mb ) return(4);
		if (_Context->trigger_Auto3559 == mb ) return(5);
		if (_Context->trigger_Select == mb ) return(6);
		if (_Context->trigger_System == mb ) return(7);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x1031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3556+569) )  
	&&  (my >= (_Context->y_Auto3556+4) )  
	&&  (mx <= (_Context->x_Auto3556+586) )  
	&&  (my <= (_Context->y_Auto3556+20) )) {
		return(1);	/* Auto3556 */

		}
	if ((mx >= (_Context->x_Auto3556+553) )  
	&&  (my >= (_Context->y_Auto3556+4) )  
	&&  (mx <= (_Context->x_Auto3556+570) )  
	&&  (my <= (_Context->y_Auto3556+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vfload.htm");
			};
		return(-1);	/* Auto3556 */

		}
	if ((mx >= (_Context->x_Auto3556+537) )  
	&&  (my >= (_Context->y_Auto3556+4) )  
	&&  (mx <= (_Context->x_Auto3556+554) )  
	&&  (my <= (_Context->y_Auto3556+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_fontload_show(_Context);
		return(-1);	/* Auto3556 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3556+4) )  
		&&  (my >= (_Context->y_Auto3556+4) )  
		&&  (mx <= (_Context->x_Auto3556+522) )  
		&&  (my <= (_Context->y_Auto3556+20) )) {
			return( Auto3556action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3556+20) ) 
	&&  ( my >= (_Context->y_Auto3556+60) ) 
	&&  ( mx <= (_Context->x_Auto3556+20+552) ) 
	&&  ( my <= (_Context->y_Auto3556+60+48))) {
		return(2); /* FileName */
		}
	if (( mx >= (_Context->x_Auto3556+230+0) ) 
	&&  ( my >= (_Context->y_Auto3556+130) ) 
	&&  ( mx <= (_Context->x_Auto3556+230+128) ) 
	&&  ( my <= (_Context->y_Auto3556+130+16))) {
		return(3); /* ConvIso */
		}
	if (( mx >= (_Context->x_Auto3556+20) ) 
	&&  ( my >= (_Context->y_Auto3556+120) ) 
	&&  ( mx <= (_Context->x_Auto3556+20+56) ) 
	&&  ( my <= (_Context->y_Auto3556+120+48))) {
		return(4); /* Auto3558 */
		}
	if (( mx >= (_Context->x_Auto3556+510) ) 
	&&  ( my >= (_Context->y_Auto3556+120) ) 
	&&  ( mx <= (_Context->x_Auto3556+510+56) ) 
	&&  ( my <= (_Context->y_Auto3556+120+48))) {
		return(5); /* Auto3559 */
		}
	if (( mx >= (_Context->x_Auto3556+90) ) 
	&&  ( my >= (_Context->y_Auto3556+120) ) 
	&&  ( mx <= (_Context->x_Auto3556+90+126) ) 
	&&  ( my <= (_Context->y_Auto3556+120+32))) {
		return(6); /* Select */
		}
	if (( mx >= (_Context->x_Auto3556+370) ) 
	&&  ( my >= (_Context->y_Auto3556+120) ) 
	&&  ( mx <= (_Context->x_Auto3556+370+126) ) 
	&&  ( my <= (_Context->y_Auto3556+120+32))) {
		return(7); /* System */
		}

	return(-1);
}


public	int	accept_fontload_focus(struct accept_fontload_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(_Context->x_Auto3556+20+1,_Context->y_Auto3556+60+1,552,48,vfh[1],_Context->buffer_FileName,255);
			break;
			case	0x3 :
				/* ConvIso */
				_Context->keycode = visual_select(_Context->x_Auto3556+230,_Context->y_Auto3556+130,128,48,vfh[2],0,0,parse_selection(_Context->msg_ConvIso[_Context->language],&_Context->value_ConvIso),770);
				break;
			case	0x4 :
				/* Auto3558 */
				_Context->trigger_Auto3558=visual_trigger_code(_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]));
				visual_button(_Context->x_Auto3556+20,_Context->y_Auto3556+120,56,48,vfh[2],34,0,_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3558=visual_trigger_code(_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]));
	visual_button(_Context->x_Auto3556+20,_Context->y_Auto3556+120,56,48,vfh[2],34,0,_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]),1040);
				break;
			case	0x5 :
				/* Auto3559 */
				_Context->trigger_Auto3559=visual_trigger_code(_Context->msg_Auto3559[_Context->language],strlen(_Context->msg_Auto3559[_Context->language]));
				visual_button(_Context->x_Auto3556+510,_Context->y_Auto3556+120,56,48,vfh[2],34,0,_Context->msg_Auto3559[_Context->language],strlen(_Context->msg_Auto3559[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3559=visual_trigger_code(_Context->msg_Auto3559[_Context->language],strlen(_Context->msg_Auto3559[_Context->language]));
	visual_button(_Context->x_Auto3556+510,_Context->y_Auto3556+120,56,48,vfh[2],34,0,_Context->msg_Auto3559[_Context->language],strlen(_Context->msg_Auto3559[_Context->language]),1040);
				break;
			case	0x6 :
				/* Select */
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
				visual_button(_Context->x_Auto3556+90,_Context->y_Auto3556+120,126,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_Auto3556+90,_Context->y_Auto3556+120,126,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;
			case	0x7 :
				/* System */
				_Context->trigger_System=visual_trigger_code(_Context->msg_System[_Context->language],strlen(_Context->msg_System[_Context->language]));
				visual_button(_Context->x_Auto3556+370,_Context->y_Auto3556+120,126,32,vfh[2],27,24,_Context->msg_System[_Context->language],strlen(_Context->msg_System[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_System=visual_trigger_code(_Context->msg_System[_Context->language],strlen(_Context->msg_System[_Context->language]));
	visual_button(_Context->x_Auto3556+370,_Context->y_Auto3556+120,126,32,vfh[2],27,24,_Context->msg_System[_Context->language],strlen(_Context->msg_System[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_fontload_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=7;
			accept_fontload_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_fontload_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (FileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Auto3558_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Auto3559_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (Select_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (System_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3556 */
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
					/* ConvIso */
					continue;
				case	0x4 :
					/* Auto3558 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3558=visual_trigger_code(_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]));
						visual_button(_Context->x_Auto3556+20,_Context->y_Auto3556+120,56,48,vfh[2],34,0,_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3558=visual_trigger_code(_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]));
	visual_button(_Context->x_Auto3556+20,_Context->y_Auto3556+120,56,48,vfh[2],34,0,_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3558_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto3559 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3559=visual_trigger_code(_Context->msg_Auto3559[_Context->language],strlen(_Context->msg_Auto3559[_Context->language]));
						visual_button(_Context->x_Auto3556+510,_Context->y_Auto3556+120,56,48,vfh[2],34,0,_Context->msg_Auto3559[_Context->language],strlen(_Context->msg_Auto3559[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3559=visual_trigger_code(_Context->msg_Auto3559[_Context->language],strlen(_Context->msg_Auto3559[_Context->language]));
	visual_button(_Context->x_Auto3556+510,_Context->y_Auto3556+120,56,48,vfh[2],34,0,_Context->msg_Auto3559[_Context->language],strlen(_Context->msg_Auto3559[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3559_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Select */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
						visual_button(_Context->x_Auto3556+90,_Context->y_Auto3556+120,126,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_Auto3556+90,_Context->y_Auto3556+120,126,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Select_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* System */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_System=visual_trigger_code(_Context->msg_System[_Context->language],strlen(_Context->msg_System[_Context->language]));
						visual_button(_Context->x_Auto3556+370,_Context->y_Auto3556+120,126,32,vfh[2],27,24,_Context->msg_System[_Context->language],strlen(_Context->msg_System[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_System=visual_trigger_code(_Context->msg_System[_Context->language],strlen(_Context->msg_System[_Context->language]));
	visual_button(_Context->x_Auto3556+370,_Context->y_Auto3556+120,126,32,vfh[2],27,24,_Context->msg_System[_Context->language],strlen(_Context->msg_System[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_System_event(_Context)) != -1) break;

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

public	int	accept_fontload(
	char * pFileName,
	char * pConvIso)
{
	int	status=0;
	struct accept_fontload_context * _Context=(struct accept_fontload_context*) 0;
	status = accept_fontload_create(
	&_Context,
	 pFileName,
	 pConvIso);
	if ( status != 0) return(status);
	status = accept_fontload_show(_Context);
		enter_modal();
	status = accept_fontload_focus(_Context);
		leave_modal();
	status = accept_fontload_hide(_Context);
	status = accept_fontload_remove(
	_Context,
	 pFileName,
	 pConvIso);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vfload_c */
