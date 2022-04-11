
#ifndef _vcobprod_c
#define _vcobprod_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vcobprod.xml                                             */
/* Target         : vcobprod.c                                               */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto3538   ""
#define fr__Auto3538   ""
#define it__Auto3538   ""
#define es__Auto3538   ""
#define de__Auto3538   ""
#define nl__Auto3538   ""
#define pt__Auto3538   ""
#define xx__Auto3538   ""
#define en_Auto3539   "COBOL Production Parameters"
#define fr_Auto3539   "ParamŠtres de production COBOL"
#define it_Auto3539   "COBOL Production Parameters"
#define es_Auto3539   "COBOL Production Parameters"
#define de_Auto3539   "COBOL Production Parameters"
#define nl_Auto3539   "COBOL Production Parameters"
#define pt_Auto3539   "COBOL Production Parameters"
#define xx_Auto3539   "COBOL Production Parameters"
#define en__Auto3539   ""
#define fr__Auto3539   ""
#define it__Auto3539   ""
#define es__Auto3539   ""
#define de__Auto3539   ""
#define nl__Auto3539   ""
#define pt__Auto3539   ""
#define xx__Auto3539   ""
#define en_Auto3540   "Cobol Production Filename"
#define fr_Auto3540   "Nom du fichier produit"
#define it_Auto3540   "Cobol Production Filename"
#define es_Auto3540   "Cobol Production Filename"
#define de_Auto3540   "Cobol Production Filename"
#define nl_Auto3540   "Cobol Production Filename"
#define pt_Auto3540   "Cobol Production Filename"
#define xx_Auto3540   "Cobol Production Filename"
#define en__Auto3540   ""
#define fr__Auto3540   ""
#define it__Auto3540   ""
#define es__Auto3540   ""
#define de__Auto3540   ""
#define nl__Auto3540   ""
#define pt__Auto3540   ""
#define xx__Auto3540   ""
#define en_Auto3541   "Program Identifier"
#define fr_Auto3541   "Identifiant du programme"
#define it_Auto3541   "Program Identifier"
#define es_Auto3541   "Program Identifier"
#define de_Auto3541   "Program Identifier"
#define nl_Auto3541   "Program Identifier"
#define pt_Auto3541   "Program Identifier"
#define xx_Auto3541   "Program Identifier"
#define en__Auto3541   ""
#define fr__Auto3541   ""
#define it__Auto3541   ""
#define es__Auto3541   ""
#define de__Auto3541   ""
#define nl__Auto3541   ""
#define pt__Auto3541   ""
#define xx__Auto3541   ""
#define en_Auto3542   ""
#define en_Auto3543   ""
#define en_Auto3544   "ok.gif"
#define fr_Auto3544   "ok.gif"
#define it_Auto3544   "ok.gif"
#define es_Auto3544   "ok.gif"
#define de_Auto3544   "ok.gif"
#define nl_Auto3544   "ok.gif"
#define pt_Auto3544   "ok.gif"
#define xx_Auto3544   "ok.gif"
#define en_Auto3545   "cancel.gif"
#define fr_Auto3545   "cancel.gif"
#define it_Auto3545   "cancel.gif"
#define es_Auto3545   "cancel.gif"
#define de_Auto3545   "cancel.gif"
#define nl_Auto3545   "cancel.gif"
#define pt_Auto3545   "cancel.gif"
#define xx_Auto3545   "cancel.gif"

private struct accept_cobol_production_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3538[8];
	char * hint_Auto3538[8];
	int	x_Auto3538;
	int	y_Auto3538;
	int	w_Auto3538;
	int	h_Auto3538;
	char * msg_Auto3539[8];
	char * hint_Auto3539[8];
	char * msg_Auto3540[8];
	char * hint_Auto3540[8];
	char * msg_Auto3541[8];
	char * hint_Auto3541[8];
	char * hint_Auto3542[8];
	char	buffer_Auto3542[256];
	char * hint_Auto3543[8];
	char	buffer_Auto3543[256];
	char * msg_Auto3544[8];
	int	trigger_Auto3544;
	char * hint_Auto3544[8];
	char * msg_Auto3545[8];
	int	trigger_Auto3545;
	char * hint_Auto3545[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};
static int	vfh[16];
private int on_Auto3544_event(struct accept_cobol_production_context * _Context);
private int on_Auto3545_event(struct accept_cobol_production_context * _Context);

