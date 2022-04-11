
#ifndef _vaprod_c
#define _vaprod_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vaprod.xml  */
/* Target         : vaprod.c  */
/* Identification : 0.0-1100519943-7158.7157 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#include "singlang.h"
#define en_auto2   "Sing : Version 1.0a"
#define fr_auto2   "Sing : Version 1.0a"
#define en_Auto6301   "skin.gif"
#define fr_Auto6301   "skin.gif"
#define en_Auto6302   "ABAL and ABAL++ Source Production"
#define fr_Auto6302   "Production de Source ABAL et ABAL++"
#define en_Production   "&Production"
#define fr_Production   "&Production"
#define es_Production   "&Produccion"
#define de_Production   "&Produktion"
#define en_Auto6305   "Nature"
#define fr_Auto6305   "Nature"
#define en_Auto6306   "abalicon.gif"
#define fr_Auto6306   "abalicon.gif"
#define en_auto7   "Abal++ Production Filename"
#define fr_auto7   "Nom de Fichier de Production Abal++"
#define en_auto52   "Program/Module Identifier"
#define fr_auto52   "Identificateur de Programme/Module"
#define en_Packaging   "Program|Overlay|Module|Include"
#define fr_Packaging   "Programme|Overlay|Module|Include"
#define en_IsAutoTrad   "A&uto Translation"
#define fr_IsAutoTrad   "A&uto-Traduction"
#define en_IsTrueColour   "True Colour RGB"
#define fr_IsTrueColour   "TrueColor RVB"
#define it_IsTrueColour   ""
#define es_IsTrueColour   ""
#define de_IsTrueColour   ""
#define nl_IsTrueColour   ""
#define pt_IsTrueColour   ""
#define xx_IsTrueColour   ""
#define en_Accept   "&Accept"
#define fr_Accept   "&Valider"
#define en_Cancel   "&Cancel"
#define fr_Cancel   "&Annuler"
#define en_Auto6307   "Dimensions"
#define fr_Auto6307   "Dimensions"
#define en_Dimensions   "320x200|640x400|640x480|800x600|1024x786|1280x1024"
#define fr_Dimensions   "320x200|640x400|640x480|800x600|1024x786|1280x1024"
#define en_UseAtr   "&Translate"
#define fr_UseAtr   "&Traduire"
#define en_Link   "&Link"
#define fr_Link   "&Lien"
#define en_UseEdit   "&Edit"
#define fr_UseEdit   "&Edition"
#define en_Select   "&Select"
#define fr_Select   "&S‚lection"
#define en_Inclusion   "&Inclusion"
#define fr_Inclusion   "&Inclusion"
#define en_Dependance   ""
#define en_Modules   "&Modules"
#define fr_Modules   "&Modules"
#define en_Linkage   ""
#define en_PragmaPage   "P&ragmas"
#define fr_PragmaPage   "P&ragmas"
#define en_Auto6308   "Tcode Constants"
#define fr_Auto6308   "Constantes Tcode"
#define en_Auto6309   "Tcode Pragmas"
#define fr_Auto6309   "Pragmas Tcode"
#define en_UseDiezeMem   "#mem"
#define fr_UseDiezeMem   "#mem"
#define en_UseDiezeStack   "#stack"
#define fr_UseDiezeStack   "#stack"
#define en_UseDiezeFiles   "#files"
#define fr_UseDiezeFiles   "#files"
#define en_UseDiezeHeap   "#heap"
#define fr_UseDiezeHeap   "#heap"
#define en_DiezeMem   ""
#define en_DiezeStack   ""
#define en_DiezeFiles   ""
#define en_DiezeHeap   ""
#define en_UsePragmaFile   "Pragma File"
#define fr_UsePragmaFile   "Fichier de Pragmas"
#define it_UsePragmaFile   "Pragma File"
#define es_UsePragmaFile   "Pragma File"
#define de_UsePragmaFile   "Pragma File"
#define nl_UsePragmaFile   "Pragma File"
#define pt_UsePragmaFile   "Pragma File"
#define xx_UsePragmaFile   "Pragma File"
#define en_PragmaFileName   ""
#define en_RespectCase   "Respect Case"
#define fr_RespectCase   "Respecter la Casse"
#define en_OptimiseTables   "Optimise Tables"
#define fr_OptimiseTables   "Optimiser Tables"
#define en_UseTokenSize   "TokenSize"
#define fr_UseTokenSize   "TokenSize"
#define en_UseLabelSize   "LabelSize"
#define fr_UseLabelSize   "LabelSize"
#define it_UseLabelSize   ""
#define es_UseLabelSize   ""
#define de_UseLabelSize   ""
#define nl_UseLabelSize   ""
#define pt_UseLabelSize   ""
#define xx_UseLabelSize   ""
#define en_TokenSize   ""
#define fr_TokenSize   ""
#define en_LabelSize   ""
#define fr_LabelSize   ""
static int	vfh[10];

private struct accept_abal_production_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[4+1];
	char * msg_auto2[8];
	int	x_auto2;
	int	y_auto2;
	int	w_auto2;
	int	h_auto2;
	char * msg_Auto6301[8];
	char * msg_Auto6302[8];
	char * msg_Production[8];
	int	trigger_Production;
	int	page_number;
	char * msg_Auto6305[8];
	char * msg_Auto6306[8];
	char * msg_auto7[8];
	char	buffer_FileName[68];
	char * msg_auto52[8];
	char	buffer_Identity[68];
	char * msg_Packaging[8];
	int	value_Packaging;
	char * msg_IsAutoTrad[8];
	int	trigger_IsAutoTrad;
	int	value_IsAutoTrad;
	char * msg_IsTrueColour[8];
	int	trigger_IsTrueColour;
	int	value_IsTrueColour;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * msg_Auto6307[8];
	char * msg_Dimensions[8];
	int	value_Dimensions;
	char * msg_UseAtr[8];
	int	trigger_UseAtr;
	char * msg_Link[8];
	int	trigger_Link;
	char * msg_UseEdit[8];
	int	trigger_UseEdit;
	char * msg_Select[8];
	int	trigger_Select;
	char * msg_Inclusion[8];
	int	trigger_Inclusion;
	char * buffer_Dependance;
	char * msg_Modules[8];
	int	trigger_Modules;
	char * buffer_Linkage;
	char * msg_PragmaPage[8];
	int	trigger_PragmaPage;
	char * msg_Auto6308[8];
	char * msg_Auto6309[8];
	char * msg_UseDiezeMem[8];
	int	trigger_UseDiezeMem;
	int	value_UseDiezeMem;
	char * msg_UseDiezeStack[8];
	int	trigger_UseDiezeStack;
	int	value_UseDiezeStack;
	char * msg_UseDiezeFiles[8];
	int	trigger_UseDiezeFiles;
	int	value_UseDiezeFiles;
	char * msg_UseDiezeHeap[8];
	int	trigger_UseDiezeHeap;
	int	value_UseDiezeHeap;
	char	buffer_DiezeMem[11];
	char	buffer_DiezeStack[11];
	char	buffer_DiezeFiles[11];
	char	buffer_DiezeHeap[11];
	char * msg_UsePragmaFile[8];
	int	trigger_UsePragmaFile;
	int	value_UsePragmaFile;
	char	buffer_PragmaFileName[45];
	char * msg_RespectCase[8];
	int	trigger_RespectCase;
	int	value_RespectCase;
	char * msg_OptimiseTables[8];
	int	trigger_OptimiseTables;
	int	value_OptimiseTables;
	char * msg_UseTokenSize[8];
	int	trigger_UseTokenSize;
	int	value_UseTokenSize;
	char * msg_UseLabelSize[8];
	int	trigger_UseLabelSize;
	int	value_UseLabelSize;
	char	buffer_TokenSize[10];
	char	buffer_LabelSize[10];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[25];
	};

public	int	accept_abal_production_create(
	struct accept_abal_production_context ** cptr,
	char * pFileName,
	char * pIdentity,
	char * pPackaging,
	char * pIsAutoTrad,
	char * pIsTrueColour,
	char * pDimensions,
	char * pDependance,
	char * pLinkage,
	char * pUseDiezeMem,
	char * pUseDiezeStack,
	char * pUseDiezeFiles,
	char * pUseDiezeHeap,
	char * pDiezeMem,
	char * pDiezeStack,
	char * pDiezeFiles,
	char * pDiezeHeap,
	char * pUsePragmaFile,
	char * pPragmaFileName,
	char * pRespectCase,
	char * pOptimiseTables,
	char * pUseTokenSize,
	char * pUseLabelSize,
	char * pTokenSize,
	char * pLabelSize)
{

	int i;
	struct accept_abal_production_context * _Context=(struct accept_abal_production_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_abal_production_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=38;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWWTTWWWWWWWWWSWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 67, pFileName);
		visual_transferin(_Context->buffer_Identity, 67, pIdentity);
		visual_transferin((void *) 0, 0, pPackaging);
		if (!( pPackaging )) _Context->value_Packaging=0;
		else	_Context->value_Packaging = *((int *)pPackaging);
		visual_transferin((void *) 0, 0, pIsAutoTrad);
		if (!( pIsAutoTrad )) _Context->value_IsAutoTrad=0;
		else	_Context->value_IsAutoTrad = *((int *)pIsAutoTrad);
		visual_transferin((void *) 0, 0, pIsTrueColour);
		if (!( pIsTrueColour )) _Context->value_IsTrueColour=0;
		else	_Context->value_IsTrueColour = *((int *)pIsTrueColour);
		visual_transferin((void *) 0, 0, pDimensions);
		if (!( pDimensions )) _Context->value_Dimensions=0;
		else	_Context->value_Dimensions = *((int *)pDimensions);
				_Context->buffer_Dependance=(char *) 0;
		visual_transferin(&_Context->buffer_Dependance, 1035, pDependance);
				_Context->buffer_Linkage=(char *) 0;
		visual_transferin(&_Context->buffer_Linkage, 1035, pLinkage);
		visual_transferin((void *) 0, 0, pUseDiezeMem);
		if (!( pUseDiezeMem )) _Context->value_UseDiezeMem=0;
		else	_Context->value_UseDiezeMem = *((int *)pUseDiezeMem);
		visual_transferin((void *) 0, 0, pUseDiezeStack);
		if (!( pUseDiezeStack )) _Context->value_UseDiezeStack=0;
		else	_Context->value_UseDiezeStack = *((int *)pUseDiezeStack);
		visual_transferin((void *) 0, 0, pUseDiezeFiles);
		if (!( pUseDiezeFiles )) _Context->value_UseDiezeFiles=0;
		else	_Context->value_UseDiezeFiles = *((int *)pUseDiezeFiles);
		visual_transferin((void *) 0, 0, pUseDiezeHeap);
		if (!( pUseDiezeHeap )) _Context->value_UseDiezeHeap=0;
		else	_Context->value_UseDiezeHeap = *((int *)pUseDiezeHeap);
		visual_transferin(_Context->buffer_DiezeMem, 10, pDiezeMem);
		visual_transferin(_Context->buffer_DiezeStack, 10, pDiezeStack);
		visual_transferin(_Context->buffer_DiezeFiles, 10, pDiezeFiles);
		visual_transferin(_Context->buffer_DiezeHeap, 10, pDiezeHeap);
		visual_transferin((void *) 0, 0, pUsePragmaFile);
		if (!( pUsePragmaFile )) _Context->value_UsePragmaFile=0;
		else	_Context->value_UsePragmaFile = *((int *)pUsePragmaFile);
		visual_transferin(_Context->buffer_PragmaFileName, 44, pPragmaFileName);
		visual_transferin((void *) 0, 0, pRespectCase);
		if (!( pRespectCase )) _Context->value_RespectCase=0;
		else	_Context->value_RespectCase = *((int *)pRespectCase);
		visual_transferin((void *) 0, 0, pOptimiseTables);
		if (!( pOptimiseTables )) _Context->value_OptimiseTables=0;
		else	_Context->value_OptimiseTables = *((int *)pOptimiseTables);
		visual_transferin((void *) 0, 0, pUseTokenSize);
		if (!( pUseTokenSize )) _Context->value_UseTokenSize=0;
		else	_Context->value_UseTokenSize = *((int *)pUseTokenSize);
		visual_transferin((void *) 0, 0, pUseLabelSize);
		if (!( pUseLabelSize )) _Context->value_UseLabelSize=0;
		else	_Context->value_UseLabelSize = *((int *)pUseLabelSize);
		visual_transferin(_Context->buffer_TokenSize, 9, pTokenSize);
		visual_transferin(_Context->buffer_LabelSize, 9, pLabelSize);
		}
	for (i=0; i < 8; i++)_Context->msg_auto2[i]=" ";
	_Context->msg_auto2[0]=en_auto2;
	_Context->msg_auto2[1]=fr_auto2;
	_Context->x_auto2=90;
	_Context->y_auto2=80;
	_Context->w_auto2=620;
	_Context->h_auto2=440;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto6301[i]=" ";
	_Context->msg_Auto6301[0]=en_Auto6301;
	_Context->msg_Auto6301[1]=fr_Auto6301;
	for (i=0; i < 8; i++)_Context->msg_Auto6302[i]=" ";
	_Context->msg_Auto6302[0]=en_Auto6302;
	_Context->msg_Auto6302[1]=fr_Auto6302;
	for (i=0; i < 8; i++)_Context->msg_Production[i]=" ";
	_Context->msg_Production[0]=en_Production;
	_Context->msg_Production[1]=fr_Production;
	_Context->msg_Production[3]=es_Production;
	_Context->msg_Production[4]=de_Production;
	_Context->focus_pages[1]=2;
	for (i=0; i < 8; i++)_Context->msg_Auto6305[i]=" ";
	_Context->msg_Auto6305[0]=en_Auto6305;
	_Context->msg_Auto6305[1]=fr_Auto6305;
	for (i=0; i < 8; i++)_Context->msg_Auto6306[i]=" ";
	_Context->msg_Auto6306[0]=en_Auto6306;
	_Context->msg_Auto6306[1]=fr_Auto6306;
	for (i=0; i < 8; i++)_Context->msg_auto7[i]=" ";
	_Context->msg_auto7[0]=en_auto7;
	_Context->msg_auto7[1]=fr_auto7;
	for (i=0; i < 8; i++)_Context->msg_auto52[i]=" ";
	_Context->msg_auto52[0]=en_auto52;
	_Context->msg_auto52[1]=fr_auto52;
	for (i=0; i < 8; i++)_Context->msg_Packaging[i]=" ";
	_Context->msg_Packaging[0]=en_Packaging;
	_Context->msg_Packaging[1]=fr_Packaging;
	for (i=0; i < 8; i++)_Context->msg_IsAutoTrad[i]=" ";
	_Context->msg_IsAutoTrad[0]=en_IsAutoTrad;
	_Context->msg_IsAutoTrad[1]=fr_IsAutoTrad;
	for (i=0; i < 8; i++)_Context->msg_IsTrueColour[i]=" ";
	_Context->msg_IsTrueColour[0]=en_IsTrueColour;
	_Context->msg_IsTrueColour[1]=fr_IsTrueColour;
	_Context->msg_IsTrueColour[2]=it_IsTrueColour;
	_Context->msg_IsTrueColour[3]=es_IsTrueColour;
	_Context->msg_IsTrueColour[4]=de_IsTrueColour;
	_Context->msg_IsTrueColour[5]=nl_IsTrueColour;
	_Context->msg_IsTrueColour[6]=pt_IsTrueColour;
	_Context->msg_IsTrueColour[7]=xx_IsTrueColour;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	for (i=0; i < 8; i++)_Context->msg_Auto6307[i]=" ";
	_Context->msg_Auto6307[0]=en_Auto6307;
	_Context->msg_Auto6307[1]=fr_Auto6307;
	for (i=0; i < 8; i++)_Context->msg_Dimensions[i]=" ";
	_Context->msg_Dimensions[0]=en_Dimensions;
	_Context->msg_Dimensions[1]=fr_Dimensions;
	for (i=0; i < 8; i++)_Context->msg_UseAtr[i]=" ";
	_Context->msg_UseAtr[0]=en_UseAtr;
	_Context->msg_UseAtr[1]=fr_UseAtr;
	for (i=0; i < 8; i++)_Context->msg_Link[i]=" ";
	_Context->msg_Link[0]=en_Link;
	_Context->msg_Link[1]=fr_Link;
	for (i=0; i < 8; i++)_Context->msg_UseEdit[i]=" ";
	_Context->msg_UseEdit[0]=en_UseEdit;
	_Context->msg_UseEdit[1]=fr_UseEdit;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	for (i=0; i < 8; i++)_Context->msg_Inclusion[i]=" ";
	_Context->msg_Inclusion[0]=en_Inclusion;
	_Context->msg_Inclusion[1]=fr_Inclusion;
	_Context->focus_pages[2]=18;
	for (i=0; i < 8; i++)_Context->msg_Modules[i]=" ";
	_Context->msg_Modules[0]=en_Modules;
	_Context->msg_Modules[1]=fr_Modules;
	_Context->focus_pages[3]=20;
	for (i=0; i < 8; i++)_Context->msg_PragmaPage[i]=" ";
	_Context->msg_PragmaPage[0]=en_PragmaPage;
	_Context->msg_PragmaPage[1]=fr_PragmaPage;
	_Context->focus_pages[4]=22;
	for (i=0; i < 8; i++)_Context->msg_Auto6308[i]=" ";
	_Context->msg_Auto6308[0]=en_Auto6308;
	_Context->msg_Auto6308[1]=fr_Auto6308;
	for (i=0; i < 8; i++)_Context->msg_Auto6309[i]=" ";
	_Context->msg_Auto6309[0]=en_Auto6309;
	_Context->msg_Auto6309[1]=fr_Auto6309;
	for (i=0; i < 8; i++)_Context->msg_UseDiezeMem[i]=" ";
	_Context->msg_UseDiezeMem[0]=en_UseDiezeMem;
	_Context->msg_UseDiezeMem[1]=fr_UseDiezeMem;
	for (i=0; i < 8; i++)_Context->msg_UseDiezeStack[i]=" ";
	_Context->msg_UseDiezeStack[0]=en_UseDiezeStack;
	_Context->msg_UseDiezeStack[1]=fr_UseDiezeStack;
	for (i=0; i < 8; i++)_Context->msg_UseDiezeFiles[i]=" ";
	_Context->msg_UseDiezeFiles[0]=en_UseDiezeFiles;
	_Context->msg_UseDiezeFiles[1]=fr_UseDiezeFiles;
	for (i=0; i < 8; i++)_Context->msg_UseDiezeHeap[i]=" ";
	_Context->msg_UseDiezeHeap[0]=en_UseDiezeHeap;
	_Context->msg_UseDiezeHeap[1]=fr_UseDiezeHeap;
	for (i=0; i < 8; i++)_Context->msg_UsePragmaFile[i]=" ";
	_Context->msg_UsePragmaFile[0]=en_UsePragmaFile;
	_Context->msg_UsePragmaFile[1]=fr_UsePragmaFile;
	_Context->msg_UsePragmaFile[2]=it_UsePragmaFile;
	_Context->msg_UsePragmaFile[3]=es_UsePragmaFile;
	_Context->msg_UsePragmaFile[4]=de_UsePragmaFile;
	_Context->msg_UsePragmaFile[5]=nl_UsePragmaFile;
	_Context->msg_UsePragmaFile[6]=pt_UsePragmaFile;
	_Context->msg_UsePragmaFile[7]=xx_UsePragmaFile;
	for (i=0; i < 8; i++)_Context->msg_RespectCase[i]=" ";
	_Context->msg_RespectCase[0]=en_RespectCase;
	_Context->msg_RespectCase[1]=fr_RespectCase;
	for (i=0; i < 8; i++)_Context->msg_OptimiseTables[i]=" ";
	_Context->msg_OptimiseTables[0]=en_OptimiseTables;
	_Context->msg_OptimiseTables[1]=fr_OptimiseTables;
	for (i=0; i < 8; i++)_Context->msg_UseTokenSize[i]=" ";
	_Context->msg_UseTokenSize[0]=en_UseTokenSize;
	_Context->msg_UseTokenSize[1]=fr_UseTokenSize;
	for (i=0; i < 8; i++)_Context->msg_UseLabelSize[i]=" ";
	_Context->msg_UseLabelSize[0]=en_UseLabelSize;
	_Context->msg_UseLabelSize[1]=fr_UseLabelSize;
	_Context->msg_UseLabelSize[2]=it_UseLabelSize;
	_Context->msg_UseLabelSize[3]=es_UseLabelSize;
	_Context->msg_UseLabelSize[4]=de_UseLabelSize;
	_Context->msg_UseLabelSize[5]=nl_UseLabelSize;
	_Context->msg_UseLabelSize[6]=pt_UseLabelSize;
	_Context->msg_UseLabelSize[7]=xx_UseLabelSize;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_auto2,_Context->y_auto2,620+10,440+10);
	return(0);
}
private int on_auto2_hide(struct accept_abal_production_context * _Context) {
	close_window_editor();
	return(-1);
}

public 	int	accept_abal_production_hide(struct accept_abal_production_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	(void) on_auto2_hide(_Context);
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_auto2,_Context->y_auto2);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_abal_production_remove(
	struct accept_abal_production_context * _Context,
	char * pFileName,
	char * pIdentity,
	char * pPackaging,
	char * pIsAutoTrad,
	char * pIsTrueColour,
	char * pDimensions,
	char * pDependance,
	char * pLinkage,
	char * pUseDiezeMem,
	char * pUseDiezeStack,
	char * pUseDiezeFiles,
	char * pUseDiezeHeap,
	char * pDiezeMem,
	char * pDiezeStack,
	char * pDiezeFiles,
	char * pDiezeHeap,
	char * pUsePragmaFile,
	char * pPragmaFileName,
	char * pRespectCase,
	char * pOptimiseTables,
	char * pUseTokenSize,
	char * pUseLabelSize,
	char * pTokenSize,
	char * pLabelSize)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWWTTWWWWWWWWWSWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 67, pFileName);
		visual_transferout(_Context->buffer_Identity, 67, pIdentity);
		visual_transferout((void *) 0, 0, pPackaging);
		if ( pPackaging != (char *) 0)
			*((int*)pPackaging) = _Context->value_Packaging;
		visual_transferout((void *) 0, 0, pIsAutoTrad);
		if ( pIsAutoTrad != (char *) 0)
			*((int*)pIsAutoTrad) = _Context->value_IsAutoTrad;
		visual_transferout((void *) 0, 0, pIsTrueColour);
		if ( pIsTrueColour != (char *) 0)
			*((int*)pIsTrueColour) = _Context->value_IsTrueColour;
		visual_transferout((void *) 0, 0, pDimensions);
		if ( pDimensions != (char *) 0)
			*((int*)pDimensions) = _Context->value_Dimensions;
		visual_transferout(&_Context->buffer_Dependance, 1035, pDependance);
		visual_transferout(&_Context->buffer_Linkage, 1035, pLinkage);
		visual_transferout((void *) 0, 0, pUseDiezeMem);
		if ( pUseDiezeMem != (char *) 0)
			*((int*)pUseDiezeMem) = _Context->value_UseDiezeMem;
		visual_transferout((void *) 0, 0, pUseDiezeStack);
		if ( pUseDiezeStack != (char *) 0)
			*((int*)pUseDiezeStack) = _Context->value_UseDiezeStack;
		visual_transferout((void *) 0, 0, pUseDiezeFiles);
		if ( pUseDiezeFiles != (char *) 0)
			*((int*)pUseDiezeFiles) = _Context->value_UseDiezeFiles;
		visual_transferout((void *) 0, 0, pUseDiezeHeap);
		if ( pUseDiezeHeap != (char *) 0)
			*((int*)pUseDiezeHeap) = _Context->value_UseDiezeHeap;
		visual_transferout(_Context->buffer_DiezeMem, 10, pDiezeMem);
		visual_transferout(_Context->buffer_DiezeStack, 10, pDiezeStack);
		visual_transferout(_Context->buffer_DiezeFiles, 10, pDiezeFiles);
		visual_transferout(_Context->buffer_DiezeHeap, 10, pDiezeHeap);
		visual_transferout((void *) 0, 0, pUsePragmaFile);
		if ( pUsePragmaFile != (char *) 0)
			*((int*)pUsePragmaFile) = _Context->value_UsePragmaFile;
		visual_transferout(_Context->buffer_PragmaFileName, 44, pPragmaFileName);
		visual_transferout((void *) 0, 0, pRespectCase);
		if ( pRespectCase != (char *) 0)
			*((int*)pRespectCase) = _Context->value_RespectCase;
		visual_transferout((void *) 0, 0, pOptimiseTables);
		if ( pOptimiseTables != (char *) 0)
			*((int*)pOptimiseTables) = _Context->value_OptimiseTables;
		visual_transferout((void *) 0, 0, pUseTokenSize);
		if ( pUseTokenSize != (char *) 0)
			*((int*)pUseTokenSize) = _Context->value_UseTokenSize;
		visual_transferout((void *) 0, 0, pUseLabelSize);
		if ( pUseLabelSize != (char *) 0)
			*((int*)pUseLabelSize) = _Context->value_UseLabelSize;
		visual_transferout(_Context->buffer_TokenSize, 9, pTokenSize);
		visual_transferout(_Context->buffer_LabelSize, 9, pLabelSize);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Inclusion_show(struct accept_abal_production_context * _Context) {
	open_window_editor(_Context->x_auto2+30,_Context->y_auto2+110,
	552,240,_Context->buffer_Dependance);
	return(-1);
}
private int on_Dependance_show(struct accept_abal_production_context * _Context) {
	visual_frame(_Context->x_auto2+30,_Context->y_auto2+110,552+2,240+2,5);
;
	show_window_editor();
	return(-1);
}
private int on_Modules_show(struct accept_abal_production_context * _Context) {
	open_window_editor(_Context->x_auto2+30,_Context->y_auto2+110,
	552,240,_Context->buffer_Linkage);
	return(-1);
}
private int on_Linkage_show(struct accept_abal_production_context * _Context) {
	visual_frame(_Context->x_auto2+30,_Context->y_auto2+110,552+2,240+2,5);
;
	show_window_editor();
	return(-1);
}

public	int	accept_abal_production_show(struct accept_abal_production_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_auto2,_Context->y_auto2);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_auto2,_Context->y_auto2,620,440,vfh[2],_Context->msg_auto2[_Context->language],strlen(_Context->msg_auto2[_Context->language]),0x407);
	visual_image(_Context->x_auto2+5,_Context->y_auto2+22,610,413,_Context->msg_Auto6301[_Context->language],4);
	visual_text(_Context->x_auto2+10,_Context->y_auto2+30,590,30,vfh[3],27,0,_Context->msg_Auto6302[_Context->language],strlen(_Context->msg_Auto6302[_Context->language]),515);
	visual_frame(_Context->x_auto2+280,_Context->y_auto2+300,70,70,1);
	if (_Context->page_number == 1 ) {
	_Context->trigger_Production=visual_trigger_code(_Context->msg_Production[_Context->language],strlen(_Context->msg_Production[_Context->language]));
	visual_tabpage(_Context->x_auto2+20,_Context->y_auto2+70,580,300,vfh[2],_Context->msg_Production[_Context->language],strlen(_Context->msg_Production[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_auto2+20,_Context->y_auto2+70,580,300,vfh[2],_Context->msg_Production[_Context->language],strlen(_Context->msg_Production[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_auto2+40,_Context->y_auto2+224,540,100,2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_auto2+50,_Context->y_auto2+230,141,18,vfh[2],27,0,_Context->msg_Auto6305[_Context->language],strlen(_Context->msg_Auto6305[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_image(_Context->x_auto2+370,_Context->y_auto2+250,51,53,_Context->msg_Auto6306[_Context->language],3);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_auto2+40,_Context->y_auto2+120,540,20,vfh[2],16,0,_Context->msg_auto7[_Context->language],strlen(_Context->msg_auto7[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_auto2+40,_Context->y_auto2+140,540+2,20+2,5);
	visual_text(_Context->x_auto2+40+1,_Context->y_auto2+140+1,540,20,vfh[1],34,0,_Context->buffer_FileName,67,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_auto2+40,_Context->y_auto2+170,540,20,vfh[2],16,0,_Context->msg_auto52[_Context->language],strlen(_Context->msg_auto52[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_auto2+40,_Context->y_auto2+190,540+2,20+2,5);
	visual_text(_Context->x_auto2+40+1,_Context->y_auto2+190+1,540,20,vfh[1],34,0,_Context->buffer_Identity,67,0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_auto2+50,_Context->y_auto2+250,141,70,vfh[1],0,0,parse_selection(_Context->msg_Packaging[_Context->language],&_Context->value_Packaging),768);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_IsAutoTrad=visual_trigger_code(_Context->msg_IsAutoTrad[_Context->language],strlen(_Context->msg_IsAutoTrad[_Context->language]));
	visual_check(_Context->x_auto2+210,_Context->y_auto2+250,154,16,vfh[2],27,0,_Context->msg_IsAutoTrad[_Context->language],strlen(_Context->msg_IsAutoTrad[_Context->language]),_Context->value_IsAutoTrad|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_IsTrueColour=visual_trigger_code(_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]));
	visual_check(_Context->x_auto2+210,_Context->y_auto2+280,154,16,vfh[2],27,0,_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]),_Context->value_IsTrueColour|0);
		}
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_auto2+20,_Context->y_auto2+380,90,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_auto2+510,_Context->y_auto2+380,90,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_auto2+430,_Context->y_auto2+230,140,20,vfh[2],27,0,_Context->msg_Auto6307[_Context->language],strlen(_Context->msg_Auto6307[_Context->language]),1);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_auto2+430,_Context->y_auto2+250,140,100,vfh[1],0,0,parse_selection(_Context->msg_Dimensions[_Context->language],&_Context->value_Dimensions),0);
		}
	_Context->trigger_UseAtr=visual_trigger_code(_Context->msg_UseAtr[_Context->language],strlen(_Context->msg_UseAtr[_Context->language]));
	visual_button(_Context->x_auto2+210,_Context->y_auto2+380,90,30,vfh[2],26,0,_Context->msg_UseAtr[_Context->language],strlen(_Context->msg_UseAtr[_Context->language]),0);
	_Context->trigger_Link=visual_trigger_code(_Context->msg_Link[_Context->language],strlen(_Context->msg_Link[_Context->language]));
	visual_button(_Context->x_auto2+310,_Context->y_auto2+380,90,30,vfh[2],16,28,_Context->msg_Link[_Context->language],strlen(_Context->msg_Link[_Context->language]),0);
	if (_Context->page_number == 1 ) {
	_Context->trigger_UseEdit=visual_trigger_code(_Context->msg_UseEdit[_Context->language],strlen(_Context->msg_UseEdit[_Context->language]));
	visual_button(_Context->x_auto2+210,_Context->y_auto2+330,90,30,vfh[2],26,0,_Context->msg_UseEdit[_Context->language],strlen(_Context->msg_UseEdit[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto2+310,_Context->y_auto2+330,90,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Inclusion=visual_trigger_code(_Context->msg_Inclusion[_Context->language],strlen(_Context->msg_Inclusion[_Context->language]));
	visual_tabpage(_Context->x_auto2+20,_Context->y_auto2+70,580,300,vfh[2],_Context->msg_Inclusion[_Context->language],strlen(_Context->msg_Inclusion[_Context->language]),104,2);
		(void) on_Inclusion_show(_Context);
	} else {
		visual_tabpage(_Context->x_auto2+20,_Context->y_auto2+70,580,300,vfh[2],_Context->msg_Inclusion[_Context->language],strlen(_Context->msg_Inclusion[_Context->language]),104,0);
		}
	if (_Context->page_number == 2 ) {
	(void) on_Dependance_show(_Context);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_Modules=visual_trigger_code(_Context->msg_Modules[_Context->language],strlen(_Context->msg_Modules[_Context->language]));
	visual_tabpage(_Context->x_auto2+20,_Context->y_auto2+70,580,300,vfh[2],_Context->msg_Modules[_Context->language],strlen(_Context->msg_Modules[_Context->language]),193,2);
		(void) on_Modules_show(_Context);
	} else {
		visual_tabpage(_Context->x_auto2+20,_Context->y_auto2+70,580,300,vfh[2],_Context->msg_Modules[_Context->language],strlen(_Context->msg_Modules[_Context->language]),193,0);
		}
	if (_Context->page_number == 3 ) {
	(void) on_Linkage_show(_Context);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_PragmaPage=visual_trigger_code(_Context->msg_PragmaPage[_Context->language],strlen(_Context->msg_PragmaPage[_Context->language]));
	visual_tabpage(_Context->x_auto2+20,_Context->y_auto2+70,580,300,vfh[2],_Context->msg_PragmaPage[_Context->language],strlen(_Context->msg_PragmaPage[_Context->language]),280,2);
	} else {
		visual_tabpage(_Context->x_auto2+20,_Context->y_auto2+70,580,300,vfh[2],_Context->msg_PragmaPage[_Context->language],strlen(_Context->msg_PragmaPage[_Context->language]),280,0);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_auto2+40,_Context->y_auto2+110,260,16,vfh[2],16,0,_Context->msg_Auto6308[_Context->language],strlen(_Context->msg_Auto6308[_Context->language]),259);
	visual_frame(_Context->x_auto2+40,_Context->y_auto2+126,260,184,4);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_auto2+40,_Context->y_auto2+320,540,40,4);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_auto2+310,_Context->y_auto2+110,270,16,vfh[2],16,0,_Context->msg_Auto6309[_Context->language],strlen(_Context->msg_Auto6309[_Context->language]),259);
	visual_frame(_Context->x_auto2+310,_Context->y_auto2+126,270,184,4);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_UseDiezeMem=visual_trigger_code(_Context->msg_UseDiezeMem[_Context->language],strlen(_Context->msg_UseDiezeMem[_Context->language]));
	visual_check(_Context->x_auto2+80,_Context->y_auto2+150,98,16,vfh[2],28,28,_Context->msg_UseDiezeMem[_Context->language],strlen(_Context->msg_UseDiezeMem[_Context->language]),_Context->value_UseDiezeMem|0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_UseDiezeStack=visual_trigger_code(_Context->msg_UseDiezeStack[_Context->language],strlen(_Context->msg_UseDiezeStack[_Context->language]));
	visual_check(_Context->x_auto2+80,_Context->y_auto2+190,98,16,vfh[2],28,28,_Context->msg_UseDiezeStack[_Context->language],strlen(_Context->msg_UseDiezeStack[_Context->language]),_Context->value_UseDiezeStack|0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_UseDiezeFiles=visual_trigger_code(_Context->msg_UseDiezeFiles[_Context->language],strlen(_Context->msg_UseDiezeFiles[_Context->language]));
	visual_check(_Context->x_auto2+80,_Context->y_auto2+230,98,16,vfh[2],28,28,_Context->msg_UseDiezeFiles[_Context->language],strlen(_Context->msg_UseDiezeFiles[_Context->language]),_Context->value_UseDiezeFiles|0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_UseDiezeHeap=visual_trigger_code(_Context->msg_UseDiezeHeap[_Context->language],strlen(_Context->msg_UseDiezeHeap[_Context->language]));
	visual_check(_Context->x_auto2+80,_Context->y_auto2+270,98,16,vfh[2],28,28,_Context->msg_UseDiezeHeap[_Context->language],strlen(_Context->msg_UseDiezeHeap[_Context->language]),_Context->value_UseDiezeHeap|0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_auto2+180,_Context->y_auto2+150,80+2,16+2,5);
	visual_text(_Context->x_auto2+180+1,_Context->y_auto2+150+1,80,16,vfh[1],16,0,_Context->buffer_DiezeMem,10,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_auto2+180,_Context->y_auto2+190,80+2,16+2,5);
	visual_text(_Context->x_auto2+180+1,_Context->y_auto2+190+1,80,16,vfh[1],16,0,_Context->buffer_DiezeStack,10,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_auto2+180,_Context->y_auto2+230,80+2,16+2,5);
	visual_text(_Context->x_auto2+180+1,_Context->y_auto2+230+1,80,16,vfh[1],16,0,_Context->buffer_DiezeFiles,10,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_auto2+180,_Context->y_auto2+270,80+2,16+2,5);
	visual_text(_Context->x_auto2+180+1,_Context->y_auto2+270+1,80,16,vfh[1],16,0,_Context->buffer_DiezeHeap,10,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_UsePragmaFile=visual_trigger_code(_Context->msg_UsePragmaFile[_Context->language],strlen(_Context->msg_UsePragmaFile[_Context->language]));
	visual_check(_Context->x_auto2+50,_Context->y_auto2+330,168,16,vfh[2],27,28,_Context->msg_UsePragmaFile[_Context->language],strlen(_Context->msg_UsePragmaFile[_Context->language]),_Context->value_UsePragmaFile|0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_auto2+220,_Context->y_auto2+330,352+2,16+2,5);
	visual_text(_Context->x_auto2+220+1,_Context->y_auto2+330+1,352,16,vfh[1],27,28,_Context->buffer_PragmaFileName,44,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_RespectCase=visual_trigger_code(_Context->msg_RespectCase[_Context->language],strlen(_Context->msg_RespectCase[_Context->language]));
	visual_check(_Context->x_auto2+360,_Context->y_auto2+150,182,16,vfh[2],28,28,_Context->msg_RespectCase[_Context->language],strlen(_Context->msg_RespectCase[_Context->language]),_Context->value_RespectCase|0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_OptimiseTables=visual_trigger_code(_Context->msg_OptimiseTables[_Context->language],strlen(_Context->msg_OptimiseTables[_Context->language]));
	visual_check(_Context->x_auto2+360,_Context->y_auto2+190,182,16,vfh[2],28,28,_Context->msg_OptimiseTables[_Context->language],strlen(_Context->msg_OptimiseTables[_Context->language]),_Context->value_OptimiseTables|0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_UseTokenSize=visual_trigger_code(_Context->msg_UseTokenSize[_Context->language],strlen(_Context->msg_UseTokenSize[_Context->language]));
	visual_check(_Context->x_auto2+360,_Context->y_auto2+230,112,16,vfh[2],28,28,_Context->msg_UseTokenSize[_Context->language],strlen(_Context->msg_UseTokenSize[_Context->language]),_Context->value_UseTokenSize|0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_UseLabelSize=visual_trigger_code(_Context->msg_UseLabelSize[_Context->language],strlen(_Context->msg_UseLabelSize[_Context->language]));
	visual_check(_Context->x_auto2+360,_Context->y_auto2+270,112,16,vfh[2],28,28,_Context->msg_UseLabelSize[_Context->language],strlen(_Context->msg_UseLabelSize[_Context->language]),_Context->value_UseLabelSize|0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_auto2+480,_Context->y_auto2+230,72+2,16+2,5);
	visual_text(_Context->x_auto2+480+1,_Context->y_auto2+230+1,72,16,vfh[1],16,0,_Context->buffer_TokenSize,9,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_auto2+480,_Context->y_auto2+270,72+2,16+2,5);
	visual_text(_Context->x_auto2+480+1,_Context->y_auto2+270+1,72,16,vfh[1],16,0,_Context->buffer_LabelSize,9,0);
		}
	visual_thaw(_Context->x_auto2,_Context->y_auto2,620,440);
	visual_thaw(_Context->x_auto2,_Context->y_auto2,620,440);

	return(0);
}

private int auto2action(struct accept_abal_production_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_abal_production_hide(_Context);

		_Context->x_auto2 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_auto2 < 0) { _Context->x_auto2=0; }
		_Context->y_auto2 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_auto2 < 0) { _Context->y_auto2=0; }
			accept_abal_production_show(_Context);

		visual_thaw(_Context->x_auto2,_Context->y_auto2,620,440);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_abal_production_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_abal_production_context * _Context) {
	return(27);
	return(-1);
}
private int on_UseAtr_event(struct accept_abal_production_context * _Context) {
	translate_abal(0,_Context->buffer_FileName,0);
		accept_abal_production_show(_Context);
;
	return(-1);
}
private int on_Link_event(struct accept_abal_production_context * _Context) {
	link_abal(_Context->buffer_FileName,_Context->buffer_Linkage,_Context->value_IsAutoTrad);
		accept_abal_production_show(_Context);
;
	return(-1);
}
private int on_UseEdit_event(struct accept_abal_production_context * _Context) {
	close_window_editor();
		accept_abal_production_hide(_Context);
;
	use_editor(_Context->buffer_FileName,_GENERATE_BAL);
		accept_abal_production_show(_Context);
;
	return(-1);
}
private int on_Select_event(struct accept_abal_production_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_AS);
		accept_abal_production_show(_Context);
;
	return(-1);
}


public	int	accept_abal_production_event(
struct accept_abal_production_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Production == mb ) return(2);
		if (_Context->trigger_IsAutoTrad == mb ) return(8);
		if (_Context->trigger_IsTrueColour == mb ) return(9);
		if (_Context->trigger_Accept == mb ) return(10);
		if (_Context->trigger_Cancel == mb ) return(11);
		if (_Context->trigger_UseAtr == mb ) return(14);
		if (_Context->trigger_Link == mb ) return(15);
		if (_Context->trigger_UseEdit == mb ) return(16);
		if (_Context->trigger_Select == mb ) return(17);
		if (_Context->trigger_Inclusion == mb ) return(18);
		if (_Context->trigger_Modules == mb ) return(20);
		if (_Context->trigger_PragmaPage == mb ) return(22);
		if (_Context->trigger_UseDiezeMem == mb ) return(23);
		if (_Context->trigger_UseDiezeStack == mb ) return(24);
		if (_Context->trigger_UseDiezeFiles == mb ) return(25);
		if (_Context->trigger_UseDiezeHeap == mb ) return(26);
		if (_Context->trigger_UsePragmaFile == mb ) return(31);
		if (_Context->trigger_RespectCase == mb ) return(33);
		if (_Context->trigger_OptimiseTables == mb ) return(34);
		if (_Context->trigger_UseTokenSize == mb ) return(35);
		if (_Context->trigger_UseLabelSize == mb ) return(36);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_auto2+599) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+616) )  
	&&  (my <= (_Context->y_auto2+20) )) {
		return(1);	/* auto2 */

		}
	if ((mx >= (_Context->x_auto2+583) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+600) )  
	&&  (my <= (_Context->y_auto2+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vaprod.htm");
			};
		return(-1);	/* auto2 */

		}
	if ((mx >= (_Context->x_auto2+567) )  
	&&  (my >= (_Context->y_auto2+4) )  
	&&  (mx <= (_Context->x_auto2+584) )  
	&&  (my <= (_Context->y_auto2+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_abal_production_show(_Context);
		return(-1);	/* auto2 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_auto2+4) )  
		&&  (my >= (_Context->y_auto2+4) )  
		&&  (mx <= (_Context->x_auto2+552) )  
		&&  (my <= (_Context->y_auto2+20) )) {
			return( auto2action(_Context) );
			}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_auto2+20+0) ) 
		&&  ( my >= (_Context->y_auto2+70) ) 
		&&  ( mx <= (_Context->x_auto2+20+103) ) 
		&&  ( my <= (_Context->y_auto2+70+24))) {
			return(2); /* Production */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+40) ) 
		&&  ( my >= (_Context->y_auto2+140) ) 
		&&  ( mx <= (_Context->x_auto2+40+540) ) 
		&&  ( my <= (_Context->y_auto2+140+20))) {
			return(4); /* FileName */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+40) ) 
		&&  ( my >= (_Context->y_auto2+190) ) 
		&&  ( mx <= (_Context->x_auto2+40+540) ) 
		&&  ( my <= (_Context->y_auto2+190+20))) {
			return(6); /* Identity */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+50+0) ) 
		&&  ( my >= (_Context->y_auto2+250) ) 
		&&  ( mx <= (_Context->x_auto2+50+141) ) 
		&&  ( my <= (_Context->y_auto2+250+16))) {
			return(7); /* Packaging */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+210) ) 
		&&  ( my >= (_Context->y_auto2+250) ) 
		&&  ( mx <= (_Context->x_auto2+210+154) ) 
		&&  ( my <= (_Context->y_auto2+250+16))) {
			return(8); /* IsAutoTrad */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+210) ) 
		&&  ( my >= (_Context->y_auto2+280) ) 
		&&  ( mx <= (_Context->x_auto2+210+154) ) 
		&&  ( my <= (_Context->y_auto2+280+16))) {
			return(9); /* IsTrueColour */
			}
		}
	if (( mx >= (_Context->x_auto2+20) ) 
	&&  ( my >= (_Context->y_auto2+380) ) 
	&&  ( mx <= (_Context->x_auto2+20+90) ) 
	&&  ( my <= (_Context->y_auto2+380+30))) {
		return(10); /* Accept */
		}
	if (( mx >= (_Context->x_auto2+510) ) 
	&&  ( my >= (_Context->y_auto2+380) ) 
	&&  ( mx <= (_Context->x_auto2+510+90) ) 
	&&  ( my <= (_Context->y_auto2+380+30))) {
		return(11); /* Cancel */
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+430+0) ) 
		&&  ( my >= (_Context->y_auto2+250) ) 
		&&  ( mx <= (_Context->x_auto2+430+140) ) 
		&&  ( my <= (_Context->y_auto2+250+16))) {
			return(13); /* Dimensions */
			}
		}
	if (( mx >= (_Context->x_auto2+210) ) 
	&&  ( my >= (_Context->y_auto2+380) ) 
	&&  ( mx <= (_Context->x_auto2+210+90) ) 
	&&  ( my <= (_Context->y_auto2+380+30))) {
		return(14); /* UseAtr */
		}
	if (( mx >= (_Context->x_auto2+310) ) 
	&&  ( my >= (_Context->y_auto2+380) ) 
	&&  ( mx <= (_Context->x_auto2+310+90) ) 
	&&  ( my <= (_Context->y_auto2+380+30))) {
		return(15); /* Link */
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+210) ) 
		&&  ( my >= (_Context->y_auto2+330) ) 
		&&  ( mx <= (_Context->x_auto2+210+90) ) 
		&&  ( my <= (_Context->y_auto2+330+30))) {
			return(16); /* UseEdit */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+310) ) 
		&&  ( my >= (_Context->y_auto2+330) ) 
		&&  ( mx <= (_Context->x_auto2+310+90) ) 
		&&  ( my <= (_Context->y_auto2+330+30))) {
			return(17); /* Select */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_auto2+20+104) ) 
		&&  ( my >= (_Context->y_auto2+70) ) 
		&&  ( mx <= (_Context->x_auto2+20+192) ) 
		&&  ( my <= (_Context->y_auto2+70+24))) {
			return(18); /* Inclusion */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_auto2+30) ) 
		&&  ( my >= (_Context->y_auto2+110) ) 
		&&  ( mx <= (_Context->x_auto2+30+552) ) 
		&&  ( my <= (_Context->y_auto2+110+240))) {
			return(19); /* Dependance */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_auto2+20+193) ) 
		&&  ( my >= (_Context->y_auto2+70) ) 
		&&  ( mx <= (_Context->x_auto2+20+279) ) 
		&&  ( my <= (_Context->y_auto2+70+24))) {
			return(20); /* Modules */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_auto2+30) ) 
		&&  ( my >= (_Context->y_auto2+110) ) 
		&&  ( mx <= (_Context->x_auto2+30+552) ) 
		&&  ( my <= (_Context->y_auto2+110+240))) {
			return(21); /* Linkage */
			}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if (( mx >= (_Context->x_auto2+20+280) ) 
		&&  ( my >= (_Context->y_auto2+70) ) 
		&&  ( mx <= (_Context->x_auto2+20+370) ) 
		&&  ( my <= (_Context->y_auto2+70+24))) {
			return(22); /* PragmaPage */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+80) ) 
		&&  ( my >= (_Context->y_auto2+150) ) 
		&&  ( mx <= (_Context->x_auto2+80+98) ) 
		&&  ( my <= (_Context->y_auto2+150+16))) {
			return(23); /* UseDiezeMem */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+80) ) 
		&&  ( my >= (_Context->y_auto2+190) ) 
		&&  ( mx <= (_Context->x_auto2+80+98) ) 
		&&  ( my <= (_Context->y_auto2+190+16))) {
			return(24); /* UseDiezeStack */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+80) ) 
		&&  ( my >= (_Context->y_auto2+230) ) 
		&&  ( mx <= (_Context->x_auto2+80+98) ) 
		&&  ( my <= (_Context->y_auto2+230+16))) {
			return(25); /* UseDiezeFiles */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+80) ) 
		&&  ( my >= (_Context->y_auto2+270) ) 
		&&  ( mx <= (_Context->x_auto2+80+98) ) 
		&&  ( my <= (_Context->y_auto2+270+16))) {
			return(26); /* UseDiezeHeap */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+180) ) 
		&&  ( my >= (_Context->y_auto2+150) ) 
		&&  ( mx <= (_Context->x_auto2+180+80) ) 
		&&  ( my <= (_Context->y_auto2+150+16))) {
			return(27); /* DiezeMem */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+180) ) 
		&&  ( my >= (_Context->y_auto2+190) ) 
		&&  ( mx <= (_Context->x_auto2+180+80) ) 
		&&  ( my <= (_Context->y_auto2+190+16))) {
			return(28); /* DiezeStack */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+180) ) 
		&&  ( my >= (_Context->y_auto2+230) ) 
		&&  ( mx <= (_Context->x_auto2+180+80) ) 
		&&  ( my <= (_Context->y_auto2+230+16))) {
			return(29); /* DiezeFiles */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+180) ) 
		&&  ( my >= (_Context->y_auto2+270) ) 
		&&  ( mx <= (_Context->x_auto2+180+80) ) 
		&&  ( my <= (_Context->y_auto2+270+16))) {
			return(30); /* DiezeHeap */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+50) ) 
		&&  ( my >= (_Context->y_auto2+330) ) 
		&&  ( mx <= (_Context->x_auto2+50+168) ) 
		&&  ( my <= (_Context->y_auto2+330+16))) {
			return(31); /* UsePragmaFile */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+220) ) 
		&&  ( my >= (_Context->y_auto2+330) ) 
		&&  ( mx <= (_Context->x_auto2+220+352) ) 
		&&  ( my <= (_Context->y_auto2+330+16))) {
			return(32); /* PragmaFileName */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+360) ) 
		&&  ( my >= (_Context->y_auto2+150) ) 
		&&  ( mx <= (_Context->x_auto2+360+182) ) 
		&&  ( my <= (_Context->y_auto2+150+16))) {
			return(33); /* RespectCase */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+360) ) 
		&&  ( my >= (_Context->y_auto2+190) ) 
		&&  ( mx <= (_Context->x_auto2+360+182) ) 
		&&  ( my <= (_Context->y_auto2+190+16))) {
			return(34); /* OptimiseTables */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+360) ) 
		&&  ( my >= (_Context->y_auto2+230) ) 
		&&  ( mx <= (_Context->x_auto2+360+112) ) 
		&&  ( my <= (_Context->y_auto2+230+16))) {
			return(35); /* UseTokenSize */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+360) ) 
		&&  ( my >= (_Context->y_auto2+270) ) 
		&&  ( mx <= (_Context->x_auto2+360+112) ) 
		&&  ( my <= (_Context->y_auto2+270+16))) {
			return(36); /* UseLabelSize */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+480) ) 
		&&  ( my >= (_Context->y_auto2+230) ) 
		&&  ( mx <= (_Context->x_auto2+480+72) ) 
		&&  ( my <= (_Context->y_auto2+230+16))) {
			return(37); /* TokenSize */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+480) ) 
		&&  ( my >= (_Context->y_auto2+270) ) 
		&&  ( mx <= (_Context->x_auto2+480+72) ) 
		&&  ( my <= (_Context->y_auto2+270+16))) {
			return(38); /* LabelSize */
			}
		}

	return(-1);
}


