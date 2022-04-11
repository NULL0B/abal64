
#ifndef _vdbok_c
#define _vdbok_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vdbok.xml                                                */
/* Target         : vdbok.c                                                  */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Auto3546   "Exadb : Version 3.1d"
#define fr_Auto3546   "Exadb : Version 3.1d"
#define it_Auto3546   "Exadb : Version 3.1d"
#define es_Auto3546   "Exadb : Version 3.1d"
#define de_Auto3546   "Exadb : Version 3.1d"
#define nl_Auto3546   "Exadb : Version 3.1d"
#define pt_Auto3546   "Exadb : Version 3.1d"
#define xx_Auto3546   "Exadb : Version 3.1d"
#define en__Auto3546   ""
#define fr__Auto3546   ""
#define it__Auto3546   ""
#define es__Auto3546   ""
#define de__Auto3546   ""
#define nl__Auto3546   ""
#define pt__Auto3546   ""
#define xx__Auto3546   ""
#define en__Auto3547   ""
#define fr__Auto3547   ""
#define it__Auto3547   ""
#define es__Auto3547   ""
#define de__Auto3547   ""
#define nl__Auto3547   ""
#define pt__Auto3547   ""
#define xx__Auto3547   ""
#define en_Auto3548   "image.new"
#define fr_Auto3548   "image.new"
#define it_Auto3548   "image.new"
#define es_Auto3548   "image.new"
#define de_Auto3548   "image.new"
#define nl_Auto3548   "image.new"
#define pt_Auto3548   "image.new"
#define xx_Auto3548   "image.new"
#define en__Auto3548   ""
#define en_Auto3549   ""
#define en__Auto3549   ""
#define en_Message   ""
#define en__Message   ""
#define en_Auto3550   "Do you really want to :"
#define fr_Auto3550   "Voulez vous vraiment :"
#define it_Auto3550   "Do you really want to :"
#define es_Auto3550   "Do you really want to :"
#define de_Auto3550   "Sind si sicher"
#define nl_Auto3550   "Do you really want to :"
#define pt_Auto3550   "Do you really want to :"
#define xx_Auto3550   "Do you really want to :"
#define en__Auto3550   ""
#define fr__Auto3550   ""
#define it__Auto3550   ""
#define es__Auto3550   ""
#define de__Auto3550   ""
#define nl__Auto3550   ""
#define pt__Auto3550   ""
#define xx__Auto3550   ""
#define en__Auto3551   ""
#define en_Auto3552   ""
#define en__Auto3552   ""
#define en_Auto3553   "&Yes"
#define fr_Auto3553   "&Oui"
#define it_Auto3553   "&Si"
#define es_Auto3553   "&Si"
#define de_Auto3553   "&Ja"
#define nl_Auto3553   "&Yes"
#define pt_Auto3553   "&Yes"
#define xx_Auto3553   "&Yes"
#define en__Auto3553   ""
#define fr__Auto3553   ""
#define it__Auto3553   ""
#define es__Auto3553   ""
#define de__Auto3553   ""
#define nl__Auto3553   ""
#define pt__Auto3553   ""
#define xx__Auto3553   ""
#define en_Auto3554   "&No"
#define fr_Auto3554   "&Non"
#define it_Auto3554   "&No"
#define es_Auto3554   "&No"
#define de_Auto3554   "&Nein"
#define nl_Auto3554   "&No"
#define pt_Auto3554   "&No"
#define xx_Auto3554   "&No"
#define en__Auto3554   ""
#define fr__Auto3554   ""
#define it__Auto3554   ""
#define es__Auto3554   ""
#define de__Auto3554   ""
#define nl__Auto3554   ""
#define pt__Auto3554   ""
#define xx__Auto3554   ""

