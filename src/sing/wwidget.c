
#ifndef _wwidget_c
#define _wwidget_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.03                                                */
/* Production     : C                                                        */
/* Project        : wwidget.xml                                              */
/* Target         : wwidget.c                                                */
/* Identification : 0.0-1159371373-4432.2468                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#include "vframe.h"
#define en_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define fr_WidgetProperties   "Sing : Version 1.0a : Propert‚s des Widgets"
#define it_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define es_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define de_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define nl_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define pt_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define xx_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define en__WidgetProperties   ""
#define en_Auto676   "skin.gif"
#define fr_Auto676   "skin.gif"
#define it_Auto676   "skin.gif"
#define es_Auto676   "skin.gif"
#define de_Auto676   "skin.gif"
#define nl_Auto676   "skin.gif"
#define pt_Auto676   "skin.gif"
#define xx_Auto676   "skin.gif"
#define en_Auto678   ""
#define en__Auto678   ""
#define en_Widget   "&Widget"
#define fr_Widget   "&Widget"
#define it_Widget   "&Widget"
#define es_Widget   "&Widget"
#define de_Widget   "&Widget"
#define nl_Widget   "&Widget"
#define pt_Widget   "&Widget"
#define xx_Widget   "&Widget"
#define en__Widget   ""
#define en_textwidget   "vwtext"
#define en__textwidget   ""
#define en_pushwidget   "vwbutton"
#define en__pushwidget   ""
#define en_Auto679   "ok.gif"
#define fr_Auto679   "ok.gif"
#define it_Auto679   "ok.gif"
#define es_Auto679   "ok.gif"
#define de_Auto679   "ok.gif"
#define nl_Auto679   "ok.gif"
#define pt_Auto679   "ok.gif"
#define xx_Auto679   "ok.gif"
#define en__Auto679   ""
#define en_Auto680   "screen.gif"
#define fr_Auto680   "screen.gif"
#define it_Auto680   "screen.gif"
#define es_Auto680   "screen.gif"
#define de_Auto680   "screen.gif"
#define nl_Auto680   "screen.gif"
#define pt_Auto680   "screen.gif"
#define xx_Auto680   "screen.gif"
#define en__Auto680   ""
#define fr__Auto680   ""
#define it__Auto680   ""
#define es__Auto680   ""
#define de__Auto680   ""
#define nl__Auto680   ""
#define pt__Auto680   ""
#define xx__Auto680   ""
#define en_Auto681   "cancel.gif"
#define fr_Auto681   "cancel.gif"
#define it_Auto681   "cancel.gif"
#define es_Auto681   "cancel.gif"
#define de_Auto681   "cancel.gif"
#define nl_Auto681   "cancel.gif"
#define pt_Auto681   "cancel.gif"
#define xx_Auto681   "cancel.gif"
#define en__Auto681   ""
#define en_Auto682   "image.new"
#define fr_Auto682   "image.new"
#define it_Auto682   "image.new"
#define es_Auto682   "image.new"
#define de_Auto682   "image.new"
#define nl_Auto682   "image.new"
#define pt_Auto682   "image.new"
#define xx_Auto682   "image.new"
#define en_OnCreate   "C&reate"
#define fr_OnCreate   "C&reate"
#define it_OnCreate   "C&reate"
#define es_OnCreate   "C&reate"
#define de_OnCreate   "C&reate"
#define nl_OnCreate   "C&reate"
#define pt_OnCreate   "C&reate"
#define xx_OnCreate   "C&reate"
#define en__CreateOptions   ""
#define en_Create   ""
#define en_OnShowPage   "&Show"
#define fr_OnShowPage   "&Show"
#define it_OnShowPage   "&Show"
#define es_OnShowPage   "&Show"
#define de_OnShowPage   "&Show"
#define nl_OnShowPage   "&Show"
#define pt_OnShowPage   "&Show"
#define xx_OnShowPage   "&Show"
#define en__ShowOptions   ""
#define en_Show   ""
#define en_OnGetFocus   "&GetFocus"
#define fr_OnGetFocus   "&GetFocus"
#define it_OnGetFocus   "&GetFocus"
#define es_OnGetFocus   "&GetFocus"
#define de_OnGetFocus   "&GetFocus"
#define nl_OnGetFocus   "&GetFocus"
#define pt_OnGetFocus   "&GetFocus"
#define xx_OnGetFocus   "&GetFocus"
#define en__FocusOptions   ""
#define en_GetFocus   ""
#define en_OnEvent   "&Event"
#define fr_OnEvent   "&Event"
#define it_OnEvent   "&Event"
#define es_OnEvent   "&Event"
#define de_OnEvent   "&Event"
#define nl_OnEvent   "&Event"
#define pt_OnEvent   "&Event"
#define xx_OnEvent   "&Event"
#define en_Auto683   "Invoke Method On Mouse ..."
#define fr_Auto683   "Activer sur ‚v‚nement .."
#define it_Auto683   "Invoke Method On Mouse ..."
#define es_Auto683   "Invoke Method On Mouse ..."
#define de_Auto683   "Invoke Method On Mouse ..."
#define nl_Auto683   "Invoke Method On Mouse ..."
#define pt_Auto683   "Invoke Method On Mouse ..."
#define xx_Auto683   "D‚anamh nur luchaig"
#define en_MimoMove   "MOVE"
#define fr_MimoMove   "MOVE"
#define it_MimoMove   "MOVE"
#define es_MimoMove   "MOVE"
#define de_MimoMove   "MOVE"
#define nl_MimoMove   "MOVE"
#define pt_MimoMove   "MOVE"
#define xx_MimoMove   "MOVE"
#define en_MimoDown   "DOWN"
#define fr_MimoDown   "DOWN"
#define it_MimoDown   "DOWN"
#define es_MimoDown   "DOWN"
#define de_MimoDown   "DOWN"
#define nl_MimoDown   "DOWN"
#define pt_MimoDown   "DOWN"
#define xx_MimoDown   "DOWN"
#define en_MimoUp   "UP"
#define fr_MimoUp   "UP"
#define it_MimoUp   "UP"
#define es_MimoUp   "UP"
#define de_MimoUp   "UP"
#define nl_MimoUp   "UP"
#define pt_MimoUp   "UP"
#define xx_MimoUp   "UP"
#define en_MimoHold   "HOLD"
#define fr_MimoHold   "HOLD"
#define it_MimoHold   "HOLD"
#define es_MimoHold   "HOLD"
#define de_MimoHold   "HOLD"
#define nl_MimoHold   "HOLD"
#define pt_MimoHold   "HOLD"
#define xx_MimoHold   "HOLD"
#define en__EventOptions   ""
#define en_Event   ""
#define en_OnLoseFocus   "&LoseFocus"
#define fr_OnLoseFocus   "&LoseFocus"
#define it_OnLoseFocus   "&LoseFocus"
#define es_OnLoseFocus   "&LoseFocus"
#define de_OnLoseFocus   "&LoseFocus"
#define nl_OnLoseFocus   "&LoseFocus"
#define pt_OnLoseFocus   "&LoseFocus"
#define xx_OnLoseFocus   "&LoseFocus"
#define en__LoseOptions   ""
#define en_LoseFocus   ""
#define en_OnHidePage   "&Hide"
#define fr_OnHidePage   "&Hide"
#define it_OnHidePage   "&Hide"
#define es_OnHidePage   "&Hide"
#define de_OnHidePage   "&Hide"
#define nl_OnHidePage   "&Hide"
#define pt_OnHidePage   "&Hide"
#define xx_OnHidePage   "&Hide"
#define en__HideOptions   ""
#define en_Hide   ""
#define fr_Hide   ""
#define en_OnRemove   "Re&move"
#define fr_OnRemove   "Re&move"
#define it_OnRemove   "Re&move"
#define es_OnRemove   "Re&move"
#define de_OnRemove   "Re&move"
#define nl_OnRemove   "Re&move"
#define pt_OnRemove   "Re&move"
#define xx_OnRemove   "Re&move"
#define en__RemoveOptions   ""
#define en_Remove   ""
#define fr_Remove   ""
#include "vwtext.h"
#include "vwbutton.h"

private struct accept_widget_properties_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[8+1];
	char * msg_WidgetProperties[8];
	char * hint_WidgetProperties[8];
	int	x_WidgetProperties;
	int	y_WidgetProperties;
	int	w_WidgetProperties;
	int	h_WidgetProperties;
	char * msg_Auto676[8];
	char * hint_Auto676[8];
	char * hint_Auto677[8];
	char * hint_Auto678[8];
	char * msg_Widget[8];
	int	trigger_Widget;
	char * hint_Widget[8];
	int	page_number;
	char * msg_textwidget[8];
	char * hint_textwidget[8];
	struct vwtext_context * textwidget;
	char * msg_pushwidget[8];
	char * hint_pushwidget[8];
	struct vwbutton_context * pushwidget;
	char * msg_Auto679[8];
	int	trigger_Auto679;
	char * hint_Auto679[8];
	char * msg_Auto680[8];
	int	trigger_Auto680;
	char * hint_Auto680[8];
	char * msg_Auto681[8];
	int	trigger_Auto681;
	char * hint_Auto681[8];
	char * msg_OnCreate[8];
	int	trigger_OnCreate;
	char * hint_OnCreate[8];
	char * msg_CreateOptions[8];
	char * hint_CreateOptions[8];
	int	value_CreateOptions;
	char * hint_Create[8];
	char * buffer_Create;
	char * msg_OnShowPage[8];
	int	trigger_OnShowPage;
	char * hint_OnShowPage[8];
	char * msg_ShowOptions[8];
	char * hint_ShowOptions[8];
	int	value_ShowOptions;
	char * hint_Show[8];
	char * buffer_Show;
	char * msg_OnGetFocus[8];
	int	trigger_OnGetFocus;
	char * hint_OnGetFocus[8];
	char * msg_FocusOptions[8];
	char * hint_FocusOptions[8];
	int	value_FocusOptions;
	char * hint_GetFocus[8];
	char * buffer_GetFocus;
	char * msg_OnEvent[8];
	int	trigger_OnEvent;
	char * hint_OnEvent[8];
	char * msg_Auto683[8];
	char * hint_Auto683[8];
	char * msg_MimoMove[8];
	int	trigger_MimoMove;
	char * hint_MimoMove[8];
	int	value_MimoMove;
	char * msg_MimoDown[8];
	int	trigger_MimoDown;
	char * hint_MimoDown[8];
	int	value_MimoDown;
	char * msg_MimoUp[8];
	int	trigger_MimoUp;
	char * hint_MimoUp[8];
	int	value_MimoUp;
	char * msg_MimoHold[8];
	int	trigger_MimoHold;
	char * hint_MimoHold[8];
	int	value_MimoHold;
	char * msg_EventOptions[8];
	char * hint_EventOptions[8];
	int	value_EventOptions;
	char * hint_Event[8];
	char * buffer_Event;
	char * msg_OnLoseFocus[8];
	int	trigger_OnLoseFocus;
	char * hint_OnLoseFocus[8];
	char * msg_LoseOptions[8];
	char * hint_LoseOptions[8];
	int	value_LoseOptions;
	char * hint_LoseFocus[8];
	char * buffer_LoseFocus;
	char * msg_OnHidePage[8];
	int	trigger_OnHidePage;
	char * hint_OnHidePage[8];
	char * msg_HideOptions[8];
	char * hint_HideOptions[8];
	int	value_HideOptions;
	char * hint_Hide[8];
	char * buffer_Hide;
	char * msg_OnRemove[8];
	int	trigger_OnRemove;
	char * hint_OnRemove[8];
	char * msg_RemoveOptions[8];
	char * hint_RemoveOptions[8];
	int	value_RemoveOptions;
	char * hint_Remove[8];
	char * buffer_Remove;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[19];
	};
static int	vfh[10];
static void	aide_en_ligne(struct accept_widget_properties_context * _Context,int x,int y,int h,char *msg_help);

/*	----------------------------	*/
/*	a i d e _ e n _ l i g n e ()	*/
/*	----------------------------	*/
static void	aide_en_ligne(struct accept_widget_properties_context * _Context,int x,int y,int h,char *msg_help){
	int accept_widget_properties_show(struct accept_widget_properties_context*_Context);
	int i,w=0;
	unsigned char*msg=msg_help;
	if(visual_event(2)==_MIMO_RIGHT)
	{
	for(i=0;i<h;i++)
	{
	if(w<(int)strlen(msg))w=(int)strlen(msg);
	msg+=strlen(msg)+1;
	};
	w*=8;
	visual_filzone(x-7,y-5,w+14,h*16+10,3598,0);
	visual_filzone(x-5,y-3,w+10,h*16+6,27,13);
	visual_filzone(x-4,y-2,w+8,h*16+4,27,13);
	for(i=0;i<h;i++)
	{
	visual_text(x,y,w,16,vfh[1],27,14,msg_help,strlen(msg_help),0);
	y+=16;
	msg_help+=strlen(msg_help)+1;
	};
	while((visual_getch()==256)&&((visual_event(1)&_MIMO_UP)!=_MIMO_UP));
		accept_widget_properties_show(_Context);
;
	return;
	};

}

