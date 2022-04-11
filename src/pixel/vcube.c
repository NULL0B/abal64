
#ifndef _vcube_c
#define _vcube_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.01  */
/* Production     : C  */
/* Project        : vcube.sng  */
/* Target         : vcube.c  */
/* Identification : 0.0-1052337677-2460.2459 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_cube_properties_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_Identity[57];
	char	buffer_tlx[7];
	char	buffer_tly[7];
	char	buffer_tlz[7];
	char	buffer_brx[7];
	char	buffer_bry[7];
	char	buffer_brz[7];
	char	buffer_Class[58];
	int	value_AutoSize;
	int	value_InhibitGif;
	char	signature[11];
	} * _Context;

private	int	accept_cube_properties_create( char * pIdentity,char * ptlx,char * ptly,char * ptlz,char * pbrx,char * pbry,char * pbrz,char * pClass,char * pAutoSize,char * pInhibitGif)
{

	if (!(_Context = allocate( sizeof( struct accept_cube_properties_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=13;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWWWWKWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Identity, 57, pIdentity);
		visual_transferin(_Context->buffer_tlx, 7, ptlx);
		visual_transferin(_Context->buffer_tly, 7, ptly);
		visual_transferin(_Context->buffer_tlz, 7, ptlz);
		visual_transferin(_Context->buffer_brx, 7, pbrx);
		visual_transferin(_Context->buffer_bry, 7, pbry);
		visual_transferin(_Context->buffer_brz, 7, pbrz);
		visual_transferin(_Context->buffer_Class, 58, pClass);
		visual_transferin((void *) 0, 0, pAutoSize);
		if (!( pAutoSize )) _Context->value_AutoSize=0;
		else	_Context->value_AutoSize = *((int *)pAutoSize);
		visual_transferin((void *) 0, 0, pInhibitGif);
		if (!( pInhibitGif )) _Context->value_InhibitGif=0;
		else	_Context->value_InhibitGif = *((int *)pInhibitGif);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	return(0);
}

private	int	accept_cube_properties_hide()
{

	return(0);
}

private	int	accept_cube_properties_remove( char * pIdentity,char * ptlx,char * ptly,char * ptlz,char * pbrx,char * pbry,char * pbrz,char * pClass,char * pAutoSize,char * pInhibitGif)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWWWWKWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Identity, 57, pIdentity);
		visual_transferout(_Context->buffer_tlx, 7, ptlx);
		visual_transferout(_Context->buffer_tly, 7, ptly);
		visual_transferout(_Context->buffer_tlz, 7, ptlz);
		visual_transferout(_Context->buffer_brx, 7, pbrx);
		visual_transferout(_Context->buffer_bry, 7, pbry);
		visual_transferout(_Context->buffer_brz, 7, pbrz);
		visual_transferout(_Context->buffer_Class, 58, pClass);
		visual_transferout((void *) 0, 0, pAutoSize);
		if ( pAutoSize != (char *) 0)
			*((int*)pAutoSize) = _Context->value_AutoSize;
		visual_transferout((void *) 0, 0, pInhibitGif);
		if ( pInhibitGif != (char *) 0)
			*((int*)pInhibitGif) = _Context->value_InhibitGif;
		}
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_cube_properties_show()
{
	visual_freeze();
	visual_window(95,180,609,239,2,"Sing : Version 1.0a",19,3);
	visual_image(98,202,600,214,VisualSkin,4);
	visual_text(125,210,560,16,3,27,0,"3d Object Properties",20,514);
	visual_text(115,250,100,20,2,27,0,"Identity",8,2);
	visual_text(115,270,80,20,2,27,0,"Position",8,2);
	visual_text(115,290,100,20,2,27,0,"Dimensions",10,2);
	visual_frame(215,250,462+2,16+2,5);
	visual_text(215+1,250+1,462,16,1,26,0,_Context->buffer_Identity,57,0);
	visual_frame(215,270,56+2,16+2,5);
	visual_text(215+1,270+1,56,16,1,26,0,_Context->buffer_tlx,7,0);
	visual_frame(295,270,56+2,16+2,5);
	visual_text(295+1,270+1,56,16,1,26,0,_Context->buffer_tly,7,0);
	visual_frame(375,270,56+2,16+2,5);
	visual_text(375+1,270+1,56,16,1,26,0,_Context->buffer_tlz,7,0);
	visual_frame(215,290,56+2,16+2,5);
	visual_text(215+1,290+1,56,16,1,26,0,_Context->buffer_brx,7,0);
	visual_frame(295,290,56+2,16+2,5);
	visual_text(295+1,290+1,56,16,1,26,0,_Context->buffer_bry,7,0);
	visual_frame(375,290,56+2,16+2,5);
	visual_text(375+1,290+1,56,16,1,26,0,_Context->buffer_brz,7,0);
	visual_text(201,270,14,16,2,27,0,"X",1,259);
	visual_text(275,270,14,16,2,27,0,"Y",1,259);
	visual_text(355,270,14,16,2,27,0,"Z",1,259);
	visual_button(215,350,120,32,2,34,0,"&Accept",7,0);
	visual_button(375,350,140,32,2,27,28,"&Select",7,0);
	visual_button(555,350,120,32,2,34,0,"&Cancel",7,0);
	visual_text(115,310,100,20,2,27,0,"Class",5,2);
	visual_frame(215,310,464+2,16+2,5);
	visual_text(215+1,310+1,464,16,1,26,0,_Context->buffer_Class,58,2);
	visual_check(455,270,140,16,2,26,0,"Au&toSize",9,_Context->value_AutoSize|0);
	visual_check(455,290,160,16,2,0,0,"Inhibit Gif",11,_Context->value_InhibitGif|0);
	visual_thaw(95,180,609,239);

	return(0);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Select_event() {
	use_file_selector(_Context->buffer_Identity,WIDGET_FILE_ANY);
	accept_cube_properties_show();
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}


private	int	accept_cube_properties_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 683 )  
	&&  (my >= 184 )  
	&&  (mx <= 699 )  
	&&  (my <= 200 )) {
		return(1);	/* auto1 */

		}
	if (( mx >= 215 ) 
	&&  ( my >= 250 ) 
	&&  ( mx <= 677 ) 
	&&  ( my <= 266 )) 
		return(2); /* Identity */
	if (( mx >= 215 ) 
	&&  ( my >= 270 ) 
	&&  ( mx <= 271 ) 
	&&  ( my <= 286 )) 
		return(3); /* tlx */
	if (( mx >= 295 ) 
	&&  ( my >= 270 ) 
	&&  ( mx <= 351 ) 
	&&  ( my <= 286 )) 
		return(4); /* tly */
	if (( mx >= 375 ) 
	&&  ( my >= 270 ) 
	&&  ( mx <= 431 ) 
	&&  ( my <= 286 )) 
		return(5); /* tlz */
	if (( mx >= 215 ) 
	&&  ( my >= 290 ) 
	&&  ( mx <= 271 ) 
	&&  ( my <= 306 )) 
		return(6); /* brx */
	if (( mx >= 295 ) 
	&&  ( my >= 290 ) 
	&&  ( mx <= 351 ) 
	&&  ( my <= 306 )) 
		return(7); /* bry */
	if (( mx >= 375 ) 
	&&  ( my >= 290 ) 
	&&  ( mx <= 431 ) 
	&&  ( my <= 306 )) 
		return(8); /* brz */
	if (( mx >= 215 ) 
	&&  ( my >= 350 ) 
	&&  ( mx <= 335 ) 
	&&  ( my <= 382 )) 
		return(9); /* Accept */
	if (( mx >= 375 ) 
	&&  ( my >= 350 ) 
	&&  ( mx <= 515 ) 
	&&  ( my <= 382 )) 
		return(10); /* Select */
	if (( mx >= 555 ) 
	&&  ( my >= 350 ) 
	&&  ( mx <= 675 ) 
	&&  ( my <= 382 )) 
		return(11); /* Cancel */
	if (( mx >= 455 ) 
	&&  ( my >= 270 ) 
	&&  ( mx <= 595 ) 
	&&  ( my <= 286 )) 
		return(12); /* AutoSize */
	if (( mx >= 455 ) 
	&&  ( my >= 290 ) 
	&&  ( mx <= 615 ) 
	&&  ( my <= 306 )) 
		return(13); /* InhibitGif */

	return(-1);
}


