
#ifndef _vwform_c
#define _vwform_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 4.1a.0.09                                                */
/* Production     : C                                                        */
/* Project        : vwform.xml                                               */
/* Target         : vwform.c                                                 */
/* Identification : 0.0-1417705916-9408.9198                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "sing.h"
#include "singform.h"
#include "singprot.h"
#define en_WidgetProperties   "Form - Properties"
#define fr_WidgetProperties   "Form - Propri‚t‚s"
#define it_WidgetProperties   "Form widget - Properties"
#define es_WidgetProperties   "Form widget - Properties"
#define de_WidgetProperties   "Form widget - Properties"
#define nl_WidgetProperties   "Form widget - Properties"
#define pt_WidgetProperties   "Form widget - Properties"
#define xx_WidgetProperties   "Form widget - Properties"
#define en__WidgetProperties   ""
#define fr__WidgetProperties   ""
#define it__WidgetProperties   ""
#define es__WidgetProperties   ""
#define de__WidgetProperties   ""
#define nl__WidgetProperties   ""
#define pt__WidgetProperties   ""
#define xx__WidgetProperties   ""
#define en_Auto2543   "Position and Dimension"
#define fr_Auto2543   "Position et Dimension"
#define it_Auto2543   "Position and Dimension"
#define es_Auto2543   "Position and Dimension"
#define de_Auto2543   "Position and Dimension"
#define nl_Auto2543   "Position and Dimension"
#define pt_Auto2543   "Position and Dimension"
#define xx_Auto2543   "Position and Dimension"
#define en__Auto2543   ""
#define fr__Auto2543   ""
#define it__Auto2543   ""
#define es__Auto2543   ""
#define de__Auto2543   ""
#define nl__Auto2543   ""
#define pt__Auto2543   ""
#define xx__Auto2543   ""
#define en_Auto2545   "Behaviour"
#define fr_Auto2545   "Comportement"
#define it_Auto2545   "Behaviour"
#define es_Auto2545   "Behaviour"
#define de_Auto2545   "Behaviour"
#define nl_Auto2545   "Behaviour"
#define pt_Auto2545   "Behaviour"
#define xx_Auto2545   "Behaviour"
#define en__Auto2545   ""
#define fr__Auto2545   ""
#define it__Auto2545   ""
#define es__Auto2545   ""
#define de__Auto2545   ""
#define nl__Auto2545   ""
#define pt__Auto2545   ""
#define xx__Auto2545   ""
#define en_Auto2546   "Appearence"
#define fr_Auto2546   "Apparence"
#define it_Auto2546   "Appearence"
#define es_Auto2546   "Appearence"
#define de_Auto2546   "Appearence"
#define nl_Auto2546   "Appearence"
#define pt_Auto2546   "Appearence"
#define xx_Auto2546   "Appearence"
#define en__Auto2546   ""
#define fr__Auto2546   ""
#define it__Auto2546   ""
#define es__Auto2546   ""
#define de__Auto2546   ""
#define nl__Auto2546   ""
#define pt__Auto2546   ""
#define xx__Auto2546   ""
#define en_Auto2547   "General"
#define fr_Auto2547   "G‚n‚ral"
#define it_Auto2547   "General"
#define es_Auto2547   "General"
#define de_Auto2547   "General"
#define nl_Auto2547   "General"
#define pt_Auto2547   "General"
#define xx_Auto2547   "General"
#define en__Auto2547   ""
#define fr__Auto2547   ""
#define it__Auto2547   ""
#define es__Auto2547   ""
#define de__Auto2547   ""
#define nl__Auto2547   ""
#define pt__Auto2547   ""
#define xx__Auto2547   ""
#define en_Identity   ""
#define en__Identity   ""
#define en__WidgetStorage   ""
#define fr__WidgetStorage   ""
#define en_Hint   ""
#define en__Hint   ""
#define en_IsLock   "L&ocked"
#define fr_IsLock   "Verr&ouill‚"
#define it_IsLock   "L&ocked"
#define es_IsLock   "L&ocked"
#define de_IsLock   "L&ocked"
#define nl_IsLock   "L&ocked"
#define pt_IsLock   "L&ocked"
#define xx_IsLock   "Sabhaladh"
#define en__IsLock   ""
#define fr__IsLock   ""
#define it__IsLock   ""
#define es__IsLock   ""
#define de__IsLock   ""
#define nl__IsLock   ""
#define pt__IsLock   ""
#define xx__IsLock   ""
#define en_AtX   ""
#define en__AtX   ""
#define en__TextFont   ""
#define fr__TextFont   ""
#define en_AtY   ""
#define en__AtY   ""
#define en_Width   ""
#define en__Width   ""
#define en_Height   ""
#define en__Height   ""
#define en__Align   ""
#define fr__Align   ""
#define it__Align   ""
#define es__Align   ""
#define de__Align   ""
#define nl__Align   ""
#define pt__Align   ""
#define xx__Align   ""
#define en_PayLoad   ""
#define fr_PayLoad   ""
#define en__PayLoad   ""
#define fr__PayLoad   ""
#define en_StyleSheet   ""
#define fr_StyleSheet   ""
#define en__StyleSheet   ""
#define fr__StyleSheet   ""
#define en_TextColour   ""
#define en__TextColour   ""
#define en_Background   ""
#define en__Background   ""
#define en_IsBold   "Enforce"
#define fr_IsBold   "Format impos‚"
#define it_IsBold   "Enforce"
#define es_IsBold   "Enforce"
#define de_IsBold   "Enforce"
#define nl_IsBold   "Enforce"
#define pt_IsBold   "Enforce"
#define xx_IsBold   "Enforce"
#define en__IsBold   ""
#define fr__IsBold   ""
#define it__IsBold   ""
#define es__IsBold   ""
#define de__IsBold   ""
#define nl__IsBold   ""
#define pt__IsBold   ""
#define xx__IsBold   ""
#define en_Compact   "Compact"
#define fr_Compact   "Compact"
#define it_Compact   "Compact"
#define es_Compact   "Compact"
#define de_Compact   "Compact"
#define nl_Compact   "Compact"
#define pt_Compact   "Compact"
#define xx_Compact   "Compact"
#define en__Compact   ""
#define fr__Compact   ""
#define it__Compact   ""
#define es__Compact   ""
#define de__Compact   ""
#define nl__Compact   ""
#define pt__Compact   ""
#define xx__Compact   ""
#define en_LineFocus   "AutoFocus"
#define fr_LineFocus   "AutoFocus"
#define it_LineFocus   "AutoFocus"
#define es_LineFocus   "AutoFocus"
#define de_LineFocus   "AutoFocus"
#define nl_LineFocus   "AutoFocus"
#define pt_LineFocus   "AutoFocus"
#define xx_LineFocus   "AutoFocus"
#define en__LineFocus   ""
#define fr__LineFocus   ""
#define it__LineFocus   ""
#define es__LineFocus   ""
#define de__LineFocus   ""
#define nl__LineFocus   ""
#define pt__LineFocus   ""
#define xx__LineFocus   ""
#define en_IsUnderline   "Underline"
#define fr_IsUnderline   "Soulign‚"
#define it_IsUnderline   "Underline"
#define es_IsUnderline   "Underline"
#define de_IsUnderline   "Underline"
#define nl_IsUnderline   "Underline"
#define pt_IsUnderline   "Underline"
#define xx_IsUnderline   "Underline"
#define en__IsUnderline   ""
#define fr__IsUnderline   ""
#define it__IsUnderline   ""
#define es__IsUnderline   ""
#define de__IsUnderline   ""
#define nl__IsUnderline   ""
#define pt__IsUnderline   ""
#define xx__IsUnderline   ""
#define en_IsShadow   "Relief"
#define fr_IsShadow   "Relief"
#define it_IsShadow   "Relief"
#define es_IsShadow   "Relief"
#define de_IsShadow   "Relief"
#define nl_IsShadow   "Relief"
#define pt_IsShadow   "Relief"
#define xx_IsShadow   "Relief"
#define en__IsShadow   ""
#define fr__IsShadow   ""
#define it__IsShadow   ""
#define es__IsShadow   ""
#define de__IsShadow   ""
#define nl__IsShadow   ""
#define pt__IsShadow   ""
#define xx__IsShadow   ""
#define en_Format   ""
#define en__Format   ""
#define en_IswResize   "Resize Width"
#define fr_IswResize   "Largeur dynamique"
#define it_IswResize   "Resize Width"
#define es_IswResize   "Resize Width"
#define de_IswResize   "Resize Width"
#define nl_IswResize   "Resize Width"
#define pt_IswResize   "Resize Width"
#define xx_IswResize   "Resize Width"
#define en__IswResize   ""
#define fr__IswResize   ""
#define it__IswResize   ""
#define es__IswResize   ""
#define de__IswResize   ""
#define nl__IswResize   ""
#define pt__IswResize   ""
#define xx__IswResize   ""
#define en_IshResize   "Resize Height"
#define fr_IshResize   "Hauteur dynamique"
#define it_IshResize   "Resize Height"
#define es_IshResize   "Resize Height"
#define de_IshResize   "Resize Height"
#define nl_IshResize   "Resize Height"
#define pt_IshResize   "Resize Height"
#define xx_IshResize   "Resize Height"
#define en__IshResize   ""
#define fr__IshResize   ""
#define it__IshResize   ""
#define es__IshResize   ""
#define de__IshResize   ""
#define nl__IshResize   ""
#define pt__IshResize   ""
#define xx__IshResize   ""
#define en_Auto2548   "X"
#define fr_Auto2548   "X"
#define it_Auto2548   "X"
#define es_Auto2548   "X"
#define de_Auto2548   "X"
#define nl_Auto2548   "X"
#define pt_Auto2548   "X"
#define xx_Auto2548   "X"
#define en__Auto2548   ""
#define fr__Auto2548   ""
#define it__Auto2548   ""
#define es__Auto2548   ""
#define de__Auto2548   ""
#define nl__Auto2548   ""
#define pt__Auto2548   ""
#define xx__Auto2548   ""
#define en_Auto2549   "Height"
#define fr_Auto2549   "Hauteur"
#define it_Auto2549   "Height"
#define es_Auto2549   "Height"
#define de_Auto2549   "Height"
#define nl_Auto2549   "Height"
#define pt_Auto2549   "Height"
#define xx_Auto2549   "Height"
#define en__Auto2549   ""
#define fr__Auto2549   ""
#define it__Auto2549   ""
#define es__Auto2549   ""
#define de__Auto2549   ""
#define nl__Auto2549   ""
#define pt__Auto2549   ""
#define xx__Auto2549   ""
#define en_Auto2550   "Width"
#define fr_Auto2550   "Largeur"
#define it_Auto2550   "Width"
#define es_Auto2550   "Width"
#define de_Auto2550   "Width"
#define nl_Auto2550   "Width"
#define pt_Auto2550   "Width"
#define xx_Auto2550   "Width"
#define en__Auto2550   ""
#define fr__Auto2550   ""
#define it__Auto2550   ""
#define es__Auto2550   ""
#define de__Auto2550   ""
#define nl__Auto2550   ""
#define pt__Auto2550   ""
#define xx__Auto2550   ""
#define en_Auto2551   "Y"
#define fr_Auto2551   "Y"
#define it_Auto2551   "Y"
#define es_Auto2551   "Y"
#define de_Auto2551   "Y"
#define nl_Auto2551   "Y"
#define pt_Auto2551   "Y"
#define xx_Auto2551   "Y"
#define en__Auto2551   ""
#define fr__Auto2551   ""
#define it__Auto2551   ""
#define es__Auto2551   ""
#define de__Auto2551   ""
#define nl__Auto2551   ""
#define pt__Auto2551   ""
#define xx__Auto2551   ""
#define en_Auto2552   "Font"
#define fr_Auto2552   "Police"
#define it_Auto2552   "Font"
#define es_Auto2552   "Font"
#define de_Auto2552   "Font"
#define nl_Auto2552   "Font"
#define pt_Auto2552   "Font"
#define xx_Auto2552   "Font"
#define en__Auto2552   ""
#define fr__Auto2552   ""
#define it__Auto2552   ""
#define es__Auto2552   ""
#define de__Auto2552   ""
#define nl__Auto2552   ""
#define pt__Auto2552   ""
#define xx__Auto2552   ""
#define en_Auto2553   "Column title"
#define fr_Auto2553   "Entˆte"
#define it_Auto2553   "Column title"
#define es_Auto2553   "Column title"
#define de_Auto2553   "Column title"
#define nl_Auto2553   "Column title"
#define pt_Auto2553   "Column title"
#define xx_Auto2553   "Column title"
#define en__Auto2553   ""
#define fr__Auto2553   ""
#define it__Auto2553   ""
#define es__Auto2553   ""
#define de__Auto2553   ""
#define nl__Auto2553   ""
#define pt__Auto2553   ""
#define xx__Auto2553   ""
#define en_Auto2554   "Fore"
#define fr_Auto2554   "Texte"
#define it_Auto2554   "Fore"
#define es_Auto2554   "Fore"
#define de_Auto2554   "Fore"
#define nl_Auto2554   "Fore"
#define pt_Auto2554   "Fore"
#define xx_Auto2554   "Fore"
#define en__Auto2554   ""
#define fr__Auto2554   ""
#define it__Auto2554   ""
#define es__Auto2554   ""
#define de__Auto2554   ""
#define nl__Auto2554   ""
#define pt__Auto2554   ""
#define xx__Auto2554   ""
#define en_fgSelect   "Colors"
#define fr_fgSelect   "Couleurs"
#define it_fgSelect   "Colors"
#define es_fgSelect   "Colors"
#define de_fgSelect   "Colors"
#define nl_fgSelect   "Colors"
#define pt_fgSelect   "Colors"
#define xx_fgSelect   "Colors"
#define en__fgSelect   ""
#define fr__fgSelect   ""
#define it__fgSelect   ""
#define es__fgSelect   ""
#define de__fgSelect   ""
#define nl__fgSelect   ""
#define pt__fgSelect   ""
#define xx__fgSelect   ""
#define en_Auto2555   "Back"
#define fr_Auto2555   "Fond"
#define it_Auto2555   "Back"
#define es_Auto2555   "Back"
#define de_Auto2555   "Back"
#define nl_Auto2555   "Back"
#define pt_Auto2555   "Back"
#define xx_Auto2555   "Back"
#define en__Auto2555   ""
#define fr__Auto2555   ""
#define it__Auto2555   ""
#define es__Auto2555   ""
#define de__Auto2555   ""
#define nl__Auto2555   ""
#define pt__Auto2555   ""
#define xx__Auto2555   ""
#define en_Auto2556   "Explicit style"
#define fr_Auto2556   "Style explicite"
#define it_Auto2556   "Explicit style"
#define es_Auto2556   "Explicit style"
#define de_Auto2556   "Explicit style"
#define nl_Auto2556   "Explicit style"
#define pt_Auto2556   "Explicit style"
#define xx_Auto2556   "Explicit style"
#define en__Auto2556   ""
#define fr__Auto2556   ""
#define it__Auto2556   ""
#define es__Auto2556   ""
#define de__Auto2556   ""
#define nl__Auto2556   ""
#define pt__Auto2556   ""
#define xx__Auto2556   ""
#define en_Auto2557   "Hint"
#define fr_Auto2557   "Infobulle"
#define it_Auto2557   "Hint"
#define es_Auto2557   "Hint"
#define de_Auto2557   "Hint"
#define nl_Auto2557   "Hint"
#define pt_Auto2557   "Hint"
#define xx_Auto2557   "Hint"
#define en__Auto2557   ""
#define fr__Auto2557   ""
#define it__Auto2557   ""
#define es__Auto2557   ""
#define de__Auto2557   ""
#define nl__Auto2557   ""
#define pt__Auto2557   ""
#define xx__Auto2557   ""
#define en__WidgetClass   ""
#define en_Auto2558   "Implicit style"
#define fr_Auto2558   "Style implicite"
#define it_Auto2558   "Implicit style"
#define es_Auto2558   "Implicit style"
#define de_Auto2558   "Implicit style"
#define nl_Auto2558   "Implicit style"
#define pt_Auto2558   "Implicit style"
#define xx_Auto2558   "Implicit style"
#define en__Auto2558   ""
#define fr__Auto2558   ""
#define it__Auto2558   ""
#define es__Auto2558   ""
#define de__Auto2558   ""
#define nl__Auto2558   ""
#define pt__Auto2558   ""
#define xx__Auto2558   ""
#define en_Auto2559   "Name"
#define fr_Auto2559   "Nom"
#define it_Auto2559   "Name"
#define es_Auto2559   "Name"
#define de_Auto2559   "Name"
#define nl_Auto2559   "Name"
#define pt_Auto2559   "Name"
#define xx_Auto2559   "Name"
#define en__Auto2559   ""
#define fr__Auto2559   ""
#define it__Auto2559   ""
#define es__Auto2559   ""
#define de__Auto2559   ""
#define nl__Auto2559   ""
#define pt__Auto2559   ""
#define xx__Auto2559   ""
#define en_Auto2560   "Widget class"
#define fr_Auto2560   "Classe de widget"
#define it_Auto2560   "Widget class"
#define es_Auto2560   "Widget class"
#define de_Auto2560   "Widget class"
#define nl_Auto2560   "Widget class"
#define pt_Auto2560   "Widget class"
#define xx_Auto2560   "Widget class"
#define en__Auto2560   ""
#define fr__Auto2560   ""
#define it__Auto2560   ""
#define es__Auto2560   ""
#define de__Auto2560   ""
#define nl__Auto2560   ""
#define pt__Auto2560   ""
#define xx__Auto2560   ""
#define en_Auto2561   "Widget storage"
#define fr_Auto2561   "Storage Type"
#define it_Auto2561   "Widget class"
#define es_Auto2561   "Widget class"
#define de_Auto2561   "Widget class"
#define nl_Auto2561   "Widget class"
#define pt_Auto2561   "Widget class"
#define xx_Auto2561   "Widget class"
#define en__Auto2561   ""
#define fr__Auto2561   ""
#define it__Auto2561   ""
#define es__Auto2561   ""
#define de__Auto2561   ""
#define nl__Auto2561   ""
#define pt__Auto2561   ""
#define xx__Auto2561   ""
#define en_Auto2562   "Format"
#define fr_Auto2562   "Format"
#define it_Auto2562   "Format"
#define es_Auto2562   "Format"
#define de_Auto2562   "Format"
#define nl_Auto2562   "Format"
#define pt_Auto2562   "Format"
#define xx_Auto2562   "Format"
#define en__Auto2562   ""
#define fr__Auto2562   ""
#define it__Auto2562   ""
#define es__Auto2562   ""
#define de__Auto2562   ""
#define nl__Auto2562   ""
#define pt__Auto2562   ""
#define xx__Auto2562   ""
#include "vwform.h"
static int	vfh[16];
private int on_fgSelect_event(struct vwform_context * _Context);

/*	------------------------	*/
/*	p o s i t i o n _ a t ()	*/
/*	------------------------	*/
void	vwform_position_at(struct vwform_context * _Context,int x, int y){
	_Context->x_WidgetProperties=x;
	_Context->y_WidgetProperties=y;

}

