
#ifndef _velabel_c
#define _velabel_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : velabel.xml                                              */
/* Target         : velabel.c                                                */
/* Identification : 0.0-1177511934-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto2720   ""
#define fr__Auto2720   ""
#define it__Auto2720   ""
#define es__Auto2720   ""
#define de__Auto2720   ""
#define nl__Auto2720   ""
#define pt__Auto2720   ""
#define xx__Auto2720   ""
#define en_Auto2721   "Export labels Parameters"
#define fr_Auto2721   "Parametres d'exportation des libell‚s"
#define it_Auto2721   "Export labels Parameters"
#define es_Auto2721   "Export labels Parameters"
#define de_Auto2721   "Export labels Parameters"
#define nl_Auto2721   "Export labels Parameters"
#define pt_Auto2721   "Export labels Parameters"
#define xx_Auto2721   "Export labels Parameters"
#define en__Auto2721   ""
#define fr__Auto2721   ""
#define it__Auto2721   ""
#define es__Auto2721   ""
#define de__Auto2721   ""
#define nl__Auto2721   ""
#define pt__Auto2721   ""
#define xx__Auto2721   ""
#define en_Auto2722   "Export Filename"
#define fr_Auto2722   "Fichier d'exportation"
#define it_Auto2722   "Export Filename"
#define es_Auto2722   "Export Filename"
#define de_Auto2722   "Export Filename"
#define nl_Auto2722   "Export Filename"
#define pt_Auto2722   "Export Filename"
#define xx_Auto2722   "Export Filename"
#define en_FileName   ""
#define en__FileName   ""
#define en_ChoixFileName   "..."
#define fr_ChoixFileName   "..."
#define it_ChoixFileName   "..."
#define es_ChoixFileName   "..."
#define de_ChoixFileName   "..."
#define nl_ChoixFileName   "..."
#define pt_ChoixFileName   "..."
#define xx_ChoixFileName   "..."
#define en__ChoixFileName   ""
#define fr__ChoixFileName   ""
#define it__ChoixFileName   ""
#define es__ChoixFileName   ""
#define de__ChoixFileName   ""
#define nl__ChoixFileName   ""
#define pt__ChoixFileName   ""
#define xx__ChoixFileName   ""
#define en_MsgSeparateur   "Field separator"
#define fr_MsgSeparateur   "S‚parateur de champs"
#define it_MsgSeparateur   "Field separator"
#define es_MsgSeparateur   "Field separator"
#define de_MsgSeparateur   "Field separator"
#define nl_MsgSeparateur   "Field separator"
#define pt_MsgSeparateur   "Field separator"
#define xx_MsgSeparateur   "Field separator"
#define en__MsgSeparateur   ""
#define fr__MsgSeparateur   ""
#define it__MsgSeparateur   ""
#define es__MsgSeparateur   ""
#define de__MsgSeparateur   ""
#define nl__MsgSeparateur   ""
#define pt__MsgSeparateur   ""
#define xx__MsgSeparateur   ""
#define en_Separator   "tabulation|pipe|coma|semicolon"
#define fr_Separator   "tabulation|pipe|virgule|point virgule"
#define it_Separator   "tabulation|pipe|coma|Semicolon"
#define es_Separator   "tabulation|pipe|coma|semicolon"
#define de_Separator   "tabulation|pipe|coma|semicolon"
#define nl_Separator   "tabulation|pipe|coma|semicolon"
#define pt_Separator   "tabulation|pipe|coma|semicolon"
#define xx_Separator   "tabulation|pipe|coma|semicolon"
#define en__Separator   ""
#define fr__Separator   ""
#define it__Separator   ""
#define es__Separator   ""
#define de__Separator   ""
#define nl__Separator   ""
#define pt__Separator   ""
#define xx__Separator   ""
#define en_Auto2723   "ok.gif"
#define fr_Auto2723   "ok.gif"
#define it_Auto2723   "ok.gif"
#define es_Auto2723   "ok.gif"
#define de_Auto2723   "ok.gif"
#define nl_Auto2723   "ok.gif"
#define pt_Auto2723   "ok.gif"
#define xx_Auto2723   "ok.gif"
#define en__Auto2723   ""
#define en_Auto2724   "cancel.gif"
#define fr_Auto2724   "cancel.gif"
#define it_Auto2724   "cancel.gif"
#define es_Auto2724   "cancel.gif"
#define de_Auto2724   "cancel.gif"
#define nl_Auto2724   "cancel.gif"
#define pt_Auto2724   "cancel.gif"
#define xx_Auto2724   "cancel.gif"
#define en__Auto2724   ""

private struct accept_elabels_parameters_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto2720[8];
	char * hint_Auto2720[8];
	int	x_Auto2720;
	int	y_Auto2720;
	int	w_Auto2720;
	int	h_Auto2720;
	char * msg_Auto2721[8];
	char * hint_Auto2721[8];
	char * msg_Auto2722[8];
	char * hint_Auto2722[8];
	char * hint_FileName[8];
	char	buffer_FileName[256];
	char * msg_ChoixFileName[8];
	int	trigger_ChoixFileName;
	char * hint_ChoixFileName[8];
	char * msg_MsgSeparateur[8];
	char * hint_MsgSeparateur[8];
	char * msg_Separator[8];
	char * hint_Separator[8];
	int	value_Separator;
	char * msg_Auto2723[8];
	int	trigger_Auto2723;
	char * hint_Auto2723[8];
	char * msg_Auto2724[8];
	int	trigger_Auto2724;
	char * hint_Auto2724[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[3];
	};
static int	vfh[16];

public	int	accept_elabels_parameters_create(
	struct accept_elabels_parameters_context ** cptr,
	char * pFileName,
	char * pSeparator)
{

	int i;
	struct accept_elabels_parameters_context * _Context=(struct accept_elabels_parameters_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_elabels_parameters_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=6;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 255, pFileName);
		visual_transferin((void *) 0, 0, pSeparator);
		if (!( pSeparator )) _Context->value_Separator=0;
		else	_Context->value_Separator = *((int *)pSeparator);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto2720[i]=" ";
	_Context->hint_Auto2720[0]=en__Auto2720;
	_Context->hint_Auto2720[1]=fr__Auto2720;
	_Context->hint_Auto2720[2]=it__Auto2720;
	_Context->hint_Auto2720[3]=es__Auto2720;
	_Context->hint_Auto2720[4]=de__Auto2720;
	_Context->hint_Auto2720[5]=nl__Auto2720;
	_Context->hint_Auto2720[6]=pt__Auto2720;
	_Context->hint_Auto2720[7]=xx__Auto2720;
	_Context->x_Auto2720=100;
	_Context->y_Auto2720=175;
	_Context->w_Auto2720=600;
	_Context->h_Auto2720=250;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2721[i]=" ";
	_Context->msg_Auto2721[0]=en_Auto2721;
	_Context->msg_Auto2721[1]=fr_Auto2721;
	_Context->msg_Auto2721[2]=it_Auto2721;
	_Context->msg_Auto2721[3]=es_Auto2721;
	_Context->msg_Auto2721[4]=de_Auto2721;
	_Context->msg_Auto2721[5]=nl_Auto2721;
	_Context->msg_Auto2721[6]=pt_Auto2721;
	_Context->msg_Auto2721[7]=xx_Auto2721;
	_Context->hint_Auto2721[0]=en__Auto2721;
	_Context->hint_Auto2721[1]=fr__Auto2721;
	_Context->hint_Auto2721[2]=it__Auto2721;
	_Context->hint_Auto2721[3]=es__Auto2721;
	_Context->hint_Auto2721[4]=de__Auto2721;
	_Context->hint_Auto2721[5]=nl__Auto2721;
	_Context->hint_Auto2721[6]=pt__Auto2721;
	_Context->hint_Auto2721[7]=xx__Auto2721;
	for (i=0; i < 8; i++)_Context->msg_Auto2722[i]=" ";
	_Context->msg_Auto2722[0]=en_Auto2722;
	_Context->msg_Auto2722[1]=fr_Auto2722;
	_Context->msg_Auto2722[2]=it_Auto2722;
	_Context->msg_Auto2722[3]=es_Auto2722;
	_Context->msg_Auto2722[4]=de_Auto2722;
	_Context->msg_Auto2722[5]=nl_Auto2722;
	_Context->msg_Auto2722[6]=pt_Auto2722;
	_Context->msg_Auto2722[7]=xx_Auto2722;
	_Context->hint_FileName[0]=en__FileName;
	for (i=0; i < 8; i++)_Context->msg_ChoixFileName[i]=" ";
	_Context->msg_ChoixFileName[0]=en_ChoixFileName;
	_Context->msg_ChoixFileName[1]=fr_ChoixFileName;
	_Context->msg_ChoixFileName[2]=it_ChoixFileName;
	_Context->msg_ChoixFileName[3]=es_ChoixFileName;
	_Context->msg_ChoixFileName[4]=de_ChoixFileName;
	_Context->msg_ChoixFileName[5]=nl_ChoixFileName;
	_Context->msg_ChoixFileName[6]=pt_ChoixFileName;
	_Context->msg_ChoixFileName[7]=xx_ChoixFileName;
	_Context->hint_ChoixFileName[0]=en__ChoixFileName;
	_Context->hint_ChoixFileName[1]=fr__ChoixFileName;
	_Context->hint_ChoixFileName[2]=it__ChoixFileName;
	_Context->hint_ChoixFileName[3]=es__ChoixFileName;
	_Context->hint_ChoixFileName[4]=de__ChoixFileName;
	_Context->hint_ChoixFileName[5]=nl__ChoixFileName;
	_Context->hint_ChoixFileName[6]=pt__ChoixFileName;
	_Context->hint_ChoixFileName[7]=xx__ChoixFileName;
	for (i=0; i < 8; i++)_Context->msg_MsgSeparateur[i]=" ";
	_Context->msg_MsgSeparateur[0]=en_MsgSeparateur;
	_Context->msg_MsgSeparateur[1]=fr_MsgSeparateur;
	_Context->msg_MsgSeparateur[2]=it_MsgSeparateur;
	_Context->msg_MsgSeparateur[3]=es_MsgSeparateur;
	_Context->msg_MsgSeparateur[4]=de_MsgSeparateur;
	_Context->msg_MsgSeparateur[5]=nl_MsgSeparateur;
	_Context->msg_MsgSeparateur[6]=pt_MsgSeparateur;
	_Context->msg_MsgSeparateur[7]=xx_MsgSeparateur;
	_Context->hint_MsgSeparateur[0]=en__MsgSeparateur;
	_Context->hint_MsgSeparateur[1]=fr__MsgSeparateur;
	_Context->hint_MsgSeparateur[2]=it__MsgSeparateur;
	_Context->hint_MsgSeparateur[3]=es__MsgSeparateur;
	_Context->hint_MsgSeparateur[4]=de__MsgSeparateur;
	_Context->hint_MsgSeparateur[5]=nl__MsgSeparateur;
	_Context->hint_MsgSeparateur[6]=pt__MsgSeparateur;
	_Context->hint_MsgSeparateur[7]=xx__MsgSeparateur;
	for (i=0; i < 8; i++)_Context->msg_Separator[i]=" ";
	_Context->msg_Separator[0]=en_Separator;
	_Context->msg_Separator[1]=fr_Separator;
	_Context->msg_Separator[2]=it_Separator;
	_Context->msg_Separator[3]=es_Separator;
	_Context->msg_Separator[4]=de_Separator;
	_Context->msg_Separator[5]=nl_Separator;
	_Context->msg_Separator[6]=pt_Separator;
	_Context->msg_Separator[7]=xx_Separator;
	_Context->hint_Separator[0]=en__Separator;
	_Context->hint_Separator[1]=fr__Separator;
	_Context->hint_Separator[2]=it__Separator;
	_Context->hint_Separator[3]=es__Separator;
	_Context->hint_Separator[4]=de__Separator;
	_Context->hint_Separator[5]=nl__Separator;
	_Context->hint_Separator[6]=pt__Separator;
	_Context->hint_Separator[7]=xx__Separator;
	for (i=0; i < 8; i++)_Context->msg_Auto2723[i]=" ";
	_Context->msg_Auto2723[0]=en_Auto2723;
	_Context->msg_Auto2723[1]=fr_Auto2723;
	_Context->msg_Auto2723[2]=it_Auto2723;
	_Context->msg_Auto2723[3]=es_Auto2723;
	_Context->msg_Auto2723[4]=de_Auto2723;
	_Context->msg_Auto2723[5]=nl_Auto2723;
	_Context->msg_Auto2723[6]=pt_Auto2723;
	_Context->msg_Auto2723[7]=xx_Auto2723;
	_Context->hint_Auto2723[0]=en__Auto2723;
	for (i=0; i < 8; i++)_Context->msg_Auto2724[i]=" ";
	_Context->msg_Auto2724[0]=en_Auto2724;
	_Context->msg_Auto2724[1]=fr_Auto2724;
	_Context->msg_Auto2724[2]=it_Auto2724;
	_Context->msg_Auto2724[3]=es_Auto2724;
	_Context->msg_Auto2724[4]=de_Auto2724;
	_Context->msg_Auto2724[5]=nl_Auto2724;
	_Context->msg_Auto2724[6]=pt_Auto2724;
	_Context->msg_Auto2724[7]=xx_Auto2724;
	_Context->hint_Auto2724[0]=en__Auto2724;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto2720,_Context->y_Auto2720,600+10,250+10);
	return(0);
}

public 	int	accept_elabels_parameters_hide(struct accept_elabels_parameters_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto2720,_Context->y_Auto2720);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_elabels_parameters_remove(
	struct accept_elabels_parameters_context * _Context,
	char * pFileName,
	char * pSeparator)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 255, pFileName);
		visual_transferout((void *) 0, 0, pSeparator);
		if ( pSeparator != (char *) 0)
			*((int*)pSeparator) = _Context->value_Separator;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_elabels_parameters_show(struct accept_elabels_parameters_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto2720,_Context->y_Auto2720);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto2720,_Context->y_Auto2720,600,250,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto2720,_Context->y_Auto2720,600,250,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto2720+10,_Context->y_Auto2720+30,580,20,vfh[3],16,0,_Context->msg_Auto2721[_Context->language],strlen(_Context->msg_Auto2721[_Context->language]),1282);
	visual_frame(_Context->x_Auto2720+10,_Context->y_Auto2720+50,580,190,4);
	visual_text(_Context->x_Auto2720+30,_Context->y_Auto2720+70,170,20,vfh[2],16,0,_Context->msg_Auto2722[_Context->language],strlen(_Context->msg_Auto2722[_Context->language]),258);
	visual_frame(_Context->x_Auto2720+30,_Context->y_Auto2720+90,510+2,16+2,5);
	visual_text(_Context->x_Auto2720+30+1,_Context->y_Auto2720+90+1,510,16,vfh[1],16,0,_Context->buffer_FileName,255,0);
	_Context->trigger_ChoixFileName=visual_trigger_code(_Context->msg_ChoixFileName[_Context->language],strlen(_Context->msg_ChoixFileName[_Context->language]));
	visual_button(_Context->x_Auto2720+550,_Context->y_Auto2720+90,20,16,vfh[2],27,24,_Context->msg_ChoixFileName[_Context->language],strlen(_Context->msg_ChoixFileName[_Context->language]),0);
	visual_text(_Context->x_Auto2720+30,_Context->y_Auto2720+130,135,20,vfh[2],16,0,_Context->msg_MsgSeparateur[_Context->language],strlen(_Context->msg_MsgSeparateur[_Context->language]),257);
	visual_select(_Context->x_Auto2720+170,_Context->y_Auto2720+130,130,20,vfh[1],0,0,parse_selection(_Context->msg_Separator[_Context->language],&_Context->value_Separator),0);
	_Context->trigger_Auto2723=visual_trigger_code(_Context->msg_Auto2723[_Context->language],strlen(_Context->msg_Auto2723[_Context->language]));
	visual_button(_Context->x_Auto2720+30,_Context->y_Auto2720+180,56,48,vfh[2],34,0,_Context->msg_Auto2723[_Context->language],strlen(_Context->msg_Auto2723[_Context->language]),1040);
	_Context->trigger_Auto2724=visual_trigger_code(_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]));
	visual_button(_Context->x_Auto2720+510,_Context->y_Auto2720+180,56,48,vfh[2],34,0,_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]),1040);
	visual_thaw(_Context->x_Auto2720,_Context->y_Auto2720,600,250);

	return(0);
}

private int ChoixFileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The Select button allows access yto the file selection dialog frame ";
			mptr[1]="allowing proimpted selection of the filename.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2723_help()
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

private int Auto2724_help()
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

private int Auto2720action(struct accept_elabels_parameters_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_elabels_parameters_hide(_Context);

		_Context->x_Auto2720 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto2720 < 0) { _Context->x_Auto2720=0; }
		_Context->y_Auto2720 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto2720 < 0) { _Context->y_Auto2720=0; }
			accept_elabels_parameters_show(_Context);

		visual_thaw(_Context->x_Auto2720,_Context->y_Auto2720,600,250);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_ChoixFileName_event(struct accept_elabels_parameters_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_TXT);
		accept_elabels_parameters_show(_Context);
;
	return(-1);
}
private int on_Auto2723_event(struct accept_elabels_parameters_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto2724_event(struct accept_elabels_parameters_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_elabels_parameters_event(
struct accept_elabels_parameters_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_ChoixFileName == mb ) return(3);
		if (_Context->trigger_Auto2723 == mb ) return(5);
		if (_Context->trigger_Auto2724 == mb ) return(6);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3030)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto2720+579) )  
	&&  (my >= (_Context->y_Auto2720+4) )  
	&&  (mx <= (_Context->x_Auto2720+596) )  
	&&  (my <= (_Context->y_Auto2720+20) )) {
		return(1);	/* Auto2720 */

		}
	if ((mx >= (_Context->x_Auto2720+563) )  
	&&  (my >= (_Context->y_Auto2720+4) )  
	&&  (mx <= (_Context->x_Auto2720+580) )  
	&&  (my <= (_Context->y_Auto2720+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("velabel.htm");
			};
		return(-1);	/* Auto2720 */

		}
	if ((mx >= (_Context->x_Auto2720+547) )  
	&&  (my >= (_Context->y_Auto2720+4) )  
	&&  (mx <= (_Context->x_Auto2720+564) )  
	&&  (my <= (_Context->y_Auto2720+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_elabels_parameters_show(_Context);
		return(-1);	/* Auto2720 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto2720+4) )  
		&&  (my >= (_Context->y_Auto2720+4) )  
		&&  (mx <= (_Context->x_Auto2720+532) )  
		&&  (my <= (_Context->y_Auto2720+20) )) {
			return( Auto2720action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto2720+30) ) 
	&&  ( my >= (_Context->y_Auto2720+90) ) 
	&&  ( mx <= (_Context->x_Auto2720+30+510) ) 
	&&  ( my <= (_Context->y_Auto2720+90+16))) {
		return(2); /* FileName */
		}
	if (( mx >= (_Context->x_Auto2720+550) ) 
	&&  ( my >= (_Context->y_Auto2720+90) ) 
	&&  ( mx <= (_Context->x_Auto2720+550+20) ) 
	&&  ( my <= (_Context->y_Auto2720+90+16))) {
		return(3); /* ChoixFileName */
		}
	if (( mx >= (_Context->x_Auto2720+170+0) ) 
	&&  ( my >= (_Context->y_Auto2720+130) ) 
	&&  ( mx <= (_Context->x_Auto2720+170+130) ) 
	&&  ( my <= (_Context->y_Auto2720+130+16))) {
		return(4); /* Separator */
		}
	if (( mx >= (_Context->x_Auto2720+30) ) 
	&&  ( my >= (_Context->y_Auto2720+180) ) 
	&&  ( mx <= (_Context->x_Auto2720+30+56) ) 
	&&  ( my <= (_Context->y_Auto2720+180+48))) {
		return(5); /* Auto2723 */
		}
	if (( mx >= (_Context->x_Auto2720+510) ) 
	&&  ( my >= (_Context->y_Auto2720+180) ) 
	&&  ( mx <= (_Context->x_Auto2720+510+56) ) 
	&&  ( my <= (_Context->y_Auto2720+180+48))) {
		return(6); /* Auto2724 */
		}

	return(-1);
}


public	int	accept_elabels_parameters_focus(struct accept_elabels_parameters_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FileName */
				_Context->keycode = visual_edit(_Context->x_Auto2720+30+1,_Context->y_Auto2720+90+1,510,16,vfh[1],_Context->buffer_FileName,255);
			break;
			case	0x3 :
				/* ChoixFileName */
				_Context->trigger_ChoixFileName=visual_trigger_code(_Context->msg_ChoixFileName[_Context->language],strlen(_Context->msg_ChoixFileName[_Context->language]));
				visual_button(_Context->x_Auto2720+550,_Context->y_Auto2720+90,20,16,vfh[2],27,24,_Context->msg_ChoixFileName[_Context->language],strlen(_Context->msg_ChoixFileName[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_ChoixFileName=visual_trigger_code(_Context->msg_ChoixFileName[_Context->language],strlen(_Context->msg_ChoixFileName[_Context->language]));
	visual_button(_Context->x_Auto2720+550,_Context->y_Auto2720+90,20,16,vfh[2],27,24,_Context->msg_ChoixFileName[_Context->language],strlen(_Context->msg_ChoixFileName[_Context->language]),0);
				break;
			case	0x4 :
				/* Separator */
				_Context->keycode = visual_select(_Context->x_Auto2720+170,_Context->y_Auto2720+130,130,20,vfh[1],0,0,parse_selection(_Context->msg_Separator[_Context->language],&_Context->value_Separator),6);
				break;
			case	0x5 :
				/* Auto2723 */
				_Context->trigger_Auto2723=visual_trigger_code(_Context->msg_Auto2723[_Context->language],strlen(_Context->msg_Auto2723[_Context->language]));
				visual_button(_Context->x_Auto2720+30,_Context->y_Auto2720+180,56,48,vfh[2],34,0,_Context->msg_Auto2723[_Context->language],strlen(_Context->msg_Auto2723[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2723=visual_trigger_code(_Context->msg_Auto2723[_Context->language],strlen(_Context->msg_Auto2723[_Context->language]));
	visual_button(_Context->x_Auto2720+30,_Context->y_Auto2720+180,56,48,vfh[2],34,0,_Context->msg_Auto2723[_Context->language],strlen(_Context->msg_Auto2723[_Context->language]),1040);
				break;
			case	0x6 :
				/* Auto2724 */
				_Context->trigger_Auto2724=visual_trigger_code(_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]));
				visual_button(_Context->x_Auto2720+510,_Context->y_Auto2720+180,56,48,vfh[2],34,0,_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2724=visual_trigger_code(_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]));
	visual_button(_Context->x_Auto2720+510,_Context->y_Auto2720+180,56,48,vfh[2],34,0,_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]),1040);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_elabels_parameters_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=6;
			accept_elabels_parameters_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_elabels_parameters_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x3 :
						if (ChoixFileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Auto2723_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (Auto2724_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto2720 */
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
					/* ChoixFileName */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFileName=visual_trigger_code(_Context->msg_ChoixFileName[_Context->language],strlen(_Context->msg_ChoixFileName[_Context->language]));
						visual_button(_Context->x_Auto2720+550,_Context->y_Auto2720+90,20,16,vfh[2],27,24,_Context->msg_ChoixFileName[_Context->language],strlen(_Context->msg_ChoixFileName[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFileName=visual_trigger_code(_Context->msg_ChoixFileName[_Context->language],strlen(_Context->msg_ChoixFileName[_Context->language]));
	visual_button(_Context->x_Auto2720+550,_Context->y_Auto2720+90,20,16,vfh[2],27,24,_Context->msg_ChoixFileName[_Context->language],strlen(_Context->msg_ChoixFileName[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFileName_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Separator */
					continue;
				case	0x5 :
					/* Auto2723 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2723=visual_trigger_code(_Context->msg_Auto2723[_Context->language],strlen(_Context->msg_Auto2723[_Context->language]));
						visual_button(_Context->x_Auto2720+30,_Context->y_Auto2720+180,56,48,vfh[2],34,0,_Context->msg_Auto2723[_Context->language],strlen(_Context->msg_Auto2723[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2723=visual_trigger_code(_Context->msg_Auto2723[_Context->language],strlen(_Context->msg_Auto2723[_Context->language]));
	visual_button(_Context->x_Auto2720+30,_Context->y_Auto2720+180,56,48,vfh[2],34,0,_Context->msg_Auto2723[_Context->language],strlen(_Context->msg_Auto2723[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2723_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Auto2724 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2724=visual_trigger_code(_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]));
						visual_button(_Context->x_Auto2720+510,_Context->y_Auto2720+180,56,48,vfh[2],34,0,_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2724=visual_trigger_code(_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]));
	visual_button(_Context->x_Auto2720+510,_Context->y_Auto2720+180,56,48,vfh[2],34,0,_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2724_event(_Context)) != -1) break;

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

public	int	accept_elabels_parameters(
	char * pFileName,
	char * pSeparator)
{
	int	status=0;
	struct accept_elabels_parameters_context * _Context=(struct accept_elabels_parameters_context*) 0;
	status = accept_elabels_parameters_create(
	&_Context,
	 pFileName,
	 pSeparator);
	if ( status != 0) return(status);
	status = accept_elabels_parameters_show(_Context);
		enter_modal();
	status = accept_elabels_parameters_focus(_Context);
		leave_modal();
	status = accept_elabels_parameters_hide(_Context);
	status = accept_elabels_parameters_remove(
	_Context,
	 pFileName,
	 pSeparator);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _velabel_c */
