
#ifndef _filemenu_c
#define _filemenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.27                                                */
/* Production     : C                                                        */
/* Project        : filemenu.xml                                             */
/* Target         : filemenu.c                                               */
/* Identification : 0.0-1179578439-3988.3987                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#define en_Auto426   "Sing Version 2.1a"
#define fr_Auto426   "Sing Version 2.1a"
#define it_Auto426   "Sing Version 2.1a"
#define es_Auto426   "Sing Version 2.1a"
#define de_Auto426   "Sing Version 2.1a"
#define nl_Auto426   "Sing Version 2.1a"
#define pt_Auto426   "Sing Version 2.1a"
#define xx_Auto426   "Sing Version 2.1a"
#define en__Auto426   ""
#define fr__Auto426   ""
#define it__Auto426   ""
#define es__Auto426   ""
#define de__Auto426   ""
#define nl__Auto426   ""
#define pt__Auto426   ""
#define xx__Auto426   ""
#define en_Auto427   ""
#define en__Auto427   ""
#define en_Auto428   "&New"
#define fr_Auto428   "&Nouveau"
#define it_Auto428   "&Nuvo"
#define es_Auto428   "&New"
#define de_Auto428   "&Neu"
#define nl_Auto428   "&Neu"
#define pt_Auto428   "&New"
#define xx_Auto428   "&New"
#define en__Auto428   ""
#define fr__Auto428   ""
#define it__Auto428   ""
#define es__Auto428   ""
#define de__Auto428   ""
#define nl__Auto428   ""
#define pt__Auto428   ""
#define xx__Auto428   ""
#define en_Auto429   "&Save"
#define fr_Auto429   "&Sauvegarder"
#define it_Auto429   "&Save"
#define es_Auto429   "&Save"
#define de_Auto429   "&Save"
#define nl_Auto429   "&Save"
#define pt_Auto429   "&Save"
#define xx_Auto429   "&Save"
#define en__Auto429   ""
#define fr__Auto429   ""
#define it__Auto429   ""
#define es__Auto429   ""
#define de__Auto429   ""
#define nl__Auto429   ""
#define pt__Auto429   ""
#define xx__Auto429   ""
#define en_Auto430   "S&ave As..."
#define fr_Auto430   "S&auvegarder sous..."
#define it_Auto430   "S&ave As..."
#define es_Auto430   "S&ave As..."
#define de_Auto430   "S&ave As..."
#define nl_Auto430   "S&ave As..."
#define pt_Auto430   "S&ave As..."
#define xx_Auto430   "S&ave As..."
#define en__Auto430   ""
#define fr__Auto430   ""
#define it__Auto430   ""
#define es__Auto430   ""
#define de__Auto430   ""
#define nl__Auto430   ""
#define pt__Auto430   ""
#define xx__Auto430   ""
#define en_Auto431   "&Open..."
#define fr_Auto431   "&Ouvrir..."
#define it_Auto431   "&Apri..."
#define es_Auto431   "&Open..."
#define de_Auto431   "&Ofnen..."
#define nl_Auto431   "&Ofnen..."
#define pt_Auto431   "&Open..."
#define xx_Auto431   "&Open..."
#define en__Auto431   ""
#define fr__Auto431   ""
#define it__Auto431   ""
#define es__Auto431   ""
#define de__Auto431   ""
#define nl__Auto431   ""
#define pt__Auto431   ""
#define xx__Auto431   ""
#define en_Auto432   "&Production..."
#define fr_Auto432   "&Production..."
#define it_Auto432   "&Production..."
#define es_Auto432   "&Production..."
#define de_Auto432   "&Production..."
#define nl_Auto432   "&Production..."
#define pt_Auto432   "&Production..."
#define xx_Auto432   "&Production..."
#define en__Auto432   ""
#define fr__Auto432   ""
#define it__Auto432   ""
#define es__Auto432   ""
#define de__Auto432   ""
#define nl__Auto432   ""
#define pt__Auto432   ""
#define xx__Auto432   ""
#define en_Auto433   "&Compare..."
#define fr_Auto433   "&Comparer..."
#define it_Auto433   "&Compare..."
#define es_Auto433   "&Compare..."
#define de_Auto433   "&Compare..."
#define nl_Auto433   "&Compare..."
#define pt_Auto433   "&Compare..."
#define xx_Auto433   "&Compare..."
#define en__Auto433   ""
#define fr__Auto433   ""
#define it__Auto433   ""
#define es__Auto433   ""
#define de__Auto433   ""
#define nl__Auto433   ""
#define pt__Auto433   ""
#define xx__Auto433   ""
#define en_Auto434   "&Close"
#define fr_Auto434   "&Fermer"
#define it_Auto434   "&Fermare"
#define es_Auto434   "&Close"
#define de_Auto434   "&Zumachen"
#define nl_Auto434   "&Zumachen"
#define pt_Auto434   "&Close"
#define xx_Auto434   "&Close"
#define en__Auto434   ""
#define fr__Auto434   ""
#define it__Auto434   ""
#define es__Auto434   ""
#define de__Auto434   ""
#define nl__Auto434   ""
#define pt__Auto434   ""
#define xx__Auto434   ""
#define en_Auto435   "A&bout..."
#define fr_Auto435   "A pro&pos..."
#define it_Auto435   "A&bout..."
#define es_Auto435   "A&bout..."
#define de_Auto435   "A&bout..."
#define nl_Auto435   "A&bout..."
#define pt_Auto435   "A&bout..."
#define xx_Auto435   "A&bout..."
#define en__Auto435   ""
#define fr__Auto435   ""
#define it__Auto435   ""
#define es__Auto435   ""
#define de__Auto435   ""
#define nl__Auto435   ""
#define pt__Auto435   ""
#define xx__Auto435   ""
#define en_Auto436   "&Quit"
#define fr_Auto436   "&Quitter"
#define it_Auto436   "&Uscita"
#define es_Auto436   "&Quit"
#define de_Auto436   "&Ausgang"
#define nl_Auto436   "&Uitgang"
#define pt_Auto436   "&Quit"
#define xx_Auto436   "&Quit"
#define en__Auto436   ""
#define fr__Auto436   ""
#define it__Auto436   ""
#define es__Auto436   ""
#define de__Auto436   ""
#define nl__Auto436   ""
#define pt__Auto436   ""
#define xx__Auto436   ""

private struct standard_file_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto426[8];
	char * hint_Auto426[8];
	int	x_Auto426;
	int	y_Auto426;
	int	w_Auto426;
	int	h_Auto426;
	int	fg_Auto426;
	int	bg_Auto426;
	int	fid_Auto426;
	int	s_Auto426;
	void *	p_Auto426;
	char * hint_Auto427[8];
	int	s_Auto427;
	void *	p_Auto427;
	char * msg_Auto428[8];
	int	trigger_Auto428;
	char * hint_Auto428[8];
	char * msg_Auto429[8];
	int	trigger_Auto429;
	char * hint_Auto429[8];
	char * msg_Auto430[8];
	int	trigger_Auto430;
	char * hint_Auto430[8];
	char * msg_Auto431[8];
	int	trigger_Auto431;
	char * hint_Auto431[8];
	char * msg_Auto432[8];
	int	trigger_Auto432;
	char * hint_Auto432[8];
	char * msg_Auto433[8];
	int	trigger_Auto433;
	char * hint_Auto433[8];
	char * msg_Auto434[8];
	int	trigger_Auto434;
	char * hint_Auto434[8];
	char * msg_Auto435[8];
	int	trigger_Auto435;
	char * hint_Auto435[8];
	char * msg_Auto436[8];
	int	trigger_Auto436;
	char * hint_Auto436[8];
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct standard_file_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = standard_file_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}

private int on_Auto426_create(struct standard_file_menu_context * _Context) {
	mouse_move_on();
	_Context->y_Auto426=(get_menubar_height()+2);
	return(-1);
}

public	int	standard_file_menu_create(struct standard_file_menu_context **cptr)
{

	int i;
	struct standard_file_menu_context * _Context=(struct standard_file_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct standard_file_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=9;
	for (i=0; i < 8; i++)_Context->msg_Auto426[i]=" ";
	_Context->msg_Auto426[0]=en_Auto426;
	_Context->msg_Auto426[1]=fr_Auto426;
	_Context->msg_Auto426[2]=it_Auto426;
	_Context->msg_Auto426[3]=es_Auto426;
	_Context->msg_Auto426[4]=de_Auto426;
	_Context->msg_Auto426[5]=nl_Auto426;
	_Context->msg_Auto426[6]=pt_Auto426;
	_Context->msg_Auto426[7]=xx_Auto426;
	_Context->hint_Auto426[0]=en__Auto426;
	_Context->hint_Auto426[1]=fr__Auto426;
	_Context->hint_Auto426[2]=it__Auto426;
	_Context->hint_Auto426[3]=es__Auto426;
	_Context->hint_Auto426[4]=de__Auto426;
	_Context->hint_Auto426[5]=nl__Auto426;
	_Context->hint_Auto426[6]=pt__Auto426;
	_Context->hint_Auto426[7]=xx__Auto426;
	_Context->x_Auto426=56;
	_Context->y_Auto426=32;
	_Context->w_Auto426=168;
	_Context->h_Auto426=204;
	_Context->fg_Auto426=204;
	_Context->bg_Auto426=204;
	_Context->fid_Auto426=1;
	_Context->s_Auto426=0;
	_Context->p_Auto426=visual_buffer(_Context->x_Auto426,_Context->y_Auto426,_Context->w_Auto426+2,_Context->h_Auto426+2);
	_Context->window_col=56;
	_Context->window_row=32;
	(void) on_Auto426_create(_Context);
	_Context->hint_Auto427[0]=en__Auto427;
	_Context->s_Auto427=0;
	_Context->p_Auto427=visual_buffer(56,32,168+2,204+2);
	for (i=0; i < 8; i++)_Context->msg_Auto428[i]=" ";
	_Context->msg_Auto428[0]=en_Auto428;
	_Context->msg_Auto428[1]=fr_Auto428;
	_Context->msg_Auto428[2]=it_Auto428;
	_Context->msg_Auto428[3]=es_Auto428;
	_Context->msg_Auto428[4]=de_Auto428;
	_Context->msg_Auto428[5]=nl_Auto428;
	_Context->msg_Auto428[6]=pt_Auto428;
	_Context->msg_Auto428[7]=xx_Auto428;
	_Context->hint_Auto428[0]=en__Auto428;
	_Context->hint_Auto428[1]=fr__Auto428;
	_Context->hint_Auto428[2]=it__Auto428;
	_Context->hint_Auto428[3]=es__Auto428;
	_Context->hint_Auto428[4]=de__Auto428;
	_Context->hint_Auto428[5]=nl__Auto428;
	_Context->hint_Auto428[6]=pt__Auto428;
	_Context->hint_Auto428[7]=xx__Auto428;
	for (i=0; i < 8; i++)_Context->msg_Auto429[i]=" ";
	_Context->msg_Auto429[0]=en_Auto429;
	_Context->msg_Auto429[1]=fr_Auto429;
	_Context->msg_Auto429[2]=it_Auto429;
	_Context->msg_Auto429[3]=es_Auto429;
	_Context->msg_Auto429[4]=de_Auto429;
	_Context->msg_Auto429[5]=nl_Auto429;
	_Context->msg_Auto429[6]=pt_Auto429;
	_Context->msg_Auto429[7]=xx_Auto429;
	_Context->hint_Auto429[0]=en__Auto429;
	_Context->hint_Auto429[1]=fr__Auto429;
	_Context->hint_Auto429[2]=it__Auto429;
	_Context->hint_Auto429[3]=es__Auto429;
	_Context->hint_Auto429[4]=de__Auto429;
	_Context->hint_Auto429[5]=nl__Auto429;
	_Context->hint_Auto429[6]=pt__Auto429;
	_Context->hint_Auto429[7]=xx__Auto429;
	for (i=0; i < 8; i++)_Context->msg_Auto430[i]=" ";
	_Context->msg_Auto430[0]=en_Auto430;
	_Context->msg_Auto430[1]=fr_Auto430;
	_Context->msg_Auto430[2]=it_Auto430;
	_Context->msg_Auto430[3]=es_Auto430;
	_Context->msg_Auto430[4]=de_Auto430;
	_Context->msg_Auto430[5]=nl_Auto430;
	_Context->msg_Auto430[6]=pt_Auto430;
	_Context->msg_Auto430[7]=xx_Auto430;
	_Context->hint_Auto430[0]=en__Auto430;
	_Context->hint_Auto430[1]=fr__Auto430;
	_Context->hint_Auto430[2]=it__Auto430;
	_Context->hint_Auto430[3]=es__Auto430;
	_Context->hint_Auto430[4]=de__Auto430;
	_Context->hint_Auto430[5]=nl__Auto430;
	_Context->hint_Auto430[6]=pt__Auto430;
	_Context->hint_Auto430[7]=xx__Auto430;
	for (i=0; i < 8; i++)_Context->msg_Auto431[i]=" ";
	_Context->msg_Auto431[0]=en_Auto431;
	_Context->msg_Auto431[1]=fr_Auto431;
	_Context->msg_Auto431[2]=it_Auto431;
	_Context->msg_Auto431[3]=es_Auto431;
	_Context->msg_Auto431[4]=de_Auto431;
	_Context->msg_Auto431[5]=nl_Auto431;
	_Context->msg_Auto431[6]=pt_Auto431;
	_Context->msg_Auto431[7]=xx_Auto431;
	_Context->hint_Auto431[0]=en__Auto431;
	_Context->hint_Auto431[1]=fr__Auto431;
	_Context->hint_Auto431[2]=it__Auto431;
	_Context->hint_Auto431[3]=es__Auto431;
	_Context->hint_Auto431[4]=de__Auto431;
	_Context->hint_Auto431[5]=nl__Auto431;
	_Context->hint_Auto431[6]=pt__Auto431;
	_Context->hint_Auto431[7]=xx__Auto431;
	for (i=0; i < 8; i++)_Context->msg_Auto432[i]=" ";
	_Context->msg_Auto432[0]=en_Auto432;
	_Context->msg_Auto432[1]=fr_Auto432;
	_Context->msg_Auto432[2]=it_Auto432;
	_Context->msg_Auto432[3]=es_Auto432;
	_Context->msg_Auto432[4]=de_Auto432;
	_Context->msg_Auto432[5]=nl_Auto432;
	_Context->msg_Auto432[6]=pt_Auto432;
	_Context->msg_Auto432[7]=xx_Auto432;
	_Context->hint_Auto432[0]=en__Auto432;
	_Context->hint_Auto432[1]=fr__Auto432;
	_Context->hint_Auto432[2]=it__Auto432;
	_Context->hint_Auto432[3]=es__Auto432;
	_Context->hint_Auto432[4]=de__Auto432;
	_Context->hint_Auto432[5]=nl__Auto432;
	_Context->hint_Auto432[6]=pt__Auto432;
	_Context->hint_Auto432[7]=xx__Auto432;
	for (i=0; i < 8; i++)_Context->msg_Auto433[i]=" ";
	_Context->msg_Auto433[0]=en_Auto433;
	_Context->msg_Auto433[1]=fr_Auto433;
	_Context->msg_Auto433[2]=it_Auto433;
	_Context->msg_Auto433[3]=es_Auto433;
	_Context->msg_Auto433[4]=de_Auto433;
	_Context->msg_Auto433[5]=nl_Auto433;
	_Context->msg_Auto433[6]=pt_Auto433;
	_Context->msg_Auto433[7]=xx_Auto433;
	_Context->hint_Auto433[0]=en__Auto433;
	_Context->hint_Auto433[1]=fr__Auto433;
	_Context->hint_Auto433[2]=it__Auto433;
	_Context->hint_Auto433[3]=es__Auto433;
	_Context->hint_Auto433[4]=de__Auto433;
	_Context->hint_Auto433[5]=nl__Auto433;
	_Context->hint_Auto433[6]=pt__Auto433;
	_Context->hint_Auto433[7]=xx__Auto433;
	for (i=0; i < 8; i++)_Context->msg_Auto434[i]=" ";
	_Context->msg_Auto434[0]=en_Auto434;
	_Context->msg_Auto434[1]=fr_Auto434;
	_Context->msg_Auto434[2]=it_Auto434;
	_Context->msg_Auto434[3]=es_Auto434;
	_Context->msg_Auto434[4]=de_Auto434;
	_Context->msg_Auto434[5]=nl_Auto434;
	_Context->msg_Auto434[6]=pt_Auto434;
	_Context->msg_Auto434[7]=xx_Auto434;
	_Context->hint_Auto434[0]=en__Auto434;
	_Context->hint_Auto434[1]=fr__Auto434;
	_Context->hint_Auto434[2]=it__Auto434;
	_Context->hint_Auto434[3]=es__Auto434;
	_Context->hint_Auto434[4]=de__Auto434;
	_Context->hint_Auto434[5]=nl__Auto434;
	_Context->hint_Auto434[6]=pt__Auto434;
	_Context->hint_Auto434[7]=xx__Auto434;
	for (i=0; i < 8; i++)_Context->msg_Auto435[i]=" ";
	_Context->msg_Auto435[0]=en_Auto435;
	_Context->msg_Auto435[1]=fr_Auto435;
	_Context->msg_Auto435[2]=it_Auto435;
	_Context->msg_Auto435[3]=es_Auto435;
	_Context->msg_Auto435[4]=de_Auto435;
	_Context->msg_Auto435[5]=nl_Auto435;
	_Context->msg_Auto435[6]=pt_Auto435;
	_Context->msg_Auto435[7]=xx_Auto435;
	_Context->hint_Auto435[0]=en__Auto435;
	_Context->hint_Auto435[1]=fr__Auto435;
	_Context->hint_Auto435[2]=it__Auto435;
	_Context->hint_Auto435[3]=es__Auto435;
	_Context->hint_Auto435[4]=de__Auto435;
	_Context->hint_Auto435[5]=nl__Auto435;
	_Context->hint_Auto435[6]=pt__Auto435;
	_Context->hint_Auto435[7]=xx__Auto435;
	for (i=0; i < 8; i++)_Context->msg_Auto436[i]=" ";
	_Context->msg_Auto436[0]=en_Auto436;
	_Context->msg_Auto436[1]=fr_Auto436;
	_Context->msg_Auto436[2]=it_Auto436;
	_Context->msg_Auto436[3]=es_Auto436;
	_Context->msg_Auto436[4]=de_Auto436;
	_Context->msg_Auto436[5]=nl_Auto436;
	_Context->msg_Auto436[6]=pt_Auto436;
	_Context->msg_Auto436[7]=xx_Auto436;
	_Context->hint_Auto436[0]=en__Auto436;
	_Context->hint_Auto436[1]=fr__Auto436;
	_Context->hint_Auto436[2]=it__Auto436;
	_Context->hint_Auto436[3]=es__Auto436;
	_Context->hint_Auto436[4]=de__Auto436;
	_Context->hint_Auto436[5]=nl__Auto436;
	_Context->hint_Auto436[6]=pt__Auto436;
	_Context->hint_Auto436[7]=xx__Auto436;
	return(0);
}

public 	int	standard_file_menu_hide(struct standard_file_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto427 != (void *) 0)
	&& (_Context->s_Auto427 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto427,56,32);
		_Context->s_Auto427=0;
		}
	if ((_Context->p_Auto426 != (void *) 0)
	&& (_Context->s_Auto426 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto426,_Context->x_Auto426,_Context->y_Auto426);
		_Context->s_Auto426=0;
		}

	return(result);
}

public	int	standard_file_menu_remove(struct standard_file_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->p_Auto427 != (void *) 0)
		_Context->p_Auto427 = visual_drop(_Context->p_Auto427);
	mouse_move_off();
	if (_Context->p_Auto426 != (void *) 0)
		_Context->p_Auto426 = visual_drop(_Context->p_Auto426);
	_Context=liberate(_Context);

	return(result);
}

public	int	standard_file_menu_show(struct standard_file_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if ((_Context->p_Auto426 != (void *) 0)
	&& (_Context->s_Auto426 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto426,_Context->x_Auto426,_Context->y_Auto426);
		_Context->s_Auto426=1;
		}
	visual_window(_Context->x_Auto426,_Context->y_Auto426,_Context->w_Auto426,_Context->h_Auto426,_Context->fid_Auto426,_Context->msg_Auto426[_Context->language],strlen(_Context->msg_Auto426[_Context->language]),0x4);
	if ((_Context->p_Auto427 != (void *) 0)
	&& (_Context->s_Auto427 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto427,56,32);
		_Context->s_Auto427=1;
		}
	if (((_Context->status = visual_styled_element(56,32,168,204,GetWidgetStyle(1)," ",0)) != 0)
) {
		visual_filzone(56,32,168,204,27,11);
		}
	_Context->trigger_Auto428=visual_trigger_code(_Context->msg_Auto428[_Context->language],strlen(_Context->msg_Auto428[_Context->language]));
	if (((_Context->status = visual_styled_element(72,44,136,20,GetWidgetStyle(2),_Context->msg_Auto428[_Context->language],strlen(_Context->msg_Auto428[_Context->language]))) != 0)
) {
	visual_button(72,44,136,20,vfh[2],16,0,_Context->msg_Auto428[_Context->language],strlen(_Context->msg_Auto428[_Context->language]),32);
		}
	_Context->trigger_Auto429=visual_trigger_code(_Context->msg_Auto429[_Context->language],strlen(_Context->msg_Auto429[_Context->language]));
	if (((_Context->status = visual_styled_element(72,64,136,20,GetWidgetStyle(2),_Context->msg_Auto429[_Context->language],strlen(_Context->msg_Auto429[_Context->language]))) != 0)
) {
	visual_button(72,64,136,20,vfh[2],16,0,_Context->msg_Auto429[_Context->language],strlen(_Context->msg_Auto429[_Context->language]),32);
		}
	_Context->trigger_Auto430=visual_trigger_code(_Context->msg_Auto430[_Context->language],strlen(_Context->msg_Auto430[_Context->language]));
	if (((_Context->status = visual_styled_element(72,84,136,20,GetWidgetStyle(2),_Context->msg_Auto430[_Context->language],strlen(_Context->msg_Auto430[_Context->language]))) != 0)
) {
	visual_button(72,84,136,20,vfh[2],16,0,_Context->msg_Auto430[_Context->language],strlen(_Context->msg_Auto430[_Context->language]),32);
		}
	_Context->trigger_Auto431=visual_trigger_code(_Context->msg_Auto431[_Context->language],strlen(_Context->msg_Auto431[_Context->language]));
	if (((_Context->status = visual_styled_element(72,104,136,20,GetWidgetStyle(2),_Context->msg_Auto431[_Context->language],strlen(_Context->msg_Auto431[_Context->language]))) != 0)
) {
	visual_button(72,104,136,20,vfh[2],16,0,_Context->msg_Auto431[_Context->language],strlen(_Context->msg_Auto431[_Context->language]),32);
		}
	_Context->trigger_Auto432=visual_trigger_code(_Context->msg_Auto432[_Context->language],strlen(_Context->msg_Auto432[_Context->language]));
	if (((_Context->status = visual_styled_element(72,144,136,20,GetWidgetStyle(2),_Context->msg_Auto432[_Context->language],strlen(_Context->msg_Auto432[_Context->language]))) != 0)
) {
	visual_button(72,144,136,20,vfh[2],16,0,_Context->msg_Auto432[_Context->language],strlen(_Context->msg_Auto432[_Context->language]),32);
		}
	_Context->trigger_Auto433=visual_trigger_code(_Context->msg_Auto433[_Context->language],strlen(_Context->msg_Auto433[_Context->language]));
	if (((_Context->status = visual_styled_element(72,164,136,20,GetWidgetStyle(2),_Context->msg_Auto433[_Context->language],strlen(_Context->msg_Auto433[_Context->language]))) != 0)
) {
	visual_button(72,164,136,20,vfh[2],16,0,_Context->msg_Auto433[_Context->language],strlen(_Context->msg_Auto433[_Context->language]),32);
		}
	_Context->trigger_Auto434=visual_trigger_code(_Context->msg_Auto434[_Context->language],strlen(_Context->msg_Auto434[_Context->language]));
	if (((_Context->status = visual_styled_element(72,124,136,20,GetWidgetStyle(2),_Context->msg_Auto434[_Context->language],strlen(_Context->msg_Auto434[_Context->language]))) != 0)
) {
	visual_button(72,124,136,20,vfh[2],16,0,_Context->msg_Auto434[_Context->language],strlen(_Context->msg_Auto434[_Context->language]),32);
		}
	_Context->trigger_Auto435=visual_trigger_code(_Context->msg_Auto435[_Context->language],strlen(_Context->msg_Auto435[_Context->language]));
	if (((_Context->status = visual_styled_element(72,184,136,20,GetWidgetStyle(2),_Context->msg_Auto435[_Context->language],strlen(_Context->msg_Auto435[_Context->language]))) != 0)
) {
	visual_button(72,184,136,20,vfh[2],16,0,_Context->msg_Auto435[_Context->language],strlen(_Context->msg_Auto435[_Context->language]),32);
		}
	_Context->trigger_Auto436=visual_trigger_code(_Context->msg_Auto436[_Context->language],strlen(_Context->msg_Auto436[_Context->language]));
	if (((_Context->status = visual_styled_element(72,204,136,20,GetWidgetStyle(2),_Context->msg_Auto436[_Context->language],strlen(_Context->msg_Auto436[_Context->language]))) != 0)
) {
	visual_button(72,204,136,20,vfh[2],16,0,_Context->msg_Auto436[_Context->language],strlen(_Context->msg_Auto436[_Context->language]),32);
		}
	visual_thaw(_Context->x_Auto426,_Context->y_Auto426,_Context->w_Auto426,_Context->h_Auto426);

	return(0);
}
private int on_Auto428_event(struct standard_file_menu_context * _Context) {
	return(_FILE_NEW);
	return(-1);
}
private int on_Auto429_event(struct standard_file_menu_context * _Context) {
	return(_FILE_QSAVE);
	return(-1);
}
private int on_Auto430_event(struct standard_file_menu_context * _Context) {
	return(_FILE_SAVE);
	return(-1);
}
private int on_Auto431_event(struct standard_file_menu_context * _Context) {
	return(_FILE_LOAD);
	return(-1);
}
private int on_Auto432_event(struct standard_file_menu_context * _Context) {
	return(_FILE_PRODUCE);
	return(-1);
}
private int on_Auto433_event(struct standard_file_menu_context * _Context) {
	return(_FILE_COMPARE);
	return(-1);
}
private int on_Auto434_event(struct standard_file_menu_context * _Context) {
	return(_FILE_DROP);
	return(-1);
}
private int on_Auto435_event(struct standard_file_menu_context * _Context) {
	return(_FILE_ABOUT);
	return(-1);
}
private int on_Auto436_event(struct standard_file_menu_context * _Context) {
	return(_LEAVE_SING);
	return(-1);
}


public	int	standard_file_menu_event(
struct standard_file_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto428 == mb ) return(1);
		if (_Context->trigger_Auto429 == mb ) return(2);
		if (_Context->trigger_Auto430 == mb ) return(3);
		if (_Context->trigger_Auto431 == mb ) return(4);
		if (_Context->trigger_Auto432 == mb ) return(5);
		if (_Context->trigger_Auto433 == mb ) return(6);
		if (_Context->trigger_Auto434 == mb ) return(7);
		if (_Context->trigger_Auto435 == mb ) return(8);
		if (_Context->trigger_Auto436 == mb ) return(9);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= 72 ) 
	&&  ( my >= 44 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 64 )) {
		return(1); /* Auto428 */
		}
	if (( mx >= 72 ) 
	&&  ( my >= 64 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 84 )) {
		return(2); /* Auto429 */
		}
	if (( mx >= 72 ) 
	&&  ( my >= 84 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 104 )) {
		return(3); /* Auto430 */
		}
	if (( mx >= 72 ) 
	&&  ( my >= 104 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 124 )) {
		return(4); /* Auto431 */
		}
	if (( mx >= 72 ) 
	&&  ( my >= 144 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 164 )) {
		return(5); /* Auto432 */
		}
	if (( mx >= 72 ) 
	&&  ( my >= 164 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 184 )) {
		return(6); /* Auto433 */
		}
	if (( mx >= 72 ) 
	&&  ( my >= 124 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 144 )) {
		return(7); /* Auto434 */
		}
	if (( mx >= 72 ) 
	&&  ( my >= 184 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 204 )) {
		return(8); /* Auto435 */
		}
	if (( mx >= 72 ) 
	&&  ( my >= 204 ) 
	&&  ( mx <= 208 ) 
	&&  ( my <= 224 )) {
		return(9); /* Auto436 */
		}

	return(-1);
}


