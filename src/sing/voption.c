
#ifndef _voption_c
#define _voption_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : voption.sng  */
/* Target         : voption.c  */
/* Identification : 0.0-1065019113-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct option_properties_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	char	buffer_AtX[7];
	char	buffer_AtY[8];
	char	buffer_Label[46];
	char	buffer_Hint[46];
	char	buffer_Service[46];
	char	buffer_Linkage[46];
	char	buffer_Result[46];
	char	buffer_Trigger[46];
	char	signature[9];
	} * _Context;

private	int	option_properties_create(
	char * pAtX,
	char * pAtY,
	char * pLabel,
	char * pHint,
	char * pService,
	char * pLinkage,
	char * pResult,
	char * pTrigger)
{

	if (!(_Context = allocate( sizeof( struct option_properties_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=11;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWSSSSWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_AtX, 6, pAtX);
		visual_transferin(_Context->buffer_AtY, 7, pAtY);
		visual_transferin(_Context->buffer_Label, 45, pLabel);
		visual_transferin(_Context->buffer_Hint, 45, pHint);
		visual_transferin(_Context->buffer_Service, 45, pService);
		visual_transferin(_Context->buffer_Linkage, 45, pLinkage);
		visual_transferin(_Context->buffer_Result, 45, pResult);
		visual_transferin(_Context->buffer_Trigger, 45, pTrigger);
		}
	_Context->window_col=70;
	_Context->window_row=100;
	return(0);
}

private	int	option_properties_hide()
{

	return(0);
}

private	int	option_properties_remove(
	char * pAtX,
	char * pAtY,
	char * pLabel,
	char * pHint,
	char * pService,
	char * pLinkage,
	char * pResult,
	char * pTrigger)
{

	int	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWSSSSWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_AtX, 6, pAtX);
		visual_transferout(_Context->buffer_AtY, 7, pAtY);
		visual_transferout(_Context->buffer_Label, 45, pLabel);
		visual_transferout(_Context->buffer_Hint, 45, pHint);
		visual_transferout(_Context->buffer_Service, 45, pService);
		visual_transferout(_Context->buffer_Linkage, 45, pLinkage);
		visual_transferout(_Context->buffer_Result, 45, pResult);
		visual_transferout(_Context->buffer_Trigger, 45, pTrigger);
		}
	_Context=liberate(_Context);

	return(result);
}

private	int	option_properties_show()
{
	visual_freeze();
	visual_window(70,100,540,400,2,"Sing : Version 1.0a",19,0x0);
	visual_frame(80,130,520,360,4);
	visual_text(90,140,490,16,2,34,0,"Menu Option Properties",22,0);
	visual_line(90,160,590,160,1,34);
	visual_text(90,170,140,16,2,34,0,"Position",8,0);
	visual_frame(230,170,48+2,16+2,5);
	visual_text(230+1,170+1,48,16,1,34,0,_Context->buffer_AtX,6,0);
	visual_frame(330,170,56+2,16+2,5);
	visual_text(330+1,170+1,56,16,1,34,0,_Context->buffer_AtY,7,0);
	visual_text(200,170,28,16,2,34,0,"X",1,0);
	visual_text(300,170,42,16,2,34,0,"Y",1,0);
	visual_text(90,190,126,16,2,34,0,"Label",5,0);
	visual_text(90,210,140,16,2,34,0,"Hint",4,0);
	visual_text(90,230,126,16,2,34,0,"Service",7,0);
	visual_text(90,250,126,16,2,34,0,"Linkage",7,0);
	visual_frame(230,190,360+2,16+2,5);
	visual_text(230+1,190+1,360,16,1,34,0,_Context->buffer_Label,45,0);
	visual_frame(230,210,360+2,16+2,5);
	visual_text(230+1,210+1,360,16,1,34,0,_Context->buffer_Hint,45,0);
	visual_frame(230,230,360+2,16+2,5);
	visual_text(230+1,230+1,360,16,1,34,0,_Context->buffer_Service,45,0);
	visual_frame(230,250,360+2,16+2,5);
	visual_text(230+1,250+1,360,16,1,34,0,_Context->buffer_Linkage,45,0);
	visual_line(90,280,590,280,1,34);
	visual_text(90,290,98,16,2,34,0,"Result",6,0);
	visual_text(90,310,140,16,2,34,0,"Trigger",7,0);
	visual_frame(230,290,360+2,16+2,5);
	visual_text(230+1,290+1,360,16,1,34,0,_Context->buffer_Result,45,0);
	visual_frame(230,310,360+2,16+2,5);
	visual_text(230+1,310+1,360,16,1,34,0,_Context->buffer_Trigger,45,0);
	visual_line(90,340,590,340,1,34);
	visual_button(90,450,130,30,2,34,0,"OK",2,0);
	visual_button(460,450,130,30,2,34,0,"CANCEL",6,0);
	visual_frame(230,450,220,30,2);
	visual_thaw(70,100,540,400);

	return(0);
}
private int on_Ok_event() {
	return(13);
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}


private	int	option_properties_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 230 ) 
	&&  ( my >= 170 ) 
	&&  ( mx <= 278 ) 
	&&  ( my <= 186 )) {
		return(2); /* AtX */
		}
	if (( mx >= 330 ) 
	&&  ( my >= 170 ) 
	&&  ( mx <= 386 ) 
	&&  ( my <= 186 )) {
		return(3); /* AtY */
		}
	if (( mx >= 230 ) 
	&&  ( my >= 190 ) 
	&&  ( mx <= 590 ) 
	&&  ( my <= 206 )) {
		return(4); /* Label */
		}
	if (( mx >= 230 ) 
	&&  ( my >= 210 ) 
	&&  ( mx <= 590 ) 
	&&  ( my <= 226 )) {
		return(5); /* Hint */
		}
	if (( mx >= 230 ) 
	&&  ( my >= 230 ) 
	&&  ( mx <= 590 ) 
	&&  ( my <= 246 )) {
		return(6); /* Service */
		}
	if (( mx >= 230 ) 
	&&  ( my >= 250 ) 
	&&  ( mx <= 590 ) 
	&&  ( my <= 266 )) {
		return(7); /* Linkage */
		}
	if (( mx >= 230 ) 
	&&  ( my >= 290 ) 
	&&  ( mx <= 590 ) 
	&&  ( my <= 306 )) {
		return(8); /* Result */
		}
	if (( mx >= 230 ) 
	&&  ( my >= 310 ) 
	&&  ( mx <= 590 ) 
	&&  ( my <= 326 )) {
		return(9); /* Trigger */
		}
	if (( mx >= 90 ) 
	&&  ( my >= 450 ) 
	&&  ( mx <= 220 ) 
	&&  ( my <= 480 )) {
		return(10); /* Ok */
		}
	if (( mx >= 460 ) 
	&&  ( my >= 450 ) 
	&&  ( mx <= 590 ) 
	&&  ( my <= 480 )) {
		return(11); /* Cancel */
		}

	return(-1);
}


