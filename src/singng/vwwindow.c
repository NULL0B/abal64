
#ifndef _vwwindow_c
#define _vwwindow_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vwwindow.xml                                             */
/* Target         : vwwindow.c                                               */
/* Identification : 0.0-1177511939-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "sing.h"
#include "singform.h"
#include "singprot.h"
#define en_WidgetProperties   "Window widget - Properties"
#define fr_WidgetProperties   "Window - Propri‚t‚s"
#define it_WidgetProperties   ""
#define es_WidgetProperties   ""
#define de_WidgetProperties   ""
#define nl_WidgetProperties   ""
#define pt_WidgetProperties   ""
#define xx_WidgetProperties   ""
#define en__WidgetProperties   ""
#define fr__WidgetProperties   ""
#define it__WidgetProperties   ""
#define es__WidgetProperties   ""
#define de__WidgetProperties   ""
#define nl__WidgetProperties   ""
#define pt__WidgetProperties   ""
#define xx__WidgetProperties   ""
#define en_Auto2791   "Position and Dimension"
#define fr_Auto2791   "Position et Dimension"
#define it_Auto2791   "Position and Dimension"
#define es_Auto2791   "Position and Dimension"
#define de_Auto2791   "Position and Dimension"
#define nl_Auto2791   "Position and Dimension"
#define pt_Auto2791   "Position and Dimension"
#define xx_Auto2791   "Position and Dimension"
#define en__Auto2791   ""
#define fr__Auto2791   ""
#define it__Auto2791   ""
#define es__Auto2791   ""
#define de__Auto2791   ""
#define nl__Auto2791   ""
#define pt__Auto2791   ""
#define xx__Auto2791   ""
#define en_Auto2793   "Title"
#define fr_Auto2793   "Titre"
#define it_Auto2793   "Title"
#define es_Auto2793   "Title"
#define de_Auto2793   "Title"
#define nl_Auto2793   "Title"
#define pt_Auto2793   "Title"
#define xx_Auto2793   "Title"
#define en__Auto2793   ""
#define fr__Auto2793   ""
#define it__Auto2793   ""
#define es__Auto2793   ""
#define de__Auto2793   ""
#define nl__Auto2793   ""
#define pt__Auto2793   ""
#define xx__Auto2793   ""
#define en_Auto2794   "Behaviour"
#define fr_Auto2794   "Comportement"
#define it_Auto2794   "Behaviour"
#define es_Auto2794   "Behaviour"
#define de_Auto2794   "Behaviour"
#define nl_Auto2794   "Behaviour"
#define pt_Auto2794   "Behaviour"
#define xx_Auto2794   "Behaviour"
#define en__Auto2794   ""
#define fr__Auto2794   ""
#define it__Auto2794   ""
#define es__Auto2794   ""
#define de__Auto2794   ""
#define nl__Auto2794   ""
#define pt__Auto2794   ""
#define xx__Auto2794   ""
#define en_Auto2795   "Appearence"
#define fr_Auto2795   "Apparence"
#define it_Auto2795   "Appearence"
#define es_Auto2795   "Appearence"
#define de_Auto2795   "Appearence"
#define nl_Auto2795   "Appearence"
#define pt_Auto2795   "Appearence"
#define xx_Auto2795   "Appearence"
#define en__Auto2795   ""
#define fr__Auto2795   ""
#define it__Auto2795   ""
#define es__Auto2795   ""
#define de__Auto2795   ""
#define nl__Auto2795   ""
#define pt__Auto2795   ""
#define xx__Auto2795   ""
#define en_Auto2796   "General"
#define fr_Auto2796   "G‚n‚ral"
#define it_Auto2796   "General"
#define es_Auto2796   "General"
#define de_Auto2796   "General"
#define nl_Auto2796   "General"
#define pt_Auto2796   "General"
#define xx_Auto2796   "General"
#define en__Auto2796   ""
#define fr__Auto2796   ""
#define it__Auto2796   ""
#define es__Auto2796   ""
#define de__Auto2796   ""
#define nl__Auto2796   ""
#define pt__Auto2796   ""
#define xx__Auto2796   ""
#define en_Identity   ""
#define fr_Identity   ""
#define en__Identity   ""
#define fr__Identity   ""
#define en__WidgetClass   ""
#define fr__WidgetClass   ""
#define en_Hint   ""
#define fr_Hint   ""
#define en__Hint   ""
#define fr__Hint   ""
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
#define en_IsSpecial   "Drag Bar"
#define fr_IsSpecial   "D‚pla‡able"
#define it_IsSpecial   "Drag Bar"
#define es_IsSpecial   "Drag Bar"
#define de_IsSpecial   "Drag Bar"
#define nl_IsSpecial   "Drag Bar"
#define pt_IsSpecial   "Drag Bar"
#define xx_IsSpecial   "Drag Bar"
#define en__IsSpecial   ""
#define fr__IsSpecial   ""
#define it__IsSpecial   ""
#define es__IsSpecial   ""
#define de__IsSpecial   ""
#define nl__IsSpecial   ""
#define pt__IsSpecial   ""
#define xx__IsSpecial   ""
#define en_AtX   ""
#define fr_AtX   ""
#define en__AtX   ""
#define fr__AtX   ""
#define en_AtY   ""
#define fr_AtY   ""
#define en__AtY   ""
#define fr__AtY   ""
#define en_Width   ""
#define fr_Width   ""
#define en__Width   ""
#define fr__Width   ""
#define en_Height   ""
#define fr_Height   ""
#define en__Height   ""
#define fr__Height   ""
#define en__Align   ""
#define fr__Align   ""
#define it__Align   ""
#define es__Align   ""
#define de__Align   ""
#define nl__Align   ""
#define pt__Align   ""
#define xx__Align   ""
#define en_StyleSheet   ""
#define fr_StyleSheet   ""
#define en__StyleSheet   ""
#define fr__StyleSheet   ""
#define en_IsBold   "Exit"
#define fr_IsBold   "Sortie"
#define it_IsBold   "Exit"
#define es_IsBold   "Exit"
#define de_IsBold   "Ausgang"
#define nl_IsBold   "Exit"
#define pt_IsBold   "Exit"
#define xx_IsBold   "Exit"
#define en__IsBold   ""
#define fr__IsBold   ""
#define it__IsBold   ""
#define es__IsBold   ""
#define de__IsBold   ""
#define nl__IsBold   ""
#define pt__IsBold   ""
#define xx__IsBold   ""
#define en_IsUnderline   "Help"
#define fr_IsUnderline   "Aide"
#define it_IsUnderline   "Help"
#define es_IsUnderline   "Help"
#define de_IsUnderline   "Hilfe"
#define nl_IsUnderline   "Help"
#define pt_IsUnderline   "Help"
#define xx_IsUnderline   "Help"
#define en__IsUnderline   ""
#define fr__IsUnderline   ""
#define it__IsUnderline   ""
#define es__IsUnderline   ""
#define de__IsUnderline   ""
#define nl__IsUnderline   ""
#define pt__IsUnderline   ""
#define xx__IsUnderline   ""
#define en_IsShadow   "Shadow"
#define fr_IsShadow   "Ombrage"
#define it_IsShadow   "Shadow"
#define es_IsShadow   "Sombra"
#define de_IsShadow   "Schatten"
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
#define en__TextFont   ""
#define fr__TextFont   ""
#define en_PayLoad   ""
#define fr_PayLoad   ""
#define en__PayLoad   ""
#define fr__PayLoad   ""
#define en_Auto2797   "X"
#define fr_Auto2797   "X"
#define it_Auto2797   "X"
#define es_Auto2797   "X"
#define de_Auto2797   "X"
#define nl_Auto2797   "X"
#define pt_Auto2797   "X"
#define xx_Auto2797   "X"
#define en__Auto2797   ""
#define fr__Auto2797   ""
#define it__Auto2797   ""
#define es__Auto2797   ""
#define de__Auto2797   ""
#define nl__Auto2797   ""
#define pt__Auto2797   ""
#define xx__Auto2797   ""
#define en_Auto2798   "Height"
#define fr_Auto2798   "Hauteur"
#define it_Auto2798   "Height"
#define es_Auto2798   "Height"
#define de_Auto2798   "Height"
#define nl_Auto2798   "Height"
#define pt_Auto2798   "Height"
#define xx_Auto2798   "Height"
#define en__Auto2798   ""
#define fr__Auto2798   ""
#define it__Auto2798   ""
#define es__Auto2798   ""
#define de__Auto2798   ""
#define nl__Auto2798   ""
#define pt__Auto2798   ""
#define xx__Auto2798   ""
#define en_Auto2799   "Width"
#define fr_Auto2799   "Largeur"
#define it_Auto2799   "Width"
#define es_Auto2799   "Width"
#define de_Auto2799   "Width"
#define nl_Auto2799   "Width"
#define pt_Auto2799   "Width"
#define xx_Auto2799   "Width"
#define en__Auto2799   ""
#define fr__Auto2799   ""
#define it__Auto2799   ""
#define es__Auto2799   ""
#define de__Auto2799   ""
#define nl__Auto2799   ""
#define pt__Auto2799   ""
#define xx__Auto2799   ""
#define en_Auto2800   "Y"
#define fr_Auto2800   "Y"
#define it_Auto2800   "Y"
#define es_Auto2800   "Y"
#define de_Auto2800   "Y"
#define nl_Auto2800   "Y"
#define pt_Auto2800   "Y"
#define xx_Auto2800   "Y"
#define en__Auto2800   ""
#define fr__Auto2800   ""
#define it__Auto2800   ""
#define es__Auto2800   ""
#define de__Auto2800   ""
#define nl__Auto2800   ""
#define pt__Auto2800   ""
#define xx__Auto2800   ""
#define en_Auto2801   "Font"
#define fr_Auto2801   "Police"
#define it_Auto2801   "Font"
#define es_Auto2801   "Font"
#define de_Auto2801   "Font"
#define nl_Auto2801   "Font"
#define pt_Auto2801   "Font"
#define xx_Auto2801   "Font"
#define en__Auto2801   ""
#define fr__Auto2801   ""
#define it__Auto2801   ""
#define es__Auto2801   ""
#define de__Auto2801   ""
#define nl__Auto2801   ""
#define pt__Auto2801   ""
#define xx__Auto2801   ""
#define en_Auto2802   "Title"
#define fr_Auto2802   "Titre"
#define it_Auto2802   "Title"
#define es_Auto2802   "Titulo"
#define de_Auto2802   "Uberschrift"
#define nl_Auto2802   "Title"
#define pt_Auto2802   "Title"
#define xx_Auto2802   "Title"
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
#include "vwwindow.h"
static int	vfh[16];

/*	------------------------	*/
/*	p o s i t i o n _ a t ()	*/
/*	------------------------	*/
void	vwwindow_position_at(struct vwwindow_context * _Context,int x,int y){
	_Context->x_WidgetProperties=x;
	_Context->y_WidgetProperties=y;

}

