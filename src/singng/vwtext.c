
#ifndef _vwtext_c
#define _vwtext_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vwtext.xml                                               */
/* Target         : vwtext.c                                                 */
/* Identification : 0.0-1177511939-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "sing.h"
#include "singform.h"
#include "singprot.h"
#define en_WidgetProperties   "Text - Properties"
#define fr_WidgetProperties   "Text - Propri‚t‚s"
#define it_WidgetProperties   "Text widget - Properties"
#define es_WidgetProperties   "Text widget - Properties"
#define de_WidgetProperties   "Text widget - Properties"
#define nl_WidgetProperties   "Text widget - Properties"
#define pt_WidgetProperties   "Text widget - Properties"
#define xx_WidgetProperties   "Text widget - Properties"
#define en__WidgetProperties   ""
#define fr__WidgetProperties   ""
#define it__WidgetProperties   ""
#define es__WidgetProperties   ""
#define de__WidgetProperties   ""
#define nl__WidgetProperties   ""
#define pt__WidgetProperties   ""
#define xx__WidgetProperties   ""
#define en_Auto2790   "Position and dimension"
#define fr_Auto2790   "Position et Dimension"
#define it_Auto2790   "Position and dimension"
#define es_Auto2790   "Position and dimension"
#define de_Auto2790   "Position and dimension"
#define nl_Auto2790   "Position and dimension"
#define pt_Auto2790   "Position and dimension"
#define xx_Auto2790   "Position and dimension"
#define en__Auto2790   ""
#define fr__Auto2790   ""
#define it__Auto2790   ""
#define es__Auto2790   ""
#define de__Auto2790   ""
#define nl__Auto2790   ""
#define pt__Auto2790   ""
#define xx__Auto2790   ""
#define en_Auto2792   "Behaviour"
#define fr_Auto2792   "Comportement"
#define it_Auto2792   "Behaviour"
#define es_Auto2792   "Behaviour"
#define de_Auto2792   "Behaviour"
#define nl_Auto2792   "Behaviour"
#define pt_Auto2792   "Behaviour"
#define xx_Auto2792   "Behaviour"
#define en__Auto2792   ""
#define fr__Auto2792   ""
#define it__Auto2792   ""
#define es__Auto2792   ""
#define de__Auto2792   ""
#define nl__Auto2792   ""
#define pt__Auto2792   ""
#define xx__Auto2792   ""
#define en_Auto2793   "Appearence"
#define fr_Auto2793   "Apparence"
#define it_Auto2793   "Appearence"
#define es_Auto2793   "Appearence"
#define de_Auto2793   "Appearence"
#define nl_Auto2793   "Appearence"
#define pt_Auto2793   "Appearence"
#define xx_Auto2793   "Appearence"
#define en__Auto2793   ""
#define fr__Auto2793   ""
#define it__Auto2793   ""
#define es__Auto2793   ""
#define de__Auto2793   ""
#define nl__Auto2793   ""
#define pt__Auto2793   ""
#define xx__Auto2793   ""
#define en_Auto2794   "General"
#define fr_Auto2794   "G‚n‚ral"
#define it_Auto2794   "General"
#define es_Auto2794   "General"
#define de_Auto2794   "General"
#define nl_Auto2794   "General"
#define pt_Auto2794   "General"
#define xx_Auto2794   "General"
#define en__Auto2794   ""
#define fr__Auto2794   ""
#define it__Auto2794   ""
#define es__Auto2794   ""
#define de__Auto2794   ""
#define nl__Auto2794   ""
#define pt__Auto2794   ""
#define xx__Auto2794   ""
#define en__WidgetClass   ""
#define fr__WidgetClass   ""
#define en_Identity   ""
#define en__Identity   ""
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
#define en_AtX   ""
#define fr_AtX   ""
#define en__AtX   ""
#define fr__AtX   ""
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
#define en__TextFont   ""
#define fr__TextFont   ""
#define en_TextColour   ""
#define en__TextColour   ""
#define en_Background   ""
#define en__Background   ""
#define en_PayLoad   ""
#define en__PayLoad   ""
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
#define en_IsBold   "Bold"
#define fr_IsBold   "Gras"
#define it_IsBold   "Bold"
#define es_IsBold   "Bold"
#define de_IsBold   "Bold"
#define nl_IsBold   "Bold"
#define pt_IsBold   "Bold"
#define xx_IsBold   "Bold"
#define en__IsBold   ""
#define fr__IsBold   ""
#define it__IsBold   ""
#define es__IsBold   ""
#define de__IsBold   ""
#define nl__IsBold   ""
#define pt__IsBold   ""
#define xx__IsBold   ""
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
#define en_IsShadow   "Shadow"
#define fr_IsShadow   "Ombre"
#define it_IsShadow   "Shadow"
#define es_IsShadow   "Shadow"
#define de_IsShadow   "Shadow"
#define nl_IsShadow   "Shadow"
#define pt_IsShadow   "Shadow"
#define xx_IsShadow   "Shadow"
#define en__IsShadow   ""
#define fr__IsShadow   ""
#define it__IsShadow   ""
#define es__IsShadow   ""
#define de__IsShadow   ""
#define nl__IsShadow   ""
#define pt__IsShadow   ""
#define xx__IsShadow   ""
#define en_Auto2795   "X"
#define fr_Auto2795   "X"
#define it_Auto2795   "X"
#define es_Auto2795   "X"
#define de_Auto2795   "X"
#define nl_Auto2795   "X"
#define pt_Auto2795   "X"
#define xx_Auto2795   "X"
#define en__Auto2795   ""
#define fr__Auto2795   ""
#define it__Auto2795   ""
#define es__Auto2795   ""
#define de__Auto2795   ""
#define nl__Auto2795   ""
#define pt__Auto2795   ""
#define xx__Auto2795   ""
#define en_Auto2796   "Height"
#define fr_Auto2796   "Hauteur"
#define it_Auto2796   "Height"
#define es_Auto2796   "Height"
#define de_Auto2796   "Height"
#define nl_Auto2796   "Height"
#define pt_Auto2796   "Height"
#define xx_Auto2796   "Height"
#define en__Auto2796   ""
#define fr__Auto2796   ""
#define it__Auto2796   ""
#define es__Auto2796   ""
#define de__Auto2796   ""
#define nl__Auto2796   ""
#define pt__Auto2796   ""
#define xx__Auto2796   ""
#define en_Auto2797   "Width"
#define fr_Auto2797   "Largeur"
#define it_Auto2797   "Width"
#define es_Auto2797   "Width"
#define de_Auto2797   "Width"
#define nl_Auto2797   "Width"
#define pt_Auto2797   "Width"
#define xx_Auto2797   "Width"
#define en__Auto2797   ""
#define fr__Auto2797   ""
#define it__Auto2797   ""
#define es__Auto2797   ""
#define de__Auto2797   ""
#define nl__Auto2797   ""
#define pt__Auto2797   ""
#define xx__Auto2797   ""
#define en_Auto2798   "Y"
#define fr_Auto2798   "Y"
#define it_Auto2798   "Y"
#define es_Auto2798   "Y"
#define de_Auto2798   "Y"
#define nl_Auto2798   "Y"
#define pt_Auto2798   "Y"
#define xx_Auto2798   "Y"
#define en__Auto2798   ""
#define fr__Auto2798   ""
#define it__Auto2798   ""
#define es__Auto2798   ""
#define de__Auto2798   ""
#define nl__Auto2798   ""
#define pt__Auto2798   ""
#define xx__Auto2798   ""
#define en_Auto2799   "Font"
#define fr_Auto2799   "Police"
#define it_Auto2799   "Font"
#define es_Auto2799   "Font"
#define de_Auto2799   "Font"
#define nl_Auto2799   "Font"
#define pt_Auto2799   "Font"
#define xx_Auto2799   "Font"
#define en__Auto2799   ""
#define fr__Auto2799   ""
#define it__Auto2799   ""
#define es__Auto2799   ""
#define de__Auto2799   ""
#define nl__Auto2799   ""
#define pt__Auto2799   ""
#define xx__Auto2799   ""
#define en_StyleSheet   ""
#define fr_StyleSheet   ""
#define en__StyleSheet   ""
#define fr__StyleSheet   ""
#define en_Auto2800   "Message"
#define fr_Auto2800   "Message"
#define it_Auto2800   "Message"
#define es_Auto2800   "Message"
#define de_Auto2800   "Message"
#define nl_Auto2800   "Message"
#define pt_Auto2800   "Message"
#define xx_Auto2800   "Message"
#define en__Auto2800   ""
#define fr__Auto2800   ""
#define it__Auto2800   ""
#define es__Auto2800   ""
#define de__Auto2800   ""
#define nl__Auto2800   ""
#define pt__Auto2800   ""
#define xx__Auto2800   ""
#define en_Auto2801   "Fore"
#define fr_Auto2801   "Texte"
#define it_Auto2801   "Fore"
#define es_Auto2801   "Fore"
#define de_Auto2801   "Fore"
#define nl_Auto2801   "Fore"
#define pt_Auto2801   "Fore"
#define xx_Auto2801   "Fore"
#define en__Auto2801   ""
#define fr__Auto2801   ""
#define it__Auto2801   ""
#define es__Auto2801   ""
#define de__Auto2801   ""
#define nl__Auto2801   ""
#define pt__Auto2801   ""
#define xx__Auto2801   ""
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
#define en_Auto2802   "Back"
#define fr_Auto2802   "Fond"
#define it_Auto2802   "Back"
#define es_Auto2802   "Back"
#define de_Auto2802   "Back"
#define nl_Auto2802   "Back"
#define pt_Auto2802   "Back"
#define xx_Auto2802   "Back"
#define en__Auto2802   ""
#define fr__Auto2802   ""
#define it__Auto2802   ""
#define es__Auto2802   ""
#define de__Auto2802   ""
#define nl__Auto2802   ""
#define pt__Auto2802   ""
#define xx__Auto2802   ""
#define en_Auto2803   "Explicit style"
#define fr_Auto2803   "Style explicite"
#define it_Auto2803   "Explicit style"
#define es_Auto2803   "Explicit style"
#define de_Auto2803   "Explicit style"
#define nl_Auto2803   "Explicit style"
#define pt_Auto2803   "Explicit style"
#define xx_Auto2803   "Explicit style"
#define en__Auto2803   ""
#define fr__Auto2803   ""
#define it__Auto2803   ""
#define es__Auto2803   ""
#define de__Auto2803   ""
#define nl__Auto2803   ""
#define pt__Auto2803   ""
#define xx__Auto2803   ""
#define en_Auto2804   "Hint"
#define fr_Auto2804   "Infobulle"
#define it_Auto2804   "Hint"
#define es_Auto2804   "Hint"
#define de_Auto2804   "Hint"
#define nl_Auto2804   "Hint"
#define pt_Auto2804   "Hint"
#define xx_Auto2804   "Hint"
#define en__Auto2804   ""
#define fr__Auto2804   ""
#define it__Auto2804   ""
#define es__Auto2804   ""
#define de__Auto2804   ""
#define nl__Auto2804   ""
#define pt__Auto2804   ""
#define xx__Auto2804   ""
#define en_Auto2805   "Alignment"
#define fr_Auto2805   "Alignement"
#define it_Auto2805   "Alignment"
#define es_Auto2805   "Alignment"
#define de_Auto2805   "Alignment"
#define nl_Auto2805   "Alignment"
#define pt_Auto2805   "Alignment"
#define xx_Auto2805   "Alignment"
#define en__Auto2805   ""
#define fr__Auto2805   ""
#define it__Auto2805   ""
#define es__Auto2805   ""
#define de__Auto2805   ""
#define nl__Auto2805   ""
#define pt__Auto2805   ""
#define xx__Auto2805   ""
#define en_Auto2806   "Name"
#define fr_Auto2806   "Nom"
#define it_Auto2806   "Name"
#define es_Auto2806   "Name"
#define de_Auto2806   "Name"
#define nl_Auto2806   "Name"
#define pt_Auto2806   "Name"
#define xx_Auto2806   "Name"
#define en__Auto2806   ""
#define fr__Auto2806   ""
#define it__Auto2806   ""
#define es__Auto2806   ""
#define de__Auto2806   ""
#define nl__Auto2806   ""
#define pt__Auto2806   ""
#define xx__Auto2806   ""
#define en_Auto2807   "Widget class"
#define fr_Auto2807   "Classe de widget"
#define it_Auto2807   "Widget class"
#define es_Auto2807   "Widget class"
#define de_Auto2807   "Widget class"
#define nl_Auto2807   "Widget class"
#define pt_Auto2807   "Widget class"
#define xx_Auto2807   "Widget class"
#define en__Auto2807   ""
#define fr__Auto2807   ""
#define it__Auto2807   ""
#define es__Auto2807   ""
#define de__Auto2807   ""
#define nl__Auto2807   ""
#define pt__Auto2807   ""
#define xx__Auto2807   ""
#define en_Auto2808   "image.new"
#include "vwtext.h"
static int	vfh[16];

/*	------------------------	*/
/*	p o s i t i o n _ a t ()	*/
/*	------------------------	*/
void	vwtext_position_at(struct vwtext_context * _Context,int x,int y){
	_Context->x_WidgetProperties=x;
	_Context->y_WidgetProperties=y;

}

