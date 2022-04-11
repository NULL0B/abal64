
#ifndef _vmsave_c
#define _vmsave_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vmsave.sng  */
/* Target         : vmsave.c  */
/* Identification : 0.0-1065019113-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_modelsave_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_FileName[71];
	int	value_SaveImages;
	int	value_SaveForms;
	int	value_SaveAll;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[5];
	} * _Context;

private	int	accept_modelsave_create(
	char * pFileName,
	char * pSaveImages,
	char * pSaveForms,
	char * pSaveAll)
{

	if (!(_Context = allocate( sizeof( struct accept_modelsave_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=8;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 70, pFileName);
		visual_transferin((void *) 0, 0, pSaveImages);
		if (!( pSaveImages )) _Context->value_SaveImages=0;
		else	_Context->value_SaveImages = *((int *)pSaveImages);
		visual_transferin((void *) 0, 0, pSaveForms);
		if (!( pSaveForms )) _Context->value_SaveForms=0;
		else	_Context->value_SaveForms = *((int *)pSaveForms);
		visual_transferin((void *) 0, 0, pSaveAll);
		if (!( pSaveAll )) _Context->value_SaveAll=0;
		else	_Context->value_SaveAll = *((int *)pSaveAll);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(100,195,600+10,210+10);
	return(0);
}

private	int	accept_modelsave_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,100,195);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_modelsave_remove(
	char * pFileName,
	char * pSaveImages,
	char * pSaveForms,
	char * pSaveAll)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 70, pFileName);
		visual_transferout((void *) 0, 0, pSaveImages);
		if ( pSaveImages != (char *) 0)
			*((int*)pSaveImages) = _Context->value_SaveImages;
		visual_transferout((void *) 0, 0, pSaveForms);
		if ( pSaveForms != (char *) 0)
			*((int*)pSaveForms) = _Context->value_SaveForms;
		visual_transferout((void *) 0, 0, pSaveAll);
		if ( pSaveAll != (char *) 0)
			*((int*)pSaveAll) = _Context->value_SaveAll;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_modelsave_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,100,195);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(100,195,600,210,2,"Sing : Version 1.0a",19,0x403);
	visual_image(103,218,594,184,"skin.gif",4);
	visual_text(120,235,560,16,2,38,0,"Name of Application to Save",27,258);
	visual_frame(121,255,560+2,16+2,5);
	visual_text(121+1,255+1,560,16,1,16,24,_Context->buffer_FileName,70,0);
	visual_button(120,345,110,30,2,34,0,"&Accept",7,0);
	visual_button(460,345,100,30,2,27,24,"&Select",7,0);
	visual_button(570,345,110,30,2,34,0,"&Cancel",7,0);
	visual_check(120,285,120,32,2,34,0,"Sa&ve Images",12,_Context->value_SaveImages|0);
	visual_check(281,283,120,32,2,34,0,"Sav&e Forms",11,_Context->value_SaveForms|0);
	visual_check(457,284,160,32,2,34,0,"Save A&ll",9,_Context->value_SaveAll|0);
	visual_image(326,331,50,50,"fileicon.gif",0);
	visual_thaw(100,195,600,210);

	return(0);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Select_event() {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_3D);
	accept_modelsave_show();
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}


private	int	accept_modelsave_event()
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
			visual_help("vmsave.htm");
			};
		return(-1);	/* auto6 */

		}
	if (( mx >= 121 ) 
	&&  ( my >= 255 ) 
	&&  ( mx <= 681 ) 
	&&  ( my <= 271 )) {
		return(2); /* FileName */
		}
	if (( mx >= 120 ) 
	&&  ( my >= 345 ) 
	&&  ( mx <= 230 ) 
	&&  ( my <= 375 )) {
		return(3); /* Accept */
		}
	if (( mx >= 460 ) 
	&&  ( my >= 345 ) 
	&&  ( mx <= 560 ) 
	&&  ( my <= 375 )) {
		return(4); /* Select */
		}
	if (( mx >= 570 ) 
	&&  ( my >= 345 ) 
	&&  ( mx <= 680 ) 
	&&  ( my <= 375 )) {
		return(5); /* Cancel */
		}
	if (( mx >= 120 ) 
	&&  ( my >= 285 ) 
	&&  ( mx <= 240 ) 
	&&  ( my <= 317 )) {
		return(6); /* SaveImages */
		}
	if (( mx >= 281 ) 
	&&  ( my >= 283 ) 
	&&  ( mx <= 401 ) 
	&&  ( my <= 315 )) {
		return(7); /* SaveForms */
		}
	if (( mx >= 457 ) 
	&&  ( my >= 284 ) 
	&&  ( mx <= 617 ) 
	&&  ( my <= 316 )) {
		return(8); /* SaveAll */
		}

	return(-1);
}


