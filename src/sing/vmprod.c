
#ifndef _vmprod_c
#define _vmprod_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vmprod.xml                                               */
/* Target         : vmprod.c                                                 */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en__auto2   ""
#define fr__auto2   ""
#define it__auto2   ""
#define es__auto2   ""
#define de__auto2   ""
#define nl__auto2   ""
#define pt__auto2   ""
#define xx__auto2   ""
#define en_auto7   "Production Parameters of Project Model"
#define fr_auto7   "ParamŠtres de production du projet"
#define it_auto7   "Production Parameters of Project Model"
#define es_auto7   "Production Parameters of Project Model"
#define de_auto7   "Production Parameters of Project Model"
#define nl_auto7   "Production Parameters of Project Model"
#define pt_auto7   "Production Parameters of Project Model"
#define xx_auto7   "Production Parameters of Project Model"
#define en__auto7   ""
#define fr__auto7   ""
#define it__auto7   ""
#define es__auto7   ""
#define de__auto7   ""
#define nl__auto7   ""
#define pt__auto7   ""
#define xx__auto7   ""
#define en_Auto3579   "Nature"
#define fr_Auto3579   "Nature"
#define it_Auto3579   "Nature"
#define es_Auto3579   "Nature"
#define de_Auto3579   "Nature"
#define nl_Auto3579   "Nature"
#define pt_Auto3579   "Nature"
#define xx_Auto3579   "Nature"
#define en__Auto3579   ""
#define fr__Auto3579   ""
#define it__Auto3579   ""
#define es__Auto3579   ""
#define de__Auto3579   ""
#define nl__Auto3579   ""
#define pt__Auto3579   ""
#define xx__Auto3579   ""
#define en_Auto3580   "Language"
#define fr_Auto3580   "Langage"
#define it_Auto3580   "Language"
#define es_Auto3580   "Language"
#define de_Auto3580   "Language"
#define nl_Auto3580   "Language"
#define pt_Auto3580   "Language"
#define xx_Auto3580   "Language"
#define en__Auto3580   ""
#define en_Auto3581   "Filename"
#define fr_Auto3581   "Nom de fichier"
#define it_Auto3581   "Filename"
#define es_Auto3581   "Filename"
#define de_Auto3581   "Datei"
#define nl_Auto3581   "Filename"
#define pt_Auto3581   "Filename"
#define xx_Auto3581   "Filename"
#define en__Auto3581   ""
#define en_Auto3582   "Filename"
#define fr_Auto3582   "Nom de fichier"
#define it_Auto3582   "Filename"
#define es_Auto3582   "Filename"
#define de_Auto3582   "Datei"
#define nl_Auto3582   "Filename"
#define pt_Auto3582   "Filename"
#define xx_Auto3582   "Filename"
#define en__Auto3582   ""
#define fr__Auto3582   ""
#define it__Auto3582   ""
#define es__Auto3582   ""
#define de__Auto3582   ""
#define nl__Auto3582   ""
#define pt__Auto3582   ""
#define xx__Auto3582   ""
#define en_Auto3583   "Filename"
#define fr_Auto3583   "Nom de fichier"
#define it_Auto3583   "Filename"
#define es_Auto3583   "Filename"
#define de_Auto3583   "Datei"
#define nl_Auto3583   "Filename"
#define pt_Auto3583   "Filename"
#define xx_Auto3583   "Filename"
#define en__Auto3583   ""
#define en_ModelName   ""
#define en__ModelName   ""
#define en_TargetFile   ""
#define en__TargetFile   ""
#define en_TargetNature   "none|module|program|overlay|library|package"
#define fr_TargetNature   "sans|module|program|overlay|library"
#define it_TargetNature   "none|module|program|overlay|library"
#define es_TargetNature   "none|module|program|overlay|library"
#define de_TargetNature   "none|module|program|overlay|library"
#define nl_TargetNature   "none|module|program|overlay|library"
#define pt_TargetNature   "none|module|program|overlay|library"
#define xx_TargetNature   "none|module|program|overlay|library"
#define en__TargetNature   ""
#define en__ProdLang   ""
#define en_IsDocument   "&Document"
#define fr_IsDocument   "&Document"
#define it_IsDocument   "&Document"
#define es_IsDocument   "&Document"
#define de_IsDocument   "&Document"
#define nl_IsDocument   "&Document"
#define pt_IsDocument   "&Document"
#define xx_IsDocument   "&Document"
#define en_DocumentFile   ""
#define en__DocumentFile   ""
#define en_Makefile   "&Makefile"
#define fr_Makefile   "&Makefile"
#define it_Makefile   "&Makefile"
#define es_Makefile   "&Makefile"
#define de_Makefile   "&Makefile"
#define nl_Makefile   "&Makefile"
#define pt_Makefile   "&Makefile"
#define xx_Makefile   "&Makefile"
#define en_MakefileName   ""
#define en__MakefileName   ""
#define en_Verbose   "V&isualise"
#define fr_Verbose   "V&isualiser"
#define it_Verbose   "V&isualise"
#define es_Verbose   "V&isualise"
#define de_Verbose   "V&isualise"
#define nl_Verbose   "V&isualise"
#define pt_Verbose   "V&isualise"
#define xx_Verbose   "V&isualise"
#define en_NoConfirm   "A&utomatic"
#define fr_NoConfirm   "&Automatique"
#define it_NoConfirm   "A&utomatic"
#define es_NoConfirm   "A&utomatic"
#define de_NoConfirm   "A&utomatic"
#define nl_NoConfirm   "A&utomatic"
#define pt_NoConfirm   "A&utomatic"
#define xx_NoConfirm   "A&utomatic"
#define en_Build   "&Force Build"
#define fr_Build   "&Forcer"
#define it_Build   "&Force Build"
#define es_Build   "&Force Build"
#define de_Build   "&Force Build"
#define nl_Build   "&Force Build"
#define pt_Build   "&Force Build"
#define xx_Build   "&Force Build"
#define en_Accept   "ok.gif"
#define fr_Accept   "ok.gif"
#define it_Accept   "ok.gif"
#define es_Accept   "ok.gif"
#define de_Accept   "ok.gif"
#define nl_Accept   "ok.gif"
#define pt_Accept   "ok.gif"
#define xx_Accept   "ok.gif"
#define en__Accept   ""
#define en_UseAed   "&Edit"
#define fr_UseAed   "&Edition"
#define it_UseAed   "&Edit"
#define es_UseAed   "&Edit"
#define de_UseAed   "&Edit"
#define nl_UseAed   "&Edit"
#define pt_UseAed   "&Edit"
#define xx_UseAed   "&Edit"
#define en__UseAed   ""
#define en_Html   "&Html"
#define fr_Html   "&Html"
#define it_Html   "&Html"
#define es_Html   "&Html"
#define de_Html   "&Html"
#define nl_Html   "&Html"
#define pt_Html   "&Html"
#define xx_Html   "&Html"
#define en__Html   ""
#define fr__Html   ""
#define it__Html   ""
#define es__Html   ""
#define de__Html   ""
#define nl__Html   ""
#define pt__Html   ""
#define xx__Html   ""
#define en_View   "&View"
#define fr_View   "&Visualiser"
#define it_View   "&View"
#define es_View   "&View"
#define de_View   "&View"
#define nl_View   "&View"
#define pt_View   "&View"
#define xx_View   "&View"
#define en__View   ""
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"
#define en__Cancel   ""

