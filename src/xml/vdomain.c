
#ifndef _vdomain_c
#define _vdomain_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vdomain.xml                                              */
/* Target         : vdomain.c                                                */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en__Auto3635   ""
#define fr__Auto3635   ""
#define it__Auto3635   ""
#define es__Auto3635   ""
#define de__Auto3635   ""
#define nl__Auto3635   ""
#define pt__Auto3635   ""
#define xx__Auto3635   ""
#define en_ImportMsg   "Style Class Selection Filter"
#define fr_ImportMsg   "Style Class Dependance Model : Domain Selection"
#define it_ImportMsg   "Style Class Dependance Model : Domain Selection"
#define es_ImportMsg   "Style Class Dependance Model : Domain Selection"
#define de_ImportMsg   "Style Class Dependance Model : Domain Selection"
#define nl_ImportMsg   "Style Class Dependance Model : Domain Selection"
#define pt_ImportMsg   "Style Class Dependance Model : Domain Selection"
#define xx_ImportMsg   "Style Class Dependance Model : Domain Selection"
#define en__ImportMsg   ""
#define fr__ImportMsg   ""
#define it__ImportMsg   ""
#define es__ImportMsg   ""
#define de__ImportMsg   ""
#define nl__ImportMsg   ""
#define pt__ImportMsg   ""
#define xx__ImportMsg   ""
#define en_Auto3636   "Selection by"
#define fr_Auto3636   "Nom de domain"
#define it_Auto3636   "Domain / Prefix"
#define es_Auto3636   "Domain / Prefix"
#define de_Auto3636   "Domain / Prefix"
#define nl_Auto3636   "Domain / Prefix"
#define pt_Auto3636   "Domain / Prefix"
#define xx_Auto3636   "Domain / Prefix"
#define en__Auto3636   ""
#define fr__Auto3636   ""
#define it__Auto3636   ""
#define es__Auto3636   ""
#define de__Auto3636   ""
#define nl__Auto3636   ""
#define pt__Auto3636   ""
#define xx__Auto3636   ""
#define en_Auto3637   "Domain or File"
#define fr_Auto3637   "Nom de domain"
#define it_Auto3637   "Domain / Prefix"
#define es_Auto3637   "Domain / Prefix"
#define de_Auto3637   "Domain / Prefix"
#define nl_Auto3637   "Domain / Prefix"
#define pt_Auto3637   "Domain / Prefix"
#define xx_Auto3637   "Domain / Prefix"
#define en__Auto3637   ""
#define fr__Auto3637   ""
#define it__Auto3637   ""
#define es__Auto3637   ""
#define de__Auto3637   ""
#define nl__Auto3637   ""
#define pt__Auto3637   ""
#define xx__Auto3637   ""
#define en_Nature   "Domain Name|File Name"
#define en__Nature   ""
#define en_DomainName   ""
#define en__DomainName   ""
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
#define fr__Cancel   ""
#define it__Cancel   ""
#define es__Cancel   ""
#define de__Cancel   ""
#define nl__Cancel   ""
#define pt__Cancel   ""
#define xx__Cancel   ""

private struct accept_css_domain_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3635[8];
	char * hint_Auto3635[8];
	int	x_Auto3635;
	int	y_Auto3635;
	int	w_Auto3635;
	int	h_Auto3635;
	char * msg_ImportMsg[8];
	char * hint_ImportMsg[8];
	char * msg_Auto3636[8];
	char * hint_Auto3636[8];
	char * msg_Auto3637[8];
	char * hint_Auto3637[8];
	char * msg_Nature[8];
	char * hint_Nature[8];
	int	value_Nature;
	char * hint_DomainName[8];
	char	buffer_DomainName[53];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};
static int	vfh[16];
private int on_Accept_event(struct accept_css_domain_context * _Context);
private int on_Cancel_event(struct accept_css_domain_context * _Context);

