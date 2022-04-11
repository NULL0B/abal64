
#ifndef _vhelper_c
#define _vhelper_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vhelper.sng  */
/* Target         : vhelper.c  */
/* Identification : 0.0-1065019002-2581.2580 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_help_messages_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	focus_pages[8+1];
	int	page_number;
	char * buffer_English;
	char * buffer_Francais;
	char * buffer_Italiano;
	char * buffer_Espagnol;
	char * buffer_Deutsch;
	char * buffer_Nederlands;
	char * buffer_Portugues;
	char * buffer_Other;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[9];
	} * _Context;

private	int	accept_help_messages_create(
	char * pEnglish,
	char * pFrancais,
	char * pItaliano,
	char * pEspagnol,
	char * pDeutsch,
	char * pNederlands,
	char * pPortugues,
	char * pOther)
{

	if (!(_Context = allocate( sizeof( struct accept_help_messages_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=20;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"TTTTTTTT");
		visual_signature(_Context->signature,_Context->signature);
				_Context->buffer_English=(char *) 0;
		visual_transferin(&_Context->buffer_English, 1840, pEnglish);
				_Context->buffer_Francais=(char *) 0;
		visual_transferin(&_Context->buffer_Francais, 1840, pFrancais);
				_Context->buffer_Italiano=(char *) 0;
		visual_transferin(&_Context->buffer_Italiano, 1840, pItaliano);
				_Context->buffer_Espagnol=(char *) 0;
		visual_transferin(&_Context->buffer_Espagnol, 1840, pEspagnol);
				_Context->buffer_Deutsch=(char *) 0;
		visual_transferin(&_Context->buffer_Deutsch, 1840, pDeutsch);
				_Context->buffer_Nederlands=(char *) 0;
		visual_transferin(&_Context->buffer_Nederlands, 1840, pNederlands);
				_Context->buffer_Portugues=(char *) 0;
		visual_transferin(&_Context->buffer_Portugues, 1840, pPortugues);
				_Context->buffer_Other=(char *) 0;
		visual_transferin(&_Context->buffer_Other, 1840, pOther);
		}
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->focus_pages[1]=5;
	_Context->focus_pages[2]=7;
	_Context->focus_pages[3]=9;
	show_window_editor();
	_Context->focus_pages[4]=11;
	_Context->focus_pages[5]=13;
	_Context->focus_pages[6]=15;
	_Context->focus_pages[7]=17;
	_Context->focus_pages[8]=19;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(60,40,680+10,520+10);
	return(0);
}

private	int	accept_help_messages_hide()
{
	close_window_editor();
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,60,40);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_help_messages_remove(
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
	if (_Context->keycode == 27 ) {
		filetransferdrop(_Context->buffer_English);
		filetransferdrop(_Context->buffer_Francais);
		filetransferdrop(_Context->buffer_Italiano);
		filetransferdrop(_Context->buffer_Espagnol);
		filetransferdrop(_Context->buffer_Deutsch);
		filetransferdrop(_Context->buffer_Nederlands);
		filetransferdrop(_Context->buffer_Portugues);
		filetransferdrop(_Context->buffer_Other);
		
	} else {
		strcpy(_Context->signature,"TTTTTTTT");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(&_Context->buffer_English, 1840, pEnglish);
		visual_transferout(&_Context->buffer_Francais, 1840, pFrancais);
		visual_transferout(&_Context->buffer_Italiano, 1840, pItaliano);
		visual_transferout(&_Context->buffer_Espagnol, 1840, pEspagnol);
		visual_transferout(&_Context->buffer_Deutsch, 1840, pDeutsch);
		visual_transferout(&_Context->buffer_Nederlands, 1840, pNederlands);
		visual_transferout(&_Context->buffer_Portugues, 1840, pPortugues);
		visual_transferout(&_Context->buffer_Other, 1840, pOther);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Auto6304_show() {
	open_window_editor(80,130,
	640,368,_Context->buffer_English);
	return(-1);
}
private int on_English_show() {
	show_window_editor();
	return(-1);
}
private int on_Auto6305_show() {
	open_window_editor(80,130,
	640,368,_Context->buffer_Francais);
	return(-1);
}
private int on_Francais_show() {
	show_window_editor();
	return(-1);
}
private int on_Auto6306_show() {
	open_window_editor(80,130,
	640,368,_Context->buffer_Italiano);
	return(-1);
}
private int on_Auto6307_show() {
	open_window_editor(80,130,
	640,368,_Context->buffer_Espagnol);
	return(-1);
}
private int on_Espagnol_show() {
	show_window_editor();
	return(-1);
}
private int on_Auto6308_show() {
	open_window_editor(80,130,
	640,368,_Context->buffer_Deutsch);
	return(-1);
}
private int on_Deutsch_show() {
	show_window_editor();
	return(-1);
}
private int on_Auto6309_show() {
	open_window_editor(80,130,
	640,368,_Context->buffer_Nederlands);
	return(-1);
}
private int on_Nederlands_show() {
	show_window_editor();
	return(-1);
}
private int on_Auto6310_show() {
	open_window_editor(80,130,
	640,368,_Context->buffer_Portugues);
	return(-1);
}
private int on_Portugues_show() {
	show_window_editor();
	return(-1);
}
private int on_Auto6933_show() {
	open_window_editor(80,130,
	640,368,_Context->buffer_Other);
	return(-1);
}
private int on_Other_show() {
	show_window_editor();
	return(-1);
}

private	int	accept_help_messages_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,60,40);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(60,40,680,520,1,"Sing : Version 1.0a",19,0x403);
	visual_image(63,62,670,490,"skin.gif",4);
	visual_button(70,520,140,32,2,16,0,"Accept",6,0);
	visual_button(330,520,140,32,2,28,28,"&Full Screen",12,0);
	visual_button(590,520,140,32,2,16,0,"Cancel",6,0);
	visual_text(80,64,650,22,4,16,0,"International Document Editor",29,1283);
	if (_Context->page_number == 1 ) {
	visual_tabpage(70,90,660,420,2,"English",7,0,34);
		(void) on_Auto6304_show();
	} else {
		visual_tabpage(70,90,660,420,2,"English",7,0,32);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(80,130,640+2,368+2,5);
	(void) on_English_show();
		}
	if (_Context->page_number == 2 ) {
	visual_tabpage(70,90,660,420,2,"Fran‡ais",8,72,34);
		(void) on_Auto6305_show();
	} else {
		visual_tabpage(70,90,660,420,2,"Fran‡ais",8,72,32);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(80,130,640+2,368+2,5);
	(void) on_Francais_show();
		}
	if (_Context->page_number == 3 ) {
	visual_tabpage(70,90,660,420,2,"Italiano",8,152,34);
		(void) on_Auto6306_show();
	} else {
		visual_tabpage(70,90,660,420,2,"Italiano",8,152,32);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(80,130,640+2,368+2,5);
		}
	if (_Context->page_number == 4 ) {
	visual_tabpage(70,90,660,420,2,"Espagnol",8,223,34);
		(void) on_Auto6307_show();
	} else {
		visual_tabpage(70,90,660,420,2,"Espagnol",8,223,32);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(80,130,640+2,368+2,5);
	(void) on_Espagnol_show();
		}
	if (_Context->page_number == 5 ) {
	visual_tabpage(70,90,660,420,2,"Deutsch",7,306,34);
		(void) on_Auto6308_show();
	} else {
		visual_tabpage(70,90,660,420,2,"Deutsch",7,306,32);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(80,130,640+2,368+2,5);
	(void) on_Deutsch_show();
		}
	if (_Context->page_number == 6 ) {
	visual_tabpage(70,90,660,420,2,"Nederlands",10,384,34);
		(void) on_Auto6309_show();
	} else {
		visual_tabpage(70,90,660,420,2,"Nederlands",10,384,32);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(80,130,640+2,368+2,5);
	(void) on_Nederlands_show();
		}
	if (_Context->page_number == 7 ) {
	visual_tabpage(70,90,660,420,2,"Portugues",9,479,34);
		(void) on_Auto6310_show();
	} else {
		visual_tabpage(70,90,660,420,2,"Portugues",9,479,32);
		}
	if (_Context->page_number == 7 ) {
	visual_frame(80,130,640+2,368+2,5);
	(void) on_Portugues_show();
		}
	if (_Context->page_number == 8 ) {
	visual_tabpage(70,90,660,420,2,"Other",5,569,34);
		(void) on_Auto6933_show();
	} else {
		visual_tabpage(70,90,660,420,2,"Other",5,569,32);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(80,130,640+2,368+2,5);
	(void) on_Other_show();
		}
	visual_thaw(60,40,680,520);

	return(0);
}
private int on_Auto6315_event() {
	return(13);
	return(-1);
}
private int on_FullScreen_event() {
	accept_help_messages_hide();
	switch(_Context->page_number){
	case 1:
	use_editor(_Context->buffer_English);
	accept_help_messages_show();
	visual_frame(80,130,640+2,368+2,5);
;
		/* English */
	/* Auto6304 */
	accept_help_messages_losefocus();
	_Context->page_number = 1;
	accept_help_messages_show();
	_Context->focus_item=5;
	accept_help_messages_show();
	_Context->focus_item=6;
