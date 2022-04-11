
#ifndef _vwdata_c
#define _vwdata_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vwdata.xml                                               */
/* Target         : vwdata.c                                                 */
/* Identification : 0.0-1177511937-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "sing.h"
#include "singprot.h"
#include "singform.h"
#define en_WidgetProperties   "Data widget - properties"
#define fr_WidgetProperties   "Data - Propri‚t‚s"
#define it_WidgetProperties   "Data widget - properties"
#define es_WidgetProperties   "Data widget - properties"
#define de_WidgetProperties   "Data widget - properties"
#define nl_WidgetProperties   "Data widget - properties"
#define pt_WidgetProperties   "Data widget - properties"
#define xx_WidgetProperties   "Data widget - properties"
#define en__WidgetProperties   ""
#define fr__WidgetProperties   ""
#define it__WidgetProperties   ""
#define es__WidgetProperties   ""
#define de__WidgetProperties   ""
#define nl__WidgetProperties   ""
#define pt__WidgetProperties   ""
#define xx__WidgetProperties   ""
#define en_Auto2774   "Position and Dimension"
#define fr_Auto2774   "Position et Dimension"
#define it_Auto2774   "Position and Dimension"
#define es_Auto2774   "Position and Dimension"
#define de_Auto2774   "Position and Dimension"
#define nl_Auto2774   "Position and Dimension"
#define pt_Auto2774   "Position and Dimension"
#define xx_Auto2774   "Position and Dimension"
#define en__Auto2774   ""
#define fr__Auto2774   ""
#define it__Auto2774   ""
#define es__Auto2774   ""
#define de__Auto2774   ""
#define nl__Auto2774   ""
#define pt__Auto2774   ""
#define xx__Auto2774   ""
#define en_Auto2776   "Behaviour"
#define fr_Auto2776   "Comportement"
#define it_Auto2776   "Behaviour"
#define es_Auto2776   "Behaviour"
#define de_Auto2776   "Behaviour"
#define nl_Auto2776   "Behaviour"
#define pt_Auto2776   "Behaviour"
#define xx_Auto2776   "Behaviour"
#define en__Auto2776   ""
#define fr__Auto2776   ""
#define it__Auto2776   ""
#define es__Auto2776   ""
#define de__Auto2776   ""
#define nl__Auto2776   ""
#define pt__Auto2776   ""
#define xx__Auto2776   ""
#define en_Auto2777   "Instance"
#define fr_Auto2777   "Instance"
#define it_Auto2777   "Instance"
#define es_Auto2777   "Instance"
#define de_Auto2777   "Instance"
#define nl_Auto2777   "Instance"
#define pt_Auto2777   "Instance"
#define xx_Auto2777   "Instance"
#define en__Auto2777   ""
#define fr__Auto2777   ""
#define it__Auto2777   ""
#define es__Auto2777   ""
#define de__Auto2777   ""
#define nl__Auto2777   ""
#define pt__Auto2777   ""
#define xx__Auto2777   ""
#define en_Auto2778   "General"
#define fr_Auto2778   "G‚n‚ral"
#define it_Auto2778   "General"
#define es_Auto2778   "General"
#define de_Auto2778   "General"
#define nl_Auto2778   "General"
#define pt_Auto2778   "General"
#define xx_Auto2778   "General"
#define en__Auto2778   ""
#define fr__Auto2778   ""
#define it__Auto2778   ""
#define es__Auto2778   ""
#define de__Auto2778   ""
#define nl__Auto2778   ""
#define pt__Auto2778   ""
#define xx__Auto2778   ""
#define en_Identity   ""
#define fr_Identity   ""
#define en__Identity   ""
#define fr__Identity   ""
#define en__WidgetClass   ""
#define en_Format   ""
#define en__Format   ""
#define en__Align   ""
#define fr__Align   ""
#define it__Align   ""
#define es__Align   ""
#define de__Align   ""
#define nl__Align   ""
#define pt__Align   ""
#define xx__Align   ""
#define en_IsBold   "NoCreate"
#define fr_IsBold   "Sans cr‚er"
#define it_IsBold   "NoCreate"
#define es_IsBold   "NoCreate"
#define de_IsBold   "NoCreate"
#define nl_IsBold   "NoCreate"
#define pt_IsBold   "NoCreate"
#define xx_IsBold   "NoCreate"
#define en__IsBold   ""
#define fr__IsBold   ""
#define it__IsBold   ""
#define es__IsBold   ""
#define de__IsBold   ""
#define nl__IsBold   ""
#define pt__IsBold   ""
#define xx__IsBold   ""
#define en_IsUnderline   "Exclusive"
#define fr_IsUnderline   "Exclusif"
#define it_IsUnderline   "Exclusive"
#define es_IsUnderline   "Exclusive"
#define de_IsUnderline   "Exclusive"
#define nl_IsUnderline   "Exclusive"
#define pt_IsUnderline   "Exclusive"
#define xx_IsUnderline   "Exclusive"
#define en__IsUnderline   ""
#define fr__IsUnderline   ""
#define it__IsUnderline   ""
#define es__IsUnderline   ""
#define de__IsUnderline   ""
#define nl__IsUnderline   ""
#define pt__IsUnderline   ""
#define xx__IsUnderline   ""
#define en_IsShadow   "ReadOnly"
#define fr_IsShadow   "Lecture"
#define it_IsShadow   "ReadOnly"
#define es_IsShadow   "ReadOnly"
#define de_IsShadow   "ReadOnly"
#define nl_IsShadow   "ReadOnly"
#define pt_IsShadow   "ReadOnly"
#define xx_IsShadow   "ReadOnly"
#define en__IsShadow   ""
#define fr__IsShadow   ""
#define it__IsShadow   ""
#define es__IsShadow   ""
#define de__IsShadow   ""
#define nl__IsShadow   ""
#define pt__IsShadow   ""
#define xx__IsShadow   ""
#define en_PayLoad   ""
#define en__PayLoad   ""
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
#define en__Type   ""
#define en_Auto2779   "X"
#define fr_Auto2779   "X"
#define it_Auto2779   "X"
#define es_Auto2779   "X"
#define de_Auto2779   "X"
#define nl_Auto2779   "X"
#define pt_Auto2779   "X"
#define xx_Auto2779   "X"
#define en__Auto2779   ""
#define fr__Auto2779   ""
#define it__Auto2779   ""
#define es__Auto2779   ""
#define de__Auto2779   ""
#define nl__Auto2779   ""
#define pt__Auto2779   ""
#define xx__Auto2779   ""
#define en_Auto2780   "Height"
#define fr_Auto2780   "Hauteur"
#define it_Auto2780   "Height"
#define es_Auto2780   "Height"
#define de_Auto2780   "Height"
#define nl_Auto2780   "Height"
#define pt_Auto2780   "Height"
#define xx_Auto2780   "Height"
#define en__Auto2780   ""
#define fr__Auto2780   ""
#define it__Auto2780   ""
#define es__Auto2780   ""
#define de__Auto2780   ""
#define nl__Auto2780   ""
#define pt__Auto2780   ""
#define xx__Auto2780   ""
#define en_Auto2781   "Width"
#define fr_Auto2781   "Largeur"
#define it_Auto2781   "Width"
#define es_Auto2781   "Width"
#define de_Auto2781   "Width"
#define nl_Auto2781   "Width"
#define pt_Auto2781   "Width"
#define xx_Auto2781   "Width"
#define en__Auto2781   ""
#define fr__Auto2781   ""
#define it__Auto2781   ""
#define es__Auto2781   ""
#define de__Auto2781   ""
#define nl__Auto2781   ""
#define pt__Auto2781   ""
#define xx__Auto2781   ""
#define en_Auto2782   "Y"
#define fr_Auto2782   "Y"
#define it_Auto2782   "Y"
#define es_Auto2782   "Y"
#define de_Auto2782   "Y"
#define nl_Auto2782   "Y"
#define pt_Auto2782   "Y"
#define xx_Auto2782   "Y"
#define en__Auto2782   ""
#define fr__Auto2782   ""
#define it__Auto2782   ""
#define es__Auto2782   ""
#define de__Auto2782   ""
#define nl__Auto2782   ""
#define pt__Auto2782   ""
#define xx__Auto2782   ""
#define en_Auto2783   "Filename"
#define fr_Auto2783   "Fichier"
#define it_Auto2783   "Filename"
#define es_Auto2783   "Filename"
#define de_Auto2783   "Filename"
#define nl_Auto2783   "Filename"
#define pt_Auto2783   "Filename"
#define xx_Auto2783   "Filename"
#define en__Auto2783   ""
#define fr__Auto2783   ""
#define it__Auto2783   ""
#define es__Auto2783   ""
#define de__Auto2783   ""
#define nl__Auto2783   ""
#define pt__Auto2783   ""
#define xx__Auto2783   ""
#define en_Auto2784   "File type"
#define fr_Auto2784   "Type de fichier"
#define it_Auto2784   "File type"
#define es_Auto2784   "File type"
#define de_Auto2784   "File type"
#define nl_Auto2784   "File type"
#define pt_Auto2784   "File type"
#define xx_Auto2784   "File type"
#define en__Auto2784   ""
#define fr__Auto2784   ""
#define it__Auto2784   ""
#define es__Auto2784   ""
#define de__Auto2784   ""
#define nl__Auto2784   ""
#define pt__Auto2784   ""
#define xx__Auto2784   ""
#define en_Auto2785   "Name"
#define fr_Auto2785   "Nom"
#define it_Auto2785   "Name"
#define es_Auto2785   "Name"
#define de_Auto2785   "Name"
#define nl_Auto2785   "Name"
#define pt_Auto2785   "Name"
#define xx_Auto2785   "Name"
#define en__Auto2785   ""
#define fr__Auto2785   ""
#define it__Auto2785   ""
#define es__Auto2785   ""
#define de__Auto2785   ""
#define nl__Auto2785   ""
#define pt__Auto2785   ""
#define xx__Auto2785   ""
#define en_Auto2786   "Widget class"
#define fr_Auto2786   "Classe de widget"
#define it_Auto2786   "Class"
#define es_Auto2786   "Class"
#define de_Auto2786   "Class"
#define nl_Auto2786   "Class"
#define pt_Auto2786   "Class"
#define xx_Auto2786   "Clais"
#define en__Auto2786   ""
#define fr__Auto2786   ""
#define it__Auto2786   ""
#define es__Auto2786   ""
#define de__Auto2786   ""
#define nl__Auto2786   ""
#define pt__Auto2786   ""
#define xx__Auto2786   ""
#define en_PayLoadSelect   "*"
#define fr_PayLoadSelect   "*"
#define it_PayLoadSelect   "*"
#define es_PayLoadSelect   "*"
#define de_PayLoadSelect   "*"
#define nl_PayLoadSelect   "*"
#define pt_PayLoadSelect   "*"
#define xx_PayLoadSelect   "*"
#define en__PayLoadSelect   ""
#define en_Auto2787   "Format"
#define fr_Auto2787   "Format"
#define it_Auto2787   "Format"
#define es_Auto2787   "Format"
#define de_Auto2787   "Format"
#define nl_Auto2787   "Format"
#define pt_Auto2787   "Format"
#define xx_Auto2787   "Format"
#define en__Auto2787   ""
#define fr__Auto2787   ""
#define it__Auto2787   ""
#define es__Auto2787   ""
#define de__Auto2787   ""
#define nl__Auto2787   ""
#define pt__Auto2787   ""
#define xx__Auto2787   ""
#include "vwdata.h"
static int	vfh[16];

/*	------------------------	*/
/*	p o s i t i o n _ a t ()	*/
/*	------------------------	*/
void	vwdata_position_at(struct vwdata_context * _Context,int x,int y){
	_Context->x_WidgetProperties=x;
	_Context->y_WidgetProperties=y;

}

