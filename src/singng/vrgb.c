
#ifndef _vrgb_c
#define _vrgb_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vrgb.xml                                                 */
/* Target         : vrgb.c                                                   */
/* Identification : 0.0-1177512079-5848.5847                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en__Window   ""
#define fr__Window   ""
#define it__Window   ""
#define es__Window   ""
#define de__Window   ""
#define nl__Window   ""
#define pt__Window   ""
#define xx__Window   ""
#define en_NewPalette   "Build New Palette"
#define fr_NewPalette   "Build New Palette"
#define it_NewPalette   "Build New Palette"
#define es_NewPalette   "Build New Palette"
#define de_NewPalette   "Build New Palette"
#define nl_NewPalette   "Build New Palette"
#define pt_NewPalette   "Build New Palette"
#define xx_NewPalette   "Build New Palette"
#define en__NewPalette   ""
#define fr__NewPalette   ""
#define it__NewPalette   ""
#define es__NewPalette   ""
#define de__NewPalette   ""
#define nl__NewPalette   ""
#define pt__NewPalette   ""
#define xx__NewPalette   ""
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"
#define en_Accept   "ok.gif"
#define fr_Accept   "ok.gif"
#define it_Accept   "ok.gif"
#define es_Accept   "ok.gif"
#define de_Accept   "ok.gif"
#define nl_Accept   "ok.gif"
#define pt_Accept   "ok.gif"
#define xx_Accept   "ok.gif"
#define en_Clip   "Apply window clipping"
#define fr_Clip   "Permettre l'‚crˆtage de la fenˆtre"
#define it_Clip   "Apply window clipping"
#define es_Clip   "Apply window clipping"
#define de_Clip   "Apply window clipping"
#define nl_Clip   "Apply window clipping"
#define pt_Clip   "Apply window clipping"
#define xx_Clip   "Apply window clipping"
#define en__Clip   ""
#define en_Auto2627   ""
#define en__Auto2627   ""
#define en_Auto2628   ""
#define en__Auto2628   ""
#define en_Auto2629   ""
#define en__Auto2629   ""
#define en_Auto2630   ""
#define en__Auto2630   ""
#define en_Auto2631   "Brightness"
#define fr_Auto2631   "Luminosit‚"
#define it_Auto2631   "Brightness"
#define es_Auto2631   "Brightness"
#define de_Auto2631   "Brightness"
#define nl_Auto2631   "Brightness"
#define pt_Auto2631   "Brightness"
#define xx_Auto2631   "Brightness"
#define en__Auto2631   ""
#define en_Auto2632   "Blue"
#define fr_Auto2632   "Bleu"
#define it_Auto2632   "Blue"
#define es_Auto2632   "Blue"
#define de_Auto2632   "Blau"
#define nl_Auto2632   "Blau"
#define pt_Auto2632   "Blue"
#define xx_Auto2632   "Blue"
#define en__Auto2632   ""
#define en_Auto2633   "Green"
#define fr_Auto2633   "Vert"
#define it_Auto2633   "Green"
#define es_Auto2633   "Green"
#define de_Auto2633   "Gr&uuml;n"
#define nl_Auto2633   "Green"
#define pt_Auto2633   "Green"
#define xx_Auto2633   "Green"
#define en__Auto2633   ""
#define en_Auto2634   "Red"
#define fr_Auto2634   "Rouge"
#define it_Auto2634   "Red"
#define es_Auto2634   "Red"
#define de_Auto2634   "Rot"
#define nl_Auto2634   "Red"
#define pt_Auto2634   "Red"
#define xx_Auto2634   "Red"
#define en__Auto2634   ""
#define en_Brightness   ""
#define en__Brightness   ""
#define en_Blue   ""
#define en__Blue   ""
#define en_Green   ""
#define en__Green   ""
#define en_Red   ""
#define en__Red   ""

private struct accept_colour_transformation_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Window[8];
	char * hint_Window[8];
	int	x_Window;
	int	y_Window;
	int	w_Window;
	int	h_Window;
	char * msg_NewPalette[8];
	int	trigger_NewPalette;
	char * hint_NewPalette[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * hint_Auto2626[8];
	char * msg_Clip[8];
	int	trigger_Clip;
	char * hint_Clip[8];
	int	value_Clip;
	char * hint_Auto2627[8];
	char	buffer_Auto2627[5];
	char * hint_Auto2628[8];
	char	buffer_Auto2628[5];
	char * hint_Auto2629[8];
	char	buffer_Auto2629[5];
	char * hint_Auto2630[8];
	char	buffer_Auto2630[5];
	char * msg_Auto2631[8];
	char * hint_Auto2631[8];
	char * msg_Auto2632[8];
	char * hint_Auto2632[8];
	char * msg_Auto2633[8];
	char * hint_Auto2633[8];
	char * msg_Auto2634[8];
	char * hint_Auto2634[8];
	char * hint_Brightness[8];
	int	value_Brightness;
	int	limit_Brightness;
	int	max_Brightness;
	char * hint_Blue[8];
	int	value_Blue;
	int	limit_Blue;
	int	max_Blue;
	char * hint_Green[8];
	int	value_Green;
	int	limit_Green;
	int	max_Green;
	char * hint_Red[8];
	int	value_Red;
	int	limit_Red;
	int	max_Red;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[16];

public	int	accept_colour_transformation_create(struct accept_colour_transformation_context **cptr)
{

	int i;
	struct accept_colour_transformation_context * _Context=(struct accept_colour_transformation_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_colour_transformation_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=13;
		_Context->value_Clip=0;
		for (i=0; i < 4; i++)  *(_Context->buffer_Auto2627+i)=' ';
		for (i=0; i < 4; i++)  *(_Context->buffer_Auto2628+i)=' ';
		for (i=0; i < 4; i++)  *(_Context->buffer_Auto2629+i)=' ';
		for (i=0; i < 4; i++)  *(_Context->buffer_Auto2630+i)=' ';
		_Context->max_Brightness=0;
		_Context->limit_Brightness=0;
		_Context->value_Brightness=0;
		_Context->max_Blue=0;
		_Context->limit_Blue=0;
		_Context->value_Blue=0;
		_Context->max_Green=0;
		_Context->limit_Green=0;
		_Context->value_Green=0;
		_Context->max_Red=0;
		_Context->limit_Red=0;
		_Context->value_Red=0;
	for (i=0; i < 8; i++)_Context->msg_Window[i]=" ";
	_Context->hint_Window[0]=en__Window;
	_Context->hint_Window[1]=fr__Window;
	_Context->hint_Window[2]=it__Window;
	_Context->hint_Window[3]=es__Window;
	_Context->hint_Window[4]=de__Window;
	_Context->hint_Window[5]=nl__Window;
	_Context->hint_Window[6]=pt__Window;
	_Context->hint_Window[7]=xx__Window;
	_Context->x_Window=160;
	_Context->y_Window=195;
	_Context->w_Window=480;
	_Context->h_Window=210;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_NewPalette[i]=" ";
	_Context->msg_NewPalette[0]=en_NewPalette;
	_Context->msg_NewPalette[1]=fr_NewPalette;
	_Context->msg_NewPalette[2]=it_NewPalette;
	_Context->msg_NewPalette[3]=es_NewPalette;
	_Context->msg_NewPalette[4]=de_NewPalette;
	_Context->msg_NewPalette[5]=nl_NewPalette;
	_Context->msg_NewPalette[6]=pt_NewPalette;
	_Context->msg_NewPalette[7]=xx_NewPalette;
	_Context->hint_NewPalette[0]=en__NewPalette;
	_Context->hint_NewPalette[1]=fr__NewPalette;
	_Context->hint_NewPalette[2]=it__NewPalette;
	_Context->hint_NewPalette[3]=es__NewPalette;
	_Context->hint_NewPalette[4]=de__NewPalette;
	_Context->hint_NewPalette[5]=nl__NewPalette;
	_Context->hint_NewPalette[6]=pt__NewPalette;
	_Context->hint_NewPalette[7]=xx__NewPalette;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->msg_Cancel[2]=it_Cancel;
	_Context->msg_Cancel[3]=es_Cancel;
	_Context->msg_Cancel[4]=de_Cancel;
	_Context->msg_Cancel[5]=nl_Cancel;
	_Context->msg_Cancel[6]=pt_Cancel;
	_Context->msg_Cancel[7]=xx_Cancel;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	for (i=0; i < 8; i++)_Context->msg_Clip[i]=" ";
	_Context->msg_Clip[0]=en_Clip;
	_Context->msg_Clip[1]=fr_Clip;
	_Context->msg_Clip[2]=it_Clip;
	_Context->msg_Clip[3]=es_Clip;
	_Context->msg_Clip[4]=de_Clip;
	_Context->msg_Clip[5]=nl_Clip;
	_Context->msg_Clip[6]=pt_Clip;
	_Context->msg_Clip[7]=xx_Clip;
	_Context->hint_Clip[0]=en__Clip;
	_Context->hint_Auto2627[0]=en__Auto2627;
	_Context->hint_Auto2628[0]=en__Auto2628;
	_Context->hint_Auto2629[0]=en__Auto2629;
	_Context->hint_Auto2630[0]=en__Auto2630;
	for (i=0; i < 8; i++)_Context->msg_Auto2631[i]=" ";
	_Context->msg_Auto2631[0]=en_Auto2631;
	_Context->msg_Auto2631[1]=fr_Auto2631;
	_Context->msg_Auto2631[2]=it_Auto2631;
	_Context->msg_Auto2631[3]=es_Auto2631;
	_Context->msg_Auto2631[4]=de_Auto2631;
	_Context->msg_Auto2631[5]=nl_Auto2631;
	_Context->msg_Auto2631[6]=pt_Auto2631;
	_Context->msg_Auto2631[7]=xx_Auto2631;
	_Context->hint_Auto2631[0]=en__Auto2631;
	for (i=0; i < 8; i++)_Context->msg_Auto2632[i]=" ";
	_Context->msg_Auto2632[0]=en_Auto2632;
	_Context->msg_Auto2632[1]=fr_Auto2632;
	_Context->msg_Auto2632[2]=it_Auto2632;
	_Context->msg_Auto2632[3]=es_Auto2632;
	_Context->msg_Auto2632[4]=de_Auto2632;
	_Context->msg_Auto2632[5]=nl_Auto2632;
	_Context->msg_Auto2632[6]=pt_Auto2632;
	_Context->msg_Auto2632[7]=xx_Auto2632;
	_Context->hint_Auto2632[0]=en__Auto2632;
	for (i=0; i < 8; i++)_Context->msg_Auto2633[i]=" ";
	_Context->msg_Auto2633[0]=en_Auto2633;
	_Context->msg_Auto2633[1]=fr_Auto2633;
	_Context->msg_Auto2633[2]=it_Auto2633;
	_Context->msg_Auto2633[3]=es_Auto2633;
	_Context->msg_Auto2633[4]=de_Auto2633;
	_Context->msg_Auto2633[5]=nl_Auto2633;
	_Context->msg_Auto2633[6]=pt_Auto2633;
	_Context->msg_Auto2633[7]=xx_Auto2633;
	_Context->hint_Auto2633[0]=en__Auto2633;
	for (i=0; i < 8; i++)_Context->msg_Auto2634[i]=" ";
	_Context->msg_Auto2634[0]=en_Auto2634;
	_Context->msg_Auto2634[1]=fr_Auto2634;
	_Context->msg_Auto2634[2]=it_Auto2634;
	_Context->msg_Auto2634[3]=es_Auto2634;
	_Context->msg_Auto2634[4]=de_Auto2634;
	_Context->msg_Auto2634[5]=nl_Auto2634;
	_Context->msg_Auto2634[6]=pt_Auto2634;
	_Context->msg_Auto2634[7]=xx_Auto2634;
	_Context->hint_Auto2634[0]=en__Auto2634;
	_Context->hint_Brightness[0]=en__Brightness;
	_Context->max_Brightness=1;
	_Context->value_Brightness=1;
	_Context->limit_Brightness=1;
	_Context->value_Brightness=256;
	_Context->limit_Brightness=10;
	_Context->max_Brightness=522;
	_Context->hint_Blue[0]=en__Blue;
	_Context->max_Blue=1;
	_Context->value_Blue=1;
	_Context->limit_Blue=1;
	_Context->value_Blue=256;
	_Context->limit_Blue=10;
	_Context->max_Blue=522;
	_Context->hint_Green[0]=en__Green;
	_Context->max_Green=1;
	_Context->value_Green=1;
	_Context->limit_Green=1;
	_Context->value_Green=256;
	_Context->limit_Green=10;
	_Context->max_Green=522;
	_Context->hint_Red[0]=en__Red;
	_Context->max_Red=1;
	_Context->value_Red=1;
	_Context->limit_Red=1;
	_Context->value_Red=256;
	_Context->limit_Red=10;
	_Context->max_Red=522;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Window,_Context->y_Window,480+10,210+10);
	return(0);
}

public 	int	accept_colour_transformation_hide(struct accept_colour_transformation_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Window,_Context->y_Window);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_colour_transformation_remove(struct accept_colour_transformation_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Auto2627_show(struct accept_colour_transformation_context * _Context) {
	sprintf(_Context->buffer_Auto2627,"%u",_Context->value_Brightness);
	visual_frame(_Context->x_Window+420,_Context->y_Window+40,32+2,16+2,5);
visual_text(_Context->x_Window+420+1,_Context->y_Window+40+1,32,16,vfh[1],27,28,_Context->buffer_Auto2627,4,0);
;
	return(-1);
}
private int on_Auto2628_show(struct accept_colour_transformation_context * _Context) {
	sprintf(_Context->buffer_Auto2628,"%u",_Context->value_Red);
	visual_frame(_Context->x_Window+420,_Context->y_Window+60,32+2,16+2,5);
visual_text(_Context->x_Window+420+1,_Context->y_Window+60+1,32,16,vfh[1],27,28,_Context->buffer_Auto2628,4,0);
;
	return(-1);
}
private int on_Auto2629_show(struct accept_colour_transformation_context * _Context) {
	sprintf(_Context->buffer_Auto2629,"%u",_Context->value_Green);
	visual_frame(_Context->x_Window+420,_Context->y_Window+80,32+2,16+2,5);
visual_text(_Context->x_Window+420+1,_Context->y_Window+80+1,32,16,vfh[1],27,28,_Context->buffer_Auto2629,4,0);
;
	return(-1);
}
private int on_Auto2630_show(struct accept_colour_transformation_context * _Context) {
	sprintf(_Context->buffer_Auto2630,"%u",_Context->value_Blue);
	visual_frame(_Context->x_Window+420,_Context->y_Window+100,32+2,16+2,5);
visual_text(_Context->x_Window+420+1,_Context->y_Window+100+1,32,16,vfh[1],27,28,_Context->buffer_Auto2630,4,0);
;
	return(-1);
}

public	int	accept_colour_transformation_show(struct accept_colour_transformation_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Window,_Context->y_Window);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Window,_Context->y_Window,480,210,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Window,_Context->y_Window,480,210,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	_Context->trigger_NewPalette=visual_trigger_code(_Context->msg_NewPalette[_Context->language],strlen(_Context->msg_NewPalette[_Context->language]));
	visual_button(_Context->x_Window+140,_Context->y_Window+160,210,32,vfh[2],27,28,_Context->msg_NewPalette[_Context->language],strlen(_Context->msg_NewPalette[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Window+404,_Context->y_Window+150,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Window+20,_Context->y_Window+150,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	visual_frame(_Context->x_Window+20,_Context->y_Window+30,440,110,2);
	_Context->trigger_Clip=visual_trigger_code(_Context->msg_Clip[_Context->language],strlen(_Context->msg_Clip[_Context->language]));
	visual_check(_Context->x_Window+110,_Context->y_Window+120,304,16,vfh[2],27,28,_Context->msg_Clip[_Context->language],strlen(_Context->msg_Clip[_Context->language]),_Context->value_Clip|0);
	(void) on_Auto2627_show(_Context);
	(void) on_Auto2628_show(_Context);
	(void) on_Auto2629_show(_Context);
	(void) on_Auto2630_show(_Context);
	visual_text(_Context->x_Window+30,_Context->y_Window+40,70,16,vfh[2],16,21,_Context->msg_Auto2631[_Context->language],strlen(_Context->msg_Auto2631[_Context->language]),257);
	visual_text(_Context->x_Window+30,_Context->y_Window+100,70,16,vfh[2],16,21,_Context->msg_Auto2632[_Context->language],strlen(_Context->msg_Auto2632[_Context->language]),257);
	visual_text(_Context->x_Window+30,_Context->y_Window+80,70,16,vfh[2],16,21,_Context->msg_Auto2633[_Context->language],strlen(_Context->msg_Auto2633[_Context->language]),257);
	visual_text(_Context->x_Window+30,_Context->y_Window+60,70,16,vfh[2],16,21,_Context->msg_Auto2634[_Context->language],strlen(_Context->msg_Auto2634[_Context->language]),257);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+40,310,20,vfh[1],27,28,_Context->value_Brightness,_Context->limit_Brightness,_Context->max_Brightness,259);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+100,310,20,vfh[1],27,28,_Context->value_Blue,_Context->limit_Blue,_Context->max_Blue,259);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+80,310,20,vfh[1],27,28,_Context->value_Green,_Context->limit_Green,_Context->max_Green,259);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+60,310,20,vfh[1],27,28,_Context->value_Red,_Context->limit_Red,_Context->max_Red,259);
	visual_thaw(_Context->x_Window,_Context->y_Window,480,210);

	return(0);
}

private int Cancel_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the CANCEL button any modifications performed will be ";
			mptr[1]="   discarded.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Accept_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the ACCEPT button any changes made to the various    parameters ";
			mptr[1]="will take effect.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Windowaction(struct accept_colour_transformation_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_colour_transformation_hide(_Context);

		_Context->x_Window += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Window < 0) { _Context->x_Window=0; }
		_Context->y_Window += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Window < 0) { _Context->y_Window=0; }
			accept_colour_transformation_show(_Context);

		visual_thaw(_Context->x_Window,_Context->y_Window,480,210);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_NewPalette_event(struct accept_colour_transformation_context * _Context) {
	char*newfilename=(char*)0;
	int paintflag=0;
	int ihmflag=1;
	int otherflag=0;
	int options=0;
	if(accept_palette_name(&newfilename,&paintflag,&ihmflag,&otherflag)!=27){
	if(paintflag)options|=1;
	if(ihmflag)options|=2;
	if(otherflag)options|=4;
	sing_build_palette(newfilename,options);
	liberate(newfilename);
	}
	return(-1);
}
private int on_Cancel_event(struct accept_colour_transformation_context * _Context) {
	return(27);
	return(-1);
}
private int on_Accept_event(struct accept_colour_transformation_context * _Context) {
	return(13);
	return(-1);
}
private int on_Brightness_event(struct accept_colour_transformation_context * _Context) {
	visual_freeze();
		accept_colour_transformation_hide(_Context);
;
	sing_light_transformation(_Context->value_Brightness,_Context->value_Clip);
		accept_colour_transformation_show(_Context);
;
	visual_thaw(_Context->x_Window,_Context->y_Window,480+10,210+10);
	return(-1);
}

private int on_Brightness_action(struct accept_colour_transformation_context * _Context) {
	int status;
	int atx=visual_event(7);
	int tox=visual_event(7);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }

	if ( visual_event(7) < (_Context->x_Window+110+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Brightness -= 1;
		if (_Context->value_Brightness < 0) 
			_Context->value_Brightness = 0;
		(void) on_Brightness_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+40,310,20,vfh[1],27,28,_Context->value_Brightness,_Context->limit_Brightness,_Context->max_Brightness,259);
		return(-1);
		}
	if ( visual_event(7) > (_Context->x_Window+110+310-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Brightness += 1;
		if (!(_Context->max_Brightness))
			_Context->value_Brightness = 0;
		else if ((_Context->max_Brightness < _Context->limit_Brightness) 
		&& (_Context->value_Brightness >= _Context->max_Brightness)) 
			_Context->value_Brightness = (_Context->max_Brightness-1);
		else if (_Context->value_Brightness > (_Context->max_Brightness-_Context->limit_Brightness)) 
			_Context->value_Brightness = (_Context->max_Brightness-_Context->limit_Brightness);
		(void) on_Brightness_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+40,310,20,vfh[1],27,28,_Context->value_Brightness,_Context->limit_Brightness,_Context->max_Brightness,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+40,310,20,vfh[1],27,28,_Context->value_Brightness,_Context->limit_Brightness,_Context->max_Brightness,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		atx = _Context->value_Brightness;
		_Context->value_Brightness = (((visual_event(7) - (_Context->x_Window+110+20)) * _Context->max_Brightness) / (310 - (2 * 20)));
		if (_Context->value_Brightness < 0) 
			_Context->value_Brightness = 0;
		else if (_Context->value_Brightness > (_Context->max_Brightness-_Context->limit_Brightness)) 
			_Context->value_Brightness = (_Context->max_Brightness-_Context->limit_Brightness);
		if (_Context->value_Brightness != atx) {
		(void) on_Brightness_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+40,310,20,vfh[1],27,28,_Context->value_Brightness,_Context->limit_Brightness,_Context->max_Brightness,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_Brightness -= (_Context->limit_Brightness/2);
			if (_Context->value_Brightness < 0) 
				_Context->value_Brightness = 0;
		(void) on_Brightness_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+40,310,20,vfh[1],27,28,_Context->value_Brightness,_Context->limit_Brightness,_Context->max_Brightness,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_Brightness += (_Context->limit_Brightness/2);
			if (!(_Context->max_Brightness))
				_Context->value_Brightness = 0;
			else if ((_Context->max_Brightness < _Context->limit_Brightness) 
			&& (_Context->value_Brightness >= _Context->max_Brightness)) 
				_Context->value_Brightness = (_Context->max_Brightness-1);
			else if (_Context->value_Brightness > (_Context->max_Brightness-_Context->limit_Brightness)) 
				_Context->value_Brightness = (_Context->max_Brightness-_Context->limit_Brightness);
		(void) on_Brightness_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+40,310,20,vfh[1],27,28,_Context->value_Brightness,_Context->limit_Brightness,_Context->max_Brightness,259);
			break;
		}
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+40,310,20,vfh[1],27,28,_Context->value_Brightness,_Context->limit_Brightness,_Context->max_Brightness,259);

	return(1);
}
private int on_Blue_event(struct accept_colour_transformation_context * _Context) {
	visual_freeze();
		accept_colour_transformation_hide(_Context);
;
	sing_blue_transformation(_Context->value_Blue,_Context->value_Clip);
		accept_colour_transformation_show(_Context);
;
	visual_thaw(_Context->x_Window,_Context->y_Window,480+10,210+10);
	return(-1);
}

private int on_Blue_action(struct accept_colour_transformation_context * _Context) {
	int status;
	int atx=visual_event(7);
	int tox=visual_event(7);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }

	if ( visual_event(7) < (_Context->x_Window+110+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Blue -= 1;
		if (_Context->value_Blue < 0) 
			_Context->value_Blue = 0;
		(void) on_Blue_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+100,310,20,vfh[1],27,28,_Context->value_Blue,_Context->limit_Blue,_Context->max_Blue,259);
		return(-1);
		}
	if ( visual_event(7) > (_Context->x_Window+110+310-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Blue += 1;
		if (!(_Context->max_Blue))
			_Context->value_Blue = 0;
		else if ((_Context->max_Blue < _Context->limit_Blue) 
		&& (_Context->value_Blue >= _Context->max_Blue)) 
			_Context->value_Blue = (_Context->max_Blue-1);
		else if (_Context->value_Blue > (_Context->max_Blue-_Context->limit_Blue)) 
			_Context->value_Blue = (_Context->max_Blue-_Context->limit_Blue);
		(void) on_Blue_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+100,310,20,vfh[1],27,28,_Context->value_Blue,_Context->limit_Blue,_Context->max_Blue,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+100,310,20,vfh[1],27,28,_Context->value_Blue,_Context->limit_Blue,_Context->max_Blue,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		atx = _Context->value_Blue;
		_Context->value_Blue = (((visual_event(7) - (_Context->x_Window+110+20)) * _Context->max_Blue) / (310 - (2 * 20)));
		if (_Context->value_Blue < 0) 
			_Context->value_Blue = 0;
		else if (_Context->value_Blue > (_Context->max_Blue-_Context->limit_Blue)) 
			_Context->value_Blue = (_Context->max_Blue-_Context->limit_Blue);
		if (_Context->value_Blue != atx) {
		(void) on_Blue_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+100,310,20,vfh[1],27,28,_Context->value_Blue,_Context->limit_Blue,_Context->max_Blue,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_Blue -= (_Context->limit_Blue/2);
			if (_Context->value_Blue < 0) 
				_Context->value_Blue = 0;
		(void) on_Blue_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+100,310,20,vfh[1],27,28,_Context->value_Blue,_Context->limit_Blue,_Context->max_Blue,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_Blue += (_Context->limit_Blue/2);
			if (!(_Context->max_Blue))
				_Context->value_Blue = 0;
			else if ((_Context->max_Blue < _Context->limit_Blue) 
			&& (_Context->value_Blue >= _Context->max_Blue)) 
				_Context->value_Blue = (_Context->max_Blue-1);
			else if (_Context->value_Blue > (_Context->max_Blue-_Context->limit_Blue)) 
				_Context->value_Blue = (_Context->max_Blue-_Context->limit_Blue);
		(void) on_Blue_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+100,310,20,vfh[1],27,28,_Context->value_Blue,_Context->limit_Blue,_Context->max_Blue,259);
			break;
		}
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+100,310,20,vfh[1],27,28,_Context->value_Blue,_Context->limit_Blue,_Context->max_Blue,259);

	return(1);
}
private int on_Green_event(struct accept_colour_transformation_context * _Context) {
	visual_freeze();
		accept_colour_transformation_hide(_Context);
;
	sing_green_transformation(_Context->value_Green,_Context->value_Clip);
		accept_colour_transformation_show(_Context);
;
	visual_thaw(_Context->x_Window,_Context->y_Window,480+10,210+10);
	return(-1);
}

private int on_Green_action(struct accept_colour_transformation_context * _Context) {
	int status;
	int atx=visual_event(7);
	int tox=visual_event(7);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }

	if ( visual_event(7) < (_Context->x_Window+110+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Green -= 1;
		if (_Context->value_Green < 0) 
			_Context->value_Green = 0;
		(void) on_Green_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+80,310,20,vfh[1],27,28,_Context->value_Green,_Context->limit_Green,_Context->max_Green,259);
		return(-1);
		}
	if ( visual_event(7) > (_Context->x_Window+110+310-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Green += 1;
		if (!(_Context->max_Green))
			_Context->value_Green = 0;
		else if ((_Context->max_Green < _Context->limit_Green) 
		&& (_Context->value_Green >= _Context->max_Green)) 
			_Context->value_Green = (_Context->max_Green-1);
		else if (_Context->value_Green > (_Context->max_Green-_Context->limit_Green)) 
			_Context->value_Green = (_Context->max_Green-_Context->limit_Green);
		(void) on_Green_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+80,310,20,vfh[1],27,28,_Context->value_Green,_Context->limit_Green,_Context->max_Green,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+80,310,20,vfh[1],27,28,_Context->value_Green,_Context->limit_Green,_Context->max_Green,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		atx = _Context->value_Green;
		_Context->value_Green = (((visual_event(7) - (_Context->x_Window+110+20)) * _Context->max_Green) / (310 - (2 * 20)));
		if (_Context->value_Green < 0) 
			_Context->value_Green = 0;
		else if (_Context->value_Green > (_Context->max_Green-_Context->limit_Green)) 
			_Context->value_Green = (_Context->max_Green-_Context->limit_Green);
		if (_Context->value_Green != atx) {
		(void) on_Green_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+80,310,20,vfh[1],27,28,_Context->value_Green,_Context->limit_Green,_Context->max_Green,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_Green -= (_Context->limit_Green/2);
			if (_Context->value_Green < 0) 
				_Context->value_Green = 0;
		(void) on_Green_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+80,310,20,vfh[1],27,28,_Context->value_Green,_Context->limit_Green,_Context->max_Green,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_Green += (_Context->limit_Green/2);
			if (!(_Context->max_Green))
				_Context->value_Green = 0;
			else if ((_Context->max_Green < _Context->limit_Green) 
			&& (_Context->value_Green >= _Context->max_Green)) 
				_Context->value_Green = (_Context->max_Green-1);
			else if (_Context->value_Green > (_Context->max_Green-_Context->limit_Green)) 
				_Context->value_Green = (_Context->max_Green-_Context->limit_Green);
		(void) on_Green_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+80,310,20,vfh[1],27,28,_Context->value_Green,_Context->limit_Green,_Context->max_Green,259);
			break;
		}
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+80,310,20,vfh[1],27,28,_Context->value_Green,_Context->limit_Green,_Context->max_Green,259);

	return(1);
}
private int on_Red_event(struct accept_colour_transformation_context * _Context) {
	visual_freeze();
		accept_colour_transformation_hide(_Context);
;
	sing_red_transformation(_Context->value_Red,_Context->value_Clip);
		accept_colour_transformation_show(_Context);
;
	visual_thaw(_Context->x_Window,_Context->y_Window,480+10,210+10);
	return(-1);
}

private int on_Red_action(struct accept_colour_transformation_context * _Context) {
	int status;
	int atx=visual_event(7);
	int tox=visual_event(7);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }

	if ( visual_event(7) < (_Context->x_Window+110+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Red -= 1;
		if (_Context->value_Red < 0) 
			_Context->value_Red = 0;
		(void) on_Red_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+60,310,20,vfh[1],27,28,_Context->value_Red,_Context->limit_Red,_Context->max_Red,259);
		return(-1);
		}
	if ( visual_event(7) > (_Context->x_Window+110+310-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_Red += 1;
		if (!(_Context->max_Red))
			_Context->value_Red = 0;
		else if ((_Context->max_Red < _Context->limit_Red) 
		&& (_Context->value_Red >= _Context->max_Red)) 
			_Context->value_Red = (_Context->max_Red-1);
		else if (_Context->value_Red > (_Context->max_Red-_Context->limit_Red)) 
			_Context->value_Red = (_Context->max_Red-_Context->limit_Red);
		(void) on_Red_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+60,310,20,vfh[1],27,28,_Context->value_Red,_Context->limit_Red,_Context->max_Red,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+60,310,20,vfh[1],27,28,_Context->value_Red,_Context->limit_Red,_Context->max_Red,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		atx = _Context->value_Red;
		_Context->value_Red = (((visual_event(7) - (_Context->x_Window+110+20)) * _Context->max_Red) / (310 - (2 * 20)));
		if (_Context->value_Red < 0) 
			_Context->value_Red = 0;
		else if (_Context->value_Red > (_Context->max_Red-_Context->limit_Red)) 
			_Context->value_Red = (_Context->max_Red-_Context->limit_Red);
		if (_Context->value_Red != atx) {
		(void) on_Red_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+60,310,20,vfh[1],27,28,_Context->value_Red,_Context->limit_Red,_Context->max_Red,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_Red -= (_Context->limit_Red/2);
			if (_Context->value_Red < 0) 
				_Context->value_Red = 0;
		(void) on_Red_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+60,310,20,vfh[1],27,28,_Context->value_Red,_Context->limit_Red,_Context->max_Red,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_Red += (_Context->limit_Red/2);
			if (!(_Context->max_Red))
				_Context->value_Red = 0;
			else if ((_Context->max_Red < _Context->limit_Red) 
			&& (_Context->value_Red >= _Context->max_Red)) 
				_Context->value_Red = (_Context->max_Red-1);
			else if (_Context->value_Red > (_Context->max_Red-_Context->limit_Red)) 
				_Context->value_Red = (_Context->max_Red-_Context->limit_Red);
		(void) on_Red_event(_Context);
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+60,310,20,vfh[1],27,28,_Context->value_Red,_Context->limit_Red,_Context->max_Red,259);
			break;
		}
	visual_scrollbar(_Context->x_Window+110,_Context->y_Window+60,310,20,vfh[1],27,28,_Context->value_Red,_Context->limit_Red,_Context->max_Red,259);

	return(1);
}


public	int	accept_colour_transformation_event(
struct accept_colour_transformation_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_NewPalette == mb ) return(2);
		if (_Context->trigger_Cancel == mb ) return(3);
		if (_Context->trigger_Accept == mb ) return(4);
		if (_Context->trigger_Clip == mb ) return(5);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Window+459) )  
	&&  (my >= (_Context->y_Window+4) )  
	&&  (mx <= (_Context->x_Window+476) )  
	&&  (my <= (_Context->y_Window+20) )) {
		return(1);	/* Window */

		}
	if ((mx >= (_Context->x_Window+443) )  
	&&  (my >= (_Context->y_Window+4) )  
	&&  (mx <= (_Context->x_Window+460) )  
	&&  (my <= (_Context->y_Window+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vrgb.htm");
			};
		return(-1);	/* Window */

		}
	if ((mx >= (_Context->x_Window+427) )  
	&&  (my >= (_Context->y_Window+4) )  
	&&  (mx <= (_Context->x_Window+444) )  
	&&  (my <= (_Context->y_Window+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_colour_transformation_show(_Context);
		return(-1);	/* Window */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Window+4) )  
		&&  (my >= (_Context->y_Window+4) )  
		&&  (mx <= (_Context->x_Window+412) )  
		&&  (my <= (_Context->y_Window+20) )) {
			return( Windowaction(_Context) );
			}
		}
	if (( mx >= (_Context->x_Window+140) ) 
	&&  ( my >= (_Context->y_Window+160) ) 
	&&  ( mx <= (_Context->x_Window+140+210) ) 
	&&  ( my <= (_Context->y_Window+160+32))) {
		return(2); /* NewPalette */
		}
	if (( mx >= (_Context->x_Window+404) ) 
	&&  ( my >= (_Context->y_Window+150) ) 
	&&  ( mx <= (_Context->x_Window+404+56) ) 
	&&  ( my <= (_Context->y_Window+150+48))) {
		return(3); /* Cancel */
		}
	if (( mx >= (_Context->x_Window+20) ) 
	&&  ( my >= (_Context->y_Window+150) ) 
	&&  ( mx <= (_Context->x_Window+20+56) ) 
	&&  ( my <= (_Context->y_Window+150+48))) {
		return(4); /* Accept */
		}
	if (( mx >= (_Context->x_Window+110) ) 
	&&  ( my >= (_Context->y_Window+120) ) 
	&&  ( mx <= (_Context->x_Window+110+304) ) 
	&&  ( my <= (_Context->y_Window+120+16))) {
		return(5); /* Clip */
		}
	if (( mx >= (_Context->x_Window+420) ) 
	&&  ( my >= (_Context->y_Window+40) ) 
	&&  ( mx <= (_Context->x_Window+420+32) ) 
	&&  ( my <= (_Context->y_Window+40+16))) {
		return(6); /* Auto2627 */
		}
	if (( mx >= (_Context->x_Window+420) ) 
	&&  ( my >= (_Context->y_Window+60) ) 
	&&  ( mx <= (_Context->x_Window+420+32) ) 
	&&  ( my <= (_Context->y_Window+60+16))) {
		return(7); /* Auto2628 */
		}
	if (( mx >= (_Context->x_Window+420) ) 
	&&  ( my >= (_Context->y_Window+80) ) 
	&&  ( mx <= (_Context->x_Window+420+32) ) 
	&&  ( my <= (_Context->y_Window+80+16))) {
		return(8); /* Auto2629 */
		}
	if (( mx >= (_Context->x_Window+420) ) 
	&&  ( my >= (_Context->y_Window+100) ) 
	&&  ( mx <= (_Context->x_Window+420+32) ) 
	&&  ( my <= (_Context->y_Window+100+16))) {
		return(9); /* Auto2630 */
		}
	if (( mx >= (_Context->x_Window+110) ) 
	&&  ( my >= (_Context->y_Window+40) ) 
	&&  ( mx <= (_Context->x_Window+110+310) ) 
	&&  ( my <= (_Context->y_Window+40+20))) {
		return(10); /* Brightness */
		}
	if (( mx >= (_Context->x_Window+110) ) 
	&&  ( my >= (_Context->y_Window+100) ) 
	&&  ( mx <= (_Context->x_Window+110+310) ) 
	&&  ( my <= (_Context->y_Window+100+20))) {
		return(11); /* Blue */
		}
	if (( mx >= (_Context->x_Window+110) ) 
	&&  ( my >= (_Context->y_Window+80) ) 
	&&  ( mx <= (_Context->x_Window+110+310) ) 
	&&  ( my <= (_Context->y_Window+80+20))) {
		return(12); /* Green */
		}
	if (( mx >= (_Context->x_Window+110) ) 
	&&  ( my >= (_Context->y_Window+60) ) 
	&&  ( mx <= (_Context->x_Window+110+310) ) 
	&&  ( my <= (_Context->y_Window+60+20))) {
		return(13); /* Red */
		}

	return(-1);
}


