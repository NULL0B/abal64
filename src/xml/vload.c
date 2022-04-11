
#ifndef _vload_c
#define _vload_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vload.xml                                                */
/* Target         : vload.c                                                  */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__auto2   ""
#define fr__auto2   ""
#define it__auto2   ""
#define es__auto2   ""
#define de__auto2   ""
#define nl__auto2   ""
#define pt__auto2   ""
#define xx__auto2   ""
#define en_auto7   "Name of Form to Load"
#define fr_auto7   "Nom du formulaire … charger"
#define it_auto7   "Name of Form to Load"
#define es_auto7   "Name of Form to Load"
#define de_auto7   "Name of Form to Load"
#define nl_auto7   "Name of Form to Load"
#define pt_auto7   "Name of Form to Load"
#define xx_auto7   "Name of Form to Load"
#define en_FileName   ""
#define en_Auto3572   "ok.gif"
#define fr_Auto3572   "ok.gif"
#define it_Auto3572   "ok.gif"
#define es_Auto3572   "ok.gif"
#define de_Auto3572   "ok.gif"
#define nl_Auto3572   "ok.gif"
#define pt_Auto3572   "ok.gif"
#define xx_Auto3572   "ok.gif"
#define en_Select   "&Select"
#define fr_Select   "&S‚lectionner"
#define it_Select   "&Select"
#define es_Select   "&Select"
#define de_Select   "&Select"
#define nl_Select   "&Select"
#define pt_Select   "&Select"
#define xx_Select   "&Select"
#define en_Auto3573   "cancel.gif"
#define fr_Auto3573   "cancel.gif"
#define it_Auto3573   "cancel.gif"
#define es_Auto3573   "cancel.gif"
#define de_Auto3573   "cancel.gif"
#define nl_Auto3573   "cancel.gif"
#define pt_Auto3573   "cancel.gif"
#define xx_Auto3573   "cancel.gif"
#define en_Auto3574   "formicon.gif"
#define fr_Auto3574   "formicon.gif"
#define it_Auto3574   "formicon.gif"
#define es_Auto3574   "formicon.gif"
#define de_Auto3574   "formicon.gif"
#define nl_Auto3574   "formicon.gif"
#define pt_Auto3574   "formicon.gif"
#define xx_Auto3574   "formicon.gif"

private struct accept_form_load_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_auto2[8];
	char * hint_auto2[8];
	int	x_auto2;
	int	y_auto2;
	int	w_auto2;
	int	h_auto2;
	char * msg_auto7[8];
	char * hint_auto7[8];
	char * hint_FileName[8];
	char	buffer_FileName[256];
	char * msg_Auto3572[8];
	int	trigger_Auto3572;
	char * hint_Auto3572[8];
	char * msg_Select[8];
	int	trigger_Select;
	char * hint_Select[8];
	char * msg_Auto3573[8];
	int	trigger_Auto3573;
	char * hint_Auto3573[8];
	char * msg_Auto3574[8];
	char * hint_Auto3574[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};
static int	vfh[16];
private int on_Auto3572_event(struct accept_form_load_context * _Context);
private int on_Select_event(struct accept_form_load_context * _Context);
private int on_Auto3573_event(struct accept_form_load_context * _Context);