/*	----------------	*/
/*	S e t V a r s ()	*/
/*	----------------	*/
void	vwform_SetVars(struct vwform_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	visual_signature("WWWW","WWWW");
	visual_transferin(_Context->buffer_AtX,7,pSpecificWidgetProperties->pAtX);
	visual_transferin(_Context->buffer_AtY,7,pSpecificWidgetProperties->pAtY);
	visual_transferin(_Context->buffer_Width,7,pSpecificWidgetProperties->pWidth);
	visual_transferin(_Context->buffer_Height,7,pSpecificWidgetProperties->pHeight);
	if(!(pSpecificWidgetProperties->pTextFont))
	_Context->value_TextFont=0;
	else _Context->value_TextFont=*((int*)pSpecificWidgetProperties->pTextFont);
	visual_signature("WWSSS","WWSSS");
	visual_transferin(_Context->buffer_TextColour,6,pSpecificWidgetProperties->pTextColour);
	visual_transferin(_Context->buffer_Background,6,pSpecificWidgetProperties->pBackground);
	visual_transferin(_Context->buffer_PayLoad,255,pSpecificWidgetProperties->pPayLoad);
	visual_transferin(_Context->buffer_Identity,255,pSpecificWidgetProperties->pIdentity);
	visual_transferin(_Context->buffer_Format,255,pSpecificWidgetProperties->pFormat);
	visual_signature("SS","SS");
	visual_transferin(_Context->buffer_StyleSheet,255,pSpecificWidgetProperties->pStyleSheet);
	visual_transferin(_Context->buffer_Hint,255,pSpecificWidgetProperties->pHint);
	if(!(pSpecificWidgetProperties->pWidgetClass))
	_Context->value_WidgetClass=0;
	else _Context->value_WidgetClass=*((int*)pSpecificWidgetProperties->pWidgetClass);
	if(!(pSpecificWidgetProperties->pType))
	_Context->value_WidgetStorage=0;
	else _Context->value_WidgetStorage=*((int*)pSpecificWidgetProperties->pType);
	if(!(pSpecificWidgetProperties->pAlign))
	_Context->value_Align=0;
	else _Context->value_Align=*((int*)pSpecificWidgetProperties->pAlign);
	if(!(pSpecificWidgetProperties->pIsBold))
	_Context->value_IsBold=0;
	else _Context->value_IsBold=*((int*)pSpecificWidgetProperties->pIsBold);
	if(!(pSpecificWidgetProperties->pIsUnderline))
	_Context->value_IsUnderline=0;
	else _Context->value_IsUnderline=*((int*)pSpecificWidgetProperties->pIsUnderline);
	if(!(pSpecificWidgetProperties->pIsShadow))
	_Context->value_IsShadow=0;
	else _Context->value_IsShadow=*((int*)pSpecificWidgetProperties->pIsShadow);
	if(!(pSpecificWidgetProperties->pIsLock))
	_Context->value_IsLock=0;
	else _Context->value_IsLock=*((int*)pSpecificWidgetProperties->pIsLock);
	if(!(pSpecificWidgetProperties->pIsSpecial))
	_Context->value_Compact=0;
	else _Context->value_Compact=*((int*)pSpecificWidgetProperties->pIsSpecial);
	if(!(pSpecificWidgetProperties->pIsSpecial2))
	_Context->value_LineFocus=0;
	else _Context->value_LineFocus=*((int*)pSpecificWidgetProperties->pIsSpecial2);
	if(!(pSpecificWidgetProperties->pIswResize))
	_Context->value_IswResize=0;
	else _Context->value_IswResize=*((int*)pSpecificWidgetProperties->pIswResize);
	if(!(pSpecificWidgetProperties->pIshResize))
	_Context->value_IshResize=0;
	else _Context->value_IshResize=*((int*)pSpecificWidgetProperties->pIshResize);

}

/*	----------------	*/
/*	G e t V a r s ()	*/
/*	----------------	*/
void	vwform_GetVars(struct vwform_context * _Context){
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
	visual_transferout(_Context->buffer_PayLoad,255,pSpecificWidgetProperties->pPayLoad);
	visual_transferout(_Context->buffer_Identity,255,pSpecificWidgetProperties->pIdentity);
	visual_transferout(_Context->buffer_Format,255,pSpecificWidgetProperties->pFormat);
	visual_signature("SS","SS");
	visual_transferout(_Context->buffer_StyleSheet,255,pSpecificWidgetProperties->pStyleSheet);
	visual_transferout(_Context->buffer_Hint,255,pSpecificWidgetProperties->pHint);
	if(pSpecificWidgetProperties->pWidgetClass!=(char*)0)
	*((int*)pSpecificWidgetProperties->pWidgetClass)=_Context->value_WidgetClass;
	if(pSpecificWidgetProperties->pType!=(char*)0)
	*((int*)pSpecificWidgetProperties->pType)=_Context->value_WidgetStorage;
	if(pSpecificWidgetProperties->pAlign!=(char*)0)
	*((int*)pSpecificWidgetProperties->pAlign)=_Context->value_Align;
	if(pSpecificWidgetProperties->pIsBold!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsBold)=_Context->value_IsBold;
	if(pSpecificWidgetProperties->pIsUnderline!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsUnderline)=_Context->value_IsUnderline;
	if(pSpecificWidgetProperties->pIsShadow!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsShadow)=_Context->value_IsShadow;
	if(pSpecificWidgetProperties->pIsLock!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsLock)=_Context->value_IsLock;
	if(pSpecificWidgetProperties->pIsSpecial!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsSpecial)=_Context->value_Compact;
	if(pSpecificWidgetProperties->pIsSpecial2!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsSpecial2)=_Context->value_LineFocus;
	if(pSpecificWidgetProperties->pIswResize!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIswResize)=_Context->value_IswResize;
	if(pSpecificWidgetProperties->pIshResize!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIshResize)=_Context->value_IshResize;

}