public	int	accept_abal_production_losefocus(struct accept_abal_production_context * _Context)
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;
		case 3 : 
			break;
		case 4 : 
			break;

		}
	return(0);

}
private int on_Dependance_getfocus(struct accept_abal_production_context * _Context) {
	return(focus_window_editor());
	return(-1);
}
private int on_Linkage_getfocus(struct accept_abal_production_context * _Context) {
	return(focus_window_editor());
	return(-1);
}


public	int	accept_abal_production_focus(struct accept_abal_production_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Production */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x4 :
				/* FileName */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+40+1,_Context->y_auto2+140+1,540,20,vfh[1],_Context->buffer_FileName,67);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* Identity */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+40+1,_Context->y_auto2+190+1,540,20,vfh[1],_Context->buffer_Identity,67);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* Packaging */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_auto2+50,_Context->y_auto2+250,141,70,vfh[1],0,0,parse_selection(_Context->msg_Packaging[_Context->language],&_Context->value_Packaging),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* IsAutoTrad */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_auto2+210,_Context->y_auto2+250,154,16,vfh[2],27,0,_Context->msg_IsAutoTrad[_Context->language],strlen(_Context->msg_IsAutoTrad[_Context->language]),(_Context->value_IsAutoTrad |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+210,_Context->y_auto2+250,154,16,vfh[2],27,0,_Context->msg_IsAutoTrad[_Context->language],strlen(_Context->msg_IsAutoTrad[_Context->language]),(_Context->value_IsAutoTrad |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* IsTrueColour */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_auto2+210,_Context->y_auto2+280,154,16,vfh[2],27,0,_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]),(_Context->value_IsTrueColour |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+210,_Context->y_auto2+280,154,16,vfh[2],27,0,_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]),(_Context->value_IsTrueColour |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* Accept */
				visual_button(_Context->x_auto2+20,_Context->y_auto2+380,90,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto2+20,_Context->y_auto2+380,90,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				break;
			case	0xb :
				/* Cancel */
				visual_button(_Context->x_auto2+510,_Context->y_auto2+380,90,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto2+510,_Context->y_auto2+380,90,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
				break;
			case	0xd :
				/* Dimensions */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_auto2+430,_Context->y_auto2+250,140,100,vfh[1],0,0,parse_selection(_Context->msg_Dimensions[_Context->language],&_Context->value_Dimensions),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* UseAtr */
				visual_button(_Context->x_auto2+210,_Context->y_auto2+380,90,30,vfh[2],26,0,_Context->msg_UseAtr[_Context->language],strlen(_Context->msg_UseAtr[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto2+210,_Context->y_auto2+380,90,30,vfh[2],26,0,_Context->msg_UseAtr[_Context->language],strlen(_Context->msg_UseAtr[_Context->language]),0);
				break;
			case	0xf :
				/* Link */
				visual_button(_Context->x_auto2+310,_Context->y_auto2+380,90,30,vfh[2],16,28,_Context->msg_Link[_Context->language],strlen(_Context->msg_Link[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_auto2+310,_Context->y_auto2+380,90,30,vfh[2],16,28,_Context->msg_Link[_Context->language],strlen(_Context->msg_Link[_Context->language]),0);
				break;
			case	0x10 :
				/* UseEdit */
				if (_Context->page_number == 1 ) {
					visual_button(_Context->x_auto2+210,_Context->y_auto2+330,90,30,vfh[2],26,0,_Context->msg_UseEdit[_Context->language],strlen(_Context->msg_UseEdit[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_auto2+210,_Context->y_auto2+330,90,30,vfh[2],26,0,_Context->msg_UseEdit[_Context->language],strlen(_Context->msg_UseEdit[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* Select */
				if (_Context->page_number == 1 ) {
					visual_button(_Context->x_auto2+310,_Context->y_auto2+330,90,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_auto2+310,_Context->y_auto2+330,90,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* Inclusion */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x13 :
				/* Dependance */
				if (_Context->page_number == 2 ) {
					if ((_Context->keycode = on_Dependance_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* Modules */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x15 :
				/* Linkage */
				if (_Context->page_number == 3 ) {
					if ((_Context->keycode = on_Linkage_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* PragmaPage */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x17 :
				/* UseDiezeMem */
				if (_Context->page_number == 4 ) {
				visual_check(_Context->x_auto2+80,_Context->y_auto2+150,98,16,vfh[2],28,28,_Context->msg_UseDiezeMem[_Context->language],strlen(_Context->msg_UseDiezeMem[_Context->language]),(_Context->value_UseDiezeMem |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+80,_Context->y_auto2+150,98,16,vfh[2],28,28,_Context->msg_UseDiezeMem[_Context->language],strlen(_Context->msg_UseDiezeMem[_Context->language]),(_Context->value_UseDiezeMem |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x18 :
				/* UseDiezeStack */
				if (_Context->page_number == 4 ) {
				visual_check(_Context->x_auto2+80,_Context->y_auto2+190,98,16,vfh[2],28,28,_Context->msg_UseDiezeStack[_Context->language],strlen(_Context->msg_UseDiezeStack[_Context->language]),(_Context->value_UseDiezeStack |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+80,_Context->y_auto2+190,98,16,vfh[2],28,28,_Context->msg_UseDiezeStack[_Context->language],strlen(_Context->msg_UseDiezeStack[_Context->language]),(_Context->value_UseDiezeStack |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* UseDiezeFiles */
				if (_Context->page_number == 4 ) {
				visual_check(_Context->x_auto2+80,_Context->y_auto2+230,98,16,vfh[2],28,28,_Context->msg_UseDiezeFiles[_Context->language],strlen(_Context->msg_UseDiezeFiles[_Context->language]),(_Context->value_UseDiezeFiles |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+80,_Context->y_auto2+230,98,16,vfh[2],28,28,_Context->msg_UseDiezeFiles[_Context->language],strlen(_Context->msg_UseDiezeFiles[_Context->language]),(_Context->value_UseDiezeFiles |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* UseDiezeHeap */
				if (_Context->page_number == 4 ) {
				visual_check(_Context->x_auto2+80,_Context->y_auto2+270,98,16,vfh[2],28,28,_Context->msg_UseDiezeHeap[_Context->language],strlen(_Context->msg_UseDiezeHeap[_Context->language]),(_Context->value_UseDiezeHeap |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+80,_Context->y_auto2+270,98,16,vfh[2],28,28,_Context->msg_UseDiezeHeap[_Context->language],strlen(_Context->msg_UseDiezeHeap[_Context->language]),(_Context->value_UseDiezeHeap |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* DiezeMem */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+180+1,_Context->y_auto2+150+1,80,16,vfh[1],_Context->buffer_DiezeMem,10);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1c :
				/* DiezeStack */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+180+1,_Context->y_auto2+190+1,80,16,vfh[1],_Context->buffer_DiezeStack,10);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1d :
				/* DiezeFiles */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+180+1,_Context->y_auto2+230+1,80,16,vfh[1],_Context->buffer_DiezeFiles,10);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* DiezeHeap */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+180+1,_Context->y_auto2+270+1,80,16,vfh[1],_Context->buffer_DiezeHeap,10);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1f :
				/* UsePragmaFile */
				if (_Context->page_number == 4 ) {
				visual_check(_Context->x_auto2+50,_Context->y_auto2+330,168,16,vfh[2],27,28,_Context->msg_UsePragmaFile[_Context->language],strlen(_Context->msg_UsePragmaFile[_Context->language]),(_Context->value_UsePragmaFile |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+50,_Context->y_auto2+330,168,16,vfh[2],27,28,_Context->msg_UsePragmaFile[_Context->language],strlen(_Context->msg_UsePragmaFile[_Context->language]),(_Context->value_UsePragmaFile |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x20 :
				/* PragmaFileName */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+220+1,_Context->y_auto2+330+1,352,16,vfh[1],_Context->buffer_PragmaFileName,44);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x21 :
				/* RespectCase */
				if (_Context->page_number == 4 ) {
				visual_check(_Context->x_auto2+360,_Context->y_auto2+150,182,16,vfh[2],28,28,_Context->msg_RespectCase[_Context->language],strlen(_Context->msg_RespectCase[_Context->language]),(_Context->value_RespectCase |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+360,_Context->y_auto2+150,182,16,vfh[2],28,28,_Context->msg_RespectCase[_Context->language],strlen(_Context->msg_RespectCase[_Context->language]),(_Context->value_RespectCase |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x22 :
				/* OptimiseTables */
				if (_Context->page_number == 4 ) {
				visual_check(_Context->x_auto2+360,_Context->y_auto2+190,182,16,vfh[2],28,28,_Context->msg_OptimiseTables[_Context->language],strlen(_Context->msg_OptimiseTables[_Context->language]),(_Context->value_OptimiseTables |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+360,_Context->y_auto2+190,182,16,vfh[2],28,28,_Context->msg_OptimiseTables[_Context->language],strlen(_Context->msg_OptimiseTables[_Context->language]),(_Context->value_OptimiseTables |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x23 :
				/* UseTokenSize */
				if (_Context->page_number == 4 ) {
				visual_check(_Context->x_auto2+360,_Context->y_auto2+230,112,16,vfh[2],28,28,_Context->msg_UseTokenSize[_Context->language],strlen(_Context->msg_UseTokenSize[_Context->language]),(_Context->value_UseTokenSize |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+360,_Context->y_auto2+230,112,16,vfh[2],28,28,_Context->msg_UseTokenSize[_Context->language],strlen(_Context->msg_UseTokenSize[_Context->language]),(_Context->value_UseTokenSize |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x24 :
				/* UseLabelSize */
				if (_Context->page_number == 4 ) {
				visual_check(_Context->x_auto2+360,_Context->y_auto2+270,112,16,vfh[2],28,28,_Context->msg_UseLabelSize[_Context->language],strlen(_Context->msg_UseLabelSize[_Context->language]),(_Context->value_UseLabelSize |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_auto2+360,_Context->y_auto2+270,112,16,vfh[2],28,28,_Context->msg_UseLabelSize[_Context->language],strlen(_Context->msg_UseLabelSize[_Context->language]),(_Context->value_UseLabelSize |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x25 :
				/* TokenSize */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+480+1,_Context->y_auto2+230+1,72,16,vfh[1],_Context->buffer_TokenSize,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x26 :
				/* LabelSize */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+480+1,_Context->y_auto2+270+1,72,16,vfh[1],_Context->buffer_LabelSize,9);
				} else {
					_Context->keycode = 5;
					}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			accept_abal_production_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_abal_production_show(_Context);
			continue;
		case	0x2 :
			accept_abal_production_losefocus(_Context);
			_Context->page_number=4;
			_Context->focus_item=38;
			accept_abal_production_show(_Context);
			continue;
		case	0x3 :
			accept_abal_production_losefocus(_Context);
			if ( _Context->page_number < 4 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_abal_production_show(_Context);
			continue;
		case	0x12 :
			accept_abal_production_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_abal_production_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_abal_production_event(_Context)) == -1)
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
					case	0x2 :
						/* Production */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_abal_production_losefocus(_Context);
							_Context->page_number = 1;
							accept_abal_production_show(_Context);
							}
						continue;
					case	0x4 :
						/* FileName */
						continue;
					case	0x6 :
						/* Identity */
						continue;
					case	0x7 :
						/* Packaging */
						continue;
					case	0x8 :
						/* IsAutoTrad */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsAutoTrad += 1;
							_Context->value_IsAutoTrad &= 1;
							}
						continue;
					case	0x9 :
						/* IsTrueColour */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_IsTrueColour += 1;
							_Context->value_IsTrueColour &= 1;
							}
						continue;
					case	0xa :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto2+20,_Context->y_auto2+380,90,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto2+20,_Context->y_auto2+380,90,30,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0xb :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto2+510,_Context->y_auto2+380,90,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto2+510,_Context->y_auto2+380,90,30,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

							}
						continue;
					case	0xd :
						/* Dimensions */
						continue;
					case	0xe :
						/* UseAtr */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto2+210,_Context->y_auto2+380,90,30,vfh[2],26,0,_Context->msg_UseAtr[_Context->language],strlen(_Context->msg_UseAtr[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto2+210,_Context->y_auto2+380,90,30,vfh[2],26,0,_Context->msg_UseAtr[_Context->language],strlen(_Context->msg_UseAtr[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_UseAtr_event(_Context)) != -1) break;

							}
						continue;
					case	0xf :
						/* Link */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto2+310,_Context->y_auto2+380,90,30,vfh[2],16,28,_Context->msg_Link[_Context->language],strlen(_Context->msg_Link[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto2+310,_Context->y_auto2+380,90,30,vfh[2],16,28,_Context->msg_Link[_Context->language],strlen(_Context->msg_Link[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Link_event(_Context)) != -1) break;

							}
						continue;
					case	0x10 :
						/* UseEdit */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto2+210,_Context->y_auto2+330,90,30,vfh[2],26,0,_Context->msg_UseEdit[_Context->language],strlen(_Context->msg_UseEdit[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto2+210,_Context->y_auto2+330,90,30,vfh[2],26,0,_Context->msg_UseEdit[_Context->language],strlen(_Context->msg_UseEdit[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_UseEdit_event(_Context)) != -1) break;

							}
						continue;
					case	0x11 :
						/* Select */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_auto2+310,_Context->y_auto2+330,90,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_auto2+310,_Context->y_auto2+330,90,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Select_event(_Context)) != -1) break;

							}
						continue;
					case	0x12 :
						/* Inclusion */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_abal_production_losefocus(_Context);
							_Context->page_number = 2;
							accept_abal_production_show(_Context);
							}
						continue;
					case	0x13 :
						/* Dependance */
						continue;
					case	0x14 :
						/* Modules */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_abal_production_losefocus(_Context);
							_Context->page_number = 3;
							accept_abal_production_show(_Context);
							}
						continue;
					case	0x15 :
						/* Linkage */
						continue;
					case	0x16 :
						/* PragmaPage */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_abal_production_losefocus(_Context);
							_Context->page_number = 4;
							accept_abal_production_show(_Context);
							}
						continue;
					case	0x17 :
						/* UseDiezeMem */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_UseDiezeMem += 1;
							_Context->value_UseDiezeMem &= 1;
							}
						continue;
					case	0x18 :
						/* UseDiezeStack */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_UseDiezeStack += 1;
							_Context->value_UseDiezeStack &= 1;
							}
						continue;
					case	0x19 :
						/* UseDiezeFiles */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_UseDiezeFiles += 1;
							_Context->value_UseDiezeFiles &= 1;
							}
						continue;
					case	0x1a :
						/* UseDiezeHeap */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_UseDiezeHeap += 1;
							_Context->value_UseDiezeHeap &= 1;
							}
						continue;
					case	0x1b :
						/* DiezeMem */
						continue;
					case	0x1c :
						/* DiezeStack */
						continue;
					case	0x1d :
						/* DiezeFiles */
						continue;
					case	0x1e :
						/* DiezeHeap */
						continue;
					case	0x1f :
						/* UsePragmaFile */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_UsePragmaFile += 1;
							_Context->value_UsePragmaFile &= 1;
							}
						continue;
					case	0x20 :
						/* PragmaFileName */
						continue;
					case	0x21 :
						/* RespectCase */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_RespectCase += 1;
							_Context->value_RespectCase &= 1;
							}
						continue;
					case	0x22 :
						/* OptimiseTables */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_OptimiseTables += 1;
							_Context->value_OptimiseTables &= 1;
							}
						continue;
					case	0x23 :
						/* UseTokenSize */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_UseTokenSize += 1;
							_Context->value_UseTokenSize &= 1;
							}
						continue;
					case	0x24 :
						/* UseLabelSize */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_UseLabelSize += 1;
							_Context->value_UseLabelSize &= 1;
							}
						continue;
					case	0x25 :
						/* TokenSize */
						continue;
					case	0x26 :
						/* LabelSize */
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
				_Context->focus_item=38;
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

public	int	accept_abal_production(
	char * pFileName,
	char * pIdentity,
	char * pPackaging,
	char * pIsAutoTrad,
	char * pIsTrueColour,
	char * pDimensions,
	char * pDependance,
	char * pLinkage,
	char * pUseDiezeMem,
	char * pUseDiezeStack,
	char * pUseDiezeFiles,
	char * pUseDiezeHeap,
	char * pDiezeMem,
	char * pDiezeStack,
	char * pDiezeFiles,
	char * pDiezeHeap,
	char * pUsePragmaFile,
	char * pPragmaFileName,
	char * pRespectCase,
	char * pOptimiseTables,
	char * pUseTokenSize,
	char * pUseLabelSize,
	char * pTokenSize,
	char * pLabelSize)
{
	int	status=0;
	struct accept_abal_production_context * _Context=(struct accept_abal_production_context*) 0;
	status = accept_abal_production_create(
	&_Context,
	 pFileName,
	 pIdentity,
	 pPackaging,
	 pIsAutoTrad,
	 pIsTrueColour,
	 pDimensions,
	 pDependance,
	 pLinkage,
	 pUseDiezeMem,
	 pUseDiezeStack,
	 pUseDiezeFiles,
	 pUseDiezeHeap,
	 pDiezeMem,
	 pDiezeStack,
	 pDiezeFiles,
	 pDiezeHeap,
	 pUsePragmaFile,
	 pPragmaFileName,
	 pRespectCase,
	 pOptimiseTables,
	 pUseTokenSize,
	 pUseLabelSize,
	 pTokenSize,
	 pLabelSize);
	if ( status != 0) return(status);
	status = accept_abal_production_show(_Context);
		enter_modal();
	status = accept_abal_production_focus(_Context);
		leave_modal();
	status = accept_abal_production_hide(_Context);
	status = accept_abal_production_remove(
	_Context,
	 pFileName,
	 pIdentity,
	 pPackaging,
	 pIsAutoTrad,
	 pIsTrueColour,
	 pDimensions,
	 pDependance,
	 pLinkage,
	 pUseDiezeMem,
	 pUseDiezeStack,
	 pUseDiezeFiles,
	 pUseDiezeHeap,
	 pDiezeMem,
	 pDiezeStack,
	 pDiezeFiles,
	 pDiezeHeap,
	 pUsePragmaFile,
	 pPragmaFileName,
	 pRespectCase,
	 pOptimiseTables,
	 pUseTokenSize,
	 pUseLabelSize,
	 pTokenSize,
	 pLabelSize);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vaprod_c */