public	int	accept_form_load_create(
	struct accept_form_load_context ** cptr,
	char * pFileName)
{

	int i;
	struct accept_form_load_context * _Context=(struct accept_form_load_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_form_load_context ) ) ))
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
	for (i=0; i < 8; i++)_Context->msg_auto2[i]=" ";
	_Context->hint_auto2[0]=en__auto2;
	_Context->hint_auto2[1]=fr__auto2;
	_Context->hint_auto2[2]=it__auto2;
	_Context->hint_auto2[3]=es__auto2;
	_Context->hint_auto2[4]=de__auto2;
	_Context->hint_auto2[5]=nl__auto2;
	_Context->hint_auto2[6]=pt__auto2;
	_Context->hint_auto2[7]=xx__auto2;
	_Context->x_auto2=100;
	_Context->y_auto2=210;
	_Context->w_auto2=600;
	_Context->h_auto2=180;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_auto7[i]=" ";
	_Context->msg_auto7[0]=en_auto7;
	_Context->msg_auto7[1]=fr_auto7;
	_Context->msg_auto7[2]=it_auto7;
	_Context->msg_auto7[3]=es_auto7;
	_Context->msg_auto7[4]=de_auto7;
	_Context->msg_auto7[5]=nl_auto7;
	_Context->msg_auto7[6]=pt_auto7;
	_Context->msg_auto7[7]=xx_auto7;
	for (i=0; i < 8; i++)_Context->msg_Auto3572[i]=" ";
	_Context->msg_Auto3572[0]=en_Auto3572;
	_Context->msg_Auto3572[1]=fr_Auto3572;
	_Context->msg_Auto3572[2]=it_Auto3572;
	_Context->msg_Auto3572[3]=es_Auto3572;
	_Context->msg_Auto3572[4]=de_Auto3572;
	_Context->msg_Auto3572[5]=nl_Auto3572;
	_Context->msg_Auto3572[6]=pt_Auto3572;
	_Context->msg_Auto3572[7]=xx_Auto3572;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	_Context->msg_Select[2]=it_Select;
	_Context->msg_Select[3]=es_Select;
	_Context->msg_Select[4]=de_Select;
	_Context->msg_Select[5]=nl_Select;
	_Context->msg_Select[6]=pt_Select;
	_Context->msg_Select[7]=xx_Select;
	for (i=0; i < 8; i++)_Context->msg_Auto3573[i]=" ";
	_Context->msg_Auto3573[0]=en_Auto3573;
	_Context->msg_Auto3573[1]=fr_Auto3573;
	_Context->msg_Auto3573[2]=it_Auto3573;
	_Context->msg_Auto3573[3]=es_Auto3573;
	_Context->msg_Auto3573[4]=de_Auto3573;
	_Context->msg_Auto3573[5]=nl_Auto3573;
	_Context->msg_Auto3573[6]=pt_Auto3573;
	_Context->msg_Auto3573[7]=xx_Auto3573;
	for (i=0; i < 8; i++)_Context->msg_Auto3574[i]=" ";
	_Context->msg_Auto3574[0]=en_Auto3574;
	_Context->msg_Auto3574[1]=fr_Auto3574;
	_Context->msg_Auto3574[2]=it_Auto3574;
	_Context->msg_Auto3574[3]=es_Auto3574;
	_Context->msg_Auto3574[4]=de_Auto3574;
	_Context->msg_Auto3574[5]=nl_Auto3574;
	_Context->msg_Auto3574[6]=pt_Auto3574;
	_Context->msg_Auto3574[7]=xx_Auto3574;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto2,_Context->y_auto2,600+10,180+10);
	return(0);
}

public 	int	accept_form_load_hide(struct accept_form_load_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_auto2,_Context->y_auto2);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_form_load_remove(
	struct accept_form_load_context * _Context,
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

public	int	accept_form_load_show(struct accept_form_load_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto2,_Context->y_auto2);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_auto2,_Context->y_auto2,600,180,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_auto2,_Context->y_auto2,600,180,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_auto2+20,_Context->y_auto2+40,560,16,vfh[2],34,0,_Context->msg_auto7[_Context->language],strlen(_Context->msg_auto7[_Context->language]),258);
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+60,560+2,16+2,5);
	visual_text(_Context->x_auto2+20+1,_Context->y_auto2+60+1,560,16,vfh[1],34,0,_Context->buffer_FileName,255,0);
	_Context->trigger_Auto3572=visual_trigger_code(_Context->msg_Auto3572[_Context->language],strlen(_Context->msg_Auto3572[_Context->language]));
	visual_button(_Context->x_auto2+20,_Context->y_auto2+120,56,48,vfh[2],34,0,_Context->msg_Auto3572[_Context->language],strlen(_Context->msg_Auto3572[_Context->language]),1040);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto2+360,_Context->y_auto2+130,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	_Context->trigger_Auto3573=visual_trigger_code(_Context->msg_Auto3573[_Context->language],strlen(_Context->msg_Auto3573[_Context->language]));
	visual_button(_Context->x_auto2+520,_Context->y_auto2+120,56,48,vfh[2],34,0,_Context->msg_Auto3573[_Context->language],strlen(_Context->msg_Auto3573[_Context->language]),1040);
	visual_image(_Context->x_auto2+220,_Context->y_auto2+110,50,50,_Context->msg_Auto3574[_Context->language],0);
	visual_thaw(_Context->x_auto2,_Context->y_auto2,600,180);

	return(0);
}

