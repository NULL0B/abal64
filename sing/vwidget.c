
#ifndef _vwidget_c
#define _vwidget_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vwidget.sng  */
/* Target         : vwidget.c  */
/* Identification : 0.0-1065019113-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_widget_properties_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	focus_pages[8+1];
	int	page_number;
	char	buffer_AtX[8];
	char	buffer_AtY[8];
	char	buffer_Width[8];
	char	buffer_Height[8];
	int	value_TextFont;
	char	buffer_TextColour[15];
	char	buffer_Background[15];
	char	buffer_PayLoad[326];
	char	buffer_Auto4659[326];
	char	buffer_Identity[66];
	char	buffer_Auto3390[8];
	int	value_WidgetClass;
	int	value_Align;
	int	value_Type;
	int	value_IsBold;
	int	value_IsUnderline;
	int	value_IsShadow;
	int	value_IsLock;
	int	value_IsInterface;
	int	value_CreateOptions;
	char * buffer_Create;
	int	value_ShowOptions;
	char * buffer_Show;
	int	value_FocusOptions;
	char * buffer_GetFocus;
	int	value_MimoMove;
	int	value_MimoDown;
	int	value_MimoUp;
	int	value_MimoHold;
	int	value_EventOptions;
	char * buffer_Event;
	int	value_LoseOptions;
	char * buffer_LoseFocus;
	int	value_HideOptions;
	char * buffer_Hide;
	int	value_RemoveOptions;
	char * buffer_Remove;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[38];
	} * _Context;

private	int	accept_widget_properties_create(
	char * pAtX,
	char * pAtY,
	char * pWidth,
	char * pHeight,
	char * pTextFont,
	char * pTextColour,
	char * pBackground,
	char * pPayLoad,
	char * pAuto4659,
	char * pIdentity,
	char * pAuto3390,
	char * pWidgetClass,
	char * pAlign,
	char * pType,
	char * pIsBold,
	char * pIsUnderline,
	char * pIsShadow,
	char * pIsLock,
	char * pIsInterface,
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

	if (!(_Context = allocate( sizeof( struct accept_widget_properties_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=51;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWSSSWWWWWWWWWWTWTWTWWWWWTWTWTWT");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_AtX, 7, pAtX);
		visual_transferin(_Context->buffer_AtY, 7, pAtY);
		visual_transferin(_Context->buffer_Width, 7, pWidth);
		visual_transferin(_Context->buffer_Height, 7, pHeight);
		visual_transferin((void *) 0, 0, pTextFont);
		if (!( pTextFont )) _Context->value_TextFont=0;
		else	_Context->value_TextFont = *((int *)pTextFont);
		visual_transferin(_Context->buffer_TextColour, 14, pTextColour);
		visual_transferin(_Context->buffer_Background, 14, pBackground);
		visual_transferin(_Context->buffer_PayLoad, 325, pPayLoad);
		visual_transferin(_Context->buffer_Auto4659, 325, pAuto4659);
		visual_transferin(_Context->buffer_Identity, 65, pIdentity);
		visual_transferin(_Context->buffer_Auto3390, 7, pAuto3390);
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
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->focus_pages[1]=2;
	_Context->focus_pages[2]=27;
	_Context->focus_pages[3]=30;
	_Context->focus_pages[4]=33;
	_Context->focus_pages[5]=36;
	_Context->focus_pages[6]=43;
	_Context->focus_pages[7]=46;
	_Context->focus_pages[8]=49;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(45,35,710+10,530+10);
	return(0);
}
private int on_WidgetProperties_hide() {
	close_window_editor();
	return(-1);
}

private	int	accept_widget_properties_hide()
{
	(void) on_WidgetProperties_hide();
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,45,35);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_widget_properties_remove(
	char * pAtX,
	char * pAtY,
	char * pWidth,
	char * pHeight,
	char * pTextFont,
	char * pTextColour,
	char * pBackground,
	char * pPayLoad,
	char * pAuto4659,
	char * pIdentity,
	char * pAuto3390,
	char * pWidgetClass,
	char * pAlign,
	char * pType,
	char * pIsBold,
	char * pIsUnderline,
	char * pIsShadow,
	char * pIsLock,
	char * pIsInterface,
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

	int	result=_Context->keycode;
	if (_Context->keycode == 27 ) {
		filetransferdrop(_Context->buffer_Create);
		filetransferdrop(_Context->buffer_Show);
		filetransferdrop(_Context->buffer_GetFocus);
		filetransferdrop(_Context->buffer_Event);
		filetransferdrop(_Context->buffer_LoseFocus);
		filetransferdrop(_Context->buffer_Hide);
		filetransferdrop(_Context->buffer_Remove);
		
	} else {
		strcpy(_Context->signature,"WWWWWWWSSSWWWWWWWWWWTWTWTWWWWWTWTWTWT");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_AtX, 7, pAtX);
		visual_transferout(_Context->buffer_AtY, 7, pAtY);
		visual_transferout(_Context->buffer_Width, 7, pWidth);
		visual_transferout(_Context->buffer_Height, 7, pHeight);
		visual_transferout((void *) 0, 0, pTextFont);
		if ( pTextFont != (char *) 0)
			*((int*)pTextFont) = _Context->value_TextFont;
		visual_transferout(_Context->buffer_TextColour, 14, pTextColour);
		visual_transferout(_Context->buffer_Background, 14, pBackground);
		visual_transferout(_Context->buffer_PayLoad, 325, pPayLoad);
		visual_transferout(_Context->buffer_Auto4659, 325, pAuto4659);
		visual_transferout(_Context->buffer_Identity, 65, pIdentity);
		visual_transferout(_Context->buffer_Auto3390, 7, pAuto3390);
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
private int on_OnCreate_show() {
	open_window_editor(75,145,
	648,352,_Context->buffer_Create);
	return(-1);
}
private int on_Create_show() {
	show_window_editor();
	return(-1);
}
private int on_OnShow_show() {
	open_window_editor(75,145,
	648,352,_Context->buffer_Show);
	return(-1);
}
private int on_Show_show() {
	show_window_editor();
	return(-1);
}
private int on_OnGetFocus_show() {
	open_window_editor(75,145,
	648,352,_Context->buffer_GetFocus);
	return(-1);
}
private int on_GetFocus_show() {
	show_window_editor();
	return(-1);
}
private int on_OnEvent_show() {
	open_window_editor(75,145,
	648,352,_Context->buffer_Event);
	return(-1);
}
private int on_Event_show() {
	show_window_editor();
	return(-1);
}
private int on_OnLoseFocus_show() {
	open_window_editor(75,145,
	648,352,_Context->buffer_LoseFocus);
	return(-1);
}
private int on_LoseFocus_show() {
	show_window_editor();
	return(-1);
}
private int on_OnHide_show() {
	open_window_editor(77,142,
	648,352,_Context->buffer_Hide);
	return(-1);
}
private int on_Hide_show() {
	show_window_editor();
	return(-1);
}
private int on_OnRemove_show() {
	open_window_editor(77,142,
	648,352,_Context->buffer_Remove);
	return(-1);
}
private int on_Remove_show() {
	show_window_editor();
	return(-1);
}

private	int	accept_widget_properties_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,45,35);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(45,35,710,530,2,"Sing : Version 1.0a : Widget Properties",39,0x403);
	visual_image(48,56,703,505,"skin.gif",4);
	visual_filzone(75,85,650,30,18,12);
	visual_filzone(75,105,670,410,18,12);
	visual_filzone(75,525,110,30,18,12);
	visual_filzone(385,525,110,30,18,12);
	visual_filzone(635,525,110,30,18,12);
	if (_Context->page_number == 1 ) {
	visual_tabpage(65,75,670,430,2,"&Widget",7,0,2);
	} else {
		visual_tabpage(65,75,670,430,2,"&Widget",7,0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(95,125,70,16,2,27,0,"Position",8,1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(335,125,100,20,2,27,0,"Dimensions",10,1282);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(175,125,56+2,16+2,5);
	visual_text(175+1,125+1,56,16,1,34,0,_Context->buffer_AtX,7,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(235,125,10,20,1,34,0,",",1,2);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(245,125,56+2,16+2,5);
	visual_text(245+1,125+1,56,16,1,34,0,_Context->buffer_AtY,7,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(495,125,10,20,1,34,0,",",1,2);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(435,125,56+2,16+2,5);
	visual_text(435+1,125+1,56,16,1,34,0,_Context->buffer_Width,7,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(505,125,56+2,16+2,5);
	visual_text(505+1,125+1,56,16,1,34,0,_Context->buffer_Height,7,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(95,155,70,16,2,27,0,"Text Font",9,1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(95,185,70,16,2,27,0,"Colour",6,1282);
		}
	if (_Context->page_number == 1 ) {
	visual_select(175,155,130,100,1,34,0,parse_selection(TextFontList,&_Context->value_TextFont),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(175,185,112+2,16+2,5);
	visual_text(175+1,185+1,112,16,1,34,0,_Context->buffer_TextColour,14,0);
		}
	if (_Context->page_number == 1 ) {
	visual_button(285,185,20,16,8,28,28,"fg",2,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(335,185,100,20,2,27,0,"Background",10,1282);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(435,185,112+2,16+2,5);
	visual_text(435+1,185+1,112,16,1,34,0,_Context->buffer_Background,14,0);
		}
	if (_Context->page_number == 1 ) {
	visual_button(545,185,20,16,8,28,28,"bg",2,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(95,215,74,16,2,27,0,"Payload",7,1282);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(175,215,520+2,80+2,5);
	visual_text(175+1,215+1,520,80,1,34,0,_Context->buffer_PayLoad,325,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(175,365,520+2,80+2,5);
	visual_text(175+1,365+1,520,80,1,27,0,_Context->buffer_Auto4659,325,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(95,305,76,17,2,27,0,"Identity",8,1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(95,465,75,16,2,27,0,"Hotkey",6,1282);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(175,305,520+2,16+2,5);
	visual_text(175+1,305+1,520,16,1,34,0,_Context->buffer_Identity,65,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(175,465,56+2,16+2,5);
	visual_text(175+1,465+1,56,16,1,27,0,_Context->buffer_Auto3390,7,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(95,335,84,16,2,27,0,"Class",5,1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(95,365,78,21,2,27,0,WidgetMessage(_Context->value_WidgetClass,0),strlen(WidgetMessage(_Context->value_WidgetClass,0)),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_text(335,335,98,16,2,27,0,"Storage Type",12,1282);
		}
	if (_Context->page_number == 1 ) {
	visual_select(175,335,128,80,1,0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),0);
		}
	visual_button(65,515,110,30,2,34,0,"&Accept",7,0);
	visual_button(375,515,112,32,2,28,28,"&Full Screen",12,0);
	visual_button(625,515,110,30,2,34,0,"&Cancel",7,0);
	if (_Context->page_number == 1 ) {
	visual_text(335,155,100,20,2,27,0,"Options",7,1282);
		}
	if (_Context->page_number == 1 ) {
	visual_select(435,155,130,100,1,0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(435,335,216,80,1,0,0,parse_selection(WidgetTypeList,&_Context->value_Type),0);
		}
	if (_Context->page_number == 1 ) {
	visual_check(585,125,112,16,2,175,0,WidgetMessage(_Context->value_WidgetClass,1),strlen(WidgetMessage(_Context->value_WidgetClass,1)),_Context->value_IsBold|0);
		}
	if (_Context->page_number == 1 ) {
	visual_check(585,155,112,16,2,175,0,WidgetMessage(_Context->value_WidgetClass,2),strlen(WidgetMessage(_Context->value_WidgetClass,2)),_Context->value_IsUnderline|0);
		}
	if (_Context->page_number == 1 ) {
	visual_check(585,185,116,15,2,28,28,WidgetMessage(_Context->value_WidgetClass,3),strlen(WidgetMessage(_Context->value_WidgetClass,3)),_Context->value_IsShadow|0);
		}
	if (_Context->page_number == 1 ) {
	visual_check(375,465,122,16,2,27,0,"L&ocked",7,_Context->value_IsLock|0);
		}
	if (_Context->page_number == 1 ) {
	visual_check(533,465,163,16,2,28,28,"Interface Item",14,_Context->value_IsInterface|0);
		}
	if (_Context->page_number == 2 ) {
	visual_tabpage(65,75,670,430,2,"C&reate",7,81,2);
		(void) on_OnCreate_show();
	} else {
		visual_tabpage(65,75,670,430,2,"C&reate",7,81,0);
		}
	if (_Context->page_number == 2 ) {
	visual_select(545,115,180,70,1,27,0,parse_selection(WidgetSizesOptions,&_Context->value_CreateOptions),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(75,145,648+2,352+2,5);
	(void) on_Create_show();
		}
	if (_Context->page_number == 3 ) {
	visual_tabpage(65,75,670,430,2,"&Show",5,159,2);
		(void) on_OnShow_show();
	} else {
		visual_tabpage(65,75,670,430,2,"&Show",5,159,0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(545,115,180,70,1,27,0,parse_selection(WidgetShowOptions,&_Context->value_ShowOptions),0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(75,145,648+2,352+2,5);
	(void) on_Show_show();
		}
	if (_Context->page_number == 4 ) {
	visual_tabpage(65,75,670,430,2,"&GetFocus",9,231,2);
		(void) on_OnGetFocus_show();
	} else {
		visual_tabpage(65,75,670,430,2,"&GetFocus",9,231,0);
		}
	if (_Context->page_number == 4 ) {
	visual_select(545,115,180,70,1,27,0,parse_selection(WidgetFocusOptions,&_Context->value_FocusOptions),0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(75,145,648+2,352+2,5);
	(void) on_GetFocus_show();
		}
	if (_Context->page_number == 5 ) {
	visual_tabpage(65,75,670,430,2,"&Event",6,327,2);
		(void) on_OnEvent_show();
	} else {
		visual_tabpage(65,75,670,430,2,"&Event",6,327,0);
		}
	if (_Context->page_number == 5 ) {
	visual_text(85,115,168,16,2,27,0,"Invoke Method On Mouse ...",26,1025);
		}
	if (_Context->page_number == 5 ) {
	visual_switch(275,115,40,16,1,25,26,"MOVE",4,_Context->value_MimoMove);
		}
	if (_Context->page_number == 5 ) {
	visual_switch(325,115,42,16,1,25,26,"DOWN",4,_Context->value_MimoDown);
		}
	if (_Context->page_number == 5 ) {
	visual_switch(375,115,24,16,1,25,26,"UP",2,_Context->value_MimoUp);
		}
	if (_Context->page_number == 5 ) {
	visual_switch(405,115,40,16,1,25,26,"HOLD",4,_Context->value_MimoHold);
		}
	if (_Context->page_number == 5 ) {
	visual_select(545,115,180,70,1,27,0,parse_selection(WidgetEventOptions,&_Context->value_EventOptions),0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(75,145,648+2,352+2,5);
	(void) on_Event_show();
		}
	if (_Context->page_number == 6 ) {
	visual_tabpage(65,75,670,430,2,"&LoseFocus",10,400,2);
		(void) on_OnLoseFocus_show();
	} else {
		visual_tabpage(65,75,670,430,2,"&LoseFocus",10,400,0);
		}
	if (_Context->page_number == 6 ) {
	visual_select(545,115,180,70,1,27,0,parse_selection(WidgetEventOptions,&_Context->value_LoseOptions),0);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(75,145,648+2,352+2,5);
	(void) on_LoseFocus_show();
		}
	if (_Context->page_number == 7 ) {
	visual_tabpage(65,75,670,430,2,"&Hide",5,503,2);
		(void) on_OnHide_show();
	} else {
		visual_tabpage(65,75,670,430,2,"&Hide",5,503,0);
		}
	if (_Context->page_number == 7 ) {
	visual_select(545,115,180,70,1,27,0,parse_selection(WidgetHideOptions,&_Context->value_HideOptions),0);
		}
	if (_Context->page_number == 7 ) {
	visual_frame(77,142,648+2,352+2,5);
	(void) on_Hide_show();
		}
	if (_Context->page_number == 8 ) {
	visual_tabpage(65,75,670,430,2,"Re&move",7,567,2);
		(void) on_OnRemove_show();
	} else {
		visual_tabpage(65,75,670,430,2,"Re&move",7,567,0);
		}
	if (_Context->page_number == 8 ) {
	visual_select(545,115,180,70,1,27,0,parse_selection(WidgetEventOptions,&_Context->value_RemoveOptions),0);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(77,142,648+2,352+2,5);
	(void) on_Remove_show();
		}
	visual_thaw(45,35,710,530);

	return(0);
}
private int on_Auto396_event() {
	sprintf(_Context->buffer_TextColour,"%u",get_foreground());
	accept_widget_properties_show();
	return(-1);
}
private int on_Auto398_event() {
	sprintf(_Context->buffer_Background,"%u",get_background());
	accept_widget_properties_show();
	return(-1);
}
private int on_Ok_event() {
	return(13);
	return(-1);
}
private int on_FullScreen_event() {
	accept_widget_properties_hide();
	switch(_Context->page_number){
	case 2:
	use_editor(_Context->buffer_Create);
	accept_widget_properties_show();
	visual_frame(75,145,648+2,352+2,5);
;
		/* Create */
	/* OnCreate */
	accept_widget_properties_losefocus();
	_Context->page_number = 2;
	accept_widget_properties_show();
	_Context->focus_item=27;
	accept_widget_properties_show();
	_Context->focus_item=29;
