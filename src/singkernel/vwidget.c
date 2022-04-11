
#ifndef _vwidget_c
#define _vwidget_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vwidget.xml  */
/* Target         : vwidget.c  */
/* Identification : 0.0-1100167577-2310.2309 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define fr_WidgetProperties   "Sing : Version 1.0a : Propert‚s des Widgets"
#define it_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define es_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define de_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define nl_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define pt_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define xx_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define en_Auto1369   "skin.gif"
#define fr_Auto1369   "skin.gif"
#define en_Widget   "&Widget"
#define fr_Widget   "&Widget"
#define xx_Widget   "&Widget"
#define en_auto50093   "Position"
#define fr_auto50093   "Position"
#define xx_auto50093   "Aite"
#define en_auto49   "Dimensions"
#define fr_auto49   "Dimensions"
#define xx_auto49   "Meud"
#define en_auto53   ","
#define en_auto55   ","
#define en_auto64   "Text Font"
#define fr_auto64   "Fonte Texte"
#define xx_auto64   "Teacs"
#define en_auto67   "Colour"
#define fr_auto67   "Caract‚res"
#define xx_auto67   "Dath Teacs"
#define en_fgSelect   "fg"
#define en_auto70   "Background"
#define fr_auto70   "Fond"
#define xx_auto70   "Dath culaidh"
#define en_bgSelect   "bg"
#define en_PayLoadSelect   "*"
#define fr_auto73   "Charge Utile"
#define xx_auto73   "Griomh"
#define en_Auto13691   "Style"
#define fr_Auto13691   "Charge Utile"
#define xx_Auto13691   "Griomh"
#define en_Identity   ""
#define en_Format   ""
#define en_StyleSheet   ""
#define en_auto77   "Identity"
#define fr_auto77   "Identit‚"
#define xx_auto77   "Ainm"
#define en_Auto1375   "Hotkey"
#define fr_Auto1375   "Hotkey"
#define xx_Auto1375   "Teas"
#define en_auto80   "Class"
#define fr_auto80   "Class"
#define xx_auto80   "Clais"
#define fr_Auto1377   "Format"
#define xx_Auto1377   "Doigh"
#define en_auto269   "Storage/Action Type"
#define fr_auto269   "Action/Stockage"
#define it_auto269   "Storage/Action Type"
#define es_auto269   "Storage/Action Type"
#define de_auto269   "Storage/Action Type"
#define nl_auto269   "Storage/Action Type"
#define pt_auto269   "Storage/Action Type"
#define xx_auto269   "Storage/Action Type"
#define en_Ok   "&Accept"
#define fr_Ok   "&Valider"
#define it_Ok   "&Accept"
#define es_Ok   "&Accept"
#define de_Ok   "&Accept"
#define nl_Ok   "&Accept"
#define pt_Ok   "&Accept"
#define xx_Ok   "&Tha gu math"
#define en_FullScreen   "&Full Screen"
#define fr_FullScreen   "&Plein Ecran"
#define it_FullScreen   "&Full Screen"
#define es_FullScreen   "&Full Screen"
#define de_FullScreen   "&Full Screen"
#define nl_FullScreen   "&Full Screen"
#define pt_FullScreen   "&Full Screen"
#define xx_FullScreen   "&Sg…il mor"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
#define it_Cancel   "&Cancel"
#define es_Cancel   "&Cancel"
#define de_Cancel   "&Cancel"
#define nl_Cancel   "&Cancel"
#define pt_Cancel   "&Cancel"
#define xx_Cancel   "&Chan Eil"
#define en_auto138   "Options"
#define fr_auto138   "Options"
#define xx_auto138   "Eile"
#define en_IsLock   "L&ocked"
#define fr_IsLock   "Verr&ouill‚"
#define xx_IsLock   "Sabhaladh"
#define en_IsInterface   "Interface Item"
#define fr_IsInterface   "Item d'Interface"
#define xx_IsInterface   "A'faicinn"
#define fr_IsSpecial   "Item d'Interface"
#define xx_IsSpecial   "A'faicinn"
#define en_OnCreate   "C&reate"
#define fr_OnCreate   "C&reate"
#define xx_OnCreate   "C&reate"
#define en_Create   ""
#define en_OnShowPage   "&Show"
#define fr_OnShowPage   "&Show"
#define it_OnShowPage   "&Show"
#define es_OnShowPage   "&Show"
#define de_OnShowPage   "&Show"
#define nl_OnShowPage   "&Show"
#define pt_OnShowPage   "&Show"
#define xx_OnShowPage   "&Show"
#define en_Show   ""
#define en_OnGetFocus   "&GetFocus"
#define fr_OnGetFocus   "&GetFocus"
#define it_OnGetFocus   "&GetFocus"
#define es_OnGetFocus   "&GetFocus"
#define de_OnGetFocus   "&GetFocus"
#define nl_OnGetFocus   "&GetFocus"
#define pt_OnGetFocus   "&GetFocus"
#define xx_OnGetFocus   "&GetFocus"
#define en_GetFocus   ""
#define en_OnEvent   "&Event"
#define fr_OnEvent   "&Event"
#define it_OnEvent   "&Event"
#define es_OnEvent   "&Event"
#define de_OnEvent   "&Event"
#define nl_OnEvent   "&Event"
#define pt_OnEvent   "&Event"
#define xx_OnEvent   "&Event"
#define en_Auto1378   "Invoke Method On Mouse ..."
#define fr_Auto1378   "Activer sur ‚v‚nement .."
#define xx_Auto1378   "D‚anamh nur luchaig"
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
#define en_Event   ""
#define en_OnLoseFocus   "&LoseFocus"
#define fr_OnLoseFocus   "&LoseFocus"
#define it_OnLoseFocus   "&LoseFocus"
#define es_OnLoseFocus   "&LoseFocus"
#define de_OnLoseFocus   "&LoseFocus"
#define nl_OnLoseFocus   "&LoseFocus"
#define pt_OnLoseFocus   "&LoseFocus"
#define xx_OnLoseFocus   "&LoseFocus"
#define en_LoseFocus   ""
#define en_OnHidePage   "&Hide"
#define fr_OnHidePage   "&Hide"
#define it_OnHidePage   "&Hide"
#define es_OnHidePage   "&Hide"
#define de_OnHidePage   "&Hide"
#define nl_OnHidePage   "&Hide"
#define pt_OnHidePage   "&Hide"
#define xx_OnHidePage   "&Hide"
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
#define en_Remove   ""
#define fr_Remove   ""
static int	vfh[10];

private struct accept_widget_properties_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[8+1];
	char * msg_WidgetProperties[8];
	int	x_WidgetProperties;
	int	y_WidgetProperties;
	int	w_WidgetProperties;
	int	h_WidgetProperties;
	char * msg_Auto1369[8];
	char * msg_Widget[8];
	int	trigger_Widget;
	int	page_number;
	char * msg_auto50093[8];
	char * msg_auto49[8];
	char	buffer_AtX[8];
	char * msg_auto53[8];
	char	buffer_AtY[8];
	char * msg_auto55[8];
	char	buffer_Width[8];
	char	buffer_Height[8];
	char * msg_auto64[8];
	char * msg_auto67[8];
	char * msg_TextFont[8];
	int	value_TextFont;
	char	buffer_TextColour[13];
	char * msg_fgSelect[8];
	int	trigger_fgSelect;
	char * msg_auto70[8];
	char	buffer_Background[13];
	char * msg_bgSelect[8];
	int	trigger_bgSelect;
	char * msg_PayLoadSelect[8];
	int	trigger_PayLoadSelect;
	int	s_PayLoadSelect;
	void *	p_PayLoadSelect;
	char * msg_auto73[8];
	char * msg_Auto13691[8];
	char	buffer_PayLoad[326];
	char	buffer_Identity[63];
	char	buffer_Format[326];
	char	buffer_StyleSheet[66];
	char * msg_auto77[8];
	char * msg_Auto1375[8];
	char	buffer_Auto1376[7];
	char * msg_auto80[8];
	char * msg_Auto1377[8];
	char * msg_auto269[8];
	char * msg_WidgetClass[8];
	int	value_WidgetClass;
	char * msg_Ok[8];
	int	trigger_Ok;
	char * msg_FullScreen[8];
	int	trigger_FullScreen;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * msg_auto138[8];
	char * msg_Align[8];
	int	value_Align;
	char * msg_Type[8];
	int	value_Type;
	char * msg_IsBold[8];
	int	trigger_IsBold;
	int	value_IsBold;
	char * msg_IsUnderline[8];
	int	trigger_IsUnderline;
	int	value_IsUnderline;
	char * msg_IsShadow[8];
	int	trigger_IsShadow;
	int	value_IsShadow;
	char * msg_IsLock[8];
	int	trigger_IsLock;
	int	value_IsLock;
	char * msg_IsInterface[8];
	int	trigger_IsInterface;
	int	value_IsInterface;
	char * msg_IsSpecial[8];
	int	trigger_IsSpecial;
	int	value_IsSpecial;
	char * msg_OnCreate[8];
	int	trigger_OnCreate;
	char * msg_CreateOptions[8];
	int	value_CreateOptions;
	char * buffer_Create;
	char * msg_OnShowPage[8];
	int	trigger_OnShowPage;
	char * msg_ShowOptions[8];
	int	value_ShowOptions;
	char * buffer_Show;
	char * msg_OnGetFocus[8];
	int	trigger_OnGetFocus;
	char * msg_FocusOptions[8];
	int	value_FocusOptions;
	char * buffer_GetFocus;
	char * msg_OnEvent[8];
	int	trigger_OnEvent;
	char * msg_Auto1378[8];
	char * msg_MimoMove[8];
	int	trigger_MimoMove;
	int	value_MimoMove;
	char * msg_MimoDown[8];
	int	trigger_MimoDown;
	int	value_MimoDown;
	char * msg_MimoUp[8];
	int	trigger_MimoUp;
	int	value_MimoUp;
	char * msg_MimoHold[8];
	int	trigger_MimoHold;
	int	value_MimoHold;
	char * msg_EventOptions[8];
	int	value_EventOptions;
	char * buffer_Event;
	char * msg_OnLoseFocus[8];
	int	trigger_OnLoseFocus;
	char * msg_LoseOptions[8];
	int	value_LoseOptions;
	char * buffer_LoseFocus;
	char * msg_OnHidePage[8];
	int	trigger_OnHidePage;
	char * msg_HideOptions[8];
	int	value_HideOptions;
	char * buffer_Hide;
	char * msg_OnRemove[8];
	int	trigger_OnRemove;
	char * msg_RemoveOptions[8];
	int	value_RemoveOptions;
	char * buffer_Remove;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[40];
	};

public	int	accept_widget_properties_create(
	struct accept_widget_properties_context ** cptr,
	char * pAtX,
	char * pAtY,
	char * pWidth,
	char * pHeight,
	char * pTextFont,
	char * pTextColour,
	char * pBackground,
	char * pPayLoad,
	char * pIdentity,
	char * pFormat,
	char * pStyleSheet,
	char * pAuto1376,
	char * pWidgetClass,
	char * pAlign,
	char * pType,
	char * pIsBold,
	char * pIsUnderline,
	char * pIsShadow,
	char * pIsLock,
	char * pIsInterface,
	char * pIsSpecial,
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
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_widget_properties_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=54;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWSSSSWWWWWWWWWWWTWTWTWWWWWTWTWTWT");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_AtX, 7, pAtX);
		visual_transferin(_Context->buffer_AtY, 7, pAtY);
		visual_transferin(_Context->buffer_Width, 7, pWidth);
		visual_transferin(_Context->buffer_Height, 7, pHeight);
		visual_transferin((void *) 0, 0, pTextFont);
		if (!( pTextFont )) _Context->value_TextFont=0;
		else	_Context->value_TextFont = *((int *)pTextFont);
		visual_transferin(_Context->buffer_TextColour, 12, pTextColour);
		visual_transferin(_Context->buffer_Background, 12, pBackground);
		visual_transferin(_Context->buffer_PayLoad, 325, pPayLoad);
		visual_transferin(_Context->buffer_Identity, 62, pIdentity);
		visual_transferin(_Context->buffer_Format, 325, pFormat);
		visual_transferin(_Context->buffer_StyleSheet, 65, pStyleSheet);
		visual_transferin(_Context->buffer_Auto1376, 6, pAuto1376);
		visual_transferin((void *) 0, 0, pWidgetClass);
		if (!( pWidgetClass )) _Context->value_WidgetClass=0;
		else	_Context->value_WidgetClass = *((int *)pWidgetClass);
		visual_transferin((void *) 0, 0, pAlign);
		if (!( pAlign )) _Context->value_Align=0;
		else	_Context->value_Align = *((int *)pAlign);
		visual_transferin((void *) 0, 0, pType);
		if (!( pType )) _Context->value_Type=0;
		else	_Context->value_Type = *((int *)pType);
		visual_transferin((void *) 0, 0, pIsBold);
		if (!( pIsBold )) _Context->value_IsBold=0;
		else	_Context->value_IsBold = *((int *)pIsBold);
		visual_transferin((void *) 0, 0, pIsUnderline);
		if (!( pIsUnderline )) _Context->value_IsUnderline=0;
		else	_Context->value_IsUnderline = *((int *)pIsUnderline);
		visual_transferin((void *) 0, 0, pIsShadow);
		if (!( pIsShadow )) _Context->value_IsShadow=0;
		else	_Context->value_IsShadow = *((int *)pIsShadow);
		visual_transferin((void *) 0, 0, pIsLock);
		if (!( pIsLock )) _Context->value_IsLock=0;
		else	_Context->value_IsLock = *((int *)pIsLock);
		visual_transferin((void *) 0, 0, pIsInterface);
		if (!( pIsInterface )) _Context->value_IsInterface=0;
		else	_Context->value_IsInterface = *((int *)pIsInterface);
		visual_transferin((void *) 0, 0, pIsSpecial);
		if (!( pIsSpecial )) _Context->value_IsSpecial=0;
		else	_Context->value_IsSpecial = *((int *)pIsSpecial);
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
	_Context->x_WidgetProperties=45;
	_Context->y_WidgetProperties=35;
	_Context->w_WidgetProperties=710;
	_Context->h_WidgetProperties=530;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto1369[i]=" ";
	_Context->msg_Auto1369[0]=en_Auto1369;
	_Context->msg_Auto1369[1]=fr_Auto1369;
	for (i=0; i < 8; i++)_Context->msg_Widget[i]=" ";
	_Context->msg_Widget[0]=en_Widget;
	_Context->msg_Widget[1]=fr_Widget;
	_Context->msg_Widget[7]=xx_Widget;
	_Context->focus_pages[1]=2;
	for (i=0; i < 8; i++)_Context->msg_auto50093[i]=" ";
	_Context->msg_auto50093[0]=en_auto50093;
	_Context->msg_auto50093[1]=fr_auto50093;
	_Context->msg_auto50093[7]=xx_auto50093;
	for (i=0; i < 8; i++)_Context->msg_auto49[i]=" ";
	_Context->msg_auto49[0]=en_auto49;
	_Context->msg_auto49[1]=fr_auto49;
	_Context->msg_auto49[7]=xx_auto49;
	for (i=0; i < 8; i++)_Context->msg_auto53[i]=" ";
	_Context->msg_auto53[0]=en_auto53;
	for (i=0; i < 8; i++)_Context->msg_auto55[i]=" ";
	_Context->msg_auto55[0]=en_auto55;
	for (i=0; i < 8; i++)_Context->msg_auto64[i]=" ";
	_Context->msg_auto64[0]=en_auto64;
	_Context->msg_auto64[1]=fr_auto64;
	_Context->msg_auto64[7]=xx_auto64;
	for (i=0; i < 8; i++)_Context->msg_auto67[i]=" ";
	_Context->msg_auto67[0]=en_auto67;
	_Context->msg_auto67[1]=fr_auto67;
	_Context->msg_auto67[7]=xx_auto67;
	for (i=0; i < 8; i++)_Context->msg_TextFont[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_fgSelect[i]=" ";
	_Context->msg_fgSelect[0]=en_fgSelect;
	for (i=0; i < 8; i++)_Context->msg_auto70[i]=" ";
	_Context->msg_auto70[0]=en_auto70;
	_Context->msg_auto70[1]=fr_auto70;
	_Context->msg_auto70[7]=xx_auto70;
	for (i=0; i < 8; i++)_Context->msg_bgSelect[i]=" ";
	_Context->msg_bgSelect[0]=en_bgSelect;
	for (i=0; i < 8; i++)_Context->msg_PayLoadSelect[i]=" ";
	_Context->msg_PayLoadSelect[0]=en_PayLoadSelect;
	_Context->s_PayLoadSelect=0;
	_Context->p_PayLoadSelect=visual_buffer(_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+260,20,18);
	for (i=0; i < 8; i++)_Context->msg_auto73[i]=" ";
	_Context->msg_auto73[1]=fr_auto73;
	_Context->msg_auto73[7]=xx_auto73;
	for (i=0; i < 8; i++)_Context->msg_Auto13691[i]=" ";
	_Context->msg_Auto13691[0]=en_Auto13691;
	_Context->msg_Auto13691[1]=fr_Auto13691;
	_Context->msg_Auto13691[7]=xx_Auto13691;
	for (i=0; i < 8; i++)_Context->msg_auto77[i]=" ";
	_Context->msg_auto77[0]=en_auto77;
	_Context->msg_auto77[1]=fr_auto77;
	_Context->msg_auto77[7]=xx_auto77;
	for (i=0; i < 8; i++)_Context->msg_Auto1375[i]=" ";
	_Context->msg_Auto1375[0]=en_Auto1375;
	_Context->msg_Auto1375[1]=fr_Auto1375;
	_Context->msg_Auto1375[7]=xx_Auto1375;
	for (i=0; i < 8; i++)_Context->msg_auto80[i]=" ";
	_Context->msg_auto80[0]=en_auto80;
	_Context->msg_auto80[1]=fr_auto80;
	_Context->msg_auto80[7]=xx_auto80;
	for (i=0; i < 8; i++)_Context->msg_Auto1377[i]=" ";
	_Context->msg_Auto1377[1]=fr_Auto1377;
	_Context->msg_Auto1377[7]=xx_Auto1377;
	for (i=0; i < 8; i++)_Context->msg_auto269[i]=" ";
	_Context->msg_auto269[0]=en_auto269;
	_Context->msg_auto269[1]=fr_auto269;
	_Context->msg_auto269[2]=it_auto269;
	_Context->msg_auto269[3]=es_auto269;
	_Context->msg_auto269[4]=de_auto269;
	_Context->msg_auto269[5]=nl_auto269;
	_Context->msg_auto269[6]=pt_auto269;
	_Context->msg_auto269[7]=xx_auto269;
	for (i=0; i < 8; i++)_Context->msg_WidgetClass[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_Ok[i]=" ";
	_Context->msg_Ok[0]=en_Ok;
	_Context->msg_Ok[1]=fr_Ok;
	_Context->msg_Ok[2]=it_Ok;
	_Context->msg_Ok[3]=es_Ok;
	_Context->msg_Ok[4]=de_Ok;
	_Context->msg_Ok[5]=nl_Ok;
	_Context->msg_Ok[6]=pt_Ok;
	_Context->msg_Ok[7]=xx_Ok;
	for (i=0; i < 8; i++)_Context->msg_FullScreen[i]=" ";
	_Context->msg_FullScreen[0]=en_FullScreen;
	_Context->msg_FullScreen[1]=fr_FullScreen;
	_Context->msg_FullScreen[2]=it_FullScreen;
	_Context->msg_FullScreen[3]=es_FullScreen;
	_Context->msg_FullScreen[4]=de_FullScreen;
	_Context->msg_FullScreen[5]=nl_FullScreen;
	_Context->msg_FullScreen[6]=pt_FullScreen;
	_Context->msg_FullScreen[7]=xx_FullScreen;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->msg_Cancel[2]=it_Cancel;
	_Context->msg_Cancel[3]=es_Cancel;
	_Context->msg_Cancel[4]=de_Cancel;
	_Context->msg_Cancel[5]=nl_Cancel;
	_Context->msg_Cancel[6]=pt_Cancel;
	_Context->msg_Cancel[7]=xx_Cancel;
	for (i=0; i < 8; i++)_Context->msg_auto138[i]=" ";
	_Context->msg_auto138[0]=en_auto138;
	_Context->msg_auto138[1]=fr_auto138;
	_Context->msg_auto138[7]=xx_auto138;
	for (i=0; i < 8; i++)_Context->msg_Align[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_Type[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_IsBold[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_IsUnderline[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_IsShadow[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_IsLock[i]=" ";
	_Context->msg_IsLock[0]=en_IsLock;
	_Context->msg_IsLock[1]=fr_IsLock;
	_Context->msg_IsLock[7]=xx_IsLock;
	for (i=0; i < 8; i++)_Context->msg_IsInterface[i]=" ";
	_Context->msg_IsInterface[0]=en_IsInterface;
	_Context->msg_IsInterface[1]=fr_IsInterface;
	_Context->msg_IsInterface[7]=xx_IsInterface;
	for (i=0; i < 8; i++)_Context->msg_IsSpecial[i]=" ";
	_Context->msg_IsSpecial[1]=fr_IsSpecial;
	_Context->msg_IsSpecial[7]=xx_IsSpecial;
	for (i=0; i < 8; i++)_Context->msg_OnCreate[i]=" ";
	_Context->msg_OnCreate[0]=en_OnCreate;
	_Context->msg_OnCreate[1]=fr_OnCreate;
	_Context->msg_OnCreate[7]=xx_OnCreate;
	_Context->focus_pages[2]=30;
	for (i=0; i < 8; i++)_Context->msg_CreateOptions[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_OnShowPage[i]=" ";
	_Context->msg_OnShowPage[0]=en_OnShowPage;
	_Context->msg_OnShowPage[1]=fr_OnShowPage;
	_Context->msg_OnShowPage[2]=it_OnShowPage;
	_Context->msg_OnShowPage[3]=es_OnShowPage;
	_Context->msg_OnShowPage[4]=de_OnShowPage;
	_Context->msg_OnShowPage[5]=nl_OnShowPage;
	_Context->msg_OnShowPage[6]=pt_OnShowPage;
	_Context->msg_OnShowPage[7]=xx_OnShowPage;
	_Context->focus_pages[3]=33;
	for (i=0; i < 8; i++)_Context->msg_ShowOptions[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_OnGetFocus[i]=" ";
	_Context->msg_OnGetFocus[0]=en_OnGetFocus;
	_Context->msg_OnGetFocus[1]=fr_OnGetFocus;
	_Context->msg_OnGetFocus[2]=it_OnGetFocus;
	_Context->msg_OnGetFocus[3]=es_OnGetFocus;
	_Context->msg_OnGetFocus[4]=de_OnGetFocus;
	_Context->msg_OnGetFocus[5]=nl_OnGetFocus;
	_Context->msg_OnGetFocus[6]=pt_OnGetFocus;
	_Context->msg_OnGetFocus[7]=xx_OnGetFocus;
	_Context->focus_pages[4]=36;
	for (i=0; i < 8; i++)_Context->msg_FocusOptions[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_OnEvent[i]=" ";
	_Context->msg_OnEvent[0]=en_OnEvent;
	_Context->msg_OnEvent[1]=fr_OnEvent;
	_Context->msg_OnEvent[2]=it_OnEvent;
	_Context->msg_OnEvent[3]=es_OnEvent;
	_Context->msg_OnEvent[4]=de_OnEvent;
	_Context->msg_OnEvent[5]=nl_OnEvent;
	_Context->msg_OnEvent[6]=pt_OnEvent;
	_Context->msg_OnEvent[7]=xx_OnEvent;
	_Context->focus_pages[5]=39;
	for (i=0; i < 8; i++)_Context->msg_Auto1378[i]=" ";
	_Context->msg_Auto1378[0]=en_Auto1378;
	_Context->msg_Auto1378[1]=fr_Auto1378;
	_Context->msg_Auto1378[7]=xx_Auto1378;
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
	for (i=0; i < 8; i++)_Context->msg_OnLoseFocus[i]=" ";
	_Context->msg_OnLoseFocus[0]=en_OnLoseFocus;
	_Context->msg_OnLoseFocus[1]=fr_OnLoseFocus;
	_Context->msg_OnLoseFocus[2]=it_OnLoseFocus;
	_Context->msg_OnLoseFocus[3]=es_OnLoseFocus;
	_Context->msg_OnLoseFocus[4]=de_OnLoseFocus;
	_Context->msg_OnLoseFocus[5]=nl_OnLoseFocus;
	_Context->msg_OnLoseFocus[6]=pt_OnLoseFocus;
	_Context->msg_OnLoseFocus[7]=xx_OnLoseFocus;
	_Context->focus_pages[6]=46;
	for (i=0; i < 8; i++)_Context->msg_LoseOptions[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_OnHidePage[i]=" ";
	_Context->msg_OnHidePage[0]=en_OnHidePage;
	_Context->msg_OnHidePage[1]=fr_OnHidePage;
	_Context->msg_OnHidePage[2]=it_OnHidePage;
	_Context->msg_OnHidePage[3]=es_OnHidePage;
	_Context->msg_OnHidePage[4]=de_OnHidePage;
	_Context->msg_OnHidePage[5]=nl_OnHidePage;
	_Context->msg_OnHidePage[6]=pt_OnHidePage;
	_Context->msg_OnHidePage[7]=xx_OnHidePage;
	_Context->focus_pages[7]=49;
	for (i=0; i < 8; i++)_Context->msg_HideOptions[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_OnRemove[i]=" ";
	_Context->msg_OnRemove[0]=en_OnRemove;
	_Context->msg_OnRemove[1]=fr_OnRemove;
	_Context->msg_OnRemove[2]=it_OnRemove;
	_Context->msg_OnRemove[3]=es_OnRemove;
	_Context->msg_OnRemove[4]=de_OnRemove;
	_Context->msg_OnRemove[5]=nl_OnRemove;
	_Context->msg_OnRemove[6]=pt_OnRemove;
	_Context->msg_OnRemove[7]=xx_OnRemove;
	_Context->focus_pages[8]=52;
	for (i=0; i < 8; i++)_Context->msg_RemoveOptions[i]=" ";
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_WidgetProperties,_Context->y_WidgetProperties,710+10,530+10);
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
	if ((_Context->p_PayLoadSelect != (void *) 0)
	&& (_Context->s_PayLoadSelect != 0)) {
		(void)visual_buffer_put(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+260);
		_Context->s_PayLoadSelect=0;
		}
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
	char * pAtX,
	char * pAtY,
	char * pWidth,
	char * pHeight,
	char * pTextFont,
	char * pTextColour,
	char * pBackground,
	char * pPayLoad,
	char * pIdentity,
	char * pFormat,
	char * pStyleSheet,
	char * pAuto1376,
	char * pWidgetClass,
	char * pAlign,
	char * pType,
	char * pIsBold,
	char * pIsUnderline,
	char * pIsShadow,
	char * pIsLock,
	char * pIsInterface,
	char * pIsSpecial,
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
	if (_Context->p_PayLoadSelect != (void *) 0)
		_Context->p_PayLoadSelect = visual_drop(_Context->p_PayLoadSelect);
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWSSSSWWWWWWWWWWWTWTWTWWWWWTWTWTWT");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_AtX, 7, pAtX);
		visual_transferout(_Context->buffer_AtY, 7, pAtY);
		visual_transferout(_Context->buffer_Width, 7, pWidth);
		visual_transferout(_Context->buffer_Height, 7, pHeight);
		visual_transferout((void *) 0, 0, pTextFont);
		if ( pTextFont != (char *) 0)
			*((int*)pTextFont) = _Context->value_TextFont;
		visual_transferout(_Context->buffer_TextColour, 12, pTextColour);
		visual_transferout(_Context->buffer_Background, 12, pBackground);
		visual_transferout(_Context->buffer_PayLoad, 325, pPayLoad);
		visual_transferout(_Context->buffer_Identity, 62, pIdentity);
		visual_transferout(_Context->buffer_Format, 325, pFormat);
		visual_transferout(_Context->buffer_StyleSheet, 65, pStyleSheet);
		visual_transferout(_Context->buffer_Auto1376, 6, pAuto1376);
		visual_transferout((void *) 0, 0, pWidgetClass);
		if ( pWidgetClass != (char *) 0)
			*((int*)pWidgetClass) = _Context->value_WidgetClass;
		visual_transferout((void *) 0, 0, pAlign);
		if ( pAlign != (char *) 0)
			*((int*)pAlign) = _Context->value_Align;
		visual_transferout((void *) 0, 0, pType);
		if ( pType != (char *) 0)
			*((int*)pType) = _Context->value_Type;
		visual_transferout((void *) 0, 0, pIsBold);
		if ( pIsBold != (char *) 0)
			*((int*)pIsBold) = _Context->value_IsBold;
		visual_transferout((void *) 0, 0, pIsUnderline);
		if ( pIsUnderline != (char *) 0)
			*((int*)pIsUnderline) = _Context->value_IsUnderline;
		visual_transferout((void *) 0, 0, pIsShadow);
		if ( pIsShadow != (char *) 0)
			*((int*)pIsShadow) = _Context->value_IsShadow;
		visual_transferout((void *) 0, 0, pIsLock);
		if ( pIsLock != (char *) 0)
			*((int*)pIsLock) = _Context->value_IsLock;
		visual_transferout((void *) 0, 0, pIsInterface);
		if ( pIsInterface != (char *) 0)
			*((int*)pIsInterface) = _Context->value_IsInterface;
		visual_transferout((void *) 0, 0, pIsSpecial);
		if ( pIsSpecial != (char *) 0)
			*((int*)pIsSpecial) = _Context->value_IsSpecial;
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
private int on_PayLoadSelect_show(struct accept_widget_properties_context * _Context) {
	switch(_Context->value_WidgetClass){
	case _IMAGE_FRAME:
	case _BUTTON_FRAME:
	case _DATA_FRAME:
		if ((_Context->p_PayLoadSelect != (void *) 0)
	&& (_Context->s_PayLoadSelect == 0)) {
		(void)visual_buffer_get(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+260);
		_Context->s_PayLoadSelect=1;
		}
	if ((_Context->p_PayLoadSelect != (void *) 0)
	&& (_Context->s_PayLoadSelect == 0)) {
		(void)visual_buffer_get(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+260);
		_Context->s_PayLoadSelect=1;
		}
	_Context->trigger_PayLoadSelect=visual_trigger_code(_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+260,20,18,vfh[8],28,28,_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]),0);
;
	break;
	default:
		if ((_Context->p_PayLoadSelect != (void *) 0)
	&& (_Context->s_PayLoadSelect != 0)) {
		(void)visual_buffer_put(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+260);
		_Context->s_PayLoadSelect=0;
		}
;
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
	visual_window(_Context->x_WidgetProperties,_Context->y_WidgetProperties,710,530,vfh[2],_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]),0x407);
	visual_image(_Context->x_WidgetProperties+3,_Context->y_WidgetProperties+22,703,505,_Context->msg_Auto1369[_Context->language],4);
	visual_filzone(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+50,650,30,18,12);
	visual_filzone(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+70,670,410,18,12);
	visual_filzone(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+490,110,30,18,12);
	visual_filzone(_Context->x_WidgetProperties+340,_Context->y_WidgetProperties+490,110,30,18,12);
	visual_filzone(_Context->x_WidgetProperties+590,_Context->y_WidgetProperties+490,110,30,18,12);
	if (_Context->page_number == 1 ) {
	_Context->trigger_Widget=visual_trigger_code(_Context->msg_Widget[_Context->language],strlen(_Context->msg_Widget[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_Widget[_Context->language],strlen(_Context->msg_Widget[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_Widget[_Context->language],strlen(_Context->msg_Widget[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_WidgetProperties+50,_Context->y_WidgetProperties+80,70,16,vfh[2],27,0,_Context->msg_auto50093[_Context->language],strlen(_Context->msg_auto50093[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_WidgetProperties+290,_Context->y_WidgetProperties+80,100,20,vfh[2],27,0,_Context->msg_auto49[_Context->language],strlen(_Context->msg_auto49[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_WidgetProperties+130,_Context->y_WidgetProperties+80,56+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+130+1,_Context->y_WidgetProperties+80+1,56,16,vfh[1],34,0,_Context->buffer_AtX,7,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_WidgetProperties+190,_Context->y_WidgetProperties+80,10,20,vfh[1],34,0,_Context->msg_auto53[_Context->language],strlen(_Context->msg_auto53[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_WidgetProperties+200,_Context->y_WidgetProperties+80,56+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+200+1,_Context->y_WidgetProperties+80+1,56,16,vfh[1],34,0,_Context->buffer_AtY,7,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_WidgetProperties+450,_Context->y_WidgetProperties+80,10,20,vfh[1],34,0,_Context->msg_auto55[_Context->language],strlen(_Context->msg_auto55[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_WidgetProperties+390,_Context->y_WidgetProperties+80,56+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+390+1,_Context->y_WidgetProperties+80+1,56,16,vfh[1],34,0,_Context->buffer_Width,7,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+80,56+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+460+1,_Context->y_WidgetProperties+80+1,56,16,vfh[1],34,0,_Context->buffer_Height,7,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_WidgetProperties+50,_Context->y_WidgetProperties+110,70,16,vfh[2],27,0,_Context->msg_auto64[_Context->language],strlen(_Context->msg_auto64[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_WidgetProperties+50,_Context->y_WidgetProperties+140,70,16,vfh[2],27,0,_Context->msg_auto67[_Context->language],strlen(_Context->msg_auto67[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_WidgetProperties+130,_Context->y_WidgetProperties+110,130,100,vfh[1],34,0,parse_selection(TextFontList,&_Context->value_TextFont),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_WidgetProperties+130,_Context->y_WidgetProperties+140,96+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+130+1,_Context->y_WidgetProperties+140+1,96,16,vfh[1],34,0,_Context->buffer_TextColour,12,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+230,_Context->y_WidgetProperties+140,28,16,vfh[8],28,28,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_WidgetProperties+290,_Context->y_WidgetProperties+140,100,20,vfh[2],27,0,_Context->msg_auto70[_Context->language],strlen(_Context->msg_auto70[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_WidgetProperties+390,_Context->y_WidgetProperties+140,96+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+390+1,_Context->y_WidgetProperties+140+1,96,16,vfh[1],34,0,_Context->buffer_Background,12,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_bgSelect=visual_trigger_code(_Context->msg_bgSelect[_Context->language],strlen(_Context->msg_bgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+490,_Context->y_WidgetProperties+140,28,16,vfh[8],28,28,_Context->msg_bgSelect[_Context->language],strlen(_Context->msg_bgSelect[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	if ((_Context->p_PayLoadSelect != (void *) 0)
	&& (_Context->s_PayLoadSelect == 0)) {
		(void)visual_buffer_get(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+260);
		_Context->s_PayLoadSelect=1;
		}
	(void) on_PayLoadSelect_show(_Context);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_WidgetProperties+50,_Context->y_WidgetProperties+170,74,16,vfh[2],27,0,WidgetPayload(_Context->value_WidgetClass),strlen(WidgetPayload(_Context->value_WidgetClass)),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_WidgetProperties+50,_Context->y_WidgetProperties+410,74,16,vfh[2],27,0,_Context->msg_Auto13691[_Context->language],strlen(_Context->msg_Auto13691[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_WidgetProperties+130,_Context->y_WidgetProperties+170,520+2,80+2,5);
	visual_text(_Context->x_WidgetProperties+130+1,_Context->y_WidgetProperties+170+1,520,80,vfh[1],34,0,_Context->buffer_PayLoad,325,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_WidgetProperties+130,_Context->y_WidgetProperties+260,496+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+130+1,_Context->y_WidgetProperties+260+1,496,16,vfh[1],34,0,_Context->buffer_Identity,62,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_WidgetProperties+130,_Context->y_WidgetProperties+320,520+2,80+2,5);
	visual_text(_Context->x_WidgetProperties+130+1,_Context->y_WidgetProperties+320+1,520,80,vfh[1],27,0,_Context->buffer_Format,325,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_WidgetProperties+130,_Context->y_WidgetProperties+410,520+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+130+1,_Context->y_WidgetProperties+410+1,520,16,vfh[1],0,0,_Context->buffer_StyleSheet,65,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_WidgetProperties+50,_Context->y_WidgetProperties+260,76,17,vfh[2],27,0,_Context->msg_auto77[_Context->language],strlen(_Context->msg_auto77[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_WidgetProperties+50,_Context->y_WidgetProperties+440,75,16,vfh[2],27,0,_Context->msg_Auto1375[_Context->language],strlen(_Context->msg_Auto1375[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_WidgetProperties+130,_Context->y_WidgetProperties+440,48+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+130+1,_Context->y_WidgetProperties+440+1,48,16,vfh[1],27,0,_Context->buffer_Auto1376,6,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_WidgetProperties+50,_Context->y_WidgetProperties+290,84,16,vfh[2],27,0,_Context->msg_auto80[_Context->language],strlen(_Context->msg_auto80[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_WidgetProperties+50,_Context->y_WidgetProperties+320,78,21,vfh[2],27,0,WidgetMessage(_Context->value_WidgetClass,0),strlen(WidgetMessage(_Context->value_WidgetClass,0)),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_WidgetProperties+290,_Context->y_WidgetProperties+290,140,16,vfh[2],27,0,_Context->msg_auto269[_Context->language],strlen(_Context->msg_auto269[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_WidgetProperties+130,_Context->y_WidgetProperties+290,128,80,vfh[1],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),0);
		}
	_Context->trigger_Ok=visual_trigger_code(_Context->msg_Ok[_Context->language],strlen(_Context->msg_Ok[_Context->language]));
	visual_button(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+480,110,30,vfh[2],34,0,_Context->msg_Ok[_Context->language],strlen(_Context->msg_Ok[_Context->language]),0);
	_Context->trigger_FullScreen=visual_trigger_code(_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]));
	visual_button(_Context->x_WidgetProperties+330,_Context->y_WidgetProperties+480,112,32,vfh[2],28,28,_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_WidgetProperties+580,_Context->y_WidgetProperties+480,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_WidgetProperties+290,_Context->y_WidgetProperties+110,100,20,vfh[2],27,0,_Context->msg_auto138[_Context->language],strlen(_Context->msg_auto138[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_WidgetProperties+390,_Context->y_WidgetProperties+110,130,100,vfh[1],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_WidgetProperties+430,_Context->y_WidgetProperties+290,216,80,vfh[1],0,0,parse_selection(WidgetTypeList,&_Context->value_Type),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_IsBold=visual_trigger_code(WidgetMessage(_Context->value_WidgetClass,1),strlen(WidgetMessage(_Context->value_WidgetClass,1)));
	visual_check(_Context->x_WidgetProperties+540,_Context->y_WidgetProperties+80,112,16,vfh[2],175,0,WidgetMessage(_Context->value_WidgetClass,1),strlen(WidgetMessage(_Context->value_WidgetClass,1)),_Context->value_IsBold|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_IsUnderline=visual_trigger_code(WidgetMessage(_Context->value_WidgetClass,2),strlen(WidgetMessage(_Context->value_WidgetClass,2)));
	visual_check(_Context->x_WidgetProperties+540,_Context->y_WidgetProperties+110,112,16,vfh[2],175,0,WidgetMessage(_Context->value_WidgetClass,2),strlen(WidgetMessage(_Context->value_WidgetClass,2)),_Context->value_IsUnderline|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_IsShadow=visual_trigger_code(WidgetMessage(_Context->value_WidgetClass,3),strlen(WidgetMessage(_Context->value_WidgetClass,3)));
	visual_check(_Context->x_WidgetProperties+540,_Context->y_WidgetProperties+140,116,16,vfh[2],28,28,WidgetMessage(_Context->value_WidgetClass,3),strlen(WidgetMessage(_Context->value_WidgetClass,3)),_Context->value_IsShadow|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+200,_Context->y_WidgetProperties+440,126,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_IsInterface=visual_trigger_code(_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]));
	visual_check(_Context->x_WidgetProperties+330,_Context->y_WidgetProperties+440,154,16,vfh[2],28,28,_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]),_Context->value_IsInterface|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_IsSpecial=visual_trigger_code(WidgetMessage(_Context->value_WidgetClass,4),strlen(WidgetMessage(_Context->value_WidgetClass,4)));
	visual_check(_Context->x_WidgetProperties+490,_Context->y_WidgetProperties+440,154,16,vfh[2],28,28,WidgetMessage(_Context->value_WidgetClass,4),strlen(WidgetMessage(_Context->value_WidgetClass,4)),_Context->value_IsSpecial|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_OnCreate=visual_trigger_code(_Context->msg_OnCreate[_Context->language],strlen(_Context->msg_OnCreate[_Context->language]));
	visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnCreate[_Context->language],strlen(_Context->msg_OnCreate[_Context->language]),81,2);
		(void) on_OnCreate_show(_Context);
	} else {
		visual_tabpage(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+40,670,430,vfh[2],_Context->msg_OnCreate[_Context->language],strlen(_Context->msg_OnCreate[_Context->language]),81,0);
		}
	if (_Context->page_number == 2 ) {
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,70,vfh[1],27,0,parse_selection(WidgetSizesOptions,&_Context->value_CreateOptions),0);
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
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,70,vfh[1],27,0,parse_selection(WidgetShowOptions,&_Context->value_ShowOptions),0);
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
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,70,vfh[1],27,0,parse_selection(WidgetFocusOptions,&_Context->value_FocusOptions),0);
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
	visual_text(_Context->x_WidgetProperties+40,_Context->y_WidgetProperties+80,168,16,vfh[2],27,0,_Context->msg_Auto1378[_Context->language],strlen(_Context->msg_Auto1378[_Context->language]),1025);
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
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,70,vfh[1],27,0,parse_selection(WidgetEventOptions,&_Context->value_EventOptions),0);
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
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,70,vfh[1],27,0,parse_selection(WidgetEventOptions,&_Context->value_LoseOptions),0);
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
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,70,vfh[1],27,0,parse_selection(WidgetHideOptions,&_Context->value_HideOptions),0);
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
	visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,70,vfh[1],27,0,parse_selection(WidgetEventOptions,&_Context->value_RemoveOptions),0);
		}
	if (_Context->page_number == 8 ) {
	(void) on_Remove_show(_Context);
		}
	visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,710,530);
	visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,710,530);

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

		visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,710,530);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_fgSelect_event(struct accept_widget_properties_context * _Context) {
	int fgv=0;
	int bgv=0;
	char*sptr;
	int slen;
	int i;
	sptr=_Context->buffer_TextColour;
	slen=12;
	for(i=0;i<slen;i++){
	if((*(sptr+i)>='0')
	&&(*(sptr+i)<='9'))
	fgv=((fgv*10)+(*(sptr+i)-'0'));
	}
	sptr=_Context->buffer_Background;
	slen=12;
	for(i=0;i<slen;i++){
	if((*(sptr+i)>='0')
	&&(*(sptr+i)<='9'))
	bgv=((bgv*10)+(*(sptr+i)-'0'));
	}
	if(accept_visual_colour(&fgv,&bgv)!=27){
	sprintf(_Context->buffer_TextColour,"%u",fgv);
	sprintf(_Context->buffer_Background,"%u",bgv);
	}
		accept_widget_properties_show(_Context);
;
	return(-1);
}
private int on_bgSelect_event(struct accept_widget_properties_context * _Context) {
	on_fgSelect_event(_Context);
	return(-1);
}
private int on_PayLoadSelect_event(struct accept_widget_properties_context * _Context) {
	switch(_Context->value_WidgetClass){
	case _IMAGE_FRAME:
	case _BUTTON_FRAME:
		accept_widget_properties_hide(_Context);
;
	use_file_selector(_Context->buffer_PayLoad,WIDGET_FILE_GIF);
		accept_widget_properties_show(_Context);
;
	break;
	case _DATA_FRAME:
		accept_widget_properties_hide(_Context);
;
	if(_Context->value_IsLock!=0){
	use_data_selector(
	(void*)0,
	_Context->buffer_Format,325,/*classname*/
	_Context->buffer_Identity,62,/*instance*/
	_Context->buffer_PayLoad,325/*filename*/
	);
	}
	else{
	use_data_selector(
	(void*)0,
	_Context->buffer_Format,325,/*classname*/
	_Context->buffer_Identity,0,/*instance*/
	_Context->buffer_PayLoad,0/*filename*/
	);
	}
		accept_widget_properties_show(_Context);
