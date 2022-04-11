
#ifndef _vabalname_c
#define _vabalname_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : vabalname.xml                                            */
/* Target         : vabalname.c                                              */
/* Identification : 0.0-1197051806-3646.3645                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en__Auto3331   ""
#define en_ImportMsg   "Abal Source Import Operation"
#define fr_ImportMsg   "Database Import Operation : Xml Filename"
#define it_ImportMsg   "Database Import Operation : Xml Filename"
#define es_ImportMsg   "Database Import Operation : Xml Filename"
#define de_ImportMsg   "Database Import Operation : Xml Filename"
#define nl_ImportMsg   "Database Import Operation : Xml Filename"
#define pt_ImportMsg   "Database Import Operation : Xml Filename"
#define xx_ImportMsg   "Database Import Operation : Xml Filename"
#define en__ImportMsg   ""
#define fr__ImportMsg   ""
#define it__ImportMsg   ""
#define es__ImportMsg   ""
#define de__ImportMsg   ""
#define nl__ImportMsg   ""
#define pt__ImportMsg   ""
#define xx__ImportMsg   ""
#define en_Auto3332   "Source Filename"
#define fr_Auto3332   "Fichier"
#define it_Auto3332   "Filename"
#define es_Auto3332   "Filename"
#define de_Auto3332   "Datei"
#define nl_Auto3332   "Filename"
#define pt_Auto3332   "Filename"
#define xx_Auto3332   "Filename"
#define en__Auto3332   ""
#define fr__Auto3332   ""
#define it__Auto3332   ""
#define es__Auto3332   ""
#define de__Auto3332   ""
#define nl__Auto3332   ""
#define pt__Auto3332   ""
#define xx__Auto3332   ""
#define en_Auto3333   "Symbol Conversion"
#define fr_Auto3333   "Fichier"
#define it_Auto3333   "Filename"
#define es_Auto3333   "Filename"
#define de_Auto3333   "Datei"
#define nl_Auto3333   "Filename"
#define pt_Auto3333   "Filename"
#define xx_Auto3333   "Filename"
#define en__Auto3333   ""
#define fr__Auto3333   ""
#define it__Auto3333   ""
#define es__Auto3333   ""
#define de__Auto3333   ""
#define nl__Auto3333   ""
#define pt__Auto3333   ""
#define xx__Auto3333   ""
#define en_StyleSheet   ""
#define en__StyleSheet   ""
#define en_ConvertCase   "convert to uppercase|convert to lowercase|preserve original case"
#define en__ConvertCase   ""
#define en_Echo   "Activate Source Echo"
#define en__Echo   ""
#define en_Accept   "ok.gif"
#define fr_Accept   "ok.gif"
#define it_Accept   "ok.gif"
#define es_Accept   "ok.gif"
#define de_Accept   "ok.gif"
#define nl_Accept   "ok.gif"
#define pt_Accept   "ok.gif"
#define xx_Accept   "ok.gif"
#define en__Accept   ""
#define fr__Accept   ""
#define it__Accept   ""
#define es__Accept   ""
#define de__Accept   ""
#define nl__Accept   ""
#define pt__Accept   ""
#define xx__Accept   ""
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
#define en_EditStyle   "screen.gif"
#define fr_EditStyle   "screen.gif"
#define it_EditStyle   "screen.gif"
#define es_EditStyle   "screen.gif"
#define de_EditStyle   "screen.gif"
#define nl_EditStyle   "screen.gif"
#define pt_EditStyle   "screen.gif"
#define xx_EditStyle   "screen.gif"
#define en__EditStyle   ""
#define fr__EditStyle   ""
#define it__EditStyle   ""
#define es__EditStyle   ""
#define de__EditStyle   ""
#define nl__EditStyle   ""
#define pt__EditStyle   ""
#define xx__EditStyle   ""
#define en_ChooseStyleName   "folder.png"
#define fr_ChooseStyleName   "folder.png"
#define it_ChooseStyleName   "folder.png"
#define es_ChooseStyleName   "folder.png"
#define de_ChooseStyleName   "folder.png"
#define nl_ChooseStyleName   "folder.png"
#define pt_ChooseStyleName   "folder.png"
#define xx_ChooseStyleName   "folder.png"
#define en__ChooseStyleName   ""
#define fr__ChooseStyleName   ""
#define it__ChooseStyleName   ""
#define es__ChooseStyleName   ""
#define de__ChooseStyleName   ""
#define nl__ChooseStyleName   ""
#define pt__ChooseStyleName   ""
#define xx__ChooseStyleName   ""

private struct accept_abal_filename_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3331[8];
	char * hint_Auto3331[8];
	int	x_Auto3331;
	int	y_Auto3331;
	int	w_Auto3331;
	int	h_Auto3331;
	char * msg_ImportMsg[8];
	char * hint_ImportMsg[8];
	char * msg_Auto3332[8];
	char * hint_Auto3332[8];
	char * msg_Auto3333[8];
	char * hint_Auto3333[8];
	char * hint_StyleSheet[8];
	char	buffer_StyleSheet[256];
	char * msg_ConvertCase[8];
	char * hint_ConvertCase[8];
	int	value_ConvertCase;
	char * msg_Echo[8];
	int	trigger_Echo;
	char * hint_Echo[8];
	int	value_Echo;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	char * msg_EditStyle[8];
	int	trigger_EditStyle;
	char * hint_EditStyle[8];
	char * msg_ChooseStyleName[8];
	int	trigger_ChooseStyleName;
	char * hint_ChooseStyleName[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[4];
	};
static int	vfh[16];

public	int	accept_abal_filename_create(
	struct accept_abal_filename_context ** cptr,
	char * pStyleSheet,
	char * pConvertCase,
	char * pEcho)
{

	int i;
	struct accept_abal_filename_context * _Context=(struct accept_abal_filename_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_abal_filename_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=8;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_StyleSheet, 255, pStyleSheet);
		visual_transferin((void *) 0, 0, pConvertCase);
		if (!( pConvertCase )) _Context->value_ConvertCase=0;
		else	_Context->value_ConvertCase = *((int *)pConvertCase);
		visual_transferin((void *) 0, 0, pEcho);
		if (!( pEcho )) _Context->value_Echo=0;
		else	_Context->value_Echo = *((int *)pEcho);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3331[i]=" ";
	_Context->hint_Auto3331[0]=en__Auto3331;
	_Context->x_Auto3331=105;
	_Context->y_Auto3331=195;
	_Context->w_Auto3331=590;
	_Context->h_Auto3331=210;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_ImportMsg[i]=" ";
	_Context->msg_ImportMsg[0]=en_ImportMsg;
	_Context->msg_ImportMsg[1]=fr_ImportMsg;
	_Context->msg_ImportMsg[2]=it_ImportMsg;
	_Context->msg_ImportMsg[3]=es_ImportMsg;
	_Context->msg_ImportMsg[4]=de_ImportMsg;
	_Context->msg_ImportMsg[5]=nl_ImportMsg;
	_Context->msg_ImportMsg[6]=pt_ImportMsg;
	_Context->msg_ImportMsg[7]=xx_ImportMsg;
	_Context->hint_ImportMsg[0]=en__ImportMsg;
	_Context->hint_ImportMsg[1]=fr__ImportMsg;
	_Context->hint_ImportMsg[2]=it__ImportMsg;
	_Context->hint_ImportMsg[3]=es__ImportMsg;
	_Context->hint_ImportMsg[4]=de__ImportMsg;
	_Context->hint_ImportMsg[5]=nl__ImportMsg;
	_Context->hint_ImportMsg[6]=pt__ImportMsg;
	_Context->hint_ImportMsg[7]=xx__ImportMsg;
	for (i=0; i < 8; i++)_Context->msg_Auto3332[i]=" ";
	_Context->msg_Auto3332[0]=en_Auto3332;
	_Context->msg_Auto3332[1]=fr_Auto3332;
	_Context->msg_Auto3332[2]=it_Auto3332;
	_Context->msg_Auto3332[3]=es_Auto3332;
	_Context->msg_Auto3332[4]=de_Auto3332;
	_Context->msg_Auto3332[5]=nl_Auto3332;
	_Context->msg_Auto3332[6]=pt_Auto3332;
	_Context->msg_Auto3332[7]=xx_Auto3332;
	_Context->hint_Auto3332[0]=en__Auto3332;
	_Context->hint_Auto3332[1]=fr__Auto3332;
	_Context->hint_Auto3332[2]=it__Auto3332;
	_Context->hint_Auto3332[3]=es__Auto3332;
	_Context->hint_Auto3332[4]=de__Auto3332;
	_Context->hint_Auto3332[5]=nl__Auto3332;
	_Context->hint_Auto3332[6]=pt__Auto3332;
	_Context->hint_Auto3332[7]=xx__Auto3332;
	for (i=0; i < 8; i++)_Context->msg_Auto3333[i]=" ";
	_Context->msg_Auto3333[0]=en_Auto3333;
	_Context->msg_Auto3333[1]=fr_Auto3333;
	_Context->msg_Auto3333[2]=it_Auto3333;
	_Context->msg_Auto3333[3]=es_Auto3333;
	_Context->msg_Auto3333[4]=de_Auto3333;
	_Context->msg_Auto3333[5]=nl_Auto3333;
	_Context->msg_Auto3333[6]=pt_Auto3333;
	_Context->msg_Auto3333[7]=xx_Auto3333;
	_Context->hint_Auto3333[0]=en__Auto3333;
	_Context->hint_Auto3333[1]=fr__Auto3333;
	_Context->hint_Auto3333[2]=it__Auto3333;
	_Context->hint_Auto3333[3]=es__Auto3333;
	_Context->hint_Auto3333[4]=de__Auto3333;
	_Context->hint_Auto3333[5]=nl__Auto3333;
	_Context->hint_Auto3333[6]=pt__Auto3333;
	_Context->hint_Auto3333[7]=xx__Auto3333;
	_Context->hint_StyleSheet[0]=en__StyleSheet;
	for (i=0; i < 8; i++)_Context->msg_ConvertCase[i]=" ";
	_Context->msg_ConvertCase[0]=en_ConvertCase;
	_Context->hint_ConvertCase[0]=en__ConvertCase;
	for (i=0; i < 8; i++)_Context->msg_Echo[i]=" ";
	_Context->msg_Echo[0]=en_Echo;
	_Context->hint_Echo[0]=en__Echo;
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
	_Context->hint_Accept[1]=fr__Accept;
	_Context->hint_Accept[2]=it__Accept;
	_Context->hint_Accept[3]=es__Accept;
	_Context->hint_Accept[4]=de__Accept;
	_Context->hint_Accept[5]=nl__Accept;
	_Context->hint_Accept[6]=pt__Accept;
	_Context->hint_Accept[7]=xx__Accept;
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
	for (i=0; i < 8; i++)_Context->msg_EditStyle[i]=" ";
	_Context->msg_EditStyle[0]=en_EditStyle;
	_Context->msg_EditStyle[1]=fr_EditStyle;
	_Context->msg_EditStyle[2]=it_EditStyle;
	_Context->msg_EditStyle[3]=es_EditStyle;
	_Context->msg_EditStyle[4]=de_EditStyle;
	_Context->msg_EditStyle[5]=nl_EditStyle;
	_Context->msg_EditStyle[6]=pt_EditStyle;
	_Context->msg_EditStyle[7]=xx_EditStyle;
	_Context->hint_EditStyle[0]=en__EditStyle;
	_Context->hint_EditStyle[1]=fr__EditStyle;
	_Context->hint_EditStyle[2]=it__EditStyle;
	_Context->hint_EditStyle[3]=es__EditStyle;
	_Context->hint_EditStyle[4]=de__EditStyle;
	_Context->hint_EditStyle[5]=nl__EditStyle;
	_Context->hint_EditStyle[6]=pt__EditStyle;
	_Context->hint_EditStyle[7]=xx__EditStyle;
	for (i=0; i < 8; i++)_Context->msg_ChooseStyleName[i]=" ";
	_Context->msg_ChooseStyleName[0]=en_ChooseStyleName;
	_Context->msg_ChooseStyleName[1]=fr_ChooseStyleName;
	_Context->msg_ChooseStyleName[2]=it_ChooseStyleName;
	_Context->msg_ChooseStyleName[3]=es_ChooseStyleName;
	_Context->msg_ChooseStyleName[4]=de_ChooseStyleName;
	_Context->msg_ChooseStyleName[5]=nl_ChooseStyleName;
	_Context->msg_ChooseStyleName[6]=pt_ChooseStyleName;
	_Context->msg_ChooseStyleName[7]=xx_ChooseStyleName;
	_Context->hint_ChooseStyleName[0]=en__ChooseStyleName;
	_Context->hint_ChooseStyleName[1]=fr__ChooseStyleName;
	_Context->hint_ChooseStyleName[2]=it__ChooseStyleName;
	_Context->hint_ChooseStyleName[3]=es__ChooseStyleName;
	_Context->hint_ChooseStyleName[4]=de__ChooseStyleName;
	_Context->hint_ChooseStyleName[5]=nl__ChooseStyleName;
	_Context->hint_ChooseStyleName[6]=pt__ChooseStyleName;
	_Context->hint_ChooseStyleName[7]=xx__ChooseStyleName;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(105,195,590+10,210+10);
	return(0);
}

public 	int	accept_abal_filename_hide(struct accept_abal_filename_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,105,195);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_abal_filename_remove(
	struct accept_abal_filename_context * _Context,
	char * pStyleSheet,
	char * pConvertCase,
	char * pEcho)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_StyleSheet, 255, pStyleSheet);
		visual_transferout((void *) 0, 0, pConvertCase);
		if ( pConvertCase != (char *) 0)
			*((int*)pConvertCase) = _Context->value_ConvertCase;
		visual_transferout((void *) 0, 0, pEcho);
		if ( pEcho != (char *) 0)
			*((int*)pEcho) = _Context->value_Echo;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_abal_filename_show(struct accept_abal_filename_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,105,195);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(105,195,590,210,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(105,195,590,210,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(125,235,552,20,vfh[3],16,0,_Context->msg_ImportMsg[_Context->language],strlen(_Context->msg_ImportMsg[_Context->language]),259);
	visual_text(125,285,126,16,vfh[2],16,0,_Context->msg_Auto3332[_Context->language],strlen(_Context->msg_Auto3332[_Context->language]),258);
	visual_text(125,325,126,16,vfh[2],16,0,_Context->msg_Auto3333[_Context->language],strlen(_Context->msg_Auto3333[_Context->language]),258);
	visual_frame(245,285,416+2,16+2,5);
	visual_text(245+1,285+1,416,16,vfh[1],27,28,_Context->buffer_StyleSheet,255,0);
	visual_select(245,325,168,64,vfh[2],0,0,parse_selection(_Context->msg_ConvertCase[_Context->language],&_Context->value_ConvertCase),768);
	_Context->trigger_Echo=visual_trigger_code(_Context->msg_Echo[_Context->language],strlen(_Context->msg_Echo[_Context->language]));
	visual_check(245,355,182,16,vfh[2],16,28,_Context->msg_Echo[_Context->language],strlen(_Context->msg_Echo[_Context->language]),_Context->value_Echo|0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(425,325,56,48,vfh[1],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(485,325,56,48,vfh[1],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
	visual_button(545,325,56,48,vfh[1],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),1040);
	_Context->trigger_ChooseStyleName=visual_trigger_code(_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]));
	visual_button(605,325,56,48,vfh[8],27,28,_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]),1040);
	visual_thaw(105,195,590,210);

	return(0);
}

private int Auto3331action(struct accept_abal_filename_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_abal_filename_hide(_Context);

		_Context->x_Auto3331 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3331 < 0) { _Context->x_Auto3331=0; }
		_Context->y_Auto3331 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3331 < 0) { _Context->y_Auto3331=0; }
			accept_abal_filename_show(_Context);

		visual_thaw(105,195,590,210);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_abal_filename_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_abal_filename_context * _Context) {
	return(27);
	return(-1);
}
private int on_EditStyle_event(struct accept_abal_filename_context * _Context) {
	int h;
		accept_abal_filename_hide(_Context);
;
	h=set_context_dataview(0);
	edit_style_file(_Context->buffer_StyleSheet,255);
	h=set_context_dataview(h);
		accept_abal_filename_show(_Context);
;
	return(-1);
}
private int on_ChooseStyleName_event(struct accept_abal_filename_context * _Context) {
	int h;
		accept_abal_filename_hide(_Context);
;
	h=set_context_dataview(0);
	use_file_selector(_Context->buffer_StyleSheet,WIDGET_FILE_AS);
	h=set_context_dataview(h);
		accept_abal_filename_show(_Context);
;
	return(-1);
}


public	int	accept_abal_filename_event(
struct accept_abal_filename_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Echo == mb ) return(4);
		if (_Context->trigger_Accept == mb ) return(5);
		if (_Context->trigger_Cancel == mb ) return(6);
		if (_Context->trigger_EditStyle == mb ) return(7);
		if (_Context->trigger_ChooseStyleName == mb ) return(8);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= 674 )  
	&&  (my >= 199 )  
	&&  (mx <= 690 )  
	&&  (my <= 215 )) {
		return(1);	/* Auto3331 */

		}
	if ((mx >= 658 )  
	&&  (my >= 199 )  
	&&  (mx <= 674 )  
	&&  (my <= 215 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vabalname.htm");
			};
		return(-1);	/* Auto3331 */

		}
	if ((mx >= 642 )  
	&&  (my >= 199 )  
	&&  (mx <= 658 )  
	&&  (my <= 215 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_abal_filename_show(_Context);
		return(-1);	/* Auto3331 */

		}
	case _MIMO_DOWN :
		if ((mx >= (105+4) )  
		&&  (my >= (195+4) )  
		&&  (mx <= (105+522) )  
		&&  (my <= (195+20) )) {
			return( Auto3331action(_Context) );
			}
		}
	if (( mx >= 245 ) 
	&&  ( my >= 285 ) 
	&&  ( mx <= 661 ) 
	&&  ( my <= 301 )) {
		return(2); /* StyleSheet */
		}
	if ((mx >= 245 ) 
	&&  (my >= 325 ) 
	&&  (mx <= 413 ) 
	&&  (my <= 341 )) {
		return(3); /* ConvertCase */
		}
	if (( mx >= 245 ) 
	&&  ( my >= 355 ) 
	&&  ( mx <= 427 ) 
	&&  ( my <= 371 )) {
		return(4); /* Echo */
		}
	if (( mx >= 425 ) 
	&&  ( my >= 325 ) 
	&&  ( mx <= 481 ) 
	&&  ( my <= 373 )) {
		return(5); /* Accept */
		}
	if (( mx >= 485 ) 
	&&  ( my >= 325 ) 
	&&  ( mx <= 541 ) 
	&&  ( my <= 373 )) {
		return(6); /* Cancel */
		}
	if (( mx >= 545 ) 
	&&  ( my >= 325 ) 
	&&  ( mx <= 601 ) 
	&&  ( my <= 373 )) {
		return(7); /* EditStyle */
		}
	if (( mx >= 605 ) 
	&&  ( my >= 325 ) 
	&&  ( mx <= 661 ) 
	&&  ( my <= 373 )) {
		return(8); /* ChooseStyleName */
		}

	return(-1);
}


