
#ifndef _vwsgen_c
#define _vwsgen_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vwsgen.xml                                               */
/* Target         : vwsgen.c                                                 */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en__Auto3642   ""
#define fr__Auto3642   ""
#define it__Auto3642   ""
#define es__Auto3642   ""
#define de__Auto3642   ""
#define nl__Auto3642   ""
#define pt__Auto3642   ""
#define xx__Auto3642   ""
#define en_Accept   "ok.gif"
#define fr_Accept   "ok.gif"
#define it_Accept   "ok.gif"
#define es_Accept   "ok.gif"
#define de_Accept   "ok.gif"
#define nl_Accept   "ok.gif"
#define pt_Accept   "ok.gif"
#define xx_Accept   "ok.gif"
#define en__Accept   ""
#define en_Auto3643   "Web Service Generation Parameters"
#define en__Auto3643   ""
#define en_Auto3644   "Site Url"
#define en__Auto3644   ""
#define en_Auto3645   "Web Service Filename"
#define en__Auto3645   ""
#define en_Auto3646   "Agent Filename"
#define en__Auto3646   ""
#define en_Auto3647   "Server Component"
#define en__Auto3647   ""
#define en_Auto3648   "Client Component"
#define en__Auto3648   ""
#define en_Auto3649   "Interface Description"
#define en__Auto3649   ""
#define en_Url   ""
#define en__Url   ""
#define en_WsName   ""
#define en__WsName   ""
#define en_AgentName   ""
#define en__AgentName   ""
#define en_GenWs   "Inhibited|Wasp|PHP"
#define en__GenWs   ""
#define en_GenAgent   "None|LSL|Html"
#define en__GenAgent   ""
#define en_GenFace   "None|WSI|Wsdl"
#define en__GenFace   ""
#define en_DoMenu   "Generate Menu"
#define en__DoMenu   ""
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"
#define en__Cancel   ""

private struct vwsgen_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3642[8];
	char * hint_Auto3642[8];
	int	x_Auto3642;
	int	y_Auto3642;
	int	w_Auto3642;
	int	h_Auto3642;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Auto3643[8];
	char * hint_Auto3643[8];
	char * msg_Auto3644[8];
	char * hint_Auto3644[8];
	char * msg_Auto3645[8];
	char * hint_Auto3645[8];
	char * msg_Auto3646[8];
	char * hint_Auto3646[8];
	char * msg_Auto3647[8];
	char * hint_Auto3647[8];
	char * msg_Auto3648[8];
	char * hint_Auto3648[8];
	char * msg_Auto3649[8];
	char * hint_Auto3649[8];
	char * hint_Url[8];
	char	buffer_Url[256];
	char * hint_WsName[8];
	char	buffer_WsName[256];
	char * hint_AgentName[8];
	char	buffer_AgentName[256];
	char * msg_GenWs[8];
	char * hint_GenWs[8];
	int	value_GenWs;
	char * msg_GenAgent[8];
	char * hint_GenAgent[8];
	int	value_GenAgent;
	char * msg_GenFace[8];
	char * hint_GenFace[8];
	int	value_GenFace;
	char * msg_DoMenu[8];
	int	trigger_DoMenu;
	char * hint_DoMenu[8];
	int	value_DoMenu;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[8];
	};
static int	vfh[16];
private int on_Accept_event(struct vwsgen_context * _Context);
private int on_Cancel_event(struct vwsgen_context * _Context);

