
#ifndef _vwedit_c
#define _vwedit_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vwedit.xml                                               */
/* Target         : vwedit.c                                                 */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "sing.h"
#include "singform.h"
#include "singprot.h"
#define en_WidgetProperties   "Edit -Properties"
#define fr_WidgetProperties   "Edit - Propri‚t‚s"
#define it_WidgetProperties   "Edit widget -Properties"
#define es_WidgetProperties   "Edit widget -Properties"
#define de_WidgetProperties   "Edit widget -Properties"
#define nl_WidgetProperties   "Edit widget -Properties"
#define pt_WidgetProperties   "Edit widget -Properties"
#define xx_WidgetProperties   "Edit widget -Properties"
#define en__WidgetProperties   ""
#define fr__WidgetProperties   ""
#define it__WidgetProperties   ""
#define es__WidgetProperties   ""
#define de__WidgetProperties   ""
#define nl__WidgetProperties   ""
#define pt__WidgetProperties   ""
#define xx__WidgetProperties   ""
#define en_Auto3605   "Position and dimension"
#define fr_Auto3605   "Position et Dimension"
#define it_Auto3605   "Position and dimension"
#define es_Auto3605   "Position and dimension"
#define de_Auto3605   "Position and dimension"
#define nl_Auto3605   "Position and dimension"
#define pt_Auto3605   "Position and dimension"
#define xx_Auto3605   "Position and dimension"
#define en__Auto3605   ""
#define fr__Auto3605   ""
#define it__Auto3605   ""
#define es__Auto3605   ""
#define de__Auto3605   ""
#define nl__Auto3605   ""
#define pt__Auto3605   ""
#define xx__Auto3605   ""
#define en_Auto3607   "Appearence"
#define fr_Auto3607   "Apparence"
#define it_Auto3607   "Appearence"
#define es_Auto3607   "Appearence"
#define de_Auto3607   "Appearence"
#define nl_Auto3607   "Appearence"
#define pt_Auto3607   "Appearence"
#define xx_Auto3607   "Appearence"
#define en__Auto3607   ""
#define fr__Auto3607   ""
#define it__Auto3607   ""
#define es__Auto3607   ""
#define de__Auto3607   ""
#define nl__Auto3607   ""
#define pt__Auto3607   ""
#define xx__Auto3607   ""
#define en_Auto3608   "Behaviour"
#define fr_Auto3608   "Comportement"
#define it_Auto3608   "Behaviour"
#define es_Auto3608   "Behaviour"
#define de_Auto3608   "Behaviour"
#define nl_Auto3608   "Behaviour"
#define pt_Auto3608   "Behaviour"
#define xx_Auto3608   "Behaviour"
#define en__Auto3608   ""
#define fr__Auto3608   ""
#define it__Auto3608   ""
#define es__Auto3608   ""
#define de__Auto3608   ""
#define nl__Auto3608   ""
#define pt__Auto3608   ""
#define xx__Auto3608   ""
#define en_IsInhibit   "Enable|Disable|Inhibit"
#define fr_IsInhibit   "Enable|Disable|Inhibit"
#define it_IsInhibit   "Enable|Disable|Inhibit"
#define es_IsInhibit   "Enable|Disable|Inhibit"
#define de_IsInhibit   "Enable|Disable|Inhibit"
#define nl_IsInhibit   "Enable|Disable|Inhibit"
#define pt_IsInhibit   "Enable|Disable|Inhibit"
#define xx_IsInhibit   "Enable|Disable|Inhibit"
#define en__IsInhibit   ""
#define fr__IsInhibit   ""
#define it__IsInhibit   ""
#define es__IsInhibit   ""
#define de__IsInhibit   ""
#define nl__IsInhibit   ""
#define pt__IsInhibit   ""
#define xx__IsInhibit   ""
#define en_Auto3609   "General"
#define fr_Auto3609   "G‚n‚ral"
#define it_Auto3609   "General"
#define es_Auto3609   "General"
#define de_Auto3609   "General"
#define nl_Auto3609   "General"
#define pt_Auto3609   "General"
#define xx_Auto3609   "General"
#define en__Auto3609   ""
#define fr__Auto3609   ""
#define it__Auto3609   ""
#define es__Auto3609   ""
#define de__Auto3609   ""
#define nl__Auto3609   ""
#define pt__Auto3609   ""
#define xx__Auto3609   ""
#define en_Auto3610   "X"
#define fr_Auto3610   "X"
#define it_Auto3610   "X"
#define es_Auto3610   "X"
#define de_Auto3610   "X"
#define nl_Auto3610   "X"
#define pt_Auto3610   "X"
#define xx_Auto3610   "X"
#define en__Auto3610   ""
#define fr__Auto3610   ""
#define it__Auto3610   ""
#define es__Auto3610   ""
#define de__Auto3610   ""
#define nl__Auto3610   ""
#define pt__Auto3610   ""
#define xx__Auto3610   ""
#define en_Auto3611   "Height"
#define fr_Auto3611   "Hauteur"
#define it_Auto3611   "Height"
#define es_Auto3611   "Height"
#define de_Auto3611   "Height"
#define nl_Auto3611   "Height"
#define pt_Auto3611   "Height"
#define xx_Auto3611   "Height"
#define en__Auto3611   ""
#define fr__Auto3611   ""
#define it__Auto3611   ""
#define es__Auto3611   ""
#define de__Auto3611   ""
#define nl__Auto3611   ""
#define pt__Auto3611   ""
#define xx__Auto3611   ""
#define en_Auto3612   "Width"
#define fr_Auto3612   "Largeur"
#define it_Auto3612   "Width"
#define es_Auto3612   "Width"
#define de_Auto3612   "Width"
#define nl_Auto3612   "Width"
#define pt_Auto3612   "Width"
#define xx_Auto3612   "Width"
#define en__Auto3612   ""
#define fr__Auto3612   ""
#define it__Auto3612   ""
#define es__Auto3612   ""
#define de__Auto3612   ""
#define nl__Auto3612   ""
#define pt__Auto3612   ""
#define xx__Auto3612   ""
#define en_Auto3613   "Y"
#define fr_Auto3613   "Y"
#define it_Auto3613   "Y"
#define es_Auto3613   "Y"
#define de_Auto3613   "Y"
#define nl_Auto3613   "Y"
#define pt_Auto3613   "Y"
#define xx_Auto3613   "Y"
#define en__Auto3613   ""
#define fr__Auto3613   ""
#define it__Auto3613   ""
#define es__Auto3613   ""
#define de__Auto3613   ""
#define nl__Auto3613   ""
#define pt__Auto3613   ""
#define xx__Auto3613   ""
#define en_Identity   ""
#define fr_Identity   ""
#define en__Identity   ""
#define fr__Identity   ""
#define en__WidgetClass   ""
#define en__Type   ""
#define fr__Type   ""
#define en_Format   ""
#define en__Format   ""
#define en_IsSpecial   "Refresh"
#define fr_IsSpecial   "Suivi"
#define it_IsSpecial   "Refresh"
#define es_IsSpecial   "Refresh"
#define de_IsSpecial   "Refresh"
#define nl_IsSpecial   "Refresh"
#define pt_IsSpecial   "Refresh"
#define xx_IsSpecial   "Refresh"
#define en__IsSpecial   ""
#define fr__IsSpecial   ""
#define it__IsSpecial   ""
#define es__IsSpecial   ""
#define de__IsSpecial   ""
#define nl__IsSpecial   ""
#define pt__IsSpecial   ""
#define xx__IsSpecial   ""
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
#define en_IsInterface   "Interface Item"
#define fr_IsInterface   "Item d'interface"
#define it_IsInterface   "Interface Item"
#define es_IsInterface   "Interface Item"
#define de_IsInterface   "Interface Item"
#define nl_IsInterface   "Interface Item"
#define pt_IsInterface   "Interface Item"
#define xx_IsInterface   "A'faicinn"
#define en__IsInterface   ""
#define fr__IsInterface   ""
#define it__IsInterface   ""
#define es__IsInterface   ""
#define de__IsInterface   ""
#define nl__IsInterface   ""
#define pt__IsInterface   ""
#define xx__IsInterface   ""
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
#define en_StyleSheet   ""
#define fr_StyleSheet   ""
#define en__StyleSheet   ""
#define fr__StyleSheet   ""
#define en_FocusStyle   ""
#define fr_FocusStyle   ""
#define en__FocusStyle   ""
#define fr__FocusStyle   ""
#define en_CursorType   "Coloured|Block|Vertical Line|Underline|Frame|None"
#define fr_CursorType   "Coloured|Block|Vertical Line|Underline|Frame|None"
#define it_CursorType   "Coloured|Block|Vertical Line|Underline|Frame|None"
#define es_CursorType   "Coloured|Block|Vertical Line|Underline|Frame|None"
#define de_CursorType   "Coloured|Block|Vertical Line|Underline|Frame|None"
#define nl_CursorType   "Coloured|Block|Vertical Line|Underline|Frame|None"
#define pt_CursorType   "Coloured|Block|Vertical Line|Underline|Frame|None"
#define xx_CursorType   "Coloured|Block|Vertical Line|Underline|Frame|None"
#define en__CursorType   ""
#define en_IsBold   "Ask"
#define fr_IsBold   "Ask"
#define it_IsBold   "Ask"
#define es_IsBold   "Ask"
#define de_IsBold   "Ask"
#define nl_IsBold   "Ask"
#define pt_IsBold   "Ask"
#define xx_IsBold   "Ask"
#define en__IsBold   ""
#define fr__IsBold   ""
#define it__IsBold   ""
#define es__IsBold   ""
#define de__IsBold   ""
#define nl__IsBold   ""
#define pt__IsBold   ""
#define xx__IsBold   ""
#define en_IsUnderline   "Secret"
#define fr_IsUnderline   "Secret"
#define it_IsUnderline   "Secret"
#define es_IsUnderline   "Secret"
#define de_IsUnderline   "Secret"
#define nl_IsUnderline   "Secret"
#define pt_IsUnderline   "Secret"
#define xx_IsUnderline   "Secret"
#define en__IsUnderline   ""
#define fr__IsUnderline   ""
#define it__IsUnderline   ""
#define es__IsUnderline   ""
#define de__IsUnderline   ""
#define nl__IsUnderline   ""
#define pt__IsUnderline   ""
#define xx__IsUnderline   ""
#define en_Auto3614   "Font"
#define fr_Auto3614   "Police"
#define it_Auto3614   "Font"
#define es_Auto3614   "Font"
#define de_Auto3614   "Font"
#define nl_Auto3614   "Font"
#define pt_Auto3614   "Font"
#define xx_Auto3614   "Font"
#define en__Auto3614   ""
#define fr__Auto3614   ""
#define it__Auto3614   ""
#define es__Auto3614   ""
#define de__Auto3614   ""
#define nl__Auto3614   ""
#define pt__Auto3614   ""
#define xx__Auto3614   ""
#define en_Auto3615   "Initial value"
#define fr_Auto3615   "Valeur initiale"
#define it_Auto3615   "Intial value"
#define es_Auto3615   "Intial value"
#define de_Auto3615   "Intial value"
#define nl_Auto3615   "Intial value"
#define pt_Auto3615   "Intial value"
#define xx_Auto3615   "Intial value"
#define en__Auto3615   ""
#define fr__Auto3615   ""
#define it__Auto3615   ""
#define es__Auto3615   ""
#define de__Auto3615   ""
#define nl__Auto3615   ""
#define pt__Auto3615   ""
#define xx__Auto3615   ""
#define en_Auto3616   "Explicit style"
#define fr_Auto3616   "Style explicite"
#define it_Auto3616   "Explicit style"
#define es_Auto3616   "Explicit style"
#define de_Auto3616   "Explicit style"
#define nl_Auto3616   "Explicit style"
#define pt_Auto3616   "Explicit style"
#define xx_Auto3616   "Explicit style"
#define en__Auto3616   ""
#define fr__Auto3616   ""
#define it__Auto3616   ""
#define es__Auto3616   ""
#define de__Auto3616   ""
#define nl__Auto3616   ""
#define pt__Auto3616   ""
#define xx__Auto3616   ""
#define en_Auto3617   "Cursor Type"
#define fr_Auto3617   "Type de curseur"
#define it_Auto3617   "Cursor Type"
#define es_Auto3617   "Cursor Type"
#define de_Auto3617   "Cursor Type"
#define nl_Auto3617   "Cursor Type"
#define pt_Auto3617   "Cursor Type"
#define xx_Auto3617   "Cursor Type"
#define en__Auto3617   ""
#define fr__Auto3617   ""
#define it__Auto3617   ""
#define es__Auto3617   ""
#define de__Auto3617   ""
#define nl__Auto3617   ""
#define pt__Auto3617   ""
#define xx__Auto3617   ""
#define en_TextColour   ""
#define en__TextColour   ""
#define en_Background   ""
#define en__Background   ""
#define en_Auto3618   "Fore"
#define fr_Auto3618   "Texte"
#define it_Auto3618   "Fore"
#define es_Auto3618   "Fore"
#define de_Auto3618   "Fore"
#define nl_Auto3618   "Fore"
#define pt_Auto3618   "Fore"
#define xx_Auto3618   "Fore"
#define en__Auto3618   ""
#define fr__Auto3618   ""
#define it__Auto3618   ""
#define es__Auto3618   ""
#define de__Auto3618   ""
#define nl__Auto3618   ""
#define pt__Auto3618   ""
#define xx__Auto3618   ""
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
#define en_Auto3619   "Back"
#define fr_Auto3619   "Fond"
#define it_Auto3619   "Back"
#define es_Auto3619   "Back"
#define de_Auto3619   "Back"
#define nl_Auto3619   "Back"
#define pt_Auto3619   "Back"
#define xx_Auto3619   "Back"
#define en__Auto3619   ""
#define fr__Auto3619   ""
#define it__Auto3619   ""
#define es__Auto3619   ""
#define de__Auto3619   ""
#define nl__Auto3619   ""
#define pt__Auto3619   ""
#define xx__Auto3619   ""
#define en_Auto3620   "Hint"
#define fr_Auto3620   "Infobulle"
#define it_Auto3620   "Hint"
#define es_Auto3620   "Hint"
#define de_Auto3620   "Hint"
#define nl_Auto3620   "Hint"
#define pt_Auto3620   "Hint"
#define xx_Auto3620   "Hint"
#define en__Auto3620   ""
#define fr__Auto3620   ""
#define it__Auto3620   ""
#define es__Auto3620   ""
#define de__Auto3620   ""
#define nl__Auto3620   ""
#define pt__Auto3620   ""
#define xx__Auto3620   ""
#define en_Auto3621   "Alignment"
#define fr_Auto3621   "Alignement"
#define it_Auto3621   "Alignment"
#define es_Auto3621   "Alignment"
#define de_Auto3621   "Alignment"
#define nl_Auto3621   "Alignment"
#define pt_Auto3621   "Alignment"
#define xx_Auto3621   "Alignment"
#define en__Auto3621   ""
#define fr__Auto3621   ""
#define it__Auto3621   ""
#define es__Auto3621   ""
#define de__Auto3621   ""
#define nl__Auto3621   ""
#define pt__Auto3621   ""
#define xx__Auto3621   ""
#define en_Auto3622   "Name"
#define fr_Auto3622   "Nom"
#define it_Auto3622   "Name"
#define es_Auto3622   "Name"
#define de_Auto3622   "Name"
#define nl_Auto3622   "Name"
#define pt_Auto3622   "Name"
#define xx_Auto3622   "Name"
#define en__Auto3622   ""
#define fr__Auto3622   ""
#define it__Auto3622   ""
#define es__Auto3622   ""
#define de__Auto3622   ""
#define nl__Auto3622   ""
#define pt__Auto3622   ""
#define xx__Auto3622   ""
#define en_Auto3623   "Widget class"
#define fr_Auto3623   "Classe de widget"
#define it_Auto3623   "Widget class"
#define es_Auto3623   "Widget class"
#define de_Auto3623   "Widget class"
#define nl_Auto3623   "Widget class"
#define pt_Auto3623   "Widget class"
#define xx_Auto3623   "Widget class"
#define en__Auto3623   ""
#define fr__Auto3623   ""
#define it__Auto3623   ""
#define es__Auto3623   ""
#define de__Auto3623   ""
#define nl__Auto3623   ""
#define pt__Auto3623   ""
#define xx__Auto3623   ""
#define en_Auto3624   "Format"
#define fr_Auto3624   "Format"
#define it_Auto3624   "Format"
#define es_Auto3624   "Format"
#define de_Auto3624   "Format"
#define nl_Auto3624   "Format"
#define pt_Auto3624   "Format"
#define xx_Auto3624   "Format"
#define en__Auto3624   ""
#define fr__Auto3624   ""
#define it__Auto3624   ""
#define es__Auto3624   ""
#define de__Auto3624   ""
#define nl__Auto3624   ""
#define pt__Auto3624   ""
#define xx__Auto3624   ""
#define en_Auto3625   "Type"
#define fr_Auto3625   "Type"
#define it_Auto3625   "Type"
#define es_Auto3625   "Type"
#define de_Auto3625   "Type"
#define nl_Auto3625   "Type"
#define pt_Auto3625   "Type"
#define xx_Auto3625   "Type"
#define en__Auto3625   ""
#define fr__Auto3625   ""
#define it__Auto3625   ""
#define es__Auto3625   ""
#define de__Auto3625   ""
#define nl__Auto3625   ""
#define pt__Auto3625   ""
#define xx__Auto3625   ""
#include "vwedit.h"
static int	vfh[16];
private int on_IsUnderline_event(struct vwedit_context * _Context);
private int on_fgSelect_event(struct vwedit_context * _Context);

