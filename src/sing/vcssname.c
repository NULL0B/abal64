
#ifndef _vcssname_c
#define _vcssname_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vcssname.xml                                             */
/* Target         : vcssname.c                                               */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en__Auto3638   ""
#define en_ExportMsg   "Database Export Operation : Xml Filename"
#define fr_ExportMsg   "Operation d'export de base de donn‚es : nom de fichier XML"
#define it_ExportMsg   "Database Export Operation : Xml Filename"
#define es_ExportMsg   "Database Export Operation : Xml Filename"
#define de_ExportMsg   "Database Export Operation : Xml Filename"
#define nl_ExportMsg   "Database Export Operation : Xml Filename"
#define pt_ExportMsg   "Database Export Operation : Xml Filename"
#define xx_ExportMsg   "Database Export Operation : Xml Filename"
#define en__ExportMsg   ""
#define fr__ExportMsg   ""
#define it__ExportMsg   ""
#define es__ExportMsg   ""
#define de__ExportMsg   ""
#define nl__ExportMsg   ""
#define pt__ExportMsg   ""
#define xx__ExportMsg   ""
#define en_ImportMsg   "Style Class Import Operation"
#define fr_ImportMsg   "Operation d'import de classe de style"
#define it_ImportMsg   "Style Class Import Operation"
#define es_ImportMsg   "Style Class Import Operation"
#define de_ImportMsg   "Style Class Import Operation"
#define nl_ImportMsg   "Style Class Import Operation"
#define pt_ImportMsg   "Style Class Import Operation"
#define xx_ImportMsg   "Style Class Import Operation"
#define en__ImportMsg   ""
#define fr__ImportMsg   ""
#define it__ImportMsg   ""
#define es__ImportMsg   ""
#define de__ImportMsg   ""
#define nl__ImportMsg   ""
#define pt__ImportMsg   ""
#define xx__ImportMsg   ""
#define en_Auto3639   "File Name"
#define fr_Auto3639   "Fichier"
#define it_Auto3639   "Filename"
#define es_Auto3639   "Filename"
#define de_Auto3639   "Datei"
#define nl_Auto3639   "Filename"
#define pt_Auto3639   "Filename"
#define xx_Auto3639   "Filename"
#define en__Auto3639   ""
#define fr__Auto3639   ""
#define it__Auto3639   ""
#define es__Auto3639   ""
#define de__Auto3639   ""
#define nl__Auto3639   ""
#define pt__Auto3639   ""
#define xx__Auto3639   ""
#define en_StyleSheet   ""
#define en__StyleSheet   ""
#define en_Nature   "Message"
#define fr_Nature   "Message"
#define it_Nature   "Message"
#define es_Nature   "Message"
#define de_Nature   "Message"
#define nl_Nature   "Message"
#define pt_Nature   "Message"
#define xx_Nature   "Message"
#define en__Nature   ""
#define fr__Nature   ""
#define it__Nature   ""
#define es__Nature   ""
#define de__Nature   ""
#define nl__Nature   ""
#define pt__Nature   ""
#define xx__Nature   ""
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

private struct accept_css_filename_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3638[8];
	char * hint_Auto3638[8];
	int	x_Auto3638;
	int	y_Auto3638;
	int	w_Auto3638;
	int	h_Auto3638;
	char * msg_ExportMsg[8];
	char * hint_ExportMsg[8];
	char * msg_ImportMsg[8];
	char * hint_ImportMsg[8];
	char * msg_Auto3639[8];
	char * hint_Auto3639[8];
	char * hint_StyleSheet[8];
	char	buffer_StyleSheet[256];
	char * msg_Nature[8];
	int	trigger_Nature;
	char * hint_Nature[8];
	int	value_Nature;
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
	char	signature[3];
	};
static int	vfh[16];
private int on_Nature_show(struct accept_css_filename_context * _Context);
private int on_Accept_event(struct accept_css_filename_context * _Context);
private int on_Cancel_event(struct accept_css_filename_context * _Context);
private int on_EditStyle_event(struct accept_css_filename_context * _Context);
private int on_ChooseStyleName_event(struct accept_css_filename_context * _Context);

