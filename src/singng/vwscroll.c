
#ifndef _vwscroll_c
#define _vwscroll_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vwscroll.xml                                             */
/* Target         : vwscroll.c                                               */
/* Identification : 0.0-1177511938-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "sing.h"
#include "singform.h"
#include "singprot.h"
#define en_WidgetProperties   "Scroll - Properties"
#define fr_WidgetProperties   "Scroll - Propri�t�s"
#define it_WidgetProperties   "Scroll widget - Properties"
#define es_WidgetProperties   "Scroll widget - Properties"
#define de_WidgetProperties   "Scroll widget - Properties"
#define nl_WidgetProperties   "Scroll widget - Properties"
#define pt_WidgetProperties   "Scroll widget - Properties"
#define xx_WidgetProperties   "Scroll widget - Properties"
#define en__WidgetProperties   ""
#define fr__WidgetProperties   ""
#define it__WidgetProperties   ""
#define es__WidgetProperties   ""
#define de__WidgetProperties   ""
#define nl__WidgetProperties   ""
#define pt__WidgetProperties   ""
#define xx__WidgetProperties   ""
#define en_Auto2786   "Position and Dimension"
#define fr_Auto2786   "Position et Dimension"
#define it_Auto2786   "Position and Dimension"
#define es_Auto2786   "Position and Dimension"
#define de_Auto2786   "Position and Dimension"
#define nl_Auto2786   "Position and Dimension"
#define pt_Auto2786   "Position and Dimension"
#define xx_Auto2786   "Position and Dimension"
#define en__Auto2786   ""
#define fr__Auto2786   ""
#define it__Auto2786   ""
#define es__Auto2786   ""
#define de__Auto2786   ""
#define nl__Auto2786   ""
#define pt__Auto2786   ""
#define xx__Auto2786   ""
#define en_Auto2788   "Behaviour"
#define fr_Auto2788   "Comportement"
#define it_Auto2788   "Behaviour"
#define es_Auto2788   "Behaviour"
#define de_Auto2788   "Behaviour"
#define nl_Auto2788   "Behaviour"
#define pt_Auto2788   "Behaviour"
#define xx_Auto2788   "Behaviour"
#define en__Auto2788   ""
#define fr__Auto2788   ""
#define it__Auto2788   ""
#define es__Auto2788   ""
#define de__Auto2788   ""
#define nl__Auto2788   ""
#define pt__Auto2788   ""
#define xx__Auto2788   ""
#define en_Auto2789   "Appearence"
#define fr_Auto2789   "Apparence"
#define it_Auto2789   "Appearence"
#define es_Auto2789   "Appearence"
#define de_Auto2789   "Appearence"
#define nl_Auto2789   "Appearence"
#define pt_Auto2789   "Appearence"
#define xx_Auto2789   "Appearence"
#define en__Auto2789   ""
#define fr__Auto2789   ""
#define it__Auto2789   ""
#define es__Auto2789   ""
#define de__Auto2789   ""
#define nl__Auto2789   ""
#define pt__Auto2789   ""
#define xx__Auto2789   ""
#define en_Auto2790   "General"
#define fr_Auto2790   "G�n�ral"
#define it_Auto2790   "General"
#define es_Auto2790   "General"
#define de_Auto2790   "General"
#define nl_Auto2790   "General"
#define pt_Auto2790   "General"
#define xx_Auto2790   "General"
#define en__Auto2790   ""
#define fr__Auto2790   ""
#define it__Auto2790   ""
#define es__Auto2790   ""
#define de__Auto2790   ""
#define nl__Auto2790   ""
#define pt__Auto2790   ""
#define xx__Auto2790   ""
#define fr_Identity   ""
#define fr__Identity   ""
#define en__WidgetClass   ""
#define fr__WidgetClass   ""
#define en_Hint   ""
#define en__Hint   ""
#define en_IsLock   "L&ocked"
#define fr_IsLock   "Verr&ouill�"
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
#define en_Auto2791   "X"
#define fr_Auto2791   "X"
#define it_Auto2791   "X"
#define es_Auto2791   "X"
#define de_Auto2791   "X"
#define nl_Auto2791   "X"
#define pt_Auto2791   "X"
#define xx_Auto2791   "X"
#define en__Auto2791   ""
#define fr__Auto2791   ""
#define it__Auto2791   ""
#define es__Auto2791   ""
#define de__Auto2791   ""
#define nl__Auto2791   ""
#define pt__Auto2791   ""
#define xx__Auto2791   ""
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
#define en_Auto2792   "Width"
#define fr_Auto2792   "Largeur"
#define it_Auto2792   "Width"
#define es_Auto2792   "Width"
#define de_Auto2792   "Width"
#define nl_Auto2792   "Width"
#define pt_Auto2792   "Width"
#define xx_Auto2792   "Width"
#define en__Auto2792   ""
#define fr__Auto2792   ""
#define it__Auto2792   ""
#define es__Auto2792   ""
#define de__Auto2792   ""
#define nl__Auto2792   ""
#define pt__Auto2792   ""
#define xx__Auto2792   ""
#define en_Auto2793   "Height"
#define fr_Auto2793   "Hauteur"
#define it_Auto2793   "Height"
#define es_Auto2793   "Height"
#define de_Auto2793   "Height"
#define nl_Auto2793   "Height"
#define pt_Auto2793   "Height"
#define xx_Auto2793   "Height"
#define en__Auto2793   ""
#define fr__Auto2793   ""
#define it__Auto2793   ""
#define es__Auto2793   ""
#define de__Auto2793   ""
#define nl__Auto2793   ""
#define pt__Auto2793   ""
#define xx__Auto2793   ""
#define en_Auto2794   "Y"
#define fr_Auto2794   "Y"
#define it_Auto2794   "Y"
#define es_Auto2794   "Y"
#define de_Auto2794   "Y"
#define nl_Auto2794   "Y"
#define pt_Auto2794   "Y"
#define xx_Auto2794   "Y"
#define en__Auto2794   ""
#define fr__Auto2794   ""
#define it__Auto2794   ""
#define es__Auto2794   ""
#define de__Auto2794   ""
#define nl__Auto2794   ""
#define pt__Auto2794   ""
#define xx__Auto2794   ""
#define en_IsBold   "Grip"
#define fr_IsBold   "Prise"
#define it_IsBold   "Grip"
#define es_IsBold   "Grip"
#define de_IsBold   "Grip"
#define nl_IsBold   "Grip"
#define pt_IsBold   "Grip"
#define xx_IsBold   "Grip"
#define en__IsBold   ""
#define fr__IsBold   ""
#define it__IsBold   ""
#define es__IsBold   ""
#define de__IsBold   ""
#define nl__IsBold   ""
#define pt__IsBold   ""
#define xx__IsBold   ""
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
#define en__Type   ""
#define fr__Type   ""
#define en_StyleSheet   ""
#define fr_StyleSheet   ""
#define en__StyleSheet   ""
#define fr__StyleSheet   ""
#define en_Auto2795   "Storage type"
#define fr_Auto2795   "Type de stockage"
#define it_Auto2795   "Storage type"
#define es_Auto2795   "Storage type"
#define de_Auto2795   "Storage type"
#define nl_Auto2795   "Storage type"
#define pt_Auto2795   "Storage type"
#define xx_Auto2795   "Storage type"
#define en__Auto2795   ""
#define fr__Auto2795   ""
#define it__Auto2795   ""
#define es__Auto2795   ""
#define de__Auto2795   ""
#define nl__Auto2795   ""
#define pt__Auto2795   ""
#define xx__Auto2795   ""
#define en_Auto2796   "Explicit style"
#define fr_Auto2796   "Style explicite"
#define it_Auto2796   "Explicit style"
#define es_Auto2796   "Explicit style"
#define de_Auto2796   "Explicit style"
#define nl_Auto2796   "Explicit style"
#define pt_Auto2796   "Explicit style"
#define xx_Auto2796   "Explicit style"
#define en__Auto2796   ""
#define fr__Auto2796   ""
#define it__Auto2796   ""
#define es__Auto2796   ""
#define de__Auto2796   ""
#define nl__Auto2796   ""
#define pt__Auto2796   ""
#define xx__Auto2796   ""
#define en_Auto2797   "Hint"
#define fr_Auto2797   "Infobulle"
#define it_Auto2797   "Hint"
#define es_Auto2797   "Hint"
#define de_Auto2797   "Hint"
#define nl_Auto2797   "Hint"
#define pt_Auto2797   "Hint"
#define xx_Auto2797   "Hint"
#define en__Auto2797   ""
#define fr__Auto2797   ""
#define it__Auto2797   ""
#define es__Auto2797   ""
#define de__Auto2797   ""
#define nl__Auto2797   ""
#define pt__Auto2797   ""
#define xx__Auto2797   ""
#define en_Auto2798   "Implicit style"
#define fr_Auto2798   "Style implicite"
#define it_Auto2798   "Implicit style"
#define es_Auto2798   "Implicit style"
#define de_Auto2798   "Implicit style"
#define nl_Auto2798   "Implicit style"
#define pt_Auto2798   "Implicit style"
#define xx_Auto2798   "Implicit style"
#define en__Auto2798   ""
#define fr__Auto2798   ""
#define it__Auto2798   ""
#define es__Auto2798   ""
#define de__Auto2798   ""
#define nl__Auto2798   ""
#define pt__Auto2798   ""
#define xx__Auto2798   ""
#define en_Auto2799   "Name"
#define fr_Auto2799   "Nom"
#define it_Auto2799   "Name"
#define es_Auto2799   "Name"
#define de_Auto2799   "Name"
#define nl_Auto2799   "Name"
#define pt_Auto2799   "Name"
#define xx_Auto2799   "Name"
#define en__Auto2799   ""
#define fr__Auto2799   ""
#define it__Auto2799   ""
#define es__Auto2799   ""
#define de__Auto2799   ""
#define nl__Auto2799   ""
#define pt__Auto2799   ""
#define xx__Auto2799   ""
#define en_Auto2800   "Widget class"
#define fr_Auto2800   "Classe de widget"
#define it_Auto2800   "Widget class"
#define es_Auto2800   "Widget class"
#define de_Auto2800   "Widget class"
#define nl_Auto2800   "Widget class"
#define pt_Auto2800   "Widget class"
#define xx_Auto2800   "Widget class"
#define en__Auto2800   ""
#define fr__Auto2800   ""
#define it__Auto2800   ""
#define es__Auto2800   ""
#define de__Auto2800   ""
#define nl__Auto2800   ""
#define pt__Auto2800   ""
#define xx__Auto2800   ""
#include "vwscroll.h"
static int	vfh[16];

/*	------------------------	*/
/*	p o s i t i o n _ a t ()	*/
/*	------------------------	*/
void	vwscroll_position_at(struct vwscroll_context * _Context,int x,int y){
	_Context->x_WidgetProperties=x;
	_Context->y_WidgetProperties=y;

}

