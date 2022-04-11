
#ifndef _membermenu_c
#define _membermenu_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : membermenu.xml                                           */
/* Target         : membermenu.c                                             */
/* Identification : 0.0-1197225567-30633.30632                               */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singmenu.h"
#include "singdbed.h"
#define en_Auto338   "Sing Version 2.1a"
#define fr_Auto338   "Sing Version 2.1a"
#define it_Auto338   "Sing Version 2.1a"
#define es_Auto338   "Sing Version 2.1a"
#define de_Auto338   "Sing Version 2.1a"
#define nl_Auto338   "Sing Version 2.1a"
#define pt_Auto338   "Sing Version 2.1a"
#define xx_Auto338   "Sing Version 2.1a"
#define en__Auto338   ""
#define fr__Auto338   ""
#define it__Auto338   ""
#define es__Auto338   ""
#define de__Auto338   ""
#define nl__Auto338   ""
#define pt__Auto338   ""
#define xx__Auto338   ""
#define en_Auto339   "&Define Member"
#define fr_Auto339   "&Definir Membre"
#define it_Auto339   "&Define Member"
#define es_Auto339   "&Define Member"
#define de_Auto339   "&Define Member"
#define nl_Auto339   "&Define Member"
#define pt_Auto339   "&Define Member"
#define xx_Auto339   "&Define Member"
#define en__Auto339   ""
#define fr__Auto339   ""
#define it__Auto339   ""
#define es__Auto339   ""
#define de__Auto339   ""
#define nl__Auto339   ""
#define pt__Auto339   ""
#define xx__Auto339   ""
#define en_Auto340   "&Copy Member"
#define fr_Auto340   "&Copier Membre"
#define it_Auto340   "&Copy Member"
#define es_Auto340   "&Copy Member"
#define de_Auto340   "&Copy Member"
#define nl_Auto340   "&Copy Member"
#define pt_Auto340   "&Copy Member"
#define xx_Auto340   "&Copy Member"
#define en__Auto340   ""
#define fr__Auto340   ""
#define it__Auto340   ""
#define es__Auto340   ""
#define de__Auto340   ""
#define nl__Auto340   ""
#define pt__Auto340   ""
#define xx__Auto340   ""
#define en_Auto341   "D&elete Member"
#define fr_Auto341   "&Supprimer Membre"
#define it_Auto341   "D&elete Member"
#define es_Auto341   "D&elete Member"
#define de_Auto341   "D&elete Member"
#define nl_Auto341   "D&elete Member"
#define pt_Auto341   "D&elete Member"
#define xx_Auto341   "D&elete Member"
#define en__Auto341   ""
#define fr__Auto341   ""
#define it__Auto341   ""
#define es__Auto341   ""
#define de__Auto341   ""
#define nl__Auto341   ""
#define pt__Auto341   ""
#define xx__Auto341   ""
#define en__Auto342   ""
#define en_Auto343   "&Add Member Before Current"
#define fr_Auto343   "&Ajout d'un membre avant le courant"
#define it_Auto343   "&Add Member Before Current"
#define es_Auto343   "&Add Member Before Current"
#define de_Auto343   "&Add Member Before Current"
#define nl_Auto343   "&Add Member Before Current"
#define pt_Auto343   "&Add Member Before Current"
#define xx_Auto343   "&Add Member Before Current"
#define en__Auto343   ""
#define fr__Auto343   ""
#define it__Auto343   ""
#define es__Auto343   ""
#define de__Auto343   ""
#define nl__Auto343   ""
#define pt__Auto343   ""
#define xx__Auto343   ""
#define en_Auto344   "Add &Member After Current"
#define fr_Auto344   "A&jout d'un membre apres le courant"
#define it_Auto344   "Add &Member After Current"
#define es_Auto344   "Add &Member After Current"
#define de_Auto344   "Add &Member After Current"
#define nl_Auto344   "Add &Member After Current"
#define pt_Auto344   "Add &Member After Current"
#define xx_Auto344   "Add &Member After Current"
#define en__Auto344   ""
#define fr__Auto344   ""
#define it__Auto344   ""
#define es__Auto344   ""
#define de__Auto344   ""
#define nl__Auto344   ""
#define pt__Auto344   ""
#define xx__Auto344   ""
#define en_Auto345   "Add Mem&ber Relation"
#define fr_Auto345   "Aj&out d'un relation entre membres"
#define it_Auto345   "Add Mem&ber Relation"
#define es_Auto345   "Add Mem&ber Relation"
#define de_Auto345   "Add Mem&ber Relation"
#define nl_Auto345   "Add Mem&ber Relation"
#define pt_Auto345   "Add Mem&ber Relation"
#define xx_Auto345   "Add Mem&ber Relation"
#define en__Auto345   ""
#define fr__Auto345   ""
#define it__Auto345   ""
#define es__Auto345   ""
#define de__Auto345   ""
#define nl__Auto345   ""
#define pt__Auto345   ""
#define xx__Auto345   ""
#define en__Auto346   ""
#define en_Auto347   "&Toggle Primary Index Member"
#define fr_Auto347   "&Baculer membre entre record et indexe primaire."
#define it_Auto347   "&Toggle Primary Index"
#define es_Auto347   "&Toggle Primary Index"
#define de_Auto347   "&Toggle Primary Index"
#define nl_Auto347   "&Toggle Primary Index"
#define pt_Auto347   "&Toggle Primary Index"
#define xx_Auto347   "&Toggle Primary Index"
#define en__Auto347   ""
#define fr__Auto347   ""
#define it__Auto347   ""
#define es__Auto347   ""
#define de__Auto347   ""
#define nl__Auto347   ""
#define pt__Auto347   ""
#define xx__Auto347   ""
#define en_Auto348   "T&oggle Secondary Index Member"
#define fr_Auto348   "Basc&uler Membre Indexe Secondaire"
#define it_Auto348   "T&oggle Secondary Index"
#define es_Auto348   "T&oggle Secondary Index"
#define de_Auto348   "T&oggle Secondary Index"
#define nl_Auto348   "T&oggle Secondary Index"
#define pt_Auto348   "T&oggle Secondary Index"
#define xx_Auto348   "T&oggle Secondary Index"
#define en__Auto348   ""
#define fr__Auto348   ""
#define it__Auto348   ""
#define es__Auto348   ""
#define de__Auto348   ""
#define nl__Auto348   ""
#define pt__Auto348   ""
#define xx__Auto348   ""
#define en_Auto349   "To&ggle List Column Member"
#define fr_Auto349   "Bascu&ler Membre Colonne de Liste"
#define it_Auto349   "To&ggle List Column"
#define es_Auto349   "To&ggle List Column"
#define de_Auto349   "To&ggle List Column"
#define nl_Auto349   "To&ggle List Column"
#define pt_Auto349   "To&ggle List Column"
#define xx_Auto349   "To&ggle List Column"
#define en__Auto349   ""
#define fr__Auto349   ""
#define it__Auto349   ""
#define es__Auto349   ""
#define de__Auto349   ""
#define nl__Auto349   ""
#define pt__Auto349   ""
#define xx__Auto349   ""

