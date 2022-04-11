
#ifndef _vphp_c
#define _vphp_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vphp.xml                                                 */
/* Target         : vphp.c                                                   */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en__Auto3643   ""
#define fr__Auto3643   ""
#define it__Auto3643   ""
#define es__Auto3643   ""
#define de__Auto3643   ""
#define nl__Auto3643   ""
#define pt__Auto3643   ""
#define xx__Auto3643   ""
#define en_Auto3644   "Php Program and Class file name stub"
#define en__Auto3644   ""
#define en_Auto3645   "Soap Host URL"
#define en__Auto3645   ""
#define en_FileStub   ""
#define en__FileStub   ""
#define en_SoapHost   ""
#define en__SoapHost   ""
#define en_WebAgent   "Generate Abal Web Service"
#define en__WebAgent   ""
#define en_Auto3646   "Automatic translation"
#define en__Auto3646   ""
#define en_Restrict   "Restrict Screen Size"
#define en__Restrict   ""
#define en_Inhibit   "Inhbit Page Menu"
#define en__Inhibit   ""
#define en_WithStyle   "Generate Style"
#define en__WithStyle   ""
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

private struct accept_php_production_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3643[8];
	char * hint_Auto3643[8];
	int	x_Auto3643;
	int	y_Auto3643;
	int	w_Auto3643;
	int	h_Auto3643;
	char * msg_Auto3644[8];
	char * hint_Auto3644[8];
	char * msg_Auto3645[8];
	char * hint_Auto3645[8];
	char * hint_FileStub[8];
	char	buffer_FileStub[256];
	char * hint_SoapHost[8];
	char	buffer_SoapHost[256];
	char * msg_WebAgent[8];
	int	trigger_WebAgent;
	char * hint_WebAgent[8];
	int	value_WebAgent;
	char * msg_Auto3646[8];
	int	trigger_Auto3646;
	char * hint_Auto3646[8];
	int	value_Auto3646;
	char * msg_Restrict[8];
	int	trigger_Restrict;
	char * hint_Restrict[8];
	int	value_Restrict;
	char * msg_Inhibit[8];
	int	trigger_Inhibit;
	char * hint_Inhibit[8];
	int	value_Inhibit;
	char * msg_WithStyle[8];
	int	trigger_WithStyle;
	char * hint_WithStyle[8];
	int	value_WithStyle;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[8];
	};
static int	vfh[16];
private int on_Accept_event(struct accept_php_production_context * _Context);
private int on_Cancel_event(struct accept_php_production_context * _Context);

