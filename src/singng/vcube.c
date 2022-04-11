
#ifndef _vcube_c
#define _vcube_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vcube.xml                                                */
/* Target         : vcube.c                                                  */
/* Identification : 0.0-1177511934-4355.4354                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__auto1   ""
#define fr__auto1   ""
#define it__auto1   ""
#define es__auto1   ""
#define de__auto1   ""
#define nl__auto1   ""
#define pt__auto1   ""
#define xx__auto1   ""
#define en_Auto2715   "Cube Face Colours"
#define fr_Auto2715   "Couleurs des faces du cube"
#define it_Auto2715   "Cube Face Colours"
#define es_Auto2715   "Cube Face Colours"
#define de_Auto2715   "Cube Face Colours"
#define nl_Auto2715   "Cube Face Colours"
#define pt_Auto2715   "Cube Face Colours"
#define xx_Auto2715   "Cube Face Colours"
#define en__Auto2715   ""
#define fr__Auto2715   ""
#define it__Auto2715   ""
#define es__Auto2715   ""
#define de__Auto2715   ""
#define nl__Auto2715   ""
#define pt__Auto2715   ""
#define xx__Auto2715   ""
#define en_Auto2716   "Back"
#define fr_Auto2716   "ArriŠre"
#define it_Auto2716   "Back"
#define es_Auto2716   "Back"
#define de_Auto2716   "Zurck"
#define nl_Auto2716   "Back"
#define pt_Auto2716   "Back"
#define xx_Auto2716   "Back"
#define en__Auto2716   ""
#define fr__Auto2716   ""
#define it__Auto2716   ""
#define es__Auto2716   ""
#define de__Auto2716   ""
#define nl__Auto2716   ""
#define pt__Auto2716   ""
#define xx__Auto2716   ""
#define en_Auto2717   "Front"
#define fr_Auto2717   "Avant"
#define it_Auto2717   "Front"
#define es_Auto2717   "Front"
#define de_Auto2717   "Front"
#define nl_Auto2717   "Front"
#define pt_Auto2717   "Front"
#define xx_Auto2717   "Front"
#define en__Auto2717   ""
#define fr__Auto2717   ""
#define it__Auto2717   ""
#define es__Auto2717   ""
#define de__Auto2717   ""
#define nl__Auto2717   ""
#define pt__Auto2717   ""
#define xx__Auto2717   ""
#define en_Auto2718   "Left"
#define fr_Auto2718   "Gauche"
#define it_Auto2718   "Left"
#define es_Auto2718   "Left"
#define de_Auto2718   "Links"
#define nl_Auto2718   "Left"
#define pt_Auto2718   "Left"
#define xx_Auto2718   "Left"
#define en__Auto2718   ""
#define fr__Auto2718   ""
#define it__Auto2718   ""
#define es__Auto2718   ""
#define de__Auto2718   ""
#define nl__Auto2718   ""
#define pt__Auto2718   ""
#define xx__Auto2718   ""
#define en_Auto2719   "Right"
#define fr_Auto2719   "Droite"
#define it_Auto2719   "Right"
#define es_Auto2719   "Right"
#define de_Auto2719   "Rechts"
#define nl_Auto2719   "Right"
#define pt_Auto2719   "Right"
#define xx_Auto2719   "Right"
#define en__Auto2719   ""
#define fr__Auto2719   ""
#define it__Auto2719   ""
#define es__Auto2719   ""
#define de__Auto2719   ""
#define nl__Auto2719   ""
#define pt__Auto2719   ""
#define xx__Auto2719   ""
#define en_Auto2720   "Upper"
#define fr_Auto2720   "Haute"
#define it_Auto2720   "Upper"
#define es_Auto2720   "Upper"
#define de_Auto2720   "Uber"
#define nl_Auto2720   "Upper"
#define pt_Auto2720   "Upper"
#define xx_Auto2720   "Upper"
#define en__Auto2720   ""
#define fr__Auto2720   ""
#define it__Auto2720   ""
#define es__Auto2720   ""
#define de__Auto2720   ""
#define nl__Auto2720   ""
#define pt__Auto2720   ""
#define xx__Auto2720   ""
#define en_Auto2721   "Lower"
#define fr_Auto2721   "Basse"
#define it_Auto2721   "Lower"
#define es_Auto2721   "Lower"
#define de_Auto2721   "Hinten"
#define nl_Auto2721   "Lower"
#define pt_Auto2721   "Lower"
#define xx_Auto2721   "Lower"
#define en__Auto2721   ""
#define fr__Auto2721   ""
#define it__Auto2721   ""
#define es__Auto2721   ""
#define de__Auto2721   ""
#define nl__Auto2721   ""
#define pt__Auto2721   ""
#define xx__Auto2721   ""
#define en_Auto2722   "Light"
#define fr_Auto2722   "Clair"
#define it_Auto2722   "Light"
#define es_Auto2722   "Light"
#define de_Auto2722   "Light"
#define nl_Auto2722   "Light"
#define pt_Auto2722   "Light"
#define xx_Auto2722   "Light"
#define en__Auto2722   ""
#define fr__Auto2722   ""
#define it__Auto2722   ""
#define es__Auto2722   ""
#define de__Auto2722   ""
#define nl__Auto2722   ""
#define pt__Auto2722   ""
#define xx__Auto2722   ""
#define en_Auto2723   "Dark"
#define fr_Auto2723   "Sombre"
#define it_Auto2723   "Dark"
#define es_Auto2723   "Dark"
#define de_Auto2723   "Dark"
#define nl_Auto2723   "Dark"
#define pt_Auto2723   "Dark"
#define xx_Auto2723   "Dark"
#define en__Auto2723   ""
#define fr__Auto2723   ""
#define it__Auto2723   ""
#define es__Auto2723   ""
#define de__Auto2723   ""
#define nl__Auto2723   ""
#define pt__Auto2723   ""
#define xx__Auto2723   ""
#define en_auto2   "3d Object Properties"
#define fr_auto2   "Propri‚t‚s de l'objet 3d"
#define it_auto2   "3d Object Properties"
#define es_auto2   "3d Object Properties"
#define de_auto2   "3d Object Properties"
#define nl_auto2   "3d Object Properties"
#define pt_auto2   "3d Object Properties"
#define xx_auto2   "3d Object Properties"
#define en__auto2   ""
#define fr__auto2   ""
#define it__auto2   ""
#define es__auto2   ""
#define de__auto2   ""
#define nl__auto2   ""
#define pt__auto2   ""
#define xx__auto2   ""
#define en_Auto2724   "Cube definition"
#define fr_Auto2724   "D‚finition du Cube"
#define it_Auto2724   "Cube definition"
#define es_Auto2724   "Cube definition"
#define de_Auto2724   "Cube definition"
#define nl_Auto2724   "Cube definition"
#define pt_Auto2724   "Cube definition"
#define xx_Auto2724   "Cube definition"
#define en__Auto2724   ""
#define fr__Auto2724   ""
#define it__Auto2724   ""
#define es__Auto2724   ""
#define de__Auto2724   ""
#define nl__Auto2724   ""
#define pt__Auto2724   ""
#define xx__Auto2724   ""
#define en_auto5   "Identity"
#define fr_auto5   "Identifiant"
#define it_auto5   "Identity"
#define es_auto5   "Identity"
#define de_auto5   "Identity"
#define nl_auto5   "Identity"
#define pt_auto5   "Identity"
#define xx_auto5   "Ainm"
#define en__auto5   ""
#define fr__auto5   ""
#define it__auto5   ""
#define es__auto5   ""
#define de__auto5   ""
#define nl__auto5   ""
#define pt__auto5   ""
#define xx__auto5   ""
#define en_auto6   "Position"
#define fr_auto6   "Position"
#define it_auto6   "Position"
#define es_auto6   "Position"
#define de_auto6   "Position"
#define nl_auto6   "Position"
#define pt_auto6   "Position"
#define xx_auto6   "Position"
#define en__auto6   ""
#define fr__auto6   ""
#define it__auto6   ""
#define es__auto6   ""
#define de__auto6   ""
#define nl__auto6   ""
#define pt__auto6   ""
#define xx__auto6   ""
#define en_auto7   "Dimensions"
#define fr_auto7   "Dimensions"
#define it_auto7   "Dimensions"
#define es_auto7   "Dimensions"
#define de_auto7   "Dimensions"
#define nl_auto7   "Dimensions"
#define pt_auto7   "Dimensions"
#define xx_auto7   "Dimensions"
#define en__auto7   ""
#define fr__auto7   ""
#define it__auto7   ""
#define es__auto7   ""
#define de__auto7   ""
#define nl__auto7   ""
#define pt__auto7   ""
#define xx__auto7   ""
#define en_Identity   ""
#define en_auto17   "X"
#define fr_auto17   "X"
#define it_auto17   "X"
#define es_auto17   "X"
#define de_auto17   "X"
#define nl_auto17   "X"
#define pt_auto17   "X"
#define xx_auto17   "X"
#define en_auto18   "Y"
#define fr_auto18   "Y"
#define it_auto18   "Y"
#define es_auto18   "Y"
#define de_auto18   "Y"
#define nl_auto18   "Y"
#define pt_auto18   "Y"
#define xx_auto18   "Y"
#define en_auto19   "Z"
#define fr_auto19   "Z"
#define it_auto19   "Z"
#define es_auto19   "Z"
#define de_auto19   "Z"
#define nl_auto19   "Z"
#define pt_auto19   "Z"
#define xx_auto19   "Z"
#define en_Auto2725   "ok.gif"
#define fr_Auto2725   "ok.gif"
#define it_Auto2725   "ok.gif"
#define es_Auto2725   "ok.gif"
#define de_Auto2725   "ok.gif"
#define nl_Auto2725   "ok.gif"
#define pt_Auto2725   "ok.gif"
#define xx_Auto2725   "ok.gif"
#define en_Auto2726   "cancel.gif"
#define fr_Auto2726   "cancel.gif"
#define it_Auto2726   "cancel.gif"
#define es_Auto2726   "cancel.gif"
#define de_Auto2726   "cancel.gif"
#define nl_Auto2726   "cancel.gif"
#define pt_Auto2726   "cancel.gif"
#define xx_Auto2726   "cancel.gif"
#define en_Select   "&Select"
#define fr_Select   "&Choisir"
#define it_Select   "&Select"
#define es_Select   "&Select"
#define de_Select   "&Select"
#define nl_Select   "&Select"
#define pt_Select   "&Select"
#define xx_Select   "&Select"
#define en__Select   ""
#define fr__Select   ""
#define it__Select   ""
#define es__Select   ""
#define de__Select   ""
#define nl__Select   ""
#define pt__Select   ""
#define xx__Select   ""
#define en_auto197   "Class"
#define fr_auto197   "Classe"
#define it_auto197   "Class"
#define es_auto197   "Class"
#define de_auto197   "Class"
#define nl_auto197   "Class"
#define pt_auto197   "Class"
#define xx_auto197   "Clais"
#define en__auto197   ""
#define fr__auto197   ""
#define it__auto197   ""
#define es__auto197   ""
#define de__auto197   ""
#define nl__auto197   ""
#define pt__auto197   ""
#define xx__auto197   ""
#define en_Class   ""
#define en_Auto2727   "Au&toSize"
#define fr_Auto2727   "Dimension Auto"
#define it_Auto2727   "Au&toSize"
#define es_Auto2727   "Au&toSize"
#define de_Auto2727   "Au&toSize"
#define nl_Auto2727   "Au&toSize"
#define pt_Auto2727   "Au&toSize"
#define xx_Auto2727   "Au&toSize"
#define en__Auto2727   ""
#define fr__Auto2727   ""
#define it__Auto2727   ""
#define es__Auto2727   ""
#define de__Auto2727   ""
#define nl__Auto2727   ""
#define pt__Auto2727   ""
#define xx__Auto2727   ""
#define en_Auto2728   "&Locked"
#define fr_Auto2728   "&Verrouill‚"
#define it_Auto2728   "&Locked"
#define es_Auto2728   "&Locked"
#define de_Auto2728   "&Locked"
#define nl_Auto2728   "&Locked"
#define pt_Auto2728   "&Locked"
#define xx_Auto2728   "&Locked"
#define en__Auto2728   ""
#define fr__Auto2728   ""
#define it__Auto2728   ""
#define es__Auto2728   ""
#define de__Auto2728   ""
#define nl__Auto2728   ""
#define pt__Auto2728   ""
#define xx__Auto2728   ""
#define fr_ImageFormat   "Bmp|Gif|Jpeg"
#define it_ImageFormat   "Bmp|Gif|Jpeg"
#define es_ImageFormat   "Bmp|Gif|Jpeg"
#define de_ImageFormat   "Bmp|Gif|Jpeg"
#define nl_ImageFormat   "Bmp|Gif|Jpeg"
#define pt_ImageFormat   "Bmp|Gif|Jpeg"
#define xx_ImageFormat   "Bmp|Gif|Jpeg"

private struct accept_cube_properties_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_auto1[8];
	char * hint_auto1[8];
	int	x_auto1;
	int	y_auto1;
	int	w_auto1;
	int	h_auto1;
	char * msg_Auto2715[8];
	char * hint_Auto2715[8];
	char * msg_Auto2716[8];
	char * hint_Auto2716[8];
	char * msg_Auto2717[8];
	char * hint_Auto2717[8];
	char * msg_Auto2718[8];
	char * hint_Auto2718[8];
	char * msg_Auto2719[8];
	char * hint_Auto2719[8];
	char * msg_Auto2720[8];
	char * hint_Auto2720[8];
	char * msg_Auto2721[8];
	char * hint_Auto2721[8];
	char * msg_Auto2722[8];
	char * hint_Auto2722[8];
	char * msg_Auto2723[8];
	char * hint_Auto2723[8];
	char * msg_auto2[8];
	char * hint_auto2[8];
	char * msg_Auto2724[8];
	char * hint_Auto2724[8];
	char * msg_auto5[8];
	char * hint_auto5[8];
	char * msg_auto6[8];
	char * hint_auto6[8];
	char * msg_auto7[8];
	char * hint_auto7[8];
	char * hint_Identity[8];
	char	buffer_Identity[256];
	char * hint_Position[8];
	char	buffer_Position[8];
	char * hint_tly[8];
	char	buffer_tly[8];
	char * hint_tlz[8];
	char	buffer_tlz[8];
	char * hint_Dimensions[8];
	char	buffer_Dimensions[8];
	char * hint_bry[8];
	char	buffer_bry[8];
	char * hint_brz[8];
	char	buffer_brz[8];
	char * msg_auto17[8];
	char * hint_auto17[8];
	char * msg_auto18[8];
	char * hint_auto18[8];
	char * msg_auto19[8];
	char * hint_auto19[8];
	char * msg_Auto2725[8];
	int	trigger_Auto2725;
	char * hint_Auto2725[8];
	char * msg_Auto2726[8];
	int	trigger_Auto2726;
	char * hint_Auto2726[8];
	char * msg_Select[8];
	int	trigger_Select;
	char * hint_Select[8];
	char * msg_auto197[8];
	char * hint_auto197[8];
	char * hint_Class[8];
	char	buffer_Class[256];
	char * msg_Auto2727[8];
	int	trigger_Auto2727;
	char * hint_Auto2727[8];
	int	value_Auto2727;
	char * msg_Auto2728[8];
	int	trigger_Auto2728;
	char * hint_Auto2728[8];
	int	value_Auto2728;
	char * msg_ImageFormat[8];
	char * hint_ImageFormat[8];
	int	value_ImageFormat;
	char * hint_Back[8];
	char	buffer_Back[8];
	char * hint_Front[8];
	char	buffer_Front[8];
	char * hint_Left[8];
	char	buffer_Left[8];
	char * hint_Right[8];
	char	buffer_Right[8];
	char * hint_Upper[8];
	char	buffer_Upper[8];
	char * hint_Lower[8];
	char	buffer_Lower[8];
	char * hint_Light[8];
	char	buffer_Light[8];
	char * hint_Dark[8];
	char	buffer_Dark[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[20];
	};
static int	vfh[16];

public	int	accept_cube_properties_create(
	struct accept_cube_properties_context ** cptr,
	char * pIdentity,
	char * pPosition,
	char * ptly,
	char * ptlz,
	char * pDimensions,
	char * pbry,
	char * pbrz,
	char * pClass,
	char * pAuto2727,
	char * pAuto2728,
	char * pImageFormat,
	char * pBack,
	char * pFront,
	char * pLeft,
	char * pRight,
	char * pUpper,
	char * pLower,
	char * pLight,
	char * pDark)
{

	int i;
	struct accept_cube_properties_context * _Context=(struct accept_cube_properties_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_cube_properties_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=22;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWWWWKWWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Identity, 255, pIdentity);
		visual_transferin(_Context->buffer_Position, 7, pPosition);
		visual_transferin(_Context->buffer_tly, 7, ptly);
		visual_transferin(_Context->buffer_tlz, 7, ptlz);
		visual_transferin(_Context->buffer_Dimensions, 7, pDimensions);
		visual_transferin(_Context->buffer_bry, 7, pbry);
		visual_transferin(_Context->buffer_brz, 7, pbrz);
		visual_transferin(_Context->buffer_Class, 255, pClass);
		visual_transferin((void *) 0, 0, pAuto2727);
		if (!( pAuto2727 )) _Context->value_Auto2727=0;
		else	_Context->value_Auto2727 = *((int *)pAuto2727);
		visual_transferin((void *) 0, 0, pAuto2728);
		if (!( pAuto2728 )) _Context->value_Auto2728=0;
		else	_Context->value_Auto2728 = *((int *)pAuto2728);
		visual_transferin((void *) 0, 0, pImageFormat);
		if (!( pImageFormat )) _Context->value_ImageFormat=0;
		else	_Context->value_ImageFormat = *((int *)pImageFormat);
		visual_transferin(_Context->buffer_Back, 7, pBack);
		visual_transferin(_Context->buffer_Front, 7, pFront);
		visual_transferin(_Context->buffer_Left, 7, pLeft);
		visual_transferin(_Context->buffer_Right, 7, pRight);
		visual_transferin(_Context->buffer_Upper, 7, pUpper);
		visual_transferin(_Context->buffer_Lower, 7, pLower);
		visual_transferin(_Context->buffer_Light, 7, pLight);
		visual_transferin(_Context->buffer_Dark, 7, pDark);
		}
	for (i=0; i < 8; i++)_Context->msg_auto1[i]=" ";
	_Context->hint_auto1[0]=en__auto1;
	_Context->hint_auto1[1]=fr__auto1;
	_Context->hint_auto1[2]=it__auto1;
	_Context->hint_auto1[3]=es__auto1;
	_Context->hint_auto1[4]=de__auto1;
	_Context->hint_auto1[5]=nl__auto1;
	_Context->hint_auto1[6]=pt__auto1;
	_Context->hint_auto1[7]=xx__auto1;
	_Context->x_auto1=95;
	_Context->y_auto1=140;
	_Context->w_auto1=610;
	_Context->h_auto1=320;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2715[i]=" ";
	_Context->msg_Auto2715[0]=en_Auto2715;
	_Context->msg_Auto2715[1]=fr_Auto2715;
	_Context->msg_Auto2715[2]=it_Auto2715;
	_Context->msg_Auto2715[3]=es_Auto2715;
	_Context->msg_Auto2715[4]=de_Auto2715;
	_Context->msg_Auto2715[5]=nl_Auto2715;
	_Context->msg_Auto2715[6]=pt_Auto2715;
	_Context->msg_Auto2715[7]=xx_Auto2715;
	_Context->hint_Auto2715[0]=en__Auto2715;
	_Context->hint_Auto2715[1]=fr__Auto2715;
	_Context->hint_Auto2715[2]=it__Auto2715;
	_Context->hint_Auto2715[3]=es__Auto2715;
	_Context->hint_Auto2715[4]=de__Auto2715;
	_Context->hint_Auto2715[5]=nl__Auto2715;
	_Context->hint_Auto2715[6]=pt__Auto2715;
	_Context->hint_Auto2715[7]=xx__Auto2715;
	for (i=0; i < 8; i++)_Context->msg_Auto2716[i]=" ";
	_Context->msg_Auto2716[0]=en_Auto2716;
	_Context->msg_Auto2716[1]=fr_Auto2716;
	_Context->msg_Auto2716[2]=it_Auto2716;
	_Context->msg_Auto2716[3]=es_Auto2716;
	_Context->msg_Auto2716[4]=de_Auto2716;
	_Context->msg_Auto2716[5]=nl_Auto2716;
	_Context->msg_Auto2716[6]=pt_Auto2716;
	_Context->msg_Auto2716[7]=xx_Auto2716;
	_Context->hint_Auto2716[0]=en__Auto2716;
	_Context->hint_Auto2716[1]=fr__Auto2716;
	_Context->hint_Auto2716[2]=it__Auto2716;
	_Context->hint_Auto2716[3]=es__Auto2716;
	_Context->hint_Auto2716[4]=de__Auto2716;
	_Context->hint_Auto2716[5]=nl__Auto2716;
	_Context->hint_Auto2716[6]=pt__Auto2716;
	_Context->hint_Auto2716[7]=xx__Auto2716;
	for (i=0; i < 8; i++)_Context->msg_Auto2717[i]=" ";
	_Context->msg_Auto2717[0]=en_Auto2717;
	_Context->msg_Auto2717[1]=fr_Auto2717;
	_Context->msg_Auto2717[2]=it_Auto2717;
	_Context->msg_Auto2717[3]=es_Auto2717;
	_Context->msg_Auto2717[4]=de_Auto2717;
	_Context->msg_Auto2717[5]=nl_Auto2717;
	_Context->msg_Auto2717[6]=pt_Auto2717;
	_Context->msg_Auto2717[7]=xx_Auto2717;
	_Context->hint_Auto2717[0]=en__Auto2717;
	_Context->hint_Auto2717[1]=fr__Auto2717;
	_Context->hint_Auto2717[2]=it__Auto2717;
	_Context->hint_Auto2717[3]=es__Auto2717;
	_Context->hint_Auto2717[4]=de__Auto2717;
	_Context->hint_Auto2717[5]=nl__Auto2717;
	_Context->hint_Auto2717[6]=pt__Auto2717;
	_Context->hint_Auto2717[7]=xx__Auto2717;
	for (i=0; i < 8; i++)_Context->msg_Auto2718[i]=" ";
	_Context->msg_Auto2718[0]=en_Auto2718;
	_Context->msg_Auto2718[1]=fr_Auto2718;
	_Context->msg_Auto2718[2]=it_Auto2718;
	_Context->msg_Auto2718[3]=es_Auto2718;
	_Context->msg_Auto2718[4]=de_Auto2718;
	_Context->msg_Auto2718[5]=nl_Auto2718;
	_Context->msg_Auto2718[6]=pt_Auto2718;
	_Context->msg_Auto2718[7]=xx_Auto2718;
	_Context->hint_Auto2718[0]=en__Auto2718;
	_Context->hint_Auto2718[1]=fr__Auto2718;
	_Context->hint_Auto2718[2]=it__Auto2718;
	_Context->hint_Auto2718[3]=es__Auto2718;
	_Context->hint_Auto2718[4]=de__Auto2718;
	_Context->hint_Auto2718[5]=nl__Auto2718;
	_Context->hint_Auto2718[6]=pt__Auto2718;
	_Context->hint_Auto2718[7]=xx__Auto2718;
	for (i=0; i < 8; i++)_Context->msg_Auto2719[i]=" ";
	_Context->msg_Auto2719[0]=en_Auto2719;
	_Context->msg_Auto2719[1]=fr_Auto2719;
	_Context->msg_Auto2719[2]=it_Auto2719;
	_Context->msg_Auto2719[3]=es_Auto2719;
	_Context->msg_Auto2719[4]=de_Auto2719;
	_Context->msg_Auto2719[5]=nl_Auto2719;
	_Context->msg_Auto2719[6]=pt_Auto2719;
	_Context->msg_Auto2719[7]=xx_Auto2719;
	_Context->hint_Auto2719[0]=en__Auto2719;
	_Context->hint_Auto2719[1]=fr__Auto2719;
	_Context->hint_Auto2719[2]=it__Auto2719;
	_Context->hint_Auto2719[3]=es__Auto2719;
	_Context->hint_Auto2719[4]=de__Auto2719;
	_Context->hint_Auto2719[5]=nl__Auto2719;
	_Context->hint_Auto2719[6]=pt__Auto2719;
	_Context->hint_Auto2719[7]=xx__Auto2719;
	for (i=0; i < 8; i++)_Context->msg_Auto2720[i]=" ";
	_Context->msg_Auto2720[0]=en_Auto2720;
	_Context->msg_Auto2720[1]=fr_Auto2720;
	_Context->msg_Auto2720[2]=it_Auto2720;
	_Context->msg_Auto2720[3]=es_Auto2720;
	_Context->msg_Auto2720[4]=de_Auto2720;
	_Context->msg_Auto2720[5]=nl_Auto2720;
	_Context->msg_Auto2720[6]=pt_Auto2720;
	_Context->msg_Auto2720[7]=xx_Auto2720;
	_Context->hint_Auto2720[0]=en__Auto2720;
	_Context->hint_Auto2720[1]=fr__Auto2720;
	_Context->hint_Auto2720[2]=it__Auto2720;
	_Context->hint_Auto2720[3]=es__Auto2720;
	_Context->hint_Auto2720[4]=de__Auto2720;
	_Context->hint_Auto2720[5]=nl__Auto2720;
	_Context->hint_Auto2720[6]=pt__Auto2720;
	_Context->hint_Auto2720[7]=xx__Auto2720;
	for (i=0; i < 8; i++)_Context->msg_Auto2721[i]=" ";
	_Context->msg_Auto2721[0]=en_Auto2721;
	_Context->msg_Auto2721[1]=fr_Auto2721;
	_Context->msg_Auto2721[2]=it_Auto2721;
	_Context->msg_Auto2721[3]=es_Auto2721;
	_Context->msg_Auto2721[4]=de_Auto2721;
	_Context->msg_Auto2721[5]=nl_Auto2721;
	_Context->msg_Auto2721[6]=pt_Auto2721;
	_Context->msg_Auto2721[7]=xx_Auto2721;
	_Context->hint_Auto2721[0]=en__Auto2721;
	_Context->hint_Auto2721[1]=fr__Auto2721;
	_Context->hint_Auto2721[2]=it__Auto2721;
	_Context->hint_Auto2721[3]=es__Auto2721;
	_Context->hint_Auto2721[4]=de__Auto2721;
	_Context->hint_Auto2721[5]=nl__Auto2721;
	_Context->hint_Auto2721[6]=pt__Auto2721;
	_Context->hint_Auto2721[7]=xx__Auto2721;
	for (i=0; i < 8; i++)_Context->msg_Auto2722[i]=" ";
	_Context->msg_Auto2722[0]=en_Auto2722;
	_Context->msg_Auto2722[1]=fr_Auto2722;
	_Context->msg_Auto2722[2]=it_Auto2722;
	_Context->msg_Auto2722[3]=es_Auto2722;
	_Context->msg_Auto2722[4]=de_Auto2722;
	_Context->msg_Auto2722[5]=nl_Auto2722;
	_Context->msg_Auto2722[6]=pt_Auto2722;
	_Context->msg_Auto2722[7]=xx_Auto2722;
	_Context->hint_Auto2722[0]=en__Auto2722;
	_Context->hint_Auto2722[1]=fr__Auto2722;
	_Context->hint_Auto2722[2]=it__Auto2722;
	_Context->hint_Auto2722[3]=es__Auto2722;
	_Context->hint_Auto2722[4]=de__Auto2722;
	_Context->hint_Auto2722[5]=nl__Auto2722;
	_Context->hint_Auto2722[6]=pt__Auto2722;
	_Context->hint_Auto2722[7]=xx__Auto2722;
	for (i=0; i < 8; i++)_Context->msg_Auto2723[i]=" ";
	_Context->msg_Auto2723[0]=en_Auto2723;
	_Context->msg_Auto2723[1]=fr_Auto2723;
	_Context->msg_Auto2723[2]=it_Auto2723;
	_Context->msg_Auto2723[3]=es_Auto2723;
	_Context->msg_Auto2723[4]=de_Auto2723;
	_Context->msg_Auto2723[5]=nl_Auto2723;
	_Context->msg_Auto2723[6]=pt_Auto2723;
	_Context->msg_Auto2723[7]=xx_Auto2723;
	_Context->hint_Auto2723[0]=en__Auto2723;
	_Context->hint_Auto2723[1]=fr__Auto2723;
	_Context->hint_Auto2723[2]=it__Auto2723;
	_Context->hint_Auto2723[3]=es__Auto2723;
	_Context->hint_Auto2723[4]=de__Auto2723;
	_Context->hint_Auto2723[5]=nl__Auto2723;
	_Context->hint_Auto2723[6]=pt__Auto2723;
	_Context->hint_Auto2723[7]=xx__Auto2723;
	for (i=0; i < 8; i++)_Context->msg_auto2[i]=" ";
	_Context->msg_auto2[0]=en_auto2;
	_Context->msg_auto2[1]=fr_auto2;
	_Context->msg_auto2[2]=it_auto2;
	_Context->msg_auto2[3]=es_auto2;
	_Context->msg_auto2[4]=de_auto2;
	_Context->msg_auto2[5]=nl_auto2;
	_Context->msg_auto2[6]=pt_auto2;
	_Context->msg_auto2[7]=xx_auto2;
	_Context->hint_auto2[0]=en__auto2;
	_Context->hint_auto2[1]=fr__auto2;
	_Context->hint_auto2[2]=it__auto2;
	_Context->hint_auto2[3]=es__auto2;
	_Context->hint_auto2[4]=de__auto2;
	_Context->hint_auto2[5]=nl__auto2;
	_Context->hint_auto2[6]=pt__auto2;
	_Context->hint_auto2[7]=xx__auto2;
	for (i=0; i < 8; i++)_Context->msg_Auto2724[i]=" ";
	_Context->msg_Auto2724[0]=en_Auto2724;
	_Context->msg_Auto2724[1]=fr_Auto2724;
	_Context->msg_Auto2724[2]=it_Auto2724;
	_Context->msg_Auto2724[3]=es_Auto2724;
	_Context->msg_Auto2724[4]=de_Auto2724;
	_Context->msg_Auto2724[5]=nl_Auto2724;
	_Context->msg_Auto2724[6]=pt_Auto2724;
	_Context->msg_Auto2724[7]=xx_Auto2724;
	_Context->hint_Auto2724[0]=en__Auto2724;
	_Context->hint_Auto2724[1]=fr__Auto2724;
	_Context->hint_Auto2724[2]=it__Auto2724;
	_Context->hint_Auto2724[3]=es__Auto2724;
	_Context->hint_Auto2724[4]=de__Auto2724;
	_Context->hint_Auto2724[5]=nl__Auto2724;
	_Context->hint_Auto2724[6]=pt__Auto2724;
	_Context->hint_Auto2724[7]=xx__Auto2724;
	for (i=0; i < 8; i++)_Context->msg_auto5[i]=" ";
	_Context->msg_auto5[0]=en_auto5;
	_Context->msg_auto5[1]=fr_auto5;
	_Context->msg_auto5[2]=it_auto5;
	_Context->msg_auto5[3]=es_auto5;
	_Context->msg_auto5[4]=de_auto5;
	_Context->msg_auto5[5]=nl_auto5;
	_Context->msg_auto5[6]=pt_auto5;
	_Context->msg_auto5[7]=xx_auto5;
	_Context->hint_auto5[0]=en__auto5;
	_Context->hint_auto5[1]=fr__auto5;
	_Context->hint_auto5[2]=it__auto5;
	_Context->hint_auto5[3]=es__auto5;
	_Context->hint_auto5[4]=de__auto5;
	_Context->hint_auto5[5]=nl__auto5;
	_Context->hint_auto5[6]=pt__auto5;
	_Context->hint_auto5[7]=xx__auto5;
	for (i=0; i < 8; i++)_Context->msg_auto6[i]=" ";
	_Context->msg_auto6[0]=en_auto6;
	_Context->msg_auto6[1]=fr_auto6;
	_Context->msg_auto6[2]=it_auto6;
	_Context->msg_auto6[3]=es_auto6;
	_Context->msg_auto6[4]=de_auto6;
	_Context->msg_auto6[5]=nl_auto6;
	_Context->msg_auto6[6]=pt_auto6;
	_Context->msg_auto6[7]=xx_auto6;
	_Context->hint_auto6[0]=en__auto6;
	_Context->hint_auto6[1]=fr__auto6;
	_Context->hint_auto6[2]=it__auto6;
	_Context->hint_auto6[3]=es__auto6;
	_Context->hint_auto6[4]=de__auto6;
	_Context->hint_auto6[5]=nl__auto6;
	_Context->hint_auto6[6]=pt__auto6;
	_Context->hint_auto6[7]=xx__auto6;
	for (i=0; i < 8; i++)_Context->msg_auto7[i]=" ";
	_Context->msg_auto7[0]=en_auto7;
	_Context->msg_auto7[1]=fr_auto7;
	_Context->msg_auto7[2]=it_auto7;
	_Context->msg_auto7[3]=es_auto7;
	_Context->msg_auto7[4]=de_auto7;
	_Context->msg_auto7[5]=nl_auto7;
	_Context->msg_auto7[6]=pt_auto7;
	_Context->msg_auto7[7]=xx_auto7;
	_Context->hint_auto7[0]=en__auto7;
	_Context->hint_auto7[1]=fr__auto7;
	_Context->hint_auto7[2]=it__auto7;
	_Context->hint_auto7[3]=es__auto7;
	_Context->hint_auto7[4]=de__auto7;
	_Context->hint_auto7[5]=nl__auto7;
	_Context->hint_auto7[6]=pt__auto7;
	_Context->hint_auto7[7]=xx__auto7;
	for (i=0; i < 8; i++)_Context->msg_auto17[i]=" ";
	_Context->msg_auto17[0]=en_auto17;
	_Context->msg_auto17[1]=fr_auto17;
	_Context->msg_auto17[2]=it_auto17;
	_Context->msg_auto17[3]=es_auto17;
	_Context->msg_auto17[4]=de_auto17;
	_Context->msg_auto17[5]=nl_auto17;
	_Context->msg_auto17[6]=pt_auto17;
	_Context->msg_auto17[7]=xx_auto17;
	for (i=0; i < 8; i++)_Context->msg_auto18[i]=" ";
	_Context->msg_auto18[0]=en_auto18;
	_Context->msg_auto18[1]=fr_auto18;
	_Context->msg_auto18[2]=it_auto18;
	_Context->msg_auto18[3]=es_auto18;
	_Context->msg_auto18[4]=de_auto18;
	_Context->msg_auto18[5]=nl_auto18;
	_Context->msg_auto18[6]=pt_auto18;
	_Context->msg_auto18[7]=xx_auto18;
	for (i=0; i < 8; i++)_Context->msg_auto19[i]=" ";
	_Context->msg_auto19[0]=en_auto19;
	_Context->msg_auto19[1]=fr_auto19;
	_Context->msg_auto19[2]=it_auto19;
	_Context->msg_auto19[3]=es_auto19;
	_Context->msg_auto19[4]=de_auto19;
	_Context->msg_auto19[5]=nl_auto19;
	_Context->msg_auto19[6]=pt_auto19;
	_Context->msg_auto19[7]=xx_auto19;
	for (i=0; i < 8; i++)_Context->msg_Auto2725[i]=" ";
	_Context->msg_Auto2725[0]=en_Auto2725;
	_Context->msg_Auto2725[1]=fr_Auto2725;
	_Context->msg_Auto2725[2]=it_Auto2725;
	_Context->msg_Auto2725[3]=es_Auto2725;
	_Context->msg_Auto2725[4]=de_Auto2725;
	_Context->msg_Auto2725[5]=nl_Auto2725;
	_Context->msg_Auto2725[6]=pt_Auto2725;
	_Context->msg_Auto2725[7]=xx_Auto2725;
	for (i=0; i < 8; i++)_Context->msg_Auto2726[i]=" ";
	_Context->msg_Auto2726[0]=en_Auto2726;
	_Context->msg_Auto2726[1]=fr_Auto2726;
	_Context->msg_Auto2726[2]=it_Auto2726;
	_Context->msg_Auto2726[3]=es_Auto2726;
	_Context->msg_Auto2726[4]=de_Auto2726;
	_Context->msg_Auto2726[5]=nl_Auto2726;
	_Context->msg_Auto2726[6]=pt_Auto2726;
	_Context->msg_Auto2726[7]=xx_Auto2726;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	_Context->msg_Select[2]=it_Select;
	_Context->msg_Select[3]=es_Select;
	_Context->msg_Select[4]=de_Select;
	_Context->msg_Select[5]=nl_Select;
	_Context->msg_Select[6]=pt_Select;
	_Context->msg_Select[7]=xx_Select;
	_Context->hint_Select[0]=en__Select;
	_Context->hint_Select[1]=fr__Select;
	_Context->hint_Select[2]=it__Select;
	_Context->hint_Select[3]=es__Select;
	_Context->hint_Select[4]=de__Select;
	_Context->hint_Select[5]=nl__Select;
	_Context->hint_Select[6]=pt__Select;
	_Context->hint_Select[7]=xx__Select;
	for (i=0; i < 8; i++)_Context->msg_auto197[i]=" ";
	_Context->msg_auto197[0]=en_auto197;
	_Context->msg_auto197[1]=fr_auto197;
	_Context->msg_auto197[2]=it_auto197;
	_Context->msg_auto197[3]=es_auto197;
	_Context->msg_auto197[4]=de_auto197;
	_Context->msg_auto197[5]=nl_auto197;
	_Context->msg_auto197[6]=pt_auto197;
	_Context->msg_auto197[7]=xx_auto197;
	_Context->hint_auto197[0]=en__auto197;
	_Context->hint_auto197[1]=fr__auto197;
	_Context->hint_auto197[2]=it__auto197;
	_Context->hint_auto197[3]=es__auto197;
	_Context->hint_auto197[4]=de__auto197;
	_Context->hint_auto197[5]=nl__auto197;
	_Context->hint_auto197[6]=pt__auto197;
	_Context->hint_auto197[7]=xx__auto197;
	for (i=0; i < 8; i++)_Context->msg_Auto2727[i]=" ";
	_Context->msg_Auto2727[0]=en_Auto2727;
	_Context->msg_Auto2727[1]=fr_Auto2727;
	_Context->msg_Auto2727[2]=it_Auto2727;
	_Context->msg_Auto2727[3]=es_Auto2727;
	_Context->msg_Auto2727[4]=de_Auto2727;
	_Context->msg_Auto2727[5]=nl_Auto2727;
	_Context->msg_Auto2727[6]=pt_Auto2727;
	_Context->msg_Auto2727[7]=xx_Auto2727;
	_Context->hint_Auto2727[0]=en__Auto2727;
	_Context->hint_Auto2727[1]=fr__Auto2727;
	_Context->hint_Auto2727[2]=it__Auto2727;
	_Context->hint_Auto2727[3]=es__Auto2727;
	_Context->hint_Auto2727[4]=de__Auto2727;
	_Context->hint_Auto2727[5]=nl__Auto2727;
	_Context->hint_Auto2727[6]=pt__Auto2727;
	_Context->hint_Auto2727[7]=xx__Auto2727;
	for (i=0; i < 8; i++)_Context->msg_Auto2728[i]=" ";
	_Context->msg_Auto2728[0]=en_Auto2728;
	_Context->msg_Auto2728[1]=fr_Auto2728;
	_Context->msg_Auto2728[2]=it_Auto2728;
	_Context->msg_Auto2728[3]=es_Auto2728;
	_Context->msg_Auto2728[4]=de_Auto2728;
	_Context->msg_Auto2728[5]=nl_Auto2728;
	_Context->msg_Auto2728[6]=pt_Auto2728;
	_Context->msg_Auto2728[7]=xx_Auto2728;
	_Context->hint_Auto2728[0]=en__Auto2728;
	_Context->hint_Auto2728[1]=fr__Auto2728;
	_Context->hint_Auto2728[2]=it__Auto2728;
	_Context->hint_Auto2728[3]=es__Auto2728;
	_Context->hint_Auto2728[4]=de__Auto2728;
	_Context->hint_Auto2728[5]=nl__Auto2728;
	_Context->hint_Auto2728[6]=pt__Auto2728;
	_Context->hint_Auto2728[7]=xx__Auto2728;
	for (i=0; i < 8; i++)_Context->msg_ImageFormat[i]=" ";
	_Context->msg_ImageFormat[1]=fr_ImageFormat;
	_Context->msg_ImageFormat[2]=it_ImageFormat;
	_Context->msg_ImageFormat[3]=es_ImageFormat;
	_Context->msg_ImageFormat[4]=de_ImageFormat;
	_Context->msg_ImageFormat[5]=nl_ImageFormat;
	_Context->msg_ImageFormat[6]=pt_ImageFormat;
	_Context->msg_ImageFormat[7]=xx_ImageFormat;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto1,_Context->y_auto1,610+10,320+10);
	return(0);
}

public 	int	accept_cube_properties_hide(struct accept_cube_properties_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_auto1,_Context->y_auto1);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_cube_properties_remove(
	struct accept_cube_properties_context * _Context,
	char * pIdentity,
	char * pPosition,
	char * ptly,
	char * ptlz,
	char * pDimensions,
	char * pbry,
	char * pbrz,
	char * pClass,
	char * pAuto2727,
	char * pAuto2728,
	char * pImageFormat,
	char * pBack,
	char * pFront,
	char * pLeft,
	char * pRight,
	char * pUpper,
	char * pLower,
	char * pLight,
	char * pDark)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWWWWKWWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Identity, 255, pIdentity);
		visual_transferout(_Context->buffer_Position, 7, pPosition);
		visual_transferout(_Context->buffer_tly, 7, ptly);
		visual_transferout(_Context->buffer_tlz, 7, ptlz);
		visual_transferout(_Context->buffer_Dimensions, 7, pDimensions);
		visual_transferout(_Context->buffer_bry, 7, pbry);
		visual_transferout(_Context->buffer_brz, 7, pbrz);
		visual_transferout(_Context->buffer_Class, 255, pClass);
		visual_transferout((void *) 0, 0, pAuto2727);
		if ( pAuto2727 != (char *) 0)
			*((int*)pAuto2727) = _Context->value_Auto2727;
		visual_transferout((void *) 0, 0, pAuto2728);
		if ( pAuto2728 != (char *) 0)
			*((int*)pAuto2728) = _Context->value_Auto2728;
		visual_transferout((void *) 0, 0, pImageFormat);
		if ( pImageFormat != (char *) 0)
			*((int*)pImageFormat) = _Context->value_ImageFormat;
		visual_transferout(_Context->buffer_Back, 7, pBack);
		visual_transferout(_Context->buffer_Front, 7, pFront);
		visual_transferout(_Context->buffer_Left, 7, pLeft);
		visual_transferout(_Context->buffer_Right, 7, pRight);
		visual_transferout(_Context->buffer_Upper, 7, pUpper);
		visual_transferout(_Context->buffer_Lower, 7, pLower);
		visual_transferout(_Context->buffer_Light, 7, pLight);
		visual_transferout(_Context->buffer_Dark, 7, pDark);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_cube_properties_show(struct accept_cube_properties_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto1,_Context->y_auto1);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_auto1,_Context->y_auto1,610,320,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_auto1,_Context->y_auto1,610,320,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_auto1+20,_Context->y_auto1+190,570,16,vfh[2],0,0,_Context->msg_Auto2715[_Context->language],strlen(_Context->msg_Auto2715[_Context->language]),258);
	visual_frame(_Context->x_auto1+20,_Context->y_auto1+206,570,44,3);
	visual_text(_Context->x_auto1+90,_Context->y_auto1+210,70,16,vfh[2],16,0,_Context->msg_Auto2716[_Context->language],strlen(_Context->msg_Auto2716[_Context->language]),259);
	visual_text(_Context->x_auto1+90,_Context->y_auto1+230,70,16,vfh[2],16,0,_Context->msg_Auto2717[_Context->language],strlen(_Context->msg_Auto2717[_Context->language]),259);
	visual_text(_Context->x_auto1+220,_Context->y_auto1+210,56,16,vfh[2],16,0,_Context->msg_Auto2718[_Context->language],strlen(_Context->msg_Auto2718[_Context->language]),259);
	visual_text(_Context->x_auto1+220,_Context->y_auto1+230,56,16,vfh[2],16,0,_Context->msg_Auto2719[_Context->language],strlen(_Context->msg_Auto2719[_Context->language]),259);
	visual_text(_Context->x_auto1+340,_Context->y_auto1+210,56,16,vfh[2],16,0,_Context->msg_Auto2720[_Context->language],strlen(_Context->msg_Auto2720[_Context->language]),259);
	visual_text(_Context->x_auto1+340,_Context->y_auto1+230,56,16,vfh[2],16,0,_Context->msg_Auto2721[_Context->language],strlen(_Context->msg_Auto2721[_Context->language]),259);
	visual_text(_Context->x_auto1+460,_Context->y_auto1+210,56,16,vfh[2],16,0,_Context->msg_Auto2722[_Context->language],strlen(_Context->msg_Auto2722[_Context->language]),259);
	visual_text(_Context->x_auto1+460,_Context->y_auto1+230,56,16,vfh[2],16,0,_Context->msg_Auto2723[_Context->language],strlen(_Context->msg_Auto2723[_Context->language]),259);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+30,575,20,vfh[3],16,0,_Context->msg_auto2[_Context->language],strlen(_Context->msg_auto2[_Context->language]),1282);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+110,570,16,vfh[2],0,0,_Context->msg_Auto2724[_Context->language],strlen(_Context->msg_Auto2724[_Context->language]),258);
	visual_frame(_Context->x_auto1+20,_Context->y_auto1+126,570,54,3);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+60,100,20,vfh[2],16,0,_Context->msg_auto5[_Context->language],strlen(_Context->msg_auto5[_Context->language]),258);
	visual_text(_Context->x_auto1+30,_Context->y_auto1+130,80,20,vfh[2],16,0,_Context->msg_auto6[_Context->language],strlen(_Context->msg_auto6[_Context->language]),258);
	visual_text(_Context->x_auto1+30,_Context->y_auto1+150,100,20,vfh[2],16,0,_Context->msg_auto7[_Context->language],strlen(_Context->msg_auto7[_Context->language]),258);
	visual_frame(_Context->x_auto1+130,_Context->y_auto1+60,456+2,16+2,5);
	visual_text(_Context->x_auto1+130+1,_Context->y_auto1+60+1,456,16,vfh[1],26,0,_Context->buffer_Identity,255,0);
	visual_frame(_Context->x_auto1+130,_Context->y_auto1+130,56+2,16+2,5);
	visual_text(_Context->x_auto1+130+1,_Context->y_auto1+130+1,56,16,vfh[1],26,0,_Context->buffer_Position,7,0);
	visual_frame(_Context->x_auto1+210,_Context->y_auto1+130,56+2,16+2,5);
	visual_text(_Context->x_auto1+210+1,_Context->y_auto1+130+1,56,16,vfh[1],26,0,_Context->buffer_tly,7,0);
	visual_frame(_Context->x_auto1+290,_Context->y_auto1+130,56+2,16+2,5);
	visual_text(_Context->x_auto1+290+1,_Context->y_auto1+130+1,56,16,vfh[1],26,0,_Context->buffer_tlz,7,0);
	visual_frame(_Context->x_auto1+130,_Context->y_auto1+150,56+2,16+2,5);
	visual_text(_Context->x_auto1+130+1,_Context->y_auto1+150+1,56,16,vfh[1],26,0,_Context->buffer_Dimensions,7,0);
	visual_frame(_Context->x_auto1+210,_Context->y_auto1+150,56+2,16+2,5);
	visual_text(_Context->x_auto1+210+1,_Context->y_auto1+150+1,56,16,vfh[1],26,0,_Context->buffer_bry,7,0);
	visual_frame(_Context->x_auto1+290,_Context->y_auto1+150,56+2,16+2,5);
	visual_text(_Context->x_auto1+290+1,_Context->y_auto1+150+1,56,16,vfh[1],26,0,_Context->buffer_brz,7,0);
	visual_text(_Context->x_auto1+110,_Context->y_auto1+140,14,16,vfh[2],16,0,_Context->msg_auto17[_Context->language],strlen(_Context->msg_auto17[_Context->language]),259);
	visual_text(_Context->x_auto1+190,_Context->y_auto1+140,14,16,vfh[2],16,0,_Context->msg_auto18[_Context->language],strlen(_Context->msg_auto18[_Context->language]),259);
	visual_text(_Context->x_auto1+270,_Context->y_auto1+140,14,16,vfh[2],16,0,_Context->msg_auto19[_Context->language],strlen(_Context->msg_auto19[_Context->language]),259);
	_Context->trigger_Auto2725=visual_trigger_code(_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]));
	visual_button(_Context->x_auto1+20,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]),1040);
	_Context->trigger_Auto2726=visual_trigger_code(_Context->msg_Auto2726[_Context->language],strlen(_Context->msg_Auto2726[_Context->language]));
	visual_button(_Context->x_auto1+530,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto2726[_Context->language],strlen(_Context->msg_Auto2726[_Context->language]),1040);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto1+230,_Context->y_auto1+270,140,32,vfh[2],27,28,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+80,100,20,vfh[2],16,0,_Context->msg_auto197[_Context->language],strlen(_Context->msg_auto197[_Context->language]),258);
	visual_frame(_Context->x_auto1+130,_Context->y_auto1+80,456+2,16+2,5);
	visual_text(_Context->x_auto1+130+1,_Context->y_auto1+80+1,456,16,vfh[1],26,0,_Context->buffer_Class,255,2);
	_Context->trigger_Auto2727=visual_trigger_code(_Context->msg_Auto2727[_Context->language],strlen(_Context->msg_Auto2727[_Context->language]));
	visual_check(_Context->x_auto1+370,_Context->y_auto1+130,112,16,vfh[2],26,0,_Context->msg_Auto2727[_Context->language],strlen(_Context->msg_Auto2727[_Context->language]),_Context->value_Auto2727|0);
	_Context->trigger_Auto2728=visual_trigger_code(_Context->msg_Auto2728[_Context->language],strlen(_Context->msg_Auto2728[_Context->language]));
	visual_check(_Context->x_auto1+480,_Context->y_auto1+130,112,16,vfh[2],26,0,_Context->msg_Auto2728[_Context->language],strlen(_Context->msg_Auto2728[_Context->language]),_Context->value_Auto2728|0);
	visual_select(_Context->x_auto1+370,_Context->y_auto1+150,104,96,vfh[1],0,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),0);
	visual_frame(_Context->x_auto1+160,_Context->y_auto1+210,56+2,16+2,5);
	visual_text(_Context->x_auto1+160+1,_Context->y_auto1+210+1,56,16,vfh[1],0,0,_Context->buffer_Back,7,0);
	visual_frame(_Context->x_auto1+160,_Context->y_auto1+230,56+2,16+2,5);
	visual_text(_Context->x_auto1+160+1,_Context->y_auto1+230+1,56,16,vfh[1],0,0,_Context->buffer_Front,7,0);
	visual_frame(_Context->x_auto1+280,_Context->y_auto1+210,56+2,16+2,5);
	visual_text(_Context->x_auto1+280+1,_Context->y_auto1+210+1,56,16,vfh[1],0,0,_Context->buffer_Left,7,0);
	visual_frame(_Context->x_auto1+280,_Context->y_auto1+230,56+2,16+2,5);
	visual_text(_Context->x_auto1+280+1,_Context->y_auto1+230+1,56,16,vfh[1],0,0,_Context->buffer_Right,7,0);
	visual_frame(_Context->x_auto1+400,_Context->y_auto1+210,56+2,16+2,5);
	visual_text(_Context->x_auto1+400+1,_Context->y_auto1+210+1,56,16,vfh[1],0,0,_Context->buffer_Upper,7,0);
	visual_frame(_Context->x_auto1+400,_Context->y_auto1+230,56+2,16+2,5);
	visual_text(_Context->x_auto1+400+1,_Context->y_auto1+230+1,56,16,vfh[1],0,0,_Context->buffer_Lower,7,0);
	visual_frame(_Context->x_auto1+520,_Context->y_auto1+210,56+2,16+2,5);
	visual_text(_Context->x_auto1+520+1,_Context->y_auto1+210+1,56,16,vfh[1],0,0,_Context->buffer_Light,7,0);
	visual_frame(_Context->x_auto1+520,_Context->y_auto1+230,56+2,16+2,5);
	visual_text(_Context->x_auto1+520+1,_Context->y_auto1+230+1,56,16,vfh[1],0,0,_Context->buffer_Dark,7,0);
	visual_thaw(_Context->x_auto1,_Context->y_auto1,610,320);

	return(0);
}

private int Identity_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[13];
			mptr[0] = "This edit field allows the generic name of the model entity to be ";
			mptr[1]="specified.   ";
			mptr[2]=" ";
			mptr[3]="Depending on the class or nature of the component an  extension will ";
			mptr[4]="be added to the name provided here  ";
			mptr[5]=" ";
			mptr[6]="   ";
			mptr[7]=" FORM The name token will be postfixed by   .gif or .bmp to form the ";
			mptr[8]="image filename, and by .sng  to form the relevant component model filename.  ";
			mptr[9]=" IMAGE No extension will be added since the  exact filename is required ";
			mptr[10]="for image model loading.  ";
			mptr[11]=" SOURCE Again no extension will be added as the  exact filename is required. ";
			mptr[12]="   ";
			return(visual_online_help(mptr,13));
			}
			break;
		case 1 : 
			{
			char * mptr[13];
			mptr[0] = "Ce champs de saisie permet de specifier le nom generic  du model a ";
			mptr[1]="charger.  ";
			mptr[2]=" ";
			mptr[3]="L'extension du fichier sera rajout‚ en fonction du class  du composent ";
			mptr[4]="ou entit‚.  ";
			mptr[5]=" ";
			mptr[6]="   ";
			mptr[7]=" FORM Dans ce cas, l'extension doit etre omise. L'extension GIF sera ";
			mptr[8]="rajout‚ pour le chargement  de l'image et l'extension SNG pour le fichier  de resource de description du formulaire.  ";
			mptr[9]=" IMAGE L'extension doit etre fourni pour definir le nom de fichier exact ";
			mptr[10]="de l'image … charger.  ";
			mptr[11]=" SOURCE Encore, l'extension doit etre specifi‚ pour bien identifier ";
			mptr[12]="le fichier source.    ";
			return(visual_online_help(mptr,13));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Position_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The POSITION X, Y, and Z edit fields allow the position within the ";
			mptr[1]="    application model 3d space of the top left hand corner to be inspected ";
			mptr[2]="or modified.     ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Dimensions_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The VECTOR X, Y and Z edit fields provide the dimensions of the cube ";
			mptr[1]="along the relevant AXIS in a positive direction from the top left ";
			mptr[2]="corner of the component cube.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2725_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the ACCEPT button any changes made to the various    parameters ";
			mptr[1]="will take effect.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2726_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the CANCEL button any modifications performed will be ";
			mptr[1]="   discarded.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Select_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This push button gives access to file selector dialog box allowing ";
			mptr[1]="prompted selection of the application component.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Class_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The CLASS edit field provides the name of the application entity  ";
			mptr[1]="  class, either FORM, IMAGE or SOURCE.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2727_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "if the AUTOSIZE check box is checked the VECTOR information will be ";
			mptr[1]="adjusted to the real size of the image used to represent the application ";
			mptr[2]=" model component. When it is unchecked values provided manually will ";
			mptr[3]="be respected.  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2728_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "if this control is checked then the object cube will remain fixed ";
			mptr[1]="in the three d space. All attempts to move it will be ignored, including ";
			mptr[2]="the project reorganisation menu operation.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ImageFormat_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This select control allows the image format to be specified. Currently ";
			mptr[1]="the only  formats that may be produced are BMP and GIF. The later producing mush smaller files but may require ";
			mptr[2]="longer image save times.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int auto1action(struct accept_cube_properties_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_cube_properties_hide(_Context);

		_Context->x_auto1 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto1 < 0) { _Context->x_auto1=0; }
		_Context->y_auto1 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto1 < 0) { _Context->y_auto1=0; }
			accept_cube_properties_show(_Context);

		visual_thaw(_Context->x_auto1,_Context->y_auto1,610,320);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto2725_event(struct accept_cube_properties_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto2726_event(struct accept_cube_properties_context * _Context) {
	return(27);
	return(-1);
}
private int on_Select_event(struct accept_cube_properties_context * _Context) {
	int ft=WIDGET_FILE_ANY;
	int i;
	int c;
	for(i=0;i<255;i++)
	if((_Context->buffer_Class[i]==' ')
	||(_Context->buffer_Class[i]==0))
	break;
	c=_Context->buffer_Class[i];
	_Context->buffer_Class[i]=0;
	if(!(strcmp(_Context->buffer_Class,"form")))
	ft=WIDGET_FILE_XML;
	else if(!(strcmp(_Context->buffer_Class,"text")))
	ft=WIDGET_FILE_AS;
	else if(!(strcmp(_Context->buffer_Class,"image")))
	ft=WIDGET_FILE_JPG;
	else ft=WIDGET_FILE_ANY;
	_Context->buffer_Class[i]=c;
	use_file_selector(_Context->buffer_Identity,ft);
		accept_cube_properties_show(_Context);
;
	return(-1);
}


public	int	accept_cube_properties_event(
struct accept_cube_properties_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto2725 == mb ) return(9);
		if (_Context->trigger_Auto2726 == mb ) return(10);
		if (_Context->trigger_Select == mb ) return(11);
		if (_Context->trigger_Auto2727 == mb ) return(12);
		if (_Context->trigger_Auto2728 == mb ) return(13);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_auto1+589) )  
	&&  (my >= (_Context->y_auto1+4) )  
	&&  (mx <= (_Context->x_auto1+606) )  
	&&  (my <= (_Context->y_auto1+20) )) {
		return(1);	/* auto1 */

		}
	if ((mx >= (_Context->x_auto1+573) )  
	&&  (my >= (_Context->y_auto1+4) )  
	&&  (mx <= (_Context->x_auto1+590) )  
	&&  (my <= (_Context->y_auto1+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcube.htm");
			};
		return(-1);	/* auto1 */

		}
	if ((mx >= (_Context->x_auto1+557) )  
	&&  (my >= (_Context->y_auto1+4) )  
	&&  (mx <= (_Context->x_auto1+574) )  
	&&  (my <= (_Context->y_auto1+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_cube_properties_show(_Context);
		return(-1);	/* auto1 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_auto1+4) )  
		&&  (my >= (_Context->y_auto1+4) )  
		&&  (mx <= (_Context->x_auto1+542) )  
		&&  (my <= (_Context->y_auto1+20) )) {
			return( auto1action(_Context) );
			}
		}
	if (( mx >= (_Context->x_auto1+130) ) 
	&&  ( my >= (_Context->y_auto1+60) ) 
	&&  ( mx <= (_Context->x_auto1+130+456) ) 
	&&  ( my <= (_Context->y_auto1+60+16))) {
		return(2); /* Identity */
		}
	if (( mx >= (_Context->x_auto1+130) ) 
	&&  ( my >= (_Context->y_auto1+130) ) 
	&&  ( mx <= (_Context->x_auto1+130+56) ) 
	&&  ( my <= (_Context->y_auto1+130+16))) {
		return(3); /* Position */
		}
	if (( mx >= (_Context->x_auto1+210) ) 
	&&  ( my >= (_Context->y_auto1+130) ) 
	&&  ( mx <= (_Context->x_auto1+210+56) ) 
	&&  ( my <= (_Context->y_auto1+130+16))) {
		return(4); /* tly */
		}
	if (( mx >= (_Context->x_auto1+290) ) 
	&&  ( my >= (_Context->y_auto1+130) ) 
	&&  ( mx <= (_Context->x_auto1+290+56) ) 
	&&  ( my <= (_Context->y_auto1+130+16))) {
		return(5); /* tlz */
		}
	if (( mx >= (_Context->x_auto1+130) ) 
	&&  ( my >= (_Context->y_auto1+150) ) 
	&&  ( mx <= (_Context->x_auto1+130+56) ) 
	&&  ( my <= (_Context->y_auto1+150+16))) {
		return(6); /* Dimensions */
		}
	if (( mx >= (_Context->x_auto1+210) ) 
	&&  ( my >= (_Context->y_auto1+150) ) 
	&&  ( mx <= (_Context->x_auto1+210+56) ) 
	&&  ( my <= (_Context->y_auto1+150+16))) {
		return(7); /* bry */
		}
	if (( mx >= (_Context->x_auto1+290) ) 
	&&  ( my >= (_Context->y_auto1+150) ) 
	&&  ( mx <= (_Context->x_auto1+290+56) ) 
	&&  ( my <= (_Context->y_auto1+150+16))) {
		return(8); /* brz */
		}
	if (( mx >= (_Context->x_auto1+20) ) 
	&&  ( my >= (_Context->y_auto1+260) ) 
	&&  ( mx <= (_Context->x_auto1+20+56) ) 
	&&  ( my <= (_Context->y_auto1+260+48))) {
		return(9); /* Auto2725 */
		}
	if (( mx >= (_Context->x_auto1+530) ) 
	&&  ( my >= (_Context->y_auto1+260) ) 
	&&  ( mx <= (_Context->x_auto1+530+56) ) 
	&&  ( my <= (_Context->y_auto1+260+48))) {
		return(10); /* Auto2726 */
		}
	if (( mx >= (_Context->x_auto1+230) ) 
	&&  ( my >= (_Context->y_auto1+270) ) 
	&&  ( mx <= (_Context->x_auto1+230+140) ) 
	&&  ( my <= (_Context->y_auto1+270+32))) {
		return(11); /* Select */
		}
	if (( mx >= (_Context->x_auto1+370) ) 
	&&  ( my >= (_Context->y_auto1+130) ) 
	&&  ( mx <= (_Context->x_auto1+370+112) ) 
	&&  ( my <= (_Context->y_auto1+130+16))) {
		return(12); /* Auto2727 */
		}
	if (( mx >= (_Context->x_auto1+480) ) 
	&&  ( my >= (_Context->y_auto1+130) ) 
	&&  ( mx <= (_Context->x_auto1+480+112) ) 
	&&  ( my <= (_Context->y_auto1+130+16))) {
		return(13); /* Auto2728 */
		}
	if (( mx >= (_Context->x_auto1+370+0) ) 
	&&  ( my >= (_Context->y_auto1+150) ) 
	&&  ( mx <= (_Context->x_auto1+370+104) ) 
	&&  ( my <= (_Context->y_auto1+150+16))) {
		return(14); /* ImageFormat */
		}
	if (( mx >= (_Context->x_auto1+160) ) 
	&&  ( my >= (_Context->y_auto1+210) ) 
	&&  ( mx <= (_Context->x_auto1+160+56) ) 
	&&  ( my <= (_Context->y_auto1+210+16))) {
		return(15); /* Back */
		}
	if (( mx >= (_Context->x_auto1+160) ) 
	&&  ( my >= (_Context->y_auto1+230) ) 
	&&  ( mx <= (_Context->x_auto1+160+56) ) 
	&&  ( my <= (_Context->y_auto1+230+16))) {
		return(16); /* Front */
		}
	if (( mx >= (_Context->x_auto1+280) ) 
	&&  ( my >= (_Context->y_auto1+210) ) 
	&&  ( mx <= (_Context->x_auto1+280+56) ) 
	&&  ( my <= (_Context->y_auto1+210+16))) {
		return(17); /* Left */
		}
	if (( mx >= (_Context->x_auto1+280) ) 
	&&  ( my >= (_Context->y_auto1+230) ) 
	&&  ( mx <= (_Context->x_auto1+280+56) ) 
	&&  ( my <= (_Context->y_auto1+230+16))) {
		return(18); /* Right */
		}
	if (( mx >= (_Context->x_auto1+400) ) 
	&&  ( my >= (_Context->y_auto1+210) ) 
	&&  ( mx <= (_Context->x_auto1+400+56) ) 
	&&  ( my <= (_Context->y_auto1+210+16))) {
		return(19); /* Upper */
		}
	if (( mx >= (_Context->x_auto1+400) ) 
	&&  ( my >= (_Context->y_auto1+230) ) 
	&&  ( mx <= (_Context->x_auto1+400+56) ) 
	&&  ( my <= (_Context->y_auto1+230+16))) {
		return(20); /* Lower */
		}
	if (( mx >= (_Context->x_auto1+520) ) 
	&&  ( my >= (_Context->y_auto1+210) ) 
	&&  ( mx <= (_Context->x_auto1+520+56) ) 
	&&  ( my <= (_Context->y_auto1+210+16))) {
		return(21); /* Light */
		}
	if (( mx >= (_Context->x_auto1+520) ) 
	&&  ( my >= (_Context->y_auto1+230) ) 
	&&  ( mx <= (_Context->x_auto1+520+56) ) 
	&&  ( my <= (_Context->y_auto1+230+16))) {
		return(22); /* Dark */
		}

	return(-1);
}


public	int	accept_cube_properties_focus(struct accept_cube_properties_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Identity */
				_Context->keycode = visual_edit(_Context->x_auto1+130+1,_Context->y_auto1+60+1,456,16,vfh[1],_Context->buffer_Identity,255);
			break;
			case	0x3 :
				/* Position */
				_Context->keycode = visual_edit(_Context->x_auto1+130+1,_Context->y_auto1+130+1,56,16,vfh[1],_Context->buffer_Position,7);
			break;
			case	0x4 :
				/* tly */
				_Context->keycode = visual_edit(_Context->x_auto1+210+1,_Context->y_auto1+130+1,56,16,vfh[1],_Context->buffer_tly,7);
			break;
			case	0x5 :
				/* tlz */
				_Context->keycode = visual_edit(_Context->x_auto1+290+1,_Context->y_auto1+130+1,56,16,vfh[1],_Context->buffer_tlz,7);
			break;
			case	0x6 :
				/* Dimensions */
				_Context->keycode = visual_edit(_Context->x_auto1+130+1,_Context->y_auto1+150+1,56,16,vfh[1],_Context->buffer_Dimensions,7);
			break;
			case	0x7 :
				/* bry */
				_Context->keycode = visual_edit(_Context->x_auto1+210+1,_Context->y_auto1+150+1,56,16,vfh[1],_Context->buffer_bry,7);
			break;
			case	0x8 :
				/* brz */
				_Context->keycode = visual_edit(_Context->x_auto1+290+1,_Context->y_auto1+150+1,56,16,vfh[1],_Context->buffer_brz,7);
			break;
			case	0x9 :
				/* Auto2725 */
				_Context->trigger_Auto2725=visual_trigger_code(_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]));
				visual_button(_Context->x_auto1+20,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2725=visual_trigger_code(_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]));
	visual_button(_Context->x_auto1+20,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]),1040);
				break;
			case	0xa :
				/* Auto2726 */
				_Context->trigger_Auto2726=visual_trigger_code(_Context->msg_Auto2726[_Context->language],strlen(_Context->msg_Auto2726[_Context->language]));
				visual_button(_Context->x_auto1+530,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto2726[_Context->language],strlen(_Context->msg_Auto2726[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2726=visual_trigger_code(_Context->msg_Auto2726[_Context->language],strlen(_Context->msg_Auto2726[_Context->language]));
	visual_button(_Context->x_auto1+530,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto2726[_Context->language],strlen(_Context->msg_Auto2726[_Context->language]),1040);
				break;
			case	0xb :
				/* Select */
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
				visual_button(_Context->x_auto1+230,_Context->y_auto1+270,140,32,vfh[2],27,28,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto1+230,_Context->y_auto1+270,140,32,vfh[2],27,28,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;
			case	0xc :
				/* Auto2727 */
				visual_check(_Context->x_auto1+370,_Context->y_auto1+130,112,16,vfh[2],26,0,_Context->msg_Auto2727[_Context->language],strlen(_Context->msg_Auto2727[_Context->language]),(_Context->value_Auto2727 |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2727=visual_trigger_code(_Context->msg_Auto2727[_Context->language],strlen(_Context->msg_Auto2727[_Context->language]));
	visual_check(_Context->x_auto1+370,_Context->y_auto1+130,112,16,vfh[2],26,0,_Context->msg_Auto2727[_Context->language],strlen(_Context->msg_Auto2727[_Context->language]),_Context->value_Auto2727|0);
				break;
			case	0xd :
				/* Auto2728 */
				visual_check(_Context->x_auto1+480,_Context->y_auto1+130,112,16,vfh[2],26,0,_Context->msg_Auto2728[_Context->language],strlen(_Context->msg_Auto2728[_Context->language]),(_Context->value_Auto2728 |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2728=visual_trigger_code(_Context->msg_Auto2728[_Context->language],strlen(_Context->msg_Auto2728[_Context->language]));
	visual_check(_Context->x_auto1+480,_Context->y_auto1+130,112,16,vfh[2],26,0,_Context->msg_Auto2728[_Context->language],strlen(_Context->msg_Auto2728[_Context->language]),_Context->value_Auto2728|0);
				break;
			case	0xe :
				/* ImageFormat */
				_Context->keycode = visual_select(_Context->x_auto1+370,_Context->y_auto1+150,104,96,vfh[1],0,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),2);
				break;
			case	0xf :
				/* Back */
				_Context->keycode = visual_edit(_Context->x_auto1+160+1,_Context->y_auto1+210+1,56,16,vfh[1],_Context->buffer_Back,7);
			break;
			case	0x10 :
				/* Front */
				_Context->keycode = visual_edit(_Context->x_auto1+160+1,_Context->y_auto1+230+1,56,16,vfh[1],_Context->buffer_Front,7);
			break;
			case	0x11 :
				/* Left */
				_Context->keycode = visual_edit(_Context->x_auto1+280+1,_Context->y_auto1+210+1,56,16,vfh[1],_Context->buffer_Left,7);
			break;
			case	0x12 :
				/* Right */
				_Context->keycode = visual_edit(_Context->x_auto1+280+1,_Context->y_auto1+230+1,56,16,vfh[1],_Context->buffer_Right,7);
			break;
			case	0x13 :
				/* Upper */
				_Context->keycode = visual_edit(_Context->x_auto1+400+1,_Context->y_auto1+210+1,56,16,vfh[1],_Context->buffer_Upper,7);
			break;
			case	0x14 :
				/* Lower */
				_Context->keycode = visual_edit(_Context->x_auto1+400+1,_Context->y_auto1+230+1,56,16,vfh[1],_Context->buffer_Lower,7);
			break;
			case	0x15 :
				/* Light */
				_Context->keycode = visual_edit(_Context->x_auto1+520+1,_Context->y_auto1+210+1,56,16,vfh[1],_Context->buffer_Light,7);
			break;
			case	0x16 :
				/* Dark */
				_Context->keycode = visual_edit(_Context->x_auto1+520+1,_Context->y_auto1+230+1,56,16,vfh[1],_Context->buffer_Dark,7);
			break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_cube_properties_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=22;
			accept_cube_properties_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_cube_properties_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (Identity_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Position_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (Dimensions_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (Auto2725_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (Auto2726_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Select_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (Auto2727_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (Auto2728_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (ImageFormat_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* auto1 */
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
					/* Position */
					continue;
				case	0x4 :
					/* tly */
					continue;
				case	0x5 :
					/* tlz */
					continue;
				case	0x6 :
					/* Dimensions */
					continue;
				case	0x7 :
					/* bry */
					continue;
				case	0x8 :
					/* brz */
					continue;
				case	0x9 :
					/* Auto2725 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2725=visual_trigger_code(_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]));
						visual_button(_Context->x_auto1+20,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2725=visual_trigger_code(_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]));
	visual_button(_Context->x_auto1+20,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto2725[_Context->language],strlen(_Context->msg_Auto2725[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2725_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Auto2726 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2726=visual_trigger_code(_Context->msg_Auto2726[_Context->language],strlen(_Context->msg_Auto2726[_Context->language]));
						visual_button(_Context->x_auto1+530,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto2726[_Context->language],strlen(_Context->msg_Auto2726[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2726=visual_trigger_code(_Context->msg_Auto2726[_Context->language],strlen(_Context->msg_Auto2726[_Context->language]));
	visual_button(_Context->x_auto1+530,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto2726[_Context->language],strlen(_Context->msg_Auto2726[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2726_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* Select */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
						visual_button(_Context->x_auto1+230,_Context->y_auto1+270,140,32,vfh[2],27,28,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto1+230,_Context->y_auto1+270,140,32,vfh[2],27,28,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Select_event(_Context)) != -1) break;

						}
					continue;
				case	0xc :
					/* Auto2727 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Auto2727 += 1;
						_Context->value_Auto2727 &= 1;
						}
					continue;
				case	0xd :
					/* Auto2728 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Auto2728 += 1;
						_Context->value_Auto2728 &= 1;
						}
					continue;
				case	0xe :
					/* ImageFormat */
					continue;
				case	0xf :
					/* Back */
					continue;
				case	0x10 :
					/* Front */
					continue;
				case	0x11 :
					/* Left */
					continue;
				case	0x12 :
					/* Right */
					continue;
				case	0x13 :
					/* Upper */
					continue;
				case	0x14 :
					/* Lower */
					continue;
				case	0x15 :
					/* Light */
					continue;
				case	0x16 :
					/* Dark */
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
				_Context->focus_item=22;
			}
			continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_cube_properties(
	char * pIdentity,
	char * pPosition,
	char * ptly,
	char * ptlz,
	char * pDimensions,
	char * pbry,
	char * pbrz,
	char * pClass,
	char * pAuto2727,
	char * pAuto2728,
	char * pImageFormat,
	char * pBack,
	char * pFront,
	char * pLeft,
	char * pRight,
	char * pUpper,
	char * pLower,
	char * pLight,
	char * pDark)
{
	int	status=0;
	struct accept_cube_properties_context * _Context=(struct accept_cube_properties_context*) 0;
	status = accept_cube_properties_create(
	&_Context,
	 pIdentity,
	 pPosition,
	 ptly,
	 ptlz,
	 pDimensions,
	 pbry,
	 pbrz,
	 pClass,
	 pAuto2727,
	 pAuto2728,
	 pImageFormat,
	 pBack,
	 pFront,
	 pLeft,
	 pRight,
	 pUpper,
	 pLower,
	 pLight,
	 pDark);
	if ( status != 0) return(status);
	status = accept_cube_properties_show(_Context);
		enter_modal();
	status = accept_cube_properties_focus(_Context);
		leave_modal();
	status = accept_cube_properties_hide(_Context);
	status = accept_cube_properties_remove(
	_Context,
	 pIdentity,
	 pPosition,
	 ptly,
	 ptlz,
	 pDimensions,
	 pbry,
	 pbrz,
	 pClass,
	 pAuto2727,
	 pAuto2728,
	 pImageFormat,
	 pBack,
	 pFront,
	 pLeft,
	 pRight,
	 pUpper,
	 pLower,
	 pLight,
	 pDark);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcube_c */