private struct accept_production_properties_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_auto2[8];
	char * hint_auto2[8];
	int	x_auto2;
	int	y_auto2;
	int	w_auto2;
	int	h_auto2;
	char * hint_Auto3576[8];
	char * hint_Auto3577[8];
	char * hint_Auto3578[8];
	char * msg_auto7[8];
	char * hint_auto7[8];
	char * msg_Auto3579[8];
	char * hint_Auto3579[8];
	char * msg_Auto3580[8];
	char * hint_Auto3580[8];
	char * msg_Auto3581[8];
	char * hint_Auto3581[8];
	char * msg_Auto3582[8];
	char * hint_Auto3582[8];
	char * msg_Auto3583[8];
	char * hint_Auto3583[8];
	char * hint_ModelName[8];
	char	buffer_ModelName[256];
	char * hint_TargetFile[8];
	char	buffer_TargetFile[256];
	char * msg_TargetNature[8];
	char * hint_TargetNature[8];
	int	value_TargetNature;
	char * msg_ProdLang[8];
	char * hint_ProdLang[8];
	int	value_ProdLang;
	char * msg_IsDocument[8];
	int	trigger_IsDocument;
	char * hint_IsDocument[8];
	int	value_IsDocument;
	char * hint_DocumentFile[8];
	char	buffer_DocumentFile[256];
	char * msg_Makefile[8];
	int	trigger_Makefile;
	char * hint_Makefile[8];
	int	value_Makefile;
	char * hint_MakefileName[8];
	char	buffer_MakefileName[256];
	char * msg_Verbose[8];
	int	trigger_Verbose;
	char * hint_Verbose[8];
	int	value_Verbose;
	char * msg_NoConfirm[8];
	int	trigger_NoConfirm;
	char * hint_NoConfirm[8];
	int	value_NoConfirm;
	char * msg_Build[8];
	int	trigger_Build;
	char * hint_Build[8];
	int	value_Build;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_UseAed[8];
	int	trigger_UseAed;
	char * hint_UseAed[8];
	char * msg_Html[8];
	int	trigger_Html;
	char * hint_Html[8];
	char * msg_View[8];
	int	trigger_View;
	char * hint_View[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[12];
	};
static int	vfh[16];
private int on_Html_show(struct accept_production_properties_context * _Context);
private int on_Accept_event(struct accept_production_properties_context * _Context);
private int on_UseAed_event(struct accept_production_properties_context * _Context);
private int on_Html_event(struct accept_production_properties_context * _Context);
private int on_View_event(struct accept_production_properties_context * _Context);
private int on_Cancel_event(struct accept_production_properties_context * _Context);

