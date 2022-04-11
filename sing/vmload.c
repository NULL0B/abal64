
#ifndef _vmload_c
#define _vmload_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vmload.sng  */
/* Target         : vmload.c  */
/* Identification : 0.0-1065019114-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_modelfilename_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_FileName[70];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	} * _Context;

private	int	accept_modelfilename_create(
	char * pFileName)
{

	if (!(_Context = allocate( sizeof( struct accept_modelfilename_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=5;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 69, pFileName);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(105,195,590+10,210+10);
	return(0);
}

private	int	accept_modelfilename_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,105,195);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_modelfilename_remove(
	char * pFileName)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 69, pFileName);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_modelfilename_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,105,195);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(105,195,590,210,2,"Sing : Version 1.0a",19,0x403);
	visual_image(108,217,582,184,"skin.gif",4);
	visual_text(125,245,546,16,2,27,0,"Name of Application to Load",27,258);
	visual_frame(125,265,552+2,16+2,5);
	visual_text(125+1,265+1,552,16,1,26,0,_Context->buffer_FileName,69,0);
	visual_button(125,355,110,30,2,26,0,"&Accept",7,0);
	visual_button(456,355,100,30,2,27,24,"&Select",7,0);
	visual_image(327,335,50,50,"fileicon.gif",0);
	visual_button(565,355,110,30,2,26,0,"&Cancel",7,0);
	visual_thaw(105,195,590,210);

	return(0);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Select_event() {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_3D);
	accept_modelfilename_show();
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}


private	int	accept_modelfilename_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 674 )  
	&&  (my >= 199 )  
	&&  (mx <= 690 )  
	&&  (my <= 215 )) {
		return(1);	/* auto703 */

		}
	if ((mx >= 658 )  
	&&  (my >= 199 )  
	&&  (mx <= 674 )  
	&&  (my <= 215 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vmload.htm");
			};
		return(-1);	/* auto703 */

		}
	if (( mx >= 125 ) 
	&&  ( my >= 265 ) 
	&&  ( mx <= 677 ) 
	&&  ( my <= 281 )) {
		return(2); /* FileName */
		}
	if (( mx >= 125 ) 
	&&  ( my >= 355 ) 
	&&  ( mx <= 235 ) 
	&&  ( my <= 385 )) {
		return(3); /* Accept */
		}
	if (( mx >= 456 ) 
	&&  ( my >= 355 ) 
	&&  ( mx <= 556 ) 
	&&  ( my <= 385 )) {
		return(4); /* Select */
		}
	if (( mx >= 565 ) 
	&&  ( my >= 355 ) 
	&&  ( mx <= 675 ) 
	&&  ( my <= 385 )) {
		return(5); /* Cancel */
		}

	return(-1);
}


private	int	accept_modelfilename_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(125+1,265+1,552,16,1,_Context->buffer_FileName,69);
				break;
			case	0x3 :
				/* Accept */
				visual_button(125,355,110,30,2,26,0,"&Accept",7,2);
				_Context->keycode = visual_getch();
				visual_button(125,355,110,30,2,26,0,"&Accept",7,0);
				break;
			case	0x4 :
				/* Select */
				visual_button(456,355,100,30,2,27,24,"&Select",7,2);
				_Context->keycode = visual_getch();
				visual_button(456,355,100,30,2,27,24,"&Select",7,0);
				break;
			case	0x5 :
				/* Cancel */
				visual_button(565,355,110,30,2,26,0,"&Cancel",7,2);
				_Context->keycode = visual_getch();
				visual_button(565,355,110,30,2,26,0,"&Cancel",7,0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_modelfilename_show();
			continue;
		case	0x2 :
			_Context->focus_item=5;
			accept_modelfilename_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_modelfilename_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto703 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* FileName */
						continue;
					case	0x3 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(125,355,110,30,2,26,0,"&Accept",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(125,355,110,30,2,26,0,"&Accept",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x4 :
						/* Select */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(456,355,100,30,2,27,24,"&Select",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(456,355,100,30,2,27,24,"&Select",7,0);
							}
						if ( visual_event(1) &  0x2020 ) {
						if ((_Context->keycode = on_Select_event()) != -1) break;

							}
						continue;
					case	0x5 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(565,355,110,30,2,26,0,"&Cancel",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(565,355,110,30,2,26,0,"&Cancel",7,0);
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
				_Context->focus_item=5;
			}
			continue;
		case 0x841 : 
		case 0x861 : 
		/* Accept */
		visual_button(125,355,110,30,2,26,0,"&Accept",7,8);
		visual_button(125,355,110,30,2,26,0,"&Accept",7,0);
		_Context->focus_item=3;
		if ((_Context->keycode = on_Accept_event()) != -1) break;
		continue;
		case 0x853 : 
		case 0x873 : 
		/* Select */
		visual_button(456,355,100,30,2,27,24,"&Select",7,8);
		visual_button(456,355,100,30,2,27,24,"&Select",7,0);
		_Context->focus_item=4;
		if ((_Context->keycode = on_Select_event()) != -1) break;
		continue;
		case 0x843 : 
		case 0x863 : 
		/* Cancel */
		visual_button(565,355,110,30,2,26,0,"&Cancel",7,8);
		visual_button(565,355,110,30,2,26,0,"&Cancel",7,0);
		_Context->focus_item=5;
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

public	int	accept_modelfilename(
	char * pFileName)
{
	int	status=0;
	status = accept_modelfilename_create(
	 pFileName);
	if ( status != 0) return(status);
	status = accept_modelfilename_show();
		enter_modal();
	status = accept_modelfilename_focus();
		leave_modal();
	status = accept_modelfilename_hide();
	status = accept_modelfilename_remove(
	 pFileName);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vmload_c */