/*	----------------	*/
/*	S e t V a r s ()	*/
/*	----------------	*/
void	vwdata_SetVars(struct vwdata_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	visual_signature("WWWW","WWWW");
	visual_transferin(_Context->buffer_AtX,7,pSpecificWidgetProperties->pAtX);
	visual_transferin(_Context->buffer_AtY,7,pSpecificWidgetProperties->pAtY);
	visual_transferin(_Context->buffer_Width,7,pSpecificWidgetProperties->pWidth);
	visual_transferin(_Context->buffer_Height,7,pSpecificWidgetProperties->pHeight);
	visual_signature("SSS","SSS");
	visual_transferin(_Context->buffer_PayLoad,255,pSpecificWidgetProperties->pPayLoad);
	visual_transferin(_Context->buffer_Identity,255,pSpecificWidgetProperties->pIdentity);
	visual_transferin(_Context->buffer_Format,255,pSpecificWidgetProperties->pFormat);
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
	if(!(pSpecificWidgetProperties->pType))
	_Context->value_Type=0;
	else
	_Context->value_Type=*((int*)pSpecificWidgetProperties->pType);

}

/*	----------------	*/
/*	G e t V a r s ()	*/
/*	----------------	*/
void	vwdata_GetVars(struct vwdata_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	visual_signature("WWWW","WWWW");
	visual_transferout(_Context->buffer_AtX,7,pSpecificWidgetProperties->pAtX);
	visual_transferout(_Context->buffer_AtY,7,pSpecificWidgetProperties->pAtY);
	visual_transferout(_Context->buffer_Width,7,pSpecificWidgetProperties->pWidth);
	visual_transferout(_Context->buffer_Height,7,pSpecificWidgetProperties->pHeight);
	visual_signature("SSS","SSS");
	visual_transferout(_Context->buffer_PayLoad,255,pSpecificWidgetProperties->pPayLoad);
	visual_transferout(_Context->buffer_Identity,255,pSpecificWidgetProperties->pIdentity);
	visual_transferout(_Context->buffer_Format,255,pSpecificWidgetProperties->pFormat);
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
	if(pSpecificWidgetProperties->pType!=(char*)0)
	*((int*)pSpecificWidgetProperties->pType)=_Context->value_Type;

}

public	int	vwdata_attach()
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

public	int	vwdata_attach_mode(int mode)
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