;
	break;
	case 2:
	use_editor(_Context->buffer_Francais);
	accept_help_messages_show();
	visual_frame(80,130,640+2,368+2,5);
;
		/* Francais */
	/* Auto6305 */
	accept_help_messages_losefocus();
	_Context->page_number = 2;
	accept_help_messages_show();
	_Context->focus_item=7;
	accept_help_messages_show();
	_Context->focus_item=8;
;
	break;
	case 3:
	use_editor(_Context->buffer_Italiano);
	accept_help_messages_show();
	visual_frame(80,130,640+2,368+2,5);
;
		/* Italiano */
	/* Auto6306 */
	accept_help_messages_losefocus();
	_Context->page_number = 3;
	accept_help_messages_show();
	_Context->focus_item=9;
	accept_help_messages_show();
	_Context->focus_item=10;
;
	break;
	case 4:
	use_editor(_Context->buffer_Espagnol);
	accept_help_messages_show();
	visual_frame(80,130,640+2,368+2,5);
;
		/* Espagnol */
	/* Auto6307 */
	accept_help_messages_losefocus();
	_Context->page_number = 4;
	accept_help_messages_show();
	_Context->focus_item=11;
	accept_help_messages_show();
	_Context->focus_item=12;
;
	break;
	case 5:
	use_editor(_Context->buffer_Deutsch);
	accept_help_messages_show();
	visual_frame(80,130,640+2,368+2,5);
