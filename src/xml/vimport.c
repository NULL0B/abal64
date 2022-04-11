
#ifndef _vimport_c
#define _vimport_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vimport.xml                                              */
/* Target         : vimport.c                                                */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__auto2   ""
#define fr__auto2   ""
#define it__auto2   ""
#define es__auto2   ""
#define de__auto2   ""
#define nl__auto2   ""
#define pt__auto2   ""
#define xx__auto2   ""
#define en_auto27   "Import Font from Image"
#define fr_auto27   "Importer la police … partir d'une image"
#define it_auto27   "Import Font from Image"
#define es_auto27   "Import Font from Image"
#define de_auto27   "Import Font from Image"
#define nl_auto27   "Import Font from Image"
#define pt_auto27   "Import Font from Image"
#define xx_auto27   "Import Font from Image"
#define en__auto27   ""
#define fr__auto27   ""
#define it__auto27   ""
#define es__auto27   ""
#define de__auto27   ""
#define nl__auto27   ""
#define pt__auto27   ""
#define xx__auto27   ""
#define en_auto28   "Character Cell Wdith"
#define fr_auto28   "Largeur de caractŠre"
#define it_auto28   "Character Cell Wdith"
#define es_auto28   "Character Cell Wdith"
#define de_auto28   "Character Cell Wdith"
#define nl_auto28   "Character Cell Wdith"
#define pt_auto28   "Character Cell Wdith"
#define xx_auto28   "Character Cell Wdith"
#define en__auto28   ""
#define fr__auto28   ""
#define it__auto28   ""
#define es__auto28   ""
#define de__auto28   ""
#define nl__auto28   ""
#define pt__auto28   ""
#define xx__auto28   ""
#define en_auto31   "Character Call Height"
#define fr_auto31   "Hauteur de caractŠre"
#define it_auto31   "Character Call Height"
#define es_auto31   "Character Call Height"
#define de_auto31   "Character Call Height"
#define nl_auto31   "Character Call Height"
#define pt_auto31   "Character Call Height"
#define xx_auto31   "Character Call Height"
#define en__auto31   ""
#define fr__auto31   ""
#define it__auto31   ""
#define es__auto31   ""
#define de__auto31   ""
#define nl__auto31   ""
#define pt__auto31   ""
#define xx__auto31   ""
#define en_CellWidth   ""
#define en__CellWidth   ""
#define en_CellHeight   ""
#define en__CellHeight   ""
#define en_Auto3569   "ok.gif"
#define fr_Auto3569   "ok.gif"
#define it_Auto3569   "ok.gif"
#define es_Auto3569   "ok.gif"
#define de_Auto3569   "ok.gif"
#define nl_Auto3569   "ok.gif"
#define pt_Auto3569   "ok.gif"
#define xx_Auto3569   "ok.gif"
#define en__Auto3569   ""
#define fr__Auto3569   ""
#define it__Auto3569   ""
#define es__Auto3569   ""
#define de__Auto3569   ""
#define nl__Auto3569   ""
#define pt__Auto3569   ""
#define xx__Auto3569   ""
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

private struct accept_font_import_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_auto2[8];
	char * hint_auto2[8];
	int	x_auto2;
	int	y_auto2;
	int	w_auto2;
	int	h_auto2;
	char * hint_Auto3568[8];
	char * msg_auto27[8];
	char * hint_auto27[8];
	char * msg_auto28[8];
	char * hint_auto28[8];
	char * msg_auto31[8];
	char * hint_auto31[8];
	char * hint_CellWidth[8];
	char	buffer_CellWidth[8];
	char * hint_CellHeight[8];
	char	buffer_CellHeight[8];
	char * msg_Auto3569[8];
	int	trigger_Auto3569;
	char * hint_Auto3569[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};
static int	vfh[16];
private int on_Auto3569_event(struct accept_font_import_context * _Context);
private int on_Cancel_event(struct accept_font_import_context * _Context);