private struct database_member_menu_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto338[8];
	char * hint_Auto338[8];
	int	s_Auto338;
	void *	p_Auto338;
	int	x_Auto338;
	int	y_Auto338;
	int	w_Auto338;
	int	h_Auto338;
	char * msg_Auto339[8];
	int	trigger_Auto339;
	char * hint_Auto339[8];
	char * msg_Auto340[8];
	int	trigger_Auto340;
	char * hint_Auto340[8];
	char * msg_Auto341[8];
	int	trigger_Auto341;
	char * hint_Auto341[8];
	char * hint_Auto342[8];
	char * msg_Auto343[8];
	int	trigger_Auto343;
	char * hint_Auto343[8];
	char * msg_Auto344[8];
	int	trigger_Auto344;
	char * hint_Auto344[8];
	char * msg_Auto345[8];
	int	trigger_Auto345;
	char * hint_Auto345[8];
	char * hint_Auto346[8];
	char * msg_Auto347[8];
	int	trigger_Auto347;
	char * hint_Auto347[8];
	char * msg_Auto348[8];
	int	trigger_Auto348;
	char * hint_Auto348[8];
	char * msg_Auto349[8];
	int	trigger_Auto349;
	char * hint_Auto349[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[16];

static int stdinput(struct database_member_menu_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = database_member_menu_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}

private int on_Auto338_create(struct database_member_menu_context * _Context) {
	mouse_move_on();
	if(((_Context->y_Auto338=visual_event(6))+220)>hardrows())
	_Context->y_Auto338=(hardrows()-220);
	if(((_Context->x_Auto338=visual_event(7))+320)>hardcolumns())
	_Context->x_Auto338=(hardcolumns()-320);
	return(-1);
}

public	int	database_member_menu_create(struct database_member_menu_context **cptr)
{

	int i;
	struct database_member_menu_context * _Context=(struct database_member_menu_context*)0;
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
	if (!(_Context = allocate( sizeof( struct database_member_menu_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=9;
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
	_Context->s_Auto338=0;
	_Context->p_Auto338=visual_buffer(_Context->x_Auto338,_Context->y_Auto338,320+2,220+2);
	_Context->x_Auto338=40;
	_Context->y_Auto338=40;
	_Context->w_Auto338=320;
	_Context->h_Auto338=220;
	_Context->window_col=40;
	_Context->window_row=40;
	(void) on_Auto338_create(_Context);
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
	for (i=0; i < 8; i++)_Context->msg_Auto341[i]=" ";
	_Context->msg_Auto341[0]=en_Auto341;
	_Context->msg_Auto341[1]=fr_Auto341;
	_Context->msg_Auto341[2]=it_Auto341;
	_Context->msg_Auto341[3]=es_Auto341;
	_Context->msg_Auto341[4]=de_Auto341;
	_Context->msg_Auto341[5]=nl_Auto341;
	_Context->msg_Auto341[6]=pt_Auto341;
	_Context->msg_Auto341[7]=xx_Auto341;
	_Context->hint_Auto341[0]=en__Auto341;
	_Context->hint_Auto341[1]=fr__Auto341;
	_Context->hint_Auto341[2]=it__Auto341;
	_Context->hint_Auto341[3]=es__Auto341;
	_Context->hint_Auto341[4]=de__Auto341;
	_Context->hint_Auto341[5]=nl__Auto341;
	_Context->hint_Auto341[6]=pt__Auto341;
	_Context->hint_Auto341[7]=xx__Auto341;
	_Context->hint_Auto342[0]=en__Auto342;
	for (i=0; i < 8; i++)_Context->msg_Auto343[i]=" ";
	_Context->msg_Auto343[0]=en_Auto343;
	_Context->msg_Auto343[1]=fr_Auto343;
	_Context->msg_Auto343[2]=it_Auto343;
	_Context->msg_Auto343[3]=es_Auto343;
	_Context->msg_Auto343[4]=de_Auto343;
	_Context->msg_Auto343[5]=nl_Auto343;
	_Context->msg_Auto343[6]=pt_Auto343;
	_Context->msg_Auto343[7]=xx_Auto343;
	_Context->hint_Auto343[0]=en__Auto343;
	_Context->hint_Auto343[1]=fr__Auto343;
	_Context->hint_Auto343[2]=it__Auto343;
	_Context->hint_Auto343[3]=es__Auto343;
	_Context->hint_Auto343[4]=de__Auto343;
	_Context->hint_Auto343[5]=nl__Auto343;
	_Context->hint_Auto343[6]=pt__Auto343;
	_Context->hint_Auto343[7]=xx__Auto343;
	for (i=0; i < 8; i++)_Context->msg_Auto344[i]=" ";
	_Context->msg_Auto344[0]=en_Auto344;
	_Context->msg_Auto344[1]=fr_Auto344;
	_Context->msg_Auto344[2]=it_Auto344;
	_Context->msg_Auto344[3]=es_Auto344;
	_Context->msg_Auto344[4]=de_Auto344;
	_Context->msg_Auto344[5]=nl_Auto344;
	_Context->msg_Auto344[6]=pt_Auto344;
	_Context->msg_Auto344[7]=xx_Auto344;
	_Context->hint_Auto344[0]=en__Auto344;
	_Context->hint_Auto344[1]=fr__Auto344;
	_Context->hint_Auto344[2]=it__Auto344;
	_Context->hint_Auto344[3]=es__Auto344;
	_Context->hint_Auto344[4]=de__Auto344;
	_Context->hint_Auto344[5]=nl__Auto344;
	_Context->hint_Auto344[6]=pt__Auto344;
	_Context->hint_Auto344[7]=xx__Auto344;
	for (i=0; i < 8; i++)_Context->msg_Auto345[i]=" ";
	_Context->msg_Auto345[0]=en_Auto345;
	_Context->msg_Auto345[1]=fr_Auto345;
	_Context->msg_Auto345[2]=it_Auto345;
	_Context->msg_Auto345[3]=es_Auto345;
	_Context->msg_Auto345[4]=de_Auto345;
	_Context->msg_Auto345[5]=nl_Auto345;
	_Context->msg_Auto345[6]=pt_Auto345;
	_Context->msg_Auto345[7]=xx_Auto345;
	_Context->hint_Auto345[0]=en__Auto345;
	_Context->hint_Auto345[1]=fr__Auto345;
	_Context->hint_Auto345[2]=it__Auto345;
	_Context->hint_Auto345[3]=es__Auto345;
	_Context->hint_Auto345[4]=de__Auto345;
	_Context->hint_Auto345[5]=nl__Auto345;
	_Context->hint_Auto345[6]=pt__Auto345;
	_Context->hint_Auto345[7]=xx__Auto345;
	_Context->hint_Auto346[0]=en__Auto346;
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
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto338,_Context->y_Auto338,320,220);
	return(0);
}

public 	int	database_member_menu_hide(struct database_member_menu_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Auto338 != (void *) 0)
	&& (_Context->s_Auto338 != 0)) {
		(void)visual_buffer_put(_Context->p_Auto338,_Context->x_Auto338,_Context->y_Auto338);
		_Context->s_Auto338=0;
		}
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto338,_Context->y_Auto338);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	database_member_menu_remove(struct database_member_menu_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	mouse_move_off();
	if (_Context->p_Auto338 != (void *) 0)
		_Context->p_Auto338 = visual_drop(_Context->p_Auto338);
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	database_member_menu_show(struct database_member_menu_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto338,_Context->y_Auto338);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if ((_Context->p_Auto338 != (void *) 0)
	&& (_Context->s_Auto338 == 0)) {
		(void)visual_buffer_get(_Context->p_Auto338,_Context->x_Auto338,_Context->y_Auto338);
		_Context->s_Auto338=1;
		}
	if (((_Context->status = visual_styled_element(_Context->x_Auto338,_Context->y_Auto338,320,220,GetWidgetStyle(1),_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]))) != 0)
) {
		visual_window(_Context->x_Auto338,_Context->y_Auto338,320,220,vfh[1],_Context->msg_Auto338[_Context->language],strlen(_Context->msg_Auto338[_Context->language]),0x4);
		}
	_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+10,290,20,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+10,290,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
		}
	_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+30,296,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+30,296,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
		}
	_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+50,296,20,GetWidgetStyle(2),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+50,296,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),32);
		}
	visual_filzone(_Context->x_Auto338+10,_Context->y_Auto338+70,300,4,26,18);
	_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+80,290,20,GetWidgetStyle(2),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+80,290,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),32);
		}
	_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+100,296,20,GetWidgetStyle(2),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+100,296,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),32);
		}
	_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+120,296,20,GetWidgetStyle(2),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+120,296,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),32);
		}
	visual_filzone(_Context->x_Auto338+10,_Context->y_Auto338+140,300,4,26,18);
	_Context->trigger_Auto347=visual_trigger_code(_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+150,290,20,GetWidgetStyle(2),_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+150,290,20,vfh[2],16,0,_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]),32);
		}
	_Context->trigger_Auto348=visual_trigger_code(_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+170,290,20,GetWidgetStyle(2),_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+170,290,20,vfh[2],16,0,_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]),32);
		}
	_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
	if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+190,290,20,GetWidgetStyle(2),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+190,290,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),32);
		}
	visual_thaw(_Context->x_Auto338,_Context->y_Auto338,320,220);

	return(0);
}
private int on_Auto339_event(struct database_member_menu_context * _Context) {
	return(_MEMBER_DEFINE);
	return(-1);
}
private int on_Auto340_event(struct database_member_menu_context * _Context) {
	return(_MEMBER_COPY);
	return(-1);
}
private int on_Auto341_event(struct database_member_menu_context * _Context) {
	return(_MEMBER_DELETE);
	return(-1);
}
private int on_Auto343_event(struct database_member_menu_context * _Context) {
	return(_MEMBER_BEFORE);
	return(-1);
}
private int on_Auto344_event(struct database_member_menu_context * _Context) {
	return(_MEMBER_AFTER);
	return(-1);
}
private int on_Auto345_event(struct database_member_menu_context * _Context) {
	return(_MEMBER_RELATION);
	return(-1);
}
private int on_Auto347_event(struct database_member_menu_context * _Context) {
	return(_MEMBER_NATURE);
	return(-1);
}
private int on_Auto348_event(struct database_member_menu_context * _Context) {
	return(_MEMBER_LINK);
	return(-1);
}
private int on_Auto349_event(struct database_member_menu_context * _Context) {
	return(_MEMBER_LIST);
	return(-1);
}


