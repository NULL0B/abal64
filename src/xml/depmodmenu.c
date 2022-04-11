
#ifndef _depmodmenu_c
#define _depmodmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : depmodmenu.xml                                           */
/* Target         : depmodmenu.c                                             */
/* Identification : 0.0-1196021476-17513.17512                               */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#include "singfmed.h"
#define en_Auto310   "Sing Version 2.1a"
#define fr_Auto310   "Sing Version 2.1a"
#define it_Auto310   "Sing Version 2.1a"
#define es_Auto310   "Sing Version 2.1a"
#define de_Auto310   "Sing Version 2.1a"
#define nl_Auto310   "Sing Version 2.1a"
#define pt_Auto310   "Sing Version 2.1a"
#define xx_Auto310   "Sing Version 2.1a"
#define en__Auto310   ""
#define fr__Auto310   ""
#define it__Auto310   ""
#define es__Auto310   ""
#define de__Auto310   ""
#define nl__Auto310   ""
#define pt__Auto310   ""
#define xx__Auto310   ""
#define en_Auto311   "&Toggle Forms Detail"
#define fr_Auto311   "&Toggle Forms Detail"
#define it_Auto311   "&Toggle Forms Detail"
#define es_Auto311   "&Toggle Forms Detail"
#define de_Auto311   "&Toggle Forms Detail"
#define nl_Auto311   "&Toggle Forms Detail"
#define pt_Auto311   "&Toggle Forms Detail"
#define xx_Auto311   "&Toggle Forms Detail"
#define en__Auto311   ""
#define fr__Auto311   ""
#define it__Auto311   ""
#define es__Auto311   ""
#define de__Auto311   ""
#define nl__Auto311   ""
#define pt__Auto311   ""
#define xx__Auto311   ""
#define en_Auto312   "T&oggle Forms Solo"
#define fr_Auto312   "T&oggle Forms Detail"
#define it_Auto312   "T&oggle Forms Detail"
#define es_Auto312   "T&oggle Forms Detail"
#define de_Auto312   "T&oggle Forms Detail"
#define nl_Auto312   "T&oggle Forms Detail"
#define pt_Auto312   "T&oggle Forms Detail"
#define xx_Auto312   "T&oggle Forms Detail"
#define en__Auto312   ""
#define fr__Auto312   ""
#define it__Auto312   ""
#define es__Auto312   ""
#define de__Auto312   ""
#define nl__Auto312   ""
#define pt__Auto312   ""
#define xx__Auto312   ""
#define en_Auto313   "&Calculate Best Positioning"
#define fr_Auto313   "&Calculate Best Positioning"
#define it_Auto313   "&Calculate Best Positioning"
#define es_Auto313   "&Calculate Best Positioning"
#define de_Auto313   "&Calculate Best Positioning"
#define nl_Auto313   "&Calculate Best Positioning"
#define pt_Auto313   "&Calculate Best Positioning"
#define xx_Auto313   "&Calculate Best Positioning"
#define en__Auto313   ""
#define fr__Auto313   ""
#define it__Auto313   ""
#define es__Auto313   ""
#define de__Auto313   ""
#define nl__Auto313   ""
#define pt__Auto313   ""
#define xx__Auto313   ""

private struct dependance_model_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto310[8];
	char * hint_Auto310[8];
	int	s_Auto310;
	void *	p_Auto310;
	int	x_Auto310;
	int	y_Auto310;
	int	w_Auto310;
	int	h_Auto310;
	char * msg_Auto311[8];
	int	trigger_Auto311;
	char * hint_Auto311[8];
	char * msg_Auto312[8];
	int	trigger_Auto312;
	char * hint_Auto312[8];
	char * msg_Auto313[8];
	int	trigger_Auto313;
	char * hint_Auto313[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct dependance_model_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = dependance_model_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}

private int on_Auto310_create(struct dependance_model_menu_context * _Context) {
	mouse_move_on();
	_Context->y_Auto310=visual_event(6);
	_Context->x_Auto310=visual_event(7);
	return(-1);
}

