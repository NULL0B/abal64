
#ifndef _linkmenu_c
#define _linkmenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : linkmenu.xml                                             */
/* Target         : linkmenu.c                                               */
/* Identification : 0.0-1197225563-30633.30632                               */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#include "singdbed.h"
#define en_Auto337   "Sing Version 2.1a"
#define fr_Auto337   "Sing Version 2.1a"
#define it_Auto337   "Sing Version 2.1a"
#define es_Auto337   "Sing Version 2.1a"
#define de_Auto337   "Sing Version 2.1a"
#define nl_Auto337   "Sing Version 2.1a"
#define pt_Auto337   "Sing Version 2.1a"
#define xx_Auto337   "Sing Version 2.1a"
#define en__Auto337   ""
#define fr__Auto337   ""
#define it__Auto337   ""
#define es__Auto337   ""
#define de__Auto337   ""
#define nl__Auto337   ""
#define pt__Auto337   ""
#define xx__Auto337   ""
#define en_Auto338   "&Inspect the Relation/Link Properties"
#define fr_Auto338   "&Inspecter PropriŠt‚s du Relation"
#define it_Auto338   "&Inspect the Relation/Link Properties"
#define es_Auto338   "&Inspect the Relation/Link Properties"
#define de_Auto338   "&Inspect the Relation/Link Properties"
#define nl_Auto338   "&Inspect the Relation/Link Properties"
#define pt_Auto338   "&Inspect the Relation/Link Properties"
#define xx_Auto338   "&Inspect the Relation/Link Properties"
#define en__Auto338   ""
#define fr__Auto338   ""
#define it__Auto338   ""
#define es__Auto338   ""
#define de__Auto338   ""
#define nl__Auto338   ""
#define pt__Auto338   ""
#define xx__Auto338   ""
#define en_Auto339   "&Delete the Relation/Link for this Member"
#define fr_Auto339   "&Supprimer un Relation de ce Membre"
#define it_Auto339   "&Delete the Relation/Link for this Member"
#define es_Auto339   "&Delete the Relation/Link for this Member"
#define de_Auto339   "&Delete the Relation/Link for this Member"
#define nl_Auto339   "&Delete the Relation/Link for this Member"
#define pt_Auto339   "&Delete the Relation/Link for this Member"
#define xx_Auto339   "&Delete the Relation/Link for this Member"
#define en__Auto339   ""
#define fr__Auto339   ""
#define it__Auto339   ""
#define es__Auto339   ""
#define de__Auto339   ""
#define nl__Auto339   ""
#define pt__Auto339   ""
#define xx__Auto339   ""
#define en_Auto340   "&Redefine the Relation/Link Target Member"
#define fr_Auto340   "&Redefinir le Cible de ce Relation"
#define it_Auto340   "&Redefine the Relation/Link Target Member"
#define es_Auto340   "&Redefine the Relation/Link Target Member"
#define de_Auto340   "&Redefine the Relation/Link Target Member"
#define nl_Auto340   "&Redefine the Relation/Link Target Member"
#define pt_Auto340   "&Redefine the Relation/Link Target Member"
#define xx_Auto340   "&Redefine the Relation/Link Target Member"
#define en__Auto340   ""
#define fr__Auto340   ""
#define it__Auto340   ""
#define es__Auto340   ""
#define de__Auto340   ""
#define nl__Auto340   ""
#define pt__Auto340   ""
#define xx__Auto340   ""

private struct database_link_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto337[8];
	char * hint_Auto337[8];
	int	s_Auto337;
	void *	p_Auto337;
	int	x_Auto337;
	int	y_Auto337;
	int	w_Auto337;
	int	h_Auto337;
	char * msg_Auto338[8];
	int	trigger_Auto338;
	char * hint_Auto338[8];
	char * msg_Auto339[8];
	int	trigger_Auto339;
	char * hint_Auto339[8];
	char * msg_Auto340[8];
	int	trigger_Auto340;
	char * hint_Auto340[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct database_link_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = database_link_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}

private int on_Auto337_create(struct database_link_menu_context * _Context) {
	mouse_move_on();
	if(((_Context->y_Auto337=visual_event(6))+88)>hardrows())
	_Context->y_Auto337=(hardrows()-88);
	if(((_Context->x_Auto337=visual_event(7))+312)>hardcolumns())
	_Context->x_Auto337=(hardcolumns()-312);
	return(-1);
}

