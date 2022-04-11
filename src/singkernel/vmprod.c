
#ifndef _vmprod_c
#define _vmprod_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vmprod.xml  */
/* Target         : vmprod.c  */
/* Identification : 0.0-1100519248-5231.5230 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_auto2   "Sing : Version 1.0a"
#define fr_auto2   "Sing : Version 1.0a"
#define en_Auto403   "skin.gif"
#define fr_Auto403   "skin.gif"
#define en_auto96   "fileicon.gif"
#define fr_auto96   "fileicon.gif"
#define it_auto96   ""
#define es_auto96   ""
#define de_auto96   ""
#define nl_auto96   ""
#define pt_auto96   ""
#define xx_auto96   ""
#define en_UseAed   "&Edit"
#define fr_UseAed   "&Edition"
#define en_View   "&View"
#define fr_View   "&Visualiser"
#define en_auto7   "Production Parameters of Application Model"
#define fr_auto7   "ParamŠtres de Production du ModŠle de Projet"
#define it_auto7   "Production Parameters of Application Model"
#define es_auto7   "Production Parameters of Application Model"
#define de_auto7   "Production Parameters of Application Model"
#define nl_auto7   "Production Parameters of Application Model"
#define pt_auto7   "Production Parameters of Application Model"
#define xx_auto7   "Production Parameters of Application Model"
#define en_Auto1177   "Target"
#define fr_Auto1177   "Cible"
#define it_Auto1177   ""
#define es_Auto1177   ""
#define de_Auto1177   ""
#define nl_Auto1177   ""
#define pt_Auto1177   ""
#define xx_Auto1177   ""
#define en_Auto1219   "Language"
#define fr_Auto1219   "Langage"
#define it_Auto1219   ""
#define es_Auto1219   ""
#define de_Auto1219   ""
#define nl_Auto1219   ""
#define pt_Auto1219   ""
#define xx_Auto1219   ""
#define en_auto52   "Filename"
#define fr_auto52   "Nom de Fichier"
#define it_auto52   ""
#define es_auto52   ""
#define de_auto52   ""
#define nl_auto52   ""
#define pt_auto52   ""
#define xx_auto52   ""
#define en_NoConfirm   "A&utomatic"
#define fr_NoConfirm   "&Automatique"
#define en_Build   "&Force Build"
#define fr_Build   "&Forc‚e"
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
#define en_Verbose   "V&isualise"
#define fr_Verbose   "V&isualise"
#define it_Verbose   ""
#define es_Verbose   ""
#define de_Verbose   ""
#define nl_Verbose   ""
#define pt_Verbose   ""
#define xx_Verbose   ""
#define en_TargetType   "none|module|program|overlay|library"
#define fr_TargetType   "sans|module|program|overlay|library"
#define it_TargetType   ""
#define es_TargetType   ""
#define de_TargetType   ""
#define nl_TargetType   ""
#define pt_TargetType   ""
#define xx_TargetType   ""
#define en_IsDocument   "&Document"
#define fr_IsDocument   "&Document"
#define it_ProdLang   ""
#define es_ProdLang   ""
#define de_ProdLang   ""
#define nl_ProdLang   ""
#define pt_ProdLang   ""
#define xx_ProdLang   ""
#define en_AdFn   "Application Document Filename"
#define fr_AdFn   "Nom de fichier du Document d'Application"
#define it_AdFn   ""
#define es_AdFn   ""
#define de_AdFn   ""
#define nl_AdFn   ""
#define pt_AdFn   ""
#define xx_AdFn   ""
#define en_Makefile   "&Makefile"
#define fr_Makefile   "&Makefile"
#define it_Makefile   ""
#define es_Makefile   ""
#define de_Makefile   ""
#define nl_Makefile   ""
#define pt_Makefile   ""
#define xx_Makefile   ""
static int	vfh[10];

private struct accept_production_properties_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_auto2[8];
	int	x_auto2;
	int	y_auto2;
	int	w_auto2;
	int	h_auto2;
	char * msg_Auto403[8];
	char * msg_auto96[8];
	char * msg_UseAed[8];
	int	trigger_UseAed;
	char * msg_View[8];
	int	trigger_View;
	char * msg_auto7[8];
	char * msg_Auto1177[8];
	char * msg_Auto1219[8];
	char	buffer_ModelName[71];
	char * msg_auto52[8];
	char	buffer_TargetFile[56];
	char * msg_NoConfirm[8];
	int	trigger_NoConfirm;
	int	value_NoConfirm;
	char * msg_Build[8];
	int	trigger_Build;
	int	value_Build;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * msg_Verbose[8];
	int	trigger_Verbose;
	int	value_Verbose;
	char * msg_TargetType[8];
	int	value_TargetType;
	char * msg_IsDocument[8];
	int	trigger_IsDocument;
	int	value_IsDocument;
	char * msg_ProdLang[8];
	int	value_ProdLang;
	char * msg_AdFn[8];
	char	buffer_DocumentFile[56];
	char * msg_Makefile[8];
	int	trigger_Makefile;
	int	value_Makefile;
	char	buffer_MakefileName[56];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[12];
	};

public	int	accept_production_properties_create(
	struct accept_production_properties_context ** cptr,
	char * pModelName,
	char * pTargetFile,
	char * pNoConfirm,
	char * pBuild,
	char * pVerbose,
	char * pTargetType,
	char * pIsDocument,
	char * pProdLang,
	char * pDocumentFile,
	char * pMakefile,
	char * pMakefileName)
{

	int i;
	struct accept_production_properties_context * _Context=(struct accept_production_properties_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_production_properties_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=20;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWWWWSWS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_ModelName, 70, pModelName);
		visual_transferin(_Context->buffer_TargetFile, 55, pTargetFile);
		visual_transferin((void *) 0, 0, pNoConfirm);
		if (!( pNoConfirm )) _Context->value_NoConfirm=0;
		else	_Context->value_NoConfirm = *((int *)pNoConfirm);
		visual_transferin((void *) 0, 0, pBuild);
		if (!( pBuild )) _Context->value_Build=0;
		else	_Context->value_Build = *((int *)pBuild);
		visual_transferin((void *) 0, 0, pVerbose);
		if (!( pVerbose )) _Context->value_Verbose=0;
		else	_Context->value_Verbose = *((int *)pVerbose);
		visual_transferin((void *) 0, 0, pTargetType);
		if (!( pTargetType )) _Context->value_TargetType=0;
		else	_Context->value_TargetType = *((int *)pTargetType);
		visual_transferin((void *) 0, 0, pIsDocument);
		if (!( pIsDocument )) _Context->value_IsDocument=0;
		else	_Context->value_IsDocument = *((int *)pIsDocument);
		visual_transferin((void *) 0, 0, pProdLang);
		if (!( pProdLang )) _Context->value_ProdLang=0;
		else	_Context->value_ProdLang = *((int *)pProdLang);
		visual_transferin(_Context->buffer_DocumentFile, 55, pDocumentFile);
		visual_transferin((void *) 0, 0, pMakefile);
		if (!( pMakefile )) _Context->value_Makefile=0;
		else	_Context->value_Makefile = *((int *)pMakefile);
		visual_transferin(_Context->buffer_MakefileName, 55, pMakefileName);
		}
	for (i=0; i < 8; i++)_Context->msg_auto2[i]=" ";
	_Context->msg_auto2[0]=en_auto2;
	_Context->msg_auto2[1]=fr_auto2;
	_Context->x_auto2=100;
	_Context->y_auto2=116;
	_Context->w_auto2=600;
	_Context->h_auto2=367;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto403[i]=" ";
	_Context->msg_Auto403[0]=en_Auto403;
	_Context->msg_Auto403[1]=fr_Auto403;
	for (i=0; i < 8; i++)_Context->msg_auto96[i]=" ";
	_Context->msg_auto96[0]=en_auto96;
	_Context->msg_auto96[1]=fr_auto96;
	_Context->msg_auto96[2]=it_auto96;
	_Context->msg_auto96[3]=es_auto96;
	_Context->msg_auto96[4]=de_auto96;
	_Context->msg_auto96[5]=nl_auto96;
	_Context->msg_auto96[6]=pt_auto96;
	_Context->msg_auto96[7]=xx_auto96;
	for (i=0; i < 8; i++)_Context->msg_UseAed[i]=" ";
	_Context->msg_UseAed[0]=en_UseAed;
	_Context->msg_UseAed[1]=fr_UseAed;
	for (i=0; i < 8; i++)_Context->msg_View[i]=" ";
	_Context->msg_View[0]=en_View;
	_Context->msg_View[1]=fr_View;
	for (i=0; i < 8; i++)_Context->msg_auto7[i]=" ";
	_Context->msg_auto7[0]=en_auto7;
	_Context->msg_auto7[1]=fr_auto7;
	_Context->msg_auto7[2]=it_auto7;
	_Context->msg_auto7[3]=es_auto7;
	_Context->msg_auto7[4]=de_auto7;
	_Context->msg_auto7[5]=nl_auto7;
	_Context->msg_auto7[6]=pt_auto7;
	_Context->msg_auto7[7]=xx_auto7;
	for (i=0; i < 8; i++)_Context->msg_Auto1177[i]=" ";
	_Context->msg_Auto1177[0]=en_Auto1177;
	_Context->msg_Auto1177[1]=fr_Auto1177;
	_Context->msg_Auto1177[2]=it_Auto1177;
	_Context->msg_Auto1177[3]=es_Auto1177;
	_Context->msg_Auto1177[4]=de_Auto1177;
	_Context->msg_Auto1177[5]=nl_Auto1177;
	_Context->msg_Auto1177[6]=pt_Auto1177;
	_Context->msg_Auto1177[7]=xx_Auto1177;
	for (i=0; i < 8; i++)_Context->msg_Auto1219[i]=" ";
	_Context->msg_Auto1219[0]=en_Auto1219;
	_Context->msg_Auto1219[1]=fr_Auto1219;
	_Context->msg_Auto1219[2]=it_Auto1219;
	_Context->msg_Auto1219[3]=es_Auto1219;
	_Context->msg_Auto1219[4]=de_Auto1219;
	_Context->msg_Auto1219[5]=nl_Auto1219;
	_Context->msg_Auto1219[6]=pt_Auto1219;
	_Context->msg_Auto1219[7]=xx_Auto1219;
	for (i=0; i < 8; i++)_Context->msg_auto52[i]=" ";
	_Context->msg_auto52[0]=en_auto52;
	_Context->msg_auto52[1]=fr_auto52;
	_Context->msg_auto52[2]=it_auto52;
	_Context->msg_auto52[3]=es_auto52;
	_Context->msg_auto52[4]=de_auto52;
	_Context->msg_auto52[5]=nl_auto52;
	_Context->msg_auto52[6]=pt_auto52;
	_Context->msg_auto52[7]=xx_auto52;
	for (i=0; i < 8; i++)_Context->msg_NoConfirm[i]=" ";
	_Context->msg_NoConfirm[0]=en_NoConfirm;
	_Context->msg_NoConfirm[1]=fr_NoConfirm;
	for (i=0; i < 8; i++)_Context->msg_Build[i]=" ";
	_Context->msg_Build[0]=en_Build;
	_Context->msg_Build[1]=fr_Build;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	for (i=0; i < 8; i++)_Context->msg_Verbose[i]=" ";
	_Context->msg_Verbose[0]=en_Verbose;
	_Context->msg_Verbose[1]=fr_Verbose;
	_Context->msg_Verbose[2]=it_Verbose;
	_Context->msg_Verbose[3]=es_Verbose;
	_Context->msg_Verbose[4]=de_Verbose;
	_Context->msg_Verbose[5]=nl_Verbose;
	_Context->msg_Verbose[6]=pt_Verbose;
	_Context->msg_Verbose[7]=xx_Verbose;
	for (i=0; i < 8; i++)_Context->msg_TargetType[i]=" ";
	_Context->msg_TargetType[0]=en_TargetType;
	_Context->msg_TargetType[1]=fr_TargetType;
	_Context->msg_TargetType[2]=it_TargetType;
	_Context->msg_TargetType[3]=es_TargetType;
	_Context->msg_TargetType[4]=de_TargetType;
	_Context->msg_TargetType[5]=nl_TargetType;
	_Context->msg_TargetType[6]=pt_TargetType;
	_Context->msg_TargetType[7]=xx_TargetType;
	for (i=0; i < 8; i++)_Context->msg_IsDocument[i]=" ";
	_Context->msg_IsDocument[0]=en_IsDocument;
	_Context->msg_IsDocument[1]=fr_IsDocument;
	for (i=0; i < 8; i++)_Context->msg_ProdLang[i]=" ";
	_Context->msg_ProdLang[2]=it_ProdLang;
	_Context->msg_ProdLang[3]=es_ProdLang;
	_Context->msg_ProdLang[4]=de_ProdLang;
	_Context->msg_ProdLang[5]=nl_ProdLang;
	_Context->msg_ProdLang[6]=pt_ProdLang;
	_Context->msg_ProdLang[7]=xx_ProdLang;
	for (i=0; i < 8; i++)_Context->msg_AdFn[i]=" ";
	_Context->msg_AdFn[0]=en_AdFn;
	_Context->msg_AdFn[1]=fr_AdFn;
	_Context->msg_AdFn[2]=it_AdFn;
	_Context->msg_AdFn[3]=es_AdFn;
	_Context->msg_AdFn[4]=de_AdFn;
	_Context->msg_AdFn[5]=nl_AdFn;
	_Context->msg_AdFn[6]=pt_AdFn;
	_Context->msg_AdFn[7]=xx_AdFn;
	for (i=0; i < 8; i++)_Context->msg_Makefile[i]=" ";
	_Context->msg_Makefile[0]=en_Makefile;
	_Context->msg_Makefile[1]=fr_Makefile;
	_Context->msg_Makefile[2]=it_Makefile;
	_Context->msg_Makefile[3]=es_Makefile;
	_Context->msg_Makefile[4]=de_Makefile;
	_Context->msg_Makefile[5]=nl_Makefile;
	_Context->msg_Makefile[6]=pt_Makefile;
	_Context->msg_Makefile[7]=xx_Makefile;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto2,_Context->y_auto2,600+10,367+10);
	return(0);
}

public 	int	accept_production_properties_hide(struct accept_production_properties_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_auto2,_Context->y_auto2);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_production_properties_remove(
	struct accept_production_properties_context * _Context,
	char * pModelName,
	char * pTargetFile,
	char * pNoConfirm,
	char * pBuild,
	char * pVerbose,
	char * pTargetType,
	char * pIsDocument,
	char * pProdLang,
	char * pDocumentFile,
	char * pMakefile,
	char * pMakefileName)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWWWWSWS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_ModelName, 70, pModelName);
		visual_transferout(_Context->buffer_TargetFile, 55, pTargetFile);
		visual_transferout((void *) 0, 0, pNoConfirm);
		if ( pNoConfirm != (char *) 0)
			*((int*)pNoConfirm) = _Context->value_NoConfirm;
		visual_transferout((void *) 0, 0, pBuild);
		if ( pBuild != (char *) 0)
			*((int*)pBuild) = _Context->value_Build;
		visual_transferout((void *) 0, 0, pVerbose);
		if ( pVerbose != (char *) 0)
			*((int*)pVerbose) = _Context->value_Verbose;
		visual_transferout((void *) 0, 0, pTargetType);
		if ( pTargetType != (char *) 0)
			*((int*)pTargetType) = _Context->value_TargetType;
		visual_transferout((void *) 0, 0, pIsDocument);
		if ( pIsDocument != (char *) 0)
			*((int*)pIsDocument) = _Context->value_IsDocument;
		visual_transferout((void *) 0, 0, pProdLang);
		if ( pProdLang != (char *) 0)
			*((int*)pProdLang) = _Context->value_ProdLang;
		visual_transferout(_Context->buffer_DocumentFile, 55, pDocumentFile);
		visual_transferout((void *) 0, 0, pMakefile);
		if ( pMakefile != (char *) 0)
			*((int*)pMakefile) = _Context->value_Makefile;
		visual_transferout(_Context->buffer_MakefileName, 55, pMakefileName);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_production_properties_show(struct accept_production_properties_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto2,_Context->y_auto2);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_auto2,_Context->y_auto2,600,367,vfh[2],_Context->msg_auto2[_Context->language],strlen(_Context->msg_auto2[_Context->language]),0x407);
	visual_image(_Context->x_auto2+3,_Context->y_auto2+22,592,340,_Context->msg_Auto403[_Context->language],4);
	visual_frame(_Context->x_auto2+14,_Context->y_auto2+255,562,29,2);
	visual_image(_Context->x_auto2+268,_Context->y_auto2+288,60,60,_Context->msg_auto96[_Context->language],0);
	_Context->trigger_UseAed=visual_trigger_code(_Context->msg_UseAed[_Context->language],strlen(_Context->msg_UseAed[_Context->language]));
	visual_button(_Context->x_auto2+150,_Context->y_auto2+300,90,30,vfh[2],27,0,_Context->msg_UseAed[_Context->language],strlen(_Context->msg_UseAed[_Context->language]),0);
	_Context->trigger_View=visual_trigger_code(_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]));
	visual_button(_Context->x_auto2+350,_Context->y_auto2+300,90,30,vfh[2],27,0,_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]),0);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+30,560,32,vfh[3],34,0,_Context->msg_auto7[_Context->language],strlen(_Context->msg_auto7[_Context->language]),1282);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+140,119,18,vfh[2],27,0,_Context->msg_Auto1177[_Context->language],strlen(_Context->msg_Auto1177[_Context->language]),2);
	visual_text(_Context->x_auto2+280,_Context->y_auto2+140,128,19,vfh[2],27,0,_Context->msg_Auto1219[_Context->language],strlen(_Context->msg_Auto1219[_Context->language]),3);
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+70,560+2,16+2,5);
	visual_text(_Context->x_auto2+20+1,_Context->y_auto2+70+1,560,16,vfh[1],34,0,_Context->buffer_ModelName,70,0);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+110,120,20,vfh[2],34,0,_Context->msg_auto52[_Context->language],strlen(_Context->msg_auto52[_Context->language]),2);
	visual_frame(_Context->x_auto2+140,_Context->y_auto2+110,440+2,16+2,5);
	visual_text(_Context->x_auto2+140+1,_Context->y_auto2+110+1,440,16,vfh[1],34,0,_Context->buffer_TargetFile,55,0);
	_Context->trigger_NoConfirm=visual_trigger_code(_Context->msg_NoConfirm[_Context->language],strlen(_Context->msg_NoConfirm[_Context->language]));
	visual_check(_Context->x_auto2+160,_Context->y_auto2+260,168,16,vfh[2],34,0,_Context->msg_NoConfirm[_Context->language],strlen(_Context->msg_NoConfirm[_Context->language]),_Context->value_NoConfirm|0);
	_Context->trigger_Build=visual_trigger_code(_Context->msg_Build[_Context->language],strlen(_Context->msg_Build[_Context->language]));
	visual_check(_Context->x_auto2+350,_Context->y_auto2+260,154,16,vfh[2],34,0,_Context->msg_Build[_Context->language],strlen(_Context->msg_Build[_Context->language]),_Context->value_Build|0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_auto2+20,_Context->y_auto2+300,120,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto2+450,_Context->y_auto2+300,120,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	_Context->trigger_Verbose=visual_trigger_code(_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]));
	visual_check(_Context->x_auto2+30,_Context->y_auto2+260,112,16,vfh[2],34,0,_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]),_Context->value_Verbose|0);
	visual_select(_Context->x_auto2+140,_Context->y_auto2+140,120,64,vfh[1],27,0,parse_selection(_Context->msg_TargetType[_Context->language],&_Context->value_TargetType),0);
	_Context->trigger_IsDocument=visual_trigger_code(_Context->msg_IsDocument[_Context->language],strlen(_Context->msg_IsDocument[_Context->language]));
	visual_check(_Context->x_auto2+20,_Context->y_auto2+190,112,16,vfh[2],27,0,_Context->msg_IsDocument[_Context->language],strlen(_Context->msg_IsDocument[_Context->language]),_Context->value_IsDocument|0);
	visual_select(_Context->x_auto2+410,_Context->y_auto2+140,168,64,vfh[1],27,0,parse_selection(ProductionLanguageList,&_Context->value_ProdLang),0);
	visual_text(_Context->x_auto2+140,_Context->y_auto2+170,440,20,vfh[2],27,0,_Context->msg_AdFn[_Context->language],strlen(_Context->msg_AdFn[_Context->language]),3);
	visual_frame(_Context->x_auto2+140,_Context->y_auto2+190,440+2,16+2,5);
	visual_text(_Context->x_auto2+140+1,_Context->y_auto2+190+1,440,16,vfh[1],27,0,_Context->buffer_DocumentFile,55,0);
	_Context->trigger_Makefile=visual_trigger_code(_Context->msg_Makefile[_Context->language],strlen(_Context->msg_Makefile[_Context->language]));
	visual_check(_Context->x_auto2+20,_Context->y_auto2+220,112,16,vfh[2],16,28,_Context->msg_Makefile[_Context->language],strlen(_Context->msg_Makefile[_Context->language]),_Context->value_Makefile|0);
	visual_frame(_Context->x_auto2+140,_Context->y_auto2+220,440+2,16+2,5);
	visual_text(_Context->x_auto2+140+1,_Context->y_auto2+220+1,440,16,vfh[1],0,0,_Context->buffer_MakefileName,55,0);
	visual_thaw(_Context->x_auto2,_Context->y_auto2,600,367);
	visual_thaw(_Context->x_auto2,_Context->y_auto2,600,367);

	return(0);
}

private int auto2action(struct accept_production_properties_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_production_properties_hide(_Context);

		_Context->x_auto2 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto2 < 0) { _Context->x_auto2=0; }
		_Context->y_auto2 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto2 < 0) { _Context->y_auto2=0; }
			accept_production_properties_show(_Context);

		visual_thaw(_Context->x_auto2,_Context->y_auto2,600,367);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_UseAed_event(struct accept_production_properties_context * _Context) {
		accept_production_properties_hide(_Context);
;
	if(_Context->value_Makefile){
	use_editor(_Context->buffer_MakefileName,0);
	}
	else if(_Context->value_IsDocument){
	use_editor(_Context->buffer_DocumentFile,0);
	}
	else{
	use_editor(_Context->buffer_TargetFile,0);
	}
		accept_production_properties_show(_Context);
;
	return(-1);
}
private int on_View_event(struct accept_production_properties_context * _Context) {
	use_navigator(_Context->buffer_TargetFile);
		accept_production_properties_show(_Context);
;
	return(-1);
}
private int on_Accept_event(struct accept_production_properties_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_production_properties_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_production_properties_event(
struct accept_production_properties_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_UseAed == mb ) return(3);
		if (_Context->trigger_View == mb ) return(4);
		if (_Context->trigger_NoConfirm == mb ) return(9);
		if (_Context->trigger_Build == mb ) return(10);
		if (_Context->trigger_Accept == mb ) return(11);
		if (_Context->trigger_Cancel == mb ) return(12);
		if (_Context->trigger_Verbose == mb ) return(13);
		if (_Context->trigger_IsDocument == mb ) return(15);
		if (_Context->trigger_Makefile == mb ) return(19);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x1031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_auto2+579) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+596) )  
	&&  (my <= (_Context->y_auto2+20) )) {
		return(1);	/* auto2 */

		}
	if ((mx >= (_Context->x_auto2+563) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+580) )  
	&&  (my <= (_Context->y_auto2+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vmprod.htm");
			};
		return(-1);	/* auto2 */

		}
	if ((mx >= (_Context->x_auto2+547) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+564) )  
	&&  (my <= (_Context->y_auto2+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_production_properties_show(_Context);
		return(-1);	/* auto2 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_auto2+4) )  
		&&  (my >= (_Context->y_auto2+4) )  
		&&  (mx <= (_Context->x_auto2+532) )  
		&&  (my <= (_Context->y_auto2+20) )) {
			return( auto2action(_Context) );
			}
		}
	if (( mx >= (_Context->x_auto2+268) ) 
	&&  ( my >= (_Context->y_auto2+288) ) 
	&&  ( mx <= (_Context->x_auto2+268+60) ) 
	&&  ( my <= (_Context->y_auto2+288+60))) {
		return(2); /* auto96 */
		}
	if (( mx >= (_Context->x_auto2+150) ) 
	&&  ( my >= (_Context->y_auto2+300) ) 
	&&  ( mx <= (_Context->x_auto2+150+90) ) 
	&&  ( my <= (_Context->y_auto2+300+30))) {
		return(3); /* UseAed */
		}
	if (( mx >= (_Context->x_auto2+350) ) 
	&&  ( my >= (_Context->y_auto2+300) ) 
	&&  ( mx <= (_Context->x_auto2+350+90) ) 
	&&  ( my <= (_Context->y_auto2+300+30))) {
		return(4); /* View */
		}
	if (( mx >= (_Context->x_auto2+20) ) 
	&&  ( my >= (_Context->y_auto2+70) ) 
	&&  ( mx <= (_Context->x_auto2+20+560) ) 
	&&  ( my <= (_Context->y_auto2+70+16))) {
		return(6); /* ModelName */
		}
	if (( mx >= (_Context->x_auto2+140) ) 
	&&  ( my >= (_Context->y_auto2+110) ) 
	&&  ( mx <= (_Context->x_auto2+140+440) ) 
	&&  ( my <= (_Context->y_auto2+110+16))) {
		return(8); /* TargetFile */
		}
	if (( mx >= (_Context->x_auto2+160) ) 
	&&  ( my >= (_Context->y_auto2+260) ) 
	&&  ( mx <= (_Context->x_auto2+160+168) ) 
	&&  ( my <= (_Context->y_auto2+260+16))) {
		return(9); /* NoConfirm */
		}
	if (( mx >= (_Context->x_auto2+350) ) 
	&&  ( my >= (_Context->y_auto2+260) ) 
	&&  ( mx <= (_Context->x_auto2+350+154) ) 
	&&  ( my <= (_Context->y_auto2+260+16))) {
		return(10); /* Build */
		}
	if (( mx >= (_Context->x_auto2+20) ) 
	&&  ( my >= (_Context->y_auto2+300) ) 
	&&  ( mx <= (_Context->x_auto2+20+120) ) 
	&&  ( my <= (_Context->y_auto2+300+30))) {
		return(11); /* Accept */
		}
	if (( mx >= (_Context->x_auto2+450) ) 
	&&  ( my >= (_Context->y_auto2+300) ) 
	&&  ( mx <= (_Context->x_auto2+450+120) ) 
	&&  ( my <= (_Context->y_auto2+300+30))) {
		return(12); /* Cancel */
		}
	if (( mx >= (_Context->x_auto2+30) ) 
	&&  ( my >= (_Context->y_auto2+260) ) 
	&&  ( mx <= (_Context->x_auto2+30+112) ) 
	&&  ( my <= (_Context->y_auto2+260+16))) {
		return(13); /* Verbose */
		}
	if (( mx >= (_Context->x_auto2+140+0) ) 
	&&  ( my >= (_Context->y_auto2+140) ) 
	&&  ( mx <= (_Context->x_auto2+140+120) ) 
	&&  ( my <= (_Context->y_auto2+140+16))) {
		return(14); /* TargetType */
		}
	if (( mx >= (_Context->x_auto2+20) ) 
	&&  ( my >= (_Context->y_auto2+190) ) 
	&&  ( mx <= (_Context->x_auto2+20+112) ) 
	&&  ( my <= (_Context->y_auto2+190+16))) {
		return(15); /* IsDocument */
		}
	if (( mx >= (_Context->x_auto2+410+0) ) 
	&&  ( my >= (_Context->y_auto2+140) ) 
	&&  ( mx <= (_Context->x_auto2+410+168) ) 
	&&  ( my <= (_Context->y_auto2+140+16))) {
		return(16); /* ProdLang */
		}
	if (( mx >= (_Context->x_auto2+140) ) 
	&&  ( my >= (_Context->y_auto2+190) ) 
	&&  ( mx <= (_Context->x_auto2+140+440) ) 
	&&  ( my <= (_Context->y_auto2+190+16))) {
		return(18); /* DocumentFile */
		}
	if (( mx >= (_Context->x_auto2+20) ) 
	&&  ( my >= (_Context->y_auto2+220) ) 
	&&  ( mx <= (_Context->x_auto2+20+112) ) 
	&&  ( my <= (_Context->y_auto2+220+16))) {
		return(19); /* Makefile */
		}
	if (( mx >= (_Context->x_auto2+140) ) 
	&&  ( my >= (_Context->y_auto2+220) ) 
	&&  ( mx <= (_Context->x_auto2+140+440) ) 
	&&  ( my <= (_Context->y_auto2+220+16))) {
		return(20); /* MakefileName */
		}

	return(-1);
}


