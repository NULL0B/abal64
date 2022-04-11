#include <stdio.h>
#include "visual.h"

private struct widget_properties_context {
	char	buffer_auto51[7];
	char	buffer_auto54[7];
	char	buffer_auto56[7];
	char	buffer_auto61[7];
	char	buffer_auto68[16];
	char	buffer_auto69[16];
	char	buffer_auto71[16];
	char	buffer_auto76[54];
	char	buffer_auto78[54];
	char	buffer_auto84[54];
	int keycode;
	} _Context;
private int on_auto93_event() {
	return(13);
	return(-1);
}
private int on_auto94_event() {
	return(27);
	return(-1);
}

private	int	widget_properties_create( char * pptr0,char * pptr1,char * pptr2,char * pptr3,char * pptr4,char * pptr5,char * pptr6,char * pptr7,char * pptr8,char * pptr9)
{
	_Context.keycode=0;
	if ( _Context.keycode != 27 ) {
		transferin(_Context.buffer_auto51, 7, pptr0);
		transferin(_Context.buffer_auto54, 7, pptr1);
		transferin(_Context.buffer_auto56, 7, pptr2);
		transferin(_Context.buffer_auto61, 7, pptr3);
		transferin(_Context.buffer_auto68, 16, pptr4);
		transferin(_Context.buffer_auto69, 16, pptr5);
		transferin(_Context.buffer_auto71, 16, pptr6);
		transferin(_Context.buffer_auto76, 54, pptr7);
		transferin(_Context.buffer_auto78, 54, pptr8);
		transferin(_Context.buffer_auto84, 54, pptr9);
		}
	return(0);
}

private	int	widget_properties_remove( char * pptr0,char * pptr1,char * pptr2,char * pptr3,char * pptr4,char * pptr5,char * pptr6,char * pptr7,char * pptr8,char * pptr9)
{
	if ( _Context.keycode != 27 ) {
		transferout(_Context.buffer_auto51, 7, pptr0);
		transferout(_Context.buffer_auto54, 7, pptr1);
		transferout(_Context.buffer_auto56, 7, pptr2);
		transferout(_Context.buffer_auto61, 7, pptr3);
		transferout(_Context.buffer_auto68, 16, pptr4);
		transferout(_Context.buffer_auto69, 16, pptr5);
		transferout(_Context.buffer_auto71, 16, pptr6);
		transferout(_Context.buffer_auto76, 54, pptr7);
		transferout(_Context.buffer_auto78, 54, pptr8);
		transferout(_Context.buffer_auto84, 54, pptr9);
		}
	return(0);
}

private	int	widget_properties_show()
{
	window(50,20,600,440,2,"Sing : Version 1.0a                     ",40,3);
	frame(60,50,580,400,4);
	text(70,70,560,16,2,34,0,"Widget Properties                       ",40);
	text(70,110,140,16,2,34,0,"Position  ",10);
	text(360,110,140,16,2,34,0,"Dimensions",10);
	frame(200,110,58,18,5);
	text(201,111,56,16,1,34,0,_Context.buffer_auto51,7);
	text(260,110,16,16,1,34,0,", ",2);
	frame(270,110,58,18,5);
	text(271,111,56,16,1,34,0,_Context.buffer_auto54,7);
	text(560,110,16,16,1,34,0,", ",2);
	frame(500,110,58,18,5);
	text(501,111,56,16,1,34,0,_Context.buffer_auto56,7);
	frame(570,110,58,18,5);
	text(571,111,56,16,1,34,0,_Context.buffer_auto61,7);
	text(70,150,126,16,2,34,0,"Text Font",9);
	text(70,180,126,16,2,34,0,"Text Colo",9);
	frame(200,150,130,18,5);
	text(201,151,128,16,1,34,0,_Context.buffer_auto68,16);
	frame(200,180,130,18,5);
	text(201,181,128,16,1,34,0,_Context.buffer_auto69,16);
	text(360,180,126,16,2,34,0,"Backgroun",9);
	frame(500,180,130,18,5);
	text(501,181,128,16,1,34,0,_Context.buffer_auto71,16);
	text(70,220,126,16,2,34,0,"Label    ",9);
	frame(200,220,434,18,5);
	text(201,221,432,16,1,34,0,_Context.buffer_auto76,54);
	text(70,250,126,16,2,34,0,"Identity ",9);
	frame(200,250,434,18,5);
	text(201,251,432,16,1,34,0,_Context.buffer_auto78,54);
	text(70,280,126,16,2,34,0,"Class    ",9);
	frame(200,280,434,18,5);
	text(201,281,432,16,1,34,0,_Context.buffer_auto84,54);
	vline(70,90,630,90,1,34);
	vline(70,310,630,310,1,34);
	button(70,320,120,32,2,34,0,"OK     ",7,0);
	button(510,320,120,32,2,34,0,"CANCEL ",7,0);
	vline(70,360,630,360,1,34);

	return(0);
}

