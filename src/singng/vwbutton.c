
#ifndef _vwbutton_c
#define _vwbutton_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : vwbutton.xml                                             */
/* Target         : vwbutton.c                                               */
/* Identification : 0.0-1195558265-4824.4823                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "sing.h"
#include "singform.h"
#include "singprot.h"
#define en_WidgetProperties   "Button widget - Properties"
#define fr_WidgetProperties   "Button - Propri‚t‚s"
#define it_WidgetProperties   "Button widget - Properties"
#define es_WidgetProperties   "Button widget - Properties"
#define de_WidgetProperties   "Button widget - Properties"
#define nl_WidgetProperties   "Button widget - Properties"
#define pt_WidgetProperties   "Button widget - Properties"
#define xx_WidgetProperties   "Button widget - Properties"
#define en__WidgetProperties   ""
#define fr__WidgetProperties   ""
#define it__WidgetProperties   ""
#define es__WidgetProperties   ""
#define de__WidgetProperties   ""
#define nl__WidgetProperties   ""
#define pt__WidgetProperties   ""
#define xx__WidgetProperties   ""
#define en_Auto3028   "Position and Dimension"
#define fr_Auto3028   "Position et Dimension"
#define it_Auto3028   "Position and Dimension"
#define es_Auto3028   "Position and Dimension"
#define de_Auto3028   "Position and Dimension"
#define nl_Auto3028   "Position and Dimension"
#define pt_Auto3028   "Position and Dimension"
#define xx_Auto3028   "Position and Dimension"
#define en__Auto3028   ""
#define fr__Auto3028   ""
#define it__Auto3028   ""
#define es__Auto3028   ""
#define de__Auto3028   ""
#define nl__Auto3028   ""
#define pt__Auto3028   ""
#define xx__Auto3028   ""
#define en_Auto3030   "Behaviour"
#define fr_Auto3030   "Comportement"
#define it_Auto3030   "Behaviour"
#define es_Auto3030   "Behaviour"
#define de_Auto3030   "Behaviour"
#define nl_Auto3030   "Behaviour"
#define pt_Auto3030   "Behaviour"
#define xx_Auto3030   "Behaviour"
#define en__Auto3030   ""
#define fr__Auto3030   ""
#define it__Auto3030   ""
#define es__Auto3030   ""
#define de__Auto3030   ""
#define nl__Auto3030   ""
#define pt__Auto3030   ""
#define xx__Auto3030   ""
#define en_Auto3031   "Appearence"
#define fr_Auto3031   "Apparence"
#define it_Auto3031   "Appearence"
#define es_Auto3031   "Appearence"
#define de_Auto3031   "Appearence"
#define nl_Auto3031   "Appearence"
#define pt_Auto3031   "Appearence"
#define xx_Auto3031   "Appearence"
#define en__Auto3031   ""
#define fr__Auto3031   ""
#define it__Auto3031   ""
#define es__Auto3031   ""
#define de__Auto3031   ""
#define nl__Auto3031   ""
#define pt__Auto3031   ""
#define xx__Auto3031   ""
#define en_Auto3032   "General"
#define fr_Auto3032   "G‚n‚ral"
#define it_Auto3032   "General"
#define es_Auto3032   "General"
#define de_Auto3032   "General"
#define nl_Auto3032   "General"
#define pt_Auto3032   "General"
#define xx_Auto3032   "General"
#define en__Auto3032   ""
#define fr__Auto3032   ""
#define it__Auto3032   ""
#define es__Auto3032   ""
#define de__Auto3032   ""
#define nl__Auto3032   ""
#define pt__Auto3032   ""
#define xx__Auto3032   ""
#define fr_Identity   ""
#define fr__Identity   ""
#define en__WidgetClass   ""
#define fr__WidgetClass   ""
#define fr_Hint   ""
#define fr__Hint   ""
#define fr_AtX   ""
#define fr__AtX   ""
#define fr_AtY   ""
#define fr__AtY   ""
#define fr_Width   ""
#define fr__Width   ""
#define fr_Height   ""
#define fr__Height   ""
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
#define en__Type   ""
#define fr__Type   ""
#define en_Format   ""
#define fr_Format   ""
#define en__Format   ""
#define fr__Format   ""
#define en_TargetSelect   "*"
#define fr_TargetSelect   "*"
#define it_TargetSelect   "*"
#define es_TargetSelect   "*"
#define de_TargetSelect   "*"
#define nl_TargetSelect   "*"
#define pt_TargetSelect   "*"
#define xx_TargetSelect   "*"
#define en__TargetSelect   ""
#define fr__TextFont   ""
#define en_TextColour   ""
#define fr_TextColour   ""
#define en__TextColour   ""
#define fr__TextColour   ""
#define en_Background   ""
#define fr_Background   ""
#define en__Background   ""
#define fr__Background   ""
#define en__Align   ""
#define fr__Align   ""
#define it__Align   ""
#define es__Align   ""
#define de__Align   ""
#define nl__Align   ""
#define pt__Align   ""
#define xx__Align   ""
#define en_ShowStyle   ""
#define fr_ShowStyle   ""
#define en__ShowStyle   ""
#define fr__ShowStyle   ""
#define en_FocusStyle   ""
#define en__FocusStyle   ""
#define en_FocusPress   ""
#define en__FocusPress   ""
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
#define en__IsBold   ""
#define fr__IsBold   ""
#define en__IsUnderline   ""
#define fr__IsUnderline   ""
#define en__IsShadow   ""
#define fr__IsShadow   ""
#define en_Auto3033   "X"
#define fr_Auto3033   "X"
#define it_Auto3033   "Position"
#define es_Auto3033   "Position"
#define de_Auto3033   "Position"
#define nl_Auto3033   "Position"
#define pt_Auto3033   "Position"
#define xx_Auto3033   "Aite"
#define en__Auto3033   ""
#define fr__Auto3033   ""
#define it__Auto3033   ""
#define es__Auto3033   ""
#define de__Auto3033   ""
#define nl__Auto3033   ""
#define pt__Auto3033   ""
#define xx__Auto3033   ""
#define en_Auto3034   "Height"
#define fr_Auto3034   "Hauteur"
#define it_Auto3034   "Height"
#define es_Auto3034   "Height"
#define de_Auto3034   "Height"
#define nl_Auto3034   "Height"
#define pt_Auto3034   "Height"
#define xx_Auto3034   "Height"
#define en__Auto3034   ""
#define fr__Auto3034   ""
#define it__Auto3034   ""
#define es__Auto3034   ""
#define de__Auto3034   ""
#define nl__Auto3034   ""
#define pt__Auto3034   ""
#define xx__Auto3034   ""
#define en_Auto3035   "Width"
#define fr_Auto3035   "Largeur"
#define it_Auto3035   "Width"
#define es_Auto3035   "Width"
#define de_Auto3035   "Width"
#define nl_Auto3035   "Width"
#define pt_Auto3035   "Width"
#define xx_Auto3035   "Width"
#define en__Auto3035   ""
#define fr__Auto3035   ""
#define it__Auto3035   ""
#define es__Auto3035   ""
#define de__Auto3035   ""
#define nl__Auto3035   ""
#define pt__Auto3035   ""
#define xx__Auto3035   ""
#define en_Auto3036   "Y"
#define fr_Auto3036   "Y"
#define it_Auto3036   "Position"
#define es_Auto3036   "Position"
#define de_Auto3036   "Position"
#define nl_Auto3036   "Position"
#define pt_Auto3036   "Position"
#define xx_Auto3036   "Aite"
#define en__Auto3036   ""
#define fr__Auto3036   ""
#define it__Auto3036   ""
#define es__Auto3036   ""
#define de__Auto3036   ""
#define nl__Auto3036   ""
#define pt__Auto3036   ""
#define xx__Auto3036   ""
#define en_Auto3037   "Font"
#define fr_Auto3037   "Police"
#define it_Auto3037   "Font"
#define es_Auto3037   "Font"
#define de_Auto3037   "Font"
#define nl_Auto3037   "Font"
#define pt_Auto3037   "Font"
#define xx_Auto3037   "Font"
#define en__Auto3037   ""
#define fr__Auto3037   ""
#define it__Auto3037   ""
#define es__Auto3037   ""
#define de__Auto3037   ""
#define nl__Auto3037   ""
#define pt__Auto3037   ""
#define xx__Auto3037   ""
#define en__Auto3038   ""
#define fr__Auto3038   ""
#define it__Auto3038   ""
#define es__Auto3038   ""
#define de__Auto3038   ""
#define nl__Auto3038   ""
#define pt__Auto3038   ""
#define xx__Auto3038   ""
#define en_Auto3039   "Fore"
#define fr_Auto3039   "Texte"
#define it_Auto3039   "Fore"
#define es_Auto3039   "Fore"
#define de_Auto3039   "Fore"
#define nl_Auto3039   "Fore"
#define pt_Auto3039   "Fore"
#define xx_Auto3039   "Fore"
#define en__Auto3039   ""
#define fr__Auto3039   ""
#define it__Auto3039   ""
#define es__Auto3039   ""
#define de__Auto3039   ""
#define nl__Auto3039   ""
#define pt__Auto3039   ""
#define xx__Auto3039   ""
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
#define en_Auto3040   "Back"
#define fr_Auto3040   "Fond"
#define it_Auto3040   "Back"
#define es_Auto3040   "Back"
#define de_Auto3040   "Back"
#define nl_Auto3040   "Back"
#define pt_Auto3040   "Back"
#define xx_Auto3040   "Back"
#define en__Auto3040   ""
#define fr__Auto3040   ""
#define it__Auto3040   ""
#define es__Auto3040   ""
#define de__Auto3040   ""
#define nl__Auto3040   ""
#define pt__Auto3040   ""
#define xx__Auto3040   ""
#define en_Auto3041   "Style : Show/Focus/Press"
#define fr_Auto3041   "Style explicite: Show/Focus"
#define it_Auto3041   "Explicit style : Show/Focus"
#define es_Auto3041   "Explicit style : Show/Focus"
#define de_Auto3041   "Explicit style : Show/Focus"
#define nl_Auto3041   "Explicit style : Show/Focus"
#define pt_Auto3041   "Explicit style : Show/Focus"
#define xx_Auto3041   "Explicit style : Show/Focus"
#define en__Auto3041   ""
#define fr__Auto3041   ""
#define it__Auto3041   ""
#define es__Auto3041   ""
#define de__Auto3041   ""
#define nl__Auto3041   ""
#define pt__Auto3041   ""
#define xx__Auto3041   ""
#define en_Auto3042   "Hint"
#define fr_Auto3042   "Infobulle"
#define it_Auto3042   "Hint"
#define es_Auto3042   "Hint"
#define de_Auto3042   "Hint"
#define nl_Auto3042   "Hint"
#define pt_Auto3042   "Hint"
#define xx_Auto3042   "Hint"
#define en__Auto3042   ""
#define fr__Auto3042   ""
#define it__Auto3042   ""
#define es__Auto3042   ""
#define de__Auto3042   ""
#define nl__Auto3042   ""
#define pt__Auto3042   ""
#define xx__Auto3042   ""
#define en_Auto3043   "Implicit style"
#define fr_Auto3043   "Style implicite"
#define it_Auto3043   "Implicit style"
#define es_Auto3043   "Implicit style"
#define de_Auto3043   "Implicit style"
#define nl_Auto3043   "Implicit style"
#define pt_Auto3043   "Implicit style"
#define xx_Auto3043   "Implicit style"
#define en__Auto3043   ""
#define fr__Auto3043   ""
#define it__Auto3043   ""
#define es__Auto3043   ""
#define de__Auto3043   ""
#define nl__Auto3043   ""
#define pt__Auto3043   ""
#define xx__Auto3043   ""
#define en_Auto3044   "Name"
#define fr_Auto3044   "Nom"
#define it_Auto3044   "Name"
#define es_Auto3044   "Name"
#define de_Auto3044   "Name"
#define nl_Auto3044   "Name"
#define pt_Auto3044   "Name"
#define xx_Auto3044   "Name"
#define en__Auto3044   ""
#define fr__Auto3044   ""
#define it__Auto3044   ""
#define es__Auto3044   ""
#define de__Auto3044   ""
#define nl__Auto3044   ""
#define pt__Auto3044   ""
#define xx__Auto3044   ""
#define en_Auto3045   "Widget class"
#define fr_Auto3045   "Classe de widget"
#define it_Auto3045   "Widget class"
#define es_Auto3045   "Widget class"
#define de_Auto3045   "Widget class"
#define nl_Auto3045   "Widget class"
#define pt_Auto3045   "Widget class"
#define xx_Auto3045   "Widget class"
#define en__Auto3045   ""
#define fr__Auto3045   ""
#define it__Auto3045   ""
#define es__Auto3045   ""
#define de__Auto3045   ""
#define nl__Auto3045   ""
#define pt__Auto3045   ""
#define xx__Auto3045   ""
#define en_PayLoadSelect   "*"
#define fr_PayLoadSelect   "*"
#define it_PayLoadSelect   "*"
#define es_PayLoadSelect   "*"
#define de_PayLoadSelect   "*"
#define nl_PayLoadSelect   "*"
#define pt_PayLoadSelect   "*"
#define xx_PayLoadSelect   "*"
#define en__PayLoadSelect   ""
#define fr__PayLoadSelect   ""
#define xx_Auto3046   "Doigh"
#define en__Auto3046   ""
#define fr__Auto3046   ""
#define it__Auto3046   ""
#define es__Auto3046   ""
#define de__Auto3046   ""
#define nl__Auto3046   ""
#define pt__Auto3046   ""
#define xx__Auto3046   ""
#define en_Auto3047   "Action Type"
#define fr_Auto3047   "Action"
#define it_Auto3047   "Action Type"
#define es_Auto3047   "Action Type"
#define de_Auto3047   "Action Type"
#define nl_Auto3047   "Action Type"
#define pt_Auto3047   "Action Type"
#define xx_Auto3047   "Action Type"
#define en__Auto3047   ""
#define fr__Auto3047   ""
#define it__Auto3047   ""
#define es__Auto3047   ""
#define de__Auto3047   ""
#define nl__Auto3047   ""
#define pt__Auto3047   ""
#define xx__Auto3047   ""
#include "vwbutton.h"
static int	vfh[16];

/*	------------------------	*/
/*	p o s i t i o n _ a t ()	*/
/*	------------------------	*/
void	vwbutton_position_at(struct vwbutton_context * _Context,int x,int y){
	_Context->x_WidgetProperties=x;
	_Context->y_WidgetProperties=y;

}

