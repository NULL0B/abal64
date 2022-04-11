
#ifndef _vview_c
#define _vview_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.39  */
/* Production     : C  */
/* Project        : vview.xml  */
/* Target         : vview.c  */
/* Identification : 0.0-1095165121-2859.2858 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
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
static int	vfh[10];

private struct accept_treeviewitem_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto1800[8];
	char	buffer_Auto1801[115];
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
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
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
		visual_transferin(_Context->buffer_Auto1801, 114, pAuto1801);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto1800[i]=" ";
	_Context->msg_Auto1800[0]=en_Auto1800;
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
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(50,30,510+10,100+10);
	return(0);
}

public 	int	accept_treeviewitem_hide(struct accept_treeviewitem_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,50,30);
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
		visual_transferout(_Context->buffer_Auto1801, 114, pAuto1801);
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
		(void)visual_buffer_get(_Context->pushbuffer,50,30);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(50,30,510,100,vfh[2],_Context->msg_Auto1800[_Context->language],strlen(_Context->msg_Auto1800[_Context->language]),0x407);
	visual_frame(60,80,456+2,32+2,5);
	visual_text(60+1,80+1,456,32,vfh[1],27,28,_Context->buffer_Auto1801,114,0);
	visual_text(60,60,460,20,vfh[2],16,0,_Context->msg_Auto1804[_Context->language],strlen(_Context->msg_Auto1804[_Context->language]),1282);
	_Context->trigger_Auto1802=visual_trigger_code(_Context->msg_Auto1802[_Context->language],strlen(_Context->msg_Auto1802[_Context->language]));
	visual_button(520,80,28,32,vfh[8],27,28,_Context->msg_Auto1802[_Context->language],strlen(_Context->msg_Auto1802[_Context->language]),0);
	visual_thaw(50,30,510,100);

	return(0);
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
	if (mt & _MIMO_UP) {
	if ((mx >= 539 )  
	&&  (my >= 34 )  
	&&  (mx <= 555 )  
	&&  (my <= 50 )) {
		return(1);	/* Auto1800 */

		}
	if ((mx >= 523 )  
	&&  (my >= 34 )  
	&&  (mx <= 539 )  
	&&  (my <= 50 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vview.htm");
			};
		return(-1);	/* Auto1800 */

		}
	if ((mx >= 507 )  
	&&  (my >= 34 )  
	&&  (mx <= 523 )  
	&&  (my <= 50 )) {
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
		}
	if (( mx >= 60 ) 
	&&  ( my >= 80 ) 
	&&  ( mx <= 516 ) 
	&&  ( my <= 112 )) {
		return(2); /* Auto1801 */
		}
	if (( mx >= 520 ) 
	&&  ( my >= 80 ) 
	&&  ( mx <= 548 ) 
	&&  ( my <= 112 )) {
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
				_Context->keycode = visual_edit(60+1,80+1,456,32,vfh[1],_Context->buffer_Auto1801,114);
			break;
			case	0x3 :
				/* Auto1802 */
				visual_button(520,80,28,32,vfh[8],27,28,_Context->msg_Auto1802[_Context->language],strlen(_Context->msg_Auto1802[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(520,80,28,32,vfh[8],27,28,_Context->msg_Auto1802[_Context->language],strlen(_Context->msg_Auto1802[_Context->language]),0);
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
							visual_button(520,80,28,32,vfh[8],27,28,_Context->msg_Auto1802[_Context->language],strlen(_Context->msg_Auto1802[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(520,80,28,32,vfh[8],27,28,_Context->msg_Auto1802[_Context->language],strlen(_Context->msg_Auto1802[_Context->language]),0);
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

#endif /* _vview_c */
