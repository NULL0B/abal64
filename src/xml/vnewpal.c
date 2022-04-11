
#ifndef _vnewpal_c
#define _vnewpal_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vnewpal.xml                                              */
/* Target         : vnewpal.c                                                */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Auto3625   "Sing : Version 1.0a"
#define en__Auto3625   ""
#define en_Accept   "ok.gif"
#define fr_Accept   "ok.gif"
#define it_Accept   "ok.gif"
#define es_Accept   "ok.gif"
#define de_Accept   "ok.gif"
#define nl_Accept   "ok.gif"
#define pt_Accept   "ok.gif"
#define xx_Accept   "ok.gif"
#define en__Accept   ""
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"
#define en__Cancel   ""
#define en_Auto3626   "Recalculate current palette and save to filename"
#define fr_Auto3626   "Recalculate current palette and save to filename"
#define it_Auto3626   "Recalculate current palette and save to filename"
#define es_Auto3626   "Recalculate current palette and save to filename"
#define de_Auto3626   "Recalculate current palette and save to filename"
#define nl_Auto3626   "Recalculate current palette and save to filename"
#define pt_Auto3626   "Recalculate current palette and save to filename"
#define xx_Auto3626   "Recalculate current palette and save to filename"
#define en__Auto3626   ""
#define fr__Auto3626   ""
#define it__Auto3626   ""
#define es__Auto3626   ""
#define de__Auto3626   ""
#define nl__Auto3626   ""
#define pt__Auto3626   ""
#define xx__Auto3626   ""
#define en_PaletteName   ""
#define en__PaletteName   ""
#define en_PaintColours   "Abal &PAINT colours ( 0 to 15 )"
#define fr_PaintColours   "Abal &PAINT colours ( 0 to 15 )"
#define it_PaintColours   "Abal &PAINT colours ( 0 to 15 )"
#define es_PaintColours   "Abal &PAINT colours ( 0 to 15 )"
#define de_PaintColours   "Abal &PAINT colours ( 0 to 15 )"
#define nl_PaintColours   "Abal &PAINT colours ( 0 to 15 )"
#define pt_PaintColours   "Abal &PAINT colours ( 0 to 15 )"
#define xx_PaintColours   "Abal &PAINT colours ( 0 to 15 )"
#define en__PaintColours   ""
#define fr__PaintColours   ""
#define it__PaintColours   ""
#define es__PaintColours   ""
#define de__PaintColours   ""
#define nl__PaintColours   ""
#define pt__PaintColours   ""
#define xx__PaintColours   ""
#define en_IhmColours   "Abal &IHM colours ( 16 to 23 )"
#define fr_IhmColours   "Abal &IHM colours ( 16 to 32 )"
#define it_IhmColours   "Abal &IHM colours ( 16 to 32 )"
#define es_IhmColours   "Abal &IHM colours ( 16 to 32 )"
#define de_IhmColours   "Abal &IHM colours ( 16 to 32 )"
#define nl_IhmColours   "Abal &IHM colours ( 16 to 32 )"
#define pt_IhmColours   "Abal &IHM colours ( 16 to 32 )"
#define xx_IhmColours   "Abal &IHM colours ( 16 to 32 )"
#define en__IhmColours   ""
#define fr__IhmColours   ""
#define it__IhmColours   ""
#define es__IhmColours   ""
#define de__IhmColours   ""
#define nl__IhmColours   ""
#define pt__IhmColours   ""
#define xx__IhmColours   ""
#define en_OtherColours   "&Other colours ( 24 to 255 )"
#define fr_OtherColours   "&Other colours ( 32 to 255 )"
#define it_OtherColours   "&Other colours ( 32 to 255 )"
#define es_OtherColours   "&Other colours ( 32 to 255 )"
#define de_OtherColours   "&Other colours ( 32 to 255 )"
#define nl_OtherColours   "&Other colours ( 32 to 255 )"
#define pt_OtherColours   "&Other colours ( 32 to 255 )"
#define xx_OtherColours   "&Other colours ( 32 to 255 )"
#define en__OtherColours   ""
#define fr__OtherColours   ""
#define it__OtherColours   ""
#define es__OtherColours   ""
#define de__OtherColours   ""
#define nl__OtherColours   ""
#define pt__OtherColours   ""
#define xx__OtherColours   ""
#define en_Choixfconf   "..."
#define fr_Choixfconf   "..."
#define it_Choixfconf   "..."
#define es_Choixfconf   "..."
#define de_Choixfconf   "..."
#define nl_Choixfconf   "..."
#define pt_Choixfconf   "..."
#define xx_Choixfconf   "..."
#define en__Choixfconf   ""

