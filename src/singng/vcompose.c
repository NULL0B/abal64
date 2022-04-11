
#ifndef _vcompose_c
#define _vcompose_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vcompose.xml                                             */
/* Target         : vcompose.c                                               */
/* Identification : 0.0-1177511934-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__Auto2712   ""
#define fr__Auto2712   ""
#define it__Auto2712   ""
#define es__Auto2712   ""
#define de__Auto2712   ""
#define nl__Auto2712   ""
#define pt__Auto2712   ""
#define xx__Auto2712   ""
#define en_Auto2713   "Widget Syntax Composer"
#define fr_Auto2713   "Assistant syntaxique"
#define it_Auto2713   "Widget Syntax Composer"
#define es_Auto2713   "Widget Syntax Composer"
#define de_Auto2713   "Widget Syntax Composer"
#define nl_Auto2713   "Widget Syntax Composer"
#define pt_Auto2713   "Widget Syntax Composer"
#define xx_Auto2713   "Widget Syntax Composer"
#define en__Auto2713   ""
#define fr__Auto2713   ""
#define it__Auto2713   ""
#define es__Auto2713   ""
#define de__Auto2713   ""
#define nl__Auto2713   ""
#define pt__Auto2713   ""
#define xx__Auto2713   ""
#define en_Auto2714   "Result Syntax"
#define fr_Auto2714   "Syntaxe r‚sultat"
#define it_Auto2714   "Result Syntax"
#define es_Auto2714   "Result Syntax"
#define de_Auto2714   "Result Syntax"
#define nl_Auto2714   "Result Syntax"
#define pt_Auto2714   "Result Syntax"
#define xx_Auto2714   "Result Syntax"
#define en__Auto2714   ""
#define fr__Auto2714   ""
#define it__Auto2714   ""
#define es__Auto2714   ""
#define de__Auto2714   ""
#define nl__Auto2714   ""
#define pt__Auto2714   ""
#define xx__Auto2714   ""
#define en_Result   ""
#define en_Concatenate   "Concatentate"
#define fr_Concatenate   "Concat‚ner"
#define it_Concatenate   "Concatentate"
#define es_Concatenate   "Concatentate"
#define de_Concatenate   "Concatentate"
#define nl_Concatenate   "Concatentate"
#define pt_Concatenate   "Concatentate"
#define xx_Concatenate   "Concatentate"
#define en__Concatenate   ""
#define fr__Concatenate   ""
#define it__Concatenate   ""
#define es__Concatenate   ""
#define de__Concatenate   ""
#define nl__Concatenate   ""
#define pt__Concatenate   ""
#define xx__Concatenate   ""
#define en_Auto2715   "ok.gif"
#define fr_Auto2715   "ok.gif"
#define it_Auto2715   "ok.gif"
#define es_Auto2715   "ok.gif"
#define de_Auto2715   "ok.gif"
#define nl_Auto2715   "ok.gif"
#define pt_Auto2715   "ok.gif"
#define xx_Auto2715   "ok.gif"
#define en_Compose   "Co&mpose"
#define fr_Compose   "Co&mposer"
#define it_Compose   "Co&mpose"
#define es_Compose   "Co&mpose"
#define de_Compose   "Co&mpose"
#define nl_Compose   "Co&mpose"
#define pt_Compose   "Co&mpose"
#define xx_Compose   "Co&mpose"
#define en__Compose   ""
#define fr__Compose   ""
#define it__Compose   ""
#define es__Compose   ""
#define de__Compose   ""
#define nl__Compose   ""
#define pt__Compose   ""
#define xx__Compose   ""
#define en_Auto2716   "cancel.gif"
#define fr_Auto2716   "cancel.gif"
#define it_Auto2716   "cancel.gif"
#define es_Auto2716   "cancel.gif"
#define de_Auto2716   "cancel.gif"
#define nl_Auto2716   "cancel.gif"
#define pt_Auto2716   "cancel.gif"
#define xx_Auto2716   "cancel.gif"

private struct accept_form_syntax_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto2712[8];
	char * hint_Auto2712[8];
	int	x_Auto2712;
	int	y_Auto2712;
	int	w_Auto2712;
	int	h_Auto2712;
	char * msg_Auto2713[8];
	char * hint_Auto2713[8];
	char * msg_Auto2714[8];
	char * hint_Auto2714[8];
	char * hint_Result[8];
	char	buffer_Result[931];
	char * msg_ClassList[8];
	char * hint_ClassList[8];
	int	value_ClassList;
	char * msg_WidgetList[8];
	char * hint_WidgetList[8];
	int	value_WidgetList;
	char * msg_MethodList[8];
	char * hint_MethodList[8];
	int	value_MethodList;
	char * msg_Concatenate[8];
	int	trigger_Concatenate;
	char * hint_Concatenate[8];
	int	value_Concatenate;
	char * msg_Auto2715[8];
	int	trigger_Auto2715;
	char * hint_Auto2715[8];
	char * msg_Compose[8];
	int	trigger_Compose;
	char * hint_Compose[8];
	char * msg_Auto2716[8];
	int	trigger_Auto2716;
	char * hint_Auto2716[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[6];
	};
static int	vfh[16];

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
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("font10.fmf",10);
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
		visual_transferin(_Context->buffer_Result, 930, pResult);
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
	for (i=0; i < 8; i++)_Context->msg_Auto2712[i]=" ";
	_Context->hint_Auto2712[0]=en__Auto2712;
	_Context->hint_Auto2712[1]=fr__Auto2712;
	_Context->hint_Auto2712[2]=it__Auto2712;
	_Context->hint_Auto2712[3]=es__Auto2712;
	_Context->hint_Auto2712[4]=de__Auto2712;
	_Context->hint_Auto2712[5]=nl__Auto2712;
	_Context->hint_Auto2712[6]=pt__Auto2712;
	_Context->hint_Auto2712[7]=xx__Auto2712;
	_Context->x_Auto2712=130;
	_Context->y_Auto2712=75;
	_Context->w_Auto2712=540;
	_Context->h_Auto2712=450;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2713[i]=" ";
	_Context->msg_Auto2713[0]=en_Auto2713;
	_Context->msg_Auto2713[1]=fr_Auto2713;
	_Context->msg_Auto2713[2]=it_Auto2713;
	_Context->msg_Auto2713[3]=es_Auto2713;
	_Context->msg_Auto2713[4]=de_Auto2713;
	_Context->msg_Auto2713[5]=nl_Auto2713;
	_Context->msg_Auto2713[6]=pt_Auto2713;
	_Context->msg_Auto2713[7]=xx_Auto2713;
	_Context->hint_Auto2713[0]=en__Auto2713;
	_Context->hint_Auto2713[1]=fr__Auto2713;
	_Context->hint_Auto2713[2]=it__Auto2713;
	_Context->hint_Auto2713[3]=es__Auto2713;
	_Context->hint_Auto2713[4]=de__Auto2713;
	_Context->hint_Auto2713[5]=nl__Auto2713;
	_Context->hint_Auto2713[6]=pt__Auto2713;
	_Context->hint_Auto2713[7]=xx__Auto2713;
	for (i=0; i < 8; i++)_Context->msg_Auto2714[i]=" ";
	_Context->msg_Auto2714[0]=en_Auto2714;
	_Context->msg_Auto2714[1]=fr_Auto2714;
	_Context->msg_Auto2714[2]=it_Auto2714;
	_Context->msg_Auto2714[3]=es_Auto2714;
	_Context->msg_Auto2714[4]=de_Auto2714;
	_Context->msg_Auto2714[5]=nl_Auto2714;
	_Context->msg_Auto2714[6]=pt_Auto2714;
	_Context->msg_Auto2714[7]=xx_Auto2714;
	_Context->hint_Auto2714[0]=en__Auto2714;
	_Context->hint_Auto2714[1]=fr__Auto2714;
	_Context->hint_Auto2714[2]=it__Auto2714;
	_Context->hint_Auto2714[3]=es__Auto2714;
	_Context->hint_Auto2714[4]=de__Auto2714;
	_Context->hint_Auto2714[5]=nl__Auto2714;
	_Context->hint_Auto2714[6]=pt__Auto2714;
	_Context->hint_Auto2714[7]=xx__Auto2714;
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
	_Context->hint_Concatenate[0]=en__Concatenate;
	_Context->hint_Concatenate[1]=fr__Concatenate;
	_Context->hint_Concatenate[2]=it__Concatenate;
	_Context->hint_Concatenate[3]=es__Concatenate;
	_Context->hint_Concatenate[4]=de__Concatenate;
	_Context->hint_Concatenate[5]=nl__Concatenate;
	_Context->hint_Concatenate[6]=pt__Concatenate;
	_Context->hint_Concatenate[7]=xx__Concatenate;
	for (i=0; i < 8; i++)_Context->msg_Auto2715[i]=" ";
	_Context->msg_Auto2715[0]=en_Auto2715;
	_Context->msg_Auto2715[1]=fr_Auto2715;
	_Context->msg_Auto2715[2]=it_Auto2715;
	_Context->msg_Auto2715[3]=es_Auto2715;
	_Context->msg_Auto2715[4]=de_Auto2715;
	_Context->msg_Auto2715[5]=nl_Auto2715;
	_Context->msg_Auto2715[6]=pt_Auto2715;
	_Context->msg_Auto2715[7]=xx_Auto2715;
	for (i=0; i < 8; i++)_Context->msg_Compose[i]=" ";
	_Context->msg_Compose[0]=en_Compose;
	_Context->msg_Compose[1]=fr_Compose;
	_Context->msg_Compose[2]=it_Compose;
	_Context->msg_Compose[3]=es_Compose;
	_Context->msg_Compose[4]=de_Compose;
	_Context->msg_Compose[5]=nl_Compose;
	_Context->msg_Compose[6]=pt_Compose;
	_Context->msg_Compose[7]=xx_Compose;
	_Context->hint_Compose[0]=en__Compose;
	_Context->hint_Compose[1]=fr__Compose;
	_Context->hint_Compose[2]=it__Compose;
	_Context->hint_Compose[3]=es__Compose;
	_Context->hint_Compose[4]=de__Compose;
	_Context->hint_Compose[5]=nl__Compose;
	_Context->hint_Compose[6]=pt__Compose;
	_Context->hint_Compose[7]=xx__Compose;
	for (i=0; i < 8; i++)_Context->msg_Auto2716[i]=" ";
	_Context->msg_Auto2716[0]=en_Auto2716;
	_Context->msg_Auto2716[1]=fr_Auto2716;
	_Context->msg_Auto2716[2]=it_Auto2716;
	_Context->msg_Auto2716[3]=es_Auto2716;
	_Context->msg_Auto2716[4]=de_Auto2716;
	_Context->msg_Auto2716[5]=nl_Auto2716;
	_Context->msg_Auto2716[6]=pt_Auto2716;
	_Context->msg_Auto2716[7]=xx_Auto2716;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto2712,_Context->y_Auto2712,540+10,450+10);
	return(0);
}

public 	int	accept_form_syntax_hide(struct accept_form_syntax_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto2712,_Context->y_Auto2712);
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
		visual_transferout(_Context->buffer_Result, 930, pResult);
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
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto2712,_Context->y_Auto2712);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto2712,_Context->y_Auto2712,540,450,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto2712,_Context->y_Auto2712,540,450,vfh[1],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto2712+10,_Context->y_Auto2712+30,520,20,vfh[3],16,0,_Context->msg_Auto2713[_Context->language],strlen(_Context->msg_Auto2713[_Context->language]),1283);
	visual_frame(_Context->x_Auto2712+10,_Context->y_Auto2712+50,520,390,3);
	visual_text(_Context->x_Auto2712+20,_Context->y_Auto2712+90,500,40,vfh[2],16,0,_Context->msg_Auto2714[_Context->language],strlen(_Context->msg_Auto2714[_Context->language]),1283);
	visual_frame(_Context->x_Auto2712+20,_Context->y_Auto2712+130,496+2,240+2,5);
	visual_text(_Context->x_Auto2712+20+1,_Context->y_Auto2712+130+1,496,240,vfh[1],16,0,_Context->buffer_Result,930,0);
	visual_select(_Context->x_Auto2712+20,_Context->y_Auto2712+60,160,304,vfh[1],27,28,parse_selection(WidgetClassList,&_Context->value_ClassList),768);
	visual_select(_Context->x_Auto2712+190,_Context->y_Auto2712+60,160,304,vfh[1],27,28,parse_selection(FormWidgetList(_Context->value_ClassList),&_Context->value_WidgetList),768);
	visual_select(_Context->x_Auto2712+360,_Context->y_Auto2712+60,160,304,vfh[1],27,28,parse_selection(FormMethodList(_Context->value_WidgetList),&_Context->value_MethodList),768);
	_Context->trigger_Concatenate=visual_trigger_code(_Context->msg_Concatenate[_Context->language],strlen(_Context->msg_Concatenate[_Context->language]));
	visual_check(_Context->x_Auto2712+270,_Context->y_Auto2712+400,126,16,vfh[2],28,28,_Context->msg_Concatenate[_Context->language],strlen(_Context->msg_Concatenate[_Context->language]),_Context->value_Concatenate|0);
	_Context->trigger_Auto2715=visual_trigger_code(_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]));
	visual_button(_Context->x_Auto2712+20,_Context->y_Auto2712+380,56,48,vfh[2],34,0,_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]),1040);
	_Context->trigger_Compose=visual_trigger_code(_Context->msg_Compose[_Context->language],strlen(_Context->msg_Compose[_Context->language]));
	visual_button(_Context->x_Auto2712+160,_Context->y_Auto2712+390,84,32,vfh[2],16,0,_Context->msg_Compose[_Context->language],strlen(_Context->msg_Compose[_Context->language]),0);
	_Context->trigger_Auto2716=visual_trigger_code(_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]));
	visual_button(_Context->x_Auto2712+460,_Context->y_Auto2712+380,56,48,vfh[2],34,0,_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]),1040);
	visual_thaw(_Context->x_Auto2712,_Context->y_Auto2712,540,450);

	return(0);
}

private int Auto2712action(struct accept_form_syntax_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_form_syntax_hide(_Context);

		_Context->x_Auto2712 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto2712 < 0) { _Context->x_Auto2712=0; }
		_Context->y_Auto2712 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto2712 < 0) { _Context->y_Auto2712=0; }
			accept_form_syntax_show(_Context);

		visual_thaw(_Context->x_Auto2712,_Context->y_Auto2712,540,450);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto2715_event(struct accept_form_syntax_context * _Context) {
	return(13);
	return(-1);
}
private int on_Compose_event(struct accept_form_syntax_context * _Context) {
	FormWidgetCompose(_Context->value_ClassList,_Context->value_WidgetList,_Context->value_MethodList,
	_Context->buffer_Result,930,_Context->value_Concatenate);
	visual_frame(_Context->x_Auto2712+20,_Context->y_Auto2712+130,496+2,240+2,5);
visual_text(_Context->x_Auto2712+20+1,_Context->y_Auto2712+130+1,496,240,vfh[1],16,0,_Context->buffer_Result,930,0);
;
	_Context->value_Concatenate=1;
		_Context->trigger_Concatenate=visual_trigger_code(_Context->msg_Concatenate[_Context->language],strlen(_Context->msg_Concatenate[_Context->language]));
	visual_check(_Context->x_Auto2712+270,_Context->y_Auto2712+400,126,16,vfh[2],28,28,_Context->msg_Concatenate[_Context->language],strlen(_Context->msg_Concatenate[_Context->language]),_Context->value_Concatenate|0);
;
	return(-1);
}
private int on_Auto2716_event(struct accept_form_syntax_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_form_syntax_event(
struct accept_form_syntax_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Concatenate == mb ) return(6);
		if (_Context->trigger_Auto2715 == mb ) return(7);
		if (_Context->trigger_Compose == mb ) return(8);
		if (_Context->trigger_Auto2716 == mb ) return(9);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto2712+519) )  
	&&  (my >= (_Context->y_Auto2712+4) )  
	&&  (mx <= (_Context->x_Auto2712+536) )  
	&&  (my <= (_Context->y_Auto2712+20) )) {
		return(1);	/* Auto2712 */

		}
	if ((mx >= (_Context->x_Auto2712+503) )  
	&&  (my >= (_Context->y_Auto2712+4) )  
	&&  (mx <= (_Context->x_Auto2712+520) )  
	&&  (my <= (_Context->y_Auto2712+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcompose.htm");
			};
		return(-1);	/* Auto2712 */

		}
	if ((mx >= (_Context->x_Auto2712+487) )  
	&&  (my >= (_Context->y_Auto2712+4) )  
	&&  (mx <= (_Context->x_Auto2712+504) )  
	&&  (my <= (_Context->y_Auto2712+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_form_syntax_show(_Context);
		return(-1);	/* Auto2712 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto2712+4) )  
		&&  (my >= (_Context->y_Auto2712+4) )  
		&&  (mx <= (_Context->x_Auto2712+472) )  
		&&  (my <= (_Context->y_Auto2712+20) )) {
			return( Auto2712action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto2712+20) ) 
	&&  ( my >= (_Context->y_Auto2712+130) ) 
	&&  ( mx <= (_Context->x_Auto2712+20+496) ) 
	&&  ( my <= (_Context->y_Auto2712+130+240))) {
		return(2); /* Result */
		}
	if (( mx >= (_Context->x_Auto2712+20+0) ) 
	&&  ( my >= (_Context->y_Auto2712+60) ) 
	&&  ( mx <= (_Context->x_Auto2712+20+160) ) 
	&&  ( my <= (_Context->y_Auto2712+60+16))) {
		return(3); /* ClassList */
		}
	if (( mx >= (_Context->x_Auto2712+190+0) ) 
	&&  ( my >= (_Context->y_Auto2712+60) ) 
	&&  ( mx <= (_Context->x_Auto2712+190+160) ) 
	&&  ( my <= (_Context->y_Auto2712+60+16))) {
		return(4); /* WidgetList */
		}
	if (( mx >= (_Context->x_Auto2712+360+0) ) 
	&&  ( my >= (_Context->y_Auto2712+60) ) 
	&&  ( mx <= (_Context->x_Auto2712+360+160) ) 
	&&  ( my <= (_Context->y_Auto2712+60+16))) {
		return(5); /* MethodList */
		}
	if (( mx >= (_Context->x_Auto2712+270) ) 
	&&  ( my >= (_Context->y_Auto2712+400) ) 
	&&  ( mx <= (_Context->x_Auto2712+270+126) ) 
	&&  ( my <= (_Context->y_Auto2712+400+16))) {
		return(6); /* Concatenate */
		}
	if (( mx >= (_Context->x_Auto2712+20) ) 
	&&  ( my >= (_Context->y_Auto2712+380) ) 
	&&  ( mx <= (_Context->x_Auto2712+20+56) ) 
	&&  ( my <= (_Context->y_Auto2712+380+48))) {
		return(7); /* Auto2715 */
		}
	if (( mx >= (_Context->x_Auto2712+160) ) 
	&&  ( my >= (_Context->y_Auto2712+390) ) 
	&&  ( mx <= (_Context->x_Auto2712+160+84) ) 
	&&  ( my <= (_Context->y_Auto2712+390+32))) {
		return(8); /* Compose */
		}
	if (( mx >= (_Context->x_Auto2712+460) ) 
	&&  ( my >= (_Context->y_Auto2712+380) ) 
	&&  ( mx <= (_Context->x_Auto2712+460+56) ) 
	&&  ( my <= (_Context->y_Auto2712+380+48))) {
		return(9); /* Auto2716 */
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
				_Context->keycode = visual_edit(_Context->x_Auto2712+20+1,_Context->y_Auto2712+130+1,496,240,vfh[1],_Context->buffer_Result,930);
			break;
			case	0x3 :
				/* ClassList */
				_Context->keycode = visual_select(_Context->x_Auto2712+20,_Context->y_Auto2712+60,160,304,vfh[1],27,28,parse_selection(WidgetClassList,&_Context->value_ClassList),770);
				break;
			case	0x4 :
				/* WidgetList */
				_Context->keycode = visual_select(_Context->x_Auto2712+190,_Context->y_Auto2712+60,160,304,vfh[1],27,28,parse_selection(FormWidgetList(_Context->value_ClassList),&_Context->value_WidgetList),770);
				break;
			case	0x5 :
				/* MethodList */
				_Context->keycode = visual_select(_Context->x_Auto2712+360,_Context->y_Auto2712+60,160,304,vfh[1],27,28,parse_selection(FormMethodList(_Context->value_WidgetList),&_Context->value_MethodList),770);
				break;
			case	0x6 :
				/* Concatenate */
				visual_check(_Context->x_Auto2712+270,_Context->y_Auto2712+400,126,16,vfh[2],28,28,_Context->msg_Concatenate[_Context->language],strlen(_Context->msg_Concatenate[_Context->language]),(_Context->value_Concatenate |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Concatenate=visual_trigger_code(_Context->msg_Concatenate[_Context->language],strlen(_Context->msg_Concatenate[_Context->language]));
	visual_check(_Context->x_Auto2712+270,_Context->y_Auto2712+400,126,16,vfh[2],28,28,_Context->msg_Concatenate[_Context->language],strlen(_Context->msg_Concatenate[_Context->language]),_Context->value_Concatenate|0);
				break;
			case	0x7 :
				/* Auto2715 */
				_Context->trigger_Auto2715=visual_trigger_code(_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]));
				visual_button(_Context->x_Auto2712+20,_Context->y_Auto2712+380,56,48,vfh[2],34,0,_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2715=visual_trigger_code(_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]));
	visual_button(_Context->x_Auto2712+20,_Context->y_Auto2712+380,56,48,vfh[2],34,0,_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]),1040);
				break;
			case	0x8 :
				/* Compose */
				_Context->trigger_Compose=visual_trigger_code(_Context->msg_Compose[_Context->language],strlen(_Context->msg_Compose[_Context->language]));
				visual_button(_Context->x_Auto2712+160,_Context->y_Auto2712+390,84,32,vfh[2],16,0,_Context->msg_Compose[_Context->language],strlen(_Context->msg_Compose[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Compose=visual_trigger_code(_Context->msg_Compose[_Context->language],strlen(_Context->msg_Compose[_Context->language]));
	visual_button(_Context->x_Auto2712+160,_Context->y_Auto2712+390,84,32,vfh[2],16,0,_Context->msg_Compose[_Context->language],strlen(_Context->msg_Compose[_Context->language]),0);
				break;
			case	0x9 :
				/* Auto2716 */
				_Context->trigger_Auto2716=visual_trigger_code(_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]));
				visual_button(_Context->x_Auto2712+460,_Context->y_Auto2712+380,56,48,vfh[2],34,0,_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2716=visual_trigger_code(_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]));
	visual_button(_Context->x_Auto2712+460,_Context->y_Auto2712+380,56,48,vfh[2],34,0,_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]),1040);
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
					/* Auto2712 */
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
					/* Auto2715 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2715=visual_trigger_code(_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]));
						visual_button(_Context->x_Auto2712+20,_Context->y_Auto2712+380,56,48,vfh[2],34,0,_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2715=visual_trigger_code(_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]));
	visual_button(_Context->x_Auto2712+20,_Context->y_Auto2712+380,56,48,vfh[2],34,0,_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2715_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Compose */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Compose=visual_trigger_code(_Context->msg_Compose[_Context->language],strlen(_Context->msg_Compose[_Context->language]));
						visual_button(_Context->x_Auto2712+160,_Context->y_Auto2712+390,84,32,vfh[2],16,0,_Context->msg_Compose[_Context->language],strlen(_Context->msg_Compose[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Compose=visual_trigger_code(_Context->msg_Compose[_Context->language],strlen(_Context->msg_Compose[_Context->language]));
	visual_button(_Context->x_Auto2712+160,_Context->y_Auto2712+390,84,32,vfh[2],16,0,_Context->msg_Compose[_Context->language],strlen(_Context->msg_Compose[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Compose_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Auto2716 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2716=visual_trigger_code(_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]));
						visual_button(_Context->x_Auto2712+460,_Context->y_Auto2712+380,56,48,vfh[2],34,0,_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2716=visual_trigger_code(_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]));
	visual_button(_Context->x_Auto2712+460,_Context->y_Auto2712+380,56,48,vfh[2],34,0,_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2716_event(_Context)) != -1) break;

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
