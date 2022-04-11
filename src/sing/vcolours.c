
#ifndef _vcolours_c
#define _vcolours_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vcolour.xml                                              */
/* Target         : vcolours.c                                               */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en__Auto3539   ""
#define fr__Auto3539   ""
#define it__Auto3539   ""
#define es__Auto3539   ""
#define de__Auto3539   ""
#define nl__Auto3539   ""
#define pt__Auto3539   ""
#define xx__Auto3539   ""
#define en_Auto3540   ""
#define en_Auto3541   "Widget Colour Selection"
#define fr_Auto3541   "S‚lection de la couleur d'un widget"
#define it_Auto3541   "Widget Colour Selection"
#define es_Auto3541   "Widget Colour Selection"
#define de_Auto3541   "Widget Colour Selection"
#define nl_Auto3541   "Widget Colour Selection"
#define pt_Auto3541   "Widget Colour Selection"
#define xx_Auto3541   "Widget Colour Selection"
#define en__Auto3541   ""
#define fr__Auto3541   ""
#define it__Auto3541   ""
#define es__Auto3541   ""
#define de__Auto3541   ""
#define nl__Auto3541   ""
#define pt__Auto3541   ""
#define xx__Auto3541   ""
#define en_Auto3542   "ok.gif"
#define fr_Auto3542   "ok.gif"
#define it_Auto3542   "ok.gif"
#define es_Auto3542   "ok.gif"
#define de_Auto3542   "ok.gif"
#define nl_Auto3542   "ok.gif"
#define pt_Auto3542   "ok.gif"
#define xx_Auto3542   "ok.gif"
#define en_Auto3543   "Foreground"
#define fr_Auto3543   "CaractŠres"
#define it_Auto3543   "Foreground"
#define es_Auto3543   "Foreground"
#define de_Auto3543   "Foreground"
#define nl_Auto3543   "Foreground"
#define pt_Auto3543   "Foreground"
#define xx_Auto3543   "Foreground"
#define en__Auto3543   ""
#define fr__Auto3543   ""
#define it__Auto3543   ""
#define es__Auto3543   ""
#define de__Auto3543   ""
#define nl__Auto3543   ""
#define pt__Auto3543   ""
#define xx__Auto3543   ""
#define en_fgcolour   ""
#define en_bgcolour   ""
#define en_Auto3544   "Background"
#define fr_Auto3544   "Fond"
#define it_Auto3544   "Background"
#define es_Auto3544   "Background"
#define de_Auto3544   "Background"
#define nl_Auto3544   "Background"
#define pt_Auto3544   "Background"
#define xx_Auto3544   "Background"
#define en__Auto3544   ""
#define fr__Auto3544   ""
#define it__Auto3544   ""
#define es__Auto3544   ""
#define de__Auto3544   ""
#define nl__Auto3544   ""
#define pt__Auto3544   ""
#define xx__Auto3544   ""
#define en_Auto3545   "cancel.gif"
#define fr_Auto3545   "cancel.gif"
#define it_Auto3545   "cancel.gif"
#define es_Auto3545   "cancel.gif"
#define de_Auto3545   "cancel.gif"
#define nl_Auto3545   "cancel.gif"
#define pt_Auto3545   "cancel.gif"
#define xx_Auto3545   "cancel.gif"
#define en_Auto3546   ""
#define en_Auto3547   ""
#define en_target   ""

private struct accept_visual_colour_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3539[8];
	char * hint_Auto3539[8];
	int	x_Auto3539;
	int	y_Auto3539;
	int	w_Auto3539;
	int	h_Auto3539;
	char * hint_Auto3540[8];
	char * msg_Auto3541[8];
	char * hint_Auto3541[8];
	char * msg_Auto3542[8];
	int	trigger_Auto3542;
	char * hint_Auto3542[8];
	char * msg_Auto3543[8];
	char * hint_Auto3543[8];
	char * hint_fgcolour[8];
	char	buffer_fgcolour[5];
	char * hint_bgcolour[8];
	char	buffer_bgcolour[5];
	char * msg_Auto3544[8];
	char * hint_Auto3544[8];
	char * msg_Auto3545[8];
	int	trigger_Auto3545;
	char * hint_Auto3545[8];
	char * hint_Auto3546[8];
	char * hint_Auto3547[8];
	char * hint_target[8];
	char	buffer_target[1251];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};
