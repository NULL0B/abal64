
#ifndef _vmenu_c
#define _vmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vmenu.sng  */
/* Target         : vmenu.c  */
/* Identification : 0.0-1065019113-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_menu_properties_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_LoadName[41];
	char	buffer_Identifier[41];
	char	buffer_AtX[8];
	char	buffer_AtY[8];
	char	buffer_Method[41];
	int	value_Popup;
	char	buffer_Hint[41];
	char	buffer_Target[41];
	char	buffer_Language[41];
	char	buffer_Font[33];
	char	buffer_Style[33];
	char	signature[12];
	} * _Context;

private	int	accept_menu_properties_create(
	char * pLoadName,
	char * pIdentifier,
	char * pAtX,
	char * pAtY,
	char * pMethod,
	char * pPopup,
	char * pHint,
	char * pTarget,
	char * pLanguage,
	char * pFont,
	char * pStyle)
{

	if (!(_Context = allocate( sizeof( struct accept_menu_properties_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=14;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWSWSSWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_LoadName, 40, pLoadName);
		visual_transferin(_Context->buffer_Identifier, 40, pIdentifier);
		visual_transferin(_Context->buffer_AtX, 7, pAtX);
		visual_transferin(_Context->buffer_AtY, 7, pAtY);
		visual_transferin(_Context->buffer_Method, 40, pMethod);
		visual_transferin((void *) 0, 0, pPopup);
		if (!( pPopup )) _Context->value_Popup=0;
		else	_Context->value_Popup = *((int *)pPopup);
		visual_transferin(_Context->buffer_Hint, 40, pHint);
		visual_transferin(_Context->buffer_Target, 40, pTarget);
		visual_transferin(_Context->buffer_Language, 40, pLanguage);
		visual_transferin(_Context->buffer_Font, 32, pFont);
		visual_transferin(_Context->buffer_Style, 32, pStyle);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	return(0);
}

private	int	accept_menu_properties_hide()
{

	return(0);
}

private	int	accept_menu_properties_remove(
	char * pLoadName,
	char * pIdentifier,
	char * pAtX,
	char * pAtY,
	char * pMethod,
	char * pPopup,
	char * pHint,
	char * pTarget,
	char * pLanguage,
	char * pFont,
	char * pStyle)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWSWSSWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_LoadName, 40, pLoadName);
		visual_transferout(_Context->buffer_Identifier, 40, pIdentifier);
		visual_transferout(_Context->buffer_AtX, 7, pAtX);
		visual_transferout(_Context->buffer_AtY, 7, pAtY);
		visual_transferout(_Context->buffer_Method, 40, pMethod);
		visual_transferout((void *) 0, 0, pPopup);
		if ( pPopup != (char *) 0)
			*((int*)pPopup) = _Context->value_Popup;
		visual_transferout(_Context->buffer_Hint, 40, pHint);
		visual_transferout(_Context->buffer_Target, 40, pTarget);
		visual_transferout(_Context->buffer_Language, 40, pLanguage);
		visual_transferout(_Context->buffer_Font, 32, pFont);
		visual_transferout(_Context->buffer_Style, 32, pStyle);
		}
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_menu_properties_show()
{
	visual_freeze();
	visual_window(140,90,520,420,2,"Sing : Version 1.0a",19,0x0);
	visual_frame(150,120,500,380,4);
	visual_text(160,130,490,16,2,38,0,"Visual Menu Parameters",22,2);
	visual_line(160,150,640,150,1,27);
	visual_text(160,170,154,16,2,27,0,"Filename",8,0);
	visual_frame(320,170,320+2,16+2,5);
	visual_text(320+1,170+1,320,16,1,27,0,_Context->buffer_LoadName,40,0);
	visual_text(160,190,154,16,2,38,0,"Identifier",10,2);
	visual_frame(320,190,320+2,16+2,5);
	visual_text(320+1,190+1,320,16,1,38,0,_Context->buffer_Identifier,40,0);
	visual_text(160,240,154,16,2,38,0,"Position",8,2);
	visual_line(160,220,640,220,1,27);
	visual_text(280,240,28,16,2,38,0,"X",1,2);
	visual_text(400,240,14,16,2,38,0,"Y",1,2);
	visual_frame(310,240,56+2,16+2,5);
	visual_text(310+1,240+1,56,16,1,38,0,_Context->buffer_AtX,7,0);
	visual_frame(430,240,56+2,16+2,5);
	visual_text(430+1,240+1,56,16,1,38,0,_Context->buffer_AtY,7,0);
	visual_line(160,270,640,270,1,38);
	visual_button(160,450,110,30,2,38,0,"Accept",6,0);
	visual_button(530,450,110,30,2,38,0,"Cancel",6,0);
	visual_text(160,280,154,16,2,38,0,"Method",6,2);
	visual_frame(320,280,320+2,16+2,5);
	visual_text(320+1,280+1,320,16,1,38,0,_Context->buffer_Method,40,0);
	visual_check(510,240,130,32,2,38,0,"Popup",5,_Context->value_Popup|0);
	visual_text(160,300,154,16,2,38,0,"Hint",4,0);
	visual_text(160,320,154,16,2,38,0,"Target",6,0);
	visual_text(160,340,154,16,2,38,0,"Language",8,0);
	visual_frame(320,300,320+2,16+2,5);
	visual_text(320+1,300+1,320,16,1,38,0,_Context->buffer_Hint,40,0);
	visual_frame(320,320,320+2,16+2,5);
	visual_text(320+1,320+1,320,16,1,38,0,_Context->buffer_Target,40,0);
	visual_frame(320,340,320+2,16+2,5);
	visual_text(320+1,340+1,320,16,1,38,0,_Context->buffer_Language,40,0);
	visual_line(160,370,640,370,1,38);
	visual_text(160,380,154,16,2,38,0,"Font",4,0);
	visual_text(160,400,154,16,2,38,0,"Style",5,0);
	visual_frame(320,380,256+2,16+2,5);
	visual_text(320+1,380+1,256,16,1,38,0,_Context->buffer_Font,32,0);
	visual_frame(320,400,256+2,16+2,5);
	visual_text(320+1,400+1,256,16,1,38,0,_Context->buffer_Style,32,0);
	visual_line(160,430,640,430,1,38);
	visual_thaw(140,90,520,420);

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


private	int	accept_menu_properties_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 320 ) 
	&&  ( my >= 170 ) 
	&&  ( mx <= 640 ) 
	&&  ( my <= 186 )) {
		return(2); /* LoadName */
		}
	if (( mx >= 320 ) 
	&&  ( my >= 190 ) 
	&&  ( mx <= 640 ) 
	&&  ( my <= 206 )) {
		return(3); /* Identifier */
		}
	if (( mx >= 310 ) 
	&&  ( my >= 240 ) 
	&&  ( mx <= 366 ) 
	&&  ( my <= 256 )) {
		return(4); /* AtX */
		}
	if (( mx >= 430 ) 
	&&  ( my >= 240 ) 
	&&  ( mx <= 486 ) 
	&&  ( my <= 256 )) {
		return(5); /* AtY */
		}
	if (( mx >= 160 ) 
	&&  ( my >= 450 ) 
	&&  ( mx <= 270 ) 
	&&  ( my <= 480 )) {
		return(6); /* Accept */
		}
	if (( mx >= 530 ) 
	&&  ( my >= 450 ) 
	&&  ( mx <= 640 ) 
	&&  ( my <= 480 )) {
		return(7); /* Cancel */
		}
	if (( mx >= 320 ) 
	&&  ( my >= 280 ) 
	&&  ( mx <= 640 ) 
	&&  ( my <= 296 )) {
		return(8); /* Method */
		}
	if (( mx >= 510 ) 
	&&  ( my >= 240 ) 
	&&  ( mx <= 640 ) 
	&&  ( my <= 272 )) {
		return(9); /* Popup */
		}
	if (( mx >= 320 ) 
	&&  ( my >= 300 ) 
	&&  ( mx <= 640 ) 
	&&  ( my <= 316 )) {
		return(10); /* Hint */
		}
	if (( mx >= 320 ) 
	&&  ( my >= 320 ) 
	&&  ( mx <= 640 ) 
	&&  ( my <= 336 )) {
		return(11); /* Target */
		}
	if (( mx >= 320 ) 
	&&  ( my >= 340 ) 
	&&  ( mx <= 640 ) 
	&&  ( my <= 356 )) {
		return(12); /* Language */
		}
	if (( mx >= 320 ) 
	&&  ( my >= 380 ) 
	&&  ( mx <= 576 ) 
	&&  ( my <= 396 )) {
		return(13); /* Font */
		}
	if (( mx >= 320 ) 
	&&  ( my >= 400 ) 
	&&  ( mx <= 576 ) 
	&&  ( my <= 416 )) {
		return(14); /* Style */
		}

	return(-1);
}


