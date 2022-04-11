
#ifndef _vaprod_c
#define _vaprod_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.27                                                */
/* Production     : C                                                        */
/* Project        : vaprod.xml                                               */
/* Target         : vaprod.c                                                 */
/* Identification : 0.0-1179685146-16854.16853                               */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#include "singlang.h"
#define en__auto2   ""
#define fr__auto2   ""
#define it__auto2   ""
#define es__auto2   ""
#define de__auto2   ""
#define nl__auto2   ""
#define pt__auto2   ""
#define xx__auto2   ""
#define en_Auto2628   "ABAL and ABAL++ Source Production"
#define fr_Auto2628   "Production de Source ABAL et ABAL++"
#define it_Auto2628   "ABAL and ABAL++ Source Production"
#define es_Auto2628   "ABAL and ABAL++ Source Production"
#define de_Auto2628   "ABAL and ABAL++ Source Produktion"
#define nl_Auto2628   "ABAL and ABAL++ Source Production"
#define pt_Auto2628   "ABAL and ABAL++ Source Production"
#define xx_Auto2628   "ABAL and ABAL++ Source Production"
#define en_Production   "&Production"
#define fr_Production   "&Production"
#define it_Production   "&Production"
#define es_Production   "&Produccion"
#define de_Production   "&Produktion"
#define nl_Production   "&Production"
#define pt_Production   "&Production"
#define xx_Production   "&Production"
#define en_Auto2631   "Nature"
#define fr_Auto2631   "Nature"
#define it_Auto2631   "Nature"
#define es_Auto2631   "Nature"
#define de_Auto2631   "Nature"
#define nl_Auto2631   "Nature"
#define pt_Auto2631   "Nature"
#define xx_Auto2631   "Nature"
#define en_Auto2632   "abalicon.gif"
#define fr_Auto2632   "abalicon.gif"
#define it_Auto2632   "abalicon.gif"
#define es_Auto2632   "abalicon.gif"
#define de_Auto2632   "abalicon.gif"
#define nl_Auto2632   "abalicon.gif"
#define pt_Auto2632   "abalicon.gif"
#define xx_Auto2632   "abalicon.gif"
#define en_auto7   "Abal++ Production Filename"
#define fr_auto7   "Nom du fichier de production Abal++"
#define it_auto7   "Abal++ Production Filename"
#define es_auto7   "Abal++ Production Filename"
#define de_auto7   "Abal++ Production Filename"
#define nl_auto7   "Abal++ Production Filename"
#define pt_auto7   "Abal++ Production Filename"
#define xx_auto7   "Abal++ Production Filename"
#define en__auto7   ""
#define fr__auto7   ""
#define it__auto7   ""
#define es__auto7   ""
#define de__auto7   ""
#define nl__auto7   ""
#define pt__auto7   ""
#define xx__auto7   ""
#define en_FileName   ""
#define en__FileName   ""
#define en_choixFileName   ".."
#define fr_choixFileName   ".."
#define it_choixFileName   ".."
#define es_choixFileName   ".."
#define de_choixFileName   ".."
#define nl_choixFileName   ".."
#define pt_choixFileName   ".."
#define xx_choixFileName   ".."
#define en__choixFileName   ""
#define en_auto52   "Program/Module Identifier"
#define fr_auto52   "Identificateur de Programme/Module"
#define it_auto52   "Program/Module Identifier"
#define es_auto52   "Program/Module Identifier"
#define de_auto52   "Program/Module Identifier"
#define nl_auto52   "Program/Module Identifier"
#define pt_auto52   "Program/Module Identifier"
#define xx_auto52   "Program/Module Identifier"
#define en_Identity   ""
#define en_Packaging   "Program|Overlay|Module|Include"
#define fr_Packaging   "Programme|Overlay|Module|Include"
#define it_Packaging   "Program|Overlay|Module|Include"
#define es_Packaging   "Program|Overlay|Module|Include"
#define de_Packaging   "Program|Overlay|Module|Include"
#define nl_Packaging   "Program|Overlay|Module|Include"
#define pt_Packaging   "Program|Overlay|Module|Include"
#define xx_Packaging   "Program|Overlay|Module|Include"
#define en__Packaging   ""
#define en_IsAutoTrad   "A&uto Translation"
#define fr_IsAutoTrad   "A&uto-Traduction"
#define it_IsAutoTrad   "A&uto Translation"
#define es_IsAutoTrad   "A&uto Translation"
#define de_IsAutoTrad   "A&uto Translation"
#define nl_IsAutoTrad   "A&uto Translation"
#define pt_IsAutoTrad   "A&uto Translation"
#define xx_IsAutoTrad   "A&uto Translation"
#define en_IsTrueColour   "True Colour RGB"
#define fr_IsTrueColour   "TrueColor RVB"
#define it_IsTrueColour   "True Colour RGB"
#define es_IsTrueColour   "True Colour RGB"
#define de_IsTrueColour   "True Colour RGB"
#define nl_IsTrueColour   "True Colour RGB"
#define pt_IsTrueColour   "True Colour RGB"
#define xx_IsTrueColour   "True Colour RGB"
#define en__IsTrueColour   ""
#define en_ExactDimensions   "Exact Dimensions"
#define fr_ExactDimensions   "Dimensions exactes"
#define it_ExactDimensions   "Exact Dimensions"
#define es_ExactDimensions   "Exact Dimensions"
#define de_ExactDimensions   "Exact Dimensions"
#define nl_ExactDimensions   "Exact Dimensions"
#define pt_ExactDimensions   "Exact Dimensions"
#define xx_ExactDimensions   "Exact Dimensions"
#define en__ExactDimensions   ""
#define fr__ExactDimensions   ""
#define it__ExactDimensions   ""
#define es__ExactDimensions   ""
#define de__ExactDimensions   ""
#define nl__ExactDimensions   ""
#define pt__ExactDimensions   ""
#define xx__ExactDimensions   ""
#define en_Auto2633   "ok.gif"
#define fr_Auto2633   "ok.gif"
#define it_Auto2633   "ok.gif"
#define es_Auto2633   "ok.gif"
#define de_Auto2633   "ok.gif"
#define nl_Auto2633   "ok.gif"
#define pt_Auto2633   "ok.gif"
#define xx_Auto2633   "ok.gif"
#define en_Auto2634   "cancel.gif"
#define fr_Auto2634   "cancel.gif"
#define it_Auto2634   "cancel.gif"
#define es_Auto2634   "cancel.gif"
#define de_Auto2634   "cancel.gif"
#define nl_Auto2634   "cancel.gif"
#define pt_Auto2634   "cancel.gif"
#define xx_Auto2634   "cancel.gif"
#define en_Auto2635   "Dimensions"
#define fr_Auto2635   "Dimensions"
#define it_Auto2635   "Dimensions"
#define es_Auto2635   "Dimensions"
#define de_Auto2635   "Dimensions"
#define nl_Auto2635   "Dimensions"
#define pt_Auto2635   "Dimensions"
#define xx_Auto2635   "Dimensions"
#define en_Dimensions   "320x200|640x400|640x480|800x600|1024x786|1280x1024"
#define fr_Dimensions   "320x200|640x400|640x480|800x600|1024x786|1280x1024"
#define it_Dimensions   "320x200|640x400|640x480|800x600|1024x786|1280x1024"
#define es_Dimensions   "320x200|640x400|640x480|800x600|1024x786|1280x1024"
#define de_Dimensions   "320x200|640x400|640x480|800x600|1024x786|1280x1024"
#define nl_Dimensions   "320x200|640x400|640x480|800x600|1024x786|1280x1024"
#define pt_Dimensions   "320x200|640x400|640x480|800x600|1024x786|1280x1024"
#define xx_Dimensions   "320x200|640x400|640x480|800x600|1024x786|1280x1024"
#define en__Dimensions   ""
#define en_UseAtr   "&Translate"
#define fr_UseAtr   "&Traduire"
#define it_UseAtr   "&Translate"
#define es_UseAtr   "&Translate"
#define de_UseAtr   "&Translate"
#define nl_UseAtr   "&Translate"
#define pt_UseAtr   "&Translate"
#define xx_UseAtr   "&Translate"
#define en_Link   "&Link"
#define fr_Link   "&Lien"
#define it_Link   "&Link"
#define es_Link   "&Link"
#define de_Link   "&Link"
#define nl_Link   "&Link"
#define pt_Link   "&Link"
#define xx_Link   "&Link"
#define en__Link   ""
#define en_UseEdit   "&Edit"
#define fr_UseEdit   "&Edition"
#define it_UseEdit   "&Edit"
#define es_UseEdit   "&Edit"
#define de_UseEdit   "&Edit"
#define nl_UseEdit   "&Edit"
#define pt_UseEdit   "&Edit"
#define xx_UseEdit   "&Edit"
#define en_Select   "&Select"
#define fr_Select   "&S‚lection"
#define it_Select   "&Select"
#define es_Select   "&Select"
#define de_Select   "&Select"
#define nl_Select   "&Select"
#define pt_Select   "&Select"
#define xx_Select   "&Select"
#define en_Inclusion   "&Inclusion"
#define fr_Inclusion   "&Inclusion"
#define it_Inclusion   "&Inclusion"
#define es_Inclusion   "&Inclusion"
#define de_Inclusion   "&Inclusion"
#define nl_Inclusion   "&Inclusion"
#define pt_Inclusion   "&Inclusion"
#define xx_Inclusion   "&Inclusion"
#define en__Inclusion   ""
#define en_Dependance   ""
#define en_Modules   "&Modules"
#define fr_Modules   "&Modules"
#define it_Modules   "&Modules"
#define es_Modules   "&Modules"
#define de_Modules   "&Modules"
#define nl_Modules   "&Modules"
#define pt_Modules   "&Modules"
#define xx_Modules   "&Modules"
#define en__Modules   ""
#define en_Linkage   ""
#define en_PragmaPage   "P&ragmas"
#define fr_PragmaPage   "P&ragmas"
#define it_PragmaPage   "P&ragmas"
#define es_PragmaPage   "P&ragmas"
#define de_PragmaPage   "P&ragmas"
#define nl_PragmaPage   "P&ragmas"
#define pt_PragmaPage   "P&ragmas"
#define xx_PragmaPage   "P&ragmas"
#define en_Auto2636   "Tcode Constants"
#define fr_Auto2636   "Constantes Tcode"
#define it_Auto2636   "Tcode Constants"
#define es_Auto2636   "Tcode Constants"
#define de_Auto2636   "Tcode Constants"
#define nl_Auto2636   "Tcode Constants"
#define pt_Auto2636   "Tcode Constants"
#define xx_Auto2636   "Tcode Constants"
#define en_Auto2638   "Tcode Pragmas"
#define fr_Auto2638   "Pragmas Tcode"
#define it_Auto2638   "Tcode Pragmas"
#define es_Auto2638   "Tcode Pragmas"
#define de_Auto2638   "Tcode Pragmas"
#define nl_Auto2638   "Tcode Pragmas"
#define pt_Auto2638   "Tcode Pragmas"
#define xx_Auto2638   "Tcode Pragmas"
#define en_UseDiezeMem   "#mem"
#define fr_UseDiezeMem   "#mem"
#define it_UseDiezeMem   "#mem"
#define es_UseDiezeMem   "#mem"
#define de_UseDiezeMem   "#mem"
#define nl_UseDiezeMem   "#mem"
#define pt_UseDiezeMem   "#mem"
#define xx_UseDiezeMem   "#mem"
#define en_UseDiezeStack   "#stack"
#define fr_UseDiezeStack   "#stack"
#define it_UseDiezeStack   "#stack"
#define es_UseDiezeStack   "#stack"
#define de_UseDiezeStack   "#stack"
#define nl_UseDiezeStack   "#stack"
#define pt_UseDiezeStack   "#stack"
#define xx_UseDiezeStack   "#stack"
#define en_UseDiezeFiles   "#files"
#define fr_UseDiezeFiles   "#files"
#define it_UseDiezeFiles   "#files"
#define es_UseDiezeFiles   "#files"
#define de_UseDiezeFiles   "#files"
#define nl_UseDiezeFiles   "#files"
#define pt_UseDiezeFiles   "#files"
#define xx_UseDiezeFiles   "#files"
#define en_UseDiezeHeap   "#heap"
#define fr_UseDiezeHeap   "#heap"
#define it_UseDiezeHeap   "#heap"
#define es_UseDiezeHeap   "#heap"
#define de_UseDiezeHeap   "#heap"
#define nl_UseDiezeHeap   "#heap"
#define pt_UseDiezeHeap   "#heap"
#define xx_UseDiezeHeap   "#heap"
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
#define en__PragmaFileName   ""
#define en_choixPragmaFileName   ".."
#define fr_choixPragmaFileName   ".."
#define it_choixPragmaFileName   ".."
#define es_choixPragmaFileName   ".."
#define de_choixPragmaFileName   ".."
#define nl_choixPragmaFileName   ".."
#define pt_choixPragmaFileName   ".."
#define xx_choixPragmaFileName   ".."
#define en__choixPragmaFileName   ""
#define en_RespectCase   "Respect Case"
#define fr_RespectCase   "Respecter la casse"
#define it_RespectCase   "Respect Case"
#define es_RespectCase   "Respect Case"
#define de_RespectCase   "Respect Case"
#define nl_RespectCase   "Respect Case"
#define pt_RespectCase   "Respect Case"
#define xx_RespectCase   "Respect Case"
#define en__RespectCase   ""
#define fr__RespectCase   ""
#define it__RespectCase   ""
#define es__RespectCase   ""
#define de__RespectCase   ""
#define nl__RespectCase   ""
#define pt__RespectCase   ""
#define xx__RespectCase   ""
#define en_OptimiseTables   "Optimise Tables"
#define fr_OptimiseTables   "Optimiser les tables"
#define it_OptimiseTables   "Optimise Tables"
#define es_OptimiseTables   "Optimise Tables"
#define de_OptimiseTables   "Optimise Tables"
#define nl_OptimiseTables   "Optimise Tables"
#define pt_OptimiseTables   "Optimise Tables"
#define xx_OptimiseTables   "Optimise Tables"
#define en__OptimiseTables   ""
#define fr__OptimiseTables   ""
#define it__OptimiseTables   ""
#define es__OptimiseTables   ""
#define de__OptimiseTables   ""
#define nl__OptimiseTables   ""
#define pt__OptimiseTables   ""
#define xx__OptimiseTables   ""
#define en_UseTokenSize   "TokenSize"
#define fr_UseTokenSize   "TokenSize"
#define it_UseTokenSize   "TokenSize"
#define es_UseTokenSize   "TokenSize"
#define de_UseTokenSize   "TokenSize"
#define nl_UseTokenSize   "TokenSize"
#define pt_UseTokenSize   "TokenSize"
#define xx_UseTokenSize   "TokenSize"
#define en_UseLabelSize   "LabelSize"
#define fr_UseLabelSize   "LabelSize"
#define it_UseLabelSize   "LabelSize"
#define es_UseLabelSize   "LabelSize"
#define de_UseLabelSize   "LabelSize"
#define nl_UseLabelSize   "LabelSize"
#define pt_UseLabelSize   "LabelSize"
#define xx_UseLabelSize   "LabelSize"
#define en_TokenSize   ""
#define fr_TokenSize   ""
#define en_LabelSize   ""
#define fr_LabelSize   ""