;
		/* Deutsch */
	/* Auto6308 */
	accept_help_messages_losefocus();
	_Context->page_number = 5;
	accept_help_messages_show();
	_Context->focus_item=13;
	accept_help_messages_show();
	_Context->focus_item=14;
;
	break;
	case 6:
	use_editor(_Context->buffer_Nederlands);
	accept_help_messages_show();
	visual_frame(80,130,640+2,368+2,5);
;
		/* Nederlands */
	/* Auto6309 */
	accept_help_messages_losefocus();
	_Context->page_number = 6;
	accept_help_messages_show();
	_Context->focus_item=15;
	accept_help_messages_show();
	_Context->focus_item=16;
;
	break;
	case 7:
	use_editor(_Context->buffer_Portugues);
	accept_help_messages_show();
	visual_frame(80,130,640+2,368+2,5);
;
		/* Portugues */
	/* Auto6310 */
	accept_help_messages_losefocus();
	_Context->page_number = 7;
	accept_help_messages_show();
	_Context->focus_item=17;
	accept_help_messages_show();
	_Context->focus_item=18;
;
	break;
	case 8:
	use_editor(_Context->buffer_Other);
	accept_help_messages_show();
	visual_frame(80,130,640+2,368+2,5);
;
		/* Other */
	/* Auto6933 */
	accept_help_messages_losefocus();
	_Context->page_number = 8;
	accept_help_messages_show();
	_Context->focus_item=19;
	accept_help_messages_show();
	_Context->focus_item=20;
;
	break;
	}
	return(-1);
}
private int on_Auto6316_event() {
	return(27);
	return(-1);
}


