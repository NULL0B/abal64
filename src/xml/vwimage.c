
#ifndef _vwimage_c
#define _vwimage_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vwimage.xml                                              */
/* Target         : vwimage.c                                                */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "sing.h"
#include "singform.h"
#include "singprot.h"
#define en_WidgetProperties   "Image - Properties"
#define fr_WidgetProperties   "Image - Propri‚t‚s"
#define it_WidgetProperties   "Image widget - Properties"
#define es_WidgetProperties   "Image widget - Properties"
#define de_WidgetProperties   "Image widget - Properties"
#define nl_WidgetProperties   "Image widget - Properties"
#define pt_WidgetProperties   "Image widget - Properties"
#define xx_WidgetProperties   "Image widget - Properties"
#define en__WidgetProperties   ""
#define fr__WidgetProperties   ""
#define it__WidgetProperties   ""
#define es__WidgetProperties   ""
#define de__WidgetProperties   ""
#define nl__WidgetProperties   ""
#define pt__WidgetProperties   ""
#define xx__WidgetProperties   ""
#define en_Auto3611   "Position and dimension"
#define fr_Auto3611   "Position et Dimension"
#define it_Auto3611   "Position and dimension"
#define es_Auto3611   "Position and dimension"
#define de_Auto3611   "Position and dimension"
#define nl_Auto3611   "Position and dimension"
#define pt_Auto3611   "Position and dimension"
#define xx_Auto3611   "Position and dimension"
#define en__Auto3611   ""
#define fr__Auto3611   ""
#define it__Auto3611   ""
#define es__Auto3611   ""
#define de__Auto3611   ""
#define nl__Auto3611   ""
#define pt__Auto3611   ""
#define xx__Auto3611   ""
#define en_Auto3613   "Behaviour"
#define fr_Auto3613   "Comportement"
#define it_Auto3613   "Behaviour"
#define es_Auto3613   "Behaviour"
#define de_Auto3613   "Behaviour"
#define nl_Auto3613   "Behaviour"
#define pt_Auto3613   "Behaviour"
#define xx_Auto3613   "Behaviour"
#define en__Auto3613   ""
#define fr__Auto3613   ""
#define it__Auto3613   ""
#define es__Auto3613   ""
#define de__Auto3613   ""
#define nl__Auto3613   ""
#define pt__Auto3613   ""
#define xx__Auto3613   ""
#define en_Auto3614   "Appearence"
#define fr_Auto3614   "Apparence"
#define it_Auto3614   "Appearence"
#define es_Auto3614   "Appearence"
#define de_Auto3614   "Appearence"
#define nl_Auto3614   "Appearence"
#define pt_Auto3614   "Appearence"
#define xx_Auto3614   "Appearence"
#define en__Auto3614   ""
#define fr__Auto3614   ""
#define it__Auto3614   ""
#define es__Auto3614   ""
#define de__Auto3614   ""
#define nl__Auto3614   ""
#define pt__Auto3614   ""
#define xx__Auto3614   ""
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
#define en_Auto3615   "General"
#define fr_Auto3615   "G‚n‚ral"
#define it_Auto3615   "General"
#define es_Auto3615   "General"
#define de_Auto3615   "General"
#define nl_Auto3615   "General"
#define pt_Auto3615   "General"
#define xx_Auto3615   "General"
#define en__Auto3615   ""
#define fr__Auto3615   ""
#define it__Auto3615   ""
#define es__Auto3615   ""
#define de__Auto3615   ""
#define nl__Auto3615   ""
#define pt__Auto3615   ""
#define xx__Auto3615   ""
#define en_Identity   ""
#define en__Identity   ""
#define en__WidgetClass   ""
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
#define en__Align   ""
#define fr__Align   ""
#define it__Align   ""
#define es__Align   ""
#define de__Align   ""
#define nl__Align   ""
#define pt__Align   ""
#define xx__Align   ""
#define en_AtX   ""
#define en__AtX   ""
#define en_AtY   ""
#define en__AtY   ""
#define en_Width   ""
#define en__Width   ""
#define en_Height   ""
#define en__Height   ""
#define en_PayLoad   ""
#define fr_PayLoad   ""
#define en__PayLoad   ""
#define fr__PayLoad   ""
#define en_StyleSheet   ""
#define fr_StyleSheet   ""
#define en__StyleSheet   ""
#define fr__StyleSheet   ""
#define en_IsUnderline   "Quality"
#define fr_IsUnderline   "Qualit‚"
#define it_IsUnderline   "Quality"
#define es_IsUnderline   "Quality"
#define de_IsUnderline   "Quality"
#define nl_IsUnderline   "Quality"
#define pt_IsUnderline   "Quality"
#define xx_IsUnderline   "Quality"
#define en__IsUnderline   ""
#define fr__IsUnderline   ""
#define it__IsUnderline   ""
#define es__IsUnderline   ""
#define de__IsUnderline   ""
#define nl__IsUnderline   ""
#define pt__IsUnderline   ""
#define xx__IsUnderline   ""
#define en_IsShadow   "Sprite"
#define fr_IsShadow   "Transparent"
#define it_IsShadow   "Sprite"
#define es_IsShadow   "Sprite"
#define de_IsShadow   "Sprite"
#define nl_IsShadow   "Sprite"
#define pt_IsShadow   "Sprite"
#define xx_IsShadow   "Sprite"
#define en__IsShadow   ""
#define fr__IsShadow   ""
#define it__IsShadow   ""
#define es__IsShadow   ""
#define de__IsShadow   ""
#define nl__IsShadow   ""
#define pt__IsShadow   ""
#define xx__IsShadow   ""
#define en_Auto3616   "X"
#define fr_Auto3616   "X"
#define it_Auto3616   "X"
#define es_Auto3616   "X"
#define de_Auto3616   "X"
#define nl_Auto3616   "X"
#define pt_Auto3616   "X"
#define xx_Auto3616   "X"
#define en__Auto3616   ""
#define fr__Auto3616   ""
#define it__Auto3616   ""
#define es__Auto3616   ""
#define de__Auto3616   ""
#define nl__Auto3616   ""
#define pt__Auto3616   ""
#define xx__Auto3616   ""
#define en_Auto3617   "Height"
#define fr_Auto3617   "Hauteur"
#define it_Auto3617   "Height"
#define es_Auto3617   "Height"
#define de_Auto3617   "Height"
#define nl_Auto3617   "Height"
#define pt_Auto3617   "Height"
#define xx_Auto3617   "Height"
#define en__Auto3617   ""
#define fr__Auto3617   ""
#define it__Auto3617   ""
#define es__Auto3617   ""
#define de__Auto3617   ""
#define nl__Auto3617   ""
#define pt__Auto3617   ""
#define xx__Auto3617   ""
#define en_Auto3618   "Width"
#define fr_Auto3618   "Largeur"
#define it_Auto3618   "Width"
#define es_Auto3618   "Width"
#define de_Auto3618   "Width"
#define nl_Auto3618   "Width"
#define pt_Auto3618   "Width"
#define xx_Auto3618   "Width"
#define en__Auto3618   ""
#define fr__Auto3618   ""
#define it__Auto3618   ""
#define es__Auto3618   ""
#define de__Auto3618   ""
#define nl__Auto3618   ""
#define pt__Auto3618   ""
#define xx__Auto3618   ""
#define en_Auto3619   "Y"
#define fr_Auto3619   "Y"
#define it_Auto3619   "Y"
#define es_Auto3619   "Y"
#define de_Auto3619   "Y"
#define nl_Auto3619   "Y"
#define pt_Auto3619   "Y"
#define xx_Auto3619   "Y"
#define en__Auto3619   ""
#define fr__Auto3619   ""
#define it__Auto3619   ""
#define es__Auto3619   ""
#define de__Auto3619   ""
#define nl__Auto3619   ""
#define pt__Auto3619   ""
#define xx__Auto3619   ""
#define en_Auto3620   "Image"
#define fr_Auto3620   "Image"
#define it_Auto3620   "Image"
#define es_Auto3620   "Image"
#define de_Auto3620   "Image"
#define nl_Auto3620   "Image"
#define pt_Auto3620   "Image"
#define xx_Auto3620   "Image"
#define en__Auto3620   ""
#define fr__Auto3620   ""
#define it__Auto3620   ""
#define es__Auto3620   ""
#define de__Auto3620   ""
#define nl__Auto3620   ""
#define pt__Auto3620   ""
#define xx__Auto3620   ""
#define en_Auto3621   "Explicit style"
#define fr_Auto3621   "Style explicite"
#define it_Auto3621   "Explicit style"
#define es_Auto3621   "Explicit style"
#define de_Auto3621   "Explicit style"
#define nl_Auto3621   "Explicit style"
#define pt_Auto3621   "Explicit style"
#define xx_Auto3621   "Explicit style"
#define en__Auto3621   ""
#define fr__Auto3621   ""
#define it__Auto3621   ""
#define es__Auto3621   ""
#define de__Auto3621   ""
#define nl__Auto3621   ""
#define pt__Auto3621   ""
#define xx__Auto3621   ""
#define en_Auto3622   "Hint"
#define fr_Auto3622   "Infobulle"
#define it_Auto3622   "Hint"
#define es_Auto3622   "Hint"
#define de_Auto3622   "Hint"
#define nl_Auto3622   "Hint"
#define pt_Auto3622   "Hint"
#define xx_Auto3622   "Hint"
#define en__Auto3622   ""
#define fr__Auto3622   ""
#define it__Auto3622   ""
#define es__Auto3622   ""
#define de__Auto3622   ""
#define nl__Auto3622   ""
#define pt__Auto3622   ""
#define xx__Auto3622   ""
#define en_Auto3623   "Alignment"
#define fr_Auto3623   "Alignement"
#define it_Auto3623   "Alignment"
#define es_Auto3623   "Alignment"
#define de_Auto3623   "Alignment"
#define nl_Auto3623   "Alignment"
#define pt_Auto3623   "Alignment"
#define xx_Auto3623   "Alignment"
#define en__Auto3623   ""
#define fr__Auto3623   ""
#define it__Auto3623   ""
#define es__Auto3623   ""
#define de__Auto3623   ""
#define nl__Auto3623   ""
#define pt__Auto3623   ""
#define xx__Auto3623   ""
#define en_Auto3624   "Name"
#define fr_Auto3624   "Nom"
#define it_Auto3624   "Name"
#define es_Auto3624   "Name"
#define de_Auto3624   "Name"
#define nl_Auto3624   "Name"
#define pt_Auto3624   "Name"
#define xx_Auto3624   "Name"
#define en__Auto3624   ""
#define fr__Auto3624   ""
#define it__Auto3624   ""
#define es__Auto3624   ""
#define de__Auto3624   ""
#define nl__Auto3624   ""
#define pt__Auto3624   ""
#define xx__Auto3624   ""
#define en_Auto3625   "Widget class"
#define fr_Auto3625   "Classe de widget"
#define it_Auto3625   "Widget class"
#define es_Auto3625   "Widget class"
#define de_Auto3625   "Widget class"
#define nl_Auto3625   "Widget class"
#define pt_Auto3625   "Widget class"
#define xx_Auto3625   "Widget class"
#define en__Auto3625   ""
#define fr__Auto3625   ""
#define it__Auto3625   ""
#define es__Auto3625   ""
#define de__Auto3625   ""
#define nl__Auto3625   ""
#define pt__Auto3625   ""
#define xx__Auto3625   ""
#define en_PayLoadSelect   "*"
#define fr_PayLoadSelect   "*"
#define it_PayLoadSelect   "*"
#define es_PayLoadSelect   "*"
#define de_PayLoadSelect   "*"
#define nl_PayLoadSelect   "*"
#define pt_PayLoadSelect   "*"
#define xx_PayLoadSelect   "*"
#define en__PayLoadSelect   ""
#include "vwimage.h"
static int	vfh[16];
private int on_PayLoadSelect_event(struct vwimage_context * _Context);