public	int	vwsgen_create(
	struct vwsgen_context ** cptr,
	char * pUrl,
	char * pWsName,
	char * pAgentName,
	char * pGenWs,
	char * pGenAgent,
	char * pGenFace,
	char * pDoMenu)
{

	int i;
	struct vwsgen_context * _Context=(struct vwsgen_context*)0;
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
	if (!(_Context = allocate( sizeof( struct vwsgen_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=9;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Url, 255, pUrl);
		visual_transferin(_Context->buffer_WsName, 255, pWsName);
		visual_transferin(_Context->buffer_AgentName, 255, pAgentName);
		visual_transferin((void *) 0, 0, pGenWs);
		if (!( pGenWs )) _Context->value_GenWs=0;
		else	_Context->value_GenWs = *((int *)pGenWs);
		visual_transferin((void *) 0, 0, pGenAgent);
		if (!( pGenAgent )) _Context->value_GenAgent=0;
		else	_Context->value_GenAgent = *((int *)pGenAgent);
		visual_transferin((void *) 0, 0, pGenFace);
		if (!( pGenFace )) _Context->value_GenFace=0;
		else	_Context->value_GenFace = *((int *)pGenFace);
		visual_transferin((void *) 0, 0, pDoMenu);
		if (!( pDoMenu )) _Context->value_DoMenu=0;
		else	_Context->value_DoMenu = *((int *)pDoMenu);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3642[i]=" ";
	_Context->hint_Auto3642[0]=en__Auto3642;
	_Context->hint_Auto3642[1]=fr__Auto3642;
	_Context->hint_Auto3642[2]=it__Auto3642;
	_Context->hint_Auto3642[3]=es__Auto3642;
	_Context->hint_Auto3642[4]=de__Auto3642;
	_Context->hint_Auto3642[5]=nl__Auto3642;
	_Context->hint_Auto3642[6]=pt__Auto3642;
	_Context->hint_Auto3642[7]=xx__Auto3642;
	_Context->x_Auto3642=90;
	_Context->y_Auto3642=80;
	_Context->w_Auto3642=620;
	_Context->h_Auto3642=440;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3643[i]=" ";
	_Context->msg_Auto3643[0]=en_Auto3643;
	_Context->hint_Auto3643[0]=en__Auto3643;
	for (i=0; i < 8; i++)_Context->msg_Auto3644[i]=" ";
	_Context->msg_Auto3644[0]=en_Auto3644;
	_Context->hint_Auto3644[0]=en__Auto3644;
	for (i=0; i < 8; i++)_Context->msg_Auto3645[i]=" ";
	_Context->msg_Auto3645[0]=en_Auto3645;
	_Context->hint_Auto3645[0]=en__Auto3645;
	for (i=0; i < 8; i++)_Context->msg_Auto3646[i]=" ";
	_Context->msg_Auto3646[0]=en_Auto3646;
	_Context->hint_Auto3646[0]=en__Auto3646;
	for (i=0; i < 8; i++)_Context->msg_Auto3647[i]=" ";
	_Context->msg_Auto3647[0]=en_Auto3647;
	_Context->hint_Auto3647[0]=en__Auto3647;
	for (i=0; i < 8; i++)_Context->msg_Auto3648[i]=" ";
	_Context->msg_Auto3648[0]=en_Auto3648;
	_Context->hint_Auto3648[0]=en__Auto3648;
	for (i=0; i < 8; i++)_Context->msg_Auto3649[i]=" ";
	_Context->msg_Auto3649[0]=en_Auto3649;
	_Context->hint_Auto3649[0]=en__Auto3649;
	_Context->hint_Url[0]=en__Url;
	_Context->hint_WsName[0]=en__WsName;
	_Context->hint_AgentName[0]=en__AgentName;
	for (i=0; i < 8; i++)_Context->msg_GenWs[i]=" ";
	_Context->msg_GenWs[0]=en_GenWs;
	_Context->hint_GenWs[0]=en__GenWs;
	for (i=0; i < 8; i++)_Context->msg_GenAgent[i]=" ";
	_Context->msg_GenAgent[0]=en_GenAgent;
	_Context->hint_GenAgent[0]=en__GenAgent;
	for (i=0; i < 8; i++)_Context->msg_GenFace[i]=" ";
	_Context->msg_GenFace[0]=en_GenFace;
	_Context->hint_GenFace[0]=en__GenFace;
	for (i=0; i < 8; i++)_Context->msg_DoMenu[i]=" ";
	_Context->msg_DoMenu[0]=en_DoMenu;
	_Context->hint_DoMenu[0]=en__DoMenu;
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
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3642,_Context->y_Auto3642,620+10,440+10);
	return(0);
}

public 	int	vwsgen_hide(struct vwsgen_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3642,_Context->y_Auto3642);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	vwsgen_remove(
	struct vwsgen_context * _Context,
	char * pUrl,
	char * pWsName,
	char * pAgentName,
	char * pGenWs,
	char * pGenAgent,
	char * pGenFace,
	char * pDoMenu)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Url, 255, pUrl);
		visual_transferout(_Context->buffer_WsName, 255, pWsName);
		visual_transferout(_Context->buffer_AgentName, 255, pAgentName);
		visual_transferout((void *) 0, 0, pGenWs);
		if ( pGenWs != (char *) 0)
			*((int*)pGenWs) = _Context->value_GenWs;
		visual_transferout((void *) 0, 0, pGenAgent);
		if ( pGenAgent != (char *) 0)
			*((int*)pGenAgent) = _Context->value_GenAgent;
		visual_transferout((void *) 0, 0, pGenFace);
		if ( pGenFace != (char *) 0)
			*((int*)pGenFace) = _Context->value_GenFace;
		visual_transferout((void *) 0, 0, pDoMenu);
		if ( pDoMenu != (char *) 0)
			*((int*)pDoMenu) = _Context->value_DoMenu;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	vwsgen_show(struct vwsgen_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3642,_Context->y_Auto3642);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3642,_Context->y_Auto3642,620,440,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3642,_Context->y_Auto3642,620,440,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3642+30,_Context->y_Auto3642+370,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	if (((_Context->status = visual_styled_element(_Context->x_Auto3642+30,_Context->y_Auto3642+50,560,30,"sing/widget_help_text",_Context->msg_Auto3643[_Context->language],strlen(_Context->msg_Auto3643[_Context->language]))) != 0)
) {
		visual_text(_Context->x_Auto3642+30,_Context->y_Auto3642+50,560,30,vfh[1],27,28,_Context->msg_Auto3643[_Context->language],strlen(_Context->msg_Auto3643[_Context->language]),0);
		}
	if (((_Context->status = visual_styled_element(_Context->x_Auto3642+30,_Context->y_Auto3642+110,568,32,"sing/control_help_label",_Context->msg_Auto3644[_Context->language],strlen(_Context->msg_Auto3644[_Context->language]))) != 0)
) {
		visual_text(_Context->x_Auto3642+30,_Context->y_Auto3642+110,568,32,vfh[1],27,28,_Context->msg_Auto3644[_Context->language],strlen(_Context->msg_Auto3644[_Context->language]),0);
		}
	if (((_Context->status = visual_styled_element(_Context->x_Auto3642+30,_Context->y_Auto3642+170,568,32,"sing/control_help_label",_Context->msg_Auto3645[_Context->language],strlen(_Context->msg_Auto3645[_Context->language]))) != 0)
) {
		visual_text(_Context->x_Auto3642+30,_Context->y_Auto3642+170,568,32,vfh[1],27,28,_Context->msg_Auto3645[_Context->language],strlen(_Context->msg_Auto3645[_Context->language]),0);
		}
	if (((_Context->status = visual_styled_element(_Context->x_Auto3642+30,_Context->y_Auto3642+230,568,32,"sing/control_help_label",_Context->msg_Auto3646[_Context->language],strlen(_Context->msg_Auto3646[_Context->language]))) != 0)
) {
		visual_text(_Context->x_Auto3642+30,_Context->y_Auto3642+230,568,32,vfh[1],27,28,_Context->msg_Auto3646[_Context->language],strlen(_Context->msg_Auto3646[_Context->language]),0);
		}
	if (((_Context->status = visual_styled_element(_Context->x_Auto3642+30,_Context->y_Auto3642+290,184,32,"sing/control_help_label",_Context->msg_Auto3647[_Context->language],strlen(_Context->msg_Auto3647[_Context->language]))) != 0)
) {
		visual_text(_Context->x_Auto3642+30,_Context->y_Auto3642+290,184,32,vfh[1],27,28,_Context->msg_Auto3647[_Context->language],strlen(_Context->msg_Auto3647[_Context->language]),0);
		}
	if (((_Context->status = visual_styled_element(_Context->x_Auto3642+220,_Context->y_Auto3642+290,184,32,"sing/control_help_label",_Context->msg_Auto3648[_Context->language],strlen(_Context->msg_Auto3648[_Context->language]))) != 0)
) {
		visual_text(_Context->x_Auto3642+220,_Context->y_Auto3642+290,184,32,vfh[1],27,28,_Context->msg_Auto3648[_Context->language],strlen(_Context->msg_Auto3648[_Context->language]),0);
		}
	if (((_Context->status = visual_styled_element(_Context->x_Auto3642+410,_Context->y_Auto3642+290,184,32,"sing/control_help_label",_Context->msg_Auto3649[_Context->language],strlen(_Context->msg_Auto3649[_Context->language]))) != 0)
) {
		visual_text(_Context->x_Auto3642+410,_Context->y_Auto3642+290,184,32,vfh[1],27,28,_Context->msg_Auto3649[_Context->language],strlen(_Context->msg_Auto3649[_Context->language]),0);
		}
	visual_frame(_Context->x_Auto3642+30,_Context->y_Auto3642+140,568+2,16+2,5);
	visual_text(_Context->x_Auto3642+30+1,_Context->y_Auto3642+140+1,568,16,vfh[1],27,28,_Context->buffer_Url,255,0);
	visual_frame(_Context->x_Auto3642+30,_Context->y_Auto3642+200,568+2,16+2,5);
	visual_text(_Context->x_Auto3642+30+1,_Context->y_Auto3642+200+1,568,16,vfh[1],27,28,_Context->buffer_WsName,255,0);
	visual_frame(_Context->x_Auto3642+30,_Context->y_Auto3642+260,568+2,16+2,5);
	visual_text(_Context->x_Auto3642+30+1,_Context->y_Auto3642+260+1,568,16,vfh[1],27,28,_Context->buffer_AgentName,255,0);
	visual_select(_Context->x_Auto3642+30,_Context->y_Auto3642+320,184,80,vfh[1],0,0,parse_selection(_Context->msg_GenWs[_Context->language],&_Context->value_GenWs),0);
	visual_select(_Context->x_Auto3642+220,_Context->y_Auto3642+320,184,80,vfh[1],0,0,parse_selection(_Context->msg_GenAgent[_Context->language],&_Context->value_GenAgent),0);
	visual_select(_Context->x_Auto3642+410,_Context->y_Auto3642+320,184,80,vfh[1],0,0,parse_selection(_Context->msg_GenFace[_Context->language],&_Context->value_GenFace),0);
	_Context->trigger_DoMenu=visual_trigger_code(_Context->msg_DoMenu[_Context->language],strlen(_Context->msg_DoMenu[_Context->language]));
	visual_check(_Context->x_Auto3642+220,_Context->y_Auto3642+360,144,16,vfh[2],16,28,_Context->msg_DoMenu[_Context->language],strlen(_Context->msg_DoMenu[_Context->language]),_Context->value_DoMenu|0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3642+530,_Context->y_Auto3642+370,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3642,_Context->y_Auto3642,620,440);

	return(0);
}