public	int	accept_php_production_create(
	struct accept_php_production_context ** cptr,
	char * pFileStub,
	char * pSoapHost,
	char * pWebAgent,
	char * pAuto3646,
	char * pRestrict,
	char * pInhibit,
	char * pWithStyle)
{

	int i;
	struct accept_php_production_context * _Context=(struct accept_php_production_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_php_production_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=9;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileStub, 255, pFileStub);
		visual_transferin(_Context->buffer_SoapHost, 255, pSoapHost);
		visual_transferin((void *) 0, 0, pWebAgent);
		if (!( pWebAgent )) _Context->value_WebAgent=0;
		else	_Context->value_WebAgent = *((int *)pWebAgent);
		visual_transferin((void *) 0, 0, pAuto3646);
		if (!( pAuto3646 )) _Context->value_Auto3646=0;
		else	_Context->value_Auto3646 = *((int *)pAuto3646);
		visual_transferin((void *) 0, 0, pRestrict);
		if (!( pRestrict )) _Context->value_Restrict=0;
		else	_Context->value_Restrict = *((int *)pRestrict);
		visual_transferin((void *) 0, 0, pInhibit);
		if (!( pInhibit )) _Context->value_Inhibit=0;
		else	_Context->value_Inhibit = *((int *)pInhibit);
		visual_transferin((void *) 0, 0, pWithStyle);
		if (!( pWithStyle )) _Context->value_WithStyle=0;
		else	_Context->value_WithStyle = *((int *)pWithStyle);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3643[i]=" ";
	_Context->hint_Auto3643[0]=en__Auto3643;
	_Context->hint_Auto3643[1]=fr__Auto3643;
	_Context->hint_Auto3643[2]=it__Auto3643;
	_Context->hint_Auto3643[3]=es__Auto3643;
	_Context->hint_Auto3643[4]=de__Auto3643;
	_Context->hint_Auto3643[5]=nl__Auto3643;
	_Context->hint_Auto3643[6]=pt__Auto3643;
	_Context->hint_Auto3643[7]=xx__Auto3643;
	_Context->x_Auto3643=100;
	_Context->y_Auto3643=165;
	_Context->w_Auto3643=600;
	_Context->h_Auto3643=270;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3644[i]=" ";
	_Context->msg_Auto3644[0]=en_Auto3644;
	_Context->hint_Auto3644[0]=en__Auto3644;
	for (i=0; i < 8; i++)_Context->msg_Auto3645[i]=" ";
	_Context->msg_Auto3645[0]=en_Auto3645;
	_Context->hint_Auto3645[0]=en__Auto3645;
	_Context->hint_FileStub[0]=en__FileStub;
	_Context->hint_SoapHost[0]=en__SoapHost;
	for (i=0; i < 8; i++)_Context->msg_WebAgent[i]=" ";
	_Context->msg_WebAgent[0]=en_WebAgent;
	_Context->hint_WebAgent[0]=en__WebAgent;
	for (i=0; i < 8; i++)_Context->msg_Auto3646[i]=" ";
	_Context->msg_Auto3646[0]=en_Auto3646;
	_Context->hint_Auto3646[0]=en__Auto3646;
	for (i=0; i < 8; i++)_Context->msg_Restrict[i]=" ";
	_Context->msg_Restrict[0]=en_Restrict;
	_Context->hint_Restrict[0]=en__Restrict;
	for (i=0; i < 8; i++)_Context->msg_Inhibit[i]=" ";
	_Context->msg_Inhibit[0]=en_Inhibit;
	_Context->hint_Inhibit[0]=en__Inhibit;
	for (i=0; i < 8; i++)_Context->msg_WithStyle[i]=" ";
	_Context->msg_WithStyle[0]=en_WithStyle;
	_Context->hint_WithStyle[0]=en__WithStyle;
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
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3643,_Context->y_Auto3643,600+10,270+10);
	return(0);
}