private struct accept_abal_production_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[4+1];
	char * msg_auto2[8];
	char * hint_auto2[8];
	int	x_auto2;
	int	y_auto2;
	int	w_auto2;
	int	h_auto2;
	char * msg_Auto2628[8];
	char * hint_Auto2628[8];
	char * hint_Auto2629[8];
	char * msg_Production[8];
	int	trigger_Production;
	char * hint_Production[8];
	int	page_number;
	char * hint_Auto2630[8];
	char * msg_Auto2631[8];
	char * hint_Auto2631[8];
	char * msg_Auto2632[8];
	char * hint_Auto2632[8];
	char * msg_auto7[8];
	char * hint_auto7[8];
	char * hint_FileName[8];
	char	buffer_FileName[256];
	char * msg_choixFileName[8];
	int	trigger_choixFileName;
	char * hint_choixFileName[8];
	char * msg_FilePath[8];
	char * hint_FilePath[8];
	int	value_FilePath;
	char * msg_auto52[8];
	char * hint_auto52[8];
	char * hint_Identity[8];
	char	buffer_Identity[256];
	char * msg_Packaging[8];
	char * hint_Packaging[8];
	int	value_Packaging;
	char * msg_IsAutoTrad[8];
	int	trigger_IsAutoTrad;
	char * hint_IsAutoTrad[8];
	int	value_IsAutoTrad;
	char * msg_IsTrueColour[8];
	int	trigger_IsTrueColour;
	char * hint_IsTrueColour[8];
	int	value_IsTrueColour;
	char * msg_ExactDimensions[8];
	int	trigger_ExactDimensions;
	char * hint_ExactDimensions[8];
	int	value_ExactDimensions;
	char * msg_Auto2633[8];
	int	trigger_Auto2633;
	char * hint_Auto2633[8];
	char * msg_Auto2634[8];
	int	trigger_Auto2634;
	char * hint_Auto2634[8];
	char * msg_Auto2635[8];
	char * hint_Auto2635[8];
	char * msg_Dimensions[8];
	char * hint_Dimensions[8];
	int	value_Dimensions;
	char * msg_UseAtr[8];
	int	trigger_UseAtr;
	char * hint_UseAtr[8];
	char * msg_Link[8];
	int	trigger_Link;
	char * hint_Link[8];
	char * msg_UseEdit[8];
	int	trigger_UseEdit;
	char * hint_UseEdit[8];
	char * msg_Select[8];
	int	trigger_Select;
	char * hint_Select[8];
	char * msg_Inclusion[8];
	int	trigger_Inclusion;
	char * hint_Inclusion[8];
	char * hint_Dependance[8];
	char * buffer_Dependance;
	char * msg_Modules[8];
	int	trigger_Modules;
	char * hint_Modules[8];
	char * hint_Linkage[8];
	char * buffer_Linkage;
	char * msg_PragmaPage[8];
	int	trigger_PragmaPage;
	char * hint_PragmaPage[8];
	char * msg_Auto2636[8];
	char * hint_Auto2636[8];
	char * hint_Auto2637[8];
	char * msg_Auto2638[8];
	char * hint_Auto2638[8];
	char * msg_UseDiezeMem[8];
	int	trigger_UseDiezeMem;
	char * hint_UseDiezeMem[8];
	int	value_UseDiezeMem;
	char * msg_UseDiezeStack[8];
	int	trigger_UseDiezeStack;
	char * hint_UseDiezeStack[8];
	int	value_UseDiezeStack;
	char * msg_UseDiezeFiles[8];
	int	trigger_UseDiezeFiles;
	char * hint_UseDiezeFiles[8];
	int	value_UseDiezeFiles;
	char * msg_UseDiezeHeap[8];
	int	trigger_UseDiezeHeap;
	char * hint_UseDiezeHeap[8];
	int	value_UseDiezeHeap;
	char * hint_DiezeMem[8];
	char	buffer_DiezeMem[11];
	char * hint_DiezeStack[8];
	char	buffer_DiezeStack[11];
	char * hint_DiezeFiles[8];
	char	buffer_DiezeFiles[11];
	char * hint_DiezeHeap[8];
	char	buffer_DiezeHeap[11];
	char * msg_UsePragmaFile[8];
	int	trigger_UsePragmaFile;
	char * hint_UsePragmaFile[8];
	int	value_UsePragmaFile;
	char * hint_PragmaFileName[8];
	char	buffer_PragmaFileName[256];
	char * msg_choixPragmaFileName[8];
	int	trigger_choixPragmaFileName;
	char * hint_choixPragmaFileName[8];
	char * msg_RespectCase[8];
	int	trigger_RespectCase;
	char * hint_RespectCase[8];
	int	value_RespectCase;
	char * msg_OptimiseTables[8];
	int	trigger_OptimiseTables;
	char * hint_OptimiseTables[8];
	int	value_OptimiseTables;
	char * msg_UseTokenSize[8];
	int	trigger_UseTokenSize;
	char * hint_UseTokenSize[8];
	int	value_UseTokenSize;
	char * msg_UseLabelSize[8];
	int	trigger_UseLabelSize;
	char * hint_UseLabelSize[8];
	int	value_UseLabelSize;
	char * hint_TokenSize[8];
	char	buffer_TokenSize[10];
	char * hint_LabelSize[8];
	char	buffer_LabelSize[10];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[27];
	};
static int	vfh[16];