/*	------------------------	*/
/*	p o s i t i o n _ a t ()	*/
/*	------------------------	*/
void	vwimage_position_at(struct vwimage_context * _Context,int x,int y){
	_Context->x_WidgetProperties=x;
	_Context->y_WidgetProperties=y;

}

/*	----------------	*/
/*	S e t V a r s ()	*/
/*	----------------	*/
void	vwimage_SetVars(struct vwimage_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	visual_signature("WWWW","WWWW");
	visual_transferin(_Context->buffer_AtX,7,pSpecificWidgetProperties->pAtX);
	visual_transferin(_Context->buffer_AtY,7,pSpecificWidgetProperties->pAtY);
	visual_transferin(_Context->buffer_Width,7,pSpecificWidgetProperties->pWidth);
	visual_transferin(_Context->buffer_Height,7,pSpecificWidgetProperties->pHeight);
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
void	vwimage_GetVars(struct vwimage_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	visual_signature("WWWW","WWWW");
	visual_transferout(_Context->buffer_AtX,7,pSpecificWidgetProperties->pAtX);
	visual_transferout(_Context->buffer_AtY,7,pSpecificWidgetProperties->pAtY);
	visual_transferout(_Context->buffer_Width,7,pSpecificWidgetProperties->pWidth);
	visual_transferout(_Context->buffer_Height,7,pSpecificWidgetProperties->pHeight);
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

public	int	vwimage_attach()
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

public	int	vwimage_attach_mode(int mode)
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

public	int	vwimage_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	vwimage_create(struct vwimage_context **cptr)
{

	int i;
	struct vwimage_context * _Context=(struct vwimage_context*)0;
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
	if (!(_Context = allocate( sizeof( struct vwimage_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=17;
		_Context->value_IswResize=0;
		_Context->value_IshResize=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Identity+i)=' ';
		_Context->value_WidgetClass=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Hint+i)=' ';
		_Context->value_IsLock=0;
		_Context->value_Align=0;
		for (i=0; i < 7; i++)  *(_Context->buffer_AtX+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_AtY+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Width+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Height+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_PayLoad+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_StyleSheet+i)=' ';
		_Context->value_IsUnderline=0;
		_Context->value_IsShadow=0;
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
	_Context->hint_Identity[0]=en__Identity;
	for (i=0; i < 8; i++)_Context->msg_WidgetClass[i]=" ";
	_Context->hint_WidgetClass[0]=en__WidgetClass;
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
	for (i=0; i < 8; i++)_Context->msg_Align[i]=" ";
	_Context->hint_Align[0]=en__Align;
	_Context->hint_Align[1]=fr__Align;
	_Context->hint_Align[2]=it__Align;
	_Context->hint_Align[3]=es__Align;
	_Context->hint_Align[4]=de__Align;
	_Context->hint_Align[5]=nl__Align;
	_Context->hint_Align[6]=pt__Align;
	_Context->hint_Align[7]=xx__Align;
	_Context->hint_AtX[0]=en__AtX;
	_Context->hint_AtY[0]=en__AtY;
	_Context->hint_Width[0]=en__Width;
	_Context->hint_Height[0]=en__Height;
	_Context->hint_PayLoad[0]=en__PayLoad;
	_Context->hint_PayLoad[1]=fr__PayLoad;
	_Context->hint_StyleSheet[0]=en__StyleSheet;
	_Context->hint_StyleSheet[1]=fr__StyleSheet;
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
	_Context->p_PayLoadSelect=visual_buffer(_Context->x_WidgetProperties+632,_Context->y_WidgetProperties+309,20+2,18+2);
	return(0);
}

public 	int	vwimage_hide(struct vwimage_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_PayLoadSelect != (void *) 0)
	&& (_Context->s_PayLoadSelect != 0)) {
		(void)visual_buffer_put(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+632,_Context->y_WidgetProperties+309);
		_Context->s_PayLoadSelect=0;
		}

	return(result);
}

public	int	vwimage_remove(struct vwimage_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->p_PayLoadSelect != (void *) 0)
		_Context->p_PayLoadSelect = visual_drop(_Context->p_PayLoadSelect);
	_Context=liberate(_Context);

	return(result);
}

public	int	vwimage_show(struct vwimage_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,"widget_frame",_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]))) != 0)
) {
		visual_window(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,vfh[2],_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]),0x4);
		}
	visual_text(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+110,210,16,vfh[2],16,0,_Context->msg_Auto3611[_Context->language],strlen(_Context->msg_Auto3611[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+126,210,62,4);
	visual_filzone(_Context->x_WidgetProperties+39,_Context->y_WidgetProperties+239,1,1,27,0);
	visual_text(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+26,210,16,vfh[2],16,0,_Context->msg_Auto3613[_Context->language],strlen(_Context->msg_Auto3613[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+42,210,62,4);
	visual_text(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+198,658,16,vfh[2],16,0,_Context->msg_Auto3614[_Context->language],strlen(_Context->msg_Auto3614[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+214,658,164,4);
	_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+350,165,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
	_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+280,_Context->y_WidgetProperties+352,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
	visual_text(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+26,442,16,vfh[2],16,0,_Context->msg_Auto3615[_Context->language],strlen(_Context->msg_Auto3615[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+42,442,146,4);
	visual_frame(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+62,128+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+12+1,_Context->y_WidgetProperties+62+1,128,16,vfh[1],34,0,_Context->buffer_Identity,255,0);
	visual_select(_Context->x_WidgetProperties+223,_Context->y_WidgetProperties+64,120,140,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),768);
	visual_frame(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+102,424+2,64+2,5);
	visual_text(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+102+1,424,64,vfh[1],0,0,_Context->buffer_Hint,255,0);
	_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+464,_Context->y_WidgetProperties+64,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
	visual_select(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+246,145,96,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),768);
	visual_frame(_Context->x_WidgetProperties+462,_Context->y_WidgetProperties+150,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+462+1,_Context->y_WidgetProperties+150+1,35,16,vfh[1],34,0,_Context->buffer_AtX,7,0);
	visual_frame(_Context->x_WidgetProperties+505,_Context->y_WidgetProperties+150,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+505+1,_Context->y_WidgetProperties+150+1,35,16,vfh[1],34,0,_Context->buffer_AtY,7,0);
	visual_frame(_Context->x_WidgetProperties+566,_Context->y_WidgetProperties+150,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+566+1,_Context->y_WidgetProperties+150+1,35,16,vfh[1],34,0,_Context->buffer_Width,7,0);
	visual_frame(_Context->x_WidgetProperties+612,_Context->y_WidgetProperties+151,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+612+1,_Context->y_WidgetProperties+151+1,35,16,vfh[1],34,0,_Context->buffer_Height,7,0);
	visual_frame(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+309,616+2,32+2,5);
	visual_text(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+309+1,616,32,vfh[1],34,0,_Context->buffer_PayLoad,255,0);
	visual_frame(_Context->x_WidgetProperties+219,_Context->y_WidgetProperties+246,216+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+219+1,_Context->y_WidgetProperties+246+1,216,16,vfh[1],0,0,_Context->buffer_StyleSheet,255,0);
	_Context->trigger_IsUnderline=visual_trigger_code(_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]));
	visual_check(_Context->x_WidgetProperties+464,_Context->y_WidgetProperties+246,180,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),_Context->value_IsUnderline|0);
	_Context->trigger_IsShadow=visual_trigger_code(_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]));
	visual_check(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+273,180,16,vfh[2],28,28,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),_Context->value_IsShadow|0);
	visual_text(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+134,14,21,vfh[2],16,0,_Context->msg_Auto3616[_Context->language],strlen(_Context->msg_Auto3616[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+612,_Context->y_WidgetProperties+134,50,21,vfh[2],16,0,_Context->msg_Auto3617[_Context->language],strlen(_Context->msg_Auto3617[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+564,_Context->y_WidgetProperties+134,50,21,vfh[2],16,0,_Context->msg_Auto3618[_Context->language],strlen(_Context->msg_Auto3618[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+504,_Context->y_WidgetProperties+134,14,21,vfh[2],16,0,_Context->msg_Auto3619[_Context->language],strlen(_Context->msg_Auto3619[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+295,322,16,vfh[2],16,0,_Context->msg_Auto3620[_Context->language],strlen(_Context->msg_Auto3620[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+220,_Context->y_WidgetProperties+232,182,16,vfh[2],16,0,_Context->msg_Auto3621[_Context->language],strlen(_Context->msg_Auto3621[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+88,180,16,vfh[2],16,0,_Context->msg_Auto3622[_Context->language],strlen(_Context->msg_Auto3622[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+232,180,16,vfh[2],16,0,_Context->msg_Auto3623[_Context->language],strlen(_Context->msg_Auto3623[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+48,154,16,vfh[2],16,0,_Context->msg_Auto3624[_Context->language],strlen(_Context->msg_Auto3624[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+222,_Context->y_WidgetProperties+50,135,16,vfh[2],16,0,_Context->msg_Auto3625[_Context->language],strlen(_Context->msg_Auto3625[_Context->language]),2);
	if ((_Context->p_PayLoadSelect != (void *) 0)
	&& (_Context->s_PayLoadSelect == 0)) {
		(void)visual_buffer_get(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+632,_Context->y_WidgetProperties+309);
		_Context->s_PayLoadSelect=1;
		}
	_Context->trigger_PayLoadSelect=visual_trigger_code(_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+632,_Context->y_WidgetProperties+309,20,18,vfh[8],28,28,_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]),0);
	visual_filzone(_Context->x_WidgetProperties+35,_Context->y_WidgetProperties+241,1,1,27,0);
	visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400);

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

private int Align_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[13];
			mptr[0] = "List of the alignment options for the image. ";
			mptr[1]="   ";
			mptr[2]=" - None    : no alignment is applied to the image.  ";
			mptr[3]=" - Right   : The image will be right aligned in the widget zone.  ";
			mptr[4]=" - Left    : The image will be left aligned in the widget zone.  ";
			mptr[5]=" - Center  : The image will be centered within the widget zone.  ";
			mptr[6]=" - Tile    : This option causes the images, smaller than their widget ";
			mptr[7]="zone, to be tiled or repeated, to fill the entire zone.  ";
			mptr[8]=" - Makefit : causes images to be stretched or squashed to fit the entire ";
			mptr[9]="widget zone.  ";
			mptr[10]=" - Bestfit : causes images to stretched and squashed respecting the image ";
			mptr[11]="proportions. The result may stil be smaller than the widget zone in ";
			mptr[12]="which case it will be centered.          ";
			return(visual_online_help(mptr,13));
			}
			break;
		case 1 : 
			{
			char * mptr[16];
			mptr[0] = "Liste des possibilit‚s mises … disposition pour aligner une image. ";
			mptr[1]=" Pour une image, choisissez parmis les alignements suivants: ";
			mptr[2]="   ";
			mptr[3]=" - None    : aucun alignement ne sera fait sur l'image.  ";
			mptr[4]=" - Right   : l'image sera align‚e sur la droite des coordonn‚s l'objet. ";
			mptr[5]=" ";
			mptr[6]=" - Left    : l'image sera align‚e sur la gauche des coordonn‚s l'objet. ";
			mptr[7]=" ";
			mptr[8]=" - Center  : l'image sera centr‚e dans la zone d‚finie.  ";
			mptr[9]=" - Tile    : Cette option permet pour les images plus petites que l'objet ";
			mptr[10]="d'ˆtres dupliqu‚es et/ou coup‚es pour occuper tout l'espace.  ";
			mptr[11]=" - Makefit : avec cette option, l'image sera r‚duite ou agrandie pour ";
			mptr[12]="occuper tout l'espace en une seule fois.  ";
			mptr[13]=" - Bestfit : Comme Makefit, l'image va ˆtre r‚duite ou agrandie mais ";
			mptr[14]="ses proportions seront conserv‚es. Si l'image n'occupe pas tout l'espace ";
			mptr[15]="en hauteur ou largeur, elle sera centr‚e.               ";
			return(visual_online_help(mptr,16));
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

private int PayLoad_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "The filename of the image. ";
			mptr[1]=" Use the button x to scan the disk. ";
			mptr[2]=" The value of this atribut may be referenced from method text by the ";
			mptr[3]="term : this.PAYLOAD.         ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[4];
			mptr[0] = "Le nom du fichier image … afficher. ";
			mptr[1]=" Utilisez le bouton x pour parcourir le disque. ";
			mptr[2]=" Vous retrouverez par programmation le texte saisie en utilisant la ";
			mptr[3]="propri‚t‚ this.PAYLOAD du widget.   ";
			return(visual_online_help(mptr,4));
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

private int IsUnderline_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "Draw the image in high quality.    ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "L'image affich‚e en haute r‚solution.   ";
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
			mptr[0] = "Draw the image without background color.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "L'image affich‚e avec un fond transparent.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}
private int on_PayLoadSelect_event(struct vwimage_context * _Context) {
	/*case _IMAGE_FRAME*/
		vwimage_hide(_Context);
;
	use_file_selector(_Context->buffer_PayLoad,WIDGET_FILE_GIF);
		vwimage_show(_Context);
;
	return(-1);
}


public	int	vwimage_event(
struct vwimage_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IswResize == mb ) return(2);
		if (_Context->trigger_IshResize == mb ) return(3);
		if (_Context->trigger_IsLock == mb ) return(7);
		if (_Context->trigger_IsUnderline == mb ) return(15);
		if (_Context->trigger_IsShadow == mb ) return(16);
		if (_Context->trigger_PayLoadSelect == mb ) return(17);
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
		vwimage_show(_Context);
		return(-1);	/* WidgetProperties */

		}
		}
	if (( mx >= (_Context->x_WidgetProperties+15) ) 
	&&  ( my >= (_Context->y_WidgetProperties+350) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+15+165) ) 
	&&  ( my <= (_Context->y_WidgetProperties+350+16))) {
		return(2); /* IswResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+280) ) 
	&&  ( my >= (_Context->y_WidgetProperties+352) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+280+165) ) 
	&&  ( my <= (_Context->y_WidgetProperties+352+16))) {
		return(3); /* IshResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+12) ) 
	&&  ( my >= (_Context->y_WidgetProperties+62) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+12+128) ) 
	&&  ( my <= (_Context->y_WidgetProperties+62+16))) {
		return(4); /* Identity */
		}
	if (( mx >= (_Context->x_WidgetProperties+223+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+64) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+223+120) ) 
	&&  ( my <= (_Context->y_WidgetProperties+64+16))) {
		return(5); /* WidgetClass */
		}
	if (( mx >= (_Context->x_WidgetProperties+13) ) 
	&&  ( my >= (_Context->y_WidgetProperties+102) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+13+424) ) 
	&&  ( my <= (_Context->y_WidgetProperties+102+64))) {
		return(6); /* Hint */
		}
	if (( mx >= (_Context->x_WidgetProperties+464) ) 
	&&  ( my >= (_Context->y_WidgetProperties+64) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+464+182) ) 
	&&  ( my <= (_Context->y_WidgetProperties+64+16))) {
		return(7); /* IsLock */
		}
	if (( mx >= (_Context->x_WidgetProperties+14+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+246) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+14+145) ) 
	&&  ( my <= (_Context->y_WidgetProperties+246+16))) {
		return(8); /* Align */
		}
	if (( mx >= (_Context->x_WidgetProperties+462) ) 
	&&  ( my >= (_Context->y_WidgetProperties+150) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+462+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+150+16))) {
		return(9); /* AtX */
		}
	if (( mx >= (_Context->x_WidgetProperties+505) ) 
	&&  ( my >= (_Context->y_WidgetProperties+150) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+505+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+150+16))) {
		return(10); /* AtY */
		}
	if (( mx >= (_Context->x_WidgetProperties+566) ) 
	&&  ( my >= (_Context->y_WidgetProperties+150) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+566+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+150+16))) {
		return(11); /* Width */
		}
	if (( mx >= (_Context->x_WidgetProperties+612) ) 
	&&  ( my >= (_Context->y_WidgetProperties+151) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+612+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+151+16))) {
		return(12); /* Height */
		}
	if (( mx >= (_Context->x_WidgetProperties+14) ) 
	&&  ( my >= (_Context->y_WidgetProperties+309) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+14+616) ) 
	&&  ( my <= (_Context->y_WidgetProperties+309+32))) {
		return(13); /* PayLoad */
		}
	if (( mx >= (_Context->x_WidgetProperties+219) ) 
	&&  ( my >= (_Context->y_WidgetProperties+246) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+219+216) ) 
	&&  ( my <= (_Context->y_WidgetProperties+246+16))) {
		return(14); /* StyleSheet */
		}
	if (( mx >= (_Context->x_WidgetProperties+464) ) 
	&&  ( my >= (_Context->y_WidgetProperties+246) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+464+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+246+16))) {
		return(15); /* IsUnderline */
		}
	if (( mx >= (_Context->x_WidgetProperties+463) ) 
	&&  ( my >= (_Context->y_WidgetProperties+273) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+463+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+273+16))) {
		return(16); /* IsShadow */
		}
	if (( mx >= (_Context->x_WidgetProperties+632) ) 
	&&  ( my >= (_Context->y_WidgetProperties+309) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+632+20) ) 
	&&  ( my <= (_Context->y_WidgetProperties+309+18))) {
		return(17); /* PayLoadSelect */
		}

	return(-1);
}