/*	----------------	*/
/*	S e t V a r s ()	*/
/*	----------------	*/
void	vwwindow_SetVars(struct vwwindow_context * _Context){
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
	visual_signature("SS","SS");
	visual_transferin(_Context->buffer_PayLoad,255,pSpecificWidgetProperties->pPayLoad);
	visual_transferin(_Context->buffer_Identity,255,pSpecificWidgetProperties->pIdentity);
	visual_signature("SS","SS");
	visual_transferin(_Context->buffer_StyleSheet,255,pSpecificWidgetProperties->pStyleSheet);
	visual_transferin(_Context->buffer_Hint,255,pSpecificWidgetProperties->pHint);
	if(!(pSpecificWidgetProperties->pWidgetClass))
	_Context->value_WidgetClass=0;
	else
	_Context->value_WidgetClass=*((int*)pSpecificWidgetProperties->pWidgetClass);
	if(!(pSpecificWidgetProperties->pAlign))
	_Context->value_Align=0;
	else
	_Context->value_Align=*((int*)pSpecificWidgetProperties->pAlign);
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
	if(!(pSpecificWidgetProperties->pIsSpecial))
	_Context->value_IsSpecial=0;
	else
	_Context->value_IsSpecial=*((int*)pSpecificWidgetProperties->pIsSpecial);

}

