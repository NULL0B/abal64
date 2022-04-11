
#ifndef _vstatus_c
#define _vstatus_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vstatus.xml                                              */
/* Target         : vstatus.c                                                */
/* Identification : 0.0-1177512019-5209.5208                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Frame   ""
#define en__Frame   ""
#define en_IsError   "is error"
#define fr_IsError   "is error"
#define it_IsError   "is error"
#define es_IsError   "is error"
#define de_IsError   "is error"
#define nl_IsError   "is error"
#define pt_IsError   "is error"
#define xx_IsError   "is error"
#define en__IsError   ""
#define en_ZoneOne   ""
#define en__ZoneOne   ""
#define en_ZoneThree   ""
#define en__ZoneThree   ""
#define en_ZoneError   ""
#define en__ZoneError   ""
#define en_ZoneTwo   ""
#define en__ZoneTwo   ""

private struct visual_status_bar_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * hint_Frame[8];
	int	x_Frame;
	int	y_Frame;
	int	w_Frame;
	int	h_Frame;
	int	fg_Frame;
	int	bg_Frame;
	int	fid_Frame;
	char * msg_IsError[8];
	int	trigger_IsError;
	char * hint_IsError[8];
	int	value_IsError;
	char * hint_ZoneOne[8];
	int	x_ZoneOne;
	int	y_ZoneOne;
	int	w_ZoneOne;
	int	h_ZoneOne;
	int	fg_ZoneOne;
	int	bg_ZoneOne;
	int	fid_ZoneOne;
	char	buffer_ZoneOne[32];
	char * hint_ZoneThree[8];
	int	x_ZoneThree;
	int	y_ZoneThree;
	int	w_ZoneThree;
	int	h_ZoneThree;
	int	fg_ZoneThree;
	int	bg_ZoneThree;
	int	fid_ZoneThree;
	char	buffer_ZoneThree[32];
	char * hint_ZoneError[8];
	int	x_ZoneError;
	int	y_ZoneError;
	int	w_ZoneError;
	int	h_ZoneError;
	int	fg_ZoneError;
	int	bg_ZoneError;
	int	fid_ZoneError;
	char	buffer_ZoneError[32];
	char * hint_ZoneTwo[8];
	int	x_ZoneTwo;
	int	y_ZoneTwo;
	int	w_ZoneTwo;
	int	h_ZoneTwo;
	int	fg_ZoneTwo;
	int	bg_ZoneTwo;
	int	fid_ZoneTwo;
	char	buffer_ZoneTwo[32];
	char	signature[1];
	};
static int	vfh[16];
void	status_bar_message(struct visual_status_bar_context * _Context,int item, char * mptr);

/*	--------------------------------------	*/
/*	s t a t u s _ b a r _ m e s s a g e ()	*/
/*	--------------------------------------	*/
void	status_bar_message(struct visual_status_bar_context * _Context,int item, char * mptr){
	int i=0;
	switch(item){
	case 1:
	for(i=0;i<31;i++){
	if(!(*mptr))
	break;
	else{
	*(_Context->buffer_ZoneOne+i)=*(mptr++);
	}
	}
	for(;i<31;i++)
	*(_Context->buffer_ZoneOne+i)=' ';
	break;
	case 2:
	for(i=0;i<31;i++){
	if(!(*mptr))
	break;
	else{
	*(_Context->buffer_ZoneTwo+i)=*(mptr++);
	}
	}
	for(;i<31;i++)
	*(_Context->buffer_ZoneTwo+i)=' ';
	break;
	case 259:
	_Context->value_IsError=1;
	for(i=0;i<31;i++){
	if(!(*mptr))
	break;
	else{
	*(_Context->buffer_ZoneError+i)=*(mptr++);
	}
	}
	for(;i<31;i++)
	*(_Context->buffer_ZoneError+i)=' ';
	break;
	case 3:
	_Context->value_IsError=0;
	for(i=0;i<31;i++){
	if(!(*mptr))
	break;
	else{
	*(_Context->buffer_ZoneThree+i)=*(mptr++);
	}
	}
	for(;i<31;i++)
	*(_Context->buffer_ZoneThree+i)=' ';
	break;
		}
		visual_status_bar_show(_Context);
;

}