/*	------------------------	*/
/*	p o s i t i o n _ a t ()	*/
/*	------------------------	*/
void	vwedit_position_at(struct vwedit_context * _Context,int x,int y){
	_Context->x_WidgetProperties=x;
	_Context->y_WidgetProperties=y;

}

/*	----------------	*/
/*	S e t V a r s ()	*/
/*	----------------	*/
void	vwedit_SetVars(struct vwedit_context * _Context){
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
	visual_transferin(_Context->buffer_PayLoad,255,pSpecificWidgetProperties->pPayLoad);
	visual_transferin(_Context->buffer_Identity,255,pSpecificWidgetProperties->pIdentity);
	visual_transferin(_Context->buffer_Format,255,pSpecificWidgetProperties->pFormat);
	visual_signature("SSS","SSS");
	visual_transferin(_Context->buffer_StyleSheet,255,pSpecificWidgetProperties->pStyleSheet);
	visual_transferin(_Context->buffer_FocusStyle,255,pSpecificWidgetProperties->pStyleFocus);
	visual_transferin(_Context->buffer_Hint,255,pSpecificWidgetProperties->pHint);
	if(!(pSpecificWidgetProperties->pWidgetClass))
	_Context->value_WidgetClass=0;
	else _Context->value_WidgetClass=*((int*)pSpecificWidgetProperties->pWidgetClass);
	if(!(pSpecificWidgetProperties->pAlign))
	_Context->value_Align=0;
	else _Context->value_Align=*((int*)pSpecificWidgetProperties->pAlign);
	if(!(pSpecificWidgetProperties->pType))
	_Context->value_Type=0;
	else _Context->value_Type=*((int*)pSpecificWidgetProperties->pType);
	if(!(pSpecificWidgetProperties->pIsBold))
	_Context->value_IsBold=0;
	else _Context->value_IsBold=*((int*)pSpecificWidgetProperties->pIsBold);
	if(!(pSpecificWidgetProperties->pIsUnderline))
	_Context->value_IsUnderline=0;
	else _Context->value_IsUnderline=*((int*)pSpecificWidgetProperties->pIsUnderline);
	if(!(pSpecificWidgetProperties->pIsLock))
	_Context->value_IsLock=0;
	else _Context->value_IsLock=*((int*)pSpecificWidgetProperties->pIsLock);
	if(!(pSpecificWidgetProperties->pIsInterface))
	_Context->value_IsInterface=0;
	else _Context->value_IsInterface=*((int*)pSpecificWidgetProperties->pIsInterface);
	if(!(pSpecificWidgetProperties->pIsSpecial))
	_Context->value_IsSpecial=0;
	else _Context->value_IsSpecial=*((int*)pSpecificWidgetProperties->pIsSpecial);
	if(!(pSpecificWidgetProperties->pCursorType))
	_Context->value_CursorType=0;
	else _Context->value_CursorType=*((int*)pSpecificWidgetProperties->pCursorType);
	if(!(pSpecificWidgetProperties->pIswResize))
	_Context->value_IswResize=0;
	else _Context->value_IswResize=*((int*)pSpecificWidgetProperties->pIswResize);
	if(!(pSpecificWidgetProperties->pIshResize))
	_Context->value_IshResize=0;
	else _Context->value_IshResize=*((int*)pSpecificWidgetProperties->pIshResize);
	if(!(pSpecificWidgetProperties->pInhibit))
	_Context->value_IsInhibit=0;
	else _Context->value_IsInhibit=*((int*)pSpecificWidgetProperties->pInhibit);

}

/*	----------------	*/
/*	G e t V a r s ()	*/
/*	----------------	*/
void	vwedit_GetVars(struct vwedit_context * _Context){
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
	visual_signature("SSS","SSS");
	visual_transferout(_Context->buffer_StyleSheet,255,pSpecificWidgetProperties->pStyleSheet);
	visual_transferout(_Context->buffer_FocusStyle,255,pSpecificWidgetProperties->pStyleFocus);
	visual_transferout(_Context->buffer_Hint,255,pSpecificWidgetProperties->pHint);
	if(pSpecificWidgetProperties->pWidgetClass!=(char*)0)
	*((int*)pSpecificWidgetProperties->pWidgetClass)=_Context->value_WidgetClass;
	if(pSpecificWidgetProperties->pCursorType!=(char*)0)
	*((int*)pSpecificWidgetProperties->pCursorType)=_Context->value_CursorType;
	if(pSpecificWidgetProperties->pAlign!=(char*)0)
	*((int*)pSpecificWidgetProperties->pAlign)=_Context->value_Align;
	if(pSpecificWidgetProperties->pType!=(char*)0)
	*((int*)pSpecificWidgetProperties->pType)=_Context->value_Type;
	if(pSpecificWidgetProperties->pIsBold!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsBold)=_Context->value_IsBold;
	if(pSpecificWidgetProperties->pIsUnderline!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsUnderline)=_Context->value_IsUnderline;
	if(pSpecificWidgetProperties->pIsLock!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsLock)=_Context->value_IsLock;
	if(pSpecificWidgetProperties->pIsInterface!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsInterface)=_Context->value_IsInterface;
	if(pSpecificWidgetProperties->pIsSpecial!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsSpecial)=_Context->value_IsSpecial;
	if(pSpecificWidgetProperties->pIswResize!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIswResize)=_Context->value_IswResize;
	if(pSpecificWidgetProperties->pIshResize!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIshResize)=_Context->value_IshResize;
	if(pSpecificWidgetProperties->pInhibit!=(char*)0)
	*((int*)pSpecificWidgetProperties->pInhibit)=_Context->value_IsInhibit;

}

public	int	vwedit_attach()
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
		vfh[10] = visual_font("bmap0414.fmf",12);
		initialise_mouse();
		}
	return(0);
}

