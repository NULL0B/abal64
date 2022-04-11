
#ifndef _vtexport_c
#define _vtexport_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vtexport.sng  */
/* Target         : vtexport.c  */
/* Identification : 0.0-1065019114-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct text_export_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_FileName[72];
	char	signature[2];
	} * _Context;

private	int	text_export_create(
	char * pFileName)
{

	if (!(_Context = allocate( sizeof( struct text_export_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=6;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 71, pFileName);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	return(0);
}

private	int	text_export_hide()
{

	return(0);
}

private	int	text_export_remove(
	char * pFileName)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 71, pFileName);
		}
	_Context=liberate(_Context);

	return(result);
}

private	int	text_export_show()
{
	visual_freeze();
	visual_window(95,210,610,180,2,"Sing : Version 1.0a",19,0x0);
	visual_image(99,232,602,154,"skin.gif",4);
	visual_button(235,330,100,30,2,26,0,"Edit",4,0);
	visual_button(465,330,100,30,2,27,24,"Select",6,0);
	visual_text(115,260,560,16,2,38,0,"Name of Text File to Export",27,258);
	visual_frame(115,280,570+2,20+2,5);
	visual_text(115+1,280+1,570,20,1,16,24,_Context->buffer_FileName,71,0);
	visual_button(115,330,110,30,2,34,0,"Accept",6,0);
	visual_button(575,330,110,30,2,34,0,"Cancel",6,0);
	visual_text(377,322,48,44,8,27,24,"abcdefghijklmnopqrstuvwxyzabcdefghijklmnop",42,0);
	visual_thaw(95,210,610,180);

	return(0);
}
private int on_UseEdit_event() {
	use_editor(_Context->buffer_FileName);
	text_export_show();
	return(-1);
}
private int on_Auto740_event() {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_ANY);
	text_export_show();
	return(-1);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}


private	int	text_export_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 235 ) 
	&&  ( my >= 330 ) 
	&&  ( mx <= 335 ) 
	&&  ( my <= 360 )) {
		return(2); /* UseEdit */
		}
	if (( mx >= 465 ) 
	&&  ( my >= 330 ) 
	&&  ( mx <= 565 ) 
	&&  ( my <= 360 )) {
		return(3); /* Auto740 */
		}
	if (( mx >= 115 ) 
	&&  ( my >= 280 ) 
	&&  ( mx <= 685 ) 
	&&  ( my <= 300 )) {
		return(4); /* FileName */
		}
	if (( mx >= 115 ) 
	&&  ( my >= 330 ) 
	&&  ( mx <= 225 ) 
	&&  ( my <= 360 )) {
		return(5); /* Accept */
		}
	if (( mx >= 575 ) 
	&&  ( my >= 330 ) 
	&&  ( mx <= 685 ) 
	&&  ( my <= 360 )) {
		return(6); /* Cancel */
		}

	return(-1);
}


private	int	text_export_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* UseEdit */
				visual_button(235,330,100,30,2,26,0,"Edit",4,2);
				_Context->keycode = visual_getch();
				visual_button(235,330,100,30,2,26,0,"Edit",4,0);
				break;
			case	0x3 :
				/* Auto740 */
				visual_button(465,330,100,30,2,27,24,"Select",6,2);
				_Context->keycode = visual_getch();
				visual_button(465,330,100,30,2,27,24,"Select",6,0);
				break;
			case	0x4 :
				/* FileName */
				_Context->keycode = visual_edit(115+1,280+1,570,20,1,_Context->buffer_FileName,71);
				break;
			case	0x5 :
				/* Accept */
				visual_button(115,330,110,30,2,34,0,"Accept",6,2);
				_Context->keycode = visual_getch();
				visual_button(115,330,110,30,2,34,0,"Accept",6,0);
				break;
			case	0x6 :
				/* Cancel */
				visual_button(575,330,110,30,2,34,0,"Cancel",6,2);
				_Context->keycode = visual_getch();
				visual_button(575,330,110,30,2,34,0,"Cancel",6,0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			text_export_show();
			continue;
		case	0x2 :
			_Context->focus_item=6;
			text_export_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=text_export_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto6 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* UseEdit */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(235,330,100,30,2,26,0,"Edit",4,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(235,330,100,30,2,26,0,"Edit",4,0);
							}
						if ( visual_event(1) &  0xc7b8 ) {
						if ((_Context->keycode = on_UseEdit_event()) != -1) break;

							}
						continue;
					case	0x3 :
						/* Auto740 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(465,330,100,30,2,27,24,"Select",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(465,330,100,30,2,27,24,"Select",6,0);
							}
						if ( visual_event(1) &  0x3366 ) {
						if ((_Context->keycode = on_Auto740_event()) != -1) break;

							}
						continue;
					case	0x4 :
						/* FileName */
						continue;
					case	0x5 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(115,330,110,30,2,34,0,"Accept",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(115,330,110,30,2,34,0,"Accept",6,0);
							}
						if ( visual_event(1) &  0x2067 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x6 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(575,330,110,30,2,34,0,"Cancel",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(575,330,110,30,2,34,0,"Cancel",6,0);
							}
						if ( visual_event(1) &  0x2020 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

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

public	int	text_export(
	char * pFileName)
{
	int	status=0;
	status = text_export_create(
	 pFileName);
	if ( status != 0) return(status);
	status = text_export_show();
		enter_modal();
	status = text_export_focus();
		leave_modal();
	status = text_export_hide();
	status = text_export_remove(
	 pFileName);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vtexport_c */
