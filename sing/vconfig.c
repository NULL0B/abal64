
#ifndef _vconfig_c
#define _vconfig_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vconfig.sng  */
/* Target         : vconfig.c  */
/* Identification : 0.0-1065019114-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_configuration_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_FontPath[38];
	char	buffer_ImagePath[38];
	char	buffer_Palette[38];
	char	buffer_BaseFont[38];
	char	buffer_BiosMode[38];
	char	buffer_SingSkin[38];
	char	buffer_FileName[38];
	int	value_Update;
	char	signature[9];
	} * _Context;

private	int	accept_configuration_create(
	char * pFontPath,
	char * pImagePath,
	char * pPalette,
	char * pBaseFont,
	char * pBiosMode,
	char * pSingSkin,
	char * pFileName,
	char * pUpdate)
{

	if (!(_Context = allocate( sizeof( struct accept_configuration_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=4;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"KKKKKKKW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FontPath, 37, pFontPath);
		visual_transferin(_Context->buffer_ImagePath, 37, pImagePath);
		visual_transferin(_Context->buffer_Palette, 37, pPalette);
		visual_transferin(_Context->buffer_BaseFont, 37, pBaseFont);
		visual_transferin(_Context->buffer_BiosMode, 37, pBiosMode);
		visual_transferin(_Context->buffer_SingSkin, 37, pSingSkin);
		visual_transferin(_Context->buffer_FileName, 37, pFileName);
		visual_transferin((void *) 0, 0, pUpdate);
		if (!( pUpdate )) _Context->value_Update=0;
		else	_Context->value_Update = *((int *)pUpdate);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	return(0);
}

private	int	accept_configuration_hide()
{

	return(0);
}

private	int	accept_configuration_remove(
	char * pFontPath,
	char * pImagePath,
	char * pPalette,
	char * pBaseFont,
	char * pBiosMode,
	char * pSingSkin,
	char * pFileName,
	char * pUpdate)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"KKKKKKKW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FontPath, 37, pFontPath);
		visual_transferout(_Context->buffer_ImagePath, 37, pImagePath);
		visual_transferout(_Context->buffer_Palette, 37, pPalette);
		visual_transferout(_Context->buffer_BaseFont, 37, pBaseFont);
		visual_transferout(_Context->buffer_BiosMode, 37, pBiosMode);
		visual_transferout(_Context->buffer_SingSkin, 37, pSingSkin);
		visual_transferout(_Context->buffer_FileName, 37, pFileName);
		visual_transferout((void *) 0, 0, pUpdate);
		if ( pUpdate != (char *) 0)
			*((int*)pUpdate) = _Context->value_Update;
		}
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_configuration_show()
{
	visual_freeze();
	visual_window(150,115,500,370,2,"Sing : Version 1.0a",19,0x0);
	visual_image(152,137,494,344,VisualSkin,4);
	visual_text(162,153,476,18,2,27,0,"Sing Configuration Variables",28,259);
	visual_text(170,195,156,16,2,27,0,"Font path",9,258);
	visual_text(170,225,154,16,2,27,0,"Image path",10,258);
	visual_text(170,255,154,16,2,27,0,"Palette",7,258);
	visual_text(170,285,154,16,2,27,0,"Base font",9,258);
	visual_text(170,315,154,16,2,27,0,"Bios mode",9,258);
	visual_text(170,345,160,20,2,27,0,"Skin",4,258);
	visual_frame(330,195,300+2,20+2,5);
	visual_text(330+1,195+1,300,20,1,27,0,_Context->buffer_FontPath,37,0);
	visual_frame(330,225,300+2,20+2,5);
	visual_text(330+1,225+1,300,20,1,27,0,_Context->buffer_ImagePath,37,0);
	visual_frame(330,255,300+2,20+2,5);
	visual_text(330+1,255+1,300,20,1,27,0,_Context->buffer_Palette,37,0);
	visual_frame(330,285,300+2,20+2,5);
	visual_text(330+1,285+1,300,20,1,27,0,_Context->buffer_BaseFont,37,0);
	visual_frame(330,315,300+2,20+2,5);
	visual_text(330+1,315+1,300,20,1,27,0,_Context->buffer_BiosMode,37,0);
	visual_frame(330,345,300+2,20+2,5);
	visual_text(330+1,345+1,300,20,1,27,0,_Context->buffer_SingSkin,37,2);
	visual_text(170,375,160,20,2,27,0,"Filename",8,258);
	visual_frame(330,375,300+2,20+2,5);
	visual_text(330+1,375+1,300,20,1,27,0,_Context->buffer_FileName,37,0);
	visual_check(362,428,121,27,2,27,0,"&Update",7,_Context->value_Update|0);
	visual_button(170,425,154,32,2,27,0,"&Accept",7,0);
	visual_button(490,425,140,32,2,27,0,"&Cancel",7,0);
	visual_thaw(150,115,500,370);

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


private	int	accept_configuration_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 362 ) 
	&&  ( my >= 428 ) 
	&&  ( mx <= 483 ) 
	&&  ( my <= 455 )) {
		return(2); /* Update */
		}
	if (( mx >= 170 ) 
	&&  ( my >= 425 ) 
	&&  ( mx <= 324 ) 
	&&  ( my <= 457 )) {
		return(3); /* Accept */
		}
	if (( mx >= 490 ) 
	&&  ( my >= 425 ) 
	&&  ( mx <= 630 ) 
	&&  ( my <= 457 )) {
		return(4); /* Cancel */
		}

	return(-1);
}


