
#ifndef _vaprod_c
#define _vaprod_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.03  */
/* Production     : C  */
/* Project        : vaprod.sng  */
/* Target         : vaprod.c  */
/* Identification : 0.0-1065019113-3524.3523 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"

private struct accept_abal_production_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	focus_pages[4+1];
	int	page_number;
	char	buffer_FileName[68];
	char	buffer_Identity[68];
	int	value_Packaging;
	int	value_IsAutoTrad;
	int	value_Dimensions;
	char * buffer_Dependance;
	char * buffer_Linkage;
	int	value_UseDiezeMem;
	int	value_UseDiezeStack;
	int	value_UseDiezeFiles;
	int	value_UseDiezeHeap;
	char	buffer_DiezeMem[11];
	char	buffer_DiezeStack[11];
	char	buffer_DiezeFiles[11];
	char	buffer_DiezeHeap[11];
	int	value_RespectCase;
	int	value_OptimiseTables;
	int	value_UseTokenSize;
	int	value_UseLabelSize;
	char	buffer_TokenSize[10];
	char	buffer_LabelSize[10];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[22];
	} * _Context;

private	int	accept_abal_production_create(
	char * pFileName,
	char * pIdentity,
	char * pPackaging,
	char * pIsAutoTrad,
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
	char * pRespectCase,
	char * pOptimiseTables,
	char * pUseTokenSize,
	char * pUseLabelSize,
	char * pTokenSize,
	char * pLabelSize)
{

	if (!(_Context = allocate( sizeof( struct accept_abal_production_context ) ) ))
		return(27);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=35;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSWWWTTWWWWWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FileName, 67, pFileName);
		visual_transferin(_Context->buffer_Identity, 67, pIdentity);
		visual_transferin((void *) 0, 0, pPackaging);
		if (!( pPackaging )) _Context->value_Packaging=0;
		else	_Context->value_Packaging = *((int *)pPackaging);
		visual_transferin((void *) 0, 0, pIsAutoTrad);
		if (!( pIsAutoTrad )) _Context->value_IsAutoTrad=0;
		else	_Context->value_IsAutoTrad = *((int *)pIsAutoTrad);
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
	_Context->window_col=0;
	_Context->window_row=0;
	_Context->focus_pages[1]=2;
	_Context->focus_pages[2]=17;
	_Context->focus_pages[3]=19;
	_Context->focus_pages[4]=21;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(90,80,620+10,440+10);
	return(0);
}
private int on_auto2_hide() {
	close_window_editor();
	return(-1);
}

private	int	accept_abal_production_hide()
{
	(void) on_auto2_hide();
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,90,80);
		_Context->ctrlbuffer=0;
		}

	return(0);
}

private	int	accept_abal_production_remove(
	char * pFileName,
	char * pIdentity,
	char * pPackaging,
	char * pIsAutoTrad,
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
	char * pRespectCase,
	char * pOptimiseTables,
	char * pUseTokenSize,
	char * pUseLabelSize,
	char * pTokenSize,
	char * pLabelSize)
{

	int	result=_Context->keycode;
	if (_Context->keycode == 27 ) {
		filetransferdrop(_Context->buffer_Dependance);
		filetransferdrop(_Context->buffer_Linkage);
		
	} else {
		strcpy(_Context->signature,"SSWWWTTWWWWWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FileName, 67, pFileName);
		visual_transferout(_Context->buffer_Identity, 67, pIdentity);
		visual_transferout((void *) 0, 0, pPackaging);
		if ( pPackaging != (char *) 0)
			*((int*)pPackaging) = _Context->value_Packaging;
		visual_transferout((void *) 0, 0, pIsAutoTrad);
		if ( pIsAutoTrad != (char *) 0)
			*((int*)pIsAutoTrad) = _Context->value_IsAutoTrad;
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
private int on_Inclusion_show() {
	open_window_editor(120,190,
	552,240,_Context->buffer_Dependance);
	return(-1);
}
private int on_Dependance_show() {
	show_window_editor();
	return(-1);
}
private int on_Modules_show() {
	open_window_editor(120,190,
	552,240,_Context->buffer_Linkage);
	return(-1);
}
private int on_Linkage_show() {
	show_window_editor();
	return(-1);
}

private	int	accept_abal_production_show()
{
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,90,80);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(90,80,620,440,2,"Sing : Version 1.0a",19,0x403);
	visual_image(95,102,610,413,"skin.gif",4);
	visual_text(100,110,590,30,3,27,0,"ABAL and ABAL++ Source Production",33,515);
	visual_frame(370,380,70,70,1);
	if (_Context->page_number == 1 ) {
	visual_tabpage(110,150,580,300,2,"&Production",11,0,2);
	} else {
		visual_tabpage(110,150,580,300,2,"&Production",11,0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(130,304,540,100,2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(140,310,141,18,2,27,0,"Nature",6,2);
		}
	if (_Context->page_number == 1 ) {
	visual_image(460,330,51,53,"abalicon.gif",3);
		}
	if (_Context->page_number == 1 ) {
	visual_text(130,200,540,20,2,16,0,"Abal++ Production Filename",26,258);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(130,220,540+2,20+2,5);
	visual_text(130+1,220+1,540,20,1,34,0,_Context->buffer_FileName,67,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(130,250,540,20,2,16,0,"Program/Module Identifier",25,258);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(130,270,540+2,20+2,5);
	visual_text(130+1,270+1,540,20,1,34,0,_Context->buffer_Identity,67,0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(140,330,141,70,1,0,0,parse_selection("Program|Overlay|Module|Include",&_Context->value_Packaging),768);
		}
	if (_Context->page_number == 1 ) {
	visual_check(300,330,154,16,2,27,0,"A&uto Translation",17,_Context->value_IsAutoTrad|0);
		}
	visual_button(110,460,90,30,2,34,0,"&Accept",7,0);
	visual_button(600,460,90,30,2,34,0,"&Cancel",7,0);
	if (_Context->page_number == 1 ) {
	visual_text(520,310,140,20,2,27,0,"Dimensions",10,1);
		}
	if (_Context->page_number == 1 ) {
	visual_select(520,330,140,100,1,0,0,parse_selection("320x200|640x400|640x480|800x600|1024x786|1280x1024",&_Context->value_Dimensions),0);
		}
	visual_button(300,460,90,30,2,26,0,"&Translate",10,0);
	visual_button(400,460,90,30,2,16,28,"&Link",5,0);
	if (_Context->page_number == 1 ) {
	visual_button(300,410,90,30,2,26,0,"&Edit",5,0);
		}
	if (_Context->page_number == 1 ) {
	visual_button(400,410,90,30,2,27,24,"&Select",7,0);
		}
	if (_Context->page_number == 2 ) {
	visual_tabpage(110,150,580,300,2,"&Inclusion",10,102,2);
		(void) on_Inclusion_show();
	} else {
		visual_tabpage(110,150,580,300,2,"&Inclusion",10,102,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(120,190,552+2,240+2,5);
	(void) on_Dependance_show();
		}
	if (_Context->page_number == 3 ) {
	visual_tabpage(110,150,580,300,2,"&Modules",8,191,2);
		(void) on_Modules_show();
	} else {
		visual_tabpage(110,150,580,300,2,"&Modules",8,191,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(120,190,552+2,240+2,5);
	(void) on_Linkage_show();
		}
	if (_Context->page_number == 4 ) {
	visual_tabpage(110,150,580,300,2,"Pra&gmas",8,278,2);
	} else {
		visual_tabpage(110,150,580,300,2,"Pra&gmas",8,278,0);
		}
	if (_Context->page_number == 4 ) {
	visual_text(140,210,250,16,2,16,0,"Tcode Constants",15,259);
	visual_frame(140,226,250,184,4);
		}
	if (_Context->page_number == 4 ) {
	visual_text(410,210,260,16,2,16,0,"Tcode Pragmas",13,259);
	visual_frame(410,226,260,184,4);
		}
	if (_Context->page_number == 4 ) {
	visual_check(170,250,98,16,2,28,28,"#mem",4,_Context->value_UseDiezeMem|0);
		}
	if (_Context->page_number == 4 ) {
	visual_check(170,290,98,16,2,28,28,"#stack",6,_Context->value_UseDiezeStack|0);
		}
	if (_Context->page_number == 4 ) {
	visual_check(170,330,98,16,2,28,28,"#files",6,_Context->value_UseDiezeFiles|0);
		}
	if (_Context->page_number == 4 ) {
	visual_check(170,370,98,16,2,28,28,"#heap",5,_Context->value_UseDiezeHeap|0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(270,250,80+2,16+2,5);
	visual_text(270+1,250+1,80,16,1,28,28,_Context->buffer_DiezeMem,10,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(270,290,80+2,16+2,5);
	visual_text(270+1,290+1,80,16,1,28,28,_Context->buffer_DiezeStack,10,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(270,330,80+2,16+2,5);
	visual_text(270+1,330+1,80,16,1,28,28,_Context->buffer_DiezeFiles,10,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(270,370,80+2,16+2,5);
	visual_text(270+1,370+1,80,16,1,28,28,_Context->buffer_DiezeHeap,10,0);
		}
	if (_Context->page_number == 4 ) {
	visual_check(450,250,182,16,2,28,28,"Respect Case",12,_Context->value_RespectCase|0);
		}
	if (_Context->page_number == 4 ) {
	visual_check(450,290,182,16,2,28,28,"Optimise Tables",15,_Context->value_OptimiseTables|0);
		}
	if (_Context->page_number == 4 ) {
	visual_check(450,330,112,16,2,28,28,"TokenSize",9,_Context->value_UseTokenSize|0);
		}
	if (_Context->page_number == 4 ) {
	visual_check(450,370,112,16,2,28,28,"LabelSize",9,_Context->value_UseLabelSize|0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(570,330,72+2,16+2,5);
	visual_text(570+1,330+1,72,16,1,28,28,_Context->buffer_TokenSize,9,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(570,370,72+2,16+2,5);
	visual_text(570+1,370+1,72,16,1,28,28,_Context->buffer_LabelSize,9,0);
		}
	if (_Context->page_number == 4 ) {
		}
	visual_thaw(90,80,620,440);

	return(0);
}
private int on_Accept_event() {
	return(13);
	return(-1);
}
private int on_Cancel_event() {
	return(27);
	return(-1);
}
private int on_UseAtr_event() {
	translate_abal(0,_Context->buffer_FileName,0);
	accept_abal_production_show();
	return(-1);
}
private int on_Link_event() {
	link_abal(_Context->buffer_FileName,_Context->buffer_Linkage);
	accept_abal_production_show();
	return(-1);
}
private int on_UseEdit_event() {
	close_window_editor();
	accept_abal_production_hide();
	use_editor(_Context->buffer_FileName);
	accept_abal_production_show();
	return(-1);
}
private int on_Select_event() {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_AS);
	accept_abal_production_show();
	return(-1);
}


private	int	accept_abal_production_event()
{
	int	mx,my,mt,mb;
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if ((mx >= 689 )  
	&&  (my >= 84 )  
	&&  (mx <= 705 )  
	&&  (my <= 100 )) {
		return(1);	/* auto2 */

		}
	if ((mx >= 673 )  
	&&  (my >= 84 )  
	&&  (mx <= 689 )  
	&&  (my <= 100 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vaprod.htm");
			};
		return(-1);	/* auto2 */

		}
	if (_Context->page_number == 1 ) {
	} else {
		if ((mx >= 110 ) 
		&&  (my >= 150 ) 
		&&  (mx <= 211 ) 
		&&  (my <= 174 )) {
			return(2); /* Production */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 130 ) 
		&&  ( my >= 220 ) 
		&&  ( mx <= 670 ) 
		&&  ( my <= 240 )) {
			return(4); /* FileName */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 130 ) 
		&&  ( my >= 270 ) 
		&&  ( mx <= 670 ) 
		&&  ( my <= 290 )) {
			return(6); /* Identity */
		}
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 140 ) 
		&&  (my >= 330 ) 
		&&  (mx <= 281 ) 
		&&  (my <= 346 )) {
			return(7); /* Packaging */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 300 ) 
		&&  ( my >= 330 ) 
		&&  ( mx <= 454 ) 
		&&  ( my <= 346 )) {
			return(8); /* IsAutoTrad */
		}
		}
	if (( mx >= 110 ) 
	&&  ( my >= 460 ) 
	&&  ( mx <= 200 ) 
	&&  ( my <= 490 )) {
		return(9); /* Accept */
		}
	if (( mx >= 600 ) 
	&&  ( my >= 460 ) 
	&&  ( mx <= 690 ) 
	&&  ( my <= 490 )) {
		return(10); /* Cancel */
		}
	if (_Context->page_number == 1 ) {
		if ((mx >= 520 ) 
		&&  (my >= 330 ) 
		&&  (mx <= 660 ) 
		&&  (my <= 346 )) {
			return(12); /* Dimensions */
		}
		}
	if (( mx >= 300 ) 
	&&  ( my >= 460 ) 
	&&  ( mx <= 390 ) 
	&&  ( my <= 490 )) {
		return(13); /* UseAtr */
		}
	if (( mx >= 400 ) 
	&&  ( my >= 460 ) 
	&&  ( mx <= 490 ) 
	&&  ( my <= 490 )) {
		return(14); /* Link */
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 300 ) 
		&&  ( my >= 410 ) 
		&&  ( mx <= 390 ) 
		&&  ( my <= 440 )) {
			return(15); /* UseEdit */
		}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 400 ) 
		&&  ( my >= 410 ) 
		&&  ( mx <= 490 ) 
		&&  ( my <= 440 )) {
			return(16); /* Select */
		}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if ((mx >= 212 ) 
		&&  (my >= 150 ) 
		&&  (mx <= 300 ) 
		&&  (my <= 174 )) {
			return(17); /* Inclusion */
		}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 120 ) 
		&&  ( my >= 190 ) 
		&&  ( mx <= 672 ) 
		&&  ( my <= 430 )) {
			return(18); /* Dependance */
		}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if ((mx >= 301 ) 
		&&  (my >= 150 ) 
		&&  (mx <= 387 ) 
		&&  (my <= 174 )) {
			return(19); /* Modules */
		}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 120 ) 
		&&  ( my >= 190 ) 
		&&  ( mx <= 672 ) 
		&&  ( my <= 430 )) {
			return(20); /* Linkage */
		}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if ((mx >= 388 ) 
		&&  (my >= 150 ) 
		&&  (mx <= 478 ) 
		&&  (my <= 174 )) {
			return(21); /* PragmaPage */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 170 ) 
		&&  ( my >= 250 ) 
		&&  ( mx <= 268 ) 
		&&  ( my <= 266 )) {
			return(22); /* UseDiezeMem */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 170 ) 
		&&  ( my >= 290 ) 
		&&  ( mx <= 268 ) 
		&&  ( my <= 306 )) {
			return(23); /* UseDiezeStack */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 170 ) 
		&&  ( my >= 330 ) 
		&&  ( mx <= 268 ) 
		&&  ( my <= 346 )) {
			return(24); /* UseDiezeFiles */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 170 ) 
		&&  ( my >= 370 ) 
		&&  ( mx <= 268 ) 
		&&  ( my <= 386 )) {
			return(25); /* UseDiezeHeap */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 270 ) 
		&&  ( my >= 250 ) 
		&&  ( mx <= 350 ) 
		&&  ( my <= 266 )) {
			return(26); /* DiezeMem */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 270 ) 
		&&  ( my >= 290 ) 
		&&  ( mx <= 350 ) 
		&&  ( my <= 306 )) {
			return(27); /* DiezeStack */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 270 ) 
		&&  ( my >= 330 ) 
		&&  ( mx <= 350 ) 
		&&  ( my <= 346 )) {
			return(28); /* DiezeFiles */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 270 ) 
		&&  ( my >= 370 ) 
		&&  ( mx <= 350 ) 
		&&  ( my <= 386 )) {
			return(29); /* DiezeHeap */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 450 ) 
		&&  ( my >= 250 ) 
		&&  ( mx <= 632 ) 
		&&  ( my <= 266 )) {
			return(30); /* RespectCase */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 450 ) 
		&&  ( my >= 290 ) 
		&&  ( mx <= 632 ) 
		&&  ( my <= 306 )) {
			return(31); /* OptimiseTables */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 450 ) 
		&&  ( my >= 330 ) 
		&&  ( mx <= 562 ) 
		&&  ( my <= 346 )) {
			return(32); /* UseTokenSize */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 450 ) 
		&&  ( my >= 370 ) 
		&&  ( mx <= 562 ) 
		&&  ( my <= 386 )) {
			return(33); /* UseLabelSize */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 570 ) 
		&&  ( my >= 330 ) 
		&&  ( mx <= 642 ) 
		&&  ( my <= 346 )) {
			return(34); /* TokenSize */
		}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 570 ) 
		&&  ( my >= 370 ) 
		&&  ( mx <= 642 ) 
		&&  ( my <= 386 )) {
			return(35); /* LabelSize */
		}
		}

	return(-1);
}


