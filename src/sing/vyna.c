
#ifndef _vyna_c
#define _vyna_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vyna.xml                                                 */
/* Target         : vyna.c                                                   */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto3621   ""
#define fr__Auto3621   ""
#define it__Auto3621   ""
#define es__Auto3621   ""
#define de__Auto3621   ""
#define nl__Auto3621   ""
#define pt__Auto3621   ""
#define xx__Auto3621   ""
#define en_Message1   ""
#define en__Message1   ""
#define en_Message2   ""
#define en__Message2   ""
#define en_Auto3626   "WARNING"
#define fr_Auto3626   "ATTENTION"
#define it_Auto3626   "WARNING"
#define es_Auto3626   "WARNING"
#define de_Auto3626   "ACHTUNG"
#define nl_Auto3626   "WARNING"
#define pt_Auto3626   "WARNING"
#define xx_Auto3626   "THOIR AN AIRE"
#define en__auto1111   ""
#define fr__auto1111   ""
#define it__auto1111   ""
#define es__auto1111   ""
#define de__auto1111   ""
#define nl__auto1111   ""
#define pt__auto1111   ""
#define xx__auto1111   ""
#define en__Auto3627   ""
#define fr__Auto3627   ""
#define it__Auto3627   ""
#define es__Auto3627   ""
#define de__Auto3627   ""
#define nl__Auto3627   ""
#define pt__Auto3627   ""
#define xx__Auto3627   ""
#define en_Cancel   "&No"
#define fr_Cancel   "&Non"
#define it_Cancel   "&Non"
#define es_Cancel   "&No"
#define de_Cancel   "&Nein"
#define nl_Cancel   "&Nein"
#define pt_Cancel   "&No"
#define xx_Cancel   "&No"
#define en__Cancel   ""
#define fr__Cancel   ""
#define it__Cancel   ""
#define es__Cancel   ""
#define de__Cancel   ""
#define nl__Cancel   ""
#define pt__Cancel   ""
#define xx__Cancel   ""
#define en_Abandon   "&Abandon"
#define fr_Abandon   "&Abandon"
#define it_Abandon   "&Abandon"
#define es_Abandon   "&Abandon"
#define de_Abandon   "&Abandon"
#define nl_Abandon   "&Abandon"
#define pt_Abandon   "&Abandon"
#define xx_Abandon   "&Abandon"
#define en__Abandon   ""
#define fr__Abandon   ""
#define it__Abandon   ""
#define es__Abandon   ""
#define de__Abandon   ""
#define nl__Abandon   ""
#define pt__Abandon   ""
#define xx__Abandon   ""
#define en_Accept   "&Yes"
#define fr_Accept   "&Oui"
#define it_Accept   "&Yes"
#define es_Accept   "&Yes"
#define de_Accept   "&Yes"
#define nl_Accept   "&Yes"
#define pt_Accept   "&Yes"
#define xx_Accept   "&Yes"
#define en__Accept   ""
#define fr__Accept   ""
#define it__Accept   ""
#define es__Accept   ""
#define de__Accept   ""
#define nl__Accept   ""
#define pt__Accept   ""
#define xx__Accept   ""

private struct accept_yes_no_abandon_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3621[8];
	char * hint_Auto3621[8];
	int	x_Auto3621;
	int	y_Auto3621;
	int	w_Auto3621;
	int	h_Auto3621;
	char * hint_Auto3622[8];
	char * hint_Auto3623[8];
	char * hint_Auto3624[8];
	char * hint_Auto3625[8];
	char * hint_Message1[8];
	char	buffer_Message1[48];
	char * hint_Message2[8];
	char	buffer_Message2[48];
	char * msg_Auto3626[8];
	char * hint_Auto3626[8];
	char * msg_auto1111[8];
	char * hint_auto1111[8];
	char * msg_Auto3627[8];
	char * hint_Auto3627[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	char * msg_Abandon[8];
	int	trigger_Abandon;
	char * hint_Abandon[8];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};