public	int	accept_widget_properties_create(
	struct accept_widget_properties_context ** cptr,
	char * pCreateOptions,
	char * pCreate,
	char * pShowOptions,
	char * pShow,
	char * pFocusOptions,
	char * pGetFocus,
	char * pMimoMove,
	char * pMimoDown,
	char * pMimoUp,
	char * pMimoHold,
	char * pEventOptions,
	char * pEvent,
	char * pLoseOptions,
	char * pLoseFocus,
	char * pHideOptions,
	char * pHide,
	char * pRemoveOptions,
	char * pRemove)
{

	int i;
	struct accept_widget_properties_context * _Context=(struct accept_widget_properties_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	if (!(_Context = allocate( sizeof( struct accept_widget_properties_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=30;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WTWTWTWWWWWTWTWTWT");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pCreateOptions);
		if (!( pCreateOptions )) _Context->value_CreateOptions=0;
		else	_Context->value_CreateOptions = *((int *)pCreateOptions);
				_Context->buffer_Create=(char *) 0;
		visual_transferin(&_Context->buffer_Create, 1782, pCreate);
		visual_transferin((void *) 0, 0, pShowOptions);
		if (!( pShowOptions )) _Context->value_ShowOptions=0;
		else	_Context->value_ShowOptions = *((int *)pShowOptions);
				_Context->buffer_Show=(char *) 0;
		visual_transferin(&_Context->buffer_Show, 1782, pShow);
		visual_transferin((void *) 0, 0, pFocusOptions);
		if (!( pFocusOptions )) _Context->value_FocusOptions=0;
		else	_Context->value_FocusOptions = *((int *)pFocusOptions);
				_Context->buffer_GetFocus=(char *) 0;
		visual_transferin(&_Context->buffer_GetFocus, 1782, pGetFocus);
		visual_transferin((void *) 0, 0, pMimoMove);
		if (!( pMimoMove )) _Context->value_MimoMove=0;
		else	_Context->value_MimoMove = *((int *)pMimoMove);
		visual_transferin((void *) 0, 0, pMimoDown);
		if (!( pMimoDown )) _Context->value_MimoDown=0;
		else	_Context->value_MimoDown = *((int *)pMimoDown);
		visual_transferin((void *) 0, 0, pMimoUp);
		if (!( pMimoUp )) _Context->value_MimoUp=0;
		else	_Context->value_MimoUp = *((int *)pMimoUp);
		visual_transferin((void *) 0, 0, pMimoHold);
		if (!( pMimoHold )) _Context->value_MimoHold=0;
		else	_Context->value_MimoHold = *((int *)pMimoHold);
		visual_transferin((void *) 0, 0, pEventOptions);
		if (!( pEventOptions )) _Context->value_EventOptions=0;
		else	_Context->value_EventOptions = *((int *)pEventOptions);
				_Context->buffer_Event=(char *) 0;
		visual_transferin(&_Context->buffer_Event, 1782, pEvent);
		visual_transferin((void *) 0, 0, pLoseOptions);
		if (!( pLoseOptions )) _Context->value_LoseOptions=0;
		else	_Context->value_LoseOptions = *((int *)pLoseOptions);
				_Context->buffer_LoseFocus=(char *) 0;
		visual_transferin(&_Context->buffer_LoseFocus, 1782, pLoseFocus);
		visual_transferin((void *) 0, 0, pHideOptions);
		if (!( pHideOptions )) _Context->value_HideOptions=0;
		else	_Context->value_HideOptions = *((int *)pHideOptions);
				_Context->buffer_Hide=(char *) 0;
		visual_transferin(&_Context->buffer_Hide, 1782, pHide);
		visual_transferin((void *) 0, 0, pRemoveOptions);
		if (!( pRemoveOptions )) _Context->value_RemoveOptions=0;
		else	_Context->value_RemoveOptions = *((int *)pRemoveOptions);
				_Context->buffer_Remove=(char *) 0;
		visual_transferin(&_Context->buffer_Remove, 1782, pRemove);
		}
	for (i=0; i < 8; i++)_Context->msg_WidgetProperties[i]=" ";
	_Context->msg_WidgetProperties[0]=en_WidgetProperties;
	_Context->msg_WidgetProperties[1]=fr_WidgetProperties;
	_Context->msg_WidgetProperties[2]=it_WidgetProperties;
	_Context->msg_WidgetProperties[3]=es_WidgetProperties;
	_Context->msg_WidgetProperties[4]=de_WidgetProperties;
	_Context->msg_WidgetProperties[5]=nl_WidgetProperties;
	_Context->msg_WidgetProperties[6]=pt_WidgetProperties;
	_Context->msg_WidgetProperties[7]=xx_WidgetProperties;
	_Context->hint_WidgetProperties[0]=en__WidgetProperties;
	_Context->x_WidgetProperties=45;
	_Context->y_WidgetProperties=30;
	_Context->w_WidgetProperties=710;
	_Context->h_WidgetProperties=540;
	_Context->window_col=0;
	_Context->window_row=0;
	wtype=_TEXT_FRAME;
	for (i=0; i < 8; i++)_Context->msg_Auto676[i]=" ";
	_Context->msg_Auto676[0]=en_Auto676;
	_Context->msg_Auto676[1]=fr_Auto676;
	_Context->msg_Auto676[2]=it_Auto676;
	_Context->msg_Auto676[3]=es_Auto676;
	_Context->msg_Auto676[4]=de_Auto676;
	_Context->msg_Auto676[5]=nl_Auto676;
	_Context->msg_Auto676[6]=pt_Auto676;
	_Context->msg_Auto676[7]=xx_Auto676;
	_Context->hint_Auto678[0]=en__Auto678;
	for (i=0; i < 8; i++)_Context->msg_Widget[i]=" ";
	_Context->msg_Widget[0]=en_Widget;
	_Context->msg_Widget[1]=fr_Widget;
	_Context->msg_Widget[2]=it_Widget;
	_Context->msg_Widget[3]=es_Widget;
	_Context->msg_Widget[4]=de_Widget;
	_Context->msg_Widget[5]=nl_Widget;
	_Context->msg_Widget[6]=pt_Widget;
	_Context->msg_Widget[7]=xx_Widget;
	_Context->hint_Widget[0]=en__Widget;
	_Context->focus_pages[1]=2;
	for (i=0; i < 8; i++)_Context->msg_textwidget[i]=" ";
	_Context->msg_textwidget[0]=en_textwidget;
	_Context->hint_textwidget[0]=en__textwidget;
	_Context->textwidget = (struct vwtext_context*) 0;
	_Context->status = vwtext_create(&_Context->textwidget);
	for (i=0; i < 8; i++)_Context->msg_pushwidget[i]=" ";
	_Context->msg_pushwidget[0]=en_pushwidget;
	_Context->hint_pushwidget[0]=en__pushwidget;
	_Context->pushwidget = (struct vwbutton_context*) 0;
	_Context->status = vwbutton_create(&_Context->pushwidget);
	for (i=0; i < 8; i++)_Context->msg_Auto679[i]=" ";
	_Context->msg_Auto679[0]=en_Auto679;
	_Context->msg_Auto679[1]=fr_Auto679;
	_Context->msg_Auto679[2]=it_Auto679;
	_Context->msg_Auto679[3]=es_Auto679;
	_Context->msg_Auto679[4]=de_Auto679;
	_Context->msg_Auto679[5]=nl_Auto679;
	_Context->msg_Auto679[6]=pt_Auto679;
	_Context->msg_Auto679[7]=xx_Auto679;
	_Context->hint_Auto679[0]=en__Auto679;
	for (i=0; i < 8; i++)_Context->msg_Auto680[i]=" ";
	_Context->msg_Auto680[0]=en_Auto680;
	_Context->msg_Auto680[1]=fr_Auto680;
	_Context->msg_Auto680[2]=it_Auto680;
	_Context->msg_Auto680[3]=es_Auto680;
	_Context->msg_Auto680[4]=de_Auto680;
	_Context->msg_Auto680[5]=nl_Auto680;
	_Context->msg_Auto680[6]=pt_Auto680;
	_Context->msg_Auto680[7]=xx_Auto680;
	_Context->hint_Auto680[0]=en__Auto680;
	_Context->hint_Auto680[1]=fr__Auto680;
	_Context->hint_Auto680[2]=it__Auto680;
	_Context->hint_Auto680[3]=es__Auto680;
	_Context->hint_Auto680[4]=de__Auto680;
	_Context->hint_Auto680[5]=nl__Auto680;
	_Context->hint_Auto680[6]=pt__Auto680;
	_Context->hint_Auto680[7]=xx__Auto680;
	for (i=0; i < 8; i++)_Context->msg_Auto681[i]=" ";
	_Context->msg_Auto681[0]=en_Auto681;
	_Context->msg_Auto681[1]=fr_Auto681;
	_Context->msg_Auto681[2]=it_Auto681;
	_Context->msg_Auto681[3]=es_Auto681;
	_Context->msg_Auto681[4]=de_Auto681;
	_Context->msg_Auto681[5]=nl_Auto681;
	_Context->msg_Auto681[6]=pt_Auto681;
	_Context->msg_Auto681[7]=xx_Auto681;
	_Context->hint_Auto681[0]=en__Auto681;
	for (i=0; i < 8; i++)_Context->msg_OnCreate[i]=" ";
	_Context->msg_OnCreate[0]=en_OnCreate;
	_Context->msg_OnCreate[1]=fr_OnCreate;
	_Context->msg_OnCreate[2]=it_OnCreate;
	_Context->msg_OnCreate[3]=es_OnCreate;
	_Context->msg_OnCreate[4]=de_OnCreate;
	_Context->msg_OnCreate[5]=nl_OnCreate;
	_Context->msg_OnCreate[6]=pt_OnCreate;
	_Context->msg_OnCreate[7]=xx_OnCreate;
	_Context->focus_pages[2]=6;
	for (i=0; i < 8; i++)_Context->msg_CreateOptions[i]=" ";
	_Context->hint_CreateOptions[0]=en__CreateOptions;
	for (i=0; i < 8; i++)_Context->msg_OnShowPage[i]=" ";
	_Context->msg_OnShowPage[0]=en_OnShowPage;
	_Context->msg_OnShowPage[1]=fr_OnShowPage;
	_Context->msg_OnShowPage[2]=it_OnShowPage;
	_Context->msg_OnShowPage[3]=es_OnShowPage;
	_Context->msg_OnShowPage[4]=de_OnShowPage;
	_Context->msg_OnShowPage[5]=nl_OnShowPage;
	_Context->msg_OnShowPage[6]=pt_OnShowPage;
	_Context->msg_OnShowPage[7]=xx_OnShowPage;
	_Context->focus_pages[3]=9;
	for (i=0; i < 8; i++)_Context->msg_ShowOptions[i]=" ";
	_Context->hint_ShowOptions[0]=en__ShowOptions;
	for (i=0; i < 8; i++)_Context->msg_OnGetFocus[i]=" ";
	_Context->msg_OnGetFocus[0]=en_OnGetFocus;
	_Context->msg_OnGetFocus[1]=fr_OnGetFocus;
	_Context->msg_OnGetFocus[2]=it_OnGetFocus;
	_Context->msg_OnGetFocus[3]=es_OnGetFocus;
	_Context->msg_OnGetFocus[4]=de_OnGetFocus;
	_Context->msg_OnGetFocus[5]=nl_OnGetFocus;
	_Context->msg_OnGetFocus[6]=pt_OnGetFocus;
	_Context->msg_OnGetFocus[7]=xx_OnGetFocus;
	_Context->focus_pages[4]=12;
	for (i=0; i < 8; i++)_Context->msg_FocusOptions[i]=" ";
	_Context->hint_FocusOptions[0]=en__FocusOptions;
	for (i=0; i < 8; i++)_Context->msg_OnEvent[i]=" ";
	_Context->msg_OnEvent[0]=en_OnEvent;
	_Context->msg_OnEvent[1]=fr_OnEvent;
	_Context->msg_OnEvent[2]=it_OnEvent;
	_Context->msg_OnEvent[3]=es_OnEvent;
	_Context->msg_OnEvent[4]=de_OnEvent;
	_Context->msg_OnEvent[5]=nl_OnEvent;
	_Context->msg_OnEvent[6]=pt_OnEvent;
	_Context->msg_OnEvent[7]=xx_OnEvent;
	_Context->focus_pages[5]=15;
	for (i=0; i < 8; i++)_Context->msg_Auto683[i]=" ";
	_Context->msg_Auto683[0]=en_Auto683;
	_Context->msg_Auto683[1]=fr_Auto683;
	_Context->msg_Auto683[2]=it_Auto683;
	_Context->msg_Auto683[3]=es_Auto683;
	_Context->msg_Auto683[4]=de_Auto683;
	_Context->msg_Auto683[5]=nl_Auto683;
	_Context->msg_Auto683[6]=pt_Auto683;
	_Context->msg_Auto683[7]=xx_Auto683;
	for (i=0; i < 8; i++)_Context->msg_MimoMove[i]=" ";
	_Context->msg_MimoMove[0]=en_MimoMove;
	_Context->msg_MimoMove[1]=fr_MimoMove;
	_Context->msg_MimoMove[2]=it_MimoMove;
	_Context->msg_MimoMove[3]=es_MimoMove;
	_Context->msg_MimoMove[4]=de_MimoMove;
	_Context->msg_MimoMove[5]=nl_MimoMove;
	_Context->msg_MimoMove[6]=pt_MimoMove;
	_Context->msg_MimoMove[7]=xx_MimoMove;
	for (i=0; i < 8; i++)_Context->msg_MimoDown[i]=" ";
	_Context->msg_MimoDown[0]=en_MimoDown;
	_Context->msg_MimoDown[1]=fr_MimoDown;
	_Context->msg_MimoDown[2]=it_MimoDown;
	_Context->msg_MimoDown[3]=es_MimoDown;
	_Context->msg_MimoDown[4]=de_MimoDown;
	_Context->msg_MimoDown[5]=nl_MimoDown;
	_Context->msg_MimoDown[6]=pt_MimoDown;
	_Context->msg_MimoDown[7]=xx_MimoDown;
	for (i=0; i < 8; i++)_Context->msg_MimoUp[i]=" ";
	_Context->msg_MimoUp[0]=en_MimoUp;
	_Context->msg_MimoUp[1]=fr_MimoUp;
	_Context->msg_MimoUp[2]=it_MimoUp;
	_Context->msg_MimoUp[3]=es_MimoUp;
	_Context->msg_MimoUp[4]=de_MimoUp;
	_Context->msg_MimoUp[5]=nl_MimoUp;
	_Context->msg_MimoUp[6]=pt_MimoUp;
	_Context->msg_MimoUp[7]=xx_MimoUp;
	for (i=0; i < 8; i++)_Context->msg_MimoHold[i]=" ";
	_Context->msg_MimoHold[0]=en_MimoHold;
	_Context->msg_MimoHold[1]=fr_MimoHold;
	_Context->msg_MimoHold[2]=it_MimoHold;
	_Context->msg_MimoHold[3]=es_MimoHold;
	_Context->msg_MimoHold[4]=de_MimoHold;
	_Context->msg_MimoHold[5]=nl_MimoHold;
	_Context->msg_MimoHold[6]=pt_MimoHold;
	_Context->msg_MimoHold[7]=xx_MimoHold;
	for (i=0; i < 8; i++)_Context->msg_EventOptions[i]=" ";
	_Context->hint_EventOptions[0]=en__EventOptions;
	for (i=0; i < 8; i++)_Context->msg_OnLoseFocus[i]=" ";
	_Context->msg_OnLoseFocus[0]=en_OnLoseFocus;
	_Context->msg_OnLoseFocus[1]=fr_OnLoseFocus;
	_Context->msg_OnLoseFocus[2]=it_OnLoseFocus;
	_Context->msg_OnLoseFocus[3]=es_OnLoseFocus;
	_Context->msg_OnLoseFocus[4]=de_OnLoseFocus;
	_Context->msg_OnLoseFocus[5]=nl_OnLoseFocus;
	_Context->msg_OnLoseFocus[6]=pt_OnLoseFocus;
	_Context->msg_OnLoseFocus[7]=xx_OnLoseFocus;
	_Context->focus_pages[6]=22;
	for (i=0; i < 8; i++)_Context->msg_LoseOptions[i]=" ";
	_Context->hint_LoseOptions[0]=en__LoseOptions;
	for (i=0; i < 8; i++)_Context->msg_OnHidePage[i]=" ";
	_Context->msg_OnHidePage[0]=en_OnHidePage;
	_Context->msg_OnHidePage[1]=fr_OnHidePage;
	_Context->msg_OnHidePage[2]=it_OnHidePage;
	_Context->msg_OnHidePage[3]=es_OnHidePage;
	_Context->msg_OnHidePage[4]=de_OnHidePage;
	_Context->msg_OnHidePage[5]=nl_OnHidePage;
	_Context->msg_OnHidePage[6]=pt_OnHidePage;
	_Context->msg_OnHidePage[7]=xx_OnHidePage;
	_Context->focus_pages[7]=25;
	for (i=0; i < 8; i++)_Context->msg_HideOptions[i]=" ";
	_Context->hint_HideOptions[0]=en__HideOptions;
	for (i=0; i < 8; i++)_Context->msg_OnRemove[i]=" ";
	_Context->msg_OnRemove[0]=en_OnRemove;
	_Context->msg_OnRemove[1]=fr_OnRemove;
	_Context->msg_OnRemove[2]=it_OnRemove;
	_Context->msg_OnRemove[3]=es_OnRemove;
	_Context->msg_OnRemove[4]=de_OnRemove;
	_Context->msg_OnRemove[5]=nl_OnRemove;
	_Context->msg_OnRemove[6]=pt_OnRemove;
	_Context->msg_OnRemove[7]=xx_OnRemove;
	_Context->focus_pages[8]=28;
	for (i=0; i < 8; i++)_Context->msg_RemoveOptions[i]=" ";
	_Context->hint_RemoveOptions[0]=en__RemoveOptions;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_WidgetProperties,_Context->y_WidgetProperties,710+10,540+10);
	return(0);
}
private int on_WidgetProperties_hide(struct accept_widget_properties_context * _Context) {
	close_window_editor();
	return(-1);
}

public 	int	accept_widget_properties_hide(struct accept_widget_properties_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	vwbutton_hide(_Context->pushwidget);
	vwtext_hide(_Context->textwidget);
	(void) on_WidgetProperties_hide(_Context);
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_WidgetProperties,_Context->y_WidgetProperties);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_widget_properties_remove(
	struct accept_widget_properties_context * _Context,
	char * pCreateOptions,
	char * pCreate,
	char * pShowOptions,
	char * pShow,
	char * pFocusOptions,
	char * pGetFocus,
	char * pMimoMove,
	char * pMimoDown,
	char * pMimoUp,
	char * pMimoHold,
	char * pEventOptions,
	char * pEvent,
	char * pLoseOptions,
	char * pLoseFocus,
	char * pHideOptions,
	char * pHide,
	char * pRemoveOptions,
	char * pRemove)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	_Context->status = vwbutton_remove(_Context->pushwidget);
	_Context->pushwidget = (struct vwbutton_context*) 0;
	_Context->status = vwtext_remove(_Context->textwidget);
	_Context->textwidget = (struct vwtext_context*) 0;
	if (_Context->keycode == 27 ) {
		filetransferdrop(_Context->buffer_Create);
		filetransferdrop(_Context->buffer_Show);
		filetransferdrop(_Context->buffer_GetFocus);
		filetransferdrop(_Context->buffer_Event);
		filetransferdrop(_Context->buffer_LoseFocus);
		filetransferdrop(_Context->buffer_Hide);
		filetransferdrop(_Context->buffer_Remove);
		
	} else {
		strcpy(_Context->signature,"WTWTWTWWWWWTWTWTWT");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pCreateOptions);
		if ( pCreateOptions != (char *) 0)
			*((int*)pCreateOptions) = _Context->value_CreateOptions;
		visual_transferout(&_Context->buffer_Create, 1782, pCreate);
		visual_transferout((void *) 0, 0, pShowOptions);
		if ( pShowOptions != (char *) 0)
			*((int*)pShowOptions) = _Context->value_ShowOptions;
		visual_transferout(&_Context->buffer_Show, 1782, pShow);
		visual_transferout((void *) 0, 0, pFocusOptions);
		if ( pFocusOptions != (char *) 0)
			*((int*)pFocusOptions) = _Context->value_FocusOptions;
		visual_transferout(&_Context->buffer_GetFocus, 1782, pGetFocus);
		visual_transferout((void *) 0, 0, pMimoMove);
		if ( pMimoMove != (char *) 0)
			*((int*)pMimoMove) = _Context->value_MimoMove;
		visual_transferout((void *) 0, 0, pMimoDown);
		if ( pMimoDown != (char *) 0)
			*((int*)pMimoDown) = _Context->value_MimoDown;
		visual_transferout((void *) 0, 0, pMimoUp);
		if ( pMimoUp != (char *) 0)
			*((int*)pMimoUp) = _Context->value_MimoUp;
		visual_transferout((void *) 0, 0, pMimoHold);
		if ( pMimoHold != (char *) 0)
			*((int*)pMimoHold) = _Context->value_MimoHold;
		visual_transferout((void *) 0, 0, pEventOptions);
		if ( pEventOptions != (char *) 0)
			*((int*)pEventOptions) = _Context->value_EventOptions;
		visual_transferout(&_Context->buffer_Event, 1782, pEvent);
		visual_transferout((void *) 0, 0, pLoseOptions);
		if ( pLoseOptions != (char *) 0)
			*((int*)pLoseOptions) = _Context->value_LoseOptions;
		visual_transferout(&_Context->buffer_LoseFocus, 1782, pLoseFocus);
		visual_transferout((void *) 0, 0, pHideOptions);
		if ( pHideOptions != (char *) 0)
			*((int*)pHideOptions) = _Context->value_HideOptions;
		visual_transferout(&_Context->buffer_Hide, 1782, pHide);
		visual_transferout((void *) 0, 0, pRemoveOptions);
		if ( pRemoveOptions != (char *) 0)
			*((int*)pRemoveOptions) = _Context->value_RemoveOptions;
		visual_transferout(&_Context->buffer_Remove, 1782, pRemove);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Widget_show(struct accept_widget_properties_context * _Context) {
		if (_Context->page_number == 1 ) {
	_Context->trigger_Widget=visual_trigger_code(_Context->msg_Widget[_Context->language],strlen(_Context->msg_Widget[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_Widget[_Context->language],strlen(_Context->msg_Widget[_Context->language]),0,1026);
		(void) on_Widget_show(_Context);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_Widget[_Context->language],strlen(_Context->msg_Widget[_Context->language]),0,1024);
		}
;
	switch wclass{
	case _TEXT_FRAME
		vwtext_show(_Context->textwidget);
;
	break;
	case _BUTTON_FRAME
		vwbutton_show(_Context->pushwidget);
;
	break;
	}
	return(-1);
}
private int on_OnCreate_show(struct accept_widget_properties_context * _Context) {
	open_window_editor(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,
	648,352,_Context->buffer_Create);
	return(-1);
}
private int on_Create_show(struct accept_widget_properties_context * _Context) {
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
	show_window_editor();
	return(-1);
}
private int on_OnShowPage_show(struct accept_widget_properties_context * _Context) {
	open_window_editor(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,
	648,352,_Context->buffer_Show);
	return(-1);
}
private int on_Show_show(struct accept_widget_properties_context * _Context) {
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
	show_window_editor();
	return(-1);
}
private int on_OnGetFocus_show(struct accept_widget_properties_context * _Context) {
	open_window_editor(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,
	648,352,_Context->buffer_GetFocus);
	return(-1);
}
private int on_GetFocus_show(struct accept_widget_properties_context * _Context) {
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
	show_window_editor();
	return(-1);
}
private int on_OnEvent_show(struct accept_widget_properties_context * _Context) {
	open_window_editor(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,
	648,352,_Context->buffer_Event);
	return(-1);
}
private int on_Event_show(struct accept_widget_properties_context * _Context) {
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
	show_window_editor();
	return(-1);
}
private int on_OnLoseFocus_show(struct accept_widget_properties_context * _Context) {
	open_window_editor(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,
	648,352,_Context->buffer_LoseFocus);
	return(-1);
}
private int on_LoseFocus_show(struct accept_widget_properties_context * _Context) {
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
	show_window_editor();
	return(-1);
}
private int on_OnHidePage_show(struct accept_widget_properties_context * _Context) {
	open_window_editor(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,
	648,352,_Context->buffer_Hide);
	return(-1);
}
private int on_Hide_show(struct accept_widget_properties_context * _Context) {
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
	show_window_editor();
	return(-1);
}
private int on_OnRemove_show(struct accept_widget_properties_context * _Context) {
	open_window_editor(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,
	648,352,_Context->buffer_Remove);
	return(-1);
}
private int on_Remove_show(struct accept_widget_properties_context * _Context) {
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
	show_window_editor();
	return(-1);
}

public	int	accept_widget_properties_show(struct accept_widget_properties_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_WidgetProperties,_Context->y_WidgetProperties);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_WidgetProperties,_Context->y_WidgetProperties,710,540,vfh[2],_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]),0x407);
	visual_image(_Context->x_WidgetProperties+3,_Context->y_WidgetProperties+22,703,515,_Context->msg_Auto676[_Context->language],4);
	visual_filzone(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+50,650,30,18,12);
	visual_filzone(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+70,670,410,18,12);
	if (_Context->page_number == 1 ) {
	_Context->trigger_Widget=visual_trigger_code(_Context->msg_Widget[_Context->language],strlen(_Context->msg_Widget[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_Widget[_Context->language],strlen(_Context->msg_Widget[_Context->language]),0,1026);
		(void) on_Widget_show(_Context);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_Widget[_Context->language],strlen(_Context->msg_Widget[_Context->language]),0,1024);
		}
	if (_Context->page_number == 1 ) {
	vwbutton_show(_Context->pushwidget);
	_Context->trigger_Auto679=visual_trigger_code(_Context->msg_Auto679[_Context->language],strlen(_Context->msg_Auto679[_Context->language]));
	visual_button(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto679[_Context->language],strlen(_Context->msg_Auto679[_Context->language]),1040);
	_Context->trigger_Auto680=visual_trigger_code(_Context->msg_Auto680[_Context->language],strlen(_Context->msg_Auto680[_Context->language]));
	visual_button(_Context->x_WidgetProperties+340,_Context->y_WidgetProperties+480,56,48,vfh[2],28,28,_Context->msg_Auto680[_Context->language],strlen(_Context->msg_Auto680[_Context->language]),1040);
	_Context->trigger_Auto681=visual_trigger_code(_Context->msg_Auto681[_Context->language],strlen(_Context->msg_Auto681[_Context->language]));
	visual_button(_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto681[_Context->language],strlen(_Context->msg_Auto681[_Context->language]),1040);
	if (_Context->page_number == 2 ) {
	_Context->trigger_OnCreate=visual_trigger_code(_Context->msg_OnCreate[_Context->language],strlen(_Context->msg_OnCreate[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnCreate[_Context->language],strlen(_Context->msg_OnCreate[_Context->language]),81,2);
		(void) on_OnCreate_show(_Context);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnCreate[_Context->language],strlen(_Context->msg_OnCreate[_Context->language]),81,0);
		}
	if (_Context->page_number == 2 ) {
	visual_select(_Context->x_WidgetProperties+390,_Context->y_WidgetProperties+80,288,90,vfh[1],27,0,parse_selection(WidgetSizesOptions,&_Context->value_CreateOptions),0);
		}
	if (_Context->page_number == 2 ) {
	(void) on_Create_show(_Context);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_OnShowPage=visual_trigger_code(_Context->msg_OnShowPage[_Context->language],strlen(_Context->msg_OnShowPage[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnShowPage[_Context->language],strlen(_Context->msg_OnShowPage[_Context->language]),159,2);
		(void) on_OnShowPage_show(_Context);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnShowPage[_Context->language],strlen(_Context->msg_OnShowPage[_Context->language]),159,0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetShowOptions,&_Context->value_ShowOptions),0);
		}
	if (_Context->page_number == 3 ) {
	(void) on_Show_show(_Context);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_OnGetFocus=visual_trigger_code(_Context->msg_OnGetFocus[_Context->language],strlen(_Context->msg_OnGetFocus[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnGetFocus[_Context->language],strlen(_Context->msg_OnGetFocus[_Context->language]),231,2);
		(void) on_OnGetFocus_show(_Context);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnGetFocus[_Context->language],strlen(_Context->msg_OnGetFocus[_Context->language]),231,0);
		}
	if (_Context->page_number == 4 ) {
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetFocusOptions,&_Context->value_FocusOptions),0);
		}
	if (_Context->page_number == 4 ) {
	(void) on_GetFocus_show(_Context);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_OnEvent=visual_trigger_code(_Context->msg_OnEvent[_Context->language],strlen(_Context->msg_OnEvent[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnEvent[_Context->language],strlen(_Context->msg_OnEvent[_Context->language]),327,2);
		(void) on_OnEvent_show(_Context);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnEvent[_Context->language],strlen(_Context->msg_OnEvent[_Context->language]),327,0);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_WidgetProperties+40,_Context->y_WidgetProperties+80,168,16,vfh[2],27,0,_Context->msg_Auto683[_Context->language],strlen(_Context->msg_Auto683[_Context->language]),1025);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_MimoMove=visual_trigger_code(_Context->msg_MimoMove[_Context->language],strlen(_Context->msg_MimoMove[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+230,_Context->y_WidgetProperties+80,40,16,vfh[1],25,26,_Context->msg_MimoMove[_Context->language],strlen(_Context->msg_MimoMove[_Context->language]),_Context->value_MimoMove| 0x0030);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_MimoDown=visual_trigger_code(_Context->msg_MimoDown[_Context->language],strlen(_Context->msg_MimoDown[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+280,_Context->y_WidgetProperties+80,42,16,vfh[1],25,26,_Context->msg_MimoDown[_Context->language],strlen(_Context->msg_MimoDown[_Context->language]),_Context->value_MimoDown| 0x0030);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_MimoUp=visual_trigger_code(_Context->msg_MimoUp[_Context->language],strlen(_Context->msg_MimoUp[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+330,_Context->y_WidgetProperties+80,24,16,vfh[1],25,26,_Context->msg_MimoUp[_Context->language],strlen(_Context->msg_MimoUp[_Context->language]),_Context->value_MimoUp| 0x0030);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_MimoHold=visual_trigger_code(_Context->msg_MimoHold[_Context->language],strlen(_Context->msg_MimoHold[_Context->language]));
	visual_switch(_Context->x_WidgetProperties+360,_Context->y_WidgetProperties+80,40,16,vfh[1],25,26,_Context->msg_MimoHold[_Context->language],strlen(_Context->msg_MimoHold[_Context->language]),_Context->value_MimoHold| 0x0030);
		}
	if (_Context->page_number == 5 ) {
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetEventOptions,&_Context->value_EventOptions),0);
		}
	if (_Context->page_number == 5 ) {
	(void) on_Event_show(_Context);
		}
	if (_Context->page_number == 6 ) {
	_Context->trigger_OnLoseFocus=visual_trigger_code(_Context->msg_OnLoseFocus[_Context->language],strlen(_Context->msg_OnLoseFocus[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnLoseFocus[_Context->language],strlen(_Context->msg_OnLoseFocus[_Context->language]),400,2);
		(void) on_OnLoseFocus_show(_Context);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnLoseFocus[_Context->language],strlen(_Context->msg_OnLoseFocus[_Context->language]),400,0);
		}
	if (_Context->page_number == 6 ) {
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetEventOptions,&_Context->value_LoseOptions),0);
		}
	if (_Context->page_number == 6 ) {
	(void) on_LoseFocus_show(_Context);
		}
	if (_Context->page_number == 7 ) {
	_Context->trigger_OnHidePage=visual_trigger_code(_Context->msg_OnHidePage[_Context->language],strlen(_Context->msg_OnHidePage[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnHidePage[_Context->language],strlen(_Context->msg_OnHidePage[_Context->language]),503,2);
		(void) on_OnHidePage_show(_Context);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnHidePage[_Context->language],strlen(_Context->msg_OnHidePage[_Context->language]),503,0);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetHideOptions,&_Context->value_HideOptions),0);
		}
	if (_Context->page_number == 7 ) {
	(void) on_Hide_show(_Context);
		}
	if (_Context->page_number == 8 ) {
	_Context->trigger_OnRemove=visual_trigger_code(_Context->msg_OnRemove[_Context->language],strlen(_Context->msg_OnRemove[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnRemove[_Context->language],strlen(_Context->msg_OnRemove[_Context->language]),567,2);
		(void) on_OnRemove_show(_Context);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnRemove[_Context->language],strlen(_Context->msg_OnRemove[_Context->language]),567,0);
		}
	if (_Context->page_number == 8 ) {
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetEventOptions,&_Context->value_RemoveOptions),0);
		}
	if (_Context->page_number == 8 ) {
	(void) on_Remove_show(_Context);
		}
	visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,710,540);

	return(0);
}

private int WidgetPropertiesaction(struct accept_widget_properties_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_widget_properties_hide(_Context);

		_Context->x_WidgetProperties += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_WidgetProperties < 0) { _Context->x_WidgetProperties=0; }
		_Context->y_WidgetProperties += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_WidgetProperties < 0) { _Context->y_WidgetProperties=0; }
			accept_widget_properties_show(_Context);

		visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,710,540);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto679_event(struct accept_widget_properties_context * _Context) {
	unsigned char*msg_help[8];
	int nblig=1;
	if((visual_event(1)==_MIMO_UP)&&(visual_event(2)!=_MIMO_RIGHT))
	return(13);
	if(visual_event(1)==_MIMO_DOWN)
	{
	msg_help[0]="By pressing this button any changes made to the various\0" \
	"parameters will take effect.";
	msg_help[1]="Presser ce bouton pour valider toutes les modifications\0" \
	"faites sur cet objet.";
	nblig=2;
	/*anglais pour les autres langues*/
	msg_help[2]=msg_help[0];
	msg_help[3]=msg_help[0];
	msg_help[4]=msg_help[0];
	msg_help[5]=msg_help[0];
	msg_help[6]=msg_help[0];
	msg_help[7]=msg_help[0];
	aide_en_ligne(_Context, _Context->x_WidgetProperties+20,_Context->y_WidgetProperties+480-15-nblig*16,nblig,msg_help[visual_national_language(-1)]);
	};
	return(-1);
}
private int on_Auto680_event(struct accept_widget_properties_context * _Context) {
	unsigned char*msg_help[8];
	int nblig=1;
	if((visual_event(1)==_MIMO_UP)&&(visual_event(2)!=_MIMO_RIGHT)){
		accept_widget_properties_hide(_Context);
;
	switch(_Context->page_number){
	case 2:
	use_editor(_Context->buffer_Create,-1);
	visual_freeze();
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* Create */
	/* OnCreate */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 2;
	accept_widget_properties_show(_Context);
	_Context->focus_item=6;
	accept_widget_properties_show(_Context);
	_Context->focus_item=8;
;
	break;
	case 3:
	use_editor(_Context->buffer_Show,-1);
	visual_freeze();
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* Show */
	/* OnShowPage */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 3;
	accept_widget_properties_show(_Context);
	_Context->focus_item=9;
	accept_widget_properties_show(_Context);
	_Context->focus_item=11;
;
	break;
	case 4:
	use_editor(_Context->buffer_GetFocus,-1);
	visual_freeze();
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* GetFocus */
	/* OnGetFocus */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 4;
	accept_widget_properties_show(_Context);
	_Context->focus_item=12;
	accept_widget_properties_show(_Context);
	_Context->focus_item=14;
;
	break;
	case 5:
	use_editor(_Context->buffer_Event,-1);
	visual_freeze();
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* Event */
	/* OnEvent */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 5;
	accept_widget_properties_show(_Context);
	_Context->focus_item=15;
	accept_widget_properties_show(_Context);
	_Context->focus_item=21;
;
	break;
	case 6:
	use_editor(_Context->buffer_LoseFocus,-1);
	visual_freeze();
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* LoseFocus */
	/* OnLoseFocus */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 6;
	accept_widget_properties_show(_Context);
	_Context->focus_item=22;
	accept_widget_properties_show(_Context);
	_Context->focus_item=24;
;
	break;
	case 7:
	use_editor(_Context->buffer_Hide,-1);
	visual_freeze();
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* Hide */
	/* OnHidePage */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 7;
	accept_widget_properties_show(_Context);
	_Context->focus_item=25;
	accept_widget_properties_show(_Context);
	_Context->focus_item=27;
;
	break;
	case 8:
	use_editor(_Context->buffer_Remove,-1);
	visual_freeze();
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* Remove */
	/* OnRemove */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 8;
	accept_widget_properties_show(_Context);
	_Context->focus_item=28;
	accept_widget_properties_show(_Context);
	_Context->focus_item=30;
;
	break;
	default:
	visual_freeze();
		accept_widget_properties_show(_Context);
;
		/* Widget */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 1;
	accept_widget_properties_show(_Context);
	_Context->focus_item=2;
;
	}
	visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,710+10,540+10);
	if(FormZoomCheck()){return(27);}
	}
	else if(visual_event(1)==_MIMO_DOWN){
	msg_help[0]="By pressing on this button the full screen source editor\0" \
	"will be actived for edition of the forms method screen\0" \
	"if you are on a form method tab. If you are on the first\0" \
	"tab, this window will be refresh.";
	msg_help[1]="Presser ce bouton pour activer l'‚diteur plein ‚cran afin\0" \
	"de modifier le code de la m‚thode correspondante a l'onglet\0" \
	"actif si vous ˆtes sur un onglet de m‚thode. Si vous ˆtes\0" \
	"sur le premier onglet, cette fenˆtre sera rafraichie";
	nblig=4;
	/*anglais pour les autres langues*/
	msg_help[2]=msg_help[0];
	msg_help[3]=msg_help[0];
	msg_help[4]=msg_help[0];
	msg_help[5]=msg_help[0];
	msg_help[6]=msg_help[0];
	msg_help[7]=msg_help[0];
	aide_en_ligne(_Context, _Context->x_WidgetProperties+340-strlen(msg_help[visual_national_language(-1)])*4,_Context->y_WidgetProperties+480-15-nblig*16,nblig,msg_help[visual_national_language(-1)]);
	};
	return(-1);
}
private int on_Auto681_event(struct accept_widget_properties_context * _Context) {
	unsigned char*msg_help[8];
	int nblig=1;
	if((visual_event(1)==_MIMO_UP)&&(visual_event(2)!=_MIMO_RIGHT))
	return(27);
	if(visual_event(1)==_MIMO_DOWN)
	{
	msg_help[0]="By pressing this button any changes modifications will\0" \
	"be discarded.";
	msg_help[1]="Presser ce bouton pour annuler toutes les modifications\0" \
	"faites sur cet objet.";
	nblig=2;
	/*anglais pour les autres langues*/
	msg_help[2]=msg_help[0];
	msg_help[3]=msg_help[0];
	msg_help[4]=msg_help[0];
	msg_help[5]=msg_help[0];
	msg_help[6]=msg_help[0];
	msg_help[7]=msg_help[0];
	aide_en_ligne(_Context, _Context->x_WidgetProperties+630-(strlen(msg_help[visual_national_language(-1)])-8)*8,_Context->y_WidgetProperties+480-15-nblig*16,nblig,msg_help[visual_national_language(-1)]);
	};
	return(-1);
}