public	int	database_link_menu_create(struct database_link_menu_context **cptr)
{

	int i;
	struct database_link_menu_context * _Context=(struct database_link_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct database_link_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=3;
	for (i=0; i < 8; i++)_Context->msg_Auto337[i]=" ";
	_Context->msg_Auto337[0]=en_Auto337;
	_Context->msg_Auto337[1]=fr_Auto337;
	_Context->msg_Auto337[2]=it_Auto337;
	_Context->msg_Auto337[3]=es_Auto337;
	_Context->msg_Auto337[4]=de_Auto337;
	_Context->msg_Auto337[5]=nl_Auto337;
	_Context->msg_Auto337[6]=pt_Auto337;
	_Context->msg_Auto337[7]=xx_Auto337;
	_Context->hint_Auto337[0]=en__Auto337;
	_Context->hint_Auto337[1]=fr__Auto337;
	_Context->hint_Auto337[2]=it__Auto337;
	_Context->hint_Auto337[3]=es__Auto337;
	_Context->hint_Auto337[4]=de__Auto337;
	_Context->hint_Auto337[5]=nl__Auto337;
	_Context->hint_Auto337[6]=pt__Auto337;
	_Context->hint_Auto337[7]=xx__Auto337;
	_Context->s_Auto337=0;
	_Context->p_Auto337=visual_buffer(_Context->x_Auto337,_Context->y_Auto337,312+2,88+2);
	_Context->x_Auto337=40;
	_Context->y_Auto337=36;
	_Context->w_Auto337=312;
	_Context->h_Auto337=88;
	_Context->window_col=40;
	_Context->window_row=36;
	(void) on_Auto337_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Auto338[i]=" ";
	_Context->msg_Auto338[0]=en_Auto338;
	_Context->msg_Auto338[1]=fr_Auto338;
	_Context->msg_Auto338[2]=it_Auto338;
	_Context->msg_Auto338[3]=es_Auto338;
	_Context->msg_Auto338[4]=de_Auto338;
	_Context->msg_Auto338[5]=nl_Auto338;
	_Context->msg_Auto338[6]=pt_Auto338;
	_Context->msg_Auto338[7]=xx_Auto338;
	_Context->hint_Auto338[0]=en__Auto338;
	_Context->hint_Auto338[1]=fr__Auto338;
	_Context->hint_Auto338[2]=it__Auto338;
	_Context->hint_Auto338[3]=es__Auto338;
	_Context->hint_Auto338[4]=de__Auto338;
	_Context->hint_Auto338[5]=nl__Auto338;
	_Context->hint_Auto338[6]=pt__Auto338;
	_Context->hint_Auto338[7]=xx__Auto338;
	for (i=0; i < 8; i++)_Context->msg_Auto339[i]=" ";
	_Context->msg_Auto339[0]=en_Auto339;
	_Context->msg_Auto339[1]=fr_Auto339;
	_Context->msg_Auto339[2]=it_Auto339;
	_Context->msg_Auto339[3]=es_Auto339;
	_Context->msg_Auto339[4]=de_Auto339;
	_Context->msg_Auto339[5]=nl_Auto339;
	_Context->msg_Auto339[6]=pt_Auto339;
	_Context->msg_Auto339[7]=xx_Auto339;
	_Context->hint_Auto339[0]=en__Auto339;
	_Context->hint_Auto339[1]=fr__Auto339;
	_Context->hint_Auto339[2]=it__Auto339;
	_Context->hint_Auto339[3]=es__Auto339;
	_Context->hint_Auto339[4]=de__Auto339;
	_Context->hint_Auto339[5]=nl__Auto339;
	_Context->hint_Auto339[6]=pt__Auto339;
	_Context->hint_Auto339[7]=xx__Auto339;
	for (i=0; i < 8; i++)_Context->msg_Auto340[i]=" ";
	_Context->msg_Auto340[0]=en_Auto340;
	_Context->msg_Auto340[1]=fr_Auto340;
	_Context->msg_Auto340[2]=it_Auto340;
	_Context->msg_Auto340[3]=es_Auto340;
	_Context->msg_Auto340[4]=de_Auto340;
	_Context->msg_Auto340[5]=nl_Auto340;
	_Context->msg_Auto340[6]=pt_Auto340;
	_Context->msg_Auto340[7]=xx_Auto340;
	_Context->hint_Auto340[0]=en__Auto340;
	_Context->hint_Auto340[1]=fr__Auto340;
	_Context->hint_Auto340[2]=it__Auto340;
	_Context->hint_Auto340[3]=es__Auto340;
	_Context->hint_Auto340[4]=de__Auto340;
	_Context->hint_Auto340[5]=nl__Auto340;
	_Context->hint_Auto340[6]=pt__Auto340;
	_Context->hint_Auto340[7]=xx__Auto340;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto337,_Context->y_Auto337,312,88);
	return(0);
}

