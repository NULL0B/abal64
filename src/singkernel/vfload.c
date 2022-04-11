
#ifndef _vfload_c
#define _vfload_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vfload.xml  */
/* Target         : vfload.c  */
/* Identification : 0.0-1100085310-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto1446   "Sing : Version 1.0a"
#define fr_Auto1446   "Sing : Version 1.0a"
#define it_Auto1446   "Sing : Version 1.0a"
#define es_Auto1446   "Sing : Version 1.0a"
#define de_Auto1446   "Sing : Version 1.0a"
#define nl_Auto1446   "Sing : Version 1.0a"
#define pt_Auto1446   "Sing : Version 1.0a"
#define xx_Auto1446   "Sing : Version 1.0a"
#define en_Auto1447   "skin.gif"
#define fr_Auto1447   "skin.gif"
#define en_Auto1448   "Name of Font to Load"
#define fr_Auto1448   "Nom de fichier Fonte … charger"
#define it_Auto1448   "Name of Font to Load"
#define es_Auto1448   "Name of Font to Load"
#define de_Auto1448   "Name of Font to Load"
#define nl_Auto1448   "Name of Font to Load"
#define pt_Auto1448   "Name of Font to Load"
#define xx_Auto1448   "Name of Font to Load"
#define en_IsAnsi   "ANSI"
#define fr_IsAnsi   "ANSI"
#define it_IsAnsi   "ANSI"
#define es_IsAnsi   "ANSI"
#define de_IsAnsi   "ANSI"
#define nl_IsAnsi   "ANSI"
#define pt_IsAnsi   "ANSI"
#define xx_IsAnsi   "ANSI"
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define it_Accept   "&Accept"
#define es_Accept   "&Accept"
#define de_Accept   "&Accept"
#define nl_Accept   "&Accept"
#define pt_Accept   "&Accept"
#define xx_Accept   "&Accept"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
#define it_Cancel   "&Cancel"
#define es_Cancel   "&Cancel"
#define de_Cancel   "&Cancel"
#define nl_Cancel   "&Cancel"
#define pt_Cancel   "&Cancel"
#define xx_Cancel   "&Cancel"
#define en_Select   "&Select File"
#define fr_Select   "&S‚lection"
#define it_Select   "&Select File"
#define es_Select   "&Select File"
#define de_Select   "&Select File"
#define nl_Select   "&Select File"
#define pt_Select   "&Select File"
#define xx_Select   "&Select File"
#define en_System   "System &Font"
#define fr_System   "&Fonte SystŠme"
#define it_System   "System &Font"
#define es_System   "System &Font"
#define de_System   "System &Font"
#define nl_System   "System &Font"
#define pt_System   "System &Font"
#define xx_System   "System &Font"
static int	vfh[10];

private struct accept_fontload_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto1446[8];
	int	x_Auto1446;
	int	y_Auto1446;
	int	w_Auto1446;
	int	h_Auto1446;
	char * msg_Auto1447[8];
	char * msg_Auto1448[8];
	char	buffer_FileName[208];
	char * msg_IsAnsi[8];
	int	trigger_IsAnsi;
	int	value_IsAnsi;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * msg_Select[8];
	int	trigger_Select;
	char * msg_System[8];
	int	trigger_System;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};

public	int	accept_fontload_create(
	struct accept_fontload_context ** cptr,
	char * pFileName,
	char * pIsAnsi)
{

	int i;
	struct accept_fontload_context * _Context=(struct accept_fontload_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_fontload_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=7;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 207, pFileName);
		visual_transferin((void *) 0, 0, pIsAnsi);
		if (!( pIsAnsi )) _Context->value_IsAnsi=0;
		else	_Context->value_IsAnsi = *((int *)pIsAnsi);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto1446[i]=" ";
	_Context->msg_Auto1446[0]=en_Auto1446;
	_Context->msg_Auto1446[1]=fr_Auto1446;
	_Context->msg_Auto1446[2]=it_Auto1446;
	_Context->msg_Auto1446[3]=es_Auto1446;
	_Context->msg_Auto1446[4]=de_Auto1446;
	_Context->msg_Auto1446[5]=nl_Auto1446;
	_Context->msg_Auto1446[6]=pt_Auto1446;
	_Context->msg_Auto1446[7]=xx_Auto1446;
	_Context->x_Auto1446=105;
	_Context->y_Auto1446=215;
	_Context->w_Auto1446=590;
	_Context->h_Auto1446=170;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto1447[i]=" ";
	_Context->msg_Auto1447[0]=en_Auto1447;
	_Context->msg_Auto1447[1]=fr_Auto1447;
	for (i=0; i < 8; i++)_Context->msg_Auto1448[i]=" ";
	_Context->msg_Auto1448[0]=en_Auto1448;
	_Context->msg_Auto1448[1]=fr_Auto1448;
	_Context->msg_Auto1448[2]=it_Auto1448;
	_Context->msg_Auto1448[3]=es_Auto1448;
	_Context->msg_Auto1448[4]=de_Auto1448;
	_Context->msg_Auto1448[5]=nl_Auto1448;
	_Context->msg_Auto1448[6]=pt_Auto1448;
	_Context->msg_Auto1448[7]=xx_Auto1448;
	for (i=0; i < 8; i++)_Context->msg_IsAnsi[i]=" ";
	_Context->msg_IsAnsi[0]=en_IsAnsi;
	_Context->msg_IsAnsi[1]=fr_IsAnsi;
	_Context->msg_IsAnsi[2]=it_IsAnsi;
	_Context->msg_IsAnsi[3]=es_IsAnsi;
	_Context->msg_IsAnsi[4]=de_IsAnsi;
	_Context->msg_IsAnsi[5]=nl_IsAnsi;
	_Context->msg_IsAnsi[6]=pt_IsAnsi;
	_Context->msg_IsAnsi[7]=xx_IsAnsi;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->msg_Cancel[2]=it_Cancel;
	_Context->msg_Cancel[3]=es_Cancel;
	_Context->msg_Cancel[4]=de_Cancel;
	_Context->msg_Cancel[5]=nl_Cancel;
	_Context->msg_Cancel[6]=pt_Cancel;
	_Context->msg_Cancel[7]=xx_Cancel;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	_Context->msg_Select[2]=it_Select;
	_Context->msg_Select[3]=es_Select;
	_Context->msg_Select[4]=de_Select;
	_Context->msg_Select[5]=nl_Select;
	_Context->msg_Select[6]=pt_Select;
	_Context->msg_Select[7]=xx_Select;
	for (i=0; i < 8; i++)_Context->msg_System[i]=" ";
	_Context->msg_System[0]=en_System;
	_Context->msg_System[1]=fr_System;
	_Context->msg_System[2]=it_System;
	_Context->msg_System[3]=es_System;
	_Context->msg_System[4]=de_System;
	_Context->msg_System[5]=nl_System;
	_Context->msg_System[6]=pt_System;
	_Context->msg_System[7]=xx_System;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto1446,_Context->y_Auto1446,590+10,170+10);
	return(0);
}

public 	int	accept_fontload_hide(struct accept_fontload_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto1446,_Context->y_Auto1446);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_fontload_remove(
	struct accept_fontload_context * _Context,
	char * pFileName,
	char * pIsAnsi)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 207, pFileName);
		visual_transferout((void *) 0, 0, pIsAnsi);
		if ( pIsAnsi != (char *) 0)
			*((int*)pIsAnsi) = _Context->value_IsAnsi;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_fontload_show(struct accept_fontload_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto1446,_Context->y_Auto1446);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto1446,_Context->y_Auto1446,590,170,vfh[2],_Context->msg_Auto1446[_Context->language],strlen(_Context->msg_Auto1446[_Context->language]),0x407);
	visual_image(_Context->x_Auto1446+3,_Context->y_Auto1446+21,583,144,_Context->msg_Auto1447[_Context->language],4);
	visual_text(_Context->x_Auto1446+20,_Context->y_Auto1446+40,560,20,vfh[2],38,0,_Context->msg_Auto1448[_Context->language],strlen(_Context->msg_Auto1448[_Context->language]),256);
	visual_frame(_Context->x_Auto1446+20,_Context->y_Auto1446+60,552+2,48+2,5);
	visual_text(_Context->x_Auto1446+20+1,_Context->y_Auto1446+60+1,552,48,vfh[1],16,24,_Context->buffer_FileName,207,0);
	_Context->trigger_IsAnsi=visual_trigger_code(_Context->msg_IsAnsi[_Context->language],strlen(_Context->msg_IsAnsi[_Context->language]));
	visual_switch(_Context->x_Auto1446+268,_Context->y_Auto1446+123,57,27,vfh[2],31,12,_Context->msg_IsAnsi[_Context->language],strlen(_Context->msg_IsAnsi[_Context->language]),_Context->value_IsAnsi| 0x0030);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto1446+20,_Context->y_Auto1446+120,98,32,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto1446+470,_Context->y_Auto1446+120,98,32,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_Auto1446+120,_Context->y_Auto1446+120,126,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	_Context->trigger_System=visual_trigger_code(_Context->msg_System[_Context->language],strlen(_Context->msg_System[_Context->language]));
	visual_button(_Context->x_Auto1446+340,_Context->y_Auto1446+120,126,32,vfh[2],27,24,_Context->msg_System[_Context->language],strlen(_Context->msg_System[_Context->language]),0);
	visual_thaw(_Context->x_Auto1446,_Context->y_Auto1446,590,170);
	visual_thaw(_Context->x_Auto1446,_Context->y_Auto1446,590,170);

	return(0);
}

private int Auto1446action(struct accept_fontload_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_fontload_hide(_Context);

		_Context->x_Auto1446 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto1446 < 0) { _Context->x_Auto1446=0; }
		_Context->y_Auto1446 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto1446 < 0) { _Context->y_Auto1446=0; }
			accept_fontload_show(_Context);

		visual_thaw(_Context->x_Auto1446,_Context->y_Auto1446,590,170);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_fontload_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_fontload_context * _Context) {
	return(27);
	return(-1);
}
private int on_Select_event(struct accept_fontload_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_FMF);
		accept_fontload_show(_Context);
;
	return(-1);
}
private int on_System_event(struct accept_fontload_context * _Context) {
	char*allocate_string(char*);
	char*sptr;
	if((sptr=allocate_string(_Context->buffer_FileName))!=(char*)0){
	if(system_font_selector(&sptr)!=27){
	if(sptr)
	strcpy(_Context->buffer_FileName,sptr);
	}
	if(sptr)
	liberate(sptr);
		accept_fontload_show(_Context);
;
	}
	return(-1);
}


public	int	accept_fontload_event(
struct accept_fontload_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsAnsi == mb ) return(3);
		if (_Context->trigger_Accept == mb ) return(4);
		if (_Context->trigger_Cancel == mb ) return(5);
		if (_Context->trigger_Select == mb ) return(6);
		if (_Context->trigger_System == mb ) return(7);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x1031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto1446+569) )  
	&&  (my >= (_Context->y_Auto1446+4) )  
	&&  (mx <= (_Context->x_Auto1446+586) )  
	&&  (my <= (_Context->y_Auto1446+20) )) {
		return(1);	/* Auto1446 */

		}
	if ((mx >= (_Context->x_Auto1446+553) )  
	&&  (my >= (_Context->y_Auto1446+4) )  
	&&  (mx <= (_Context->x_Auto1446+570) )  
	&&  (my <= (_Context->y_Auto1446+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vfload.htm");
			};
		return(-1);	/* Auto1446 */

		}
	if ((mx >= (_Context->x_Auto1446+537) )  
	&&  (my >= (_Context->y_Auto1446+4) )  
	&&  (mx <= (_Context->x_Auto1446+554) )  
	&&  (my <= (_Context->y_Auto1446+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_fontload_show(_Context);
		return(-1);	/* Auto1446 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto1446+4) )  
		&&  (my >= (_Context->y_Auto1446+4) )  
		&&  (mx <= (_Context->x_Auto1446+522) )  
		&&  (my <= (_Context->y_Auto1446+20) )) {
			return( Auto1446action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto1446+20) ) 
	&&  ( my >= (_Context->y_Auto1446+60) ) 
	&&  ( mx <= (_Context->x_Auto1446+20+552) ) 
	&&  ( my <= (_Context->y_Auto1446+60+48))) {
		return(2); /* FileName */
		}
	if (( mx >= (_Context->x_Auto1446+268) ) 
	&&  ( my >= (_Context->y_Auto1446+123) ) 
	&&  ( mx <= (_Context->x_Auto1446+268+57) ) 
	&&  ( my <= (_Context->y_Auto1446+123+27))) {
		return(3); /* IsAnsi */
		}
	if (( mx >= (_Context->x_Auto1446+20) ) 
	&&  ( my >= (_Context->y_Auto1446+120) ) 
	&&  ( mx <= (_Context->x_Auto1446+20+98) ) 
	&&  ( my <= (_Context->y_Auto1446+120+32))) {
		return(4); /* Accept */
		}
	if (( mx >= (_Context->x_Auto1446+470) ) 
	&&  ( my >= (_Context->y_Auto1446+120) ) 
	&&  ( mx <= (_Context->x_Auto1446+470+98) ) 
	&&  ( my <= (_Context->y_Auto1446+120+32))) {
		return(5); /* Cancel */
		}
	if (( mx >= (_Context->x_Auto1446+120) ) 
	&&  ( my >= (_Context->y_Auto1446+120) ) 
	&&  ( mx <= (_Context->x_Auto1446+120+126) ) 
	&&  ( my <= (_Context->y_Auto1446+120+32))) {
		return(6); /* Select */
		}
	if (( mx >= (_Context->x_Auto1446+340) ) 
	&&  ( my >= (_Context->y_Auto1446+120) ) 
	&&  ( mx <= (_Context->x_Auto1446+340+126) ) 
	&&  ( my <= (_Context->y_Auto1446+120+32))) {
		return(7); /* System */
		}

	return(-1);
}


public	int	accept_fontload_focus(struct accept_fontload_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(_Context->x_Auto1446+20+1,_Context->y_Auto1446+60+1,552,48,vfh[1],_Context->buffer_FileName,207);
			break;
			case	0x3 :
				/* IsAnsi */
				visual_switch(_Context->x_Auto1446+268,_Context->y_Auto1446+123,57,27,vfh[2],31,12,_Context->msg_IsAnsi[_Context->language],strlen(_Context->msg_IsAnsi[_Context->language]),(_Context->value_IsAnsi | 2 | 0x0030 ));
				_Context->keycode = visual_getch();
				visual_switch(_Context->x_Auto1446+268,_Context->y_Auto1446+123,57,27,vfh[2],31,12,_Context->msg_IsAnsi[_Context->language],strlen(_Context->msg_IsAnsi[_Context->language]),(_Context->value_IsAnsi | 0 | 0x0030 ));
				break;
			case	0x4 :
				/* Accept */
				visual_button(_Context->x_Auto1446+20,_Context->y_Auto1446+120,98,32,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto1446+20,_Context->y_Auto1446+120,98,32,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x5 :
				/* Cancel */
				visual_button(_Context->x_Auto1446+470,_Context->y_Auto1446+120,98,32,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto1446+470,_Context->y_Auto1446+120,98,32,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0x6 :
				/* Select */
				visual_button(_Context->x_Auto1446+120,_Context->y_Auto1446+120,126,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto1446+120,_Context->y_Auto1446+120,126,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;
			case	0x7 :
				/* System */
				visual_button(_Context->x_Auto1446+340,_Context->y_Auto1446+120,126,32,vfh[2],27,24,_Context->msg_System[_Context->language],strlen(_Context->msg_System[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto1446+340,_Context->y_Auto1446+120,126,32,vfh[2],27,24,_Context->msg_System[_Context->language],strlen(_Context->msg_System[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_fontload_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=7;
			accept_fontload_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_fontload_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1446 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* FileName */
						continue;
					case	0x3 :
						/* IsAnsi */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsAnsi += 1;
							_Context->value_IsAnsi &= 1;
							}
						continue;
					case	0x4 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1446+20,_Context->y_Auto1446+120,98,32,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1446+20,_Context->y_Auto1446+120,98,32,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1446+470,_Context->y_Auto1446+120,98,32,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1446+470,_Context->y_Auto1446+120,98,32,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* Select */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1446+120,_Context->y_Auto1446+120,126,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1446+120,_Context->y_Auto1446+120,126,32,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Select_event(_Context)) != -1) break;

							}
						continue;
					case	0x7 :
						/* System */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1446+340,_Context->y_Auto1446+120,126,32,vfh[2],27,24,_Context->msg_System[_Context->language],strlen(_Context->msg_System[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1446+340,_Context->y_Auto1446+120,126,32,vfh[2],27,24,_Context->msg_System[_Context->language],strlen(_Context->msg_System[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_System_event(_Context)) != -1) break;

							}
						continue;
					case	0xffffffff :
					default :
						_Context->focus_item=1;
					continue;
					}
				break;
			case	0x1b :
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
				_Context->focus_item=7;
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

public	int	accept_fontload(
	char * pFileName,
	char * pIsAnsi)
{
	int	status=0;
	struct accept_fontload_context * _Context=(struct accept_fontload_context*) 0;
	status = accept_fontload_create(
	&_Context,
	 pFileName,
	 pIsAnsi);
	if ( status != 0) return(status);
	status = accept_fontload_show(_Context);
		enter_modal();
	status = accept_fontload_focus(_Context);
		leave_modal();
	status = accept_fontload_hide(_Context);
	status = accept_fontload_remove(
	_Context,
	 pFileName,
	 pIsAnsi);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vfload_c */
