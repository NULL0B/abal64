
#ifndef _xcamera_c
#define _xcamera_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.02                                                */
/* Production     : C                                                        */
/* Project        : xcamera.xml                                              */
/* Target         : xcamera.c                                                */
/* Identification : 0.0-1158305776-2831.2412                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Auto141   "Sing : Version 1.0a"
#define en_Accept   "ok.gif"
#define fr_Accept   "ok.gif"
#define it_Accept   "ok.gif"
#define es_Accept   "ok.gif"
#define de_Accept   "ok.gif"
#define nl_Accept   "ok.gif"
#define pt_Accept   "ok.gif"
#define xx_Accept   "ok.gif"
#define en__Accept   ""
#define fr__Accept   ""
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"
#define en__Cancel   ""
#define fr__Cancel   ""
#define en_Auto142   "Directories"
#define en__Auto142   ""
#define en_Auto143   "Name"
#define fr_Auto143   "Nom"
#define it_Auto143   "Name"
#define es_Auto143   "Name"
#define de_Auto143   "Name"
#define nl_Auto143   "Name"
#define pt_Auto143   "Name"
#define xx_Auto143   "Name"
#define en_Auto144   "Configuration"
#define fr_Auto144   "Configuration"
#define it_Auto144   "Configuration"
#define es_Auto144   "Configuration"
#define de_Auto144   "Configuration"
#define nl_Auto144   "Configuration"
#define pt_Auto144   "Configuration"
#define xx_Auto144   "Configuration"
#define en_Auto145   "Template"
#define fr_Auto145   "Template"
#define it_Auto145   "Template"
#define es_Auto145   "Template"
#define de_Auto145   "Template"
#define nl_Auto145   "Template"
#define pt_Auto145   "Template"
#define xx_Auto145   "Template"
#define en__Auto145   ""
#define en_Auto146   "Modules"
#define fr_Auto146   "Modules"
#define it_Auto146   "Template"
#define es_Auto146   "Template"
#define de_Auto146   "Template"
#define nl_Auto146   "Template"
#define pt_Auto146   "Template"
#define xx_Auto146   "Template"
#define en__Auto146   ""
#define fr__Auto146   ""
#define en_Auto147   "Forms Directory"
#define fr_Auto147   "Rep. formulaires"
#define it_Auto147   "Forms Directory"
#define es_Auto147   "Forms Directory"
#define de_Auto147   "Forms Directory"
#define nl_Auto147   "Forms Directory"
#define pt_Auto147   "Forms Directory"
#define xx_Auto147   "Forms Directory"
#define en__Auto147   ""
#define fr__Auto147   ""
#define en_Auto148   "Sources Directory"
#define fr_Auto148   "Rep. Sources"
#define it_Auto148   "Sources Directory"
#define es_Auto148   "Sources Directory"
#define de_Auto148   "Sources Directory"
#define nl_Auto148   "Sources Directory"
#define pt_Auto148   "Sources Directory"
#define xx_Auto148   "Sources Directory"
#define en__Auto148   ""
#define fr__Auto148   ""
#define en_Auto149   "Binary Directory"
#define fr_Auto149   "Rep. binaires"
#define it_Auto149   "Binary Directory"
#define es_Auto149   "Binary Directory"
#define de_Auto149   "Binary Directory"
#define nl_Auto149   "Binary Directory"
#define pt_Auto149   "Binary Directory"
#define xx_Auto149   "Binary Directory"
#define en__Auto149   ""
#define fr__Auto149   ""
#define en_Auto150   "Background Image"
#define fr_Auto150   "Image de Fond"
#define it_Auto150   "Background Image"
#define es_Auto150   "Background Image"
#define de_Auto150   "Background Image"
#define nl_Auto150   "Background Image"
#define pt_Auto150   "Background Image"
#define xx_Auto150   "Background Image"
#define en__Auto150   ""
#define fr__Auto150   ""
#define en_Auto151   "Stylesheet"
#define fr_Auto151   "Image de Fond"
#define it_Auto151   "Background Image"
#define es_Auto151   "Background Image"
#define de_Auto151   "Background Image"
#define nl_Auto151   "Background Image"
#define pt_Auto151   "Background Image"
#define xx_Auto151   "Background Image"
#define en__Auto151   ""
#define fr__Auto151   ""
#define en_Auto152   "Palette"
#define fr_Auto152   "Palette"
#define it_Auto152   "Palette"
#define es_Auto152   "Palette"
#define de_Auto152   "Palette"
#define nl_Auto152   "Palette"
#define pt_Auto152   "Palette"
#define xx_Auto152   "Palette"
#define en__Auto152   ""
#define fr__Auto152   ""
#define en_TitreDataBase   "Data Base"
#define fr_TitreDataBase   "Base de donn‚es"
#define it_TitreDataBase   "Data Base"
#define es_TitreDataBase   "Data Base"
#define de_TitreDataBase   "Data Base"
#define nl_TitreDataBase   "Data Base"
#define pt_TitreDataBase   "Data Base"
#define xx_TitreDataBase   "Data Base"
#define en__TitreDataBase   ""
#define fr__TitreDataBase   ""
#define it__TitreDataBase   ""
#define es__TitreDataBase   ""
#define de__TitreDataBase   ""
#define nl__TitreDataBase   ""
#define pt__TitreDataBase   ""
#define xx__TitreDataBase   ""
#define en_Name   ""
#define en_Configuration   ""
#define en__Configuration   ""
#define en_Choixfconf   "..."
#define fr_Choixfconf   "..."
#define it_Choixfconf   "..."
#define es_Choixfconf   "..."
#define de_Choixfconf   "..."
#define nl_Choixfconf   "..."
#define pt_Choixfconf   "..."
#define xx_Choixfconf   "..."
#define en__Choixfconf   ""
#define en_DataBase   ""
#define en__DataBase   ""
#define en_ChoixBase   "..."
#define fr_ChoixBase   "..."
#define it_ChoixBase   "..."
#define es_ChoixBase   "..."
#define de_ChoixBase   "..."
#define nl_ChoixBase   "..."
#define pt_ChoixBase   "..."
#define xx_ChoixBase   "..."
#define en__ChoixBase   ""
#define en_Template   ""
#define en__Template   ""
#define en_ChoixTemplate   "..."
#define fr_ChoixTemplate   "..."
#define it_ChoixTemplate   "..."
#define es_ChoixTemplate   "..."
#define de_ChoixTemplate   "..."
#define nl_ChoixTemplate   "..."
#define pt_ChoixTemplate   "..."
#define xx_ChoixTemplate   "..."
#define en__ChoixTemplate   ""
#define en_Modules   ""
#define en__Modules   ""
#define en_ChoixModules   "..."
#define fr_ChoixModules   "..."
#define it_ChoixModules   "..."
#define es_ChoixModules   "..."
#define de_ChoixModules   "..."
#define nl_ChoixModules   "..."
#define pt_ChoixModules   "..."
#define xx_ChoixModules   "..."
#define en__ChoixModules   ""
#define en_FormsDirectory   ""
#define fr_FormsDirectory   ""
#define en__FormsDirectory   ""
#define fr__FormsDirectory   ""
#define en_ChoixForms   "..."
#define fr_ChoixForms   "..."
#define it_ChoixForms   "..."
#define es_ChoixForms   "..."
#define de_ChoixForms   "..."
#define nl_ChoixForms   "..."
#define pt_ChoixForms   "..."
#define xx_ChoixForms   "..."
#define en__ChoixForms   ""
#define fr__ChoixForms   ""
#define it__ChoixForms   ""
#define es__ChoixForms   ""
#define de__ChoixForms   ""
#define nl__ChoixForms   ""
#define pt__ChoixForms   ""
#define xx__ChoixForms   ""
#define en_SourcesDirectory   ""
#define fr_SourcesDirectory   ""
#define en__SourcesDirectory   ""
#define fr__SourcesDirectory   ""
#define en_ChoixSrcDir   "..."
#define fr_ChoixSrcDir   "..."
#define it_ChoixSrcDir   "..."
#define es_ChoixSrcDir   "..."
#define de_ChoixSrcDir   "..."
#define nl_ChoixSrcDir   "..."
#define pt_ChoixSrcDir   "..."
#define xx_ChoixSrcDir   "..."
#define en__ChoixSrcDir   ""
#define en_ObjectsDirectory   ""
#define fr_ObjectsDirectory   ""
#define en__ObjectsDirectory   ""
#define fr__ObjectsDirectory   ""
#define en_ChoixObjDir   "..."
#define fr_ChoixObjDir   "..."
#define it_ChoixObjDir   "..."
#define es_ChoixObjDir   "..."
#define de_ChoixObjDir   "..."
#define nl_ChoixObjDir   "..."
#define pt_ChoixObjDir   "..."
#define xx_ChoixObjDir   "..."
#define en__ChoixObjDir   ""
#define en_PaletteName   ""
#define fr_PaletteName   ""
#define en__PaletteName   ""
#define fr__PaletteName   ""
#define en_ChoixPalette   "..."
#define fr_ChoixPalette   "..."
#define it_ChoixPalette   "..."
#define es_ChoixPalette   "..."
#define de_ChoixPalette   "..."
#define nl_ChoixPalette   "..."
#define pt_ChoixPalette   "..."
#define xx_ChoixPalette   "..."
#define en__ChoixPalette   ""
#define en_ImageName   ""
#define fr_ImageName   ""
#define en__ImageName   ""
#define fr__ImageName   ""
#define en_ChoixImgName   "..."
#define fr_ChoixImgName   "..."
#define it_ChoixImgName   "..."
#define es_ChoixImgName   "..."
#define de_ChoixImgName   "..."
#define nl_ChoixImgName   "..."
#define pt_ChoixImgName   "..."
#define xx_ChoixImgName   "..."
#define en__ChoixImgName   ""
#define fr__ChoixImgName   ""
#define en_StyleSheet   ""
#define fr_StyleSheet   ""
#define en__StyleSheet   ""
#define fr__StyleSheet   ""
#define en_ChoixStyle   "..."
#define fr_ChoixStyle   "..."
#define it_ChoixStyle   "..."
#define es_ChoixStyle   "..."
#define de_ChoixStyle   "..."
#define nl_ChoixStyle   "..."
#define pt_ChoixStyle   "..."
#define xx_ChoixStyle   "..."
#define en__ChoixStyle   ""
#define fr__ChoixStyle   ""
#define en_SaveImages   "Save &Images"
#define fr_SaveImages   "Sa&uve Images"
#define it_SaveImages   "Save &Images"
#define es_SaveImages   "Save &Images"
#define de_SaveImages   "Save &Images"
#define nl_SaveImages   "Save &Images"
#define pt_SaveImages   "Save &Images"
#define xx_SaveImages   "Save &Images"
#define en__SaveImages   ""
#define fr__SaveImages   ""
#define en_Quality   "&Quality"
#define fr_Quality   "&Qualit‚"
#define it_Quality   "&Quality"
#define es_Quality   "&Quality"
#define de_Quality   "&Quality"
#define nl_Quality   "&Quality"
#define pt_Quality   "&Quality"
#define xx_Quality   "&Quality"
#define en__Quality   ""
#define fr__Quality   ""
#define en_ApplyStyle   "&Apply Style"
#define fr_ApplyStyle   "&Qualit‚"
#define it_ApplyStyle   "&Quality"
#define es_ApplyStyle   "&Quality"
#define de_ApplyStyle   "&Quality"
#define nl_ApplyStyle   "&Quality"
#define pt_ApplyStyle   "&Quality"
#define xx_ApplyStyle   "&Quality"
#define en__ApplyStyle   ""
#define fr__ApplyStyle   ""
#define en__ImageFormat   ""
#define fr__ImageFormat   ""
#define it__ImageFormat   ""
#define es__ImageFormat   ""
#define de__ImageFormat   ""
#define nl__ImageFormat   ""
#define pt__ImageFormat   ""
#define xx__ImageFormat   ""
#define en__ImageType   ""
#define fr__ImageType   ""
#define it__ImageType   ""
#define es__ImageType   ""
#define de__ImageType   ""
#define nl__ImageType   ""
#define pt__ImageType   ""
#define xx__ImageType   ""
#define en_Auto153   "3D Viewer"
#define en__Auto153   ""

private struct new_accept_camera_properties_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[2+1];
	char * msg_Auto141[8];
	char * hint_Auto141[8];
	int	x_Auto141;
	int	y_Auto141;
	int	w_Auto141;
	int	h_Auto141;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	char * msg_Auto142[8];
	int	trigger_Auto142;
	char * hint_Auto142[8];
	int	page_number;
	char * msg_Auto143[8];
	char * hint_Auto143[8];
	char * msg_Auto144[8];
	char * hint_Auto144[8];
	char * msg_Auto145[8];
	char * hint_Auto145[8];
	char * msg_Auto146[8];
	char * hint_Auto146[8];
	char * msg_Auto147[8];
	char * hint_Auto147[8];
	char * msg_Auto148[8];
	char * hint_Auto148[8];
	char * msg_Auto149[8];
	char * hint_Auto149[8];
	char * msg_Auto150[8];
	char * hint_Auto150[8];
	char * msg_Auto151[8];
	char * hint_Auto151[8];
	char * msg_Auto152[8];
	char * hint_Auto152[8];
	char * msg_TitreDataBase[8];
	char * hint_TitreDataBase[8];
	char * hint_Name[8];
	char	buffer_Name[256];
	char * hint_Configuration[8];
	char	buffer_Configuration[256];
	char * msg_Choixfconf[8];
	int	trigger_Choixfconf;
	char * hint_Choixfconf[8];
	char * hint_DataBase[8];
	char	buffer_DataBase[256];
	char * msg_ChoixBase[8];
	int	trigger_ChoixBase;
	char * hint_ChoixBase[8];
	char * hint_Template[8];
	char	buffer_Template[256];
	char * msg_ChoixTemplate[8];
	int	trigger_ChoixTemplate;
	char * hint_ChoixTemplate[8];
	char * hint_Modules[8];
	char	buffer_Modules[401];
	char * msg_ChoixModules[8];
	int	trigger_ChoixModules;
	char * hint_ChoixModules[8];
	char * hint_FormsDirectory[8];
	char	buffer_FormsDirectory[256];
	char * msg_ChoixForms[8];
	int	trigger_ChoixForms;
	char * hint_ChoixForms[8];
	char * hint_SourcesDirectory[8];
	char	buffer_SourcesDirectory[256];
	char * msg_ChoixSrcDir[8];
	int	trigger_ChoixSrcDir;
	char * hint_ChoixSrcDir[8];
	char * hint_ObjectsDirectory[8];
	char	buffer_ObjectsDirectory[256];
	char * msg_ChoixObjDir[8];
	int	trigger_ChoixObjDir;
	char * hint_ChoixObjDir[8];
	char * hint_PaletteName[8];
	char	buffer_PaletteName[256];
	char * msg_ChoixPalette[8];
	int	trigger_ChoixPalette;
	char * hint_ChoixPalette[8];
	char * hint_ImageName[8];
	char	buffer_ImageName[256];
	char * msg_ChoixImgName[8];
	int	trigger_ChoixImgName;
	char * hint_ChoixImgName[8];
	char * hint_StyleSheet[8];
	char	buffer_StyleSheet[256];
	char * msg_ChoixStyle[8];
	int	trigger_ChoixStyle;
	char * hint_ChoixStyle[8];
	char * msg_SaveImages[8];
	int	trigger_SaveImages;
	char * hint_SaveImages[8];
	int	value_SaveImages;
	char * msg_Quality[8];
	int	trigger_Quality;
	char * hint_Quality[8];
	int	value_Quality;
	char * msg_ApplyStyle[8];
	int	trigger_ApplyStyle;
	char * hint_ApplyStyle[8];
	int	value_ApplyStyle;
	char * msg_ImageFormat[8];
	char * hint_ImageFormat[8];
	int	value_ImageFormat;
	char * msg_ImageType[8];
	char * hint_ImageType[8];
	int	value_ImageType;
	char * msg_Auto153[8];
	int	trigger_Auto153;
	char * hint_Auto153[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[17];
	};
static int	vfh[10];

public	int	new_accept_camera_properties_create(
	struct new_accept_camera_properties_context ** cptr,
	char * pName,
	char * pConfiguration,
	char * pDataBase,
	char * pTemplate,
	char * pModules,
	char * pFormsDirectory,
	char * pSourcesDirectory,
	char * pObjectsDirectory,
	char * pPaletteName,
	char * pImageName,
	char * pStyleSheet,
	char * pSaveImages,
	char * pQuality,
	char * pApplyStyle,
	char * pImageFormat,
	char * pImageType)
{

	int i;
	struct new_accept_camera_properties_context * _Context=(struct new_accept_camera_properties_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	if (!(_Context = allocate( sizeof( struct new_accept_camera_properties_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=26;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSSSSSSWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Name, 255, pName);
		visual_transferin(_Context->buffer_Configuration, 255, pConfiguration);
		visual_transferin(_Context->buffer_DataBase, 255, pDataBase);
		visual_transferin(_Context->buffer_Template, 255, pTemplate);
		visual_transferin(_Context->buffer_Modules, 400, pModules);
		visual_transferin(_Context->buffer_FormsDirectory, 255, pFormsDirectory);
		visual_transferin(_Context->buffer_SourcesDirectory, 255, pSourcesDirectory);
		visual_transferin(_Context->buffer_ObjectsDirectory, 255, pObjectsDirectory);
		visual_transferin(_Context->buffer_PaletteName, 255, pPaletteName);
		visual_transferin(_Context->buffer_ImageName, 255, pImageName);
		visual_transferin(_Context->buffer_StyleSheet, 255, pStyleSheet);
		visual_transferin((void *) 0, 0, pSaveImages);
		if (!( pSaveImages )) _Context->value_SaveImages=0;
		else	_Context->value_SaveImages = *((int *)pSaveImages);
		visual_transferin((void *) 0, 0, pQuality);
		if (!( pQuality )) _Context->value_Quality=0;
		else	_Context->value_Quality = *((int *)pQuality);
		visual_transferin((void *) 0, 0, pApplyStyle);
		if (!( pApplyStyle )) _Context->value_ApplyStyle=0;
		else	_Context->value_ApplyStyle = *((int *)pApplyStyle);
		visual_transferin((void *) 0, 0, pImageFormat);
		if (!( pImageFormat )) _Context->value_ImageFormat=0;
		else	_Context->value_ImageFormat = *((int *)pImageFormat);
		visual_transferin((void *) 0, 0, pImageType);
		if (!( pImageType )) _Context->value_ImageType=0;
		else	_Context->value_ImageType = *((int *)pImageType);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto141[i]=" ";
	_Context->msg_Auto141[0]=en_Auto141;
	_Context->x_Auto141=0;
	_Context->y_Auto141=0;
	_Context->w_Auto141=640;
	_Context->h_Auto141=610;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	_Context->hint_Accept[0]=en__Accept;
	_Context->hint_Accept[1]=fr__Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->msg_Cancel[2]=it_Cancel;
	_Context->msg_Cancel[3]=es_Cancel;
	_Context->msg_Cancel[4]=de_Cancel;
	_Context->msg_Cancel[5]=nl_Cancel;
	_Context->msg_Cancel[6]=pt_Cancel;
	_Context->msg_Cancel[7]=xx_Cancel;
	_Context->hint_Cancel[0]=en__Cancel;
	_Context->hint_Cancel[1]=fr__Cancel;
	for (i=0; i < 8; i++)_Context->msg_Auto142[i]=" ";
	_Context->msg_Auto142[0]=en_Auto142;
	_Context->hint_Auto142[0]=en__Auto142;
	_Context->focus_pages[1]=4;
	for (i=0; i < 8; i++)_Context->msg_Auto143[i]=" ";
	_Context->msg_Auto143[0]=en_Auto143;
	_Context->msg_Auto143[1]=fr_Auto143;
	_Context->msg_Auto143[2]=it_Auto143;
	_Context->msg_Auto143[3]=es_Auto143;
	_Context->msg_Auto143[4]=de_Auto143;
	_Context->msg_Auto143[5]=nl_Auto143;
	_Context->msg_Auto143[6]=pt_Auto143;
	_Context->msg_Auto143[7]=xx_Auto143;
	for (i=0; i < 8; i++)_Context->msg_Auto144[i]=" ";
	_Context->msg_Auto144[0]=en_Auto144;
	_Context->msg_Auto144[1]=fr_Auto144;
	_Context->msg_Auto144[2]=it_Auto144;
	_Context->msg_Auto144[3]=es_Auto144;
	_Context->msg_Auto144[4]=de_Auto144;
	_Context->msg_Auto144[5]=nl_Auto144;
	_Context->msg_Auto144[6]=pt_Auto144;
	_Context->msg_Auto144[7]=xx_Auto144;
	for (i=0; i < 8; i++)_Context->msg_Auto145[i]=" ";
	_Context->msg_Auto145[0]=en_Auto145;
	_Context->msg_Auto145[1]=fr_Auto145;
	_Context->msg_Auto145[2]=it_Auto145;
	_Context->msg_Auto145[3]=es_Auto145;
	_Context->msg_Auto145[4]=de_Auto145;
	_Context->msg_Auto145[5]=nl_Auto145;
	_Context->msg_Auto145[6]=pt_Auto145;
	_Context->msg_Auto145[7]=xx_Auto145;
	_Context->hint_Auto145[0]=en__Auto145;
	for (i=0; i < 8; i++)_Context->msg_Auto146[i]=" ";
	_Context->msg_Auto146[0]=en_Auto146;
	_Context->msg_Auto146[1]=fr_Auto146;
	_Context->msg_Auto146[2]=it_Auto146;
	_Context->msg_Auto146[3]=es_Auto146;
	_Context->msg_Auto146[4]=de_Auto146;
	_Context->msg_Auto146[5]=nl_Auto146;
	_Context->msg_Auto146[6]=pt_Auto146;
	_Context->msg_Auto146[7]=xx_Auto146;
	_Context->hint_Auto146[0]=en__Auto146;
	_Context->hint_Auto146[1]=fr__Auto146;
	for (i=0; i < 8; i++)_Context->msg_Auto147[i]=" ";
	_Context->msg_Auto147[0]=en_Auto147;
	_Context->msg_Auto147[1]=fr_Auto147;
	_Context->msg_Auto147[2]=it_Auto147;
	_Context->msg_Auto147[3]=es_Auto147;
	_Context->msg_Auto147[4]=de_Auto147;
	_Context->msg_Auto147[5]=nl_Auto147;
	_Context->msg_Auto147[6]=pt_Auto147;
	_Context->msg_Auto147[7]=xx_Auto147;
	_Context->hint_Auto147[0]=en__Auto147;
	_Context->hint_Auto147[1]=fr__Auto147;
	for (i=0; i < 8; i++)_Context->msg_Auto148[i]=" ";
	_Context->msg_Auto148[0]=en_Auto148;
	_Context->msg_Auto148[1]=fr_Auto148;
	_Context->msg_Auto148[2]=it_Auto148;
	_Context->msg_Auto148[3]=es_Auto148;
	_Context->msg_Auto148[4]=de_Auto148;
	_Context->msg_Auto148[5]=nl_Auto148;
	_Context->msg_Auto148[6]=pt_Auto148;
	_Context->msg_Auto148[7]=xx_Auto148;
	_Context->hint_Auto148[0]=en__Auto148;
	_Context->hint_Auto148[1]=fr__Auto148;
	for (i=0; i < 8; i++)_Context->msg_Auto149[i]=" ";
	_Context->msg_Auto149[0]=en_Auto149;
	_Context->msg_Auto149[1]=fr_Auto149;
	_Context->msg_Auto149[2]=it_Auto149;
	_Context->msg_Auto149[3]=es_Auto149;
	_Context->msg_Auto149[4]=de_Auto149;
	_Context->msg_Auto149[5]=nl_Auto149;
	_Context->msg_Auto149[6]=pt_Auto149;
	_Context->msg_Auto149[7]=xx_Auto149;
	_Context->hint_Auto149[0]=en__Auto149;
	_Context->hint_Auto149[1]=fr__Auto149;
	for (i=0; i < 8; i++)_Context->msg_Auto150[i]=" ";
	_Context->msg_Auto150[0]=en_Auto150;
	_Context->msg_Auto150[1]=fr_Auto150;
	_Context->msg_Auto150[2]=it_Auto150;
	_Context->msg_Auto150[3]=es_Auto150;
	_Context->msg_Auto150[4]=de_Auto150;
	_Context->msg_Auto150[5]=nl_Auto150;
	_Context->msg_Auto150[6]=pt_Auto150;
	_Context->msg_Auto150[7]=xx_Auto150;
	_Context->hint_Auto150[0]=en__Auto150;
	_Context->hint_Auto150[1]=fr__Auto150;
	for (i=0; i < 8; i++)_Context->msg_Auto151[i]=" ";
	_Context->msg_Auto151[0]=en_Auto151;
	_Context->msg_Auto151[1]=fr_Auto151;
	_Context->msg_Auto151[2]=it_Auto151;
	_Context->msg_Auto151[3]=es_Auto151;
	_Context->msg_Auto151[4]=de_Auto151;
	_Context->msg_Auto151[5]=nl_Auto151;
	_Context->msg_Auto151[6]=pt_Auto151;
	_Context->msg_Auto151[7]=xx_Auto151;
	_Context->hint_Auto151[0]=en__Auto151;
	_Context->hint_Auto151[1]=fr__Auto151;
	for (i=0; i < 8; i++)_Context->msg_Auto152[i]=" ";
	_Context->msg_Auto152[0]=en_Auto152;
	_Context->msg_Auto152[1]=fr_Auto152;
	_Context->msg_Auto152[2]=it_Auto152;
	_Context->msg_Auto152[3]=es_Auto152;
	_Context->msg_Auto152[4]=de_Auto152;
	_Context->msg_Auto152[5]=nl_Auto152;
	_Context->msg_Auto152[6]=pt_Auto152;
	_Context->msg_Auto152[7]=xx_Auto152;
	_Context->hint_Auto152[0]=en__Auto152;
	_Context->hint_Auto152[1]=fr__Auto152;
	for (i=0; i < 8; i++)_Context->msg_TitreDataBase[i]=" ";
	_Context->msg_TitreDataBase[0]=en_TitreDataBase;
	_Context->msg_TitreDataBase[1]=fr_TitreDataBase;
	_Context->msg_TitreDataBase[2]=it_TitreDataBase;
	_Context->msg_TitreDataBase[3]=es_TitreDataBase;
	_Context->msg_TitreDataBase[4]=de_TitreDataBase;
	_Context->msg_TitreDataBase[5]=nl_TitreDataBase;
	_Context->msg_TitreDataBase[6]=pt_TitreDataBase;
	_Context->msg_TitreDataBase[7]=xx_TitreDataBase;
	_Context->hint_TitreDataBase[0]=en__TitreDataBase;
	_Context->hint_TitreDataBase[1]=fr__TitreDataBase;
	_Context->hint_TitreDataBase[2]=it__TitreDataBase;
	_Context->hint_TitreDataBase[3]=es__TitreDataBase;
	_Context->hint_TitreDataBase[4]=de__TitreDataBase;
	_Context->hint_TitreDataBase[5]=nl__TitreDataBase;
	_Context->hint_TitreDataBase[6]=pt__TitreDataBase;
	_Context->hint_TitreDataBase[7]=xx__TitreDataBase;
	_Context->hint_Configuration[0]=en__Configuration;
	for (i=0; i < 8; i++)_Context->msg_Choixfconf[i]=" ";
	_Context->msg_Choixfconf[0]=en_Choixfconf;
	_Context->msg_Choixfconf[1]=fr_Choixfconf;
	_Context->msg_Choixfconf[2]=it_Choixfconf;
	_Context->msg_Choixfconf[3]=es_Choixfconf;
	_Context->msg_Choixfconf[4]=de_Choixfconf;
	_Context->msg_Choixfconf[5]=nl_Choixfconf;
	_Context->msg_Choixfconf[6]=pt_Choixfconf;
	_Context->msg_Choixfconf[7]=xx_Choixfconf;
	_Context->hint_Choixfconf[0]=en__Choixfconf;
	_Context->hint_DataBase[0]=en__DataBase;
	for (i=0; i < 8; i++)_Context->msg_ChoixBase[i]=" ";
	_Context->msg_ChoixBase[0]=en_ChoixBase;
	_Context->msg_ChoixBase[1]=fr_ChoixBase;
	_Context->msg_ChoixBase[2]=it_ChoixBase;
	_Context->msg_ChoixBase[3]=es_ChoixBase;
	_Context->msg_ChoixBase[4]=de_ChoixBase;
	_Context->msg_ChoixBase[5]=nl_ChoixBase;
	_Context->msg_ChoixBase[6]=pt_ChoixBase;
	_Context->msg_ChoixBase[7]=xx_ChoixBase;
	_Context->hint_ChoixBase[0]=en__ChoixBase;
	_Context->hint_Template[0]=en__Template;
	for (i=0; i < 8; i++)_Context->msg_ChoixTemplate[i]=" ";
	_Context->msg_ChoixTemplate[0]=en_ChoixTemplate;
	_Context->msg_ChoixTemplate[1]=fr_ChoixTemplate;
	_Context->msg_ChoixTemplate[2]=it_ChoixTemplate;
	_Context->msg_ChoixTemplate[3]=es_ChoixTemplate;
	_Context->msg_ChoixTemplate[4]=de_ChoixTemplate;
	_Context->msg_ChoixTemplate[5]=nl_ChoixTemplate;
	_Context->msg_ChoixTemplate[6]=pt_ChoixTemplate;
	_Context->msg_ChoixTemplate[7]=xx_ChoixTemplate;
	_Context->hint_ChoixTemplate[0]=en__ChoixTemplate;
	_Context->hint_Modules[0]=en__Modules;
	for (i=0; i < 8; i++)_Context->msg_ChoixModules[i]=" ";
	_Context->msg_ChoixModules[0]=en_ChoixModules;
	_Context->msg_ChoixModules[1]=fr_ChoixModules;
	_Context->msg_ChoixModules[2]=it_ChoixModules;
	_Context->msg_ChoixModules[3]=es_ChoixModules;
	_Context->msg_ChoixModules[4]=de_ChoixModules;
	_Context->msg_ChoixModules[5]=nl_ChoixModules;
	_Context->msg_ChoixModules[6]=pt_ChoixModules;
	_Context->msg_ChoixModules[7]=xx_ChoixModules;
	_Context->hint_ChoixModules[0]=en__ChoixModules;
	_Context->hint_FormsDirectory[0]=en__FormsDirectory;
	_Context->hint_FormsDirectory[1]=fr__FormsDirectory;
	for (i=0; i < 8; i++)_Context->msg_ChoixForms[i]=" ";
	_Context->msg_ChoixForms[0]=en_ChoixForms;
	_Context->msg_ChoixForms[1]=fr_ChoixForms;
	_Context->msg_ChoixForms[2]=it_ChoixForms;
	_Context->msg_ChoixForms[3]=es_ChoixForms;
	_Context->msg_ChoixForms[4]=de_ChoixForms;
	_Context->msg_ChoixForms[5]=nl_ChoixForms;
	_Context->msg_ChoixForms[6]=pt_ChoixForms;
	_Context->msg_ChoixForms[7]=xx_ChoixForms;
	_Context->hint_ChoixForms[0]=en__ChoixForms;
	_Context->hint_ChoixForms[1]=fr__ChoixForms;
	_Context->hint_ChoixForms[2]=it__ChoixForms;
	_Context->hint_ChoixForms[3]=es__ChoixForms;
	_Context->hint_ChoixForms[4]=de__ChoixForms;
	_Context->hint_ChoixForms[5]=nl__ChoixForms;
	_Context->hint_ChoixForms[6]=pt__ChoixForms;
	_Context->hint_ChoixForms[7]=xx__ChoixForms;
	_Context->hint_SourcesDirectory[0]=en__SourcesDirectory;
	_Context->hint_SourcesDirectory[1]=fr__SourcesDirectory;
	for (i=0; i < 8; i++)_Context->msg_ChoixSrcDir[i]=" ";
	_Context->msg_ChoixSrcDir[0]=en_ChoixSrcDir;
	_Context->msg_ChoixSrcDir[1]=fr_ChoixSrcDir;
	_Context->msg_ChoixSrcDir[2]=it_ChoixSrcDir;
	_Context->msg_ChoixSrcDir[3]=es_ChoixSrcDir;
	_Context->msg_ChoixSrcDir[4]=de_ChoixSrcDir;
	_Context->msg_ChoixSrcDir[5]=nl_ChoixSrcDir;
	_Context->msg_ChoixSrcDir[6]=pt_ChoixSrcDir;
	_Context->msg_ChoixSrcDir[7]=xx_ChoixSrcDir;
	_Context->hint_ChoixSrcDir[0]=en__ChoixSrcDir;
	_Context->hint_ObjectsDirectory[0]=en__ObjectsDirectory;
	_Context->hint_ObjectsDirectory[1]=fr__ObjectsDirectory;
	for (i=0; i < 8; i++)_Context->msg_ChoixObjDir[i]=" ";
	_Context->msg_ChoixObjDir[0]=en_ChoixObjDir;
	_Context->msg_ChoixObjDir[1]=fr_ChoixObjDir;
	_Context->msg_ChoixObjDir[2]=it_ChoixObjDir;
	_Context->msg_ChoixObjDir[3]=es_ChoixObjDir;
	_Context->msg_ChoixObjDir[4]=de_ChoixObjDir;
	_Context->msg_ChoixObjDir[5]=nl_ChoixObjDir;
	_Context->msg_ChoixObjDir[6]=pt_ChoixObjDir;
	_Context->msg_ChoixObjDir[7]=xx_ChoixObjDir;
	_Context->hint_ChoixObjDir[0]=en__ChoixObjDir;
	_Context->hint_PaletteName[0]=en__PaletteName;
	_Context->hint_PaletteName[1]=fr__PaletteName;
	for (i=0; i < 8; i++)_Context->msg_ChoixPalette[i]=" ";
	_Context->msg_ChoixPalette[0]=en_ChoixPalette;
	_Context->msg_ChoixPalette[1]=fr_ChoixPalette;
	_Context->msg_ChoixPalette[2]=it_ChoixPalette;
	_Context->msg_ChoixPalette[3]=es_ChoixPalette;
	_Context->msg_ChoixPalette[4]=de_ChoixPalette;
	_Context->msg_ChoixPalette[5]=nl_ChoixPalette;
	_Context->msg_ChoixPalette[6]=pt_ChoixPalette;
	_Context->msg_ChoixPalette[7]=xx_ChoixPalette;
	_Context->hint_ChoixPalette[0]=en__ChoixPalette;
	_Context->hint_ImageName[0]=en__ImageName;
	_Context->hint_ImageName[1]=fr__ImageName;
	for (i=0; i < 8; i++)_Context->msg_ChoixImgName[i]=" ";
	_Context->msg_ChoixImgName[0]=en_ChoixImgName;
	_Context->msg_ChoixImgName[1]=fr_ChoixImgName;
	_Context->msg_ChoixImgName[2]=it_ChoixImgName;
	_Context->msg_ChoixImgName[3]=es_ChoixImgName;
	_Context->msg_ChoixImgName[4]=de_ChoixImgName;
	_Context->msg_ChoixImgName[5]=nl_ChoixImgName;
	_Context->msg_ChoixImgName[6]=pt_ChoixImgName;
	_Context->msg_ChoixImgName[7]=xx_ChoixImgName;
	_Context->hint_ChoixImgName[0]=en__ChoixImgName;
	_Context->hint_ChoixImgName[1]=fr__ChoixImgName;
	_Context->hint_StyleSheet[0]=en__StyleSheet;
	_Context->hint_StyleSheet[1]=fr__StyleSheet;
	for (i=0; i < 8; i++)_Context->msg_ChoixStyle[i]=" ";
	_Context->msg_ChoixStyle[0]=en_ChoixStyle;
	_Context->msg_ChoixStyle[1]=fr_ChoixStyle;
	_Context->msg_ChoixStyle[2]=it_ChoixStyle;
	_Context->msg_ChoixStyle[3]=es_ChoixStyle;
	_Context->msg_ChoixStyle[4]=de_ChoixStyle;
	_Context->msg_ChoixStyle[5]=nl_ChoixStyle;
	_Context->msg_ChoixStyle[6]=pt_ChoixStyle;
	_Context->msg_ChoixStyle[7]=xx_ChoixStyle;
	_Context->hint_ChoixStyle[0]=en__ChoixStyle;
	_Context->hint_ChoixStyle[1]=fr__ChoixStyle;
	for (i=0; i < 8; i++)_Context->msg_SaveImages[i]=" ";
	_Context->msg_SaveImages[0]=en_SaveImages;
	_Context->msg_SaveImages[1]=fr_SaveImages;
	_Context->msg_SaveImages[2]=it_SaveImages;
	_Context->msg_SaveImages[3]=es_SaveImages;
	_Context->msg_SaveImages[4]=de_SaveImages;
	_Context->msg_SaveImages[5]=nl_SaveImages;
	_Context->msg_SaveImages[6]=pt_SaveImages;
	_Context->msg_SaveImages[7]=xx_SaveImages;
	_Context->hint_SaveImages[0]=en__SaveImages;
	_Context->hint_SaveImages[1]=fr__SaveImages;
	for (i=0; i < 8; i++)_Context->msg_Quality[i]=" ";
	_Context->msg_Quality[0]=en_Quality;
	_Context->msg_Quality[1]=fr_Quality;
	_Context->msg_Quality[2]=it_Quality;
	_Context->msg_Quality[3]=es_Quality;
	_Context->msg_Quality[4]=de_Quality;
	_Context->msg_Quality[5]=nl_Quality;
	_Context->msg_Quality[6]=pt_Quality;
	_Context->msg_Quality[7]=xx_Quality;
	_Context->hint_Quality[0]=en__Quality;
	_Context->hint_Quality[1]=fr__Quality;
	for (i=0; i < 8; i++)_Context->msg_ApplyStyle[i]=" ";
	_Context->msg_ApplyStyle[0]=en_ApplyStyle;
	_Context->msg_ApplyStyle[1]=fr_ApplyStyle;
	_Context->msg_ApplyStyle[2]=it_ApplyStyle;
	_Context->msg_ApplyStyle[3]=es_ApplyStyle;
	_Context->msg_ApplyStyle[4]=de_ApplyStyle;
	_Context->msg_ApplyStyle[5]=nl_ApplyStyle;
	_Context->msg_ApplyStyle[6]=pt_ApplyStyle;
	_Context->msg_ApplyStyle[7]=xx_ApplyStyle;
	_Context->hint_ApplyStyle[0]=en__ApplyStyle;
	_Context->hint_ApplyStyle[1]=fr__ApplyStyle;
	for (i=0; i < 8; i++)_Context->msg_ImageFormat[i]=" ";
	_Context->hint_ImageFormat[0]=en__ImageFormat;
	_Context->hint_ImageFormat[1]=fr__ImageFormat;
	_Context->hint_ImageFormat[2]=it__ImageFormat;
	_Context->hint_ImageFormat[3]=es__ImageFormat;
	_Context->hint_ImageFormat[4]=de__ImageFormat;
	_Context->hint_ImageFormat[5]=nl__ImageFormat;
	_Context->hint_ImageFormat[6]=pt__ImageFormat;
	_Context->hint_ImageFormat[7]=xx__ImageFormat;
	for (i=0; i < 8; i++)_Context->msg_ImageType[i]=" ";
	_Context->hint_ImageType[0]=en__ImageType;
	_Context->hint_ImageType[1]=fr__ImageType;
	_Context->hint_ImageType[2]=it__ImageType;
	_Context->hint_ImageType[3]=es__ImageType;
	_Context->hint_ImageType[4]=de__ImageType;
	_Context->hint_ImageType[5]=nl__ImageType;
	_Context->hint_ImageType[6]=pt__ImageType;
	_Context->hint_ImageType[7]=xx__ImageType;
	for (i=0; i < 8; i++)_Context->msg_Auto153[i]=" ";
	_Context->msg_Auto153[0]=en_Auto153;
	_Context->hint_Auto153[0]=en__Auto153;
	_Context->focus_pages[2]=26;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto141,_Context->y_Auto141,640,610);
	return(0);
}

public 	int	new_accept_camera_properties_hide(struct new_accept_camera_properties_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto141,_Context->y_Auto141);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	new_accept_camera_properties_remove(
	struct new_accept_camera_properties_context * _Context,
	char * pName,
	char * pConfiguration,
	char * pDataBase,
	char * pTemplate,
	char * pModules,
	char * pFormsDirectory,
	char * pSourcesDirectory,
	char * pObjectsDirectory,
	char * pPaletteName,
	char * pImageName,
	char * pStyleSheet,
	char * pSaveImages,
	char * pQuality,
	char * pApplyStyle,
	char * pImageFormat,
	char * pImageType)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSSSSSSWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Name, 255, pName);
		visual_transferout(_Context->buffer_Configuration, 255, pConfiguration);
		visual_transferout(_Context->buffer_DataBase, 255, pDataBase);
		visual_transferout(_Context->buffer_Template, 255, pTemplate);
		visual_transferout(_Context->buffer_Modules, 400, pModules);
		visual_transferout(_Context->buffer_FormsDirectory, 255, pFormsDirectory);
		visual_transferout(_Context->buffer_SourcesDirectory, 255, pSourcesDirectory);
		visual_transferout(_Context->buffer_ObjectsDirectory, 255, pObjectsDirectory);
		visual_transferout(_Context->buffer_PaletteName, 255, pPaletteName);
		visual_transferout(_Context->buffer_ImageName, 255, pImageName);
		visual_transferout(_Context->buffer_StyleSheet, 255, pStyleSheet);
		visual_transferout((void *) 0, 0, pSaveImages);
		if ( pSaveImages != (char *) 0)
			*((int*)pSaveImages) = _Context->value_SaveImages;
		visual_transferout((void *) 0, 0, pQuality);
		if ( pQuality != (char *) 0)
			*((int*)pQuality) = _Context->value_Quality;
		visual_transferout((void *) 0, 0, pApplyStyle);
		if ( pApplyStyle != (char *) 0)
			*((int*)pApplyStyle) = _Context->value_ApplyStyle;
		visual_transferout((void *) 0, 0, pImageFormat);
		if ( pImageFormat != (char *) 0)
			*((int*)pImageFormat) = _Context->value_ImageFormat;
		visual_transferout((void *) 0, 0, pImageType);
		if ( pImageType != (char *) 0)
			*((int*)pImageType) = _Context->value_ImageType;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	new_accept_camera_properties_show(struct new_accept_camera_properties_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto141,_Context->y_Auto141);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto141,_Context->y_Auto141,640,610,vfh[1],_Context->msg_Auto141[_Context->language],strlen(_Context->msg_Auto141[_Context->language]),0x4);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto141+260,_Context->y_Auto141+550,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto141+330,_Context->y_Auto141+550,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	if (_Context->page_number == 1 ) {
	_Context->trigger_Auto142=visual_trigger_code(_Context->msg_Auto142[_Context->language],strlen(_Context->msg_Auto142[_Context->language]));
	visual_tabpage(_Context->x_Auto141+10,_Context->y_Auto141+30,620,510,vfh[2],_Context->msg_Auto142[_Context->language],strlen(_Context->msg_Auto142[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_Auto141+10,_Context->y_Auto141+30,620,510,vfh[2],_Context->msg_Auto142[_Context->language],strlen(_Context->msg_Auto142[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto141+30,_Context->y_Auto141+70,112,16,vfh[2],27,0,_Context->msg_Auto143[_Context->language],strlen(_Context->msg_Auto143[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto141+30,_Context->y_Auto141+100,112,16,vfh[2],27,0,_Context->msg_Auto144[_Context->language],strlen(_Context->msg_Auto144[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto141+30,_Context->y_Auto141+160,112,16,vfh[2],27,0,_Context->msg_Auto145[_Context->language],strlen(_Context->msg_Auto145[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto141+30,_Context->y_Auto141+220,112,16,vfh[2],27,0,_Context->msg_Auto146[_Context->language],strlen(_Context->msg_Auto146[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto141+30,_Context->y_Auto141+250,112,16,vfh[2],27,0,_Context->msg_Auto147[_Context->language],strlen(_Context->msg_Auto147[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto141+30,_Context->y_Auto141+280,112,16,vfh[2],27,0,_Context->msg_Auto148[_Context->language],strlen(_Context->msg_Auto148[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto141+30,_Context->y_Auto141+310,112,16,vfh[2],27,0,_Context->msg_Auto149[_Context->language],strlen(_Context->msg_Auto149[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto141+30,_Context->y_Auto141+400,112,16,vfh[2],27,0,_Context->msg_Auto150[_Context->language],strlen(_Context->msg_Auto150[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto141+30,_Context->y_Auto141+460,574,16,vfh[2],27,22,_Context->msg_Auto151[_Context->language],strlen(_Context->msg_Auto151[_Context->language]),259);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto141+30,_Context->y_Auto141+360,112,16,vfh[2],27,0,_Context->msg_Auto152[_Context->language],strlen(_Context->msg_Auto152[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto141+30,_Context->y_Auto141+130,112,16,vfh[2],27,0,_Context->msg_TitreDataBase[_Context->language],strlen(_Context->msg_TitreDataBase[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto141+140,_Context->y_Auto141+70,432+2,16+2,5);
	visual_text(_Context->x_Auto141+140+1,_Context->y_Auto141+70+1,432,16,vfh[1],26,0,_Context->buffer_Name,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto141+140,_Context->y_Auto141+100,430+2,16+2,5);
	visual_text(_Context->x_Auto141+140+1,_Context->y_Auto141+100+1,430,16,vfh[1],26,0,_Context->buffer_Configuration,255,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Choixfconf=visual_trigger_code(_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]));
	visual_button(_Context->x_Auto141+580,_Context->y_Auto141+100,20,16,vfh[8],27,28,_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto141+140,_Context->y_Auto141+130,430+2,16+2,5);
	visual_text(_Context->x_Auto141+140+1,_Context->y_Auto141+130+1,430,16,vfh[1],26,0,_Context->buffer_DataBase,255,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ChoixBase=visual_trigger_code(_Context->msg_ChoixBase[_Context->language],strlen(_Context->msg_ChoixBase[_Context->language]));
	visual_button(_Context->x_Auto141+580,_Context->y_Auto141+130,20,16,vfh[8],27,28,_Context->msg_ChoixBase[_Context->language],strlen(_Context->msg_ChoixBase[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto141+140,_Context->y_Auto141+160,431+2,16+2,5);
	visual_text(_Context->x_Auto141+140+1,_Context->y_Auto141+160+1,431,16,vfh[1],26,0,_Context->buffer_Template,255,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ChoixTemplate=visual_trigger_code(_Context->msg_ChoixTemplate[_Context->language],strlen(_Context->msg_ChoixTemplate[_Context->language]));
	visual_button(_Context->x_Auto141+580,_Context->y_Auto141+160,20,16,vfh[8],27,28,_Context->msg_ChoixTemplate[_Context->language],strlen(_Context->msg_ChoixTemplate[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto141+140,_Context->y_Auto141+220,431+2,16+2,5);
	visual_text(_Context->x_Auto141+140+1,_Context->y_Auto141+220+1,431,16,vfh[1],26,0,_Context->buffer_Modules,400,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ChoixModules=visual_trigger_code(_Context->msg_ChoixModules[_Context->language],strlen(_Context->msg_ChoixModules[_Context->language]));
	visual_button(_Context->x_Auto141+580,_Context->y_Auto141+220,20,16,vfh[8],27,28,_Context->msg_ChoixModules[_Context->language],strlen(_Context->msg_ChoixModules[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto141+140,_Context->y_Auto141+250,430+2,16+2,5);
	visual_text(_Context->x_Auto141+140+1,_Context->y_Auto141+250+1,430,16,vfh[1],26,0,_Context->buffer_FormsDirectory,255,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ChoixForms=visual_trigger_code(_Context->msg_ChoixForms[_Context->language],strlen(_Context->msg_ChoixForms[_Context->language]));
	visual_button(_Context->x_Auto141+580,_Context->y_Auto141+250,20,16,vfh[8],27,28,_Context->msg_ChoixForms[_Context->language],strlen(_Context->msg_ChoixForms[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto141+140,_Context->y_Auto141+280,430+2,16+2,5);
	visual_text(_Context->x_Auto141+140+1,_Context->y_Auto141+280+1,430,16,vfh[1],26,0,_Context->buffer_SourcesDirectory,255,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ChoixSrcDir=visual_trigger_code(_Context->msg_ChoixSrcDir[_Context->language],strlen(_Context->msg_ChoixSrcDir[_Context->language]));
	visual_button(_Context->x_Auto141+580,_Context->y_Auto141+280,20,16,vfh[8],27,28,_Context->msg_ChoixSrcDir[_Context->language],strlen(_Context->msg_ChoixSrcDir[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto141+140,_Context->y_Auto141+310,430+2,16+2,5);
	visual_text(_Context->x_Auto141+140+1,_Context->y_Auto141+310+1,430,16,vfh[1],26,0,_Context->buffer_ObjectsDirectory,255,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ChoixObjDir=visual_trigger_code(_Context->msg_ChoixObjDir[_Context->language],strlen(_Context->msg_ChoixObjDir[_Context->language]));
	visual_button(_Context->x_Auto141+580,_Context->y_Auto141+310,20,16,vfh[8],27,28,_Context->msg_ChoixObjDir[_Context->language],strlen(_Context->msg_ChoixObjDir[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto141+140,_Context->y_Auto141+360,430+2,16+2,5);
	visual_text(_Context->x_Auto141+140+1,_Context->y_Auto141+360+1,430,16,vfh[1],26,0,_Context->buffer_PaletteName,255,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ChoixPalette=visual_trigger_code(_Context->msg_ChoixPalette[_Context->language],strlen(_Context->msg_ChoixPalette[_Context->language]));
	visual_button(_Context->x_Auto141+580,_Context->y_Auto141+360,20,16,vfh[8],27,28,_Context->msg_ChoixPalette[_Context->language],strlen(_Context->msg_ChoixPalette[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto141+140,_Context->y_Auto141+430,430+2,16+2,5);
	visual_text(_Context->x_Auto141+140+1,_Context->y_Auto141+430+1,430,16,vfh[1],26,0,_Context->buffer_ImageName,255,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ChoixImgName=visual_trigger_code(_Context->msg_ChoixImgName[_Context->language],strlen(_Context->msg_ChoixImgName[_Context->language]));
	visual_button(_Context->x_Auto141+580,_Context->y_Auto141+430,20,16,vfh[2],27,24,_Context->msg_ChoixImgName[_Context->language],strlen(_Context->msg_ChoixImgName[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto141+140,_Context->y_Auto141+480,430+2,16+2,5);
	visual_text(_Context->x_Auto141+140+1,_Context->y_Auto141+480+1,430,16,vfh[1],26,0,_Context->buffer_StyleSheet,255,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ChoixStyle=visual_trigger_code(_Context->msg_ChoixStyle[_Context->language],strlen(_Context->msg_ChoixStyle[_Context->language]));
	visual_button(_Context->x_Auto141+580,_Context->y_Auto141+480,20,16,vfh[2],27,24,_Context->msg_ChoixStyle[_Context->language],strlen(_Context->msg_ChoixStyle[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_SaveImages=visual_trigger_code(_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]));
	visual_check(_Context->x_Auto141+200,_Context->y_Auto141+400,126,16,vfh[2],26,0,_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]),_Context->value_SaveImages|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Quality=visual_trigger_code(_Context->msg_Quality[_Context->language],strlen(_Context->msg_Quality[_Context->language]));
	visual_check(_Context->x_Auto141+30,_Context->y_Auto141+430,112,16,vfh[2],27,28,_Context->msg_Quality[_Context->language],strlen(_Context->msg_Quality[_Context->language]),_Context->value_Quality|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ApplyStyle=visual_trigger_code(_Context->msg_ApplyStyle[_Context->language],strlen(_Context->msg_ApplyStyle[_Context->language]));
	visual_check(_Context->x_Auto141+30,_Context->y_Auto141+480,126,16,vfh[2],27,28,_Context->msg_ApplyStyle[_Context->language],strlen(_Context->msg_ApplyStyle[_Context->language]),_Context->value_ApplyStyle|0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_Auto141+330,_Context->y_Auto141+400,88,96,vfh[2],0,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),768);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_Auto141+430,_Context->y_Auto141+400,140,90,vfh[2],0,0,parse_selection(WidgetImageList,&_Context->value_ImageType),768);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Auto153=visual_trigger_code(_Context->msg_Auto153[_Context->language],strlen(_Context->msg_Auto153[_Context->language]));
	visual_tabpage(_Context->x_Auto141+10,_Context->y_Auto141+30,620,510,vfh[2],_Context->msg_Auto153[_Context->language],strlen(_Context->msg_Auto153[_Context->language]),94,2);
	} else {
		visual_tabpage(_Context->x_Auto141+10,_Context->y_Auto141+30,620,510,vfh[2],_Context->msg_Auto153[_Context->language],strlen(_Context->msg_Auto153[_Context->language]),94,0);
		}
	visual_thaw(_Context->x_Auto141,_Context->y_Auto141,640,610);

	return(0);
}
private int on_Accept_event(struct new_accept_camera_properties_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct new_accept_camera_properties_context * _Context) {
	return(27);
	return(-1);
}
private int on_Choixfconf_event(struct new_accept_camera_properties_context * _Context) {
	char fconf[260];
	strcpy(fconf,_Context->buffer_Configuration);
	use_file_selector(fconf,WIDGET_FILE_CFG);
	if(strlen(fconf)>0)
	{
	fn_parser(fconf,_Context->buffer_Configuration,0x000F);
		new_accept_camera_properties_show(_Context);
;
	};
	return(-1);
}
private int on_ChoixBase_event(struct new_accept_camera_properties_context * _Context) {
	use_file_selector(_Context->buffer_DataBase,WIDGET_FILE_XML);
		new_accept_camera_properties_show(_Context);
;
	return(-1);
}
private int on_ChoixTemplate_event(struct new_accept_camera_properties_context * _Context) {
	use_file_selector(_Context->buffer_Template,WIDGET_FILE_XML);
		new_accept_camera_properties_show(_Context);
;
	return(-1);
}
private int on_ChoixModules_event(struct new_accept_camera_properties_context * _Context) {
	char ch_module[260]="\0";
	int i;
	use_file_selector(ch_module,WIDGET_FILE_OBJ);
	if(strlen(ch_module))
	{
	for(i=strlen(_Context->buffer_Modules);(i)&&(_Context->buffer_Modules[i]<=' ');i--);
	if(_Context->buffer_Modules[i]>' ')i++;
	_Context->buffer_Modules[i]=0;
	if(i)strcat(_Context->buffer_Modules,";");
	strcat(_Context->buffer_Modules,ch_module);
		new_accept_camera_properties_show(_Context);
;
	};
	return(-1);
}
private int on_ChoixForms_event(struct new_accept_camera_properties_context * _Context) {
	switch(visual_national_language(-1))
	{
	case 1:
	if(ChoixRep(_Context->buffer_FormsDirectory,"Repertoire de stockage des formulaires"))
		new_accept_camera_properties_show(_Context);
;
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	if(ChoixRep(_Context->buffer_FormsDirectory,"Directory for the XML documents"))
		new_accept_camera_properties_show(_Context);
;
	break;
	};
	return(-1);
}
private int on_ChoixSrcDir_event(struct new_accept_camera_properties_context * _Context) {
	switch(visual_national_language(-1))
	{
	case 1:
	if(ChoixRep(_Context->buffer_SourcesDirectory,"Repertoire de stockage des sources produits"))
		new_accept_camera_properties_show(_Context);
;
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	if(ChoixRep(_Context->buffer_SourcesDirectory,"Directory for the AS documents"))
		new_accept_camera_properties_show(_Context);
;
	break;
	};
	return(-1);
}
private int on_ChoixObjDir_event(struct new_accept_camera_properties_context * _Context) {
	switch(visual_national_language(-1))
	{
	case 1:
	if(ChoixRep(_Context->buffer_ObjectsDirectory,"Repertoire de stockage des fichiers binaires"))
		new_accept_camera_properties_show(_Context);
;
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	if(ChoixRep(_Context->buffer_ObjectsDirectory,"Directory for the binary files products"))
		new_accept_camera_properties_show(_Context);
;
	break;
	};
	return(-1);
}
private int on_ChoixPalette_event(struct new_accept_camera_properties_context * _Context) {
	use_file_selector(_Context->buffer_PaletteName,WIDGET_FILE_RGB);
		new_accept_camera_properties_show(_Context);
;
	return(-1);
}


public	int	new_accept_camera_properties_event(
struct new_accept_camera_properties_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Accept == mb ) return(2);
		if (_Context->trigger_Cancel == mb ) return(3);
		if (_Context->trigger_Auto142 == mb ) return(4);
		if (_Context->trigger_Choixfconf == mb ) return(6);
		if (_Context->trigger_ChoixBase == mb ) return(8);
		if (_Context->trigger_ChoixTemplate == mb ) return(10);
		if (_Context->trigger_ChoixModules == mb ) return(12);
		if (_Context->trigger_ChoixForms == mb ) return(14);
		if (_Context->trigger_ChoixSrcDir == mb ) return(16);
		if (_Context->trigger_ChoixObjDir == mb ) return(18);
		if (_Context->trigger_ChoixPalette == mb ) return(20);
		if (_Context->trigger_ChoixImgName == mb ) return(0);
		if (_Context->trigger_ChoixStyle == mb ) return(0);
		if (_Context->trigger_SaveImages == mb ) return(21);
		if (_Context->trigger_Quality == mb ) return(22);
		if (_Context->trigger_ApplyStyle == mb ) return(23);
		if (_Context->trigger_Auto153 == mb ) return(26);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto141+587) )  
	&&  (my >= (_Context->y_Auto141+4) )  
	&&  (mx <= (_Context->x_Auto141+604) )  
	&&  (my <= (_Context->y_Auto141+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		new_accept_camera_properties_show(_Context);
		return(-1);	/* Auto141 */

		}
		}
	if (( mx >= (_Context->x_Auto141+260) ) 
	&&  ( my >= (_Context->y_Auto141+550) ) 
	&&  ( mx <= (_Context->x_Auto141+260+56) ) 
	&&  ( my <= (_Context->y_Auto141+550+48))) {
		return(2); /* Accept */
		}
	if (( mx >= (_Context->x_Auto141+330) ) 
	&&  ( my >= (_Context->y_Auto141+550) ) 
	&&  ( mx <= (_Context->x_Auto141+330+56) ) 
	&&  ( my <= (_Context->y_Auto141+550+48))) {
		return(3); /* Cancel */
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto141+10+0) ) 
		&&  ( my >= (_Context->y_Auto141+30) ) 
		&&  ( mx <= (_Context->x_Auto141+10+93) ) 
		&&  ( my <= (_Context->y_Auto141+30+24))) {
			return(4); /* Auto142 */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+140) ) 
		&&  ( my >= (_Context->y_Auto141+100) ) 
		&&  ( mx <= (_Context->x_Auto141+140+430) ) 
		&&  ( my <= (_Context->y_Auto141+100+16))) {
			return(5); /* Configuration */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+580) ) 
		&&  ( my >= (_Context->y_Auto141+100) ) 
		&&  ( mx <= (_Context->x_Auto141+580+20) ) 
		&&  ( my <= (_Context->y_Auto141+100+16))) {
			return(6); /* Choixfconf */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+140) ) 
		&&  ( my >= (_Context->y_Auto141+130) ) 
		&&  ( mx <= (_Context->x_Auto141+140+430) ) 
		&&  ( my <= (_Context->y_Auto141+130+16))) {
			return(7); /* DataBase */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+580) ) 
		&&  ( my >= (_Context->y_Auto141+130) ) 
		&&  ( mx <= (_Context->x_Auto141+580+20) ) 
		&&  ( my <= (_Context->y_Auto141+130+16))) {
			return(8); /* ChoixBase */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+140) ) 
		&&  ( my >= (_Context->y_Auto141+160) ) 
		&&  ( mx <= (_Context->x_Auto141+140+431) ) 
		&&  ( my <= (_Context->y_Auto141+160+16))) {
			return(9); /* Template */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+580) ) 
		&&  ( my >= (_Context->y_Auto141+160) ) 
		&&  ( mx <= (_Context->x_Auto141+580+20) ) 
		&&  ( my <= (_Context->y_Auto141+160+16))) {
			return(10); /* ChoixTemplate */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+140) ) 
		&&  ( my >= (_Context->y_Auto141+220) ) 
		&&  ( mx <= (_Context->x_Auto141+140+431) ) 
		&&  ( my <= (_Context->y_Auto141+220+16))) {
			return(11); /* Modules */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+580) ) 
		&&  ( my >= (_Context->y_Auto141+220) ) 
		&&  ( mx <= (_Context->x_Auto141+580+20) ) 
		&&  ( my <= (_Context->y_Auto141+220+16))) {
			return(12); /* ChoixModules */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+140) ) 
		&&  ( my >= (_Context->y_Auto141+250) ) 
		&&  ( mx <= (_Context->x_Auto141+140+430) ) 
		&&  ( my <= (_Context->y_Auto141+250+16))) {
			return(13); /* FormsDirectory */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+580) ) 
		&&  ( my >= (_Context->y_Auto141+250) ) 
		&&  ( mx <= (_Context->x_Auto141+580+20) ) 
		&&  ( my <= (_Context->y_Auto141+250+16))) {
			return(14); /* ChoixForms */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+140) ) 
		&&  ( my >= (_Context->y_Auto141+280) ) 
		&&  ( mx <= (_Context->x_Auto141+140+430) ) 
		&&  ( my <= (_Context->y_Auto141+280+16))) {
			return(15); /* SourcesDirectory */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+580) ) 
		&&  ( my >= (_Context->y_Auto141+280) ) 
		&&  ( mx <= (_Context->x_Auto141+580+20) ) 
		&&  ( my <= (_Context->y_Auto141+280+16))) {
			return(16); /* ChoixSrcDir */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+140) ) 
		&&  ( my >= (_Context->y_Auto141+310) ) 
		&&  ( mx <= (_Context->x_Auto141+140+430) ) 
		&&  ( my <= (_Context->y_Auto141+310+16))) {
			return(17); /* ObjectsDirectory */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+580) ) 
		&&  ( my >= (_Context->y_Auto141+310) ) 
		&&  ( mx <= (_Context->x_Auto141+580+20) ) 
		&&  ( my <= (_Context->y_Auto141+310+16))) {
			return(18); /* ChoixObjDir */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+140) ) 
		&&  ( my >= (_Context->y_Auto141+360) ) 
		&&  ( mx <= (_Context->x_Auto141+140+430) ) 
		&&  ( my <= (_Context->y_Auto141+360+16))) {
			return(19); /* PaletteName */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+580) ) 
		&&  ( my >= (_Context->y_Auto141+360) ) 
		&&  ( mx <= (_Context->x_Auto141+580+20) ) 
		&&  ( my <= (_Context->y_Auto141+360+16))) {
			return(20); /* ChoixPalette */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+200) ) 
		&&  ( my >= (_Context->y_Auto141+400) ) 
		&&  ( mx <= (_Context->x_Auto141+200+126) ) 
		&&  ( my <= (_Context->y_Auto141+400+16))) {
			return(21); /* SaveImages */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+30) ) 
		&&  ( my >= (_Context->y_Auto141+430) ) 
		&&  ( mx <= (_Context->x_Auto141+30+112) ) 
		&&  ( my <= (_Context->y_Auto141+430+16))) {
			return(22); /* Quality */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+30) ) 
		&&  ( my >= (_Context->y_Auto141+480) ) 
		&&  ( mx <= (_Context->x_Auto141+30+126) ) 
		&&  ( my <= (_Context->y_Auto141+480+16))) {
			return(23); /* ApplyStyle */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+330+0) ) 
		&&  ( my >= (_Context->y_Auto141+400) ) 
		&&  ( mx <= (_Context->x_Auto141+330+88) ) 
		&&  ( my <= (_Context->y_Auto141+400+16))) {
			return(24); /* ImageFormat */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto141+430+0) ) 
		&&  ( my >= (_Context->y_Auto141+400) ) 
		&&  ( mx <= (_Context->x_Auto141+430+140) ) 
		&&  ( my <= (_Context->y_Auto141+400+16))) {
			return(25); /* ImageType */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto141+10+94) ) 
		&&  ( my >= (_Context->y_Auto141+30) ) 
		&&  ( mx <= (_Context->x_Auto141+10+186) ) 
		&&  ( my <= (_Context->y_Auto141+30+24))) {
			return(26); /* Auto153 */
			}
		}

	return(-1);
}


