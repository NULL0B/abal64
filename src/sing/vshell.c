
#ifndef _vshell_c
#define _vshell_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vshell.xml                                               */
/* Target         : vshell.c                                                 */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en__Auto3589   ""
#define fr__Auto3589   ""
#define it__Auto3589   ""
#define es__Auto3589   ""
#define de__Auto3589   ""
#define nl__Auto3589   ""
#define pt__Auto3589   ""
#define xx__Auto3589   ""
#define en_Accept   "ok.gif"
#define fr_Accept   "ok.gif"
#define it_Accept   "ok.gif"
#define es_Accept   "ok.gif"
#define de_Accept   "ok.gif"
#define nl_Accept   "ok.gif"
#define pt_Accept   "ok.gif"
#define xx_Accept   "ok.gif"
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"
#define en__Cancel   ""
#define en_Output   ""
#define en__Output   ""

private struct visual_command_shell_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3589[8];
	char * hint_Auto3589[8];
	int	x_Auto3589;
	int	y_Auto3589;
	int	w_Auto3589;
	int	h_Auto3589;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	char * hint_Output[8];
	int	s_Output;
	void *	p_Output;
	char	buffer_Output[2001];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[16];
private int on_Output_show(struct visual_command_shell_context * _Context);
private int on_Accept_event(struct visual_command_shell_context * _Context);
private int on_Cancel_event(struct visual_command_shell_context * _Context);
private int on_Output_event(struct visual_command_shell_context * _Context);
private int on_Output_hide(struct visual_command_shell_context * _Context);
long	visual_system_d(struct visual_command_shell_context * _Context,char * cptr);

/*	--------------------------------	*/
/*	v i s u a l _ s y s t e m _ d ()	*/
/*	--------------------------------	*/
long	visual_system_d(struct visual_command_shell_context * _Context,char * cptr){
	int ecode;
	ecode=systemd(cptr,1,25,1);
	return(ecode);

}

