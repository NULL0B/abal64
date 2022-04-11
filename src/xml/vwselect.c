
#ifndef _vwselect_c
#define _vwselect_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vwselect.xml                                             */
/* Target         : vwselect.c                                               */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "sing.h"
#include "singform.h"
#include "singprot.h"
#define en_WidgetProperties   "Select - Properties"
#define fr_WidgetProperties   "Select - Propri‚t‚s"
#define it_WidgetProperties   "Select - Properties"
#define es_WidgetProperties   "Select - Properties"
#define de_WidgetProperties   "Select - Properties"
#define nl_WidgetProperties   "Select - Properties"
#define pt_WidgetProperties   "Select - Properties"
#define xx_WidgetProperties   "Select - Properties"
#define en__WidgetProperties   ""
#define fr__WidgetProperties   ""
#define it__WidgetProperties   ""
#define es__WidgetProperties   ""
#define de__WidgetProperties   ""
#define nl__WidgetProperties   ""
#define pt__WidgetProperties   ""
#define xx__WidgetProperties   ""
#define en_Auto3616   "Position and Dimension"
#define fr_Auto3616   "Position et Dimension"
#define it_Auto3616   ""
#define es_Auto3616   ""
#define de_Auto3616   ""
#define nl_Auto3616   ""
#define pt_Auto3616   ""
#define xx_Auto3616   ""
#define en__Auto3616   ""
#define fr__Auto3616   ""
#define it__Auto3616   ""
#define es__Auto3616   ""
#define de__Auto3616   ""
#define nl__Auto3616   ""
#define pt__Auto3616   ""
#define xx__Auto3616   ""
#define en_Auto3618   "Behaviour"
#define fr_Auto3618   "Comportement"
#define it_Auto3618   "Behaviour"
#define es_Auto3618   "Behaviour"
#define de_Auto3618   "Behaviour"
#define nl_Auto3618   "Behaviour"
#define pt_Auto3618   "Behaviour"
#define xx_Auto3618   "Behaviour"
#define en__Auto3618   ""
#define fr__Auto3618   ""
#define it__Auto3618   ""
#define es__Auto3618   ""
#define de__Auto3618   ""
#define nl__Auto3618   ""
#define pt__Auto3618   ""
#define xx__Auto3618   ""
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
#define en_Auto3619   "Appearence"
#define fr_Auto3619   "Apparence"
#define it_Auto3619   "Appearence"
#define es_Auto3619   "Appearence"
#define de_Auto3619   "Appearence"
#define nl_Auto3619   "Appearence"
#define pt_Auto3619   "Appearence"
#define xx_Auto3619   "Appearence"
#define en__Auto3619   ""
#define fr__Auto3619   ""
#define it__Auto3619   ""
#define es__Auto3619   ""
#define de__Auto3619   ""
#define nl__Auto3619   ""
#define pt__Auto3619   ""
#define xx__Auto3619   ""
#define en_Auto3620   "General"
#define fr_Auto3620   "G‚n‚ral"
#define it_Auto3620   "General"
#define es_Auto3620   "General"
#define de_Auto3620   "General"
#define nl_Auto3620   "General"
#define pt_Auto3620   "General"
#define xx_Auto3620   "General"
#define en__Auto3620   ""
#define fr__Auto3620   ""
#define it__Auto3620   ""
#define es__Auto3620   ""
#define de__Auto3620   ""
#define nl__Auto3620   ""
#define pt__Auto3620   ""
#define xx__Auto3620   ""
#define en_Identity   ""
#define en__Identity   ""
#define en__WidgetClass   ""
#define fr__WidgetClass   ""
#define en_Hint   ""
#define en__Hint   ""
#define en_IsSpecial   "Sort"
#define fr_IsSpecial   "Tri‚"
#define it_IsSpecial   "Sort"
#define es_IsSpecial   "Sort"
#define de_IsSpecial   "Sort"
#define nl_IsSpecial   "Sort"
#define pt_IsSpecial   "Sort"
#define xx_IsSpecial   "Sort"
#define en__IsSpecial   ""
#define fr__IsSpecial   ""
#define it__IsSpecial   ""
#define es__IsSpecial   ""
#define de__IsSpecial   ""
#define nl__IsSpecial   ""
#define pt__IsSpecial   ""
#define xx__IsSpecial   ""
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
#define en_IsBold   "Focus Open"
#define fr_IsBold   "Ouvert"
#define it_IsBold   "Focus Open"
#define es_IsBold   "Focus Open"
#define de_IsBold   "Focus Open"
#define nl_IsBold   "Focus Open"
#define pt_IsBold   "Focus Open"
#define xx_IsBold   "Focus Open"
#define en__IsBold   ""
#define fr__IsBold   ""
#define it__IsBold   ""
#define es__IsBold   ""
#define de__IsBold   ""
#define nl__IsBold   ""
#define pt__IsBold   ""
#define xx__IsBold   ""
#define en_Auto3621   "X"
#define fr_Auto3621   "X"
#define it_Auto3621   "X"
#define es_Auto3621   "X"
#define de_Auto3621   "X"
#define nl_Auto3621   "X"
#define pt_Auto3621   "X"
#define xx_Auto3621   "X"
#define en__Auto3621   ""
#define fr__Auto3621   ""
#define it__Auto3621   ""
#define es__Auto3621   ""
#define de__Auto3621   ""
#define nl__Auto3621   ""
#define pt__Auto3621   ""
#define xx__Auto3621   ""
#define en__TextFont   ""
#define fr__TextFont   ""
#define en_Auto3622   "Height"
#define fr_Auto3622   "Hauteur"
#define it_Auto3622   "Height"
#define es_Auto3622   "Height"
#define de_Auto3622   "Height"
#define nl_Auto3622   "Height"
#define pt_Auto3622   "Height"
#define xx_Auto3622   "Height"
#define en__Auto3622   ""
#define fr__Auto3622   ""
#define it__Auto3622   ""
#define es__Auto3622   ""
#define de__Auto3622   ""
#define nl__Auto3622   ""
#define pt__Auto3622   ""
#define xx__Auto3622   ""
#define en_AtX   ""
#define en__AtX   ""
#define en_AtY   ""
#define en__AtY   ""
#define en_Width   ""
#define en__Width   ""
#define en_Height   ""
#define en__Height   ""
#define en_Auto3623   "Width"
#define fr_Auto3623   "Largeur"
#define it_Auto3623   "Width"
#define es_Auto3623   "Width"
#define de_Auto3623   "Width"
#define nl_Auto3623   "Width"
#define pt_Auto3623   "Width"
#define xx_Auto3623   "Width"
#define en__Auto3623   ""
#define fr__Auto3623   ""
#define it__Auto3623   ""
#define es__Auto3623   ""
#define de__Auto3623   ""
#define nl__Auto3623   ""
#define pt__Auto3623   ""
#define xx__Auto3623   ""
#define en_Auto3624   "Y"
#define fr_Auto3624   "Y"
#define it_Auto3624   "Y"
#define es_Auto3624   "Y"
#define de_Auto3624   "Y"
#define nl_Auto3624   "Y"
#define pt_Auto3624   "Y"
#define xx_Auto3624   "Y"
#define en__Auto3624   ""
#define fr__Auto3624   ""
#define it__Auto3624   ""
#define es__Auto3624   ""
#define de__Auto3624   ""
#define nl__Auto3624   ""
#define pt__Auto3624   ""
#define xx__Auto3624   ""
#define en_StyleSheet   ""
#define fr_StyleSheet   ""
#define en__StyleSheet   ""
#define fr__StyleSheet   ""
#define en__Align   ""
#define fr__Align   ""
#define it__Align   ""
#define es__Align   ""
#define de__Align   ""
#define nl__Align   ""
#define pt__Align   ""
#define xx__Align   ""
#define en_Auto3625   "Font"
#define fr_Auto3625   "Police"
#define it_Auto3625   "Text Font"
#define es_Auto3625   "Text Font"
#define de_Auto3625   "Text Font"
#define nl_Auto3625   "Text Font"
#define pt_Auto3625   "Text Font"
#define xx_Auto3625   "Teacs"
#define en__Auto3625   ""
#define fr__Auto3625   ""
#define it__Auto3625   ""
#define es__Auto3625   ""
#define de__Auto3625   ""
#define nl__Auto3625   ""
#define pt__Auto3625   ""
#define xx__Auto3625   ""
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
#define en_Auto3626   "Options list"
#define fr_Auto3626   "Liste des options"
#define it_Auto3626   "Text"
#define es_Auto3626   "Text"
#define de_Auto3626   "Text"
#define nl_Auto3626   "Text"
#define pt_Auto3626   "Text"
#define xx_Auto3626   "Text"
#define en__Auto3626   ""
#define fr__Auto3626   ""
#define it__Auto3626   ""
#define es__Auto3626   ""
#define de__Auto3626   ""
#define nl__Auto3626   ""
#define pt__Auto3626   ""
#define xx__Auto3626   ""
#define en_Auto3627   "Explicit style"
#define fr_Auto3627   "Style explicite"
#define it_Auto3627   "Style"
#define es_Auto3627   "Style"
#define de_Auto3627   "Style"
#define nl_Auto3627   "Style"
#define pt_Auto3627   "Style"
#define xx_Auto3627   "Style"
#define en__Auto3627   ""
#define fr__Auto3627   ""
#define it__Auto3627   ""
#define es__Auto3627   ""
#define de__Auto3627   ""
#define nl__Auto3627   ""
#define pt__Auto3627   ""
#define xx__Auto3627   ""
#define en_Auto3628   "Hint"
#define fr_Auto3628   "Infobulle"
#define it_Auto3628   "Hint"
#define es_Auto3628   "Hint"
#define de_Auto3628   "Hint"
#define nl_Auto3628   "Hint"
#define pt_Auto3628   "Hint"
#define xx_Auto3628   "Hint"
#define en__Auto3628   ""
#define fr__Auto3628   ""
#define it__Auto3628   ""
#define es__Auto3628   ""
#define de__Auto3628   ""
#define nl__Auto3628   ""
#define pt__Auto3628   ""
#define xx__Auto3628   ""
#define en_Auto3629   "Alignment"
#define fr_Auto3629   "Alignement"
#define it_Auto3629   "Options"
#define es_Auto3629   "Options"
#define de_Auto3629   "Options"
#define nl_Auto3629   "Options"
#define pt_Auto3629   "Options"
#define xx_Auto3629   "Eile"
#define en__Auto3629   ""
#define fr__Auto3629   ""
#define it__Auto3629   ""
#define es__Auto3629   ""
#define de__Auto3629   ""
#define nl__Auto3629   ""
#define pt__Auto3629   ""
#define xx__Auto3629   ""
#define en_Auto3630   "Name"
#define fr_Auto3630   "Nom"
#define it_Auto3630   "Name"
#define es_Auto3630   "Name"
#define de_Auto3630   "Name"
#define nl_Auto3630   "Name"
#define pt_Auto3630   "Name"
#define xx_Auto3630   "Name"
#define en__Auto3630   ""
#define fr__Auto3630   ""
#define it__Auto3630   ""
#define es__Auto3630   ""
#define de__Auto3630   ""
#define nl__Auto3630   ""
#define pt__Auto3630   ""
#define xx__Auto3630   ""
#define en_Auto3631   "Widget class"
#define fr_Auto3631   "Classe de widget"
#define it_Auto3631   "Widget class"
#define es_Auto3631   "Widget class"
#define de_Auto3631   "Widget class"
#define nl_Auto3631   "Widget class"
#define pt_Auto3631   "Widget class"
#define xx_Auto3631   "Widget class"
#define en__Auto3631   ""
#define fr__Auto3631   ""
#define it__Auto3631   ""
#define es__Auto3631   ""
#define de__Auto3631   ""
#define nl__Auto3631   ""
#define pt__Auto3631   ""
#define xx__Auto3631   ""
#include "vwselect.h"
static int	vfh[16];
private int on_IsSpecial_event(struct vwselect_context * _Context);