public	int	accept_production_properties_focus(struct accept_production_properties_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* auto96 */
				_Context->keycode = visual_getch();
				break;
			case	0x3 :
				/* UseAed */
				visual_button(_Context->x_auto2+150,_Context->y_auto2+300,90,30,vfh[2],27,0,_Context->msg_UseAed[_Context->language],strlen(_Context->msg_UseAed[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto2+150,_Context->y_auto2+300,90,30,vfh[2],27,0,_Context->msg_UseAed[_Context->language],strlen(_Context->msg_UseAed[_Context->language]),0);
				break;
			case	0x4 :
				/* View */
				visual_button(_Context->x_auto2+350,_Context->y_auto2+300,90,30,vfh[2],27,0,_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto2+350,_Context->y_auto2+300,90,30,vfh[2],27,0,_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]),0);
				break;
			case	0x6 :
				/* ModelName */
				_Context->keycode = visual_edit(_Context->x_auto2+20+1,_Context->y_auto2+70+1,560,16,vfh[1],_Context->buffer_ModelName,70);
			break;
			case	0x8 :
				/* TargetFile */
				_Context->keycode = visual_edit(_Context->x_auto2+140+1,_Context->y_auto2+110+1,440,16,vfh[1],_Context->buffer_TargetFile,55);
			break;
			case	0x9 :
				/* NoConfirm */
				visual_check(_Context->x_auto2+160,_Context->y_auto2+260,168,16,vfh[2],34,0,_Context->msg_NoConfirm[_Context->language],strlen(_Context->msg_NoConfirm[_Context->language]),(_Context->value_NoConfirm |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+160,_Context->y_auto2+260,168,16,vfh[2],34,0,_Context->msg_NoConfirm[_Context->language],strlen(_Context->msg_NoConfirm[_Context->language]),(_Context->value_NoConfirm |0));
				break;
			case	0xa :
				/* Build */
				visual_check(_Context->x_auto2+350,_Context->y_auto2+260,154,16,vfh[2],34,0,_Context->msg_Build[_Context->language],strlen(_Context->msg_Build[_Context->language]),(_Context->value_Build |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+350,_Context->y_auto2+260,154,16,vfh[2],34,0,_Context->msg_Build[_Context->language],strlen(_Context->msg_Build[_Context->language]),(_Context->value_Build |0));
				break;
			case	0xb :
				/* Accept */
				visual_button(_Context->x_auto2+20,_Context->y_auto2+300,120,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto2+20,_Context->y_auto2+300,120,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0xc :
				/* Cancel */
				visual_button(_Context->x_auto2+450,_Context->y_auto2+300,120,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto2+450,_Context->y_auto2+300,120,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0xd :
				/* Verbose */
				visual_check(_Context->x_auto2+30,_Context->y_auto2+260,112,16,vfh[2],34,0,_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]),(_Context->value_Verbose |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+30,_Context->y_auto2+260,112,16,vfh[2],34,0,_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]),(_Context->value_Verbose |0));
				break;
			case	0xe :
				/* TargetType */
				_Context->keycode = visual_select(_Context->x_auto2+140,_Context->y_auto2+140,120,64,vfh[1],27,0,parse_selection(_Context->msg_TargetType[_Context->language],&_Context->value_TargetType),2);
				break;
			case	0xf :
				/* IsDocument */
				visual_check(_Context->x_auto2+20,_Context->y_auto2+190,112,16,vfh[2],27,0,_Context->msg_IsDocument[_Context->language],strlen(_Context->msg_IsDocument[_Context->language]),(_Context->value_IsDocument |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+20,_Context->y_auto2+190,112,16,vfh[2],27,0,_Context->msg_IsDocument[_Context->language],strlen(_Context->msg_IsDocument[_Context->language]),(_Context->value_IsDocument |0));
				break;
			case	0x10 :
				/* ProdLang */
				_Context->keycode = visual_select(_Context->x_auto2+410,_Context->y_auto2+140,168,64,vfh[1],27,0,parse_selection(ProductionLanguageList,&_Context->value_ProdLang),2);
				break;
			case	0x12 :
				/* DocumentFile */
				_Context->keycode = visual_edit(_Context->x_auto2+140+1,_Context->y_auto2+190+1,440,16,vfh[1],_Context->buffer_DocumentFile,55);
			break;
			case	0x13 :
				/* Makefile */
				visual_check(_Context->x_auto2+20,_Context->y_auto2+220,112,16,vfh[2],16,28,_Context->msg_Makefile[_Context->language],strlen(_Context->msg_Makefile[_Context->language]),(_Context->value_Makefile |2));
				_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+20,_Context->y_auto2+220,112,16,vfh[2],16,28,_Context->msg_Makefile[_Context->language],strlen(_Context->msg_Makefile[_Context->language]),(_Context->value_Makefile |0));
				break;
			case	0x14 :
				/* MakefileName */
				_Context->keycode = visual_edit(_Context->x_auto2+140+1,_Context->y_auto2+220+1,440,16,vfh[1],_Context->buffer_MakefileName,55);
			break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_production_properties_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=20;
			accept_production_properties_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_production_properties_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* auto2 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x3 :
						/* UseAed */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto2+150,_Context->y_auto2+300,90,30,vfh[2],27,0,_Context->msg_UseAed[_Context->language],strlen(_Context->msg_UseAed[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto2+150,_Context->y_auto2+300,90,30,vfh[2],27,0,_Context->msg_UseAed[_Context->language],strlen(_Context->msg_UseAed[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_UseAed_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* View */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto2+350,_Context->y_auto2+300,90,30,vfh[2],27,0,_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto2+350,_Context->y_auto2+300,90,30,vfh[2],27,0,_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_View_event(_Context)) != -1) break;

							}
						continue;
					case	0x6 :
						/* ModelName */
						continue;
					case	0x8 :
						/* TargetFile */
						continue;
					case	0x9 :
						/* NoConfirm */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_NoConfirm += 1;
							_Context->value_NoConfirm &= 1;
							}
						continue;
					case	0xa :
						/* Build */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Build += 1;
							_Context->value_Build &= 1;
							}
						continue;
					case	0xb :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto2+20,_Context->y_auto2+300,120,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto2+20,_Context->y_auto2+300,120,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0xc :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto2+450,_Context->y_auto2+300,120,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto2+450,_Context->y_auto2+300,120,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
						continue;
					case	0xd :
						/* Verbose */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Verbose += 1;
							_Context->value_Verbose &= 1;
							}
						continue;
					case	0xe :
						/* TargetType */
						continue;
					case	0xf :
						/* IsDocument */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsDocument += 1;
							_Context->value_IsDocument &= 1;
							}
						continue;
					case	0x10 :
						/* ProdLang */
						continue;
					case	0x12 :
						/* DocumentFile */
						continue;
					case	0x13 :
						/* Makefile */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_Makefile += 1;
							_Context->value_Makefile &= 1;
							}
						continue;
					case	0x14 :
						/* MakefileName */
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
				_Context->focus_item=20;
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