public	int	accept_css_domain_create(
	struct accept_css_domain_context ** cptr,
	char * pNature,
	char * pDomainName)
{

	int i;
	struct accept_css_domain_context * _Context=(struct accept_css_domain_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_css_domain_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=5;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pNature);
		if (!( pNature )) _Context->value_Nature=0;
		else	_Context->value_Nature = *((int *)pNature);
		visual_transferin(_Context->buffer_DomainName, 52, pDomainName);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3635[i]=" ";
	_Context->hint_Auto3635[0]=en__Auto3635;
	_Context->hint_Auto3635[1]=fr__Auto3635;
	_Context->hint_Auto3635[2]=it__Auto3635;
	_Context->hint_Auto3635[3]=es__Auto3635;
	_Context->hint_Auto3635[4]=de__Auto3635;
	_Context->hint_Auto3635[5]=nl__Auto3635;
	_Context->hint_Auto3635[6]=pt__Auto3635;
	_Context->hint_Auto3635[7]=xx__Auto3635;
	_Context->x_Auto3635=105;
	_Context->y_Auto3635=205;
	_Context->w_Auto3635=590;
	_Context->h_Auto3635=190;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3636[i]=" ";
	_Context->msg_Auto3636[0]=en_Auto3636;
	_Context->msg_Auto3636[1]=fr_Auto3636;
	_Context->msg_Auto3636[2]=it_Auto3636;
	_Context->msg_Auto3636[3]=es_Auto3636;
	_Context->msg_Auto3636[4]=de_Auto3636;
	_Context->msg_Auto3636[5]=nl_Auto3636;
	_Context->msg_Auto3636[6]=pt_Auto3636;
	_Context->msg_Auto3636[7]=xx_Auto3636;
	_Context->hint_Auto3636[0]=en__Auto3636;
	_Context->hint_Auto3636[1]=fr__Auto3636;
	_Context->hint_Auto3636[2]=it__Auto3636;
	_Context->hint_Auto3636[3]=es__Auto3636;
	_Context->hint_Auto3636[4]=de__Auto3636;
	_Context->hint_Auto3636[5]=nl__Auto3636;
	_Context->hint_Auto3636[6]=pt__Auto3636;
	_Context->hint_Auto3636[7]=xx__Auto3636;
	for (i=0; i < 8; i++)_Context->msg_Auto3637[i]=" ";
	_Context->msg_Auto3637[0]=en_Auto3637;
	_Context->msg_Auto3637[1]=fr_Auto3637;
	_Context->msg_Auto3637[2]=it_Auto3637;
	_Context->msg_Auto3637[3]=es_Auto3637;
	_Context->msg_Auto3637[4]=de_Auto3637;
	_Context->msg_Auto3637[5]=nl_Auto3637;
	_Context->msg_Auto3637[6]=pt_Auto3637;
	_Context->msg_Auto3637[7]=xx_Auto3637;
	_Context->hint_Auto3637[0]=en__Auto3637;
	_Context->hint_Auto3637[1]=fr__Auto3637;
	_Context->hint_Auto3637[2]=it__Auto3637;
	_Context->hint_Auto3637[3]=es__Auto3637;
	_Context->hint_Auto3637[4]=de__Auto3637;
	_Context->hint_Auto3637[5]=nl__Auto3637;
	_Context->hint_Auto3637[6]=pt__Auto3637;
	_Context->hint_Auto3637[7]=xx__Auto3637;
	for (i=0; i < 8; i++)_Context->msg_Nature[i]=" ";
	_Context->msg_Nature[0]=en_Nature;
	_Context->hint_Nature[0]=en__Nature;
	_Context->hint_DomainName[0]=en__DomainName;
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
	_Context->hint_Cancel[1]=fr__Cancel;
	_Context->hint_Cancel[2]=it__Cancel;
	_Context->hint_Cancel[3]=es__Cancel;
	_Context->hint_Cancel[4]=de__Cancel;
	_Context->hint_Cancel[5]=nl__Cancel;
	_Context->hint_Cancel[6]=pt__Cancel;
	_Context->hint_Cancel[7]=xx__Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(105,205,590+10,190+10);
	return(0);
}