private int Auto3642action(struct vwsgen_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			vwsgen_hide(_Context);

		_Context->x_Auto3642 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3642 < 0) { _Context->x_Auto3642=0; }
		_Context->y_Auto3642 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3642 < 0) { _Context->y_Auto3642=0; }
			vwsgen_show(_Context);

		visual_thaw(_Context->x_Auto3642,_Context->y_Auto3642,620,440);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct vwsgen_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct vwsgen_context * _Context) {
	return(27);
	return(-1);
}


public	int	vwsgen_event(
struct vwsgen_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(1);
		if (_Context->trigger_DoMenu == mb ) return(8);
		if (_Context->trigger_Cancel == mb ) return(9);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_Auto3642+30) ) 
	&&  ( my >= (_Context->y_Auto3642+370) ) 
	&&  ( mx <= (_Context->x_Auto3642+30+56) ) 
	&&  ( my <= (_Context->y_Auto3642+370+48))) {
		return(1); /* Accept */
		}
	if (( mx >= (_Context->x_Auto3642+30) ) 
	&&  ( my >= (_Context->y_Auto3642+140) ) 
	&&  ( mx <= (_Context->x_Auto3642+30+568) ) 
	&&  ( my <= (_Context->y_Auto3642+140+16))) {
		return(2); /* Url */
		}
	if (( mx >= (_Context->x_Auto3642+30) ) 
	&&  ( my >= (_Context->y_Auto3642+200) ) 
	&&  ( mx <= (_Context->x_Auto3642+30+568) ) 
	&&  ( my <= (_Context->y_Auto3642+200+16))) {
		return(3); /* WsName */
		}
	if (( mx >= (_Context->x_Auto3642+30) ) 
	&&  ( my >= (_Context->y_Auto3642+260) ) 
	&&  ( mx <= (_Context->x_Auto3642+30+568) ) 
	&&  ( my <= (_Context->y_Auto3642+260+16))) {
		return(4); /* AgentName */
		}
	if (( mx >= (_Context->x_Auto3642+30+0) ) 
	&&  ( my >= (_Context->y_Auto3642+320) ) 
	&&  ( mx <= (_Context->x_Auto3642+30+184) ) 
	&&  ( my <= (_Context->y_Auto3642+320+16))) {
		return(5); /* GenWs */
		}
	if (( mx >= (_Context->x_Auto3642+220+0) ) 
	&&  ( my >= (_Context->y_Auto3642+320) ) 
	&&  ( mx <= (_Context->x_Auto3642+220+184) ) 
	&&  ( my <= (_Context->y_Auto3642+320+16))) {
		return(6); /* GenAgent */
		}
	if (( mx >= (_Context->x_Auto3642+410+0) ) 
	&&  ( my >= (_Context->y_Auto3642+320) ) 
	&&  ( mx <= (_Context->x_Auto3642+410+184) ) 
	&&  ( my <= (_Context->y_Auto3642+320+16))) {
		return(7); /* GenFace */
		}
	if (( mx >= (_Context->x_Auto3642+220) ) 
	&&  ( my >= (_Context->y_Auto3642+360) ) 
	&&  ( mx <= (_Context->x_Auto3642+220+144) ) 
	&&  ( my <= (_Context->y_Auto3642+360+16))) {
		return(8); /* DoMenu */
		}
	if (( mx >= (_Context->x_Auto3642+530) ) 
	&&  ( my >= (_Context->y_Auto3642+370) ) 
	&&  ( mx <= (_Context->x_Auto3642+530+56) ) 
	&&  ( my <= (_Context->y_Auto3642+370+48))) {
		return(9); /* Cancel */
		}

	return(-1);
}