private struct visual_debug_confirm_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3546[8];
	char * hint_Auto3546[8];
	int	x_Auto3546;
	int	y_Auto3546;
	int	w_Auto3546;
	int	h_Auto3546;
	char * msg_Auto3547[8];
	char * hint_Auto3547[8];
	char * msg_Auto3548[8];
	char * hint_Auto3548[8];
	char * hint_Auto3549[8];
	char * hint_Message[8];
	char	buffer_Message[85];
	char * msg_Auto3550[8];
	char * hint_Auto3550[8];
	char * msg_Auto3551[8];
	char * hint_Auto3551[8];
	char * hint_Auto3552[8];
	char * msg_Auto3553[8];
	int	trigger_Auto3553;
	char * hint_Auto3553[8];
	char * msg_Auto3554[8];
	int	trigger_Auto3554;
	char * hint_Auto3554[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};
static int	vfh[16];
private int on_Auto3553_event(struct visual_debug_confirm_context * _Context);
private int on_Auto3554_event(struct visual_debug_confirm_context * _Context);

public	int	visual_debug_confirm_create(
	struct visual_debug_confirm_context ** cptr,
	char * pMessage)
{

	int i;
	struct visual_debug_confirm_context * _Context=(struct visual_debug_confirm_context*)0;
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
	if (!(_Context = allocate( sizeof( struct visual_debug_confirm_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->status = load_visual_style("exadb.css",9);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=3;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"K");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Message, 84, pMessage);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3546[i]=" ";
	_Context->msg_Auto3546[0]=en_Auto3546;
	_Context->msg_Auto3546[1]=fr_Auto3546;
	_Context->msg_Auto3546[2]=it_Auto3546;
	_Context->msg_Auto3546[3]=es_Auto3546;
	_Context->msg_Auto3546[4]=de_Auto3546;
	_Context->msg_Auto3546[5]=nl_Auto3546;
	_Context->msg_Auto3546[6]=pt_Auto3546;
	_Context->msg_Auto3546[7]=xx_Auto3546;
	_Context->hint_Auto3546[0]=en__Auto3546;
	_Context->hint_Auto3546[1]=fr__Auto3546;
	_Context->hint_Auto3546[2]=it__Auto3546;
	_Context->hint_Auto3546[3]=es__Auto3546;
	_Context->hint_Auto3546[4]=de__Auto3546;
	_Context->hint_Auto3546[5]=nl__Auto3546;
	_Context->hint_Auto3546[6]=pt__Auto3546;
	_Context->hint_Auto3546[7]=xx__Auto3546;
	_Context->x_Auto3546=195;
	_Context->y_Auto3546=200;
	_Context->w_Auto3546=410;
	_Context->h_Auto3546=200;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3547[i]=" ";
	_Context->hint_Auto3547[0]=en__Auto3547;
	_Context->hint_Auto3547[1]=fr__Auto3547;
	_Context->hint_Auto3547[2]=it__Auto3547;
	_Context->hint_Auto3547[3]=es__Auto3547;
	_Context->hint_Auto3547[4]=de__Auto3547;
	_Context->hint_Auto3547[5]=nl__Auto3547;
	_Context->hint_Auto3547[6]=pt__Auto3547;
	_Context->hint_Auto3547[7]=xx__Auto3547;
	for (i=0; i < 8; i++)_Context->msg_Auto3548[i]=" ";
	_Context->msg_Auto3548[0]=en_Auto3548;
	_Context->msg_Auto3548[1]=fr_Auto3548;
	_Context->msg_Auto3548[2]=it_Auto3548;
	_Context->msg_Auto3548[3]=es_Auto3548;
	_Context->msg_Auto3548[4]=de_Auto3548;
	_Context->msg_Auto3548[5]=nl_Auto3548;
	_Context->msg_Auto3548[6]=pt_Auto3548;
	_Context->msg_Auto3548[7]=xx_Auto3548;
	_Context->hint_Auto3548[0]=en__Auto3548;
	_Context->hint_Auto3549[0]=en__Auto3549;
	_Context->hint_Message[0]=en__Message;
	for (i=0; i < 8; i++)_Context->msg_Auto3550[i]=" ";
	_Context->msg_Auto3550[0]=en_Auto3550;
	_Context->msg_Auto3550[1]=fr_Auto3550;
	_Context->msg_Auto3550[2]=it_Auto3550;
	_Context->msg_Auto3550[3]=es_Auto3550;
	_Context->msg_Auto3550[4]=de_Auto3550;
	_Context->msg_Auto3550[5]=nl_Auto3550;
	_Context->msg_Auto3550[6]=pt_Auto3550;
	_Context->msg_Auto3550[7]=xx_Auto3550;
	_Context->hint_Auto3550[0]=en__Auto3550;
	_Context->hint_Auto3550[1]=fr__Auto3550;
	_Context->hint_Auto3550[2]=it__Auto3550;
	_Context->hint_Auto3550[3]=es__Auto3550;
	_Context->hint_Auto3550[4]=de__Auto3550;
	_Context->hint_Auto3550[5]=nl__Auto3550;
	_Context->hint_Auto3550[6]=pt__Auto3550;
	_Context->hint_Auto3550[7]=xx__Auto3550;
	for (i=0; i < 8; i++)_Context->msg_Auto3551[i]=" ";
	_Context->hint_Auto3551[0]=en__Auto3551;
	_Context->hint_Auto3552[0]=en__Auto3552;
	for (i=0; i < 8; i++)_Context->msg_Auto3553[i]=" ";
	_Context->msg_Auto3553[0]=en_Auto3553;
	_Context->msg_Auto3553[1]=fr_Auto3553;
	_Context->msg_Auto3553[2]=it_Auto3553;
	_Context->msg_Auto3553[3]=es_Auto3553;
	_Context->msg_Auto3553[4]=de_Auto3553;
	_Context->msg_Auto3553[5]=nl_Auto3553;
	_Context->msg_Auto3553[6]=pt_Auto3553;
	_Context->msg_Auto3553[7]=xx_Auto3553;
	_Context->hint_Auto3553[0]=en__Auto3553;
	_Context->hint_Auto3553[1]=fr__Auto3553;
	_Context->hint_Auto3553[2]=it__Auto3553;
	_Context->hint_Auto3553[3]=es__Auto3553;
	_Context->hint_Auto3553[4]=de__Auto3553;
	_Context->hint_Auto3553[5]=nl__Auto3553;
	_Context->hint_Auto3553[6]=pt__Auto3553;
	_Context->hint_Auto3553[7]=xx__Auto3553;
	for (i=0; i < 8; i++)_Context->msg_Auto3554[i]=" ";
	_Context->msg_Auto3554[0]=en_Auto3554;
	_Context->msg_Auto3554[1]=fr_Auto3554;
	_Context->msg_Auto3554[2]=it_Auto3554;
	_Context->msg_Auto3554[3]=es_Auto3554;
	_Context->msg_Auto3554[4]=de_Auto3554;
	_Context->msg_Auto3554[5]=nl_Auto3554;
	_Context->msg_Auto3554[6]=pt_Auto3554;
	_Context->msg_Auto3554[7]=xx_Auto3554;
	_Context->hint_Auto3554[0]=en__Auto3554;
	_Context->hint_Auto3554[1]=fr__Auto3554;
	_Context->hint_Auto3554[2]=it__Auto3554;
	_Context->hint_Auto3554[3]=es__Auto3554;
	_Context->hint_Auto3554[4]=de__Auto3554;
	_Context->hint_Auto3554[5]=nl__Auto3554;
	_Context->hint_Auto3554[6]=pt__Auto3554;
	_Context->hint_Auto3554[7]=xx__Auto3554;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3546,_Context->y_Auto3546,410+10,200+10);
	return(0);
}

public 	int	visual_debug_confirm_hide(struct visual_debug_confirm_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3546,_Context->y_Auto3546);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	visual_debug_confirm_remove(
	struct visual_debug_confirm_context * _Context,
	char * pMessage)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"K");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Message, 84, pMessage);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	visual_debug_confirm_show(struct visual_debug_confirm_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3546,_Context->y_Auto3546);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto3546,_Context->y_Auto3546,410,200,vfh[2],_Context->msg_Auto3546[_Context->language],strlen(_Context->msg_Auto3546[_Context->language]),0x407);
	visual_image(_Context->x_Auto3546+3,_Context->y_Auto3546+21,402,176,DebugImageName(0),516);
	if (((_Context->status = visual_styled_element(_Context->x_Auto3546,_Context->y_Auto3546,410,200,"test",_Context->msg_Auto3548[_Context->language],strlen(_Context->msg_Auto3548[_Context->language]))) != 0)
) {
		visual_image(_Context->x_Auto3546,_Context->y_Auto3546,410,200,_Context->msg_Auto3548[_Context->language],0);
		}
	visual_filzone(_Context->x_Auto3546+30,_Context->y_Auto3546+120,344,52,83,524);
	visual_text(_Context->x_Auto3546+30,_Context->y_Auto3546+40,345,40,vfh[3],70,126,_Context->msg_Auto3550[_Context->language],strlen(_Context->msg_Auto3550[_Context->language]),259);
	visual_text(_Context->x_Auto3546+30,_Context->y_Auto3546+80,345,40,vfh[3],70,126,_Context->buffer_Message,strlen(_Context->buffer_Message),259);
	visual_filzone(_Context->x_Auto3546+30,_Context->y_Auto3546+40,344,130,35,513);
	_Context->trigger_Auto3553=visual_trigger_code(_Context->msg_Auto3553[_Context->language],strlen(_Context->msg_Auto3553[_Context->language]));
	visual_button(_Context->x_Auto3546+50,_Context->y_Auto3546+130,140,32,vfh[2],27,28,_Context->msg_Auto3553[_Context->language],strlen(_Context->msg_Auto3553[_Context->language]),0);
	_Context->trigger_Auto3554=visual_trigger_code(_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]));
	visual_button(_Context->x_Auto3546+210,_Context->y_Auto3546+130,140,32,vfh[2],27,28,_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]),0);
	visual_thaw(_Context->x_Auto3546,_Context->y_Auto3546,410,200);

	return(0);
}