private int FileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows the data entry of the full path and  filename ";
			mptr[1]="of the file from which the model is to be loaded.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3572_help()
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
			mptr[0] = "The Select button gives access  to the file selection dialog frame ";
			mptr[1]="allowing prompted selection of the filename.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3573_help()
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

private int auto2action(struct accept_form_load_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_form_load_hide(_Context);

		_Context->x_auto2 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto2 < 0) { _Context->x_auto2=0; }
		_Context->y_auto2 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto2 < 0) { _Context->y_auto2=0; }
			accept_form_load_show(_Context);

		visual_thaw(_Context->x_auto2,_Context->y_auto2,600,180);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3572_event(struct accept_form_load_context * _Context) {
	return(13);
	return(-1);
}
private int on_Select_event(struct accept_form_load_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_SNG);
		accept_form_load_show(_Context);
;
	return(-1);
}
private int on_Auto3573_event(struct accept_form_load_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_form_load_event(
struct accept_form_load_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto3572 == mb ) return(3);
		if (_Context->trigger_Select == mb ) return(4);
		if (_Context->trigger_Auto3573 == mb ) return(5);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_auto2+579) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+596) )  
	&&  (my <= (_Context->y_auto2+20) )) {
		return(1);	/* auto2 */

		}
	if ((mx >= (_Context->x_auto2+563) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+580) )  
	&&  (my <= (_Context->y_auto2+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vload.htm");
			};
		return(-1);	/* auto2 */

		}
	if ((mx >= (_Context->x_auto2+547) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+564) )  
	&&  (my <= (_Context->y_auto2+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_form_load_show(_Context);
		return(-1);	/* auto2 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_auto2+4) )  
		&&  (my >= (_Context->y_auto2+4) )  
		&&  (mx <= (_Context->x_auto2+532) )  
		&&  (my <= (_Context->y_auto2+20) )) {
			return( auto2action(_Context) );
			}
		}
	if (( mx >= (_Context->x_auto2+20) ) 
	&&  ( my >= (_Context->y_auto2+60) ) 
	&&  ( mx <= (_Context->x_auto2+20+560) ) 
	&&  ( my <= (_Context->y_auto2+60+16))) {
		return(2); /* FileName */
		}
	if (( mx >= (_Context->x_auto2+20) ) 
	&&  ( my >= (_Context->y_auto2+120) ) 
	&&  ( mx <= (_Context->x_auto2+20+56) ) 
	&&  ( my <= (_Context->y_auto2+120+48))) {
		return(3); /* Auto3572 */
		}
	if (( mx >= (_Context->x_auto2+360) ) 
	&&  ( my >= (_Context->y_auto2+130) ) 
	&&  ( mx <= (_Context->x_auto2+360+100) ) 
	&&  ( my <= (_Context->y_auto2+130+30))) {
		return(4); /* Select */
		}
	if (( mx >= (_Context->x_auto2+520) ) 
	&&  ( my >= (_Context->y_auto2+120) ) 
	&&  ( mx <= (_Context->x_auto2+520+56) ) 
	&&  ( my <= (_Context->y_auto2+120+48))) {
		return(5); /* Auto3573 */
		}

	return(-1);
}