public 	int	database_link_menu_hide(struct database_link_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto337 != (void *) 0)
	&& (_Context->s_Auto337 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto337,_Context->x_Auto337,_Context->y_Auto337);
		_Context->s_Auto337=0;
		}
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto337,_Context->y_Auto337);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	database_link_menu_remove(struct database_link_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	mouse_move_off();
	if (_Context->p_Auto337 != (void *) 0)
		_Context->p_Auto337 = visual_drop(_Context->p_Auto337);
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	database_link_menu_show(struct database_link_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto337,_Context->y_Auto337);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if ((_Context->p_Auto337 != (void *) 0)
	&& (_Context->s_Auto337 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto337,_Context->x_Auto337,_Context->y_Auto337);
		_Context->s_Auto337=1;
		}
	if (((_Context->status = visual_styled_element(_Context->x_Auto337,_Context->y_Auto337,312,88,GetWidgetStyle(1),_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]))) != 0)
) {
		visual_window(_Context->x_Auto337,_Context->y_Auto337,312,88,vfh[1],_Context->msg_Auto337[_Context->language],strlen(_Context->msg_Auto337[_Context->language]),0x4);
		}
	_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto337+16,_Context->y_Auto337+12,280,24,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+16,_Context->y_Auto337+12,280,24,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
		}
	_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto337+16,_Context->y_Auto337+36,280,20,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+16,_Context->y_Auto337+36,280,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
		}
	_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto337+16,_Context->y_Auto337+56,272,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+16,_Context->y_Auto337+56,272,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
		}
	visual_thaw(_Context->x_Auto337,_Context->y_Auto337,312,88);

	return(0);
}
private int on_Auto338_event(struct database_link_menu_context * _Context) {
	return(_LINK_INFO);
	return(-1);
}
private int on_Auto339_event(struct database_link_menu_context * _Context) {
	return(_LINK_DELETE);
	return(-1);
}
private int on_Auto340_event(struct database_link_menu_context * _Context) {
	return(_LINK_MOVE);
	return(-1);
}


public	int	database_link_menu_event(
struct database_link_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto338 == mb ) return(1);
		if (_Context->trigger_Auto339 == mb ) return(2);
		if (_Context->trigger_Auto340 == mb ) return(3);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_Auto337+16) ) 
	&&  ( my >= (_Context->y_Auto337+12) ) 
	&&  ( mx <= (_Context->x_Auto337+16+280) ) 
	&&  ( my <= (_Context->y_Auto337+12+24))) {
		return(1); /* Auto338 */
		}
	if (( mx >= (_Context->x_Auto337+16) ) 
	&&  ( my >= (_Context->y_Auto337+36) ) 
	&&  ( mx <= (_Context->x_Auto337+16+280) ) 
	&&  ( my <= (_Context->y_Auto337+36+20))) {
		return(2); /* Auto339 */
		}
	if (( mx >= (_Context->x_Auto337+16) ) 
	&&  ( my >= (_Context->y_Auto337+56) ) 
	&&  ( mx <= (_Context->x_Auto337+16+272) ) 
	&&  ( my <= (_Context->y_Auto337+56+20))) {
		return(3); /* Auto340 */
		}

	return(-1);
}


public	int	database_link_menu_focus(struct database_link_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto338 */
				_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+16,_Context->y_Auto337+12,280,24,GetWidgetStyle(3),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto337+16,_Context->y_Auto337+12,280,24,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+16,_Context->y_Auto337+12,280,24,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+16,_Context->y_Auto337+12,280,24,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto339 */
				_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+16,_Context->y_Auto337+36,280,20,GetWidgetStyle(3),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto337+16,_Context->y_Auto337+36,280,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+16,_Context->y_Auto337+36,280,20,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+16,_Context->y_Auto337+36,280,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto340 */
				_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+16,_Context->y_Auto337+56,272,20,GetWidgetStyle(3),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto337+16,_Context->y_Auto337+56,272,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto337+16,_Context->y_Auto337+56,272,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+16,_Context->y_Auto337+56,272,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			database_link_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=3;
			database_link_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  _Context->x_Auto337 )
				|| ( visual_event(6) < _Context->y_Auto337  )
				|| ( visual_event(7) > (_Context->x_Auto337+_Context->w_Auto337))
				|| ( visual_event(6) >  (_Context->y_Auto337+_Context->h_Auto337))) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=database_link_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto338 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+16,_Context->y_Auto337+12,280,24,GetWidgetStyle(3),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto337+16,_Context->y_Auto337+12,280,24,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto338=visual_trigger_code(_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+16,_Context->y_Auto337+12,280,24,GetWidgetStyle(2),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+16,_Context->y_Auto337+12,280,24,vfh[2],16,0,_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto338_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto339 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+16,_Context->y_Auto337+36,280,20,GetWidgetStyle(3),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto337+16,_Context->y_Auto337+36,280,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+16,_Context->y_Auto337+36,280,20,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+16,_Context->y_Auto337+36,280,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto339_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto340 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+16,_Context->y_Auto337+56,272,20,GetWidgetStyle(3),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto337+16,_Context->y_Auto337+56,272,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto337+16,_Context->y_Auto337+56,272,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto337+16,_Context->y_Auto337+56,272,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto340_event(_Context)) != -1) break;

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

public	int	database_link_menu()
{
	int	status=0;
	struct database_link_menu_context * _Context=(struct database_link_menu_context*) 0;
	status = database_link_menu_create(&_Context);
	if ( status != 0) return(status);
	status = database_link_menu_show(_Context);
		enter_modal();
	status = database_link_menu_focus(_Context);
		leave_modal();
	status = database_link_menu_hide(_Context);
	status = database_link_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _linkmenu_c */
