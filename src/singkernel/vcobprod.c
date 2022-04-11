
#ifndef _vcobprod_c
#define _vcobprod_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vcobprod.xml  */
/* Target         : vcobprod.c  */
/* Identification : 0.0-1100085469-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto1769   "Sing : Version 1.0a"
#define en_Auto1770   "COBOL Production Parameters"
#define en_Auto1771   "Cobol Production Filename"
#define en_Auto1772   "Program Identifier"
#define en_Auto1773   ""
#define en_Auto1774   ""
#define en_Auto1775   "Accept"
#define en_Auto1776   "Cancel"
static int	vfh[10];

private struct accept_cobol_production_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto1769[8];
	int	x_Auto1769;
	int	y_Auto1769;
	int	w_Auto1769;
	int	h_Auto1769;
	char * msg_Auto1770[8];
	char * msg_Auto1771[8];
	char * msg_Auto1772[8];
	char	buffer_Auto1773[68];
	char	buffer_Auto1774[68];
	char * msg_Auto1775[8];
	int	trigger_Auto1775;
	char * msg_Auto1776[8];
	int	trigger_Auto1776;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};

public	int	accept_cobol_production_create(
	struct accept_cobol_production_context ** cptr,
	char * pAuto1773,
	char * pAuto1774)
{

	int i;
	struct accept_cobol_production_context * _Context=(struct accept_cobol_production_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
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
		visual_transferin(_Context->buffer_Auto1773, 67, pAuto1773);
		visual_transferin(_Context->buffer_Auto1774, 67, pAuto1774);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto1769[i]=" ";
	_Context->msg_Auto1769[0]=en_Auto1769;
	_Context->x_Auto1769=100;
	_Context->y_Auto1769=175;
	_Context->w_Auto1769=600;
	_Context->h_Auto1769=250;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto1770[i]=" ";
	_Context->msg_Auto1770[0]=en_Auto1770;
	for (i=0; i < 8; i++)_Context->msg_Auto1771[i]=" ";
	_Context->msg_Auto1771[0]=en_Auto1771;
	for (i=0; i < 8; i++)_Context->msg_Auto1772[i]=" ";
	_Context->msg_Auto1772[0]=en_Auto1772;
	for (i=0; i < 8; i++)_Context->msg_Auto1775[i]=" ";
	_Context->msg_Auto1775[0]=en_Auto1775;
	for (i=0; i < 8; i++)_Context->msg_Auto1776[i]=" ";
	_Context->msg_Auto1776[0]=en_Auto1776;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto1769,_Context->y_Auto1769,600+10,250+10);
	return(0);
}

public 	int	accept_cobol_production_hide(struct accept_cobol_production_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto1769,_Context->y_Auto1769);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_cobol_production_remove(
	struct accept_cobol_production_context * _Context,
	char * pAuto1773,
	char * pAuto1774)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Auto1773, 67, pAuto1773);
		visual_transferout(_Context->buffer_Auto1774, 67, pAuto1774);
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
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto1769,_Context->y_Auto1769);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto1769,_Context->y_Auto1769,600,250,vfh[2],_Context->msg_Auto1769[_Context->language],strlen(_Context->msg_Auto1769[_Context->language]),0x407);
	visual_text(_Context->x_Auto1769+10,_Context->y_Auto1769+30,580,20,vfh[3],16,0,_Context->msg_Auto1770[_Context->language],strlen(_Context->msg_Auto1770[_Context->language]),1282);
	visual_frame(_Context->x_Auto1769+10,_Context->y_Auto1769+50,580,190,4);
	visual_text(_Context->x_Auto1769+30,_Context->y_Auto1769+70,170,20,vfh[2],16,0,_Context->msg_Auto1771[_Context->language],strlen(_Context->msg_Auto1771[_Context->language]),258);
	visual_text(_Context->x_Auto1769+30,_Context->y_Auto1769+120,168,16,vfh[2],16,0,_Context->msg_Auto1772[_Context->language],strlen(_Context->msg_Auto1772[_Context->language]),258);
	visual_frame(_Context->x_Auto1769+30,_Context->y_Auto1769+90,536+2,16+2,5);
	visual_text(_Context->x_Auto1769+30+1,_Context->y_Auto1769+90+1,536,16,vfh[1],16,0,_Context->buffer_Auto1773,67,0);
	visual_frame(_Context->x_Auto1769+30,_Context->y_Auto1769+140,536+2,16+2,5);
	visual_text(_Context->x_Auto1769+30+1,_Context->y_Auto1769+140+1,536,16,vfh[1],16,0,_Context->buffer_Auto1774,67,0);
	_Context->trigger_Auto1775=visual_trigger_code(_Context->msg_Auto1775[_Context->language],strlen(_Context->msg_Auto1775[_Context->language]));
	visual_button(_Context->x_Auto1769+30,_Context->y_Auto1769+180,180,32,vfh[2],16,0,_Context->msg_Auto1775[_Context->language],strlen(_Context->msg_Auto1775[_Context->language]),0);
	_Context->trigger_Auto1776=visual_trigger_code(_Context->msg_Auto1776[_Context->language],strlen(_Context->msg_Auto1776[_Context->language]));
	visual_button(_Context->x_Auto1769+390,_Context->y_Auto1769+180,176,32,vfh[2],16,0,_Context->msg_Auto1776[_Context->language],strlen(_Context->msg_Auto1776[_Context->language]),0);
	visual_thaw(_Context->x_Auto1769,_Context->y_Auto1769,600,250);
	visual_thaw(_Context->x_Auto1769,_Context->y_Auto1769,600,250);

	return(0);
}

private int Auto1769action(struct accept_cobol_production_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_cobol_production_hide(_Context);

		_Context->x_Auto1769 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto1769 < 0) { _Context->x_Auto1769=0; }
		_Context->y_Auto1769 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto1769 < 0) { _Context->y_Auto1769=0; }
			accept_cobol_production_show(_Context);

		visual_thaw(_Context->x_Auto1769,_Context->y_Auto1769,600,250);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Auto1775_event(struct accept_cobol_production_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto1776_event(struct accept_cobol_production_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_cobol_production_event(
struct accept_cobol_production_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto1775 == mb ) return(4);
		if (_Context->trigger_Auto1776 == mb ) return(5);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto1769+579) )  
	&&  (my >= (_Context->y_Auto1769+4) )  
	&&  (mx <= (_Context->x_Auto1769+596) )  
	&&  (my <= (_Context->y_Auto1769+20) )) {
		return(1);	/* Auto1769 */

		}
	if ((mx >= (_Context->x_Auto1769+563) )  
	&&  (my >= (_Context->y_Auto1769+4) )  
	&&  (mx <= (_Context->x_Auto1769+580) )  
	&&  (my <= (_Context->y_Auto1769+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcobprod.htm");
			};
		return(-1);	/* Auto1769 */

		}
	if ((mx >= (_Context->x_Auto1769+547) )  
	&&  (my >= (_Context->y_Auto1769+4) )  
	&&  (mx <= (_Context->x_Auto1769+564) )  
	&&  (my <= (_Context->y_Auto1769+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_cobol_production_show(_Context);
		return(-1);	/* Auto1769 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto1769+4) )  
		&&  (my >= (_Context->y_Auto1769+4) )  
		&&  (mx <= (_Context->x_Auto1769+532) )  
		&&  (my <= (_Context->y_Auto1769+20) )) {
			return( Auto1769action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto1769+30) ) 
	&&  ( my >= (_Context->y_Auto1769+90) ) 
	&&  ( mx <= (_Context->x_Auto1769+30+536) ) 
	&&  ( my <= (_Context->y_Auto1769+90+16))) {
		return(2); /* Auto1773 */
		}
	if (( mx >= (_Context->x_Auto1769+30) ) 
	&&  ( my >= (_Context->y_Auto1769+140) ) 
	&&  ( mx <= (_Context->x_Auto1769+30+536) ) 
	&&  ( my <= (_Context->y_Auto1769+140+16))) {
		return(3); /* Auto1774 */
		}
	if (( mx >= (_Context->x_Auto1769+30) ) 
	&&  ( my >= (_Context->y_Auto1769+180) ) 
	&&  ( mx <= (_Context->x_Auto1769+30+180) ) 
	&&  ( my <= (_Context->y_Auto1769+180+32))) {
		return(4); /* Auto1775 */
		}
	if (( mx >= (_Context->x_Auto1769+390) ) 
	&&  ( my >= (_Context->y_Auto1769+180) ) 
	&&  ( mx <= (_Context->x_Auto1769+390+176) ) 
	&&  ( my <= (_Context->y_Auto1769+180+32))) {
		return(5); /* Auto1776 */
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
				/* Auto1773 */
				_Context->keycode = visual_edit(_Context->x_Auto1769+30+1,_Context->y_Auto1769+90+1,536,16,vfh[1],_Context->buffer_Auto1773,67);
			break;
			case	0x3 :
				/* Auto1774 */
				_Context->keycode = visual_edit(_Context->x_Auto1769+30+1,_Context->y_Auto1769+140+1,536,16,vfh[1],_Context->buffer_Auto1774,67);
			break;
			case	0x4 :
				/* Auto1775 */
				visual_button(_Context->x_Auto1769+30,_Context->y_Auto1769+180,180,32,vfh[2],16,0,_Context->msg_Auto1775[_Context->language],strlen(_Context->msg_Auto1775[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto1769+30,_Context->y_Auto1769+180,180,32,vfh[2],16,0,_Context->msg_Auto1775[_Context->language],strlen(_Context->msg_Auto1775[_Context->language]),0);
				break;
			case	0x5 :
				/* Auto1776 */
				visual_button(_Context->x_Auto1769+390,_Context->y_Auto1769+180,176,32,vfh[2],16,0,_Context->msg_Auto1776[_Context->language],strlen(_Context->msg_Auto1776[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto1769+390,_Context->y_Auto1769+180,176,32,vfh[2],16,0,_Context->msg_Auto1776[_Context->language],strlen(_Context->msg_Auto1776[_Context->language]),0);
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
						/* Auto1769 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Auto1773 */
						continue;
					case	0x3 :
						/* Auto1774 */
						continue;
					case	0x4 :
						/* Auto1775 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1769+30,_Context->y_Auto1769+180,180,32,vfh[2],16,0,_Context->msg_Auto1775[_Context->language],strlen(_Context->msg_Auto1775[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1769+30,_Context->y_Auto1769+180,180,32,vfh[2],16,0,_Context->msg_Auto1775[_Context->language],strlen(_Context->msg_Auto1775[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1775_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* Auto1776 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1769+390,_Context->y_Auto1769+180,176,32,vfh[2],16,0,_Context->msg_Auto1776[_Context->language],strlen(_Context->msg_Auto1776[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1769+390,_Context->y_Auto1769+180,176,32,vfh[2],16,0,_Context->msg_Auto1776[_Context->language],strlen(_Context->msg_Auto1776[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1776_event(_Context)) != -1) break;

							}
						continue;
					case	0xffffffff :
					default :
						_Context->focus_item=1;
					continue;
					}
				break;
			case	0x1b :
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
	char * pAuto1773,
	char * pAuto1774)
{
	int	status=0;
	struct accept_cobol_production_context * _Context=(struct accept_cobol_production_context*) 0;
	status = accept_cobol_production_create(
	&_Context,
	 pAuto1773,
	 pAuto1774);
	if ( status != 0) return(status);
	status = accept_cobol_production_show(_Context);
		enter_modal();
	status = accept_cobol_production_focus(_Context);
		leave_modal();
	status = accept_cobol_production_hide(_Context);
	status = accept_cobol_production_remove(
	_Context,
	 pAuto1773,
	 pAuto1774);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcobprod_c */