public	int	database_member_menu_event(
struct database_member_menu_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto339 == mb ) return(1);
		if (_Context->trigger_Auto340 == mb ) return(2);
		if (_Context->trigger_Auto341 == mb ) return(3);
		if (_Context->trigger_Auto343 == mb ) return(4);
		if (_Context->trigger_Auto344 == mb ) return(5);
		if (_Context->trigger_Auto345 == mb ) return(6);
		if (_Context->trigger_Auto347 == mb ) return(7);
		if (_Context->trigger_Auto348 == mb ) return(8);
		if (_Context->trigger_Auto349 == mb ) return(9);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3331)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_Auto338+10) ) 
	&&  ( my >= (_Context->y_Auto338+10) ) 
	&&  ( mx <= (_Context->x_Auto338+10+290) ) 
	&&  ( my <= (_Context->y_Auto338+10+20))) {
		return(1); /* Auto339 */
		}
	if (( mx >= (_Context->x_Auto338+10) ) 
	&&  ( my >= (_Context->y_Auto338+30) ) 
	&&  ( mx <= (_Context->x_Auto338+10+296) ) 
	&&  ( my <= (_Context->y_Auto338+30+20))) {
		return(2); /* Auto340 */
		}
	if (( mx >= (_Context->x_Auto338+10) ) 
	&&  ( my >= (_Context->y_Auto338+50) ) 
	&&  ( mx <= (_Context->x_Auto338+10+296) ) 
	&&  ( my <= (_Context->y_Auto338+50+20))) {
		return(3); /* Auto341 */
		}
	if (( mx >= (_Context->x_Auto338+10) ) 
	&&  ( my >= (_Context->y_Auto338+80) ) 
	&&  ( mx <= (_Context->x_Auto338+10+290) ) 
	&&  ( my <= (_Context->y_Auto338+80+20))) {
		return(4); /* Auto343 */
		}
	if (( mx >= (_Context->x_Auto338+10) ) 
	&&  ( my >= (_Context->y_Auto338+100) ) 
	&&  ( mx <= (_Context->x_Auto338+10+296) ) 
	&&  ( my <= (_Context->y_Auto338+100+20))) {
		return(5); /* Auto344 */
		}
	if (( mx >= (_Context->x_Auto338+10) ) 
	&&  ( my >= (_Context->y_Auto338+120) ) 
	&&  ( mx <= (_Context->x_Auto338+10+296) ) 
	&&  ( my <= (_Context->y_Auto338+120+20))) {
		return(6); /* Auto345 */
		}
	if (( mx >= (_Context->x_Auto338+10) ) 
	&&  ( my >= (_Context->y_Auto338+150) ) 
	&&  ( mx <= (_Context->x_Auto338+10+290) ) 
	&&  ( my <= (_Context->y_Auto338+150+20))) {
		return(7); /* Auto347 */
		}
	if (( mx >= (_Context->x_Auto338+10) ) 
	&&  ( my >= (_Context->y_Auto338+170) ) 
	&&  ( mx <= (_Context->x_Auto338+10+290) ) 
	&&  ( my <= (_Context->y_Auto338+170+20))) {
		return(8); /* Auto348 */
		}
	if (( mx >= (_Context->x_Auto338+10) ) 
	&&  ( my >= (_Context->y_Auto338+190) ) 
	&&  ( mx <= (_Context->x_Auto338+10+290) ) 
	&&  ( my <= (_Context->y_Auto338+190+20))) {
		return(9); /* Auto349 */
		}

	return(-1);
}


