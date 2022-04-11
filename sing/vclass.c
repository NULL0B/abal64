
#ifndef _vclass_c
#define _vclass_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vclass.sng  */
/* Target         : vclass.c  */
/* Identification : 0.0-1065019113-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_class_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_ClassName[52];
	char	buffer_LoadName[52];
	char	buffer_ProdName[52];
	char	buffer_Header[52];
	char	buffer_Dependance[521];
	char	signature[6];
	} * _Context;

private	int	accept_class_create(
	char * pClassName,
	char * pLoadName,
	char * pProdName,
	char * pHeader,
	char * pDependance)
{

	if (!(_Context = allocate( sizeof( struct accept_class_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=9;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_ClassName, 51, pClassName);
		visual_transferin(_Context->buffer_LoadName, 51, pLoadName);
		visual_transferin(_Context->buffer_ProdName, 51, pProdName);
		visual_transferin(_Context->buffer_Header, 51, pHeader);
		visual_transferin(_Context->buffer_Dependance, 520, pDependance);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	return(0);
}

private	int	accept_class_hide()
{

	return(0);
}

private	int	accept_class_remove(
	char * pClassName,
	char * pLoadName,
	char * pProdName,
	char * pHeader,
	char * pDependance)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_ClassName, 51, pClassName);
		visual_transferout(_Context->buffer_LoadName, 51, pLoadName);
		visual_transferout(_Context->buffer_ProdName, 51, pProdName);
		visual_transferout(_Context->buffer_Header, 51, pHeader);
		visual_transferout(_Context->buffer_Dependance, 520, pDependance);
		}
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_class_show()
{
	visual_freeze();
	visual_window(120,90,560,420,2,"Sing : Version 1.0a",19,0x0);
	visual_frame(130,120,540,380,4);
	visual_text(140,130,462,16,2,27,0,"Virtual Class",13,0);
	visual_line(140,150,660,150,1,27);
	visual_text(140,170,462,16,2,27,0,"Class Identifier",16,0);
	visual_text(140,200,462,16,2,27,0,"Load Filename",13,0);
	visual_text(140,230,462,16,2,27,0,"Target Filename",15,0);
	visual_frame(250,170,410+2,20+2,5);
	visual_text(250+1,170+1,410,20,1,26,0,_Context->buffer_ClassName,51,0);
	visual_frame(250,200,410+2,20+2,5);
	visual_text(250+1,200+1,410,20,1,26,0,_Context->buffer_LoadName,51,0);
	visual_frame(250,230,410+2,20+2,5);
	visual_text(250+1,230+1,410,20,1,26,0,_Context->buffer_ProdName,51,0);
	visual_text(140,260,378,16,2,27,0,"Target Header",13,0);
	visual_frame(250,260,410+2,20+2,5);
	visual_text(250+1,260+1,410,20,1,27,0,_Context->buffer_Header,51,0);
	visual_text(140,290,462,16,2,27,0,"Dependance",10,0);
	visual_frame(140,310,520+2,130+2,5);
	visual_text(140+1,310+1,520,130,1,27,0,_Context->buffer_Dependance,520,0);
	visual_button(140,450,90,30,2,26,0,"Accept",6,0);
	visual_button(240,450,100,30,2,27,0,"Editor",6,0);
	visual_button(560,450,100,30,2,26,0,"Cancel",6,0);
	visual_thaw(120,90,560,420);

	return(0);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Editor_event() {
	perform_editor(_Context->buffer_ProdName);
	accept_class_show();
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}


private	int	accept_class_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 250 ) 
	&&  ( my >= 170 ) 
	&&  ( mx <= 660 ) 
	&&  ( my <= 190 )) {
		return(2); /* ClassName */
		}
	if (( mx >= 250 ) 
	&&  ( my >= 200 ) 
	&&  ( mx <= 660 ) 
	&&  ( my <= 220 )) {
		return(3); /* LoadName */
		}
	if (( mx >= 250 ) 
	&&  ( my >= 230 ) 
	&&  ( mx <= 660 ) 
	&&  ( my <= 250 )) {
		return(4); /* ProdName */
		}
	if (( mx >= 250 ) 
	&&  ( my >= 260 ) 
	&&  ( mx <= 660 ) 
	&&  ( my <= 280 )) {
		return(5); /* Header */
		}
	if (( mx >= 140 ) 
	&&  ( my >= 310 ) 
	&&  ( mx <= 660 ) 
	&&  ( my <= 440 )) {
		return(6); /* Dependance */
		}
	if (( mx >= 140 ) 
	&&  ( my >= 450 ) 
	&&  ( mx <= 230 ) 
	&&  ( my <= 480 )) {
		return(7); /* Accept */
		}
	if (( mx >= 240 ) 
	&&  ( my >= 450 ) 
	&&  ( mx <= 340 ) 
	&&  ( my <= 480 )) {
		return(8); /* Editor */
		}
	if (( mx >= 560 ) 
	&&  ( my >= 450 ) 
	&&  ( mx <= 660 ) 
	&&  ( my <= 480 )) {
		return(9); /* Cancel */
		}

	return(-1);
}