private int Auto3546action(struct visual_debug_confirm_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			visual_debug_confirm_hide(_Context);

		_Context->x_Auto3546 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3546 < 0) { _Context->x_Auto3546=0; }
		_Context->y_Auto3546 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3546 < 0) { _Context->y_Auto3546=0; }
			visual_debug_confirm_show(_Context);

		visual_thaw(_Context->x_Auto3546,_Context->y_Auto3546,410,200);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3553_event(struct visual_debug_confirm_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto3554_event(struct visual_debug_confirm_context * _Context) {
	return(27);
	return(-1);
}


public	int	visual_debug_confirm_event(
struct visual_debug_confirm_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto3553 == mb ) return(2);
		if (_Context->trigger_Auto3554 == mb ) return(3);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3546+389) )  
	&&  (my >= (_Context->y_Auto3546+4) )  
	&&  (mx <= (_Context->x_Auto3546+406) )  
	&&  (my <= (_Context->y_Auto3546+20) )) {
		return(1);	/* Auto3546 */

		}
	if ((mx >= (_Context->x_Auto3546+373) )  
	&&  (my >= (_Context->y_Auto3546+4) )  
	&&  (mx <= (_Context->x_Auto3546+390) )  
	&&  (my <= (_Context->y_Auto3546+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vdbok.htm");
			};
		return(-1);	/* Auto3546 */

		}
	if ((mx >= (_Context->x_Auto3546+357) )  
	&&  (my >= (_Context->y_Auto3546+4) )  
	&&  (mx <= (_Context->x_Auto3546+374) )  
	&&  (my <= (_Context->y_Auto3546+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		visual_debug_confirm_show(_Context);
		return(-1);	/* Auto3546 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3546+4) )  
		&&  (my >= (_Context->y_Auto3546+4) )  
		&&  (mx <= (_Context->x_Auto3546+342) )  
		&&  (my <= (_Context->y_Auto3546+20) )) {
			return( Auto3546action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3546+50) ) 
	&&  ( my >= (_Context->y_Auto3546+130) ) 
	&&  ( mx <= (_Context->x_Auto3546+50+140) ) 
	&&  ( my <= (_Context->y_Auto3546+130+32))) {
		return(2); /* Auto3553 */
		}
	if (( mx >= (_Context->x_Auto3546+210) ) 
	&&  ( my >= (_Context->y_Auto3546+130) ) 
	&&  ( mx <= (_Context->x_Auto3546+210+140) ) 
	&&  ( my <= (_Context->y_Auto3546+130+32))) {
		return(3); /* Auto3554 */
		}

	return(-1);
}


public	int	visual_debug_confirm_focus(struct visual_debug_confirm_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto3553 */
				_Context->trigger_Auto3553=visual_trigger_code(_Context->msg_Auto3553[_Context->language],strlen(_Context->msg_Auto3553[_Context->language]));
				visual_button(_Context->x_Auto3546+50,_Context->y_Auto3546+130,140,32,vfh[2],27,28,_Context->msg_Auto3553[_Context->language],strlen(_Context->msg_Auto3553[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3553=visual_trigger_code(_Context->msg_Auto3553[_Context->language],strlen(_Context->msg_Auto3553[_Context->language]));
	visual_button(_Context->x_Auto3546+50,_Context->y_Auto3546+130,140,32,vfh[2],27,28,_Context->msg_Auto3553[_Context->language],strlen(_Context->msg_Auto3553[_Context->language]),0);
				break;
			case	0x3 :
				/* Auto3554 */
				_Context->trigger_Auto3554=visual_trigger_code(_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]));
				visual_button(_Context->x_Auto3546+210,_Context->y_Auto3546+130,140,32,vfh[2],27,28,_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3554=visual_trigger_code(_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]));
	visual_button(_Context->x_Auto3546+210,_Context->y_Auto3546+130,140,32,vfh[2],27,28,_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			visual_debug_confirm_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=3;
			visual_debug_confirm_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=visual_debug_confirm_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3546 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Auto3553 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3553=visual_trigger_code(_Context->msg_Auto3553[_Context->language],strlen(_Context->msg_Auto3553[_Context->language]));
						visual_button(_Context->x_Auto3546+50,_Context->y_Auto3546+130,140,32,vfh[2],27,28,_Context->msg_Auto3553[_Context->language],strlen(_Context->msg_Auto3553[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3553=visual_trigger_code(_Context->msg_Auto3553[_Context->language],strlen(_Context->msg_Auto3553[_Context->language]));
	visual_button(_Context->x_Auto3546+50,_Context->y_Auto3546+130,140,32,vfh[2],27,28,_Context->msg_Auto3553[_Context->language],strlen(_Context->msg_Auto3553[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3553_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto3554 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3554=visual_trigger_code(_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]));
						visual_button(_Context->x_Auto3546+210,_Context->y_Auto3546+130,140,32,vfh[2],27,28,_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3554=visual_trigger_code(_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]));
	visual_button(_Context->x_Auto3546+210,_Context->y_Auto3546+130,140,32,vfh[2],27,28,_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3554_event(_Context)) != -1) break;

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

public	int	visual_debug_confirm(
	char * pMessage)
{
	int	status=0;
	struct visual_debug_confirm_context * _Context=(struct visual_debug_confirm_context*) 0;
	status = visual_debug_confirm_create(
	&_Context,
	 pMessage);
	if ( status != 0) return(status);
	status = visual_debug_confirm_show(_Context);
		enter_modal();
	status = visual_debug_confirm_focus(_Context);
		leave_modal();
	status = visual_debug_confirm_hide(_Context);
	status = visual_debug_confirm_remove(
	_Context,
	 pMessage);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vdbok_c */