public	int	dependance_model_menu_create(struct dependance_model_menu_context **cptr)
{

	int i;
	struct dependance_model_menu_context * _Context=(struct dependance_model_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct dependance_model_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=3;
	for (i=0; i < 8; i++)_Context->msg_Auto310[i]=" ";
	_Context->msg_Auto310[0]=en_Auto310;
	_Context->msg_Auto310[1]=fr_Auto310;
	_Context->msg_Auto310[2]=it_Auto310;
	_Context->msg_Auto310[3]=es_Auto310;
	_Context->msg_Auto310[4]=de_Auto310;
	_Context->msg_Auto310[5]=nl_Auto310;
	_Context->msg_Auto310[6]=pt_Auto310;
	_Context->msg_Auto310[7]=xx_Auto310;
	_Context->hint_Auto310[0]=en__Auto310;
	_Context->hint_Auto310[1]=fr__Auto310;
	_Context->hint_Auto310[2]=it__Auto310;
	_Context->hint_Auto310[3]=es__Auto310;
	_Context->hint_Auto310[4]=de__Auto310;
	_Context->hint_Auto310[5]=nl__Auto310;
	_Context->hint_Auto310[6]=pt__Auto310;
	_Context->hint_Auto310[7]=xx__Auto310;
	_Context->s_Auto310=0;
	_Context->p_Auto310=visual_buffer(_Context->x_Auto310,_Context->y_Auto310,312+2,96+2);
	_Context->x_Auto310=40;
	_Context->y_Auto310=44;
	_Context->w_Auto310=312;
	_Context->h_Auto310=96;
	_Context->window_col=40;
	_Context->window_row=44;
	(void) on_Auto310_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Auto311[i]=" ";
	_Context->msg_Auto311[0]=en_Auto311;
	_Context->msg_Auto311[1]=fr_Auto311;
	_Context->msg_Auto311[2]=it_Auto311;
	_Context->msg_Auto311[3]=es_Auto311;
	_Context->msg_Auto311[4]=de_Auto311;
	_Context->msg_Auto311[5]=nl_Auto311;
	_Context->msg_Auto311[6]=pt_Auto311;
	_Context->msg_Auto311[7]=xx_Auto311;
	_Context->hint_Auto311[0]=en__Auto311;
	_Context->hint_Auto311[1]=fr__Auto311;
	_Context->hint_Auto311[2]=it__Auto311;
	_Context->hint_Auto311[3]=es__Auto311;
	_Context->hint_Auto311[4]=de__Auto311;
	_Context->hint_Auto311[5]=nl__Auto311;
	_Context->hint_Auto311[6]=pt__Auto311;
	_Context->hint_Auto311[7]=xx__Auto311;
	for (i=0; i < 8; i++)_Context->msg_Auto312[i]=" ";
	_Context->msg_Auto312[0]=en_Auto312;
	_Context->msg_Auto312[1]=fr_Auto312;
	_Context->msg_Auto312[2]=it_Auto312;
	_Context->msg_Auto312[3]=es_Auto312;
	_Context->msg_Auto312[4]=de_Auto312;
	_Context->msg_Auto312[5]=nl_Auto312;
	_Context->msg_Auto312[6]=pt_Auto312;
	_Context->msg_Auto312[7]=xx_Auto312;
	_Context->hint_Auto312[0]=en__Auto312;
	_Context->hint_Auto312[1]=fr__Auto312;
	_Context->hint_Auto312[2]=it__Auto312;
	_Context->hint_Auto312[3]=es__Auto312;
	_Context->hint_Auto312[4]=de__Auto312;
	_Context->hint_Auto312[5]=nl__Auto312;
	_Context->hint_Auto312[6]=pt__Auto312;
	_Context->hint_Auto312[7]=xx__Auto312;
	for (i=0; i < 8; i++)_Context->msg_Auto313[i]=" ";
	_Context->msg_Auto313[0]=en_Auto313;
	_Context->msg_Auto313[1]=fr_Auto313;
	_Context->msg_Auto313[2]=it_Auto313;
	_Context->msg_Auto313[3]=es_Auto313;
	_Context->msg_Auto313[4]=de_Auto313;
	_Context->msg_Auto313[5]=nl_Auto313;
	_Context->msg_Auto313[6]=pt_Auto313;
	_Context->msg_Auto313[7]=xx_Auto313;
	_Context->hint_Auto313[0]=en__Auto313;
	_Context->hint_Auto313[1]=fr__Auto313;
	_Context->hint_Auto313[2]=it__Auto313;
	_Context->hint_Auto313[3]=es__Auto313;
	_Context->hint_Auto313[4]=de__Auto313;
	_Context->hint_Auto313[5]=nl__Auto313;
	_Context->hint_Auto313[6]=pt__Auto313;
	_Context->hint_Auto313[7]=xx__Auto313;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto310,_Context->y_Auto310,312,96);
	return(0);
}

