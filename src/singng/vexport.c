
#ifndef _vexport_c
#define _vexport_c
#include <stdio.h>
#include "visual.h"

private struct on_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_FileName[71];
	char	signature[2];
	} * _Context;

private	int	on_create( char * pFileName)
{
	void * allocate( int );
	if ( initialisepixel(5|256) == -1 )
		return(56);

	else	{
		palette("standard.rgb",12);
		cicopalette(0,0);
if ( font("standard.fmf",12) != 1)
		return(40);

if ( font("font2.fmf",9) != 2)
		return(40);

if ( font("font3.fmf",9) != 3)
		return(40);

if ( font("font4.fmf",9) != 4)
		return(40);

if ( font("font5.fmf",9) != 5)
		return(40);

if ( font("font6.fmf",9) != 6)
		return(40);

if ( font("font7.fmf",9) != 7)
		return(40);

if ( font("font8.fmf",9) != 8)
		return(40);

if ( font("font9.fmf",9) != 9)
		return(40);

	initialise_mouse();
	if (!(_Context = allocate( sizeof( struct on_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=6;
	if ( _Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		transferXsignature(_Context->signature,_Context->signature);
		transferin(_Context->buffer_FileName, 71, pFileName);
		}
	_Context->window_col = 0;
	_Context->window_row = 0;
	return(0);
}

private	int	on_remove( char * pFileName)
{
	void * liberate( void * );
	int	result=_Context->keycode;
	if ( _Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		transferXsignature(_Context->signature,_Context->signature);
		transferout(_Context->buffer_FileName, 71, pFileName);
		}
	_Context = liberate( _Context );
	if ( liberatepixel() == -1 )
		return(56);


	return(result);
}

private	int	on_show()
{
	freeze();
	window(207,303,610,180,2,"Sing : Version 1.0a",19,3);
	frame(217,333,590,140,4);
	button(347,423,100,30,2,26,0,"Edit",4,0);
	button(577,423,100,30,2,27,24,"Select",6,0);
	text(227,353,560,16,2,38,0,"Name of Text File to Export",27,258);
	frame(227,373,570+2,20+2,5);
	text(227+1,373+1,570,20,1,16,24,_Context->buffer_FileName,71,0);
	button(227,423,110,30,2,34,0,"OK",2,0);
	button(687,423,110,30,2,34,0,"CANCEL",6,0);
	frame(467,403,90,60,1);
	text(477,413,70,40,8,27,24,"abcdefghijklmnopqrstuvwxyzabcdefghijklmnop",42,0);
	thaw(207,303,610,180);

	return(0);
}
private int on_UseEdit_event() {
	use_editor(_Context->buffer_FileName,-1);                             
	accept_text_export_show();
	return(-1);
}
private int on_Ok_event() {
	return(13);
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}


private	int	on_event()
{
	int	mx,my,mt,mb;
	if ((mt = visual_event(1)) != _MIMO_UP) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 796 )  
	&&  (my >= 307 )  
	&&  (mx <= 812 )  
	&&  (my <= 323 ))
		return(1);	/* auto6 */

	if (( mx >= 347 ) 
	&&  ( my >= 423 ) 
	&&  ( mx <= 447 ) 
	&&  ( my <= 453 )) 
		return(2); /* UseEdit */
	if (( mx >= 577 ) 
	&&  ( my >= 423 ) 
	&&  ( mx <= 677 ) 
	&&  ( my <= 453 )) 
		return(3); /* Auto740 */
	if (( mx >= 227 ) 
	&&  ( my >= 373 ) 
	&&  ( mx <= 797 ) 
	&&  ( my <= 393 )) 
		return(4); /* FileName */
	if (( mx >= 227 ) 
	&&  ( my >= 423 ) 
	&&  ( mx <= 337 ) 
	&&  ( my <= 453 )) 
		return(5); /* Ok */
	if (( mx >= 687 ) 
	&&  ( my >= 423 ) 
	&&  ( mx <= 797 ) 
	&&  ( my <= 453 )) 
		return(6); /* Cancel */

	return(-1);
}


private	int	on_focus()
{
	while( visual_kbhit() ) (void) visual_getch();
	while(1) {
		switch ( _Context->focus_item ) {
			case	2 :
				/* UseEdit */
				button(347,423,100,30,2,26,0,"Edit",4,2);
				_Context->keycode = visual_getch();
				button(347,423,100,30,2,26,0,"Edit",4,0);
				break;
			case	3 :
				/* Auto740 */
				button(577,423,100,30,2,27,24,"Select",6,2);
				_Context->keycode = visual_getch();
				button(577,423,100,30,2,27,24,"Select",6,0);
				break;
			case	4 :
				/* FileName */
					_Context->keycode = edit(227+1,373+1,570,20,1,_Context->buffer_FileName,71);
				break;
			case	5 :
				/* Ok */
				button(227,423,110,30,2,34,0,"OK",2,2);
				_Context->keycode = visual_getch();
				button(227,423,110,30,2,34,0,"OK",2,0);
				break;
			case	6 :
				/* Cancel */
				button(687,423,110,30,2,34,0,"CANCEL",6,2);
				_Context->keycode = visual_getch();
				button(687,423,110,30,2,34,0,"CANCEL",6,0);
				break;

			default :
				_Context->keycode = 5;

			}
		switch ( _Context->keycode ) {
		case	12 :
			_Context->focus_item=1;
			on_show();
			continue;
		case	2 :
			_Context->focus_item=6;
			on_show();
			continue;
			case	256 :
				switch ((_Context->focus_item = on_event())) {
					case	1 :
						/* auto6 */
			_Context->keycode=27;
			break;
					case	2 :
						/* UseEdit */
	button(347,423,100,30,2,26,0,"Edit",4,8);
		if ((_Context->keycode = on_UseEdit_event()) != -1) break;
						continue;
					case	3 :
						/* Auto740 */
	button(577,423,100,30,2,27,24,"Select",6,8);
						continue;
					case	4 :
						/* FileName */
						continue;
					case	5 :
						/* Ok */
	button(227,423,110,30,2,34,0,"OK",2,8);
		if ((_Context->keycode = on_Ok_event()) != -1) break;
						continue;
					case	6 :
						/* Cancel */
	button(687,423,110,30,2,34,0,"CANCEL",6,8);
		if ((_Context->keycode = on_Cancel_event()) != -1) break;
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
				_Context->focus_item++; 
			} else {
				_Context->focus_item=1; 
			}
			continue;
			case	11 :
			if ( _Context->focus_item > 1 ) {
				_Context->focus_item--; 
			} else {
				_Context->focus_item=6;
			}
			continue;

			}
		break;
		}
	return(0);

}
public	int	main(int argc, char * argv[])
{
	if ( on_create() == 0 ) {
		on_show();
		on_focus();
		ton_remove();
	}
	return(0);

}
/* End of File */

#endif /* _vexport_c */
