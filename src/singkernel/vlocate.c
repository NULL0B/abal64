
#ifndef _vlocate_c
#define _vlocate_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vlocate.xml  */
/* Target         : vlocate.c  */
/* Identification : 0.0-1100085415-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto1452   "Sing : Version 1.0a"
#define fr_Auto1452   "Sing : Version 1.0a"
#define it_Auto1452   "Sing : Version 1.0a"
#define es_Auto1452   "Sing : Version 1.0a"
#define de_Auto1452   "Sing : Version 1.0a"
#define nl_Auto1452   "Sing : Version 1.0a"
#define pt_Auto1452   "Sing : Version 1.0a"
#define xx_Auto1452   "Sing : Version 1.0a"
#define en_Auto1453   "Widget References"
#define fr_Auto1453   "References au Widget"
#define it_Auto1453   "Widget References"
#define es_Auto1453   "Widget References"
#define de_Auto1453   "Widget References"
#define nl_Auto1453   "Widget References"
#define pt_Auto1453   "Widget References"
#define xx_Auto1453   "Widget References"
#define en_Auto1456   "Name"
#define fr_Auto1456   "Nom"
#define it_Auto1456   "Nom"
#define es_Auto1456   "Name"
#define de_Auto1456   "Name"
#define nl_Auto1456   "Name"
#define pt_Auto1456   "Name"
#define xx_Auto1456   "Ainm"
#define en_Target   ""
#define en_RefList   "Widget.Method"
#define fr_RefList   "Widget.Method"
#define it_RefList   "Widget.Method"
#define es_RefList   "Widget.Method"
#define de_RefList   "Widget.Method"
#define nl_RefList   "Widget.Method"
#define pt_RefList   "Widget.Method"
#define xx_RefList   "Widget.Method"
#define en_RefBar   ""
static int	vfh[10];

private struct widget_reference_locator_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto1452[8];
	int	x_Auto1452;
	int	y_Auto1452;
	int	w_Auto1452;
	int	h_Auto1452;
	char * msg_Auto1453[8];
	char * msg_Auto1456[8];
	char	buffer_Target[37];
	char * msg_RefList[8];
	int	value_RefList;
	int	column_RefList;
	char	buffer_RefList[32][41];
	char * row_RefList;
	int	value_RefBar;
	int	limit_RefBar;
	int	max_RefBar;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};

public	int	widget_reference_locator_create(
	struct widget_reference_locator_context ** cptr,
	char * pTarget)
{

	int i;
	struct widget_reference_locator_context * _Context=(struct widget_reference_locator_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct widget_reference_locator_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=4;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Target, 36, pTarget);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto1452[i]=" ";
	_Context->msg_Auto1452[0]=en_Auto1452;
	_Context->msg_Auto1452[1]=fr_Auto1452;
	_Context->msg_Auto1452[2]=it_Auto1452;
	_Context->msg_Auto1452[3]=es_Auto1452;
	_Context->msg_Auto1452[4]=de_Auto1452;
	_Context->msg_Auto1452[5]=nl_Auto1452;
	_Context->msg_Auto1452[6]=pt_Auto1452;
	_Context->msg_Auto1452[7]=xx_Auto1452;
	_Context->x_Auto1452=10;
	_Context->y_Auto1452=10;
	_Context->w_Auto1452=370;
	_Context->h_Auto1452=620;
	_Context->window_col=10;
	_Context->window_row=10;
	for (i=0; i < 8; i++)_Context->msg_Auto1453[i]=" ";
	_Context->msg_Auto1453[0]=en_Auto1453;
	_Context->msg_Auto1453[1]=fr_Auto1453;
	_Context->msg_Auto1453[2]=it_Auto1453;
	_Context->msg_Auto1453[3]=es_Auto1453;
	_Context->msg_Auto1453[4]=de_Auto1453;
	_Context->msg_Auto1453[5]=nl_Auto1453;
	_Context->msg_Auto1453[6]=pt_Auto1453;
	_Context->msg_Auto1453[7]=xx_Auto1453;
	for (i=0; i < 8; i++)_Context->msg_Auto1456[i]=" ";
	_Context->msg_Auto1456[0]=en_Auto1456;
	_Context->msg_Auto1456[1]=fr_Auto1456;
	_Context->msg_Auto1456[2]=it_Auto1456;
	_Context->msg_Auto1456[3]=es_Auto1456;
	_Context->msg_Auto1456[4]=de_Auto1456;
	_Context->msg_Auto1456[5]=nl_Auto1456;
	_Context->msg_Auto1456[6]=pt_Auto1456;
	_Context->msg_Auto1456[7]=xx_Auto1456;
	for (i=0; i < 8; i++)_Context->msg_RefList[i]=" ";
	_Context->msg_RefList[0]=en_RefList;
	_Context->msg_RefList[1]=fr_RefList;
	_Context->msg_RefList[2]=it_RefList;
	_Context->msg_RefList[3]=es_RefList;
	_Context->msg_RefList[4]=de_RefList;
	_Context->msg_RefList[5]=nl_RefList;
	_Context->msg_RefList[6]=pt_RefList;
	_Context->msg_RefList[7]=xx_RefList;
	if ( 0 > 0 ) { _Context->row_RefList=&_Context->buffer_RefList[0-1][0]; } ;
	_Context->max_RefBar=1;
	_Context->value_RefBar=1;
	_Context->limit_RefBar=1;
	_Context->value_RefBar=0;
	_Context->limit_RefBar=32;
	_Context->max_RefBar=widget_reference_count();
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto1452,_Context->y_Auto1452,370+10,620+10);
	return(0);
}

public 	int	widget_reference_locator_hide(struct widget_reference_locator_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto1452,_Context->y_Auto1452);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	widget_reference_locator_remove(
	struct widget_reference_locator_context * _Context,
	char * pTarget)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Target, 36, pTarget);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_RefList_show(struct widget_reference_locator_context * _Context) {
	int i;
	for(i=1;i<=32;i++){
	if ( i > 0 ) { _Context->row_RefList=&_Context->buffer_RefList[i-1][0]; } ;
	get_widget_reference(i+_Context->value_RefBar,(_Context->row_RefList+0),41);
	}
		visual_table(_Context->x_Auto1452+10,_Context->y_Auto1452+80,330+2,530+2,vfh[1],0,28,_Context->msg_RefList[_Context->language],_Context->buffer_RefList,0x4401,"($)");
;
	return(-1);
}

public	int	widget_reference_locator_show(struct widget_reference_locator_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto1452,_Context->y_Auto1452);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto1452,_Context->y_Auto1452,370,620,vfh[2],_Context->msg_Auto1452[_Context->language],strlen(_Context->msg_Auto1452[_Context->language]),0x407);
	visual_text(_Context->x_Auto1452+10,_Context->y_Auto1452+30,322,20,vfh[3],16,0,_Context->msg_Auto1453[_Context->language],strlen(_Context->msg_Auto1453[_Context->language]),1282);
	visual_text(_Context->x_Auto1452+10,_Context->y_Auto1452+60,42,16,vfh[2],16,0,_Context->msg_Auto1456[_Context->language],strlen(_Context->msg_Auto1456[_Context->language]),258);
	visual_frame(_Context->x_Auto1452+48,_Context->y_Auto1452+60,288+2,16+2,5);
	visual_text(_Context->x_Auto1452+48+1,_Context->y_Auto1452+60+1,288,16,vfh[1],0,28,_Context->buffer_Target,36,0);
	(void) on_RefList_show(_Context);
	visual_scrollbar(_Context->x_Auto1452+340,_Context->y_Auto1452+80,20,530,vfh[1],0,28,_Context->value_RefBar,_Context->limit_RefBar,_Context->max_RefBar,259);
	visual_thaw(_Context->x_Auto1452,_Context->y_Auto1452,370,620);
	visual_thaw(_Context->x_Auto1452,_Context->y_Auto1452,370,620);

	return(0);
}

private int Auto1452action(struct widget_reference_locator_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			widget_reference_locator_hide(_Context);

		_Context->x_Auto1452 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto1452 < 0) { _Context->x_Auto1452=0; }
		_Context->y_Auto1452 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto1452 < 0) { _Context->y_Auto1452=0; }
			widget_reference_locator_show(_Context);

		visual_thaw(_Context->x_Auto1452,_Context->y_Auto1452,370,620);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_RefList_event(struct widget_reference_locator_context * _Context) {
	int l;
	l=_Context->value_RefList;
	if(l>0){
		widget_reference_locator_hide(_Context);
;
	if ( l > 0 ) { _Context->row_RefList=&_Context->buffer_RefList[l-1][0]; } ;
	status_message_length(2,(_Context->row_RefList+0),41);
	if(visual_event(2)!=_MIMO_RIGHT)
	inspect_widget_reference(_Context->value_RefBar+l);
	else search_widget_reference(_Context->value_RefBar+l,_Context->buffer_Target,36);
		widget_reference_locator_show(_Context);
;
	}
	return(-1);
}
private int on_RefBar_event(struct widget_reference_locator_context * _Context) {
	on_RefList_show(_Context);
	return(-1);
}

private int on_RefBar_action(struct widget_reference_locator_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto1452+80+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_RefBar -= 1;
		if (_Context->value_RefBar < 0) 
			_Context->value_RefBar = 0;
		(void) on_RefBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1452+340,_Context->y_Auto1452+80,20,530,vfh[1],0,28,_Context->value_RefBar,_Context->limit_RefBar,_Context->max_RefBar,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto1452+80+530-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_RefBar += 1;
		if (_Context->value_RefBar > (_Context->max_RefBar-_Context->limit_RefBar)) 
			_Context->value_RefBar = (_Context->max_RefBar-_Context->limit_RefBar);
		(void) on_RefBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1452+340,_Context->y_Auto1452+80,20,530,vfh[1],0,28,_Context->value_RefBar,_Context->limit_RefBar,_Context->max_RefBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto1452+340,_Context->y_Auto1452+80,20,530,vfh[1],0,28,_Context->value_RefBar,_Context->limit_RefBar,_Context->max_RefBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_RefBar;
		_Context->value_RefBar = (((visual_event(6) - (_Context->y_Auto1452+80+20)) * _Context->max_RefBar) / (530 - (2 * 20)));
		if (_Context->value_RefBar < 0) 
			_Context->value_RefBar = 0;
		else if (_Context->value_RefBar > (_Context->max_RefBar-_Context->limit_RefBar)) 
			_Context->value_RefBar = (_Context->max_RefBar-_Context->limit_RefBar);
		if (_Context->value_RefBar != aty) {
		(void) on_RefBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1452+340,_Context->y_Auto1452+80,20,530,vfh[1],0,28,_Context->value_RefBar,_Context->limit_RefBar,_Context->max_RefBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_RefBar -= (_Context->limit_RefBar/2);
			if (_Context->value_RefBar < 0) 
				_Context->value_RefBar = 0;
		(void) on_RefBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1452+340,_Context->y_Auto1452+80,20,530,vfh[1],0,28,_Context->value_RefBar,_Context->limit_RefBar,_Context->max_RefBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_RefBar += (_Context->limit_RefBar/2);
			if (_Context->value_RefBar > (_Context->max_RefBar-_Context->limit_RefBar)) 
				_Context->value_RefBar = (_Context->max_RefBar-_Context->limit_RefBar);
		(void) on_RefBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1452+340,_Context->y_Auto1452+80,20,530,vfh[1],0,28,_Context->value_RefBar,_Context->limit_RefBar,_Context->max_RefBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto1452+340,_Context->y_Auto1452+80,20,530,vfh[1],0,28,_Context->value_RefBar,_Context->limit_RefBar,_Context->max_RefBar,259);

	return(1);
}


public	int	widget_reference_locator_event(
struct widget_reference_locator_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto1452+349) )  
	&&  (my >= (_Context->y_Auto1452+4) )  
	&&  (mx <= (_Context->x_Auto1452+366) )  
	&&  (my <= (_Context->y_Auto1452+20) )) {
		return(1);	/* Auto1452 */

		}
	if ((mx >= (_Context->x_Auto1452+333) )  
	&&  (my >= (_Context->y_Auto1452+4) )  
	&&  (mx <= (_Context->x_Auto1452+350) )  
	&&  (my <= (_Context->y_Auto1452+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vlocate.htm");
			};
		return(-1);	/* Auto1452 */

		}
	if ((mx >= (_Context->x_Auto1452+317) )  
	&&  (my >= (_Context->y_Auto1452+4) )  
	&&  (mx <= (_Context->x_Auto1452+334) )  
	&&  (my <= (_Context->y_Auto1452+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		widget_reference_locator_show(_Context);
		return(-1);	/* Auto1452 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto1452+4) )  
		&&  (my >= (_Context->y_Auto1452+4) )  
		&&  (mx <= (_Context->x_Auto1452+302) )  
		&&  (my <= (_Context->y_Auto1452+20) )) {
			return( Auto1452action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto1452+48) ) 
	&&  ( my >= (_Context->y_Auto1452+60) ) 
	&&  ( mx <= (_Context->x_Auto1452+48+288) ) 
	&&  ( my <= (_Context->y_Auto1452+60+16))) {
		return(2); /* Target */
		}
	if (( mx >= (_Context->x_Auto1452+10) ) 
	&&  ( my >= (_Context->y_Auto1452+80) ) 
	&&  ( mx <= (_Context->x_Auto1452+10+330) ) 
	&&  ( my <= (_Context->y_Auto1452+80+530))) {
		if ((_Context->value_RefList = ((visual_event(6) - (_Context->y_Auto1452+80)) / 16)) < 1)
			_Context->value_RefList=0;
else if (_Context->value_RefList > 32 )
			_Context->value_RefList=32;
		if ( _Context->value_RefList > 0 ) { _Context->row_RefList = &_Context->buffer_RefList[(_Context->value_RefList-1)][0]; } 
		_Context->column_RefList = (visual_event(7) - (_Context->x_Auto1452+10));
		if ( _Context->column_RefList < 329 ) {
			_Context->column_RefList = 1;
			}
		return(3); /* RefList */
		}
	if (( mx >= (_Context->x_Auto1452+340) ) 
	&&  ( my >= (_Context->y_Auto1452+80) ) 
	&&  ( mx <= (_Context->x_Auto1452+340+20) ) 
	&&  ( my <= (_Context->y_Auto1452+80+530))) {
		return(4); /* RefBar */
		}

	return(-1);
}
private int on_Target_getfocus(struct widget_reference_locator_context * _Context) {
	return(visual_getch());
	return(-1);
}


public	int	widget_reference_locator_focus(struct widget_reference_locator_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Target */
				if ((_Context->keycode = on_Target_getfocus(_Context)) != -1) break;
			break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			widget_reference_locator_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=4;
			widget_reference_locator_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=widget_reference_locator_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1452 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Target */
						continue;
					case	0x3 :
						/* RefList */
						if ( visual_event(1) &  0x10 ) {
						if ((_Context->keycode = on_RefList_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* RefBar */
						(void) on_RefBar_action(_Context);
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
				_Context->focus_item=4;
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

public	int	widget_reference_locator(
	char * pTarget)
{
	int	status=0;
	struct widget_reference_locator_context * _Context=(struct widget_reference_locator_context*) 0;
	status = widget_reference_locator_create(
	&_Context,
	 pTarget);
	if ( status != 0) return(status);
	status = widget_reference_locator_show(_Context);
		enter_modal();
	status = widget_reference_locator_focus(_Context);
		leave_modal();
	status = widget_reference_locator_hide(_Context);
	status = widget_reference_locator_remove(
	_Context,
	 pTarget);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vlocate_c */