public	int	visual_status_bar_create(struct visual_status_bar_context **cptr)
{

	int i;
	struct visual_status_bar_context * _Context=(struct visual_status_bar_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct visual_status_bar_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=1;
		_Context->value_IsError=0;
		for (i=0; i < 31; i++)  *(_Context->buffer_ZoneOne+i)=' ';
		for (i=0; i < 31; i++)  *(_Context->buffer_ZoneThree+i)=' ';
		for (i=0; i < 31; i++)  *(_Context->buffer_ZoneError+i)=' ';
		for (i=0; i < 31; i++)  *(_Context->buffer_ZoneTwo+i)=' ';
	_Context->hint_Frame[0]=en__Frame;
	_Context->x_Frame=0;
	_Context->y_Frame=0;
	_Context->w_Frame=790;
	_Context->h_Frame=30;
	_Context->fg_Frame=30;
	_Context->bg_Frame=30;
	_Context->fid_Frame=1;
	for (i=0; i < 8; i++)_Context->msg_IsError[i]=" ";
	_Context->msg_IsError[0]=en_IsError;
	_Context->msg_IsError[1]=fr_IsError;
	_Context->msg_IsError[2]=it_IsError;
	_Context->msg_IsError[3]=es_IsError;
	_Context->msg_IsError[4]=de_IsError;
	_Context->msg_IsError[5]=nl_IsError;
	_Context->msg_IsError[6]=pt_IsError;
	_Context->msg_IsError[7]=xx_IsError;
	_Context->hint_IsError[0]=en__IsError;
	_Context->value_IsError=0;
	_Context->hint_ZoneOne[0]=en__ZoneOne;
	_Context->x_ZoneOne=8;
	_Context->y_ZoneOne=7;
	_Context->w_ZoneOne=252;
	_Context->h_ZoneOne=16;
	_Context->fg_ZoneOne=16;
	_Context->bg_ZoneOne=16;
	_Context->fid_ZoneOne=1;
	_Context->hint_ZoneThree[0]=en__ZoneThree;
	_Context->x_ZoneThree=528;
	_Context->y_ZoneThree=7;
	_Context->w_ZoneThree=252;
	_Context->h_ZoneThree=16;
	_Context->fg_ZoneThree=16;
	_Context->bg_ZoneThree=16;
	_Context->fid_ZoneThree=1;
	_Context->hint_ZoneError[0]=en__ZoneError;
	_Context->x_ZoneError=528;
	_Context->y_ZoneError=7;
	_Context->w_ZoneError=252;
	_Context->h_ZoneError=16;
	_Context->fg_ZoneError=16;
	_Context->bg_ZoneError=16;
	_Context->fid_ZoneError=1;
	_Context->hint_ZoneTwo[0]=en__ZoneTwo;
	_Context->x_ZoneTwo=268;
	_Context->y_ZoneTwo=7;
	_Context->w_ZoneTwo=252;
	_Context->h_ZoneTwo=16;
	_Context->fg_ZoneTwo=16;
	_Context->bg_ZoneTwo=16;
	_Context->fid_ZoneTwo=1;
	return(0);
}

public 	int	visual_status_bar_hide(struct visual_status_bar_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;

	return(result);
}

public	int	visual_status_bar_remove(struct visual_status_bar_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}
private int on_ZoneThree_show(struct visual_status_bar_context * _Context) {
	if(_Context->value_IsError){
		if (((_Context->status = visual_styled_element(_Context->x_ZoneError,_Context->y_ZoneError,_Context->w_ZoneError,_Context->h_ZoneError,GetWidgetStyle(11),_Context->buffer_ZoneError,31)) != 0)
) {
visual_frame(_Context->x_ZoneError,_Context->y_ZoneError,_Context->w_ZoneError+2,_Context->h_ZoneError+2,5);
visual_text(_Context->x_ZoneError+1,_Context->y_ZoneError+1,_Context->w_ZoneError,_Context->h_ZoneError,_Context->fid_ZoneError,31,12,_Context->buffer_ZoneError,31,1);
	}
;
	}
	else{
		if (((_Context->status = visual_styled_element(_Context->x_ZoneThree,_Context->y_ZoneThree,_Context->w_ZoneThree,_Context->h_ZoneThree,GetWidgetStyle(11),_Context->buffer_ZoneThree,31)) != 0)
) {
visual_frame(_Context->x_ZoneThree,_Context->y_ZoneThree,_Context->w_ZoneThree+2,_Context->h_ZoneThree+2,5);
visual_text(_Context->x_ZoneThree+1,_Context->y_ZoneThree+1,_Context->w_ZoneThree,_Context->h_ZoneThree,_Context->fid_ZoneThree,27,0,_Context->buffer_ZoneThree,31,1);
	}
;
	}
	return(-1);
}

public	int	visual_status_bar_show(struct visual_status_bar_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	{
	int aty;
	int ow;
	int oh;
	_Context->x_Frame=0;_Context->y_Frame=0;_Context->w_Frame=790;_Context->h_Frame=30;;
	ow=_Context->w_Frame;
	_Context->w_Frame=(inner_width(2)+1);
	oh=_Context->y_Frame;
	aty=x_conf(68);
	_Context->x_Frame=inner_left();
	_Context->y_Frame=(aty-(_Context->h_Frame+1));
	_Context->h_Frame+=1;
	_Context->x_ZoneOne=8;_Context->y_ZoneOne=7;_Context->w_ZoneOne=252;_Context->h_ZoneOne=16;;
	_Context->x_ZoneTwo=268;_Context->y_ZoneTwo=7;_Context->w_ZoneTwo=252;_Context->h_ZoneTwo=16;;
	_Context->x_ZoneThree=528;_Context->y_ZoneThree=7;_Context->w_ZoneThree=252;_Context->h_ZoneThree=16;;
	_Context->x_ZoneError=528;_Context->y_ZoneError=7;_Context->w_ZoneError=252;_Context->h_ZoneError=16;;
	_Context->y_ZoneOne=((_Context->y_ZoneOne-oh)+_Context->y_Frame)+1;
	_Context->y_ZoneTwo=((_Context->y_ZoneTwo-oh)+_Context->y_Frame)+1;
	_Context->y_ZoneThree=((_Context->y_ZoneThree-oh)+_Context->y_Frame)+1;
	_Context->y_ZoneError=((_Context->y_ZoneError-oh)+_Context->y_Frame)+1;
	_Context->w_ZoneError=_Context->w_ZoneOne=_Context->w_ZoneTwo=_Context->w_ZoneThree=((_Context->w_Frame-40)/3);
	_Context->x_ZoneOne=(_Context->x_Frame+10);
	_Context->x_ZoneTwo=(_Context->x_ZoneOne+_Context->w_ZoneOne+10);
	_Context->x_ZoneThree=(_Context->x_ZoneTwo+_Context->w_ZoneTwo+10);
	_Context->x_ZoneError=(_Context->x_ZoneTwo+_Context->w_ZoneTwo+10);
	/*
	Tray.x=_Context->x_Frame+1;
	Tray.y=_Context->y_Frame+1;
	Tray.w=_Context->w_Frame-2;
	Tray.h=_Context->h_Frame-2;
	*/
		if (((_Context->status = visual_styled_element(_Context->x_Frame,_Context->y_Frame,_Context->w_Frame,_Context->h_Frame,GetWidgetStyle(8)," ",0)) != 0)
) {
		visual_filzone(_Context->x_Frame,_Context->y_Frame,_Context->w_Frame,_Context->h_Frame,27,11);
	}
;
	}
		if (((_Context->status = visual_styled_element(_Context->x_ZoneOne,_Context->y_ZoneOne,_Context->w_ZoneOne,_Context->h_ZoneOne,GetWidgetStyle(11),_Context->buffer_ZoneOne,31)) != 0)
) {
		visual_frame(_Context->x_ZoneOne,_Context->y_ZoneOne,_Context->w_ZoneOne+2,_Context->h_ZoneOne+2,5);
		visual_text(_Context->x_ZoneOne+1,_Context->y_ZoneOne+1,_Context->w_ZoneOne,_Context->h_ZoneOne,_Context->fid_ZoneOne,27,0,_Context->buffer_ZoneOne,31,3);
		}
	(void) on_ZoneThree_show(_Context);
	if (((_Context->status = visual_styled_element(_Context->x_ZoneTwo,_Context->y_ZoneTwo,_Context->w_ZoneTwo,_Context->h_ZoneTwo,GetWidgetStyle(11),_Context->buffer_ZoneTwo,31)) != 0)
) {
		visual_frame(_Context->x_ZoneTwo,_Context->y_ZoneTwo,_Context->w_ZoneTwo+2,_Context->h_ZoneTwo+2,5);
		visual_text(_Context->x_ZoneTwo+1,_Context->y_ZoneTwo+1,_Context->w_ZoneTwo,_Context->h_ZoneTwo,_Context->fid_ZoneTwo,27,0,_Context->buffer_ZoneTwo,31,3);
		}
	visual_thaw(0,0,790,30);

	return(0);
}


public	int	visual_status_bar_event(
struct visual_status_bar_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsError == mb ){
		if (visual_event(1) & _MIMO_UP) {
			_Context->value_IsError += 1;
			_Context->value_IsError &= 1;
			}
		_Context->focus_item=1;
		return(256);
		}
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 12 ) 
	&&  ( my >= 8 ) 
	&&  ( mx <= 76 ) 
	&&  ( my <= 24 )) {
		if (visual_event(1) & _MIMO_UP) {
			_Context->value_IsError += 1;
			_Context->value_IsError &= 1;
			}
		_Context->focus_item=1;
		return(256);
		}

	return(-1);
}


