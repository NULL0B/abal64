
#ifndef _vedcmd_c
#define _vedcmd_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vedcmd.xml                                               */
/* Target         : vedcmd.c                                                 */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto3548   ""
#define fr__Auto3548   ""
#define it__Auto3548   ""
#define es__Auto3548   ""
#define de__Auto3548   ""
#define nl__Auto3548   ""
#define pt__Auto3548   ""
#define xx__Auto3548   ""
#define en_Auto3549   "Editor Command"
#define fr_Auto3549   "Commande de l'‚diteur"
#define it_Auto3549   "Editor Command"
#define es_Auto3549   "Editor Command"
#define de_Auto3549   "Editor Command"
#define nl_Auto3549   "Editor Command"
#define pt_Auto3549   "Editor Command"
#define xx_Auto3549   "Editor Command"
#define en__Auto3549   ""
#define fr__Auto3549   ""
#define it__Auto3549   ""
#define es__Auto3549   ""
#define de__Auto3549   ""
#define nl__Auto3549   ""
#define pt__Auto3549   ""
#define xx__Auto3549   ""
#define en_EditorCommand   ""
#define en_Auto3550   "ok.gif"
#define fr_Auto3550   "ok.gif"
#define it_Auto3550   "ok.gif"
#define es_Auto3550   "ok.gif"
#define de_Auto3550   "ok.gif"
#define nl_Auto3550   "ok.gif"
#define pt_Auto3550   "ok.gif"
#define xx_Auto3550   "ok.gif"
#define en_Auto3551   "cancel.gif"
#define fr_Auto3551   "cancel.gif"
#define it_Auto3551   "cancel.gif"
#define es_Auto3551   "cancel.gif"
#define de_Auto3551   "cancel.gif"
#define nl_Auto3551   "cancel.gif"
#define pt_Auto3551   "cancel.gif"
#define xx_Auto3551   "cancel.gif"

private struct accept_editor_command_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3548[8];
	char * hint_Auto3548[8];
	int	x_Auto3548;
	int	y_Auto3548;
	int	w_Auto3548;
	int	h_Auto3548;
	char * msg_Auto3549[8];
	char * hint_Auto3549[8];
	char * hint_EditorCommand[8];
	char	buffer_EditorCommand[256];
	char * msg_Auto3550[8];
	int	trigger_Auto3550;
	char * hint_Auto3550[8];
	char * msg_Auto3551[8];
	int	trigger_Auto3551;
	char * hint_Auto3551[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};
static int	vfh[16];
private int on_Auto3550_event(struct accept_editor_command_context * _Context);
private int on_Auto3551_event(struct accept_editor_command_context * _Context);

public	int	accept_editor_command_create(
	struct accept_editor_command_context ** cptr,
	char * pEditorCommand)
{

	int i;
	struct accept_editor_command_context * _Context=(struct accept_editor_command_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_editor_command_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=4;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_EditorCommand, 255, pEditorCommand);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3548[i]=" ";
	_Context->hint_Auto3548[0]=en__Auto3548;
	_Context->hint_Auto3548[1]=fr__Auto3548;
	_Context->hint_Auto3548[2]=it__Auto3548;
	_Context->hint_Auto3548[3]=es__Auto3548;
	_Context->hint_Auto3548[4]=de__Auto3548;
	_Context->hint_Auto3548[5]=nl__Auto3548;
	_Context->hint_Auto3548[6]=pt__Auto3548;
	_Context->hint_Auto3548[7]=xx__Auto3548;
	_Context->x_Auto3548=125;
	_Context->y_Auto3548=220;
	_Context->w_Auto3548=550;
	_Context->h_Auto3548=160;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3549[i]=" ";
	_Context->msg_Auto3549[0]=en_Auto3549;
	_Context->msg_Auto3549[1]=fr_Auto3549;
	_Context->msg_Auto3549[2]=it_Auto3549;
	_Context->msg_Auto3549[3]=es_Auto3549;
	_Context->msg_Auto3549[4]=de_Auto3549;
	_Context->msg_Auto3549[5]=nl_Auto3549;
	_Context->msg_Auto3549[6]=pt_Auto3549;
	_Context->msg_Auto3549[7]=xx_Auto3549;
	_Context->hint_Auto3549[0]=en__Auto3549;
	_Context->hint_Auto3549[1]=fr__Auto3549;
	_Context->hint_Auto3549[2]=it__Auto3549;
	_Context->hint_Auto3549[3]=es__Auto3549;
	_Context->hint_Auto3549[4]=de__Auto3549;
	_Context->hint_Auto3549[5]=nl__Auto3549;
	_Context->hint_Auto3549[6]=pt__Auto3549;
	_Context->hint_Auto3549[7]=xx__Auto3549;
	for (i=0; i < 8; i++)_Context->msg_Auto3550[i]=" ";
	_Context->msg_Auto3550[0]=en_Auto3550;
	_Context->msg_Auto3550[1]=fr_Auto3550;
	_Context->msg_Auto3550[2]=it_Auto3550;
	_Context->msg_Auto3550[3]=es_Auto3550;
	_Context->msg_Auto3550[4]=de_Auto3550;
	_Context->msg_Auto3550[5]=nl_Auto3550;
	_Context->msg_Auto3550[6]=pt_Auto3550;
	_Context->msg_Auto3550[7]=xx_Auto3550;
	for (i=0; i < 8; i++)_Context->msg_Auto3551[i]=" ";
	_Context->msg_Auto3551[0]=en_Auto3551;
	_Context->msg_Auto3551[1]=fr_Auto3551;
	_Context->msg_Auto3551[2]=it_Auto3551;
	_Context->msg_Auto3551[3]=es_Auto3551;
	_Context->msg_Auto3551[4]=de_Auto3551;
	_Context->msg_Auto3551[5]=nl_Auto3551;
	_Context->msg_Auto3551[6]=pt_Auto3551;
	_Context->msg_Auto3551[7]=xx_Auto3551;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3548,_Context->y_Auto3548,550+10,160+10);
	return(0);
}