public	int	accept_form_load_focus(struct accept_form_load_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(_Context->x_auto2+20+1,_Context->y_auto2+60+1,560,16,vfh[1],_Context->buffer_FileName,255);
			break;
			case	0x3 :
				/* Auto3572 */
				_Context->trigger_Auto3572=visual_trigger_code(_Context->msg_Auto3572[_Context->language],strlen(_Context->msg_Auto3572[_Context->language]));
				visual_button(_Context->x_auto2+20,_Context->y_auto2+120,56,48,vfh[2],34,0,_Context->msg_Auto3572[_Context->language],strlen(_Context->msg_Auto3572[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3572=visual_trigger_code(_Context->msg_Auto3572[_Context->language],strlen(_Context->msg_Auto3572[_Context->language]));
	visual_button(_Context->x_auto2+20,_Context->y_auto2+120,56,48,vfh[2],34,0,_Context->msg_Auto3572[_Context->language],strlen(_Context->msg_Auto3572[_Context->language]),1040);
				break;
			case	0x4 :
				/* Select */
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
				visual_button(_Context->x_auto2+360,_Context->y_auto2+130,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto2+360,_Context->y_auto2+130,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;
			case	0x5 :
				/* Auto3573 */
				_Context->trigger_Auto3573=visual_trigger_code(_Context->msg_Auto3573[_Context->language],strlen(_Context->msg_Auto3573[_Context->language]));
				visual_button(_Context->x_auto2+520,_Context->y_auto2+120,56,48,vfh[2],34,0,_Context->msg_Auto3573[_Context->language],strlen(_Context->msg_Auto3573[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3573=visual_trigger_code(_Context->msg_Auto3573[_Context->language],strlen(_Context->msg_Auto3573[_Context->language]));
	visual_button(_Context->x_auto2+520,_Context->y_auto2+120,56,48,vfh[2],34,0,_Context->msg_Auto3573[_Context->language],strlen(_Context->msg_Auto3573[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_form_load_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=5;
			accept_form_load_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_form_load_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (FileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Auto3572_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Select_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Auto3573_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* auto2 */
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
					/* Auto3572 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3572=visual_trigger_code(_Context->msg_Auto3572[_Context->language],strlen(_Context->msg_Auto3572[_Context->language]));
						visual_button(_Context->x_auto2+20,_Context->y_auto2+120,56,48,vfh[2],34,0,_Context->msg_Auto3572[_Context->language],strlen(_Context->msg_Auto3572[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3572=visual_trigger_code(_Context->msg_Auto3572[_Context->language],strlen(_Context->msg_Auto3572[_Context->language]));
	visual_button(_Context->x_auto2+20,_Context->y_auto2+120,56,48,vfh[2],34,0,_Context->msg_Auto3572[_Context->language],strlen(_Context->msg_Auto3572[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3572_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Select */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
						visual_button(_Context->x_auto2+360,_Context->y_auto2+130,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto2+360,_Context->y_auto2+130,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Select_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto3573 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3573=visual_trigger_code(_Context->msg_Auto3573[_Context->language],strlen(_Context->msg_Auto3573[_Context->language]));
						visual_button(_Context->x_auto2+520,_Context->y_auto2+120,56,48,vfh[2],34,0,_Context->msg_Auto3573[_Context->language],strlen(_Context->msg_Auto3573[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3573=visual_trigger_code(_Context->msg_Auto3573[_Context->language],strlen(_Context->msg_Auto3573[_Context->language]));
	visual_button(_Context->x_auto2+520,_Context->y_auto2+120,56,48,vfh[2],34,0,_Context->msg_Auto3573[_Context->language],strlen(_Context->msg_Auto3573[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3573_event(_Context)) != -1) break;

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

public	int	accept_form_load(
	char * pFileName)
{
	int	status=0;
	struct accept_form_load_context * _Context=(struct accept_form_load_context*) 0;
	status = accept_form_load_create(
	&_Context,
	 pFileName);
	if ( status != 0) return(status);
	status = accept_form_load_show(_Context);
		enter_modal();
	status = accept_form_load_focus(_Context);
		leave_modal();
	status = accept_form_load_hide(_Context);
	status = accept_form_load_remove(
	_Context,
	 pFileName);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vload_c */