public	int	accept_abal_filename_focus(struct accept_abal_filename_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* StyleSheet */
				_Context->keycode = visual_edit(245+1,285+1,416,16,vfh[1],_Context->buffer_StyleSheet,255);
			break;
			case	0x3 :
				/* ConvertCase */
				_Context->keycode = visual_select(245,325,168,64,vfh[2],0,0,parse_selection(_Context->msg_ConvertCase[_Context->language],&_Context->value_ConvertCase),770);
				break;
			case	0x4 :
				/* Echo */
				visual_check(245,355,182,16,vfh[2],16,28,_Context->msg_Echo[_Context->language],strlen(_Context->msg_Echo[_Context->language]),(_Context->value_Echo |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Echo=visual_trigger_code(_Context->msg_Echo[_Context->language],strlen(_Context->msg_Echo[_Context->language]));
	visual_check(245,355,182,16,vfh[2],16,28,_Context->msg_Echo[_Context->language],strlen(_Context->msg_Echo[_Context->language]),_Context->value_Echo|0);
				break;
			case	0x5 :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(425,325,56,48,vfh[1],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(425,325,56,48,vfh[1],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0x6 :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(485,325,56,48,vfh[1],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(485,325,56,48,vfh[1],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;
			case	0x7 :
				/* EditStyle */
				_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
				visual_button(545,325,56,48,vfh[1],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
	visual_button(545,325,56,48,vfh[1],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),1040);
				break;
			case	0x8 :
				/* ChooseStyleName */
				_Context->trigger_ChooseStyleName=visual_trigger_code(_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]));
				visual_button(605,325,56,48,vfh[8],27,28,_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_ChooseStyleName=visual_trigger_code(_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]));
	visual_button(605,325,56,48,vfh[8],27,28,_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_abal_filename_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=8;
			accept_abal_filename_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_abal_filename_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3331 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* StyleSheet */
					continue;
				case	0x3 :
					/* ConvertCase */
					continue;
				case	0x4 :
					/* Echo */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Echo += 1;
						_Context->value_Echo &= 1;
						}
					continue;
				case	0x5 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(425,325,56,48,vfh[1],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(425,325,56,48,vfh[1],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(485,325,56,48,vfh[1],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(485,325,56,48,vfh[1],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* EditStyle */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
						visual_button(545,325,56,48,vfh[1],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
	visual_button(545,325,56,48,vfh[1],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_EditStyle_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* ChooseStyleName */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChooseStyleName=visual_trigger_code(_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]));
						visual_button(605,325,56,48,vfh[8],27,28,_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChooseStyleName=visual_trigger_code(_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]));
	visual_button(605,325,56,48,vfh[8],27,28,_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChooseStyleName_event(_Context)) != -1) break;

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

public	int	accept_abal_filename(
	char * pStyleSheet,
	char * pConvertCase,
	char * pEcho)
{
	int	status=0;
	struct accept_abal_filename_context * _Context=(struct accept_abal_filename_context*) 0;
	status = accept_abal_filename_create(
	&_Context,
	 pStyleSheet,
	 pConvertCase,
	 pEcho);
	if ( status != 0) return(status);
	status = accept_abal_filename_show(_Context);
		enter_modal();
	status = accept_abal_filename_focus(_Context);
		leave_modal();
	status = accept_abal_filename_hide(_Context);
	status = accept_abal_filename_remove(
	_Context,
	 pStyleSheet,
	 pConvertCase,
	 pEcho);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vabalname_c */
