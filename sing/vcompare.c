
#ifndef _vcompare_c
#define _vcompare_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.04  */
/* Production     : C  */
/* Project        : vcompare.sng  */
/* Target         : vcompare.c  */
/* Identification : 0.0-1067510729-11504.11503 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Auto6278   "Sing : Version 1.0a"
#define en_Auto6284   "File Compare Utility"
#define en_LeftName   ""
#define en_RightName   ""
#define en_LeftFile   ""
#define en_RightFile   ""

private struct visual_file_compare_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto6278[8];
	char * msg_Auto6284[8];
	int	trigger_Auto6284;
	char	buffer_LeftName[38];
	char	buffer_RightName[39];
	char	buffer_LeftFile[1537];
	char	buffer_RightFile[1537];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	} * _Context;

private	int	visual_file_compare_create(
	char * pLeftName,
	char * pRightName,
	char * pLeftFile,
	char * pRightFile)
{

	int i;
	if (!(_Context = allocate( sizeof( struct visual_file_compare_context ) ) ))
		return(27);
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=6;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_LeftName, 37, pLeftName);
		visual_transferin(_Context->buffer_RightName, 38, pRightName);
		visual_transferin(_Context->buffer_LeftFile, 1536, pLeftFile);
		visual_transferin(_Context->buffer_RightFile, 1536, pRightFile);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto6278[i]=" ";
	_Context->msg_Auto6278[0]=en_Auto6278;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto6284[i]=" ";
	_Context->msg_Auto6284[0]=en_Auto6284;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(0,0,800,600);
	return(0);
}

private	int	visual_file_compare_hide()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,0,0);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	visual_file_compare_remove(
	char * pLeftName,
	char * pRightName,
	char * pLeftFile,
	char * pRightFile)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_LeftName, 37, pLeftName);
		visual_transferout(_Context->buffer_RightName, 38, pRightName);
		visual_transferout(_Context->buffer_LeftFile, 1536, pLeftFile);
		visual_transferout(_Context->buffer_RightFile, 1536, pRightFile);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

private	int	visual_file_compare_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,0,0);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(0,0,800,600,1,_Context->msg_Auto6278[_Context->language],strlen(_Context->msg_Auto6278[_Context->language]),0x4);
	_Context->trigger_Auto6284=visual_trigger_code(_Context->msg_Auto6284[_Context->language],strlen(_Context->msg_Auto6284[_Context->language]));
	visual_button(320,30,140,32,2,16,0,_Context->msg_Auto6284[_Context->language],strlen(_Context->msg_Auto6284[_Context->language]),0);
	visual_frame(10,40,296+2,16+2,5);
	visual_text(10+1,40+1,296,16,1,16,0,_Context->buffer_LeftName,37,0);
	visual_frame(480,40,304+2,16+2,5);
	visual_text(480+1,40+1,304,16,1,16,0,_Context->buffer_RightName,38,0);
	visual_frame(10,70,384+2,512+2,5);
	visual_text(10+1,70+1,384,512,1,27,28,_Context->buffer_LeftFile,1536,0);
	visual_frame(400,70,384+2,512+2,5);
	visual_text(400+1,70+1,384,512,1,27,28,_Context->buffer_RightFile,1536,0);
	visual_thaw(0,0,800,600);

	return(0);
}


private	int	visual_file_compare_event()
{
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto6284 == mb ) return(2);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (mt & _MIMO_UP) {
	if ((mx >= 747 )  
	&&  (my >= 4 )  
	&&  (mx <= 763 )  
	&&  (my <= 20 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		_Context->language--; _Context->language %=8;
			}
		(void) visual_national_language(_Context->language);
		visual_file_compare_show();
		return(-1);	/* Auto6278 */

		}
		}
	if (( mx >= 320 ) 
	&&  ( my >= 30 ) 
	&&  ( mx <= 460 ) 
	&&  ( my <= 62 )) {
		return(2); /* Auto6284 */
		}
	if (( mx >= 10 ) 
	&&  ( my >= 40 ) 
	&&  ( mx <= 306 ) 
	&&  ( my <= 56 )) {
		return(3); /* LeftName */
		}
	if (( mx >= 480 ) 
	&&  ( my >= 40 ) 
	&&  ( mx <= 784 ) 
	&&  ( my <= 56 )) {
		return(4); /* RightName */
		}
	if (( mx >= 10 ) 
	&&  ( my >= 70 ) 
	&&  ( mx <= 394 ) 
	&&  ( my <= 582 )) {
		return(5); /* LeftFile */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 70 ) 
	&&  ( mx <= 784 ) 
	&&  ( my <= 582 )) {
		return(6); /* RightFile */
		}

	return(-1);
}


private	int	visual_file_compare_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x3 :
				/* LeftName */
				_Context->keycode = visual_edit(10+1,40+1,296,16,1,_Context->buffer_LeftName,37);
				break;
			case	0x4 :
				/* RightName */
				_Context->keycode = visual_edit(480+1,40+1,304,16,1,_Context->buffer_RightName,38);
				break;
			case	0x5 :
				/* LeftFile */
				_Context->keycode = visual_edit(10+1,70+1,384,512,1,_Context->buffer_LeftFile,1536);
				break;
			case	0x6 :
				/* RightFile */
				_Context->keycode = visual_edit(400+1,70+1,384,512,1,_Context->buffer_RightFile,1536);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			visual_file_compare_show();
			continue;
		case	0x2 :
			_Context->focus_item=6;
			visual_file_compare_show();
			continue;
			case	0x100 :
				if ((retcode=visual_file_compare_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto6278 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Auto6284 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(320,30,140,32,2,16,0,_Context->msg_Auto6284[_Context->language],strlen(_Context->msg_Auto6284[_Context->language]),1288);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(320,30,140,32,2,16,0,_Context->msg_Auto6284[_Context->language],strlen(_Context->msg_Auto6284[_Context->language]),1280);
							}
						continue;
					case	0x3 :
						/* LeftName */
						continue;
					case	0x4 :
						/* RightName */
						continue;
					case	0x5 :
						/* LeftFile */
						continue;
					case	0x6 :
						/* RightFile */
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
				_Context->focus_item=6;
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

public	int	visual_file_compare(
	char * pLeftName,
	char * pRightName,
	char * pLeftFile,
	char * pRightFile)
{
	int	status=0;
	status = visual_file_compare_create(
	 pLeftName,
	 pRightName,
	 pLeftFile,
	 pRightFile);
	if ( status != 0) return(status);
	status = visual_file_compare_show();
		enter_modal();
	status = visual_file_compare_focus();
		leave_modal();
	status = visual_file_compare_hide();
	status = visual_file_compare_remove(
	 pLeftName,
	 pRightName,
	 pLeftFile,
	 pRightFile);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcompare_c */