public	int	accept_widget_properties_event(
struct accept_widget_properties_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Widget == mb ) return(2);
		if (_Context->trigger_Auto679 == mb ) return(3);
		if (_Context->trigger_Auto680 == mb ) return(4);
		if (_Context->trigger_Auto681 == mb ) return(5);
		if (_Context->trigger_OnCreate == mb ) return(6);
		if (_Context->trigger_OnShowPage == mb ) return(9);
		if (_Context->trigger_OnGetFocus == mb ) return(12);
		if (_Context->trigger_OnEvent == mb ) return(15);
		if (_Context->trigger_MimoMove == mb ) return(16);
		if (_Context->trigger_MimoDown == mb ) return(17);
		if (_Context->trigger_MimoUp == mb ) return(18);
		if (_Context->trigger_MimoHold == mb ) return(19);
		if (_Context->trigger_OnLoseFocus == mb ) return(22);
		if (_Context->trigger_OnHidePage == mb ) return(25);
		if (_Context->trigger_OnRemove == mb ) return(28);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x1031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_WidgetProperties+689) )  
	&&  (my >= (_Context->y_WidgetProperties+4) )  
	&&  (mx <= (_Context->x_WidgetProperties+706) )  
	&&  (my <= (_Context->y_WidgetProperties+20) )) {
		return(1);	/* WidgetProperties */

		}
	if ((mx >= (_Context->x_WidgetProperties+673) )  
	&&  (my >= (_Context->y_WidgetProperties+4) )  
	&&  (mx <= (_Context->x_WidgetProperties+690) )  
	&&  (my <= (_Context->y_WidgetProperties+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("wwidget.htm");
			};
		return(-1);	/* WidgetProperties */

		}
	if ((mx >= (_Context->x_WidgetProperties+657) )  
	&&  (my >= (_Context->y_WidgetProperties+4) )  
	&&  (mx <= (_Context->x_WidgetProperties+674) )  
	&&  (my <= (_Context->y_WidgetProperties+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_widget_properties_show(_Context);
		return(-1);	/* WidgetProperties */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_WidgetProperties+4) )  
		&&  (my >= (_Context->y_WidgetProperties+4) )  
		&&  (mx <= (_Context->x_WidgetProperties+642) )  
		&&  (my <= (_Context->y_WidgetProperties+20) )) {
			return( WidgetPropertiesaction(_Context) );
			}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+80) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(2); /* Widget */
			}
		}
	if (( mx >= (_Context->x_WidgetProperties+20) ) 
	&&  ( my >= (_Context->y_WidgetProperties+480) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+20+56) ) 
	&&  ( my <= (_Context->y_WidgetProperties+480+48))) {
		return(3); /* Auto679 */
		}
	if (( mx >= (_Context->x_WidgetProperties+340) ) 
	&&  ( my >= (_Context->y_WidgetProperties+480) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+340+56) ) 
	&&  ( my <= (_Context->y_WidgetProperties+480+48))) {
		return(4); /* Auto680 */
		}
	if (( mx >= (_Context->x_WidgetProperties+630) ) 
	&&  ( my >= (_Context->y_WidgetProperties+480) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+630+56) ) 
	&&  ( my <= (_Context->y_WidgetProperties+480+48))) {
		return(5); /* Auto681 */
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+81) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+158) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(6); /* OnCreate */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_WidgetProperties+390+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+390+288) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(7); /* CreateOptions */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(8); /* Create */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+159) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+230) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(9); /* OnShowPage */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(10); /* ShowOptions */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(11); /* Show */
			}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+231) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+326) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(12); /* OnGetFocus */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(13); /* FocusOptions */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(14); /* GetFocus */
			}
		}
	if (_Context->page_number == 5 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+327) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+399) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(15); /* OnEvent */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+230) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+230+40) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(16); /* MimoMove */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+280) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+280+42) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(17); /* MimoDown */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+330) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+330+24) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(18); /* MimoUp */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+360) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+360+40) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(19); /* MimoHold */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(20); /* EventOptions */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(21); /* Event */
			}
		}
	if (_Context->page_number == 6 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+400) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+502) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(22); /* OnLoseFocus */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(23); /* LoseOptions */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(24); /* LoseFocus */
			}
		}
	if (_Context->page_number == 7 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+503) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+566) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(25); /* OnHidePage */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(26); /* HideOptions */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(27); /* Hide */
			}
		}
	if (_Context->page_number == 8 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+567) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+652) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(28); /* OnRemove */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(29); /* RemoveOptions */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(30); /* Remove */
			}
		}

	return(-1);
}


