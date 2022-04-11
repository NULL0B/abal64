
#ifndef _vwselect_c
#define _vwselect_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.33                                                */
/* Production     : C                                                        */
/* Project        : vwselect.xml                                             */
/* Target         : vwselect.c                                               */
/* Identification : 0.0-1189177890-7931.7930                                 */
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
#define en_Auto2898   "Position and Dimension"
#define fr_Auto2898   "Position et Dimension"
#define it_Auto2898   ""
#define es_Auto2898   ""
#define de_Auto2898   ""
#define nl_Auto2898   ""
#define pt_Auto2898   ""
#define xx_Auto2898   ""
#define en__Auto2898   ""
#define fr__Auto2898   ""
#define it__Auto2898   ""
#define es__Auto2898   ""
#define de__Auto2898   ""
#define nl__Auto2898   ""
#define pt__Auto2898   ""
#define xx__Auto2898   ""
#define en_Auto2900   "Behaviour"
#define fr_Auto2900   "Comportement"
#define it_Auto2900   "Behaviour"
#define es_Auto2900   "Behaviour"
#define de_Auto2900   "Behaviour"
#define nl_Auto2900   "Behaviour"
#define pt_Auto2900   "Behaviour"
#define xx_Auto2900   "Behaviour"
#define en__Auto2900   ""
#define fr__Auto2900   ""
#define it__Auto2900   ""
#define es__Auto2900   ""
#define de__Auto2900   ""
#define nl__Auto2900   ""
#define pt__Auto2900   ""
#define xx__Auto2900   ""
#define en_Auto2901   "Appearence"
#define fr_Auto2901   "Apparence"
#define it_Auto2901   "Appearence"
#define es_Auto2901   "Appearence"
#define de_Auto2901   "Appearence"
#define nl_Auto2901   "Appearence"
#define pt_Auto2901   "Appearence"
#define xx_Auto2901   "Appearence"
#define en__Auto2901   ""
#define fr__Auto2901   ""
#define it__Auto2901   ""
#define es__Auto2901   ""
#define de__Auto2901   ""
#define nl__Auto2901   ""
#define pt__Auto2901   ""
#define xx__Auto2901   ""
#define en_Auto2902   "General"
#define fr_Auto2902   "G‚n‚ral"
#define it_Auto2902   "General"
#define es_Auto2902   "General"
#define de_Auto2902   "General"
#define nl_Auto2902   "General"
#define pt_Auto2902   "General"
#define xx_Auto2902   "General"
#define en__Auto2902   ""
#define fr__Auto2902   ""
#define it__Auto2902   ""
#define es__Auto2902   ""
#define de__Auto2902   ""
#define nl__Auto2902   ""
#define pt__Auto2902   ""
#define xx__Auto2902   ""
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
#define en_Auto2903   "X"
#define fr_Auto2903   "X"
#define it_Auto2903   "X"
#define es_Auto2903   "X"
#define de_Auto2903   "X"
#define nl_Auto2903   "X"
#define pt_Auto2903   "X"
#define xx_Auto2903   "X"
#define en__Auto2903   ""
#define fr__Auto2903   ""
#define it__Auto2903   ""
#define es__Auto2903   ""
#define de__Auto2903   ""
#define nl__Auto2903   ""
#define pt__Auto2903   ""
#define xx__Auto2903   ""
#define en__TextFont   ""
#define fr__TextFont   ""
#define en_Auto2904   "Height"
#define fr_Auto2904   "Hauteur"
#define it_Auto2904   "Height"
#define es_Auto2904   "Height"
#define de_Auto2904   "Height"
#define nl_Auto2904   "Height"
#define pt_Auto2904   "Height"
#define xx_Auto2904   "Height"
#define en__Auto2904   ""
#define fr__Auto2904   ""
#define it__Auto2904   ""
#define es__Auto2904   ""
#define de__Auto2904   ""
#define nl__Auto2904   ""
#define pt__Auto2904   ""
#define xx__Auto2904   ""
#define en_AtX   ""
#define en__AtX   ""
#define en_AtY   ""
#define en__AtY   ""
#define en_Width   ""
#define en__Width   ""
#define en_Height   ""
#define en__Height   ""
#define en_Auto2905   "Width"
#define fr_Auto2905   "Largeur"
#define it_Auto2905   "Width"
#define es_Auto2905   "Width"
#define de_Auto2905   "Width"
#define nl_Auto2905   "Width"
#define pt_Auto2905   "Width"
#define xx_Auto2905   "Width"
#define en__Auto2905   ""
#define fr__Auto2905   ""
#define it__Auto2905   ""
#define es__Auto2905   ""
#define de__Auto2905   ""
#define nl__Auto2905   ""
#define pt__Auto2905   ""
#define xx__Auto2905   ""
#define en_Auto2906   "Y"
#define fr_Auto2906   "Y"
#define it_Auto2906   "Y"
#define es_Auto2906   "Y"
#define de_Auto2906   "Y"
#define nl_Auto2906   "Y"
#define pt_Auto2906   "Y"
#define xx_Auto2906   "Y"
#define en__Auto2906   ""
#define fr__Auto2906   ""
#define it__Auto2906   ""
#define es__Auto2906   ""
#define de__Auto2906   ""
#define nl__Auto2906   ""
#define pt__Auto2906   ""
#define xx__Auto2906   ""
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
#define en_Auto2907   "Font"
#define fr_Auto2907   "Police"
#define it_Auto2907   "Text Font"
#define es_Auto2907   "Text Font"
#define de_Auto2907   "Text Font"
#define nl_Auto2907   "Text Font"
#define pt_Auto2907   "Text Font"
#define xx_Auto2907   "Teacs"
#define en__Auto2907   ""
#define fr__Auto2907   ""
#define it__Auto2907   ""
#define es__Auto2907   ""
#define de__Auto2907   ""
#define nl__Auto2907   ""
#define pt__Auto2907   ""
#define xx__Auto2907   ""
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
#define en_Auto2908   "Options list"
#define fr_Auto2908   "Liste des options"
#define it_Auto2908   "Text"
#define es_Auto2908   "Text"
#define de_Auto2908   "Text"
#define nl_Auto2908   "Text"
#define pt_Auto2908   "Text"
#define xx_Auto2908   "Text"
#define en__Auto2908   ""
#define fr__Auto2908   ""
#define it__Auto2908   ""
#define es__Auto2908   ""
#define de__Auto2908   ""
#define nl__Auto2908   ""
#define pt__Auto2908   ""
#define xx__Auto2908   ""
#define en_Auto2909   "Explicit style"
#define fr_Auto2909   "Style explicite"
#define it_Auto2909   "Style"
#define es_Auto2909   "Style"
#define de_Auto2909   "Style"
#define nl_Auto2909   "Style"
#define pt_Auto2909   "Style"
#define xx_Auto2909   "Style"
#define en__Auto2909   ""
#define fr__Auto2909   ""
#define it__Auto2909   ""
#define es__Auto2909   ""
#define de__Auto2909   ""
#define nl__Auto2909   ""
#define pt__Auto2909   ""
#define xx__Auto2909   ""
#define en_Auto2910   "Hint"
#define fr_Auto2910   "Infobulle"
#define it_Auto2910   "Hint"
#define es_Auto2910   "Hint"
#define de_Auto2910   "Hint"
#define nl_Auto2910   "Hint"
#define pt_Auto2910   "Hint"
#define xx_Auto2910   "Hint"
#define en__Auto2910   ""
#define fr__Auto2910   ""
#define it__Auto2910   ""
#define es__Auto2910   ""
#define de__Auto2910   ""
#define nl__Auto2910   ""
#define pt__Auto2910   ""
#define xx__Auto2910   ""
#define en_Auto2911   "Alignment"
#define fr_Auto2911   "Alignement"
#define it_Auto2911   "Options"
#define es_Auto2911   "Options"
#define de_Auto2911   "Options"
#define nl_Auto2911   "Options"
#define pt_Auto2911   "Options"
#define xx_Auto2911   "Eile"
#define en__Auto2911   ""
#define fr__Auto2911   ""
#define it__Auto2911   ""
#define es__Auto2911   ""
#define de__Auto2911   ""
#define nl__Auto2911   ""
#define pt__Auto2911   ""
#define xx__Auto2911   ""
#define en_Auto2912   "Name"
#define fr_Auto2912   "Nom"
#define it_Auto2912   "Name"
#define es_Auto2912   "Name"
#define de_Auto2912   "Name"
#define nl_Auto2912   "Name"
#define pt_Auto2912   "Name"
#define xx_Auto2912   "Name"
#define en__Auto2912   ""
#define fr__Auto2912   ""
#define it__Auto2912   ""
#define es__Auto2912   ""
#define de__Auto2912   ""
#define nl__Auto2912   ""
#define pt__Auto2912   ""
#define xx__Auto2912   ""
#define en_Auto2913   "Widget class"
#define fr_Auto2913   "Classe de widget"
#define it_Auto2913   "Widget class"
#define es_Auto2913   "Widget class"
#define de_Auto2913   "Widget class"
#define nl_Auto2913   "Widget class"
#define pt_Auto2913   "Widget class"
#define xx_Auto2913   "Widget class"
#define en__Auto2913   ""
#define fr__Auto2913   ""
#define it__Auto2913   ""
#define es__Auto2913   ""
#define de__Auto2913   ""
#define nl__Auto2913   ""
#define pt__Auto2913   ""
#define xx__Auto2913   ""
#include "vwselect.h"
static int	vfh[16];

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

}

