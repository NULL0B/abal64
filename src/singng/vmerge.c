#include <stdio.h>
#include "visual.h"

private struct accept_mergename_context {
	int keycode;
	int focus_item;
	int focus_items;
	char	buffer_auto9[70];
	} _Context;
private int on_Ok_event() {
	return(13);
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}

private	int	accept_mergename_create( char * pptr0)
{
	_Context.keycode=0;
	_Context.focus_item=0;
	_Context.focus_items=1;
	if ( _Context.keycode != 27 ) {
		visual_transferin(_Context.buffer_auto9, 70, pptr0);
		}
	return(0);
}

private	int	accept_mergename_remove( char * pptr0)
{
	if ( _Context.keycode != 27 ) {
		visual_transferout(_Context.buffer_auto9, 70, pptr0);
		}
	return(0);
}

private	int	accept_mergename_show()
{
	visual_window(60,160,600,210,2,"Sing : Version 1.0a",19,3);
	visual_frame(70,190,580,170,4);
	visual_text(80,200,560,16,2,38,0,"Name of File to Merge",21);
	visual_frame(80,220,562,18,5);
	visual_text(81,221,560,16,1,16,24,_Context.buffer_auto9,70);
	visual_button(80,310,120,30,2,34,0,"OK",2,0);
	visual_button(520,310,120,30,2,34,0,"CANCEL",6,0);

	return(0);
}

private	int	accept_mergename_event()
{
	int	mx,my;
	int	mt,mb;
	if ((mt = get_mimo_type()) != _MIMO_UP) return(-1); 
	mx = get_mimo_column();
	my = get_mimo_row();
	if (( mx >= 80 )
	&&  ( my >= 220 )
	&&  ( mx <= 640 )
	&&  ( my <= 236 ))
		return(0);
	if (( mx >= 80 )
	&&  ( my >= 310 )
	&&  ( mx <= 200 )
	&&  ( my <= 340 ))
		return(1);
	if (( mx >= 520 )
	&&  ( my >= 310 )
	&&  ( mx <= 640 )
	&&  ( my <= 340 ))
		return(2);

	return(-1);
}

private	int	accept_mergename_focus()
{
	while( mimo_kbhit() ) (void) mimo_getch();
	while(1) {
		switch ( _Context.focus_item ) {
			case	0 :
				_Context.keycode = visual_edit(81,221,560,16,1,_Context.buffer_auto9,70);
				break;
			case	1 :
				visual_button(80,310,120,30,2,34,0,"OK",2,2);
				_Context.keycode = mimo_getch();
				visual_button(80,310,120,30,2,34,0,"OK",2,0);
				break;
			case	2 :
				visual_button(520,310,120,30,2,34,0,"CANCEL",6,2);
				_Context.keycode = mimo_getch();
				visual_button(520,310,120,30,2,34,0,"CANCEL",6,0);
				break;
			}
		switch ( _Context.keycode ) {
			case	256 :
				switch ((_Context.focus_item = accept_mergename_event())) {
					case	0 :
						continue;
					case	1 :
		if ((_Context.keycode = on_Ok_event()) != -1) break;
						continue;
					case	2 :
		if ((_Context.keycode = on_Cancel_event()) != -1) break;
						continue;
					case	-1 :
					default :
						_Context.focus_item=0;
					continue;
					}
				break;
			case	27 :
			case	13 :
				break;
			case	9 :
			case	5 :
				_Context.focus_item++; if ( _Context.focus_item >= _Context.focus_items ) { _Context.focus_item=0; } continue;
			case	11 :
				if ( _Context.focus_item <=0 ) { _Context.focus_item = _Context.focus_items; } _Context.focus_item--; continue;
			}
		break;
		}
	return(0);
}

public	int	accept_mergename( char * pptr0)
{
	accept_mergename_create(pptr0);
	accept_mergename_show();
	accept_mergename_focus();
	accept_mergename_remove(pptr0);
	return(_Context.keycode);
}
/* End of File */