public	int	vwdata_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	vwdata_create(struct vwdata_context **cptr)
{

	int i;
	struct vwdata_context * _Context=(struct vwdata_context*)0;
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
	if (!(_Context = allocate( sizeof( struct vwdata_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=16;
		for (i=0; i < 255; i++)  *(_Context->buffer_Identity+i)=' ';
		_Context->value_WidgetClass=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Format+i)=' ';
		_Context->value_Align=0;
		_Context->value_IsBold=0;
		_Context->value_IsUnderline=0;
		_Context->value_IsShadow=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_PayLoad+i)=' ';
		_Context->value_IsLock=0;
		for (i=0; i < 7; i++)  *(_Context->buffer_AtX+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_AtY+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Width+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Height+i)=' ';
		_Context->value_Type=0;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2774[i]=" ";
	_Context->msg_Auto2774[0]=en_Auto2774;
	_Context->msg_Auto2774[1]=fr_Auto2774;
	_Context->msg_Auto2774[2]=it_Auto2774;
	_Context->msg_Auto2774[3]=es_Auto2774;
	_Context->msg_Auto2774[4]=de_Auto2774;
	_Context->msg_Auto2774[5]=nl_Auto2774;
	_Context->msg_Auto2774[6]=pt_Auto2774;
	_Context->msg_Auto2774[7]=xx_Auto2774;
	_Context->hint_Auto2774[0]=en__Auto2774;
	_Context->hint_Auto2774[1]=fr__Auto2774;
	_Context->hint_Auto2774[2]=it__Auto2774;
	_Context->hint_Auto2774[3]=es__Auto2774;
	_Context->hint_Auto2774[4]=de__Auto2774;
	_Context->hint_Auto2774[5]=nl__Auto2774;
	_Context->hint_Auto2774[6]=pt__Auto2774;
	_Context->hint_Auto2774[7]=xx__Auto2774;
	for (i=0; i < 8; i++)_Context->msg_Auto2776[i]=" ";
	_Context->msg_Auto2776[0]=en_Auto2776;
	_Context->msg_Auto2776[1]=fr_Auto2776;
	_Context->msg_Auto2776[2]=it_Auto2776;
	_Context->msg_Auto2776[3]=es_Auto2776;
	_Context->msg_Auto2776[4]=de_Auto2776;
	_Context->msg_Auto2776[5]=nl_Auto2776;
	_Context->msg_Auto2776[6]=pt_Auto2776;
	_Context->msg_Auto2776[7]=xx_Auto2776;
	_Context->hint_Auto2776[0]=en__Auto2776;
	_Context->hint_Auto2776[1]=fr__Auto2776;
	_Context->hint_Auto2776[2]=it__Auto2776;
	_Context->hint_Auto2776[3]=es__Auto2776;
	_Context->hint_Auto2776[4]=de__Auto2776;
	_Context->hint_Auto2776[5]=nl__Auto2776;
	_Context->hint_Auto2776[6]=pt__Auto2776;
	_Context->hint_Auto2776[7]=xx__Auto2776;
	for (i=0; i < 8; i++)_Context->msg_Auto2777[i]=" ";
	_Context->msg_Auto2777[0]=en_Auto2777;
	_Context->msg_Auto2777[1]=fr_Auto2777;
	_Context->msg_Auto2777[2]=it_Auto2777;
	_Context->msg_Auto2777[3]=es_Auto2777;
	_Context->msg_Auto2777[4]=de_Auto2777;
	_Context->msg_Auto2777[5]=nl_Auto2777;
	_Context->msg_Auto2777[6]=pt_Auto2777;
	_Context->msg_Auto2777[7]=xx_Auto2777;
	_Context->hint_Auto2777[0]=en__Auto2777;
	_Context->hint_Auto2777[1]=fr__Auto2777;
	_Context->hint_Auto2777[2]=it__Auto2777;
	_Context->hint_Auto2777[3]=es__Auto2777;
	_Context->hint_Auto2777[4]=de__Auto2777;
	_Context->hint_Auto2777[5]=nl__Auto2777;
	_Context->hint_Auto2777[6]=pt__Auto2777;
	_Context->hint_Auto2777[7]=xx__Auto2777;
	for (i=0; i < 8; i++)_Context->msg_Auto2778[i]=" ";
	_Context->msg_Auto2778[0]=en_Auto2778;
	_Context->msg_Auto2778[1]=fr_Auto2778;
	_Context->msg_Auto2778[2]=it_Auto2778;
	_Context->msg_Auto2778[3]=es_Auto2778;
	_Context->msg_Auto2778[4]=de_Auto2778;
	_Context->msg_Auto2778[5]=nl_Auto2778;
	_Context->msg_Auto2778[6]=pt_Auto2778;
	_Context->msg_Auto2778[7]=xx_Auto2778;
	_Context->hint_Auto2778[0]=en__Auto2778;
	_Context->hint_Auto2778[1]=fr__Auto2778;
	_Context->hint_Auto2778[2]=it__Auto2778;
	_Context->hint_Auto2778[3]=es__Auto2778;
	_Context->hint_Auto2778[4]=de__Auto2778;
	_Context->hint_Auto2778[5]=nl__Auto2778;
	_Context->hint_Auto2778[6]=pt__Auto2778;
	_Context->hint_Auto2778[7]=xx__Auto2778;
	_Context->hint_Identity[0]=en__Identity;
	_Context->hint_Identity[1]=fr__Identity;
	for (i=0; i < 8; i++)_Context->msg_WidgetClass[i]=" ";
	_Context->hint_WidgetClass[0]=en__WidgetClass;
	_Context->hint_Format[0]=en__Format;
	for (i=0; i < 8; i++)_Context->msg_Align[i]=" ";
	_Context->hint_Align[0]=en__Align;
	_Context->hint_Align[1]=fr__Align;
	_Context->hint_Align[2]=it__Align;
	_Context->hint_Align[3]=es__Align;
	_Context->hint_Align[4]=de__Align;
	_Context->hint_Align[5]=nl__Align;
	_Context->hint_Align[6]=pt__Align;
	_Context->hint_Align[7]=xx__Align;
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
	_Context->hint_PayLoad[0]=en__PayLoad;
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
	for (i=0; i < 8; i++)_Context->msg_Type[i]=" ";
	_Context->hint_Type[0]=en__Type;
	for (i=0; i < 8; i++)_Context->msg_Auto2779[i]=" ";
	_Context->msg_Auto2779[0]=en_Auto2779;
	_Context->msg_Auto2779[1]=fr_Auto2779;
	_Context->msg_Auto2779[2]=it_Auto2779;
	_Context->msg_Auto2779[3]=es_Auto2779;
	_Context->msg_Auto2779[4]=de_Auto2779;
	_Context->msg_Auto2779[5]=nl_Auto2779;
	_Context->msg_Auto2779[6]=pt_Auto2779;
	_Context->msg_Auto2779[7]=xx_Auto2779;
	_Context->hint_Auto2779[0]=en__Auto2779;
	_Context->hint_Auto2779[1]=fr__Auto2779;
	_Context->hint_Auto2779[2]=it__Auto2779;
	_Context->hint_Auto2779[3]=es__Auto2779;
	_Context->hint_Auto2779[4]=de__Auto2779;
	_Context->hint_Auto2779[5]=nl__Auto2779;
	_Context->hint_Auto2779[6]=pt__Auto2779;
	_Context->hint_Auto2779[7]=xx__Auto2779;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2781[i]=" ";
	_Context->msg_Auto2781[0]=en_Auto2781;
	_Context->msg_Auto2781[1]=fr_Auto2781;
	_Context->msg_Auto2781[2]=it_Auto2781;
	_Context->msg_Auto2781[3]=es_Auto2781;
	_Context->msg_Auto2781[4]=de_Auto2781;
	_Context->msg_Auto2781[5]=nl_Auto2781;
	_Context->msg_Auto2781[6]=pt_Auto2781;
	_Context->msg_Auto2781[7]=xx_Auto2781;
	_Context->hint_Auto2781[0]=en__Auto2781;
	_Context->hint_Auto2781[1]=fr__Auto2781;
	_Context->hint_Auto2781[2]=it__Auto2781;
	_Context->hint_Auto2781[3]=es__Auto2781;
	_Context->hint_Auto2781[4]=de__Auto2781;
	_Context->hint_Auto2781[5]=nl__Auto2781;
	_Context->hint_Auto2781[6]=pt__Auto2781;
	_Context->hint_Auto2781[7]=xx__Auto2781;
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
	for (i=0; i < 8; i++)_Context->msg_Auto2784[i]=" ";
	_Context->msg_Auto2784[0]=en_Auto2784;
	_Context->msg_Auto2784[1]=fr_Auto2784;
	_Context->msg_Auto2784[2]=it_Auto2784;
	_Context->msg_Auto2784[3]=es_Auto2784;
	_Context->msg_Auto2784[4]=de_Auto2784;
	_Context->msg_Auto2784[5]=nl_Auto2784;
	_Context->msg_Auto2784[6]=pt_Auto2784;
	_Context->msg_Auto2784[7]=xx_Auto2784;
	_Context->hint_Auto2784[0]=en__Auto2784;
	_Context->hint_Auto2784[1]=fr__Auto2784;
	_Context->hint_Auto2784[2]=it__Auto2784;
	_Context->hint_Auto2784[3]=es__Auto2784;
	_Context->hint_Auto2784[4]=de__Auto2784;
	_Context->hint_Auto2784[5]=nl__Auto2784;
	_Context->hint_Auto2784[6]=pt__Auto2784;
	_Context->hint_Auto2784[7]=xx__Auto2784;
	for (i=0; i < 8; i++)_Context->msg_Auto2785[i]=" ";
	_Context->msg_Auto2785[0]=en_Auto2785;
	_Context->msg_Auto2785[1]=fr_Auto2785;
	_Context->msg_Auto2785[2]=it_Auto2785;
	_Context->msg_Auto2785[3]=es_Auto2785;
	_Context->msg_Auto2785[4]=de_Auto2785;
	_Context->msg_Auto2785[5]=nl_Auto2785;
	_Context->msg_Auto2785[6]=pt_Auto2785;
	_Context->msg_Auto2785[7]=xx_Auto2785;
	_Context->hint_Auto2785[0]=en__Auto2785;
	_Context->hint_Auto2785[1]=fr__Auto2785;
	_Context->hint_Auto2785[2]=it__Auto2785;
	_Context->hint_Auto2785[3]=es__Auto2785;
	_Context->hint_Auto2785[4]=de__Auto2785;
	_Context->hint_Auto2785[5]=nl__Auto2785;
	_Context->hint_Auto2785[6]=pt__Auto2785;
	_Context->hint_Auto2785[7]=xx__Auto2785;
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
	_Context->p_PayLoadSelect=visual_buffer(_Context->x_WidgetProperties+638,_Context->y_WidgetProperties+183,20+2,18+2);
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
	return(0);
}

public 	int	vwdata_hide(struct vwdata_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_PayLoadSelect != (void *) 0)
	&& (_Context->s_PayLoadSelect != 0)) {
		(void)visual_buffer_put(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+638,_Context->y_WidgetProperties+183);
		_Context->s_PayLoadSelect=0;
		}

	return(result);
}