;
	break;
	case 3:
	use_editor(_Context->buffer_Show);
	accept_widget_properties_show();
	visual_frame(75,145,648+2,352+2,5);
;
		/* Show */
	/* OnShow */
	accept_widget_properties_losefocus();
	_Context->page_number = 3;
	accept_widget_properties_show();
	_Context->focus_item=30;
	accept_widget_properties_show();
	_Context->focus_item=32;
;
	break;
	case 4:
	use_editor(_Context->buffer_GetFocus);
	accept_widget_properties_show();
	visual_frame(75,145,648+2,352+2,5);
;
		/* GetFocus */
	/* OnGetFocus */
	accept_widget_properties_losefocus();
	_Context->page_number = 4;
	accept_widget_properties_show();
	_Context->focus_item=33;
	accept_widget_properties_show();
	_Context->focus_item=35;
;
	break;
	case 5:
	use_editor(_Context->buffer_Event);
	accept_widget_properties_show();
	visual_frame(75,145,648+2,352+2,5);
;
		/* Event */
	/* OnEvent */
	accept_widget_properties_losefocus();
	_Context->page_number = 5;
	accept_widget_properties_show();
	_Context->focus_item=36;
	accept_widget_properties_show();
	_Context->focus_item=42;
;
	break;
	case 6:
	use_editor(_Context->buffer_LoseFocus);
	accept_widget_properties_show();
	visual_frame(75,145,648+2,352+2,5);
