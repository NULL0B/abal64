
#ifndef _umledit_c
#define _umledit_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1d.0.10  */
/* Production     : C  */
/* Project        : umledit.xml  */
/* Target         : umledit.c  */
/* Identification : 0.0-1148384851-2794.2531 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Auto8   "UML : Editor"
#define en__Auto8   ""
#define en_Auto9   "cancel.gif"
#define en__Auto9   ""
#define en_ModelPage   ""
#define en__ModelPage   ""
#define en_Auto12   ""
#define en__Auto12   ""
#define en_Auto13   ""
#define en__Auto13   ""
static int	vfh[10];

private struct umledit_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto8[8];
	char * hint_Auto8[8];
	int	x_Auto8;
	int	y_Auto8;
	int	w_Auto8;
	int	h_Auto8;
	int	fg_Auto8;
	int	bg_Auto8;
	int	fid_Auto8;
	char * msg_Auto9[8];
	int	trigger_Auto9;
	char * hint_Auto9[8];
	char	buffer_ModelPage[3037];
	int	value_Auto12;
	int	limit_Auto12;
	int	max_Auto12;
	int	value_Auto13;
	int	limit_Auto13;
	int	max_Auto13;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};

static int stdinput(struct umledit_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = umledit_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}


public	int	umledit_create(struct umledit_context **cptr)
{

	int i;
	struct umledit_context * _Context=(struct umledit_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	if (!(_Context = allocate( sizeof( struct umledit_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=5;
		for (i=0; i < 3036; i++)  *(_Context->buffer_ModelPage+i)=' ';
		_Context->max_Auto12=0;
		_Context->limit_Auto12=0;
		_Context->value_Auto12=0;
		_Context->max_Auto13=0;
		_Context->limit_Auto13=0;
		_Context->value_Auto13=0;
	for (i=0; i < 8; i++)_Context->msg_Auto8[i]=" ";
	_Context->msg_Auto8[0]=en_Auto8;
	_Context->hint_Auto8[0]=en__Auto8;
	_Context->x_Auto8=0;
	_Context->y_Auto8=0;
	_Context->w_Auto8=820;
	_Context->h_Auto8=630;
	_Context->fg_Auto8=630;
	_Context->bg_Auto8=630;
	_Context->fid_Auto8=2;
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->w_Auto8=xgr_event(69);
	_Context->h_Auto8=xgr_event(68);
	for (i=0; i < 8; i++)_Context->msg_Auto9[i]=" ";
	_Context->msg_Auto9[0]=en_Auto9;
	_Context->hint_Auto9[0]=en__Auto9;
	_Context->max_Auto12=1;
	_Context->value_Auto12=1;
	_Context->limit_Auto12=1;
	_Context->max_Auto13=1;
	_Context->value_Auto13=1;
	_Context->limit_Auto13=1;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto8,_Context->y_Auto8,_Context->w_Auto8+10,_Context->h_Auto8+10);
	return(0);
}

public 	int	umledit_hide(struct umledit_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto8,_Context->y_Auto8);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	umledit_remove(struct umledit_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_ModelPage_show(struct umledit_context * _Context) {
	visual_frame(50,60,736+2,537+2,5);
visual_text(50+1,60+1,736,537,vfh[1],27,28,_Context->buffer_ModelPage,3036,0);
;
	return(-1);
}

public	int	umledit_show(struct umledit_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto8,_Context->y_Auto8);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto8,_Context->y_Auto8,_Context->w_Auto8,_Context->h_Auto8,_Context->fid_Auto8,_Context->msg_Auto8[_Context->language],strlen(_Context->msg_Auto8[_Context->language]),0x407);
	_Context->trigger_Auto9=visual_trigger_code(_Context->msg_Auto9[_Context->language],strlen(_Context->msg_Auto9[_Context->language]));
	visual_button(10,30,40,30,vfh[1],27,28,_Context->msg_Auto9[_Context->language],strlen(_Context->msg_Auto9[_Context->language]),1328);
	visual_frame(10,60,40,560,4);
	visual_frame(50,30,760,30,4);
	(void) on_ModelPage_show(_Context);
	visual_scrollbar(790,60,20,550,vfh[1],27,28,_Context->value_Auto12,_Context->limit_Auto12,_Context->max_Auto12,259);
	visual_scrollbar(50,600,740,20,vfh[1],27,28,_Context->value_Auto13,_Context->limit_Auto13,_Context->max_Auto13,259);
	visual_thaw(_Context->x_Auto8,_Context->y_Auto8,_Context->w_Auto8,_Context->h_Auto8);
	visual_thaw(_Context->x_Auto8,_Context->y_Auto8,_Context->w_Auto8,_Context->h_Auto8);

	return(0);
}
private int on_Auto9_event(struct umledit_context * _Context) {
	return(27);
	return(-1);
}
private int on_Auto12_event(struct umledit_context * _Context) {
	on_ModelPage_show(_Context);
	return(-1);
}

private int on_Auto12_action(struct umledit_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (60+20) ) {
		do { while( stdinput(_Context) != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Auto12 -= 1;
		if (_Context->value_Auto12 < 0) 
			_Context->value_Auto12 = 0;
		(void) on_Auto12_event(_Context);
	visual_scrollbar(790,60,20,550,vfh[1],27,28,_Context->value_Auto12,_Context->limit_Auto12,_Context->max_Auto12,259);
		return(-1);
		}
	if ( visual_event(6) > (60+550-20) ) {
		do { while( stdinput(_Context) != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Auto12 += 1;
		if (!(_Context->max_Auto12))
			_Context->value_Auto12 = 0;
		else if ((_Context->max_Auto12 < _Context->limit_Auto12) 
		&& (_Context->value_Auto12 >= _Context->max_Auto12)) 
			_Context->value_Auto12 = (_Context->max_Auto12-1);
		else if (_Context->value_Auto12 > (_Context->max_Auto12-_Context->limit_Auto12)) 
			_Context->value_Auto12 = (_Context->max_Auto12-_Context->limit_Auto12);
		(void) on_Auto12_event(_Context);
	visual_scrollbar(790,60,20,550,vfh[1],27,28,_Context->value_Auto12,_Context->limit_Auto12,_Context->max_Auto12,259);
		return(-1);
		}
	visual_scrollbar(790,60,20,550,vfh[1],27,28,_Context->value_Auto12,_Context->limit_Auto12,_Context->max_Auto12,259);

	do {
		while(stdinput(_Context) != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_Auto12;
		_Context->value_Auto12 = (((visual_event(6) - (60+20)) * _Context->max_Auto12) / (550 - (2 * 20)));
		if (_Context->value_Auto12 < 0) 
			_Context->value_Auto12 = 0;
		else if (_Context->value_Auto12 > (_Context->max_Auto12-_Context->limit_Auto12)) 
			_Context->value_Auto12 = (_Context->max_Auto12-_Context->limit_Auto12);
		if (_Context->value_Auto12 != aty) {
		(void) on_Auto12_event(_Context);
	visual_scrollbar(790,60,20,550,vfh[1],27,28,_Context->value_Auto12,_Context->limit_Auto12,_Context->max_Auto12,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_Auto12 -= (_Context->limit_Auto12/2);
			if (_Context->value_Auto12 < 0) 
				_Context->value_Auto12 = 0;
		(void) on_Auto12_event(_Context);
	visual_scrollbar(790,60,20,550,vfh[1],27,28,_Context->value_Auto12,_Context->limit_Auto12,_Context->max_Auto12,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_Auto12 += (_Context->limit_Auto12/2);
			if (!(_Context->max_Auto12))
				_Context->value_Auto12 = 0;
			else if ((_Context->max_Auto12 < _Context->limit_Auto12) 
			&& (_Context->value_Auto12 >= _Context->max_Auto12)) 
				_Context->value_Auto12 = (_Context->max_Auto12-1);
			else if (_Context->value_Auto12 > (_Context->max_Auto12-_Context->limit_Auto12)) 
				_Context->value_Auto12 = (_Context->max_Auto12-_Context->limit_Auto12);
		(void) on_Auto12_event(_Context);
	visual_scrollbar(790,60,20,550,vfh[1],27,28,_Context->value_Auto12,_Context->limit_Auto12,_Context->max_Auto12,259);
			break;
		}
	visual_scrollbar(790,60,20,550,vfh[1],27,28,_Context->value_Auto12,_Context->limit_Auto12,_Context->max_Auto12,259);

	return(1);
}
private int on_Auto13_event(struct umledit_context * _Context) {
	on_ModelPage_show(_Context);
	return(-1);
}

private int on_Auto13_action(struct umledit_context * _Context) {
	int status;
	int atx=visual_event(7);
	int tox=visual_event(7);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }

	if ( visual_event(7) < (50+20) ) {
		do { while( stdinput(_Context) != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Auto13 -= 1;
		if (_Context->value_Auto13 < 0) 
			_Context->value_Auto13 = 0;
		(void) on_Auto13_event(_Context);
	visual_scrollbar(50,600,740,20,vfh[1],27,28,_Context->value_Auto13,_Context->limit_Auto13,_Context->max_Auto13,259);
		return(-1);
		}
	if ( visual_event(7) > (50+740-20) ) {
		do { while( stdinput(_Context) != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Auto13 += 1;
		if (!(_Context->max_Auto13))
			_Context->value_Auto13 = 0;
		else if ((_Context->max_Auto13 < _Context->limit_Auto13) 
		&& (_Context->value_Auto13 >= _Context->max_Auto13)) 
			_Context->value_Auto13 = (_Context->max_Auto13-1);
		else if (_Context->value_Auto13 > (_Context->max_Auto13-_Context->limit_Auto13)) 
			_Context->value_Auto13 = (_Context->max_Auto13-_Context->limit_Auto13);
		(void) on_Auto13_event(_Context);
	visual_scrollbar(50,600,740,20,vfh[1],27,28,_Context->value_Auto13,_Context->limit_Auto13,_Context->max_Auto13,259);
		return(-1);
		}
	visual_scrollbar(50,600,740,20,vfh[1],27,28,_Context->value_Auto13,_Context->limit_Auto13,_Context->max_Auto13,259);

	do {
		while(stdinput(_Context) != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		atx = _Context->value_Auto13;
		_Context->value_Auto13 = (((visual_event(7) - (50+20)) * _Context->max_Auto13) / (740 - (2 * 20)));
		if (_Context->value_Auto13 < 0) 
			_Context->value_Auto13 = 0;
		else if (_Context->value_Auto13 > (_Context->max_Auto13-_Context->limit_Auto13)) 
			_Context->value_Auto13 = (_Context->max_Auto13-_Context->limit_Auto13);
		if (_Context->value_Auto13 != atx) {
		(void) on_Auto13_event(_Context);
	visual_scrollbar(50,600,740,20,vfh[1],27,28,_Context->value_Auto13,_Context->limit_Auto13,_Context->max_Auto13,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_Auto13 -= (_Context->limit_Auto13/2);
			if (_Context->value_Auto13 < 0) 
				_Context->value_Auto13 = 0;
		(void) on_Auto13_event(_Context);
	visual_scrollbar(50,600,740,20,vfh[1],27,28,_Context->value_Auto13,_Context->limit_Auto13,_Context->max_Auto13,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_Auto13 += (_Context->limit_Auto13/2);
			if (!(_Context->max_Auto13))
				_Context->value_Auto13 = 0;
			else if ((_Context->max_Auto13 < _Context->limit_Auto13) 
			&& (_Context->value_Auto13 >= _Context->max_Auto13)) 
				_Context->value_Auto13 = (_Context->max_Auto13-1);
			else if (_Context->value_Auto13 > (_Context->max_Auto13-_Context->limit_Auto13)) 
				_Context->value_Auto13 = (_Context->max_Auto13-_Context->limit_Auto13);
		(void) on_Auto13_event(_Context);
	visual_scrollbar(50,600,740,20,vfh[1],27,28,_Context->value_Auto13,_Context->limit_Auto13,_Context->max_Auto13,259);
			break;
		}
	visual_scrollbar(50,600,740,20,vfh[1],27,28,_Context->value_Auto13,_Context->limit_Auto13,_Context->max_Auto13,259);

	return(1);
}


public	int	umledit_event(
struct umledit_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto9 == mb ) return(2);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (0+799) )  
	&&  (my >= (0+4) )  
	&&  (mx <= (0+816) )  
	&&  (my <= (0+20) )) {
		return(1);	/* Auto8 */

		}
	if ((mx >= (0+783) )  
	&&  (my >= (0+4) )  
	&&  (mx <= (0+800) )  
	&&  (my <= (0+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("umledit.htm");
			};
		return(-1);	/* Auto8 */

		}
	if ((mx >= (0+767) )  
	&&  (my >= (0+4) )  
	&&  (mx <= (0+784) )  
	&&  (my <= (0+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		umledit_show(_Context);
		return(-1);	/* Auto8 */

		}
		}
	if (( mx >= (10) ) 
	&&  ( my >= (30) ) 
	&&  ( mx <= (10+40) ) 
	&&  ( my <= (30+30))) {
		return(2); /* Auto9 */
		}
	if (( mx >= (50) ) 
	&&  ( my >= (60) ) 
	&&  ( mx <= (50+736) ) 
	&&  ( my <= (60+537))) {
		return(3); /* ModelPage */
		}
	if (( mx >= (790) ) 
	&&  ( my >= (60) ) 
	&&  ( mx <= (790+20) ) 
	&&  ( my <= (60+550))) {
		return(4); /* Auto12 */
		}
	if (( mx >= (50) ) 
	&&  ( my >= (600) ) 
	&&  ( mx <= (50+740) ) 
	&&  ( my <= (600+20))) {
		return(5); /* Auto13 */
		}

	return(-1);
}
private int on_ModelPage_getfocus(struct umledit_context * _Context) {
	return(visual_getch());
	return(-1);
}


public	int	umledit_focus(struct umledit_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto9 */
				visual_button(10,30,40,30,vfh[1],27,28,_Context->msg_Auto9[_Context->language],strlen(_Context->msg_Auto9[_Context->language]),1330);
				_Context->keycode = stdinput(_Context);
				visual_button(10,30,40,30,vfh[1],27,28,_Context->msg_Auto9[_Context->language],strlen(_Context->msg_Auto9[_Context->language]),1328);
				break;
			case	0x3 :
				/* ModelPage */
				if ((_Context->keycode = on_ModelPage_getfocus(_Context)) != -1) break;
			break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			umledit_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=5;
			umledit_show(_Context);
			continue;
			case	0x100 :
				if (!( visual_event(1)  & _MIMO_ALT )) { 
					if (( visual_event(7) <  0 )
					|| ( visual_event(6) <  0 )
					|| ( visual_event(7) >  820 )
					|| ( visual_event(6) >  630 )) {
						if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
						else { return(256); }
						}
					}
				if ((retcode=umledit_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto8 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Auto9 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(10,30,40,30,vfh[1],27,28,_Context->msg_Auto9[_Context->language],strlen(_Context->msg_Auto9[_Context->language]),1330);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(10,30,40,30,vfh[1],27,28,_Context->msg_Auto9[_Context->language],strlen(_Context->msg_Auto9[_Context->language]),1328);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto9_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* ModelPage */
						continue;
					case	0x4 :
						/* Auto12 */
						(void) on_Auto12_action(_Context);
						continue;
					case	0x5 :
						/* Auto13 */
						(void) on_Auto13_action(_Context);
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
				_Context->focus_item=5;
			}
			continue;
			case	0x0 :
			
			continue;
			case	0xffffffff :
			
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) stdinput(_Context);
	return(0);

}

public	int	umledit()
{
	int	status=0;
	struct umledit_context * _Context=(struct umledit_context*) 0;
	status = umledit_create(&_Context);
	if ( status != 0) return(status);
	status = umledit_show(_Context);
		enter_modal();
	status = umledit_focus(_Context);
		leave_modal();
	status = umledit_hide(_Context);
	status = umledit_remove(_Context);

	while( visual_kbhit() ) (void) stdinput(_Context);
	return(status);
}
/* End of File */

#endif /* _umledit_c */
