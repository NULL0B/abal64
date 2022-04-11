
#ifndef _visave_c
#define _visave_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : visave.sng  */
/* Target         : visave.c  */
/* Identification : 0.0-1065019113-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_imagesave_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_FileName[71];
	int	value_PathSelection;
	int	value_ImageFormat;
	int	value_IsTransparent;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[5];
	} * _Context;

private	int	accept_imagesave_create(
	char * pFileName,
	char * pPathSelection,
	char * pImageFormat,
	char * pIsTransparent)
{

	if (!(_Context = allocate( sizeof( struct accept_imagesave_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=8;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 70, pFileName);
		visual_transferin((void *) 0, 0, pPathSelection);
		if (!( pPathSelection )) _Context->value_PathSelection=0;
		else	_Context->value_PathSelection = *((int *)pPathSelection);
		visual_transferin((void *) 0, 0, pImageFormat);
		if (!( pImageFormat )) _Context->value_ImageFormat=0;
		else	_Context->value_ImageFormat = *((int *)pImageFormat);
		visual_transferin((void *) 0, 0, pIsTransparent);
		if (!( pIsTransparent )) _Context->value_IsTransparent=0;
		else	_Context->value_IsTransparent = *((int *)pIsTransparent);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(100,195,600+10,210+10);
	return(0);
}

private	int	accept_imagesave_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,100,195);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_imagesave_remove(
	char * pFileName,
	char * pPathSelection,
	char * pImageFormat,
	char * pIsTransparent)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 70, pFileName);
		visual_transferout((void *) 0, 0, pPathSelection);
		if ( pPathSelection != (char *) 0)
			*((int*)pPathSelection) = _Context->value_PathSelection;
		visual_transferout((void *) 0, 0, pImageFormat);
		if ( pImageFormat != (char *) 0)
			*((int*)pImageFormat) = _Context->value_ImageFormat;
		visual_transferout((void *) 0, 0, pIsTransparent);
		if ( pIsTransparent != (char *) 0)
			*((int*)pIsTransparent) = _Context->value_IsTransparent;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_imagesave_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,100,195);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(100,195,600,210,2,"Sing : Version 1.0a",19,0x403);
	visual_image(103,216,594,184,"skin.gif",4);
	visual_image(330,335,50,50,"imgicon.gif",0);
	visual_text(120,225,560,16,2,27,0,"Name of Image to Save",21,258);
	visual_text(120,305,100,20,2,27,0,"File Format",11,258);
	visual_frame(120,245,560+2,16+2,5);
	visual_text(120+1,245+1,560,16,1,16,24,_Context->buffer_FileName,70,0);
	visual_select(120,265,560,80,1,0,0,parse_selection(GetPathSelection(),&_Context->value_PathSelection),768);
	visual_select(270,305,108,58,1,0,0,parse_selection("Bmp|Gif|Jpeg",&_Context->value_ImageFormat),0);
	visual_check(460,305,140,16,2,27,0,"&Transparent",12,_Context->value_IsTransparent|0);
	visual_button(120,345,120,30,2,34,0,"&Accept",7,0);
	visual_button(460,345,100,30,2,27,24,"&Select",7,0);
	visual_button(570,345,110,30,2,34,0,"&Cancel",7,0);
	visual_thaw(100,195,600,210);

	return(0);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Select_event() {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_GIF);
	accept_imagesave_show();
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}


private	int	accept_imagesave_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 679 )  
	&&  (my >= 199 )  
	&&  (mx <= 695 )  
	&&  (my <= 215 )) {
		return(1);	/* auto6 */

		}
	if ((mx >= 663 )  
	&&  (my >= 199 )  
	&&  (mx <= 679 )  
	&&  (my <= 215 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("visave.htm");
			};
		return(-1);	/* auto6 */

		}
	if (( mx >= 120 ) 
	&&  ( my >= 245 ) 
	&&  ( mx <= 680 ) 
	&&  ( my <= 261 )) {
		return(2); /* FileName */
		}
	if ((mx >= 120 ) 
	&&  (my >= 265 ) 
	&&  (mx <= 680 ) 
	&&  (my <= 281 )) {
		return(3); /* PathSelection */
		}
	if ((mx >= 270 ) 
	&&  (my >= 305 ) 
	&&  (mx <= 378 ) 
	&&  (my <= 321 )) {
		return(4); /* ImageFormat */
		}
	if (( mx >= 460 ) 
	&&  ( my >= 305 ) 
	&&  ( mx <= 600 ) 
	&&  ( my <= 321 )) {
		return(5); /* IsTransparent */
		}
	if (( mx >= 120 ) 
	&&  ( my >= 345 ) 
	&&  ( mx <= 240 ) 
	&&  ( my <= 375 )) {
		return(6); /* Accept */
		}
	if (( mx >= 460 ) 
	&&  ( my >= 345 ) 
	&&  ( mx <= 560 ) 
	&&  ( my <= 375 )) {
		return(7); /* Select */
		}
	if (( mx >= 570 ) 
	&&  ( my >= 345 ) 
	&&  ( mx <= 680 ) 
	&&  ( my <= 375 )) {
		return(8); /* Cancel */
		}

	return(-1);
}