;
		/* LoseFocus */
	/* OnLoseFocus */
	accept_widget_properties_losefocus();
	_Context->page_number = 6;
	accept_widget_properties_show();
	_Context->focus_item=43;
	accept_widget_properties_show();
	_Context->focus_item=45;
;
	break;
	case 7:
	use_editor(_Context->buffer_Hide);
	accept_widget_properties_show();
	visual_frame(77,142,648+2,352+2,5);
;
		/* Hide */
	/* OnHide */
	accept_widget_properties_losefocus();
	_Context->page_number = 7;
	accept_widget_properties_show();
	_Context->focus_item=46;
	accept_widget_properties_show();
	_Context->focus_item=48;
;
	break;
	case 8:
	use_editor(_Context->buffer_Remove);
	accept_widget_properties_show();
	visual_frame(77,142,648+2,352+2,5);
;
		/* Remove */
	/* OnRemove */
	accept_widget_properties_losefocus();
	_Context->page_number = 8;
	accept_widget_properties_show();
	_Context->focus_item=49;
	accept_widget_properties_show();
	_Context->focus_item=51;
;
	break;
	default:
	accept_widget_properties_show();
		/* Widget */
	accept_widget_properties_losefocus();
	_Context->page_number = 1;
	accept_widget_properties_show();
	_Context->focus_item=2;