public	int	vwedit_attach_mode(int mode)
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
		vfh[10] = visual_font("bmap0414.fmf",12);
		initialise_mouse();
		}
	return(0);
}

public	int	vwedit_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	vwedit_create(struct vwedit_context **cptr)
{

	int i;
	struct vwedit_context * _Context=(struct vwedit_context*)0;
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
	if (!(_Context = allocate( sizeof( struct vwedit_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=27;
		_Context->value_IsInhibit=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Identity+i)=' ';
		_Context->value_WidgetClass=0;
		_Context->value_Type=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Format+i)=' ';
		_Context->value_IsSpecial=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Hint+i)=' ';
		_Context->value_IsLock=0;
		_Context->value_IsInterface=0;
		for (i=0; i < 7; i++)  *(_Context->buffer_AtX+i)=' ';
		_Context->value_TextFont=0;
		for (i=0; i < 7; i++)  *(_Context->buffer_AtY+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Width+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Height+i)=' ';
		_Context->value_Align=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_PayLoad+i)=' ';
		_Context->value_IswResize=0;
		_Context->value_IshResize=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_StyleSheet+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_FocusStyle+i)=' ';
		_Context->value_CursorType=0;
		_Context->value_IsBold=0;
		_Context->value_IsUnderline=0;
		for (i=0; i < 6; i++)  *(_Context->buffer_TextColour+i)=' ';
		for (i=0; i < 6; i++)  *(_Context->buffer_Background+i)=' ';
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
	for (i=0; i < 8; i++)_Context->msg_Auto3605[i]=" ";
	_Context->msg_Auto3605[0]=en_Auto3605;
	_Context->msg_Auto3605[1]=fr_Auto3605;
	_Context->msg_Auto3605[2]=it_Auto3605;
	_Context->msg_Auto3605[3]=es_Auto3605;
	_Context->msg_Auto3605[4]=de_Auto3605;
	_Context->msg_Auto3605[5]=nl_Auto3605;
	_Context->msg_Auto3605[6]=pt_Auto3605;
	_Context->msg_Auto3605[7]=xx_Auto3605;
	_Context->hint_Auto3605[0]=en__Auto3605;
	_Context->hint_Auto3605[1]=fr__Auto3605;
	_Context->hint_Auto3605[2]=it__Auto3605;
	_Context->hint_Auto3605[3]=es__Auto3605;
	_Context->hint_Auto3605[4]=de__Auto3605;
	_Context->hint_Auto3605[5]=nl__Auto3605;
	_Context->hint_Auto3605[6]=pt__Auto3605;
	_Context->hint_Auto3605[7]=xx__Auto3605;
	for (i=0; i < 8; i++)_Context->msg_Auto3607[i]=" ";
	_Context->msg_Auto3607[0]=en_Auto3607;
	_Context->msg_Auto3607[1]=fr_Auto3607;
	_Context->msg_Auto3607[2]=it_Auto3607;
	_Context->msg_Auto3607[3]=es_Auto3607;
	_Context->msg_Auto3607[4]=de_Auto3607;
	_Context->msg_Auto3607[5]=nl_Auto3607;
	_Context->msg_Auto3607[6]=pt_Auto3607;
	_Context->msg_Auto3607[7]=xx_Auto3607;
	_Context->hint_Auto3607[0]=en__Auto3607;
	_Context->hint_Auto3607[1]=fr__Auto3607;
	_Context->hint_Auto3607[2]=it__Auto3607;
	_Context->hint_Auto3607[3]=es__Auto3607;
	_Context->hint_Auto3607[4]=de__Auto3607;
	_Context->hint_Auto3607[5]=nl__Auto3607;
	_Context->hint_Auto3607[6]=pt__Auto3607;
	_Context->hint_Auto3607[7]=xx__Auto3607;
	for (i=0; i < 8; i++)_Context->msg_Auto3608[i]=" ";
	_Context->msg_Auto3608[0]=en_Auto3608;
	_Context->msg_Auto3608[1]=fr_Auto3608;
	_Context->msg_Auto3608[2]=it_Auto3608;
	_Context->msg_Auto3608[3]=es_Auto3608;
	_Context->msg_Auto3608[4]=de_Auto3608;
	_Context->msg_Auto3608[5]=nl_Auto3608;
	_Context->msg_Auto3608[6]=pt_Auto3608;
	_Context->msg_Auto3608[7]=xx_Auto3608;
	_Context->hint_Auto3608[0]=en__Auto3608;
	_Context->hint_Auto3608[1]=fr__Auto3608;
	_Context->hint_Auto3608[2]=it__Auto3608;
	_Context->hint_Auto3608[3]=es__Auto3608;
	_Context->hint_Auto3608[4]=de__Auto3608;
	_Context->hint_Auto3608[5]=nl__Auto3608;
	_Context->hint_Auto3608[6]=pt__Auto3608;
	_Context->hint_Auto3608[7]=xx__Auto3608;
	for (i=0; i < 8; i++)_Context->msg_IsInhibit[i]=" ";
	_Context->msg_IsInhibit[0]=en_IsInhibit;
	_Context->msg_IsInhibit[1]=fr_IsInhibit;
	_Context->msg_IsInhibit[2]=it_IsInhibit;
	_Context->msg_IsInhibit[3]=es_IsInhibit;
	_Context->msg_IsInhibit[4]=de_IsInhibit;
	_Context->msg_IsInhibit[5]=nl_IsInhibit;
	_Context->msg_IsInhibit[6]=pt_IsInhibit;
	_Context->msg_IsInhibit[7]=xx_IsInhibit;
	_Context->hint_IsInhibit[0]=en__IsInhibit;
	_Context->hint_IsInhibit[1]=fr__IsInhibit;
	_Context->hint_IsInhibit[2]=it__IsInhibit;
	_Context->hint_IsInhibit[3]=es__IsInhibit;
	_Context->hint_IsInhibit[4]=de__IsInhibit;
	_Context->hint_IsInhibit[5]=nl__IsInhibit;
	_Context->hint_IsInhibit[6]=pt__IsInhibit;
	_Context->hint_IsInhibit[7]=xx__IsInhibit;
	for (i=0; i < 8; i++)_Context->msg_Auto3609[i]=" ";
	_Context->msg_Auto3609[0]=en_Auto3609;
	_Context->msg_Auto3609[1]=fr_Auto3609;
	_Context->msg_Auto3609[2]=it_Auto3609;
	_Context->msg_Auto3609[3]=es_Auto3609;
	_Context->msg_Auto3609[4]=de_Auto3609;
	_Context->msg_Auto3609[5]=nl_Auto3609;
	_Context->msg_Auto3609[6]=pt_Auto3609;
	_Context->msg_Auto3609[7]=xx_Auto3609;
	_Context->hint_Auto3609[0]=en__Auto3609;
	_Context->hint_Auto3609[1]=fr__Auto3609;
	_Context->hint_Auto3609[2]=it__Auto3609;
	_Context->hint_Auto3609[3]=es__Auto3609;
	_Context->hint_Auto3609[4]=de__Auto3609;
	_Context->hint_Auto3609[5]=nl__Auto3609;
	_Context->hint_Auto3609[6]=pt__Auto3609;
	_Context->hint_Auto3609[7]=xx__Auto3609;
	for (i=0; i < 8; i++)_Context->msg_Auto3610[i]=" ";
	_Context->msg_Auto3610[0]=en_Auto3610;
	_Context->msg_Auto3610[1]=fr_Auto3610;
	_Context->msg_Auto3610[2]=it_Auto3610;
	_Context->msg_Auto3610[3]=es_Auto3610;
	_Context->msg_Auto3610[4]=de_Auto3610;
	_Context->msg_Auto3610[5]=nl_Auto3610;
	_Context->msg_Auto3610[6]=pt_Auto3610;
	_Context->msg_Auto3610[7]=xx_Auto3610;
	_Context->hint_Auto3610[0]=en__Auto3610;
	_Context->hint_Auto3610[1]=fr__Auto3610;
	_Context->hint_Auto3610[2]=it__Auto3610;
	_Context->hint_Auto3610[3]=es__Auto3610;
	_Context->hint_Auto3610[4]=de__Auto3610;
	_Context->hint_Auto3610[5]=nl__Auto3610;
	_Context->hint_Auto3610[6]=pt__Auto3610;
	_Context->hint_Auto3610[7]=xx__Auto3610;
	for (i=0; i < 8; i++)_Context->msg_Auto3611[i]=" ";
	_Context->msg_Auto3611[0]=en_Auto3611;
	_Context->msg_Auto3611[1]=fr_Auto3611;
	_Context->msg_Auto3611[2]=it_Auto3611;
	_Context->msg_Auto3611[3]=es_Auto3611;
	_Context->msg_Auto3611[4]=de_Auto3611;
	_Context->msg_Auto3611[5]=nl_Auto3611;
	_Context->msg_Auto3611[6]=pt_Auto3611;
	_Context->msg_Auto3611[7]=xx_Auto3611;
	_Context->hint_Auto3611[0]=en__Auto3611;
	_Context->hint_Auto3611[1]=fr__Auto3611;
	_Context->hint_Auto3611[2]=it__Auto3611;
	_Context->hint_Auto3611[3]=es__Auto3611;
	_Context->hint_Auto3611[4]=de__Auto3611;
	_Context->hint_Auto3611[5]=nl__Auto3611;
	_Context->hint_Auto3611[6]=pt__Auto3611;
	_Context->hint_Auto3611[7]=xx__Auto3611;
	for (i=0; i < 8; i++)_Context->msg_Auto3612[i]=" ";
	_Context->msg_Auto3612[0]=en_Auto3612;
	_Context->msg_Auto3612[1]=fr_Auto3612;
	_Context->msg_Auto3612[2]=it_Auto3612;
	_Context->msg_Auto3612[3]=es_Auto3612;
	_Context->msg_Auto3612[4]=de_Auto3612;
	_Context->msg_Auto3612[5]=nl_Auto3612;
	_Context->msg_Auto3612[6]=pt_Auto3612;
	_Context->msg_Auto3612[7]=xx_Auto3612;
	_Context->hint_Auto3612[0]=en__Auto3612;
	_Context->hint_Auto3612[1]=fr__Auto3612;
	_Context->hint_Auto3612[2]=it__Auto3612;
	_Context->hint_Auto3612[3]=es__Auto3612;
	_Context->hint_Auto3612[4]=de__Auto3612;
	_Context->hint_Auto3612[5]=nl__Auto3612;
	_Context->hint_Auto3612[6]=pt__Auto3612;
	_Context->hint_Auto3612[7]=xx__Auto3612;
	for (i=0; i < 8; i++)_Context->msg_Auto3613[i]=" ";
	_Context->msg_Auto3613[0]=en_Auto3613;
	_Context->msg_Auto3613[1]=fr_Auto3613;
	_Context->msg_Auto3613[2]=it_Auto3613;
	_Context->msg_Auto3613[3]=es_Auto3613;
	_Context->msg_Auto3613[4]=de_Auto3613;
	_Context->msg_Auto3613[5]=nl_Auto3613;
	_Context->msg_Auto3613[6]=pt_Auto3613;
	_Context->msg_Auto3613[7]=xx_Auto3613;
	_Context->hint_Auto3613[0]=en__Auto3613;
	_Context->hint_Auto3613[1]=fr__Auto3613;
	_Context->hint_Auto3613[2]=it__Auto3613;
	_Context->hint_Auto3613[3]=es__Auto3613;
	_Context->hint_Auto3613[4]=de__Auto3613;
	_Context->hint_Auto3613[5]=nl__Auto3613;
	_Context->hint_Auto3613[6]=pt__Auto3613;
	_Context->hint_Auto3613[7]=xx__Auto3613;
	_Context->hint_Identity[0]=en__Identity;
	_Context->hint_Identity[1]=fr__Identity;
	for (i=0; i < 8; i++)_Context->msg_WidgetClass[i]=" ";
	_Context->hint_WidgetClass[0]=en__WidgetClass;
	for (i=0; i < 8; i++)_Context->msg_Type[i]=" ";
	_Context->hint_Type[0]=en__Type;
	_Context->hint_Type[1]=fr__Type;
	_Context->hint_Format[0]=en__Format;
	for (i=0; i < 8; i++)_Context->msg_IsSpecial[i]=" ";
	_Context->msg_IsSpecial[0]=en_IsSpecial;
	_Context->msg_IsSpecial[1]=fr_IsSpecial;
	_Context->msg_IsSpecial[2]=it_IsSpecial;
	_Context->msg_IsSpecial[3]=es_IsSpecial;
	_Context->msg_IsSpecial[4]=de_IsSpecial;
	_Context->msg_IsSpecial[5]=nl_IsSpecial;
	_Context->msg_IsSpecial[6]=pt_IsSpecial;
	_Context->msg_IsSpecial[7]=xx_IsSpecial;
	_Context->hint_IsSpecial[0]=en__IsSpecial;
	_Context->hint_IsSpecial[1]=fr__IsSpecial;
	_Context->hint_IsSpecial[2]=it__IsSpecial;
	_Context->hint_IsSpecial[3]=es__IsSpecial;
	_Context->hint_IsSpecial[4]=de__IsSpecial;
	_Context->hint_IsSpecial[5]=nl__IsSpecial;
	_Context->hint_IsSpecial[6]=pt__IsSpecial;
	_Context->hint_IsSpecial[7]=xx__IsSpecial;
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
	_Context->hint_IsInterface[1]=fr__IsInterface;
	_Context->hint_IsInterface[2]=it__IsInterface;
	_Context->hint_IsInterface[3]=es__IsInterface;
	_Context->hint_IsInterface[4]=de__IsInterface;
	_Context->hint_IsInterface[5]=nl__IsInterface;
	_Context->hint_IsInterface[6]=pt__IsInterface;
	_Context->hint_IsInterface[7]=xx__IsInterface;
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
	_Context->hint_StyleSheet[0]=en__StyleSheet;
	_Context->hint_StyleSheet[1]=fr__StyleSheet;
	_Context->hint_FocusStyle[0]=en__FocusStyle;
	_Context->hint_FocusStyle[1]=fr__FocusStyle;
	for (i=0; i < 8; i++)_Context->msg_CursorType[i]=" ";
	_Context->msg_CursorType[0]=en_CursorType;
	_Context->msg_CursorType[1]=fr_CursorType;
	_Context->msg_CursorType[2]=it_CursorType;
	_Context->msg_CursorType[3]=es_CursorType;
	_Context->msg_CursorType[4]=de_CursorType;
	_Context->msg_CursorType[5]=nl_CursorType;
	_Context->msg_CursorType[6]=pt_CursorType;
	_Context->msg_CursorType[7]=xx_CursorType;
	_Context->hint_CursorType[0]=en__CursorType;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3614[i]=" ";
	_Context->msg_Auto3614[0]=en_Auto3614;
	_Context->msg_Auto3614[1]=fr_Auto3614;
	_Context->msg_Auto3614[2]=it_Auto3614;
	_Context->msg_Auto3614[3]=es_Auto3614;
	_Context->msg_Auto3614[4]=de_Auto3614;
	_Context->msg_Auto3614[5]=nl_Auto3614;
	_Context->msg_Auto3614[6]=pt_Auto3614;
	_Context->msg_Auto3614[7]=xx_Auto3614;
	_Context->hint_Auto3614[0]=en__Auto3614;
	_Context->hint_Auto3614[1]=fr__Auto3614;
	_Context->hint_Auto3614[2]=it__Auto3614;
	_Context->hint_Auto3614[3]=es__Auto3614;
	_Context->hint_Auto3614[4]=de__Auto3614;
	_Context->hint_Auto3614[5]=nl__Auto3614;
	_Context->hint_Auto3614[6]=pt__Auto3614;
	_Context->hint_Auto3614[7]=xx__Auto3614;
	for (i=0; i < 8; i++)_Context->msg_Auto3615[i]=" ";
	_Context->msg_Auto3615[0]=en_Auto3615;
	_Context->msg_Auto3615[1]=fr_Auto3615;
	_Context->msg_Auto3615[2]=it_Auto3615;
	_Context->msg_Auto3615[3]=es_Auto3615;
	_Context->msg_Auto3615[4]=de_Auto3615;
	_Context->msg_Auto3615[5]=nl_Auto3615;
	_Context->msg_Auto3615[6]=pt_Auto3615;
	_Context->msg_Auto3615[7]=xx_Auto3615;
	_Context->hint_Auto3615[0]=en__Auto3615;
	_Context->hint_Auto3615[1]=fr__Auto3615;
	_Context->hint_Auto3615[2]=it__Auto3615;
	_Context->hint_Auto3615[3]=es__Auto3615;
	_Context->hint_Auto3615[4]=de__Auto3615;
	_Context->hint_Auto3615[5]=nl__Auto3615;
	_Context->hint_Auto3615[6]=pt__Auto3615;
	_Context->hint_Auto3615[7]=xx__Auto3615;
	for (i=0; i < 8; i++)_Context->msg_Auto3616[i]=" ";
	_Context->msg_Auto3616[0]=en_Auto3616;
	_Context->msg_Auto3616[1]=fr_Auto3616;
	_Context->msg_Auto3616[2]=it_Auto3616;
	_Context->msg_Auto3616[3]=es_Auto3616;
	_Context->msg_Auto3616[4]=de_Auto3616;
	_Context->msg_Auto3616[5]=nl_Auto3616;
	_Context->msg_Auto3616[6]=pt_Auto3616;
	_Context->msg_Auto3616[7]=xx_Auto3616;
	_Context->hint_Auto3616[0]=en__Auto3616;
	_Context->hint_Auto3616[1]=fr__Auto3616;
	_Context->hint_Auto3616[2]=it__Auto3616;
	_Context->hint_Auto3616[3]=es__Auto3616;
	_Context->hint_Auto3616[4]=de__Auto3616;
	_Context->hint_Auto3616[5]=nl__Auto3616;
	_Context->hint_Auto3616[6]=pt__Auto3616;
	_Context->hint_Auto3616[7]=xx__Auto3616;
	for (i=0; i < 8; i++)_Context->msg_Auto3617[i]=" ";
	_Context->msg_Auto3617[0]=en_Auto3617;
	_Context->msg_Auto3617[1]=fr_Auto3617;
	_Context->msg_Auto3617[2]=it_Auto3617;
	_Context->msg_Auto3617[3]=es_Auto3617;
	_Context->msg_Auto3617[4]=de_Auto3617;
	_Context->msg_Auto3617[5]=nl_Auto3617;
	_Context->msg_Auto3617[6]=pt_Auto3617;
	_Context->msg_Auto3617[7]=xx_Auto3617;
	_Context->hint_Auto3617[0]=en__Auto3617;
	_Context->hint_Auto3617[1]=fr__Auto3617;
	_Context->hint_Auto3617[2]=it__Auto3617;
	_Context->hint_Auto3617[3]=es__Auto3617;
	_Context->hint_Auto3617[4]=de__Auto3617;
	_Context->hint_Auto3617[5]=nl__Auto3617;
	_Context->hint_Auto3617[6]=pt__Auto3617;
	_Context->hint_Auto3617[7]=xx__Auto3617;
	_Context->hint_TextColour[0]=en__TextColour;
	_Context->hint_Background[0]=en__Background;
	for (i=0; i < 8; i++)_Context->msg_Auto3618[i]=" ";
	_Context->msg_Auto3618[0]=en_Auto3618;
	_Context->msg_Auto3618[1]=fr_Auto3618;
	_Context->msg_Auto3618[2]=it_Auto3618;
	_Context->msg_Auto3618[3]=es_Auto3618;
	_Context->msg_Auto3618[4]=de_Auto3618;
	_Context->msg_Auto3618[5]=nl_Auto3618;
	_Context->msg_Auto3618[6]=pt_Auto3618;
	_Context->msg_Auto3618[7]=xx_Auto3618;
	_Context->hint_Auto3618[0]=en__Auto3618;
	_Context->hint_Auto3618[1]=fr__Auto3618;
	_Context->hint_Auto3618[2]=it__Auto3618;
	_Context->hint_Auto3618[3]=es__Auto3618;
	_Context->hint_Auto3618[4]=de__Auto3618;
	_Context->hint_Auto3618[5]=nl__Auto3618;
	_Context->hint_Auto3618[6]=pt__Auto3618;
	_Context->hint_Auto3618[7]=xx__Auto3618;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3619[i]=" ";
	_Context->msg_Auto3619[0]=en_Auto3619;
	_Context->msg_Auto3619[1]=fr_Auto3619;
	_Context->msg_Auto3619[2]=it_Auto3619;
	_Context->msg_Auto3619[3]=es_Auto3619;
	_Context->msg_Auto3619[4]=de_Auto3619;
	_Context->msg_Auto3619[5]=nl_Auto3619;
	_Context->msg_Auto3619[6]=pt_Auto3619;
	_Context->msg_Auto3619[7]=xx_Auto3619;
	_Context->hint_Auto3619[0]=en__Auto3619;
	_Context->hint_Auto3619[1]=fr__Auto3619;
	_Context->hint_Auto3619[2]=it__Auto3619;
	_Context->hint_Auto3619[3]=es__Auto3619;
	_Context->hint_Auto3619[4]=de__Auto3619;
	_Context->hint_Auto3619[5]=nl__Auto3619;
	_Context->hint_Auto3619[6]=pt__Auto3619;
	_Context->hint_Auto3619[7]=xx__Auto3619;
	for (i=0; i < 8; i++)_Context->msg_Auto3620[i]=" ";
	_Context->msg_Auto3620[0]=en_Auto3620;
	_Context->msg_Auto3620[1]=fr_Auto3620;
	_Context->msg_Auto3620[2]=it_Auto3620;
	_Context->msg_Auto3620[3]=es_Auto3620;
	_Context->msg_Auto3620[4]=de_Auto3620;
	_Context->msg_Auto3620[5]=nl_Auto3620;
	_Context->msg_Auto3620[6]=pt_Auto3620;
	_Context->msg_Auto3620[7]=xx_Auto3620;
	_Context->hint_Auto3620[0]=en__Auto3620;
	_Context->hint_Auto3620[1]=fr__Auto3620;
	_Context->hint_Auto3620[2]=it__Auto3620;
	_Context->hint_Auto3620[3]=es__Auto3620;
	_Context->hint_Auto3620[4]=de__Auto3620;
	_Context->hint_Auto3620[5]=nl__Auto3620;
	_Context->hint_Auto3620[6]=pt__Auto3620;
	_Context->hint_Auto3620[7]=xx__Auto3620;
	for (i=0; i < 8; i++)_Context->msg_Auto3621[i]=" ";
	_Context->msg_Auto3621[0]=en_Auto3621;
	_Context->msg_Auto3621[1]=fr_Auto3621;
	_Context->msg_Auto3621[2]=it_Auto3621;
	_Context->msg_Auto3621[3]=es_Auto3621;
	_Context->msg_Auto3621[4]=de_Auto3621;
	_Context->msg_Auto3621[5]=nl_Auto3621;
	_Context->msg_Auto3621[6]=pt_Auto3621;
	_Context->msg_Auto3621[7]=xx_Auto3621;
	_Context->hint_Auto3621[0]=en__Auto3621;
	_Context->hint_Auto3621[1]=fr__Auto3621;
	_Context->hint_Auto3621[2]=it__Auto3621;
	_Context->hint_Auto3621[3]=es__Auto3621;
	_Context->hint_Auto3621[4]=de__Auto3621;
	_Context->hint_Auto3621[5]=nl__Auto3621;
	_Context->hint_Auto3621[6]=pt__Auto3621;
	_Context->hint_Auto3621[7]=xx__Auto3621;
	for (i=0; i < 8; i++)_Context->msg_Auto3622[i]=" ";
	_Context->msg_Auto3622[0]=en_Auto3622;
	_Context->msg_Auto3622[1]=fr_Auto3622;
	_Context->msg_Auto3622[2]=it_Auto3622;
	_Context->msg_Auto3622[3]=es_Auto3622;
	_Context->msg_Auto3622[4]=de_Auto3622;
	_Context->msg_Auto3622[5]=nl_Auto3622;
	_Context->msg_Auto3622[6]=pt_Auto3622;
	_Context->msg_Auto3622[7]=xx_Auto3622;
	_Context->hint_Auto3622[0]=en__Auto3622;
	_Context->hint_Auto3622[1]=fr__Auto3622;
	_Context->hint_Auto3622[2]=it__Auto3622;
	_Context->hint_Auto3622[3]=es__Auto3622;
	_Context->hint_Auto3622[4]=de__Auto3622;
	_Context->hint_Auto3622[5]=nl__Auto3622;
	_Context->hint_Auto3622[6]=pt__Auto3622;
	_Context->hint_Auto3622[7]=xx__Auto3622;
	for (i=0; i < 8; i++)_Context->msg_Auto3623[i]=" ";
	_Context->msg_Auto3623[0]=en_Auto3623;
	_Context->msg_Auto3623[1]=fr_Auto3623;
	_Context->msg_Auto3623[2]=it_Auto3623;
	_Context->msg_Auto3623[3]=es_Auto3623;
	_Context->msg_Auto3623[4]=de_Auto3623;
	_Context->msg_Auto3623[5]=nl_Auto3623;
	_Context->msg_Auto3623[6]=pt_Auto3623;
	_Context->msg_Auto3623[7]=xx_Auto3623;
	_Context->hint_Auto3623[0]=en__Auto3623;
	_Context->hint_Auto3623[1]=fr__Auto3623;
	_Context->hint_Auto3623[2]=it__Auto3623;
	_Context->hint_Auto3623[3]=es__Auto3623;
	_Context->hint_Auto3623[4]=de__Auto3623;
	_Context->hint_Auto3623[5]=nl__Auto3623;
	_Context->hint_Auto3623[6]=pt__Auto3623;
	_Context->hint_Auto3623[7]=xx__Auto3623;
	for (i=0; i < 8; i++)_Context->msg_Auto3624[i]=" ";
	_Context->msg_Auto3624[0]=en_Auto3624;
	_Context->msg_Auto3624[1]=fr_Auto3624;
	_Context->msg_Auto3624[2]=it_Auto3624;
	_Context->msg_Auto3624[3]=es_Auto3624;
	_Context->msg_Auto3624[4]=de_Auto3624;
	_Context->msg_Auto3624[5]=nl_Auto3624;
	_Context->msg_Auto3624[6]=pt_Auto3624;
	_Context->msg_Auto3624[7]=xx_Auto3624;
	_Context->hint_Auto3624[0]=en__Auto3624;
	_Context->hint_Auto3624[1]=fr__Auto3624;
	_Context->hint_Auto3624[2]=it__Auto3624;
	_Context->hint_Auto3624[3]=es__Auto3624;
	_Context->hint_Auto3624[4]=de__Auto3624;
	_Context->hint_Auto3624[5]=nl__Auto3624;
	_Context->hint_Auto3624[6]=pt__Auto3624;
	_Context->hint_Auto3624[7]=xx__Auto3624;
	for (i=0; i < 8; i++)_Context->msg_Auto3625[i]=" ";
	_Context->msg_Auto3625[0]=en_Auto3625;
	_Context->msg_Auto3625[1]=fr_Auto3625;
	_Context->msg_Auto3625[2]=it_Auto3625;
	_Context->msg_Auto3625[3]=es_Auto3625;
	_Context->msg_Auto3625[4]=de_Auto3625;
	_Context->msg_Auto3625[5]=nl_Auto3625;
	_Context->msg_Auto3625[6]=pt_Auto3625;
	_Context->msg_Auto3625[7]=xx_Auto3625;
	_Context->hint_Auto3625[0]=en__Auto3625;
	_Context->hint_Auto3625[1]=fr__Auto3625;
	_Context->hint_Auto3625[2]=it__Auto3625;
	_Context->hint_Auto3625[3]=es__Auto3625;
	_Context->hint_Auto3625[4]=de__Auto3625;
	_Context->hint_Auto3625[5]=nl__Auto3625;
	_Context->hint_Auto3625[6]=pt__Auto3625;
	_Context->hint_Auto3625[7]=xx__Auto3625;
	return(0);
}

