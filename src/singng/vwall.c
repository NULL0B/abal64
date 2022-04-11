
#ifndef _vwall_c
#define _vwall_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vwall.xml                                                */
/* Target         : vwall.c                                                  */
/* Identification : 0.0-1177511937-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "sing.h"
#include "singform.h"
#include "singprot.h"
#define en_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define fr_WidgetProperties   "Sing : Version 1.0a : Propert‚s des Widgets"
#define it_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define es_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define de_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define nl_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define pt_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define xx_WidgetProperties   "Sing : Version 1.0a : Widget Properties"
#define en__WidgetProperties   ""
#define en_auto50093   "Position"
#define fr_auto50093   "Position"
#define it_auto50093   "Position"
#define es_auto50093   "Position"
#define de_auto50093   "Position"
#define nl_auto50093   "Position"
#define pt_auto50093   "Position"
#define xx_auto50093   "Aite"
#define en__auto50093   ""
#define en_auto49   "Dimensions"
#define fr_auto49   "Dimensions"
#define it_auto49   "Dimensions"
#define es_auto49   "Dimensions"
#define de_auto49   "Dimensions"
#define nl_auto49   "Dimensions"
#define pt_auto49   "Dimensions"
#define xx_auto49   "Meud"
#define en__auto49   ""
#define en_AtX   ""
#define fr_AtX   ""
#define it_AtX   ""
#define es_AtX   ""
#define de_AtX   ""
#define nl_AtX   ""
#define pt_AtX   ""
#define xx_AtX   ""
#define en__AtX   ""
#define en_auto53   ","
#define fr_auto53   ","
#define it_auto53   ","
#define es_auto53   ","
#define de_auto53   ","
#define nl_auto53   ","
#define pt_auto53   ","
#define xx_auto53   ","
#define en__auto53   ""
#define en_AtY   ""
#define fr_AtY   ""
#define it_AtY   ""
#define es_AtY   ""
#define de_AtY   ""
#define nl_AtY   ""
#define pt_AtY   ""
#define xx_AtY   ""
#define en__AtY   ""
#define en_auto55   ","
#define fr_auto55   ","
#define it_auto55   ","
#define es_auto55   ","
#define de_auto55   ","
#define nl_auto55   ","
#define pt_auto55   ","
#define xx_auto55   ","
#define en__auto55   ""
#define en_Width   ""
#define fr_Width   ""
#define it_Width   ""
#define es_Width   ""
#define de_Width   ""
#define nl_Width   ""
#define pt_Width   ""
#define xx_Width   ""
#define en__Width   ""
#define en_Height   ""
#define fr_Height   ""
#define it_Height   ""
#define es_Height   ""
#define de_Height   ""
#define nl_Height   ""
#define pt_Height   ""
#define xx_Height   ""
#define en__Height   ""
#define en_auto64   "Text Font"
#define fr_auto64   "Fonte Texte"
#define it_auto64   "Text Font"
#define es_auto64   "Text Font"
#define de_auto64   "Text Font"
#define nl_auto64   "Text Font"
#define pt_auto64   "Text Font"
#define xx_auto64   "Teacs"
#define en__auto64   ""
#define en_auto67   "Colour"
#define fr_auto67   "Couleur"
#define it_auto67   "Colour"
#define es_auto67   "Colour"
#define de_auto67   "Colour"
#define nl_auto67   "Colour"
#define pt_auto67   "Colour"
#define xx_auto67   "Dath Teacs"
#define en__auto67   ""
#define fr__auto67   ""
#define it__auto67   ""
#define es__auto67   ""
#define de__auto67   ""
#define nl__auto67   ""
#define pt__auto67   ""
#define xx__auto67   ""
#define en__TextFont   ""
#define en_TextColour   ""
#define fr_TextColour   ""
#define it_TextColour   ""
#define es_TextColour   ""
#define de_TextColour   ""
#define nl_TextColour   ""
#define pt_TextColour   ""
#define xx_TextColour   ""
#define en__TextColour   ""
#define en_fgSelect   "fg"
#define fr_fgSelect   "fg"
#define it_fgSelect   "fg"
#define es_fgSelect   "fg"
#define de_fgSelect   "fg"
#define nl_fgSelect   "fg"
#define pt_fgSelect   "fg"
#define xx_fgSelect   "fg"
#define en__fgSelect   ""
#define en_auto70   "Background"
#define fr_auto70   "Fond"
#define it_auto70   "Background"
#define es_auto70   "Background"
#define de_auto70   "Background"
#define nl_auto70   "Background"
#define pt_auto70   "Background"
#define xx_auto70   "Dath culaidh"
#define en__auto70   ""
#define fr__auto70   ""
#define it__auto70   ""
#define es__auto70   ""
#define de__auto70   ""
#define nl__auto70   ""
#define pt__auto70   ""
#define xx__auto70   ""
#define en_Background   ""
#define fr_Background   ""
#define it_Background   ""
#define es_Background   ""
#define de_Background   ""
#define nl_Background   ""
#define pt_Background   ""
#define xx_Background   ""
#define en__Background   ""
#define en_bgSelect   "bg"
#define fr_bgSelect   "bg"
#define it_bgSelect   "bg"
#define es_bgSelect   "bg"
#define de_bgSelect   "bg"
#define nl_bgSelect   "bg"
#define pt_bgSelect   "bg"
#define xx_bgSelect   "bg"
#define en__bgSelect   ""
#define en_PayLoadSelect   "*"
#define fr_PayLoadSelect   "*"
#define it_PayLoadSelect   "*"
#define es_PayLoadSelect   "*"
#define de_PayLoadSelect   "*"
#define nl_PayLoadSelect   "*"
#define pt_PayLoadSelect   "*"
#define xx_PayLoadSelect   "*"
#define en__PayLoadSelect   ""
#define xx_auto73   "Griomh"
#define en__auto73   ""
#define fr__auto73   ""
#define it__auto73   ""
#define es__auto73   ""
#define de__auto73   ""
#define nl__auto73   ""
#define pt__auto73   ""
#define xx__auto73   ""
#define en_Auto2770   "Style : Show"
#define fr_Auto2770   "Style"
#define it_Auto2770   "Style"
#define es_Auto2770   "Style"
#define de_Auto2770   "Style"
#define nl_Auto2770   "Style"
#define pt_Auto2770   "Style"
#define xx_Auto2770   "Style"
#define en__Auto2770   ""
#define en_Auto2771   "Style : Focus"
#define fr_Auto2771   "Style"
#define it_Auto2771   "Style"
#define es_Auto2771   "Style"
#define de_Auto2771   "Style"
#define nl_Auto2771   "Style"
#define pt_Auto2771   "Style"
#define xx_Auto2771   "Style"
#define en__Auto2771   ""
#define en_Auto2772   "Hint"
#define fr_Auto2772   "Aide status"
#define it_Auto2772   "Hint"
#define es_Auto2772   "Hint"
#define de_Auto2772   "Hint"
#define nl_Auto2772   "Hint"
#define pt_Auto2772   "Hint"
#define xx_Auto2772   "Hint"
#define en__Auto2772   ""
#define fr__Auto2772   ""
#define it__Auto2772   ""
#define es__Auto2772   ""
#define de__Auto2772   ""
#define nl__Auto2772   ""
#define pt__Auto2772   ""
#define xx__Auto2772   ""
#define en_PayLoad   ""
#define fr_PayLoad   ""
#define it_PayLoad   ""
#define es_PayLoad   ""
#define de_PayLoad   ""
#define nl_PayLoad   ""
#define pt_PayLoad   ""
#define xx_PayLoad   ""
#define en__PayLoad   ""
#define en_Identity   ""
#define fr_Identity   ""
#define it_Identity   ""
#define es_Identity   ""
#define de_Identity   ""
#define nl_Identity   ""
#define pt_Identity   ""
#define xx_Identity   ""
#define en__Identity   ""
#define en_Format   ""
#define fr_Format   ""
#define it_Format   ""
#define es_Format   ""
#define de_Format   ""
#define nl_Format   ""
#define pt_Format   ""
#define xx_Format   ""
#define en__Format   ""
#define en_StyleSheet   ""
#define fr_StyleSheet   ""
#define it_StyleSheet   ""
#define es_StyleSheet   ""
#define de_StyleSheet   ""
#define nl_StyleSheet   ""
#define pt_StyleSheet   ""
#define xx_StyleSheet   ""
#define en__StyleSheet   ""
#define en_StyleFocus   ""
#define fr_StyleFocus   ""
#define it_StyleFocus   ""
#define es_StyleFocus   ""
#define de_StyleFocus   ""
#define nl_StyleFocus   ""
#define pt_StyleFocus   ""
#define xx_StyleFocus   ""
#define en__StyleFocus   ""
#define en_Hint   ""
#define fr_Hint   ""
#define it_Hint   ""
#define es_Hint   ""
#define de_Hint   ""
#define nl_Hint   ""
#define pt_Hint   ""
#define xx_Hint   ""
#define en__Hint   ""
#define en_auto77   "Identity"
#define fr_auto77   "Identit‚"
#define it_auto77   "Identity"
#define es_auto77   "Identity"
#define de_auto77   "Identity"
#define nl_auto77   "Identity"
#define pt_auto77   "Identity"
#define xx_auto77   "Ainm"
#define en__auto77   ""
#define fr__auto77   ""
#define it__auto77   ""
#define es__auto77   ""
#define de__auto77   ""
#define nl__auto77   ""
#define pt__auto77   ""
#define xx__auto77   ""
#define en_Auto2773   "Hotkey"
#define fr_Auto2773   "Hotkey"
#define it_Auto2773   "Hotkey"
#define es_Auto2773   "Hotkey"
#define de_Auto2773   "Hotkey"
#define nl_Auto2773   "Hotkey"
#define pt_Auto2773   "Hotkey"
#define xx_Auto2773   "Teas"
#define en__Auto2773   ""
#define en_HotkeyValue   ""
#define fr_HotkeyValue   ""
#define it_HotkeyValue   ""
#define es_HotkeyValue   ""
#define de_HotkeyValue   ""
#define nl_HotkeyValue   ""
#define pt_HotkeyValue   ""
#define xx_HotkeyValue   ""
#define en__HotkeyValue   ""
#define en_auto80   "Class"
#define fr_auto80   "Class"
#define it_auto80   "Class"
#define es_auto80   "Class"
#define de_auto80   "Class"
#define nl_auto80   "Class"
#define pt_auto80   "Class"
#define xx_auto80   "Clais"
#define en__auto80   ""
#define en__Auto2774   ""
#define fr__Auto2774   ""
#define it__Auto2774   ""
#define es__Auto2774   ""
#define de__Auto2774   ""
#define nl__Auto2774   ""
#define pt__Auto2774   ""
#define xx__Auto2774   ""
#define en_auto269   "Storage/Action Type"
#define fr_auto269   "Action/Stockage"
#define it_auto269   "Storage/Action Type"
#define es_auto269   "Storage/Action Type"
#define de_auto269   "Storage/Action Type"
#define nl_auto269   "Storage/Action Type"
#define pt_auto269   "Storage/Action Type"
#define xx_auto269   "Storage/Action Type"
#define en__auto269   ""
#define en__WidgetClass   ""
#define en_auto138   "Options"
#define fr_auto138   "Options"
#define it_auto138   "Options"
#define es_auto138   "Options"
#define de_auto138   "Options"
#define nl_auto138   "Options"
#define pt_auto138   "Options"
#define xx_auto138   "Eile"
#define en__auto138   ""
#define en__Align   ""
#define en_Auto2775   "image.new"
#define fr_Auto2775   "image.new"
#define it_Auto2775   "image.new"
#define es_Auto2775   "image.new"
#define de_Auto2775   "image.new"
#define nl_Auto2775   "image.new"
#define pt_Auto2775   "image.new"
#define xx_Auto2775   "image.new"
#define en__Auto2775   ""
#define en__Type   ""
#define en__IsBold   ""
#define en__IsUnderline   ""
#define en__IsShadow   ""
#define en_IsLock   "L&ocked"
#define fr_IsLock   "Verr&ouill‚"
#define it_IsLock   "L&ocked"
#define es_IsLock   "L&ocked"
#define de_IsLock   "L&ocked"
#define nl_IsLock   "L&ocked"
#define pt_IsLock   "L&ocked"
#define xx_IsLock   "Sabhaladh"
#define en__IsLock   ""
#define en_IsInterface   "Interface Item"
#define fr_IsInterface   "Item d'Interface"
#define it_IsInterface   "Interface Item"
#define es_IsInterface   "Interface Item"
#define de_IsInterface   "Interface Item"
#define nl_IsInterface   "Interface Item"
#define pt_IsInterface   "Interface Item"
#define xx_IsInterface   "A'faicinn"
#define en__IsInterface   ""
#define en__IsSpecial   ""
#define en_Auto2776   "Resize"
#define fr_Auto2776   "Redimensionnement"
#define it_Auto2776   "Resize"
#define es_Auto2776   "Resize"
#define de_Auto2776   "Resize"
#define nl_Auto2776   "Resize"
#define pt_Auto2776   "Resize"
#define xx_Auto2776   "Resize"
#define en__Auto2776   ""
#define fr__Auto2776   ""
#define it__Auto2776   ""
#define es__Auto2776   ""
#define de__Auto2776   ""
#define nl__Auto2776   ""
#define pt__Auto2776   ""
#define xx__Auto2776   ""
#define en_IswResize   "Width"
#define fr_IswResize   "Largeur"
#define it_IswResize   "Width"
#define es_IswResize   "Width"
#define de_IswResize   "Width"
#define nl_IswResize   "Width"
#define pt_IswResize   "Width"
#define xx_IswResize   "Width"
#define en__IswResize   ""
#define fr__IswResize   ""
#define it__IswResize   ""
#define es__IswResize   ""
#define de__IswResize   ""
#define nl__IswResize   ""
#define pt__IswResize   ""
#define xx__IswResize   ""
#define en_IshResize   "Height"
#define fr_IshResize   "Hauteur"
#define it_IshResize   "Height"
#define es_IshResize   "Height"
#define de_IshResize   "Height"
#define nl_IshResize   "Height"
#define pt_IshResize   "Height"
#define xx_IshResize   "Height"
#define en__IshResize   ""
#define fr__IshResize   ""
#define it__IshResize   ""
#define es__IshResize   ""
#define de__IshResize   ""
#define nl__IshResize   ""
#define pt__IshResize   ""
#define xx__IshResize   ""
#include "vwall.h"
static int	vfh[16];

/*	------------------------	*/
/*	p o s i t i o n _ a t ()	*/
/*	------------------------	*/
void	vwall_position_at(struct vwall_context * _Context,int x,int y){
	_Context->x_WidgetProperties=x;
	_Context->y_WidgetProperties=y;

}

