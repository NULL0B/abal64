
#ifndef _vcube_c
#define _vcube_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vcube.xml                                                */
/* Target         : vcube.c                                                  */
/* Identification : 0.0-1334659659-14025.1163                                */
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
#define en_Auto3544   "Cube Face Colours"
#define fr_Auto3544   "Couleurs des faces du cube"
#define it_Auto3544   "Cube Face Colours"
#define es_Auto3544   "Cube Face Colours"
#define de_Auto3544   "Cube Face Colours"
#define nl_Auto3544   "Cube Face Colours"
#define pt_Auto3544   "Cube Face Colours"
#define xx_Auto3544   "Cube Face Colours"
#define en__Auto3544   ""
#define fr__Auto3544   ""
#define it__Auto3544   ""
#define es__Auto3544   ""
#define de__Auto3544   ""
#define nl__Auto3544   ""
#define pt__Auto3544   ""
#define xx__Auto3544   ""
#define en_Auto3545   "Back"
#define fr_Auto3545   "ArriŠre"
#define it_Auto3545   "Back"
#define es_Auto3545   "Back"
#define de_Auto3545   "Zurck"
#define nl_Auto3545   "Back"
#define pt_Auto3545   "Back"
#define xx_Auto3545   "Back"
#define en__Auto3545   ""
#define fr__Auto3545   ""
#define it__Auto3545   ""
#define es__Auto3545   ""
#define de__Auto3545   ""
#define nl__Auto3545   ""
#define pt__Auto3545   ""
#define xx__Auto3545   ""
#define en_Auto3546   "Front"
#define fr_Auto3546   "Avant"
#define it_Auto3546   "Front"
#define es_Auto3546   "Front"
#define de_Auto3546   "Front"
#define nl_Auto3546   "Front"
#define pt_Auto3546   "Front"
#define xx_Auto3546   "Front"
#define en__Auto3546   ""
#define fr__Auto3546   ""
#define it__Auto3546   ""
#define es__Auto3546   ""
#define de__Auto3546   ""
#define nl__Auto3546   ""
#define pt__Auto3546   ""
#define xx__Auto3546   ""
#define en_Auto3547   "Left"
#define fr_Auto3547   "Gauche"
#define it_Auto3547   "Left"
#define es_Auto3547   "Left"
#define de_Auto3547   "Links"
#define nl_Auto3547   "Left"
#define pt_Auto3547   "Left"
#define xx_Auto3547   "Left"
#define en__Auto3547   ""
#define fr__Auto3547   ""
#define it__Auto3547   ""
#define es__Auto3547   ""
#define de__Auto3547   ""
#define nl__Auto3547   ""
#define pt__Auto3547   ""
#define xx__Auto3547   ""
#define en_Auto3548   "Right"
#define fr_Auto3548   "Droite"
#define it_Auto3548   "Right"
#define es_Auto3548   "Right"
#define de_Auto3548   "Rechts"
#define nl_Auto3548   "Right"
#define pt_Auto3548   "Right"
#define xx_Auto3548   "Right"
#define en__Auto3548   ""
#define fr__Auto3548   ""
#define it__Auto3548   ""
#define es__Auto3548   ""
#define de__Auto3548   ""
#define nl__Auto3548   ""
#define pt__Auto3548   ""
#define xx__Auto3548   ""
#define en_Auto3549   "Upper"
#define fr_Auto3549   "Haute"
#define it_Auto3549   "Upper"
#define es_Auto3549   "Upper"
#define de_Auto3549   "Uber"
#define nl_Auto3549   "Upper"
#define pt_Auto3549   "Upper"
#define xx_Auto3549   "Upper"
#define en__Auto3549   ""
#define fr__Auto3549   ""
#define it__Auto3549   ""
#define es__Auto3549   ""
#define de__Auto3549   ""
#define nl__Auto3549   ""
#define pt__Auto3549   ""
#define xx__Auto3549   ""
#define en_Auto3550   "Lower"
#define fr_Auto3550   "Basse"
#define it_Auto3550   "Lower"
#define es_Auto3550   "Lower"
#define de_Auto3550   "Hinten"
#define nl_Auto3550   "Lower"
#define pt_Auto3550   "Lower"
#define xx_Auto3550   "Lower"
#define en__Auto3550   ""
#define fr__Auto3550   ""
#define it__Auto3550   ""
#define es__Auto3550   ""
#define de__Auto3550   ""
#define nl__Auto3550   ""
#define pt__Auto3550   ""
#define xx__Auto3550   ""
#define en_Auto3551   "Light"
#define fr_Auto3551   "Clair"
#define it_Auto3551   "Light"
#define es_Auto3551   "Light"
#define de_Auto3551   "Light"
#define nl_Auto3551   "Light"
#define pt_Auto3551   "Light"
#define xx_Auto3551   "Light"
#define en__Auto3551   ""
#define fr__Auto3551   ""
#define it__Auto3551   ""
#define es__Auto3551   ""
#define de__Auto3551   ""
#define nl__Auto3551   ""
#define pt__Auto3551   ""
#define xx__Auto3551   ""
#define en_Auto3552   "Dark"
#define fr_Auto3552   "Sombre"
#define it_Auto3552   "Dark"
#define es_Auto3552   "Dark"
#define de_Auto3552   "Dark"
#define nl_Auto3552   "Dark"
#define pt_Auto3552   "Dark"
#define xx_Auto3552   "Dark"
#define en__Auto3552   ""
#define fr__Auto3552   ""
#define it__Auto3552   ""
#define es__Auto3552   ""
#define de__Auto3552   ""
#define nl__Auto3552   ""
#define pt__Auto3552   ""
#define xx__Auto3552   ""
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
#define en_Auto3553   "Cube definition"
#define fr_Auto3553   "D‚finition du Cube"
#define it_Auto3553   "Cube definition"
#define es_Auto3553   "Cube definition"
#define de_Auto3553   "Cube definition"
#define nl_Auto3553   "Cube definition"
#define pt_Auto3553   "Cube definition"
#define xx_Auto3553   "Cube definition"
#define en__Auto3553   ""
#define fr__Auto3553   ""
#define it__Auto3553   ""
#define es__Auto3553   ""
#define de__Auto3553   ""
#define nl__Auto3553   ""
#define pt__Auto3553   ""
#define xx__Auto3553   ""
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
#define en_Auto3554   "ok.gif"
#define fr_Auto3554   "ok.gif"
#define it_Auto3554   "ok.gif"
#define es_Auto3554   "ok.gif"
#define de_Auto3554   "ok.gif"
#define nl_Auto3554   "ok.gif"
#define pt_Auto3554   "ok.gif"
#define xx_Auto3554   "ok.gif"
#define en_Auto3555   "cancel.gif"
#define fr_Auto3555   "cancel.gif"
#define it_Auto3555   "cancel.gif"
#define es_Auto3555   "cancel.gif"
#define de_Auto3555   "cancel.gif"
#define nl_Auto3555   "cancel.gif"
#define pt_Auto3555   "cancel.gif"
#define xx_Auto3555   "cancel.gif"
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
#define en_Auto3556   "Au&toSize"
#define fr_Auto3556   "Dimension Auto"
#define it_Auto3556   "Au&toSize"
#define es_Auto3556   "Au&toSize"
#define de_Auto3556   "Au&toSize"
#define nl_Auto3556   "Au&toSize"
#define pt_Auto3556   "Au&toSize"
#define xx_Auto3556   "Au&toSize"
#define en__Auto3556   ""
#define fr__Auto3556   ""
#define it__Auto3556   ""
#define es__Auto3556   ""
#define de__Auto3556   ""
#define nl__Auto3556   ""
#define pt__Auto3556   ""
#define xx__Auto3556   ""
#define en_Auto3557   "&Locked"
#define fr_Auto3557   "&Verrouill‚"
#define it_Auto3557   "&Locked"
#define es_Auto3557   "&Locked"
#define de_Auto3557   "&Locked"
#define nl_Auto3557   "&Locked"
#define pt_Auto3557   "&Locked"
#define xx_Auto3557   "&Locked"
#define en__Auto3557   ""
#define fr__Auto3557   ""
#define it__Auto3557   ""
#define es__Auto3557   ""
#define de__Auto3557   ""
#define nl__Auto3557   ""
#define pt__Auto3557   ""
#define xx__Auto3557   ""
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
	char * msg_Auto3544[8];
	char * hint_Auto3544[8];
	char * msg_Auto3545[8];
	char * hint_Auto3545[8];
	char * msg_Auto3546[8];
	char * hint_Auto3546[8];
	char * msg_Auto3547[8];
	char * hint_Auto3547[8];
	char * msg_Auto3548[8];
	char * hint_Auto3548[8];
	char * msg_Auto3549[8];
	char * hint_Auto3549[8];
	char * msg_Auto3550[8];
	char * hint_Auto3550[8];
	char * msg_Auto3551[8];
	char * hint_Auto3551[8];
	char * msg_Auto3552[8];
	char * hint_Auto3552[8];
	char * msg_auto2[8];
	char * hint_auto2[8];
	char * msg_Auto3553[8];
	char * hint_Auto3553[8];
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
	char * msg_Auto3554[8];
	int	trigger_Auto3554;
	char * hint_Auto3554[8];
	char * msg_Auto3555[8];
	int	trigger_Auto3555;
	char * hint_Auto3555[8];
	char * msg_Select[8];
	int	trigger_Select;
	char * hint_Select[8];
	char * msg_auto197[8];
	char * hint_auto197[8];
	char * hint_Class[8];
	char	buffer_Class[256];
	char * msg_Auto3556[8];
	int	trigger_Auto3556;
	char * hint_Auto3556[8];
	int	value_Auto3556;
	char * msg_Auto3557[8];
	int	trigger_Auto3557;
	char * hint_Auto3557[8];
	int	value_Auto3557;
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
private int on_Auto3554_event(struct accept_cube_properties_context * _Context);
private int on_Auto3555_event(struct accept_cube_properties_context * _Context);
private int on_Select_event(struct accept_cube_properties_context * _Context);

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
	char * pAuto3556,
	char * pAuto3557,
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
	vfh[10] = visual_font("bmap0414.fmf",12);
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
		visual_transferin((void *) 0, 0, pAuto3556);
		if (!( pAuto3556 )) _Context->value_Auto3556=0;
		else	_Context->value_Auto3556 = *((int *)pAuto3556);
		visual_transferin((void *) 0, 0, pAuto3557);
		if (!( pAuto3557 )) _Context->value_Auto3557=0;
		else	_Context->value_Auto3557 = *((int *)pAuto3557);
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
	for (i=0; i < 8; i++)_Context->msg_Auto3544[i]=" ";
	_Context->msg_Auto3544[0]=en_Auto3544;
	_Context->msg_Auto3544[1]=fr_Auto3544;
	_Context->msg_Auto3544[2]=it_Auto3544;
	_Context->msg_Auto3544[3]=es_Auto3544;
	_Context->msg_Auto3544[4]=de_Auto3544;
	_Context->msg_Auto3544[5]=nl_Auto3544;
	_Context->msg_Auto3544[6]=pt_Auto3544;
	_Context->msg_Auto3544[7]=xx_Auto3544;
	_Context->hint_Auto3544[0]=en__Auto3544;
	_Context->hint_Auto3544[1]=fr__Auto3544;
	_Context->hint_Auto3544[2]=it__Auto3544;
	_Context->hint_Auto3544[3]=es__Auto3544;
	_Context->hint_Auto3544[4]=de__Auto3544;
	_Context->hint_Auto3544[5]=nl__Auto3544;
	_Context->hint_Auto3544[6]=pt__Auto3544;
	_Context->hint_Auto3544[7]=xx__Auto3544;
	for (i=0; i < 8; i++)_Context->msg_Auto3545[i]=" ";
	_Context->msg_Auto3545[0]=en_Auto3545;
	_Context->msg_Auto3545[1]=fr_Auto3545;
	_Context->msg_Auto3545[2]=it_Auto3545;
	_Context->msg_Auto3545[3]=es_Auto3545;
	_Context->msg_Auto3545[4]=de_Auto3545;
	_Context->msg_Auto3545[5]=nl_Auto3545;
	_Context->msg_Auto3545[6]=pt_Auto3545;
	_Context->msg_Auto3545[7]=xx_Auto3545;
	_Context->hint_Auto3545[0]=en__Auto3545;
	_Context->hint_Auto3545[1]=fr__Auto3545;
	_Context->hint_Auto3545[2]=it__Auto3545;
	_Context->hint_Auto3545[3]=es__Auto3545;
	_Context->hint_Auto3545[4]=de__Auto3545;
	_Context->hint_Auto3545[5]=nl__Auto3545;
	_Context->hint_Auto3545[6]=pt__Auto3545;
	_Context->hint_Auto3545[7]=xx__Auto3545;
	for (i=0; i < 8; i++)_Context->msg_Auto3546[i]=" ";
	_Context->msg_Auto3546[0]=en_Auto3546;
	_Context->msg_Auto3546[1]=fr_Auto3546;
	_Context->msg_Auto3546[2]=it_Auto3546;
	_Context->msg_Auto3546[3]=es_Auto3546;
	_Context->msg_Auto3546[4]=de_Auto3546;
	_Context->msg_Auto3546[5]=nl_Auto3546;
	_Context->msg_Auto3546[6]=pt_Auto3546;
	_Context->msg_Auto3546[7]=xx_Auto3546;
	_Context->hint_Auto3546[0]=en__Auto3546;
	_Context->hint_Auto3546[1]=fr__Auto3546;
	_Context->hint_Auto3546[2]=it__Auto3546;
	_Context->hint_Auto3546[3]=es__Auto3546;
	_Context->hint_Auto3546[4]=de__Auto3546;
	_Context->hint_Auto3546[5]=nl__Auto3546;
	_Context->hint_Auto3546[6]=pt__Auto3546;
	_Context->hint_Auto3546[7]=xx__Auto3546;
	for (i=0; i < 8; i++)_Context->msg_Auto3547[i]=" ";
	_Context->msg_Auto3547[0]=en_Auto3547;
	_Context->msg_Auto3547[1]=fr_Auto3547;
	_Context->msg_Auto3547[2]=it_Auto3547;
	_Context->msg_Auto3547[3]=es_Auto3547;
	_Context->msg_Auto3547[4]=de_Auto3547;
	_Context->msg_Auto3547[5]=nl_Auto3547;
	_Context->msg_Auto3547[6]=pt_Auto3547;
	_Context->msg_Auto3547[7]=xx_Auto3547;
	_Context->hint_Auto3547[0]=en__Auto3547;
	_Context->hint_Auto3547[1]=fr__Auto3547;
	_Context->hint_Auto3547[2]=it__Auto3547;
	_Context->hint_Auto3547[3]=es__Auto3547;
	_Context->hint_Auto3547[4]=de__Auto3547;
	_Context->hint_Auto3547[5]=nl__Auto3547;
	_Context->hint_Auto3547[6]=pt__Auto3547;
	_Context->hint_Auto3547[7]=xx__Auto3547;
	for (i=0; i < 8; i++)_Context->msg_Auto3548[i]=" ";
	_Context->msg_Auto3548[0]=en_Auto3548;
	_Context->msg_Auto3548[1]=fr_Auto3548;
	_Context->msg_Auto3548[2]=it_Auto3548;
	_Context->msg_Auto3548[3]=es_Auto3548;
	_Context->msg_Auto3548[4]=de_Auto3548;
	_Context->msg_Auto3548[5]=nl_Auto3548;
	_Context->msg_Auto3548[6]=pt_Auto3548;
	_Context->msg_Auto3548[7]=xx_Auto3548;
	_Context->hint_Auto3548[0]=en__Auto3548;
	_Context->hint_Auto3548[1]=fr__Auto3548;
	_Context->hint_Auto3548[2]=it__Auto3548;
	_Context->hint_Auto3548[3]=es__Auto3548;
	_Context->hint_Auto3548[4]=de__Auto3548;
	_Context->hint_Auto3548[5]=nl__Auto3548;
	_Context->hint_Auto3548[6]=pt__Auto3548;
	_Context->hint_Auto3548[7]=xx__Auto3548;
	for (i=0; i < 8; i++)_Context->msg_Auto3549[i]=" ";
	_Context->msg_Auto3549[0]=en_Auto3549;
	_Context->msg_Auto3549[1]=fr_Auto3549;
	_Context->msg_Auto3549[2]=it_Auto3549;
	_Context->msg_Auto3549[3]=es_Auto3549;
	_Context->msg_Auto3549[4]=de_Auto3549;
	_Context->msg_Auto3549[5]=nl_Auto3549;
	_Context->msg_Auto3549[6]=pt_Auto3549;
	_Context->msg_Auto3549[7]=xx_Auto3549;
	_Context->hint_Auto3549[0]=en__Auto3549;
	_Context->hint_Auto3549[1]=fr__Auto3549;
	_Context->hint_Auto3549[2]=it__Auto3549;
	_Context->hint_Auto3549[3]=es__Auto3549;
	_Context->hint_Auto3549[4]=de__Auto3549;
	_Context->hint_Auto3549[5]=nl__Auto3549;
	_Context->hint_Auto3549[6]=pt__Auto3549;
	_Context->hint_Auto3549[7]=xx__Auto3549;
	for (i=0; i < 8; i++)_Context->msg_Auto3550[i]=" ";
	_Context->msg_Auto3550[0]=en_Auto3550;
	_Context->msg_Auto3550[1]=fr_Auto3550;
	_Context->msg_Auto3550[2]=it_Auto3550;
	_Context->msg_Auto3550[3]=es_Auto3550;
	_Context->msg_Auto3550[4]=de_Auto3550;
	_Context->msg_Auto3550[5]=nl_Auto3550;
	_Context->msg_Auto3550[6]=pt_Auto3550;
	_Context->msg_Auto3550[7]=xx_Auto3550;
	_Context->hint_Auto3550[0]=en__Auto3550;
	_Context->hint_Auto3550[1]=fr__Auto3550;
	_Context->hint_Auto3550[2]=it__Auto3550;
	_Context->hint_Auto3550[3]=es__Auto3550;
	_Context->hint_Auto3550[4]=de__Auto3550;
	_Context->hint_Auto3550[5]=nl__Auto3550;
	_Context->hint_Auto3550[6]=pt__Auto3550;
	_Context->hint_Auto3550[7]=xx__Auto3550;
	for (i=0; i < 8; i++)_Context->msg_Auto3551[i]=" ";
	_Context->msg_Auto3551[0]=en_Auto3551;
	_Context->msg_Auto3551[1]=fr_Auto3551;
	_Context->msg_Auto3551[2]=it_Auto3551;
	_Context->msg_Auto3551[3]=es_Auto3551;
	_Context->msg_Auto3551[4]=de_Auto3551;
	_Context->msg_Auto3551[5]=nl_Auto3551;
	_Context->msg_Auto3551[6]=pt_Auto3551;
	_Context->msg_Auto3551[7]=xx_Auto3551;
	_Context->hint_Auto3551[0]=en__Auto3551;
	_Context->hint_Auto3551[1]=fr__Auto3551;
	_Context->hint_Auto3551[2]=it__Auto3551;
	_Context->hint_Auto3551[3]=es__Auto3551;
	_Context->hint_Auto3551[4]=de__Auto3551;
	_Context->hint_Auto3551[5]=nl__Auto3551;
	_Context->hint_Auto3551[6]=pt__Auto3551;
	_Context->hint_Auto3551[7]=xx__Auto3551;
	for (i=0; i < 8; i++)_Context->msg_Auto3552[i]=" ";
	_Context->msg_Auto3552[0]=en_Auto3552;
	_Context->msg_Auto3552[1]=fr_Auto3552;
	_Context->msg_Auto3552[2]=it_Auto3552;
	_Context->msg_Auto3552[3]=es_Auto3552;
	_Context->msg_Auto3552[4]=de_Auto3552;
	_Context->msg_Auto3552[5]=nl_Auto3552;
	_Context->msg_Auto3552[6]=pt_Auto3552;
	_Context->msg_Auto3552[7]=xx_Auto3552;
	_Context->hint_Auto3552[0]=en__Auto3552;
	_Context->hint_Auto3552[1]=fr__Auto3552;
	_Context->hint_Auto3552[2]=it__Auto3552;
	_Context->hint_Auto3552[3]=es__Auto3552;
	_Context->hint_Auto3552[4]=de__Auto3552;
	_Context->hint_Auto3552[5]=nl__Auto3552;
	_Context->hint_Auto3552[6]=pt__Auto3552;
	_Context->hint_Auto3552[7]=xx__Auto3552;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3553[i]=" ";
	_Context->msg_Auto3553[0]=en_Auto3553;
	_Context->msg_Auto3553[1]=fr_Auto3553;
	_Context->msg_Auto3553[2]=it_Auto3553;
	_Context->msg_Auto3553[3]=es_Auto3553;
	_Context->msg_Auto3553[4]=de_Auto3553;
	_Context->msg_Auto3553[5]=nl_Auto3553;
	_Context->msg_Auto3553[6]=pt_Auto3553;
	_Context->msg_Auto3553[7]=xx_Auto3553;
	_Context->hint_Auto3553[0]=en__Auto3553;
	_Context->hint_Auto3553[1]=fr__Auto3553;
	_Context->hint_Auto3553[2]=it__Auto3553;
	_Context->hint_Auto3553[3]=es__Auto3553;
	_Context->hint_Auto3553[4]=de__Auto3553;
	_Context->hint_Auto3553[5]=nl__Auto3553;
	_Context->hint_Auto3553[6]=pt__Auto3553;
	_Context->hint_Auto3553[7]=xx__Auto3553;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3554[i]=" ";
	_Context->msg_Auto3554[0]=en_Auto3554;
	_Context->msg_Auto3554[1]=fr_Auto3554;
	_Context->msg_Auto3554[2]=it_Auto3554;
	_Context->msg_Auto3554[3]=es_Auto3554;
	_Context->msg_Auto3554[4]=de_Auto3554;
	_Context->msg_Auto3554[5]=nl_Auto3554;
	_Context->msg_Auto3554[6]=pt_Auto3554;
	_Context->msg_Auto3554[7]=xx_Auto3554;
	for (i=0; i < 8; i++)_Context->msg_Auto3555[i]=" ";
	_Context->msg_Auto3555[0]=en_Auto3555;
	_Context->msg_Auto3555[1]=fr_Auto3555;
	_Context->msg_Auto3555[2]=it_Auto3555;
	_Context->msg_Auto3555[3]=es_Auto3555;
	_Context->msg_Auto3555[4]=de_Auto3555;
	_Context->msg_Auto3555[5]=nl_Auto3555;
	_Context->msg_Auto3555[6]=pt_Auto3555;
	_Context->msg_Auto3555[7]=xx_Auto3555;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3556[i]=" ";
	_Context->msg_Auto3556[0]=en_Auto3556;
	_Context->msg_Auto3556[1]=fr_Auto3556;
	_Context->msg_Auto3556[2]=it_Auto3556;
	_Context->msg_Auto3556[3]=es_Auto3556;
	_Context->msg_Auto3556[4]=de_Auto3556;
	_Context->msg_Auto3556[5]=nl_Auto3556;
	_Context->msg_Auto3556[6]=pt_Auto3556;
	_Context->msg_Auto3556[7]=xx_Auto3556;
	_Context->hint_Auto3556[0]=en__Auto3556;
	_Context->hint_Auto3556[1]=fr__Auto3556;
	_Context->hint_Auto3556[2]=it__Auto3556;
	_Context->hint_Auto3556[3]=es__Auto3556;
	_Context->hint_Auto3556[4]=de__Auto3556;
	_Context->hint_Auto3556[5]=nl__Auto3556;
	_Context->hint_Auto3556[6]=pt__Auto3556;
	_Context->hint_Auto3556[7]=xx__Auto3556;
	for (i=0; i < 8; i++)_Context->msg_Auto3557[i]=" ";
	_Context->msg_Auto3557[0]=en_Auto3557;
	_Context->msg_Auto3557[1]=fr_Auto3557;
	_Context->msg_Auto3557[2]=it_Auto3557;
	_Context->msg_Auto3557[3]=es_Auto3557;
	_Context->msg_Auto3557[4]=de_Auto3557;
	_Context->msg_Auto3557[5]=nl_Auto3557;
	_Context->msg_Auto3557[6]=pt_Auto3557;
	_Context->msg_Auto3557[7]=xx_Auto3557;
	_Context->hint_Auto3557[0]=en__Auto3557;
	_Context->hint_Auto3557[1]=fr__Auto3557;
	_Context->hint_Auto3557[2]=it__Auto3557;
	_Context->hint_Auto3557[3]=es__Auto3557;
	_Context->hint_Auto3557[4]=de__Auto3557;
	_Context->hint_Auto3557[5]=nl__Auto3557;
	_Context->hint_Auto3557[6]=pt__Auto3557;
	_Context->hint_Auto3557[7]=xx__Auto3557;
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
	char * pAuto3556,
	char * pAuto3557,
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
		visual_transferout((void *) 0, 0, pAuto3556);
		if ( pAuto3556 != (char *) 0)
			*((int*)pAuto3556) = _Context->value_Auto3556;
		visual_transferout((void *) 0, 0, pAuto3557);
		if ( pAuto3557 != (char *) 0)
			*((int*)pAuto3557) = _Context->value_Auto3557;
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
	visual_text(_Context->x_auto1+20,_Context->y_auto1+190,570,16,vfh[2],0,0,_Context->msg_Auto3544[_Context->language],strlen(_Context->msg_Auto3544[_Context->language]),258);
	visual_frame(_Context->x_auto1+20,_Context->y_auto1+206,570,44,3);
	visual_text(_Context->x_auto1+90,_Context->y_auto1+210,70,16,vfh[2],16,0,_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]),259);
	visual_text(_Context->x_auto1+90,_Context->y_auto1+230,70,16,vfh[2],16,0,_Context->msg_Auto3546[_Context->language],strlen(_Context->msg_Auto3546[_Context->language]),259);
	visual_text(_Context->x_auto1+220,_Context->y_auto1+210,56,16,vfh[2],16,0,_Context->msg_Auto3547[_Context->language],strlen(_Context->msg_Auto3547[_Context->language]),259);
	visual_text(_Context->x_auto1+220,_Context->y_auto1+230,56,16,vfh[2],16,0,_Context->msg_Auto3548[_Context->language],strlen(_Context->msg_Auto3548[_Context->language]),259);
	visual_text(_Context->x_auto1+340,_Context->y_auto1+210,56,16,vfh[2],16,0,_Context->msg_Auto3549[_Context->language],strlen(_Context->msg_Auto3549[_Context->language]),259);
	visual_text(_Context->x_auto1+340,_Context->y_auto1+230,56,16,vfh[2],16,0,_Context->msg_Auto3550[_Context->language],strlen(_Context->msg_Auto3550[_Context->language]),259);
	visual_text(_Context->x_auto1+460,_Context->y_auto1+210,56,16,vfh[2],16,0,_Context->msg_Auto3551[_Context->language],strlen(_Context->msg_Auto3551[_Context->language]),259);
	visual_text(_Context->x_auto1+460,_Context->y_auto1+230,56,16,vfh[2],16,0,_Context->msg_Auto3552[_Context->language],strlen(_Context->msg_Auto3552[_Context->language]),259);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+30,575,20,vfh[3],16,0,_Context->msg_auto2[_Context->language],strlen(_Context->msg_auto2[_Context->language]),1282);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+110,570,16,vfh[2],0,0,_Context->msg_Auto3553[_Context->language],strlen(_Context->msg_Auto3553[_Context->language]),258);
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
	_Context->trigger_Auto3554=visual_trigger_code(_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]));
	visual_button(_Context->x_auto1+20,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]),1040);
	_Context->trigger_Auto3555=visual_trigger_code(_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]));
	visual_button(_Context->x_auto1+530,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]),1040);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto1+230,_Context->y_auto1+270,140,32,vfh[2],27,28,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+80,100,20,vfh[2],16,0,_Context->msg_auto197[_Context->language],strlen(_Context->msg_auto197[_Context->language]),258);
	visual_frame(_Context->x_auto1+130,_Context->y_auto1+80,456+2,16+2,5);
	visual_text(_Context->x_auto1+130+1,_Context->y_auto1+80+1,456,16,vfh[1],26,0,_Context->buffer_Class,255,2);
	_Context->trigger_Auto3556=visual_trigger_code(_Context->msg_Auto3556[_Context->language],strlen(_Context->msg_Auto3556[_Context->language]));
	visual_check(_Context->x_auto1+370,_Context->y_auto1+130,112,16,vfh[2],26,0,_Context->msg_Auto3556[_Context->language],strlen(_Context->msg_Auto3556[_Context->language]),_Context->value_Auto3556|0);
	_Context->trigger_Auto3557=visual_trigger_code(_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]));
	visual_check(_Context->x_auto1+480,_Context->y_auto1+130,112,16,vfh[2],26,0,_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]),_Context->value_Auto3557|0);
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

