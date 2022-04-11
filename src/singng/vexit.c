
#ifndef _vexit_c
#define _vexit_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vexit.xml                                                */
/* Target         : vexit.c                                                  */
/* Identification : 0.0-1177511934-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto2723   ""
#define fr__Auto2723   ""
#define it__Auto2723   ""
#define es__Auto2723   ""
#define de__Auto2723   ""
#define nl__Auto2723   ""
#define pt__Auto2723   ""
#define xx__Auto2723   ""
#define en_Auto2728   "WARNING"
#define fr_Auto2728   "ATTENTION"
#define it_Auto2728   "WARNING"
#define es_Auto2728   "WARNING"
#define de_Auto2728   "ACHTUNG"
#define nl_Auto2728   "WARNING"
#define pt_Auto2728   "WARNING"
#define xx_Auto2728   "THOIR AN AIRE"
#define en_auto1111   "This model has been modified and is unsaved"
#define fr_auto1111   "Ce modŠle a ‚t‚ modifi‚ sans avoir ‚t‚ sauvegard‚"
#define it_auto1111   "This model has been modified and is unsaved"
#define es_auto1111   "This model has been modified and is unsaved"
#define de_auto1111   "This model has been modified and is unsaved"
#define nl_auto1111   "This model has been modified and is unsaved"
#define pt_auto1111   "This model has been modified and is unsaved"
#define xx_auto1111   "Tha an t‚ seo air a'bhith atharachadh gun sgriobhaidh"
#define en_Auto2729   "Do you want to save these modifications before exiting"
#define fr_Auto2729   "Voulez vous sauver les modifications avant de sortir"
#define it_Auto2729   "Do you want to save these modifications before exiting"
#define es_Auto2729   "Do you want to save these modifications before exiting"
#define de_Auto2729   "Do you want to save these modifications before exiting"
#define nl_Auto2729   "Do you want to save these modifications before exiting"
#define pt_Auto2729   "Do you want to save these modifications before exiting"
#define xx_Auto2729   "A bheil feum air na sgriobhadh"
#define en_JustQuit   "&No Just Quit"
#define fr_JustQuit   "&Non"
#define it_JustQuit   "&No Just Quit"
#define es_JustQuit   "&No Just Quit"
#define de_JustQuit   "&No Just Quit"
#define nl_JustQuit   "&No Just Quit"
#define pt_JustQuit   "&No Just Quit"
#define xx_JustQuit   "Cha&n eil"
#define en_AbandonExit   "&Abandon Exit"
#define fr_AbandonExit   "&Annuler"
#define it_AbandonExit   "&Abandon Exit"
#define es_AbandonExit   "&Abandon Exit"
#define de_AbandonExit   "&Abandon Exit"
#define nl_AbandonExit   "&Abandon Exit"
#define pt_AbandonExit   "&Abandon Exit"
#define xx_AbandonExit   "Tileadh"
#define en_SaveOnExit   "&Save then Exit"
#define fr_SaveOnExit   "&Oui"
#define it_SaveOnExit   "&Save then Exit"
#define es_SaveOnExit   "&Save then Exit"
#define de_SaveOnExit   "&Save then Exit"
#define nl_SaveOnExit   "&Save then Exit"
#define pt_SaveOnExit   "&Save then Exit"
#define xx_SaveOnExit   "Tha gu &dearbh"

private struct accept_exit_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto2723[8];
	char * hint_Auto2723[8];
	int	x_Auto2723;
	int	y_Auto2723;
	int	w_Auto2723;
	int	h_Auto2723;
	char * hint_Auto2724[8];
	char * hint_Auto2725[8];
	char * hint_Auto2726[8];
	char * hint_Auto2727[8];
	char * msg_Auto2728[8];
	char * hint_Auto2728[8];
	char * msg_auto1111[8];
	char * hint_auto1111[8];
	char * msg_Auto2729[8];
	char * hint_Auto2729[8];
	char * hint_Auto2730[8];
	char	buffer_Auto2730[48];
	char * msg_JustQuit[8];
	int	trigger_JustQuit;
	char * hint_JustQuit[8];
	char * msg_AbandonExit[8];
	int	trigger_AbandonExit;
	char * hint_AbandonExit[8];
	char * msg_SaveOnExit[8];
	int	trigger_SaveOnExit;
	char * hint_SaveOnExit[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};
static int	vfh[16];

public	int	accept_exit_create(
	struct accept_exit_context ** cptr,
	char * pAuto2730)
{

	int i;
	struct accept_exit_context * _Context=(struct accept_exit_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_exit_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=4;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"K");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Auto2730, 47, pAuto2730);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto2723[i]=" ";
	_Context->hint_Auto2723[0]=en__Auto2723;
	_Context->hint_Auto2723[1]=fr__Auto2723;
	_Context->hint_Auto2723[2]=it__Auto2723;
	_Context->hint_Auto2723[3]=es__Auto2723;
	_Context->hint_Auto2723[4]=de__Auto2723;
	_Context->hint_Auto2723[5]=nl__Auto2723;
	_Context->hint_Auto2723[6]=pt__Auto2723;
	_Context->hint_Auto2723[7]=xx__Auto2723;
	_Context->x_Auto2723=160;
	_Context->y_Auto2723=160;
	_Context->w_Auto2723=480;
	_Context->h_Auto2723=280;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2728[i]=" ";
	_Context->msg_Auto2728[0]=en_Auto2728;
	_Context->msg_Auto2728[1]=fr_Auto2728;
	_Context->msg_Auto2728[2]=it_Auto2728;
	_Context->msg_Auto2728[3]=es_Auto2728;
	_Context->msg_Auto2728[4]=de_Auto2728;
	_Context->msg_Auto2728[5]=nl_Auto2728;
	_Context->msg_Auto2728[6]=pt_Auto2728;
	_Context->msg_Auto2728[7]=xx_Auto2728;
	for (i=0; i < 8; i++)_Context->msg_auto1111[i]=" ";
	_Context->msg_auto1111[0]=en_auto1111;
	_Context->msg_auto1111[1]=fr_auto1111;
	_Context->msg_auto1111[2]=it_auto1111;
	_Context->msg_auto1111[3]=es_auto1111;
	_Context->msg_auto1111[4]=de_auto1111;
	_Context->msg_auto1111[5]=nl_auto1111;
	_Context->msg_auto1111[6]=pt_auto1111;
	_Context->msg_auto1111[7]=xx_auto1111;
	for (i=0; i < 8; i++)_Context->msg_Auto2729[i]=" ";
	_Context->msg_Auto2729[0]=en_Auto2729;
	_Context->msg_Auto2729[1]=fr_Auto2729;
	_Context->msg_Auto2729[2]=it_Auto2729;
	_Context->msg_Auto2729[3]=es_Auto2729;
	_Context->msg_Auto2729[4]=de_Auto2729;
	_Context->msg_Auto2729[5]=nl_Auto2729;
	_Context->msg_Auto2729[6]=pt_Auto2729;
	_Context->msg_Auto2729[7]=xx_Auto2729;
	for (i=0; i < 8; i++)_Context->msg_JustQuit[i]=" ";
	_Context->msg_JustQuit[0]=en_JustQuit;
	_Context->msg_JustQuit[1]=fr_JustQuit;
	_Context->msg_JustQuit[2]=it_JustQuit;
	_Context->msg_JustQuit[3]=es_JustQuit;
	_Context->msg_JustQuit[4]=de_JustQuit;
	_Context->msg_JustQuit[5]=nl_JustQuit;
	_Context->msg_JustQuit[6]=pt_JustQuit;
	_Context->msg_JustQuit[7]=xx_JustQuit;
	for (i=0; i < 8; i++)_Context->msg_AbandonExit[i]=" ";
	_Context->msg_AbandonExit[0]=en_AbandonExit;
	_Context->msg_AbandonExit[1]=fr_AbandonExit;
	_Context->msg_AbandonExit[2]=it_AbandonExit;
	_Context->msg_AbandonExit[3]=es_AbandonExit;
	_Context->msg_AbandonExit[4]=de_AbandonExit;
	_Context->msg_AbandonExit[5]=nl_AbandonExit;
	_Context->msg_AbandonExit[6]=pt_AbandonExit;
	_Context->msg_AbandonExit[7]=xx_AbandonExit;
	for (i=0; i < 8; i++)_Context->msg_SaveOnExit[i]=" ";
	_Context->msg_SaveOnExit[0]=en_SaveOnExit;
	_Context->msg_SaveOnExit[1]=fr_SaveOnExit;
	_Context->msg_SaveOnExit[2]=it_SaveOnExit;
	_Context->msg_SaveOnExit[3]=es_SaveOnExit;
	_Context->msg_SaveOnExit[4]=de_SaveOnExit;
	_Context->msg_SaveOnExit[5]=nl_SaveOnExit;
	_Context->msg_SaveOnExit[6]=pt_SaveOnExit;
	_Context->msg_SaveOnExit[7]=xx_SaveOnExit;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(160,160,480+10,280+10);
	return(0);
}

public 	int	accept_exit_hide(struct accept_exit_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,160,160);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_exit_remove(
	struct accept_exit_context * _Context,
	char * pAuto2730)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"K");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Auto2730, 47, pAuto2730);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_exit_show(struct accept_exit_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,160,160);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(160,160,480,280,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(160,160,480,280,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_frame(170,190,460,240,4);
	visual_frame(180,260,440,160,4);
	visual_filzone(185,265,429,149,28,0);
	visual_frame(201,362,399,46,3);
	visual_text(180,200,440,50,vfh[3],28,27,_Context->msg_Auto2728[_Context->language],strlen(_Context->msg_Auto2728[_Context->language]),3);
	visual_text(200,266,400,44,vfh[2],27,28,_Context->msg_auto1111[_Context->language],strlen(_Context->msg_auto1111[_Context->language]),259);
	visual_text(200,318,400,40,vfh[2],27,28,_Context->msg_Auto2729[_Context->language],strlen(_Context->msg_Auto2729[_Context->language]),259);
	visual_frame(210,300,380+2,20+2,5);
	visual_text(210+1,300+1,380,20,vfh[1],16,15,_Context->buffer_Auto2730,47,3);
	_Context->trigger_JustQuit=visual_trigger_code(_Context->msg_JustQuit[_Context->language],strlen(_Context->msg_JustQuit[_Context->language]));
	visual_button(210,370,120,30,vfh[2],16,21,_Context->msg_JustQuit[_Context->language],strlen(_Context->msg_JustQuit[_Context->language]),0);
	_Context->trigger_AbandonExit=visual_trigger_code(_Context->msg_AbandonExit[_Context->language],strlen(_Context->msg_AbandonExit[_Context->language]));
	visual_button(340,370,120,30,vfh[2],16,21,_Context->msg_AbandonExit[_Context->language],strlen(_Context->msg_AbandonExit[_Context->language]),0);
	_Context->trigger_SaveOnExit=visual_trigger_code(_Context->msg_SaveOnExit[_Context->language],strlen(_Context->msg_SaveOnExit[_Context->language]));
	visual_button(470,370,120,30,vfh[2],16,21,_Context->msg_SaveOnExit[_Context->language],strlen(_Context->msg_SaveOnExit[_Context->language]),0);
	visual_thaw(160,160,480,280);

	return(0);
}
private int on_JustQuit_event(struct accept_exit_context * _Context) {
	return(13);
	return(-1);
}
private int on_AbandonExit_event(struct accept_exit_context * _Context) {
	return(27);
	return(-1);
}
private int on_SaveOnExit_event(struct accept_exit_context * _Context) {
	return('FS');
	return(-1);
}


public	int	accept_exit_event(
struct accept_exit_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_JustQuit == mb ) return(2);
		if (_Context->trigger_AbandonExit == mb ) return(3);
		if (_Context->trigger_SaveOnExit == mb ) return(4);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= 619 )  
	&&  (my >= 164 )  
	&&  (mx <= 635 )  
	&&  (my <= 180 )) {
		return(1);	/* Auto2723 */

		}
	if ((mx >= 603 )  
	&&  (my >= 164 )  
	&&  (mx <= 619 )  
	&&  (my <= 180 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vexit.htm");
			};
		return(-1);	/* Auto2723 */

		}
	if ((mx >= 587 )  
	&&  (my >= 164 )  
	&&  (mx <= 603 )  
	&&  (my <= 180 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_exit_show(_Context);
		return(-1);	/* Auto2723 */

		}
		}
	if (( mx >= 210 ) 
	&&  ( my >= 370 ) 
	&&  ( mx <= 330 ) 
	&&  ( my <= 400 )) {
		return(2); /* JustQuit */
		}
	if (( mx >= 340 ) 
	&&  ( my >= 370 ) 
	&&  ( mx <= 460 ) 
	&&  ( my <= 400 )) {
		return(3); /* AbandonExit */
		}
	if (( mx >= 470 ) 
	&&  ( my >= 370 ) 
	&&  ( mx <= 590 ) 
	&&  ( my <= 400 )) {
		return(4); /* SaveOnExit */
		}

	return(-1);
}


