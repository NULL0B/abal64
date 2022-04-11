
#ifndef _vseek_c
#define _vseek_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vview.xml  */
/* Target         : vseek.c  */
/* Identification : 0.0-1100085502-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto1800   "Sing : Version 1.0a"
#define en_Auto1801   ""
#define en_Auto1804   "Tree View Item Search Pattern"
#define fr_Auto1804   "Pattern de Recherche d'une item TreeView"
#define it_Auto1804   "Tree View Item Search Pattern"
#define es_Auto1804   "Tree View Item Search Pattern"
#define de_Auto1804   "Tree View Item Search Pattern"
#define nl_Auto1804   "Tree View Item Search Pattern"
#define pt_Auto1804   "Tree View Item Search Pattern"
#define xx_Auto1804   "Tree View Item Search Pattern"
#define en_Auto1802   "OK"
#define fr_Auto1802   "Ok"
#define it_Auto1802   "Ok"
#define es_Auto1802   "Ok"
#define de_Auto1802   "Ok"
#define nl_Auto1802   "Ok"
#define pt_Auto1802   "Ok"
#define xx_Auto1802   "Ok"
static int	vfh[10];

private struct accept_treeviewitem_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto1800[8];
	int	x_Auto1800;
	int	y_Auto1800;
	int	w_Auto1800;
	int	h_Auto1800;
	char	buffer_Auto1801[58];
	char * msg_Auto1804[8];
	char * msg_Auto1802[8];
	int	trigger_Auto1802;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};

public	int	accept_treeviewitem_create(
	struct accept_treeviewitem_context ** cptr,
	char * pAuto1801)
{

	int i;
	struct accept_treeviewitem_context * _Context=(struct accept_treeviewitem_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_treeviewitem_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=3;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Auto1801, 57, pAuto1801);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto1800[i]=" ";
	_Context->msg_Auto1800[0]=en_Auto1800;
	_Context->x_Auto1800=50;
	_Context->y_Auto1800=30;
	_Context->w_Auto1800=510;
	_Context->h_Auto1800=80;
	_Context->window_col=50;
	_Context->window_row=30;
	for (i=0; i < 8; i++)_Context->msg_Auto1804[i]=" ";
	_Context->msg_Auto1804[0]=en_Auto1804;
	_Context->msg_Auto1804[1]=fr_Auto1804;
	_Context->msg_Auto1804[2]=it_Auto1804;
	_Context->msg_Auto1804[3]=es_Auto1804;
	_Context->msg_Auto1804[4]=de_Auto1804;
	_Context->msg_Auto1804[5]=nl_Auto1804;
	_Context->msg_Auto1804[6]=pt_Auto1804;
	_Context->msg_Auto1804[7]=xx_Auto1804;
	for (i=0; i < 8; i++)_Context->msg_Auto1802[i]=" ";
	_Context->msg_Auto1802[0]=en_Auto1802;
	_Context->msg_Auto1802[1]=fr_Auto1802;
	_Context->msg_Auto1802[2]=it_Auto1802;
	_Context->msg_Auto1802[3]=es_Auto1802;
	_Context->msg_Auto1802[4]=de_Auto1802;
	_Context->msg_Auto1802[5]=nl_Auto1802;
	_Context->msg_Auto1802[6]=pt_Auto1802;
	_Context->msg_Auto1802[7]=xx_Auto1802;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto1800,_Context->y_Auto1800,510+10,80+10);
	return(0);
}

public 	int	accept_treeviewitem_hide(struct accept_treeviewitem_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto1800,_Context->y_Auto1800);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_treeviewitem_remove(
	struct accept_treeviewitem_context * _Context,
	char * pAuto1801)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"S");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Auto1801, 57, pAuto1801);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_treeviewitem_show(struct accept_treeviewitem_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto1800,_Context->y_Auto1800);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto1800,_Context->y_Auto1800,510,80,vfh[2],_Context->msg_Auto1800[_Context->language],strlen(_Context->msg_Auto1800[_Context->language]),0x407);
	visual_frame(_Context->x_Auto1800+10,_Context->y_Auto1800+50,456+2,16+2,5);
	visual_text(_Context->x_Auto1800+10+1,_Context->y_Auto1800+50+1,456,16,vfh[1],27,28,_Context->buffer_Auto1801,57,0);
	visual_text(_Context->x_Auto1800+10,_Context->y_Auto1800+30,460,20,vfh[2],16,0,_Context->msg_Auto1804[_Context->language],strlen(_Context->msg_Auto1804[_Context->language]),1282);
	_Context->trigger_Auto1802=visual_trigger_code(_Context->msg_Auto1802[_Context->language],strlen(_Context->msg_Auto1802[_Context->language]));
	visual_button(_Context->x_Auto1800+470,_Context->y_Auto1800+30,32,40,vfh[2],27,28,_Context->msg_Auto1802[_Context->language],strlen(_Context->msg_Auto1802[_Context->language]),0);
	visual_thaw(_Context->x_Auto1800,_Context->y_Auto1800,510,80);
	visual_thaw(_Context->x_Auto1800,_Context->y_Auto1800,510,80);

	return(0);
}

private int Auto1800action(struct accept_treeviewitem_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_treeviewitem_hide(_Context);

		_Context->x_Auto1800 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto1800 < 0) { _Context->x_Auto1800=0; }
		_Context->y_Auto1800 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto1800 < 0) { _Context->y_Auto1800=0; }
			accept_treeviewitem_show(_Context);

		visual_thaw(_Context->x_Auto1800,_Context->y_Auto1800,510,80);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Auto1802_event(struct accept_treeviewitem_context * _Context) {
	return(13);
	return(-1);
}


public	int	accept_treeviewitem_event(
struct accept_treeviewitem_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto1802 == mb ) return(3);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto1800+489) )  
	&&  (my >= (_Context->y_Auto1800+4) )  
	&&  (mx <= (_Context->x_Auto1800+506) )  
	&&  (my <= (_Context->y_Auto1800+20) )) {
		return(1);	/* Auto1800 */

		}
	if ((mx >= (_Context->x_Auto1800+473) )  
	&&  (my >= (_Context->y_Auto1800+4) )  
	&&  (mx <= (_Context->x_Auto1800+490) )  
	&&  (my <= (_Context->y_Auto1800+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vseek.htm");
			};
		return(-1);	/* Auto1800 */

		}
	if ((mx >= (_Context->x_Auto1800+457) )  
	&&  (my >= (_Context->y_Auto1800+4) )  
	&&  (mx <= (_Context->x_Auto1800+474) )  
	&&  (my <= (_Context->y_Auto1800+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_treeviewitem_show(_Context);
		return(-1);	/* Auto1800 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto1800+4) )  
		&&  (my >= (_Context->y_Auto1800+4) )  
		&&  (mx <= (_Context->x_Auto1800+442) )  
		&&  (my <= (_Context->y_Auto1800+20) )) {
			return( Auto1800action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto1800+10) ) 
	&&  ( my >= (_Context->y_Auto1800+50) ) 
	&&  ( mx <= (_Context->x_Auto1800+10+456) ) 
	&&  ( my <= (_Context->y_Auto1800+50+16))) {
		return(2); /* Auto1801 */
		}
	if (( mx >= (_Context->x_Auto1800+470) ) 
	&&  ( my >= (_Context->y_Auto1800+30) ) 
	&&  ( mx <= (_Context->x_Auto1800+470+32) ) 
	&&  ( my <= (_Context->y_Auto1800+30+40))) {
		return(3); /* Auto1802 */
		}

	return(-1);
}


public	int	accept_treeviewitem_focus(struct accept_treeviewitem_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto1801 */
				_Context->keycode = visual_edit(_Context->x_Auto1800+10+1,_Context->y_Auto1800+50+1,456,16,vfh[1],_Context->buffer_Auto1801,57);
			break;
			case	0x3 :
				/* Auto1802 */
				visual_button(_Context->x_Auto1800+470,_Context->y_Auto1800+30,32,40,vfh[2],27,28,_Context->msg_Auto1802[_Context->language],strlen(_Context->msg_Auto1802[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto1800+470,_Context->y_Auto1800+30,32,40,vfh[2],27,28,_Context->msg_Auto1802[_Context->language],strlen(_Context->msg_Auto1802[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_treeviewitem_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=3;
			accept_treeviewitem_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_treeviewitem_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1800 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Auto1801 */
						continue;
					case	0x3 :
						/* Auto1802 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1800+470,_Context->y_Auto1800+30,32,40,vfh[2],27,28,_Context->msg_Auto1802[_Context->language],strlen(_Context->msg_Auto1802[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1800+470,_Context->y_Auto1800+30,32,40,vfh[2],27,28,_Context->msg_Auto1802[_Context->language],strlen(_Context->msg_Auto1802[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1802_event(_Context)) != -1) break;

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
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_treeviewitem(
	char * pAuto1801)
{
	int	status=0;
	struct accept_treeviewitem_context * _Context=(struct accept_treeviewitem_context*) 0;
	status = accept_treeviewitem_create(
	&_Context,
	 pAuto1801);
	if ( status != 0) return(status);
	status = accept_treeviewitem_show(_Context);
		enter_modal();
	status = accept_treeviewitem_focus(_Context);
		leave_modal();
	status = accept_treeviewitem_hide(_Context);
	status = accept_treeviewitem_remove(
	_Context,
	 pAuto1801);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vseek_c */