/*	----------------	*/
/*	S e t V a r s ()	*/
/*	----------------	*/
void	vwall_SetVars(struct vwall_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	visual_signature("WWWW","WWWW");
	visual_transferin(_Context->buffer_AtX,7,pSpecificWidgetProperties->pAtX);
	visual_transferin(_Context->buffer_AtY,7,pSpecificWidgetProperties->pAtY);
	visual_transferin(_Context->buffer_Width,7,pSpecificWidgetProperties->pWidth);
	visual_transferin(_Context->buffer_Height,7,pSpecificWidgetProperties->pHeight);
	if(!(pSpecificWidgetProperties->pTextFont))
	_Context->value_TextFont=0;
	else
	_Context->value_TextFont=*((int*)pSpecificWidgetProperties->pTextFont);
	visual_signature("WWSSS","WWSSS");
	visual_transferin(_Context->buffer_TextColour,6,pSpecificWidgetProperties->pTextColour);
	visual_transferin(_Context->buffer_Background,6,pSpecificWidgetProperties->pBackground);
	visual_transferin(_Context->buffer_PayLoad,325,pSpecificWidgetProperties->pPayLoad);
	visual_transferin(_Context->buffer_Identity,255,pSpecificWidgetProperties->pIdentity);
	visual_transferin(_Context->buffer_Format,325,pSpecificWidgetProperties->pFormat);
	visual_signature("SSSW","SSSW");
	visual_transferin(_Context->buffer_StyleSheet,255,pSpecificWidgetProperties->pStyleSheet);
	visual_transferin(_Context->buffer_StyleFocus,255,pSpecificWidgetProperties->pStyleFocus);
	visual_transferin(_Context->buffer_Hint,255,pSpecificWidgetProperties->pHint);
	visual_transferin(_Context->buffer_HotkeyValue,6,pSpecificWidgetProperties->pHotkeyValue);
	if(!(pSpecificWidgetProperties->pWidgetClass))
	_Context->value_WidgetClass=0;
	else
	_Context->value_WidgetClass=*((int*)pSpecificWidgetProperties->pWidgetClass);
	if(!(pSpecificWidgetProperties->pAlign))
	_Context->value_Align=0;
	else
	_Context->value_Align=*((int*)pSpecificWidgetProperties->pAlign);
	if(!(pSpecificWidgetProperties->pType))
	_Context->value_Type=0;
	else
	_Context->value_Type=*((int*)pSpecificWidgetProperties->pType);
	if(!(pSpecificWidgetProperties->pIsBold))
	_Context->value_IsBold=0;
	else
	_Context->value_IsBold=*((int*)pSpecificWidgetProperties->pIsBold);
	if(!(pSpecificWidgetProperties->pIsUnderline))
	_Context->value_IsUnderline=0;
	else
	_Context->value_IsUnderline=*((int*)pSpecificWidgetProperties->pIsUnderline);
	if(!(pSpecificWidgetProperties->pIsShadow))
	_Context->value_IsShadow=0;
	else
	_Context->value_IsShadow=*((int*)pSpecificWidgetProperties->pIsShadow);
	if(!(pSpecificWidgetProperties->pIsLock))
	_Context->value_IsLock=0;
	else
	_Context->value_IsLock=*((int*)pSpecificWidgetProperties->pIsLock);
	if(!(pSpecificWidgetProperties->pIsInterface))
	_Context->value_IsInterface=0;
	else
	_Context->value_IsInterface=*((int*)pSpecificWidgetProperties->pIsInterface);
	if(!(pSpecificWidgetProperties->pIsSpecial))
	_Context->value_IsSpecial=0;
	else
	_Context->value_IsSpecial=*((int*)pSpecificWidgetProperties->pIsSpecial);

}

/*	----------------	*/
/*	G e t V a r s ()	*/
/*	----------------	*/
void	vwall_GetVars(struct vwall_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	visual_signature("WWWW","WWWW");
	visual_transferout(_Context->buffer_AtX,7,pSpecificWidgetProperties->pAtX);
	visual_transferout(_Context->buffer_AtY,7,pSpecificWidgetProperties->pAtY);
	visual_transferout(_Context->buffer_Width,7,pSpecificWidgetProperties->pWidth);
	visual_transferout(_Context->buffer_Height,7,pSpecificWidgetProperties->pHeight);
	if(pSpecificWidgetProperties->pTextFont!=(char*)0)
	*((int*)pSpecificWidgetProperties->pTextFont)=_Context->value_TextFont;
	visual_signature("WWSSS","WWSSS");
	visual_transferout(_Context->buffer_TextColour,6,pSpecificWidgetProperties->pTextColour);
	visual_transferout(_Context->buffer_Background,6,pSpecificWidgetProperties->pBackground);
	visual_transferout(_Context->buffer_PayLoad,325,pSpecificWidgetProperties->pPayLoad);
	visual_transferout(_Context->buffer_Identity,255,pSpecificWidgetProperties->pIdentity);
	visual_transferout(_Context->buffer_Format,325,pSpecificWidgetProperties->pFormat);
	visual_signature("SSSW","SSSW");
	visual_transferout(_Context->buffer_StyleSheet,255,pSpecificWidgetProperties->pStyleSheet);
	visual_transferout(_Context->buffer_StyleFocus,255,pSpecificWidgetProperties->pStyleFocus);
	visual_transferout(_Context->buffer_Hint,255,pSpecificWidgetProperties->pHint);
	visual_transferout(_Context->buffer_HotkeyValue,6,pSpecificWidgetProperties->pHotkeyValue);
	if(pSpecificWidgetProperties->pWidgetClass!=(char*)0)
	*((int*)pSpecificWidgetProperties->pWidgetClass)=_Context->value_WidgetClass;
	if(pSpecificWidgetProperties->pAlign!=(char*)0)
	*((int*)pSpecificWidgetProperties->pAlign)=_Context->value_Align;
	if(pSpecificWidgetProperties->pType!=(char*)0)
	*((int*)pSpecificWidgetProperties->pType)=_Context->value_Type;
	if(pSpecificWidgetProperties->pIsBold!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsBold)=_Context->value_IsBold;
	if(pSpecificWidgetProperties->pIsUnderline!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsUnderline)=_Context->value_IsUnderline;
	if(pSpecificWidgetProperties->pIsShadow!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsShadow)=_Context->value_IsShadow;
	if(pSpecificWidgetProperties->pIsLock!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsLock)=_Context->value_IsLock;
	if(pSpecificWidgetProperties->pIsInterface!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsInterface)=_Context->value_IsInterface;
	if(pSpecificWidgetProperties->pIsSpecial!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsSpecial)=_Context->value_IsSpecial;

}

public	int	vwall_attach()
{
	if ( visual_initialise(3|256) == -1 )
		return(56);

	else	{
		visual_palette("/home/abal3/images/aqua.rgb",27);
		cicopalette(0,0);
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
		initialise_mouse();
		}
	return(0);
}

public	int	vwall_attach_mode(int mode)
{
	if ( visual_initialise(3|mode) == -1 )
		return(56);

	else	{
		visual_palette("/home/abal3/images/aqua.rgb",27);
		cicopalette(0,0);
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
		initialise_mouse();
		}
	return(0);
}