private	int	accept_menu_properties_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* LoadName */
				_Context->keycode = visual_edit(320+1,170+1,320,16,1,_Context->buffer_LoadName,40);
				break;
			case	0x3 :
				/* Identifier */
				_Context->keycode = visual_edit(320+1,190+1,320,16,1,_Context->buffer_Identifier,40);
				break;
			case	0x4 :
				/* AtX */
				_Context->keycode = visual_edit(310+1,240+1,56,16,1,_Context->buffer_AtX,7);
				break;
			case	0x5 :
				/* AtY */
				_Context->keycode = visual_edit(430+1,240+1,56,16,1,_Context->buffer_AtY,7);
				break;
			case	0x6 :
				/* Accept */
				visual_button(160,450,110,30,2,38,0,"Accept",6,2);
				_Context->keycode = visual_getch();
				visual_button(160,450,110,30,2,38,0,"Accept",6,0);
				break;
			case	0x7 :
				/* Cancel */
				visual_button(530,450,110,30,2,38,0,"Cancel",6,2);
				_Context->keycode = visual_getch();
				visual_button(530,450,110,30,2,38,0,"Cancel",6,0);
				break;
			case	0x8 :
				/* Method */
				_Context->keycode = visual_edit(320+1,280+1,320,16,1,_Context->buffer_Method,40);
				break;
			case	0x9 :
				/* Popup */
				visual_check(510,240,130,32,2,38,0,"Popup",5,(_Context->value_Popup |2));
				_Context->keycode = visual_getch();
				visual_check(510,240,130,32,2,38,0,"Popup",5,(_Context->value_Popup |0));
				break;
			case	0xa :
				/* Hint */
				_Context->keycode = visual_edit(320+1,300+1,320,16,1,_Context->buffer_Hint,40);
				break;
			case	0xb :
				/* Target */
				_Context->keycode = visual_edit(320+1,320+1,320,16,1,_Context->buffer_Target,40);
				break;
			case	0xc :
				/* Language */
				_Context->keycode = visual_edit(320+1,340+1,320,16,1,_Context->buffer_Language,40);
				break;
			case	0xd :
				/* Font */
				_Context->keycode = visual_edit(320+1,380+1,256,16,1,_Context->buffer_Font,32);
				break;
			case	0xe :
				/* Style */
				_Context->keycode = visual_edit(320+1,400+1,256,16,1,_Context->buffer_Style,32);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_menu_properties_show();
			continue;
		case	0x2 :
			_Context->focus_item=14;
			accept_menu_properties_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_menu_properties_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto149 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* LoadName */
						continue;
					case	0x3 :
						/* Identifier */
						continue;
					case	0x4 :
						/* AtX */
						continue;
					case	0x5 :
						/* AtY */
						continue;
					case	0x6 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(160,450,110,30,2,38,0,"Accept",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(160,450,110,30,2,38,0,"Accept",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x7 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(530,450,110,30,2,38,0,"Cancel",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(530,450,110,30,2,38,0,"Cancel",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

							}
						continue;
					case	0x8 :
						/* Method */
						continue;
					case	0x9 :
						/* Popup */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Popup += 1;
							_Context->value_Popup &= 1;
							}
						continue;
					case	0xa :
						/* Hint */
						continue;
					case	0xb :
						/* Target */
						continue;
					case	0xc :
						/* Language */
						continue;
					case	0xd :
						/* Font */
						continue;
					case	0xe :
						/* Style */
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
				_Context->focus_item=14;
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

public	int	accept_menu_properties(
	char * pLoadName,
	char * pIdentifier,
	char * pAtX,
	char * pAtY,
	char * pMethod,
	char * pPopup,
	char * pHint,
	char * pTarget,
	char * pLanguage,
	char * pFont,
	char * pStyle)
{
	int	status=0;
	status = accept_menu_properties_create(
	 pLoadName,
	 pIdentifier,
	 pAtX,
	 pAtY,
	 pMethod,
	 pPopup,
	 pHint,
	 pTarget,
	 pLanguage,
	 pFont,
	 pStyle);
	if ( status != 0) return(status);
	status = accept_menu_properties_show();
		enter_modal();
	status = accept_menu_properties_focus();
		leave_modal();
	status = accept_menu_properties_hide();
	status = accept_menu_properties_remove(
	 pLoadName,
	 pIdentifier,
	 pAtX,
	 pAtY,
	 pMethod,
	 pPopup,
	 pHint,
	 pTarget,
	 pLanguage,
	 pFont,
	 pStyle);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vmenu_c */