public	int	accept_css_filename_create(
	struct accept_css_filename_context ** cptr,
	char * pStyleSheet,
	char * pNature)
{

	int i;
	struct accept_css_filename_context * _Context=(struct accept_css_filename_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_css_filename_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=6;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_StyleSheet, 255, pStyleSheet);
		visual_transferin((void *) 0, 0, pNature);
		if (!( pNature )) _Context->value_Nature=0;
		else	_Context->value_Nature = *((int *)pNature);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3638[i]=" ";
	_Context->hint_Auto3638[0]=en__Auto3638;
	_Context->x_Auto3638=100;
	_Context->y_Auto3638=195;
	_Context->w_Auto3638=600;
	_Context->h_Auto3638=210;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_ExportMsg[i]=" ";
	_Context->msg_ExportMsg[0]=en_ExportMsg;
	_Context->msg_ExportMsg[1]=fr_ExportMsg;
	_Context->msg_ExportMsg[2]=it_ExportMsg;
	_Context->msg_ExportMsg[3]=es_ExportMsg;
	_Context->msg_ExportMsg[4]=de_ExportMsg;
	_Context->msg_ExportMsg[5]=nl_ExportMsg;
	_Context->msg_ExportMsg[6]=pt_ExportMsg;
	_Context->msg_ExportMsg[7]=xx_ExportMsg;
	_Context->hint_ExportMsg[0]=en__ExportMsg;
	_Context->hint_ExportMsg[1]=fr__ExportMsg;
	_Context->hint_ExportMsg[2]=it__ExportMsg;
	_Context->hint_ExportMsg[3]=es__ExportMsg;
	_Context->hint_ExportMsg[4]=de__ExportMsg;
	_Context->hint_ExportMsg[5]=nl__ExportMsg;
	_Context->hint_ExportMsg[6]=pt__ExportMsg;
	_Context->hint_ExportMsg[7]=xx__ExportMsg;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3639[i]=" ";
	_Context->msg_Auto3639[0]=en_Auto3639;
	_Context->msg_Auto3639[1]=fr_Auto3639;
	_Context->msg_Auto3639[2]=it_Auto3639;
	_Context->msg_Auto3639[3]=es_Auto3639;
	_Context->msg_Auto3639[4]=de_Auto3639;
	_Context->msg_Auto3639[5]=nl_Auto3639;
	_Context->msg_Auto3639[6]=pt_Auto3639;
	_Context->msg_Auto3639[7]=xx_Auto3639;
	_Context->hint_Auto3639[0]=en__Auto3639;
	_Context->hint_Auto3639[1]=fr__Auto3639;
	_Context->hint_Auto3639[2]=it__Auto3639;
	_Context->hint_Auto3639[3]=es__Auto3639;
	_Context->hint_Auto3639[4]=de__Auto3639;
	_Context->hint_Auto3639[5]=nl__Auto3639;
	_Context->hint_Auto3639[6]=pt__Auto3639;
	_Context->hint_Auto3639[7]=xx__Auto3639;
	_Context->hint_StyleSheet[0]=en__StyleSheet;
	for (i=0; i < 8; i++)_Context->msg_Nature[i]=" ";
	_Context->msg_Nature[0]=en_Nature;
	_Context->msg_Nature[1]=fr_Nature;
	_Context->msg_Nature[2]=it_Nature;
	_Context->msg_Nature[3]=es_Nature;
	_Context->msg_Nature[4]=de_Nature;
	_Context->msg_Nature[5]=nl_Nature;
	_Context->msg_Nature[6]=pt_Nature;
	_Context->msg_Nature[7]=xx_Nature;
	_Context->hint_Nature[0]=en__Nature;
	_Context->hint_Nature[1]=fr__Nature;
	_Context->hint_Nature[2]=it__Nature;
	_Context->hint_Nature[3]=es__Nature;
	_Context->hint_Nature[4]=de__Nature;
	_Context->hint_Nature[5]=nl__Nature;
	_Context->hint_Nature[6]=pt__Nature;
	_Context->hint_Nature[7]=xx__Nature;
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
	_Context->pushbuffer=visual_buffer(100,195,600+10,210+10);
	return(0);
}