/*	------------------------	*/
/*	p o s i t i o n _ a t ()	*/
/*	------------------------	*/
void	vwselect_position_at(struct vwselect_context * _Context,int x,int y){
	_Context->x_WidgetProperties=x;
	_Context->y_WidgetProperties=y;

}

/*	----------------	*/
/*	S e t V a r s ()	*/
/*	----------------	*/
void	vwselect_SetVars(struct vwselect_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	visual_signature("WWWW","WWWW");
	visual_transferin(_Context->buffer_AtX,7,pSpecificWidgetProperties->pAtX);
	visual_transferin(_Context->buffer_AtY,7,pSpecificWidgetProperties->pAtY);
	visual_transferin(_Context->buffer_Width,7,pSpecificWidgetProperties->pWidth);
	visual_transferin(_Context->buffer_Height,7,pSpecificWidgetProperties->pHeight);
	if(!(pSpecificWidgetProperties->pTextFont))
	_Context->value_TextFont=0;
	else _Context->value_TextFont=*((int*)pSpecificWidgetProperties->pTextFont);
	visual_signature("SS","SS");
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
	if(!(pSpecificWidgetProperties->pIsLock))
	_Context->value_IsLock=0;
	else _Context->value_IsLock=*((int*)pSpecificWidgetProperties->pIsLock);
	if(!(pSpecificWidgetProperties->pIsInterface))
	_Context->value_IsInterface=0;
	else _Context->value_IsInterface=*((int*)pSpecificWidgetProperties->pIsInterface);
	if(!(pSpecificWidgetProperties->pIsBold))
	_Context->value_IsBold=0;
	else _Context->value_IsBold=*((int*)pSpecificWidgetProperties->pIsBold);
	if(!(pSpecificWidgetProperties->pIsSpecial))
	_Context->value_IsSpecial=0;
	else _Context->value_IsSpecial=*((int*)pSpecificWidgetProperties->pIsSpecial);
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
void	vwselect_GetVars(struct vwselect_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	visual_signature("WWWW","WWWW");
	visual_transferout(_Context->buffer_AtX,7,pSpecificWidgetProperties->pAtX);
	visual_transferout(_Context->buffer_AtY,7,pSpecificWidgetProperties->pAtY);
	visual_transferout(_Context->buffer_Width,7,pSpecificWidgetProperties->pWidth);
	visual_transferout(_Context->buffer_Height,7,pSpecificWidgetProperties->pHeight);
	if(pSpecificWidgetProperties->pTextFont!=(char*)0)
	*((int*)pSpecificWidgetProperties->pTextFont)=_Context->value_TextFont;
	visual_signature("SS","SS");
	visual_transferout(_Context->buffer_PayLoad,255,pSpecificWidgetProperties->pPayLoad);
	visual_transferout(_Context->buffer_Identity,255,pSpecificWidgetProperties->pIdentity);
	visual_signature("SS","SS");
	visual_transferout(_Context->buffer_StyleSheet,255,pSpecificWidgetProperties->pStyleSheet);
	visual_transferout(_Context->buffer_Hint,255,pSpecificWidgetProperties->pHint);
	if(pSpecificWidgetProperties->pWidgetClass!=(char*)0)
	*((int*)pSpecificWidgetProperties->pWidgetClass)=_Context->value_WidgetClass;
	if(pSpecificWidgetProperties->pAlign!=(char*)0)
	*((int*)pSpecificWidgetProperties->pAlign)=_Context->value_Align;
	if(pSpecificWidgetProperties->pIsLock!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsLock)=_Context->value_IsLock;
	if(pSpecificWidgetProperties->pIsInterface!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsInterface)=_Context->value_IsInterface;
	if(pSpecificWidgetProperties->pIsBold!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsBold)=_Context->value_IsBold;
	if(pSpecificWidgetProperties->pIsSpecial!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsSpecial)=_Context->value_IsSpecial;
	if(pSpecificWidgetProperties->pIswResize!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIswResize)=_Context->value_IswResize;
	if(pSpecificWidgetProperties->pIshResize!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIshResize)=_Context->value_IshResize;
	if(pSpecificWidgetProperties->pInhibit!=(char*)0)
	*((int*)pSpecificWidgetProperties->pInhibit)=_Context->value_IsInhibit;

}

public	int	vwselect_attach()
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

public	int	vwselect_attach_mode(int mode)
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

public	int	vwselect_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	vwselect_create(struct vwselect_context **cptr)
{

	int i;
	struct vwselect_context * _Context=(struct vwselect_context*)0;
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
	if (!(_Context = allocate( sizeof( struct vwselect_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=18;
		_Context->value_IsInhibit=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Identity+i)=' ';
		_Context->value_WidgetClass=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Hint+i)=' ';
		_Context->value_IsSpecial=0;
		_Context->value_IsLock=0;
		_Context->value_IsInterface=0;
		_Context->value_IsBold=0;
		_Context->value_TextFont=0;
		for (i=0; i < 7; i++)  *(_Context->buffer_AtX+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_AtY+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Width+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Height+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_StyleSheet+i)=' ';
		_Context->value_Align=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_PayLoad+i)=' ';
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
	_Context->hint_Identity[0]=en__Identity;
	for (i=0; i < 8; i++)_Context->msg_WidgetClass[i]=" ";
	_Context->hint_WidgetClass[0]=en__WidgetClass;
	_Context->hint_WidgetClass[1]=fr__WidgetClass;
	_Context->hint_Hint[0]=en__Hint;
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
	for (i=0; i < 8; i++)_Context->msg_TextFont[i]=" ";
	_Context->hint_TextFont[0]=en__TextFont;
	_Context->hint_TextFont[1]=fr__TextFont;
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
	_Context->hint_AtX[0]=en__AtX;
	_Context->hint_AtY[0]=en__AtY;
	_Context->hint_Width[0]=en__Width;
	_Context->hint_Height[0]=en__Height;
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
	_Context->hint_StyleSheet[0]=en__StyleSheet;
	_Context->hint_StyleSheet[1]=fr__StyleSheet;
	for (i=0; i < 8; i++)_Context->msg_Align[i]=" ";
	_Context->hint_Align[0]=en__Align;
	_Context->hint_Align[1]=fr__Align;
	_Context->hint_Align[2]=it__Align;
	_Context->hint_Align[3]=es__Align;
	_Context->hint_Align[4]=de__Align;
	_Context->hint_Align[5]=nl__Align;
	_Context->hint_Align[6]=pt__Align;
	_Context->hint_Align[7]=xx__Align;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3626[i]=" ";
	_Context->msg_Auto3626[0]=en_Auto3626;
	_Context->msg_Auto3626[1]=fr_Auto3626;
	_Context->msg_Auto3626[2]=it_Auto3626;
	_Context->msg_Auto3626[3]=es_Auto3626;
	_Context->msg_Auto3626[4]=de_Auto3626;
	_Context->msg_Auto3626[5]=nl_Auto3626;
	_Context->msg_Auto3626[6]=pt_Auto3626;
	_Context->msg_Auto3626[7]=xx_Auto3626;
	_Context->hint_Auto3626[0]=en__Auto3626;
	_Context->hint_Auto3626[1]=fr__Auto3626;
	_Context->hint_Auto3626[2]=it__Auto3626;
	_Context->hint_Auto3626[3]=es__Auto3626;
	_Context->hint_Auto3626[4]=de__Auto3626;
	_Context->hint_Auto3626[5]=nl__Auto3626;
	_Context->hint_Auto3626[6]=pt__Auto3626;
	_Context->hint_Auto3626[7]=xx__Auto3626;
	for (i=0; i < 8; i++)_Context->msg_Auto3627[i]=" ";
	_Context->msg_Auto3627[0]=en_Auto3627;
	_Context->msg_Auto3627[1]=fr_Auto3627;
	_Context->msg_Auto3627[2]=it_Auto3627;
	_Context->msg_Auto3627[3]=es_Auto3627;
	_Context->msg_Auto3627[4]=de_Auto3627;
	_Context->msg_Auto3627[5]=nl_Auto3627;
	_Context->msg_Auto3627[6]=pt_Auto3627;
	_Context->msg_Auto3627[7]=xx_Auto3627;
	_Context->hint_Auto3627[0]=en__Auto3627;
	_Context->hint_Auto3627[1]=fr__Auto3627;
	_Context->hint_Auto3627[2]=it__Auto3627;
	_Context->hint_Auto3627[3]=es__Auto3627;
	_Context->hint_Auto3627[4]=de__Auto3627;
	_Context->hint_Auto3627[5]=nl__Auto3627;
	_Context->hint_Auto3627[6]=pt__Auto3627;
	_Context->hint_Auto3627[7]=xx__Auto3627;
	for (i=0; i < 8; i++)_Context->msg_Auto3628[i]=" ";
	_Context->msg_Auto3628[0]=en_Auto3628;
	_Context->msg_Auto3628[1]=fr_Auto3628;
	_Context->msg_Auto3628[2]=it_Auto3628;
	_Context->msg_Auto3628[3]=es_Auto3628;
	_Context->msg_Auto3628[4]=de_Auto3628;
	_Context->msg_Auto3628[5]=nl_Auto3628;
	_Context->msg_Auto3628[6]=pt_Auto3628;
	_Context->msg_Auto3628[7]=xx_Auto3628;
	_Context->hint_Auto3628[0]=en__Auto3628;
	_Context->hint_Auto3628[1]=fr__Auto3628;
	_Context->hint_Auto3628[2]=it__Auto3628;
	_Context->hint_Auto3628[3]=es__Auto3628;
	_Context->hint_Auto3628[4]=de__Auto3628;
	_Context->hint_Auto3628[5]=nl__Auto3628;
	_Context->hint_Auto3628[6]=pt__Auto3628;
	_Context->hint_Auto3628[7]=xx__Auto3628;
	for (i=0; i < 8; i++)_Context->msg_Auto3629[i]=" ";
	_Context->msg_Auto3629[0]=en_Auto3629;
	_Context->msg_Auto3629[1]=fr_Auto3629;
	_Context->msg_Auto3629[2]=it_Auto3629;
	_Context->msg_Auto3629[3]=es_Auto3629;
	_Context->msg_Auto3629[4]=de_Auto3629;
	_Context->msg_Auto3629[5]=nl_Auto3629;
	_Context->msg_Auto3629[6]=pt_Auto3629;
	_Context->msg_Auto3629[7]=xx_Auto3629;
	_Context->hint_Auto3629[0]=en__Auto3629;
	_Context->hint_Auto3629[1]=fr__Auto3629;
	_Context->hint_Auto3629[2]=it__Auto3629;
	_Context->hint_Auto3629[3]=es__Auto3629;
	_Context->hint_Auto3629[4]=de__Auto3629;
	_Context->hint_Auto3629[5]=nl__Auto3629;
	_Context->hint_Auto3629[6]=pt__Auto3629;
	_Context->hint_Auto3629[7]=xx__Auto3629;
	for (i=0; i < 8; i++)_Context->msg_Auto3630[i]=" ";
	_Context->msg_Auto3630[0]=en_Auto3630;
	_Context->msg_Auto3630[1]=fr_Auto3630;
	_Context->msg_Auto3630[2]=it_Auto3630;
	_Context->msg_Auto3630[3]=es_Auto3630;
	_Context->msg_Auto3630[4]=de_Auto3630;
	_Context->msg_Auto3630[5]=nl_Auto3630;
	_Context->msg_Auto3630[6]=pt_Auto3630;
	_Context->msg_Auto3630[7]=xx_Auto3630;
	_Context->hint_Auto3630[0]=en__Auto3630;
	_Context->hint_Auto3630[1]=fr__Auto3630;
	_Context->hint_Auto3630[2]=it__Auto3630;
	_Context->hint_Auto3630[3]=es__Auto3630;
	_Context->hint_Auto3630[4]=de__Auto3630;
	_Context->hint_Auto3630[5]=nl__Auto3630;
	_Context->hint_Auto3630[6]=pt__Auto3630;
	_Context->hint_Auto3630[7]=xx__Auto3630;
	for (i=0; i < 8; i++)_Context->msg_Auto3631[i]=" ";
	_Context->msg_Auto3631[0]=en_Auto3631;
	_Context->msg_Auto3631[1]=fr_Auto3631;
	_Context->msg_Auto3631[2]=it_Auto3631;
	_Context->msg_Auto3631[3]=es_Auto3631;
	_Context->msg_Auto3631[4]=de_Auto3631;
	_Context->msg_Auto3631[5]=nl_Auto3631;
	_Context->msg_Auto3631[6]=pt_Auto3631;
	_Context->msg_Auto3631[7]=xx_Auto3631;
	_Context->hint_Auto3631[0]=en__Auto3631;
	_Context->hint_Auto3631[1]=fr__Auto3631;
	_Context->hint_Auto3631[2]=it__Auto3631;
	_Context->hint_Auto3631[3]=es__Auto3631;
	_Context->hint_Auto3631[4]=de__Auto3631;
	_Context->hint_Auto3631[5]=nl__Auto3631;
	_Context->hint_Auto3631[6]=pt__Auto3631;
	_Context->hint_Auto3631[7]=xx__Auto3631;
	return(0);
}

public 	int	vwselect_hide(struct vwselect_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;

	return(result);
}

public	int	vwselect_remove(struct vwselect_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}

public	int	vwselect_show(struct vwselect_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,"widget_frame",_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]))) != 0)
) {
		visual_window(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,vfh[2],_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]),0x4);
		}
	visual_text(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+139,210,16,vfh[2],16,0,_Context->msg_Auto3616[_Context->language],strlen(_Context->msg_Auto3616[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+155,210,62,4);
	visual_filzone(_Context->x_WidgetProperties+251,_Context->y_WidgetProperties+254,1,1,27,0);
	visual_text(_Context->x_WidgetProperties+455,_Context->y_WidgetProperties+36,210,16,vfh[2],16,0,_Context->msg_Auto3618[_Context->language],strlen(_Context->msg_Auto3618[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+455,_Context->y_WidgetProperties+52,210,99,4);
	visual_select(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+124,114,46,vfh[2],0,0,parse_selection(_Context->msg_IsInhibit[_Context->language],&_Context->value_IsInhibit),768);
	visual_text(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+224,660,16,vfh[2],16,0,_Context->msg_Auto3619[_Context->language],strlen(_Context->msg_Auto3619[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+240,660,140,4);
	visual_text(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+36,444,16,vfh[2],16,0,_Context->msg_Auto3620[_Context->language],strlen(_Context->msg_Auto3620[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+52,444,167,4);
	visual_frame(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+80,128+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+15+1,_Context->y_WidgetProperties+80+1,128,16,vfh[1],34,0,_Context->buffer_Identity,255,0);
	visual_select(_Context->x_WidgetProperties+222,_Context->y_WidgetProperties+80,120,140,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),768);
	visual_frame(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+132,424+2,64+2,5);
	visual_text(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+132+1,424,64,vfh[1],0,0,_Context->buffer_Hint,255,0);
	_Context->trigger_IsSpecial=visual_trigger_code(_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]));
	visual_check(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+100,190,16,vfh[2],28,28,_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]),_Context->value_IsSpecial|0);
	_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+60,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
	_Context->trigger_IsInterface=visual_trigger_code(_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]));
	visual_check(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+80,180,16,vfh[2],28,28,_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]),_Context->value_IsInterface|0);
	_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+352,182,16,vfh[2],16,28,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
	visual_text(_Context->x_WidgetProperties+465,_Context->y_WidgetProperties+162,14,21,vfh[2],16,0,_Context->msg_Auto3621[_Context->language],strlen(_Context->msg_Auto3621[_Context->language]),2);
	visual_select(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+259,126,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),768);
	visual_text(_Context->x_WidgetProperties+615,_Context->y_WidgetProperties+161,50,21,vfh[2],16,0,_Context->msg_Auto3622[_Context->language],strlen(_Context->msg_Auto3622[_Context->language]),2);
	visual_frame(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+179,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+463+1,_Context->y_WidgetProperties+179+1,35,16,vfh[1],34,0,_Context->buffer_AtX,7,0);
	visual_frame(_Context->x_WidgetProperties+508,_Context->y_WidgetProperties+179,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+508+1,_Context->y_WidgetProperties+179+1,35,16,vfh[1],34,0,_Context->buffer_AtY,7,0);
	visual_frame(_Context->x_WidgetProperties+563,_Context->y_WidgetProperties+179,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+563+1,_Context->y_WidgetProperties+179+1,35,16,vfh[1],34,0,_Context->buffer_Width,7,0);
	visual_frame(_Context->x_WidgetProperties+615,_Context->y_WidgetProperties+179,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+615+1,_Context->y_WidgetProperties+179+1,35,16,vfh[1],34,0,_Context->buffer_Height,7,0);
	visual_text(_Context->x_WidgetProperties+561,_Context->y_WidgetProperties+162,50,21,vfh[2],16,0,_Context->msg_Auto3623[_Context->language],strlen(_Context->msg_Auto3623[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+507,_Context->y_WidgetProperties+162,14,21,vfh[2],16,0,_Context->msg_Auto3624[_Context->language],strlen(_Context->msg_Auto3624[_Context->language]),2);
	visual_frame(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+261,190+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+463+1,_Context->y_WidgetProperties+261+1,190,16,vfh[1],0,0,_Context->buffer_StyleSheet,255,0);
	visual_select(_Context->x_WidgetProperties+225,_Context->y_WidgetProperties+260,120,140,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),768);
	visual_text(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+245,182,16,vfh[2],16,0,_Context->msg_Auto3625[_Context->language],strlen(_Context->msg_Auto3625[_Context->language]),2);
	visual_frame(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+311,641+2,32+2,5);
	visual_text(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+311+1,641,32,vfh[1],34,0,_Context->buffer_PayLoad,255,0);
	_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+352,182,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
	_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+224,_Context->y_WidgetProperties+352,224,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
	visual_text(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+298,168,16,vfh[2],16,0,_Context->msg_Auto3626[_Context->language],strlen(_Context->msg_Auto3626[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+464,_Context->y_WidgetProperties+247,154,16,vfh[2],16,0,_Context->msg_Auto3627[_Context->language],strlen(_Context->msg_Auto3627[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+118,171,16,vfh[2],16,0,_Context->msg_Auto3628[_Context->language],strlen(_Context->msg_Auto3628[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+226,_Context->y_WidgetProperties+247,70,16,vfh[2],16,0,_Context->msg_Auto3629[_Context->language],strlen(_Context->msg_Auto3629[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+66,154,16,vfh[2],16,0,_Context->msg_Auto3630[_Context->language],strlen(_Context->msg_Auto3630[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+221,_Context->y_WidgetProperties+65,135,16,vfh[2],16,0,_Context->msg_Auto3631[_Context->language],strlen(_Context->msg_Auto3631[_Context->language]),2);
	visual_filzone(_Context->x_WidgetProperties+247,_Context->y_WidgetProperties+256,1,1,27,0);
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

private int IsSpecial_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This case sort the list of options.     ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Cette case … cocher permet de trier la liste des options.   ";
			return(visual_online_help(mptr,1));
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

private int PayLoad_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "Options List. ";
			mptr[1]=" The value of this atribut may be referenced from properties select ";
			mptr[2]="by the term :this.PAYLOAD.        ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Liste des option … afficher dans la liste. ";
			mptr[1]=" Vous devrez utiliser le caractŠres | pour s‚parer les options de ";
			mptr[2]="la liste dans la d‚claration. ";
			mptr[3]=" Vous retrouverez par programmation la liste en utilisant la propri‚t‚ ";
			mptr[4]=" this.PAYLOAD du widget.      ";
			return(visual_online_help(mptr,5));
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

private int WidgetPropertiesaction(struct vwselect_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			vwselect_hide(_Context);

		_Context->x_WidgetProperties += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_WidgetProperties < 0) { _Context->x_WidgetProperties=0; }
		_Context->y_WidgetProperties += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_WidgetProperties < 0) { _Context->y_WidgetProperties=0; }
			vwselect_show(_Context);

		visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_IsSpecial_event(struct vwselect_context * _Context) {
	unsigned char*msg_help[8],*msg;
	int i,nblig=1;
	int largeur=0;
	/*case _SELECT_FRAME:*/
	msg_help[0]="Sort the list of options.";
	msg_help[1]="Permet de trier la liste des options.";
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
	aide_en_ligne(_Context->x_WidgetProperties+670-largeur*8-75,_Context->y_WidgetProperties+100+30,nblig,msg_help[visual_national_language(-1)]);
	return(-1);
}


public	int	vwselect_event(
struct vwselect_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsSpecial == mb ) return(5);
		if (_Context->trigger_IsLock == mb ) return(6);
		if (_Context->trigger_IsInterface == mb ) return(7);
		if (_Context->trigger_IsBold == mb ) return(8);
		if (_Context->trigger_IswResize == mb ) return(17);
		if (_Context->trigger_IshResize == mb ) return(18);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_WidgetProperties+468+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+124) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+468+114) ) 
	&&  ( my <= (_Context->y_WidgetProperties+124+16))) {
		return(1); /* IsInhibit */
		}
	if (( mx >= (_Context->x_WidgetProperties+15) ) 
	&&  ( my >= (_Context->y_WidgetProperties+80) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+15+128) ) 
	&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
		return(2); /* Identity */
		}
	if (( mx >= (_Context->x_WidgetProperties+222+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+80) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+222+120) ) 
	&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
		return(3); /* WidgetClass */
		}
	if (( mx >= (_Context->x_WidgetProperties+14) ) 
	&&  ( my >= (_Context->y_WidgetProperties+132) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+14+424) ) 
	&&  ( my <= (_Context->y_WidgetProperties+132+64))) {
		return(4); /* Hint */
		}
	if (( mx >= (_Context->x_WidgetProperties+468) ) 
	&&  ( my >= (_Context->y_WidgetProperties+100) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+468+190) ) 
	&&  ( my <= (_Context->y_WidgetProperties+100+16))) {
		return(5); /* IsSpecial */
		}
	if (( mx >= (_Context->x_WidgetProperties+468) ) 
	&&  ( my >= (_Context->y_WidgetProperties+60) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+468+182) ) 
	&&  ( my <= (_Context->y_WidgetProperties+60+16))) {
		return(6); /* IsLock */
		}
	if (( mx >= (_Context->x_WidgetProperties+468) ) 
	&&  ( my >= (_Context->y_WidgetProperties+80) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+468+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
		return(7); /* IsInterface */
		}
	if (( mx >= (_Context->x_WidgetProperties+460) ) 
	&&  ( my >= (_Context->y_WidgetProperties+352) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+460+182) ) 
	&&  ( my <= (_Context->y_WidgetProperties+352+16))) {
		return(8); /* IsBold */
		}
	if (( mx >= (_Context->x_WidgetProperties+14+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+259) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+14+126) ) 
	&&  ( my <= (_Context->y_WidgetProperties+259+16))) {
		return(9); /* TextFont */
		}
	if (( mx >= (_Context->x_WidgetProperties+463) ) 
	&&  ( my >= (_Context->y_WidgetProperties+179) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+463+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+179+16))) {
		return(10); /* AtX */
		}
	if (( mx >= (_Context->x_WidgetProperties+508) ) 
	&&  ( my >= (_Context->y_WidgetProperties+179) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+508+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+179+16))) {
		return(11); /* AtY */
		}
	if (( mx >= (_Context->x_WidgetProperties+563) ) 
	&&  ( my >= (_Context->y_WidgetProperties+179) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+563+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+179+16))) {
		return(12); /* Width */
		}
	if (( mx >= (_Context->x_WidgetProperties+615) ) 
	&&  ( my >= (_Context->y_WidgetProperties+179) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+615+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+179+16))) {
		return(13); /* Height */
		}
	if (( mx >= (_Context->x_WidgetProperties+463) ) 
	&&  ( my >= (_Context->y_WidgetProperties+261) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+463+190) ) 
	&&  ( my <= (_Context->y_WidgetProperties+261+16))) {
		return(14); /* StyleSheet */
		}
	if (( mx >= (_Context->x_WidgetProperties+225+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+260) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+225+120) ) 
	&&  ( my <= (_Context->y_WidgetProperties+260+16))) {
		return(15); /* Align */
		}
	if (( mx >= (_Context->x_WidgetProperties+13) ) 
	&&  ( my >= (_Context->y_WidgetProperties+311) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+13+641) ) 
	&&  ( my <= (_Context->y_WidgetProperties+311+32))) {
		return(16); /* PayLoad */
		}
	if (( mx >= (_Context->x_WidgetProperties+20) ) 
	&&  ( my >= (_Context->y_WidgetProperties+352) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+20+182) ) 
	&&  ( my <= (_Context->y_WidgetProperties+352+16))) {
		return(17); /* IswResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+224) ) 
	&&  ( my >= (_Context->y_WidgetProperties+352) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+224+224) ) 
	&&  ( my <= (_Context->y_WidgetProperties+352+16))) {
		return(18); /* IshResize */
		}

	return(-1);
}


