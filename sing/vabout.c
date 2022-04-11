
#ifndef _vabout_c
#define _vabout_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vabout.sng  */
/* Target         : vabout.c  */
/* Identification : 0.0-1065019113-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct inform_about_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	signature[1];
	} * _Context;

private	int	inform_about_create()
{

	if (!(_Context = allocate( sizeof( struct inform_about_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=2;
	_Context->window_col=0;
	_Context->window_row=0;
	return(0);
}

private	int	inform_about_hide()
{

	return(0);
}

private	int	inform_about_remove()
{

	int	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}

private	int	inform_about_show()
{
	visual_freeze();
	visual_window(210,70,380,460,2,"Sing : Version 1.0a",19,0x0);
	visual_image(213,92,372,434,"skin.gif",4);
	visual_frame(230,120,340,56,2);
	visual_text(230,130,338,22,2,16,0,"Visual Design Tool",18,259);
	visual_text(234,154,330,16,2,16,0,"Version 1.0a",12,259);
	visual_frame(230,210,340,150,2);
	visual_text(240,228,320,24,2,16,0,"Image Editor",12,3);
	visual_text(240,250,320,24,2,16,0,"Font Editor",11,3);
	visual_text(240,270,320,24,2,16,0,"Forms Editor",12,3);
	visual_text(240,312,320,24,2,16,0,"Application Editor",18,3);
	visual_text(240,290,320,24,2,16,0,"Document Editor",15,3);
	visual_button(356,408,86,32,2,38,0,"Accept",6,0);
	visual_frame(233,474,334,33,2);
	visual_text(230,486,350,20,2,16,0,"Copyright (c) 2002 Prologue Software",36,259);
	visual_thaw(210,70,380,460);

	return(0);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}


private	int	inform_about_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 356 ) 
	&&  ( my >= 408 ) 
	&&  ( mx <= 442 ) 
	&&  ( my <= 440 )) {
		return(2); /* Accept */
		}

	return(-1);
}


private	int	inform_about_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Accept */
				visual_button(356,408,86,32,2,38,0,"Accept",6,2);
				_Context->keycode = visual_getch();
				visual_button(356,408,86,32,2,38,0,"Accept",6,0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			inform_about_show();
			continue;
		case	0x2 :
			_Context->focus_item=2;
			inform_about_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=inform_about_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto117 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(356,408,86,32,2,38,0,"Accept",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(356,408,86,32,2,38,0,"Accept",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

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
				_Context->focus_item=2;
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

public	int	inform_about()
{
	int	status=0;
	status = inform_about_create();
	if ( status != 0) return(status);
	status = inform_about_show();
		enter_modal();
	status = inform_about_focus();
		leave_modal();
	status = inform_about_hide();
	status = inform_about_remove();

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vabout_c */