/*	----------------	*/
/*	S e t V a r s ()	*/
/*	----------------	*/
void	vwbutton_SetVars(struct vwbutton_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	visual_signature("WWWW","WWWW");
	visual_transferin(_Context->buffer_AtX,7,pSpecificWidgetProperties->pAtX);
	visual_transferin(_Context->buffer_AtY,7,pSpecificWidgetProperties->pAtY);
	visual_transferin(_Context->buffer_Width,7,pSpecificWidgetProperties->pWidth);
	visual_transferin(_Context->buffer_Height,7,pSpecificWidgetProperties->pHeight);
	if(!(pSpecificWidgetProperties->pTextFont))
	_Context->value_TextFont=0;
	else _Context->value_TextFont=*((int*)pSpecificWidgetProperties->pTextFont);
	visual_signature("WWSSS","WWSSS");
	visual_transferin(_Context->buffer_TextColour,6,pSpecificWidgetProperties->pTextColour);
	visual_transferin(_Context->buffer_Background,6,pSpecificWidgetProperties->pBackground);
	visual_transferin(_Context->buffer_PayLoad,255,pSpecificWidgetProperties->pPayLoad);
	visual_transferin(_Context->buffer_Identity,255,pSpecificWidgetProperties->pIdentity);
	visual_transferin(_Context->buffer_Format,255,pSpecificWidgetProperties->pFormat);
	visual_signature("SSSS","SSSS");
	visual_transferin(_Context->buffer_ShowStyle,255,pSpecificWidgetProperties->pStyleSheet);
	visual_transferin(_Context->buffer_FocusStyle,255,pSpecificWidgetProperties->pStyleFocus);
	visual_transferin(_Context->buffer_FocusPress,255,pSpecificWidgetProperties->pStylePress);
	visual_transferin(_Context->buffer_Hint,255,pSpecificWidgetProperties->pHint);
	if(!(pSpecificWidgetProperties->pWidgetClass))
	_Context->value_WidgetClass=0;
	else _Context->value_WidgetClass=*((int*)pSpecificWidgetProperties->pWidgetClass);
	if(!(pSpecificWidgetProperties->pAlign))
	_Context->value_Align=0;
	else _Context->value_Align=*((int*)pSpecificWidgetProperties->pAlign);
	if(!(pSpecificWidgetProperties->pType))
	_Context->value_Type=0;
	else _Context->value_Type=*((int*)pSpecificWidgetProperties->pType);
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
void	vwbutton_GetVars(struct vwbutton_context * _Context){
	struct SpecificWidgetProperties*pSpecificWidgetProperties=get_form_widgetProperties();
	visual_signature("WWWW","WWWW");
	visual_transferout(_Context->buffer_AtX,7,pSpecificWidgetProperties->pAtX);
	visual_transferout(_Context->buffer_AtY,7,pSpecificWidgetProperties->pAtY);
	visual_transferout(_Context->buffer_Width,7,pSpecificWidgetProperties->pWidth);
	visual_transferout(_Context->buffer_Height,7,pSpecificWidgetProperties->pHeight);
	if(pSpecificWidgetProperties->pTextFont!=(char*)0)
	*((int*)pSpecificWidgetProperties->pTextFont)=_Context->value_TextFont;
	visual_signature("WWSSS","WWSSS");
	visual_transferout(_Context->buffer_TextColour,6,pSpecificWidgetProperties->pTextColour);
	visual_transferout(_Context->buffer_Background,6,pSpecificWidgetProperties->pBackground);
	visual_transferout(_Context->buffer_PayLoad,255,pSpecificWidgetProperties->pPayLoad);
	visual_transferout(_Context->buffer_Identity,255,pSpecificWidgetProperties->pIdentity);
	visual_transferout(_Context->buffer_Format,255,pSpecificWidgetProperties->pFormat);
	visual_signature("SSSS","SSSS");
	visual_transferout(_Context->buffer_ShowStyle,255,pSpecificWidgetProperties->pStyleSheet);
	visual_transferout(_Context->buffer_FocusStyle,255,pSpecificWidgetProperties->pStyleFocus);
	visual_transferout(_Context->buffer_FocusPress,255,pSpecificWidgetProperties->pStylePress);
	visual_transferout(_Context->buffer_Hint,255,pSpecificWidgetProperties->pHint);
	if(pSpecificWidgetProperties->pWidgetClass!=(char*)0)
	*((int*)pSpecificWidgetProperties->pWidgetClass)=_Context->value_WidgetClass;
	if(pSpecificWidgetProperties->pAlign!=(char*)0)
	*((int*)pSpecificWidgetProperties->pAlign)=_Context->value_Align;
	if(pSpecificWidgetProperties->pType!=(char*)0)
	*((int*)pSpecificWidgetProperties->pType)=_Context->value_Type;
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

public	int	vwbutton_attach()
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

public	int	vwbutton_attach_mode(int mode)
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

public	int	vwbutton_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	vwbutton_create(struct vwbutton_context **cptr)
{

	int i;
	struct vwbutton_context * _Context=(struct vwbutton_context*)0;
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
	if (!(_Context = allocate( sizeof( struct vwbutton_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=27;
		for (i=0; i < 255; i++)  *(_Context->buffer_Identity+i)=' ';
		_Context->value_WidgetClass=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Hint+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_AtX+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_AtY+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Width+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_Height+i)=' ';
		_Context->value_IsLock=0;
		_Context->value_Type=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Format+i)=' ';
		_Context->value_TextFont=0;
		for (i=0; i < 6; i++)  *(_Context->buffer_TextColour+i)=' ';
		for (i=0; i < 6; i++)  *(_Context->buffer_Background+i)=' ';
		_Context->value_Align=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_ShowStyle+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_FocusStyle+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_FocusPress+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_PayLoad+i)=' ';
		_Context->value_IswResize=0;
		_Context->value_IshResize=0;
		_Context->value_IsBold=0;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3028[i]=" ";
	_Context->msg_Auto3028[0]=en_Auto3028;
	_Context->msg_Auto3028[1]=fr_Auto3028;
	_Context->msg_Auto3028[2]=it_Auto3028;
	_Context->msg_Auto3028[3]=es_Auto3028;
	_Context->msg_Auto3028[4]=de_Auto3028;
	_Context->msg_Auto3028[5]=nl_Auto3028;
	_Context->msg_Auto3028[6]=pt_Auto3028;
	_Context->msg_Auto3028[7]=xx_Auto3028;
	_Context->hint_Auto3028[0]=en__Auto3028;
	_Context->hint_Auto3028[1]=fr__Auto3028;
	_Context->hint_Auto3028[2]=it__Auto3028;
	_Context->hint_Auto3028[3]=es__Auto3028;
	_Context->hint_Auto3028[4]=de__Auto3028;
	_Context->hint_Auto3028[5]=nl__Auto3028;
	_Context->hint_Auto3028[6]=pt__Auto3028;
	_Context->hint_Auto3028[7]=xx__Auto3028;
	for (i=0; i < 8; i++)_Context->msg_Auto3030[i]=" ";
	_Context->msg_Auto3030[0]=en_Auto3030;
	_Context->msg_Auto3030[1]=fr_Auto3030;
	_Context->msg_Auto3030[2]=it_Auto3030;
	_Context->msg_Auto3030[3]=es_Auto3030;
	_Context->msg_Auto3030[4]=de_Auto3030;
	_Context->msg_Auto3030[5]=nl_Auto3030;
	_Context->msg_Auto3030[6]=pt_Auto3030;
	_Context->msg_Auto3030[7]=xx_Auto3030;
	_Context->hint_Auto3030[0]=en__Auto3030;
	_Context->hint_Auto3030[1]=fr__Auto3030;
	_Context->hint_Auto3030[2]=it__Auto3030;
	_Context->hint_Auto3030[3]=es__Auto3030;
	_Context->hint_Auto3030[4]=de__Auto3030;
	_Context->hint_Auto3030[5]=nl__Auto3030;
	_Context->hint_Auto3030[6]=pt__Auto3030;
	_Context->hint_Auto3030[7]=xx__Auto3030;
	for (i=0; i < 8; i++)_Context->msg_Auto3031[i]=" ";
	_Context->msg_Auto3031[0]=en_Auto3031;
	_Context->msg_Auto3031[1]=fr_Auto3031;
	_Context->msg_Auto3031[2]=it_Auto3031;
	_Context->msg_Auto3031[3]=es_Auto3031;
	_Context->msg_Auto3031[4]=de_Auto3031;
	_Context->msg_Auto3031[5]=nl_Auto3031;
	_Context->msg_Auto3031[6]=pt_Auto3031;
	_Context->msg_Auto3031[7]=xx_Auto3031;
	_Context->hint_Auto3031[0]=en__Auto3031;
	_Context->hint_Auto3031[1]=fr__Auto3031;
	_Context->hint_Auto3031[2]=it__Auto3031;
	_Context->hint_Auto3031[3]=es__Auto3031;
	_Context->hint_Auto3031[4]=de__Auto3031;
	_Context->hint_Auto3031[5]=nl__Auto3031;
	_Context->hint_Auto3031[6]=pt__Auto3031;
	_Context->hint_Auto3031[7]=xx__Auto3031;
	for (i=0; i < 8; i++)_Context->msg_Auto3032[i]=" ";
	_Context->msg_Auto3032[0]=en_Auto3032;
	_Context->msg_Auto3032[1]=fr_Auto3032;
	_Context->msg_Auto3032[2]=it_Auto3032;
	_Context->msg_Auto3032[3]=es_Auto3032;
	_Context->msg_Auto3032[4]=de_Auto3032;
	_Context->msg_Auto3032[5]=nl_Auto3032;
	_Context->msg_Auto3032[6]=pt_Auto3032;
	_Context->msg_Auto3032[7]=xx_Auto3032;
	_Context->hint_Auto3032[0]=en__Auto3032;
	_Context->hint_Auto3032[1]=fr__Auto3032;
	_Context->hint_Auto3032[2]=it__Auto3032;
	_Context->hint_Auto3032[3]=es__Auto3032;
	_Context->hint_Auto3032[4]=de__Auto3032;
	_Context->hint_Auto3032[5]=nl__Auto3032;
	_Context->hint_Auto3032[6]=pt__Auto3032;
	_Context->hint_Auto3032[7]=xx__Auto3032;
	_Context->hint_Identity[1]=fr__Identity;
	for (i=0; i < 8; i++)_Context->msg_WidgetClass[i]=" ";
	_Context->hint_WidgetClass[0]=en__WidgetClass;
	_Context->hint_WidgetClass[1]=fr__WidgetClass;
	_Context->hint_Hint[1]=fr__Hint;
	_Context->hint_AtX[1]=fr__AtX;
	_Context->hint_AtY[1]=fr__AtY;
	_Context->hint_Width[1]=fr__Width;
	_Context->hint_Height[1]=fr__Height;
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
	for (i=0; i < 8; i++)_Context->msg_Type[i]=" ";
	_Context->hint_Type[0]=en__Type;
	_Context->hint_Type[1]=fr__Type;
	_Context->hint_Format[0]=en__Format;
	_Context->hint_Format[1]=fr__Format;
	for (i=0; i < 8; i++)_Context->msg_TargetSelect[i]=" ";
	_Context->msg_TargetSelect[0]=en_TargetSelect;
	_Context->msg_TargetSelect[1]=fr_TargetSelect;
	_Context->msg_TargetSelect[2]=it_TargetSelect;
	_Context->msg_TargetSelect[3]=es_TargetSelect;
	_Context->msg_TargetSelect[4]=de_TargetSelect;
	_Context->msg_TargetSelect[5]=nl_TargetSelect;
	_Context->msg_TargetSelect[6]=pt_TargetSelect;
	_Context->msg_TargetSelect[7]=xx_TargetSelect;
	_Context->hint_TargetSelect[0]=en__TargetSelect;
	_Context->s_TargetSelect=0;
	_Context->p_TargetSelect=visual_buffer(_Context->x_WidgetProperties+634,_Context->y_WidgetProperties+194,20+2,18+2);
	for (i=0; i < 8; i++)_Context->msg_TextFont[i]=" ";
	_Context->hint_TextFont[1]=fr__TextFont;
	_Context->hint_TextColour[0]=en__TextColour;
	_Context->hint_TextColour[1]=fr__TextColour;
	_Context->hint_Background[0]=en__Background;
	_Context->hint_Background[1]=fr__Background;
	for (i=0; i < 8; i++)_Context->msg_Align[i]=" ";
	_Context->hint_Align[0]=en__Align;
	_Context->hint_Align[1]=fr__Align;
	_Context->hint_Align[2]=it__Align;
	_Context->hint_Align[3]=es__Align;
	_Context->hint_Align[4]=de__Align;
	_Context->hint_Align[5]=nl__Align;
	_Context->hint_Align[6]=pt__Align;
	_Context->hint_Align[7]=xx__Align;
	_Context->hint_ShowStyle[0]=en__ShowStyle;
	_Context->hint_ShowStyle[1]=fr__ShowStyle;
	_Context->hint_FocusStyle[0]=en__FocusStyle;
	_Context->hint_FocusPress[0]=en__FocusPress;
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
	for (i=0; i < 8; i++)_Context->msg_IsBold[i]=" ";
	_Context->hint_IsBold[0]=en__IsBold;
	_Context->hint_IsBold[1]=fr__IsBold;
	for (i=0; i < 8; i++)_Context->msg_IsUnderline[i]=" ";
	_Context->hint_IsUnderline[0]=en__IsUnderline;
	_Context->hint_IsUnderline[1]=fr__IsUnderline;
	for (i=0; i < 8; i++)_Context->msg_IsShadow[i]=" ";
	_Context->hint_IsShadow[0]=en__IsShadow;
	_Context->hint_IsShadow[1]=fr__IsShadow;
	for (i=0; i < 8; i++)_Context->msg_Auto3033[i]=" ";
	_Context->msg_Auto3033[0]=en_Auto3033;
	_Context->msg_Auto3033[1]=fr_Auto3033;
	_Context->msg_Auto3033[2]=it_Auto3033;
	_Context->msg_Auto3033[3]=es_Auto3033;
	_Context->msg_Auto3033[4]=de_Auto3033;
	_Context->msg_Auto3033[5]=nl_Auto3033;
	_Context->msg_Auto3033[6]=pt_Auto3033;
	_Context->msg_Auto3033[7]=xx_Auto3033;
	_Context->hint_Auto3033[0]=en__Auto3033;
	_Context->hint_Auto3033[1]=fr__Auto3033;
	_Context->hint_Auto3033[2]=it__Auto3033;
	_Context->hint_Auto3033[3]=es__Auto3033;
	_Context->hint_Auto3033[4]=de__Auto3033;
	_Context->hint_Auto3033[5]=nl__Auto3033;
	_Context->hint_Auto3033[6]=pt__Auto3033;
	_Context->hint_Auto3033[7]=xx__Auto3033;
	for (i=0; i < 8; i++)_Context->msg_Auto3034[i]=" ";
	_Context->msg_Auto3034[0]=en_Auto3034;
	_Context->msg_Auto3034[1]=fr_Auto3034;
	_Context->msg_Auto3034[2]=it_Auto3034;
	_Context->msg_Auto3034[3]=es_Auto3034;
	_Context->msg_Auto3034[4]=de_Auto3034;
	_Context->msg_Auto3034[5]=nl_Auto3034;
	_Context->msg_Auto3034[6]=pt_Auto3034;
	_Context->msg_Auto3034[7]=xx_Auto3034;
	_Context->hint_Auto3034[0]=en__Auto3034;
	_Context->hint_Auto3034[1]=fr__Auto3034;
	_Context->hint_Auto3034[2]=it__Auto3034;
	_Context->hint_Auto3034[3]=es__Auto3034;
	_Context->hint_Auto3034[4]=de__Auto3034;
	_Context->hint_Auto3034[5]=nl__Auto3034;
	_Context->hint_Auto3034[6]=pt__Auto3034;
	_Context->hint_Auto3034[7]=xx__Auto3034;
	for (i=0; i < 8; i++)_Context->msg_Auto3035[i]=" ";
	_Context->msg_Auto3035[0]=en_Auto3035;
	_Context->msg_Auto3035[1]=fr_Auto3035;
	_Context->msg_Auto3035[2]=it_Auto3035;
	_Context->msg_Auto3035[3]=es_Auto3035;
	_Context->msg_Auto3035[4]=de_Auto3035;
	_Context->msg_Auto3035[5]=nl_Auto3035;
	_Context->msg_Auto3035[6]=pt_Auto3035;
	_Context->msg_Auto3035[7]=xx_Auto3035;
	_Context->hint_Auto3035[0]=en__Auto3035;
	_Context->hint_Auto3035[1]=fr__Auto3035;
	_Context->hint_Auto3035[2]=it__Auto3035;
	_Context->hint_Auto3035[3]=es__Auto3035;
	_Context->hint_Auto3035[4]=de__Auto3035;
	_Context->hint_Auto3035[5]=nl__Auto3035;
	_Context->hint_Auto3035[6]=pt__Auto3035;
	_Context->hint_Auto3035[7]=xx__Auto3035;
	for (i=0; i < 8; i++)_Context->msg_Auto3036[i]=" ";
	_Context->msg_Auto3036[0]=en_Auto3036;
	_Context->msg_Auto3036[1]=fr_Auto3036;
	_Context->msg_Auto3036[2]=it_Auto3036;
	_Context->msg_Auto3036[3]=es_Auto3036;
	_Context->msg_Auto3036[4]=de_Auto3036;
	_Context->msg_Auto3036[5]=nl_Auto3036;
	_Context->msg_Auto3036[6]=pt_Auto3036;
	_Context->msg_Auto3036[7]=xx_Auto3036;
	_Context->hint_Auto3036[0]=en__Auto3036;
	_Context->hint_Auto3036[1]=fr__Auto3036;
	_Context->hint_Auto3036[2]=it__Auto3036;
	_Context->hint_Auto3036[3]=es__Auto3036;
	_Context->hint_Auto3036[4]=de__Auto3036;
	_Context->hint_Auto3036[5]=nl__Auto3036;
	_Context->hint_Auto3036[6]=pt__Auto3036;
	_Context->hint_Auto3036[7]=xx__Auto3036;
	for (i=0; i < 8; i++)_Context->msg_Auto3037[i]=" ";
	_Context->msg_Auto3037[0]=en_Auto3037;
	_Context->msg_Auto3037[1]=fr_Auto3037;
	_Context->msg_Auto3037[2]=it_Auto3037;
	_Context->msg_Auto3037[3]=es_Auto3037;
	_Context->msg_Auto3037[4]=de_Auto3037;
	_Context->msg_Auto3037[5]=nl_Auto3037;
	_Context->msg_Auto3037[6]=pt_Auto3037;
	_Context->msg_Auto3037[7]=xx_Auto3037;
	_Context->hint_Auto3037[0]=en__Auto3037;
	_Context->hint_Auto3037[1]=fr__Auto3037;
	_Context->hint_Auto3037[2]=it__Auto3037;
	_Context->hint_Auto3037[3]=es__Auto3037;
	_Context->hint_Auto3037[4]=de__Auto3037;
	_Context->hint_Auto3037[5]=nl__Auto3037;
	_Context->hint_Auto3037[6]=pt__Auto3037;
	_Context->hint_Auto3037[7]=xx__Auto3037;
	for (i=0; i < 8; i++)_Context->msg_Auto3038[i]=" ";
	_Context->hint_Auto3038[0]=en__Auto3038;
	_Context->hint_Auto3038[1]=fr__Auto3038;
	_Context->hint_Auto3038[2]=it__Auto3038;
	_Context->hint_Auto3038[3]=es__Auto3038;
	_Context->hint_Auto3038[4]=de__Auto3038;
	_Context->hint_Auto3038[5]=nl__Auto3038;
	_Context->hint_Auto3038[6]=pt__Auto3038;
	_Context->hint_Auto3038[7]=xx__Auto3038;
	for (i=0; i < 8; i++)_Context->msg_Auto3039[i]=" ";
	_Context->msg_Auto3039[0]=en_Auto3039;
	_Context->msg_Auto3039[1]=fr_Auto3039;
	_Context->msg_Auto3039[2]=it_Auto3039;
	_Context->msg_Auto3039[3]=es_Auto3039;
	_Context->msg_Auto3039[4]=de_Auto3039;
	_Context->msg_Auto3039[5]=nl_Auto3039;
	_Context->msg_Auto3039[6]=pt_Auto3039;
	_Context->msg_Auto3039[7]=xx_Auto3039;
	_Context->hint_Auto3039[0]=en__Auto3039;
	_Context->hint_Auto3039[1]=fr__Auto3039;
	_Context->hint_Auto3039[2]=it__Auto3039;
	_Context->hint_Auto3039[3]=es__Auto3039;
	_Context->hint_Auto3039[4]=de__Auto3039;
	_Context->hint_Auto3039[5]=nl__Auto3039;
	_Context->hint_Auto3039[6]=pt__Auto3039;
	_Context->hint_Auto3039[7]=xx__Auto3039;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3040[i]=" ";
	_Context->msg_Auto3040[0]=en_Auto3040;
	_Context->msg_Auto3040[1]=fr_Auto3040;
	_Context->msg_Auto3040[2]=it_Auto3040;
	_Context->msg_Auto3040[3]=es_Auto3040;
	_Context->msg_Auto3040[4]=de_Auto3040;
	_Context->msg_Auto3040[5]=nl_Auto3040;
	_Context->msg_Auto3040[6]=pt_Auto3040;
	_Context->msg_Auto3040[7]=xx_Auto3040;
	_Context->hint_Auto3040[0]=en__Auto3040;
	_Context->hint_Auto3040[1]=fr__Auto3040;
	_Context->hint_Auto3040[2]=it__Auto3040;
	_Context->hint_Auto3040[3]=es__Auto3040;
	_Context->hint_Auto3040[4]=de__Auto3040;
	_Context->hint_Auto3040[5]=nl__Auto3040;
	_Context->hint_Auto3040[6]=pt__Auto3040;
	_Context->hint_Auto3040[7]=xx__Auto3040;
	for (i=0; i < 8; i++)_Context->msg_Auto3041[i]=" ";
	_Context->msg_Auto3041[0]=en_Auto3041;
	_Context->msg_Auto3041[1]=fr_Auto3041;
	_Context->msg_Auto3041[2]=it_Auto3041;
	_Context->msg_Auto3041[3]=es_Auto3041;
	_Context->msg_Auto3041[4]=de_Auto3041;
	_Context->msg_Auto3041[5]=nl_Auto3041;
	_Context->msg_Auto3041[6]=pt_Auto3041;
	_Context->msg_Auto3041[7]=xx_Auto3041;
	_Context->hint_Auto3041[0]=en__Auto3041;
	_Context->hint_Auto3041[1]=fr__Auto3041;
	_Context->hint_Auto3041[2]=it__Auto3041;
	_Context->hint_Auto3041[3]=es__Auto3041;
	_Context->hint_Auto3041[4]=de__Auto3041;
	_Context->hint_Auto3041[5]=nl__Auto3041;
	_Context->hint_Auto3041[6]=pt__Auto3041;
	_Context->hint_Auto3041[7]=xx__Auto3041;
	for (i=0; i < 8; i++)_Context->msg_Auto3042[i]=" ";
	_Context->msg_Auto3042[0]=en_Auto3042;
	_Context->msg_Auto3042[1]=fr_Auto3042;
	_Context->msg_Auto3042[2]=it_Auto3042;
	_Context->msg_Auto3042[3]=es_Auto3042;
	_Context->msg_Auto3042[4]=de_Auto3042;
	_Context->msg_Auto3042[5]=nl_Auto3042;
	_Context->msg_Auto3042[6]=pt_Auto3042;
	_Context->msg_Auto3042[7]=xx_Auto3042;
	_Context->hint_Auto3042[0]=en__Auto3042;
	_Context->hint_Auto3042[1]=fr__Auto3042;
	_Context->hint_Auto3042[2]=it__Auto3042;
	_Context->hint_Auto3042[3]=es__Auto3042;
	_Context->hint_Auto3042[4]=de__Auto3042;
	_Context->hint_Auto3042[5]=nl__Auto3042;
	_Context->hint_Auto3042[6]=pt__Auto3042;
	_Context->hint_Auto3042[7]=xx__Auto3042;
	for (i=0; i < 8; i++)_Context->msg_Auto3043[i]=" ";
	_Context->msg_Auto3043[0]=en_Auto3043;
	_Context->msg_Auto3043[1]=fr_Auto3043;
	_Context->msg_Auto3043[2]=it_Auto3043;
	_Context->msg_Auto3043[3]=es_Auto3043;
	_Context->msg_Auto3043[4]=de_Auto3043;
	_Context->msg_Auto3043[5]=nl_Auto3043;
	_Context->msg_Auto3043[6]=pt_Auto3043;
	_Context->msg_Auto3043[7]=xx_Auto3043;
	_Context->hint_Auto3043[0]=en__Auto3043;
	_Context->hint_Auto3043[1]=fr__Auto3043;
	_Context->hint_Auto3043[2]=it__Auto3043;
	_Context->hint_Auto3043[3]=es__Auto3043;
	_Context->hint_Auto3043[4]=de__Auto3043;
	_Context->hint_Auto3043[5]=nl__Auto3043;
	_Context->hint_Auto3043[6]=pt__Auto3043;
	_Context->hint_Auto3043[7]=xx__Auto3043;
	for (i=0; i < 8; i++)_Context->msg_Auto3044[i]=" ";
	_Context->msg_Auto3044[0]=en_Auto3044;
	_Context->msg_Auto3044[1]=fr_Auto3044;
	_Context->msg_Auto3044[2]=it_Auto3044;
	_Context->msg_Auto3044[3]=es_Auto3044;
	_Context->msg_Auto3044[4]=de_Auto3044;
	_Context->msg_Auto3044[5]=nl_Auto3044;
	_Context->msg_Auto3044[6]=pt_Auto3044;
	_Context->msg_Auto3044[7]=xx_Auto3044;
	_Context->hint_Auto3044[0]=en__Auto3044;
	_Context->hint_Auto3044[1]=fr__Auto3044;
	_Context->hint_Auto3044[2]=it__Auto3044;
	_Context->hint_Auto3044[3]=es__Auto3044;
	_Context->hint_Auto3044[4]=de__Auto3044;
	_Context->hint_Auto3044[5]=nl__Auto3044;
	_Context->hint_Auto3044[6]=pt__Auto3044;
	_Context->hint_Auto3044[7]=xx__Auto3044;
	for (i=0; i < 8; i++)_Context->msg_Auto3045[i]=" ";
	_Context->msg_Auto3045[0]=en_Auto3045;
	_Context->msg_Auto3045[1]=fr_Auto3045;
	_Context->msg_Auto3045[2]=it_Auto3045;
	_Context->msg_Auto3045[3]=es_Auto3045;
	_Context->msg_Auto3045[4]=de_Auto3045;
	_Context->msg_Auto3045[5]=nl_Auto3045;
	_Context->msg_Auto3045[6]=pt_Auto3045;
	_Context->msg_Auto3045[7]=xx_Auto3045;
	_Context->hint_Auto3045[0]=en__Auto3045;
	_Context->hint_Auto3045[1]=fr__Auto3045;
	_Context->hint_Auto3045[2]=it__Auto3045;
	_Context->hint_Auto3045[3]=es__Auto3045;
	_Context->hint_Auto3045[4]=de__Auto3045;
	_Context->hint_Auto3045[5]=nl__Auto3045;
	_Context->hint_Auto3045[6]=pt__Auto3045;
	_Context->hint_Auto3045[7]=xx__Auto3045;
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
	_Context->hint_PayLoadSelect[1]=fr__PayLoadSelect;
	_Context->s_PayLoadSelect=0;
	_Context->p_PayLoadSelect=visual_buffer(_Context->x_WidgetProperties+436,_Context->y_WidgetProperties+322,20+2,18+2);
	for (i=0; i < 8; i++)_Context->msg_Auto3046[i]=" ";
	_Context->msg_Auto3046[7]=xx_Auto3046;
	_Context->hint_Auto3046[0]=en__Auto3046;
	_Context->hint_Auto3046[1]=fr__Auto3046;
	_Context->hint_Auto3046[2]=it__Auto3046;
	_Context->hint_Auto3046[3]=es__Auto3046;
	_Context->hint_Auto3046[4]=de__Auto3046;
	_Context->hint_Auto3046[5]=nl__Auto3046;
	_Context->hint_Auto3046[6]=pt__Auto3046;
	_Context->hint_Auto3046[7]=xx__Auto3046;
	for (i=0; i < 8; i++)_Context->msg_Auto3047[i]=" ";
	_Context->msg_Auto3047[0]=en_Auto3047;
	_Context->msg_Auto3047[1]=fr_Auto3047;
	_Context->msg_Auto3047[2]=it_Auto3047;
	_Context->msg_Auto3047[3]=es_Auto3047;
	_Context->msg_Auto3047[4]=de_Auto3047;
	_Context->msg_Auto3047[5]=nl_Auto3047;
	_Context->msg_Auto3047[6]=pt_Auto3047;
	_Context->msg_Auto3047[7]=xx_Auto3047;
	_Context->hint_Auto3047[0]=en__Auto3047;
	_Context->hint_Auto3047[1]=fr__Auto3047;
	_Context->hint_Auto3047[2]=it__Auto3047;
	_Context->hint_Auto3047[3]=es__Auto3047;
	_Context->hint_Auto3047[4]=de__Auto3047;
	_Context->hint_Auto3047[5]=nl__Auto3047;
	_Context->hint_Auto3047[6]=pt__Auto3047;
	_Context->hint_Auto3047[7]=xx__Auto3047;
	return(0);
}

public 	int	vwbutton_hide(struct vwbutton_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_PayLoadSelect != (void *) 0)
	&& (_Context->s_PayLoadSelect != 0)) {
		(void)visual_buffer_put(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+436,_Context->y_WidgetProperties+322);
		_Context->s_PayLoadSelect=0;
		}
	if ((_Context->p_TargetSelect != (void *) 0)
	&& (_Context->s_TargetSelect != 0)) {
		(void)visual_buffer_put(_Context->p_TargetSelect,_Context->x_WidgetProperties+634,_Context->y_WidgetProperties+194);
		_Context->s_TargetSelect=0;
		}

	return(result);
}

public	int	vwbutton_remove(struct vwbutton_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->p_PayLoadSelect != (void *) 0)
		_Context->p_PayLoadSelect = visual_drop(_Context->p_PayLoadSelect);
	if (_Context->p_TargetSelect != (void *) 0)
		_Context->p_TargetSelect = visual_drop(_Context->p_TargetSelect);
	_Context=liberate(_Context);

	return(result);
}

