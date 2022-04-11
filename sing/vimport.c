
#ifndef _vimport_c
#define _vimport_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vimport.sng  */
/* Target         : vimport.c  */
/* Identification : 0.0-1065019114-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_font_import_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_CellWidth[8];
	char	buffer_CellHeight[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	} * _Context;

private	int	accept_font_import_create(
	char * pCellWidth,
	char * pCellHeight)
{

	if (!(_Context = allocate( sizeof( struct accept_font_import_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=6;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_CellWidth, 7, pCellWidth);
		visual_transferin(_Context->buffer_CellHeight, 7, pCellHeight);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(235,200,330+10,200+10);
	return(0);
}

private	int	accept_font_import_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,235,200);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_font_import_remove(
	char * pCellWidth,
	char * pCellHeight)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_CellWidth, 7, pCellWidth);
		visual_transferout(_Context->buffer_CellHeight, 7, pCellHeight);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_font_import_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,235,200);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(235,200,330,200,2,"Sing : Version 1.0a",19,0x403);
	visual_image(238,222,323,175,"skin.gif",4);
	visual_text(255,230,276,20,3,27,0,"Import Font from Image",22,1538);
	visual_text(255,280,72,20,2,27,0,"Cell Wdith",10,258);
	visual_text(405,280,72,20,2,27,0,"Cell Height",11,258);
	visual_frame(325,280,60+2,20+2,5);
	visual_text(325+1,280+1,60,20,1,26,0,_Context->buffer_CellWidth,7,0);
	visual_frame(475,280,60+2,20+2,5);
	visual_text(475+1,280+1,60,20,1,26,0,_Context->buffer_CellHeight,7,0);
	visual_button(255,350,84,32,2,26,0,"Automatic",9,0);
	visual_button(355,350,84,32,2,26,0,"&Prompted",9,0);
	visual_button(455,350,84,32,2,26,0,"&Cancel",7,0);
	visual_thaw(235,200,330,200);

	return(0);
}
private int on_Auto4868_event() {
	return(13);
	return(-1);
}
private int on_Prompted_event() {
	return(26);
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}


private	int	accept_font_import_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 544 )  
	&&  (my >= 204 )  
	&&  (mx <= 560 )  
	&&  (my <= 220 )) {
		return(1);	/* auto2 */

		}
	if ((mx >= 528 )  
	&&  (my >= 204 )  
	&&  (mx <= 544 )  
	&&  (my <= 220 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vimport.htm");
			};
		return(-1);	/* auto2 */

		}
	if (( mx >= 325 ) 
	&&  ( my >= 280 ) 
	&&  ( mx <= 385 ) 
	&&  ( my <= 300 )) {
		return(2); /* CellWidth */
		}
	if (( mx >= 475 ) 
	&&  ( my >= 280 ) 
	&&  ( mx <= 535 ) 
	&&  ( my <= 300 )) {
		return(3); /* CellHeight */
		}
	if (( mx >= 255 ) 
	&&  ( my >= 350 ) 
	&&  ( mx <= 339 ) 
	&&  ( my <= 382 )) {
		return(4); /* Auto4868 */
		}
	if (( mx >= 355 ) 
	&&  ( my >= 350 ) 
	&&  ( mx <= 439 ) 
	&&  ( my <= 382 )) {
		return(5); /* Prompted */
		}
	if (( mx >= 455 ) 
	&&  ( my >= 350 ) 
	&&  ( mx <= 539 ) 
	&&  ( my <= 382 )) {
		return(6); /* Cancel */
		}

	return(-1);
}


private	int	accept_font_import_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* CellWidth */
				_Context->keycode = visual_edit(325+1,280+1,60,20,1,_Context->buffer_CellWidth,7);
				break;
			case	0x3 :
				/* CellHeight */
				_Context->keycode = visual_edit(475+1,280+1,60,20,1,_Context->buffer_CellHeight,7);
				break;
			case	0x4 :
				/* Auto4868 */
				visual_button(255,350,84,32,2,26,0,"Automatic",9,2);
				_Context->keycode = visual_getch();
				visual_button(255,350,84,32,2,26,0,"Automatic",9,0);
				break;
			case	0x5 :
				/* Prompted */
				visual_button(355,350,84,32,2,26,0,"&Prompted",9,2);
				_Context->keycode = visual_getch();
				visual_button(355,350,84,32,2,26,0,"&Prompted",9,0);
				break;
			case	0x6 :
				/* Cancel */
				visual_button(455,350,84,32,2,26,0,"&Cancel",7,2);
				_Context->keycode = visual_getch();
				visual_button(455,350,84,32,2,26,0,"&Cancel",7,0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_font_import_show();
			continue;
		case	0x2 :
			_Context->focus_item=6;
			accept_font_import_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_font_import_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto2 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* CellWidth */
						continue;
					case	0x3 :
						/* CellHeight */
						continue;
					case	0x4 :
						/* Auto4868 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(255,350,84,32,2,26,0,"Automatic",9,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(255,350,84,32,2,26,0,"Automatic",9,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto4868_event()) != -1) break;

							}
						continue;
					case	0x5 :
						/* Prompted */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(355,350,84,32,2,26,0,"&Prompted",9,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(355,350,84,32,2,26,0,"&Prompted",9,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Prompted_event()) != -1) break;

							}
						continue;
					case	0x6 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(455,350,84,32,2,26,0,"&Cancel",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(455,350,84,32,2,26,0,"&Cancel",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
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
		case 0x850 : 
		case 0x870 : 
		/* Prompted */
		visual_button(355,350,84,32,2,26,0,"&Prompted",9,8);
		visual_button(355,350,84,32,2,26,0,"&Prompted",9,0);
		_Context->focus_item=5;
		if ((_Context->keycode = on_Prompted_event()) != -1) break;
		continue;
		case 0x843 : 
		case 0x863 : 
		/* Cancel */
		visual_button(455,350,84,32,2,26,0,"&Cancel",7,8);
		visual_button(455,350,84,32,2,26,0,"&Cancel",7,0);
		_Context->focus_item=6;
		if ((_Context->keycode = on_Cancel_event()) != -1) break;
		continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_font_import(
	char * pCellWidth,
	char * pCellHeight)
{
	int	status=0;
	status = accept_font_import_create(
	 pCellWidth,
	 pCellHeight);
	if ( status != 0) return(status);
	status = accept_font_import_show();
		enter_modal();
	status = accept_font_import_focus();
		leave_modal();
	status = accept_font_import_hide();
	status = accept_font_import_remove(
	 pCellWidth,
	 pCellHeight);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vimport_c */
