
#ifndef _vwfill_c
#define _vwfill_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vwfill.xml                                               */
/* Target         : vwfill.c                                                 */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "sing.h"
#include "singform.h"
#include "singprot.h"
#define en_WidgetProperties   "Fill - Properties"
#define fr_WidgetProperties   "Fill - Propri�t�s"
#define it_WidgetProperties   "Fill widget- Properties"
#define es_WidgetProperties   "Fill widget- Properties"
#define de_WidgetProperties   "Fill widget- Properties"
#define nl_WidgetProperties   "Fill widget- Properties"
#define pt_WidgetProperties   "Fill widget- Properties"
#define xx_WidgetProperties   "Fill widget- Properties"
#define en__WidgetProperties   ""
#define fr__WidgetProperties   ""
#define it__WidgetProperties   ""
#define es__WidgetProperties   ""
#define de__WidgetProperties   ""
#define nl__WidgetProperties   ""
#define pt__WidgetProperties   ""
#define xx__WidgetProperties   ""
#define en_Auto3606   "Position and dimension"
#define fr_Auto3606   "Position et Dimension"
#define it_Auto3606   "Position and dimension"
#define es_Auto3606   "Position and dimension"
#define de_Auto3606   "Position and dimension"
#define nl_Auto3606   "Position and dimension"
#define pt_Auto3606   "Position and dimension"
#define xx_Auto3606   "Position and dimension"
#define en__Auto3606   ""
#define fr__Auto3606   ""
#define it__Auto3606   ""
#define es__Auto3606   ""
#define de__Auto3606   ""
#define nl__Auto3606   ""
#define pt__Auto3606   ""
#define xx__Auto3606   ""
#define en_Auto3608   "Behaviour"
#define fr_Auto3608   "Comportement"
#define it_Auto3608   "Behaviour"
#define es_Auto3608   "Behaviour"
#define de_Auto3608   "Behaviour"
#define nl_Auto3608   "Behaviour"
#define pt_Auto3608   "Behaviour"
#define xx_Auto3608   "Behaviour"
#define en__Auto3608   ""
#define fr__Auto3608   ""
#define it__Auto3608   ""
#define es__Auto3608   ""
#define de__Auto3608   ""
#define nl__Auto3608   ""
#define pt__Auto3608   ""
#define xx__Auto3608   ""
#define en_Auto3609   "Appearence"
#define fr_Auto3609   "Apparence"
#define it_Auto3609   "Appearence"
#define es_Auto3609   "Appearence"
#define de_Auto3609   "Appearence"
#define nl_Auto3609   "Appearence"
#define pt_Auto3609   "Appearence"
#define xx_Auto3609   "Appearence"
#define en__Auto3609   ""
#define fr__Auto3609   ""
#define it__Auto3609   ""
#define es__Auto3609   ""
#define de__Auto3609   ""
#define nl__Auto3609   ""
#define pt__Auto3609   ""
#define xx__Auto3609   ""
#define en_Auto3610   "General"
#define fr_Auto3610   "G�n�ral"
#define it_Auto3610   "General"
#define es_Auto3610   "General"
#define de_Auto3610   "General"
#define nl_Auto3610   "General"
#define pt_Auto3610   "General"
#define xx_Auto3610   "General"
#define en__Auto3610   ""
#define fr__Auto3610   ""
#define it__Auto3610   ""
#define es__Auto3610   ""
#define de__Auto3610   ""
#define nl__Auto3610   ""
#define pt__Auto3610   ""
#define xx__Auto3610   ""
#define en_Identity   ""
#define en__Identity   ""
#define en__WidgetClass   ""
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
#define en_AtX   ""
#define en__AtX   ""
#define en__Align   ""
#define fr__Align   ""
#define it__Align   ""
#define es__Align   ""
#define de__Align   ""
#define nl__Align   ""
#define pt__Align   ""
#define xx__Align   ""
#define en_AtY   ""
#define en__AtY   ""
#define en_Width   ""
#define en__Width   ""
#define en_Height   ""
#define en__Height   ""
#define en_StyleSheet   ""
#define fr_StyleSheet   ""
#define en__StyleSheet   ""
#define fr__StyleSheet   ""
#define en_TextColour   ""
#define en__TextColour   ""
#define en_Auto3611   "Fore"
#define fr_Auto3611   "Texte"
#define it_Auto3611   "Fore"
#define es_Auto3611   "Fore"
#define de_Auto3611   "Fore"
#define nl_Auto3611   "Fore"
#define pt_Auto3611   "Fore"
#define xx_Auto3611   "Fore"
#define en__Auto3611   ""
#define fr__Auto3611   ""
#define it__Auto3611   ""
#define es__Auto3611   ""
#define de__Auto3611   ""
#define nl__Auto3611   ""
#define pt__Auto3611   ""
#define xx__Auto3611   ""
#define en_Background   ""
#define en__Background   ""
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
#define en_Auto3614   "X"
#define fr_Auto3614   "X"
#define it_Auto3614   "X"
#define es_Auto3614   "X"
#define de_Auto3614   "X"
#define nl_Auto3614   "X"
#define pt_Auto3614   "X"
#define xx_Auto3614   "X"
#define en__Auto3614   ""
#define fr__Auto3614   ""
#define it__Auto3614   ""
#define es__Auto3614   ""
#define de__Auto3614   ""
#define nl__Auto3614   ""
#define pt__Auto3614   ""
#define xx__Auto3614   ""
#define en_Auto3615   "Height"
#define fr_Auto3615   "Hauteur"
#define it_Auto3615   "Height"
#define es_Auto3615   "Height"
#define de_Auto3615   "Height"
#define nl_Auto3615   "Height"
#define pt_Auto3615   "Height"
#define xx_Auto3615   "Height"
#define en__Auto3615   ""
#define fr__Auto3615   ""
#define it__Auto3615   ""
#define es__Auto3615   ""
#define de__Auto3615   ""
#define nl__Auto3615   ""
#define pt__Auto3615   ""
#define xx__Auto3615   ""
#define en_Auto3616   "Width"
#define fr_Auto3616   "Largeur"
#define it_Auto3616   "Width"
#define es_Auto3616   "Width"
#define de_Auto3616   "Width"
#define nl_Auto3616   "Width"
#define pt_Auto3616   "Width"
#define xx_Auto3616   "Width"
#define en__Auto3616   ""
#define fr__Auto3616   ""
#define it__Auto3616   ""
#define es__Auto3616   ""
#define de__Auto3616   ""
#define nl__Auto3616   ""
#define pt__Auto3616   ""
#define xx__Auto3616   ""
#define en_Auto3617   "Y"
#define fr_Auto3617   "Y"
#define it_Auto3617   "Y"
#define es_Auto3617   "Y"
#define de_Auto3617   "Y"
#define nl_Auto3617   "Y"
#define pt_Auto3617   "Y"
#define xx_Auto3617   "Y"
#define en__Auto3617   ""
#define fr__Auto3617   ""
#define it__Auto3617   ""
#define es__Auto3617   ""
#define de__Auto3617   ""
#define nl__Auto3617   ""
#define pt__Auto3617   ""
#define xx__Auto3617   ""
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
#define en_Auto3618   "Back"
#define fr_Auto3618   "Fond"
#define it_Auto3618   "Back"
#define es_Auto3618   "Back"
#define de_Auto3618   "Back"
#define nl_Auto3618   "Back"
#define pt_Auto3618   "Back"
#define xx_Auto3618   "Back"
#define en__Auto3618   ""
#define fr__Auto3618   ""
#define it__Auto3618   ""
#define es__Auto3618   ""
#define de__Auto3618   ""
#define nl__Auto3618   ""
#define pt__Auto3618   ""
#define xx__Auto3618   ""
#define en_Auto3620   "Explicit style"
#define fr_Auto3620   "Style personnalis�"
#define it_Auto3620   "Explicit style"
#define es_Auto3620   "Explicit style"
#define de_Auto3620   "Explicit style"
#define nl_Auto3620   "Explicit style"
#define pt_Auto3620   "Explicit style"
#define xx_Auto3620   "Explicit style"
#define en__Auto3620   ""
#define fr__Auto3620   ""
#define it__Auto3620   ""
#define es__Auto3620   ""
#define de__Auto3620   ""
#define nl__Auto3620   ""
#define pt__Auto3620   ""
#define xx__Auto3620   ""
#define en_Auto3621   "Hint"
#define fr_Auto3621   "Infobulle"
#define it_Auto3621   "Hint"
#define es_Auto3621   "Hint"
#define de_Auto3621   "Hint"
#define nl_Auto3621   "Hint"
#define pt_Auto3621   "Hint"
#define xx_Auto3621   "Hint"
#define en__Auto3621   ""
#define fr__Auto3621   ""
#define it__Auto3621   ""
#define es__Auto3621   ""
#define de__Auto3621   ""
#define nl__Auto3621   ""
#define pt__Auto3621   ""
#define xx__Auto3621   ""
#define en_Auto3622   "Implicit style"
#define fr_Auto3622   "Style implicite"
#define it_Auto3622   "Implicit style"
#define es_Auto3622   "Implicit style"
#define de_Auto3622   "Implicit style"
#define nl_Auto3622   "Implicit style"
#define pt_Auto3622   "Implicit style"
#define xx_Auto3622   "Implicit style"
#define en__Auto3622   ""
#define fr__Auto3622   ""
#define it__Auto3622   ""
#define es__Auto3622   ""
#define de__Auto3622   ""
#define nl__Auto3622   ""
#define pt__Auto3622   ""
#define xx__Auto3622   ""
#define en_Auto3623   "Name"
#define fr_Auto3623   "Nom"
#define it_Auto3623   "Name"
#define es_Auto3623   "Name"
#define de_Auto3623   "Name"
#define nl_Auto3623   "Name"
#define pt_Auto3623   "Name"
#define xx_Auto3623   "Name"
#define en__Auto3623   ""
#define fr__Auto3623   ""
#define it__Auto3623   ""
#define es__Auto3623   ""
#define de__Auto3623   ""
#define nl__Auto3623   ""
#define pt__Auto3623   ""
#define xx__Auto3623   ""
#define en_Auto3624   "Widget class"
#define fr_Auto3624   "Classe de widget"
#define it_Auto3624   "Widget class"
#define es_Auto3624   "Widget class"
#define de_Auto3624   "Widget class"
#define nl_Auto3624   "Widget class"
#define pt_Auto3624   "Widget class"
#define xx_Auto3624   "Widget class"
#define en__Auto3624   ""
#define fr__Auto3624   ""
#define it__Auto3624   ""
#define es__Auto3624   ""
#define de__Auto3624   ""
#define nl__Auto3624   ""
#define pt__Auto3624   ""
#define xx__Auto3624   ""
#include "vwfill.h"
static int	vfh[16];
private int on_fgSelect_event(struct vwfill_context * _Context);

