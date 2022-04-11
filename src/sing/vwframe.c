
#ifndef _vwframe_c
#define _vwframe_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vwframe.xml                                              */
/* Target         : vwframe.c                                                */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "sing.h"
#include "singform.h"
#include "singprot.h"
#define en_WidgetProperties   "Frame widget - Properties"
#define fr_WidgetProperties   "Frame - Propri‚t‚s"
#define it_WidgetProperties   "Frame widget - Properties"
#define es_WidgetProperties   "Frame widget - Properties"
#define de_WidgetProperties   "Frame widget - Properties"
#define nl_WidgetProperties   "Frame widget - Properties"
#define pt_WidgetProperties   "Frame widget - Properties"
#define xx_WidgetProperties   "Frame widget - Properties"
#define en__WidgetProperties   ""
#define fr__WidgetProperties   ""
#define it__WidgetProperties   ""
#define es__WidgetProperties   ""
#define de__WidgetProperties   ""
#define nl__WidgetProperties   ""
#define pt__WidgetProperties   ""
#define xx__WidgetProperties   ""
#define en_Auto3608   "Position and dimension"
#define fr_Auto3608   "Position et Dimension"
#define it_Auto3608   "Position and dimension"
#define es_Auto3608   "Position and dimension"
#define de_Auto3608   "Position and dimension"
#define nl_Auto3608   "Position and dimension"
#define pt_Auto3608   "Position and dimension"
#define xx_Auto3608   "Position and dimension"
#define en__Auto3608   ""
#define fr__Auto3608   ""
#define it__Auto3608   ""
#define es__Auto3608   ""
#define de__Auto3608   ""
#define nl__Auto3608   ""
#define pt__Auto3608   ""
#define xx__Auto3608   ""
#define en_Auto3610   "Title"
#define fr_Auto3610   "Titre"
#define it_Auto3610   "Title"
#define es_Auto3610   "Title"
#define de_Auto3610   "Title"
#define nl_Auto3610   "Title"
#define pt_Auto3610   "Title"
#define xx_Auto3610   "Title"
#define en__Auto3610   ""
#define fr__Auto3610   ""
#define it__Auto3610   ""
#define es__Auto3610   ""
#define de__Auto3610   ""
#define nl__Auto3610   ""
#define pt__Auto3610   ""
#define xx__Auto3610   ""
#define en_Auto3611   "Behaviour"
#define fr_Auto3611   "Comportement"
#define it_Auto3611   "Behaviour"
#define es_Auto3611   "Behaviour"
#define de_Auto3611   "Behaviour"
#define nl_Auto3611   "Behaviour"
#define pt_Auto3611   "Behaviour"
#define xx_Auto3611   "Behaviour"
#define en__Auto3611   ""
#define fr__Auto3611   ""
#define it__Auto3611   ""
#define es__Auto3611   ""
#define de__Auto3611   ""
#define nl__Auto3611   ""
#define pt__Auto3611   ""
#define xx__Auto3611   ""
#define en_Auto3612   "Appearence"
#define fr_Auto3612   "Apparence"
#define it_Auto3612   "Appearence"
#define es_Auto3612   "Appearence"
#define de_Auto3612   "Appearence"
#define nl_Auto3612   "Appearence"
#define pt_Auto3612   "Appearence"
#define xx_Auto3612   "Appearence"
#define en__Auto3612   ""
#define fr__Auto3612   ""
#define it__Auto3612   ""
#define es__Auto3612   ""
#define de__Auto3612   ""
#define nl__Auto3612   ""
#define pt__Auto3612   ""
#define xx__Auto3612   ""
#define en_Auto3613   "General"
#define fr_Auto3613   "G‚n‚ral"
#define it_Auto3613   "General"
#define es_Auto3613   "General"
#define de_Auto3613   "General"
#define nl_Auto3613   "General"
#define pt_Auto3613   "General"
#define xx_Auto3613   "General"
#define en__Auto3613   ""
#define fr__Auto3613   ""
#define it__Auto3613   ""
#define es__Auto3613   ""
#define de__Auto3613   ""
#define nl__Auto3613   ""
#define pt__Auto3613   ""
#define xx__Auto3613   ""
#define en_Identity   ""
#define en__Identity   ""
#define en__WidgetClass   ""
#define en__Align   ""
#define fr__Align   ""
#define it__Align   ""
#define es__Align   ""
#define de__Align   ""
#define nl__Align   ""
#define pt__Align   ""
#define xx__Align   ""
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
#define en_AtY   ""
#define en__AtY   ""
#define en_Width   ""
#define en__Width   ""
#define en_Height   ""
#define en__Height   ""
#define en__TextFont   ""
#define fr__TextFont   ""
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
#define en_TextColour   ""
#define en__TextColour   ""
#define en_Background   ""
#define en__Background   ""
#define en_auto5   "X"
#define fr_auto5   "X"
#define it_auto5   "X"
#define es_auto5   "X"
#define de_auto5   "X"
#define nl_auto5   "X"
#define pt_auto5   "X"
#define xx_auto5   "X"
#define en__auto5   ""
#define fr__auto5   ""
#define it__auto5   ""
#define es__auto5   ""
#define de__auto5   ""
#define nl__auto5   ""
#define pt__auto5   ""
#define xx__auto5   ""
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
#define en_auto6   "Height"
#define fr_auto6   "Hauteur"
#define it_auto6   "Height"
#define es_auto6   "Height"
#define de_auto6   "Height"
#define nl_auto6   "Height"
#define pt_auto6   "Height"
#define xx_auto6   "Height"
#define en__auto6   ""
#define fr__auto6   ""
#define it__auto6   ""
#define es__auto6   ""
#define de__auto6   ""
#define nl__auto6   ""
#define pt__auto6   ""
#define xx__auto6   ""
#define en_auto7   "Width"
#define fr_auto7   "Largeur"
#define it_auto7   "Width"
#define es_auto7   "Width"
#define de_auto7   "Width"
#define nl_auto7   "Width"
#define pt_auto7   "Width"
#define xx_auto7   "Width"
#define en__auto7   ""
#define fr__auto7   ""
#define it__auto7   ""
#define es__auto7   ""
#define de__auto7   ""
#define nl__auto7   ""
#define pt__auto7   ""
#define xx__auto7   ""
#define en_auto8   "Y"
#define fr_auto8   "Y"
#define it_auto8   "Y"
#define es_auto8   "Y"
#define de_auto8   "Y"
#define nl_auto8   "Y"
#define pt_auto8   "Y"
#define xx_auto8   "Y"
#define en__auto8   ""
#define fr__auto8   ""
#define it__auto8   ""
#define es__auto8   ""
#define de__auto8   ""
#define nl__auto8   ""
#define pt__auto8   ""
#define xx__auto8   ""
#define en_auto64   "Font"
#define fr_auto64   "Police"
#define it_auto64   "Font"
#define es_auto64   "Font"
#define de_auto64   "Font"
#define nl_auto64   "Font"
#define pt_auto64   "Font"
#define xx_auto64   "Font"
#define en__auto64   ""
#define fr__auto64   ""
#define it__auto64   ""
#define es__auto64   ""
#define de__auto64   ""
#define nl__auto64   ""
#define pt__auto64   ""
#define xx__auto64   ""
#define en_StyleSheet   ""
#define fr_StyleSheet   ""
#define en__StyleSheet   ""
#define fr__StyleSheet   ""
#define en_auto73   "Text"
#define fr_auto73   "Texte"
#define it_auto73   "Text"
#define es_auto73   "Text"
#define de_auto73   "Text"
#define nl_auto73   "Text"
#define pt_auto73   "Text"
#define xx_auto73   "Text"
#define en__auto73   ""
#define fr__auto73   ""
#define it__auto73   ""
#define es__auto73   ""
#define de__auto73   ""
#define nl__auto73   ""
#define pt__auto73   ""
#define xx__auto73   ""
#define en_auto67   "Fore"
#define fr_auto67   "Texte"
#define it_auto67   "Fore"
#define es_auto67   "Fore"
#define de_auto67   "Fore"
#define nl_auto67   "Fore"
#define pt_auto67   "Fore"
#define xx_auto67   "Fore"
#define en__auto67   ""
#define fr__auto67   ""
#define it__auto67   ""
#define es__auto67   ""
#define de__auto67   ""
#define nl__auto67   ""
#define pt__auto67   ""
#define xx__auto67   ""
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
#define en_auto70   "Back"
#define fr_auto70   "Fond"
#define it_auto70   "Back"
#define es_auto70   "Back"
#define de_auto70   "Back"
#define nl_auto70   "Back"
#define pt_auto70   "Back"
#define xx_auto70   "Back"
#define en__auto70   ""
#define fr__auto70   ""
#define it__auto70   ""
#define es__auto70   ""
#define de__auto70   ""
#define nl__auto70   ""
#define pt__auto70   ""
#define xx__auto70   ""
#define en_Auto3615   "Explicit style"
#define fr_Auto3615   "Style explicite"
#define it_Auto3615   "Explicit style"
#define es_Auto3615   "Explicit style"
#define de_Auto3615   "Explicit style"
#define nl_Auto3615   "Explicit style"
#define pt_Auto3615   "Explicit style"
#define xx_Auto3615   "Explicit style"
#define en__Auto3615   ""
#define fr__Auto3615   ""
#define it__Auto3615   ""
#define es__Auto3615   ""
#define de__Auto3615   ""
#define nl__Auto3615   ""
#define pt__Auto3615   ""
#define xx__Auto3615   ""
#define en_Auto3616   "Hint"
#define fr_Auto3616   "Infobulle"
#define it_Auto3616   "Hint"
#define es_Auto3616   "Hint"
#define de_Auto3616   "Hint"
#define nl_Auto3616   "Hint"
#define pt_Auto3616   "Hint"
#define xx_Auto3616   "Hint"
#define en__Auto3616   ""
#define fr__Auto3616   ""
#define it__Auto3616   ""
#define es__Auto3616   ""
#define de__Auto3616   ""
#define nl__Auto3616   ""
#define pt__Auto3616   ""
#define xx__Auto3616   ""
#define en_auto138   "Alignment"
#define fr_auto138   "Alignement"
#define it_auto138   "Alignment"
#define es_auto138   "Alignment"
#define de_auto138   "Alignment"
#define nl_auto138   "Alignment"
#define pt_auto138   "Alignment"
#define xx_auto138   "Alignment"
#define en__auto138   ""
#define fr__auto138   ""
#define it__auto138   ""
#define es__auto138   ""
#define de__auto138   ""
#define nl__auto138   ""
#define pt__auto138   ""
#define xx__auto138   ""
#define en_auto77   "Name"
#define fr_auto77   "Nom"
#define it_auto77   "Name"
#define es_auto77   "Name"
#define de_auto77   "Name"
#define nl_auto77   "Name"
#define pt_auto77   "Name"
#define xx_auto77   "Name"
#define en__auto77   ""
#define fr__auto77   ""
#define it__auto77   ""
#define es__auto77   ""
#define de__auto77   ""
#define nl__auto77   ""
#define pt__auto77   ""
#define xx__auto77   ""
#define en_auto80   "Widget class"
#define fr_auto80   "Classe de widget"
#define it_auto80   "Widget class"
#define es_auto80   "Widget class"
#define de_auto80   "Widget class"
#define nl_auto80   "Widget class"
#define pt_auto80   "Widget class"
#define xx_auto80   "Widget class"
#define en__auto80   ""
#define fr__auto80   ""
#define it__auto80   ""
#define es__auto80   ""
#define de__auto80   ""
#define nl__auto80   ""
#define pt__auto80   ""
#define xx__auto80   ""
#include "vwframe.h"
static int	vfh[16];
private int on_fgSelect_event(struct vwframe_context * _Context);