public	int	accept_production_properties(
	char * pModelName,
	char * pTargetFile,
	char * pNoConfirm,
	char * pBuild,
	char * pVerbose,
	char * pTargetType,
	char * pIsDocument,
	char * pProdLang,
	char * pDocumentFile,
	char * pMakefile,
	char * pMakefileName)
{
	int	status=0;
	struct accept_production_properties_context * _Context=(struct accept_production_properties_context*) 0;
	status = accept_production_properties_create(
	&_Context,
	 pModelName,
	 pTargetFile,
	 pNoConfirm,
	 pBuild,
	 pVerbose,
	 pTargetType,
	 pIsDocument,
	 pProdLang,
	 pDocumentFile,
	 pMakefile,
	 pMakefileName);
	if ( status != 0) return(status);
	status = accept_production_properties_show(_Context);
		enter_modal();
	status = accept_production_properties_focus(_Context);
		leave_modal();
	status = accept_production_properties_hide(_Context);
	status = accept_production_properties_remove(
	_Context,
	 pModelName,
	 pTargetFile,
	 pNoConfirm,
	 pBuild,
	 pVerbose,
	 pTargetType,
	 pIsDocument,
	 pProdLang,
	 pDocumentFile,
	 pMakefile,
	 pMakefileName);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vmprod_c */