public	int	vwimage_focus(struct vwimage_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* IswResize */
				visual_check(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+350,165,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),(_Context->value_IswResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+350,165,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
				break;
			case	0x3 :
				/* IshResize */
				visual_check(_Context->x_WidgetProperties+280,_Context->y_WidgetProperties+352,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),(_Context->value_IshResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+280,_Context->y_WidgetProperties+352,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
				break;
			case	0x4 :
				/* Identity */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+12+1,_Context->y_WidgetProperties+62+1,128,16,vfh[1],_Context->buffer_Identity,255);
			break;
			case	0x5 :
				/* WidgetClass */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+223,_Context->y_WidgetProperties+64,120,140,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),774);
				if(change_widget_class(&_Context->value_WidgetClass)!=0){
				return(26);
				}
				break;
			case	0x6 :
				/* Hint */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+102+1,424,64,vfh[1],_Context->buffer_Hint,255);
			break;
			case	0x7 :
				/* IsLock */
				visual_check(_Context->x_WidgetProperties+464,_Context->y_WidgetProperties+64,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),(_Context->value_IsLock |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+464,_Context->y_WidgetProperties+64,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
				break;
			case	0x8 :
				/* Align */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+246,145,96,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),774);
				break;
			case	0x9 :
				/* AtX */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+462+1,_Context->y_WidgetProperties+150+1,35,16,vfh[1],_Context->buffer_AtX,7);
			break;
			case	0xa :
				/* AtY */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+505+1,_Context->y_WidgetProperties+150+1,35,16,vfh[1],_Context->buffer_AtY,7);
			break;
			case	0xb :
				/* Width */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+566+1,_Context->y_WidgetProperties+150+1,35,16,vfh[1],_Context->buffer_Width,7);
			break;
			case	0xc :
				/* Height */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+612+1,_Context->y_WidgetProperties+151+1,35,16,vfh[1],_Context->buffer_Height,7);
			break;
			case	0xd :
				/* PayLoad */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+309+1,616,32,vfh[1],_Context->buffer_PayLoad,255);
			break;
			case	0xe :
				/* StyleSheet */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+219+1,_Context->y_WidgetProperties+246+1,216,16,vfh[1],_Context->buffer_StyleSheet,255);
			break;
			case	0xf :
				/* IsUnderline */
				visual_check(_Context->x_WidgetProperties+464,_Context->y_WidgetProperties+246,180,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),(_Context->value_IsUnderline |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsUnderline=visual_trigger_code(_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]));
	visual_check(_Context->x_WidgetProperties+464,_Context->y_WidgetProperties+246,180,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),_Context->value_IsUnderline|0);
				break;
			case	0x10 :
				/* IsShadow */
				visual_check(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+273,180,16,vfh[2],28,28,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),(_Context->value_IsShadow |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsShadow=visual_trigger_code(_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]));
	visual_check(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+273,180,16,vfh[2],28,28,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),_Context->value_IsShadow|0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			vwimage_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=17;
			vwimage_show(_Context);
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
			if ((retcode=vwimage_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (IswResize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (IshResize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Identity_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (WidgetClass_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (Hint_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (IsLock_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (Align_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (AtX_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (AtY_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Width_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (Height_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (PayLoad_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (StyleSheet_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (IsUnderline_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (IsShadow_help(_Context) != 0) { continue; }
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
					/* IswResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IswResize += 1;
						_Context->value_IswResize &= 1;
						}
					continue;
				case	0x3 :
					/* IshResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IshResize += 1;
						_Context->value_IshResize &= 1;
						}
					continue;
				case	0x4 :
					/* Identity */
					continue;
				case	0x5 :
					/* WidgetClass */
					continue;
				case	0x6 :
					/* Hint */
					continue;
				case	0x7 :
					/* IsLock */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsLock += 1;
						_Context->value_IsLock &= 1;
						}
					continue;
				case	0x8 :
					/* Align */
					continue;
				case	0x9 :
					/* AtX */
					continue;
				case	0xa :
					/* AtY */
					continue;
				case	0xb :
					/* Width */
					continue;
				case	0xc :
					/* Height */
					continue;
				case	0xd :
					/* PayLoad */
					continue;
				case	0xe :
					/* StyleSheet */
					continue;
				case	0xf :
					/* IsUnderline */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsUnderline += 1;
						_Context->value_IsUnderline &= 1;
						}
					continue;
				case	0x10 :
					/* IsShadow */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsShadow += 1;
						_Context->value_IsShadow &= 1;
						}
					continue;
				case	0x11 :
					/* PayLoadSelect */
					if (visual_event(1) & _MIMO_DOWN) {
						if ((_Context->p_PayLoadSelect != (void *) 0)
						&& (_Context->s_PayLoadSelect == 0)) {
							(void)visual_buffer_get(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+632,_Context->y_WidgetProperties+309);
							_Context->s_PayLoadSelect=1;
							}
						_Context->trigger_PayLoadSelect=visual_trigger_code(_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]));
						visual_button(_Context->x_WidgetProperties+632,_Context->y_WidgetProperties+309,20,18,vfh[8],28,28,_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						if ((_Context->p_PayLoadSelect != (void *) 0)
						&& (_Context->s_PayLoadSelect == 0)) {
							(void)visual_buffer_get(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+632,_Context->y_WidgetProperties+309);
							_Context->s_PayLoadSelect=1;
							}
						_Context->trigger_PayLoadSelect=visual_trigger_code(_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+632,_Context->y_WidgetProperties+309,20,18,vfh[8],28,28,_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_PayLoadSelect_event(_Context)) != -1) break;

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
				_Context->focus_item=17;
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

public	int	vwimage()
{
	int	status=0;
	struct vwimage_context * _Context=(struct vwimage_context*) 0;
	status = vwimage_create(&_Context);
	if ( status != 0) return(status);
	status = vwimage_show(_Context);
		enter_modal();
	status = vwimage_focus(_Context);
		leave_modal();
	status = vwimage_hide(_Context);
	status = vwimage_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwimage_c */