public	int	visual_command_shell_create(struct visual_command_shell_context **cptr)
{

	int i;
	struct visual_command_shell_context * _Context=(struct visual_command_shell_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("bmap0414.fmf",12);
	if (!(_Context = allocate( sizeof( struct visual_command_shell_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=4;
		for (i=0; i < 2000; i++)  *(_Context->buffer_Output+i)=' ';
	for (i=0; i < 8; i++)_Context->msg_Auto3589[i]=" ";
	_Context->hint_Auto3589[0]=en__Auto3589;
	_Context->hint_Auto3589[1]=fr__Auto3589;
	_Context->hint_Auto3589[2]=it__Auto3589;
	_Context->hint_Auto3589[3]=es__Auto3589;
	_Context->hint_Auto3589[4]=de__Auto3589;
	_Context->hint_Auto3589[5]=nl__Auto3589;
	_Context->hint_Auto3589[6]=pt__Auto3589;
	_Context->hint_Auto3589[7]=xx__Auto3589;
	_Context->x_Auto3589=60;
	_Context->y_Auto3589=45;
	_Context->w_Auto3589=680;
	_Context->h_Auto3589=510;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->msg_Cancel[2]=it_Cancel;
	_Context->msg_Cancel[3]=es_Cancel;
	_Context->msg_Cancel[4]=de_Cancel;
	_Context->msg_Cancel[5]=nl_Cancel;
	_Context->msg_Cancel[6]=pt_Cancel;
	_Context->msg_Cancel[7]=xx_Cancel;
	_Context->hint_Cancel[0]=en__Cancel;
	_Context->hint_Output[0]=en__Output;
	_Context->s_Output=0;
	_Context->p_Output=visual_buffer(80,85,640+2,400+2);
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(60,45,680+10,510+10);
	return(0);
}
private int on_Output_hide(struct visual_command_shell_context * _Context) {
	visual_viewport(0,0,0,0,0);
		if ((_Context->p_Output != (void *) 0)
	&& (_Context->s_Output != 0)) {
		(void)visual_buffer_put(_Context->p_Output,80,85);
		_Context->s_Output=0;
		}
;
		return(-1);
}

public 	int	visual_command_shell_hide(struct visual_command_shell_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	(void) on_Output_hide(_Context);
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,60,45);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	visual_command_shell_remove(struct visual_command_shell_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->p_Output != (void *) 0)
		_Context->p_Output = visual_drop(_Context->p_Output);
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Output_show(struct visual_command_shell_context * _Context) {
		if ((_Context->p_Output != (void *) 0)
	&& (_Context->s_Output == 0)) {
		(void)visual_buffer_get(_Context->p_Output,80,85);
		_Context->s_Output=1;
		}
	if ((_Context->p_Output != (void *) 0)
	&& (_Context->s_Output == 0)) {
		(void)visual_buffer_get(_Context->p_Output,80,85);
		_Context->s_Output=1;
		}
visual_frame(80,85,640+2,400+2,5);
visual_text(80+1,85+1,640,400,vfh[1],27,28,_Context->buffer_Output,2000,0);

	_Context->status=visual_viewport(80+1,85+1,640,400,vfh[1]);
	foregr(27);
	backgr(28);
	x_putch(27);x_putch('n');
	x_putch((28>9?((28-10)+'A'):(28+'0')));
	return(-1);
}

public	int	visual_command_shell_show(struct visual_command_shell_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,60,45);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(60,45,680,510,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(60,45,680,510,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(310,495,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(440,495,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	if ((_Context->p_Output != (void *) 0)
	&& (_Context->s_Output == 0)) {
		(void)visual_buffer_get(_Context->p_Output,80,85);
		_Context->s_Output=1;
		}
	(void) on_Output_show(_Context);
	visual_thaw(60,45,680,510);

	return(0);
}
private int on_Accept_event(struct visual_command_shell_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct visual_command_shell_context * _Context) {
	cancel_automatic_production();
	return(27);
	return(-1);
}
private int on_Output_event(struct visual_command_shell_context * _Context) {
	int c;
	return(-1);
}


public	int	visual_command_shell_event(
struct visual_command_shell_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(2);
		if (_Context->trigger_Cancel == mb ) return(3);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= 719 )  
	&&  (my >= 49 )  
	&&  (mx <= 735 )  
	&&  (my <= 65 )) {
		return(1);	/* Auto3589 */

		}
	if ((mx >= 703 )  
	&&  (my >= 49 )  
	&&  (mx <= 719 )  
	&&  (my <= 65 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vshell.htm");
			};
		return(-1);	/* Auto3589 */

		}
	if ((mx >= 687 )  
	&&  (my >= 49 )  
	&&  (mx <= 703 )  
	&&  (my <= 65 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		visual_command_shell_show(_Context);
		return(-1);	/* Auto3589 */

		}
		}
	if (( mx >= 310 ) 
	&&  ( my >= 495 ) 
	&&  ( mx <= 366 ) 
	&&  ( my <= 543 )) {
		return(2); /* Accept */
		}
	if (( mx >= 440 ) 
	&&  ( my >= 495 ) 
	&&  ( mx <= 496 ) 
	&&  ( my <= 543 )) {
		return(3); /* Cancel */
		}
	if (( mx >= 80 ) 
	&&  ( my >= 85 ) 
	&&  ( mx <= 720 ) 
	&&  ( my <= 485 )) {
		return(4); /* Output */
		}

	return(-1);
}


public	int	visual_command_shell_focus(struct visual_command_shell_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(310,495,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(310,495,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0x3 :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(440,495,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(440,495,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			visual_command_shell_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=4;
			visual_command_shell_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=visual_command_shell_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3589 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(310,495,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(310,495,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(440,495,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(440,495,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Output */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Output_event(_Context)) != -1) break;

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

public	int	visual_command_shell()
{
	int	status=0;
	struct visual_command_shell_context * _Context=(struct visual_command_shell_context*) 0;
	status = visual_command_shell_create(&_Context);
	if ( status != 0) return(status);
	status = visual_command_shell_show(_Context);
		enter_modal();
	status = visual_command_shell_focus(_Context);
		leave_modal();
	status = visual_command_shell_hide(_Context);
	status = visual_command_shell_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vshell_c */
