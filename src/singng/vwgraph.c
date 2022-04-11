
#ifndef _vwgraph_c
#define _vwgraph_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vwgraph.xml                                              */
/* Target         : vwgraph.c                                                */
/* Identification : 0.0-1177511938-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "sing.h"
#include "singform.h"
#include "singprot.h"
#define en_WidgetProperties   "Graph - Properties"
#define fr_WidgetProperties   "Graph - Propri‚t‚s"
#define it_WidgetProperties   "Graph widget - Properties"
#define es_WidgetProperties   "Graph widget - Properties"
#define de_WidgetProperties   "Graph widget - Properties"
#define nl_WidgetProperties   "Graph widget - Properties"
#define pt_WidgetProperties   "Graph widget - Properties"
#define xx_WidgetProperties   "Graph widget - Properties"
#define en__WidgetProperties   ""
#define fr__WidgetProperties   ""
#define it__WidgetProperties   ""
#define es__WidgetProperties   ""
#define de__WidgetProperties   ""
#define nl__WidgetProperties   ""
#define pt__WidgetProperties   ""
#define xx__WidgetProperties   ""
#define en_Auto2780   "Position and Dimension"
#define fr_Auto2780   "Position et Dimension"
#define it_Auto2780   "Position and Dimension"
#define es_Auto2780   "Position and Dimension"
#define de_Auto2780   "Position and Dimension"
#define nl_Auto2780   "Position and Dimension"
#define pt_Auto2780   "Position and Dimension"
#define xx_Auto2780   "Position and Dimension"
#define en__Auto2780   ""
#define fr__Auto2780   ""
#define it__Auto2780   ""
#define es__Auto2780   ""
#define de__Auto2780   ""
#define nl__Auto2780   ""
#define pt__Auto2780   ""
#define xx__Auto2780   ""
#define en_Auto2782   "Behaviour"
#define fr_Auto2782   "Comportement"
#define it_Auto2782   ""
#define es_Auto2782   ""
#define de_Auto2782   ""
#define nl_Auto2782   ""
#define pt_Auto2782   ""
#define xx_Auto2782   ""
#define en__Auto2782   ""
#define fr__Auto2782   ""
#define it__Auto2782   ""
#define es__Auto2782   ""
#define de__Auto2782   ""
#define nl__Auto2782   ""
#define pt__Auto2782   ""
#define xx__Auto2782   ""
#define en_Auto2783   "Appearence"
#define fr_Auto2783   "Apparence"
#define it_Auto2783   ""
#define es_Auto2783   ""
#define de_Auto2783   ""
#define nl_Auto2783   ""
#define pt_Auto2783   ""
#define xx_Auto2783   ""
#define en__Auto2783   ""
#define fr__Auto2783   ""
#define it__Auto2783   ""
#define es__Auto2783   ""
#define de__Auto2783   ""
#define nl__Auto2783   ""
#define pt__Auto2783   ""
#define xx__Auto2783   ""
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
#define en_Auto2786   "General"
#define fr_Auto2786   "G‚n‚ral"
#define it_Auto2786   ""
#define es_Auto2786   ""
#define de_Auto2786   ""
#define nl_Auto2786   ""
#define pt_Auto2786   ""
#define xx_Auto2786   ""
#define en__Auto2786   ""
#define fr__Auto2786   ""
#define it__Auto2786   ""
#define es__Auto2786   ""
#define de__Auto2786   ""
#define nl__Auto2786   ""
#define pt__Auto2786   ""
#define xx__Auto2786   ""
#define en_Identity   ""
#define en__Identity   ""
#define en__WidgetClass   ""
#define en__Type   ""
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
#define en_TextColour   ""
#define en__TextColour   ""
#define en_Background   ""
#define en__Background   ""
#define en_Auto2787   "X"
#define fr_Auto2787   "X"
#define it_Auto2787   "Position"
#define es_Auto2787   "Position"
#define de_Auto2787   "Position"
#define nl_Auto2787   "Position"
#define pt_Auto2787   "Position"
#define xx_Auto2787   "Aite"
#define en__Auto2787   ""
#define fr__Auto2787   ""
#define it__Auto2787   ""
#define es__Auto2787   ""
#define de__Auto2787   ""
#define nl__Auto2787   ""
#define pt__Auto2787   ""
#define xx__Auto2787   ""
#define en_StyleSheet   ""
#define fr_StyleSheet   ""
#define en__StyleSheet   ""
#define fr__StyleSheet   ""
#define en_Auto2788   "Height"
#define fr_Auto2788   "Hauteur"
#define it_Auto2788   "Position"
#define es_Auto2788   "Position"
#define de_Auto2788   "Position"
#define nl_Auto2788   "Position"
#define pt_Auto2788   "Position"
#define xx_Auto2788   "Aite"
#define en__Auto2788   ""
#define fr__Auto2788   ""
#define it__Auto2788   ""
#define es__Auto2788   ""
#define de__Auto2788   ""
#define nl__Auto2788   ""
#define pt__Auto2788   ""
#define xx__Auto2788   ""
#define en_Auto2789   "Width"
#define fr_Auto2789   "Largeur"
#define it_Auto2789   "Position"
#define es_Auto2789   "Position"
#define de_Auto2789   "Position"
#define nl_Auto2789   "Position"
#define pt_Auto2789   "Position"
#define xx_Auto2789   "Aite"
#define en__Auto2789   ""
#define fr__Auto2789   ""
#define it__Auto2789   ""
#define es__Auto2789   ""
#define de__Auto2789   ""
#define nl__Auto2789   ""
#define pt__Auto2789   ""
#define xx__Auto2789   ""
#define en_Auto2790   "Y"
#define fr_Auto2790   "Y"
#define it_Auto2790   "Position"
#define es_Auto2790   "Position"
#define de_Auto2790   "Position"
#define nl_Auto2790   "Position"
#define pt_Auto2790   "Position"
#define xx_Auto2790   "Aite"
#define en__Auto2790   ""
#define fr__Auto2790   ""
#define it__Auto2790   ""
#define es__Auto2790   ""
#define de__Auto2790   ""
#define nl__Auto2790   ""
#define pt__Auto2790   ""
#define xx__Auto2790   ""
#define en_Auto2791   "Fore"
#define fr_Auto2791   "Texte"
#define it_Auto2791   "Colour"
#define es_Auto2791   "Colour"
#define de_Auto2791   "Colour"
#define nl_Auto2791   "Colour"
#define pt_Auto2791   "Colour"
#define xx_Auto2791   "Dath Teacs"
#define en__Auto2791   ""
#define fr__Auto2791   ""
#define it__Auto2791   ""
#define es__Auto2791   ""
#define de__Auto2791   ""
#define nl__Auto2791   ""
#define pt__Auto2791   ""
#define xx__Auto2791   ""
#define en_fgSelect   "Colors"
#define fr_fgSelect   "Couleurs"
#define it_fgSelect   "fg"
#define es_fgSelect   "fg"
#define de_fgSelect   "fg"
#define nl_fgSelect   "fg"
#define pt_fgSelect   "fg"
#define xx_fgSelect   "fg"
#define en__fgSelect   ""
#define fr__fgSelect   ""
#define it__fgSelect   ""
#define es__fgSelect   ""
#define de__fgSelect   ""
#define nl__fgSelect   ""
#define pt__fgSelect   ""
#define xx__fgSelect   ""
#define en_Auto2792   "Back"
#define fr_Auto2792   "Fond"
#define it_Auto2792   "Background"
#define es_Auto2792   "Background"
#define de_Auto2792   "Background"
#define nl_Auto2792   "Background"
#define pt_Auto2792   "Background"
#define xx_Auto2792   "Dath culaidh"
#define en__Auto2792   ""
#define fr__Auto2792   ""
#define it__Auto2792   ""
#define es__Auto2792   ""
#define de__Auto2792   ""
#define nl__Auto2792   ""
#define pt__Auto2792   ""
#define xx__Auto2792   ""
#define en_Auto2793   "Explicit style"
#define fr_Auto2793   "Style explicite"
#define it_Auto2793   "Style"
#define es_Auto2793   "Style"
#define de_Auto2793   "Style"
#define nl_Auto2793   "Style"
#define pt_Auto2793   "Style"
#define xx_Auto2793   "Style"
#define en__Auto2793   ""
#define fr__Auto2793   ""
#define it__Auto2793   ""
#define es__Auto2793   ""
#define de__Auto2793   ""
#define nl__Auto2793   ""
#define pt__Auto2793   ""
#define xx__Auto2793   ""
#define en_Auto2794   "Hint"
#define fr_Auto2794   "Infobulle"
#define it_Auto2794   "Hint"
#define es_Auto2794   "Hint"
#define de_Auto2794   "Hint"
#define nl_Auto2794   "Hint"
#define pt_Auto2794   "Hint"
#define xx_Auto2794   "Hint"
#define en__Auto2794   ""
#define fr__Auto2794   ""
#define it__Auto2794   ""
#define es__Auto2794   ""
#define de__Auto2794   ""
#define nl__Auto2794   ""
#define pt__Auto2794   ""
#define xx__Auto2794   ""
#define en_Auto2795   "Name"
#define fr_Auto2795   "Nom"
#define it_Auto2795   "Identity"
#define es_Auto2795   "Identity"
#define de_Auto2795   "Identity"
#define nl_Auto2795   "Identity"
#define pt_Auto2795   "Identity"
#define xx_Auto2795   "Ainm"
#define en__Auto2795   ""
#define fr__Auto2795   ""
#define it__Auto2795   ""
#define es__Auto2795   ""
#define de__Auto2795   ""
#define nl__Auto2795   ""
#define pt__Auto2795   ""
#define xx__Auto2795   ""
#define en_Auto2796   "Widget class"
#define fr_Auto2796   "Classe de widget"
#define it_Auto2796   "Class"
#define es_Auto2796   "Class"
#define de_Auto2796   "Class"
#define nl_Auto2796   "Class"
#define pt_Auto2796   "Class"
#define xx_Auto2796   "Clais"
#define en__Auto2796   ""
#define fr__Auto2796   ""
#define it__Auto2796   ""
#define es__Auto2796   ""
#define de__Auto2796   ""
#define nl__Auto2796   ""
#define pt__Auto2796   ""
#define xx__Auto2796   ""
#define en_Auto2797   "Type"
#define fr_Auto2797   "Type"
#define it_Auto2797   "Storage/Action Type"
#define es_Auto2797   "Storage/Action Type"
#define de_Auto2797   "Storage/Action Type"
#define nl_Auto2797   "Storage/Action Type"
#define pt_Auto2797   "Storage/Action Type"
#define xx_Auto2797   "Storage/Action Type"
#define en__Auto2797   ""
#define fr__Auto2797   ""
#define it__Auto2797   ""
#define es__Auto2797   ""
#define de__Auto2797   ""
#define nl__Auto2797   ""
#define pt__Auto2797   ""
#define xx__Auto2797   ""
#include "vwgraph.h"
static int	vfh[16];

/*	------------------------	*/
/*	p o s i t i o n _ a t ()	*/
/*	------------------------	*/
void	vwgraph_position_at(struct vwgraph_context * _Context,int x,int y){
	_Context->x_WidgetProperties=x;
	_Context->y_WidgetProperties=y;

}