public	int	vwall_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	vwall_create(struct vwall_context **cptr)
{

	int i;
	struct vwall_context * _Context=(struct vwall_context*)0;
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
	if (!(_Context = allocate( sizeof( struct vwall_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=28;
		for (i=0; i < 7; i++)  *(_Context->buffer_AtX+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_AtY+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Width+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Height+i)=' ';
		_Context->value_TextFont=0;
		for (i=0; i < 12; i++)  *(_Context->buffer_TextColour+i)=' ';
		for (i=0; i < 12; i++)  *(_Context->buffer_Background+i)=' ';
		for (i=0; i < 260; i++)  *(_Context->buffer_PayLoad+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_Identity+i)=' ';
		for (i=0; i < 260; i++)  *(_Context->buffer_Format+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_StyleSheet+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_StyleFocus+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_Hint+i)=' ';
		for (i=0; i < 6; i++)  *(_Context->buffer_HotkeyValue+i)=' ';
		_Context->value_WidgetClass=0;
		_Context->value_Align=0;
		_Context->value_Type=0;
		_Context->value_IsBold=0;
		_Context->value_IsUnderline=0;
		_Context->value_IsShadow=0;
		_Context->value_IsLock=0;
		_Context->value_IsInterface=0;
		_Context->value_IsSpecial=0;
		_Context->value_IswResize=0;
		_Context->value_IshResize=0;
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
	_Context->x_WidgetProperties=65;
	_Context->y_WidgetProperties=100;
	_Context->w_WidgetProperties=670;
	_Context->h_WidgetProperties=400;
	_Context->window_col=0;
	_Context->window_row=10;
	for (i=0; i < 8; i++)_Context->msg_auto50093[i]=" ";
	_Context->msg_auto50093[0]=en_auto50093;
	_Context->msg_auto50093[1]=fr_auto50093;
	_Context->msg_auto50093[2]=it_auto50093;
	_Context->msg_auto50093[3]=es_auto50093;
	_Context->msg_auto50093[4]=de_auto50093;
	_Context->msg_auto50093[5]=nl_auto50093;
	_Context->msg_auto50093[6]=pt_auto50093;
	_Context->msg_auto50093[7]=xx_auto50093;
	_Context->hint_auto50093[0]=en__auto50093;
	for (i=0; i < 8; i++)_Context->msg_auto49[i]=" ";
	_Context->msg_auto49[0]=en_auto49;
	_Context->msg_auto49[1]=fr_auto49;
	_Context->msg_auto49[2]=it_auto49;
	_Context->msg_auto49[3]=es_auto49;
	_Context->msg_auto49[4]=de_auto49;
	_Context->msg_auto49[5]=nl_auto49;
	_Context->msg_auto49[6]=pt_auto49;
	_Context->msg_auto49[7]=xx_auto49;
	_Context->hint_auto49[0]=en__auto49;
	_Context->hint_AtX[0]=en__AtX;
	for (i=0; i < 8; i++)_Context->msg_auto53[i]=" ";
	_Context->msg_auto53[0]=en_auto53;
	_Context->msg_auto53[1]=fr_auto53;
	_Context->msg_auto53[2]=it_auto53;
	_Context->msg_auto53[3]=es_auto53;
	_Context->msg_auto53[4]=de_auto53;
	_Context->msg_auto53[5]=nl_auto53;
	_Context->msg_auto53[6]=pt_auto53;
	_Context->msg_auto53[7]=xx_auto53;
	_Context->hint_auto53[0]=en__auto53;
	_Context->hint_AtY[0]=en__AtY;
	for (i=0; i < 8; i++)_Context->msg_auto55[i]=" ";
	_Context->msg_auto55[0]=en_auto55;
	_Context->msg_auto55[1]=fr_auto55;
	_Context->msg_auto55[2]=it_auto55;
	_Context->msg_auto55[3]=es_auto55;
	_Context->msg_auto55[4]=de_auto55;
	_Context->msg_auto55[5]=nl_auto55;
	_Context->msg_auto55[6]=pt_auto55;
	_Context->msg_auto55[7]=xx_auto55;
	_Context->hint_auto55[0]=en__auto55;
	_Context->hint_Width[0]=en__Width;
	_Context->hint_Height[0]=en__Height;
	for (i=0; i < 8; i++)_Context->msg_auto64[i]=" ";
	_Context->msg_auto64[0]=en_auto64;
	_Context->msg_auto64[1]=fr_auto64;
	_Context->msg_auto64[2]=it_auto64;
	_Context->msg_auto64[3]=es_auto64;
	_Context->msg_auto64[4]=de_auto64;
	_Context->msg_auto64[5]=nl_auto64;
	_Context->msg_auto64[6]=pt_auto64;
	_Context->msg_auto64[7]=xx_auto64;
	_Context->hint_auto64[0]=en__auto64;
	for (i=0; i < 8; i++)_Context->msg_auto67[i]=" ";
	_Context->msg_auto67[0]=en_auto67;
	_Context->msg_auto67[1]=fr_auto67;
	_Context->msg_auto67[2]=it_auto67;
	_Context->msg_auto67[3]=es_auto67;
	_Context->msg_auto67[4]=de_auto67;
	_Context->msg_auto67[5]=nl_auto67;
	_Context->msg_auto67[6]=pt_auto67;
	_Context->msg_auto67[7]=xx_auto67;
	_Context->hint_auto67[0]=en__auto67;
	_Context->hint_auto67[1]=fr__auto67;
	_Context->hint_auto67[2]=it__auto67;
	_Context->hint_auto67[3]=es__auto67;
	_Context->hint_auto67[4]=de__auto67;
	_Context->hint_auto67[5]=nl__auto67;
	_Context->hint_auto67[6]=pt__auto67;
	_Context->hint_auto67[7]=xx__auto67;
	for (i=0; i < 8; i++)_Context->msg_TextFont[i]=" ";
	_Context->hint_TextFont[0]=en__TextFont;
	_Context->hint_TextColour[0]=en__TextColour;
	for (i=0; i < 8; i++)_Context->msg_fgSelect[i]=" ";
	_Context->msg_fgSelect[0]=en_fgSelect;
	_Context->msg_fgSelect[1]=fr_fgSelect;
	_Context->msg_fgSelect[2]=it_fgSelect;
	_Context->msg_fgSelect[3]=es_fgSelect;
	_Context->msg_fgSelect[4]=de_fgSelect;
	_Context->msg_fgSelect[5]=nl_fgSelect;
	_Context->msg_fgSelect[6]=pt_fgSelect;
	_Context->msg_fgSelect[7]=xx_fgSelect;
	_Context->hint_fgSelect[0]=en__fgSelect;
	for (i=0; i < 8; i++)_Context->msg_auto70[i]=" ";
	_Context->msg_auto70[0]=en_auto70;
	_Context->msg_auto70[1]=fr_auto70;
	_Context->msg_auto70[2]=it_auto70;
	_Context->msg_auto70[3]=es_auto70;
	_Context->msg_auto70[4]=de_auto70;
	_Context->msg_auto70[5]=nl_auto70;
	_Context->msg_auto70[6]=pt_auto70;
	_Context->msg_auto70[7]=xx_auto70;
	_Context->hint_auto70[0]=en__auto70;
	_Context->hint_auto70[1]=fr__auto70;
	_Context->hint_auto70[2]=it__auto70;
	_Context->hint_auto70[3]=es__auto70;
	_Context->hint_auto70[4]=de__auto70;
	_Context->hint_auto70[5]=nl__auto70;
	_Context->hint_auto70[6]=pt__auto70;
	_Context->hint_auto70[7]=xx__auto70;
	_Context->hint_Background[0]=en__Background;
	for (i=0; i < 8; i++)_Context->msg_bgSelect[i]=" ";
	_Context->msg_bgSelect[0]=en_bgSelect;
	_Context->msg_bgSelect[1]=fr_bgSelect;
	_Context->msg_bgSelect[2]=it_bgSelect;
	_Context->msg_bgSelect[3]=es_bgSelect;
	_Context->msg_bgSelect[4]=de_bgSelect;
	_Context->msg_bgSelect[5]=nl_bgSelect;
	_Context->msg_bgSelect[6]=pt_bgSelect;
	_Context->msg_bgSelect[7]=xx_bgSelect;
	_Context->hint_bgSelect[0]=en__bgSelect;
	for (i=0; i < 8; i++)_Context->msg_PayLoadSelect[i]=" ";
	_Context->msg_PayLoadSelect[0]=en_PayLoadSelect;
	_Context->msg_PayLoadSelect[1]=fr_PayLoadSelect;
	_Context->msg_PayLoadSelect[2]=it_PayLoadSelect;
	_Context->msg_PayLoadSelect[3]=es_PayLoadSelect;
	_Context->msg_PayLoadSelect[4]=de_PayLoadSelect;
	_Context->msg_PayLoadSelect[5]=nl_PayLoadSelect;
	_Context->msg_PayLoadSelect[6]=pt_PayLoadSelect;
	_Context->msg_PayLoadSelect[7]=xx_PayLoadSelect;
	_Context->hint_PayLoadSelect[0]=en__PayLoadSelect;
	_Context->s_PayLoadSelect=0;
	_Context->p_PayLoadSelect=visual_buffer(_Context->x_WidgetProperties+610,_Context->y_WidgetProperties+195,20+2,18+2);
	for (i=0; i < 8; i++)_Context->msg_auto73[i]=" ";
	_Context->msg_auto73[7]=xx_auto73;
	_Context->hint_auto73[0]=en__auto73;
	_Context->hint_auto73[1]=fr__auto73;
	_Context->hint_auto73[2]=it__auto73;
	_Context->hint_auto73[3]=es__auto73;
	_Context->hint_auto73[4]=de__auto73;
	_Context->hint_auto73[5]=nl__auto73;
	_Context->hint_auto73[6]=pt__auto73;
	_Context->hint_auto73[7]=xx__auto73;
	for (i=0; i < 8; i++)_Context->msg_Auto2770[i]=" ";
	_Context->msg_Auto2770[0]=en_Auto2770;
	_Context->msg_Auto2770[1]=fr_Auto2770;
	_Context->msg_Auto2770[2]=it_Auto2770;
	_Context->msg_Auto2770[3]=es_Auto2770;
	_Context->msg_Auto2770[4]=de_Auto2770;
	_Context->msg_Auto2770[5]=nl_Auto2770;
	_Context->msg_Auto2770[6]=pt_Auto2770;
	_Context->msg_Auto2770[7]=xx_Auto2770;
	_Context->hint_Auto2770[0]=en__Auto2770;
	for (i=0; i < 8; i++)_Context->msg_Auto2771[i]=" ";
	_Context->msg_Auto2771[0]=en_Auto2771;
	_Context->msg_Auto2771[1]=fr_Auto2771;
	_Context->msg_Auto2771[2]=it_Auto2771;
	_Context->msg_Auto2771[3]=es_Auto2771;
	_Context->msg_Auto2771[4]=de_Auto2771;
	_Context->msg_Auto2771[5]=nl_Auto2771;
	_Context->msg_Auto2771[6]=pt_Auto2771;
	_Context->msg_Auto2771[7]=xx_Auto2771;
	_Context->hint_Auto2771[0]=en__Auto2771;
	for (i=0; i < 8; i++)_Context->msg_Auto2772[i]=" ";
	_Context->msg_Auto2772[0]=en_Auto2772;
	_Context->msg_Auto2772[1]=fr_Auto2772;
	_Context->msg_Auto2772[2]=it_Auto2772;
	_Context->msg_Auto2772[3]=es_Auto2772;
	_Context->msg_Auto2772[4]=de_Auto2772;
	_Context->msg_Auto2772[5]=nl_Auto2772;
	_Context->msg_Auto2772[6]=pt_Auto2772;
	_Context->msg_Auto2772[7]=xx_Auto2772;
	_Context->hint_Auto2772[0]=en__Auto2772;
	_Context->hint_Auto2772[1]=fr__Auto2772;
	_Context->hint_Auto2772[2]=it__Auto2772;
	_Context->hint_Auto2772[3]=es__Auto2772;
	_Context->hint_Auto2772[4]=de__Auto2772;
	_Context->hint_Auto2772[5]=nl__Auto2772;
	_Context->hint_Auto2772[6]=pt__Auto2772;
	_Context->hint_Auto2772[7]=xx__Auto2772;
	_Context->hint_PayLoad[0]=en__PayLoad;
	_Context->hint_Identity[0]=en__Identity;
	_Context->hint_Format[0]=en__Format;
	_Context->hint_StyleSheet[0]=en__StyleSheet;
	_Context->hint_StyleFocus[0]=en__StyleFocus;
	_Context->hint_Hint[0]=en__Hint;
	for (i=0; i < 8; i++)_Context->msg_auto77[i]=" ";
	_Context->msg_auto77[0]=en_auto77;
	_Context->msg_auto77[1]=fr_auto77;
	_Context->msg_auto77[2]=it_auto77;
	_Context->msg_auto77[3]=es_auto77;
	_Context->msg_auto77[4]=de_auto77;
	_Context->msg_auto77[5]=nl_auto77;
	_Context->msg_auto77[6]=pt_auto77;
	_Context->msg_auto77[7]=xx_auto77;
	_Context->hint_auto77[0]=en__auto77;
	_Context->hint_auto77[1]=fr__auto77;
	_Context->hint_auto77[2]=it__auto77;
	_Context->hint_auto77[3]=es__auto77;
	_Context->hint_auto77[4]=de__auto77;
	_Context->hint_auto77[5]=nl__auto77;
	_Context->hint_auto77[6]=pt__auto77;
	_Context->hint_auto77[7]=xx__auto77;
	for (i=0; i < 8; i++)_Context->msg_Auto2773[i]=" ";
	_Context->msg_Auto2773[0]=en_Auto2773;
	_Context->msg_Auto2773[1]=fr_Auto2773;
	_Context->msg_Auto2773[2]=it_Auto2773;
	_Context->msg_Auto2773[3]=es_Auto2773;
	_Context->msg_Auto2773[4]=de_Auto2773;
	_Context->msg_Auto2773[5]=nl_Auto2773;
	_Context->msg_Auto2773[6]=pt_Auto2773;
	_Context->msg_Auto2773[7]=xx_Auto2773;
	_Context->hint_Auto2773[0]=en__Auto2773;
	_Context->hint_HotkeyValue[0]=en__HotkeyValue;
	for (i=0; i < 8; i++)_Context->msg_auto80[i]=" ";
	_Context->msg_auto80[0]=en_auto80;
	_Context->msg_auto80[1]=fr_auto80;
	_Context->msg_auto80[2]=it_auto80;
	_Context->msg_auto80[3]=es_auto80;
	_Context->msg_auto80[4]=de_auto80;
	_Context->msg_auto80[5]=nl_auto80;
	_Context->msg_auto80[6]=pt_auto80;
	_Context->msg_auto80[7]=xx_auto80;
	_Context->hint_auto80[0]=en__auto80;
	for (i=0; i < 8; i++)_Context->msg_Auto2774[i]=" ";
	_Context->hint_Auto2774[0]=en__Auto2774;
	_Context->hint_Auto2774[1]=fr__Auto2774;
	_Context->hint_Auto2774[2]=it__Auto2774;
	_Context->hint_Auto2774[3]=es__Auto2774;
	_Context->hint_Auto2774[4]=de__Auto2774;
	_Context->hint_Auto2774[5]=nl__Auto2774;
	_Context->hint_Auto2774[6]=pt__Auto2774;
	_Context->hint_Auto2774[7]=xx__Auto2774;
	for (i=0; i < 8; i++)_Context->msg_auto269[i]=" ";
	_Context->msg_auto269[0]=en_auto269;
	_Context->msg_auto269[1]=fr_auto269;
	_Context->msg_auto269[2]=it_auto269;
	_Context->msg_auto269[3]=es_auto269;
	_Context->msg_auto269[4]=de_auto269;
	_Context->msg_auto269[5]=nl_auto269;
	_Context->msg_auto269[6]=pt_auto269;
	_Context->msg_auto269[7]=xx_auto269;
	_Context->hint_auto269[0]=en__auto269;
	for (i=0; i < 8; i++)_Context->msg_WidgetClass[i]=" ";
	_Context->hint_WidgetClass[0]=en__WidgetClass;
	for (i=0; i < 8; i++)_Context->msg_auto138[i]=" ";
	_Context->msg_auto138[0]=en_auto138;
	_Context->msg_auto138[1]=fr_auto138;
	_Context->msg_auto138[2]=it_auto138;
	_Context->msg_auto138[3]=es_auto138;
	_Context->msg_auto138[4]=de_auto138;
	_Context->msg_auto138[5]=nl_auto138;
	_Context->msg_auto138[6]=pt_auto138;
	_Context->msg_auto138[7]=xx_auto138;
	_Context->hint_auto138[0]=en__auto138;
	for (i=0; i < 8; i++)_Context->msg_Align[i]=" ";
	_Context->hint_Align[0]=en__Align;
	for (i=0; i < 8; i++)_Context->msg_Type[i]=" ";
	_Context->hint_Type[0]=en__Type;
	for (i=0; i < 8; i++)_Context->msg_IsBold[i]=" ";
	_Context->hint_IsBold[0]=en__IsBold;
	for (i=0; i < 8; i++)_Context->msg_IsUnderline[i]=" ";
	_Context->hint_IsUnderline[0]=en__IsUnderline;
	for (i=0; i < 8; i++)_Context->msg_IsShadow[i]=" ";
	_Context->hint_IsShadow[0]=en__IsShadow;
	for (i=0; i < 8; i++)_Context->msg_IsLock[i]=" ";
	_Context->msg_IsLock[0]=en_IsLock;
	_Context->msg_IsLock[1]=fr_IsLock;
	_Context->msg_IsLock[2]=it_IsLock;
	_Context->msg_IsLock[3]=es_IsLock;
	_Context->msg_IsLock[4]=de_IsLock;
	_Context->msg_IsLock[5]=nl_IsLock;
	_Context->msg_IsLock[6]=pt_IsLock;
	_Context->msg_IsLock[7]=xx_IsLock;
	_Context->hint_IsLock[0]=en__IsLock;
	for (i=0; i < 8; i++)_Context->msg_IsInterface[i]=" ";
	_Context->msg_IsInterface[0]=en_IsInterface;
	_Context->msg_IsInterface[1]=fr_IsInterface;
	_Context->msg_IsInterface[2]=it_IsInterface;
	_Context->msg_IsInterface[3]=es_IsInterface;
	_Context->msg_IsInterface[4]=de_IsInterface;
	_Context->msg_IsInterface[5]=nl_IsInterface;
	_Context->msg_IsInterface[6]=pt_IsInterface;
	_Context->msg_IsInterface[7]=xx_IsInterface;
	_Context->hint_IsInterface[0]=en__IsInterface;
	for (i=0; i < 8; i++)_Context->msg_IsSpecial[i]=" ";
	_Context->hint_IsSpecial[0]=en__IsSpecial;
	for (i=0; i < 8; i++)_Context->msg_Auto2776[i]=" ";
	_Context->msg_Auto2776[0]=en_Auto2776;
	_Context->msg_Auto2776[1]=fr_Auto2776;
	_Context->msg_Auto2776[2]=it_Auto2776;
	_Context->msg_Auto2776[3]=es_Auto2776;
	_Context->msg_Auto2776[4]=de_Auto2776;
	_Context->msg_Auto2776[5]=nl_Auto2776;
	_Context->msg_Auto2776[6]=pt_Auto2776;
	_Context->msg_Auto2776[7]=xx_Auto2776;
	_Context->hint_Auto2776[0]=en__Auto2776;
	_Context->hint_Auto2776[1]=fr__Auto2776;
	_Context->hint_Auto2776[2]=it__Auto2776;
	_Context->hint_Auto2776[3]=es__Auto2776;
	_Context->hint_Auto2776[4]=de__Auto2776;
	_Context->hint_Auto2776[5]=nl__Auto2776;
	_Context->hint_Auto2776[6]=pt__Auto2776;
	_Context->hint_Auto2776[7]=xx__Auto2776;
	for (i=0; i < 8; i++)_Context->msg_IswResize[i]=" ";
	_Context->msg_IswResize[0]=en_IswResize;
	_Context->msg_IswResize[1]=fr_IswResize;
	_Context->msg_IswResize[2]=it_IswResize;
	_Context->msg_IswResize[3]=es_IswResize;
	_Context->msg_IswResize[4]=de_IswResize;
	_Context->msg_IswResize[5]=nl_IswResize;
	_Context->msg_IswResize[6]=pt_IswResize;
	_Context->msg_IswResize[7]=xx_IswResize;
	_Context->hint_IswResize[0]=en__IswResize;
	_Context->hint_IswResize[1]=fr__IswResize;
	_Context->hint_IswResize[2]=it__IswResize;
	_Context->hint_IswResize[3]=es__IswResize;
	_Context->hint_IswResize[4]=de__IswResize;
	_Context->hint_IswResize[5]=nl__IswResize;
	_Context->hint_IswResize[6]=pt__IswResize;
	_Context->hint_IswResize[7]=xx__IswResize;
	for (i=0; i < 8; i++)_Context->msg_IshResize[i]=" ";
	_Context->msg_IshResize[0]=en_IshResize;
	_Context->msg_IshResize[1]=fr_IshResize;
	_Context->msg_IshResize[2]=it_IshResize;
	_Context->msg_IshResize[3]=es_IshResize;
	_Context->msg_IshResize[4]=de_IshResize;
	_Context->msg_IshResize[5]=nl_IshResize;
	_Context->msg_IshResize[6]=pt_IshResize;
	_Context->msg_IshResize[7]=xx_IshResize;
	_Context->hint_IshResize[0]=en__IshResize;
	_Context->hint_IshResize[1]=fr__IshResize;
	_Context->hint_IshResize[2]=it__IshResize;
	_Context->hint_IshResize[3]=es__IshResize;
	_Context->hint_IshResize[4]=de__IshResize;
	_Context->hint_IshResize[5]=nl__IshResize;
	_Context->hint_IshResize[6]=pt__IshResize;
	_Context->hint_IshResize[7]=xx__IshResize;
	return(0);
}

public 	int	vwall_hide(struct vwall_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_PayLoadSelect != (void *) 0)
	&& (_Context->s_PayLoadSelect != 0)) {
		(void)visual_buffer_put(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+610,_Context->y_WidgetProperties+195);
		_Context->s_PayLoadSelect=0;
		}

	return(result);
}

public	int	vwall_remove(struct vwall_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->p_PayLoadSelect != (void *) 0)
		_Context->p_PayLoadSelect = visual_drop(_Context->p_PayLoadSelect);
	_Context=liberate(_Context);

	return(result);
}
private int on_PayLoadSelect_show(struct vwall_context * _Context) {
	switch(_Context->value_WidgetClass){
	case _IMAGE_FRAME:
	case _BUTTON_FRAME:
	case _DATA_FRAME:
		if ((_Context->p_PayLoadSelect != (void *) 0)
	&& (_Context->s_PayLoadSelect == 0)) {
		(void)visual_buffer_get(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+610,_Context->y_WidgetProperties+195);
		_Context->s_PayLoadSelect=1;
		}
	if ((_Context->p_PayLoadSelect != (void *) 0)
	&& (_Context->s_PayLoadSelect == 0)) {
		(void)visual_buffer_get(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+610,_Context->y_WidgetProperties+195);
		_Context->s_PayLoadSelect=1;
		}
	_Context->trigger_PayLoadSelect=visual_trigger_code(_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+610,_Context->y_WidgetProperties+195,20,18,vfh[8],28,28,_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]),0);
;
	break;
	default:
		if ((_Context->p_PayLoadSelect != (void *) 0)
	&& (_Context->s_PayLoadSelect != 0)) {
		(void)visual_buffer_put(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+610,_Context->y_WidgetProperties+195);
		_Context->s_PayLoadSelect=0;
		}
;
	}
	return(-1);
}