public	int	accept_abal_production_create(
	struct accept_abal_production_context ** cptr,
	char * pFileName,
	char * pFilePath,
	char * pIdentity,
	char * pPackaging,
	char * pIsAutoTrad,
	char * pIsTrueColour,
	char * pExactDimensions,
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
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_abal_production_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=42;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSWWWWWTTWWWWWWWWWSWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 255, pFileName);
		visual_transferin((void *) 0, 0, pFilePath);
		if (!( pFilePath )) _Context->value_FilePath=0;
		else	_Context->value_FilePath = *((int *)pFilePath);
		visual_transferin(_Context->buffer_Identity, 255, pIdentity);
		visual_transferin((void *) 0, 0, pPackaging);
		if (!( pPackaging )) _Context->value_Packaging=0;
		else	_Context->value_Packaging = *((int *)pPackaging);
		visual_transferin((void *) 0, 0, pIsAutoTrad);
		if (!( pIsAutoTrad )) _Context->value_IsAutoTrad=0;
		else	_Context->value_IsAutoTrad = *((int *)pIsAutoTrad);
		visual_transferin((void *) 0, 0, pIsTrueColour);
		if (!( pIsTrueColour )) _Context->value_IsTrueColour=0;
		else	_Context->value_IsTrueColour = *((int *)pIsTrueColour);
		visual_transferin((void *) 0, 0, pExactDimensions);
		if (!( pExactDimensions )) _Context->value_ExactDimensions=0;
		else	_Context->value_ExactDimensions = *((int *)pExactDimensions);
		visual_transferin((void *) 0, 0, pDimensions);
		if (!( pDimensions )) _Context->value_Dimensions=0;
		else	_Context->value_Dimensions = *((int *)pDimensions);
				_Context->buffer_Dependance=(char *) 0;
		visual_transferin(&_Context->buffer_Dependance, 1173, pDependance);
				_Context->buffer_Linkage=(char *) 0;
		visual_transferin(&_Context->buffer_Linkage, 1173, pLinkage);
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
		visual_transferin(_Context->buffer_PragmaFileName, 255, pPragmaFileName);
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
	_Context->hint_auto2[0]=en__auto2;
	_Context->hint_auto2[1]=fr__auto2;
	_Context->hint_auto2[2]=it__auto2;
	_Context->hint_auto2[3]=es__auto2;
	_Context->hint_auto2[4]=de__auto2;
	_Context->hint_auto2[5]=nl__auto2;
	_Context->hint_auto2[6]=pt__auto2;
	_Context->hint_auto2[7]=xx__auto2;
	_Context->x_auto2=90;
	_Context->y_auto2=65;
	_Context->w_auto2=620;
	_Context->h_auto2=470;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto2628[i]=" ";
	_Context->msg_Auto2628[0]=en_Auto2628;
	_Context->msg_Auto2628[1]=fr_Auto2628;
	_Context->msg_Auto2628[2]=it_Auto2628;
	_Context->msg_Auto2628[3]=es_Auto2628;
	_Context->msg_Auto2628[4]=de_Auto2628;
	_Context->msg_Auto2628[5]=nl_Auto2628;
	_Context->msg_Auto2628[6]=pt_Auto2628;
	_Context->msg_Auto2628[7]=xx_Auto2628;
	for (i=0; i < 8; i++)_Context->msg_Production[i]=" ";
	_Context->msg_Production[0]=en_Production;
	_Context->msg_Production[1]=fr_Production;
	_Context->msg_Production[2]=it_Production;
	_Context->msg_Production[3]=es_Production;
	_Context->msg_Production[4]=de_Production;
	_Context->msg_Production[5]=nl_Production;
	_Context->msg_Production[6]=pt_Production;
	_Context->msg_Production[7]=xx_Production;
	_Context->focus_pages[1]=2;
	for (i=0; i < 8; i++)_Context->msg_Auto2631[i]=" ";
	_Context->msg_Auto2631[0]=en_Auto2631;
	_Context->msg_Auto2631[1]=fr_Auto2631;
	_Context->msg_Auto2631[2]=it_Auto2631;
	_Context->msg_Auto2631[3]=es_Auto2631;
	_Context->msg_Auto2631[4]=de_Auto2631;
	_Context->msg_Auto2631[5]=nl_Auto2631;
	_Context->msg_Auto2631[6]=pt_Auto2631;
	_Context->msg_Auto2631[7]=xx_Auto2631;
	for (i=0; i < 8; i++)_Context->msg_Auto2632[i]=" ";
	_Context->msg_Auto2632[0]=en_Auto2632;
	_Context->msg_Auto2632[1]=fr_Auto2632;
	_Context->msg_Auto2632[2]=it_Auto2632;
	_Context->msg_Auto2632[3]=es_Auto2632;
	_Context->msg_Auto2632[4]=de_Auto2632;
	_Context->msg_Auto2632[5]=nl_Auto2632;
	_Context->msg_Auto2632[6]=pt_Auto2632;
	_Context->msg_Auto2632[7]=xx_Auto2632;
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
	_Context->hint_FileName[0]=en__FileName;
	for (i=0; i < 8; i++)_Context->msg_choixFileName[i]=" ";
	_Context->msg_choixFileName[0]=en_choixFileName;
	_Context->msg_choixFileName[1]=fr_choixFileName;
	_Context->msg_choixFileName[2]=it_choixFileName;
	_Context->msg_choixFileName[3]=es_choixFileName;
	_Context->msg_choixFileName[4]=de_choixFileName;
	_Context->msg_choixFileName[5]=nl_choixFileName;
	_Context->msg_choixFileName[6]=pt_choixFileName;
	_Context->msg_choixFileName[7]=xx_choixFileName;
	_Context->hint_choixFileName[0]=en__choixFileName;
	for (i=0; i < 8; i++)_Context->msg_FilePath[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_auto52[i]=" ";
	_Context->msg_auto52[0]=en_auto52;
	_Context->msg_auto52[1]=fr_auto52;
	_Context->msg_auto52[2]=it_auto52;
	_Context->msg_auto52[3]=es_auto52;
	_Context->msg_auto52[4]=de_auto52;
	_Context->msg_auto52[5]=nl_auto52;
	_Context->msg_auto52[6]=pt_auto52;
	_Context->msg_auto52[7]=xx_auto52;
	for (i=0; i < 8; i++)_Context->msg_Packaging[i]=" ";
	_Context->msg_Packaging[0]=en_Packaging;
	_Context->msg_Packaging[1]=fr_Packaging;
	_Context->msg_Packaging[2]=it_Packaging;
	_Context->msg_Packaging[3]=es_Packaging;
	_Context->msg_Packaging[4]=de_Packaging;
	_Context->msg_Packaging[5]=nl_Packaging;
	_Context->msg_Packaging[6]=pt_Packaging;
	_Context->msg_Packaging[7]=xx_Packaging;
	_Context->hint_Packaging[0]=en__Packaging;
	for (i=0; i < 8; i++)_Context->msg_IsAutoTrad[i]=" ";
	_Context->msg_IsAutoTrad[0]=en_IsAutoTrad;
	_Context->msg_IsAutoTrad[1]=fr_IsAutoTrad;
	_Context->msg_IsAutoTrad[2]=it_IsAutoTrad;
	_Context->msg_IsAutoTrad[3]=es_IsAutoTrad;
	_Context->msg_IsAutoTrad[4]=de_IsAutoTrad;
	_Context->msg_IsAutoTrad[5]=nl_IsAutoTrad;
	_Context->msg_IsAutoTrad[6]=pt_IsAutoTrad;
	_Context->msg_IsAutoTrad[7]=xx_IsAutoTrad;
	for (i=0; i < 8; i++)_Context->msg_IsTrueColour[i]=" ";
	_Context->msg_IsTrueColour[0]=en_IsTrueColour;
	_Context->msg_IsTrueColour[1]=fr_IsTrueColour;
	_Context->msg_IsTrueColour[2]=it_IsTrueColour;
	_Context->msg_IsTrueColour[3]=es_IsTrueColour;
	_Context->msg_IsTrueColour[4]=de_IsTrueColour;
	_Context->msg_IsTrueColour[5]=nl_IsTrueColour;
	_Context->msg_IsTrueColour[6]=pt_IsTrueColour;
	_Context->msg_IsTrueColour[7]=xx_IsTrueColour;
	_Context->hint_IsTrueColour[0]=en__IsTrueColour;
	for (i=0; i < 8; i++)_Context->msg_ExactDimensions[i]=" ";
	_Context->msg_ExactDimensions[0]=en_ExactDimensions;
	_Context->msg_ExactDimensions[1]=fr_ExactDimensions;
	_Context->msg_ExactDimensions[2]=it_ExactDimensions;
	_Context->msg_ExactDimensions[3]=es_ExactDimensions;
	_Context->msg_ExactDimensions[4]=de_ExactDimensions;
	_Context->msg_ExactDimensions[5]=nl_ExactDimensions;
	_Context->msg_ExactDimensions[6]=pt_ExactDimensions;
	_Context->msg_ExactDimensions[7]=xx_ExactDimensions;
	_Context->hint_ExactDimensions[0]=en__ExactDimensions;
	_Context->hint_ExactDimensions[1]=fr__ExactDimensions;
	_Context->hint_ExactDimensions[2]=it__ExactDimensions;
	_Context->hint_ExactDimensions[3]=es__ExactDimensions;
	_Context->hint_ExactDimensions[4]=de__ExactDimensions;
	_Context->hint_ExactDimensions[5]=nl__ExactDimensions;
	_Context->hint_ExactDimensions[6]=pt__ExactDimensions;
	_Context->hint_ExactDimensions[7]=xx__ExactDimensions;
	for (i=0; i < 8; i++)_Context->msg_Auto2633[i]=" ";
	_Context->msg_Auto2633[0]=en_Auto2633;
	_Context->msg_Auto2633[1]=fr_Auto2633;
	_Context->msg_Auto2633[2]=it_Auto2633;
	_Context->msg_Auto2633[3]=es_Auto2633;
	_Context->msg_Auto2633[4]=de_Auto2633;
	_Context->msg_Auto2633[5]=nl_Auto2633;
	_Context->msg_Auto2633[6]=pt_Auto2633;
	_Context->msg_Auto2633[7]=xx_Auto2633;
	for (i=0; i < 8; i++)_Context->msg_Auto2634[i]=" ";
	_Context->msg_Auto2634[0]=en_Auto2634;
	_Context->msg_Auto2634[1]=fr_Auto2634;
	_Context->msg_Auto2634[2]=it_Auto2634;
	_Context->msg_Auto2634[3]=es_Auto2634;
	_Context->msg_Auto2634[4]=de_Auto2634;
	_Context->msg_Auto2634[5]=nl_Auto2634;
	_Context->msg_Auto2634[6]=pt_Auto2634;
	_Context->msg_Auto2634[7]=xx_Auto2634;
	for (i=0; i < 8; i++)_Context->msg_Auto2635[i]=" ";
	_Context->msg_Auto2635[0]=en_Auto2635;
	_Context->msg_Auto2635[1]=fr_Auto2635;
	_Context->msg_Auto2635[2]=it_Auto2635;
	_Context->msg_Auto2635[3]=es_Auto2635;
	_Context->msg_Auto2635[4]=de_Auto2635;
	_Context->msg_Auto2635[5]=nl_Auto2635;
	_Context->msg_Auto2635[6]=pt_Auto2635;
	_Context->msg_Auto2635[7]=xx_Auto2635;
	for (i=0; i < 8; i++)_Context->msg_Dimensions[i]=" ";
	_Context->msg_Dimensions[0]=en_Dimensions;
	_Context->msg_Dimensions[1]=fr_Dimensions;
	_Context->msg_Dimensions[2]=it_Dimensions;
	_Context->msg_Dimensions[3]=es_Dimensions;
	_Context->msg_Dimensions[4]=de_Dimensions;
	_Context->msg_Dimensions[5]=nl_Dimensions;
	_Context->msg_Dimensions[6]=pt_Dimensions;
	_Context->msg_Dimensions[7]=xx_Dimensions;
	_Context->hint_Dimensions[0]=en__Dimensions;
	for (i=0; i < 8; i++)_Context->msg_UseAtr[i]=" ";
	_Context->msg_UseAtr[0]=en_UseAtr;
	_Context->msg_UseAtr[1]=fr_UseAtr;
	_Context->msg_UseAtr[2]=it_UseAtr;
	_Context->msg_UseAtr[3]=es_UseAtr;
	_Context->msg_UseAtr[4]=de_UseAtr;
	_Context->msg_UseAtr[5]=nl_UseAtr;
	_Context->msg_UseAtr[6]=pt_UseAtr;
	_Context->msg_UseAtr[7]=xx_UseAtr;
	for (i=0; i < 8; i++)_Context->msg_Link[i]=" ";
	_Context->msg_Link[0]=en_Link;
	_Context->msg_Link[1]=fr_Link;
	_Context->msg_Link[2]=it_Link;
	_Context->msg_Link[3]=es_Link;
	_Context->msg_Link[4]=de_Link;
	_Context->msg_Link[5]=nl_Link;
	_Context->msg_Link[6]=pt_Link;
	_Context->msg_Link[7]=xx_Link;
	_Context->hint_Link[0]=en__Link;
	for (i=0; i < 8; i++)_Context->msg_UseEdit[i]=" ";
	_Context->msg_UseEdit[0]=en_UseEdit;
	_Context->msg_UseEdit[1]=fr_UseEdit;
	_Context->msg_UseEdit[2]=it_UseEdit;
	_Context->msg_UseEdit[3]=es_UseEdit;
	_Context->msg_UseEdit[4]=de_UseEdit;
	_Context->msg_UseEdit[5]=nl_UseEdit;
	_Context->msg_UseEdit[6]=pt_UseEdit;
	_Context->msg_UseEdit[7]=xx_UseEdit;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	_Context->msg_Select[2]=it_Select;
	_Context->msg_Select[3]=es_Select;
	_Context->msg_Select[4]=de_Select;
	_Context->msg_Select[5]=nl_Select;
	_Context->msg_Select[6]=pt_Select;
	_Context->msg_Select[7]=xx_Select;
	for (i=0; i < 8; i++)_Context->msg_Inclusion[i]=" ";
	_Context->msg_Inclusion[0]=en_Inclusion;
	_Context->msg_Inclusion[1]=fr_Inclusion;
	_Context->msg_Inclusion[2]=it_Inclusion;
	_Context->msg_Inclusion[3]=es_Inclusion;
	_Context->msg_Inclusion[4]=de_Inclusion;
	_Context->msg_Inclusion[5]=nl_Inclusion;
	_Context->msg_Inclusion[6]=pt_Inclusion;
	_Context->msg_Inclusion[7]=xx_Inclusion;
	_Context->hint_Inclusion[0]=en__Inclusion;
	_Context->focus_pages[2]=21;
	for (i=0; i < 8; i++)_Context->msg_Modules[i]=" ";
	_Context->msg_Modules[0]=en_Modules;
	_Context->msg_Modules[1]=fr_Modules;
	_Context->msg_Modules[2]=it_Modules;
	_Context->msg_Modules[3]=es_Modules;
	_Context->msg_Modules[4]=de_Modules;
	_Context->msg_Modules[5]=nl_Modules;
	_Context->msg_Modules[6]=pt_Modules;
	_Context->msg_Modules[7]=xx_Modules;
	_Context->hint_Modules[0]=en__Modules;
	_Context->focus_pages[3]=23;
	for (i=0; i < 8; i++)_Context->msg_PragmaPage[i]=" ";
	_Context->msg_PragmaPage[0]=en_PragmaPage;
	_Context->msg_PragmaPage[1]=fr_PragmaPage;
	_Context->msg_PragmaPage[2]=it_PragmaPage;
	_Context->msg_PragmaPage[3]=es_PragmaPage;
	_Context->msg_PragmaPage[4]=de_PragmaPage;
	_Context->msg_PragmaPage[5]=nl_PragmaPage;
	_Context->msg_PragmaPage[6]=pt_PragmaPage;
	_Context->msg_PragmaPage[7]=xx_PragmaPage;
	_Context->focus_pages[4]=25;
	for (i=0; i < 8; i++)_Context->msg_Auto2636[i]=" ";
	_Context->msg_Auto2636[0]=en_Auto2636;
	_Context->msg_Auto2636[1]=fr_Auto2636;
	_Context->msg_Auto2636[2]=it_Auto2636;
	_Context->msg_Auto2636[3]=es_Auto2636;
	_Context->msg_Auto2636[4]=de_Auto2636;
	_Context->msg_Auto2636[5]=nl_Auto2636;
	_Context->msg_Auto2636[6]=pt_Auto2636;
	_Context->msg_Auto2636[7]=xx_Auto2636;
	for (i=0; i < 8; i++)_Context->msg_Auto2638[i]=" ";
	_Context->msg_Auto2638[0]=en_Auto2638;
	_Context->msg_Auto2638[1]=fr_Auto2638;
	_Context->msg_Auto2638[2]=it_Auto2638;
	_Context->msg_Auto2638[3]=es_Auto2638;
	_Context->msg_Auto2638[4]=de_Auto2638;
	_Context->msg_Auto2638[5]=nl_Auto2638;
	_Context->msg_Auto2638[6]=pt_Auto2638;
	_Context->msg_Auto2638[7]=xx_Auto2638;
	for (i=0; i < 8; i++)_Context->msg_UseDiezeMem[i]=" ";
	_Context->msg_UseDiezeMem[0]=en_UseDiezeMem;
	_Context->msg_UseDiezeMem[1]=fr_UseDiezeMem;
	_Context->msg_UseDiezeMem[2]=it_UseDiezeMem;
	_Context->msg_UseDiezeMem[3]=es_UseDiezeMem;
	_Context->msg_UseDiezeMem[4]=de_UseDiezeMem;
	_Context->msg_UseDiezeMem[5]=nl_UseDiezeMem;
	_Context->msg_UseDiezeMem[6]=pt_UseDiezeMem;
	_Context->msg_UseDiezeMem[7]=xx_UseDiezeMem;
	for (i=0; i < 8; i++)_Context->msg_UseDiezeStack[i]=" ";
	_Context->msg_UseDiezeStack[0]=en_UseDiezeStack;
	_Context->msg_UseDiezeStack[1]=fr_UseDiezeStack;
	_Context->msg_UseDiezeStack[2]=it_UseDiezeStack;
	_Context->msg_UseDiezeStack[3]=es_UseDiezeStack;
	_Context->msg_UseDiezeStack[4]=de_UseDiezeStack;
	_Context->msg_UseDiezeStack[5]=nl_UseDiezeStack;
	_Context->msg_UseDiezeStack[6]=pt_UseDiezeStack;
	_Context->msg_UseDiezeStack[7]=xx_UseDiezeStack;
	for (i=0; i < 8; i++)_Context->msg_UseDiezeFiles[i]=" ";
	_Context->msg_UseDiezeFiles[0]=en_UseDiezeFiles;
	_Context->msg_UseDiezeFiles[1]=fr_UseDiezeFiles;
	_Context->msg_UseDiezeFiles[2]=it_UseDiezeFiles;
	_Context->msg_UseDiezeFiles[3]=es_UseDiezeFiles;
	_Context->msg_UseDiezeFiles[4]=de_UseDiezeFiles;
	_Context->msg_UseDiezeFiles[5]=nl_UseDiezeFiles;
	_Context->msg_UseDiezeFiles[6]=pt_UseDiezeFiles;
	_Context->msg_UseDiezeFiles[7]=xx_UseDiezeFiles;
	for (i=0; i < 8; i++)_Context->msg_UseDiezeHeap[i]=" ";
	_Context->msg_UseDiezeHeap[0]=en_UseDiezeHeap;
	_Context->msg_UseDiezeHeap[1]=fr_UseDiezeHeap;
	_Context->msg_UseDiezeHeap[2]=it_UseDiezeHeap;
	_Context->msg_UseDiezeHeap[3]=es_UseDiezeHeap;
	_Context->msg_UseDiezeHeap[4]=de_UseDiezeHeap;
	_Context->msg_UseDiezeHeap[5]=nl_UseDiezeHeap;
	_Context->msg_UseDiezeHeap[6]=pt_UseDiezeHeap;
	_Context->msg_UseDiezeHeap[7]=xx_UseDiezeHeap;
	for (i=0; i < 8; i++)_Context->msg_UsePragmaFile[i]=" ";
	_Context->msg_UsePragmaFile[0]=en_UsePragmaFile;
	_Context->msg_UsePragmaFile[1]=fr_UsePragmaFile;
	_Context->msg_UsePragmaFile[2]=it_UsePragmaFile;
	_Context->msg_UsePragmaFile[3]=es_UsePragmaFile;
	_Context->msg_UsePragmaFile[4]=de_UsePragmaFile;
	_Context->msg_UsePragmaFile[5]=nl_UsePragmaFile;
	_Context->msg_UsePragmaFile[6]=pt_UsePragmaFile;
	_Context->msg_UsePragmaFile[7]=xx_UsePragmaFile;
	_Context->hint_PragmaFileName[0]=en__PragmaFileName;
	for (i=0; i < 8; i++)_Context->msg_choixPragmaFileName[i]=" ";
	_Context->msg_choixPragmaFileName[0]=en_choixPragmaFileName;
	_Context->msg_choixPragmaFileName[1]=fr_choixPragmaFileName;
	_Context->msg_choixPragmaFileName[2]=it_choixPragmaFileName;
	_Context->msg_choixPragmaFileName[3]=es_choixPragmaFileName;
	_Context->msg_choixPragmaFileName[4]=de_choixPragmaFileName;
	_Context->msg_choixPragmaFileName[5]=nl_choixPragmaFileName;
	_Context->msg_choixPragmaFileName[6]=pt_choixPragmaFileName;
	_Context->msg_choixPragmaFileName[7]=xx_choixPragmaFileName;
	_Context->hint_choixPragmaFileName[0]=en__choixPragmaFileName;
	for (i=0; i < 8; i++)_Context->msg_RespectCase[i]=" ";
	_Context->msg_RespectCase[0]=en_RespectCase;
	_Context->msg_RespectCase[1]=fr_RespectCase;
	_Context->msg_RespectCase[2]=it_RespectCase;
	_Context->msg_RespectCase[3]=es_RespectCase;
	_Context->msg_RespectCase[4]=de_RespectCase;
	_Context->msg_RespectCase[5]=nl_RespectCase;
	_Context->msg_RespectCase[6]=pt_RespectCase;
	_Context->msg_RespectCase[7]=xx_RespectCase;
	_Context->hint_RespectCase[0]=en__RespectCase;
	_Context->hint_RespectCase[1]=fr__RespectCase;
	_Context->hint_RespectCase[2]=it__RespectCase;
	_Context->hint_RespectCase[3]=es__RespectCase;
	_Context->hint_RespectCase[4]=de__RespectCase;
	_Context->hint_RespectCase[5]=nl__RespectCase;
	_Context->hint_RespectCase[6]=pt__RespectCase;
	_Context->hint_RespectCase[7]=xx__RespectCase;
	for (i=0; i < 8; i++)_Context->msg_OptimiseTables[i]=" ";
	_Context->msg_OptimiseTables[0]=en_OptimiseTables;
	_Context->msg_OptimiseTables[1]=fr_OptimiseTables;
	_Context->msg_OptimiseTables[2]=it_OptimiseTables;
	_Context->msg_OptimiseTables[3]=es_OptimiseTables;
	_Context->msg_OptimiseTables[4]=de_OptimiseTables;
	_Context->msg_OptimiseTables[5]=nl_OptimiseTables;
	_Context->msg_OptimiseTables[6]=pt_OptimiseTables;
	_Context->msg_OptimiseTables[7]=xx_OptimiseTables;
	_Context->hint_OptimiseTables[0]=en__OptimiseTables;
	_Context->hint_OptimiseTables[1]=fr__OptimiseTables;
	_Context->hint_OptimiseTables[2]=it__OptimiseTables;
	_Context->hint_OptimiseTables[3]=es__OptimiseTables;
	_Context->hint_OptimiseTables[4]=de__OptimiseTables;
	_Context->hint_OptimiseTables[5]=nl__OptimiseTables;
	_Context->hint_OptimiseTables[6]=pt__OptimiseTables;
	_Context->hint_OptimiseTables[7]=xx__OptimiseTables;
	for (i=0; i < 8; i++)_Context->msg_UseTokenSize[i]=" ";
	_Context->msg_UseTokenSize[0]=en_UseTokenSize;
	_Context->msg_UseTokenSize[1]=fr_UseTokenSize;
	_Context->msg_UseTokenSize[2]=it_UseTokenSize;
	_Context->msg_UseTokenSize[3]=es_UseTokenSize;
	_Context->msg_UseTokenSize[4]=de_UseTokenSize;
	_Context->msg_UseTokenSize[5]=nl_UseTokenSize;
	_Context->msg_UseTokenSize[6]=pt_UseTokenSize;
	_Context->msg_UseTokenSize[7]=xx_UseTokenSize;
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
	_Context->pushbuffer=visual_buffer(_Context->x_auto2,_Context->y_auto2,620+10,470+10);
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
	char * pFilePath,
	char * pIdentity,
	char * pPackaging,
	char * pIsAutoTrad,
	char * pIsTrueColour,
	char * pExactDimensions,
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
	if (_Context->keycode == 27 ) {
		filetransferdrop(_Context->buffer_Dependance);
		filetransferdrop(_Context->buffer_Linkage);
		
	} else {
		strcpy(_Context->signature,"SSSWWWWWTTWWWWWWWWWSWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 255, pFileName);
		visual_transferout((void *) 0, 0, pFilePath);
		if ( pFilePath != (char *) 0)
			*((int*)pFilePath) = _Context->value_FilePath;
		visual_transferout(_Context->buffer_Identity, 255, pIdentity);
		visual_transferout((void *) 0, 0, pPackaging);
		if ( pPackaging != (char *) 0)
			*((int*)pPackaging) = _Context->value_Packaging;
		visual_transferout((void *) 0, 0, pIsAutoTrad);
		if ( pIsAutoTrad != (char *) 0)
			*((int*)pIsAutoTrad) = _Context->value_IsAutoTrad;
		visual_transferout((void *) 0, 0, pIsTrueColour);
		if ( pIsTrueColour != (char *) 0)
			*((int*)pIsTrueColour) = _Context->value_IsTrueColour;
		visual_transferout((void *) 0, 0, pExactDimensions);
		if ( pExactDimensions != (char *) 0)
			*((int*)pExactDimensions) = _Context->value_ExactDimensions;
		visual_transferout((void *) 0, 0, pDimensions);
		if ( pDimensions != (char *) 0)
			*((int*)pDimensions) = _Context->value_Dimensions;
		visual_transferout(&_Context->buffer_Dependance, 1173, pDependance);
		visual_transferout(&_Context->buffer_Linkage, 1173, pLinkage);
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
		visual_transferout(_Context->buffer_PragmaFileName, 255, pPragmaFileName);
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
	552,272,_Context->buffer_Dependance);
	return(-1);
}
private int on_Dependance_show(struct accept_abal_production_context * _Context) {
	visual_frame(_Context->x_auto2+30,_Context->y_auto2+110,552+2,272+2,5);
;
	show_window_editor();
	return(-1);
}
private int on_Modules_show(struct accept_abal_production_context * _Context) {
	open_window_editor(_Context->x_auto2+30,_Context->y_auto2+110,
	552,272,_Context->buffer_Linkage);
	return(-1);
}
private int on_Linkage_show(struct accept_abal_production_context * _Context) {
	visual_frame(_Context->x_auto2+30,_Context->y_auto2+110,552+2,272+2,5);
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
	if (((_Context->status = visual_styled_element(_Context->x_auto2,_Context->y_auto2,620,470,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_auto2,_Context->y_auto2,620,470,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_auto2+10,_Context->y_auto2+30,590,30,vfh[3],27,0,_Context->msg_Auto2628[_Context->language],strlen(_Context->msg_Auto2628[_Context->language]),515);
	visual_frame(_Context->x_auto2+280,_Context->y_auto2+300,70,70,1);
	if (_Context->page_number == 1 ) {
	_Context->trigger_Production=visual_trigger_code(_Context->msg_Production[_Context->language],strlen(_Context->msg_Production[_Context->language]));
	visual_tabpage(_Context->x_auto2+20,_Context->y_auto2+70,580,330,vfh[2],_Context->msg_Production[_Context->language],strlen(_Context->msg_Production[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_auto2+20,_Context->y_auto2+70,580,330,vfh[2],_Context->msg_Production[_Context->language],strlen(_Context->msg_Production[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_auto2+40,_Context->y_auto2+244,540,100,2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_auto2+50,_Context->y_auto2+250,141,18,vfh[2],27,0,_Context->msg_Auto2631[_Context->language],strlen(_Context->msg_Auto2631[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_image(_Context->x_auto2+370,_Context->y_auto2+270,51,53,_Context->msg_Auto2632[_Context->language],3);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_auto2+40,_Context->y_auto2+110,540,20,vfh[2],16,0,_Context->msg_auto7[_Context->language],strlen(_Context->msg_auto7[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_auto2+40,_Context->y_auto2+130,511+2,16+2,5);
	visual_text(_Context->x_auto2+40+1,_Context->y_auto2+130+1,511,16,vfh[1],34,0,_Context->buffer_FileName,255,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_choixFileName=visual_trigger_code(_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]));
	visual_button(_Context->x_auto2+556,_Context->y_auto2+130,20,18,vfh[1],27,28,_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_auto2+40,_Context->y_auto2+150,536,16,vfh[1],34,0,parse_selection(GetPathSelection(),&_Context->value_FilePath),0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_auto2+40,_Context->y_auto2+190,540,20,vfh[2],16,0,_Context->msg_auto52[_Context->language],strlen(_Context->msg_auto52[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_auto2+40,_Context->y_auto2+210,536+2,16+2,5);
	visual_text(_Context->x_auto2+40+1,_Context->y_auto2+210+1,536,16,vfh[1],34,0,_Context->buffer_Identity,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_auto2+50,_Context->y_auto2+270,141,70,vfh[2],0,0,parse_selection(_Context->msg_Packaging[_Context->language],&_Context->value_Packaging),768);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_IsAutoTrad=visual_trigger_code(_Context->msg_IsAutoTrad[_Context->language],strlen(_Context->msg_IsAutoTrad[_Context->language]));
	visual_check(_Context->x_auto2+210,_Context->y_auto2+270,154,16,vfh[2],27,0,_Context->msg_IsAutoTrad[_Context->language],strlen(_Context->msg_IsAutoTrad[_Context->language]),_Context->value_IsAutoTrad|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_IsTrueColour=visual_trigger_code(_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]));
	visual_check(_Context->x_auto2+210,_Context->y_auto2+290,154,16,vfh[2],27,0,_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]),_Context->value_IsTrueColour|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ExactDimensions=visual_trigger_code(_Context->msg_ExactDimensions[_Context->language],strlen(_Context->msg_ExactDimensions[_Context->language]));
	visual_check(_Context->x_auto2+210,_Context->y_auto2+310,168,16,vfh[2],27,0,_Context->msg_ExactDimensions[_Context->language],strlen(_Context->msg_ExactDimensions[_Context->language]),_Context->value_ExactDimensions|0);
		}
	_Context->trigger_Auto2633=visual_trigger_code(_Context->msg_Auto2633[_Context->language],strlen(_Context->msg_Auto2633[_Context->language]));
	visual_button(_Context->x_auto2+20,_Context->y_auto2+410,56,48,vfh[2],34,0,_Context->msg_Auto2633[_Context->language],strlen(_Context->msg_Auto2633[_Context->language]),1040);
	_Context->trigger_Auto2634=visual_trigger_code(_Context->msg_Auto2634[_Context->language],strlen(_Context->msg_Auto2634[_Context->language]));
	visual_button(_Context->x_auto2+540,_Context->y_auto2+410,56,48,vfh[2],34,0,_Context->msg_Auto2634[_Context->language],strlen(_Context->msg_Auto2634[_Context->language]),1040);
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_auto2+430,_Context->y_auto2+250,140,20,vfh[2],27,0,_Context->msg_Auto2635[_Context->language],strlen(_Context->msg_Auto2635[_Context->language]),1);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_auto2+430,_Context->y_auto2+270,140,100,vfh[2],0,0,parse_selection(_Context->msg_Dimensions[_Context->language],&_Context->value_Dimensions),768);
		}
	_Context->trigger_UseAtr=visual_trigger_code(_Context->msg_UseAtr[_Context->language],strlen(_Context->msg_UseAtr[_Context->language]));
	visual_button(_Context->x_auto2+210,_Context->y_auto2+420,90,30,vfh[2],26,0,_Context->msg_UseAtr[_Context->language],strlen(_Context->msg_UseAtr[_Context->language]),0);
	_Context->trigger_Link=visual_trigger_code(_Context->msg_Link[_Context->language],strlen(_Context->msg_Link[_Context->language]));
	visual_button(_Context->x_auto2+310,_Context->y_auto2+420,90,30,vfh[2],16,28,_Context->msg_Link[_Context->language],strlen(_Context->msg_Link[_Context->language]),0);
	if (_Context->page_number == 1 ) {
	_Context->trigger_UseEdit=visual_trigger_code(_Context->msg_UseEdit[_Context->language],strlen(_Context->msg_UseEdit[_Context->language]));
	visual_button(_Context->x_auto2+210,_Context->y_auto2+360,90,30,vfh[2],26,0,_Context->msg_UseEdit[_Context->language],strlen(_Context->msg_UseEdit[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto2+310,_Context->y_auto2+360,90,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Inclusion=visual_trigger_code(_Context->msg_Inclusion[_Context->language],strlen(_Context->msg_Inclusion[_Context->language]));
	visual_tabpage(_Context->x_auto2+20,_Context->y_auto2+70,580,330,vfh[2],_Context->msg_Inclusion[_Context->language],strlen(_Context->msg_Inclusion[_Context->language]),104,2);
		(void) on_Inclusion_show(_Context);
	} else {
		visual_tabpage(_Context->x_auto2+20,_Context->y_auto2+70,580,330,vfh[2],_Context->msg_Inclusion[_Context->language],strlen(_Context->msg_Inclusion[_Context->language]),104,0);
		}
	if (_Context->page_number == 2 ) {
	(void) on_Dependance_show(_Context);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_Modules=visual_trigger_code(_Context->msg_Modules[_Context->language],strlen(_Context->msg_Modules[_Context->language]));
	visual_tabpage(_Context->x_auto2+20,_Context->y_auto2+70,580,330,vfh[2],_Context->msg_Modules[_Context->language],strlen(_Context->msg_Modules[_Context->language]),193,2);
		(void) on_Modules_show(_Context);
	} else {
		visual_tabpage(_Context->x_auto2+20,_Context->y_auto2+70,580,330,vfh[2],_Context->msg_Modules[_Context->language],strlen(_Context->msg_Modules[_Context->language]),193,0);
		}
	if (_Context->page_number == 3 ) {
	(void) on_Linkage_show(_Context);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_PragmaPage=visual_trigger_code(_Context->msg_PragmaPage[_Context->language],strlen(_Context->msg_PragmaPage[_Context->language]));
	visual_tabpage(_Context->x_auto2+20,_Context->y_auto2+70,580,330,vfh[2],_Context->msg_PragmaPage[_Context->language],strlen(_Context->msg_PragmaPage[_Context->language]),280,2);
	} else {
		visual_tabpage(_Context->x_auto2+20,_Context->y_auto2+70,580,330,vfh[2],_Context->msg_PragmaPage[_Context->language],strlen(_Context->msg_PragmaPage[_Context->language]),280,0);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_auto2+40,_Context->y_auto2+110,260,16,vfh[2],16,0,_Context->msg_Auto2636[_Context->language],strlen(_Context->msg_Auto2636[_Context->language]),259);
	visual_frame(_Context->x_auto2+40,_Context->y_auto2+126,260,184,4);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_auto2+40,_Context->y_auto2+330,540,40,4);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_auto2+310,_Context->y_auto2+110,270,16,vfh[2],16,0,_Context->msg_Auto2638[_Context->language],strlen(_Context->msg_Auto2638[_Context->language]),259);
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
	visual_check(_Context->x_auto2+50,_Context->y_auto2+340,168,16,vfh[2],27,28,_Context->msg_UsePragmaFile[_Context->language],strlen(_Context->msg_UsePragmaFile[_Context->language]),_Context->value_UsePragmaFile|0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_auto2+220,_Context->y_auto2+340,326+2,16+2,5);
	visual_text(_Context->x_auto2+220+1,_Context->y_auto2+340+1,326,16,vfh[1],27,28,_Context->buffer_PragmaFileName,255,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_choixPragmaFileName=visual_trigger_code(_Context->msg_choixPragmaFileName[_Context->language],strlen(_Context->msg_choixPragmaFileName[_Context->language]));
	visual_button(_Context->x_auto2+556,_Context->y_auto2+340,20,18,vfh[1],27,28,_Context->msg_choixPragmaFileName[_Context->language],strlen(_Context->msg_choixPragmaFileName[_Context->language]),0);
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
	visual_thaw(_Context->x_auto2,_Context->y_auto2,620,470);

	return(0);
}

private int Production_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This page presents the general production parameters.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "Cette page pr‚sente les paramŠtres g‚n‚raux de production.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The ABAL++ Production Filename field identifies the full path and ";
			mptr[1]="filename of the target to which  the production of source will be ";
			mptr[2]="generated.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Le champ de Nom de Fichier de production ABAL++ identifie le chemin ";
			mptr[1]="complet et le nom de fichier de la cible dans laquelle la production ";
			mptr[2]="de source sera g‚n‚r‚e.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FilePath_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The ABAL++ Production Filename field identifies the full path and ";
			mptr[1]="filename of the target to which  the production of source will be ";
			mptr[2]="generated.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Le champ de Nom de Fichier de production ABAL++ identifie le chemin ";
			mptr[1]="complet et le nom de fichier de la cible dans laquelle la production ";
			mptr[2]="de source sera g‚n‚r‚e.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Identity_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[13];
			mptr[0] = "This usage of this edit field value depends on both the production ";
			mptr[1]="language and the production packaging.   ";
			mptr[2]=" ";
			mptr[3]="For ABAL++ production ir provides the class name.  ";
			mptr[4]=" ";
			mptr[5]="For the production of an ABAL module it provides the stub or root ";
			mptr[6]="name of the module interface and support procedures.  ";
			mptr[7]=" ";
			mptr[8]="For ABAL PROGRAM production packages it will be used un the generation ";
			mptr[9]="of the PROGRAM statement.  ";
			mptr[10]=" ";
			mptr[11]="In all cases it will be used as the title and identification of the ";
			mptr[12]="model in html document production.   ";
			return(visual_online_help(mptr,13));
			}
			break;
		case 1 : 
			{
			char * mptr[14];
			mptr[0] = "L'utilisation de la valeur de ce champ d‚pend et du langage de production ";
			mptr[1]="et du l'emballage (packaging) de production.  ";
			mptr[2]=" ";
			mptr[3]="Pour une production ABAL++ il fournit le nom de classe.  ";
			mptr[4]=" ";
			mptr[5]="Pour une production d'un module ABAL, il fournit le pied ou le nom ";
			mptr[6]="de la racine des proc‚dures d'interface et de support des modules. ";
			mptr[7]="  ";
			mptr[8]=" ";
			mptr[9]="Pour les empaquetages de production de PROGRAMMES ABAL, il sera utilis‚ ";
			mptr[10]="pour la g‚n‚ration de la d‚claration de PROGRAMME.  ";
			mptr[11]=" ";
			mptr[12]="Dans tous les cas, il sera utilis‚ comme le titre et l'identification ";
			mptr[13]="du modŠle dans la production de documents html.   ";
			return(visual_online_help(mptr,14));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Packaging_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[18];
			mptr[0] = "This control allows selection of the ABAL production packaging model ";
			mptr[1]="from the following list  ";
			mptr[2]=" ";
			mptr[3]="   ";
			mptr[4]=" Model Description  ";
			mptr[5]=" Program Production packages of this type are intended to fulfil the ";
			mptr[6]="requirements of application root scenarios to which modules may be ";
			mptr[7]="linked, sources included and to which overlays may be attached.  ";
			mptr[8]=" Module These production packages are suitable for the implementation ";
			mptr[9]="of resident application  services for use from various application ";
			mptr[10]="platforms.Modular production includes the generation of the corresponding ";
			mptr[11]="external reference description file.  ";
			mptr[12]=" Overlay These production packages are intended for the implementation ";
			mptr[13]="of transient application services again to be shared amongst applications. ";
			mptr[14]=" ";
			mptr[15]=" Include This packaging is intended for the production of re-usable ";
			mptr[16]=" visual components in the form of a class file to be included by other ";
			mptr[17]="packaging types for the resolution of visual complex data types.     ";
			return(visual_online_help(mptr,18));
			}
			break;
		case 1 : 
			{
			char * mptr[21];
			mptr[0] = "Ce contr“le permet la s‚lection du modŠle d'emballage (packaging) ";
			mptr[1]="de la production ABAL … partir de la liste suivante  ";
			mptr[2]=" ";
			mptr[3]="   ";
			mptr[4]=" ModŠle Description  ";
			mptr[5]=" Programme Les Packages de Production de ce type sont pr‚vus pour satisfaire ";
			mptr[6]="aux conditions  requises par les sc‚narios racines de l'application, ";
			mptr[7]="auxquels des modules peuvent ˆtre li‚s, des sources inclus et de overlays ";
			mptr[8]="attach‚s.  ";
			mptr[9]=" Module Ces packages de production conviennent pour l'impl‚mentation ";
			mptr[10]="de services d'application r‚sidents pour l'utilisation depuis diverses ";
			mptr[11]="plateformes d'application. La production modulaire inclut la g‚n‚ration ";
			mptr[12]="d'un fichier correspondant de description des r‚f‚rences externes. ";
			mptr[13]=" ";
			mptr[14]=" Overlay Ces packages de production sont pr‚vus pour l'impl‚mentation ";
			mptr[15]="de services d'application transitoires devant aussi ˆtre partag‚s ";
			mptr[16]="entre plusieurs applications.  ";
			mptr[17]=" Include Cet emballage (packaging) est pr‚vu pour la production de  ";
			mptr[18]="composants visuels r‚utilisables sous forme d'un fichier de classe ";
			mptr[19]="devant ˆtre inclus par d'autres types d'emballage (packaging) pour ";
			mptr[20]="la r‚solution de types de donn‚es visuelles complexes.     ";
			return(visual_online_help(mptr,21));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsAutoTrad_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "When this control is checked secondary production phases will be performed ";
			mptr[1]="without prior user confirmation. Secondary production involves source ";
			mptr[2]="translation and eventual object linking as described by the  various ";
			mptr[3]="production parameters.    ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Quand ce contr“le est coch‚, les phases de production secondaire  ";
			mptr[1]="seront ex‚cut‚es sans confirmation pr‚alable de l'utilisateur. La ";
			mptr[2]="production secondaire implique une traduction de source et un lien ";
			mptr[3]="objet (linking) ‚ventuel comme d‚crit par les divers paramŠtres de ";
			mptr[4]="production.    ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IsTrueColour_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[9];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" When this control had been checked, true colour mode of operation ";
			mptr[3]="will be requested by the VisualInitialise or VisualActivate instruction generated for the OnCreate ";
			mptr[4]="method of the parent form.  ";
			mptr[5]=" ";
			mptr[6]="When unchecked, 256 colour palette mode will be selected.  ";
			mptr[7]=" ";
			mptr[8]="    ";
			return(visual_online_help(mptr,9));
			}
			break;
		case 1 : 
			{
			char * mptr[10];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" Lors que ce contr“le a ‚t‚ coch‚, l'instruction VisualInitialise ";
			mptr[3]="ou VisualActivate produit dans le OnCreate du formulaire prend le parametre ";
			mptr[4]="d'activation du mode True Colour.  ";
			mptr[5]=" ";
			mptr[6]="Autrement le mode standard avec le palette de 256 couleurs se voit ";
			mptr[7]="activ‚.  ";
			mptr[8]=" ";
			mptr[9]="   ";
			return(visual_online_help(mptr,10));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ExactDimensions_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[9];
			mptr[0] = "When this control is checked the form window dimensions are preserved ";
			mptr[1]="instead of being rounded up to the nearest VESA display mode.  ";
			mptr[2]=" ";
			mptr[3]="In this case the form dimensions will be used in the generation of ";
			mptr[4]=" a VisualActivate instruction instead of the VisualInitialise instruction ";
			mptr[5]="generated to use the VESA display mode.  ";
			mptr[6]=" ";
			mptr[7]="In addition window alignment will be performed with respect to runtime ";
			mptr[8]="screen width activetool the Conf(68) and Conf(69) values during the OnCreate method of the parent form.    ";
			return(visual_online_help(mptr,9));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Quand ce contr“le est coch‚, les phases de production secondaire  ";
			mptr[1]="seront ex‚cut‚es sans confirmation pr‚alable de l'utilisateur. La ";
			mptr[2]="production secondaire implique une traduction de source et un lien ";
			mptr[3]="objet (linking) ‚ventuel comme d‚crit par les divers paramŠtres de ";
			mptr[4]="production.    ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto2633_help()
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

private int Auto2634_help()
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

private int Auto2635_help()
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

private int Dimensions_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This control allows selection of the target graphics resolutions required ";
			mptr[1]="for the production of program packaging. The optimal value will be ";
			mptr[2]="calculated prior to presentation of this dialog frame. It may be increased ";
			mptr[3]="as needed to encompass the requirements of secondary components.  ";
			mptr[4]=" ";
			return(visual_online_help(mptr,5));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Ce contr“le permet la s‚lection des r‚solutions des graphiques cibles ";
			mptr[1]="requises pour la production d'emballage (packaging) de programmes. ";
			mptr[2]="La valeur optimale sera calcul‚e avant la pr‚sentation de cette boŒte ";
			mptr[3]="de dialogue. Il peut ˆtre augment‚ si n‚cessaire pour prendre en compte ";
			mptr[4]="les besoins des composants secondaires.  ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int UseAtr_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This button provides direct access to the secondary production or ";
			mptr[1]="translation phase required for all ABAL production packing models ";
			mptr[2]="except inclusions.  The filename indicated in the Target filename ";
			mptr[3]="field will be submited for translation via the Abal Translator dialog frame.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Ce bouton fournit un accŠs direct … la phase de traduction ou de production ";
			mptr[1]="secondaire requise pour les modŠles  d'emballage (packing) de production ";
			mptr[2]="ABAL, except‚es les inclusions. Le nom de fichier indiqu‚ dans le ";
			mptr[3]="champ Nom de fichier Cible sera soumis pour traduction  via la boŒte ";
			mptr[4]="de dialogue du Traducteur Abal.  ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Link_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This button provides a short cut to the final phase of secondary production ";
			mptr[1]="for ABAL program and  overlay packaging models for which module linking ";
			mptr[2]="is required.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Ce bouton fournit un raccourci de la phase finale de production secondaire ";
			mptr[1]="pour des modŠles d'emballage (packaging) de programmes et d'overlays ";
			mptr[2]="pour lesquels le lien (linking) avec des modules est requis.  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int UseEdit_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the EDIT button the filename indicated in the Target filename ";
			mptr[1]="field will be opened  for inspection activetool the standard Text Editor.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "En pressant le bouton EDITION le nom de fichier indiqu‚ dans le champ ";
			mptr[1]="de nom de fichier Cible sera ouvert  pour examen en utilisant l'Editeur de Texte standard.    ";
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
			mptr[0] = "The Select button allows access  to the file selection dialog frame ";
			mptr[1]="allowing prompted selection of the production target filename.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Le bouton Selection permet d'acc‚der … la boŒte de dialogue de  s‚lection ";
			mptr[1]="de fichier pour la saisie du nom de fichier cible  de production.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Inclusion_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[17];
			mptr[0] = "This page allows the names of the various files required to be included ";
			mptr[1]="to be specified. The names may be specified in any order and will ";
			mptr[2]="be sorted in terms of their extension to be included as follows : ";
			mptr[3]=" ";
			mptr[4]=" ";
			mptr[5]="   ";
			mptr[6]=" EXTENSION Description  ";
			mptr[7]=" DEF Library definition files will be included prior to the generation ";
			mptr[8]="of their packaging statement.  ";
			mptr[9]=" CLS Files bearing this extension will be included prior to the generation ";
			mptr[10]="of the program module or overlay packaging.  ";
			mptr[11]=" DCL Files bearing this extension will be included after the production ";
			mptr[12]="of the model data section.  ";
			mptr[13]=" EXT Files bearing this extension will be included prior to the generation ";
			mptr[14]="of the internal procedures  ";
			mptr[15]=" OTHER  All other file extensions will the be included prior to the ";
			mptr[16]="generation of forward, extern and procedure statements.    ";
			return(visual_online_help(mptr,17));
			}
			break;
		case 1 : 
			{
			char * mptr[17];
			mptr[0] = "Cette page permet de pr‚ciser les noms des divers fichiers devant ";
			mptr[1]="ˆtre inclus. Les noms peuvent ˆtre pr‚cis‚s dans  un ordre quelconque ";
			mptr[2]="et seront tri‚s en fonction de leurs extensions, pour ˆtre inclus ";
			mptr[3]="comme d‚crit ci-aprŠs:   ";
			mptr[4]=" ";
			mptr[5]="   ";
			mptr[6]=" EXTENSION Description  ";
			mptr[7]=" DEF Les fichiers de d‚finition de bibliothŠque seront inclus avant ";
			mptr[8]="la g‚n‚ration de  leur d‚claration d'emballage (packaging).  ";
			mptr[9]=" CLS Les fichiers ayant cette extension seront inclus avant la g‚n‚ration ";
			mptr[10]="d'emballage (packaging) d'overlays ou de modules de programmes.  ";
			mptr[11]=" DCL  Les fichiers ayant cette extension seront inclus aprŠs la production ";
			mptr[12]="de la section des donn‚es du modŠle.  ";
			mptr[13]=" EXT Les fichiers ayant cette extension seront inclus avant la g‚n‚ration ";
			mptr[14]="des proc‚dures internes.  ";
			mptr[15]=" OTHER  Tous les fichiers avec d'autres extensions seront inclus  avant ";
			mptr[16]="la g‚n‚ration des d‚clarations des proc‚dures externes et forward.    ";
			return(visual_online_help(mptr,17));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Dependance_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows the list of include files to be specified as ";
			mptr[1]="a space  or comma separated list of file names.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Ce champ permet de pr‚ciser la liste des noms de fichiers inclus s‚par‚s ";
			mptr[1]="par des espaces ou des virgules.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Modules_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[7];
			mptr[0] = "This page allows the list of modules to which the program or overlay ";
			mptr[1]="is to be linked to be specified. Modules for which a corresponding ";
			mptr[2]="visual model file is detected will give rise to the generation of ";
			mptr[3]="the corresponding external description inclusion.  ";
			mptr[4]=" ";
			mptr[5]="Models for which modules are declared will be scheduled for the secondary ";
			mptr[6]="production module linkage  phase.   ";
			return(visual_online_help(mptr,7));
			}
			break;
		case 1 : 
			{
			char * mptr[7];
			mptr[0] = "Cette page permet de pr‚ciser la liste des modules auquels un programme ";
			mptr[1]="ou un overlay doit ˆtre li‚. Les modules pour lesquels un fichier ";
			mptr[2]="de modŠle visuel est d‚tect‚, provoqueront la g‚n‚ration  de l'inclusion ";
			mptr[3]="de la description externe correspondante.  ";
			mptr[4]=" ";
			mptr[5]="Les modŠles pour lesquels des modules sont d‚clar‚s seront programm‚s ";
			mptr[6]="pour la phase de  linkage de modules de  production secondaire.  ";
			return(visual_online_help(mptr,7));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Linkage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allow specification of a space or comma separated ";
			mptr[1]="list of abal module filenames including their extension.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Ce champ permet de pr‚ciser une liste de noms de fichiers de modules ";
			mptr[1]="abal, avec leurs extensions,  s‚par‚s par  des espaces ou des virgules. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PragmaPage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This page provides a collection of translation pragmas and definitions ";
			mptr[1]=" allowing fine control over the production and runtime context.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Cette page fournit un ensemble de d‚finitions et de pragmas de traduction ";
			mptr[1]="permettant  un contr“le fin sur le contexte de production et d'ex‚cution. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int UseDiezeMem_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control may be checked to permit generation of the corresponding ";
			mptr[1]="#MEM statement.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Ce contr“le peut ˆtre coch‚ pour permettre la g‚n‚ration de la d‚claration ";
			mptr[1]="#MEM correspondante.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int UseDiezeStack_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control may be checked to allow generation of the corresponding ";
			mptr[1]="#STACK statement.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Ce contr“le peut ˆtre coch‚ pour permettre la g‚n‚ration de la d‚claration ";
			mptr[1]="#STACK correspondante.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int UseDiezeFiles_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control may be check to allow generation of the corresponding ";
			mptr[1]="#FILES statement.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Ce contr“le peut ˆtre coch‚ pour permettre la g‚n‚ration de la d‚claration ";
			mptr[1]="#FILES correspondante.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int UseDiezeHeap_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control may be checked to allow generation of the corresponding ";
			mptr[1]="#HEAP statement.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Ce contr“le peut ˆtre coch‚ pour permettre la g‚n‚ration de la d‚claration ";
			mptr[1]="#HEAP correspondante.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DiezeMem_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[7];
			mptr[0] = "This edit field provides the value to be used for the #MEM statement ";
			mptr[1]="which determines the amount or temporary storage memory to be preallocated ";
			mptr[2]="by the ABAL RunTime for use in calculations and  procedure nesting. ";
			mptr[3]="  ";
			mptr[4]=" ";
			mptr[5]="It should be at least twice as large as the largest temporary string ";
			mptr[6]="operation.    ";
			return(visual_online_help(mptr,7));
			}
			break;
		case 1 : 
			{
			char * mptr[7];
			mptr[0] = "Ce champ fournit la valeur … utiliser pour la d‚claration de #MEM ";
			mptr[1]="d‚terminant la quantit‚  de m‚moire de stockage temporaraire … pr‚allouer ";
			mptr[2]="par l'‚x‚cuteur ABAL pour l'utilisation dans les calculs et  l'imbrication ";
			mptr[3]="de proc‚dures.  ";
			mptr[4]=" ";
			mptr[5]="Elle devra ˆtre au moins deux fois plus grande que la plus grande ";
			mptr[6]="op‚ration chaŒne temporaire.  ";
			return(visual_online_help(mptr,7));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DiezeStack_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field provides the value to be used for the #STACK statement ";
			mptr[1]="which determines the  depth of gosub,segment and procedure nesting. ";
			mptr[2]="As a general rule segments and gosubs use one entry eacj whilst procedures ";
			mptr[3]="may require between 12 and 16 items depending on the nature of the ";
			mptr[4]="call.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Ce champ fournit la valeur … utiliser pour la d‚claration de #STACK ";
			mptr[1]="d‚terminant la profondeur de l'imbrication de proc‚dures, segment ";
			mptr[2]="et gosub. En rŠgle g‚n‚rale, les segments et gosub utilisent une entr‚e ";
			mptr[3]=" chacun alors que les proc‚dures peuvent n‚cessiter entre 12 et 16 ";
			mptr[4]="items, en fonction de la nature de l'appel.    ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DiezeFiles_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field provides the value to be used for the #FILES statement ";
			mptr[1]="which determines the total number of files that may be assigned at ";
			mptr[2]="any one time by the ABAL runtime. The number of files which may actually ";
			mptr[3]="be opened is not controlled by this value being rather a function ";
			mptr[4]="of the host operating system.     ";
			return(visual_online_help(mptr,5));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Ce champ fournit la valeur … utiliser pour la d‚claration de #FILES ";
			mptr[1]="d‚terminant le nombre de fichiers qui peuvent ˆtre assign‚s au mˆme ";
			mptr[2]="moment par l'ex‚cuteur ABAL. Le nombre de fichers pouvant  actuellement ";
			mptr[3]="ˆtre ouverts simultan‚ment n'est pas contr“l‚ par cette valeur mais ";
			mptr[4]="par une fonction du systŠme h“te.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DiezeHeap_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field provides the value to be used for the #HEAP statement. ";
			mptr[1]="This construction is of little use in modern operating system environments ";
			mptr[2]="but may improve performance in memory critical situations. The value ";
			mptr[3]="may be calculated as the total amount of nested local memory.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Ce champ fournit la valeur … utiliser pour la d‚claration de #HEAP. ";
			mptr[1]=" Cette construction est de peu d'utilit‚ dans les environnements systŠmes ";
			mptr[2]="modernes mais peut am‚liorer la performance  dans les situations de ";
			mptr[3]="m‚moire critique. La valeur peut ˆtre calcul‚e comme la taille totale ";
			mptr[4]="de m‚moire locale imbriqu‚e.    ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int UsePragmaFile_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This check control when active allows the inclusion of a file providing ";
			mptr[1]="global pragma values. The inclusion is generated after the aboce pragma ";
			mptr[2]="switchs and may over-ride their effects.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PragmaFileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows a file name to be specified for the preceeding ";
			mptr[1]="check control global pragma inclusion mechanisms.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int RespectCase_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This control may be check forcing the translator to ignore differences ";
			mptr[1]="in case when translating  variabel, constant and procedure names. ";
			mptr[2]="When this control is unchecked then names of different case will refer ";
			mptr[3]="to different objects.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[5];
			mptr[0] = "Ce contr“le peut ˆtre coch‚ pour forcer le traducteur … ignorer les ";
			mptr[1]="diff‚rences de casses dans les noms de proc‚dures, constantes et variables ";
			mptr[2]="lors des traductions. Quand cet contr“le n'est pas coch‚, les noms ";
			mptr[3]="similaires de casses diff‚rentes se rapportent … des  objets distincts. ";
			mptr[4]="  ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int OptimiseTables_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control when checked signals that the translator is to perform ";
			mptr[1]="variable table optimisation for the elimination of unused variable ";
			mptr[2]="identifiers. This option is not to be used for modules.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[4];
			mptr[0] = "Ce contr“le, quand il est coch‚, signale que le traducteur ex‚cutera ";
			mptr[1]="une optimisation de la table des variables afin d'‚liminer les identifiants ";
			mptr[2]="des variables non utilis‚es. Cette option n'est pas utilis‚e pour ";
			mptr[3]="les modules.  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int UseTokenSize_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control may be checked to allow generation of the corresponding ";
			mptr[1]="token size statement.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Ce contr“le peut coch‚ pour permettre la g‚n‚ration de la d‚claration ";
			mptr[1]="de la taille d'identificateur correspondante.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int UseLabelSize_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control may be checked to allow generation of the corresponding ";
			mptr[1]="label size pragma statement.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Ce contr“le peut coch‚ pour permettre la g‚n‚ration de la d‚claration ";
			mptr[1]="de la taille d'identificateur correspondante.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TokenSize_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field provides the value to be used for the token size pragma ";
			mptr[1]="statement. By default tokens are 16 bytes long. They may be increased ";
			mptr[2]="or reduced to any reasonable value between 8 and 64 bytes.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[4];
			mptr[0] = "Ce champ fournit la valeur … utiliser pour la d‚claration de pragma ";
			mptr[1]="de taille d'identificateur. Par d‚faut, les identificateurs sont  ";
			mptr[2]="longs de 16 octets. Ils peuvent ˆtre augment‚s ou r‚duits … une valeur ";
			mptr[3]="raisonnable comprise entre 8 et 64 octets.  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int LabelSize_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field provides the value for the label size pragma statement. ";
			mptr[1]="As for the token size pragma this may take any reasonable value between ";
			mptr[2]="8 and 64 bytes.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Ce champ fournit la valeur pour la d‚claration de pragma de taille ";
			mptr[1]="d'‚tiquette. Comme pour le pragma de taille   d'identificateur, elle ";
			mptr[2]="peut prendre une valeur entre 8 et 64 octets.  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
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

		visual_thaw(_Context->x_auto2,_Context->y_auto2,620,470);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_choixFileName_event(struct accept_abal_production_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_AS);
		accept_abal_production_show(_Context);
;
	return(-1);
}
private int on_Auto2633_event(struct accept_abal_production_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto2634_event(struct accept_abal_production_context * _Context) {
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
	link_abal(_Context->buffer_FileName,_Context->buffer_Linkage,_Context->value_IsAutoTrad,0);
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
private int on_choixPragmaFileName_event(struct accept_abal_production_context * _Context) {
	use_file_selector(_Context->buffer_PragmaFileName,WIDGET_FILE_AS);
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
		if (_Context->trigger_choixFileName == mb ) return(5);
		if (_Context->trigger_IsAutoTrad == mb ) return(10);
		if (_Context->trigger_IsTrueColour == mb ) return(11);
		if (_Context->trigger_ExactDimensions == mb ) return(12);
		if (_Context->trigger_Auto2633 == mb ) return(13);
		if (_Context->trigger_Auto2634 == mb ) return(14);
		if (_Context->trigger_UseAtr == mb ) return(17);
		if (_Context->trigger_Link == mb ) return(18);
		if (_Context->trigger_UseEdit == mb ) return(19);
		if (_Context->trigger_Select == mb ) return(20);
		if (_Context->trigger_Inclusion == mb ) return(21);
		if (_Context->trigger_Modules == mb ) return(23);
		if (_Context->trigger_PragmaPage == mb ) return(25);
		if (_Context->trigger_UseDiezeMem == mb ) return(26);
		if (_Context->trigger_UseDiezeStack == mb ) return(27);
		if (_Context->trigger_UseDiezeFiles == mb ) return(28);
		if (_Context->trigger_UseDiezeHeap == mb ) return(29);
		if (_Context->trigger_UsePragmaFile == mb ) return(34);
		if (_Context->trigger_choixPragmaFileName == mb ) return(36);
		if (_Context->trigger_RespectCase == mb ) return(37);
		if (_Context->trigger_OptimiseTables == mb ) return(38);
		if (_Context->trigger_UseTokenSize == mb ) return(39);
		if (_Context->trigger_UseLabelSize == mb ) return(40);
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
		&&  ( my >= (_Context->y_auto2+130) ) 
		&&  ( mx <= (_Context->x_auto2+40+511) ) 
		&&  ( my <= (_Context->y_auto2+130+16))) {
			return(4); /* FileName */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+556) ) 
		&&  ( my >= (_Context->y_auto2+130) ) 
		&&  ( mx <= (_Context->x_auto2+556+20) ) 
		&&  ( my <= (_Context->y_auto2+130+18))) {
			return(5); /* choixFileName */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+40+0) ) 
		&&  ( my >= (_Context->y_auto2+150) ) 
		&&  ( mx <= (_Context->x_auto2+40+536) ) 
		&&  ( my <= (_Context->y_auto2+150+16))) {
			return(6); /* FilePath */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+40) ) 
		&&  ( my >= (_Context->y_auto2+210) ) 
		&&  ( mx <= (_Context->x_auto2+40+536) ) 
		&&  ( my <= (_Context->y_auto2+210+16))) {
			return(8); /* Identity */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+50+0) ) 
		&&  ( my >= (_Context->y_auto2+270) ) 
		&&  ( mx <= (_Context->x_auto2+50+141) ) 
		&&  ( my <= (_Context->y_auto2+270+16))) {
			return(9); /* Packaging */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+210) ) 
		&&  ( my >= (_Context->y_auto2+270) ) 
		&&  ( mx <= (_Context->x_auto2+210+154) ) 
		&&  ( my <= (_Context->y_auto2+270+16))) {
			return(10); /* IsAutoTrad */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+210) ) 
		&&  ( my >= (_Context->y_auto2+290) ) 
		&&  ( mx <= (_Context->x_auto2+210+154) ) 
		&&  ( my <= (_Context->y_auto2+290+16))) {
			return(11); /* IsTrueColour */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+210) ) 
		&&  ( my >= (_Context->y_auto2+310) ) 
		&&  ( mx <= (_Context->x_auto2+210+168) ) 
		&&  ( my <= (_Context->y_auto2+310+16))) {
			return(12); /* ExactDimensions */
			}
		}
	if (( mx >= (_Context->x_auto2+20) ) 
	&&  ( my >= (_Context->y_auto2+410) ) 
	&&  ( mx <= (_Context->x_auto2+20+56) ) 
	&&  ( my <= (_Context->y_auto2+410+48))) {
		return(13); /* Auto2633 */
		}
	if (( mx >= (_Context->x_auto2+540) ) 
	&&  ( my >= (_Context->y_auto2+410) ) 
	&&  ( mx <= (_Context->x_auto2+540+56) ) 
	&&  ( my <= (_Context->y_auto2+410+48))) {
		return(14); /* Auto2634 */
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+430+0) ) 
		&&  ( my >= (_Context->y_auto2+270) ) 
		&&  ( mx <= (_Context->x_auto2+430+140) ) 
		&&  ( my <= (_Context->y_auto2+270+16))) {
			return(16); /* Dimensions */
			}
		}
	if (( mx >= (_Context->x_auto2+210) ) 
	&&  ( my >= (_Context->y_auto2+420) ) 
	&&  ( mx <= (_Context->x_auto2+210+90) ) 
	&&  ( my <= (_Context->y_auto2+420+30))) {
		return(17); /* UseAtr */
		}
	if (( mx >= (_Context->x_auto2+310) ) 
	&&  ( my >= (_Context->y_auto2+420) ) 
	&&  ( mx <= (_Context->x_auto2+310+90) ) 
	&&  ( my <= (_Context->y_auto2+420+30))) {
		return(18); /* Link */
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+210) ) 
		&&  ( my >= (_Context->y_auto2+360) ) 
		&&  ( mx <= (_Context->x_auto2+210+90) ) 
		&&  ( my <= (_Context->y_auto2+360+30))) {
			return(19); /* UseEdit */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_auto2+310) ) 
		&&  ( my >= (_Context->y_auto2+360) ) 
		&&  ( mx <= (_Context->x_auto2+310+90) ) 
		&&  ( my <= (_Context->y_auto2+360+30))) {
			return(20); /* Select */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_auto2+20+104) ) 
		&&  ( my >= (_Context->y_auto2+70) ) 
		&&  ( mx <= (_Context->x_auto2+20+192) ) 
		&&  ( my <= (_Context->y_auto2+70+24))) {
			return(21); /* Inclusion */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_auto2+30) ) 
		&&  ( my >= (_Context->y_auto2+110) ) 
		&&  ( mx <= (_Context->x_auto2+30+552) ) 
		&&  ( my <= (_Context->y_auto2+110+272))) {
			return(22); /* Dependance */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_auto2+20+193) ) 
		&&  ( my >= (_Context->y_auto2+70) ) 
		&&  ( mx <= (_Context->x_auto2+20+279) ) 
		&&  ( my <= (_Context->y_auto2+70+24))) {
			return(23); /* Modules */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_auto2+30) ) 
		&&  ( my >= (_Context->y_auto2+110) ) 
		&&  ( mx <= (_Context->x_auto2+30+552) ) 
		&&  ( my <= (_Context->y_auto2+110+272))) {
			return(24); /* Linkage */
			}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if (( mx >= (_Context->x_auto2+20+280) ) 
		&&  ( my >= (_Context->y_auto2+70) ) 
		&&  ( mx <= (_Context->x_auto2+20+370) ) 
		&&  ( my <= (_Context->y_auto2+70+24))) {
			return(25); /* PragmaPage */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+80) ) 
		&&  ( my >= (_Context->y_auto2+150) ) 
		&&  ( mx <= (_Context->x_auto2+80+98) ) 
		&&  ( my <= (_Context->y_auto2+150+16))) {
			return(26); /* UseDiezeMem */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+80) ) 
		&&  ( my >= (_Context->y_auto2+190) ) 
		&&  ( mx <= (_Context->x_auto2+80+98) ) 
		&&  ( my <= (_Context->y_auto2+190+16))) {
			return(27); /* UseDiezeStack */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+80) ) 
		&&  ( my >= (_Context->y_auto2+230) ) 
		&&  ( mx <= (_Context->x_auto2+80+98) ) 
		&&  ( my <= (_Context->y_auto2+230+16))) {
			return(28); /* UseDiezeFiles */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+80) ) 
		&&  ( my >= (_Context->y_auto2+270) ) 
		&&  ( mx <= (_Context->x_auto2+80+98) ) 
		&&  ( my <= (_Context->y_auto2+270+16))) {
			return(29); /* UseDiezeHeap */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+180) ) 
		&&  ( my >= (_Context->y_auto2+150) ) 
		&&  ( mx <= (_Context->x_auto2+180+80) ) 
		&&  ( my <= (_Context->y_auto2+150+16))) {
			return(30); /* DiezeMem */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+180) ) 
		&&  ( my >= (_Context->y_auto2+190) ) 
		&&  ( mx <= (_Context->x_auto2+180+80) ) 
		&&  ( my <= (_Context->y_auto2+190+16))) {
			return(31); /* DiezeStack */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+180) ) 
		&&  ( my >= (_Context->y_auto2+230) ) 
		&&  ( mx <= (_Context->x_auto2+180+80) ) 
		&&  ( my <= (_Context->y_auto2+230+16))) {
			return(32); /* DiezeFiles */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+180) ) 
		&&  ( my >= (_Context->y_auto2+270) ) 
		&&  ( mx <= (_Context->x_auto2+180+80) ) 
		&&  ( my <= (_Context->y_auto2+270+16))) {
			return(33); /* DiezeHeap */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+50) ) 
		&&  ( my >= (_Context->y_auto2+340) ) 
		&&  ( mx <= (_Context->x_auto2+50+168) ) 
		&&  ( my <= (_Context->y_auto2+340+16))) {
			return(34); /* UsePragmaFile */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+220) ) 
		&&  ( my >= (_Context->y_auto2+340) ) 
		&&  ( mx <= (_Context->x_auto2+220+326) ) 
		&&  ( my <= (_Context->y_auto2+340+16))) {
			return(35); /* PragmaFileName */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+556) ) 
		&&  ( my >= (_Context->y_auto2+340) ) 
		&&  ( mx <= (_Context->x_auto2+556+20) ) 
		&&  ( my <= (_Context->y_auto2+340+18))) {
			return(36); /* choixPragmaFileName */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+360) ) 
		&&  ( my >= (_Context->y_auto2+150) ) 
		&&  ( mx <= (_Context->x_auto2+360+182) ) 
		&&  ( my <= (_Context->y_auto2+150+16))) {
			return(37); /* RespectCase */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+360) ) 
		&&  ( my >= (_Context->y_auto2+190) ) 
		&&  ( mx <= (_Context->x_auto2+360+182) ) 
		&&  ( my <= (_Context->y_auto2+190+16))) {
			return(38); /* OptimiseTables */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+360) ) 
		&&  ( my >= (_Context->y_auto2+230) ) 
		&&  ( mx <= (_Context->x_auto2+360+112) ) 
		&&  ( my <= (_Context->y_auto2+230+16))) {
			return(39); /* UseTokenSize */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+360) ) 
		&&  ( my >= (_Context->y_auto2+270) ) 
		&&  ( mx <= (_Context->x_auto2+360+112) ) 
		&&  ( my <= (_Context->y_auto2+270+16))) {
			return(40); /* UseLabelSize */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+480) ) 
		&&  ( my >= (_Context->y_auto2+230) ) 
		&&  ( mx <= (_Context->x_auto2+480+72) ) 
		&&  ( my <= (_Context->y_auto2+230+16))) {
			return(41); /* TokenSize */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_auto2+480) ) 
		&&  ( my >= (_Context->y_auto2+270) ) 
		&&  ( mx <= (_Context->x_auto2+480+72) ) 
		&&  ( my <= (_Context->y_auto2+270+16))) {
			return(42); /* LabelSize */
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
					_Context->keycode = visual_edit(_Context->x_auto2+40+1,_Context->y_auto2+130+1,511,16,vfh[1],_Context->buffer_FileName,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* choixFileName */
				if (_Context->page_number == 1 ) {
					_Context->trigger_choixFileName=visual_trigger_code(_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]));
					visual_button(_Context->x_auto2+556,_Context->y_auto2+130,20,18,vfh[1],27,28,_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_choixFileName=visual_trigger_code(_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]));
	visual_button(_Context->x_auto2+556,_Context->y_auto2+130,20,18,vfh[1],27,28,_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* FilePath */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_auto2+40,_Context->y_auto2+150,536,16,vfh[1],34,0,parse_selection(GetPathSelection(),&_Context->value_FilePath),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* Identity */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+40+1,_Context->y_auto2+210+1,536,16,vfh[1],_Context->buffer_Identity,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* Packaging */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_auto2+50,_Context->y_auto2+270,141,70,vfh[2],0,0,parse_selection(_Context->msg_Packaging[_Context->language],&_Context->value_Packaging),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* IsAutoTrad */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_auto2+210,_Context->y_auto2+270,154,16,vfh[2],27,0,_Context->msg_IsAutoTrad[_Context->language],strlen(_Context->msg_IsAutoTrad[_Context->language]),(_Context->value_IsAutoTrad |2));
					_Context->keycode = visual_getch();
					_Context->trigger_IsAutoTrad=visual_trigger_code(_Context->msg_IsAutoTrad[_Context->language],strlen(_Context->msg_IsAutoTrad[_Context->language]));
	visual_check(_Context->x_auto2+210,_Context->y_auto2+270,154,16,vfh[2],27,0,_Context->msg_IsAutoTrad[_Context->language],strlen(_Context->msg_IsAutoTrad[_Context->language]),_Context->value_IsAutoTrad|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* IsTrueColour */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_auto2+210,_Context->y_auto2+290,154,16,vfh[2],27,0,_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]),(_Context->value_IsTrueColour |2));
					_Context->keycode = visual_getch();
					_Context->trigger_IsTrueColour=visual_trigger_code(_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]));
	visual_check(_Context->x_auto2+210,_Context->y_auto2+290,154,16,vfh[2],27,0,_Context->msg_IsTrueColour[_Context->language],strlen(_Context->msg_IsTrueColour[_Context->language]),_Context->value_IsTrueColour|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* ExactDimensions */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_auto2+210,_Context->y_auto2+310,168,16,vfh[2],27,0,_Context->msg_ExactDimensions[_Context->language],strlen(_Context->msg_ExactDimensions[_Context->language]),(_Context->value_ExactDimensions |2));
					_Context->keycode = visual_getch();
					_Context->trigger_ExactDimensions=visual_trigger_code(_Context->msg_ExactDimensions[_Context->language],strlen(_Context->msg_ExactDimensions[_Context->language]));
	visual_check(_Context->x_auto2+210,_Context->y_auto2+310,168,16,vfh[2],27,0,_Context->msg_ExactDimensions[_Context->language],strlen(_Context->msg_ExactDimensions[_Context->language]),_Context->value_ExactDimensions|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* Auto2633 */
				_Context->trigger_Auto2633=visual_trigger_code(_Context->msg_Auto2633[_Context->language],strlen(_Context->msg_Auto2633[_Context->language]));
				visual_button(_Context->x_auto2+20,_Context->y_auto2+410,56,48,vfh[2],34,0,_Context->msg_Auto2633[_Context->language],strlen(_Context->msg_Auto2633[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2633=visual_trigger_code(_Context->msg_Auto2633[_Context->language],strlen(_Context->msg_Auto2633[_Context->language]));
	visual_button(_Context->x_auto2+20,_Context->y_auto2+410,56,48,vfh[2],34,0,_Context->msg_Auto2633[_Context->language],strlen(_Context->msg_Auto2633[_Context->language]),1040);
				break;
			case	0xe :
				/* Auto2634 */
				_Context->trigger_Auto2634=visual_trigger_code(_Context->msg_Auto2634[_Context->language],strlen(_Context->msg_Auto2634[_Context->language]));
				visual_button(_Context->x_auto2+540,_Context->y_auto2+410,56,48,vfh[2],34,0,_Context->msg_Auto2634[_Context->language],strlen(_Context->msg_Auto2634[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto2634=visual_trigger_code(_Context->msg_Auto2634[_Context->language],strlen(_Context->msg_Auto2634[_Context->language]));
	visual_button(_Context->x_auto2+540,_Context->y_auto2+410,56,48,vfh[2],34,0,_Context->msg_Auto2634[_Context->language],strlen(_Context->msg_Auto2634[_Context->language]),1040);
				break;
			case	0x10 :
				/* Dimensions */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_auto2+430,_Context->y_auto2+270,140,100,vfh[2],0,0,parse_selection(_Context->msg_Dimensions[_Context->language],&_Context->value_Dimensions),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* UseAtr */
				_Context->trigger_UseAtr=visual_trigger_code(_Context->msg_UseAtr[_Context->language],strlen(_Context->msg_UseAtr[_Context->language]));
				visual_button(_Context->x_auto2+210,_Context->y_auto2+420,90,30,vfh[2],26,0,_Context->msg_UseAtr[_Context->language],strlen(_Context->msg_UseAtr[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_UseAtr=visual_trigger_code(_Context->msg_UseAtr[_Context->language],strlen(_Context->msg_UseAtr[_Context->language]));
	visual_button(_Context->x_auto2+210,_Context->y_auto2+420,90,30,vfh[2],26,0,_Context->msg_UseAtr[_Context->language],strlen(_Context->msg_UseAtr[_Context->language]),0);
				break;
			case	0x12 :
				/* Link */
				_Context->trigger_Link=visual_trigger_code(_Context->msg_Link[_Context->language],strlen(_Context->msg_Link[_Context->language]));
				visual_button(_Context->x_auto2+310,_Context->y_auto2+420,90,30,vfh[2],16,28,_Context->msg_Link[_Context->language],strlen(_Context->msg_Link[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_Link=visual_trigger_code(_Context->msg_Link[_Context->language],strlen(_Context->msg_Link[_Context->language]));
	visual_button(_Context->x_auto2+310,_Context->y_auto2+420,90,30,vfh[2],16,28,_Context->msg_Link[_Context->language],strlen(_Context->msg_Link[_Context->language]),0);
				break;
			case	0x13 :
				/* UseEdit */
				if (_Context->page_number == 1 ) {
					_Context->trigger_UseEdit=visual_trigger_code(_Context->msg_UseEdit[_Context->language],strlen(_Context->msg_UseEdit[_Context->language]));
					visual_button(_Context->x_auto2+210,_Context->y_auto2+360,90,30,vfh[2],26,0,_Context->msg_UseEdit[_Context->language],strlen(_Context->msg_UseEdit[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_UseEdit=visual_trigger_code(_Context->msg_UseEdit[_Context->language],strlen(_Context->msg_UseEdit[_Context->language]));
	visual_button(_Context->x_auto2+210,_Context->y_auto2+360,90,30,vfh[2],26,0,_Context->msg_UseEdit[_Context->language],strlen(_Context->msg_UseEdit[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* Select */
				if (_Context->page_number == 1 ) {
					_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
					visual_button(_Context->x_auto2+310,_Context->y_auto2+360,90,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto2+310,_Context->y_auto2+360,90,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x15 :
				/* Inclusion */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x16 :
				/* Dependance */
				if (_Context->page_number == 2 ) {
					if ((_Context->keycode = on_Dependance_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x17 :
				/* Modules */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x18 :
				/* Linkage */
				if (_Context->page_number == 3 ) {
					if ((_Context->keycode = on_Linkage_getfocus(_Context)) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* PragmaPage */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x1a :
				/* UseDiezeMem */
				if (_Context->page_number == 4 ) {
				visual_check(_Context->x_auto2+80,_Context->y_auto2+150,98,16,vfh[2],28,28,_Context->msg_UseDiezeMem[_Context->language],strlen(_Context->msg_UseDiezeMem[_Context->language]),(_Context->value_UseDiezeMem |2));
					_Context->keycode = visual_getch();
					_Context->trigger_UseDiezeMem=visual_trigger_code(_Context->msg_UseDiezeMem[_Context->language],strlen(_Context->msg_UseDiezeMem[_Context->language]));
	visual_check(_Context->x_auto2+80,_Context->y_auto2+150,98,16,vfh[2],28,28,_Context->msg_UseDiezeMem[_Context->language],strlen(_Context->msg_UseDiezeMem[_Context->language]),_Context->value_UseDiezeMem|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* UseDiezeStack */
				if (_Context->page_number == 4 ) {
				visual_check(_Context->x_auto2+80,_Context->y_auto2+190,98,16,vfh[2],28,28,_Context->msg_UseDiezeStack[_Context->language],strlen(_Context->msg_UseDiezeStack[_Context->language]),(_Context->value_UseDiezeStack |2));
					_Context->keycode = visual_getch();
					_Context->trigger_UseDiezeStack=visual_trigger_code(_Context->msg_UseDiezeStack[_Context->language],strlen(_Context->msg_UseDiezeStack[_Context->language]));
	visual_check(_Context->x_auto2+80,_Context->y_auto2+190,98,16,vfh[2],28,28,_Context->msg_UseDiezeStack[_Context->language],strlen(_Context->msg_UseDiezeStack[_Context->language]),_Context->value_UseDiezeStack|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1c :
				/* UseDiezeFiles */
				if (_Context->page_number == 4 ) {
				visual_check(_Context->x_auto2+80,_Context->y_auto2+230,98,16,vfh[2],28,28,_Context->msg_UseDiezeFiles[_Context->language],strlen(_Context->msg_UseDiezeFiles[_Context->language]),(_Context->value_UseDiezeFiles |2));
					_Context->keycode = visual_getch();
					_Context->trigger_UseDiezeFiles=visual_trigger_code(_Context->msg_UseDiezeFiles[_Context->language],strlen(_Context->msg_UseDiezeFiles[_Context->language]));
	visual_check(_Context->x_auto2+80,_Context->y_auto2+230,98,16,vfh[2],28,28,_Context->msg_UseDiezeFiles[_Context->language],strlen(_Context->msg_UseDiezeFiles[_Context->language]),_Context->value_UseDiezeFiles|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1d :
				/* UseDiezeHeap */
				if (_Context->page_number == 4 ) {
				visual_check(_Context->x_auto2+80,_Context->y_auto2+270,98,16,vfh[2],28,28,_Context->msg_UseDiezeHeap[_Context->language],strlen(_Context->msg_UseDiezeHeap[_Context->language]),(_Context->value_UseDiezeHeap |2));
					_Context->keycode = visual_getch();
					_Context->trigger_UseDiezeHeap=visual_trigger_code(_Context->msg_UseDiezeHeap[_Context->language],strlen(_Context->msg_UseDiezeHeap[_Context->language]));
	visual_check(_Context->x_auto2+80,_Context->y_auto2+270,98,16,vfh[2],28,28,_Context->msg_UseDiezeHeap[_Context->language],strlen(_Context->msg_UseDiezeHeap[_Context->language]),_Context->value_UseDiezeHeap|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* DiezeMem */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+180+1,_Context->y_auto2+150+1,80,16,vfh[1],_Context->buffer_DiezeMem,10);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1f :
				/* DiezeStack */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+180+1,_Context->y_auto2+190+1,80,16,vfh[1],_Context->buffer_DiezeStack,10);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x20 :
				/* DiezeFiles */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+180+1,_Context->y_auto2+230+1,80,16,vfh[1],_Context->buffer_DiezeFiles,10);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x21 :
				/* DiezeHeap */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+180+1,_Context->y_auto2+270+1,80,16,vfh[1],_Context->buffer_DiezeHeap,10);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x22 :
				/* UsePragmaFile */
				if (_Context->page_number == 4 ) {
				visual_check(_Context->x_auto2+50,_Context->y_auto2+340,168,16,vfh[2],27,28,_Context->msg_UsePragmaFile[_Context->language],strlen(_Context->msg_UsePragmaFile[_Context->language]),(_Context->value_UsePragmaFile |2));
					_Context->keycode = visual_getch();
					_Context->trigger_UsePragmaFile=visual_trigger_code(_Context->msg_UsePragmaFile[_Context->language],strlen(_Context->msg_UsePragmaFile[_Context->language]));
	visual_check(_Context->x_auto2+50,_Context->y_auto2+340,168,16,vfh[2],27,28,_Context->msg_UsePragmaFile[_Context->language],strlen(_Context->msg_UsePragmaFile[_Context->language]),_Context->value_UsePragmaFile|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x23 :
				/* PragmaFileName */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+220+1,_Context->y_auto2+340+1,326,16,vfh[1],_Context->buffer_PragmaFileName,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x24 :
				/* choixPragmaFileName */
				if (_Context->page_number == 4 ) {
					_Context->trigger_choixPragmaFileName=visual_trigger_code(_Context->msg_choixPragmaFileName[_Context->language],strlen(_Context->msg_choixPragmaFileName[_Context->language]));
					visual_button(_Context->x_auto2+556,_Context->y_auto2+340,20,18,vfh[1],27,28,_Context->msg_choixPragmaFileName[_Context->language],strlen(_Context->msg_choixPragmaFileName[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_choixPragmaFileName=visual_trigger_code(_Context->msg_choixPragmaFileName[_Context->language],strlen(_Context->msg_choixPragmaFileName[_Context->language]));
	visual_button(_Context->x_auto2+556,_Context->y_auto2+340,20,18,vfh[1],27,28,_Context->msg_choixPragmaFileName[_Context->language],strlen(_Context->msg_choixPragmaFileName[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x25 :
				/* RespectCase */
				if (_Context->page_number == 4 ) {
				visual_check(_Context->x_auto2+360,_Context->y_auto2+150,182,16,vfh[2],28,28,_Context->msg_RespectCase[_Context->language],strlen(_Context->msg_RespectCase[_Context->language]),(_Context->value_RespectCase |2));
					_Context->keycode = visual_getch();
					_Context->trigger_RespectCase=visual_trigger_code(_Context->msg_RespectCase[_Context->language],strlen(_Context->msg_RespectCase[_Context->language]));
	visual_check(_Context->x_auto2+360,_Context->y_auto2+150,182,16,vfh[2],28,28,_Context->msg_RespectCase[_Context->language],strlen(_Context->msg_RespectCase[_Context->language]),_Context->value_RespectCase|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x26 :
				/* OptimiseTables */
				if (_Context->page_number == 4 ) {
				visual_check(_Context->x_auto2+360,_Context->y_auto2+190,182,16,vfh[2],28,28,_Context->msg_OptimiseTables[_Context->language],strlen(_Context->msg_OptimiseTables[_Context->language]),(_Context->value_OptimiseTables |2));
					_Context->keycode = visual_getch();
					_Context->trigger_OptimiseTables=visual_trigger_code(_Context->msg_OptimiseTables[_Context->language],strlen(_Context->msg_OptimiseTables[_Context->language]));
	visual_check(_Context->x_auto2+360,_Context->y_auto2+190,182,16,vfh[2],28,28,_Context->msg_OptimiseTables[_Context->language],strlen(_Context->msg_OptimiseTables[_Context->language]),_Context->value_OptimiseTables|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x27 :
				/* UseTokenSize */
				if (_Context->page_number == 4 ) {
				visual_check(_Context->x_auto2+360,_Context->y_auto2+230,112,16,vfh[2],28,28,_Context->msg_UseTokenSize[_Context->language],strlen(_Context->msg_UseTokenSize[_Context->language]),(_Context->value_UseTokenSize |2));
					_Context->keycode = visual_getch();
					_Context->trigger_UseTokenSize=visual_trigger_code(_Context->msg_UseTokenSize[_Context->language],strlen(_Context->msg_UseTokenSize[_Context->language]));
	visual_check(_Context->x_auto2+360,_Context->y_auto2+230,112,16,vfh[2],28,28,_Context->msg_UseTokenSize[_Context->language],strlen(_Context->msg_UseTokenSize[_Context->language]),_Context->value_UseTokenSize|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x28 :
				/* UseLabelSize */
				if (_Context->page_number == 4 ) {
				visual_check(_Context->x_auto2+360,_Context->y_auto2+270,112,16,vfh[2],28,28,_Context->msg_UseLabelSize[_Context->language],strlen(_Context->msg_UseLabelSize[_Context->language]),(_Context->value_UseLabelSize |2));
					_Context->keycode = visual_getch();
					_Context->trigger_UseLabelSize=visual_trigger_code(_Context->msg_UseLabelSize[_Context->language],strlen(_Context->msg_UseLabelSize[_Context->language]));
	visual_check(_Context->x_auto2+360,_Context->y_auto2+270,112,16,vfh[2],28,28,_Context->msg_UseLabelSize[_Context->language],strlen(_Context->msg_UseLabelSize[_Context->language]),_Context->value_UseLabelSize|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x29 :
				/* TokenSize */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_auto2+480+1,_Context->y_auto2+230+1,72,16,vfh[1],_Context->buffer_TokenSize,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2a :
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
			_Context->focus_item=42;
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
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (Production_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (FileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (FilePath_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (Identity_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (Packaging_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (IsAutoTrad_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (IsTrueColour_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (ExactDimensions_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (Auto2633_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (Auto2634_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (Auto2635_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (Dimensions_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (UseAtr_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (Link_help(_Context) != 0) { continue; }
						else { break; }
					case	0x13 :
						if (UseEdit_help(_Context) != 0) { continue; }
						else { break; }
					case	0x14 :
						if (Select_help(_Context) != 0) { continue; }
						else { break; }
					case	0x15 :
						if (Inclusion_help(_Context) != 0) { continue; }
						else { break; }
					case	0x16 :
						if (Dependance_help(_Context) != 0) { continue; }
						else { break; }
					case	0x17 :
						if (Modules_help(_Context) != 0) { continue; }
						else { break; }
					case	0x18 :
						if (Linkage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x19 :
						if (PragmaPage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1a :
						if (UseDiezeMem_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1b :
						if (UseDiezeStack_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1c :
						if (UseDiezeFiles_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1d :
						if (UseDiezeHeap_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1e :
						if (DiezeMem_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1f :
						if (DiezeStack_help(_Context) != 0) { continue; }
						else { break; }
					case	0x20 :
						if (DiezeFiles_help(_Context) != 0) { continue; }
						else { break; }
					case	0x21 :
						if (DiezeHeap_help(_Context) != 0) { continue; }
						else { break; }
					case	0x22 :
						if (UsePragmaFile_help(_Context) != 0) { continue; }
						else { break; }
					case	0x23 :
						if (PragmaFileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x25 :
						if (RespectCase_help(_Context) != 0) { continue; }
						else { break; }
					case	0x26 :
						if (OptimiseTables_help(_Context) != 0) { continue; }
						else { break; }
					case	0x27 :
						if (UseTokenSize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x28 :
						if (UseLabelSize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x29 :
						if (TokenSize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2a :
						if (LabelSize_help(_Context) != 0) { continue; }
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
				case	0x5 :
					/* choixFileName */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_choixFileName=visual_trigger_code(_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]));
						visual_button(_Context->x_auto2+556,_Context->y_auto2+130,20,18,vfh[1],27,28,_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_choixFileName=visual_trigger_code(_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]));
	visual_button(_Context->x_auto2+556,_Context->y_auto2+130,20,18,vfh[1],27,28,_Context->msg_choixFileName[_Context->language],strlen(_Context->msg_choixFileName[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_choixFileName_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* FilePath */
					continue;
				case	0x8 :
					/* Identity */
					continue;
				case	0x9 :
					/* Packaging */
					continue;
				case	0xa :
					/* IsAutoTrad */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsAutoTrad += 1;
						_Context->value_IsAutoTrad &= 1;
						}
					continue;
				case	0xb :
					/* IsTrueColour */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_IsTrueColour += 1;
						_Context->value_IsTrueColour &= 1;
						}
					continue;
				case	0xc :
					/* ExactDimensions */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ExactDimensions += 1;
						_Context->value_ExactDimensions &= 1;
						}
					continue;
				case	0xd :
					/* Auto2633 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2633=visual_trigger_code(_Context->msg_Auto2633[_Context->language],strlen(_Context->msg_Auto2633[_Context->language]));
						visual_button(_Context->x_auto2+20,_Context->y_auto2+410,56,48,vfh[2],34,0,_Context->msg_Auto2633[_Context->language],strlen(_Context->msg_Auto2633[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2633=visual_trigger_code(_Context->msg_Auto2633[_Context->language],strlen(_Context->msg_Auto2633[_Context->language]));
	visual_button(_Context->x_auto2+20,_Context->y_auto2+410,56,48,vfh[2],34,0,_Context->msg_Auto2633[_Context->language],strlen(_Context->msg_Auto2633[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2633_event(_Context)) != -1) break;

						}
					continue;
				case	0xe :
					/* Auto2634 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto2634=visual_trigger_code(_Context->msg_Auto2634[_Context->language],strlen(_Context->msg_Auto2634[_Context->language]));
						visual_button(_Context->x_auto2+540,_Context->y_auto2+410,56,48,vfh[2],34,0,_Context->msg_Auto2634[_Context->language],strlen(_Context->msg_Auto2634[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto2634=visual_trigger_code(_Context->msg_Auto2634[_Context->language],strlen(_Context->msg_Auto2634[_Context->language]));
	visual_button(_Context->x_auto2+540,_Context->y_auto2+410,56,48,vfh[2],34,0,_Context->msg_Auto2634[_Context->language],strlen(_Context->msg_Auto2634[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto2634_event(_Context)) != -1) break;

						}
					continue;
				case	0x10 :
					/* Dimensions */
					continue;
				case	0x11 :
					/* UseAtr */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_UseAtr=visual_trigger_code(_Context->msg_UseAtr[_Context->language],strlen(_Context->msg_UseAtr[_Context->language]));
						visual_button(_Context->x_auto2+210,_Context->y_auto2+420,90,30,vfh[2],26,0,_Context->msg_UseAtr[_Context->language],strlen(_Context->msg_UseAtr[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_UseAtr=visual_trigger_code(_Context->msg_UseAtr[_Context->language],strlen(_Context->msg_UseAtr[_Context->language]));
	visual_button(_Context->x_auto2+210,_Context->y_auto2+420,90,30,vfh[2],26,0,_Context->msg_UseAtr[_Context->language],strlen(_Context->msg_UseAtr[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_UseAtr_event(_Context)) != -1) break;

						}
					continue;
				case	0x12 :
					/* Link */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Link=visual_trigger_code(_Context->msg_Link[_Context->language],strlen(_Context->msg_Link[_Context->language]));
						visual_button(_Context->x_auto2+310,_Context->y_auto2+420,90,30,vfh[2],16,28,_Context->msg_Link[_Context->language],strlen(_Context->msg_Link[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Link=visual_trigger_code(_Context->msg_Link[_Context->language],strlen(_Context->msg_Link[_Context->language]));
	visual_button(_Context->x_auto2+310,_Context->y_auto2+420,90,30,vfh[2],16,28,_Context->msg_Link[_Context->language],strlen(_Context->msg_Link[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Link_event(_Context)) != -1) break;

						}
					continue;
				case	0x13 :
					/* UseEdit */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_UseEdit=visual_trigger_code(_Context->msg_UseEdit[_Context->language],strlen(_Context->msg_UseEdit[_Context->language]));
						visual_button(_Context->x_auto2+210,_Context->y_auto2+360,90,30,vfh[2],26,0,_Context->msg_UseEdit[_Context->language],strlen(_Context->msg_UseEdit[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_UseEdit=visual_trigger_code(_Context->msg_UseEdit[_Context->language],strlen(_Context->msg_UseEdit[_Context->language]));
	visual_button(_Context->x_auto2+210,_Context->y_auto2+360,90,30,vfh[2],26,0,_Context->msg_UseEdit[_Context->language],strlen(_Context->msg_UseEdit[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_UseEdit_event(_Context)) != -1) break;

						}
					continue;
				case	0x14 :
					/* Select */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
						visual_button(_Context->x_auto2+310,_Context->y_auto2+360,90,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_auto2+310,_Context->y_auto2+360,90,30,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Select_event(_Context)) != -1) break;

						}
					continue;
				case	0x15 :
					/* Inclusion */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_abal_production_losefocus(_Context);
						_Context->page_number = 2;
						accept_abal_production_show(_Context);
						}
					continue;
				case	0x16 :
					/* Dependance */
					continue;
				case	0x17 :
					/* Modules */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_abal_production_losefocus(_Context);
						_Context->page_number = 3;
						accept_abal_production_show(_Context);
						}
					continue;
				case	0x18 :
					/* Linkage */
					continue;
				case	0x19 :
					/* PragmaPage */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_abal_production_losefocus(_Context);
						_Context->page_number = 4;
						accept_abal_production_show(_Context);
						}
					continue;
				case	0x1a :
					/* UseDiezeMem */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_UseDiezeMem += 1;
						_Context->value_UseDiezeMem &= 1;
						}
					continue;
				case	0x1b :
					/* UseDiezeStack */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_UseDiezeStack += 1;
						_Context->value_UseDiezeStack &= 1;
						}
					continue;
				case	0x1c :
					/* UseDiezeFiles */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_UseDiezeFiles += 1;
						_Context->value_UseDiezeFiles &= 1;
						}
					continue;
				case	0x1d :
					/* UseDiezeHeap */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_UseDiezeHeap += 1;
						_Context->value_UseDiezeHeap &= 1;
						}
					continue;
				case	0x1e :
					/* DiezeMem */
					continue;
				case	0x1f :
					/* DiezeStack */
					continue;
				case	0x20 :
					/* DiezeFiles */
					continue;
				case	0x21 :
					/* DiezeHeap */
					continue;
				case	0x22 :
					/* UsePragmaFile */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_UsePragmaFile += 1;
						_Context->value_UsePragmaFile &= 1;
						}
					continue;
				case	0x23 :
					/* PragmaFileName */
					continue;
				case	0x24 :
					/* choixPragmaFileName */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_choixPragmaFileName=visual_trigger_code(_Context->msg_choixPragmaFileName[_Context->language],strlen(_Context->msg_choixPragmaFileName[_Context->language]));
						visual_button(_Context->x_auto2+556,_Context->y_auto2+340,20,18,vfh[1],27,28,_Context->msg_choixPragmaFileName[_Context->language],strlen(_Context->msg_choixPragmaFileName[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_choixPragmaFileName=visual_trigger_code(_Context->msg_choixPragmaFileName[_Context->language],strlen(_Context->msg_choixPragmaFileName[_Context->language]));
	visual_button(_Context->x_auto2+556,_Context->y_auto2+340,20,18,vfh[1],27,28,_Context->msg_choixPragmaFileName[_Context->language],strlen(_Context->msg_choixPragmaFileName[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_choixPragmaFileName_event(_Context)) != -1) break;

						}
					continue;
				case	0x25 :
					/* RespectCase */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_RespectCase += 1;
						_Context->value_RespectCase &= 1;
						}
					continue;
				case	0x26 :
					/* OptimiseTables */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_OptimiseTables += 1;
						_Context->value_OptimiseTables &= 1;
						}
					continue;
				case	0x27 :
					/* UseTokenSize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_UseTokenSize += 1;
						_Context->value_UseTokenSize &= 1;
						}
					continue;
				case	0x28 :
					/* UseLabelSize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_UseLabelSize += 1;
						_Context->value_UseLabelSize &= 1;
						}
					continue;
				case	0x29 :
					/* TokenSize */
					continue;
				case	0x2a :
					/* LabelSize */
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
				_Context->focus_item=42;
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
	char * pFilePath,
	char * pIdentity,
	char * pPackaging,
	char * pIsAutoTrad,
	char * pIsTrueColour,
	char * pExactDimensions,
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
	 pFilePath,
	 pIdentity,
	 pPackaging,
	 pIsAutoTrad,
	 pIsTrueColour,
	 pExactDimensions,
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
	 pFilePath,
	 pIdentity,
	 pPackaging,
	 pIsAutoTrad,
	 pIsTrueColour,
	 pExactDimensions,
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
