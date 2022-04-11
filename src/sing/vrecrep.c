
#ifndef _vrecrep_c
#define _vrecrep_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vrecrep.xml                                              */
/* Target         : vrecrep.c                                                */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto3583   ""
#define fr__Auto3583   ""
#define it__Auto3583   ""
#define es__Auto3583   ""
#define de__Auto3583   ""
#define nl__Auto3583   ""
#define pt__Auto3583   ""
#define xx__Auto3583   ""
#define en_Filename   "Animation Filename"
#define fr_Filename   "Nom de fichier d'animation"
#define it_Filename   "Animation Filename"
#define es_Filename   "Animation Filename"
#define de_Filename   "Animation Filename"
#define nl_Filename   "Animation Filename"
#define pt_Filename   "Animation Filename"
#define xx_Filename   "Animation Filename"
#define en_FileName   ""
#define en_Mode   "Record Script|Replay Animation"
#define fr_Mode   "Enregistrer|Re-enacter"
#define it_Mode   "Record Script|Replay Animation"
#define es_Mode   "Record Script|Replay Animation"
#define de_Mode   "Record Script|Replay Animation"
#define nl_Mode   "Record Script|Replay Animation"
#define pt_Mode   "Record Script|Replay Animation"
#define xx_Mode   "Record Script|Replay Animation"
#define en_Auto3584   "ok.gif"
#define fr_Auto3584   "ok.gif"
#define it_Auto3584   "ok.gif"
#define es_Auto3584   "ok.gif"
#define de_Auto3584   "ok.gif"
#define nl_Auto3584   "ok.gif"
#define pt_Auto3584   "ok.gif"
#define xx_Auto3584   "ok.gif"
#define en_Auto3585   "cancel.gif"
#define fr_Auto3585   "cancel.gif"
#define it_Auto3585   "cancel.gif"
#define es_Auto3585   "cancel.gif"
#define de_Auto3585   "cancel.gif"
#define nl_Auto3585   "cancel.gif"
#define pt_Auto3585   "cancel.gif"
#define xx_Auto3585   "cancel.gif"

private struct accept_animation_parameters_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3583[8];
	char * hint_Auto3583[8];
	int	x_Auto3583;
	int	y_Auto3583;
	int	w_Auto3583;
	int	h_Auto3583;
	char * msg_Filename[8];
	char * hint_Filename[8];
	char * hint_FileName[8];
	char	buffer_FileName[256];
	char * msg_Mode[8];
	char * hint_Mode[8];
	int	value_Mode;
	char * msg_Auto3584[8];
	int	trigger_Auto3584;
	char * hint_Auto3584[8];
	char * msg_Auto3585[8];
	int	trigger_Auto3585;
	char * hint_Auto3585[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};
static int	vfh[16];
private int on_Auto3584_event(struct accept_animation_parameters_context * _Context);
private int on_Auto3585_event(struct accept_animation_parameters_context * _Context);