/*	----------------	*/
/*	S e t V a r s ()	*/
/*	----------------	*/
void	vwtext_SetVars(struct vwtext_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	visual_signature("WWWW","WWWW");
	visual_transferin(_Context->buffer_AtX,7,pSpecificWidgetProperties->pAtX);
	visual_transferin(_Context->buffer_AtY,7,pSpecificWidgetProperties->pAtY);
	visual_transferin(_Context->buffer_Width,7,pSpecificWidgetProperties->pWidth);
	visual_transferin(_Context->buffer_Height,7,pSpecificWidgetProperties->pHeight);
	if(!(pSpecificWidgetProperties->pTextFont))
	_Context->value_TextFont=0;
	else _Context->value_TextFont=*((int*)pSpecificWidgetProperties->pTextFont);
	visual_signature("WWSS","WWSS");
	visual_transferin(_Context->buffer_TextColour,6,pSpecificWidgetProperties->pTextColour);
	visual_transferin(_Context->buffer_Background,6,pSpecificWidgetProperties->pBackground);
	visual_transferin(_Context->buffer_PayLoad,255,pSpecificWidgetProperties->pPayLoad);
	visual_transferin(_Context->buffer_Identity,255,pSpecificWidgetProperties->pIdentity);
	visual_signature("SS","SS");
	visual_transferin(_Context->buffer_StyleSheet,255,pSpecificWidgetProperties->pStyleSheet);
	visual_transferin(_Context->buffer_Hint,255,pSpecificWidgetProperties->pHint);
	if(!(pSpecificWidgetProperties->pWidgetClass))
	_Context->value_WidgetClass=0;
	else _Context->value_WidgetClass=*((int*)pSpecificWidgetProperties->pWidgetClass);
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
void	vwtext_GetVars(struct vwtext_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	visual_signature("WWWW","WWWW");
	visual_transferout(_Context->buffer_AtX,7,pSpecificWidgetProperties->pAtX);
	visual_transferout(_Context->buffer_AtY,7,pSpecificWidgetProperties->pAtY);
	visual_transferout(_Context->buffer_Width,7,pSpecificWidgetProperties->pWidth);
	visual_transferout(_Context->buffer_Height,7,pSpecificWidgetProperties->pHeight);
	if(pSpecificWidgetProperties->pTextFont!=(char*)0)
	*((int*)pSpecificWidgetProperties->pTextFont)=_Context->value_TextFont;
	visual_signature("WWSS","WWSS");
	visual_transferout(_Context->buffer_TextColour,6,pSpecificWidgetProperties->pTextColour);
	visual_transferout(_Context->buffer_Background,6,pSpecificWidgetProperties->pBackground);
	visual_transferout(_Context->buffer_PayLoad,255,pSpecificWidgetProperties->pPayLoad);
	visual_transferout(_Context->buffer_Identity,255,pSpecificWidgetProperties->pIdentity);
	visual_signature("SS","SS");
	visual_transferout(_Context->buffer_StyleSheet,255,pSpecificWidgetProperties->pStyleSheet);
	visual_transferout(_Context->buffer_Hint,255,pSpecificWidgetProperties->pHint);
	if(pSpecificWidgetProperties->pWidgetClass!=(char*)0)
	*((int*)pSpecificWidgetProperties->pWidgetClass)=_Context->value_WidgetClass;
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
	if(pSpecificWidgetProperties->pIswResize!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIswResize)=_Context->value_IswResize;
	if(pSpecificWidgetProperties->pIshResize!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIshResize)=_Context->value_IshResize;

}

public	int	vwtext_attach()
{
	if ( visual_initialise(3|512) == -1 )
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

public	int	vwtext_attach_mode(int mode)
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

public	int	vwtext_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	vwtext_create(struct vwtext_context **cptr)
{

	int i;
	struct vwtext_context * _Context=(struct vwtext_context*)0;
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
	if (!(_Context = allocate( sizeof( struct vwtext_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=21;
		_Context->value_WidgetClass=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Identity+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_Hint+i)=' ';
		_Context->value_IsLock=0;
		for (i=0; i < 7; i++)  *(_Context->buffer_AtX+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_AtY+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Width+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Height+i)=' ';
		_Context->value_Align=0;
		_Context->value_TextFont=0;
		for (i=0; i < 6; i++)  *(_Context->buffer_TextColour+i)=' ';
		for (i=0; i < 6; i++)  *(_Context->buffer_Background+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_PayLoad+i)=' ';
		_Context->value_IswResize=0;
		_Context->value_IshResize=0;
		_Context->value_IsBold=0;
		_Context->value_IsUnderline=0;
		_Context->value_IsShadow=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_StyleSheet+i)=' ';
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
	_Context->w_WidgetProperties=669;
	_Context->h_WidgetProperties=400;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2790[i]=" ";
	_Context->msg_Auto2790[0]=en_Auto2790;
	_Context->msg_Auto2790[1]=fr_Auto2790;
	_Context->msg_Auto2790[2]=it_Auto2790;
	_Context->msg_Auto2790[3]=es_Auto2790;
	_Context->msg_Auto2790[4]=de_Auto2790;
	_Context->msg_Auto2790[5]=nl_Auto2790;
	_Context->msg_Auto2790[6]=pt_Auto2790;
	_Context->msg_Auto2790[7]=xx_Auto2790;
	_Context->hint_Auto2790[0]=en__Auto2790;
	_Context->hint_Auto2790[1]=fr__Auto2790;
	_Context->hint_Auto2790[2]=it__Auto2790;
	_Context->hint_Auto2790[3]=es__Auto2790;
	_Context->hint_Auto2790[4]=de__Auto2790;
	_Context->hint_Auto2790[5]=nl__Auto2790;
	_Context->hint_Auto2790[6]=pt__Auto2790;
	_Context->hint_Auto2790[7]=xx__Auto2790;
	for (i=0; i < 8; i++)_Context->msg_Auto2792[i]=" ";
	_Context->msg_Auto2792[0]=en_Auto2792;
	_Context->msg_Auto2792[1]=fr_Auto2792;
	_Context->msg_Auto2792[2]=it_Auto2792;
	_Context->msg_Auto2792[3]=es_Auto2792;
	_Context->msg_Auto2792[4]=de_Auto2792;
	_Context->msg_Auto2792[5]=nl_Auto2792;
	_Context->msg_Auto2792[6]=pt_Auto2792;
	_Context->msg_Auto2792[7]=xx_Auto2792;
	_Context->hint_Auto2792[0]=en__Auto2792;
	_Context->hint_Auto2792[1]=fr__Auto2792;
	_Context->hint_Auto2792[2]=it__Auto2792;
	_Context->hint_Auto2792[3]=es__Auto2792;
	_Context->hint_Auto2792[4]=de__Auto2792;
	_Context->hint_Auto2792[5]=nl__Auto2792;
	_Context->hint_Auto2792[6]=pt__Auto2792;
	_Context->hint_Auto2792[7]=xx__Auto2792;
	for (i=0; i < 8; i++)_Context->msg_Auto2793[i]=" ";
	_Context->msg_Auto2793[0]=en_Auto2793;
	_Context->msg_Auto2793[1]=fr_Auto2793;
	_Context->msg_Auto2793[2]=it_Auto2793;
	_Context->msg_Auto2793[3]=es_Auto2793;
	_Context->msg_Auto2793[4]=de_Auto2793;
	_Context->msg_Auto2793[5]=nl_Auto2793;
	_Context->msg_Auto2793[6]=pt_Auto2793;
	_Context->msg_Auto2793[7]=xx_Auto2793;
	_Context->hint_Auto2793[0]=en__Auto2793;
	_Context->hint_Auto2793[1]=fr__Auto2793;
	_Context->hint_Auto2793[2]=it__Auto2793;
	_Context->hint_Auto2793[3]=es__Auto2793;
	_Context->hint_Auto2793[4]=de__Auto2793;
	_Context->hint_Auto2793[5]=nl__Auto2793;
	_Context->hint_Auto2793[6]=pt__Auto2793;
	_Context->hint_Auto2793[7]=xx__Auto2793;
	for (i=0; i < 8; i++)_Context->msg_Auto2794[i]=" ";
	_Context->msg_Auto2794[0]=en_Auto2794;
	_Context->msg_Auto2794[1]=fr_Auto2794;
	_Context->msg_Auto2794[2]=it_Auto2794;
	_Context->msg_Auto2794[3]=es_Auto2794;
	_Context->msg_Auto2794[4]=de_Auto2794;
	_Context->msg_Auto2794[5]=nl_Auto2794;
	_Context->msg_Auto2794[6]=pt_Auto2794;
	_Context->msg_Auto2794[7]=xx_Auto2794;
	_Context->hint_Auto2794[0]=en__Auto2794;
	_Context->hint_Auto2794[1]=fr__Auto2794;
	_Context->hint_Auto2794[2]=it__Auto2794;
	_Context->hint_Auto2794[3]=es__Auto2794;
	_Context->hint_Auto2794[4]=de__Auto2794;
	_Context->hint_Auto2794[5]=nl__Auto2794;
	_Context->hint_Auto2794[6]=pt__Auto2794;
	_Context->hint_Auto2794[7]=xx__Auto2794;
	for (i=0; i < 8; i++)_Context->msg_WidgetClass[i]=" ";
	_Context->hint_WidgetClass[0]=en__WidgetClass;
	_Context->hint_WidgetClass[1]=fr__WidgetClass;
	_Context->hint_Identity[0]=en__Identity;
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
	_Context->hint_AtX[0]=en__AtX;
	_Context->hint_AtX[1]=fr__AtX;
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
	for (i=0; i < 8; i++)_Context->msg_TextFont[i]=" ";
	_Context->hint_TextFont[0]=en__TextFont;
	_Context->hint_TextFont[1]=fr__TextFont;
	_Context->hint_TextColour[0]=en__TextColour;
	_Context->hint_Background[0]=en__Background;
	_Context->hint_PayLoad[0]=en__PayLoad;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2795[i]=" ";
	_Context->msg_Auto2795[0]=en_Auto2795;
	_Context->msg_Auto2795[1]=fr_Auto2795;
	_Context->msg_Auto2795[2]=it_Auto2795;
	_Context->msg_Auto2795[3]=es_Auto2795;
	_Context->msg_Auto2795[4]=de_Auto2795;
	_Context->msg_Auto2795[5]=nl_Auto2795;
	_Context->msg_Auto2795[6]=pt_Auto2795;
	_Context->msg_Auto2795[7]=xx_Auto2795;
	_Context->hint_Auto2795[0]=en__Auto2795;
	_Context->hint_Auto2795[1]=fr__Auto2795;
	_Context->hint_Auto2795[2]=it__Auto2795;
	_Context->hint_Auto2795[3]=es__Auto2795;
	_Context->hint_Auto2795[4]=de__Auto2795;
	_Context->hint_Auto2795[5]=nl__Auto2795;
	_Context->hint_Auto2795[6]=pt__Auto2795;
	_Context->hint_Auto2795[7]=xx__Auto2795;
	for (i=0; i < 8; i++)_Context->msg_Auto2796[i]=" ";
	_Context->msg_Auto2796[0]=en_Auto2796;
	_Context->msg_Auto2796[1]=fr_Auto2796;
	_Context->msg_Auto2796[2]=it_Auto2796;
	_Context->msg_Auto2796[3]=es_Auto2796;
	_Context->msg_Auto2796[4]=de_Auto2796;
	_Context->msg_Auto2796[5]=nl_Auto2796;
	_Context->msg_Auto2796[6]=pt_Auto2796;
	_Context->msg_Auto2796[7]=xx_Auto2796;
	_Context->hint_Auto2796[0]=en__Auto2796;
	_Context->hint_Auto2796[1]=fr__Auto2796;
	_Context->hint_Auto2796[2]=it__Auto2796;
	_Context->hint_Auto2796[3]=es__Auto2796;
	_Context->hint_Auto2796[4]=de__Auto2796;
	_Context->hint_Auto2796[5]=nl__Auto2796;
	_Context->hint_Auto2796[6]=pt__Auto2796;
	_Context->hint_Auto2796[7]=xx__Auto2796;
	for (i=0; i < 8; i++)_Context->msg_Auto2797[i]=" ";
	_Context->msg_Auto2797[0]=en_Auto2797;
	_Context->msg_Auto2797[1]=fr_Auto2797;
	_Context->msg_Auto2797[2]=it_Auto2797;
	_Context->msg_Auto2797[3]=es_Auto2797;
	_Context->msg_Auto2797[4]=de_Auto2797;
	_Context->msg_Auto2797[5]=nl_Auto2797;
	_Context->msg_Auto2797[6]=pt_Auto2797;
	_Context->msg_Auto2797[7]=xx_Auto2797;
	_Context->hint_Auto2797[0]=en__Auto2797;
	_Context->hint_Auto2797[1]=fr__Auto2797;
	_Context->hint_Auto2797[2]=it__Auto2797;
	_Context->hint_Auto2797[3]=es__Auto2797;
	_Context->hint_Auto2797[4]=de__Auto2797;
	_Context->hint_Auto2797[5]=nl__Auto2797;
	_Context->hint_Auto2797[6]=pt__Auto2797;
	_Context->hint_Auto2797[7]=xx__Auto2797;
	for (i=0; i < 8; i++)_Context->msg_Auto2798[i]=" ";
	_Context->msg_Auto2798[0]=en_Auto2798;
	_Context->msg_Auto2798[1]=fr_Auto2798;
	_Context->msg_Auto2798[2]=it_Auto2798;
	_Context->msg_Auto2798[3]=es_Auto2798;
	_Context->msg_Auto2798[4]=de_Auto2798;
	_Context->msg_Auto2798[5]=nl_Auto2798;
	_Context->msg_Auto2798[6]=pt_Auto2798;
	_Context->msg_Auto2798[7]=xx_Auto2798;
	_Context->hint_Auto2798[0]=en__Auto2798;
	_Context->hint_Auto2798[1]=fr__Auto2798;
	_Context->hint_Auto2798[2]=it__Auto2798;
	_Context->hint_Auto2798[3]=es__Auto2798;
	_Context->hint_Auto2798[4]=de__Auto2798;
	_Context->hint_Auto2798[5]=nl__Auto2798;
	_Context->hint_Auto2798[6]=pt__Auto2798;
	_Context->hint_Auto2798[7]=xx__Auto2798;
	for (i=0; i < 8; i++)_Context->msg_Auto2799[i]=" ";
	_Context->msg_Auto2799[0]=en_Auto2799;
	_Context->msg_Auto2799[1]=fr_Auto2799;
	_Context->msg_Auto2799[2]=it_Auto2799;
	_Context->msg_Auto2799[3]=es_Auto2799;
	_Context->msg_Auto2799[4]=de_Auto2799;
	_Context->msg_Auto2799[5]=nl_Auto2799;
	_Context->msg_Auto2799[6]=pt_Auto2799;
	_Context->msg_Auto2799[7]=xx_Auto2799;
	_Context->hint_Auto2799[0]=en__Auto2799;
	_Context->hint_Auto2799[1]=fr__Auto2799;
	_Context->hint_Auto2799[2]=it__Auto2799;
	_Context->hint_Auto2799[3]=es__Auto2799;
	_Context->hint_Auto2799[4]=de__Auto2799;
	_Context->hint_Auto2799[5]=nl__Auto2799;
	_Context->hint_Auto2799[6]=pt__Auto2799;
	_Context->hint_Auto2799[7]=xx__Auto2799;
	_Context->hint_StyleSheet[0]=en__StyleSheet;
	_Context->hint_StyleSheet[1]=fr__StyleSheet;
	for (i=0; i < 8; i++)_Context->msg_Auto2800[i]=" ";
	_Context->msg_Auto2800[0]=en_Auto2800;
	_Context->msg_Auto2800[1]=fr_Auto2800;
	_Context->msg_Auto2800[2]=it_Auto2800;
	_Context->msg_Auto2800[3]=es_Auto2800;
	_Context->msg_Auto2800[4]=de_Auto2800;
	_Context->msg_Auto2800[5]=nl_Auto2800;
	_Context->msg_Auto2800[6]=pt_Auto2800;
	_Context->msg_Auto2800[7]=xx_Auto2800;
	_Context->hint_Auto2800[0]=en__Auto2800;
	_Context->hint_Auto2800[1]=fr__Auto2800;
	_Context->hint_Auto2800[2]=it__Auto2800;
	_Context->hint_Auto2800[3]=es__Auto2800;
	_Context->hint_Auto2800[4]=de__Auto2800;
	_Context->hint_Auto2800[5]=nl__Auto2800;
	_Context->hint_Auto2800[6]=pt__Auto2800;
	_Context->hint_Auto2800[7]=xx__Auto2800;
	for (i=0; i < 8; i++)_Context->msg_Auto2801[i]=" ";
	_Context->msg_Auto2801[0]=en_Auto2801;
	_Context->msg_Auto2801[1]=fr_Auto2801;
	_Context->msg_Auto2801[2]=it_Auto2801;
	_Context->msg_Auto2801[3]=es_Auto2801;
	_Context->msg_Auto2801[4]=de_Auto2801;
	_Context->msg_Auto2801[5]=nl_Auto2801;
	_Context->msg_Auto2801[6]=pt_Auto2801;
	_Context->msg_Auto2801[7]=xx_Auto2801;
	_Context->hint_Auto2801[0]=en__Auto2801;
	_Context->hint_Auto2801[1]=fr__Auto2801;
	_Context->hint_Auto2801[2]=it__Auto2801;
	_Context->hint_Auto2801[3]=es__Auto2801;
	_Context->hint_Auto2801[4]=de__Auto2801;
	_Context->hint_Auto2801[5]=nl__Auto2801;
	_Context->hint_Auto2801[6]=pt__Auto2801;
	_Context->hint_Auto2801[7]=xx__Auto2801;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2802[i]=" ";
	_Context->msg_Auto2802[0]=en_Auto2802;
	_Context->msg_Auto2802[1]=fr_Auto2802;
	_Context->msg_Auto2802[2]=it_Auto2802;
	_Context->msg_Auto2802[3]=es_Auto2802;
	_Context->msg_Auto2802[4]=de_Auto2802;
	_Context->msg_Auto2802[5]=nl_Auto2802;
	_Context->msg_Auto2802[6]=pt_Auto2802;
	_Context->msg_Auto2802[7]=xx_Auto2802;
	_Context->hint_Auto2802[0]=en__Auto2802;
	_Context->hint_Auto2802[1]=fr__Auto2802;
	_Context->hint_Auto2802[2]=it__Auto2802;
	_Context->hint_Auto2802[3]=es__Auto2802;
	_Context->hint_Auto2802[4]=de__Auto2802;
	_Context->hint_Auto2802[5]=nl__Auto2802;
	_Context->hint_Auto2802[6]=pt__Auto2802;
	_Context->hint_Auto2802[7]=xx__Auto2802;
	for (i=0; i < 8; i++)_Context->msg_Auto2803[i]=" ";
	_Context->msg_Auto2803[0]=en_Auto2803;
	_Context->msg_Auto2803[1]=fr_Auto2803;
	_Context->msg_Auto2803[2]=it_Auto2803;
	_Context->msg_Auto2803[3]=es_Auto2803;
	_Context->msg_Auto2803[4]=de_Auto2803;
	_Context->msg_Auto2803[5]=nl_Auto2803;
	_Context->msg_Auto2803[6]=pt_Auto2803;
	_Context->msg_Auto2803[7]=xx_Auto2803;
	_Context->hint_Auto2803[0]=en__Auto2803;
	_Context->hint_Auto2803[1]=fr__Auto2803;
	_Context->hint_Auto2803[2]=it__Auto2803;
	_Context->hint_Auto2803[3]=es__Auto2803;
	_Context->hint_Auto2803[4]=de__Auto2803;
	_Context->hint_Auto2803[5]=nl__Auto2803;
	_Context->hint_Auto2803[6]=pt__Auto2803;
	_Context->hint_Auto2803[7]=xx__Auto2803;
	for (i=0; i < 8; i++)_Context->msg_Auto2804[i]=" ";
	_Context->msg_Auto2804[0]=en_Auto2804;
	_Context->msg_Auto2804[1]=fr_Auto2804;
	_Context->msg_Auto2804[2]=it_Auto2804;
	_Context->msg_Auto2804[3]=es_Auto2804;
	_Context->msg_Auto2804[4]=de_Auto2804;
	_Context->msg_Auto2804[5]=nl_Auto2804;
	_Context->msg_Auto2804[6]=pt_Auto2804;
	_Context->msg_Auto2804[7]=xx_Auto2804;
	_Context->hint_Auto2804[0]=en__Auto2804;
	_Context->hint_Auto2804[1]=fr__Auto2804;
	_Context->hint_Auto2804[2]=it__Auto2804;
	_Context->hint_Auto2804[3]=es__Auto2804;
	_Context->hint_Auto2804[4]=de__Auto2804;
	_Context->hint_Auto2804[5]=nl__Auto2804;
	_Context->hint_Auto2804[6]=pt__Auto2804;
	_Context->hint_Auto2804[7]=xx__Auto2804;
	for (i=0; i < 8; i++)_Context->msg_Auto2805[i]=" ";
	_Context->msg_Auto2805[0]=en_Auto2805;
	_Context->msg_Auto2805[1]=fr_Auto2805;
	_Context->msg_Auto2805[2]=it_Auto2805;
	_Context->msg_Auto2805[3]=es_Auto2805;
	_Context->msg_Auto2805[4]=de_Auto2805;
	_Context->msg_Auto2805[5]=nl_Auto2805;
	_Context->msg_Auto2805[6]=pt_Auto2805;
	_Context->msg_Auto2805[7]=xx_Auto2805;
	_Context->hint_Auto2805[0]=en__Auto2805;
	_Context->hint_Auto2805[1]=fr__Auto2805;
	_Context->hint_Auto2805[2]=it__Auto2805;
	_Context->hint_Auto2805[3]=es__Auto2805;
	_Context->hint_Auto2805[4]=de__Auto2805;
	_Context->hint_Auto2805[5]=nl__Auto2805;
	_Context->hint_Auto2805[6]=pt__Auto2805;
	_Context->hint_Auto2805[7]=xx__Auto2805;
	for (i=0; i < 8; i++)_Context->msg_Auto2806[i]=" ";
	_Context->msg_Auto2806[0]=en_Auto2806;
	_Context->msg_Auto2806[1]=fr_Auto2806;
	_Context->msg_Auto2806[2]=it_Auto2806;
	_Context->msg_Auto2806[3]=es_Auto2806;
	_Context->msg_Auto2806[4]=de_Auto2806;
	_Context->msg_Auto2806[5]=nl_Auto2806;
	_Context->msg_Auto2806[6]=pt_Auto2806;
	_Context->msg_Auto2806[7]=xx_Auto2806;
	_Context->hint_Auto2806[0]=en__Auto2806;
	_Context->hint_Auto2806[1]=fr__Auto2806;
	_Context->hint_Auto2806[2]=it__Auto2806;
	_Context->hint_Auto2806[3]=es__Auto2806;
	_Context->hint_Auto2806[4]=de__Auto2806;
	_Context->hint_Auto2806[5]=nl__Auto2806;
	_Context->hint_Auto2806[6]=pt__Auto2806;
	_Context->hint_Auto2806[7]=xx__Auto2806;
	for (i=0; i < 8; i++)_Context->msg_Auto2807[i]=" ";
	_Context->msg_Auto2807[0]=en_Auto2807;
	_Context->msg_Auto2807[1]=fr_Auto2807;
	_Context->msg_Auto2807[2]=it_Auto2807;
	_Context->msg_Auto2807[3]=es_Auto2807;
	_Context->msg_Auto2807[4]=de_Auto2807;
	_Context->msg_Auto2807[5]=nl_Auto2807;
	_Context->msg_Auto2807[6]=pt_Auto2807;
	_Context->msg_Auto2807[7]=xx_Auto2807;
	_Context->hint_Auto2807[0]=en__Auto2807;
	_Context->hint_Auto2807[1]=fr__Auto2807;
	_Context->hint_Auto2807[2]=it__Auto2807;
	_Context->hint_Auto2807[3]=es__Auto2807;
	_Context->hint_Auto2807[4]=de__Auto2807;
	_Context->hint_Auto2807[5]=nl__Auto2807;
	_Context->hint_Auto2807[6]=pt__Auto2807;
	_Context->hint_Auto2807[7]=xx__Auto2807;
	return(0);
}

public 	int	vwtext_hide(struct vwtext_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;

	return(result);
}

public	int	vwtext_remove(struct vwtext_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}

public	int	vwtext_show(struct vwtext_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_WidgetProperties,_Context->y_WidgetProperties,669,400,"widget_frame",_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]))) != 0)
) {
		visual_window(_Context->x_WidgetProperties,_Context->y_WidgetProperties,669,400,vfh[2],_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]),0x4);
		}
	visual_text(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+110,210,16,vfh[2],16,0,_Context->msg_Auto2790[_Context->language],strlen(_Context->msg_Auto2790[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+126,210,62,4);
	visual_filzone(_Context->x_WidgetProperties+181,_Context->y_WidgetProperties+239,1,1,27,0);
	visual_text(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+26,210,16,vfh[2],16,0,_Context->msg_Auto2792[_Context->language],strlen(_Context->msg_Auto2792[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+42,210,62,4);
	visual_text(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+200,658,16,vfh[2],16,0,_Context->msg_Auto2793[_Context->language],strlen(_Context->msg_Auto2793[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+216,658,174,4);
	visual_text(_Context->x_WidgetProperties+5,_Context->y_WidgetProperties+26,444,16,vfh[2],16,0,_Context->msg_Auto2794[_Context->language],strlen(_Context->msg_Auto2794[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+5,_Context->y_WidgetProperties+42,444,146,4);
	visual_select(_Context->x_WidgetProperties+312,_Context->y_WidgetProperties+60,126,128,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),768);
	visual_frame(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+64,128+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+12+1,_Context->y_WidgetProperties+64+1,128,16,vfh[1],34,0,_Context->buffer_Identity,255,0);
	visual_frame(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+104,424+2,64+2,5);
	visual_text(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+104+1,424,64,vfh[1],0,0,_Context->buffer_Hint,255,0);
	_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+63,180,17,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
	visual_frame(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+153,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+459+1,_Context->y_WidgetProperties+153+1,35,16,vfh[1],34,0,_Context->buffer_AtX,7,0);
	visual_frame(_Context->x_WidgetProperties+506,_Context->y_WidgetProperties+153,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+506+1,_Context->y_WidgetProperties+153+1,35,16,vfh[1],34,0,_Context->buffer_AtY,7,0);
	visual_frame(_Context->x_WidgetProperties+559,_Context->y_WidgetProperties+153,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+559+1,_Context->y_WidgetProperties+153+1,35,16,vfh[1],34,0,_Context->buffer_Width,7,0);
	visual_frame(_Context->x_WidgetProperties+614,_Context->y_WidgetProperties+153,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+614+1,_Context->y_WidgetProperties+153+1,35,16,vfh[1],34,0,_Context->buffer_Height,7,0);
	visual_select(_Context->x_WidgetProperties+160,_Context->y_WidgetProperties+244,130,100,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),768);
	visual_select(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+244,126,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),768);
	visual_frame(_Context->x_WidgetProperties+307,_Context->y_WidgetProperties+243,42+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+307+1,_Context->y_WidgetProperties+243+1,42,16,vfh[1],34,0,_Context->buffer_TextColour,6,0);
	visual_frame(_Context->x_WidgetProperties+397,_Context->y_WidgetProperties+243,42+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+397+1,_Context->y_WidgetProperties+243+1,42,16,vfh[1],34,0,_Context->buffer_Background,6,0);
	visual_frame(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+297,424+2,64+2,5);
	visual_text(_Context->x_WidgetProperties+12+1,_Context->y_WidgetProperties+297+1,424,64,vfh[1],34,0,_Context->buffer_PayLoad,255,0);
	_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+17,_Context->y_WidgetProperties+366,168,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
	_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+279,_Context->y_WidgetProperties+366,154,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
	_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+300,180,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
	_Context->trigger_IsUnderline=visual_trigger_code(_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]));
	visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+324,180,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),_Context->value_IsUnderline|0);
	_Context->trigger_IsShadow=visual_trigger_code(_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]));
	visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+348,180,16,vfh[2],28,28,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),_Context->value_IsShadow|0);
	visual_text(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+135,14,21,vfh[2],16,0,_Context->msg_Auto2795[_Context->language],strlen(_Context->msg_Auto2795[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+614,_Context->y_WidgetProperties+134,50,21,vfh[2],16,0,_Context->msg_Auto2796[_Context->language],strlen(_Context->msg_Auto2796[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+559,_Context->y_WidgetProperties+136,47,16,vfh[2],16,0,_Context->msg_Auto2797[_Context->language],strlen(_Context->msg_Auto2797[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+506,_Context->y_WidgetProperties+136,14,21,vfh[2],16,0,_Context->msg_Auto2798[_Context->language],strlen(_Context->msg_Auto2798[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+230,180,16,vfh[2],16,0,_Context->msg_Auto2799[_Context->language],strlen(_Context->msg_Auto2799[_Context->language]),2);
	visual_frame(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+244,192+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+460+1,_Context->y_WidgetProperties+244+1,192,16,vfh[1],0,0,_Context->buffer_StyleSheet,255,0);
	visual_text(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+283,98,16,vfh[2],16,0,_Context->msg_Auto2800[_Context->language],strlen(_Context->msg_Auto2800[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+308,_Context->y_WidgetProperties+228,42,16,vfh[2],16,0,_Context->msg_Auto2801[_Context->language],strlen(_Context->msg_Auto2801[_Context->language]),2);
	_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+352,_Context->y_WidgetProperties+243,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
	visual_text(_Context->x_WidgetProperties+398,_Context->y_WidgetProperties+228,42,16,vfh[2],16,0,_Context->msg_Auto2802[_Context->language],strlen(_Context->msg_Auto2802[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+230,154,16,vfh[2],16,0,_Context->msg_Auto2803[_Context->language],strlen(_Context->msg_Auto2803[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+88,180,16,vfh[2],16,0,_Context->msg_Auto2804[_Context->language],strlen(_Context->msg_Auto2804[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+160,_Context->y_WidgetProperties+228,126,16,vfh[2],16,0,_Context->msg_Auto2805[_Context->language],strlen(_Context->msg_Auto2805[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+48,154,16,vfh[2],16,0,_Context->msg_Auto2806[_Context->language],strlen(_Context->msg_Auto2806[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+308,_Context->y_WidgetProperties+44,140,16,vfh[2],16,0,_Context->msg_Auto2807[_Context->language],strlen(_Context->msg_Auto2807[_Context->language]),2);
	visual_filzone(_Context->x_WidgetProperties+177,_Context->y_WidgetProperties+241,1,1,27,0);
	visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,669,400);

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
			mptr[0] = "La classe … la quelle le widget appartient. ";
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
			mptr[0] = "Cochez cette case pour v‚rrouiller le widget. Ainsi il sera prot‚g‚ ";
			mptr[1]="contre toute tentative de modification involontaire.   ";
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
			mptr[0] = "List of the alignment options for the text.      ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Liste des possibilit‚s mises … disposition pour aligner un texte. ";
			mptr[1]="   ";
			return(visual_online_help(mptr,2));
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

private int PayLoad_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The text of the message to display. ";
			mptr[1]=" The value of this atribut may be referenced from properties text ";
			mptr[2]="by the term :this.PAYLOAD.      ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Texte … affichier. ";
			mptr[1]=" Vous retrouverez par programmation ce texte en utilisant la propri‚t‚ ";
			mptr[2]="this.PAYLOAD du widget.   ";
			return(visual_online_help(mptr,3));
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

private int IsBold_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "Display of the bold text.       ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Affichage du texte en gras.  ";
			return(visual_online_help(mptr,1));
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
			mptr[0] = "Display of the underline text   ";
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
			mptr[0] = "Display of the shadow text.  ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Affichage du texte ombr‚.  ";
			return(visual_online_help(mptr,1));
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
private int on_fgSelect_event(struct vwtext_context * _Context) {
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
		vwtext_show(_Context);
;
	return(-1);
}


public	int	vwtext_event(
struct vwtext_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsLock == mb ) return(5);
		if (_Context->trigger_IswResize == mb ) return(15);
		if (_Context->trigger_IshResize == mb ) return(16);
		if (_Context->trigger_IsBold == mb ) return(17);
		if (_Context->trigger_IsUnderline == mb ) return(18);
		if (_Context->trigger_IsShadow == mb ) return(19);
		if (_Context->trigger_fgSelect == mb ) return(21);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_WidgetProperties+616) )  
	&&  (my >= (_Context->y_WidgetProperties+4) )  
	&&  (mx <= (_Context->x_WidgetProperties+633) )  
	&&  (my <= (_Context->y_WidgetProperties+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		vwtext_show(_Context);
		return(-1);	/* WidgetProperties */

		}
		}
	if (( mx >= (_Context->x_WidgetProperties+312+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+60) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+312+126) ) 
	&&  ( my <= (_Context->y_WidgetProperties+60+16))) {
		return(2); /* WidgetClass */
		}
	if (( mx >= (_Context->x_WidgetProperties+12) ) 
	&&  ( my >= (_Context->y_WidgetProperties+64) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+12+128) ) 
	&&  ( my <= (_Context->y_WidgetProperties+64+16))) {
		return(3); /* Identity */
		}
	if (( mx >= (_Context->x_WidgetProperties+13) ) 
	&&  ( my >= (_Context->y_WidgetProperties+104) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+13+424) ) 
	&&  ( my <= (_Context->y_WidgetProperties+104+64))) {
		return(4); /* Hint */
		}
	if (( mx >= (_Context->x_WidgetProperties+460) ) 
	&&  ( my >= (_Context->y_WidgetProperties+63) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+460+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+63+17))) {
		return(5); /* IsLock */
		}
	if (( mx >= (_Context->x_WidgetProperties+459) ) 
	&&  ( my >= (_Context->y_WidgetProperties+153) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+459+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+153+16))) {
		return(6); /* AtX */
		}
	if (( mx >= (_Context->x_WidgetProperties+506) ) 
	&&  ( my >= (_Context->y_WidgetProperties+153) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+506+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+153+16))) {
		return(7); /* AtY */
		}
	if (( mx >= (_Context->x_WidgetProperties+559) ) 
	&&  ( my >= (_Context->y_WidgetProperties+153) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+559+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+153+16))) {
		return(8); /* Width */
		}
	if (( mx >= (_Context->x_WidgetProperties+614) ) 
	&&  ( my >= (_Context->y_WidgetProperties+153) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+614+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+153+16))) {
		return(9); /* Height */
		}
	if (( mx >= (_Context->x_WidgetProperties+160+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+244) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+160+130) ) 
	&&  ( my <= (_Context->y_WidgetProperties+244+16))) {
		return(10); /* Align */
		}
	if (( mx >= (_Context->x_WidgetProperties+12+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+244) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+12+126) ) 
	&&  ( my <= (_Context->y_WidgetProperties+244+16))) {
		return(11); /* TextFont */
		}
	if (( mx >= (_Context->x_WidgetProperties+307) ) 
	&&  ( my >= (_Context->y_WidgetProperties+243) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+307+42) ) 
	&&  ( my <= (_Context->y_WidgetProperties+243+16))) {
		return(12); /* TextColour */
		}
	if (( mx >= (_Context->x_WidgetProperties+397) ) 
	&&  ( my >= (_Context->y_WidgetProperties+243) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+397+42) ) 
	&&  ( my <= (_Context->y_WidgetProperties+243+16))) {
		return(13); /* Background */
		}
	if (( mx >= (_Context->x_WidgetProperties+12) ) 
	&&  ( my >= (_Context->y_WidgetProperties+297) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+12+424) ) 
	&&  ( my <= (_Context->y_WidgetProperties+297+64))) {
		return(14); /* PayLoad */
		}
	if (( mx >= (_Context->x_WidgetProperties+17) ) 
	&&  ( my >= (_Context->y_WidgetProperties+366) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+17+168) ) 
	&&  ( my <= (_Context->y_WidgetProperties+366+16))) {
		return(15); /* IswResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+279) ) 
	&&  ( my >= (_Context->y_WidgetProperties+366) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+279+154) ) 
	&&  ( my <= (_Context->y_WidgetProperties+366+16))) {
		return(16); /* IshResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+459) ) 
	&&  ( my >= (_Context->y_WidgetProperties+300) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+459+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+300+16))) {
		return(17); /* IsBold */
		}
	if (( mx >= (_Context->x_WidgetProperties+459) ) 
	&&  ( my >= (_Context->y_WidgetProperties+324) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+459+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+324+16))) {
		return(18); /* IsUnderline */
		}
	if (( mx >= (_Context->x_WidgetProperties+459) ) 
	&&  ( my >= (_Context->y_WidgetProperties+348) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+459+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+348+16))) {
		return(19); /* IsShadow */
		}
	if (( mx >= (_Context->x_WidgetProperties+460) ) 
	&&  ( my >= (_Context->y_WidgetProperties+244) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+460+192) ) 
	&&  ( my <= (_Context->y_WidgetProperties+244+16))) {
		return(20); /* StyleSheet */
		}
	if (( mx >= (_Context->x_WidgetProperties+352) ) 
	&&  ( my >= (_Context->y_WidgetProperties+243) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+352+44) ) 
	&&  ( my <= (_Context->y_WidgetProperties+243+18))) {
		return(21); /* fgSelect */
		}

	return(-1);
}


