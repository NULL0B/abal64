
#ifndef _vcompose_c
#define _vcompose_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vcompose.xml  */
/* Target         : vcompose.c  */
/* Identification : 0.0-1100085342-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto5287   "Sing : Version 1.0a"
#define fr_Auto5287   "Sing : Version 1.0a"
#define en_Auto6250   "skin.gif"
#define fr_Auto6250   "skin.gif"
#define en_Auto5292   "Widget Syntax Composer"
#define fr_Auto5292   "Assistance de Composition Syntaxique"
#define it_Auto5292   ""
#define es_Auto5292   ""
#define de_Auto5292   ""
#define nl_Auto5292   ""
#define pt_Auto5292   ""
#define xx_Auto5292   ""
#define en_Auto5293   "Result Syntax"
#define fr_Auto5293   "Syntaxe Resultat"
#define it_Auto5293   ""
#define es_Auto5293   ""
#define de_Auto5293   ""
#define nl_Auto5293   ""
#define pt_Auto5293   ""
#define xx_Auto5293   ""
#define en_Concatenate   "Concatentate"
#define fr_Concatenate   "Concatener"
#define it_Concatenate   "Concatentate"
#define es_Concatenate   "Concatentate"
#define de_Concatenate   "Concatentate"
#define nl_Concatenate   "Concatentate"
#define pt_Concatenate   "Concatentate"
#define xx_Concatenate   "Concatentate"
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_Compose   "Co&mpose"
#define fr_Compose   "Co&mposer"
#define it_Compose   "Co&mpose"
#define es_Compose   "Co&mpose"
#define de_Compose   "Co&mpose"
#define nl_Compose   "Co&mpose"
#define pt_Compose   "Co&mpose"
#define xx_Compose   "Co&mpose"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
static int	vfh[10];

private struct accept_form_syntax_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto5287[8];
	int	x_Auto5287;
	int	y_Auto5287;
	int	w_Auto5287;
	int	h_Auto5287;
	char * msg_Auto6250[8];
	char * msg_Auto5292[8];
	char * msg_Auto5293[8];
	char	buffer_Result[435];
	char * msg_ClassList[8];
	int	value_ClassList;
	char * msg_WidgetList[8];
	int	value_WidgetList;
	char * msg_MethodList[8];
	int	value_MethodList;
	char * msg_Concatenate[8];
	int	trigger_Concatenate;
	int	value_Concatenate;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Compose[8];
	int	trigger_Compose;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[6];
	};

public	int	accept_form_syntax_create(
	struct accept_form_syntax_context ** cptr,
	char * pResult,
	char * pClassList,
	char * pWidgetList,
	char * pMethodList,
	char * pConcatenate)
{

	int i;
	struct accept_form_syntax_context * _Context=(struct accept_form_syntax_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_form_syntax_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=9;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Result, 434, pResult);
		visual_transferin((void *) 0, 0, pClassList);
		if (!( pClassList )) _Context->value_ClassList=0;
		else	_Context->value_ClassList = *((int *)pClassList);
		visual_transferin((void *) 0, 0, pWidgetList);
		if (!( pWidgetList )) _Context->value_WidgetList=0;
		else	_Context->value_WidgetList = *((int *)pWidgetList);
		visual_transferin((void *) 0, 0, pMethodList);
		if (!( pMethodList )) _Context->value_MethodList=0;
		else	_Context->value_MethodList = *((int *)pMethodList);
		visual_transferin((void *) 0, 0, pConcatenate);
		if (!( pConcatenate )) _Context->value_Concatenate=0;
		else	_Context->value_Concatenate = *((int *)pConcatenate);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto5287[i]=" ";
	_Context->msg_Auto5287[0]=en_Auto5287;
	_Context->msg_Auto5287[1]=fr_Auto5287;
	_Context->x_Auto5287=130;
	_Context->y_Auto5287=140;
	_Context->w_Auto5287=540;
	_Context->h_Auto5287=320;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto6250[i]=" ";
	_Context->msg_Auto6250[0]=en_Auto6250;
	_Context->msg_Auto6250[1]=fr_Auto6250;
	for (i=0; i < 8; i++)_Context->msg_Auto5292[i]=" ";
	_Context->msg_Auto5292[0]=en_Auto5292;
	_Context->msg_Auto5292[1]=fr_Auto5292;
	_Context->msg_Auto5292[2]=it_Auto5292;
	_Context->msg_Auto5292[3]=es_Auto5292;
	_Context->msg_Auto5292[4]=de_Auto5292;
	_Context->msg_Auto5292[5]=nl_Auto5292;
	_Context->msg_Auto5292[6]=pt_Auto5292;
	_Context->msg_Auto5292[7]=xx_Auto5292;
	for (i=0; i < 8; i++)_Context->msg_Auto5293[i]=" ";
	_Context->msg_Auto5293[0]=en_Auto5293;
	_Context->msg_Auto5293[1]=fr_Auto5293;
	_Context->msg_Auto5293[2]=it_Auto5293;
	_Context->msg_Auto5293[3]=es_Auto5293;
	_Context->msg_Auto5293[4]=de_Auto5293;
	_Context->msg_Auto5293[5]=nl_Auto5293;
	_Context->msg_Auto5293[6]=pt_Auto5293;
	_Context->msg_Auto5293[7]=xx_Auto5293;
	for (i=0; i < 8; i++)_Context->msg_ClassList[i]=" ";
	_Context->value_ClassList=5;
	for (i=0; i < 8; i++)_Context->msg_WidgetList[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_MethodList[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_Concatenate[i]=" ";
	_Context->msg_Concatenate[0]=en_Concatenate;
	_Context->msg_Concatenate[1]=fr_Concatenate;
	_Context->msg_Concatenate[2]=it_Concatenate;
	_Context->msg_Concatenate[3]=es_Concatenate;
	_Context->msg_Concatenate[4]=de_Concatenate;
	_Context->msg_Concatenate[5]=nl_Concatenate;
	_Context->msg_Concatenate[6]=pt_Concatenate;
	_Context->msg_Concatenate[7]=xx_Concatenate;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Compose[i]=" ";
	_Context->msg_Compose[0]=en_Compose;
	_Context->msg_Compose[1]=fr_Compose;
	_Context->msg_Compose[2]=it_Compose;
	_Context->msg_Compose[3]=es_Compose;
	_Context->msg_Compose[4]=de_Compose;
	_Context->msg_Compose[5]=nl_Compose;
	_Context->msg_Compose[6]=pt_Compose;
	_Context->msg_Compose[7]=xx_Compose;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto5287,_Context->y_Auto5287,540+10,320+10);
	return(0);
}

public 	int	accept_form_syntax_hide(struct accept_form_syntax_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto5287,_Context->y_Auto5287);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_form_syntax_remove(
	struct accept_form_syntax_context * _Context,
	char * pResult,
	char * pClassList,
	char * pWidgetList,
	char * pMethodList,
	char * pConcatenate)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Result, 434, pResult);
		visual_transferout((void *) 0, 0, pClassList);
		if ( pClassList != (char *) 0)
			*((int*)pClassList) = _Context->value_ClassList;
		visual_transferout((void *) 0, 0, pWidgetList);
		if ( pWidgetList != (char *) 0)
			*((int*)pWidgetList) = _Context->value_WidgetList;
		visual_transferout((void *) 0, 0, pMethodList);
		if ( pMethodList != (char *) 0)
			*((int*)pMethodList) = _Context->value_MethodList;
		visual_transferout((void *) 0, 0, pConcatenate);
		if ( pConcatenate != (char *) 0)
			*((int*)pConcatenate) = _Context->value_Concatenate;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_form_syntax_show(struct accept_form_syntax_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto5287,_Context->y_Auto5287);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto5287,_Context->y_Auto5287,540,320,vfh[1],_Context->msg_Auto5287[_Context->language],strlen(_Context->msg_Auto5287[_Context->language]),0x407);
	visual_image(_Context->x_Auto5287+3,_Context->y_Auto5287+21,532,294,_Context->msg_Auto6250[_Context->language],4);
	visual_text(_Context->x_Auto5287+10,_Context->y_Auto5287+30,520,20,vfh[3],16,0,_Context->msg_Auto5292[_Context->language],strlen(_Context->msg_Auto5292[_Context->language]),1283);
	visual_frame(_Context->x_Auto5287+10,_Context->y_Auto5287+50,520,260,3);
	visual_text(_Context->x_Auto5287+20,_Context->y_Auto5287+100,500,40,vfh[2],16,0,_Context->msg_Auto5293[_Context->language],strlen(_Context->msg_Auto5293[_Context->language]),1283);
	visual_frame(_Context->x_Auto5287+20,_Context->y_Auto5287+140,500+2,120+2,5);
	visual_text(_Context->x_Auto5287+20+1,_Context->y_Auto5287+140+1,500,120,vfh[1],16,0,_Context->buffer_Result,434,0);
	visual_select(_Context->x_Auto5287+20,_Context->y_Auto5287+60,160,208,vfh[1],27,28,parse_selection(WidgetClassList,&_Context->value_ClassList),768);
	visual_select(_Context->x_Auto5287+190,_Context->y_Auto5287+60,160,208,vfh[1],27,28,parse_selection(FormWidgetList(_Context->value_ClassList),&_Context->value_WidgetList),768);
	visual_select(_Context->x_Auto5287+360,_Context->y_Auto5287+60,160,200,vfh[1],27,28,parse_selection(FormMethodList(_Context->value_WidgetList),&_Context->value_MethodList),768);
	_Context->trigger_Concatenate=visual_trigger_code(_Context->msg_Concatenate[_Context->language],strlen(_Context->msg_Concatenate[_Context->language]));
	visual_check(_Context->x_Auto5287+270,_Context->y_Auto5287+270,140,32,vfh[2],28,28,_Context->msg_Concatenate[_Context->language],strlen(_Context->msg_Concatenate[_Context->language]),_Context->value_Concatenate|0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto5287+20,_Context->y_Auto5287+270,84,32,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Compose=visual_trigger_code(_Context->msg_Compose[_Context->language],strlen(_Context->msg_Compose[_Context->language]));
	visual_button(_Context->x_Auto5287+160,_Context->y_Auto5287+270,84,32,vfh[2],16,0,_Context->msg_Compose[_Context->language],strlen(_Context->msg_Compose[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto5287+440,_Context->y_Auto5287+270,84,32,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_thaw(_Context->x_Auto5287,_Context->y_Auto5287,540,320);
	visual_thaw(_Context->x_Auto5287,_Context->y_Auto5287,540,320);

	return(0);
}

private int Auto5287action(struct accept_form_syntax_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_form_syntax_hide(_Context);

		_Context->x_Auto5287 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto5287 < 0) { _Context->x_Auto5287=0; }
		_Context->y_Auto5287 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto5287 < 0) { _Context->y_Auto5287=0; }
			accept_form_syntax_show(_Context);

		visual_thaw(_Context->x_Auto5287,_Context->y_Auto5287,540,320);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_form_syntax_context * _Context) {
	return(13);
	return(-1);
}
private int on_Compose_event(struct accept_form_syntax_context * _Context) {
	FormWidgetCompose(_Context->value_ClassList,_Context->value_WidgetList,_Context->value_MethodList,
	_Context->buffer_Result,434,_Context->value_Concatenate);
	visual_frame(_Context->x_Auto5287+20,_Context->y_Auto5287+140,500+2,120+2,5);
visual_text(_Context->x_Auto5287+20+1,_Context->y_Auto5287+140+1,500,120,vfh[1],16,0,_Context->buffer_Result,434,0);
;
	_Context->value_Concatenate=1;
		_Context->trigger_Concatenate=visual_trigger_code(_Context->msg_Concatenate[_Context->language],strlen(_Context->msg_Concatenate[_Context->language]));
	visual_check(_Context->x_Auto5287+270,_Context->y_Auto5287+270,140,32,vfh[2],28,28,_Context->msg_Concatenate[_Context->language],strlen(_Context->msg_Concatenate[_Context->language]),_Context->value_Concatenate|0);
;
	return(-1);
}
private int on_Cancel_event(struct accept_form_syntax_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_form_syntax_event(
struct accept_form_syntax_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Concatenate == mb ) return(6);
		if (_Context->trigger_Accept == mb ) return(7);
		if (_Context->trigger_Compose == mb ) return(8);
		if (_Context->trigger_Cancel == mb ) return(9);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto5287+519) )  
	&&  (my >= (_Context->y_Auto5287+4) )  
	&&  (mx <= (_Context->x_Auto5287+536) )  
	&&  (my <= (_Context->y_Auto5287+20) )) {
		return(1);	/* Auto5287 */

		}
	if ((mx >= (_Context->x_Auto5287+503) )  
	&&  (my >= (_Context->y_Auto5287+4) )  
	&&  (mx <= (_Context->x_Auto5287+520) )  
	&&  (my <= (_Context->y_Auto5287+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcompose.htm");
			};
		return(-1);	/* Auto5287 */

		}
	if ((mx >= (_Context->x_Auto5287+487) )  
	&&  (my >= (_Context->y_Auto5287+4) )  
	&&  (mx <= (_Context->x_Auto5287+504) )  
	&&  (my <= (_Context->y_Auto5287+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_form_syntax_show(_Context);
		return(-1);	/* Auto5287 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto5287+4) )  
		&&  (my >= (_Context->y_Auto5287+4) )  
		&&  (mx <= (_Context->x_Auto5287+472) )  
		&&  (my <= (_Context->y_Auto5287+20) )) {
			return( Auto5287action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto5287+20) ) 
	&&  ( my >= (_Context->y_Auto5287+140) ) 
	&&  ( mx <= (_Context->x_Auto5287+20+500) ) 
	&&  ( my <= (_Context->y_Auto5287+140+120))) {
		return(2); /* Result */
		}
	if (( mx >= (_Context->x_Auto5287+20+0) ) 
	&&  ( my >= (_Context->y_Auto5287+60) ) 
	&&  ( mx <= (_Context->x_Auto5287+20+160) ) 
	&&  ( my <= (_Context->y_Auto5287+60+16))) {
		return(3); /* ClassList */
		}
	if (( mx >= (_Context->x_Auto5287+190+0) ) 
	&&  ( my >= (_Context->y_Auto5287+60) ) 
	&&  ( mx <= (_Context->x_Auto5287+190+160) ) 
	&&  ( my <= (_Context->y_Auto5287+60+16))) {
		return(4); /* WidgetList */
		}
	if (( mx >= (_Context->x_Auto5287+360+0) ) 
	&&  ( my >= (_Context->y_Auto5287+60) ) 
	&&  ( mx <= (_Context->x_Auto5287+360+160) ) 
	&&  ( my <= (_Context->y_Auto5287+60+16))) {
		return(5); /* MethodList */
		}
	if (( mx >= (_Context->x_Auto5287+270) ) 
	&&  ( my >= (_Context->y_Auto5287+270) ) 
	&&  ( mx <= (_Context->x_Auto5287+270+140) ) 
	&&  ( my <= (_Context->y_Auto5287+270+32))) {
		return(6); /* Concatenate */
		}
	if (( mx >= (_Context->x_Auto5287+20) ) 
	&&  ( my >= (_Context->y_Auto5287+270) ) 
	&&  ( mx <= (_Context->x_Auto5287+20+84) ) 
	&&  ( my <= (_Context->y_Auto5287+270+32))) {
		return(7); /* Accept */
		}
	if (( mx >= (_Context->x_Auto5287+160) ) 
	&&  ( my >= (_Context->y_Auto5287+270) ) 
	&&  ( mx <= (_Context->x_Auto5287+160+84) ) 
	&&  ( my <= (_Context->y_Auto5287+270+32))) {
		return(8); /* Compose */
		}
	if (( mx >= (_Context->x_Auto5287+440) ) 
	&&  ( my >= (_Context->y_Auto5287+270) ) 
	&&  ( mx <= (_Context->x_Auto5287+440+84) ) 
	&&  ( my <= (_Context->y_Auto5287+270+32))) {
		return(9); /* Cancel */
		}

	return(-1);
}


public	int	accept_form_syntax_focus(struct accept_form_syntax_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Result */
				_Context->keycode = visual_edit(_Context->x_Auto5287+20+1,_Context->y_Auto5287+140+1,500,120,vfh[1],_Context->buffer_Result,434);
			break;
			case	0x3 :
				/* ClassList */
				_Context->keycode = visual_select(_Context->x_Auto5287+20,_Context->y_Auto5287+60,160,208,vfh[1],27,28,parse_selection(WidgetClassList,&_Context->value_ClassList),770);
				break;
			case	0x4 :
				/* WidgetList */
				_Context->keycode = visual_select(_Context->x_Auto5287+190,_Context->y_Auto5287+60,160,208,vfh[1],27,28,parse_selection(FormWidgetList(_Context->value_ClassList),&_Context->value_WidgetList),770);
				break;
			case	0x5 :
				/* MethodList */
				_Context->keycode = visual_select(_Context->x_Auto5287+360,_Context->y_Auto5287+60,160,200,vfh[1],27,28,parse_selection(FormMethodList(_Context->value_WidgetList),&_Context->value_MethodList),770);
				break;
			case	0x6 :
				/* Concatenate */
				visual_check(_Context->x_Auto5287+270,_Context->y_Auto5287+270,140,32,vfh[2],28,28,_Context->msg_Concatenate[_Context->language],strlen(_Context->msg_Concatenate[_Context->language]),(_Context->value_Concatenate |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto5287+270,_Context->y_Auto5287+270,140,32,vfh[2],28,28,_Context->msg_Concatenate[_Context->language],strlen(_Context->msg_Concatenate[_Context->language]),(_Context->value_Concatenate |0));
				break;
			case	0x7 :
				/* Accept */
				visual_button(_Context->x_Auto5287+20,_Context->y_Auto5287+270,84,32,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto5287+20,_Context->y_Auto5287+270,84,32,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0x8 :
				/* Compose */
				visual_button(_Context->x_Auto5287+160,_Context->y_Auto5287+270,84,32,vfh[2],16,0,_Context->msg_Compose[_Context->language],strlen(_Context->msg_Compose[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto5287+160,_Context->y_Auto5287+270,84,32,vfh[2],16,0,_Context->msg_Compose[_Context->language],strlen(_Context->msg_Compose[_Context->language]),0);
				break;
			case	0x9 :
				/* Cancel */
				visual_button(_Context->x_Auto5287+440,_Context->y_Auto5287+270,84,32,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto5287+440,_Context->y_Auto5287+270,84,32,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_form_syntax_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=9;
			accept_form_syntax_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_form_syntax_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto5287 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Result */
						continue;
					case	0x3 :
						/* ClassList */
						continue;
					case	0x4 :
						/* WidgetList */
						continue;
					case	0x5 :
						/* MethodList */
						continue;
					case	0x6 :
						/* Concatenate */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Concatenate += 1;
							_Context->value_Concatenate &= 1;
							}
						continue;
					case	0x7 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto5287+20,_Context->y_Auto5287+270,84,32,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto5287+20,_Context->y_Auto5287+270,84,32,vfh[2],16,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0x8 :
						/* Compose */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto5287+160,_Context->y_Auto5287+270,84,32,vfh[2],16,0,_Context->msg_Compose[_Context->language],strlen(_Context->msg_Compose[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto5287+160,_Context->y_Auto5287+270,84,32,vfh[2],16,0,_Context->msg_Compose[_Context->language],strlen(_Context->msg_Compose[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Compose_event(_Context)) != -1) break;

							}
						continue;
					case	0x9 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto5287+440,_Context->y_Auto5287+270,84,32,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto5287+440,_Context->y_Auto5287+270,84,32,vfh[2],16,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
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

public	int	accept_form_syntax(
	char * pResult,
	char * pClassList,
	char * pWidgetList,
	char * pMethodList,
	char * pConcatenate)
{
	int	status=0;
	struct accept_form_syntax_context * _Context=(struct accept_form_syntax_context*) 0;
	status = accept_form_syntax_create(
	&_Context,
	 pResult,
	 pClassList,
	 pWidgetList,
	 pMethodList,
	 pConcatenate);
	if ( status != 0) return(status);
	status = accept_form_syntax_show(_Context);
		enter_modal();
	status = accept_form_syntax_focus(_Context);
		leave_modal();
	status = accept_form_syntax_hide(_Context);
	status = accept_form_syntax_remove(
	_Context,
	 pResult,
	 pClassList,
	 pWidgetList,
	 pMethodList,
	 pConcatenate);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcompose_c */