public	int	accept_exit_focus(struct accept_exit_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* JustQuit */
				_Context->trigger_JustQuit=visual_trigger_code(_Context->msg_JustQuit[_Context->language],strlen(_Context->msg_JustQuit[_Context->language]));
				visual_button(210,370,120,30,vfh[2],16,21,_Context->msg_JustQuit[_Context->language],strlen(_Context->msg_JustQuit[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_JustQuit=visual_trigger_code(_Context->msg_JustQuit[_Context->language],strlen(_Context->msg_JustQuit[_Context->language]));
	visual_button(210,370,120,30,vfh[2],16,21,_Context->msg_JustQuit[_Context->language],strlen(_Context->msg_JustQuit[_Context->language]),0);
				break;
			case	0x3 :
				/* AbandonExit */
				_Context->trigger_AbandonExit=visual_trigger_code(_Context->msg_AbandonExit[_Context->language],strlen(_Context->msg_AbandonExit[_Context->language]));
				visual_button(340,370,120,30,vfh[2],16,21,_Context->msg_AbandonExit[_Context->language],strlen(_Context->msg_AbandonExit[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_AbandonExit=visual_trigger_code(_Context->msg_AbandonExit[_Context->language],strlen(_Context->msg_AbandonExit[_Context->language]));
	visual_button(340,370,120,30,vfh[2],16,21,_Context->msg_AbandonExit[_Context->language],strlen(_Context->msg_AbandonExit[_Context->language]),0);
				break;
			case	0x4 :
				/* SaveOnExit */
				_Context->trigger_SaveOnExit=visual_trigger_code(_Context->msg_SaveOnExit[_Context->language],strlen(_Context->msg_SaveOnExit[_Context->language]));
				visual_button(470,370,120,30,vfh[2],16,21,_Context->msg_SaveOnExit[_Context->language],strlen(_Context->msg_SaveOnExit[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_SaveOnExit=visual_trigger_code(_Context->msg_SaveOnExit[_Context->language],strlen(_Context->msg_SaveOnExit[_Context->language]));
	visual_button(470,370,120,30,vfh[2],16,21,_Context->msg_SaveOnExit[_Context->language],strlen(_Context->msg_SaveOnExit[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_exit_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=4;
			accept_exit_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_exit_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto2723 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* JustQuit */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_JustQuit=visual_trigger_code(_Context->msg_JustQuit[_Context->language],strlen(_Context->msg_JustQuit[_Context->language]));
						visual_button(210,370,120,30,vfh[2],16,21,_Context->msg_JustQuit[_Context->language],strlen(_Context->msg_JustQuit[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_JustQuit=visual_trigger_code(_Context->msg_JustQuit[_Context->language],strlen(_Context->msg_JustQuit[_Context->language]));
	visual_button(210,370,120,30,vfh[2],16,21,_Context->msg_JustQuit[_Context->language],strlen(_Context->msg_JustQuit[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_JustQuit_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* AbandonExit */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_AbandonExit=visual_trigger_code(_Context->msg_AbandonExit[_Context->language],strlen(_Context->msg_AbandonExit[_Context->language]));
						visual_button(340,370,120,30,vfh[2],16,21,_Context->msg_AbandonExit[_Context->language],strlen(_Context->msg_AbandonExit[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_AbandonExit=visual_trigger_code(_Context->msg_AbandonExit[_Context->language],strlen(_Context->msg_AbandonExit[_Context->language]));
	visual_button(340,370,120,30,vfh[2],16,21,_Context->msg_AbandonExit[_Context->language],strlen(_Context->msg_AbandonExit[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_AbandonExit_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* SaveOnExit */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_SaveOnExit=visual_trigger_code(_Context->msg_SaveOnExit[_Context->language],strlen(_Context->msg_SaveOnExit[_Context->language]));
						visual_button(470,370,120,30,vfh[2],16,21,_Context->msg_SaveOnExit[_Context->language],strlen(_Context->msg_SaveOnExit[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_SaveOnExit=visual_trigger_code(_Context->msg_SaveOnExit[_Context->language],strlen(_Context->msg_SaveOnExit[_Context->language]));
	visual_button(470,370,120,30,vfh[2],16,21,_Context->msg_SaveOnExit[_Context->language],strlen(_Context->msg_SaveOnExit[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_SaveOnExit_event(_Context)) != -1) break;

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

public	int	accept_exit(
	char * pAuto2730)
{
	int	status=0;
	struct accept_exit_context * _Context=(struct accept_exit_context*) 0;
	status = accept_exit_create(
	&_Context,
	 pAuto2730);
	if ( status != 0) return(status);
	status = accept_exit_show(_Context);
		enter_modal();
	status = accept_exit_focus(_Context);
		leave_modal();
	status = accept_exit_hide(_Context);
	status = accept_exit_remove(
	_Context,
	 pAuto2730);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vexit_c */