public	int	vwbutton_show(struct vwbutton_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,"widget_frame",_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]))) != 0)
) {
		visual_window(_Context->x_WidgetProperties,_Context->y_WidgetProperties,670,400,vfh[2],_Context->msg_WidgetProperties[_Context->language],strlen(_Context->msg_WidgetProperties[_Context->language]),0x4);
		}
	visual_text(_Context->x_WidgetProperties+522,_Context->y_WidgetProperties+26,140,16,vfh[2],16,0,_Context->msg_Auto3028[_Context->language],strlen(_Context->msg_Auto3028[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+522,_Context->y_WidgetProperties+42,140,109,4);
	visual_filzone(_Context->x_WidgetProperties+186,_Context->y_WidgetProperties+280,1,1,27,0);
	visual_text(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+152,656,16,vfh[2],16,0,_Context->msg_Auto3030[_Context->language],strlen(_Context->msg_Auto3030[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+168,656,64,4);
	visual_text(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+234,657,16,vfh[2],16,0,_Context->msg_Auto3031[_Context->language],strlen(_Context->msg_Auto3031[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+250,657,139,4);
	visual_text(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+26,514,16,vfh[2],16,0,_Context->msg_Auto3032[_Context->language],strlen(_Context->msg_Auto3032[_Context->language]),258);
	visual_frame(_Context->x_WidgetProperties+6,_Context->y_WidgetProperties+42,514,109,4);
	visual_frame(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+64,288+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+12+1,_Context->y_WidgetProperties+64+1,288,16,vfh[1],34,0,_Context->buffer_Identity,255,0);
	visual_select(_Context->x_WidgetProperties+314,_Context->y_WidgetProperties+64,126,128,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),768);
	visual_frame(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+106,496+2,32+2,5);
	visual_text(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+106+1,496,32,vfh[1],0,0,_Context->buffer_Hint,255,0);
	visual_frame(_Context->x_WidgetProperties+534,_Context->y_WidgetProperties+64,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+534+1,_Context->y_WidgetProperties+64+1,35,16,vfh[1],34,0,_Context->buffer_AtX,7,0);
	visual_frame(_Context->x_WidgetProperties+588,_Context->y_WidgetProperties+64,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+588+1,_Context->y_WidgetProperties+64+1,35,16,vfh[1],34,0,_Context->buffer_AtY,7,0);
	visual_frame(_Context->x_WidgetProperties+534,_Context->y_WidgetProperties+108,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+534+1,_Context->y_WidgetProperties+108+1,35,16,vfh[1],34,0,_Context->buffer_Width,7,0);
	visual_frame(_Context->x_WidgetProperties+588,_Context->y_WidgetProperties+108,35+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+588+1,_Context->y_WidgetProperties+108+1,35,16,vfh[1],34,0,_Context->buffer_Height,7,0);
	_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+194,112,17,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
	visual_select(_Context->x_WidgetProperties+158,_Context->y_WidgetProperties+194,130,100,vfh[2],0,0,parse_selection(WidgetTypeList,&_Context->value_Type),768);
	visual_frame(_Context->x_WidgetProperties+320,_Context->y_WidgetProperties+194,312+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+320+1,_Context->y_WidgetProperties+194+1,312,16,vfh[1],27,0,_Context->buffer_Format,255,0);
	if ((_Context->p_TargetSelect != (void *) 0)
	&& (_Context->s_TargetSelect == 0)) {
		(void)visual_buffer_get(_Context->p_TargetSelect,_Context->x_WidgetProperties+634,_Context->y_WidgetProperties+194);
		_Context->s_TargetSelect=1;
		}
	_Context->trigger_TargetSelect=visual_trigger_code(_Context->msg_TargetSelect[_Context->language],strlen(_Context->msg_TargetSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+634,_Context->y_WidgetProperties+194,20,18,vfh[8],28,28,_Context->msg_TargetSelect[_Context->language],strlen(_Context->msg_TargetSelect[_Context->language]),0);
	visual_select(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+276,130,100,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),768);
	visual_frame(_Context->x_WidgetProperties+158,_Context->y_WidgetProperties+276,42+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+158+1,_Context->y_WidgetProperties+276+1,42,16,vfh[1],34,0,_Context->buffer_TextColour,6,0);
	visual_frame(_Context->x_WidgetProperties+250,_Context->y_WidgetProperties+276,40+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+250+1,_Context->y_WidgetProperties+276+1,40,16,vfh[1],34,0,_Context->buffer_Background,6,0);
	visual_select(_Context->x_WidgetProperties+320,_Context->y_WidgetProperties+276,140,96,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),768);
	visual_frame(_Context->x_WidgetProperties+480,_Context->y_WidgetProperties+276,176+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+480+1,_Context->y_WidgetProperties+276+1,176,16,vfh[1],0,0,_Context->buffer_ShowStyle,255,0);
	visual_frame(_Context->x_WidgetProperties+480,_Context->y_WidgetProperties+293,176+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+480+1,_Context->y_WidgetProperties+293+1,176,16,vfh[1],0,0,_Context->buffer_FocusStyle,255,0);
	visual_frame(_Context->x_WidgetProperties+480,_Context->y_WidgetProperties+310,176+2,16+2,5);
	visual_text(_Context->x_WidgetProperties+480+1,_Context->y_WidgetProperties+310+1,176,16,vfh[1],0,0,_Context->buffer_FocusPress,255,0);
	visual_frame(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+322,416+2,32+2,5);
	visual_text(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+322+1,416,32,vfh[1],34,0,_Context->buffer_PayLoad,255,0);
	_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+16,_Context->y_WidgetProperties+366,168,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
	_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+206,_Context->y_WidgetProperties+366,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
	_Context->trigger_IsBold=visual_trigger_code(WidgetMessage(_Context->value_WidgetClass,1),strlen(WidgetMessage(_Context->value_WidgetClass,1)));
	visual_check(_Context->x_WidgetProperties+480,_Context->y_WidgetProperties+328,179,16,vfh[2],175,0,WidgetMessage(_Context->value_WidgetClass,1),strlen(WidgetMessage(_Context->value_WidgetClass,1)),_Context->value_IsBold|0);
	_Context->trigger_IsUnderline=visual_trigger_code(WidgetMessage(_Context->value_WidgetClass,2),strlen(WidgetMessage(_Context->value_WidgetClass,2)));
	visual_check(_Context->x_WidgetProperties+480,_Context->y_WidgetProperties+346,181,16,vfh[2],175,0,WidgetMessage(_Context->value_WidgetClass,2),strlen(WidgetMessage(_Context->value_WidgetClass,2)),_Context->value_IsUnderline|0);
	_Context->trigger_IsShadow=visual_trigger_code(WidgetMessage(_Context->value_WidgetClass,3),strlen(WidgetMessage(_Context->value_WidgetClass,3)));
	visual_check(_Context->x_WidgetProperties+480,_Context->y_WidgetProperties+364,184,16,vfh[2],28,28,WidgetMessage(_Context->value_WidgetClass,3),strlen(WidgetMessage(_Context->value_WidgetClass,3)),_Context->value_IsShadow|0);
	visual_text(_Context->x_WidgetProperties+534,_Context->y_WidgetProperties+48,14,21,vfh[2],16,0,_Context->msg_Auto3033[_Context->language],strlen(_Context->msg_Auto3033[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+588,_Context->y_WidgetProperties+90,56,16,vfh[2],16,0,_Context->msg_Auto3034[_Context->language],strlen(_Context->msg_Auto3034[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+534,_Context->y_WidgetProperties+88,50,21,vfh[2],16,0,_Context->msg_Auto3035[_Context->language],strlen(_Context->msg_Auto3035[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+588,_Context->y_WidgetProperties+48,14,21,vfh[2],16,0,_Context->msg_Auto3036[_Context->language],strlen(_Context->msg_Auto3036[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+260,180,16,vfh[2],16,0,_Context->msg_Auto3037[_Context->language],strlen(_Context->msg_Auto3037[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+16,_Context->y_WidgetProperties+308,418,16,vfh[2],16,0,WidgetPayload(_Context->value_WidgetClass),strlen(WidgetPayload(_Context->value_WidgetClass)),2);
	visual_text(_Context->x_WidgetProperties+162,_Context->y_WidgetProperties+260,42,16,vfh[2],16,0,_Context->msg_Auto3039[_Context->language],strlen(_Context->msg_Auto3039[_Context->language]),2);
	_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+204,_Context->y_WidgetProperties+276,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
	visual_text(_Context->x_WidgetProperties+250,_Context->y_WidgetProperties+262,42,16,vfh[2],16,0,_Context->msg_Auto3040[_Context->language],strlen(_Context->msg_Auto3040[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+482,_Context->y_WidgetProperties+258,182,16,vfh[2],16,0,_Context->msg_Auto3041[_Context->language],strlen(_Context->msg_Auto3041[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+90,180,16,vfh[2],16,0,_Context->msg_Auto3042[_Context->language],strlen(_Context->msg_Auto3042[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+320,_Context->y_WidgetProperties+262,126,16,vfh[2],16,0,_Context->msg_Auto3043[_Context->language],strlen(_Context->msg_Auto3043[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+48,154,16,vfh[2],16,0,_Context->msg_Auto3044[_Context->language],strlen(_Context->msg_Auto3044[_Context->language]),2);
	visual_text(_Context->x_WidgetProperties+316,_Context->y_WidgetProperties+48,135,16,vfh[2],16,0,_Context->msg_Auto3045[_Context->language],strlen(_Context->msg_Auto3045[_Context->language]),2);
	if ((_Context->p_PayLoadSelect != (void *) 0)
	&& (_Context->s_PayLoadSelect == 0)) {
		(void)visual_buffer_get(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+436,_Context->y_WidgetProperties+322);
		_Context->s_PayLoadSelect=1;
		}
	_Context->trigger_PayLoadSelect=visual_trigger_code(_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+436,_Context->y_WidgetProperties+322,20,18,vfh[8],28,28,_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]),0);
	visual_text(_Context->x_WidgetProperties+320,_Context->y_WidgetProperties+176,336,16,vfh[2],16,0,WidgetMessage(_Context->value_WidgetClass,0),strlen(WidgetMessage(_Context->value_WidgetClass,0)),2);
	visual_text(_Context->x_WidgetProperties+158,_Context->y_WidgetProperties+178,135,16,vfh[2],16,0,_Context->msg_Auto3047[_Context->language],strlen(_Context->msg_Auto3047[_Context->language]),2);
	visual_filzone(_Context->x_WidgetProperties+174,_Context->y_WidgetProperties+282,1,1,27,0);
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
			char * mptr[3];
			mptr[0] = "This edit field allows an explicative message text to be provided ";
			mptr[1]="to be used by an eventual hint presentation mechanism of the parent ";
			mptr[2]="form activetool the  forms method ONHINT(message).   ";
			return(visual_online_help(mptr,3));
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
			mptr[0] = "  ";
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

private int IsLock_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This check box allows the collection of widget properties to be  locked ";
			mptr[1]="and consequently protected against accidental modification.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Cocher la case pour v‚rouiller l'objet, ainsi il sera prot‚g‚ contre ";
			mptr[1]="toute  tentative de modification involontaire    ";
			return(visual_online_help(mptr,2));
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
			char * mptr[20];
			mptr[0] = "This combo selection field allows the behaviour or action of the push ";
			mptr[1]="button widget to be define as can be seen below :  ";
			mptr[2]="  ";
			mptr[3]=" - Void      : this value indicates that the Event will contain code ";
			mptr[4]="to determine the action of the button.  ";
			mptr[5]=" - Overlay   : The TARGET property defines the name of the forms model ";
			mptr[6]="to be invoked as an OVERLAY object.  ";
			mptr[7]=" - Module    : The TARGET property defines the name of the forms model ";
			mptr[8]="to be invoked as a MODULE object.  ";
			mptr[9]=" - Chain     : The TARGET property defines the name of the forms model, ";
			mptr[10]="or the standard abal program, to be invoked by an abal CHAIN instruction. ";
			mptr[11]=" ";
			mptr[12]=" - Loadgo    : The TARGET property defines the name of the forms model, ";
			mptr[13]="or the standard abal program, to be invoked by an abal LOAD.GO instruction. ";
			mptr[14]=" ";
			mptr[15]=" - Hyperlink : The TARGET property defines the hypertext URL to be activated ";
			mptr[16]="activetool the standard system web browser.  ";
			mptr[17]=" - System    : The TARGET property defines the system command to be invoked ";
			mptr[18]="by the abal instruction LOAD.GO.  ";
			mptr[19]="      ";
			return(visual_online_help(mptr,20));
			}
			break;
		case 1 : 
			{
			char * mptr[20];
			mptr[0] = "Ce combo control permet de d‚finir le comportement des composant graphiques ";
			mptr[1]="de type bouton comme decrit ci-desous :  ";
			mptr[2]="  ";
			mptr[3]=" - Void      : Ceci indiques que le method Event permet de determiner ";
			mptr[4]="l'action exacte du bouton.  ";
			mptr[5]=" - Overlay   : Le propriŠt‚ CIBLE permet de definir le nom du formulaire ";
			mptr[6]="a activer en tant que objet OVERLAY d'abal.  ";
			mptr[7]=" - Module    :  Le propriŠt‚ CIBLE permet de definir le nom du formulaire ";
			mptr[8]="a activer en tant que MODULE d'abal.  ";
			mptr[9]=" - Chain     :  Le propriŠt‚ CIBLE permet de definir le nom du formulaire ";
			mptr[10]="ou le nom d'un program abal, a activer par l'instruction abal CHAIN. ";
			mptr[11]=" ";
			mptr[12]=" - Loadgo    :  Le propriŠt‚ CIBLE permet de definir le nom du formulaire ";
			mptr[13]="ou le nom d'un program abal, a activer par l'instruction abal LOAD.GO. ";
			mptr[14]=" ";
			mptr[15]=" - Hyperlink :  Le propriŠt‚ CIBLE permet de definir le nom du page html ";
			mptr[16]="a ouvrir avec le browser web standard du systeme.  ";
			mptr[17]=" - System    :  Le propriŠt‚ CIBLE permet de definir le nom de la commande ";
			mptr[18]="systeme a activer par l'instruction abal LOAD.GO.  ";
			mptr[19]="    ";
			return(visual_online_help(mptr,20));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Format_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "This edit field allows the behaviour or action of VOID and MODULE ";
			mptr[1]="buttons to be  specified. ";
			mptr[2]=" It also allows supplementary information to be provided for OVERLAY,CHAIN,LOADGO ";
			mptr[3]="and system buttons. In this case a buffer member will be associated ";
			mptr[4]="with the push button element allowing the parameter to be stored for ";
			mptr[5]="use by the button specific action.   ";
			return(visual_online_help(mptr,6));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Cette zone permet de d‚crire l'action a declencher pour les boutons ";
			mptr[1]="de type VOID. ";
			mptr[2]=" ";
			mptr[3]=" Elle permet aussi pour les autres types de boutons  d'indiquer le ";
			mptr[4]="nom du programme  a activer.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TargetSelect_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = " ";
			mptr[1]=" This pushbutton gices access to the database manager for selection ";
			mptr[2]="or creation of the datafile class description of the file component. ";
			mptr[3]=" ";
			mptr[4]="    ";
			return(visual_online_help(mptr,5));
			}
			break;
		case 1 : 
			{
			char * mptr[4];
			mptr[0] = " ";
			mptr[1]=" Ce bouton permet d'acceder a la gestionaire de classes de fichiers ";
			mptr[2]="a fin de pouvoir selectioner ou cr‚er une classe de fichier.  ";
			mptr[3]="    ";
			return(visual_online_help(mptr,4));
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

private int Align_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This combo selection field allows the display type of the push button ";
			mptr[1]="to be  defined. ";
			mptr[2]=" ";
			mptr[3]=" Two basic button types are possible, textual buttons, image or icon ";
			mptr[4]="buttons. Each of these types may be framed or unframed.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Permet de choisir le type de bouton, texte ou image, avec ou sans ";
			mptr[1]="cadre.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ShowStyle_help()
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

private int FocusStyle_help()
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

private int FocusPress_help()
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

private int PayLoad_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[7];
			mptr[0] = "For textual buttons, this edit field defines the text to be displayed ";
			mptr[1]="as the label of the button. ";
			mptr[2]=" ";
			mptr[3]=" For image buttons, this edit field defines the name of the image ";
			mptr[4]="to be displayed by the button. It may also provide, separated by the ";
			mptr[5]="standard pipe character, a textual message to be displayed after the ";
			mptr[6]="image.   ";
			return(visual_online_help(mptr,7));
			}
			break;
		case 1 : 
			{
			char * mptr[7];
			mptr[0] = "Pour les boutons de type texte ce champs edit permet de definir le ";
			mptr[1]="texte a afficher en tant que libell‚ du bouton. ";
			mptr[2]=" ";
			mptr[3]=" Dans le cas des boutons de type image, ce champ sert a definir le ";
			mptr[4]="nom  de l'image a affichier sur le bouton. Elle permet aussi de definir ";
			mptr[5]="une texte, separ‚ de le nom d'image par une barre verticale, a afficher ";
			mptr[6]="en tant que libell‚ de l'image.   ";
			return(visual_online_help(mptr,7));
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

private int IsBold_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This check box indicates that for textual widgets the label is to ";
			mptr[1]="be displayed activetool a bold typeface. ";
			mptr[2]=" ";
			mptr[3]=" For image buttons this check box activates image stretch or squash ";
			mptr[4]="mechansisms to ensure an exact fit to the button zone.       ";
			return(visual_online_help(mptr,5));
			}
			break;
		case 1 : 
			{
			char * mptr[6];
			mptr[0] = "Ce check bouton permet d'indiquer que les des boutons d'affichage ";
			mptr[1]="de texte doivent activer l'atribut GRAS. ";
			mptr[2]=" ";
			mptr[3]=" Pour les boutons afficheurs d'images, ce check bouton, permet d'indiquer ";
			mptr[4]="que l'image se doit de se faire redimensioner pour couvrir le bouton ";
			mptr[5]=" exactement.    ";
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
			char * mptr[2];
			mptr[0] = "This check control allows activation of underlining for unframed textual ";
			mptr[1]="push  buttons only.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Ce check bouton permet d'indiquer l'utilisation de soulignement pour ";
			mptr[1]="les  boutons de type texte sans cadre seulement.   ";
			return(visual_online_help(mptr,2));
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
			char * mptr[5];
			mptr[0] = "This check control allows transparence to be respected for images ";
			mptr[1]="displayed on image type buttons. ";
			mptr[2]=" ";
			mptr[3]=" It also allows use of the colour information by unframed textual ";
			mptr[4]="push buttons.    ";
			return(visual_online_help(mptr,5));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Ce check control permet d'indiquer l'utilisation de transparence lors ";
			mptr[1]="de l'affiche  des images des boutons a image. ";
			mptr[2]=" ";
			mptr[3]=" Ell permet aussi pour les boutons texte sans cadre d'utiliser les ";
			mptr[4]="informations de couleur.    ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PayLoadSelect_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This push button gives access to the stanard file selection dialog ";
			mptr[1]="frame for image push buttons.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Ce bouton permet d'acceder a la fenetre de selection des nom de fichiers ";
			mptr[1]="pour les boutons de type image.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}
private int on_TargetSelect_event(struct vwbutton_context * _Context) {
	struct form_control*fptr;
	struct form_control*resolve_component_number(int);
	int component=0;
	switch(_Context->value_Type){
	case _WIDGET_MODULE:
	case _WIDGET_CHAIN:
	case _WIDGET_OVERLAY:
	case _WIDGET_LOADGO:
	case _WIDGET_TASK:
		vwbutton_hide(_Context);
;
	if(accept_component_selection(&component)!=27){
	if((fptr=resolve_component_number(component))!=(struct form_control*)0){
	if(fptr->identifier){
	strcpy(_Context->buffer_Format,fptr->identifier);
	}
	}
	}
	reset_component_selection_list();
		vwbutton_show(_Context);
;
	}
		return(-1);
}
private int on_TextFont_event(struct vwbutton_context * _Context) {
	TextFont_help(_Context);
	return(-1);
}
private int on_Align_event(struct vwbutton_context * _Context) {
	unsigned char*msg_help[8],*msg;
	int i,nblig=1;
	int largeur=0;
	/*case _BUTTON_FRAME:*/
	msg_help[0]="Choose the type of button you want, with or without frame, text or Image inside";
	msg_help[1]="Choisir le type de button, avec ou sans cadre et texte ou image";
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
	aide_en_ligne(_Context->x_WidgetProperties+670-largeur*8,_Context->y_WidgetProperties+276+30,nblig,msg_help[visual_national_language(-1)]);
	return(-1);
}
private int on_ShowStyle_event(struct vwbutton_context * _Context) {
	ShowStyle_help(_Context);
	return(-1);
}
private int on_FocusStyle_event(struct vwbutton_context * _Context) {
	FocusStyle_help(_Context);
	return(-1);
}
private int on_FocusPress_event(struct vwbutton_context * _Context) {
	FocusPress_help(_Context);
	return(-1);
}
private int on_IsShadow_event(struct vwbutton_context * _Context) {
	unsigned char*msg_help[8],*msg;
	int i,nblig=1;
	int largeur=0;
	switch(_Context->value_WidgetClass)
	{
	case _TAB_FRAME:
	msg_help[0]="this check control add a shadow beind the tab";
	msg_help[1]="Ajouter une ombre en bas et a droite de l'onglet";
	break;
	case _BUTTON_FRAME:
	msg_help[0]="this check control add a shadow beind the button";
	msg_help[1]="Ajouter une ombre en bas et a droite du bouton";
	break;
	case _EDIT_FRAME:
	msg_help[0]="No help for this check.";
	msg_help[1]="pas d'aide pour cette case … cocher";
	break;
		case _PROGRESS_FRAME:
	msg_help[0]="activates the mode relief for the progress bar.\0The widget will appears in a outset zone with the standard color.";
	msg_help[1]="la barre de progrŠs sera en relif\0Elle apparais dans un cadre de couleur standard.";
	nblig=2;
	break;
		case _FORM_FRAME:
	msg_help[0]="this check controls the title bar relief atribut,\0which when set causes the titles zone to be displayed\0in GUI RELIEF format rather than in GUI TITLE COLOUR format.";
	msg_help[1]="Si vous cochez cette case, les titres\0des colonnes seront en relief sur fond gris\0plutot que sans cadre sur fond bleu.";
	nblig=3;
	break;
	case _SCROLL_FRAME:
	msg_help[0]="Nothing for this check";
	msg_help[1]="Cette case … cocher est sans effets pour cet objet";
	break;
		case _IMAGE_FRAME:
	msg_help[0]="Nothing help this check";
	msg_help[1]="Pas d'aide sur cette case … cocher";
	break;
	case _WINDOW_FRAME:
	msg_help[0]="this check control add a shadow beind the window";
	msg_help[1]="Ajouter une ombre en bas et a droite de la fenˆtre";
	break;
		case _DATA_FRAME:
	msg_help[0]="Check to open the file in read only mode.";
	msg_help[1]="Cocher pour ouvrir le fichier en mode lecture seule.";
	break;
	case _FILL_FRAME:
	msg_help[0]="This data is unsued for the fill widget";
	msg_help[1]="Cette case a cocher n'est pas utilis‚e pour cet objet";
	break;
	case _OUTSET_FRAME:
	case _INSET_FRAME:
	case _RIDGE_FRAME:
	case _GROOVE_FRAME:
	msg_help[0]="this check control add a shadow beind the widget";
	msg_help[1]="Ajouter une ombre en bas et a droite de l'objet";
	break;
	case _SELECT_FRAME:
	case _SWITCH_FRAME:
	case _GRAPH_FRAME:
	case _CHECK_FRAME:
	case _RADIO_FRAME:
	case _LINE_FRAME:
	msg_help[0]="Nothing for this check";
	msg_help[1]="Cette case … cocher est sans effets pour ce widget";
	break;
	case _TEXT_FRAME:
	msg_help[0]="Add a shadow beind the text.";
	msg_help[1]="Afficher le texte en ombr‚";
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
	aide_en_ligne(_Context->x_WidgetProperties+670-largeur*8-75,_Context->y_WidgetProperties+364+30,nblig,msg_help[visual_national_language(-1)]);
	return(-1);
}
private int on_fgSelect_event(struct vwbutton_context * _Context) {
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
		vwbutton_show(_Context);
;
	return(-1);
}
private int on_PayLoadSelect_event(struct vwbutton_context * _Context) {
		vwbutton_hide(_Context);
;
	use_file_selector(_Context->buffer_PayLoad,WIDGET_FILE_GIF);
		vwbutton_show(_Context);
;
	return(-1);
}


public	int	vwbutton_event(
struct vwbutton_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_IsLock == mb ) return(9);
		if (_Context->trigger_TargetSelect == mb ) return(12);
		if (_Context->trigger_IswResize == mb ) return(21);
		if (_Context->trigger_IshResize == mb ) return(22);
		if (_Context->trigger_IsBold == mb ) return(23);
		if (_Context->trigger_IsUnderline == mb ) return(24);
		if (_Context->trigger_IsShadow == mb ) return(25);
		if (_Context->trigger_fgSelect == mb ) return(26);
		if (_Context->trigger_PayLoadSelect == mb ) return(27);
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
		vwbutton_show(_Context);
		return(-1);	/* WidgetProperties */

		}
		}
	if (( mx >= (_Context->x_WidgetProperties+12) ) 
	&&  ( my >= (_Context->y_WidgetProperties+64) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+12+288) ) 
	&&  ( my <= (_Context->y_WidgetProperties+64+16))) {
		return(2); /* Identity */
		}
	if (( mx >= (_Context->x_WidgetProperties+314+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+64) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+314+126) ) 
	&&  ( my <= (_Context->y_WidgetProperties+64+16))) {
		return(3); /* WidgetClass */
		}
	if (( mx >= (_Context->x_WidgetProperties+14) ) 
	&&  ( my >= (_Context->y_WidgetProperties+106) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+14+496) ) 
	&&  ( my <= (_Context->y_WidgetProperties+106+32))) {
		return(4); /* Hint */
		}
	if (( mx >= (_Context->x_WidgetProperties+534) ) 
	&&  ( my >= (_Context->y_WidgetProperties+64) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+534+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+64+16))) {
		return(5); /* AtX */
		}
	if (( mx >= (_Context->x_WidgetProperties+588) ) 
	&&  ( my >= (_Context->y_WidgetProperties+64) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+588+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+64+16))) {
		return(6); /* AtY */
		}
	if (( mx >= (_Context->x_WidgetProperties+534) ) 
	&&  ( my >= (_Context->y_WidgetProperties+108) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+534+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+108+16))) {
		return(7); /* Width */
		}
	if (( mx >= (_Context->x_WidgetProperties+588) ) 
	&&  ( my >= (_Context->y_WidgetProperties+108) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+588+35) ) 
	&&  ( my <= (_Context->y_WidgetProperties+108+16))) {
		return(8); /* Height */
		}
	if (( mx >= (_Context->x_WidgetProperties+14) ) 
	&&  ( my >= (_Context->y_WidgetProperties+194) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+14+112) ) 
	&&  ( my <= (_Context->y_WidgetProperties+194+17))) {
		return(9); /* IsLock */
		}
	if (( mx >= (_Context->x_WidgetProperties+158+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+194) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+158+130) ) 
	&&  ( my <= (_Context->y_WidgetProperties+194+16))) {
		return(10); /* Type */
		}
	if (( mx >= (_Context->x_WidgetProperties+320) ) 
	&&  ( my >= (_Context->y_WidgetProperties+194) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+320+312) ) 
	&&  ( my <= (_Context->y_WidgetProperties+194+16))) {
		return(11); /* Format */
		}
	if (( mx >= (_Context->x_WidgetProperties+634) ) 
	&&  ( my >= (_Context->y_WidgetProperties+194) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+634+20) ) 
	&&  ( my <= (_Context->y_WidgetProperties+194+18))) {
		return(12); /* TargetSelect */
		}
	if (( mx >= (_Context->x_WidgetProperties+12+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+276) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+12+130) ) 
	&&  ( my <= (_Context->y_WidgetProperties+276+16))) {
		return(13); /* TextFont */
		}
	if (( mx >= (_Context->x_WidgetProperties+158) ) 
	&&  ( my >= (_Context->y_WidgetProperties+276) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+158+42) ) 
	&&  ( my <= (_Context->y_WidgetProperties+276+16))) {
		return(14); /* TextColour */
		}
	if (( mx >= (_Context->x_WidgetProperties+250) ) 
	&&  ( my >= (_Context->y_WidgetProperties+276) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+250+40) ) 
	&&  ( my <= (_Context->y_WidgetProperties+276+16))) {
		return(15); /* Background */
		}
	if (( mx >= (_Context->x_WidgetProperties+320+0) ) 
	&&  ( my >= (_Context->y_WidgetProperties+276) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+320+140) ) 
	&&  ( my <= (_Context->y_WidgetProperties+276+16))) {
		return(16); /* Align */
		}
	if (( mx >= (_Context->x_WidgetProperties+480) ) 
	&&  ( my >= (_Context->y_WidgetProperties+276) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+480+176) ) 
	&&  ( my <= (_Context->y_WidgetProperties+276+16))) {
		return(17); /* ShowStyle */
		}
	if (( mx >= (_Context->x_WidgetProperties+480) ) 
	&&  ( my >= (_Context->y_WidgetProperties+293) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+480+176) ) 
	&&  ( my <= (_Context->y_WidgetProperties+293+16))) {
		return(18); /* FocusStyle */
		}
	if (( mx >= (_Context->x_WidgetProperties+480) ) 
	&&  ( my >= (_Context->y_WidgetProperties+310) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+480+176) ) 
	&&  ( my <= (_Context->y_WidgetProperties+310+16))) {
		return(19); /* FocusPress */
		}
	if (( mx >= (_Context->x_WidgetProperties+14) ) 
	&&  ( my >= (_Context->y_WidgetProperties+322) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+14+416) ) 
	&&  ( my <= (_Context->y_WidgetProperties+322+32))) {
		return(20); /* PayLoad */
		}
	if (( mx >= (_Context->x_WidgetProperties+16) ) 
	&&  ( my >= (_Context->y_WidgetProperties+366) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+16+168) ) 
	&&  ( my <= (_Context->y_WidgetProperties+366+16))) {
		return(21); /* IswResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+206) ) 
	&&  ( my >= (_Context->y_WidgetProperties+366) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+206+165) ) 
	&&  ( my <= (_Context->y_WidgetProperties+366+16))) {
		return(22); /* IshResize */
		}
	if (( mx >= (_Context->x_WidgetProperties+480) ) 
	&&  ( my >= (_Context->y_WidgetProperties+328) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+480+179) ) 
	&&  ( my <= (_Context->y_WidgetProperties+328+16))) {
		return(23); /* IsBold */
		}
	if (( mx >= (_Context->x_WidgetProperties+480) ) 
	&&  ( my >= (_Context->y_WidgetProperties+346) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+480+181) ) 
	&&  ( my <= (_Context->y_WidgetProperties+346+16))) {
		return(24); /* IsUnderline */
		}
	if (( mx >= (_Context->x_WidgetProperties+480) ) 
	&&  ( my >= (_Context->y_WidgetProperties+364) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+480+184) ) 
	&&  ( my <= (_Context->y_WidgetProperties+364+16))) {
		return(25); /* IsShadow */
		}
	if (( mx >= (_Context->x_WidgetProperties+204) ) 
	&&  ( my >= (_Context->y_WidgetProperties+276) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+204+44) ) 
	&&  ( my <= (_Context->y_WidgetProperties+276+18))) {
		return(26); /* fgSelect */
		}
	if (( mx >= (_Context->x_WidgetProperties+436) ) 
	&&  ( my >= (_Context->y_WidgetProperties+322) ) 
	&&  ( mx <= (_Context->x_WidgetProperties+436+20) ) 
	&&  ( my <= (_Context->y_WidgetProperties+322+18))) {
		return(27); /* PayLoadSelect */
		}

	return(-1);
}


