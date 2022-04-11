
#ifndef _vnation_c
#define _vnation_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vnation.sng  */
/* Target         : vnation.c  */
/* Identification : 0.0-1065231656-3027.3026 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_widget_messages_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	focus_pages[8+1];
	int	page_number;
	char	buffer_English[1841];
	char	buffer_Francais[1841];
	char	buffer_Italiano[1841];
	char	buffer_Espagnol[1841];
	char	buffer_Deutsch[1921];
	char	buffer_Nederlands[1841];
	char	buffer_Portugues[1841];
	char	buffer_Other[1841];
	char	signature[9];
	} * _Context;

private	int	accept_widget_messages_create(
	char * pEnglish,
	char * pFrancais,
	char * pItaliano,
	char * pEspagnol,
	char * pDeutsch,
	char * pNederlands,
	char * pPortugues,
	char * pOther)
{

	if (!(_Context = allocate( sizeof( struct accept_widget_messages_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=20;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_English, 1840, pEnglish);
		visual_transferin(_Context->buffer_Francais, 1840, pFrancais);
		visual_transferin(_Context->buffer_Italiano, 1840, pItaliano);
		visual_transferin(_Context->buffer_Espagnol, 1840, pEspagnol);
		visual_transferin(_Context->buffer_Deutsch, 1920, pDeutsch);
		visual_transferin(_Context->buffer_Nederlands, 1840, pNederlands);
		visual_transferin(_Context->buffer_Portugues, 1840, pPortugues);
		visual_transferin(_Context->buffer_Other, 1840, pOther);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->focus_pages[1]=5;
	_Context->focus_pages[2]=7;
	_Context->focus_pages[3]=9;
	_Context->focus_pages[4]=11;
	_Context->focus_pages[5]=13;
	_Context->focus_pages[6]=15;
	_Context->focus_pages[7]=17;
	_Context->focus_pages[8]=19;
	return(0);
}

private	int	accept_widget_messages_hide()
{

	return(0);
}

private	int	accept_widget_messages_remove(
	char * pEnglish,
	char * pFrancais,
	char * pItaliano,
	char * pEspagnol,
	char * pDeutsch,
	char * pNederlands,
	char * pPortugues,
	char * pOther)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_English, 1840, pEnglish);
		visual_transferout(_Context->buffer_Francais, 1840, pFrancais);
		visual_transferout(_Context->buffer_Italiano, 1840, pItaliano);
		visual_transferout(_Context->buffer_Espagnol, 1840, pEspagnol);
		visual_transferout(_Context->buffer_Deutsch, 1920, pDeutsch);
		visual_transferout(_Context->buffer_Nederlands, 1840, pNederlands);
		visual_transferout(_Context->buffer_Portugues, 1840, pPortugues);
		visual_transferout(_Context->buffer_Other, 1840, pOther);
		}
	_Context=liberate(_Context);

	return(result);
}

private	int	accept_widget_messages_show()
{
	visual_freeze();
	visual_window(60,35,680,530,1,"Sing : Version 1.0a",19,0x403);
	visual_image(63,57,674,504,"skin.gif",4);
	visual_button(70,525,140,32,2,16,0,"Accept",6,0);
	visual_button(340,525,136,32,2,0,0,"Copy",4,0);
	visual_button(590,525,140,32,2,16,0,"Cancel",6,0);
	visual_text(70,59,625,22,4,16,0,"International Message Editor",28,1283);
	if (_Context->page_number == 1 ) {
	visual_tabpage(70,85,660,430,2,"English",7,0,34);
	} else {
		visual_tabpage(70,85,660,430,2,"English",7,0,32);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(80,125,640+2,368+2,5);
	visual_text(80+1,125+1,640,368,1,27,28,_Context->buffer_English,1840,0);
		}
	if (_Context->page_number == 2 ) {
	visual_tabpage(70,85,660,430,2,"Fran‡ais",8,72,34);
	} else {
		visual_tabpage(70,85,660,430,2,"Fran‡ais",8,72,32);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(80,125,640+2,368+2,5);
	visual_text(80+1,125+1,640,368,1,16,0,_Context->buffer_Francais,1840,0);
		}
	if (_Context->page_number == 3 ) {
	visual_tabpage(70,85,660,430,2,"Italiano",8,152,34);
	} else {
		visual_tabpage(70,85,660,430,2,"Italiano",8,152,32);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(80,125,640+2,368+2,5);
	visual_text(80+1,125+1,640,368,1,16,0,_Context->buffer_Italiano,1840,0);
		}
	if (_Context->page_number == 4 ) {
	visual_tabpage(70,85,660,430,2,"Espagnol",8,223,34);
	} else {
		visual_tabpage(70,85,660,430,2,"Espagnol",8,223,32);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(80,125,640+2,368+2,5);
	visual_text(80+1,125+1,640,368,1,16,0,_Context->buffer_Espagnol,1840,0);
		}
	if (_Context->page_number == 5 ) {
	visual_tabpage(70,85,660,430,2,"Deutsch",7,306,34);
	} else {
		visual_tabpage(70,85,660,430,2,"Deutsch",7,306,32);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(80,115,640+2,384+2,5);
	visual_text(80+1,115+1,640,384,1,16,0,_Context->buffer_Deutsch,1920,0);
		}
	if (_Context->page_number == 6 ) {
	visual_tabpage(70,85,660,430,2,"Nederlands",10,384,34);
	} else {
		visual_tabpage(70,85,660,430,2,"Nederlands",10,384,32);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(80,125,640+2,368+2,5);
	visual_text(80+1,125+1,640,368,1,16,0,_Context->buffer_Nederlands,1840,0);
		}
	if (_Context->page_number == 7 ) {
	visual_tabpage(70,85,660,430,2,"Portugues",9,479,34);
	} else {
		visual_tabpage(70,85,660,430,2,"Portugues",9,479,32);
		}
	if (_Context->page_number == 7 ) {
	visual_frame(80,125,640+2,368+2,5);
	visual_text(80+1,125+1,640,368,1,16,0,_Context->buffer_Portugues,1840,0);
		}
	if (_Context->page_number == 8 ) {
	visual_tabpage(70,85,660,430,2,"Other",5,569,34);
	} else {
		visual_tabpage(70,85,660,430,2,"Other",5,569,32);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(80,125,640+2,368+2,5);
	visual_text(80+1,125+1,640,368,1,16,0,_Context->buffer_Other,1840,0);
		}
	visual_thaw(60,35,680,530);

	return(0);
}
private int on_Auto6315_event() {
	return(13);
	return(-1);
}
private int on_Auto6982_event() {
	if(_Context->buffer_Francais[0]==' '){
	memcpy(_Context->buffer_Francais,_Context->buffer_English,1840);
	}
	if(_Context->buffer_Italiano[0]==' '){
	memcpy(_Context->buffer_Italiano,_Context->buffer_English,1840);
	}
	if(_Context->buffer_Espagnol[0]==' '){
	memcpy(_Context->buffer_Espagnol,_Context->buffer_English,1840);
	}
	if(_Context->buffer_Deutsch[0]==' '){
	memcpy(_Context->buffer_Deutsch,_Context->buffer_English,1840);
	}
	if(_Context->buffer_Nederlands[0]==' '){
	memcpy(_Context->buffer_Nederlands,_Context->buffer_English,1840);
	}
	if(_Context->buffer_Portugues[0]==' '){
	memcpy(_Context->buffer_Portugues,_Context->buffer_English,1840);
	}
	if(_Context->buffer_Other[0]==' '){
	memcpy(_Context->buffer_Other,_Context->buffer_English,1840);
	}
	return(-1);
}
private int on_Auto6316_event() {
	return(27);
	return(-1);
}


private	int	accept_widget_messages_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 719 )  
	&&  (my >= 39 )  
	&&  (mx <= 735 )  
	&&  (my <= 55 )) {
		return(1);	/* Auto6300 */

		}
	if ((mx >= 703 )  
	&&  (my >= 39 )  
	&&  (mx <= 719 )  
	&&  (my <= 55 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vnation.htm");
			};
		return(-1);	/* Auto6300 */

		}
	if (( mx >= 70 ) 
	&&  ( my >= 525 ) 
	&&  ( mx <= 210 ) 
	&&  ( my <= 557 )) {
		return(2); /* Auto6315 */
		}
	if (( mx >= 340 ) 
	&&  ( my >= 525 ) 
	&&  ( mx <= 476 ) 
	&&  ( my <= 557 )) {
		return(3); /* Auto6982 */
		}
	if (( mx >= 590 ) 
	&&  ( my >= 525 ) 
	&&  ( mx <= 730 ) 
	&&  ( my <= 557 )) {
		return(4); /* Auto6316 */
		}
	if (_Context->page_number == 1 ) {
	} else {
		if ((mx >= 70 ) 
		&&  (my >= 85 ) 
		&&  (mx <= 141 ) 
		&&  (my <= 109 )) {
			return(5); /* Auto6304 */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 125 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 493 )) {
			return(6); /* English */
		}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if ((mx >= 142 ) 
		&&  (my >= 85 ) 
		&&  (mx <= 221 ) 
		&&  (my <= 109 )) {
			return(7); /* Auto6305 */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 125 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 493 )) {
			return(8); /* Francais */
		}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if ((mx >= 222 ) 
		&&  (my >= 85 ) 
		&&  (mx <= 292 ) 
		&&  (my <= 109 )) {
			return(9); /* Auto6306 */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 125 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 493 )) {
			return(10); /* Italiano */
		}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if ((mx >= 293 ) 
		&&  (my >= 85 ) 
		&&  (mx <= 375 ) 
		&&  (my <= 109 )) {
			return(11); /* Auto6307 */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 125 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 493 )) {
			return(12); /* Espagnol */
		}
		}
	if (_Context->page_number == 5 ) {
	} else {
		if ((mx >= 376 ) 
		&&  (my >= 85 ) 
		&&  (mx <= 453 ) 
		&&  (my <= 109 )) {
			return(13); /* Auto6308 */
		}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 115 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 499 )) {
			return(14); /* Deutsch */
		}
		}
	if (_Context->page_number == 6 ) {
	} else {
		if ((mx >= 454 ) 
		&&  (my >= 85 ) 
		&&  (mx <= 548 ) 
		&&  (my <= 109 )) {
			return(15); /* Auto6309 */
		}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 125 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 493 )) {
			return(16); /* Nederlands */
		}
		}
	if (_Context->page_number == 7 ) {
	} else {
		if ((mx >= 549 ) 
		&&  (my >= 85 ) 
		&&  (mx <= 638 ) 
		&&  (my <= 109 )) {
			return(17); /* Auto6310 */
		}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 125 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 493 )) {
			return(18); /* Portugues */
		}
		}
	if (_Context->page_number == 8 ) {
	} else {
		if ((mx >= 639 ) 
		&&  (my >= 85 ) 
		&&  (mx <= 711 ) 
		&&  (my <= 109 )) {
			return(19); /* Auto6933 */
		}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 125 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 493 )) {
			return(20); /* Other */
		}
		}

	return(-1);
}