private	int	accept_help_messages_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 719 )  
	&&  (my >= 44 )  
	&&  (mx <= 735 )  
	&&  (my <= 60 )) {
		return(1);	/* Auto6300 */

		}
	if ((mx >= 703 )  
	&&  (my >= 44 )  
	&&  (mx <= 719 )  
	&&  (my <= 60 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vhelper.htm");
			};
		return(-1);	/* Auto6300 */

		}
	if (( mx >= 70 ) 
	&&  ( my >= 520 ) 
	&&  ( mx <= 210 ) 
	&&  ( my <= 552 )) {
		return(2); /* Auto6315 */
		}
	if (( mx >= 330 ) 
	&&  ( my >= 520 ) 
	&&  ( mx <= 470 ) 
	&&  ( my <= 552 )) {
		return(3); /* FullScreen */
		}
	if (( mx >= 590 ) 
	&&  ( my >= 520 ) 
	&&  ( mx <= 730 ) 
	&&  ( my <= 552 )) {
		return(4); /* Auto6316 */
		}
	if (_Context->page_number == 1 ) {
	} else {
		if ((mx >= 70 ) 
		&&  (my >= 90 ) 
		&&  (mx <= 141 ) 
		&&  (my <= 114 )) {
			return(5); /* Auto6304 */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 130 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 498 )) {
			return(6); /* English */
		}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if ((mx >= 142 ) 
		&&  (my >= 90 ) 
		&&  (mx <= 221 ) 
		&&  (my <= 114 )) {
			return(7); /* Auto6305 */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 130 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 498 )) {
			return(8); /* Francais */
		}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if ((mx >= 222 ) 
		&&  (my >= 90 ) 
		&&  (mx <= 292 ) 
		&&  (my <= 114 )) {
			return(9); /* Auto6306 */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 130 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 498 )) {
			return(10); /* Italiano */
		}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if ((mx >= 293 ) 
		&&  (my >= 90 ) 
		&&  (mx <= 375 ) 
		&&  (my <= 114 )) {
			return(11); /* Auto6307 */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 130 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 498 )) {
			return(12); /* Espagnol */
		}
		}
	if (_Context->page_number == 5 ) {
	} else {
		if ((mx >= 376 ) 
		&&  (my >= 90 ) 
		&&  (mx <= 453 ) 
		&&  (my <= 114 )) {
			return(13); /* Auto6308 */
		}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 130 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 498 )) {
			return(14); /* Deutsch */
		}
		}
	if (_Context->page_number == 6 ) {
	} else {
		if ((mx >= 454 ) 
		&&  (my >= 90 ) 
		&&  (mx <= 548 ) 
		&&  (my <= 114 )) {
			return(15); /* Auto6309 */
		}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 130 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 498 )) {
			return(16); /* Nederlands */
		}
		}
	if (_Context->page_number == 7 ) {
	} else {
		if ((mx >= 549 ) 
		&&  (my >= 90 ) 
		&&  (mx <= 638 ) 
		&&  (my <= 114 )) {
			return(17); /* Auto6310 */
		}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 130 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 498 )) {
			return(18); /* Portugues */
		}
		}
	if (_Context->page_number == 8 ) {
	} else {
		if ((mx >= 639 ) 
		&&  (my >= 90 ) 
		&&  (mx <= 701 ) 
		&&  (my <= 114 )) {
			return(19); /* Auto6933 */
		}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= 80 ) 
		&&  ( my >= 130 ) 
		&&  ( mx <= 720 ) 
		&&  ( my <= 498 )) {
			return(20); /* Other */
		}
		}

	return(-1);
}


private	int	accept_help_messages_losefocus()
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
private int on_English_getfocus() {
	return(focus_window_editor());
	return(-1);
}
private int on_Francais_getfocus() {
	return(focus_window_editor());
	return(-1);
}
private int on_Italiano_getfocus() {
	return(focus_window_editor());
	return(-1);
}
private int on_Espagnol_getfocus() {
	return(focus_window_editor());
	return(-1);
}
private int on_Deutsch_getfocus() {
	return(focus_window_editor());
	return(-1);
}
private int on_Nederlands_getfocus() {
	return(focus_window_editor());
	return(-1);
}
private int on_Portugues_getfocus() {
	return(focus_window_editor());
	return(-1);
}
private int on_Other_getfocus() {
	return(focus_window_editor());
	return(-1);
}


