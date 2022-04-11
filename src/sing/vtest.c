
#ifndef _vtest_c
#define _vtest_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.38  */
/* Production     : C  */
/* Project        : test.xml  */
/* Target         : vtest.c  */
/* Identification : 0.0-1094882068-4315.4314 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
static int	vfh[10];

private struct sing_c_production_tester_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[2+1];
	int	page_number;
	char	buffer_Auto1922[45];
	int	value_TestCheck;
	int	value_TestSwitch;
	int	value_TestRadio;
	int	value_TestList;
	int	column_TestList;
	char	buffer_TestList[18][30];
	char * row_TestList;
	int	value_TestBar;
	int	limit_TestBar;
	int	max_TestBar;
	int	value_TestProgress;
	int	limit_TestProgress;
	int	value_TestSelection;
	int	value_TestGraph;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
private int on_TestButton_create(struct sing_c_production_tester_context * _Context) {
	int vv=0;
	return(-1);
}

public	int	sing_c_production_tester_create(struct sing_c_production_tester_context **cptr)
{

	int i;
	struct sing_c_production_tester_context * _Context=(struct sing_c_production_tester_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	if (!(_Context = allocate( sizeof( struct sing_c_production_tester_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=14;
	_Context->page_number=1;
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->focus_pages[1]=2;
	(void) on_TestButton_create(_Context);
	_Context->focus_pages[2]=9;
	if ( 0 > 0 ) { _Context->row_TestList=&_Context->buffer_TestList[0-1][0]; } ;
	_Context->max_TestBar=1;
	_Context->value_TestBar=1;
	_Context->limit_TestBar=1;
	_Context->value_TestProgress=1;
	_Context->limit_TestProgress=1;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(135,70,530+10,460+10);
	return(0);
}
private int on_TestButton_hide(struct sing_c_production_tester_context * _Context) {
	int vv=0;
	return(-1);
}

public 	int	sing_c_production_tester_hide(struct sing_c_production_tester_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	(void) on_TestButton_hide(_Context);
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,135,70);
		_Context->ctrlbuffer=0;
		}

	return(result);
}
private int on_TestButton_remove(struct sing_c_production_tester_context * _Context) {
	int vv=0;
	return(-1);
}

public	int	sing_c_production_tester_remove(struct sing_c_production_tester_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	(void) on_TestButton_remove(_Context);
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_TestButton_show(struct sing_c_production_tester_context * _Context) {
	int vv=0;
		visual_button(365,220,240,32,vfh[1],27,28,"Test Press Button",strlen("Test Press Button"),0);
;
	return(-1);
}

public	int	sing_c_production_tester_show(struct sing_c_production_tester_context * _Context)
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,135,70);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(135,70,530,460,vfh[1],"Sing : Version 1.0a",strlen("Sing : Version 1.0a"),0x403);
	if (_Context->page_number == 1 ) {
	visual_tabpage(145,100,480,370,vfh[1],"TestPageOne",strlen("TestPageOne"),0,2);
	} else {
		visual_tabpage(145,100,480,370,vfh[1],"TestPageOne",strlen("TestPageOne"),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(155,140,190,170,1);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(175,160,150,130,2);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(185,170,130,110,4);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(195,180,110,90,3);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(205,190,90+2,70+2,5);
	visual_text(205+1,190+1,90,70,vfh[1],27,28,_Context->buffer_Auto1922,44,0);
		}
	if (_Context->page_number == 1 ) {
	visual_check(365,150,240,16,vfh[1],27,28,"Check Box Test",strlen("Check Box Test"),_Context->value_TestCheck|0);
		}
	if (_Context->page_number == 1 ) {
	(void) on_TestButton_show(_Context);
		}
	if (_Context->page_number == 1 ) {
	visual_switch(365,270,168,32,vfh[2],27,28,"Test Switch",strlen("Test Switch"),_Context->value_TestSwitch);
		}
	if (_Context->page_number == 1 ) {
	visual_image(155,320,190,130,"singbmap.gif",6);
		}
	if (_Context->page_number == 1 ) {
	visual_text(365,300,240,20,vfh[1],27,28,"No alignement",strlen("No alignement"),0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(365,420,240,32,vfh[1],27,28,"Space Justified between margins",strlen("Space Justified between margins"),4);
		}
	if (_Context->page_number == 1 ) {
	visual_text(365,390,240,20,vfh[1],27,28,"Centered Text",strlen("Centered Text"),3);
		}
	if (_Context->page_number == 1 ) {
	visual_text(365,360,240,20,vfh[1],27,28,"Right Aligned",strlen("Right Aligned"),1);
		}
	if (_Context->page_number == 1 ) {
	visual_text(365,330,240,20,vfh[1],27,28,"Left Aligned",strlen("Left Aligned"),2);
		}
	if (_Context->page_number == 1 ) {
	visual_radio(365,170,224,16,vfh[1],27,28,"Test Radio Option 1",strlen("Test Radio Option 1"),_Context->value_TestRadio,1);
		}
	if (_Context->page_number == 1 ) {
	visual_radio(365,190,224,16,vfh[1],27,28,"Test Radio Option 2",strlen("Test Radio Option 2"),_Context->value_TestRadio,2);
		}
	if (_Context->page_number == 2 ) {
	visual_tabpage(145,100,480,370,vfh[1],"TestPageTwo",strlen("TestPageTwo"),105,2);
	} else {
		visual_tabpage(145,100,480,370,vfh[1],"TestPageTwo",strlen("TestPageTwo"),105,0);
		}
	if (_Context->page_number == 2 ) {
	visual_table(155,140,240+2,310+2,vfh[1],27,28,"One|Two",_Context->buffer_TestList,0x0401,(char*) 0);
		}
	if (_Context->page_number == 2 ) {
	visual_scrollbar(395,140,20,310,vfh[1],27,28,_Context->value_TestBar,_Context->limit_TestBar,_Context->max_TestBar,259);
		}
	if (_Context->page_number == 2 ) {
	visual_progress(415,140,190,20,vfh[1],27,28,_Context->value_TestProgress,_Context->limit_TestProgress,0);
		}
	if (_Context->page_number == 2 ) {
	visual_select(415,170,200,110,vfh[1],27,28,parse_selection("A|Collection|Of|Several|Values|To|Fill|The|List",&_Context->value_TestSelection),0);
		}
	if (_Context->page_number == 2 ) {
	visual_graph(415,200,200,250,vfh[1],27,28,"200",strlen("200"),_Context->value_TestGraph);
		}
	visual_thaw(135,70,530,460);

	return(0);
}
private int on_TestButton_event(struct sing_c_production_tester_context * _Context) {
	int vv=0;
	_Context->value_TestCheck+=1;
	_Context->value_TestCheck&=1;
		visual_check(365,150,240,16,vfh[1],27,28,"Check Box Test",strlen("Check Box Test"),_Context->value_TestCheck|0);
;
	return(-1);
}

private int on_TestBar_action(struct sing_c_production_tester_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (140+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_TestBar -= 1;
		if (_Context->value_TestBar < 0) 
			_Context->value_TestBar = 0;
	status = sing_c_production_tester_show(_Context);
	visual_scrollbar(395,140,20,310,vfh[1],27,28,_Context->value_TestBar,_Context->limit_TestBar,_Context->max_TestBar,259);
		return(-1);
		}
	if ( visual_event(6) > (140+310-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_TestBar += 1;
		if (_Context->value_TestBar > (_Context->max_TestBar-_Context->limit_TestBar)) 
			_Context->value_TestBar = (_Context->max_TestBar-_Context->limit_TestBar);
	status = sing_c_production_tester_show(_Context);
	visual_scrollbar(395,140,20,310,vfh[1],27,28,_Context->value_TestBar,_Context->limit_TestBar,_Context->max_TestBar,259);
		return(-1);
		}
	visual_scrollbar(395,140,20,310,vfh[1],27,28,_Context->value_TestBar,_Context->limit_TestBar,_Context->max_TestBar,259);

	do {
		while(visual_getch() != 256);
		aty = _Context->value_TestBar;
		_Context->value_TestBar = (((visual_event(6) - (140+20)) * _Context->max_TestBar) / (310 - (2 * 20)));
		if (_Context->value_TestBar < 0) 
			_Context->value_TestBar = 0;
		else if (_Context->value_TestBar > (_Context->max_TestBar-_Context->limit_TestBar)) 
			_Context->value_TestBar = (_Context->max_TestBar-_Context->limit_TestBar);
		if (_Context->value_TestBar != aty) {
	status = sing_c_production_tester_show(_Context);
	visual_scrollbar(395,140,20,310,vfh[1],27,28,_Context->value_TestBar,_Context->limit_TestBar,_Context->max_TestBar,259);
			}

		}
	while (visual_event(1) != _MIMO_UP);	visual_scrollbar(395,140,20,310,vfh[1],27,28,_Context->value_TestBar,_Context->limit_TestBar,_Context->max_TestBar,259);

	return(1);
}


public	int	sing_c_production_tester_event(
struct sing_c_production_tester_context * _Context){
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (mt & _MIMO_UP) {
	if ((mx >= 644 )  
	&&  (my >= 74 )  
	&&  (mx <= 660 )  
	&&  (my <= 90 )) {
		return(1);	/* Auto1912 */

		}
	if ((mx >= 628 )  
	&&  (my >= 74 )  
	&&  (mx <= 644 )  
	&&  (my <= 90 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vtest.htm");
			};
		return(-1);	/* Auto1912 */

		}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if ((mx >= 145 ) 
		&&  (my >= 100 ) 
		&&  (mx <= 249 ) 
		&&  (my <= 124 )) {
			return(2); /* Auto1913 */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 205 ) 
		&&  ( my >= 190 ) 
		&&  ( mx <= 295 ) 
		&&  ( my <= 260 )) {
			return(3); /* Auto1922 */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 365 ) 
		&&  ( my >= 150 ) 
		&&  ( mx <= 605 ) 
		&&  ( my <= 166 )) {
			return(4); /* TestCheck */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 365 ) 
		&&  ( my >= 220 ) 
		&&  ( mx <= 605 ) 
		&&  ( my <= 252 )) {
			return(5); /* TestButton */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 365 ) 
		&&  ( my >= 270 ) 
		&&  ( mx <= 533 ) 
		&&  ( my <= 302 )) {
			return(6); /* TestSwitch */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 365 ) 
		&&  ( my >= 170 ) 
		&&  ( mx <= 589 ) 
		&&  ( my <= 186 )) {
			return(7); /* TestRadio */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 365 ) 
		&&  ( my >= 190 ) 
		&&  ( mx <= 589 ) 
		&&  ( my <= 206 )) {
			return(8); /* TestRadio */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if ((mx >= 250 ) 
		&&  (my >= 100 ) 
		&&  (mx <= 354 ) 
		&&  (my <= 124 )) {
			return(9); /* Auto1916 */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 155 ) 
		&&  ( my >= 140 ) 
		&&  ( mx <= 395 ) 
		&&  ( my <= 450 )) {
			if ((_Context->value_TestList = ((visual_event(6) - 140) / 16)) < 1)
				_Context->value_TestList=0;
else if (_Context->value_TestList > 18 )
				_Context->value_TestList=18;
			if ( _Context->value_TestList > 0 ) { _Context->row_TestList = &_Context->buffer_TestList[(_Context->value_TestList-1)][0]; } 
			_Context->column_TestList = (visual_event(7) - 155);
			if ( _Context->column_TestList < 121 ) {
				_Context->column_TestList = 1;
				}
			else if ( _Context->column_TestList < 242 ) {
				_Context->column_TestList = 2;
				}
			return(10); /* TestList */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 395 ) 
		&&  ( my >= 140 ) 
		&&  ( mx <= 415 ) 
		&&  ( my <= 450 )) {
			return(11); /* TestBar */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 415 ) 
		&&  ( my >= 140 ) 
		&&  ( mx <= 605 ) 
		&&  ( my <= 160 )) {
			return(12); /* TestProgress */
			}
		}
	if (_Context->page_number == 2 ) {
		if ((mx >= 415 ) 
		&&  (my >= 170 ) 
		&&  (mx <= 615 ) 
		&&  (my <= 186 )) {
			return(13); /* TestSelection */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 415 ) 
		&&  ( my >= 200 ) 
		&&  ( mx <= 615 ) 
		&&  ( my <= 450 )) {
			return(14); /* TestGraph */
			}
		}

	return(-1);
}
private int on_TestButton_losefocus(struct sing_c_production_tester_context * _Context) {
	int vv=0;
	return(-1);
}