public	int	visual_status_bar_focus(struct visual_status_bar_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* IsError */
				visual_check(12,8,64,16,vfh[1],27,28,_Context->msg_IsError[_Context->language],strlen(_Context->msg_IsError[_Context->language]),(_Context->value_IsError |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsError=visual_trigger_code(_Context->msg_IsError[_Context->language],strlen(_Context->msg_IsError[_Context->language]));
	visual_check(12,8,64,16,vfh[1],27,28,_Context->msg_IsError[_Context->language],strlen(_Context->msg_IsError[_Context->language]),_Context->value_IsError|0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			visual_status_bar_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=1;
			visual_status_bar_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=visual_status_bar_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* IsError */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsError += 1;
						_Context->value_IsError &= 1;
						}
					continue;
				case	0xffffffff :
				default :
					_Context->focus_item=1;
				continue;
				}
				break;
		case	0x1b :
			break;
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
				_Context->focus_item=1;
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

public	int	visual_status_bar()
{
	int	status=0;
	struct visual_status_bar_context * _Context=(struct visual_status_bar_context*) 0;
	status = visual_status_bar_create(&_Context);
	if ( status != 0) return(status);
	status = visual_status_bar_show(_Context);
	status = visual_status_bar_focus(_Context);
	status = visual_status_bar_hide(_Context);
	status = visual_status_bar_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vstatus_c */