/*	------------------------	*/
/*	p o s i t i o n _ a t ()	*/
/*	------------------------	*/
void	vwfill_position_at(struct vwfill_context * _Context,int x,int y){
	_Context->x_WidgetProperties=x;
	_Context->y_WidgetProperties=y;

}

/*	----------------	*/
/*	S e t V a r s ()	*/
/*	----------------	*/
void	vwfill_SetVars(struct vwfill_context * _Context){
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
	if(!(pSpecificWidgetProperties->pAlign))
	_Context->value_Align=0;
	else _Context->value_Align=*((int*)pSpecificWidgetProperties->pAlign);
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
void	vwfill_GetVars(struct vwfill_context * _Context){
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
	if(pSpecificWidgetProperties->pAlign!=(char*)0)
	*((int*)pSpecificWidgetProperties->pAlign)=_Context->value_Align;
	if(pSpecificWidgetProperties->pIsLock!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIsLock)=_Context->value_IsLock;
	if(pSpecificWidgetProperties->pIswResize!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIswResize)=_Context->value_IswResize;
	if(pSpecificWidgetProperties->pIshResize!=(char*)0)
	*((int*)pSpecificWidgetProperties->pIshResize)=_Context->value_IshResize;

}

public	int	vwfill_attach()
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

public	int	vwfill_attach_mode(int mode)
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

public	int	vwfill_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	vwfill_create(struct vwfill_context **cptr)
{

	int i;
	struct vwfill_context * _Context=(struct vwfill_context*)0;
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
	if (!(_Context = allocate( sizeof( struct vwfill_context ) ) ))
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
		for (i=0; i < 7; i++)  *(_Context->buffer_AtX+i)=' ';
		_Context->value_Align=0;
		for (i=0; i < 7; i++)  *(_Context->buffer_AtY+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Width+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Height+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_StyleSheet+i)=' ';
		for (i=0; i < 6; i++)  *(_Context->buffer_TextColour+i)=' ';
		for (i=0; i < 6; i++)  *(_Context->buffer_Background+i)=' ';
		_Context->value_IswResize=0;
		_Context->value_IshResize=0;
		for (i=0; i < 1; i++)  *(_Context->buffer_Auto3619+i)=' ';
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
	_Context->w_WidgetProperties=672;
	_Context->h_WidgetProperties=399;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3606[i]=" ";
	_Context->msg_Auto3606[0]=en_Auto3606;
	_Context->msg_Auto3606[1]=fr_Auto3606;
	_Context->msg_Auto3606[2]=it_Auto3606;
	_Context->msg_Auto3606[3]=es_Auto3606;
	_Context->msg_Auto3606[4]=de_Auto3606;
	_Context->msg_Auto3606[5]=nl_Auto3606;
	_Context->msg_Auto3606[6]=pt_Auto3606;
	_Context->msg_Auto3606[7]=xx_Auto3606;
	_Context->hint_Auto3606[0]=en__Auto3606;
	_Context->hint_Auto3606[1]=fr__Auto3606;
	_Context->hint_Auto3606[2]=it__Auto3606;
	_Context->hint_Auto3606[3]=es__Auto3606;
	_Context->hint_Auto3606[4]=de__Auto3606;
	_Context->hint_Auto3606[5]=nl__Auto3606;
	_Context->hint_Auto3606[6]=pt__Auto3606;
	_Context->hint_Auto3606[7]=xx__Auto3606;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3609[i]=" ";
	_Context->msg_Auto3609[0]=en_Auto3609;
	_Context->msg_Auto3609[1]=fr_Auto3609;
	_Context->msg_Auto3609[2]=it_Auto3609;
	_Context->msg_Auto3609[3]=es_Auto3609;
	_Context->msg_Auto3609[4]=de_Auto3609;
	_Context->msg_Auto3609[5]=nl_Auto3609;
	_Context->msg_Auto3609[6]=pt_Auto3609;
	_Context->msg_Auto3609[7]=xx_Auto3609;
	_Context->hint_Auto3609[0]=en__Auto3609;
	_Context->hint_Auto3609[1]=fr__Auto3609;
	_Context->hint_Auto3609[2]=it__Auto3609;
	_Context->hint_Auto3609[3]=es__Auto3609;
	_Context->hint_Auto3609[4]=de__Auto3609;
	_Context->hint_Auto3609[5]=nl__Auto3609;
	_Context->hint_Auto3609[6]=pt__Auto3609;
	_Context->hint_Auto3609[7]=xx__Auto3609;
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
	_Context->hint_AtX[0]=en__AtX;
	for (i=0; i < 8; i++)_Context->msg_Align[i]=" ";
	_Context->hint_Align[0]=en__Align;
	_Context->hint_Align[1]=fr__Align;
	_Context->hint_Align[2]=it__Align;
	_Context->hint_Align[3]=es__Align;
	_Context->hint_Align[4]=de__Align;
	_Context->hint_Align[5]=nl__Align;
	_Context->hint_Align[6]=pt__Align;
	_Context->hint_Align[7]=xx__Align;
	_Context->hint_AtY[0]=en__AtY;
	_Context->hint_Width[0]=en__Width;
	_Context->hint_Height[0]=en__Height;
	_Context->hint_StyleSheet[0]=en__StyleSheet;
	_Context->hint_StyleSheet[1]=fr__StyleSheet;
	_Context->hint_TextColour[0]=en__TextColour;
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
	_Context->hint_Background[0]=en__Background;
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
	return(0);
}

public 	int	vwfill_hide(struct vwfill_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;

	return(result);
}

public	int	vwfill_remove(struct vwfill_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	_Context=liberate(_Context);

	return(result);
}

public	int	vwfill_show(struct vwfill_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_WidgetProperties,_Context->y_WidgetProperties,672,399,"widget_frame",_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]))) != 0)
) {
		visual_window(_Context->x_WidgetProperties,_Context->y_WidgetProperties,672,399,vfh[2],_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]),0x4);
		}
	visual_text(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+136,210,16,vfh[2],16,0,_Context->msg_Auto3606[_Context->language],strlen(_Context->msg_Auto3606[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+152,210,59,4);
	visual_filzone(_Context->x_WidgetProperties+302,_Context->y_WidgetProperties+307,1,1,27,0);
	visual_text(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+57,210,16,vfh[2],16,0,_Context->msg_Auto3608[_Context->language],strlen(_Context->msg_Auto3608[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+454,_Context->y_WidgetProperties+73,210,59,4);
	visual_text(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+234,658,16,vfh[2],16,0,_Context->msg_Auto3609[_Context->language],strlen(_Context->msg_Auto3609[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+250,658,95,4);
	visual_text(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+57,444,16,vfh[2],16,0,_Context->msg_Auto3610[_Context->language],strlen(_Context->msg_Auto3610[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+73,444,138,4);
	visual_frame(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+92,192+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+92+1,192,16,vfh[1],34,0,_Context->buffer_Identity,255,0);
	visual_select(_Context->x_WidgetProperties+226,_Context->y_WidgetProperties+92,126,144,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),768);
	visual_frame(_Context->x_WidgetProperties+16,_Context->y_WidgetProperties+133,424+2,64+2,5);
	visual_text(_Context->x_WidgetProperties+16+1,_Context->y_WidgetProperties+133+1,424,64,vfh[1],0,0,_Context->buffer_Hint,255,0);
	_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+461,_Context->y_WidgetProperties+94,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
	visual_frame(_Context->x_WidgetProperties+464,_Context->y_WidgetProperties+180,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+464+1,_Context->y_WidgetProperties+180+1,35,16,vfh[1],34,0,_Context->buffer_AtX,7,0);
	visual_select(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+282,196,112,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),768);
	visual_frame(_Context->x_WidgetProperties+506,_Context->y_WidgetProperties+180,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+506+1,_Context->y_WidgetProperties+180+1,35,16,vfh[1],34,0,_Context->buffer_AtY,7,0);
	visual_frame(_Context->x_WidgetProperties+562,_Context->y_WidgetProperties+181,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+562+1,_Context->y_WidgetProperties+181+1,35,16,vfh[1],34,0,_Context->buffer_Width,7,0);
	visual_frame(_Context->x_WidgetProperties+609,_Context->y_WidgetProperties+181,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+609+1,_Context->y_WidgetProperties+181+1,35,16,vfh[1],34,0,_Context->buffer_Height,7,0);
	visual_frame(_Context->x_WidgetProperties+225,_Context->y_WidgetProperties+282,190+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+225+1,_Context->y_WidgetProperties+282+1,190,16,vfh[1],0,0,_Context->buffer_StyleSheet,255,0);
	visual_frame(_Context->x_WidgetProperties+464,_Context->y_WidgetProperties+282,42+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+464+1,_Context->y_WidgetProperties+282+1,42,16,vfh[1],34,0,_Context->buffer_TextColour,6,0);
	visual_text(_Context->x_WidgetProperties+464,_Context->y_WidgetProperties+266,42,16,vfh[2],16,0,_Context->msg_Auto3611[_Context->language],strlen(_Context->msg_Auto3611[_Context->language]),2);
	visual_frame(_Context->x_WidgetProperties+552,_Context->y_WidgetProperties+282,42+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+552+1,_Context->y_WidgetProperties+282+1,42,16,vfh[1],34,0,_Context->buffer_Background,6,0);
	visual_filzone(_Context->x_WidgetProperties+302,_Context->y_WidgetProperties+306,1,1,27,0);
	_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+320,196,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
	_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+226,_Context->y_WidgetProperties+320,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
	visual_filzone(_Context->x_WidgetProperties+298,_Context->y_WidgetProperties+308,1,1,27,0);
	visual_text(_Context->x_WidgetProperties+465,_Context->y_WidgetProperties+163,14,21,vfh[2],16,0,_Context->msg_Auto3614[_Context->language],strlen(_Context->msg_Auto3614[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+610,_Context->y_WidgetProperties+165,50,21,vfh[2],16,0,_Context->msg_Auto3615[_Context->language],strlen(_Context->msg_Auto3615[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+560,_Context->y_WidgetProperties+165,54,21,vfh[2],16,0,_Context->msg_Auto3616[_Context->language],strlen(_Context->msg_Auto3616[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+506,_Context->y_WidgetProperties+163,14,21,vfh[2],16,0,_Context->msg_Auto3617[_Context->language],strlen(_Context->msg_Auto3617[_Context->language]),2);
	_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+508,_Context->y_WidgetProperties+282,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
	visual_text(_Context->x_WidgetProperties+553,_Context->y_WidgetProperties+265,42,16,vfh[2],16,0,_Context->msg_Auto3618[_Context->language],strlen(_Context->msg_Auto3618[_Context->language]),2);
	visual_frame(_Context->x_WidgetProperties+29,_Context->y_WidgetProperties+86,1+2,1+2,5);
	visual_text(_Context->x_WidgetProperties+29+1,_Context->y_WidgetProperties+86+1,1,1,vfh[1],27,28,_Context->buffer_Auto3619,1,0);
	visual_text(_Context->x_WidgetProperties+226,_Context->y_WidgetProperties+268,112,16,vfh[2],16,0,_Context->msg_Auto3620[_Context->language],strlen(_Context->msg_Auto3620[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+17,_Context->y_WidgetProperties+119,160,16,vfh[2],16,0,_Context->msg_Auto3621[_Context->language],strlen(_Context->msg_Auto3621[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+266,126,16,vfh[2],16,0,_Context->msg_Auto3622[_Context->language],strlen(_Context->msg_Auto3622[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+79,154,16,vfh[2],16,0,_Context->msg_Auto3623[_Context->language],strlen(_Context->msg_Auto3623[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+225,_Context->y_WidgetProperties+79,135,16,vfh[2],16,0,_Context->msg_Auto3624[_Context->language],strlen(_Context->msg_Auto3624[_Context->language]),2);
	visual_filzone(_Context->x_WidgetProperties+298,_Context->y_WidgetProperties+309,1,1,27,0);
	visual_thaw(_Context->x_WidgetProperties,_Context->y_WidgetProperties,672,399);

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
			mptr[1]=" Vous aurez acc�s par programmation � cette valeur en utilisant la ";
			mptr[2]="propri�t� this.FG.     ";
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
			mptr[1]=" Vous aurez acc�s par programmation � cette valeur en utilisant la ";
			mptr[2]="propri�t� this.BG.     ";
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
private int on_fgSelect_event(struct vwfill_context * _Context) {
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
		vwfill_show(_Context);
;
	return(-1);
}


public	int	vwfill_event(
struct vwfill_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsLock == mb ) return(5);
		if (_Context->trigger_IswResize == mb ) return(14);
		if (_Context->trigger_IshResize == mb ) return(15);
		if (_Context->trigger_fgSelect == mb ) return(16);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_WidgetProperties+619) )  
	&&  (my >= (_Context->y_WidgetProperties+4) )  
	&&  (mx <= (_Context->x_WidgetProperties+636) )  
	&&  (my <= (_Context->y_WidgetProperties+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		vwfill_show(_Context);
		return(-1);	/* WidgetProperties */

		}
		}
	if (( mx >= (_Context->x_WidgetProperties+14) ) 
	&&  ( my >= (_Context->y_WidgetProperties+92) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+14+192) ) 
	&&  ( my <= (_Context->y_WidgetProperties+92+16))) {
		return(2); /* Identity */
		}
	if (( mx >= (_Context->x_WidgetProperties+226+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+92) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+226+126) ) 
	&&  ( my <= (_Context->y_WidgetProperties+92+16))) {
		return(3); /* WidgetClass */
		}
	if (( mx >= (_Context->x_WidgetProperties+16) ) 
	&&  ( my >= (_Context->y_WidgetProperties+133) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+16+424) ) 
	&&  ( my <= (_Context->y_WidgetProperties+133+64))) {
		return(4); /* Hint */
		}
	if (( mx >= (_Context->x_WidgetProperties+461) ) 
	&&  ( my >= (_Context->y_WidgetProperties+94) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+461+182) ) 
	&&  ( my <= (_Context->y_WidgetProperties+94+16))) {
		return(5); /* IsLock */
		}
	if (( mx >= (_Context->x_WidgetProperties+464) ) 
	&&  ( my >= (_Context->y_WidgetProperties+180) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+464+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+180+16))) {
		return(6); /* AtX */
		}
	if (( mx >= (_Context->x_WidgetProperties+12+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+282) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+12+196) ) 
	&&  ( my <= (_Context->y_WidgetProperties+282+16))) {
		return(7); /* Align */
		}
	if (( mx >= (_Context->x_WidgetProperties+506) ) 
	&&  ( my >= (_Context->y_WidgetProperties+180) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+506+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+180+16))) {
		return(8); /* AtY */
		}
	if (( mx >= (_Context->x_WidgetProperties+562) ) 
	&&  ( my >= (_Context->y_WidgetProperties+181) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+562+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+181+16))) {
		return(9); /* Width */
		}
	if (( mx >= (_Context->x_WidgetProperties+609) ) 
	&&  ( my >= (_Context->y_WidgetProperties+181) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+609+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+181+16))) {
		return(10); /* Height */
		}
	if (( mx >= (_Context->x_WidgetProperties+225) ) 
	&&  ( my >= (_Context->y_WidgetProperties+282) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+225+190) ) 
	&&  ( my <= (_Context->y_WidgetProperties+282+16))) {
		return(11); /* StyleSheet */
		}
	if (( mx >= (_Context->x_WidgetProperties+464) ) 
	&&  ( my >= (_Context->y_WidgetProperties+282) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+464+42) ) 
	&&  ( my <= (_Context->y_WidgetProperties+282+16))) {
		return(12); /* TextColour */
		}
	if (( mx >= (_Context->x_WidgetProperties+552) ) 
	&&  ( my >= (_Context->y_WidgetProperties+282) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+552+42) ) 
	&&  ( my <= (_Context->y_WidgetProperties+282+16))) {
		return(13); /* Background */
		}
	if (( mx >= (_Context->x_WidgetProperties+15) ) 
	&&  ( my >= (_Context->y_WidgetProperties+320) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+15+196) ) 
	&&  ( my <= (_Context->y_WidgetProperties+320+16))) {
		return(14); /* IswResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+226) ) 
	&&  ( my >= (_Context->y_WidgetProperties+320) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+226+165) ) 
	&&  ( my <= (_Context->y_WidgetProperties+320+16))) {
		return(15); /* IshResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+508) ) 
	&&  ( my >= (_Context->y_WidgetProperties+282) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+508+44) ) 
	&&  ( my <= (_Context->y_WidgetProperties+282+18))) {
		return(16); /* fgSelect */
		}
	if (( mx >= (_Context->x_WidgetProperties+29) ) 
	&&  ( my >= (_Context->y_WidgetProperties+86) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+29+1) ) 
	&&  ( my <= (_Context->y_WidgetProperties+86+1))) {
		return(17); /* Auto3619 */
		}

	return(-1);
}


public	int	vwfill_focus(struct vwfill_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Identity */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+92+1,192,16,vfh[1],_Context->buffer_Identity,255);
			break;
			case	0x3 :
				/* WidgetClass */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+226,_Context->y_WidgetProperties+92,126,144,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),774);
				if(change_widget_class(&_Context->value_WidgetClass)!=0){
				return(26);
				}
				break;
			case	0x4 :
				/* Hint */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+16+1,_Context->y_WidgetProperties+133+1,424,64,vfh[1],_Context->buffer_Hint,255);
			break;
			case	0x5 :
				/* IsLock */
				visual_check(_Context->x_WidgetProperties+461,_Context->y_WidgetProperties+94,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),(_Context->value_IsLock |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+461,_Context->y_WidgetProperties+94,182,16,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
				break;
			case	0x6 :
				/* AtX */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+464+1,_Context->y_WidgetProperties+180+1,35,16,vfh[1],_Context->buffer_AtX,7);
			break;
			case	0x7 :
				/* Align */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+282,196,112,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),774);
				break;
			case	0x8 :
				/* AtY */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+506+1,_Context->y_WidgetProperties+180+1,35,16,vfh[1],_Context->buffer_AtY,7);
			break;
			case	0x9 :
				/* Width */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+562+1,_Context->y_WidgetProperties+181+1,35,16,vfh[1],_Context->buffer_Width,7);
			break;
			case	0xa :
				/* Height */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+609+1,_Context->y_WidgetProperties+181+1,35,16,vfh[1],_Context->buffer_Height,7);
			break;
			case	0xb :
				/* StyleSheet */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+225+1,_Context->y_WidgetProperties+282+1,190,16,vfh[1],_Context->buffer_StyleSheet,255);
			break;
			case	0xc :
				/* TextColour */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+464+1,_Context->y_WidgetProperties+282+1,42,16,vfh[1],_Context->buffer_TextColour,6);
			break;
			case	0xd :
				/* Background */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+552+1,_Context->y_WidgetProperties+282+1,42,16,vfh[1],_Context->buffer_Background,6);
			break;
			case	0xe :
				/* IswResize */
				visual_check(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+320,196,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),(_Context->value_IswResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+15,_Context->y_WidgetProperties+320,196,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
				break;
			case	0xf :
				/* IshResize */
				visual_check(_Context->x_WidgetProperties+226,_Context->y_WidgetProperties+320,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),(_Context->value_IshResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+226,_Context->y_WidgetProperties+320,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
				break;
			case	0x10 :
				/* fgSelect */
				_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
				visual_button(_Context->x_WidgetProperties+508,_Context->y_WidgetProperties+282,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+508,_Context->y_WidgetProperties+282,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
				break;
			case	0x11 :
				/* Auto3619 */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+29+1,_Context->y_WidgetProperties+86+1,1,1,vfh[1],_Context->buffer_Auto3619,1);
			break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			vwfill_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=17;
			vwfill_show(_Context);
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
			if ((retcode=vwfill_event(_Context)) == -1)
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
						if (AtX_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (Align_help(_Context) != 0) { continue; }
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
						if (StyleSheet_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (TextColour_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (Background_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (IswResize_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (IshResize_help(_Context) != 0) { continue; }
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
					/* AtX */
					continue;
				case	0x7 :
					/* Align */
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
					/* StyleSheet */
					continue;
				case	0xc :
					/* TextColour */
					continue;
				case	0xd :
					/* Background */
					continue;
				case	0xe :
					/* IswResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IswResize += 1;
						_Context->value_IswResize &= 1;
						}
					continue;
				case	0xf :
					/* IshResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IshResize += 1;
						_Context->value_IshResize &= 1;
						}
					continue;
				case	0x10 :
					/* fgSelect */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
						visual_button(_Context->x_WidgetProperties+508,_Context->y_WidgetProperties+282,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+508,_Context->y_WidgetProperties+282,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_fgSelect_event(_Context)) != -1) break;

						}
					continue;
				case	0x11 :
					/* Auto3619 */
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

public	int	vwfill()
{
	int	status=0;
	struct vwfill_context * _Context=(struct vwfill_context*) 0;
	status = vwfill_create(&_Context);
	if ( status != 0) return(status);
	status = vwfill_show(_Context);
		enter_modal();
	status = vwfill_focus(_Context);
		leave_modal();
	status = vwfill_hide(_Context);
	status = vwfill_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwfill_c */