public	int	vwselect_attach()
{
	if ( visual_initialise(3|512) == -1 )
		return(56);

	else	{
		visual_palette("/home/abal3/images/nuit.rgb",27);
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

public	int	vwselect_attach_mode(int mode)
{
	if ( visual_initialise(3|mode) == -1 )
		return(56);

	else	{
		visual_palette("/home/abal3/images/nuit.rgb",27);
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
	vfh[10] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct vwselect_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=17;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2898[i]=" ";
	_Context->msg_Auto2898[0]=en_Auto2898;
	_Context->msg_Auto2898[1]=fr_Auto2898;
	_Context->msg_Auto2898[2]=it_Auto2898;
	_Context->msg_Auto2898[3]=es_Auto2898;
	_Context->msg_Auto2898[4]=de_Auto2898;
	_Context->msg_Auto2898[5]=nl_Auto2898;
	_Context->msg_Auto2898[6]=pt_Auto2898;
	_Context->msg_Auto2898[7]=xx_Auto2898;
	_Context->hint_Auto2898[0]=en__Auto2898;
	_Context->hint_Auto2898[1]=fr__Auto2898;
	_Context->hint_Auto2898[2]=it__Auto2898;
	_Context->hint_Auto2898[3]=es__Auto2898;
	_Context->hint_Auto2898[4]=de__Auto2898;
	_Context->hint_Auto2898[5]=nl__Auto2898;
	_Context->hint_Auto2898[6]=pt__Auto2898;
	_Context->hint_Auto2898[7]=xx__Auto2898;
	for (i=0; i < 8; i++)_Context->msg_Auto2900[i]=" ";
	_Context->msg_Auto2900[0]=en_Auto2900;
	_Context->msg_Auto2900[1]=fr_Auto2900;
	_Context->msg_Auto2900[2]=it_Auto2900;
	_Context->msg_Auto2900[3]=es_Auto2900;
	_Context->msg_Auto2900[4]=de_Auto2900;
	_Context->msg_Auto2900[5]=nl_Auto2900;
	_Context->msg_Auto2900[6]=pt_Auto2900;
	_Context->msg_Auto2900[7]=xx_Auto2900;
	_Context->hint_Auto2900[0]=en__Auto2900;
	_Context->hint_Auto2900[1]=fr__Auto2900;
	_Context->hint_Auto2900[2]=it__Auto2900;
	_Context->hint_Auto2900[3]=es__Auto2900;
	_Context->hint_Auto2900[4]=de__Auto2900;
	_Context->hint_Auto2900[5]=nl__Auto2900;
	_Context->hint_Auto2900[6]=pt__Auto2900;
	_Context->hint_Auto2900[7]=xx__Auto2900;
	for (i=0; i < 8; i++)_Context->msg_Auto2901[i]=" ";
	_Context->msg_Auto2901[0]=en_Auto2901;
	_Context->msg_Auto2901[1]=fr_Auto2901;
	_Context->msg_Auto2901[2]=it_Auto2901;
	_Context->msg_Auto2901[3]=es_Auto2901;
	_Context->msg_Auto2901[4]=de_Auto2901;
	_Context->msg_Auto2901[5]=nl_Auto2901;
	_Context->msg_Auto2901[6]=pt_Auto2901;
	_Context->msg_Auto2901[7]=xx_Auto2901;
	_Context->hint_Auto2901[0]=en__Auto2901;
	_Context->hint_Auto2901[1]=fr__Auto2901;
	_Context->hint_Auto2901[2]=it__Auto2901;
	_Context->hint_Auto2901[3]=es__Auto2901;
	_Context->hint_Auto2901[4]=de__Auto2901;
	_Context->hint_Auto2901[5]=nl__Auto2901;
	_Context->hint_Auto2901[6]=pt__Auto2901;
	_Context->hint_Auto2901[7]=xx__Auto2901;
	for (i=0; i < 8; i++)_Context->msg_Auto2902[i]=" ";
	_Context->msg_Auto2902[0]=en_Auto2902;
	_Context->msg_Auto2902[1]=fr_Auto2902;
	_Context->msg_Auto2902[2]=it_Auto2902;
	_Context->msg_Auto2902[3]=es_Auto2902;
	_Context->msg_Auto2902[4]=de_Auto2902;
	_Context->msg_Auto2902[5]=nl_Auto2902;
	_Context->msg_Auto2902[6]=pt_Auto2902;
	_Context->msg_Auto2902[7]=xx_Auto2902;
	_Context->hint_Auto2902[0]=en__Auto2902;
	_Context->hint_Auto2902[1]=fr__Auto2902;
	_Context->hint_Auto2902[2]=it__Auto2902;
	_Context->hint_Auto2902[3]=es__Auto2902;
	_Context->hint_Auto2902[4]=de__Auto2902;
	_Context->hint_Auto2902[5]=nl__Auto2902;
	_Context->hint_Auto2902[6]=pt__Auto2902;
	_Context->hint_Auto2902[7]=xx__Auto2902;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2903[i]=" ";
	_Context->msg_Auto2903[0]=en_Auto2903;
	_Context->msg_Auto2903[1]=fr_Auto2903;
	_Context->msg_Auto2903[2]=it_Auto2903;
	_Context->msg_Auto2903[3]=es_Auto2903;
	_Context->msg_Auto2903[4]=de_Auto2903;
	_Context->msg_Auto2903[5]=nl_Auto2903;
	_Context->msg_Auto2903[6]=pt_Auto2903;
	_Context->msg_Auto2903[7]=xx_Auto2903;
	_Context->hint_Auto2903[0]=en__Auto2903;
	_Context->hint_Auto2903[1]=fr__Auto2903;
	_Context->hint_Auto2903[2]=it__Auto2903;
	_Context->hint_Auto2903[3]=es__Auto2903;
	_Context->hint_Auto2903[4]=de__Auto2903;
	_Context->hint_Auto2903[5]=nl__Auto2903;
	_Context->hint_Auto2903[6]=pt__Auto2903;
	_Context->hint_Auto2903[7]=xx__Auto2903;
	for (i=0; i < 8; i++)_Context->msg_TextFont[i]=" ";
	_Context->hint_TextFont[0]=en__TextFont;
	_Context->hint_TextFont[1]=fr__TextFont;
	for (i=0; i < 8; i++)_Context->msg_Auto2904[i]=" ";
	_Context->msg_Auto2904[0]=en_Auto2904;
	_Context->msg_Auto2904[1]=fr_Auto2904;
	_Context->msg_Auto2904[2]=it_Auto2904;
	_Context->msg_Auto2904[3]=es_Auto2904;
	_Context->msg_Auto2904[4]=de_Auto2904;
	_Context->msg_Auto2904[5]=nl_Auto2904;
	_Context->msg_Auto2904[6]=pt_Auto2904;
	_Context->msg_Auto2904[7]=xx_Auto2904;
	_Context->hint_Auto2904[0]=en__Auto2904;
	_Context->hint_Auto2904[1]=fr__Auto2904;
	_Context->hint_Auto2904[2]=it__Auto2904;
	_Context->hint_Auto2904[3]=es__Auto2904;
	_Context->hint_Auto2904[4]=de__Auto2904;
	_Context->hint_Auto2904[5]=nl__Auto2904;
	_Context->hint_Auto2904[6]=pt__Auto2904;
	_Context->hint_Auto2904[7]=xx__Auto2904;
	_Context->hint_AtX[0]=en__AtX;
	_Context->hint_AtY[0]=en__AtY;
	_Context->hint_Width[0]=en__Width;
	_Context->hint_Height[0]=en__Height;
	for (i=0; i < 8; i++)_Context->msg_Auto2905[i]=" ";
	_Context->msg_Auto2905[0]=en_Auto2905;
	_Context->msg_Auto2905[1]=fr_Auto2905;
	_Context->msg_Auto2905[2]=it_Auto2905;
	_Context->msg_Auto2905[3]=es_Auto2905;
	_Context->msg_Auto2905[4]=de_Auto2905;
	_Context->msg_Auto2905[5]=nl_Auto2905;
	_Context->msg_Auto2905[6]=pt_Auto2905;
	_Context->msg_Auto2905[7]=xx_Auto2905;
	_Context->hint_Auto2905[0]=en__Auto2905;
	_Context->hint_Auto2905[1]=fr__Auto2905;
	_Context->hint_Auto2905[2]=it__Auto2905;
	_Context->hint_Auto2905[3]=es__Auto2905;
	_Context->hint_Auto2905[4]=de__Auto2905;
	_Context->hint_Auto2905[5]=nl__Auto2905;
	_Context->hint_Auto2905[6]=pt__Auto2905;
	_Context->hint_Auto2905[7]=xx__Auto2905;
	for (i=0; i < 8; i++)_Context->msg_Auto2906[i]=" ";
	_Context->msg_Auto2906[0]=en_Auto2906;
	_Context->msg_Auto2906[1]=fr_Auto2906;
	_Context->msg_Auto2906[2]=it_Auto2906;
	_Context->msg_Auto2906[3]=es_Auto2906;
	_Context->msg_Auto2906[4]=de_Auto2906;
	_Context->msg_Auto2906[5]=nl_Auto2906;
	_Context->msg_Auto2906[6]=pt_Auto2906;
	_Context->msg_Auto2906[7]=xx_Auto2906;
	_Context->hint_Auto2906[0]=en__Auto2906;
	_Context->hint_Auto2906[1]=fr__Auto2906;
	_Context->hint_Auto2906[2]=it__Auto2906;
	_Context->hint_Auto2906[3]=es__Auto2906;
	_Context->hint_Auto2906[4]=de__Auto2906;
	_Context->hint_Auto2906[5]=nl__Auto2906;
	_Context->hint_Auto2906[6]=pt__Auto2906;
	_Context->hint_Auto2906[7]=xx__Auto2906;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2907[i]=" ";
	_Context->msg_Auto2907[0]=en_Auto2907;
	_Context->msg_Auto2907[1]=fr_Auto2907;
	_Context->msg_Auto2907[2]=it_Auto2907;
	_Context->msg_Auto2907[3]=es_Auto2907;
	_Context->msg_Auto2907[4]=de_Auto2907;
	_Context->msg_Auto2907[5]=nl_Auto2907;
	_Context->msg_Auto2907[6]=pt_Auto2907;
	_Context->msg_Auto2907[7]=xx_Auto2907;
	_Context->hint_Auto2907[0]=en__Auto2907;
	_Context->hint_Auto2907[1]=fr__Auto2907;
	_Context->hint_Auto2907[2]=it__Auto2907;
	_Context->hint_Auto2907[3]=es__Auto2907;
	_Context->hint_Auto2907[4]=de__Auto2907;
	_Context->hint_Auto2907[5]=nl__Auto2907;
	_Context->hint_Auto2907[6]=pt__Auto2907;
	_Context->hint_Auto2907[7]=xx__Auto2907;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2908[i]=" ";
	_Context->msg_Auto2908[0]=en_Auto2908;
	_Context->msg_Auto2908[1]=fr_Auto2908;
	_Context->msg_Auto2908[2]=it_Auto2908;
	_Context->msg_Auto2908[3]=es_Auto2908;
	_Context->msg_Auto2908[4]=de_Auto2908;
	_Context->msg_Auto2908[5]=nl_Auto2908;
	_Context->msg_Auto2908[6]=pt_Auto2908;
	_Context->msg_Auto2908[7]=xx_Auto2908;
	_Context->hint_Auto2908[0]=en__Auto2908;
	_Context->hint_Auto2908[1]=fr__Auto2908;
	_Context->hint_Auto2908[2]=it__Auto2908;
	_Context->hint_Auto2908[3]=es__Auto2908;
	_Context->hint_Auto2908[4]=de__Auto2908;
	_Context->hint_Auto2908[5]=nl__Auto2908;
	_Context->hint_Auto2908[6]=pt__Auto2908;
	_Context->hint_Auto2908[7]=xx__Auto2908;
	for (i=0; i < 8; i++)_Context->msg_Auto2909[i]=" ";
	_Context->msg_Auto2909[0]=en_Auto2909;
	_Context->msg_Auto2909[1]=fr_Auto2909;
	_Context->msg_Auto2909[2]=it_Auto2909;
	_Context->msg_Auto2909[3]=es_Auto2909;
	_Context->msg_Auto2909[4]=de_Auto2909;
	_Context->msg_Auto2909[5]=nl_Auto2909;
	_Context->msg_Auto2909[6]=pt_Auto2909;
	_Context->msg_Auto2909[7]=xx_Auto2909;
	_Context->hint_Auto2909[0]=en__Auto2909;
	_Context->hint_Auto2909[1]=fr__Auto2909;
	_Context->hint_Auto2909[2]=it__Auto2909;
	_Context->hint_Auto2909[3]=es__Auto2909;
	_Context->hint_Auto2909[4]=de__Auto2909;
	_Context->hint_Auto2909[5]=nl__Auto2909;
	_Context->hint_Auto2909[6]=pt__Auto2909;
	_Context->hint_Auto2909[7]=xx__Auto2909;
	for (i=0; i < 8; i++)_Context->msg_Auto2910[i]=" ";
	_Context->msg_Auto2910[0]=en_Auto2910;
	_Context->msg_Auto2910[1]=fr_Auto2910;
	_Context->msg_Auto2910[2]=it_Auto2910;
	_Context->msg_Auto2910[3]=es_Auto2910;
	_Context->msg_Auto2910[4]=de_Auto2910;
	_Context->msg_Auto2910[5]=nl_Auto2910;
	_Context->msg_Auto2910[6]=pt_Auto2910;
	_Context->msg_Auto2910[7]=xx_Auto2910;
	_Context->hint_Auto2910[0]=en__Auto2910;
	_Context->hint_Auto2910[1]=fr__Auto2910;
	_Context->hint_Auto2910[2]=it__Auto2910;
	_Context->hint_Auto2910[3]=es__Auto2910;
	_Context->hint_Auto2910[4]=de__Auto2910;
	_Context->hint_Auto2910[5]=nl__Auto2910;
	_Context->hint_Auto2910[6]=pt__Auto2910;
	_Context->hint_Auto2910[7]=xx__Auto2910;
	for (i=0; i < 8; i++)_Context->msg_Auto2911[i]=" ";
	_Context->msg_Auto2911[0]=en_Auto2911;
	_Context->msg_Auto2911[1]=fr_Auto2911;
	_Context->msg_Auto2911[2]=it_Auto2911;
	_Context->msg_Auto2911[3]=es_Auto2911;
	_Context->msg_Auto2911[4]=de_Auto2911;
	_Context->msg_Auto2911[5]=nl_Auto2911;
	_Context->msg_Auto2911[6]=pt_Auto2911;
	_Context->msg_Auto2911[7]=xx_Auto2911;
	_Context->hint_Auto2911[0]=en__Auto2911;
	_Context->hint_Auto2911[1]=fr__Auto2911;
	_Context->hint_Auto2911[2]=it__Auto2911;
	_Context->hint_Auto2911[3]=es__Auto2911;
	_Context->hint_Auto2911[4]=de__Auto2911;
	_Context->hint_Auto2911[5]=nl__Auto2911;
	_Context->hint_Auto2911[6]=pt__Auto2911;
	_Context->hint_Auto2911[7]=xx__Auto2911;
	for (i=0; i < 8; i++)_Context->msg_Auto2912[i]=" ";
	_Context->msg_Auto2912[0]=en_Auto2912;
	_Context->msg_Auto2912[1]=fr_Auto2912;
	_Context->msg_Auto2912[2]=it_Auto2912;
	_Context->msg_Auto2912[3]=es_Auto2912;
	_Context->msg_Auto2912[4]=de_Auto2912;
	_Context->msg_Auto2912[5]=nl_Auto2912;
	_Context->msg_Auto2912[6]=pt_Auto2912;
	_Context->msg_Auto2912[7]=xx_Auto2912;
	_Context->hint_Auto2912[0]=en__Auto2912;
	_Context->hint_Auto2912[1]=fr__Auto2912;
	_Context->hint_Auto2912[2]=it__Auto2912;
	_Context->hint_Auto2912[3]=es__Auto2912;
	_Context->hint_Auto2912[4]=de__Auto2912;
	_Context->hint_Auto2912[5]=nl__Auto2912;
	_Context->hint_Auto2912[6]=pt__Auto2912;
	_Context->hint_Auto2912[7]=xx__Auto2912;
	for (i=0; i < 8; i++)_Context->msg_Auto2913[i]=" ";
	_Context->msg_Auto2913[0]=en_Auto2913;
	_Context->msg_Auto2913[1]=fr_Auto2913;
	_Context->msg_Auto2913[2]=it_Auto2913;
	_Context->msg_Auto2913[3]=es_Auto2913;
	_Context->msg_Auto2913[4]=de_Auto2913;
	_Context->msg_Auto2913[5]=nl_Auto2913;
	_Context->msg_Auto2913[6]=pt_Auto2913;
	_Context->msg_Auto2913[7]=xx_Auto2913;
	_Context->hint_Auto2913[0]=en__Auto2913;
	_Context->hint_Auto2913[1]=fr__Auto2913;
	_Context->hint_Auto2913[2]=it__Auto2913;
	_Context->hint_Auto2913[3]=es__Auto2913;
	_Context->hint_Auto2913[4]=de__Auto2913;
	_Context->hint_Auto2913[5]=nl__Auto2913;
	_Context->hint_Auto2913[6]=pt__Auto2913;
	_Context->hint_Auto2913[7]=xx__Auto2913;
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
	visual_text(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+139,210,16,vfh[2],16,0,_Context->msg_Auto2898[_Context->language],strlen(_Context->msg_Auto2898[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+155,210,62,4);
	visual_filzone(_Context->x_WidgetProperties+251,_Context->y_WidgetProperties+254,1,1,27,0);
	visual_text(_Context->x_WidgetProperties+455,_Context->y_WidgetProperties+34,210,16,vfh[2],16,0,_Context->msg_Auto2900[_Context->language],strlen(_Context->msg_Auto2900[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+455,_Context->y_WidgetProperties+50,210,83,4);
	visual_text(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+224,660,16,vfh[2],16,0,_Context->msg_Auto2901[_Context->language],strlen(_Context->msg_Auto2901[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+240,660,140,4);
	visual_text(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+36,444,16,vfh[2],16,0,_Context->msg_Auto2902[_Context->language],strlen(_Context->msg_Auto2902[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+52,444,167,4);
	visual_frame(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+80,128+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+15+1,_Context->y_WidgetProperties+80+1,128,16,vfh[1],34,0,_Context->buffer_Identity,255,0);
	visual_select(_Context->x_WidgetProperties+222,_Context->y_WidgetProperties+80,120,140,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),768);
	visual_frame(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+132,424+2,64+2,5);
	visual_text(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+132+1,424,64,vfh[1],0,0,_Context->buffer_Hint,255,0);
	_Context->trigger_IsSpecial=visual_trigger_code(_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]));
	visual_check(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+108,190,16,vfh[2],28,28,_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]),_Context->value_IsSpecial|0);
	_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+60,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
	_Context->trigger_IsInterface=visual_trigger_code(_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]));
	visual_check(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+84,180,16,vfh[2],28,28,_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]),_Context->value_IsInterface|0);
	_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+352,182,16,vfh[2],16,28,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
	visual_text(_Context->x_WidgetProperties+465,_Context->y_WidgetProperties+162,14,21,vfh[2],16,0,_Context->msg_Auto2903[_Context->language],strlen(_Context->msg_Auto2903[_Context->language]),2);
	visual_select(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+259,126,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),768);
	visual_text(_Context->x_WidgetProperties+615,_Context->y_WidgetProperties+161,50,21,vfh[2],16,0,_Context->msg_Auto2904[_Context->language],strlen(_Context->msg_Auto2904[_Context->language]),2);
	visual_frame(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+179,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+463+1,_Context->y_WidgetProperties+179+1,35,16,vfh[1],34,0,_Context->buffer_AtX,7,0);
	visual_frame(_Context->x_WidgetProperties+508,_Context->y_WidgetProperties+179,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+508+1,_Context->y_WidgetProperties+179+1,35,16,vfh[1],34,0,_Context->buffer_AtY,7,0);
	visual_frame(_Context->x_WidgetProperties+563,_Context->y_WidgetProperties+179,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+563+1,_Context->y_WidgetProperties+179+1,35,16,vfh[1],34,0,_Context->buffer_Width,7,0);
	visual_frame(_Context->x_WidgetProperties+615,_Context->y_WidgetProperties+179,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+615+1,_Context->y_WidgetProperties+179+1,35,16,vfh[1],34,0,_Context->buffer_Height,7,0);
	visual_text(_Context->x_WidgetProperties+561,_Context->y_WidgetProperties+162,50,21,vfh[2],16,0,_Context->msg_Auto2905[_Context->language],strlen(_Context->msg_Auto2905[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+507,_Context->y_WidgetProperties+162,14,21,vfh[2],16,0,_Context->msg_Auto2906[_Context->language],strlen(_Context->msg_Auto2906[_Context->language]),2);
	visual_frame(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+261,190+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+463+1,_Context->y_WidgetProperties+261+1,190,16,vfh[1],0,0,_Context->buffer_StyleSheet,255,0);
	visual_select(_Context->x_WidgetProperties+225,_Context->y_WidgetProperties+260,120,140,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),768);
	visual_text(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+245,182,16,vfh[2],16,0,_Context->msg_Auto2907[_Context->language],strlen(_Context->msg_Auto2907[_Context->language]),2);
	visual_frame(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+311,641+2,32+2,5);
	visual_text(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+311+1,641,32,vfh[1],34,0,_Context->buffer_PayLoad,255,0);
	_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+352,182,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
	_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+224,_Context->y_WidgetProperties+352,224,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
	visual_text(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+298,168,16,vfh[2],16,0,_Context->msg_Auto2908[_Context->language],strlen(_Context->msg_Auto2908[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+464,_Context->y_WidgetProperties+247,154,16,vfh[2],16,0,_Context->msg_Auto2909[_Context->language],strlen(_Context->msg_Auto2909[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+118,171,16,vfh[2],16,0,_Context->msg_Auto2910[_Context->language],strlen(_Context->msg_Auto2910[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+226,_Context->y_WidgetProperties+247,70,16,vfh[2],16,0,_Context->msg_Auto2911[_Context->language],strlen(_Context->msg_Auto2911[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+66,154,16,vfh[2],16,0,_Context->msg_Auto2912[_Context->language],strlen(_Context->msg_Auto2912[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+221,_Context->y_WidgetProperties+65,135,16,vfh[2],16,0,_Context->msg_Auto2913[_Context->language],strlen(_Context->msg_Auto2913[_Context->language]),2);
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
	aide_en_ligne(_Context->x_WidgetProperties+670-largeur*8-75,_Context->y_WidgetProperties+108+30,nblig,msg_help[visual_national_language(-1)]);
	return(-1);
}


public	int	vwselect_event(
struct vwselect_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsSpecial == mb ) return(4);
		if (_Context->trigger_IsLock == mb ) return(5);
		if (_Context->trigger_IsInterface == mb ) return(6);
		if (_Context->trigger_IsBold == mb ) return(7);
		if (_Context->trigger_IswResize == mb ) return(16);
		if (_Context->trigger_IshResize == mb ) return(17);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (( mx >= (_Context->x_WidgetProperties+15) ) 
	&&  ( my >= (_Context->y_WidgetProperties+80) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+15+128) ) 
	&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
		return(1); /* Identity */
		}
	if (( mx >= (_Context->x_WidgetProperties+222+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+80) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+222+120) ) 
	&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
		return(2); /* WidgetClass */
		}
	if (( mx >= (_Context->x_WidgetProperties+14) ) 
	&&  ( my >= (_Context->y_WidgetProperties+132) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+14+424) ) 
	&&  ( my <= (_Context->y_WidgetProperties+132+64))) {
		return(3); /* Hint */
		}
	if (( mx >= (_Context->x_WidgetProperties+468) ) 
	&&  ( my >= (_Context->y_WidgetProperties+108) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+468+190) ) 
	&&  ( my <= (_Context->y_WidgetProperties+108+16))) {
		return(4); /* IsSpecial */
		}
	if (( mx >= (_Context->x_WidgetProperties+468) ) 
	&&  ( my >= (_Context->y_WidgetProperties+60) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+468+182) ) 
	&&  ( my <= (_Context->y_WidgetProperties+60+16))) {
		return(5); /* IsLock */
		}
	if (( mx >= (_Context->x_WidgetProperties+468) ) 
	&&  ( my >= (_Context->y_WidgetProperties+84) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+468+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+84+16))) {
		return(6); /* IsInterface */
		}
	if (( mx >= (_Context->x_WidgetProperties+460) ) 
	&&  ( my >= (_Context->y_WidgetProperties+352) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+460+182) ) 
	&&  ( my <= (_Context->y_WidgetProperties+352+16))) {
		return(7); /* IsBold */
		}
	if (( mx >= (_Context->x_WidgetProperties+14+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+259) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+14+126) ) 
	&&  ( my <= (_Context->y_WidgetProperties+259+16))) {
		return(8); /* TextFont */
		}
	if (( mx >= (_Context->x_WidgetProperties+463) ) 
	&&  ( my >= (_Context->y_WidgetProperties+179) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+463+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+179+16))) {
		return(9); /* AtX */
		}
	if (( mx >= (_Context->x_WidgetProperties+508) ) 
	&&  ( my >= (_Context->y_WidgetProperties+179) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+508+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+179+16))) {
		return(10); /* AtY */
		}
	if (( mx >= (_Context->x_WidgetProperties+563) ) 
	&&  ( my >= (_Context->y_WidgetProperties+179) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+563+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+179+16))) {
		return(11); /* Width */
		}
	if (( mx >= (_Context->x_WidgetProperties+615) ) 
	&&  ( my >= (_Context->y_WidgetProperties+179) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+615+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+179+16))) {
		return(12); /* Height */
		}
	if (( mx >= (_Context->x_WidgetProperties+463) ) 
	&&  ( my >= (_Context->y_WidgetProperties+261) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+463+190) ) 
	&&  ( my <= (_Context->y_WidgetProperties+261+16))) {
		return(13); /* StyleSheet */
		}
	if (( mx >= (_Context->x_WidgetProperties+225+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+260) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+225+120) ) 
	&&  ( my <= (_Context->y_WidgetProperties+260+16))) {
		return(14); /* Align */
		}
	if (( mx >= (_Context->x_WidgetProperties+13) ) 
	&&  ( my >= (_Context->y_WidgetProperties+311) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+13+641) ) 
	&&  ( my <= (_Context->y_WidgetProperties+311+32))) {
		return(15); /* PayLoad */
		}
	if (( mx >= (_Context->x_WidgetProperties+20) ) 
	&&  ( my >= (_Context->y_WidgetProperties+352) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+20+182) ) 
	&&  ( my <= (_Context->y_WidgetProperties+352+16))) {
		return(16); /* IswResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+224) ) 
	&&  ( my >= (_Context->y_WidgetProperties+352) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+224+224) ) 
	&&  ( my <= (_Context->y_WidgetProperties+352+16))) {
		return(17); /* IshResize */
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
				/* Identity */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+15+1,_Context->y_WidgetProperties+80+1,128,16,vfh[1],_Context->buffer_Identity,255);
			break;
			case	0x2 :
				/* WidgetClass */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+222,_Context->y_WidgetProperties+80,120,140,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),774);
				if(change_widget_class(&_Context->value_WidgetClass)!=0){
				return(26);
				}
				break;
			case	0x3 :
				/* Hint */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+132+1,424,64,vfh[1],_Context->buffer_Hint,255);
			break;
			case	0x4 :
				/* IsSpecial */
				visual_check(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+108,190,16,vfh[2],28,28,_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]),(_Context->value_IsSpecial |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsSpecial=visual_trigger_code(_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]));
	visual_check(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+108,190,16,vfh[2],28,28,_Context->msg_IsSpecial[_Context->language],strlen(_Context->msg_IsSpecial[_Context->language]),_Context->value_IsSpecial|0);
				break;
			case	0x5 :
				/* IsLock */
				visual_check(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+60,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),(_Context->value_IsLock |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+60,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
				break;
			case	0x6 :
				/* IsInterface */
				visual_check(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+84,180,16,vfh[2],28,28,_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]),(_Context->value_IsInterface |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsInterface=visual_trigger_code(_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]));
	visual_check(_Context->x_WidgetProperties+468,_Context->y_WidgetProperties+84,180,16,vfh[2],28,28,_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]),_Context->value_IsInterface|0);
				break;
			case	0x7 :
				/* IsBold */
				visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+352,182,16,vfh[2],16,28,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),(_Context->value_IsBold |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+352,182,16,vfh[2],16,28,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
				break;
			case	0x8 :
				/* TextFont */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+259,126,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),770);
				break;
			case	0x9 :
				/* AtX */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+463+1,_Context->y_WidgetProperties+179+1,35,16,vfh[1],_Context->buffer_AtX,7);
			break;
			case	0xa :
				/* AtY */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+508+1,_Context->y_WidgetProperties+179+1,35,16,vfh[1],_Context->buffer_AtY,7);
			break;
			case	0xb :
				/* Width */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+563+1,_Context->y_WidgetProperties+179+1,35,16,vfh[1],_Context->buffer_Width,7);
			break;
			case	0xc :
				/* Height */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+615+1,_Context->y_WidgetProperties+179+1,35,16,vfh[1],_Context->buffer_Height,7);
			break;
			case	0xd :
				/* StyleSheet */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+463+1,_Context->y_WidgetProperties+261+1,190,16,vfh[1],_Context->buffer_StyleSheet,255);
			break;
			case	0xe :
				/* Align */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+225,_Context->y_WidgetProperties+260,120,140,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),774);
				break;
			case	0xf :
				/* PayLoad */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+13+1,_Context->y_WidgetProperties+311+1,641,32,vfh[1],_Context->buffer_PayLoad,255);
			break;
			case	0x10 :
				/* IswResize */
				visual_check(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+352,182,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),(_Context->value_IswResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+20,_Context->y_WidgetProperties+352,182,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
				break;
			case	0x11 :
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
			_Context->focus_item=17;
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
					case	0x1 :
						if (Identity_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2 :
						if (WidgetClass_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Hint_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (IsSpecial_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (IsLock_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (IsInterface_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (TextFont_help(_Context) != 0) { continue; }
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
						if (StyleSheet_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (Align_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (PayLoad_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (IswResize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (IshResize_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Identity */
					continue;
				case	0x2 :
					/* WidgetClass */
					continue;
				case	0x3 :
					/* Hint */
					continue;
				case	0x4 :
					/* IsSpecial */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsSpecial += 1;
						_Context->value_IsSpecial &= 1;
						}
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_IsSpecial_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* IsLock */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsLock += 1;
						_Context->value_IsLock &= 1;
						}
					continue;
				case	0x6 :
					/* IsInterface */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsInterface += 1;
						_Context->value_IsInterface &= 1;
						}
					continue;
				case	0x7 :
					/* IsBold */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsBold += 1;
						_Context->value_IsBold &= 1;
						}
					continue;
				case	0x8 :
					/* TextFont */
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
					/* StyleSheet */
					continue;
				case	0xe :
					/* Align */
					continue;
				case	0xf :
					/* PayLoad */
					continue;
				case	0x10 :
					/* IswResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IswResize += 1;
						_Context->value_IswResize &= 1;
						}
					continue;
				case	0x11 :
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