private int Auto3554_help()
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

private int Auto3555_help()
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

private int Auto3556_help()
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

private int Auto3557_help()
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
private int on_Auto3554_event(struct accept_cube_properties_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto3555_event(struct accept_cube_properties_context * _Context) {
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
		if (_Context->trigger_Auto3554 == mb ) return(9);
		if (_Context->trigger_Auto3555 == mb ) return(10);
		if (_Context->trigger_Select == mb ) return(11);
		if (_Context->trigger_Auto3556 == mb ) return(12);
		if (_Context->trigger_Auto3557 == mb ) return(13);
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
		return(9); /* Auto3554 */
		}
	if (( mx >= (_Context->x_auto1+530) ) 
	&&  ( my >= (_Context->y_auto1+260) ) 
	&&  ( mx <= (_Context->x_auto1+530+56) ) 
	&&  ( my <= (_Context->y_auto1+260+48))) {
		return(10); /* Auto3555 */
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
		return(12); /* Auto3556 */
		}
	if (( mx >= (_Context->x_auto1+480) ) 
	&&  ( my >= (_Context->y_auto1+130) ) 
	&&  ( mx <= (_Context->x_auto1+480+112) ) 
	&&  ( my <= (_Context->y_auto1+130+16))) {
		return(13); /* Auto3557 */
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
				/* Auto3554 */
				_Context->trigger_Auto3554=visual_trigger_code(_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]));
				visual_button(_Context->x_auto1+20,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3554=visual_trigger_code(_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]));
	visual_button(_Context->x_auto1+20,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]),1040);
				break;
			case	0xa :
				/* Auto3555 */
				_Context->trigger_Auto3555=visual_trigger_code(_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]));
				visual_button(_Context->x_auto1+530,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3555=visual_trigger_code(_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]));
	visual_button(_Context->x_auto1+530,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]),1040);
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
				/* Auto3556 */
				visual_check(_Context->x_auto1+370,_Context->y_auto1+130,112,16,vfh[2],26,0,_Context->msg_Auto3556[_Context->language],strlen(_Context->msg_Auto3556[_Context->language]),(_Context->value_Auto3556 |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3556=visual_trigger_code(_Context->msg_Auto3556[_Context->language],strlen(_Context->msg_Auto3556[_Context->language]));
	visual_check(_Context->x_auto1+370,_Context->y_auto1+130,112,16,vfh[2],26,0,_Context->msg_Auto3556[_Context->language],strlen(_Context->msg_Auto3556[_Context->language]),_Context->value_Auto3556|0);
				break;
			case	0xd :
				/* Auto3557 */
				visual_check(_Context->x_auto1+480,_Context->y_auto1+130,112,16,vfh[2],26,0,_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]),(_Context->value_Auto3557 |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3557=visual_trigger_code(_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]));
	visual_check(_Context->x_auto1+480,_Context->y_auto1+130,112,16,vfh[2],26,0,_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]),_Context->value_Auto3557|0);
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
						if (Auto3554_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (Auto3555_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Select_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (Auto3556_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (Auto3557_help(_Context) != 0) { continue; }
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
					/* Auto3554 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3554=visual_trigger_code(_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]));
						visual_button(_Context->x_auto1+20,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3554=visual_trigger_code(_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]));
	visual_button(_Context->x_auto1+20,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3554_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* Auto3555 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3555=visual_trigger_code(_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]));
						visual_button(_Context->x_auto1+530,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3555=visual_trigger_code(_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]));
	visual_button(_Context->x_auto1+530,_Context->y_auto1+260,56,48,vfh[2],34,0,_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3555_event(_Context)) != -1) break;

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
					/* Auto3556 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Auto3556 += 1;
						_Context->value_Auto3556 &= 1;
						}
					continue;
				case	0xd :
					/* Auto3557 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Auto3557 += 1;
						_Context->value_Auto3557 &= 1;
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
	char * pAuto3556,
	char * pAuto3557,
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
	 pAuto3556,
	 pAuto3557,
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
	 pAuto3556,
	 pAuto3557,
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
