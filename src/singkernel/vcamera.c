
#ifndef _vcamera_c
#define _vcamera_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vcamera.xml  */
/* Target         : vcamera.c  */
/* Identification : 0.0-1100085127-2936.2935 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_auto1   "Sing : Version 1.0a"
#define fr_auto1   "Sing : Version 1.0a"
#define en_Auto1549   "skin.gif"
#define fr_Auto1549   "skin.gif"
#define en_Auto1550   "Project 3D Camera Properties"
#define fr_Auto1550   "PropriŠtes de la Vue du Projet"
#define it_Auto1550   ""
#define es_Auto1550   ""
#define de_Auto1550   ""
#define nl_Auto1550   ""
#define pt_Auto1550   ""
#define xx_Auto1550   ""
#define en_Auto1551   "Name"
#define fr_Auto1551   "Nom"
#define it_Auto1551   ""
#define es_Auto1551   ""
#define de_Auto1551   ""
#define nl_Auto1551   ""
#define pt_Auto1551   ""
#define xx_Auto1551   ""
#define en_Auto1552   "Position"
#define fr_Auto1552   "Position"
#define xx_Auto1552   "Aite"
#define en_Auto1553   "Focus"
#define fr_Auto1553   "Focus"
#define it_Auto1553   "Focus"
#define es_Auto1553   "Focus"
#define de_Auto1553   "Focus"
#define nl_Auto1553   "Focus"
#define pt_Auto1553   "Focus"
#define xx_Auto1553   "Focus"
#define en_auto331   "Direction"
#define fr_auto331   "Direction"
#define it_auto331   "Direction"
#define es_auto331   "Direction"
#define de_auto331   "Direction"
#define nl_auto331   "Direction"
#define pt_auto331   "Direction"
#define xx_auto331   "Direction"
#define en_auto332   "Configuration"
#define fr_auto332   "Configuration"
#define it_auto332   "Configuration"
#define es_auto332   "Configuration"
#define de_auto332   "Configuration"
#define nl_auto332   "Configuration"
#define pt_auto332   "Configuration"
#define xx_auto332   "Configuration"
#define en_Auto1554   "Base"
#define fr_Auto1554   "Configuration"
#define it_Auto1554   "Configuration"
#define es_Auto1554   "Configuration"
#define de_Auto1554   "Configuration"
#define nl_Auto1554   "Configuration"
#define pt_Auto1554   "Configuration"
#define xx_Auto1554   "Configuration"
#define en_Auto1555   "Step"
#define fr_Auto1555   "Pas"
#define it_Auto1555   "Step"
#define es_Auto1555   "Step"
#define de_Auto1555   "Step"
#define nl_Auto1555   "Step"
#define pt_Auto1555   "Step"
#define xx_Auto1555   "Step"
#define en_Auto1556   "Type"
#define fr_Auto1556   "Pas"
#define it_Auto1556   "Step"
#define es_Auto1556   "Step"
#define de_Auto1556   "Step"
#define nl_Auto1556   "Step"
#define pt_Auto1556   "Step"
#define xx_Auto1556   "Step"
#define en_Direction   "forward|backward|left|right|up|down"
#define fr_Direction   "devant|arriŠre|gauche|droite|haut|bas"
#define it_Direction   "forward|backward|left|right|up|down"
#define es_Direction   "forward|backward|left|right|up|down"
#define de_Direction   "forward|backward|left|right|up|down"
#define nl_Direction   "forward|backward|left|right|up|down"
#define pt_Direction   "forward|backward|left|right|up|down"
#define xx_Direction   "forward|backward|left|right|up|down"
#define en_Configuration   ""
#define en_DataBase   ""
#define en_auto347   "X"
#define fr_auto347   "X"
#define it_auto347   "X"
#define es_auto347   "X"
#define de_auto347   "X"
#define nl_auto347   "X"
#define pt_auto347   "X"
#define xx_auto347   "X"
#define en_auto348   "Y"
#define fr_auto348   "Y"
#define it_auto348   "Y"
#define es_auto348   "Y"
#define de_auto348   "Y"
#define nl_auto348   "Y"
#define pt_auto348   "Y"
#define xx_auto348   "Y"
#define en_auto349   "Z"
#define fr_auto349   "Z"
#define it_auto349   "Z"
#define es_auto349   "Z"
#define de_auto349   "Z"
#define nl_auto349   "Z"
#define pt_auto349   "Z"
#define xx_auto349   "Z"
#define en_auto350   "X"
#define fr_auto350   "X"
#define it_auto350   "X"
#define es_auto350   "X"
#define de_auto350   "X"
#define nl_auto350   "X"
#define pt_auto350   "X"
#define xx_auto350   "X"
#define en_auto351   "Y"
#define fr_auto351   "Y"
#define it_auto351   "Y"
#define es_auto351   "Y"
#define de_auto351   "Y"
#define nl_auto351   "Y"
#define pt_auto351   "Y"
#define xx_auto351   "Y"
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
#define en_auto380   "Sizes"
#define fr_auto380   "Dimensions"
#define it_auto380   "Sizes"
#define es_auto380   "Sizes"
#define de_auto380   "Sizes"
#define nl_auto380   "Sizes"
#define pt_auto380   "Sizes"
#define xx_auto380   "Sizes"
#define en_auto382   "Distance"
#define fr_auto382   "Distance"
#define it_auto382   "Distance"
#define es_auto382   "Distance"
#define de_auto382   "Distance"
#define nl_auto382   "Distance"
#define pt_auto382   "Distance"
#define xx_auto382   "Distance"
#define fr_ImageFormat   "Bmp|Gif|Jpeg"
#define it_ImageFormat   "Bmp|Gif|Jpeg"
#define es_ImageFormat   "Bmp|Gif|Jpeg"
#define de_ImageFormat   "Bmp|Gif|Jpeg"
#define nl_ImageFormat   "Bmp|Gif|Jpeg"
#define pt_ImageFormat   "Bmp|Gif|Jpeg"
#define xx_ImageFormat   "Bmp|Gif|Jpeg"
#define en_auto394   "X"
#define fr_auto394   "X"
#define it_auto394   "X"
#define es_auto394   "X"
#define de_auto394   "X"
#define nl_auto394   "X"
#define pt_auto394   "X"
#define xx_auto394   "X"
#define en_auto395   "Y"
#define fr_auto395   "Y"
#define it_auto395   "Y"
#define es_auto395   "Y"
#define de_auto395   "Y"
#define nl_auto395   "Y"
#define pt_auto395   "Y"
#define xx_auto395   "Y"
#define en_auto398   "Z"
#define fr_auto398   "Z"
#define it_auto398   "Z"
#define es_auto398   "Z"
#define de_auto398   "Z"
#define nl_auto398   "Z"
#define pt_auto398   "Z"
#define xx_auto398   "Z"
#define en_DynamicSize   "Au&toSize"
#define fr_DynamicSize   "&Taille Automatique"
#define it_DynamicSize   "Au&toSize"
#define es_DynamicSize   "Au&toSize"
#define de_DynamicSize   "Au&toSize"
#define nl_DynamicSize   "Au&toSize"
#define pt_DynamicSize   "Au&toSize"
#define xx_DynamicSize   "Au&toSize"
#define en_SaveForms   "Save &Forms"
#define fr_SaveForms   "Sauve &Formulaires"
#define it_SaveForms   ""
#define es_SaveForms   ""
#define de_SaveForms   ""
#define nl_SaveForms   ""
#define pt_SaveForms   ""
#define xx_SaveForms   ""
#define en_SaveImages   "Save &Images"
#define fr_SaveImages   "Sa&uve Images"
#define it_SaveImages   ""
#define es_SaveImages   ""
#define de_SaveImages   ""
#define nl_SaveImages   ""
#define pt_SaveImages   ""
#define xx_SaveImages   ""
#define en_Auto1557   "Background Image"
#define fr_Auto1557   "Image de Fond"
#define it_Auto1557   ""
#define es_Auto1557   ""
#define de_Auto1557   ""
#define nl_Auto1557   ""
#define pt_Auto1557   ""
#define xx_Auto1557   ""
#define en_Auto1738   "Palette"
#define fr_Auto1738   "Palette"
#define it_Auto1738   "Palette"
#define es_Auto1738   "Palette"
#define de_Auto1738   "Palette"
#define nl_Auto1738   "Palette"
#define pt_Auto1738   "Palette"
#define xx_Auto1738   "Palette"
#define en_Auto1558   "Image Options"
#define fr_Auto1558   "Options d'image"
#define it_Auto1558   ""
#define es_Auto1558   ""
#define de_Auto1558   ""
#define nl_Auto1558   ""
#define pt_Auto1558   ""
#define xx_Auto1558   ""
#define en_auto702   "Colour"
#define fr_auto702   "Caract‚res"
#define xx_auto702   "Dath Teacs"
#define en_PaletteName   ""
#define en_Quality   "&Quality"
#define fr_Quality   "&Qualit‚"
#define it_Quality   "&Quality"
#define es_Quality   "&Quality"
#define de_Quality   "&Quality"
#define nl_Quality   "&Quality"
#define pt_Quality   "&Quality"
#define xx_Quality   "&Quality"
#define en_Select   "&Select"
#define fr_Select   "&S‚lection"
static int	vfh[10];

private struct accept_camera_properties_context {
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
	char * msg_Auto1549[8];
	char * msg_Auto1550[8];
	char * msg_Auto1551[8];
	char * msg_Auto1552[8];
	char * msg_Auto1553[8];
	char * msg_auto331[8];
	char * msg_auto332[8];
	char * msg_Auto1554[8];
	char * msg_Auto1555[8];
	char * msg_Auto1556[8];
	char	buffer_Name[58];
	char	buffer_AtX[11];
	char	buffer_AtY[11];
	char	buffer_AtZ[10];
	char	buffer_ToX[11];
	char	buffer_ToY[11];
	char * msg_Direction[8];
	int	value_Direction;
	char	buffer_Configuration[26];
	char	buffer_DataBase[28];
	char	buffer_Step[12];
	char * msg_auto347[8];
	char * msg_auto348[8];
	char * msg_auto349[8];
	char * msg_auto350[8];
	char * msg_auto351[8];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * msg_auto380[8];
	char * msg_auto382[8];
	char	buffer_NbX[11];
	char	buffer_nbY[11];
	char	buffer_NbZ[11];
	char	buffer_StepX[11];
	char	buffer_StepY[11];
	char	buffer_StepZ[11];
	char * msg_ImageFormat[8];
	int	value_ImageFormat;
	char * msg_auto394[8];
	char * msg_auto395[8];
	char * msg_auto398[8];
	char * msg_DynamicSize[8];
	int	trigger_DynamicSize;
	int	value_DynamicSize;
	char * msg_SaveForms[8];
	int	trigger_SaveForms;
	int	value_SaveForms;
	char * msg_SaveImages[8];
	int	trigger_SaveImages;
	int	value_SaveImages;
	char * msg_Auto1557[8];
	char * msg_Auto1738[8];
	char * msg_Auto1558[8];
	char * msg_auto702[8];
	char	buffer_ImageName[58];
	char	buffer_PaletteName[58];
	char * msg_ImageType[8];
	int	value_ImageType;
	char	buffer_Colour[11];
	char * msg_Quality[8];
	int	trigger_Quality;
	int	value_Quality;
	char * msg_Select[8];
	int	trigger_Select;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[26];
	};

public	int	accept_camera_properties_create(
	struct accept_camera_properties_context ** cptr,
	char * pName,
	char * pAtX,
	char * pAtY,
	char * pAtZ,
	char * pToX,
	char * pToY,
	char * pDirection,
	char * pConfiguration,
	char * pDataBase,
	char * pStep,
	char * pNbX,
	char * pnbY,
	char * pNbZ,
	char * pStepX,
	char * pStepY,
	char * pStepZ,
	char * pImageFormat,
	char * pDynamicSize,
	char * pSaveForms,
	char * pSaveImages,
	char * pImageName,
	char * pPaletteName,
	char * pImageType,
	char * pColour,
	char * pQuality)
{

	int i;
	struct accept_camera_properties_context * _Context=(struct accept_camera_properties_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_camera_properties_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=29;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWWWWSSWWWWWWWWWWWSSWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Name, 57, pName);
		visual_transferin(_Context->buffer_AtX, 10, pAtX);
		visual_transferin(_Context->buffer_AtY, 10, pAtY);
		visual_transferin(_Context->buffer_AtZ, 9, pAtZ);
		visual_transferin(_Context->buffer_ToX, 10, pToX);
		visual_transferin(_Context->buffer_ToY, 10, pToY);
		visual_transferin((void *) 0, 0, pDirection);
		if (!( pDirection )) _Context->value_Direction=0;
		else	_Context->value_Direction = *((int *)pDirection);
		visual_transferin(_Context->buffer_Configuration, 25, pConfiguration);
		visual_transferin(_Context->buffer_DataBase, 27, pDataBase);
		visual_transferin(_Context->buffer_Step, 11, pStep);
		visual_transferin(_Context->buffer_NbX, 10, pNbX);
		visual_transferin(_Context->buffer_nbY, 10, pnbY);
		visual_transferin(_Context->buffer_NbZ, 10, pNbZ);
		visual_transferin(_Context->buffer_StepX, 10, pStepX);
		visual_transferin(_Context->buffer_StepY, 10, pStepY);
		visual_transferin(_Context->buffer_StepZ, 10, pStepZ);
		visual_transferin((void *) 0, 0, pImageFormat);
		if (!( pImageFormat )) _Context->value_ImageFormat=0;
		else	_Context->value_ImageFormat = *((int *)pImageFormat);
		visual_transferin((void *) 0, 0, pDynamicSize);
		if (!( pDynamicSize )) _Context->value_DynamicSize=0;
		else	_Context->value_DynamicSize = *((int *)pDynamicSize);
		visual_transferin((void *) 0, 0, pSaveForms);
		if (!( pSaveForms )) _Context->value_SaveForms=0;
		else	_Context->value_SaveForms = *((int *)pSaveForms);
		visual_transferin((void *) 0, 0, pSaveImages);
		if (!( pSaveImages )) _Context->value_SaveImages=0;
		else	_Context->value_SaveImages = *((int *)pSaveImages);
		visual_transferin(_Context->buffer_ImageName, 57, pImageName);
		visual_transferin(_Context->buffer_PaletteName, 57, pPaletteName);
		visual_transferin((void *) 0, 0, pImageType);
		if (!( pImageType )) _Context->value_ImageType=0;
		else	_Context->value_ImageType = *((int *)pImageType);
		visual_transferin(_Context->buffer_Colour, 10, pColour);
		visual_transferin((void *) 0, 0, pQuality);
		if (!( pQuality )) _Context->value_Quality=0;
		else	_Context->value_Quality = *((int *)pQuality);
		}
	for (i=0; i < 8; i++)_Context->msg_auto1[i]=" ";
	_Context->msg_auto1[0]=en_auto1;
	_Context->msg_auto1[1]=fr_auto1;
	_Context->x_auto1=95;
	_Context->y_auto1=85;
	_Context->w_auto1=610;
	_Context->h_auto1=430;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto1549[i]=" ";
	_Context->msg_Auto1549[0]=en_Auto1549;
	_Context->msg_Auto1549[1]=fr_Auto1549;
	for (i=0; i < 8; i++)_Context->msg_Auto1550[i]=" ";
	_Context->msg_Auto1550[0]=en_Auto1550;
	_Context->msg_Auto1550[1]=fr_Auto1550;
	_Context->msg_Auto1550[2]=it_Auto1550;
	_Context->msg_Auto1550[3]=es_Auto1550;
	_Context->msg_Auto1550[4]=de_Auto1550;
	_Context->msg_Auto1550[5]=nl_Auto1550;
	_Context->msg_Auto1550[6]=pt_Auto1550;
	_Context->msg_Auto1550[7]=xx_Auto1550;
	for (i=0; i < 8; i++)_Context->msg_Auto1551[i]=" ";
	_Context->msg_Auto1551[0]=en_Auto1551;
	_Context->msg_Auto1551[1]=fr_Auto1551;
	_Context->msg_Auto1551[2]=it_Auto1551;
	_Context->msg_Auto1551[3]=es_Auto1551;
	_Context->msg_Auto1551[4]=de_Auto1551;
	_Context->msg_Auto1551[5]=nl_Auto1551;
	_Context->msg_Auto1551[6]=pt_Auto1551;
	_Context->msg_Auto1551[7]=xx_Auto1551;
	for (i=0; i < 8; i++)_Context->msg_Auto1552[i]=" ";
	_Context->msg_Auto1552[0]=en_Auto1552;
	_Context->msg_Auto1552[1]=fr_Auto1552;
	_Context->msg_Auto1552[7]=xx_Auto1552;
	for (i=0; i < 8; i++)_Context->msg_Auto1553[i]=" ";
	_Context->msg_Auto1553[0]=en_Auto1553;
	_Context->msg_Auto1553[1]=fr_Auto1553;
	_Context->msg_Auto1553[2]=it_Auto1553;
	_Context->msg_Auto1553[3]=es_Auto1553;
	_Context->msg_Auto1553[4]=de_Auto1553;
	_Context->msg_Auto1553[5]=nl_Auto1553;
	_Context->msg_Auto1553[6]=pt_Auto1553;
	_Context->msg_Auto1553[7]=xx_Auto1553;
	for (i=0; i < 8; i++)_Context->msg_auto331[i]=" ";
	_Context->msg_auto331[0]=en_auto331;
	_Context->msg_auto331[1]=fr_auto331;
	_Context->msg_auto331[2]=it_auto331;
	_Context->msg_auto331[3]=es_auto331;
	_Context->msg_auto331[4]=de_auto331;
	_Context->msg_auto331[5]=nl_auto331;
	_Context->msg_auto331[6]=pt_auto331;
	_Context->msg_auto331[7]=xx_auto331;
	for (i=0; i < 8; i++)_Context->msg_auto332[i]=" ";
	_Context->msg_auto332[0]=en_auto332;
	_Context->msg_auto332[1]=fr_auto332;
	_Context->msg_auto332[2]=it_auto332;
	_Context->msg_auto332[3]=es_auto332;
	_Context->msg_auto332[4]=de_auto332;
	_Context->msg_auto332[5]=nl_auto332;
	_Context->msg_auto332[6]=pt_auto332;
	_Context->msg_auto332[7]=xx_auto332;
	for (i=0; i < 8; i++)_Context->msg_Auto1554[i]=" ";
	_Context->msg_Auto1554[0]=en_Auto1554;
	_Context->msg_Auto1554[1]=fr_Auto1554;
	_Context->msg_Auto1554[2]=it_Auto1554;
	_Context->msg_Auto1554[3]=es_Auto1554;
	_Context->msg_Auto1554[4]=de_Auto1554;
	_Context->msg_Auto1554[5]=nl_Auto1554;
	_Context->msg_Auto1554[6]=pt_Auto1554;
	_Context->msg_Auto1554[7]=xx_Auto1554;
	for (i=0; i < 8; i++)_Context->msg_Auto1555[i]=" ";
	_Context->msg_Auto1555[0]=en_Auto1555;
	_Context->msg_Auto1555[1]=fr_Auto1555;
	_Context->msg_Auto1555[2]=it_Auto1555;
	_Context->msg_Auto1555[3]=es_Auto1555;
	_Context->msg_Auto1555[4]=de_Auto1555;
	_Context->msg_Auto1555[5]=nl_Auto1555;
	_Context->msg_Auto1555[6]=pt_Auto1555;
	_Context->msg_Auto1555[7]=xx_Auto1555;
	for (i=0; i < 8; i++)_Context->msg_Auto1556[i]=" ";
	_Context->msg_Auto1556[0]=en_Auto1556;
	_Context->msg_Auto1556[1]=fr_Auto1556;
	_Context->msg_Auto1556[2]=it_Auto1556;
	_Context->msg_Auto1556[3]=es_Auto1556;
	_Context->msg_Auto1556[4]=de_Auto1556;
	_Context->msg_Auto1556[5]=nl_Auto1556;
	_Context->msg_Auto1556[6]=pt_Auto1556;
	_Context->msg_Auto1556[7]=xx_Auto1556;
	for (i=0; i < 8; i++)_Context->msg_Direction[i]=" ";
	_Context->msg_Direction[0]=en_Direction;
	_Context->msg_Direction[1]=fr_Direction;
	_Context->msg_Direction[2]=it_Direction;
	_Context->msg_Direction[3]=es_Direction;
	_Context->msg_Direction[4]=de_Direction;
	_Context->msg_Direction[5]=nl_Direction;
	_Context->msg_Direction[6]=pt_Direction;
	_Context->msg_Direction[7]=xx_Direction;
	for (i=0; i < 8; i++)_Context->msg_auto347[i]=" ";
	_Context->msg_auto347[0]=en_auto347;
	_Context->msg_auto347[1]=fr_auto347;
	_Context->msg_auto347[2]=it_auto347;
	_Context->msg_auto347[3]=es_auto347;
	_Context->msg_auto347[4]=de_auto347;
	_Context->msg_auto347[5]=nl_auto347;
	_Context->msg_auto347[6]=pt_auto347;
	_Context->msg_auto347[7]=xx_auto347;
	for (i=0; i < 8; i++)_Context->msg_auto348[i]=" ";
	_Context->msg_auto348[0]=en_auto348;
	_Context->msg_auto348[1]=fr_auto348;
	_Context->msg_auto348[2]=it_auto348;
	_Context->msg_auto348[3]=es_auto348;
	_Context->msg_auto348[4]=de_auto348;
	_Context->msg_auto348[5]=nl_auto348;
	_Context->msg_auto348[6]=pt_auto348;
	_Context->msg_auto348[7]=xx_auto348;
	for (i=0; i < 8; i++)_Context->msg_auto349[i]=" ";
	_Context->msg_auto349[0]=en_auto349;
	_Context->msg_auto349[1]=fr_auto349;
	_Context->msg_auto349[2]=it_auto349;
	_Context->msg_auto349[3]=es_auto349;
	_Context->msg_auto349[4]=de_auto349;
	_Context->msg_auto349[5]=nl_auto349;
	_Context->msg_auto349[6]=pt_auto349;
	_Context->msg_auto349[7]=xx_auto349;
	for (i=0; i < 8; i++)_Context->msg_auto350[i]=" ";
	_Context->msg_auto350[0]=en_auto350;
	_Context->msg_auto350[1]=fr_auto350;
	_Context->msg_auto350[2]=it_auto350;
	_Context->msg_auto350[3]=es_auto350;
	_Context->msg_auto350[4]=de_auto350;
	_Context->msg_auto350[5]=nl_auto350;
	_Context->msg_auto350[6]=pt_auto350;
	_Context->msg_auto350[7]=xx_auto350;
	for (i=0; i < 8; i++)_Context->msg_auto351[i]=" ";
	_Context->msg_auto351[0]=en_auto351;
	_Context->msg_auto351[1]=fr_auto351;
	_Context->msg_auto351[2]=it_auto351;
	_Context->msg_auto351[3]=es_auto351;
	_Context->msg_auto351[4]=de_auto351;
	_Context->msg_auto351[5]=nl_auto351;
	_Context->msg_auto351[6]=pt_auto351;
	_Context->msg_auto351[7]=xx_auto351;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	for (i=0; i < 8; i++)_Context->msg_auto380[i]=" ";
	_Context->msg_auto380[0]=en_auto380;
	_Context->msg_auto380[1]=fr_auto380;
	_Context->msg_auto380[2]=it_auto380;
	_Context->msg_auto380[3]=es_auto380;
	_Context->msg_auto380[4]=de_auto380;
	_Context->msg_auto380[5]=nl_auto380;
	_Context->msg_auto380[6]=pt_auto380;
	_Context->msg_auto380[7]=xx_auto380;
	for (i=0; i < 8; i++)_Context->msg_auto382[i]=" ";
	_Context->msg_auto382[0]=en_auto382;
	_Context->msg_auto382[1]=fr_auto382;
	_Context->msg_auto382[2]=it_auto382;
	_Context->msg_auto382[3]=es_auto382;
	_Context->msg_auto382[4]=de_auto382;
	_Context->msg_auto382[5]=nl_auto382;
	_Context->msg_auto382[6]=pt_auto382;
	_Context->msg_auto382[7]=xx_auto382;
	for (i=0; i < 8; i++)_Context->msg_ImageFormat[i]=" ";
	_Context->msg_ImageFormat[1]=fr_ImageFormat;
	_Context->msg_ImageFormat[2]=it_ImageFormat;
	_Context->msg_ImageFormat[3]=es_ImageFormat;
	_Context->msg_ImageFormat[4]=de_ImageFormat;
	_Context->msg_ImageFormat[5]=nl_ImageFormat;
	_Context->msg_ImageFormat[6]=pt_ImageFormat;
	_Context->msg_ImageFormat[7]=xx_ImageFormat;
	for (i=0; i < 8; i++)_Context->msg_auto394[i]=" ";
	_Context->msg_auto394[0]=en_auto394;
	_Context->msg_auto394[1]=fr_auto394;
	_Context->msg_auto394[2]=it_auto394;
	_Context->msg_auto394[3]=es_auto394;
	_Context->msg_auto394[4]=de_auto394;
	_Context->msg_auto394[5]=nl_auto394;
	_Context->msg_auto394[6]=pt_auto394;
	_Context->msg_auto394[7]=xx_auto394;
	for (i=0; i < 8; i++)_Context->msg_auto395[i]=" ";
	_Context->msg_auto395[0]=en_auto395;
	_Context->msg_auto395[1]=fr_auto395;
	_Context->msg_auto395[2]=it_auto395;
	_Context->msg_auto395[3]=es_auto395;
	_Context->msg_auto395[4]=de_auto395;
	_Context->msg_auto395[5]=nl_auto395;
	_Context->msg_auto395[6]=pt_auto395;
	_Context->msg_auto395[7]=xx_auto395;
	for (i=0; i < 8; i++)_Context->msg_auto398[i]=" ";
	_Context->msg_auto398[0]=en_auto398;
	_Context->msg_auto398[1]=fr_auto398;
	_Context->msg_auto398[2]=it_auto398;
	_Context->msg_auto398[3]=es_auto398;
	_Context->msg_auto398[4]=de_auto398;
	_Context->msg_auto398[5]=nl_auto398;
	_Context->msg_auto398[6]=pt_auto398;
	_Context->msg_auto398[7]=xx_auto398;
	for (i=0; i < 8; i++)_Context->msg_DynamicSize[i]=" ";
	_Context->msg_DynamicSize[0]=en_DynamicSize;
	_Context->msg_DynamicSize[1]=fr_DynamicSize;
	_Context->msg_DynamicSize[2]=it_DynamicSize;
	_Context->msg_DynamicSize[3]=es_DynamicSize;
	_Context->msg_DynamicSize[4]=de_DynamicSize;
	_Context->msg_DynamicSize[5]=nl_DynamicSize;
	_Context->msg_DynamicSize[6]=pt_DynamicSize;
	_Context->msg_DynamicSize[7]=xx_DynamicSize;
	for (i=0; i < 8; i++)_Context->msg_SaveForms[i]=" ";
	_Context->msg_SaveForms[0]=en_SaveForms;
	_Context->msg_SaveForms[1]=fr_SaveForms;
	_Context->msg_SaveForms[2]=it_SaveForms;
	_Context->msg_SaveForms[3]=es_SaveForms;
	_Context->msg_SaveForms[4]=de_SaveForms;
	_Context->msg_SaveForms[5]=nl_SaveForms;
	_Context->msg_SaveForms[6]=pt_SaveForms;
	_Context->msg_SaveForms[7]=xx_SaveForms;
	for (i=0; i < 8; i++)_Context->msg_SaveImages[i]=" ";
	_Context->msg_SaveImages[0]=en_SaveImages;
	_Context->msg_SaveImages[1]=fr_SaveImages;
	_Context->msg_SaveImages[2]=it_SaveImages;
	_Context->msg_SaveImages[3]=es_SaveImages;
	_Context->msg_SaveImages[4]=de_SaveImages;
	_Context->msg_SaveImages[5]=nl_SaveImages;
	_Context->msg_SaveImages[6]=pt_SaveImages;
	_Context->msg_SaveImages[7]=xx_SaveImages;
	for (i=0; i < 8; i++)_Context->msg_Auto1557[i]=" ";
	_Context->msg_Auto1557[0]=en_Auto1557;
	_Context->msg_Auto1557[1]=fr_Auto1557;
	_Context->msg_Auto1557[2]=it_Auto1557;
	_Context->msg_Auto1557[3]=es_Auto1557;
	_Context->msg_Auto1557[4]=de_Auto1557;
	_Context->msg_Auto1557[5]=nl_Auto1557;
	_Context->msg_Auto1557[6]=pt_Auto1557;
	_Context->msg_Auto1557[7]=xx_Auto1557;
	for (i=0; i < 8; i++)_Context->msg_Auto1738[i]=" ";
	_Context->msg_Auto1738[0]=en_Auto1738;
	_Context->msg_Auto1738[1]=fr_Auto1738;
	_Context->msg_Auto1738[2]=it_Auto1738;
	_Context->msg_Auto1738[3]=es_Auto1738;
	_Context->msg_Auto1738[4]=de_Auto1738;
	_Context->msg_Auto1738[5]=nl_Auto1738;
	_Context->msg_Auto1738[6]=pt_Auto1738;
	_Context->msg_Auto1738[7]=xx_Auto1738;
	for (i=0; i < 8; i++)_Context->msg_Auto1558[i]=" ";
	_Context->msg_Auto1558[0]=en_Auto1558;
	_Context->msg_Auto1558[1]=fr_Auto1558;
	_Context->msg_Auto1558[2]=it_Auto1558;
	_Context->msg_Auto1558[3]=es_Auto1558;
	_Context->msg_Auto1558[4]=de_Auto1558;
	_Context->msg_Auto1558[5]=nl_Auto1558;
	_Context->msg_Auto1558[6]=pt_Auto1558;
	_Context->msg_Auto1558[7]=xx_Auto1558;
	for (i=0; i < 8; i++)_Context->msg_auto702[i]=" ";
	_Context->msg_auto702[0]=en_auto702;
	_Context->msg_auto702[1]=fr_auto702;
	_Context->msg_auto702[7]=xx_auto702;
	for (i=0; i < 8; i++)_Context->msg_ImageType[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_Quality[i]=" ";
	_Context->msg_Quality[0]=en_Quality;
	_Context->msg_Quality[1]=fr_Quality;
	_Context->msg_Quality[2]=it_Quality;
	_Context->msg_Quality[3]=es_Quality;
	_Context->msg_Quality[4]=de_Quality;
	_Context->msg_Quality[5]=nl_Quality;
	_Context->msg_Quality[6]=pt_Quality;
	_Context->msg_Quality[7]=xx_Quality;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto1,_Context->y_auto1,610+10,430+10);
	return(0);
}

public 	int	accept_camera_properties_hide(struct accept_camera_properties_context * _Context)
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

public	int	accept_camera_properties_remove(
	struct accept_camera_properties_context * _Context,
	char * pName,
	char * pAtX,
	char * pAtY,
	char * pAtZ,
	char * pToX,
	char * pToY,
	char * pDirection,
	char * pConfiguration,
	char * pDataBase,
	char * pStep,
	char * pNbX,
	char * pnbY,
	char * pNbZ,
	char * pStepX,
	char * pStepY,
	char * pStepZ,
	char * pImageFormat,
	char * pDynamicSize,
	char * pSaveForms,
	char * pSaveImages,
	char * pImageName,
	char * pPaletteName,
	char * pImageType,
	char * pColour,
	char * pQuality)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SWWWWWWSSWWWWWWWWWWWSSWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Name, 57, pName);
		visual_transferout(_Context->buffer_AtX, 10, pAtX);
		visual_transferout(_Context->buffer_AtY, 10, pAtY);
		visual_transferout(_Context->buffer_AtZ, 9, pAtZ);
		visual_transferout(_Context->buffer_ToX, 10, pToX);
		visual_transferout(_Context->buffer_ToY, 10, pToY);
		visual_transferout((void *) 0, 0, pDirection);
		if ( pDirection != (char *) 0)
			*((int*)pDirection) = _Context->value_Direction;
		visual_transferout(_Context->buffer_Configuration, 25, pConfiguration);
		visual_transferout(_Context->buffer_DataBase, 27, pDataBase);
		visual_transferout(_Context->buffer_Step, 11, pStep);
		visual_transferout(_Context->buffer_NbX, 10, pNbX);
		visual_transferout(_Context->buffer_nbY, 10, pnbY);
		visual_transferout(_Context->buffer_NbZ, 10, pNbZ);
		visual_transferout(_Context->buffer_StepX, 10, pStepX);
		visual_transferout(_Context->buffer_StepY, 10, pStepY);
		visual_transferout(_Context->buffer_StepZ, 10, pStepZ);
		visual_transferout((void *) 0, 0, pImageFormat);
		if ( pImageFormat != (char *) 0)
			*((int*)pImageFormat) = _Context->value_ImageFormat;
		visual_transferout((void *) 0, 0, pDynamicSize);
		if ( pDynamicSize != (char *) 0)
			*((int*)pDynamicSize) = _Context->value_DynamicSize;
		visual_transferout((void *) 0, 0, pSaveForms);
		if ( pSaveForms != (char *) 0)
			*((int*)pSaveForms) = _Context->value_SaveForms;
		visual_transferout((void *) 0, 0, pSaveImages);
		if ( pSaveImages != (char *) 0)
			*((int*)pSaveImages) = _Context->value_SaveImages;
		visual_transferout(_Context->buffer_ImageName, 57, pImageName);
		visual_transferout(_Context->buffer_PaletteName, 57, pPaletteName);
		visual_transferout((void *) 0, 0, pImageType);
		if ( pImageType != (char *) 0)
			*((int*)pImageType) = _Context->value_ImageType;
		visual_transferout(_Context->buffer_Colour, 10, pColour);
		visual_transferout((void *) 0, 0, pQuality);
		if ( pQuality != (char *) 0)
			*((int*)pQuality) = _Context->value_Quality;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_camera_properties_show(struct accept_camera_properties_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto1,_Context->y_auto1);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_auto1,_Context->y_auto1,610,430,vfh[2],_Context->msg_auto1[_Context->language],strlen(_Context->msg_auto1[_Context->language]),0x407);
	visual_image(_Context->x_auto1+2,_Context->y_auto1+20,604,406,_Context->msg_Auto1549[_Context->language],4);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+30,560,20,vfh[3],27,0,_Context->msg_Auto1550[_Context->language],strlen(_Context->msg_Auto1550[_Context->language]),1282);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+60,110,20,vfh[2],27,0,_Context->msg_Auto1551[_Context->language],strlen(_Context->msg_Auto1551[_Context->language]),2);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+90,110,20,vfh[2],27,0,_Context->msg_Auto1552[_Context->language],strlen(_Context->msg_Auto1552[_Context->language]),2);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+120,100,20,vfh[2],27,0,_Context->msg_Auto1553[_Context->language],strlen(_Context->msg_Auto1553[_Context->language]),2);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+150,110,20,vfh[2],27,0,_Context->msg_auto331[_Context->language],strlen(_Context->msg_auto331[_Context->language]),2);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+180,110,20,vfh[2],27,0,_Context->msg_auto332[_Context->language],strlen(_Context->msg_auto332[_Context->language]),2);
	visual_text(_Context->x_auto1+340,_Context->y_auto1+180,42,16,vfh[2],27,0,_Context->msg_Auto1554[_Context->language],strlen(_Context->msg_Auto1554[_Context->language]),2);
	visual_text(_Context->x_auto1+460,_Context->y_auto1+210,42,16,vfh[2],27,0,_Context->msg_Auto1555[_Context->language],strlen(_Context->msg_Auto1555[_Context->language]),2);
	visual_text(_Context->x_auto1+460,_Context->y_auto1+240,42,16,vfh[2],27,0,_Context->msg_Auto1556[_Context->language],strlen(_Context->msg_Auto1556[_Context->language]),2);
	visual_frame(_Context->x_auto1+130,_Context->y_auto1+60,456+2,16+2,5);
	visual_text(_Context->x_auto1+130+1,_Context->y_auto1+60+1,456,16,vfh[1],26,0,_Context->buffer_Name,57,0);
	visual_frame(_Context->x_auto1+130,_Context->y_auto1+90,80+2,16+2,5);
	visual_text(_Context->x_auto1+130+1,_Context->y_auto1+90+1,80,16,vfh[1],26,0,_Context->buffer_AtX,10,0);
	visual_frame(_Context->x_auto1+250,_Context->y_auto1+90,80+2,16+2,5);
	visual_text(_Context->x_auto1+250+1,_Context->y_auto1+90+1,80,16,vfh[1],26,0,_Context->buffer_AtY,10,0);
	visual_frame(_Context->x_auto1+370,_Context->y_auto1+90,72+2,16+2,5);
	visual_text(_Context->x_auto1+370+1,_Context->y_auto1+90+1,72,16,vfh[1],26,0,_Context->buffer_AtZ,9,0);
	visual_frame(_Context->x_auto1+130,_Context->y_auto1+120,80+2,16+2,5);
	visual_text(_Context->x_auto1+130+1,_Context->y_auto1+120+1,80,16,vfh[1],26,0,_Context->buffer_ToX,10,0);
	visual_frame(_Context->x_auto1+250,_Context->y_auto1+120,80+2,16+2,5);
	visual_text(_Context->x_auto1+250+1,_Context->y_auto1+120+1,80,16,vfh[1],26,0,_Context->buffer_ToY,10,0);
	visual_select(_Context->x_auto1+130,_Context->y_auto1+150,200,80,vfh[1],26,0,parse_selection(_Context->msg_Direction[_Context->language],&_Context->value_Direction),512);
	visual_frame(_Context->x_auto1+130,_Context->y_auto1+180,200+2,16+2,5);
	visual_text(_Context->x_auto1+130+1,_Context->y_auto1+180+1,200,16,vfh[1],26,0,_Context->buffer_Configuration,25,0);
	visual_frame(_Context->x_auto1+370,_Context->y_auto1+180,216+2,16+2,5);
	visual_text(_Context->x_auto1+370+1,_Context->y_auto1+180+1,216,16,vfh[1],26,0,_Context->buffer_DataBase,27,0);
	visual_frame(_Context->x_auto1+500,_Context->y_auto1+210,88+2,16+2,5);
	visual_text(_Context->x_auto1+500+1,_Context->y_auto1+210+1,88,16,vfh[1],26,0,_Context->buffer_Step,11,0);
	visual_text(_Context->x_auto1+120,_Context->y_auto1+90,14,16,vfh[2],27,0,_Context->msg_auto347[_Context->language],strlen(_Context->msg_auto347[_Context->language]),3);
	visual_text(_Context->x_auto1+240,_Context->y_auto1+90,14,16,vfh[2],27,0,_Context->msg_auto348[_Context->language],strlen(_Context->msg_auto348[_Context->language]),3);
	visual_text(_Context->x_auto1+350,_Context->y_auto1+90,20,20,vfh[2],27,0,_Context->msg_auto349[_Context->language],strlen(_Context->msg_auto349[_Context->language]),3);
	visual_text(_Context->x_auto1+120,_Context->y_auto1+120,14,20,vfh[2],27,0,_Context->msg_auto350[_Context->language],strlen(_Context->msg_auto350[_Context->language]),3);
	visual_text(_Context->x_auto1+240,_Context->y_auto1+120,14,20,vfh[2],27,0,_Context->msg_auto351[_Context->language],strlen(_Context->msg_auto351[_Context->language]),3);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_auto1+20,_Context->y_auto1+380,120,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto1+470,_Context->y_auto1+380,120,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+210,98,16,vfh[2],27,0,_Context->msg_auto380[_Context->language],strlen(_Context->msg_auto380[_Context->language]),2);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+240,110,20,vfh[2],27,0,_Context->msg_auto382[_Context->language],strlen(_Context->msg_auto382[_Context->language]),2);
	visual_frame(_Context->x_auto1+130,_Context->y_auto1+210,80+2,16+2,5);
	visual_text(_Context->x_auto1+130+1,_Context->y_auto1+210+1,80,16,vfh[1],26,0,_Context->buffer_NbX,10,0);
	visual_frame(_Context->x_auto1+250,_Context->y_auto1+210,80+2,16+2,5);
	visual_text(_Context->x_auto1+250+1,_Context->y_auto1+210+1,80,16,vfh[1],0,0,_Context->buffer_nbY,10,0);
	visual_frame(_Context->x_auto1+370,_Context->y_auto1+210,80+2,16+2,5);
	visual_text(_Context->x_auto1+370+1,_Context->y_auto1+210+1,80,16,vfh[1],26,0,_Context->buffer_NbZ,10,0);
	visual_frame(_Context->x_auto1+130,_Context->y_auto1+240,80+2,16+2,5);
	visual_text(_Context->x_auto1+130+1,_Context->y_auto1+240+1,80,16,vfh[1],26,0,_Context->buffer_StepX,10,0);
	visual_frame(_Context->x_auto1+250,_Context->y_auto1+240,80+2,16+2,5);
	visual_text(_Context->x_auto1+250+1,_Context->y_auto1+240+1,80,16,vfh[1],26,0,_Context->buffer_StepY,10,0);
	visual_frame(_Context->x_auto1+370,_Context->y_auto1+240,80+2,16+2,5);
	visual_text(_Context->x_auto1+370+1,_Context->y_auto1+240+1,80,16,vfh[1],26,0,_Context->buffer_StepZ,10,0);
	visual_select(_Context->x_auto1+500,_Context->y_auto1+240,88,96,vfh[1],0,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),0);
	visual_text(_Context->x_auto1+120,_Context->y_auto1+210,14,20,vfh[2],27,0,_Context->msg_auto394[_Context->language],strlen(_Context->msg_auto394[_Context->language]),3);
	visual_text(_Context->x_auto1+240,_Context->y_auto1+210,14,20,vfh[2],27,0,_Context->msg_auto395[_Context->language],strlen(_Context->msg_auto395[_Context->language]),3);
	visual_text(_Context->x_auto1+360,_Context->y_auto1+210,14,20,vfh[2],27,0,_Context->msg_auto398[_Context->language],strlen(_Context->msg_auto398[_Context->language]),3);
	_Context->trigger_DynamicSize=visual_trigger_code(_Context->msg_DynamicSize[_Context->language],strlen(_Context->msg_DynamicSize[_Context->language]));
	visual_check(_Context->x_auto1+370,_Context->y_auto1+110,112,16,vfh[2],26,0,_Context->msg_DynamicSize[_Context->language],strlen(_Context->msg_DynamicSize[_Context->language]),_Context->value_DynamicSize|0);
	_Context->trigger_SaveForms=visual_trigger_code(_Context->msg_SaveForms[_Context->language],strlen(_Context->msg_SaveForms[_Context->language]));
	visual_check(_Context->x_auto1+370,_Context->y_auto1+130,126,16,vfh[2],26,0,_Context->msg_SaveForms[_Context->language],strlen(_Context->msg_SaveForms[_Context->language]),_Context->value_SaveForms|0);
	_Context->trigger_SaveImages=visual_trigger_code(_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]));
	visual_check(_Context->x_auto1+370,_Context->y_auto1+150,126,16,vfh[2],26,0,_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]),_Context->value_SaveImages|0);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+270,110,20,vfh[2],27,0,_Context->msg_Auto1557[_Context->language],strlen(_Context->msg_Auto1557[_Context->language]),2);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+300,110,20,vfh[2],27,0,_Context->msg_Auto1738[_Context->language],strlen(_Context->msg_Auto1738[_Context->language]),2);
	visual_text(_Context->x_auto1+20,_Context->y_auto1+330,110,20,vfh[2],27,0,_Context->msg_Auto1558[_Context->language],strlen(_Context->msg_Auto1558[_Context->language]),2);
	visual_text(_Context->x_auto1+430,_Context->y_auto1+330,56,16,vfh[2],27,0,_Context->msg_auto702[_Context->language],strlen(_Context->msg_auto702[_Context->language]),2);
	visual_frame(_Context->x_auto1+130,_Context->y_auto1+270,456+2,16+2,5);
	visual_text(_Context->x_auto1+130+1,_Context->y_auto1+270+1,456,16,vfh[1],26,0,_Context->buffer_ImageName,57,0);
	visual_frame(_Context->x_auto1+130,_Context->y_auto1+300,456+2,16+2,5);
	visual_text(_Context->x_auto1+130+1,_Context->y_auto1+300+1,456,16,vfh[1],26,0,_Context->buffer_PaletteName,57,0);
	visual_select(_Context->x_auto1+130,_Context->y_auto1+330,140,90,vfh[1],0,0,parse_selection(WidgetImageList,&_Context->value_ImageType),0);
	visual_frame(_Context->x_auto1+500,_Context->y_auto1+330,80+2,20+2,5);
	visual_text(_Context->x_auto1+500+1,_Context->y_auto1+330+1,80,20,vfh[1],26,0,_Context->buffer_Colour,10,0);
	_Context->trigger_Quality=visual_trigger_code(_Context->msg_Quality[_Context->language],strlen(_Context->msg_Quality[_Context->language]));
	visual_check(_Context->x_auto1+290,_Context->y_auto1+330,128,16,vfh[2],27,28,_Context->msg_Quality[_Context->language],strlen(_Context->msg_Quality[_Context->language]),_Context->value_Quality|0);
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto1+360,_Context->y_auto1+380,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
	visual_thaw(_Context->x_auto1,_Context->y_auto1,610,430);
	visual_thaw(_Context->x_auto1,_Context->y_auto1,610,430);

	return(0);
}

private int auto1action(struct accept_camera_properties_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_camera_properties_hide(_Context);

		_Context->x_auto1 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto1 < 0) { _Context->x_auto1=0; }
		_Context->y_auto1 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto1 < 0) { _Context->y_auto1=0; }
			accept_camera_properties_show(_Context);

		visual_thaw(_Context->x_auto1,_Context->y_auto1,610,430);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_camera_properties_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_camera_properties_context * _Context) {
	return(27);
	return(-1);
}
private int on_Select_event(struct accept_camera_properties_context * _Context) {
	use_file_selector(_Context->buffer_ImageName,WIDGET_FILE_GIF);
		accept_camera_properties_show(_Context);
;
	return(-1);
}


public	int	accept_camera_properties_event(
struct accept_camera_properties_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(12);
		if (_Context->trigger_Cancel == mb ) return(13);
		if (_Context->trigger_DynamicSize == mb ) return(21);
		if (_Context->trigger_SaveForms == mb ) return(22);
		if (_Context->trigger_SaveImages == mb ) return(23);
		if (_Context->trigger_Quality == mb ) return(28);
		if (_Context->trigger_Select == mb ) return(29);
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
			visual_help("vcamera.htm");
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
		accept_camera_properties_show(_Context);
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
		return(2); /* Name */
		}
	if (( mx >= (_Context->x_auto1+130) ) 
	&&  ( my >= (_Context->y_auto1+90) ) 
	&&  ( mx <= (_Context->x_auto1+130+80) ) 
	&&  ( my <= (_Context->y_auto1+90+16))) {
		return(3); /* AtX */
		}
	if (( mx >= (_Context->x_auto1+250) ) 
	&&  ( my >= (_Context->y_auto1+90) ) 
	&&  ( mx <= (_Context->x_auto1+250+80) ) 
	&&  ( my <= (_Context->y_auto1+90+16))) {
		return(4); /* AtY */
		}
	if (( mx >= (_Context->x_auto1+370) ) 
	&&  ( my >= (_Context->y_auto1+90) ) 
	&&  ( mx <= (_Context->x_auto1+370+72) ) 
	&&  ( my <= (_Context->y_auto1+90+16))) {
		return(5); /* AtZ */
		}
	if (( mx >= (_Context->x_auto1+130) ) 
	&&  ( my >= (_Context->y_auto1+120) ) 
	&&  ( mx <= (_Context->x_auto1+130+80) ) 
	&&  ( my <= (_Context->y_auto1+120+16))) {
		return(6); /* ToX */
		}
	if (( mx >= (_Context->x_auto1+250) ) 
	&&  ( my >= (_Context->y_auto1+120) ) 
	&&  ( mx <= (_Context->x_auto1+250+80) ) 
	&&  ( my <= (_Context->y_auto1+120+16))) {
		return(7); /* ToY */
		}
	if (( mx >= (_Context->x_auto1+130+0) ) 
	&&  ( my >= (_Context->y_auto1+150) ) 
	&&  ( mx <= (_Context->x_auto1+130+200) ) 
	&&  ( my <= (_Context->y_auto1+150+16))) {
		return(8); /* Direction */
		}
	if (( mx >= (_Context->x_auto1+130) ) 
	&&  ( my >= (_Context->y_auto1+180) ) 
	&&  ( mx <= (_Context->x_auto1+130+200) ) 
	&&  ( my <= (_Context->y_auto1+180+16))) {
		return(9); /* Configuration */
		}
	if (( mx >= (_Context->x_auto1+370) ) 
	&&  ( my >= (_Context->y_auto1+180) ) 
	&&  ( mx <= (_Context->x_auto1+370+216) ) 
	&&  ( my <= (_Context->y_auto1+180+16))) {
		return(10); /* DataBase */
		}
	if (( mx >= (_Context->x_auto1+500) ) 
	&&  ( my >= (_Context->y_auto1+210) ) 
	&&  ( mx <= (_Context->x_auto1+500+88) ) 
	&&  ( my <= (_Context->y_auto1+210+16))) {
		return(11); /* Step */
		}
	if (( mx >= (_Context->x_auto1+20) ) 
	&&  ( my >= (_Context->y_auto1+380) ) 
	&&  ( mx <= (_Context->x_auto1+20+120) ) 
	&&  ( my <= (_Context->y_auto1+380+30))) {
		return(12); /* Accept */
		}
	if (( mx >= (_Context->x_auto1+470) ) 
	&&  ( my >= (_Context->y_auto1+380) ) 
	&&  ( mx <= (_Context->x_auto1+470+120) ) 
	&&  ( my <= (_Context->y_auto1+380+30))) {
		return(13); /* Cancel */
		}
	if (( mx >= (_Context->x_auto1+130) ) 
	&&  ( my >= (_Context->y_auto1+210) ) 
	&&  ( mx <= (_Context->x_auto1+130+80) ) 
	&&  ( my <= (_Context->y_auto1+210+16))) {
		return(14); /* NbX */
		}
	if (( mx >= (_Context->x_auto1+250) ) 
	&&  ( my >= (_Context->y_auto1+210) ) 
	&&  ( mx <= (_Context->x_auto1+250+80) ) 
	&&  ( my <= (_Context->y_auto1+210+16))) {
		return(15); /* nbY */
		}
	if (( mx >= (_Context->x_auto1+370) ) 
	&&  ( my >= (_Context->y_auto1+210) ) 
	&&  ( mx <= (_Context->x_auto1+370+80) ) 
	&&  ( my <= (_Context->y_auto1+210+16))) {
		return(16); /* NbZ */
		}
	if (( mx >= (_Context->x_auto1+130) ) 
	&&  ( my >= (_Context->y_auto1+240) ) 
	&&  ( mx <= (_Context->x_auto1+130+80) ) 
	&&  ( my <= (_Context->y_auto1+240+16))) {
		return(17); /* StepX */
		}
	if (( mx >= (_Context->x_auto1+250) ) 
	&&  ( my >= (_Context->y_auto1+240) ) 
	&&  ( mx <= (_Context->x_auto1+250+80) ) 
	&&  ( my <= (_Context->y_auto1+240+16))) {
		return(18); /* StepY */
		}
	if (( mx >= (_Context->x_auto1+370) ) 
	&&  ( my >= (_Context->y_auto1+240) ) 
	&&  ( mx <= (_Context->x_auto1+370+80) ) 
	&&  ( my <= (_Context->y_auto1+240+16))) {
		return(19); /* StepZ */
		}
	if (( mx >= (_Context->x_auto1+500+0) ) 
	&&  ( my >= (_Context->y_auto1+240) ) 
	&&  ( mx <= (_Context->x_auto1+500+88) ) 
	&&  ( my <= (_Context->y_auto1+240+16))) {
		return(20); /* ImageFormat */
		}
	if (( mx >= (_Context->x_auto1+370) ) 
	&&  ( my >= (_Context->y_auto1+110) ) 
	&&  ( mx <= (_Context->x_auto1+370+112) ) 
	&&  ( my <= (_Context->y_auto1+110+16))) {
		return(21); /* DynamicSize */
		}
	if (( mx >= (_Context->x_auto1+370) ) 
	&&  ( my >= (_Context->y_auto1+130) ) 
	&&  ( mx <= (_Context->x_auto1+370+126) ) 
	&&  ( my <= (_Context->y_auto1+130+16))) {
		return(22); /* SaveForms */
		}
	if (( mx >= (_Context->x_auto1+370) ) 
	&&  ( my >= (_Context->y_auto1+150) ) 
	&&  ( mx <= (_Context->x_auto1+370+126) ) 
	&&  ( my <= (_Context->y_auto1+150+16))) {
		return(23); /* SaveImages */
		}
	if (( mx >= (_Context->x_auto1+130) ) 
	&&  ( my >= (_Context->y_auto1+270) ) 
	&&  ( mx <= (_Context->x_auto1+130+456) ) 
	&&  ( my <= (_Context->y_auto1+270+16))) {
		return(24); /* ImageName */
		}
	if (( mx >= (_Context->x_auto1+130) ) 
	&&  ( my >= (_Context->y_auto1+300) ) 
	&&  ( mx <= (_Context->x_auto1+130+456) ) 
	&&  ( my <= (_Context->y_auto1+300+16))) {
		return(25); /* PaletteName */
		}
	if (( mx >= (_Context->x_auto1+130+0) ) 
	&&  ( my >= (_Context->y_auto1+330) ) 
	&&  ( mx <= (_Context->x_auto1+130+140) ) 
	&&  ( my <= (_Context->y_auto1+330+16))) {
		return(26); /* ImageType */
		}
	if (( mx >= (_Context->x_auto1+500) ) 
	&&  ( my >= (_Context->y_auto1+330) ) 
	&&  ( mx <= (_Context->x_auto1+500+80) ) 
	&&  ( my <= (_Context->y_auto1+330+20))) {
		return(27); /* Colour */
		}
	if (( mx >= (_Context->x_auto1+290) ) 
	&&  ( my >= (_Context->y_auto1+330) ) 
	&&  ( mx <= (_Context->x_auto1+290+128) ) 
	&&  ( my <= (_Context->y_auto1+330+16))) {
		return(28); /* Quality */
		}
	if (( mx >= (_Context->x_auto1+360) ) 
	&&  ( my >= (_Context->y_auto1+380) ) 
	&&  ( mx <= (_Context->x_auto1+360+100) ) 
	&&  ( my <= (_Context->y_auto1+380+30))) {
		return(29); /* Select */
		}

	return(-1);
}