static int	vfh[16];
private int on_fgcolour_show(struct accept_visual_colour_context * _Context);
private int on_bgcolour_show(struct accept_visual_colour_context * _Context);
private int on_target_show(struct accept_visual_colour_context * _Context);
private int on_target_getfocus(struct accept_visual_colour_context * _Context);
private int on_Auto3542_event(struct accept_visual_colour_context * _Context);
private int on_Auto3545_event(struct accept_visual_colour_context * _Context);
private int on_target_event(struct accept_visual_colour_context * _Context);

public	int	accept_visual_colour_create(
	struct accept_visual_colour_context ** cptr,
	char * pfgcolour,
	char * pbgcolour)
{

	int i;
	struct accept_visual_colour_context * _Context=(struct accept_visual_colour_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_visual_colour_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=6;
		for (i=0; i < 1250; i++)  *(_Context->buffer_target+i)=' ';
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_fgcolour, 4, pfgcolour);
		visual_transferin(_Context->buffer_bgcolour, 4, pbgcolour);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3539[i]=" ";
	_Context->hint_Auto3539[0]=en__Auto3539;
	_Context->hint_Auto3539[1]=fr__Auto3539;
	_Context->hint_Auto3539[2]=it__Auto3539;
	_Context->hint_Auto3539[3]=es__Auto3539;
	_Context->hint_Auto3539[4]=de__Auto3539;
	_Context->hint_Auto3539[5]=nl__Auto3539;
	_Context->hint_Auto3539[6]=pt__Auto3539;
	_Context->hint_Auto3539[7]=xx__Auto3539;
	_Context->x_Auto3539=165;
	_Context->y_Auto3539=20;
	_Context->w_Auto3539=470;
	_Context->h_Auto3539=560;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3541[i]=" ";
	_Context->msg_Auto3541[0]=en_Auto3541;
	_Context->msg_Auto3541[1]=fr_Auto3541;
	_Context->msg_Auto3541[2]=it_Auto3541;
	_Context->msg_Auto3541[3]=es_Auto3541;
	_Context->msg_Auto3541[4]=de_Auto3541;
	_Context->msg_Auto3541[5]=nl_Auto3541;
	_Context->msg_Auto3541[6]=pt_Auto3541;
	_Context->msg_Auto3541[7]=xx_Auto3541;
	_Context->hint_Auto3541[0]=en__Auto3541;
	_Context->hint_Auto3541[1]=fr__Auto3541;
	_Context->hint_Auto3541[2]=it__Auto3541;
	_Context->hint_Auto3541[3]=es__Auto3541;
	_Context->hint_Auto3541[4]=de__Auto3541;
	_Context->hint_Auto3541[5]=nl__Auto3541;
	_Context->hint_Auto3541[6]=pt__Auto3541;
	_Context->hint_Auto3541[7]=xx__Auto3541;
	for (i=0; i < 8; i++)_Context->msg_Auto3542[i]=" ";
	_Context->msg_Auto3542[0]=en_Auto3542;
	_Context->msg_Auto3542[1]=fr_Auto3542;
	_Context->msg_Auto3542[2]=it_Auto3542;
	_Context->msg_Auto3542[3]=es_Auto3542;
	_Context->msg_Auto3542[4]=de_Auto3542;
	_Context->msg_Auto3542[5]=nl_Auto3542;
	_Context->msg_Auto3542[6]=pt_Auto3542;
	_Context->msg_Auto3542[7]=xx_Auto3542;
	for (i=0; i < 8; i++)_Context->msg_Auto3543[i]=" ";
	_Context->msg_Auto3543[0]=en_Auto3543;
	_Context->msg_Auto3543[1]=fr_Auto3543;
	_Context->msg_Auto3543[2]=it_Auto3543;
	_Context->msg_Auto3543[3]=es_Auto3543;
	_Context->msg_Auto3543[4]=de_Auto3543;
	_Context->msg_Auto3543[5]=nl_Auto3543;
	_Context->msg_Auto3543[6]=pt_Auto3543;
	_Context->msg_Auto3543[7]=xx_Auto3543;
	_Context->hint_Auto3543[0]=en__Auto3543;
	_Context->hint_Auto3543[1]=fr__Auto3543;
	_Context->hint_Auto3543[2]=it__Auto3543;
	_Context->hint_Auto3543[3]=es__Auto3543;
	_Context->hint_Auto3543[4]=de__Auto3543;
	_Context->hint_Auto3543[5]=nl__Auto3543;
	_Context->hint_Auto3543[6]=pt__Auto3543;
	_Context->hint_Auto3543[7]=xx__Auto3543;
	for (i=0; i < 8; i++)_Context->msg_Auto3544[i]=" ";
	_Context->msg_Auto3544[0]=en_Auto3544;
	_Context->msg_Auto3544[1]=fr_Auto3544;
	_Context->msg_Auto3544[2]=it_Auto3544;
	_Context->msg_Auto3544[3]=es_Auto3544;
	_Context->msg_Auto3544[4]=de_Auto3544;
	_Context->msg_Auto3544[5]=nl_Auto3544;
	_Context->msg_Auto3544[6]=pt_Auto3544;
	_Context->msg_Auto3544[7]=xx_Auto3544;
	_Context->hint_Auto3544[0]=en__Auto3544;
	_Context->hint_Auto3544[1]=fr__Auto3544;
	_Context->hint_Auto3544[2]=it__Auto3544;
	_Context->hint_Auto3544[3]=es__Auto3544;
	_Context->hint_Auto3544[4]=de__Auto3544;
	_Context->hint_Auto3544[5]=nl__Auto3544;
	_Context->hint_Auto3544[6]=pt__Auto3544;
	_Context->hint_Auto3544[7]=xx__Auto3544;
	for (i=0; i < 8; i++)_Context->msg_Auto3545[i]=" ";
	_Context->msg_Auto3545[0]=en_Auto3545;
	_Context->msg_Auto3545[1]=fr_Auto3545;
	_Context->msg_Auto3545[2]=it_Auto3545;
	_Context->msg_Auto3545[3]=es_Auto3545;
	_Context->msg_Auto3545[4]=de_Auto3545;
	_Context->msg_Auto3545[5]=nl_Auto3545;
	_Context->msg_Auto3545[6]=pt_Auto3545;
	_Context->msg_Auto3545[7]=xx_Auto3545;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(165,20,470+10,560+10);
	return(0);
}