public 	int	accept_php_production_hide(struct accept_php_production_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3643,_Context->y_Auto3643);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_php_production_remove(
	struct accept_php_production_context * _Context,
	char * pFileStub,
	char * pSoapHost,
	char * pWebAgent,
	char * pAuto3646,
	char * pRestrict,
	char * pInhibit,
	char * pWithStyle)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileStub, 255, pFileStub);
		visual_transferout(_Context->buffer_SoapHost, 255, pSoapHost);
		visual_transferout((void *) 0, 0, pWebAgent);
		if ( pWebAgent != (char *) 0)
			*((int*)pWebAgent) = _Context->value_WebAgent;
		visual_transferout((void *) 0, 0, pAuto3646);
		if ( pAuto3646 != (char *) 0)
			*((int*)pAuto3646) = _Context->value_Auto3646;
		visual_transferout((void *) 0, 0, pRestrict);
		if ( pRestrict != (char *) 0)
			*((int*)pRestrict) = _Context->value_Restrict;
		visual_transferout((void *) 0, 0, pInhibit);
		if ( pInhibit != (char *) 0)
			*((int*)pInhibit) = _Context->value_Inhibit;
		visual_transferout((void *) 0, 0, pWithStyle);
		if ( pWithStyle != (char *) 0)
			*((int*)pWithStyle) = _Context->value_WithStyle;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_php_production_show(struct accept_php_production_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3643,_Context->y_Auto3643);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3643,_Context->y_Auto3643,600,270,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3643,_Context->y_Auto3643,600,270,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto3643+30,_Context->y_Auto3643+50,532,16,vfh[2],16,0,_Context->msg_Auto3644[_Context->language],strlen(_Context->msg_Auto3644[_Context->language]),258);
	visual_text(_Context->x_Auto3643+30,_Context->y_Auto3643+90,532,16,vfh[2],16,0,_Context->msg_Auto3645[_Context->language],strlen(_Context->msg_Auto3645[_Context->language]),258);
	visual_frame(_Context->x_Auto3643+30,_Context->y_Auto3643+70,536+2,16+2,5);
	visual_text(_Context->x_Auto3643+30+1,_Context->y_Auto3643+70+1,536,16,vfh[1],16,0,_Context->buffer_FileStub,255,0);
	visual_frame(_Context->x_Auto3643+30,_Context->y_Auto3643+110,536+2,16+2,5);
	visual_text(_Context->x_Auto3643+30+1,_Context->y_Auto3643+110+1,536,16,vfh[1],16,0,_Context->buffer_SoapHost,255,0);
	_Context->trigger_WebAgent=visual_trigger_code(_Context->msg_WebAgent[_Context->language],strlen(_Context->msg_WebAgent[_Context->language]));
	visual_check(_Context->x_Auto3643+200,_Context->y_Auto3643+150,216,16,vfh[2],16,28,_Context->msg_WebAgent[_Context->language],strlen(_Context->msg_WebAgent[_Context->language]),_Context->value_WebAgent|0);
	_Context->trigger_Auto3646=visual_trigger_code(_Context->msg_Auto3646[_Context->language],strlen(_Context->msg_Auto3646[_Context->language]));
	visual_check(_Context->x_Auto3643+200,_Context->y_Auto3643+170,216,16,vfh[2],16,28,_Context->msg_Auto3646[_Context->language],strlen(_Context->msg_Auto3646[_Context->language]),_Context->value_Auto3646|0);
	_Context->trigger_Restrict=visual_trigger_code(_Context->msg_Restrict[_Context->language],strlen(_Context->msg_Restrict[_Context->language]));
	visual_check(_Context->x_Auto3643+200,_Context->y_Auto3643+190,210,16,vfh[2],16,28,_Context->msg_Restrict[_Context->language],strlen(_Context->msg_Restrict[_Context->language]),_Context->value_Restrict|0);
	_Context->trigger_Inhibit=visual_trigger_code(_Context->msg_Inhibit[_Context->language],strlen(_Context->msg_Inhibit[_Context->language]));
	visual_check(_Context->x_Auto3643+200,_Context->y_Auto3643+210,210,16,vfh[2],16,28,_Context->msg_Inhibit[_Context->language],strlen(_Context->msg_Inhibit[_Context->language]),_Context->value_Inhibit|0);
	_Context->trigger_WithStyle=visual_trigger_code(_Context->msg_WithStyle[_Context->language],strlen(_Context->msg_WithStyle[_Context->language]));
	visual_check(_Context->x_Auto3643+200,_Context->y_Auto3643+230,210,16,vfh[2],16,28,_Context->msg_WithStyle[_Context->language],strlen(_Context->msg_WithStyle[_Context->language]),_Context->value_WithStyle|0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3643+30,_Context->y_Auto3643+200,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3643+510,_Context->y_Auto3643+200,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3643,_Context->y_Auto3643,600,270);

	return(0);
}