public 	int	accept_editor_command_hide(struct accept_editor_command_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3548,_Context->y_Auto3548);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_editor_command_remove(
	struct accept_editor_command_context * _Context,
	char * pEditorCommand)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_EditorCommand, 255, pEditorCommand);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_editor_command_show(struct accept_editor_command_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3548,_Context->y_Auto3548);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3548,_Context->y_Auto3548,550,160,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3548,_Context->y_Auto3548,550,160,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto3548+10,_Context->y_Auto3548+30,530,20,vfh[3],27,0,_Context->msg_Auto3549[_Context->language],strlen(_Context->msg_Auto3549[_Context->language]),1026);
	visual_frame(_Context->x_Auto3548+10,_Context->y_Auto3548+50,530,40,4);
	visual_frame(_Context->x_Auto3548+20,_Context->y_Auto3548+60,512+2,16+2,5);
	visual_text(_Context->x_Auto3548+20+1,_Context->y_Auto3548+60+1,512,16,vfh[1],27,0,_Context->buffer_EditorCommand,255,0);
	_Context->trigger_Auto3550=visual_trigger_code(_Context->msg_Auto3550[_Context->language],strlen(_Context->msg_Auto3550[_Context->language]));
	visual_button(_Context->x_Auto3548+10,_Context->y_Auto3548+100,56,48,vfh[2],34,0,_Context->msg_Auto3550[_Context->language],strlen(_Context->msg_Auto3550[_Context->language]),1040);
	_Context->trigger_Auto3551=visual_trigger_code(_Context->msg_Auto3551[_Context->language],strlen(_Context->msg_Auto3551[_Context->language]));
	visual_button(_Context->x_Auto3548+480,_Context->y_Auto3548+100,56,48,vfh[2],34,0,_Context->msg_Auto3551[_Context->language],strlen(_Context->msg_Auto3551[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3548,_Context->y_Auto3548,550,160);

	return(0);
}

private int Auto3548action(struct accept_editor_command_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_editor_command_hide(_Context);

		_Context->x_Auto3548 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3548 < 0) { _Context->x_Auto3548=0; }
		_Context->y_Auto3548 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3548 < 0) { _Context->y_Auto3548=0; }
			accept_editor_command_show(_Context);

		visual_thaw(_Context->x_Auto3548,_Context->y_Auto3548,550,160);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3550_event(struct accept_editor_command_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto3551_event(struct accept_editor_command_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_editor_command_event(
struct accept_editor_command_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto3550 == mb ) return(3);
		if (_Context->trigger_Auto3551 == mb ) return(4);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3548+529) )  
	&&  (my >= (_Context->y_Auto3548+4) )  
	&&  (mx <= (_Context->x_Auto3548+546) )  
	&&  (my <= (_Context->y_Auto3548+20) )) {
		return(1);	/* Auto3548 */

		}
	if ((mx >= (_Context->x_Auto3548+513) )  
	&&  (my >= (_Context->y_Auto3548+4) )  
	&&  (mx <= (_Context->x_Auto3548+530) )  
	&&  (my <= (_Context->y_Auto3548+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vedcmd.htm");
			};
		return(-1);	/* Auto3548 */

		}
	if ((mx >= (_Context->x_Auto3548+497) )  
	&&  (my >= (_Context->y_Auto3548+4) )  
	&&  (mx <= (_Context->x_Auto3548+514) )  
	&&  (my <= (_Context->y_Auto3548+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_editor_command_show(_Context);
		return(-1);	/* Auto3548 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3548+4) )  
		&&  (my >= (_Context->y_Auto3548+4) )  
		&&  (mx <= (_Context->x_Auto3548+482) )  
		&&  (my <= (_Context->y_Auto3548+20) )) {
			return( Auto3548action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3548+20) ) 
	&&  ( my >= (_Context->y_Auto3548+60) ) 
	&&  ( mx <= (_Context->x_Auto3548+20+512) ) 
	&&  ( my <= (_Context->y_Auto3548+60+16))) {
		return(2); /* EditorCommand */
		}
	if (( mx >= (_Context->x_Auto3548+10) ) 
	&&  ( my >= (_Context->y_Auto3548+100) ) 
	&&  ( mx <= (_Context->x_Auto3548+10+56) ) 
	&&  ( my <= (_Context->y_Auto3548+100+48))) {
		return(3); /* Auto3550 */
		}
	if (( mx >= (_Context->x_Auto3548+480) ) 
	&&  ( my >= (_Context->y_Auto3548+100) ) 
	&&  ( mx <= (_Context->x_Auto3548+480+56) ) 
	&&  ( my <= (_Context->y_Auto3548+100+48))) {
		return(4); /* Auto3551 */
		}

	return(-1);
}


public	int	accept_editor_command_focus(struct accept_editor_command_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* EditorCommand */
				_Context->keycode = visual_edit(_Context->x_Auto3548+20+1,_Context->y_Auto3548+60+1,512,16,vfh[1],_Context->buffer_EditorCommand,255);
			break;
			case	0x3 :
				/* Auto3550 */
				_Context->trigger_Auto3550=visual_trigger_code(_Context->msg_Auto3550[_Context->language],strlen(_Context->msg_Auto3550[_Context->language]));
				visual_button(_Context->x_Auto3548+10,_Context->y_Auto3548+100,56,48,vfh[2],34,0,_Context->msg_Auto3550[_Context->language],strlen(_Context->msg_Auto3550[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3550=visual_trigger_code(_Context->msg_Auto3550[_Context->language],strlen(_Context->msg_Auto3550[_Context->language]));
	visual_button(_Context->x_Auto3548+10,_Context->y_Auto3548+100,56,48,vfh[2],34,0,_Context->msg_Auto3550[_Context->language],strlen(_Context->msg_Auto3550[_Context->language]),1040);
				break;
			case	0x4 :
				/* Auto3551 */
				_Context->trigger_Auto3551=visual_trigger_code(_Context->msg_Auto3551[_Context->language],strlen(_Context->msg_Auto3551[_Context->language]));
				visual_button(_Context->x_Auto3548+480,_Context->y_Auto3548+100,56,48,vfh[2],34,0,_Context->msg_Auto3551[_Context->language],strlen(_Context->msg_Auto3551[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3551=visual_trigger_code(_Context->msg_Auto3551[_Context->language],strlen(_Context->msg_Auto3551[_Context->language]));
	visual_button(_Context->x_Auto3548+480,_Context->y_Auto3548+100,56,48,vfh[2],34,0,_Context->msg_Auto3551[_Context->language],strlen(_Context->msg_Auto3551[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_editor_command_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=4;
			accept_editor_command_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_editor_command_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3548 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* EditorCommand */
					continue;
				case	0x3 :
					/* Auto3550 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3550=visual_trigger_code(_Context->msg_Auto3550[_Context->language],strlen(_Context->msg_Auto3550[_Context->language]));
						visual_button(_Context->x_Auto3548+10,_Context->y_Auto3548+100,56,48,vfh[2],34,0,_Context->msg_Auto3550[_Context->language],strlen(_Context->msg_Auto3550[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3550=visual_trigger_code(_Context->msg_Auto3550[_Context->language],strlen(_Context->msg_Auto3550[_Context->language]));
	visual_button(_Context->x_Auto3548+10,_Context->y_Auto3548+100,56,48,vfh[2],34,0,_Context->msg_Auto3550[_Context->language],strlen(_Context->msg_Auto3550[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3550_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto3551 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3551=visual_trigger_code(_Context->msg_Auto3551[_Context->language],strlen(_Context->msg_Auto3551[_Context->language]));
						visual_button(_Context->x_Auto3548+480,_Context->y_Auto3548+100,56,48,vfh[2],34,0,_Context->msg_Auto3551[_Context->language],strlen(_Context->msg_Auto3551[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3551=visual_trigger_code(_Context->msg_Auto3551[_Context->language],strlen(_Context->msg_Auto3551[_Context->language]));
	visual_button(_Context->x_Auto3548+480,_Context->y_Auto3548+100,56,48,vfh[2],34,0,_Context->msg_Auto3551[_Context->language],strlen(_Context->msg_Auto3551[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3551_event(_Context)) != -1) break;

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

public	int	accept_editor_command(
	char * pEditorCommand)
{
	int	status=0;
	struct accept_editor_command_context * _Context=(struct accept_editor_command_context*) 0;
	status = accept_editor_command_create(
	&_Context,
	 pEditorCommand);
	if ( status != 0) return(status);
	status = accept_editor_command_show(_Context);
		enter_modal();
	status = accept_editor_command_focus(_Context);
		leave_modal();
	status = accept_editor_command_hide(_Context);
	status = accept_editor_command_remove(
	_Context,
	 pEditorCommand);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vedcmd_c */