/*	----------------	*/
/*	G e t V a r s ()	*/
/*	----------------	*/
void	vwwindow_GetVars(struct vwwindow_context * _Context){
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
	if(pSpecificWidgetProperties->pIsBold!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsBold)=_Context->value_IsBold;
	if(pSpecificWidgetProperties->pIsUnderline!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsUnderline)=_Context->value_IsUnderline;
	if(pSpecificWidgetProperties->pIsShadow!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsShadow)=_Context->value_IsShadow;
	if(pSpecificWidgetProperties->pIsLock!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsLock)=_Context->value_IsLock;
	if(pSpecificWidgetProperties->pIsSpecial!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsSpecial)=_Context->value_IsSpecial;

}

public	int	vwwindow_attach()
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

public	int	vwwindow_attach_mode(int mode)
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

public	int	vwwindow_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	vwwindow_create(struct vwwindow_context **cptr)
{

	int i;
	struct vwwindow_context * _Context=(struct vwwindow_context*)0;
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
	if (!(_Context = allocate( sizeof( struct vwwindow_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=17;
		for (i=0; i < 255; i++)  *(_Context->buffer_Identity+i)=' ';
		_Context->value_WidgetClass=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Hint+i)=' ';
		_Context->value_IsLock=0;
		_Context->value_IsSpecial=0;
		for (i=0; i < 7; i++)  *(_Context->buffer_AtX+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_AtY+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Width+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Height+i)=' ';
		_Context->value_Align=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_StyleSheet+i)=' ';
		_Context->value_IsBold=0;
		_Context->value_IsUnderline=0;
		_Context->value_IsShadow=0;
		_Context->value_TextFont=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_PayLoad+i)=' ';
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
	_Context->w_WidgetProperties=670;
	_Context->h_WidgetProperties=400;
	_Context->window_col=1;
	_Context->window_row=0;
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
	_Context->hint_Identity[0]=en__Identity;
	_Context->hint_Identity[1]=fr__Identity;
	for (i=0; i < 8; i++)_Context->msg_WidgetClass[i]=" ";
	_Context->hint_WidgetClass[0]=en__WidgetClass;
	_Context->hint_WidgetClass[1]=fr__WidgetClass;
	_Context->hint_Hint[0]=en__Hint;
	_Context->hint_Hint[1]=fr__Hint;
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
	_Context->hint_AtX[0]=en__AtX;
	_Context->hint_AtX[1]=fr__AtX;
	_Context->hint_AtY[0]=en__AtY;
	_Context->hint_AtY[1]=fr__AtY;
	_Context->hint_Width[0]=en__Width;
	_Context->hint_Width[1]=fr__Width;
	_Context->hint_Height[0]=en__Height;
	_Context->hint_Height[1]=fr__Height;
	for (i=0; i < 8; i++)_Context->msg_Align[i]=" ";
	_Context->hint_Align[0]=en__Align;
	_Context->hint_Align[1]=fr__Align;
	_Context->hint_Align[2]=it__Align;
	_Context->hint_Align[3]=es__Align;
	_Context->hint_Align[4]=de__Align;
	_Context->hint_Align[5]=nl__Align;
	_Context->hint_Align[6]=pt__Align;
	_Context->hint_Align[7]=xx__Align;
	_Context->hint_StyleSheet[0]=en__StyleSheet;
	_Context->hint_StyleSheet[1]=fr__StyleSheet;
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
	for (i=0; i < 8; i++)_Context->msg_TextFont[i]=" ";
	_Context->hint_TextFont[0]=en__TextFont;
	_Context->hint_TextFont[1]=fr__TextFont;
	_Context->hint_PayLoad[0]=en__PayLoad;
	_Context->hint_PayLoad[1]=fr__PayLoad;
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

public 	int	vwwindow_hide(struct vwwindow_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;

	return(result);
}

public	int	vwwindow_remove(struct vwwindow_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}

public	int	vwwindow_show(struct vwwindow_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,"widget_frame",_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]))) != 0)
) {
		visual_window(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,vfh[2],_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]),0x4);
		}
	visual_text(_Context->x_WidgetProperties+453,_Context->y_WidgetProperties+100,208,16,vfh[2],16,0,_Context->msg_Auto2791[_Context->language],strlen(_Context->msg_Auto2791[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+453,_Context->y_WidgetProperties+116,208,47,4);
	visual_filzone(_Context->x_WidgetProperties+217,_Context->y_WidgetProperties+297,1,1,27,0);
	visual_text(_Context->x_WidgetProperties+5,_Context->y_WidgetProperties+268,659,16,vfh[2],16,0,_Context->msg_Auto2793[_Context->language],strlen(_Context->msg_Auto2793[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+5,_Context->y_WidgetProperties+284,659,108,4);
	visual_text(_Context->x_WidgetProperties+453,_Context->y_WidgetProperties+24,208,16,vfh[2],16,0,_Context->msg_Auto2794[_Context->language],strlen(_Context->msg_Auto2794[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+453,_Context->y_WidgetProperties+40,208,55,4);
	visual_text(_Context->x_WidgetProperties+4,_Context->y_WidgetProperties+164,658,16,vfh[2],16,0,_Context->msg_Auto2795[_Context->language],strlen(_Context->msg_Auto2795[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+4,_Context->y_WidgetProperties+180,658,87,4);
	visual_text(_Context->x_WidgetProperties+4,_Context->y_WidgetProperties+25,445,16,vfh[2],16,0,_Context->msg_Auto2796[_Context->language],strlen(_Context->msg_Auto2796[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+4,_Context->y_WidgetProperties+41,445,122,4);
	visual_frame(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+60,128+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+10+1,_Context->y_WidgetProperties+60+1,128,16,vfh[1],34,0,_Context->buffer_Identity,255,0);
	visual_select(_Context->x_WidgetProperties+222,_Context->y_WidgetProperties+62,120,140,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),768);
	visual_frame(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+100,424+2,48+2,5);
	visual_text(_Context->x_WidgetProperties+10+1,_Context->y_WidgetProperties+100+1,424,48,vfh[1],0,0,_Context->buffer_Hint,255,0);
	_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+47,180,17,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
	_Context->trigger_IsSpecial=visual_trigger_code(_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]));
	visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+72,168,16,vfh[2],28,28,_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]),_Context->value_IsSpecial|0);
	visual_frame(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+136,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+459+1,_Context->y_WidgetProperties+136+1,35,16,vfh[1],34,0,_Context->buffer_AtX,7,0);
	visual_frame(_Context->x_WidgetProperties+504,_Context->y_WidgetProperties+136,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+504+1,_Context->y_WidgetProperties+136+1,35,16,vfh[1],34,0,_Context->buffer_AtY,7,0);
	visual_frame(_Context->x_WidgetProperties+565,_Context->y_WidgetProperties+136,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+565+1,_Context->y_WidgetProperties+136+1,35,16,vfh[1],34,0,_Context->buffer_Width,7,0);
	visual_frame(_Context->x_WidgetProperties+615,_Context->y_WidgetProperties+136,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+615+1,_Context->y_WidgetProperties+136+1,35,16,vfh[1],34,0,_Context->buffer_Height,7,0);
	visual_select(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+215,130,100,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),768);
	visual_frame(_Context->x_WidgetProperties+223,_Context->y_WidgetProperties+218,212+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+223+1,_Context->y_WidgetProperties+218+1,212,16,vfh[1],0,0,_Context->buffer_StyleSheet,255,0);
	_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+190,180,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
	_Context->trigger_IsUnderline=visual_trigger_code(_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]));
	visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+216,180,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),_Context->value_IsUnderline|0);
	_Context->trigger_IsShadow=visual_trigger_code(_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]));
	visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+240,180,16,vfh[2],28,28,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),_Context->value_IsShadow|0);
	visual_select(_Context->x_WidgetProperties+9,_Context->y_WidgetProperties+303,130,100,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),768);
	visual_frame(_Context->x_WidgetProperties+11,_Context->y_WidgetProperties+347,642+2,32+2,5);
	visual_text(_Context->x_WidgetProperties+11+1,_Context->y_WidgetProperties+347+1,642,32,vfh[1],34,0,_Context->buffer_PayLoad,255,0);
	visual_text(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+120,14,21,vfh[2],16,0,_Context->msg_Auto2797[_Context->language],strlen(_Context->msg_Auto2797[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+611,_Context->y_WidgetProperties+120,50,21,vfh[2],16,0,_Context->msg_Auto2798[_Context->language],strlen(_Context->msg_Auto2798[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+559,_Context->y_WidgetProperties+119,50,21,vfh[2],16,0,_Context->msg_Auto2799[_Context->language],strlen(_Context->msg_Auto2799[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+503,_Context->y_WidgetProperties+120,14,21,vfh[2],16,0,_Context->msg_Auto2800[_Context->language],strlen(_Context->msg_Auto2800[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+288,208,16,vfh[2],16,0,_Context->msg_Auto2801[_Context->language],strlen(_Context->msg_Auto2801[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+11,_Context->y_WidgetProperties+332,98,16,vfh[2],16,0,_Context->msg_Auto2802[_Context->language],strlen(_Context->msg_Auto2802[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+222,_Context->y_WidgetProperties+203,182,16,vfh[2],16,0,_Context->msg_Auto2803[_Context->language],strlen(_Context->msg_Auto2803[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+85,180,16,vfh[2],16,0,_Context->msg_Auto2804[_Context->language],strlen(_Context->msg_Auto2804[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+200,70,16,vfh[2],16,0,_Context->msg_Auto2805[_Context->language],strlen(_Context->msg_Auto2805[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+46,154,16,vfh[2],16,0,_Context->msg_Auto2806[_Context->language],strlen(_Context->msg_Auto2806[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+220,_Context->y_WidgetProperties+48,135,16,vfh[2],16,0,_Context->msg_Auto2807[_Context->language],strlen(_Context->msg_Auto2807[_Context->language]),2);
	visual_filzone(_Context->x_WidgetProperties+213,_Context->y_WidgetProperties+299,1,1,27,0);
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
			mptr[5]="or forms method instructions.    ";
			return(visual_online_help(mptr,6));
			}
			break;
		case 1 : 
			{
			char * mptr[6];
			mptr[0] = "Donner un nom a votre objet afin de pouvoir acc‚der a ses m‚thodes ";
			mptr[1]="a partir d'autres objets (ex: MyObject.BUFFER). ";
			mptr[2]=" Par d‚faut, le nom commencera par Auto suivi d'un chiffre  unique. ";
			mptr[3]="Mais ce chiffre change a chaque production de code. ";
			mptr[4]=" Attention a ne pas r‚ferencer widgets de ce genre depuis d'eventuelles ";
			mptr[5]=" instructions dans vos methodes.   ";
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
			mptr[0] = "This Combo allows the CLASS of the window widget to be changed. ";
			mptr[1]=" The secondary properties associated with the widget and its methods ";
			mptr[2]="will be preserved and will not be changed to the default values of ";
			mptr[3]="the new widget type.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[4];
			mptr[0] = "Cette combo permet de changer la classe de votre objet. ";
			mptr[1]=" Mais c'est d‚conseill‚, car une partie du code est g‚n‚r‚ ";
			mptr[2]=" a la cr‚ation en fonction de la classe du widget et ne sera ";
			mptr[3]=" pas modifi‚ ici.   ";
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
			char * mptr[4];
			mptr[0] = "This edit field allows an explicative message text to be provided ";
			mptr[1]="to be used by an eventual hint presentation mechanism of the parent ";
			mptr[2]="form activetool the  forms method OnHint(message). For imformation concerning the  activation of hint ";
			mptr[3]="messages please refer to the corresponding section of the Widget, Forms and File Methods and Properties documentation.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Cette zone d'‚dition permet d'ajouter un texte d'expliquations ";
			mptr[1]=" pour ˆtre ‚ventuellement utilis‚ pour une pr‚sentation par le ";
			mptr[2]=" formulaire parent a l'aide de la fonction OnHint(message$).   ";
			return(visual_online_help(mptr,3));
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
			char * mptr[4];
			mptr[0] = "This check box allows the collection of widget properties to be locked ";
			mptr[1]="and consequently protected against accidental modification. The window ";
			mptr[2]="will also be protected against accidental displacement activetool the mouse. ";
			mptr[3]="   ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Cocher la case pour v‚rouiller l'objet, ainsi il sera prot‚g‚ ";
			mptr[1]=" contre toute tentative de modification involontaire.   ";
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
			char * mptr[11];
			mptr[0] = "This check control allows activation of a drag bar mechanisms for ";
			mptr[1]="these window  components when the corresponding form property, Dynamic Positioning,  has also been activated in the Forms Properties ";
			mptr[2]=" dialog box. ";
			mptr[3]=" ";
			mptr[4]=" When the window drag mechanisms is active it allows the user to reposition ";
			mptr[5]=" the window, activetool the mouse, by pressing the left button on the mouse ";
			mptr[6]="over the title bar of the window. The window may then be moved to ";
			mptr[7]="its desired position before releasing the left button of the mouse ";
			mptr[8]="to complete the operation.  ";
			mptr[9]=" ";
			mptr[10]="   ";
			return(visual_online_help(mptr,11));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Cocher cette case pour autoriser l'utilisateur a d‚placer la fenˆtre ";
			mptr[1]="si l'  attribut n‚c‚ssaire, DEPLACABALE, a bien ‚t‚ selectionn‚.  ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
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
			mptr[25]="dimensions du methode CREATE du widget … fin de pouvoir deplacer dynamiquement ";
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

private int AtY_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "See preceeding information concerning AtX.   ";
			return(visual_online_help(mptr,1));
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
			char * mptr[21];
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
			mptr[15]="this.H  ";
			mptr[16]=" ";
			mptr[17]=" By  default the dimensions are constant integer expressions. To be ";
			mptr[18]="able to redimension widgets during program operation it is necessary ";
			mptr[19]="to activate the corresponding option of the widget method CREATE. ";
			mptr[20]="      ";
			return(visual_online_help(mptr,21));
			}
			break;
		case 1 : 
			{
			char * mptr[28];
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
			mptr[26]="avec dimensions du methode CREATE du widget a fin de pouvoir redimensioner ";
			mptr[27]="dynamiquement un widget pendant l'execution finale du program.   ";
			return(visual_online_help(mptr,28));
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
			char * mptr[10];
			mptr[0] = "This combo allows the window alignment value to be selected from the ";
			mptr[1]="following list ";
			mptr[2]="  ";
			mptr[3]="  ";
			mptr[4]=" - none : no alignment is applied  ";
			mptr[5]=" - left : the window is aligned at the left edge of the screen  ";
			mptr[6]=" - right : the window is aligned on the right edge of the screen  ";
			mptr[7]=" - center : the window will be centered in the screen.  ";
			mptr[8]=" The alignment value applies to the window itself within the parent ";
			mptr[9]="graphical output screen.   ";
			return(visual_online_help(mptr,10));
			}
			break;
		case 1 : 
			{
			char * mptr[9];
			mptr[0] = "Ce combo permet de choisir allows une valeur d'alignement pour la ";
			mptr[1]="fenˆtre … partir  de la liste suivante :  ";
			mptr[2]="  ";
			mptr[3]=" - aucun : pas d'alignement   ";
			mptr[4]=" - gauche : alignement … gauche de l'‚cran.  ";
			mptr[5]=" - droite : alignement … droite de l'‚cran.  ";
			mptr[6]=" - centr‚ : alignement au mileu de l'‚cran.  ";
			mptr[7]=" L'alignement choisi s'appliquera sur la fenˆtre par rapport a la ";
			mptr[8]="fenˆtre parent.   ";
			return(visual_online_help(mptr,9));
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
			char * mptr[7];
			mptr[0] = "This edit field allows an alternative style classname to be specified ";
			mptr[1]="for this  component widget. Style classes specified in this way should ";
			mptr[2]="be described in the style sheet file defined in the Forms Properties dialog box. If a style sheet file is present and ";
			mptr[3]="the class is found to exist then the style will be  used for the display ";
			mptr[4]="of the component by the forms model editor. For further information ";
			mptr[5]="concerning style and style classes please refer to the corresponding ";
			mptr[6]="Visual Style and Widget Style documentations.     ";
			return(visual_online_help(mptr,7));
			}
			break;
		case 1 : 
			{
			char * mptr[6];
			mptr[0] = "Cette zone d'‚dition permet d'indiquer une classe de style pour cet ";
			mptr[1]="objet. La classe de style sp‚cifi‚e ici doit ˆtre d‚crite dans un ";
			mptr[2]="fichier d‚finie dans la boite de dialogue propri‚t‚s du formulaire. ";
			mptr[3]=" Si le fichier style est pr‚sent au moment de l'‚x‚cution et qu'il ";
			mptr[4]="contient bien la description de la classe indiqu‚e alors il sera utilis‚ ";
			mptr[5]="pour afficher l'objet.    ";
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
			char * mptr[6];
			mptr[0] = "This check value controls the presence of the WINDOW EXIT button, ";
			mptr[1]=" appearing at the top right hand corner of the widget, which when ";
			mptr[2]="clicked will  return an ESCAPE result. The window exit button may not be visible  depending ";
			mptr[3]="upon the actual definition of overloading style classes used at runtime. ";
			mptr[4]="The style class windowexit may be defined to control the visual aspect and position ";
			mptr[5]="of this property.           ";
			return(visual_online_help(mptr,6));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Cocher la case pour avoir un bouton de sortie en haut a droite. ";
			mptr[1]=" La fonction renvoie alors Escape si on sors par ce bouton.    ";
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
			char * mptr[14];
			mptr[0] = "This check control activates display of the WINDOW HELP button in ";
			mptr[1]="the top right corner of the window widget. ";
			mptr[2]=" ";
			mptr[3]=" This help button gives direct access to the HTML documentation generated ";
			mptr[4]="for the  parent forms component. The window help button may not be ";
			mptr[5]="visible  depending upon the actual definition of overloading style ";
			mptr[6]="classes used at runtime. The style class windowhelp may be defined to control the visual aspect and position ";
			mptr[7]="of this property.  ";
			mptr[8]=" ";
			mptr[9]="The standard internet navigator will be used, depending on the host ";
			mptr[10]="system and the visual configuration, for consultation of the document ";
			mptr[11]="opening in this way.  ";
			mptr[12]=" ";
			mptr[13]="    ";
			return(visual_online_help(mptr,14));
			}
			break;
		case 1 : 
			{
			char * mptr[4];
			mptr[0] = "Si vous cochez cette case, vous aurez alors un bouton d'aide en haut ";
			mptr[1]="a droite de  la fenˆtre. ";
			mptr[2]=" En cliquant sur ce bouton vous aurez accŠs … la page de documentation ";
			mptr[3]="du formulaire en cours.    ";
			return(visual_online_help(mptr,4));
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
			char * mptr[4];
			mptr[0] = "Activation of this check control allows a window shadowing to be applied ";
			mptr[1]="to the bottom right of the window component. Window shadowing mat ";
			mptr[2]="not be visible  depending upon the actual definition of overloading ";
			mptr[3]="style classes used at runtime.    ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Activation de ce check permet d'ajouter une ombre en bas et … droite ";
			mptr[1]="de la  fenˆtre.    ";
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
			char * mptr[17];
			mptr[0] = "Choisir la police de caract‚res pour le titre de la fenetre. ";
			mptr[1]=" ";
			mptr[2]=" Vous pouvez retrouver dans vos programmes, la valeur num‚rique de ";
			mptr[3]="ce champ  avec le terme ";
			mptr[4]=" ";
			mptr[5]="      this.FONT. ";
			mptr[6]=" ";
			mptr[7]=" Les dimensions de la police sont disponibles a travers les termes ";
			mptr[8]=" ";
			mptr[9]=" ";
			mptr[10]="      this.FONTWIDTH ";
			mptr[11]=" ";
			mptr[12]=" et ";
			mptr[13]=" ";
			mptr[14]="      this.FONTHEIGHT ";
			mptr[15]=" ";
			mptr[16]=" pour la calculs eventuelles de redimensionment.   ";
			return(visual_online_help(mptr,17));
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
			char * mptr[15];
			mptr[0] = "The window title. ";
			mptr[1]=" ";
			mptr[2]=" If the first caracter of this zone is a $, then the standard constant ";
			mptr[3]="string expression will be inhibited and the remainder of the expression ";
			mptr[4]=" will be used as is to represent the title of the window. ";
			mptr[5]=" ";
			mptr[6]=" This may be any legal ABAL expression ";
			mptr[7]=" ";
			mptr[8]=" Example : $fct(p1,p2) ";
			mptr[9]=" ";
			mptr[10]=" will call fct with the parameters p1 and p2. ";
			mptr[11]=" The return value must be a string. ";
			mptr[12]=" ";
			mptr[13]=" The value of this atribut may referenced by the term this.PAYLOAD. ";
			mptr[14]="   ";
			return(visual_online_help(mptr,15));
			}
			break;
		case 1 : 
			{
			char * mptr[16];
			mptr[0] = "Saisir le titre de la fenetre. ";
			mptr[1]=" ";
			mptr[2]=" Si le premier caract‚re de cette zone est un $, la creation d'une ";
			mptr[3]="expression  constante est inhib‚ et l'expression derriere la dollar ";
			mptr[4]="est utilis‚ telle quelle.  ";
			mptr[5]=" ";
			mptr[6]="Ceci peut etre une expression d'appel de fonction avec ‚ventuellement ";
			mptr[7]="des param‚tres.  ";
			mptr[8]=" ";
			mptr[9]=" Exemple : $fct(p1,p2)  ";
			mptr[10]=" ";
			mptr[11]=" entrainera l'appel de la fonction fct avec les param‚tres p1 et p2. ";
			mptr[12]=" La fonction doit retourner une valeur string. ";
			mptr[13]=" ";
			mptr[14]=" Retrouvez la valeur de cette zone dans la variable this.PAYLOAD. ";
			mptr[15]="  ";
			return(visual_online_help(mptr,16));
			}
			break;
		default : return(0);
		}
	return(0);
}
private int on_Identity_event(struct vwwindow_context * _Context) {
	Identity_help(_Context);
	return(-1);
}
private int on_WidgetClass_event(struct vwwindow_context * _Context) {
	WidgetClass_help(_Context);
	return(-1);
}
private int on_Hint_event(struct vwwindow_context * _Context) {
	Hint_help(_Context);
	return(-1);
}
private int on_IsLock_event(struct vwwindow_context * _Context) {
	IsLock_help(_Context);
	return(-1);
}
private int on_IsSpecial_event(struct vwwindow_context * _Context) {
	IsSpecial_help(_Context);
	return(-1);
}
private int on_AtX_event(struct vwwindow_context * _Context) {
	AtX_help(_Context);
	return(-1);
}
private int on_AtY_event(struct vwwindow_context * _Context) {
	AtX_help(_Context);
	return(-1);
}
private int on_Width_event(struct vwwindow_context * _Context) {
	Width_help(_Context);
	return(-1);
}
private int on_Height_event(struct vwwindow_context * _Context) {
	Width_help(_Context);
	return(-1);
}
private int on_Align_event(struct vwwindow_context * _Context) {
	Align_help(_Context);
	return(-1);
}
private int on_StyleSheet_event(struct vwwindow_context * _Context) {
	StyleSheet_help(_Context);
	return(-1);
}
private int on_IsBold_event(struct vwwindow_context * _Context) {
	IsBold_help(_Context);
	return(-1);
}
private int on_IsUnderline_event(struct vwwindow_context * _Context) {
	IsUnderline_help(_Context);
	return(-1);
}
private int on_IsShadow_event(struct vwwindow_context * _Context) {
	IsShadow_help(_Context);
	return(-1);
}
private int on_TextFont_event(struct vwwindow_context * _Context) {
	TextFont_help(_Context);
	return(-1);
}
private int on_PayLoad_event(struct vwwindow_context * _Context) {
	PayLoad_help(_Context);
	return(-1);
}


public	int	vwwindow_event(
struct vwwindow_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsLock == mb ) return(5);
		if (_Context->trigger_IsSpecial == mb ) return(6);
		if (_Context->trigger_IsBold == mb ) return(13);
		if (_Context->trigger_IsUnderline == mb ) return(14);
		if (_Context->trigger_IsShadow == mb ) return(15);
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
		vwwindow_show(_Context);
		return(-1);	/* WidgetProperties */

		}
		}
	if (( mx >= (_Context->x_WidgetProperties+10) ) 
	&&  ( my >= (_Context->y_WidgetProperties+60) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+10+128) ) 
	&&  ( my <= (_Context->y_WidgetProperties+60+16))) {
		return(2); /* Identity */
		}
	if (( mx >= (_Context->x_WidgetProperties+222+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+62) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+222+120) ) 
	&&  ( my <= (_Context->y_WidgetProperties+62+16))) {
		return(3); /* WidgetClass */
		}
	if (( mx >= (_Context->x_WidgetProperties+10) ) 
	&&  ( my >= (_Context->y_WidgetProperties+100) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+10+424) ) 
	&&  ( my <= (_Context->y_WidgetProperties+100+48))) {
		return(4); /* Hint */
		}
	if (( mx >= (_Context->x_WidgetProperties+459) ) 
	&&  ( my >= (_Context->y_WidgetProperties+47) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+459+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+47+17))) {
		return(5); /* IsLock */
		}
	if (( mx >= (_Context->x_WidgetProperties+460) ) 
	&&  ( my >= (_Context->y_WidgetProperties+72) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+460+168) ) 
	&&  ( my <= (_Context->y_WidgetProperties+72+16))) {
		return(6); /* IsSpecial */
		}
	if (( mx >= (_Context->x_WidgetProperties+459) ) 
	&&  ( my >= (_Context->y_WidgetProperties+136) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+459+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+136+16))) {
		return(7); /* AtX */
		}
	if (( mx >= (_Context->x_WidgetProperties+504) ) 
	&&  ( my >= (_Context->y_WidgetProperties+136) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+504+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+136+16))) {
		return(8); /* AtY */
		}
	if (( mx >= (_Context->x_WidgetProperties+565) ) 
	&&  ( my >= (_Context->y_WidgetProperties+136) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+565+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+136+16))) {
		return(9); /* Width */
		}
	if (( mx >= (_Context->x_WidgetProperties+615) ) 
	&&  ( my >= (_Context->y_WidgetProperties+136) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+615+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+136+16))) {
		return(10); /* Height */
		}
	if (( mx >= (_Context->x_WidgetProperties+10+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+215) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+10+130) ) 
	&&  ( my <= (_Context->y_WidgetProperties+215+16))) {
		return(11); /* Align */
		}
	if (( mx >= (_Context->x_WidgetProperties+223) ) 
	&&  ( my >= (_Context->y_WidgetProperties+218) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+223+212) ) 
	&&  ( my <= (_Context->y_WidgetProperties+218+16))) {
		return(12); /* StyleSheet */
		}
	if (( mx >= (_Context->x_WidgetProperties+459) ) 
	&&  ( my >= (_Context->y_WidgetProperties+190) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+459+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+190+16))) {
		return(13); /* IsBold */
		}
	if (( mx >= (_Context->x_WidgetProperties+459) ) 
	&&  ( my >= (_Context->y_WidgetProperties+216) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+459+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+216+16))) {
		return(14); /* IsUnderline */
		}
	if (( mx >= (_Context->x_WidgetProperties+459) ) 
	&&  ( my >= (_Context->y_WidgetProperties+240) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+459+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+240+16))) {
		return(15); /* IsShadow */
		}
	if (( mx >= (_Context->x_WidgetProperties+9+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+303) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+9+130) ) 
	&&  ( my <= (_Context->y_WidgetProperties+303+16))) {
		return(16); /* TextFont */
		}
	if (( mx >= (_Context->x_WidgetProperties+11) ) 
	&&  ( my >= (_Context->y_WidgetProperties+347) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+11+642) ) 
	&&  ( my <= (_Context->y_WidgetProperties+347+32))) {
		return(17); /* PayLoad */
		}

	return(-1);
}