;
	}
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}


private	int	accept_widget_properties_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x1031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 734 )  
	&&  (my >= 39 )  
	&&  (mx <= 750 )  
	&&  (my <= 55 )) {
		return(1);	/* WidgetProperties */

		}
	if ((mx >= 718 )  
	&&  (my >= 39 )  
	&&  (mx <= 734 )  
	&&  (my <= 55 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vwidget.htm");
			};
		return(-1);	/* WidgetProperties */

		}
	if (_Context->page_number == 1 ) {
	} else {
		if ((mx >= 65 ) 
		&&  (my >= 75 ) 
		&&  (mx <= 145 ) 
		&&  (my <= 99 )) {
			return(2); /* Widget */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 175 ) 
		&&  ( my >= 125 ) 
		&&  ( mx <= 231 ) 
		&&  ( my <= 141 )) {
			return(3); /* AtX */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 245 ) 
		&&  ( my >= 125 ) 
		&&  ( mx <= 301 ) 
		&&  ( my <= 141 )) {
			return(4); /* AtY */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 435 ) 
		&&  ( my >= 125 ) 
		&&  ( mx <= 491 ) 
		&&  ( my <= 141 )) {
			return(5); /* Width */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 505 ) 
		&&  ( my >= 125 ) 
		&&  ( mx <= 561 ) 
		&&  ( my <= 141 )) {
			return(6); /* Height */
		}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 175 ) 
		&&  (my >= 155 ) 
		&&  (mx <= 305 ) 
		&&  (my <= 171 )) {
			return(7); /* TextFont */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 175 ) 
		&&  ( my >= 185 ) 
		&&  ( mx <= 287 ) 
		&&  ( my <= 201 )) {
			return(8); /* TextColour */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 285 ) 
		&&  ( my >= 185 ) 
		&&  ( mx <= 305 ) 
		&&  ( my <= 201 )) {
			return(9); /* Auto396 */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 435 ) 
		&&  ( my >= 185 ) 
		&&  ( mx <= 547 ) 
		&&  ( my <= 201 )) {
			return(10); /* Background */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 545 ) 
		&&  ( my >= 185 ) 
		&&  ( mx <= 565 ) 
		&&  ( my <= 201 )) {
			return(11); /* Auto398 */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 175 ) 
		&&  ( my >= 215 ) 
		&&  ( mx <= 695 ) 
		&&  ( my <= 295 )) {
			return(12); /* PayLoad */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 175 ) 
		&&  ( my >= 365 ) 
		&&  ( mx <= 695 ) 
		&&  ( my <= 445 )) {
			return(13); /* Auto4659 */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 175 ) 
		&&  ( my >= 305 ) 
		&&  ( mx <= 695 ) 
		&&  ( my <= 321 )) {
			return(14); /* Identity */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 175 ) 
		&&  ( my >= 465 ) 
		&&  ( mx <= 231 ) 
		&&  ( my <= 481 )) {
			return(15); /* Auto3390 */
		}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 175 ) 
		&&  (my >= 335 ) 
		&&  (mx <= 303 ) 
		&&  (my <= 351 )) {
			return(16); /* WidgetClass */
		}
		}
	if (( mx >= 65 ) 
	&&  ( my >= 515 ) 
	&&  ( mx <= 175 ) 
	&&  ( my <= 545 )) {
		return(17); /* Ok */
		}
	if (( mx >= 375 ) 
	&&  ( my >= 515 ) 
	&&  ( mx <= 487 ) 
	&&  ( my <= 547 )) {
		return(18); /* FullScreen */
		}
	if (( mx >= 625 ) 
	&&  ( my >= 515 ) 
	&&  ( mx <= 735 ) 
	&&  ( my <= 545 )) {
		return(19); /* Cancel */
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 435 ) 
		&&  (my >= 155 ) 
		&&  (mx <= 565 ) 
		&&  (my <= 171 )) {
			return(20); /* Align */
		}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 435 ) 
		&&  (my >= 335 ) 
		&&  (mx <= 651 ) 
		&&  (my <= 351 )) {
			return(21); /* Type */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 585 ) 
		&&  ( my >= 125 ) 
		&&  ( mx <= 697 ) 
		&&  ( my <= 141 )) {
			return(22); /* IsBold */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 585 ) 
		&&  ( my >= 155 ) 
		&&  ( mx <= 697 ) 
		&&  ( my <= 171 )) {
			return(23); /* IsUnderline */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 585 ) 
		&&  ( my >= 185 ) 
		&&  ( mx <= 701 ) 
		&&  ( my <= 200 )) {
			return(24); /* IsShadow */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 375 ) 
		&&  ( my >= 465 ) 
		&&  ( mx <= 497 ) 
		&&  ( my <= 481 )) {
			return(25); /* IsLock */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 533 ) 
		&&  ( my >= 465 ) 
		&&  ( mx <= 696 ) 
		&&  ( my <= 481 )) {
			return(26); /* IsInterface */
		}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if ((mx >= 146 ) 
		&&  (my >= 75 ) 
		&&  (mx <= 223 ) 
		&&  (my <= 99 )) {
			return(27); /* OnCreate */
		}
		}
	if (_Context->page_number == 2 ) {
		if ((mx >= 545 ) 
		&&  (my >= 115 ) 
		&&  (mx <= 725 ) 
		&&  (my <= 131 )) {
			return(28); /* CreateOptions */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 75 ) 
		&&  ( my >= 145 ) 
		&&  ( mx <= 723 ) 
		&&  ( my <= 497 )) {
			return(29); /* Create */
		}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if ((mx >= 224 ) 
		&&  (my >= 75 ) 
		&&  (mx <= 295 ) 
		&&  (my <= 99 )) {
			return(30); /* OnShow */
		}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 545 ) 
		&&  (my >= 115 ) 
		&&  (mx <= 725 ) 
		&&  (my <= 131 )) {
			return(31); /* ShowOptions */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 75 ) 
		&&  ( my >= 145 ) 
		&&  ( mx <= 723 ) 
		&&  ( my <= 497 )) {
			return(32); /* Show */
		}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if ((mx >= 296 ) 
		&&  (my >= 75 ) 
		&&  (mx <= 391 ) 
		&&  (my <= 99 )) {
			return(33); /* OnGetFocus */
		}
		}
	if (_Context->page_number == 4 ) {
		if ((mx >= 545 ) 
		&&  (my >= 115 ) 
		&&  (mx <= 725 ) 
		&&  (my <= 131 )) {
			return(34); /* FocusOptions */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 75 ) 
		&&  ( my >= 145 ) 
		&&  ( mx <= 723 ) 
		&&  ( my <= 497 )) {
			return(35); /* GetFocus */
		}
		}
	if (_Context->page_number == 5 ) {
	} else {
		if ((mx >= 392 ) 
		&&  (my >= 75 ) 
		&&  (mx <= 464 ) 
		&&  (my <= 99 )) {
			return(36); /* OnEvent */
		}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= 275 ) 
		&&  ( my >= 115 ) 
		&&  ( mx <= 315 ) 
		&&  ( my <= 131 )) {
			return(37); /* MimoMove */
		}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= 325 ) 
		&&  ( my >= 115 ) 
		&&  ( mx <= 367 ) 
		&&  ( my <= 131 )) {
			return(38); /* MimoDown */
		}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= 375 ) 
		&&  ( my >= 115 ) 
		&&  ( mx <= 399 ) 
		&&  ( my <= 131 )) {
			return(39); /* MimoUp */
		}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= 405 ) 
		&&  ( my >= 115 ) 
		&&  ( mx <= 445 ) 
		&&  ( my <= 131 )) {
			return(40); /* MimoHold */
		}
		}
	if (_Context->page_number == 5 ) {
		if ((mx >= 545 ) 
		&&  (my >= 115 ) 
		&&  (mx <= 725 ) 
		&&  (my <= 131 )) {
			return(41); /* EventOptions */
		}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= 75 ) 
		&&  ( my >= 145 ) 
		&&  ( mx <= 723 ) 
		&&  ( my <= 497 )) {
			return(42); /* Event */
		}
		}
	if (_Context->page_number == 6 ) {
	} else {
		if ((mx >= 465 ) 
		&&  (my >= 75 ) 
		&&  (mx <= 567 ) 
		&&  (my <= 99 )) {
			return(43); /* OnLoseFocus */
		}
		}
	if (_Context->page_number == 6 ) {
		if ((mx >= 545 ) 
		&&  (my >= 115 ) 
		&&  (mx <= 725 ) 
		&&  (my <= 131 )) {
			return(44); /* LoseOptions */
		}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= 75 ) 
		&&  ( my >= 145 ) 
		&&  ( mx <= 723 ) 
		&&  ( my <= 497 )) {
			return(45); /* LoseFocus */
		}
		}
	if (_Context->page_number == 7 ) {
	} else {
		if ((mx >= 568 ) 
		&&  (my >= 75 ) 
		&&  (mx <= 631 ) 
		&&  (my <= 99 )) {
			return(46); /* OnHide */
		}
		}
	if (_Context->page_number == 7 ) {
		if ((mx >= 545 ) 
		&&  (my >= 115 ) 
		&&  (mx <= 725 ) 
		&&  (my <= 131 )) {
			return(47); /* HideOptions */
		}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= 77 ) 
		&&  ( my >= 142 ) 
		&&  ( mx <= 725 ) 
		&&  ( my <= 494 )) {
			return(48); /* Hide */
		}
		}
	if (_Context->page_number == 8 ) {
	} else {
		if ((mx >= 632 ) 
		&&  (my >= 75 ) 
		&&  (mx <= 717 ) 
		&&  (my <= 99 )) {
			return(49); /* OnRemove */
		}
		}
	if (_Context->page_number == 8 ) {
		if ((mx >= 545 ) 
		&&  (my >= 115 ) 
		&&  (mx <= 725 ) 
		&&  (my <= 131 )) {
			return(50); /* RemoveOptions */
		}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= 77 ) 
		&&  ( my >= 142 ) 
		&&  ( mx <= 725 ) 
		&&  ( my <= 494 )) {
			return(51); /* Remove */
		}
		}

	return(-1);
}