/*	------------------------	*/
/*	p o s i t i o n _ a t ()	*/
/*	------------------------	*/
void	vwframe_position_at(struct vwframe_context * _Context,int x,int y){
	_Context->x_WidgetProperties=x;
	_Context->y_WidgetProperties=y;

}

/*	----------------	*/
/*	S e t V a r s ()	*/
/*	----------------	*/
void	vwframe_SetVars(struct vwframe_context * _Context){
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
void	vwframe_GetVars(struct vwframe_context * _Context){
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

public	int	vwframe_attach()
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

public	int	vwframe_attach_mode(int mode)
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

public	int	vwframe_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	vwframe_create(struct vwframe_context **cptr)
{

	int i;
	struct vwframe_context * _Context=(struct vwframe_context*)0;
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
	if (!(_Context = allocate( sizeof( struct vwframe_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=21;
		for (i=0; i < 255; i++)  *(_Context->buffer_Identity+i)=' ';
		_Context->value_WidgetClass=0;
		_Context->value_Align=0;
		for (i=0; i < 265; i++)  *(_Context->buffer_Hint+i)=' ';
		_Context->value_IsLock=0;
		for (i=0; i < 7; i++)  *(_Context->buffer_AtX+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_AtY+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Width+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Height+i)=' ';
		_Context->value_TextFont=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_PayLoad+i)=' ';
		_Context->value_IswResize=0;
		_Context->value_IshResize=0;
		for (i=0; i < 6; i++)  *(_Context->buffer_TextColour+i)=' ';
		for (i=0; i < 6; i++)  *(_Context->buffer_Background+i)=' ';
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
	_Context->w_WidgetProperties=670;
	_Context->h_WidgetProperties=400;
	_Context->window_col=0;
	_Context->window_row=0;
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
	for (i=0; i < 8; i++)_Context->msg_WidgetClass[i]=" ";
	_Context->hint_WidgetClass[0]=en__WidgetClass;
	for (i=0; i < 8; i++)_Context->msg_Align[i]=" ";
	_Context->hint_Align[0]=en__Align;
	_Context->hint_Align[1]=fr__Align;
	_Context->hint_Align[2]=it__Align;
	_Context->hint_Align[3]=es__Align;
	_Context->hint_Align[4]=de__Align;
	_Context->hint_Align[5]=nl__Align;
	_Context->hint_Align[6]=pt__Align;
	_Context->hint_Align[7]=xx__Align;
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
	_Context->hint_AtY[0]=en__AtY;
	_Context->hint_Width[0]=en__Width;
	_Context->hint_Height[0]=en__Height;
	for (i=0; i < 8; i++)_Context->msg_TextFont[i]=" ";
	_Context->hint_TextFont[0]=en__TextFont;
	_Context->hint_TextFont[1]=fr__TextFont;
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
	_Context->hint_TextColour[0]=en__TextColour;
	_Context->hint_Background[0]=en__Background;
	for (i=0; i < 8; i++)_Context->msg_auto5[i]=" ";
	_Context->msg_auto5[0]=en_auto5;
	_Context->msg_auto5[1]=fr_auto5;
	_Context->msg_auto5[2]=it_auto5;
	_Context->msg_auto5[3]=es_auto5;
	_Context->msg_auto5[4]=de_auto5;
	_Context->msg_auto5[5]=nl_auto5;
	_Context->msg_auto5[6]=pt_auto5;
	_Context->msg_auto5[7]=xx_auto5;
	_Context->hint_auto5[0]=en__auto5;
	_Context->hint_auto5[1]=fr__auto5;
	_Context->hint_auto5[2]=it__auto5;
	_Context->hint_auto5[3]=es__auto5;
	_Context->hint_auto5[4]=de__auto5;
	_Context->hint_auto5[5]=nl__auto5;
	_Context->hint_auto5[6]=pt__auto5;
	_Context->hint_auto5[7]=xx__auto5;
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
	for (i=0; i < 8; i++)_Context->msg_auto6[i]=" ";
	_Context->msg_auto6[0]=en_auto6;
	_Context->msg_auto6[1]=fr_auto6;
	_Context->msg_auto6[2]=it_auto6;
	_Context->msg_auto6[3]=es_auto6;
	_Context->msg_auto6[4]=de_auto6;
	_Context->msg_auto6[5]=nl_auto6;
	_Context->msg_auto6[6]=pt_auto6;
	_Context->msg_auto6[7]=xx_auto6;
	_Context->hint_auto6[0]=en__auto6;
	_Context->hint_auto6[1]=fr__auto6;
	_Context->hint_auto6[2]=it__auto6;
	_Context->hint_auto6[3]=es__auto6;
	_Context->hint_auto6[4]=de__auto6;
	_Context->hint_auto6[5]=nl__auto6;
	_Context->hint_auto6[6]=pt__auto6;
	_Context->hint_auto6[7]=xx__auto6;
	for (i=0; i < 8; i++)_Context->msg_auto7[i]=" ";
	_Context->msg_auto7[0]=en_auto7;
	_Context->msg_auto7[1]=fr_auto7;
	_Context->msg_auto7[2]=it_auto7;
	_Context->msg_auto7[3]=es_auto7;
	_Context->msg_auto7[4]=de_auto7;
	_Context->msg_auto7[5]=nl_auto7;
	_Context->msg_auto7[6]=pt_auto7;
	_Context->msg_auto7[7]=xx_auto7;
	_Context->hint_auto7[0]=en__auto7;
	_Context->hint_auto7[1]=fr__auto7;
	_Context->hint_auto7[2]=it__auto7;
	_Context->hint_auto7[3]=es__auto7;
	_Context->hint_auto7[4]=de__auto7;
	_Context->hint_auto7[5]=nl__auto7;
	_Context->hint_auto7[6]=pt__auto7;
	_Context->hint_auto7[7]=xx__auto7;
	for (i=0; i < 8; i++)_Context->msg_auto8[i]=" ";
	_Context->msg_auto8[0]=en_auto8;
	_Context->msg_auto8[1]=fr_auto8;
	_Context->msg_auto8[2]=it_auto8;
	_Context->msg_auto8[3]=es_auto8;
	_Context->msg_auto8[4]=de_auto8;
	_Context->msg_auto8[5]=nl_auto8;
	_Context->msg_auto8[6]=pt_auto8;
	_Context->msg_auto8[7]=xx_auto8;
	_Context->hint_auto8[0]=en__auto8;
	_Context->hint_auto8[1]=fr__auto8;
	_Context->hint_auto8[2]=it__auto8;
	_Context->hint_auto8[3]=es__auto8;
	_Context->hint_auto8[4]=de__auto8;
	_Context->hint_auto8[5]=nl__auto8;
	_Context->hint_auto8[6]=pt__auto8;
	_Context->hint_auto8[7]=xx__auto8;
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
	_Context->hint_auto64[1]=fr__auto64;
	_Context->hint_auto64[2]=it__auto64;
	_Context->hint_auto64[3]=es__auto64;
	_Context->hint_auto64[4]=de__auto64;
	_Context->hint_auto64[5]=nl__auto64;
	_Context->hint_auto64[6]=pt__auto64;
	_Context->hint_auto64[7]=xx__auto64;
	_Context->hint_StyleSheet[0]=en__StyleSheet;
	_Context->hint_StyleSheet[1]=fr__StyleSheet;
	for (i=0; i < 8; i++)_Context->msg_auto73[i]=" ";
	_Context->msg_auto73[0]=en_auto73;
	_Context->msg_auto73[1]=fr_auto73;
	_Context->msg_auto73[2]=it_auto73;
	_Context->msg_auto73[3]=es_auto73;
	_Context->msg_auto73[4]=de_auto73;
	_Context->msg_auto73[5]=nl_auto73;
	_Context->msg_auto73[6]=pt_auto73;
	_Context->msg_auto73[7]=xx_auto73;
	_Context->hint_auto73[0]=en__auto73;
	_Context->hint_auto73[1]=fr__auto73;
	_Context->hint_auto73[2]=it__auto73;
	_Context->hint_auto73[3]=es__auto73;
	_Context->hint_auto73[4]=de__auto73;
	_Context->hint_auto73[5]=nl__auto73;
	_Context->hint_auto73[6]=pt__auto73;
	_Context->hint_auto73[7]=xx__auto73;
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
	_Context->hint_auto138[1]=fr__auto138;
	_Context->hint_auto138[2]=it__auto138;
	_Context->hint_auto138[3]=es__auto138;
	_Context->hint_auto138[4]=de__auto138;
	_Context->hint_auto138[5]=nl__auto138;
	_Context->hint_auto138[6]=pt__auto138;
	_Context->hint_auto138[7]=xx__auto138;
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
	_Context->hint_auto80[1]=fr__auto80;
	_Context->hint_auto80[2]=it__auto80;
	_Context->hint_auto80[3]=es__auto80;
	_Context->hint_auto80[4]=de__auto80;
	_Context->hint_auto80[5]=nl__auto80;
	_Context->hint_auto80[6]=pt__auto80;
	_Context->hint_auto80[7]=xx__auto80;
	return(0);
}

public 	int	vwframe_hide(struct vwframe_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;

	return(result);
}

public	int	vwframe_remove(struct vwframe_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}

public	int	vwframe_show(struct vwframe_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,"widget_frame",_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]))) != 0)
) {
		visual_window(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,vfh[2],_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]),0x4);
		}
	visual_text(_Context->x_WidgetProperties+455,_Context->y_WidgetProperties+94,210,16,vfh[2],16,0,_Context->msg_Auto3608[_Context->language],strlen(_Context->msg_Auto3608[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+455,_Context->y_WidgetProperties+110,210,46,4);
	visual_filzone(_Context->x_WidgetProperties+251,_Context->y_WidgetProperties+259,1,1,27,0);
	visual_text(_Context->x_WidgetProperties+5,_Context->y_WidgetProperties+227,660,16,vfh[2],16,0,_Context->msg_Auto3610[_Context->language],strlen(_Context->msg_Auto3610[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+5,_Context->y_WidgetProperties+243,660,152,4);
	visual_text(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+27,210,16,vfh[2],16,0,_Context->msg_Auto3611[_Context->language],strlen(_Context->msg_Auto3611[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+43,210,46,4);
	visual_text(_Context->x_WidgetProperties+455,_Context->y_WidgetProperties+159,210,16,vfh[2],16,0,_Context->msg_Auto3612[_Context->language],strlen(_Context->msg_Auto3612[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+455,_Context->y_WidgetProperties+175,210,46,4);
	visual_text(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+26,441,16,vfh[2],16,0,_Context->msg_Auto3613[_Context->language],strlen(_Context->msg_Auto3613[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+42,441,179,4);
	visual_frame(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+81,128+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+81+1,128,16,vfh[1],34,0,_Context->buffer_Identity,255,0);
	visual_select(_Context->x_WidgetProperties+226,_Context->y_WidgetProperties+80,126,144,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),768);
	visual_select(_Context->x_WidgetProperties+226,_Context->y_WidgetProperties+266,130,100,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),768);
	visual_frame(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+131,424+2,80+2,5);
	visual_text(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+131+1,424,80,vfh[1],0,0,_Context->buffer_Hint,265,0);
	_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+462,_Context->y_WidgetProperties+59,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
	visual_frame(_Context->x_WidgetProperties+461,_Context->y_WidgetProperties+130,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+461+1,_Context->y_WidgetProperties+130+1,35,16,vfh[1],34,0,_Context->buffer_AtX,7,0);
	visual_frame(_Context->x_WidgetProperties+505,_Context->y_WidgetProperties+129,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+505+1,_Context->y_WidgetProperties+129+1,35,16,vfh[1],34,0,_Context->buffer_AtY,7,0);
	visual_frame(_Context->x_WidgetProperties+566,_Context->y_WidgetProperties+130,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+566+1,_Context->y_WidgetProperties+130+1,35,16,vfh[1],34,0,_Context->buffer_Width,7,0);
	visual_frame(_Context->x_WidgetProperties+616,_Context->y_WidgetProperties+131,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+616+1,_Context->y_WidgetProperties+131+1,35,16,vfh[1],34,0,_Context->buffer_Height,7,0);
	visual_select(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+267,126,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),768);
	visual_frame(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+319,424+2,48+2,5);
	visual_text(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+319+1,424,48,vfh[1],34,0,_Context->buffer_PayLoad,255,0);
	_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+372,200,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
	_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+268,_Context->y_WidgetProperties+372,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
	visual_frame(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+266,42+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+454+1,_Context->y_WidgetProperties+266+1,42,16,vfh[1],34,0,_Context->buffer_TextColour,6,0);
	visual_frame(_Context->x_WidgetProperties+545,_Context->y_WidgetProperties+266,42+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+545+1,_Context->y_WidgetProperties+266+1,42,16,vfh[1],34,0,_Context->buffer_Background,6,0);
	visual_text(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+115,14,21,vfh[2],16,0,_Context->msg_auto5[_Context->language],strlen(_Context->msg_auto5[_Context->language]),2);
	_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+320,180,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
	_Context->trigger_IsUnderline=visual_trigger_code(_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]));
	visual_check(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+344,180,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),_Context->value_IsUnderline|0);
	_Context->trigger_IsShadow=visual_trigger_code(_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]));
	visual_check(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+368,180,16,vfh[2],28,28,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),_Context->value_IsShadow|0);
	visual_text(_Context->x_WidgetProperties+616,_Context->y_WidgetProperties+114,50,21,vfh[2],16,0,_Context->msg_auto6[_Context->language],strlen(_Context->msg_auto6[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+564,_Context->y_WidgetProperties+115,54,21,vfh[2],16,0,_Context->msg_auto7[_Context->language],strlen(_Context->msg_auto7[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+505,_Context->y_WidgetProperties+115,14,21,vfh[2],16,0,_Context->msg_auto8[_Context->language],strlen(_Context->msg_auto8[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+253,168,16,vfh[2],16,0,_Context->msg_auto64[_Context->language],strlen(_Context->msg_auto64[_Context->language]),2);
	visual_frame(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+195,190+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+463+1,_Context->y_WidgetProperties+195+1,190,16,vfh[1],0,0,_Context->buffer_StyleSheet,255,0);
	visual_text(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+303,98,16,vfh[2],16,0,_Context->msg_auto73[_Context->language],strlen(_Context->msg_auto73[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+455,_Context->y_WidgetProperties+250,42,16,vfh[2],16,0,_Context->msg_auto67[_Context->language],strlen(_Context->msg_auto67[_Context->language]),2);
	_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+499,_Context->y_WidgetProperties+266,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
	visual_text(_Context->x_WidgetProperties+545,_Context->y_WidgetProperties+251,42,16,vfh[2],16,0,_Context->msg_auto70[_Context->language],strlen(_Context->msg_auto70[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+181,182,16,vfh[2],16,0,_Context->msg_Auto3615[_Context->language],strlen(_Context->msg_Auto3615[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+117,168,16,vfh[2],16,0,_Context->msg_Auto3616[_Context->language],strlen(_Context->msg_Auto3616[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+226,_Context->y_WidgetProperties+251,70,16,vfh[2],16,0,_Context->msg_auto138[_Context->language],strlen(_Context->msg_auto138[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+67,154,16,vfh[2],16,0,_Context->msg_auto77[_Context->language],strlen(_Context->msg_auto77[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+225,_Context->y_WidgetProperties+65,135,16,vfh[2],16,0,_Context->msg_auto80[_Context->language],strlen(_Context->msg_auto80[_Context->language]),2);
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

private int Align_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "List of the alignment options for the text.     ";
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

private int PayLoad_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The title of the frame. ";
			mptr[1]=" The value of this atribut may be referenced from properties text ";
			mptr[2]="by the term :this.PAYLOAD.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Le titre du cadre. ";
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
private int on_fgSelect_event(struct vwframe_context * _Context) {
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
		vwframe_show(_Context);
;
	return(-1);
}


public	int	vwframe_event(
struct vwframe_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsLock == mb ) return(6);
		if (_Context->trigger_IswResize == mb ) return(13);
		if (_Context->trigger_IshResize == mb ) return(14);
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
		vwframe_show(_Context);
		return(-1);	/* WidgetProperties */

		}
		}
	if (( mx >= (_Context->x_WidgetProperties+14) ) 
	&&  ( my >= (_Context->y_WidgetProperties+81) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+14+128) ) 
	&&  ( my <= (_Context->y_WidgetProperties+81+16))) {
		return(2); /* Identity */
		}
	if (( mx >= (_Context->x_WidgetProperties+226+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+80) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+226+126) ) 
	&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
		return(3); /* WidgetClass */
		}
	if (( mx >= (_Context->x_WidgetProperties+226+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+266) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+226+130) ) 
	&&  ( my <= (_Context->y_WidgetProperties+266+16))) {
		return(4); /* Align */
		}
	if (( mx >= (_Context->x_WidgetProperties+13) ) 
	&&  ( my >= (_Context->y_WidgetProperties+131) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+13+424) ) 
	&&  ( my <= (_Context->y_WidgetProperties+131+80))) {
		return(5); /* Hint */
		}
	if (( mx >= (_Context->x_WidgetProperties+462) ) 
	&&  ( my >= (_Context->y_WidgetProperties+59) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+462+182) ) 
	&&  ( my <= (_Context->y_WidgetProperties+59+16))) {
		return(6); /* IsLock */
		}
	if (( mx >= (_Context->x_WidgetProperties+461) ) 
	&&  ( my >= (_Context->y_WidgetProperties+130) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+461+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+130+16))) {
		return(7); /* AtX */
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
	&&  ( my >= (_Context->y_WidgetProperties+131) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+616+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+131+16))) {
		return(10); /* Height */
		}
	if (( mx >= (_Context->x_WidgetProperties+13+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+267) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+13+126) ) 
	&&  ( my <= (_Context->y_WidgetProperties+267+16))) {
		return(11); /* TextFont */
		}
	if (( mx >= (_Context->x_WidgetProperties+13) ) 
	&&  ( my >= (_Context->y_WidgetProperties+319) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+13+424) ) 
	&&  ( my <= (_Context->y_WidgetProperties+319+48))) {
		return(12); /* PayLoad */
		}
	if (( mx >= (_Context->x_WidgetProperties+13) ) 
	&&  ( my >= (_Context->y_WidgetProperties+372) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+13+200) ) 
	&&  ( my <= (_Context->y_WidgetProperties+372+16))) {
		return(13); /* IswResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+268) ) 
	&&  ( my >= (_Context->y_WidgetProperties+372) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+268+165) ) 
	&&  ( my <= (_Context->y_WidgetProperties+372+16))) {
		return(14); /* IshResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+454) ) 
	&&  ( my >= (_Context->y_WidgetProperties+266) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+454+42) ) 
	&&  ( my <= (_Context->y_WidgetProperties+266+16))) {
		return(15); /* TextColour */
		}
	if (( mx >= (_Context->x_WidgetProperties+545) ) 
	&&  ( my >= (_Context->y_WidgetProperties+266) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+545+42) ) 
	&&  ( my <= (_Context->y_WidgetProperties+266+16))) {
		return(16); /* Background */
		}
	if (( mx >= (_Context->x_WidgetProperties+463) ) 
	&&  ( my >= (_Context->y_WidgetProperties+320) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+463+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+320+16))) {
		return(17); /* IsBold */
		}
	if (( mx >= (_Context->x_WidgetProperties+463) ) 
	&&  ( my >= (_Context->y_WidgetProperties+344) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+463+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+344+16))) {
		return(18); /* IsUnderline */
		}
	if (( mx >= (_Context->x_WidgetProperties+463) ) 
	&&  ( my >= (_Context->y_WidgetProperties+368) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+463+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+368+16))) {
		return(19); /* IsShadow */
		}
	if (( mx >= (_Context->x_WidgetProperties+463) ) 
	&&  ( my >= (_Context->y_WidgetProperties+195) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+463+190) ) 
	&&  ( my <= (_Context->y_WidgetProperties+195+16))) {
		return(20); /* StyleSheet */
		}
	if (( mx >= (_Context->x_WidgetProperties+499) ) 
	&&  ( my >= (_Context->y_WidgetProperties+266) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+499+44) ) 
	&&  ( my <= (_Context->y_WidgetProperties+266+18))) {
		return(21); /* fgSelect */
		}

	return(-1);
}