private int Auto3643action(struct accept_php_production_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_php_production_hide(_Context);

		_Context->x_Auto3643 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3643 < 0) { _Context->x_Auto3643=0; }
		_Context->y_Auto3643 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3643 < 0) { _Context->y_Auto3643=0; }
			accept_php_production_show(_Context);

		visual_thaw(_Context->x_Auto3643,_Context->y_Auto3643,600,270);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_php_production_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_php_production_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_php_production_event(
struct accept_php_production_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_WebAgent == mb ) return(3);
		if (_Context->trigger_Auto3646 == mb ) return(4);
		if (_Context->trigger_Restrict == mb ) return(5);
		if (_Context->trigger_Inhibit == mb ) return(6);
		if (_Context->trigger_WithStyle == mb ) return(7);
		if (_Context->trigger_Accept == mb ) return(8);
		if (_Context->trigger_Cancel == mb ) return(9);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_Auto3643+30) ) 
	&&  ( my >= (_Context->y_Auto3643+70) ) 
	&&  ( mx <= (_Context->x_Auto3643+30+536) ) 
	&&  ( my <= (_Context->y_Auto3643+70+16))) {
		return(1); /* FileStub */
		}
	if (( mx >= (_Context->x_Auto3643+30) ) 
	&&  ( my >= (_Context->y_Auto3643+110) ) 
	&&  ( mx <= (_Context->x_Auto3643+30+536) ) 
	&&  ( my <= (_Context->y_Auto3643+110+16))) {
		return(2); /* SoapHost */
		}
	if (( mx >= (_Context->x_Auto3643+200) ) 
	&&  ( my >= (_Context->y_Auto3643+150) ) 
	&&  ( mx <= (_Context->x_Auto3643+200+216) ) 
	&&  ( my <= (_Context->y_Auto3643+150+16))) {
		return(3); /* WebAgent */
		}
	if (( mx >= (_Context->x_Auto3643+200) ) 
	&&  ( my >= (_Context->y_Auto3643+170) ) 
	&&  ( mx <= (_Context->x_Auto3643+200+216) ) 
	&&  ( my <= (_Context->y_Auto3643+170+16))) {
		return(4); /* Auto3646 */
		}
	if (( mx >= (_Context->x_Auto3643+200) ) 
	&&  ( my >= (_Context->y_Auto3643+190) ) 
	&&  ( mx <= (_Context->x_Auto3643+200+210) ) 
	&&  ( my <= (_Context->y_Auto3643+190+16))) {
		return(5); /* Restrict */
		}
	if (( mx >= (_Context->x_Auto3643+200) ) 
	&&  ( my >= (_Context->y_Auto3643+210) ) 
	&&  ( mx <= (_Context->x_Auto3643+200+210) ) 
	&&  ( my <= (_Context->y_Auto3643+210+16))) {
		return(6); /* Inhibit */
		}
	if (( mx >= (_Context->x_Auto3643+200) ) 
	&&  ( my >= (_Context->y_Auto3643+230) ) 
	&&  ( mx <= (_Context->x_Auto3643+200+210) ) 
	&&  ( my <= (_Context->y_Auto3643+230+16))) {
		return(7); /* WithStyle */
		}
	if (( mx >= (_Context->x_Auto3643+30) ) 
	&&  ( my >= (_Context->y_Auto3643+200) ) 
	&&  ( mx <= (_Context->x_Auto3643+30+56) ) 
	&&  ( my <= (_Context->y_Auto3643+200+48))) {
		return(8); /* Accept */
		}
	if (( mx >= (_Context->x_Auto3643+510) ) 
	&&  ( my >= (_Context->y_Auto3643+200) ) 
	&&  ( mx <= (_Context->x_Auto3643+510+56) ) 
	&&  ( my <= (_Context->y_Auto3643+200+48))) {
		return(9); /* Cancel */
		}

	return(-1);
}