private	int	accept_cube_properties_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Identity */
					_Context->keycode = visual_edit(215+1,250+1,462,16,1,_Context->buffer_Identity,57);
				break;
			case	0x3 :
				/* tlx */
					_Context->keycode = visual_edit(215+1,270+1,56,16,1,_Context->buffer_tlx,7);
				break;
			case	0x4 :
				/* tly */
					_Context->keycode = visual_edit(295+1,270+1,56,16,1,_Context->buffer_tly,7);
				break;
			case	0x5 :
				/* tlz */
					_Context->keycode = visual_edit(375+1,270+1,56,16,1,_Context->buffer_tlz,7);
				break;
			case	0x6 :
				/* brx */
					_Context->keycode = visual_edit(215+1,290+1,56,16,1,_Context->buffer_brx,7);
				break;
			case	0x7 :
				/* bry */
					_Context->keycode = visual_edit(295+1,290+1,56,16,1,_Context->buffer_bry,7);
				break;
			case	0x8 :
				/* brz */
					_Context->keycode = visual_edit(375+1,290+1,56,16,1,_Context->buffer_brz,7);
				break;
			case	0x9 :
				/* Accept */
				visual_button(215,350,120,32,2,34,0,"&Accept",7,2);
				_Context->keycode = visual_getch();
				visual_button(215,350,120,32,2,34,0,"&Accept",7,0);
				break;
			case	0xa :
				/* Select */
				visual_button(375,350,140,32,2,27,28,"&Select",7,2);
				_Context->keycode = visual_getch();
				visual_button(375,350,140,32,2,27,28,"&Select",7,0);
				break;
			case	0xb :
				/* Cancel */
				visual_button(555,350,120,32,2,34,0,"&Cancel",7,2);
				_Context->keycode = visual_getch();
				visual_button(555,350,120,32,2,34,0,"&Cancel",7,0);
				break;
			case	0xc :
				/* AutoSize */
				visual_check(455,270,140,16,2,26,0,"Au&toSize",9,(_Context->value_AutoSize |2));
				_Context->keycode = visual_getch();
				visual_check(455,270,140,16,2,26,0,"Au&toSize",9,_Context->value_AutoSize);
				break;
			case	0xd :
				/* InhibitGif */
				visual_check(455,290,160,16,2,0,0,"Inhibit Gif",11,(_Context->value_InhibitGif |2));
				_Context->keycode = visual_getch();
				visual_check(455,290,160,16,2,0,0,"Inhibit Gif",11,_Context->value_InhibitGif);
				break;

			default :
				_Context->keycode = 5;
			
}
retry:
		switch (_Context->keycode ) {
		case	0xc :
			_Context->focus_item=1;
			accept_cube_properties_show();
			continue;
		case	0x2 :
			_Context->focus_item=13;
			accept_cube_properties_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_cube_properties_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto1 */
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
						/* tlx */
						continue;
					case	0x4 :
						/* tly */
						continue;
					case	0x5 :
						/* tlz */
						continue;
					case	0x6 :
						/* brx */
						continue;
					case	0x7 :
						/* bry */
						continue;
					case	0x8 :
						/* brz */
						continue;
					case	0x9 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(215,350,120,32,2,34,0,"&Accept",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(215,350,120,32,2,34,0,"&Accept",7,0);
							}
						if (visual_event(1) &  0x20 ) {
		if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0xa :
						/* Select */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(375,350,140,32,2,27,28,"&Select",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(375,350,140,32,2,27,28,"&Select",7,0);
							}
						if (visual_event(1) &  0x20 ) {
		if ((_Context->keycode = on_Select_event()) != -1) break;

							}
						continue;
					case	0xb :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(555,350,120,32,2,34,0,"&Cancel",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(555,350,120,32,2,34,0,"&Cancel",7,0);
							}
						if (visual_event(1) &  0x20 ) {
		if ((_Context->keycode = on_Cancel_event()) != -1) break;

							}
						continue;
					case	0xc :
						/* AutoSize */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_AutoSize += 1;
							_Context->value_AutoSize &= 1;
							}
						continue;
					case	0xd :
						/* InhibitGif */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_InhibitGif += 1;
							_Context->value_InhibitGif &= 1;
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
				_Context->focus_item=13;
			}
			continue;
		case 0x841 : 
		case 0x861 : 
		/* Accept */
		visual_button(215,350,120,32,2,34,0,"&Accept",7,8);
		visual_button(215,350,120,32,2,34,0,"&Accept",7,0);
		_Context->focus_item=9;
		if ((_Context->keycode = on_Accept_event()) != -1) break;
		continue;
		case 0x853 : 
		case 0x873 : 
		/* Select */
		visual_button(375,350,140,32,2,27,28,"&Select",7,8);
		visual_button(375,350,140,32,2,27,28,"&Select",7,0);
		_Context->focus_item=10;
		if ((_Context->keycode = on_Select_event()) != -1) break;
		continue;
		case 0x843 : 
		case 0x863 : 
		/* Cancel */
		visual_button(555,350,120,32,2,34,0,"&Cancel",7,8);
		visual_button(555,350,120,32,2,34,0,"&Cancel",7,0);
		_Context->focus_item=11;
		if ((_Context->keycode = on_Cancel_event()) != -1) break;
		continue;
		case 0x874 : 
		case 0x894 : 
		/* AutoSize */
		_Context->value_AutoSize += 1;
		_Context->value_AutoSize &= 1;
		_Context->focus_item=12;
		continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_cube_properties( char * pIdentity,char * ptlx,char * ptly,char * ptlz,char * pbrx,char * pbry,char * pbrz,char * pClass,char * pAutoSize,char * pInhibitGif)
{
	int	status=0;
	status = accept_cube_properties_create(  pIdentity, ptlx, ptly, ptlz, pbrx, pbry, pbrz, pClass, pAutoSize, pInhibitGif);
	if ( status != 0) return(status);
	status = accept_cube_properties_show();
		enter_modal();
	status = accept_cube_properties_focus();
		leave_modal();
	status = accept_cube_properties_hide();
	status = accept_cube_properties_remove(  pIdentity, ptlx, ptly, ptlz, pbrx, pbry, pbrz, pClass, pAutoSize, pInhibitGif);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcube_c */
