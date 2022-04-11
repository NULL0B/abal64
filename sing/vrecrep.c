
#ifndef _vrecrep_c
#define _vrecrep_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vrecrep.sng  */
/* Target         : vrecrep.c  */
/* Identification : 0.0-1065019114-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_animation_parameters_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_FileName[60];
	int	value_Mode;
	char	signature[3];
	} * _Context;

private	int	accept_animation_parameters_create(
	char * pFileName,
	char * pMode)
{

	if (!(_Context = allocate( sizeof( struct accept_animation_parameters_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=5;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 59, pFileName);
		visual_transferin((void *) 0, 0, pMode);
		if (!( pMode )) _Context->value_Mode=0;
		else	_Context->value_Mode = *((int *)pMode);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	return(0);
}

private	int	accept_animation_parameters_hide()
{

	return(0);
}

private	int	accept_animation_parameters_remove(
	char * pFileName,
	char * pMode)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 59, pFileName);
		visual_transferout((void *) 0, 0, pMode);
		if ( pMode != (char *) 0)
			*((int*)pMode) = _Context->value_Mode;
		}
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_animation_parameters_show()
{
	visual_freeze();
	visual_window(140,220,520,160,2,"Sing : Version 1.0a",19,0x403);
	visual_image(142,242,514,134,"skin.gif",4);
	visual_text(160,260,476,16,2,27,0,"Animation Filename",18,258);
	visual_frame(160,280,472+2,16+2,5);
	visual_text(160+1,280+1,472,16,1,27,0,_Context->buffer_FileName,59,0);
	visual_select(270,320,250,46,1,27,0,parse_selection("Record Script|Replay Animation",&_Context->value_Mode),0);
	visual_button(160,320,100,30,2,27,0,"&Accept",7,0);
	visual_button(530,320,100,30,2,27,0,"&Cancel",7,0);
	visual_thaw(140,220,520,160);

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


private	int	accept_animation_parameters_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 639 )  
	&&  (my >= 224 )  
	&&  (mx <= 655 )  
	&&  (my <= 240 )) {
		return(1);	/* Auto529 */

		}
	if ((mx >= 623 )  
	&&  (my >= 224 )  
	&&  (mx <= 639 )  
	&&  (my <= 240 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vrecrep.htm");
			};
		return(-1);	/* Auto529 */

		}
	if (( mx >= 160 ) 
	&&  ( my >= 280 ) 
	&&  ( mx <= 632 ) 
	&&  ( my <= 296 )) {
		return(2); /* FileName */
		}
	if ((mx >= 270 ) 
	&&  (my >= 320 ) 
	&&  (mx <= 520 ) 
	&&  (my <= 336 )) {
		return(3); /* Mode */
		}
	if (( mx >= 160 ) 
	&&  ( my >= 320 ) 
	&&  ( mx <= 260 ) 
	&&  ( my <= 350 )) {
		return(4); /* Accept */
		}
	if (( mx >= 530 ) 
	&&  ( my >= 320 ) 
	&&  ( mx <= 630 ) 
	&&  ( my <= 350 )) {
		return(5); /* Cancel */
		}

	return(-1);
}


private	int	accept_animation_parameters_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(160+1,280+1,472,16,1,_Context->buffer_FileName,59);
				break;
			case	0x3 :
				/* Mode */
				_Context->keycode = visual_select(270,320,250,46,1,27,0,parse_selection("Record Script|Replay Animation",&_Context->value_Mode),2);
				break;
			case	0x4 :
				/* Accept */
				visual_button(160,320,100,30,2,27,0,"&Accept",7,2);
				_Context->keycode = visual_getch();
				visual_button(160,320,100,30,2,27,0,"&Accept",7,0);
				break;
			case	0x5 :
				/* Cancel */
				visual_button(530,320,100,30,2,27,0,"&Cancel",7,2);
				_Context->keycode = visual_getch();
				visual_button(530,320,100,30,2,27,0,"&Cancel",7,0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_animation_parameters_show();
			continue;
		case	0x2 :
			_Context->focus_item=5;
			accept_animation_parameters_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_animation_parameters_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto529 */
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
						/* Mode */
						continue;
					case	0x4 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(160,320,100,30,2,27,0,"&Accept",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(160,320,100,30,2,27,0,"&Accept",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x5 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(530,320,100,30,2,27,0,"&Cancel",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(530,320,100,30,2,27,0,"&Cancel",7,0);
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
		visual_button(160,320,100,30,2,27,0,"&Accept",7,8);
		visual_button(160,320,100,30,2,27,0,"&Accept",7,0);
		_Context->focus_item=4;
		if ((_Context->keycode = on_Accept_event()) != -1) break;
		continue;
		case 0x843 : 
		case 0x863 : 
		/* Cancel */
		visual_button(530,320,100,30,2,27,0,"&Cancel",7,8);
		visual_button(530,320,100,30,2,27,0,"&Cancel",7,0);
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

public	int	accept_animation_parameters(
	char * pFileName,
	char * pMode)
{
	int	status=0;
	status = accept_animation_parameters_create(
	 pFileName,
	 pMode);
	if ( status != 0) return(status);
	status = accept_animation_parameters_show();
		enter_modal();
	status = accept_animation_parameters_focus();
		leave_modal();
	status = accept_animation_parameters_hide();
	status = accept_animation_parameters_remove(
	 pFileName,
	 pMode);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vrecrep_c */