public	int	accept_animation_parameters_create(
	struct accept_animation_parameters_context ** cptr,
	char * pFileName,
	char * pMode)
{

	int i;
	struct accept_animation_parameters_context * _Context=(struct accept_animation_parameters_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_animation_parameters_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=5;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 255, pFileName);
		visual_transferin((void *) 0, 0, pMode);
		if (!( pMode )) _Context->value_Mode=0;
		else	_Context->value_Mode = *((int *)pMode);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3583[i]=" ";
	_Context->hint_Auto3583[0]=en__Auto3583;
	_Context->hint_Auto3583[1]=fr__Auto3583;
	_Context->hint_Auto3583[2]=it__Auto3583;
	_Context->hint_Auto3583[3]=es__Auto3583;
	_Context->hint_Auto3583[4]=de__Auto3583;
	_Context->hint_Auto3583[5]=nl__Auto3583;
	_Context->hint_Auto3583[6]=pt__Auto3583;
	_Context->hint_Auto3583[7]=xx__Auto3583;
	_Context->x_Auto3583=140;
	_Context->y_Auto3583=220;
	_Context->w_Auto3583=520;
	_Context->h_Auto3583=160;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Filename[i]=" ";
	_Context->msg_Filename[0]=en_Filename;
	_Context->msg_Filename[1]=fr_Filename;
	_Context->msg_Filename[2]=it_Filename;
	_Context->msg_Filename[3]=es_Filename;
	_Context->msg_Filename[4]=de_Filename;
	_Context->msg_Filename[5]=nl_Filename;
	_Context->msg_Filename[6]=pt_Filename;
	_Context->msg_Filename[7]=xx_Filename;
	for (i=0; i < 8; i++)_Context->msg_Mode[i]=" ";
	_Context->msg_Mode[0]=en_Mode;
	_Context->msg_Mode[1]=fr_Mode;
	_Context->msg_Mode[2]=it_Mode;
	_Context->msg_Mode[3]=es_Mode;
	_Context->msg_Mode[4]=de_Mode;
	_Context->msg_Mode[5]=nl_Mode;
	_Context->msg_Mode[6]=pt_Mode;
	_Context->msg_Mode[7]=xx_Mode;
	for (i=0; i < 8; i++)_Context->msg_Auto3584[i]=" ";
	_Context->msg_Auto3584[0]=en_Auto3584;
	_Context->msg_Auto3584[1]=fr_Auto3584;
	_Context->msg_Auto3584[2]=it_Auto3584;
	_Context->msg_Auto3584[3]=es_Auto3584;
	_Context->msg_Auto3584[4]=de_Auto3584;
	_Context->msg_Auto3584[5]=nl_Auto3584;
	_Context->msg_Auto3584[6]=pt_Auto3584;
	_Context->msg_Auto3584[7]=xx_Auto3584;
	for (i=0; i < 8; i++)_Context->msg_Auto3585[i]=" ";
	_Context->msg_Auto3585[0]=en_Auto3585;
	_Context->msg_Auto3585[1]=fr_Auto3585;
	_Context->msg_Auto3585[2]=it_Auto3585;
	_Context->msg_Auto3585[3]=es_Auto3585;
	_Context->msg_Auto3585[4]=de_Auto3585;
	_Context->msg_Auto3585[5]=nl_Auto3585;
	_Context->msg_Auto3585[6]=pt_Auto3585;
	_Context->msg_Auto3585[7]=xx_Auto3585;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3583,_Context->y_Auto3583,520+10,160+10);
	return(0);
}