public	int	accept_production_properties_create(
	struct accept_production_properties_context ** cptr,
	char * pModelName,
	char * pTargetFile,
	char * pTargetNature,
	char * pProdLang,
	char * pIsDocument,
	char * pDocumentFile,
	char * pMakefile,
	char * pMakefileName,
	char * pVerbose,
	char * pNoConfirm,
	char * pBuild)
{

	int i;
	struct accept_production_properties_context * _Context=(struct accept_production_properties_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_production_properties_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=21;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWSWSWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_ModelName, 255, pModelName);
		visual_transferin(_Context->buffer_TargetFile, 255, pTargetFile);
		visual_transferin((void *) 0, 0, pTargetNature);
		if (!( pTargetNature )) _Context->value_TargetNature=0;
		else	_Context->value_TargetNature = *((int *)pTargetNature);
		visual_transferin((void *) 0, 0, pProdLang);
		if (!( pProdLang )) _Context->value_ProdLang=0;
		else	_Context->value_ProdLang = *((int *)pProdLang);
		visual_transferin((void *) 0, 0, pIsDocument);
		if (!( pIsDocument )) _Context->value_IsDocument=0;
		else	_Context->value_IsDocument = *((int *)pIsDocument);
		visual_transferin(_Context->buffer_DocumentFile, 255, pDocumentFile);
		visual_transferin((void *) 0, 0, pMakefile);
		if (!( pMakefile )) _Context->value_Makefile=0;
		else	_Context->value_Makefile = *((int *)pMakefile);
		visual_transferin(_Context->buffer_MakefileName, 255, pMakefileName);
		visual_transferin((void *) 0, 0, pVerbose);
		if (!( pVerbose )) _Context->value_Verbose=0;
		else	_Context->value_Verbose = *((int *)pVerbose);
		visual_transferin((void *) 0, 0, pNoConfirm);
		if (!( pNoConfirm )) _Context->value_NoConfirm=0;
		else	_Context->value_NoConfirm = *((int *)pNoConfirm);
		visual_transferin((void *) 0, 0, pBuild);
		if (!( pBuild )) _Context->value_Build=0;
		else	_Context->value_Build = *((int *)pBuild);
		}
	for (i=0; i < 8; i++)_Context->msg_auto2[i]=" ";
	_Context->hint_auto2[0]=en__auto2;
	_Context->hint_auto2[1]=fr__auto2;
	_Context->hint_auto2[2]=it__auto2;
	_Context->hint_auto2[3]=es__auto2;
	_Context->hint_auto2[4]=de__auto2;
	_Context->hint_auto2[5]=nl__auto2;
	_Context->hint_auto2[6]=pt__auto2;
	_Context->hint_auto2[7]=xx__auto2;
	_Context->x_auto2=100;
	_Context->y_auto2=105;
	_Context->w_auto2=600;
	_Context->h_auto2=390;
	_Context->window_col=0;
	_Context->window_row=0;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3579[i]=" ";
	_Context->msg_Auto3579[0]=en_Auto3579;
	_Context->msg_Auto3579[1]=fr_Auto3579;
	_Context->msg_Auto3579[2]=it_Auto3579;
	_Context->msg_Auto3579[3]=es_Auto3579;
	_Context->msg_Auto3579[4]=de_Auto3579;
	_Context->msg_Auto3579[5]=nl_Auto3579;
	_Context->msg_Auto3579[6]=pt_Auto3579;
	_Context->msg_Auto3579[7]=xx_Auto3579;
	_Context->hint_Auto3579[0]=en__Auto3579;
	_Context->hint_Auto3579[1]=fr__Auto3579;
	_Context->hint_Auto3579[2]=it__Auto3579;
	_Context->hint_Auto3579[3]=es__Auto3579;
	_Context->hint_Auto3579[4]=de__Auto3579;
	_Context->hint_Auto3579[5]=nl__Auto3579;
	_Context->hint_Auto3579[6]=pt__Auto3579;
	_Context->hint_Auto3579[7]=xx__Auto3579;
	for (i=0; i < 8; i++)_Context->msg_Auto3580[i]=" ";
	_Context->msg_Auto3580[0]=en_Auto3580;
	_Context->msg_Auto3580[1]=fr_Auto3580;
	_Context->msg_Auto3580[2]=it_Auto3580;
	_Context->msg_Auto3580[3]=es_Auto3580;
	_Context->msg_Auto3580[4]=de_Auto3580;
	_Context->msg_Auto3580[5]=nl_Auto3580;
	_Context->msg_Auto3580[6]=pt_Auto3580;
	_Context->msg_Auto3580[7]=xx_Auto3580;
	_Context->hint_Auto3580[0]=en__Auto3580;
	for (i=0; i < 8; i++)_Context->msg_Auto3581[i]=" ";
	_Context->msg_Auto3581[0]=en_Auto3581;
	_Context->msg_Auto3581[1]=fr_Auto3581;
	_Context->msg_Auto3581[2]=it_Auto3581;
	_Context->msg_Auto3581[3]=es_Auto3581;
	_Context->msg_Auto3581[4]=de_Auto3581;
	_Context->msg_Auto3581[5]=nl_Auto3581;
	_Context->msg_Auto3581[6]=pt_Auto3581;
	_Context->msg_Auto3581[7]=xx_Auto3581;
	_Context->hint_Auto3581[0]=en__Auto3581;
	for (i=0; i < 8; i++)_Context->msg_Auto3582[i]=" ";
	_Context->msg_Auto3582[0]=en_Auto3582;
	_Context->msg_Auto3582[1]=fr_Auto3582;
	_Context->msg_Auto3582[2]=it_Auto3582;
	_Context->msg_Auto3582[3]=es_Auto3582;
	_Context->msg_Auto3582[4]=de_Auto3582;
	_Context->msg_Auto3582[5]=nl_Auto3582;
	_Context->msg_Auto3582[6]=pt_Auto3582;
	_Context->msg_Auto3582[7]=xx_Auto3582;
	_Context->hint_Auto3582[0]=en__Auto3582;
	_Context->hint_Auto3582[1]=fr__Auto3582;
	_Context->hint_Auto3582[2]=it__Auto3582;
	_Context->hint_Auto3582[3]=es__Auto3582;
	_Context->hint_Auto3582[4]=de__Auto3582;
	_Context->hint_Auto3582[5]=nl__Auto3582;
	_Context->hint_Auto3582[6]=pt__Auto3582;
	_Context->hint_Auto3582[7]=xx__Auto3582;
	for (i=0; i < 8; i++)_Context->msg_Auto3583[i]=" ";
	_Context->msg_Auto3583[0]=en_Auto3583;
	_Context->msg_Auto3583[1]=fr_Auto3583;
	_Context->msg_Auto3583[2]=it_Auto3583;
	_Context->msg_Auto3583[3]=es_Auto3583;
	_Context->msg_Auto3583[4]=de_Auto3583;
	_Context->msg_Auto3583[5]=nl_Auto3583;
	_Context->msg_Auto3583[6]=pt_Auto3583;
	_Context->msg_Auto3583[7]=xx_Auto3583;
	_Context->hint_Auto3583[0]=en__Auto3583;
	_Context->hint_ModelName[0]=en__ModelName;
	_Context->hint_TargetFile[0]=en__TargetFile;
	for (i=0; i < 8; i++)_Context->msg_TargetNature[i]=" ";
	_Context->msg_TargetNature[0]=en_TargetNature;
	_Context->msg_TargetNature[1]=fr_TargetNature;
	_Context->msg_TargetNature[2]=it_TargetNature;
	_Context->msg_TargetNature[3]=es_TargetNature;
	_Context->msg_TargetNature[4]=de_TargetNature;
	_Context->msg_TargetNature[5]=nl_TargetNature;
	_Context->msg_TargetNature[6]=pt_TargetNature;
	_Context->msg_TargetNature[7]=xx_TargetNature;
	_Context->hint_TargetNature[0]=en__TargetNature;
	for (i=0; i < 8; i++)_Context->msg_ProdLang[i]=" ";
	_Context->hint_ProdLang[0]=en__ProdLang;
	for (i=0; i < 8; i++)_Context->msg_IsDocument[i]=" ";
	_Context->msg_IsDocument[0]=en_IsDocument;
	_Context->msg_IsDocument[1]=fr_IsDocument;
	_Context->msg_IsDocument[2]=it_IsDocument;
	_Context->msg_IsDocument[3]=es_IsDocument;
	_Context->msg_IsDocument[4]=de_IsDocument;
	_Context->msg_IsDocument[5]=nl_IsDocument;
	_Context->msg_IsDocument[6]=pt_IsDocument;
	_Context->msg_IsDocument[7]=xx_IsDocument;
	_Context->hint_DocumentFile[0]=en__DocumentFile;
	for (i=0; i < 8; i++)_Context->msg_Makefile[i]=" ";
	_Context->msg_Makefile[0]=en_Makefile;
	_Context->msg_Makefile[1]=fr_Makefile;
	_Context->msg_Makefile[2]=it_Makefile;
	_Context->msg_Makefile[3]=es_Makefile;
	_Context->msg_Makefile[4]=de_Makefile;
	_Context->msg_Makefile[5]=nl_Makefile;
	_Context->msg_Makefile[6]=pt_Makefile;
	_Context->msg_Makefile[7]=xx_Makefile;
	_Context->hint_MakefileName[0]=en__MakefileName;
	for (i=0; i < 8; i++)_Context->msg_Verbose[i]=" ";
	_Context->msg_Verbose[0]=en_Verbose;
	_Context->msg_Verbose[1]=fr_Verbose;
	_Context->msg_Verbose[2]=it_Verbose;
	_Context->msg_Verbose[3]=es_Verbose;
	_Context->msg_Verbose[4]=de_Verbose;
	_Context->msg_Verbose[5]=nl_Verbose;
	_Context->msg_Verbose[6]=pt_Verbose;
	_Context->msg_Verbose[7]=xx_Verbose;
	for (i=0; i < 8; i++)_Context->msg_NoConfirm[i]=" ";
	_Context->msg_NoConfirm[0]=en_NoConfirm;
	_Context->msg_NoConfirm[1]=fr_NoConfirm;
	_Context->msg_NoConfirm[2]=it_NoConfirm;
	_Context->msg_NoConfirm[3]=es_NoConfirm;
	_Context->msg_NoConfirm[4]=de_NoConfirm;
	_Context->msg_NoConfirm[5]=nl_NoConfirm;
	_Context->msg_NoConfirm[6]=pt_NoConfirm;
	_Context->msg_NoConfirm[7]=xx_NoConfirm;
	for (i=0; i < 8; i++)_Context->msg_Build[i]=" ";
	_Context->msg_Build[0]=en_Build;
	_Context->msg_Build[1]=fr_Build;
	_Context->msg_Build[2]=it_Build;
	_Context->msg_Build[3]=es_Build;
	_Context->msg_Build[4]=de_Build;
	_Context->msg_Build[5]=nl_Build;
	_Context->msg_Build[6]=pt_Build;
	_Context->msg_Build[7]=xx_Build;
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
	for (i=0; i < 8; i++)_Context->msg_UseAed[i]=" ";
	_Context->msg_UseAed[0]=en_UseAed;
	_Context->msg_UseAed[1]=fr_UseAed;
	_Context->msg_UseAed[2]=it_UseAed;
	_Context->msg_UseAed[3]=es_UseAed;
	_Context->msg_UseAed[4]=de_UseAed;
	_Context->msg_UseAed[5]=nl_UseAed;
	_Context->msg_UseAed[6]=pt_UseAed;
	_Context->msg_UseAed[7]=xx_UseAed;
	_Context->hint_UseAed[0]=en__UseAed;
	for (i=0; i < 8; i++)_Context->msg_Html[i]=" ";
	_Context->msg_Html[0]=en_Html;
	_Context->msg_Html[1]=fr_Html;
	_Context->msg_Html[2]=it_Html;
	_Context->msg_Html[3]=es_Html;
	_Context->msg_Html[4]=de_Html;
	_Context->msg_Html[5]=nl_Html;
	_Context->msg_Html[6]=pt_Html;
	_Context->msg_Html[7]=xx_Html;
	_Context->hint_Html[0]=en__Html;
	_Context->hint_Html[1]=fr__Html;
	_Context->hint_Html[2]=it__Html;
	_Context->hint_Html[3]=es__Html;
	_Context->hint_Html[4]=de__Html;
	_Context->hint_Html[5]=nl__Html;
	_Context->hint_Html[6]=pt__Html;
	_Context->hint_Html[7]=xx__Html;
	for (i=0; i < 8; i++)_Context->msg_View[i]=" ";
	_Context->msg_View[0]=en_View;
	_Context->msg_View[1]=fr_View;
	_Context->msg_View[2]=it_View;
	_Context->msg_View[3]=es_View;
	_Context->msg_View[4]=de_View;
	_Context->msg_View[5]=nl_View;
	_Context->msg_View[6]=pt_View;
	_Context->msg_View[7]=xx_View;
	_Context->hint_View[0]=en__View;
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
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto2,_Context->y_auto2,600+10,390+10);
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
	char * pTargetNature,
	char * pProdLang,
	char * pIsDocument,
	char * pDocumentFile,
	char * pMakefile,
	char * pMakefileName,
	char * pVerbose,
	char * pNoConfirm,
	char * pBuild)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWSWSWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_ModelName, 255, pModelName);
		visual_transferout(_Context->buffer_TargetFile, 255, pTargetFile);
		visual_transferout((void *) 0, 0, pTargetNature);
		if ( pTargetNature != (char *) 0)
			*((int*)pTargetNature) = _Context->value_TargetNature;
		visual_transferout((void *) 0, 0, pProdLang);
		if ( pProdLang != (char *) 0)
			*((int*)pProdLang) = _Context->value_ProdLang;
		visual_transferout((void *) 0, 0, pIsDocument);
		if ( pIsDocument != (char *) 0)
			*((int*)pIsDocument) = _Context->value_IsDocument;
		visual_transferout(_Context->buffer_DocumentFile, 255, pDocumentFile);
		visual_transferout((void *) 0, 0, pMakefile);
		if ( pMakefile != (char *) 0)
			*((int*)pMakefile) = _Context->value_Makefile;
		visual_transferout(_Context->buffer_MakefileName, 255, pMakefileName);
		visual_transferout((void *) 0, 0, pVerbose);
		if ( pVerbose != (char *) 0)
			*((int*)pVerbose) = _Context->value_Verbose;
		visual_transferout((void *) 0, 0, pNoConfirm);
		if ( pNoConfirm != (char *) 0)
			*((int*)pNoConfirm) = _Context->value_NoConfirm;
		visual_transferout((void *) 0, 0, pBuild);
		if ( pBuild != (char *) 0)
			*((int*)pBuild) = _Context->value_Build;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Html_show(struct accept_production_properties_context * _Context) {
	if(is_expert_user()){
		_Context->trigger_Html=visual_trigger_code(_Context->msg_Html[_Context->language],strlen(_Context->msg_Html[_Context->language]));
	visual_button(_Context->x_auto2+240,_Context->y_auto2+340,112,32,vfh[2],27,0,_Context->msg_Html[_Context->language],strlen(_Context->msg_Html[_Context->language]),0);
;
	}
	return(-1);
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
	if (((_Context->status = visual_styled_element(_Context->x_auto2,_Context->y_auto2,600,390,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_auto2,_Context->y_auto2,600,390,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+90,560,80,2);
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+180,560,80,2);
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+270,560,40,2);
	visual_text(_Context->x_auto2+20,_Context->y_auto2+30,560,32,vfh[3],34,0,_Context->msg_auto7[_Context->language],strlen(_Context->msg_auto7[_Context->language]),1282);
	visual_text(_Context->x_auto2+30,_Context->y_auto2+140,98,16,vfh[2],27,0,_Context->msg_Auto3579[_Context->language],strlen(_Context->msg_Auto3579[_Context->language]),1);
	visual_text(_Context->x_auto2+270,_Context->y_auto2+140,128,19,vfh[2],27,0,_Context->msg_Auto3580[_Context->language],strlen(_Context->msg_Auto3580[_Context->language]),1);
	visual_text(_Context->x_auto2+30,_Context->y_auto2+110,98,16,vfh[2],34,0,_Context->msg_Auto3581[_Context->language],strlen(_Context->msg_Auto3581[_Context->language]),1);
	visual_text(_Context->x_auto2+130,_Context->y_auto2+200,98,16,vfh[2],34,0,_Context->msg_Auto3582[_Context->language],strlen(_Context->msg_Auto3582[_Context->language]),1);
	visual_text(_Context->x_auto2+130,_Context->y_auto2+230,98,16,vfh[2],34,0,_Context->msg_Auto3583[_Context->language],strlen(_Context->msg_Auto3583[_Context->language]),1);
	visual_frame(_Context->x_auto2+20,_Context->y_auto2+60,560+2,16+2,5);
	visual_text(_Context->x_auto2+20+1,_Context->y_auto2+60+1,560,16,vfh[1],34,0,_Context->buffer_ModelName,255,0);
	visual_frame(_Context->x_auto2+130,_Context->y_auto2+110,432+2,16+2,5);
	visual_text(_Context->x_auto2+130+1,_Context->y_auto2+110+1,432,16,vfh[1],34,0,_Context->buffer_TargetFile,255,0);
	visual_select(_Context->x_auto2+130,_Context->y_auto2+140,120,64,vfh[1],27,0,parse_selection(_Context->msg_TargetNature[_Context->language],&_Context->value_TargetNature),0);
	visual_select(_Context->x_auto2+400,_Context->y_auto2+140,160,64,vfh[1],27,0,parse_selection(ProductionLanguageList,&_Context->value_ProdLang),0);
	_Context->trigger_IsDocument=visual_trigger_code(_Context->msg_IsDocument[_Context->language],strlen(_Context->msg_IsDocument[_Context->language]));
	visual_check(_Context->x_auto2+30,_Context->y_auto2+200,112,16,vfh[2],27,0,_Context->msg_IsDocument[_Context->language],strlen(_Context->msg_IsDocument[_Context->language]),_Context->value_IsDocument|0);
	visual_frame(_Context->x_auto2+230,_Context->y_auto2+200,336+2,16+2,5);
	visual_text(_Context->x_auto2+230+1,_Context->y_auto2+200+1,336,16,vfh[1],27,0,_Context->buffer_DocumentFile,255,0);
	_Context->trigger_Makefile=visual_trigger_code(_Context->msg_Makefile[_Context->language],strlen(_Context->msg_Makefile[_Context->language]));
	visual_check(_Context->x_auto2+30,_Context->y_auto2+230,98,16,vfh[2],16,28,_Context->msg_Makefile[_Context->language],strlen(_Context->msg_Makefile[_Context->language]),_Context->value_Makefile|0);
	visual_frame(_Context->x_auto2+230,_Context->y_auto2+230,336+2,16+2,5);
	visual_text(_Context->x_auto2+230+1,_Context->y_auto2+230+1,336,16,vfh[1],0,0,_Context->buffer_MakefileName,255,0);
	_Context->trigger_Verbose=visual_trigger_code(_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]));
	visual_check(_Context->x_auto2+100,_Context->y_auto2+280,112,16,vfh[2],34,0,_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]),_Context->value_Verbose|0);
	_Context->trigger_NoConfirm=visual_trigger_code(_Context->msg_NoConfirm[_Context->language],strlen(_Context->msg_NoConfirm[_Context->language]));
	visual_check(_Context->x_auto2+240,_Context->y_auto2+280,140,16,vfh[2],34,0,_Context->msg_NoConfirm[_Context->language],strlen(_Context->msg_NoConfirm[_Context->language]),_Context->value_NoConfirm|0);
	_Context->trigger_Build=visual_trigger_code(_Context->msg_Build[_Context->language],strlen(_Context->msg_Build[_Context->language]));
	visual_check(_Context->x_auto2+380,_Context->y_auto2+280,154,16,vfh[2],34,0,_Context->msg_Build[_Context->language],strlen(_Context->msg_Build[_Context->language]),_Context->value_Build|0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_auto2+20,_Context->y_auto2+330,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_UseAed=visual_trigger_code(_Context->msg_UseAed[_Context->language],strlen(_Context->msg_UseAed[_Context->language]));
	visual_button(_Context->x_auto2+100,_Context->y_auto2+340,112,32,vfh[2],27,0,_Context->msg_UseAed[_Context->language],strlen(_Context->msg_UseAed[_Context->language]),0);
	(void) on_Html_show(_Context);
	_Context->trigger_View=visual_trigger_code(_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]));
	visual_button(_Context->x_auto2+380,_Context->y_auto2+340,112,32,vfh[2],27,0,_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto2+520,_Context->y_auto2+330,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_thaw(_Context->x_auto2,_Context->y_auto2,600,390);

	return(0);
}

