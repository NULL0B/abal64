
#ifndef _methmenu_c
#define _methmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : methmenu.xml                                             */
/* Target         : methmenu.c                                               */
/* Identification : 0.0-1177512019-5209.5208                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#include "vwidget.h"
#define en_Auto625   "Forms Methods List"
#define fr_Auto625   "Liste des m‚thodes du formulaire"
#define it_Auto625   ""
#define es_Auto625   ""
#define de_Auto625   ""
#define nl_Auto625   ""
#define pt_Auto625   ""
#define xx_Auto625   ""
#define en__Auto625   ""
#define fr__Auto625   ""
#define it__Auto625   ""
#define es__Auto625   ""
#define de__Auto625   ""
#define nl__Auto625   ""
#define pt__Auto625   ""
#define xx__Auto625   ""
#define fr_Auto626   "a|b|c"
#define en__Auto626   ""
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"
#define en__Cancel   ""
#define fr__Cancel   ""
#define it__Cancel   ""
#define es__Cancel   ""
#define de__Cancel   ""
#define nl__Cancel   ""
#define pt__Cancel   ""
#define xx__Cancel   ""

private struct form_methods_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto625[8];
	char * hint_Auto625[8];
	int	x_Auto625;
	int	y_Auto625;
	int	w_Auto625;
	int	h_Auto625;
	char * msg_Auto626[8];
	char * hint_Auto626[8];
	int	value_Auto626;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[2];
	};
static int	vfh[16];

public	int	form_methods_menu_create(
	struct form_methods_menu_context ** cptr,
	char * pAuto626)
{

	int i;
	struct form_methods_menu_context * _Context=(struct form_methods_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct form_methods_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=3;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"W");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pAuto626);
		if (!( pAuto626 )) _Context->value_Auto626=0;
		else	_Context->value_Auto626 = *((int *)pAuto626);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto625[i]=" ";
	_Context->msg_Auto625[0]=en_Auto625;
	_Context->msg_Auto625[1]=fr_Auto625;
	_Context->msg_Auto625[2]=it_Auto625;
	_Context->msg_Auto625[3]=es_Auto625;
	_Context->msg_Auto625[4]=de_Auto625;
	_Context->msg_Auto625[5]=nl_Auto625;
	_Context->msg_Auto625[6]=pt_Auto625;
	_Context->msg_Auto625[7]=xx_Auto625;
	_Context->hint_Auto625[0]=en__Auto625;
	_Context->hint_Auto625[1]=fr__Auto625;
	_Context->hint_Auto625[2]=it__Auto625;
	_Context->hint_Auto625[3]=es__Auto625;
	_Context->hint_Auto625[4]=de__Auto625;
	_Context->hint_Auto625[5]=nl__Auto625;
	_Context->hint_Auto625[6]=pt__Auto625;
	_Context->hint_Auto625[7]=xx__Auto625;
	_Context->x_Auto625=50;
	_Context->y_Auto625=40;
	_Context->w_Auto625=300;
	_Context->h_Auto625=490;
	_Context->window_col=50;
	_Context->window_row=40;
	for (i=0; i < 8; i++)_Context->msg_Auto626[i]=" ";
	_Context->msg_Auto626[1]=fr_Auto626;
	_Context->hint_Auto626[0]=en__Auto626;
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
	_Context->hint_Cancel[1]=fr__Cancel;
	_Context->hint_Cancel[2]=it__Cancel;
	_Context->hint_Cancel[3]=es__Cancel;
	_Context->hint_Cancel[4]=de__Cancel;
	_Context->hint_Cancel[5]=nl__Cancel;
	_Context->hint_Cancel[6]=pt__Cancel;
	_Context->hint_Cancel[7]=xx__Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto625,_Context->y_Auto625,300+10,490+10);
	return(0);
}

public 	int	form_methods_menu_hide(struct form_methods_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto625,_Context->y_Auto625);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	form_methods_menu_remove(
	struct form_methods_menu_context * _Context,
	char * pAuto626)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"W");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pAuto626);
		if ( pAuto626 != (char *) 0)
			*((int*)pAuto626) = _Context->value_Auto626;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	form_methods_menu_show(struct form_methods_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto625,_Context->y_Auto625);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto625,_Context->y_Auto625,300,490,vfh[2],_Context->msg_Auto625[_Context->language],strlen(_Context->msg_Auto625[_Context->language]),0x405);
	visual_select(_Context->x_Auto625+10,_Context->y_Auto625+30,280,400,vfh[1],27,0,parse_selection(FormsMethodNames(),&_Context->value_Auto626),65536);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto625+250,_Context->y_Auto625+440,40,40,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1072);
	visual_thaw(_Context->x_Auto625,_Context->y_Auto625,300,490);

	return(0);
}

private int Auto625action(struct form_methods_menu_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			form_methods_menu_hide(_Context);

		_Context->x_Auto625 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto625 < 0) { _Context->x_Auto625=0; }
		_Context->y_Auto625 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto625 < 0) { _Context->y_Auto625=0; }
			form_methods_menu_show(_Context);

		visual_thaw(_Context->x_Auto625,_Context->y_Auto625,300,490);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto626_event(struct form_methods_menu_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct form_methods_menu_context * _Context) {
	return(27);
	return(-1);
}


public	int	form_methods_menu_event(
struct form_methods_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Cancel == mb ) return(3);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto625+279) )  
	&&  (my >= (_Context->y_Auto625+4) )  
	&&  (mx <= (_Context->x_Auto625+296) )  
	&&  (my <= (_Context->y_Auto625+20) )) {
		return(1);	/* Auto625 */

		}
	if ((mx >= (_Context->x_Auto625+247) )  
	&&  (my >= (_Context->y_Auto625+4) )  
	&&  (mx <= (_Context->x_Auto625+264) )  
	&&  (my <= (_Context->y_Auto625+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		form_methods_menu_show(_Context);
		return(-1);	/* Auto625 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto625+4) )  
		&&  (my >= (_Context->y_Auto625+4) )  
		&&  (mx <= (_Context->x_Auto625+232) )  
		&&  (my <= (_Context->y_Auto625+20) )) {
			return( Auto625action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto625+10+0) ) 
	&&  ( my >= (_Context->y_Auto625+30) ) 
	&&  ( mx <= (_Context->x_Auto625+10+280) ) 
	&&  ( my <= (_Context->y_Auto625+30+16))) {
		return(2); /* Auto626 */
		}
	if (( mx >= (_Context->x_Auto625+250) ) 
	&&  ( my >= (_Context->y_Auto625+440) ) 
	&&  ( mx <= (_Context->x_Auto625+250+40) ) 
	&&  ( my <= (_Context->y_Auto625+440+40))) {
		return(3); /* Cancel */
		}

	return(-1);
}


public	int	form_methods_menu_focus(struct form_methods_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto626 */
				_Context->keycode = visual_select(_Context->x_Auto625+10,_Context->y_Auto625+30,280,400,vfh[1],27,0,parse_selection(FormsMethodNames(),&_Context->value_Auto626),65550);
				if(!(_Context->keycode)){
				_Context->keycode=13;
				}
				break;
			case	0x3 :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_Auto625+250,_Context->y_Auto625+440,40,40,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1074);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto625+250,_Context->y_Auto625+440,40,40,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1072);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			form_methods_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=3;
			form_methods_menu_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=form_methods_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto625 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Auto626 */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto626_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Auto625+250,_Context->y_Auto625+440,40,40,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1074);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto625+250,_Context->y_Auto625+440,40,40,vfh[1],27,28,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1072);
						}
					if ( visual_event(1) &  0x10 ) {
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

public	int	form_methods_menu(
	char * pAuto626)
{
	int	status=0;
	struct form_methods_menu_context * _Context=(struct form_methods_menu_context*) 0;
	status = form_methods_menu_create(
	&_Context,
	 pAuto626);
	if ( status != 0) return(status);
	status = form_methods_menu_show(_Context);
		enter_modal();
	status = form_methods_menu_focus(_Context);
		leave_modal();
	status = form_methods_menu_hide(_Context);
	status = form_methods_menu_remove(
	_Context,
	 pAuto626);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _methmenu_c */