public	int	vwform_attach()
{
	if ( visual_initialise(3|512) == -1 )
		return(56);

	else	{
		visual_palette("/home/abal3/images/standard.rgb",31);
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
		vfh[10] = visual_font("bmap0416.fmf",12);
		initialise_mouse();
		}
	return(0);
}

public	int	vwform_attach_mode(int mode)
{
	if ( visual_initialise(3|mode) == -1 )
		return(56);

	else	{
		visual_palette("/home/abal3/images/standard.rgb",31);
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
		vfh[10] = visual_font("bmap0416.fmf",12);
		initialise_mouse();
		}
	return(0);
}

public	int	vwform_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	vwform_create(struct vwform_context **cptr)
{

	int i;
	struct vwform_context * _Context=(struct vwform_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("bmap0416.fmf",12);
	if (!(_Context = allocate( sizeof( struct vwform_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=25;
		for (i=0; i < 255; i++)  *(_Context->buffer_Identity+i)=' ';
		_Context->value_WidgetStorage=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Hint+i)=' ';
		_Context->value_IsLock=0;
		for (i=0; i < 7; i++)  *(_Context->buffer_AtX+i)=' ';
		_Context->value_TextFont=0;
		for (i=0; i < 7; i++)  *(_Context->buffer_AtY+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Width+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Height+i)=' ';
		_Context->value_Align=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_PayLoad+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_StyleSheet+i)=' ';
		for (i=0; i < 6; i++)  *(_Context->buffer_TextColour+i)=' ';
		for (i=0; i < 6; i++)  *(_Context->buffer_Background+i)=' ';
		_Context->value_IsBold=0;
		_Context->value_Compact=0;
		_Context->value_LineFocus=0;
		_Context->value_IsUnderline=0;
		_Context->value_IsShadow=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Format+i)=' ';
		_Context->value_IswResize=0;
		_Context->value_IshResize=0;
		_Context->value_WidgetClass=0;
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
	_Context->hint_WidgetProperties[1]=fr__WidgetProperties;
	_Context->hint_WidgetProperties[2]=it__WidgetProperties;
	_Context->hint_WidgetProperties[3]=es__WidgetProperties;
	_Context->hint_WidgetProperties[4]=de__WidgetProperties;
	_Context->hint_WidgetProperties[5]=nl__WidgetProperties;
	_Context->hint_WidgetProperties[6]=pt__WidgetProperties;
	_Context->hint_WidgetProperties[7]=xx__WidgetProperties;
	_Context->x_WidgetProperties=0;
	_Context->y_WidgetProperties=0;
	_Context->w_WidgetProperties=670;
	_Context->h_WidgetProperties=400;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2543[i]=" ";
	_Context->msg_Auto2543[0]=en_Auto2543;
	_Context->msg_Auto2543[1]=fr_Auto2543;
	_Context->msg_Auto2543[2]=it_Auto2543;
	_Context->msg_Auto2543[3]=es_Auto2543;
	_Context->msg_Auto2543[4]=de_Auto2543;
	_Context->msg_Auto2543[5]=nl_Auto2543;
	_Context->msg_Auto2543[6]=pt_Auto2543;
	_Context->msg_Auto2543[7]=xx_Auto2543;
	_Context->hint_Auto2543[0]=en__Auto2543;
	_Context->hint_Auto2543[1]=fr__Auto2543;
	_Context->hint_Auto2543[2]=it__Auto2543;
	_Context->hint_Auto2543[3]=es__Auto2543;
	_Context->hint_Auto2543[4]=de__Auto2543;
	_Context->hint_Auto2543[5]=nl__Auto2543;
	_Context->hint_Auto2543[6]=pt__Auto2543;
	_Context->hint_Auto2543[7]=xx__Auto2543;
	for (i=0; i < 8; i++)_Context->msg_Auto2545[i]=" ";
	_Context->msg_Auto2545[0]=en_Auto2545;
	_Context->msg_Auto2545[1]=fr_Auto2545;
	_Context->msg_Auto2545[2]=it_Auto2545;
	_Context->msg_Auto2545[3]=es_Auto2545;
	_Context->msg_Auto2545[4]=de_Auto2545;
	_Context->msg_Auto2545[5]=nl_Auto2545;
	_Context->msg_Auto2545[6]=pt_Auto2545;
	_Context->msg_Auto2545[7]=xx_Auto2545;
	_Context->hint_Auto2545[0]=en__Auto2545;
	_Context->hint_Auto2545[1]=fr__Auto2545;
	_Context->hint_Auto2545[2]=it__Auto2545;
	_Context->hint_Auto2545[3]=es__Auto2545;
	_Context->hint_Auto2545[4]=de__Auto2545;
	_Context->hint_Auto2545[5]=nl__Auto2545;
	_Context->hint_Auto2545[6]=pt__Auto2545;
	_Context->hint_Auto2545[7]=xx__Auto2545;
	for (i=0; i < 8; i++)_Context->msg_Auto2546[i]=" ";
	_Context->msg_Auto2546[0]=en_Auto2546;
	_Context->msg_Auto2546[1]=fr_Auto2546;
	_Context->msg_Auto2546[2]=it_Auto2546;
	_Context->msg_Auto2546[3]=es_Auto2546;
	_Context->msg_Auto2546[4]=de_Auto2546;
	_Context->msg_Auto2546[5]=nl_Auto2546;
	_Context->msg_Auto2546[6]=pt_Auto2546;
	_Context->msg_Auto2546[7]=xx_Auto2546;
	_Context->hint_Auto2546[0]=en__Auto2546;
	_Context->hint_Auto2546[1]=fr__Auto2546;
	_Context->hint_Auto2546[2]=it__Auto2546;
	_Context->hint_Auto2546[3]=es__Auto2546;
	_Context->hint_Auto2546[4]=de__Auto2546;
	_Context->hint_Auto2546[5]=nl__Auto2546;
	_Context->hint_Auto2546[6]=pt__Auto2546;
	_Context->hint_Auto2546[7]=xx__Auto2546;
	for (i=0; i < 8; i++)_Context->msg_Auto2547[i]=" ";
	_Context->msg_Auto2547[0]=en_Auto2547;
	_Context->msg_Auto2547[1]=fr_Auto2547;
	_Context->msg_Auto2547[2]=it_Auto2547;
	_Context->msg_Auto2547[3]=es_Auto2547;
	_Context->msg_Auto2547[4]=de_Auto2547;
	_Context->msg_Auto2547[5]=nl_Auto2547;
	_Context->msg_Auto2547[6]=pt_Auto2547;
	_Context->msg_Auto2547[7]=xx_Auto2547;
	_Context->hint_Auto2547[0]=en__Auto2547;
	_Context->hint_Auto2547[1]=fr__Auto2547;
	_Context->hint_Auto2547[2]=it__Auto2547;
	_Context->hint_Auto2547[3]=es__Auto2547;
	_Context->hint_Auto2547[4]=de__Auto2547;
	_Context->hint_Auto2547[5]=nl__Auto2547;
	_Context->hint_Auto2547[6]=pt__Auto2547;
	_Context->hint_Auto2547[7]=xx__Auto2547;
	_Context->hint_Identity[0]=en__Identity;
	for (i=0; i < 8; i++)_Context->msg_WidgetStorage[i]=" ";
	_Context->hint_WidgetStorage[0]=en__WidgetStorage;
	_Context->hint_WidgetStorage[1]=fr__WidgetStorage;
	_Context->hint_Hint[0]=en__Hint;
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
	_Context->hint_IsLock[1]=fr__IsLock;
	_Context->hint_IsLock[2]=it__IsLock;
	_Context->hint_IsLock[3]=es__IsLock;
	_Context->hint_IsLock[4]=de__IsLock;
	_Context->hint_IsLock[5]=nl__IsLock;
	_Context->hint_IsLock[6]=pt__IsLock;
	_Context->hint_IsLock[7]=xx__IsLock;
	_Context->hint_AtX[0]=en__AtX;
	for (i=0; i < 8; i++)_Context->msg_TextFont[i]=" ";
	_Context->hint_TextFont[0]=en__TextFont;
	_Context->hint_TextFont[1]=fr__TextFont;
	_Context->hint_AtY[0]=en__AtY;
	_Context->hint_Width[0]=en__Width;
	_Context->hint_Height[0]=en__Height;
	for (i=0; i < 8; i++)_Context->msg_Align[i]=" ";
	_Context->hint_Align[0]=en__Align;
	_Context->hint_Align[1]=fr__Align;
	_Context->hint_Align[2]=it__Align;
	_Context->hint_Align[3]=es__Align;
	_Context->hint_Align[4]=de__Align;
	_Context->hint_Align[5]=nl__Align;
	_Context->hint_Align[6]=pt__Align;
	_Context->hint_Align[7]=xx__Align;
	_Context->hint_PayLoad[0]=en__PayLoad;
	_Context->hint_PayLoad[1]=fr__PayLoad;
	_Context->hint_StyleSheet[0]=en__StyleSheet;
	_Context->hint_StyleSheet[1]=fr__StyleSheet;
	_Context->hint_TextColour[0]=en__TextColour;
	_Context->hint_Background[0]=en__Background;
	for (i=0; i < 8; i++)_Context->msg_IsBold[i]=" ";
	_Context->msg_IsBold[0]=en_IsBold;
	_Context->msg_IsBold[1]=fr_IsBold;
	_Context->msg_IsBold[2]=it_IsBold;
	_Context->msg_IsBold[3]=es_IsBold;
	_Context->msg_IsBold[4]=de_IsBold;
	_Context->msg_IsBold[5]=nl_IsBold;
	_Context->msg_IsBold[6]=pt_IsBold;
	_Context->msg_IsBold[7]=xx_IsBold;
	_Context->hint_IsBold[0]=en__IsBold;
	_Context->hint_IsBold[1]=fr__IsBold;
	_Context->hint_IsBold[2]=it__IsBold;
	_Context->hint_IsBold[3]=es__IsBold;
	_Context->hint_IsBold[4]=de__IsBold;
	_Context->hint_IsBold[5]=nl__IsBold;
	_Context->hint_IsBold[6]=pt__IsBold;
	_Context->hint_IsBold[7]=xx__IsBold;
	for (i=0; i < 8; i++)_Context->msg_Compact[i]=" ";
	_Context->msg_Compact[0]=en_Compact;
	_Context->msg_Compact[1]=fr_Compact;
	_Context->msg_Compact[2]=it_Compact;
	_Context->msg_Compact[3]=es_Compact;
	_Context->msg_Compact[4]=de_Compact;
	_Context->msg_Compact[5]=nl_Compact;
	_Context->msg_Compact[6]=pt_Compact;
	_Context->msg_Compact[7]=xx_Compact;
	_Context->hint_Compact[0]=en__Compact;
	_Context->hint_Compact[1]=fr__Compact;
	_Context->hint_Compact[2]=it__Compact;
	_Context->hint_Compact[3]=es__Compact;
	_Context->hint_Compact[4]=de__Compact;
	_Context->hint_Compact[5]=nl__Compact;
	_Context->hint_Compact[6]=pt__Compact;
	_Context->hint_Compact[7]=xx__Compact;
	for (i=0; i < 8; i++)_Context->msg_LineFocus[i]=" ";
	_Context->msg_LineFocus[0]=en_LineFocus;
	_Context->msg_LineFocus[1]=fr_LineFocus;
	_Context->msg_LineFocus[2]=it_LineFocus;
	_Context->msg_LineFocus[3]=es_LineFocus;
	_Context->msg_LineFocus[4]=de_LineFocus;
	_Context->msg_LineFocus[5]=nl_LineFocus;
	_Context->msg_LineFocus[6]=pt_LineFocus;
	_Context->msg_LineFocus[7]=xx_LineFocus;
	_Context->hint_LineFocus[0]=en__LineFocus;
	_Context->hint_LineFocus[1]=fr__LineFocus;
	_Context->hint_LineFocus[2]=it__LineFocus;
	_Context->hint_LineFocus[3]=es__LineFocus;
	_Context->hint_LineFocus[4]=de__LineFocus;
	_Context->hint_LineFocus[5]=nl__LineFocus;
	_Context->hint_LineFocus[6]=pt__LineFocus;
	_Context->hint_LineFocus[7]=xx__LineFocus;
	for (i=0; i < 8; i++)_Context->msg_IsUnderline[i]=" ";
	_Context->msg_IsUnderline[0]=en_IsUnderline;
	_Context->msg_IsUnderline[1]=fr_IsUnderline;
	_Context->msg_IsUnderline[2]=it_IsUnderline;
	_Context->msg_IsUnderline[3]=es_IsUnderline;
	_Context->msg_IsUnderline[4]=de_IsUnderline;
	_Context->msg_IsUnderline[5]=nl_IsUnderline;
	_Context->msg_IsUnderline[6]=pt_IsUnderline;
	_Context->msg_IsUnderline[7]=xx_IsUnderline;
	_Context->hint_IsUnderline[0]=en__IsUnderline;
	_Context->hint_IsUnderline[1]=fr__IsUnderline;
	_Context->hint_IsUnderline[2]=it__IsUnderline;
	_Context->hint_IsUnderline[3]=es__IsUnderline;
	_Context->hint_IsUnderline[4]=de__IsUnderline;
	_Context->hint_IsUnderline[5]=nl__IsUnderline;
	_Context->hint_IsUnderline[6]=pt__IsUnderline;
	_Context->hint_IsUnderline[7]=xx__IsUnderline;
	for (i=0; i < 8; i++)_Context->msg_IsShadow[i]=" ";
	_Context->msg_IsShadow[0]=en_IsShadow;
	_Context->msg_IsShadow[1]=fr_IsShadow;
	_Context->msg_IsShadow[2]=it_IsShadow;
	_Context->msg_IsShadow[3]=es_IsShadow;
	_Context->msg_IsShadow[4]=de_IsShadow;
	_Context->msg_IsShadow[5]=nl_IsShadow;
	_Context->msg_IsShadow[6]=pt_IsShadow;
	_Context->msg_IsShadow[7]=xx_IsShadow;
	_Context->hint_IsShadow[0]=en__IsShadow;
	_Context->hint_IsShadow[1]=fr__IsShadow;
	_Context->hint_IsShadow[2]=it__IsShadow;
	_Context->hint_IsShadow[3]=es__IsShadow;
	_Context->hint_IsShadow[4]=de__IsShadow;
	_Context->hint_IsShadow[5]=nl__IsShadow;
	_Context->hint_IsShadow[6]=pt__IsShadow;
	_Context->hint_IsShadow[7]=xx__IsShadow;
	_Context->hint_Format[0]=en__Format;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2548[i]=" ";
	_Context->msg_Auto2548[0]=en_Auto2548;
	_Context->msg_Auto2548[1]=fr_Auto2548;
	_Context->msg_Auto2548[2]=it_Auto2548;
	_Context->msg_Auto2548[3]=es_Auto2548;
	_Context->msg_Auto2548[4]=de_Auto2548;
	_Context->msg_Auto2548[5]=nl_Auto2548;
	_Context->msg_Auto2548[6]=pt_Auto2548;
	_Context->msg_Auto2548[7]=xx_Auto2548;
	_Context->hint_Auto2548[0]=en__Auto2548;
	_Context->hint_Auto2548[1]=fr__Auto2548;
	_Context->hint_Auto2548[2]=it__Auto2548;
	_Context->hint_Auto2548[3]=es__Auto2548;
	_Context->hint_Auto2548[4]=de__Auto2548;
	_Context->hint_Auto2548[5]=nl__Auto2548;
	_Context->hint_Auto2548[6]=pt__Auto2548;
	_Context->hint_Auto2548[7]=xx__Auto2548;
	for (i=0; i < 8; i++)_Context->msg_Auto2549[i]=" ";
	_Context->msg_Auto2549[0]=en_Auto2549;
	_Context->msg_Auto2549[1]=fr_Auto2549;
	_Context->msg_Auto2549[2]=it_Auto2549;
	_Context->msg_Auto2549[3]=es_Auto2549;
	_Context->msg_Auto2549[4]=de_Auto2549;
	_Context->msg_Auto2549[5]=nl_Auto2549;
	_Context->msg_Auto2549[6]=pt_Auto2549;
	_Context->msg_Auto2549[7]=xx_Auto2549;
	_Context->hint_Auto2549[0]=en__Auto2549;
	_Context->hint_Auto2549[1]=fr__Auto2549;
	_Context->hint_Auto2549[2]=it__Auto2549;
	_Context->hint_Auto2549[3]=es__Auto2549;
	_Context->hint_Auto2549[4]=de__Auto2549;
	_Context->hint_Auto2549[5]=nl__Auto2549;
	_Context->hint_Auto2549[6]=pt__Auto2549;
	_Context->hint_Auto2549[7]=xx__Auto2549;
	for (i=0; i < 8; i++)_Context->msg_Auto2550[i]=" ";
	_Context->msg_Auto2550[0]=en_Auto2550;
	_Context->msg_Auto2550[1]=fr_Auto2550;
	_Context->msg_Auto2550[2]=it_Auto2550;
	_Context->msg_Auto2550[3]=es_Auto2550;
	_Context->msg_Auto2550[4]=de_Auto2550;
	_Context->msg_Auto2550[5]=nl_Auto2550;
	_Context->msg_Auto2550[6]=pt_Auto2550;
	_Context->msg_Auto2550[7]=xx_Auto2550;
	_Context->hint_Auto2550[0]=en__Auto2550;
	_Context->hint_Auto2550[1]=fr__Auto2550;
	_Context->hint_Auto2550[2]=it__Auto2550;
	_Context->hint_Auto2550[3]=es__Auto2550;
	_Context->hint_Auto2550[4]=de__Auto2550;
	_Context->hint_Auto2550[5]=nl__Auto2550;
	_Context->hint_Auto2550[6]=pt__Auto2550;
	_Context->hint_Auto2550[7]=xx__Auto2550;
	for (i=0; i < 8; i++)_Context->msg_Auto2551[i]=" ";
	_Context->msg_Auto2551[0]=en_Auto2551;
	_Context->msg_Auto2551[1]=fr_Auto2551;
	_Context->msg_Auto2551[2]=it_Auto2551;
	_Context->msg_Auto2551[3]=es_Auto2551;
	_Context->msg_Auto2551[4]=de_Auto2551;
	_Context->msg_Auto2551[5]=nl_Auto2551;
	_Context->msg_Auto2551[6]=pt_Auto2551;
	_Context->msg_Auto2551[7]=xx_Auto2551;
	_Context->hint_Auto2551[0]=en__Auto2551;
	_Context->hint_Auto2551[1]=fr__Auto2551;
	_Context->hint_Auto2551[2]=it__Auto2551;
	_Context->hint_Auto2551[3]=es__Auto2551;
	_Context->hint_Auto2551[4]=de__Auto2551;
	_Context->hint_Auto2551[5]=nl__Auto2551;
	_Context->hint_Auto2551[6]=pt__Auto2551;
	_Context->hint_Auto2551[7]=xx__Auto2551;
	for (i=0; i < 8; i++)_Context->msg_Auto2552[i]=" ";
	_Context->msg_Auto2552[0]=en_Auto2552;
	_Context->msg_Auto2552[1]=fr_Auto2552;
	_Context->msg_Auto2552[2]=it_Auto2552;
	_Context->msg_Auto2552[3]=es_Auto2552;
	_Context->msg_Auto2552[4]=de_Auto2552;
	_Context->msg_Auto2552[5]=nl_Auto2552;
	_Context->msg_Auto2552[6]=pt_Auto2552;
	_Context->msg_Auto2552[7]=xx_Auto2552;
	_Context->hint_Auto2552[0]=en__Auto2552;
	_Context->hint_Auto2552[1]=fr__Auto2552;
	_Context->hint_Auto2552[2]=it__Auto2552;
	_Context->hint_Auto2552[3]=es__Auto2552;
	_Context->hint_Auto2552[4]=de__Auto2552;
	_Context->hint_Auto2552[5]=nl__Auto2552;
	_Context->hint_Auto2552[6]=pt__Auto2552;
	_Context->hint_Auto2552[7]=xx__Auto2552;
	for (i=0; i < 8; i++)_Context->msg_Auto2553[i]=" ";
	_Context->msg_Auto2553[0]=en_Auto2553;
	_Context->msg_Auto2553[1]=fr_Auto2553;
	_Context->msg_Auto2553[2]=it_Auto2553;
	_Context->msg_Auto2553[3]=es_Auto2553;
	_Context->msg_Auto2553[4]=de_Auto2553;
	_Context->msg_Auto2553[5]=nl_Auto2553;
	_Context->msg_Auto2553[6]=pt_Auto2553;
	_Context->msg_Auto2553[7]=xx_Auto2553;
	_Context->hint_Auto2553[0]=en__Auto2553;
	_Context->hint_Auto2553[1]=fr__Auto2553;
	_Context->hint_Auto2553[2]=it__Auto2553;
	_Context->hint_Auto2553[3]=es__Auto2553;
	_Context->hint_Auto2553[4]=de__Auto2553;
	_Context->hint_Auto2553[5]=nl__Auto2553;
	_Context->hint_Auto2553[6]=pt__Auto2553;
	_Context->hint_Auto2553[7]=xx__Auto2553;
	for (i=0; i < 8; i++)_Context->msg_Auto2554[i]=" ";
	_Context->msg_Auto2554[0]=en_Auto2554;
	_Context->msg_Auto2554[1]=fr_Auto2554;
	_Context->msg_Auto2554[2]=it_Auto2554;
	_Context->msg_Auto2554[3]=es_Auto2554;
	_Context->msg_Auto2554[4]=de_Auto2554;
	_Context->msg_Auto2554[5]=nl_Auto2554;
	_Context->msg_Auto2554[6]=pt_Auto2554;
	_Context->msg_Auto2554[7]=xx_Auto2554;
	_Context->hint_Auto2554[0]=en__Auto2554;
	_Context->hint_Auto2554[1]=fr__Auto2554;
	_Context->hint_Auto2554[2]=it__Auto2554;
	_Context->hint_Auto2554[3]=es__Auto2554;
	_Context->hint_Auto2554[4]=de__Auto2554;
	_Context->hint_Auto2554[5]=nl__Auto2554;
	_Context->hint_Auto2554[6]=pt__Auto2554;
	_Context->hint_Auto2554[7]=xx__Auto2554;
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
	_Context->hint_fgSelect[1]=fr__fgSelect;
	_Context->hint_fgSelect[2]=it__fgSelect;
	_Context->hint_fgSelect[3]=es__fgSelect;
	_Context->hint_fgSelect[4]=de__fgSelect;
	_Context->hint_fgSelect[5]=nl__fgSelect;
	_Context->hint_fgSelect[6]=pt__fgSelect;
	_Context->hint_fgSelect[7]=xx__fgSelect;
	for (i=0; i < 8; i++)_Context->msg_Auto2555[i]=" ";
	_Context->msg_Auto2555[0]=en_Auto2555;
	_Context->msg_Auto2555[1]=fr_Auto2555;
	_Context->msg_Auto2555[2]=it_Auto2555;
	_Context->msg_Auto2555[3]=es_Auto2555;
	_Context->msg_Auto2555[4]=de_Auto2555;
	_Context->msg_Auto2555[5]=nl_Auto2555;
	_Context->msg_Auto2555[6]=pt_Auto2555;
	_Context->msg_Auto2555[7]=xx_Auto2555;
	_Context->hint_Auto2555[0]=en__Auto2555;
	_Context->hint_Auto2555[1]=fr__Auto2555;
	_Context->hint_Auto2555[2]=it__Auto2555;
	_Context->hint_Auto2555[3]=es__Auto2555;
	_Context->hint_Auto2555[4]=de__Auto2555;
	_Context->hint_Auto2555[5]=nl__Auto2555;
	_Context->hint_Auto2555[6]=pt__Auto2555;
	_Context->hint_Auto2555[7]=xx__Auto2555;
	for (i=0; i < 8; i++)_Context->msg_Auto2556[i]=" ";
	_Context->msg_Auto2556[0]=en_Auto2556;
	_Context->msg_Auto2556[1]=fr_Auto2556;
	_Context->msg_Auto2556[2]=it_Auto2556;
	_Context->msg_Auto2556[3]=es_Auto2556;
	_Context->msg_Auto2556[4]=de_Auto2556;
	_Context->msg_Auto2556[5]=nl_Auto2556;
	_Context->msg_Auto2556[6]=pt_Auto2556;
	_Context->msg_Auto2556[7]=xx_Auto2556;
	_Context->hint_Auto2556[0]=en__Auto2556;
	_Context->hint_Auto2556[1]=fr__Auto2556;
	_Context->hint_Auto2556[2]=it__Auto2556;
	_Context->hint_Auto2556[3]=es__Auto2556;
	_Context->hint_Auto2556[4]=de__Auto2556;
	_Context->hint_Auto2556[5]=nl__Auto2556;
	_Context->hint_Auto2556[6]=pt__Auto2556;
	_Context->hint_Auto2556[7]=xx__Auto2556;
	for (i=0; i < 8; i++)_Context->msg_Auto2557[i]=" ";
	_Context->msg_Auto2557[0]=en_Auto2557;
	_Context->msg_Auto2557[1]=fr_Auto2557;
	_Context->msg_Auto2557[2]=it_Auto2557;
	_Context->msg_Auto2557[3]=es_Auto2557;
	_Context->msg_Auto2557[4]=de_Auto2557;
	_Context->msg_Auto2557[5]=nl_Auto2557;
	_Context->msg_Auto2557[6]=pt_Auto2557;
	_Context->msg_Auto2557[7]=xx_Auto2557;
	_Context->hint_Auto2557[0]=en__Auto2557;
	_Context->hint_Auto2557[1]=fr__Auto2557;
	_Context->hint_Auto2557[2]=it__Auto2557;
	_Context->hint_Auto2557[3]=es__Auto2557;
	_Context->hint_Auto2557[4]=de__Auto2557;
	_Context->hint_Auto2557[5]=nl__Auto2557;
	_Context->hint_Auto2557[6]=pt__Auto2557;
	_Context->hint_Auto2557[7]=xx__Auto2557;
	for (i=0; i < 8; i++)_Context->msg_WidgetClass[i]=" ";
	_Context->hint_WidgetClass[0]=en__WidgetClass;
	for (i=0; i < 8; i++)_Context->msg_Auto2558[i]=" ";
	_Context->msg_Auto2558[0]=en_Auto2558;
	_Context->msg_Auto2558[1]=fr_Auto2558;
	_Context->msg_Auto2558[2]=it_Auto2558;
	_Context->msg_Auto2558[3]=es_Auto2558;
	_Context->msg_Auto2558[4]=de_Auto2558;
	_Context->msg_Auto2558[5]=nl_Auto2558;
	_Context->msg_Auto2558[6]=pt_Auto2558;
	_Context->msg_Auto2558[7]=xx_Auto2558;
	_Context->hint_Auto2558[0]=en__Auto2558;
	_Context->hint_Auto2558[1]=fr__Auto2558;
	_Context->hint_Auto2558[2]=it__Auto2558;
	_Context->hint_Auto2558[3]=es__Auto2558;
	_Context->hint_Auto2558[4]=de__Auto2558;
	_Context->hint_Auto2558[5]=nl__Auto2558;
	_Context->hint_Auto2558[6]=pt__Auto2558;
	_Context->hint_Auto2558[7]=xx__Auto2558;
	for (i=0; i < 8; i++)_Context->msg_Auto2559[i]=" ";
	_Context->msg_Auto2559[0]=en_Auto2559;
	_Context->msg_Auto2559[1]=fr_Auto2559;
	_Context->msg_Auto2559[2]=it_Auto2559;
	_Context->msg_Auto2559[3]=es_Auto2559;
	_Context->msg_Auto2559[4]=de_Auto2559;
	_Context->msg_Auto2559[5]=nl_Auto2559;
	_Context->msg_Auto2559[6]=pt_Auto2559;
	_Context->msg_Auto2559[7]=xx_Auto2559;
	_Context->hint_Auto2559[0]=en__Auto2559;
	_Context->hint_Auto2559[1]=fr__Auto2559;
	_Context->hint_Auto2559[2]=it__Auto2559;
	_Context->hint_Auto2559[3]=es__Auto2559;
	_Context->hint_Auto2559[4]=de__Auto2559;
	_Context->hint_Auto2559[5]=nl__Auto2559;
	_Context->hint_Auto2559[6]=pt__Auto2559;
	_Context->hint_Auto2559[7]=xx__Auto2559;
	for (i=0; i < 8; i++)_Context->msg_Auto2560[i]=" ";
	_Context->msg_Auto2560[0]=en_Auto2560;
	_Context->msg_Auto2560[1]=fr_Auto2560;
	_Context->msg_Auto2560[2]=it_Auto2560;
	_Context->msg_Auto2560[3]=es_Auto2560;
	_Context->msg_Auto2560[4]=de_Auto2560;
	_Context->msg_Auto2560[5]=nl_Auto2560;
	_Context->msg_Auto2560[6]=pt_Auto2560;
	_Context->msg_Auto2560[7]=xx_Auto2560;
	_Context->hint_Auto2560[0]=en__Auto2560;
	_Context->hint_Auto2560[1]=fr__Auto2560;
	_Context->hint_Auto2560[2]=it__Auto2560;
	_Context->hint_Auto2560[3]=es__Auto2560;
	_Context->hint_Auto2560[4]=de__Auto2560;
	_Context->hint_Auto2560[5]=nl__Auto2560;
	_Context->hint_Auto2560[6]=pt__Auto2560;
	_Context->hint_Auto2560[7]=xx__Auto2560;
	for (i=0; i < 8; i++)_Context->msg_Auto2561[i]=" ";
	_Context->msg_Auto2561[0]=en_Auto2561;
	_Context->msg_Auto2561[1]=fr_Auto2561;
	_Context->msg_Auto2561[2]=it_Auto2561;
	_Context->msg_Auto2561[3]=es_Auto2561;
	_Context->msg_Auto2561[4]=de_Auto2561;
	_Context->msg_Auto2561[5]=nl_Auto2561;
	_Context->msg_Auto2561[6]=pt_Auto2561;
	_Context->msg_Auto2561[7]=xx_Auto2561;
	_Context->hint_Auto2561[0]=en__Auto2561;
	_Context->hint_Auto2561[1]=fr__Auto2561;
	_Context->hint_Auto2561[2]=it__Auto2561;
	_Context->hint_Auto2561[3]=es__Auto2561;
	_Context->hint_Auto2561[4]=de__Auto2561;
	_Context->hint_Auto2561[5]=nl__Auto2561;
	_Context->hint_Auto2561[6]=pt__Auto2561;
	_Context->hint_Auto2561[7]=xx__Auto2561;
	for (i=0; i < 8; i++)_Context->msg_Auto2562[i]=" ";
	_Context->msg_Auto2562[0]=en_Auto2562;
	_Context->msg_Auto2562[1]=fr_Auto2562;
	_Context->msg_Auto2562[2]=it_Auto2562;
	_Context->msg_Auto2562[3]=es_Auto2562;
	_Context->msg_Auto2562[4]=de_Auto2562;
	_Context->msg_Auto2562[5]=nl_Auto2562;
	_Context->msg_Auto2562[6]=pt_Auto2562;
	_Context->msg_Auto2562[7]=xx_Auto2562;
	_Context->hint_Auto2562[0]=en__Auto2562;
	_Context->hint_Auto2562[1]=fr__Auto2562;
	_Context->hint_Auto2562[2]=it__Auto2562;
	_Context->hint_Auto2562[3]=es__Auto2562;
	_Context->hint_Auto2562[4]=de__Auto2562;
	_Context->hint_Auto2562[5]=nl__Auto2562;
	_Context->hint_Auto2562[6]=pt__Auto2562;
	_Context->hint_Auto2562[7]=xx__Auto2562;
	return(0);
}

public 	int	vwform_hide(struct vwform_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;

	return(result);
}

public	int	vwform_remove(struct vwform_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}

public	int	vwform_show(struct vwform_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,"widget_frame",_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]))) != 0)
) {
		visual_window(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,vfh[2],_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]),0x4);
		}
	visual_text(_Context->x_WidgetProperties+455,_Context->y_WidgetProperties+96,210,16,vfh[2],16,0,_Context->msg_Auto2543[_Context->language],strlen(_Context->msg_Auto2543[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+455,_Context->y_WidgetProperties+112,210,49,4);
	visual_filzone(_Context->x_WidgetProperties+269,_Context->y_WidgetProperties+193,1,1,27,0);
	visual_text(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+27,210,16,vfh[2],16,0,_Context->msg_Auto2545[_Context->language],strlen(_Context->msg_Auto2545[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+43,210,64,4);
	visual_text(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+165,657,16,vfh[2],16,0,_Context->msg_Auto2546[_Context->language],strlen(_Context->msg_Auto2546[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+181,657,210,4);
	visual_text(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+27,443,16,vfh[2],16,0,_Context->msg_Auto2547[_Context->language],strlen(_Context->msg_Auto2547[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+43,443,118,4);
	visual_frame(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+64,160+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+64+1,160,16,vfh[1],34,0,_Context->buffer_Identity,255,0);
	visual_select(_Context->x_WidgetProperties+179,_Context->y_WidgetProperties+64,140,112,vfh[2],0,0,parse_selection(WidgetTypeList,&_Context->value_WidgetStorage),768);
	visual_frame(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+101,424+2,48+2,5);
	visual_text(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+101+1,424,48,vfh[1],0,0,_Context->buffer_Hint,255,0);
	_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+464,_Context->y_WidgetProperties+63,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
	visual_frame(_Context->x_WidgetProperties+461,_Context->y_WidgetProperties+130,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+461+1,_Context->y_WidgetProperties+130+1,35,16,vfh[1],34,0,_Context->buffer_AtX,7,0);
	visual_select(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+208,126,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),768);
	visual_frame(_Context->x_WidgetProperties+505,_Context->y_WidgetProperties+129,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+505+1,_Context->y_WidgetProperties+129+1,35,16,vfh[1],34,0,_Context->buffer_AtY,7,0);
	visual_frame(_Context->x_WidgetProperties+566,_Context->y_WidgetProperties+130,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+566+1,_Context->y_WidgetProperties+130+1,35,16,vfh[1],34,0,_Context->buffer_Width,7,0);
	visual_frame(_Context->x_WidgetProperties+616,_Context->y_WidgetProperties+130,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+616+1,_Context->y_WidgetProperties+130+1,35,16,vfh[1],34,0,_Context->buffer_Height,7,0);
	visual_select(_Context->x_WidgetProperties+314,_Context->y_WidgetProperties+208,130,100,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),768);
	visual_frame(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+252,426+2,32+2,5);
	visual_text(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+252+1,426,32,vfh[1],34,0,_Context->buffer_PayLoad,255,0);
	visual_frame(_Context->x_WidgetProperties+464,_Context->y_WidgetProperties+208,190+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+464+1,_Context->y_WidgetProperties+208+1,190,16,vfh[1],0,0,_Context->buffer_StyleSheet,255,0);
	visual_frame(_Context->x_WidgetProperties+167,_Context->y_WidgetProperties+208,40+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+167+1,_Context->y_WidgetProperties+208+1,40,16,vfh[1],34,0,_Context->buffer_TextColour,6,0);
	visual_frame(_Context->x_WidgetProperties+257,_Context->y_WidgetProperties+208,42+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+257+1,_Context->y_WidgetProperties+208+1,42,16,vfh[1],34,0,_Context->buffer_Background,6,0);
	_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_WidgetProperties+467,_Context->y_WidgetProperties+317,180,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
	_Context->trigger_Compact=visual_trigger_code(_Context->msg_Compact[_Context->language],strlen(_Context->msg_Compact[_Context->language]));
	visual_check(_Context->x_WidgetProperties+467,_Context->y_WidgetProperties+338,168,16,vfh[2],175,0,_Context->msg_Compact[_Context->language],strlen(_Context->msg_Compact[_Context->language]),_Context->value_Compact|0);
	_Context->trigger_LineFocus=visual_trigger_code(_Context->msg_LineFocus[_Context->language],strlen(_Context->msg_LineFocus[_Context->language]));
	visual_check(_Context->x_WidgetProperties+467,_Context->y_WidgetProperties+358,168,16,vfh[2],175,0,_Context->msg_LineFocus[_Context->language],strlen(_Context->msg_LineFocus[_Context->language]),_Context->value_LineFocus|0);
	_Context->trigger_IsUnderline=visual_trigger_code(_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]));
	visual_check(_Context->x_WidgetProperties+466,_Context->y_WidgetProperties+251,180,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),_Context->value_IsUnderline|0);
	_Context->trigger_IsShadow=visual_trigger_code(_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]));
	visual_check(_Context->x_WidgetProperties+466,_Context->y_WidgetProperties+271,180,16,vfh[2],28,28,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),_Context->value_IsShadow|0);
	visual_frame(_Context->x_WidgetProperties+17,_Context->y_WidgetProperties+316,424+2,48+2,5);
	visual_text(_Context->x_WidgetProperties+17+1,_Context->y_WidgetProperties+316+1,424,48,vfh[1],27,0,_Context->buffer_Format,255,0);
	_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+17,_Context->y_WidgetProperties+369,168,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
	_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+288,_Context->y_WidgetProperties+369,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
	visual_text(_Context->x_WidgetProperties+462,_Context->y_WidgetProperties+116,14,21,vfh[2],16,0,_Context->msg_Auto2548[_Context->language],strlen(_Context->msg_Auto2548[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+616,_Context->y_WidgetProperties+115,50,21,vfh[2],16,0,_Context->msg_Auto2549[_Context->language],strlen(_Context->msg_Auto2549[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+566,_Context->y_WidgetProperties+115,50,21,vfh[2],16,0,_Context->msg_Auto2550[_Context->language],strlen(_Context->msg_Auto2550[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+504,_Context->y_WidgetProperties+116,14,21,vfh[2],16,0,_Context->msg_Auto2551[_Context->language],strlen(_Context->msg_Auto2551[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+194,150,16,vfh[2],16,0,_Context->msg_Auto2552[_Context->language],strlen(_Context->msg_Auto2552[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+237,98,16,vfh[2],16,0,_Context->msg_Auto2553[_Context->language],strlen(_Context->msg_Auto2553[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+168,_Context->y_WidgetProperties+193,42,16,vfh[2],16,0,_Context->msg_Auto2554[_Context->language],strlen(_Context->msg_Auto2554[_Context->language]),2);
	_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+211,_Context->y_WidgetProperties+208,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
	visual_text(_Context->x_WidgetProperties+256,_Context->y_WidgetProperties+193,42,16,vfh[2],16,0,_Context->msg_Auto2555[_Context->language],strlen(_Context->msg_Auto2555[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+465,_Context->y_WidgetProperties+194,182,16,vfh[2],16,0,_Context->msg_Auto2556[_Context->language],strlen(_Context->msg_Auto2556[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+88,168,16,vfh[2],16,0,_Context->msg_Auto2557[_Context->language],strlen(_Context->msg_Auto2557[_Context->language]),2);
	visual_select(_Context->x_WidgetProperties+324,_Context->y_WidgetProperties+64,112,128,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),768);
	visual_text(_Context->x_WidgetProperties+315,_Context->y_WidgetProperties+193,126,16,vfh[2],16,0,_Context->msg_Auto2558[_Context->language],strlen(_Context->msg_Auto2558[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+49,154,16,vfh[2],16,0,_Context->msg_Auto2559[_Context->language],strlen(_Context->msg_Auto2559[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+326,_Context->y_WidgetProperties+50,112,16,vfh[2],16,0,_Context->msg_Auto2560[_Context->language],strlen(_Context->msg_Auto2560[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+178,_Context->y_WidgetProperties+49,112,16,vfh[2],16,0,_Context->msg_Auto2561[_Context->language],strlen(_Context->msg_Auto2561[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+17,_Context->y_WidgetProperties+301,266,16,vfh[2],16,0,_Context->msg_Auto2562[_Context->language],strlen(_Context->msg_Auto2562[_Context->language]),2);
	visual_filzone(_Context->x_WidgetProperties+265,_Context->y_WidgetProperties+195,1,1,27,0);
	visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400);

	return(0);
}

private int Identity_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "Choose a name for the widget to be able to access its methods and ";
			mptr[1]="properties from other widgets. ";
			mptr[2]=" Un-named widgets are auto-identified and may change their names during ";
			mptr[3]="code production. ";
			mptr[4]=" Be careful not to reference autonamed widgets from within widget ";
			mptr[5]="or forms method instructions.      ";
			return(visual_online_help(mptr,6));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Nom du widget … utiliser dans le code source pour avoir accŠs aux ";
			mptr[1]="propri‚t‚s et m‚thodes du widget. ";
			mptr[2]=" Par d‚faut, Sing va donner un nom qui commence par Auto suivi d'un ";
			mptr[3]="num‚ro qui change … chaque production du formulaire. ";
			mptr[4]=" N'utilisez pas ce nom par d‚faut dans le code source.     ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int WidgetStorage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[20];
			mptr[0] = "This combo selection field allows the behaviour or action of the push ";
			mptr[1]="button widget to be define as can be seen below :  ";
			mptr[2]="  ";
			mptr[3]=" - Void      : this value indicates that the Event will contain code ";
			mptr[4]="to determine the action of the button.  ";
			mptr[5]=" - Overlay   : The TARGET property defines the name of the forms model ";
			mptr[6]="to be invoked as an OVERLAY object.  ";
			mptr[7]=" - Module    : The TARGET property defines the name of the forms model ";
			mptr[8]="to be invoked as a MODULE object.  ";
			mptr[9]=" - Chain     : The TARGET property defines the name of the forms model, ";
			mptr[10]="or the standard abal program, to be invoked by an abal CHAIN instruction. ";
			mptr[11]=" ";
			mptr[12]=" - Loadgo    : The TARGET property defines the name of the forms model, ";
			mptr[13]="or the standard abal program, to be invoked by an abal LOAD.GO instruction. ";
			mptr[14]=" ";
			mptr[15]=" - Hyperlink : The TARGET property defines the hypertext URL to be activated ";
			mptr[16]="using the standard system web browser.  ";
			mptr[17]=" - System    : The TARGET property defines the system command to be invoked ";
			mptr[18]="by the abal instruction LOAD.GO.  ";
			mptr[19]="      ";
			return(visual_online_help(mptr,20));
			}
			break;
		case 1 : 
			{
			char * mptr[20];
			mptr[0] = "Ce combo control permet de d‚finir le comportement des composant graphiques ";
			mptr[1]="de type bouton comme decrit ci-desous :  ";
			mptr[2]="  ";
			mptr[3]=" - Void      : Ceci indiques que le method Event permet de determiner ";
			mptr[4]="l'action exacte du bouton.  ";
			mptr[5]=" - Overlay   : Le propriŠt‚ CIBLE permet de definir le nom du formulaire ";
			mptr[6]="a activer en tant que objet OVERLAY d'abal.  ";
			mptr[7]=" - Module    :  Le propriŠt‚ CIBLE permet de definir le nom du formulaire ";
			mptr[8]="a activer en tant que MODULE d'abal.  ";
			mptr[9]=" - Chain     :  Le propriŠt‚ CIBLE permet de definir le nom du formulaire ";
			mptr[10]="ou le nom d'un program abal, a activer par l'instruction abal CHAIN. ";
			mptr[11]=" ";
			mptr[12]=" - Loadgo    :  Le propriŠt‚ CIBLE permet de definir le nom du formulaire ";
			mptr[13]="ou le nom d'un program abal, a activer par l'instruction abal LOAD.GO. ";
			mptr[14]=" ";
			mptr[15]=" - Hyperlink :  Le propriŠt‚ CIBLE permet de definir le nom du page html ";
			mptr[16]="a ouvrir avec le browser web standard du systeme.  ";
			mptr[17]=" - System    :  Le propriŠt‚ CIBLE permet de definir le nom de la commande ";
			mptr[18]="systeme a activer par l'instruction abal LOAD.GO.  ";
			mptr[19]="    ";
			return(visual_online_help(mptr,20));
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
			mptr[2]="form.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Zone d'‚dition dans laquelle vous pouvez ajoutez du texte pour avoir ";
			mptr[1]="plus  de d‚tails concernant le widget. ";
			mptr[2]=" Le texte peut ˆtre afficher si vous avez cr‚‚ une m‚thode OnHint(message$), ";
			mptr[3]="qui re‡oit comme paramŠtre le texte et l'affiche dans un widget d'affichage ";
			mptr[4]="(widget text par exemple) existant dans votre formulaire.       ";
			return(visual_online_help(mptr,5));
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
			mptr[0] = "This check box allows the collection of widget properties to be locked ";
			mptr[1]="and consequently protected against accidental modification.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Cette case … cocher v‚rrouille le widget contre toute tentative de ";
			mptr[1]="modification involontaire.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int AtX_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[20];
			mptr[0] = "The X and Y position edit fields allow the graphical pixel position ";
			mptr[1]="of the widget to be specified.  ";
			mptr[2]="The widget position may be changed in the visual forms editor by pressing ";
			mptr[3]="the left button of the mouse over the widget and then moving with ";
			mptr[4]="the button still pressed. When the mouse button is released the position ";
			mptr[5]="fields X and Y will reflect the new current position.  ";
			mptr[6]="The widget position coordinate values are available for use in method ";
			mptr[7]="text via the method terms :  ";
			mptr[8]=" ";
			mptr[9]="this.X  ";
			mptr[10]=" ";
			mptr[11]="and  ";
			mptr[12]=" ";
			mptr[13]="this.Y  ";
			mptr[14]=" ";
			mptr[15]="respectivly. By default, these values are constant integer expressions. ";
			mptr[16]=" To be able to move a widget during program operation it is necessary ";
			mptr[17]="to  ";
			mptr[18]=" activate the corresponding option of the widget method CREATE.   ";
			mptr[19]=" ";
			return(visual_online_help(mptr,20));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Les zones de saisie  X et Y permettent de sp‚cifier la position du ";
			mptr[1]="coin en haut … gauche du widget. Pour pouvoir changer les valeurs ";
			mptr[2]=" X, Y dynamiquement, activez l'option with sizes de la  m‚thode CREATE du widget. Les valeurs X,Y du widget ";
			mptr[3]="peuvent ˆtre chang‚es par programmation en faisant appel  aux propri‚t‚s ";
			mptr[4]="this.X et this.Y.     ";
			return(visual_online_help(mptr,5));
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
			char * mptr[16];
			mptr[0] = "The TEXT FONT edit field allows selection of the text font used for ";
			mptr[1]="the display  of the title of the window. ";
			mptr[2]=" The initial value of this field will be taken from the current  value ";
			mptr[3]="of the general parameter Current Font of the  Options.Parameters menu.  ";
			mptr[4]=" ";
			mptr[5]="The numeric value of the field may be referenced in method text by ";
			mptr[6]="the term :  ";
			mptr[7]=" ";
			mptr[8]="this.FONT  ";
			mptr[9]=" ";
			mptr[10]="Information relating to the font dimensions may be retrieved  by the ";
			mptr[11]="terms :  ";
			mptr[12]=" ";
			mptr[13]="this.FONTWIDTH : the width of the font in pixels.  ";
			mptr[14]=" ";
			mptr[15]="this.FONTHEIGHT : the height of the font in pixels.    ";
			return(visual_online_help(mptr,16));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Police de caractŠres pour le texte … afficher. ";
			mptr[1]=" Vous retrouverez dans le programme la valeur num‚rique de ce champ ";
			mptr[2]=" en utilisant la propri‚t‚ this.FONT. ";
			mptr[3]=" Les dimensions de la police sont donn‚es par les propri‚t‚s this.FONTWIDTH ";
			mptr[4]="et this.FONTHEIGHT.      ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int AtY_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[19];
			mptr[0] = "The X and Y position edit fields allow the graphical pixel position ";
			mptr[1]="of the widget to be specified.  ";
			mptr[2]="The widget position may be changed in the visual forms editor by pressing ";
			mptr[3]="the left button of the mouse over the widget and then moving with ";
			mptr[4]="the button still pressed. When the mouse button is released the position ";
			mptr[5]="fields X and Y will reflect the new current position.  ";
			mptr[6]="The widget position coordinate values are available for use in method ";
			mptr[7]="text via the method terms :  ";
			mptr[8]=" ";
			mptr[9]="this.X  ";
			mptr[10]=" ";
			mptr[11]="and  ";
			mptr[12]=" ";
			mptr[13]="this.Y  ";
			mptr[14]=" ";
			mptr[15]="respectivly. By default, these values are constant integer expressions. ";
			mptr[16]=" To be able to move a widget during program operation it is necessary ";
			mptr[17]="to  ";
			mptr[18]=" activate the corresponding option of the widget method CREATE.   ";
			return(visual_online_help(mptr,19));
			}
			break;
		case 1 : 
			{
			char * mptr[6];
			mptr[0] = "Les zones de saisie  X et Y permettent de sp‚cifier la position du ";
			mptr[1]="coin en haut … gauche du widget. ";
			mptr[2]=" Pour pouvoir changer les valeurs  X, Y dynamiquement, il faut activez ";
			mptr[3]="l'option with sizes de la  m‚thode CREATE du widget. Les valeurs X,Y du widget ";
			mptr[4]="peuvent ˆtre chang‚es par programmation en faisant appel  aux propri‚t‚s ";
			mptr[5]="this.X et this.Y.    ";
			return(visual_online_help(mptr,6));
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
			char * mptr[6];
			mptr[0] = "Les zones de saisie  Largeur et Hauteur permettent de sp‚cifier la ";
			mptr[1]="largeur et la hauteur du widget. ";
			mptr[2]=" Pour pouvoir changer dynamiquement les valeurs W,H, activez l'option ";
			mptr[3]="with sizes de la  m‚thode CREATE du widget. Les valeurs W,H du widget ";
			mptr[4]="peuvent ˆtre chang‚es par programmation en faisant appel  aux propri‚t‚s ";
			mptr[5]="this.H et this.W.     ";
			return(visual_online_help(mptr,6));
			}
			break;
		case 2 : 
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

private int Height_help()
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
			char * mptr[6];
			mptr[0] = "Les zones de saisie  Largeur et Hauteur permettent de sp‚cifier la ";
			mptr[1]="largeur et la hauteur du widget. ";
			mptr[2]=" Pour pouvoir changer dynamiquement les valeurs W,H, activez l'option ";
			mptr[3]="with sizes de la  m‚thode CREATE du widget. Les valeurs W,H du widget ";
			mptr[4]="peuvent ˆtre chang‚es par programmation en faisant appel  aux propri‚t‚s ";
			mptr[5]="this.H et this.W.     ";
			return(visual_online_help(mptr,6));
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
			char * mptr[1];
			mptr[0] = "Style liste proposit by Sing for this widget.     ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Liste des styles propos‚s par Sing.  ";
			return(visual_online_help(mptr,1));
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
			char * mptr[3];
			mptr[0] = "Text of columns title. ";
			mptr[1]=" The value of this atribut may be referenced from properties select ";
			mptr[2]="by the term :this.PAYLOAD.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Le texte pour l'entˆte de la liste. ";
			mptr[1]=" Vous devrez utiliser le caractŠres | pour s‚parer les noms des colonnes ";
			mptr[2]="dans la d‚claration. ";
			mptr[3]=" Vous retrouverez par programmation la liste en utilisant la propri‚t‚ ";
			mptr[4]=" this.PAYLOAD du widget.   ";
			return(visual_online_help(mptr,5));
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
			char * mptr[5];
			mptr[0] = "This edit field allows an alternative style classname to be specified ";
			mptr[1]="for this  component widget. Style classes specified in this way should ";
			mptr[2]="be described in the style sheet file defined in the Forms Properties dialog box. If a style sheet file is present and ";
			mptr[3]="the class is found to exist then the style will be  used for the display ";
			mptr[4]="of the component by the forms model editor.    ";
			return(visual_online_help(mptr,5));
			}
			break;
		case 1 : 
			{
			char * mptr[6];
			mptr[0] = "Zone d'‚dititon qui permet d'indiquer une classe de style pour ce ";
			mptr[1]="widget. La classe de style sp‚cifi‚e doit ˆtre d‚crite dans un fichier ";
			mptr[2]="d‚finit dans  Menu Formulaire/Propri‚t‚s/ Nom du fichier de classes de styles. ";
			mptr[3]=" Si le fichier .css est pr‚sent au moment de l'‚x‚cution et si il ";
			mptr[4]="contient bien la description de la classe indiqu‚e, cette classe sera ";
			mptr[5]="utilis‚e pour afficher le widget.      ";
			return(visual_online_help(mptr,6));
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
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Couleur du texte. ";
			mptr[1]=" Vous aurez accŠs par programmation … cette valeur en utilisant la ";
			mptr[2]="propri‚t‚ this.FG.     ";
			return(visual_online_help(mptr,3));
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
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "La couleur du fond. ";
			mptr[1]=" Vous aurez accŠs par programmation … cette valeur en utilisant la ";
			mptr[2]="propri‚t‚ this.BG.     ";
			return(visual_online_help(mptr,3));
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
			char * mptr[2];
			mptr[0] = "This check activates enforcement of the format supplied by the format ";
			mptr[1]="field of the these widgets.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Cette case … cocher permet de prendre en compt le fomat qui a ‚t‚ ";
			mptr[1]="d‚clar‚.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Compact_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[7];
			mptr[0] = "This check indicates that the table is to be drawn with a compact ";
			mptr[1]="border. ";
			mptr[2]=" Eventual style class application will be performed to the entire ";
			mptr[3]="visual area. ";
			mptr[4]=" When unchecked, table drawing functions reduce internal dimensions ";
			mptr[5]="by the double  of the table frame width, by default 2 * 4 pixels. ";
			mptr[6]="    ";
			return(visual_online_help(mptr,7));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Cette case … cocher permet de prendre en compt le fomat qui a ‚t‚ ";
			mptr[1]="d‚clar‚.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int LineFocus_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This check indicates that the table component will manage an autofocus. ";
			mptr[1]="The focus will be displayed using colour inversion if no style is ";
			mptr[2]="presence, otherwise the tablefocus class will be applied to each data cell of the current ";
			mptr[3]="focus line.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Cette case … cocher permet de prendre en compt le fomat qui a ‚t‚ ";
			mptr[1]="d‚clar‚.   ";
			return(visual_online_help(mptr,2));
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
			char * mptr[1];
			mptr[0] = "Display of the underline text.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Affichage du texte soulign‚.  ";
			return(visual_online_help(mptr,1));
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
			char * mptr[1];
			mptr[0] = "Activates the mode relief for the title list.     ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "L'entˆte de la liste sera en relif.   ";
			return(visual_online_help(mptr,1));
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
			char * mptr[3];
			mptr[0] = "Used in conjonction with the Column Titles edit zone. ";
			mptr[1]=" This information schould be provided by a standard abal format expression. ";
			mptr[2]="   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Format des colonnes d‚clar‚es dans l'entˆte. ";
			mptr[1]=" Cette zone permet d'indiquer le format des colonnes avec la syntaxe ";
			mptr[2]="ABAL des zones d'‚dition.   ";
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
			char * mptr[6];
			mptr[0] = "This check control when activated allows the widget width to be resized ";
			mptr[1]="as  and when required by the auto-resize operation ofthe parent form. ";
			mptr[2]="When not active the widget will preserve its defined width across ";
			mptr[3]="form redimensioning operations.  ";
			mptr[4]=" ";
			mptr[5]="   ";
			return(visual_online_help(mptr,6));
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
			char * mptr[6];
			mptr[0] = "This check control when activated allows the widget height to be resized ";
			mptr[1]="as  and when required by the auto-resize operation ofthe parent form. ";
			mptr[2]="When not active the widget will preserve its defined height across ";
			mptr[3]="form redimensioning operations.  ";
			mptr[4]=" ";
			mptr[5]="   ";
			return(visual_online_help(mptr,6));
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
			char * mptr[4];
			mptr[0] = "This Combo allows the CLASS of an existing widget to be changed. ";
			mptr[1]=" The secondary properties associated with the widget and its methods ";
			mptr[2]="will be preserved and will not be changed to the default values of ";
			mptr[3]="the new widget type.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[4];
			mptr[0] = "La classe … laquelle le widget appartient. ";
			mptr[1]=" Le changement de classe est d‚conseill‚, car une partie du code est ";
			mptr[2]="g‚n‚r‚ … la cr‚ation en fonction de la classe initiale et ne sera ";
			mptr[3]="pas modifi‚ une fois la classe chang‚e.      ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}
private int on_fgSelect_event(struct vwform_context * _Context) {
	int fgv=0;
	int bgv=0;
	char*sptr;
	int slen;
	int i;
	sptr=_Context->buffer_TextColour;
	slen=6;
	for(i=0;i<slen;i++){
	if((*(sptr+i)>='0')
	&&(*(sptr+i)<='9'))
	fgv=((fgv*10)+(*(sptr+i)-'0'));
	}
	sptr=_Context->buffer_Background;
	slen=6;
	for(i=0;i<slen;i++){
	if((*(sptr+i)>='0')
	&&(*(sptr+i)<='9'))
	bgv=((bgv*10)+(*(sptr+i)-'0'));
	}
	if(accept_visual_colour(&fgv,&bgv)!=27){
	sprintf(_Context->buffer_TextColour,"%u",fgv);
	sprintf(_Context->buffer_Background,"%u",bgv);
	}
		vwform_show(_Context);
;
	return(-1);
}


public	int	vwform_event(
struct vwform_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsLock == mb ) return(5);
		if (_Context->trigger_IsBold == mb ) return(16);
		if (_Context->trigger_Compact == mb ) return(17);
		if (_Context->trigger_LineFocus == mb ) return(18);
		if (_Context->trigger_IsUnderline == mb ) return(19);
		if (_Context->trigger_IsShadow == mb ) return(20);
		if (_Context->trigger_IswResize == mb ) return(22);
		if (_Context->trigger_IshResize == mb ) return(23);
		if (_Context->trigger_fgSelect == mb ) return(24);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_WidgetProperties+617) )  
	&&  (my >= (_Context->y_WidgetProperties+4) )  
	&&  (mx <= (_Context->x_WidgetProperties+634) )  
	&&  (my <= (_Context->y_WidgetProperties+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		vwform_show(_Context);
		return(-1);	/* WidgetProperties */

		}
		}
	if (( mx >= (_Context->x_WidgetProperties+13) ) 
	&&  ( my >= (_Context->y_WidgetProperties+64) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+13+160) ) 
	&&  ( my <= (_Context->y_WidgetProperties+64+16))) {
		return(2); /* Identity */
		}
	if (( mx >= (_Context->x_WidgetProperties+179+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+64) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+179+140) ) 
	&&  ( my <= (_Context->y_WidgetProperties+64+16))) {
		return(3); /* WidgetStorage */
		}
	if (( mx >= (_Context->x_WidgetProperties+13) ) 
	&&  ( my >= (_Context->y_WidgetProperties+101) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+13+424) ) 
	&&  ( my <= (_Context->y_WidgetProperties+101+48))) {
		return(4); /* Hint */
		}
	if (( mx >= (_Context->x_WidgetProperties+464) ) 
	&&  ( my >= (_Context->y_WidgetProperties+63) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+464+182) ) 
	&&  ( my <= (_Context->y_WidgetProperties+63+16))) {
		return(5); /* IsLock */
		}
	if (( mx >= (_Context->x_WidgetProperties+461) ) 
	&&  ( my >= (_Context->y_WidgetProperties+130) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+461+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+130+16))) {
		return(6); /* AtX */
		}
	if (( mx >= (_Context->x_WidgetProperties+13+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+208) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+13+126) ) 
	&&  ( my <= (_Context->y_WidgetProperties+208+16))) {
		return(7); /* TextFont */
		}
	if (( mx >= (_Context->x_WidgetProperties+505) ) 
	&&  ( my >= (_Context->y_WidgetProperties+129) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+505+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+129+16))) {
		return(8); /* AtY */
		}
	if (( mx >= (_Context->x_WidgetProperties+566) ) 
	&&  ( my >= (_Context->y_WidgetProperties+130) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+566+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+130+16))) {
		return(9); /* Width */
		}
	if (( mx >= (_Context->x_WidgetProperties+616) ) 
	&&  ( my >= (_Context->y_WidgetProperties+130) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+616+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+130+16))) {
		return(10); /* Height */
		}
	if (( mx >= (_Context->x_WidgetProperties+314+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+208) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+314+130) ) 
	&&  ( my <= (_Context->y_WidgetProperties+208+16))) {
		return(11); /* Align */
		}
	if (( mx >= (_Context->x_WidgetProperties+14) ) 
	&&  ( my >= (_Context->y_WidgetProperties+252) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+14+426) ) 
	&&  ( my <= (_Context->y_WidgetProperties+252+32))) {
		return(12); /* PayLoad */
		}
	if (( mx >= (_Context->x_WidgetProperties+464) ) 
	&&  ( my >= (_Context->y_WidgetProperties+208) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+464+190) ) 
	&&  ( my <= (_Context->y_WidgetProperties+208+16))) {
		return(13); /* StyleSheet */
		}
	if (( mx >= (_Context->x_WidgetProperties+167) ) 
	&&  ( my >= (_Context->y_WidgetProperties+208) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+167+40) ) 
	&&  ( my <= (_Context->y_WidgetProperties+208+16))) {
		return(14); /* TextColour */
		}
	if (( mx >= (_Context->x_WidgetProperties+257) ) 
	&&  ( my >= (_Context->y_WidgetProperties+208) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+257+42) ) 
	&&  ( my <= (_Context->y_WidgetProperties+208+16))) {
		return(15); /* Background */
		}
	if (( mx >= (_Context->x_WidgetProperties+467) ) 
	&&  ( my >= (_Context->y_WidgetProperties+317) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+467+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+317+16))) {
		return(16); /* IsBold */
		}
	if (( mx >= (_Context->x_WidgetProperties+467) ) 
	&&  ( my >= (_Context->y_WidgetProperties+338) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+467+168) ) 
	&&  ( my <= (_Context->y_WidgetProperties+338+16))) {
		return(17); /* Compact */
		}
	if (( mx >= (_Context->x_WidgetProperties+467) ) 
	&&  ( my >= (_Context->y_WidgetProperties+358) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+467+168) ) 
	&&  ( my <= (_Context->y_WidgetProperties+358+16))) {
		return(18); /* LineFocus */
		}
	if (( mx >= (_Context->x_WidgetProperties+466) ) 
	&&  ( my >= (_Context->y_WidgetProperties+251) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+466+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+251+16))) {
		return(19); /* IsUnderline */
		}
	if (( mx >= (_Context->x_WidgetProperties+466) ) 
	&&  ( my >= (_Context->y_WidgetProperties+271) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+466+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+271+16))) {
		return(20); /* IsShadow */
		}
	if (( mx >= (_Context->x_WidgetProperties+17) ) 
	&&  ( my >= (_Context->y_WidgetProperties+316) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+17+424) ) 
	&&  ( my <= (_Context->y_WidgetProperties+316+48))) {
		return(21); /* Format */
		}
	if (( mx >= (_Context->x_WidgetProperties+17) ) 
	&&  ( my >= (_Context->y_WidgetProperties+369) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+17+168) ) 
	&&  ( my <= (_Context->y_WidgetProperties+369+16))) {
		return(22); /* IswResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+288) ) 
	&&  ( my >= (_Context->y_WidgetProperties+369) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+288+165) ) 
	&&  ( my <= (_Context->y_WidgetProperties+369+16))) {
		return(23); /* IshResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+211) ) 
	&&  ( my >= (_Context->y_WidgetProperties+208) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+211+44) ) 
	&&  ( my <= (_Context->y_WidgetProperties+208+18))) {
		return(24); /* fgSelect */
		}
	if (( mx >= (_Context->x_WidgetProperties+324+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+64) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+324+112) ) 
	&&  ( my <= (_Context->y_WidgetProperties+64+16))) {
		return(25); /* WidgetClass */
		}

	return(-1);
}