public 	int	accept_animation_parameters_hide(struct accept_animation_parameters_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3583,_Context->y_Auto3583);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_animation_parameters_remove(
	struct accept_animation_parameters_context * _Context,
	char * pFileName,
	char * pMode)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 255, pFileName);
		visual_transferout((void *) 0, 0, pMode);
		if ( pMode != (char *) 0)
			*((int*)pMode) = _Context->value_Mode;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_animation_parameters_show(struct accept_animation_parameters_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3583,_Context->y_Auto3583);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3583,_Context->y_Auto3583,520,160,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3583,_Context->y_Auto3583,520,160,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto3583+20,_Context->y_Auto3583+40,476,16,vfh[2],27,0,_Context->msg_Filename[_Context->language],strlen(_Context->msg_Filename[_Context->language]),258);
	visual_frame(_Context->x_Auto3583+20,_Context->y_Auto3583+60,472+2,16+2,5);
	visual_text(_Context->x_Auto3583+20+1,_Context->y_Auto3583+60+1,472,16,vfh[1],27,0,_Context->buffer_FileName,255,0);
	visual_select(_Context->x_Auto3583+130,_Context->y_Auto3583+100,250,46,vfh[1],27,0,parse_selection(_Context->msg_Mode[_Context->language],&_Context->value_Mode),0);
	_Context->trigger_Auto3584=visual_trigger_code(_Context->msg_Auto3584[_Context->language],strlen(_Context->msg_Auto3584[_Context->language]));
	visual_button(_Context->x_Auto3583+20,_Context->y_Auto3583+100,56,48,vfh[2],34,0,_Context->msg_Auto3584[_Context->language],strlen(_Context->msg_Auto3584[_Context->language]),1040);
	_Context->trigger_Auto3585=visual_trigger_code(_Context->msg_Auto3585[_Context->language],strlen(_Context->msg_Auto3585[_Context->language]));
	visual_button(_Context->x_Auto3583+440,_Context->y_Auto3583+100,56,48,vfh[2],34,0,_Context->msg_Auto3585[_Context->language],strlen(_Context->msg_Auto3585[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3583,_Context->y_Auto3583,520,160);

	return(0);
}

private int FileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows definition of the animation script file to ";
			mptr[1]="which the animation will be recorded or from which an animation  will ";
			mptr[2]="be replayed.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Mode_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This select control allows selection of the nature of the animation ";
			mptr[1]="operation, either record events or playback.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3584_help()
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

private int Auto3585_help()
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

private int Auto3583action(struct accept_animation_parameters_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_animation_parameters_hide(_Context);

		_Context->x_Auto3583 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3583 < 0) { _Context->x_Auto3583=0; }
		_Context->y_Auto3583 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3583 < 0) { _Context->y_Auto3583=0; }
			accept_animation_parameters_show(_Context);

		visual_thaw(_Context->x_Auto3583,_Context->y_Auto3583,520,160);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3584_event(struct accept_animation_parameters_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto3585_event(struct accept_animation_parameters_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_animation_parameters_event(
struct accept_animation_parameters_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto3584 == mb ) return(4);
		if (_Context->trigger_Auto3585 == mb ) return(5);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3583+499) )  
	&&  (my >= (_Context->y_Auto3583+4) )  
	&&  (mx <= (_Context->x_Auto3583+516) )  
	&&  (my <= (_Context->y_Auto3583+20) )) {
		return(1);	/* Auto3583 */

		}
	if ((mx >= (_Context->x_Auto3583+483) )  
	&&  (my >= (_Context->y_Auto3583+4) )  
	&&  (mx <= (_Context->x_Auto3583+500) )  
	&&  (my <= (_Context->y_Auto3583+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vrecrep.htm");
			};
		return(-1);	/* Auto3583 */

		}
	if ((mx >= (_Context->x_Auto3583+467) )  
	&&  (my >= (_Context->y_Auto3583+4) )  
	&&  (mx <= (_Context->x_Auto3583+484) )  
	&&  (my <= (_Context->y_Auto3583+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_animation_parameters_show(_Context);
		return(-1);	/* Auto3583 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3583+4) )  
		&&  (my >= (_Context->y_Auto3583+4) )  
		&&  (mx <= (_Context->x_Auto3583+452) )  
		&&  (my <= (_Context->y_Auto3583+20) )) {
			return( Auto3583action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3583+20) ) 
	&&  ( my >= (_Context->y_Auto3583+60) ) 
	&&  ( mx <= (_Context->x_Auto3583+20+472) ) 
	&&  ( my <= (_Context->y_Auto3583+60+16))) {
		return(2); /* FileName */
		}
	if (( mx >= (_Context->x_Auto3583+130+0) ) 
	&&  ( my >= (_Context->y_Auto3583+100) ) 
	&&  ( mx <= (_Context->x_Auto3583+130+250) ) 
	&&  ( my <= (_Context->y_Auto3583+100+16))) {
		return(3); /* Mode */
		}
	if (( mx >= (_Context->x_Auto3583+20) ) 
	&&  ( my >= (_Context->y_Auto3583+100) ) 
	&&  ( mx <= (_Context->x_Auto3583+20+56) ) 
	&&  ( my <= (_Context->y_Auto3583+100+48))) {
		return(4); /* Auto3584 */
		}
	if (( mx >= (_Context->x_Auto3583+440) ) 
	&&  ( my >= (_Context->y_Auto3583+100) ) 
	&&  ( mx <= (_Context->x_Auto3583+440+56) ) 
	&&  ( my <= (_Context->y_Auto3583+100+48))) {
		return(5); /* Auto3585 */
		}

	return(-1);
}


public	int	accept_animation_parameters_focus(struct accept_animation_parameters_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(_Context->x_Auto3583+20+1,_Context->y_Auto3583+60+1,472,16,vfh[1],_Context->buffer_FileName,255);
			break;
			case	0x3 :
				/* Mode */
				_Context->keycode = visual_select(_Context->x_Auto3583+130,_Context->y_Auto3583+100,250,46,vfh[1],27,0,parse_selection(_Context->msg_Mode[_Context->language],&_Context->value_Mode),2);
				break;
			case	0x4 :
				/* Auto3584 */
				_Context->trigger_Auto3584=visual_trigger_code(_Context->msg_Auto3584[_Context->language],strlen(_Context->msg_Auto3584[_Context->language]));
				visual_button(_Context->x_Auto3583+20,_Context->y_Auto3583+100,56,48,vfh[2],34,0,_Context->msg_Auto3584[_Context->language],strlen(_Context->msg_Auto3584[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3584=visual_trigger_code(_Context->msg_Auto3584[_Context->language],strlen(_Context->msg_Auto3584[_Context->language]));
	visual_button(_Context->x_Auto3583+20,_Context->y_Auto3583+100,56,48,vfh[2],34,0,_Context->msg_Auto3584[_Context->language],strlen(_Context->msg_Auto3584[_Context->language]),1040);
				break;
			case	0x5 :
				/* Auto3585 */
				_Context->trigger_Auto3585=visual_trigger_code(_Context->msg_Auto3585[_Context->language],strlen(_Context->msg_Auto3585[_Context->language]));
				visual_button(_Context->x_Auto3583+440,_Context->y_Auto3583+100,56,48,vfh[2],34,0,_Context->msg_Auto3585[_Context->language],strlen(_Context->msg_Auto3585[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3585=visual_trigger_code(_Context->msg_Auto3585[_Context->language],strlen(_Context->msg_Auto3585[_Context->language]));
	visual_button(_Context->x_Auto3583+440,_Context->y_Auto3583+100,56,48,vfh[2],34,0,_Context->msg_Auto3585[_Context->language],strlen(_Context->msg_Auto3585[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_animation_parameters_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=5;
			accept_animation_parameters_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_animation_parameters_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (FileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Mode_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Auto3584_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Auto3585_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3583 */
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
					/* Mode */
					continue;
				case	0x4 :
					/* Auto3584 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3584=visual_trigger_code(_Context->msg_Auto3584[_Context->language],strlen(_Context->msg_Auto3584[_Context->language]));
						visual_button(_Context->x_Auto3583+20,_Context->y_Auto3583+100,56,48,vfh[2],34,0,_Context->msg_Auto3584[_Context->language],strlen(_Context->msg_Auto3584[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3584=visual_trigger_code(_Context->msg_Auto3584[_Context->language],strlen(_Context->msg_Auto3584[_Context->language]));
	visual_button(_Context->x_Auto3583+20,_Context->y_Auto3583+100,56,48,vfh[2],34,0,_Context->msg_Auto3584[_Context->language],strlen(_Context->msg_Auto3584[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3584_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto3585 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3585=visual_trigger_code(_Context->msg_Auto3585[_Context->language],strlen(_Context->msg_Auto3585[_Context->language]));
						visual_button(_Context->x_Auto3583+440,_Context->y_Auto3583+100,56,48,vfh[2],34,0,_Context->msg_Auto3585[_Context->language],strlen(_Context->msg_Auto3585[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3585=visual_trigger_code(_Context->msg_Auto3585[_Context->language],strlen(_Context->msg_Auto3585[_Context->language]));
	visual_button(_Context->x_Auto3583+440,_Context->y_Auto3583+100,56,48,vfh[2],34,0,_Context->msg_Auto3585[_Context->language],strlen(_Context->msg_Auto3585[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3585_event(_Context)) != -1) break;

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

public	int	accept_animation_parameters(
	char * pFileName,
	char * pMode)
{
	int	status=0;
	struct accept_animation_parameters_context * _Context=(struct accept_animation_parameters_context*) 0;
	status = accept_animation_parameters_create(
	&_Context,
	 pFileName,
	 pMode);
	if ( status != 0) return(status);
	status = accept_animation_parameters_show(_Context);
		enter_modal();
	status = accept_animation_parameters_focus(_Context);
		leave_modal();
	status = accept_animation_parameters_hide(_Context);
	status = accept_animation_parameters_remove(
	_Context,
	 pFileName,
	 pMode);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vrecrep_c */