public 	int	vwedit_hide(struct vwedit_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;

	return(result);
}

public	int	vwedit_remove(struct vwedit_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}

public	int	vwedit_show(struct vwedit_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,"widget_frame",_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]))) != 0)
) {
		visual_window(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,vfh[2],_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]),0x4);
		}
	visual_text(_Context->x_WidgetProperties+453,_Context->y_WidgetProperties+151,210,16,vfh[2],16,0,_Context->msg_Auto3605[_Context->language],strlen(_Context->msg_Auto3605[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+453,_Context->y_WidgetProperties+167,210,62,4);
	visual_filzone(_Context->x_WidgetProperties+251,_Context->y_WidgetProperties+262,1,1,27,0);
	visual_text(_Context->x_WidgetProperties+5,_Context->y_WidgetProperties+230,660,16,vfh[2],16,0,_Context->msg_Auto3607[_Context->language],strlen(_Context->msg_Auto3607[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+5,_Context->y_WidgetProperties+246,660,150,4);
	visual_text(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+29,210,16,vfh[2],16,0,_Context->msg_Auto3608[_Context->language],strlen(_Context->msg_Auto3608[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+45,210,104,4);
	visual_select(_Context->x_WidgetProperties+461,_Context->y_WidgetProperties+120,114,46,vfh[2],0,0,parse_selection(_Context->msg_IsInhibit[_Context->language],&_Context->value_IsInhibit),768);
	visual_text(_Context->x_WidgetProperties+4,_Context->y_WidgetProperties+30,441,16,vfh[2],16,0,_Context->msg_Auto3609[_Context->language],strlen(_Context->msg_Auto3609[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+4,_Context->y_WidgetProperties+46,441,184,4);
	visual_text(_Context->x_WidgetProperties+461,_Context->y_WidgetProperties+185,14,21,vfh[2],16,0,_Context->msg_Auto3610[_Context->language],strlen(_Context->msg_Auto3610[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+615,_Context->y_WidgetProperties+185,50,21,vfh[2],16,0,_Context->msg_Auto3611[_Context->language],strlen(_Context->msg_Auto3611[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+560,_Context->y_WidgetProperties+185,50,21,vfh[2],16,0,_Context->msg_Auto3612[_Context->language],strlen(_Context->msg_Auto3612[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+505,_Context->y_WidgetProperties+185,14,21,vfh[2],16,0,_Context->msg_Auto3613[_Context->language],strlen(_Context->msg_Auto3613[_Context->language]),2);
	visual_frame(_Context->x_WidgetProperties+11,_Context->y_WidgetProperties+65,184+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+11+1,_Context->y_WidgetProperties+65+1,184,16,vfh[1],34,0,_Context->buffer_Identity,255,0);
	visual_select(_Context->x_WidgetProperties+230,_Context->y_WidgetProperties+65,196,144,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),768);
	visual_select(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+110,182,128,vfh[2],0,0,parse_selection(WidgetTypeList,&_Context->value_Type),768);
	visual_frame(_Context->x_WidgetProperties+233,_Context->y_WidgetProperties+112,192+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+233+1,_Context->y_WidgetProperties+112+1,192,16,vfh[1],27,0,_Context->buffer_Format,255,0);
	_Context->trigger_IsSpecial=visual_trigger_code(_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]));
	visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+99,190,16,vfh[2],28,28,_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]),_Context->value_IsSpecial|0);
	visual_frame(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+154,424+2,64+2,5);
	visual_text(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+154+1,424,64,vfh[1],0,0,_Context->buffer_Hint,255,0);
	_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+54,170,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
	_Context->trigger_IsInterface=visual_trigger_code(_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]));
	visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+77,180,16,vfh[2],28,28,_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]),_Context->value_IsInterface|0);
	visual_frame(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+202,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+460+1,_Context->y_WidgetProperties+202+1,35,16,vfh[1],34,0,_Context->buffer_AtX,7,0);
	visual_select(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+270,126,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),768);
	visual_frame(_Context->x_WidgetProperties+505,_Context->y_WidgetProperties+202,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+505+1,_Context->y_WidgetProperties+202+1,35,16,vfh[1],34,0,_Context->buffer_AtY,7,0);
	visual_frame(_Context->x_WidgetProperties+561,_Context->y_WidgetProperties+202,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+561+1,_Context->y_WidgetProperties+202+1,35,16,vfh[1],34,0,_Context->buffer_Width,7,0);
	visual_frame(_Context->x_WidgetProperties+615,_Context->y_WidgetProperties+202,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+615+1,_Context->y_WidgetProperties+202+1,35,16,vfh[1],34,0,_Context->buffer_Height,7,0);
	visual_select(_Context->x_WidgetProperties+170,_Context->y_WidgetProperties+270,130,100,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),768);
	visual_frame(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+320,424+2,32+2,5);
	visual_text(_Context->x_WidgetProperties+20+1,_Context->y_WidgetProperties+320+1,424,32,vfh[1],34,0,_Context->buffer_PayLoad,255,0);
	_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+21,_Context->y_WidgetProperties+370,182,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
	_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+220,_Context->y_WidgetProperties+370,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
	visual_frame(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+270,190+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+460+1,_Context->y_WidgetProperties+270+1,190,16,vfh[1],0,0,_Context->buffer_StyleSheet,255,0);
	visual_frame(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+290,190+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+460+1,_Context->y_WidgetProperties+290+1,190,16,vfh[1],0,0,_Context->buffer_FocusStyle,255,0);
	visual_select(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+330,184,15,vfh[1],0,0,parse_selection(_Context->msg_CursorType[_Context->language],&_Context->value_CursorType),0);
	_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+370,84,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
	_Context->trigger_IsUnderline=visual_trigger_code(_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]));
	visual_check(_Context->x_WidgetProperties+550,_Context->y_WidgetProperties+370,98,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),_Context->value_IsUnderline|0);
	visual_text(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+253,150,16,vfh[2],16,0,_Context->msg_Auto3614[_Context->language],strlen(_Context->msg_Auto3614[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+300,336,16,vfh[2],16,0,_Context->msg_Auto3615[_Context->language],strlen(_Context->msg_Auto3615[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+461,_Context->y_WidgetProperties+253,182,16,vfh[2],16,0,_Context->msg_Auto3616[_Context->language],strlen(_Context->msg_Auto3616[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+310,182,16,vfh[2],16,0,_Context->msg_Auto3617[_Context->language],strlen(_Context->msg_Auto3617[_Context->language]),2);
	visual_frame(_Context->x_WidgetProperties+312,_Context->y_WidgetProperties+270,40+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+312+1,_Context->y_WidgetProperties+270+1,40,16,vfh[1],34,0,_Context->buffer_TextColour,6,0);
	visual_frame(_Context->x_WidgetProperties+398,_Context->y_WidgetProperties+270,40+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+398+1,_Context->y_WidgetProperties+270+1,40,16,vfh[1],34,0,_Context->buffer_Background,6,0);
	visual_text(_Context->x_WidgetProperties+312,_Context->y_WidgetProperties+253,42,16,vfh[2],16,0,_Context->msg_Auto3618[_Context->language],strlen(_Context->msg_Auto3618[_Context->language]),2);
	_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+353,_Context->y_WidgetProperties+270,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
	visual_text(_Context->x_WidgetProperties+398,_Context->y_WidgetProperties+253,42,16,vfh[2],16,0,_Context->msg_Auto3619[_Context->language],strlen(_Context->msg_Auto3619[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+140,182,16,vfh[2],16,0,_Context->msg_Auto3620[_Context->language],strlen(_Context->msg_Auto3620[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+170,_Context->y_WidgetProperties+253,70,16,vfh[2],16,0,_Context->msg_Auto3621[_Context->language],strlen(_Context->msg_Auto3621[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+51,154,16,vfh[2],16,0,_Context->msg_Auto3622[_Context->language],strlen(_Context->msg_Auto3622[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+230,_Context->y_WidgetProperties+51,135,16,vfh[2],16,0,_Context->msg_Auto3623[_Context->language],strlen(_Context->msg_Auto3623[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+232,_Context->y_WidgetProperties+99,196,16,vfh[2],16,0,_Context->msg_Auto3624[_Context->language],strlen(_Context->msg_Auto3624[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+11,_Context->y_WidgetProperties+95,135,16,vfh[2],16,0,_Context->msg_Auto3625[_Context->language],strlen(_Context->msg_Auto3625[_Context->language]),2);
	visual_filzone(_Context->x_WidgetProperties+247,_Context->y_WidgetProperties+264,1,1,27,0);
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

private int WidgetClass_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This Combo allows the CLASS of an existing widget to be changed. ";
			mptr[1]=" The secondary properties associated with the widget and its methods ";
			mptr[2]="will be preserved and will not be changed to the default values of ";
			mptr[3]="the new widget type if the class of a widget is modified using this ";
			mptr[4]="control.   ";
			return(visual_online_help(mptr,5));
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

private int Type_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[16];
			mptr[0] = "This combo selection field allows the data or behavioural type  associated ";
			mptr[1]="with an edit widget to be defined.  ";
			mptr[2]=" ";
			mptr[3]="Edit widgets are normally of type String  and giving rise to the declaration ";
			mptr[4]="of a string buffer variable in the  object container of theparent ";
			mptr[5]="form.  ";
			mptr[6]=" ";
			mptr[7]="The following widget method instructions may be used to access the ";
			mptr[8]="data of widgets of this type.  ";
			mptr[9]=" ";
			mptr[10]="  ";
			mptr[11]=" this.BUFFER   returns the string buffer value  ";
			mptr[12]=" this.SIZE     returns the length of the string buffer  ";
			mptr[13]=" this.VALUE   returns the CONV value of thebuffer.  ";
			mptr[14]=" this.FORMAT   returns the format information associated with the widget. ";
			mptr[15]="       ";
			return(visual_online_help(mptr,16));
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

private int Format_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[36];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]="Format information is to be provided using standard abal format expressions. ";
			mptr[3]=" ";
			mptr[4]=" ";
			mptr[5]="Evaluated dimensions provided by format expression may influence the ";
			mptr[6]="size of the string buffer associated with an edit widget in the following ";
			mptr[7]="manner.  ";
			mptr[8]=" ";
			mptr[9]="The string buffer length is first calculated using the edit widget ";
			mptr[10]="zone  dimensions and the font dimensions as can be seen in the following ";
			mptr[11]="pseudo code :  ";
			mptr[12]=" ";
			mptr[13]="  ";
			mptr[14]="  ";
			mptr[15]=" ";
			mptr[16]="    this.lines = (this.h / this.fontheight)  ";
			mptr[17]=" ";
			mptr[18]="    this.columns = (this.w / this.fontwidth)  ";
			mptr[19]=" ";
			mptr[20]="    if ( format_length > (this.lines * this.columns ))  ";
			mptr[21]=" ";
			mptr[22]="    this.size = format_length  ";
			mptr[23]=" ";
			mptr[24]="    else :: this.size = (this.columns * this.lines) :: endif  ";
			mptr[25]="  ";
			mptr[26]=" ";
			mptr[27]=" Consequently if the explicite length indicated by the format information ";
			mptr[28]="is greater than the implicite zone calculated length the buffer will ";
			mptr[29]="be declared as the explicte size otherwise the zone calculated implicite ";
			mptr[30]="size will beused.  ";
			mptr[31]=" ";
			mptr[32]=" The format information will be used in edit widgets declared as ASK ";
			mptr[33]="instructions in a predictable fashion.  ";
			mptr[34]=" ";
			mptr[35]="      ";
			return(visual_online_help(mptr,36));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Format de la zone d'‚dition. ";
			mptr[1]=" Cette zone permet d'indiquer le format avec la syntaxe ABAL.    ";
			return(visual_online_help(mptr,2));
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
			char * mptr[22];
			mptr[0] = "This option influences the behaviour of the VisualEdit instruction ";
			mptr[1]="generated for edit widgets for which focus reception has been activated. ";
			mptr[2]=" ";
			mptr[3]=" ";
			mptr[4]="When this option has been activated, the VisualEdit instruction will ";
			mptr[5]="return individual keycodes to be processed by the application by instructions ";
			mptr[6]="provided in the LoseFocus method of the widget. Key values returned are stored to ";
			mptr[7]="the forms property KeyCode and are available for consultation and modification by the ";
			mptr[8]="LoseFocus method.  ";
			mptr[9]=" ";
			mptr[10]="Instructions in the LoseFocus method have priority and take immediate ";
			mptr[11]="effect on leaving the VisualEdit instruction.  ";
			mptr[12]=" ";
			mptr[13]="It is very important to correctly handle KeyCode consumption in this ";
			mptr[14]="method.  ";
			mptr[15]=" ";
			mptr[16]="The KeyCode value should be reset to 0 or -1 to indicate to the forms ";
			mptr[17]="event processing cycle that the key event has been  consumed.  ";
			mptr[18]=" ";
			mptr[19]=" This option is of no effect for Ask type edit widgets.  ";
			mptr[20]=" ";
			mptr[21]="   ";
			return(visual_online_help(mptr,22));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Suivi de la saisie. ";
			mptr[1]=" Cette option permet d'appeler la fonction LoseFocus aprŠs la saisie ";
			mptr[2]="de chaque caractŠre.  ";
			return(visual_online_help(mptr,3));
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
			char * mptr[10];
			mptr[0] = "This check box allows the collection of widget properties to be locked ";
			mptr[1]="and consequently protected against accidental modification.  ";
			mptr[2]=" ";
			mptr[3]="The widget lock also protects the widget against being moved using ";
			mptr[4]="the mouse in the forms editor.  ";
			mptr[5]=" ";
			mptr[6]="Locked widgets can not be deleted by the Del key or moved in the tree ";
			mptr[7]="view manager.  ";
			mptr[8]=" ";
			mptr[9]="     ";
			return(visual_online_help(mptr,10));
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

private int IsInterface_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[14];
			mptr[0] = "This check control, when activated, indicates that the initial value ";
			mptr[1]="of the widget storage area is to be received as a parameter value. ";
			mptr[2]=" ";
			mptr[3]=" ";
			mptr[4]="This is possible in the case of modular or overlay  packaging models ";
			mptr[5]="only.  ";
			mptr[6]=" ";
			mptr[7]="The data type, as indicated by the type or behaviour selection control, ";
			mptr[8]="is  of importance to this option and will be used to define the type ";
			mptr[9]="of the  parameter reception variable contributing to signatures of ";
			mptr[10]="the  module interface, oncreate and onremove methods of theparent ";
			mptr[11]="form.  ";
			mptr[12]=" ";
			mptr[13]="   ";
			return(visual_online_help(mptr,14));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Cette case … cocher permet d'envoyerla valeur de ce widget comme paramŠtre ";
			mptr[1]="… un autre formulaire de type module. ";
			mptr[2]=" Pour assurer ce passage vous devrez d‚clarer dans le module, un widget ";
			mptr[3]="de mˆme  type et mˆme nom que celui du programme principal d‚clar‚ ";
			mptr[4]="lui mˆme comme  item d'interface.            ";
			return(visual_online_help(mptr,5));
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
			char * mptr[20];
			mptr[0] = "Alignment information for Edit Widgets will only apply when the data ";
			mptr[1]="type  or behaviour type has been set to constant. In this case the ";
			mptr[2]="following  list of the alignment options for the text displayed by ";
			mptr[3]="the widget are  available :  ";
			mptr[4]=" ";
			mptr[5]="  ";
			mptr[6]="  ";
			mptr[7]="none ";
			mptr[8]="   text is displayed as is  ";
			mptr[9]="left ";
			mptr[10]="   text is displayed left aligned inside the edit frame.  ";
			mptr[11]="right ";
			mptr[12]="   text is displayed right aligned inside the edit frame.  ";
			mptr[13]="center ";
			mptr[14]="   the text is centered inside the edit frame.  ";
			mptr[15]="justify ";
			mptr[16]="   the text is justified inside the edit frame.  ";
			mptr[17]="  ";
			mptr[18]=" ";
			mptr[19]="     ";
			return(visual_online_help(mptr,20));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Liste des posibilit‚s pour aligner un texte.  ";
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
			char * mptr[11];
			mptr[0] = "This field may be used to specify a value to be used to initialise ";
			mptr[1]="the contents of the string buffer associated with the edit widget ";
			mptr[2]="during it's implicite OnCreate method.  ";
			mptr[3]=" ";
			mptr[4]="The value of this attribut may be referenced from method text by the ";
			mptr[5]="term :this.PAYLOAD  ";
			mptr[6]=" ";
			mptr[7]="The payload value may reference other widget and method expression ";
			mptr[8]="using the standard $ prefixed escape expressions.  ";
			mptr[9]=" ";
			mptr[10]="     ";
			return(visual_online_help(mptr,11));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Valeur initiale de la zone d'‚dition. ";
			mptr[1]=" Vous retrouverez par programmation ce texte en utilisant la propri‚t‚ ";
			mptr[2]="this.PAYLOAD du widget.   ";
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

private int FocusStyle_help()
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

private int CursorType_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[22];
			mptr[0] = "This control allows selection of the cursor type for use with the ";
			mptr[1]="VisualEdit instruction amongst the options of the following list : ";
			mptr[2]=" ";
			mptr[3]=" ";
			mptr[4]="  ";
			mptr[5]="  ";
			mptr[6]="Coloured  ";
			mptr[7]="   The standard edit colour cursor will bedisplayed, this will change ";
			mptr[8]="colour to reflect insert or overwrite modes.  ";
			mptr[9]="Block  ";
			mptr[10]="   The standard GIGO XOR Cursor block will be displayed.   ";
			mptr[11]="Vertical Line  ";
			mptr[12]="   The standard GIGO XOR Cursor Vertical Line will be displayed.   ";
			mptr[13]="Userlined  ";
			mptr[14]="   The standard GIGO XOR Cursor Underline will be displayed.   ";
			mptr[15]="Frame  ";
			mptr[16]="   The standard GIGO XOR Cursor Frame will be displayed.   ";
			mptr[17]="None  ";
			mptr[18]="   No cursor will be displayed.  ";
			mptr[19]="  ";
			mptr[20]=" ";
			mptr[21]="   ";
			return(visual_online_help(mptr,22));
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
			char * mptr[39];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" This check box option when activated requests the Edit Widget to ";
			mptr[3]="make use  the standard Ask instruction for data input upon focus reception.  ";
			mptr[4]=" ";
			mptr[5]="The Ask instruction requires that valid abal format information  be ";
			mptr[6]="provided by the corresponding widget property field.  ";
			mptr[7]=" ";
			mptr[8]="The string property Widget.HotKeys allows a specific collection of ";
			mptr[9]="exit key values to be defined for use by the Ask instruction.  ";
			mptr[10]=" ";
			mptr[11]="If this buffer is empty then the standard collection of hotkeys will ";
			mptr[12]="be  used directing exection to the next abal source line.  ";
			mptr[13]=" ";
			mptr[14]="   ";
			mptr[15]=" Hotkey Target Description  ";
			mptr[16]=" T ThisLine Timer events will be redirected after handling to restart ";
			mptr[17]="the  Ask instruction.  ";
			mptr[18]=" X Next All Mouse Events will be directed to line of abal source following ";
			mptr[19]="the Ask instruction.  ";
			mptr[20]=" I Next The Escape key will be directed to the next line.  ";
			mptr[21]=" U Next The Up Arrow  will be directed to the next line.  ";
			mptr[22]=" D Next The Down Arrow will be directed to the next line.  ";
			mptr[23]=" /0D Next The Enter Key will be directed to the next line.  ";
			mptr[24]=" /12 Next The Page Up Key will be directed to the next line.  ";
			mptr[25]=" /03 Next The Page Down Key will be directed to the next line.  ";
			mptr[26]=" /09 Next The Tabulation Key will be directed to the next line.  ";
			mptr[27]=" (Widget.HotKeys) Next When defined widget hotkeys will be directed to ";
			mptr[28]="the next source line.   ";
			mptr[29]=" ";
			mptr[30]=" The Ask instruction will be performed inside of a VisualViewPort ";
			mptr[31]="of  exactly the right dimensions to fit the buffer and an eventual ";
			mptr[32]="validation curser position.  ";
			mptr[33]=" ";
			mptr[34]="The forms properties AskForeGround and AskBackGround will be used ";
			mptr[35]="to establish the required colour using a standard Paint instruction preceeded by the Atb(53) instruction requesting ";
			mptr[36]="ask  cursor colouring to be performed.  ";
			mptr[37]=" ";
			mptr[38]="          ";
			return(visual_online_help(mptr,39));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Cette option permet d'utiliser la zone d'‚dition avec les fonctionnalit‚s ";
			mptr[1]="d'un ask Abal.   ";
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
			char * mptr[4];
			mptr[0] = "This check control may be used to indicate that the data input must ";
			mptr[1]="be performed in secret mode,only stars being displayed.This may be ";
			mptr[2]="used for pass word entry or other fields where discretion is required. ";
			mptr[3]="   ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[4];
			mptr[0] = "Cette case permet la saisie en mode secret.Des ‚toiles remplacent ";
			mptr[1]="les caractŠres saisis. ";
			mptr[2]=" Utilisez cette option pour saisir un mot de passe par exemple.   ";
			mptr[3]=" ";
			return(visual_online_help(mptr,4));
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
private int on_IsUnderline_event(struct vwedit_context * _Context) {
	unsigned char*msg_help[8],*msg;
	int i,nblig=1;
	int largeur=0;
	switch(_Context->value_WidgetClass)
	{
	case _TAB_FRAME:
	msg_help[0]="Make the tab text underline";
	msg_help[1]="Souligner le texte du titre de l'onglet";
	break;
	case _BUTTON_FRAME:
	switch(_Context->value_Align)
	{
	case 1:/*Bouton image*/
	case 3:
	msg_help[0]="This check is only for text.";
	msg_help[1]="cette case a cocher ne sert que pour le texte";
	break;
	default:/*Bouton texte*/
	msg_help[0]="Make the button text underline";
	msg_help[1]="Souligner le texte du bouton";
	break;
	};
	break;
	case _EDIT_FRAME:
	msg_help[0]="this check controls may be used to indicate that\0the data input must be performed in secret mode,\0only stars being displayed, the actual value being\0 hidden. This may be used for pass word entry or other\0fields where discretion is required.";
	msg_help[1]="Cocher cette case pour que la zone soit saisie\0en mode secret. Des ‚toiles remplaceront la valeur\0de la zone. Utiliser cette option pour saisir\0un mot de passe par exemple";
	if(visual_national_language(-1)==1)
	nblig=4;
	else
	nblig=5;
	break;
		case _PROGRESS_FRAME:
	msg_help[0]="activates the underline attribute for the text";
	msg_help[1]="souligne le texte d'‚volution affich‚";
	break;
		case _FORM_FRAME:
	msg_help[0]="If you check this control,\0the text of the titles will be underline";
	msg_help[1]="Si vous cochez cette case, les titres\0des colonnes seront soulign‚s";
	nblig=2;
	break;
	case _SCROLL_FRAME:
	msg_help[0]="Nothing for this check";
	msg_help[1]="Cette case … cocher est sans effets pour cet objet";
	break;
		case _IMAGE_FRAME:
	msg_help[0]="No help for this check";
	msg_help[1]="Pas d'aide sur cet case … cocher";
	break;
	case _WINDOW_FRAME:
	msg_help[0]="this check control allows a help button to be added\0to the window in the top right corner.";
	msg_help[1]="Si vous cochez cette case, vous aurez alors\0un bouton d'aide en haut a droite de la fenˆtre";
	nblig=2;
	break;
		case _DATA_FRAME:
	msg_help[0]="Check to open the file in exclusive mode.";
	msg_help[1]="Cocher pour ouvrir le fichier en mode exclusif.";
	break;
	case _FILL_FRAME:
	msg_help[0]="This data is unsued for the fill widget";
	msg_help[1]="Cette case a cocher n'est pas utilis‚e pour cet objet";
	break;
	case _OUTSET_FRAME:
	case _INSET_FRAME:
	case _RIDGE_FRAME:
	case _GROOVE_FRAME:
	msg_help[0]="underline the title,\0if you select an option with text";
	msg_help[1]="Souligne le titre\0si vous choisissez une option avec texte";
	nblig=2;
	break;
	case _LINE_FRAME:
	msg_help[0]="Nothing for this check";
	msg_help[1]="Cette case … cocher est sans effets pour ce widget";
	break;
	case _CHECK_FRAME:
	case _SWITCH_FRAME:
	case _GRAPH_FRAME:
	msg_help[0]="This check is unused for this widget";
	msg_help[1]="Cette case a cocher est sans effets pour cet objet";
	break;
	case _SELECT_FRAME:
	msg_help[0]="This check is unused for this widget";
	msg_help[1]="Cette case a cocher est sans effets pour cet objet";
	/*msg_help[0]="Underline the text of the widget";
	msg_help[1]="Mettre en gras le texte de l'objet";*/
	break;
	case _RADIO_FRAME:
	msg_help[0]="This check is unused for this widget";
	msg_help[1]="Cette case a cocher est sans effets pour cet objet";
	/*msg_help[0]="Underline text of the radio button bold";
	msg_help[1]="Souligner le texte du radio bouton";*/
	break;
	case _TEXT_FRAME:
	msg_help[0]="Activate the underline attribute for the text";
	msg_help[1]="Souligner le texte.";
	break;
	default:
	msg_help[0]="No help for this Widget";
	msg_help[1]="Pas d'aide pour cet objet";
	};
	/*anglais pour les autres langues*/
	msg_help[2]=msg_help[0];
	msg_help[3]=msg_help[0];
	msg_help[4]=msg_help[0];
	msg_help[5]=msg_help[0];
	msg_help[6]=msg_help[0];
	msg_help[7]=msg_help[0];
	msg=msg_help[visual_national_language(-1)];
	for(i=0;i<nblig;i++)
	{
	if(largeur<(int)strlen(msg))largeur=(int)strlen(msg);
	msg+=strlen(msg)+1;
	};
	aide_en_ligne(_Context->x_WidgetProperties+670-largeur*8-75,_Context->y_WidgetProperties+370+30,nblig,msg_help[visual_national_language(-1)]);
	return(-1);
}
private int on_fgSelect_event(struct vwedit_context * _Context) {
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
		vwedit_show(_Context);
;
	return(-1);
}


public	int	vwedit_event(
struct vwedit_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsSpecial == mb ) return(7);
		if (_Context->trigger_IsLock == mb ) return(9);
		if (_Context->trigger_IsInterface == mb ) return(10);
		if (_Context->trigger_IswResize == mb ) return(18);
		if (_Context->trigger_IshResize == mb ) return(19);
		if (_Context->trigger_IsBold == mb ) return(23);
		if (_Context->trigger_IsUnderline == mb ) return(24);
		if (_Context->trigger_fgSelect == mb ) return(27);
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
		vwedit_show(_Context);
		return(-1);	/* WidgetProperties */

		}
		}
	if (( mx >= (_Context->x_WidgetProperties+461+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+120) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+461+114) ) 
	&&  ( my <= (_Context->y_WidgetProperties+120+16))) {
		return(2); /* IsInhibit */
		}
	if (( mx >= (_Context->x_WidgetProperties+11) ) 
	&&  ( my >= (_Context->y_WidgetProperties+65) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+11+184) ) 
	&&  ( my <= (_Context->y_WidgetProperties+65+16))) {
		return(3); /* Identity */
		}
	if (( mx >= (_Context->x_WidgetProperties+230+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+65) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+230+196) ) 
	&&  ( my <= (_Context->y_WidgetProperties+65+16))) {
		return(4); /* WidgetClass */
		}
	if (( mx >= (_Context->x_WidgetProperties+12+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+110) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+12+182) ) 
	&&  ( my <= (_Context->y_WidgetProperties+110+16))) {
		return(5); /* Type */
		}
	if (( mx >= (_Context->x_WidgetProperties+233) ) 
	&&  ( my >= (_Context->y_WidgetProperties+112) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+233+192) ) 
	&&  ( my <= (_Context->y_WidgetProperties+112+16))) {
		return(6); /* Format */
		}
	if (( mx >= (_Context->x_WidgetProperties+460) ) 
	&&  ( my >= (_Context->y_WidgetProperties+99) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+460+190) ) 
	&&  ( my <= (_Context->y_WidgetProperties+99+16))) {
		return(7); /* IsSpecial */
		}
	if (( mx >= (_Context->x_WidgetProperties+13) ) 
	&&  ( my >= (_Context->y_WidgetProperties+154) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+13+424) ) 
	&&  ( my <= (_Context->y_WidgetProperties+154+64))) {
		return(8); /* Hint */
		}
	if (( mx >= (_Context->x_WidgetProperties+460) ) 
	&&  ( my >= (_Context->y_WidgetProperties+54) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+460+170) ) 
	&&  ( my <= (_Context->y_WidgetProperties+54+16))) {
		return(9); /* IsLock */
		}
	if (( mx >= (_Context->x_WidgetProperties+460) ) 
	&&  ( my >= (_Context->y_WidgetProperties+77) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+460+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+77+16))) {
		return(10); /* IsInterface */
		}
	if (( mx >= (_Context->x_WidgetProperties+460) ) 
	&&  ( my >= (_Context->y_WidgetProperties+202) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+460+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+202+16))) {
		return(11); /* AtX */
		}
	if (( mx >= (_Context->x_WidgetProperties+20+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+270) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+20+126) ) 
	&&  ( my <= (_Context->y_WidgetProperties+270+16))) {
		return(12); /* TextFont */
		}
	if (( mx >= (_Context->x_WidgetProperties+505) ) 
	&&  ( my >= (_Context->y_WidgetProperties+202) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+505+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+202+16))) {
		return(13); /* AtY */
		}
	if (( mx >= (_Context->x_WidgetProperties+561) ) 
	&&  ( my >= (_Context->y_WidgetProperties+202) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+561+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+202+16))) {
		return(14); /* Width */
		}
	if (( mx >= (_Context->x_WidgetProperties+615) ) 
	&&  ( my >= (_Context->y_WidgetProperties+202) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+615+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+202+16))) {
		return(15); /* Height */
		}
	if (( mx >= (_Context->x_WidgetProperties+170+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+270) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+170+130) ) 
	&&  ( my <= (_Context->y_WidgetProperties+270+16))) {
		return(16); /* Align */
		}
	if (( mx >= (_Context->x_WidgetProperties+20) ) 
	&&  ( my >= (_Context->y_WidgetProperties+320) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+20+424) ) 
	&&  ( my <= (_Context->y_WidgetProperties+320+32))) {
		return(17); /* PayLoad */
		}
	if (( mx >= (_Context->x_WidgetProperties+21) ) 
	&&  ( my >= (_Context->y_WidgetProperties+370) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+21+182) ) 
	&&  ( my <= (_Context->y_WidgetProperties+370+16))) {
		return(18); /* IswResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+220) ) 
	&&  ( my >= (_Context->y_WidgetProperties+370) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+220+165) ) 
	&&  ( my <= (_Context->y_WidgetProperties+370+16))) {
		return(19); /* IshResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+460) ) 
	&&  ( my >= (_Context->y_WidgetProperties+270) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+460+190) ) 
	&&  ( my <= (_Context->y_WidgetProperties+270+16))) {
		return(20); /* StyleSheet */
		}
	if (( mx >= (_Context->x_WidgetProperties+460) ) 
	&&  ( my >= (_Context->y_WidgetProperties+290) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+460+190) ) 
	&&  ( my <= (_Context->y_WidgetProperties+290+16))) {
		return(21); /* FocusStyle */
		}
	if (( mx >= (_Context->x_WidgetProperties+460+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+330) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+460+184) ) 
	&&  ( my <= (_Context->y_WidgetProperties+330+16))) {
		return(22); /* CursorType */
		}
	if (( mx >= (_Context->x_WidgetProperties+460) ) 
	&&  ( my >= (_Context->y_WidgetProperties+370) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+460+84) ) 
	&&  ( my <= (_Context->y_WidgetProperties+370+16))) {
		return(23); /* IsBold */
		}
	if (( mx >= (_Context->x_WidgetProperties+550) ) 
	&&  ( my >= (_Context->y_WidgetProperties+370) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+550+98) ) 
	&&  ( my <= (_Context->y_WidgetProperties+370+16))) {
		return(24); /* IsUnderline */
		}
	if (( mx >= (_Context->x_WidgetProperties+312) ) 
	&&  ( my >= (_Context->y_WidgetProperties+270) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+312+40) ) 
	&&  ( my <= (_Context->y_WidgetProperties+270+16))) {
		return(25); /* TextColour */
		}
	if (( mx >= (_Context->x_WidgetProperties+398) ) 
	&&  ( my >= (_Context->y_WidgetProperties+270) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+398+40) ) 
	&&  ( my <= (_Context->y_WidgetProperties+270+16))) {
		return(26); /* Background */
		}
	if (( mx >= (_Context->x_WidgetProperties+353) ) 
	&&  ( my >= (_Context->y_WidgetProperties+270) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+353+44) ) 
	&&  ( my <= (_Context->y_WidgetProperties+270+18))) {
		return(27); /* fgSelect */
		}

	return(-1);
}


