
#ifndef _verror_c
#define _verror_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : verror.xml  */
/* Target         : verror.c  */
/* Identification : 0.0-1100518744-5191.5190 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
static int	vfh[10];

private struct accept_error_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	x_auto562;
	int	y_auto562;
	int	w_auto562;
	int	h_auto562;
	char	buffer_ErrorMsg[37];
	char	buffer_FileName[37];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};

public	int	accept_error_create(
	struct accept_error_context ** cptr,
	char * pErrorMsg,
	char * pFileName)
{

	int i;
	struct accept_error_context * _Context=(struct accept_error_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_error_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=3;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"KK");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_ErrorMsg, 36, pErrorMsg);
		visual_transferin(_Context->buffer_FileName, 36, pFileName);
		}
	_Context->x_auto562=125;
	_Context->y_auto562=150;
	_Context->w_auto562=550;
	_Context->h_auto562=300;
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(125,150,550+10,300+10);
	return(0);
}

public 	int	accept_error_hide(struct accept_error_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,125,150);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_error_remove(
	struct accept_error_context * _Context,
	char * pErrorMsg,
	char * pFileName)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"KK");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_ErrorMsg, 36, pErrorMsg);
		visual_transferout(_Context->buffer_FileName, 36, pFileName);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_error_show(struct accept_error_context * _Context)
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,125,150);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(125,150,550,300,vfh[2],"Sing Version 1.0a",strlen("Sing Version 1.0a"),0x403);
	visual_image(128,172,542,274,"skin.gif",4);
	visual_button(293,390,112,32,vfh[2],26,0,"&Retry",strlen("&Retry"),0);
	visual_button(407,390,112,32,vfh[2],26,0,"&Cancel",strlen("&Cancel"),0);
	visual_frame(143,276,510+2,20+2,5);
	visual_text(143+1,276+1,510,20,vfh[2],26,0,_Context->buffer_ErrorMsg,36,0);
	visual_frame(143,326,510+2,20+2,5);
	visual_text(143+1,326+1,510,20,vfh[2],0,0,_Context->buffer_FileName,36,0);
	visual_image(145,192,50,50,"bombicon.gif",0);
	visual_image(603,190,50,50,"bombicon.gif",0);
	visual_text(255,220,310,22,vfh[4],27,0,"An unexpected Error has occured",strlen("An unexpected Error has occured"),259);
	visual_thaw(125,150,550,300);
	visual_thaw(125,150,550,300);

	return(0);
}
private int on_Retry_event(struct accept_error_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_error_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_error_event(
struct accept_error_context * _Context){
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= 654 )  
	&&  (my >= 154 )  
	&&  (mx <= 670 )  
	&&  (my <= 170 )) {
		return(1);	/* auto562 */

		}
	if ((mx >= 638 )  
	&&  (my >= 154 )  
	&&  (mx <= 654 )  
	&&  (my <= 170 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("verror.htm");
			};
		return(-1);	/* auto562 */

		}
		}
	if (( mx >= 293 ) 
	&&  ( my >= 390 ) 
	&&  ( mx <= 405 ) 
	&&  ( my <= 422 )) {
		return(2); /* Retry */
		}
	if (( mx >= 407 ) 
	&&  ( my >= 390 ) 
	&&  ( mx <= 519 ) 
	&&  ( my <= 422 )) {
		return(3); /* Cancel */
		}

	return(-1);
}


public	int	accept_error_focus(struct accept_error_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Retry */
				visual_button(293,390,112,32,vfh[2],26,0,"&Retry",strlen("&Retry"),2);
				_Context->keycode = visual_getch();
				visual_button(293,390,112,32,vfh[2],26,0,"&Retry",strlen("&Retry"),0);
				break;
			case	0x3 :
				/* Cancel */
				visual_button(407,390,112,32,vfh[2],26,0,"&Cancel",strlen("&Cancel"),2);
				_Context->keycode = visual_getch();
				visual_button(407,390,112,32,vfh[2],26,0,"&Cancel",strlen("&Cancel"),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_error_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=3;
			accept_error_show(_Context);
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_error_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto562 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Retry */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(293,390,112,32,vfh[2],26,0,"&Retry",strlen("&Retry"),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(293,390,112,32,vfh[2],26,0,"&Retry",strlen("&Retry"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Retry_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(407,390,112,32,vfh[2],26,0,"&Cancel",strlen("&Cancel"),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(407,390,112,32,vfh[2],26,0,"&Cancel",strlen("&Cancel"),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
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
				_Context->focus_item=3;
			}
			continue;
		case 0x852 : 
		case 0x872 : 
		/* Retry */
		visual_button(293,390,112,32,vfh[2],26,0,"&Retry",strlen("&Retry"),8);
		visual_button(293,390,112,32,vfh[2],26,0,"&Retry",strlen("&Retry"),0);
		_Context->focus_item=2;
		if ((_Context->keycode = on_Retry_event(_Context)) != -1) break;
		continue;
		case 0x843 : 
		case 0x863 : 
		/* Cancel */
		visual_button(407,390,112,32,vfh[2],26,0,"&Cancel",strlen("&Cancel"),8);
		visual_button(407,390,112,32,vfh[2],26,0,"&Cancel",strlen("&Cancel"),0);
		_Context->focus_item=3;
		if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;
		continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_error(
	char * pErrorMsg,
	char * pFileName)
{
	int	status=0;
	struct accept_error_context * _Context=(struct accept_error_context*) 0;
	status = accept_error_create(
	&_Context,
	 pErrorMsg,
	 pFileName);
	if ( status != 0) return(status);
	status = accept_error_show(_Context);
		enter_modal();
	status = accept_error_focus(_Context);
		leave_modal();
	status = accept_error_hide(_Context);
	status = accept_error_remove(
	_Context,
	 pErrorMsg,
	 pFileName);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _verror_c */