public	int	accept_camera_properties_focus(struct accept_camera_properties_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Name */
				_Context->keycode = visual_edit(_Context->x_auto1+130+1,_Context->y_auto1+60+1,456,16,vfh[1],_Context->buffer_Name,57);
			break;
			case	0x3 :
				/* AtX */
				_Context->keycode = visual_edit(_Context->x_auto1+130+1,_Context->y_auto1+90+1,80,16,vfh[1],_Context->buffer_AtX,10);
			break;
			case	0x4 :
				/* AtY */
				_Context->keycode = visual_edit(_Context->x_auto1+250+1,_Context->y_auto1+90+1,80,16,vfh[1],_Context->buffer_AtY,10);
			break;
			case	0x5 :
				/* AtZ */
				_Context->keycode = visual_edit(_Context->x_auto1+370+1,_Context->y_auto1+90+1,72,16,vfh[1],_Context->buffer_AtZ,9);
			break;
			case	0x6 :
				/* ToX */
				_Context->keycode = visual_edit(_Context->x_auto1+130+1,_Context->y_auto1+120+1,80,16,vfh[1],_Context->buffer_ToX,10);
			break;
			case	0x7 :
				/* ToY */
				_Context->keycode = visual_edit(_Context->x_auto1+250+1,_Context->y_auto1+120+1,80,16,vfh[1],_Context->buffer_ToY,10);
			break;
			case	0x8 :
				/* Direction */
				_Context->keycode = visual_select(_Context->x_auto1+130,_Context->y_auto1+150,200,80,vfh[1],26,0,parse_selection(_Context->msg_Direction[_Context->language],&_Context->value_Direction),514);
				break;
			case	0x9 :
				/* Configuration */
				_Context->keycode = visual_edit(_Context->x_auto1+130+1,_Context->y_auto1+180+1,200,16,vfh[1],_Context->buffer_Configuration,25);
			break;
			case	0xa :
				/* DataBase */
				_Context->keycode = visual_edit(_Context->x_auto1+370+1,_Context->y_auto1+180+1,216,16,vfh[1],_Context->buffer_DataBase,27);
			break;
			case	0xb :
				/* Step */
				_Context->keycode = visual_edit(_Context->x_auto1+500+1,_Context->y_auto1+210+1,88,16,vfh[1],_Context->buffer_Step,11);
			break;
			case	0xc :
				/* Accept */
				visual_button(_Context->x_auto1+20,_Context->y_auto1+380,120,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto1+20,_Context->y_auto1+380,120,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0xd :
				/* Cancel */
				visual_button(_Context->x_auto1+470,_Context->y_auto1+380,120,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto1+470,_Context->y_auto1+380,120,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0xe :
				/* NbX */
				_Context->keycode = visual_edit(_Context->x_auto1+130+1,_Context->y_auto1+210+1,80,16,vfh[1],_Context->buffer_NbX,10);
			break;
			case	0xf :
				/* nbY */
				_Context->keycode = visual_edit(_Context->x_auto1+250+1,_Context->y_auto1+210+1,80,16,vfh[1],_Context->buffer_nbY,10);
			break;
			case	0x10 :
				/* NbZ */
				_Context->keycode = visual_edit(_Context->x_auto1+370+1,_Context->y_auto1+210+1,80,16,vfh[1],_Context->buffer_NbZ,10);
			break;
			case	0x11 :
				/* StepX */
				_Context->keycode = visual_edit(_Context->x_auto1+130+1,_Context->y_auto1+240+1,80,16,vfh[1],_Context->buffer_StepX,10);
			break;
			case	0x12 :
				/* StepY */
				_Context->keycode = visual_edit(_Context->x_auto1+250+1,_Context->y_auto1+240+1,80,16,vfh[1],_Context->buffer_StepY,10);
			break;
			case	0x13 :
				/* StepZ */
				_Context->keycode = visual_edit(_Context->x_auto1+370+1,_Context->y_auto1+240+1,80,16,vfh[1],_Context->buffer_StepZ,10);
			break;
			case	0x14 :
				/* ImageFormat */
				_Context->keycode = visual_select(_Context->x_auto1+500,_Context->y_auto1+240,88,96,vfh[1],0,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),2);
				break;
			case	0x15 :
				/* DynamicSize */
				visual_check(_Context->x_auto1+370,_Context->y_auto1+110,112,16,vfh[2],26,0,_Context->msg_DynamicSize[_Context->language],strlen(_Context->msg_DynamicSize[_Context->language]),(_Context->value_DynamicSize |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto1+370,_Context->y_auto1+110,112,16,vfh[2],26,0,_Context->msg_DynamicSize[_Context->language],strlen(_Context->msg_DynamicSize[_Context->language]),(_Context->value_DynamicSize |0));
				break;
			case	0x16 :
				/* SaveForms */
				visual_check(_Context->x_auto1+370,_Context->y_auto1+130,126,16,vfh[2],26,0,_Context->msg_SaveForms[_Context->language],strlen(_Context->msg_SaveForms[_Context->language]),(_Context->value_SaveForms |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto1+370,_Context->y_auto1+130,126,16,vfh[2],26,0,_Context->msg_SaveForms[_Context->language],strlen(_Context->msg_SaveForms[_Context->language]),(_Context->value_SaveForms |0));
				break;
			case	0x17 :
				/* SaveImages */
				visual_check(_Context->x_auto1+370,_Context->y_auto1+150,126,16,vfh[2],26,0,_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]),(_Context->value_SaveImages |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto1+370,_Context->y_auto1+150,126,16,vfh[2],26,0,_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]),(_Context->value_SaveImages |0));
				break;
			case	0x18 :
				/* ImageName */
				_Context->keycode = visual_edit(_Context->x_auto1+130+1,_Context->y_auto1+270+1,456,16,vfh[1],_Context->buffer_ImageName,57);
			break;
			case	0x19 :
				/* PaletteName */
				_Context->keycode = visual_edit(_Context->x_auto1+130+1,_Context->y_auto1+300+1,456,16,vfh[1],_Context->buffer_PaletteName,57);
			break;
			case	0x1a :
				/* ImageType */
				_Context->keycode = visual_select(_Context->x_auto1+130,_Context->y_auto1+330,140,90,vfh[1],0,0,parse_selection(WidgetImageList,&_Context->value_ImageType),2);
				break;
			case	0x1b :
				/* Colour */
				_Context->keycode = visual_edit(_Context->x_auto1+500+1,_Context->y_auto1+330+1,80,20,vfh[1],_Context->buffer_Colour,10);
			break;
			case	0x1c :
				/* Quality */
				visual_check(_Context->x_auto1+290,_Context->y_auto1+330,128,16,vfh[2],27,28,_Context->msg_Quality[_Context->language],strlen(_Context->msg_Quality[_Context->language]),(_Context->value_Quality |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto1+290,_Context->y_auto1+330,128,16,vfh[2],27,28,_Context->msg_Quality[_Context->language],strlen(_Context->msg_Quality[_Context->language]),(_Context->value_Quality |0));
				break;
			case	0x1d :
				/* Select */
				visual_button(_Context->x_auto1+360,_Context->y_auto1+380,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto1+360,_Context->y_auto1+380,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_camera_properties_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=29;
			accept_camera_properties_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_camera_properties_event(_Context)) == -1)
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
						/* Name */
						continue;
					case	0x3 :
						/* AtX */
						continue;
					case	0x4 :
						/* AtY */
						continue;
					case	0x5 :
						/* AtZ */
						continue;
					case	0x6 :
						/* ToX */
						continue;
					case	0x7 :
						/* ToY */
						continue;
					case	0x8 :
						/* Direction */
						continue;
					case	0x9 :
						/* Configuration */
						continue;
					case	0xa :
						/* DataBase */
						continue;
					case	0xb :
						/* Step */
						continue;
					case	0xc :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto1+20,_Context->y_auto1+380,120,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto1+20,_Context->y_auto1+380,120,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0xd :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto1+470,_Context->y_auto1+380,120,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto1+470,_Context->y_auto1+380,120,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
						continue;
					case	0xe :
						/* NbX */
						continue;
					case	0xf :
						/* nbY */
						continue;
					case	0x10 :
						/* NbZ */
						continue;
					case	0x11 :
						/* StepX */
						continue;
					case	0x12 :
						/* StepY */
						continue;
					case	0x13 :
						/* StepZ */
						continue;
					case	0x14 :
						/* ImageFormat */
						continue;
					case	0x15 :
						/* DynamicSize */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_DynamicSize += 1;
							_Context->value_DynamicSize &= 1;
							}
						continue;
					case	0x16 :
						/* SaveForms */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SaveForms += 1;
							_Context->value_SaveForms &= 1;
							}
						continue;
					case	0x17 :
						/* SaveImages */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SaveImages += 1;
							_Context->value_SaveImages &= 1;
							}
						continue;
					case	0x18 :
						/* ImageName */
						continue;
					case	0x19 :
						/* PaletteName */
						continue;
					case	0x1a :
						/* ImageType */
						continue;
					case	0x1b :
						/* Colour */
						continue;
					case	0x1c :
						/* Quality */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Quality += 1;
							_Context->value_Quality &= 1;
							}
						continue;
					case	0x1d :
						/* Select */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto1+360,_Context->y_auto1+380,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto1+360,_Context->y_auto1+380,100,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Select_event(_Context)) != -1) break;

							}
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
				_Context->focus_item=29;
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