public 	int	accept_visual_colour_hide(struct accept_visual_colour_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,165,20);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_visual_colour_remove(
	struct accept_visual_colour_context * _Context,
	char * pfgcolour,
	char * pbgcolour)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_fgcolour, 4, pfgcolour);
		visual_transferout(_Context->buffer_bgcolour, 4, pbgcolour);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_fgcolour_show(struct accept_visual_colour_context * _Context) {
	int i;
	int j;
	int v;
	char*sptr;
	int slen;
	for(v=0,sptr=_Context->buffer_fgcolour,slen=4,i=0;
	i<slen;i++){
	if((*(sptr+i)>='0')&&(*(sptr+i)<='9'))
	v=((v*10)+(*(sptr+i)-'0'));
	}
	if(((i=(v/16))<16)
	&&((j=(v%16))<16)){
	visual_filzone(
	195+((400/16)*j),
	80+((400/16)*i),
	(400/16),(400/16),v,9);
	}
	visual_frame(395,510,32+2,16+2,5);
visual_text(395+1,510+1,32,16,vfh[1],16,0,_Context->buffer_fgcolour,4,0);

	filzone(395+32+8,510,32*2,16,v);
	return(-1);
}
private int on_bgcolour_show(struct accept_visual_colour_context * _Context) {
	int i;
	int j;
	int v;
	char*sptr;
	int slen;
	for(v=0,sptr=_Context->buffer_bgcolour,slen=4,i=0;
	i<slen;i++){
	if((*(sptr+i)>='0')&&(*(sptr+i)<='9'))
	v=((v*10)+(*(sptr+i)-'0'));
	}
	if(((i=(v/16))<16)
	&&((j=(v%16))<16)){
	visual_filzone(
	195+((400/16)*j),
	80+((400/16)*i),
	(400/16),(400/16),v|0x0F00,9);
	}
	visual_frame(395,540,32+2,16+2,5);
visual_text(395+1,540+1,32,16,vfh[1],16,0,_Context->buffer_bgcolour,4,0);

	filzone(395+32+8,540,32*2,16,v);
	return(-1);
}
private int on_target_show(struct accept_visual_colour_context * _Context) {
	int i;
	int j;
	visual_freeze();
	visual_frame(195,80,400+2,400+2,5);
visual_text(195+1,80+1,400,400,vfh[1],27,0,_Context->buffer_target,1250,0);
;
	for(i=0;i<16;i++){
	for(j=0;j<16;j++){
	filzone(
	195+((400/16)*j),
	80+((400/16)*i),
	(400/16),(400/16),((i*16)+j));
	}
	}
	visual_thaw(195,80,400,400);
	on_fgcolour_show(_Context);
	on_bgcolour_show(_Context);
	return(-1);
}