public	int	vwselect_focus(struct vwselect_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* IsInhibit */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+124,114,46,vfh[2],0,0,parse_selection(_Context->msg_IsInhibit[_Context->language],&_Context->value_IsInhibit),770);
				break;
			case	0x2 :
				/* Identity */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+15+1,_Context->y_WidgetProperties+80+1,128,16,vfh[1],_Context->buffer_Identity,255);
			break;
			case	0x3 :
				/* WidgetClass */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+222,_Context->y_WidgetProperties+80,120,140,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),774);
				if(change_widget_class(&_Context->value_WidgetClass)!=0){
				return(26);
				}
				break;
			case	0x4 :
				/* Hint */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+132+1,424,64,vfh[1],_Context->buffer_Hint,255);
			break;
			case	0x5 :
				/* IsSpecial */
				visual_check(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+100,190,16,vfh[2],28,28,_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]),(_Context->value_IsSpecial |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsSpecial=visual_trigger_code(_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]));
	visual_check(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+100,190,16,vfh[2],28,28,_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]),_Context->value_IsSpecial|0);
				break;
			case	0x6 :
				/* IsLock */
				visual_check(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+60,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),(_Context->value_IsLock |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+60,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
				break;
			case	0x7 :
				/* IsInterface */
				visual_check(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+80,180,16,vfh[2],28,28,_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]),(_Context->value_IsInterface |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsInterface=visual_trigger_code(_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]));
	visual_check(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+80,180,16,vfh[2],28,28,_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]),_Context->value_IsInterface|0);
				break;
			case	0x8 :
				/* IsBold */
				visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+352,182,16,vfh[2],16,28,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),(_Context->value_IsBold |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+352,182,16,vfh[2],16,28,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
				break;
			case	0x9 :
				/* TextFont */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+259,126,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),770);
				break;
			case	0xa :
				/* AtX */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+463+1,_Context->y_WidgetProperties+179+1,35,16,vfh[1],_Context->buffer_AtX,7);
			break;
			case	0xb :
				/* AtY */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+508+1,_Context->y_WidgetProperties+179+1,35,16,vfh[1],_Context->buffer_AtY,7);
			break;
			case	0xc :
				/* Width */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+563+1,_Context->y_WidgetProperties+179+1,35,16,vfh[1],_Context->buffer_Width,7);
			break;
			case	0xd :
				/* Height */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+615+1,_Context->y_WidgetProperties+179+1,35,16,vfh[1],_Context->buffer_Height,7);
			break;
			case	0xe :
				/* StyleSheet */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+463+1,_Context->y_WidgetProperties+261+1,190,16,vfh[1],_Context->buffer_StyleSheet,255);
			break;
			case	0xf :
				/* Align */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+225,_Context->y_WidgetProperties+260,120,140,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),774);
				break;
			case	0x10 :
				/* PayLoad */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+311+1,641,32,vfh[1],_Context->buffer_PayLoad,255);
			break;
			case	0x11 :
				/* IswResize */
				visual_check(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+352,182,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),(_Context->value_IswResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+352,182,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
				break;
			case	0x12 :
				/* IshResize */
				visual_check(_Context->x_WidgetProperties+224,_Context->y_WidgetProperties+352,224,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),(_Context->value_IshResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+224,_Context->y_WidgetProperties+352,224,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			vwselect_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=18;
			vwselect_show(_Context);
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
			if ((retcode=vwselect_event(_Context)) == -1)
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
						if (Hint_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (IsSpecial_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (IsLock_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (IsInterface_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (TextFont_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (AtX_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (AtY_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (Width_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (Height_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (StyleSheet_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (Align_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (PayLoad_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (IswResize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (IshResize_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* IsInhibit */
					continue;
				case	0x2 :
					/* Identity */
					continue;
				case	0x3 :
					/* WidgetClass */
					continue;
				case	0x4 :
					/* Hint */
					continue;
				case	0x5 :
					/* IsSpecial */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsSpecial += 1;
						_Context->value_IsSpecial &= 1;
						}
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_IsSpecial_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* IsLock */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsLock += 1;
						_Context->value_IsLock &= 1;
						}
					continue;
				case	0x7 :
					/* IsInterface */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsInterface += 1;
						_Context->value_IsInterface &= 1;
						}
					continue;
				case	0x8 :
					/* IsBold */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsBold += 1;
						_Context->value_IsBold &= 1;
						}
					continue;
				case	0x9 :
					/* TextFont */
					continue;
				case	0xa :
					/* AtX */
					continue;
				case	0xb :
					/* AtY */
					continue;
				case	0xc :
					/* Width */
					continue;
				case	0xd :
					/* Height */
					continue;
				case	0xe :
					/* StyleSheet */
					continue;
				case	0xf :
					/* Align */
					continue;
				case	0x10 :
					/* PayLoad */
					continue;
				case	0x11 :
					/* IswResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IswResize += 1;
						_Context->value_IswResize &= 1;
						}
					continue;
				case	0x12 :
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
				_Context->focus_item=18;
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

public	int	vwselect()
{
	int	status=0;
	struct vwselect_context * _Context=(struct vwselect_context*) 0;
	status = vwselect_create(&_Context);
	if ( status != 0) return(status);
	status = vwselect_show(_Context);
		enter_modal();
	status = vwselect_focus(_Context);
		leave_modal();
	status = vwselect_hide(_Context);
	status = vwselect_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwselect_c */