/*	----------------	*/
/*	S e t V a r s ()	*/
/*	----------------	*/
void	vwscroll_SetVars(struct vwscroll_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	visual_signature("WWWW","WWWW");
	visual_transferin(_Context->buffer_AtX,7,pSpecificWidgetProperties->pAtX);
	visual_transferin(_Context->buffer_AtY,7,pSpecificWidgetProperties->pAtY);
	visual_transferin(_Context->buffer_Width,7,pSpecificWidgetProperties->pWidth);
	visual_transferin(_Context->buffer_Height,7,pSpecificWidgetProperties->pHeight);
	visual_signature("S","S");
	visual_transferin(_Context->buffer_Identity,255,pSpecificWidgetProperties->pIdentity);
	visual_signature("SS","SS");
	visual_transferin(_Context->buffer_StyleSheet,255,pSpecificWidgetProperties->pStyleSheet);
	visual_transferin(_Context->buffer_Hint,255,pSpecificWidgetProperties->pHint);
	if(!(pSpecificWidgetProperties->pWidgetClass))
	_Context->value_WidgetClass=0;
	else _Context->value_WidgetClass=*((int*)pSpecificWidgetProperties->pWidgetClass);
	if(!(pSpecificWidgetProperties->pType))
	_Context->value_Type=0;
	else _Context->value_Type=*((int*)pSpecificWidgetProperties->pType);
	if(!(pSpecificWidgetProperties->pAlign))
	_Context->value_Align=0;
	else _Context->value_Align=*((int*)pSpecificWidgetProperties->pAlign);
	if(!(pSpecificWidgetProperties->pIsBold))
	_Context->value_IsBold=0;
	else _Context->value_IsBold=*((int*)pSpecificWidgetProperties->pIsBold);
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
void	vwscroll_GetVars(struct vwscroll_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	visual_signature("WWWW","WWWW");
	visual_transferout(_Context->buffer_AtX,7,pSpecificWidgetProperties->pAtX);
	visual_transferout(_Context->buffer_AtY,7,pSpecificWidgetProperties->pAtY);
	visual_transferout(_Context->buffer_Width,7,pSpecificWidgetProperties->pWidth);
	visual_transferout(_Context->buffer_Height,7,pSpecificWidgetProperties->pHeight);
	visual_signature("S","S");
	visual_transferout(_Context->buffer_Identity,255,pSpecificWidgetProperties->pIdentity);
	visual_signature("SS","SS");
	visual_transferout(_Context->buffer_StyleSheet,255,pSpecificWidgetProperties->pStyleSheet);
	visual_transferout(_Context->buffer_Hint,255,pSpecificWidgetProperties->pHint);
	if(pSpecificWidgetProperties->pWidgetClass!=(char*)0)
	*((int*)pSpecificWidgetProperties->pWidgetClass)=_Context->value_WidgetClass;
	if(pSpecificWidgetProperties->pType!=(char*)0)
	*((int*)pSpecificWidgetProperties->pType)=_Context->value_Type;
	if(pSpecificWidgetProperties->pAlign!=(char*)0)
	*((int*)pSpecificWidgetProperties->pAlign)=_Context->value_Align;
	if(pSpecificWidgetProperties->pIsBold!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsBold)=_Context->value_IsBold;
	if(pSpecificWidgetProperties->pIsLock!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsLock)=_Context->value_IsLock;
	if(pSpecificWidgetProperties->pIswResize!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIswResize)=_Context->value_IswResize;
	if(pSpecificWidgetProperties->pIshResize!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIshResize)=_Context->value_IshResize;

}

public	int	vwscroll_attach()
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

public	int	vwscroll_attach_mode(int mode)
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

public	int	vwscroll_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	vwscroll_create(struct vwscroll_context **cptr)
{

	int i;
	struct vwscroll_context * _Context=(struct vwscroll_context*)0;
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
	if (!(_Context = allocate( sizeof( struct vwscroll_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=15;
		for (i=0; i < 255; i++)  *(_Context->buffer_Identity+i)=' ';
		_Context->value_WidgetClass=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Hint+i)=' ';
		_Context->value_IsLock=0;
		_Context->value_Align=0;
		for (i=0; i < 7; i++)  *(_Context->buffer_AtX+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_AtY+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Width+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Height+i)=' ';
		_Context->value_IsBold=0;
		_Context->value_IshResize=0;
		_Context->value_IswResize=0;
		_Context->value_Type=0;
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
	_Context->x_WidgetProperties=1;
	_Context->y_WidgetProperties=0;
	_Context->w_WidgetProperties=669;
	_Context->h_WidgetProperties=400;
	_Context->window_col=1;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2786[i]=" ";
	_Context->msg_Auto2786[0]=en_Auto2786;
	_Context->msg_Auto2786[1]=fr_Auto2786;
	_Context->msg_Auto2786[2]=it_Auto2786;
	_Context->msg_Auto2786[3]=es_Auto2786;
	_Context->msg_Auto2786[4]=de_Auto2786;
	_Context->msg_Auto2786[5]=nl_Auto2786;
	_Context->msg_Auto2786[6]=pt_Auto2786;
	_Context->msg_Auto2786[7]=xx_Auto2786;
	_Context->hint_Auto2786[0]=en__Auto2786;
	_Context->hint_Auto2786[1]=fr__Auto2786;
	_Context->hint_Auto2786[2]=it__Auto2786;
	_Context->hint_Auto2786[3]=es__Auto2786;
	_Context->hint_Auto2786[4]=de__Auto2786;
	_Context->hint_Auto2786[5]=nl__Auto2786;
	_Context->hint_Auto2786[6]=pt__Auto2786;
	_Context->hint_Auto2786[7]=xx__Auto2786;
	for (i=0; i < 8; i++)_Context->msg_Auto2788[i]=" ";
	_Context->msg_Auto2788[0]=en_Auto2788;
	_Context->msg_Auto2788[1]=fr_Auto2788;
	_Context->msg_Auto2788[2]=it_Auto2788;
	_Context->msg_Auto2788[3]=es_Auto2788;
	_Context->msg_Auto2788[4]=de_Auto2788;
	_Context->msg_Auto2788[5]=nl_Auto2788;
	_Context->msg_Auto2788[6]=pt_Auto2788;
	_Context->msg_Auto2788[7]=xx_Auto2788;
	_Context->hint_Auto2788[0]=en__Auto2788;
	_Context->hint_Auto2788[1]=fr__Auto2788;
	_Context->hint_Auto2788[2]=it__Auto2788;
	_Context->hint_Auto2788[3]=es__Auto2788;
	_Context->hint_Auto2788[4]=de__Auto2788;
	_Context->hint_Auto2788[5]=nl__Auto2788;
	_Context->hint_Auto2788[6]=pt__Auto2788;
	_Context->hint_Auto2788[7]=xx__Auto2788;
	for (i=0; i < 8; i++)_Context->msg_Auto2789[i]=" ";
	_Context->msg_Auto2789[0]=en_Auto2789;
	_Context->msg_Auto2789[1]=fr_Auto2789;
	_Context->msg_Auto2789[2]=it_Auto2789;
	_Context->msg_Auto2789[3]=es_Auto2789;
	_Context->msg_Auto2789[4]=de_Auto2789;
	_Context->msg_Auto2789[5]=nl_Auto2789;
	_Context->msg_Auto2789[6]=pt_Auto2789;
	_Context->msg_Auto2789[7]=xx_Auto2789;
	_Context->hint_Auto2789[0]=en__Auto2789;
	_Context->hint_Auto2789[1]=fr__Auto2789;
	_Context->hint_Auto2789[2]=it__Auto2789;
	_Context->hint_Auto2789[3]=es__Auto2789;
	_Context->hint_Auto2789[4]=de__Auto2789;
	_Context->hint_Auto2789[5]=nl__Auto2789;
	_Context->hint_Auto2789[6]=pt__Auto2789;
	_Context->hint_Auto2789[7]=xx__Auto2789;
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
	_Context->hint_Identity[1]=fr__Identity;
	for (i=0; i < 8; i++)_Context->msg_WidgetClass[i]=" ";
	_Context->hint_WidgetClass[0]=en__WidgetClass;
	_Context->hint_WidgetClass[1]=fr__WidgetClass;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2791[i]=" ";
	_Context->msg_Auto2791[0]=en_Auto2791;
	_Context->msg_Auto2791[1]=fr_Auto2791;
	_Context->msg_Auto2791[2]=it_Auto2791;
	_Context->msg_Auto2791[3]=es_Auto2791;
	_Context->msg_Auto2791[4]=de_Auto2791;
	_Context->msg_Auto2791[5]=nl_Auto2791;
	_Context->msg_Auto2791[6]=pt_Auto2791;
	_Context->msg_Auto2791[7]=xx_Auto2791;
	_Context->hint_Auto2791[0]=en__Auto2791;
	_Context->hint_Auto2791[1]=fr__Auto2791;
	_Context->hint_Auto2791[2]=it__Auto2791;
	_Context->hint_Auto2791[3]=es__Auto2791;
	_Context->hint_Auto2791[4]=de__Auto2791;
	_Context->hint_Auto2791[5]=nl__Auto2791;
	_Context->hint_Auto2791[6]=pt__Auto2791;
	_Context->hint_Auto2791[7]=xx__Auto2791;
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
	for (i=0; i < 8; i++)_Context->msg_Type[i]=" ";
	_Context->hint_Type[0]=en__Type;
	_Context->hint_Type[1]=fr__Type;
	_Context->hint_StyleSheet[0]=en__StyleSheet;
	_Context->hint_StyleSheet[1]=fr__StyleSheet;
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
	return(0);
}

public 	int	vwscroll_hide(struct vwscroll_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;

	return(result);
}

public	int	vwscroll_remove(struct vwscroll_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}

public	int	vwscroll_show(struct vwscroll_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_WidgetProperties,_Context->y_WidgetProperties,669,400,"widget_frame",_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]))) != 0)
) {
		visual_window(_Context->x_WidgetProperties,_Context->y_WidgetProperties,669,400,vfh[2],_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]),0x4);
		}
	visual_text(_Context->x_WidgetProperties+453,_Context->y_WidgetProperties+119,210,16,vfh[2],16,0,_Context->msg_Auto2786[_Context->language],strlen(_Context->msg_Auto2786[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+453,_Context->y_WidgetProperties+135,210,62,4);
	visual_filzone(_Context->x_WidgetProperties+251,_Context->y_WidgetProperties+268,1,1,27,0);
	visual_text(_Context->x_WidgetProperties+453,_Context->y_WidgetProperties+35,210,16,vfh[2],16,0,_Context->msg_Auto2788[_Context->language],strlen(_Context->msg_Auto2788[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+453,_Context->y_WidgetProperties+51,210,62,4);
	visual_text(_Context->x_WidgetProperties+7,_Context->y_WidgetProperties+201,657,16,vfh[2],16,0,_Context->msg_Auto2789[_Context->language],strlen(_Context->msg_Auto2789[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+7,_Context->y_WidgetProperties+217,657,94,4);
	visual_text(_Context->x_WidgetProperties+7,_Context->y_WidgetProperties+35,442,16,vfh[2],16,0,_Context->msg_Auto2790[_Context->language],strlen(_Context->msg_Auto2790[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+7,_Context->y_WidgetProperties+51,442,146,4);
	visual_frame(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+70,128+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+12+1,_Context->y_WidgetProperties+70+1,128,16,vfh[1],34,0,_Context->buffer_Identity,255,0);
	visual_select(_Context->x_WidgetProperties+222,_Context->y_WidgetProperties+70,120,140,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),768);
	visual_frame(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+114,424+2,64+2,5);
	visual_text(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+114+1,424,64,vfh[1],0,0,_Context->buffer_Hint,255,0);
	_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+461,_Context->y_WidgetProperties+72,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
	visual_text(_Context->x_WidgetProperties+464,_Context->y_WidgetProperties+144,14,21,vfh[2],16,0,_Context->msg_Auto2791[_Context->language],strlen(_Context->msg_Auto2791[_Context->language]),2);
	visual_select(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+250,126,96,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),768);
	visual_frame(_Context->x_WidgetProperties+462,_Context->y_WidgetProperties+161,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+462+1,_Context->y_WidgetProperties+161+1,35,16,vfh[1],34,0,_Context->buffer_AtX,7,0);
	visual_frame(_Context->x_WidgetProperties+507,_Context->y_WidgetProperties+161,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+507+1,_Context->y_WidgetProperties+161+1,35,16,vfh[1],34,0,_Context->buffer_AtY,7,0);
	visual_frame(_Context->x_WidgetProperties+562,_Context->y_WidgetProperties+161,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+562+1,_Context->y_WidgetProperties+161+1,35,16,vfh[1],34,0,_Context->buffer_Width,7,0);
	visual_frame(_Context->x_WidgetProperties+614,_Context->y_WidgetProperties+161,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+614+1,_Context->y_WidgetProperties+161+1,35,16,vfh[1],34,0,_Context->buffer_Height,7,0);
	visual_text(_Context->x_WidgetProperties+560,_Context->y_WidgetProperties+144,50,21,vfh[2],16,0,_Context->msg_Auto2792[_Context->language],strlen(_Context->msg_Auto2792[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+613,_Context->y_WidgetProperties+146,48,17,vfh[2],16,0,_Context->msg_Auto2793[_Context->language],strlen(_Context->msg_Auto2793[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+506,_Context->y_WidgetProperties+144,14,21,vfh[2],16,0,_Context->msg_Auto2794[_Context->language],strlen(_Context->msg_Auto2794[_Context->language]),2);
	_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_WidgetProperties+581,_Context->y_WidgetProperties+250,78,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
	_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+368,_Context->y_WidgetProperties+285,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
	_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+150,_Context->y_WidgetProperties+283,165,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
	visual_select(_Context->x_WidgetProperties+160,_Context->y_WidgetProperties+250,185,128,vfh[2],0,0,parse_selection(WidgetTypeList,&_Context->value_Type),768);
	visual_frame(_Context->x_WidgetProperties+369,_Context->y_WidgetProperties+250,190+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+369+1,_Context->y_WidgetProperties+250+1,190,16,vfh[1],0,0,_Context->buffer_StyleSheet,255,0);
	visual_text(_Context->x_WidgetProperties+160,_Context->y_WidgetProperties+236,182,16,vfh[2],16,0,_Context->msg_Auto2795[_Context->language],strlen(_Context->msg_Auto2795[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+369,_Context->y_WidgetProperties+234,182,16,vfh[2],16,0,_Context->msg_Auto2796[_Context->language],strlen(_Context->msg_Auto2796[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+98,210,16,vfh[2],16,0,_Context->msg_Auto2797[_Context->language],strlen(_Context->msg_Auto2797[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+235,126,16,vfh[2],16,0,_Context->msg_Auto2798[_Context->language],strlen(_Context->msg_Auto2798[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+57,154,16,vfh[2],16,0,_Context->msg_Auto2799[_Context->language],strlen(_Context->msg_Auto2799[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+222,_Context->y_WidgetProperties+57,135,16,vfh[2],16,0,_Context->msg_Auto2800[_Context->language],strlen(_Context->msg_Auto2800[_Context->language]),2);
	visual_filzone(_Context->x_WidgetProperties+247,_Context->y_WidgetProperties+270,1,1,27,0);
	visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,669,400);

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
			mptr[0] = "Nom du widget � utiliser dans le code source pour avoir acc�s aux ";
			mptr[1]="propri�t�s et m�thodes du widget. ";
			mptr[2]=" Par d�faut, Sing va donner un nom qui commence par Auto suivi d'un ";
			mptr[3]="num�ro qui change � chaque production du formulaire. ";
			mptr[4]=" N'utilisez pas ce nom par d�faut dans le code source.     ";
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
			mptr[0] = "La classe � laquelle le widget appartient. ";
			mptr[1]=" Le changement de classe est d�conseill�, car une partie du code est ";
			mptr[2]="g�n�r� � la cr�ation en fonction de la classe initiale et ne sera ";
			mptr[3]="pas modifi� une fois la classe chang�e.      ";
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
			mptr[0] = "Zone d'�dition dans laquelle vous pouvez ajoutez du texte pour avoir ";
			mptr[1]="plus  de d�tails concernant le widget. ";
			mptr[2]=" Le texte peut �tre afficher si vous avez cr�� une m�thode OnHint(message$), ";
			mptr[3]="qui re�oit comme param�tre le texte et l'affiche dans un widget d'affichage ";
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
			mptr[0] = "Cette case � cocher v�rrouille le widget contre toute tentative de ";
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
			char * mptr[1];
			mptr[0] = "Style liste proposit by Sing for this widget.     ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Liste des styles propos�s par Sing.  ";
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
			mptr[0] = "Les zones de saisie  X et Y permettent de sp�cifier la position du ";
			mptr[1]="coin en haut � gauche du widget. Pour pouvoir changer les valeurs ";
			mptr[2]=" X, Y dynamiquement, activez l'option with sizes de la  m�thode CREATE du widget. Les valeurs X,Y du widget ";
			mptr[3]="peuvent �tre chang�es par programmation en faisant appel  aux propri�t�s ";
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
			mptr[0] = "Les zones de saisie  X et Y permettent de sp�cifier la position du ";
			mptr[1]="coin en haut � gauche du widget. ";
			mptr[2]=" Pour pouvoir changer les valeurs  X, Y dynamiquement, il faut activez ";
			mptr[3]="l'option with sizes de la  m�thode CREATE du widget. Les valeurs X,Y du widget ";
			mptr[4]="peuvent �tre chang�es par programmation en faisant appel  aux propri�t�s ";
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
			mptr[0] = "Les zones de saisie  Largeur et Hauteur permettent de sp�cifier la ";
			mptr[1]="largeur et la hauteur du widget. ";
			mptr[2]=" Pour pouvoir changer dynamiquement les valeurs W,H, activez l'option ";
			mptr[3]="with sizes de la  m�thode CREATE du widget. Les valeurs W,H du widget ";
			mptr[4]="peuvent �tre chang�es par programmation en faisant appel  aux propri�t�s ";
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
			mptr[0] = "Les zones de saisie  Largeur et Hauteur permettent de sp�cifier la ";
			mptr[1]="largeur et la hauteur du widget. ";
			mptr[2]=" Pour pouvoir changer dynamiquement les valeurs W,H, activez l'option ";
			mptr[3]="with sizes de la  m�thode CREATE du widget. Les valeurs W,H du widget ";
			mptr[4]="peuvent �tre chang�es par programmation en faisant appel  aux propri�t�s ";
			mptr[5]="this.H et this.W.     ";
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
			mptr[0] = "Controls the focus grip atribut of scrollbars        ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Affiche une grille sur la scroll bar lorsqu'elle a le focus.     ";
			return(visual_online_help(mptr,1));
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
			mptr[0] = "Zone d'�dititon qui permet d'indiquer une classe de style pour ce ";
			mptr[1]="widget. La classe de style sp�cifi�e doit �tre d�crite dans un fichier ";
			mptr[2]="d�finit dans  Menu Formulaire/Propri�t�s/ Nom du fichier de classes de styles. ";
			mptr[3]=" Si le fichier .css est pr�sent au moment de l'�x�cution et si il ";
			mptr[4]="contient bien la description de la classe indiqu�e, cette classe sera ";
			mptr[5]="utilis�e pour afficher le widget.      ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}


public	int	vwscroll_event(
struct vwscroll_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsLock == mb ) return(5);
		if (_Context->trigger_IsBold == mb ) return(11);
		if (_Context->trigger_IshResize == mb ) return(12);
		if (_Context->trigger_IswResize == mb ) return(13);
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
		vwscroll_show(_Context);
		return(-1);	/* WidgetProperties */

		}
		}
	if (( mx >= (_Context->x_WidgetProperties+12) ) 
	&&  ( my >= (_Context->y_WidgetProperties+70) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+12+128) ) 
	&&  ( my <= (_Context->y_WidgetProperties+70+16))) {
		return(2); /* Identity */
		}
	if (( mx >= (_Context->x_WidgetProperties+222+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+70) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+222+120) ) 
	&&  ( my <= (_Context->y_WidgetProperties+70+16))) {
		return(3); /* WidgetClass */
		}
	if (( mx >= (_Context->x_WidgetProperties+13) ) 
	&&  ( my >= (_Context->y_WidgetProperties+114) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+13+424) ) 
	&&  ( my <= (_Context->y_WidgetProperties+114+64))) {
		return(4); /* Hint */
		}
	if (( mx >= (_Context->x_WidgetProperties+461) ) 
	&&  ( my >= (_Context->y_WidgetProperties+72) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+461+182) ) 
	&&  ( my <= (_Context->y_WidgetProperties+72+16))) {
		return(5); /* IsLock */
		}
	if (( mx >= (_Context->x_WidgetProperties+13+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+250) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+13+126) ) 
	&&  ( my <= (_Context->y_WidgetProperties+250+16))) {
		return(6); /* Align */
		}
	if (( mx >= (_Context->x_WidgetProperties+462) ) 
	&&  ( my >= (_Context->y_WidgetProperties+161) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+462+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+161+16))) {
		return(7); /* AtX */
		}
	if (( mx >= (_Context->x_WidgetProperties+507) ) 
	&&  ( my >= (_Context->y_WidgetProperties+161) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+507+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+161+16))) {
		return(8); /* AtY */
		}
	if (( mx >= (_Context->x_WidgetProperties+562) ) 
	&&  ( my >= (_Context->y_WidgetProperties+161) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+562+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+161+16))) {
		return(9); /* Width */
		}
	if (( mx >= (_Context->x_WidgetProperties+614) ) 
	&&  ( my >= (_Context->y_WidgetProperties+161) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+614+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+161+16))) {
		return(10); /* Height */
		}
	if (( mx >= (_Context->x_WidgetProperties+581) ) 
	&&  ( my >= (_Context->y_WidgetProperties+250) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+581+78) ) 
	&&  ( my <= (_Context->y_WidgetProperties+250+16))) {
		return(11); /* IsBold */
		}
	if (( mx >= (_Context->x_WidgetProperties+368) ) 
	&&  ( my >= (_Context->y_WidgetProperties+285) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+368+165) ) 
	&&  ( my <= (_Context->y_WidgetProperties+285+16))) {
		return(12); /* IshResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+150) ) 
	&&  ( my >= (_Context->y_WidgetProperties+283) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+150+165) ) 
	&&  ( my <= (_Context->y_WidgetProperties+283+16))) {
		return(13); /* IswResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+160+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+250) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+160+185) ) 
	&&  ( my <= (_Context->y_WidgetProperties+250+16))) {
		return(14); /* Type */
		}
	if (( mx >= (_Context->x_WidgetProperties+369) ) 
	&&  ( my >= (_Context->y_WidgetProperties+250) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+369+190) ) 
	&&  ( my <= (_Context->y_WidgetProperties+250+16))) {
		return(15); /* StyleSheet */
		}

	return(-1);
}


public	int	vwscroll_focus(struct vwscroll_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Identity */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+12+1,_Context->y_WidgetProperties+70+1,128,16,vfh[1],_Context->buffer_Identity,255);
			break;
			case	0x3 :
				/* WidgetClass */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+222,_Context->y_WidgetProperties+70,120,140,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),774);
				if(change_widget_class(&_Context->value_WidgetClass)!=0){
				return(26);
				}
				break;
			case	0x4 :
				/* Hint */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+114+1,424,64,vfh[1],_Context->buffer_Hint,255);
			break;
			case	0x5 :
				/* IsLock */
				visual_check(_Context->x_WidgetProperties+461,_Context->y_WidgetProperties+72,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),(_Context->value_IsLock |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+461,_Context->y_WidgetProperties+72,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
				break;
			case	0x6 :
				/* Align */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+250,126,96,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),774);
				break;
			case	0x7 :
				/* AtX */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+462+1,_Context->y_WidgetProperties+161+1,35,16,vfh[1],_Context->buffer_AtX,7);
			break;
			case	0x8 :
				/* AtY */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+507+1,_Context->y_WidgetProperties+161+1,35,16,vfh[1],_Context->buffer_AtY,7);
			break;
			case	0x9 :
				/* Width */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+562+1,_Context->y_WidgetProperties+161+1,35,16,vfh[1],_Context->buffer_Width,7);
			break;
			case	0xa :
				/* Height */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+614+1,_Context->y_WidgetProperties+161+1,35,16,vfh[1],_Context->buffer_Height,7);
			break;
			case	0xb :
				/* IsBold */
				visual_check(_Context->x_WidgetProperties+581,_Context->y_WidgetProperties+250,78,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),(_Context->value_IsBold |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_WidgetProperties+581,_Context->y_WidgetProperties+250,78,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
				break;
			case	0xc :
				/* IshResize */
				visual_check(_Context->x_WidgetProperties+368,_Context->y_WidgetProperties+285,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),(_Context->value_IshResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+368,_Context->y_WidgetProperties+285,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
				break;
			case	0xd :
				/* IswResize */
				visual_check(_Context->x_WidgetProperties+150,_Context->y_WidgetProperties+283,165,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),(_Context->value_IswResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+150,_Context->y_WidgetProperties+283,165,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
				break;
			case	0xe :
				/* Type */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+160,_Context->y_WidgetProperties+250,185,128,vfh[2],0,0,parse_selection(WidgetTypeList,&_Context->value_Type),774);
				break;
			case	0xf :
				/* StyleSheet */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+369+1,_Context->y_WidgetProperties+250+1,190,16,vfh[1],_Context->buffer_StyleSheet,255);
			break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			vwscroll_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=15;
			vwscroll_show(_Context);
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
			if ((retcode=vwscroll_event(_Context)) == -1)
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
						if (IsLock_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (Align_help(_Context) != 0) { continue; }
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
						if (IsBold_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (IshResize_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (IswResize_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (Type_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
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
					/* Align */
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
					/* IsBold */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsBold += 1;
						_Context->value_IsBold &= 1;
						}
					continue;
				case	0xc :
					/* IshResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IshResize += 1;
						_Context->value_IshResize &= 1;
						}
					continue;
				case	0xd :
					/* IswResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IswResize += 1;
						_Context->value_IswResize &= 1;
						}
					continue;
				case	0xe :
					/* Type */
					continue;
				case	0xf :
					/* StyleSheet */
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
				_Context->focus_item=15;
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

public	int	vwscroll()
{
	int	status=0;
	struct vwscroll_context * _Context=(struct vwscroll_context*) 0;
	status = vwscroll_create(&_Context);
	if ( status != 0) return(status);
	status = vwscroll_show(_Context);
		enter_modal();
	status = vwscroll_focus(_Context);
		leave_modal();
	status = vwscroll_hide(_Context);
	status = vwscroll_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwscroll_c */