public	int	vwbutton_focus(struct vwbutton_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Identity */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+12+1,_Context->y_WidgetProperties+64+1,288,16,vfh[1],_Context->buffer_Identity,255);
			break;
			case	0x3 :
				/* WidgetClass */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+314,_Context->y_WidgetProperties+64,126,128,vfh[2],0,0,parse_selection(WidgetClassList,&_Context->value_WidgetClass),774);
				if(change_widget_class(&_Context->value_WidgetClass)!=0){
				return(26);
				}
				break;
			case	0x4 :
				/* Hint */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+106+1,496,32,vfh[1],_Context->buffer_Hint,255);
			break;
			case	0x5 :
				/* AtX */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+534+1,_Context->y_WidgetProperties+64+1,35,16,vfh[1],_Context->buffer_AtX,7);
			break;
			case	0x6 :
				/* AtY */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+588+1,_Context->y_WidgetProperties+64+1,35,16,vfh[1],_Context->buffer_AtY,7);
			break;
			case	0x7 :
				/* Width */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+534+1,_Context->y_WidgetProperties+108+1,35,16,vfh[1],_Context->buffer_Width,7);
			break;
			case	0x8 :
				/* Height */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+588+1,_Context->y_WidgetProperties+108+1,35,16,vfh[1],_Context->buffer_Height,7);
			break;
			case	0x9 :
				/* IsLock */
				visual_check(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+194,112,17,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),(_Context->value_IsLock |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsLock=visual_trigger_code(_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]));
	visual_check(_Context->x_WidgetProperties+14,_Context->y_WidgetProperties+194,112,17,vfh[2],27,0,_Context->msg_IsLock[_Context->language],strlen(_Context->msg_IsLock[_Context->language]),_Context->value_IsLock|0);
				break;
			case	0xa :
				/* Type */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+158,_Context->y_WidgetProperties+194,130,100,vfh[2],0,0,parse_selection(WidgetTypeList,&_Context->value_Type),774);
				break;
			case	0xb :
				/* Format */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+320+1,_Context->y_WidgetProperties+194+1,312,16,vfh[1],_Context->buffer_Format,255);
			break;
			case	0xd :
				/* TextFont */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+12,_Context->y_WidgetProperties+276,130,100,vfh[2],34,0,parse_selection(TextFontList,&_Context->value_TextFont),770);
				break;
			case	0xe :
				/* TextColour */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+158+1,_Context->y_WidgetProperties+276+1,42,16,vfh[1],_Context->buffer_TextColour,6);
			break;
			case	0xf :
				/* Background */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+250+1,_Context->y_WidgetProperties+276+1,40,16,vfh[1],_Context->buffer_Background,6);
			break;
			case	0x10 :
				/* Align */
				_Context->keycode = visual_select(_Context->x_WidgetProperties+320,_Context->y_WidgetProperties+276,140,96,vfh[2],0,0,parse_selection(WidgetOptionList(_Context->value_WidgetClass),&_Context->value_Align),774);
				break;
			case	0x11 :
				/* ShowStyle */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+480+1,_Context->y_WidgetProperties+276+1,176,16,vfh[1],_Context->buffer_ShowStyle,255);
			break;
			case	0x12 :
				/* FocusStyle */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+480+1,_Context->y_WidgetProperties+293+1,176,16,vfh[1],_Context->buffer_FocusStyle,255);
			break;
			case	0x13 :
				/* FocusPress */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+480+1,_Context->y_WidgetProperties+310+1,176,16,vfh[1],_Context->buffer_FocusPress,255);
			break;
			case	0x14 :
				/* PayLoad */
				_Context->keycode = visual_edit(_Context->x_WidgetProperties+14+1,_Context->y_WidgetProperties+322+1,416,32,vfh[1],_Context->buffer_PayLoad,255);
			break;
			case	0x15 :
				/* IswResize */
				visual_check(_Context->x_WidgetProperties+16,_Context->y_WidgetProperties+366,168,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),(_Context->value_IswResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IswResize=visual_trigger_code(_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+16,_Context->y_WidgetProperties+366,168,16,vfh[2],28,28,_Context->msg_IswResize[_Context->language],strlen(_Context->msg_IswResize[_Context->language]),_Context->value_IswResize|0);
				break;
			case	0x16 :
				/* IshResize */
				visual_check(_Context->x_WidgetProperties+206,_Context->y_WidgetProperties+366,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),(_Context->value_IshResize |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IshResize=visual_trigger_code(_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]));
	visual_check(_Context->x_WidgetProperties+206,_Context->y_WidgetProperties+366,165,16,vfh[2],28,28,_Context->msg_IshResize[_Context->language],strlen(_Context->msg_IshResize[_Context->language]),_Context->value_IshResize|0);
				break;
			case	0x17 :
				/* IsBold */
				visual_check(_Context->x_WidgetProperties+480,_Context->y_WidgetProperties+328,179,16,vfh[2],175,0,WidgetMessage(_Context->value_WidgetClass,1),strlen(WidgetMessage(_Context->value_WidgetClass,1)),(_Context->value_IsBold |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsBold=visual_trigger_code(WidgetMessage(_Context->value_WidgetClass,1),strlen(WidgetMessage(_Context->value_WidgetClass,1)));
	visual_check(_Context->x_WidgetProperties+480,_Context->y_WidgetProperties+328,179,16,vfh[2],175,0,WidgetMessage(_Context->value_WidgetClass,1),strlen(WidgetMessage(_Context->value_WidgetClass,1)),_Context->value_IsBold|0);
				break;
			case	0x18 :
				/* IsUnderline */
				visual_check(_Context->x_WidgetProperties+480,_Context->y_WidgetProperties+346,181,16,vfh[2],175,0,WidgetMessage(_Context->value_WidgetClass,2),strlen(WidgetMessage(_Context->value_WidgetClass,2)),(_Context->value_IsUnderline |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsUnderline=visual_trigger_code(WidgetMessage(_Context->value_WidgetClass,2),strlen(WidgetMessage(_Context->value_WidgetClass,2)));
	visual_check(_Context->x_WidgetProperties+480,_Context->y_WidgetProperties+346,181,16,vfh[2],175,0,WidgetMessage(_Context->value_WidgetClass,2),strlen(WidgetMessage(_Context->value_WidgetClass,2)),_Context->value_IsUnderline|0);
				break;
			case	0x19 :
				/* IsShadow */
				visual_check(_Context->x_WidgetProperties+480,_Context->y_WidgetProperties+364,184,16,vfh[2],28,28,WidgetMessage(_Context->value_WidgetClass,3),strlen(WidgetMessage(_Context->value_WidgetClass,3)),(_Context->value_IsShadow |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsShadow=visual_trigger_code(WidgetMessage(_Context->value_WidgetClass,3),strlen(WidgetMessage(_Context->value_WidgetClass,3)));
	visual_check(_Context->x_WidgetProperties+480,_Context->y_WidgetProperties+364,184,16,vfh[2],28,28,WidgetMessage(_Context->value_WidgetClass,3),strlen(WidgetMessage(_Context->value_WidgetClass,3)),_Context->value_IsShadow|0);
				break;
			case	0x1a :
				/* fgSelect */
				_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
				visual_button(_Context->x_WidgetProperties+204,_Context->y_WidgetProperties+276,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+204,_Context->y_WidgetProperties+276,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			vwbutton_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=27;
			vwbutton_show(_Context);
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
			if ((retcode=vwbutton_event(_Context)) == -1)
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
						if (AtX_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (AtY_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (Width_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (IsLock_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (Type_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Format_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (TargetSelect_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (TextFont_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (TextColour_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (Background_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (Align_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (ShowStyle_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (FocusStyle_help(_Context) != 0) { continue; }
						else { break; }
					case	0x13 :
						if (FocusPress_help(_Context) != 0) { continue; }
						else { break; }
					case	0x14 :
						if (PayLoad_help(_Context) != 0) { continue; }
						else { break; }
					case	0x15 :
						if (IswResize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x16 :
						if (IshResize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x17 :
						if (IsBold_help(_Context) != 0) { continue; }
						else { break; }
					case	0x18 :
						if (IsUnderline_help(_Context) != 0) { continue; }
						else { break; }
					case	0x19 :
						if (IsShadow_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1b :
						if (PayLoadSelect_help(_Context) != 0) { continue; }
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
					/* AtX */
					continue;
				case	0x6 :
					/* AtY */
					continue;
				case	0x7 :
					/* Width */
					continue;
				case	0x8 :
					/* Height */
					continue;
				case	0x9 :
					/* IsLock */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsLock += 1;
						_Context->value_IsLock &= 1;
						}
					continue;
				case	0xa :
					/* Type */
					continue;
				case	0xb :
					/* Format */
					continue;
				case	0xc :
					/* TargetSelect */
					if (visual_event(1) & _MIMO_DOWN) {
						if ((_Context->p_TargetSelect != (void *) 0)
						&& (_Context->s_TargetSelect == 0)) {
							(void)visual_buffer_get(_Context->p_TargetSelect,_Context->x_WidgetProperties+634,_Context->y_WidgetProperties+194);
							_Context->s_TargetSelect=1;
							}
						_Context->trigger_TargetSelect=visual_trigger_code(_Context->msg_TargetSelect[_Context->language],strlen(_Context->msg_TargetSelect[_Context->language]));
						visual_button(_Context->x_WidgetProperties+634,_Context->y_WidgetProperties+194,20,18,vfh[8],28,28,_Context->msg_TargetSelect[_Context->language],strlen(_Context->msg_TargetSelect[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						if ((_Context->p_TargetSelect != (void *) 0)
						&& (_Context->s_TargetSelect == 0)) {
							(void)visual_buffer_get(_Context->p_TargetSelect,_Context->x_WidgetProperties+634,_Context->y_WidgetProperties+194);
							_Context->s_TargetSelect=1;
							}
						_Context->trigger_TargetSelect=visual_trigger_code(_Context->msg_TargetSelect[_Context->language],strlen(_Context->msg_TargetSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+634,_Context->y_WidgetProperties+194,20,18,vfh[8],28,28,_Context->msg_TargetSelect[_Context->language],strlen(_Context->msg_TargetSelect[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_TargetSelect_event(_Context)) != -1) break;

						}
					continue;
				case	0xd :
					/* TextFont */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_TextFont_event(_Context)) != -1) break;

						}
					continue;
				case	0xe :
					/* TextColour */
					continue;
				case	0xf :
					/* Background */
					continue;
				case	0x10 :
					/* Align */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_Align_event(_Context)) != -1) break;

						}
					continue;
				case	0x11 :
					/* ShowStyle */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_ShowStyle_event(_Context)) != -1) break;

						}
					continue;
				case	0x12 :
					/* FocusStyle */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_FocusStyle_event(_Context)) != -1) break;

						}
					continue;
				case	0x13 :
					/* FocusPress */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_FocusPress_event(_Context)) != -1) break;

						}
					continue;
				case	0x14 :
					/* PayLoad */
					continue;
				case	0x15 :
					/* IswResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IswResize += 1;
						_Context->value_IswResize &= 1;
						}
					continue;
				case	0x16 :
					/* IshResize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IshResize += 1;
						_Context->value_IshResize &= 1;
						}
					continue;
				case	0x17 :
					/* IsBold */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsBold += 1;
						_Context->value_IsBold &= 1;
						}
					continue;
				case	0x18 :
					/* IsUnderline */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsUnderline += 1;
						_Context->value_IsUnderline &= 1;
						}
					continue;
				case	0x19 :
					/* IsShadow */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsShadow += 1;
						_Context->value_IsShadow &= 1;
						}
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_IsShadow_event(_Context)) != -1) break;

						}
					continue;
				case	0x1a :
					/* fgSelect */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
						visual_button(_Context->x_WidgetProperties+204,_Context->y_WidgetProperties+276,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+204,_Context->y_WidgetProperties+276,44,18,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_fgSelect_event(_Context)) != -1) break;

						}
					continue;
				case	0x1b :
					/* PayLoadSelect */
					if (visual_event(1) & _MIMO_DOWN) {
						if ((_Context->p_PayLoadSelect != (void *) 0)
						&& (_Context->s_PayLoadSelect == 0)) {
							(void)visual_buffer_get(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+436,_Context->y_WidgetProperties+322);
							_Context->s_PayLoadSelect=1;
							}
						_Context->trigger_PayLoadSelect=visual_trigger_code(_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]));
						visual_button(_Context->x_WidgetProperties+436,_Context->y_WidgetProperties+322,20,18,vfh[8],28,28,_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						if ((_Context->p_PayLoadSelect != (void *) 0)
						&& (_Context->s_PayLoadSelect == 0)) {
							(void)visual_buffer_get(_Context->p_PayLoadSelect,_Context->x_WidgetProperties+436,_Context->y_WidgetProperties+322);
							_Context->s_PayLoadSelect=1;
							}
						_Context->trigger_PayLoadSelect=visual_trigger_code(_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]));
	visual_button(_Context->x_WidgetProperties+436,_Context->y_WidgetProperties+322,20,18,vfh[8],28,28,_Context->msg_PayLoadSelect[_Context->language],strlen(_Context->msg_PayLoadSelect[_Context->language]),0);
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
				_Context->focus_item=27;
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

public	int	vwbutton()
{
	int	status=0;
	struct vwbutton_context * _Context=(struct vwbutton_context*) 0;
	status = vwbutton_create(&_Context);
	if ( status != 0) return(status);
	status = vwbutton_show(_Context);
		enter_modal();
	status = vwbutton_focus(_Context);
		leave_modal();
	status = vwbutton_hide(_Context);
	status = vwbutton_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vwbutton_c */