public	int	accept_cobol_production_create(
	struct accept_cobol_production_context ** cptr,
	char * pAuto3542,
	char * pAuto3543)
{

	int i;
	struct accept_cobol_production_context * _Context=(struct accept_cobol_production_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_cobol_production_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=5;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Auto3542, 255, pAuto3542);
		visual_transferin(_Context->buffer_Auto3543, 255, pAuto3543);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3538[i]=" ";
	_Context->hint_Auto3538[0]=en__Auto3538;
	_Context->hint_Auto3538[1]=fr__Auto3538;
	_Context->hint_Auto3538[2]=it__Auto3538;
	_Context->hint_Auto3538[3]=es__Auto3538;
	_Context->hint_Auto3538[4]=de__Auto3538;
	_Context->hint_Auto3538[5]=nl__Auto3538;
	_Context->hint_Auto3538[6]=pt__Auto3538;
	_Context->hint_Auto3538[7]=xx__Auto3538;
	_Context->x_Auto3538=100;
	_Context->y_Auto3538=175;
	_Context->w_Auto3538=600;
	_Context->h_Auto3538=250;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3539[i]=" ";
	_Context->msg_Auto3539[0]=en_Auto3539;
	_Context->msg_Auto3539[1]=fr_Auto3539;
	_Context->msg_Auto3539[2]=it_Auto3539;
	_Context->msg_Auto3539[3]=es_Auto3539;
	_Context->msg_Auto3539[4]=de_Auto3539;
	_Context->msg_Auto3539[5]=nl_Auto3539;
	_Context->msg_Auto3539[6]=pt_Auto3539;
	_Context->msg_Auto3539[7]=xx_Auto3539;
	_Context->hint_Auto3539[0]=en__Auto3539;
	_Context->hint_Auto3539[1]=fr__Auto3539;
	_Context->hint_Auto3539[2]=it__Auto3539;
	_Context->hint_Auto3539[3]=es__Auto3539;
	_Context->hint_Auto3539[4]=de__Auto3539;
	_Context->hint_Auto3539[5]=nl__Auto3539;
	_Context->hint_Auto3539[6]=pt__Auto3539;
	_Context->hint_Auto3539[7]=xx__Auto3539;
	for (i=0; i < 8; i++)_Context->msg_Auto3540[i]=" ";
	_Context->msg_Auto3540[0]=en_Auto3540;
	_Context->msg_Auto3540[1]=fr_Auto3540;
	_Context->msg_Auto3540[2]=it_Auto3540;
	_Context->msg_Auto3540[3]=es_Auto3540;
	_Context->msg_Auto3540[4]=de_Auto3540;
	_Context->msg_Auto3540[5]=nl_Auto3540;
	_Context->msg_Auto3540[6]=pt_Auto3540;
	_Context->msg_Auto3540[7]=xx_Auto3540;
	_Context->hint_Auto3540[0]=en__Auto3540;
	_Context->hint_Auto3540[1]=fr__Auto3540;
	_Context->hint_Auto3540[2]=it__Auto3540;
	_Context->hint_Auto3540[3]=es__Auto3540;
	_Context->hint_Auto3540[4]=de__Auto3540;
	_Context->hint_Auto3540[5]=nl__Auto3540;
	_Context->hint_Auto3540[6]=pt__Auto3540;
	_Context->hint_Auto3540[7]=xx__Auto3540;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3544[i]=" ";
	_Context->msg_Auto3544[0]=en_Auto3544;
	_Context->msg_Auto3544[1]=fr_Auto3544;
	_Context->msg_Auto3544[2]=it_Auto3544;
	_Context->msg_Auto3544[3]=es_Auto3544;
	_Context->msg_Auto3544[4]=de_Auto3544;
	_Context->msg_Auto3544[5]=nl_Auto3544;
	_Context->msg_Auto3544[6]=pt_Auto3544;
	_Context->msg_Auto3544[7]=xx_Auto3544;
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
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3538,_Context->y_Auto3538,600+10,250+10);
	return(0);
}

