
#ifndef _ctest_c
#define _ctest_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.01  */
/* Production     : C  */
/* Project        : ctest.sng  */
/* Target         : ctest.c  */
/* Identification : 0.0-1051298768-2591.2590 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "cico.c"

private struct on_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_Auto245[27];
	char	buffer_Edith[30];
	int	value_Tchek;
	char	signature[4];
	} * _Context;
private int on_Edith_create() {
	strcpy(_Context->buffer_Edith,"create");
	return(-1);
}

private	int	on_create( char * pAuto245,char * pEdith,char * pTchek)
{

	if ( visual_initialise(3|256) == -1 )
		return(56);

	else	{
		visual_palette("/home/abal3/images/foret.rgb",28);
		cicopalette(0,0);
		if ( visual_font("standard.fmf",12) != 1)
			return(40);

		if ( visual_font("font2.fmf",9) != 2)
			return(40);

		if ( visual_font("font3.fmf",9) != 3)
			return(40);

		if ( visual_font("font4.fmf",9) != 4)
			return(40);

		if ( visual_font("font5.fmf",9) != 5)
			return(40);

		if ( visual_font("font6.fmf",9) != 6)
			return(40);

		if ( visual_font("font7.fmf",9) != 7)
			return(40);

		if ( visual_font("font8.fmf",9) != 8)
			return(40);

		if ( visual_font("font9.fmf",9) != 9)
			return(40);

		initialise_mouse();
		}
	if (!(_Context = allocate( sizeof( struct on_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=11;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Auto245, 27, pAuto245);
		visual_transferin(_Context->buffer_Edith, 30, pEdith);
		visual_transferin((void *) 0, 0, pTchek);
		if (!( pTchek )) _Context->value_Tchek=0;
		else	_Context->value_Tchek = *((int *)pTchek);
		}
	_Context->window_col=0;
	_Context->window_row=0;
		(void) on_Edith_create();
	return(0);
}
private int on_Edith_hide() {
	strcpy(_Context->buffer_Edith,"hide");
	return(-1);
}

private	int	on_hide()
{
		(void) on_Edith_hide();

	return(0);
}
private int on_Edith_remove() {
	strcpy(_Context->buffer_Edith,"remove");
	return(-1);
}

private	int	on_remove( char * pAuto245,char * pEdith,char * pTchek)
{

	int	result=_Context->keycode;
		(void) on_Edith_remove();
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Auto245, 27, pAuto245);
		visual_transferout(_Context->buffer_Edith, 30, pEdith);
		visual_transferout((void *) 0, 0, pTchek);
		if ( pTchek != (char *) 0)
			*((int*)pTchek) = _Context->value_Tchek;
		}
	_Context=liberate(_Context);

	if ( visual_liberate() == -1 )
		return(56);


	return(result);
}
private int on_Edith_show() {
	_Context->value_Tchek=1;
	return(-1);
}
private int on_Auto214_show() {
	return(-1);
}

private	int	on_show()
{
	visual_freeze();
	visual_window(0,0,328,192,1,"Sing : Version 1.0a",19,3);
	visual_frame(8,32,24+2,144+2,5);
	visual_text(8+1,32+1,24,144,1,0,0,_Context->buffer_Auto245,27,0);
	visual_frame(40,32,240+2,16+2,5);
	visual_text(40+1,32+1,240,16,1,16,24,_Context->buffer_Edith,30,0);
		(void) on_Edith_show();
	visual_button(40,64,80,32,2,16,24,"Create",6,0);
		(void) on_Auto214_show();
	visual_button(120,64,80,32,2,16,24,"Show",4,0);
	visual_button(40,96,80,32,2,16,24,"GetFocus",8,0);
	visual_button(120,96,80,32,2,16,24,"Event",5,0);
	visual_button(120,128,80,32,2,16,24,"Hide",4,0);
	visual_button(200,128,80,32,2,16,24,"Remove",6,0);
	visual_check(40,144,72,16,1,16,24,"ABCDE",5,_Context->value_Tchek);
	visual_button(200,96,80,32,2,16,24,"LoseFocus",9,0);
	visual_thaw(0,0,328,192);

	return(0);
}
private int on_Edith_event() {
	strcpy(_Context->buffer_Edith,"event");
	return(-1);
}
private int on_Auto214_event() {
	on_Edith_create();
		visual_frame(40,32,240+2,16+2,5);
	visual_text(40+1,32+1,240,16,1,16,24,_Context->buffer_Edith,30,0);
		(void) on_Edith_show();
;
	return(-1);
}
private int on_Auto215_event() {
	on_Edith_show();
		visual_frame(40,32,240+2,16+2,5);
	visual_text(40+1,32+1,240,16,1,16,24,_Context->buffer_Edith,30,0);
		(void) on_Edith_show();
;
	return(-1);
}
private int on_Auto216_event() {
	on_Edith_getfocus();
		visual_frame(40,32,240+2,16+2,5);
	visual_text(40+1,32+1,240,16,1,16,24,_Context->buffer_Edith,30,0);
		(void) on_Edith_show();
;
	return(-1);
}
private int on_Auto217_event() {
	on_Edith_event();
		visual_frame(40,32,240+2,16+2,5);
	visual_text(40+1,32+1,240,16,1,16,24,_Context->buffer_Edith,30,0);
		(void) on_Edith_show();
;
	return(-1);
}
private int on_Auto218_event() {
	on_Edith_hide();
		visual_frame(40,32,240+2,16+2,5);
	visual_text(40+1,32+1,240,16,1,16,24,_Context->buffer_Edith,30,0);
		(void) on_Edith_show();
;
	return(-1);
}
private int on_Auto220_event() {
	on_Edith_remove();
		visual_frame(40,32,240+2,16+2,5);
	visual_text(40+1,32+1,240,16,1,16,24,_Context->buffer_Edith,30,0);
		(void) on_Edith_show();
;
	return(-1);
}
private int on_Auto219_event() {
	on_Edith_losefocus();
		visual_frame(40,32,240+2,16+2,5);
	visual_text(40+1,32+1,240,16,1,16,24,_Context->buffer_Edith,30,0);
		(void) on_Edith_show();
;
	return(-1);
}


private	int	on_event()
{
	int	mx,my,mt,mb;
	if ((mt = visual_event(1)) != _MIMO_UP) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 307 )  
	&&  (my >= 4 )  
	&&  (mx <= 323 )  
	&&  (my <= 20 ))
		return(1);	/* Auto212 */

	if (( mx >= 8 ) 
	&&  ( my >= 32 ) 
	&&  ( mx <= 32 ) 
	&&  ( my <= 176 )) 
		return(2); /* Auto245 */
	if (( mx >= 40 ) 
	&&  ( my >= 32 ) 
	&&  ( mx <= 280 ) 
	&&  ( my <= 48 )) 
		return(3); /* Edith */
	if (( mx >= 40 ) 
	&&  ( my >= 64 ) 
	&&  ( mx <= 120 ) 
	&&  ( my <= 96 )) 
		return(4); /* Auto214 */
	if (( mx >= 120 ) 
	&&  ( my >= 64 ) 
	&&  ( mx <= 200 ) 
	&&  ( my <= 96 )) 
		return(5); /* Auto215 */
	if (( mx >= 40 ) 
	&&  ( my >= 96 ) 
	&&  ( mx <= 120 ) 
	&&  ( my <= 128 )) 
		return(6); /* Auto216 */
	if (( mx >= 120 ) 
	&&  ( my >= 96 ) 
	&&  ( mx <= 200 ) 
	&&  ( my <= 128 )) 
		return(7); /* Auto217 */
	if (( mx >= 120 ) 
	&&  ( my >= 128 ) 
	&&  ( mx <= 200 ) 
	&&  ( my <= 160 )) 
		return(8); /* Auto218 */
	if (( mx >= 200 ) 
	&&  ( my >= 128 ) 
	&&  ( mx <= 280 ) 
	&&  ( my <= 160 )) 
		return(9); /* Auto220 */
	if (( mx >= 40 ) 
	&&  ( my >= 144 ) 
	&&  ( mx <= 112 ) 
	&&  ( my <= 160 )) 
		return(10); /* Tchek */
	if (( mx >= 200 ) 
	&&  ( my >= 96 ) 
	&&  ( mx <= 280 ) 
	&&  ( my <= 128 )) 
		return(11); /* Auto219 */

	return(-1);
}
private int on_Edith_losefocus() {
	strcpy(_Context->buffer_Edith,"losefocus");
	return(-1);
}
private int on_Edith_getfocus() {
	strcpy(_Context->buffer_Edith,"getfocus");
	return(-1);
}


