
#ifndef _verror_c
#define _verror_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : verror.xml                                               */
/* Target         : verror.c                                                 */
/* Identification : 0.0-1177511934-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__auto562   ""
#define fr__auto562   ""
#define it__auto562   ""
#define es__auto562   ""
#define de__auto562   ""
#define nl__auto562   ""
#define pt__auto562   ""
#define xx__auto562   ""
#define en_Auto2721   ""
#define en__Auto2721   ""
#define en_Accept   "ok.gif"
#define fr_Accept   "ok.gif"
#define it_Accept   "ok.gif"
#define es_Accept   "ok.gif"
#define de_Accept   "ok.gif"
#define nl_Accept   "ok.gif"
#define pt_Accept   "ok.gif"
#define xx_Accept   "ok.gif"
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"
#define en_ErrorMsg   ""
#define en__ErrorMsg   ""
#define en_FileName   ""
#define en__FileName   ""
#define en_Auto2722   "bombicon.gif"
#define fr_Auto2722   "bombicon.gif"
#define it_Auto2722   "bombicon.gif"
#define es_Auto2722   "bombicon.gif"
#define de_Auto2722   "bombicon.gif"
#define nl_Auto2722   "bombicon.gif"
#define pt_Auto2722   "bombicon.gif"
#define xx_Auto2722   "bombicon.gif"
#define en__Auto2722   ""
#define fr__Auto2722   ""
#define it__Auto2722   ""
#define es__Auto2722   ""
#define de__Auto2722   ""
#define nl__Auto2722   ""
#define pt__Auto2722   ""
#define xx__Auto2722   ""
#define en_auto758   "bombicon.gif"
#define fr_auto758   "bombicon.gif"
#define it_auto758   "bombicon.gif"
#define es_auto758   "bombicon.gif"
#define de_auto758   "bombicon.gif"
#define nl_auto758   "bombicon.gif"
#define pt_auto758   "bombicon.gif"
#define xx_auto758   "bombicon.gif"
#define en__auto758   ""
#define fr__auto758   ""
#define it__auto758   ""
#define es__auto758   ""
#define de__auto758   ""
#define nl__auto758   ""
#define pt__auto758   ""
#define xx__auto758   ""
#define en_Auto2723   "An unexpected error condition has been encountered during the current operation"
#define fr_Auto2723   "Une erreur inattendue est survenue pendant le traitement en cours"
#define it_Auto2723   "An unexpected error condition has been encountered during the current operation"
#define es_Auto2723   "An unexpected error condition has been encountered during the current operation"
#define de_Auto2723   "An unexpected error condition has been encountered during the current operation"
#define nl_Auto2723   "An unexpected error condition has been encountered during the current operation"
#define pt_Auto2723   "An unexpected error condition has been encountered during the current operation"
#define xx_Auto2723   "An unexpected error condition has been encountered during the current operation"
#define en__Auto2723   ""
#define fr__Auto2723   ""
#define it__Auto2723   ""
#define es__Auto2723   ""
#define de__Auto2723   ""
#define nl__Auto2723   ""
#define pt__Auto2723   ""
#define xx__Auto2723   ""
#define en_Auto2724   "Do you want to retry the operation ?"
#define fr_Auto2724   "Voulez-vous r‚essayer?"
#define it_Auto2724   "Do you want to retry the operation ?"
#define es_Auto2724   "Do you want to retry the operation ?"
#define de_Auto2724   "Do you want to retry the operation ?"
#define nl_Auto2724   "Do you want to retry the operation ?"
#define pt_Auto2724   "Do you want to retry the operation ?"
#define xx_Auto2724   "Do you want to retry the operation ?"
#define en__Auto2724   ""
#define fr__Auto2724   ""
#define it__Auto2724   ""
#define es__Auto2724   ""
#define de__Auto2724   ""
#define nl__Auto2724   ""
#define pt__Auto2724   ""
#define xx__Auto2724   ""

private struct accept_error_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_auto562[8];
	char * hint_auto562[8];
	int	x_auto562;
	int	y_auto562;
	int	w_auto562;
	int	h_auto562;
	char * hint_Auto2721[8];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	char * hint_ErrorMsg[8];
	char	buffer_ErrorMsg[73];
	char * hint_FileName[8];
	char	buffer_FileName[73];
	char * msg_Auto2722[8];
	char * hint_Auto2722[8];
	char * msg_auto758[8];
	char * hint_auto758[8];
	char * msg_Auto2723[8];
	char * hint_Auto2723[8];
	char * msg_Auto2724[8];
	char * hint_Auto2724[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};
static int	vfh[16];

public	int	accept_error_create(
	struct accept_error_context ** cptr,
	char * pErrorMsg,
	char * pFileName)
{

	int i;
	struct accept_error_context * _Context=(struct accept_error_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_error_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=3;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"KK");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_ErrorMsg, 72, pErrorMsg);
		visual_transferin(_Context->buffer_FileName, 72, pFileName);
		}
	for (i=0; i < 8; i++)_Context->msg_auto562[i]=" ";
	_Context->hint_auto562[0]=en__auto562;
	_Context->hint_auto562[1]=fr__auto562;
	_Context->hint_auto562[2]=it__auto562;
	_Context->hint_auto562[3]=es__auto562;
	_Context->hint_auto562[4]=de__auto562;
	_Context->hint_auto562[5]=nl__auto562;
	_Context->hint_auto562[6]=pt__auto562;
	_Context->hint_auto562[7]=xx__auto562;
	_Context->x_auto562=125;
	_Context->y_auto562=125;
	_Context->w_auto562=550;
	_Context->h_auto562=350;
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->hint_Auto2721[0]=en__Auto2721;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->msg_Cancel[2]=it_Cancel;
	_Context->msg_Cancel[3]=es_Cancel;
	_Context->msg_Cancel[4]=de_Cancel;
	_Context->msg_Cancel[5]=nl_Cancel;
	_Context->msg_Cancel[6]=pt_Cancel;
	_Context->msg_Cancel[7]=xx_Cancel;
	_Context->hint_ErrorMsg[0]=en__ErrorMsg;
	_Context->hint_FileName[0]=en__FileName;
	for (i=0; i < 8; i++)_Context->msg_Auto2722[i]=" ";
	_Context->msg_Auto2722[0]=en_Auto2722;
	_Context->msg_Auto2722[1]=fr_Auto2722;
	_Context->msg_Auto2722[2]=it_Auto2722;
	_Context->msg_Auto2722[3]=es_Auto2722;
	_Context->msg_Auto2722[4]=de_Auto2722;
	_Context->msg_Auto2722[5]=nl_Auto2722;
	_Context->msg_Auto2722[6]=pt_Auto2722;
	_Context->msg_Auto2722[7]=xx_Auto2722;
	_Context->hint_Auto2722[0]=en__Auto2722;
	_Context->hint_Auto2722[1]=fr__Auto2722;
	_Context->hint_Auto2722[2]=it__Auto2722;
	_Context->hint_Auto2722[3]=es__Auto2722;
	_Context->hint_Auto2722[4]=de__Auto2722;
	_Context->hint_Auto2722[5]=nl__Auto2722;
	_Context->hint_Auto2722[6]=pt__Auto2722;
	_Context->hint_Auto2722[7]=xx__Auto2722;
	for (i=0; i < 8; i++)_Context->msg_auto758[i]=" ";
	_Context->msg_auto758[0]=en_auto758;
	_Context->msg_auto758[1]=fr_auto758;
	_Context->msg_auto758[2]=it_auto758;
	_Context->msg_auto758[3]=es_auto758;
	_Context->msg_auto758[4]=de_auto758;
	_Context->msg_auto758[5]=nl_auto758;
	_Context->msg_auto758[6]=pt_auto758;
	_Context->msg_auto758[7]=xx_auto758;
	_Context->hint_auto758[0]=en__auto758;
	_Context->hint_auto758[1]=fr__auto758;
	_Context->hint_auto758[2]=it__auto758;
	_Context->hint_auto758[3]=es__auto758;
	_Context->hint_auto758[4]=de__auto758;
	_Context->hint_auto758[5]=nl__auto758;
	_Context->hint_auto758[6]=pt__auto758;
	_Context->hint_auto758[7]=xx__auto758;
	for (i=0; i < 8; i++)_Context->msg_Auto2723[i]=" ";
	_Context->msg_Auto2723[0]=en_Auto2723;
	_Context->msg_Auto2723[1]=fr_Auto2723;
	_Context->msg_Auto2723[2]=it_Auto2723;
	_Context->msg_Auto2723[3]=es_Auto2723;
	_Context->msg_Auto2723[4]=de_Auto2723;
	_Context->msg_Auto2723[5]=nl_Auto2723;
	_Context->msg_Auto2723[6]=pt_Auto2723;
	_Context->msg_Auto2723[7]=xx_Auto2723;
	_Context->hint_Auto2723[0]=en__Auto2723;
	_Context->hint_Auto2723[1]=fr__Auto2723;
	_Context->hint_Auto2723[2]=it__Auto2723;
	_Context->hint_Auto2723[3]=es__Auto2723;
	_Context->hint_Auto2723[4]=de__Auto2723;
	_Context->hint_Auto2723[5]=nl__Auto2723;
	_Context->hint_Auto2723[6]=pt__Auto2723;
	_Context->hint_Auto2723[7]=xx__Auto2723;
	for (i=0; i < 8; i++)_Context->msg_Auto2724[i]=" ";
	_Context->msg_Auto2724[0]=en_Auto2724;
	_Context->msg_Auto2724[1]=fr_Auto2724;
	_Context->msg_Auto2724[2]=it_Auto2724;
	_Context->msg_Auto2724[3]=es_Auto2724;
	_Context->msg_Auto2724[4]=de_Auto2724;
	_Context->msg_Auto2724[5]=nl_Auto2724;
	_Context->msg_Auto2724[6]=pt_Auto2724;
	_Context->msg_Auto2724[7]=xx_Auto2724;
	_Context->hint_Auto2724[0]=en__Auto2724;
	_Context->hint_Auto2724[1]=fr__Auto2724;
	_Context->hint_Auto2724[2]=it__Auto2724;
	_Context->hint_Auto2724[3]=es__Auto2724;
	_Context->hint_Auto2724[4]=de__Auto2724;
	_Context->hint_Auto2724[5]=nl__Auto2724;
	_Context->hint_Auto2724[6]=pt__Auto2724;
	_Context->hint_Auto2724[7]=xx__Auto2724;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto562,_Context->y_auto562,550+10,350+10);
	return(0);
}

public 	int	accept_error_hide(struct accept_error_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_auto562,_Context->y_auto562);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_error_remove(
	struct accept_error_context * _Context,
	char * pErrorMsg,
	char * pFileName)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"KK");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_ErrorMsg, 72, pErrorMsg);
		visual_transferout(_Context->buffer_FileName, 72, pFileName);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_error_show(struct accept_error_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto562,_Context->y_auto562);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_auto562,_Context->y_auto562,550,350,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_auto562,_Context->y_auto562,550,350,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_filzone(_Context->x_auto562+10,_Context->y_auto562+70,530,250,7952,8);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_auto562+190,_Context->y_auto562+260,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto562+310,_Context->y_auto562+260,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_frame(_Context->x_auto562+20,_Context->y_auto562+140,504+2,32+2,5);
	visual_text(_Context->x_auto562+20+1,_Context->y_auto562+140+1,504,32,vfh[2],176,31,_Context->buffer_ErrorMsg,72,3);
	visual_frame(_Context->x_auto562+20,_Context->y_auto562+180,504+2,32+2,5);
	visual_text(_Context->x_auto562+20+1,_Context->y_auto562+180+1,504,32,vfh[2],176,31,_Context->buffer_FileName,72,3);
	visual_image(_Context->x_auto562+30,_Context->y_auto562+90,40,40,_Context->msg_Auto2722[_Context->language],1024);
	visual_image(_Context->x_auto562+480,_Context->y_auto562+90,40,40,_Context->msg_auto758[_Context->language],1027);
	visual_text(_Context->x_auto562+80,_Context->y_auto562+80,391,60,vfh[3],27,0,_Context->msg_Auto2723[_Context->language],strlen(_Context->msg_Auto2723[_Context->language]),1283);
	visual_text(_Context->x_auto562+90,_Context->y_auto562+220,391,40,vfh[3],27,0,_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]),1283);
	visual_thaw(_Context->x_auto562,_Context->y_auto562,550,350);

	return(0);
}

private int auto562action(struct accept_error_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_error_hide(_Context);

		_Context->x_auto562 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto562 < 0) { _Context->x_auto562=0; }
		_Context->y_auto562 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto562 < 0) { _Context->y_auto562=0; }
			accept_error_show(_Context);

		visual_thaw(_Context->x_auto562,_Context->y_auto562,550,350);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_error_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_error_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_error_event(
struct accept_error_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(2);
		if (_Context->trigger_Cancel == mb ) return(3);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_auto562+529) )  
	&&  (my >= (_Context->y_auto562+4) )  
	&&  (mx <= (_Context->x_auto562+546) )  
	&&  (my <= (_Context->y_auto562+20) )) {
		return(1);	/* auto562 */

		}
	if ((mx >= (_Context->x_auto562+513) )  
	&&  (my >= (_Context->y_auto562+4) )  
	&&  (mx <= (_Context->x_auto562+530) )  
	&&  (my <= (_Context->y_auto562+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("verror.htm");
			};
		return(-1);	/* auto562 */

		}
	if ((mx >= (_Context->x_auto562+497) )  
	&&  (my >= (_Context->y_auto562+4) )  
	&&  (mx <= (_Context->x_auto562+514) )  
	&&  (my <= (_Context->y_auto562+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_error_show(_Context);
		return(-1);	/* auto562 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_auto562+4) )  
		&&  (my >= (_Context->y_auto562+4) )  
		&&  (mx <= (_Context->x_auto562+482) )  
		&&  (my <= (_Context->y_auto562+20) )) {
			return( auto562action(_Context) );
			}
		}
	if (( mx >= (_Context->x_auto562+190) ) 
	&&  ( my >= (_Context->y_auto562+260) ) 
	&&  ( mx <= (_Context->x_auto562+190+56) ) 
	&&  ( my <= (_Context->y_auto562+260+48))) {
		return(2); /* Accept */
		}
	if (( mx >= (_Context->x_auto562+310) ) 
	&&  ( my >= (_Context->y_auto562+260) ) 
	&&  ( mx <= (_Context->x_auto562+310+56) ) 
	&&  ( my <= (_Context->y_auto562+260+48))) {
		return(3); /* Cancel */
		}

	return(-1);
}


public	int	accept_error_focus(struct accept_error_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(_Context->x_auto562+190,_Context->y_auto562+260,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_auto562+190,_Context->y_auto562+260,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0x3 :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_auto562+310,_Context->y_auto562+260,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto562+310,_Context->y_auto562+260,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_error_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=3;
			accept_error_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_error_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* auto562 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_auto562+190,_Context->y_auto562+260,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_auto562+190,_Context->y_auto562+260,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_auto562+310,_Context->y_auto562+260,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto562+310,_Context->y_auto562+260,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
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
				_Context->focus_item=3;
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

public	int	accept_error(
	char * pErrorMsg,
	char * pFileName)
{
	int	status=0;
	struct accept_error_context * _Context=(struct accept_error_context*) 0;
	status = accept_error_create(
	&_Context,
	 pErrorMsg,
	 pFileName);
	if ( status != 0) return(status);
	status = accept_error_show(_Context);
		enter_modal();
	status = accept_error_focus(_Context);
		leave_modal();
	status = accept_error_hide(_Context);
	status = accept_error_remove(
	_Context,
	 pErrorMsg,
	 pFileName);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _verror_c */