private	int	accept_abal_production_losefocus()
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
private int on_Dependance_getfocus() {
	return(focus_window_editor());
	return(-1);
}
private int on_Linkage_getfocus() {
	return(focus_window_editor());
	return(-1);
}


private	int	accept_abal_production_focus()
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
					_Context->keycode = visual_edit(130+1,220+1,540,20,1,_Context->buffer_FileName,67);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* Identity */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(130+1,270+1,540,20,1,_Context->buffer_Identity,67);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* Packaging */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(140,330,141,70,1,0,0,parse_selection("Program|Overlay|Module|Include",&_Context->value_Packaging),770);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* IsAutoTrad */
				if (_Context->page_number == 1 ) {
				visual_check(300,330,154,16,2,27,0,"A&uto Translation",17,(_Context->value_IsAutoTrad |2));
					_Context->keycode = visual_getch();
				visual_check(300,330,154,16,2,27,0,"A&uto Translation",17,(_Context->value_IsAutoTrad |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* Accept */
				visual_button(110,460,90,30,2,34,0,"&Accept",7,2);
				_Context->keycode = visual_getch();
				visual_button(110,460,90,30,2,34,0,"&Accept",7,0);
				break;
			case	0xa :
				/* Cancel */
				visual_button(600,460,90,30,2,34,0,"&Cancel",7,2);
				_Context->keycode = visual_getch();
				visual_button(600,460,90,30,2,34,0,"&Cancel",7,0);
				break;
			case	0xc :
				/* Dimensions */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(520,330,140,100,1,0,0,parse_selection("320x200|640x400|640x480|800x600|1024x786|1280x1024",&_Context->value_Dimensions),2);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* UseAtr */
				visual_button(300,460,90,30,2,26,0,"&Translate",10,2);
				_Context->keycode = visual_getch();
				visual_button(300,460,90,30,2,26,0,"&Translate",10,0);
				break;
			case	0xe :
				/* Link */
				visual_button(400,460,90,30,2,16,28,"&Link",5,2);
				_Context->keycode = visual_getch();
				visual_button(400,460,90,30,2,16,28,"&Link",5,0);
				break;
			case	0xf :
				/* UseEdit */
				if (_Context->page_number == 1 ) {
					visual_button(300,410,90,30,2,26,0,"&Edit",5,2);
					_Context->keycode = visual_getch();
					visual_button(300,410,90,30,2,26,0,"&Edit",5,0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* Select */
				if (_Context->page_number == 1 ) {
					visual_button(400,410,90,30,2,27,24,"&Select",7,2);
					_Context->keycode = visual_getch();
					visual_button(400,410,90,30,2,27,24,"&Select",7,0);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* Inclusion */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x12 :
				/* Dependance */
				if (_Context->page_number == 2 ) {
					if ((_Context->keycode = on_Dependance_getfocus()) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* Modules */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x14 :
				/* Linkage */
				if (_Context->page_number == 3 ) {
					if ((_Context->keycode = on_Linkage_getfocus()) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x15 :
				/* PragmaPage */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x16 :
				/* UseDiezeMem */
				if (_Context->page_number == 4 ) {
				visual_check(170,250,98,16,2,28,28,"#mem",4,(_Context->value_UseDiezeMem |2));
					_Context->keycode = visual_getch();
				visual_check(170,250,98,16,2,28,28,"#mem",4,(_Context->value_UseDiezeMem |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x17 :
				/* UseDiezeStack */
				if (_Context->page_number == 4 ) {
				visual_check(170,290,98,16,2,28,28,"#stack",6,(_Context->value_UseDiezeStack |2));
					_Context->keycode = visual_getch();
				visual_check(170,290,98,16,2,28,28,"#stack",6,(_Context->value_UseDiezeStack |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x18 :
				/* UseDiezeFiles */
				if (_Context->page_number == 4 ) {
				visual_check(170,330,98,16,2,28,28,"#files",6,(_Context->value_UseDiezeFiles |2));
					_Context->keycode = visual_getch();
				visual_check(170,330,98,16,2,28,28,"#files",6,(_Context->value_UseDiezeFiles |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* UseDiezeHeap */
				if (_Context->page_number == 4 ) {
				visual_check(170,370,98,16,2,28,28,"#heap",5,(_Context->value_UseDiezeHeap |2));
					_Context->keycode = visual_getch();
				visual_check(170,370,98,16,2,28,28,"#heap",5,(_Context->value_UseDiezeHeap |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* DiezeMem */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(270+1,250+1,80,16,1,_Context->buffer_DiezeMem,10);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* DiezeStack */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(270+1,290+1,80,16,1,_Context->buffer_DiezeStack,10);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1c :
				/* DiezeFiles */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(270+1,330+1,80,16,1,_Context->buffer_DiezeFiles,10);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1d :
				/* DiezeHeap */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(270+1,370+1,80,16,1,_Context->buffer_DiezeHeap,10);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* RespectCase */
				if (_Context->page_number == 4 ) {
				visual_check(450,250,182,16,2,28,28,"Respect Case",12,(_Context->value_RespectCase |2));
					_Context->keycode = visual_getch();
				visual_check(450,250,182,16,2,28,28,"Respect Case",12,(_Context->value_RespectCase |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1f :
				/* OptimiseTables */
				if (_Context->page_number == 4 ) {
				visual_check(450,290,182,16,2,28,28,"Optimise Tables",15,(_Context->value_OptimiseTables |2));
					_Context->keycode = visual_getch();
				visual_check(450,290,182,16,2,28,28,"Optimise Tables",15,(_Context->value_OptimiseTables |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x20 :
				/* UseTokenSize */
				if (_Context->page_number == 4 ) {
				visual_check(450,330,112,16,2,28,28,"TokenSize",9,(_Context->value_UseTokenSize |2));
					_Context->keycode = visual_getch();
				visual_check(450,330,112,16,2,28,28,"TokenSize",9,(_Context->value_UseTokenSize |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x21 :
				/* UseLabelSize */
				if (_Context->page_number == 4 ) {
				visual_check(450,370,112,16,2,28,28,"LabelSize",9,(_Context->value_UseLabelSize |2));
					_Context->keycode = visual_getch();
				visual_check(450,370,112,16,2,28,28,"LabelSize",9,(_Context->value_UseLabelSize |0));
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x22 :
				/* TokenSize */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(570+1,330+1,72,16,1,_Context->buffer_TokenSize,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x23 :
				/* LabelSize */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(570+1,370+1,72,16,1,_Context->buffer_LabelSize,9);
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
			accept_abal_production_losefocus();
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_abal_production_show();
			continue;
		case	0x2 :
			accept_abal_production_losefocus();
			_Context->page_number=4;
			_Context->focus_item=35;
			accept_abal_production_show();
			continue;
		case	0x3 :
			accept_abal_production_losefocus();
			if ( _Context->page_number < 4 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_abal_production_show();
			continue;
		case	0x12 :
			accept_abal_production_losefocus();
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_abal_production_show();
			continue;
			case	0x100 :
				if (visual_event(1) & _MIMO_ALT) { _Context->keycode=visual_event(2); goto retry; }
				if ((retcode=accept_abal_production_event()) == -1)
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
							accept_abal_production_losefocus();
							_Context->page_number = 1;
							accept_abal_production_show();
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
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(110,460,90,30,2,34,0,"&Accept",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(110,460,90,30,2,34,0,"&Accept",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event()) != -1) break;

							}
						continue;
					case	0xa :
						/* Cancel */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(600,460,90,30,2,34,0,"&Cancel",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(600,460,90,30,2,34,0,"&Cancel",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Cancel_event()) != -1) break;

							}
						continue;
					case	0xc :
						/* Dimensions */
						continue;
					case	0xd :
						/* UseAtr */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(300,460,90,30,2,26,0,"&Translate",10,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(300,460,90,30,2,26,0,"&Translate",10,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_UseAtr_event()) != -1) break;

							}
						continue;
					case	0xe :
						/* Link */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,460,90,30,2,16,28,"&Link",5,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,460,90,30,2,16,28,"&Link",5,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Link_event()) != -1) break;

							}
						continue;
					case	0xf :
						/* UseEdit */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(300,410,90,30,2,26,0,"&Edit",5,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(300,410,90,30,2,26,0,"&Edit",5,0);
							}
						if ( visual_event(1) &  0x3834 ) {
						if ((_Context->keycode = on_UseEdit_event()) != -1) break;

							}
						continue;
					case	0x10 :
						/* Select */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(400,410,90,30,2,27,24,"&Select",7,8);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(400,410,90,30,2,27,24,"&Select",7,0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Select_event()) != -1) break;

							}
						continue;
					case	0x11 :
						/* Inclusion */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_abal_production_losefocus();
							_Context->page_number = 2;
							accept_abal_production_show();
							}
						continue;
					case	0x12 :
						/* Dependance */
						continue;
					case	0x13 :
						/* Modules */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_abal_production_losefocus();
							_Context->page_number = 3;
							accept_abal_production_show();
							}
						continue;
					case	0x14 :
						/* Linkage */
						continue;
					case	0x15 :
						/* PragmaPage */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_abal_production_losefocus();
							_Context->page_number = 4;
							accept_abal_production_show();
							}
						continue;
					case	0x16 :
						/* UseDiezeMem */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_UseDiezeMem += 1;
							_Context->value_UseDiezeMem &= 1;
							}
						continue;
					case	0x17 :
						/* UseDiezeStack */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_UseDiezeStack += 1;
							_Context->value_UseDiezeStack &= 1;
							}
						continue;
					case	0x18 :
						/* UseDiezeFiles */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_UseDiezeFiles += 1;
							_Context->value_UseDiezeFiles &= 1;
							}
						continue;
					case	0x19 :
						/* UseDiezeHeap */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_UseDiezeHeap += 1;
							_Context->value_UseDiezeHeap &= 1;
							}
						continue;
					case	0x1a :
						/* DiezeMem */
						continue;
					case	0x1b :
						/* DiezeStack */
						continue;
					case	0x1c :
						/* DiezeFiles */
						continue;
					case	0x1d :
						/* DiezeHeap */
						continue;
					case	0x1e :
						/* RespectCase */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_RespectCase += 1;
							_Context->value_RespectCase &= 1;
							}
						continue;
					case	0x1f :
						/* OptimiseTables */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_OptimiseTables += 1;
							_Context->value_OptimiseTables &= 1;
							}
						continue;
					case	0x20 :
						/* UseTokenSize */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_UseTokenSize += 1;
							_Context->value_UseTokenSize &= 1;
							}
						continue;
					case	0x21 :
						/* UseLabelSize */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_UseLabelSize += 1;
							_Context->value_UseLabelSize &= 1;
							}
						continue;
					case	0x22 :
						/* TokenSize */
						continue;
					case	0x23 :
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
				_Context->focus_item=35;
			}
			continue;
		case 0x870 : 
		case 0x850 : 
			/* Production */
						accept_abal_production_losefocus();
			_Context->page_number = 1;
			accept_abal_production_show();
			_Context->focus_item=2;
			continue;
			continue;
		case 0x875 : 
		case 0x855 : 
			if (_Context->page_number == 1) {
				/* IsAutoTrad */
				_Context->value_IsAutoTrad += 1;
				_Context->value_IsAutoTrad &= 1;
				_Context->focus_item=8;
				continue;
				}
			continue;
		case 0x861 : 
		case 0x841 : 
			/* Accept */
			visual_button(110,460,90,30,2,34,0,"&Accept",7,8);
			visual_button(110,460,90,30,2,34,0,"&Accept",7,0);
			_Context->focus_item=9;
			if ((_Context->keycode = on_Accept_event()) != -1) break;
			continue;
			continue;
		case 0x863 : 
		case 0x843 : 
			/* Cancel */
			visual_button(600,460,90,30,2,34,0,"&Cancel",7,8);
			visual_button(600,460,90,30,2,34,0,"&Cancel",7,0);
			_Context->focus_item=10;
			if ((_Context->keycode = on_Cancel_event()) != -1) break;
			continue;
			continue;
		case 0x874 : 
		case 0x854 : 
			/* UseAtr */
			visual_button(300,460,90,30,2,26,0,"&Translate",10,8);
			visual_button(300,460,90,30,2,26,0,"&Translate",10,0);
			_Context->focus_item=13;
			if ((_Context->keycode = on_UseAtr_event()) != -1) break;
			continue;
			continue;
		case 0x86c : 
		case 0x84c : 
			/* Link */
			visual_button(400,460,90,30,2,16,28,"&Link",5,8);
			visual_button(400,460,90,30,2,16,28,"&Link",5,0);
			_Context->focus_item=14;
			if ((_Context->keycode = on_Link_event()) != -1) break;
			continue;
			continue;
		case 0x865 : 
		case 0x845 : 
			if (_Context->page_number == 1) {
				/* UseEdit */
				visual_button(300,410,90,30,2,26,0,"&Edit",5,8);
				visual_button(300,410,90,30,2,26,0,"&Edit",5,0);
				_Context->focus_item=15;
				if ((_Context->keycode = on_UseEdit_event()) != -1) break;
				continue;
				}
			continue;
		case 0x873 : 
		case 0x853 : 
			if (_Context->page_number == 1) {
				/* Select */
				visual_button(400,410,90,30,2,27,24,"&Select",7,8);
				visual_button(400,410,90,30,2,27,24,"&Select",7,0);
				_Context->focus_item=16;
				if ((_Context->keycode = on_Select_event()) != -1) break;
				continue;
				}
			continue;
		case 0x869 : 
		case 0x849 : 
			/* Inclusion */
						accept_abal_production_losefocus();
			_Context->page_number = 2;
			accept_abal_production_show();
			_Context->focus_item=17;
			continue;
			continue;
		case 0x86d : 
		case 0x84d : 
			/* Modules */
						accept_abal_production_losefocus();
			_Context->page_number = 3;
			accept_abal_production_show();
			_Context->focus_item=19;
			continue;
			continue;
		case 0x867 : 
		case 0x847 : 
			/* PragmaPage */
						accept_abal_production_losefocus();
			_Context->page_number = 4;
			accept_abal_production_show();
			_Context->focus_item=21;
			continue;
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
	char * pRespectCase,
	char * pOptimiseTables,
	char * pUseTokenSize,
	char * pUseLabelSize,
	char * pTokenSize,
	char * pLabelSize)
{
	int	status=0;
	status = accept_abal_production_create(
	 pFileName,
	 pIdentity,
	 pPackaging,
	 pIsAutoTrad,
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
	 pRespectCase,
	 pOptimiseTables,
	 pUseTokenSize,
	 pUseLabelSize,
	 pTokenSize,
	 pLabelSize);
	if ( status != 0) return(status);
	status = accept_abal_production_show();
		enter_modal();
	status = accept_abal_production_focus();
		leave_modal();
	status = accept_abal_production_hide();
	status = accept_abal_production_remove(
	 pFileName,
	 pIdentity,
	 pPackaging,
	 pIsAutoTrad,
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