public	int	vwtext_focus(struct vwtext_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* WidgetClass */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+312,_Context->y_WidgetProperties+60,126,128,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),774);
				if(change_widget_class(&_Context->value_WidgetClass)!=0){
				return(26);
				}
				break;
			case	0x3 :
				/* Identity */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+12+1,_Context->y_WidgetProperties+64+1,128,16,vfh[1],_Context->buffer_Identity,255);
			break;
			case	0x4 :
				/* Hint */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+104+1,424,64,vfh[1],_Context->buffer_Hint,255);
			break;
			case	0x5 :
				/* IsLock */
				visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+63,180,17,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),(_Context->value_IsLock |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+63,180,17,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
				break;
			case	0x6 :
				/* AtX */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+459+1,_Context->y_WidgetProperties+153+1,35,16,vfh[1],_Context->buffer_AtX,7);
			break;
			case	0x7 :
				/* AtY */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+506+1,_Context->y_WidgetProperties+153+1,35,16,vfh[1],_Context->buffer_AtY,7);
			break;
			case	0x8 :
				/* Width */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+559+1,_Context->y_WidgetProperties+153+1,35,16,vfh[1],_Context->buffer_Width,7);
			break;
			case	0x9 :
				/* Height */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+614+1,_Context->y_WidgetProperties+153+1,35,16,vfh[1],_Context->buffer_Height,7);
			break;
			case	0xa :
				/* Align */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+160,_Context->y_WidgetProperties+244,130,100,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),774);
				break;
			case	0xb :
				/* TextFont */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+244,126,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),770);
				break;
			case	0xc :
				/* TextColour */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+307+1,_Context->y_WidgetProperties+243+1,42,16,vfh[1],_Context->buffer_TextColour,6);
			break;
			case	0xd :
				/* Background */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+397+1,_Context->y_WidgetProperties+243+1,42,16,vfh[1],_Context->buffer_Background,6);
			break;
			case	0xe :
				/* PayLoad */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+12+1,_Context->y_WidgetProperties+297+1,424,64,vfh[1],_Context->buffer_PayLoad,255);
			break;
			case	0xf :
				/* IswResize */
				visual_check(_Context->x_WidgetProperties+17,_Context->y_WidgetProperties+366,168,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),(_Context->value_IswResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+17,_Context->y_WidgetProperties+366,168,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
				break;
			case	0x10 :
				/* IshResize */
				visual_check(_Context->x_WidgetProperties+279,_Context->y_WidgetProperties+366,154,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),(_Context->value_IshResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+279,_Context->y_WidgetProperties+366,154,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
				break;
			case	0x11 :
				/* IsBold */
				visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+300,180,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),(_Context->value_IsBold |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+300,180,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
				break;
			case	0x12 :
				/* IsUnderline */
				visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+324,180,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),(_Context->value_IsUnderline |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsUnderline=visual_trigger_code(_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]));
	visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+324,180,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),_Context->value_IsUnderline|0);
				break;
			case	0x13 :
				/* IsShadow */
				visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+348,180,16,vfh[2],28,28,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),(_Context->value_IsShadow |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsShadow=visual_trigger_code(_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]));
	visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+348,180,16,vfh[2],28,28,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),_Context->value_IsShadow|0);
				break;
			case	0x14 :
				/* StyleSheet */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+460+1,_Context->y_WidgetProperties+244+1,192,16,vfh[1],_Context->buffer_StyleSheet,255);
			break;
			case	0x15 :
				/* fgSelect */
				_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
				visual_button(_Context->x_WidgetProperties+352,_Context->y_WidgetProperties+243,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+352,_Context->y_WidgetProperties+243,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			vwtext_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=21;
			vwtext_show(_Context);
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
			if ((retcode=vwtext_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (WidgetClass_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Identity_help(_Context) != 0) { continue; }
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
						if (AtY_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (Width_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (Height_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (Align_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (TextFont_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (TextColour_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (Background_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (PayLoad_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (IswResize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (IshResize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (IsBold_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (IsUnderline_help(_Context) != 0) { continue; }
						else { break; }
					case	0x13 :
						if (IsShadow_help(_Context) != 0) { continue; }
						else { break; }
					case	0x14 :
						if (StyleSheet_help(_Context) != 0) { continue; }
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
					/* WidgetClass */
					continue;
				case	0x3 :
					/* Identity */
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
					/* AtY */
					continue;
				case	0x8 :
					/* Width */
					continue;
				case	0x9 :
					/* Height */
					continue;
				case	0xa :
					/* Align */
					continue;
				case	0xb :
					/* TextFont */
					continue;
				case	0xc :
					/* TextColour */
					continue;
				case	0xd :
					/* Background */
					continue;
				case	0xe :
					/* PayLoad */
					continue;
				case	0xf :
					/* IswResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IswResize += 1;
						_Context->value_IswResize &= 1;
						}
					continue;
				case	0x10 :
					/* IshResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IshResize += 1;
						_Context->value_IshResize &= 1;
						}
					continue;
				case	0x11 :
					/* IsBold */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsBold += 1;
						_Context->value_IsBold &= 1;
						}
					continue;
				case	0x12 :
					/* IsUnderline */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsUnderline += 1;
						_Context->value_IsUnderline &= 1;
						}
					continue;
				case	0x13 :
					/* IsShadow */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsShadow += 1;
						_Context->value_IsShadow &= 1;
						}
					continue;
				case	0x14 :
					/* StyleSheet */
					continue;
				case	0x15 :
					/* fgSelect */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
						visual_button(_Context->x_WidgetProperties+352,_Context->y_WidgetProperties+243,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+352,_Context->y_WidgetProperties+243,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
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
				_Context->focus_item=21;
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

public	int	vwtext()
{
	int	status=0;
	struct vwtext_context * _Context=(struct vwtext_context*) 0;
	status = vwtext_create(&_Context);
	if ( status != 0) return(status);
	status = vwtext_show(_Context);
		enter_modal();
	status = vwtext_focus(_Context);
		leave_modal();
	status = vwtext_hide(_Context);
	status = vwtext_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwtext_c */
