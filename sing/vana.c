
#ifndef _vana_c
#define _vana_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vana.sng  */
/* Target         : vana.c  */
/* Identification : 0.0-1065019002-2581.2580 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct visual_analyser_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	focus_pages[4+1];
	int	page_number;
	char	buffer_Auto5818[3235];
	int	value_Auto5819;
	int	limit_Auto5819;
	int	max_Auto5819;
	char	buffer_Auto5820[3008];
	int	value_Auto5821;
	int	limit_Auto5821;
	int	max_Auto5821;
	int	value_Auto5822;
	int	limit_Auto5822;
	int	max_Auto5822;
	char	buffer_Auto5823[3235];
	int	value_Auto5824;
	int	limit_Auto5824;
	int	max_Auto5824;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	} * _Context;

private	int	visual_analyser_create()
{

	if (!(_Context = allocate( sizeof( struct visual_analyser_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=13;
	_Context->page_number=1;
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->focus_pages[1]=2;
	_Context->focus_pages[2]=4;
	_Context->max_Auto5819=1;
	_Context->value_Auto5819=1;
	_Context->limit_Auto5819=1;
	_Context->focus_pages[3]=7;
	_Context->max_Auto5821=1;
	_Context->value_Auto5821=1;
	_Context->limit_Auto5821=1;
	_Context->max_Auto5822=1;
	_Context->value_Auto5822=1;
	_Context->limit_Auto5822=1;
	_Context->focus_pages[4]=11;
	_Context->max_Auto5824=1;
	_Context->value_Auto5824=1;
	_Context->limit_Auto5824=1;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(87,78,850,630);
	return(0);
}

private	int	visual_analyser_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,87,78);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	visual_analyser_remove()
{

	int	result=_Context->keycode;
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	visual_analyser_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,87,78);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(87,78,850,630,2,"AnAbal 3 : Version 1.0a.0.01",28,0x1);
	if (_Context->page_number == 1 ) {
	visual_tabpage(97,108,830,590,1,"&Analyser",9,0,34);
	} else {
		visual_tabpage(97,108,830,590,1,"&Analyser",9,0,32);
		}
	if (_Context->page_number == 1 ) {
	visual_image(117,148,790,530,"/home/abal3/images/prlimg15.gif",4);
		}
	if (_Context->page_number == 1 ) {
	visual_button(457,598,110,50,4,28,28,"OK",2,0);
		}
	if (_Context->page_number == 2 ) {
	visual_tabpage(97,108,830,590,1,"&TreeView",9,89,50);
	} else {
		visual_tabpage(97,108,830,590,1,"&TreeView",9,89,48);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(107,148,790+2,530+2,5);
	visual_text(107+1,148+1,790,530,1,27,28,_Context->buffer_Auto5818,3234,0);
		}
	if (_Context->page_number == 2 ) {
	visual_scrollbar(897,148,20,530,1,27,28,_Context->value_Auto5819,_Context->limit_Auto5819,_Context->max_Auto5819,3);
		}
	if (_Context->page_number == 3 ) {
	visual_tabpage(97,108,830,590,1,"&3dViewer",9,178,34);
	} else {
		visual_tabpage(97,108,830,590,1,"&3dViewer",9,178,32);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(107,148,780+2,510+2,5);
	visual_text(107+1,148+1,780,510,1,27,28,_Context->buffer_Auto5820,3007,0);
		}
	if (_Context->page_number == 3 ) {
	visual_scrollbar(107,658,780,20,1,27,28,_Context->value_Auto5821,_Context->limit_Auto5821,_Context->max_Auto5821,3);
		}
	if (_Context->page_number == 3 ) {
	visual_scrollbar(887,148,20,510,1,27,28,_Context->value_Auto5822,_Context->limit_Auto5822,_Context->max_Auto5822,3);
		}
	if (_Context->page_number == 4 ) {
	visual_tabpage(97,108,830,590,1,"T&extEditor",11,267,34);
	} else {
		visual_tabpage(97,108,830,590,1,"T&extEditor",11,267,32);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(107,148,790+2,530+2,5);
	visual_text(107+1,148+1,790,530,1,27,28,_Context->buffer_Auto5823,3234,0);
		}
	if (_Context->page_number == 4 ) {
	visual_scrollbar(897,148,20,530,1,27,28,_Context->value_Auto5824,_Context->limit_Auto5824,_Context->max_Auto5824,3);
		}
	visual_thaw(87,78,850,630);

	return(0);
}

private int on_Auto5819_action() {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (148+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Auto5819 -= 1;
		if (_Context->value_Auto5819 < 0) 
			_Context->value_Auto5819 = 0;
	status = visual_analyser_show();
	visual_scrollbar(897,148,20,530,1,27,28,_Context->value_Auto5819,_Context->limit_Auto5819,_Context->max_Auto5819,259);
		return(-1);
		}
	if ( visual_event(6) > (148+530-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Auto5819 += 1;
		if (_Context->value_Auto5819 > (_Context->max_Auto5819-_Context->limit_Auto5819)) 
			_Context->value_Auto5819 = (_Context->max_Auto5819-_Context->limit_Auto5819);
	status = visual_analyser_show();
	visual_scrollbar(897,148,20,530,1,27,28,_Context->value_Auto5819,_Context->limit_Auto5819,_Context->max_Auto5819,259);
		return(-1);
		}
	visual_scrollbar(897,148,20,530,1,27,28,_Context->value_Auto5819,_Context->limit_Auto5819,_Context->max_Auto5819,259);

	do {
		while(visual_getch() != 256);
		aty = _Context->value_Auto5819;
		_Context->value_Auto5819 = (((visual_event(6) - (148+20)) * _Context->max_Auto5819) / (530 - (2 * 20)));
		if (_Context->value_Auto5819 < 0) 
			_Context->value_Auto5819 = 0;
		else if (_Context->value_Auto5819 > (_Context->max_Auto5819-_Context->limit_Auto5819)) 
			_Context->value_Auto5819 = (_Context->max_Auto5819-_Context->limit_Auto5819);
		if (_Context->value_Auto5819 != aty) {
	status = visual_analyser_show();
	visual_scrollbar(897,148,20,530,1,27,28,_Context->value_Auto5819,_Context->limit_Auto5819,_Context->max_Auto5819,259);
			}

		}
	while (visual_event(1) != _MIMO_UP);	visual_scrollbar(897,148,20,530,1,27,28,_Context->value_Auto5819,_Context->limit_Auto5819,_Context->max_Auto5819,3);

	return(1);
}

private int on_Auto5821_action() {
	int status;
	int atx=visual_event(7);
	int tox=visual_event(7);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }

	if ( visual_event(7) < (107+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Auto5821 -= 1;
		if (_Context->value_Auto5821 < 0) 
			_Context->value_Auto5821 = 0;
	status = visual_analyser_show();
	visual_scrollbar(107,658,780,20,1,27,28,_Context->value_Auto5821,_Context->limit_Auto5821,_Context->max_Auto5821,259);
		return(-1);
		}
	if ( visual_event(7) > (107+780-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Auto5821 += 1;
		if (_Context->value_Auto5821 > (_Context->max_Auto5821-_Context->limit_Auto5821)) 
			_Context->value_Auto5821 = (_Context->max_Auto5821-_Context->limit_Auto5821);
	status = visual_analyser_show();
	visual_scrollbar(107,658,780,20,1,27,28,_Context->value_Auto5821,_Context->limit_Auto5821,_Context->max_Auto5821,259);
		return(-1);
		}
	visual_scrollbar(107,658,780,20,1,27,28,_Context->value_Auto5821,_Context->limit_Auto5821,_Context->max_Auto5821,259);

	do {
		while(visual_getch() != 256);
		atx = _Context->value_Auto5821;
		_Context->value_Auto5821 = (((visual_event(7) - (107+20)) * _Context->max_Auto5821) / (780 - (2 * 20)));
		if (_Context->value_Auto5821 < 0) 
			_Context->value_Auto5821 = 0;
		else if (_Context->value_Auto5821 > (_Context->max_Auto5821-_Context->limit_Auto5821)) 
			_Context->value_Auto5821 = (_Context->max_Auto5821-_Context->limit_Auto5821);
		if (_Context->value_Auto5821 != atx) {
	status = visual_analyser_show();
	visual_scrollbar(107,658,780,20,1,27,28,_Context->value_Auto5821,_Context->limit_Auto5821,_Context->max_Auto5821,259);
			}

		}
	while (visual_event(1) != _MIMO_UP);	visual_scrollbar(107,658,780,20,1,27,28,_Context->value_Auto5821,_Context->limit_Auto5821,_Context->max_Auto5821,3);

	return(1);
}

private int on_Auto5822_action() {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (148+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Auto5822 -= 1;
		if (_Context->value_Auto5822 < 0) 
			_Context->value_Auto5822 = 0;
	status = visual_analyser_show();
	visual_scrollbar(887,148,20,510,1,27,28,_Context->value_Auto5822,_Context->limit_Auto5822,_Context->max_Auto5822,259);
		return(-1);
		}
	if ( visual_event(6) > (148+510-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Auto5822 += 1;
		if (_Context->value_Auto5822 > (_Context->max_Auto5822-_Context->limit_Auto5822)) 
			_Context->value_Auto5822 = (_Context->max_Auto5822-_Context->limit_Auto5822);
	status = visual_analyser_show();
	visual_scrollbar(887,148,20,510,1,27,28,_Context->value_Auto5822,_Context->limit_Auto5822,_Context->max_Auto5822,259);
		return(-1);
		}
	visual_scrollbar(887,148,20,510,1,27,28,_Context->value_Auto5822,_Context->limit_Auto5822,_Context->max_Auto5822,259);

	do {
		while(visual_getch() != 256);
		aty = _Context->value_Auto5822;
		_Context->value_Auto5822 = (((visual_event(6) - (148+20)) * _Context->max_Auto5822) / (510 - (2 * 20)));
		if (_Context->value_Auto5822 < 0) 
			_Context->value_Auto5822 = 0;
		else if (_Context->value_Auto5822 > (_Context->max_Auto5822-_Context->limit_Auto5822)) 
			_Context->value_Auto5822 = (_Context->max_Auto5822-_Context->limit_Auto5822);
		if (_Context->value_Auto5822 != aty) {
	status = visual_analyser_show();
	visual_scrollbar(887,148,20,510,1,27,28,_Context->value_Auto5822,_Context->limit_Auto5822,_Context->max_Auto5822,259);
			}

		}
	while (visual_event(1) != _MIMO_UP);	visual_scrollbar(887,148,20,510,1,27,28,_Context->value_Auto5822,_Context->limit_Auto5822,_Context->max_Auto5822,3);

	return(1);
}

private int on_Auto5824_action() {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (148+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Auto5824 -= 1;
		if (_Context->value_Auto5824 < 0) 
			_Context->value_Auto5824 = 0;
	status = visual_analyser_show();
	visual_scrollbar(897,148,20,530,1,27,28,_Context->value_Auto5824,_Context->limit_Auto5824,_Context->max_Auto5824,259);
		return(-1);
		}
	if ( visual_event(6) > (148+530-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Auto5824 += 1;
		if (_Context->value_Auto5824 > (_Context->max_Auto5824-_Context->limit_Auto5824)) 
			_Context->value_Auto5824 = (_Context->max_Auto5824-_Context->limit_Auto5824);
	status = visual_analyser_show();
	visual_scrollbar(897,148,20,530,1,27,28,_Context->value_Auto5824,_Context->limit_Auto5824,_Context->max_Auto5824,259);
		return(-1);
		}
	visual_scrollbar(897,148,20,530,1,27,28,_Context->value_Auto5824,_Context->limit_Auto5824,_Context->max_Auto5824,259);

	do {
		while(visual_getch() != 256);
		aty = _Context->value_Auto5824;
		_Context->value_Auto5824 = (((visual_event(6) - (148+20)) * _Context->max_Auto5824) / (530 - (2 * 20)));
		if (_Context->value_Auto5824 < 0) 
			_Context->value_Auto5824 = 0;
		else if (_Context->value_Auto5824 > (_Context->max_Auto5824-_Context->limit_Auto5824)) 
			_Context->value_Auto5824 = (_Context->max_Auto5824-_Context->limit_Auto5824);
		if (_Context->value_Auto5824 != aty) {
	status = visual_analyser_show();
	visual_scrollbar(897,148,20,530,1,27,28,_Context->value_Auto5824,_Context->limit_Auto5824,_Context->max_Auto5824,259);
			}

		}
	while (visual_event(1) != _MIMO_UP);	visual_scrollbar(897,148,20,530,1,27,28,_Context->value_Auto5824,_Context->limit_Auto5824,_Context->max_Auto5824,3);

	return(1);
}


private	int	visual_analyser_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 916 )  
	&&  (my >= 82 )  
	&&  (mx <= 932 )  
	&&  (my <= 98 )) {
		return(1);	/* Auto5806 */

		}
	if (_Context->page_number == 1 ) {
	} else {
		if ((mx >= 97 ) 
		&&  (my >= 108 ) 
		&&  (mx <= 185 ) 
		&&  (my <= 132 )) {
			return(2); /* Analyser */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 457 ) 
		&&  ( my >= 598 ) 
		&&  ( mx <= 567 ) 
		&&  ( my <= 648 )) {
			return(3); /* Auto5854 */
		}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if ((mx >= 186 ) 
		&&  (my >= 108 ) 
		&&  (mx <= 274 ) 
		&&  (my <= 132 )) {
			return(4); /* TreeView */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 107 ) 
		&&  ( my >= 148 ) 
		&&  ( mx <= 897 ) 
		&&  ( my <= 678 )) {
			return(5); /* Auto5818 */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 897 ) 
		&&  ( my >= 148 ) 
		&&  ( mx <= 917 ) 
		&&  ( my <= 678 )) {
			return(6); /* Auto5819 */
		}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if ((mx >= 275 ) 
		&&  (my >= 108 ) 
		&&  (mx <= 363 ) 
		&&  (my <= 132 )) {
			return(7); /* 3dViewer */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 107 ) 
		&&  ( my >= 148 ) 
		&&  ( mx <= 887 ) 
		&&  ( my <= 658 )) {
			return(8); /* Auto5820 */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 107 ) 
		&&  ( my >= 658 ) 
		&&  ( mx <= 887 ) 
		&&  ( my <= 678 )) {
			return(9); /* Auto5821 */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 887 ) 
		&&  ( my >= 148 ) 
		&&  ( mx <= 907 ) 
		&&  ( my <= 658 )) {
			return(10); /* Auto5822 */
		}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if ((mx >= 364 ) 
		&&  (my >= 108 ) 
		&&  (mx <= 468 ) 
		&&  (my <= 132 )) {
			return(11); /* TextEditor */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 107 ) 
		&&  ( my >= 148 ) 
		&&  ( mx <= 897 ) 
		&&  ( my <= 678 )) {
			return(12); /* Auto5823 */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 897 ) 
		&&  ( my >= 148 ) 
		&&  ( mx <= 917 ) 
		&&  ( my <= 678 )) {
			return(13); /* Auto5824 */
		}
		}

	return(-1);
}