public	int	accept_widget_properties_losefocus(struct accept_widget_properties_context * _Context)
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;
		case 3 : 
			break;
		case 4 : 
			break;
		case 5 : 
			break;
		case 6 : 
			break;
		case 7 : 
			break;
		case 8 : 
			break;

		}
	return(0);

}
private int on_Create_getfocus(struct accept_widget_properties_context * _Context) {
	return(focus_window_editor());
	return(-1);
}
private int on_Show_getfocus(struct accept_widget_properties_context * _Context) {
	return(focus_window_editor());
	return(-1);
}
private int on_GetFocus_getfocus(struct accept_widget_properties_context * _Context) {
	return(focus_window_editor());
	return(-1);
}
private int on_Event_getfocus(struct accept_widget_properties_context * _Context) {
	return(focus_window_editor());
	return(-1);
}
private int on_LoseFocus_getfocus(struct accept_widget_properties_context * _Context) {
	return(focus_window_editor());
	return(-1);
}
private int on_Hide_getfocus(struct accept_widget_properties_context * _Context) {
	return(focus_window_editor());
	return(-1);
}
private int on_Remove_getfocus(struct accept_widget_properties_context * _Context) {
	return(focus_window_editor());
	return(-1);
}


public	int	accept_widget_properties_focus(struct accept_widget_properties_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Widget */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x3 :
				/* Auto679 */
				visual_button(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto679[_Context->language],strlen(_Context->msg_Auto679[_Context->language]),1042);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto679[_Context->language],strlen(_Context->msg_Auto679[_Context->language]),1040);
				break;
			case	0x5 :
				/* Auto681 */
				visual_button(_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto681[_Context->language],strlen(_Context->msg_Auto681[_Context->language]),1042);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto681[_Context->language],strlen(_Context->msg_Auto681[_Context->language]),1040);
				break;
			case	0x6 :
				/* OnCreate */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x7 :
				/* CreateOptions */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+390,_Context->y_WidgetProperties+80,288,90,vfh[1],27,0,parse_selection(WidgetSizesOptions,&_Context->value_CreateOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* Create */
				if (_Context->page_number == 2 ) {
					if ((_Context->keycode = on_Create_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* OnShowPage */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xa :
				/* ShowOptions */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetShowOptions,&_Context->value_ShowOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* Show */
				if (_Context->page_number == 3 ) {
					if ((_Context->keycode = on_Show_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* OnGetFocus */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xd :
				/* FocusOptions */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetFocusOptions,&_Context->value_FocusOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* GetFocus */
				if (_Context->page_number == 4 ) {
					if ((_Context->keycode = on_GetFocus_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* OnEvent */
				if (_Context->page_number == 5 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x10 :
				/* MimoMove */
				if (_Context->page_number == 5 ) {
				visual_switch(_Context->x_WidgetProperties+230,_Context->y_WidgetProperties+80,40,16,vfh[1],25,26,_Context->msg_MimoMove[_Context->language],strlen(_Context->msg_MimoMove[_Context->language]),(_Context->value_MimoMove | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
				visual_switch(_Context->x_WidgetProperties+230,_Context->y_WidgetProperties+80,40,16,vfh[1],25,26,_Context->msg_MimoMove[_Context->language],strlen(_Context->msg_MimoMove[_Context->language]),(_Context->value_MimoMove | 0 | 0x0030 ));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* MimoDown */
				if (_Context->page_number == 5 ) {
				visual_switch(_Context->x_WidgetProperties+280,_Context->y_WidgetProperties+80,42,16,vfh[1],25,26,_Context->msg_MimoDown[_Context->language],strlen(_Context->msg_MimoDown[_Context->language]),(_Context->value_MimoDown | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
				visual_switch(_Context->x_WidgetProperties+280,_Context->y_WidgetProperties+80,42,16,vfh[1],25,26,_Context->msg_MimoDown[_Context->language],strlen(_Context->msg_MimoDown[_Context->language]),(_Context->value_MimoDown | 0 | 0x0030 ));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* MimoUp */
				if (_Context->page_number == 5 ) {
				visual_switch(_Context->x_WidgetProperties+330,_Context->y_WidgetProperties+80,24,16,vfh[1],25,26,_Context->msg_MimoUp[_Context->language],strlen(_Context->msg_MimoUp[_Context->language]),(_Context->value_MimoUp | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
				visual_switch(_Context->x_WidgetProperties+330,_Context->y_WidgetProperties+80,24,16,vfh[1],25,26,_Context->msg_MimoUp[_Context->language],strlen(_Context->msg_MimoUp[_Context->language]),(_Context->value_MimoUp | 0 | 0x0030 ));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* MimoHold */
				if (_Context->page_number == 5 ) {
				visual_switch(_Context->x_WidgetProperties+360,_Context->y_WidgetProperties+80,40,16,vfh[1],25,26,_Context->msg_MimoHold[_Context->language],strlen(_Context->msg_MimoHold[_Context->language]),(_Context->value_MimoHold | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
				visual_switch(_Context->x_WidgetProperties+360,_Context->y_WidgetProperties+80,40,16,vfh[1],25,26,_Context->msg_MimoHold[_Context->language],strlen(_Context->msg_MimoHold[_Context->language]),(_Context->value_MimoHold | 0 | 0x0030 ));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* EventOptions */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetEventOptions,&_Context->value_EventOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x15 :
				/* Event */
				if (_Context->page_number == 5 ) {
					if ((_Context->keycode = on_Event_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* OnLoseFocus */
				if (_Context->page_number == 6 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x17 :
				/* LoseOptions */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetEventOptions,&_Context->value_LoseOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x18 :
				/* LoseFocus */
				if (_Context->page_number == 6 ) {
					if ((_Context->keycode = on_LoseFocus_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* OnHidePage */
				if (_Context->page_number == 7 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x1a :
				/* HideOptions */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetHideOptions,&_Context->value_HideOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* Hide */
				if (_Context->page_number == 7 ) {
					if ((_Context->keycode = on_Hide_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1c :
				/* OnRemove */
				if (_Context->page_number == 8 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x1d :
				/* RemoveOptions */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,90,vfh[1],27,0,parse_selection(WidgetEventOptions,&_Context->value_RemoveOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* Remove */
				if (_Context->page_number == 8 ) {
					if ((_Context->keycode = on_Remove_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			accept_widget_properties_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_widget_properties_show(_Context);
			continue;
		case	0x2 :
			accept_widget_properties_losefocus(_Context);
			_Context->page_number=8;
			_Context->focus_item=30;
			accept_widget_properties_show(_Context);
			continue;
		case	0x3 :
			accept_widget_properties_losefocus(_Context);
			if ( _Context->page_number < 8 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_widget_properties_show(_Context);
			continue;
		case	0x12 :
			accept_widget_properties_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_widget_properties_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_widget_properties_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* WidgetProperties */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Widget */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus(_Context);
							_Context->page_number = 1;
							accept_widget_properties_show(_Context);
							}
						continue;
					case	0x3 :
						/* Auto679 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto679[_Context->language],strlen(_Context->msg_Auto679[_Context->language]),1042);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto679[_Context->language],strlen(_Context->msg_Auto679[_Context->language]),1040);
							}
						if ( visual_event(1) &  0x30 ) {
						if ((_Context->keycode = on_Auto679_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* Auto680 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_WidgetProperties+340,_Context->y_WidgetProperties+480,56,48,vfh[2],28,28,_Context->msg_Auto680[_Context->language],strlen(_Context->msg_Auto680[_Context->language]),1042);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_WidgetProperties+340,_Context->y_WidgetProperties+480,56,48,vfh[2],28,28,_Context->msg_Auto680[_Context->language],strlen(_Context->msg_Auto680[_Context->language]),1040);
							}
						if ( visual_event(1) &  0x30 ) {
						if ((_Context->keycode = on_Auto680_event(_Context)) != -1) break;

							}
						continue;
					case	0x5 :
						/* Auto681 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto681[_Context->language],strlen(_Context->msg_Auto681[_Context->language]),1042);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+480,56,48,vfh[2],34,0,_Context->msg_Auto681[_Context->language],strlen(_Context->msg_Auto681[_Context->language]),1040);
							}
						if ( visual_event(1) &  0x30 ) {
						if ((_Context->keycode = on_Auto681_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* OnCreate */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus(_Context);
							_Context->page_number = 2;
							accept_widget_properties_show(_Context);
							}
						continue;
					case	0x7 :
						/* CreateOptions */
						continue;
					case	0x8 :
						/* Create */
						continue;
					case	0x9 :
						/* OnShowPage */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus(_Context);
							_Context->page_number = 3;
							accept_widget_properties_show(_Context);
							}
						continue;
					case	0xa :
						/* ShowOptions */
						continue;
					case	0xb :
						/* Show */
						continue;
					case	0xc :
						/* OnGetFocus */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus(_Context);
							_Context->page_number = 4;
							accept_widget_properties_show(_Context);
							}
						continue;
					case	0xd :
						/* FocusOptions */
						continue;
					case	0xe :
						/* GetFocus */
						continue;
					case	0xf :
						/* OnEvent */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus(_Context);
							_Context->page_number = 5;
							accept_widget_properties_show(_Context);
							}
						continue;
					case	0x10 :
						/* MimoMove */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MimoMove += 1;
							_Context->value_MimoMove &= 1;
							}
						continue;
					case	0x11 :
						/* MimoDown */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MimoDown += 1;
							_Context->value_MimoDown &= 1;
							}
						continue;
					case	0x12 :
						/* MimoUp */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MimoUp += 1;
							_Context->value_MimoUp &= 1;
							}
						continue;
					case	0x13 :
						/* MimoHold */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MimoHold += 1;
							_Context->value_MimoHold &= 1;
							}
						continue;
					case	0x14 :
						/* EventOptions */
						continue;
					case	0x15 :
						/* Event */
						continue;
					case	0x16 :
						/* OnLoseFocus */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus(_Context);
							_Context->page_number = 6;
							accept_widget_properties_show(_Context);
							}
						continue;
					case	0x17 :
						/* LoseOptions */
						continue;
					case	0x18 :
						/* LoseFocus */
						continue;
					case	0x19 :
						/* OnHidePage */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus(_Context);
							_Context->page_number = 7;
							accept_widget_properties_show(_Context);
							}
						continue;
					case	0x1a :
						/* HideOptions */
						continue;
					case	0x1b :
						/* Hide */
						continue;
					case	0x1c :
						/* OnRemove */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus(_Context);
							_Context->page_number = 8;
							accept_widget_properties_show(_Context);
							}
						continue;
					case	0x1d :
						/* RemoveOptions */
						continue;
					case	0x1e :
						/* Remove */
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
				_Context->focus_item=30;
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

public	int	accept_widget_properties(
	char * pCreateOptions,
	char * pCreate,
	char * pShowOptions,
	char * pShow,
	char * pFocusOptions,
	char * pGetFocus,
	char * pMimoMove,
	char * pMimoDown,
	char * pMimoUp,
	char * pMimoHold,
	char * pEventOptions,
	char * pEvent,
	char * pLoseOptions,
	char * pLoseFocus,
	char * pHideOptions,
	char * pHide,
	char * pRemoveOptions,
	char * pRemove)
{
	int	status=0;
	struct accept_widget_properties_context * _Context=(struct accept_widget_properties_context*) 0;
	status = accept_widget_properties_create(
	&_Context,
	 pCreateOptions,
	 pCreate,
	 pShowOptions,
	 pShow,
	 pFocusOptions,
	 pGetFocus,
	 pMimoMove,
	 pMimoDown,
	 pMimoUp,
	 pMimoHold,
	 pEventOptions,
	 pEvent,
	 pLoseOptions,
	 pLoseFocus,
	 pHideOptions,
	 pHide,
	 pRemoveOptions,
	 pRemove);
	if ( status != 0) return(status);
	status = accept_widget_properties_show(_Context);
		enter_modal();
	status = accept_widget_properties_focus(_Context);
		leave_modal();
	status = accept_widget_properties_hide(_Context);
	status = accept_widget_properties_remove(
	_Context,
	 pCreateOptions,
	 pCreate,
	 pShowOptions,
	 pShow,
	 pFocusOptions,
	 pGetFocus,
	 pMimoMove,
	 pMimoDown,
	 pMimoUp,
	 pMimoHold,
	 pEventOptions,
	 pEvent,
	 pLoseOptions,
	 pLoseFocus,
	 pHideOptions,
	 pHide,
	 pRemoveOptions,
	 pRemove);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _wwidget_c */