private struct accept_palette_name_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3625[8];
	char * hint_Auto3625[8];
	int	x_Auto3625;
	int	y_Auto3625;
	int	w_Auto3625;
	int	h_Auto3625;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	char * msg_Auto3626[8];
	char * hint_Auto3626[8];
	char * hint_PaletteName[8];
	char	buffer_PaletteName[63];
	char * msg_PaintColours[8];
	int	trigger_PaintColours;
	char * hint_PaintColours[8];
	int	value_PaintColours;
	char * msg_IhmColours[8];
	int	trigger_IhmColours;
	char * hint_IhmColours[8];
	int	value_IhmColours;
	char * msg_OtherColours[8];
	int	trigger_OtherColours;
	char * hint_OtherColours[8];
	int	value_OtherColours;
	char * msg_Choixfconf[8];
	int	trigger_Choixfconf;
	char * hint_Choixfconf[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[5];
	};
static int	vfh[16];
private int on_Accept_event(struct accept_palette_name_context * _Context);
private int on_Cancel_event(struct accept_palette_name_context * _Context);
private int on_Choixfconf_event(struct accept_palette_name_context * _Context);

public	int	accept_palette_name_create(
	struct accept_palette_name_context ** cptr,
	char * pPaletteName,
	char * pPaintColours,
	char * pIhmColours,
	char * pOtherColours)
{

	int i;
	struct accept_palette_name_context * _Context=(struct accept_palette_name_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("bmap0414.fmf",12);
	if (!(_Context = allocate( sizeof( struct accept_palette_name_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=8;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_PaletteName, 62, pPaletteName);
		visual_transferin((void *) 0, 0, pPaintColours);
		if (!( pPaintColours )) _Context->value_PaintColours=0;
		else	_Context->value_PaintColours = *((int *)pPaintColours);
		visual_transferin((void *) 0, 0, pIhmColours);
		if (!( pIhmColours )) _Context->value_IhmColours=0;
		else	_Context->value_IhmColours = *((int *)pIhmColours);
		visual_transferin((void *) 0, 0, pOtherColours);
		if (!( pOtherColours )) _Context->value_OtherColours=0;
		else	_Context->value_OtherColours = *((int *)pOtherColours);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3625[i]=" ";
	_Context->msg_Auto3625[0]=en_Auto3625;
	_Context->hint_Auto3625[0]=en__Auto3625;
	_Context->x_Auto3625=115;
	_Context->y_Auto3625=200;
	_Context->w_Auto3625=570;
	_Context->h_Auto3625=200;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	_Context->hint_Accept[0]=en__Accept;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3626[i]=" ";
	_Context->msg_Auto3626[0]=en_Auto3626;
	_Context->msg_Auto3626[1]=fr_Auto3626;
	_Context->msg_Auto3626[2]=it_Auto3626;
	_Context->msg_Auto3626[3]=es_Auto3626;
	_Context->msg_Auto3626[4]=de_Auto3626;
	_Context->msg_Auto3626[5]=nl_Auto3626;
	_Context->msg_Auto3626[6]=pt_Auto3626;
	_Context->msg_Auto3626[7]=xx_Auto3626;
	_Context->hint_Auto3626[0]=en__Auto3626;
	_Context->hint_Auto3626[1]=fr__Auto3626;
	_Context->hint_Auto3626[2]=it__Auto3626;
	_Context->hint_Auto3626[3]=es__Auto3626;
	_Context->hint_Auto3626[4]=de__Auto3626;
	_Context->hint_Auto3626[5]=nl__Auto3626;
	_Context->hint_Auto3626[6]=pt__Auto3626;
	_Context->hint_Auto3626[7]=xx__Auto3626;
	_Context->hint_PaletteName[0]=en__PaletteName;
	for (i=0; i < 8; i++)_Context->msg_PaintColours[i]=" ";
	_Context->msg_PaintColours[0]=en_PaintColours;
	_Context->msg_PaintColours[1]=fr_PaintColours;
	_Context->msg_PaintColours[2]=it_PaintColours;
	_Context->msg_PaintColours[3]=es_PaintColours;
	_Context->msg_PaintColours[4]=de_PaintColours;
	_Context->msg_PaintColours[5]=nl_PaintColours;
	_Context->msg_PaintColours[6]=pt_PaintColours;
	_Context->msg_PaintColours[7]=xx_PaintColours;
	_Context->hint_PaintColours[0]=en__PaintColours;
	_Context->hint_PaintColours[1]=fr__PaintColours;
	_Context->hint_PaintColours[2]=it__PaintColours;
	_Context->hint_PaintColours[3]=es__PaintColours;
	_Context->hint_PaintColours[4]=de__PaintColours;
	_Context->hint_PaintColours[5]=nl__PaintColours;
	_Context->hint_PaintColours[6]=pt__PaintColours;
	_Context->hint_PaintColours[7]=xx__PaintColours;
	for (i=0; i < 8; i++)_Context->msg_IhmColours[i]=" ";
	_Context->msg_IhmColours[0]=en_IhmColours;
	_Context->msg_IhmColours[1]=fr_IhmColours;
	_Context->msg_IhmColours[2]=it_IhmColours;
	_Context->msg_IhmColours[3]=es_IhmColours;
	_Context->msg_IhmColours[4]=de_IhmColours;
	_Context->msg_IhmColours[5]=nl_IhmColours;
	_Context->msg_IhmColours[6]=pt_IhmColours;
	_Context->msg_IhmColours[7]=xx_IhmColours;
	_Context->hint_IhmColours[0]=en__IhmColours;
	_Context->hint_IhmColours[1]=fr__IhmColours;
	_Context->hint_IhmColours[2]=it__IhmColours;
	_Context->hint_IhmColours[3]=es__IhmColours;
	_Context->hint_IhmColours[4]=de__IhmColours;
	_Context->hint_IhmColours[5]=nl__IhmColours;
	_Context->hint_IhmColours[6]=pt__IhmColours;
	_Context->hint_IhmColours[7]=xx__IhmColours;
	for (i=0; i < 8; i++)_Context->msg_OtherColours[i]=" ";
	_Context->msg_OtherColours[0]=en_OtherColours;
	_Context->msg_OtherColours[1]=fr_OtherColours;
	_Context->msg_OtherColours[2]=it_OtherColours;
	_Context->msg_OtherColours[3]=es_OtherColours;
	_Context->msg_OtherColours[4]=de_OtherColours;
	_Context->msg_OtherColours[5]=nl_OtherColours;
	_Context->msg_OtherColours[6]=pt_OtherColours;
	_Context->msg_OtherColours[7]=xx_OtherColours;
	_Context->hint_OtherColours[0]=en__OtherColours;
	_Context->hint_OtherColours[1]=fr__OtherColours;
	_Context->hint_OtherColours[2]=it__OtherColours;
	_Context->hint_OtherColours[3]=es__OtherColours;
	_Context->hint_OtherColours[4]=de__OtherColours;
	_Context->hint_OtherColours[5]=nl__OtherColours;
	_Context->hint_OtherColours[6]=pt__OtherColours;
	_Context->hint_OtherColours[7]=xx__OtherColours;
	for (i=0; i < 8; i++)_Context->msg_Choixfconf[i]=" ";
	_Context->msg_Choixfconf[0]=en_Choixfconf;
	_Context->msg_Choixfconf[1]=fr_Choixfconf;
	_Context->msg_Choixfconf[2]=it_Choixfconf;
	_Context->msg_Choixfconf[3]=es_Choixfconf;
	_Context->msg_Choixfconf[4]=de_Choixfconf;
	_Context->msg_Choixfconf[5]=nl_Choixfconf;
	_Context->msg_Choixfconf[6]=pt_Choixfconf;
	_Context->msg_Choixfconf[7]=xx_Choixfconf;
	_Context->hint_Choixfconf[0]=en__Choixfconf;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3625,_Context->y_Auto3625,570+10,200+10);
	return(0);
}

public 	int	accept_palette_name_hide(struct accept_palette_name_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3625,_Context->y_Auto3625);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_palette_name_remove(
	struct accept_palette_name_context * _Context,
	char * pPaletteName,
	char * pPaintColours,
	char * pIhmColours,
	char * pOtherColours)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_PaletteName, 62, pPaletteName);
		visual_transferout((void *) 0, 0, pPaintColours);
		if ( pPaintColours != (char *) 0)
			*((int*)pPaintColours) = _Context->value_PaintColours;
		visual_transferout((void *) 0, 0, pIhmColours);
		if ( pIhmColours != (char *) 0)
			*((int*)pIhmColours) = _Context->value_IhmColours;
		visual_transferout((void *) 0, 0, pOtherColours);
		if ( pOtherColours != (char *) 0)
			*((int*)pOtherColours) = _Context->value_OtherColours;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_palette_name_show(struct accept_palette_name_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3625,_Context->y_Auto3625);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto3625,_Context->y_Auto3625,570,200,vfh[2],_Context->msg_Auto3625[_Context->language],strlen(_Context->msg_Auto3625[_Context->language]),0x407);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3625+20,_Context->y_Auto3625+130,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3625+490,_Context->y_Auto3625+130,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_text(_Context->x_Auto3625+20,_Context->y_Auto3625+60,490,16,vfh[2],16,0,_Context->msg_Auto3626[_Context->language],strlen(_Context->msg_Auto3626[_Context->language]),258);
	visual_frame(_Context->x_Auto3625+20,_Context->y_Auto3625+80,496+2,16+2,5);
	visual_text(_Context->x_Auto3625+20+1,_Context->y_Auto3625+80+1,496,16,vfh[1],16,0,_Context->buffer_PaletteName,62,0);
	_Context->trigger_PaintColours=visual_trigger_code(_Context->msg_PaintColours[_Context->language],strlen(_Context->msg_PaintColours[_Context->language]));
	visual_check(_Context->x_Auto3625+120,_Context->y_Auto3625+120,336,16,vfh[2],16,28,_Context->msg_PaintColours[_Context->language],strlen(_Context->msg_PaintColours[_Context->language]),_Context->value_PaintColours|0);
	_Context->trigger_IhmColours=visual_trigger_code(_Context->msg_IhmColours[_Context->language],strlen(_Context->msg_IhmColours[_Context->language]));
	visual_check(_Context->x_Auto3625+120,_Context->y_Auto3625+140,336,16,vfh[2],16,28,_Context->msg_IhmColours[_Context->language],strlen(_Context->msg_IhmColours[_Context->language]),_Context->value_IhmColours|0);
	_Context->trigger_OtherColours=visual_trigger_code(_Context->msg_OtherColours[_Context->language],strlen(_Context->msg_OtherColours[_Context->language]));
	visual_check(_Context->x_Auto3625+120,_Context->y_Auto3625+160,336,16,vfh[2],16,28,_Context->msg_OtherColours[_Context->language],strlen(_Context->msg_OtherColours[_Context->language]),_Context->value_OtherColours|0);
	_Context->trigger_Choixfconf=visual_trigger_code(_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]));
	visual_button(_Context->x_Auto3625+520,_Context->y_Auto3625+80,20,16,vfh[8],27,28,_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]),0);
	visual_thaw(_Context->x_Auto3625,_Context->y_Auto3625,570,200);

	return(0);
}