public	int	accept_php_production_focus(struct accept_php_production_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* FileStub */
				_Context->keycode = visual_edit(_Context->x_Auto3643+30+1,_Context->y_Auto3643+70+1,536,16,vfh[1],_Context->buffer_FileStub,255);
			break;
			case	0x2 :
				/* SoapHost */
				_Context->keycode = visual_edit(_Context->x_Auto3643+30+1,_Context->y_Auto3643+110+1,536,16,vfh[1],_Context->buffer_SoapHost,255);
			break;
			case	0x3 :
				/* WebAgent */
				visual_check(_Context->x_Auto3643+200,_Context->y_Auto3643+150,216,16,vfh[2],16,28,_Context->msg_WebAgent[_Context->language],strlen(_Context->msg_WebAgent[_Context->language]),(_Context->value_WebAgent |2));
				_Context->keycode = visual_getch();
				_Context->trigger_WebAgent=visual_trigger_code(_Context->msg_WebAgent[_Context->language],strlen(_Context->msg_WebAgent[_Context->language]));
	visual_check(_Context->x_Auto3643+200,_Context->y_Auto3643+150,216,16,vfh[2],16,28,_Context->msg_WebAgent[_Context->language],strlen(_Context->msg_WebAgent[_Context->language]),_Context->value_WebAgent|0);
				break;
			case	0x4 :
				/* Auto3646 */
				visual_check(_Context->x_Auto3643+200,_Context->y_Auto3643+170,216,16,vfh[2],16,28,_Context->msg_Auto3646[_Context->language],strlen(_Context->msg_Auto3646[_Context->language]),(_Context->value_Auto3646 |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3646=visual_trigger_code(_Context->msg_Auto3646[_Context->language],strlen(_Context->msg_Auto3646[_Context->language]));
	visual_check(_Context->x_Auto3643+200,_Context->y_Auto3643+170,216,16,vfh[2],16,28,_Context->msg_Auto3646[_Context->language],strlen(_Context->msg_Auto3646[_Context->language]),_Context->value_Auto3646|0);
				break;
			case	0x5 :
				/* Restrict */
				visual_check(_Context->x_Auto3643+200,_Context->y_Auto3643+190,210,16,vfh[2],16,28,_Context->msg_Restrict[_Context->language],strlen(_Context->msg_Restrict[_Context->language]),(_Context->value_Restrict |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Restrict=visual_trigger_code(_Context->msg_Restrict[_Context->language],strlen(_Context->msg_Restrict[_Context->language]));
	visual_check(_Context->x_Auto3643+200,_Context->y_Auto3643+190,210,16,vfh[2],16,28,_Context->msg_Restrict[_Context->language],strlen(_Context->msg_Restrict[_Context->language]),_Context->value_Restrict|0);
				break;
			case	0x6 :
				/* Inhibit */
				visual_check(_Context->x_Auto3643+200,_Context->y_Auto3643+210,210,16,vfh[2],16,28,_Context->msg_Inhibit[_Context->language],strlen(_Context->msg_Inhibit[_Context->language]),(_Context->value_Inhibit |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Inhibit=visual_trigger_code(_Context->msg_Inhibit[_Context->language],strlen(_Context->msg_Inhibit[_Context->language]));
	visual_check(_Context->x_Auto3643+200,_Context->y_Auto3643+210,210,16,vfh[2],16,28,_Context->msg_Inhibit[_Context->language],strlen(_Context->msg_Inhibit[_Context->language]),_Context->value_Inhibit|0);
				break;
			case	0x7 :
				/* WithStyle */
				visual_check(_Context->x_Auto3643+200,_Context->y_Auto3643+230,210,16,vfh[2],16,28,_Context->msg_WithStyle[_Context->language],strlen(_Context->msg_WithStyle[_Context->language]),(_Context->value_WithStyle |2));
				_Context->keycode = visual_getch();
				_Context->trigger_WithStyle=visual_trigger_code(_Context->msg_WithStyle[_Context->language],strlen(_Context->msg_WithStyle[_Context->language]));
	visual_check(_Context->x_Auto3643+200,_Context->y_Auto3643+230,210,16,vfh[2],16,28,_Context->msg_WithStyle[_Context->language],strlen(_Context->msg_WithStyle[_Context->language]),_Context->value_WithStyle|0);
				break;
			case	0x8 :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(_Context->x_Auto3643+30,_Context->y_Auto3643+200,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3643+30,_Context->y_Auto3643+200,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0x9 :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_Auto3643+510,_Context->y_Auto3643+200,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3643+510,_Context->y_Auto3643+200,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_php_production_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=9;
			accept_php_production_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_php_production_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* FileStub */
					continue;
				case	0x2 :
					/* SoapHost */
					continue;
				case	0x3 :
					/* WebAgent */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_WebAgent += 1;
						_Context->value_WebAgent &= 1;
						}
					continue;
				case	0x4 :
					/* Auto3646 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Auto3646 += 1;
						_Context->value_Auto3646 &= 1;
						}
					continue;
				case	0x5 :
					/* Restrict */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Restrict += 1;
						_Context->value_Restrict &= 1;
						}
					continue;
				case	0x6 :
					/* Inhibit */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Inhibit += 1;
						_Context->value_Inhibit &= 1;
						}
					continue;
				case	0x7 :
					/* WithStyle */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_WithStyle += 1;
						_Context->value_WithStyle &= 1;
						}
					continue;
				case	0x8 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_Auto3643+30,_Context->y_Auto3643+200,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3643+30,_Context->y_Auto3643+200,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Auto3643+510,_Context->y_Auto3643+200,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3643+510,_Context->y_Auto3643+200,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
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
				_Context->focus_item=9;
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

public	int	accept_php_production(
	char * pFileStub,
	char * pSoapHost,
	char * pWebAgent,
	char * pAuto3646,
	char * pRestrict,
	char * pInhibit,
	char * pWithStyle)
{
	int	status=0;
	struct accept_php_production_context * _Context=(struct accept_php_production_context*) 0;
	status = accept_php_production_create(
	&_Context,
	 pFileStub,
	 pSoapHost,
	 pWebAgent,
	 pAuto3646,
	 pRestrict,
	 pInhibit,
	 pWithStyle);
	if ( status != 0) return(status);
	status = accept_php_production_show(_Context);
		enter_modal();
	status = accept_php_production_focus(_Context);
		leave_modal();
	status = accept_php_production_hide(_Context);
	status = accept_php_production_remove(
	_Context,
	 pFileStub,
	 pSoapHost,
	 pWebAgent,
	 pAuto3646,
	 pRestrict,
	 pInhibit,
	 pWithStyle);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vphp_c */