public	int	accept_font_import_create(
	struct accept_font_import_context ** cptr,
	char * pCellWidth,
	char * pCellHeight)
{

	int i;
	struct accept_font_import_context * _Context=(struct accept_font_import_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_font_import_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=5;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_CellWidth, 7, pCellWidth);
		visual_transferin(_Context->buffer_CellHeight, 7, pCellHeight);
		}
	for (i=0; i < 8; i++)_Context->msg_auto2[i]=" ";
	_Context->hint_auto2[0]=en__auto2;
	_Context->hint_auto2[1]=fr__auto2;
	_Context->hint_auto2[2]=it__auto2;
	_Context->hint_auto2[3]=es__auto2;
	_Context->hint_auto2[4]=de__auto2;
	_Context->hint_auto2[5]=nl__auto2;
	_Context->hint_auto2[6]=pt__auto2;
	_Context->hint_auto2[7]=xx__auto2;
	_Context->x_auto2=235;
	_Context->y_auto2=170;
	_Context->w_auto2=330;
	_Context->h_auto2=260;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_auto27[i]=" ";
	_Context->msg_auto27[0]=en_auto27;
	_Context->msg_auto27[1]=fr_auto27;
	_Context->msg_auto27[2]=it_auto27;
	_Context->msg_auto27[3]=es_auto27;
	_Context->msg_auto27[4]=de_auto27;
	_Context->msg_auto27[5]=nl_auto27;
	_Context->msg_auto27[6]=pt_auto27;
	_Context->msg_auto27[7]=xx_auto27;
	_Context->hint_auto27[0]=en__auto27;
	_Context->hint_auto27[1]=fr__auto27;
	_Context->hint_auto27[2]=it__auto27;
	_Context->hint_auto27[3]=es__auto27;
	_Context->hint_auto27[4]=de__auto27;
	_Context->hint_auto27[5]=nl__auto27;
	_Context->hint_auto27[6]=pt__auto27;
	_Context->hint_auto27[7]=xx__auto27;
	for (i=0; i < 8; i++)_Context->msg_auto28[i]=" ";
	_Context->msg_auto28[0]=en_auto28;
	_Context->msg_auto28[1]=fr_auto28;
	_Context->msg_auto28[2]=it_auto28;
	_Context->msg_auto28[3]=es_auto28;
	_Context->msg_auto28[4]=de_auto28;
	_Context->msg_auto28[5]=nl_auto28;
	_Context->msg_auto28[6]=pt_auto28;
	_Context->msg_auto28[7]=xx_auto28;
	_Context->hint_auto28[0]=en__auto28;
	_Context->hint_auto28[1]=fr__auto28;
	_Context->hint_auto28[2]=it__auto28;
	_Context->hint_auto28[3]=es__auto28;
	_Context->hint_auto28[4]=de__auto28;
	_Context->hint_auto28[5]=nl__auto28;
	_Context->hint_auto28[6]=pt__auto28;
	_Context->hint_auto28[7]=xx__auto28;
	for (i=0; i < 8; i++)_Context->msg_auto31[i]=" ";
	_Context->msg_auto31[0]=en_auto31;
	_Context->msg_auto31[1]=fr_auto31;
	_Context->msg_auto31[2]=it_auto31;
	_Context->msg_auto31[3]=es_auto31;
	_Context->msg_auto31[4]=de_auto31;
	_Context->msg_auto31[5]=nl_auto31;
	_Context->msg_auto31[6]=pt_auto31;
	_Context->msg_auto31[7]=xx_auto31;
	_Context->hint_auto31[0]=en__auto31;
	_Context->hint_auto31[1]=fr__auto31;
	_Context->hint_auto31[2]=it__auto31;
	_Context->hint_auto31[3]=es__auto31;
	_Context->hint_auto31[4]=de__auto31;
	_Context->hint_auto31[5]=nl__auto31;
	_Context->hint_auto31[6]=pt__auto31;
	_Context->hint_auto31[7]=xx__auto31;
	_Context->hint_CellWidth[0]=en__CellWidth;
	_Context->hint_CellHeight[0]=en__CellHeight;
	for (i=0; i < 8; i++)_Context->msg_Auto3569[i]=" ";
	_Context->msg_Auto3569[0]=en_Auto3569;
	_Context->msg_Auto3569[1]=fr_Auto3569;
	_Context->msg_Auto3569[2]=it_Auto3569;
	_Context->msg_Auto3569[3]=es_Auto3569;
	_Context->msg_Auto3569[4]=de_Auto3569;
	_Context->msg_Auto3569[5]=nl_Auto3569;
	_Context->msg_Auto3569[6]=pt_Auto3569;
	_Context->msg_Auto3569[7]=xx_Auto3569;
	_Context->hint_Auto3569[0]=en__Auto3569;
	_Context->hint_Auto3569[1]=fr__Auto3569;
	_Context->hint_Auto3569[2]=it__Auto3569;
	_Context->hint_Auto3569[3]=es__Auto3569;
	_Context->hint_Auto3569[4]=de__Auto3569;
	_Context->hint_Auto3569[5]=nl__Auto3569;
	_Context->hint_Auto3569[6]=pt__Auto3569;
	_Context->hint_Auto3569[7]=xx__Auto3569;
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
	_Context->pushbuffer=visual_buffer(_Context->x_auto2,_Context->y_auto2,330+10,260+10);
	return(0);
}

