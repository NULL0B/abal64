
#ifndef _vcobprod_c
#define _vcobprod_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vcobprod.xml                                             */
/* Target         : vcobprod.c                                               */
/* Identification : 0.0-1177511934-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto2709   ""
#define fr__Auto2709   ""
#define it__Auto2709   ""
#define es__Auto2709   ""
#define de__Auto2709   ""
#define nl__Auto2709   ""
#define pt__Auto2709   ""
#define xx__Auto2709   ""
#define en_Auto2710   "COBOL Production Parameters"
#define fr_Auto2710   "ParamŠtres de production COBOL"
#define it_Auto2710   "COBOL Production Parameters"
#define es_Auto2710   "COBOL Production Parameters"
#define de_Auto2710   "COBOL Production Parameters"
#define nl_Auto2710   "COBOL Production Parameters"
#define pt_Auto2710   "COBOL Production Parameters"
#define xx_Auto2710   "COBOL Production Parameters"
#define en__Auto2710   ""
#define fr__Auto2710   ""
#define it__Auto2710   ""
#define es__Auto2710   ""
#define de__Auto2710   ""
#define nl__Auto2710   ""
#define pt__Auto2710   ""
#define xx__Auto2710   ""
#define en_Auto2711   "Cobol Production Filename"
#define fr_Auto2711   "Nom du fichier produit"
#define it_Auto2711   "Cobol Production Filename"
#define es_Auto2711   "Cobol Production Filename"
#define de_Auto2711   "Cobol Production Filename"
#define nl_Auto2711   "Cobol Production Filename"
#define pt_Auto2711   "Cobol Production Filename"
#define xx_Auto2711   "Cobol Production Filename"
#define en__Auto2711   ""
#define fr__Auto2711   ""
#define it__Auto2711   ""
#define es__Auto2711   ""
#define de__Auto2711   ""
#define nl__Auto2711   ""
#define pt__Auto2711   ""
#define xx__Auto2711   ""
#define en_Auto2712   "Program Identifier"
#define fr_Auto2712   "Identifiant du programme"
#define it_Auto2712   "Program Identifier"
#define es_Auto2712   "Program Identifier"
#define de_Auto2712   "Program Identifier"
#define nl_Auto2712   "Program Identifier"
#define pt_Auto2712   "Program Identifier"
#define xx_Auto2712   "Program Identifier"
#define en__Auto2712   ""
#define fr__Auto2712   ""
#define it__Auto2712   ""
#define es__Auto2712   ""
#define de__Auto2712   ""
#define nl__Auto2712   ""
#define pt__Auto2712   ""
#define xx__Auto2712   ""
#define en_Auto2713   ""
#define en_Auto2714   ""
#define en_Auto2715   "ok.gif"
#define fr_Auto2715   "ok.gif"
#define it_Auto2715   "ok.gif"
#define es_Auto2715   "ok.gif"
#define de_Auto2715   "ok.gif"
#define nl_Auto2715   "ok.gif"
#define pt_Auto2715   "ok.gif"
#define xx_Auto2715   "ok.gif"
#define en_Auto2716   "cancel.gif"
#define fr_Auto2716   "cancel.gif"
#define it_Auto2716   "cancel.gif"
#define es_Auto2716   "cancel.gif"
#define de_Auto2716   "cancel.gif"
#define nl_Auto2716   "cancel.gif"
#define pt_Auto2716   "cancel.gif"
#define xx_Auto2716   "cancel.gif"

private struct accept_cobol_production_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto2709[8];
	char * hint_Auto2709[8];
	int	x_Auto2709;
	int	y_Auto2709;
	int	w_Auto2709;
	int	h_Auto2709;
	char * msg_Auto2710[8];
	char * hint_Auto2710[8];
	char * msg_Auto2711[8];
	char * hint_Auto2711[8];
	char * msg_Auto2712[8];
	char * hint_Auto2712[8];
	char * hint_Auto2713[8];
	char	buffer_Auto2713[256];
	char * hint_Auto2714[8];
	char	buffer_Auto2714[256];
	char * msg_Auto2715[8];
	int	trigger_Auto2715;
	char * hint_Auto2715[8];
	char * msg_Auto2716[8];
	int	trigger_Auto2716;
	char * hint_Auto2716[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};
static int	vfh[16];

public	int	accept_cobol_production_create(
	struct accept_cobol_production_context ** cptr,
	char * pAuto2713,
	char * pAuto2714)
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
	vfh[10] = visual_font("font10.fmf",10);
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
		visual_transferin(_Context->buffer_Auto2713, 255, pAuto2713);
		visual_transferin(_Context->buffer_Auto2714, 255, pAuto2714);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto2709[i]=" ";
	_Context->hint_Auto2709[0]=en__Auto2709;
	_Context->hint_Auto2709[1]=fr__Auto2709;
	_Context->hint_Auto2709[2]=it__Auto2709;
	_Context->hint_Auto2709[3]=es__Auto2709;
	_Context->hint_Auto2709[4]=de__Auto2709;
	_Context->hint_Auto2709[5]=nl__Auto2709;
	_Context->hint_Auto2709[6]=pt__Auto2709;
	_Context->hint_Auto2709[7]=xx__Auto2709;
	_Context->x_Auto2709=100;
	_Context->y_Auto2709=175;
	_Context->w_Auto2709=600;
	_Context->h_Auto2709=250;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2710[i]=" ";
	_Context->msg_Auto2710[0]=en_Auto2710;
	_Context->msg_Auto2710[1]=fr_Auto2710;
	_Context->msg_Auto2710[2]=it_Auto2710;
	_Context->msg_Auto2710[3]=es_Auto2710;
	_Context->msg_Auto2710[4]=de_Auto2710;
	_Context->msg_Auto2710[5]=nl_Auto2710;
	_Context->msg_Auto2710[6]=pt_Auto2710;
	_Context->msg_Auto2710[7]=xx_Auto2710;
	_Context->hint_Auto2710[0]=en__Auto2710;
	_Context->hint_Auto2710[1]=fr__Auto2710;
	_Context->hint_Auto2710[2]=it__Auto2710;
	_Context->hint_Auto2710[3]=es__Auto2710;
	_Context->hint_Auto2710[4]=de__Auto2710;
	_Context->hint_Auto2710[5]=nl__Auto2710;
	_Context->hint_Auto2710[6]=pt__Auto2710;
	_Context->hint_Auto2710[7]=xx__Auto2710;
	for (i=0; i < 8; i++)_Context->msg_Auto2711[i]=" ";
	_Context->msg_Auto2711[0]=en_Auto2711;
	_Context->msg_Auto2711[1]=fr_Auto2711;
	_Context->msg_Auto2711[2]=it_Auto2711;
	_Context->msg_Auto2711[3]=es_Auto2711;
	_Context->msg_Auto2711[4]=de_Auto2711;
	_Context->msg_Auto2711[5]=nl_Auto2711;
	_Context->msg_Auto2711[6]=pt_Auto2711;
	_Context->msg_Auto2711[7]=xx_Auto2711;
	_Context->hint_Auto2711[0]=en__Auto2711;
	_Context->hint_Auto2711[1]=fr__Auto2711;
	_Context->hint_Auto2711[2]=it__Auto2711;
	_Context->hint_Auto2711[3]=es__Auto2711;
	_Context->hint_Auto2711[4]=de__Auto2711;
	_Context->hint_Auto2711[5]=nl__Auto2711;
	_Context->hint_Auto2711[6]=pt__Auto2711;
	_Context->hint_Auto2711[7]=xx__Auto2711;
	for (i=0; i < 8; i++)_Context->msg_Auto2712[i]=" ";
	_Context->msg_Auto2712[0]=en_Auto2712;
	_Context->msg_Auto2712[1]=fr_Auto2712;
	_Context->msg_Auto2712[2]=it_Auto2712;
	_Context->msg_Auto2712[3]=es_Auto2712;
	_Context->msg_Auto2712[4]=de_Auto2712;
	_Context->msg_Auto2712[5]=nl_Auto2712;
	_Context->msg_Auto2712[6]=pt_Auto2712;
	_Context->msg_Auto2712[7]=xx_Auto2712;
	_Context->hint_Auto2712[0]=en__Auto2712;
	_Context->hint_Auto2712[1]=fr__Auto2712;
	_Context->hint_Auto2712[2]=it__Auto2712;
	_Context->hint_Auto2712[3]=es__Auto2712;
	_Context->hint_Auto2712[4]=de__Auto2712;
	_Context->hint_Auto2712[5]=nl__Auto2712;
	_Context->hint_Auto2712[6]=pt__Auto2712;
	_Context->hint_Auto2712[7]=xx__Auto2712;
	for (i=0; i < 8; i++)_Context->msg_Auto2715[i]=" ";
	_Context->msg_Auto2715[0]=en_Auto2715;
	_Context->msg_Auto2715[1]=fr_Auto2715;
	_Context->msg_Auto2715[2]=it_Auto2715;
	_Context->msg_Auto2715[3]=es_Auto2715;
	_Context->msg_Auto2715[4]=de_Auto2715;
	_Context->msg_Auto2715[5]=nl_Auto2715;
	_Context->msg_Auto2715[6]=pt_Auto2715;
	_Context->msg_Auto2715[7]=xx_Auto2715;
	for (i=0; i < 8; i++)_Context->msg_Auto2716[i]=" ";
	_Context->msg_Auto2716[0]=en_Auto2716;
	_Context->msg_Auto2716[1]=fr_Auto2716;
	_Context->msg_Auto2716[2]=it_Auto2716;
	_Context->msg_Auto2716[3]=es_Auto2716;
	_Context->msg_Auto2716[4]=de_Auto2716;
	_Context->msg_Auto2716[5]=nl_Auto2716;
	_Context->msg_Auto2716[6]=pt_Auto2716;
	_Context->msg_Auto2716[7]=xx_Auto2716;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto2709,_Context->y_Auto2709,600+10,250+10);
	return(0);
}

public 	int	accept_cobol_production_hide(struct accept_cobol_production_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto2709,_Context->y_Auto2709);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_cobol_production_remove(
	struct accept_cobol_production_context * _Context,
	char * pAuto2713,
	char * pAuto2714)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Auto2713, 255, pAuto2713);
		visual_transferout(_Context->buffer_Auto2714, 255, pAuto2714);
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
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto2709,_Context->y_Auto2709);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto2709,_Context->y_Auto2709,600,250,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
	visual_text(_Context->x_Auto2709+10,_Context->y_Auto2709+30,580,20,vfh[3],16,0,_Context->msg_Auto2710[_Context->language],strlen(_Context->msg_Auto2710[_Context->language]),1282);
	visual_frame(_Context->x_Auto2709+10,_Context->y_Auto2709+50,580,190,4);
	visual_text(_Context->x_Auto2709+30,_Context->y_Auto2709+70,170,20,vfh[2],16,0,_Context->msg_Auto2711[_Context->language],strlen(_Context->msg_Auto2711[_Context->language]),258);
	visual_text(_Context->x_Auto2709+30,_Context->y_Auto2709+120,168,16,vfh[2],16,0,_Context->msg_Auto2712[_Context->language],strlen(_Context->msg_Auto2712[_Context->language]),258);
	visual_frame(_Context->x_Auto2709+30,_Context->y_Auto2709+90,536+2,16+2,5);
	visual_text(_Context->x_Auto2709+30+1,_Context->y_Auto2709+90+1,536,16,vfh[1],16,0,_Context->buffer_Auto2713,255,0);
	visual_frame(_Context->x_Auto2709+30,_Context->y_Auto2709+140,536+2,16+2,5);
	visual_text(_Context->x_Auto2709+30+1,_Context->y_Auto2709+140+1,536,16,vfh[1],16,0,_Context->buffer_Auto2714,255,0);
	_Context->trigger_Auto2715=visual_trigger_code(_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]));
	visual_button(_Context->x_Auto2709+30,_Context->y_Auto2709+180,56,48,vfh[2],34,0,_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]),1040);
	_Context->trigger_Auto2716=visual_trigger_code(_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]));
	visual_button(_Context->x_Auto2709+510,_Context->y_Auto2709+180,56,48,vfh[2],34,0,_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]),1040);
	visual_thaw(_Context->x_Auto2709,_Context->y_Auto2709,600,250);

	return(0);
}

private int Auto2709action(struct accept_cobol_production_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_cobol_production_hide(_Context);

		_Context->x_Auto2709 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto2709 < 0) { _Context->x_Auto2709=0; }
		_Context->y_Auto2709 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto2709 < 0) { _Context->y_Auto2709=0; }
			accept_cobol_production_show(_Context);

		visual_thaw(_Context->x_Auto2709,_Context->y_Auto2709,600,250);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto2715_event(struct accept_cobol_production_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto2716_event(struct accept_cobol_production_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_cobol_production_event(
struct accept_cobol_production_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto2715 == mb ) return(4);
		if (_Context->trigger_Auto2716 == mb ) return(5);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto2709+579) )  
	&&  (my >= (_Context->y_Auto2709+4) )  
	&&  (mx <= (_Context->x_Auto2709+596) )  
	&&  (my <= (_Context->y_Auto2709+20) )) {
		return(1);	/* Auto2709 */

		}
	if ((mx >= (_Context->x_Auto2709+563) )  
	&&  (my >= (_Context->y_Auto2709+4) )  
	&&  (mx <= (_Context->x_Auto2709+580) )  
	&&  (my <= (_Context->y_Auto2709+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcobprod.htm");
			};
		return(-1);	/* Auto2709 */

		}
	if ((mx >= (_Context->x_Auto2709+547) )  
	&&  (my >= (_Context->y_Auto2709+4) )  
	&&  (mx <= (_Context->x_Auto2709+564) )  
	&&  (my <= (_Context->y_Auto2709+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_cobol_production_show(_Context);
		return(-1);	/* Auto2709 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto2709+4) )  
		&&  (my >= (_Context->y_Auto2709+4) )  
		&&  (mx <= (_Context->x_Auto2709+532) )  
		&&  (my <= (_Context->y_Auto2709+20) )) {
			return( Auto2709action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto2709+30) ) 
	&&  ( my >= (_Context->y_Auto2709+90) ) 
	&&  ( mx <= (_Context->x_Auto2709+30+536) ) 
	&&  ( my <= (_Context->y_Auto2709+90+16))) {
		return(2); /* Auto2713 */
		}
	if (( mx >= (_Context->x_Auto2709+30) ) 
	&&  ( my >= (_Context->y_Auto2709+140) ) 
	&&  ( mx <= (_Context->x_Auto2709+30+536) ) 
	&&  ( my <= (_Context->y_Auto2709+140+16))) {
		return(3); /* Auto2714 */
		}
	if (( mx >= (_Context->x_Auto2709+30) ) 
	&&  ( my >= (_Context->y_Auto2709+180) ) 
	&&  ( mx <= (_Context->x_Auto2709+30+56) ) 
	&&  ( my <= (_Context->y_Auto2709+180+48))) {
		return(4); /* Auto2715 */
		}
	if (( mx >= (_Context->x_Auto2709+510) ) 
	&&  ( my >= (_Context->y_Auto2709+180) ) 
	&&  ( mx <= (_Context->x_Auto2709+510+56) ) 
	&&  ( my <= (_Context->y_Auto2709+180+48))) {
		return(5); /* Auto2716 */
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
				/* Auto2713 */
				_Context->keycode = visual_edit(_Context->x_Auto2709+30+1,_Context->y_Auto2709+90+1,536,16,vfh[1],_Context->buffer_Auto2713,255);
			break;
			case	0x3 :
				/* Auto2714 */
				_Context->keycode = visual_edit(_Context->x_Auto2709+30+1,_Context->y_Auto2709+140+1,536,16,vfh[1],_Context->buffer_Auto2714,255);
			break;
			case	0x4 :
				/* Auto2715 */
				_Context->trigger_Auto2715=visual_trigger_code(_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]));
				visual_button(_Context->x_Auto2709+30,_Context->y_Auto2709+180,56,48,vfh[2],34,0,_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2715=visual_trigger_code(_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]));
	visual_button(_Context->x_Auto2709+30,_Context->y_Auto2709+180,56,48,vfh[2],34,0,_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]),1040);
				break;
			case	0x5 :
				/* Auto2716 */
				_Context->trigger_Auto2716=visual_trigger_code(_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]));
				visual_button(_Context->x_Auto2709+510,_Context->y_Auto2709+180,56,48,vfh[2],34,0,_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2716=visual_trigger_code(_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]));
	visual_button(_Context->x_Auto2709+510,_Context->y_Auto2709+180,56,48,vfh[2],34,0,_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]),1040);
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
					/* Auto2709 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Auto2713 */
					continue;
				case	0x3 :
					/* Auto2714 */
					continue;
				case	0x4 :
					/* Auto2715 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2715=visual_trigger_code(_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]));
						visual_button(_Context->x_Auto2709+30,_Context->y_Auto2709+180,56,48,vfh[2],34,0,_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2715=visual_trigger_code(_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]));
	visual_button(_Context->x_Auto2709+30,_Context->y_Auto2709+180,56,48,vfh[2],34,0,_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2715_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto2716 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2716=visual_trigger_code(_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]));
						visual_button(_Context->x_Auto2709+510,_Context->y_Auto2709+180,56,48,vfh[2],34,0,_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2716=visual_trigger_code(_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]));
	visual_button(_Context->x_Auto2709+510,_Context->y_Auto2709+180,56,48,vfh[2],34,0,_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2716_event(_Context)) != -1) break;

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
	char * pAuto2713,
	char * pAuto2714)
{
	int	status=0;
	struct accept_cobol_production_context * _Context=(struct accept_cobol_production_context*) 0;
	status = accept_cobol_production_create(
	&_Context,
	 pAuto2713,
	 pAuto2714);
	if ( status != 0) return(status);
	status = accept_cobol_production_show(_Context);
		enter_modal();
	status = accept_cobol_production_focus(_Context);
		leave_modal();
	status = accept_cobol_production_hide(_Context);
	status = accept_cobol_production_remove(
	_Context,
	 pAuto2713,
	 pAuto2714);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcobprod_c */