public	int	vwedit_focus(struct vwedit_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* IsInhibit */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+461,_Context->y_WidgetProperties+120,114,46,vfh[2],0,0,parse_selection(_Context->msg_IsInhibit[_Context->language],&_Context->value_IsInhibit),770);
				break;
			case	0x3 :
				/* Identity */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+11+1,_Context->y_WidgetProperties+65+1,184,16,vfh[1],_Context->buffer_Identity,255);
			break;
			case	0x4 :
				/* WidgetClass */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+230,_Context->y_WidgetProperties+65,196,144,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),774);
				if(change_widget_class(&_Context->value_WidgetClass)!=0){
				return(26);
				}
				break;
			case	0x5 :
				/* Type */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+110,182,128,vfh[2],0,0,parse_selection(WidgetTypeList,&_Context->value_Type),774);
				break;
			case	0x6 :
				/* Format */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+233+1,_Context->y_WidgetProperties+112+1,192,16,vfh[1],_Context->buffer_Format,255);
			break;
			case	0x7 :
				/* IsSpecial */
				visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+99,190,16,vfh[2],28,28,_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]),(_Context->value_IsSpecial |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsSpecial=visual_trigger_code(_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]));
	visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+99,190,16,vfh[2],28,28,_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]),_Context->value_IsSpecial|0);
				break;
			case	0x8 :
				/* Hint */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+154+1,424,64,vfh[1],_Context->buffer_Hint,255);
			break;
			case	0x9 :
				/* IsLock */
				visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+54,170,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),(_Context->value_IsLock |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+54,170,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
				break;
			case	0xa :
				/* IsInterface */
				visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+77,180,16,vfh[2],28,28,_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]),(_Context->value_IsInterface |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsInterface=visual_trigger_code(_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]));
	visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+77,180,16,vfh[2],28,28,_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]),_Context->value_IsInterface|0);
				break;
			case	0xb :
				/* AtX */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+460+1,_Context->y_WidgetProperties+202+1,35,16,vfh[1],_Context->buffer_AtX,7);
			break;
			case	0xc :
				/* TextFont */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+270,126,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),770);
				break;
			case	0xd :
				/* AtY */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+505+1,_Context->y_WidgetProperties+202+1,35,16,vfh[1],_Context->buffer_AtY,7);
			break;
			case	0xe :
				/* Width */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+561+1,_Context->y_WidgetProperties+202+1,35,16,vfh[1],_Context->buffer_Width,7);
			break;
			case	0xf :
				/* Height */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+615+1,_Context->y_WidgetProperties+202+1,35,16,vfh[1],_Context->buffer_Height,7);
			break;
			case	0x10 :
				/* Align */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+170,_Context->y_WidgetProperties+270,130,100,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),774);
				break;
			case	0x11 :
				/* PayLoad */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+20+1,_Context->y_WidgetProperties+320+1,424,32,vfh[1],_Context->buffer_PayLoad,255);
			break;
			case	0x12 :
				/* IswResize */
				visual_check(_Context->x_WidgetProperties+21,_Context->y_WidgetProperties+370,182,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),(_Context->value_IswResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+21,_Context->y_WidgetProperties+370,182,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
				break;
			case	0x13 :
				/* IshResize */
				visual_check(_Context->x_WidgetProperties+220,_Context->y_WidgetProperties+370,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),(_Context->value_IshResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+220,_Context->y_WidgetProperties+370,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
				break;
			case	0x14 :
				/* StyleSheet */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+460+1,_Context->y_WidgetProperties+270+1,190,16,vfh[1],_Context->buffer_StyleSheet,255);
			break;
			case	0x15 :
				/* FocusStyle */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+460+1,_Context->y_WidgetProperties+290+1,190,16,vfh[1],_Context->buffer_FocusStyle,255);
			break;
			case	0x16 :
				/* CursorType */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+330,184,15,vfh[1],0,0,parse_selection(_Context->msg_CursorType[_Context->language],&_Context->value_CursorType),2);
				break;
			case	0x17 :
				/* IsBold */
				visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+370,84,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),(_Context->value_IsBold |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+370,84,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
				break;
			case	0x18 :
				/* IsUnderline */
				visual_check(_Context->x_WidgetProperties+550,_Context->y_WidgetProperties+370,98,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),(_Context->value_IsUnderline |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsUnderline=visual_trigger_code(_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]));
	visual_check(_Context->x_WidgetProperties+550,_Context->y_WidgetProperties+370,98,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),_Context->value_IsUnderline|0);
				break;
			case	0x19 :
				/* TextColour */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+312+1,_Context->y_WidgetProperties+270+1,40,16,vfh[1],_Context->buffer_TextColour,6);
			break;
			case	0x1a :
				/* Background */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+398+1,_Context->y_WidgetProperties+270+1,40,16,vfh[1],_Context->buffer_Background,6);
			break;
			case	0x1b :
				/* fgSelect */
				_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
				visual_button(_Context->x_WidgetProperties+353,_Context->y_WidgetProperties+270,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+353,_Context->y_WidgetProperties+270,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			vwedit_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=27;
			vwedit_show(_Context);
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
			if ((retcode=vwedit_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x3 :
						if (Identity_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (WidgetClass_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Type_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (Format_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (IsSpecial_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (Hint_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (IsLock_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (IsInterface_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (AtX_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (TextFont_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (AtY_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (Width_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (Height_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (Align_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (PayLoad_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (IswResize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x13 :
						if (IshResize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x14 :
						if (StyleSheet_help(_Context) != 0) { continue; }
						else { break; }
					case	0x15 :
						if (FocusStyle_help(_Context) != 0) { continue; }
						else { break; }
					case	0x16 :
						if (CursorType_help(_Context) != 0) { continue; }
						else { break; }
					case	0x17 :
						if (IsBold_help(_Context) != 0) { continue; }
						else { break; }
					case	0x18 :
						if (IsUnderline_help(_Context) != 0) { continue; }
						else { break; }
					case	0x19 :
						if (TextColour_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1a :
						if (Background_help(_Context) != 0) { continue; }
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
					/* IsInhibit */
					continue;
				case	0x3 :
					/* Identity */
					continue;
				case	0x4 :
					/* WidgetClass */
					continue;
				case	0x5 :
					/* Type */
					continue;
				case	0x6 :
					/* Format */
					continue;
				case	0x7 :
					/* IsSpecial */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsSpecial += 1;
						_Context->value_IsSpecial &= 1;
						}
					continue;
				case	0x8 :
					/* Hint */
					continue;
				case	0x9 :
					/* IsLock */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsLock += 1;
						_Context->value_IsLock &= 1;
						}
					continue;
				case	0xa :
					/* IsInterface */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsInterface += 1;
						_Context->value_IsInterface &= 1;
						}
					continue;
				case	0xb :
					/* AtX */
					continue;
				case	0xc :
					/* TextFont */
					continue;
				case	0xd :
					/* AtY */
					continue;
				case	0xe :
					/* Width */
					continue;
				case	0xf :
					/* Height */
					continue;
				case	0x10 :
					/* Align */
					continue;
				case	0x11 :
					/* PayLoad */
					continue;
				case	0x12 :
					/* IswResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IswResize += 1;
						_Context->value_IswResize &= 1;
						}
					continue;
				case	0x13 :
					/* IshResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IshResize += 1;
						_Context->value_IshResize &= 1;
						}
					continue;
				case	0x14 :
					/* StyleSheet */
					continue;
				case	0x15 :
					/* FocusStyle */
					continue;
				case	0x16 :
					/* CursorType */
					continue;
				case	0x17 :
					/* IsBold */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsBold += 1;
						_Context->value_IsBold &= 1;
						}
					continue;
				case	0x18 :
					/* IsUnderline */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsUnderline += 1;
						_Context->value_IsUnderline &= 1;
						}
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_IsUnderline_event(_Context)) != -1) break;

						}
					continue;
				case	0x19 :
					/* TextColour */
					continue;
				case	0x1a :
					/* Background */
					continue;
				case	0x1b :
					/* fgSelect */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
						visual_button(_Context->x_WidgetProperties+353,_Context->y_WidgetProperties+270,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+353,_Context->y_WidgetProperties+270,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_fgSelect_event(_Context)) != -1) break;

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
				_Context->focus_item=27;
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

public	int	vwedit()
{
	int	status=0;
	struct vwedit_context * _Context=(struct vwedit_context*) 0;
	status = vwedit_create(&_Context);
	if ( status != 0) return(status);
	status = vwedit_show(_Context);
		enter_modal();
	status = vwedit_focus(_Context);
		leave_modal();
	status = vwedit_hide(_Context);
	status = vwedit_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwedit_c */