public 	int	accept_font_import_hide(struct accept_font_import_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_auto2,_Context->y_auto2);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_font_import_remove(
	struct accept_font_import_context * _Context,
	char * pCellWidth,
	char * pCellHeight)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_CellWidth, 7, pCellWidth);
		visual_transferout(_Context->buffer_CellHeight, 7, pCellHeight);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_font_import_show(struct accept_font_import_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto2,_Context->y_auto2);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_auto2,_Context->y_auto2,330,260,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_auto2,_Context->y_auto2,330,260,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+80,290,100,4);
	visual_text(_Context->x_auto2+30,_Context->y_auto2+40,275,22,vfh[4],16,0,_Context->msg_auto27[_Context->language],strlen(_Context->msg_auto27[_Context->language]),1283);
	visual_text(_Context->x_auto2+50,_Context->y_auto2+110,154,16,vfh[2],16,0,_Context->msg_auto28[_Context->language],strlen(_Context->msg_auto28[_Context->language]),257);
	visual_text(_Context->x_auto2+50,_Context->y_auto2+140,154,16,vfh[2],16,0,_Context->msg_auto31[_Context->language],strlen(_Context->msg_auto31[_Context->language]),257);
	visual_frame(_Context->x_auto2+210,_Context->y_auto2+110,56+2,16+2,5);
	visual_text(_Context->x_auto2+210+1,_Context->y_auto2+110+1,56,16,vfh[1],26,0,_Context->buffer_CellWidth,7,0);
	visual_frame(_Context->x_auto2+210,_Context->y_auto2+140,56+2,16+2,5);
	visual_text(_Context->x_auto2+210+1,_Context->y_auto2+140+1,56,16,vfh[1],26,0,_Context->buffer_CellHeight,7,0);
	_Context->trigger_Auto3569=visual_trigger_code(_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]));
	visual_button(_Context->x_auto2+100,_Context->y_auto2+190,56,48,vfh[2],26,0,_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto2+180,_Context->y_auto2+190,56,48,vfh[2],26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_thaw(_Context->x_auto2,_Context->y_auto2,330,260);

	return(0);
}