public	int	vwall_show(struct vwall_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,"widget_frame",_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]))) != 0)
) {
		visual_window(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,vfh[2],_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]),0x4);
		}
	visual_text(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+30,98,16,vfh[2],27,0,_Context->msg_auto50093[_Context->language],strlen(_Context->msg_auto50093[_Context->language]),1281);
	visual_text(_Context->x_WidgetProperties+240,_Context->y_WidgetProperties+30,126,16,vfh[2],27,0,_Context->msg_auto49[_Context->language],strlen(_Context->msg_auto49[_Context->language]),1281);
	visual_frame(_Context->x_WidgetProperties+110,_Context->y_WidgetProperties+30,56+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+110+1,_Context->y_WidgetProperties+30+1,56,16,vfh[1],34,0,_Context->buffer_AtX,7,0);
	visual_text(_Context->x_WidgetProperties+170,_Context->y_WidgetProperties+30,10,20,vfh[1],34,0,_Context->msg_auto53[_Context->language],strlen(_Context->msg_auto53[_Context->language]),2);
	visual_frame(_Context->x_WidgetProperties+180,_Context->y_WidgetProperties+30,56+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+180+1,_Context->y_WidgetProperties+30+1,56,16,vfh[1],34,0,_Context->buffer_AtY,7,0);
	visual_text(_Context->x_WidgetProperties+430,_Context->y_WidgetProperties+30,10,20,vfh[1],34,0,_Context->msg_auto55[_Context->language],strlen(_Context->msg_auto55[_Context->language]),2);
	visual_frame(_Context->x_WidgetProperties+370,_Context->y_WidgetProperties+30,56+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+370+1,_Context->y_WidgetProperties+30+1,56,16,vfh[1],34,0,_Context->buffer_Width,7,0);
	visual_frame(_Context->x_WidgetProperties+440,_Context->y_WidgetProperties+30,56+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+440+1,_Context->y_WidgetProperties+30+1,56,16,vfh[1],34,0,_Context->buffer_Height,7,0);
	visual_text(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+60,98,16,vfh[2],27,0,_Context->msg_auto64[_Context->language],strlen(_Context->msg_auto64[_Context->language]),1281);
	visual_text(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+90,98,16,vfh[2],27,0,_Context->msg_auto67[_Context->language],strlen(_Context->msg_auto67[_Context->language]),1281);
	visual_select(_Context->x_WidgetProperties+110,_Context->y_WidgetProperties+60,130,100,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),768);
	visual_frame(_Context->x_WidgetProperties+110,_Context->y_WidgetProperties+90,96+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+110+1,_Context->y_WidgetProperties+90+1,96,16,vfh[1],34,0,_Context->buffer_TextColour,12,0);
	_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+210,_Context->y_WidgetProperties+90,28,16,vfh[8],28,28,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
	visual_text(_Context->x_WidgetProperties+240,_Context->y_WidgetProperties+90,126,16,vfh[2],27,0,_Context->msg_auto70[_Context->language],strlen(_Context->msg_auto70[_Context->language]),1281);
	visual_frame(_Context->x_WidgetProperties+370,_Context->y_WidgetProperties+90,96+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+370+1,_Context->y_WidgetProperties+90+1,96,16,vfh[1],34,0,_Context->buffer_Background,12,0);
	_Context->trigger_bgSelect=visual_trigger_code(_Context->msg_bgSelect[_Context->language],strlen(_Context->msg_bgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+470,_Context->y_WidgetProperties+90,28,16,vfh[8],28,28,_Context->msg_bgSelect[_Context->language],strlen(_Context->msg_bgSelect[_Context->language]),0);
	if ((_Context->p_PayLoadSelect != (void *) 0)
	&& (_Context->s_PayLoadSelect == 0)) {
		(void)visual_buffer_get(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+610,_Context->y_WidgetProperties+195);
		_Context->s_PayLoadSelect=1;
		}
	(void) on_PayLoadSelect_show(_Context);
	visual_text(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+120,98,16,vfh[2],27,0,WidgetPayload(_Context->value_WidgetClass),strlen(WidgetPayload(_Context->value_WidgetClass)),1281);
	visual_text(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+310,98,16,vfh[2],27,0,_Context->msg_Auto2770[_Context->language],strlen(_Context->msg_Auto2770[_Context->language]),1281);
	visual_text(_Context->x_WidgetProperties+325,_Context->y_WidgetProperties+310,84,16,vfh[2],27,0,_Context->msg_Auto2771[_Context->language],strlen(_Context->msg_Auto2771[_Context->language]),1281);
	visual_text(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+330,98,16,vfh[2],27,0,_Context->msg_Auto2772[_Context->language],strlen(_Context->msg_Auto2772[_Context->language]),1281);
	visual_frame(_Context->x_WidgetProperties+110,_Context->y_WidgetProperties+120,520+2,64+2,5);
	visual_text(_Context->x_WidgetProperties+110+1,_Context->y_WidgetProperties+120+1,520,64,vfh[1],34,0,_Context->buffer_PayLoad,260,0);
	visual_frame(_Context->x_WidgetProperties+110,_Context->y_WidgetProperties+195,496+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+110+1,_Context->y_WidgetProperties+195+1,496,16,vfh[1],34,0,_Context->buffer_Identity,255,0);
	visual_frame(_Context->x_WidgetProperties+110,_Context->y_WidgetProperties+240,520+2,64+2,5);
	visual_text(_Context->x_WidgetProperties+110+1,_Context->y_WidgetProperties+240+1,520,64,vfh[1],27,0,_Context->buffer_Format,260,0);
	visual_frame(_Context->x_WidgetProperties+110,_Context->y_WidgetProperties+310,216+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+110+1,_Context->y_WidgetProperties+310+1,216,16,vfh[1],0,0,_Context->buffer_StyleSheet,255,0);
	visual_frame(_Context->x_WidgetProperties+414,_Context->y_WidgetProperties+310,216+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+414+1,_Context->y_WidgetProperties+310+1,216,16,vfh[1],0,0,_Context->buffer_StyleFocus,255,0);
	visual_frame(_Context->x_WidgetProperties+110,_Context->y_WidgetProperties+330,520+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+110+1,_Context->y_WidgetProperties+330+1,520,16,vfh[1],0,0,_Context->buffer_Hint,255,0);
	visual_text(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+195,98,16,vfh[2],27,0,_Context->msg_auto77[_Context->language],strlen(_Context->msg_auto77[_Context->language]),1281);
	visual_text(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+355,98,16,vfh[2],27,0,_Context->msg_Auto2773[_Context->language],strlen(_Context->msg_Auto2773[_Context->language]),1281);
	visual_frame(_Context->x_WidgetProperties+110,_Context->y_WidgetProperties+355,48+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+110+1,_Context->y_WidgetProperties+355+1,48,16,vfh[1],27,0,_Context->buffer_HotkeyValue,6,0);
	visual_text(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+215,98,16,vfh[2],27,0,_Context->msg_auto80[_Context->language],strlen(_Context->msg_auto80[_Context->language]),1281);
	visual_text(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+240,98,16,vfh[2],27,0,WidgetMessage(_Context->value_WidgetClass,0),strlen(WidgetMessage(_Context->value_WidgetClass,0)),1281);
	visual_text(_Context->x_WidgetProperties+240,_Context->y_WidgetProperties+215,168,16,vfh[2],27,0,_Context->msg_auto269[_Context->language],strlen(_Context->msg_auto269[_Context->language]),1281);
	visual_select(_Context->x_WidgetProperties+110,_Context->y_WidgetProperties+215,128,140,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),768);
	visual_text(_Context->x_WidgetProperties+240,_Context->y_WidgetProperties+60,126,16,vfh[2],27,0,_Context->msg_auto138[_Context->language],strlen(_Context->msg_auto138[_Context->language]),1281);
	visual_select(_Context->x_WidgetProperties+370,_Context->y_WidgetProperties+60,130,100,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),768);
	visual_select(_Context->x_WidgetProperties+410,_Context->y_WidgetProperties+215,216,140,vfh[2],0,0,parse_selection(WidgetTypeList,&_Context->value_Type),768);
	_Context->trigger_IsBold=visual_trigger_code(WidgetMessage(_Context->value_WidgetClass,1),strlen(WidgetMessage(_Context->value_WidgetClass,1)));
	visual_check(_Context->x_WidgetProperties+520,_Context->y_WidgetProperties+30,140,16,vfh[2],175,0,WidgetMessage(_Context->value_WidgetClass,1),strlen(WidgetMessage(_Context->value_WidgetClass,1)),_Context->value_IsBold|0);
	_Context->trigger_IsUnderline=visual_trigger_code(WidgetMessage(_Context->value_WidgetClass,2),strlen(WidgetMessage(_Context->value_WidgetClass,2)));
	visual_check(_Context->x_WidgetProperties+520,_Context->y_WidgetProperties+60,112,16,vfh[2],175,0,WidgetMessage(_Context->value_WidgetClass,2),strlen(WidgetMessage(_Context->value_WidgetClass,2)),_Context->value_IsUnderline|0);
	_Context->trigger_IsShadow=visual_trigger_code(WidgetMessage(_Context->value_WidgetClass,3),strlen(WidgetMessage(_Context->value_WidgetClass,3)));
	visual_check(_Context->x_WidgetProperties+520,_Context->y_WidgetProperties+90,116,16,vfh[2],28,28,WidgetMessage(_Context->value_WidgetClass,3),strlen(WidgetMessage(_Context->value_WidgetClass,3)),_Context->value_IsShadow|0);
	_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+180,_Context->y_WidgetProperties+355,126,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
	_Context->trigger_IsInterface=visual_trigger_code(_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]));
	visual_check(_Context->x_WidgetProperties+310,_Context->y_WidgetProperties+355,154,16,vfh[2],28,28,_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]),_Context->value_IsInterface|0);
	_Context->trigger_IsSpecial=visual_trigger_code(WidgetMessage(_Context->value_WidgetClass,4),strlen(WidgetMessage(_Context->value_WidgetClass,4)));
	visual_check(_Context->x_WidgetProperties+470,_Context->y_WidgetProperties+355,154,16,vfh[2],28,28,WidgetMessage(_Context->value_WidgetClass,4),strlen(WidgetMessage(_Context->value_WidgetClass,4)),_Context->value_IsSpecial|0);
	visual_text(_Context->x_WidgetProperties+100,_Context->y_WidgetProperties+374,200,16,vfh[2],27,0,_Context->msg_Auto2776[_Context->language],strlen(_Context->msg_Auto2776[_Context->language]),1281);
	_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+310,_Context->y_WidgetProperties+374,150,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
	_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+470,_Context->y_WidgetProperties+374,154,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
	visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400);

	return(0);
}