public	int	vwform_focus(struct vwform_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Identity */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+64+1,160,16,vfh[1],_Context->buffer_Identity,255);
			break;
			case	0x3 :
				/* WidgetStorage */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+179,_Context->y_WidgetProperties+64,140,112,vfh[2],0,0,parse_selection(WidgetTypeList,&_Context->value_WidgetStorage),774);
				break;
			case	0x4 :
				/* Hint */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+101+1,424,48,vfh[1],_Context->buffer_Hint,255);
			break;
			case	0x5 :
				/* IsLock */
				visual_check(_Context->x_WidgetProperties+464,_Context->y_WidgetProperties+63,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),(_Context->value_IsLock |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+464,_Context->y_WidgetProperties+63,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
				break;
			case	0x6 :
				/* AtX */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+461+1,_Context->y_WidgetProperties+130+1,35,16,vfh[1],_Context->buffer_AtX,7);
			break;
			case	0x7 :
				/* TextFont */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+208,126,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),770);
				break;
			case	0x8 :
				/* AtY */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+505+1,_Context->y_WidgetProperties+129+1,35,16,vfh[1],_Context->buffer_AtY,7);
			break;
			case	0x9 :
				/* Width */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+566+1,_Context->y_WidgetProperties+130+1,35,16,vfh[1],_Context->buffer_Width,7);
			break;
			case	0xa :
				/* Height */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+616+1,_Context->y_WidgetProperties+130+1,35,16,vfh[1],_Context->buffer_Height,7);
			break;
			case	0xb :
				/* Align */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+314,_Context->y_WidgetProperties+208,130,100,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),774);
				break;
			case	0xc :
				/* PayLoad */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+252+1,426,32,vfh[1],_Context->buffer_PayLoad,255);
			break;
			case	0xd :
				/* StyleSheet */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+464+1,_Context->y_WidgetProperties+208+1,190,16,vfh[1],_Context->buffer_StyleSheet,255);
			break;
			case	0xe :
				/* TextColour */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+167+1,_Context->y_WidgetProperties+208+1,40,16,vfh[1],_Context->buffer_TextColour,6);
			break;
			case	0xf :
				/* Background */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+257+1,_Context->y_WidgetProperties+208+1,42,16,vfh[1],_Context->buffer_Background,6);
			break;
			case	0x10 :
				/* IsBold */
				visual_check(_Context->x_WidgetProperties+467,_Context->y_WidgetProperties+317,180,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),(_Context->value_IsBold |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_WidgetProperties+467,_Context->y_WidgetProperties+317,180,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
				break;
			case	0x11 :
				/* Compact */
				visual_check(_Context->x_WidgetProperties+467,_Context->y_WidgetProperties+338,168,16,vfh[2],175,0,_Context->msg_Compact[_Context->language],strlen(_Context->msg_Compact[_Context->language]),(_Context->value_Compact |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Compact=visual_trigger_code(_Context->msg_Compact[_Context->language],strlen(_Context->msg_Compact[_Context->language]));
	visual_check(_Context->x_WidgetProperties+467,_Context->y_WidgetProperties+338,168,16,vfh[2],175,0,_Context->msg_Compact[_Context->language],strlen(_Context->msg_Compact[_Context->language]),_Context->value_Compact|0);
				break;
			case	0x12 :
				/* LineFocus */
				visual_check(_Context->x_WidgetProperties+467,_Context->y_WidgetProperties+358,168,16,vfh[2],175,0,_Context->msg_LineFocus[_Context->language],strlen(_Context->msg_LineFocus[_Context->language]),(_Context->value_LineFocus |2));
				_Context->keycode = visual_getch();
				_Context->trigger_LineFocus=visual_trigger_code(_Context->msg_LineFocus[_Context->language],strlen(_Context->msg_LineFocus[_Context->language]));
	visual_check(_Context->x_WidgetProperties+467,_Context->y_WidgetProperties+358,168,16,vfh[2],175,0,_Context->msg_LineFocus[_Context->language],strlen(_Context->msg_LineFocus[_Context->language]),_Context->value_LineFocus|0);
				break;
			case	0x13 :
				/* IsUnderline */
				visual_check(_Context->x_WidgetProperties+466,_Context->y_WidgetProperties+251,180,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),(_Context->value_IsUnderline |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsUnderline=visual_trigger_code(_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]));
	visual_check(_Context->x_WidgetProperties+466,_Context->y_WidgetProperties+251,180,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),_Context->value_IsUnderline|0);
				break;
			case	0x14 :
				/* IsShadow */
				visual_check(_Context->x_WidgetProperties+466,_Context->y_WidgetProperties+271,180,16,vfh[2],28,28,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),(_Context->value_IsShadow |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsShadow=visual_trigger_code(_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]));
	visual_check(_Context->x_WidgetProperties+466,_Context->y_WidgetProperties+271,180,16,vfh[2],28,28,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),_Context->value_IsShadow|0);
				break;
			case	0x15 :
				/* Format */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+17+1,_Context->y_WidgetProperties+316+1,424,48,vfh[1],_Context->buffer_Format,255);
			break;
			case	0x16 :
				/* IswResize */
				visual_check(_Context->x_WidgetProperties+17,_Context->y_WidgetProperties+369,168,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),(_Context->value_IswResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+17,_Context->y_WidgetProperties+369,168,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
				break;
			case	0x17 :
				/* IshResize */
				visual_check(_Context->x_WidgetProperties+288,_Context->y_WidgetProperties+369,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),(_Context->value_IshResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+288,_Context->y_WidgetProperties+369,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
				break;
			case	0x18 :
				/* fgSelect */
				_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
				visual_button(_Context->x_WidgetProperties+211,_Context->y_WidgetProperties+208,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+211,_Context->y_WidgetProperties+208,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
				break;
			case	0x19 :
				/* WidgetClass */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+324,_Context->y_WidgetProperties+64,112,128,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),774);
				if(change_widget_class(&_Context->value_WidgetClass)!=0){
				return(26);
				}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			vwform_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=25;
			vwform_show(_Context);
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
			if ((retcode=vwform_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (Identity_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (WidgetStorage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Hint_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (IsLock_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (AtX_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (TextFont_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (AtY_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (Width_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (Height_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Align_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (PayLoad_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (StyleSheet_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (TextColour_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (Background_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (IsBold_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (Compact_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (LineFocus_help(_Context) != 0) { continue; }
						else { break; }
					case	0x13 :
						if (IsUnderline_help(_Context) != 0) { continue; }
						else { break; }
					case	0x14 :
						if (IsShadow_help(_Context) != 0) { continue; }
						else { break; }
					case	0x15 :
						if (Format_help(_Context) != 0) { continue; }
						else { break; }
					case	0x16 :
						if (IswResize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x17 :
						if (IshResize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x19 :
						if (WidgetClass_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
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
					/* Identity */
					continue;
				case	0x3 :
					/* WidgetStorage */
					continue;
				case	0x4 :
					/* Hint */
					continue;
				case	0x5 :
					/* IsLock */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsLock += 1;
						_Context->value_IsLock &= 1;
						}
					continue;
				case	0x6 :
					/* AtX */
					continue;
				case	0x7 :
					/* TextFont */
					continue;
				case	0x8 :
					/* AtY */
					continue;
				case	0x9 :
					/* Width */
					continue;
				case	0xa :
					/* Height */
					continue;
				case	0xb :
					/* Align */
					continue;
				case	0xc :
					/* PayLoad */
					continue;
				case	0xd :
					/* StyleSheet */
					continue;
				case	0xe :
					/* TextColour */
					continue;
				case	0xf :
					/* Background */
					continue;
				case	0x10 :
					/* IsBold */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsBold += 1;
						_Context->value_IsBold &= 1;
						}
					continue;
				case	0x11 :
					/* Compact */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Compact += 1;
						_Context->value_Compact &= 1;
						}
					continue;
				case	0x12 :
					/* LineFocus */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_LineFocus += 1;
						_Context->value_LineFocus &= 1;
						}
					continue;
				case	0x13 :
					/* IsUnderline */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsUnderline += 1;
						_Context->value_IsUnderline &= 1;
						}
					continue;
				case	0x14 :
					/* IsShadow */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsShadow += 1;
						_Context->value_IsShadow &= 1;
						}
					continue;
				case	0x15 :
					/* Format */
					continue;
				case	0x16 :
					/* IswResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IswResize += 1;
						_Context->value_IswResize &= 1;
						}
					continue;
				case	0x17 :
					/* IshResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IshResize += 1;
						_Context->value_IshResize &= 1;
						}
					continue;
				case	0x18 :
					/* fgSelect */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
						visual_button(_Context->x_WidgetProperties+211,_Context->y_WidgetProperties+208,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+211,_Context->y_WidgetProperties+208,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_fgSelect_event(_Context)) != -1) break;

						}
					continue;
				case	0x19 :
					/* WidgetClass */
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
				_Context->focus_item=25;
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

public	int	vwform()
{
	int	status=0;
	struct vwform_context * _Context=(struct vwform_context*) 0;
	status = vwform_create(&_Context);
	if ( status != 0) return(status);
	status = vwform_show(_Context);
		enter_modal();
	status = vwform_focus(_Context);
		leave_modal();
	status = vwform_hide(_Context);
	status = vwform_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwform_c */