public	int	accept_visual_colour_show(struct accept_visual_colour_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,165,20);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(165,20,470,560,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(165,20,470,560,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_frame(185,500,420,70,2);
	visual_text(175,50,450,20,vfh[3],16,0,_Context->msg_Auto3541[_Context->language],strlen(_Context->msg_Auto3541[_Context->language]),1283);
	_Context->trigger_Auto3542=visual_trigger_code(_Context->msg_Auto3542[_Context->language],strlen(_Context->msg_Auto3542[_Context->language]));
	visual_button(195,510,56,48,vfh[2],34,0,_Context->msg_Auto3542[_Context->language],strlen(_Context->msg_Auto3542[_Context->language]),1040);
	visual_text(315,510,70,16,vfh[2],16,0,_Context->msg_Auto3543[_Context->language],strlen(_Context->msg_Auto3543[_Context->language]),1282);
	visual_text(315,540,70,16,vfh[2],16,0,_Context->msg_Auto3544[_Context->language],strlen(_Context->msg_Auto3544[_Context->language]),1282);
	_Context->trigger_Auto3545=visual_trigger_code(_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]));
	visual_button(535,510,56,48,vfh[2],34,0,_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]),1040);
	visual_filzone(195,80,420,420,19,12);
	visual_filzone(185,70,420,420,27,11);
	(void) on_target_show(_Context);
	visual_thaw(165,20,470,560);

	return(0);
}

private int Auto3542_help()
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

private int Auto3545_help()
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
private int on_Auto3542_event(struct accept_visual_colour_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto3545_event(struct accept_visual_colour_context * _Context) {
	return(27);
	return(-1);
}
private int on_target_event(struct accept_visual_colour_context * _Context) {
	int r,c,b;
	int v=0;
	char*sptr=(char*)0;
	int slen;
	switch(visual_event(1)){
	case 32:/*mimo up*/
	switch(visual_event(2)){
	case 1:
	sptr=_Context->buffer_fgcolour;
	slen=4;
	break;
	case 2:
	sptr=_Context->buffer_bgcolour;
	slen=4;
	break;
	}
		r=visual_event(6);
	c=visual_event(7);
	r-=80;
	c-=195;
	c/=(400/16);
	r/=(400/16);
	v=((r*16)+c);
	if(sptr){
	sprintf(sptr,"%u",v);
	on_target_show(_Context);
	}
	}
	return(-1);
}


public	int	accept_visual_colour_event(
struct accept_visual_colour_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto3542 == mb ) return(2);
		if (_Context->trigger_Auto3545 == mb ) return(5);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= 614 )  
	&&  (my >= 24 )  
	&&  (mx <= 630 )  
	&&  (my <= 40 )) {
		return(1);	/* Auto3539 */

		}
	if ((mx >= 598 )  
	&&  (my >= 24 )  
	&&  (mx <= 614 )  
	&&  (my <= 40 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcolours.htm");
			};
		return(-1);	/* Auto3539 */

		}
	if ((mx >= 582 )  
	&&  (my >= 24 )  
	&&  (mx <= 598 )  
	&&  (my <= 40 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_visual_colour_show(_Context);
		return(-1);	/* Auto3539 */

		}
		}
	if (( mx >= 195 ) 
	&&  ( my >= 510 ) 
	&&  ( mx <= 251 ) 
	&&  ( my <= 558 )) {
		return(2); /* Auto3542 */
		}
	if (( mx >= 395 ) 
	&&  ( my >= 510 ) 
	&&  ( mx <= 427 ) 
	&&  ( my <= 526 )) {
		return(3); /* fgcolour */
		}
	if (( mx >= 395 ) 
	&&  ( my >= 540 ) 
	&&  ( mx <= 427 ) 
	&&  ( my <= 556 )) {
		return(4); /* bgcolour */
		}
	if (( mx >= 535 ) 
	&&  ( my >= 510 ) 
	&&  ( mx <= 591 ) 
	&&  ( my <= 558 )) {
		return(5); /* Auto3545 */
		}
	if (( mx >= 195 ) 
	&&  ( my >= 80 ) 
	&&  ( mx <= 595 ) 
	&&  ( my <= 480 )) {
		return(6); /* target */
		}

	return(-1);
}
private int on_target_getfocus(struct accept_visual_colour_context * _Context) {
	return(visual_getch());
	return(-1);
}


