
#ifndef _vparam_c
#define _vparam_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vparam.sng  */
/* Target         : vparam.c  */
/* Identification : 0.0-1065578460-4352.4351 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_general_options_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	value_ProductionLanguage;
	int	value_ImageFormat;
	int	value_TextFont;
	int	value_Alignment;
	int	value_IsBold;
	int	value_IsUnderline;
	int	value_IsShadow;
	int	value_SnapOn;
	char	buffer_GridWidth[10];
	char	buffer_GridHeight[10];
	char	buffer_ThickNess[10];
	int	value_LockOn;
	int	value_DropTool;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[12];
	} * _Context;

private	int	accept_general_options_create(
	char * pProductionLanguage,
	char * pImageFormat,
	char * pTextFont,
	char * pAlignment,
	char * pIsBold,
	char * pIsUnderline,
	char * pIsShadow,
	char * pSnapOn,
	char * pGridWidth,
	char * pGridHeight,
	char * pThickNess,
	char * pLockOn,
	char * pDropTool)
{

	int i;
	if (!(_Context = allocate( sizeof( struct accept_general_options_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=17;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pProductionLanguage);
		if (!( pProductionLanguage )) _Context->value_ProductionLanguage=0;
		else	_Context->value_ProductionLanguage = *((int *)pProductionLanguage);
		visual_transferin((void *) 0, 0, pImageFormat);
		if (!( pImageFormat )) _Context->value_ImageFormat=0;
		else	_Context->value_ImageFormat = *((int *)pImageFormat);
		visual_transferin((void *) 0, 0, pTextFont);
		if (!( pTextFont )) _Context->value_TextFont=0;
		else	_Context->value_TextFont = *((int *)pTextFont);
		visual_transferin((void *) 0, 0, pAlignment);
		if (!( pAlignment )) _Context->value_Alignment=0;
		else	_Context->value_Alignment = *((int *)pAlignment);
		visual_transferin((void *) 0, 0, pIsBold);
		if (!( pIsBold )) _Context->value_IsBold=0;
		else	_Context->value_IsBold = *((int *)pIsBold);
		visual_transferin((void *) 0, 0, pIsUnderline);
		if (!( pIsUnderline )) _Context->value_IsUnderline=0;
		else	_Context->value_IsUnderline = *((int *)pIsUnderline);
		visual_transferin((void *) 0, 0, pIsShadow);
		if (!( pIsShadow )) _Context->value_IsShadow=0;
		else	_Context->value_IsShadow = *((int *)pIsShadow);
		visual_transferin((void *) 0, 0, pSnapOn);
		if (!( pSnapOn )) _Context->value_SnapOn=0;
		else	_Context->value_SnapOn = *((int *)pSnapOn);
		visual_transferin(_Context->buffer_GridWidth, 9, pGridWidth);
		visual_transferin(_Context->buffer_GridHeight, 9, pGridHeight);
		visual_transferin(_Context->buffer_ThickNess, 9, pThickNess);
		visual_transferin((void *) 0, 0, pLockOn);
		if (!( pLockOn )) _Context->value_LockOn=0;
		else	_Context->value_LockOn = *((int *)pLockOn);
		visual_transferin((void *) 0, 0, pDropTool);
		if (!( pDropTool )) _Context->value_DropTool=0;
		else	_Context->value_DropTool = *((int *)pDropTool);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(215,95,370+10,410+10);
	return(0);
}

private	int	accept_general_options_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,215,95);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_general_options_remove(
	char * pProductionLanguage,
	char * pImageFormat,
	char * pTextFont,
	char * pAlignment,
	char * pIsBold,
	char * pIsUnderline,
	char * pIsShadow,
	char * pSnapOn,
	char * pGridWidth,
	char * pGridHeight,
	char * pThickNess,
	char * pLockOn,
	char * pDropTool)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pProductionLanguage);
		if ( pProductionLanguage != (char *) 0)
			*((int*)pProductionLanguage) = _Context->value_ProductionLanguage;
		visual_transferout((void *) 0, 0, pImageFormat);
		if ( pImageFormat != (char *) 0)
			*((int*)pImageFormat) = _Context->value_ImageFormat;
		visual_transferout((void *) 0, 0, pTextFont);
		if ( pTextFont != (char *) 0)
			*((int*)pTextFont) = _Context->value_TextFont;
		visual_transferout((void *) 0, 0, pAlignment);
		if ( pAlignment != (char *) 0)
			*((int*)pAlignment) = _Context->value_Alignment;
		visual_transferout((void *) 0, 0, pIsBold);
		if ( pIsBold != (char *) 0)
			*((int*)pIsBold) = _Context->value_IsBold;
		visual_transferout((void *) 0, 0, pIsUnderline);
		if ( pIsUnderline != (char *) 0)
			*((int*)pIsUnderline) = _Context->value_IsUnderline;
		visual_transferout((void *) 0, 0, pIsShadow);
		if ( pIsShadow != (char *) 0)
			*((int*)pIsShadow) = _Context->value_IsShadow;
		visual_transferout((void *) 0, 0, pSnapOn);
		if ( pSnapOn != (char *) 0)
			*((int*)pSnapOn) = _Context->value_SnapOn;
		visual_transferout(_Context->buffer_GridWidth, 9, pGridWidth);
		visual_transferout(_Context->buffer_GridHeight, 9, pGridHeight);
		visual_transferout(_Context->buffer_ThickNess, 9, pThickNess);
		visual_transferout((void *) 0, 0, pLockOn);
		if ( pLockOn != (char *) 0)
			*((int*)pLockOn) = _Context->value_LockOn;
		visual_transferout((void *) 0, 0, pDropTool);
		if ( pDropTool != (char *) 0)
			*((int*)pDropTool) = _Context->value_DropTool;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_general_options_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,215,95);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(215,95,370,410,2,"Sing : Version 1.0a",strlen("Sing : Version 1.0a"),0x403);
	visual_image(218,119,363,382,"skin.gif",4);
	visual_text(225,125,350,20,3,27,0,"General Parameters",strlen("General Parameters"),1538);
	visual_text(235,165,180,20,2,27,0,"Production Language",strlen("Production Language"),2);
	visual_text(235,195,180,20,2,27,0,"Image Production",strlen("Image Production"),2);
	visual_text(235,225,180,20,2,27,0,"Current Text Font",strlen("Current Text Font"),2);
	visual_text(235,255,180,20,2,27,0,"Alignment",strlen("Alignment"),2);
	visual_text(235,415,98,16,2,27,0,"Line Thickness",strlen("Line Thickness"),2);
	visual_text(235,365,98,16,2,27,0,"Grid Width",strlen("Grid Width"),2);
	visual_text(235,385,98,16,2,27,0,"Grid Height",strlen("Grid Height"),2);
	visual_select(415,165,150,60,1,27,0,parse_selection(ProductionLanguageList,&_Context->value_ProductionLanguage),0);
	visual_select(415,195,150,30,1,27,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),0);
	visual_select(415,225,150,48,1,0,0,parse_selection(TextFontList,&_Context->value_TextFont),0);
	visual_select(415,255,150,56,1,0,0,parse_selection(WidgetAlignList,&_Context->value_Alignment),0);
	visual_check(235,295,98,16,2,175,0,"&Bold",strlen("&Bold"),_Context->value_IsBold|0);
	visual_check(345,295,112,16,2,175,0,"&Underline",strlen("&Underline"),_Context->value_IsUnderline|0);
	visual_check(465,295,98,16,2,175,0,"&Shadow",strlen("&Shadow"),_Context->value_IsShadow|0);
	visual_check(235,325,98,16,2,27,0,"&Grid On",strlen("&Grid On"),_Context->value_SnapOn|0);
	visual_frame(355,365,72+2,16+2,5);
	visual_text(355+1,365+1,72,16,1,0,0,_Context->buffer_GridWidth,9,0);
	visual_frame(355,385,72+2,16+2,5);
	visual_text(355+1,385+1,72,16,1,0,0,_Context->buffer_GridHeight,9,0);
	visual_button(355,455,98,32,2,27,28,"Te&xtFont",strlen("Te&xtFont"),0);
	visual_frame(355,415,72+2,16+2,5);
	visual_text(355+1,415+1,72,16,1,0,0,_Context->buffer_ThickNess,9,0);
	visual_check(345,325,112,16,2,27,0,"&Lock On",strlen("&Lock On"),_Context->value_LockOn|0);
	visual_check(465,325,112,16,2,27,0,"&DropTool",strlen("&DropTool"),_Context->value_DropTool|0);
	visual_button(235,455,98,32,2,27,0,"&Accept",strlen("&Accept"),0);
	visual_button(475,455,98,32,2,27,0,"&Cancel",strlen("&Cancel"),0);
	visual_thaw(215,95,370,410);

	return(0);
}
private int on_TextFont_event() {
	int fw=guifontsize(_Context->value_TextFont+1);
	int fh=((fw&0xFF00)>>8);
	fw=(fw&0x00FF);
	sprintf(_Context->buffer_GridWidth,"%u",fw);
	sprintf(_Context->buffer_GridHeight,"%u",fh);
	accept_general_options_show();
	return(-1);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Auto3413_event() {
	return(27);
	return(-1);
}


private	int	accept_general_options_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (mt & _MIMO_UP) {
	if ((mx >= 564 )  
	&&  (my >= 99 )  
	&&  (mx <= 580 )  
	&&  (my <= 115 )) {
		return(1);	/* Auto553 */

		}
	if ((mx >= 548 )  
	&&  (my >= 99 )  
	&&  (mx <= 564 )  
	&&  (my <= 115 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vparam.htm");
			};
		return(-1);	/* Auto553 */

		}
		}
	if ((mx >= 415 ) 
	&&  (my >= 165 ) 
	&&  (mx <= 565 ) 
	&&  (my <= 181 )) {
		return(2); /* ProductionLanguage */
		}
	if ((mx >= 415 ) 
	&&  (my >= 195 ) 
	&&  (mx <= 565 ) 
	&&  (my <= 211 )) {
		return(3); /* ImageFormat */
		}
	if ((mx >= 415 ) 
	&&  (my >= 225 ) 
	&&  (mx <= 565 ) 
	&&  (my <= 241 )) {
		return(4); /* TextFont */
		}
	if ((mx >= 415 ) 
	&&  (my >= 255 ) 
	&&  (mx <= 565 ) 
	&&  (my <= 271 )) {
		return(5); /* Alignment */
		}
	if (( mx >= 235 ) 
	&&  ( my >= 295 ) 
	&&  ( mx <= 333 ) 
	&&  ( my <= 311 )) {
		return(6); /* IsBold */
		}
	if (( mx >= 345 ) 
	&&  ( my >= 295 ) 
	&&  ( mx <= 457 ) 
	&&  ( my <= 311 )) {
		return(7); /* IsUnderline */
		}
	if (( mx >= 465 ) 
	&&  ( my >= 295 ) 
	&&  ( mx <= 563 ) 
	&&  ( my <= 311 )) {
		return(8); /* IsShadow */
		}
	if (( mx >= 235 ) 
	&&  ( my >= 325 ) 
	&&  ( mx <= 333 ) 
	&&  ( my <= 341 )) {
		return(9); /* SnapOn */
		}
	if (( mx >= 355 ) 
	&&  ( my >= 365 ) 
	&&  ( mx <= 427 ) 
	&&  ( my <= 381 )) {
		return(10); /* GridWidth */
		}
	if (( mx >= 355 ) 
	&&  ( my >= 385 ) 
	&&  ( mx <= 427 ) 
	&&  ( my <= 401 )) {
		return(11); /* GridHeight */
		}
	if (( mx >= 355 ) 
	&&  ( my >= 455 ) 
	&&  ( mx <= 453 ) 
	&&  ( my <= 487 )) {
		return(12); /* TextFont */
		}
	if (( mx >= 355 ) 
	&&  ( my >= 415 ) 
	&&  ( mx <= 427 ) 
	&&  ( my <= 431 )) {
		return(13); /* ThickNess */
		}
	if (( mx >= 345 ) 
	&&  ( my >= 325 ) 
	&&  ( mx <= 457 ) 
	&&  ( my <= 341 )) {
		return(14); /* LockOn */
		}
	if (( mx >= 465 ) 
	&&  ( my >= 325 ) 
	&&  ( mx <= 577 ) 
	&&  ( my <= 341 )) {
		return(15); /* DropTool */
		}
	if (( mx >= 235 ) 
	&&  ( my >= 455 ) 
	&&  ( mx <= 333 ) 
	&&  ( my <= 487 )) {
		return(16); /* Accept */
		}
	if (( mx >= 475 ) 
	&&  ( my >= 455 ) 
	&&  ( mx <= 573 ) 
	&&  ( my <= 487 )) {
		return(17); /* Auto3413 */
		}

	return(-1);
}


