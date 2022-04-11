
#ifndef _vexit_c
#define _vexit_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vexit.xml  */
/* Target         : vexit.c  */
/* Identification : 0.0-1100085209-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto273   "Sing : Version 1.0a"
#define fr_Auto273   "Sing : Version 1.0a"
#define en_Auto397   "skin.gif"
#define fr_Auto397   "skin.gif"
#define en_Auto286   "WARNING"
#define fr_Auto286   "ATTENTION"
#define de_Auto286   "ACHTUNG"
#define xx_Auto286   "THOIR AN AIRE"
#define en_auto1111   "This model has been modified and is unsaved"
#define fr_auto1111   "Ce modŠle a ‚t‚ modifi‚ sans avoir ‚t‚ sauvegard‚"
#define xx_auto1111   "Tha an t‚ seo air a'bhith atharachadh gun sgriobhaidh"
#define en_Auto354   "Do you want to save these modifications before exiting"
#define fr_Auto354   "Voulez vous sauver les modifications avant de sortir"
#define xx_Auto354   "A bheil feum air na sgriobhadh"
#define en_JustQuit   "&No Just Quit"
#define fr_JustQuit   "&Non, Quitter"
#define xx_JustQuit   "Cha&n eil"
#define en_AbandonExit   "&Abandon Exit"
#define fr_AbandonExit   "Ne pas &Quitter"
#define xx_AbandonExit   "Tileadh"
#define en_SaveOnExit   "&Save then Exit"
#define fr_SaveOnExit   "&Oui puis Sortir"
#define xx_SaveOnExit   "Tha gu &dearbh"
static int	vfh[10];

private struct accept_exit_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto273[8];
	int	x_Auto273;
	int	y_Auto273;
	int	w_Auto273;
	int	h_Auto273;
	char * msg_Auto397[8];
	char * msg_Auto286[8];
	char * msg_auto1111[8];
	char * msg_Auto354[8];
	char	buffer_Auto283[48];
	char * msg_JustQuit[8];
	int	trigger_JustQuit;
	char * msg_AbandonExit[8];
	int	trigger_AbandonExit;
	char * msg_SaveOnExit[8];
	int	trigger_SaveOnExit;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};

public	int	accept_exit_create(
	struct accept_exit_context ** cptr,
	char * pAuto283)
{

	int i;
	struct accept_exit_context * _Context=(struct accept_exit_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
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
		visual_transferin(_Context->buffer_Auto283, 47, pAuto283);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto273[i]=" ";
	_Context->msg_Auto273[0]=en_Auto273;
	_Context->msg_Auto273[1]=fr_Auto273;
	_Context->x_Auto273=160;
	_Context->y_Auto273=160;
	_Context->w_Auto273=480;
	_Context->h_Auto273=280;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto397[i]=" ";
	_Context->msg_Auto397[0]=en_Auto397;
	_Context->msg_Auto397[1]=fr_Auto397;
	for (i=0; i < 8; i++)_Context->msg_Auto286[i]=" ";
	_Context->msg_Auto286[0]=en_Auto286;
	_Context->msg_Auto286[1]=fr_Auto286;
	_Context->msg_Auto286[4]=de_Auto286;
	_Context->msg_Auto286[7]=xx_Auto286;
	for (i=0; i < 8; i++)_Context->msg_auto1111[i]=" ";
	_Context->msg_auto1111[0]=en_auto1111;
	_Context->msg_auto1111[1]=fr_auto1111;
	_Context->msg_auto1111[7]=xx_auto1111;
	for (i=0; i < 8; i++)_Context->msg_Auto354[i]=" ";
	_Context->msg_Auto354[0]=en_Auto354;
	_Context->msg_Auto354[1]=fr_Auto354;
	_Context->msg_Auto354[7]=xx_Auto354;
	for (i=0; i < 8; i++)_Context->msg_JustQuit[i]=" ";
	_Context->msg_JustQuit[0]=en_JustQuit;
	_Context->msg_JustQuit[1]=fr_JustQuit;
	_Context->msg_JustQuit[7]=xx_JustQuit;
	for (i=0; i < 8; i++)_Context->msg_AbandonExit[i]=" ";
	_Context->msg_AbandonExit[0]=en_AbandonExit;
	_Context->msg_AbandonExit[1]=fr_AbandonExit;
	_Context->msg_AbandonExit[7]=xx_AbandonExit;
	for (i=0; i < 8; i++)_Context->msg_SaveOnExit[i]=" ";
	_Context->msg_SaveOnExit[0]=en_SaveOnExit;
	_Context->msg_SaveOnExit[1]=fr_SaveOnExit;
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
	char * pAuto283)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"K");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Auto283, 47, pAuto283);
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
	visual_window(160,160,480,280,vfh[2],_Context->msg_Auto273[_Context->language],strlen(_Context->msg_Auto273[_Context->language]),0x407);
	visual_image(164,181,471,255,_Context->msg_Auto397[_Context->language],4);
	visual_frame(170,190,460,240,4);
	visual_frame(180,260,440,160,4);
	visual_filzone(185,265,429,149,28,0);
	visual_frame(201,362,399,46,3);
	visual_text(180,200,440,50,vfh[3],28,27,_Context->msg_Auto286[_Context->language],strlen(_Context->msg_Auto286[_Context->language]),3);
	visual_text(200,266,400,44,vfh[2],27,28,_Context->msg_auto1111[_Context->language],strlen(_Context->msg_auto1111[_Context->language]),259);
	visual_text(200,318,400,40,vfh[2],27,28,_Context->msg_Auto354[_Context->language],strlen(_Context->msg_Auto354[_Context->language]),259);
	visual_frame(210,300,380+2,20+2,5);
	visual_text(210+1,300+1,380,20,vfh[1],16,15,_Context->buffer_Auto283,47,3);
	_Context->trigger_JustQuit=visual_trigger_code(_Context->msg_JustQuit[_Context->language],strlen(_Context->msg_JustQuit[_Context->language]));
	visual_button(210,370,120,30,vfh[2],16,21,_Context->msg_JustQuit[_Context->language],strlen(_Context->msg_JustQuit[_Context->language]),0);
	_Context->trigger_AbandonExit=visual_trigger_code(_Context->msg_AbandonExit[_Context->language],strlen(_Context->msg_AbandonExit[_Context->language]));
	visual_button(340,370,120,30,vfh[2],16,21,_Context->msg_AbandonExit[_Context->language],strlen(_Context->msg_AbandonExit[_Context->language]),0);
	_Context->trigger_SaveOnExit=visual_trigger_code(_Context->msg_SaveOnExit[_Context->language],strlen(_Context->msg_SaveOnExit[_Context->language]));
	visual_button(470,370,120,30,vfh[2],16,21,_Context->msg_SaveOnExit[_Context->language],strlen(_Context->msg_SaveOnExit[_Context->language]),0);
	visual_thaw(160,160,480,280);
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
		return(1);	/* Auto273 */

		}
	if ((mx >= 603 )  
	&&  (my >= 164 )  
	&&  (mx <= 619 )  
	&&  (my <= 180 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vexit.htm");
			};
		return(-1);	/* Auto273 */

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
		return(-1);	/* Auto273 */

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
				visual_button(210,370,120,30,vfh[2],16,21,_Context->msg_JustQuit[_Context->language],strlen(_Context->msg_JustQuit[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(210,370,120,30,vfh[2],16,21,_Context->msg_JustQuit[_Context->language],strlen(_Context->msg_JustQuit[_Context->language]),0);
				break;
			case	0x3 :
				/* AbandonExit */
				visual_button(340,370,120,30,vfh[2],16,21,_Context->msg_AbandonExit[_Context->language],strlen(_Context->msg_AbandonExit[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(340,370,120,30,vfh[2],16,21,_Context->msg_AbandonExit[_Context->language],strlen(_Context->msg_AbandonExit[_Context->language]),0);
				break;
			case	0x4 :
				/* SaveOnExit */
				visual_button(470,370,120,30,vfh[2],16,21,_Context->msg_SaveOnExit[_Context->language],strlen(_Context->msg_SaveOnExit[_Context->language]),2);
				_Context->keycode = visual_getch();
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
						/* Auto273 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* JustQuit */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(210,370,120,30,vfh[2],16,21,_Context->msg_JustQuit[_Context->language],strlen(_Context->msg_JustQuit[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(210,370,120,30,vfh[2],16,21,_Context->msg_JustQuit[_Context->language],strlen(_Context->msg_JustQuit[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_JustQuit_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* AbandonExit */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(340,370,120,30,vfh[2],16,21,_Context->msg_AbandonExit[_Context->language],strlen(_Context->msg_AbandonExit[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(340,370,120,30,vfh[2],16,21,_Context->msg_AbandonExit[_Context->language],strlen(_Context->msg_AbandonExit[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_AbandonExit_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* SaveOnExit */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(470,370,120,30,vfh[2],16,21,_Context->msg_SaveOnExit[_Context->language],strlen(_Context->msg_SaveOnExit[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
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
	char * pAuto283)
{
	int	status=0;
	struct accept_exit_context * _Context=(struct accept_exit_context*) 0;
	status = accept_exit_create(
	&_Context,
	 pAuto283);
	if ( status != 0) return(status);
	status = accept_exit_show(_Context);
		enter_modal();
	status = accept_exit_focus(_Context);
		leave_modal();
	status = accept_exit_hide(_Context);
	status = accept_exit_remove(
	_Context,
	 pAuto283);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vexit_c */