public	int	standard_file_menu_focus(struct standard_file_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto428 */
				_Context->trigger_Auto428=visual_trigger_code(_Context->msg_Auto428[_Context->language],strlen(_Context->msg_Auto428[_Context->language]));
				if (((_Context->status = visual_styled_element(72,44,136,20,GetWidgetStyle(3),_Context->msg_Auto428[_Context->language],strlen(_Context->msg_Auto428[_Context->language]))) != 0)
) {
					visual_button(72,44,136,20,vfh[2],16,0,_Context->msg_Auto428[_Context->language],strlen(_Context->msg_Auto428[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto428=visual_trigger_code(_Context->msg_Auto428[_Context->language],strlen(_Context->msg_Auto428[_Context->language]));
				if (((_Context->status = visual_styled_element(72,44,136,20,GetWidgetStyle(2),_Context->msg_Auto428[_Context->language],strlen(_Context->msg_Auto428[_Context->language]))) != 0)
) {
	visual_button(72,44,136,20,vfh[2],16,0,_Context->msg_Auto428[_Context->language],strlen(_Context->msg_Auto428[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto429 */
				_Context->trigger_Auto429=visual_trigger_code(_Context->msg_Auto429[_Context->language],strlen(_Context->msg_Auto429[_Context->language]));
				if (((_Context->status = visual_styled_element(72,64,136,20,GetWidgetStyle(3),_Context->msg_Auto429[_Context->language],strlen(_Context->msg_Auto429[_Context->language]))) != 0)
) {
					visual_button(72,64,136,20,vfh[2],16,0,_Context->msg_Auto429[_Context->language],strlen(_Context->msg_Auto429[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto429=visual_trigger_code(_Context->msg_Auto429[_Context->language],strlen(_Context->msg_Auto429[_Context->language]));
				if (((_Context->status = visual_styled_element(72,64,136,20,GetWidgetStyle(2),_Context->msg_Auto429[_Context->language],strlen(_Context->msg_Auto429[_Context->language]))) != 0)
) {
	visual_button(72,64,136,20,vfh[2],16,0,_Context->msg_Auto429[_Context->language],strlen(_Context->msg_Auto429[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto430 */
				_Context->trigger_Auto430=visual_trigger_code(_Context->msg_Auto430[_Context->language],strlen(_Context->msg_Auto430[_Context->language]));
				if (((_Context->status = visual_styled_element(72,84,136,20,GetWidgetStyle(3),_Context->msg_Auto430[_Context->language],strlen(_Context->msg_Auto430[_Context->language]))) != 0)
) {
					visual_button(72,84,136,20,vfh[2],16,0,_Context->msg_Auto430[_Context->language],strlen(_Context->msg_Auto430[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto430=visual_trigger_code(_Context->msg_Auto430[_Context->language],strlen(_Context->msg_Auto430[_Context->language]));
				if (((_Context->status = visual_styled_element(72,84,136,20,GetWidgetStyle(2),_Context->msg_Auto430[_Context->language],strlen(_Context->msg_Auto430[_Context->language]))) != 0)
) {
	visual_button(72,84,136,20,vfh[2],16,0,_Context->msg_Auto430[_Context->language],strlen(_Context->msg_Auto430[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto431 */
				_Context->trigger_Auto431=visual_trigger_code(_Context->msg_Auto431[_Context->language],strlen(_Context->msg_Auto431[_Context->language]));
				if (((_Context->status = visual_styled_element(72,104,136,20,GetWidgetStyle(3),_Context->msg_Auto431[_Context->language],strlen(_Context->msg_Auto431[_Context->language]))) != 0)
) {
					visual_button(72,104,136,20,vfh[2],16,0,_Context->msg_Auto431[_Context->language],strlen(_Context->msg_Auto431[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto431=visual_trigger_code(_Context->msg_Auto431[_Context->language],strlen(_Context->msg_Auto431[_Context->language]));
				if (((_Context->status = visual_styled_element(72,104,136,20,GetWidgetStyle(2),_Context->msg_Auto431[_Context->language],strlen(_Context->msg_Auto431[_Context->language]))) != 0)
) {
	visual_button(72,104,136,20,vfh[2],16,0,_Context->msg_Auto431[_Context->language],strlen(_Context->msg_Auto431[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto432 */
				_Context->trigger_Auto432=visual_trigger_code(_Context->msg_Auto432[_Context->language],strlen(_Context->msg_Auto432[_Context->language]));
				if (((_Context->status = visual_styled_element(72,144,136,20,GetWidgetStyle(3),_Context->msg_Auto432[_Context->language],strlen(_Context->msg_Auto432[_Context->language]))) != 0)
) {
					visual_button(72,144,136,20,vfh[2],16,0,_Context->msg_Auto432[_Context->language],strlen(_Context->msg_Auto432[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto432=visual_trigger_code(_Context->msg_Auto432[_Context->language],strlen(_Context->msg_Auto432[_Context->language]));
				if (((_Context->status = visual_styled_element(72,144,136,20,GetWidgetStyle(2),_Context->msg_Auto432[_Context->language],strlen(_Context->msg_Auto432[_Context->language]))) != 0)
) {
	visual_button(72,144,136,20,vfh[2],16,0,_Context->msg_Auto432[_Context->language],strlen(_Context->msg_Auto432[_Context->language]),32);
				}
				break;
			case	0x6 :
				/* Auto433 */
				_Context->trigger_Auto433=visual_trigger_code(_Context->msg_Auto433[_Context->language],strlen(_Context->msg_Auto433[_Context->language]));
				if (((_Context->status = visual_styled_element(72,164,136,20,GetWidgetStyle(3),_Context->msg_Auto433[_Context->language],strlen(_Context->msg_Auto433[_Context->language]))) != 0)
) {
					visual_button(72,164,136,20,vfh[2],16,0,_Context->msg_Auto433[_Context->language],strlen(_Context->msg_Auto433[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto433=visual_trigger_code(_Context->msg_Auto433[_Context->language],strlen(_Context->msg_Auto433[_Context->language]));
				if (((_Context->status = visual_styled_element(72,164,136,20,GetWidgetStyle(2),_Context->msg_Auto433[_Context->language],strlen(_Context->msg_Auto433[_Context->language]))) != 0)
) {
	visual_button(72,164,136,20,vfh[2],16,0,_Context->msg_Auto433[_Context->language],strlen(_Context->msg_Auto433[_Context->language]),32);
				}
				break;
			case	0x7 :
				/* Auto434 */
				_Context->trigger_Auto434=visual_trigger_code(_Context->msg_Auto434[_Context->language],strlen(_Context->msg_Auto434[_Context->language]));
				if (((_Context->status = visual_styled_element(72,124,136,20,GetWidgetStyle(3),_Context->msg_Auto434[_Context->language],strlen(_Context->msg_Auto434[_Context->language]))) != 0)
) {
					visual_button(72,124,136,20,vfh[2],16,0,_Context->msg_Auto434[_Context->language],strlen(_Context->msg_Auto434[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto434=visual_trigger_code(_Context->msg_Auto434[_Context->language],strlen(_Context->msg_Auto434[_Context->language]));
				if (((_Context->status = visual_styled_element(72,124,136,20,GetWidgetStyle(2),_Context->msg_Auto434[_Context->language],strlen(_Context->msg_Auto434[_Context->language]))) != 0)
) {
	visual_button(72,124,136,20,vfh[2],16,0,_Context->msg_Auto434[_Context->language],strlen(_Context->msg_Auto434[_Context->language]),32);
				}
				break;
			case	0x8 :
				/* Auto435 */
				_Context->trigger_Auto435=visual_trigger_code(_Context->msg_Auto435[_Context->language],strlen(_Context->msg_Auto435[_Context->language]));
				if (((_Context->status = visual_styled_element(72,184,136,20,GetWidgetStyle(3),_Context->msg_Auto435[_Context->language],strlen(_Context->msg_Auto435[_Context->language]))) != 0)
) {
					visual_button(72,184,136,20,vfh[2],16,0,_Context->msg_Auto435[_Context->language],strlen(_Context->msg_Auto435[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto435=visual_trigger_code(_Context->msg_Auto435[_Context->language],strlen(_Context->msg_Auto435[_Context->language]));
				if (((_Context->status = visual_styled_element(72,184,136,20,GetWidgetStyle(2),_Context->msg_Auto435[_Context->language],strlen(_Context->msg_Auto435[_Context->language]))) != 0)
) {
	visual_button(72,184,136,20,vfh[2],16,0,_Context->msg_Auto435[_Context->language],strlen(_Context->msg_Auto435[_Context->language]),32);
				}
				break;
			case	0x9 :
				/* Auto436 */
				_Context->trigger_Auto436=visual_trigger_code(_Context->msg_Auto436[_Context->language],strlen(_Context->msg_Auto436[_Context->language]));
				if (((_Context->status = visual_styled_element(72,204,136,20,GetWidgetStyle(3),_Context->msg_Auto436[_Context->language],strlen(_Context->msg_Auto436[_Context->language]))) != 0)
) {
					visual_button(72,204,136,20,vfh[2],16,0,_Context->msg_Auto436[_Context->language],strlen(_Context->msg_Auto436[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto436=visual_trigger_code(_Context->msg_Auto436[_Context->language],strlen(_Context->msg_Auto436[_Context->language]));
				if (((_Context->status = visual_styled_element(72,204,136,20,GetWidgetStyle(2),_Context->msg_Auto436[_Context->language],strlen(_Context->msg_Auto436[_Context->language]))) != 0)
) {
	visual_button(72,204,136,20,vfh[2],16,0,_Context->msg_Auto436[_Context->language],strlen(_Context->msg_Auto436[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			standard_file_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=9;
			standard_file_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  56 )
				|| ( visual_event(6) <  32 )
				|| ( visual_event(7) >  224 )
				|| ( visual_event(6) >  236 )) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=standard_file_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto428 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto428=visual_trigger_code(_Context->msg_Auto428[_Context->language],strlen(_Context->msg_Auto428[_Context->language]));
						if (((_Context->status = visual_styled_element(72,44,136,20,GetWidgetStyle(3),_Context->msg_Auto428[_Context->language],strlen(_Context->msg_Auto428[_Context->language]))) != 0)
) {
							visual_button(72,44,136,20,vfh[2],16,0,_Context->msg_Auto428[_Context->language],strlen(_Context->msg_Auto428[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto428=visual_trigger_code(_Context->msg_Auto428[_Context->language],strlen(_Context->msg_Auto428[_Context->language]));
						if (((_Context->status = visual_styled_element(72,44,136,20,GetWidgetStyle(2),_Context->msg_Auto428[_Context->language],strlen(_Context->msg_Auto428[_Context->language]))) != 0)
) {
	visual_button(72,44,136,20,vfh[2],16,0,_Context->msg_Auto428[_Context->language],strlen(_Context->msg_Auto428[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto428_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto429 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto429=visual_trigger_code(_Context->msg_Auto429[_Context->language],strlen(_Context->msg_Auto429[_Context->language]));
						if (((_Context->status = visual_styled_element(72,64,136,20,GetWidgetStyle(3),_Context->msg_Auto429[_Context->language],strlen(_Context->msg_Auto429[_Context->language]))) != 0)
) {
							visual_button(72,64,136,20,vfh[2],16,0,_Context->msg_Auto429[_Context->language],strlen(_Context->msg_Auto429[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto429=visual_trigger_code(_Context->msg_Auto429[_Context->language],strlen(_Context->msg_Auto429[_Context->language]));
						if (((_Context->status = visual_styled_element(72,64,136,20,GetWidgetStyle(2),_Context->msg_Auto429[_Context->language],strlen(_Context->msg_Auto429[_Context->language]))) != 0)
) {
	visual_button(72,64,136,20,vfh[2],16,0,_Context->msg_Auto429[_Context->language],strlen(_Context->msg_Auto429[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto429_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto430 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto430=visual_trigger_code(_Context->msg_Auto430[_Context->language],strlen(_Context->msg_Auto430[_Context->language]));
						if (((_Context->status = visual_styled_element(72,84,136,20,GetWidgetStyle(3),_Context->msg_Auto430[_Context->language],strlen(_Context->msg_Auto430[_Context->language]))) != 0)
) {
							visual_button(72,84,136,20,vfh[2],16,0,_Context->msg_Auto430[_Context->language],strlen(_Context->msg_Auto430[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto430=visual_trigger_code(_Context->msg_Auto430[_Context->language],strlen(_Context->msg_Auto430[_Context->language]));
						if (((_Context->status = visual_styled_element(72,84,136,20,GetWidgetStyle(2),_Context->msg_Auto430[_Context->language],strlen(_Context->msg_Auto430[_Context->language]))) != 0)
) {
	visual_button(72,84,136,20,vfh[2],16,0,_Context->msg_Auto430[_Context->language],strlen(_Context->msg_Auto430[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto430_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto431 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto431=visual_trigger_code(_Context->msg_Auto431[_Context->language],strlen(_Context->msg_Auto431[_Context->language]));
						if (((_Context->status = visual_styled_element(72,104,136,20,GetWidgetStyle(3),_Context->msg_Auto431[_Context->language],strlen(_Context->msg_Auto431[_Context->language]))) != 0)
) {
							visual_button(72,104,136,20,vfh[2],16,0,_Context->msg_Auto431[_Context->language],strlen(_Context->msg_Auto431[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto431=visual_trigger_code(_Context->msg_Auto431[_Context->language],strlen(_Context->msg_Auto431[_Context->language]));
						if (((_Context->status = visual_styled_element(72,104,136,20,GetWidgetStyle(2),_Context->msg_Auto431[_Context->language],strlen(_Context->msg_Auto431[_Context->language]))) != 0)
) {
	visual_button(72,104,136,20,vfh[2],16,0,_Context->msg_Auto431[_Context->language],strlen(_Context->msg_Auto431[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto431_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto432 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto432=visual_trigger_code(_Context->msg_Auto432[_Context->language],strlen(_Context->msg_Auto432[_Context->language]));
						if (((_Context->status = visual_styled_element(72,144,136,20,GetWidgetStyle(3),_Context->msg_Auto432[_Context->language],strlen(_Context->msg_Auto432[_Context->language]))) != 0)
) {
							visual_button(72,144,136,20,vfh[2],16,0,_Context->msg_Auto432[_Context->language],strlen(_Context->msg_Auto432[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto432=visual_trigger_code(_Context->msg_Auto432[_Context->language],strlen(_Context->msg_Auto432[_Context->language]));
						if (((_Context->status = visual_styled_element(72,144,136,20,GetWidgetStyle(2),_Context->msg_Auto432[_Context->language],strlen(_Context->msg_Auto432[_Context->language]))) != 0)
) {
	visual_button(72,144,136,20,vfh[2],16,0,_Context->msg_Auto432[_Context->language],strlen(_Context->msg_Auto432[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto432_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto433 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto433=visual_trigger_code(_Context->msg_Auto433[_Context->language],strlen(_Context->msg_Auto433[_Context->language]));
						if (((_Context->status = visual_styled_element(72,164,136,20,GetWidgetStyle(3),_Context->msg_Auto433[_Context->language],strlen(_Context->msg_Auto433[_Context->language]))) != 0)
) {
							visual_button(72,164,136,20,vfh[2],16,0,_Context->msg_Auto433[_Context->language],strlen(_Context->msg_Auto433[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto433=visual_trigger_code(_Context->msg_Auto433[_Context->language],strlen(_Context->msg_Auto433[_Context->language]));
						if (((_Context->status = visual_styled_element(72,164,136,20,GetWidgetStyle(2),_Context->msg_Auto433[_Context->language],strlen(_Context->msg_Auto433[_Context->language]))) != 0)
) {
	visual_button(72,164,136,20,vfh[2],16,0,_Context->msg_Auto433[_Context->language],strlen(_Context->msg_Auto433[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto433_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Auto434 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto434=visual_trigger_code(_Context->msg_Auto434[_Context->language],strlen(_Context->msg_Auto434[_Context->language]));
						if (((_Context->status = visual_styled_element(72,124,136,20,GetWidgetStyle(3),_Context->msg_Auto434[_Context->language],strlen(_Context->msg_Auto434[_Context->language]))) != 0)
) {
							visual_button(72,124,136,20,vfh[2],16,0,_Context->msg_Auto434[_Context->language],strlen(_Context->msg_Auto434[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto434=visual_trigger_code(_Context->msg_Auto434[_Context->language],strlen(_Context->msg_Auto434[_Context->language]));
						if (((_Context->status = visual_styled_element(72,124,136,20,GetWidgetStyle(2),_Context->msg_Auto434[_Context->language],strlen(_Context->msg_Auto434[_Context->language]))) != 0)
) {
	visual_button(72,124,136,20,vfh[2],16,0,_Context->msg_Auto434[_Context->language],strlen(_Context->msg_Auto434[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto434_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Auto435 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto435=visual_trigger_code(_Context->msg_Auto435[_Context->language],strlen(_Context->msg_Auto435[_Context->language]));
						if (((_Context->status = visual_styled_element(72,184,136,20,GetWidgetStyle(3),_Context->msg_Auto435[_Context->language],strlen(_Context->msg_Auto435[_Context->language]))) != 0)
) {
							visual_button(72,184,136,20,vfh[2],16,0,_Context->msg_Auto435[_Context->language],strlen(_Context->msg_Auto435[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto435=visual_trigger_code(_Context->msg_Auto435[_Context->language],strlen(_Context->msg_Auto435[_Context->language]));
						if (((_Context->status = visual_styled_element(72,184,136,20,GetWidgetStyle(2),_Context->msg_Auto435[_Context->language],strlen(_Context->msg_Auto435[_Context->language]))) != 0)
) {
	visual_button(72,184,136,20,vfh[2],16,0,_Context->msg_Auto435[_Context->language],strlen(_Context->msg_Auto435[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto435_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Auto436 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto436=visual_trigger_code(_Context->msg_Auto436[_Context->language],strlen(_Context->msg_Auto436[_Context->language]));
						if (((_Context->status = visual_styled_element(72,204,136,20,GetWidgetStyle(3),_Context->msg_Auto436[_Context->language],strlen(_Context->msg_Auto436[_Context->language]))) != 0)
) {
							visual_button(72,204,136,20,vfh[2],16,0,_Context->msg_Auto436[_Context->language],strlen(_Context->msg_Auto436[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto436=visual_trigger_code(_Context->msg_Auto436[_Context->language],strlen(_Context->msg_Auto436[_Context->language]));
						if (((_Context->status = visual_styled_element(72,204,136,20,GetWidgetStyle(2),_Context->msg_Auto436[_Context->language],strlen(_Context->msg_Auto436[_Context->language]))) != 0)
) {
	visual_button(72,204,136,20,vfh[2],16,0,_Context->msg_Auto436[_Context->language],strlen(_Context->msg_Auto436[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto436_event(_Context)) != -1) break;

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
				_Context->focus_item=9;
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

public	int	standard_file_menu()
{
	int	status=0;
	struct standard_file_menu_context * _Context=(struct standard_file_menu_context*) 0;
	status = standard_file_menu_create(&_Context);
	if ( status != 0) return(status);
	status = standard_file_menu_show(_Context);
		enter_modal();
	status = standard_file_menu_focus(_Context);
		leave_modal();
	status = standard_file_menu_hide(_Context);
	status = standard_file_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _filemenu_c */