private	int	on_focus()
{

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	2 :
				/* Auto245 */
					_Context->keycode = visual_edit(8+1,32+1,24,144,1,_Context->buffer_Auto245,27);
				break;
			case	3 :
				/* Edith */
		if ((_Context->keycode = on_Edith_getfocus()) != -1) break;
		(void) on_Edith_losefocus();
				break;
			case	4 :
				/* Auto214 */
				visual_button(40,64,80,32,2,16,24,"Create",6,2);
				_Context->keycode = visual_getch();
				visual_button(40,64,80,32,2,16,24,"Create",6,0);
				break;
			case	5 :
				/* Auto215 */
				visual_button(120,64,80,32,2,16,24,"Show",4,2);
				_Context->keycode = visual_getch();
				visual_button(120,64,80,32,2,16,24,"Show",4,0);
				break;
			case	6 :
				/* Auto216 */
				visual_button(40,96,80,32,2,16,24,"GetFocus",8,2);
				_Context->keycode = visual_getch();
				visual_button(40,96,80,32,2,16,24,"GetFocus",8,0);
				break;
			case	7 :
				/* Auto217 */
				visual_button(120,96,80,32,2,16,24,"Event",5,2);
				_Context->keycode = visual_getch();
				visual_button(120,96,80,32,2,16,24,"Event",5,0);
				break;
			case	8 :
				/* Auto218 */
				visual_button(120,128,80,32,2,16,24,"Hide",4,2);
				_Context->keycode = visual_getch();
				visual_button(120,128,80,32,2,16,24,"Hide",4,0);
				break;
			case	9 :
				/* Auto220 */
				visual_button(200,128,80,32,2,16,24,"Remove",6,2);
				_Context->keycode = visual_getch();
				visual_button(200,128,80,32,2,16,24,"Remove",6,0);
				break;
			case	10 :
				/* Tchek */
				visual_check(40,144,72,16,1,16,24,"ABCDE",5,(_Context->value_Tchek |2));
				_Context->keycode = visual_getch();
				visual_check(40,144,72,16,1,16,24,"ABCDE",5,_Context->value_Tchek);
				break;
			case	11 :
				/* Auto219 */
				visual_button(200,96,80,32,2,16,24,"LoseFocus",9,2);
				_Context->keycode = visual_getch();
				visual_button(200,96,80,32,2,16,24,"LoseFocus",9,0);
				break;

			default :
				_Context->keycode = 5;

			}
		switch (_Context->keycode ) {
		case	12 :
			_Context->focus_item=1;
			on_show();
			continue;
		case	2 :
			_Context->focus_item=11;
			on_show();
			continue;
			case	256 :
				switch ((_Context->focus_item = on_event())) {
					case	1 :
						/* Auto212 */
			_Context->keycode=27;
			break;
					case	2 :
						/* Auto245 */
						continue;
					case	3 :
						/* Edith */
		if ((_Context->keycode = on_Edith_event()) != -1) break;
						continue;
					case	4 :
						/* Auto214 */
	visual_button(40,64,80,32,2,16,24,"Create",6,8);
		if ((_Context->keycode = on_Auto214_event()) != -1) break;
						continue;
					case	5 :
						/* Auto215 */
	visual_button(120,64,80,32,2,16,24,"Show",4,8);
		if ((_Context->keycode = on_Auto215_event()) != -1) break;
						continue;
					case	6 :
						/* Auto216 */
	visual_button(40,96,80,32,2,16,24,"GetFocus",8,8);
		if ((_Context->keycode = on_Auto216_event()) != -1) break;
						continue;
					case	7 :
						/* Auto217 */
	visual_button(120,96,80,32,2,16,24,"Event",5,8);
		if ((_Context->keycode = on_Auto217_event()) != -1) break;
						continue;
					case	8 :
						/* Auto218 */
	visual_button(120,128,80,32,2,16,24,"Hide",4,8);
		if ((_Context->keycode = on_Auto218_event()) != -1) break;
						continue;
					case	9 :
						/* Auto220 */
	visual_button(200,128,80,32,2,16,24,"Remove",6,8);
		if ((_Context->keycode = on_Auto220_event()) != -1) break;
						continue;
					case	10 :
						/* Tchek */
						_Context->value_Tchek += 1;
						_Context->value_Tchek &= 1;
						continue;
					case	11 :
						/* Auto219 */
	visual_button(200,96,80,32,2,16,24,"LoseFocus",9,8);
		if ((_Context->keycode = on_Auto219_event()) != -1) break;
						continue;
					case	-1 :
					default :
						_Context->focus_item=1;
					continue;
					}
				break;
			case	27 :
			case	13 :
				break;
			case	9 :
			case	5 :
			if ( _Context->focus_item < _Context->focus_items ) {
				_Context->focus_item++;			} else {
				_Context->focus_item=1;
			}
			continue;
			case	11 :
			if ( _Context->focus_item > 1 ) {
				_Context->focus_item--;
			} else {
				_Context->focus_item=11;
			}
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}
public	int	main(int argc, char * argv[])
{
	set_configuration_name(argv[0]);
	if ( on_create(0,0,0) == 0 ) {
		on_show();
		on_focus();
		on_hide();
		on_remove(0,0,0);
		}
	return(0);

}
/* End of File */

#endif /* _ctest_c */
