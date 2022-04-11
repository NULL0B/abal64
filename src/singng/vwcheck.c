
#ifndef _vwcheck_c
#define _vwcheck_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vwcheck.xml                                              */
/* Target         : vwcheck.c                                                */
/* Identification : 0.0-1177511937-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "sing.h"
#include "singform.h"
#include "singprot.h"
#define en_WidgetProperties   "Check widget - Properties"
#define fr_WidgetProperties   "Check - Propri‚t‚s"
#define it_WidgetProperties   "Check widget - Properties"
#define es_WidgetProperties   "Check widget - Properties"
#define de_WidgetProperties   "Check widget - Properties"
#define nl_WidgetProperties   "Check widget - Properties"
#define pt_WidgetProperties   "Check widget - Properties"
#define xx_WidgetProperties   "Check widget - Properties"
#define en__WidgetProperties   ""
#define fr__WidgetProperties   ""
#define it__WidgetProperties   ""
#define es__WidgetProperties   ""
#define de__WidgetProperties   ""
#define nl__WidgetProperties   ""
#define pt__WidgetProperties   ""
#define xx__WidgetProperties   ""
#define en_Auto2773   "Position and Dimension"
#define fr_Auto2773   "Position et Dimension"
#define it_Auto2773   "Position and Dimension"
#define es_Auto2773   "Position and Dimension"
#define de_Auto2773   "Position and Dimension"
#define nl_Auto2773   "Position and Dimension"
#define pt_Auto2773   "Position and Dimension"
#define xx_Auto2773   "Position and Dimension"
#define en__Auto2773   ""
#define fr__Auto2773   ""
#define it__Auto2773   ""
#define es__Auto2773   ""
#define de__Auto2773   ""
#define nl__Auto2773   ""
#define pt__Auto2773   ""
#define xx__Auto2773   ""
#define en_Auto2775   "Behaviour"
#define fr_Auto2775   "Comportement"
#define it_Auto2775   "Behaviour"
#define es_Auto2775   "Behaviour"
#define de_Auto2775   "Behaviour"
#define nl_Auto2775   "Behaviour"
#define pt_Auto2775   "Behaviour"
#define xx_Auto2775   "Behaviour"
#define en__Auto2775   ""
#define fr__Auto2775   ""
#define it__Auto2775   ""
#define es__Auto2775   ""
#define de__Auto2775   ""
#define nl__Auto2775   ""
#define pt__Auto2775   ""
#define xx__Auto2775   ""
#define en_Auto2776   "Appearence"
#define fr_Auto2776   "Apparence"
#define it_Auto2776   "Appearence"
#define es_Auto2776   "Appearence"
#define de_Auto2776   "Appearence"
#define nl_Auto2776   "Appearence"
#define pt_Auto2776   "Appearence"
#define xx_Auto2776   "Appearence"
#define en__Auto2776   ""
#define fr__Auto2776   ""
#define it__Auto2776   ""
#define es__Auto2776   ""
#define de__Auto2776   ""
#define nl__Auto2776   ""
#define pt__Auto2776   ""
#define xx__Auto2776   ""
#define en_Auto2777   "General"
#define fr_Auto2777   "G‚n‚ral"
#define it_Auto2777   "General"
#define es_Auto2777   "General"
#define de_Auto2777   "General"
#define nl_Auto2777   "General"
#define pt_Auto2777   "General"
#define xx_Auto2777   "General"
#define en__Auto2777   ""
#define fr__Auto2777   ""
#define it__Auto2777   ""
#define es__Auto2777   ""
#define de__Auto2777   ""
#define nl__Auto2777   ""
#define pt__Auto2777   ""
#define xx__Auto2777   ""
#define en_Identity   ""
#define fr_Identity   ""
#define en__Identity   ""
#define fr__Identity   ""
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
#define en_AtY   ""
#define en__AtY   ""
#define en_Width   ""
#define en__Width   ""
#define en_Height   ""
#define en__Height   ""
#define en__TextFont   ""
#define fr__TextFont   ""
#define en_PayLoad   ""
#define en__PayLoad   ""
#define en_StyleSheet   ""
#define fr_StyleSheet   ""
#define en__StyleSheet   ""
#define fr__StyleSheet   ""
#define en_FocusStyle   ""
#define fr_FocusStyle   ""
#define en__FocusStyle   ""
#define fr__FocusStyle   ""
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
#define en_Auto2778   "X"
#define fr_Auto2778   "X"
#define it_Auto2778   "X"
#define es_Auto2778   "X"
#define de_Auto2778   "X"
#define nl_Auto2778   "X"
#define pt_Auto2778   "X"
#define xx_Auto2778   "X"
#define en__Auto2778   ""
#define fr__Auto2778   ""
#define it__Auto2778   ""
#define es__Auto2778   ""
#define de__Auto2778   ""
#define nl__Auto2778   ""
#define pt__Auto2778   ""
#define xx__Auto2778   ""
#define en_Auto2779   "Height"
#define fr_Auto2779   "Hauteur"
#define it_Auto2779   "Height"
#define es_Auto2779   "Height"
#define de_Auto2779   "Height"
#define nl_Auto2779   "Height"
#define pt_Auto2779   "Height"
#define xx_Auto2779   "Height"
#define en__Auto2779   ""
#define fr__Auto2779   ""
#define it__Auto2779   ""
#define es__Auto2779   ""
#define de__Auto2779   ""
#define nl__Auto2779   ""
#define pt__Auto2779   ""
#define xx__Auto2779   ""
#define en_Auto2780   "Width"
#define fr_Auto2780   "Largeur"
#define it_Auto2780   "Width"
#define es_Auto2780   "Width"
#define de_Auto2780   "Width"
#define nl_Auto2780   "Width"
#define pt_Auto2780   "Width"
#define xx_Auto2780   "Width"
#define en__Auto2780   ""
#define fr__Auto2780   ""
#define it__Auto2780   ""
#define es__Auto2780   ""
#define de__Auto2780   ""
#define nl__Auto2780   ""
#define pt__Auto2780   ""
#define xx__Auto2780   ""
#define en_Auto2781   "Y"
#define fr_Auto2781   "Y"
#define it_Auto2781   "Y"
#define es_Auto2781   "Y"
#define de_Auto2781   "Y"
#define nl_Auto2781   "Y"
#define pt_Auto2781   "Y"
#define xx_Auto2781   "Y"
#define en__Auto2781   ""
#define fr__Auto2781   ""
#define it__Auto2781   ""
#define es__Auto2781   ""
#define de__Auto2781   ""
#define nl__Auto2781   ""
#define pt__Auto2781   ""
#define xx__Auto2781   ""
#define en_Auto2782   "Font"
#define fr_Auto2782   "Police"
#define it_Auto2782   "Font"
#define es_Auto2782   "Font"
#define de_Auto2782   "Font"
#define nl_Auto2782   "Font"
#define pt_Auto2782   "Font"
#define xx_Auto2782   "Font"
#define en__Auto2782   ""
#define fr__Auto2782   ""
#define it__Auto2782   ""
#define es__Auto2782   ""
#define de__Auto2782   ""
#define nl__Auto2782   ""
#define pt__Auto2782   ""
#define xx__Auto2782   ""
#define en__Auto2783   ""
#define fr__Auto2783   ""
#define it__Auto2783   ""
#define es__Auto2783   ""
#define de__Auto2783   ""
#define nl__Auto2783   ""
#define pt__Auto2783   ""
#define xx__Auto2783   ""
#define en_Auto2784   "Explicit style"
#define fr_Auto2784   "Style explicite"
#define it_Auto2784   "Explicit style"
#define es_Auto2784   "Explicit style"
#define de_Auto2784   "Explicit style"
#define nl_Auto2784   "Explicit style"
#define pt_Auto2784   "Explicit style"
#define xx_Auto2784   "Explicit style"
#define en__Auto2784   ""
#define fr__Auto2784   ""
#define it__Auto2784   ""
#define es__Auto2784   ""
#define de__Auto2784   ""
#define nl__Auto2784   ""
#define pt__Auto2784   ""
#define xx__Auto2784   ""
#define en_Auto2785   "Hint"
#define fr_Auto2785   "Infobulle"
#define it_Auto2785   "Hint"
#define es_Auto2785   "Hint"
#define de_Auto2785   "Hint"
#define nl_Auto2785   "Hint"
#define pt_Auto2785   "Hint"
#define xx_Auto2785   "Hint"
#define en__Auto2785   ""
#define fr__Auto2785   ""
#define it__Auto2785   ""
#define es__Auto2785   ""
#define de__Auto2785   ""
#define nl__Auto2785   ""
#define pt__Auto2785   ""
#define xx__Auto2785   ""
#define en_Auto2786   "Name"
#define fr_Auto2786   "Nom"
#define it_Auto2786   "Name"
#define es_Auto2786   "Name"
#define de_Auto2786   "Name"
#define nl_Auto2786   "Name"
#define pt_Auto2786   "Name"
#define xx_Auto2786   "Name"
#define en__Auto2786   ""
#define fr__Auto2786   ""
#define it__Auto2786   ""
#define es__Auto2786   ""
#define de__Auto2786   ""
#define nl__Auto2786   ""
#define pt__Auto2786   ""
#define xx__Auto2786   ""
#define en_Auto2787   "Widget class"
#define fr_Auto2787   "Classe de widget"
#define it_Auto2787   "Widget class"
#define es_Auto2787   "Widget class"
#define de_Auto2787   "Widget class"
#define nl_Auto2787   "Widget class"
#define pt_Auto2787   "Widget class"
#define xx_Auto2787   "Widget class"
#define en__Auto2787   ""
#define fr__Auto2787   ""
#define it__Auto2787   ""
#define es__Auto2787   ""
#define de__Auto2787   ""
#define nl__Auto2787   ""
#define pt__Auto2787   ""
#define xx__Auto2787   ""
#include "vwcheck.h"
static int	vfh[16];

/*	------------------------	*/
/*	p o s i t i o n _ a t ()	*/
/*	------------------------	*/
void	vwcheck_position_at(struct vwcheck_context * _Context,int x,int y){
	_Context->x_WidgetProperties=x;
	_Context->y_WidgetProperties=y;

}