public	int	vwdata_remove(struct vwdata_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->p_PayLoadSelect != (void *) 0)
		_Context->p_PayLoadSelect = visual_drop(_Context->p_PayLoadSelect);
	_Context=liberate(_Context);

	return(result);
}

public	int	vwdata_show(struct vwdata_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,"widget_frame",_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]))) != 0)
) {
		visual_window(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,vfh[2],_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]),0x4);
		}
	visual_text(_Context->x_WidgetProperties+221,_Context->y_WidgetProperties+226,210,16,vfh[2],16,0,_Context->msg_Auto2774[_Context->language],strlen(_Context->msg_Auto2774[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+221,_Context->y_WidgetProperties+242,210,46,4);
	visual_filzone(_Context->x_WidgetProperties+559,_Context->y_WidgetProperties+143,1,1,27,0);
	visual_text(_Context->x_WidgetProperties+9,_Context->y_WidgetProperties+226,210,16,vfh[2],16,0,_Context->msg_Auto2776[_Context->language],strlen(_Context->msg_Auto2776[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+9,_Context->y_WidgetProperties+242,210,46,4);
	visual_text(_Context->x_WidgetProperties+434,_Context->y_WidgetProperties+226,231,16,vfh[2],16,0,_Context->msg_Auto2777[_Context->language],strlen(_Context->msg_Auto2777[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+434,_Context->y_WidgetProperties+242,231,47,4);
	visual_text(_Context->x_WidgetProperties+7,_Context->y_WidgetProperties+39,658,16,vfh[2],16,0,_Context->msg_Auto2778[_Context->language],strlen(_Context->msg_Auto2778[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+7,_Context->y_WidgetProperties+55,658,163,4);
	visual_frame(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+77,264+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+77+1,264,16,vfh[1],34,0,_Context->buffer_Identity,255,0);
	visual_select(_Context->x_WidgetProperties+296,_Context->y_WidgetProperties+78,130,100,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),768);
	visual_frame(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+126,264+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+126+1,264,16,vfh[1],27,0,_Context->buffer_Format,255,0);
	visual_select(_Context->x_WidgetProperties+297,_Context->y_WidgetProperties+127,130,100,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),768);
	_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_WidgetProperties+503,_Context->y_WidgetProperties+76,150,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
	_Context->trigger_IsUnderline=visual_trigger_code(_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]));
	visual_check(_Context->x_WidgetProperties+504,_Context->y_WidgetProperties+105,150,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),_Context->value_IsUnderline|0);
	_Context->trigger_IsShadow=visual_trigger_code(_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]));
	visual_check(_Context->x_WidgetProperties+505,_Context->y_WidgetProperties+135,150,16,vfh[2],28,28,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),_Context->value_IsShadow|0);
	visual_frame(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+184,620+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+15+1,_Context->y_WidgetProperties+184+1,620,16,vfh[1],34,0,_Context->buffer_PayLoad,255,0);
	_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+21,_Context->y_WidgetProperties+256,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
	visual_frame(_Context->x_WidgetProperties+228,_Context->y_WidgetProperties+262,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+228+1,_Context->y_WidgetProperties+262+1,35,16,vfh[1],34,0,_Context->buffer_AtX,7,0);
	visual_frame(_Context->x_WidgetProperties+269,_Context->y_WidgetProperties+262,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+269+1,_Context->y_WidgetProperties+262+1,35,16,vfh[1],34,0,_Context->buffer_AtY,7,0);
	visual_frame(_Context->x_WidgetProperties+331,_Context->y_WidgetProperties+263,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+331+1,_Context->y_WidgetProperties+263+1,35,16,vfh[1],34,0,_Context->buffer_Width,7,0);
	visual_frame(_Context->x_WidgetProperties+380,_Context->y_WidgetProperties+264,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+380+1,_Context->y_WidgetProperties+264+1,35,16,vfh[1],34,0,_Context->buffer_Height,7,0);
	visual_select(_Context->x_WidgetProperties+444,_Context->y_WidgetProperties+263,210,112,vfh[2],0,0,parse_selection(WidgetTypeList,&_Context->value_Type),768);
	visual_text(_Context->x_WidgetProperties+229,_Context->y_WidgetProperties+246,14,21,vfh[2],16,0,_Context->msg_Auto2779[_Context->language],strlen(_Context->msg_Auto2779[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+380,_Context->y_WidgetProperties+248,50,21,vfh[2],16,0,_Context->msg_Auto2780[_Context->language],strlen(_Context->msg_Auto2780[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+331,_Context->y_WidgetProperties+247,50,21,vfh[2],16,0,_Context->msg_Auto2781[_Context->language],strlen(_Context->msg_Auto2781[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+271,_Context->y_WidgetProperties+246,14,21,vfh[2],16,0,_Context->msg_Auto2782[_Context->language],strlen(_Context->msg_Auto2782[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+164,98,16,vfh[2],16,0,_Context->msg_Auto2783[_Context->language],strlen(_Context->msg_Auto2783[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+297,_Context->y_WidgetProperties+111,126,16,vfh[2],16,0,_Context->msg_Auto2784[_Context->language],strlen(_Context->msg_Auto2784[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+63,154,16,vfh[2],16,0,_Context->msg_Auto2785[_Context->language],strlen(_Context->msg_Auto2785[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+294,_Context->y_WidgetProperties+63,135,16,vfh[2],16,0,_Context->msg_Auto2786[_Context->language],strlen(_Context->msg_Auto2786[_Context->language]),2);
	if ((_Context->p_PayLoadSelect != (void *) 0)
	&& (_Context->s_PayLoadSelect == 0)) {
		(void)visual_buffer_get(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+638,_Context->y_WidgetProperties+183);
		_Context->s_PayLoadSelect=1;
		}
	_Context->trigger_PayLoadSelect=visual_trigger_code(_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+638,_Context->y_WidgetProperties+183,20,18,vfh[8],28,28,_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]),0);
	visual_text(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+112,148,16,vfh[2],16,0,_Context->msg_Auto2787[_Context->language],strlen(_Context->msg_Auto2787[_Context->language]),2);
	visual_filzone(_Context->x_WidgetProperties+555,_Context->y_WidgetProperties+145,1,1,27,0);
	visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400);

	return(0);
}

private int WidgetPropertiesaction(struct vwdata_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			vwdata_hide(_Context);

		_Context->x_WidgetProperties += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_WidgetProperties < 0) { _Context->x_WidgetProperties=0; }
		_Context->y_WidgetProperties += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_WidgetProperties < 0) { _Context->y_WidgetProperties=0; }
			vwdata_show(_Context);

		visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_WidgetClass_event(struct vwdata_context * _Context) {
	unsigned char*msg_help[8];
	int nblig=1;
	msg_help[0]="With this Combo, you can change the Classe of the\0" \
	"widget. But it his dangerous, because some code is\0" \
	"generated at the creation of the widget, and won't be\0" \
	"modified here.";
	msg_help[1]="Cette combo permet de changer la classe de votre objet.\0" \
	"Mais c'est d‚conseill‚, car une partie du code est g‚n‚r‚\0" \
	"a la cr‚ation en fonction de la classe du widget et ne sera\0" \
	"pas modifi‚ ici.";
	nblig=4;
	/*anglais pour les autres langues*/
	msg_help[2]=msg_help[0];
	msg_help[3]=msg_help[0];
	msg_help[4]=msg_help[0];
	msg_help[5]=msg_help[0];
	msg_help[6]=msg_help[0];
	msg_help[7]=msg_help[0];
	aide_en_ligne(_Context->x_WidgetProperties+296-80,_Context->y_WidgetProperties+78+30,nblig,msg_help[visual_national_language(-1)]);
	return(-1);
}
private int on_Align_event(struct vwdata_context * _Context) {
	unsigned char*msg_help[8],*msg;
	int i,nblig=1;
	int largeur=0;
	switch(_Context->value_WidgetClass)
	{
	case _TAB_FRAME:
	msg_help[0]="Choose the form of your tab (standard,concave or convex).";
	msg_help[1]="Choisir la forme de l'onglet (standard,concave ou convex)";
	break;
	case _BUTTON_FRAME:
	msg_help[0]="Choose the type of button you want, with or without frame, text or Image inside";
	msg_help[1]="Choisir le type de button, avec ou sans cadre et texte ou image";
	break;
	case _EDIT_FRAME:
	case _PROGRESS_FRAME:
	msg_help[0]="Choose the alignment of your widget (none,left,right,center or justify).";
	msg_help[1]="Choisir l'alignement de l'objet (aucun,gauche,droite,centr‚ ou justifi‚)";
	break;
		case _FORM_FRAME:
	msg_help[0]="Choose your type of form. Your choice will make effects\0sometimes for the titles, other times for the columns";
	msg_help[1]="Choisir le type de tableau, le choix peut influer sur les titres\0ou bien sur les donn‚es";
	nblig=2;
	break;
	case _SCROLL_FRAME:
	msg_help[0]="This option controls the composition of the scroll bar. In all cases,\0" \
	"when the zone width is found to be greater than the zone height a horizontal\0" \
	"bar will be displayed. Otherwise, when the width is less than the height, a\0" \
	"vertical bar will be displayed.\0" \
	"\0" \
	"None : The scroll bar trough will occupy the entire widget zone. No butons\0" \
	"        will be displayed.\0" \
	"\0" \
	"Right : A down or right button will be displayed at the appropriate extremity.\0" \
	"        The scroll bar trough will occupy the remaining zone.\0" \
	"\0" \
	"Left : A up or left button will be displayed at the appropriate extremity.\0" \
	"       The scroll bar trough will occupy the remaining zone.\0" \
	"\0" \
	"Both : Both up and down or left and right buttons will be displayed at each\0" \
	"       end of the bar. The scroll bar trough will occupy the remaining zone.\0" \
	"\0" \
	"Slider : No buttons will be displayed and the slider bar will be displayed as a\0" \
	"         rounded slider in a grooved trough, occupying the entire widget zone.\0";
	msg_help[1]="Cette option permet de d‚finir l'aspect de la barre de defilement.Dans tous\0" \
	"les cas, quand la zone largeur est calcul‚e plus grande que la hauteur une barre\0" \
	"horizontale est affich‚e, sinon, quand la largeur est plus petite que la\0" \
	"hauteur, c'est une barre verticale.\0" \
	"\0" \
	"None : La barre de d‚filement occupera l'int‚gralit‚ de la zone d‚finie par les\0" \
	"       les points x,y,w et h.\0" \
	"\0" \
	"Right : Selon le sens de la barre de d‚filement, on aura un bouton bas ou un\0" \
	"        bouton haut a l'extr‚mit‚\0" \
	"\0" \
	"Left : Sur le mˆme principe que l'iption right, on aurra un bouton\0" \
	"       haut ou gauche.\0" \
	"\0" \
	"Both : Selon le sens de la barre, on aura un bouton haut et bas\0" \
	"       ou droite et gauche aux extr‚mit‚s.\0" \
	"\0" \
	"Slider : Aucun bouton ne sera affich‚ et la barre apparaitra arondie comme un\0" \
	"         tube entour‚ d'un cadre concave.\0";
	nblig=19;
	break;
	case _IMAGE_FRAME:
	msg_help[0]="The following image options are available.\0" \
	"\0" \
	"None    : no alignment is applied to the image.\0" \
	"\0" \
	"Right   : The image will be right aligned in the widget zone.\0" \
	"\0" \
	"Left    : The image will be left aligned in the widget zone.\0" \
	"\0" \
	"Center  : The image will be centered within the widget zone.\0" \
	"\0" \
	"Tile    : This option causes the images, smaller than their widget\0" \
	"          zone, to be tiled or repeated, to fill the entire zone.\0" \
	"\0" \
	"Makefit : causes images to be stretched or squashed to fit the entire\0" \
	"          widget zone.\0" \
	"\0" \
	"Bestfit : causes images to stretched and squashed respecting the image\0" \
	"          proportions. The result may stil be smaller than the widget\0" \
	"          zone in which case it will be centered.";
	msg_help[1]="Pour une image, choisissez parmis les alignements suivants.\0" \
	"\0" \
	"None    : aucun alignement ne sera fait sur l'image.\0" \
	"\0" \
	"Right   : l'image sera align‚e sur la droite des coordonn‚s l'objet.\0" \
	"\0" \
	"Left    : l'image sera align‚e sur la gauche des coordonn‚s l'objet.\0" \
	"\0" \
	"Center  : l'image sera centr‚e dans la zone d‚finie.\0" \
	"\0" \
	"Tile    : Cette option permet pour les images plus petites que l'objet\0" \
	"          d'ˆtres dupliqu‚es et/ou coup‚es pour occuper tout l'espace.\0" \
	"\0" \
	"Makefit : avec cette option, l'image sera r‚duite ou agrandie pour occuper\0" \
	"          tout l'espace en une seule fois.\0" \
	"\0" \
	"Bestfit : Comme Makefit, l'image va ˆtre r‚duite ou agrandie mais ses\0" \
	"          proportions seront conserv‚es. Si l'image n'occupe pas tout l'espace\0" \
	"          en hauteur ou largeur, elle sera centr‚e.";
	nblig=19;
	break;
	case _DATA_FRAME:
	msg_help[0]="With this combo box choose the type of file you want to manage.\0" \
	"\0" \
	"variable : use this option for a CRITERIA file with variable data lengths\0" \
	"\0" \
	"instance : select this to manage an instance file\0" \
	"\0" \
	"visual   : to manage a file for the visual library\0" \
	"\0" \
	"sifile   : for a CRITERIA file with only SI acces\0" \
	"\0" \
	"mcfile   : for CRITERIA files with muti-crit‚res acces\0" \
	"\0" \
	"vmemory  : select this to manage data mapped in a file\0" \
	"\0" \
	"sqfile   : for s‚quential files\0" \
	"\0" \
	"dbfile   : for CRITERIA files whith data base acces";
	msg_help[1]="Cette Combo box permet de choisir le type de fichiers a g‚rer\0" \
	"\0" \
	"variable : pour les fichiers CRITERIA avec des donn‚es a longueur variable\0" \
	"\0" \
	"instance : pour les fichiers de type instance\0" \
	"\0" \
	"visual   : pour les fichiers de configuraton visual\0" \
	"\0" \
	"sifile   : pour les fichiers CRITERIA avec l'accŠs s‚quentiel index‚ seul\0" \
	"\0" \
	"mcfile   : pour les fichiers CRITERIA avec l'accŠs multi crit‚res\0" \
	"\0" \
	"vmemory  : pour les fichiers de donn‚es m‚moris‚es sur disque\0" \
	"\0" \
	"sqfile   : pour les fichiers s‚quentiels\0" \
	"\0" \
	"dbfile   : pour les fichiers CRITERIA avec accŠs base de donn‚es";
	nblig=17;
	break;
		case _WINDOW_FRAME:
	msg_help[0]="The alignment value applies to the window itself\0" \
	"within the parent graphical output screen\0";
	msg_help[1]="L'alignement choisi s'appliquera sur la fenˆtre\0" \
	"par rapport a la fenˆtre parent";
	nblig=2;
	break;
	case _FILL_FRAME:
	msg_help[0]="Choose what sort of fill you want. Except when it is writen, the color\0" \
	"used to fill or draw his always the foreground one.\0" \
	"\0" \
	"block : a rectangle fill.\0" \
	"\0" \
	"frame : a line draw a rectangle.\0" \
	"\0" \
	"circle : a line draw a circle.\0" \
	"\0" \
	"disk   : a circle his fill.\0" \
	"\0" \
	"convex1, convex2 : a convex rectangle his fill with the button color.\0" \
	"\0" \
	"concave1, concave2 : a concave rectangle his fill with the button color.\0" \
	"\0" \
	"framed block : a rectangle his fill with the background color and framed\0" \
	"               with the foreground color.\0" \
	"\0" \
	"framed disk : like framed block but with a circle.\0" \
	"\0" \
	"framed convex, framed concave : like convex1 or concave1.\0" \
	"\0" \
	"shadow : a block with a shadow.\0" \
	"\0" \
	"roundedframe : a frame with rounded corners.\0" \
	"\0" \
	"roundedfill : a fill with rounded corners.\0";
	msg_help[1]="Choisissez votre sorte de remplissage. A pars lorsque c'est\0" \
	"sp‚cifi‚, la couleur utilis‚e est toujours celle des caracteres\0" \
	"\0" \
	"block : un rectangle plein.\0" \
	"\0" \
	"frame : les contours d'un rectangle.\0" \
	"\0" \
	"circle : les contours d'un cercle.\0" \
	"\0" \
	"disk   : un cercle plein.\0" \
	"\0" \
	"convex1, convex2 : un rectangle convexe avec la couleur des boutons.\0" \
	"\0" \
	"concave1, concave2 : un rectangle concave avec la couleur des boutons.\0" \
	"\0" \
	"framed block : un rectangle remplis avec la couleur de fond et entour‚\0" \
	"               d'un trait de couleur de caracteres.\0" \
	"\0" \
	"framed disk : comme framed block mais avec un cercle.\0" \
	"\0" \
	"framed convex, framed concave : comme convex1 or concave1.\0" \
	"\0" \
	"shadow : un block avec une ombre.\0" \
	"\0" \
	"roundedframe : comme frame avec des bords arrondis.\0" \
	"\0" \
	"roundedfill : comme block avec des bords arrondis.\0";
	nblig=27;
	break;
	case _OUTSET_FRAME:
	case _INSET_FRAME:
	case _RIDGE_FRAME:
	case _GROOVE_FRAME:
	msg_help[0]="Select the position of the title of your widget,\0" \
	"choose none if you don't want a title";
	msg_help[1]="Choisissez la position du titre de l'objet\0" \
	"Choisissez none si vous ne voulez pas de titre";
	nblig=2;
	break;
	case _LINE_FRAME:
	msg_help[0]="This combo box is without effect for the line";
	msg_help[1]="Cette combo box n'a aucune utilit‚ sur les lignes";
	break;
	case _SWITCH_FRAME:
	msg_help[0]="Choose the align of the label for the swith button";
	msg_help[1]="Choir l'alignement pour le libell‚ du bouton";
	break;
	case _SELECT_FRAME:
	case _GRAPH_FRAME:
	case _CHECK_FRAME:
	case _RADIO_FRAME:
	msg_help[0]="This combo box is without effect for this widget";
	msg_help[1]="Cette combo box n'a aucune utilit‚ pour cet objet";
	break;
	case _TEXT_FRAME:
	msg_help[0]="Choose the alignment of the text.";
	msg_help[1]="Choisir l'alignement du texte";
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
	if(nblig>24)
	aide_en_ligne(_Context->x_WidgetProperties+670-largeur*8-55,_Context->y_WidgetProperties+127-30,nblig,msg_help[visual_national_language(-1)]);
	else
	aide_en_ligne(_Context->x_WidgetProperties+670-largeur*8-55,_Context->y_WidgetProperties+127+30,nblig,msg_help[visual_national_language(-1)]);
	return(-1);
}
private int on_Type_event(struct vwdata_context * _Context) {
	unsigned char*msg_help[8],*msg,msg1[1300],msg2[1300];
	int i,nblig=1;
	int largeur=0;
	switch(_Context->value_WidgetClass)
	{
	case _PROGRESS_FRAME:
	msg_help[0]="This Combo box has no effect for this widget.\0" \
	"Use this.LIMIT to fix the maximum of the progress\0" \
	"and this.VALUE before OnShow to affect the progression";
	msg_help[1]="Cette combo box est sans effets pour cet objet.\0" \
	"Utiliser this.LIMIT pour indiquer le maximum et\0" \
	"this.VALUE avant OnShow pour l'‚tat de la progression";
	nblig=3;
	break;
	case _FORM_FRAME:
	msg_help[0]="This Combo box has no effect for this widget.\0" \
	"this.LINE(N) set the active line to line N.\0" \
	"this.LINES return the number of lines.\0" \
	"this.LINESIZE return the maximum size of a line.\0" \
	"this.COLUMN(N)=label set the column N of the active line.\0" \
	"this.COLUMNS return the number of columns.";
	msg_help[1]="Cette combo box est sans effets pour cet objet.\0" \
	"this.LINE(N) rend la ligne N active.\0" \
	"this.LINES retourne le nombre de lignes.\0" \
	"this.LINESIZE donne la taille maximum d'une ligne.\0" \
	"this.COLUMN(N)=label modifie la valeur de la colonne N.\0" \
	"this.COLUMNS indique le nombre de colonnes.";
	nblig=6;
	break;
	case _IMAGE_FRAME:
	case _TAB_FRAME:
	case _DATA_FRAME:
	case _WINDOW_FRAME:
	case _FILL_FRAME:
	case _OUTSET_FRAME:
	case _INSET_FRAME:
	case _RIDGE_FRAME:
	case _GROOVE_FRAME:
	case _LINE_FRAME:
	case _GRAPH_FRAME:
	case _TEXT_FRAME:
	msg_help[0]="This Combo box has no effect for this widget.";
	msg_help[1]="Cette combo box est sans effets pour cet objet.";
	break;
	case _BUTTON_FRAME:
	msg_help[0]="Choose the option overlay, loadgo or chain to call the value\0" \
	"edit in Taget zone with this.buffer parameter after event\0" \
	"action.";
	msg_help[1]="Choisir l'option overlay, loadgo ou chain pour appeler le\0" \
	"programme saisi dans la zone Target avec le param‚tre\0" \
	"this.buffer aprŠs l'action Event.";
	nblig=3;
	break;
	case _EDIT_FRAME:
	msg_help[0]="Leave the storage type string for edit frame\0" \
	"Use this.BUFFER or this.VALUE to acces content\0" \
	"Use this.SIZE to have length as LEN(this.BUFFER).";
	msg_help[1]="Pour les zones d'‚dition, laisser le type string\0" \
	"Utiliser this.BUFFER ou this.VALUE pour acc‚der au contenu\0" \
	"Utilisez this.SIZE pour avoir la longueur maximum de la chaine.";
	nblig=3;
	break;
	case _SCROLL_FRAME:
	msg_help[0]="This combo doesn't have signification for Scroll frame.\0" \
	"Use this.MAX to indicate the high value, this.VALUE for\0" \
	"the actual view of scroll bar and this.limit for the size\0" \
	"of a page.";
	msg_help[1]="Cette combo box n'a pas d'utilit‚ pour la barre de scroll.\0" \
	"Utilisez this.MAX pour indiquer la valeur maximum, this.VALUE\0" \
	"pour la valeur actuelle de la scroll barre et this.limit pour\0" \
	"la taille d'une page.";
	nblig=3;
	break;
	case _SWITCH_FRAME:
	case _SELECT_FRAME:
	case _RADIO_FRAME:
	msg_help[0]="This Combo box has no effect for this widget.\0" \
	"Use this.VALUE to read or change the item\0" \
	"selected.";
	msg_help[1]="Cette combo box est sans effets pour cet objet.\0" \
	"Utilisez this.VALUE pour lire ou modifier le\0" \
	"num‚ro d'item selectionn‚.";
	nblig=3;
	break;
	case _CHECK_FRAME:
	msg_help[0]="This Combo box has no effect for this widget.\0" \
	"Use this.VALUE to read or change the boolean\0" \
	"value.";
	msg_help[1]="Cette combo box est sans effets pour cet objet.\0" \
	"Utilisez this.VALUE pour lire ou modifier la\0" \
	"valeur bool‚enne (0 ou 1).";
	nblig=3;
	break;
	default:
	msg_help[0]="No help for this Widget.";
	msg_help[1]="Pas d'aide pour cet objet.";
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
	aide_en_ligne(_Context->x_WidgetProperties+670-largeur*8-55,_Context->y_WidgetProperties+263+30,nblig,msg_help[visual_national_language(-1)]);
	return(-1);
}
private int on_PayLoadSelect_event(struct vwdata_context * _Context) {
	struct form_control*fptr;
	struct form_control*resolve_component_number(int);
	int component=0;
		vwdata_hide(_Context);
;
	if(_Context->value_Align==_VISUAL_FRAME){
	if(accept_component_selection(&component)!=27){
	if((fptr=resolve_component_number(component))!=(struct form_control*)0){
	if(fptr->identifier){
	strcpy(_Context->buffer_PayLoad,fptr->identifier);
	}
	}
	}
	reset_component_selection_list();
	}
	else if(_Context->value_IsLock!=0){
	use_data_selector(
	(void*)0,
	_Context->buffer_Format,255,/*classname*/
	_Context->buffer_Identity,255,/*instance*/
	_Context->buffer_PayLoad,255/*filename*/
	);
	}
	else{
	use_data_selector(
	(void*)0,
	_Context->buffer_Format,255,/*classname*/
	_Context->buffer_Identity,0,/*instance*/
	_Context->buffer_PayLoad,0/*filename*/
	);
	}
		vwdata_show(_Context);
;
		return(-1);
}


public	int	vwdata_event(
struct vwdata_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsBold == mb ) return(6);
		if (_Context->trigger_IsUnderline == mb ) return(7);
		if (_Context->trigger_IsShadow == mb ) return(8);
		if (_Context->trigger_IsLock == mb ) return(10);
		if (_Context->trigger_PayLoadSelect == mb ) return(16);
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
		vwdata_show(_Context);
		return(-1);	/* WidgetProperties */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_WidgetProperties+4) )  
		&&  (my >= (_Context->y_WidgetProperties+4) )  
		&&  (mx <= (_Context->x_WidgetProperties+602) )  
		&&  (my <= (_Context->y_WidgetProperties+20) )) {
			return( WidgetPropertiesaction(_Context) );
			}
		}
	if (( mx >= (_Context->x_WidgetProperties+14) ) 
	&&  ( my >= (_Context->y_WidgetProperties+77) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+14+264) ) 
	&&  ( my <= (_Context->y_WidgetProperties+77+16))) {
		return(2); /* Identity */
		}
	if (( mx >= (_Context->x_WidgetProperties+296+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+78) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+296+130) ) 
	&&  ( my <= (_Context->y_WidgetProperties+78+16))) {
		return(3); /* WidgetClass */
		}
	if (( mx >= (_Context->x_WidgetProperties+14) ) 
	&&  ( my >= (_Context->y_WidgetProperties+126) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+14+264) ) 
	&&  ( my <= (_Context->y_WidgetProperties+126+16))) {
		return(4); /* Format */
		}
	if (( mx >= (_Context->x_WidgetProperties+297+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+127) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+297+130) ) 
	&&  ( my <= (_Context->y_WidgetProperties+127+16))) {
		return(5); /* Align */
		}
	if (( mx >= (_Context->x_WidgetProperties+503) ) 
	&&  ( my >= (_Context->y_WidgetProperties+76) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+503+150) ) 
	&&  ( my <= (_Context->y_WidgetProperties+76+16))) {
		return(6); /* IsBold */
		}
	if (( mx >= (_Context->x_WidgetProperties+504) ) 
	&&  ( my >= (_Context->y_WidgetProperties+105) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+504+150) ) 
	&&  ( my <= (_Context->y_WidgetProperties+105+16))) {
		return(7); /* IsUnderline */
		}
	if (( mx >= (_Context->x_WidgetProperties+505) ) 
	&&  ( my >= (_Context->y_WidgetProperties+135) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+505+150) ) 
	&&  ( my <= (_Context->y_WidgetProperties+135+16))) {
		return(8); /* IsShadow */
		}
	if (( mx >= (_Context->x_WidgetProperties+15) ) 
	&&  ( my >= (_Context->y_WidgetProperties+184) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+15+620) ) 
	&&  ( my <= (_Context->y_WidgetProperties+184+16))) {
		return(9); /* PayLoad */
		}
	if (( mx >= (_Context->x_WidgetProperties+21) ) 
	&&  ( my >= (_Context->y_WidgetProperties+256) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+21+182) ) 
	&&  ( my <= (_Context->y_WidgetProperties+256+16))) {
		return(10); /* IsLock */
		}
	if (( mx >= (_Context->x_WidgetProperties+228) ) 
	&&  ( my >= (_Context->y_WidgetProperties+262) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+228+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+262+16))) {
		return(11); /* AtX */
		}
	if (( mx >= (_Context->x_WidgetProperties+269) ) 
	&&  ( my >= (_Context->y_WidgetProperties+262) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+269+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+262+16))) {
		return(12); /* AtY */
		}
	if (( mx >= (_Context->x_WidgetProperties+331) ) 
	&&  ( my >= (_Context->y_WidgetProperties+263) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+331+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+263+16))) {
		return(13); /* Width */
		}
	if (( mx >= (_Context->x_WidgetProperties+380) ) 
	&&  ( my >= (_Context->y_WidgetProperties+264) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+380+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+264+16))) {
		return(14); /* Height */
		}
	if (( mx >= (_Context->x_WidgetProperties+444+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+263) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+444+210) ) 
	&&  ( my <= (_Context->y_WidgetProperties+263+16))) {
		return(15); /* Type */
		}
	if (( mx >= (_Context->x_WidgetProperties+638) ) 
	&&  ( my >= (_Context->y_WidgetProperties+183) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+638+20) ) 
	&&  ( my <= (_Context->y_WidgetProperties+183+18))) {
		return(16); /* PayLoadSelect */
		}

	return(-1);
}