static int	vfh[16];
private int on_Cancel_event(struct accept_yes_no_abandon_context * _Context);
private int on_Abandon_event(struct accept_yes_no_abandon_context * _Context);
private int on_Accept_event(struct accept_yes_no_abandon_context * _Context);

public	int	accept_yes_no_abandon_create(
	struct accept_yes_no_abandon_context ** cptr,
	char * pMessage1,
	char * pMessage2)
{

	int i;
	struct accept_yes_no_abandon_context * _Context=(struct accept_yes_no_abandon_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_yes_no_abandon_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=4;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"KK");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Message1, 47, pMessage1);
		visual_transferin(_Context->buffer_Message2, 47, pMessage2);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3621[i]=" ";
	_Context->hint_Auto3621[0]=en__Auto3621;
	_Context->hint_Auto3621[1]=fr__Auto3621;
	_Context->hint_Auto3621[2]=it__Auto3621;
	_Context->hint_Auto3621[3]=es__Auto3621;
	_Context->hint_Auto3621[4]=de__Auto3621;
	_Context->hint_Auto3621[5]=nl__Auto3621;
	_Context->hint_Auto3621[6]=pt__Auto3621;
	_Context->hint_Auto3621[7]=xx__Auto3621;
	_Context->x_Auto3621=160;
	_Context->y_Auto3621=160;
	_Context->w_Auto3621=480;
	_Context->h_Auto3621=280;
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->hint_Message1[0]=en__Message1;
	_Context->hint_Message2[0]=en__Message2;
	for (i=0; i < 8; i++)_Context->msg_Auto3626[i]=" ";
	_Context->msg_Auto3626[0]=en_Auto3626;
	_Context->msg_Auto3626[1]=fr_Auto3626;
	_Context->msg_Auto3626[2]=it_Auto3626;
	_Context->msg_Auto3626[3]=es_Auto3626;
	_Context->msg_Auto3626[4]=de_Auto3626;
	_Context->msg_Auto3626[5]=nl_Auto3626;
	_Context->msg_Auto3626[6]=pt_Auto3626;
	_Context->msg_Auto3626[7]=xx_Auto3626;
	for (i=0; i < 8; i++)_Context->msg_auto1111[i]=" ";
	_Context->hint_auto1111[0]=en__auto1111;
	_Context->hint_auto1111[1]=fr__auto1111;
	_Context->hint_auto1111[2]=it__auto1111;
	_Context->hint_auto1111[3]=es__auto1111;
	_Context->hint_auto1111[4]=de__auto1111;
	_Context->hint_auto1111[5]=nl__auto1111;
	_Context->hint_auto1111[6]=pt__auto1111;
	_Context->hint_auto1111[7]=xx__auto1111;
	for (i=0; i < 8; i++)_Context->msg_Auto3627[i]=" ";
	_Context->hint_Auto3627[0]=en__Auto3627;
	_Context->hint_Auto3627[1]=fr__Auto3627;
	_Context->hint_Auto3627[2]=it__Auto3627;
	_Context->hint_Auto3627[3]=es__Auto3627;
	_Context->hint_Auto3627[4]=de__Auto3627;
	_Context->hint_Auto3627[5]=nl__Auto3627;
	_Context->hint_Auto3627[6]=pt__Auto3627;
	_Context->hint_Auto3627[7]=xx__Auto3627;
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
	_Context->hint_Cancel[1]=fr__Cancel;
	_Context->hint_Cancel[2]=it__Cancel;
	_Context->hint_Cancel[3]=es__Cancel;
	_Context->hint_Cancel[4]=de__Cancel;
	_Context->hint_Cancel[5]=nl__Cancel;
	_Context->hint_Cancel[6]=pt__Cancel;
	_Context->hint_Cancel[7]=xx__Cancel;
	for (i=0; i < 8; i++)_Context->msg_Abandon[i]=" ";
	_Context->msg_Abandon[0]=en_Abandon;
	_Context->msg_Abandon[1]=fr_Abandon;
	_Context->msg_Abandon[2]=it_Abandon;
	_Context->msg_Abandon[3]=es_Abandon;
	_Context->msg_Abandon[4]=de_Abandon;
	_Context->msg_Abandon[5]=nl_Abandon;
	_Context->msg_Abandon[6]=pt_Abandon;
	_Context->msg_Abandon[7]=xx_Abandon;
	_Context->hint_Abandon[0]=en__Abandon;
	_Context->hint_Abandon[1]=fr__Abandon;
	_Context->hint_Abandon[2]=it__Abandon;
	_Context->hint_Abandon[3]=es__Abandon;
	_Context->hint_Abandon[4]=de__Abandon;
	_Context->hint_Abandon[5]=nl__Abandon;
	_Context->hint_Abandon[6]=pt__Abandon;
	_Context->hint_Abandon[7]=xx__Abandon;
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
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(160,160,480+10,280+10);
	return(0);
}

