
#ifndef _vfload_c
#define _vfload_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vfload.sng  */
/* Target         : vfload.c  */
/* Identification : 0.0-1065019113-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_fontload_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_FileName[71];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	} * _Context;

private	int	accept_fontload_create(
	char * pFileName)
{

	if (!(_Context = allocate( sizeof( struct accept_fontload_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=5;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 70, pFileName);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(105,215,590+10,170+10);
	return(0);
}

private	int	accept_fontload_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,105,215);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_fontload_remove(
	char * pFileName)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 70, pFileName);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_fontload_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,105,215);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(105,215,590,170,2,"Sing : Version 1.0a",19,0x403);
	visual_image(108,236,583,144,"skin.gif",4);
	visual_text(125,255,560,16,2,38,0,"Name of Font to Load",20,256);
	visual_frame(125,275,560+2,16+2,5);
	visual_text(125+1,275+1,560,16,1,16,24,_Context->buffer_FileName,70,0);
	visual_button(125,335,110,30,2,34,0,"&Accept",7,0);
	visual_button(575,335,110,30,2,34,0,"&Cancel",7,0);
	visual_button(465,335,100,30,2,27,24,"&Select",7,0);
	visual_image(335,335,30,30,"texticon.gif",0);
	visual_thaw(105,215,590,170);

	return(0);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}
private int on_Select_event() {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_FMF);
	accept_fontload_show();
	return(-1);
}


private	int	accept_fontload_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x1031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 674 )  
	&&  (my >= 219 )  
	&&  (mx <= 690 )  
	&&  (my <= 235 )) {
		return(1);	/* auto6 */

		}
	if ((mx >= 658 )  
	&&  (my >= 219 )  
	&&  (mx <= 674 )  
	&&  (my <= 235 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vfload.htm");
			};
		return(-1);	/* auto6 */

		}
	if (( mx >= 125 ) 
	&&  ( my >= 275 ) 
	&&  ( mx <= 685 ) 
	&&  ( my <= 291 )) {
		return(2); /* FileName */
		}
	if (( mx >= 125 ) 
	&&  ( my >= 335 ) 
	&&  ( mx <= 235 ) 
	&&  ( my <= 365 )) {
		return(3); /* Accept */
		}
	if (( mx >= 575 ) 
	&&  ( my >= 335 ) 
	&&  ( mx <= 685 ) 
	&&  ( my <= 365 )) {
		return(4); /* Cancel */
		}
	if (( mx >= 465 ) 
	&&  ( my >= 335 ) 
	&&  ( mx <= 565 ) 
	&&  ( my <= 365 )) {
		return(5); /* Select */
		}

	return(-1);
}


private	int	accept_fontload_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(125+1,275+1,560,16,1,_Context->buffer_FileName,70);
				break;
			case	0x3 :
				/* Accept */
				visual_button(125,335,110,30,2,34,0,"&Accept",7,2);
				_Context->keycode = visual_getch();
				visual_button(125,335,110,30,2,34,0,"&Accept",7,0);
				break;
			case	0x4 :
				/* Cancel */
				visual_button(575,335,110,30,2,34,0,"&Cancel",7,2);
				_Context->keycode = visual_getch();
				visual_button(575,335,110,30,2,34,0,"&Cancel",7,0);
				break;
			case	0x5 :
				/* Select */
				visual_button(465,335,100,30,2,27,24,"&Select",7,2);
				_Context->keycode = visual_getch();
				visual_button(465,335,100,30,2,27,24,"&Select",7,0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_fontload_show();
			continue;
		case	0x2 :
			_Context->focus_item=5;
			accept_fontload_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_fontload_event()) == -1)
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
						/* FileName */
						continue;
					case	0x3 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(125,335,110,30,2,34,0,"&Accept",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(125,335,110,30,2,34,0,"&Accept",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x4 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(575,335,110,30,2,34,0,"&Cancel",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(575,335,110,30,2,34,0,"&Cancel",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

							}
						continue;
					case	0x5 :
						/* Select */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(465,335,100,30,2,27,24,"&Select",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(465,335,100,30,2,27,24,"&Select",7,0);
							}
						if ( visual_event(1) &  0x6c65 ) {
						if ((_Context->keycode = on_Select_event()) != -1) break;

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
		visual_button(125,335,110,30,2,34,0,"&Accept",7,8);
		visual_button(125,335,110,30,2,34,0,"&Accept",7,0);
		_Context->focus_item=3;
		if ((_Context->keycode = on_Accept_event()) != -1) break;
		continue;
		case 0x843 : 
		case 0x863 : 
		/* Cancel */
		visual_button(575,335,110,30,2,34,0,"&Cancel",7,8);
		visual_button(575,335,110,30,2,34,0,"&Cancel",7,0);
		_Context->focus_item=4;
		if ((_Context->keycode = on_Cancel_event()) != -1) break;
		continue;
		case 0x853 : 
		case 0x873 : 
		/* Select */
		visual_button(465,335,100,30,2,27,24,"&Select",7,8);
		visual_button(465,335,100,30,2,27,24,"&Select",7,0);
		_Context->focus_item=5;
		if ((_Context->keycode = on_Select_event()) != -1) break;
		continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_fontload(
	char * pFileName)
{
	int	status=0;
	status = accept_fontload_create(
	 pFileName);
	if ( status != 0) return(status);
	status = accept_fontload_show();
		enter_modal();
	status = accept_fontload_focus();
		leave_modal();
	status = accept_fontload_hide();
	status = accept_fontload_remove(
	 pFileName);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vfload_c */