/*	----------------	*/
/*	S e t V a r s ()	*/
/*	----------------	*/
void	vwgraph_SetVars(struct vwgraph_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	visual_signature("WWWW","WWWW");
	visual_transferin(_Context->buffer_AtX,7,pSpecificWidgetProperties->pAtX);
	visual_transferin(_Context->buffer_AtY,7,pSpecificWidgetProperties->pAtY);
	visual_transferin(_Context->buffer_Width,7,pSpecificWidgetProperties->pWidth);
	visual_transferin(_Context->buffer_Height,7,pSpecificWidgetProperties->pHeight);
	visual_signature("WWS","WWS");
	visual_transferin(_Context->buffer_TextColour,6,pSpecificWidgetProperties->pTextColour);
	visual_transferin(_Context->buffer_Background,6,pSpecificWidgetProperties->pBackground);
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
void	vwgraph_GetVars(struct vwgraph_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	visual_signature("WWWW","WWWW");
	visual_transferout(_Context->buffer_AtX,7,pSpecificWidgetProperties->pAtX);
	visual_transferout(_Context->buffer_AtY,7,pSpecificWidgetProperties->pAtY);
	visual_transferout(_Context->buffer_Width,7,pSpecificWidgetProperties->pWidth);
	visual_transferout(_Context->buffer_Height,7,pSpecificWidgetProperties->pHeight);
	visual_signature("WWS","WWS");
	visual_transferout(_Context->buffer_TextColour,6,pSpecificWidgetProperties->pTextColour);
	visual_transferout(_Context->buffer_Background,6,pSpecificWidgetProperties->pBackground);
	visual_transferout(_Context->buffer_Identity,255,pSpecificWidgetProperties->pIdentity);
	visual_signature("SS","SS");
	visual_transferout(_Context->buffer_StyleSheet,255,pSpecificWidgetProperties->pStyleSheet);
	visual_transferout(_Context->buffer_Hint,255,pSpecificWidgetProperties->pHint);
	if(pSpecificWidgetProperties->pWidgetClass!=(char*)0)
	*((int*)pSpecificWidgetProperties->pWidgetClass)=_Context->value_WidgetClass;
	if(pSpecificWidgetProperties->pType!=(char*)0)
	*((int*)pSpecificWidgetProperties->pType)=_Context->value_Type;
	if(pSpecificWidgetProperties->pIsLock!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsLock)=_Context->value_IsLock;
	if(pSpecificWidgetProperties->pIswResize!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIswResize)=_Context->value_IswResize;
	if(pSpecificWidgetProperties->pIshResize!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIshResize)=_Context->value_IshResize;

}

public	int	vwgraph_attach()
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

public	int	vwgraph_attach_mode(int mode)
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

public	int	vwgraph_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	vwgraph_create(struct vwgraph_context **cptr)
{

	int i;
	struct vwgraph_context * _Context=(struct vwgraph_context*)0;
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
	if (!(_Context = allocate( sizeof( struct vwgraph_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=16;
		_Context->value_IswResize=0;
		_Context->value_IshResize=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Identity+i)=' ';
		_Context->value_WidgetClass=0;
		_Context->value_Type=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Hint+i)=' ';
		_Context->value_IsLock=0;
		for (i=0; i < 7; i++)  *(_Context->buffer_AtX+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_AtY+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Width+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Height+i)=' ';
		for (i=0; i < 6; i++)  *(_Context->buffer_TextColour+i)=' ';
		for (i=0; i < 6; i++)  *(_Context->buffer_Background+i)=' ';
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
	_Context->h_WidgetProperties=410;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2780[i]=" ";
	_Context->msg_Auto2780[0]=en_Auto2780;
	_Context->msg_Auto2780[1]=fr_Auto2780;
	_Context->msg_Auto2780[2]=it_Auto2780;
	_Context->msg_Auto2780[3]=es_Auto2780;
	_Context->msg_Auto2780[4]=de_Auto2780;
	_Context->msg_Auto2780[5]=nl_Auto2780;
	_Context->msg_Auto2780[6]=pt_Auto2780;
	_Context->msg_Auto2780[7]=xx_Auto2780;
	_Context->hint_Auto2780[0]=en__Auto2780;
	_Context->hint_Auto2780[1]=fr__Auto2780;
	_Context->hint_Auto2780[2]=it__Auto2780;
	_Context->hint_Auto2780[3]=es__Auto2780;
	_Context->hint_Auto2780[4]=de__Auto2780;
	_Context->hint_Auto2780[5]=nl__Auto2780;
	_Context->hint_Auto2780[6]=pt__Auto2780;
	_Context->hint_Auto2780[7]=xx__Auto2780;
	for (i=0; i < 8; i++)_Context->msg_Auto2782[i]=" ";
	_Context->msg_Auto2782[0]=en_Auto2782;
	_Context->msg_Auto2782[1]=fr_Auto2782;
	_Context->msg_Auto2782[2]=it_Auto2782;
	_Context->msg_Auto2782[3]=es_Auto2782;
	_Context->msg_Auto2782[4]=de_Auto2782;
	_Context->msg_Auto2782[5]=nl_Auto2782;
	_Context->msg_Auto2782[6]=pt_Auto2782;
	_Context->msg_Auto2782[7]=xx_Auto2782;
	_Context->hint_Auto2782[0]=en__Auto2782;
	_Context->hint_Auto2782[1]=fr__Auto2782;
	_Context->hint_Auto2782[2]=it__Auto2782;
	_Context->hint_Auto2782[3]=es__Auto2782;
	_Context->hint_Auto2782[4]=de__Auto2782;
	_Context->hint_Auto2782[5]=nl__Auto2782;
	_Context->hint_Auto2782[6]=pt__Auto2782;
	_Context->hint_Auto2782[7]=xx__Auto2782;
	for (i=0; i < 8; i++)_Context->msg_Auto2783[i]=" ";
	_Context->msg_Auto2783[0]=en_Auto2783;
	_Context->msg_Auto2783[1]=fr_Auto2783;
	_Context->msg_Auto2783[2]=it_Auto2783;
	_Context->msg_Auto2783[3]=es_Auto2783;
	_Context->msg_Auto2783[4]=de_Auto2783;
	_Context->msg_Auto2783[5]=nl_Auto2783;
	_Context->msg_Auto2783[6]=pt_Auto2783;
	_Context->msg_Auto2783[7]=xx_Auto2783;
	_Context->hint_Auto2783[0]=en__Auto2783;
	_Context->hint_Auto2783[1]=fr__Auto2783;
	_Context->hint_Auto2783[2]=it__Auto2783;
	_Context->hint_Auto2783[3]=es__Auto2783;
	_Context->hint_Auto2783[4]=de__Auto2783;
	_Context->hint_Auto2783[5]=nl__Auto2783;
	_Context->hint_Auto2783[6]=pt__Auto2783;
	_Context->hint_Auto2783[7]=xx__Auto2783;
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
	_Context->hint_Identity[0]=en__Identity;
	for (i=0; i < 8; i++)_Context->msg_WidgetClass[i]=" ";
	_Context->hint_WidgetClass[0]=en__WidgetClass;
	for (i=0; i < 8; i++)_Context->msg_Type[i]=" ";
	_Context->hint_Type[0]=en__Type;
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
	_Context->hint_TextColour[0]=en__TextColour;
	_Context->hint_Background[0]=en__Background;
	for (i=0; i < 8; i++)_Context->msg_Auto2787[i]=" ";
	_Context->msg_Auto2787[0]=en_Auto2787;
	_Context->msg_Auto2787[1]=fr_Auto2787;
	_Context->msg_Auto2787[2]=it_Auto2787;
	_Context->msg_Auto2787[3]=es_Auto2787;
	_Context->msg_Auto2787[4]=de_Auto2787;
	_Context->msg_Auto2787[5]=nl_Auto2787;
	_Context->msg_Auto2787[6]=pt_Auto2787;
	_Context->msg_Auto2787[7]=xx_Auto2787;
	_Context->hint_Auto2787[0]=en__Auto2787;
	_Context->hint_Auto2787[1]=fr__Auto2787;
	_Context->hint_Auto2787[2]=it__Auto2787;
	_Context->hint_Auto2787[3]=es__Auto2787;
	_Context->hint_Auto2787[4]=de__Auto2787;
	_Context->hint_Auto2787[5]=nl__Auto2787;
	_Context->hint_Auto2787[6]=pt__Auto2787;
	_Context->hint_Auto2787[7]=xx__Auto2787;
	_Context->hint_StyleSheet[0]=en__StyleSheet;
	_Context->hint_StyleSheet[1]=fr__StyleSheet;
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
	return(0);
}

public 	int	vwgraph_hide(struct vwgraph_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;

	return(result);
}

public	int	vwgraph_remove(struct vwgraph_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}

public	int	vwgraph_show(struct vwgraph_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,410,"widget_frame",_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]))) != 0)
) {
		visual_window(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,410,vfh[2],_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]),0x4);
		}
	visual_text(_Context->x_WidgetProperties+452,_Context->y_WidgetProperties+131,210,16,vfh[2],16,0,_Context->msg_Auto2780[_Context->language],strlen(_Context->msg_Auto2780[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+452,_Context->y_WidgetProperties+147,210,57,4);
	visual_filzone(_Context->x_WidgetProperties+249,_Context->y_WidgetProperties+279,1,1,27,0);
	visual_text(_Context->x_WidgetProperties+452,_Context->y_WidgetProperties+46,209,16,vfh[2],16,0,_Context->msg_Auto2782[_Context->language],strlen(_Context->msg_Auto2782[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+452,_Context->y_WidgetProperties+62,209,62,4);
	visual_text(_Context->x_WidgetProperties+5,_Context->y_WidgetProperties+211,656,16,vfh[2],16,0,_Context->msg_Auto2783[_Context->language],strlen(_Context->msg_Auto2783[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+5,_Context->y_WidgetProperties+227,656,79,4);
	visual_filzone(_Context->x_WidgetProperties+249,_Context->y_WidgetProperties+279,1,1,27,0);
	_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+16,_Context->y_WidgetProperties+277,165,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
	_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+219,_Context->y_WidgetProperties+276,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
	visual_filzone(_Context->x_WidgetProperties+245,_Context->y_WidgetProperties+281,1,1,27,0);
	visual_text(_Context->x_WidgetProperties+4,_Context->y_WidgetProperties+46,443,16,vfh[2],16,0,_Context->msg_Auto2786[_Context->language],strlen(_Context->msg_Auto2786[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+4,_Context->y_WidgetProperties+62,443,142,4);
	visual_frame(_Context->x_WidgetProperties+10,_Context->y_WidgetProperties+92,128+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+10+1,_Context->y_WidgetProperties+92+1,128,16,vfh[1],34,0,_Context->buffer_Identity,255,0);
	visual_select(_Context->x_WidgetProperties+168,_Context->y_WidgetProperties+92,120,140,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),768);
	visual_select(_Context->x_WidgetProperties+316,_Context->y_WidgetProperties+92,120,140,vfh[2],0,0,parse_selection(WidgetTypeList,&_Context->value_Type),768);
	visual_frame(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+140,424+2,48+2,5);
	visual_text(_Context->x_WidgetProperties+12+1,_Context->y_WidgetProperties+140+1,424,48,vfh[1],0,0,_Context->buffer_Hint,255,0);
	_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+91,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
	visual_frame(_Context->x_WidgetProperties+458,_Context->y_WidgetProperties+171,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+458+1,_Context->y_WidgetProperties+171+1,35,16,vfh[1],34,0,_Context->buffer_AtX,7,0);
	visual_frame(_Context->x_WidgetProperties+502,_Context->y_WidgetProperties+171,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+502+1,_Context->y_WidgetProperties+171+1,35,16,vfh[1],34,0,_Context->buffer_AtY,7,0);
	visual_frame(_Context->x_WidgetProperties+563,_Context->y_WidgetProperties+172,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+563+1,_Context->y_WidgetProperties+172+1,35,16,vfh[1],34,0,_Context->buffer_Width,7,0);
	visual_frame(_Context->x_WidgetProperties+610,_Context->y_WidgetProperties+172,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+610+1,_Context->y_WidgetProperties+172+1,35,16,vfh[1],34,0,_Context->buffer_Height,7,0);
	visual_frame(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+249,42+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+12+1,_Context->y_WidgetProperties+249+1,42,16,vfh[1],34,0,_Context->buffer_TextColour,6,0);
	visual_frame(_Context->x_WidgetProperties+102,_Context->y_WidgetProperties+249,42+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+102+1,_Context->y_WidgetProperties+249+1,42,16,vfh[1],34,0,_Context->buffer_Background,6,0);
	visual_text(_Context->x_WidgetProperties+460,_Context->y_WidgetProperties+157,14,21,vfh[2],16,0,_Context->msg_Auto2787[_Context->language],strlen(_Context->msg_Auto2787[_Context->language]),2);
	visual_frame(_Context->x_WidgetProperties+165,_Context->y_WidgetProperties+249,216+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+165+1,_Context->y_WidgetProperties+249+1,216,16,vfh[1],0,0,_Context->buffer_StyleSheet,255,0);
	visual_text(_Context->x_WidgetProperties+610,_Context->y_WidgetProperties+159,50,16,vfh[2],16,0,_Context->msg_Auto2788[_Context->language],strlen(_Context->msg_Auto2788[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+561,_Context->y_WidgetProperties+157,52,21,vfh[2],16,0,_Context->msg_Auto2789[_Context->language],strlen(_Context->msg_Auto2789[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+502,_Context->y_WidgetProperties+157,14,21,vfh[2],16,0,_Context->msg_Auto2790[_Context->language],strlen(_Context->msg_Auto2790[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+233,42,16,vfh[2],16,0,_Context->msg_Auto2791[_Context->language],strlen(_Context->msg_Auto2791[_Context->language]),2);
	_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+57,_Context->y_WidgetProperties+249,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
	visual_text(_Context->x_WidgetProperties+104,_Context->y_WidgetProperties+234,42,16,vfh[2],16,0,_Context->msg_Auto2792[_Context->language],strlen(_Context->msg_Auto2792[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+165,_Context->y_WidgetProperties+234,182,16,vfh[2],16,0,_Context->msg_Auto2793[_Context->language],strlen(_Context->msg_Auto2793[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+125,180,16,vfh[2],16,0,_Context->msg_Auto2794[_Context->language],strlen(_Context->msg_Auto2794[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+11,_Context->y_WidgetProperties+77,154,16,vfh[2],16,0,_Context->msg_Auto2795[_Context->language],strlen(_Context->msg_Auto2795[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+166,_Context->y_WidgetProperties+77,135,16,vfh[2],16,0,_Context->msg_Auto2796[_Context->language],strlen(_Context->msg_Auto2796[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+314,_Context->y_WidgetProperties+75,126,16,vfh[2],16,0,_Context->msg_Auto2797[_Context->language],strlen(_Context->msg_Auto2797[_Context->language]),2);
	visual_filzone(_Context->x_WidgetProperties+245,_Context->y_WidgetProperties+281,1,1,27,0);
	visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,410);

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

private int Type_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "      ";
			return(visual_online_help(mptr,1));
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
private int on_fgSelect_event(struct vwgraph_context * _Context) {
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
		vwgraph_show(_Context);
;
	return(-1);
}


public	int	vwgraph_event(
struct vwgraph_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IswResize == mb ) return(2);
		if (_Context->trigger_IshResize == mb ) return(3);
		if (_Context->trigger_IsLock == mb ) return(8);
		if (_Context->trigger_fgSelect == mb ) return(16);
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
		vwgraph_show(_Context);
		return(-1);	/* WidgetProperties */

		}
		}
	if (( mx >= (_Context->x_WidgetProperties+16) ) 
	&&  ( my >= (_Context->y_WidgetProperties+277) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+16+165) ) 
	&&  ( my <= (_Context->y_WidgetProperties+277+16))) {
		return(2); /* IswResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+219) ) 
	&&  ( my >= (_Context->y_WidgetProperties+276) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+219+165) ) 
	&&  ( my <= (_Context->y_WidgetProperties+276+16))) {
		return(3); /* IshResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+10) ) 
	&&  ( my >= (_Context->y_WidgetProperties+92) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+10+128) ) 
	&&  ( my <= (_Context->y_WidgetProperties+92+16))) {
		return(4); /* Identity */
		}
	if (( mx >= (_Context->x_WidgetProperties+168+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+92) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+168+120) ) 
	&&  ( my <= (_Context->y_WidgetProperties+92+16))) {
		return(5); /* WidgetClass */
		}
	if (( mx >= (_Context->x_WidgetProperties+316+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+92) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+316+120) ) 
	&&  ( my <= (_Context->y_WidgetProperties+92+16))) {
		return(6); /* Type */
		}
	if (( mx >= (_Context->x_WidgetProperties+12) ) 
	&&  ( my >= (_Context->y_WidgetProperties+140) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+12+424) ) 
	&&  ( my <= (_Context->y_WidgetProperties+140+48))) {
		return(7); /* Hint */
		}
	if (( mx >= (_Context->x_WidgetProperties+459) ) 
	&&  ( my >= (_Context->y_WidgetProperties+91) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+459+182) ) 
	&&  ( my <= (_Context->y_WidgetProperties+91+16))) {
		return(8); /* IsLock */
		}
	if (( mx >= (_Context->x_WidgetProperties+458) ) 
	&&  ( my >= (_Context->y_WidgetProperties+171) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+458+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+171+16))) {
		return(9); /* AtX */
		}
	if (( mx >= (_Context->x_WidgetProperties+502) ) 
	&&  ( my >= (_Context->y_WidgetProperties+171) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+502+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+171+16))) {
		return(10); /* AtY */
		}
	if (( mx >= (_Context->x_WidgetProperties+563) ) 
	&&  ( my >= (_Context->y_WidgetProperties+172) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+563+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+172+16))) {
		return(11); /* Width */
		}
	if (( mx >= (_Context->x_WidgetProperties+610) ) 
	&&  ( my >= (_Context->y_WidgetProperties+172) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+610+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+172+16))) {
		return(12); /* Height */
		}
	if (( mx >= (_Context->x_WidgetProperties+12) ) 
	&&  ( my >= (_Context->y_WidgetProperties+249) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+12+42) ) 
	&&  ( my <= (_Context->y_WidgetProperties+249+16))) {
		return(13); /* TextColour */
		}
	if (( mx >= (_Context->x_WidgetProperties+102) ) 
	&&  ( my >= (_Context->y_WidgetProperties+249) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+102+42) ) 
	&&  ( my <= (_Context->y_WidgetProperties+249+16))) {
		return(14); /* Background */
		}
	if (( mx >= (_Context->x_WidgetProperties+165) ) 
	&&  ( my >= (_Context->y_WidgetProperties+249) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+165+216) ) 
	&&  ( my <= (_Context->y_WidgetProperties+249+16))) {
		return(15); /* StyleSheet */
		}
	if (( mx >= (_Context->x_WidgetProperties+57) ) 
	&&  ( my >= (_Context->y_WidgetProperties+249) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+57+44) ) 
	&&  ( my <= (_Context->y_WidgetProperties+249+18))) {
		return(16); /* fgSelect */
		}

	return(-1);
}


public	int	vwgraph_focus(struct vwgraph_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* IswResize */
				visual_check(_Context->x_WidgetProperties+16,_Context->y_WidgetProperties+277,165,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),(_Context->value_IswResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+16,_Context->y_WidgetProperties+277,165,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
				break;
			case	0x3 :
				/* IshResize */
				visual_check(_Context->x_WidgetProperties+219,_Context->y_WidgetProperties+276,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),(_Context->value_IshResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+219,_Context->y_WidgetProperties+276,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
				break;
			case	0x4 :
				/* Identity */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+10+1,_Context->y_WidgetProperties+92+1,128,16,vfh[1],_Context->buffer_Identity,255);
			break;
			case	0x5 :
				/* WidgetClass */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+168,_Context->y_WidgetProperties+92,120,140,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),774);
				if(change_widget_class(&_Context->value_WidgetClass)!=0){
				return(26);
				}
				break;
			case	0x6 :
				/* Type */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+316,_Context->y_WidgetProperties+92,120,140,vfh[2],0,0,parse_selection(WidgetTypeList,&_Context->value_Type),774);
				break;
			case	0x7 :
				/* Hint */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+12+1,_Context->y_WidgetProperties+140+1,424,48,vfh[1],_Context->buffer_Hint,255);
			break;
			case	0x8 :
				/* IsLock */
				visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+91,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),(_Context->value_IsLock |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+91,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
				break;
			case	0x9 :
				/* AtX */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+458+1,_Context->y_WidgetProperties+171+1,35,16,vfh[1],_Context->buffer_AtX,7);
			break;
			case	0xa :
				/* AtY */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+502+1,_Context->y_WidgetProperties+171+1,35,16,vfh[1],_Context->buffer_AtY,7);
			break;
			case	0xb :
				/* Width */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+563+1,_Context->y_WidgetProperties+172+1,35,16,vfh[1],_Context->buffer_Width,7);
			break;
			case	0xc :
				/* Height */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+610+1,_Context->y_WidgetProperties+172+1,35,16,vfh[1],_Context->buffer_Height,7);
			break;
			case	0xd :
				/* TextColour */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+12+1,_Context->y_WidgetProperties+249+1,42,16,vfh[1],_Context->buffer_TextColour,6);
			break;
			case	0xe :
				/* Background */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+102+1,_Context->y_WidgetProperties+249+1,42,16,vfh[1],_Context->buffer_Background,6);
			break;
			case	0xf :
				/* StyleSheet */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+165+1,_Context->y_WidgetProperties+249+1,216,16,vfh[1],_Context->buffer_StyleSheet,255);
			break;
			case	0x10 :
				/* fgSelect */
				_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
				visual_button(_Context->x_WidgetProperties+57,_Context->y_WidgetProperties+249,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+57,_Context->y_WidgetProperties+249,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			vwgraph_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=16;
			vwgraph_show(_Context);
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
			if ((retcode=vwgraph_event(_Context)) == -1)
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
						if (Type_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (Hint_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (IsLock_help(_Context) != 0) { continue; }
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
						if (TextColour_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (Background_help(_Context) != 0) { continue; }
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
					/* Type */
					continue;
				case	0x7 :
					/* Hint */
					continue;
				case	0x8 :
					/* IsLock */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsLock += 1;
						_Context->value_IsLock &= 1;
						}
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
					/* TextColour */
					continue;
				case	0xe :
					/* Background */
					continue;
				case	0xf :
					/* StyleSheet */
					continue;
				case	0x10 :
					/* fgSelect */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
						visual_button(_Context->x_WidgetProperties+57,_Context->y_WidgetProperties+249,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+57,_Context->y_WidgetProperties+249,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
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
				_Context->focus_item=16;
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

public	int	vwgraph()
{
	int	status=0;
	struct vwgraph_context * _Context=(struct vwgraph_context*) 0;
	status = vwgraph_create(&_Context);
	if ( status != 0) return(status);
	status = vwgraph_show(_Context);
		enter_modal();
	status = vwgraph_focus(_Context);
		leave_modal();
	status = vwgraph_hide(_Context);
	status = vwgraph_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwgraph_c */
