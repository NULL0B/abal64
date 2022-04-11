
#ifndef _vimage_c
#define _vimage_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vimage.sng  */
/* Target         : vimage.c  */
/* Identification : 0.0-1065019114-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_image_dimensions_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_Width[9];
	char	buffer_Height[9];
	int	value_MakeFit;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[4];
	} * _Context;

private	int	accept_image_dimensions_create(
	char * pWidth,
	char * pHeight,
	char * pMakeFit)
{

	if (!(_Context = allocate( sizeof( struct accept_image_dimensions_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=6;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Width, 8, pWidth);
		visual_transferin(_Context->buffer_Height, 8, pHeight);
		visual_transferin((void *) 0, 0, pMakeFit);
		if (!( pMakeFit )) _Context->value_MakeFit=0;
		else	_Context->value_MakeFit = *((int *)pMakeFit);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(310,175,180+10,250+10);
	return(0);
}

private	int	accept_image_dimensions_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,310,175);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_image_dimensions_remove(
	char * pWidth,
	char * pHeight,
	char * pMakeFit)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Width, 8, pWidth);
		visual_transferout(_Context->buffer_Height, 8, pHeight);
		visual_transferout((void *) 0, 0, pMakeFit);
		if ( pMakeFit != (char *) 0)
			*((int*)pMakeFit) = _Context->value_MakeFit;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_image_dimensions_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,310,175);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(310,175,180,250,2,"Sing : Version 1.0a",19,0x403);
	visual_image(313,197,172,224,VisualSkin,4);
	visual_text(320,215,160,20,3,27,0,"Image",5,1027);
	visual_text(320,305,160,20,3,27,0,"Dimension",9,1027);
	visual_text(330,245,68,20,2,27,0,"Width",5,258);
	visual_text(330,275,68,20,2,27,0,"Height",6,258);
	visual_frame(400,245,70+2,20+2,5);
	visual_text(400+1,245+1,70,20,1,27,0,_Context->buffer_Width,8,0);
	visual_frame(400,275,70+2,20+2,5);
	visual_text(400+1,275+1,70,20,1,27,0,_Context->buffer_Height,8,0);
	visual_button(330,379,60,30,2,27,0,"Accept",6,0);
	visual_button(410,379,60,30,2,27,0,"Cancel",6,0);
	visual_check(320,335,150,20,2,27,0,"Make Fit",8,_Context->value_MakeFit|0);
	visual_thaw(310,175,180,250);

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


private	int	accept_image_dimensions_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 469 )  
	&&  (my >= 179 )  
	&&  (mx <= 485 )  
	&&  (my <= 195 )) {
		return(1);	/* auto193 */

		}
	if ((mx >= 453 )  
	&&  (my >= 179 )  
	&&  (mx <= 469 )  
	&&  (my <= 195 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vimage.htm");
			};
		return(-1);	/* auto193 */

		}
	if (( mx >= 400 ) 
	&&  ( my >= 245 ) 
	&&  ( mx <= 470 ) 
	&&  ( my <= 265 )) {
		return(2); /* Width */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 275 ) 
	&&  ( mx <= 470 ) 
	&&  ( my <= 295 )) {
		return(3); /* Height */
		}
	if (( mx >= 330 ) 
	&&  ( my >= 379 ) 
	&&  ( mx <= 390 ) 
	&&  ( my <= 409 )) {
		return(4); /* Accept */
		}
	if (( mx >= 410 ) 
	&&  ( my >= 379 ) 
	&&  ( mx <= 470 ) 
	&&  ( my <= 409 )) {
		return(5); /* Cancel */
		}
	if (( mx >= 320 ) 
	&&  ( my >= 335 ) 
	&&  ( mx <= 470 ) 
	&&  ( my <= 355 )) {
		return(6); /* MakeFit */
		}

	return(-1);
}


private	int	accept_image_dimensions_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Width */
				_Context->keycode = visual_edit(400+1,245+1,70,20,1,_Context->buffer_Width,8);
				break;
			case	0x3 :
				/* Height */
				_Context->keycode = visual_edit(400+1,275+1,70,20,1,_Context->buffer_Height,8);
				break;
			case	0x4 :
				/* Accept */
				visual_button(330,379,60,30,2,27,0,"Accept",6,2);
				_Context->keycode = visual_getch();
				visual_button(330,379,60,30,2,27,0,"Accept",6,0);
				break;
			case	0x5 :
				/* Cancel */
				visual_button(410,379,60,30,2,27,0,"Cancel",6,2);
				_Context->keycode = visual_getch();
				visual_button(410,379,60,30,2,27,0,"Cancel",6,0);
				break;
			case	0x6 :
				/* MakeFit */
				visual_check(320,335,150,20,2,27,0,"Make Fit",8,(_Context->value_MakeFit |2));
				_Context->keycode = visual_getch();
				visual_check(320,335,150,20,2,27,0,"Make Fit",8,(_Context->value_MakeFit |0));
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_image_dimensions_show();
			continue;
		case	0x2 :
			_Context->focus_item=6;
			accept_image_dimensions_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_image_dimensions_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto193 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Width */
						continue;
					case	0x3 :
						/* Height */
						continue;
					case	0x4 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(330,379,60,30,2,27,0,"Accept",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(330,379,60,30,2,27,0,"Accept",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0x5 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(410,379,60,30,2,27,0,"Cancel",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(410,379,60,30,2,27,0,"Cancel",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

							}
						continue;
					case	0x6 :
						/* MakeFit */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MakeFit += 1;
							_Context->value_MakeFit &= 1;
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
				_Context->focus_item=6;
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

public	int	accept_image_dimensions(
	char * pWidth,
	char * pHeight,
	char * pMakeFit)
{
	int	status=0;
	status = accept_image_dimensions_create(
	 pWidth,
	 pHeight,
	 pMakeFit);
	if ( status != 0) return(status);
	status = accept_image_dimensions_show();
		enter_modal();
	status = accept_image_dimensions_focus();
		leave_modal();
	status = accept_image_dimensions_hide();
	status = accept_image_dimensions_remove(
	 pWidth,
	 pHeight,
	 pMakeFit);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vimage_c */