private	int	accept_general_options_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* ProductionLanguage */
				_Context->keycode = visual_select(415,165,150,60,1,27,0,parse_selection(ProductionLanguageList,&_Context->value_ProductionLanguage),2);
				break;
			case	0x3 :
				/* ImageFormat */
				_Context->keycode = visual_select(415,195,150,30,1,27,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),2);
				break;
			case	0x4 :
				/* TextFont */
				_Context->keycode = visual_select(415,225,150,48,1,0,0,parse_selection(TextFontList,&_Context->value_TextFont),2);
				break;
			case	0x5 :
				/* Alignment */
				_Context->keycode = visual_select(415,255,150,56,1,0,0,parse_selection(WidgetAlignList,&_Context->value_Alignment),2);
				break;
			case	0x6 :
				/* IsBold */
				visual_check(235,295,98,16,2,175,0,"&Bold",strlen("&Bold"),(_Context->value_IsBold |2));
				_Context->keycode = visual_getch();
				visual_check(235,295,98,16,2,175,0,"&Bold",strlen("&Bold"),(_Context->value_IsBold |0));
				break;
			case	0x7 :
				/* IsUnderline */
				visual_check(345,295,112,16,2,175,0,"&Underline",strlen("&Underline"),(_Context->value_IsUnderline |2));
				_Context->keycode = visual_getch();
				visual_check(345,295,112,16,2,175,0,"&Underline",strlen("&Underline"),(_Context->value_IsUnderline |0));
				break;
			case	0x8 :
				/* IsShadow */
				visual_check(465,295,98,16,2,175,0,"&Shadow",strlen("&Shadow"),(_Context->value_IsShadow |2));
				_Context->keycode = visual_getch();
				visual_check(465,295,98,16,2,175,0,"&Shadow",strlen("&Shadow"),(_Context->value_IsShadow |0));
				break;
			case	0x9 :
				/* SnapOn */
				visual_check(235,325,98,16,2,27,0,"&Grid On",strlen("&Grid On"),(_Context->value_SnapOn |2));
				_Context->keycode = visual_getch();
				visual_check(235,325,98,16,2,27,0,"&Grid On",strlen("&Grid On"),(_Context->value_SnapOn |0));
				break;
			case	0xa :
				/* GridWidth */
				_Context->keycode = visual_edit(355+1,365+1,72,16,1,_Context->buffer_GridWidth,9);
				break;
			case	0xb :
				/* GridHeight */
				_Context->keycode = visual_edit(355+1,385+1,72,16,1,_Context->buffer_GridHeight,9);
				break;
			case	0xc :
				/* TextFont */
				visual_button(355,455,98,32,2,27,28,"Te&xtFont",strlen("Te&xtFont"),2);
				_Context->keycode = visual_getch();
				visual_button(355,455,98,32,2,27,28,"Te&xtFont",strlen("Te&xtFont"),0);
				break;
			case	0xd :
				/* ThickNess */
				_Context->keycode = visual_edit(355+1,415+1,72,16,1,_Context->buffer_ThickNess,9);
				break;
			case	0xe :
				/* LockOn */
				visual_check(345,325,112,16,2,27,0,"&Lock On",strlen("&Lock On"),(_Context->value_LockOn |2));
				_Context->keycode = visual_getch();
				visual_check(345,325,112,16,2,27,0,"&Lock On",strlen("&Lock On"),(_Context->value_LockOn |0));
				break;
			case	0xf :
				/* DropTool */
				visual_check(465,325,112,16,2,27,0,"&DropTool",strlen("&DropTool"),(_Context->value_DropTool |2));
				_Context->keycode = visual_getch();
				visual_check(465,325,112,16,2,27,0,"&DropTool",strlen("&DropTool"),(_Context->value_DropTool |0));
				break;
			case	0x10 :
				/* Accept */
				visual_button(235,455,98,32,2,27,0,"&Accept",strlen("&Accept"),2);
				_Context->keycode = visual_getch();
				visual_button(235,455,98,32,2,27,0,"&Accept",strlen("&Accept"),0);
				break;
			case	0x11 :
				/* Auto3413 */
				visual_button(475,455,98,32,2,27,0,"&Cancel",strlen("&Cancel"),2);
				_Context->keycode = visual_getch();
				visual_button(475,455,98,32,2,27,0,"&Cancel",strlen("&Cancel"),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_general_options_show();
			continue;
		case	0x2 :
			_Context->focus_item=17;
			accept_general_options_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_general_options_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto553 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* ProductionLanguage */
						continue;
					case	0x3 :
						/* ImageFormat */
						continue;
					case	0x4 :
						/* TextFont */
						continue;
					case	0x5 :
						/* Alignment */
						continue;
					case	0x6 :
						/* IsBold */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsBold += 1;
							_Context->value_IsBold &= 1;
							}
						continue;
					case	0x7 :
						/* IsUnderline */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsUnderline += 1;
							_Context->value_IsUnderline &= 1;
							}
						continue;
					case	0x8 :
						/* IsShadow */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsShadow += 1;
							_Context->value_IsShadow &= 1;
							}
						continue;
					case	0x9 :
						/* SnapOn */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SnapOn += 1;
							_Context->value_SnapOn &= 1;
							}
						continue;
					case	0xa :
						/* GridWidth */
						continue;
					case	0xb :
						/* GridHeight */
						continue;
					case	0xc :
						/* TextFont */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(355,455,98,32,2,27,28,"Te&xtFont",strlen("Te&xtFont"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(355,455,98,32,2,27,28,"Te&xtFont",strlen("Te&xtFont"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_TextFont_event()) != -1) break;

							}
						continue;
					case	0xd :
						/* ThickNess */
						continue;
					case	0xe :
						/* LockOn */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_LockOn += 1;
							_Context->value_LockOn &= 1;
							}
						continue;
					case	0xf :
						/* DropTool */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_DropTool += 1;
							_Context->value_DropTool &= 1;
							}
						continue;
					case	0x10 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(235,455,98,32,2,27,0,"&Accept",strlen("&Accept"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(235,455,98,32,2,27,0,"&Accept",strlen("&Accept"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x11 :
						/* Auto3413 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(475,455,98,32,2,27,0,"&Cancel",strlen("&Cancel"),8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(475,455,98,32,2,27,0,"&Cancel",strlen("&Cancel"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto3413_event()) != -1) break;

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
				_Context->focus_item=17;
			}
			continue;
		case 0x842 : 
		case 0x862 : 
		/* IsBold */
		_Context->value_IsBold += 1;
		_Context->value_IsBold &= 1;
		_Context->focus_item=6;
		continue;
		case 0x855 : 
		case 0x875 : 
		/* IsUnderline */
		_Context->value_IsUnderline += 1;
		_Context->value_IsUnderline &= 1;
		_Context->focus_item=7;
		continue;
		case 0x853 : 
		case 0x873 : 
		/* IsShadow */
		_Context->value_IsShadow += 1;
		_Context->value_IsShadow &= 1;
		_Context->focus_item=8;
		continue;
		case 0x847 : 
		case 0x867 : 
		/* SnapOn */
		_Context->value_SnapOn += 1;
		_Context->value_SnapOn &= 1;
		_Context->focus_item=9;
		continue;
		case 0x878 : 
		case 0x898 : 
		/* TextFont */
		visual_button(355,455,98,32,2,27,28,"Te&xtFont",strlen("Te&xtFont"),8);
		visual_button(355,455,98,32,2,27,28,"Te&xtFont",strlen("Te&xtFont"),0);
		_Context->focus_item=12;
		if ((_Context->keycode = on_TextFont_event()) != -1) break;
		continue;
		case 0x84c : 
		case 0x86c : 
		/* LockOn */
		_Context->value_LockOn += 1;
		_Context->value_LockOn &= 1;
		_Context->focus_item=14;
		continue;
		case 0x844 : 
		case 0x864 : 
		/* DropTool */
		_Context->value_DropTool += 1;
		_Context->value_DropTool &= 1;
		_Context->focus_item=15;
		continue;
		case 0x841 : 
		case 0x861 : 
		/* Accept */
		visual_button(235,455,98,32,2,27,0,"&Accept",strlen("&Accept"),8);
		visual_button(235,455,98,32,2,27,0,"&Accept",strlen("&Accept"),0);
		_Context->focus_item=16;
		if ((_Context->keycode = on_Accept_event()) != -1) break;
		continue;
		case 0x843 : 
		case 0x863 : 
		/* Auto3413 */
		visual_button(475,455,98,32,2,27,0,"&Cancel",strlen("&Cancel"),8);
		visual_button(475,455,98,32,2,27,0,"&Cancel",strlen("&Cancel"),0);
		_Context->focus_item=17;
		if ((_Context->keycode = on_Auto3413_event()) != -1) break;
		continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_general_options(
	char * pProductionLanguage,
	char * pImageFormat,
	char * pTextFont,
	char * pAlignment,
	char * pIsBold,
	char * pIsUnderline,
	char * pIsShadow,
	char * pSnapOn,
	char * pGridWidth,
	char * pGridHeight,
	char * pThickNess,
	char * pLockOn,
	char * pDropTool)
{
	int	status=0;
	status = accept_general_options_create(
	 pProductionLanguage,
	 pImageFormat,
	 pTextFont,
	 pAlignment,
	 pIsBold,
	 pIsUnderline,
	 pIsShadow,
	 pSnapOn,
	 pGridWidth,
	 pGridHeight,
	 pThickNess,
	 pLockOn,
	 pDropTool);
	if ( status != 0) return(status);
	status = accept_general_options_show();
		enter_modal();
	status = accept_general_options_focus();
		leave_modal();
	status = accept_general_options_hide();
	status = accept_general_options_remove(
	 pProductionLanguage,
	 pImageFormat,
	 pTextFont,
	 pAlignment,
	 pIsBold,
	 pIsUnderline,
	 pIsShadow,
	 pSnapOn,
	 pGridWidth,
	 pGridHeight,
	 pThickNess,
	 pLockOn,
	 pDropTool);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vparam_c */
