
#ifndef _actormenu_c
#define _actormenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : actormenu.xml                                            */
/* Target         : actormenu.c                                              */
/* Identification : 0.0-1197472041-4032.4031                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#include "singfmed.h"
#define en_Auto346   "Sing Version 2.1a"
#define fr_Auto346   "Sing Version 2.1a"
#define it_Auto346   "Sing Version 2.1a"
#define es_Auto346   "Sing Version 2.1a"
#define de_Auto346   "Sing Version 2.1a"
#define nl_Auto346   "Sing Version 2.1a"
#define pt_Auto346   "Sing Version 2.1a"
#define xx_Auto346   "Sing Version 2.1a"
#define en__Auto346   ""
#define fr__Auto346   ""
#define it__Auto346   ""
#define es__Auto346   ""
#define de__Auto346   ""
#define nl__Auto346   ""
#define pt__Auto346   ""
#define xx__Auto346   ""
#define en_Auto347   "&Inspect Form Properties"
#define fr_Auto347   "&PropriŠt‚s du formulaire"
#define it_Auto347   "&Inspect Form Properties"
#define es_Auto347   "&Inspect Form Properties"
#define de_Auto347   "&Inspect Form Properties"
#define nl_Auto347   "&Inspect Form Properties"
#define pt_Auto347   "&Inspect Form Properties"
#define xx_Auto347   "&Inspect Form Properties"
#define en__Auto347   ""
#define fr__Auto347   ""
#define it__Auto347   ""
#define es__Auto347   ""
#define de__Auto347   ""
#define nl__Auto347   ""
#define pt__Auto347   ""
#define xx__Auto347   ""
#define en_Auto348   "&Visual Forms Editor"
#define fr_Auto348   "&Editeur de formulaire"
#define it_Auto348   "&Visual Forms Editor"
#define es_Auto348   "&Visual Forms Editor"
#define de_Auto348   "&Visual Forms Editor"
#define nl_Auto348   "&Visual Forms Editor"
#define pt_Auto348   "&Visual Forms Editor"
#define xx_Auto348   "&Visual Forms Editor"
#define en__Auto348   ""
#define fr__Auto348   ""
#define it__Auto348   ""
#define es__Auto348   ""
#define de__Auto348   ""
#define nl__Auto348   ""
#define pt__Auto348   ""
#define xx__Auto348   ""
#define en_Auto349   "&Toggle Forms Detail"
#define fr_Auto349   "&Bascule l'affichage du D‚tail"
#define it_Auto349   "&Toggle Forms Detail"
#define es_Auto349   "&Toggle Forms Detail"
#define de_Auto349   "&Toggle Forms Detail"
#define nl_Auto349   "&Toggle Forms Detail"
#define pt_Auto349   "&Toggle Forms Detail"
#define xx_Auto349   "&Toggle Forms Detail"
#define en__Auto349   ""
#define fr__Auto349   ""
#define it__Auto349   ""
#define es__Auto349   ""
#define de__Auto349   ""
#define nl__Auto349   ""
#define pt__Auto349   ""
#define xx__Auto349   ""
#define en_Auto350   "T&oggle Flowchart Images"
#define fr_Auto350   "B&ascule l'affichage Image"
#define it_Auto350   "T&oggle Flowchart Images"
#define es_Auto350   "T&oggle Flowchart Images"
#define de_Auto350   "T&oggle Flowchart Images"
#define nl_Auto350   "T&oggle Flowchart Images"
#define pt_Auto350   "T&oggle Flowchart Images"
#define xx_Auto350   "T&oggle Flowchart Images"
#define en__Auto350   ""
#define fr__Auto350   ""
#define it__Auto350   ""
#define es__Auto350   ""
#define de__Auto350   ""
#define nl__Auto350   ""
#define pt__Auto350   ""
#define xx__Auto350   ""
#define en_Auto351   "To&ggle Forms Solo"
#define fr_Auto351   "Ba&scule de l'affichage Solo"
#define it_Auto351   "To&ggle Forms Detail"
#define es_Auto351   "To&ggle Forms Detail"
#define de_Auto351   "To&ggle Forms Detail"
#define nl_Auto351   "To&ggle Forms Detail"
#define pt_Auto351   "To&ggle Forms Detail"
#define xx_Auto351   "To&ggle Forms Detail"
#define en__Auto351   ""
#define fr__Auto351   ""
#define it__Auto351   ""
#define es__Auto351   ""
#define de__Auto351   ""
#define nl__Auto351   ""
#define pt__Auto351   ""
#define xx__Auto351   ""
#define en_Auto352   "&Calculate Best Positioning"
#define fr_Auto352   "&Recalculation positionnement a partir de formulaire"
#define it_Auto352   "&Calculate Best Positioning"
#define es_Auto352   "&Calculate Best Positioning"
#define de_Auto352   "&Calculate Best Positioning"
#define nl_Auto352   "&Calculate Best Positioning"
#define pt_Auto352   "&Calculate Best Positioning"
#define xx_Auto352   "&Calculate Best Positioning"
#define en__Auto352   ""
#define fr__Auto352   ""
#define it__Auto352   ""
#define es__Auto352   ""
#define de__Auto352   ""
#define nl__Auto352   ""
#define pt__Auto352   ""
#define xx__Auto352   ""

private struct flowchart_model_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto346[8];
	char * hint_Auto346[8];
	int	s_Auto346;
	void *	p_Auto346;
	int	x_Auto346;
	int	y_Auto346;
	int	w_Auto346;
	int	h_Auto346;
	char * msg_Auto347[8];
	int	trigger_Auto347;
	char * hint_Auto347[8];
	char * msg_Auto348[8];
	int	trigger_Auto348;
	char * hint_Auto348[8];
	char * msg_Auto349[8];
	int	trigger_Auto349;
	char * hint_Auto349[8];
	char * msg_Auto350[8];
	int	trigger_Auto350;
	char * hint_Auto350[8];
	char * msg_Auto351[8];
	int	trigger_Auto351;
	char * hint_Auto351[8];
	char * msg_Auto352[8];
	int	trigger_Auto352;
	char * hint_Auto352[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct flowchart_model_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = flowchart_model_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}

private int on_Auto346_create(struct flowchart_model_menu_context * _Context) {
	mouse_move_on();
	if(((_Context->y_Auto346=visual_event(6))+160)>hardrows())
	_Context->y_Auto346=(hardrows()-160);
	if(((_Context->x_Auto346=visual_event(7))+336)>hardcolumns())
	_Context->x_Auto346=(hardcolumns()-336);
	return(-1);
}

public	int	flowchart_model_menu_create(struct flowchart_model_menu_context **cptr)
{

	int i;
	struct flowchart_model_menu_context * _Context=(struct flowchart_model_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct flowchart_model_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=6;
	for (i=0; i < 8; i++)_Context->msg_Auto346[i]=" ";
	_Context->msg_Auto346[0]=en_Auto346;
	_Context->msg_Auto346[1]=fr_Auto346;
	_Context->msg_Auto346[2]=it_Auto346;
	_Context->msg_Auto346[3]=es_Auto346;
	_Context->msg_Auto346[4]=de_Auto346;
	_Context->msg_Auto346[5]=nl_Auto346;
	_Context->msg_Auto346[6]=pt_Auto346;
	_Context->msg_Auto346[7]=xx_Auto346;
	_Context->hint_Auto346[0]=en__Auto346;
	_Context->hint_Auto346[1]=fr__Auto346;
	_Context->hint_Auto346[2]=it__Auto346;
	_Context->hint_Auto346[3]=es__Auto346;
	_Context->hint_Auto346[4]=de__Auto346;
	_Context->hint_Auto346[5]=nl__Auto346;
	_Context->hint_Auto346[6]=pt__Auto346;
	_Context->hint_Auto346[7]=xx__Auto346;
	_Context->s_Auto346=0;
	_Context->p_Auto346=visual_buffer(_Context->x_Auto346,_Context->y_Auto346,336+2,160+2);
	_Context->x_Auto346=40;
	_Context->y_Auto346=44;
	_Context->w_Auto346=336;
	_Context->h_Auto346=160;
	_Context->window_col=40;
	_Context->window_row=44;
	(void) on_Auto346_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Auto347[i]=" ";
	_Context->msg_Auto347[0]=en_Auto347;
	_Context->msg_Auto347[1]=fr_Auto347;
	_Context->msg_Auto347[2]=it_Auto347;
	_Context->msg_Auto347[3]=es_Auto347;
	_Context->msg_Auto347[4]=de_Auto347;
	_Context->msg_Auto347[5]=nl_Auto347;
	_Context->msg_Auto347[6]=pt_Auto347;
	_Context->msg_Auto347[7]=xx_Auto347;
	_Context->hint_Auto347[0]=en__Auto347;
	_Context->hint_Auto347[1]=fr__Auto347;
	_Context->hint_Auto347[2]=it__Auto347;
	_Context->hint_Auto347[3]=es__Auto347;
	_Context->hint_Auto347[4]=de__Auto347;
	_Context->hint_Auto347[5]=nl__Auto347;
	_Context->hint_Auto347[6]=pt__Auto347;
	_Context->hint_Auto347[7]=xx__Auto347;
	for (i=0; i < 8; i++)_Context->msg_Auto348[i]=" ";
	_Context->msg_Auto348[0]=en_Auto348;
	_Context->msg_Auto348[1]=fr_Auto348;
	_Context->msg_Auto348[2]=it_Auto348;
	_Context->msg_Auto348[3]=es_Auto348;
	_Context->msg_Auto348[4]=de_Auto348;
	_Context->msg_Auto348[5]=nl_Auto348;
	_Context->msg_Auto348[6]=pt_Auto348;
	_Context->msg_Auto348[7]=xx_Auto348;
	_Context->hint_Auto348[0]=en__Auto348;
	_Context->hint_Auto348[1]=fr__Auto348;
	_Context->hint_Auto348[2]=it__Auto348;
	_Context->hint_Auto348[3]=es__Auto348;
	_Context->hint_Auto348[4]=de__Auto348;
	_Context->hint_Auto348[5]=nl__Auto348;
	_Context->hint_Auto348[6]=pt__Auto348;
	_Context->hint_Auto348[7]=xx__Auto348;
	for (i=0; i < 8; i++)_Context->msg_Auto349[i]=" ";
	_Context->msg_Auto349[0]=en_Auto349;
	_Context->msg_Auto349[1]=fr_Auto349;
	_Context->msg_Auto349[2]=it_Auto349;
	_Context->msg_Auto349[3]=es_Auto349;
	_Context->msg_Auto349[4]=de_Auto349;
	_Context->msg_Auto349[5]=nl_Auto349;
	_Context->msg_Auto349[6]=pt_Auto349;
	_Context->msg_Auto349[7]=xx_Auto349;
	_Context->hint_Auto349[0]=en__Auto349;
	_Context->hint_Auto349[1]=fr__Auto349;
	_Context->hint_Auto349[2]=it__Auto349;
	_Context->hint_Auto349[3]=es__Auto349;
	_Context->hint_Auto349[4]=de__Auto349;
	_Context->hint_Auto349[5]=nl__Auto349;
	_Context->hint_Auto349[6]=pt__Auto349;
	_Context->hint_Auto349[7]=xx__Auto349;
	for (i=0; i < 8; i++)_Context->msg_Auto350[i]=" ";
	_Context->msg_Auto350[0]=en_Auto350;
	_Context->msg_Auto350[1]=fr_Auto350;
	_Context->msg_Auto350[2]=it_Auto350;
	_Context->msg_Auto350[3]=es_Auto350;
	_Context->msg_Auto350[4]=de_Auto350;
	_Context->msg_Auto350[5]=nl_Auto350;
	_Context->msg_Auto350[6]=pt_Auto350;
	_Context->msg_Auto350[7]=xx_Auto350;
	_Context->hint_Auto350[0]=en__Auto350;
	_Context->hint_Auto350[1]=fr__Auto350;
	_Context->hint_Auto350[2]=it__Auto350;
	_Context->hint_Auto350[3]=es__Auto350;
	_Context->hint_Auto350[4]=de__Auto350;
	_Context->hint_Auto350[5]=nl__Auto350;
	_Context->hint_Auto350[6]=pt__Auto350;
	_Context->hint_Auto350[7]=xx__Auto350;
	for (i=0; i < 8; i++)_Context->msg_Auto351[i]=" ";
	_Context->msg_Auto351[0]=en_Auto351;
	_Context->msg_Auto351[1]=fr_Auto351;
	_Context->msg_Auto351[2]=it_Auto351;
	_Context->msg_Auto351[3]=es_Auto351;
	_Context->msg_Auto351[4]=de_Auto351;
	_Context->msg_Auto351[5]=nl_Auto351;
	_Context->msg_Auto351[6]=pt_Auto351;
	_Context->msg_Auto351[7]=xx_Auto351;
	_Context->hint_Auto351[0]=en__Auto351;
	_Context->hint_Auto351[1]=fr__Auto351;
	_Context->hint_Auto351[2]=it__Auto351;
	_Context->hint_Auto351[3]=es__Auto351;
	_Context->hint_Auto351[4]=de__Auto351;
	_Context->hint_Auto351[5]=nl__Auto351;
	_Context->hint_Auto351[6]=pt__Auto351;
	_Context->hint_Auto351[7]=xx__Auto351;
	for (i=0; i < 8; i++)_Context->msg_Auto352[i]=" ";
	_Context->msg_Auto352[0]=en_Auto352;
	_Context->msg_Auto352[1]=fr_Auto352;
	_Context->msg_Auto352[2]=it_Auto352;
	_Context->msg_Auto352[3]=es_Auto352;
	_Context->msg_Auto352[4]=de_Auto352;
	_Context->msg_Auto352[5]=nl_Auto352;
	_Context->msg_Auto352[6]=pt_Auto352;
	_Context->msg_Auto352[7]=xx_Auto352;
	_Context->hint_Auto352[0]=en__Auto352;
	_Context->hint_Auto352[1]=fr__Auto352;
	_Context->hint_Auto352[2]=it__Auto352;
	_Context->hint_Auto352[3]=es__Auto352;
	_Context->hint_Auto352[4]=de__Auto352;
	_Context->hint_Auto352[5]=nl__Auto352;
	_Context->hint_Auto352[6]=pt__Auto352;
	_Context->hint_Auto352[7]=xx__Auto352;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto346,_Context->y_Auto346,336,160);
	return(0);
}

public 	int	flowchart_model_menu_hide(struct flowchart_model_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto346 != (void *) 0)
	&& (_Context->s_Auto346 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto346,_Context->x_Auto346,_Context->y_Auto346);
		_Context->s_Auto346=0;
		}
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto346,_Context->y_Auto346);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	flowchart_model_menu_remove(struct flowchart_model_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	mouse_move_off();
	if (_Context->p_Auto346 != (void *) 0)
		_Context->p_Auto346 = visual_drop(_Context->p_Auto346);
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	flowchart_model_menu_show(struct flowchart_model_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto346,_Context->y_Auto346);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if ((_Context->p_Auto346 != (void *) 0)
	&& (_Context->s_Auto346 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto346,_Context->x_Auto346,_Context->y_Auto346);
		_Context->s_Auto346=1;
		}
	if (((_Context->status = visual_styled_element(_Context->x_Auto346,_Context->y_Auto346,336,160,GetWidgetStyle(1),_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]))) != 0)
) {
		visual_window(_Context->x_Auto346,_Context->y_Auto346,336,160,vfh[1],_Context->msg_Auto346[_Context->language],strlen(_Context->msg_Auto346[_Context->language]),0x4);
		}
	_Context->trigger_Auto347=visual_trigger_code(_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+12,312,20,GetWidgetStyle(2),_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto346+16,_Context->y_Auto346+12,312,20,vfh[2],16,0,_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]),32);
		}
	_Context->trigger_Auto348=visual_trigger_code(_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+36,312,20,GetWidgetStyle(2),_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto346+16,_Context->y_Auto346+36,312,20,vfh[2],16,0,_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]),32);
		}
	_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+60,312,20,GetWidgetStyle(2),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto346+16,_Context->y_Auto346+60,312,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),32);
		}
	_Context->trigger_Auto350=visual_trigger_code(_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+84,296,20,GetWidgetStyle(2),_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto346+16,_Context->y_Auto346+84,296,20,vfh[2],16,0,_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]),32);
		}
	_Context->trigger_Auto351=visual_trigger_code(_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+108,312,20,GetWidgetStyle(2),_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto346+16,_Context->y_Auto346+108,312,20,vfh[2],16,0,_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]),32);
		}
	_Context->trigger_Auto352=visual_trigger_code(_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+132,312,20,GetWidgetStyle(2),_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto346+16,_Context->y_Auto346+132,312,20,vfh[2],16,0,_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]),32);
		}
	visual_thaw(_Context->x_Auto346,_Context->y_Auto346,336,160);

	return(0);
}
private int on_Auto347_event(struct flowchart_model_menu_context * _Context) {
	return(_FORM_PARA);
	return(-1);
}
private int on_Auto348_event(struct flowchart_model_menu_context * _Context) {
	return(_EDIT_FORM);
	return(-1);
}
private int on_Auto349_event(struct flowchart_model_menu_context * _Context) {
	return(_FLOW_DETAIL);
	return(-1);
}
private int on_Auto350_event(struct flowchart_model_menu_context * _Context) {
	return(_FLOW_SIGHT);
	return(-1);
}
private int on_Auto351_event(struct flowchart_model_menu_context * _Context) {
	return(_FLOW_SOLO);
	return(-1);
}
private int on_Auto352_event(struct flowchart_model_menu_context * _Context) {
	return(_FLOW_BEST);
	return(-1);
}


public	int	flowchart_model_menu_event(
struct flowchart_model_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto347 == mb ) return(1);
		if (_Context->trigger_Auto348 == mb ) return(2);
		if (_Context->trigger_Auto349 == mb ) return(3);
		if (_Context->trigger_Auto350 == mb ) return(4);
		if (_Context->trigger_Auto351 == mb ) return(5);
		if (_Context->trigger_Auto352 == mb ) return(6);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_Auto346+16) ) 
	&&  ( my >= (_Context->y_Auto346+12) ) 
	&&  ( mx <= (_Context->x_Auto346+16+312) ) 
	&&  ( my <= (_Context->y_Auto346+12+20))) {
		return(1); /* Auto347 */
		}
	if (( mx >= (_Context->x_Auto346+16) ) 
	&&  ( my >= (_Context->y_Auto346+36) ) 
	&&  ( mx <= (_Context->x_Auto346+16+312) ) 
	&&  ( my <= (_Context->y_Auto346+36+20))) {
		return(2); /* Auto348 */
		}
	if (( mx >= (_Context->x_Auto346+16) ) 
	&&  ( my >= (_Context->y_Auto346+60) ) 
	&&  ( mx <= (_Context->x_Auto346+16+312) ) 
	&&  ( my <= (_Context->y_Auto346+60+20))) {
		return(3); /* Auto349 */
		}
	if (( mx >= (_Context->x_Auto346+16) ) 
	&&  ( my >= (_Context->y_Auto346+84) ) 
	&&  ( mx <= (_Context->x_Auto346+16+296) ) 
	&&  ( my <= (_Context->y_Auto346+84+20))) {
		return(4); /* Auto350 */
		}
	if (( mx >= (_Context->x_Auto346+16) ) 
	&&  ( my >= (_Context->y_Auto346+108) ) 
	&&  ( mx <= (_Context->x_Auto346+16+312) ) 
	&&  ( my <= (_Context->y_Auto346+108+20))) {
		return(5); /* Auto351 */
		}
	if (( mx >= (_Context->x_Auto346+16) ) 
	&&  ( my >= (_Context->y_Auto346+132) ) 
	&&  ( mx <= (_Context->x_Auto346+16+312) ) 
	&&  ( my <= (_Context->y_Auto346+132+20))) {
		return(6); /* Auto352 */
		}

	return(-1);
}