public	int	vwframe_focus(struct vwframe_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Identity */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+81+1,128,16,vfh[1],_Context->buffer_Identity,255);
			break;
			case	0x3 :
				/* WidgetClass */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+226,_Context->y_WidgetProperties+80,126,144,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),774);
				if(change_widget_class(&_Context->value_WidgetClass)!=0){
				return(26);
				}
				break;
			case	0x4 :
				/* Align */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+226,_Context->y_WidgetProperties+266,130,100,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),774);
				break;
			case	0x5 :
				/* Hint */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+131+1,424,80,vfh[1],_Context->buffer_Hint,265);
			break;
			case	0x6 :
				/* IsLock */
				visual_check(_Context->x_WidgetProperties+462,_Context->y_WidgetProperties+59,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),(_Context->value_IsLock |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+462,_Context->y_WidgetProperties+59,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
				break;
			case	0x7 :
				/* AtX */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+461+1,_Context->y_WidgetProperties+130+1,35,16,vfh[1],_Context->buffer_AtX,7);
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
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+616+1,_Context->y_WidgetProperties+131+1,35,16,vfh[1],_Context->buffer_Height,7);
			break;
			case	0xb :
				/* TextFont */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+267,126,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),770);
				break;
			case	0xc :
				/* PayLoad */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+319+1,424,48,vfh[1],_Context->buffer_PayLoad,255);
			break;
			case	0xd :
				/* IswResize */
				visual_check(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+372,200,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),(_Context->value_IswResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+372,200,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
				break;
			case	0xe :
				/* IshResize */
				visual_check(_Context->x_WidgetProperties+268,_Context->y_WidgetProperties+372,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),(_Context->value_IshResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+268,_Context->y_WidgetProperties+372,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
				break;
			case	0xf :
				/* TextColour */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+454+1,_Context->y_WidgetProperties+266+1,42,16,vfh[1],_Context->buffer_TextColour,6);
			break;
			case	0x10 :
				/* Background */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+545+1,_Context->y_WidgetProperties+266+1,42,16,vfh[1],_Context->buffer_Background,6);
			break;
			case	0x11 :
				/* IsBold */
				visual_check(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+320,180,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),(_Context->value_IsBold |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+320,180,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
				break;
			case	0x12 :
				/* IsUnderline */
				visual_check(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+344,180,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),(_Context->value_IsUnderline |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsUnderline=visual_trigger_code(_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]));
	visual_check(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+344,180,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),_Context->value_IsUnderline|0);
				break;
			case	0x13 :
				/* IsShadow */
				visual_check(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+368,180,16,vfh[2],28,28,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),(_Context->value_IsShadow |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsShadow=visual_trigger_code(_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]));
	visual_check(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+368,180,16,vfh[2],28,28,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),_Context->value_IsShadow|0);
				break;
			case	0x14 :
				/* StyleSheet */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+463+1,_Context->y_WidgetProperties+195+1,190,16,vfh[1],_Context->buffer_StyleSheet,255);
			break;
			case	0x15 :
				/* fgSelect */
				_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
				visual_button(_Context->x_WidgetProperties+499,_Context->y_WidgetProperties+266,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+499,_Context->y_WidgetProperties+266,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			vwframe_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=21;
			vwframe_show(_Context);
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
			if ((retcode=vwframe_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (Identity_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (WidgetClass_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Align_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Hint_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (IsLock_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (AtX_help(_Context) != 0) { continue; }
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
						if (TextFont_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (PayLoad_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (IswResize_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (IshResize_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (TextColour_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (Background_help(_Context) != 0) { continue; }
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
					/* Identity */
					continue;
				case	0x3 :
					/* WidgetClass */
					continue;
				case	0x4 :
					/* Align */
					continue;
				case	0x5 :
					/* Hint */
					continue;
				case	0x6 :
					/* IsLock */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsLock += 1;
						_Context->value_IsLock &= 1;
						}
					continue;
				case	0x7 :
					/* AtX */
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
					/* TextFont */
					continue;
				case	0xc :
					/* PayLoad */
					continue;
				case	0xd :
					/* IswResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IswResize += 1;
						_Context->value_IswResize &= 1;
						}
					continue;
				case	0xe :
					/* IshResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IshResize += 1;
						_Context->value_IshResize &= 1;
						}
					continue;
				case	0xf :
					/* TextColour */
					continue;
				case	0x10 :
					/* Background */
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
						visual_button(_Context->x_WidgetProperties+499,_Context->y_WidgetProperties+266,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+499,_Context->y_WidgetProperties+266,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
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

public	int	vwframe()
{
	int	status=0;
	struct vwframe_context * _Context=(struct vwframe_context*) 0;
	status = vwframe_create(&_Context);
	if ( status != 0) return(status);
	status = vwframe_show(_Context);
		enter_modal();
	status = vwframe_focus(_Context);
		leave_modal();
	status = vwframe_hide(_Context);
	status = vwframe_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwframe_c */