private	int	accept_modelsave_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(121+1,255+1,560,16,1,_Context->buffer_FileName,70);
				break;
			case	0x3 :
				/* Accept */
				visual_button(120,345,110,30,2,34,0,"&Accept",7,2);
				_Context->keycode = visual_getch();
				visual_button(120,345,110,30,2,34,0,"&Accept",7,0);
				break;
			case	0x4 :
				/* Select */
				visual_button(460,345,100,30,2,27,24,"&Select",7,2);
				_Context->keycode = visual_getch();
				visual_button(460,345,100,30,2,27,24,"&Select",7,0);
				break;
			case	0x5 :
				/* Cancel */
				visual_button(570,345,110,30,2,34,0,"&Cancel",7,2);
				_Context->keycode = visual_getch();
				visual_button(570,345,110,30,2,34,0,"&Cancel",7,0);
				break;
			case	0x6 :
				/* SaveImages */
				visual_check(120,285,120,32,2,34,0,"Sa&ve Images",12,(_Context->value_SaveImages |2));
				_Context->keycode = visual_getch();
				visual_check(120,285,120,32,2,34,0,"Sa&ve Images",12,(_Context->value_SaveImages |0));
				break;
			case	0x7 :
				/* SaveForms */
				visual_check(281,283,120,32,2,34,0,"Sav&e Forms",11,(_Context->value_SaveForms |2));
				_Context->keycode = visual_getch();
				visual_check(281,283,120,32,2,34,0,"Sav&e Forms",11,(_Context->value_SaveForms |0));
				break;
			case	0x8 :
				/* SaveAll */
				visual_check(457,284,160,32,2,34,0,"Save A&ll",9,(_Context->value_SaveAll |2));
				_Context->keycode = visual_getch();
				visual_check(457,284,160,32,2,34,0,"Save A&ll",9,(_Context->value_SaveAll |0));
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_modelsave_show();
			continue;
		case	0x2 :
			_Context->focus_item=8;
			accept_modelsave_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_modelsave_event()) == -1)
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
							visual_button(120,345,110,30,2,34,0,"&Accept",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(120,345,110,30,2,34,0,"&Accept",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x4 :
						/* Select */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(460,345,100,30,2,27,24,"&Select",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(460,345,100,30,2,27,24,"&Select",7,0);
							}
						if ( visual_event(1) &  0x2020 ) {
						if ((_Context->keycode = on_Select_event()) != -1) break;

							}
						continue;
					case	0x5 :
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
					case	0x6 :
						/* SaveImages */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SaveImages += 1;
							_Context->value_SaveImages &= 1;
							}
						continue;
					case	0x7 :
						/* SaveForms */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SaveForms += 1;
							_Context->value_SaveForms &= 1;
							}
						continue;
					case	0x8 :
						/* SaveAll */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SaveAll += 1;
							_Context->value_SaveAll &= 1;
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
		case 0x841 : 
		case 0x861 : 
		/* Accept */
		visual_button(120,345,110,30,2,34,0,"&Accept",7,8);
		visual_button(120,345,110,30,2,34,0,"&Accept",7,0);
		_Context->focus_item=3;
		if ((_Context->keycode = on_Accept_event()) != -1) break;
		continue;
		case 0x853 : 
		case 0x873 : 
		/* Select */
		visual_button(460,345,100,30,2,27,24,"&Select",7,8);
		visual_button(460,345,100,30,2,27,24,"&Select",7,0);
		_Context->focus_item=4;
		if ((_Context->keycode = on_Select_event()) != -1) break;
		continue;
		case 0x843 : 
		case 0x863 : 
		/* Cancel */
		visual_button(570,345,110,30,2,34,0,"&Cancel",7,8);
		visual_button(570,345,110,30,2,34,0,"&Cancel",7,0);
		_Context->focus_item=5;
		if ((_Context->keycode = on_Cancel_event()) != -1) break;
		continue;
		case 0x876 : 
		case 0x896 : 
		/* SaveImages */
		_Context->value_SaveImages += 1;
		_Context->value_SaveImages &= 1;
		_Context->focus_item=6;
		continue;
		case 0x865 : 
		case 0x885 : 
		/* SaveForms */
		_Context->value_SaveForms += 1;
		_Context->value_SaveForms &= 1;
		_Context->focus_item=7;
		continue;
		case 0x86c : 
		case 0x88c : 
		/* SaveAll */
		_Context->value_SaveAll += 1;
		_Context->value_SaveAll &= 1;
		_Context->focus_item=8;
		continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_modelsave(
	char * pFileName,
	char * pSaveImages,
	char * pSaveForms,
	char * pSaveAll)
{
	int	status=0;
	status = accept_modelsave_create(
	 pFileName,
	 pSaveImages,
	 pSaveForms,
	 pSaveAll);
	if ( status != 0) return(status);
	status = accept_modelsave_show();
		enter_modal();
	status = accept_modelsave_focus();
		leave_modal();
	status = accept_modelsave_hide();
	status = accept_modelsave_remove(
	 pFileName,
	 pSaveImages,
	 pSaveForms,
	 pSaveAll);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vmsave_c */