public	int	flowchart_model_menu_focus(struct flowchart_model_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto347 */
				_Context->trigger_Auto347=visual_trigger_code(_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+12,312,20,GetWidgetStyle(3),_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto346+16,_Context->y_Auto346+12,312,20,vfh[2],16,0,_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto347=visual_trigger_code(_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+12,312,20,GetWidgetStyle(2),_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto346+16,_Context->y_Auto346+12,312,20,vfh[2],16,0,_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto348 */
				_Context->trigger_Auto348=visual_trigger_code(_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+36,312,20,GetWidgetStyle(3),_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto346+16,_Context->y_Auto346+36,312,20,vfh[2],16,0,_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto348=visual_trigger_code(_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+36,312,20,GetWidgetStyle(2),_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto346+16,_Context->y_Auto346+36,312,20,vfh[2],16,0,_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto349 */
				_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+60,312,20,GetWidgetStyle(3),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto346+16,_Context->y_Auto346+60,312,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+60,312,20,GetWidgetStyle(2),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto346+16,_Context->y_Auto346+60,312,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto350 */
				_Context->trigger_Auto350=visual_trigger_code(_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+84,296,20,GetWidgetStyle(3),_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto346+16,_Context->y_Auto346+84,296,20,vfh[2],16,0,_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto350=visual_trigger_code(_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+84,296,20,GetWidgetStyle(2),_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto346+16,_Context->y_Auto346+84,296,20,vfh[2],16,0,_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto351 */
				_Context->trigger_Auto351=visual_trigger_code(_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+108,312,20,GetWidgetStyle(3),_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto346+16,_Context->y_Auto346+108,312,20,vfh[2],16,0,_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto351=visual_trigger_code(_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+108,312,20,GetWidgetStyle(2),_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto346+16,_Context->y_Auto346+108,312,20,vfh[2],16,0,_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]),32);
				}
				break;
			case	0x6 :
				/* Auto352 */
				_Context->trigger_Auto352=visual_trigger_code(_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+132,312,20,GetWidgetStyle(3),_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto346+16,_Context->y_Auto346+132,312,20,vfh[2],16,0,_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto352=visual_trigger_code(_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+132,312,20,GetWidgetStyle(2),_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto346+16,_Context->y_Auto346+132,312,20,vfh[2],16,0,_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			flowchart_model_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=6;
			flowchart_model_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  _Context->x_Auto346 )
				|| ( visual_event(6) < _Context->y_Auto346  )
				|| ( visual_event(7) > (_Context->x_Auto346+_Context->w_Auto346))
				|| ( visual_event(6) >  (_Context->y_Auto346+_Context->h_Auto346))) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=flowchart_model_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto347 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto347=visual_trigger_code(_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+12,312,20,GetWidgetStyle(3),_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto346+16,_Context->y_Auto346+12,312,20,vfh[2],16,0,_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto347=visual_trigger_code(_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+12,312,20,GetWidgetStyle(2),_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto346+16,_Context->y_Auto346+12,312,20,vfh[2],16,0,_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto347_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto348 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto348=visual_trigger_code(_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+36,312,20,GetWidgetStyle(3),_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto346+16,_Context->y_Auto346+36,312,20,vfh[2],16,0,_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto348=visual_trigger_code(_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+36,312,20,GetWidgetStyle(2),_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto346+16,_Context->y_Auto346+36,312,20,vfh[2],16,0,_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto348_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto349 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+60,312,20,GetWidgetStyle(3),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto346+16,_Context->y_Auto346+60,312,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+60,312,20,GetWidgetStyle(2),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto346+16,_Context->y_Auto346+60,312,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto349_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto350 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto350=visual_trigger_code(_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+84,296,20,GetWidgetStyle(3),_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto346+16,_Context->y_Auto346+84,296,20,vfh[2],16,0,_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto350=visual_trigger_code(_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+84,296,20,GetWidgetStyle(2),_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto346+16,_Context->y_Auto346+84,296,20,vfh[2],16,0,_Context->msg_Auto350[_Context->language],strlen(_Context->msg_Auto350[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto350_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto351 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto351=visual_trigger_code(_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+108,312,20,GetWidgetStyle(3),_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto346+16,_Context->y_Auto346+108,312,20,vfh[2],16,0,_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto351=visual_trigger_code(_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+108,312,20,GetWidgetStyle(2),_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto346+16,_Context->y_Auto346+108,312,20,vfh[2],16,0,_Context->msg_Auto351[_Context->language],strlen(_Context->msg_Auto351[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto351_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto352 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto352=visual_trigger_code(_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+132,312,20,GetWidgetStyle(3),_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto346+16,_Context->y_Auto346+132,312,20,vfh[2],16,0,_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto352=visual_trigger_code(_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto346+16,_Context->y_Auto346+132,312,20,GetWidgetStyle(2),_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto346+16,_Context->y_Auto346+132,312,20,vfh[2],16,0,_Context->msg_Auto352[_Context->language],strlen(_Context->msg_Auto352[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto352_event(_Context)) != -1) break;

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
				_Context->focus_item=6;
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

public	int	flowchart_model_menu()
{
	int	status=0;
	struct flowchart_model_menu_context * _Context=(struct flowchart_model_menu_context*) 0;
	status = flowchart_model_menu_create(&_Context);
	if ( status != 0) return(status);
	status = flowchart_model_menu_show(_Context);
		enter_modal();
	status = flowchart_model_menu_focus(_Context);
		leave_modal();
	status = flowchart_model_menu_hide(_Context);
	status = flowchart_model_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _actormenu_c */