public	int	accept_colour_transformation_focus(struct accept_colour_transformation_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* NewPalette */
				_Context->trigger_NewPalette=visual_trigger_code(_Context->msg_NewPalette[_Context->language],strlen(_Context->msg_NewPalette[_Context->language]));
				visual_button(_Context->x_Window+140,_Context->y_Window+160,210,32,vfh[2],27,28,_Context->msg_NewPalette[_Context->language],strlen(_Context->msg_NewPalette[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_NewPalette=visual_trigger_code(_Context->msg_NewPalette[_Context->language],strlen(_Context->msg_NewPalette[_Context->language]));
	visual_button(_Context->x_Window+140,_Context->y_Window+160,210,32,vfh[2],27,28,_Context->msg_NewPalette[_Context->language],strlen(_Context->msg_NewPalette[_Context->language]),0);
				break;
			case	0x3 :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_Window+404,_Context->y_Window+150,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Window+404,_Context->y_Window+150,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;
			case	0x4 :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(_Context->x_Window+20,_Context->y_Window+150,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Window+20,_Context->y_Window+150,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0x5 :
				/* Clip */
				visual_check(_Context->x_Window+110,_Context->y_Window+120,304,16,vfh[2],27,28,_Context->msg_Clip[_Context->language],strlen(_Context->msg_Clip[_Context->language]),(_Context->value_Clip |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Clip=visual_trigger_code(_Context->msg_Clip[_Context->language],strlen(_Context->msg_Clip[_Context->language]));
	visual_check(_Context->x_Window+110,_Context->y_Window+120,304,16,vfh[2],27,28,_Context->msg_Clip[_Context->language],strlen(_Context->msg_Clip[_Context->language]),_Context->value_Clip|0);
				break;
			case	0xa :
				/* Brightness */
				_Context->keycode=visual_getch();
				break;
			case	0xb :
				/* Blue */
				_Context->keycode=visual_getch();
				break;
			case	0xc :
				/* Green */
				_Context->keycode=visual_getch();
				break;
			case	0xd :
				/* Red */
				_Context->keycode=visual_getch();
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_colour_transformation_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=13;
			accept_colour_transformation_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_colour_transformation_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x3 :
						if (Cancel_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Accept_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Window */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* NewPalette */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_NewPalette=visual_trigger_code(_Context->msg_NewPalette[_Context->language],strlen(_Context->msg_NewPalette[_Context->language]));
						visual_button(_Context->x_Window+140,_Context->y_Window+160,210,32,vfh[2],27,28,_Context->msg_NewPalette[_Context->language],strlen(_Context->msg_NewPalette[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_NewPalette=visual_trigger_code(_Context->msg_NewPalette[_Context->language],strlen(_Context->msg_NewPalette[_Context->language]));
	visual_button(_Context->x_Window+140,_Context->y_Window+160,210,32,vfh[2],27,28,_Context->msg_NewPalette[_Context->language],strlen(_Context->msg_NewPalette[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_NewPalette_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Window+404,_Context->y_Window+150,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Window+404,_Context->y_Window+150,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_Window+20,_Context->y_Window+150,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Window+20,_Context->y_Window+150,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Clip */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Clip += 1;
						_Context->value_Clip &= 1;
						}
					continue;
				case	0x6 :
					/* Auto2627 */
					continue;
				case	0x7 :
					/* Auto2628 */
					continue;
				case	0x8 :
					/* Auto2629 */
					continue;
				case	0x9 :
					/* Auto2630 */
					continue;
				case	0xa :
					/* Brightness */
					(void) on_Brightness_action(_Context);
					continue;
				case	0xb :
					/* Blue */
					(void) on_Blue_action(_Context);
					continue;
				case	0xc :
					/* Green */
					(void) on_Green_action(_Context);
					continue;
				case	0xd :
					/* Red */
					(void) on_Red_action(_Context);
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
				_Context->focus_item=13;
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

public	int	accept_colour_transformation()
{
	int	status=0;
	struct accept_colour_transformation_context * _Context=(struct accept_colour_transformation_context*) 0;
	status = accept_colour_transformation_create(&_Context);
	if ( status != 0) return(status);
	status = accept_colour_transformation_show(_Context);
		enter_modal();
	status = accept_colour_transformation_focus(_Context);
		leave_modal();
	status = accept_colour_transformation_hide(_Context);
	status = accept_colour_transformation_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vrgb_c */