private	int	widget_properties_event()
{
	int	mx,my;
	int	mt,mb;
	if ((mt = get_mimo_type()) != _MIMO_UP) return(-1); 
	mx = get_mimo_column();
	my = get_mimo_row();
	if (( mx >= 200 )
	&&  ( my >= 110 )
	&&  ( mx <= 256 )
	&&  ( my <= 126 ))
		return(0);
	if (( mx >= 270 )
	&&  ( my >= 110 )
	&&  ( mx <= 326 )
	&&  ( my <= 126 ))
		return(1);
	if (( mx >= 500 )
	&&  ( my >= 110 )
	&&  ( mx <= 556 )
	&&  ( my <= 126 ))
		return(2);
	if (( mx >= 570 )
	&&  ( my >= 110 )
	&&  ( mx <= 626 )
	&&  ( my <= 126 ))
		return(3);
	if (( mx >= 200 )
	&&  ( my >= 150 )
	&&  ( mx <= 328 )
	&&  ( my <= 166 ))
		return(4);
	if (( mx >= 200 )
	&&  ( my >= 180 )
	&&  ( mx <= 328 )
	&&  ( my <= 196 ))
		return(5);
	if (( mx >= 500 )
	&&  ( my >= 180 )
	&&  ( mx <= 628 )
	&&  ( my <= 196 ))
		return(6);
	if (( mx >= 200 )
	&&  ( my >= 220 )
	&&  ( mx <= 632 )
	&&  ( my <= 236 ))
		return(7);
	if (( mx >= 200 )
	&&  ( my >= 250 )
	&&  ( mx <= 632 )
	&&  ( my <= 266 ))
		return(8);
	if (( mx >= 200 )
	&&  ( my >= 280 )
	&&  ( mx <= 632 )
	&&  ( my <= 296 ))
		return(9);
	if (( mx >= 70 )
	&&  ( my >= 320 )
	&&  ( mx <= 190 )
	&&  ( my <= 352 ))
		return(10);
	if (( mx >= 510 )
	&&  ( my >= 320 )
	&&  ( mx <= 630 )
	&&  ( my <= 352 ))
		return(11);

	return(-1);
}

private	int	widget_properties_focus()
{
	int	focus_item=0;
	int	focus_items=12;
	while( mimo_kbhit() ) (void) mimo_getch();
	while(1) {
		switch ( focus_item ) {
			case	0 :
					_Context.keycode = edit(201,111,56,16,1,_Context.buffer_auto51,7);
				break;
			case	1 :
					_Context.keycode = edit(271,111,56,16,1,_Context.buffer_auto54,7);
				break;
			case	2 :
					_Context.keycode = edit(501,111,56,16,1,_Context.buffer_auto56,7);
				break;
			case	3 :
					_Context.keycode = edit(571,111,56,16,1,_Context.buffer_auto61,7);
				break;
			case	4 :
					_Context.keycode = edit(201,151,128,16,1,_Context.buffer_auto68,16);
				break;
			case	5 :
					_Context.keycode = edit(201,181,128,16,1,_Context.buffer_auto69,16);
				break;
			case	6 :
					_Context.keycode = edit(501,181,128,16,1,_Context.buffer_auto71,16);
				break;
			case	7 :
					_Context.keycode = edit(201,221,432,16,1,_Context.buffer_auto76,54);
				break;
			case	8 :
					_Context.keycode = edit(201,251,432,16,1,_Context.buffer_auto78,54);
				break;
			case	9 :
					_Context.keycode = edit(201,281,432,16,1,_Context.buffer_auto84,54);
				break;
			case	10 :
				button(70,320,120,32,2,34,0,"OK     ",7,2);
				_Context.keycode = mimo_getch();
				button(70,320,120,32,2,34,0,"OK     ",7,0);
				break;
			case	11 :
				button(510,320,120,32,2,34,0,"CANCEL ",7,2);
				_Context.keycode = mimo_getch();
				button(510,320,120,32,2,34,0,"CANCEL ",7,0);
				break;
			}
		switch ( _Context.keycode ) {
			case	256 :
				switch ((focus_item = widget_properties_event())) {
					case	0 :
						continue;
					case	1 :
						continue;
					case	2 :
						continue;
					case	3 :
						continue;
					case	4 :
						continue;
					case	5 :
						continue;
					case	6 :
						continue;
					case	7 :
						continue;
					case	8 :
						continue;
					case	9 :
						continue;
					case	10 :
		if ((_Context.keycode = on_auto93_event()) != -1) break;
						continue;
					case	11 :
		if ((_Context.keycode = on_auto94_event()) != -1) break;
						continue;
					case	-1 :
					default :
						focus_item=0;
					continue;
					}
				break;
			case	27 :
			case	13 :
				break;
			case	9 :
			case	5 :
				focus_item++; if ( focus_item >= focus_items ) { focus_item=0; } continue;
			case	11 :
				if ( focus_item <=0 ) { focus_item = focus_items; } focus_item--; continue;
			}
		break;
		}
	return(0);
}

public	int	widget_properties( char * pptr0,char * pptr1,char * pptr2,char * pptr3,char * pptr4,char * pptr5,char * pptr6,char * pptr7,char * pptr8,char * pptr9)
{
	widget_properties_create(pptr0,pptr1,pptr2,pptr3,pptr4,pptr5,pptr6,pptr7,pptr8,pptr9);
	widget_properties_show();
	widget_properties_focus();
	widget_properties_remove(pptr0,pptr1,pptr2,pptr3,pptr4,pptr5,pptr6,pptr7,pptr8,pptr9);
	return(_Context.keycode);
}
/* End of File */