public	int	sing_c_production_tester_losefocus(struct sing_c_production_tester_context * _Context)
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;

		}
	return(0);

}


public	int	sing_c_production_tester_focus(struct sing_c_production_tester_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto1913 */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x3 :
				/* Auto1922 */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(205+1,190+1,90,70,vfh[1],_Context->buffer_Auto1922,44);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* TestCheck */
				if (_Context->page_number == 1 ) {
				visual_check(365,150,240,16,vfh[1],27,28,"Check Box Test",strlen("Check Box Test"),(_Context->value_TestCheck |2));
					_Context->keycode = visual_getch();
				visual_check(365,150,240,16,vfh[1],27,28,"Check Box Test",strlen("Check Box Test"),(_Context->value_TestCheck |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* TestButton */
				if (_Context->page_number == 1 ) {
					visual_button(365,220,240,32,vfh[1],27,28,"Test Press Button",strlen("Test Press Button"),2);
					_Context->keycode = visual_getch();
					visual_button(365,220,240,32,vfh[1],27,28,"Test Press Button",strlen("Test Press Button"),0);
					(void) on_TestButton_losefocus(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* TestSwitch */
				if (_Context->page_number == 1 ) {
				visual_switch(365,270,168,32,vfh[2],27,28,"Test Switch",strlen("Test Switch"),(_Context->value_TestSwitch |2));
					_Context->keycode = visual_getch();
				visual_switch(365,270,168,32,vfh[2],27,28,"Test Switch",strlen("Test Switch"),(_Context->value_TestSwitch |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* TestRadio */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_getch();
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* TestRadio */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_getch();
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* Auto1916 */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xa :
				/* TestList */
				if (_Context->page_number == 2 ) {
	_Context->keycode = visual_getch();
					if ( _Context->keycode == 9 ) {
						_Context->column_TestList++;
						if ( _Context->column_TestList > 0 ) {
							_Context->column_TestList=1;
							_Context->value_TestList++;
							if ( _Context->value_TestList > 0 ) {
								_Context->value_TestList=1;
								}
							}
						_Context->keycode=0;
						}
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* TestSelection */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_select(415,170,200,110,vfh[1],27,28,parse_selection("A|Collection|Of|Several|Values|To|Fill|The|List",&_Context->value_TestSelection),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* TestGraph */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_getch();
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
			sing_c_production_tester_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			sing_c_production_tester_show(_Context);
			continue;
		case	0x2 :
			sing_c_production_tester_losefocus(_Context);
			_Context->page_number=2;
			_Context->focus_item=14;
			sing_c_production_tester_show(_Context);
			continue;
		case	0x3 :
			sing_c_production_tester_losefocus(_Context);
			if ( _Context->page_number < 2 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			sing_c_production_tester_show(_Context);
			continue;
		case	0x12 :
			sing_c_production_tester_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			sing_c_production_tester_show(_Context);
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=sing_c_production_tester_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1912 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Auto1913 */
						if (visual_event(1) & _MIMO_DOWN) {
							sing_c_production_tester_losefocus(_Context);
							_Context->page_number = 1;
							sing_c_production_tester_show(_Context);
							}
						continue;
					case	0x3 :
						/* Auto1922 */
						continue;
					case	0x4 :
						/* TestCheck */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_TestCheck += 1;
							_Context->value_TestCheck &= 1;
							}
						continue;
					case	0x5 :
						/* TestButton */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(365,220,240,32,vfh[1],27,28,"Test Press Button",strlen("Test Press Button"),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(365,220,240,32,vfh[1],27,28,"Test Press Button",strlen("Test Press Button"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_TestButton_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* TestSwitch */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_TestSwitch += 1;
							_Context->value_TestSwitch &= 1;
							}
						continue;
					case	0x7 :
						/* TestRadio */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_TestRadio = 1;
							sing_c_production_tester_show(_Context);
							}
						continue;
					case	0x8 :
						/* TestRadio */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_TestRadio = 2;
							sing_c_production_tester_show(_Context);
							}
						continue;
					case	0x9 :
						/* Auto1916 */
						if (visual_event(1) & _MIMO_DOWN) {
							sing_c_production_tester_losefocus(_Context);
							_Context->page_number = 2;
							sing_c_production_tester_show(_Context);
							}
						continue;
					case	0xa :
						/* TestList */
						continue;
					case	0xb :
						/* TestBar */
						(void) on_TestBar_action(_Context);
						continue;
					case	0xc :
						/* TestProgress */
						continue;
					case	0xd :
						/* TestSelection */
						continue;
					case	0xe :
						/* TestGraph */
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
				_Context->focus_item=14;
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

public	int	sing_c_production_tester(struct sing_c_production_tester_context * _Context)
{
	int	status=0;
	struct sing_c_production_tester_context * _Context=(struct sing_c_production_tester_context*) 0;
	status = sing_c_production_tester_create(&_Context);
	if ( status != 0) return(status);
	status = sing_c_production_tester_show(_Context);
		enter_modal();
	status = sing_c_production_tester_focus(_Context);
		leave_modal();
	status = sing_c_production_tester_hide(_Context);
	status = sing_c_production_tester_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vtest_c */