private	int	accept_imagesave_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(120+1,245+1,560,16,1,_Context->buffer_FileName,70);
				break;
			case	0x3 :
				/* PathSelection */
				_Context->keycode = visual_select(120,265,560,80,1,0,0,parse_selection(GetPathSelection(),&_Context->value_PathSelection),770);
				break;
			case	0x4 :
				/* ImageFormat */
				_Context->keycode = visual_select(270,305,108,58,1,0,0,parse_selection("Bmp|Gif|Jpeg",&_Context->value_ImageFormat),2);
				break;
			case	0x5 :
				/* IsTransparent */
				visual_check(460,305,140,16,2,27,0,"&Transparent",12,(_Context->value_IsTransparent |2));
				_Context->keycode = visual_getch();
				visual_check(460,305,140,16,2,27,0,"&Transparent",12,(_Context->value_IsTransparent |0));
				break;
			case	0x6 :
				/* Accept */
				visual_button(120,345,120,30,2,34,0,"&Accept",7,2);
				_Context->keycode = visual_getch();
				visual_button(120,345,120,30,2,34,0,"&Accept",7,0);
				break;
			case	0x7 :
				/* Select */
				visual_button(460,345,100,30,2,27,24,"&Select",7,2);
				_Context->keycode = visual_getch();
				visual_button(460,345,100,30,2,27,24,"&Select",7,0);
				break;
			case	0x8 :
				/* Cancel */
				visual_button(570,345,110,30,2,34,0,"&Cancel",7,2);
				_Context->keycode = visual_getch();
				visual_button(570,345,110,30,2,34,0,"&Cancel",7,0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_imagesave_show();
			continue;
		case	0x2 :
			_Context->focus_item=8;
			accept_imagesave_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_imagesave_event()) == -1)
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
						/* PathSelection */
						continue;
					case	0x4 :
						/* ImageFormat */
						continue;
					case	0x5 :
						/* IsTransparent */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsTransparent += 1;
							_Context->value_IsTransparent &= 1;
							}
						continue;
					case	0x6 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(120,345,120,30,2,34,0,"&Accept",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(120,345,120,30,2,34,0,"&Accept",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x7 :
						/* Select */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(460,345,100,30,2,27,24,"&Select",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(460,345,100,30,2,27,24,"&Select",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Select_event()) != -1) break;

							}
						continue;
					case	0x8 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(570,345,110,30,2,34,0,"&Cancel",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(570,345,110,30,2,34,0,"&Cancel",7,0);
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
				_Context->focus_item=8;
			}
			continue;
		case 0x854 : 
		case 0x874 : 
		/* IsTransparent */
		_Context->value_IsTransparent += 1;
		_Context->value_IsTransparent &= 1;
		_Context->focus_item=5;
		continue;
		case 0x841 : 
		case 0x861 : 
		/* Accept */
		visual_button(120,345,120,30,2,34,0,"&Accept",7,8);
		visual_button(120,345,120,30,2,34,0,"&Accept",7,0);
		_Context->focus_item=6;
		if ((_Context->keycode = on_Accept_event()) != -1) break;
		continue;
		case 0x853 : 
		case 0x873 : 
		/* Select */
		visual_button(460,345,100,30,2,27,24,"&Select",7,8);
		visual_button(460,345,100,30,2,27,24,"&Select",7,0);
		_Context->focus_item=7;
		if ((_Context->keycode = on_Select_event()) != -1) break;
		continue;
		case 0x843 : 
		case 0x863 : 
		/* Cancel */
		visual_button(570,345,110,30,2,34,0,"&Cancel",7,8);
		visual_button(570,345,110,30,2,34,0,"&Cancel",7,0);
		_Context->focus_item=8;
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

public	int	accept_imagesave(
	char * pFileName,
	char * pPathSelection,
	char * pImageFormat,
	char * pIsTransparent)
{
	int	status=0;
	status = accept_imagesave_create(
	 pFileName,
	 pPathSelection,
	 pImageFormat,
	 pIsTransparent);
	if ( status != 0) return(status);
	status = accept_imagesave_show();
		enter_modal();
	status = accept_imagesave_focus();
		leave_modal();
	status = accept_imagesave_hide();
	status = accept_imagesave_remove(
	 pFileName,
	 pPathSelection,
	 pImageFormat,
	 pIsTransparent);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _visave_c */