private int AtX_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[16];
			mptr[0] = "The X and Y position edit fields allow the graphical pixel position ";
			mptr[1]="of the widget to be specified.  ";
			mptr[2]="The widget position may be changed in the visual forms editor by pressing ";
			mptr[3]="the left button of the mouse over the widget and then moving with ";
			mptr[4]="the button still pressed. When the mouse button is released the position ";
			mptr[5]="fileds X and Y will reflect the new current position.  ";
			mptr[6]="The widget position coordinate values are available for use in method ";
			mptr[7]="text via the method terms :  ";
			mptr[8]=" ";
			mptr[9]="this.X  ";
			mptr[10]=" ";
			mptr[11]="and  ";
			mptr[12]=" ";
			mptr[13]="this.Y  ";
			mptr[14]=" ";
			mptr[15]="respectivly.   ";
			return(visual_online_help(mptr,16));
			}
			break;
		case 1 : 
			{
			char * mptr[29];
			mptr[0] = "Les zones de saisie  X et Y permet de sp‚cifier la position du coin ";
			mptr[1]="en haut … gauche du widget.  ";
			mptr[2]="Pour changer la position … partir de l'‚diteur des formulaires :  ";
			mptr[3]="  ";
			mptr[4]=" -  positionez la souris au desous le widget a deplacer  ";
			mptr[5]=" -  appuyez sur le bouton GAUCHE du souris  ";
			mptr[6]=" -  toute en gardant la bouton GAUCHE appuy‚, deplacez le widget en deplacant ";
			mptr[7]="la souris.  ";
			mptr[8]=" -  finalement relachez la bouton GAUCHE du souris pour deposer le widget ";
			mptr[9]="Š sa position finale.  ";
			mptr[10]="  ";
			mptr[11]=" ";
			mptr[12]=" Les valeurs de ces deux champs vont indiquer par la suite la position ";
			mptr[13]="actuelle du widget.  ";
			mptr[14]=" ";
			mptr[15]="Les coordin‚es de la position du widget sont accessible en programmation ";
			mptr[16]="au sein des methodes par les expressions :  ";
			mptr[17]=" ";
			mptr[18]="this.X  ";
			mptr[19]=" ";
			mptr[20]="et   ";
			mptr[21]=" ";
			mptr[22]="this.Y  ";
			mptr[23]=" ";
			mptr[24]=" Par defaut la position est constante. Il faut activer l'option avec ";
			mptr[25]="dimensions du methode Show du widget … fin de pouvoir deplacer dynamiquement ";
			mptr[26]="un widget pendant l'‚xecution finale du program.  ";
			mptr[27]=" ";
			mptr[28]="   ";
			return(visual_online_help(mptr,29));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Width_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[16];
			mptr[0] = "The DIMENSION edit fields allow the widget size in pixels to be modified ";
			mptr[1]="and represent the WIDTH and HEIGHT of the item.  ";
			mptr[2]=" ";
			mptr[3]="The dimensions may be modified from the visual form editor by pressing ";
			mptr[4]="and holding the right button of the mouse and then stretching the ";
			mptr[5]="widget to its required size. The dimension fields W and H will adopt ";
			mptr[6]="the new widget dimensions when the right button is released.  ";
			mptr[7]=" ";
			mptr[8]="The dimensions values are available for use in method text  through ";
			mptr[9]="the following terms :  ";
			mptr[10]=" ";
			mptr[11]="this.W  ";
			mptr[12]=" ";
			mptr[13]="and  ";
			mptr[14]=" ";
			mptr[15]="this.H   ";
			return(visual_online_help(mptr,16));
			}
			break;
		case 1 : 
			{
			char * mptr[30];
			mptr[0] = "Les zones de saisie  W et H permet de specifier les dimensions, en ";
			mptr[1]="terms de son largeur et son hauteur, d'un widget.  ";
			mptr[2]="Pour changer les dimensions a partir de l'editeur des formulaires ";
			mptr[3]=":  ";
			mptr[4]="  ";
			mptr[5]=" -  positionez la souris au desous le widget a redimensioner  ";
			mptr[6]=" -  appuyez sur le bouton DROITE du souris  ";
			mptr[7]=" -  toute en gardant la bouton DROITE appuiŠ, deplacez le widget en deplacant ";
			mptr[8]="la souris.  ";
			mptr[9]=" -  finalement relachez la bouton DROITEgauche du souris pour valider ";
			mptr[10]=" les dimensions finales du widget.  ";
			mptr[11]="  ";
			mptr[12]=" ";
			mptr[13]=" Les valeurs de ces deux champs vont indiquer les dimensions actuelles ";
			mptr[14]="du widget.  ";
			mptr[15]=" ";
			mptr[16]="Les valeurs largeur et hauteur du widget sont accessible en programmation ";
			mptr[17]="au sein des methodes par les expression :  ";
			mptr[18]=" ";
			mptr[19]="this.W  ";
			mptr[20]=" ";
			mptr[21]="et   ";
			mptr[22]=" ";
			mptr[23]="this.H  ";
			mptr[24]=" ";
			mptr[25]=" Par defaut les dimensions sont constantes. Il faut activer l'option ";
			mptr[26]="avec dimensions du methode Show du widget a fin de pouvoir redimensioner ";
			mptr[27]="dynamiquement un widget pendant l'execution finale du program.  ";
			mptr[28]=" ";
			mptr[29]="   ";
			return(visual_online_help(mptr,30));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TextFont_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[20];
			mptr[0] = "The TEXT FONT edit field allows the font used by the widget, when ";
			mptr[1]="displaying text, to be selected.  The initial value of this field ";
			mptr[2]="will be taken from the current  value of the general parameter Current Font or the  Options.Parameters menu.  ";
			mptr[3]=" ";
			mptr[4]="This field is of conseqence to all widgets for which the  payload ";
			mptr[5]="represents a text to be displayed.  ";
			mptr[6]="This field should reference a fixed font for Edit widgets. In other ";
			mptr[7]="case proportional fonts are also possible.  ";
			mptr[8]=" ";
			mptr[9]="The numeric value of the field may be referenced in method text by ";
			mptr[10]="the term :  ";
			mptr[11]=" ";
			mptr[12]="this.FONT  ";
			mptr[13]=" ";
			mptr[14]="Information relating to the font dimensions may be refered to by the ";
			mptr[15]="terms :  ";
			mptr[16]=" ";
			mptr[17]="this.FONTWIDTH : the widht of the font in pixels.  ";
			mptr[18]=" ";
			mptr[19]="this.FONTHEIGHT : the height of the font in pixels.    ";
			return(visual_online_help(mptr,20));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "  ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TextColour_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[12];
			mptr[0] = "This edit field allows value of the text colour to be specified. The ";
			mptr[1]="initial value of this field is taken from the current default foreground ";
			mptr[2]="colour value as defined by the palette control  mechanisms of the ";
			mptr[3]="forms editor context.  ";
			mptr[4]="The default value may be changed by clicking with the left button ";
			mptr[5]="of the mouse on the desired colour.  ";
			mptr[6]="The Tool Icons of all widget types which make use of the text colour ";
			mptr[7]="will be redisplayed to reflect the text colour change.  ";
			mptr[8]="The value of this atribut may be referenced in method text  expressions ";
			mptr[9]="by the term :  ";
			mptr[10]=" ";
			mptr[11]="this.FG    ";
			return(visual_online_help(mptr,12));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Background_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[12];
			mptr[0] = "This edit field allows value of the background colour of the widget ";
			mptr[1]=" to be specified. The initial value of this field is taken from the ";
			mptr[2]="current default background colour value as defined by the palette ";
			mptr[3]="control  mechanisms of the forms editor context.  ";
			mptr[4]="The default value may be changed by clicking with the right button ";
			mptr[5]="of the mouse on the desired colour in the palette window.  ";
			mptr[6]="The Tool Icons of all widget types which make use of the background ";
			mptr[7]="colour will be redisplayed to reflect the colour change.  ";
			mptr[8]="The value of this atribut may be referenced in method text  expressions ";
			mptr[9]="by the term :  ";
			mptr[10]=" ";
			mptr[11]="this.BG    ";
			return(visual_online_help(mptr,12));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PayLoad_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[25];
			mptr[0] = "This edit field allows the payload of the widget to be specified. ";
			mptr[1]=" ";
			mptr[2]="The semantics of the payload depends on the actual widget class as ";
			mptr[3]="can be seen in the following table.  ";
			mptr[4]=" ";
			mptr[5]="  ";
			mptr[6]=" Class Description  ";
			mptr[7]=" WINDOW the window title  ";
			mptr[8]=" TEXT the text of the message to display  ";
			mptr[9]=" CHECK The label of the check box  ";
			mptr[10]=" RADIO The label of the radio button  ";
			mptr[11]=" BUTTON The label of the push button  ";
			mptr[12]=" TABPAGE The label on the tab page button  ";
			mptr[13]=" SWITCH The label in the switch button  ";
			mptr[14]=" SELECT The | separated list of option texts to numerated  by the selection ";
			mptr[15]="mechanism.  ";
			mptr[16]=" TABLE The | separated list of column titles  ";
			mptr[17]=" IMAGE The filename of the image.  ";
			mptr[18]=" OTHER No semantics are defined for the payload of other widget types. ";
			mptr[19]="  ";
			mptr[20]=" ";
			mptr[21]="The value of this atribut may be referenced from method text by the ";
			mptr[22]="term :  ";
			mptr[23]=" ";
			mptr[24]="this.PAYLOAD   ";
			return(visual_online_help(mptr,25));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Identity_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[7];
			mptr[0] = "This edit field allows an explicite name to give to identify  and ";
			mptr[1]="be able to access the widget from method text of other widgets and ";
			mptr[2]="in forms model documentation.  ";
			mptr[3]="By default widgets are atributed a unique auto generated name  with ";
			mptr[4]="the following basic format  ";
			mptr[5]=" ";
			mptr[6]="auto1345   ";
			return(visual_online_help(mptr,7));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Format_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[42];
			mptr[0] = "This edit field allows suplementary imformation to be provided  for ";
			mptr[1]=" ";
			mptr[2]=" ";
			mptr[3]="  ";
			mptr[4]="  ";
			mptr[5]=" - EDIT and FORM. ";
			mptr[6]=" ";
			mptr[7]=" Used in conjunction with  their payload in defining their structure, ";
			mptr[8]="display and usage.  ";
			mptr[9]=" ";
			mptr[10]=" This information should be provided by a standard abal format expression. ";
			mptr[11]=" ";
			mptr[12]=" ";
			mptr[13]="  ";
			mptr[14]=" - DATABASE components ";
			mptr[15]=" ";
			mptr[16]=" This edit field will also be used to provide suplementary information ";
			mptr[17]="for database compoents in the form of the the braced class name description ";
			mptr[18]="of the database structure.  ";
			mptr[19]=" ";
			mptr[20]="  ";
			mptr[21]=" - CLASS INSTANCE components ";
			mptr[22]=" ";
			mptr[23]=" This edit field will also be used to provide suplementary information ";
			mptr[24]="for class instance components in the form of a standard braced construction ";
			mptr[25]="parameter colon separated value list.  ";
			mptr[26]=" ";
			mptr[27]="  ";
			mptr[28]=" - BUTTON components ";
			mptr[29]=" ";
			mptr[30]=" This edit field will be used to provide the name of the target program ";
			mptr[31]="for CHAIN, LOADGO and OVERLAY type push buttons.  ";
			mptr[32]=" ";
			mptr[33]=" It should also specify the module name  for MODULE type push buttons. ";
			mptr[34]=" ";
			mptr[35]=" ";
			mptr[36]="  ";
			mptr[37]="  ";
			mptr[38]=" ";
			mptr[39]="It has no defined semantic for other classes of widget.  ";
			mptr[40]=" ";
			mptr[41]="     ";
			return(visual_online_help(mptr,42));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int StyleSheet_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[9];
			mptr[0] = " ";
			mptr[1]=" This edit field allows an alternative style classname to be specified ";
			mptr[2]="for the display of this component widget instead of the widget specific ";
			mptr[3]="visual library  function call OnShow. Style classes specified in this way should be  described in ";
			mptr[4]="the style sheet file defined in the  Forms Properties dialog box.  ";
			mptr[5]=" If a style sheet file is present and the class is found to exist ";
			mptr[6]="then the style will be  used for the display of the component by the ";
			mptr[7]="forms model editor.  ";
			mptr[8]="    ";
			return(visual_online_help(mptr,9));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int StyleFocus_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[9];
			mptr[0] = " ";
			mptr[1]="This edit field allows an alternative style classname to be specified ";
			mptr[2]="for  display of this component widget whenever it takes the focus. ";
			mptr[3]="  ";
			mptr[4]="Style classes specified in this way should be described in the style ";
			mptr[5]="sheet file defined in the Forms Properties dialog box. If a style sheet file is present and ";
			mptr[6]="the class is found to exist then the style will be  used for the display ";
			mptr[7]="of the component by the forms model editor.  ";
			mptr[8]="     ";
			return(visual_online_help(mptr,9));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Hint_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows an explicative message text to be provided ";
			mptr[1]="to be used by an eventual hint presentation mechanism of the parent ";
			mptr[2]="form.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int HotkeyValue_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field simply displays the numeric value of an eventual  ";
			mptr[1]="hotkey trigger found to be present in the payload field.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int WidgetClass_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[25];
			mptr[0] = "This combo selection field allows the nature or class of a widget ";
			mptr[1]=" to be changed. The following provides an exhaustive list of all widgets ";
			mptr[2]="types :  ";
			mptr[3]="  ";
			mptr[4]=" - fillzone  ";
			mptr[5]=" - outset frame ";
			mptr[6]=" - inset frame ";
			mptr[7]=" - ridge frame ";
			mptr[8]=" - groove frame  ";
			mptr[9]=" - edit ";
			mptr[10]=" - text ";
			mptr[11]=" - image ";
			mptr[12]=" - line ";
			mptr[13]=" - push button  ";
			mptr[14]=" - window ";
			mptr[15]=" - tab view  ";
			mptr[16]=" - check box ";
			mptr[17]=" - radio button  ";
			mptr[18]=" - combo select  ";
			mptr[19]=" - form or table  ";
			mptr[20]=" - scroll bar or slider  ";
			mptr[21]=" - progress  ";
			mptr[22]=" - switch ";
			mptr[23]=" - graph  ";
			mptr[24]="   ";
			return(visual_online_help(mptr,25));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Align_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[83];
			mptr[0] = "This combo selection field allows a value to be chosen  from a,widget ";
			mptr[1]="specific,list of options.  ";
			mptr[2]=" ";
			mptr[3]="The semantics of the options vary depending on the  actual class of ";
			mptr[4]="the widget as can be seen in the following table.  ";
			mptr[5]=" ";
			mptr[6]="   ";
			mptr[7]=" WIDGET Behaviour   ";
			mptr[8]=" WINDOW The alignment value applies to the window itself within the ";
			mptr[9]="parent graphical output screen.   ";
			mptr[10]=" TEXT   ";
			mptr[11]=" ";
			mptr[12]="None ";
			mptr[13]="   no alignment is applied and the text will be  displayed with automatic ";
			mptr[14]="line wrap within the zone defined by the position and dimension values. ";
			mptr[15]="This alignment value is not  intended for use with proportional fonts. ";
			mptr[16]=" ";
			mptr[17]="Right,Left,Center ";
			mptr[18]="   These values will cause the text to be  displayed aligned in a single ";
			mptr[19]="line centered in a vertical direction within the zone.  ";
			mptr[20]="Justify ";
			mptr[21]="   The text will be space padded displayed such that  it touches both ";
			mptr[22]="left and right edges of its zone ";
			mptr[23]="  ";
			mptr[24]=" FRAMES For the various frame components, namely INSET,OUTSET,GROOVE ";
			mptr[25]="andRIDGE, The alignment value applies to the payload which , when provided, ";
			mptr[26]=" will be displayed as a textual title for the frame.  The alignment ";
			mptr[27]="value of none inhibits title display.   ";
			mptr[28]=" IMAGE The following image options are available.  ";
			mptr[29]=" ";
			mptr[30]="None ";
			mptr[31]="   no alignment is applied to the image.  ";
			mptr[32]="Right ";
			mptr[33]="   The image will be right aligned in the widget zone.  ";
			mptr[34]="Left ";
			mptr[35]="   The image will be left aligned in the widget zone.  ";
			mptr[36]="Center ";
			mptr[37]="   The image will be centered within the widget zone.  ";
			mptr[38]="Tile ";
			mptr[39]="   This option causes the images, smaller than their  widget zone, to ";
			mptr[40]="be tiled or repeated, to fill the entire  zone.  ";
			mptr[41]="Makefit ";
			mptr[42]="   causes images to be stretched or squashed to fit the entire widget ";
			mptr[43]="zone.  ";
			mptr[44]="Bestfit ";
			mptr[45]="   causes images to stretched and squashed respecting the image proportions. ";
			mptr[46]="The result may stil be smaller than the  widget zone in which case ";
			mptr[47]="it will be centered.  ";
			mptr[48]="  ";
			mptr[49]=" SCROLLBAR This option controls the composition of the scroll bar. In ";
			mptr[50]="all cases, when the zone width is found to be greater than the zone ";
			mptr[51]="height a horizontal bar will be displayed. Otherwise, when the width ";
			mptr[52]="is less than the height, a vertical bar will be displayed.   ";
			mptr[53]=" ";
			mptr[54]="None ";
			mptr[55]="   The scroll bar trough will occupy the entire widget zone. No butons ";
			mptr[56]="will be displayed.  ";
			mptr[57]="Right ";
			mptr[58]="   A down or right button will be displayed at the appropriate extremity. ";
			mptr[59]="The scroll bar trough will occupy the remaining zone.  ";
			mptr[60]="Left ";
			mptr[61]="   A up or left button will be displayed at the appropriate extremity. ";
			mptr[62]="The scroll bar trough will occupy the remaining zone.  ";
			mptr[63]="Both ";
			mptr[64]="   Both up and down or left and right buttons will be displayed at each ";
			mptr[65]="end of the bar. The scroll bar trough will occupy the remaining zone. ";
			mptr[66]=" ";
			mptr[67]="Slider ";
			mptr[68]="   No buttons will be displayed and the slider bar will be displayed ";
			mptr[69]="as a rounded slider in a grooved trough, occupying the entire widget ";
			mptr[70]="zone.  ";
			mptr[71]="  ";
			mptr[72]=" PUSHBUTTON This option controls the nature of the push button as follows. ";
			mptr[73]=" ";
			mptr[74]=" ";
			mptr[75]="TEXT ";
			mptr[76]="   The payload of the widget will be displayed as the textual title of ";
			mptr[77]="the button with an eventual underlined hotkey trigger character.  ";
			mptr[78]="IMAGE ";
			mptr[79]="   The payload ofthe widget will be used as the filename of an image ";
			mptr[80]="to be displayed within the surface of the push button.  ";
			mptr[81]="  ";
			mptr[82]=" OTHER No semantic is currently defined for other widget types.     ";
			return(visual_online_help(mptr,83));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Type_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[40];
			mptr[0] = "This combo selection field allows the data or behavioural type  associated ";
			mptr[1]="with the widgets as can be seen below  ";
			mptr[2]=" ";
			mptr[3]="   ";
			mptr[4]=" Edit These widgets are normally of type String  and give rise to the ";
			mptr[5]="declaration of a string buffer storage area in the object container. ";
			mptr[6]=" ";
			mptr[7]=" Edit Widgets of this class also declare string storage but in addition ";
			mptr[8]="further declarations allow row and column access to the various table ";
			mptr[9]="members or positions.  ";
			mptr[10]=" Check,Switch These widgets are of type word with  a single integer ";
			mptr[11]="declaration representing their state.  ";
			mptr[12]=" Radio These widgets are of type word with  a single integer declaration ";
			mptr[13]="shared between all members of the radio group identifying the active ";
			mptr[14]="item of the radio group.  ";
			mptr[15]=" Button,TabView  In the case of these activator widgets the behavioural ";
			mptr[16]="type  Overlay implies that the widget is to trigger the attachment  of an ";
			mptr[17]="ABAL OVERLAY program when activated.  ";
			mptr[18]=" Progress These widgets have two integer data items the value and the ";
			mptr[19]="limit.  ";
			mptr[20]=" Scroll These widgets have three integer data items the value, the max ";
			mptr[21]="and the limit.   ";
			mptr[22]=" ";
			mptr[23]="The various data items may be referenced from method text by the terms ";
			mptr[24]=":   ";
			mptr[25]=" ";
			mptr[26]="  ";
			mptr[27]=" this.BUFFER   returns the string buffer value  ";
			mptr[28]=" this.SIZE     returns the string length  ";
			mptr[29]=" this.LINE(N)   sets the table line to N  ";
			mptr[30]=" this.LINES   returns the total number of table lines  ";
			mptr[31]=" this.LINESIZE   returns the total size in characters  of the table ";
			mptr[32]="line  ";
			mptr[33]=" this.COLUMN(N)  refers to the column N of the current LINE  ";
			mptr[34]=" this.COLUMNS   returns the total number of table columns  ";
			mptr[35]=" this.COLUMNSIZE   returns the total size in characters  of the table ";
			mptr[36]="column  ";
			mptr[37]=" this.VALUE   returns the numeric value  ";
			mptr[38]=" this.LIMIT   returns the numeric value  ";
			mptr[39]=" this.MAX   returns the numeric value        ";
			return(visual_online_help(mptr,40));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsBold_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[30];
			mptr[0] = "This check box controls widget dependant features.  ";
			mptr[1]=" ";
			mptr[2]="In most cases the check control allows activation of the bold atribut ";
			mptr[3]="for the textual payload, in the form of a title , label or other message. ";
			mptr[4]=" ";
			mptr[5]=" ";
			mptr[6]="The following table describes the widgets which are an exception to ";
			mptr[7]="this general rule.  ";
			mptr[8]=" ";
			mptr[9]="   ";
			mptr[10]=" Widget Description  ";
			mptr[11]=" Button For Image buttons this check controls the makefit option of ";
			mptr[12]="the button image. When set the image will be stretched or squashed ";
			mptr[13]="to fit inside the button area or frame. Otherwise, when reset, the ";
			mptr[14]="image will be aligned or clipped  as required, retaining its original ";
			mptr[15]="size.  ";
			mptr[16]=" EDIT This check activates enforcement of the format supplied by the ";
			mptr[17]="format field of the these widgets.  ";
			mptr[18]=" FORM As for edit widgets this check activates enforcement of the format ";
			mptr[19]=" supplied by the format field of the these widgets.  ";
			mptr[20]=" SCROLL This check controls the focus grip atribut of scrollbars which ";
			mptr[21]="will be visible when a scrollbar is selected by mouse activity and ";
			mptr[22]="will be maintained during their operation up until the final mouse ";
			mptr[23]="release.  ";
			mptr[24]=" IMAGE This check controls the spriting nature of its widget. Image ";
			mptr[25]="sprites will recognise and apply their transparency allowing backgrounds ";
			mptr[26]="to shine through in appropriate areas.  ";
			mptr[27]=" WINDOW This check controls the presence of the exit button,  appearing ";
			mptr[28]="at the top right hand corner of the widget, which when clicked will ";
			mptr[29]="return an escape result.         ";
			return(visual_online_help(mptr,30));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsUnderline_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[16];
			mptr[0] = "This check box controls widget dependant features.  ";
			mptr[1]=" ";
			mptr[2]="In most cases the check control allows activation of the underline ";
			mptr[3]="atribut for the textual payload, in the form of a title , label or ";
			mptr[4]="other message.  ";
			mptr[5]=" ";
			mptr[6]="For the EDIT widget this check controls may be used to indicate that ";
			mptr[7]=" the data input must be performed in secret mode, only stars being ";
			mptr[8]="displayed, the actual  value being hidden. This may be used for pass ";
			mptr[9]="word entry or other fields where discretion is required.  ";
			mptr[10]=" ";
			mptr[11]="For the WINDOW widget this check control allows a help button to be ";
			mptr[12]=" added to the window in the top right corner.  ";
			mptr[13]=" ";
			mptr[14]="This help button gives direct access to the html document generated ";
			mptr[15]="for the  parent forms component.   ";
			return(visual_online_help(mptr,16));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsShadow_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[9];
			mptr[0] = "This check box controls widget dependant features.  ";
			mptr[1]=" ";
			mptr[2]="In most cases the check control allows activation of the shadow atribut ";
			mptr[3]="for the textual payload, in the form of a title , label or other message. ";
			mptr[4]=" ";
			mptr[5]=" ";
			mptr[6]="For the FORM widget this check controls the title bar relief atribut, ";
			mptr[7]="which when set causes the titles zone to be displayed in GUI RELIEF ";
			mptr[8]="format rather than in GUI TITLE COLOUR format.    ";
			return(visual_online_help(mptr,9));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsLock_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This check box allows the collection of widget properties to be  locked ";
			mptr[1]="and consequently protected against accidental modification.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsInterface_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This check control when selected indicates that the initial value ";
			mptr[1]="of the storage associated with the widget is to be received as a parameter ";
			mptr[2]="in the case of modular packaging.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsSpecial_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This check control allows activation of the drag bar for window components ";
			mptr[1]="when the corresponding form property check control has also been activated. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IswResize_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This check control when selected indicates that the initial value ";
			mptr[1]="of the storage associated with the widget is to be received as a parameter ";
			mptr[2]="in the case of modular packaging.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IshResize_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This check control when selected indicates that the initial value ";
			mptr[1]="of the storage associated with the widget is to be received as a parameter ";
			mptr[2]="in the case of modular packaging.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int WidgetPropertiesaction(struct vwall_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			vwall_hide(_Context);

		_Context->x_WidgetProperties += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_WidgetProperties < 0) { _Context->x_WidgetProperties=0; }
		_Context->y_WidgetProperties += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_WidgetProperties < 0) { _Context->y_WidgetProperties=0; }
			vwall_show(_Context);

		visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_fgSelect_event(struct vwall_context * _Context) {
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
		vwall_show(_Context);
;
	return(-1);
}
private int on_bgSelect_event(struct vwall_context * _Context) {
	on_fgSelect_event(_Context);
	return(-1);
}
private int on_PayLoadSelect_event(struct vwall_context * _Context) {
	switch(_Context->value_WidgetClass){
	case _IMAGE_FRAME:
	case _BUTTON_FRAME:
		vwall_hide(_Context);
;
	use_file_selector(_Context->buffer_PayLoad,WIDGET_FILE_GIF);
		vwall_show(_Context);
;
	break;
	case _DATA_FRAME:
		vwall_hide(_Context);
;
	if(_Context->value_IsLock!=0){
	use_data_selector(
	(void*)0,
	_Context->buffer_Format,260,/*classname*/
	_Context->buffer_Identity,255,/*instance*/
	_Context->buffer_PayLoad,260/*filename*/
	);
	}
	else{
	use_data_selector(
	(void*)0,
	_Context->buffer_Format,260,/*classname*/
	_Context->buffer_Identity,0,/*instance*/
	_Context->buffer_PayLoad,0/*filename*/
	);
	}
		vwall_show(_Context);
;
	break;
	}
		return(-1);
}


