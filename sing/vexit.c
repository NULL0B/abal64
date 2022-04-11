
#ifndef _vexit_c
#define _vexit_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vexit.sng  */
/* Target         : vexit.c  */
/* Identification : 0.0-1065019002-2581.2580 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_exit_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_Auto283[48];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	} * _Context;

private	int	accept_exit_create(
	char * pAuto283)
{

	if (!(_Context = allocate( sizeof( struct accept_exit_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=4;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"K");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Auto283, 47, pAuto283);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(160,160,480+10,280+10);
	return(0);
}

private	int	accept_exit_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,160,160);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_exit_remove(
	char * pAuto283)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"K");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Auto283, 47, pAuto283);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_exit_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,160,160);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(160,160,480,280,2,"Sing : Version 1.0a",19,0x403);
	visual_image(164,181,471,255,"skin.gif",4);
	visual_frame(170,190,460,240,4);
	visual_frame(180,260,440,160,4);
	visual_filzone(185,265,429,149,28,0);
	visual_frame(201,362,399,46,3);
	visual_text(180,200,440,50,3,28,27,"WARNING",7,3);
	visual_text(200,266,400,44,2,27,28,"This model has been modified and is unsaved",43,259);
	visual_text(200,318,400,40,2,27,28,"Do you want to save these modifications before exiting",54,259);
	visual_frame(210,300,380+2,20+2,5);
	visual_text(210+1,300+1,380,20,1,16,15,_Context->buffer_Auto283,47,3);
	visual_button(210,370,120,30,2,16,21,"&No Just Quit",13,0);
	visual_button(340,370,120,30,2,16,21,"&Abandon Exit",13,0);
	visual_button(470,370,120,30,2,16,21,"&Save then Exit",15,0);
	visual_thaw(160,160,480,280);

	return(0);
}
private int on_JustQuit_event() {
	return(13);
	return(-1);
}
private int on_AbandonExit_event() {
	return(27);
	return(-1);
}
private int on_SaveOnExit_event() {
	return('FS');
	return(-1);
}


private	int	accept_exit_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 619 )  
	&&  (my >= 164 )  
	&&  (mx <= 635 )  
	&&  (my <= 180 )) {
		return(1);	/* Auto273 */

		}
	if ((mx >= 603 )  
	&&  (my >= 164 )  
	&&  (mx <= 619 )  
	&&  (my <= 180 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vexit.htm");
			};
		return(-1);	/* Auto273 */

		}
	if (( mx >= 210 ) 
	&&  ( my >= 370 ) 
	&&  ( mx <= 330 ) 
	&&  ( my <= 400 )) {
		return(2); /* JustQuit */
		}
	if (( mx >= 340 ) 
	&&  ( my >= 370 ) 
	&&  ( mx <= 460 ) 
	&&  ( my <= 400 )) {
		return(3); /* AbandonExit */
		}
	if (( mx >= 470 ) 
	&&  ( my >= 370 ) 
	&&  ( mx <= 590 ) 
	&&  ( my <= 400 )) {
		return(4); /* SaveOnExit */
		}

	return(-1);
}


private	int	accept_exit_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* JustQuit */
				visual_button(210,370,120,30,2,16,21,"&No Just Quit",13,2);
				_Context->keycode = visual_getch();
				visual_button(210,370,120,30,2,16,21,"&No Just Quit",13,0);
				break;
			case	0x3 :
				/* AbandonExit */
				visual_button(340,370,120,30,2,16,21,"&Abandon Exit",13,2);
				_Context->keycode = visual_getch();
				visual_button(340,370,120,30,2,16,21,"&Abandon Exit",13,0);
				break;
			case	0x4 :
				/* SaveOnExit */
				visual_button(470,370,120,30,2,16,21,"&Save then Exit",15,2);
				_Context->keycode = visual_getch();
				visual_button(470,370,120,30,2,16,21,"&Save then Exit",15,0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_exit_show();
			continue;
		case	0x2 :
			_Context->focus_item=4;
			accept_exit_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_exit_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto273 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* JustQuit */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(210,370,120,30,2,16,21,"&No Just Quit",13,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(210,370,120,30,2,16,21,"&No Just Quit",13,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_JustQuit_event()) != -1) break;

							}
						continue;
					case	0x3 :
						/* AbandonExit */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(340,370,120,30,2,16,21,"&Abandon Exit",13,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(340,370,120,30,2,16,21,"&Abandon Exit",13,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_AbandonExit_event()) != -1) break;

							}
						continue;
					case	0x4 :
						/* SaveOnExit */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(470,370,120,30,2,16,21,"&Save then Exit",15,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(470,370,120,30,2,16,21,"&Save then Exit",15,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_SaveOnExit_event()) != -1) break;

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
				_Context->focus_item=4;
			}
			continue;
		case 0x84e : 
		case 0x86e : 
		/* JustQuit */
		visual_button(210,370,120,30,2,16,21,"&No Just Quit",13,8);
		visual_button(210,370,120,30,2,16,21,"&No Just Quit",13,0);
		_Context->focus_item=2;
		if ((_Context->keycode = on_JustQuit_event()) != -1) break;
		continue;
		case 0x841 : 
		case 0x861 : 
		/* AbandonExit */
		visual_button(340,370,120,30,2,16,21,"&Abandon Exit",13,8);
		visual_button(340,370,120,30,2,16,21,"&Abandon Exit",13,0);
		_Context->focus_item=3;
		if ((_Context->keycode = on_AbandonExit_event()) != -1) break;
		continue;
		case 0x853 : 
		case 0x873 : 
		/* SaveOnExit */
		visual_button(470,370,120,30,2,16,21,"&Save then Exit",15,8);
		visual_button(470,370,120,30,2,16,21,"&Save then Exit",15,0);
		_Context->focus_item=4;
		if ((_Context->keycode = on_SaveOnExit_event()) != -1) break;
		continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_exit(
	char * pAuto283)
{
	int	status=0;
	status = accept_exit_create(
	 pAuto283);
	if ( status != 0) return(status);
	status = accept_exit_show();
		enter_modal();
	status = accept_exit_focus();
		leave_modal();
	status = accept_exit_hide();
	status = accept_exit_remove(
	 pAuto283);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vexit_c */
