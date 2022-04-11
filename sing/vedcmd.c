
#ifndef _vedcmd_c
#define _vedcmd_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.01  */
/* Production     : C  */
/* Project        : vedcmd.sng  */
/* Target         : vedcmd.c  */
/* Identification : 0.0-1057622498-2176.2175 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_editor_command_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_Auto4873[65];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	} * _Context;

private	int	accept_editor_command_create( char * pAuto4873)
{

	if (!(_Context = allocate( sizeof( struct accept_editor_command_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=4;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Auto4873, 64, pAuto4873);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(125,230,550+10,140+10);
	return(0);
}

private	int	accept_editor_command_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,125,230);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_editor_command_remove( char * pAuto4873)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Auto4873, 64, pAuto4873);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_editor_command_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,125,230);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(125,230,550,140,2,"Sing : Version 1.0a",19,0x403);
	visual_text(135,260,530,20,3,27,0,"Editor Command",14,1026);
	visual_frame(135,280,530,40,4);
	visual_frame(145,290,512+2,16+2,5);
	visual_text(145+1,290+1,512,16,1,27,0,_Context->buffer_Auto4873,64,0);
	visual_button(135,330,100,32,2,27,0,"&Accept",7,0);
	visual_button(565,330,100,32,2,27,0,"&Cancel",7,0);
	visual_thaw(125,230,550,140);

	return(0);
}
private int on_Auto4728_event() {
	return(13);
	return(-1);
}
private int on_Auto4729_event() {
	return(27);
	return(-1);
}


private	int	accept_editor_command_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 654 )  
	&&  (my >= 234 )  
	&&  (mx <= 670 )  
	&&  (my <= 250 )) {
		return(1);	/* Auto4724 */

		}
	if ((mx >= 638 )  
	&&  (my >= 234 )  
	&&  (mx <= 654 )  
	&&  (my <= 250 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vedcmd.htm");
			};
		return(-1);	/* Auto4724 */

		}
	if (( mx >= 145 ) 
	&&  ( my >= 290 ) 
	&&  ( mx <= 657 ) 
	&&  ( my <= 306 )) {
		return(2); /* Auto4873 */
		}
	if (( mx >= 135 ) 
	&&  ( my >= 330 ) 
	&&  ( mx <= 235 ) 
	&&  ( my <= 362 )) {
		return(3); /* Auto4728 */
		}
	if (( mx >= 565 ) 
	&&  ( my >= 330 ) 
	&&  ( mx <= 665 ) 
	&&  ( my <= 362 )) {
		return(4); /* Auto4729 */
		}

	return(-1);
}


private	int	accept_editor_command_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto4873 */
				_Context->keycode = visual_edit(145+1,290+1,512,16,1,_Context->buffer_Auto4873,64);
				break;
			case	0x3 :
				/* Auto4728 */
				visual_button(135,330,100,32,2,27,0,"&Accept",7,2);
				_Context->keycode = visual_getch();
				visual_button(135,330,100,32,2,27,0,"&Accept",7,0);
				break;
			case	0x4 :
				/* Auto4729 */
				visual_button(565,330,100,32,2,27,0,"&Cancel",7,2);
				_Context->keycode = visual_getch();
				visual_button(565,330,100,32,2,27,0,"&Cancel",7,0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_editor_command_show();
			continue;
		case	0x2 :
			_Context->focus_item=4;
			accept_editor_command_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_editor_command_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto4724 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Auto4873 */
						continue;
					case	0x3 :
						/* Auto4728 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(135,330,100,32,2,27,0,"&Accept",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(135,330,100,32,2,27,0,"&Accept",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto4728_event()) != -1) break;

							}
						continue;
					case	0x4 :
						/* Auto4729 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(565,330,100,32,2,27,0,"&Cancel",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(565,330,100,32,2,27,0,"&Cancel",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto4729_event()) != -1) break;

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
		case 0x841 : 
		case 0x861 : 
		/* Auto4728 */
		visual_button(135,330,100,32,2,27,0,"&Accept",7,8);
		visual_button(135,330,100,32,2,27,0,"&Accept",7,0);
		_Context->focus_item=3;
		if ((_Context->keycode = on_Auto4728_event()) != -1) break;
		continue;
		case 0x843 : 
		case 0x863 : 
		/* Auto4729 */
		visual_button(565,330,100,32,2,27,0,"&Cancel",7,8);
		visual_button(565,330,100,32,2,27,0,"&Cancel",7,0);
		_Context->focus_item=4;
		if ((_Context->keycode = on_Auto4729_event()) != -1) break;
		continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_editor_command( char * pAuto4873)
{
	int	status=0;
	status = accept_editor_command_create(  pAuto4873);
	if ( status != 0) return(status);
	status = accept_editor_command_show();
		enter_modal();
	status = accept_editor_command_focus();
		leave_modal();
	status = accept_editor_command_hide();
	status = accept_editor_command_remove(  pAuto4873);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vedcmd_c */