/*	----------------	*/
/*	S e t V a r s ()	*/
/*	----------------	*/
void	vwcheck_SetVars(struct vwcheck_context * _Context){
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
	visual_signature("SSS","SSS");
	visual_transferin(_Context->buffer_StyleSheet,255,pSpecificWidgetProperties->pStyleSheet);
	visual_transferin(_Context->buffer_FocusStyle,255,pSpecificWidgetProperties->pStyleFocus);
	visual_transferin(_Context->buffer_Hint,255,pSpecificWidgetProperties->pHint);
	if(!(pSpecificWidgetProperties->pWidgetClass))
	_Context->value_WidgetClass=0;
	else _Context->value_WidgetClass=*((int*)pSpecificWidgetProperties->pWidgetClass);
	if(!(pSpecificWidgetProperties->pIsLock))
	_Context->value_IsLock=0;
	else _Context->value_IsLock=*((int*)pSpecificWidgetProperties->pIsLock);
	if(!(pSpecificWidgetProperties->pIsInterface))
	_Context->value_IsInterface=0;
	else _Context->value_IsInterface=*((int*)pSpecificWidgetProperties->pIsInterface);
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
void	vwcheck_GetVars(struct vwcheck_context * _Context){
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
	visual_signature("SSS","SSS");
	visual_transferout(_Context->buffer_StyleSheet,255,pSpecificWidgetProperties->pStyleSheet);
	visual_transferout(_Context->buffer_FocusStyle,255,pSpecificWidgetProperties->pStyleFocus);
	visual_transferout(_Context->buffer_Hint,255,pSpecificWidgetProperties->pHint);
	if(pSpecificWidgetProperties->pWidgetClass!=(char*)0)
	*((int*)pSpecificWidgetProperties->pWidgetClass)=_Context->value_WidgetClass;
	if(pSpecificWidgetProperties->pIsLock!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsLock)=_Context->value_IsLock;
	if(pSpecificWidgetProperties->pIsInterface!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsInterface)=_Context->value_IsInterface;
	if(pSpecificWidgetProperties->pIswResize!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIswResize)=_Context->value_IswResize;
	if(pSpecificWidgetProperties->pIshResize!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIshResize)=_Context->value_IshResize;
	if(pSpecificWidgetProperties->pIswResize!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIswResize)=_Context->value_IswResize;

}

public	int	vwcheck_attach()
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

public	int	vwcheck_attach_mode(int mode)
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

public	int	vwcheck_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	vwcheck_create(struct vwcheck_context **cptr)
{

	int i;
	struct vwcheck_context * _Context=(struct vwcheck_context*)0;
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
	if (!(_Context = allocate( sizeof( struct vwcheck_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=16;
		for (i=0; i < 255; i++)  *(_Context->buffer_Identity+i)=' ';
		_Context->value_WidgetClass=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Hint+i)=' ';
		_Context->value_IsLock=0;
		_Context->value_IsInterface=0;
		for (i=0; i < 7; i++)  *(_Context->buffer_AtX+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_AtY+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Width+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Height+i)=' ';
		_Context->value_TextFont=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_PayLoad+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_StyleSheet+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_FocusStyle+i)=' ';
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
	for (i=0; i < 8; i++)_Context->msg_Auto2773[i]=" ";
	_Context->msg_Auto2773[0]=en_Auto2773;
	_Context->msg_Auto2773[1]=fr_Auto2773;
	_Context->msg_Auto2773[2]=it_Auto2773;
	_Context->msg_Auto2773[3]=es_Auto2773;
	_Context->msg_Auto2773[4]=de_Auto2773;
	_Context->msg_Auto2773[5]=nl_Auto2773;
	_Context->msg_Auto2773[6]=pt_Auto2773;
	_Context->msg_Auto2773[7]=xx_Auto2773;
	_Context->hint_Auto2773[0]=en__Auto2773;
	_Context->hint_Auto2773[1]=fr__Auto2773;
	_Context->hint_Auto2773[2]=it__Auto2773;
	_Context->hint_Auto2773[3]=es__Auto2773;
	_Context->hint_Auto2773[4]=de__Auto2773;
	_Context->hint_Auto2773[5]=nl__Auto2773;
	_Context->hint_Auto2773[6]=pt__Auto2773;
	_Context->hint_Auto2773[7]=xx__Auto2773;
	for (i=0; i < 8; i++)_Context->msg_Auto2775[i]=" ";
	_Context->msg_Auto2775[0]=en_Auto2775;
	_Context->msg_Auto2775[1]=fr_Auto2775;
	_Context->msg_Auto2775[2]=it_Auto2775;
	_Context->msg_Auto2775[3]=es_Auto2775;
	_Context->msg_Auto2775[4]=de_Auto2775;
	_Context->msg_Auto2775[5]=nl_Auto2775;
	_Context->msg_Auto2775[6]=pt_Auto2775;
	_Context->msg_Auto2775[7]=xx_Auto2775;
	_Context->hint_Auto2775[0]=en__Auto2775;
	_Context->hint_Auto2775[1]=fr__Auto2775;
	_Context->hint_Auto2775[2]=it__Auto2775;
	_Context->hint_Auto2775[3]=es__Auto2775;
	_Context->hint_Auto2775[4]=de__Auto2775;
	_Context->hint_Auto2775[5]=nl__Auto2775;
	_Context->hint_Auto2775[6]=pt__Auto2775;
	_Context->hint_Auto2775[7]=xx__Auto2775;
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
	_Context->hint_Identity[0]=en__Identity;
	_Context->hint_Identity[1]=fr__Identity;
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
	_Context->hint_AtY[0]=en__AtY;
	_Context->hint_Width[0]=en__Width;
	_Context->hint_Height[0]=en__Height;
	for (i=0; i < 8; i++)_Context->msg_TextFont[i]=" ";
	_Context->hint_TextFont[0]=en__TextFont;
	_Context->hint_TextFont[1]=fr__TextFont;
	_Context->hint_PayLoad[0]=en__PayLoad;
	_Context->hint_StyleSheet[0]=en__StyleSheet;
	_Context->hint_StyleSheet[1]=fr__StyleSheet;
	_Context->hint_FocusStyle[0]=en__FocusStyle;
	_Context->hint_FocusStyle[1]=fr__FocusStyle;
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

public 	int	vwcheck_hide(struct vwcheck_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;

	return(result);
}

public	int	vwcheck_remove(struct vwcheck_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}

public	int	vwcheck_show(struct vwcheck_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,"widget_frame",_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]))) != 0)
) {
		visual_window(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,vfh[2],_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]),0x4);
		}
	visual_text(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+115,210,16,vfh[2],16,0,_Context->msg_Auto2773[_Context->language],strlen(_Context->msg_Auto2773[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+131,210,62,4);
	visual_filzone(_Context->x_WidgetProperties+252,_Context->y_WidgetProperties+236,1,1,27,0);
	visual_text(_Context->x_WidgetProperties+455,_Context->y_WidgetProperties+31,210,16,vfh[2],16,0,_Context->msg_Auto2775[_Context->language],strlen(_Context->msg_Auto2775[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+455,_Context->y_WidgetProperties+47,210,62,4);
	visual_text(_Context->x_WidgetProperties+8,_Context->y_WidgetProperties+204,658,16,vfh[2],16,0,_Context->msg_Auto2776[_Context->language],strlen(_Context->msg_Auto2776[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+8,_Context->y_WidgetProperties+220,658,83,4);
	visual_text(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+31,442,16,vfh[2],16,0,_Context->msg_Auto2777[_Context->language],strlen(_Context->msg_Auto2777[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+47,442,146,4);
	visual_frame(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+67,192+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+67+1,192,16,vfh[1],34,0,_Context->buffer_Identity,255,0);
	visual_select(_Context->x_WidgetProperties+223,_Context->y_WidgetProperties+66,126,144,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),768);
	visual_frame(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+110,424+2,64+2,5);
	visual_text(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+110+1,424,64,vfh[1],0,0,_Context->buffer_Hint,255,0);
	_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+462,_Context->y_WidgetProperties+59,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
	_Context->trigger_IsInterface=visual_trigger_code(_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]));
	visual_check(_Context->x_WidgetProperties+462,_Context->y_WidgetProperties+80,180,16,vfh[2],28,28,_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]),_Context->value_IsInterface|0);
	visual_frame(_Context->x_WidgetProperties+459,_Context->y_WidgetProperties+156,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+459+1,_Context->y_WidgetProperties+156+1,35,16,vfh[1],34,0,_Context->buffer_AtX,7,0);
	visual_frame(_Context->x_WidgetProperties+505,_Context->y_WidgetProperties+155,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+505+1,_Context->y_WidgetProperties+155+1,35,16,vfh[1],34,0,_Context->buffer_AtY,7,0);
	visual_frame(_Context->x_WidgetProperties+565,_Context->y_WidgetProperties+156,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+565+1,_Context->y_WidgetProperties+156+1,35,16,vfh[1],34,0,_Context->buffer_Width,7,0);
	visual_frame(_Context->x_WidgetProperties+614,_Context->y_WidgetProperties+156,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+614+1,_Context->y_WidgetProperties+156+1,35,16,vfh[1],34,0,_Context->buffer_Height,7,0);
	visual_select(_Context->x_WidgetProperties+16,_Context->y_WidgetProperties+248,182,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),768);
	visual_frame(_Context->x_WidgetProperties+224,_Context->y_WidgetProperties+250,214+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+224+1,_Context->y_WidgetProperties+250+1,214,16,vfh[1],34,0,_Context->buffer_PayLoad,255,0);
	visual_frame(_Context->x_WidgetProperties+462,_Context->y_WidgetProperties+250,190+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+462+1,_Context->y_WidgetProperties+250+1,190,16,vfh[1],0,0,_Context->buffer_StyleSheet,255,0);
	visual_frame(_Context->x_WidgetProperties+462,_Context->y_WidgetProperties+270,190+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+462+1,_Context->y_WidgetProperties+270+1,190,16,vfh[1],0,0,_Context->buffer_FocusStyle,255,0);
	_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+19,_Context->y_WidgetProperties+279,165,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
	_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+225,_Context->y_WidgetProperties+278,140,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
	visual_text(_Context->x_WidgetProperties+462,_Context->y_WidgetProperties+139,14,21,vfh[2],16,0,_Context->msg_Auto2778[_Context->language],strlen(_Context->msg_Auto2778[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+614,_Context->y_WidgetProperties+139,50,21,vfh[2],16,0,_Context->msg_Auto2779[_Context->language],strlen(_Context->msg_Auto2779[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+564,_Context->y_WidgetProperties+138,50,21,vfh[2],16,0,_Context->msg_Auto2780[_Context->language],strlen(_Context->msg_Auto2780[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+504,_Context->y_WidgetProperties+140,14,21,vfh[2],16,0,_Context->msg_Auto2781[_Context->language],strlen(_Context->msg_Auto2781[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+235,180,16,vfh[2],16,0,_Context->msg_Auto2782[_Context->language],strlen(_Context->msg_Auto2782[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+223,_Context->y_WidgetProperties+235,217,16,vfh[2],16,0,WidgetPayload(_Context->value_WidgetClass),strlen(WidgetPayload(_Context->value_WidgetClass)),2);
	visual_text(_Context->x_WidgetProperties+463,_Context->y_WidgetProperties+235,182,16,vfh[2],16,0,_Context->msg_Auto2784[_Context->language],strlen(_Context->msg_Auto2784[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+93,180,16,vfh[2],16,0,_Context->msg_Auto2785[_Context->language],strlen(_Context->msg_Auto2785[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+13,_Context->y_WidgetProperties+53,154,16,vfh[2],16,0,_Context->msg_Auto2786[_Context->language],strlen(_Context->msg_Auto2786[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+223,_Context->y_WidgetProperties+53,135,16,vfh[2],16,0,_Context->msg_Auto2787[_Context->language],strlen(_Context->msg_Auto2787[_Context->language]),2);
	visual_filzone(_Context->x_WidgetProperties+248,_Context->y_WidgetProperties+238,1,1,27,0);
	visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400);

	return(0);
}


public	int	vwcheck_event(
struct vwcheck_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsLock == mb ) return(5);
		if (_Context->trigger_IsInterface == mb ) return(6);
		if (_Context->trigger_IswResize == mb ) return(15);
		if (_Context->trigger_IshResize == mb ) return(16);
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
		vwcheck_show(_Context);
		return(-1);	/* WidgetProperties */

		}
		}
	if (( mx >= (_Context->x_WidgetProperties+14) ) 
	&&  ( my >= (_Context->y_WidgetProperties+67) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+14+192) ) 
	&&  ( my <= (_Context->y_WidgetProperties+67+16))) {
		return(2); /* Identity */
		}
	if (( mx >= (_Context->x_WidgetProperties+223+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+66) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+223+126) ) 
	&&  ( my <= (_Context->y_WidgetProperties+66+16))) {
		return(3); /* WidgetClass */
		}
	if (( mx >= (_Context->x_WidgetProperties+14) ) 
	&&  ( my >= (_Context->y_WidgetProperties+110) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+14+424) ) 
	&&  ( my <= (_Context->y_WidgetProperties+110+64))) {
		return(4); /* Hint */
		}
	if (( mx >= (_Context->x_WidgetProperties+462) ) 
	&&  ( my >= (_Context->y_WidgetProperties+59) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+462+182) ) 
	&&  ( my <= (_Context->y_WidgetProperties+59+16))) {
		return(5); /* IsLock */
		}
	if (( mx >= (_Context->x_WidgetProperties+462) ) 
	&&  ( my >= (_Context->y_WidgetProperties+80) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+462+180) ) 
	&&  ( my <= (_Context->y_WidgetProperties+80+16))) {
		return(6); /* IsInterface */
		}
	if (( mx >= (_Context->x_WidgetProperties+459) ) 
	&&  ( my >= (_Context->y_WidgetProperties+156) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+459+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+156+16))) {
		return(7); /* AtX */
		}
	if (( mx >= (_Context->x_WidgetProperties+505) ) 
	&&  ( my >= (_Context->y_WidgetProperties+155) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+505+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+155+16))) {
		return(8); /* AtY */
		}
	if (( mx >= (_Context->x_WidgetProperties+565) ) 
	&&  ( my >= (_Context->y_WidgetProperties+156) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+565+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+156+16))) {
		return(9); /* Width */
		}
	if (( mx >= (_Context->x_WidgetProperties+614) ) 
	&&  ( my >= (_Context->y_WidgetProperties+156) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+614+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+156+16))) {
		return(10); /* Height */
		}
	if (( mx >= (_Context->x_WidgetProperties+16+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+248) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+16+182) ) 
	&&  ( my <= (_Context->y_WidgetProperties+248+16))) {
		return(11); /* TextFont */
		}
	if (( mx >= (_Context->x_WidgetProperties+224) ) 
	&&  ( my >= (_Context->y_WidgetProperties+250) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+224+214) ) 
	&&  ( my <= (_Context->y_WidgetProperties+250+16))) {
		return(12); /* PayLoad */
		}
	if (( mx >= (_Context->x_WidgetProperties+462) ) 
	&&  ( my >= (_Context->y_WidgetProperties+250) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+462+190) ) 
	&&  ( my <= (_Context->y_WidgetProperties+250+16))) {
		return(13); /* StyleSheet */
		}
	if (( mx >= (_Context->x_WidgetProperties+462) ) 
	&&  ( my >= (_Context->y_WidgetProperties+270) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+462+190) ) 
	&&  ( my <= (_Context->y_WidgetProperties+270+16))) {
		return(14); /* FocusStyle */
		}
	if (( mx >= (_Context->x_WidgetProperties+19) ) 
	&&  ( my >= (_Context->y_WidgetProperties+279) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+19+165) ) 
	&&  ( my <= (_Context->y_WidgetProperties+279+16))) {
		return(15); /* IswResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+225) ) 
	&&  ( my >= (_Context->y_WidgetProperties+278) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+225+140) ) 
	&&  ( my <= (_Context->y_WidgetProperties+278+16))) {
		return(16); /* IshResize */
		}

	return(-1);
}