public 	int	accept_css_filename_hide(struct accept_css_filename_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,100,195);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_css_filename_remove(
	struct accept_css_filename_context * _Context,
	char * pStyleSheet,
	char * pNature)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_StyleSheet, 255, pStyleSheet);
		visual_transferout((void *) 0, 0, pNature);
		if ( pNature != (char *) 0)
			*((int*)pNature) = _Context->value_Nature;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Nature_show(struct accept_css_filename_context * _Context) {
	switch(_Context->value_Nature){
	case 0:	visual_text(120,235,552,40,vfh[3],16,0,_Context->msg_ImportMsg[_Context->language],strlen(_Context->msg_ImportMsg[_Context->language]),259);
;break;
	case 1:	visual_text(120,235,552,40,vfh[3],16,0,_Context->msg_ExportMsg[_Context->language],strlen(_Context->msg_ExportMsg[_Context->language]),259);
;break;
	}
	return(-1);
}

public	int	accept_css_filename_show(struct accept_css_filename_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,100,195);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(100,195,600,210,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(100,195,600,210,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(130,295,98,16,vfh[2],16,0,_Context->msg_Auto3639[_Context->language],strlen(_Context->msg_Auto3639[_Context->language]),258);
	visual_frame(230,295,416+2,16+2,5);
	visual_text(230+1,295+1,416,16,vfh[1],27,28,_Context->buffer_StyleSheet,255,0);
	(void) on_Nature_show(_Context);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(410,325,56,48,vfh[1],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(470,325,56,48,vfh[1],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
	visual_button(530,325,56,48,vfh[1],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),1040);
	_Context->trigger_ChooseStyleName=visual_trigger_code(_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]));
	visual_button(590,325,56,48,vfh[8],27,28,_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]),1040);
	visual_thaw(100,195,600,210);

	return(0);
}

private int Auto3638action(struct accept_css_filename_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_css_filename_hide(_Context);

		_Context->x_Auto3638 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3638 < 0) { _Context->x_Auto3638=0; }
		_Context->y_Auto3638 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3638 < 0) { _Context->y_Auto3638=0; }
			accept_css_filename_show(_Context);

		visual_thaw(100,195,600,210);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_css_filename_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_css_filename_context * _Context) {
	return(27);
	return(-1);
}
private int on_EditStyle_event(struct accept_css_filename_context * _Context) {
	int h;
		accept_css_filename_hide(_Context);
;
	h=set_context_dataview(0);
	edit_style_file(_Context->buffer_StyleSheet,255);
	h=set_context_dataview(h);
		accept_css_filename_show(_Context);
;
	return(-1);
}
private int on_ChooseStyleName_event(struct accept_css_filename_context * _Context) {
	int h;
		accept_css_filename_hide(_Context);
;
	h=set_context_dataview(0);
	use_file_selector(_Context->buffer_StyleSheet,WIDGET_FILE_CSS);
	h=set_context_dataview(h);
		accept_css_filename_show(_Context);
;
	return(-1);
}