private int Auto3625action(struct accept_palette_name_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_palette_name_hide(_Context);

		_Context->x_Auto3625 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3625 < 0) { _Context->x_Auto3625=0; }
		_Context->y_Auto3625 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3625 < 0) { _Context->y_Auto3625=0; }
			accept_palette_name_show(_Context);

		visual_thaw(_Context->x_Auto3625,_Context->y_Auto3625,570,200);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_palette_name_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_palette_name_context * _Context) {
	return(27);
	return(-1);
}
private int on_Choixfconf_event(struct accept_palette_name_context * _Context) {
	use_file_selector(_Context->buffer_PaletteName,WIDGET_FILE_RGB);
		accept_palette_name_show(_Context);
;
	return(-1);
}


public	int	accept_palette_name_event(
struct accept_palette_name_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(2);
		if (_Context->trigger_Cancel == mb ) return(3);
		if (_Context->trigger_PaintColours == mb ) return(5);
		if (_Context->trigger_IhmColours == mb ) return(6);
		if (_Context->trigger_OtherColours == mb ) return(7);
		if (_Context->trigger_Choixfconf == mb ) return(8);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3625+549) )  
	&&  (my >= (_Context->y_Auto3625+4) )  
	&&  (mx <= (_Context->x_Auto3625+566) )  
	&&  (my <= (_Context->y_Auto3625+20) )) {
		return(1);	/* Auto3625 */

		}
	if ((mx >= (_Context->x_Auto3625+533) )  
	&&  (my >= (_Context->y_Auto3625+4) )  
	&&  (mx <= (_Context->x_Auto3625+550) )  
	&&  (my <= (_Context->y_Auto3625+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vnewpal.htm");
			};
		return(-1);	/* Auto3625 */

		}
	if ((mx >= (_Context->x_Auto3625+517) )  
	&&  (my >= (_Context->y_Auto3625+4) )  
	&&  (mx <= (_Context->x_Auto3625+534) )  
	&&  (my <= (_Context->y_Auto3625+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_palette_name_show(_Context);
		return(-1);	/* Auto3625 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3625+4) )  
		&&  (my >= (_Context->y_Auto3625+4) )  
		&&  (mx <= (_Context->x_Auto3625+502) )  
		&&  (my <= (_Context->y_Auto3625+20) )) {
			return( Auto3625action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3625+20) ) 
	&&  ( my >= (_Context->y_Auto3625+130) ) 
	&&  ( mx <= (_Context->x_Auto3625+20+56) ) 
	&&  ( my <= (_Context->y_Auto3625+130+48))) {
		return(2); /* Accept */
		}
	if (( mx >= (_Context->x_Auto3625+490) ) 
	&&  ( my >= (_Context->y_Auto3625+130) ) 
	&&  ( mx <= (_Context->x_Auto3625+490+56) ) 
	&&  ( my <= (_Context->y_Auto3625+130+48))) {
		return(3); /* Cancel */
		}
	if (( mx >= (_Context->x_Auto3625+20) ) 
	&&  ( my >= (_Context->y_Auto3625+80) ) 
	&&  ( mx <= (_Context->x_Auto3625+20+496) ) 
	&&  ( my <= (_Context->y_Auto3625+80+16))) {
		return(4); /* PaletteName */
		}
	if (( mx >= (_Context->x_Auto3625+120) ) 
	&&  ( my >= (_Context->y_Auto3625+120) ) 
	&&  ( mx <= (_Context->x_Auto3625+120+336) ) 
	&&  ( my <= (_Context->y_Auto3625+120+16))) {
		return(5); /* PaintColours */
		}
	if (( mx >= (_Context->x_Auto3625+120) ) 
	&&  ( my >= (_Context->y_Auto3625+140) ) 
	&&  ( mx <= (_Context->x_Auto3625+120+336) ) 
	&&  ( my <= (_Context->y_Auto3625+140+16))) {
		return(6); /* IhmColours */
		}
	if (( mx >= (_Context->x_Auto3625+120) ) 
	&&  ( my >= (_Context->y_Auto3625+160) ) 
	&&  ( mx <= (_Context->x_Auto3625+120+336) ) 
	&&  ( my <= (_Context->y_Auto3625+160+16))) {
		return(7); /* OtherColours */
		}
	if (( mx >= (_Context->x_Auto3625+520) ) 
	&&  ( my >= (_Context->y_Auto3625+80) ) 
	&&  ( mx <= (_Context->x_Auto3625+520+20) ) 
	&&  ( my <= (_Context->y_Auto3625+80+16))) {
		return(8); /* Choixfconf */
		}

	return(-1);
}


public	int	accept_palette_name_focus(struct accept_palette_name_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x4 :
				/* PaletteName */
				_Context->keycode = visual_edit(_Context->x_Auto3625+20+1,_Context->y_Auto3625+80+1,496,16,vfh[1],_Context->buffer_PaletteName,62);
			break;
			case	0x5 :
				/* PaintColours */
				visual_check(_Context->x_Auto3625+120,_Context->y_Auto3625+120,336,16,vfh[2],16,28,_Context->msg_PaintColours[_Context->language],strlen(_Context->msg_PaintColours[_Context->language]),(_Context->value_PaintColours |2));
				_Context->keycode = visual_getch();
				_Context->trigger_PaintColours=visual_trigger_code(_Context->msg_PaintColours[_Context->language],strlen(_Context->msg_PaintColours[_Context->language]));
	visual_check(_Context->x_Auto3625+120,_Context->y_Auto3625+120,336,16,vfh[2],16,28,_Context->msg_PaintColours[_Context->language],strlen(_Context->msg_PaintColours[_Context->language]),_Context->value_PaintColours|0);
				break;
			case	0x6 :
				/* IhmColours */
				visual_check(_Context->x_Auto3625+120,_Context->y_Auto3625+140,336,16,vfh[2],16,28,_Context->msg_IhmColours[_Context->language],strlen(_Context->msg_IhmColours[_Context->language]),(_Context->value_IhmColours |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IhmColours=visual_trigger_code(_Context->msg_IhmColours[_Context->language],strlen(_Context->msg_IhmColours[_Context->language]));
	visual_check(_Context->x_Auto3625+120,_Context->y_Auto3625+140,336,16,vfh[2],16,28,_Context->msg_IhmColours[_Context->language],strlen(_Context->msg_IhmColours[_Context->language]),_Context->value_IhmColours|0);
				break;
			case	0x7 :
				/* OtherColours */
				visual_check(_Context->x_Auto3625+120,_Context->y_Auto3625+160,336,16,vfh[2],16,28,_Context->msg_OtherColours[_Context->language],strlen(_Context->msg_OtherColours[_Context->language]),(_Context->value_OtherColours |2));
				_Context->keycode = visual_getch();
				_Context->trigger_OtherColours=visual_trigger_code(_Context->msg_OtherColours[_Context->language],strlen(_Context->msg_OtherColours[_Context->language]));
	visual_check(_Context->x_Auto3625+120,_Context->y_Auto3625+160,336,16,vfh[2],16,28,_Context->msg_OtherColours[_Context->language],strlen(_Context->msg_OtherColours[_Context->language]),_Context->value_OtherColours|0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_palette_name_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=8;
			accept_palette_name_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_palette_name_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3625 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_Auto3625+20,_Context->y_Auto3625+130,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3625+20,_Context->y_Auto3625+130,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Auto3625+490,_Context->y_Auto3625+130,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3625+490,_Context->y_Auto3625+130,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* PaletteName */
					continue;
				case	0x5 :
					/* PaintColours */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_PaintColours += 1;
						_Context->value_PaintColours &= 1;
						}
					continue;
				case	0x6 :
					/* IhmColours */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IhmColours += 1;
						_Context->value_IhmColours &= 1;
						}
					continue;
				case	0x7 :
					/* OtherColours */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_OtherColours += 1;
						_Context->value_OtherColours &= 1;
						}
					continue;
				case	0x8 :
					/* Choixfconf */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Choixfconf=visual_trigger_code(_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]));
						visual_button(_Context->x_Auto3625+520,_Context->y_Auto3625+80,20,16,vfh[8],27,28,_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Choixfconf=visual_trigger_code(_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]));
	visual_button(_Context->x_Auto3625+520,_Context->y_Auto3625+80,20,16,vfh[8],27,28,_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Choixfconf_event(_Context)) != -1) break;

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
				_Context->focus_item=8;
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

public	int	accept_palette_name(
	char * pPaletteName,
	char * pPaintColours,
	char * pIhmColours,
	char * pOtherColours)
{
	int	status=0;
	struct accept_palette_name_context * _Context=(struct accept_palette_name_context*) 0;
	status = accept_palette_name_create(
	&_Context,
	 pPaletteName,
	 pPaintColours,
	 pIhmColours,
	 pOtherColours);
	if ( status != 0) return(status);
	status = accept_palette_name_show(_Context);
		enter_modal();
	status = accept_palette_name_focus(_Context);
		leave_modal();
	status = accept_palette_name_hide(_Context);
	status = accept_palette_name_remove(
	_Context,
	 pPaletteName,
	 pPaintColours,
	 pIhmColours,
	 pOtherColours);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vnewpal_c */