public	int	vwall_event(
struct vwall_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_fgSelect == mb ) return(7);
		if (_Context->trigger_bgSelect == mb ) return(9);
		if (_Context->trigger_PayLoadSelect == mb ) return(10);
		if (_Context->trigger_IsBold == mb ) return(21);
		if (_Context->trigger_IsUnderline == mb ) return(22);
		if (_Context->trigger_IsShadow == mb ) return(23);
		if (_Context->trigger_IsLock == mb ) return(24);
		if (_Context->trigger_IsInterface == mb ) return(25);
		if (_Context->trigger_IsSpecial == mb ) return(26);
		if (_Context->trigger_IswResize == mb ) return(27);
		if (_Context->trigger_IshResize == mb ) return(28);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x1031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_WidgetProperties+110) ) 
	&&  ( my >= (_Context->y_WidgetProperties+30) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+110+56) ) 
	&&  ( my <= (_Context->y_WidgetProperties+30+16))) {
		return(1); /* AtX */
		}
	if (( mx >= (_Context->x_WidgetProperties+180) ) 
	&&  ( my >= (_Context->y_WidgetProperties+30) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+180+56) ) 
	&&  ( my <= (_Context->y_WidgetProperties+30+16))) {
		return(2); /* AtY */
		}
	if (( mx >= (_Context->x_WidgetProperties+370) ) 
	&&  ( my >= (_Context->y_WidgetProperties+30) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+370+56) ) 
	&&  ( my <= (_Context->y_WidgetProperties+30+16))) {
		return(3); /* Width */
		}
	if (( mx >= (_Context->x_WidgetProperties+440) ) 
	&&  ( my >= (_Context->y_WidgetProperties+30) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+440+56) ) 
	&&  ( my <= (_Context->y_WidgetProperties+30+16))) {
		return(4); /* Height */
		}
	if (( mx >= (_Context->x_WidgetProperties+110+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+60) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+110+130) ) 
	&&  ( my <= (_Context->y_WidgetProperties+60+16))) {
		return(5); /* TextFont */
		}
	if (( mx >= (_Context->x_WidgetProperties+110) ) 
	&&  ( my >= (_Context->y_WidgetProperties+90) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+110+96) ) 
	&&  ( my <= (_Context->y_WidgetProperties+90+16))) {
		return(6); /* TextColour */
		}
	if (( mx >= (_Context->x_WidgetProperties+210) ) 
	&&  ( my >= (_Context->y_WidgetProperties+90) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+210+28) ) 
	&&  ( my <= (_Context->y_WidgetProperties+90+16))) {
		return(7); /* fgSelect */
		}
	if (( mx >= (_Context->x_WidgetProperties+370) ) 
	&&  ( my >= (_Context->y_WidgetProperties+90) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+370+96) ) 
	&&  ( my <= (_Context->y_WidgetProperties+90+16))) {
		return(8); /* Background */
		}
	if (( mx >= (_Context->x_WidgetProperties+470) ) 
	&&  ( my >= (_Context->y_WidgetProperties+90) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+470+28) ) 
	&&  ( my <= (_Context->y_WidgetProperties+90+16))) {
		return(9); /* bgSelect */
		}
	if (( mx >= (_Context->x_WidgetProperties+610) ) 
	&&  ( my >= (_Context->y_WidgetProperties+195) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+610+20) ) 
	&&  ( my <= (_Context->y_WidgetProperties+195+18))) {
		return(10); /* PayLoadSelect */
		}
	if (( mx >= (_Context->x_WidgetProperties+110) ) 
	&&  ( my >= (_Context->y_WidgetProperties+120) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+110+520) ) 
	&&  ( my <= (_Context->y_WidgetProperties+120+64))) {
		return(11); /* PayLoad */
		}
	if (( mx >= (_Context->x_WidgetProperties+110) ) 
	&&  ( my >= (_Context->y_WidgetProperties+195) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+110+496) ) 
	&&  ( my <= (_Context->y_WidgetProperties+195+16))) {
		return(12); /* Identity */
		}
	if (( mx >= (_Context->x_WidgetProperties+110) ) 
	&&  ( my >= (_Context->y_WidgetProperties+240) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+110+520) ) 
	&&  ( my <= (_Context->y_WidgetProperties+240+64))) {
		return(13); /* Format */
		}
	if (( mx >= (_Context->x_WidgetProperties+110) ) 
	&&  ( my >= (_Context->y_WidgetProperties+310) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+110+216) ) 
	&&  ( my <= (_Context->y_WidgetProperties+310+16))) {
		return(14); /* StyleSheet */
		}
	if (( mx >= (_Context->x_WidgetProperties+414) ) 
	&&  ( my >= (_Context->y_WidgetProperties+310) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+414+216) ) 
	&&  ( my <= (_Context->y_WidgetProperties+310+16))) {
		return(15); /* StyleFocus */
		}
	if (( mx >= (_Context->x_WidgetProperties+110) ) 
	&&  ( my >= (_Context->y_WidgetProperties+330) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+110+520) ) 
	&&  ( my <= (_Context->y_WidgetProperties+330+16))) {
		return(16); /* Hint */
		}
	if (( mx >= (_Context->x_WidgetProperties+110) ) 
	&&  ( my >= (_Context->y_WidgetProperties+355) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+110+48) ) 
	&&  ( my <= (_Context->y_WidgetProperties+355+16))) {
		return(17); /* HotkeyValue */
		}
	if (( mx >= (_Context->x_WidgetProperties+110+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+215) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+110+128) ) 
	&&  ( my <= (_Context->y_WidgetProperties+215+16))) {
		return(18); /* WidgetClass */
		}
	if (( mx >= (_Context->x_WidgetProperties+370+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+60) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+370+130) ) 
	&&  ( my <= (_Context->y_WidgetProperties+60+16))) {
		return(19); /* Align */
		}
	if (( mx >= (_Context->x_WidgetProperties+410+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+215) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+410+216) ) 
	&&  ( my <= (_Context->y_WidgetProperties+215+16))) {
		return(20); /* Type */
		}
	if (( mx >= (_Context->x_WidgetProperties+520) ) 
	&&  ( my >= (_Context->y_WidgetProperties+30) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+520+140) ) 
	&&  ( my <= (_Context->y_WidgetProperties+30+16))) {
		return(21); /* IsBold */
		}
	if (( mx >= (_Context->x_WidgetProperties+520) ) 
	&&  ( my >= (_Context->y_WidgetProperties+60) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+520+112) ) 
	&&  ( my <= (_Context->y_WidgetProperties+60+16))) {
		return(22); /* IsUnderline */
		}
	if (( mx >= (_Context->x_WidgetProperties+520) ) 
	&&  ( my >= (_Context->y_WidgetProperties+90) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+520+116) ) 
	&&  ( my <= (_Context->y_WidgetProperties+90+16))) {
		return(23); /* IsShadow */
		}
	if (( mx >= (_Context->x_WidgetProperties+180) ) 
	&&  ( my >= (_Context->y_WidgetProperties+355) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+180+126) ) 
	&&  ( my <= (_Context->y_WidgetProperties+355+16))) {
		return(24); /* IsLock */
		}
	if (( mx >= (_Context->x_WidgetProperties+310) ) 
	&&  ( my >= (_Context->y_WidgetProperties+355) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+310+154) ) 
	&&  ( my <= (_Context->y_WidgetProperties+355+16))) {
		return(25); /* IsInterface */
		}
	if (( mx >= (_Context->x_WidgetProperties+470) ) 
	&&  ( my >= (_Context->y_WidgetProperties+355) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+470+154) ) 
	&&  ( my <= (_Context->y_WidgetProperties+355+16))) {
		return(26); /* IsSpecial */
		}
	if (( mx >= (_Context->x_WidgetProperties+310) ) 
	&&  ( my >= (_Context->y_WidgetProperties+374) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+310+150) ) 
	&&  ( my <= (_Context->y_WidgetProperties+374+16))) {
		return(27); /* IswResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+470) ) 
	&&  ( my >= (_Context->y_WidgetProperties+374) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+470+154) ) 
	&&  ( my <= (_Context->y_WidgetProperties+374+16))) {
		return(28); /* IshResize */
		}

	return(-1);
}