public	int	accept_css_filename_event(
struct accept_css_filename_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Nature == mb ) return(0);
		if (_Context->trigger_Accept == mb ) return(3);
		if (_Context->trigger_Cancel == mb ) return(4);
		if (_Context->trigger_EditStyle == mb ) return(5);
		if (_Context->trigger_ChooseStyleName == mb ) return(6);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= 679 )  
	&&  (my >= 199 )  
	&&  (mx <= 695 )  
	&&  (my <= 215 )) {
		return(1);	/* Auto3638 */

		}
	if ((mx >= 663 )  
	&&  (my >= 199 )  
	&&  (mx <= 679 )  
	&&  (my <= 215 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcssname.htm");
			};
		return(-1);	/* Auto3638 */

		}
	if ((mx >= 647 )  
	&&  (my >= 199 )  
	&&  (mx <= 663 )  
	&&  (my <= 215 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_css_filename_show(_Context);
		return(-1);	/* Auto3638 */

		}
	case _MIMO_DOWN :
		if ((mx >= (100+4) )  
		&&  (my >= (195+4) )  
		&&  (mx <= (100+532) )  
		&&  (my <= (195+20) )) {
			return( Auto3638action(_Context) );
			}
		}
	if (( mx >= 230 ) 
	&&  ( my >= 295 ) 
	&&  ( mx <= 646 ) 
	&&  ( my <= 311 )) {
		return(2); /* StyleSheet */
		}
	if (( mx >= 410 ) 
	&&  ( my >= 325 ) 
	&&  ( mx <= 466 ) 
	&&  ( my <= 373 )) {
		return(3); /* Accept */
		}
	if (( mx >= 470 ) 
	&&  ( my >= 325 ) 
	&&  ( mx <= 526 ) 
	&&  ( my <= 373 )) {
		return(4); /* Cancel */
		}
	if (( mx >= 530 ) 
	&&  ( my >= 325 ) 
	&&  ( mx <= 586 ) 
	&&  ( my <= 373 )) {
		return(5); /* EditStyle */
		}
	if (( mx >= 590 ) 
	&&  ( my >= 325 ) 
	&&  ( mx <= 646 ) 
	&&  ( my <= 373 )) {
		return(6); /* ChooseStyleName */
		}

	return(-1);
}


public	int	accept_css_filename_focus(struct accept_css_filename_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* StyleSheet */
				_Context->keycode = visual_edit(230+1,295+1,416,16,vfh[1],_Context->buffer_StyleSheet,255);
			break;
			case	0x3 :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(410,325,56,48,vfh[1],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(410,325,56,48,vfh[1],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0x4 :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(470,325,56,48,vfh[1],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(470,325,56,48,vfh[1],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;
			case	0x5 :
				/* EditStyle */
				_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
				visual_button(530,325,56,48,vfh[1],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
	visual_button(530,325,56,48,vfh[1],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),1040);
				break;
			case	0x6 :
				/* ChooseStyleName */
				_Context->trigger_ChooseStyleName=visual_trigger_code(_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]));
				visual_button(590,325,56,48,vfh[8],27,28,_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_ChooseStyleName=visual_trigger_code(_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]));
	visual_button(590,325,56,48,vfh[8],27,28,_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_css_filename_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=6;
			accept_css_filename_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_css_filename_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3638 */
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
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(410,325,56,48,vfh[1],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(410,325,56,48,vfh[1],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(470,325,56,48,vfh[1],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(470,325,56,48,vfh[1],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* EditStyle */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
						visual_button(530,325,56,48,vfh[1],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
	visual_button(530,325,56,48,vfh[1],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_EditStyle_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* ChooseStyleName */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChooseStyleName=visual_trigger_code(_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]));
						visual_button(590,325,56,48,vfh[8],27,28,_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChooseStyleName=visual_trigger_code(_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]));
	visual_button(590,325,56,48,vfh[8],27,28,_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]),1040);
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
				_Context->focus_item=6;
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

public	int	accept_css_filename(
	char * pStyleSheet,
	char * pNature)
{
	int	status=0;
	struct accept_css_filename_context * _Context=(struct accept_css_filename_context*) 0;
	status = accept_css_filename_create(
	&_Context,
	 pStyleSheet,
	 pNature);
	if ( status != 0) return(status);
	status = accept_css_filename_show(_Context);
		enter_modal();
	status = accept_css_filename_focus(_Context);
		leave_modal();
	status = accept_css_filename_hide(_Context);
	status = accept_css_filename_remove(
	_Context,
	 pStyleSheet,
	 pNature);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcssname_c */