public 	int	accept_cobol_production_hide(struct accept_cobol_production_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3538,_Context->y_Auto3538);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_cobol_production_remove(
	struct accept_cobol_production_context * _Context,
	char * pAuto3542,
	char * pAuto3543)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Auto3542, 255, pAuto3542);
		visual_transferout(_Context->buffer_Auto3543, 255, pAuto3543);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_cobol_production_show(struct accept_cobol_production_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3538,_Context->y_Auto3538);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto3538,_Context->y_Auto3538,600,250,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
	visual_text(_Context->x_Auto3538+10,_Context->y_Auto3538+30,580,20,vfh[3],16,0,_Context->msg_Auto3539[_Context->language],strlen(_Context->msg_Auto3539[_Context->language]),1282);
	visual_frame(_Context->x_Auto3538+10,_Context->y_Auto3538+50,580,190,4);
	visual_text(_Context->x_Auto3538+30,_Context->y_Auto3538+70,170,20,vfh[2],16,0,_Context->msg_Auto3540[_Context->language],strlen(_Context->msg_Auto3540[_Context->language]),258);
	visual_text(_Context->x_Auto3538+30,_Context->y_Auto3538+120,168,16,vfh[2],16,0,_Context->msg_Auto3541[_Context->language],strlen(_Context->msg_Auto3541[_Context->language]),258);
	visual_frame(_Context->x_Auto3538+30,_Context->y_Auto3538+90,536+2,16+2,5);
	visual_text(_Context->x_Auto3538+30+1,_Context->y_Auto3538+90+1,536,16,vfh[1],16,0,_Context->buffer_Auto3542,255,0);
	visual_frame(_Context->x_Auto3538+30,_Context->y_Auto3538+140,536+2,16+2,5);
	visual_text(_Context->x_Auto3538+30+1,_Context->y_Auto3538+140+1,536,16,vfh[1],16,0,_Context->buffer_Auto3543,255,0);
	_Context->trigger_Auto3544=visual_trigger_code(_Context->msg_Auto3544[_Context->language],strlen(_Context->msg_Auto3544[_Context->language]));
	visual_button(_Context->x_Auto3538+30,_Context->y_Auto3538+180,56,48,vfh[2],34,0,_Context->msg_Auto3544[_Context->language],strlen(_Context->msg_Auto3544[_Context->language]),1040);
	_Context->trigger_Auto3545=visual_trigger_code(_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]));
	visual_button(_Context->x_Auto3538+510,_Context->y_Auto3538+180,56,48,vfh[2],34,0,_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3538,_Context->y_Auto3538,600,250);

	return(0);
}