public	int	accept_camera_properties(
	char * pName,
	char * pAtX,
	char * pAtY,
	char * pAtZ,
	char * pToX,
	char * pToY,
	char * pDirection,
	char * pConfiguration,
	char * pDataBase,
	char * pStep,
	char * pNbX,
	char * pnbY,
	char * pNbZ,
	char * pStepX,
	char * pStepY,
	char * pStepZ,
	char * pImageFormat,
	char * pDynamicSize,
	char * pSaveForms,
	char * pSaveImages,
	char * pImageName,
	char * pPaletteName,
	char * pImageType,
	char * pColour,
	char * pQuality)
{
	int	status=0;
	struct accept_camera_properties_context * _Context=(struct accept_camera_properties_context*) 0;
	status = accept_camera_properties_create(
	&_Context,
	 pName,
	 pAtX,
	 pAtY,
	 pAtZ,
	 pToX,
	 pToY,
	 pDirection,
	 pConfiguration,
	 pDataBase,
	 pStep,
	 pNbX,
	 pnbY,
	 pNbZ,
	 pStepX,
	 pStepY,
	 pStepZ,
	 pImageFormat,
	 pDynamicSize,
	 pSaveForms,
	 pSaveImages,
	 pImageName,
	 pPaletteName,
	 pImageType,
	 pColour,
	 pQuality);
	if ( status != 0) return(status);
	status = accept_camera_properties_show(_Context);
		enter_modal();
	status = accept_camera_properties_focus(_Context);
		leave_modal();
	status = accept_camera_properties_hide(_Context);
	status = accept_camera_properties_remove(
	_Context,
	 pName,
	 pAtX,
	 pAtY,
	 pAtZ,
	 pToX,
	 pToY,
	 pDirection,
	 pConfiguration,
	 pDataBase,
	 pStep,
	 pNbX,
	 pnbY,
	 pNbZ,
	 pStepX,
	 pStepY,
	 pStepZ,
	 pImageFormat,
	 pDynamicSize,
	 pSaveForms,
	 pSaveImages,
	 pImageName,
	 pPaletteName,
	 pImageType,
	 pColour,
	 pQuality);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcamera_c */