public 	int	accept_css_domain_hide(struct accept_css_domain_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,105,205);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_css_domain_remove(
	struct accept_css_domain_context * _Context,
	char * pNature,
	char * pDomainName)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pNature);
		if ( pNature != (char *) 0)
			*((int*)pNature) = _Context->value_Nature;
		visual_transferout(_Context->buffer_DomainName, 52, pDomainName);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_css_domain_show(struct accept_css_domain_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,105,205);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(105,205,590,190,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(105,205,590,190,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(125,325,112,16,vfh[2],16,0,_Context->msg_Auto3636[_Context->language],strlen(_Context->msg_Auto3636[_Context->language]),258);
	visual_text(125,295,112,16,vfh[2],16,0,_Context->msg_Auto3637[_Context->language],strlen(_Context->msg_Auto3637[_Context->language]),258);
	visual_select(245,325,140,64,vfh[2],0,0,parse_selection(_Context->msg_Nature[_Context->language],&_Context->value_Nature),768);
	visual_frame(245,295,416+2,16+2,5);
	visual_text(245+1,295+1,416,16,vfh[1],27,28,_Context->buffer_DomainName,52,0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(545,325,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(605,325,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_thaw(105,205,590,190);

	return(0);
}

private int Auto3635action(struct accept_css_domain_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_css_domain_hide(_Context);

		_Context->x_Auto3635 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3635 < 0) { _Context->x_Auto3635=0; }
		_Context->y_Auto3635 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3635 < 0) { _Context->y_Auto3635=0; }
			accept_css_domain_show(_Context);

		visual_thaw(105,205,590,190);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_css_domain_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_css_domain_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_css_domain_event(
struct accept_css_domain_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(4);
		if (_Context->trigger_Cancel == mb ) return(5);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= 674 )  
	&&  (my >= 209 )  
	&&  (mx <= 690 )  
	&&  (my <= 225 )) {
		return(1);	/* Auto3635 */

		}
	if ((mx >= 658 )  
	&&  (my >= 209 )  
	&&  (mx <= 674 )  
	&&  (my <= 225 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vdomain.htm");
			};
		return(-1);	/* Auto3635 */

		}
	if ((mx >= 642 )  
	&&  (my >= 209 )  
	&&  (mx <= 658 )  
	&&  (my <= 225 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_css_domain_show(_Context);
		return(-1);	/* Auto3635 */

		}
	case _MIMO_DOWN :
		if ((mx >= (105+4) )  
		&&  (my >= (205+4) )  
		&&  (mx <= (105+522) )  
		&&  (my <= (205+20) )) {
			return( Auto3635action(_Context) );
			}
		}
	if ((mx >= 245 ) 
	&&  (my >= 325 ) 
	&&  (mx <= 385 ) 
	&&  (my <= 341 )) {
		return(2); /* Nature */
		}
	if (( mx >= 245 ) 
	&&  ( my >= 295 ) 
	&&  ( mx <= 661 ) 
	&&  ( my <= 311 )) {
		return(3); /* DomainName */
		}
	if (( mx >= 545 ) 
	&&  ( my >= 325 ) 
	&&  ( mx <= 601 ) 
	&&  ( my <= 373 )) {
		return(4); /* Accept */
		}
	if (( mx >= 605 ) 
	&&  ( my >= 325 ) 
	&&  ( mx <= 661 ) 
	&&  ( my <= 373 )) {
		return(5); /* Cancel */
		}

	return(-1);
}


public	int	accept_css_domain_focus(struct accept_css_domain_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Nature */
				_Context->keycode = visual_select(245,325,140,64,vfh[2],0,0,parse_selection(_Context->msg_Nature[_Context->language],&_Context->value_Nature),770);
				break;
			case	0x3 :
				/* DomainName */
				_Context->keycode = visual_edit(245+1,295+1,416,16,vfh[1],_Context->buffer_DomainName,52);
			break;
			case	0x4 :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(545,325,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(545,325,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0x5 :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(605,325,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(605,325,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_css_domain_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=5;
			accept_css_domain_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_css_domain_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3635 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Nature */
					continue;
				case	0x3 :
					/* DomainName */
					continue;
				case	0x4 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(545,325,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(545,325,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(605,325,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(605,325,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
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

public	int	accept_css_domain(
	char * pNature,
	char * pDomainName)
{
	int	status=0;
	struct accept_css_domain_context * _Context=(struct accept_css_domain_context*) 0;
	status = accept_css_domain_create(
	&_Context,
	 pNature,
	 pDomainName);
	if ( status != 0) return(status);
	status = accept_css_domain_show(_Context);
		enter_modal();
	status = accept_css_domain_focus(_Context);
		leave_modal();
	status = accept_css_domain_hide(_Context);
	status = accept_css_domain_remove(
	_Context,
	 pNature,
	 pDomainName);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vdomain_c */