public 	int	dependance_model_menu_hide(struct dependance_model_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto310 != (void *) 0)
	&& (_Context->s_Auto310 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto310,_Context->x_Auto310,_Context->y_Auto310);
		_Context->s_Auto310=0;
		}
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto310,_Context->y_Auto310);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	dependance_model_menu_remove(struct dependance_model_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	mouse_move_off();
	if (_Context->p_Auto310 != (void *) 0)
		_Context->p_Auto310 = visual_drop(_Context->p_Auto310);
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	dependance_model_menu_show(struct dependance_model_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto310,_Context->y_Auto310);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if ((_Context->p_Auto310 != (void *) 0)
	&& (_Context->s_Auto310 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto310,_Context->x_Auto310,_Context->y_Auto310);
		_Context->s_Auto310=1;
		}
	if (((_Context->status = visual_styled_element(_Context->x_Auto310,_Context->y_Auto310,312,96,GetWidgetStyle(1),_Context->msg_Auto310[_Context->language],strlen(_Context->msg_Auto310[_Context->language]))) != 0)
) {
		visual_window(_Context->x_Auto310,_Context->y_Auto310,312,96,vfh[1],_Context->msg_Auto310[_Context->language],strlen(_Context->msg_Auto310[_Context->language]),0x4);
		}
	_Context->trigger_Auto311=visual_trigger_code(_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto310+16,_Context->y_Auto310+16,272,20,GetWidgetStyle(2),_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto310+16,_Context->y_Auto310+16,272,20,vfh[2],16,0,_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]),32);
		}
	_Context->trigger_Auto312=visual_trigger_code(_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto310+16,_Context->y_Auto310+40,272,20,GetWidgetStyle(2),_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto310+16,_Context->y_Auto310+40,272,20,vfh[2],16,0,_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]),32);
		}
	_Context->trigger_Auto313=visual_trigger_code(_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto310+16,_Context->y_Auto310+64,280,20,GetWidgetStyle(2),_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto310+16,_Context->y_Auto310+64,280,20,vfh[2],16,0,_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]),32);
		}
	visual_thaw(_Context->x_Auto310,_Context->y_Auto310,312,96);

	return(0);
}
private int on_Auto311_event(struct dependance_model_menu_context * _Context) {
	return(_FLOW_DETAIL);
	return(-1);
}
private int on_Auto312_event(struct dependance_model_menu_context * _Context) {
	return(_FLOW_SOLO);
	return(-1);
}
private int on_Auto313_event(struct dependance_model_menu_context * _Context) {
	return(_FLOW_BEST);
	return(-1);
}


public	int	dependance_model_menu_event(
struct dependance_model_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto311 == mb ) return(1);
		if (_Context->trigger_Auto312 == mb ) return(2);
		if (_Context->trigger_Auto313 == mb ) return(3);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_Auto310+16) ) 
	&&  ( my >= (_Context->y_Auto310+16) ) 
	&&  ( mx <= (_Context->x_Auto310+16+272) ) 
	&&  ( my <= (_Context->y_Auto310+16+20))) {
		return(1); /* Auto311 */
		}
	if (( mx >= (_Context->x_Auto310+16) ) 
	&&  ( my >= (_Context->y_Auto310+40) ) 
	&&  ( mx <= (_Context->x_Auto310+16+272) ) 
	&&  ( my <= (_Context->y_Auto310+40+20))) {
		return(2); /* Auto312 */
		}
	if (( mx >= (_Context->x_Auto310+16) ) 
	&&  ( my >= (_Context->y_Auto310+64) ) 
	&&  ( mx <= (_Context->x_Auto310+16+280) ) 
	&&  ( my <= (_Context->y_Auto310+64+20))) {
		return(3); /* Auto313 */
		}

	return(-1);
}