public	int	new_accept_camera_properties_losefocus(struct new_accept_camera_properties_context * _Context)
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;

		}
	return(0);

}


public	int	new_accept_camera_properties_focus(struct new_accept_camera_properties_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Accept */
				visual_button(_Context->x_Auto141+260,_Context->y_Auto141+550,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto141+260,_Context->y_Auto141+550,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0x3 :
				/* Cancel */
				visual_button(_Context->x_Auto141+330,_Context->y_Auto141+550,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto141+330,_Context->y_Auto141+550,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;
			case	0x4 :
				/* Auto142 */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x5 :
				/* Configuration */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto141+140+1,_Context->y_Auto141+100+1,430,16,vfh[1],_Context->buffer_Configuration,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* Choixfconf */
				if (_Context->page_number == 1 ) {
					visual_button(_Context->x_Auto141+580,_Context->y_Auto141+100,20,16,vfh[8],27,28,_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto141+580,_Context->y_Auto141+100,20,16,vfh[8],27,28,_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* DataBase */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto141+140+1,_Context->y_Auto141+130+1,430,16,vfh[1],_Context->buffer_DataBase,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* ChoixBase */
				if (_Context->page_number == 1 ) {
					visual_button(_Context->x_Auto141+580,_Context->y_Auto141+130,20,16,vfh[8],27,28,_Context->msg_ChoixBase[_Context->language],strlen(_Context->msg_ChoixBase[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto141+580,_Context->y_Auto141+130,20,16,vfh[8],27,28,_Context->msg_ChoixBase[_Context->language],strlen(_Context->msg_ChoixBase[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* Template */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto141+140+1,_Context->y_Auto141+160+1,431,16,vfh[1],_Context->buffer_Template,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* ChoixTemplate */
				if (_Context->page_number == 1 ) {
					visual_button(_Context->x_Auto141+580,_Context->y_Auto141+160,20,16,vfh[8],27,28,_Context->msg_ChoixTemplate[_Context->language],strlen(_Context->msg_ChoixTemplate[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto141+580,_Context->y_Auto141+160,20,16,vfh[8],27,28,_Context->msg_ChoixTemplate[_Context->language],strlen(_Context->msg_ChoixTemplate[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* Modules */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto141+140+1,_Context->y_Auto141+220+1,431,16,vfh[1],_Context->buffer_Modules,400);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* ChoixModules */
				if (_Context->page_number == 1 ) {
					visual_button(_Context->x_Auto141+580,_Context->y_Auto141+220,20,16,vfh[8],27,28,_Context->msg_ChoixModules[_Context->language],strlen(_Context->msg_ChoixModules[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto141+580,_Context->y_Auto141+220,20,16,vfh[8],27,28,_Context->msg_ChoixModules[_Context->language],strlen(_Context->msg_ChoixModules[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* FormsDirectory */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto141+140+1,_Context->y_Auto141+250+1,430,16,vfh[1],_Context->buffer_FormsDirectory,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* ChoixForms */
				if (_Context->page_number == 1 ) {
					visual_button(_Context->x_Auto141+580,_Context->y_Auto141+250,20,16,vfh[8],27,28,_Context->msg_ChoixForms[_Context->language],strlen(_Context->msg_ChoixForms[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto141+580,_Context->y_Auto141+250,20,16,vfh[8],27,28,_Context->msg_ChoixForms[_Context->language],strlen(_Context->msg_ChoixForms[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* SourcesDirectory */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto141+140+1,_Context->y_Auto141+280+1,430,16,vfh[1],_Context->buffer_SourcesDirectory,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* ChoixSrcDir */
				if (_Context->page_number == 1 ) {
					visual_button(_Context->x_Auto141+580,_Context->y_Auto141+280,20,16,vfh[8],27,28,_Context->msg_ChoixSrcDir[_Context->language],strlen(_Context->msg_ChoixSrcDir[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto141+580,_Context->y_Auto141+280,20,16,vfh[8],27,28,_Context->msg_ChoixSrcDir[_Context->language],strlen(_Context->msg_ChoixSrcDir[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* ObjectsDirectory */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto141+140+1,_Context->y_Auto141+310+1,430,16,vfh[1],_Context->buffer_ObjectsDirectory,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* ChoixObjDir */
				if (_Context->page_number == 1 ) {
					visual_button(_Context->x_Auto141+580,_Context->y_Auto141+310,20,16,vfh[8],27,28,_Context->msg_ChoixObjDir[_Context->language],strlen(_Context->msg_ChoixObjDir[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto141+580,_Context->y_Auto141+310,20,16,vfh[8],27,28,_Context->msg_ChoixObjDir[_Context->language],strlen(_Context->msg_ChoixObjDir[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* PaletteName */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto141+140+1,_Context->y_Auto141+360+1,430,16,vfh[1],_Context->buffer_PaletteName,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* ChoixPalette */
				if (_Context->page_number == 1 ) {
					visual_button(_Context->x_Auto141+580,_Context->y_Auto141+360,20,16,vfh[8],27,28,_Context->msg_ChoixPalette[_Context->language],strlen(_Context->msg_ChoixPalette[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto141+580,_Context->y_Auto141+360,20,16,vfh[8],27,28,_Context->msg_ChoixPalette[_Context->language],strlen(_Context->msg_ChoixPalette[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x15 :
				/* SaveImages */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto141+200,_Context->y_Auto141+400,126,16,vfh[2],26,0,_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]),(_Context->value_SaveImages |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto141+200,_Context->y_Auto141+400,126,16,vfh[2],26,0,_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]),(_Context->value_SaveImages |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* Quality */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto141+30,_Context->y_Auto141+430,112,16,vfh[2],27,28,_Context->msg_Quality[_Context->language],strlen(_Context->msg_Quality[_Context->language]),(_Context->value_Quality |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto141+30,_Context->y_Auto141+430,112,16,vfh[2],27,28,_Context->msg_Quality[_Context->language],strlen(_Context->msg_Quality[_Context->language]),(_Context->value_Quality |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x17 :
				/* ApplyStyle */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto141+30,_Context->y_Auto141+480,126,16,vfh[2],27,28,_Context->msg_ApplyStyle[_Context->language],strlen(_Context->msg_ApplyStyle[_Context->language]),(_Context->value_ApplyStyle |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto141+30,_Context->y_Auto141+480,126,16,vfh[2],27,28,_Context->msg_ApplyStyle[_Context->language],strlen(_Context->msg_ApplyStyle[_Context->language]),(_Context->value_ApplyStyle |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x18 :
				/* ImageFormat */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_Auto141+330,_Context->y_Auto141+400,88,96,vfh[2],0,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),774);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* ImageType */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_Auto141+430,_Context->y_Auto141+400,140,90,vfh[2],0,0,parse_selection(WidgetImageList,&_Context->value_ImageType),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* Auto153 */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			new_accept_camera_properties_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			new_accept_camera_properties_show(_Context);
			continue;
		case	0x2 :
			new_accept_camera_properties_losefocus(_Context);
			_Context->page_number=2;
			_Context->focus_item=26;
			new_accept_camera_properties_show(_Context);
			continue;
		case	0x3 :
			new_accept_camera_properties_losefocus(_Context);
			if ( _Context->page_number < 2 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			new_accept_camera_properties_show(_Context);
			continue;
		case	0x12 :
			new_accept_camera_properties_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			new_accept_camera_properties_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=new_accept_camera_properties_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto141 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto141+260,_Context->y_Auto141+550,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto141+260,_Context->y_Auto141+550,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0x3 :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto141+330,_Context->y_Auto141+550,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto141+330,_Context->y_Auto141+550,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* Auto142 */
						if (visual_event(1) & _MIMO_DOWN) {
							new_accept_camera_properties_losefocus(_Context);
							_Context->page_number = 1;
							new_accept_camera_properties_show(_Context);
							}
						continue;
					case	0x5 :
						/* Configuration */
						continue;
					case	0x6 :
						/* Choixfconf */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto141+580,_Context->y_Auto141+100,20,16,vfh[8],27,28,_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto141+580,_Context->y_Auto141+100,20,16,vfh[8],27,28,_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Choixfconf_event(_Context)) != -1) break;

							}
						continue;
					case	0x7 :
						/* DataBase */
						continue;
					case	0x8 :
						/* ChoixBase */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto141+580,_Context->y_Auto141+130,20,16,vfh[8],27,28,_Context->msg_ChoixBase[_Context->language],strlen(_Context->msg_ChoixBase[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto141+580,_Context->y_Auto141+130,20,16,vfh[8],27,28,_Context->msg_ChoixBase[_Context->language],strlen(_Context->msg_ChoixBase[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_ChoixBase_event(_Context)) != -1) break;

							}
						continue;
					case	0x9 :
						/* Template */
						continue;
					case	0xa :
						/* ChoixTemplate */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto141+580,_Context->y_Auto141+160,20,16,vfh[8],27,28,_Context->msg_ChoixTemplate[_Context->language],strlen(_Context->msg_ChoixTemplate[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto141+580,_Context->y_Auto141+160,20,16,vfh[8],27,28,_Context->msg_ChoixTemplate[_Context->language],strlen(_Context->msg_ChoixTemplate[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_ChoixTemplate_event(_Context)) != -1) break;

							}
						continue;
					case	0xb :
						/* Modules */
						continue;
					case	0xc :
						/* ChoixModules */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto141+580,_Context->y_Auto141+220,20,16,vfh[8],27,28,_Context->msg_ChoixModules[_Context->language],strlen(_Context->msg_ChoixModules[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto141+580,_Context->y_Auto141+220,20,16,vfh[8],27,28,_Context->msg_ChoixModules[_Context->language],strlen(_Context->msg_ChoixModules[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_ChoixModules_event(_Context)) != -1) break;

							}
						continue;
					case	0xd :
						/* FormsDirectory */
						continue;
					case	0xe :
						/* ChoixForms */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto141+580,_Context->y_Auto141+250,20,16,vfh[8],27,28,_Context->msg_ChoixForms[_Context->language],strlen(_Context->msg_ChoixForms[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto141+580,_Context->y_Auto141+250,20,16,vfh[8],27,28,_Context->msg_ChoixForms[_Context->language],strlen(_Context->msg_ChoixForms[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_ChoixForms_event(_Context)) != -1) break;

							}
						continue;
					case	0xf :
						/* SourcesDirectory */
						continue;
					case	0x10 :
						/* ChoixSrcDir */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto141+580,_Context->y_Auto141+280,20,16,vfh[8],27,28,_Context->msg_ChoixSrcDir[_Context->language],strlen(_Context->msg_ChoixSrcDir[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto141+580,_Context->y_Auto141+280,20,16,vfh[8],27,28,_Context->msg_ChoixSrcDir[_Context->language],strlen(_Context->msg_ChoixSrcDir[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_ChoixSrcDir_event(_Context)) != -1) break;

							}
						continue;
					case	0x11 :
						/* ObjectsDirectory */
						continue;
					case	0x12 :
						/* ChoixObjDir */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto141+580,_Context->y_Auto141+310,20,16,vfh[8],27,28,_Context->msg_ChoixObjDir[_Context->language],strlen(_Context->msg_ChoixObjDir[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto141+580,_Context->y_Auto141+310,20,16,vfh[8],27,28,_Context->msg_ChoixObjDir[_Context->language],strlen(_Context->msg_ChoixObjDir[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_ChoixObjDir_event(_Context)) != -1) break;

							}
						continue;
					case	0x13 :
						/* PaletteName */
						continue;
					case	0x14 :
						/* ChoixPalette */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto141+580,_Context->y_Auto141+360,20,16,vfh[8],27,28,_Context->msg_ChoixPalette[_Context->language],strlen(_Context->msg_ChoixPalette[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto141+580,_Context->y_Auto141+360,20,16,vfh[8],27,28,_Context->msg_ChoixPalette[_Context->language],strlen(_Context->msg_ChoixPalette[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_ChoixPalette_event(_Context)) != -1) break;

							}
						continue;
					case	0x15 :
						/* SaveImages */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_SaveImages += 1;
							_Context->value_SaveImages &= 1;
							}
						continue;
					case	0x16 :
						/* Quality */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Quality += 1;
							_Context->value_Quality &= 1;
							}
						continue;
					case	0x17 :
						/* ApplyStyle */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_ApplyStyle += 1;
							_Context->value_ApplyStyle &= 1;
							}
						continue;
					case	0x18 :
						/* ImageFormat */
						continue;
					case	0x19 :
						/* ImageType */
						continue;
					case	0x1a :
						/* Auto153 */
						if (visual_event(1) & _MIMO_DOWN) {
							new_accept_camera_properties_losefocus(_Context);
							_Context->page_number = 2;
							new_accept_camera_properties_show(_Context);
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
				_Context->focus_item=26;
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

public	int	new_accept_camera_properties(
	char * pName,
	char * pConfiguration,
	char * pDataBase,
	char * pTemplate,
	char * pModules,
	char * pFormsDirectory,
	char * pSourcesDirectory,
	char * pObjectsDirectory,
	char * pPaletteName,
	char * pImageName,
	char * pStyleSheet,
	char * pSaveImages,
	char * pQuality,
	char * pApplyStyle,
	char * pImageFormat,
	char * pImageType)
{
	int	status=0;
	struct new_accept_camera_properties_context * _Context=(struct new_accept_camera_properties_context*) 0;
	status = new_accept_camera_properties_create(
	&_Context,
	 pName,
	 pConfiguration,
	 pDataBase,
	 pTemplate,
	 pModules,
	 pFormsDirectory,
	 pSourcesDirectory,
	 pObjectsDirectory,
	 pPaletteName,
	 pImageName,
	 pStyleSheet,
	 pSaveImages,
	 pQuality,
	 pApplyStyle,
	 pImageFormat,
	 pImageType);
	if ( status != 0) return(status);
	status = new_accept_camera_properties_show(_Context);
		enter_modal();
	status = new_accept_camera_properties_focus(_Context);
		leave_modal();
	status = new_accept_camera_properties_hide(_Context);
	status = new_accept_camera_properties_remove(
	_Context,
	 pName,
	 pConfiguration,
	 pDataBase,
	 pTemplate,
	 pModules,
	 pFormsDirectory,
	 pSourcesDirectory,
	 pObjectsDirectory,
	 pPaletteName,
	 pImageName,
	 pStyleSheet,
	 pSaveImages,
	 pQuality,
	 pApplyStyle,
	 pImageFormat,
	 pImageType);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _xcamera_c */