private	int	accept_class_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* ClassName */
				_Context->keycode = visual_edit(250+1,170+1,410,20,1,_Context->buffer_ClassName,51);
				break;
			case	0x3 :
				/* LoadName */
				_Context->keycode = visual_edit(250+1,200+1,410,20,1,_Context->buffer_LoadName,51);
				break;
			case	0x4 :
				/* ProdName */
				_Context->keycode = visual_edit(250+1,230+1,410,20,1,_Context->buffer_ProdName,51);
				break;
			case	0x5 :
				/* Header */
				_Context->keycode = visual_edit(250+1,260+1,410,20,1,_Context->buffer_Header,51);
				break;
			case	0x6 :
				/* Dependance */
				_Context->keycode = visual_edit(140+1,310+1,520,130,1,_Context->buffer_Dependance,520);
				break;
			case	0x7 :
				/* Accept */
				visual_button(140,450,90,30,2,26,0,"Accept",6,2);
				_Context->keycode = visual_getch();
				visual_button(140,450,90,30,2,26,0,"Accept",6,0);
				break;
			case	0x8 :
				/* Editor */
				visual_button(240,450,100,30,2,27,0,"Editor",6,2);
				_Context->keycode = visual_getch();
				visual_button(240,450,100,30,2,27,0,"Editor",6,0);
				break;
			case	0x9 :
				/* Cancel */
				visual_button(560,450,100,30,2,26,0,"Cancel",6,2);
				_Context->keycode = visual_getch();
				visual_button(560,450,100,30,2,26,0,"Cancel",6,0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_class_show();
			continue;
		case	0x2 :
			_Context->focus_item=9;
			accept_class_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_class_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto383 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* ClassName */
						continue;
					case	0x3 :
						/* LoadName */
						continue;
					case	0x4 :
						/* ProdName */
						continue;
					case	0x5 :
						/* Header */
						continue;
					case	0x6 :
						/* Dependance */
						continue;
					case	0x7 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(140,450,90,30,2,26,0,"Accept",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(140,450,90,30,2,26,0,"Accept",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x8 :
						/* Editor */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(240,450,100,30,2,27,0,"Editor",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(240,450,100,30,2,27,0,"Editor",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Editor_event()) != -1) break;

							}
						continue;
					case	0x9 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(560,450,100,30,2,26,0,"Cancel",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(560,450,100,30,2,26,0,"Cancel",6,0);
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
				_Context->focus_item=9;
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

public	int	accept_class(
	char * pClassName,
	char * pLoadName,
	char * pProdName,
	char * pHeader,
	char * pDependance)
{
	int	status=0;
	status = accept_class_create(
	 pClassName,
	 pLoadName,
	 pProdName,
	 pHeader,
	 pDependance);
	if ( status != 0) return(status);
	status = accept_class_show();
		enter_modal();
	status = accept_class_focus();
		leave_modal();
	status = accept_class_hide();
	status = accept_class_remove(
	 pClassName,
	 pLoadName,
	 pProdName,
	 pHeader,
	 pDependance);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vclass_c */