public	int	database_member_menu_focus(struct database_member_menu_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto339 */
				_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+10,290,20,GetWidgetStyle(3),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto338+10,_Context->y_Auto338+10,290,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+10,290,20,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+10,290,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
				}
				break;
			case	0x2 :
				/* Auto340 */
				_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+30,296,20,GetWidgetStyle(3),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto338+10,_Context->y_Auto338+30,296,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+30,296,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+30,296,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
				}
				break;
			case	0x3 :
				/* Auto341 */
				_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+50,296,20,GetWidgetStyle(3),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto338+10,_Context->y_Auto338+50,296,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+50,296,20,GetWidgetStyle(2),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+50,296,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),32);
				}
				break;
			case	0x4 :
				/* Auto343 */
				_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+80,290,20,GetWidgetStyle(3),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto338+10,_Context->y_Auto338+80,290,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+80,290,20,GetWidgetStyle(2),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+80,290,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),32);
				}
				break;
			case	0x5 :
				/* Auto344 */
				_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+100,296,20,GetWidgetStyle(3),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto338+10,_Context->y_Auto338+100,296,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+100,296,20,GetWidgetStyle(2),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+100,296,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),32);
				}
				break;
			case	0x6 :
				/* Auto345 */
				_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+120,296,20,GetWidgetStyle(3),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto338+10,_Context->y_Auto338+120,296,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+120,296,20,GetWidgetStyle(2),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+120,296,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),32);
				}
				break;
			case	0x7 :
				/* Auto347 */
				_Context->trigger_Auto347=visual_trigger_code(_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+150,290,20,GetWidgetStyle(3),_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto338+10,_Context->y_Auto338+150,290,20,vfh[2],16,0,_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto347=visual_trigger_code(_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+150,290,20,GetWidgetStyle(2),_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+150,290,20,vfh[2],16,0,_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]),32);
				}
				break;
			case	0x8 :
				/* Auto348 */
				_Context->trigger_Auto348=visual_trigger_code(_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+170,290,20,GetWidgetStyle(3),_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto338+10,_Context->y_Auto338+170,290,20,vfh[2],16,0,_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto348=visual_trigger_code(_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+170,290,20,GetWidgetStyle(2),_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+170,290,20,vfh[2],16,0,_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]),32);
				}
				break;
			case	0x9 :
				/* Auto349 */
				_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+190,290,20,GetWidgetStyle(3),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
					visual_button(_Context->x_Auto338+10,_Context->y_Auto338+190,290,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),34);
				}
				_Context->keycode = stdinput(_Context);
				_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
				if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+190,290,20,GetWidgetStyle(2),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+190,290,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),32);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			database_member_menu_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=9;
			database_member_menu_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  _Context->x_Auto338 )
				|| ( visual_event(6) < _Context->y_Auto338  )
				|| ( visual_event(7) > (_Context->x_Auto338+_Context->w_Auto338))
				|| ( visual_event(6) >  (_Context->y_Auto338+_Context->h_Auto338))) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=database_member_menu_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto339 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+10,290,20,GetWidgetStyle(3),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto338+10,_Context->y_Auto338+10,290,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto339=visual_trigger_code(_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+10,290,20,GetWidgetStyle(2),_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+10,290,20,vfh[2],16,0,_Context->msg_Auto339[_Context->language],strlen(_Context->msg_Auto339[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto339_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Auto340 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+30,296,20,GetWidgetStyle(3),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto338+10,_Context->y_Auto338+30,296,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto340=visual_trigger_code(_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+30,296,20,GetWidgetStyle(2),_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+30,296,20,vfh[2],16,0,_Context->msg_Auto340[_Context->language],strlen(_Context->msg_Auto340[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto340_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Auto341 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+50,296,20,GetWidgetStyle(3),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto338+10,_Context->y_Auto338+50,296,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto341=visual_trigger_code(_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+50,296,20,GetWidgetStyle(2),_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+50,296,20,vfh[2],16,0,_Context->msg_Auto341[_Context->language],strlen(_Context->msg_Auto341[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto341_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto343 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+80,290,20,GetWidgetStyle(3),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto338+10,_Context->y_Auto338+80,290,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto343=visual_trigger_code(_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+80,290,20,GetWidgetStyle(2),_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+80,290,20,vfh[2],16,0,_Context->msg_Auto343[_Context->language],strlen(_Context->msg_Auto343[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto343_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Auto344 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+100,296,20,GetWidgetStyle(3),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto338+10,_Context->y_Auto338+100,296,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto344=visual_trigger_code(_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+100,296,20,GetWidgetStyle(2),_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+100,296,20,vfh[2],16,0,_Context->msg_Auto344[_Context->language],strlen(_Context->msg_Auto344[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto344_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto345 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+120,296,20,GetWidgetStyle(3),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto338+10,_Context->y_Auto338+120,296,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto345=visual_trigger_code(_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+120,296,20,GetWidgetStyle(2),_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+120,296,20,vfh[2],16,0,_Context->msg_Auto345[_Context->language],strlen(_Context->msg_Auto345[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto345_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Auto347 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto347=visual_trigger_code(_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+150,290,20,GetWidgetStyle(3),_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto338+10,_Context->y_Auto338+150,290,20,vfh[2],16,0,_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto347=visual_trigger_code(_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+150,290,20,GetWidgetStyle(2),_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+150,290,20,vfh[2],16,0,_Context->msg_Auto347[_Context->language],strlen(_Context->msg_Auto347[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto347_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Auto348 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto348=visual_trigger_code(_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+170,290,20,GetWidgetStyle(3),_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto338+10,_Context->y_Auto338+170,290,20,vfh[2],16,0,_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto348=visual_trigger_code(_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+170,290,20,GetWidgetStyle(2),_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+170,290,20,vfh[2],16,0,_Context->msg_Auto348[_Context->language],strlen(_Context->msg_Auto348[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto348_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Auto349 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+190,290,20,GetWidgetStyle(3),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
							visual_button(_Context->x_Auto338+10,_Context->y_Auto338+190,290,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),34);
						}
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto349=visual_trigger_code(_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]));
						if (((_Context->status = visual_styled_element(_Context->x_Auto338+10,_Context->y_Auto338+190,290,20,GetWidgetStyle(2),_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]))) != 0)
) {
	visual_button(_Context->x_Auto338+10,_Context->y_Auto338+190,290,20,vfh[2],16,0,_Context->msg_Auto349[_Context->language],strlen(_Context->msg_Auto349[_Context->language]),32);
						}
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto349_event(_Context)) != -1) break;

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

public	int	database_member_menu()
{
	int	status=0;
	struct database_member_menu_context * _Context=(struct database_member_menu_context*) 0;
	status = database_member_menu_create(&_Context);
	if ( status != 0) return(status);
	status = database_member_menu_show(_Context);
		enter_modal();
	status = database_member_menu_focus(_Context);
		leave_modal();
	status = database_member_menu_hide(_Context);
	status = database_member_menu_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _membermenu_c */