public	int	vwcheck_focus(struct vwcheck_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Identity */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+67+1,192,16,vfh[1],_Context->buffer_Identity,255);
			break;
			case	0x3 :
				/* WidgetClass */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+223,_Context->y_WidgetProperties+66,126,144,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),774);
				if(change_widget_class(&_Context->value_WidgetClass)!=0){
				return(26);
				}
				break;
			case	0x4 :
				/* Hint */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+110+1,424,64,vfh[1],_Context->buffer_Hint,255);
			break;
			case	0x5 :
				/* IsLock */
				visual_check(_Context->x_WidgetProperties+462,_Context->y_WidgetProperties+59,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),(_Context->value_IsLock |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+462,_Context->y_WidgetProperties+59,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
				break;
			case	0x6 :
				/* IsInterface */
				visual_check(_Context->x_WidgetProperties+462,_Context->y_WidgetProperties+80,180,16,vfh[2],28,28,_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]),(_Context->value_IsInterface |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsInterface=visual_trigger_code(_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]));
	visual_check(_Context->x_WidgetProperties+462,_Context->y_WidgetProperties+80,180,16,vfh[2],28,28,_Context->msg_IsInterface[_Context->language],strlen(_Context->msg_IsInterface[_Context->language]),_Context->value_IsInterface|0);
				break;
			case	0x7 :
				/* AtX */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+459+1,_Context->y_WidgetProperties+156+1,35,16,vfh[1],_Context->buffer_AtX,7);
			break;
			case	0x8 :
				/* AtY */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+505+1,_Context->y_WidgetProperties+155+1,35,16,vfh[1],_Context->buffer_AtY,7);
			break;
			case	0x9 :
				/* Width */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+565+1,_Context->y_WidgetProperties+156+1,35,16,vfh[1],_Context->buffer_Width,7);
			break;
			case	0xa :
				/* Height */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+614+1,_Context->y_WidgetProperties+156+1,35,16,vfh[1],_Context->buffer_Height,7);
			break;
			case	0xb :
				/* TextFont */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+16,_Context->y_WidgetProperties+248,182,96,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),770);
				break;
			case	0xc :
				/* PayLoad */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+224+1,_Context->y_WidgetProperties+250+1,214,16,vfh[1],_Context->buffer_PayLoad,255);
			break;
			case	0xd :
				/* StyleSheet */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+462+1,_Context->y_WidgetProperties+250+1,190,16,vfh[1],_Context->buffer_StyleSheet,255);
			break;
			case	0xe :
				/* FocusStyle */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+462+1,_Context->y_WidgetProperties+270+1,190,16,vfh[1],_Context->buffer_FocusStyle,255);
			break;
			case	0xf :
				/* IswResize */
				visual_check(_Context->x_WidgetProperties+19,_Context->y_WidgetProperties+279,165,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),(_Context->value_IswResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+19,_Context->y_WidgetProperties+279,165,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
				break;
			case	0x10 :
				/* IshResize */
				visual_check(_Context->x_WidgetProperties+225,_Context->y_WidgetProperties+278,140,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),(_Context->value_IshResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+225,_Context->y_WidgetProperties+278,140,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			vwcheck_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=16;
			vwcheck_show(_Context);
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
			if ((retcode=vwcheck_event(_Context)) == -1)
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
					/* IsInterface */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsInterface += 1;
						_Context->value_IsInterface &= 1;
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
					/* StyleSheet */
					continue;
				case	0xe :
					/* FocusStyle */
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

public	int	vwcheck()
{
	int	status=0;
	struct vwcheck_context * _Context=(struct vwcheck_context*) 0;
	status = vwcheck_create(&_Context);
	if ( status != 0) return(status);
	status = vwcheck_show(_Context);
		enter_modal();
	status = vwcheck_focus(_Context);
		leave_modal();
	status = vwcheck_hide(_Context);
	status = vwcheck_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwcheck_c */