private int ModelName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The MODELNAME edit field presents the name of the application model ";
			mptr[1]="   for inspection.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TargetFile_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "The PRODUCTION filename edit field presents the production target ";
			mptr[1]="filename for  modification or inspection. The value of this edit field ";
			mptr[2]="will be used as required by the project production nature control ";
			mptr[3]="to provide the name of the file to which global production will be ";
			mptr[4]="sent.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		case 1 : 
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

private int TargetNature_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[28];
			mptr[0] = "This control allows selection of the project production nature. A ";
			mptr[1]="value may be taken from the following list :  ";
			mptr[2]="  ";
			mptr[3]="none ";
			mptr[4]="   no production is performed other than that required for  the individual ";
			mptr[5]="model components.  ";
			mptr[6]="program ";
			mptr[7]="   the project model is a program source, all text items will be generated ";
			mptr[8]="as inclusions.  ";
			mptr[9]="module ";
			mptr[10]="   the project model is a module source, all text items will be generated ";
			mptr[11]="as inclusions.  ";
			mptr[12]="overlay ";
			mptr[13]="   the project model is an overlay source, all text items will be generated ";
			mptr[14]="as inclusions.  ";
			mptr[15]="library ";
			mptr[16]="   the project model is a class library  source, all text items will ";
			mptr[17]="be generated as inclusions.  ";
			mptr[18]="package ";
			mptr[19]="   the project model is a product package and will generate a makefile ";
			mptr[20]="describing the various components of the product.  ";
			mptr[21]="  ";
			mptr[22]=" ";
			mptr[23]="All application model types other than none will perform the corresponding ";
			mptr[24]="post production operation as required by the specific model type. ";
			mptr[25]=" ";
			mptr[26]=" ";
			mptr[27]="  ";
			return(visual_online_help(mptr,28));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ProdLang_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This check box allows selection of the production language associated ";
			mptr[1]="with the project production model nature defined by the preceeding ";
			mptr[2]="select control.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsDocument_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "The DOCUMENT check box when checked allows the production of an HTML ";
			mptr[1]="document containing all Application model Images and documentary text ";
			mptr[2]="from the sub-components. This will be generated to the Document Filename ";
			mptr[3]="target if one has been specified.  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DocumentFile_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows a full path and filename to be specified for ";
			mptr[1]="the top level HTML document to be produced in response to the activation ";
			mptr[2]="of document production by the corresponding check box.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Ce champs permet de specifier le nom de fichier du document HTML principale ";
			mptr[1]="a generer pendant l'operation de production documentatire.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Makefile_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "When this control has been checked the production mechanism will generate ";
			mptr[1]="a description of the entire project to a standard makefile.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MakefileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the full path and filename of the file to which ";
			mptr[1]="the project make file will be generated if the  corresponding check ";
			mptr[2]="control has been activated.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Verbose_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The VERBOSE check box controls the visualisation of the various application ";
			mptr[1]="components as they are presented for effective production.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int NoConfirm_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "The AUTOMATIC check box when checked alleviates the need to validate ";
			mptr[1]="the various stages involved in the production of the target and its ";
			mptr[2]=" documentation. When unchecked each stage will present the corresponding ";
			mptr[3]="visual frame for validation or cancellation.  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Build_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The FORCE BUILD check box when checked performs production of all ";
			mptr[1]="partial products in a systematic manner. When unchecked only the entities ";
			mptr[2]="which are out of date will be produced.  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Accept_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the ACCEPT button any changes made to the various parameters ";
			mptr[1]="will take effect.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int UseAed_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing on the EDIT button the document source will be presented ";
			mptr[1]="for inspection via the Standard Text Editor mechanisms.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Html_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing on this button you will gain access to the Html Document ";
			mptr[1]="Generation parameters for inspection and eventual modification.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int View_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "By pressing on the VIEW button the system navigator will be activated ";
			mptr[1]="allowing the finalised version of the production document to be consulted. ";
			mptr[2]="Under UseIT NETSCAPE will be activated.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Cancel_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the CANCEL button any modifications performed will be ";
			mptr[1]="discarded.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
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

		visual_thaw(_Context->x_auto2,_Context->y_auto2,600,390);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_production_properties_context * _Context) {
	return(13);
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
private int on_Html_event(struct accept_production_properties_context * _Context) {
	if(is_expert_user()){
		accept_production_properties_hide(_Context);
;
	camera_document_Properties(0);
		accept_production_properties_show(_Context);
;
	}
	else 	/* UseAed */
	accept_production_properties_show(_Context);
	_Context->focus_item=18;
;
	return(-1);
}
private int on_View_event(struct accept_production_properties_context * _Context) {
	use_document_navigator(_Context->buffer_DocumentFile,255);
		accept_production_properties_show(_Context);
;
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
		if (_Context->trigger_IsDocument == mb ) return(10);
		if (_Context->trigger_Makefile == mb ) return(12);
		if (_Context->trigger_Verbose == mb ) return(14);
		if (_Context->trigger_NoConfirm == mb ) return(15);
		if (_Context->trigger_Build == mb ) return(16);
		if (_Context->trigger_Accept == mb ) return(17);
		if (_Context->trigger_UseAed == mb ) return(18);
		if (_Context->trigger_Html == mb ) return(19);
		if (_Context->trigger_View == mb ) return(20);
		if (_Context->trigger_Cancel == mb ) return(21);
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
	if (( mx >= (_Context->x_auto2+20) ) 
	&&  ( my >= (_Context->y_auto2+60) ) 
	&&  ( mx <= (_Context->x_auto2+20+560) ) 
	&&  ( my <= (_Context->y_auto2+60+16))) {
		return(6); /* ModelName */
		}
	if (( mx >= (_Context->x_auto2+130) ) 
	&&  ( my >= (_Context->y_auto2+110) ) 
	&&  ( mx <= (_Context->x_auto2+130+432) ) 
	&&  ( my <= (_Context->y_auto2+110+16))) {
		return(7); /* TargetFile */
		}
	if (( mx >= (_Context->x_auto2+130+0) ) 
	&&  ( my >= (_Context->y_auto2+140) ) 
	&&  ( mx <= (_Context->x_auto2+130+120) ) 
	&&  ( my <= (_Context->y_auto2+140+16))) {
		return(8); /* TargetNature */
		}
	if (( mx >= (_Context->x_auto2+400+0) ) 
	&&  ( my >= (_Context->y_auto2+140) ) 
	&&  ( mx <= (_Context->x_auto2+400+160) ) 
	&&  ( my <= (_Context->y_auto2+140+16))) {
		return(9); /* ProdLang */
		}
	if (( mx >= (_Context->x_auto2+30) ) 
	&&  ( my >= (_Context->y_auto2+200) ) 
	&&  ( mx <= (_Context->x_auto2+30+112) ) 
	&&  ( my <= (_Context->y_auto2+200+16))) {
		return(10); /* IsDocument */
		}
	if (( mx >= (_Context->x_auto2+230) ) 
	&&  ( my >= (_Context->y_auto2+200) ) 
	&&  ( mx <= (_Context->x_auto2+230+336) ) 
	&&  ( my <= (_Context->y_auto2+200+16))) {
		return(11); /* DocumentFile */
		}
	if (( mx >= (_Context->x_auto2+30) ) 
	&&  ( my >= (_Context->y_auto2+230) ) 
	&&  ( mx <= (_Context->x_auto2+30+98) ) 
	&&  ( my <= (_Context->y_auto2+230+16))) {
		return(12); /* Makefile */
		}
	if (( mx >= (_Context->x_auto2+230) ) 
	&&  ( my >= (_Context->y_auto2+230) ) 
	&&  ( mx <= (_Context->x_auto2+230+336) ) 
	&&  ( my <= (_Context->y_auto2+230+16))) {
		return(13); /* MakefileName */
		}
	if (( mx >= (_Context->x_auto2+100) ) 
	&&  ( my >= (_Context->y_auto2+280) ) 
	&&  ( mx <= (_Context->x_auto2+100+112) ) 
	&&  ( my <= (_Context->y_auto2+280+16))) {
		return(14); /* Verbose */
		}
	if (( mx >= (_Context->x_auto2+240) ) 
	&&  ( my >= (_Context->y_auto2+280) ) 
	&&  ( mx <= (_Context->x_auto2+240+140) ) 
	&&  ( my <= (_Context->y_auto2+280+16))) {
		return(15); /* NoConfirm */
		}
	if (( mx >= (_Context->x_auto2+380) ) 
	&&  ( my >= (_Context->y_auto2+280) ) 
	&&  ( mx <= (_Context->x_auto2+380+154) ) 
	&&  ( my <= (_Context->y_auto2+280+16))) {
		return(16); /* Build */
		}
	if (( mx >= (_Context->x_auto2+20) ) 
	&&  ( my >= (_Context->y_auto2+330) ) 
	&&  ( mx <= (_Context->x_auto2+20+56) ) 
	&&  ( my <= (_Context->y_auto2+330+48))) {
		return(17); /* Accept */
		}
	if (( mx >= (_Context->x_auto2+100) ) 
	&&  ( my >= (_Context->y_auto2+340) ) 
	&&  ( mx <= (_Context->x_auto2+100+112) ) 
	&&  ( my <= (_Context->y_auto2+340+32))) {
		return(18); /* UseAed */
		}
	if (( mx >= (_Context->x_auto2+240) ) 
	&&  ( my >= (_Context->y_auto2+340) ) 
	&&  ( mx <= (_Context->x_auto2+240+112) ) 
	&&  ( my <= (_Context->y_auto2+340+32))) {
		return(19); /* Html */
		}
	if (( mx >= (_Context->x_auto2+380) ) 
	&&  ( my >= (_Context->y_auto2+340) ) 
	&&  ( mx <= (_Context->x_auto2+380+112) ) 
	&&  ( my <= (_Context->y_auto2+340+32))) {
		return(20); /* View */
		}
	if (( mx >= (_Context->x_auto2+520) ) 
	&&  ( my >= (_Context->y_auto2+330) ) 
	&&  ( mx <= (_Context->x_auto2+520+56) ) 
	&&  ( my <= (_Context->y_auto2+330+48))) {
		return(21); /* Cancel */
		}

	return(-1);
}


public	int	accept_production_properties_focus(struct accept_production_properties_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x7 :
				/* TargetFile */
				_Context->keycode = visual_edit(_Context->x_auto2+130+1,_Context->y_auto2+110+1,432,16,vfh[1],_Context->buffer_TargetFile,255);
			break;
			case	0x8 :
				/* TargetNature */
				_Context->keycode = visual_select(_Context->x_auto2+130,_Context->y_auto2+140,120,64,vfh[1],27,0,parse_selection(_Context->msg_TargetNature[_Context->language],&_Context->value_TargetNature),2);
				break;
			case	0x9 :
				/* ProdLang */
				_Context->keycode = visual_select(_Context->x_auto2+400,_Context->y_auto2+140,160,64,vfh[1],27,0,parse_selection(ProductionLanguageList,&_Context->value_ProdLang),2);
				break;
			case	0xa :
				/* IsDocument */
				visual_check(_Context->x_auto2+30,_Context->y_auto2+200,112,16,vfh[2],27,0,_Context->msg_IsDocument[_Context->language],strlen(_Context->msg_IsDocument[_Context->language]),(_Context->value_IsDocument |2));
				_Context->keycode = visual_getch();
				_Context->trigger_IsDocument=visual_trigger_code(_Context->msg_IsDocument[_Context->language],strlen(_Context->msg_IsDocument[_Context->language]));
	visual_check(_Context->x_auto2+30,_Context->y_auto2+200,112,16,vfh[2],27,0,_Context->msg_IsDocument[_Context->language],strlen(_Context->msg_IsDocument[_Context->language]),_Context->value_IsDocument|0);
				break;
			case	0xb :
				/* DocumentFile */
				_Context->keycode = visual_edit(_Context->x_auto2+230+1,_Context->y_auto2+200+1,336,16,vfh[1],_Context->buffer_DocumentFile,255);
			break;
			case	0xc :
				/* Makefile */
				visual_check(_Context->x_auto2+30,_Context->y_auto2+230,98,16,vfh[2],16,28,_Context->msg_Makefile[_Context->language],strlen(_Context->msg_Makefile[_Context->language]),(_Context->value_Makefile |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Makefile=visual_trigger_code(_Context->msg_Makefile[_Context->language],strlen(_Context->msg_Makefile[_Context->language]));
	visual_check(_Context->x_auto2+30,_Context->y_auto2+230,98,16,vfh[2],16,28,_Context->msg_Makefile[_Context->language],strlen(_Context->msg_Makefile[_Context->language]),_Context->value_Makefile|0);
				break;
			case	0xd :
				/* MakefileName */
				_Context->keycode = visual_edit(_Context->x_auto2+230+1,_Context->y_auto2+230+1,336,16,vfh[1],_Context->buffer_MakefileName,255);
			break;
			case	0xe :
				/* Verbose */
				visual_check(_Context->x_auto2+100,_Context->y_auto2+280,112,16,vfh[2],34,0,_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]),(_Context->value_Verbose |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Verbose=visual_trigger_code(_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]));
	visual_check(_Context->x_auto2+100,_Context->y_auto2+280,112,16,vfh[2],34,0,_Context->msg_Verbose[_Context->language],strlen(_Context->msg_Verbose[_Context->language]),_Context->value_Verbose|0);
				break;
			case	0xf :
				/* NoConfirm */
				visual_check(_Context->x_auto2+240,_Context->y_auto2+280,140,16,vfh[2],34,0,_Context->msg_NoConfirm[_Context->language],strlen(_Context->msg_NoConfirm[_Context->language]),(_Context->value_NoConfirm |2));
				_Context->keycode = visual_getch();
				_Context->trigger_NoConfirm=visual_trigger_code(_Context->msg_NoConfirm[_Context->language],strlen(_Context->msg_NoConfirm[_Context->language]));
	visual_check(_Context->x_auto2+240,_Context->y_auto2+280,140,16,vfh[2],34,0,_Context->msg_NoConfirm[_Context->language],strlen(_Context->msg_NoConfirm[_Context->language]),_Context->value_NoConfirm|0);
				break;
			case	0x10 :
				/* Build */
				visual_check(_Context->x_auto2+380,_Context->y_auto2+280,154,16,vfh[2],34,0,_Context->msg_Build[_Context->language],strlen(_Context->msg_Build[_Context->language]),(_Context->value_Build |2));
				_Context->keycode = visual_getch();
				_Context->trigger_Build=visual_trigger_code(_Context->msg_Build[_Context->language],strlen(_Context->msg_Build[_Context->language]));
	visual_check(_Context->x_auto2+380,_Context->y_auto2+280,154,16,vfh[2],34,0,_Context->msg_Build[_Context->language],strlen(_Context->msg_Build[_Context->language]),_Context->value_Build|0);
				break;
			case	0x11 :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(_Context->x_auto2+20,_Context->y_auto2+330,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_auto2+20,_Context->y_auto2+330,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0x12 :
				/* UseAed */
				_Context->trigger_UseAed=visual_trigger_code(_Context->msg_UseAed[_Context->language],strlen(_Context->msg_UseAed[_Context->language]));
				visual_button(_Context->x_auto2+100,_Context->y_auto2+340,112,32,vfh[2],27,0,_Context->msg_UseAed[_Context->language],strlen(_Context->msg_UseAed[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_UseAed=visual_trigger_code(_Context->msg_UseAed[_Context->language],strlen(_Context->msg_UseAed[_Context->language]));
	visual_button(_Context->x_auto2+100,_Context->y_auto2+340,112,32,vfh[2],27,0,_Context->msg_UseAed[_Context->language],strlen(_Context->msg_UseAed[_Context->language]),0);
				break;
			case	0x14 :
				/* View */
				_Context->trigger_View=visual_trigger_code(_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]));
				visual_button(_Context->x_auto2+380,_Context->y_auto2+340,112,32,vfh[2],27,0,_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_View=visual_trigger_code(_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]));
	visual_button(_Context->x_auto2+380,_Context->y_auto2+340,112,32,vfh[2],27,0,_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]),0);
				break;
			case	0x15 :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_auto2+520,_Context->y_auto2+330,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto2+520,_Context->y_auto2+330,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
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
			_Context->focus_item=21;
			accept_production_properties_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_production_properties_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x6 :
						if (ModelName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (TargetFile_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (TargetNature_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (ProdLang_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (IsDocument_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (DocumentFile_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (Makefile_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (MakefileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (Verbose_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (NoConfirm_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (Build_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (Accept_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (UseAed_help(_Context) != 0) { continue; }
						else { break; }
					case	0x13 :
						if (Html_help(_Context) != 0) { continue; }
						else { break; }
					case	0x14 :
						if (View_help(_Context) != 0) { continue; }
						else { break; }
					case	0x15 :
						if (Cancel_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* auto2 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x6 :
					/* ModelName */
					continue;
				case	0x7 :
					/* TargetFile */
					continue;
				case	0x8 :
					/* TargetNature */
					continue;
				case	0x9 :
					/* ProdLang */
					continue;
				case	0xa :
					/* IsDocument */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsDocument += 1;
						_Context->value_IsDocument &= 1;
						}
					continue;
				case	0xb :
					/* DocumentFile */
					continue;
				case	0xc :
					/* Makefile */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Makefile += 1;
						_Context->value_Makefile &= 1;
						}
					continue;
				case	0xd :
					/* MakefileName */
					continue;
				case	0xe :
					/* Verbose */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Verbose += 1;
						_Context->value_Verbose &= 1;
						}
					continue;
				case	0xf :
					/* NoConfirm */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_NoConfirm += 1;
						_Context->value_NoConfirm &= 1;
						}
					continue;
				case	0x10 :
					/* Build */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Build += 1;
						_Context->value_Build &= 1;
						}
					continue;
				case	0x11 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_auto2+20,_Context->y_auto2+330,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_auto2+20,_Context->y_auto2+330,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x12 :
					/* UseAed */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_UseAed=visual_trigger_code(_Context->msg_UseAed[_Context->language],strlen(_Context->msg_UseAed[_Context->language]));
						visual_button(_Context->x_auto2+100,_Context->y_auto2+340,112,32,vfh[2],27,0,_Context->msg_UseAed[_Context->language],strlen(_Context->msg_UseAed[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_UseAed=visual_trigger_code(_Context->msg_UseAed[_Context->language],strlen(_Context->msg_UseAed[_Context->language]));
	visual_button(_Context->x_auto2+100,_Context->y_auto2+340,112,32,vfh[2],27,0,_Context->msg_UseAed[_Context->language],strlen(_Context->msg_UseAed[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_UseAed_event(_Context)) != -1) break;

						}
					continue;
				case	0x13 :
					/* Html */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Html=visual_trigger_code(_Context->msg_Html[_Context->language],strlen(_Context->msg_Html[_Context->language]));
						visual_button(_Context->x_auto2+240,_Context->y_auto2+340,112,32,vfh[2],27,0,_Context->msg_Html[_Context->language],strlen(_Context->msg_Html[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Html=visual_trigger_code(_Context->msg_Html[_Context->language],strlen(_Context->msg_Html[_Context->language]));
	visual_button(_Context->x_auto2+240,_Context->y_auto2+340,112,32,vfh[2],27,0,_Context->msg_Html[_Context->language],strlen(_Context->msg_Html[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Html_event(_Context)) != -1) break;

						}
					continue;
				case	0x14 :
					/* View */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_View=visual_trigger_code(_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]));
						visual_button(_Context->x_auto2+380,_Context->y_auto2+340,112,32,vfh[2],27,0,_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_View=visual_trigger_code(_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]));
	visual_button(_Context->x_auto2+380,_Context->y_auto2+340,112,32,vfh[2],27,0,_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_View_event(_Context)) != -1) break;

						}
					continue;
				case	0x15 :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_auto2+520,_Context->y_auto2+330,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto2+520,_Context->y_auto2+330,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

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

public	int	accept_production_properties(
	char * pModelName,
	char * pTargetFile,
	char * pTargetNature,
	char * pProdLang,
	char * pIsDocument,
	char * pDocumentFile,
	char * pMakefile,
	char * pMakefileName,
	char * pVerbose,
	char * pNoConfirm,
	char * pBuild)
{
	int	status=0;
	struct accept_production_properties_context * _Context=(struct accept_production_properties_context*) 0;
	status = accept_production_properties_create(
	&_Context,
	 pModelName,
	 pTargetFile,
	 pTargetNature,
	 pProdLang,
	 pIsDocument,
	 pDocumentFile,
	 pMakefile,
	 pMakefileName,
	 pVerbose,
	 pNoConfirm,
	 pBuild);
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
	 pTargetNature,
	 pProdLang,
	 pIsDocument,
	 pDocumentFile,
	 pMakefile,
	 pMakefileName,
	 pVerbose,
	 pNoConfirm,
	 pBuild);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vmprod_c */