private int CellWidth_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "The CELL WIDTH edit field provides the value calculated by dividing ";
			mptr[1]=" the overall image width by 16, the number of character cells wide ";
			mptr[2]="the   image is assumed to be. This may not be an appropriate width ";
			mptr[3]="to be    used as the default base character width and may need to ";
			mptr[4]="be  modified.  ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CellHeight_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "The CELL Height edit field presents the character cell height as calculated ";
			mptr[1]=" by the overall image height divided by 16, the number of rows of ";
			mptr[2]="characters  assumed to constitute the image. This value may need to ";
			mptr[3]="be  modified to provide a realistic base character cell height .  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3569_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "If neither the CELL WIDTH nor CELL HEIGHT fields have been modified ";
			mptr[1]="and their default values correspond to the dimensions of the characters ";
			mptr[2]="then this button may be pressed to activate the auto importation of ";
			mptr[3]="the entire font from the image.  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Cancel_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "If the CANCEL button is pressed the font import operation will be ";
			mptr[1]=" abandoned.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int auto2action(struct accept_font_import_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_font_import_hide(_Context);

		_Context->x_auto2 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto2 < 0) { _Context->x_auto2=0; }
		_Context->y_auto2 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto2 < 0) { _Context->y_auto2=0; }
			accept_font_import_show(_Context);

		visual_thaw(_Context->x_auto2,_Context->y_auto2,330,260);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3569_event(struct accept_font_import_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_font_import_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_font_import_event(
struct accept_font_import_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto3569 == mb ) return(4);
		if (_Context->trigger_Cancel == mb ) return(5);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_auto2+309) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+326) )  
	&&  (my <= (_Context->y_auto2+20) )) {
		return(1);	/* auto2 */

		}
	if ((mx >= (_Context->x_auto2+293) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+310) )  
	&&  (my <= (_Context->y_auto2+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vimport.htm");
			};
		return(-1);	/* auto2 */

		}
	if ((mx >= (_Context->x_auto2+277) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+294) )  
	&&  (my <= (_Context->y_auto2+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_font_import_show(_Context);
		return(-1);	/* auto2 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_auto2+4) )  
		&&  (my >= (_Context->y_auto2+4) )  
		&&  (mx <= (_Context->x_auto2+262) )  
		&&  (my <= (_Context->y_auto2+20) )) {
			return( auto2action(_Context) );
			}
		}
	if (( mx >= (_Context->x_auto2+210) ) 
	&&  ( my >= (_Context->y_auto2+110) ) 
	&&  ( mx <= (_Context->x_auto2+210+56) ) 
	&&  ( my <= (_Context->y_auto2+110+16))) {
		return(2); /* CellWidth */
		}
	if (( mx >= (_Context->x_auto2+210) ) 
	&&  ( my >= (_Context->y_auto2+140) ) 
	&&  ( mx <= (_Context->x_auto2+210+56) ) 
	&&  ( my <= (_Context->y_auto2+140+16))) {
		return(3); /* CellHeight */
		}
	if (( mx >= (_Context->x_auto2+100) ) 
	&&  ( my >= (_Context->y_auto2+190) ) 
	&&  ( mx <= (_Context->x_auto2+100+56) ) 
	&&  ( my <= (_Context->y_auto2+190+48))) {
		return(4); /* Auto3569 */
		}
	if (( mx >= (_Context->x_auto2+180) ) 
	&&  ( my >= (_Context->y_auto2+190) ) 
	&&  ( mx <= (_Context->x_auto2+180+56) ) 
	&&  ( my <= (_Context->y_auto2+190+48))) {
		return(5); /* Cancel */
		}

	return(-1);
}


public	int	accept_font_import_focus(struct accept_font_import_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* CellWidth */
				_Context->keycode = visual_edit(_Context->x_auto2+210+1,_Context->y_auto2+110+1,56,16,vfh[1],_Context->buffer_CellWidth,7);
			break;
			case	0x3 :
				/* CellHeight */
				_Context->keycode = visual_edit(_Context->x_auto2+210+1,_Context->y_auto2+140+1,56,16,vfh[1],_Context->buffer_CellHeight,7);
			break;
			case	0x4 :
				/* Auto3569 */
				_Context->trigger_Auto3569=visual_trigger_code(_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]));
				visual_button(_Context->x_auto2+100,_Context->y_auto2+190,56,48,vfh[2],26,0,_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3569=visual_trigger_code(_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]));
	visual_button(_Context->x_auto2+100,_Context->y_auto2+190,56,48,vfh[2],26,0,_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]),1040);
				break;
			case	0x5 :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_auto2+180,_Context->y_auto2+190,56,48,vfh[2],26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto2+180,_Context->y_auto2+190,56,48,vfh[2],26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_font_import_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=5;
			accept_font_import_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_font_import_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (CellWidth_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (CellHeight_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Auto3569_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Cancel_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* auto2 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* CellWidth */
					continue;
				case	0x3 :
					/* CellHeight */
					continue;
				case	0x4 :
					/* Auto3569 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3569=visual_trigger_code(_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]));
						visual_button(_Context->x_auto2+100,_Context->y_auto2+190,56,48,vfh[2],26,0,_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3569=visual_trigger_code(_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]));
	visual_button(_Context->x_auto2+100,_Context->y_auto2+190,56,48,vfh[2],26,0,_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3569_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_auto2+180,_Context->y_auto2+190,56,48,vfh[2],26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto2+180,_Context->y_auto2+190,56,48,vfh[2],26,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
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
				_Context->focus_item=5;
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

public	int	accept_font_import(
	char * pCellWidth,
	char * pCellHeight)
{
	int	status=0;
	struct accept_font_import_context * _Context=(struct accept_font_import_context*) 0;
	status = accept_font_import_create(
	&_Context,
	 pCellWidth,
	 pCellHeight);
	if ( status != 0) return(status);
	status = accept_font_import_show(_Context);
		enter_modal();
	status = accept_font_import_focus(_Context);
		leave_modal();
	status = accept_font_import_hide(_Context);
	status = accept_font_import_remove(
	_Context,
	 pCellWidth,
	 pCellHeight);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vimport_c */