private	int	option_properties_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* AtX */
				_Context->keycode = visual_edit(230+1,170+1,48,16,1,_Context->buffer_AtX,6);
				break;
			case	0x3 :
				/* AtY */
				_Context->keycode = visual_edit(330+1,170+1,56,16,1,_Context->buffer_AtY,7);
				break;
			case	0x4 :
				/* Label */
				_Context->keycode = visual_edit(230+1,190+1,360,16,1,_Context->buffer_Label,45);
				break;
			case	0x5 :
				/* Hint */
				_Context->keycode = visual_edit(230+1,210+1,360,16,1,_Context->buffer_Hint,45);
				break;
			case	0x6 :
				/* Service */
				_Context->keycode = visual_edit(230+1,230+1,360,16,1,_Context->buffer_Service,45);
				break;
			case	0x7 :
				/* Linkage */
				_Context->keycode = visual_edit(230+1,250+1,360,16,1,_Context->buffer_Linkage,45);
				break;
			case	0x8 :
				/* Result */
				_Context->keycode = visual_edit(230+1,290+1,360,16,1,_Context->buffer_Result,45);
				break;
			case	0x9 :
				/* Trigger */
				_Context->keycode = visual_edit(230+1,310+1,360,16,1,_Context->buffer_Trigger,45);
				break;
			case	0xa :
				/* Ok */
				visual_button(90,450,130,30,2,34,0,"OK",2,2);
				_Context->keycode = visual_getch();
				visual_button(90,450,130,30,2,34,0,"OK",2,0);
				break;
			case	0xb :
				/* Cancel */
				visual_button(460,450,130,30,2,34,0,"CANCEL",6,2);
				_Context->keycode = visual_getch();
				visual_button(460,450,130,30,2,34,0,"CANCEL",6,0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			option_properties_show();
			continue;
		case	0x2 :
			_Context->focus_item=11;
			option_properties_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=option_properties_event()) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto152 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* AtX */
						continue;
					case	0x3 :
						/* AtY */
						continue;
					case	0x4 :
						/* Label */
						continue;
					case	0x5 :
						/* Hint */
						continue;
					case	0x6 :
						/* Service */
						continue;
					case	0x7 :
						/* Linkage */
						continue;
					case	0x8 :
						/* Result */
						continue;
					case	0x9 :
						/* Trigger */
						continue;
					case	0xa :
						/* Ok */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(90,450,130,30,2,34,0,"OK",2,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(90,450,130,30,2,34,0,"OK",2,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Ok_event()) != -1) break;

							}
						continue;
					case	0xb :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(460,450,130,30,2,34,0,"CANCEL",6,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(460,450,130,30,2,34,0,"CANCEL",6,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

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
				_Context->focus_item=11;
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

public	int	option_properties(
	char * pAtX,
	char * pAtY,
	char * pLabel,
	char * pHint,
	char * pService,
	char * pLinkage,
	char * pResult,
	char * pTrigger)
{
	int	status=0;
	status = option_properties_create(
	 pAtX,
	 pAtY,
	 pLabel,
	 pHint,
	 pService,
	 pLinkage,
	 pResult,
	 pTrigger);
	if ( status != 0) return(status);
	status = option_properties_show();
		enter_modal();
	status = option_properties_focus();
		leave_modal();
	status = option_properties_hide();
	status = option_properties_remove(
	 pAtX,
	 pAtY,
	 pLabel,
	 pHint,
	 pService,
	 pLinkage,
	 pResult,
	 pTrigger);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _voption_c */