private	int	accept_widget_properties_losefocus()
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
private int on_Create_getfocus() {
	return(focus_window_editor());
	return(-1);
}
private int on_Show_getfocus() {
	return(focus_window_editor());
	return(-1);
}
private int on_GetFocus_getfocus() {
	return(focus_window_editor());
	return(-1);
}
private int on_Event_getfocus() {
	return(focus_window_editor());
	return(-1);
}
private int on_LoseFocus_getfocus() {
	return(focus_window_editor());
	return(-1);
}
private int on_Hide_getfocus() {
	return(focus_window_editor());
	return(-1);
}
private int on_Remove_getfocus() {
	return(focus_window_editor());
	return(-1);
}


private	int	accept_widget_properties_focus()
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
					_Context->keycode = visual_edit(175+1,125+1,56,16,1,_Context->buffer_AtX,7);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* AtY */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(245+1,125+1,56,16,1,_Context->buffer_AtY,7);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* Width */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(435+1,125+1,56,16,1,_Context->buffer_Width,7);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* Height */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(505+1,125+1,56,16,1,_Context->buffer_Height,7);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* TextFont */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(175,155,130,100,1,34,0,parse_selection(TextFontList,&_Context->value_TextFont),2);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* TextColour */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(175+1,185+1,112,16,1,_Context->buffer_TextColour,14);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* Auto396 */
				if (_Context->page_number == 1 ) {
					visual_button(285,185,20,16,8,28,28,"fg",2,2);
					_Context->keycode = visual_getch();
					visual_button(285,185,20,16,8,28,28,"fg",2,0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* Background */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(435+1,185+1,112,16,1,_Context->buffer_Background,14);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* Auto398 */
				if (_Context->page_number == 1 ) {
					visual_button(545,185,20,16,8,28,28,"bg",2,2);
					_Context->keycode = visual_getch();
					visual_button(545,185,20,16,8,28,28,"bg",2,0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* PayLoad */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(175+1,215+1,520,80,1,_Context->buffer_PayLoad,325);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* Auto4659 */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(175+1,365+1,520,80,1,_Context->buffer_Auto4659,325);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* Identity */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(175+1,305+1,520,16,1,_Context->buffer_Identity,65);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* Auto3390 */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(175+1,465+1,56,16,1,_Context->buffer_Auto3390,7);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* WidgetClass */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(175,335,128,80,1,0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),2);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* Align */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(435,155,130,100,1,0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),2);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x15 :
				/* Type */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(435,335,216,80,1,0,0,parse_selection(WidgetTypeList,&_Context->value_Type),2);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* IsBold */
				if (_Context->page_number == 1 ) {
				visual_check(585,125,112,16,2,175,0,WidgetMessage(_Context->value_WidgetClass,1),strlen(WidgetMessage(_Context->value_WidgetClass,1)),(_Context->value_IsBold |2));
					_Context->keycode = visual_getch();
				visual_check(585,125,112,16,2,175,0,WidgetMessage(_Context->value_WidgetClass,1),strlen(WidgetMessage(_Context->value_WidgetClass,1)),(_Context->value_IsBold |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x17 :
				/* IsUnderline */
				if (_Context->page_number == 1 ) {
				visual_check(585,155,112,16,2,175,0,WidgetMessage(_Context->value_WidgetClass,2),strlen(WidgetMessage(_Context->value_WidgetClass,2)),(_Context->value_IsUnderline |2));
					_Context->keycode = visual_getch();
				visual_check(585,155,112,16,2,175,0,WidgetMessage(_Context->value_WidgetClass,2),strlen(WidgetMessage(_Context->value_WidgetClass,2)),(_Context->value_IsUnderline |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x18 :
				/* IsShadow */
				if (_Context->page_number == 1 ) {
				visual_check(585,185,116,15,2,28,28,WidgetMessage(_Context->value_WidgetClass,3),strlen(WidgetMessage(_Context->value_WidgetClass,3)),(_Context->value_IsShadow |2));
					_Context->keycode = visual_getch();
				visual_check(585,185,116,15,2,28,28,WidgetMessage(_Context->value_WidgetClass,3),strlen(WidgetMessage(_Context->value_WidgetClass,3)),(_Context->value_IsShadow |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* IsLock */
				if (_Context->page_number == 1 ) {
				visual_check(375,465,122,16,2,27,0,"L&ocked",7,(_Context->value_IsLock |2));
					_Context->keycode = visual_getch();
				visual_check(375,465,122,16,2,27,0,"L&ocked",7,(_Context->value_IsLock |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* IsInterface */
				if (_Context->page_number == 1 ) {
				visual_check(533,465,163,16,2,28,28,"Interface Item",14,(_Context->value_IsInterface |2));
					_Context->keycode = visual_getch();
				visual_check(533,465,163,16,2,28,28,"Interface Item",14,(_Context->value_IsInterface |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* OnCreate */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x1c :
				/* CreateOptions */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_select(545,115,180,70,1,27,0,parse_selection(WidgetSizesOptions,&_Context->value_CreateOptions),2);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1d :
				/* Create */
				if (_Context->page_number == 2 ) {
					if ((_Context->keycode = on_Create_getfocus()) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* OnShow */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x1f :
				/* ShowOptions */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(545,115,180,70,1,27,0,parse_selection(WidgetShowOptions,&_Context->value_ShowOptions),2);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x20 :
				/* Show */
				if (_Context->page_number == 3 ) {
					if ((_Context->keycode = on_Show_getfocus()) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x21 :
				/* OnGetFocus */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x22 :
				/* FocusOptions */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_select(545,115,180,70,1,27,0,parse_selection(WidgetFocusOptions,&_Context->value_FocusOptions),2);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x23 :
				/* GetFocus */
				if (_Context->page_number == 4 ) {
					if ((_Context->keycode = on_GetFocus_getfocus()) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x24 :
				/* OnEvent */
				if (_Context->page_number == 5 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x25 :
				/* MimoMove */
				if (_Context->page_number == 5 ) {
				visual_switch(275,115,40,16,1,25,26,"MOVE",4,(_Context->value_MimoMove |2));
					_Context->keycode = visual_getch();
				visual_switch(275,115,40,16,1,25,26,"MOVE",4,(_Context->value_MimoMove |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x26 :
				/* MimoDown */
				if (_Context->page_number == 5 ) {
				visual_switch(325,115,42,16,1,25,26,"DOWN",4,(_Context->value_MimoDown |2));
					_Context->keycode = visual_getch();
				visual_switch(325,115,42,16,1,25,26,"DOWN",4,(_Context->value_MimoDown |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x27 :
				/* MimoUp */
				if (_Context->page_number == 5 ) {
				visual_switch(375,115,24,16,1,25,26,"UP",2,(_Context->value_MimoUp |2));
					_Context->keycode = visual_getch();
				visual_switch(375,115,24,16,1,25,26,"UP",2,(_Context->value_MimoUp |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x28 :
				/* MimoHold */
				if (_Context->page_number == 5 ) {
				visual_switch(405,115,40,16,1,25,26,"HOLD",4,(_Context->value_MimoHold |2));
					_Context->keycode = visual_getch();
				visual_switch(405,115,40,16,1,25,26,"HOLD",4,(_Context->value_MimoHold |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x29 :
				/* EventOptions */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_select(545,115,180,70,1,27,0,parse_selection(WidgetEventOptions,&_Context->value_EventOptions),2);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2a :
				/* Event */
				if (_Context->page_number == 5 ) {
					if ((_Context->keycode = on_Event_getfocus()) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2b :
				/* OnLoseFocus */
				if (_Context->page_number == 6 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x2c :
				/* LoseOptions */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_select(545,115,180,70,1,27,0,parse_selection(WidgetEventOptions,&_Context->value_LoseOptions),2);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2d :
				/* LoseFocus */
				if (_Context->page_number == 6 ) {
					if ((_Context->keycode = on_LoseFocus_getfocus()) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2e :
				/* OnHide */
				if (_Context->page_number == 7 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x2f :
				/* HideOptions */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(545,115,180,70,1,27,0,parse_selection(WidgetHideOptions,&_Context->value_HideOptions),2);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x30 :
				/* Hide */
				if (_Context->page_number == 7 ) {
					if ((_Context->keycode = on_Hide_getfocus()) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x31 :
				/* OnRemove */
				if (_Context->page_number == 8 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x32 :
				/* RemoveOptions */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_select(545,115,180,70,1,27,0,parse_selection(WidgetEventOptions,&_Context->value_RemoveOptions),2);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x33 :
				/* Remove */
				if (_Context->page_number == 8 ) {
					if ((_Context->keycode = on_Remove_getfocus()) != -1) break;
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
			accept_widget_properties_losefocus();
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_widget_properties_show();
			continue;
		case	0x2 :
			accept_widget_properties_losefocus();
			_Context->page_number=8;
			_Context->focus_item=51;
			accept_widget_properties_show();
			continue;
		case	0x3 :
			accept_widget_properties_losefocus();
			if ( _Context->page_number < 8 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_widget_properties_show();
			continue;
		case	0x12 :
			accept_widget_properties_losefocus();
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_widget_properties_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_widget_properties_event()) == -1)
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
							accept_widget_properties_losefocus();
							_Context->page_number = 1;
							accept_widget_properties_show();
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
						/* Auto396 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(285,185,20,16,8,28,28,"fg",2,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(285,185,20,16,8,28,28,"fg",2,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto396_event()) != -1) break;

							}
						continue;
					case	0xa :
						/* Background */
						continue;
					case	0xb :
						/* Auto398 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(545,185,20,16,8,28,28,"bg",2,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(545,185,20,16,8,28,28,"bg",2,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto398_event()) != -1) break;

							}
						continue;
					case	0xc :
						/* PayLoad */
						continue;
					case	0xd :
						/* Auto4659 */
						continue;
					case	0xe :
						/* Identity */
						continue;
					case	0xf :
						/* Auto3390 */
						continue;
					case	0x10 :
						/* WidgetClass */
						continue;
					case	0x11 :
						/* Ok */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(65,515,110,30,2,34,0,"&Accept",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(65,515,110,30,2,34,0,"&Accept",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Ok_event()) != -1) break;

							}
						continue;
					case	0x12 :
						/* FullScreen */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(375,515,112,32,2,28,28,"&Full Screen",12,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(375,515,112,32,2,28,28,"&Full Screen",12,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_FullScreen_event()) != -1) break;

							}
						continue;
					case	0x13 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(625,515,110,30,2,34,0,"&Cancel",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(625,515,110,30,2,34,0,"&Cancel",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

							}
						continue;
					case	0x14 :
						/* Align */
						continue;
					case	0x15 :
						/* Type */
						continue;
					case	0x16 :
						/* IsBold */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsBold += 1;
							_Context->value_IsBold &= 1;
							}
						continue;
					case	0x17 :
						/* IsUnderline */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsUnderline += 1;
							_Context->value_IsUnderline &= 1;
							}
						continue;
					case	0x18 :
						/* IsShadow */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsShadow += 1;
							_Context->value_IsShadow &= 1;
							}
						continue;
					case	0x19 :
						/* IsLock */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsLock += 1;
							_Context->value_IsLock &= 1;
							}
						continue;
					case	0x1a :
						/* IsInterface */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsInterface += 1;
							_Context->value_IsInterface &= 1;
							}
						continue;
					case	0x1b :
						/* OnCreate */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus();
							_Context->page_number = 2;
							accept_widget_properties_show();
							}
						continue;
					case	0x1c :
						/* CreateOptions */
						continue;
					case	0x1d :
						/* Create */
						continue;
					case	0x1e :
						/* OnShow */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus();
							_Context->page_number = 3;
							accept_widget_properties_show();
							}
						continue;
					case	0x1f :
						/* ShowOptions */
						continue;
					case	0x20 :
						/* Show */
						continue;
					case	0x21 :
						/* OnGetFocus */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus();
							_Context->page_number = 4;
							accept_widget_properties_show();
							}
						continue;
					case	0x22 :
						/* FocusOptions */
						continue;
					case	0x23 :
						/* GetFocus */
						continue;
					case	0x24 :
						/* OnEvent */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus();
							_Context->page_number = 5;
							accept_widget_properties_show();
							}
						continue;
					case	0x25 :
						/* MimoMove */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MimoMove += 1;
							_Context->value_MimoMove &= 1;
							}
						continue;
					case	0x26 :
						/* MimoDown */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MimoDown += 1;
							_Context->value_MimoDown &= 1;
							}
						continue;
					case	0x27 :
						/* MimoUp */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MimoUp += 1;
							_Context->value_MimoUp &= 1;
							}
						continue;
					case	0x28 :
						/* MimoHold */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_MimoHold += 1;
							_Context->value_MimoHold &= 1;
							}
						continue;
					case	0x29 :
						/* EventOptions */
						continue;
					case	0x2a :
						/* Event */
						continue;
					case	0x2b :
						/* OnLoseFocus */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus();
							_Context->page_number = 6;
							accept_widget_properties_show();
							}
						continue;
					case	0x2c :
						/* LoseOptions */
						continue;
					case	0x2d :
						/* LoseFocus */
						continue;
					case	0x2e :
						/* OnHide */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus();
							_Context->page_number = 7;
							accept_widget_properties_show();
							}
						continue;
					case	0x2f :
						/* HideOptions */
						continue;
					case	0x30 :
						/* Hide */
						continue;
					case	0x31 :
						/* OnRemove */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_widget_properties_losefocus();
							_Context->page_number = 8;
							accept_widget_properties_show();
							}
						continue;
					case	0x32 :
						/* RemoveOptions */
						continue;
					case	0x33 :
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
				_Context->focus_item=51;
			}
			continue;
		case 0x877 : 
		case 0x857 : 
			/* Widget */
						accept_widget_properties_losefocus();
			_Context->page_number = 1;
			accept_widget_properties_show();
			_Context->focus_item=2;
			continue;
			continue;
		case 0x861 : 
		case 0x841 : 
			/* Ok */
			visual_button(65,515,110,30,2,34,0,"&Accept",7,8);
			visual_button(65,515,110,30,2,34,0,"&Accept",7,0);
			_Context->focus_item=17;
			if ((_Context->keycode = on_Ok_event()) != -1) break;
			continue;
			continue;
		case 0x866 : 
		case 0x846 : 
			/* FullScreen */
			visual_button(375,515,112,32,2,28,28,"&Full Screen",12,8);
			visual_button(375,515,112,32,2,28,28,"&Full Screen",12,0);
			_Context->focus_item=18;
			if ((_Context->keycode = on_FullScreen_event()) != -1) break;
			continue;
			continue;
		case 0x863 : 
		case 0x843 : 
			/* Cancel */
			visual_button(625,515,110,30,2,34,0,"&Cancel",7,8);
			visual_button(625,515,110,30,2,34,0,"&Cancel",7,0);
			_Context->focus_item=19;
			if ((_Context->keycode = on_Cancel_event()) != -1) break;
			continue;
			continue;
		case 0x86f : 
		case 0x84f : 
			if (_Context->page_number == 1) {
				/* IsLock */
				_Context->value_IsLock += 1;
				_Context->value_IsLock &= 1;
				_Context->focus_item=25;
				continue;
				}
			continue;
		case 0x872 : 
		case 0x852 : 
			/* OnCreate */
						accept_widget_properties_losefocus();
			_Context->page_number = 2;
			accept_widget_properties_show();
			_Context->focus_item=27;
			continue;
			continue;
		case 0x873 : 
		case 0x853 : 
			/* OnShow */
						accept_widget_properties_losefocus();
			_Context->page_number = 3;
			accept_widget_properties_show();
			_Context->focus_item=30;
			continue;
			continue;
		case 0x867 : 
		case 0x847 : 
			/* OnGetFocus */
						accept_widget_properties_losefocus();
			_Context->page_number = 4;
			accept_widget_properties_show();
			_Context->focus_item=33;
			continue;
			continue;
		case 0x865 : 
		case 0x845 : 
			/* OnEvent */
						accept_widget_properties_losefocus();
			_Context->page_number = 5;
			accept_widget_properties_show();
			_Context->focus_item=36;
			continue;
			continue;
		case 0x86c : 
		case 0x84c : 
			/* OnLoseFocus */
						accept_widget_properties_losefocus();
			_Context->page_number = 6;
			accept_widget_properties_show();
			_Context->focus_item=43;
			continue;
			continue;
		case 0x868 : 
		case 0x848 : 
			/* OnHide */
						accept_widget_properties_losefocus();
			_Context->page_number = 7;
			accept_widget_properties_show();
			_Context->focus_item=46;
			continue;
			continue;
		case 0x86d : 
		case 0x84d : 
			/* OnRemove */
						accept_widget_properties_losefocus();
			_Context->page_number = 8;
			accept_widget_properties_show();
			_Context->focus_item=49;
			continue;
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
	char * pAuto4659,
	char * pIdentity,
	char * pAuto3390,
	char * pWidgetClass,
	char * pAlign,
	char * pType,
	char * pIsBold,
	char * pIsUnderline,
	char * pIsShadow,
	char * pIsLock,
	char * pIsInterface,
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
	status = accept_widget_properties_create(
	 pAtX,
	 pAtY,
	 pWidth,
	 pHeight,
	 pTextFont,
	 pTextColour,
	 pBackground,
	 pPayLoad,
	 pAuto4659,
	 pIdentity,
	 pAuto3390,
	 pWidgetClass,
	 pAlign,
	 pType,
	 pIsBold,
	 pIsUnderline,
	 pIsShadow,
	 pIsLock,
	 pIsInterface,
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
	status = accept_widget_properties_show();
		enter_modal();
	status = accept_widget_properties_focus();
		leave_modal();
	status = accept_widget_properties_hide();
	status = accept_widget_properties_remove(
	 pAtX,
	 pAtY,
	 pWidth,
	 pHeight,
	 pTextFont,
	 pTextColour,
	 pBackground,
	 pPayLoad,
	 pAuto4659,
	 pIdentity,
	 pAuto3390,
	 pWidgetClass,
	 pAlign,
	 pType,
	 pIsBold,
	 pIsUnderline,
	 pIsShadow,
	 pIsLock,
	 pIsInterface,
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