private	int	visual_analyser_losefocus()
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

		}
	return(0);

}


private	int	visual_analyser_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x3 :
				/* Auto5854 */
				if (_Context->page_number == 1 ) {
					visual_button(457,598,110,50,4,28,28,"OK",2,770);
					_Context->keycode = visual_getch();
					visual_button(457,598,110,50,4,28,28,"OK",2,768);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* TreeView */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x5 :
				/* Auto5818 */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(107+1,148+1,790,530,1,_Context->buffer_Auto5818,3234);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* 3dViewer */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x8 :
				/* Auto5820 */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(107+1,148+1,780,510,1,_Context->buffer_Auto5820,3007);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* TextEditor */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xc :
				/* Auto5823 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(107+1,148+1,790,530,1,_Context->buffer_Auto5823,3234);
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
			visual_analyser_losefocus();
			_Context->page_number=1;
			_Context->focus_item=1;
			visual_analyser_show();
			continue;
		case	0x2 :
			visual_analyser_losefocus();
			_Context->page_number=4;
			_Context->focus_item=13;
			visual_analyser_show();
			continue;
		case	0x3 :
			visual_analyser_losefocus();
			if ( _Context->page_number < 4 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			visual_analyser_show();
			continue;
		case	0x12 :
			visual_analyser_losefocus();
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			visual_analyser_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=visual_analyser_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto5806 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Analyser */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_analyser_losefocus();
							_Context->page_number = 1;
							visual_analyser_show();
							}
						continue;
					case	0x3 :
						/* Auto5854 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(457,598,110,50,4,28,28,"OK",2,776);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(457,598,110,50,4,28,28,"OK",2,768);
							}
						continue;
					case	0x4 :
						/* TreeView */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_analyser_losefocus();
							_Context->page_number = 2;
							visual_analyser_show();
							}
						continue;
					case	0x5 :
						/* Auto5818 */
						continue;
					case	0x6 :
						/* Auto5819 */
						(void) on_Auto5819_action();
						continue;
					case	0x7 :
						/* 3dViewer */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_analyser_losefocus();
							_Context->page_number = 3;
							visual_analyser_show();
							}
						continue;
					case	0x8 :
						/* Auto5820 */
						continue;
					case	0x9 :
						/* Auto5821 */
						(void) on_Auto5821_action();
						continue;
					case	0xa :
						/* Auto5822 */
						(void) on_Auto5822_action();
						continue;
					case	0xb :
						/* TextEditor */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_analyser_losefocus();
							_Context->page_number = 4;
							visual_analyser_show();
							}
						continue;
					case	0xc :
						/* Auto5823 */
						continue;
					case	0xd :
						/* Auto5824 */
						(void) on_Auto5824_action();
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
		case 0x861 : 
		case 0x841 : 
			/* Analyser */
						visual_analyser_losefocus();
			_Context->page_number = 1;
			visual_analyser_show();
			_Context->focus_item=2;
			continue;
			continue;
		case 0x874 : 
		case 0x854 : 
			/* TreeView */
						visual_analyser_losefocus();
			_Context->page_number = 2;
			visual_analyser_show();
			_Context->focus_item=4;
			continue;
			continue;
		case 0x833 : 
			/* 3dViewer */
						visual_analyser_losefocus();
			_Context->page_number = 3;
			visual_analyser_show();
			_Context->focus_item=7;
			continue;
			continue;
		case 0x865 : 
		case 0x845 : 
			/* TextEditor */
						visual_analyser_losefocus();
			_Context->page_number = 4;
			visual_analyser_show();
			_Context->focus_item=11;
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

public	int	visual_analyser()
{
	int	status=0;
	status = visual_analyser_create();
	if ( status != 0) return(status);
	status = visual_analyser_show();
		enter_modal();
	status = visual_analyser_focus();
		leave_modal();
	status = visual_analyser_hide();
	status = visual_analyser_remove();

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vana_c */