;
	break;
	}
		return(-1);
}
private int on_Ok_event(struct accept_widget_properties_context * _Context) {
	return(13);
	return(-1);
}
private int on_FullScreen_event(struct accept_widget_properties_context * _Context) {
		accept_widget_properties_hide(_Context);
;
	switch(_Context->page_number){
	case 2:
	use_editor(_Context->buffer_Create,0); 
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* Create */
	/* OnCreate */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 2;
	accept_widget_properties_show(_Context);
	_Context->focus_item=30;
	accept_widget_properties_show(_Context);
	_Context->focus_item=32;
;
	break;
	case 3:
	use_editor(_Context->buffer_Show,0);
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* Show */
	/* OnShowPage */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 3;
	accept_widget_properties_show(_Context);
	_Context->focus_item=33;
	accept_widget_properties_show(_Context);
	_Context->focus_item=35;
;
	break;
	case 4:
	use_editor(_Context->buffer_GetFocus,0);
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* GetFocus */
	/* OnGetFocus */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 4;
	accept_widget_properties_show(_Context);
	_Context->focus_item=36;
	accept_widget_properties_show(_Context);
	_Context->focus_item=38;
;
	break;
	case 5:
	use_editor(_Context->buffer_Event,0);
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* Event */
	/* OnEvent */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 5;
	accept_widget_properties_show(_Context);
	_Context->focus_item=39;
	accept_widget_properties_show(_Context);
	_Context->focus_item=45;
;
	break;
	case 6:
	use_editor(_Context->buffer_LoseFocus,0);
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* LoseFocus */
	/* OnLoseFocus */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 6;
	accept_widget_properties_show(_Context);
	_Context->focus_item=46;
	accept_widget_properties_show(_Context);
	_Context->focus_item=48;
;
	break;
	case 7:
	use_editor(_Context->buffer_Hide,0);
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* Hide */
	/* OnHidePage */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 7;
	accept_widget_properties_show(_Context);
	_Context->focus_item=49;
	accept_widget_properties_show(_Context);
	_Context->focus_item=51;
;
	break;
	case 8:
	use_editor(_Context->buffer_Remove,0);
		accept_widget_properties_show(_Context);
;
	visual_frame(_Context->x_WidgetProperties+30,_Context->y_WidgetProperties+110,648+2,352+2,5);
;
		/* Remove */
	/* OnRemove */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 8;
	accept_widget_properties_show(_Context);
	_Context->focus_item=52;
	accept_widget_properties_show(_Context);
	_Context->focus_item=54;
;
	break;
	default:
		accept_widget_properties_show(_Context);
;
		/* Widget */
	accept_widget_properties_losefocus(_Context);
	_Context->page_number = 1;
	accept_widget_properties_show(_Context);
	_Context->focus_item=2;
;
	}
	return(-1);
}
private int on_Cancel_event(struct accept_widget_properties_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_widget_properties_event(
struct accept_widget_properties_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Widget == mb ) return(2);
		if (_Context->trigger_fgSelect == mb ) return(9);
		if (_Context->trigger_bgSelect == mb ) return(11);
		if (_Context->trigger_PayLoadSelect == mb ) return(12);
		if (_Context->trigger_Ok == mb ) return(19);
		if (_Context->trigger_FullScreen == mb ) return(20);
		if (_Context->trigger_Cancel == mb ) return(21);
		if (_Context->trigger_IsBold == mb ) return(24);
		if (_Context->trigger_IsUnderline == mb ) return(25);
		if (_Context->trigger_IsShadow == mb ) return(26);
		if (_Context->trigger_IsLock == mb ) return(27);
		if (_Context->trigger_IsInterface == mb ) return(28);
		if (_Context->trigger_IsSpecial == mb ) return(29);
		if (_Context->trigger_OnCreate == mb ) return(30);
		if (_Context->trigger_OnShowPage == mb ) return(33);
		if (_Context->trigger_OnGetFocus == mb ) return(36);
		if (_Context->trigger_OnEvent == mb ) return(39);
		if (_Context->trigger_MimoMove == mb ) return(40);
		if (_Context->trigger_MimoDown == mb ) return(41);
		if (_Context->trigger_MimoUp == mb ) return(42);
		if (_Context->trigger_MimoHold == mb ) return(43);
		if (_Context->trigger_OnLoseFocus == mb ) return(46);
		if (_Context->trigger_OnHidePage == mb ) return(49);
		if (_Context->trigger_OnRemove == mb ) return(52);
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
			visual_help("vwidget.htm");
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
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+130) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+130+56) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(3); /* AtX */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+200) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+200+56) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(4); /* AtY */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+390) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+390+56) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(5); /* Width */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+460) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+460+56) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(6); /* Height */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+130+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+130+130) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+16))) {
			return(7); /* TextFont */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+130) ) 
		&&  ( my >= (_Context->y_WidgetProperties+140) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+130+96) ) 
		&&  ( my <= (_Context->y_WidgetProperties+140+16))) {
			return(8); /* TextColour */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+230) ) 
		&&  ( my >= (_Context->y_WidgetProperties+140) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+230+28) ) 
		&&  ( my <= (_Context->y_WidgetProperties+140+16))) {
			return(9); /* fgSelect */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+390) ) 
		&&  ( my >= (_Context->y_WidgetProperties+140) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+390+96) ) 
		&&  ( my <= (_Context->y_WidgetProperties+140+16))) {
			return(10); /* Background */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+490) ) 
		&&  ( my >= (_Context->y_WidgetProperties+140) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+490+28) ) 
		&&  ( my <= (_Context->y_WidgetProperties+140+16))) {
			return(11); /* bgSelect */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+630) ) 
		&&  ( my >= (_Context->y_WidgetProperties+260) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+630+20) ) 
		&&  ( my <= (_Context->y_WidgetProperties+260+18))) {
			return(12); /* PayLoadSelect */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+130) ) 
		&&  ( my >= (_Context->y_WidgetProperties+170) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+130+520) ) 
		&&  ( my <= (_Context->y_WidgetProperties+170+80))) {
			return(13); /* PayLoad */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+130) ) 
		&&  ( my >= (_Context->y_WidgetProperties+260) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+130+496) ) 
		&&  ( my <= (_Context->y_WidgetProperties+260+16))) {
			return(14); /* Identity */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+130) ) 
		&&  ( my >= (_Context->y_WidgetProperties+320) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+130+520) ) 
		&&  ( my <= (_Context->y_WidgetProperties+320+80))) {
			return(15); /* Format */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+130) ) 
		&&  ( my >= (_Context->y_WidgetProperties+410) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+130+520) ) 
		&&  ( my <= (_Context->y_WidgetProperties+410+16))) {
			return(16); /* StyleSheet */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+130) ) 
		&&  ( my >= (_Context->y_WidgetProperties+440) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+130+48) ) 
		&&  ( my <= (_Context->y_WidgetProperties+440+16))) {
			return(17); /* Auto1376 */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+130+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+290) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+130+128) ) 
		&&  ( my <= (_Context->y_WidgetProperties+290+16))) {
			return(18); /* WidgetClass */
			}
		}
	if (( mx >= (_Context->x_WidgetProperties+20) ) 
	&&  ( my >= (_Context->y_WidgetProperties+480) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+20+110) ) 
	&&  ( my <= (_Context->y_WidgetProperties+480+30))) {
		return(19); /* Ok */
		}
	if (( mx >= (_Context->x_WidgetProperties+330) ) 
	&&  ( my >= (_Context->y_WidgetProperties+480) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+330+112) ) 
	&&  ( my <= (_Context->y_WidgetProperties+480+32))) {
		return(20); /* FullScreen */
		}
	if (( mx >= (_Context->x_WidgetProperties+580) ) 
	&&  ( my >= (_Context->y_WidgetProperties+480) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+580+110) ) 
	&&  ( my <= (_Context->y_WidgetProperties+480+30))) {
		return(21); /* Cancel */
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+390+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+390+130) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+16))) {
			return(22); /* Align */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+430+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+290) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+430+216) ) 
		&&  ( my <= (_Context->y_WidgetProperties+290+16))) {
			return(23); /* Type */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+540) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+540+112) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(24); /* IsBold */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+540) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+540+112) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+16))) {
			return(25); /* IsUnderline */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+540) ) 
		&&  ( my >= (_Context->y_WidgetProperties+140) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+540+116) ) 
		&&  ( my <= (_Context->y_WidgetProperties+140+16))) {
			return(26); /* IsShadow */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+200) ) 
		&&  ( my >= (_Context->y_WidgetProperties+440) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+200+126) ) 
		&&  ( my <= (_Context->y_WidgetProperties+440+16))) {
			return(27); /* IsLock */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+330) ) 
		&&  ( my >= (_Context->y_WidgetProperties+440) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+330+154) ) 
		&&  ( my <= (_Context->y_WidgetProperties+440+16))) {
			return(28); /* IsInterface */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_WidgetProperties+490) ) 
		&&  ( my >= (_Context->y_WidgetProperties+440) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+490+154) ) 
		&&  ( my <= (_Context->y_WidgetProperties+440+16))) {
			return(29); /* IsSpecial */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+81) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+158) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(30); /* OnCreate */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(31); /* CreateOptions */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(32); /* Create */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+159) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+230) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(33); /* OnShowPage */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(34); /* ShowOptions */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(35); /* Show */
			}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+231) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+326) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(36); /* OnGetFocus */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(37); /* FocusOptions */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(38); /* GetFocus */
			}
		}
	if (_Context->page_number == 5 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+327) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+399) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(39); /* OnEvent */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+230) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+230+40) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(40); /* MimoMove */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+280) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+280+42) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(41); /* MimoDown */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+330) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+330+24) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(42); /* MimoUp */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+360) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+360+40) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(43); /* MimoHold */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(44); /* EventOptions */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(45); /* Event */
			}
		}
	if (_Context->page_number == 6 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+400) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+502) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(46); /* OnLoseFocus */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(47); /* LoseOptions */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(48); /* LoseFocus */
			}
		}
	if (_Context->page_number == 7 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+503) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+566) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(49); /* OnHidePage */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(50); /* HideOptions */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(51); /* Hide */
			}
		}
	if (_Context->page_number == 8 ) {
	} else {
		if (( mx >= (_Context->x_WidgetProperties+20+567) ) 
		&&  ( my >= (_Context->y_WidgetProperties+40) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+20+652) ) 
		&&  ( my <= (_Context->y_WidgetProperties+40+24))) {
			return(52); /* OnRemove */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_WidgetProperties+500+0) ) 
		&&  ( my >= (_Context->y_WidgetProperties+80) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+500+180) ) 
		&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
			return(53); /* RemoveOptions */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_WidgetProperties+30) ) 
		&&  ( my >= (_Context->y_WidgetProperties+110) ) 
		&&  ( mx <= (_Context->x_WidgetProperties+30+648) ) 
		&&  ( my <= (_Context->y_WidgetProperties+110+352))) {
			return(54); /* Remove */
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
				/* AtX */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_WidgetProperties+130+1,_Context->y_WidgetProperties+80+1,56,16,vfh[1],_Context->buffer_AtX,7);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* AtY */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_WidgetProperties+200+1,_Context->y_WidgetProperties+80+1,56,16,vfh[1],_Context->buffer_AtY,7);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* Width */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_WidgetProperties+390+1,_Context->y_WidgetProperties+80+1,56,16,vfh[1],_Context->buffer_Width,7);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* Height */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_WidgetProperties+460+1,_Context->y_WidgetProperties+80+1,56,16,vfh[1],_Context->buffer_Height,7);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* TextFont */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+130,_Context->y_WidgetProperties+110,130,100,vfh[1],34,0,parse_selection(TextFontList,&_Context->value_TextFont),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* TextColour */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_WidgetProperties+130+1,_Context->y_WidgetProperties+140+1,96,16,vfh[1],_Context->buffer_TextColour,12);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* fgSelect */
				if (_Context->page_number == 1 ) {
					visual_button(_Context->x_WidgetProperties+230,_Context->y_WidgetProperties+140,28,16,vfh[8],28,28,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_WidgetProperties+230,_Context->y_WidgetProperties+140,28,16,vfh[8],28,28,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* Background */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_WidgetProperties+390+1,_Context->y_WidgetProperties+140+1,96,16,vfh[1],_Context->buffer_Background,12);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* bgSelect */
				if (_Context->page_number == 1 ) {
					visual_button(_Context->x_WidgetProperties+490,_Context->y_WidgetProperties+140,28,16,vfh[8],28,28,_Context->msg_bgSelect[_Context->language],strlen(_Context->msg_bgSelect[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_WidgetProperties+490,_Context->y_WidgetProperties+140,28,16,vfh[8],28,28,_Context->msg_bgSelect[_Context->language],strlen(_Context->msg_bgSelect[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* PayLoad */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_WidgetProperties+130+1,_Context->y_WidgetProperties+170+1,520,80,vfh[1],_Context->buffer_PayLoad,325);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* Identity */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_WidgetProperties+130+1,_Context->y_WidgetProperties+260+1,496,16,vfh[1],_Context->buffer_Identity,62);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* Format */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_WidgetProperties+130+1,_Context->y_WidgetProperties+320+1,520,80,vfh[1],_Context->buffer_Format,325);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* StyleSheet */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_WidgetProperties+130+1,_Context->y_WidgetProperties+410+1,520,16,vfh[1],_Context->buffer_StyleSheet,65);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* Auto1376 */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_WidgetProperties+130+1,_Context->y_WidgetProperties+440+1,48,16,vfh[1],_Context->buffer_Auto1376,6);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* WidgetClass */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+130,_Context->y_WidgetProperties+290,128,80,vfh[1],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* Align */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+390,_Context->y_WidgetProperties+110,130,100,vfh[1],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x17 :
				/* Type */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+430,_Context->y_WidgetProperties+290,216,80,vfh[1],0,0,parse_selection(WidgetTypeList,&_Context->value_Type),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x18 :
				/* IsBold */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_WidgetProperties+540,_Context->y_WidgetProperties+80,112,16,vfh[2],175,0,WidgetMessage(_Context->value_WidgetClass,1),strlen(WidgetMessage(_Context->value_WidgetClass,1)),(_Context->value_IsBold |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_WidgetProperties+540,_Context->y_WidgetProperties+80,112,16,vfh[2],175,0,WidgetMessage(_Context->value_WidgetClass,1),strlen(WidgetMessage(_Context->value_WidgetClass,1)),(_Context->value_IsBold |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* IsUnderline */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_WidgetProperties+540,_Context->y_WidgetProperties+110,112,16,vfh[2],175,0,WidgetMessage(_Context->value_WidgetClass,2),strlen(WidgetMessage(_Context->value_WidgetClass,2)),(_Context->value_IsUnderline |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_WidgetProperties+540,_Context->y_WidgetProperties+110,112,16,vfh[2],175,0,WidgetMessage(_Context->value_WidgetClass,2),strlen(WidgetMessage(_Context->value_WidgetClass,2)),(_Context->value_IsUnderline |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* IsShadow */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_WidgetProperties+540,_Context->y_WidgetProperties+140,116,16,vfh[2],28,28,WidgetMessage(_Context->value_WidgetClass,3),strlen(WidgetMessage(_Context->value_WidgetClass,3)),(_Context->value_IsShadow |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_WidgetProperties+540,_Context->y_WidgetProperties+140,116,16,vfh[2],28,28,WidgetMessage(_Context->value_WidgetClass,3),strlen(WidgetMessage(_Context->value_WidgetClass,3)),(_Context->value_IsShadow |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* IsLock */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_WidgetProperties+200,_Context->y_WidgetProperties+440,126,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),(_Context->value_IsLock |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_WidgetProperties+200,_Context->y_WidgetProperties+440,126,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),(_Context->value_IsLock |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1c :
				/* IsInterface */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_WidgetProperties+330,_Context->y_WidgetProperties+440,154,16,vfh[2],28,28,_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]),(_Context->value_IsInterface |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_WidgetProperties+330,_Context->y_WidgetProperties+440,154,16,vfh[2],28,28,_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]),(_Context->value_IsInterface |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1d :
				/* IsSpecial */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_WidgetProperties+490,_Context->y_WidgetProperties+440,154,16,vfh[2],28,28,WidgetMessage(_Context->value_WidgetClass,4),strlen(WidgetMessage(_Context->value_WidgetClass,4)),(_Context->value_IsSpecial |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_WidgetProperties+490,_Context->y_WidgetProperties+440,154,16,vfh[2],28,28,WidgetMessage(_Context->value_WidgetClass,4),strlen(WidgetMessage(_Context->value_WidgetClass,4)),(_Context->value_IsSpecial |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* OnCreate */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x1f :
				/* CreateOptions */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,70,vfh[1],27,0,parse_selection(WidgetSizesOptions,&_Context->value_CreateOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x20 :
				/* Create */
				if (_Context->page_number == 2 ) {
					if ((_Context->keycode = on_Create_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x21 :
				/* OnShowPage */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x22 :
				/* ShowOptions */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,70,vfh[1],27,0,parse_selection(WidgetShowOptions,&_Context->value_ShowOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x23 :
				/* Show */
				if (_Context->page_number == 3 ) {
					if ((_Context->keycode = on_Show_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x24 :
				/* OnGetFocus */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x25 :
				/* FocusOptions */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,70,vfh[1],27,0,parse_selection(WidgetFocusOptions,&_Context->value_FocusOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x26 :
				/* GetFocus */
				if (_Context->page_number == 4 ) {
					if ((_Context->keycode = on_GetFocus_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x27 :
				/* OnEvent */
				if (_Context->page_number == 5 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x28 :
				/* MimoMove */
				if (_Context->page_number == 5 ) {
				visual_switch(_Context->x_WidgetProperties+230,_Context->y_WidgetProperties+80,40,16,vfh[1],25,26,_Context->msg_MimoMove[_Context->language],strlen(_Context->msg_MimoMove[_Context->language]),(_Context->value_MimoMove | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
				visual_switch(_Context->x_WidgetProperties+230,_Context->y_WidgetProperties+80,40,16,vfh[1],25,26,_Context->msg_MimoMove[_Context->language],strlen(_Context->msg_MimoMove[_Context->language]),(_Context->value_MimoMove | 0 | 0x0030 ));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x29 :
				/* MimoDown */
				if (_Context->page_number == 5 ) {
				visual_switch(_Context->x_WidgetProperties+280,_Context->y_WidgetProperties+80,42,16,vfh[1],25,26,_Context->msg_MimoDown[_Context->language],strlen(_Context->msg_MimoDown[_Context->language]),(_Context->value_MimoDown | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
				visual_switch(_Context->x_WidgetProperties+280,_Context->y_WidgetProperties+80,42,16,vfh[1],25,26,_Context->msg_MimoDown[_Context->language],strlen(_Context->msg_MimoDown[_Context->language]),(_Context->value_MimoDown | 0 | 0x0030 ));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2a :
				/* MimoUp */
				if (_Context->page_number == 5 ) {
				visual_switch(_Context->x_WidgetProperties+330,_Context->y_WidgetProperties+80,24,16,vfh[1],25,26,_Context->msg_MimoUp[_Context->language],strlen(_Context->msg_MimoUp[_Context->language]),(_Context->value_MimoUp | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
				visual_switch(_Context->x_WidgetProperties+330,_Context->y_WidgetProperties+80,24,16,vfh[1],25,26,_Context->msg_MimoUp[_Context->language],strlen(_Context->msg_MimoUp[_Context->language]),(_Context->value_MimoUp | 0 | 0x0030 ));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2b :
				/* MimoHold */
				if (_Context->page_number == 5 ) {
				visual_switch(_Context->x_WidgetProperties+360,_Context->y_WidgetProperties+80,40,16,vfh[1],25,26,_Context->msg_MimoHold[_Context->language],strlen(_Context->msg_MimoHold[_Context->language]),(_Context->value_MimoHold | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
				visual_switch(_Context->x_WidgetProperties+360,_Context->y_WidgetProperties+80,40,16,vfh[1],25,26,_Context->msg_MimoHold[_Context->language],strlen(_Context->msg_MimoHold[_Context->language]),(_Context->value_MimoHold | 0 | 0x0030 ));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2c :
				/* EventOptions */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,70,vfh[1],27,0,parse_selection(WidgetEventOptions,&_Context->value_EventOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2d :
				/* Event */
				if (_Context->page_number == 5 ) {
					if ((_Context->keycode = on_Event_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2e :
				/* OnLoseFocus */
				if (_Context->page_number == 6 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x2f :
				/* LoseOptions */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,70,vfh[1],27,0,parse_selection(WidgetEventOptions,&_Context->value_LoseOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x30 :
				/* LoseFocus */
				if (_Context->page_number == 6 ) {
					if ((_Context->keycode = on_LoseFocus_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x31 :
				/* OnHidePage */
				if (_Context->page_number == 7 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x32 :
				/* HideOptions */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,70,vfh[1],27,0,parse_selection(WidgetHideOptions,&_Context->value_HideOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x33 :
				/* Hide */
				if (_Context->page_number == 7 ) {
					if ((_Context->keycode = on_Hide_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x34 :
				/* OnRemove */
				if (_Context->page_number == 8 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x35 :
				/* RemoveOptions */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_select(_Context->x_WidgetProperties+500,_Context->y_WidgetProperties+80,180,70,vfh[1],27,0,parse_selection(WidgetEventOptions,&_Context->value_RemoveOptions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x36 :
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
			_Context->focus_item=54;
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
						/* AtX */
						continue;
					case	0x4 :
						/* AtY */
						continue;
					case	0x5 :
						/* Width */
						continue;
					case	0x6 :
						/* Height */
						continue;
					case	0x7 :
						/* TextFont */
						continue;
					case	0x8 :
						/* TextColour */
						continue;
					case	0x9 :
						/* fgSelect */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_WidgetProperties+230,_Context->y_WidgetProperties+140,28,16,vfh[8],28,28,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_WidgetProperties+230,_Context->y_WidgetProperties+140,28,16,vfh[8],28,28,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_fgSelect_event(_Context)) != -1) break;

							}
						continue;
					case	0xa :
						/* Background */
						continue;
					case	0xb :
						/* bgSelect */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_WidgetProperties+490,_Context->y_WidgetProperties+140,28,16,vfh[8],28,28,_Context->msg_bgSelect[_Context->language],strlen(_Context->msg_bgSelect[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_WidgetProperties+490,_Context->y_WidgetProperties+140,28,16,vfh[8],28,28,_Context->msg_bgSelect[_Context->language],strlen(_Context->msg_bgSelect[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_bgSelect_event(_Context)) != -1) break;

							}
						continue;
					case	0xc :
						/* PayLoadSelect */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+260,20,18,vfh[8],28,28,_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_WidgetProperties+630,_Context->y_WidgetProperties+260,20,18,vfh[8],28,28,_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_PayLoadSelect_event(_Context)) != -1) break;

							}
						continue;
					case	0xd :
						/* PayLoad */
						continue;
					case	0xe :
						/* Identity */
						continue;
					case	0xf :
						/* Format */
						continue;
					case	0x10 :
						/* StyleSheet */
						continue;
					case	0x11 :
						/* Auto1376 */
						continue;
					case	0x12 :
						/* WidgetClass */
						continue;
					case	0x13 :
						/* Ok */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+480,110,30,vfh[2],34,0,_Context->msg_Ok[_Context->language],strlen(_Context->msg_Ok[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+480,110,30,vfh[2],34,0,_Context->msg_Ok[_Context->language],strlen(_Context->msg_Ok[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Ok_event(_Context)) != -1) break;

							}
						continue;
					case	0x14 :
						/* FullScreen */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_WidgetProperties+330,_Context->y_WidgetProperties+480,112,32,vfh[2],28,28,_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_WidgetProperties+330,_Context->y_WidgetProperties+480,112,32,vfh[2],28,28,_Context->msg_FullScreen[_Context->language],strlen(_Context->msg_FullScreen[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_FullScreen_event(_Context)) != -1) break;

							}
						continue;
					case	0x15 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_WidgetProperties+580,_Context->y_WidgetProperties+480,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_WidgetProperties+580,_Context->y_WidgetProperties+480,110,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
						continue;
					case	0x16 :
						/* Align */
						continue;
					case	0x17 :
						/* Type */
						continue;
					case	0x18 :
						/* IsBold */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsBold += 1;
							_Context->value_IsBold &= 1;
							}
						continue;
					case	0x19 :
						/* IsUnderline */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsUnderline += 1;
							_Context->value_IsUnderline &= 1;
							}
						continue;
					case	0x1a :
						/* IsShadow */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsShadow += 1;
							_Context->value_IsShadow &= 1;
							}
						continue;
					case	0x1b :
						/* IsLock */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsLock += 1;
							_Context->value_IsLock &= 1;
							}
						continue;
					case	0x1c :
						/* IsInterface */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsInterface += 1;
							_Context->value_IsInterface &= 1;
							}
						continue;
					case	0x1d :
						/* IsSpecial */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsSpecial += 1;
							_Context->value_IsSpecial &= 1;
							}
						continue;
					case	0x1e :
						/* OnCreate */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus(_Context);
							_Context->page_number = 2;
							accept_widget_properties_show(_Context);
							}
						continue;
					case	0x1f :
						/* CreateOptions */
						continue;
					case	0x20 :
						/* Create */
						continue;
					case	0x21 :
						/* OnShowPage */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus(_Context);
							_Context->page_number = 3;
							accept_widget_properties_show(_Context);
							}
						continue;
					case	0x22 :
						/* ShowOptions */
						continue;
					case	0x23 :
						/* Show */
						continue;
					case	0x24 :
						/* OnGetFocus */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus(_Context);
							_Context->page_number = 4;
							accept_widget_properties_show(_Context);
							}
						continue;
					case	0x25 :
						/* FocusOptions */
						continue;
					case	0x26 :
						/* GetFocus */
						continue;
					case	0x27 :
						/* OnEvent */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus(_Context);
							_Context->page_number = 5;
							accept_widget_properties_show(_Context);
							}
						continue;
					case	0x28 :
						/* MimoMove */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MimoMove += 1;
							_Context->value_MimoMove &= 1;
							}
						continue;
					case	0x29 :
						/* MimoDown */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MimoDown += 1;
							_Context->value_MimoDown &= 1;
							}
						continue;
					case	0x2a :
						/* MimoUp */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MimoUp += 1;
							_Context->value_MimoUp &= 1;
							}
						continue;
					case	0x2b :
						/* MimoHold */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MimoHold += 1;
							_Context->value_MimoHold &= 1;
							}
						continue;
					case	0x2c :
						/* EventOptions */
						continue;
					case	0x2d :
						/* Event */
						continue;
					case	0x2e :
						/* OnLoseFocus */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus(_Context);
							_Context->page_number = 6;
							accept_widget_properties_show(_Context);
							}
						continue;
					case	0x2f :
						/* LoseOptions */
						continue;
					case	0x30 :
						/* LoseFocus */
						continue;
					case	0x31 :
						/* OnHidePage */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus(_Context);
							_Context->page_number = 7;
							accept_widget_properties_show(_Context);
							}
						continue;
					case	0x32 :
						/* HideOptions */
						continue;
					case	0x33 :
						/* Hide */
						continue;
					case	0x34 :
						/* OnRemove */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus(_Context);
							_Context->page_number = 8;
							accept_widget_properties_show(_Context);
							}
						continue;
					case	0x35 :
						/* RemoveOptions */
						continue;
					case	0x36 :
						/* Remove */
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
				_Context->focus_item=54;
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
	char * pAtX,
	char * pAtY,
	char * pWidth,
	char * pHeight,
	char * pTextFont,
	char * pTextColour,
	char * pBackground,
	char * pPayLoad,
	char * pIdentity,
	char * pFormat,
	char * pStyleSheet,
	char * pAuto1376,
	char * pWidgetClass,
	char * pAlign,
	char * pType,
	char * pIsBold,
	char * pIsUnderline,
	char * pIsShadow,
	char * pIsLock,
	char * pIsInterface,
	char * pIsSpecial,
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
	 pAtX,
	 pAtY,
	 pWidth,
	 pHeight,
	 pTextFont,
	 pTextColour,
	 pBackground,
	 pPayLoad,
	 pIdentity,
	 pFormat,
	 pStyleSheet,
	 pAuto1376,
	 pWidgetClass,
	 pAlign,
	 pType,
	 pIsBold,
	 pIsUnderline,
	 pIsShadow,
	 pIsLock,
	 pIsInterface,
	 pIsSpecial,
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
	 pAtX,
	 pAtY,
	 pWidth,
	 pHeight,
	 pTextFont,
	 pTextColour,
	 pBackground,
	 pPayLoad,
	 pIdentity,
	 pFormat,
	 pStyleSheet,
	 pAuto1376,
	 pWidgetClass,
	 pAlign,
	 pType,
	 pIsBold,
	 pIsUnderline,
	 pIsShadow,
	 pIsLock,
	 pIsInterface,
	 pIsSpecial,
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

#endif /* _vwidget_c */
