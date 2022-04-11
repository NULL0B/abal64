
#ifndef _vconst_c
#define _vconst_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vconst.sng  */
/* Target         : vconst.c  */
/* Identification : 0.0-1065019113-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_constant_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_Identity[46];
	int	value_Type;
	char	buffer_Value[406];
	int	value_Public;
	char	signature[5];
	} * _Context;

private	int	accept_constant_create(
	char * pIdentity,
	char * pType,
	char * pValue,
	char * pPublic)
{

	if (!(_Context = allocate( sizeof( struct accept_constant_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=7;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWSW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Identity, 45, pIdentity);
		visual_transferin((void *) 0, 0, pType);
		if (!( pType )) _Context->value_Type=0;
		else	_Context->value_Type = *((int *)pType);
		visual_transferin(_Context->buffer_Value, 405, pValue);
		visual_transferin((void *) 0, 0, pPublic);
		if (!( pPublic )) _Context->value_Public=0;
		else	_Context->value_Public = *((int *)pPublic);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	return(0);
}

private	int	accept_constant_hide()
{

	return(0);
}

private	int	accept_constant_remove(
	char * pIdentity,
	char * pType,
	char * pValue,
	char * pPublic)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWSW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Identity, 45, pIdentity);
		visual_transferout((void *) 0, 0, pType);
		if ( pType != (char *) 0)
			*((int*)pType) = _Context->value_Type;
		visual_transferout(_Context->buffer_Value, 405, pValue);
		visual_transferout((void *) 0, 0, pPublic);
		if ( pPublic != (char *) 0)
			*((int*)pPublic) = _Context->value_Public;
		}
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_constant_show()
{
	visual_freeze();
	visual_window(155,140,490,320,2,"Sing : Version 1.0a",19,0x0);
	visual_frame(165,170,470,280,4);
	visual_text(175,180,448,16,2,26,0,"Constant",8,0);
	visual_text(175,210,140,16,2,26,0,"Identifier",10,0);
	visual_text(175,240,98,16,2,26,0,"Value",5,0);
	visual_frame(265,210,360+2,16+2,5);
	visual_text(265+1,210+1,360,16,1,26,0,_Context->buffer_Identity,45,0);
	visual_select(484,180,140,110,1,0,0,parse_selection("void+byte+word+long+float+bcd+string",&_Context->value_Type),0);
	visual_frame(265,240,360+2,144+2,5);
	visual_text(265+1,240+1,360,144,1,26,0,_Context->buffer_Value,405,0);
	visual_button(175,410,90,32,2,26,0,"Accept",6,0);
	visual_button(515,410,110,30,2,26,0,"Cancel",6,0);
	visual_check(252,180,100,32,2,26,0,"Public",6,_Context->value_Public|0);
	visual_thaw(155,140,490,320);

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


private	int	accept_constant_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 265 ) 
	&&  ( my >= 210 ) 
	&&  ( mx <= 625 ) 
	&&  ( my <= 226 )) {
		return(2); /* Identity */
		}
	if ((mx >= 484 ) 
	&&  (my >= 180 ) 
	&&  (mx <= 624 ) 
	&&  (my <= 196 )) {
		return(3); /* Type */
		}
	if (( mx >= 265 ) 
	&&  ( my >= 240 ) 
	&&  ( mx <= 625 ) 
	&&  ( my <= 384 )) {
		return(4); /* Value */
		}
	if (( mx >= 175 ) 
	&&  ( my >= 410 ) 
	&&  ( mx <= 265 ) 
	&&  ( my <= 442 )) {
		return(5); /* Accept */
		}
	if (( mx >= 515 ) 
	&&  ( my >= 410 ) 
	&&  ( mx <= 625 ) 
	&&  ( my <= 440 )) {
		return(6); /* Cancel */
		}
	if (( mx >= 252 ) 
	&&  ( my >= 180 ) 
	&&  ( mx <= 352 ) 
	&&  ( my <= 212 )) {
		return(7); /* Public */
		}

	return(-1);
}


private	int	accept_constant_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Identity */
				_Context->keycode = visual_edit(265+1,210+1,360,16,1,_Context->buffer_Identity,45);
				break;
			case	0x3 :
				/* Type */
				_Context->keycode = visual_select(484,180,140,110,1,0,0,parse_selection("void+byte+word+long+float+bcd+string",&_Context->value_Type),2);
				break;
			case	0x4 :
				/* Value */
				_Context->keycode = visual_edit(265+1,240+1,360,144,1,_Context->buffer_Value,405);
				break;
			case	0x5 :
				/* Accept */
				visual_button(175,410,90,32,2,26,0,"Accept",6,2);
				_Context->keycode = visual_getch();
				visual_button(175,410,90,32,2,26,0,"Accept",6,0);
				break;
			case	0x6 :
				/* Cancel */
				visual_button(515,410,110,30,2,26,0,"Cancel",6,2);
				_Context->keycode = visual_getch();
				visual_button(515,410,110,30,2,26,0,"Cancel",6,0);
				break;
			case	0x7 :
				/* Public */
				visual_check(252,180,100,32,2,26,0,"Public",6,(_Context->value_Public |2));
				_Context->keycode = visual_getch();
				visual_check(252,180,100,32,2,26,0,"Public",6,(_Context->value_Public |0));
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_constant_show();
			continue;
		case	0x2 :
			_Context->focus_item=7;
			accept_constant_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_constant_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Window1 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Identity */
						continue;
					case	0x3 :
						/* Type */
						continue;
					case	0x4 :
						/* Value */
						continue;
					case	0x5 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(175,410,90,32,2,26,0,"Accept",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(175,410,90,32,2,26,0,"Accept",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x6 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(515,410,110,30,2,26,0,"Cancel",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(515,410,110,30,2,26,0,"Cancel",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

							}
						continue;
					case	0x7 :
						/* Public */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Public += 1;
							_Context->value_Public &= 1;
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
				_Context->focus_item=7;
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

public	int	accept_constant(
	char * pIdentity,
	char * pType,
	char * pValue,
	char * pPublic)
{
	int	status=0;
	status = accept_constant_create(
	 pIdentity,
	 pType,
	 pValue,
	 pPublic);
	if ( status != 0) return(status);
	status = accept_constant_show();
		enter_modal();
	status = accept_constant_focus();
		leave_modal();
	status = accept_constant_hide();
	status = accept_constant_remove(
	 pIdentity,
	 pType,
	 pValue,
	 pPublic);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vconst_c */