private int Auto3538action(struct accept_cobol_production_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_cobol_production_hide(_Context);

		_Context->x_Auto3538 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3538 < 0) { _Context->x_Auto3538=0; }
		_Context->y_Auto3538 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3538 < 0) { _Context->y_Auto3538=0; }
			accept_cobol_production_show(_Context);

		visual_thaw(_Context->x_Auto3538,_Context->y_Auto3538,600,250);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3544_event(struct accept_cobol_production_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto3545_event(struct accept_cobol_production_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_cobol_production_event(
struct accept_cobol_production_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto3544 == mb ) return(4);
		if (_Context->trigger_Auto3545 == mb ) return(5);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3538+579) )  
	&&  (my >= (_Context->y_Auto3538+4) )  
	&&  (mx <= (_Context->x_Auto3538+596) )  
	&&  (my <= (_Context->y_Auto3538+20) )) {
		return(1);	/* Auto3538 */

		}
	if ((mx >= (_Context->x_Auto3538+563) )  
	&&  (my >= (_Context->y_Auto3538+4) )  
	&&  (mx <= (_Context->x_Auto3538+580) )  
	&&  (my <= (_Context->y_Auto3538+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcobprod.htm");
			};
		return(-1);	/* Auto3538 */

		}
	if ((mx >= (_Context->x_Auto3538+547) )  
	&&  (my >= (_Context->y_Auto3538+4) )  
	&&  (mx <= (_Context->x_Auto3538+564) )  
	&&  (my <= (_Context->y_Auto3538+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_cobol_production_show(_Context);
		return(-1);	/* Auto3538 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3538+4) )  
		&&  (my >= (_Context->y_Auto3538+4) )  
		&&  (mx <= (_Context->x_Auto3538+532) )  
		&&  (my <= (_Context->y_Auto3538+20) )) {
			return( Auto3538action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3538+30) ) 
	&&  ( my >= (_Context->y_Auto3538+90) ) 
	&&  ( mx <= (_Context->x_Auto3538+30+536) ) 
	&&  ( my <= (_Context->y_Auto3538+90+16))) {
		return(2); /* Auto3542 */
		}
	if (( mx >= (_Context->x_Auto3538+30) ) 
	&&  ( my >= (_Context->y_Auto3538+140) ) 
	&&  ( mx <= (_Context->x_Auto3538+30+536) ) 
	&&  ( my <= (_Context->y_Auto3538+140+16))) {
		return(3); /* Auto3543 */
		}
	if (( mx >= (_Context->x_Auto3538+30) ) 
	&&  ( my >= (_Context->y_Auto3538+180) ) 
	&&  ( mx <= (_Context->x_Auto3538+30+56) ) 
	&&  ( my <= (_Context->y_Auto3538+180+48))) {
		return(4); /* Auto3544 */
		}
	if (( mx >= (_Context->x_Auto3538+510) ) 
	&&  ( my >= (_Context->y_Auto3538+180) ) 
	&&  ( mx <= (_Context->x_Auto3538+510+56) ) 
	&&  ( my <= (_Context->y_Auto3538+180+48))) {
		return(5); /* Auto3545 */
		}

	return(-1);
}


public	int	accept_cobol_production_focus(struct accept_cobol_production_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto3542 */
				_Context->keycode = visual_edit(_Context->x_Auto3538+30+1,_Context->y_Auto3538+90+1,536,16,vfh[1],_Context->buffer_Auto3542,255);
			break;
			case	0x3 :
				/* Auto3543 */
				_Context->keycode = visual_edit(_Context->x_Auto3538+30+1,_Context->y_Auto3538+140+1,536,16,vfh[1],_Context->buffer_Auto3543,255);
			break;
			case	0x4 :
				/* Auto3544 */
				_Context->trigger_Auto3544=visual_trigger_code(_Context->msg_Auto3544[_Context->language],strlen(_Context->msg_Auto3544[_Context->language]));
				visual_button(_Context->x_Auto3538+30,_Context->y_Auto3538+180,56,48,vfh[2],34,0,_Context->msg_Auto3544[_Context->language],strlen(_Context->msg_Auto3544[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3544=visual_trigger_code(_Context->msg_Auto3544[_Context->language],strlen(_Context->msg_Auto3544[_Context->language]));
	visual_button(_Context->x_Auto3538+30,_Context->y_Auto3538+180,56,48,vfh[2],34,0,_Context->msg_Auto3544[_Context->language],strlen(_Context->msg_Auto3544[_Context->language]),1040);
				break;
			case	0x5 :
				/* Auto3545 */
				_Context->trigger_Auto3545=visual_trigger_code(_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]));
				visual_button(_Context->x_Auto3538+510,_Context->y_Auto3538+180,56,48,vfh[2],34,0,_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3545=visual_trigger_code(_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]));
	visual_button(_Context->x_Auto3538+510,_Context->y_Auto3538+180,56,48,vfh[2],34,0,_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_cobol_production_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=5;
			accept_cobol_production_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_cobol_production_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3538 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Auto3542 */
					continue;
				case	0x3 :
					/* Auto3543 */
					continue;
				case	0x4 :
					/* Auto3544 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3544=visual_trigger_code(_Context->msg_Auto3544[_Context->language],strlen(_Context->msg_Auto3544[_Context->language]));
						visual_button(_Context->x_Auto3538+30,_Context->y_Auto3538+180,56,48,vfh[2],34,0,_Context->msg_Auto3544[_Context->language],strlen(_Context->msg_Auto3544[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3544=visual_trigger_code(_Context->msg_Auto3544[_Context->language],strlen(_Context->msg_Auto3544[_Context->language]));
	visual_button(_Context->x_Auto3538+30,_Context->y_Auto3538+180,56,48,vfh[2],34,0,_Context->msg_Auto3544[_Context->language],strlen(_Context->msg_Auto3544[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3544_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto3545 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3545=visual_trigger_code(_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]));
						visual_button(_Context->x_Auto3538+510,_Context->y_Auto3538+180,56,48,vfh[2],34,0,_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3545=visual_trigger_code(_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]));
	visual_button(_Context->x_Auto3538+510,_Context->y_Auto3538+180,56,48,vfh[2],34,0,_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3545_event(_Context)) != -1) break;

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

public	int	accept_cobol_production(
	char * pAuto3542,
	char * pAuto3543)
{
	int	status=0;
	struct accept_cobol_production_context * _Context=(struct accept_cobol_production_context*) 0;
	status = accept_cobol_production_create(
	&_Context,
	 pAuto3542,
	 pAuto3543);
	if ( status != 0) return(status);
	status = accept_cobol_production_show(_Context);
		enter_modal();
	status = accept_cobol_production_focus(_Context);
		leave_modal();
	status = accept_cobol_production_hide(_Context);
	status = accept_cobol_production_remove(
	_Context,
	 pAuto3542,
	 pAuto3543);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcobprod_c */