public 	int	accept_yes_no_abandon_hide(struct accept_yes_no_abandon_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,160,160);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_yes_no_abandon_remove(
	struct accept_yes_no_abandon_context * _Context,
	char * pMessage1,
	char * pMessage2)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"KK");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Message1, 47, pMessage1);
		visual_transferout(_Context->buffer_Message2, 47, pMessage2);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_yes_no_abandon_show(struct accept_yes_no_abandon_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,160,160);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(160,160,480,280,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(160,160,480,280,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_frame(170,190,460,240,4);
	visual_frame(180,260,440,160,4);
	visual_filzone(185,265,429,149,28,0);
	visual_frame(201,362,399,46,3);
	visual_text(180,200,440,50,vfh[3],28,27,_Context->msg_Auto3626[_Context->language],strlen(_Context->msg_Auto3626[_Context->language]),3);
	visual_text(200,270,400,44,vfh[2],27,28,_Context->buffer_Message1,strlen(_Context->buffer_Message1),259);
	visual_text(200,310,400,40,vfh[2],27,28,_Context->buffer_Message2,strlen(_Context->buffer_Message2),259);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(210,370,120,30,vfh[2],16,21,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	_Context->trigger_Abandon=visual_trigger_code(_Context->msg_Abandon[_Context->language],strlen(_Context->msg_Abandon[_Context->language]));
	visual_button(340,370,120,30,vfh[2],16,21,_Context->msg_Abandon[_Context->language],strlen(_Context->msg_Abandon[_Context->language]),0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(470,370,120,30,vfh[2],16,21,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	visual_thaw(160,160,480,280);

	return(0);
}

private int Cancel_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = " ";
			mptr[1]="By clicking on this button the NO response will be returned.   ";
			mptr[2]="The requesting operation will proceed but without confirmation of ";
			mptr[3]="the particular conditions.  ";
			mptr[4]="  ";
			return(visual_online_help(mptr,5));
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

private int Abandon_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = " ";
			mptr[1]="By clicking on this button the ABANDON response will be returned. ";
			mptr[2]=" ";
			mptr[3]="The requesting operation will not proceed.  ";
			mptr[4]="    ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Accept_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = " ";
			mptr[1]="By clicking on this button the YES response will be returned.   ";
			mptr[2]="The requesting operation will proceed with confirmation of the particular ";
			mptr[3]="conditions.  ";
			mptr[4]="   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}
private int on_Cancel_event(struct accept_yes_no_abandon_context * _Context) {
	return(26);
	return(-1);
}
private int on_Abandon_event(struct accept_yes_no_abandon_context * _Context) {
	return(27);
	return(-1);
}
private int on_Accept_event(struct accept_yes_no_abandon_context * _Context) {
	return(13);
	return(-1);
}


public	int	accept_yes_no_abandon_event(
struct accept_yes_no_abandon_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Cancel == mb ) return(2);
		if (_Context->trigger_Abandon == mb ) return(3);
		if (_Context->trigger_Accept == mb ) return(4);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= 619 )  
	&&  (my >= 164 )  
	&&  (mx <= 635 )  
	&&  (my <= 180 )) {
		return(1);	/* Auto3621 */

		}
	if ((mx >= 603 )  
	&&  (my >= 164 )  
	&&  (mx <= 619 )  
	&&  (my <= 180 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vyna.htm");
			};
		return(-1);	/* Auto3621 */

		}
	if ((mx >= 587 )  
	&&  (my >= 164 )  
	&&  (mx <= 603 )  
	&&  (my <= 180 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_yes_no_abandon_show(_Context);
		return(-1);	/* Auto3621 */

		}
		}
	if (( mx >= 210 ) 
	&&  ( my >= 370 ) 
	&&  ( mx <= 330 ) 
	&&  ( my <= 400 )) {
		return(2); /* Cancel */
		}
	if (( mx >= 340 ) 
	&&  ( my >= 370 ) 
	&&  ( mx <= 460 ) 
	&&  ( my <= 400 )) {
		return(3); /* Abandon */
		}
	if (( mx >= 470 ) 
	&&  ( my >= 370 ) 
	&&  ( mx <= 590 ) 
	&&  ( my <= 400 )) {
		return(4); /* Accept */
		}

	return(-1);
}


public	int	accept_yes_no_abandon_focus(struct accept_yes_no_abandon_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(210,370,120,30,vfh[2],16,21,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(210,370,120,30,vfh[2],16,21,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0x3 :
				/* Abandon */
				_Context->trigger_Abandon=visual_trigger_code(_Context->msg_Abandon[_Context->language],strlen(_Context->msg_Abandon[_Context->language]));
				visual_button(340,370,120,30,vfh[2],16,21,_Context->msg_Abandon[_Context->language],strlen(_Context->msg_Abandon[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Abandon=visual_trigger_code(_Context->msg_Abandon[_Context->language],strlen(_Context->msg_Abandon[_Context->language]));
	visual_button(340,370,120,30,vfh[2],16,21,_Context->msg_Abandon[_Context->language],strlen(_Context->msg_Abandon[_Context->language]),0);
				break;
			case	0x4 :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(470,370,120,30,vfh[2],16,21,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(470,370,120,30,vfh[2],16,21,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_yes_no_abandon_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=4;
			accept_yes_no_abandon_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_yes_no_abandon_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (Cancel_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Abandon_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Accept_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3621 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(210,370,120,30,vfh[2],16,21,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(210,370,120,30,vfh[2],16,21,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Abandon */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Abandon=visual_trigger_code(_Context->msg_Abandon[_Context->language],strlen(_Context->msg_Abandon[_Context->language]));
						visual_button(340,370,120,30,vfh[2],16,21,_Context->msg_Abandon[_Context->language],strlen(_Context->msg_Abandon[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Abandon=visual_trigger_code(_Context->msg_Abandon[_Context->language],strlen(_Context->msg_Abandon[_Context->language]));
	visual_button(340,370,120,30,vfh[2],16,21,_Context->msg_Abandon[_Context->language],strlen(_Context->msg_Abandon[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Abandon_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(470,370,120,30,vfh[2],16,21,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(470,370,120,30,vfh[2],16,21,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

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
				_Context->focus_item=4;
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

public	int	accept_yes_no_abandon(
	char * pMessage1,
	char * pMessage2)
{
	int	status=0;
	struct accept_yes_no_abandon_context * _Context=(struct accept_yes_no_abandon_context*) 0;
	status = accept_yes_no_abandon_create(
	&_Context,
	 pMessage1,
	 pMessage2);
	if ( status != 0) return(status);
	status = accept_yes_no_abandon_show(_Context);
		enter_modal();
	status = accept_yes_no_abandon_focus(_Context);
		leave_modal();
	status = accept_yes_no_abandon_hide(_Context);
	status = accept_yes_no_abandon_remove(
	_Context,
	 pMessage1,
	 pMessage2);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vyna_c */