public	int	vwdata_focus(struct vwdata_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Identity */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+77+1,264,16,vfh[1],_Context->buffer_Identity,255);
			break;
			case	0x3 :
				/* WidgetClass */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+296,_Context->y_WidgetProperties+78,130,100,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),774);
				if(change_widget_class(&_Context->value_WidgetClass)!=0){
				return(26);
				}
				break;
			case	0x4 :
				/* Format */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+126+1,264,16,vfh[1],_Context->buffer_Format,255);
			break;
			case	0x5 :
				/* Align */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+297,_Context->y_WidgetProperties+127,130,100,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),774);
				break;
			case	0x6 :
				/* IsBold */
				visual_check(_Context->x_WidgetProperties+503,_Context->y_WidgetProperties+76,150,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),(_Context->value_IsBold |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsBold=visual_trigger_code(_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]));
	visual_check(_Context->x_WidgetProperties+503,_Context->y_WidgetProperties+76,150,16,vfh[2],175,0,_Context->msg_IsBold[_Context->language],strlen(_Context->msg_IsBold[_Context->language]),_Context->value_IsBold|0);
				break;
			case	0x7 :
				/* IsUnderline */
				visual_check(_Context->x_WidgetProperties+504,_Context->y_WidgetProperties+105,150,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),(_Context->value_IsUnderline |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsUnderline=visual_trigger_code(_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]));
	visual_check(_Context->x_WidgetProperties+504,_Context->y_WidgetProperties+105,150,16,vfh[2],175,0,_Context->msg_IsUnderline[_Context->language],strlen(_Context->msg_IsUnderline[_Context->language]),_Context->value_IsUnderline|0);
				break;
			case	0x8 :
				/* IsShadow */
				visual_check(_Context->x_WidgetProperties+505,_Context->y_WidgetProperties+135,150,16,vfh[2],28,28,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),(_Context->value_IsShadow |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsShadow=visual_trigger_code(_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]));
	visual_check(_Context->x_WidgetProperties+505,_Context->y_WidgetProperties+135,150,16,vfh[2],28,28,_Context->msg_IsShadow[_Context->language],strlen(_Context->msg_IsShadow[_Context->language]),_Context->value_IsShadow|0);
				break;
			case	0x9 :
				/* PayLoad */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+15+1,_Context->y_WidgetProperties+184+1,620,16,vfh[1],_Context->buffer_PayLoad,255);
			break;
			case	0xa :
				/* IsLock */
				visual_check(_Context->x_WidgetProperties+21,_Context->y_WidgetProperties+256,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),(_Context->value_IsLock |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+21,_Context->y_WidgetProperties+256,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
				break;
			case	0xb :
				/* AtX */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+228+1,_Context->y_WidgetProperties+262+1,35,16,vfh[1],_Context->buffer_AtX,7);
			break;
			case	0xc :
				/* AtY */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+269+1,_Context->y_WidgetProperties+262+1,35,16,vfh[1],_Context->buffer_AtY,7);
			break;
			case	0xd :
				/* Width */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+331+1,_Context->y_WidgetProperties+263+1,35,16,vfh[1],_Context->buffer_Width,7);
			break;
			case	0xe :
				/* Height */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+380+1,_Context->y_WidgetProperties+264+1,35,16,vfh[1],_Context->buffer_Height,7);
			break;
			case	0xf :
				/* Type */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+444,_Context->y_WidgetProperties+263,210,112,vfh[2],0,0,parse_selection(WidgetTypeList,&_Context->value_Type),774);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			vwdata_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=16;
			vwdata_show(_Context);
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
			if ((retcode=vwdata_event(_Context)) == -1)
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
					continue;
				case	0x3 :
					/* WidgetClass */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_WidgetClass_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Format */
					continue;
				case	0x5 :
					/* Align */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_Align_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* IsBold */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsBold += 1;
						_Context->value_IsBold &= 1;
						}
					continue;
				case	0x7 :
					/* IsUnderline */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsUnderline += 1;
						_Context->value_IsUnderline &= 1;
						}
					continue;
				case	0x8 :
					/* IsShadow */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsShadow += 1;
						_Context->value_IsShadow &= 1;
						}
					continue;
				case	0x9 :
					/* PayLoad */
					continue;
				case	0xa :
					/* IsLock */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsLock += 1;
						_Context->value_IsLock &= 1;
						}
					continue;
				case	0xb :
					/* AtX */
					continue;
				case	0xc :
					/* AtY */
					continue;
				case	0xd :
					/* Width */
					continue;
				case	0xe :
					/* Height */
					continue;
				case	0xf :
					/* Type */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_Type_event(_Context)) != -1) break;

						}
					continue;
				case	0x10 :
					/* PayLoadSelect */
					if (visual_event(1) & _MIMO_DOWN) {
						if ((_Context->p_PayLoadSelect != (void *) 0)
						&& (_Context->s_PayLoadSelect == 0)) {
							(void)visual_buffer_get(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+638,_Context->y_WidgetProperties+183);
							_Context->s_PayLoadSelect=1;
							}
						_Context->trigger_PayLoadSelect=visual_trigger_code(_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]));
						visual_button(_Context->x_WidgetProperties+638,_Context->y_WidgetProperties+183,20,18,vfh[8],28,28,_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						if ((_Context->p_PayLoadSelect != (void *) 0)
						&& (_Context->s_PayLoadSelect == 0)) {
							(void)visual_buffer_get(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+638,_Context->y_WidgetProperties+183);
							_Context->s_PayLoadSelect=1;
							}
						_Context->trigger_PayLoadSelect=visual_trigger_code(_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+638,_Context->y_WidgetProperties+183,20,18,vfh[8],28,28,_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]),0);
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

public	int	vwdata()
{
	int	status=0;
	struct vwdata_context * _Context=(struct vwdata_context*) 0;
	status = vwdata_create(&_Context);
	if ( status != 0) return(status);
	status = vwdata_show(_Context);
		enter_modal();
	status = vwdata_focus(_Context);
		leave_modal();
	status = vwdata_hide(_Context);
	status = vwdata_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwdata_c */
