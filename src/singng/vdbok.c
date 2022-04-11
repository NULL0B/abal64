
#ifndef _vdbok_c
#define _vdbok_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vdbok.xml                                                */
/* Target         : vdbok.c                                                  */
/* Identification : 0.0-1177511934-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Auto2717   "Exadb : Version 3.1d"
#define fr_Auto2717   "Exadb : Version 3.1d"
#define it_Auto2717   "Exadb : Version 3.1d"
#define es_Auto2717   "Exadb : Version 3.1d"
#define de_Auto2717   "Exadb : Version 3.1d"
#define nl_Auto2717   "Exadb : Version 3.1d"
#define pt_Auto2717   "Exadb : Version 3.1d"
#define xx_Auto2717   "Exadb : Version 3.1d"
#define en__Auto2717   ""
#define fr__Auto2717   ""
#define it__Auto2717   ""
#define es__Auto2717   ""
#define de__Auto2717   ""
#define nl__Auto2717   ""
#define pt__Auto2717   ""
#define xx__Auto2717   ""
#define en__Auto2718   ""
#define fr__Auto2718   ""
#define it__Auto2718   ""
#define es__Auto2718   ""
#define de__Auto2718   ""
#define nl__Auto2718   ""
#define pt__Auto2718   ""
#define xx__Auto2718   ""
#define en_Auto2719   "image.new"
#define fr_Auto2719   "image.new"
#define it_Auto2719   "image.new"
#define es_Auto2719   "image.new"
#define de_Auto2719   "image.new"
#define nl_Auto2719   "image.new"
#define pt_Auto2719   "image.new"
#define xx_Auto2719   "image.new"
#define en__Auto2719   ""
#define en_Auto2720   ""
#define en__Auto2720   ""
#define en_Message   ""
#define en__Message   ""
#define en_Auto2721   "Do you really want to :"
#define fr_Auto2721   "Voulez vous vraiment :"
#define it_Auto2721   "Do you really want to :"
#define es_Auto2721   "Do you really want to :"
#define de_Auto2721   "Sind si sicher"
#define nl_Auto2721   "Do you really want to :"
#define pt_Auto2721   "Do you really want to :"
#define xx_Auto2721   "Do you really want to :"
#define en__Auto2721   ""
#define fr__Auto2721   ""
#define it__Auto2721   ""
#define es__Auto2721   ""
#define de__Auto2721   ""
#define nl__Auto2721   ""
#define pt__Auto2721   ""
#define xx__Auto2721   ""
#define en__Auto2722   ""
#define en_Auto2723   ""
#define en__Auto2723   ""
#define en_Auto2724   "&Yes"
#define fr_Auto2724   "&Oui"
#define it_Auto2724   "&Si"
#define es_Auto2724   "&Si"
#define de_Auto2724   "&Ja"
#define nl_Auto2724   "&Yes"
#define pt_Auto2724   "&Yes"
#define xx_Auto2724   "&Yes"
#define en__Auto2724   ""
#define fr__Auto2724   ""
#define it__Auto2724   ""
#define es__Auto2724   ""
#define de__Auto2724   ""
#define nl__Auto2724   ""
#define pt__Auto2724   ""
#define xx__Auto2724   ""
#define en_Auto2725   "&No"
#define fr_Auto2725   "&Non"
#define it_Auto2725   "&No"
#define es_Auto2725   "&No"
#define de_Auto2725   "&Nein"
#define nl_Auto2725   "&No"
#define pt_Auto2725   "&No"
#define xx_Auto2725   "&No"
#define en__Auto2725   ""
#define fr__Auto2725   ""
#define it__Auto2725   ""
#define es__Auto2725   ""
#define de__Auto2725   ""
#define nl__Auto2725   ""
#define pt__Auto2725   ""
#define xx__Auto2725   ""

private struct visual_debug_confirm_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto2717[8];
	char * hint_Auto2717[8];
	int	x_Auto2717;
	int	y_Auto2717;
	int	w_Auto2717;
	int	h_Auto2717;
	char * msg_Auto2718[8];
	char * hint_Auto2718[8];
	char * msg_Auto2719[8];
	char * hint_Auto2719[8];
	char * hint_Auto2720[8];
	char * hint_Message[8];
	char	buffer_Message[85];
	char * msg_Auto2721[8];
	char * hint_Auto2721[8];
	char * msg_Auto2722[8];
	char * hint_Auto2722[8];
	char * hint_Auto2723[8];
	char * msg_Auto2724[8];
	int	trigger_Auto2724;
	char * hint_Auto2724[8];
	char * msg_Auto2725[8];
	int	trigger_Auto2725;
	char * hint_Auto2725[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};
static int	vfh[16];

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
	vfh[10] = visual_font("font10.fmf",10);
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
	for (i=0; i < 8; i++)_Context->msg_Auto2717[i]=" ";
	_Context->msg_Auto2717[0]=en_Auto2717;
	_Context->msg_Auto2717[1]=fr_Auto2717;
	_Context->msg_Auto2717[2]=it_Auto2717;
	_Context->msg_Auto2717[3]=es_Auto2717;
	_Context->msg_Auto2717[4]=de_Auto2717;
	_Context->msg_Auto2717[5]=nl_Auto2717;
	_Context->msg_Auto2717[6]=pt_Auto2717;
	_Context->msg_Auto2717[7]=xx_Auto2717;
	_Context->hint_Auto2717[0]=en__Auto2717;
	_Context->hint_Auto2717[1]=fr__Auto2717;
	_Context->hint_Auto2717[2]=it__Auto2717;
	_Context->hint_Auto2717[3]=es__Auto2717;
	_Context->hint_Auto2717[4]=de__Auto2717;
	_Context->hint_Auto2717[5]=nl__Auto2717;
	_Context->hint_Auto2717[6]=pt__Auto2717;
	_Context->hint_Auto2717[7]=xx__Auto2717;
	_Context->x_Auto2717=195;
	_Context->y_Auto2717=200;
	_Context->w_Auto2717=410;
	_Context->h_Auto2717=200;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2718[i]=" ";
	_Context->hint_Auto2718[0]=en__Auto2718;
	_Context->hint_Auto2718[1]=fr__Auto2718;
	_Context->hint_Auto2718[2]=it__Auto2718;
	_Context->hint_Auto2718[3]=es__Auto2718;
	_Context->hint_Auto2718[4]=de__Auto2718;
	_Context->hint_Auto2718[5]=nl__Auto2718;
	_Context->hint_Auto2718[6]=pt__Auto2718;
	_Context->hint_Auto2718[7]=xx__Auto2718;
	for (i=0; i < 8; i++)_Context->msg_Auto2719[i]=" ";
	_Context->msg_Auto2719[0]=en_Auto2719;
	_Context->msg_Auto2719[1]=fr_Auto2719;
	_Context->msg_Auto2719[2]=it_Auto2719;
	_Context->msg_Auto2719[3]=es_Auto2719;
	_Context->msg_Auto2719[4]=de_Auto2719;
	_Context->msg_Auto2719[5]=nl_Auto2719;
	_Context->msg_Auto2719[6]=pt_Auto2719;
	_Context->msg_Auto2719[7]=xx_Auto2719;
	_Context->hint_Auto2719[0]=en__Auto2719;
	_Context->hint_Auto2720[0]=en__Auto2720;
	_Context->hint_Message[0]=en__Message;
	for (i=0; i < 8; i++)_Context->msg_Auto2721[i]=" ";
	_Context->msg_Auto2721[0]=en_Auto2721;
	_Context->msg_Auto2721[1]=fr_Auto2721;
	_Context->msg_Auto2721[2]=it_Auto2721;
	_Context->msg_Auto2721[3]=es_Auto2721;
	_Context->msg_Auto2721[4]=de_Auto2721;
	_Context->msg_Auto2721[5]=nl_Auto2721;
	_Context->msg_Auto2721[6]=pt_Auto2721;
	_Context->msg_Auto2721[7]=xx_Auto2721;
	_Context->hint_Auto2721[0]=en__Auto2721;
	_Context->hint_Auto2721[1]=fr__Auto2721;
	_Context->hint_Auto2721[2]=it__Auto2721;
	_Context->hint_Auto2721[3]=es__Auto2721;
	_Context->hint_Auto2721[4]=de__Auto2721;
	_Context->hint_Auto2721[5]=nl__Auto2721;
	_Context->hint_Auto2721[6]=pt__Auto2721;
	_Context->hint_Auto2721[7]=xx__Auto2721;
	for (i=0; i < 8; i++)_Context->msg_Auto2722[i]=" ";
	_Context->hint_Auto2722[0]=en__Auto2722;
	_Context->hint_Auto2723[0]=en__Auto2723;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2725[i]=" ";
	_Context->msg_Auto2725[0]=en_Auto2725;
	_Context->msg_Auto2725[1]=fr_Auto2725;
	_Context->msg_Auto2725[2]=it_Auto2725;
	_Context->msg_Auto2725[3]=es_Auto2725;
	_Context->msg_Auto2725[4]=de_Auto2725;
	_Context->msg_Auto2725[5]=nl_Auto2725;
	_Context->msg_Auto2725[6]=pt_Auto2725;
	_Context->msg_Auto2725[7]=xx_Auto2725;
	_Context->hint_Auto2725[0]=en__Auto2725;
	_Context->hint_Auto2725[1]=fr__Auto2725;
	_Context->hint_Auto2725[2]=it__Auto2725;
	_Context->hint_Auto2725[3]=es__Auto2725;
	_Context->hint_Auto2725[4]=de__Auto2725;
	_Context->hint_Auto2725[5]=nl__Auto2725;
	_Context->hint_Auto2725[6]=pt__Auto2725;
	_Context->hint_Auto2725[7]=xx__Auto2725;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto2717,_Context->y_Auto2717,410+10,200+10);
	return(0);
}

public 	int	visual_debug_confirm_hide(struct visual_debug_confirm_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto2717,_Context->y_Auto2717);
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
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto2717,_Context->y_Auto2717);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto2717,_Context->y_Auto2717,410,200,vfh[2],_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]),0x407);
	visual_image(_Context->x_Auto2717+3,_Context->y_Auto2717+21,402,176,DebugImageName(0),516);
	if (((_Context->status = visual_styled_element(_Context->x_Auto2717,_Context->y_Auto2717,410,200,"test",_Context->msg_Auto2719[_Context->language],strlen(_Context->msg_Auto2719[_Context->language]))) != 0)
) {
		visual_image(_Context->x_Auto2717,_Context->y_Auto2717,410,200,_Context->msg_Auto2719[_Context->language],0);
		}
	visual_filzone(_Context->x_Auto2717+30,_Context->y_Auto2717+120,344,52,83,524);
	visual_text(_Context->x_Auto2717+30,_Context->y_Auto2717+40,345,40,vfh[3],70,126,_Context->msg_Auto2721[_Context->language],strlen(_Context->msg_Auto2721[_Context->language]),259);
	visual_text(_Context->x_Auto2717+30,_Context->y_Auto2717+80,345,40,vfh[3],70,126,_Context->buffer_Message,strlen(_Context->buffer_Message),259);
	visual_filzone(_Context->x_Auto2717+30,_Context->y_Auto2717+40,344,130,35,513);
	_Context->trigger_Auto2724=visual_trigger_code(_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]));
	visual_button(_Context->x_Auto2717+50,_Context->y_Auto2717+130,140,32,vfh[2],27,28,_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]),0);
	_Context->trigger_Auto2725=visual_trigger_code(_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]));
	visual_button(_Context->x_Auto2717+210,_Context->y_Auto2717+130,140,32,vfh[2],27,28,_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]),0);
	visual_thaw(_Context->x_Auto2717,_Context->y_Auto2717,410,200);

	return(0);
}

private int Auto2717action(struct visual_debug_confirm_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			visual_debug_confirm_hide(_Context);

		_Context->x_Auto2717 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto2717 < 0) { _Context->x_Auto2717=0; }
		_Context->y_Auto2717 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto2717 < 0) { _Context->y_Auto2717=0; }
			visual_debug_confirm_show(_Context);

		visual_thaw(_Context->x_Auto2717,_Context->y_Auto2717,410,200);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto2724_event(struct visual_debug_confirm_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto2725_event(struct visual_debug_confirm_context * _Context) {
	return(27);
	return(-1);
}


public	int	visual_debug_confirm_event(
struct visual_debug_confirm_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto2724 == mb ) return(2);
		if (_Context->trigger_Auto2725 == mb ) return(3);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto2717+389) )  
	&&  (my >= (_Context->y_Auto2717+4) )  
	&&  (mx <= (_Context->x_Auto2717+406) )  
	&&  (my <= (_Context->y_Auto2717+20) )) {
		return(1);	/* Auto2717 */

		}
	if ((mx >= (_Context->x_Auto2717+373) )  
	&&  (my >= (_Context->y_Auto2717+4) )  
	&&  (mx <= (_Context->x_Auto2717+390) )  
	&&  (my <= (_Context->y_Auto2717+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vdbok.htm");
			};
		return(-1);	/* Auto2717 */

		}
	if ((mx >= (_Context->x_Auto2717+357) )  
	&&  (my >= (_Context->y_Auto2717+4) )  
	&&  (mx <= (_Context->x_Auto2717+374) )  
	&&  (my <= (_Context->y_Auto2717+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		visual_debug_confirm_show(_Context);
		return(-1);	/* Auto2717 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto2717+4) )  
		&&  (my >= (_Context->y_Auto2717+4) )  
		&&  (mx <= (_Context->x_Auto2717+342) )  
		&&  (my <= (_Context->y_Auto2717+20) )) {
			return( Auto2717action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto2717+50) ) 
	&&  ( my >= (_Context->y_Auto2717+130) ) 
	&&  ( mx <= (_Context->x_Auto2717+50+140) ) 
	&&  ( my <= (_Context->y_Auto2717+130+32))) {
		return(2); /* Auto2724 */
		}
	if (( mx >= (_Context->x_Auto2717+210) ) 
	&&  ( my >= (_Context->y_Auto2717+130) ) 
	&&  ( mx <= (_Context->x_Auto2717+210+140) ) 
	&&  ( my <= (_Context->y_Auto2717+130+32))) {
		return(3); /* Auto2725 */
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
				/* Auto2724 */
				_Context->trigger_Auto2724=visual_trigger_code(_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]));
				visual_button(_Context->x_Auto2717+50,_Context->y_Auto2717+130,140,32,vfh[2],27,28,_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2724=visual_trigger_code(_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]));
	visual_button(_Context->x_Auto2717+50,_Context->y_Auto2717+130,140,32,vfh[2],27,28,_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]),0);
				break;
			case	0x3 :
				/* Auto2725 */
				_Context->trigger_Auto2725=visual_trigger_code(_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]));
				visual_button(_Context->x_Auto2717+210,_Context->y_Auto2717+130,140,32,vfh[2],27,28,_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2725=visual_trigger_code(_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]));
	visual_button(_Context->x_Auto2717+210,_Context->y_Auto2717+130,140,32,vfh[2],27,28,_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]),0);
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
					/* Auto2717 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Auto2724 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2724=visual_trigger_code(_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]));
						visual_button(_Context->x_Auto2717+50,_Context->y_Auto2717+130,140,32,vfh[2],27,28,_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2724=visual_trigger_code(_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]));
	visual_button(_Context->x_Auto2717+50,_Context->y_Auto2717+130,140,32,vfh[2],27,28,_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2724_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto2725 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2725=visual_trigger_code(_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]));
						visual_button(_Context->x_Auto2717+210,_Context->y_Auto2717+130,140,32,vfh[2],27,28,_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2725=visual_trigger_code(_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]));
	visual_button(_Context->x_Auto2717+210,_Context->y_Auto2717+130,140,32,vfh[2],27,28,_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2725_event(_Context)) != -1) break;

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