public	int	dependance_model_menu_focus(struct dependance_model_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto311 */
				_Context->trigger_Auto311=visual_trigger_code(_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto310+16,_Context->y_Auto310+16,272,20,GetWidgetStyle(3),_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto310+16,_Context->y_Auto310+16,272,20,vfh[2],16,0,_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto311=visual_trigger_code(_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto310+16,_Context->y_Auto310+16,272,20,GetWidgetStyle(2),_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto310+16,_Context->y_Auto310+16,272,20,vfh[2],16,0,_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto312 */
				_Context->trigger_Auto312=visual_trigger_code(_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto310+16,_Context->y_Auto310+40,272,20,GetWidgetStyle(3),_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto310+16,_Context->y_Auto310+40,272,20,vfh[2],16,0,_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto312=visual_trigger_code(_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto310+16,_Context->y_Auto310+40,272,20,GetWidgetStyle(2),_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto310+16,_Context->y_Auto310+40,272,20,vfh[2],16,0,_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto313 */
				_Context->trigger_Auto313=visual_trigger_code(_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto310+16,_Context->y_Auto310+64,280,20,GetWidgetStyle(3),_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto310+16,_Context->y_Auto310+64,280,20,vfh[2],16,0,_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto313=visual_trigger_code(_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto310+16,_Context->y_Auto310+64,280,20,GetWidgetStyle(2),_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto310+16,_Context->y_Auto310+64,280,20,vfh[2],16,0,_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			dependance_model_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=3;
			dependance_model_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  _Context->x_Auto310 )
				|| ( visual_event(6) < _Context->y_Auto310  )
				|| ( visual_event(7) > (_Context->x_Auto310+_Context->w_Auto310))
				|| ( visual_event(6) >  (_Context->y_Auto310+_Context->h_Auto310))) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=dependance_model_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto311 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto311=visual_trigger_code(_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto310+16,_Context->y_Auto310+16,272,20,GetWidgetStyle(3),_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto310+16,_Context->y_Auto310+16,272,20,vfh[2],16,0,_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto311=visual_trigger_code(_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto310+16,_Context->y_Auto310+16,272,20,GetWidgetStyle(2),_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto310+16,_Context->y_Auto310+16,272,20,vfh[2],16,0,_Context->msg_Auto311[_Context->language],strlen(_Context->msg_Auto311[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto311_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto312 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto312=visual_trigger_code(_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto310+16,_Context->y_Auto310+40,272,20,GetWidgetStyle(3),_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto310+16,_Context->y_Auto310+40,272,20,vfh[2],16,0,_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto312=visual_trigger_code(_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto310+16,_Context->y_Auto310+40,272,20,GetWidgetStyle(2),_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto310+16,_Context->y_Auto310+40,272,20,vfh[2],16,0,_Context->msg_Auto312[_Context->language],strlen(_Context->msg_Auto312[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto312_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto313 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto313=visual_trigger_code(_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto310+16,_Context->y_Auto310+64,280,20,GetWidgetStyle(3),_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto310+16,_Context->y_Auto310+64,280,20,vfh[2],16,0,_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto313=visual_trigger_code(_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto310+16,_Context->y_Auto310+64,280,20,GetWidgetStyle(2),_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto310+16,_Context->y_Auto310+64,280,20,vfh[2],16,0,_Context->msg_Auto313[_Context->language],strlen(_Context->msg_Auto313[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto313_event(_Context)) != -1) break;

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
		case	0x0 :
			
			continue;
		case	0xffffffff :
			
			continue;

			}
		break;
		}

	return( _Context->keycode );
}

public	int	dependance_model_menu()
{
	int	status=0;
	struct dependance_model_menu_context * _Context=(struct dependance_model_menu_context*) 0;
	status = dependance_model_menu_create(&_Context);
	if ( status != 0) return(status);
	status = dependance_model_menu_show(_Context);
		enter_modal();
	status = dependance_model_menu_focus(_Context);
		leave_modal();
	status = dependance_model_menu_hide(_Context);
	status = dependance_model_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _depmodmenu_c */