public	int	vwsgen_focus(struct vwsgen_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(_Context->x_Auto3642+30,_Context->y_Auto3642+370,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3642+30,_Context->y_Auto3642+370,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0x2 :
				/* Url */
				_Context->keycode = visual_edit(_Context->x_Auto3642+30+1,_Context->y_Auto3642+140+1,568,16,vfh[1],_Context->buffer_Url,255);
			break;
			case	0x3 :
				/* WsName */
				_Context->keycode = visual_edit(_Context->x_Auto3642+30+1,_Context->y_Auto3642+200+1,568,16,vfh[1],_Context->buffer_WsName,255);
			break;
			case	0x4 :
				/* AgentName */
				_Context->keycode = visual_edit(_Context->x_Auto3642+30+1,_Context->y_Auto3642+260+1,568,16,vfh[1],_Context->buffer_AgentName,255);
			break;
			case	0x5 :
				/* GenWs */
				_Context->keycode = visual_select(_Context->x_Auto3642+30,_Context->y_Auto3642+320,184,80,vfh[1],0,0,parse_selection(_Context->msg_GenWs[_Context->language],&_Context->value_GenWs),2);
				break;
			case	0x6 :
				/* GenAgent */
				_Context->keycode = visual_select(_Context->x_Auto3642+220,_Context->y_Auto3642+320,184,80,vfh[1],0,0,parse_selection(_Context->msg_GenAgent[_Context->language],&_Context->value_GenAgent),2);
				break;
			case	0x7 :
				/* GenFace */
				_Context->keycode = visual_select(_Context->x_Auto3642+410,_Context->y_Auto3642+320,184,80,vfh[1],0,0,parse_selection(_Context->msg_GenFace[_Context->language],&_Context->value_GenFace),2);
				break;
			case	0x8 :
				/* DoMenu */
				visual_check(_Context->x_Auto3642+220,_Context->y_Auto3642+360,144,16,vfh[2],16,28,_Context->msg_DoMenu[_Context->language],strlen(_Context->msg_DoMenu[_Context->language]),(_Context->value_DoMenu |2));
				_Context->keycode = visual_getch();
				_Context->trigger_DoMenu=visual_trigger_code(_Context->msg_DoMenu[_Context->language],strlen(_Context->msg_DoMenu[_Context->language]));
	visual_check(_Context->x_Auto3642+220,_Context->y_Auto3642+360,144,16,vfh[2],16,28,_Context->msg_DoMenu[_Context->language],strlen(_Context->msg_DoMenu[_Context->language]),_Context->value_DoMenu|0);
				break;
			case	0x9 :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_Auto3642+530,_Context->y_Auto3642+370,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3642+530,_Context->y_Auto3642+370,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			vwsgen_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=9;
			vwsgen_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=vwsgen_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_Auto3642+30,_Context->y_Auto3642+370,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3642+30,_Context->y_Auto3642+370,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x2 :
					/* Url */
					continue;
				case	0x3 :
					/* WsName */
					continue;
				case	0x4 :
					/* AgentName */
					continue;
				case	0x5 :
					/* GenWs */
					continue;
				case	0x6 :
					/* GenAgent */
					continue;
				case	0x7 :
					/* GenFace */
					continue;
				case	0x8 :
					/* DoMenu */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_DoMenu += 1;
						_Context->value_DoMenu &= 1;
						}
					continue;
				case	0x9 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Auto3642+530,_Context->y_Auto3642+370,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3642+530,_Context->y_Auto3642+370,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
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

public	int	vwsgen(
	char * pUrl,
	char * pWsName,
	char * pAgentName,
	char * pGenWs,
	char * pGenAgent,
	char * pGenFace,
	char * pDoMenu)
{
	int	status=0;
	struct vwsgen_context * _Context=(struct vwsgen_context*) 0;
	status = vwsgen_create(
	&_Context,
	 pUrl,
	 pWsName,
	 pAgentName,
	 pGenWs,
	 pGenAgent,
	 pGenFace,
	 pDoMenu);
	if ( status != 0) return(status);
	status = vwsgen_show(_Context);
		enter_modal();
	status = vwsgen_focus(_Context);
		leave_modal();
	status = vwsgen_hide(_Context);
	status = vwsgen_remove(
	_Context,
	 pUrl,
	 pWsName,
	 pAgentName,
	 pGenWs,
	 pGenAgent,
	 pGenFace,
	 pDoMenu);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwsgen_c */