private	int	accept_help_messages_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto6315 */
				visual_button(70,520,140,32,2,16,0,"Accept",6,2);
				_Context->keycode = visual_getch();
				visual_button(70,520,140,32,2,16,0,"Accept",6,0);
				break;
			case	0x4 :
				/* Auto6316 */
				visual_button(590,520,140,32,2,16,0,"Cancel",6,2);
				_Context->keycode = visual_getch();
				visual_button(590,520,140,32,2,16,0,"Cancel",6,0);
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
					if ((_Context->keycode = on_English_getfocus()) != -1) break;
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
					if ((_Context->keycode = on_Francais_getfocus()) != -1) break;
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
					if ((_Context->keycode = on_Italiano_getfocus()) != -1) break;
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
					if ((_Context->keycode = on_Espagnol_getfocus()) != -1) break;
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
					if ((_Context->keycode = on_Deutsch_getfocus()) != -1) break;
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
					if ((_Context->keycode = on_Nederlands_getfocus()) != -1) break;
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
					if ((_Context->keycode = on_Portugues_getfocus()) != -1) break;
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
					if ((_Context->keycode = on_Other_getfocus()) != -1) break;
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
			accept_help_messages_losefocus();
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_help_messages_show();
			continue;
		case	0x2 :
			accept_help_messages_losefocus();
			_Context->page_number=8;
			_Context->focus_item=20;
			accept_help_messages_show();
			continue;
		case	0x3 :
			accept_help_messages_losefocus();
			if ( _Context->page_number < 8 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_help_messages_show();
			continue;
		case	0x12 :
			accept_help_messages_losefocus();
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_help_messages_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_help_messages_event()) == -1)
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
							visual_button(70,520,140,32,2,16,0,"Accept",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(70,520,140,32,2,16,0,"Accept",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto6315_event()) != -1) break;

							}
						continue;
					case	0x3 :
						/* FullScreen */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(330,520,140,32,2,28,28,"&Full Screen",12,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(330,520,140,32,2,28,28,"&Full Screen",12,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_FullScreen_event()) != -1) break;

							}
						continue;
					case	0x4 :
						/* Auto6316 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(590,520,140,32,2,16,0,"Cancel",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(590,520,140,32,2,16,0,"Cancel",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto6316_event()) != -1) break;

							}
						continue;
					case	0x5 :
						/* Auto6304 */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_help_messages_losefocus();
							_Context->page_number = 1;
							accept_help_messages_show();
							}
						continue;
					case	0x6 :
						/* English */
						continue;
					case	0x7 :
						/* Auto6305 */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_help_messages_losefocus();
							_Context->page_number = 2;
							accept_help_messages_show();
							}
						continue;
					case	0x8 :
						/* Francais */
						continue;
					case	0x9 :
						/* Auto6306 */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_help_messages_losefocus();
							_Context->page_number = 3;
							accept_help_messages_show();
							}
						continue;
					case	0xa :
						/* Italiano */
						continue;
					case	0xb :
						/* Auto6307 */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_help_messages_losefocus();
							_Context->page_number = 4;
							accept_help_messages_show();
							}
						continue;
					case	0xc :
						/* Espagnol */
						continue;
					case	0xd :
						/* Auto6308 */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_help_messages_losefocus();
							_Context->page_number = 5;
							accept_help_messages_show();
							}
						continue;
					case	0xe :
						/* Deutsch */
						continue;
					case	0xf :
						/* Auto6309 */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_help_messages_losefocus();
							_Context->page_number = 6;
							accept_help_messages_show();
							}
						continue;
					case	0x10 :
						/* Nederlands */
						continue;
					case	0x11 :
						/* Auto6310 */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_help_messages_losefocus();
							_Context->page_number = 7;
							accept_help_messages_show();
							}
						continue;
					case	0x12 :
						/* Portugues */
						continue;
					case	0x13 :
						/* Auto6933 */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_help_messages_losefocus();
							_Context->page_number = 8;
							accept_help_messages_show();
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
		case 0x866 : 
		case 0x846 : 
			/* FullScreen */
			visual_button(330,520,140,32,2,28,28,"&Full Screen",12,8);
			visual_button(330,520,140,32,2,28,28,"&Full Screen",12,0);
			_Context->focus_item=3;
			if ((_Context->keycode = on_FullScreen_event()) != -1) break;
			continue;
			continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_help_messages(
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
	status = accept_help_messages_create(
	 pEnglish,
	 pFrancais,
	 pItaliano,
	 pEspagnol,
	 pDeutsch,
	 pNederlands,
	 pPortugues,
	 pOther);
	if ( status != 0) return(status);
	status = accept_help_messages_show();
		enter_modal();
	status = accept_help_messages_focus();
		leave_modal();
	status = accept_help_messages_hide();
	status = accept_help_messages_remove(
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

#endif /* _vhelper_c */