private	int	accept_widget_messages_losefocus()
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;
		case 3 : 
			break;
		case 4 : 
			break;
		case 5 : 
			break;
		case 6 : 
			break;
		case 7 : 
			break;
		case 8 : 
			break;

		}
	return(0);

}


private	int	accept_widget_messages_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto6315 */
				visual_button(70,525,140,32,2,16,0,"Accept",6,2);
				_Context->keycode = visual_getch();
				visual_button(70,525,140,32,2,16,0,"Accept",6,0);
				break;
			case	0x3 :
				/* Auto6982 */
				visual_button(340,525,136,32,2,0,0,"Copy",4,2);
				_Context->keycode = visual_getch();
				visual_button(340,525,136,32,2,0,0,"Copy",4,0);
				break;
			case	0x4 :
				/* Auto6316 */
				visual_button(590,525,140,32,2,16,0,"Cancel",6,2);
				_Context->keycode = visual_getch();
				visual_button(590,525,140,32,2,16,0,"Cancel",6,0);
				break;
			case	0x5 :
				/* Auto6304 */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x6 :
				/* English */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(80+1,125+1,640,368,1,_Context->buffer_English,1840);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* Auto6305 */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x8 :
				/* Francais */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(80+1,125+1,640,368,1,_Context->buffer_Francais,1840);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* Auto6306 */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xa :
				/* Italiano */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(80+1,125+1,640,368,1,_Context->buffer_Italiano,1840);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* Auto6307 */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xc :
				/* Espagnol */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(80+1,125+1,640,368,1,_Context->buffer_Espagnol,1840);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* Auto6308 */
				if (_Context->page_number == 5 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xe :
				/* Deutsch */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(80+1,115+1,640,384,1,_Context->buffer_Deutsch,1920);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* Auto6309 */
				if (_Context->page_number == 6 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x10 :
				/* Nederlands */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_edit(80+1,125+1,640,368,1,_Context->buffer_Nederlands,1840);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* Auto6310 */
				if (_Context->page_number == 7 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x12 :
				/* Portugues */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_edit(80+1,125+1,640,368,1,_Context->buffer_Portugues,1840);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* Auto6933 */
				if (_Context->page_number == 8 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x14 :
				/* Other */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_edit(80+1,125+1,640,368,1,_Context->buffer_Other,1840);
				} else {
					_Context->keycode = 5;
					}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			accept_widget_messages_losefocus();
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_widget_messages_show();
			continue;
		case	0x2 :
			accept_widget_messages_losefocus();
			_Context->page_number=8;
			_Context->focus_item=20;
			accept_widget_messages_show();
			continue;
		case	0x3 :
			accept_widget_messages_losefocus();
			if ( _Context->page_number < 8 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_widget_messages_show();
			continue;
		case	0x12 :
			accept_widget_messages_losefocus();
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_widget_messages_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_widget_messages_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto6300 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Auto6315 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(70,525,140,32,2,16,0,"Accept",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(70,525,140,32,2,16,0,"Accept",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto6315_event()) != -1) break;

							}
						continue;
					case	0x3 :
						/* Auto6982 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(340,525,136,32,2,0,0,"Copy",4,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(340,525,136,32,2,0,0,"Copy",4,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto6982_event()) != -1) break;

							}
						continue;
					case	0x4 :
						/* Auto6316 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(590,525,140,32,2,16,0,"Cancel",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(590,525,140,32,2,16,0,"Cancel",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto6316_event()) != -1) break;

							}
						continue;
					case	0x5 :
						/* Auto6304 */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_messages_losefocus();
							_Context->page_number = 1;
							accept_widget_messages_show();
							}
						continue;
					case	0x6 :
						/* English */
						continue;
					case	0x7 :
						/* Auto6305 */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_messages_losefocus();
							_Context->page_number = 2;
							accept_widget_messages_show();
							}
						continue;
					case	0x8 :
						/* Francais */
						continue;
					case	0x9 :
						/* Auto6306 */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_messages_losefocus();
							_Context->page_number = 3;
							accept_widget_messages_show();
							}
						continue;
					case	0xa :
						/* Italiano */
						continue;
					case	0xb :
						/* Auto6307 */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_messages_losefocus();
							_Context->page_number = 4;
							accept_widget_messages_show();
							}
						continue;
					case	0xc :
						/* Espagnol */
						continue;
					case	0xd :
						/* Auto6308 */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_messages_losefocus();
							_Context->page_number = 5;
							accept_widget_messages_show();
							}
						continue;
					case	0xe :
						/* Deutsch */
						continue;
					case	0xf :
						/* Auto6309 */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_messages_losefocus();
							_Context->page_number = 6;
							accept_widget_messages_show();
							}
						continue;
					case	0x10 :
						/* Nederlands */
						continue;
					case	0x11 :
						/* Auto6310 */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_messages_losefocus();
							_Context->page_number = 7;
							accept_widget_messages_show();
							}
						continue;
					case	0x12 :
						/* Portugues */
						continue;
					case	0x13 :
						/* Auto6933 */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_messages_losefocus();
							_Context->page_number = 8;
							accept_widget_messages_show();
							}
						continue;
					case	0x14 :
						/* Other */
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
				_Context->focus_item=20;
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

public	int	accept_widget_messages(
	char * pEnglish,
	char * pFrancais,
	char * pItaliano,
	char * pEspagnol,
	char * pDeutsch,
	char * pNederlands,
	char * pPortugues,
	char * pOther)
{
	int	status=0;
	status = accept_widget_messages_create(
	 pEnglish,
	 pFrancais,
	 pItaliano,
	 pEspagnol,
	 pDeutsch,
	 pNederlands,
	 pPortugues,
	 pOther);
	if ( status != 0) return(status);
	status = accept_widget_messages_show();
		enter_modal();
	status = accept_widget_messages_focus();
		leave_modal();
	status = accept_widget_messages_hide();
	status = accept_widget_messages_remove(
	 pEnglish,
	 pFrancais,
	 pItaliano,
	 pEspagnol,
	 pDeutsch,
	 pNederlands,
	 pPortugues,
	 pOther);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vnation_c */
