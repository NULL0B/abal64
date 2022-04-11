
#ifndef _vcube_c
#define _vcube_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vcube.xml  */
/* Target         : vcube.c  */
/* Identification : 0.0-1100085255-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_auto1   "Sing : Version 1.0a"
#define fr_auto1   "Sing : Version 1.0a"
#define it_auto1   "Sing : Version 1.0a"
#define es_auto1   "Sing : Version 1.0a"
#define de_auto1   "Sing : Version 1.0a"
#define nl_auto1   "Sing : Version 1.0a"
#define pt_auto1   "Sing : Version 1.0a"
#define xx_auto1   "Sing : Version 1.0a"
#define en_Auto714   "skin.gif"
#define fr_Auto714   "skin.gif"
#define en_Auto7650   "Cube Face Colours"
#define fr_Auto7650   "Couleurs des faces du Cube"
#define en_Auto7654   "Back"
#define fr_Auto7654   "Arriere"
#define en_Auto7655   "Front"
#define fr_Auto7655   "Avant"
#define en_Auto7656   "Left"
#define fr_Auto7656   "Gauche"
#define en_Auto7657   "Right"
#define fr_Auto7657   "Droite"
#define en_Auto7669   "Upper"
#define fr_Auto7669   "Haut"
#define en_Auto7671   "Lower"
#define fr_Auto7671   "Bas"
#define en_Auto7658   "Light"
#define fr_Auto7658   "Clair"
#define en_Auto7661   "Dark"
#define fr_Auto7661   "Sombre"
#define en_auto2   "3d Object Properties"
#define fr_auto2   "Propert‚s de l'objet 3d"
#define it_auto2   "3d Object Properties"
#define es_auto2   "3d Object Properties"
#define de_auto2   "3d Object Properties"
#define nl_auto2   "3d Object Properties"
#define pt_auto2   "3d Object Properties"
#define xx_auto2   "3d Object Properties"
#define en_Auto7605   "Cube definition"
#define fr_Auto7605   "D‚finition du Cube"
#define en_auto5   "Identity"
#define fr_auto5   "Identit‚"
#define xx_auto5   "Ainm"
#define en_auto6   "Position"
#define fr_auto6   "Position"
#define xx_auto6   "Aite"
#define en_auto7   "Dimensions"
#define fr_auto7   "Dimensions"
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
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define it_Accept   "&Accept"
#define es_Accept   "&Accept"
#define de_Accept   "&Accept"
#define nl_Accept   "&Accept"
#define pt_Accept   "&Accept"
#define xx_Accept   "&Accept"
#define en_Select   "&Select"
#define fr_Select   "&Choisir"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
#define en_auto197   "Class"
#define fr_auto197   "Class"
#define xx_auto197   "Clais"
#define en_AutoSize   "Au&toSize"
#define fr_AutoSize   "Dimension Auto"
#define it_AutoSize   "Au&toSize"
#define es_AutoSize   "Au&toSize"
#define de_AutoSize   "Au&toSize"
#define nl_AutoSize   "Au&toSize"
#define pt_AutoSize   "Au&toSize"
#define xx_AutoSize   "Au&toSize"
#define fr_ImageFormat   "Bmp|Gif|Jpeg"
#define it_ImageFormat   "Bmp|Gif|Jpeg"
#define es_ImageFormat   "Bmp|Gif|Jpeg"
#define de_ImageFormat   "Bmp|Gif|Jpeg"
#define nl_ImageFormat   "Bmp|Gif|Jpeg"
#define pt_ImageFormat   "Bmp|Gif|Jpeg"
#define xx_ImageFormat   "Bmp|Gif|Jpeg"
static int	vfh[10];

private struct accept_cube_properties_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_auto1[8];
	int	x_auto1;
	int	y_auto1;
	int	w_auto1;
	int	h_auto1;
	char * msg_Auto714[8];
	char * msg_Auto7650[8];
	char * msg_Auto7654[8];
	char * msg_Auto7655[8];
	char * msg_Auto7656[8];
	char * msg_Auto7657[8];
	char * msg_Auto7669[8];
	char * msg_Auto7671[8];
	char * msg_Auto7658[8];
	char * msg_Auto7661[8];
	char * msg_auto2[8];
	char * msg_Auto7605[8];
	char * msg_auto5[8];
	char * msg_auto6[8];
	char * msg_auto7[8];
	char	buffer_Identity[58];
	char	buffer_Position[8];
	char	buffer_tly[8];
	char	buffer_tlz[8];
	char	buffer_Dimensions[8];
	char	buffer_bry[8];
	char	buffer_brz[8];
	char * msg_auto17[8];
	char * msg_auto18[8];
	char * msg_auto19[8];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Select[8];
	int	trigger_Select;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * msg_auto197[8];
	char	buffer_Class[58];
	char * msg_AutoSize[8];
	int	trigger_AutoSize;
	int	value_AutoSize;
	char * msg_ImageFormat[8];
	int	value_ImageFormat;
	char	buffer_Back[8];
	char	buffer_Front[8];
	char	buffer_Left[8];
	char	buffer_Right[8];
	char	buffer_Upper[8];
	char	buffer_Lower[8];
	char	buffer_Light[8];
	char	buffer_Dark[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[19];
	};

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
	char * pAutoSize,
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
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_cube_properties_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=21;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWWWWKWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Identity, 57, pIdentity);
		visual_transferin(_Context->buffer_Position, 7, pPosition);
		visual_transferin(_Context->buffer_tly, 7, ptly);
		visual_transferin(_Context->buffer_tlz, 7, ptlz);
		visual_transferin(_Context->buffer_Dimensions, 7, pDimensions);
		visual_transferin(_Context->buffer_bry, 7, pbry);
		visual_transferin(_Context->buffer_brz, 7, pbrz);
		visual_transferin(_Context->buffer_Class, 57, pClass);
		visual_transferin((void *) 0, 0, pAutoSize);
		if (!( pAutoSize )) _Context->value_AutoSize=0;
		else	_Context->value_AutoSize = *((int *)pAutoSize);
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
	_Context->msg_auto1[0]=en_auto1;
	_Context->msg_auto1[1]=fr_auto1;
	_Context->msg_auto1[2]=it_auto1;
	_Context->msg_auto1[3]=es_auto1;
	_Context->msg_auto1[4]=de_auto1;
	_Context->msg_auto1[5]=nl_auto1;
	_Context->msg_auto1[6]=pt_auto1;
	_Context->msg_auto1[7]=xx_auto1;
	_Context->x_auto1=95;
	_Context->y_auto1=150;
	_Context->w_auto1=610;
	_Context->h_auto1=300;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto714[i]=" ";
	_Context->msg_Auto714[0]=en_Auto714;
	_Context->msg_Auto714[1]=fr_Auto714;
	for (i=0; i < 8; i++)_Context->msg_Auto7650[i]=" ";
	_Context->msg_Auto7650[0]=en_Auto7650;
	_Context->msg_Auto7650[1]=fr_Auto7650;
	for (i=0; i < 8; i++)_Context->msg_Auto7654[i]=" ";
	_Context->msg_Auto7654[0]=en_Auto7654;
	_Context->msg_Auto7654[1]=fr_Auto7654;
	for (i=0; i < 8; i++)_Context->msg_Auto7655[i]=" ";
	_Context->msg_Auto7655[0]=en_Auto7655;
	_Context->msg_Auto7655[1]=fr_Auto7655;
	for (i=0; i < 8; i++)_Context->msg_Auto7656[i]=" ";
	_Context->msg_Auto7656[0]=en_Auto7656;
	_Context->msg_Auto7656[1]=fr_Auto7656;
	for (i=0; i < 8; i++)_Context->msg_Auto7657[i]=" ";
	_Context->msg_Auto7657[0]=en_Auto7657;
	_Context->msg_Auto7657[1]=fr_Auto7657;
	for (i=0; i < 8; i++)_Context->msg_Auto7669[i]=" ";
	_Context->msg_Auto7669[0]=en_Auto7669;
	_Context->msg_Auto7669[1]=fr_Auto7669;
	for (i=0; i < 8; i++)_Context->msg_Auto7671[i]=" ";
	_Context->msg_Auto7671[0]=en_Auto7671;
	_Context->msg_Auto7671[1]=fr_Auto7671;
	for (i=0; i < 8; i++)_Context->msg_Auto7658[i]=" ";
	_Context->msg_Auto7658[0]=en_Auto7658;
	_Context->msg_Auto7658[1]=fr_Auto7658;
	for (i=0; i < 8; i++)_Context->msg_Auto7661[i]=" ";
	_Context->msg_Auto7661[0]=en_Auto7661;
	_Context->msg_Auto7661[1]=fr_Auto7661;
	for (i=0; i < 8; i++)_Context->msg_auto2[i]=" ";
	_Context->msg_auto2[0]=en_auto2;
	_Context->msg_auto2[1]=fr_auto2;
	_Context->msg_auto2[2]=it_auto2;
	_Context->msg_auto2[3]=es_auto2;
	_Context->msg_auto2[4]=de_auto2;
	_Context->msg_auto2[5]=nl_auto2;
	_Context->msg_auto2[6]=pt_auto2;
	_Context->msg_auto2[7]=xx_auto2;
	for (i=0; i < 8; i++)_Context->msg_Auto7605[i]=" ";
	_Context->msg_Auto7605[0]=en_Auto7605;
	_Context->msg_Auto7605[1]=fr_Auto7605;
	for (i=0; i < 8; i++)_Context->msg_auto5[i]=" ";
	_Context->msg_auto5[0]=en_auto5;
	_Context->msg_auto5[1]=fr_auto5;
	_Context->msg_auto5[7]=xx_auto5;
	for (i=0; i < 8; i++)_Context->msg_auto6[i]=" ";
	_Context->msg_auto6[0]=en_auto6;
	_Context->msg_auto6[1]=fr_auto6;
	_Context->msg_auto6[7]=xx_auto6;
	for (i=0; i < 8; i++)_Context->msg_auto7[i]=" ";
	_Context->msg_auto7[0]=en_auto7;
	_Context->msg_auto7[1]=fr_auto7;
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
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	for (i=0; i < 8; i++)_Context->msg_auto197[i]=" ";
	_Context->msg_auto197[0]=en_auto197;
	_Context->msg_auto197[1]=fr_auto197;
	_Context->msg_auto197[7]=xx_auto197;
	for (i=0; i < 8; i++)_Context->msg_AutoSize[i]=" ";
	_Context->msg_AutoSize[0]=en_AutoSize;
	_Context->msg_AutoSize[1]=fr_AutoSize;
	_Context->msg_AutoSize[2]=it_AutoSize;
	_Context->msg_AutoSize[3]=es_AutoSize;
	_Context->msg_AutoSize[4]=de_AutoSize;
	_Context->msg_AutoSize[5]=nl_AutoSize;
	_Context->msg_AutoSize[6]=pt_AutoSize;
	_Context->msg_AutoSize[7]=xx_AutoSize;
	for (i=0; i < 8; i++)_Context->msg_ImageFormat[i]=" ";
	_Context->msg_ImageFormat[1]=fr_ImageFormat;
	_Context->msg_ImageFormat[2]=it_ImageFormat;
	_Context->msg_ImageFormat[3]=es_ImageFormat;
	_Context->msg_ImageFormat[4]=de_ImageFormat;
	_Context->msg_ImageFormat[5]=nl_ImageFormat;
	_Context->msg_ImageFormat[6]=pt_ImageFormat;
	_Context->msg_ImageFormat[7]=xx_ImageFormat;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto1,_Context->y_auto1,610+10,300+10);
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
	char * pAutoSize,
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
		strcpy(_Context->signature,"SWWWWWWKWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Identity, 57, pIdentity);
		visual_transferout(_Context->buffer_Position, 7, pPosition);
		visual_transferout(_Context->buffer_tly, 7, ptly);
		visual_transferout(_Context->buffer_tlz, 7, ptlz);
		visual_transferout(_Context->buffer_Dimensions, 7, pDimensions);
		visual_transferout(_Context->buffer_bry, 7, pbry);
		visual_transferout(_Context->buffer_brz, 7, pbrz);
		visual_transferout(_Context->buffer_Class, 57, pClass);
		visual_transferout((void *) 0, 0, pAutoSize);
		if ( pAutoSize != (char *) 0)
			*((int*)pAutoSize) = _Context->value_AutoSize;
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
	visual_window(_Context->x_auto1,_Context->y_auto1,610,300,vfh[2],_Context->msg_auto1[_Context->language],strlen(_Context->msg_auto1[_Context->language]),0x407);
	visual_image(_Context->x_auto1+3,_Context->y_auto1+22,604,274,_Context->msg_Auto714[_Context->language],4);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+190,570,16,vfh[2],0,0,_Context->msg_Auto7650[_Context->language],strlen(_Context->msg_Auto7650[_Context->language]),258);
	visual_frame(_Context->x_auto1+20,_Context->y_auto1+206,570,44,3);
	visual_text(_Context->x_auto1+90,_Context->y_auto1+210,70,16,vfh[2],16,0,_Context->msg_Auto7654[_Context->language],strlen(_Context->msg_Auto7654[_Context->language]),259);
	visual_text(_Context->x_auto1+90,_Context->y_auto1+230,70,16,vfh[2],16,0,_Context->msg_Auto7655[_Context->language],strlen(_Context->msg_Auto7655[_Context->language]),259);
	visual_text(_Context->x_auto1+220,_Context->y_auto1+210,56,16,vfh[2],16,0,_Context->msg_Auto7656[_Context->language],strlen(_Context->msg_Auto7656[_Context->language]),259);
	visual_text(_Context->x_auto1+220,_Context->y_auto1+230,56,16,vfh[2],16,0,_Context->msg_Auto7657[_Context->language],strlen(_Context->msg_Auto7657[_Context->language]),259);
	visual_text(_Context->x_auto1+340,_Context->y_auto1+210,56,16,vfh[2],16,0,_Context->msg_Auto7669[_Context->language],strlen(_Context->msg_Auto7669[_Context->language]),259);
	visual_text(_Context->x_auto1+340,_Context->y_auto1+230,56,16,vfh[2],16,0,_Context->msg_Auto7671[_Context->language],strlen(_Context->msg_Auto7671[_Context->language]),259);
	visual_text(_Context->x_auto1+460,_Context->y_auto1+210,56,16,vfh[2],16,0,_Context->msg_Auto7658[_Context->language],strlen(_Context->msg_Auto7658[_Context->language]),259);
	visual_text(_Context->x_auto1+460,_Context->y_auto1+230,56,16,vfh[2],16,0,_Context->msg_Auto7661[_Context->language],strlen(_Context->msg_Auto7661[_Context->language]),259);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+30,575,20,vfh[3],16,0,_Context->msg_auto2[_Context->language],strlen(_Context->msg_auto2[_Context->language]),1282);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+110,570,16,vfh[2],0,0,_Context->msg_Auto7605[_Context->language],strlen(_Context->msg_Auto7605[_Context->language]),258);
	visual_frame(_Context->x_auto1+20,_Context->y_auto1+126,570,54,3);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+60,100,20,vfh[2],16,0,_Context->msg_auto5[_Context->language],strlen(_Context->msg_auto5[_Context->language]),258);
	visual_text(_Context->x_auto1+30,_Context->y_auto1+130,80,20,vfh[2],16,0,_Context->msg_auto6[_Context->language],strlen(_Context->msg_auto6[_Context->language]),258);
	visual_text(_Context->x_auto1+30,_Context->y_auto1+150,100,20,vfh[2],16,0,_Context->msg_auto7[_Context->language],strlen(_Context->msg_auto7[_Context->language]),258);
	visual_frame(_Context->x_auto1+130,_Context->y_auto1+60,456+2,16+2,5);
	visual_text(_Context->x_auto1+130+1,_Context->y_auto1+60+1,456,16,vfh[1],26,0,_Context->buffer_Identity,57,0);
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
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_auto1+20,_Context->y_auto1+260,120,32,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto1+230,_Context->y_auto1+260,140,32,vfh[2],27,28,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto1+470,_Context->y_auto1+260,120,32,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+80,100,20,vfh[2],16,0,_Context->msg_auto197[_Context->language],strlen(_Context->msg_auto197[_Context->language]),258);
	visual_frame(_Context->x_auto1+130,_Context->y_auto1+80,456+2,16+2,5);
	visual_text(_Context->x_auto1+130+1,_Context->y_auto1+80+1,456,16,vfh[1],26,0,_Context->buffer_Class,57,2);
	_Context->trigger_AutoSize=visual_trigger_code(_Context->msg_AutoSize[_Context->language],strlen(_Context->msg_AutoSize[_Context->language]));
	visual_check(_Context->x_auto1+390,_Context->y_auto1+130,196,16,vfh[2],26,0,_Context->msg_AutoSize[_Context->language],strlen(_Context->msg_AutoSize[_Context->language]),_Context->value_AutoSize|0);
	visual_select(_Context->x_auto1+390,_Context->y_auto1+150,104,96,vfh[1],0,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),0);
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
	visual_thaw(_Context->x_auto1,_Context->y_auto1,610,300);
	visual_thaw(_Context->x_auto1,_Context->y_auto1,610,300);

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

		visual_thaw(_Context->x_auto1,_Context->y_auto1,610,300);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_cube_properties_context * _Context) {
	return(13);
	return(-1);
}
private int on_Select_event(struct accept_cube_properties_context * _Context) {
	int ft=WIDGET_FILE_ANY;
	int i;
	int c;
	for(i=0;i<57;i++)
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
private int on_Cancel_event(struct accept_cube_properties_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_cube_properties_event(
struct accept_cube_properties_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(9);
		if (_Context->trigger_Select == mb ) return(10);
		if (_Context->trigger_Cancel == mb ) return(11);
		if (_Context->trigger_AutoSize == mb ) return(12);
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
	&&  ( mx <= (_Context->x_auto1+20+120) ) 
	&&  ( my <= (_Context->y_auto1+260+32))) {
		return(9); /* Accept */
		}
	if (( mx >= (_Context->x_auto1+230) ) 
	&&  ( my >= (_Context->y_auto1+260) ) 
	&&  ( mx <= (_Context->x_auto1+230+140) ) 
	&&  ( my <= (_Context->y_auto1+260+32))) {
		return(10); /* Select */
		}
	if (( mx >= (_Context->x_auto1+470) ) 
	&&  ( my >= (_Context->y_auto1+260) ) 
	&&  ( mx <= (_Context->x_auto1+470+120) ) 
	&&  ( my <= (_Context->y_auto1+260+32))) {
		return(11); /* Cancel */
		}
	if (( mx >= (_Context->x_auto1+390) ) 
	&&  ( my >= (_Context->y_auto1+130) ) 
	&&  ( mx <= (_Context->x_auto1+390+196) ) 
	&&  ( my <= (_Context->y_auto1+130+16))) {
		return(12); /* AutoSize */
		}
	if (( mx >= (_Context->x_auto1+390+0) ) 
	&&  ( my >= (_Context->y_auto1+150) ) 
	&&  ( mx <= (_Context->x_auto1+390+104) ) 
	&&  ( my <= (_Context->y_auto1+150+16))) {
		return(13); /* ImageFormat */
		}
	if (( mx >= (_Context->x_auto1+160) ) 
	&&  ( my >= (_Context->y_auto1+210) ) 
	&&  ( mx <= (_Context->x_auto1+160+56) ) 
	&&  ( my <= (_Context->y_auto1+210+16))) {
		return(14); /* Back */
		}
	if (( mx >= (_Context->x_auto1+160) ) 
	&&  ( my >= (_Context->y_auto1+230) ) 
	&&  ( mx <= (_Context->x_auto1+160+56) ) 
	&&  ( my <= (_Context->y_auto1+230+16))) {
		return(15); /* Front */
		}
	if (( mx >= (_Context->x_auto1+280) ) 
	&&  ( my >= (_Context->y_auto1+210) ) 
	&&  ( mx <= (_Context->x_auto1+280+56) ) 
	&&  ( my <= (_Context->y_auto1+210+16))) {
		return(16); /* Left */
		}
	if (( mx >= (_Context->x_auto1+280) ) 
	&&  ( my >= (_Context->y_auto1+230) ) 
	&&  ( mx <= (_Context->x_auto1+280+56) ) 
	&&  ( my <= (_Context->y_auto1+230+16))) {
		return(17); /* Right */
		}
	if (( mx >= (_Context->x_auto1+400) ) 
	&&  ( my >= (_Context->y_auto1+210) ) 
	&&  ( mx <= (_Context->x_auto1+400+56) ) 
	&&  ( my <= (_Context->y_auto1+210+16))) {
		return(18); /* Upper */
		}
	if (( mx >= (_Context->x_auto1+400) ) 
	&&  ( my >= (_Context->y_auto1+230) ) 
	&&  ( mx <= (_Context->x_auto1+400+56) ) 
	&&  ( my <= (_Context->y_auto1+230+16))) {
		return(19); /* Lower */
		}
	if (( mx >= (_Context->x_auto1+520) ) 
	&&  ( my >= (_Context->y_auto1+210) ) 
	&&  ( mx <= (_Context->x_auto1+520+56) ) 
	&&  ( my <= (_Context->y_auto1+210+16))) {
		return(20); /* Light */
		}
	if (( mx >= (_Context->x_auto1+520) ) 
	&&  ( my >= (_Context->y_auto1+230) ) 
	&&  ( mx <= (_Context->x_auto1+520+56) ) 
	&&  ( my <= (_Context->y_auto1+230+16))) {
		return(21); /* Dark */
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
				_Context->keycode = visual_edit(_Context->x_auto1+130+1,_Context->y_auto1+60+1,456,16,vfh[1],_Context->buffer_Identity,57);
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
				/* Accept */
				visual_button(_Context->x_auto1+20,_Context->y_auto1+260,120,32,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto1+20,_Context->y_auto1+260,120,32,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0xa :
				/* Select */
				visual_button(_Context->x_auto1+230,_Context->y_auto1+260,140,32,vfh[2],27,28,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto1+230,_Context->y_auto1+260,140,32,vfh[2],27,28,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;
			case	0xb :
				/* Cancel */
				visual_button(_Context->x_auto1+470,_Context->y_auto1+260,120,32,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto1+470,_Context->y_auto1+260,120,32,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0xc :
				/* AutoSize */
				visual_check(_Context->x_auto1+390,_Context->y_auto1+130,196,16,vfh[2],26,0,_Context->msg_AutoSize[_Context->language],strlen(_Context->msg_AutoSize[_Context->language]),(_Context->value_AutoSize |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto1+390,_Context->y_auto1+130,196,16,vfh[2],26,0,_Context->msg_AutoSize[_Context->language],strlen(_Context->msg_AutoSize[_Context->language]),(_Context->value_AutoSize |0));
				break;
			case	0xd :
				/* ImageFormat */
				_Context->keycode = visual_select(_Context->x_auto1+390,_Context->y_auto1+150,104,96,vfh[1],0,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),2);
				break;
			case	0xe :
				/* Back */
				_Context->keycode = visual_edit(_Context->x_auto1+160+1,_Context->y_auto1+210+1,56,16,vfh[1],_Context->buffer_Back,7);
			break;
			case	0xf :
				/* Front */
				_Context->keycode = visual_edit(_Context->x_auto1+160+1,_Context->y_auto1+230+1,56,16,vfh[1],_Context->buffer_Front,7);
			break;
			case	0x10 :
				/* Left */
				_Context->keycode = visual_edit(_Context->x_auto1+280+1,_Context->y_auto1+210+1,56,16,vfh[1],_Context->buffer_Left,7);
			break;
			case	0x11 :
				/* Right */
				_Context->keycode = visual_edit(_Context->x_auto1+280+1,_Context->y_auto1+230+1,56,16,vfh[1],_Context->buffer_Right,7);
			break;
			case	0x12 :
				/* Upper */
				_Context->keycode = visual_edit(_Context->x_auto1+400+1,_Context->y_auto1+210+1,56,16,vfh[1],_Context->buffer_Upper,7);
			break;
			case	0x13 :
				/* Lower */
				_Context->keycode = visual_edit(_Context->x_auto1+400+1,_Context->y_auto1+230+1,56,16,vfh[1],_Context->buffer_Lower,7);
			break;
			case	0x14 :
				/* Light */
				_Context->keycode = visual_edit(_Context->x_auto1+520+1,_Context->y_auto1+210+1,56,16,vfh[1],_Context->buffer_Light,7);
			break;
			case	0x15 :
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
			_Context->focus_item=21;
			accept_cube_properties_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_cube_properties_event(_Context)) == -1)
					continue;
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
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto1+20,_Context->y_auto1+260,120,32,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto1+20,_Context->y_auto1+260,120,32,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0xa :
						/* Select */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto1+230,_Context->y_auto1+260,140,32,vfh[2],27,28,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto1+230,_Context->y_auto1+260,140,32,vfh[2],27,28,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Select_event(_Context)) != -1) break;

							}
						continue;
					case	0xb :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto1+470,_Context->y_auto1+260,120,32,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto1+470,_Context->y_auto1+260,120,32,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
						continue;
					case	0xc :
						/* AutoSize */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_AutoSize += 1;
							_Context->value_AutoSize &= 1;
							}
						continue;
					case	0xd :
						/* ImageFormat */
						continue;
					case	0xe :
						/* Back */
						continue;
					case	0xf :
						/* Front */
						continue;
					case	0x10 :
						/* Left */
						continue;
					case	0x11 :
						/* Right */
						continue;
					case	0x12 :
						/* Upper */
						continue;
					case	0x13 :
						/* Lower */
						continue;
					case	0x14 :
						/* Light */
						continue;
					case	0x15 :
						/* Dark */
						continue;
					case	0xffffffff :
					default :
						_Context->focus_item=1;
					continue;
					}
				break;
			case	0x1b :
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
				_Context->focus_item=21;
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
	char * pAutoSize,
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
	 pAutoSize,
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
	 pAutoSize,
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
