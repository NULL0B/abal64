
#ifndef _vheader_c
#define _vheader_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vheader.sng  */
/* Target         : vheader.c  */
/* Identification : 0.0-1065019114-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct class_header_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_Auto663[16];
	char	signature[2];
	} * _Context;

private	int	class_header_create(
	char * pAuto663)
{

	if (!(_Context = allocate( sizeof( struct class_header_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=2;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Auto663, 15, pAuto663);
		}
	_Context->window_col=53;
	_Context->window_row=34;
	return(0);
}

private	int	class_header_hide()
{

	return(0);
}

private	int	class_header_remove(
	char * pAuto663)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Auto663, 15, pAuto663);
		}
	_Context=liberate(_Context);

	return(result);
}

private	int	class_header_show()
{
	visual_freeze();
	visual_window(53,34,440,180,2,"Sing : Version 1.0a : Class Header",34,0x0);
	visual_frame(60,62,424,143,3);
	visual_image(63,64,420,140,"paper.gif",0);
	visual_text(83,104,170,30,4,27,0,"Class    ",9,0);
	visual_image(413,84,50,50,"fileicon.gif",0);
	visual_frame(83,144,378+2,24+2,5);
	visual_text(83+1,144+1,378,24,4,27,0,_Context->buffer_Auto663,15,0);
	visual_thaw(53,34,440,180);

	return(0);
}


private	int	class_header_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 83 ) 
	&&  ( my >= 144 ) 
	&&  ( mx <= 461 ) 
	&&  ( my <= 168 )) {
		return(2); /* Auto663 */
		}

	return(-1);
}
private int on_Auto663_getfocus() {
	return(27);
	return(-1);
}


private	int	class_header_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto663 */
				if ((_Context->keycode = on_Auto663_getfocus()) != -1) break;
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			class_header_show();
			continue;
		case	0x2 :
			_Context->focus_item=2;
			class_header_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=class_header_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto661 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Auto663 */
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

public	int	class_header(
	char * pAuto663)
{
	int	status=0;
	status = class_header_create(
	 pAuto663);
	if ( status != 0) return(status);
	status = class_header_show();
		enter_modal();
	status = class_header_focus();
		leave_modal();
	status = class_header_hide();
	status = class_header_remove(
	 pAuto663);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vheader_c */