public	int	accept_visual_colour_focus(struct accept_visual_colour_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto3542 */
				_Context->trigger_Auto3542=visual_trigger_code(_Context->msg_Auto3542[_Context->language],strlen(_Context->msg_Auto3542[_Context->language]));
				visual_button(195,510,56,48,vfh[2],34,0,_Context->msg_Auto3542[_Context->language],strlen(_Context->msg_Auto3542[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3542=visual_trigger_code(_Context->msg_Auto3542[_Context->language],strlen(_Context->msg_Auto3542[_Context->language]));
	visual_button(195,510,56,48,vfh[2],34,0,_Context->msg_Auto3542[_Context->language],strlen(_Context->msg_Auto3542[_Context->language]),1040);
				break;
			case	0x5 :
				/* Auto3545 */
				_Context->trigger_Auto3545=visual_trigger_code(_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]));
				visual_button(535,510,56,48,vfh[2],34,0,_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3545=visual_trigger_code(_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]));
	visual_button(535,510,56,48,vfh[2],34,0,_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]),1040);
				break;
			case	0x6 :
				/* target */
				_Context->keycode = on_target_getfocus(_Context);
			break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_visual_colour_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=6;
			accept_visual_colour_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_visual_colour_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (Auto3542_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Auto3545_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3539 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Auto3542 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3542=visual_trigger_code(_Context->msg_Auto3542[_Context->language],strlen(_Context->msg_Auto3542[_Context->language]));
						visual_button(195,510,56,48,vfh[2],34,0,_Context->msg_Auto3542[_Context->language],strlen(_Context->msg_Auto3542[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3542=visual_trigger_code(_Context->msg_Auto3542[_Context->language],strlen(_Context->msg_Auto3542[_Context->language]));
	visual_button(195,510,56,48,vfh[2],34,0,_Context->msg_Auto3542[_Context->language],strlen(_Context->msg_Auto3542[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3542_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* fgcolour */
					continue;
				case	0x4 :
					/* bgcolour */
					continue;
				case	0x5 :
					/* Auto3545 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3545=visual_trigger_code(_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]));
						visual_button(535,510,56,48,vfh[2],34,0,_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3545=visual_trigger_code(_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]));
	visual_button(535,510,56,48,vfh[2],34,0,_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3545_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* target */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_target_event(_Context)) != -1) break;

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
				_Context->focus_item=6;
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

public	int	accept_visual_colour(
	char * pfgcolour,
	char * pbgcolour)
{
	int	status=0;
	struct accept_visual_colour_context * _Context=(struct accept_visual_colour_context*) 0;
	status = accept_visual_colour_create(
	&_Context,
	 pfgcolour,
	 pbgcolour);
	if ( status != 0) return(status);
	status = accept_visual_colour_show(_Context);
		enter_modal();
	status = accept_visual_colour_focus(_Context);
		leave_modal();
	status = accept_visual_colour_hide(_Context);
	status = accept_visual_colour_remove(
	_Context,
	 pfgcolour,
	 pbgcolour);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcolours_c */
