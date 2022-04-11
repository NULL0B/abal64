
#ifndef _tselect_c
#define _tselect_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.07                                                */
/* Production     : C                                                        */
/* Project        : tselect.xml                                              */
/* Target         : tselect.c                                                */
/* Identification : 0.0-1160735861-1851.1850                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "tselect.h"
static int	vfh[10];

public	int	tselect_attach()
{
	if ( visual_initialise(3|512) == -1 )
		return(56);

	else	{
		visual_palette("aqua.rgb",8);
		cicopalette(0,0);
		vfh[1] = visual_font("standard.fmf",12);
		vfh[2] = visual_font("arial2.fmf",10);
		vfh[3] = visual_font("arial3.fmf",10);
		vfh[4] = visual_font("arial4.fmf",10);
		vfh[5] = visual_font("arial5.fmf",10);
		vfh[6] = visual_font("arial6.fmf",10);
		vfh[7] = visual_font("font7.fmf",9);
		vfh[8] = visual_font("font8.fmf",9);
		vfh[9] = visual_font("/home/Dev/abal32/fonts/bmap1642.fmf",35);
		initialise_mouse();
		}
	return(0);
}

public	int	tselect_attach_mode(int mode)
{
	if ( visual_initialise(3|mode) == -1 )
		return(56);

	else	{
		visual_palette("aqua.rgb",8);
		cicopalette(0,0);
		vfh[1] = visual_font("standard.fmf",12);
		vfh[2] = visual_font("arial2.fmf",10);
		vfh[3] = visual_font("arial3.fmf",10);
		vfh[4] = visual_font("arial4.fmf",10);
		vfh[5] = visual_font("arial5.fmf",10);
		vfh[6] = visual_font("arial6.fmf",10);
		vfh[7] = visual_font("font7.fmf",9);
		vfh[8] = visual_font("font8.fmf",9);
		vfh[9] = visual_font("/home/Dev/abal32/fonts/bmap1642.fmf",35);
		initialise_mouse();
		}
	return(0);
}

public	int	tselect_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	tselect_create(struct tselect_context **cptr)
{

	int i;
	struct tselect_context * _Context=(struct tselect_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("/home/Dev/abal32/fonts/bmap1642.fmf",35);
	if (!(_Context = allocate( sizeof( struct tselect_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=3;
		_Context->value_Ouch=0;
		for (i=0; i < 75; i++)  *(_Context->buffer_message+i)=' ';
	_Context->x_Auto2429=0;
	_Context->y_Auto2429=0;
	_Context->w_Auto2429=410;
	_Context->h_Auto2429=360;
	_Context->window_col=0;
	_Context->window_row=0;
	return(0);
}

public 	int	tselect_hide(struct tselect_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;

	return(result);
}

public	int	tselect_remove(struct tselect_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}

public	int	tselect_show(struct tselect_context * _Context)
{
	visual_freeze();
	visual_window(0,0,410,360,vfh[1],"Sing : Version 1.0a",strlen("Sing : Version 1.0a"),0x0);
	visual_select(80,100,200,90,vfh[1],27,28,parse_selection("one|two|three|four",&_Context->value_Ouch),0);
	visual_frame(80,220,200+2,50+2,5);
	visual_text(80+1,220+1,200,50,vfh[1],27,28,_Context->buffer_message,75,0);
	visual_thaw(0,0,410,360);

	return(0);
}
private int on_Ouch_event(struct tselect_context * _Context) {
	sprintf(_Context->buffer_message,"%u",_Context->value_Ouch);
	visual_frame(80,220,200+2,50+2,5);
visual_text(80+1,220+1,200,50,vfh[1],27,28,_Context->buffer_message,75,0);
;
	return(-1);
}


public	int	tselect_event(
struct tselect_context * _Context){
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 80 ) 
	&&  (my >= 100 ) 
	&&  (mx <= 280 ) 
	&&  (my <= 116 )) {
		return(2); /* Ouch */
		}
	if (( mx >= 80 ) 
	&&  ( my >= 220 ) 
	&&  ( mx <= 280 ) 
	&&  ( my <= 270 )) {
		return(3); /* message */
		}

	return(-1);
}


public	int	tselect_focus(struct tselect_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Ouch */
				_Context->keycode = visual_select(80,100,200,90,vfh[1],27,28,parse_selection("one|two|three|four",&_Context->value_Ouch),2);
				break;
			case	0x3 :
				/* message */
				_Context->keycode = visual_edit(80+1,220+1,200,50,vfh[1],_Context->buffer_message,75);
			break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			tselect_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=3;
			tselect_show(_Context);
			continue;
		case	0x100 :
			if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
			if ((retcode=tselect_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto2429 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Ouch */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Ouch_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* message */
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

public	int	tselect()
{
	int	status=0;
	struct tselect_context * _Context=(struct tselect_context*) 0;
	status = tselect_create(&_Context);
	if ( status != 0) return(status);
	status = tselect_show(_Context);
		enter_modal();
	status = tselect_focus(_Context);
		leave_modal();
	status = tselect_hide(_Context);
	status = tselect_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _tselect_c */