private	int	accept_configuration_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Update */
				visual_check(362,428,121,27,2,27,0,"&Update",7,(_Context->value_Update |2));
				_Context->keycode = visual_getch();
				visual_check(362,428,121,27,2,27,0,"&Update",7,(_Context->value_Update |0));
				break;
			case	0x3 :
				/* Accept */
				visual_button(170,425,154,32,2,27,0,"&Accept",7,2);
				_Context->keycode = visual_getch();
				visual_button(170,425,154,32,2,27,0,"&Accept",7,0);
				break;
			case	0x4 :
				/* Cancel */
				visual_button(490,425,140,32,2,27,0,"&Cancel",7,2);
				_Context->keycode = visual_getch();
				visual_button(490,425,140,32,2,27,0,"&Cancel",7,0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_configuration_show();
			continue;
		case	0x2 :
			_Context->focus_item=4;
			accept_configuration_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_configuration_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto232 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Update */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Update += 1;
							_Context->value_Update &= 1;
							}
						continue;
					case	0x3 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(170,425,154,32,2,27,0,"&Accept",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(170,425,154,32,2,27,0,"&Accept",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x4 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(490,425,140,32,2,27,0,"&Cancel",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(490,425,140,32,2,27,0,"&Cancel",7,0);
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
				_Context->focus_item=4;
			}
			continue;
		case 0x855 : 
		case 0x875 : 
		/* Update */
		_Context->value_Update += 1;
		_Context->value_Update &= 1;
		_Context->focus_item=2;
		continue;
		case 0x841 : 
		case 0x861 : 
		/* Accept */
		visual_button(170,425,154,32,2,27,0,"&Accept",7,8);
		visual_button(170,425,154,32,2,27,0,"&Accept",7,0);
		_Context->focus_item=3;
		if ((_Context->keycode = on_Accept_event()) != -1) break;
		continue;
		case 0x843 : 
		case 0x863 : 
		/* Cancel */
		visual_button(490,425,140,32,2,27,0,"&Cancel",7,8);
		visual_button(490,425,140,32,2,27,0,"&Cancel",7,0);
		_Context->focus_item=4;
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

public	int	accept_configuration(
	char * pFontPath,
	char * pImagePath,
	char * pPalette,
	char * pBaseFont,
	char * pBiosMode,
	char * pSingSkin,
	char * pFileName,
	char * pUpdate)
{
	int	status=0;
	status = accept_configuration_create(
	 pFontPath,
	 pImagePath,
	 pPalette,
	 pBaseFont,
	 pBiosMode,
	 pSingSkin,
	 pFileName,
	 pUpdate);
	if ( status != 0) return(status);
	status = accept_configuration_show();
		enter_modal();
	status = accept_configuration_focus();
		leave_modal();
	status = accept_configuration_hide();
	status = accept_configuration_remove(
	 pFontPath,
	 pImagePath,
	 pPalette,
	 pBaseFont,
	 pBiosMode,
	 pSingSkin,
	 pFileName,
	 pUpdate);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vconfig_c */