public	int	vwall_focus(struct vwall_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* AtX */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+110+1,_Context->y_WidgetProperties+30+1,56,16,vfh[1],_Context->buffer_AtX,7);
			break;
			case	0x2 :
				/* AtY */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+180+1,_Context->y_WidgetProperties+30+1,56,16,vfh[1],_Context->buffer_AtY,7);
			break;
			case	0x3 :
				/* Width */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+370+1,_Context->y_WidgetProperties+30+1,56,16,vfh[1],_Context->buffer_Width,7);
			break;
			case	0x4 :
				/* Height */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+440+1,_Context->y_WidgetProperties+30+1,56,16,vfh[1],_Context->buffer_Height,7);
			break;
			case	0x5 :
				/* TextFont */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+110,_Context->y_WidgetProperties+60,130,100,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),770);
				break;
			case	0x6 :
				/* TextColour */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+110+1,_Context->y_WidgetProperties+90+1,96,16,vfh[1],_Context->buffer_TextColour,12);
			break;
			case	0x7 :
				/* fgSelect */
				_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
				visual_button(_Context->x_WidgetProperties+210,_Context->y_WidgetProperties+90,28,16,vfh[8],28,28,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+210,_Context->y_WidgetProperties+90,28,16,vfh[8],28,28,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
				break;
			case	0x8 :
				/* Background */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+370+1,_Context->y_WidgetProperties+90+1,96,16,vfh[1],_Context->buffer_Background,12);
			break;
			case	0x9 :
				/* bgSelect */
				_Context->trigger_bgSelect=visual_trigger_code(_Context->msg_bgSelect[_Context->language],strlen(_Context->msg_bgSelect[_Context->language]));
				visual_button(_Context->x_WidgetProperties+470,_Context->y_WidgetProperties+90,28,16,vfh[8],28,28,_Context->msg_bgSelect[_Context->language],strlen(_Context->msg_bgSelect[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_bgSelect=visual_trigger_code(_Context->msg_bgSelect[_Context->language],strlen(_Context->msg_bgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+470,_Context->y_WidgetProperties+90,28,16,vfh[8],28,28,_Context->msg_bgSelect[_Context->language],strlen(_Context->msg_bgSelect[_Context->language]),0);
				break;
			case	0xb :
				/* PayLoad */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+110+1,_Context->y_WidgetProperties+120+1,520,64,vfh[1],_Context->buffer_PayLoad,260);
			break;
			case	0xc :
				/* Identity */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+110+1,_Context->y_WidgetProperties+195+1,496,16,vfh[1],_Context->buffer_Identity,255);
			break;
			case	0xd :
				/* Format */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+110+1,_Context->y_WidgetProperties+240+1,520,64,vfh[1],_Context->buffer_Format,260);
			break;
			case	0xe :
				/* StyleSheet */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+110+1,_Context->y_WidgetProperties+310+1,216,16,vfh[1],_Context->buffer_StyleSheet,255);
			break;
			case	0xf :
				/* StyleFocus */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+414+1,_Context->y_WidgetProperties+310+1,216,16,vfh[1],_Context->buffer_StyleFocus,255);
			break;
			case	0x10 :
				/* Hint */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+110+1,_Context->y_WidgetProperties+330+1,520,16,vfh[1],_Context->buffer_Hint,255);
			break;
			case	0x11 :
				/* HotkeyValue */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+110+1,_Context->y_WidgetProperties+355+1,48,16,vfh[1],_Context->buffer_HotkeyValue,6);
			break;
			case	0x12 :
				/* WidgetClass */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+110,_Context->y_WidgetProperties+215,128,140,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),774);
				break;
			case	0x13 :
				/* Align */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+370,_Context->y_WidgetProperties+60,130,100,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),774);
				break;
			case	0x14 :
				/* Type */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+410,_Context->y_WidgetProperties+215,216,140,vfh[2],0,0,parse_selection(WidgetTypeList,&_Context->value_Type),774);
				break;
			case	0x15 :
				/* IsBold */
				visual_check(_Context->x_WidgetProperties+520,_Context->y_WidgetProperties+30,140,16,vfh[2],175,0,WidgetMessage(_Context->value_WidgetClass,1),strlen(WidgetMessage(_Context->value_WidgetClass,1)),(_Context->value_IsBold |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsBold=visual_trigger_code(WidgetMessage(_Context->value_WidgetClass,1),strlen(WidgetMessage(_Context->value_WidgetClass,1)));
	visual_check(_Context->x_WidgetProperties+520,_Context->y_WidgetProperties+30,140,16,vfh[2],175,0,WidgetMessage(_Context->value_WidgetClass,1),strlen(WidgetMessage(_Context->value_WidgetClass,1)),_Context->value_IsBold|0);
				break;
			case	0x16 :
				/* IsUnderline */
				visual_check(_Context->x_WidgetProperties+520,_Context->y_WidgetProperties+60,112,16,vfh[2],175,0,WidgetMessage(_Context->value_WidgetClass,2),strlen(WidgetMessage(_Context->value_WidgetClass,2)),(_Context->value_IsUnderline |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsUnderline=visual_trigger_code(WidgetMessage(_Context->value_WidgetClass,2),strlen(WidgetMessage(_Context->value_WidgetClass,2)));
	visual_check(_Context->x_WidgetProperties+520,_Context->y_WidgetProperties+60,112,16,vfh[2],175,0,WidgetMessage(_Context->value_WidgetClass,2),strlen(WidgetMessage(_Context->value_WidgetClass,2)),_Context->value_IsUnderline|0);
				break;
			case	0x17 :
				/* IsShadow */
				visual_check(_Context->x_WidgetProperties+520,_Context->y_WidgetProperties+90,116,16,vfh[2],28,28,WidgetMessage(_Context->value_WidgetClass,3),strlen(WidgetMessage(_Context->value_WidgetClass,3)),(_Context->value_IsShadow |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsShadow=visual_trigger_code(WidgetMessage(_Context->value_WidgetClass,3),strlen(WidgetMessage(_Context->value_WidgetClass,3)));
	visual_check(_Context->x_WidgetProperties+520,_Context->y_WidgetProperties+90,116,16,vfh[2],28,28,WidgetMessage(_Context->value_WidgetClass,3),strlen(WidgetMessage(_Context->value_WidgetClass,3)),_Context->value_IsShadow|0);
				break;
			case	0x18 :
				/* IsLock */
				visual_check(_Context->x_WidgetProperties+180,_Context->y_WidgetProperties+355,126,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),(_Context->value_IsLock |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+180,_Context->y_WidgetProperties+355,126,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
				break;
			case	0x19 :
				/* IsInterface */
				visual_check(_Context->x_WidgetProperties+310,_Context->y_WidgetProperties+355,154,16,vfh[2],28,28,_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]),(_Context->value_IsInterface |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsInterface=visual_trigger_code(_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]));
	visual_check(_Context->x_WidgetProperties+310,_Context->y_WidgetProperties+355,154,16,vfh[2],28,28,_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]),_Context->value_IsInterface|0);
				break;
			case	0x1a :
				/* IsSpecial */
				visual_check(_Context->x_WidgetProperties+470,_Context->y_WidgetProperties+355,154,16,vfh[2],28,28,WidgetMessage(_Context->value_WidgetClass,4),strlen(WidgetMessage(_Context->value_WidgetClass,4)),(_Context->value_IsSpecial |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsSpecial=visual_trigger_code(WidgetMessage(_Context->value_WidgetClass,4),strlen(WidgetMessage(_Context->value_WidgetClass,4)));
	visual_check(_Context->x_WidgetProperties+470,_Context->y_WidgetProperties+355,154,16,vfh[2],28,28,WidgetMessage(_Context->value_WidgetClass,4),strlen(WidgetMessage(_Context->value_WidgetClass,4)),_Context->value_IsSpecial|0);
				break;
			case	0x1b :
				/* IswResize */
				visual_check(_Context->x_WidgetProperties+310,_Context->y_WidgetProperties+374,150,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),(_Context->value_IswResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+310,_Context->y_WidgetProperties+374,150,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
				break;
			case	0x1c :
				/* IshResize */
				visual_check(_Context->x_WidgetProperties+470,_Context->y_WidgetProperties+374,154,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),(_Context->value_IshResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+470,_Context->y_WidgetProperties+374,154,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			vwall_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=28;
			vwall_show(_Context);
			continue;
		case	0x100 :
			if (!( visual_event(1)  & _MIMO_ALT )) { 
				if (( visual_event(7) <  _Context->x_WidgetProperties )
				|| ( visual_event(6) < _Context->y_WidgetProperties  )
				|| ( visual_event(7) > (_Context->x_WidgetProperties+_Context->w_WidgetProperties))
				|| ( visual_event(6) >  (_Context->y_WidgetProperties+_Context->h_WidgetProperties))) {
					if ( visual_event(1)  & _MIMO_MOVE ) { continue; }
					else { return(256); }
					}
				}
			if ((retcode=vwall_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						if (AtX_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Width_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (TextFont_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (TextColour_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (Background_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (PayLoad_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (Identity_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (Format_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (StyleSheet_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (StyleFocus_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (Hint_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (HotkeyValue_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (WidgetClass_help(_Context) != 0) { continue; }
						else { break; }
					case	0x13 :
						if (Align_help(_Context) != 0) { continue; }
						else { break; }
					case	0x14 :
						if (Type_help(_Context) != 0) { continue; }
						else { break; }
					case	0x15 :
						if (IsBold_help(_Context) != 0) { continue; }
						else { break; }
					case	0x16 :
						if (IsUnderline_help(_Context) != 0) { continue; }
						else { break; }
					case	0x17 :
						if (IsShadow_help(_Context) != 0) { continue; }
						else { break; }
					case	0x18 :
						if (IsLock_help(_Context) != 0) { continue; }
						else { break; }
					case	0x19 :
						if (IsInterface_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1a :
						if (IsSpecial_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1b :
						if (IswResize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1c :
						if (IshResize_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* AtX */
					continue;
				case	0x2 :
					/* AtY */
					continue;
				case	0x3 :
					/* Width */
					continue;
				case	0x4 :
					/* Height */
					continue;
				case	0x5 :
					/* TextFont */
					continue;
				case	0x6 :
					/* TextColour */
					continue;
				case	0x7 :
					/* fgSelect */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
						visual_button(_Context->x_WidgetProperties+210,_Context->y_WidgetProperties+90,28,16,vfh[8],28,28,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+210,_Context->y_WidgetProperties+90,28,16,vfh[8],28,28,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_fgSelect_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Background */
					continue;
				case	0x9 :
					/* bgSelect */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_bgSelect=visual_trigger_code(_Context->msg_bgSelect[_Context->language],strlen(_Context->msg_bgSelect[_Context->language]));
						visual_button(_Context->x_WidgetProperties+470,_Context->y_WidgetProperties+90,28,16,vfh[8],28,28,_Context->msg_bgSelect[_Context->language],strlen(_Context->msg_bgSelect[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_bgSelect=visual_trigger_code(_Context->msg_bgSelect[_Context->language],strlen(_Context->msg_bgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+470,_Context->y_WidgetProperties+90,28,16,vfh[8],28,28,_Context->msg_bgSelect[_Context->language],strlen(_Context->msg_bgSelect[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_bgSelect_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* PayLoadSelect */
					if (visual_event(1) & _MIMO_DOWN) {
						if ((_Context->p_PayLoadSelect != (void *) 0)
						&& (_Context->s_PayLoadSelect == 0)) {
							(void)visual_buffer_get(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+610,_Context->y_WidgetProperties+195);
							_Context->s_PayLoadSelect=1;
							}
						_Context->trigger_PayLoadSelect=visual_trigger_code(_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]));
						visual_button(_Context->x_WidgetProperties+610,_Context->y_WidgetProperties+195,20,18,vfh[8],28,28,_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						if ((_Context->p_PayLoadSelect != (void *) 0)
						&& (_Context->s_PayLoadSelect == 0)) {
							(void)visual_buffer_get(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+610,_Context->y_WidgetProperties+195);
							_Context->s_PayLoadSelect=1;
							}
						_Context->trigger_PayLoadSelect=visual_trigger_code(_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+610,_Context->y_WidgetProperties+195,20,18,vfh[8],28,28,_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_PayLoadSelect_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* PayLoad */
					continue;
				case	0xc :
					/* Identity */
					continue;
				case	0xd :
					/* Format */
					continue;
				case	0xe :
					/* StyleSheet */
					continue;
				case	0xf :
					/* StyleFocus */
					continue;
				case	0x10 :
					/* Hint */
					continue;
				case	0x11 :
					/* HotkeyValue */
					continue;
				case	0x12 :
					/* WidgetClass */
					continue;
				case	0x13 :
					/* Align */
					continue;
				case	0x14 :
					/* Type */
					continue;
				case	0x15 :
					/* IsBold */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsBold += 1;
						_Context->value_IsBold &= 1;
						}
					continue;
				case	0x16 :
					/* IsUnderline */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsUnderline += 1;
						_Context->value_IsUnderline &= 1;
						}
					continue;
				case	0x17 :
					/* IsShadow */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsShadow += 1;
						_Context->value_IsShadow &= 1;
						}
					continue;
				case	0x18 :
					/* IsLock */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsLock += 1;
						_Context->value_IsLock &= 1;
						}
					continue;
				case	0x19 :
					/* IsInterface */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsInterface += 1;
						_Context->value_IsInterface &= 1;
						}
					continue;
				case	0x1a :
					/* IsSpecial */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsSpecial += 1;
						_Context->value_IsSpecial &= 1;
						}
					continue;
				case	0x1b :
					/* IswResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IswResize += 1;
						_Context->value_IswResize &= 1;
						}
					continue;
				case	0x1c :
					/* IshResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IshResize += 1;
						_Context->value_IshResize &= 1;
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
				_Context->focus_item=28;
			}
			continue;
		case	0x0 :
			
			continue;
		case	0xffffffff :
			
			continue;

			}
		break;
		}

	return( _Context->keycode );
}

public	int	vwall()
{
	int	status=0;
	struct vwall_context * _Context=(struct vwall_context*) 0;
	status = vwall_create(&_Context);
	if ( status != 0) return(status);
	status = vwall_show(_Context);
		enter_modal();
	status = vwall_focus(_Context);
		leave_modal();
	status = vwall_hide(_Context);
	status = vwall_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwall_c */