public	int	vwwindow_focus(struct vwwindow_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Identity */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+10+1,_Context->y_WidgetProperties+60+1,128,16,vfh[1],_Context->buffer_Identity,255);
			break;
			case	0x3 :
				/* WidgetClass */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+222,_Context->y_WidgetProperties+62,120,140,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),774);
				if(change_widget_class(&_Context->value_WidgetClass)!=0){
				return(26);
				}
				break;
			case	0x4 :
				/* Hint */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+10+1,_Context->y_WidgetProperties+100+1,424,48,vfh[1],_Context->buffer_Hint,255);
			break;
			case	0x5 :
				/* IsLock */
				visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+47,180,17,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),(_Context->value_IsLock |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+47,180,17,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
				break;
			case	0x6 :
				/* IsSpecial */
				visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+72,168,16,vfh[2],28,28,_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]),(_Context->value_IsSpecial |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsSpecial=visual_trigger_code(_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]));
	visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+72,168,16,vfh[2],28,28,_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]),_Context->value_IsSpecial|0);
				break;
			case	0x7 :
				/* AtX */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+459+1,_Context->y_WidgetProperties+136+1,35,16,vfh[1],_Context->buffer_AtX,7);
			break;
			case	0x8 :
				/* AtY */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+504+1,_Context->y_WidgetProperties+136+1,35,16,vfh[1],_Context->buffer_AtY,7);
			break;
			case	0x9 :
				/* Width */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+565+1,_Context->y_WidgetProperties+136+1,35,16,vfh[1],_Context->buffer_Width,7);
			break;
			case	0xa :
				/* Height */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+615+1,_Context->y_WidgetProperties+136+1,35,16,vfh[1],_Context->buffer_Height,7);
			break;
			case	0xb :
				/* Align */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+215,130,100,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),774);
				break;
			case	0xc :
				/* StyleSheet */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+223+1,_Context->y_WidgetProperties+218+1,212,16,vfh[1],_Context->buffer_StyleSheet,255);
			break;
			case	0xd :
				/* IsBold */
				visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+190,180,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),(_Context->value_IsBold |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+190,180,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
				break;
			case	0xe :
				/* IsUnderline */
				visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+216,180,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),(_Context->value_IsUnderline |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsUnderline=visual_trigger_code(_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]));
	visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+216,180,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),_Context->value_IsUnderline|0);
				break;
			case	0xf :
				/* IsShadow */
				visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+240,180,16,vfh[2],28,28,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),(_Context->value_IsShadow |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsShadow=visual_trigger_code(_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]));
	visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+240,180,16,vfh[2],28,28,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),_Context->value_IsShadow|0);
				break;
			case	0x10 :
				/* TextFont */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+9,_Context->y_WidgetProperties+303,130,100,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),770);
				break;
			case	0x11 :
				/* PayLoad */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+11+1,_Context->y_WidgetProperties+347+1,642,32,vfh[1],_Context->buffer_PayLoad,255);
			break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			vwwindow_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=17;
			vwwindow_show(_Context);
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
			if ((retcode=vwwindow_event(_Context)) == -1)
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
					/* Identity */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_Identity_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* WidgetClass */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_WidgetClass_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Hint */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_Hint_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* IsLock */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsLock += 1;
						_Context->value_IsLock &= 1;
						}
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_IsLock_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* IsSpecial */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsSpecial += 1;
						_Context->value_IsSpecial &= 1;
						}
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_IsSpecial_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* AtX */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_AtX_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* AtY */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_AtY_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Width */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_Width_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Height */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_Height_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Align */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_Align_event(_Context)) != -1) break;

						}
					continue;
				case	0xc :
					/* StyleSheet */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_StyleSheet_event(_Context)) != -1) break;

						}
					continue;
				case	0xd :
					/* IsBold */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsBold += 1;
						_Context->value_IsBold &= 1;
						}
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_IsBold_event(_Context)) != -1) break;

						}
					continue;
				case	0xe :
					/* IsUnderline */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsUnderline += 1;
						_Context->value_IsUnderline &= 1;
						}
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_IsUnderline_event(_Context)) != -1) break;

						}
					continue;
				case	0xf :
					/* IsShadow */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsShadow += 1;
						_Context->value_IsShadow &= 1;
						}
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_IsShadow_event(_Context)) != -1) break;

						}
					continue;
				case	0x10 :
					/* TextFont */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_TextFont_event(_Context)) != -1) break;

						}
					continue;
				case	0x11 :
					/* PayLoad */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_PayLoad_event(_Context)) != -1) break;

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

public	int	vwwindow()
{
	int	status=0;
	struct vwwindow_context * _Context=(struct vwwindow_context*) 0;
	status = vwwindow_create(&_Context);
	if ( status != 0) return(status);
	status = vwwindow_show(_Context);
		enter_modal();
	status = vwwindow_focus(_Context);
		leave_modal();
	status = vwwindow_hide(_Context);
	status = vwwindow_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwwindow_c */
